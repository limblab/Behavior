/* $Id: $
 *
 * Master Control block for behavior: resist perturbations
 */

#define DATABURST_VERSION ((byte)0x02) 
/* 
 * Current Databurst version: 2 
 *
 * Note that all databursts are encoded half a byte at a time as a word who's 
 * high order bits are all 1 and who's low order bits represent the half byte to
 * be transmitted.  Low order bits are transmitted first.  Thus to transmit the
 * two bytes 0xCF 0x07, one would send 0xFF 0xFC 0xF7 0xF0.
 *
 * Databurst version descriptions
 * ==============================
 *** * Version 2 (0x02)
 * ----------------
 * byte         0: uchar    => number of bytes to be transmitted
 * byte         1: uchar    => databurst version number (in this case zero)
 * byte         2: uchar    => model version major
 * byte         3: uchar    => model version minor
 * bytes   4 to 5: short    => model version micro
 * bytes   6 to 9: float    => x offset (cm)
 * bytes 10 to 13: float    => y offset (cm)
 * bytes 14 to 17: float    => trial force direction (rad)
 * bytes 18 to 21: float    => trial force amplitude (N)
 * bytes 22 to 25: float    => perturbation type (0 = sin, 1 = triangle)
 * bytes 26 to 29: float    => perturbation hold target radius (cm)
 * byte        30: int      => brain control (if 1: yes)
 * byte        31: int      => force visual feedback (if 1: yes)
 * byte        32: int      => bump trial
 * bytes 33 to 36: float    => bump magnitude or velocity (N or cm/s)
 * bytes 37 to 40: float    => bump direction (rad)
 * bytes 41 to 44: float    => bump_duration (s)
 * byte        45: int      => force bump (1 if force, 0 if velocity)
 * bytes 46 to 49: float    => trial force frequency (Hz)     
 * bytes 50 to 53: float    => stiffness (N/cm)    
 * bytes 54 to 57: float    => damping (N/cm/s)    
 * bytes 58 to 61: float    => center hold target radius (cm) 
 * byte        62: int    => early bump
 *
 ** * Version 1 (0x01)
 * ----------------
 * byte         0: uchar    => number of bytes to be transmitted
 * byte         1: uchar    => databurst version number (in this case zero)
 * byte         2: uchar    => model version major
 * byte         3: uchar    => model version minor
 * bytes   4 to 5: short    => model version micro
 * bytes   6 to 9: float    => x offset (cm)
 * bytes 10 to 13: float    => y offset (cm)
 * bytes 14 to 17: float    => trial force direction (rad)
 * bytes 18 to 21: float    => trial force amplitude (N)
 * bytes 22 to 25: float    => perturbation type (0 = sin, 1 = triangle)
 * bytes 26 to 29: float    => target radius (cm)
 * byte        30: int      => brain control (if 1: yes)
 * byte        31: int      => force visual feedback (if 1: yes)
 * byte        32: int      => bump trial
 * bytes 33 to 36: float    => bump magnitude or velocity (N or cm/s)
 * bytes 37 to 40: float    => bump direction (rad)
 * bytes 41 to 44: float    => bump_duration (s)
 * byte        45: int      => force bump (1 if force, 0 if velocity)
 * bytes 46 to 49: float    => trial force frequency (Hz)     
 * bytes 50 to 53: float    => stiffness (N/cm)    
 * bytes 54 to 57: float    => damping (N/cm/s)     
 *
 *** * Version 0 (0x00)
 * ----------------
 * byte         0: uchar    => number of bytes to be transmitted
 * byte         1: uchar    => databurst version number (in this case zero)
 * byte         2: uchar    => model version major
 * byte         3: uchar    => model version minor
 * bytes   4 to 5: short    => model version micro
 * bytes   6 to 9: float    => x offset (cm)
 * bytes 10 to 13: float    => y offset (cm)
 * bytes 14 to 17: float    => trial force direction (rad)
 * bytes 18 to 21: float    => trial force amplitude (N)
 * bytes 22 to 25: float    => perturbation type (0 = sin, 1 = triangle)
 * bytes 26 to 29: float    => target radius (cm)
 * byte        30: int      => brain control (if 1: yes)
 * byte        31: int      => force visual feedback (if 1: yes)
 * byte        32: int      => bump trial
 * bytes 33 to 36: float    => bump magnitude or velocity (N or cm/s)
 * bytes 37 to 40: float    => bump direction (rad)
 * bytes 41 to 44: float    => bump_duration (s)
 * byte        45: int      => force bump (1 if force, 0 if velocity)
 * bytes 46 to 49: float    => trial force frequency (Hz)   
 */

#define S_FUNCTION_NAME mastercon_resist_perturbations
#define S_FUNCTION_LEVEL 2

// Our task code will be in the databurst
#define TASK_DB_DEFINED 1
#include "words.h"

#include "common_header.cpp"

/*
 * State IDs
 */
#define STATE_PRETRIAL				 0
#define STATE_WAIT_FOR_DB            1
#define STATE_CENTER_TARGET_ON		 2
#define STATE_CT_HOLD				 3
#define STATE_PERTURBATION           4
#define STATE_BUMP                   5
#define STATE_START_RECORDING        6
#define STATE_STOP_RECORDING         7

/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */

// This must be custom defined for your behavior
struct LocalParams{
	real_T master_reset;

	// Timing	
    real_T center_hold_low;
    real_T center_hold_high;
    real_T perturbation_hold_low;
    real_T perturbation_hold_high;
	real_T reward_wait;
	real_T abort_wait;
    real_T fail_wait;

    // Cursor
    real_T brain_control;
    
	// Targets
	real_T target_radius;
	real_T force_visual_feedback;
        
    // Perturbations
    real_T force_amplitude_low;
    real_T force_amplitude_high;
    real_T num_force_amplitudes;
    real_T force_frequency_low;  
    real_T force_frequency_high;
    real_T num_force_frequencies;
    real_T force_block_size;    
    real_T first_force_direction;
    real_T num_force_directions;
    real_T block_force_directions;
    real_T toggle_reset_block;
    real_T perturbation_type;
            
    // Velocity controller parameters
    real_T vel_filt;
    real_T pos_filt;  
    
    // Cerebus recording stuff
    real_T record;
    real_T record_for_x_mins;            
    
    // Bumps
    real_T num_bump_directions;
    real_T first_bump_direction;
    real_T percent_bump_trials;
    real_T bump_magnitude;
    real_T bump_duration;
    real_T bump_velocity;
    real_T P_gain_vel;
    real_T P_gain_pos;
    real_T force_bump;
    
    // Stabilizing field
    real_T stiffness;
    real_T damping;
    
    // More target stuff
    real_T center_hold_target_radius;
    
    // More bump stuff
    real_T early_bumps;
    real_T late_bumps;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME ResistPerturbations
class ResistPerturbations : public RobotBehavior {
public:
	// You must implement these three public methods
	ResistPerturbations(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables    
	CircleTarget *centerTarget;	
    CircleTarget *holdTarget;
	CircleTarget *forceFeedback[5];	   
    CircleTarget *lowerArm[5];
    CircleTarget *upperArm[5];    
    
	LocalParams *params;	

	real_T center_hold_time;
    real_T perturbation_hold_time;
    
    real_T trial_force_amplitude;
	real_T trial_force_direction;
    real_T trial_force_frequency;
       
    Point cursor_velocity;
    Point cursor_velocity_old;
    
    Point cursor_position;
    Point cursor_position_old;
    Point force;        
    
    Point shoulder_pos;
    Point elbow_pos;
    
    int trial_counter;   
    int block_counter;
    int old_toggle_reset_block; 
    real_T debug_var;  
    int bump_trial;
    real_T bump_direction;
    int last_trial_reward;
    
    int frequency_order[16];
    real_T frequencies[16];
    
    int trigger_bump;    
    real_T old_force_magnitude;
    
    TrapBumpGenerator *bump;
    TrapBumpGenerator *infinite_bump;
    PDBumpGenerator *PDbump;
    
    int early_bump;
    
	// any helper functions you need
	void doPreTrial(SimStruct *S);    
    Timer *recordingTimer;   
    Timer *perturbationTimer;
              
};

ResistPerturbations::ResistPerturbations(SimStruct *S) : RobotBehavior() {

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(41);
	// Identify each bound variable 
    this->bindParamId(&params->master_reset,                            0);
    
	this->bindParamId(&params->center_hold_low,                         1);
	this->bindParamId(&params->center_hold_high,                        2);
	this->bindParamId(&params->perturbation_hold_low,                   3);
    this->bindParamId(&params->perturbation_hold_high,                  4);
	this->bindParamId(&params->reward_wait,                             5);
	this->bindParamId(&params->abort_wait,								6);
	this->bindParamId(&params->fail_wait,								7);
    
    this->bindParamId(&params->brain_control,                           8);
    
    this->bindParamId(&params->target_radius,                           9);
    this->bindParamId(&params->force_visual_feedback,                   10);
    
    this->bindParamId(&params->force_amplitude_low,                     11);
    this->bindParamId(&params->force_amplitude_high,                    12);
    this->bindParamId(&params->num_force_amplitudes,                    13);
    this->bindParamId(&params->force_frequency_low,                     14);
    this->bindParamId(&params->force_frequency_high,                    15);
    this->bindParamId(&params->num_force_frequencies,                   16);
    this->bindParamId(&params->force_block_size,                        17);
    this->bindParamId(&params->first_force_direction,                   18);
    this->bindParamId(&params->num_force_directions,                    19);
    this->bindParamId(&params->block_force_directions,                  20);
    this->bindParamId(&params->toggle_reset_block,                      21);
    this->bindParamId(&params->perturbation_type,                       22);
    
    this->bindParamId(&params->vel_filt,                                23);
    this->bindParamId(&params->pos_filt,                                24);
    
    this->bindParamId(&params->record,                                  25);
    this->bindParamId(&params->record_for_x_mins,                       26);
    
    this->bindParamId(&params->num_bump_directions,                     27);
    this->bindParamId(&params->first_bump_direction,                    28);
    this->bindParamId(&params->percent_bump_trials,                     29);
    this->bindParamId(&params->bump_magnitude,                          30);
    this->bindParamId(&params->bump_duration,                           31);    
    this->bindParamId(&params->bump_velocity,                           32);
    this->bindParamId(&params->P_gain_vel,                              33);
    this->bindParamId(&params->P_gain_pos,                              34);
    this->bindParamId(&params->force_bump,                              35);
    
    this->bindParamId(&params->stiffness,                               36);
    this->bindParamId(&params->damping,                                 37);
    
    this->bindParamId(&params->center_hold_target_radius,               38);
    
    this->bindParamId(&params->early_bumps,                             39);
    this->bindParamId(&params->late_bumps,                              40);
  
    // default parameters:
    // 0   1 2 2 5 1 1 1   0   2 1   .5 1.5 3 .1 1 3 5 0 4 0 0 0   1 1   0 0   8 0 20 2 .2 5 1 0 1   0 0   1   1 1
    
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
  
	centerTarget = new CircleTarget();
	centerTarget->color = Target::Color(255,0,0);	
    holdTarget = new CircleTarget();
	holdTarget->color = Target::Color(255,0,0);	    
    
    for (int i=0; i<5; i++) {
		lowerArm[i] = new CircleTarget(0,0,.3,0);
        lowerArm[i]->color = Target::Color(80,80,80);
        upperArm[i] = new CircleTarget(0,0,.3,0);
        upperArm[i]->color = Target::Color(80,80,80);
        forceFeedback[i] = new CircleTarget(0,0,.3,0);
        forceFeedback[i]->color = Target::Color(255,255,255);
	}
    
    for (int i=0; i<16; i++){
        frequency_order[i] = -1;
        frequencies[i] = 0;
    }

    center_hold_time = 0.0;
    perturbation_hold_time = 1.0;
    
    trial_force_amplitude = 0.0;
	trial_force_direction = 0.0;
    trial_force_frequency = 1.0;
    
    cursor_position = Point(0,0);
    cursor_position_old = Point(0,0);
    cursor_velocity = Point(0,0);
    cursor_velocity_old = Point(0,0);
    force = Point(0,0);
    
    shoulder_pos = Point(0,0);
    elbow_pos = Point(0,0);
        
    recordingTimer = new Timer();
    perturbationTimer = new Timer();
    
    trial_counter = 10000;
    block_counter = 10000;
    old_toggle_reset_block = 1;
    debug_var = 0.0;
    
    trigger_bump = 0;
    old_force_magnitude = 0;
    bump_trial = 0;
    bump_direction = 0;
    bump = new TrapBumpGenerator();
    infinite_bump = new TrapBumpGenerator();
    PDbump = new PDBumpGenerator();     
    last_trial_reward = 1;
    
    early_bump = 0;
}

void ResistPerturbations::doPreTrial(SimStruct *S) {
    double tmp_sort[16];
    double tmp_d;
    int tmp;
    int number_of_blocks;
    int rand_i;
    real_T rand_d;
    
    number_of_blocks = params->num_force_frequencies;

	centerTarget->radius = params->target_radius;
    holdTarget->radius = params->center_hold_target_radius;
      
    if (last_trial_reward==1){
        trial_counter++;
        if (trial_counter >= params->force_block_size){
            trial_counter = 0;
            block_counter++;
        }
       
        rand_i = random->getInteger(0,params->num_force_amplitudes-1);  
        rand_d = random->getDouble(0,1);
        if (params->num_force_amplitudes > 1){
            trial_force_amplitude = params->force_amplitude_low + rand_i*(params->force_amplitude_high -
                    params->force_amplitude_low)/(params->num_force_amplitudes-1);
        } else if (params->num_force_amplitudes == 1){
            trial_force_amplitude = params->force_amplitude_low;
        } else {
            trial_force_amplitude = params->force_amplitude_low + rand_d*(params->force_amplitude_high -
                    params->force_amplitude_low);
        }

        rand_i = random->getInteger(0,params->num_force_directions-1);
        rand_d = random->getDouble(0,2*PI);
        if (params->num_force_directions > 1){
            trial_force_direction = params->first_force_direction + 
                    rand_i*(2*PI)/(params->num_force_directions);
        } else if (params->num_force_directions == 1){
            trial_force_direction = params->first_force_direction;
        } else {
            trial_force_direction = rand_d;
        }

        if (block_counter >= number_of_blocks || old_toggle_reset_block != params->toggle_reset_block){
            old_toggle_reset_block = params->toggle_reset_block;
            block_counter = 0;
            trial_counter = 0;

            // Frequency order

            if (params->num_force_frequencies > 0){
                for (int i=0; i<params->num_force_frequencies; i++){
                    frequency_order[i] = i;
                    if (params->num_force_frequencies > 1){
                        frequencies[i] = params->force_frequency_low + i*(params->force_frequency_high -
                                params->force_frequency_low)/(params->num_force_frequencies-1);
                    } else {
                        frequencies[i] = params->force_frequency_low;
                    }
                    tmp_sort[i] = random->getDouble(0,1);
                }

                for (int i=0; i<params->num_force_frequencies; i++){
                    for (int j=0; j<params->num_force_frequencies; j++){
                        if (tmp_sort[j] < tmp_sort[j+1]){
                            tmp_d = tmp_sort[j];
                            tmp_sort[j] = tmp_sort[j+1];
                            tmp_sort[j+1] = tmp_d;

                            tmp = frequency_order[j];
                            frequency_order[j] = frequency_order[j+1];
                            frequency_order[j+1] = tmp;  
                        }
                    }
                }
            }
        }
        trial_force_frequency = frequencies[frequency_order[block_counter]];

        // Bumps
        if (random->getDouble(0,1)*100 < params->percent_bump_trials){
            bump_trial = 1;   
            rand_i = random->getInteger(0,params->num_bump_directions-1);       
            rand_d = random->getDouble(0,2*PI);
            if (params->num_bump_directions > 1){
                bump_direction = params->first_bump_direction + 
                        rand_i*(2*PI)/(params->num_bump_directions);
            } else if (params->num_bump_directions == 1){
                bump_direction = params->first_bump_direction;
            } else {
                bump_direction = rand_d;
            }
        } else {
            bump_trial = 0;
            bump_direction = 0;
        }
        if (params->early_bumps && params->late_bumps){
            rand_d = random->getDouble(0,1);
            early_bump = (rand_d>0.5) ? 1 : 0;
        } else if (params->early_bumps) {
            early_bump = 1;
        } else {
            early_bump = 0;
        }
    }
    
    bump->direction = bump_direction;
    bump->hold_duration = params->bump_duration;
    bump->peak_magnitude = params->bump_magnitude;
    bump->rise_time = 0;	

    infinite_bump->direction = bump_direction;
    infinite_bump->hold_duration = 0.03;
    infinite_bump->peak_magnitude = 0*params->bump_magnitude;
    infinite_bump->rise_time = 0;

    PDbump->direction = bump_direction;
    PDbump->duration = params->bump_duration;
    PDbump->bump_vel = params->bump_velocity;
    PDbump->vel_gain = params->P_gain_vel;
    PDbump->pos_gain = params->P_gain_pos;
    
    last_trial_reward = 0;
    
    // Targets
    real_T m_red = 1/(params->force_frequency_high - params->force_frequency_low);
    real_T b_red = -params->force_frequency_low/(params->force_frequency_high - params->force_frequency_low);
    real_T m_blue = -m_red;
    real_T b_blue = params->force_frequency_high/(params->force_frequency_high - params->force_frequency_low);
    int red_value = int(255*(m_red*trial_force_frequency + b_red));
    red_value = (red_value < 0) ? 0 : (red_value > 255 ? 255 : red_value);    
    int blue_value = int(255*(m_blue*trial_force_frequency + b_blue));
    blue_value = (blue_value < 0) ? 0 : (blue_value > 255 ? 255 : blue_value);
    centerTarget->color = Target::Color(red_value,0,blue_value);    
    holdTarget->color = Target::Color(red_value,0,blue_value);    
    
    centerTarget->centerX = 0;
    centerTarget->centerY = 0;
    holdTarget->centerX = 0;
    holdTarget->centerY = 0;
        
	center_hold_time = this->random->getDouble(params->center_hold_low,params->center_hold_high);
    perturbation_hold_time = this->random->getDouble(params->perturbation_hold_low,params->perturbation_hold_high);

	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);								// byte 1 -> Matlab idx 2
	db->addByte(BEHAVIOR_VERSION_MAJOR);						// byte 2 -> Matlab idx 3
    db->addByte(BEHAVIOR_VERSION_MINOR);						// byte 3 -> Matlab idx 4
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);		// byte 4 -> Matlab idx 5
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);				// byte 5 -> Matlab idx 6
	db->addFloat((float)(inputs->offsets.x));					// bytes 6 to 9 -> Matlab idx 7 to 10
	db->addFloat((float)(inputs->offsets.y));					// bytes 10 to 13 -> Matlab idx 11 to 14
	db->addFloat((float)trial_force_direction);                 // bytes 14 to 17 -> Matlab idx 15 to 18
    db->addFloat((float)trial_force_amplitude);                 // bytes 18 to 21 -> Matlab idx 19 to 22    
	db->addFloat((float)params->perturbation_type);             // bytes 22 to 25 -> Matlab idx 23 to 26
	db->addFloat((float)params->target_radius);                 // bytes 26 to 29 -> Matlab idx 27 to 30	    
    db->addByte((int)params->brain_control);                    // byte  30       -> Matlab idx 31
    db->addByte((int)params->force_visual_feedback);            // byte  31       -> Matlab idx 32
    db->addByte((int)bump_trial);                               // byte  32       -> Matlab idx 33    
    if (params->force_bump){
        db->addFloat((float)params->bump_magnitude);            // bytes 33 to 36 -> Matlab idx 34 to 37
    } else {
        db->addFloat((float)params->bump_velocity);             // bytes 33 to 36 -> Matlab idx 34 to 37
    }
    db->addFloat((float)bump_direction);                        // bytes 37 to 40 -> Matlab idx 38 to 41
    db->addFloat((float)params->bump_duration);                 // bytes 41 to 44 -> Matlab idx 42 to 45
    db->addByte((int)params->force_bump);                       // byte  45       -> Matlab idx 46
    db->addFloat((float)trial_force_frequency);                 // bytes 46 to 49 -> Matlab idx 47 to 50
    db->addFloat((float)params->stiffness);                     // bytes 50 to 53 -> Matlab idx 51 to 54
    db->addFloat((float)params->damping);                       // bytes 54 to 57 -> Matlab idx 55 to 58
    db->addFloat((float)params->center_hold_target_radius);     // bytes 58 to 61 -> Matlab idx 59 to 62
    db->addByte((int)early_bump);                               // byte 62        -> Matlab idx 63
	db->start();
}

void ResistPerturbations::update(SimStruct *S) {       
	// State machine
    switch (this->getState()) {
        case STATE_PRETRIAL:
            updateParameters(S);
            doPreTrial(S);
            setState(STATE_WAIT_FOR_DB);
            break;
        case STATE_WAIT_FOR_DB:
            if (!db->isRunning()) {
                if ((bool)params->record && !recordingTimer->isRunning()){
                    setState(STATE_START_RECORDING);
                } else if ((!((bool)params->record) && recordingTimer->isRunning()) ||
                        (recordingTimer->elapsedTime(S) > 60 * params->record_for_x_mins)) {
                    setState(STATE_STOP_RECORDING);
                } else {
                    setState(STATE_CENTER_TARGET_ON);
                }
            }
            break;
        case STATE_START_RECORDING:
            if (!recordingTimer->isRunning()) {
                recordingTimer->start(S);
            }
            if (stateTimer->elapsedTime(S) > 1.0) {    
                playTone(TONE_FAIL);
                setState(STATE_CENTER_TARGET_ON);
            }
            break;
        case STATE_STOP_RECORDING:
            if (recordingTimer->isRunning()) {
                recordingTimer->stop(S);
            }            
            if (stateTimer->elapsedTime(S) > 1.0){     
                playTone(TONE_FAIL);
                setState(STATE_INCOMPLETE);
            }
            break;                   
        case STATE_CENTER_TARGET_ON:
            /* center target on */
            if (inputs->catchForce.x && !params->brain_control) {
                setState(STATE_INCOMPLETE);
            } else {
                if (holdTarget->cursorInTarget(cursor_position)) {
                    setState(STATE_CT_HOLD);
                }
            }
            break;
        case STATE_CT_HOLD:
            if (inputs->catchForce.x  && !params->brain_control) {
                setState(STATE_INCOMPLETE);
            } else {
                if (!holdTarget->cursorInTarget(cursor_position)){
                    playTone(TONE_ABORT);
                    setState(STATE_ABORT);				
                } else if (stateTimer->elapsedTime(S) > center_hold_time){
                    if (bump_trial && early_bump){
                        setState(STATE_BUMP);
                    } else {
                        perturbationTimer->start(S);
                        setState(STATE_PERTURBATION);
                    }
                }
            }
            break;
        case STATE_PERTURBATION:
            if (inputs->catchForce.x && !params->brain_control) {
                setState(STATE_INCOMPLETE);
            } else {
                if (!centerTarget->cursorInTarget(cursor_position)){
                    perturbationTimer->stop(S);
                    playTone(TONE_ABORT);
                    setState(STATE_ABORT);		
                } else if (bump_trial && trigger_bump) {
                    perturbationTimer->stop(S);
                    setState(STATE_BUMP);                      
                } else if (!bump_trial && (stateTimer->elapsedTime(S) >= perturbation_hold_time)){
                    perturbationTimer->stop(S);
                    playTone(TONE_REWARD);
                    setState(STATE_REWARD);                    
                }
            }
            break;  
        case STATE_BUMP:
            if (!bump->isRunning(S)){
                bump->start(S);
                infinite_bump->start(S);
                PDbump->start(S);
            }
            if (stateTimer->elapsedTime(S) > params->bump_duration){
                this->bump->stop();
                this->infinite_bump->stop();
                this->PDbump->stop();
                playTone(TONE_REWARD);
                setState(STATE_REWARD);
            }
            break;      
        case STATE_REWARD:
            if (stateTimer->elapsedTime(S) > params->reward_wait){ 
                last_trial_reward = 1;
                setState(STATE_PRETRIAL);
            }
            break;
        case STATE_ABORT:
            if (stateTimer->elapsedTime(S) > params->abort_wait){
                setState(STATE_PRETRIAL);
            }
            break;
        case STATE_FAIL:
            if (stateTimer->elapsedTime(S) > params->fail_wait){                
                setState(STATE_PRETRIAL);
            }
            break;
        case STATE_INCOMPLETE:            
            if (inputs->catchForce.x && !params->brain_control){
                // Stay in this state until handle is back in workspace.
            } else if (stateTimer->elapsedTime(S) > params->reward_wait) {                
                setState(STATE_PRETRIAL);
            }
			break;
        default:
            setState(STATE_PRETRIAL);
    }
    
}

void ResistPerturbations::calculateOutputs(SimStruct *S) {  
    if (params->brain_control){
        if (!(cursor_position_old.x>=0) && !(cursor_position_old.x<=0) || 
                !(cursor_position_old.y>=0) && !(cursor_position_old.y<=0)){
            cursor_position_old.x = inputs->force.x;
            cursor_position_old.y = inputs->force.y;
        }
        if (!(cursor_velocity_old.x>=0) && !(cursor_velocity_old.x<=0) || 
                !(cursor_velocity_old.y>=0) && !(cursor_velocity_old.y<=0)){
            cursor_velocity_old.x = 0;
            cursor_velocity_old.y = 0;
        }
        cursor_position.x = cursor_position_old.x*(1-params->pos_filt) + 
                inputs->force.x * params->pos_filt; // hacked it to take the neural input through the force port
        cursor_position.y = cursor_position_old.y*(1-params->pos_filt) + 
                inputs->force.y * params->pos_filt; // hacked it to take the neural input through the force port
        
        shoulder_pos = inputs->extra1;
        elbow_pos = inputs->extra2;
        
        Point upper_arm_length;
        Point lower_arm_length;
        
        upper_arm_length = shoulder_pos - elbow_pos;
        lower_arm_length = elbow_pos - cursor_position;
        
        for(int i=0; i<5 ; i++){
            upperArm[i]->centerX = shoulder_pos.x - (i+1)*upper_arm_length.x/5;
            upperArm[i]->centerY = shoulder_pos.y - (i+1)*upper_arm_length.y/5;
            lowerArm[i]->centerX = elbow_pos.x - (i+1)*lower_arm_length.x/6;
            lowerArm[i]->centerY = elbow_pos.y - (i+1)*lower_arm_length.y/6;
        }
    } else {
        cursor_position.x = cursor_position_old.x*(1-params->pos_filt) + 
                inputs->cursor.x * params->pos_filt; 
        cursor_position.y = cursor_position_old.y*(1-params->pos_filt) + 
                inputs->cursor.y * params->pos_filt; 
    }         
    
    cursor_velocity.x = cursor_velocity_old.x*(1-params->vel_filt) +
        ((cursor_position.x-cursor_position_old.x)/.001)*params->vel_filt;
    cursor_velocity.y = cursor_velocity_old.y*(1-params->vel_filt) +
        ((cursor_position.y-cursor_position_old.y)/.001)*params->vel_filt;
    
    cursor_position_old = cursor_position;
    cursor_velocity_old = cursor_velocity;   
    
    /* force (0) */ 
    force = Point(0,0);
    
    real_T force_magnitude = 0;
    if (perturbationTimer->isRunning()){
        real_T t = perturbationTimer->elapsedTime(S);
        real_T a = trial_force_amplitude;
        real_T p = 1/trial_force_frequency;
        
        if (params->perturbation_type == 0) { // Sinusoidal perturbation
            force_magnitude = a * sin(2*PI*trial_force_frequency*t);            
        } else if (params->perturbation_type == 1) { // Triangular perturbation 
            if (p>0){
                force_magnitude = a*(2*abs(2*((t+p/4)/p-floor((t+p/4)/p + 1/2)))-1);
            }            
        } else {   // Non implemented perturbation
            force = Point(0,0);
        }
        force.x = force_magnitude * cos(trial_force_direction);
        force.y = force_magnitude * sin(trial_force_direction);
        
    }
    force.x += -params->stiffness*(cursor_position.x * cos(trial_force_direction+PI/2) +
                    cursor_position.y * sin(trial_force_direction+PI/2)) * cos(trial_force_direction+PI/2) -
                    params->damping*(cursor_velocity.x * cos(trial_force_direction+PI/2) + 
                    cursor_velocity.y * sin(trial_force_direction+PI/2)) * cos(trial_force_direction+PI/2);        
    force.y += -params->stiffness*(cursor_position.x*cos(trial_force_direction+PI/2) + 
            cursor_position.y * sin(trial_force_direction+PI/2)) * sin(trial_force_direction+PI/2) -
            params->damping*(cursor_velocity.x * cos(trial_force_direction+PI/2) + 
            cursor_velocity.y * sin(trial_force_direction+PI/2)) * sin(trial_force_direction+PI/2);    
    if (getState() == STATE_CT_HOLD) {
        real_T force_scaling = (center_hold_time - stateTimer->elapsedTime(S))/center_hold_time;
        force.x += force_scaling*(-params->stiffness*(cursor_position.x * cos(trial_force_direction) +
                    cursor_position.y * sin(trial_force_direction)) * cos(trial_force_direction) -
                    params->damping*(cursor_velocity.x * cos(trial_force_direction) + 
                    cursor_velocity.y * sin(trial_force_direction)) * cos(trial_force_direction));        
        force.y += force_scaling*(-params->stiffness*(cursor_position.x*cos(trial_force_direction) + 
                cursor_position.y * sin(trial_force_direction)) * sin(trial_force_direction) -
                params->damping*(cursor_velocity.x * cos(trial_force_direction) + 
                cursor_velocity.y * sin(trial_force_direction)) * sin(trial_force_direction));    
    }
    
    if (getState() == STATE_PERTURBATION &&
            stateTimer->elapsedTime(S) >= perturbation_hold_time &&
            old_force_magnitude>=0 && force_magnitude<0){
        trigger_bump = 1;
    }
    old_force_magnitude = force_magnitude;
      
    if (getState() == STATE_PERTURBATION && params->force_visual_feedback) {
        for (int i=0; i<5; i++){
            forceFeedback[i]->centerX = cursor_position.x + force_magnitude*i/4*cos(trial_force_direction);
            forceFeedback[i]->centerY = cursor_position.y + force_magnitude*i/4*sin(trial_force_direction);
        }
    } else {
        for (int i=0; i<5; i++){
            forceFeedback[i]->centerX = cursor_position.x;
            forceFeedback[i]->centerY = cursor_position.y;
        }
    }
    
    if (bump->isRunning(S)){
        if(params->force_bump){
            force = bump->getBumpForce(S);
            force += infinite_bump->getBumpForce(S);
        } else {            
            force = PDbump->getBumpForce(S,cursor_velocity,cursor_position);
        }
    }
   
    if (getState()==STATE_CT_HOLD ||
            getState()==STATE_PERTURBATION ||
            getState()==STATE_BUMP){
        outputs->force = force;
    } else {        
        outputs->force = Point(0,0);
    }
        
	/* status (1) */
	outputs->status[0] = getState();
	outputs->status[1] = trialCounter->successes;
	outputs->status[2] = trialCounter->aborts;
	outputs->status[3] = trialCounter->failures;
	outputs->status[4] = trialCounter->incompletes;  
    
//     outputs->status[0] = 100*frequencies[0];
// 	outputs->status[1] = 100*frequencies[1];
// 	outputs->status[2] = 100*frequencies[2];
// 	outputs->status[3] = 100*frequencies[3];
// 	outputs->status[4] = trial_counter;  
    
	/* word (2) */
	if (db->isRunning()) {
		outputs->word = db->getByte();
	} else if (isNewState()) {
		switch (getState()) {
			case STATE_PRETRIAL:
				outputs->word = WORD_START_TRIAL;           // 0x1F = 31 
				break;
            case STATE_START_RECORDING:
				outputs->word = WORD_START_RECORDING;        // 0x91 = 145  
                break;
            case STATE_STOP_RECORDING:
				outputs->word = WORD_STOP_RECORDING;         // 0x92 = 146  
                break;              
			case STATE_CENTER_TARGET_ON:
				outputs->word = WORD_CT_ON;                 // 0x30 = 48
                break;
			case STATE_CT_HOLD:
				outputs->word = WORD_CENTER_TARGET_HOLD;    // 0xA0 = 160
                break;
            case STATE_PERTURBATION:
                outputs->word = WORD_GO_CUE;                // 0x31 = 49
                break;
            case STATE_BUMP:
				outputs->word = WORD_BUMP(0);               // 0x50 = 80
				break; 
			case STATE_REWARD:
				outputs->word = WORD_REWARD;                // 0x20 = 32
                break;
			case STATE_ABORT:
				outputs->word = WORD_ABORT;                 // 0x21 = 33
                break;		
            case STATE_FAIL:
                outputs->word = WORD_FAIL;                  // 0x22 = 34
                break;
			default:
				outputs->word = 0;
		}
	} else {
		outputs->word = 0;
	}

	/* targets (3) */    
    if (params->brain_control){
        for(int i=0;i<5;i++){
            outputs->targets[i] = upperArm[i];
            outputs->targets[5+i] = lowerArm[i];
        }
    } else {
        for(int i=0;i<5;i++){
            outputs->targets[i] = nullTarget;
            outputs->targets[5+i] = nullTarget;
        }
    }
	switch (this->getState()){
		case STATE_CENTER_TARGET_ON:
        case STATE_CT_HOLD: 
            outputs->targets[10] = (Target *)holdTarget;
            break;
        case STATE_PERTURBATION:
        case STATE_BUMP:
            outputs->targets[10] = (Target *)centerTarget;
			break;     
		default:
            outputs->targets[10] = nullTarget;
	}
    if (params->force_visual_feedback && getState()==STATE_PERTURBATION) {
        for (int i=0; i<5; i++){
            outputs->targets[11+i] = forceFeedback[i];
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
    outputs->position = cursor_position;
}

/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"

