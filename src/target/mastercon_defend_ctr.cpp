/* $Id: $
 *
 * Master Control block for behavior: bump psychophysics 2-bump choice
 */

#pragma warning(disable: 4800)

#define S_FUNCTION_NAME mastercon_defend_ctr
#define S_FUNCTION_LEVEL 2

// Our task code will be in the databurst
#define TASK_DB_DEFINED 1
#include "words.h"

#include "common_header.cpp"

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_CT_ON 1
#define STATE_CT_HOLD 2
#define STATE_CT_BLOCK 3
#define STATE_STIM 4
#define STATE_BUMP 5
#define STATE_MOVEMENT 6
#define STATE_PENALTY 7

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
	db->addByte(DATABURST_VERSION);
	db->addByte('2');
	db->addByte('D');
	db->addByte('C');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)this->bump_dir);
	db->addFloat((float)this->bumpmag_local);
	db->addFloat((float)this->params->bump_duration);
	db->addFloat((float)this->params->bump_ramp);
	db->addFloat((float)this->params->bump_floor);
	db->addFloat((float)this->params->bump_ceiling);
	db->addFloat((float)this->params->target_size);
	db->addFloat((float)this->params->big_target);
	db->addFloat((float)this->params->intertrial_time);
	db->addFloat((float)this->params->penalty_time);
	db->addFloat((float)this->params->bump_hold_time);
	db->addFloat((float)this->params->ct_hold_time);
	db->addFloat((float)this->bumpdelay);
	db->addByte((byte)this->stim_trial);
	db->addFloat((float)this->params->stim_prob);
	db->addFloat((float)this->params->bump_incr);
 */
	
#define DATABURST_VERSION ((byte)0x00) 
#define DATABURST_TASK_CODE ((byte)0x01)

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;
	real_T soft_reset;
	real_T target_size;
	real_T big_target;
	real_T bump_magnitude;
	real_T bump_duration;
    real_T bump_ramp;
	real_T ct_hold_time;
	real_T bump_delay_time;
	real_T bump_delay_rand;
	real_T bump_hold_time;
	real_T intertrial_time;
	real_T hide_cursor;
	real_T stim_prob;
	real_T penalty_time;
	real_T bump_floor;
	real_T bump_ceiling;
    real_T bump_incr;
	real_T stim_levels;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */

#define MY_CLASS_NAME DefendCenterBehavior
class DefendCenterBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	DefendCenterBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	CircleTarget *centerTarget;
	SquareTarget *errorTarget;
    
	bool stim_trial;

	int bump_dir;
	float bumpmag_local;
	float bumpdelay;
    float catch_rate;

	CosineBumpGenerator *bump;

	LocalParams *params;
	real_T last_soft_reset;

	int bump_quadrent;

	// any helper functions you need
	void doPreTrial(SimStruct *S);

};

DefendCenterBehavior::DefendCenterBehavior(SimStruct *S) : RobotBehavior() {


	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(19);
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			0);
	this->bindParamId(&params->soft_reset,				1);
	this->bindParamId(&params->target_size,				2);
	this->bindParamId(&params->big_target,				3);
	this->bindParamId(&params->bump_magnitude,			4);
	this->bindParamId(&params->bump_duration,			5);
    this->bindParamId(&params->bump_ramp,				6);
	this->bindParamId(&params->ct_hold_time,			7);
	this->bindParamId(&params->bump_delay_time,			8);
	this->bindParamId(&params->bump_delay_rand,			9);
	this->bindParamId(&params->bump_hold_time,			10);
	this->bindParamId(&params->intertrial_time,			11);
	this->bindParamId(&params->hide_cursor,				12);
	this->bindParamId(&params->stim_prob,				13);
	this->bindParamId(&params->penalty_time,			14);
	this->bindParamId(&params->bump_floor,				15);
	this->bindParamId(&params->bump_ceiling,			16);
    this->bindParamId(&params->bump_incr,           	17);
	this->bindParamId(&params->stim_levels,				18);
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);
	
	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
	
	last_soft_reset = -1; // force a soft reset of first trial

	centerTarget = new CircleTarget();
	centerTarget->color = Target::Color(128, 128, 128);
    centerTarget->centerX = 0;
	centerTarget->centerY = 0;

	errorTarget = new SquareTarget(0, 0, 100, Target::Color(255, 255, 255));



	this->stim_trial = false;
	this->catch_rate = 0.1;//this is a stupid hardcode until I get rount to implementing a link to the graphics panel for dynamic setting
	this->bump_dir = 0;
	this->bump = new CosineBumpGenerator();

}


void DefendCenterBehavior::doPreTrial(SimStruct *S) {
    int num_bump_dirs; // number of bump directions there will be between bump_floor and bump_ceiling


	// Set up target locations, etc.
	centerTarget->radius = params->target_size;
    
 	//select a random bump direction. 
    num_bump_dirs = (int)((this->params->bump_ceiling - this->params->bump_floor)/this->params->bump_incr);
	bump_dir = (int)this->params->bump_floor + (int)this->params->bump_incr * (this->random->getInteger(0,num_bump_dirs)); 
	this->bump->direction = ((double)this->bump_dir) * PI/180;

	// Set up the bump itself
	if(catch_rate>0){
		if(this->random->getInteger(1,10)>1){
			bumpmag_local=(float)params->bump_magnitude;
		} else {
			bumpmag_local=0;
		}
	} else {
		bumpmag_local=(float)params->bump_magnitude;
	}
    this->bump->peak_magnitude = bumpmag_local;
	this->bump->hold_duration = params->bump_duration;
	this->bump->rise_time = params->bump_ramp;

	this->bumpdelay=params->bump_delay_time+this->random->getDouble(0,params->bump_delay_rand);
    
    /* Select whether this will be a stimulation trial */
    this->stim_trial=(this->random->getDouble() < params->stim_prob);

	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('2');
	db->addByte('D');
	db->addByte('C');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)this->bump_dir);
	db->addFloat((float)this->bumpmag_local);
	db->addFloat((float)this->params->bump_duration);
	db->addFloat((float)this->params->bump_ramp);
	db->addFloat((float)this->params->bump_floor);
	db->addFloat((float)this->params->bump_ceiling);
	db->addFloat((float)this->params->target_size);
	db->addFloat((float)this->params->big_target);
	db->addFloat((float)this->params->intertrial_time);
	db->addFloat((float)this->params->penalty_time);
	db->addFloat((float)this->params->bump_hold_time);
	db->addFloat((float)this->params->ct_hold_time);
	db->addFloat((float)this->bumpdelay);
	db->addByte((byte)this->stim_trial);
	db->addFloat((float)this->params->stim_prob);
	db->addFloat((float)this->params->bump_incr);
	db->start();
}

void DefendCenterBehavior::update(SimStruct *S) {
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
			break;
		case STATE_CT_ON:
			/* first target on */
			if (centerTarget->cursorInTarget(inputs->cursor)) {
				setState(STATE_CT_HOLD);
			}
			break;
		case STATE_CT_HOLD:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > params->ct_hold_time) {
                centerTarget->radius = params->big_target;
				setState(STATE_CT_BLOCK);
			}
			break;
		case STATE_CT_BLOCK:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > this->bumpdelay) {
				bump->start(S);
				if (this->stim_trial) {
					setState(STATE_STIM);
				} else {
					setState(STATE_BUMP);
				}
			}
			break;
		case STATE_BUMP:
			if (stateTimer->elapsedTime(S) > params->bump_hold_time) {
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_STIM:
			setState(STATE_BUMP);
			break;
		case STATE_MOVEMENT:
			if (centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			} else  {
				playTone(TONE_FAIL);
				if (this->params->penalty_time > 0) {
					setState(STATE_PENALTY);
				} else {
					setState(STATE_FAIL);
				}
			}
			break;
		case STATE_PENALTY:
			if (stateTimer->elapsedTime(S) > params->penalty_time) {
				setState(STATE_FAIL);
			}
			break;
		case STATE_ABORT:
        case STATE_REWARD:
		case STATE_FAIL:
        case STATE_INCOMPLETE:
			this->bump->stop();
			if (stateTimer->elapsedTime(S) > params->intertrial_time) {
				setState(STATE_PRETRIAL);
			}
			break;
		default:
			setState(STATE_PRETRIAL);
	}
}

void DefendCenterBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
    Point bf;

	/* force (0) */
	if (bump->isRunning(S)) {
		bf = bump->getBumpForce(S);
		outputs->force.x = inputs->force.x + bf.x;
		outputs->force.y = inputs->force.y + bf.y;
	} else {
		outputs->force = inputs->force;
	}

	/* status (1) */
 	outputs->status[0] = getState();
  	outputs->status[1] = trialCounter->successes;

  	outputs->status[2] = trialCounter->aborts;

 	outputs->status[3] = trialCounter->failures;
 	outputs->status[4] = (int)(180/PI)*this->bump->direction;
    
    outputs->status[3] = -1;
    outputs->status[4] = params->target_size;
      
	/* word(2) */
	if (db->isRunning()) {
		outputs->word = db->getByte();
	} else if (isNewState()) {
		switch (getState()) {
			case STATE_PRETRIAL:
				outputs->word = WORD_START_TRIAL;
				break;
			case STATE_CT_BLOCK:
				outputs->word = WORD_OT_ON(0);
				break;
			case STATE_STIM:
				outputs->word = WORD_STIM(this->random->getInteger(0,(int)this->params->stim_levels));
				break;
			case STATE_BUMP:
				outputs->word = WORD_BUMP(0);
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
	// Center Target    
	if (getState() == STATE_CT_ON || getState() == STATE_CT_HOLD ) {
		outputs->targets[0] = (Target *)(this->centerTarget);		
	} else if (getState() == STATE_CT_BLOCK || getState() == STATE_BUMP){
        outputs->targets[0] = (Target *)(this->centerTarget);
	} else if (getState() == STATE_MOVEMENT) {
		outputs->targets[0] = (Target *)(this->centerTarget);
	} else if (getState() == STATE_PENALTY) {
		outputs->targets[0] = (Target *)(this->errorTarget);
	} else {
		outputs->targets[0] = nullTarget;
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
    if ((getState() == STATE_CT_BLOCK || getState() == STATE_BUMP) && (params->hide_cursor > .1))
    {
        outputs->position = Point(1E6, 1E6);
    } else { 
        outputs->position = inputs->cursor;

    } 
}

/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


