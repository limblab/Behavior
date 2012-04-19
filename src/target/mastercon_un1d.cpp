/* $Id: mastercon_un1d.cpp 858 2012-04-11 21:46:24Z paulw $
 *
 * Master Control block for behavior: uncertainty 1d task 
 */

#define S_FUNCTION_NAME mastercon_un1d
#define S_FUNCTION_LEVEL 2

#define TASK_UN1D 1
#include "words.h"

#include "common_header.cpp"
#define PI (3.141592654)

/*
 * State IDs
 */
#define STATE_PRETRIAL     0
#define STATE_CT_ON        1
#define STATE_CENTER_HOLD  2
#define STATE_CENTER_DELAY 3
#define STATE_MOVEMENT     4
#define STATE_OUTER_HOLD   5
/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */


#define DATABURST_VERSION ((byte)0x00) 

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;

	real_T center_hold_l;
	real_T center_hold_h;
	real_T center_delay_l;
	real_T center_delay_h;
	real_T outer_hold_l;
	real_T outer_hold_h;
	real_T intertrial;
	real_T movement_time;
	real_T failure_lag;

	real_T target_angle;
	real_T target_radius;
	real_T target_size;
	real_T error_targets_on;

	real_T displacement_mean;
	real_T displacement_var;
	real_T block_window_begin;
	real_T block_window_end;



	real_T cloud_var_one;
	real_T cloud_var_two;
	real_T cloud_var_three;
	real_T cloud_var_four;
	real_T cloud_frq_one;
	real_T cloud_frq_two;
	real_T cloud_frq_three;
	real_T cloud_frq_four;
	real_T cloud_one_blank_on;

	real_T feedback_window_begin;
	real_T feedback_window_end;
	real_T feedback_dot_size;
	real_T feedback_dot_num;

	real_T feedback_timer_on;
	real_T feedback_time;
	real_T feedback_loc;

};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME Uncertainty1dBehavior
class Uncertainty1dBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	Uncertainty1dBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	Point cloud_points[10];
	CircleTarget *cloud[10];
	double displacement;
	double current_cloud_var;
	Point cursor_shift;
	Point cursor_end_point;
	double center_hold_time, center_delay_time, outer_hold_time;
	bool cloud_blank;

	SquareTarget *centerTarget;
	RectangleTarget *outerTarget;
	RectangleTarget *errorTargetLeft;
	RectangleTarget *errorTargetRight;

	LocalParams *params;

	// any helper functions you need
	void doPreTrial(SimStruct *S);
};

Uncertainty1dBehavior::Uncertainty1dBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(34);

	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			 0);
	
	this->bindParamId(&params->center_hold_l,			 1);
	this->bindParamId(&params->center_hold_h,			 2);
	this->bindParamId(&params->center_delay_l,			 3);
	this->bindParamId(&params->center_delay_h,			 4);
	this->bindParamId(&params->outer_hold_l,			 5);
	this->bindParamId(&params->outer_hold_h,			 6);
	this->bindParamId(&params->intertrial,				 7);
	this->bindParamId(&params->movement_time,			 8);
	this->bindParamId(&params->failure_lag,				 9);

	this->bindParamId(&params->target_angle,			10);
	this->bindParamId(&params->target_radius,			11);
	this->bindParamId(&params->target_size,				12);
	this->bindParamId(&params->error_targets_on,		13);

	this->bindParamId(&params->displacement_mean,		14);
	this->bindParamId(&params->displacement_var,		15);
	this->bindParamId(&params->block_window_begin,		16);
	this->bindParamId(&params->block_window_end,		17);
	
	this->bindParamId(&params->cloud_var_one,			18);
	this->bindParamId(&params->cloud_var_two,			19);
	this->bindParamId(&params->cloud_var_three,			20);
	this->bindParamId(&params->cloud_var_four,			21);
	this->bindParamId(&params->cloud_frq_one,			22);
	this->bindParamId(&params->cloud_frq_two,			23);
	this->bindParamId(&params->cloud_frq_three,			24);
	this->bindParamId(&params->cloud_frq_four,			25);
	this->bindParamId(&params->cloud_one_blank_on,		26);

	this->bindParamId(&params->feedback_window_begin,	27);
	this->bindParamId(&params->feedback_window_end,		28);
	this->bindParamId(&params->feedback_dot_size,		29);
	this->bindParamId(&params->feedback_dot_num,		30);

	this->bindParamId(&params->feedback_timer_on,		31);
	this->bindParamId(&params->feedback_time,			32);
	this->bindParamId(&params->feedback_loc,			33);



	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	this->updateParameters(S);

    /* 
	 * Then do any behavior specific initialization 
	 */
	centerTarget	 = new SquareTarget(0,0,0,0);
	outerTarget		 = new RectangleTarget(0,0,0,0,1);
	errorTargetLeft  = new RectangleTarget(0,0,0,0,7);
	errorTargetRight = new RectangleTarget(0,0,0,0,7);

	for (i=0; i<10; i++) {
		cloud[i] = new CircleTarget(0,0,0,Target::Color(255, 255, 0));
	}
	displacement       = 0.0;
	current_cloud_var  = 0.0;
	cursor_shift.x	   = 0.0;
	cursor_shift.y	   = 0.0;
	cursor_end_point.x = 0.0;
	cursor_end_point.y = 0.0;
	center_hold_time   = 0.0;
	center_delay_time  = 0.0;
	outer_hold_time	   = 0.0;
	cloud_blank        = false;
}

void Uncertainty1dBehavior::doPreTrial(SimStruct *S) {
	int i;
	double tgt_ang_rad;
	double total_cloud_freq;
	double actual_freq_one;
	double actual_freq_two;
	double actual_freq_three;
	double actual_freq_four;
	double r_which_var;

	// Set Center Target to Origin
	centerTarget->centerX = 0.0;
	centerTarget->centerY = 0.0;
	centerTarget->width   = params->target_size;
	centerTarget->color   = Target::Color(255, 0, 0);

	// Calculate the Displacement (Prior Shift)
	displacement = random->getGaussian(params->displacement_mean, params->displacement_var);

	// The Target Angle in Radians
	tgt_ang_rad = params->target_angle*PI/180;

	// Calculate the Cursor Shift
	cursor_shift.x = displacement*sin(tgt_ang_rad);
	cursor_shift.y = -displacement*cos(tgt_ang_rad);

	// Set Up The Targets
	if ((params->target_angle == 90.0) || (params->target_angle == 270.0)){
		outerTarget->left   = -params->target_size/2;
		outerTarget->right  =  params->target_size/2;
		outerTarget->top    = sin(tgt_ang_rad)*params->target_radius + params->target_size/2;
		outerTarget->bottom = sin(tgt_ang_rad)*params->target_radius - params->target_size/2;

		errorTargetLeft->left   = -20;
		errorTargetLeft->right  = -params->target_size/2;
		errorTargetLeft->top    = sin(tgt_ang_rad)*params->target_radius + params->target_size/2;
		errorTargetLeft->bottom = sin(tgt_ang_rad)*params->target_radius - params->target_size/2;

		errorTargetRight->left   = params->target_size/2;
		errorTargetRight->right  = 20;
		errorTargetRight->top    = sin(tgt_ang_rad)*params->target_radius + params->target_size/2;
		errorTargetRight->bottom = sin(tgt_ang_rad)*params->target_radius - params->target_size/2;
	} else if ((params->target_angle == 0.0) || (params->target_angle == 180.0)){
		outerTarget->top     = params->target_size/2;
		outerTarget->bottom  = -params->target_size/2;
		outerTarget->left    = cos(tgt_ang_rad)*params->target_radius - params->target_size/2;
		outerTarget->right   = cos(tgt_ang_rad)*params->target_radius + params->target_size/2;

		errorTargetLeft->top     = 20;
		errorTargetLeft->bottom  = params->target_size/2;
		errorTargetLeft->left    = cos(tgt_ang_rad)*params->target_radius - params->target_size/2;
		errorTargetLeft->right   = cos(tgt_ang_rad)*params->target_radius + params->target_size/2;

		errorTargetRight->top    = -params->target_size/2;
		errorTargetRight->bottom = -20;
		errorTargetRight->left   = cos(tgt_ang_rad)*params->target_radius - params->target_size/2;
		errorTargetRight->right  = cos(tgt_ang_rad)*params->target_radius + params->target_size/2;	
	} else {
		// by default, place target at top
		outerTarget->left   = -params->target_size/2;
		outerTarget->right  =  params->target_size/2;
		outerTarget->top    = params->target_radius + params->target_size/2;
		outerTarget->bottom = params->target_radius - params->target_size/2;

		errorTargetLeft->left   = -20;
		errorTargetLeft->right  = -params->target_size/2;
		errorTargetLeft->top    = params->target_radius + params->target_size/2;
		errorTargetLeft->bottom = params->target_radius - params->target_size/2;

		errorTargetRight->left   = params->target_size/2;
		errorTargetRight->right  = 20;
		errorTargetRight->top    = params->target_radius + params->target_size/2;
		errorTargetRight->bottom = params->target_radius - params->target_size/2;
	}

	r_which_var = random->getDouble();
	total_cloud_freq  = params->cloud_frq_one+params->cloud_frq_two+params->cloud_frq_three+params->cloud_frq_four;
	actual_freq_one   = params->cloud_frq_one/total_cloud_freq;
	actual_freq_two   = params->cloud_frq_two/total_cloud_freq;
	actual_freq_three = params->cloud_frq_three/total_cloud_freq;
	actual_freq_four  = params->cloud_frq_four/total_cloud_freq;
	
	if (r_which_var <= actual_freq_one){
		current_cloud_var = params->cloud_var_one;
		// Using Variance One, so check if this trial should be blanked feedback
		cloud_blank = params->cloud_one_blank_on;
	} else if (r_which_var <= actual_freq_one+actual_freq_two){
		current_cloud_var = params->cloud_var_two;
		cloud_blank = false;
	} else if (r_which_var <= actual_freq_one+actual_freq_two+actual_freq_three){
		current_cloud_var = params->cloud_var_three;
		cloud_blank = false;
	} else if (r_which_var <= actual_freq_one+actual_freq_two+actual_freq_three+actual_freq_four){
		current_cloud_var = params->cloud_var_four;
		cloud_blank = false;
	} else {
		// by default, cloud var of zero
		current_cloud_var = 0.0;
		cloud_blank = false;
	}

	// Set Up The Cloud Points
	for (i=0; i<10; i++) {
		cloud_points[i].x = random->getGaussian(0, current_cloud_var) + cursor_shift.x;
		cloud_points[i].y = random->getGaussian(0, current_cloud_var) + cursor_shift.y;
		cloud[i]->radius = params->feedback_dot_size;
	}


	// Randomized Timers
	center_hold_time  = random->getDouble(params->center_hold_l, params->center_hold_h);
	center_delay_time = random->getDouble(params->center_delay_l, params->center_delay_h);
	outer_hold_time   = random->getDouble(params->outer_hold_l, params->outer_hold_h);

	// setup the databurst
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)displacement);
	db->addFloat((float)current_cloud_var);
    db->start();
}

void Uncertainty1dBehavior::update(SimStruct *S) {
    /* declarations */
	for (int i=0; i<10; i++) {
		cloud[i]->centerX = inputs->cursor.x + cloud_points[i].x;
		cloud[i]->centerY = inputs->cursor.y + cloud_points[i].y;
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
		case STATE_CT_ON:
			/* first target on */
			if (centerTarget->cursorInTarget(inputs->cursor)) {
				setState(STATE_CENTER_HOLD);
			} 
			break;
		case STATE_CENTER_HOLD:
			if (!centerTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			else if (stateTimer->elapsedTime(S) > center_hold_time) {
				setState(STATE_CENTER_DELAY);
			}
			break;
		case STATE_CENTER_DELAY:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} 
			else if (stateTimer->elapsedTime(S) > center_delay_time) {
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_MOVEMENT:
			if (outerTarget->cursorInTarget(inputs->cursor.x+cursor_shift.x,inputs->cursor.y+cursor_shift.y)) {

				setState(STATE_OUTER_HOLD);
			} 
			else if ((params->error_targets_on) &&
				     ((errorTargetLeft->cursorInTarget(inputs->cursor.x+cursor_shift.x,inputs->cursor.y+cursor_shift.y)) ||
				      (errorTargetRight->cursorInTarget(inputs->cursor.x+cursor_shift.x,inputs->cursor.y+cursor_shift.y)))) {
			  
				cursor_end_point.x=inputs->cursor.x + cursor_shift.x;
				cursor_end_point.y=inputs->cursor.y + cursor_shift.y;
				playTone(TONE_ABORT);
				setState(STATE_FAIL);
			}
			else if (stateTimer->elapsedTime(S) > params->movement_time) {
				setState(STATE_INCOMPLETE);
			}
			break;
		case STATE_OUTER_HOLD:
			if (!outerTarget->cursorInTarget(inputs->cursor.x+cursor_shift.x,inputs->cursor.y+cursor_shift.y)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			else if (stateTimer->elapsedTime(S) > outer_hold_time) {
				cursor_end_point.x=inputs->cursor.x + cursor_shift.x;
				cursor_end_point.y=inputs->cursor.y + cursor_shift.y;
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			}
			break;
		case STATE_FAIL:
			if (stateTimer->elapsedTime(S) > (params->failure_lag + params->intertrial)) {
				setState(STATE_PRETRIAL);
			}
			break;
		case STATE_REWARD:
		case STATE_ABORT:
        case STATE_INCOMPLETE:
			if (stateTimer->elapsedTime(S) > params->intertrial) {
				setState(STATE_PRETRIAL);
			}
			break;
		default:
			setState(STATE_PRETRIAL);
	}
}

void Uncertainty1dBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
	int i;
	double cursor_extent;
	if ((params->target_angle == 90.0) || (params->target_angle == 270.0)){
		cursor_extent = fabs(inputs->cursor.y);
	} else if ((params->target_angle == 0.0) || (params->target_angle == 180.0)){
		cursor_extent = fabs(inputs->cursor.x);
	} else {
		cursor_extent = 0.0;
	}


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
			case STATE_CENTER_HOLD:
				outputs->word = WORD_OUTER_TARGET_HOLD;
				break;
			case STATE_CENTER_DELAY:
				outputs->word = WORD_OT_ON(0 /* change to whatever your target is */);
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
	// Target 0
	 if (getState() == STATE_CT_ON || 
		 getState() == STATE_CENTER_HOLD || 
		 getState() == STATE_CENTER_DELAY) {
		outputs->targets[0] = (Target *)centerTarget;
	} else {
		outputs->targets[0] = nullTarget;
	}

	// Target 1, 2, 3
	 if (getState() == STATE_CENTER_DELAY || 
		 getState() == STATE_MOVEMENT || 
		 getState() == STATE_OUTER_HOLD || 
		 getState() == STATE_REWARD || 
		 getState() == STATE_FAIL) {
		
		outputs->targets[1] = (Target *)outerTarget;

		// Only draw error targets if they are active
		if (params->error_targets_on){
			outputs->targets[2] = (Target *)errorTargetLeft;
			outputs->targets[3] = (Target *)errorTargetRight;
		} else { 
			outputs->targets[2] = nullTarget;
			outputs->targets[3] = nullTarget;
		}
	 } else {
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
		outputs->targets[3] = nullTarget;
	}

	// Target 4 through 20 Cue Cluster
	 if (getState() == STATE_MOVEMENT && 
		 cursor_extent > params->feedback_window_begin && 
		 cursor_extent < params->feedback_window_end &&
		 !cloud_blank) 
	 {
		/*show dots*/
		 for (i = 0; i<params->feedback_dot_num; i++) {
			 outputs->targets[4+i] = cloud[i];
		 }
	 } else {
		for (i = 4; i<14; i++) {
			outputs->targets[i] = nullTarget;
		}
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
	if ((getState() == STATE_MOVEMENT) && (cursor_extent >= params->block_window_begin) && (cursor_extent <= params->block_window_end)) {	
		// if we are in the cursor blocking window, hide the cursor
		outputs->position = Point(100000,100000);
	} 
	else if (getState() == STATE_OUTER_HOLD){
		// show real-time shifted cursor during outer hold
		outputs->position.x = inputs->cursor.x + cursor_shift.x;
		outputs->position.y = inputs->cursor.y + cursor_shift.y;		
	}
	else if ((getState() == STATE_REWARD) || (getState() == STATE_FAIL)) {
		// if a completed trial, show the shifted endpoint
		outputs->position.x = cursor_end_point.x;
		outputs->position.y = cursor_end_point.y;
	} else {
		// otherwise, show veridical feedback
		outputs->position = inputs->cursor;
	}
}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


