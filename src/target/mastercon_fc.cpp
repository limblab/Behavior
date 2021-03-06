
/* $Id: $
 *
 * Master Control block for behavior: bump psychophysics 2-bump choice
 */

#pragma warning(disable: 4800)


#define S_FUNCTION_NAME mastercon_fc
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
 * Current Databurst version: 1 (version 0 is for the old c code- no version 0 exists for this cpp code)
 *
 * Note that all databursts are encoded half a byte at a time as a word who's 
 * high order bits are all 1 and who's low order bits represent the half byte to
 * be transmitted.  Low order bits are transmitted first.  Thus to transmit the
 * two bytes 0xCF 0x07, one would send 0xFF 0xFC 0xF7 0xF0.
 *
 * Databurst version descriptions
 * ==============================
 *
 * Version 1 (0x01)
 * ----------------
 * byte  0:		uchar		=> number of bytes to be transmitted
 * byte  1:		uchar		=> version number (in this case one)
 * byte  2-3:	uchar		=> task code ('FC')
 * bytes 4-5:	uchar       => version code
 * byte  5-6:	uchar		=> version code (micro)
 *
 * bytes 7-8:  float		=> target angle
 * byte  9:	uchar		=> random target flag
 * bytes 10-13: float		=> target radius
 * bytes 14-17: float		=> target size
 * byte  18:	uchar		=> show target during bump
 *
 * byte  19:                => bump trial flag
 * bytes 20-23: float		=> bump direction
 * bytes 24-27: float       => bump magnitude
 * bytes 28-31: float		=> bump floor (minimum force(N) bump can take)
 * bytes 32-35:	float		=> bump ceiling (maximum force(N) bump can take)
 * bytes 36-39:	float		=> bump step
 * bytes 40-43: float		=> bump duration
 * bytes 44-47: float		=> bump ramp
 *
 * byte  48:	uchar		=> stim trial flag
 * bytes 49:    uchar       => stim code
 *
 * byte  50:    uchar       => training trial flag
 *
 * byte  51:	uchar		=> recenter cursor flag
 * byte  52:    uchar       => hide cursor during bump
 *
 * bytes 53-56: float		=> intertrial time
 * bytes 57-60: float		=> penalty time
 * bytes 61-64: float		=> bump hold time
 * bytes 65-68: float		=> center hold time
 * bytes 69-72: float		=> bump delay time
 */
	
#define DATABURST_VERSION ((byte)0x01) 
#define DATABURST_TASK_CODE ((byte)0x01)


// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;
	real_T soft_reset;
    
	real_T target_size;
	real_T target_radius;
    real_T target_angle;
	real_T use_random_targets;
	real_T show_target_during_bump;
	
    real_T bump_prob;
    real_T bump_direction;
	real_T bump_floor;
	real_T bump_ceiling;
    real_T bump_step;
	real_T bump_duration;
    real_T bump_ramp;
	
    real_T ct_hold_time;
	real_T bump_delay_low;
	real_T bump_delay_high;
	real_T bump_hold_time;
    real_T reaction_time;
	real_T intertrial_time;
	real_T penalty_time;
    
	real_T hide_cursor;
	real_T recenter_cursor;
	
    real_T stim_prob;
	real_T stim_levels;
    
    real_T training_frequency;
	real_T abort_during_bump;
    real_T force_reaction;
};

#define MY_CLASS_NAME ForcedChoiceBehavior
class ForcedChoiceBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	ForcedChoiceBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
    LocalParams *params;
	CosineBumpGenerator *bump;
    Staircase *bump_stair;
    Staircase *stim_stair;

    CircleTarget *centerTarget;     //target for monkey to hold on while waiting for stimulus
	CircleTarget *primaryTarget;    //correct when stimulus is present
	CircleTarget *secondaryTarget;  //correct when no stimulus present
	SquareTarget *errorTarget;      //used as gray mask to indicate error during intertrial
    
	bool bump_trial;
    bool stim_trial;
	bool training_trial;

	int bump_dir;
	int tgt_dir;
    float bump_mag;
    float bump_delay;
    int bump_steps;
    int stim_code;
    
    Point cursorOffset;

	real_T last_soft_reset;

	// any helper functions you need
	void doPreTrial(SimStruct *S);

};

ForcedChoiceBehavior::ForcedChoiceBehavior(SimStruct *S) : RobotBehavior() {
	params = new LocalParams();
    //create binding map for pulling variables from simulink into the params struct
	this->setNumParams(28);
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			0);
	this->bindParamId(&params->soft_reset,				1);
    
	this->bindParamId(&params->target_size,				2);
	this->bindParamId(&params->target_radius,			3);
	this->bindParamId(&params->target_angle,			4);
	this->bindParamId(&params->use_random_targets,		5);
	this->bindParamId(&params->show_target_during_bump,	6);
    
    this->bindParamId(&params->bump_prob,               7);
    this->bindParamId(&params->bump_direction,          8);
    this->bindParamId(&params->bump_floor,				9);
	this->bindParamId(&params->bump_ceiling,			10);
    this->bindParamId(&params->bump_step,           	11);
	this->bindParamId(&params->bump_duration,			12);
    this->bindParamId(&params->bump_ramp,				13);
    
	this->bindParamId(&params->ct_hold_time,			14);
	this->bindParamId(&params->bump_delay_low,			15);
    this->bindParamId(&params->bump_delay_high,			16);
    this->bindParamId(&params->bump_hold_time,			17);
    this->bindParamId(&params->reaction_time,			18);
    this->bindParamId(&params->intertrial_time,			19);
	this->bindParamId(&params->penalty_time,			20);
    
	this->bindParamId(&params->hide_cursor,				21);
	this->bindParamId(&params->recenter_cursor,			22);
    
	this->bindParamId(&params->stim_prob,				23);
	this->bindParamId(&params->stim_levels,				24);
    
	this->bindParamId(&params->training_frequency,		25);
	this->bindParamId(&params->abort_during_bump,		26);
	this->bindParamId(&params->force_reaction,  		27);
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);
	
	last_soft_reset = -1; // force a soft reset of first trial
    //define targets
	centerTarget = new CircleTarget();
	primaryTarget = new CircleTarget(); 
	secondaryTarget = new CircleTarget(); 

	centerTarget->color = Target::Color(128, 128, 128);
	primaryTarget->color = Target::Color(160, 255, 0);
	secondaryTarget->color = Target::Color(255, 0, 160);

	errorTarget = new SquareTarget(0, 0, 100, Target::Color(255, 255, 255));
    // establish flags (default false)
	this->bump_trial = false;
	this->stim_trial = false;
	this->training_trial = false;
    // establish bump/target directions
	this->bump_dir = 0;
	this->tgt_dir = 0;
    //initialize the bump generator
	this->bump = new CosineBumpGenerator();
    //initialize the staircases
    this->bump_stair->setStepSize(params->bump_step);
    this->bump_steps=(int)floor((params->bump_ceiling-params->bump_floor)/params->bump_step);
    this->bump_stair->setCurrentValue(this->bump_steps/2);
    this->bump_stair->setForwardLimit(this->bump_steps);
    this->bump_stair->setBackwardLimit(0);
    this->stim_stair->setStepSize(1);
    this->stim_stair->setCurrentValue(params->stim_levels/2);
    this->stim_stair->setForwardLimit(params->stim_levels);
    this->stim_stair->setBackwardLimit(0);
}


void ForcedChoiceBehavior::doPreTrial(SimStruct *S) {
    
	//set the target direction deg
	if ((int)this->params->use_random_targets) {
		this->tgt_dir = this->random->getInteger(0,359);
	} else {
		this->tgt_dir = this->params->target_angle;
	}

	// Set up target locations, etc.
	centerTarget->radius = params->target_size;
    // the targed object defines target->radius as the radius of the target on the screen
    // the target radius input from simulink is the radius of a circle around the center on which the targets are placed
	primaryTarget->radius = params->target_size;
	primaryTarget->centerX = params->target_radius*cos((float)this->tgt_dir * PI/180);
	primaryTarget->centerY = params->target_radius*sin((float)this->tgt_dir * PI/180);
	
	secondaryTarget->radius = params->target_size;
	secondaryTarget->centerX = params->target_radius*cos(PI + (float)this->tgt_dir * PI/180);
	secondaryTarget->centerY = params->target_radius*sin(PI + (float)this->tgt_dir * PI/180);

    // Reset cursor offset
    cursorOffset.x = 0;
    cursorOffset.y = 0;
    
	//set up the bump
    this->bump_delay=this->random->getDouble(params->bump_delay_low,params->bump_delay_high);
    this->bump_trial=this->random->getDouble()>params->bump_prob;
    if(this->bump_trial){
        this->bump->peak_magnitude=this->bump_stair->getCurrentValue() *params->bump_step + params->bump_floor;
        this->bump->hold_duration = params->bump_duration;
        this->bump->rise_time = params->bump_ramp;
        this->bump->direction = (double)(params->bump_direction) * PI/180;
    } else {
		this->bump->peak_magnitude=0;
	}

	/* Select whether this will be a training trial 
	*  If the training frequency is zero we should not see any training trials*/
	this->training_trial=(this->random->getDouble() < params->training_frequency);
    
    /* Select whether this will be a stimulation trial */
    this->stim_trial=(this->random->getDouble() < params->stim_prob);
    this->stim_code=this->random->getInteger(0,params->stim_levels-1);
	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
    db->addByte(DATABURST_TASK_CODE);
	db->addByte('F');
	db->addByte('C');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
    
	db->addFloat((float)this->tgt_dir);
	db->addByte((byte)this->params->use_random_targets);
	db->addFloat((float)this->params->target_radius);
	db->addFloat((float)this->params->target_size);
	db->addByte((byte)this->params->show_target_during_bump);
    
    db->addByte((byte)this->bump_trial);
	db->addFloat((float)this->bump_dir);
	db->addFloat((float)this->bump_mag);
	db->addFloat((float)this->params->bump_floor);
	db->addFloat((float)this->params->bump_ceiling);
	db->addFloat((float)this->params->bump_step);
	db->addFloat((float)this->params->bump_duration);
	db->addFloat((float)this->params->bump_ramp);
    
	db->addByte((byte)this->stim_trial);
	db->addByte((byte)this->stim_code);
    
	db->addByte((byte)this->training_trial);
    
	db->addByte((byte)this->params->recenter_cursor);
	db->addByte((byte)this->params->hide_cursor);
    
	db->addFloat((float)this->params->intertrial_time);
	db->addFloat((float)this->params->penalty_time);
	db->addFloat((float)this->params->bump_hold_time);
	db->addFloat((float)this->params->ct_hold_time);
	db->addFloat((float)this->bump_delay);
	db->start();
}

void ForcedChoiceBehavior::update(SimStruct *S) {
	Target *correctTarget;
	Target *incorrectTarget;
	
	if (training_trial) {
		if (this->bump_trial) {
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
		if (this->bump_trial) {
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
                //centerTarget->radius = params->big_target;
				setState(STATE_CT_BLOCK);
			}
			break;
		case STATE_CT_BLOCK:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > this->bump_delay) {
				if (this->stim_trial) {
					setState(STATE_STIM);
				} else {
    				bump->start(S);
					setState(STATE_BUMP);
				}
			}
			break;
		case STATE_BUMP:
            if(params->force_reaction){
                playTone(TONE_GO);
                setState(STATE_MOVEMENT);
            }else{
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
            }
			break;
		case STATE_STIM:
            if(params->force_reaction){
                playTone(TONE_GO);
                setState(STATE_MOVEMENT);
            }else{
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
            }
			break;
		case STATE_MOVEMENT:
            if (params->force_reaction && params->reaction_time>stateTimer->elapsedTime(S)){
                playTone(TONE_FAIL);
				if (this->params->penalty_time > 0) {
					setState(STATE_PENALTY);
				} else {
					setState(STATE_FAIL);
				}
            }
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
            //iterate staircase
            if(this->bump_trial){
                    if(this->stim_trial){
                        this->stim_stair->addSuccess();
                    }else {
                        this->bump_stair->addSuccess();
                    }
            }
		case STATE_FAIL:
            //iterate staircase
            if(this->bump_trial){
                    if(this->stim_trial){
                        this->stim_stair->addFailure();
                    }else {
                        this->bump_stair->addFailure();
                    }
            }
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

void ForcedChoiceBehavior::calculateOutputs(SimStruct *S) {
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
// outputs->status[0] = inputs->force.x;
// outputs->status[1] = inputs->force.y;
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
				outputs->word = WORD_STIM(this->stim_stair->getCurrentValue());
				break;
			case STATE_BUMP:
				outputs->word = WORD_BUMP(this->bump_stair->getCurrentValue());
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
				if(this->bump_trial) {
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
			if(this->bump_trial) {
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
	} else {
		outputs->targets[0] = nullTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
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


