/* $Id: mastercon_cosabes.cpp 2016-06-15 briand $
 *
 * Master Control block for behavior: center out sabes task 
 */

#define S_FUNCTION_NAME mastercon_cosabes
#define S_FUNCTION_LEVEL 2
#define TASK_DB_DEFINED 1

#include "words.h"
#include "common_header.cpp"

#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#define PI (3.141592654)

/*
 * State IDs
 */
#define STATE_PRETRIAL     0
#define STATE_BUMP		   1
#define STATE_CT_ON        2
#define STATE_CENTER_HOLD  3
#define STATE_CENTER_DELAY 4
#define STATE_MOVEMENT     5
#define STATE_OUTER_HOLD   6
/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */

#define DATABURST_VERSION ((byte)0x01) 

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;

	// Time Bounds for various timers
	real_T center_hold_l;
	real_T center_hold_h;
	real_T center_delay_l;
	real_T center_delay_h;
	real_T outer_hold_l;
	real_T outer_hold_h;
	real_T intertrial;
	real_T movement_time;	   // maximum allowed movement time
	real_T failure_lag;        // penalty lag for failed movements

	real_T movement_length;      // i.e. movement length
	real_T CT_size;				// width of center target
	real_T OT_size;				// size of outer target

	real_T center_X_offset;   // offset of the center along x axis
	real_T center_Y_offset;   // offset of the center along y axis

	// parameters determining the cursor shift from true hand location 
	real_T shift_mag;
	real_T shift_axis;

	// frequency of cursor shift
	real_T shift_freq;
	real_T vis_freq;
	
	real_T delay_catch_freq;
	real_T delay_catch_l;
	real_T delay_catch_h;

	real_T co_tgtnum;
	real_T co_rot;
	real_T workspace_exploration;

	real_T CT_color;
	real_T OT_color;

	real_T Gain_vel;
	real_T Gain_pos;

};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME CO_sabesBehavior
class CO_sabesBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	CO_sabesBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	PosBumpGenerator *bump;

	Point center_offset; // center target location
	Point current_trial_shift;  // current trial displacement
	double target_ang;
	double shift_dir;
	double cursor_extent;  // distance from center in direction of target

	std::vector<int> shift_list;
	std::vector<int> noshift_list;
	std::vector<int> visshift_list;
	std::vector<int> skipped_list;

	int shift_i;
	int noshift_i;
	int skipped_i;
	int visshift_i;
	int trial_counter;

	double shift_targ;

	bool repeat_trial;

	double center_hold_time, center_delay_time, outer_hold_time;

	Point  previous_position; // for calculating speed
	double previous_time_point;

	CircleTarget    *centerTarget;
	CircleTarget	*outerTarget;
	SquareTarget    *timerTarget;
	LocalParams     *params;

	// helper functions
	void doPreTrial(SimStruct *S);
	void updateCursorExtent(SimStruct *S); // updates cursor extent
	//void swap(int *a, int *b);
	//void randomshuff (int arr[], int n);

};

CO_sabesBehavior::CO_sabesBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(28);

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
	
	this->bindParamId(&params->movement_length,			10);
	this->bindParamId(&params->CT_size,					11);
	this->bindParamId(&params->OT_size,					12);
	
	this->bindParamId(&params->center_X_offset,			13);
	this->bindParamId(&params->center_Y_offset,			14);

	this->bindParamId(&params->shift_mag,				15);
	this->bindParamId(&params->shift_axis,				16);
	this->bindParamId(&params->shift_freq,				17);
	this->bindParamId(&params->vis_freq,				18);
	
	this->bindParamId(&params->delay_catch_freq,		19);
	this->bindParamId(&params->delay_catch_l,			20);
	this->bindParamId(&params->delay_catch_h,			21);

	this->bindParamId(&params->co_tgtnum,				22);
	this->bindParamId(&params->co_rot,					23);
	this->bindParamId(&params->CT_color,				24);
	this->bindParamId(&params->OT_color,				25);

	this->bindParamId(&params->Gain_vel,				26);
	this->bindParamId(&params->Gain_pos,				27);

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
	outerTarget		 = new CircleTarget(0,0,0,0);
	timerTarget      = new SquareTarget(0,0,0,0);
	this->bump		 = new PosBumpGenerator();

	cursor_extent			= 0.0;
	current_trial_shift.x   = 0.0;
	current_trial_shift.y   = 0.0;
	center_offset.x			= 0.0;
	center_offset.y			= 0.0;
	previous_position.x		= 0.0;
	previous_position.y		= 0.0;
	center_hold_time		= 0.0;
	center_delay_time		= 0.0;
	outer_hold_time			= 0.0;
	previous_time_point		= 0.0;
	target_ang				= 0.0;
	shift_dir				= 0.0;
	shift_targ				= 0.0;
	repeat_trial			= false;
	
	shift_i = 0.0;
	noshift_i = 0.0;
	skipped_i = 0.0;
	visshift_i = 0.0;
	trial_counter = 0.0;

	shift_list.reserve(20);
    noshift_list.reserve(20);
	visshift_list.reserve(20);
	skipped_list.reserve(20);

	for (i=0; i<20; i++){
		shift_list[i]=0;
		noshift_list[i]=0;
		visshift_list[i]=0;
		skipped_list[i]=0;
	}
}

void CO_sabesBehavior::updateCursorExtent(SimStruct *S){
	
	cursor_extent = sqrt((inputs->cursor.x)*(inputs->cursor.x) + (inputs->cursor.y)*(inputs->cursor.y));

}

//void CO_sabesBehavior::swap (int *a, int *b){
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void CO_sabesBehavior::randomshuff (int arr[], int n){
//	for (int i = n-1; i > 0; i--){
//		int j = random->getInteger(1,i);
//		swap(&arr[i], &arr[j]);
//	}
//}

// Pre-trial initialization and calculations
void CO_sabesBehavior::doPreTrial(SimStruct *S) {
	int i;
	double target_index = 0.0;
	double myrandom = random->getDouble();

	// If last trial was skipped, add to skipped trials list
	if (repeat_trial){
		skipped_list[skipped_i] = shift_list[shift_i - 1];
		repeat_trial = false;
		skipped_i++;
	}

	// Set up list of target locations for non-shift trials
	if (int ((int)noshift_i % (int)(params->co_tgtnum))==0){
		noshift_i = 0;
		for (i=0; i<params->co_tgtnum; i++) {
			noshift_list[i] = i+1;
		}
		std::random_shuffle( noshift_list.begin(), (noshift_list.begin()+params->co_tgtnum));
	}

	//Set up list of target locations for visual-shift trials
	if (int ((int)visshift_i % (int)(2* params->co_tgtnum))==0){
		visshift_i = 0;
		for (i=0; i<(2*params->co_tgtnum); i++){
			visshift_list[i] = i+1;
		}
		std::random_shuffle( visshift_list.begin(), (visshift_list.begin() + 2*params->co_tgtnum));
	}

	// Set up list of target locations for shift trials
	if (int ((int)shift_i % (int)(2* params->co_tgtnum))==0){
		shift_i = 0;

		if (skipped_i > (2*params->co_tgtnum - 1)){ //If our skipped trials list is full, make it the next shifted trials list
			skipped_i = 0;
			shift_list = skipped_list;
		} else { // Otherwise create a new randomized list
			for (i=0; i<(2*params->co_tgtnum); i++){
				shift_list[i] = i+1;//(i-params->co_tgtnum) % params->co_tgtnum;
			}
			std::random_shuffle( shift_list.begin(), (shift_list.begin() + 2*params->co_tgtnum));
		}
	}

	target_index = shift_list[shift_i];

	// Assign target location and shift direction
	if (random->getDouble() <= params->shift_freq) {
		if (target_index<(params->co_tgtnum + 1)){
			target_ang = params->co_rot*PI/180 +2*PI*target_index/params->co_tgtnum;
			shift_dir  = 1.0;
			shift_targ = 0.0;
		} else {
			target_ang = params->co_rot*PI/180 +2*PI*(target_index-params->co_tgtnum)/params->co_tgtnum;
			shift_dir  = -1.0;
			shift_targ = 0.0;
		}
		shift_i++; // increment shift trial counter
	} else if (random->getDouble() <= (params->shift_freq + params->vis_freq)){
		if (visshift_list[visshift_i] < (params->co_tgtnum + 1)) {
			target_ang = params->co_rot*PI/180 + 2*PI*(visshift_list[visshift_i])/params->co_tgtnum;
			shift_dir = 0.0;
			shift_targ = 1.0;
		} else {
			target_ang = params->co_rot*PI/180 +2*PI*(visshift_list[visshift_i]-params->co_tgtnum)
						 /params->co_tgtnum;
			shift_dir = 0.0;
			shift_targ = -1.0;
		}
		visshift_i++;
	} else {
		target_ang = noshift_list[noshift_i];
		shift_dir = 0.0;
		shift_targ = 0.0;
		noshift_i++; // increment non-shift trial counter
	}

	// Apply cursor shift
	current_trial_shift.x = shift_dir*(params->shift_mag)*cos(params->shift_axis);
	current_trial_shift.y = shift_dir*(params->shift_mag)*sin(params->shift_axis);

	center_offset.x = params->center_X_offset;
	center_offset.y = params->center_Y_offset;

	// Set up the targets

	centerTarget->centerX = 0.0+center_offset.x+shift_targ*(params->shift_mag)*cos(params->shift_axis) ;
	centerTarget->centerY = 0.0+center_offset.y+shift_targ*(params->shift_mag)*sin(params->shift_axis) ;
	centerTarget->radius  = params->CT_size;
	centerTarget->color   = Target::Color(255, 0, 0);

	outerTarget->centerX = center_offset.x + (params->movement_length)*cos(target_ang)
							+ shift_targ*(params->shift_mag)*cos(params->shift_axis) ;
	outerTarget->centerY = center_offset.y + (params->movement_length)*sin(target_ang)
							+ shift_targ*(params->shift_mag)*sin(params->shift_axis) ;
	outerTarget->radius  = params->OT_size;
	outerTarget->color   = params->OT_color;

	timerTarget->centerX = 14.25;
	timerTarget->centerY = 10.55 ;
	timerTarget->width   = 1;
	timerTarget->color   = Target::Color(255, 255, 255);

	// Initialize cursor extent
	updateCursorExtent(S);
	
	// Randomized Timers
	center_hold_time  = random->getDouble(params->center_hold_l, params->center_hold_h);
	
	// if this is a center delay catch trial, calculate the delay time based on catch bounds
	if (random->getDouble() <= params->delay_catch_freq)
	{
		center_delay_time = random->getDouble(params->delay_catch_l, params->delay_catch_h);
	}
	else
	{
		center_delay_time = random->getDouble(params->center_delay_l, params->center_delay_h);
	}
	
	outer_hold_time = random->getDouble(params->outer_hold_l, params->outer_hold_h);

	this->bump->distance = sqrt(pow(previous_position.x-current_trial_shift.x,2) + 
								pow(previous_position.y-current_trial_shift.y,2));
	this->bump->direction = atan2(current_trial_shift.y-previous_position.y,current_trial_shift.x-previous_position.x);
    this->bump->duration = sqrt(pow(previous_position.x-current_trial_shift.x,2) + 
								pow(previous_position.y-current_trial_shift.y,2))/13.3;
    this->bump->vel_gain = params->Gain_vel;
    this->bump->pos_gain = params->Gain_pos;

	// setup the databurst
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('S');
	db->addByte('A');
	db->addByte('B');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)target_ang);
	db->addFloat((float)shift_dir);
	db->addFloat((float)shift_targ);

    db->start();
}

void CO_sabesBehavior::update(SimStruct *S) {
    /* declarations */
	double current_speed = (sqrt(pow((inputs->cursor.x-previous_position.x),2)+pow((inputs->cursor.y-previous_position.y),2))/
				(stateTimer->elapsedTime(S)-previous_time_point));
	
	// State machine
	switch (this->getState()) {
		case STATE_PRETRIAL:
			updateParameters(S);
			doPreTrial(S);
			setState(STATE_DATA_BLOCK);
			break;
		case STATE_DATA_BLOCK: // Start the to initial position
			if (db->isDone()) {
				this->bump->start(S);
				setState(STATE_BUMP);
			}
		case STATE_BUMP: // Wait for bump to finish and go to STATE_CT_ON
			if (!this->bump->isRunning(S)){
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
			else if (stateTimer->elapsedTime(S) >= center_hold_time) {
				setState(STATE_CENTER_DELAY);
			}
			break;
		case STATE_CENTER_DELAY:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} 
			else if (stateTimer->elapsedTime(S) >= center_delay_time) {
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_MOVEMENT:
			if (stateTimer->elapsedTime(S) > params->movement_time) {
				if (double (abs(shift_dir)) > 0){ repeat_trial = true; }
				setState(STATE_INCOMPLETE);
			}
			else if (outerTarget->cursorInTarget(inputs->cursor)) {
				setState(STATE_OUTER_HOLD);
			}
			break;
		case STATE_OUTER_HOLD:
			if (stateTimer->elapsedTime(S) >= outer_hold_time) {	
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			}
			else if (!outerTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				if (double (abs(shift_dir)) > 0){ repeat_trial = true; }
				setState(STATE_ABORT);
			}
			break;
		case STATE_FAIL:
			if (stateTimer->elapsedTime(S) > (params->failure_lag + params->intertrial)) {
				if (double (abs(shift_dir)) > 0){ repeat_trial = true; }
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
    // assign the current position and time point to previous position
	previous_position = inputs->cursor;
	previous_time_point = stateTimer->elapsedTime(S);
}

void CO_sabesBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
	int i;
	updateCursorExtent(S);

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
			case STATE_BUMP:
				outputs->word = WORD_BUMP(1);
				break;
			case STATE_CT_ON:
				outputs->word = WORD_CT_ON;
				break;
			case STATE_CENTER_HOLD:
				outputs->word = WORD_CENTER_TARGET_HOLD;
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
	// Target 0 is the center target
	if (getState() == STATE_BUMP ||
		getState() == STATE_CT_ON || 
		getState() == STATE_CENTER_HOLD || 
		getState() == STATE_CENTER_DELAY) {
		outputs->targets[0] = (Target *)centerTarget;
	} else {
		outputs->targets[0] = nullTarget;
	}

	// Target 1 is the outer target
	if (getState() == STATE_CENTER_DELAY || 
		getState() == STATE_MOVEMENT ||
		getState() == STATE_OUTER_HOLD ||
		getState() == STATE_REWARD) {

		outputs->targets[1] = (Target *)outerTarget;

	}else {
		outputs->targets[1] = nullTarget;
	}

	// Target 2 is the Timer Dot
	if (stateTimer->elapsedTime(S) < 0.25) {
		outputs->targets[2] = (Target *)timerTarget;
	}
	else {
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
	// If we are in the return portion
	if (getState() == STATE_BUMP){

		// Hide cursor
		outputs->position = Point(100000,100000);

		// otherwise, show the cursor
	} else {
		outputs->position.x = inputs->cursor.x - current_trial_shift.x;
		outputs->position.y = inputs->cursor.y - current_trial_shift.y;
	}

}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


