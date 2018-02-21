/* $Id: mastercon_COC3D.cpp 2016-12-05 Raeed $
 *
 * Master Control block for behavior: CenterOutCenter3D
 */

#define S_FUNCTION_NAME mastercon_RT3D
#define S_FUNCTION_LEVEL 2
#define TASK_DB_DEFINED 1

#include "words.h"
#include "common_header.cpp"

#define PI (3.141592654)

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_START_TARG_ON 1
#define STATE_START_TARG_HOLD 2
#define STATE_OUTER_TARG_ON 3
#define STATE_MOVEMENT_OUT 4
#define STATE_OUTER_TARG_HOLD 5
#define STATE_FINAL_TARG_ON 6
#define STATE_MOVEMENT_IN 7
#define STATE_FINAL_TARG_HOLD 8

/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */

/* 
 * Current Databurst version: 0
 *
 * Note that all databursts are encoded half a byte at a time as a word who's 
 * high order bits are all 1 and who's low order bits represent the half byte to
 * be transmitted.  Low order bits are transmitted first.  Thus to transmit the
 * two bytes 0xCF 0x07, one would send 0xFF 0xFC 0xF7 0xF0.
 *
 * Databurst version descriptions
 * ==============================
 *
 * Version 0 (0x00)
 * ----------------
 * byte   0: uchar => number of bytes to be transmitted
 * byte   1: uchar => databurst version number (in this case: 0)
 * byte   2 to 4: uchar => task code ('COC')
 * byte   5: uchar => model version major
 * byte   6: uchar => model version minor
 * bytes  7 to  8: short => model version micro
 * bytes  9 to 12: float => outer target number. targets
 *          are numbered 1-7, counter-clockwise, starting from bottom right
 * bytes 13 to 16: float => start (center) target hold time
 * bytes 17 to 20: float => outer target hold time 
 * bytes 21 to 24: float => final (center) target hold time
 * byte  25: uchar => IMU reset on this trial
 */
typedef unsigned char byte;
#define DATABURST_VERSION ((byte)0x00) 

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;

	// Time Bounds for various timers
    real_T st_hold_lo; // start target hold time
    real_T st_hold_hi;
	real_T targ_hold_lo; // outer target hold time
	real_T targ_hold_hi;
    real_T ft_hold_lo; // final target hold time
    real_T ft_hold_hi;

    real_T initial_movement_time; // maximum allowed time to start trial
	real_T movement_max_time;    // maximum allowed movement time

    real_T IMUreset_interval; // interval (in seconds) at which to send reset IMU signal (only when in center target)
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME CenterOutCenter3D
class CenterOutCenter3D : public Behavior3DReach {
public:
	// You must implement these three public methods
	CenterOutCenter3D(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
    int target_index;
	double targ_hold_time;
    double ft_hold_time;

    Timer *IMUreset_timer;
    
    LEDTarget *center_target;
    LEDTarget *outer_target;
   
	LocalParams *params;

	// helper functions
	void doPreTrial(SimStruct *S);
};

CenterOutCenter3D::CenterOutCenter3D(SimStruct *S) : Behavior3DReach() {
	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(10);

	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			0);
	
    // Timing info
	this->bindParamId(&params->st_hold_lo,				1);
	this->bindParamId(&params->st_hold_hi,				2);
	this->bindParamId(&params->targ_hold_lo,			3);
	this->bindParamId(&params->targ_hold_hi,			4);
	this->bindParamId(&params->ft_hold_lo,				5);
	this->bindParamId(&params->ft_hold_hi,				6);

    this->bindParamId(&params->initial_movement_time,   7);
	this->bindParamId(&params->movement_max_time,		8);

	this->bindParamId(&params->IMUreset_inteval,		9);

	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	this->updateParameters(S);

    /* 
	 * Then do any behavior specific initialization 
	 */
    center_target = new LEDTarget();
    outer_target = new LEDTarget();
    
	st_hold_time	     = 0.0;
	targ_hold_time	     = 0.0;
	ft_hold_time	     = 0.0;

    // initialize IMUreset timer
    this->IMUreset_timer = new Timer();
}

// Pre-trial initialization and calculations
void CenterOutCenter3D::doPreTrial(SimStruct *S) {
    /* set first target */
    center_target->target_num = 0;
    
    /* set outer targets */
    outer_target->target_num = random->getInteger(1,7);

    // Randomized Timers
	st_hold_time		= random->getDouble(params->st_hold_lo, params->st_hold_hi);
	targ_hold_time		= random->getDouble(params->targ_hold_lo, params->targ_hold_hi);
	ft_hold_time		= random->getDouble(params->ft_hold_lo, params->ft_hold_hi);

    // make sure IMUreset timer is running
    IMUreset = 0;
    if (!this->IMUreset_timer->isRunning){
        this->IMUreset_timer->start();
    } else if (this->IMUreset_timer->elapsedTime(S) >= IMUreset_interval) {
        IMUreset = 1;
        this->IMUreset_timer->reset(S);
    }

	// setup the databurst
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('C');
	db->addByte('O');
	db->addByte('C');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)(outer_target->target_num));
    db->addFloat((float)(st_hold_time));
    db->addFloat((float)(targ_hold_time));
    db->addFloat((float)(ft_hold_time));
    db->addByte(IMUreset)
    db->start();
    
}

void CenterOutCenter3D::update(SimStruct *S) {
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
               setState(STATE_FIRST_TARG_ON);
           }
       case STATE_START_TARG_ON:
           /* target on */
           if (center_target->handInTarget(inputs->targetStaircase)) {
               setState(STATE_START_TARG_HOLD);
           } else if (stateTimer->elapsedTime(S) > params->initial_movement_time) {
               setState(STATE_INCOMPLETE);
           }
           break;
       case STATE_START_TARG_HOLD:
           // first target hold
           if (!center_target->handInTarget(inputs->targetStaircase)){
               playTone(TONE_ABORT);
               setState(STATE_ABORT);
           } else if (stateTimer->elapsedTime(S) >= st_hold_time) {
               // Outer target on
               playTone(TONE_GO);
               setState(STATE_OUTER_TARG_ON);
           }
           break;
       case STATE_OUTER_TARG_ON:
           if (!center_target->handInTarget(inputs->targetStaircase)){
               setState(STATE_MOVEMENT_OUT);
           }
       case STATE_MOVEMENT_OUT:
           if (stateTimer->elapsedTime(S) > params->movement_max_time) {
               playTone(TONE_FAIL);
               setState(STATE_FAIL);
           }
           else if (outer_target->handInTarget(inputs->targetStaircase)) {
               setState(STATE_OUTER_TARG_HOLD);
           }
           break;
       case STATE_OUTER_TARG_HOLD:
           if (!outer_target->handInTarget(inputs->targetStaircase)){
               playTone(TONE_ABORT);
               setState(STATE_ABORT);
           }
           else if (stateTimer->elapsedTime(S) >= targ_hold_time) {
               // Center target on
               playTone(TONE_GO);
               setState(STATE_FINAL_TARG_ON);
           }
           break;
       case STATE_FINAL_TARG_ON:
           if (!outer_target->handInTarget(inputs->targetStaircase)){
               setState(STATE_MOVEMENT_IN);
           }
       case STATE_MOVEMENT_IN:
           if (stateTimer->elapsedTime(S) > params->movement_max_time) {
               playTone(TONE_FAIL);
               setState(STATE_FAIL);
           }
           else if (center_target->handInTarget(inputs->targetStaircase)) {
               setState(STATE_FINAL_TARG_HOLD);
           }
           break;
       case STATE_FINAL_TARG_HOLD:
           if (!center_target->handInTarget(inputs->targetStaircase)){
               playTone(TONE_ABORT);
               setState(STATE_ABORT);
           }
           else if (stateTimer->elapsedTime(S) >= ft_hold_time) {
               // Center target on
               playTone(TONE_REWARD);
               setState(STATE_REWARD);
           }
           break;
       case STATE_REWARD:
       case STATE_ABORT:
       case STATE_INCOMPLETE:
       case STATE_FAIL:
       default:
           setState(STATE_PRETRIAL);
	}
}

void CenterOutCenter3D::calculateOutputs(SimStruct *S) {
    /* declarations */
    LEDTarget *currentTarget = targets[target_index];


	/* status (0) */
	outputs->status[0] = getState();
	outputs->status[1] = trialCounter->successes;
	outputs->status[2] = trialCounter->aborts;
	outputs->status[3] = trialCounter->failures;
	outputs->status[4] = trialCounter->incompletes;

	/* word (1) */
	if (db->isRunning()) {
		outputs->word = db->getByte();
	} else if (isNewState()) {
		switch (getState()) {
			case STATE_PRETRIAL:
				outputs->word = WORD_START_TRIAL;
				break;
			case STATE_START_TARG_ON:
				outputs->word = WORD_CT_ON;
				break;
			case STATE_FIRST_TARG_HOLD:
				outputs->word = WORD_CENTER_TARGET_HOLD;
				break;
			case STATE_OUTER_TARG_ON:
                outputs->word = WORD_GO_CUE;
                break;
			case STATE_MOVEMENT_OUT:
                outputs->word = WORD_LEAVE_CT;
				break;
			case STATE_OUTER_TARG_HOLD:
				outputs->word = WORD_OUTER_TARGET_HOLD;
				break;
			case STATE_FINAL_TARG_ON:
                outputs->word = WORD_GO_CUE_BACK;
                break;
			case STATE_MOVEMENT_IN:
                outputs->word = WORD_LEAVE_OT;
				break;
			case STATE_FINAL_TARG_HOLD:
				outputs->word = WORD_FINAL_TARGET_HOLD;
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
                break;
			default:
				outputs->word = 0;
		}
	} else {
		outputs->word = 0;
	}

	/* reward (2) */
	outputs->reward = (isNewState() && getState() == STATE_REWARD);

	/* tone (3) */
	this->outputs->tone_counter = this->tone_counter;
	this->outputs->last_tone_id = this->last_tone_id;

	/* version (4) */
	outputs->version[0] = BEHAVIOR_VERSION_MAJOR;
	outputs->version[1] = BEHAVIOR_VERSION_MINOR;
	outputs->version[2] = BEHAVIOR_VERSION_MICRO;
    outputs->version[3] = BEHAVIOR_VERSION_BUILD;
    
    /* target (5) */
    if (this->getState() == STATE_OUTER_TARG_ON ||
            this->getState() == STATE_MOVEMENT_OUT ||
            this->getState() == STATE_OUTER_TARG_HOLD){
        outputs->target = outer_target;
    } else {
        outputs->target = center_target;
    }
    
    /* IMU reset (6) */
    if (getState() == STATE_FIRST_TARG_HOLD){
        outputs->IMUreset = 1;
    } else {
        outputs->IMUreset = 0;
    };
}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer_3d_reach.cpp"
