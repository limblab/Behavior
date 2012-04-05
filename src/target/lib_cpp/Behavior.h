#ifndef _BEHAVIOR_H
#define _BEHAVIOR_H 1

/*
 * Inputs/Outputs
 *********************************************/

/**
 * This class holds a representation of the inputs to the master control block.
 * One instance of this class is created at Behavior::inputs and is automatically
 * filled prior to each call to update or setOutputs.
 */
class Inputs {
public:
	Point cursor; 	  /**< The current cursor location. */
	Point offsets;    /**< The offsets (position of workspace zero relative to motor axes). */	
    Point force;      /**< The input force from the selected force generator. */
    Point catchForce; /**< The input force from the selected catch-force generator. */
};

/**
 * This class holds a representation of the outputs of the master control block.
 * One instance of this class is created at Behavior::outputs and must be filled
 * during the subclass' setOutputs function.  The contents of this are then written
 * to simulink output fields after setOutputs returns.  See the reference implementation
 * in random walk for an example.
 */
class Outputs {
public:
	Point force; 	     /**< Requested output force. */
	int status[5];       /**< Five status numbers to be displayed. */
	int word;            /**< 8-bit word to be output. */
	Target *targets[17]; /**< Targets to be displayed. */
	int reward;          /**< Set true to pulse the reward line. */
	int tone_counter;    /**< Tone counter (see Behavior::playTone).  */
	int last_tone_id;    /**< Id of last requested tone (see Behavior::playTone). */
	int version[4];      /**< Four numbers indicating the version of the currently running behavior. */
	Point position;      /**< The position to draw the cursor. */
};

/*
 * Behavior
 *********************************************/

/**
 * The parent class for the behavior.
 * This abstract class is extended for each behavior.  The derived
 * behavior must at a minimum implement Behavior::update(SimStruct *S)
 * and calculateOutputs(SimStruct *S).  It may also contain any
 * instance variables desired (which will be persistant) and any
 * helper functions. Subclasses should define their own constructor for
 * any setup needed (including defining parameters).
 */
class Behavior {
public:
	Behavior();
	void generalUpdate(SimStruct *S);
	void readInputs(SimStruct *S);
	void writeOutputs(SimStruct *S);
	void updateTrialCounters();
	int checkMasterReset(SimStruct *S);
	int getNumParams();
	
	/* These are the two functions that must be implemented for each behavior */

	/**
	 * Updates the state machine.
	 * A true virtual function, each subclass must define an update function.
	 * The update function should execute a cycle of the state machine.
	 */
	virtual void update(SimStruct *S) = 0;

	/**
	 * Sets the outputs.
	 * A true virtual function, each subclass must define a calculateOutputs function.
	 * The implementing function should set all of the fields of Behavior::outputs to 
	 * the desired outputs.
	 */
	virtual void calculateOutputs(SimStruct *S) = 0;

protected:
	void updateParameters(SimStruct *S);
	void setNumParams(int n);
	void bindParamId(real_T *paramLocation, int paramIdNumber);
	void setMasterResetParamId(int n);

	void setState(int state);
	int getState();
	bool isNewState();

	void playTone(int ToneID);

	/* Instance variables follow 
	 *****************************/

	/** 
	 * Counts how many tones have been played since the behavior was started. 
	 * This value should not need to be accessed directly, but is updated when
	 * Behavior::playSound() is called.
	 */
	int tone_counter;

	/** 
	 * Holds the tone id of the last tone played. This value is typically sent to be 
	 * This value should not need to be accessed directly, but is updated when
	 * Behavior::playSound() is called.
	 */
	int last_tone_id;

	/**
	 * Contains the trial counters for each of the trial results.
	 * The fields of the TrialCounter should not be updated directly but are set
	 * every time the state machine enters the reward, abort, incomplete, or failure
	 * states.
	 */
	TrialCounter *trialCounter;

	/**
	 * Stores the values of the inputs to the master control block.
	 * These fields are updated automatically prior to calls to calculateOutputs or update.
	 */
    Inputs *inputs;

	/**
	 * Set these fields to the desired outputs of the master control block.
	 */
	Outputs *outputs;

	/**
	 * The state timer (do not modify).
	 * This timer is automatically reset each time setState() is called.  Calls to `stateTimer->elapsedTime(S)`
	 * will return the time spent in the current state.
	 */
	Timer *stateTimer;

	/**
	 * A pseudo random number generator. This is the instance of Random that 
	 * should be used by all subclases.  To add entropy, a number is 
	 * automatically burned each xpc cycle. Subclasses should not need to 
	 * instantiate their own RNG.
	 */
	Random *random;

	/**
	 * A predefined null target that will not be draw, provided for Convenience.
	 */
	Target *nullTarget;

	/**
	 * The provided instance of DataBurst.
	 */
	DataBurst *db;

private:
	int state;
	bool state_changed;
	int masterResetParamId;
	int masterResetCounter;

	int numParams;
	real_T **paramAddrs;

	SimStruct *S;
};

#endif /* _BEHAVIOR_H */



