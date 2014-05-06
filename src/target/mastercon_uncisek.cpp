/* $Id: mastercon_uncisek.cpp 2014-04-21 pwanda $
 *
 * Master Control block for behavior: Cisek 2005-like task
 */

#define S_FUNCTION_NAME mastercon_uncisek
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
#define STATE_CT_OUTER_DELAY  3
#define STATE_CT_MEM_DELAY	  4
#define STATE_CT_CUE_DELAY    5
#define STATE_MOVEMENT		  6
#define STATE_OUTER_HOLD      7


/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */


#define DATABURST_VERSION ((byte)0x00) 

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;

	// Time Bounds for various timers
	real_T ct_hold_lo;
	real_T ct_hold_hi;
	real_T ct_outer_delay_lo;
	real_T ct_outer_delay_hi;
	real_T ct_mem_delay_lo;
	real_T ct_mem_delay_hi;
	real_T ct_cue_delay_lo;
	real_T ct_cue_delay_hi;
	real_T ot_hold_lo;
	real_T ot_hold_hi;

	real_T intertrial_interval;
	real_T movement_max_time;    // maximum allowed movement time
	real_T failure_penalty_lag;  // penalty lag for failed movements

	real_T movement_length;  
	real_T center_size;          // width of center target
	real_T outer_size;			 // size of outer target

	real_T target_angle_diff;   // distance between two cue targets

	real_T cue_color_one_R;
	real_T cue_color_one_G;
	real_T cue_color_one_B;

	real_T cue_color_two_R;
	real_T cue_color_two_G;
	real_T cue_color_two_B;

	real_T target_def_color_R;
	real_T target_def_color_G;
	real_T target_def_color_B;

	real_T cue_reward_one;
	real_T cue_reward_two;

	real_T center_out_mode;
	real_T match_mode;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME UncertaintyCisekBehavior
class UncertaintyCisekBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	UncertaintyCisekBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	Timer  *feedback_timer; // feedback timer

	bool   co_mode;
	bool   m_mode;

	double ct_hold_time, ct_outer_delay_time, ct_mem_delay_time, ct_cue_delay_time, ot_hold_time;
	double reach_len;
	double ang_diff;
	
	int target_default_color;
	int c_color_one;
	int c_color_two;
	int curr_cue_one_idx;
	int curr_cue_two_idx;
	int curr_target_idx;
	int curr_cue_color;
	double reward_one, reward_two;
	bool   give_reward;


	CircleTarget    *centerTarget;
	CircleTarget    *outerTarget[8];
	double			outer_angles[8];
	SquareTarget    *timerTarget;

	LocalParams *params;

	// helper functions
	void doPreTrial(SimStruct *S);
};

UncertaintyCisekBehavior::UncertaintyCisekBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(31);

	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			0);
	
	this->bindParamId(&params->ct_hold_lo,				1);
	this->bindParamId(&params->ct_hold_hi,				2);
	this->bindParamId(&params->ct_outer_delay_lo,		3);
	this->bindParamId(&params->ct_outer_delay_hi,		4);
	this->bindParamId(&params->ct_mem_delay_lo,			5);
	this->bindParamId(&params->ct_mem_delay_hi,			6);
	this->bindParamId(&params->ct_cue_delay_lo,			7);
	this->bindParamId(&params->ct_cue_delay_hi,			8);
	this->bindParamId(&params->ot_hold_lo,				9);
	this->bindParamId(&params->ot_hold_hi,				10);

	this->bindParamId(&params->intertrial_interval,		11);
	this->bindParamId(&params->movement_max_time,		12);
	this->bindParamId(&params->failure_penalty_lag,	    13);

	this->bindParamId(&params->movement_length,			14);
	this->bindParamId(&params->center_size,				15);
	this->bindParamId(&params->outer_size,				16);
	
	this->bindParamId(&params->target_angle_diff,		17);

	this->bindParamId(&params->cue_color_one_R,			18);
	this->bindParamId(&params->cue_color_one_G,			19);
	this->bindParamId(&params->cue_color_one_B,			20);

	this->bindParamId(&params->cue_color_two_R,			21);
	this->bindParamId(&params->cue_color_two_G,			22);
	this->bindParamId(&params->cue_color_two_B,			23);

	this->bindParamId(&params->target_def_color_R,		24);
	this->bindParamId(&params->target_def_color_G,		25);
	this->bindParamId(&params->target_def_color_B,		26);

	this->bindParamId(&params->cue_reward_one,			27);
	this->bindParamId(&params->cue_reward_two,			28);

	this->bindParamId(&params->center_out_mode,			29);
	this->bindParamId(&params->match_mode,				30);

	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	this->updateParameters(S);

    /* 
	 * Then do any behavior specific initialization 
	 */
	centerTarget	 = new CircleTarget(0,0,0,0);
	for (i=0; i<8; i++) {
		outerTarget[i]=new CircleTarget(0,0,0,0);
		outer_angles[i]=0.0;
	}
	timerTarget      = new SquareTarget(0,0,0,0);
	
	feedback_timer	 = new Timer();
	reach_len=0.0;

	ct_hold_time	     = 0.0;
	ct_outer_delay_time  = 0.0;
	ct_mem_delay_time	 = 0.0;
	ct_cue_delay_time    = 0.0;
	ot_hold_time	     = 0.0;
	
	ang_diff = 0.0;

	target_default_color  = 0;
	c_color_one = 0;
	c_color_two = 0;
	curr_cue_one_idx=0;
	curr_cue_two_idx=0;
	curr_target_idx=0;
	curr_cue_color = 0;
	reward_one = 0.0;
	reward_two = 0.0;
	give_reward	= true;
	co_mode	 = false;
	m_mode   = false;
}

// Pre-trial initialization and calculations
void UncertaintyCisekBehavior::doPreTrial(SimStruct *S) {
	int i;


	double t_ang;
	t_ang = 2*PI/8;
	reach_len = params->movement_length;
	//Set Colors
	target_default_color = Target::Color(params->target_def_color_R, params->target_def_color_G, params->target_def_color_B);
	c_color_one = Target::Color(params->cue_color_one_R, params->cue_color_one_G, params->cue_color_one_B);
	c_color_two = Target::Color(params->cue_color_two_R, params->cue_color_two_G, params->cue_color_two_B);
	
	// Set Center Target
	centerTarget->centerX = 0.0 ;
	centerTarget->centerY = 0.0 ;
	centerTarget->radius  = params->center_size;
	centerTarget->color   = target_default_color;

	// Set Up The Targets
	for (i=0;i<8;i++){
		outer_angles[i]=t_ang*i;
		outerTarget[i]->centerX = reach_len*cos(outer_angles[i]);
		outerTarget[i]->centerY = reach_len*sin(outer_angles[i]);
		outerTarget[i]->radius  = params->outer_size;
		outerTarget[i]->color   = target_default_color;
	}

	// Pick Targets for the Current Trial
	ang_diff=params->target_angle_diff*PI/180;
	curr_cue_one_idx=random->getInteger(0,7);
	int t_dif;
	t_dif = (int) (ang_diff/t_ang);
	int c_2a, c_2b;
	c_2a = curr_cue_one_idx + t_dif;
	c_2b = curr_cue_one_idx - t_dif;
	if (c_2a > 7)
		c_2a = c_2a - 8;
	if (c_2b < 0)
		c_2b = c_2b + 8;
	if (random->getBool())
		curr_cue_two_idx=c_2a;
	else
		curr_cue_two_idx=c_2b;

	if (random->getBool()){
		curr_target_idx=curr_cue_one_idx;
		curr_cue_color=c_color_one;
	}
	else{
		curr_target_idx=curr_cue_two_idx;
		curr_cue_color=c_color_two;
	}

	co_mode=params->center_out_mode;
	if (co_mode)
		m_mode=false;
	else
		m_mode =params->match_mode;

	// Timer Target used for Photodetector Correction
	timerTarget->centerX = 14.25;
	timerTarget->centerY = 10.55 ;
	timerTarget->width   = 0.8;
	timerTarget->color   = Target::Color(255, 255, 255);

	// Randomized Timers
	ct_hold_time		= random->getDouble(params->ct_hold_lo, params->ct_hold_hi);
	ct_outer_delay_time = random->getDouble(params->ct_outer_delay_lo, params->ct_outer_delay_hi);
	ct_mem_delay_time	= random->getDouble(params->ct_mem_delay_lo, params->ct_mem_delay_hi);
	ct_cue_delay_time	= random->getDouble(params->ct_cue_delay_lo, params->ct_cue_delay_hi);
	ot_hold_time		= random->getDouble(params->ot_hold_lo, params->ot_hold_hi);

	feedback_timer->stop();

	// setup the databurst
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('U');
	db->addByte('C');
	db->addByte('K');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)outer_angles[curr_cue_one_idx]); // angle of cue 1
	db->addFloat((float)outer_angles[curr_cue_two_idx]); // angle of cue 2
	db->addFloat((float)c_color_one);				     // color of cue 1
	db->addFloat((float)c_color_two);					 // color of cue 2
	db->addFloat((float)outer_angles[curr_target_idx]);  // angle of true target (Cisek)
    db->start();
}

void UncertaintyCisekBehavior::update(SimStruct *S) {
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
			if (centerTarget->cursorInTarget(inputs->cursor)) {
				setState(STATE_CT_HOLD);
			} 
			break;
		case STATE_CT_HOLD:
			if (!centerTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			else if (stateTimer->elapsedTime(S) >= ct_hold_time) {
				outerTarget[curr_cue_one_idx]->color = c_color_one;
				outerTarget[curr_cue_two_idx]->color = c_color_two;
				setState(STATE_CT_OUTER_DELAY);
			}
			break;
		case STATE_CT_OUTER_DELAY:
			if (!centerTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			else if (stateTimer->elapsedTime(S) >= ct_outer_delay_time) {
				outerTarget[curr_cue_one_idx]->color = target_default_color;
				outerTarget[curr_cue_two_idx]->color = target_default_color;
				setState(STATE_CT_MEM_DELAY);
			}
			break;
		case STATE_CT_MEM_DELAY:
			if (!centerTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			else if (stateTimer->elapsedTime(S) >= ct_mem_delay_time) {
				centerTarget->color = curr_cue_color;
				setState(STATE_CT_CUE_DELAY);
			}
			break;
		case STATE_CT_CUE_DELAY:
			if (!centerTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			else if (stateTimer->elapsedTime(S) >= ct_cue_delay_time) {
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_MOVEMENT:
			if (stateTimer->elapsedTime(S) > params->movement_max_time) {
				setState(STATE_INCOMPLETE);
			}
			else { 
				for(i=0;i<8;i++)	{			
					if (outerTarget[i]->cursorInTarget(inputs->cursor)) {
						if (i==curr_target_idx){
							setState(STATE_OUTER_HOLD);
						}
						else {
							outerTarget[curr_target_idx]->color = curr_cue_color;
							playTone(TONE_ABORT);
							setState(STATE_FAIL);

						}
					}
				}
			}
			break;
		case STATE_OUTER_HOLD:
			if (stateTimer->elapsedTime(S) >= ot_hold_time) {
				outerTarget[curr_target_idx]->color = curr_cue_color;
				if (give_reward) {
					playTone(TONE_REWARD);
				}
				setState(STATE_REWARD);
			}
			else if (!outerTarget[curr_target_idx]->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			break;
		case STATE_FAIL:
			if (stateTimer->elapsedTime(S) > (params->failure_penalty_lag + params->intertrial_interval)) {
				setState(STATE_PRETRIAL);
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

void UncertaintyCisekBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
	int i;

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
			case STATE_CT_ON:
				outputs->word = WORD_CT_ON;
				break;
			case STATE_CT_HOLD:
				outputs->word = WORD_CENTER_TARGET_HOLD;
				break;
			case STATE_CT_OUTER_DELAY:
				outputs->word = WORD_OT_ON(0 /* change to whatever your target is */);
				break;
			case STATE_CT_MEM_DELAY:
				outputs->word = WORD_CT_MEM_DELAY;
				break;
			case STATE_CT_CUE_DELAY:
				outputs->word = WORD_CT_TARGCUE_ON;
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
	// Target 0 is the center target
	if (getState() == STATE_CT_ON || getState() == STATE_CT_MEM_DELAY || getState() == STATE_CT_OUTER_DELAY ||
		getState() == STATE_CT_HOLD || getState() == STATE_CT_CUE_DELAY) {
		outputs->targets[0] = (Target *)centerTarget;
	}
	else {
		outputs->targets[0] = nullTarget;
	}

	// Target(s) 1-8 are the outer target(s)
	if (getState() == STATE_CT_OUTER_DELAY){
		for (i=0;i<8;i++){
			outputs->targets[i+1] = nullTarget;
		}
		outputs->targets[curr_cue_one_idx+1] = outerTarget[curr_cue_one_idx];
		outputs->targets[curr_cue_two_idx+1] = outerTarget[curr_cue_two_idx];
	}
	else if (getState() == STATE_REWARD || getState() == STATE_FAIL) {
		for (i=0;i<8;i++){
			outputs->targets[i+1] = nullTarget;
		}
		outputs->targets[curr_target_idx+1] = outerTarget[curr_target_idx];
	}
	else if (getState() == STATE_MOVEMENT || (getState() == STATE_OUTER_HOLD)){
//		for (i=0;i<8;i++){
//			outputs->targets[i+1] = outerTarget[i];
//		}
		outputs->targets[curr_cue_one_idx+1] = outerTarget[curr_cue_one_idx];
		outputs->targets[curr_cue_two_idx+1] = outerTarget[curr_cue_two_idx];
	}
	else {
		for (i=0;i<8;i++){
			outputs->targets[i+1] = nullTarget;
		}
	}

	/* Timer Dot */
	if (stateTimer->elapsedTime(S) < 0.25) {
		outputs->targets[9] = (Target *)timerTarget;
	}
	else {
		outputs->targets[9] = nullTarget;
	}

	/* reward (4) */
	outputs->reward = (isNewState() && (getState() == STATE_REWARD) && give_reward);

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


