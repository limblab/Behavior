/* $Id: mastercon_outout.cpp 2016-12-05 Raeed $
 *
 * Master Control block for behavior: Out-out
 */

#define S_FUNCTION_NAME mastercon_outout
#define S_FUNCTION_LEVEL 2
#define TASK_DB_DEFINED 1

#include "words.h"
#include "common_header.cpp"

#define PI (3.141592654)

/*
 * State IDs
 */
#define STATE_PRETRIAL        0
#define STATE_CT_ON			  1
#define STATE_CT_HOLD		  2
#define STATE_MOVEMENT		  3
#define STATE_OUTER_HOLD      4


/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */


#define DATABURST_VERSION ((byte)0x01) 

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;

	// Time Bounds for various timers
	real_T ct_hold_lo;
	real_T ct_hold_hi;
	real_T ot_hold_lo;
	real_T ot_hold_hi;

	real_T intertrial_interval;
	real_T movement_max_time;    // maximum allowed movement time
	real_T failure_penalty_lag;  // penalty lag for failed movements

	real_T movement_length;  
	real_T target_size;          // width of targets
	real_T num_targets;

	real_T targ_color_R;
	real_T targ_color_G;
	real_T targ_color_B;

	real_T force_mag; 
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME OutOutBehavior
class OutOutBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	OutOutBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	Timer  *feedback_timer; // feedback timer

	double ct_hold_time, ot_hold_time;
	double reach_len;
	int t_color;
	Point forces;

	CircleTarget    *startTarget;
	CircleTarget    *endTarget;

	LocalParams *params;

	// helper functions
	void doPreTrial(SimStruct *S);
};

OutOutBehavior::OutOutBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(15);

	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			0);
	
	this->bindParamId(&params->ct_hold_lo,				1);
	this->bindParamId(&params->ct_hold_hi,				2);
	this->bindParamId(&params->ot_hold_lo,				3);
	this->bindParamId(&params->ot_hold_hi,				4);

	this->bindParamId(&params->intertrial_interval,		5);
	this->bindParamId(&params->movement_max_time,		6);
	this->bindParamId(&params->failure_penalty_lag,	    7);

	this->bindParamId(&params->movement_length,			8);
	this->bindParamId(&params->target_size,				9);

	this->bindParamId(&params->targ_color_R,			10);
	this->bindParamId(&params->targ_color_G,			11);
	this->bindParamId(&params->targ_color_B,			12);
	this->bindParamId(&params->num_targets,				13);

	this->bindParamId(&params->force_mag,				14);

	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	this->updateParameters(S);

    /* 
	 * Then do any behavior specific initialization 
	 */
	startTarget	 = new CircleTarget(0,0,0,0);
	endTarget	 = new CircleTarget(0,0,0,0);

	reach_len=0.0;
	ct_hold_time	     = 0.0;
	ot_hold_time	     = 0.0;
	t_color = 0;
	forces.x = 0.0;
	forces.y = 0.0;

}

// Pre-trial initialization and calculations
void OutOutBehavior::doPreTrial(SimStruct *S) {
	int i; 

	double tloc = 2*PI*random->getInteger(1,params->num_targets)/params->num_targets;

	reach_len = params->movement_length;
	//Set Colors
	t_color = Target::Color(params->targ_color_R, params->targ_color_G, params->targ_color_B);
	
	// Set Target 1
	startTarget->centerX = reach_len*cos(tloc);
	startTarget->centerY = reach_len*sin(tloc);
	startTarget->radius  = params->target_size;
	startTarget->color   = t_color;
	// Set Target 2
	endTarget->centerX = reach_len*cos(tloc+PI);
	endTarget->centerY = reach_len*sin(tloc+PI);
	endTarget->radius  = params->target_size;
	endTarget->color   = t_color;

	// Forces
	double floc = 2*PI*random->getInteger(1,params->num_targets)/params->num_targets;
	forces.x = params->force_mag*cos(floc);
	forces.y = params->force_mag*sin(floc);

	// Randomized Timers
	ct_hold_time		= random->getDouble(params->ct_hold_lo, params->ct_hold_hi);
	ot_hold_time		= random->getDouble(params->ot_hold_lo, params->ot_hold_hi);

	// setup the databurst
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('O');
	db->addByte('O');
	db->addByte('R');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)startTarget->centerX); // targ 1 X
	db->addFloat((float)startTarget->centerY); // targ 1 Y
	db->addFloat((float)endTarget->centerX);  // targ 2 X
	db->addFloat((float)endTarget->centerY);  // targ 2 Y
    db->start();

}

void OutOutBehavior::update(SimStruct *S) {
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
				setState(STATE_CT_ON);
			}
		case STATE_CT_ON:
			/* first target on */
			if (startTarget->cursorInTarget(inputs->cursor)) {
				setState(STATE_CT_HOLD);
			} 
			break;
		case STATE_CT_HOLD:
			if (!startTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			else if (stateTimer->elapsedTime(S) >= ct_hold_time) {
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_MOVEMENT:
			if (stateTimer->elapsedTime(S) > params->movement_time) {
				setState(STATE_INCOMPLETE);
			}
			else if (endTarget->cursorInTarget(inputs->cursor)) {
				setState(STATE_OUTER_HOLD);
			}
			break;
		case STATE_OUTER_HOLD:
			if (stateTimer->elapsedTime(S) >= ot_hold_time) {
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			}
			else if (!endTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			break;
		case STATE_REWARD:
		case STATE_ABORT:
        case STATE_INCOMPLETE:
			if (stateTimer->elapsedTime(S) > params->intertrial_interval) {
				setState(STATE_PRETRIAL);
			}
			break;
		default:
			setState(STATE_PRETRIAL);
	}
}

void OutOutBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
	int i;

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
			case STATE_CT_ON:
				outputs->word = WORD_CT_ON;
				break;
			case STATE_CT_HOLD:
				outputs->word = WORD_CENTER_TARGET_HOLD;
				break;
			case STATE_MOVEMENT:
				outputs->word = WORD_GO_CUE;
				break;
			case STATE_OUTER_HOLD:
				outputs->word = WORD_OUTER_TARGET_HOLD;
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
			default:
				outputs->word = 0;
		}
	} else {
		outputs->word = 0;
	}

	/* force (0) */
	if (getState() == STATE_MOVEMENT ||
		getState() == STATE_OUTER_HOLD){

			outputs->force.x = forces.x;
			outputs->force.y = forces.y;
	} else {

		outputs->force = inputs->force;
	}


	/* target_pos (3) */
	// target 1
	if (getState() == STATE_CT_ON ||
		getState() == STATE_CT_HOLD){
			outputs->targets[0] = (Target *)startTarget;
	} else {
		outputs->targets[0] = nullTarget;
	}
	// target 2
	if (getState() == STATE_MOVEMENT ||
		getState() == STATE_OUTER_HOLD){

			outputs->targets[1] = (Target *)endTarget;
	} else {
		outputs->targets[1] = nullTarget;
	}

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


