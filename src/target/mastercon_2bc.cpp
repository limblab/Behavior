/* $Id: $
 *
 * Master Control block for behavior: bump psychophysics 2-bump choice
 */

#define S_FUNCTION_NAME mastercon_2bc
#define S_FUNCTION_LEVEL 2

// Our task code will be in the databurst
#define TASK_DB_DEFINED 1
#include "words.h"

#include "common_header.cpp"

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_CT_ON 1
#define STATE_CT_HOLD 2
#define STATE_OT_DISPLAY 3
#define STATE_BUMP 4
#define STATE_MOVEMENT 5
/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
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
 * byte 0: uchar      => number of bytes to be transmitted
 * byte 1: uchar      => version number (in this case zero)
 * byte 2: uchar      => task code (0x01)
 * bytes 3-6:         => version code
 * byte 7: uchar      => staircase id
 * bytes 8-11: int    => staircase iteration
 * bytes 12-15: float  => bump direction
 * bytes 16-19: float => target angle
 * bytes 20-23: float => bump magnitude
 * bytes 24-27: float => bump duration
 */

#define DATABURST_VERSION ((byte)0x00) 
#define DATABURST_TASK_CODE ((byte)0x01)

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;
	real_T soft_reset;
	real_T target_size;
	real_T target_radius;
	real_T target_angle;
	real_T bump_magnitude;
	real_T bump_duration;
	real_T ct_hold_time;
	real_T ot_delay_time;
	real_T bump_hold_time;
	real_T intertrial_time;
	real_T run_staircase;
	real_T sc_step_size;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME TwoBumpChoiceBehavior
class TwoBumpChoiceBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	TwoBumpChoiceBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	CircleTarget *centerTarget;
	CircleTarget *primaryTarget;
	CircleTarget *secondaryTarget;

	Staircase *stairs[2];
	int staircase_id;

	double bump_dir;

	SquareBumpGenerator *bump;

	LocalParams *params;
	real_T last_soft_reset;

	// any helper functions you need
	void doPreTrial(SimStruct *S);
};

TwoBumpChoiceBehavior::TwoBumpChoiceBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams(13);

	// Identify each bound variable 
	this->bindParamId(&params->master_reset,	 0);
	this->bindParamId(&params->soft_reset,		 1);
	this->bindParamId(&params->target_size,		 2);
	this->bindParamId(&params->target_radius,	 3);
	this->bindParamId(&params->target_angle,	 4);
	this->bindParamId(&params->bump_magnitude,	 5);
	this->bindParamId(&params->bump_duration,	 6);
	this->bindParamId(&params->ct_hold_time,	 7);
	this->bindParamId(&params->ot_delay_time,	 8);
	this->bindParamId(&params->bump_hold_time,	 9);
	this->bindParamId(&params->intertrial_time, 10);
	this->bindParamId(&params->run_staircase,	11);
	this->bindParamId(&params->sc_step_size,	12);

	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);

	last_soft_reset = -1; // force a soft reset of first trial

	centerTarget = new CircleTarget();
	primaryTarget = new CircleTarget(); 
	secondaryTarget = new CircleTarget(); 

	centerTarget->color = Target::Color(255, 255, 255);
	primaryTarget->color = Target::Color(255, 0, 160);
	secondaryTarget->color = Target::Color(160, 255, 0);

	for (i=0; i<2; i++) {
		stairs[i] = new Staircase();
	}

	this->staircase_id = 0;
	this->bump_dir = 0.0;
	this->bump = new SquareBumpGenerator();
}

void TwoBumpChoiceBehavior::doPreTrial(SimStruct *S) {
	// Set up target locations, etc.
	centerTarget->radius = params->target_size;

	primaryTarget->radius = params->target_size;
	primaryTarget->centerX = params->target_radius*cos(params->target_angle);
	primaryTarget->centerY = params->target_radius*sin(params->target_angle);
	
	secondaryTarget->radius = params->target_size;
	secondaryTarget->centerX = params->target_radius*cos(PI + params->target_angle);
	secondaryTarget->centerY = params->target_radius*sin(PI + params->target_angle);

	if (last_soft_reset != params->soft_reset) {
		// load parameters to the staircases and reset them.
		last_soft_reset = params->soft_reset;

		stairs[0]->setStartValue( params->target_angle );
		stairs[0]->setRatio(3);
		stairs[0]->setStep( params->sc_step_size );
		stairs[0]->restart();

		stairs[1]->setStartValue( params->target_angle + 180 );
		stairs[1]->setRatio(3);
		stairs[1]->setStep( -params->sc_step_size );
		stairs[1]->restart();
	}

	// Pick which staircase to use
	this->staircase_id = random->getInteger(0,1);
	this->bump_dir = stairs[staircase_id]->getValue();

	// Set up the bump itself
	this->bump->duration = params->bump_duration;
	this->bump->magnitude = params->bump_magnitude;
	this->bump->direction = PI * this->bump_dir / 180;

	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte(DATABURST_TASK_CODE);
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	db->addByte(staircase_id);
	db->addInt(stairs[staircase_id]->getIteration());
	db->addFloat((float)bump_dir);
	db->addFloat((float)params->target_angle);
	db->addFloat((float)params->bump_magnitude);
	db->addFloat((float)params->bump_duration);
    db->start();
}

void TwoBumpChoiceBehavior::update(SimStruct *S) {
	Target *correctTarget;
	Target *incorrectTarget;

	if (staircase_id == 0) {
		// want to be in primary target
		correctTarget = primaryTarget;
		incorrectTarget = secondaryTarget;
	} else {
		// staircase_id == 1
		// want to be in secondary target
		correctTarget = secondaryTarget;
		incorrectTarget = primaryTarget;
	}


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
			break;
		case STATE_CT_ON:
			/* first target on */
			if (centerTarget->cursorInTarget(inputs->cursor)) {
				setState(STATE_CT_HOLD);
			}
			break;
		case STATE_CT_HOLD:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > params->ct_hold_time) {
				setState(STATE_OT_DISPLAY);
			}
			break;
		case STATE_OT_DISPLAY:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > params->ot_delay_time) {
				bump->start(S);
				setState(STATE_BUMP);
			}
			break;
		case STATE_BUMP:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > params->bump_hold_time) {
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_MOVEMENT:
			if (correctTarget->cursorInTarget(inputs->cursor)) {
				if (params->run_staircase)
					this->stairs[staircase_id]->stepForward();
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			} else if (incorrectTarget->cursorInTarget(inputs->cursor)) {
				if (params->run_staircase)
					this->stairs[staircase_id]->stepBackward();
				playTone(TONE_ABORT);
				setState(STATE_FAIL);
			}
			break;
		case STATE_ABORT:
        case STATE_REWARD:
		case STATE_FAIL:
        case STATE_INCOMPLETE:
			if (stateTimer->elapsedTime(S) > params->intertrial_time) {
				setState(STATE_PRETRIAL);
			}
			break;
		default:
			setState(STATE_PRETRIAL);
	}
}

void TwoBumpChoiceBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
    Point bf;

	/* force (0) */
	if (bump->isRunning(S)) {
		bf = bump->getBumpForce(S);
		outputs->force.x = inputs->force.x + bf.x;
		outputs->force.y = inputs->force.y + bf.y;
	} else {
		outputs->force = inputs->force;
	}

	/* status (1) */
	outputs->status[0] = getState();
	outputs->status[1] = trialCounter->successes;
	outputs->status[2] = trialCounter->failures;
	outputs->status[3] = (int)stairs[0]->getValue();
	outputs->status[4] = (int)stairs[1]->getValue();

	/* word(2) */
	if (db->isRunning()) {
		outputs->word = db->getByte();
	} else if (isNewState()) {
		switch (getState()) {
			case STATE_PRETRIAL:
				outputs->word = WORD_START_TRIAL;
				break;
			case STATE_OT_DISPLAY:
				outputs->word = WORD_OT_ON(0);
				break;
			case STATE_BUMP:
				outputs->word = WORD_BUMP(0);
				break;
			case STATE_MOVEMENT:
				outputs->word = WORD_GO_CUE;
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
	if (getState() == STATE_CT_ON || 
	    getState() == STATE_CT_HOLD || 
        getState() == STATE_OT_DISPLAY ||
        getState() == STATE_BUMP) 
	{
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = nullTarget;
	} else if (getState() == STATE_MOVEMENT) {
		outputs->targets[0] = (Target *)(this->primaryTarget);
		outputs->targets[1] = (Target *)(this->secondaryTarget);
	} else {
		outputs->targets[0] = nullTarget;
		outputs->targets[1] = nullTarget;
	}

#if 0
	if (getState() == STATE_CT_ON || 
	    getState() == STATE_CT_HOLD || 
        getState() == STATE_OT_DISPLAY ||
        getState() == STATE_BUMP) 
	{
		outputs->targets[0] = (Target *)centerTarget;
	} else {
		outputs->targets[0] = nullTarget;
	}

	// Outer Targets
	if (/*getState() == STATE_OT_DISPLAY || 
		getState() == STATE_BUMP || 
		*/getState() == STATE_MOVEMENT) 
	{
		outputs->targets[0] = (Target *)(this->primaryTarget);
		outputs->targets[1] = (Target *)(this->secondaryTarget);
	} else {
		outputs->targets[0] = nullTarget;
		outputs->targets[1] = nullTarget;
	}
#endif
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
	outputs->position = inputs->cursor;
}

/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


