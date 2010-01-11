/* $Id: mastercon_fc.c 380 2009-02-02 21:38:53Z brian $
 *
 * Master Control block for behavior: bump choice task
 */

#define S_FUNCTION_NAME mastercon_bc
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "simstruc.h"

#define TASK_BC 1
#include "words.h"
#include "random_macros.h"

#define PI (3.141592654)
#define ROUND2INT(val) ((int)((val) + 0.5))
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
 * Version 0 (0x00)
 * ----------------
 * byte 0: uchar => number of bytes to be transmitted (in this case 11)
 * byte 1: uchar => version number (in this case zero)
 * byte 2: uchar => training trial (1 if training, 0 if not)
 * bytes 3-6: float => target angle (rad)
 * bytes 7-10: float => bump magnitude (bump units?)
 *
 */

typedef unsigned char byte;
#define DATABURST_VERSION ((byte)0x00) 

/*
 * Until we implement tunable parameters, these will act as defaults
 */

/* Target parameters */
static real_T target_radius = 10.0; /* radius of target circle in cm */
#define param_target_radius mxGetScalar(ssGetSFcnParam(S,0))
static real_T target_size = 3.0;    /* width and height of targets in cm */
#define param_target_size mxGetScalar(ssGetSFcnParam(S,1))
static real_T window_size = 5.0;   /* diameter of blocking circle */
#define param_window_size mxGetScalar(ssGetSFcnParam(S,2))

/* Bump parameters */
#define param_bump_steps ((int)(mxGetScalar(ssGetSFcnParam(S,3))) <= 7 ? (int)(mxGetScalar(ssGetSFcnParam(S,3))) : 7)
static int bump_steps = 7;
#define param_bump_magnitude_min mxGetScalar(ssGetSFcnParam(S,4))
static real_T bump_magnitude_min = 0.0;
#define param_bump_magnitude_max mxGetScalar(ssGetSFcnParam(S,5))
static real_T bump_magnitude_max = 0.05;
#define param_bump_duration mxGetScalar(ssGetSFcnParam(S,6))
static real_T bump_duration = 125;

/* Timing parameters */
static real_T center_hold;
static real_T center_hold_l = 0.5; /* shortest delay between entry of ct and bump/stim */ 
#define param_center_hold_l mxGetScalar(ssGetSFcnParam(S,7))
static real_T center_hold_h = 1.0; /* longest delay between entry of ct and bump/stim */ 
#define param_center_hold_h mxGetScalar(ssGetSFcnParam(S,8))
static real_T movement_time = 10;  /* movement time */
#define param_movement_time mxGetScalar(ssGetSFcnParam(S,9))
#define param_intertrial mxGetScalar(ssGetSFcnParam(S,10)) /* time between trials*/
static real_T abort_timeout   = 1.0;    /* delay after abort */
static real_T failure_timeout = 1.0;    /* delay after failure */
static real_T incomplete_timeout = 1.0; /* delay after incomplete */
static real_T center_bump_timeout  = 1.0; 
static real_T reward_timeout  = 1.0;    /* delay after reward before starting next trial
                                         * This is NOT the reward pulse length */

/* General parameters */
static real_T pct_training_trials = 0.0; /* true=show one outer target, false=show 2 */
#define param_pct_training_trials mxGetScalar(ssGetSFcnParam(S,11))
static real_T master_reset = 0.0;
#define param_master_reset mxGetScalar(ssGetSFcnParam(S,12))

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_ORIGIN_ON 1
#define STATE_CENTER_HOLD 2
#define STATE_BUMP_STIM 3
#define STATE_MOVEMENT 4
#define STATE_REWARD 82
#define STATE_ABORT 65
#define STATE_FAIL 70
#define STATE_INCOMPLETE 74
#define STATE_DATA_BLOCK 255

#define TONE_GO 1
#define TONE_REWARD 2
#define TONE_ABORT 3
#define TONE_MASK 5

static void mdlCheckParameters(SimStruct *S)
{
    target_radius = param_target_radius;
    target_size = param_target_size;
    window_size = param_window_size;
    
    bump_steps = (int)param_bump_steps;
    bump_magnitude_min = param_bump_magnitude_min;
    bump_magnitude_max = param_bump_magnitude_max;
    bump_duration = param_bump_duration;
    
    pct_training_trials = param_pct_training_trials;
    
    center_hold_l = param_center_hold_l;
    center_hold_h = param_center_hold_h;
    movement_time = param_movement_time;

    abort_timeout   = param_intertrial;    
    failure_timeout = param_intertrial;
    reward_timeout  = param_intertrial;   
    incomplete_timeout = param_intertrial;
}

static void mdlInitializeSizes(SimStruct *S)
{
    int i;
    
    ssSetNumSFcnParams(S, 13);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* parameter number mismatch */
    }
    for (i=0; i<ssGetNumSFcnParams(S); i++)
        ssSetSFcnParamTunable(S, i, 1);
    mdlCheckParameters(S);
    
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 1);
    
    /*
     * Block has 2 input ports
     *      input port 0: (position) of width 2 (x, y)
     *      input port 1: (force) of width 2 (x, y)
     *      input port 2: (catch force) of width 2 (x,y) NOT USED
     */
    if (!ssSetNumInputPorts(S, 3)) return;
    ssSetInputPortWidth(S, 0, 2);
    ssSetInputPortWidth(S, 1, 2);
    ssSetInputPortWidth(S, 2, 2);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortDirectFeedThrough(S, 2, 1);
    
    /* 
     * Block has 8 output ports (force, status, word, targets, reward, tone, version, pos) of widths:
     *  force: 2
     *  status: 5 ( block counter, successes, aborts, failures, incompletes )
     *  word:  1 (8 bits)
     *  target: 15 ( target 1, 2, 3: 
     *                  on/off, 
     *                  target UL corner x, 
     *                  target UL corner y,
     *                  target LR corner x, 
     *                  target LR corner y)
     *  reward: 1
     *  tone: 2     ( 1: counter incemented for each new tone, 2: tone ID )
     *  version: 1 ( the cvs revision of the current .c file )
     *  pos: 2 (x and y position of the cursor)
     */
    if (!ssSetNumOutputPorts(S, 8)) return;
    ssSetOutputPortWidth(S, 0, 2);   /* force   */
    ssSetOutputPortWidth(S, 1, 5);   /* status  */
    ssSetOutputPortWidth(S, 2, 1);   /* word    */
    ssSetOutputPortWidth(S, 3, 15);  /* target  */
    ssSetOutputPortWidth(S, 4, 1);   /* reward  */
    ssSetOutputPortWidth(S, 5, 2);   /* tone    */
    ssSetOutputPortWidth(S, 6, 4);   /* version */
    ssSetOutputPortWidth(S, 7, 2);   /* pos     */
    
    ssSetNumSampleTimes(S, 1);
    
    /* work buffers */
    ssSetNumRWork(S, 6);  /* 0: time of last timer reset 
                             1: tone counter (incremented each time a tone is played)
                             2: tone id
							 3: mastercon version
                             4: target direction
                             5: bump magnitude                           
                           */
    ssSetNumPWork(S, 1);   /* 0: pointer to databurst array
                            */
    
    ssSetNumIWork(S, 9);     /* 0: state_transition (true if state changed), 
                                1: successes
                                2: failures
                                3: aborts
                                4: incompletes   
                                5: bump step 
                                6: training mode
                                7: databurst counter
                                8: bump duration counter
                             */
    
    /* we have no zero crossing detection or modes */
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}

#define MDL_INITIALIZE_CONDITIONS
static void mdlInitializeConditions(SimStruct *S)
{
    real_T *x0;
    int *databurst;
    
    /* initialize state to zero */
    x0 = ssGetRealDiscStates(S);
    *x0 = 0.0;
    
    /* notify that we just entered this state */
    ssSetIWorkValue(S, 0, 1);
       
    /* set the tone counter to zero */
    ssSetRWorkValue(S, 1, 0.0);
        
    /* set trial counters to zero */
    ssSetIWorkValue(S, 1, 0);
    ssSetIWorkValue(S, 2, 0);
    ssSetIWorkValue(S, 3, 0);
    ssSetIWorkValue(S, 4, 0);
    
    /* setup databurst */
    databurst = malloc(256);
    ssSetPWorkValue(S, 0, databurst);
    ssSetIWorkValue(S, 7, 0);
    
}

/* macro for setting state changed */
#define state_changed() (ssSetIWorkValue(S, 0, 1))
/* macro for resetting timer */
#define reset_timer() (ssSetRWorkValue(S, 0, (real_T)ssGetT(S)))

/* cursorInTarget
 * returns true (1) if the cursor is in the target and false (0) otherwise
 * cursor is specified as x,y = c[0], c[1]
 * target is specified by two corners: UL: x, y = t[0], t[1]
 *                                     LR: x, y = t[2], t[3]
 */
static int cursorInTarget(real_T *c, real_T *t)
{
    return ( (c[0] > t[0]) && (c[1] < t[1]) && (c[0] < t[2]) && (c[1] > t[3]) );
}

#define MDL_UPDATE
static void mdlUpdate(SimStruct *S, int_T tid) 
{
    /********************
     * Declarations     *
     ********************/
    
    /* stupidly declare all variables at the begining of the function */
    int *IWorkVector; 
    
    real_T ct[4];
    real_T rt[4];     /* reward target UL and LR coordinates */
    real_T ft[4];     /* fail target UL and LR coordinates */
    
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T elapsed_timer_time;
    int reset_block = 0;
    
    /* get trial parameters */
    real_T bump_magnitude;
    int bump_step;
    int training_mode;
    real_T target_direction;
        
    /* databurst variables */
    byte* databurst;
    float* db_angle;
    float* db_bump_mag;
    byte* db_training;
    int databurst_counter;
            
    /******************
     * Initialization *
     ******************/
        
    /* get current state */
    real_T *state_r = ssGetRealDiscStates(S);
    int state = (int)state_r[0];
    int new_state = state;
    
    /* current cursor location */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 0);
    cursor[0] = *uPtrs[0];
    cursor[1] = *uPtrs[1];

    /* get IWorkVector */
    IWorkVector = ssGetIWork(S);
    bump_step = ssGetIWorkValue(S,5);
    training_mode = ssGetIWorkValue(S,6);
    target_direction = ssGetRWorkValue(S,4);
    bump_magnitude = ssGetRWorkValue(S,5);
            
    /* get elapsed time since last timer reset */
    elapsed_timer_time = (real_T)(ssGetT(S)) - ssGetRWorkValue(S, 0);
        
    /* get target bounds */
    ct[0] = -target_size/2;
    ct[1] = target_size/2;
    ct[2] = target_size/2;
    ct[3] = -target_size/2;
       
    rt[0] = target_radius*cos(target_direction) - target_size/2; /* reward target */
    rt[1] = target_radius*sin(target_direction) + target_size/2;
    rt[2] = target_radius*cos(target_direction) + target_size/2;
    rt[3] = target_radius*sin(target_direction) - target_size/2;

    ft[0] = target_radius*cos(target_direction+PI) - target_size/2; /* fail target */
    ft[1] = target_radius*sin(target_direction+PI) + target_size/2;
    ft[2] = target_radius*cos(target_direction+PI) + target_size/2; 
    ft[3] = target_radius*sin(target_direction+PI) - target_size/2;   
    
    /* databurst pointers */
    databurst_counter = ssGetIWorkValue(S, 7);
    databurst = (byte *)ssGetPWorkValue(S, 0);
    db_training = (byte *)(databurst + 2*sizeof(byte));
    db_angle = (float *)(databurst + 3*sizeof(byte));
    db_bump_mag = (float *)(databurst + 3*sizeof(byte) + sizeof(float));
    
    /*********************************
     * See if we have issued a reset *  
     *********************************/
    if (param_master_reset != master_reset) {
        master_reset = param_master_reset;
        ssSetIWorkValue(S, 1, 0);
        ssSetIWorkValue(S, 2, 0);
        ssSetIWorkValue(S, 3, 0);
        ssSetIWorkValue(S, 4, 0);
        state_r[0] = STATE_PRETRIAL;
        return;
    }
    
    /************************
     * Calculate next state *
     ************************/
    
    /* execute one step of state machine */
    switch (state) {
        case STATE_PRETRIAL:
            /* pretrial initilization */
            /* 
             * We should only be in this state for one cycle.
             * Initilize the trial and then advance to CT_ON 
             */
            
            /* update parameters */

            target_radius = param_target_radius;
            target_size = param_target_size;
            window_size = param_window_size;

            bump_steps = param_bump_steps;
            bump_magnitude_min = param_bump_magnitude_min;
            bump_magnitude_max = param_bump_magnitude_max;
            bump_duration = param_bump_duration;

            pct_training_trials = param_pct_training_trials;

            center_hold_l = param_center_hold_l;
            center_hold_h = param_center_hold_h;
            movement_time = param_movement_time;

            abort_timeout   = param_intertrial;    
            failure_timeout = param_intertrial;
            reward_timeout  = param_intertrial;   
            incomplete_timeout = param_intertrial;
            
            /* decide it if it a training trial */
            training_mode = (UNI<pct_training_trials) ? 1 : 0;
            ssSetIWorkValue(S,6,training_mode);
            
            /* give a random direction to next target */ 
            target_direction = 2*PI*UNI;
            ssSetRWorkValue(S,4,target_direction);
                       
            /* get a random bump step */
            bump_step = ROUND2INT(UNI*bump_steps);
            ssSetIWorkValue(S,5,bump_step);
            
            bump_magnitude = bump_magnitude_min + ((float)bump_step)*(bump_magnitude_max-bump_magnitude_min)/((float)bump_steps);
            ssSetRWorkValue(S,5,bump_magnitude);
            
            /* In all cases, we need to decide on the random timer durations */
	        if (center_hold_h == center_hold_l) {
	            center_hold = center_hold_h;
	        } else {
	            center_hold = center_hold_l + (center_hold_h - center_hold_l)*UNI;
	        }
	                        
	        /* and advance */
	        new_state = STATE_ORIGIN_ON;
	        state_changed();
            break;
        case STATE_DATA_BLOCK:            
            if (databurst_counter++ >= databurst[0]*2) {
                new_state = STATE_ORIGIN_ON;
                reset_timer(); /* start timer for movement */
                state_changed();
            }                        
            databurst[0] = (byte)11;
            databurst[1] = DATABURST_VERSION;
            db_training[0] = (byte)training_mode;
            db_angle[0] = (float)target_direction;
            db_bump_mag[0] = (float)bump_magnitude;
            
            ssSetIWorkValue(S, 7, databurst_counter);
            break;
        case STATE_ORIGIN_ON:
            /* center target on */
            if (cursorInTarget(cursor, ct)) {
                new_state = STATE_CENTER_HOLD;
                reset_timer(); /* start center hold timer */
                state_changed();
            }
            break;
        case STATE_CENTER_HOLD:
            /* center hold */
            if (!cursorInTarget(cursor, ct)) {
                new_state = STATE_ABORT;
                reset_timer(); /* abort timeout */
                state_changed();
            } else if (elapsed_timer_time > center_hold) {
                new_state = STATE_BUMP_STIM;
                reset_timer(); /* delay timer */
                state_changed();
            } 
            break;
        case STATE_BUMP_STIM:
            /* stimulation */            
            if(cursorInTarget(cursor, rt)) {
                new_state = STATE_REWARD;
                reset_timer(); /* abort timeout */
                state_changed();
            } else if (cursorInTarget(cursor, ft)) {
                new_state = STATE_FAIL;
                reset_timer(); /* abort timeout */
                state_changed();
            } else if (elapsed_timer_time > bump_duration) {
                new_state = STATE_MOVEMENT;
                reset_timer(); /* movement timer */
                state_changed();
            }
            break;
        case STATE_MOVEMENT:
            /* movement phase (go tone on entry) */
			if (cursorInTarget(cursor, rt)) {
				new_state = STATE_REWARD;
                reset_timer(); /* reward timeout */
                state_changed();
			
			} else if (cursorInTarget(cursor, ft)) {			
                new_state = STATE_FAIL;
                reset_timer(); /* incomplete timeout */
                state_changed();
				
			} else if (elapsed_timer_time > movement_time) {
				new_state = STATE_INCOMPLETE;
                reset_timer(); /* incomplete timeout */
                state_changed();

			}
			break;
        case STATE_ABORT:
            /* abort */
            if (elapsed_timer_time > abort_timeout) {
                new_state = STATE_PRETRIAL;
                state_changed();
			}
            break;
        case STATE_FAIL:
            /* failure */
            if (elapsed_timer_time > failure_timeout) {
                new_state = STATE_PRETRIAL;
                state_changed();
            }
            break;
        case STATE_INCOMPLETE:
            /* incomplete */
            if (elapsed_timer_time > incomplete_timeout) {
                new_state = STATE_PRETRIAL;
                state_changed();
            }
            break;
        case STATE_REWARD:
            /* reward */
            if (elapsed_timer_time > reward_timeout) {
                new_state = STATE_PRETRIAL;
                state_changed();
            }
            break;
        default:
            new_state = STATE_PRETRIAL;
    }
    
    /***********
     * Cleanup *
     ***********/
    
    /* write back new state */
    state_r[0] = new_state;
    
    /* Burn random number from stack */
    KISS;

    UNUSED_ARG(tid);
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
    /********************
     *  Initialization
     ********************/
    int i;
    
    int_T *IWorkVector; 
    
    real_T ct[4];
    real_T rt[4];     /* left outer target UL and LR coordinates */
    real_T ft[4];     /* right outer target UL and LR coordinates */
    real_T ct_type;   /* type of center target 0=invisible 1=red square 2=lightning bolt (?) */
    real_T rt_type;   /* type of left outer target 0=invisible 1=red square 2=lightning bolt (?) */
    real_T ft_type;   /* type of right outer target 0=invisible 1=red square 2=lightning bolt (?) */
    real_T target_direction;
    
    /* get trial type */
    int training_mode;
    int bump_duration_counter;
    real_T bump_magnitude;
    int bump_step;
    
    int databurst_counter;
    byte* databurst;
    
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T force_in[2];
    
    /* allocate holders for outputs */
    real_T force_x, force_y, word, reward, tone_cnt, tone_id, pos_x, pos_y;
    real_T target_pos[15];
    real_T status[5];
    real_T version[4];
    
    /* pointers to output buffers */
    real_T *force_p;
    real_T *word_p;
    real_T *target_p;
    real_T *status_p;
    real_T *reward_p;
    real_T *tone_p;
    real_T *version_p;
    real_T *pos_p;
    
    /* get current state */
    real_T *state_r = ssGetRealDiscStates(S);
    int state = (int)(state_r[0]);
    int new_state = ssGetIWorkValue(S, 0);
    ssSetIWorkValue(S, 0, 0); /* reset changed state each iteration */

    /* current trial type */
    target_direction = ssGetRWorkValue(S,4);
    training_mode = ssGetIWorkValue(S,6);
            
    /* bump parameters */
    bump_magnitude = ssGetRWorkValue(S,5);
    bump_duration_counter = ssGetIWorkValue(S, 8);
    bump_step = ssGetIWorkValue(S, 5);
   
    /* get current tone counter */
    tone_cnt = ssGetRWorkValue(S, 1);
    tone_id = ssGetRWorkValue(S, 2);
    
    /* get target bounds */
    ct[0] = -target_size/2;
    ct[1] = target_size/2;
    ct[2] = target_size/2;
    ct[3] = -target_size/2;

    rt[0] = target_radius*cos(target_direction) - target_size/2; /* reward target */
    rt[1] = target_radius*sin(target_direction) + target_size/2;
    rt[2] = target_radius*cos(target_direction) + target_size/2;
    rt[3] = target_radius*sin(target_direction) - target_size/2;

    ft[0] = target_radius*cos(target_direction+PI) - target_size/2; /* fail target */
    ft[1] = target_radius*sin(target_direction+PI) + target_size/2;
    ft[2] = target_radius*cos(target_direction+PI) + target_size/2; 
    ft[3] = target_radius*sin(target_direction+PI) - target_size/2;   
        
    /* current cursor location */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 0);
    cursor[0] = *uPtrs[0];
    cursor[1] = *uPtrs[1];
    
    /* input force */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 1);
    force_in[0] = *uPtrs[0];
    force_in[1] = *uPtrs[1];
    
    /* databurst */
    databurst_counter = ssGetIWorkValue(S, 7);
    databurst = (byte *)ssGetPWorkValue(S, 0);
    
    /********************
     * Calculate outputs
     ********************/
    
    /* force (0) */
    
    if (bump_duration_counter > 0) {
        /* yes, so decrement the counter and maintain the bump */
        bump_duration_counter--;
        force_x = force_in[0] + cos(target_direction)*bump_magnitude;
        force_y = force_in[1] + sin(target_direction)*bump_magnitude;
    } else if ( state == STATE_BUMP_STIM && new_state ) 
    {
        /* initiating a new bump */
        bump_duration_counter = (int)bump_duration;
        force_x = force_in[0] + cos(target_direction)*bump_magnitude;
        force_y = force_in[1] + sin(target_direction)*bump_magnitude;
    } else {
        force_x = force_in[0]; 
        force_y = force_in[1];
    }
    
    /* status (1) */
    if (state == STATE_REWARD && new_state)
        ssSetIWorkValue(S,1, ssGetIWorkValue(S, 1)+1);
    if (state == STATE_FAIL && new_state)
        ssSetIWorkValue(S, 2, ssGetIWorkValue(S, 2)+1);
    if (state == STATE_ABORT && new_state)
        ssSetIWorkValue(S, 3, ssGetIWorkValue(S, 3)+1);
    if (state == STATE_INCOMPLETE && new_state)
        ssSetIWorkValue(S, 4, ssGetIWorkValue(S, 4)+1);
    
    status[0] = state;
    status[1] = ssGetIWorkValue(S, 1); /* num rewards     */
    status[2] = ssGetIWorkValue(S, 2); /* num fails       */
    status[3] = ssGetIWorkValue(S, 3); /* num aborts      */
    status[4] = ssGetIWorkValue(S, 4); /* num incompletes */
    
    /* word (2) */
    if (new_state) {
        switch (state) {
            case STATE_PRETRIAL:
                word = WORD_START_TRIAL;
                break;
            case STATE_ORIGIN_ON:
                word = WORD_CT_ON;
                break;
            case STATE_BUMP_STIM:
                word = WORD_BUMP(bump_step);
                break;
            case STATE_MOVEMENT:
                word = WORD_GO_CUE;
                break;
            case STATE_REWARD:
                word = WORD_REWARD;
                break;
            case STATE_ABORT:
                word = WORD_ABORT;
                break;
            case STATE_FAIL:
                word = WORD_FAIL;
                break;
            case STATE_INCOMPLETE:
                word = WORD_INCOMPLETE;
                break;
            default:
                word = 0;
        }
    } else {
        word = 0;
    }
    
    /* target_pos (3) */    
    /* start assuming no targets will be drawn */
    for (i = 0; i<15; i++)
        target_pos[i] = 0;
    
    if ( state == STATE_ORIGIN_ON || 
         state == STATE_CENTER_HOLD)
    {
        /* center target on */
        target_pos[0] = 2;
        for (i=0; i<4; i++) {
           target_pos[i+1] = ct[i];
        }
    } else if (state == STATE_MOVEMENT  ||
         state == STATE_BUMP_STIM) {
        /* center target on */
        target_pos[0] = 2;
        for (i=0; i<4; i++) {
           target_pos[i+1] = ct[i];
        }
        /* outer target on */
        target_pos[5] = 2;
        for (i=0; i<4; i++) {
            target_pos[i+6] = rt[i];
        }
        if (!training_mode) {
            target_pos[10] = 2;
            for (i=0; i<4; i++) {
                target_pos[i+11] = ft[i];
            }
        }
    }
        
    /* reward (4) */
    if (new_state && state==STATE_REWARD) {
        reward = 1;
    } else {
        reward = 0;
    }
    
    /* tone (5) */
    if (new_state) {
        if (state == STATE_ABORT || state == STATE_FAIL) {
            tone_cnt++;
            tone_id = TONE_ABORT;
        } else if (state == STATE_BUMP_STIM) {
            tone_cnt++;
            tone_id = TONE_GO; 
        } else if (state == STATE_REWARD) {
            tone_cnt++;
            tone_id = TONE_REWARD;
        }
    }

    /* version (6) */
    version[0] = BEHAVIOR_VERSION_MAJOR;
    version[1] = BEHAVIOR_VERSION_MINOR;
    version[2] = BEHAVIOR_VERSION_MICRO;
    version[3] = BEHAVIOR_VERSION_BUILD;

    /* pos (7) */
    if ( (state == STATE_BUMP_STIM || state == STATE_MOVEMENT) && sqrt(cursor[0]*cursor[0]+cursor[1]*cursor[1]) < window_size) {
        /* we are inside blocking window => draw cursor off screen */
        pos_x = 1E6;
        pos_y = 1E6;
    } else {
        /* we are outside the blocking window */
        pos_x = cursor[0];
        pos_y = cursor[1];
    }
    
    /**********************************
     * Write outputs back to SimStruct
     **********************************/
    force_p = ssGetOutputPortRealSignal(S,0);
    force_p[0] = force_x;
    force_p[1] = force_y;
    ssSetIWorkValue(S, 8, bump_duration_counter);
    
    status_p = ssGetOutputPortRealSignal(S,1);
    for (i=0; i<5; i++) 
        status_p[i] = status[i];
    
    word_p = ssGetOutputPortRealSignal(S,2);
    word_p[0] = word;
    
    target_p = ssGetOutputPortRealSignal(S,3);
    for (i=0; i<15; i++) {
        target_p[i] = target_pos[i];
    }
    
    reward_p = ssGetOutputPortRealSignal(S,4);
    reward_p[0] = reward;
    
    tone_p = ssGetOutputPortRealSignal(S,5);
    tone_p[0] = tone_cnt;
    tone_p[1] = tone_id;
    ssSetRWorkValue(S, 1, tone_cnt);
    ssSetRWorkValue(S, 2, tone_id);
    
    version_p = ssGetOutputPortRealSignal(S,6);
    for (i=0; i<4; i++) {
        version_p[i] = version[i];
    }
    
    pos_p = ssGetOutputPortRealSignal(S,7);
    pos_p[0] = pos_x;
    pos_p[1] = pos_y;

    UNUSED_ARG(tid);
}

static void mdlTerminate (SimStruct *S) { UNUSED_ARG(S); }

#ifdef MATLAB_MEX_FILE   /* Is this being compiled as a MEX-file? */
#include "simulink.c"    /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"     /* Code generation registration func */
#endif
