/* $Id: $
 *
 * Master Control block for behavior: Center out with bumps
 */
 
#pragma warning(disable: 4800)

#define S_FUNCTION_NAME mastercon_2afc_stim
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
#define STATE_OT_HOLD 8
#define STATE_CUE 9
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
 *
% * Version 1 (0x01)
%  * ----------------
%  * byte  0:		uchar		=> number of bytes to be transmitted
%  * byte  1:		uchar		=> version number (in this case 0)
%  * byte  2-4:	uchar		=> task code 'A' 'F' 'C'
%  * bytes 5-6:	uchar       => version code
%  * byte  7-8:	uchar		=> version code (micro)
%  * byte 9-12: float       => center hold time
%  * byte 13-16: float      => delay hold time
%  * byte 17-20: float      => movement time
%  * byte 21-24: float      => bump delay time
%  * byte 25-28: float      => bump hold time
%  * byte 29-32: float      => intertrial time
%  * byte 33-36: float      => penalty time
%  * byte 37-40: float      => target size
%  * byte 41-44: float      => big target size
%  * byte 45-48: float      => target distance
%  * byte 49-52: float      => target angle
%  * byte 53: uchar         => hide cursor
%  * byte 54: uchar         => abort during bump
%  * byte 55-58: float      => cue 1 bump hold duration
%  * byte 59-62: float      => cue 1 bump rise time
%  * byte 63-66: float      => cue 1 bump peak magnitude
%  * byte 67-70: float      => cue 1 bump direction
%  * byte 71-74: float      => cue 2 bump hold duration
%  * byte 75-78: float      => cue 2 bump rise time
%  * byte 79-82: float      => cue 2 bump peak magnitude
%  * byte 83-86: float      => cue 2 bump direction
%  * byte 87: uchar         => cue 1 is stim
%  * byte 88: uchar         => cue 2 is stim
%  * byte 89-92: float      => cue 1 stim code
%  * byte 93-96: float      => cue 2 stim code
%  * byte 97: uchar         => is same cue
%  * byte 98: uchar         => use cue 1
%  * byte 99: uchar         => cue 1 first
%  * byte 100-103: float    => outer target hold
%  * byte 104-107: float    => period duration
%  * byte 108-111: float    => interperiod duration
%  * byte 112: uchar        => redo trial
%  * byte 113: uchar        => same target right 
%  * byte 114: uchar        => training trial  
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
	real_T hide_cursor;
	real_T abort_during_bump;
		
	real_T cue_1_bump_dir;
	real_T cue_2_bump_dir;
	
	real_T bump_peak_hold;
	real_T bump_ramp;
	real_T bump_magnitude;

	real_T cue_1_stim_prob;
	real_T cue_1_stim_level_low;
	real_T cue_1_stim_level_high;
	
	real_T cue_2_stim_prob;
	real_T cue_2_stim_level_low;
	real_T cue_2_stim_level_high;
    
	real_T same_cue_prob;
	
	real_T period_duration;
	real_T interperiod_duration;
	
	real_T same_target_right;
	
    real_T idiot_mode;
    real_T big_target_size;
    real_T training_trial_prob;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME TwoAFCBehavior
class TwoAFCBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	TwoAFCBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	CircleTarget *centerTarget;
    CircleTarget *bigCenterTarget;
    
	CircleTarget *primaryTarget;
	CircleTarget *secondaryTarget;
	CircleTarget *periodTarget;
	
	SquareTarget *errorTarget;
    
	Target *correctTarget;
	Target *incorrectTarget;
	
	bool cue_1_is_stim;
	bool cue_2_is_stim;
	int cue_1_stim_level;
	int cue_2_stim_level;
	
	bool is_same_cue;
	bool use_cue_1;
	bool cue_1_first;
	bool did_first_cue;
	bool did_second_cue;

	Point cursorOffset;

	CosineBumpGenerator *cue_1_bump;
	CosineBumpGenerator *cue_2_bump;
	
	LocalParams *params;
	real_T last_soft_reset;

	int tgt_angle;
	double ctr_hold;
	double delay_hold;
    double ot_hold;
    
    // center hold timer
    Timer *ch_timer;

    // whether to redo the trial (idiot mode)
    bool redo_trial;
    bool training_trial;
    
	int stim_level;
	// any helper functions you need
	void doPreTrial(SimStruct *S);

};

TwoAFCBehavior::TwoAFCBehavior(SimStruct *S) : RobotBehavior() {

	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using

	this->setNumParams(36);
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,            0);
	this->bindParamId(&params->soft_reset,        		1);
	this->bindParamId(&params->CH_low,             		2);
	this->bindParamId(&params->CH_high,              	3);
	this->bindParamId(&params->DP_low,              	4);
	this->bindParamId(&params->DP_high,              	5);
	this->bindParamId(&params->move_time,              	6);
	this->bindParamId(&params->target_hold_low,         7);
	this->bindParamId(&params->target_hold_high,      	8);
	this->bindParamId(&params->bump_delay_time,        	9);
	this->bindParamId(&params->bump_hold_time,          10);
	this->bindParamId(&params->intertrial_time,         11);
	this->bindParamId(&params->penalty_time,            12);

	this->bindParamId(&params->target_size,             13);
	this->bindParamId(&params->target_radius,           14);
	this->bindParamId(&params->target_angle,            15);
	this->bindParamId(&params->hide_cursor,             16);
	this->bindParamId(&params->abort_during_bump,       17);
	
	this->bindParamId(&params->cue_1_bump_dir,			18);
	this->bindParamId(&params->cue_2_bump_dir,			19);
	
	this->bindParamId(&params->bump_peak_hold,          20);
	this->bindParamId(&params->bump_ramp,              	21);
	this->bindParamId(&params->bump_magnitude,          22);
	
	this->bindParamId(&params->cue_1_stim_prob,         23);
	this->bindParamId(&params->cue_1_stim_level_low,    24);
	this->bindParamId(&params->cue_1_stim_level_high,   25);
	
	this->bindParamId(&params->cue_2_stim_prob,         26);
	this->bindParamId(&params->cue_2_stim_level_low,    27);
	this->bindParamId(&params->cue_2_stim_level_high,   28);
	
	this->bindParamId(&params->same_cue_prob,			29);
	
	this->bindParamId(&params->period_duration,			30);
	this->bindParamId(&params->interperiod_duration,	31);
	
	this->bindParamId(&params->same_target_right,       32);

    this->bindParamId(&params->idiot_mode,              33);
    this->bindParamId(&params->big_target_size,         34);
    this->bindParamId(&params->training_trial_prob,     35);
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);
	
	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
	
	last_soft_reset = -1; // force a soft reset of first trial

	centerTarget = new CircleTarget();
    bigCenterTarget = new CircleTarget();
    
	periodTarget = new CircleTarget();
	
	primaryTarget = new CircleTarget(); 
	secondaryTarget = new CircleTarget();
	
 	//centerTarget->color = Target::Color(128, 128, 128);
    centerTarget->color = Target::Color(255, 0, 0);
    bigCenterTarget->color = centerTarget->color;
    
	periodTarget->color = Target::Color(128,128,128);
    
	primaryTarget->color = Target::Color(160, 255, 0);
	secondaryTarget->color = Target::Color(160, 255, 0);
	
	errorTarget = new SquareTarget(0, 0, 100, Target::Color(255, 255, 255));

	this->cue_1_bump = new CosineBumpGenerator();
	this->cue_2_bump = new CosineBumpGenerator();
	
	this->tgt_angle=0;

	this->cue_1_is_stim=false;
	this->cue_2_is_stim=false;
	this->cue_1_stim_level=0;
	this->cue_2_stim_level=0;
	
	this->did_first_cue = false;
	this->did_second_cue = false;
	this->use_cue_1 = false;
	this->cue_1_first = false;
	
	this->is_same_cue=false;
	
	this->ctr_hold=0.0;
	this->delay_hold=0.0;
    this->ot_hold = 0.0;
    
    this->ch_timer = new Timer();

	this->stim_level = 0;

    this->redo_trial = false;
}


void TwoAFCBehavior::doPreTrial(SimStruct *S) {
	
	this->did_first_cue = false;
	this->did_second_cue = false;

    if (!this->redo_trial) {
	    //set the target direction
		this->tgt_angle = (int)((this->params->target_angle)) ;

	    // Set up target locations, etc.
	    centerTarget->radius = params->target_size;
        bigCenterTarget->radius = params->big_target_size;
		periodTarget->radius = params->big_target_size;
		
	    primaryTarget->radius = params->target_size;
	    primaryTarget->centerX = params->target_radius*cos((float)this->tgt_angle * PI/180);
	    primaryTarget->centerY = params->target_radius*sin((float)this->tgt_angle * PI/180);
        
		
		secondaryTarget->radius = params->target_size;
	    secondaryTarget->centerX = params->target_radius*cos((float)this->tgt_angle * PI/180 + PI);
	    secondaryTarget->centerY = params->target_radius*sin((float)this->tgt_angle * PI/180 + PI);
		
        //select the actual center hold time
	    this->ctr_hold=this->random->getDouble(this->params->CH_low,this->params->CH_high);
	    //select the actual delay period hold
	    this->delay_hold=this->random->getDouble(this->params->DP_low,this->params->DP_high);
        //select actual outer target hold
        this->ot_hold=this->random->getDouble(this->params->target_hold_low,this->params->target_hold_high);
        
        // stop and reset center hold timer
	    this->ch_timer->stop(S);
	    
		
		// determine if the same cue is used, or if two different cues are used
		this->is_same_cue = (this->random->getDouble() < this->params->same_cue_prob);
		
		// determine which cue is first
		this->cue_1_first = (this->random->getDouble() < 0.5);
		
		// determine which cue to use if the same cue is used.
		this->use_cue_1 = (this->random->getDouble() < 0.5);
		
		// determine if training trial
        this->training_trial = (this->random->getDouble() < this->params->training_trial_prob);
        
		// setup cue 1
			// determine if stim or bump
			this->cue_1_is_stim = (this->random->getDouble() < this->params->cue_1_stim_prob);
			
			if(this->cue_1_is_stim) { // deal with stim
				this->cue_1_stim_level = this->random->getInteger(this->params->cue_1_stim_level_low,this->params->cue_1_stim_level_high);
			} else { // cue 1 is a bump
				this->cue_1_bump->hold_duration = this->params->bump_peak_hold;
                this->cue_1_bump->rise_time = this->params->bump_ramp;
                this->cue_1_bump->peak_magnitude = this->params->bump_magnitude;

                this->cue_1_bump->direction = (double)(this->params->cue_1_bump_dir) * PI/180;
			}
		// setup cue 2
			this->cue_2_is_stim = (this->random->getDouble() < this->params->cue_2_stim_prob);
			
			if(this->cue_2_is_stim) { // deal with stim
				this->cue_2_stim_level = this->random->getInteger(this->params->cue_2_stim_level_low,this->params->cue_2_stim_level_high);
			} else { // cue 1 is a bump
				this->cue_2_bump->hold_duration = this->params->bump_peak_hold;
                this->cue_2_bump->rise_time = this->params->bump_ramp;
                this->cue_2_bump->peak_magnitude = this->params->bump_magnitude;

                this->cue_2_bump->direction = (double)(this->params->cue_2_bump_dir) * PI/180;
			}
		
		
		
		// determine which target is the correct target and which one is the incorrect target
		if (this->is_same_cue) {
			// want to be in primary target if same_target_right, otherwise want to be in secondary target
			if(this->params->same_target_right){
				this->correctTarget = primaryTarget;
				this->incorrectTarget = secondaryTarget;
			} else {
				this->correctTarget = secondaryTarget;
				this->incorrectTarget = primaryTarget;
			}
			
            // switch 1 of the cues to match the other based on use_cue_1
            if(use_cue_1){
                this->cue_2_is_stim = this->cue_1_is_stim;
				this->cue_2_stim_level = this->cue_1_stim_level;
				this->cue_2_bump->hold_duration = this->cue_1_bump->hold_duration;
                this->cue_2_bump->rise_time = this->cue_1_bump->rise_time;
                this->cue_2_bump->peak_magnitude = this->cue_1_bump->peak_magnitude;

                this->cue_2_bump->direction = this->cue_1_bump->direction;
            } else {
                this->cue_1_is_stim = this->cue_2_is_stim;
				this->cue_1_stim_level = this->cue_2_stim_level;
				this->cue_1_bump->hold_duration = this->cue_2_bump->hold_duration;
                this->cue_1_bump->rise_time = this->cue_2_bump->rise_time;
                this->cue_1_bump->peak_magnitude = this->cue_2_bump->peak_magnitude;

                this->cue_1_bump->direction = this->cue_2_bump->direction;
            }
            
		} else {
			// want to be in secondary target if same_target_right, otherwise want to be in primary target
			if(this->params->same_target_right){
				this->correctTarget = secondaryTarget;
				this->incorrectTarget = primaryTarget;
			} else {
				this->correctTarget = primaryTarget;
				this->incorrectTarget = secondaryTarget;
			}
		}
		
        if(this->training_trial){
            this->incorrectTarget = (Target *)nullTarget;
        }
		

    } //else everything else is the same

	this->redo_trial = false;
		
	
	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('A');
	db->addByte('F');
	db->addByte('C');
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
	db->addFloat((float)this->params->target_radius);
	db->addFloat((float)this->tgt_angle);

	db->addByte((byte)this->params->hide_cursor);
	db->addByte((byte)this->params->abort_during_bump);
    
	db->addFloat((float)this->cue_1_bump->hold_duration);
	db->addFloat((float)this->cue_1_bump->rise_time);
	db->addFloat((float)this->cue_1_bump->peak_magnitude);
	db->addFloat((float)this->cue_1_bump->direction);

    db->addFloat((float)this->cue_2_bump->hold_duration);
	db->addFloat((float)this->cue_2_bump->rise_time);
	db->addFloat((float)this->cue_2_bump->peak_magnitude);
	db->addFloat((float)this->cue_2_bump->direction);
    
	db->addByte((byte)this->cue_1_is_stim);
    db->addByte((byte)this->cue_2_is_stim);
    
    db->addFloat((float)this->cue_1_stim_level);
    db->addFloat((float)this->cue_2_stim_level);
    
    db->addByte((byte)this->is_same_cue);
    db->addByte((byte)this->use_cue_1);
    db->addByte((byte)this->cue_1_first);
    
    db->addFloat((float)this->ot_hold);
    db->addFloat((float)this->params->period_duration);
    db->addFloat((float)this->params->interperiod_duration);
    db->addByte((byte)this->redo_trial);
    db->addByte((byte)this->params->same_target_right);
    db->addByte((byte)this->training_trial);
    
	db->start();
}

void TwoAFCBehavior::update(SimStruct *S) {

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
				this->ch_timer->start(S);
				setState(STATE_CT_HOLD);
			}
			break;
		case STATE_CT_HOLD:
			if (!bigCenterTarget->cursorInTarget(inputs->cursor)) {
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if(this->ch_timer->elapsedTime(S) > this->ctr_hold || (this->did_first_cue && this->ch_timer->elapsedTime(S) > this->params->interperiod_duration)) { // leave the state
				if(!this->did_first_cue) {
					setState(STATE_CUE);
				} else if(!this->did_second_cue){
					setState(STATE_CUE);
				} else {
					setState(STATE_DELAY);
				}
			}
			break;
		case STATE_CUE:
			if(!this->did_first_cue) { // send first cue
				if(this->cue_1_first) { // send cue 1
					if(this->cue_1_is_stim) { // state stim
						this->stim_level = cue_1_stim_level;
						setState(STATE_STIM);
						
					} else { // state bump
						cue_1_bump->start(S);
						setState(STATE_BUMP);
					}
				
				} else { // send cue 2
					if(this->cue_2_is_stim){
						this->stim_level = cue_2_stim_level;
						setState(STATE_STIM);
					} else {
						cue_2_bump->start(S);
						setState(STATE_BUMP);
					}
					
				}
				
				this->did_first_cue = true;
			} else if(!this->did_second_cue) { //send second cue
				if(!this->cue_1_first) { // send cue 1
					if(this->cue_1_is_stim) { // state stim
						this->stim_level = cue_1_stim_level;
						setState(STATE_STIM);
						
					} else { // state bump
						cue_1_bump->start(S);
						setState(STATE_BUMP);
					}
				
				} else { // send cue 2
					if(this->cue_2_is_stim){
						this->stim_level = cue_2_stim_level;
						setState(STATE_STIM);
					} else {
						cue_2_bump->start(S);
						setState(STATE_BUMP);
					}
					
				}
				this->did_second_cue = true;
			}
		
			break;
		case STATE_DELAY:
			if(!bigCenterTarget->cursorInTarget(inputs->cursor)){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if(stateTimer->elapsedTime(S) > this->delay_hold){
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_MOVEMENT:
			if (correctTarget->cursorInTarget(inputs->cursor) || incorrectTarget->cursorInTarget(inputs->cursor)){
                setState(STATE_OT_HOLD);
			}else if (stateTimer->elapsedTime(S) > this->params->move_time){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
                playTone(TONE_FAIL);
    			setState(STATE_INCOMPLETE);
       		}
			break;         
        case STATE_OT_HOLD:
            if (stateTimer->elapsedTime(S) > this->ot_hold ) {
                if(correctTarget->cursorInTarget(inputs->cursor)) {
                    playTone(TONE_REWARD);
                    setState(STATE_REWARD);
                } else if(incorrectTarget->cursorInTarget(inputs->cursor)) {
                    playTone(TONE_FAIL);
                    setState(STATE_PENALTY);
                }

            } else if (!(correctTarget->cursorInTarget(inputs->cursor) || incorrectTarget->cursorInTarget(inputs->cursor))){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
                playTone(TONE_ABORT);
                setState(STATE_ABORT);
            }
            break;
		case STATE_BUMP:
			if(this->params->abort_during_bump && !bigCenterTarget->cursorInTarget(inputs->cursor)){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if(stateTimer->elapsedTime(S) > this->params->bump_hold_time) {
				this->ch_timer->stop(S);
				this->ch_timer->start(S);
				setState(STATE_CT_HOLD);
            }
			break;
		case STATE_STIM:
			if(this->params->abort_during_bump && !bigCenterTarget->cursorInTarget(inputs->cursor)){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}else if(stateTimer->elapsedTime(S) > this->params->bump_hold_time ) {
				this->ch_timer->stop(S);
				this->ch_timer->start(S);
				setState(STATE_CT_HOLD);
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
			this->cue_1_bump->stop();
			this->cue_2_bump->stop();
			if (stateTimer->elapsedTime(S) > params->intertrial_time) {
				setState(STATE_PRETRIAL);
			}
			break;
		default:
			setState(STATE_PRETRIAL);
	}
}

void TwoAFCBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
    Point bf;
	double radius;
    double x_comp;
    double y_comp;

	/* force (0) */
	if (getState() == STATE_BUMP) {
        if (this->cue_1_bump->isRunning(S)) {
            outputs->force = cue_1_bump->getBumpForce(S);
//     		bf = bump->getBumpForce(S);
//     		outputs->force.x = inputs->force.x + bf.x;
//     		outputs->force.y = inputs->force.y + bf.y;
            
        } else if(this->cue_2_bump->isRunning(S)) {
            outputs->force = cue_2_bump->getBumpForce(S);
        } else {
            outputs->force.x = 0;
            outputs->force.y = 0;
        }
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
				outputs->word = WORD_STIM(this->stim_level);
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
	// Center Target
	if (getState() == STATE_CT_ON){
        outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = (Target *)nullTarget;
		outputs->targets[2] = (Target *)nullTarget;
    } else if(getState() == STATE_CT_HOLD || getState() == STATE_DELAY ) {
		outputs->targets[0] = (Target *)bigCenterTarget;
		outputs->targets[1] = (Target *)correctTarget;
		outputs->targets[2] = (Target *)incorrectTarget;
	} else if(getState() == STATE_BUMP || getState() == STATE_STIM) {
		outputs->targets[0] = (Target *)periodTarget;
		outputs->targets[1] = (Target *)correctTarget;
		outputs->targets[2] = (Target *)incorrectTarget;
	}else if ((getState() == STATE_MOVEMENT) || getState() == STATE_OT_HOLD) {
		outputs->targets[0] = (Target *)(this->correctTarget);
	    outputs->targets[1] = (Target *)(this->incorrectTarget);
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

	outputs->position = inputs->cursor;
    
    
}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


