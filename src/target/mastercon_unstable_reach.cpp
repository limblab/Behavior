/* $Id: $
 *
 * Master Control block for behavior: unstable reach
 */

#define DATABURST_VERSION ((byte)0x01) 
/* 
 * Current Databurst version: 1
 *
 * Note that all databursts are encoded half a byte at a time as a word who's 
 * high order bits are all 1 and who's low order bits represent the half byte to
 * be transmitted.  Low order bits are transmitted first.  Thus to transmit the
 * two bytes 0xCF 0x07, one would send 0xFF 0xFC 0xF7 0xF0.
 *
 * Databurst version descriptions
 * ==============================
 *
 * * Version 0 (0x00)
 * ----------------
 * byte         0: uchar    => number of bytes to be transmitted
 * byte         1: uchar    => databurst version number (in this case zero)
 * byte         2: uchar    => model version major
 * byte         3: uchar    => model version minor
 * bytes   4 to 5: short    => model version micro
 * bytes   6 to 9: float    => x offset (cm)
 * bytes 10 to 13: float    => y offset (cm)
 * bytes 14 to 17: float    => movement direction (rad)
 * bytes 18 to 21: float    => trial stiffness (N/cm)
 * bytes 22 to 25: float    => target radius (cm)
 * bytes 26 to 29: float    => movement distance (cm)
 * byte        30: int      => brain control (if 1: yes)
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
 * bytes 14 to 17: float    => movement direction (rad)
 * bytes 18 to 21: float    => trial stiffness (N/cm)
 * bytes 22 to 25: float    => target radius (cm)
 * bytes 26 to 29: float    => movement distance (cm)
 * byte        30: int      => brain control (if 1: yes)
 * bytes 31 to 34: float    => curve displacement (cm)
 * bytes 35 to 38: float    => curve displacement direction
 */

#define S_FUNCTION_NAME mastercon_unstable_reach
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
#define STATE_OT_ON     			 4
#define STATE_WAIT_FOR_MOVEMENT      5
#define STATE_MOVEMENT               6
#define STATE_OT_HOLD                7
#define STATE_START_RECORDING        8
#define STATE_STOP_RECORDING         9

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
    real_T outer_hold;
	real_T reward_wait;
	real_T abort_wait;
    real_T fail_wait;
    real_T movement_time;

    // Cursor
    real_T brain_control;
    
	// Targets
	real_T target_radius;
	real_T movement_distance;  
    real_T color_cue;
        
    // Field
    real_T field_stiffness_1;  
    real_T field_stiffness_2;
    real_T field_stiffness_3;
    real_T percent_stiffness_1;
    real_T percent_stiffness_2;
    real_T damping;
    real_T first_movement_direction;
    real_T num_movement_directions;    
    real_T trial_block_size;
            
    // Velocity controller parameters
    real_T vel_filt;
    real_T pos_filt;  
    
    // Cerebus recording stuff
    real_T record;
    real_T record_for_x_mins;
    
    // Curved field stuff
    real_T min_curve_displacement;
    real_T max_curve_displacement;
    real_T num_curve_displacements;        
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME UnstableReach
class UnstableReach : public RobotBehavior {
public:
	// You must implement these three public methods
	UnstableReach(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables    
	CircleTarget *centerTarget;	
	CircleTarget *outerTarget;	   
    CircleTarget *lowerArm[5];
    CircleTarget *upperArm[5];    
    
	LocalParams *params;	

	real_T center_hold_time;
	real_T movement_direction;
    real_T field_stiffness;
    
    Point cursor_velocity;
    Point cursor_velocity_old;
    
    Point cursor_position;
    Point cursor_position_old;
    Point force;        
    
    Point shoulder_pos;
    Point elbow_pos;
    
    int trial_counter;
    int stiffness_order [3];
    int stiffness_order_percent [3];
    real_T stiffnesses[3];
    real_T trial_stiffness;
    int stiffness_index;
    int old_block_length;
    int movement_direction_index;
    int target_colors[4];    
    int target_color;
    real_T debug_var;  
    real_T curve_displacement;
    real_T curve_direction;
    int curve_counter;
//     int curve_order[16];
    real_T curve_list[16];
    
	// any helper functions you need
	void doPreTrial(SimStruct *S);    
    Timer *recordingTimer;   
              
};

UnstableReach::UnstableReach(SimStruct *S) : RobotBehavior() {

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(28);
	// Identify each bound variable 
    this->bindParamId(&params->master_reset,                            0);
	this->bindParamId(&params->center_hold_low,                         1);
	this->bindParamId(&params->center_hold_high,                        2);
	this->bindParamId(&params->outer_hold,                              3);
	this->bindParamId(&params->reward_wait,                             4);
	this->bindParamId(&params->abort_wait,								5);
	this->bindParamId(&params->fail_wait,								6);
    this->bindParamId(&params->movement_time,							7);
    
    this->bindParamId(&params->brain_control,                           8);
    
    this->bindParamId(&params->target_radius,                           9);
    this->bindParamId(&params->movement_distance,                       10);
    this->bindParamId(&params->color_cue,                               11);
    
    this->bindParamId(&params->field_stiffness_1,                       12);
    this->bindParamId(&params->field_stiffness_2,                       13);
    this->bindParamId(&params->field_stiffness_3,                       14);
    this->bindParamId(&params->percent_stiffness_1,                     15);
    this->bindParamId(&params->percent_stiffness_2,                     16);
    this->bindParamId(&params->damping,                                 17);
    
    this->bindParamId(&params->first_movement_direction,                18);
    this->bindParamId(&params->num_movement_directions,                 19);
    this->bindParamId(&params->trial_block_size,                        20);
    
    this->bindParamId(&params->vel_filt,                                21);
    this->bindParamId(&params->pos_filt,                                22);
    
    this->bindParamId(&params->record,                                  23);
    this->bindParamId(&params->record_for_x_mins,                       24);
    
    this->bindParamId(&params->min_curve_displacement,                  25);
    this->bindParamId(&params->max_curve_displacement,                  26);
    this->bindParamId(&params->num_curve_displacements,                 27);
  
    // default parameters:
    // 0 1 2 1 1 1 1 30   0   2 15 1   .5 0 -.5 33 33 .05   0 8 10   1 1   0 0   0 2 3
    
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
  
	centerTarget = new CircleTarget();
	centerTarget->color = Target::Color(255,0,0);	
    
    outerTarget = new CircleTarget();
    outerTarget->color = Target::Color(255,0,0);
    
    for (int i=0; i<5; i++) {
		lowerArm[i] = new CircleTarget(0,0,.3,0);
        lowerArm[i]->color = Target::Color(80,80,80);
        upperArm[i] = new CircleTarget(0,0,.3,0);
        upperArm[i]->color = Target::Color(80,80,80);
	}

    center_hold_time = 0.0;
	movement_direction = 0.0;
    field_stiffness = 0.0;
    
    cursor_position = Point(0,0);
    cursor_position_old = Point(0,0);
    cursor_velocity = Point(0,0);
    cursor_velocity_old = Point(0,0);
    force = Point(0,0);
    
    shoulder_pos = Point(0,0);
    elbow_pos = Point(0,0);
        
    recordingTimer = new Timer();
    
    debug_var = 0.0;
        
    old_block_length = -10;
    trial_counter = 10000;
    stiffness_index = 0;
    movement_direction_index = random->getInteger(0,100);
    
    target_color = Target::Color(117,140,0);
    target_colors[0] = Target::Color(50,50,255);
    target_colors[1] = Target::Color(50,200,50);
    target_colors[2] = Target::Color(255,166,0);
    target_colors[3] = Target::Color(230,0,0);
    
    curve_displacement = 0;
    curve_counter = 10000;
    curve_direction = 1;
}

void UnstableReach::doPreTrial(SimStruct *S) {
    double tmp_sort[16];
    double tmp_d;
    int tmp;
        
	centerTarget->radius = params->target_radius;
    outerTarget->radius = params->target_radius;
      
    trial_counter++;  
           
    if (trial_counter >= params->trial_block_size || old_block_length != params->trial_block_size){
        trial_counter = 0;
        stiffness_index = 0;
        movement_direction_index++;
        old_block_length = params->trial_block_size;
        
        // Stiffness order         

        for (int i=0; i<3; i++){
            stiffness_order[i] = i;            
            tmp_sort[i] = random->getDouble(0,1);
        }
        stiffness_order_percent[0] = params->percent_stiffness_1;
        stiffness_order_percent[1] = params->percent_stiffness_2;
        stiffness_order_percent[2] = 100-(params->percent_stiffness_1+params->percent_stiffness_2);
        
        stiffnesses[0] = params->field_stiffness_1;
        stiffnesses[1] = params->field_stiffness_2;
        stiffnesses[2] = params->field_stiffness_3;

        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (tmp_sort[j] < tmp_sort[j+1]){
                    tmp_d = tmp_sort[j];
                    tmp_sort[j] = tmp_sort[j+1];
                    tmp_sort[j+1] = tmp_d;

                    tmp = stiffness_order[j];
                    stiffness_order[j] = stiffness_order[j+1];                    
                    stiffness_order[j+1] = tmp;
                    
                    tmp = stiffness_order_percent[j];
                    stiffness_order_percent[j] = stiffness_order_percent[j+1];
                    stiffness_order_percent[j+1] = tmp;
                }
            }
        }
    }
    
    // Select movement direction
    movement_direction = fmod(movement_direction_index * 2 * PI/(params->num_movement_directions) + 
        params->first_movement_direction,2*PI);
    
    // Select stiffness
    if ((stiffness_index == 0) &&
            ((100*trial_counter/params->trial_block_size) >= (stiffness_order_percent[0]-1))){
        stiffness_index = 1;
        if (stiffness_order_percent[1]==0)
            stiffness_index = 2;
    } else if ((stiffness_index == 1) &&
            ((100*trial_counter/params->trial_block_size) >= (stiffness_order_percent[0]+stiffness_order_percent[1]-1))){
        stiffness_index = 2;
        if (stiffness_order_percent[2]==0)
            stiffness_index = 0;
    } else if ((stiffness_index == 2) &&
            ((100*trial_counter/params->trial_block_size) >= 100)){
        stiffness_index = 0;
        if (stiffness_order_percent[0]==0)
            stiffness_index = 1;
    }
    trial_stiffness = stiffnesses[stiffness_order[stiffness_index]];
    
    // Curvature
    if (curve_counter >= params->num_curve_displacements){
        for (int i=0; i<params->num_curve_displacements; i++){
            curve_list[i] = i*(params->max_curve_displacement - params->min_curve_displacement)/
                    (params->num_curve_displacements-1) + params->min_curve_displacement;
            tmp_sort[i] = random->getDouble(0,1);
        }
        for (int i=0; i<params->num_curve_displacements; i++){
            for (int j=0; j<params->num_curve_displacements; j++){
                if (tmp_sort[j] < tmp_sort[j+1]){
                    tmp_d = tmp_sort[j];
                    tmp_sort[j] = tmp_sort[j+1];
                    tmp_sort[j+1] = tmp_d;
                    
                    tmp = curve_list[j];
                    curve_list[j] = curve_list[j+1];
                    curve_list[j+1] = tmp;
                }
            }
        }
        curve_counter = 0;
    }
    curve_displacement = curve_list[curve_counter++];    
    curve_direction = random->getDouble(0,1) > 0.5 ? 1 : -1;
    
    // Targets
    if (params->color_cue){
        target_color = target_colors[stiffness_order[stiffness_index]];
    } else {
        target_color = target_colors[3];
    }
    centerTarget->color = target_color;
    outerTarget->color = target_color;
    
    centerTarget->centerX = cos(movement_direction+PI) * params->movement_distance/2;
    centerTarget->centerY = sin(movement_direction+PI) * params->movement_distance/2;
    outerTarget->centerX = cos(movement_direction) * params->movement_distance/2;
    outerTarget->centerY = sin(movement_direction) * params->movement_distance/2;
        
	center_hold_time = this->random->getDouble(params->center_hold_low,params->center_hold_high);

	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);								// byte 1 -> Matlab idx 2
	db->addByte(BEHAVIOR_VERSION_MAJOR);						// byte 2 -> Matlab idx 3
    db->addByte(BEHAVIOR_VERSION_MINOR);						// byte 3 -> Matlab idx 4
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);		// byte 4 -> Matlab idx 5
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);				// byte 5 -> Matlab idx 6
	db->addFloat((float)(inputs->offsets.x));					// bytes 6 to 9 -> Matlab idx 7 to 10
	db->addFloat((float)(inputs->offsets.y));					// bytes 10 to 13 -> Matlab idx 11 to 14
	db->addFloat((float)movement_direction);                    // bytes 14 to 17 -> Matlab idx 15 to 18
    db->addFloat((float)trial_stiffness);                       // bytes 18 to 21 -> Matlab idx 19 to 22
	db->addFloat((float)params->target_radius);                 // bytes 22 to 25 -> Matlab idx 23 to 26
	db->addFloat((float)params->movement_distance);             // bytes 26 to 29 -> Matlab idx 27 to 30	    
    db->addByte((int)params->brain_control);                    // byte 30        -> Matlab idx 31
    db->addFloat((float)curve_displacement);                    // bytes 31 to 34 -> Matlab idx 32 to 35
    db->addFloat((float)curve_direction);                       // bytes 35 to 38 -> Matlab idx 36 to 39
	db->start();
}

void UnstableReach::update(SimStruct *S) {       
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
                if (centerTarget->cursorInTarget(cursor_position)) {
                    setState(STATE_CT_HOLD);
                }
            }
            break;
        case STATE_CT_HOLD:
            if (inputs->catchForce.x  && !params->brain_control) {
                setState(STATE_INCOMPLETE);
            } else {
                if (!centerTarget->cursorInTarget(cursor_position)){
                    playTone(TONE_ABORT);
                    setState(STATE_ABORT);				
                } else if (stateTimer->elapsedTime(S) > params->center_hold_low){
                    setState(STATE_OT_ON);
                }
            }
            break;
        case STATE_OT_ON:
            if (inputs->catchForce.x && !params->brain_control) {
                setState(STATE_INCOMPLETE);
            } else {
                if (!centerTarget->cursorInTarget(cursor_position)){
                    playTone(TONE_ABORT);
                    setState(STATE_ABORT);				
                } else if (stateTimer->elapsedTime(S) > center_hold_time){
                    playTone(TONE_GO);
                    setState(STATE_WAIT_FOR_MOVEMENT);
                }
            }
            break;   
        case STATE_WAIT_FOR_MOVEMENT:
            if (inputs->catchForce.x && !params->brain_control) {
                setState(STATE_INCOMPLETE);
            } else {
                if (!centerTarget->cursorInTarget(cursor_position)){
                    setState(STATE_MOVEMENT);
                }
            }
            break; 
        case STATE_MOVEMENT:
            if (inputs->catchForce.x && !params->brain_control) {
                setState(STATE_INCOMPLETE);
            } else {
                if (params->movement_time > 0 && 
                        (stateTimer->elapsedTime(S) > params->movement_time)){
                    setState(STATE_INCOMPLETE);
                } else if (outerTarget->cursorInTarget(cursor_position)){
                    setState(STATE_OT_HOLD);
                }
            }
            break;        
        case STATE_OT_HOLD:           
            if (stateTimer->elapsedTime(S) > params->outer_hold){
                playTone(TONE_REWARD);
                setState(STATE_REWARD);
            } else if (!outerTarget->cursorInTarget(cursor_position)){
                setState(STATE_FAIL);
            }
            break;
        case STATE_REWARD:
            if (stateTimer->elapsedTime(S) > params->reward_wait){                
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

void UnstableReach::calculateOutputs(SimStruct *S) {  
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
    
    real_T center_offset = (curve_displacement*curve_displacement - 
                    ((params->movement_distance/2)*(params->movement_distance/2)))/
                    (2*params->movement_distance/2);
    real_T curve_radius = ((params->movement_distance/2)*(params->movement_distance/2) +
                    curve_displacement*curve_displacement)/
                    (2*curve_displacement);
    
    Point curve_center;
    curve_center.x = sin(movement_direction + PI*(curve_direction+1)/2)*(curve_radius - curve_displacement);
    curve_center.y = cos(movement_direction + PI*(curve_direction+1)/2)*(curve_radius - curve_displacement);
    
    real_T distance_cursor_to_center = sqrt(
            (curve_center.x - cursor_position.x)*(curve_center.x - cursor_position.x) +
            (curve_center.y - cursor_position.y)*(curve_center.y - cursor_position.y));
    real_T distance_cursor_to_arc = abs(abs(curve_radius) - distance_cursor_to_center);
    real_T force_angle = atan2(cursor_position.y-curve_center.y,cursor_position.x-curve_center.x);
    
    real_T inside_circle = distance_cursor_to_center < abs(curve_radius) ? 1 : -1;    
    force_angle = (inside_circle == 1) ? force_angle+PI : force_angle;    
    
    real_T target_angle_bound_1 = atan2(centerTarget->centerY - curve_center.y,
            centerTarget->centerX - curve_center.x);
    while (target_angle_bound_1 < 0)
        target_angle_bound_1 = target_angle_bound_1 + 2*PI;
    
    real_T target_angle_bound_2 = atan2(outerTarget->centerY - curve_center.y,
            outerTarget->centerX - curve_center.x);
    while (target_angle_bound_2 < 0)
        target_angle_bound_2 = target_angle_bound_2 + 2*PI;
    
    if (target_angle_bound_2 < target_angle_bound_1){
        real_T temp_angle = target_angle_bound_1;
        target_angle_bound_1 = target_angle_bound_2;
        target_angle_bound_2 = temp_angle;
    }
    
    target_angle_bound_2 = target_angle_bound_2 - target_angle_bound_1;
    while (target_angle_bound_2 < 0)
        target_angle_bound_2 = target_angle_bound_2 + 2*PI;
    
    real_T cursor_angle = atan2(cursor_position.y-curve_center.y,cursor_position.x-curve_center.x);
    cursor_angle = cursor_angle - target_angle_bound_1;
    while (cursor_angle < 0)
        cursor_angle = cursor_angle + 2*PI;
    
    real_T within_angle;
    if (cursor_angle < target_angle_bound_2 && curve_direction == 1 || 
           cursor_angle > target_angle_bound_2 && curve_direction == -1 ){
        within_angle = 1;
    } else {
        within_angle = 0;
    }
    
    real_T damping_axis_angle = atan2(cursor_position.y-curve_center.y,cursor_position.x-curve_center.x);
    
    if (curve_displacement == 0 || !within_angle){
        force.x = -trial_stiffness*(cursor_position.x * cos(movement_direction+PI/2) +
                    cursor_position.y * sin(movement_direction+PI/2)) * cos(movement_direction+PI/2) -
                    (trial_stiffness>0 ? params->damping*(cursor_velocity.x * cos(movement_direction+PI/2) + 
                    cursor_velocity.y * sin(movement_direction+PI/2)) * cos(movement_direction+PI/2) : 0);        
        force.y = -trial_stiffness*(cursor_position.x*cos(movement_direction+PI/2) + 
                    cursor_position.y * sin(movement_direction+PI/2)) * sin(movement_direction+PI/2) -
                    (trial_stiffness>0 ? params->damping*(cursor_velocity.x * cos(movement_direction+PI/2) + 
                    cursor_velocity.y * sin(movement_direction+PI/2)) * sin(movement_direction+PI/2) : 0);    
    } else {
        force.x = -trial_stiffness*distance_cursor_to_arc*cos(force_angle) -
                (trial_stiffness>0 ? params->damping*(cursor_velocity.x * cos(damping_axis_angle) + 
                    cursor_velocity.y * sin(damping_axis_angle)) * cos(damping_axis_angle) : 0);  
        force.y = -trial_stiffness*distance_cursor_to_arc*sin(force_angle) -
                (trial_stiffness>0 ? params->damping*(cursor_velocity.x * cos(damping_axis_angle) + 
                    cursor_velocity.y * sin(damping_axis_angle)) * sin(damping_axis_angle) : 0); 
    }
            
    
   
    if (getState()==STATE_CT_HOLD || 
            getState()==STATE_OT_ON ||
            getState()==STATE_WAIT_FOR_MOVEMENT ||
            getState()==STATE_MOVEMENT || 
            getState()==STATE_OT_HOLD){
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
    
    outputs->status[0] = within_angle;
	outputs->status[1] = target_angle_bound_1*180/PI;
	outputs->status[2] = target_angle_bound_2*180/PI;
	outputs->status[3] = cursor_angle * 180/PI;
	outputs->status[4] = 0;  
    
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
            case STATE_OT_ON:
                outputs->word = WORD_OT_ON(0);              // 0x40 = 64
                break;
			case STATE_MOVEMENT:
				outputs->word = WORD_MOVEMENT_ONSET;        // 0x80 = 128
                break;
            case STATE_WAIT_FOR_MOVEMENT:
                outputs->word = WORD_GO_CUE;                     // 0x31 = 49
                break;
            case STATE_OT_HOLD:
                outputs->word = WORD_OUTER_TARGET_HOLD;     // 0xA1 = 161
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
            outputs->targets[10] = (Target *)centerTarget;
			outputs->targets[11] = nullTarget;
			break;
        case STATE_CT_HOLD: 
            outputs->targets[10] = (Target *)centerTarget;
			outputs->targets[11] = nullTarget;
			break;
		case STATE_OT_ON: 
            outputs->targets[10] = (Target *)centerTarget;
			outputs->targets[11] = (Target *)outerTarget;
			break;             
        case STATE_WAIT_FOR_MOVEMENT:
        case STATE_MOVEMENT:
        case STATE_OT_HOLD:
            outputs->targets[10] = (Target *)outerTarget;
			outputs->targets[11] = nullTarget;
			break;       
		default:
            outputs->targets[10] = nullTarget;
			outputs->targets[11] = nullTarget;
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

