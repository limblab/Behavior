/* $Id: $
 *
 * Master Control block for behavior: bump psychophysics 2-bump choice
 */
 

#pragma warning(disable: 4800)

#define S_FUNCTION_NAME mastercon_CO_bump
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
#define STATE_DELAY 3
#define STATE_STIM 4
#define STATE_BUMP 5
#define STATE_MOVEMENT 6
#define STATE_PENALTY 7

/* 
 * STATE_REWARD STATE_ABORT STATE_FAIL STATE_INCOMPLETE STATE_DATA_BLOCK 
 * are all defined in Behavior.h Do not use state numbers above 64 (0x40)
 */

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

% * Version 1 (0x01)
%  * ----------------
%  * byte  0:		uchar		=> number of bytes to be transmitted
%  * byte  1:		uchar		=> version number (in this case 0)
%  * byte  2-4:	uchar		=> task code 'C' 'O' 'B'
%  * bytes 5-6:	uchar       => version code
%  * byte  7-8:	uchar		=> version code (micro)
%  * bytes 9-12:  float		=> target angle
%  * byte	 13:	uchar		=> random target flag
%  * bytes 14-17:	float		=> target floor (minimum angle(deg) target can take in random target assignment)
%  * bytes 18-21:	float		=> target ceiling (maximum angle(deg) target can take in random target assignment)
%  * bytes 22-25:	float		=> target incriment(deg)
%  * bytes 26-29: float		=> bump magnitude
%  * bytes 30-33: float		=> bump direction
%  * bytes 34-37: float		=> bump duration
%  * bytes 38-41: float		=> bump ramp
%  * byte  42:	uchar		=> stim trial flag
%  * bytes 43-46: float		=> stimulation probability 
%  * bytes 47-50: float		=> target radius
%  * bytes 51-54: float		=> target size
%  * bytes 55-58: float		=> intertrial time
%  * bytes 59-62: float		=> penalty time
%  * bytes 63-66: float		=> bump hold time
%  * bytes 67-70: float		=> center hold time
%  * bytes 71-74: float		=> bump delay time
%  * byte  75:	uchar		=> flag for whether or not the cursor is hidden during movement
%  * bytes 76-79: float		=> radius from center within which the cursor will be hidden
%  */
	
#define DATABURST_VERSION ((byte)0x01) 
#define DATABURST_TASK_CODE ((byte)0x01)

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;
	real_T soft_reset;
	real_T CH_low;
	real_T CH_high;
	real_T DP_low;
	real_T DP_high;
	real_T move_time;
	real_T target_hold_low;
	real_T target_hold_high;
	real_T bump_delay_time;
	real_T bump_hold_time;
    real_T intertrial_time;
	real_T penalty_time;
	real_T target_size;
	real_T target_radius;
	real_T target_angle;
	real_T target_floor;
	real_T target_ceiling;
	real_T num_tgts;
	real_T use_random_targets;
	real_T hide_cursor;
	real_T hide_radius_min;
	real_T hide_radius_max;
	real_T hidden_cursor_training;
    real_T abort_during_bump;
	real_T catch_rate;
	real_T bi_directional_bumps;
	real_T do_CH_bump;
	real_T CH_bump_rate;
	real_T CH_bump_peak_hold;
    real_T CH_bump_ramp;
    real_T CH_bump_magnitude;
    real_T CH_bump_dir_floor;
    real_T CH_bump_dir_ceil;
    real_T CH_bump_num_dir;
	real_T do_DP_bump;
	real_T DP_bump_rate;
	real_T DP_bump_peak_hold;
    real_T DP_bump_ramp;
    real_T DP_bump_magnitude;
    real_T DP_bump_dir_floor;
    real_T DP_bump_dir_ceil;
    real_T DP_bump_num_dir;
	real_T do_M_bump;
	real_T M_bump_rate;
	real_T M_bump_peak_hold;
    real_T M_bump_ramp;
    real_T M_bump_magnitude;
    real_T M_bump_dir_floor;
    real_T M_bump_dir_ceil;
    real_T M_bump_num_dir;
	real_T stim_prob;
	real_T stim_levels;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME COBumpBehavior
class COBumpBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	COBumpBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	CircleTarget *centerTarget;
	CircleTarget *primaryTarget;

	SquareTarget *errorTarget;
    
	bool stim_trial;
	bool do_bump;
	bool CH_bump;
	bool DP_bump;
	bool M_bump;

	int bump_dir;
    Point cursorOffset;

	CosineBumpGenerator *bump;

	LocalParams *params;
	real_T last_soft_reset;

	int tgt_angle;
	double reward_rate;
	float ctr_hold;
	float delay_hold;
	// any helper functions you need
	void doPreTrial(SimStruct *S);

};

COBumpBehavior::COBumpBehavior(SimStruct *S) : RobotBehavior() {

	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using

	this->setNumParams(52);
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,			0);
	this->bindParamId(&params->soft_reset,				1);
	this->bindParamId(&params->CH_low,					2);
	this->bindParamId(&params->CH_high,					3);
	this->bindParamId(&params->DP_low,					4);
	this->bindParamId(&params->DP_high,					5);
	this->bindParamId(&params->move_time,				6);
	this->bindParamId(&params->target_hold_low,			7);
	this->bindParamId(&params->target_hold_high,		8);
	this->bindParamId(&params->bump_delay_time,			9);
	this->bindParamId(&params->bump_hold_time,			10);
	this->bindParamId(&params->intertrial_time,			11);
	this->bindParamId(&params->penalty_time,			12);

	this->bindParamId(&params->target_size,				13);
	this->bindParamId(&params->target_radius,			14);
	this->bindParamId(&params->target_angle,			15);
	this->bindParamId(&params->target_floor,			16);
	this->bindParamId(&params->target_ceiling,			17);
	this->bindParamId(&params->num_tgt,					18);
	this->bindParamId(&params->use_random_targets,		19);
    
	this->bindParamId(&params->hide_cursor,				20);
	this->bindParamId(&params->hide_radius_min,			21);
	this->bindParamId(&params->hide_radius_max,			22);

	this->bindParamId(&params->catch_rate,				23);
	this->bindParamId(&params->bi_directional_bumps,	24);
    this->bindParamId(&params->abort_during_bump,	    25);

	this->bindParamId(&params->do_CH_bump,				26);
	this->bindParamId(&params->CH_bump_rate,			27);
	this->bindParamId(&params->CH_bump_peak_hold,		28);
    this->bindParamId(&params->CH_bump_ramp,			29);
	this->bindParamId(&params->CH_bump_magnitude,		30);
    this->bindParamId(&params->CH_bump_dir_floor,		31);
    this->bindParamId(&params->CH_bump_dir_ceil,		32);
    this->bindParamId(&params->CH_bump_num_dir,			33);

	this->bindParamId(&params->do_DP_bump,				34);
	this->bindParamId(&params->DP_bump_rate,			35);
	this->bindParamId(&params->DP_bump_peak_hold,		36);
    this->bindParamId(&params->DP_bump_ramp,			37);
	this->bindParamId(&params->DP_bump_magnitude,		38);
    this->bindParamId(&params->DP_bump_dir_floor,		39);
    this->bindParamId(&params->DP_bump_dir_ceil,		40);
    this->bindParamId(&params->DP_bump_num_dir,			41);

	this->bindParamId(&params->do_M_bump,				42);
	this->bindParamId(&params->M_bump_rate,				43);
	this->bindParamId(&params->M_bump_peak_hold,		44);
    this->bindParamId(&params->M_bump_ramp,				45);
	this->bindParamId(&params->M_bump_magnitude,		46);
    this->bindParamId(&params->M_bump_dir_floor,		47);
    this->bindParamId(&params->M_bump_dir_ceil,			48);
    this->bindParamId(&params->M_bump_num_dir,			49);

	this->bindParamId(&params->stim_prob,				50);
	this->bindParamId(&params->stim_levels,				51);
    	
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);
	
	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
	
	last_soft_reset = -1; // force a soft reset of first trial

	centerTarget = new CircleTarget();
	primaryTarget = new CircleTarget(); 
 
	centerTarget->color = Target::Color(128, 128, 128);
	primaryTarget->color = Target::Color(160, 255, 0);

	errorTarget = new SquareTarget(0, 0, 100, Target::Color(255, 255, 255));

	this->stim_trial = false;
	this->bump_dir = 0;
	this->bump = new CosineBumpGenerator();
	this->tgt_angle=0;

	this->do_bump=false;
	this->CH_bump=false;
	this->DP_bump=false;
	this->M_bump=false;

	this->reward_rate=0.6;
	this->ctr_hold=0.0;
	this->delay_hold=0.0;
}


void COBumpBehavior::doPreTrial(SimStruct *S) {
	int num_tgt_dirs;	//number of target directions there will be between target floor and target ceiling
	int tgt_sep;
	int tgt_num;
	int CH_sep;
	int DP_sep;
	int M_sep;
	double temp;
	double bump_rate_denom;

	//set the target direction
	if ((int)this->params->use_random_targets) {
		tgt_sep = (int)floor((this->params->target_ceiling - this->params->target_floor)/this->params->num_tgt);
		this->tgt_angle = (int)this->params->target_floor + (int)this->params->num_tgt*tgt_sep;
	} else {
		this->tgt_angle = (int)((180/PI)*(this->params->target_angle)) ;
	}

	// Set up target locations, etc.
	centerTarget->radius = params->target_size;

	primaryTarget->radius = params->target_size;
	primaryTarget->centerX = params->target_radius*cos((float)this->tgt_angle * PI/180);
	primaryTarget->centerY = params->target_radius*sin((float)this->tgt_angle * PI/180);
	
	// Select whether this will be a stimulation trial 
		this->stim_trial=(this->random->getDouble() < params->stim_prob);

	//identify if this is a bump trial:
		if(!this->stim_trial && this->params->catch_rate<1 && (this->params->do_CH_bump || this->params->do_DP_bump || this->params->do_M_bump)){
			this->do_bump=(this->random->getDouble()>params->catch_rate);
		} else {
			this->do_bump=false;
			this->bump->peak_magnitude = 0;
			this->bump->direction = -10000;
		}
	//pick what type of bump this is:
		if(this->do_bump){
			//get the sum of the rate values for flagged bump types:
			bump_rate_denom=0.0;
			if(this->params->do_CH_bump){
				bump_rate_denom= bump_rate_denom + this->params->CH_bump_rate;
			}
			if(this->params->do_DP_bump){
				bump_rate_denom= bump_rate_denom + this->params->DP_bump_rate;
			}
			if(this->params->do_M_bump){
				bump_rate_denom= bump_rate_denom + this->params->M_bump_rate;
			} 
			//select what phase the bump will be in using the aggregate rates
			temp=this->random->getDouble(0,bump_rate_denom);
			if(temp <= (this->params->CH_bump_rate*(int)this->params->do_CH_bump)){
				this->CH_bump=true;
				this->DP_bump=false;
				this->M_bump=false;
			} else if(temp <= (this->params->CH_bump_rate*(int)this->params->do_CH_bump + this->params->DP_bump_rate*(int)this->params->do_DP_bump)){
				this->CH_bump=false;
				this->DP_bump=true;
				this->M_bump=false;
			} else { //no extra if-clause needed because we know this is a bump trial, and if we got here then move bumps must be enabled
				this->CH_bump=false;
				this->DP_bump=false;
				this->M_bump=true;
			}
			//now set up a bump direction relative to the target direction based on the configuration for the selected phase
			if(this->CH_bump){
				CH_sep=(this->params->CH_bump_dir_ceil - this->params->CH_bump_dir_floor)/this->params->CH_bump_num_dir;
				bump_dir=(int)this->params->CH_bump_dir_floor + CH_sep*this->random->getInteger(0,this->params->CH_bump_num_dir);
				this->bump->hold_duration = this->params->CH_bump_peak_hold;
				this->bump->rise_time = this->params->CH_bump_ramp;
				this->bump->peak_magnitude = this->params->CH_bump_magnitude;
			} else if(this->DP_bump){
				DP_sep=(this->params->DP_bump_dir_ceil - this->params->DP_bump_dir_floor)/this->params->DP_bump_num_dir;
				bump_dir=(int)this->params->DP_bump_dir_floor + DP_sep*this->random->getInteger(0,this->params->DP_bump_num_dir);
				this->bump->hold_duration = this->params->DP_bump_peak_hold;
				this->bump->rise_time = this->params->DP_bump_ramp;
				this->bump->peak_magnitude = this->params->DP_bump_magnitude;
			} else{
				M_sep=(this->params->M_bump_dir_ceil - this->params->M_bump_dir_floor)/this->params->M_bump_num_dir;
				bump_dir=(int)this->params->M_bump_dir_floor + M_sep*this->random->getInteger(0,this->params->M_bump_num_dir);
				this->bump->hold_duration = this->params->M_bump_peak_hold;
				this->bump->rise_time = this->params->M_bump_ramp;
				this->bump->peak_magnitude = this->params->M_bump_magnitude;
			}
			if( this->params->bi_directional_bumps){
				if(this->random->getBool()){
					bump_dir=(bump_dir+180)%360;
				}
			}
			this->bump->direction = ((double)(this->tgt_angle + this->bump_dir)) * PI/180;
		} else {
			this->CH_bump=false;
			this->DP_bump=false;
			this->M_bump=false;
		}
		
	//select the actual center hold time
		this->ctr_hold=this->params->CH_low+(float)this->random->getDouble((double)this->params->CH_low,(double)this->params->CH_high);
	//select the actual delay period hold
		this->delay_hold=this->params->DP_low+(float)this->random->getDouble((double)this->params->DP_low,(double)this->params->DP_high);
	// Reset primary target color if needed
		primaryTarget->color = Target::Color(255, 0, 160);
	/* set the reward rate for this trial */
		this->reward_rate=.6;

	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('C');
	db->addByte('O');
	db->addByte('B');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
	db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);

	db->addFloat((float)this->ctr_hold);
	db->addFloat((float)this->delay_hold);
	db->addFloat((float)this->params->move_time);
	db->addFloat((float)this->params->bump_delay_time);
	db->addFloat((float)this->params->bump_hold_time);
	db->addFloat((float)this->params->intertrial_time);
	db->addFloat((float)this->params->penalty_time);

	db->addFloat((float)this->params->target_size);
	db->addFloat((float)this->params->target_radius);
	db->addFloat((float)this->tgt_angle);

	db->addByte((byte)this->params->hide_cursor);
	db->addFloat((float)this->params->hide_radius_min);
	db->addFloat((float)this->params->hide_radius_max);
	db->addFloat((float)this->params->hidden_cursor_training);

	db->addByte((byte)this->params->abort_during_bump);
	db->addByte((byte)this->params->catch_rate);
	db->addByte((byte)this->CH_bump);
	db->addByte((byte)this->DP_bump);
	db->addByte((byte)this->M_bump);
	db->addFloat((float)this->bump->hold_duration);
	db->addFloat((float)this->bump->rise_time);
	db->addFloat((float)this->bump->peak_magnitude);
	db->addFloat((float)this->bump_dir);

	db->addByte((byte)this->stim_trial);
	db->addFloat((float)this->params->stim_prob);
	db->start();
}

void COBumpBehavior::update(SimStruct *S) {

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
			} else if(this->CH_bump && stateTimer->elapsedTime(S)>this->params->bump_delay_time){
				bump->start(S);
				setState(STATE_BUMP);
			}else if (stateTimer->elapsedTime(S) > this->ctr_hold) {
				setState(STATE_DELAY);
			}
			break;
		case STATE_DELAY:
			if(!centerTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}else if(this->DP_bump && stateTimer->elapsedTime(S) > this->params->bump_delay_time){
				bump->start(S);
				setState(STATE_BUMP);
			}else if(stateTimer->elapsedTime(S) > this->delay_hold){
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_MOVEMENT:
			if ( primaryTarget->cursorInTarget(inputs->cursor) ){
        		playTone(TONE_REWARD);
            	setState(STATE_REWARD);
			}else if (M_bump && stateTimer->elapsedTime(S) > this->params->bump_delay_time){ 
				bump->start(S);
				setState(STATE_BUMP);
			}else if (stateTimer->elapsedTime(S) > this->params->move_time){
                playTone(TONE_FAIL);
    			setState(STATE_INCOMPLETE);
       		}
			
			break;         
		case STATE_BUMP:
            if(stateTimer->elapsedTime(S) > this->params->bump_hold_time) {
				if(this->CH_bump){
					setState(STATE_DELAY);
				} else if(this->DP_bump){
					playTone(TONE_GO);
    				setState(STATE_MOVEMENT);
				} 
            }else if(this->M_bump && primaryTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_REWARD);
				setState(STATE_REWARD);
			} else if(this->M_bump && this->params->move_time < (stateTimer->elapsedTime(S)+this->params->bump_delay_time)){
				playTone(TONE_FAIL);
				setState(STATE_INCOMPLETE);
			}
			break;
		case STATE_STIM:
			if (stateTimer->elapsedTime(S) > this->params->bump_hold_time){
				if (this->random->getDouble() < this->reward_rate){
					playTone(TONE_REWARD);
					setState(STATE_REWARD);
				} else {
					playTone(TONE_FAIL);
					setState(STATE_PENALTY);
				}
            } 
			break;   
		case STATE_PENALTY:
			if (stateTimer->elapsedTime(S) > this->params->penalty_time) {
				setState(STATE_FAIL);
			}
			break;
		case STATE_ABORT:
        case STATE_REWARD:
		case STATE_FAIL:
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

void COBumpBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
    Point bf;
	double radius;
    double x_comp;
    double y_comp;

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
    //outputs->status[0] = bumpmag_local;
	outputs->status[1] = trialCounter->successes;
    //outputs->status[1] = this->tgt_angle; 
	outputs->status[2] = trialCounter->aborts;
//    outputs->status[2] = this->bump_dir;
 	outputs->status[3] = trialCounter->failures;
 	outputs->status[4] = trialCounter->incompletes;
  
	/* word(2) */
	if (db->isRunning()) {
		outputs->word = db->getByte();
	} else if (isNewState()) {
		switch (getState()) {
			case STATE_PRETRIAL:
				outputs->word = WORD_START_TRIAL;
				break;
			case STATE_DELAY:
				outputs->word = WORD_OT_ON(0);
				break;
			case STATE_STIM:
				outputs->word = WORD_STIM(this->random->getInteger(0,(int)this->params->stim_levels));
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
	if (getState() == STATE_CT_ON || getState() == STATE_CT_HOLD) {
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
	} else if(getState() == STATE_DELAY) {
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = (Target *)(this->primaryTarget);
		outputs->targets[2] = nullTarget;
	} else if ( (getState() == STATE_BUMP) && this->CH_bump) {
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
	} else if ( (getState() == STATE_BUMP) && this->DP_bump) {
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = (Target *)(this->primaryTarget);
		outputs->targets[2] = nullTarget;
	} else if ( (getState() == STATE_BUMP) && this->M_bump) {
		outputs->targets[0] = (Target *)(this->primaryTarget);
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
	} else if ((getState() == STATE_MOVEMENT) ) {
		outputs->targets[0] = (Target *)(this->primaryTarget);
	    outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;

	} else if (getState() == STATE_PENALTY) {
		outputs->targets[0] = (Target *)(this->errorTarget);
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
        
	} else {
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
    x_comp=inputs->cursor.x - centerTarget->centerX;
    y_comp=inputs->cursor.y - centerTarget->centerY;
	radius=sqrt(x_comp*x_comp + y_comp*y_comp	)	/	params->target_radius;
    
    if (params->hide_cursor > .1) {
        if (params->hidden_cursor_training > .1){
            if(getState() == STATE_MOVEMENT || getState() == STATE_BUMP || getState() == STATE_STIM ){
                if ( radius<params->hide_radius_max && radius>params->hide_radius_min){
                    outputs->position = Point(1E6, 1E6);
                } else {
                    outputs->position = inputs->cursor;
                }
            } else {
                outputs->position = inputs->cursor;
            }
        } else {
            if(getState() == STATE_MOVEMENT || getState() == STATE_BUMP || getState() == STATE_STIM || getState() == STATE_PRETRIAL || getState() == STATE_FAIL || getState() == STATE_ABORT || getState() == STATE_REWARD || getState() == STATE_INCOMPLETE){
                outputs->position = Point(1E6, 1E6);
            } else {
                outputs->position = inputs->cursor;
            }
        }
    } else {
        outputs->position = inputs->cursor;
    }
    
}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


