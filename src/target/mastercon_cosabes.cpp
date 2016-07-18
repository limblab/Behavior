/* $Id: mastercon_cosabes.cpp 2016-06-15 briand $
 *
 * Master Control block for behavior: center out sabes task 
 */

#define S_FUNCTION_NAME mastercon_cosabes
#define S_FUNCTION_LEVEL 2
#define TASK_DB_DEFINED 1

#include "words.h"
#include "common_header.cpp"

//#include <iostream>     // std::cout
//#include <algorithm>    // std::random_shuffle
//#include <vector>       // std::vector
//#include <ctime>        // std::time
//#include <cstdlib>      // std::rand, std::srand

#define PI (3.141592654)

/*
 * State IDs
 */
#define STATE_PRETRIAL     0
#define STATE_BUMP		   1
#define STATE_CENTER_HOLD  2
#define STATE_CENTER_DELAY 3
#define STATE_MOVEMENT     4
#define STATE_OUTER_HOLD   5
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

	real_T max_force;
	real_T force_gain;
	real_T pos_filt;
	real_T vel_filt;
	real_T cursor_return;

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
	Point cursor_shifted;
	Point cursor_curshifted;
	Point previous_trial_shift;
	Point inst_shift;

	//std::vector<int> shift_list;
	//std::vector<int> noshift_list;
	//std::vector<int> visshift_list;
	//std::vector<int> skipped_list;

	double x_pos;
	double y_pos;
	double x_pos_old;
    double y_pos_old;
    
	double x_vel;
	double y_vel;
    double x_vel_old;
    double y_vel_old;

	int shift_list[20];
	int noshift_list[20];
	int visshift_list[20];
	int skipped_list[20];

	int shift_i;
	int noshift_i;
	int skipped_i;
	int visshift_i;

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
	//void updateCursorExtent(SimStruct *S); // updates cursor extent
	void gradualOffset(SimStruct *S);
	int ColorHelper(int colorcode);
	void swap(int *a, int *b);
	void randomshuff (int arr[], int n);

	double fvec_dir;
	double fvec_mag;
	double extent_at_switch;
	double prev_cur_weighting;
	double added_lag;

	int typeflag;
	bool abort_blank;
	Point fake_shift;
	int rdir; 

};

CO_sabesBehavior::CO_sabesBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(31);

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

	this->bindParamId(&params->max_force,				26);
	this->bindParamId(&params->force_gain,				27);
	this->bindParamId(&params->vel_filt,				28);
	this->bindParamId(&params->pos_filt,				29);

	this->bindParamId(&params->cursor_return,			30);

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
	cursor_shifted.x		= 1.0;
	cursor_shifted.y		= 1.0;
	cursor_curshifted.x		= 1.0;
	cursor_curshifted.y		= 1.0;
	previous_trial_shift.x	= 0.0;
	previous_trial_shift.y	= 0.0;
	inst_shift.x			= 0.0;
	inst_shift.y			= 0.0;
	prev_cur_weighting		= 0.0;
	added_lag				= 0.0;
	abort_blank				= false;

	shift_i = 1000; // initialize high so we redraw targets on first trial
	noshift_i = 1000;
	visshift_i = 1000;
	skipped_i = 0;

	x_pos = 0.0;
	y_pos = 0.0;
	x_pos_old = 0.0;
    y_pos_old = 0.0;
    
	x_vel = 0.0;
	y_vel = 0.0;
    x_vel_old = 0.0;
    y_vel_old = 0.0;

	fvec_dir = 0.0;
	fvec_mag = 0.0;
	extent_at_switch = 1.0;
	typeflag = 0;
	fake_shift.x = 0.0;
	fake_shift.y = 0.0;
	rdir = 0;

	for (i=0; i<20; i++){
		shift_list[i]=0;
		noshift_list[i]=0;
		visshift_list[i]=0;
		skipped_list[i]=0;
	}
}

//void CO_sabesBehavior::updateCursorExtent(SimStruct *S){
//	
//	//cursor_extent = sqrt(pow(inputs->cursor.x - current_trial_shift.x,2) + 
//	//					   pow(inputs->cursor.y - current_trial_shift.y,2));
//
//	cursor_extent = sqrt(pow(cursor_shiftedV.x - centerTarget->centerX,2) + 
//						 pow(cursor_shiftedV.y - centerTarget->centerY,2));
//
//}

void CO_sabesBehavior::gradualOffset(SimStruct *S){
	// Calculate distance from cursor to target
	cursor_extent = sqrt(pow(cursor_shifted.x - centerTarget->centerX,2) + 
						 pow(cursor_shifted.y - centerTarget->centerY,2)) - params->CT_size;

	// Calculate weighting of current and previous shifts
	prev_cur_weighting = cursor_extent/extent_at_switch;
	if ((cursor_extent <= 0) || (extent_at_switch <= 0)) { 
		prev_cur_weighting = 0.0;
	} else if (prev_cur_weighting > 1) {
		prev_cur_weighting = 1.0;
	}

	// If the current trial shift is the same as the previous trials shift,
	// we'll add a cosine-shaped perturbation to the displayed cursor during the return
	if ( (current_trial_shift.x == previous_trial_shift.x) && 
	     (current_trial_shift.y == previous_trial_shift.y)) {
	/*		
		fake_shift.x = rdir * params->shift_mag * cos(params->shift_axis) * 
									(0.25 + 0.25*cos( 2*PI* prev_cur_weighting - PI));

		fake_shift.y = rdir * params->shift_mag * sin(params->shift_axis) *
									(0.25 + 0.25*cos( 2*PI* prev_cur_weighting - PI));*/

		fake_shift.x = rdir * params->shift_mag * cos(params->shift_axis) * 
									(0.5 - abs(prev_cur_weighting - 0.5));

		fake_shift.y = rdir * params->shift_mag * sin(params->shift_axis) *
									(0.5 - abs(prev_cur_weighting - 0.5));

		inst_shift.x = current_trial_shift.x + fake_shift.x;
		inst_shift.y = current_trial_shift.y + fake_shift.y;

	} else {

		inst_shift.x = current_trial_shift.x*(1-prev_cur_weighting) + 
			 		  previous_trial_shift.x*(  prev_cur_weighting);

		inst_shift.y = current_trial_shift.y*(1-prev_cur_weighting) + 
		 			  previous_trial_shift.y*(  prev_cur_weighting);
	}

	// These are the displayed, gradually shifted cursors
	cursor_shifted.x = inputs->cursor.x - inst_shift.x;
	cursor_shifted.y = inputs->cursor.y - inst_shift.y;

	// These are the instantaneousy shifted cursor versions
	cursor_curshifted.x = inputs->cursor.x - current_trial_shift.x; 
	cursor_curshifted.y = inputs->cursor.y - current_trial_shift.y;



}

int CO_sabesBehavior::ColorHelper(int colorcode){
	int retcolr;
	if ( colorcode == 1){
		retcolr = Target::Color(255,0,0);
	} else if (colorcode == 2){
		retcolr = Target::Color(0,255,0);
	} else if (colorcode == 3){
		retcolr = Target::Color(0,0,255);
	} else {
		retcolr = Target::Color(255,0,0);
	}
	return retcolr;
}

void CO_sabesBehavior::swap (int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void CO_sabesBehavior::randomshuff (int arr[], int n){
	for (int i = n-1; i > 0; i--){
		int j = random->getInteger(1,i);
		swap(&arr[i], &arr[j]);
	}
}

// Pre-trial initialization and calculations
void CO_sabesBehavior::doPreTrial(SimStruct *S) {
	int i;
	double target_index = 0.0;
	double myrandom = random->getDouble();
	double randomTrialType = random->getDouble();
	gradualOffset(S);
	if (random->getDouble() <= 0.5) { rdir = 1; } else { rdir = -1; }

	previous_trial_shift = current_trial_shift; // update "previous shift"

	// If last trial was skipped, add to skipped trials list
	if (repeat_trial){
		skipped_list[skipped_i] = shift_list[shift_i - 1];
		skipped_i++;
	}

	// Set up list of target locations for non-shift trials
	if (noshift_i > (params->co_tgtnum-1)){
		noshift_i = 0;
		for (i=0; i<params->co_tgtnum; i++) {
			noshift_list[i] = i+1;
		}
		//random->permute( (void **)noshift_list, params->co_tgtnum );
		randomshuff( noshift_list, params->co_tgtnum);
		//std::random_shuffle( noshift_list.begin(), (noshift_list.begin()+params->co_tgtnum));
	}

	//Set up list of target locations for visual-shift trials
	if (visshift_i > (2* params->co_tgtnum - 1)){
		visshift_i = 0;
		for (i=0; i<(2*params->co_tgtnum); i++){
			visshift_list[i] = i+1;
		}
		//random->permute( (void **)visshift_list, 2*params->co_tgtnum );
		randomshuff( visshift_list, 2*params->co_tgtnum);

		//std::random_shuffle( visshift_list.begin(), (visshift_list.begin() + 2*params->co_tgtnum));
	}

	// Set up list of target locations for shift trials
	if (shift_i > (2* params->co_tgtnum - 1)){
		shift_i = 0;

		if (skipped_i > (2*params->co_tgtnum - 1)){ //If our skipped trials list is full, make it the next shifted trials list
			skipped_i = 0;
			for (i=0; i<(2*params->co_tgtnum); i++){
				shift_list[i] = skipped_list[i];
			}
		} else { // Otherwise create a new randomized list
			for (i=0; i<(2*params->co_tgtnum); i++){
				shift_list[i] = i+1;//(i-params->co_tgtnum) % params->co_tgtnum;
			}
			//random->permute( (void **)shift_list , 2*params->co_tgtnum );
			//std::random_shuffle( shift_list.begin(), (shift_list.begin() + 2*params->co_tgtnum));
		}
		randomshuff( shift_list, 2*params->co_tgtnum);
	}

	target_index = shift_list[shift_i];

	// Assign target location and shift direction
	if (randomTrialType <= params->shift_freq) {
		if (target_index<(params->co_tgtnum + 1)){
			target_ang = params->co_rot*PI/180 + 2*PI*target_index/params->co_tgtnum;
			shift_dir  = 1.0;
			shift_targ = 0.0;
		} else {
			target_ang = params->co_rot*PI/180 + 2*PI*(target_index-params->co_tgtnum)/params->co_tgtnum;
			shift_dir  = -1.0;
			shift_targ = 0.0;
		}
		typeflag = 1;
		shift_i++; // increment shift trial counter
	} else if (randomTrialType <= (params->shift_freq + params->vis_freq)){
		if (visshift_list[visshift_i] < (params->co_tgtnum + 1)) {
			target_ang = params->co_rot*PI/180 + 2*PI*(visshift_list[visshift_i])/params->co_tgtnum;
			shift_dir = 0.0;
			shift_targ = 1.0;
		} else {
			target_ang = params->co_rot*PI/180 + 2*PI*(visshift_list[visshift_i]-params->co_tgtnum)
						 /params->co_tgtnum;
			shift_dir = 0.0;
			shift_targ = -1.0;
		}
		typeflag = 2;
		visshift_i++;
	} else {
		target_ang = params->co_rot*PI/180 + 2*PI*noshift_list[noshift_i]/params->co_tgtnum;
		shift_dir = 0.0;
		shift_targ = 0.0;
		typeflag = 3;
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
	centerTarget->color   = ColorHelper((int)params->CT_color);

	outerTarget->centerX = center_offset.x + (params->movement_length)*cos(target_ang)
							+ shift_targ*(params->shift_mag)*cos(params->shift_axis) ;
	outerTarget->centerY = center_offset.y + (params->movement_length)*sin(target_ang)
							+ shift_targ*(params->shift_mag)*sin(params->shift_axis) ;
	outerTarget->radius  = params->OT_size;
	outerTarget->color   = ColorHelper((int)params->OT_color);

	timerTarget->centerX = 14.25;
	timerTarget->centerY = 10.55 ;
	timerTarget->width   = 1;
	timerTarget->color   = Target::Color(255, 255, 255);

	// Initialize cursor extent
	//updateCursorExtent(S);
	
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
								pow(previous_position.y-current_trial_shift.y,2))/3.5;
    this->bump->vel_gain = params->max_force;
    this->bump->pos_gain = params->force_gain;

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
	//updateCursorExtent(S);
	gradualOffset(S);
	double current_speed = (sqrt(pow((inputs->cursor.x-previous_position.x),2)+pow((inputs->cursor.y-previous_position.y),2))/
				(stateTimer->elapsedTime(S)-previous_time_point));
	//cursor_shifted.x = inputs->cursor.x - inst_shift.x;// - current_trial_shift.x;
	//cursor_shifted.y = inputs->cursor.y - inst_shift.y;//current_trial_shift.y;
					   
	x_pos = inputs->cursor.x;//x_pos_old*(1-params->pos_filt) + inputs->cursor.x * params->pos_filt;
    y_pos = inputs->cursor.y;//y_pos_old*(1-params->pos_filt) + inputs->cursor.y * params->pos_filt;
    
    x_vel = x_vel_old*(1-params->vel_filt) + ((x_pos-x_pos_old)/.001)*params->vel_filt;
    y_vel = y_vel_old*(1-params->vel_filt) + ((y_pos-y_pos_old)/.001)*params->vel_filt; 

	fvec_mag = sqrt(pow(cursor_shifted.x,2) + pow(cursor_shifted.y,2)); 
	fvec_dir = atan2(-cursor_shifted.y,-cursor_shifted.x);

	// State machine
	switch (this->getState()) {
		case STATE_PRETRIAL:
			updateParameters(S);
			doPreTrial(S);
			extent_at_switch = cursor_extent;
			setState(STATE_DATA_BLOCK);
			break;
		case STATE_DATA_BLOCK: // Start the to initial position
			if (db->isDone()) {
				if (stateTimer->elapsedTime(S) > (added_lag + params->intertrial)) {
					added_lag = 0.0;
					setState(STATE_BUMP);
				}
			}
			break;
		case STATE_BUMP: // Wait until cursor is in center target and go to STATE_CENTER_HOLD
			//if (!this->bump->isRunning(S)){
			if (centerTarget->cursorInTarget(cursor_curshifted)){
				setState(STATE_CENTER_HOLD);
			}
			break;
		case STATE_CENTER_HOLD:
			abort_blank = false;
			repeat_trial = false;
			if (!centerTarget->cursorInTarget(cursor_curshifted)){
				if        (typeflag == 1) { shift_i--; 
				} else if (typeflag == 2) { visshift_i--; 
				} else if (typeflag == 3) { noshift_i--; }
				abort_blank = true;
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			else if (stateTimer->elapsedTime(S) >= center_hold_time) {
				setState(STATE_CENTER_DELAY);
			}
			break;
		case STATE_CENTER_DELAY:
			if (!centerTarget->cursorInTarget(cursor_curshifted)) {
				if (double (abs(shift_dir)) > 0){ 
					repeat_trial = true; 
				}
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
				if (double (abs(shift_dir)) > 0){ 
					repeat_trial = true; 
				}
				setState(STATE_INCOMPLETE);
			}
			else if (outerTarget->cursorInTarget(cursor_curshifted)) {
				setState(STATE_OUTER_HOLD);
			}
			break;
		case STATE_OUTER_HOLD:
			if (stateTimer->elapsedTime(S) >= outer_hold_time) {	
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			}
			else if (!outerTarget->cursorInTarget(cursor_curshifted)){
				playTone(TONE_FAIL);
				if (double (abs(shift_dir)) > 0){ repeat_trial = true; }
				setState(STATE_FAIL);
			}
			break;
		case STATE_FAIL:
			if (double (abs(shift_dir)) > 0){ repeat_trial = true; }
			added_lag = params->failure_lag;
			setState(STATE_PRETRIAL);
			break;
		case STATE_REWARD:
		case STATE_ABORT:
        case STATE_INCOMPLETE:
			setState(STATE_PRETRIAL);
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
	//updateCursorExtent(S);
    Point Posbump_force;

    // Position bump
	//Posbump_force = this->bump->getBumpForce(S,Point(x_vel,y_vel),Point(x_pos,y_pos));

	///* force (0) */
	//if (this->bump->isRunning(S)) {
	//	outputs->force.x = Posbump_force.x;
	//	outputs->force.y = Posbump_force.y;
	//} else {
	//	outputs->force = inputs->force;
	//}

	if (getState() == STATE_BUMP){

		Posbump_force.x = params->force_gain * fvec_mag * cos(fvec_dir);
		Posbump_force.y = params->force_gain * fvec_mag * sin(fvec_dir);

		if (sqrt(pow(Posbump_force.x,2)+pow(Posbump_force.y,2)) > params->max_force){
			outputs->force.x = params->max_force * cos(fvec_dir);
			outputs->force.y = params->max_force * sin(fvec_dir);
		} else {
			outputs->force.x = Posbump_force.x;
			outputs->force.y = Posbump_force.y;
		}

	/*} else if (getState() == STATE_CENTER_HOLD){
		outputs->force.x = -params->co_rot*x_vel;
		outputs->force.y = -params->co_rot*y_vel;*/
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
			case STATE_BUMP:
				outputs->word = WORD_BUMP(1);
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

	if (abort_blank || repeat_trial) {

		if (getState() == STATE_PRETRIAL ||
			getState() == STATE_DATA_BLOCK){
			
			outputs->position = Point(100000,100000);

		} else {
			outputs->position = cursor_curshifted;
		}
	} else {

		if (getState() == STATE_PRETRIAL ||
			getState() == STATE_DATA_BLOCK ||
			getState() == STATE_BUMP){
		
			if (params->cursor_return){
				outputs->position = cursor_shifted;
			} else {
				outputs->position = Point(100000,100000);
			}

			// otherwise, show the cursor
		} else {
			outputs->position = cursor_curshifted;
		}
	}

	x_pos_old = x_pos;
    y_pos_old = y_pos;    
    x_vel_old = x_vel;
    y_vel_old = y_vel;
}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


