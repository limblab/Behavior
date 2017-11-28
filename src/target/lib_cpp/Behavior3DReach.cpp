/**
 * $Id$
 *
 * Parent class for all robot based c++ behaviors.
 */

#ifndef __COMMON_HEADER_CPP
#error "This file is meant to be included through common_header.cpp."
#endif

/*
 * LED target class definition
 * This class has helper functions that define which LED target to light up and which target is being reached for
 */
class LEDTarget {
    public:
        int target_row;
        int target_col;
        
        // figure out which target is being reached for
        // targetStaircase -> voltage staircase given by arduino to determine target being reached to
        // output -> true means hand is at target
        bool handInTarget(float targetStaircase);

        // set outputs for LEDs
        // u -> pointer to output array to copy into
        void setTargetOutputs(real_T *u);
}

bool LEDTarget::handInTarget(float targetStaircase) {
    double targetVoltageLow;
    double targetVoltageHigh;

    if (this->target_row == 1 && this->target_col == 1){
        targetVoltageLow = 0.4;
        targetVoltageHigh = 0.8;
    } else if (this->target_row == 1 && this->target_col == 2){
        targetVoltageLow = 1;
        targetVoltageHigh = 1.5;
    } else if (this->target_row == 1 && this->target_col == 3){
        targetVoltageLow = 1.7;
        targetVoltageHigh = 2.1;
    } else if (this->target_row == 2 && this->target_col == 1){
        targetVoltageLow = 2.3;
        targetVoltageHigh = 2.7;
    } else if (this->target_row == 2 && this->target_col == 3){
        targetVoltageLow = 3;
        targetVoltageHigh = 3.4;
    } else if (this->target_row == 3 && this->target_col == 1){
        targetVoltageLow = 3.6;
        targetVoltageHigh = 4;
    } else if (this->target_row == 3 && this->target_col == 2){
        targetVoltageLow = 4.2;
        targetVoltageHigh = 4.6;
    } else if (this->target_row == 3 && this->target_col == 3){
        targetVoltageLow = 4.8;
        targetVoltageHigh = 5.2;
    } else {
        targetVoltageLow = -11;
        targetVoltageHigh = -10;
    };

    return ((targetStaircase > targetVoltageLow) && (targetStaircase < targetVoltageHigh));
}
void LEDTarget::setTargetOutputs(real_T *u) {
    int output_vals[3];
    if (target_row == 1 && target_col == 1){
        output_vals[0] = 0;
        output_vals[1] = 0;
        output_vals[2] = 0;
    } else if (target_row == 1 && target_col == 2){
        output_vals[0] = 0;
        output_vals[1] = 0;
        output_vals[2] = 1;
    } else if (target_row == 1 && target_col == 3){
        output_vals[0] = 0;
        output_vals[1] = 1;
        output_vals[2] = 0;
    } else if (target_row == 2 && target_col == 1){
        output_vals[0] = 0;
        output_vals[1] = 1;
        output_vals[2] = 1;
    } else if (target_row == 2 && target_col == 3){
        output_vals[0] = 1;
        output_vals[1] = 0;
        output_vals[2] = 0;
    } else if (target_row == 3 && target_col == 1){
        output_vals[0] = 1;
        output_vals[1] = 0;
        output_vals[2] = 1;
    } else if (target_row == 3 && target_col == 2){
        output_vals[0] = 1;
        output_vals[1] = 1;
        output_vals[2] = 0;
    } else if (target_row == 3 && target_col == 3){
        output_vals[0] = 1;
        output_vals[1] = 1;
        output_vals[2] = 1;
    } //else if wrong row and col, do nothing

	for (i = 0; i<3; i++) {
		u[i] = output_vals[i];
	}
}

/*
 * Inputs/Outputs
 *********************************************/

/**
 * This class holds a representation of the inputs to the master control block.
 * One instance of this class is created at Behavior::inputs and is automatically
 * filled prior to each call to update or setOutputs.
 */
class Reach3DInputs {
public:
    float targetStaircase;      /*Voltage sent by Arduino indicating sensed target*/        
};

/**
 * This class holds a representation of the outputs of the master control block.
 * One instance of this class is created at Behavior::outputs and must be filled
 * during the subclass' setOutputs function.  The contents of this are then written
 * to simulink output fields after setOutputs returns.  See the reference implementation
 * in random walk for an example.
 */
class Reach3DOutputs {
public:
	int status[5];       /**< Five status numbers to be displayed. */
	int word;            /**< 8-bit word to be output. */
	int reward;          /**< Set true to pulse the reward line. */
	int tone_counter;    /**< Tone counter (see Behavior::playTone).  */
	int last_tone_id;    /**< Id of last requested tone (see: Behavior::playTone). */
	int version[4];      /**< Four numbers indicating the version of the currently running behavior. */
	LEDTarget *target;    /**< Target object to determine LED to display*/
	int IMUreset;      /**< Reset signal for IMUS */
};

/**
 * A behavior deisnged to run on the robot.  Contains the inputs and outputs for the robot model.
 */
class Behavior3DReach : public Behavior {
protected:
	/**
	 * Stores the values of the inputs to the master control block.
	 * These fields are updated automatically prior to calls to calculateOutputs or update.
	 */
    Reach3DInputs *inputs;

	/**
	 * Set these fields to the desired outputs of the master control block.
	 */
	Reach3DOutputs *outputs;

public:
	Behavior3DReach();
	virtual void readInputs(SimStruct *S);
	virtual void writeOutputs(SimStruct *S);
};

/**
 * Default constructor. Initializes inputs, outputs and calls Robot().
 */
Behavior3DReach::Behavior3DReach() : Behavior() { 
    this->inputs = new Reach3DInputs();
	this->outputs = new Reach3DOutputs();

	for (int i = 0; i < 3; i++) {
		this->outputs->leds[i] = 0;
	}
    this->outputs->IMUreset = 0;
}

/**
 * Reads the inputs of the master control block into the RobotBehavior::inputs structure.
 * Called automatically prior to calculateOutputs or update.
 * @param S the current SimStruct.
 */
void Behavior3DReach::readInputs(SimStruct *S) {
	InputRealPtrsType uPtrs;

	/* input voltage */
	uPtrs = ssGetInputPortRealSignalPtrs(S, 0);
	inputs->targetStaircase = *uPtrs[0];
}

/**
 * Write the contents of RobotBehavior::outputs to the SimStruct (automatically called).
 */
void Behavior3DReach::writeOutputs(SimStruct *S) {
	int i;
	real_T *uPtrs;

	// status
	uPtrs = ssGetOutputPortRealSignal(S, 0);
	for (i = 0; i<5; i++) {
		uPtrs[i] = (real_T)outputs->status[i];
	}

	// word
	uPtrs = ssGetOutputPortRealSignal(S, 1);
	uPtrs[0] = (real_T)outputs->word;

	// reward
	uPtrs = ssGetOutputPortRealSignal(S, 2);
	uPtrs[0] = (real_T)(outputs->reward ? 1.0 : 0.0);

	// tone
	uPtrs = ssGetOutputPortRealSignal(S, 3);
	uPtrs[0] = (real_T)outputs->tone_counter;
	uPtrs[1] = (real_T)outputs->last_tone_id;

	// version
	uPtrs = ssGetOutputPortRealSignal(S, 4);
	for (i = 0; i<4; i++) {
		uPtrs[i] = outputs->version[i];
	}

	// leds
	uPtrs = ssGetOutputPortRealSignal(S, 5);
    outputs->target->setTargetOutputs(uPtrs);

	// IMU reset
	uPtrs = ssGetOutputPortRealSignal(S, 6);
    uPtrs[0] = outputs->IMUreset;

}
