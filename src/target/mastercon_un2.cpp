/* $Id: mastercon_rw2.cpp 858 2012-04-11 21:46:24Z brian $
 *
 * Master Control block for behavior: random walk task 
 */

#define S_FUNCTION_NAME mastercon_un2
#define S_FUNCTION_LEVEL 2

#define TASK_UN 1
#include "words.h"

#include "common_header.cpp"

/*
 * State IDs
 */
#define STATE_PRETRIAL     0
#define STATE_CT_ON        1
#define STATE_CENTER_HOLD  2
#define STATE_CENTER_DELAY 3
#define STATE_MOVEMENT     4
#define STATE_OUTER_HOLD   5
/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */


// #define DATABURST_VERSION ((byte)0x02) 

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;

	real_T num_targets;
	real_T target_radius;
	real_T target_size;
	real_T center_hold_l;
	real_T center_hold_h;
	real_T center_delay_l;
	real_T center_delay_h;
	real_T movement_time;
	real_T target_hold_l;
	real_T target_hold_h;
	real_T intertrial;

	real_T displacement_mean;
	real_T displacement_var;

	real_T feedback_var;
	real_T feedback_dot_size;
	real_T feedback_dot_num;

	real_T feedback_window_begin;
	real_T feedback_window_end;
//	real_T feedback_timer_end;
//	real_T feedback_use_timer;

	real_T cursor_window_begin;
	real_T cursor_window_end;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME UncertaintyBehavior
class UncertaintyBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	UncertaintyBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	double displacement;
	Point cloud_points[16];
	double center_hold, center_delay, outer_hold;

	Target *centerTarget;
	Target *outerTarget;
	Target *errorTargetLeft;
	Target *errorTargetRight;

	LocalParams *params;

	// any helper functions you need
	void doPreTrial(SimStruct *S);
};

UncertaintyBehavior::UncertaintyBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(21);

	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			 0);
	this->bindParamId(&params->num_targets,				 1);
	this->bindParamId(&params->target_radius,			 2);
	this->bindParamId(&params->target_size,				 3);
	this->bindParamId(&params->center_hold_l;
	this->bindParamId(&params->center_hold_h;
	this->bindParamId(&params->center_delay_l;
	this->bindParamId(&params->center_delay_h;
	this->bindParamId(&params->movement_time;
	this->bindParamId(&params->target_hold_l;
	this->bindParamId(&params->target_hold_h;
	this->bindParamId(&params->intertrial;
	this->bindParamId(&params->displacement_mean;
	this->bindParamId(&params->displacement_var;
	this->bindParamId(&params->feedback_var;
	this->bindParamId(&params->feedback_dot_size;
	this->bindParamId(&params->feedback_dot_num;
	this->bindParamId(&params->feedback_window_begin,	17);
	this->bindParamId(&params->feedback_window_end,		18);
	this->bindParamId(&params->cursor_window_begin,		19);
	this->bindParamId(&params->cursor_window_end,		20);

	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	this->updateParameters(S);

    /* 
	 * Then do any behavior specific initialization 
	 */
	centerTarget = new RectangleTarget(0,0,0,0,0);
	outerTarget = new RectangleTarget(0,0,0,0,0);
	errorTargetLeft = new RectangleTarget(0,0,0,0,0);
	errorTargetRight = new RectangleTarget(0,0,0,0,0);

	for (i=0; i<16; i++) {
		cloud_points[i].x = 0;
		cloud_points[i].y = 0;
	}
}

void RandomWalkBehavior::doPreTrial(SimStruct *S) {
	int i, j;
	double r, th;
	SquareTarget lastTarget = *targets[(int)params->num_targets];
	SquareTarget tmpTarget;

	/* initialize target positions */
	if (params->maximum_distance == 0) {
		/* uniform random positions */
		for (i = 0; i<params->num_targets; i++) {
			targets[i]->centerX = random->getDouble(params->left_target_boundary,  params->right_target_boundary);
			targets[i]->centerY = random->getDouble(params->lower_target_boundary, params->upper_target_boundary);
			targets[i]->width = params->target_size;
			targets[i]->color = Target::Color(255, 0, 0);
		}
	} else {
		/* set not-quite-random target distances 
		 * semi-random with max and min distances */

		for (i = 0; i<params->num_targets; i++) {
			// Foreach Target
			r = random->getDouble(params->minimum_distance, params->maximum_distance);
			th = random->getDouble(0, 2*PI);

			// Copy previous target as a starting point
			if (i==0) {
				*targets[i] = lastTarget;
			} else {
				*targets[i] = *targets[i-1];
			}
			tmpTarget = *targets[i];

			for (j=0; j<5; j++) {
				// Add the offset
				tmpTarget.centerX = targets[i]->centerX + r * cos(th);
				tmpTarget.centerY = targets[i]->centerY + r * sin(th);
				if (tmpTarget.centerX > params->left_target_boundary &&
					tmpTarget.centerX < params->right_target_boundary &&
					tmpTarget.centerY > params->lower_target_boundary &&
					tmpTarget.centerY < params->upper_target_boundary)
				{
					// Found a location that works
					break;
				}

				if (j==4) {
					// Give up and set at origin
					tmpTarget.centerX = 0.0;
					tmpTarget.centerY = 0.0;
					break;
				}

				th = th + PI/2;
				r = params->minimum_distance;
			}

            tmpTarget.width = params->target_size;
            tmpTarget.color = Target::Color(255, 0, 0);
			*targets[i] = tmpTarget;
		}
	}

	target_index = 0;
	catchTrial = false;

	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)(inputs->offsets.x));
	db->addFloat((float)(inputs->offsets.y));
	db->addFloat((float)params->target_tolerance + (float)params->target_size);
	for (i = 0; i<params->num_targets; i++) {
		db->addFloat((float)targets[i]->centerX);
		db->addFloat((float)targets[i]->centerY);
	}
    db->start();
}

void RandomWalkBehavior::update(SimStruct *S) {
    /* declarations */
	SquareTarget currentTarget;
	SquareTarget targetBounds;
	
	currentTarget = *targets[target_index];
	targetBounds = currentTarget;
    targetBounds.width = currentTarget.width + params->target_tolerance;

	// State machine
	switch (this->getState()) {
		case STATE_PRETRIAL:
			updateParameters(S);
			doPreTrial(S);
			setState(STATE_DATA_BLOCK);
			break;
		case STATE_DATA_BLOCK:
			if (db->isDone()) {
				cumulativeHoldTimer->stop(S);
				setState(STATE_INITIAL_MOVEMENT);
			}
		case STATE_INITIAL_MOVEMENT:
			/* first target on */
			if (targetBounds.cursorInTarget(inputs->cursor)) {
				cumulativeHoldTimer->start(S);
				setState(STATE_TARGET_HOLD);
			} else if (stateTimer->elapsedTime(S) > params->initial_movement_time) {
				setState(STATE_INCOMPLETE);
			}
			break;
		case STATE_MOVEMENT:
			if (targetBounds.cursorInTarget(inputs->cursor)) {
				cumulativeHoldTimer->start(S);
				setState(STATE_TARGET_HOLD);
			} else if (stateTimer->elapsedTime(S) > params->movement_time) {
				setState(STATE_FAIL);
			}
			break;
		case STATE_TARGET_HOLD:
			if (params->cumulative_hold && cumulativeHoldTimer->elapsedTime(S) > targetHoldTime) {
				/* next state depends on whether there are more targets */
				if (target_index == params->num_targets - 1) {
					/* no more targets */
					cumulativeHoldTimer->stop(S);
					playTone(TONE_REWARD);
					setState(STATE_REWARD);
				} else {
					/* more targets */
					cumulativeHoldTimer->stop(S);
					delayTime = random->getDouble(params->target_delay_l, params->target_delay_h);
					setState(STATE_TARGET_DELAY);
				}
			} else if (params->disable_abort && !targetBounds.cursorInTarget(inputs->cursor)) {
				cumulativeHoldTimer->pause(S);
				setState(STATE_MOVEMENT);
			} else if (!targetBounds.cursorInTarget(inputs->cursor)) {
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > targetHoldTime) {
				/* next state depends on whether there are more targets */
				if (target_index == params->num_targets - 1) {
					/* no more targets */
					playTone(TONE_REWARD);
					setState(STATE_REWARD);
				} else {
					/* more targets */
					delayTime = random->getDouble(params->target_delay_l, params->target_delay_h);
					setState(STATE_TARGET_DELAY);
				}
			}
			break;
		case STATE_TARGET_DELAY:
			if (!targetBounds.cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > delayTime) {
				target_index++;
				catchTrial = ( random->getDouble() < params->percent_catch_trials );
				targetHoldTime = random->getDouble(params->target_hold_l, params->target_hold_h);
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_ABORT:
        case STATE_REWARD:
		case STATE_FAIL:
        case STATE_INCOMPLETE:
			if (stateTimer->elapsedTime(S) > params->intertrial) {
				setState(STATE_PRETRIAL);
			}
			break;
		default:
			setState(STATE_PRETRIAL);
	}
}

void RandomWalkBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
    SquareTarget *currentTarget = targets[target_index];

	/* force (0) */
	if (catchTrial) {
		outputs->force = inputs->catchForce;
	} else {
		outputs->force = inputs->force;
	}

	/* status (1) */
	outputs->status[0] = getState();
	outputs->status[1] = trialCounter->successes;
	outputs->status[2] = trialCounter->aborts;
	outputs->status[3] = trialCounter->failures;
	outputs->status[4] = trialCounter->incompletes;

	/* word(2) */
	if (db->isRunning()) {
		outputs->word = db->getByte();
	} else if (isNewState()) {
		switch (getState()) {
			case STATE_PRETRIAL:
				outputs->word = WORD_START_TRIAL;
				break;
			case STATE_INITIAL_MOVEMENT:
				if (catchTrial) {
					outputs->word = WORD_CATCH;
				} else {
					outputs->word = WORD_GO_CUE;
				}
				break;
			case STATE_TARGET_HOLD:
				outputs->word = WORD_TARGET_HOLD;
				break;
			case STATE_MOVEMENT:
				if (catchTrial) {
					outputs->word = WORD_CATCH;
				} else {
					outputs->word = WORD_GO_CUE;
				}
				break;
			case STATE_REWARD:
				outputs->word = WORD_REWARD;
				break;
			case STATE_ABORT:
				outputs->word = WORD_ABORT;
				break;
			case STATE_FAIL:
				outputs->word = WORD_FAIL;
				break;
			case STATE_INCOMPLETE:
				outputs->word = WORD_INCOMPLETE;
				break;
			default:
				outputs->word = 0;
		}
	} else {
		outputs->word = 0;
	}

	/* target_pos (3) */
	// Target 0
	if (getState() == STATE_TARGET_HOLD && params->green_hold) {
		currentTarget->color = Target::Color(0, 128, 0);
		outputs->targets[0] = (Target *)currentTarget;
	} else if (getState() == STATE_INITIAL_MOVEMENT || 
			   getState() == STATE_MOVEMENT || 
		       getState() == STATE_TARGET_HOLD ||
		       getState() == STATE_TARGET_DELAY) {
		currentTarget->color = Target::Color(255, 0, 0);
		outputs->targets[0] = (Target *)currentTarget;
	} else {
		outputs->targets[0] = nullTarget;
	}

	// Target 1
	if (getState() == STATE_TARGET_DELAY) {
		outputs->targets[1] = (Target *)(this->targets[target_index+1]);		
	} else {
		outputs->targets[1] = this->nullTarget;
	}  

	/* reward (4) */
	outputs->reward = (isNewState() && (getState() == STATE_REWARD));

	/* tone (5) */
	this->outputs->tone_counter = this->tone_counter;
	this->outputs->last_tone_id = this->last_tone_id;

	/* version (6) */
	outputs->version[0] = BEHAVIOR_VERSION_MAJOR;
	outputs->version[1] = BEHAVIOR_VERSION_MINOR;
	outputs->version[2] = BEHAVIOR_VERSION_MICRO;
	outputs->version[3] = BEHAVIOR_VERSION_BUILD;

	/* position (7) */
	outputs->position = inputs->cursor;
}

/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


