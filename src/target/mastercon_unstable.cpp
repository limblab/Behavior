/* $Id: $
 *
 * Master Control block for behavior: unstable field
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
 */

#define S_FUNCTION_NAME mastercon_unstable
#define S_FUNCTION_LEVEL 2

// Our task code will be in the databurst
#define TASK_UF 1
#include "words.h"

#include "common_header.cpp"

/*
 * State IDs
 */
#define STATE_PRETRIAL				 0
#define STATE_CENTER_TARGET_ON		 1

/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */

#define DATABURST_VERSION ((byte)0x00) 

// This must be custom defined for your behavior
struct LocalParams{
	real_T master_reset;

	// Unstable field
	real_T negative_stiffness;
	real_T positive_stiffness;
	real_T field_angle;
	real_T x_position_offset;
	real_T y_position_offset;
	real_T x_force_offset;
	real_T y_force_offset;
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
	LocalParams *params;	
	// any helper functions you need
};

AttentionBehavior::AttentionBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(8);
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,							 0);
	this->bindParamId(&params->negative_stiffness,						 1);
	this->bindParamId(&params->positive_stiffness,						 2);
	this->bindParamId(&params->field_angle,								 3);
	this->bindParamId(&params->x_position_offset,						 4);
	this->bindParamId(&params->y_position_offset,						 5);
    this->bindParamId(&params->x_force_offset,							 6);
	this->bindParamId(&params->y_force_offset,							 7);
    
    // default parameters:
    // 5 5 0 0 0 1 1 
    
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
		
	centerTarget = new SquareTarget();
	centerTarget->color = Target::Color(0,255,255);	
}

void AttentionBehavior::doPreTrial(SimStruct *S) {
	
	centerTarget->centerX = params->x_position_offset;
	centerTarget->centerY = params->y_position_offset;
	centerTarget->width = 4;

}

void AttentionBehavior::update(SimStruct *S) {
	//int i;
	// State machine
	switch (this->getState()) {
		case STATE_PRETRIAL:
            updateParameters(S);
            doPreTrial(S);
            setState(STATE_CENTER_TARGET_ON);
			break;		
		case STATE_CENTER_TARGET_ON:
			/* first target on */
			if (stateTimer->elapsedTime(S) > 2) {				
				setState(STATE_PRETRIAL);
			}
			break;		
		default:
			setState(STATE_PRETRIAL);
	}
}

void AttentionBehavior::calculateOutputs(SimStruct *S) {

	/* force (0) */
	outputs->force = inputs->force;

	outputs->force.X += params->negative_stiffness*((inputs->cursor.X - params->x_position_offset)*cos(params->field_angle) +
					    (inputs->cursor.Y - params->y_position_offset)*sin(params->field_angle))*cos(params->field_angle) + 
						params->positive_stiffness*(-(inputs->cursor.X - params->x_position_offset)*sin(params->field_angle) + 
						(inputs->cursor.Y - params->y_position_offset)*cos(params->field_angle))*sin(params->field_angle) + params->x_force_offset;

	outputs->force.Y = params->negative_stiffness*((inputs->cursor.X-params->x_position_offset)*cos(params->field_angle) + 
						(inputs->cursor.Y-params->y_position_offset)*sin(params->field_angle))*sin(params->field_angle) -
						params->positive_stiffness*(-(inputs->cursor.X - params->x_position_offset)*sin(params->field_angle) + 
						(inputs->cursor.Y-params->y_position_offset)*cos(params->field_angle))*cos(params->field_angle) + params->y_force_offset;
	
	/* status (1) */
	outputs->status[0] = getState();
	outputs->status[1] = 0;
	outputs->status[2] = 0;
	outputs->status[3] = 0;	
	outputs->status[4] = 0;    	
 	
 	outputs->targets[0] = (Target *)centerTarget;
	outputs->targets[1] = nullTarget;
 	
	/* version (6) */
	outputs->version[0] = BEHAVIOR_VERSION_MAJOR;
	outputs->version[1] = BEHAVIOR_VERSION_MINOR;
	outputs->version[2] = BEHAVIOR_VERSION_MICRO;
	outputs->version[3] = BEHAVIOR_VERSION_BUILD;

	/* position (7) */    
    outputs->position = inputs->cursor;    

}

/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"

