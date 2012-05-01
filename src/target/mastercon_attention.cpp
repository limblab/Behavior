/* $Id: $
 *
 * Master Control block for behavior: attention
 */

/* 
 * Current Databurst version: 0
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
 * byte         0: uchar => number of bytes to be transmitted
 * byte         1: uchar => databurst version number (in this case one)
 * byte         2: uchar => model version major
 * byte         3: uchar => model version minor
 * bytes   4 to 5: short => model version micro
 * bytes   6 to 9: float => x offset (cm)
 * bytes 10 to 13: float => y offset (cm)
 * byte        14: uchar => trial type (0=visual, 1=proprioceptive, 2=control)
 * byte		   15: uchar => staircase ID
 * byte        16: uchar => training mode (1=yes, 0=no)
 * byte        17: uchar => catch trial (1=yes, 0=no)
 * bytes 18 to 21: float => bump 1 magnitude (N?)
 * bytes 22 to 25: float => bump 2 magnitude (N?)
 * bytes 26 to 29: float => bump angle (rad)
 * bytes 30 to 33: float => bump duration (s)
 * bytes 34 to 37: float => visual target 1 size (cm)
 * bytes 38 to 41: float => visual target 2 size (cm)
 * bytes 42 to 45: float => reward target center x (cm)
 * bytes 46 to 49: float => fail target center x (cm)
 * bytes 50 to 53: float => outer target delay after bump (ms, if -1 outer
 *                          targets visible during center hold)
 * bytes 54 to 57: float => bias force magnitude (N?)
 * bytes 58 to 61: float => bias force direction (rad)
 */

#define S_FUNCTION_NAME mastercon_attention
#define S_FUNCTION_LEVEL 2

// Our task code will be in the databurst
#define TASK_AT 1
#include "words.h"

#include "common_header.cpp"

/* Trial types */
#define VISUAL_TRIAL 0
#define PROPRIO_TRIAL 1
#define CONTROL_TRIAL 2

/*
 * State IDs
 */
#define STATE_PRETRIAL				 0
#define STATE_CENTER_TARGET_ON		 1
#define STATE_CENTER_HOLD_1			 2
#define STATE_VISUAL_1				 3
#define STATE_BUMP_1				 4
#define STATE_INTERBUMP				 5
#define STATE_CENTER_HOLD_2			 6
#define STATE_BUMP_2				 7
#define STATE_INTERVISUAL			 8
#define STATE_VISUAL_2				 9
#define STATE_OUTER_TARGET_DELAY	10
#define STATE_MOVEMENT				11
/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */

#define DATABURST_VERSION ((byte)0x00) 

// This must be custom defined for your behavior
struct LocalParams{
	real_T master_reset;

	// Timing
	real_T center_hold_l;
	real_T center_hold_h;
	real_T interbump_delay_l;
	real_T interbump_delay_h;
	real_T movement_time;
	real_T reward_timeout;
	real_T fail_timeout;
	real_T abort_timeout;
	real_T outer_target_delay;

	// Target parameters
	real_T target_size;
	real_T target_radius;
	real_T visual_target_duration;
	real_T inter_visual_target_delay;

	// Trial types
	real_T percent_visual_trials;
	real_T percent_proprio_trials;
	real_T trial_block_size;
	real_T percent_training_trials;
	real_T percent_catch_trials;
	real_T blocked_directions;
	real_T num_directions;
	real_T first_bump_direction;
	
	// Stimuli
	real_T num_visual_steps;
	real_T visual_min_diameter;
	real_T visual_max_diameter;
	real_T num_proprio_steps;
	real_T bump_mag_min;
	real_T bump_mag_max;	
	real_T bump_duration;
	real_T use_staircases;
	real_T staircase_reset;

	// Bias force
	real_T bias_force_magnitude;
	real_T bias_force_direction;
	real_T bias_force_ramp;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME AttentionBehavior
class AttentionBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	AttentionBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	SquareTarget *centerTarget;
	SquareTarget *biggerFirstResponseTarget;
	SquareTarget *biggerSecondResponseTarget;
	SquareTarget *rewardTarget; 
	SquareTarget *failTarget;

	CircleTarget *visualTarget1;
	CircleTarget *visualTarget2;

	real_T center_hold;
	real_T interbump_delay;

    Staircase *proprioStairs[16];
	Staircase *visualStairs[2];
	int staircase_id;
	
	int trial_type;	/* VISUAL_TRIAL, PROPRIO_TRIAL, CONTROL_TRIAL */
	int trial_counter;
	int training_mode;
	int catch_trial;
	int bigger_first;

	int visual_color;
	int proprio_color;
	int control_color;
	int response_color;

	int debug_var;
	
	real_T standard_target_radius;
	real_T test_target_radius;
	real_T visual_step_size;
	real_T bump_direction;
	real_T standard_bump_magnitude;
	real_T test_bump_magnitude;
	real_T proprio_step_size;
	real_T bump_1_magnitude;
	real_T bump_2_magnitude;

	TrapBumpGenerator *bump1;
	TrapBumpGenerator *bump2;
	TrapBumpGenerator *bias_force;

	LocalParams *params;
	real_T last_staircase_reset;

	// any helper functions you need
	void doPreTrial(SimStruct *S);
	void setupProprioStaircase(int i, double angle, double step, double fl, double bl);
	void setupVisualStaircase(int i, double angle, double step, double fl, double bl);
};

AttentionBehavior::AttentionBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(34);
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,							 0);
	this->bindParamId(&params->center_hold_l,							 1);
	this->bindParamId(&params->center_hold_h,							 2);
	this->bindParamId(&params->interbump_delay_l,						 3);
	this->bindParamId(&params->interbump_delay_h,						 4);
	this->bindParamId(&params->movement_time,							 5);
	this->bindParamId(&params->reward_timeout,							 6);
	this->bindParamId(&params->fail_timeout,							 7);
    this->bindParamId(&params->abort_timeout,							 8);
	this->bindParamId(&params->outer_target_delay,						 9);
	this->bindParamId(&params->target_size,								10);
	this->bindParamId(&params->target_radius,							11);
	this->bindParamId(&params->visual_target_duration,					12);
	this->bindParamId(&params->inter_visual_target_delay,				13);
	this->bindParamId(&params->percent_visual_trials,					14);
	this->bindParamId(&params->percent_proprio_trials,					15);
	this->bindParamId(&params->trial_block_size,						16);
	this->bindParamId(&params->percent_training_trials,					17);
	this->bindParamId(&params->percent_catch_trials,					18);
	this->bindParamId(&params->blocked_directions,						19);
	this->bindParamId(&params->num_directions,							20);
	this->bindParamId(&params->first_bump_direction,					21);
	this->bindParamId(&params->num_visual_steps,						22);
	this->bindParamId(&params->visual_min_diameter,						23);
	this->bindParamId(&params->visual_max_diameter,						24);	
	this->bindParamId(&params->num_proprio_steps,						25);
	this->bindParamId(&params->bump_mag_min,							26);
	this->bindParamId(&params->bump_mag_max,							27);
	this->bindParamId(&params->bump_duration,							28);
	this->bindParamId(&params->use_staircases,							29);
	this->bindParamId(&params->staircase_reset,							30);
	this->bindParamId(&params->bias_force_magnitude,					31);
	this->bindParamId(&params->bias_force_direction,					32);
	this->bindParamId(&params->bias_force_ramp,							33);				
    
    // default parameters:
    // 0 .5 1 .5 1 10 1 1 1 1 3 10 1 1 35 35 10 20 20 1 2 1.57 4 5 7 4 .01 .03 .2 1 0 .0001 0 .2
    
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
	
	debug_var = -1;
	last_staircase_reset = -1; // force a staircase reset of first trial

	visual_color = Target::Color(50,50,255);
	proprio_color = Target::Color(255,180,0);
	control_color = Target::Color(50,200,50);
	response_color = Target::Color(255,0,0);

	centerTarget = new SquareTarget();

	visualTarget1 = new CircleTarget();
	visualTarget2 = new CircleTarget();

	biggerFirstResponseTarget = new SquareTarget(); 
	biggerSecondResponseTarget = new SquareTarget(); 

	rewardTarget = new SquareTarget(); 
	failTarget = new SquareTarget();

	visualTarget1->color = visual_color;
	visualTarget2->color = visual_color;

	biggerFirstResponseTarget->color = response_color;
	biggerSecondResponseTarget->color = response_color;

	for (i=0; i<16; i++) {
		proprioStairs[i] = new Staircase();		
	}
		
	visualStairs[0] = new Staircase();
	visualStairs[1] = new Staircase();

	staircase_id = -1;
	trial_type = 0;
	trial_counter = 0;
	training_mode = false;
	catch_trial = false;

	standard_bump_magnitude = 0.0;
	test_bump_magnitude = 0.0;
	bump_1_magnitude = 0.0;
	bump_2_magnitude = 0.0;
	bump_direction = 0.0;

	bump1 = new TrapBumpGenerator();
	bump2 = new TrapBumpGenerator();
	bias_force = new TrapBumpGenerator();
}

void AttentionBehavior::setupProprioStaircase(
	int i, double start_magnitude, double step, double fl, double bl) 
{	
	proprioStairs[i]->setStartValue( start_magnitude );
	proprioStairs[i]->setRatio( 3 );
	proprioStairs[i]->setStep( step );
	proprioStairs[i]->setUseForwardLimit( 1 );
	proprioStairs[i]->setUseBackwardLimit( 1 );
	proprioStairs[i]->setForwardLimit( fl );
	proprioStairs[i]->setBackwardLimit( bl );
	proprioStairs[i]->restart();
}

void AttentionBehavior::setupVisualStaircase(
	int i, double start_size, double step, double fl, double bl) 
{	
	visualStairs[i]->setStartValue( start_size );
	visualStairs[i]->setRatio( 3 );
	visualStairs[i]->setStep( step );
	visualStairs[i]->setUseForwardLimit( 1 );
	visualStairs[i]->setUseBackwardLimit( 1 );
	visualStairs[i]->setForwardLimit( fl );
	visualStairs[i]->setBackwardLimit( bl );
	visualStairs[i]->restart();
}


void AttentionBehavior::doPreTrial(SimStruct *S) {
	int i;
	real_T temp_real;

	center_hold = this->random->getDouble(params->center_hold_l, params->center_hold_h);
	interbump_delay = this->random->getDouble(params->interbump_delay_l, params->interbump_delay_h);
	
	standard_bump_magnitude = (params->bump_mag_max + params->bump_mag_min)/2;
	standard_target_radius = ((params->visual_min_diameter + params->visual_max_diameter)/2)/2;

	visual_step_size = (params->visual_max_diameter - params->visual_min_diameter)/(params->num_visual_steps);
	proprio_step_size = (params->bump_mag_max - params->bump_mag_min)/(params->num_proprio_steps);

	if (last_staircase_reset != params->staircase_reset) {
		// load parameters to the staircases and reset them.
		last_staircase_reset = params->staircase_reset;
		for (i=0 ; i < params->num_directions ; i++){
			setupProprioStaircase(i*2, params->bump_mag_min, proprio_step_size, standard_bump_magnitude, params->bump_mag_min);
			setupProprioStaircase(i*2+1, params->bump_mag_max, -proprio_step_size, standard_bump_magnitude, params->bump_mag_max);
		};
		setupVisualStaircase(0, params->visual_min_diameter, visual_step_size, 2*standard_target_radius, params->visual_min_diameter);
		setupVisualStaircase(1, params->visual_max_diameter, -visual_step_size, 2*standard_target_radius, params->visual_max_diameter);
	}

	trial_counter++;
	if (trial_counter > params->trial_block_size)
		trial_counter = 1;

	// Select a trial type
	if (params->trial_block_size > 1){
		if ((100*trial_counter/params->trial_block_size) <= params->percent_visual_trials){
			trial_type = VISUAL_TRIAL;
		} else if ((100*trial_counter/params->trial_block_size) <= (params->percent_visual_trials + params->percent_proprio_trials)){
			trial_type = PROPRIO_TRIAL;
		} else {
			trial_type = CONTROL_TRIAL;
		}
	} else {
		temp_real = random->getDouble(0,100);
		if (temp_real <= params->percent_visual_trials){
			trial_type = VISUAL_TRIAL;
		} else if (temp_real <= (params->percent_visual_trials + params->percent_proprio_trials)){
			trial_type = PROPRIO_TRIAL;
		} else {
			trial_type = CONTROL_TRIAL; 
		}
	}
		
	catch_trial = (this->random->getDouble(0,100) < params->percent_catch_trials) ? 1 : 0;
	training_mode = (this->random->getDouble(0,100) < params->percent_training_trials) ? 1 : 0;
	bigger_first = this->random->getBool();
	
	// Set up target locations, etc.
	centerTarget->width = params->target_size;
	visualTarget1->centerY = params->target_radius;
	visualTarget2->centerY = params->target_radius;

	biggerFirstResponseTarget->width = params->target_size;
	biggerFirstResponseTarget->centerX = -params->target_radius;
	biggerFirstResponseTarget->centerY = 0;

	biggerSecondResponseTarget->width = params->target_size;
	biggerSecondResponseTarget->centerX = params->target_radius;
	biggerSecondResponseTarget->centerY = 0;
	
	// Pick the bump direction
	if (!params->blocked_directions || trial_counter==1){
        if (params->num_directions>0){
            i = random->getInteger(0,(int)(params->num_directions-1));
            bump_direction = fmod(i * 2 * PI/params->num_directions + params->first_bump_direction,2*PI);
        } else {
            bump_direction = random->getDouble(0,2*PI);
        }
    }
		
	bump_1_magnitude = standard_bump_magnitude;
	bump_2_magnitude = standard_bump_magnitude;

	if (trial_type == VISUAL_TRIAL) {

		centerTarget->color = visual_color;
		biggerFirstResponseTarget->color = visual_color;
		biggerSecondResponseTarget->color = visual_color;
		visualTarget1->color = visual_color;
		visualTarget2->color = visual_color;		

		if (params->use_staircases){			
			staircase_id = random->getBool();
			test_target_radius = (visualStairs[staircase_id]->getValue())/2;
		} else {
			i = random->getInteger(0,(int)(params->num_visual_steps-1));
			test_target_radius = (params->visual_min_diameter + i*(params->visual_max_diameter - params->visual_min_diameter)/(params->num_visual_steps-1))/2;
		}

		if (bigger_first){
			visualTarget1->radius = standard_target_radius > test_target_radius ? standard_target_radius : test_target_radius;
			visualTarget2->radius = standard_target_radius > test_target_radius ? test_target_radius : standard_target_radius;
			rewardTarget = biggerFirstResponseTarget;
			failTarget = biggerSecondResponseTarget;
		} else {			
			visualTarget1->radius = standard_target_radius > test_target_radius ? test_target_radius : standard_target_radius;
			visualTarget2->radius = standard_target_radius > test_target_radius ? standard_target_radius : test_target_radius;
			rewardTarget = biggerSecondResponseTarget;
			failTarget = biggerFirstResponseTarget;
		}

	} else if ( trial_type == PROPRIO_TRIAL ) {	

		centerTarget->color = proprio_color;
		biggerFirstResponseTarget->color = proprio_color;
		biggerSecondResponseTarget->color = proprio_color;
		visualTarget1->color = 0;
		visualTarget2->color = 0;

		if (params->use_staircases){
			i = random->getInteger(0,(int)(params->num_directions-1));
			staircase_id = i*2 + random->getBool();
			test_bump_magnitude = proprioStairs[staircase_id]->getValue();
		} else {			
			i = random->getInteger(0,(int)(params->num_proprio_steps-1));
			test_bump_magnitude = params->bump_mag_min + i*(params->bump_mag_max - params->bump_mag_min)/(params->num_proprio_steps-1);
		}

		if (bigger_first){		
			bump_1_magnitude = test_bump_magnitude > standard_bump_magnitude ? test_bump_magnitude : standard_bump_magnitude;
			bump_2_magnitude = test_bump_magnitude > standard_bump_magnitude ? standard_bump_magnitude : test_bump_magnitude;
			rewardTarget = biggerFirstResponseTarget;
			failTarget = biggerSecondResponseTarget;
		} else {									
			bump_1_magnitude = test_bump_magnitude > standard_bump_magnitude ? standard_bump_magnitude : test_bump_magnitude;
			bump_2_magnitude = test_bump_magnitude > standard_bump_magnitude ? test_bump_magnitude : standard_bump_magnitude;
			rewardTarget = biggerSecondResponseTarget;
			failTarget = biggerFirstResponseTarget;
		}

	} else {
		centerTarget->color = control_color;
		biggerFirstResponseTarget->color = 0;
		biggerSecondResponseTarget->color = 0;
		visualTarget1->color = 0;
		visualTarget2->color = 0;
		bump_1_magnitude = standard_bump_magnitude;
		bump_2_magnitude = standard_bump_magnitude;
	}	

	// Set up the bumps	
	bump1->hold_duration = params->bump_duration;
	bump1->peak_magnitude = bump_1_magnitude;
	bump1->rise_time = 0;
	if (!catch_trial){
		bump1->direction = bump_direction;
	} else {
		if (params->num_directions>0){
            i = random->getInteger(0,(int)(params->num_directions-1));
            bump1->direction = fmod(i * 2 * PI/params->num_directions + params->first_bump_direction,2*PI);
		} else {
			bump1->direction = random->getDouble(0,2*PI);
		}
	}

	bump2->hold_duration = params->bump_duration;
	bump2->peak_magnitude = bump_2_magnitude;
	bump2->rise_time = 0;
	bump2->direction = bump_direction;
				
	bias_force->hold_duration = center_hold;
	bias_force->peak_magnitude = params->bias_force_magnitude;
	bias_force->rise_time = params->bias_force_ramp;
	bias_force->direction = params->bias_force_direction;

	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addFloat((float)(inputs->offsets.x));
	db->addFloat((float)(inputs->offsets.y));
	db->addByte(trial_type);
	db->addByte(staircase_id);
	db->addByte(training_mode);
	db->addByte(catch_trial);
	db->addFloat((float)(bump_1_magnitude));
	db->addFloat((float)(bump_2_magnitude));
	db->addFloat((float)(bump_direction));
	db->addFloat((float)(params->bump_duration));
	db->addFloat((float)(visualTarget1->radius));
	db->addFloat((float)(visualTarget2->radius));
	db->addFloat((float)(rewardTarget->centerX));
	db->addFloat((float)(failTarget->centerX));
	db->addFloat((float)(params->outer_target_delay));
	db->addFloat((float)(params->bias_force_magnitude));
	db->addFloat((float)(params->bias_force_direction));
	db->start();
}

void AttentionBehavior::update(SimStruct *S) {
	//int i;
	// State machine
	switch (this->getState()) {
		case STATE_PRETRIAL:
            updateParameters(S);
            doPreTrial(S);
            setState(STATE_DATA_BLOCK);
			break;
		case STATE_DATA_BLOCK:
			if (db->isDone()) {
				setState(STATE_CENTER_TARGET_ON);
			}
			break;
		case STATE_CENTER_TARGET_ON:
			/* first target on */
			if (centerTarget->cursorInTarget(inputs->cursor)) {
				bias_force->start(S);
				setState(STATE_CENTER_HOLD_1);
			}
			break;
		case STATE_CENTER_HOLD_1:
			if (stateTimer->elapsedTime(S) > center_hold && trial_type != VISUAL_TRIAL) {
				bump1->start(S);
				setState(STATE_BUMP_1);
			} else if (stateTimer->elapsedTime(S) > center_hold && trial_type == VISUAL_TRIAL) {
				setState(STATE_VISUAL_1);
			} else if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			break;
		case STATE_VISUAL_1:
			if (stateTimer->elapsedTime(S) > params->visual_target_duration) {
				bump1->start(S);
				setState(STATE_BUMP_1);
			} else if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			break;
		case STATE_BUMP_1:
			if (stateTimer->elapsedTime(S) > params->bump_duration) {
				if (catch_trial){
					setState(STATE_INCOMPLETE);
				} else if (trial_type == VISUAL_TRIAL){
					setState(STATE_INTERVISUAL);
				} else if (trial_type == PROPRIO_TRIAL){
					setState(STATE_INTERBUMP);
				} else {
					playTone(TONE_REWARD);
					setState(STATE_REWARD);
				}
			}
			break;
		case STATE_INTERBUMP:
			if (stateTimer->elapsedTime(S) > interbump_delay && centerTarget->cursorInTarget(inputs->cursor)){
				bias_force->start(S);
				setState(STATE_CENTER_HOLD_2);
			}
			break;
		case STATE_CENTER_HOLD_2:
			if (stateTimer->elapsedTime(S) > center_hold) {
				bump2->start(S);
				setState(STATE_BUMP_2);			
			} else if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			break; 
		case STATE_BUMP_2:
			if (stateTimer->elapsedTime(S) > params->bump_duration) {
				setState(STATE_OUTER_TARGET_DELAY);				
			}
			break;
		case STATE_INTERVISUAL:
			if (stateTimer->elapsedTime(S) + params->bump_duration > params->inter_visual_target_delay &&
				centerTarget->cursorInTarget(inputs->cursor)){
					setState(STATE_VISUAL_2);
			}
			break;
		case STATE_VISUAL_2:
			if (stateTimer->elapsedTime(S) > params->visual_target_duration){
				setState(STATE_OUTER_TARGET_DELAY);
			} else if (!centerTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}
			break;
		case STATE_OUTER_TARGET_DELAY:
			if (stateTimer->elapsedTime(S) > params->outer_target_delay){
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_MOVEMENT:
			if (rewardTarget->cursorInTarget(inputs->cursor)){
				if (params->use_staircases){
					if (trial_type == VISUAL_TRIAL){
						visualStairs[staircase_id]->stepForward();						
					} else if (trial_type == PROPRIO_TRIAL){
						proprioStairs[staircase_id]->stepForward();
					}
				}			
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			} else if (failTarget->cursorInTarget(inputs->cursor)){
				if (params->use_staircases){
					if (trial_type == VISUAL_TRIAL){
						visualStairs[staircase_id]->stepBackward();
					} else if (trial_type == PROPRIO_TRIAL){
						proprioStairs[staircase_id]->stepBackward();
					}
				}
				playTone(TONE_ABORT);
				setState(STATE_FAIL);
			} else if (stateTimer->elapsedTime(S) > params->movement_time){
				setState(STATE_INCOMPLETE);
			}
			break;
		case STATE_ABORT:
			this->bump1->stop();
			this->bump2->stop();
			this->bias_force->stop();			
			if (stateTimer->elapsedTime(S) > params->abort_timeout) {
				setState(STATE_PRETRIAL);
			}
			break;
        case STATE_REWARD:
			this->bump1->stop();
			this->bump2->stop();
			this->bias_force->stop();			
			if (stateTimer->elapsedTime(S) > params->reward_timeout) {
				setState(STATE_PRETRIAL);
			}
			break;
		case STATE_FAIL:
			this->bump1->stop();
			this->bump2->stop();
			this->bias_force->stop();			
			if (stateTimer->elapsedTime(S) > params->fail_timeout) {
				setState(STATE_PRETRIAL);
			}
			break;
        case STATE_INCOMPLETE:
			this->bump1->stop();
			this->bump2->stop();
			this->bias_force->stop();
			if (stateTimer->elapsedTime(S) > params->reward_timeout) {
				setState(STATE_PRETRIAL);
			}
			break;
		default:
			setState(STATE_PRETRIAL);
	}
}

void AttentionBehavior::calculateOutputs(SimStruct *S) {

	Point bf;

	/* force (0) */
	outputs->force = inputs->force;

	if (bias_force->isRunning(S)){
		outputs->force += bias_force->getBumpForce(S);
	}

	if (bump1->isRunning(S)) {
		outputs->force += bump1->getBumpForce(S);		
	} else if (bump2->isRunning(S)){
		outputs->force += bump2->getBumpForce(S);
	} 

    /* status (1) */
	outputs->status[0] = getState();
	outputs->status[1] = trialCounter->successes;
	outputs->status[2] = trialCounter->failures;
	outputs->status[3] = trialCounter->aborts;	
	outputs->status[4] = trialCounter->incompletes;
	/*outputs->status[4] = debug_var;*/
    
	/* word(2) */
	if (db->isRunning()) {
		outputs->word = db->getByte();
	} else if (isNewState()) {
		switch (getState()) {
			case STATE_PRETRIAL:
				outputs->word = WORD_START_TRIAL;
				break;
			case STATE_CENTER_TARGET_ON:
				outputs->word = WORD_OT_ON(0);
				break;
			case STATE_CENTER_HOLD_1:
				outputs->word = WORD_CENTER_TARGET_HOLD;
				break;
			case STATE_VISUAL_1:
				outputs->word = WORD_OT_ON(1);
				break;
			case STATE_BUMP_1:
				outputs->word = WORD_BUMP(1);
				break;
			case STATE_CENTER_HOLD_2:
				outputs->word = WORD_CENTER_TARGET_HOLD;
				break;
			case STATE_VISUAL_2:
				outputs->word = WORD_OT_ON(2);
				break;
			case STATE_BUMP_2:
				outputs->word = WORD_BUMP(2);
				break;
			case STATE_MOVEMENT:
				outputs->word = WORD_OT_ON(3);
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
	// Center Target
	if (getState() == STATE_CENTER_TARGET_ON || 
	    getState() == STATE_CENTER_HOLD_1 || 
        getState() == STATE_INTERBUMP ||
        getState() == STATE_CENTER_HOLD_2 ||
		getState() == STATE_BUMP_1 ||
		getState() == STATE_BUMP_2 ||
		getState() == STATE_INTERVISUAL) 
	{
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = nullTarget;
	} else if (getState() == STATE_VISUAL_1) {
		outputs->targets[0] = (Target *)visualTarget1;
		outputs->targets[1] = (Target *)centerTarget;
	} else if (getState() == STATE_VISUAL_2) {
		outputs->targets[0] = (Target *)visualTarget2;
		outputs->targets[1] = (Target *)centerTarget;
	} else if (getState() == STATE_MOVEMENT) {
		outputs->targets[0] = (Target *)rewardTarget;
		if (!training_mode) {
			outputs->targets[1] = (Target *)failTarget;
		} else {
			outputs->targets[1] = nullTarget;
		}
	} else {
		outputs->targets[0] = nullTarget;
		outputs->targets[1] = nullTarget;
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
    if (getState() == STATE_BUMP_1 || getState() == STATE_INTERBUMP || 
		getState() == STATE_BUMP_2 )
    {
        outputs->position = Point(1E6, 1E6);
    } else {
    	outputs->position = inputs->cursor;
    } 

}

/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


