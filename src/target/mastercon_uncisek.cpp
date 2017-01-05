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


#define DATABURST_VERSION ((byte)0x01) 

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

	real_T cue_rate_one;
	real_T cue_rate_two;

	real_T center_out_mode;
	real_T match_mode;

	real_T center_cue_offset;

	real_T color_choice_mode;
	real_T cue_only_choice_mode;
	real_T true_only_choice_mode;

	real_T skip_center_cue;
	real_T skip_center_cue_rate;
	real_T co_percentage;
	real_T num_targlocs;

	real_T static_colors;
	real_T color_training;
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
	double co_perc; 

	double ct_hold_time, ct_outer_delay_time, ct_mem_delay_time, ct_cue_delay_time, ot_hold_time;
	double reach_len;
	double ang_diff;
	
	int target_default_color;
	int c_color_one;
	int c_color_two;
	int curr_cue_one_idx;
	int curr_cue_two_idx;
	int curr_target_idx;
	int curr_wrong_idx;
	int curr_cue_color;
	double rate_one, rate_two;
	bool   give_reward;
	double centerCueOffset;
	bool   colorChoiceMode;
	bool   cueOnlyChoiceMode;
	bool   trueOnlyChoiceMode;
	bool   skipCenterCue;
	bool   staticColors;
	bool   colorTraining;
	double skipCueRate;
	int num_targs;
	CircleTarget    *centerTarget;
	CircleTarget    *cueTarget;
	CircleTarget    *outerTarget[8];
	CircleTarget    *colorCursor;
	double			outer_angles[8];
	SquareTarget    *timerTarget;
	Point cursor_endpoint;

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
	this->setNumParams(41);

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

	this->bindParamId(&params->cue_rate_one,			27);
	this->bindParamId(&params->cue_rate_two,			28);

	this->bindParamId(&params->center_out_mode,			29);
	this->bindParamId(&params->match_mode,				30);

	this->bindParamId(&params->center_cue_offset,		31);
	this->bindParamId(&params->color_choice_mode,		32);
	this->bindParamId(&params->cue_only_choice_mode,	33);
	this->bindParamId(&params->true_only_choice_mode,	34);
	this->bindParamId(&params->skip_center_cue,			35);
	this->bindParamId(&params->skip_center_cue_rate,	36);

	this->bindParamId(&params->co_percentage,			37);
	this->bindParamId(&params->num_targlocs,			38);

	this->bindParamId(&params->static_colors,			39);
	this->bindParamId(&params->color_training,			40);


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
	cueTarget		 = new CircleTarget(0,0,0,0);
	for (i=0; i<8; i++) {
		outerTarget[i]=new CircleTarget(0,0,0,0);
		outer_angles[i]=0.0;
	}
	timerTarget      = new SquareTarget(0,0,0,0);
	colorCursor	     = new CircleTarget(0,0,0,0);
	
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
	curr_wrong_idx = 0;
	curr_cue_color = 0;
	cursor_endpoint.x = 0.0;
	cursor_endpoint.y = 0.0;
	rate_one = 0.0;
	rate_two = 0.0;
	give_reward	= true;
	co_mode	 = false;
	m_mode   = false;
	colorChoiceMode = false;
	cueOnlyChoiceMode = false;
	trueOnlyChoiceMode = false;
	skipCenterCue=false;
	skipCueRate=0;
	staticColors = false;
	colorTraining = false;
	centerCueOffset = 0;
	co_perc = 0;
	num_targs = 8;

}

// Pre-trial initialization and calculations
void UncertaintyCisekBehavior::doPreTrial(SimStruct *S) {
	int i; 
	//co_mode = params->center_out_mode;
	staticColors = params->static_colors;
	colorTraining = params->color_training;
	num_targs = params->num_targlocs;
	skipCenterCue      = params->skip_center_cue;
	skipCueRate = params->skip_center_cue_rate;
	if ((skipCenterCue)&&(random->getDouble()>skipCueRate)){
		skipCenterCue=false;
	}

	rate_one = params->cue_rate_one;
	rate_two = params->cue_rate_two;

	double total_rate;
	double adj_rate_one, adj_rate_two;
	total_rate = fabs(rate_one)+fabs(rate_two);
	if (total_rate == 0){
		total_rate = 1.0;
	}
	adj_rate_one = fabs(rate_one)/total_rate;
	adj_rate_two = fabs(rate_two)/total_rate;

	co_mode= (params->center_out_mode) && (random->getDouble()<params->co_percentage);
	double t_ang;
	//t_ang = 2*PI/8;
	if ((num_targs <= 2) && (co_mode)){
		t_ang = 2*PI/4;
	} else {
		t_ang = 2*PI/num_targs;
	}
	
	int Rs[8] = {  0,  0, 255, 132,   0, 255, 255, 255};
	int Gs[8] = {  0, 88,   0, 132, 255,  26, 255, 140};
	int Bs[8] = {255,  0,   0, 255,   0, 185, 255,   0};


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

	centerCueOffset = params->center_cue_offset;

	colorChoiceMode    = params->color_choice_mode;
	cueOnlyChoiceMode  = params->cue_only_choice_mode;
	trueOnlyChoiceMode = params->true_only_choice_mode;


	// Pick Targets for the Current Trial
	ang_diff=params->target_angle_diff*PI/180;
	curr_cue_one_idx=random->getInteger(0,7);
	int t_dif;
	int modtarg_curr, modtarg_wrong;
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

	if (random->getDouble()<=adj_rate_one){
		curr_target_idx=curr_cue_one_idx;
		curr_wrong_idx = curr_cue_two_idx;
		curr_cue_color=c_color_one;
	}
	else{
		curr_target_idx=curr_cue_two_idx;
		curr_wrong_idx = curr_cue_one_idx;
		curr_cue_color=c_color_two;
	}
	if (staticColors){
		modtarg_curr = curr_target_idx % num_targs;
		modtarg_wrong = curr_wrong_idx % num_targs;
		curr_cue_color = Target::Color(Rs[modtarg_curr],Gs[modtarg_curr],Bs[modtarg_curr]);
		c_color_one = Target::Color(Rs[modtarg_curr],Gs[modtarg_curr],Bs[modtarg_curr]);
		c_color_two = Target::Color(Rs[modtarg_wrong],Gs[modtarg_wrong],Bs[modtarg_wrong]);
	}

	cueTarget->centerX =  centerCueOffset*cos(outer_angles[curr_target_idx]);
	cueTarget->centerY =  centerCueOffset*sin(outer_angles[curr_target_idx]);
	cueTarget->radius  = params->center_size;
	cueTarget->color   = curr_cue_color;

	// Set Up The Targets
	for (i=0;i<8;i++){
		outer_angles[i]=t_ang*i;
		outerTarget[i]->centerX = reach_len*cos(outer_angles[i]);
		outerTarget[i]->centerY = reach_len*sin(outer_angles[i]);
		outerTarget[i]->radius  = params->outer_size;
		if (params->static_colors) {
			outerTarget[i]->color = Target::Color(Rs[i*8/num_targs],Gs[i*8/num_targs],Bs[i*8/num_targs]);
		} else {
			outerTarget[i]->color = target_default_color;
		}
	}

	if (!staticColors) {
		outerTarget[curr_cue_one_idx]->color = c_color_one;
		outerTarget[curr_cue_two_idx]->color = c_color_two;
	}


	//if (co_mode)
	//	m_mode=false;
	//else
	m_mode = params->match_mode;

	int num_on_screen;
	if (co_mode) {
		num_on_screen = 1;
	} else {
		num_on_screen = 2;
	}
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
	db->addFloat((float)rate_one);
	db->addFloat((float)rate_two);
	db->addFloat((float)num_on_screen);
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
				//outerTarget[curr_cue_one_idx]->color = c_color_one;
				//outerTarget[curr_cue_two_idx]->color = c_color_two;
				setState(STATE_CT_OUTER_DELAY);
			}
			break;
		case STATE_CT_OUTER_DELAY:
			if (!centerTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			else if (stateTimer->elapsedTime(S) >= ct_outer_delay_time) {
				if (!colorChoiceMode){
					outerTarget[curr_cue_one_idx]->color = target_default_color;
					outerTarget[curr_cue_two_idx]->color = target_default_color;
				}
				setState(STATE_CT_MEM_DELAY);
			}
			break;
		case STATE_CT_MEM_DELAY:
			if (!centerTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			else if (stateTimer->elapsedTime(S) >= ct_mem_delay_time) {
				if (skipCenterCue) {
					playTone(TONE_GO);
					setState(STATE_MOVEMENT);
				} else{
					setState(STATE_CT_CUE_DELAY);
				}
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
				for(i=0;i<params->num_targlocs;i++)	{	
					if  (outerTarget[i]->cursorInTarget(inputs->cursor)) { // Cursor is in target i

						if ((curr_target_idx % num_targs) == i) { // Target i is the correct target
							setState(STATE_OUTER_HOLD);
							break;
						} else {										     // Target i is not the correct target
							playTone(TONE_ABORT);
							setState(STATE_FAIL);
							break;
						}
					}
				}
			}
			break;
				//if (outerTarget[curr_target_idx]->cursorInTarget(inputs->cursor)){
				//	setState(STATE_OUTER_HOLD);
				//} else if ((outerTarget[curr_wrong_idx]->cursorInTarget(inputs->cursor)) && 
				//		  (!params->color_training)){
				//	outerTarget[curr_target_idx]->color = curr_cue_color;
				//	playTone(TONE_ABORT);
				//	cursor_endpoint = inputs->cursor;
				//	setState(STATE_FAIL);
				//}
		case STATE_OUTER_HOLD:
			if (stateTimer->elapsedTime(S) >= ot_hold_time) {
				outerTarget[curr_target_idx]->color = curr_cue_color;
				if (give_reward) {
					playTone(TONE_REWARD);
				}
				cursor_endpoint = inputs->cursor;
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

	colorCursor->centerX =  inputs->cursor.x;
	colorCursor->centerY =  inputs->cursor.y;
	colorCursor->radius  = 1;
	colorCursor->color   = cueTarget->color;
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
	if (getState() == STATE_CT_ON || 
		getState() == STATE_CT_MEM_DELAY || 
		getState() == STATE_CT_OUTER_DELAY ||
		getState() == STATE_CT_HOLD || 
		getState() == STATE_CT_CUE_DELAY) {
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
		if ((!co_mode) && (!colorTraining)){ // normal mode, no color training
			outputs->targets[curr_cue_one_idx+1] = outerTarget[curr_cue_one_idx];
			outputs->targets[curr_cue_two_idx+1] = outerTarget[curr_cue_two_idx];
		}
		else if (!co_mode && colorTraining) { // normal mode, color training
			for (i=0;i<num_targs;i++){
				outputs->targets[i+1] = outerTarget[i]; 
			}
		} else { // in CO mode
			outputs->targets[curr_target_idx+1] = outerTarget[curr_target_idx];
		}
	} else if (getState() == STATE_CT_MEM_DELAY){
		if (colorTraining && !co_mode) {
			for (i=0;i<num_targs;i++){
				outputs->targets[i+1] = outerTarget[i];
			}
		} else if (colorTraining && co_mode) {
			outputs->targets[curr_target_idx+1] = outerTarget[curr_target_idx];
		} else {
			for (i=0;i<8;i++){
				outputs->targets[i+1] = nullTarget;
			}
		}
	} else if (getState() == STATE_CT_CUE_DELAY){
		if (colorTraining) { 
			if (co_mode) {
				outputs->targets[curr_target_idx+1] = outerTarget[curr_target_idx];
			} else {
				for (i=0;i<num_targs;i++){
					outputs->targets[i+1] = outerTarget[i];
				}
			}
		} else {
			for (i=0;i<num_targs;i++){
					outputs->targets[i+1] = nullTarget;
			}
		}
	} else if (getState() == STATE_MOVEMENT || 
			   getState() == STATE_OUTER_HOLD){


		if (trueOnlyChoiceMode){
			for (i=0;i<8;i++){
			outputs->targets[i+1] = nullTarget;
			}
			outputs->targets[curr_target_idx+1]  = outerTarget[curr_target_idx];
		}
		else if (cueOnlyChoiceMode){
			for (i=0;i<8;i++){
				outputs->targets[i+1] = nullTarget;
			}
			if (!co_mode){
				outputs->targets[curr_cue_one_idx+1] = outerTarget[curr_cue_one_idx];
				outputs->targets[curr_cue_two_idx+1] = outerTarget[curr_cue_two_idx];
			}
			else{
				outputs->targets[curr_target_idx+1] = outerTarget[curr_target_idx];
			}
		}
		else if (colorTraining) {
			for (i=0;i<num_targs;i++){
				outputs->targets[i+1] = outerTarget[i]; 
			}
		} else {
			for (i=0;i<8;i++){
				outerTarget[i]->color = target_default_color;
				outputs->targets[i+1] = outerTarget[i];
			}
		}
	}
	else if (getState() == STATE_REWARD || getState() == STATE_FAIL) {
		for (i=0;i<8;i++){
			outputs->targets[i+1] = nullTarget;
		}
		outputs->targets[curr_target_idx+1] = outerTarget[curr_target_idx];
		/*outputs->targets[curr_cue_one_idx+1] = outerTarget[curr_cue_one_idx];
		outputs->targets[curr_cue_two_idx+1] = outerTarget[curr_cue_two_idx];*/
	}
	else {
		for (i=0;i<8;i++){
			outputs->targets[i+1] = nullTarget;
		}
	}

	// Target 9 is the cue target
	if (m_mode) {
		if (getState() == STATE_CT_CUE_DELAY ||
			getState() == STATE_MOVEMENT){
				//outputs->targets[9] = (Target *)cueTarget;
				outputs->targets[9] = (Target *)colorCursor;
				outputs->position = Point(1000,1000);
		} else if (getState() == STATE_REWARD || 
				   getState() == STATE_FAIL) {	
			colorCursor->centerX = cursor_endpoint.x;
			colorCursor->centerY = cursor_endpoint.y;
		    outputs->targets[9] = (Target *)colorCursor;
			outputs->position = Point(1000,1000);
		} else {
			outputs->targets[9] = nullTarget;
			outputs->position = inputs->cursor;
		}
	} else if (colorTraining) {
		if (getState() == STATE_CT_MEM_DELAY ||
			getState() == STATE_CT_CUE_DELAY ||
			getState() == STATE_MOVEMENT){
				outputs->targets[9] = (Target *)colorCursor;
				outputs->position = Point(1000,1000);
		} else if (getState() == STATE_REWARD ||
				   getState() == STATE_FAIL) {
		    colorCursor->centerX = cursor_endpoint.x;
			colorCursor->centerY = cursor_endpoint.y;
			outputs->targets[9] = (Target *)colorCursor;
			outputs->position = Point(1000,1000);
		} else {
			outputs->targets[9] = nullTarget;
			outputs->position = inputs->cursor;
		}
	} else {
		outputs->position = inputs->cursor;
		if (getState() == STATE_CT_CUE_DELAY) {
			outputs->targets[9] = (Target *)cueTarget;
		}
		else {
			outputs->targets[9] = nullTarget;
		}	
	}

	/* Timer Dot */
	if (stateTimer->elapsedTime(S) < 0.25) {
		outputs->targets[10] = (Target *)timerTarget;
	}
	else {
		outputs->targets[10] = nullTarget;
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

}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


