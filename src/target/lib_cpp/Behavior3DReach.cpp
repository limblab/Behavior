/**
 * $Id$
 *
 * Parent class for all robot based c++ behaviors.
 */

#ifndef __COMMON_HEADER_CPP
#error "This file is meant to be included through common_header.cpp."
#endif

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
	int leds[3]; /**< Output signal to determine LED to display*/
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
    this->inputs = new  Reach3DInputs();
	this->outputs = new Reach3DOutputs();

	for (int i = 0; i < 3; i++) {
		this->outputs->leds[i] = 0;
	}
    IMUreset = 0;
}

/**
 * Reads the inputs of the master control block into the RobotBehavior::inputs structure.
 * Called automatically prior to calculateOutputs or update.
 * @param S the current SimStruct.
 */
void Behavior3DReach::readInputs(SimStruct *S) {
	InputRealPtrsType uPtrs;

	/* cursor */
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

	// position
	uPtrs = ssGetOutputPortRealSignal(S, 5);
    uPtrs[0] = outputs->leds[0];
    uPtrs[1] = outputs->leds[1];
    uPtrs[2] = outputs->leds[2];

	uPtrs = ssGetOutputPortRealSignal(S, 6);
    uPtrs[0] = outputs->IMUreset;

}
