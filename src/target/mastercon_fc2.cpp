
/* $Id: $
 *
 * Master Control block for behavior: bump psychophysics 2-bump choice
 */


#pragma warning(disable: 4800)


#define S_FUNCTION_NAME mastercon_fc2
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
 * Current Databurst version: 1 (version 0 is for the old c code- no version 0 exists for this cpp code)
 *
 * Note that all databursts are encoded half a byte at a time as a word who's 
 * high order bits are all 1 and who's low order bits represent the half byte to
 * be transmitted.  Low order bits are transmitted first.  Thus to transmit the
 * two bytes 0xCF 0x07, one would send 0xFF 0xFC 0xF7 0xF0.
 *
 * Databurst version descriptions
 * ==============================
 *
 * Version 1 (0x01)
 * ----------------
 * byte  0:		uchar		=> number of bytes to be transmitted
 * byte  1:		uchar		=> version number (in this case one)
 * byte  2-3:	uchar		=> task code ('FC')
 * bytes 4-5:	uchar       => version code
 * byte  5-6:	uchar		=> version code (micro)
 *
 * bytes 7-10:  float		=> target angle
 * byte  11:	uchar           => random target flag
 * bytes 12-15: float		=> target radius
 * bytes 16-19: float		=> target size
 * byte  20:	uchar		=> show target during bump
 *
 * byte  21:                => bump trial flag
 * bytes 22-25: float		=> bump direction
 * bytes 26-29: float       => bump magnitude
 * bytes 30-33: float		=> bump floor (minimum force(N) bump can take)
 * bytes 34-37:	float		=> bump ceiling (maximum force(N) bump can take)
 * bytes 38-41:	float		=> bump step
 * bytes 42-45: float		=> bump duration
 * bytes 46-49: float		=> bump ramp
 *
 * byte  50:	uchar		=> stim trial flag
 * bytes 51:    uchar       => stim code
 *
 * byte  52:    uchar       => training trial flag
 *
 * byte  53:	uchar		=> recenter cursor flag
 * byte  54:    uchar       => hide cursor during bump
 *
 * bytes 55-58: float		=> intertrial time
 * bytes 59-62: float		=> penalty time
 * bytes 63-66: float		=> bump hold time
 * bytes 67-70: float		=> center hold time
 * bytes 71-74: float		=> bump delay time
 * byte 75:	uchar		=> abort during bump
 * byte 76:	uchar		=> force reactionm
	
* Version 2 (0x02) -- supports multiple bump staircases, more information is output
 *  so that the staircases can be tracked (which staircase was selected and where that
 *  staircase currently is)
 * ----------------
 * byte  0:		uchar		=> number of bytes to be transmitted
 * byte  1:		uchar		=> version number (in this case one)
 * byte  2-3:	uchar		=> task code ('FC')
 * bytes 4-5:	uchar       => version code
 * byte  5-6:	uchar		=> version code (micro)
 *
 * bytes 7-10:  float		=> target angle
 * byte  11:	uchar           => random target flag
 * bytes 12-15: float		=> target radius
 * bytes 16-19: float		=> target size
 * byte  20:	uchar		=> show target during bump
 *
 * byte  21:                => bump trial flag
 * bytes 22-25: float		=> bump direction
 * bytes 26-29: float       => bump magnitude
 * bytes 30-33: float		=> bump floor (minimum force(N) bump can take)
 * bytes 34-37:	float		=> bump ceiling (maximum force(N) bump can take)
 * bytes 38-41:	float		=> bump step
 * bytes 42-45: float		=> bump duration
 * bytes 46-49: float		=> bump ramp
 *
 * byte  50:	uchar		=> stim trial flag
 * bytes 51:    uchar       => stim code
 *
 * byte  52:    uchar       => training trial flag
 *
 * byte  53:	uchar		=> recenter cursor flag
 * byte  54:    uchar       => hide cursor during bump
 *
 * bytes 55-58: float		=> intertrial time
 * bytes 59-62: float		=> penalty time
 * bytes 63-66: float		=> bump hold time
 * bytes 67-70: float		=> center hold time
 * bytes 71-74: float		=> bump delay time
 * byte 75:	uchar		=> abort during bump
 * byte 76:	uchar		=> force reaction
 * bytes 77-80: float   => bump staircase idx
 * bytes 81-84: float   => current bump staircase value
 */
 
 /* Version 3 (0x03) -- supports multiple stim staircases and bump staircases, more information is output
 *  so that the staircases can be tracked (which staircase was selected and where that
 *  staircase currently is)
 * ----------------
 * byte  0:		uchar		=> number of bytes to be transmitted
 * byte  1:		uchar		=> version number (in this case one)
 * byte  2-3:	uchar		=> task code ('FC')
 * bytes 4-5:	uchar       => version code
 * byte  5-6:	uchar		=> version code (micro)
 *
 * bytes 7-10:  float		=> target angle
 * byte  11:	uchar           => random target flag
 * bytes 12-15: float		=> target radius
 * bytes 16-19: float		=> target size
 * byte  20:	uchar		=> show target during bump
 *
 * byte  21:                => bump trial flag
 * bytes 22-25: float		=> bump direction
 * bytes 26-29: float       => bump magnitude
 * bytes 30-33: float		=> bump floor (minimum force(N) bump can take)
 * bytes 34-37:	float		=> bump ceiling (maximum force(N) bump can take)
 * bytes 38-41:	float		=> bump step
 * bytes 42-45: float		=> bump duration
 * bytes 46-49: float		=> bump ramp
 *
 * byte  50:	uchar		=> stim trial flag
 * bytes 51:    uchar       => stim code
 *
 * byte  52:    uchar       => training trial flag
 *
 * byte  53:	uchar		=> recenter cursor flag
 * byte  54:    uchar       => hide cursor during bump
 *
 * bytes 55-58: float		=> intertrial time
 * bytes 59-62: float		=> penalty time
 * bytes 63-66: float		=> bump hold time
 * bytes 67-70: float		=> center hold time
 * bytes 71-74: float		=> bump delay time
 * byte 75:	uchar		=> abort during bump
 * byte 76:	uchar		=> force reaction
 * bytes 77-80: float   => bump staircase idx
 * bytes 81-84: float   => current bump staircase value
 * bytes 85-88: float	=> current stim staircase idx
 */
 
 /* Version 4 (0x04) -- supports multiple stim staircases and bump staircases, more information is output
 *  so that the staircases can be tracked (which staircase was selected and where that
 *  staircase currently is)
 * ----------------
 * byte  0:		uchar		=> number of bytes to be transmitted
 * byte  1:		uchar		=> version number (in this case one)
 * byte  2-3:	uchar		=> task code ('FC')
 * bytes 4-5:	uchar       => version code
 * byte  5-6:	uchar		=> version code (micro)
 *
 * bytes 7-10:  float		=> target angle
 * byte  11:	uchar           => random target flag
 * bytes 12-15: float		=> target radius
 * bytes 16-19: float		=> target size
 * byte  20:	uchar		=> show target during bump
 *
 * byte  21:                => bump trial flag
 * bytes 22-25: float		=> bump direction
 * bytes 26-29: float       => bump magnitude
 * bytes 30-33: float		=> bump floor (minimum force(N) bump can take)
 * bytes 34-37:	float		=> bump ceiling (maximum force(N) bump can take)
 * bytes 38-41:	float		=> bump step
 * bytes 42-45: float		=> bump duration
 * bytes 46-49: float		=> bump ramp
 *
 * byte  50:	uchar		=> stim trial flag
 * bytes 51:    uchar       => stim code
 *
 * byte  52:    uchar       => training trial flag
 *
 * byte  53:	uchar		=> recenter cursor flag
 * byte  54:    uchar       => hide cursor during bump
 *
 * bytes 55-58: float		=> intertrial time
 * bytes 59-62: float		=> penalty time
 * bytes 63-66: float		=> bump hold time
 * bytes 67-70: float		=> center hold time
 * bytes 71-74: float		=> bump delay time
 * byte 75:	uchar		=> abort during bump
 * byte 76:	uchar		=> force reaction
 * bytes 77-80: float   => bump staircase idx
 * bytes 81-84: float   => current bump staircase value
 * bytes 85-88: float	=> current stim staircase idx
  *byte 89: uchar       => visual trial
  *byte 90: uchar       => lock cursor during cue
 */

#define DATABURST_VERSION ((byte)0x04) 
#define DATABURST_TASK_CODE ((byte)0x01)

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;
	real_T soft_reset;
    
	real_T target_size;
	real_T target_radius;
    real_T target_angle;
	real_T use_random_targets;
	real_T show_target_during_bump;
	
    real_T bump_prob;
    real_T bump_direction;
	real_T bump_floor;
	real_T bump_ceiling;
    real_T bump_step;
	real_T bump_duration;
    real_T bump_ramp;
	
    real_T ct_hold_time;
	real_T bump_delay_low;
	real_T bump_delay_high;
	real_T bump_hold_time;
    real_T reaction_time;
	real_T intertrial_time;
	real_T penalty_time;
    
	real_T hide_cursor;
	real_T recenter_cursor;
	
    real_T stim_prob;
	real_T stim_levels;
    
    real_T training_frequency;
	real_T abort_during_bump;
    real_T force_reaction;
    
    real_T use_staircase;
    real_T stim_code_low;
    
    real_T play_audio;
    real_T visual_prob;
    real_T lock_cursor_during_cue;
    
    real_T audio_cue_prob;
};

#define MY_CLASS_NAME ForcedChoiceBehavior
class ForcedChoiceBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	ForcedChoiceBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	
    
private:
	// Your behavior's instance variables
    LocalParams *params;
	CosineBumpGenerator *bump;
    Staircase * bump_stair[2];
    Staircase * stim_stair[1];

	int num_bump_stairs;
	int num_stim_stairs;
    int bump_staircase_idx;
	int stim_staircase_idx;
	
    CircleTarget *centerTarget;     //target for monkey to hold on while waiting for stimulus
	CircleTarget *smallCenterTarget; // target before trial start that is smaller than center target
    CircleTarget *primaryTarget;    //correct when stimulus is present
	CircleTarget *secondaryTarget;  //correct when no stimulus present
	SquareTarget *errorTarget;      //used as gray mask to indicate error during intertrial
    CircleTarget *centerGoTarget; // target to be used as a go cue
    CircleTarget *primaryGoTarget;
    
	bool bump_trial;
    bool stim_trial;
    bool visual_trial;
	bool training_trial;
    bool audio_trial;

	int bump_dir;
	int tgt_dir;
    float bump_delay;
    int bump_steps;
    int stim_code;
    
    int max_staircase_iterations;
    int staircase_ratio;
	
    Point cursorOffset;
    Point cursor_position_go_cue;
	real_T last_soft_reset;

	// parameters to store past bump and stim parameters
	real_T bump_ceiling_old;
	real_T bump_floor_old;
	real_T bump_step_old;
	real_T stim_levels_old;
	
    real_T movement_time;
    
	// any helper functions you need
	void doPreTrial(SimStruct *S);

};

ForcedChoiceBehavior::ForcedChoiceBehavior(SimStruct *S) : RobotBehavior() {
	params = new LocalParams();
    //create binding map for pulling variables from simulink into the params struct
	this->setNumParams(34);
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			0);
	this->bindParamId(&params->soft_reset,				1);
    
	this->bindParamId(&params->target_size,				2);
	this->bindParamId(&params->target_radius,			3);
	this->bindParamId(&params->target_angle,			4);
	this->bindParamId(&params->use_random_targets,		5);
	this->bindParamId(&params->show_target_during_bump,	6);
    
    this->bindParamId(&params->bump_prob,               7);
    this->bindParamId(&params->bump_direction,          8);
    this->bindParamId(&params->bump_floor,				9);
	this->bindParamId(&params->bump_ceiling,			10);
    this->bindParamId(&params->bump_step,           	11);
	this->bindParamId(&params->bump_duration,			12);
    this->bindParamId(&params->bump_ramp,				13);
    
	this->bindParamId(&params->ct_hold_time,			14);
    this->bindParamId(&params->bump_delay_low,			15);
    this->bindParamId(&params->bump_delay_high,			16);
    this->bindParamId(&params->bump_hold_time,			17);
    this->bindParamId(&params->reaction_time,			18);
    this->bindParamId(&params->intertrial_time,			19);
	this->bindParamId(&params->penalty_time,			20);
    
	this->bindParamId(&params->hide_cursor,				21);
	this->bindParamId(&params->recenter_cursor,			22);
    
	this->bindParamId(&params->stim_prob,				23);
	this->bindParamId(&params->stim_levels,				24);
    
	this->bindParamId(&params->training_frequency,		25);
	this->bindParamId(&params->abort_during_bump,		26);
	this->bindParamId(&params->force_reaction,  		27);
    this->bindParamId(&params->use_staircase,           28);
    this->bindParamId(&params->stim_code_low,           29);
    this->bindParamId(&params->play_audio,              30);
    this->bindParamId(&params->visual_prob,             31);
    this->bindParamId(&params->lock_cursor_during_cue,  32);
    this->bindParamId(&params->audio_cue_prob,          33);
    
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);
	
	last_soft_reset = -1; // force a soft reset of first trial
   
    movement_time = 0;
    
    //define targets
	centerTarget = new CircleTarget();
    smallCenterTarget = new CircleTarget();
	primaryTarget = new CircleTarget(); 
	secondaryTarget = new CircleTarget(); 
    centerGoTarget = new CircleTarget();
    primaryGoTarget = new CircleTarget();
   
	centerTarget->color = Target::Color(160,255,0);
    centerGoTarget->color = Target::Color(255,0,0);
    smallCenterTarget->color = Target::Color(160,255,0);
	primaryTarget->color = Target::Color(255,0,160);
	secondaryTarget->color = Target::Color(255, 0, 160);
    primaryGoTarget->color = Target::Color(255,0,0);
            
	errorTarget = new SquareTarget(0, 0, 100, Target::Color(255, 255, 255));
    // establish flags (default false)
	this->bump_trial = false;
	this->stim_trial = false;
    this->visual_trial = false;
	this->training_trial = false;
    this->audio_trial = false; // this can be paired with a different cue
    
    // establish bump/target directions
	this->bump_dir = 0;
	this->tgt_dir = 0;
    //initialize the bump generator
	this->bump = new CosineBumpGenerator();
    this->bump_delay=0;
    this->bump_steps=16;
    this->stim_code=0;
    this-> last_soft_reset=0;
	
	// initialize the number of staircases to be run simultaneously
	this->num_bump_stairs = 2; // need to match with initialization
	this->num_stim_stairs = 1; // need to match with initialization
    this->bump_staircase_idx = 0;
	this->stim_staircase_idx = 0;
	// initialize the staircase ratio
	this->staircase_ratio = 2;
	
    //initialize the bump staircases
	for(int bump_stair_idx=0; bump_stair_idx < this->num_bump_stairs; bump_stair_idx++) {
		this->bump_stair[bump_stair_idx] = new Staircase();
		this->bump_stair[bump_stair_idx]->setForwardStepSize(3); // forward indicates larger, backwards indicates smaller
		this->bump_stair[bump_stair_idx]->setBackwardStepSize(1);
		this->bump_stair[bump_stair_idx]->setRatio(this->staircase_ratio);
	}
	
	// initialize the stim staircases
	for(int stim_stair_idx=0; stim_stair_idx < this->num_stim_stairs; stim_stair_idx++) {
		this->stim_stair[stim_stair_idx] = new Staircase();
		this->stim_stair[stim_stair_idx]->setForwardStepSize(2); // forward indicates larger, backwards indicates smaller amplitude/code
		this->stim_stair[stim_stair_idx]->setBackwardStepSize(1);
		this->stim_stair[stim_stair_idx]->setRatio(this->staircase_ratio);
	}
    //this->bump_stair=new Staircase();
    //this->stim_stair=new Staircase();
	
    //this->bump_stair->setStepSize(1);
    //this->stim_stair->setForwardStepSize(3);
	//this->stim_stair->setBackwardStepSize(1);
	
    //this->bump_stair->setRatio(this->staircase_ratio);
	//this->stim_stair->setRatio(this->staircase_ratio);
	
	// initialize variables that keep track of if bump/stim parameters changed here
	this->bump_step_old = -1; // negative one so that stairs get initialized
	this->bump_ceiling_old = -1;
	this->bump_floor_old = -1;
	this->stim_levels_old = -1;
    
    
}


void ForcedChoiceBehavior::doPreTrial(SimStruct *S) {
    int startVal;
    int steps;
    int rand_num_bump;
    int rand_num_stim;
    double randNumTrialType;
    
	//set the target direction deg
	if ((int)this->params->use_random_targets) {
		this->tgt_dir = this->random->getInteger(0,359);
	} else {
		this->tgt_dir = this->params->target_angle;
	}

	// Set up target locations, etc.
	centerTarget->radius = params->target_size;
    smallCenterTarget->radius = params->target_size;
    centerGoTarget->radius = params->target_size;
    
    // the targed object defines target->radius as the radius of the target on the screen
    // the target radius input from simulink is the radius of a circle around the center on which the targets are placed
	primaryTarget->radius = params->target_size;
	primaryTarget->centerX = params->target_radius*cos((float)this->tgt_dir * PI/180);
	primaryTarget->centerY = params->target_radius*sin((float)this->tgt_dir * PI/180);
	
    primaryGoTarget->radius = params->target_size;
	primaryGoTarget->centerX = params->target_radius*cos((float)this->tgt_dir * PI/180);
	primaryGoTarget->centerY = params->target_radius*sin((float)this->tgt_dir * PI/180);
    
	secondaryTarget->radius = params->target_size;
	secondaryTarget->centerX = params->target_radius*cos(PI + (float)this->tgt_dir * PI/180);
	secondaryTarget->centerY = params->target_radius*sin(PI + (float)this->tgt_dir * PI/180);

    // Reset cursor offset
    cursorOffset.x = 0;
    cursorOffset.y = 0;
    cursor_position_go_cue.x = 0;
    cursor_position_go_cue.y = 0;
    
	// reset movement time
	this->movement_time = 0;
	
    // modify BUMP staircases if necessary:
    steps=(int)((params->bump_ceiling-params->bump_floor)/params->bump_step);
    startVal=(int)(steps);
	
	this->max_staircase_iterations = steps*2;
	
    if(this->bump_ceiling_old != params->bump_ceiling || // check if parameters have changed
		this->bump_floor_old != params->bump_floor || 
		this->bump_step_old != params->bump_step){
        //reset all staircases
        for(int bump_stair_idx=0; bump_stair_idx < this->num_bump_stairs; bump_stair_idx++) {
            this->bump_stair[bump_stair_idx]->setStartValue(startVal);
            this->bump_stair[bump_stair_idx]->setCurrentValue(startVal);
            this->bump_stair[bump_stair_idx]->setForwardLimit(steps);
            this->bump_stair[bump_stair_idx]->setBackwardLimit(0);
            this->bump_stair[bump_stair_idx]->setStaircaseDirection(-1); // on a success, negative indicates move backwards
            this->bump_stair[bump_stair_idx]->setIteration(0);
        }
        // update old params
        this->bump_ceiling_old = params->bump_ceiling;
        this->bump_floor_old = params->bump_floor;
        this->bump_step_old = params->bump_step;
        
    } else if(this->bump_stair[this->bump_staircase_idx]->getIteration() > this->max_staircase_iterations) { // if we did a bunch of iterations
        // reset this current staircase
        this->bump_stair[this->bump_staircase_idx]->setStartValue(startVal);
        this->bump_stair[this->bump_staircase_idx]->setCurrentValue(startVal);
        this->bump_stair[this->bump_staircase_idx]->setForwardLimit(steps);
        this->bump_stair[this->bump_staircase_idx]->setBackwardLimit(0);
        this->bump_stair[this->bump_staircase_idx]->setStaircaseDirection(-1); // on a success, negative indicates move backwards
        this->bump_stair[this->bump_staircase_idx]->setIteration(0);
        
    }
    
	// see if pairing with an audio cue
    this->audio_trial = this->random->getDouble(0,1) < params->audio_cue_prob;

	// modify STIM staircases if necessary
    startVal=(int)(params->stim_levels);
	
	this->max_staircase_iterations = (int)params->stim_levels*3;
	
    if(this->stim_levels_old != params->stim_levels){ // check if parameters have changed
        //reset all stim staircases
		for(int stim_stair_idx = 0; stim_stair_idx < num_stim_stairs; stim_stair_idx++) {
			this->stim_stair[stim_stair_idx]->setStartValue(startVal);
			this->stim_stair[stim_stair_idx]->setCurrentValue(startVal);
			this->stim_stair[stim_stair_idx]->setForwardLimit((int)params->stim_levels);
			this->stim_stair[stim_stair_idx]->setBackwardLimit(0);
			this->stim_stair[stim_stair_idx]->setStaircaseDirection(-1);
			this->stim_stair[stim_stair_idx]->setIteration(0);
        }
        this->stim_levels_old = params->stim_levels;
    } else if(this->stim_stair[stim_staircase_idx]->getIteration() > this->max_staircase_iterations) {// check if this stim staircase has reached the max iterations
		this->stim_stair[stim_staircase_idx]->setStartValue(startVal);
			this->stim_stair[stim_staircase_idx]->setCurrentValue(startVal);
			this->stim_stair[stim_staircase_idx]->setForwardLimit((int)params->stim_levels);
			this->stim_stair[stim_staircase_idx]->setBackwardLimit(0);
			this->stim_stair[stim_staircase_idx]->setStaircaseDirection(-1);
			this->stim_stair[stim_staircase_idx]->setIteration(0);
	}
	
	//set up the bump
    randNumTrialType = this->random->getDouble(0,1);
    
    this->bump_delay=this->random->getDouble(params->bump_delay_low,params->bump_delay_high);
    
    this->bump_trial= randNumTrialType<params->bump_prob;
    if(this->bump_trial && this->params->use_staircase){
        this->bump_staircase_idx = this->random->getInteger(0,this->num_bump_stairs-1);
        
        this->bump->peak_magnitude= this->bump_stair[bump_staircase_idx]->getCurrentValue()*params->bump_step + params->bump_floor;
        this->bump->hold_duration = params->bump_duration;
        this->bump->rise_time = params->bump_ramp;
        this->bump->direction = (double)(params->bump_direction) * PI/180;		
    } else if(this->bump_trial && !this->params->use_staircase){
        rand_num_bump = this->random->getInteger(0,(int)((params->bump_ceiling-params->bump_floor)/params->bump_step));
        
        this->bump->peak_magnitude = rand_num_bump*params->bump_step + params->bump_floor;
        this->bump->hold_duration = params->bump_duration;
        this->bump->rise_time = params->bump_ramp;
        this->bump->direction = (double)(params->bump_direction) * PI/180;	
    }
    else {
		this->bump->peak_magnitude=0;
	}
    
	/* Select whether this will be a training trial 
	*  If the training frequency is zero we should not see any training trials*/
	
    this->training_trial=(this->random->getDouble() < params->training_frequency);
    
    /* Select whether this will be a stimulation trial */
	this->stim_trial = (randNumTrialType > params->bump_prob && randNumTrialType < params->stim_prob+params->bump_prob);
	
    if(this->stim_trial) {
		// determine which stim staircase to use
        if(this->params->use_staircase) {
            this->stim_staircase_idx = this->random->getInteger(0,this->num_stim_stairs-1);
            this->stim_code=this->stim_stair[stim_staircase_idx]->getCurrentValue();  \
        } else {
            this->stim_code = this->random->getInteger(this->params->stim_code_low,this->params->stim_levels);
        }
       
    }
    // select whether this will be a visual tria
    this->visual_trial = (randNumTrialType > params->bump_prob+params->stim_prob && randNumTrialType < params->stim_prob+params->bump_prob+params->visual_prob);
	
    
    // 
    if(~(this->visual_trial || this->bump_trial || this->stim_trial || this->audio_trial)) {
        this->bump_delay = params->bump_delay_high;
    }
    /* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
    db->addByte(DATABURST_TASK_CODE);
	db->addByte('F');
	db->addByte('C');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);
    
	db->addFloat((float)this->tgt_dir);
	db->addByte((byte)this->params->use_random_targets);
	db->addFloat((float)this->params->target_radius);
	db->addFloat((float)this->params->target_size);
	db->addByte((byte)this->params->show_target_during_bump);
    
    db->addByte((byte)this->bump_trial);
	db->addFloat((float)this->bump->direction);
	db->addFloat((float)this->bump->peak_magnitude);
	db->addFloat((float)this->params->bump_floor);
	db->addFloat((float)this->params->bump_ceiling);
	db->addFloat((float)this->params->bump_step);
	db->addFloat((float)this->params->bump_duration);
	db->addFloat((float)this->params->bump_ramp);
    
	db->addByte((byte)this->stim_trial);
	db->addByte((byte)this->stim_code);
	
	db->addByte((byte)this->training_trial);
    
	db->addByte((byte)this->params->recenter_cursor);
	db->addByte((byte)this->params->hide_cursor);
  
    
	db->addFloat((float)this->params->intertrial_time);
	db->addFloat((float)this->params->penalty_time);
	db->addFloat((float)this->params->bump_hold_time);
	db->addFloat((float)this->params->ct_hold_time);
	db->addFloat((float)this->bump_delay);
	db->addByte((byte)this->params->abort_during_bump);
	db->addByte((byte)this->params->force_reaction);
    
    db->addFloat((float)this->bump_staircase_idx);
    db->addFloat((float)this->bump_stair[bump_staircase_idx]->getCurrentValue());
    
	db->addFloat((float)this->stim_staircase_idx);
	db->addByte((byte)this->visual_trial);
    db->addByte((byte)this->params->lock_cursor_during_cue);
    
	db->start();
}

void ForcedChoiceBehavior::update(SimStruct *S) {
	Target *correctTarget;
	Target *incorrectTarget;
	

    if (this->bump_trial || this->stim_trial || this->visual_trial || this->audio_trial) {
        // want to be in primary target
        correctTarget = primaryTarget;
        if (this->training_trial) {
            incorrectTarget = nullTarget;
        } else { 
            incorrectTarget = secondaryTarget;
        }

    } else {
        // want to be in secondary target
        correctTarget = secondaryTarget;
        if (this->training_trial) {
            incorrectTarget = nullTarget;
        } else { 
            incorrectTarget = primaryTarget;
        }
    }

   
	// State machine
	switch (this->getState()) {
		case STATE_PRETRIAL:
            if(params->play_audio){
                playTone(TONE_MASK);
            }
			updateParameters(S);
			doPreTrial(S);
			setState(STATE_DATA_BLOCK);
			break;
		case STATE_DATA_BLOCK:
            if(params->play_audio){
                playTone(TONE_MASK);
            }
			if (db->isDone()) {
				setState(STATE_CT_ON);
			}
			break;
		case STATE_CT_ON:
			/* first target on */
            if(params->play_audio){
                playTone(TONE_MASK);
            }
			if (smallCenterTarget->cursorInTarget(inputs->cursor)) {
				setState(STATE_CT_HOLD);
                stateTimer->stop(S);
                stateTimer->start(S);
			}
			break;
		case STATE_CT_HOLD:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (stateTimer->elapsedTime(S) > (params->ct_hold_time + this->bump_delay) &&
                     ((this->stim_trial)||(this->bump_trial)||(this->visual_trial)||(this->audio_trial))) {
                if(params->play_audio){
                    playTone(TONE_MASK);
                }
				if(this->stim_trial) {
					setState(STATE_STIM);
                    if(this->audio_trial){
                        playTone(TONE_GO);
                    }
				} else if(this->bump_trial) {
    				if(this->audio_trial){
                        playTone(TONE_GO);
                    }
                    bump->start(S);
					setState(STATE_BUMP);
				} else if(this->visual_trial) {
                    setState(STATE_MOVEMENT);
                } else if(this->audio_trial) {
                    playTone(TONE_GO);
                    setState(STATE_MOVEMENT);
                }
			} else if (stateTimer->elapsedTime(S) > (params->ct_hold_time + this->bump_delay + params->bump_hold_time)){
                playTone(TONE_REWARD);
                setState(STATE_REWARD);
            } else if(params->play_audio){
                playTone(TONE_MASK);
            }
			break;
		case STATE_BUMP:
            if(params->force_reaction){
                if(params->play_audio){
                    playTone(TONE_MASK);
                }
                if(stateTimer->elapsedTime(S) > params->bump_hold_time) {
                    if(params->recenter_cursor || params->lock_cursor_during_cue) {
                        cursorOffset = inputs->cursor;
                    } 
					this->movement_time = stateTimer->elapsedTime(S);
                    setState(STATE_MOVEMENT);
                }
            }else{
                if (!centerTarget->cursorInTarget(inputs->cursor) && params->abort_during_bump) {
                    playTone(TONE_ABORT);
                    setState(STATE_ABORT);
                } else if (stateTimer->elapsedTime(S) > params->bump_hold_time) {
                    playTone(TONE_GO);
                    if(params->recenter_cursor || params->lock_cursor_during_cue) {
                        cursorOffset = inputs->cursor;
                    }   
                    setState(STATE_MOVEMENT);
                }
            }
			break;
		case STATE_STIM:
            if(params->force_reaction){
                if(params->play_audio){
                    playTone(TONE_MASK);
                }
				if(this->bump_trial) { 
					bump->start(S);
					setState(STATE_BUMP);
				}
				else if(stateTimer->elapsedTime(S) > params->bump_hold_time) {
                    if(params->recenter_cursor || params->lock_cursor_during_cue) {
                        cursorOffset = inputs->cursor;
                    } 
					setState(STATE_MOVEMENT);
				}
            }else{
                if (!centerTarget->cursorInTarget(inputs->cursor) && params->abort_during_bump) {
                    playTone(TONE_ABORT);
                    setState(STATE_ABORT);
                } else if (stateTimer->elapsedTime(S) > params->bump_hold_time) {
                    playTone(TONE_GO);
                    if (params->recenter_cursor || params->lock_cursor_during_cue) {
                        cursorOffset = inputs->cursor;
                    }   
                    setState(STATE_MOVEMENT);
                }
            }
			break;
		case STATE_MOVEMENT:
            if (((this->bump_trial || this->stim_trial) && params->force_reaction && params->reaction_time < stateTimer->elapsedTime(S))    ||
                    ((this->audio_trial || this->visual_trial) && params->force_reaction && params->reaction_time+params->bump_hold_time < stateTimer->elapsedTime(S))    ||
                    (incorrectTarget->cursorInTarget(inputs->cursor - cursorOffset)) ) {
                //iterate staircase
                if(this->bump_trial && this->params->use_staircase){
                    this->bump_stair[bump_staircase_idx]->addFailure();
                } 
				if(this->stim_trial && this->params->use_staircase){
                    this->stim_stair[stim_staircase_idx]->addFailure();
                }
                playTone(TONE_FAIL);
				setState(STATE_FAIL);
            } else if (correctTarget->cursorInTarget(inputs->cursor - cursorOffset)) {
				//iterate staircase
                this->movement_time = stateTimer->elapsedTime(S) + this->movement_time;
                
                if(this->bump_trial && this->params->use_staircase){
                    this->bump_stair[bump_staircase_idx]->addSuccess();
                } 
				if(this->stim_trial && this->params->use_staircase){
					this->stim_stair[stim_staircase_idx]->addSuccess();
                }
				
                playTone(TONE_REWARD);
				setState(STATE_REWARD);
			} else if(params->play_audio){
                playTone(TONE_MASK);
            }
			break;
		case STATE_ABORT:
            this->bump->stop();
			if (stateTimer->elapsedTime(S) > params->intertrial_time) {
				setState(STATE_PRETRIAL);
			}
			break;
        case STATE_REWARD:
            this->bump->stop();
             
			if (stateTimer->elapsedTime(S) > params->intertrial_time) {
				setState(STATE_PRETRIAL);
			}
			break;
		case STATE_FAIL:
            this->bump->stop();
            
			if (stateTimer->elapsedTime(S) > params->intertrial_time+ params->penalty_time) {
				setState(STATE_PRETRIAL);
			}
			break;
        case STATE_INCOMPLETE:
			this->bump->stop();
			if (stateTimer->elapsedTime(S) > params->intertrial_time) {
				setState(STATE_PRETRIAL);
			}
			break;
		default:
			setState(STATE_PRETRIAL);
	}
}

void ForcedChoiceBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
    Point bf;

	/* force (0) */
	if (bump->isRunning(S)) {
		bf = bump->getBumpForce(S);
		outputs->force.x = inputs->force.x + bf.x;
		outputs->force.y = inputs->force.y + bf.y;
	} else {
		outputs->force = inputs->force;
        //outputs->force.x = floor((params->bump_ceiling-params->bump_floor));
		//outputs->force.y = floor((params->bump_ceiling-params->bump_floor)/params->bump_step);
	}

	// add in preloading to prevent slop issue
	//outputs->force.x = outputs->force.x + cos(params->bump_direction*PI/180)*(params->bump_floor);
	//outputs->force.y = outputs->force.y + sin(params->bump_direction*PI/180)*(params->bump_floor);
	
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
				outputs->word = WORD_START_TRIAL;
				break;
			case STATE_CT_HOLD:
				outputs->word = WORD_OT_ON(0);
				break;
			case STATE_STIM:
				outputs->word = WORD_STIM(this->stim_code);
//				outputs->word = WORD_STIM(0);
                break;
			case STATE_BUMP:
//				outputs->word = WORD_BUMP(this->bump_stair[this->bump_staircase_idx]->getCurrentValue());
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
	    getState() == STATE_DATA_BLOCK )  {
		outputs->targets[0] = (Target *)smallCenterTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
	} else if(getState() == STATE_MOVEMENT && this->visual_trial) {
        outputs->targets[0] = (Target *)centerGoTarget;
        outputs->targets[1] = this->primaryGoTarget;
        outputs->targets[2] = nullTarget;
    } else if ( getState() == STATE_CT_HOLD ||
                getState() == STATE_BUMP ||
                getState() == STATE_STIM || 
                getState() == STATE_MOVEMENT) {
		outputs->targets[0] = (Target *)centerTarget;
        outputs->targets[1] = this->primaryTarget;
        outputs->targets[2] = nullTarget;
    } else if (getState() == STATE_PENALTY) {
		outputs->targets[0] = this->errorTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
	} else {
		outputs->targets[0] = nullTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
	}

	/* reward (4) */
	
	// currently overwriting above code with a binary reward. 
	outputs->reward = 1000*((isNewState() && (getState() == STATE_REWARD)));
	// movement_time is seconds in the STATE_MOVEMENT
    /*if(isNewState() && (getState() == STATE_REWARD)){
        if(this->bump_trial || this->stim_trial) {
            outputs->reward = 1000*(params->reaction_time+params->bump_hold_time-(double)this->movement_time)/(params->reaction_time);
            if(outputs->reward < 0.25) {
                outputs->reward = 0.25;
            } else if(outputs->reward > 1000) {
                outputs->reward = 1000;
            }
        } else {
            outputs->reward = 750; // no cue, stay in place case. he gets 0.75*water
        }
    } else {
        outputs->reward = 0;
    }*/
    
    //outputs->status[3] = outputs->reward;
    
	/* tone (5) */
	this->outputs->tone_counter = this->tone_counter;
	this->outputs->last_tone_id = this->last_tone_id;

	/* version (6) */
	outputs->version[0] = BEHAVIOR_VERSION_MAJOR;
	outputs->version[1] = BEHAVIOR_VERSION_MINOR;
	outputs->version[2] = BEHAVIOR_VERSION_MICRO;
	outputs->version[3] = BEHAVIOR_VERSION_BUILD;

	/* position (7) */
	// remove cursor during the bump/stim and hold period to avoid reacting to a visual cue if force reaction
    if (params->hide_cursor > 0.1 && (getState() == STATE_BUMP || getState() == STATE_STIM || (params->force_reaction && getState() == STATE_CT_HOLD))) { 
            outputs->position = Point(1E6, 1E6);

    } else if(params->lock_cursor_during_cue > 0.1 && (getState() == STATE_BUMP || getState() == STATE_STIM || (params->force_reaction && getState() == STATE_CT_HOLD))) {
            outputs->position = Point(0,0);
    }
    else { 
        outputs->position = inputs->cursor - cursorOffset;
    } 
}

/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


