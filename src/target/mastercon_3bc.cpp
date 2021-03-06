/* $Id: $
 *
 * Master Control block for behavior: bump psychophysics 2-bump choice
 */

#pragma warning(disable: 4800)


#define S_FUNCTION_NAME mastercon_3bc
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
 * Current Databurst version: 3
 *
 * Note that all databursts are encoded half a byte at a time as a word who's 
 * high order bits are all 1 and who's low order bits represent the half byte to
 * be transmitted.  Low order bits are transmitted first.  Thus to transmit the
 * two bytes 0xCF 0x07, one would send 0xFF 0xFC 0xF7 0xF0.
 *
 * Databurst version descriptions
 * ==============================
 *
 * Version 4 (0x04)
 * ----------------
 * byte  0:		uchar		=> number of bytes to be transmitted
 * byte  1:		uchar		=> version number (in this case one)
 * byte  2:		uchar		=> task code (0x01)
 * bytes 3-6:	uchar       => version code
 * byte  7-8:	uchar		=> version code (micro)
 * bytes 9-12:  float		=> target angle
 * bytes 13-16: float		=> bump direction
 * byte  17:	uchar		=> random target flag
 * bytes 18-21: float		=> target floor (minimum angle(deg) target can take in random target assignment)
 * bytes 22-25: float		=> target ceiling (maximum angle(deg) target can take in random target assignment)
 * bytes 26-29: float		=> bump magnitude
 * bytes 30-33: float		=> bump duration
 * bytes 34-37: float		=> bump ramp
 * bytes 38-41: float		=> bump floor (minimum angle(deg) bump can take in random target assignment)
 * bytes 42-45:	float		=> bump ceiling (maximum angle(deg) bump can take in random target assignment)
 * byte  46:	uchar		=> stim trial flag
 * byte  47:    uchar       => training trial flag
 * bytes 48-51: float		=> training trial frequency
 * bytes 52-55: float		=> stimulation probability 
 * byte  56:	uchar		=> recenter cursor flag
 * bytes 57-60: float		=> target radius
 * bytes 61-64: float		=> target size
 * bytes 65-68: float		=> intertrial time
 * bytes 69-72: float		=> penalty time
 * bytes 73-76: float		=> bump hold time
 * bytes 77-80: float		=> center hold time
 * bytes 81-84: float		=> bump delay time
 * byte  85:	uchar		=> show target during bump
 * bytes 86-89:	float		=> bump incriment
 * byte	 90		uchar		=> is primary target
 */
	
#define DATABURST_VERSION ((byte)0x04) 
#define DATABURST_TASK_CODE ((byte)0x01)


// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;
	real_T soft_reset;
	real_T target_size;
	real_T target_radius;
	real_T big_target;
	real_T target_angle_min;
	real_T bump_magnitude;
	real_T bump_duration;
    real_T bump_ramp;
	real_T ct_hold_time;
	real_T bump_delay_time;
	real_T bump_hold_time;
	real_T intertrial_time;
	real_T green_prim_targ;
	real_T hide_cursor;
	real_T stim_prob;
	real_T penalty_time;
    real_T recenter_cursor;
	real_T training_frequency;
	real_T use_random_targets;
	real_T target_floor;
	real_T target_ceiling;
	real_T bump_floor;
	real_T bump_ceiling;
	real_T show_target_during_bump;
    real_T bump_incr;
	real_T stim_levels;
	real_T catch_rate;
	real_T abort_during_bump;
    real_T num_targets;
    real_T angle_tolerance;
    real_T use_bump_mapping;
    real_T p1;
    real_T p2;
    real_T p3;
    real_T p4;
    real_T p5;
    real_T p6;
    real_T show_ring_prob;
    real_T target_angle_max;
    real_T num_target_angles;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME TwoBumpChoiceBehavior
class TwoBumpChoiceBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	TwoBumpChoiceBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	CircleTarget *centerTarget;
	CircleTarget *primaryTarget;
	CircleTarget *secondaryTarget;
    
	SquareTarget *errorTarget;
    
	bool stim_trial;

	int bump_dir;
	float bumpmag_local;
    Point cursorOffset;

	CosineBumpGenerator *bump;

	LocalParams *params;
	real_T last_soft_reset;

	bool training_trial;
	int tgt_angle;
	int bump_quadrent;
	bool is_primary_target;
	// any helper functions you need
	void doPreTrial(SimStruct *S);

};

TwoBumpChoiceBehavior::TwoBumpChoiceBehavior(SimStruct *S) : RobotBehavior() {
	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(41);
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			0);
	this->bindParamId(&params->soft_reset,				1);
	this->bindParamId(&params->target_size,				2);
	this->bindParamId(&params->target_radius,			3);
	this->bindParamId(&params->big_target,				4);
	this->bindParamId(&params->target_angle_min,			5);
	this->bindParamId(&params->bump_magnitude,			6);
	this->bindParamId(&params->bump_duration,			7);
    this->bindParamId(&params->bump_ramp,				8);
	this->bindParamId(&params->ct_hold_time,			9);
	this->bindParamId(&params->bump_delay_time,			10);
	this->bindParamId(&params->bump_hold_time,			11);
	this->bindParamId(&params->intertrial_time,			12);
	this->bindParamId(&params->green_prim_targ,			13);
	this->bindParamId(&params->hide_cursor,				14);
	this->bindParamId(&params->stim_prob,				15);
	this->bindParamId(&params->penalty_time,			16);
	this->bindParamId(&params->recenter_cursor,			17);
	this->bindParamId(&params->training_frequency,		18);
	this->bindParamId(&params->use_random_targets,		19);
	this->bindParamId(&params->target_floor,			20);
	this->bindParamId(&params->target_ceiling,			21);
	this->bindParamId(&params->bump_floor,				22);
	this->bindParamId(&params->bump_ceiling,			23);
	this->bindParamId(&params->show_target_during_bump,	24);
    this->bindParamId(&params->bump_incr,           	25);
	this->bindParamId(&params->stim_levels,				26);
	this->bindParamId(&params->catch_rate,				27);
	this->bindParamId(&params->abort_during_bump,		28);
    this->bindParamId(&params->num_targets,             29);
    this->bindParamId(&params->angle_tolerance,         30);
    this->bindParamId(&params->use_bump_mapping,        31);
    this->bindParamId(&params->p1,                      32);
    this->bindParamId(&params->p2,                      33);
    this->bindParamId(&params->p3,                      34);
    this->bindParamId(&params->p4,                      35);
    this->bindParamId(&params->p5,                      36);
    this->bindParamId(&params->p6,                      37);
    this->bindParamId(&params->show_ring_prob,          38);
    this->bindParamId(&params->target_angle_max,        39);
    this->bindParamId(&params->num_target_angles,       40);
    
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);
	
	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
	
	last_soft_reset = -1; // force a soft reset of first trial

	centerTarget = new CircleTarget();
	primaryTarget = new CircleTarget(); 
	secondaryTarget = new CircleTarget(); 
    
	centerTarget->color = Target::Color(128, 128, 128);
	primaryTarget->color = Target::Color(160, 255, 0);
	secondaryTarget->color = Target::Color(255, 0, 160);
    
	errorTarget = new SquareTarget(0, 0, 100, Target::Color(255, 255, 255));

	this->stim_trial = false;
	this->bump_dir = 0;
	this->bump = new CosineBumpGenerator();
	this->training_trial=0;
	this->tgt_angle=0;
    
}


void TwoBumpChoiceBehavior::doPreTrial(SimStruct *S) {
    int num_bump_dirs; // number of bump directions there will be between bump_floor and bump_ceiling

	//set the target direction
	if ((int)this->params->use_random_targets) {
		this->tgt_angle = this->random->getInteger((int)this->params->target_floor,(int)this->params->target_ceiling);
	} else if(this->params->num_target_angles > 1) {
        int tgt_angle_idx = (this->random->getInteger(0,(int)this->params->num_target_angles));
		this->tgt_angle = (int)((180/PI)*(tgt_angle_idx*(this->params->target_angle_max - this->params->target_angle_min)/(this->params->num_target_angles-1) + this->params->target_angle_min));
    } else {
        this->tgt_angle = (int)((180/PI)*this->params->target_angle_min);
    }

	// Set up target locations, etc.
	centerTarget->radius = params->target_size+1.0;

	primaryTarget->radius = params->target_size;
	primaryTarget->centerX = params->target_radius*cos((float)this->tgt_angle * PI/180);
	primaryTarget->centerY = params->target_radius*sin((float)this->tgt_angle * PI/180);
	
	secondaryTarget->radius = params->target_size;
	secondaryTarget->centerX = params->target_radius*cos(PI + (float)this->tgt_angle * PI/180);
	secondaryTarget->centerY = params->target_radius*sin(PI + (float)this->tgt_angle * PI/180);
    
    // Reset cursor offset
    cursorOffset.x = 0;
    cursorOffset.y = 0;
    
	//select a random bump direction. 
    num_bump_dirs = (int)((this->params->bump_ceiling - this->params->bump_floor)/this->params->bump_incr);
	this->bump_quadrent = this->random->getInteger(0,3);
	switch (this->bump_quadrent){
		case 0:
			//bumps in the 0-90deg quadrent
            bump_dir = (int)this->params->bump_floor + (int)this->params->bump_incr * (this->random->getInteger(0,num_bump_dirs)); 
			this->is_primary_target=true;
			break;
		case 1:
			//bumps in the 90-180deg quadrent
            bump_dir=180 - (int)this->params->bump_floor - (int)this->params->bump_incr * (this->random->getInteger(0,num_bump_dirs));
			this->is_primary_target=false;
			break;
		case 2:
			//bumps in the 180-270deg quadrent
            bump_dir = 180 + (int)this->params->bump_floor + (int)this->params->bump_incr * (this->random->getInteger(0,num_bump_dirs));
			this->is_primary_target=false;
			break;
		default:
			//bumps in the 270-360deg quadrent
			bump_dir=360 - (int)this->params->bump_floor - (int)this->params->bump_incr * (this->random->getInteger(0,num_bump_dirs));
			this->is_primary_target=true;
			break;
	}

	// Set up the bump itself
	if(params->catch_rate>0){
		if(this->random->getDouble()>params->catch_rate){
			bumpmag_local=(float)params->bump_magnitude;
		} else {
			bumpmag_local=0;
		}
	} else {
		bumpmag_local=(float)params->bump_magnitude;
	}
	this->bump->hold_duration = params->bump_duration;
    this->bump->peak_magnitude = bumpmag_local;
	this->bump->rise_time = params->bump_ramp;
	this->bump->direction = ((double)(this->tgt_angle + this->bump_dir)) * PI/180;

	// Reset primary target color if needed
    if(params->green_prim_targ){
        // do nothing because default is green
    }
    else{
        primaryTarget->color = Target::Color(255, 0, 160);
    }
	/* Select whether this will be a training trial 
	*  If the training frequency is zero we should not see any training trials*/
	training_trial=(this->random->getDouble() < params->training_frequency);
    
    /* Select whether this will be a stimulation trial */
    this->stim_trial=(this->random->getDouble() < params->stim_prob);

	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('2');
	db->addByte('B');
	db->addByte('C');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)this->tgt_angle);
	db->addFloat((float)this->bump_dir);
	db->addByte((byte)this->params->use_random_targets);
	db->addFloat((float)this->params->target_floor);
	db->addFloat((float)this->params->target_ceiling);
	db->addFloat((float)this->bumpmag_local);
	db->addFloat((float)this->params->bump_duration);
	db->addFloat((float)this->params->bump_ramp);
	db->addFloat((float)this->params->bump_floor);
	db->addFloat((float)this->params->bump_ceiling);
	db->addByte((byte)this->stim_trial);
	db->addByte((byte)this->training_trial);
	db->addFloat((float)this->params->training_frequency);
	db->addFloat((float)this->params->stim_prob);
	db->addByte((byte)this->params->recenter_cursor);
	db->addFloat((float)this->params->target_radius);
	db->addFloat((float)this->params->target_size);
	db->addFloat((float)this->params->intertrial_time);
	db->addFloat((float)this->params->penalty_time);
	db->addFloat((float)this->params->bump_hold_time);
	db->addFloat((float)this->params->ct_hold_time);
	db->addFloat((float)this->params->bump_delay_time);
	db->addByte((byte)this->params->show_target_during_bump);
	db->addFloat((float)this->params->bump_incr);
	db->addByte((byte)this->is_primary_target);
	db->start();
}

void TwoBumpChoiceBehavior::update(SimStruct *S) {
	Target *correctTarget;
	Target *incorrectTarget;
	
	if (training_trial) {
		if (this->is_primary_target) {
			// want to be in primary target
			correctTarget = primaryTarget;
			incorrectTarget = nullTarget;
		} else {
			// staircase_id == 1
			// want to be in secondary target
			correctTarget = secondaryTarget;
			incorrectTarget = nullTarget;
		}
	} else {
		if (this->is_primary_target) {
			// want to be in primary target
			correctTarget = primaryTarget;
			incorrectTarget = secondaryTarget;
		} else {
			// staircase_id == 1
			// want to be in secondary target
			correctTarget = secondaryTarget;
			incorrectTarget = primaryTarget;
		}
	}

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
			} else if (stateTimer->elapsedTime(S) > params->bump_delay_time) {
				bump->start(S);
				if (this->stim_trial) {
					setState(STATE_STIM);
				} else {
					setState(STATE_BUMP);
				}
			}
			break;
		case STATE_BUMP:
			if (!centerTarget->cursorInTarget(inputs->cursor) && params->abort_during_bump) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > params->bump_hold_time) {
				playTone(TONE_GO);
                if (params->recenter_cursor) {
                    cursorOffset = inputs->cursor;
                }   
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_STIM:
			setState(STATE_BUMP);
			break;
		case STATE_MOVEMENT:
			if (correctTarget->cursorInTarget(inputs->cursor - cursorOffset)) {
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			} else if (incorrectTarget->cursorInTarget(inputs->cursor - cursorOffset)) {
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

void TwoBumpChoiceBehavior::calculateOutputs(SimStruct *S) {
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
    //outputs->status[0] = inputs->force.x;
    //outputs->status[1] = inputs->force.y;
	outputs->status[2] = trialCounter->aborts;
	outputs->status[3] = trialCounter->failures;
 	outputs->status[4] = trialCounter->incompletes;
// 	outputs->status[0] = (int)this->bump_dir;
//	outputs->status[1] = (int)this->tgt_angle;
//	outputs->status[2] = trialCounter->aborts;
//	outputs->status[3] = trialCounter->failures;
//  outputs->status[4] = params->abort_during_bump;
  
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
	if (getState() == STATE_CT_ON || 
	    getState() == STATE_CT_HOLD ) 
	{
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
	} else if
        (getState() == STATE_CT_BLOCK ||
         getState() == STATE_BUMP) 
	{
		outputs->targets[0] = (Target *)centerTarget;
		if (this->params->show_target_during_bump) {
			if (this->training_trial) {
				if(this->is_primary_target) {
                    outputs->targets[1] = (Target *)(this->primaryTarget);
			        outputs->targets[2] = nullTarget;
				} else {
                    outputs->targets[1] = (Target *)(this->secondaryTarget);
			        outputs->targets[2] = nullTarget; 
				}
			} else {
				outputs->targets[1] = (Target *)(this->primaryTarget);
		        outputs->targets[2] = (Target *)(this->secondaryTarget);
			}
		} else {
            outputs->targets[1] = nullTarget;
            outputs->targets[2] = nullTarget;
		}
	} else if (getState() == STATE_MOVEMENT) {
        outputs->targets[0] = (Target *)(this->primaryTarget);
		outputs->targets[1] = (Target *)(this->secondaryTarget);
        
		if (this->training_trial) {
			if(this->is_primary_target) {
                outputs->targets[0] = (Target *)(this->primaryTarget);
		        outputs->targets[1] = nullTarget;
				outputs->targets[2] = nullTarget; 
			} else {
                outputs->targets[0] = (Target *)(this->secondaryTarget);
				outputs->targets[1] = nullTarget;
		        outputs->targets[2] = nullTarget;
			}
		} else {
            outputs->targets[0] = (Target *)(this->primaryTarget);
	        outputs->targets[1] = (Target *)(this->secondaryTarget);
			outputs->targets[2] = nullTarget;
		}
	} else if (getState() == STATE_PENALTY) {
		outputs->targets[0] = (Target *)(this->errorTarget);
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
        outputs->targets[3] = nullTarget;
	} else {
		outputs->targets[0] = nullTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
        outputs->targets[3] = nullTarget;
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
    } else { //if ( (params->recenter_cursor) && (getState() == STATE_MOVEMENT) ) {
        outputs->position = inputs->cursor - cursorOffset;
//    } else {
//    	outputs->position = inputs->cursor;
    } 
}

/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


