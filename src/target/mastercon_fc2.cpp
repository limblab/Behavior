/* $Id: $
 *
 * Master Control block for behavior: Center out with bumps
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
#define STATE_DELAY 3
#define STATE_STIM 4
#define STATE_BUMP 5
#define STATE_MOVEMENT 6
#define STATE_PENALTY 7
#define STATE_OT_HOLD 8
#define STATE_AUDIO 9
#define STATE_CUE_ON 10
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

 */
#define DATABURST_VERSION ((byte)0x01) 
#define DATABURST_TASK_CODE ((byte)0x01)

// This must be custom defined for your behavior
struct LocalParams {
	real_T master_reset;
	real_T soft_reset;
	
    real_T target_size;
	real_T target_dist;
    real_T target_angle;
    real_T use_random_targets;
    real_T show_tgt_during_bump;
    
    real_T CH_time;
	real_T cue_delay_low;
	real_T cue_delay_high;
    real_T cue_hold_time;
    real_T move_time;
    
    real_T intertrial_time;
	real_T penalty_time;

    real_T hide_cursor_during_cue;
    real_T recenter_cursor_after_cue;
    real_T lock_cursor_during_cue;
    
    real_T training_prob;
    real_T abort_during_cue;
    real_T force_reaction_time;
    
	real_T stim_prob;
    real_T audio_prob;
    real_T pair_stim_audio;
    
	real_T stim_levels;
    real_T stim_code0_duration;
    real_T stim_code1_duration;
    real_T stim_code2_duration;
    real_T stim_code3_duration;
    real_T stim_code4_duration;
    real_T stim_code5_duration;
    real_T stim_code6_duration;
    real_T stim_code7_duration;
    real_T stim_code8_duration;
    real_T stim_code9_duration;
    real_T stim_code10_duration;
    real_T stim_code11_duration;
    real_T stim_code12_duration;
    real_T stim_code13_duration;
    real_T stim_code14_duration;
    real_T stim_code15_duration;
    
    real_T audio_levels;
    real_T audio_code0_duration;
    real_T audio_code1_duration;
    real_T audio_code2_duration;
    real_T audio_code3_duration;
    real_T audio_code4_duration;
    real_T audio_code5_duration;
    real_T audio_code6_duration;
    real_T audio_code7_duration;
    real_T audio_code8_duration;
    real_T audio_code9_duration;
    real_T audio_code10_duration;
    real_T audio_code11_duration;
    real_T audio_code12_duration;
    real_T audio_code13_duration;
    real_T audio_code14_duration;
    real_T audio_code15_duration;
    
};

/**
 * This is the behavior class.  You must extend "Behavior" and implement
 * at least a constructor and the functions:
 *   void update(SimStruct *S)
 *   void calculateOutputs(SimStruct *S)
 *
 * You must also update the definition below with the name of your class
 */
#define MY_CLASS_NAME RTOffsetBehavior
class RTOffsetBehavior : public RobotBehavior {
public:
	// You must implement these three public methods
	RTOffsetBehavior(SimStruct *S);
	void update(SimStruct *S);
	void calculateOutputs(SimStruct *S);	

private:
	// Your behavior's instance variables
	CircleTarget *centerTarget;
	CircleTarget *primaryTarget;

	SquareTarget *errorTarget;
    
	bool stim_trial;
    bool audio_trial;
    bool catch_trial;
    
    int stim_level;
    int audio_level;
    
    double cue_time;
    double cue_duration;
    double stim_dur_list[16];
    double audio_dur_list[16];
    
    double stim_grace_period;
    
    Point cursorOffset;
    Point cursorPosGoCue;
        
	LocalParams *params;
	real_T last_soft_reset;

	int tgt_angle;
	double ctr_hold;
    
    // center hold timer
    Timer *ch_timer;

    // whether to redo the trial (idiot mode)
    bool is_hiding_cursor;
    bool redo_trial;
	// any helper functions you need
	void doPreTrial(SimStruct *S);

};

RTOffsetBehavior::RTOffsetBehavior(SimStruct *S) : RobotBehavior() {

	// Create your *params object
	params = new LocalParams();

	// Set up the number of parameters you'll be using

	this->setNumParams(57);
	// Identify each bound variable 
	this->bindParamId(&params->master_reset,            0);
	this->bindParamId(&params->soft_reset,              1);
	
    this->bindParamId(&params->target_size,             2);
	this->bindParamId(&params->target_dist,             3);
    this->bindParamId(&params->target_angle,            4);
    this->bindParamId(&params->use_random_targets,      5);
    this->bindParamId(&params->show_tgt_during_bump,    6);
    
    this->bindParamId(&params->CH_time,                 7);
	this->bindParamId(&params->cue_delay_low,           8);
	this->bindParamId(&params->cue_delay_high,          9);
    this->bindParamId(&params->cue_hold_time,           10);
    this->bindParamId(&params->move_time,               11);
    
    this->bindParamId(&params->intertrial_time,         12);
	this->bindParamId(&params->penalty_time,            13);

    this->bindParamId(&params->hide_cursor_during_cue,  14);
    this->bindParamId(&params->recenter_cursor_after_cue,15);
    this->bindParamId(&params->lock_cursor_during_cue,16);
    
    this->bindParamId(&params->training_prob,           17);
    this->bindParamId(&params->abort_during_cue,        18);
    this->bindParamId(&params->force_reaction_time,     19);
    
	this->bindParamId(&params->stim_prob,               20);
    this->bindParamId(&params->audio_prob,              21);
    this->bindParamId(&params->pair_stim_audio,         22);
    
	this->bindParamId(&params->stim_levels,             23);
    this->bindParamId(&params->stim_code0_duration,     24);
    this->bindParamId(&params->stim_code1_duration,     25);
    this->bindParamId(&params->stim_code2_duration,     26);
    this->bindParamId(&params->stim_code3_duration,     27);
    this->bindParamId(&params->stim_code4_duration,     28);
    this->bindParamId(&params->stim_code5_duration,     29);
    this->bindParamId(&params->stim_code6_duration,     30);
    this->bindParamId(&params->stim_code7_duration,     31);
    this->bindParamId(&params->stim_code8_duration,     32);
    this->bindParamId(&params->stim_code9_duration,     33);
    this->bindParamId(&params->stim_code10_duration,    34);
    this->bindParamId(&params->stim_code11_duration,    35);
    this->bindParamId(&params->stim_code12_duration,    36);
    this->bindParamId(&params->stim_code13_duration,    37);
    this->bindParamId(&params->stim_code14_duration,    38);
    this->bindParamId(&params->stim_code15_duration,    39);
    
    this->bindParamId(&params->audio_levels,            40);
    this->bindParamId(&params->audio_code0_duration,    41);
    this->bindParamId(&params->audio_code1_duration,    42);
    this->bindParamId(&params->audio_code2_duration,    43);
    this->bindParamId(&params->audio_code3_duration,    44);
    this->bindParamId(&params->audio_code4_duration,    45);
    this->bindParamId(&params->audio_code5_duration,    46);
    this->bindParamId(&params->audio_code6_duration,    47);
    this->bindParamId(&params->audio_code7_duration,    48);
    this->bindParamId(&params->audio_code8_duration,    49);
    this->bindParamId(&params->audio_code9_duration,    50);
    this->bindParamId(&params->audio_code10_duration,   51);
    this->bindParamId(&params->audio_code11_duration,   52);
    this->bindParamId(&params->audio_code12_duration,   53);
    this->bindParamId(&params->audio_code13_duration,   54);
    this->bindParamId(&params->audio_code14_duration,   55);
    this->bindParamId(&params->audio_code15_duration,   56);
    
	// declare which already defined parameter is our master reset 
	// (if you're using one) otherwise omit the following line
	this->setMasterResetParamId(0);
	
	// This function now fetches all of the parameters into the variables
	// as defined above.
	//this->updateParameters(S);
	
	last_soft_reset = -1; // force a soft reset of first trial

	centerTarget = new CircleTarget();
	primaryTarget = new CircleTarget(); 

 	//centerTarget->color = Target::Color(128, 128, 128);
    centerTarget->color = Target::Color(160, 255, 0);
	primaryTarget->color = Target::Color(160, 255, 0);

	errorTarget = new SquareTarget(0, 0, 100, Target::Color(255, 255, 255));

	this->stim_trial = false;
    this->audio_trial = false;
    this->catch_trial = true;
    
    this->stim_level = 0;
    this->audio_level = 0;
    
    this->stim_grace_period = 0;
    
	this->tgt_angle = 0;
    this->cue_time = 0;
	this->cue_duration = 0;
	this->ctr_hold=0.0;

    this->ch_timer = new Timer();    
    this->is_hiding_cursor = false;
    this->redo_trial = false;
}


void RTOffsetBehavior::doPreTrial(SimStruct *S) {
   
    this->is_hiding_cursor = 0;
    if (!this->redo_trial) {
	    //set the target direction
	    if ((int)this->params->use_random_targets) {
	    	this->tgt_angle = this->random->getInteger(0,360);
	    } else {
	    	this->tgt_angle = (int)((this->params->target_angle)) ;
	    }

	    // Set up target locations, etc.
	    centerTarget->radius = params->target_size;
        if(centerTarget->radius < 0.1) {
            centerTarget->radius = 1;
        }
	    primaryTarget->radius = params->target_size;
	    primaryTarget->centerX = this->params->target_dist*cos((float)this->tgt_angle * PI/180);
	    primaryTarget->centerY = this->params->target_dist*sin((float)this->tgt_angle * PI/180);
        
        //select the actual center hold time
	    this->ctr_hold=this->params->CH_time;
	    
        // select the actual cue time
        this->cue_time = this->random->getDouble(this->params->cue_delay_low, this->params->cue_delay_high);
        
        // stop and reset center hold timer
	    this->ch_timer->stop(S);
	    
	    // Select which type of trial this is 
        // select stim and audio level as well
        if(this->params->pair_stim_audio){
            this->stim_trial=(this->random->getDouble() < this->params->stim_prob);
            this->audio_trial=(this->random->getDouble() < this->params->audio_prob);
            this->stim_level = this->random->getInteger(0,(int)this->params->stim_levels);
            this->audio_level = this->stim_level; // audio and stim should end at same time if they are paired.....
        } else {
            double rand_val = this->random->getDouble();
            this->stim_trial=(rand_val < this->params->stim_prob);
            this->audio_trial=(rand_val > this->params->stim_prob && rand_val < this->params->audio_prob+this->params->stim_prob);
            this->stim_level = this->random->getInteger(0,(int)this->params->stim_levels);
            this->audio_level = this->random->getInteger(0,(int)this->params->audio_levels);
        }
        this->catch_trial = false;
        if(!this->stim_trial && !this->audio_trial){
            this->catch_trial = true;
        }
        
        // get cue length based on level and cue type
        
        // setup stim_dur manually (oops)
        stim_dur_list[0] = this->params->stim_code0_duration;
        stim_dur_list[1] = this->params->stim_code1_duration;
        stim_dur_list[2] = this->params->stim_code2_duration;
        stim_dur_list[3] = this->params->stim_code3_duration;
        stim_dur_list[4] = this->params->stim_code4_duration;
        stim_dur_list[5] = this->params->stim_code5_duration;
        stim_dur_list[6] = this->params->stim_code6_duration;
        stim_dur_list[7] = this->params->stim_code7_duration;
        stim_dur_list[8] = this->params->stim_code8_duration;
        stim_dur_list[9] = this->params->stim_code9_duration;
        stim_dur_list[10] = this->params->stim_code10_duration;
        stim_dur_list[11] = this->params->stim_code11_duration;
        stim_dur_list[12] = this->params->stim_code12_duration;
        stim_dur_list[13] = this->params->stim_code13_duration;
        stim_dur_list[14] = this->params->stim_code14_duration;
        stim_dur_list[15] = this->params->stim_code15_duration;
        // setup audio_dur manually (oops)
        audio_dur_list[0] = this->params->audio_code0_duration;
        audio_dur_list[1] = this->params->audio_code1_duration;
        audio_dur_list[2] = this->params->audio_code2_duration;
        audio_dur_list[3] = this->params->audio_code3_duration;
        audio_dur_list[4] = this->params->audio_code4_duration;
        audio_dur_list[5] = this->params->audio_code5_duration;
        audio_dur_list[6] = this->params->audio_code6_duration;
        audio_dur_list[7] = this->params->audio_code7_duration;
        audio_dur_list[8] = this->params->audio_code8_duration;
        audio_dur_list[9] = this->params->audio_code9_duration;
        audio_dur_list[10] = this->params->audio_code10_duration;
        audio_dur_list[11] = this->params->audio_code11_duration;
        audio_dur_list[12] = this->params->audio_code12_duration;
        audio_dur_list[13] = this->params->audio_code13_duration;
        audio_dur_list[14] = this->params->audio_code14_duration;
        audio_dur_list[15] = this->params->audio_code15_duration;
        
        this->stim_grace_period = 0;
        if(this->stim_trial) {
            this->cue_duration = stim_dur_list[this->stim_level];
        } else if(this->audio_trial){
            this->cue_duration = audio_dur_list[this->audio_level];
        }
        this->cue_duration = this->cue_duration + 0.04; // ~40 ms delay between cue start here and actual start
        
    } //else everything else is the same

	this->redo_trial = false;
    this->is_hiding_cursor = false;
    
	/* setup the databurst */
	db->reset();
	db->addByte(DATABURST_VERSION);
	db->addByte('R');
	db->addByte('T');
	db->addByte('O');
	db->addByte(BEHAVIOR_VERSION_MAJOR);
    	db->addByte(BEHAVIOR_VERSION_MINOR);
	db->addByte((BEHAVIOR_VERSION_MICRO & 0xFF00) >> 8);
        db->addByte(BEHAVIOR_VERSION_MICRO & 0x00FF);

	db->addFloat((float)this->ctr_hold);
    db->addFloat((float)this->cue_time);
    db->addFloat((float)this->tgt_angle);
	db->addFloat((float)this->params->move_time);
    
    db->addFloat((float)this->params->target_size);
    db->addFloat((float)this->params->target_dist);
    db->addFloat((float)this->cue_duration);
    db->addByte((byte)this->stim_trial);
    db->addByte((byte)this->audio_trial);
    db->addByte((byte)this->catch_trial);
    db->addByte((byte)this->redo_trial);
	db->start();
}

void RTOffsetBehavior::update(SimStruct *S) {

	// State machine
	switch (this->getState()) {
		case STATE_PRETRIAL:
            this->is_hiding_cursor=0;
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
                playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if (this->ch_timer->elapsedTime(S) > this->ctr_hold) {
				setState(STATE_DELAY);
			}
			break;
		case STATE_DELAY:
			if(!centerTarget->cursorInTarget(inputs->cursor)){
                playTone(TONE_ABORT);
				setState(STATE_ABORT);
			} else if(stateTimer->elapsedTime(S) > this->cue_time){
                // start cue, then set state to STATE_CUE
                if(this->stim_trial) {
                    setState(STATE_STIM);
                } else if(this->audio_trial) {
                    setState(STATE_AUDIO);
                } else {
                    setState(STATE_CUE_ON);
                }
			}
			break;
        case STATE_CUE_ON:
            if(!centerTarget->cursorInTarget(inputs->cursor)){
                playTone(TONE_ABORT);
				setState(STATE_ABORT);
            }
            if(stateTimer->elapsedTime(S) > this->cue_duration) {
                setState(STATE_MOVEMENT);
            }
            break;
		case STATE_MOVEMENT:
			if(primaryTarget->cursorInTarget(inputs->cursor)){
                playTone(TONE_REWARD);
                setState(STATE_REWARD);
			} else if (stateTimer->elapsedTime(S) > this->params->move_time + this->stim_grace_period){
                playTone(TONE_FAIL);
    			setState(STATE_FAIL);
       		}
			break;         
		case STATE_STIM:
            setState(STATE_CUE_ON);
			break; 
        case STATE_AUDIO:
            setState(STATE_CUE_ON);
            break;
		case STATE_PENALTY:
            this->is_hiding_cursor=0;
			if (stateTimer->elapsedTime(S) > this->params->penalty_time) {
				setState(STATE_FAIL);
			}
			break;
		case STATE_ABORT:
        case STATE_REWARD:
		case STATE_FAIL:
        case STATE_INCOMPLETE:
            this->is_hiding_cursor=0;
			if (stateTimer->elapsedTime(S) > params->intertrial_time) {
				setState(STATE_PRETRIAL);
			}
			break;
		default:
			setState(STATE_PRETRIAL);
	}
}

void RTOffsetBehavior::calculateOutputs(SimStruct *S) {
    /* declarations */
    Point bf;
	double radius;
    double x_comp;
    double y_comp;

	/* force (0) */
    outputs->force = inputs->force;

	/* status (1) */
 	outputs->status[0] = getState();
	outputs->status[1] = trialCounter->successes;
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
            case STATE_CT_HOLD:
				outputs->word = WORD_CENTER_TARGET_HOLD;
				break;
			case STATE_DELAY:
				outputs->word = WORD_OT_ON(0);
				break;
			case STATE_STIM:
				outputs->word = WORD_STIM(this->stim_level);
				break;
            case STATE_AUDIO:
                outputs->word = WORD_RECEPTOR_STIM(this->audio_level);
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
	if (getState() == STATE_CT_ON || getState() == STATE_CT_HOLD) {
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = nullTarget;
		outputs->targets[2] = nullTarget;
	} else if(getState() == STATE_DELAY || getState() == STATE_STIM || getState() == STATE_AUDIO
            || getState() == STATE_CUE_ON || getState() == STATE_MOVEMENT) {
		outputs->targets[0] = (Target *)centerTarget;
		outputs->targets[1] = (Target *)(this->primaryTarget);
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


