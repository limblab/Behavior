/* $Id: $
 *
 * Master Control block for behavior: unstable field
 */

#define DATABURST_VERSION ((byte)0x06) 
/* 
 * Current Databurst version: 6
 *
 * Note that all databursts are encoded half a byte at a time as a word who's 
 * high order bits are all 1 and who's low order bits represent the half byte to
 * be transmitted.  Low order bits are transmitted first.  Thus to transmit the
 * two bytes 0xCF 0x07, one would send 0xFF 0xFC 0xF7 0xF0.
 *
 * Databurst version descriptions
 * ==============================
 * 
 * * * Version 6 (0x06)
 * ----------------
 * byte         0: uchar => number of bytes to be transmitted
 * byte         1: uchar => databurst version number (in this case zero)
 * byte         2: uchar => model version major
 * byte         3: uchar => model version minor
 * bytes   4 to 5: short => model version micro
 * bytes   6 to 9: float => x offset (cm)
 * bytes 10 to 13: float => y offset (cm)
 * bytes 14 to 17: float => bump velocity (cm/s) or magnitude (N) depending on type.
 * bytes 18 to 21: float => bump direction (rad)
 * bytes 22 to 25: float => bump duration (s)
 * bytes 26 to 29: float => negative stiffness (N/cm)
 * bytes 30 to 33: float => positive stiffness (N/cm)
 * bytes 34 to 37: float => force field angle (rad)
 * bytes 38 to 41: float => bias force magnitude (N)
 * bytes 42 to 45: float => bias force angle (rad)
 * bytes 46 to 49: float => force target diameter (N)
 * byte        50: uchar => force bump (if 0: vel bump)
 * bytes 51 to 54: float => infintite force bump duration
 * byte        55: uchar => position cursor (if 0: force cursor)
 *
 * * Version 5 (0x05)
 * ----------------
 * byte         0: uchar => number of bytes to be transmitted
 * byte         1: uchar => databurst version number (in this case zero)
 * byte         2: uchar => model version major
 * byte         3: uchar => model version minor
 * bytes   4 to 5: short => model version micro
 * bytes   6 to 9: float => x offset (cm)
 * bytes 10 to 13: float => y offset (cm)
 * bytes 14 to 17: float => bump velocity (cm/s) or magnitude (N) depending on type.
 * bytes 18 to 21: float => bump direction (rad)
 * bytes 22 to 25: float => bump duration (s)
 * bytes 26 to 29: float => negative stiffness (N/cm)
 * bytes 30 to 33: float => positive stiffness (N/cm)
 * bytes 34 to 37: float => force field angle (rad)
 * bytes 38 to 41: float => bias force magnitude (N)
 * bytes 42 to 45: float => bias force angle (rad)
 * bytes 46 to 49: float => force target diameter (N)
 * byte        50: uchar => force bump (if 0, vel bump)
 * bytes 51 to 54: float => infintite force bump duration
 *
 * Version 4 (0x04)
 * ----------------
 * byte         0: uchar => number of bytes to be transmitted
 * byte         1: uchar => databurst version number (in this case zero)
 * byte         2: uchar => model version major
 * byte         3: uchar => model version minor
 * bytes   4 to 5: short => model version micro
 * bytes   6 to 9: float => x offset (cm)
 * bytes 10 to 13: float => y offset (cm)
 * bytes 14 to 17: float => bump velocity (cm/s) or magnitude (N) depending on type.
 * bytes 18 to 21: float => bump direction (rad)
 * bytes 22 to 25: float => bump duration (s)
 * bytes 26 to 29: float => negative stiffness (N/cm)
 * bytes 30 to 33: float => positive stiffness (N/cm)
 * bytes 34 to 37: float => force field angle (rad)
 * bytes 38 to 41: float => bias force magnitude (N)
 * bytes 42 to 45: float => bias force angle (rad)
 * bytes 46 to 49: float => force target diameter (N)
 * byte        50: uchar => force bump (if 0, vel bump)
 *
 * Version 3 (0x03)
 * ----------------
 * byte         0: uchar => number of bytes to be transmitted
 * byte         1: uchar => databurst version number (in this case zero)
 * byte         2: uchar => model version major
 * byte         3: uchar => model version minor
 * bytes   4 to 5: short => model version micro
 * bytes   6 to 9: float => x offset (cm)
 * bytes 10 to 13: float => y offset (cm)
 * bytes 14 to 17: float => bump velocity (cm/s)
 * bytes 18 to 21: float => bump direction (rad)
 * bytes 22 to 25: float => bump duration (s)
 * bytes 26 to 29: float => negative stiffness (N/cm)
 * bytes 30 to 33: float => positive stiffness (N/cm)
 * bytes 34 to 37: float => force field angle (rad)
 * bytes 38 to 41: float => bias force magnitude (N)
 * bytes 42 to 45: float => bias force angle (rad)
 * bytes 46 to 49: float => force target diameter (N)
 *
 * Version 2 (0x02)
 * ----------------
 * byte         0: uchar => number of bytes to be transmitted
 * byte         1: uchar => databurst version number (in this case zero)
 * byte         2: uchar => model version major
 * byte         3: uchar => model version minor
 * bytes   4 to 5: short => model version micro
 * bytes   6 to 9: float => x offset (cm)
 * bytes 10 to 13: float => y offset (cm)
 * bytes 14 to 17: float => bump magnitude (N?)
 * bytes 18 to 21: float => bump direction (rad)
 * bytes 22 to 25: float => bump duration (s)
 * bytes 26 to 29: float => negative stiffness (N/m?)
 * bytes 30 to 33: float => positive stiffness (N/m?)
 * bytes 34 to 37: float => force field angle (rad)
 * bytes 38 to 41: float => bias force magnitude (N?)
 * bytes 42 to 45: float => bias force angle (rad)
 * bytes 46 to 49: float => force target diameter (N?)
 *
 * Version 1 (0x01)
 * ----------------
 * byte         0: uchar => number of bytes to be transmitted
 * byte         1: uchar => databurst version number (in this case zero)
 * byte         2: uchar => model version major
 * byte         3: uchar => model version minor
 * bytes   4 to 5: short => model version micro
 * bytes   6 to 9: float => x offset (cm)
 * bytes 10 to 13: float => y offset (cm)
 * bytes 14 to 17: float => bump magnitude (N?)
 * bytes 18 to 21: float => bump direction (rad)
 * bytes 22 to 25: float => bump duration (s)
 * bytes 26 to 29: float => negative stiffness (N/m?)
 * bytes 30 to 33: float => positive stiffness (N/m?)
 * bytes 34 to 37: float => force field angle (rad)
 * bytes 38 to 41: float => bias force magnitude (N?)
 * bytes 42 to 45: float => bias force angle (rad)
 *
 * Version 0 (0x00)
 * ----------------
 * byte         0: uchar => number of bytes to be transmitted
 * byte         1: uchar => databurst version number (in this case zero)
 * byte         2: uchar => model version major
 * byte         3: uchar => model version minor
 * bytes   4 to 5: short => model version micro
 * bytes   6 to 9: float => x offset (cm)
 * bytes 10 to 13: float => y offset (cm)
 * bytes 14 to 17: float => bump magnitude (N?)
 * bytes 18 to 21: float => bump direction (rad)
 * bytes 22 to 25: float => negative stiffness (N/m?)
 * bytes 26 to 29: float => positive stiffness (N/m?)
 * bytes 30 to 33: float => force field angle (rad)
 * bytes 34 to 37: float => bias force magnitude (N?)
 * bytes 38 to 41: float => bias force angle (rad)
 */


#define S_FUNCTION_NAME mastercon_unstable
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
#define STATE_FIELD_BUILD_UP		 3
#define STATE_HOLD_FIELD			 4
#define STATE_CT_HOLD				 5
#define STATE_BUMP					 6
#define STATE_START_RECORDING        7
#define STATE_STOP_RECORDING         8

/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */

// This must be custom defined for your behavior
struct LocalParams{
	real_T master_reset;

	// Timing
	real_T field_ramp_up;
	real_T field_hold_low;
	real_T field_hold_high;
	real_T reward_wait;
	real_T abort_wait;

	// Target and workspace
	real_T target_diameter;
	real_T workspace_diameter;

	// Unstable field
	real_T negative_stiffness;  // Must be a positive value
	real_T positive_stiffness;
	real_T first_field_angle;
	real_T x_position_offset;
	real_T y_position_offset;
	real_T bias_force_magnitude;
	real_T first_bias_force_direction;

	// Bumps
	real_T bump_duration;
	real_T bump_velocity;
	real_T num_bump_directions;
	real_T first_bump_direction;
        
    // Unstable field again
    real_T num_field_orientations;
    real_T field_block_length;    
        
    // Force target
    real_T force_target_diameter;
    
    // Velocity controller parameters
    real_T P_gain_vel;
    real_T controller_damping_ratio;
    real_T mass;
    real_T P_gain_pos;
    
    real_T force_field_damping;
    
    // Bump type
    real_T force_bump;
    real_T force_bump_magnitude;
    
    // More bias force stuff
    real_T num_bias_directions;
    real_T bias_direction_separation;
    
    // More bump stuff
    real_T infinite_bump_duration;
    
    // More field stuff
    real_T vel_filt;
    real_T pos_filt;
    
    // Cereubs recording stuff
    real_T record;
    real_T record_for_x_mins;
    
    // More cursor stuff
    real_T position_cursor;
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
	CircleTarget *centerTarget;	
	CircleTarget *workSpaceTarget;	
    CircleTarget *forceTarget;
    CircleTarget *forceFeedbackTarget;
    
	LocalParams *params;	

	real_T field_hold_time;
	real_T bump_direction;
	
	TrapBumpGenerator *bump;
    TrapBumpGenerator *infinite_bump;
	real_T x_force_at_bump_start;
	real_T y_force_at_bump_start;
    
    real_T x_pos_at_bump_start;
    real_T y_pos_at_bump_start;
    
    real_T x_vel;
    real_T y_vel;
    real_T vel;
    real_T x_vel_old;
    real_T y_vel_old;
    
    real_T x_pos;
    real_T y_pos;
    real_T x_pos_old;
    real_T y_pos_old;
    
    real_T field_angle;
    
    real_T old_block_length;
    
    int trial_counter;
    int block_counter;
    int block_order [10];
    int *block_order_point [10];
    int bias_force_counter;
    int bump_counter;
    int bump_order [10];
    int *bump_order_point [10];
    
    real_T bias_force_angle;

	// any helper functions you need
	void doPreTrial(SimStruct *S);
    
    Timer *recordingTimer;
    
    int lastWord;
    
    real_T debug_var;
    real_T pos_cursor_x_offset;
    real_T pos_cursor_y_offset;
    Point cursor_offset;
    real_T x_force_field;
    real_T y_force_field;
    real_T x_force_cursor;
    real_T y_force_cursor;
    real_T ratio_force;
    real_T x_force_neg_stiffness;
    real_T y_force_neg_stiffness;
    real_T x_force_pos_stiffness;
    real_T y_force_pos_stiffness;
    real_T force_to_position;
    real_T desired_x_pos;
    real_T desired_y_pos;
};

AttentionBehavior::AttentionBehavior(SimStruct *S) : RobotBehavior() {

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(37);
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,							 0);
	this->bindParamId(&params->field_ramp_up,							 1);
	this->bindParamId(&params->field_hold_low,							 2);
	this->bindParamId(&params->field_hold_high,							 3);
	this->bindParamId(&params->reward_wait,								 4);
	this->bindParamId(&params->abort_wait,								 5);

	this->bindParamId(&params->target_diameter,							 6);
	this->bindParamId(&params->workspace_diameter,						 7);

	this->bindParamId(&params->negative_stiffness,						 8);
	this->bindParamId(&params->positive_stiffness,						 9);
	this->bindParamId(&params->first_field_angle,   					 10);
	this->bindParamId(&params->x_position_offset,						 11);
	this->bindParamId(&params->y_position_offset,						 12);
    this->bindParamId(&params->bias_force_magnitude,					 13);
	this->bindParamId(&params->first_bias_force_direction,			     14);

	this->bindParamId(&params->bump_duration,							 15);
	this->bindParamId(&params->bump_velocity,							 16);
	this->bindParamId(&params->num_bump_directions,						 17);
	this->bindParamId(&params->first_bump_direction,					 18);
    
    this->bindParamId(&params->num_field_orientations,                   19);
    this->bindParamId(&params->field_block_length,                       20);
    
    this->bindParamId(&params->force_target_diameter,                    21);
    
    this->bindParamId(&params->P_gain_vel,                               22);
    this->bindParamId(&params->controller_damping_ratio,                 23);
    this->bindParamId(&params->mass,                                     24);
    this->bindParamId(&params->P_gain_pos,                               25);
    
    this->bindParamId(&params->force_field_damping,                      26);
    
    this->bindParamId(&params->force_bump,                               27);
    this->bindParamId(&params->force_bump_magnitude,                     28);
    
    this->bindParamId(&params->num_bias_directions,                      29);
    this->bindParamId(&params->bias_direction_separation,                30);
    
    this->bindParamId(&params->infinite_bump_duration,                   31);
    
    this->bindParamId(&params->vel_filt,                                 32);
    this->bindParamId(&params->pos_filt,                                 33);
    
    this->bindParamId(&params->record,                                   34);
    this->bindParamId(&params->record_for_x_mins,                        35);
    
    this->bindParamId(&params->position_cursor,                          36);
    
    // default parameters:
    // 1 1 2 1 1   5 10   5 5 0 0 0 1 1   .2 0 1 0   1 10   1   0.015 1 0.5 0   .001   1 0   1 pi/2   0   1 1   0
    
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
		
	centerTarget = new CircleTarget();
	centerTarget->color = Target::Color(255,150,50);	

	workSpaceTarget = new CircleTarget();
	workSpaceTarget->color = Target::Color(60,60,60);
    
    forceTarget = new CircleTarget();
	forceTarget->color = Target::Color(255,0,0);
    
    forceFeedbackTarget = new CircleTarget();
	forceFeedbackTarget->color = Target::Color(255,0,0);

    field_hold_time = 0.0;
	bump_direction = 0.0;
	
	bump = new TrapBumpGenerator();
    infinite_bump = new TrapBumpGenerator();
    
    x_pos_at_bump_start = 0;
	y_pos_at_bump_start = 0;
	x_force_at_bump_start = 0;
	y_force_at_bump_start = 0;
    
    block_counter = 10000; 
    trial_counter = 10000; // Stupidly large number so that the blocks are reset in first pretrial.
    bias_force_counter = 10000;
    bump_counter = 10000;
    field_angle = 0;
    
    x_pos_old = 0;
    y_pos_old = 0;
    
    x_vel_old = 0;
    y_vel_old = 0;
    
    bias_force_angle = 0;
    
    recordingTimer = new Timer();
    
    debug_var = 0.0;
    
    lastWord = 0;
    
    pos_cursor_x_offset = 0.0;
    pos_cursor_y_offset = 0.0;
    x_force_field = 0.0;
    y_force_field = 0.0;
    x_force_cursor = 0.0;
    y_force_cursor = 0.0;
    ratio_force = 0.0;
    x_force_neg_stiffness = 0.0;
    y_force_neg_stiffness = 0.0;
    x_force_pos_stiffness = 0.0;
    y_force_pos_stiffness = 0.0;
    force_to_position = 0.0;
    desired_x_pos = 0.0;
    desired_y_pos = 0.0;
}

void AttentionBehavior::doPreTrial(SimStruct *S) {	
    force_to_position = params->target_diameter/params->force_target_diameter;
    
	centerTarget->centerX = params->x_position_offset;
	centerTarget->centerY = params->y_position_offset;
	centerTarget->radius = params->target_diameter/2;

	workSpaceTarget->centerX = params->x_position_offset;
	workSpaceTarget->centerY = params->y_position_offset;
	workSpaceTarget->radius = params->workspace_diameter/2;
        
	field_hold_time = this->random->getDouble(params->field_hold_low,params->field_hold_high);
	   
    if (old_block_length != params->field_block_length) {
        trial_counter = 10000;
        block_counter = 10000;
        bias_force_counter = 10000;
        bump_counter = 10000;
    }
        
    if (trial_counter >= params->field_block_length-1){
        trial_counter = -1;
        block_counter++;
        if (block_counter >= params->num_field_orientations){            
            block_counter = 0;
            double tmp_sort[100];
            double tmp_d;
            int tmp;

            for (int i=0; i<params->num_field_orientations; i++){
                block_order[i] = i;
                tmp_sort[i] = random->getDouble(0,1);
            }

            for (int i=0; i<params->num_field_orientations-1; i++){
                for (int j=0; j<params->num_field_orientations-1; j++){
                    if (tmp_sort[j] < tmp_sort[j+1]){
                        tmp_d = tmp_sort[j];
                        tmp_sort[j] = tmp_sort[j+1];
                        tmp_sort[j+1] = tmp_d;

                        tmp = block_order[j];
                        block_order[j] = block_order[j+1];
                        block_order[j+1] = tmp;
                    }
                }
            }
        }
    }
    trial_counter++;
    field_angle = fmod(block_order[block_counter] * PI/(params->num_field_orientations) + 
        params->first_field_angle,2*PI); 
    
    if (block_counter == 0 && trial_counter == 0){
        bias_force_counter++;
        if (bias_force_counter >= params->num_bias_directions){
            bias_force_counter = 0;
        }
        bias_force_angle = fmod(bias_force_counter * params->bias_direction_separation + 
            params->first_bias_force_direction,2*PI); 
    }
    forceTarget->centerX = params->bias_force_magnitude*cos(bias_force_angle);
    forceTarget->centerY = params->bias_force_magnitude*sin(bias_force_angle);
    forceTarget->radius = params->force_target_diameter/2;
    
    forceFeedbackTarget->centerX = params->x_position_offset;
    forceFeedbackTarget->centerY = params->y_position_offset;
    real_T stiffness_scale = (params->negative_stiffness > params->positive_stiffness)?
        params->negative_stiffness:params->positive_stiffness;   
    forceFeedbackTarget->radius = params->force_target_diameter/(stiffness_scale*2);
    
    if (bump_counter >= params->num_bump_directions-1){
        bump_counter = -1;
        double tmp_sort[100];
        double tmp_d;
        int tmp;

        for (int i=0; i<params->num_bump_directions; i++){
            bump_order[i] = i;
            tmp_sort[i] = random->getDouble(0,1);
        }

        for (int i=0; i<params->num_bump_directions-1; i++){
            for (int j=0; j<params->num_bump_directions-1; j++){
                if (tmp_sort[j] < tmp_sort[j+1]){
                    tmp_d = tmp_sort[j];
                    tmp_sort[j] = tmp_sort[j+1];
                    tmp_sort[j+1] = tmp_d;

                    tmp = bump_order[j];
                    bump_order[j] = bump_order[j+1];
                    bump_order[j+1] = tmp;
                }
            }
        }
    }
    bump_counter++;
    bump_direction = fmod(bump_order[bump_counter] * 2 * PI/params->num_bump_directions + params->first_bump_direction,2*PI);

	bump->direction = bump_direction;
	bump->hold_duration = params->bump_duration;
	bump->peak_magnitude = params->force_bump_magnitude;
	bump->rise_time = 0;	
    
    infinite_bump->direction = bump_direction;
	infinite_bump->hold_duration = params->infinite_bump_duration;
	infinite_bump->peak_magnitude = 10*params->force_bump_magnitude;
	infinite_bump->rise_time = 0;
    
	x_force_at_bump_start = 0;
	y_force_at_bump_start = 0;
    
    // Cursor offset for position feedback
    real_T Fb, kneg, kpos, theta_f, theta_b, a, b, c, d, e;
    Fb = params->bias_force_magnitude;
    kneg = params->negative_stiffness;
    kpos = params->positive_stiffness;
    theta_f = field_angle;
    theta_b = bias_force_angle;   
    a = kneg*cos(theta_f)*cos(theta_f)-kpos*sin(theta_f)*sin(theta_f);
    b = (kneg+kpos)*sin(theta_f)*cos(theta_f);
    c = Fb*sin(theta_b);
    d = kneg*sin(theta_f)*sin(theta_f)-kpos*cos(theta_f)*cos(theta_f);
    e = Fb*cos(theta_b);
    
    pos_cursor_x_offset = (c*d-b*e)/(b*b-a*d);    
    pos_cursor_y_offset = (a*e-b*c)/(b*b-a*d);
               
    if (params->position_cursor){
        cursor_offset.x = pos_cursor_x_offset;
        cursor_offset.y = pos_cursor_y_offset;
    } else {
        cursor_offset.x = 0;
        cursor_offset.y = 0;
    }

	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);								// byte 1 -> Matlab idx 2
	db->addByte(BEHAVIOR_VERSION_MAJOR);						// byte 2 -> Matlab idx 3
    db->addByte(BEHAVIOR_VERSION_MINOR);						// byte 3 -> Matlab idx 4
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);		// byte 4 -> Matlab idx 5
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);				// byte 5 -> Matlab idx 6
	db->addFloat((float)(inputs->offsets.x));					// bytes 6 to 9 -> Matlab idx 7 to 10
	db->addFloat((float)(inputs->offsets.y));					// bytes 10 to 13 -> Matlab idx 11 to 14
    if (params->force_bump){
        db->addFloat((float)params->force_bump_magnitude);      // bytes 14 to 17 -> Matlab idx 15 to 18
    } else {
    	db->addFloat((float)params->bump_velocity);				// bytes 14 to 17 -> Matlab idx 15 to 18
    }
	db->addFloat((float)bump_direction);						// bytes 18 to 21 -> Matlab idx 19 to 22
    db->addFloat((float)params->bump_duration);                 // bytes 22 to 25 -> Matlab idx 23 to 26
	db->addFloat((float)params->negative_stiffness);			// bytes 26 to 29 -> Matlab idx 27 to 30
	db->addFloat((float)params->positive_stiffness);			// bytes 30 to 33 -> Matlab idx 31 to 34
	db->addFloat((float)field_angle);                           // bytes 34 to 37 -> Matlab idx 35 to 38
	db->addFloat((float)params->bias_force_magnitude);			// bytes 38 to 41 -> Matlab idx 39 to 42
	db->addFloat((float)bias_force_angle);                      // bytes 42 to 45 -> Matlab idx 43 to 46
    db->addFloat((float)params->force_target_diameter);         // bytes 46 to 49 -> Matlab idx 47 to 50
    db->addByte((int)params->force_bump);                       // byte 50        -> Matlab idx 51
    db->addFloat((float)params->infinite_bump_duration);        // bytes 51 to 54 -> Matlab idx 52 to 55
    db->addByte((int)params->position_cursor);                  // byte 44        -> Matlab idx 56 
    
	db->start();

}

void AttentionBehavior::update(SimStruct *S) {   
    
    real_T zero_for_debugging = 0.0;
    
    real_T damping;  
    // Force field damping coefficient    
    damping = params->force_field_damping;
    
    x_pos = x_pos_old*(1-params->pos_filt) + inputs->cursor.x * params->pos_filt;
    y_pos = y_pos_old*(1-params->pos_filt) + inputs->cursor.y * params->pos_filt;
    
    x_vel = x_vel_old*(1-params->vel_filt) + ((x_pos-x_pos_old)/.001)*params->vel_filt;
    y_vel = y_vel_old*(1-params->vel_filt) + ((y_pos-y_pos_old)/.001)*params->vel_filt;
    vel = sqrt(x_vel*x_vel + y_vel*y_vel);      
               
    /* force (0) */ 
    x_force_neg_stiffness = params->negative_stiffness*((inputs->cursor.x - params->x_position_offset - cursor_offset.x)*cos(field_angle) +
                    (inputs->cursor.y - params->y_position_offset - cursor_offset.y)*sin(field_angle))*cos(field_angle);    
//         x_force_neg_stiffness = (x_force_neg_stiffness>0?1:-1)*sqrt(fabs(x_force_neg_stiffness));
    x_force_pos_stiffness = params->positive_stiffness*(-(inputs->cursor.x - params->x_position_offset - cursor_offset.x)*sin(field_angle) + 
                    (inputs->cursor.y - params->y_position_offset - cursor_offset.y)*cos(field_angle))*sin(field_angle);
    y_force_neg_stiffness = params->negative_stiffness*((inputs->cursor.x-params->x_position_offset - cursor_offset.x)*cos(field_angle) + 
                    (inputs->cursor.y - params->y_position_offset - cursor_offset.y)*sin(field_angle))*sin(field_angle);
//         y_force_neg_stiffness = (y_force_neg_stiffness>0?1:-1)*sqrt(fabs(y_force_neg_stiffness));    
    y_force_pos_stiffness = params->positive_stiffness*(-(inputs->cursor.x - params->x_position_offset - cursor_offset.x)*sin(field_angle) + 
                    (inputs->cursor.y-params->y_position_offset - cursor_offset.y)*cos(field_angle))*cos(field_angle);
    
    
    x_force_field = x_force_neg_stiffness + x_force_pos_stiffness + 
                    params->bias_force_magnitude * cos(bias_force_angle) +
                    damping*(-x_vel*sin(field_angle) + y_vel*cos(field_angle))*sin(field_angle);
    
	y_force_field = y_force_neg_stiffness - y_force_pos_stiffness + 
                        params->bias_force_magnitude * sin(bias_force_angle) -
                        damping*(-x_vel*sin(field_angle) + y_vel*cos(field_angle))*cos(field_angle);

    // Force cursor
    x_force_cursor = params->negative_stiffness*((inputs->cursor.x - params->x_position_offset)*cos(field_angle) +
					    (inputs->cursor.y - params->y_position_offset)*sin(field_angle))*cos(field_angle) - 
						params->positive_stiffness*(-(inputs->cursor.x - params->x_position_offset)*sin(field_angle) + 
						(inputs->cursor.y - params->y_position_offset)*cos(field_angle))*sin(field_angle);

	y_force_cursor = params->negative_stiffness*((inputs->cursor.x-params->x_position_offset)*cos(field_angle) + 
						(inputs->cursor.y - params->y_position_offset)*sin(field_angle))*sin(field_angle) +
						params->positive_stiffness*(-(inputs->cursor.x - params->x_position_offset)*sin(field_angle) + 
						(inputs->cursor.y-params->y_position_offset)*cos(field_angle))*cos(field_angle);
           
	// State machine
    switch (this->getState()) {
        case STATE_PRETRIAL:
            old_block_length = params->field_block_length;
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
                playTone(TONE_GO);
                setState(STATE_CENTER_TARGET_ON);
            }
            break;
        case STATE_STOP_RECORDING:
            if (recordingTimer->isRunning()) {
                recordingTimer->stop(S);
            }            
            if (stateTimer->elapsedTime(S) > 1.0){     
                playTone(TONE_GO);
                setState(STATE_INCOMPLETE);
            }
            break;                   
        case STATE_CENTER_TARGET_ON:
            /* center target on */
            if (inputs->catchForce.x) {
                setState(STATE_INCOMPLETE);
            } else {
                if (centerTarget->cursorInTarget(inputs->cursor - Point(cursor_offset.x*zero_for_debugging,cursor_offset.y*zero_for_debugging))) {
                    setState(STATE_FIELD_BUILD_UP);
                }
            }
            break;		
        case STATE_FIELD_BUILD_UP:
            if (inputs->catchForce.x) {
                setState(STATE_INCOMPLETE);
            } else {
                if (stateTimer->elapsedTime(S) > params->field_ramp_up){
                    setState(STATE_HOLD_FIELD);
                } else if (!workSpaceTarget->cursorInTarget(inputs->cursor - Point(cursor_offset.x*zero_for_debugging,cursor_offset.y*zero_for_debugging))){
                    setState(STATE_ABORT);
                }
            }
            break;
        case STATE_HOLD_FIELD:
            if (inputs->catchForce.x) {
                setState(STATE_INCOMPLETE);
            } else {
                if (!params->position_cursor){
                    if (!workSpaceTarget->cursorInTarget(Point(force_to_position*x_force_cursor,force_to_position*y_force_cursor))){
                        playTone(TONE_ABORT);
                        setState(STATE_ABORT);				
                    } else if (centerTarget->cursorInTarget(Point(force_to_position*x_force_cursor,force_to_position*y_force_cursor))){
                        setState(STATE_CT_HOLD);
                    }
                } else {
                    if (!workSpaceTarget->cursorInTarget(inputs->cursor - Point(cursor_offset.x*zero_for_debugging,cursor_offset.y*zero_for_debugging))){
                        playTone(TONE_ABORT);
                        setState(STATE_ABORT);				
                    } else if (centerTarget->cursorInTarget(inputs->cursor - Point(cursor_offset.x*zero_for_debugging,cursor_offset.y*zero_for_debugging))){
                        setState(STATE_CT_HOLD);
                    }
                }
            }
            break;
        case STATE_CT_HOLD:
            if (inputs->catchForce.x) {
                setState(STATE_INCOMPLETE);
            } else {
                if (stateTimer->elapsedTime(S) > field_hold_time && !params->position_cursor){
                    bump->start(S);
                    infinite_bump->start(S);
                    setState(STATE_BUMP);
                } else if (stateTimer->elapsedTime(S) > field_hold_time && forceTarget->cursorInTarget(Point(x_force_field,y_force_field))){
                    bump->start(S);
                    infinite_bump->start(S);
                    setState(STATE_BUMP);
                } else {
                    if (!params->position_cursor){
                        if (!centerTarget->cursorInTarget(Point(force_to_position*x_force_cursor,force_to_position*y_force_cursor))){
                            setState(STATE_HOLD_FIELD);
                        }
                    } else {
                        if (!centerTarget->cursorInTarget(inputs->cursor - Point(cursor_offset.x*zero_for_debugging,cursor_offset.y*zero_for_debugging))){
                            setState(STATE_HOLD_FIELD);
                        }
                    }
                }
            }
            break;
        case STATE_BUMP:
            if (inputs->catchForce.x) {
                setState(STATE_INCOMPLETE);
            } else {
                if (stateTimer->elapsedTime(S) > params->bump_duration){
                    playTone(TONE_REWARD);
                    setState(STATE_REWARD);
                }
            }
            break;
        case STATE_REWARD:
            if (stateTimer->elapsedTime(S) > params->reward_wait){
                setState(STATE_PRETRIAL);
            }
            break;
        case STATE_ABORT:
            if (stateTimer->elapsedTime(S) > params->abort_wait){
                trial_counter--;
                setState(STATE_PRETRIAL);
            }
            break;
        case STATE_INCOMPLETE:
            this->bump->stop();
            this->infinite_bump->stop();
            if (inputs->catchForce.x){
                // Stay in this state until handle is back in workspace.
            } else if (stateTimer->elapsedTime(S) > params->reward_wait) {
                trial_counter--;
                setState(STATE_PRETRIAL);
            }
			break;
        default:
            setState(STATE_PRETRIAL);
    }
    
}

void AttentionBehavior::calculateOutputs(SimStruct *S) {
    real_T zero_for_debugging = 0.0;
    
    real_T x_force_bump;
    real_T y_force_bump;
            
    // Velocity bump P,D values
    real_T D_gain_vel = params->controller_damping_ratio;
    real_T x_acc = (x_vel - x_vel_old)/.001;
    real_T y_acc = (y_vel - y_vel_old)/.001;   
    
    // Position bump
    x_force_bump = (params->bump_velocity*cos(bump_direction)-x_vel)*params->P_gain_vel - x_acc*cos(bump_direction)*D_gain_vel +
            (desired_x_pos - inputs->cursor.x) * params->P_gain_pos;
    y_force_bump = (params->bump_velocity*sin(bump_direction)-y_vel)*params->P_gain_vel - y_acc*sin(bump_direction)*D_gain_vel +
            (desired_y_pos - inputs->cursor.y) * params->P_gain_pos;
    
    if (isNewState() && getState() == STATE_BUMP){
		x_force_at_bump_start = x_force_field;
		y_force_at_bump_start = y_force_field;
        x_pos_at_bump_start = inputs->cursor.x;
        y_pos_at_bump_start = inputs->cursor.y;
	}
    
    if (getState() == STATE_BUMP){
        desired_x_pos = x_pos_at_bump_start + params->bump_velocity * stateTimer->elapsedTime(S)/.001 * cos(bump_direction);
        desired_y_pos = y_pos_at_bump_start + params->bump_velocity * stateTimer->elapsedTime(S)/.001 * sin(bump_direction);
    }
    
	switch (this->getState()){
		case STATE_FIELD_BUILD_UP:
			ratio_force = stateTimer->elapsedTime(S) / params->field_ramp_up;
			outputs->force.x = ratio_force * x_force_field;
			outputs->force.y = ratio_force * y_force_field;
			break;
		case STATE_HOLD_FIELD:
		case STATE_CT_HOLD:
			outputs->force.x = x_force_field;
			outputs->force.y = y_force_field;
			break;
		case STATE_BUMP:            
            if(params->force_bump){
                outputs->force = bump->getBumpForce(S);
                outputs->force += infinite_bump->getBumpForce(S);
                outputs->force.x += x_force_at_bump_start;
                outputs->force.y += y_force_at_bump_start;
            } else {            
                outputs->force.x = x_force_bump;
                outputs->force.y = y_force_bump;
            }                        
			break;
        case STATE_REWARD:
        case STATE_ABORT:
            outputs->force.x = -x_vel*0.012;
            outputs->force.y = -y_vel*0.012;
            break;
		default:
			outputs->force = Point(0,0);
	}        
		
	/* status (1) */
	outputs->status[0] = getState();
	outputs->status[1] = trialCounter->successes;
	outputs->status[2] = trialCounter->aborts;
	outputs->status[3] = floor(180*bump_direction/PI);	
	outputs->status[4] = floor(180*field_angle/PI);
    
//     outputs->status[3] = x_force_neg_stiffness*100;
//     outputs->status[4] = y_force_neg_stiffness*100;
 	
	/* word (2) */
	if (db->isRunning()) {
		outputs->word = db->getByte();
	} else if (isNewState()) {
		switch (getState()) {
			case STATE_PRETRIAL:
				outputs->word = WORD_START_TRIAL;           // 0x1F = 31  
                lastWord = WORD_START_TRIAL;
				break;
            case STATE_START_RECORDING:
				outputs->word = WORD_START_RECORDING;        // 0x91 = 145  
                lastWord = WORD_START_RECORDING;
				break;
            case STATE_STOP_RECORDING:
				outputs->word = WORD_STOP_RECORDING;         // 0x92 = 146  
                lastWord = WORD_STOP_RECORDING;
				break;              
			case STATE_CENTER_TARGET_ON:
				outputs->word = WORD_CT_ON;                 // 0x30 = 48
                lastWord = WORD_CT_ON;
				break;
			case STATE_FIELD_BUILD_UP:
				outputs->word = WORD_FIELD_BUILDING_UP;     // 0x31 = 49
                lastWord = WORD_FIELD_BUILDING_UP;
				break;
			case STATE_CT_HOLD:
				outputs->word = WORD_CENTER_TARGET_HOLD;    // 0xA0 = 160
                lastWord = WORD_CENTER_TARGET_HOLD;
				break;			
			case STATE_BUMP:
				outputs->word = WORD_BUMP(0);               // 0x50 = 80
                lastWord = WORD_BUMP(0);
				break;			
			case STATE_REWARD:
				outputs->word = WORD_REWARD;                // 0x20 = 32
                lastWord = WORD_REWARD;
				break;
			case STATE_ABORT:
				outputs->word = WORD_ABORT;                 // 0x21 = 33
                lastWord = WORD_ABORT;
				break;			
			default:
				outputs->word = 0;
		}
	} else {
		outputs->word = 0;
	}

	/* targets (3) */
	switch (this->getState()){
		case STATE_CENTER_TARGET_ON:
			outputs->targets[0] = (Target *)centerTarget;
			outputs->targets[1] = nullTarget;
            outputs->targets[2] = nullTarget;
			break;
		case STATE_FIELD_BUILD_UP:
		case STATE_HOLD_FIELD:
		case STATE_CT_HOLD:
			outputs->targets[0] = (Target *)workSpaceTarget;
			outputs->targets[1] = (Target *)centerTarget;
            if (params->position_cursor){
                outputs->targets[2] = (Target *)forceFeedbackTarget;
            } else {
                outputs->targets[2] = nullTarget;
            }
			break;
		default:
			outputs->targets[0] = nullTarget;
			outputs->targets[1] = nullTarget;
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
    switch (this->getState()){
		case STATE_FIELD_BUILD_UP:
            if (!params->position_cursor){
                ratio_force = stateTimer->elapsedTime(S) / params->field_ramp_up;
                outputs->position.x = force_to_position * ratio_force * x_force_cursor;
                outputs->position.y = force_to_position * ratio_force * y_force_cursor;
            } else {                
                outputs->position.x = inputs->cursor.x - params->x_position_offset - zero_for_debugging*cursor_offset.x;
                outputs->position.y = inputs->cursor.y - params->y_position_offset - zero_for_debugging*cursor_offset.y;
            }
			break;
		case STATE_HOLD_FIELD:
		case STATE_CT_HOLD:
            if (!params->position_cursor){
                outputs->position.x = force_to_position * x_force_cursor;
                outputs->position.y = force_to_position * y_force_cursor;
            } else {                
                outputs->position.x = inputs->cursor.x - params->x_position_offset - zero_for_debugging*cursor_offset.x;
                outputs->position.y = inputs->cursor.y - params->y_position_offset - zero_for_debugging*cursor_offset.y;
            }
			break;
		case STATE_BUMP:
			outputs->position = Point(1E6, 1E6);
			break;
		default:
            if (!params->position_cursor){
                outputs->position = inputs->cursor;
            } else {
                outputs->position = inputs->cursor - Point(cursor_offset.x*zero_for_debugging,cursor_offset.y*zero_for_debugging);
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

