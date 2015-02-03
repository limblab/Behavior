/* $Id: mastercon_cuecomb.cpp 2015-01-07
 *
 * Master Control block for behavior: cue combination on the circle
 */
 
//#pragma warning(disable: 4800)

#define S_FUNCTION_NAME mastercon_cuecomb
#define S_FUNCTION_LEVEL 2

// Our task code will be in the databurst
#define TASK_DB_DEFINED 1
#include "words.h"
#include "common_header.cpp"

#define PI (3.141592654)

/*
 * State IDs
 */
#define STATE_PRETRIAL	0
#define STATE_CT_ON		1
#define STATE_CT_HOLD	2
#define STATE_BUMP_OUT  3
#define STATE_BUMP_IN	4
#define STATE_CT_DELAY	5
#define STATE_MOVEMENT	6
#define STATE_OT_HOLD	7

/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */
	
#define DATABURST_VERSION ((byte)0x01) 
#define DATABURST_TASK_CODE ((byte)0x01)

// This must be custom defined for your behavior
struct LocalParams {

	real_T master_reset;
	// Time Bounds for various timers
	real_T center_hold_l;
	real_T center_hold_h;
	real_T center_delay_l;
	real_T center_delay_h;
	real_T intertrial;
	real_T movement_time;	  // maximum allowed movement time
	real_T failure_lag;       // penalty lag for failed movements

	real_T movement_length;   // i.e. movement length
	real_T target_size;       // width of center target
	real_T OT_size;			  // size of outer target
	real_T OT_depth;
	real_T center_X_offset;   // offset of the center along x axis
	real_T center_Y_offset;   // offset of the center along y axis

	// parameters determining the visual uncertainty
	real_T prior_mean;
	real_T prior_kap;

	// currently supports up to four feedback cloud uncertainties
	real_T cloud_kap_one;
	real_T cloud_kap_two;
	real_T cloud_kap_three;
	real_T cloud_kap_four;
	// relative frequency of occurrence for each cloud (arbitrary units)
	real_T cloud_freq_one;
	real_T cloud_freq_two;
	real_T cloud_freq_three;
	real_T cloud_freq_four;
	
	// up to three different bump levels
	real_T use_random_bump;
	real_T random_bump_low;
	real_T random_bump_high;
	real_T bump_mag_one;
	real_T bump_mag_two;
	real_T bump_mag_three;
	// relative frequency of occurence for each bump magnitude
	real_T bump_freq_one;
	real_T bump_freq_two;
	real_T bump_freq_three;

	real_T bump_duration;
	real_T bump_duration_back;
	real_T Gain_pos;
	real_T Gain_vel;

	real_T cloud_one_blank_mode; // toggles blank feedback (no cloud) for "cloud one"

	real_T slice_size;    // size of each slice in cloud
	real_T slice_number;	 // number of slices in the cloud

	real_T delay_catch_freq;
	real_T delay_catch_l;
	real_T delay_catch_h;
	
	real_T use_cohack_mode;
	real_T cohack_tgtnum;

	real_T stim_prob;

	real_T pos_filt; 
	real_T vel_filt;

	real_T NoReturn;

	real_T feedback_win;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME cuecombBehavior
class cuecombBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	cuecombBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
    Point cursorOffset;

	PosBumpGenerator *bump;

	bool stim_trial;
	
	// Your behavior's instance variables
	Point  center_offset; // center target offset
	double current_trial_shift;  // current trial displacement
	double  target_shift;  // current trial cursor shift
	Point  cursor_end_point; // current trial end point
	double cursor_extent;  // distance from center in direction of target
	double current_trial_bumpmag; // current trial bump magnitude

	double  slice_points[10];
	double current_target_stdev; // current trial feedback variance
	bool   cloud_blank;       // toggles current trial, blank feedback
	bool   cohack_mode;
	bool   random_bump_mode;

	Point bump_offset;

	double center_hold_time, center_delay_time, outer_hold_time;

	Point  previous_position; // for calculating speed
	double previous_time_point;

	double x_pos;
	double y_pos;
	double x_pos_old;
    double y_pos_old;
    
	double x_vel;
	double y_vel;
    double x_vel_old;
    double y_vel_old;

	CircleTarget    *centerTarget;
	ArcTarget		*outerTarget;
	ArcTarget		*targetBar;
	ArcTarget		*cloud[10];
	SquareTarget    *timerTarget;
	LocalParams     *params;

	// helper functions
	void doPreTrial(SimStruct *S);
	void updateCursorExtent(SimStruct *S); // updates cursor extent (used for windowing)

};

cuecombBehavior::cuecombBehavior(SimStruct *S) : RobotBehavior() {

	int i;
	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(50);

	this->bindParamId(&params->master_reset,		0);
	
	this->bindParamId(&params->center_hold_l,		1);
	this->bindParamId(&params->center_hold_h,		2);

	this->bindParamId(&params->center_delay_l,		3);
	this->bindParamId(&params->center_delay_h,		4);
	this->bindParamId(&params->intertrial,			5);
	this->bindParamId(&params->movement_time,		6);	 
	this->bindParamId(&params->failure_lag,			7);       
	this->bindParamId(&params->movement_length,		8);  
	this->bindParamId(&params->target_size,			9);       
	this->bindParamId(&params->OT_size,				10);			
	this->bindParamId(&params->OT_depth,			11);
	this->bindParamId(&params->center_X_offset,		12);   
	this->bindParamId(&params->center_Y_offset,		13);   
	this->bindParamId(&params->prior_mean,			14);
	this->bindParamId(&params->prior_kap,			15);
	
	this->bindParamId(&params->cloud_kap_one,		16);
	this->bindParamId(&params->cloud_kap_two,		17);
	this->bindParamId(&params->cloud_kap_three,		18);
	this->bindParamId(&params->cloud_kap_four,		19);

	this->bindParamId(&params->cloud_freq_one,		20);
	this->bindParamId(&params->cloud_freq_two,		21);
	this->bindParamId(&params->cloud_freq_three,	22);
	this->bindParamId(&params->cloud_freq_four,		23);

	this->bindParamId(&params->cloud_one_blank_mode,24); 
	this->bindParamId(&params->slice_size,			25);    
	this->bindParamId(&params->slice_number,		26);	
	
	this->bindParamId(&params->delay_catch_freq,	27);
	this->bindParamId(&params->delay_catch_l,		28);
	this->bindParamId(&params->delay_catch_h,		29);
	this->bindParamId(&params->use_cohack_mode,		30);
	this->bindParamId(&params->cohack_tgtnum,		31);
	
	this->bindParamId(&params->use_random_bump,		32);	
	this->bindParamId(&params->random_bump_low,		33);
	this->bindParamId(&params->random_bump_high,	34);

	this->bindParamId(&params->bump_mag_one,		35);
	this->bindParamId(&params->bump_mag_two,		36);
	this->bindParamId(&params->bump_mag_three,		37);

	this->bindParamId(&params->bump_freq_one,		38);
	this->bindParamId(&params->bump_freq_two,		39);
	this->bindParamId(&params->bump_freq_three,		40);

	this->bindParamId(&params->bump_duration,		41);
    this->bindParamId(&params->Gain_pos,			42);
	this->bindParamId(&params->Gain_vel,			43);

	this->bindParamId(&params->stim_prob,			44);

	this->bindParamId(&params->pos_filt,			45);
	this->bindParamId(&params->vel_filt,			46);

	this->bindParamId(&params->bump_duration_back,	47);
	this->bindParamId(&params->NoReturn,			48);
	
	this->bindParamId(&params->feedback_win,		49);

	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	this->updateParameters(S);

	centerTarget	= new CircleTarget(0,0,0,0);
	outerTarget		= new ArcTarget(0,0,0,0,5);
	targetBar		= new ArcTarget(0,0,0,0,8);
	timerTarget		= new SquareTarget(0,0,0,0);

	for (i=0; i<10; i++) {
		cloud[i] = new ArcTarget(0,0,0,0,5);
	}
	this->stim_trial = false;
	this->bump = new PosBumpGenerator();

	x_pos_old = 0;
    y_pos_old = 0;
    
    x_vel_old = 0;
    y_vel_old = 0;

	cursor_extent		 = 0.0;
	current_trial_shift  = 0.0;
	current_target_stdev = 0.0;
	target_shift         = 0.0;
	center_offset.x	     = 0.0;
	center_offset.y	     = 0.0;
	previous_position.x  = 0.0;
	previous_position.y  = 0.0;
	cursor_end_point.x   = 0.0;
	cursor_end_point.y   = 0.0;
	center_hold_time     = 0.0;
	center_delay_time    = 0.0;
	outer_hold_time	     = 0.0;
	previous_time_point  = 0.0;
	bump_offset.x		 = 0.0;
	bump_offset.y		 = 0.0;
	cloud_blank          = false;
	cohack_mode			 = false;
	random_bump_mode	 = false;

}
void cuecombBehavior::updateCursorExtent(SimStruct *S){
	cursor_extent = sqrt((inputs->cursor.x-bump_offset.x)*(inputs->cursor.x-bump_offset.x)
					   + (inputs->cursor.y-bump_offset.y)*(inputs->cursor.y-bump_offset.y));
}

void cuecombBehavior::doPreTrial(SimStruct *S) {
	int i;
	double total_cloud_freq;
	double actual_freq_one;
	double actual_freq_two;
	double actual_freq_three;
	double actual_freq_four;
	double cloud_rand;
	double bump_rand;
	double act_bf_one;
	double act_bf_two;
	double act_bf_three;
	double total_bump_freq;
	double vel_from_dist;

	cohack_mode = params->use_cohack_mode;
	random_bump_mode = params->use_random_bump;

	// Get Random target location (Prior Shift)
	current_trial_shift = (params->prior_mean)*PI/180 + random->getVonMises(params->prior_kap);

	// If in center out hack mode, set the "shift" to one of a set number of potential locations
	if (cohack_mode){
		current_trial_shift = 2*PI*random->getInteger(1,params->cohack_tgtnum)/params->cohack_tgtnum;
	}

	// Get bump magnitude
	if (random_bump_mode){
		current_trial_bumpmag = random->getDouble(params->random_bump_low,params->random_bump_high);
	}else{
		
		bump_rand = random->getDouble();  	// generate a random number between 0 and 1
		total_bump_freq  = fabs(params->bump_freq_one)+fabs(params->bump_freq_two)+
			fabs(params->bump_freq_three);
		// in case of divide by zero
		if (total_bump_freq == 0){
			total_bump_freq = 1.0;
		}

		// recalculate frequencies 
		act_bf_one   = fabs(params->bump_freq_one)/total_bump_freq;
		act_bf_two   = fabs(params->bump_freq_two)/total_bump_freq;
		act_bf_three = fabs(params->bump_freq_three)/total_bump_freq;
		
		if (bump_rand <= act_bf_one){
			current_trial_bumpmag = params->bump_mag_one;
		} else if (bump_rand <= act_bf_one+act_bf_two){
			current_trial_bumpmag = params->bump_mag_two;
		} else if (bump_rand <= act_bf_one+act_bf_two+act_bf_three){
			current_trial_bumpmag = params->bump_mag_three;
		} else {
			// by default, no bump
			current_trial_bumpmag = 0.0;
		}

	}

	center_offset.x = params->center_X_offset;
	center_offset.y = params->center_Y_offset;

	// Calculate the Target Shift
	target_shift = current_trial_shift;
    
	/* Select whether this will be a stimulation trial */
    this->stim_trial=(this->random->getDouble() < params->stim_prob);

	// Set up the Bump	
	if (this->stim_trial){
		current_trial_bumpmag=0;
	}

	this->bump->distance = current_trial_bumpmag;
	this->bump->direction = target_shift;
    this->bump->duration = params->bump_duration;
    this->bump->vel_gain = params->Gain_vel;
    this->bump->pos_gain = params->Gain_pos;

	// Set up Visual Target
	cloud_rand = random->getDouble(); // Generate random number between 0 and 1
	total_cloud_freq  = fabs(params->cloud_freq_one)+fabs(params->cloud_freq_two)+
		fabs(params->cloud_freq_three)+fabs(params->cloud_freq_four);
	// in case of divide by zero
	if (total_cloud_freq == 0){
		total_cloud_freq = 1.0;
	}
	// recalculate frequencies 
	actual_freq_one   = fabs(params->cloud_freq_one)/total_cloud_freq;
	actual_freq_two   = fabs(params->cloud_freq_two)/total_cloud_freq;
	actual_freq_three = fabs(params->cloud_freq_three)/total_cloud_freq;
	actual_freq_four  = fabs(params->cloud_freq_four)/total_cloud_freq;
	
	if (cloud_rand <= actual_freq_one){
		current_target_stdev = params->cloud_kap_one;
		// Using Variance One, so check if this trial should be blanked feedback
		cloud_blank = params->cloud_one_blank_mode;
	} else if (cloud_rand <= actual_freq_one+actual_freq_two){
		current_target_stdev = params->cloud_kap_two;
		cloud_blank = false;
	} else if (cloud_rand <= actual_freq_one+actual_freq_two+actual_freq_three){
		current_target_stdev = params->cloud_kap_three;
		cloud_blank = false;
	} else if (cloud_rand <= actual_freq_one+actual_freq_two+actual_freq_three+actual_freq_four){
		current_target_stdev = params->cloud_kap_four;
		cloud_blank = false;
	} else {
		// by default, no feedback is shown
		current_target_stdev = 0.0;
		cloud_blank = true;
	}

	// Set Up The Cloud Points
	for (i=0; i<10; i++) {
			// For 1D clouds, since targets are at 0, 90, 180, 270....
			slice_points[i] = random->getVonMises(current_target_stdev);
	}

	// Set Up The Targets

	centerTarget->centerX = 0.0;//+center_offset.x ;
	centerTarget->centerY = 0.0;//+center_offset.y ;
	centerTarget->radius   = params->target_size;
	centerTarget->color   = Target::Color(255, 0, 0);

	outerTarget->r = params->movement_length;
	outerTarget->theta = target_shift;
	outerTarget->span   = (params->OT_size)*PI/180;
	outerTarget->height = params->OT_depth;

	targetBar->r  = params->movement_length;
	targetBar->theta  = 0; 
	targetBar->span    = 2*PI-0.00001;
	targetBar->height = params->OT_depth+.1;

	timerTarget->centerX = 14.25;
	timerTarget->centerY = 10.55 ;
	timerTarget->width   = 0.8;
	timerTarget->color   = Target::Color(255, 255, 255);

	for (i=0; i<10; i++) {
		cloud[i]->r      = params->movement_length;
		cloud[i]->theta  = target_shift + slice_points[i];
		cloud[i]->span   = (params->slice_size)*PI/180;
		cloud[i]->height = params->OT_depth;
	}

	// Initialize the cloud and cursor extent
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
	
	outer_hold_time = params->intertrial;

	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('C');
	db->addByte('C');
	db->addByte('B');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)current_trial_shift);
	db->addFloat((float)params->prior_kap);
	db->addFloat((float)this->current_trial_bumpmag);
	db->addFloat((float)this->params->bump_duration);
	db->addFloat((float)this->params->bump_duration_back);
	db->addByte((byte)this->stim_trial);
	db->addFloat((float)current_target_stdev);
	db->addFloat((float)params->slice_number);
	// Set Up The Cloud Points
	for (i=0; i<10; i++) {
		db->addFloat((float)slice_points[i]);
	}
    db->start();
}

void cuecombBehavior::update(SimStruct *S) {

    x_pos = x_pos_old*(1-params->pos_filt) + inputs->cursor.x * params->pos_filt;
    y_pos = y_pos_old*(1-params->pos_filt) + inputs->cursor.y * params->pos_filt;
    
    x_vel = x_vel_old*(1-params->vel_filt) + ((x_pos-x_pos_old)/.001)*params->vel_filt;
    y_vel = y_vel_old*(1-params->vel_filt) + ((y_pos-y_pos_old)/.001)*params->vel_filt;   

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
			} else if (stateTimer->elapsedTime(S) > center_hold_time) {
				this->bump->start(S);
				setState(STATE_BUMP_OUT);
			}
			break;
		case STATE_BUMP_OUT:
			if (!this->bump->isRunning(S)){
				this->bump->direction = target_shift + PI;
				if (params->NoReturn){
					this->bump->distance = 0;
					bump_offset = inputs->cursor;
				} else { 
					this->bump->distance = current_trial_bumpmag;
					bump_offset.x = 0.0;
					bump_offset.y = 0.0;
					this->bump->duration = params->bump_duration_back;
				}
				this->bump->duration = params->bump_duration;
				this->bump->start(S);
				setState(STATE_BUMP_IN);
			}
			break;
		case STATE_BUMP_IN:
			if (!this->bump->isRunning(S)){
				setState(STATE_CT_DELAY);
			}
			break;
		case STATE_CT_DELAY:
			if (!centerTarget->cursorInTarget(inputs->cursor.x-bump_offset.x,
											  inputs->cursor.y-bump_offset.y)) {
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
				setState(STATE_INCOMPLETE);
			} else if (cursor_extent > params->movement_length-(params->OT_depth*0.50)) {
				if (params->NoReturn){
					cursor_end_point.x = inputs->cursor.x - bump_offset.x;
					cursor_end_point.y = inputs->cursor.y - bump_offset.y;
				} else {
					cursor_end_point=inputs->cursor;
				}
				setState(STATE_OT_HOLD);
			}
			break;  		
		case STATE_OT_HOLD:
			if (outerTarget->cursorInTarget(cursor_end_point)){
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			} else if (!outerTarget->cursorInTarget(cursor_end_point)) {
				playTone(TONE_ABORT);
				setState(STATE_FAIL);
			}
			break;
		case STATE_FAIL:         
			if (stateTimer->elapsedTime(S) > (params->intertrial+params->failure_lag)) {
				setState(STATE_PRETRIAL);
			}
			break;
		
		case STATE_ABORT:
			this->bump->stop();
			if (stateTimer->elapsedTime(S) > params->intertrial) {
				setState(STATE_PRETRIAL);
			}
			break;
        case STATE_REWARD:
			if (stateTimer->elapsedTime(S) > params->intertrial) {
				setState(STATE_PRETRIAL);
			}
			break;
        case STATE_INCOMPLETE:
			this->bump->stop();
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

void cuecombBehavior::calculateOutputs(SimStruct *S) {
    updateCursorExtent(S);
	
	/* declarations */
    Point bf;
	int i;
	real_T x_force_bump;
    real_T y_force_bump;           

    // Position bump
    Point Posbump_force = this->bump->getBumpForce(S,Point(x_vel,y_vel),Point(x_pos,y_pos));
    x_force_bump = Posbump_force.x;
    y_force_bump = Posbump_force.y;    

	/* force (0) */
	if (this->bump->isRunning(S)) {
		outputs->force.x = x_force_bump;
		outputs->force.y = y_force_bump;
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
			case STATE_BUMP_OUT:
				outputs->word = WORD_BUMP(0);
				break;
			case STATE_BUMP_IN:
				outputs->word = WORD_BUMP(1);
				break;
			case STATE_CT_HOLD:
				outputs->word = WORD_CENTER_TARGET_HOLD;
				break;
			case STATE_CT_DELAY:
				outputs->word = WORD_OT_ON(0);
				break;
			case STATE_MOVEMENT:
				outputs->word = WORD_GO_CUE;
				break;
			case STATE_OT_HOLD:
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
	// Center Target (0)
	if (getState() == STATE_CT_ON ||
		getState() == STATE_CT_HOLD ||
		getState() == STATE_BUMP_OUT ||
		getState() == STATE_BUMP_IN ||
		getState() == STATE_CT_DELAY) {
			outputs->targets[0] = (Target *)centerTarget;
	}else{
		outputs->targets[0] = nullTarget;
	}

	// Outer target (correct) and Target Bar (1-2)
	if (	getState() == STATE_CT_HOLD		||
			getState() == STATE_CT_DELAY	||
			getState() == STATE_BUMP_OUT	||
			getState() == STATE_BUMP_IN		||
			getState() == STATE_MOVEMENT){
		
		outputs->targets[1] = (Target *)outerTarget;
		outputs->targets[2] = (Target *)targetBar;
	} else if (getState() == STATE_OT_HOLD ||
			   getState() == STATE_REWARD  ||
			   getState() == STATE_FAIL) {

		outputs->targets[1] = (Target *)targetBar;
		outputs->targets[2] = (Target *)outerTarget;

	}else {
		outputs->targets[2] = nullTarget;
		outputs->targets[1] = nullTarget;
	}


	// Targets 3 through 12 Target Cloud (3-12)

	if (!cloud_blank &&
		(getState() == STATE_BUMP_OUT || 
		getState() == STATE_BUMP_IN || 
		((getState() == STATE_CT_DELAY || 
		getState() == STATE_MOVEMENT) &&
		cursor_extent < params->feedback_win))) {
		for (i = 0; i<params->slice_number; i++) {
			outputs->targets[3+i] = cloud[i];
		}
	} else {
		for (i = 0; i<params->slice_number; i++) {
			outputs->targets[3+i] = nullTarget;
		}
	}
		
	
	/* Timer Dot */
	if ( getState() == STATE_CT_ON	 ||
		 getState() == STATE_CT_HOLD ||
		 getState() == STATE_BUMP_OUT ||
		 getState() == STATE_MOVEMENT ||
		 getState() == STATE_OT_HOLD) {
	
		if (stateTimer->elapsedTime(S) < 0.25) {
			outputs->targets[14] = (Target *)timerTarget;
		} else {
			outputs->targets[14] = nullTarget;
		} 
	} else {
		outputs->targets[14] = nullTarget;
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

	/* cursor position (7) */
	if (getState() == STATE_BUMP_OUT ||
		getState() == STATE_BUMP_IN){

		outputs->position = Point(100000,100000);
	} else if ( getState() == STATE_OT_HOLD ||
				getState() == STATE_REWARD ||
			    getState() == STATE_FAIL) {
		outputs->position = cursor_end_point;
	} else if ( getState() == STATE_CT_DELAY ||
				getState() == STATE_MOVEMENT ||
				getState() == STATE_ABORT    ||
				getState() == STATE_INCOMPLETE) {
		outputs->position.x = inputs->cursor.x - bump_offset.x;
		outputs->position.y = inputs->cursor.y - bump_offset.y;
	} else {
		outputs->position = inputs->cursor;
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


