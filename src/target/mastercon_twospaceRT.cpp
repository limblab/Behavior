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
#define STATE_CT_ON 1
#define STATE_CT_HOLD 2
#define STATE_MOVEMENT 3
#define STATE_TARG_HOLD 4
#define STATE_BUMP 5


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
 *  Version 1 (0x01)
 * ----------------
 *  Version 1 includes a center target on and center target hold state, along with possible bumps
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
 * byte  25 : uchar => did bump?
 * bytes 26 to 29: float => bump peak hold time
 * bytes 30 to 33: float => bump rise time
 * bytes 34 to 37: float => bump magnitude
 * bytes 38 to 41: float => bump direction
 * bytes 42 to 42+(N+1)*8: where N is the number of targets, contains 8 bytes per 
 *      target representing two single-precision floating point numbers in 
 *      little-endian format represnting the x and y position of the center of 
 *      the target. This also includes the first, center target
 *
 */
#define DATABURST_VERSION ((byte)0x01) 

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;

	// Time Bounds for various timers
    real_T ct_hold_lo;
    real_T ct_hold_hi;
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

    // bump stuff
    real_T bump_rate;
    real_T bump_hold_time;
   	real_T bump_ramp;
	real_T bump_magnitude;
    real_T bump_peak_hold;
   	real_T bump_dir_floor;
   	real_T bump_dir_ceil;
   	real_T bump_num_dir;
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
    double ct_hold_time;
	int t_color;
	
    CircleTarget *targets[128];
    CircleTarget *centerTarget;

    // bump things
    bool do_bump;
    double bump_time;
    CosineBumpGenerator *bump;

    // center hold timer
    Timer *ch_timer;

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
	this->setNumParams(30);

	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			0);
	
    // Timing info
	this->bindParamId(&params->ct_hold_lo,				1);
	this->bindParamId(&params->ct_hold_hi,				2);
	this->bindParamId(&params->targ_hold_lo,				3);
	this->bindParamId(&params->targ_hold_hi,				4);

	this->bindParamId(&params->intertrial_interval,		5);
    this->bindParamId(&params->initial_movement_time,   6);
	this->bindParamId(&params->movement_max_time,		7);
	this->bindParamId(&params->failure_penalty_lag,	    8);

    // target info
	this->bindParamId(&params->target_size,				9);
	this->bindParamId(&params->num_targets,				10);

	this->bindParamId(&params->targ_color_R,			11);
	this->bindParamId(&params->targ_color_G,			12);
	this->bindParamId(&params->targ_color_B,			13);

    // workspace things
	this->bindParamId(&params->ws1_xmin,			14);
	this->bindParamId(&params->ws1_xmax,			15);
	this->bindParamId(&params->ws1_ymin,			16);
	this->bindParamId(&params->ws1_ymax,			17);
	this->bindParamId(&params->ws2_xmin,			18);
	this->bindParamId(&params->ws2_xmax,			19);
	this->bindParamId(&params->ws2_ymin,			20);
	this->bindParamId(&params->ws2_ymax,			21);

    // bump info
    this->bindParamId(&params->bump_rate,           22);
    this->bindParamId(&params->bump_hold_time,      23);
   	this->bindParamId(&params->bump_ramp,           24);
	this->bindParamId(&params->bump_magnitude,		25);
	this->bindParamId(&params->bump_peak_hold,		26);
   	this->bindParamId(&params->bump_dir_floor,		27);
   	this->bindParamId(&params->bump_dir_ceil,		28);
   	this->bindParamId(&params->bump_num_dir,        29);

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
        targets[i] = new CircleTarget(0,0,0,0);
    }
    centerTarget = new CircleTarget(0,0,0,0);

	targ_hold_time	     = 0.0;
	t_color = 0;

    // bump stuff
	this->bump = new CosineBumpGenerator();
    this->do_bump = false;
    this->bump_time = 0;

    this->ch_timer = new Timer();
}

// Pre-trial initialization and calculations
void TwoSpaceRTBehavior::doPreTrial(SimStruct *S) {
	int i; 
    double bump_sep;

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
    centerTarget->centerX = (left_target_boundary + right_target_boundary)/2;
    centerTarget->centerY = (lower_target_boundary + upper_target_boundary)/2;
    centerTarget->radius = params->target_size;
    centerTarget->color = t_color;

	// Randomized Timers
	targ_hold_time		= random->getDouble(params->targ_hold_lo, params->targ_hold_hi);
	ct_hold_time		= random->getDouble(params->ct_hold_lo, params->ct_hold_hi);
    this->ch_timer->stop(S);

    // Bump stuff
    if(random->getDouble(0,1) < params->bump_rate) {
        this->do_bump = true;
        bump_sep=(this->params->bump_dir_ceil - this->params->bump_dir_floor)/(this->params->bump_num_dir -1);
        this->bump->direction=PI/180 * (this->params->bump_dir_floor + bump_sep*this->random->getInteger(0,(this->params->bump_num_dir -1)));
        this->bump->hold_duration = this->params->bump_peak_hold;
        this->bump->rise_time = this->params->bump_ramp;
        this->bump->peak_magnitude = this->params->bump_magnitude;
        this->bump_time = random->getDouble((double)this->params->ct_hold_lo,(double)this->ct_hold_time);
    } else {
        this->do_bump = false;
        this->bump->direction=0;
        this->bump->hold_duration = 0;
        this->bump->rise_time = 0;
        this->bump->peak_magnitude = 0;
        this->bump_time = 0;
    }

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
    db->addByte((byte)this->do_bump);
	db->addFloat((float)this->bump->hold_duration);
	db->addFloat((float)this->bump->rise_time);
	db->addFloat((float)this->bump->peak_magnitude);
    db->addFloat((float)this->bump->direction);
    db->addFloat((float)centerTarget->centerX);
    db->addFloat((float)centerTarget->centerY);
	for (i = 0; i<params->num_targets; i++) {
		db->addFloat((float)targets[i]->centerX);
		db->addFloat((float)targets[i]->centerY);
	}
    db->start();

}

void TwoSpaceRTBehavior::update(SimStruct *S) {
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
			/* target on */
			if (centerTarget->cursorInTarget(inputs->cursor)) {
                this->ch_timer->stop(S);
                this->ch_timer->start(S);
				setState(STATE_CT_HOLD);
			} else if (stateTimer->elapsedTime(S) > params->initial_movement_time) {
                setState(STATE_INCOMPLETE);
            }
			break;
        case STATE_CT_HOLD:
            // center target hold
			if (!centerTarget->cursorInTarget(inputs->cursor)){
                playTone(TONE_ABORT);
                setState(STATE_ABORT);
			} else if(this->do_bump && this->ch_timer->elapsedTime(S)>this->bump_time){
                this->ch_timer->pause(S);
                bump->start(S);
                setState(STATE_BUMP);
            } else if (this->ch_timer->elapsedTime(S) >= ct_hold_time) {
                // check if there are more targets
                if (target_index == params->num_targets-1) {
                    // no more targets - this shouldn't happen on the center target, but just in case
                    playTone(TONE_REWARD);
                    setState(STATE_REWARD);
                } else {
                    // more targets
                    targ_hold_time = random->getDouble(params->targ_hold_lo, params->targ_hold_hi);
                    playTone(TONE_GO);
                    setState(STATE_MOVEMENT);
                }
			}
			break;
		case STATE_BUMP:
			if(stateTimer->elapsedTime(S) > this->params->bump_hold_time) {
                if(centerTarget->cursorInTarget(inputs->cursor)){
                    // reset bump bool so that bump isn't triggered again on this trial
                    this->do_bump = false;
                    // resume CH timer
                    this->ch_timer->start(S);
                    // Go back to CT_HOLD
                    setState(STATE_CT_HOLD);
                }
            }
		case STATE_MOVEMENT:
			if (stateTimer->elapsedTime(S) > params->movement_max_time) {
				setState(STATE_FAIL);
			}
			else if (targets[target_index]->cursorInTarget(inputs->cursor)) {
				setState(STATE_TARG_HOLD);
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
		case STATE_REWARD:
		case STATE_ABORT:
        case STATE_INCOMPLETE:
			if (stateTimer->elapsedTime(S) > params->intertrial_interval) {
				setState(STATE_PRETRIAL);
			}
			break;
        case STATE_FAIL:
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
	if (getState() == STATE_BUMP) {
        if (bump->isRunning(S)) {
            outputs->force = bump->getBumpForce(S);
        } else {
            outputs->force.x = 0;
            outputs->force.y = 0;
        }
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
			case STATE_CT_ON:
				outputs->word = WORD_CT_ON;
				break;
			case STATE_CT_HOLD:
				outputs->word = WORD_CENTER_TARGET_HOLD;
				break;
            case STATE_BUMP:
                outputs->word = WORD_BUMP(0);
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

	/* target_pos (3) */
	// target 1
	if (getState() == STATE_MOVEMENT ||
		getState() == STATE_TARG_HOLD ||
		getState() == STATE_MOVEMENT){
			outputs->targets[0] = (Target *)currentTarget;
	} else if (getState() == STATE_CT_ON ||
               getState() == STATE_BUMP ||
               getState() == STATE_CT_HOLD) {
        outputs->targets[0] = centerTarget;
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
	outputs->position = inputs->cursor;
}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


