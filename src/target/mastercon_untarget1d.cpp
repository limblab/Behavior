/* $Id: mastercon_un1d.cpp 858 2012-11-01 21:46:24Z paulw $
 *
 * Master Control block for behavior: uncertainty target 1d task 
 */

#define S_FUNCTION_NAME mastercon_untarget1d
#define S_FUNCTION_LEVEL 2
#define TASK_DB_DEFINED 1

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

	real_T target_angle;       // Four cardinal directions
	real_T movement_length;      // i.e. movement length
	real_T target_size;        // width of target
	real_T center_X_offset;   // offset of the center along x axis
	real_T center_Y_offset;   // offset of the center along y axis

	// parameters determining the cursor shift from true hand location 
	//   (always perpendicular to target direction)
	real_T shift_mean;
	real_T shift_stdev;
	real_T block_window_begin;
	real_T block_window_end;

	// currently supports up to four feedback cloud uncertainties
	real_T cloud_stdev_one;
	real_T cloud_stdev_two;
	real_T cloud_stdev_three;
	real_T cloud_stdev_four;

	// relative frequency of occurrence for each cloud (arbitrary units)
	real_T cloud_freq_one;
	real_T cloud_freq_two;
	real_T cloud_freq_three;
	real_T cloud_freq_four;

	real_T cloud_one_blank_mode; // toggles blank feedback (no cloud) for "cloud one"

	real_T slice_size;    // size of each dot in cloud
	real_T slice_number;	 // number of dots in the cloud
	real_T feedback_window_begin;
	real_T feedback_window_end;

	real_T cloud_jitter;

	//   timed:    displays static feedback cloud centered at shifted cursor position when at a 
	//			   specified distance, for a specific length of time
	real_T use_timed_cloud;		// toggles use of the feedback timer instead of windowed feedback
	real_T timed_duration;		// time feedback cloud is shown
	real_T timed_location;      // where the feedback cloud is activated (in cm along radius)
	real_T use_delay_cloud;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME UncertaintyTarget1dBehavior
class UncertaintyTarget1dBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	UncertaintyTarget1dBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	Point  center_offset; // center target offset
	double current_trial_shift;  // current trial displacement
	Point  target_shift;  // current trial cursor shift
	Point  cursor_end_point; // current trial end point
	double cursor_extent;  // distance from center in direction of target

	Point  slice_points[10];
	double current_target_stdev; // current trial feedback variance
	bool   cloud_blank;       // toggles current trial, blank feedback
	bool   delay_cloud_mode;
	Timer  *feedback_timer; // feedback timer
	
	double center_hold_time, center_delay_time, outer_hold_time;

	Point  previous_position; // for calculating speed
	double previous_time_point;

	SquareTarget    *centerTarget;
	SquareTarget	 *outerTarget;
	RectangleTarget *targetBar;
	RectangleTarget *cloud[10];

	LocalParams *params;

	// helper functions
	void doPreTrial(SimStruct *S);
	void updateCursorExtent(SimStruct *S); // updates cursor extent (used for windowing)
};

UncertaintyTarget1dBehavior::UncertaintyTarget1dBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(37);

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
	this->bindParamId(&params->movement_length,			11);
	this->bindParamId(&params->target_size,				12);
	this->bindParamId(&params->center_X_offset,			13);
	this->bindParamId(&params->center_Y_offset,			14);

	this->bindParamId(&params->shift_mean,				15);
	this->bindParamId(&params->shift_stdev,				16);
	this->bindParamId(&params->block_window_begin,		17);
	this->bindParamId(&params->block_window_end,		18);
	
	this->bindParamId(&params->cloud_stdev_one,			19);
	this->bindParamId(&params->cloud_stdev_two,			20);
	this->bindParamId(&params->cloud_stdev_three,		21);
	this->bindParamId(&params->cloud_stdev_four,		22);
	this->bindParamId(&params->cloud_freq_one,			23);
	this->bindParamId(&params->cloud_freq_two,			24);
	this->bindParamId(&params->cloud_freq_three,		25);
	this->bindParamId(&params->cloud_freq_four,			26);
	this->bindParamId(&params->cloud_one_blank_mode,	27);

	this->bindParamId(&params->slice_size,				28);
	this->bindParamId(&params->slice_number,			29);
	this->bindParamId(&params->feedback_window_begin,	30);
	this->bindParamId(&params->feedback_window_end,		31);

	this->bindParamId(&params->cloud_jitter,			32);
	this->bindParamId(&params->use_timed_cloud,			33);
	this->bindParamId(&params->timed_duration,			34);
	this->bindParamId(&params->timed_location,			35);

	this->bindParamId(&params->use_delay_cloud,			36);

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
	outerTarget		 = new SquareTarget(0,0,0,0);
	targetBar		 = new RectangleTarget(0,0,0,0,7);
	feedback_timer	 = new Timer();
	for (i=0; i<10; i++) {
		cloud[i] = new RectangleTarget(0,0,0,0,1);
	}
	cursor_extent			   = 0.0;
	current_trial_shift       = 0.0;
	current_target_stdev  = 0.0;
	target_shift.x	   = 0.0;
	target_shift.y	   = 0.0;
	center_offset.x	   = 0.0;
	center_offset.y	   = 0.0;
	previous_position.x = 0.0;
	previous_position.y = 0.0;
	cursor_end_point.x = 0.0;
	cursor_end_point.y = 0.0;
	center_hold_time   = 0.0;
	center_delay_time  = 0.0;
	outer_hold_time	   = 0.0;
	previous_time_point= 0.0;
	cloud_blank        = false;
	delay_cloud_mode	   = false;
}
/*
void Uncertainty1dBehavior::updateCloud(SimStruct *S) {
	for (int i=0; i<10; i++) {
		cloud[i]->centerX = inputs->cursor.x + slice_points[i].x;
		cloud[i]->centerY = inputs->cursor.y + slice_points[i].y; 
	}
}
*/
void UncertaintyTarget1dBehavior::updateCursorExtent(SimStruct *S){
	if ((params->target_angle == 90.0) || (params->target_angle == 270.0)){
		cursor_extent = inputs->cursor.y - params->center_Y_offset;
	} else if ((params->target_angle == 0.0) || (params->target_angle == 180.0)){
		cursor_extent = inputs->cursor.x - params->center_X_offset;
	} else {
		cursor_extent = 0.0;
	}
}

// Pre-trial initialization and calculations
void UncertaintyTarget1dBehavior::doPreTrial(SimStruct *S) {
	int i;
	double tgt_ang_rad;
	double total_cloud_freq;
	double actual_freq_one;
	double actual_freq_two;
	double actual_freq_three;
	double actual_freq_four;
	double cloud_rand; // random variable to determine which cloud
	delay_cloud_mode = params->use_delay_cloud;
	// Calculate the Shift (Prior Shift)
	current_trial_shift = random->getGaussian(params->shift_mean, params->shift_stdev);

	// The Target Angle in Radians
	tgt_ang_rad = params->target_angle*PI/180;

	center_offset.x = params->center_X_offset;
	center_offset.y = params->center_Y_offset;

	// Set Center Target
	centerTarget->centerX = 0.0+center_offset.x ;
	centerTarget->centerY = 0.0+center_offset.y ;
	centerTarget->width   = params->target_size;
	centerTarget->color   = Target::Color(255, 0, 0);

	// Calculate the Target Shift
	target_shift.x =  current_trial_shift*sin(tgt_ang_rad);
	target_shift.y =  current_trial_shift*-cos(tgt_ang_rad);
	
	// Regarding Cloud Frequency:
	//   Rather than require frequencies to be additive to 1.0 or 100 or something,
	//   we recalculate the frequency in arbitrary units/proportions
	//	 So inputting 1 1 1 1 and 0.25 0.25 0.25 0.25 gives the same frequencies	
	//   Also, as a rule, we use the magnitude of each frequency input
	cloud_rand = random->getDouble();  	// generate a random number between 0 and 1
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
		current_target_stdev = params->cloud_stdev_one;
		// Using Variance One, so check if this trial should be blanked feedback
		cloud_blank = params->cloud_one_blank_mode;
	} else if (cloud_rand <= actual_freq_one+actual_freq_two){
		current_target_stdev = params->cloud_stdev_two;
		cloud_blank = false;
	} else if (cloud_rand <= actual_freq_one+actual_freq_two+actual_freq_three){
		current_target_stdev = params->cloud_stdev_three;
		cloud_blank = false;
	} else if (cloud_rand <= actual_freq_one+actual_freq_two+actual_freq_three+actual_freq_four){
		current_target_stdev = params->cloud_stdev_four;
		cloud_blank = false;
	} else {
		// by default, no feedback is shown
		current_target_stdev = 0.0;
		cloud_blank = true;
	}

	// Set Up The Cloud Points
	for (i=0; i<10; i++) {
			// For 1D clouds, since targets are at 0, 90, 180, 270....
			slice_points[i].x = random->getGaussian(0, current_target_stdev)*abs(sin(tgt_ang_rad)) + center_offset.x +
				/*random->getDouble(-abs(params->cloud_jitter),abs(params->cloud_jitter))*abs(cos(tgt_ang_rad))+*/target_shift.x;
			slice_points[i].y = random->getGaussian(0, current_target_stdev)*abs(cos(tgt_ang_rad)) + center_offset.y +
				/*random->getDouble(-abs(params->cloud_jitter),abs(params->cloud_jitter))*abs(sin(tgt_ang_rad))+*/target_shift.y;
	}


	// Set Up The Targets
	if ((params->target_angle == 90.0) || (params->target_angle == 270.0)){
			outerTarget->centerX = centerTarget->centerX+target_shift.x ;
			outerTarget->centerY = centerTarget->centerY+sin(tgt_ang_rad)*params->movement_length ;
			outerTarget->width   = params->target_size;
			outerTarget->color   = Target::Color(0, 0, 255);

		targetBar->left   = centerTarget->centerX-40;
		targetBar->right  = centerTarget->centerX+40;
		targetBar->top    = centerTarget->centerY+sin(tgt_ang_rad)*params->movement_length + params->target_size/2;
		targetBar->bottom = centerTarget->centerY+sin(tgt_ang_rad)*params->movement_length - params->target_size/2;

		for (i=0; i<10; i++) {
			cloud[i]->left   = slice_points[i].x-params->slice_size*params->target_size/2;
			cloud[i]->right  = slice_points[i].x+params->slice_size*params->target_size/2;
			cloud[i]->top    = centerTarget->centerY+sin(tgt_ang_rad)*params->movement_length + params->target_size/2;
			cloud[i]->bottom = centerTarget->centerY+sin(tgt_ang_rad)*params->movement_length - params->target_size/2;
		}
	} else if ((params->target_angle == 0.0) || (params->target_angle == 180.0)){
			outerTarget->centerY = centerTarget->centerY+target_shift.y ;
			outerTarget->centerX = centerTarget->centerX+cos(tgt_ang_rad)*params->movement_length ;
			outerTarget->width   = params->target_size;
			outerTarget->color   = Target::Color(0, 0, 255);


		targetBar->top     = centerTarget->centerY+40;
		targetBar->bottom  = centerTarget->centerY-40;
		targetBar->left    = centerTarget->centerX+cos(tgt_ang_rad)*params->movement_length - params->target_size/2;
		targetBar->right   = centerTarget->centerX+cos(tgt_ang_rad)*params->movement_length + params->target_size/2;
		for (i=0; i<10; i++) {
			cloud[i]->top     = slice_points[i].y+params->slice_size*params->target_size/2;
			cloud[i]->bottom  = slice_points[i].y-params->slice_size*params->target_size/2;
			cloud[i]->left    = centerTarget->centerX+cos(tgt_ang_rad)*params->movement_length - params->target_size/2;
			cloud[i]->right   = centerTarget->centerX+cos(tgt_ang_rad)*params->movement_length + params->target_size/2;
		}

	} else {
		// by default, place target at top
			outerTarget->centerX = centerTarget->centerX+target_shift.x ;
			outerTarget->centerY = centerTarget->centerY+sin(tgt_ang_rad)*params->movement_length ;
			outerTarget->width   = params->target_size;
			outerTarget->color   = Target::Color(0, 0, 255);

		targetBar->left   = centerTarget->centerX-40;
		targetBar->right  = centerTarget->centerY+40;
		targetBar->top    = centerTarget->centerY+sin(tgt_ang_rad)*params->movement_length + params->target_size/2;
		targetBar->bottom = centerTarget->centerY+sin(tgt_ang_rad)*params->movement_length - params->target_size/2;
		
		for (i=0; i<10; i++) {
			cloud[i]->left   = slice_points[i].x-params->slice_size*params->target_size/2;
			cloud[i]->right  = slice_points[i].x+params->slice_size*params->target_size/2;
			cloud[i]->top    = centerTarget->centerY+sin(tgt_ang_rad)*params->movement_length + params->target_size/2;
			cloud[i]->bottom = centerTarget->centerY+sin(tgt_ang_rad)*params->movement_length - params->target_size/2;
		}

	}
	// Initialize the cloud and cursor extent
//	updateCloud(S);
	updateCursorExtent(S);
	
	// Randomized Timers
	center_hold_time  = random->getDouble(params->center_hold_l, params->center_hold_h);
	center_delay_time = random->getDouble(params->center_delay_l, params->center_delay_h);
	outer_hold_time   = random->getDouble(params->outer_hold_l, params->outer_hold_h);


	feedback_timer->stop();

	// setup the databurst
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('U');
	db->addByte('N');
	db->addByte('T');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)current_trial_shift);
	db->addFloat((float)current_target_stdev);
	db->addFloat((float)params->slice_number);
	// Set Up The Cloud Points
	for (i=0; i<10; i++) {
		db->addFloat((float)slice_points[i].x);
		db->addFloat((float)slice_points[i].y);
	}
    db->start();
}

void UncertaintyTarget1dBehavior::update(SimStruct *S) {
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
				setState(STATE_INCOMPLETE);
			}
			else if (outerTarget->cursorInTarget(inputs->cursor)) {
				outerTarget->color   = Target::Color(255, 0, 0);
				setState(STATE_OUTER_HOLD);
			}
			else if (targetBar->cursorInTarget(inputs->cursor)) {
				outerTarget->color   = Target::Color(255, 0, 0);
				cursor_end_point=inputs->cursor;
				playTone(TONE_ABORT);
				setState(STATE_FAIL);
			}
			break;
		case STATE_OUTER_HOLD:
			if (stateTimer->elapsedTime(S) >= outer_hold_time) {
				cursor_end_point=inputs->cursor;	
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			}
			else if (!outerTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
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
    // assign the current position and time point to previous position
	previous_position = inputs->cursor;
	previous_time_point = stateTimer->elapsedTime(S);
}

void UncertaintyTarget1dBehavior::calculateOutputs(SimStruct *S) {
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
	if (getState() == STATE_CT_ON || 
		getState() == STATE_CENTER_HOLD || 
		getState() == STATE_CENTER_DELAY) {
		outputs->targets[0] = (Target *)centerTarget;
	} else {
		outputs->targets[0] = nullTarget;
	}

	// Target 2 is the outer target
	// Target 1 is the target bar
	if (getState() == STATE_CENTER_DELAY || 
		getState() == STATE_MOVEMENT || 
		getState() == STATE_OUTER_HOLD || 
		getState() == STATE_REWARD || 
		getState() == STATE_FAIL) {

		outputs->targets[2] = (Target *)outerTarget;
		outputs->targets[1] = (Target *)targetBar;
	} 
	else {
		outputs->targets[2] = nullTarget;
		outputs->targets[1] = nullTarget;
	}

	// Targets 3 through 12 Target Cloud
	// If we are in delay mode, draw the cloud during the delay period and during the movement period.
	if (delay_cloud_mode)
	{
		// if in delay or movement (and feedback_window_end is positive), show the slices
		if (params->feedback_window_end >= 0) {
			if (((getState() == STATE_CENTER_DELAY) || (getState() == STATE_MOVEMENT)) &&
				(fabs(cursor_extent) >= params->feedback_window_begin) && 
				(fabs(cursor_extent) <= params->feedback_window_end)) {
				for (i = 0; i<params->slice_number; i++) {
					outputs->targets[3+i] = cloud[i];
				}		
			}
			else {
				for (i = 3; i<13; i++) {
					outputs->targets[i] = nullTarget;
				}
			}
		}
		// if feedback_window_end is negative, only display slices when in CENTER DELAY
		else {
			if (getState() == STATE_CENTER_DELAY) {
				for (i = 0; i<params->slice_number; i++) {
					outputs->targets[3+i] = cloud[i];
				}		
			}
			else {
				for (i = 3; i<13; i++) {
					outputs->targets[i] = nullTarget;
				}
			}
		}
	}
	// Draw the target cloud if we are within a movement and its not a cloud_blank trial
	else {
		if ((getState() == STATE_MOVEMENT) && !cloud_blank) {
		
			// If we are in timer feedback mode (which shows the timed cloud also)
			if (params->use_timed_cloud) {
				// If the feedback location was reached and the timer isn't running yet, start the timer, 
				// and set the cloud position 
				// (this should occur only once per movement since feedback_timer never stops, once started)
				if ((fabs(cursor_extent) >= params->timed_location) && !feedback_timer->isRunning()) {
					feedback_timer->start(S);
				}

				// If the timer is running and we haven't hit the feedback time limit yet,
				// keep drawing the cloud
				if (feedback_timer->isRunning() && (feedback_timer->elapsedTime(S) <= params->timed_duration)){
					// show dots
					for (i = 0; i<params->slice_number; i++) {
						outputs->targets[3+i] = cloud[i];
					}
				}
				else {
					// otherwise don't draw the cloud
					for (i = 3; i<13; i++) {
						outputs->targets[i] = nullTarget;
					}
				}
			}
			// Windowed feedback mode
			// Update the cloud position continuously if not in feedback timer mode (i.e. window mode)
			else {
				// If cursor is actually in the window
				// Show the dots
				if ((fabs(cursor_extent) >= params->feedback_window_begin) && 
					(fabs(cursor_extent) <= params->feedback_window_end)) {
					for (i = 0; i<params->slice_number; i++) {
						outputs->targets[3+i] = cloud[i];
					}
				} 
				// Otherwise hide dots
				else {
					for (i = 3; i<13; i++) {
						outputs->targets[i] = nullTarget;
					}
				}
			}
		
		}
	// Hide the dots otherwise (if not a movement, or it is a blank cloud trial)
		else {
			for (i = 3; i<13; i++) {
				outputs->targets[i] = nullTarget;
			}
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
	// If we are in the movement,
	if (getState() == STATE_MOVEMENT){ 
			// but in the block window, hide it
			if ((fabs(cursor_extent) >= params->block_window_begin) &&
				(fabs(cursor_extent) <= params->block_window_end)) {	
				outputs->position = Point(100000,100000);
			}
			// otherwise, show the cursor
			else {
				outputs->position = inputs->cursor;
			}
		
	}
	// If we are in the outer hold, show the cursor
	else if (getState() == STATE_OUTER_HOLD) {
		outputs->position = inputs->cursor;
	}
	// If in a reward or fail state, show the final shifted endpoint
	else if ((getState() == STATE_REWARD) || (getState() == STATE_FAIL)) {
		// if a completed trial, show the shifted endpoint
		outputs->position = cursor_end_point;
	}
	// In all other cases, show the real cursor position
	else {
		outputs->position = inputs->cursor;
	}
}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


