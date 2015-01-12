/* $Id: $
 *
 * Master Control block for behavior: stim angle
 */

#pragma warning(disable:4800)

#define S_FUNCTION_NAME mastercon_stim_angle
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
#define STATE_CT_BLOCK 3
#define STATE_STIM 4
#define STATE_BUMP 5
#define STATE_MOVEMENT 6
#define STATE_PENALTY 7

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
 * bytes 3-6:	uchar       => version code
 * byte  7-8:	uchar		=> version code (micro)
 * bytes 16-19: float => target angle
 * bytes 20-23: float => bump magnitude
 * bytes 24-27: float => bump duration
 * byte 7: uchar      => staircase id
 * bytes 12-15: float  => bump direction

 */

#define DATABURST_VERSION ((byte)0x00) 
#define DATABURST_TASK_CODE ((byte)0x01)

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;
	real_T soft_reset;
// target info
	real_T target_size;
	real_T target_radius;
	real_T big_target;
	real_T target_angle;
// cursor info
	real_T hide_cursor;
    real_T recenter_cursor;
// bump info
	real_T bump_magnitude;
	real_T bump_peak_duration;
    real_T bump_ramp;
// trial timings
	real_T ct_hold_time;

	real_T intertrial_time;
	real_T penalty_time;
// staircase setup
	real_T run_staircase;
	real_T sc_step_size;
	real_T staircase_start;
	real_T staircase_ratio;
	real_T use_single_sc;
// stimulation
	real_T stim_prob;
	
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME StimAngleBehavior
class StimAngleBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	StimAngleBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	CircleTarget *centerTarget;
	CircleTarget *primaryTarget;
	CircleTarget *secondaryTarget;
	SquareTarget *errorTarget;
    
	Electrode *elec[9];//elec[0] will be our control bump

	int num_elec;
	int num_stairs;
	int electrode_id;
	int staircase_id;
	int *electrode_list[8];
	int *stair_list[4];
	bool stim_trial;
	double bump_reference_dir;
	bool first_bump_done;

    
    Point cursorOffset;

	CosineBumpGenerator *bump_ref;
	CosineBumpGenerator *bump_control;

	LocalParams *params;
	real_T last_soft_reset;

	// any helper functions you need
	void doPreTrial(SimStruct *S);
};

StimAngleBehavior::StimAngleBehavior(SimStruct *S) : RobotBehavior() {
    int i;

	/* 
	 * First, set up the parameters to be used 
	 */
	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using
	this->setNumParams();
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,					0);
	this->bindParamId(&params->soft_reset,						1);
//targets
	this->bindParamId(&params->target_size,						2);
	this->bindParamId(&params->big_target,						3);
	this->bindParamId(&params->target_radius,					4);
//cursor
	this->bindParamId(&params->hide_cursor,						5);
	this->bindParamId(&params->recenter_cursor,					6);
	this->bindParamId(&params->abort_during_bump,				7);
//timing
	this->bindParamId(&params->ct_hold_time,					8);
	this->bindParamId(&params->bump_delay_time,					9);
	this->bindParamId(&params->bump_hold_time,					10);
	this->bindParamId(&params->intertrial_time,					11);
	this->bindParamId(&params->penalty_time,					12);
//control bump
	this->bindParamId(&params->control_bump_peak_duration,		13);
    this->bindParamId(&params->control_bump_ramp,				14);
	this->bindParamId(&params->control_bump_magnitude,			15);
	//ref bump
	this->bindParamId(&params->ref_bump_peak_duration,			16);
    this->bindParamId(&params->ref_bump_ramp,					17);
	this->bindParamId(&params->ref_bump_magnitude,				18);
//electrodes
	this->bindParamId(&params->stim_prob,						19);
	this->bindParamId(&params->use_elec1,						20);
	this->bindParamId(&params->elec1_PD,						21);

	this->bindParamId(&params->use_elec2,						22);
	this->bindParamId(&params->elec2_PD,						23);

	this->bindParamId(&params->use_elec3,						24);
	this->bindParamId(&params->elec3_PD,						25);

	this->bindParamId(&params->use_elec4,						26);
	this->bindParamId(&params->elec4_PD,						27);

	this->bindParamId(&params->use_elec5,						28);
	this->bindParamId(&params->elec5_PD,						29);

	this->bindParamId(&params->use_elec6,						30);
	this->bindParamId(&params->elec6_PD,						31);

	this->bindParamId(&params->use_elec7,						32);
	this->bindParamId(&params->elec7_PD,						33);

	this->bindParamId(&params->use_elec8,						34);
	this->bindParamId(&params->elec8_PD,						35);
//staircases
	this->bindParamId(&params->step_size						36);
	this->bindParamId(&params->use_limits,						37);
	this->bindParamId(&params->center_angle,					38);

	this->bindParamId(&params->run_staircase1,					39);
	this->bindParamId(&params->staircase1_start,				40);
	this->bindParamId(&params->staircase1_ratio,				41);
	this->bindParamId(&params->staircase1_lower_limit,			42);
	this->bindParamId(&params->staircase1_upper_limit,			43);

	this->bindParamId(&params->run_staircase2,					44);
	this->bindParamId(&params->staircase2_start,				45);
	this->bindParamId(&params->staircase2_ratio,				46);
	this->bindParamId(&params->staircase2_lower_limit,			47);
	this->bindParamId(&params->staircase2_upper_limit,			48);

	this->bindParamId(&params->run_staircase3,					49);
	this->bindParamId(&params->staircase3_start,				50);
	this->bindParamId(&params->staircase3_ratio,				51);
	this->bindParamId(&params->staircase3_lower_limit,			52);
	this->bindParamId(&params->staircase3_upper_limit,			53);

	this->bindParamId(&params->run_staircase4,					54);
	this->bindParamId(&params->staircase4_start,				55);
	this->bindParamId(&params->staircase4_ratio,				56);
	this->bindParamId(&params->staircase4_lower_limit,			57);
	this->bindParamId(&params->staircase4_upper_limit,			58);

	

	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);

	// This function now fetches all of the parameters into the variables
	// as defined above.
	this->updateParameters(S);
	
	last_soft_reset = -1; // force a soft reset of first trial

	centerTarget = new CircleTarget();
	primaryTarget = new CircleTarget(); 
	secondaryTarget = new CircleTarget(); 

	centerTarget->color = Target::Color(128, 128, 128);
	primaryTarget->color = Target::Color(128, 128, 128);
	secondaryTarget->color = Target::Color(128, 128, 128);

	errorTarget = new SquareTarget(0, 0, 100, Target::Color(255, 255, 255));
	//generate the staircases
	for (i=0; i<8; i++) {
		stairs[i] = new Staircase();
	}
	//get count of number of stairs we are using for this run
	this->num_stairs=	(int)this->params->run_staircase1+
						(int)this->params->run_staircase2+
						(int)this->params->run_staircase3+
						(int)this->params->run_staircase4;

	//fill in the list of staircases in use for this run
	i=0;
	if(this->params->run_staircase1){
		stair_list[i]=1;
		i++;
	}
	if(this->params->run_staircase2){
		stair_list[i]=2;
		i++;
	}
	if(this->params->run_staircase3){
		stair_list[i]=3;
		i++;
	}
	if(this->params->run_staircase4){
		stair_list[i]=4;
	}


	//get an electrode count
	this->num_elec=	(int)this->params->use_elec1+
					(int)this->params->use_elec2+
					(int)this->params->use_elec3+
					(int)this->params->use_elec4+
					(int)this->params->use_elec5+
					(int)this->params->use_elec6+
					(int)this->params->use_elec7+
					(int)this->params->use_elec8;
	//get an electrode list
	i=0;
	if(this->use_elec1){
		elec_list[i]=1;
		i++;
	}
	if(this->use_elec2){
		elec_list[i]=2;
		i++;
	}
	if(this->use_elec3){
		elec_list[i]=3;
		i++;
	}
	if(this->use_elec4){
		elec_list[i]=4;
		i++;
	}
	if(this->use_elec5){
		elec_list[i]=5;
		i++;
	}
	if(this->use_elec6){
		elec_list[i]=6;
		i++;
	}
	if(this->use_elec7){
		elec_list[i]=7;
		i++;
	}
	if(this->use_elec8){
		elec_list[i]=8;
		i++;
	}

	//some defaults
	this->stim_trial = false;
	this->staircase_id = -1;
	this->bump_dir = 0.0;
	this->bump_ref = new CosineBumpGenerator();
	this->bump_control = new CosineBumpGenerator();
}


void StimAngleBehavior::doPreTrial(SimStruct *S) {
	int i
	//if there was a reset, load parameters to the staircases and reset them.
	if (last_soft_reset != params->soft_reset) {
		last_soft_reset = params->soft_reset;
		for(i=0;i<num_stairs;i++){
			elec[i]->resetStaircases(double step,(bool) use_limits,double lower_limit, double upper_limit, double ratio1, double ratio2, double ratio3, double ratio4, double start1, double start2, double start3, double start4);
		}
	}

	// Select whether this will be a stimulation trial 
    this->stim_trial=(this->random->getDouble() < params->stim_prob);
	if()this->stim_trial){
		electrode_id=this->random->getInteger(1:num_elec)
	} else{
		electrode_id=0;
	}

	//select a staircase
	staircase_id=stair_list(this->random->getInteger(0,2*num_stairs-1));

	//pull the direction of the reference bump, and targets from the staircase
	this->bump_ref_dir=elec(electrode_id)->stairs(staircase_id)->getValue();

	// Set up the reference bump itself
	this->bump_ref->hold_duration	= params->bump_peak_duration;
	this->bump_ref->peak_magnitude	= params->bump_magnitude;
	this->bump_ref->rise_time		= params->bump_ramp;
	this->bump_ref->direction		= PI * this->bump_ref_dir / 180;

	//set up the control bump if we aren't in a stim trial, otherwise, don't bother
	if( !this->stim_trial){
		this->bump_control->hold_duration		= params->bump_peak_duration;
		this->bump_control->peak_magnitude		= params->bump_magnitude;
		this->bump_control->rise_time			= params->bump_ramp;
		this->bump_control->direction			= PI * this->elec[0]->getPD() / 180;
	}


	this->first_bump_done=false;
	// Set up targets 
	centerTarget->radius = params->target_size;
	centerTarget->centerX = 0;
	centerTarget->centerY = 0;
	
	CWTarget->radius = params->target_size;
	CWTarget->centerX = params->target_radius*cos(PI * (this->bump_ref_dir -90) / 180);
	CWTarget->centerY = params->target_radius*sin(PI * (this->bump_ref_dir -90) / 180);
	
	CCWTarget->radius = params->target_size;
	CCWTarget->centerX = params->target_radius*cos(PI * (this->bump_ref_dir +90) / 180);
	CCWTarget->centerY = params->target_radius*sin(PI * (this->bump_ref_dir +90) / 180);

    // Reset cursor offset
    cursorOffset.x = 0;
    cursorOffset.y = 0;
    
	/* setup the databurst */
	//basic task info
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('S');
	db->addByte('A');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
	//cursor
	db->addByte(this->params->hide_cursor);//hide during bump
	db->addByte(this->params->recenter_cursor);//recenter after bump
	db->addByte(params->abort_during_bump)://abort during bump
	//targets
	db->addFloat((float)this->params->target_size);
	db->Float((float)this->params->big_target);
	db->Float((float)this->params->target_radius);
	//timing
	db->addFloat((float)this->params->ct_hold_time);
	db->addFloat((float)this->params->bump_delay_time);
	db->addFloat((float)this->params->bump_hold_time);
	db->addFloat((float)this->params->intertrial_time);
	db->addFloat((float)this->params->penalty_time);
	//bumps for this trial
	db->addFloat((float)this->bump_ref->peak_magnitude);
	db->addFloat((float)this->bump_ref->hold_duration);
	db->addFloat((float)this->bump_ref->rise_time);
	db->addFloat((float)this->bump_ref_dir);//variable bump direction
	db->addFloat((float)this->bump_control->peak_magnitude);
	db->addFloat((float)this->bump_control->hold_duration);
	db->addFloat((float)this->bump_control->rise_time);
	db->addFloat((float)this->elec[0]->getPD());
	db->addFloat((float)this->elec[0]->getPD());//control bump direction
	db->addByte(this->stim_trial);
	//electrode for this trial
	db->addByte(electrode_id);//electrode 0 is the control trial electrode
	db->addByte(elec[electrode_id]->getPD();
	// staircase for this trial
	db->addByte(staircase_id);
	db->addFloat((float)elec[electrode_id]->stairs[staircase_id]->getIteration());
	db->addFloat((float)elec[electrode_id]->stairs[staircase_id]->getStepSize());
	db->addFloat((float)elec[electrode_id]->stairs[staircase_id]->getStepRatio());
	db->addByte(this->params->use_limits);
	db->addFloat((float)elec[electrode_id]->stairs[staircase_id]->getForwardLimit());
	db->addFloat((float)elec[electrode_id]->stairs[staircase_id]->getBackwardLimit());
	
    db->start();
}

void StimAngleBehavior::update(SimStruct *S) {
	Target *correctTarget;
	Target *incorrectTarget;

	if (elec(electrode_id)->stairs(staircase_id)->getStepSize()<0){
		//this is a staircase iterating in from the CCW side
		correctTarget = CCWTarget;
		incorrectTarget = CWTarget;
	}else {
		correctTarget = CWTarget;
		incorrectTarget = CCWTarget;
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
			/* center target on wait for cursor to enter target*/
			if (centerTarget->cursorInTarget(inputs->cursor)) {
				setState(STATE_CT_HOLD);
			}
			break;
		case STATE_CT_HOLD:
			/* make sure cursor stays in target during hold */
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > params->ct_hold_time) {
                centerTarget->radius = params->big_target;
				setState(STATE_CT_BLOCK);
			}
			break;
		case STATE_CT_BLOCK:
			/* if the cursor is out of the target abort
				if the delay for bump onset has elapsed then check whether the first bump is done
				if the first bump is not done, go to the bump state
				if the first bump is done, check whether its a stim trial
				if its a stim trial go to the stim state
				if its not a stim trial go to the bump state again*/ 
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > params->bump_delay_time) {
				bump->start(S);
				if(this->first_bump_done){
					if(this->stim_trial) {
						setState(STATE_STIM);
					} else {
						setState(SATE_BUMP);
					}
				} else {
					setState(STATE_BUMP);
				}
			}
			break;
		case STATE_BUMP:
			/* if the cursor leaves the center target abort
				if the bump hold time is over check whether we are in the first or second bump
				if we are in the second bump start the movement state
				if we are in the first bump return to the ct_block state*/
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > params->bump_hold_time) {
				if(this->first_bump_done) {
					if (this->stim_trial) {
						setState(STATE_STIM);
					} else {
						if (params->recenter_cursor) {
							cursorOffset = inputs->cursor;
						}   
						playTone(TONE_GO);
						setState(STATE_MOVEMENT);
					}
				} else {
					this->first_bump_done=true;
					setState(STATE_CT_BLOCK);
				}
			}
			break;
		case STATE_STIM:
				/* wait for the bump time then go to the movement state */ 
				if (stateTimer->elapsedTime(S) > params->bump_hold_time) {
					if(this->params->recenter_cursor){
						cursorOffset = inputs->cursor;
					}
					playTone(TONE_GO);
					setState(STATE_MOVEMENT);
				}
			break;
		case STATE_MOVEMENT:
			/* if the cursor is in one of the outer targets, then enter either the reward or fail state */
			if (correctTarget->cursorInTarget(inputs->cursor - cursorOffset)) {
				this->stairs[staircase_id]->stepForward();
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			} else if (incorrectTarget->cursorInTarget(inputs->cursor - cursorOffset)) {
				this->stairs[staircase_id]->stepBackward();
				playTone(TONE_FAIL);
				setState(STATE_FAIL):
			}
			break;
		case STATE_FAIL:
			this->bump_ref->stop();
			this->bump_control->stop();
			/* check whether there is a penalty time, if so go to the penalty state, otherwise, go to pretrial */
			if (this->params->penalty_time > 0) {
					setState(STATE_PENALTY);
				} else {
					setState(STATE_PRETRIAL);
				}
			}
			break;
		case STATE_PENALTY:
			/* wait for the penalty time to finish then go to the pretrial*/
			if (stateTimer->elapsedTime(S) > params->penalty_time) {
				setState(STATE_PRETRIAL);
			}
			break;
		case STATE_INCOMPLETE:
			this->bump_ref->stop();
			this->bump_control->stop();
			if (stateTimer->elapsedTime(S) > params->intertrial_time) {
				setState(STATE_PRETRIAL);
			}
			break;
		
		case STATE_ABORT:
			this->bump_ref->stop();
			this->bump_control->stop();
        case STATE_REWARD:
		    this->bump_ref->stop();
			this->bump_control->stop();
		default:
			setState(STATE_PRETRIAL);
	}

}

void StimAngleBehavior::calculateOutputs(SimStruct *S) {
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
			case STATE_CT_BLOCK:
				outputs->word = WORD_OT_ON(0);
				break;
			case STATE_STIM:
				outputs->word = WORD_STIM(this->electrode_id);
				break;
			case STATE_BUMP:
				outputs->word = WORD_BUMP(this->first_bump_done);
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
        getState() == STATE_CT_BLOCK ||
        getState() == STATE_BUMP) 
	{
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;

	} else if (getState() == STATE_MOVEMENT) {
		outputs->targets[0] = (Target *)(this->CWTarget);
		outputs->targets[1] = (Target *)(this->CCWTarget);
	} else if (getState() == STATE_PENALTY) {
		outputs->targets[0] = (Target *)(this->errorTarget);
		outputs->targets[1] = nullTarget;
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

	/* cursor position (7) */
    if ((getState() == STATE_CT_BLOCK || getState() == STATE_BUMP || getState()== STATE_STIM) && (params->hide_cursor > .1))
    {
        outputs->position = Point(1E6, 1E6);
    } else { //if ( (params->recenter_cursor) && (getState() == STATE_MOVEMENT) ) {
        outputs->position = inputs->cursor - cursorOffset;
    } 
}

/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


