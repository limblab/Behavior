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
%  * byte  2-4:	uchar		=> task code 'A' 'F' 'C'
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
	
	real_T sameTargetRight;
	
    real_T idiot_mode;
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME 2AFCBehavior
class 2AFCBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	2AFCBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	CircleTarget *centerTarget;
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
    
	// any helper functions you need
	void doPreTrial(SimStruct *S);

};

COBumpBehavior::COBumpBehavior(SimStruct *S) : RobotBehavior() {

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
	
	this->bindParamId(&params->sameTargetRight,			32);

    this->bindParamId(&params->idiot_mode,              33);
    	
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);
	
	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
	
	last_soft_reset = -1; // force a soft reset of first trial

	centerTarget = new CircleTarget();
	periodTarget = new CircleTarget();
	
	primaryTarget = new CircleTarget(); 
	secondaryTarget = new CircleTarget();
	
 	//centerTarget->color = Target::Color(128, 128, 128);
    centerTarget->color = Target::Color(160, 255, 0);
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
	
	this->is_same_cue=false;
	
	this->ctr_hold=0.0;
	this->delay_hold=0.0;
    this->ot_hold = 0.0;
    
    this->ch_timer = new Timer();

    this->redo_trial = false;
}


void COBumpBehavior::doPreTrial(SimStruct *S) {
	
	int bump_dir;
	bool rate_flag_match;

    if (!this->redo_trial) {
	    //set the target direction
		this->tgt_angle = (int)((this->params->target_angle)) ;

	    // Set up target locations, etc.
	    centerTarget->radius = params->target_size;
		periodTarget->radius = params->target_size;
		
	    primaryTarget->radius = params->target_size;
	    primaryTarget->centerX = params->target_radius*cos((float)this->tgt_angle * PI/180);
	    primaryTarget->centerY = params->target_radius*sin((float)this->tgt_angle * PI/180);
        
		
		secondaryTarget->radius = params->target_size;
	    secondaryTarget->centerX = params->target_radius*cos((float)this->tgt_angle * PI/180);
	    secondaryTarget->centerY = params->target_radius*sin((float)this->tgt_angle * PI/180);
		
        //select the actual center hold time
	    this->ctr_hold=this->random->getDouble(this->params->CH_low,this->params->CH_high);
	    //select the actual delay period hold
	    this->delay_hold=this->random->getDouble(this->params->DP_low,this->params->DP_high);
        //select actual outer target hold
        this->ot_hold=this->random->getDouble(this->params->target_hold_low,this->params->target_hold_high);
	    // Reset primary target color if needed
	    primaryTarget->color = Target::Color(255, 0, 160);
		            
        // stop and reset center hold timer
	    this->ch_timer->stop(S);
	    
		
		// determine if the same cue is used, or if two different cues are used
		this->is_same_cue = (this->random->getDouble() < this->params->same_cue_prob);
		
		// setup cue 1
			// determine if stim or bump
			this->cue_1_is_stim = (this->random->getDouble() < this->params->cue_1_stim_prob);
			
			if(this->cue_1_is_stim) { // deal with stim
				this->cue_1_stim_level = this->random->getInteger(this->params->cue_1_stim_level_low,this->params->cue_1_stim_level_high);
			} else { // cue 1 is a bump
				this->cue_1_bump->hold_duration = this->params->CH_bump_peak_hold;
                this->cue_1_bump->rise_time = this->params->CH_bump_ramp;
                this->cue_1_bump->peak_magnitude = this->params->CH_bump_magnitude;

                this->cue_1_bump->direction = (double)(this->params->cue_1_bump_dir) * PI/180;
			}
		// setup cue 2
			this->cue_2_is_stim = (this->random->getDouble() < this->params->cue_2_stim_prob);
			
			if(this->cue_2_is_stim) { // deal with stim
				this->cue_2_stim_level = this->random->getInteger(this->params->cue_2_stim_level_low,this->params->cue_2_stim_level_high);
			} else { // cue 1 is a bump
				this->cue_2_bump->hold_duration = this->params->CH_bump_peak_hold;
                this->cue_2_bump->rise_time = this->params->CH_bump_ramp;
                this->cue_2_bump->peak_magnitude = this->params->CH_bump_magnitude;

                this->cue_2_bump->direction = (double)(this->params->cue_2_bump_dir) * PI/180;
			}
		
		
		
		// determine which target is the correct target and which one is the incorrect target
		if (this->is_same_cue) {
			// want to be in primary target if sameTargetRight, otherwise want to be in secondary target
			if(this->params->sameTargetRight){
				this->correctTarget = primaryTarget;
				this->incorrectTarget = secondaryTarget;
			} else {
				this->correctTarget = secondaryTarget;
				this->incorrectTarget = primaryTarget;
			}
			
		} else {
			// want to be in secondary target if sameTargetRight, otherwise want to be in primary target
			if(this->params->sameTargetRight){
				this->correctTarget = secondaryTarget;
				this->incorrectTarget = primaryTarget;
			} else {
				this->correctTarget = primaryTarget;
				this->incorrectTarget = secondaryTarget;
			}
		}
		
		

    } //else everything else is the same

	this->redo_trial = false;
		
	
	/* setup the databurst */
	
	
	/// NEED TO DO STILL
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
	db->addFloat((float)this->params->target_radius);
	db->addFloat((float)this->tgt_angle);

	db->addByte((byte)this->params->hide_cursor);
	db->addFloat((float)this->params->hide_radius_min);
	db->addFloat((float)this->params->hide_radius_max);

	db->addByte((byte)this->params->abort_during_bump);
	db->addByte((byte)this->CH_bump);
	db->addByte((byte)this->DP_bump);
	db->addByte((byte)this->M_bump);
	db->addFloat((float)this->bump->hold_duration);
	db->addFloat((float)this->bump->rise_time);
	db->addFloat((float)this->bump->peak_magnitude);
	db->addFloat((float)this->bump->direction);

	db->addByte((byte)this->stim_trial);
    db->addByte((byte)this->params->stimDuringBump);
    db->addByte((byte)this->params->stimInsteadOfBump);
    db->addFloat((float)this->params->stimDelay);

    db->addFloat((float)this->ot_hold);
    db->addByte((byte)this->redo_trial);
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
                this->ch_timer->stop(S);
				this->ch_timer->start(S);
				setState(STATE_CT_HOLD);
			}
			break;
		case STATE_CT_HOLD:
			if (!centerTarget->cursorInTarget(inputs->cursor)) {
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if(this->CH_bump && this->ch_timer->elapsedTime(S)>this->bump_time){
                this->ch_timer->pause(S);
                if(this->stim_trial) {
                        setState(STATE_STIM);
                } else {
                    bump->start(S);
                    setState(STATE_BUMP);
                }
			} else if (this->ch_timer->elapsedTime(S) > this->ctr_hold) {
				setState(STATE_DELAY);
			}
			break;
		case STATE_DELAY:
			if(!centerTarget->cursorInTarget(inputs->cursor)){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if(this->DP_bump && stateTimer->elapsedTime(S) > this->bump_time){
				if(this->stim_trial ){
                        setState(STATE_STIM);
                } else {
                    bump->start(S);
                    setState(STATE_BUMP);
                }
			}else if(stateTimer->elapsedTime(S) > this->delay_hold){
				playTone(TONE_GO);
				setState(STATE_MOVEMENT);
			}
			break;
		case STATE_MOVEMENT:
			if ( primaryTarget->cursorInTarget(inputs->cursor) ){
        		//playTone(TONE_REWARD);
            	//setState(STATE_REWARD);
                setState(STATE_OT_HOLD);
			}else if (this->M_bump && stateTimer->elapsedTime(S) > this->bump_time){ 
				if(this->stim_trial) {
                    setState(STATE_STIM);
                } else {
                    bump->start(S);
                    setState(STATE_BUMP);
                }
			}else if (stateTimer->elapsedTime(S) > this->params->move_time){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
                playTone(TONE_FAIL);
    			setState(STATE_INCOMPLETE);
       		}
			break;         
        case STATE_OT_HOLD:
            if ( stateTimer->elapsedTime(S) > this->ot_hold ) {
                playTone(TONE_REWARD);
                setState(STATE_REWARD);
            } else if ( !primaryTarget->cursorInTarget(inputs->cursor) ){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
                playTone(TONE_ABORT);
                setState(STATE_ABORT);
            }
            break;
		case STATE_BUMP:
			if(this->params->abort_during_bump && (this->CH_bump || this->DP_bump) && !centerTarget->cursorInTarget(inputs->cursor)){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}else if(stateTimer->elapsedTime(S) > this->params->bump_hold_time) {
				if(this->CH_bump){
					//setState(STATE_DELAY);
                    if(centerTarget->cursorInTarget(inputs->cursor)){
                        // reset bump bool so that bump isn't triggered again on this trial
                        this->CH_bump = false;
                        // resume CH timer
                        this->ch_timer->start(S);
                        // Go back to CT_HOLD
                        setState(STATE_CT_HOLD);
                    }
				} else if(this->DP_bump){
					playTone(TONE_GO);
    				setState(STATE_MOVEMENT);
				} else if(this->M_bump && primaryTarget->cursorInTarget(inputs->cursor)){
                    playTone(TONE_REWARD);
                    setState(STATE_REWARD);
                }
            }
            if(this->M_bump && this->params->move_time < (stateTimer->elapsedTime(S)+this->params->bump_delay_time)){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
				playTone(TONE_FAIL);
				setState(STATE_INCOMPLETE);
			}
			break;
		case STATE_STIM:
            if(this->params->stimDuringBump){
                this->stim_trial = false;
                bump->start(S);
                setState(STATE_BUMP);
                break;
            }
			if(this->params->abort_during_bump && (this->CH_bump || this->DP_bump) && !centerTarget->cursorInTarget(inputs->cursor)){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
				playTone(TONE_ABORT);
				setState(STATE_ABORT);
			}else if(stateTimer->elapsedTime(S) > this->params->bump_hold_time ) {
				if(this->CH_bump){
					//setState(STATE_DELAY);
                    if(centerTarget->cursorInTarget(inputs->cursor)){
                        // reset bump bool so that bump isn't triggered again on this trial
                        this->CH_bump = false;
                        // resume CH timer
                        this->ch_timer->start(S);
                        // Go back to CT_HOLD
                        setState(STATE_CT_HOLD);
                    }
				} else if(this->DP_bump){
					playTone(TONE_GO);
    				setState(STATE_MOVEMENT);
				} else if(this->M_bump && primaryTarget->cursorInTarget(inputs->cursor)){
                    playTone(TONE_REWARD);
                    setState(STATE_REWARD);
                }
            }
            if(this->M_bump && this->params->move_time < (stateTimer->elapsedTime(S)+this->params->bump_delay_time)){
                if(this->params->idiot_mode) {
                    this->redo_trial = true;
                }
				playTone(TONE_FAIL);
				setState(STATE_INCOMPLETE);
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
	if (getState() == STATE_BUMP) {
        if (bump->isRunning(S)) {
            outputs->force = bump->getBumpForce(S);
//     		bf = bump->getBumpForce(S);
//     		outputs->force.x = inputs->force.x + bf.x;
//     		outputs->force.y = inputs->force.y + bf.y;
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
	} else if ( (getState() == STATE_STIM) && this->CH_bump) {
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
	} else if ( (getState() == STATE_STIM) && this->DP_bump) {
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = (Target *)(this->primaryTarget);
		outputs->targets[2] = nullTarget;
	} else if ( (getState() == STATE_STIM) && this->M_bump) {
		outputs->targets[0] = (Target *)(this->primaryTarget);
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
	} else if ((getState() == STATE_MOVEMENT) || getState() == STATE_OT_HOLD) {
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
    if (params->hide_cursor > .1) {
		//x_comp=inputs->cursor.x - centerTarget->centerX;
		x_comp=inputs->cursor.x;
		//y_comp=inputs->cursor.y - centerTarget->centerY;
		y_comp=inputs->cursor.y;
		radius=sqrt(x_comp*x_comp + y_comp*y_comp);
		if(getState() == STATE_MOVEMENT || getState() == STATE_BUMP || getState() == STATE_STIM || getState() == STATE_PRETRIAL || getState() == STATE_FAIL || getState() == STATE_ABORT || getState() == STATE_REWARD || getState() == STATE_INCOMPLETE){
			if ( (radius < this->params->hide_radius_max) && (radius > this->params->hide_radius_min)){
				outputs->position = Point(1E6, 1E6);
            } else {
				outputs->position = inputs->cursor;
            }
        } else {
			outputs->position = inputs->cursor;
        }

    } else {
        outputs->position = inputs->cursor;
    }
    
}
/*
 * Include at bottom of your behavior code
 */
#include "common_footer.cpp"


