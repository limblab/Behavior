/* $Id: $
 *
 * Master Control block for behavior: Center out with bumps
 */
 
#pragma warning(disable: 4800)

#define S_FUNCTION_NAME mastercon_ring_reporting
#define S_FUNCTION_LEVEL 2

// Our task code will be in the databurst
#define TASK_DB_DEFINED 1
#include "words.h"
#include "common_header.cpp"

#define PI (3.141592654)
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
#define STATE_OT_HOLD 8

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
%  * Created by modifying version 6 of CObump
 
%  * byte  0:		uchar		=> number of bytes to be transmitted
%  * byte  1:		uchar		=> version number (in this case 1)
%  * byte  2-4:		uchar		=> task code 'R' 'R' 'B'
%  * bytes 5-6:		uchar       => version code
%  * byte  7-8:		uchar		=> version code (micro)

%  * bytes 9-12:	float		=> center hold time
%  * bytes 13-16:	float		=> delay time
%  * bytes 17-20:	float		=> move time
%  * bytes 21-24:	float		=> bump delay time
%  * bytes 25-28:	float		=> bump hold time
%  * bytes 29-32:	float		=> intertrial time
%  * bytes 33-36:	float		=> penalty time

%  * bytes 37-40:	float		=> target size
%  * bytes 41-44:   float       => big target size
%  * bytes 45-48:   float       => outer target hold time
%  * bytes 49-52:	float		=> target angle
%  * bytes 53-56:   float       => movement length (target radius)
%  * bytes 57-60:   float       => target width (OT_size)
 
%  * byte 61:		uchar		=> hide cursor during bump
%  * byte 62:       uchar       => hide cursor during movement
%  * byte 63:		uchar		=> abort during bumps

%  * bytes 64-67:	float		=> bump hold at peak
%  * bytes 68-71:	float		=> bump rise time
%  * bytes 72-75:	float		=> bump magnitude
%  * bytes 76-79:	float		=> bump direction
%  * byte 80:       uchar       => do bump 
 
%  * byte 81:		uchar		=> stim trial
%  * byte 82:		uchar		=> stim during bump
%  * byte 83:		uchar		=> stim instead of bump
%  * bytes 84-87:   float       => stim delay
%  * byte 88:       uchar        => catch trial

%  * byte 89:       uchar       => show ring
%  * byte 90:       uchar       => show outer target
%  * byte 91:       uchar       => use square targets
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
	real_T big_target_size;
    
    real_T OT_size;
    real_T OT_depth;
    real_T move_length;
    real_T center_X_offset;
    real_T center_Y_offset;
        
	real_T target_floor;
	real_T target_ceiling;
	real_T num_targets;
	real_T use_random_targets;
    real_T prior_kap;
    
	real_T hide_cursor_during_bump;
    real_T recenter_cursor;
    real_T hide_cursor_during_movement;
    	real_T abort_during_bump;
        
    // up to three different bump levels
	real_T bump_mag_one;
	real_T bump_mag_two;
	real_T bump_mag_three;
	// relative frequency of occurence for each bump magnitude
	real_T bump_freq_one;
	real_T bump_freq_two;
	real_T bump_freq_three;

    real_T force_rise_time;
    real_T force_peak_time;
    
	real_T stim_prob;
	real_T stim_levels;
    real_T stimDuringBump;
    real_T stimInsteadOfBump;
    
    real_T catch_rate;
    
    real_T show_ring;
    real_T show_target_rate;
    real_T use_square_targets;
    
    real_T target_angle_offset;
    real_T outer_target_size;

    real_T stim_delay;
    real_T repeat_failures;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME RingReportingBehavior
class RingReportingBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	RingReportingBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	CircleTarget *centerTarget;
    CircleTarget *bigCenterTarget;
    
	ArcTarget *outerTarget;
    ArcTarget *targetBar;
    
    // for training a monkey - circle targets instead of arc targets
    SquareTarget *primaryTarget;
    
	bool stim_trial;
    bool catch_trial;
	bool do_bump;
    double bump_time;

    Point cursor_offset;
    Point cursor_end_point;
    
	CosineBumpGenerator *bump;

	LocalParams *params;
	real_T last_soft_reset;
    
    double cursor_extent;
    
	double tgt_angle;
    double current_trial_shift;
	double reward_rate;
	double ctr_hold;
	double delay_hold;
    double ot_hold;
    
    bool show_target;
    bool prev_fail;
    // center hold timer
    Timer *ch_timer;
    
	// any helper functions you need
	void doPreTrial(SimStruct *S);
    void updateCursorExtent(SimStruct *S); // updates cursor extent (used for windowing)

};

RingReportingBehavior::RingReportingBehavior(SimStruct *S) : RobotBehavior() {

	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using

	this->setNumParams(48);
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,            0);
	this->bindParamId(&params->soft_reset,              1);
	this->bindParamId(&params->CH_low,                  2);
	this->bindParamId(&params->CH_high,                 3);
	this->bindParamId(&params->DP_low,                  4);
	this->bindParamId(&params->DP_high,                 5);
	this->bindParamId(&params->move_time,               6);
	this->bindParamId(&params->target_hold_low,         7);
	this->bindParamId(&params->target_hold_high,		8);
	this->bindParamId(&params->bump_delay_time,         9);
	this->bindParamId(&params->bump_hold_time,          10);
	this->bindParamId(&params->intertrial_time,         11);
	this->bindParamId(&params->penalty_time,            12);

	this->bindParamId(&params->target_size,             13);
    this->bindParamId(&params->big_target_size,         14);
    
	this->bindParamId(&params->OT_size,                 15);
	this->bindParamId(&params->OT_depth,                16);
    this->bindParamId(&params->center_X_offset,         17);
    this->bindParamId(&params->center_Y_offset,         18);
    
	this->bindParamId(&params->num_targets,             19);
	this->bindParamId(&params->use_random_targets,		20);
    
    this->bindParamId(&params->prior_kap,               21);

	this->bindParamId(&params->hide_cursor_during_bump, 22);
	this->bindParamId(&params->hide_cursor_during_movement,23);
    this->bindParamId(&params->recenter_cursor,         24);
    this->bindParamId(&params->abort_during_bump,       25);
    
    this->bindParamId(&params->bump_mag_one,            26);
    this->bindParamId(&params->bump_mag_two,            27);
    this->bindParamId(&params->bump_mag_three,          28);
    
    this->bindParamId(&params->bump_freq_one,           29);
    this->bindParamId(&params->bump_freq_two,           30);
    this->bindParamId(&params->bump_freq_three,         31);
    
    this->bindParamId(&params->force_rise_time,         32);
    this->bindParamId(&params->force_peak_time,         33);
    
    this->bindParamId(&params->stim_prob,               34);
	this->bindParamId(&params->stim_levels,             35);
    this->bindParamId(&params->stimDuringBump,          36);
    this->bindParamId(&params->stimInsteadOfBump,       37);
    
    this->bindParamId(&params->catch_rate,              38);
    this->bindParamId(&params->show_ring,               39);
    this->bindParamId(&params->show_target_rate,        40);
    this->bindParamId(&params->use_square_targets,      41);
    
    this->bindParamId(&params->move_length,             42);
    this->bindParamId(&params->target_angle_offset,     43);
    
    this->bindParamId(&params->outer_target_size,       44);
    this->bindParamId(&params->stim_delay,              45);
    
    this->bindParamId(&params->repeat_failures,         46);
    
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);
	
	// This function now fetches all of the parameters into the variables
	// as defined above.
	this->updateParameters(S);
	
	last_soft_reset = -1; // force a soft reset of first trial

	centerTarget = new CircleTarget();
    bigCenterTarget = new CircleTarget();
    outerTarget = new ArcTarget(0,0,0,0,5);
    targetBar = new ArcTarget(0,0,0,0,8);
	primaryTarget = new SquareTarget(); 
	
	this->bump = new CosineBumpGenerator();
	this->tgt_angle=0;

    this->stim_trial = false;
	this->do_bump=false;
    this->catch_trial = false;
    
    this->bump_time = 0;

	this->reward_rate=0.6;
	this->ctr_hold=0.0;
	this->delay_hold=0.0;
    this->ot_hold = 0.0;
    
    this->ch_timer = new Timer();
    
    this->show_target = false;
    
    this->prev_fail = 0;
}

void RingReportingBehavior::updateCursorExtent(SimStruct *S){
	cursor_extent = sqrt((inputs->cursor.x-cursor_offset.x)*(inputs->cursor.x-cursor_offset.x)
					   + (inputs->cursor.y-cursor_offset.y)*(inputs->cursor.y-cursor_offset.y));
}

void RingReportingBehavior::doPreTrial(SimStruct *S) {
	double tgt_sep;
	double CH_sep;
	double DP_sep;
	double M_sep;
	double temp;
	double bump_rate_denom;
    double current_trial_bumpmag;
	int bump_dir;
	bool rate_flag_match;
    
    double act_bf_one;
    double act_bf_two;
    double act_bf_three;
    
    double bump_rand;
    double total_bump_freq;
    
    // reset cursor offset
    cursor_offset.x = 0;
    cursor_offset.y = 0;
    cursor_end_point.x = 0;
    cursor_end_point.y = 0;
    
    //select the actual center hold time
    this->ctr_hold=this->random->getDouble(this->params->CH_low,this->params->CH_high);
    //select the actual delay period hold
    this->delay_hold=this->random->getDouble(this->params->DP_low,this->params->DP_high);
    //select actual outer target hold
    this->ot_hold=this->random->getDouble(this->params->target_hold_low,this->params->target_hold_high);

    // stop and reset center hold timer
    this->ch_timer->stop(S);
    
    /* set the reward rate for this trial */
    this->reward_rate=.6;
    
    // if we are repeating failures, update parameters only if 
    // previous trial was not a fail -- fail = fail, abort, incomplete
    if(!this->params->repeat_failures || (this->params->repeat_failures && !this->prev_fail)) {
        //set the target direction
        if(params->use_random_targets) {
            this->current_trial_shift = random->getVonMises(params->prior_kap);
        } else {
            this->current_trial_shift = 2*PI*(random->getInteger(1,params->num_targets)/params->num_targets);
            this->current_trial_shift += params->target_angle_offset*PI/180;
        }   
        this->tgt_angle = this->current_trial_shift;

        // Set up target locations, etc.
        centerTarget->centerX = 0.0;
        centerTarget->centerY = 0.0;
        centerTarget->radius = params->target_size;
        centerTarget->color = Target::Color(255, 0, 0);

        bigCenterTarget->centerX = 0.0;
        bigCenterTarget->centerY = 0.0;
        bigCenterTarget->radius = params->big_target_size;
        bigCenterTarget->color = Target::Color(255, 0, 0);

        outerTarget->r = params->move_length;
        outerTarget->theta = this->current_trial_shift;
        outerTarget->span = (params->OT_size)*PI/180;
        outerTarget->height = params->OT_depth;

        targetBar->r = params->move_length;
        targetBar->theta = 0;
        targetBar->span = 2*PI-0.00001;
        targetBar->height = params->OT_depth+0.1;

        // training target
        primaryTarget->centerX = (params->move_length-0.1)*cos((float)this->current_trial_shift);
        primaryTarget->centerY = (params->move_length-0.1)*sin((float)this->current_trial_shift);
        primaryTarget->width = params->outer_target_size;
        primaryTarget->color = Target::Color(255, 0, 0);

        // Select whether this will be a stimulation trial, catch trial, or normal trial
        temp =  this->random->getDouble();
        if(temp < this->params->catch_rate){ // catch trial
            this->stim_trial = false;
            this->do_bump = false;
            this->catch_trial = true;

            this->bump->peak_magnitude = 0;
            this->bump->direction = -10000;
        } else if(temp < this->params->catch_rate + this->params->stim_prob){ // stim trial
            this->stim_trial = true;
            if(params->stimDuringBump){ // check if still doing a bump
                this->do_bump = true;
            } else {
                this->do_bump = false;
            }
            this->catch_trial = false;
        } else{ // normal bump trial
            this->stim_trial = false;
            this->do_bump = true;
            this->catch_trial = false;
        }

        // select if this is a training target and we show the answer target from the start
        this->show_target = (this->random->getDouble() < this->params->show_target_rate);

        //pick which bump this is:
        if(this->do_bump){
            bump_rand = random->getDouble();

            total_bump_freq = fabs(params->bump_freq_one) + fabs(params->bump_freq_two) +
                    fabs(params->bump_freq_three);
            if(total_bump_freq==0){
                total_bump_freq = 1;
            }

            act_bf_one = fabs(params->bump_freq_one)/total_bump_freq;
            act_bf_two = fabs(params->bump_freq_two)/total_bump_freq;
            act_bf_three = fabs(params->bump_freq_three)/total_bump_freq;

            if(bump_rand <= act_bf_one){
                current_trial_bumpmag = params->bump_mag_one;
            } else if(bump_rand <= act_bf_one + act_bf_two) {
                current_trial_bumpmag = params->bump_mag_two;
            } else if(bump_rand <= act_bf_one + act_bf_two + act_bf_three) {
                current_trial_bumpmag = params->bump_mag_three;
            } else { // no bump
                current_trial_bumpmag = 0;
            }
        }

        this->bump->direction		= this->current_trial_shift;
        this->bump->rise_time		= params->force_rise_time;
        this->bump->hold_duration   = params->force_peak_time;
        this->bump->peak_magnitude  = current_trial_bumpmag;
    
    }
    
    /* initialize cursor extent */
    updateCursorExtent(S);
    
	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('R');
	db->addByte('R');
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
    db->addFloat((float)this->params->big_target_size);
    db->addFloat((float)this->ot_hold);
	db->addFloat((float)this->tgt_angle);
    db->addFloat((float)this->params->move_length);
    db->addFloat((float)this->params->OT_size); // target width
    
	db->addByte((byte)this->params->hide_cursor_during_bump);
    db->addByte((byte)this->params->hide_cursor_during_movement);
    db->addByte((byte)this->params->abort_during_bump);
	
    db->addFloat((float)this->bump->hold_duration);
	db->addFloat((float)this->bump->rise_time);
	db->addFloat((float)this->bump->peak_magnitude);
	db->addFloat((float)this->bump->direction);
    db->addByte((byte)this->do_bump);
    
	db->addByte((byte)this->stim_trial);
    db->addByte((byte)this->params->stimDuringBump);
    db->addByte((byte)this->params->stimInsteadOfBump);
    db->addFloat((float)this->params->stim_delay);
    
    db->addByte((byte)this->catch_trial);
    
    db->addByte((byte)this->params->show_ring);
    db->addByte((byte)this->show_target);
    db->addByte((byte)this->params->use_square_targets);
    
    db->start();
}

void RingReportingBehavior::update(SimStruct *S) {

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
                this->ch_timer->stop(S);
				setState(STATE_CT_HOLD);
			}
			break;
		case STATE_CT_HOLD:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if(stateTimer->elapsedTime(S) > this->ctr_hold){
                if(this->stim_trial) {
                        setState(STATE_STIM); // state stim will move to state bump
                } 
                else { // catch trials will set bump mag to 0, so no need for extra logic
                    bump->start(S);
                    setState(STATE_BUMP);
                }
			}
			break;
		case STATE_DELAY:
			if(!bigCenterTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if(stateTimer->elapsedTime(S) > this->delay_hold){
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_MOVEMENT:
            if(stateTimer->elapsedTime(S) > params->move_time){
                setState(STATE_INCOMPLETE);
            } 
            else if(!this->params->use_square_targets && !this->params->show_ring && outerTarget->cursorInTarget(inputs->cursor - cursor_offset)) { // arc targets but no ring, for training
                cursor_end_point = inputs->cursor - cursor_offset;
                setState(STATE_OT_HOLD);
            }
            else if(this->params->show_ring && this->params->end_at_ring && cursor_extent > params->move_length - params->OT_depth*0.5){ // end when hitting ring if shown and requested
                cursor_end_point = inputs->cursor - cursor_offset;
                setState(STATE_OT_HOLD);
            }
            else if(this->params->use_square_targets && primaryTarget->cursorInTarget(inputs->cursor - cursor_offset)){ // circle targets
                cursor_end_point = inputs->cursor - cursor_offset;
                setState(STATE_OT_HOLD);
			}
			break;         
        case STATE_OT_HOLD:
            if(this->params->use_square_targets && primaryTarget->cursorInTarget(cursor_end_point)){ // use circle targets case
                playTone(TONE_REWARD);
                setState(STATE_REWARD);
            } else if (!this->params->use_square_targets && outerTarget->cursorInTarget(cursor_end_point) ){
                playTone(TONE_REWARD);
                setState(STATE_REWARD);
			} else {
                playTone(TONE_ABORT);
                setState(STATE_PENALTY);
            }
            break;
		case STATE_BUMP:
			if(this->params->abort_during_bump && !bigCenterTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (!this->bump->isRunning(S)) {
                if(this->params->recenter_cursor){
                    cursor_offset = inputs->cursor;
                }
                setState(STATE_DELAY);
            }
			break;
		case STATE_STIM:
            if(this->params->stimDuringBump){
                bump->start(S);
                setState(STATE_BUMP);
                break;
            }
			if(this->params->abort_during_bump && !bigCenterTarget->cursorInTarget(inputs->cursor)){
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}else if(stateTimer->elapsedTime(S) > this->params->bump_hold_time ) {
				setState(STATE_DELAY);
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

void RingReportingBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
    Point bf;
	double radius;
    double x_comp;
    double y_comp;
    double cursor_end_angle;
    
    updateCursorExtent(S);
    /* update prev_fail flag */
    if(getState() == STATE_REWARD) {
        prev_fail = 0;
    } else if(getState() == STATE_FAIL || 
            getState() == STATE_ABORT || 
            getState() == STATE_INCOMPLETE) {
        prev_fail = 1;
    }
    
	/* force (0) */
    if (bump->isRunning(S)) {
        outputs->force = bump->getBumpForce(S);
//     		bf = bump->getBumpForce(S);
//     		outputs->force.x = inputs->force.x + bf.x;
//     		outputs->force.y = inputs->force.y + bf.y;
    } else {
        outputs->force = inputs->force;
    }
    

	/* status (1) */
 	outputs->status[0] = getState();
    //outputs->status[0] = bumpmag_local;
	outputs->status[1] = trialCounter->successes;
    //outputs->status[1] = this->tgt_angle; 
	outputs->status[2] = trialCounter->aborts;
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
            case STATE_OT_HOLD:
                outputs->word = WORD_OUTER_TARGET_HOLD;
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
	if (getState() == STATE_CT_ON || getState() == STATE_CT_HOLD){ // only show small center target
        outputs->targets[0] = (Target *)centerTarget;
        outputs->targets[1] = nullTarget;
        outputs->targets[2] = nullTarget;
    } else if(getState() == STATE_DELAY || 
            getState() == STATE_BUMP || 
            getState() == STATE_STIM) { 
                outputs->targets[0] = (Target *)bigCenterTarget; // center target
                if(this->params->show_ring) { // large ring if requested
                    outputs->targets[1] = (Target *)targetBar;
                } else {
                    outputs->targets[1] = nullTarget;
                }
                if(this->params->use_square_targets) { // if training and using circle targets, display outer target
                    outputs->targets[2] = (Target *)primaryTarget;
                } else if(this->show_target) { // else display outer ring target if training trial
                    outputs->targets[2] = (Target *)outerTarget;
                } else { // otherwise do not show answer
                    outputs->targets[2] = nullTarget;
                }
	}else if(getState() == STATE_MOVEMENT || 
            getState() == STATE_OT_HOLD){
                outputs->targets[0] = nullTarget; // no center target
                if(this->params->show_ring) { // large ring if requested
                    outputs->targets[1] = (Target *)targetBar;
                } else {
                    outputs->targets[1] = nullTarget;
                }
                if(this->params->use_square_targets) { // if training and using circle targets, display outer target
                    outputs->targets[2] = (Target *)primaryTarget;
                } else if(this->show_target) { // else display outer ring target if training trial
                    outputs->targets[2] = (Target *)outerTarget;
                } else { // otherwise do not show answer
                    outputs->targets[2] = nullTarget;
                }
    }else if (getState() == STATE_PENALTY || 
            getState() == STATE_FAIL || 
            getState() == STATE_REWARD) {
		outputs->targets[0] = nullTarget; // no center target
		if(this->params->show_ring) { //large ring if requested
            outputs->targets[1] = (Target *)targetBar;
        } else {
            outputs->targets[1] = nullTarget;
        }
		if(this->params->use_square_targets) { // if training and using circle targets, display outer target
            outputs->targets[2] = (Target *)primaryTarget;
        } else { // else display outer ring target 
            outputs->targets[2] = (Target *)outerTarget;
        } 
	} else {
		outputs->targets[0] = nullTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
	}

	/* reward (4) */
	// outputs->reward = (isNewState() && (getState() == STATE_REWARD));
    if(isNewState() && getState() == STATE_REWARD) {
        // outputs->reward should be between 0 and 1, 1 at center of tgt,
        // decaying to 0 near edge of tgt and 0 if not a reward
        cursor_end_angle = 180/PI*atan2(this->cursor_end_point.y,this->cursor_end_point.x);
        // linear decay
        outputs->reward = 1-abs(this->outerTarget->theta - cursor_end_angle)/(this->outerTarget->span/2.0);    
    } else {
        outputs->reward = 0;
    }
	/* tone (5) */
	this->outputs->tone_counter = this->tone_counter;
	this->outputs->last_tone_id = this->last_tone_id;

	/* version (6) */
	outputs->version[0] = BEHAVIOR_VERSION_MAJOR;
	outputs->version[1] = BEHAVIOR_VERSION_MINOR;
	outputs->version[2] = BEHAVIOR_VERSION_MICRO;
	outputs->version[3] = BEHAVIOR_VERSION_BUILD;

	/* position (7) */
    if (params->hide_cursor_during_bump > .1 && (getState() == STATE_BUMP || getState() == STATE_STIM)) {
        outputs->position = Point(1E6, 1E6);
    } else if(params->hide_cursor_during_movement > 0.1 && (getState() == STATE_DELAY || getState() == STATE_MOVEMENT)) {
        outputs->position = Point(1E6, 1E6);
    } else if(getState() == STATE_OT_HOLD || getState() == STATE_REWARD || getState() == STATE_FAIL || getState() == STATE_PENALTY) {
        outputs->position = cursor_end_point;
    } else {
        outputs->position = inputs->cursor - cursor_offset;
    }

   
}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


