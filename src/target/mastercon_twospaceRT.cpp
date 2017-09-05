/* $Id: mastercon_outout.cpp 2016-12-05 Raeed $
 *
 * Master Control block for behavior: Out-out
 */

#define S_FUNCTION_NAME mastercon_twospaceRT
#define S_FUNCTION_LEVEL 2
#define TASK_DB_DEFINED 1

#include "words.h"
#include "common_header.cpp"

#define PI (3.141592654)

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_INIT_MOVE 1
#define STATE_TARG_HOLD 2
#define STATE_MOVEMENT 3


/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */

/* Databurst documentation
 *
 *  Version 0 (0x00)
 * ----------------
 * byte   0: uchar => number of bytes to be transmitted
 * byte   1: uchar => databurst version number (in this case: 0)
 * byte   2 to 4: uchar => task code ('TRT')
 * byte   5: uchar => model version major
 * byte   6: uchar => model version minor
 * bytes  7 to  8: short => model version micro
 * bytes  9 to  12: float => x offset
 * bytes 13 to 16: float => y offset
 * bytes 17 to 20: float => target_size
 * bytes 21 to 24: float => workspace number
 * bytes 25 to 25+N*8: where N is the number of targets, contains 8 bytes per 
 *      target representing two single-precision floating point numbers in 
 *      little-endian format represnting the x and y position of the center of 
 *      the target.
 *
 */
#define DATABURST_VERSION ((byte)0x00) 

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;

	// Time Bounds for various timers
	real_T targ_hold_lo;
	real_T targ_hold_hi;

	real_T intertrial_interval;
    real_T initial_movement_time; // maximum allowed time to start trial
	real_T movement_max_time;    // maximum allowed movement time
	real_T failure_penalty_lag;  // penalty lag for failed movements

	real_T target_size;          // radius of targets
	real_T num_targets;

	real_T targ_color_R;
	real_T targ_color_G;
	real_T targ_color_B;

    // workspace boundaries
    real_T ws1_xmin;
    real_T ws1_xmax;
    real_T ws1_ymin;
    real_T ws1_ymax;
    real_T ws2_xmin;
    real_T ws2_xmax;
    real_T ws2_ymin;
    real_T ws2_ymax;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME TwoSpaceRTBehavior
class TwoSpaceRTBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	TwoSpaceRTBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
    int target_index;
	double targ_hold_time;
	int t_color;
	
    CircleTarget *ws1_targets[128];
    CircleTarget *ws2_targets[128];

	LocalParams *params;

	// helper functions
	void doPreTrial(SimStruct *S);
};

TwoSpaceRTBehavior::TwoSpaceRTBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(20);

	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			0);
	
	this->bindParamId(&params->targ_hold_lo,				1);
	this->bindParamId(&params->targ_hold_hi,				2);

	this->bindParamId(&params->intertrial_interval,		3);
    this->bindParamID(&params->initial_movement_time,   4);
	this->bindParamId(&params->movement_max_time,		5);
	this->bindParamId(&params->failure_penalty_lag,	    6);

	this->bindParamId(&params->target_size,				7);
	this->bindParamId(&params->num_targets,				8);

	this->bindParamId(&params->targ_color_R,			9);
	this->bindParamId(&params->targ_color_G,			10);
	this->bindParamId(&params->targ_color_B,			11);

	this->bindParamId(&params->ws1_xmin,			12);
	this->bindParamId(&params->ws1_xmax,			13);
	this->bindParamId(&params->ws1_ymin,			14);
	this->bindParamId(&params->ws1_ymax,			15);
	this->bindParamId(&params->ws2_xmin,			16);
	this->bindParamId(&params->ws2_xmax,			17);
	this->bindParamId(&params->ws2_ymin,			18);
	this->bindParamId(&params->ws2_ymax,			19);

	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	this->updateParameters(S);

    /* 
	 * Then do any behavior specific initialization 
	 */
    target_index = (int)params->num_targets-1;
    for(i=0; i<128; i++) {
        ws1_targets[i] = new CircleTarget(0,0,0,0)
        ws2_targets[i] = new CircleTarget(0,0,0,0)
    }

	targ_hold_time	     = 0.0;
	t_color = 0;
}

// Pre-trial initialization and calculations
void TwoSpaceRTBehavior::doPreTrial(SimStruct *S) {
	int i; 

	/* initialize targets */
	//Set Colors
	t_color = Target::Color(params->targ_color_R, params->targ_color_G, params->targ_color_B);

    //Pick workspace
    int ws_num = random->getInteger(1,2);
    int left_target_boundary, right_target_boundary, lower_target_boundary, upper_target_boundary;

    /* uniform random positions */
    for (i = 0; i<params->num_targets; i++) {
        if (ws_num == 1) {
            left_target_boundary =  params->ws1_xmin;
            right_target_boundary = params->ws1_xmax;
            lower_target_boundary = params->ws1_ymin;
            upper_target_boundary = params->ws1_ymax;
        }
        else if (ws_num == 2) {
            left_target_boundary =  params->ws2_xmin;
            right_target_boundary = params->ws2_xmax;
            lower_target_boundary = params->ws2_ymin;
            upper_target_boundary = params->ws2_ymax;
        }
            
        targets[i]->centerX = random->getDouble(left_target_boundary,  right_target_boundary);
        targets[i]->centerY = random->getDouble(lower_target_boundary, upper_target_boundary);
        targets[i]->radius = params->target_size;
        targets[i]->color = t_color;
    }

	// Randomized Timers
	targ_hold_time		= random->getDouble(params->targ_hold_lo, params->targ_hold_hi);

    // Reset target index
    target_index = 0;

	// setup the databurst
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('T');
	db->addByte('R');
	db->addByte('T');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)(inputs->offsets.x));
	db->addFloat((float)(inputs->offsets.y));
    db->addFloat((float)(params->target_size));
    db->addFloat((float)(ws_num));
	for (i = 0; i<params->num_targets; i++) {
		db->addFloat((float)targets[i]->centerX);
		db->addFloat((float)targets[i]->centerY);
	}
    db->start();

}

void TwoSpaceRTBehavior::update(SimStruct *S) {
	int i;
    /* declarations */

	// State machine
	switch (this->getState()) {
		case STATE_PRETRIAL:
			updateParameters(S);
			doPreTrial(S);
			setState(STATE_DATA_BLOCK);
			break;
		case STATE_DATA_BLOCK:
			if (db->isDone()) {
				setState(STATE_INIT_MOVE);
			}
		case STATE_INIT_MOVE:
			/* target on */
			if (targets[target_index]->cursorInTarget(inputs->cursor)) {
				setState(STATE_TARG_HOLD);
			} else if (stateTimer->elapsedTime(S) > params->initial_movement_time) {
                setState(STATE_INCOMPLETE);
            }
			break;
		case STATE_TARG_HOLD:
			if (!targets[target_index]->cursorInTarget(inputs->cursor)){
                setState(STATE_ABORT);
			}
			else if (stateTimer->elapsedTime(S) >= targ_hold_time) {
                // check if there are more targets
                if (target_index == params->num_targets-1) {
                    // no more targets
                    playTone(TONE_REWARD);
                    setState(STATE_REWARD);
                } else {
                    // more targets
                    target_index++;
                    targ_hold_time = random->getDouble(params->targ_hold_lo, params->targ_hold_hi);
                    playTone(TONE_GO);
                    setState(STATE_MOVEMENT);
                }
			}
			break;
		case STATE_MOVEMENT:
			if (stateTimer->elapsedTime(S) > params->movement_max_time) {
				setState(STATE_FAIL);
			}
			else if (targets[target_index]->cursorInTarget(inputs->cursor)) {
				setState(STATE_TARG_HOLD);
			}
			break;
		case STATE_REWARD:
		case STATE_ABORT:
        case STATE_INCOMPLETE:
			if (stateTimer->elapsedTime(S) > params->intertrial_interval) {
				setState(STATE_PRETRIAL);
			}
			break;
        case FAIL:
			if (stateTimer->elapsedTime(S) > params->failure_penalty_lag) {
				setState(STATE_PRETRIAL);
			}
			break;
		default:
			setState(STATE_PRETRIAL);
	}
}

void TwoSpaceRTBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
	int i;
    CircleTarget *currentTarget = targets[target_index];

	/* force (0) */
    outputs->force = inputs->force;

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
			case STATE_INIT_MOVE:
				outputs->word = WORD_GO_CUE;
				break;
			case STATE_TARG_HOLD:
				outputs->word = WORD_TARGET_HOLD;
				break;
			case STATE_MOVEMENT:
				outputs->word = WORD_GO_CUE;
				break;
			case STATE_REWARD:
				outputs->word = WORD_REWARD;
				break;
			case STATE_ABORT:
				outputs->word = WORD_ABORT;
				break;
			case STATE_INCOMPLETE:
				outputs->word = WORD_INCOMPLETE;
				break;
            case STATE_FAIL:
                outputs->word = WORD_FAIL;
			default:
				outputs->word = 0;
		}
	} else {
		outputs->word = 0;
	}

    /*----------------START HERE------------------*/

	/* target_pos (3) */
	// target 1
	if (getState() == STATE_INITIAL_MOVEMENT ||
		getState() == STATE_TARGET_HOLD ||
		getState() == STATE_MOVEMENT){
			outputs->targets[0] = (Target *)currentTarget;
	} else {
		outputs->targets[0] = nullTarget;
	}
	// target 2 (if delay)
	// if (getState() == STATE_TARGET_DELAY){
	// 		outputs->targets[1] = (Target *)(this->targets[target_index+1]);
	// } else {
	// 	outputs->targets[1] = nullTarget;
	// }

	/* reward (4) */
	outputs->reward = (isNewState() && getState() == STATE_REWARD);

	/* tone (5) */
	this->outputs->tone_counter = this->tone_counter;
	this->outputs->last_tone_id = this->last_tone_id;

	/* version (6) */
	outputs->version[0] = BEHAVIOR_VERSION_MAJOR;
	outputs->version[1] = BEHAVIOR_VERSION_MINOR;
	outputs->version[2] = BEHAVIOR_VERSION_MICRO;
	outputs->version[3] = BEHAVIOR_VERSION_BUILD;

	/* position (7) */
	// If we are in the movement,
	outputs->position = inputs->cursor;
}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


