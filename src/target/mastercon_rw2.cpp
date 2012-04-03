/* $Id: mastercon_rw.c 753 2012-01-16 22:03:55Z bwalker $
 *
 * Master Control block for behavior: random walk task 
 */


#define S_FUNCTION_NAME mastercon_rw2
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include <stdlib.h>
#include "simstruc.h"

#include "Behavior.cpp"

#define TASK_RW 1
#include "words.h"

/* 
 * identifiers for param values 
 */
#define NUM_PARAMETERS 21 /* this line MUST be updated for you param to take effect */

#define param_num_targets_id            0
#define param_target_size_id            1
#define param_target_tolerance_id       2
#define param_left_target_boundary_id   3 /* left boundary for target drawing in cm */
#define param_right_target_boundary_id  4 /* right boundary for target drawing in cm */
#define param_upper_target_boundary_id  5 /* upper boundary for target drawing in cm */
#define param_lower_target_boundary_id  6 /* lower boundary for target drawing in cm*/
#define param_target_hold_l_id          7 /* dwell time in target before new target shown (low value) */
#define param_target_hold_h_id          8 /* dwell time in target before new target shown (high value) */
#define param_target_delay_l_id         9 /* delay time between next target  */
#define param_target_delay_h_id        10 /* appearance and movement state   */
#define param_movement_time_id         11
#define param_initial_movement_time_id 12
#define param_intertrial_id            13
#define param_minimum_distance_id      14
#define param_maximum_distance_id      15
#define param_percent_catch_trials_id  16
#define param_master_reset_id          17
#define param_disable_abort_id         18
#define param_green_hold_id            19
#define param_cumulative_hold_id       20

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_INITIAL_MOVEMENT 1
#define STATE_TARGET_HOLD 2
#define STATE_TARGET_DELAY 3
#define STATE_MOVEMENT 4
/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME RandomWalkBehavior
class RandomWalkBehavior : Behavior {
public:
	RandomWalkBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	int target_index;
	SquareTarget *targets[128];
	Timer *cumulativeHoldTimer;
	double targetHoldTime;
	double delayTime;
	bool catchTrial;

	void doPreTrial(SimStruct *S) {
		int i;

		/* initialize target positions */
		if (paramValues[param_maximum_distance_id] == 0) {
			/* uniform random positions */
			for (i = 0; i<paramValues[param_num_targets_id]; i++) {
				targets[i]->centerX = random->getDouble(paramValues[param_left_target_boundary_id],  paramValues[param_right_target_boundary_id]);
				targets[i]->centerY = random->getDouble(paramValues[param_lower_target_boundary_id], paramValues[param_upper_target_boundary_id]);
				targets[i]->width = paramValues[param_target_size_id];
				targets[i]->color = Target::Color(255, 0, 0);
			}
		} else {
			/* TODO: set not-quite-random target distances */
		}

		target_index = 0;
		catchTrial = false;
	}
};

RandomWalkBehavior::RandomWalkBehavior(SimStruct *S) {
	int i;

	/* 
	 * First, set up the number of parameters to be used 
	 */
	this->setNumParams(NUM_PARAMETERS);
	this->updateParameters(S);

	/* 
	 * Then do any behavior specific initialization 
	 */
	this->cumulativeHoldTimer = new Timer();

	/* set target index to indicate that we need to begin a new block */
	target_index = (int)paramValues[param_num_targets_id]-1;

	for (i = 0; i<128; i++) {
		targets[i] = new SquareTarget(0, 0, 0, 0);
	}
}

void RandomWalkBehavior::update(SimStruct *S) {
	/* declarations */
	SquareTarget currentTarget;
	SquareTarget targetBounds;
	
	/* Run parent update -- this must be the FIRST thing you do */
	this->Behavior::update(S);

	/* 
	 *custom update function 
	 */
	currentTarget = *targets[target_index];
	targetBounds = currentTarget;
	targetBounds.width = currentTarget.width + paramValues[param_target_tolerance_id];
	
	// Check for a master reset
	// TODO: Check for a master reset

	// State machine
	switch (this->getState()) {
		case STATE_PRETRIAL:
			updateParameters(S);
			doPreTrial(S);
			setState(STATE_INITIAL_MOVEMENT);
			break;
		case STATE_INITIAL_MOVEMENT:
			/* first target on */
			if (targetBounds.cursorInTarget(cursor)) {
				setState(STATE_TARGET_HOLD);
			} else if (stateTimer->elapsedTime(S) > paramValues[param_initial_movement_time_id]) {
				setState(STATE_INCOMPLETE);
			}
			break;
		case STATE_MOVEMENT:
			if (targetBounds.cursorInTarget(cursor)) {
				setState(STATE_TARGET_HOLD);
			} else if (stateTimer->elapsedTime(S) > paramValues[param_movement_time_id]) {
				setState(STATE_FAIL);
			}
			break;
		case STATE_TARGET_HOLD:
			if (!targetBounds.cursorInTarget(cursor) && paramValues[param_disable_abort_id]) {
				setState(STATE_MOVEMENT);
			} else if (!targetBounds.cursorInTarget(cursor)) {
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > targetHoldTime) {
				/* next state depends on whether there are more targets */
				if (target_index == paramValues[param_num_targets_id]-1) {
					/* no more targets */
					playTone(TONE_REWARD);
					setState(STATE_REWARD);
				} else {
					/* more targets */
					delayTime = random->getDouble(paramValues[param_target_delay_l_id], paramValues[param_target_delay_h_id]);
					setState(STATE_TARGET_DELAY);
				}
			}
			break;
		case STATE_TARGET_DELAY:
			if (!targetBounds.cursorInTarget(cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > delayTime) {
				target_index++;
				catchTrial = ( random->getDouble() < paramValues[param_percent_catch_trials_id] );
				targetHoldTime = random->getDouble(paramValues[param_target_hold_l_id], paramValues[param_target_hold_h_id]);
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_ABORT:
        case STATE_REWARD:
		case STATE_FAIL:
        case STATE_INCOMPLETE:
			if (stateTimer->elapsedTime(S) > paramValues[param_intertrial_id]) {
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

	/*
	 * This must be the first thing you do
	 */
	readInputs(S);

	/* force (0) */
	if (catchTrial) {
		outputs->force = *catchForce;
	} else {
		outputs->force = *force;
	}

	/* status (1) */
	updateTrialCounters();
	outputs->status[0] = getState();
	outputs->status[1] = trialCounter->successes;
	outputs->status[2] = trialCounter->aborts;
	outputs->status[3] = trialCounter->failures;
	outputs->status[4] = trialCounter->incompletes;

	/* word(2) */
	if (isNewState()) {
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
	if (getState() == STATE_TARGET_HOLD && paramValues[param_green_hold_id]) {
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
	outputs->position = *cursor;

	/* 
	 * This must be the last thing you do.
	 */
	writeOutputs(S);
}

/*********************************************************************************
 * Begining of S-Function API interface                                          *
 *********************************************************************************
 * DO NOT EDIT ANYTHING BELOW THIS LINE * * DO NOT EDIT ANYTHING BELOW THIS LINE *
 * DO NOT EDIT ANYTHING BELOW THIS LINE * * DO NOT EDIT ANYTHING BELOW THIS LINE *
 * DO NOT EDIT ANYTHING BELOW THIS LINE * * DO NOT EDIT ANYTHING BELOW THIS LINE *
 * DO NOT EDIT ANYTHING BELOW THIS LINE * * DO NOT EDIT ANYTHING BELOW THIS LINE *
 *********************************************************************************/

#ifdef __cplusplus
extern "C" { // use the C fcn-call standard for all functions  
#endif       // defined within this scope                     

/* 
 * Current Databurst version: 1
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
 * byte 0: uchar => number of bytes to be transmitted
 * byte 1: uchar => version number (in this case zero)
 * bytes 2 - 2+N*8: where N is the number of targets, contains 8 bytes per 
 *      target representing two single-precision floating point numbers in 
 *      little-endian format represnting the x and y position of the center of 
 *      the target.
 *
 * Version 1 (0x01)
 * ----------------
 * byte   0: uchar => number of bytes to be transmitted
 * byte   1: uchar => databurst version number (in this case one)
 * byte   2: uchar => model version major
 * byte   3: uchar => model version minor
 * bytes  4 to  5: short => model version micro
 * bytes  6 to  9: float => x offset
 * bytes 10 to 13: float => y offset
 * bytes 14 to 17: float => target_size - target_tolerance
 * bytes 18 to 18+N*8: where N is the number of targets, contains 8 bytes per 
 *      target representing two single-precision floating point numbers in 
 *      little-endian format represnting the x and y position of the center of 
 *      the target.
 *
 *  Version 2 (0x02) - Similar to version 1, fixed "target_size + target_tolerance" and
 *                      it should now send all the bytes, previous version only sent
 *                      half of them.
 * ----------------
 * byte   0: uchar => number of bytes to be transmitted
 * byte   1: uchar => databurst version number (in this case two)
 * byte   2: uchar => model version major
 * byte   3: uchar => model version minor
 * bytes  4 to  5: short => model version micro
 * bytes  6 to  9: float => x offset
 * bytes 10 to 13: float => y offset
 * bytes 14 to 17: float => target_size + target_tolerance
 * bytes 18 to 18+N*8: where N is the number of targets, contains 8 bytes per 
 *      target representing two single-precision floating point numbers in 
 *      little-endian format represnting the x and y position of the center of 
 *      the target.
 */

typedef unsigned char byte;
#define DATABURST_VERSION ((byte)0x02) 

static void mdlInitializeSizes(SimStruct *S)
{
    int i;
    
    ssSetNumSFcnParams(S, NUM_PARAMETERS); 
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* parameter number mismatch */
    }
    for (i=0; i<ssGetNumSFcnParams(S); i++)
        ssSetSFcnParamTunable(S,i, 1);
    // mdlCheckParameters(S);
    
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);
    
    /*
     * Block has 4 input ports
     *      input port 0: (position) of width 2 (x, y)
     *      input port 1: (position offset) of width 2 (x, y)
     *      input port 2: (force) of width 2 (x, y)
     *      input port 3: (catch force) of width 2 (x, y)
     */
    if (!ssSetNumInputPorts(S, 4)) return;
    ssSetInputPortWidth(S, 0, 2); /* x & y position */
    ssSetInputPortWidth(S, 1, 2); /* x & y position offsets */
    ssSetInputPortWidth(S, 2, 2); /* main force */
    ssSetInputPortWidth(S, 3, 2); /* catch trial force */
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortDirectFeedThrough(S, 3, 1);
    
    /* 
     * Block has 8 output ports (force, status, word, targets, reward, tone, version, pos) of widths:
     *  force: 2
     *  status: 5 ( block counter, successes, aborts, failures, incompletes )
     *  word:  1 (8 bits)
     *  target: 10 ( target 1, 2: 
     *                  on/off, 
     *                  target UL corner x, 
     *                  target UL corner y,
     *                  target LR corner x, 
     *                  target LR corner y)
     *  reward: 1
     *  tone: 2     ( 1: counter incemented for each new tone, 2: tone ID )
     *  version: 1 ( the cvs revision of the current .c file )
     *  pos: 2 (x and y position of the cursor)
     */
    if (!ssSetNumOutputPorts(S, 8)) return;
    ssSetOutputPortWidth(S, 0, 2);   /* force   */
    ssSetOutputPortWidth(S, 1, 5);   /* status  */
    ssSetOutputPortWidth(S, 2, 1);   /* word    */
    ssSetOutputPortWidth(S, 3, 10);  /* target  */
    ssSetOutputPortWidth(S, 4, 1);   /* reward  */
    ssSetOutputPortWidth(S, 5, 2);   /* tone    */
    ssSetOutputPortWidth(S, 6, 4);   /* version */
    ssSetOutputPortWidth(S, 7, 2);   /* pos     */
    
    ssSetNumSampleTimes(S, 1);

    /* work buffers */
	ssSetNumRWork(S, 0);
	ssSetNumIWork(S, 0);
	ssSetNumPWork(S, 1);

    /* we have no zero crossing detection or modes */
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}

#define MDL_START
static void mdlStart(SimStruct *S)
{
	ssGetPWork(S)[0] = (void *) new MY_CLASS_NAME(S);
}

#define MDL_UPDATE
static void mdlUpdate(SimStruct *S, int_T tid) 
{
	MY_CLASS_NAME *b = (MY_CLASS_NAME *) ssGetPWork(S)[0];
	b->update(S);
	
    UNUSED_ARG(tid);
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
	MY_CLASS_NAME *b = (MY_CLASS_NAME *) ssGetPWork(S)[0];
	b->calculateOutputs(S);
	
	UNUSED_ARG(tid);
}

static void mdlTerminate (SimStruct *S) { 
	MY_CLASS_NAME *b = (MY_CLASS_NAME *) ssGetPWork(S)[0];
	delete b;
}

#ifdef MATLAB_MEX_FILE   /* Is this being compiled as a MEX-file? */
#include "simulink.c"    /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"     /* Code generation registration func */
#endif

#ifdef __cplusplus
} // end of extern "C" scope
#endif
