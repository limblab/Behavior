/* $Id: $
 *
 * Master Control block for behavior: dynamic center out
 */

#define DATABURST_VERSION ((byte)0x00) 
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
 * * Version 0 (0x00)
 * ----------------
 * byte         0: uchar    => number of bytes to be transmitted
 * byte         1: uchar    => databurst version number (in this case zero)
 * byte         2: uchar    => model version major
 * byte         3: uchar    => model version minor
 * bytes   4 to 5: short    => model version micro
 * bytes   6 to 9: float    => x offset (cm)
 * bytes 10 to 13: float    => y offset (cm)
 * bytes 14 to 17: float    => outer target direction (rad)
 * bytes 30 to 33: float    => outer target radius (cm)
 * bytes 34 to 37: float    => outer target span (cm)
 * bytes 38 to 41: float    => outer target thickness (cm)
 * bytes 18 to 21: float    => outer target stiffness (N/cm)
 * bytes 22 to 25: float    => min target force (N)
 * bytes 26 to 29: float    => max target force (N)
 * bytes 30 to 33: float    => cursor radius (cm)
 * byte        34: int      => brain control (if 1: yes)
 */

#define S_FUNCTION_NAME mastercon_dynamic_center_out
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
#define STATE_MOVEMENT               4
#define STATE_OT_HOLD                5
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
    real_T outer_hold;
	real_T reward_wait;
	real_T abort_wait;
    real_T fail_wait;
    real_T movement_time;

    // Cursor
    real_T cursor_radius;
    real_T brain_control;
    
	// Targets
	real_T center_target_radius;
	real_T outer_target_radius;
    real_T outer_target_span;
    real_T outer_target_thickness;
    real_T num_targets;
    real_T target_stiffness;
    real_T target_force_min;
    real_T target_force_max;
    
    // Velocity controller parameters       
    real_T damping;
    real_T vel_filt;
    real_T pos_filt;
    
    // Cerebus recording stuff
    real_T record;
    real_T record_for_x_mins;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME DynamicCenterOut
class DynamicCenterOut : public RobotBehavior {
public:
	// You must implement these three public methods
	DynamicCenterOut(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables    
	CircleTarget *centerTarget;	
	ArcTarget *outerTarget;	
    CircleTarget *cursorTarget;   
    
	LocalParams *params;	

	real_T center_hold_time;
	real_T target_direction;
    
    Point cursor_velocity;
    Point cursor_velocity_old;
    
    Point cursor_position;
    Point cursor_position_old;    
    Point force;
    
	// any helper functions you need
	void doPreTrial(SimStruct *S);
    
    Timer *recordingTimer;   
    
    real_T debug_var;        
    
    int i;
};

DynamicCenterOut::DynamicCenterOut(SimStruct *S) : RobotBehavior() {

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(23);
	// Identify each bound variable 
    this->bindParamId(&params->master_reset,                            0);
	this->bindParamId(&params->center_hold_low,                         1);
	this->bindParamId(&params->center_hold_high,                        2);
	this->bindParamId(&params->outer_hold,                              3);
	this->bindParamId(&params->reward_wait,                             4);
	this->bindParamId(&params->abort_wait,								5);
	this->bindParamId(&params->fail_wait,								6);
    this->bindParamId(&params->movement_time,							7);

	this->bindParamId(&params->cursor_radius,							8);
	this->bindParamId(&params->brain_control,                           9);

	this->bindParamId(&params->center_target_radius,                    10);
	this->bindParamId(&params->outer_target_radius,						11);
	this->bindParamId(&params->outer_target_span,   					12);
	this->bindParamId(&params->outer_target_thickness,                  13);
	this->bindParamId(&params->num_targets,                             14);
    this->bindParamId(&params->target_stiffness,                        15);
	this->bindParamId(&params->target_force_min,                        16);
	this->bindParamId(&params->target_force_max,                        17);
    
	this->bindParamId(&params->damping,                                 18);
	this->bindParamId(&params->vel_filt,                                19);
	this->bindParamId(&params->pos_filt,                                20);
      
    this->bindParamId(&params->record,                                  21);
    this->bindParamId(&params->record_for_x_mins,                       22);    
   
    
    // default parameters:
    // 1  .5 1 .5 1 2 2 10  .5 0  3 8 .5 2 0 50 2 4  0 0 0  0 0
    
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
  
	centerTarget = new CircleTarget();
	centerTarget->color = Target::Color(255,0,0);	
    
    // ArcTarget(double r, double theta, double span, double height, int type);
    outerTarget = new ArcTarget(0,0,0,0,5);
    
	cursorTarget = new CircleTarget();
	cursorTarget->color = Target::Color(255,255,255);

    center_hold_time = 0.0;
	target_direction = 0.0;
    
    cursor_position = Point(0,0);
    cursor_position_old = Point(0,0);
    cursor_velocity = Point(0,0);
    cursor_velocity_old = Point(0,0);
    force = Point(0,0);
        
    recordingTimer = new Timer();
    
    debug_var = 0.0;
        
    i = 0;
}

void DynamicCenterOut::doPreTrial(SimStruct *S) {	
	centerTarget->radius = params->center_target_radius;

    outerTarget->r = params->outer_target_radius;
    outerTarget->span = params->outer_target_span;
	outerTarget->height = params->outer_target_thickness;
    if (params->num_targets == 0){
        target_direction = random->getDouble(0,2*PI);
    } else {
        i = random->getInteger(0,params->num_targets-1);
        target_direction = fmod(i * 2 * PI/params->num_targets,2*PI);
    }
    outerTarget->theta = target_direction;
    
    cursorTarget->centerX = cursor_position.x;
	cursorTarget->centerY = cursor_position.y;
	cursorTarget->radius = params->cursor_radius;
    cursorTarget->color = Target::Color(255,255,255);
        
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
	db->addFloat((float)target_direction);						// bytes 14 to 17 -> Matlab idx 15 to 18
    db->addFloat((float)params->outer_target_radius);           // bytes 18 to 21 -> Matlab idx 19 to 22
	db->addFloat((float)params->outer_target_span);             // bytes 22 to 25 -> Matlab idx 23 to 26
	db->addFloat((float)params->outer_target_thickness);        // bytes 26 to 29 -> Matlab idx 27 to 30
	db->addFloat((float)params->target_stiffness);              // bytes 30 to 33 -> Matlab idx 31 to 34
	db->addFloat((float)params->target_force_min);              // bytes 34 to 37 -> Matlab idx 35 to 38
	db->addFloat((float)params->target_force_max);              // bytes 38 to 41 -> Matlab idx 39 to 42
    db->addFloat((float)params->cursor_radius);                 // bytes 42 to 45 -> Matlab idx 43 to 46
    db->addByte((int)params->brain_control);                    // byte 46        -> Matlab idx 47    
	db->start();
}

void DynamicCenterOut::update(SimStruct *S) {       
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
                if (centerTarget->cursorInTarget(cursor_position)) {
                    setState(STATE_CT_HOLD);
                }
            }
            break;
        case STATE_CT_HOLD:
            if (inputs->catchForce.x) {
                setState(STATE_INCOMPLETE);
            } else {
                if (!centerTarget->cursorInTarget(cursor_position)){
                    playTone(TONE_ABORT);
                    setState(STATE_ABORT);				
                } else if (stateTimer->elapsedTime(S) > center_hold_time){
                    setState(STATE_MOVEMENT);
                }
            }
            break;        
        case STATE_MOVEMENT:
            if (inputs->catchForce.x) {
                setState(STATE_INCOMPLETE);
            } else {
                if (params->movement_time > 0 && 
                        (stateTimer->elapsedTime(S) > params->movement_time)){
                    setState(STATE_FAIL);
                } else if (outerTarget->cursorInTarget(cursor_position)){
                    setState(STATE_OT_HOLD);
                }
            }
            break;        
        case STATE_OT_HOLD:
            if (~outerTarget->cursorInTarget(cursor_position)){
                setState(STATE_MOVEMENT);
            } else {
                if (stateTimer->elapsedTime(S) > params->outer_hold){
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
                setState(STATE_PRETRIAL);
            }
            break;
        case STATE_FAIL:
            if (stateTimer->elapsedTime(S) > params->fail_wait){                
                setState(STATE_PRETRIAL);
            }
            break;
        case STATE_INCOMPLETE:            
            if (inputs->catchForce.x){
                // Stay in this state until handle is back in workspace.
            } else if (stateTimer->elapsedTime(S) > params->reward_wait) {                
                setState(STATE_PRETRIAL);
            }
			break;
        default:
            setState(STATE_PRETRIAL);
    }
    
}

void DynamicCenterOut::calculateOutputs(SimStruct *S) {   
    cursorTarget->centerX = cursor_position.x;
	cursorTarget->centerY = cursor_position.y;
    
    if (params->brain_control){
        cursor_position.x = cursor_position_old.x*(1-params->pos_filt) + 
                inputs->force.x * params->pos_filt; // hacked it to take the neural input through the force port
        cursor_position.y = cursor_position_old.y*(1-params->pos_filt) + 
                inputs->force.y * params->pos_filt; // hacked it to take the neural input through the force port
    } else {
        cursor_position.x = cursor_position_old.x*(1-params->pos_filt) + 
                inputs->cursor.x * params->pos_filt; // hacked it to take the neural input through the force port
        cursor_position.y = cursor_position_old.y*(1-params->pos_filt) + 
                inputs->cursor.y * params->pos_filt; // hacked it to take the neural input through the force port
    }
    
    cursor_velocity.x = cursor_velocity_old.x*(1-params->vel_filt) +
        ((cursor_position.x-cursor_position_old.x)/.001)*params->vel_filt;
    cursor_velocity.y = cursor_velocity_old.y*(1-params->vel_filt) +
        ((cursor_position.y-cursor_position_old.y)/.001)*params->vel_filt;
    
    cursor_position_old = cursor_position;
    cursor_velocity_old = cursor_velocity;   
    
    /* force (0) */ 
    force = Point(0,0);
       
    real_T distance_cursor_target;
    real_T force_angle;
    real_T cursor_red;
    real_T cursor_blue_green;
    real_T target_force;
    real_T force_magnitude;
    
    distance_cursor_target = params->outer_target_radius -
            sqrt(cursor_position.x*cursor_position.x + cursor_position.y*cursor_position.y);
    force_angle = fmod(atan2(cursor_position.y,cursor_position.x) + PI,2*PI);
    force_magnitude = params->target_stiffness * distance_cursor_target;
            
    force.x = force_magnitude * cos(force_angle) + params->damping*(-cursor_velocity.x);
    force.y = force_magnitude * sin(force_angle) + params->damping*(-cursor_velocity.y);
    
    target_force = (params->target_force_min + params->target_force_max)/2;
    real_T b = -2*255/(params->target_force_max - params->target_force_min);
        
    if (outerTarget->cursorInTarget(cursor_position)){
        outputs->force = force;    
        if (force_magnitude > target_force){
            cursor_red = b * force_magnitude + 
                2*255*params->target_force_max/(params->target_force_max - params->target_force_min);            
            cursor_blue_green = 0;
        } else if (force_magnitude < target_force){
            cursor_red = 255;
            cursor_blue_green = b * force_magnitude + 
                2*255*target_force/(params->target_force_max - params->target_force_min);
        }
    } else {
        outputs->force = Point(0,0);
        cursor_red = 255;
        cursor_blue_green = 255;
    }   
    cursor_red = (cursor_red>0)?cursor_red:0;
    cursor_red = (cursor_red<255)?cursor_red:255;
    cursor_blue_green = (cursor_blue_green>0)?cursor_blue_green:0;
    cursor_blue_green = (cursor_blue_green<255)?cursor_blue_green:255;
		
	/* status (1) */
	outputs->status[0] = getState();
	outputs->status[1] = trialCounter->successes;
	outputs->status[2] = trialCounter->aborts;
	outputs->status[3] = trialCounter->failures;
	outputs->status[4] = trialCounter->incompletes;	    
 	
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
			case STATE_MOVEMENT:
				outputs->word = WORD_MOVEMENT_ONSET;        // 0x80 = 128
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
    cursorTarget->color = Target::Color(cursor_red,cursor_blue_green,cursor_blue_green);	
    
	switch (this->getState()){
		case STATE_CENTER_TARGET_ON:
            outputs->targets[0] = (Target *)cursorTarget;
			outputs->targets[1] = (Target *)centerTarget;
			outputs->targets[2] = nullTarget;            
			break;
		case STATE_CT_HOLD: 
        case STATE_MOVEMENT:
        case STATE_OT_HOLD:
            outputs->targets[0] = (Target *)cursorTarget;
			outputs->targets[1] = (Target *)centerTarget;
			outputs->targets[2] = (Target *)outerTarget;
			break;       
		default:
            outputs->targets[0] = (Target *)cursorTarget;
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
    
    /* position (7) (Not using normal cursor with this task) */    
    outputs->position.x = 10000;
    outputs->position.y = 10000;    
}

/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"

