/* $Id: mastercon_outout.cpp 2016-12-05 Raeed $
 *
 * Master Control block for behavior: RandomTarget3D
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
#define STATE_FIRST_TARG_ON 1
#define STATE_FIRST_TARG_HOLD 2
#define STATE_MOVEMENT 3
#define STATE_TARG_HOLD 4

/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */

/* 
 * Current Databurst version: 2
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
 * ...I have no idea
 *
 * Version 1 (0x01)
 * ----------------
 * ...I have no idea
 *
 * Version 2 (0x02)
 * ----------------
 * byte   0: uchar => number of bytes to be transmitted
 * byte   1: uchar => databurst version number (in this case: 0)
 * byte   2 to 4: uchar => task code ('3DR')
 * byte   5: uchar => model version major
 * byte   6: uchar => model version minor
 * bytes  7 to  8: short => model version micro
 * bytes  9 to 12: float => number of targets (includes first target)
 * bytes 13 to 16: float => start target hold time
 * bytes 17 to 20: float => other target hold time 
 * bytes 21 to 21+(N)*8: where N is the number of targets, contains 8 bytes per 
 *      target representing two single-precision floating point numbers in 
 *      little-endian format represnting the row and column of the 
 *      target. This also includes the first target. Encoding scheme is:
 *      (looking at it like the monkey)
 *      o       o       o
 *     1,1     1,2     1,3
 *      o               o
 *     2,1             2,3
 *      o       o       o
 *     3,1     3,2     3,3
 */
typedef unsigned char byte;
#define DATABURST_VERSION ((byte)0x02) 

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;

    // location of first target
    real_T ft_location_row;
    real_T ft_location_col;

	// Time Bounds for various timers
    real_T ft_hold_lo;
    real_T ft_hold_hi;
	real_T targ_hold_lo;
	real_T targ_hold_hi;

    real_T initial_movement_time; // maximum allowed time to start trial
	real_T movement_max_time;    // maximum allowed movement time

	real_T num_targets;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME RandomTarget3D
class RandomTarget3D : public Behavior3DReach {
public:
	// You must implement these three public methods
	RandomTarget3D(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
    int target_index;
	double targ_hold_time;
    double ft_hold_time;
    
    LEDTarget *targets[128];
   
	LocalParams *params;

	// helper functions
	void doPreTrial(SimStruct *S);
};

RandomTarget3D::RandomTarget3D(SimStruct *S) : Behavior3DReach() {
    int i;

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
	this->bindParamId(&params->ft_hold_lo,				1);
	this->bindParamId(&params->ft_hold_hi,				2);
	this->bindParamId(&params->targ_hold_lo,			3);
	this->bindParamId(&params->targ_hold_hi,			4);

    this->bindParamId(&params->initial_movement_time,   5);
	this->bindParamId(&params->movement_max_time,		6);

    // target info
	this->bindParamId(&params->num_targets,				7);
    this->bindParamId(&params->ft_location_row,         8);
	this->bindParamId(&params->ft_location_col,			9);

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
        targets[i] = new LEDTarget();
    }
    
	targ_hold_time	     = 0.0;

}

// Pre-trial initialization and calculations
void RandomTarget3D::doPreTrial(SimStruct *S) {
	int i; 
	/* initialize targets */

    /* set first target */
    targets[0]->target_row = params->ft_location_row;
    targets[0]->target_col = params->ft_location_col;
    
    /* set rest of targets */
    for (i = 1; i<params->num_targets; i++) {
        targets[i]->target_row = random->getInteger(1,3);
        targets[i]->target_col = random->getInteger(1,3);
        while (targets[i]->target_row == 2 && targets[i]->target_col == 2){
            targets[i]->target_row = random->getInteger(1,3);
            targets[i]->target_col = random->getInteger(1,3);
        }
    }

    // Randomized Timers
	targ_hold_time		= random->getDouble(params->targ_hold_lo, params->targ_hold_hi);
	ft_hold_time		= random->getDouble(params->ft_hold_lo, params->ft_hold_hi);


    // Reset target index
    target_index = 0;

	// setup the databurst
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('3');
	db->addByte('D');
	db->addByte('R');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)(params->num_targets));
    db->addFloat((float)(ft_hold_time));
    db->addFloat((float)(targ_hold_time));
	for (i = 0; i<params->num_targets; i++) {
		db->addFloat((float)targets[i]->target_row);
		db->addFloat((float)targets[i]->target_col);
	}
    db->start();
    
}

void RandomTarget3D::update(SimStruct *S) {
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
		case STATE_FIRST_TARG_ON:
			/* target on */
			if (targets[target_index]->handInTarget(inputs->targetStaircase)) {
                target_index++;
				setState(STATE_FIRST_TARG_HOLD);
			} else if (stateTimer->elapsedTime(S) > params->initial_movement_time) {
                setState(STATE_INCOMPLETE);
            }
			break;
        case STATE_FIRST_TARG_HOLD:
            // first target hold
			if (!targets[target_index]->handInTarget(inputs->targetStaircase)){
                playTone(TONE_ABORT);
                setState(STATE_ABORT);
            } else if (stateTimer->elapsedTime(S) >= ft_hold_time) {
                // check if there are more targets
                if (target_index == params->num_targets-1) {
                    // no more targets - this shouldn't happen on the center target, but just in case
                    playTone(TONE_REWARD);
                    setState(STATE_REWARD);
                } else {
                    // more targets
                    target_index++;
                    playTone(TONE_GO);
                    setState(STATE_MOVEMENT);
                }
			}
			break;
		case STATE_MOVEMENT:
			if (stateTimer->elapsedTime(S) > params->movement_max_time) {
                playTone(TONE_FAIL);
				setState(STATE_FAIL);
			}
            else if (targets[target_index]->handInTarget(inputs->targetStaircase)) {
				setState(STATE_TARG_HOLD);
			}
			break;
		case STATE_TARG_HOLD:
			if (!targets[target_index]->handInTarget(inputs->targetStaircase)){
                playTone(TONE_ABORT);
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
                    playTone(TONE_GO);
                    setState(STATE_MOVEMENT);
                }
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

void RandomTarget3D::calculateOutputs(SimStruct *S) {
    /* declarations */
	int i;
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
			case STATE_FIRST_TARG_ON:
				outputs->word = WORD_CT_ON;
				break;
			case STATE_FIRST_TARG_HOLD:
				outputs->word = WORD_CENTER_TARGET_HOLD;
				break;
			case STATE_MOVEMENT:
                outputs->word = WORD_GO_CUE;
				break;
			case STATE_TARG_HOLD:
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
            case STATE_FAIL:
                outputs->word = WORD_FAIL;
			default:
				outputs->word = 0;
		}
	} else {
		outputs->word = 0;
	}

    /*----------------START HERE------------------*/

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
    outputs->target = currentTarget;
    
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
