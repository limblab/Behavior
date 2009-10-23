/* $Id$
 * 
 * Master Control block for behavior: bump-stim task
 */

#define S_FUNCTION_NAME mastercon_bs
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "simstruc.h"

#define TASK_BS 1
#include "words.h"
#include "random_macros.h"

#define PI (3.141592654)

/*
 * Until we implement tunable parameters, these will act as defaults
 */
static real_T req_target_angle = 0; /* requested angle at which targets appear */
#define param_req_target_angle mxGetScalar(ssGetSFcnParam(S,0))
static real_T target_radius = 15.0; /* radius of target circle in cm */
#define param_target_radius mxGetScalar(ssGetSFcnParam(S,1))
static real_T target_size = 5.0;    /* width and height of targets in cm */
#define param_target_size mxGetScalar(ssGetSFcnParam(S,2))
static real_T window_size = 10.0;   /* diameter of blocking circle */
#define param_window_size mxGetScalar(ssGetSFcnParam(S,3))

/*
 * Trial type nomenclature:
 *
 * All trials consist of two targets, "target 1" (T1) and "target 2" (T2)
 * T1 is always positioned on the target_radius circle at an angle of target_angle from the x axis (monkey right)
 * T2 is always positioned on the target_radius circle at an angle of target_angle + 180 degrees
 *
 * Trials are divided into "forward" (Movement is from T1 to T2) and "reverse" (T2 to T1) trials
 * 
 * Within a trial targets may be referred to as "origin" or "destination".  Thus, in a forward trial T1 is the origin
 * and T2 is the destination.  In a reverse trial T2 is the origin and T1 is the destination.
 */

static real_T origin_hold;     /* dwell time in state 2 */
static real_T origin_hold_l = .5;     
#define param_origin_hold_l mxGetScalar(ssGetSFcnParam(S,4))
static real_T origin_hold_h = 2.0;     
#define param_origin_hold_h mxGetScalar(ssGetSFcnParam(S,5))

static real_T origin_delay;     /* delay between destination target and go tone */
static real_T origin_delay_l = 0.0;
#define param_origin_delay_l mxGetScalar(ssGetSFcnParam(S,6))
static real_T origin_delay_h = 0.0;
#define param_origin_delay_h mxGetScalar(ssGetSFcnParam(S,7))

static real_T movement_time = 10.0;  /* movement time */
#define param_movement_time mxGetScalar(ssGetSFcnParam(S,8))

static real_T destination_hold;      /* destination target hold time */
static real_T destination_hold_l = 1.0;      
#define param_destination_hold_l mxGetScalar(ssGetSFcnParam(S,9))
static real_T destination_hold_h = 1.0; 
#define param_destination_hold_h mxGetScalar(ssGetSFcnParam(S,10))

#define param_intertrial mxGetScalar(ssGetSFcnParam(S,11))
static real_T abort_timeout   = 1.0;    /* delay after abort */
static real_T failure_timeout = 1.0;    /* delay after failure */
static real_T incomplete_timeout = 1.0; /* delay after incomplete */
static real_T center_bump_timeout  = 1.0; 
static real_T reward_timeout  = 1.0;    /* delay after reward before starting next trial
                                         * This is NOT the reward pulse length */

#define param_stim_trial_pct mxGetScalar(ssGetSFcnParam(S,12))
static real_T stim_trial_pct = 0.0; /* percent of trial in which we stimulate rather than bump */

#define set_stim_trial(x) ssSetRWorkValue(S, 3, (x))
#define get_stim_trial() ssGetRWorkValue(S, 3)

#define param_bump_magnitude mxGetScalar(ssGetSFcnParam(S,13))
static real_T bump_magnitude;

#define param_bump_duration mxGetScalar(ssGetSFcnParam(S,14))
static real_T bump_duration;

#define param_bump_steps ((int)(mxGetScalar(ssGetSFcnParam(S,15))))
static int bump_steps;

#define param_num_targets_per_angle ((int)(mxGetScalar(ssGetSFcnParam(S,16))))
static int num_targets_per_angle;

static real_T master_reset = 0.0;
#define param_master_reset mxGetScalar(ssGetSFcnParam(S,17))

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_ORIGIN_ON 1
#define STATE_ORIGIN_HOLD 2
#define STATE_ORIGIN_DELAY 3
#define STATE_MOVEMENT 4
#define STATE_DEST_HOLD 5
#define STATE_REWARD 82
#define STATE_ABORT 65
#define STATE_FAIL 70
#define STATE_INCOMPLETE 74

#define TONE_GO 1
#define TONE_REWARD 2
#define TONE_ABORT 3
#define TONE_MASK 5

#define DIRECTION_FORWARD 0
#define DIRECTION_REVERSE 1

static void mdlCheckParameters(SimStruct *S)
{
    bump_steps = (int)param_bump_steps;
    bump_magnitude = param_bump_magnitude;
    bump_duration = param_bump_duration;
    stim_trial_pct = param_stim_trial_pct;

    req_target_angle = param_req_target_angle;
    num_targets_per_angle = param_num_targets_per_angle;
    target_radius = param_target_radius;
    target_size = param_target_size;
    window_size = param_window_size;
    
    origin_hold_l = param_origin_hold_l;
    origin_hold_h = param_origin_hold_h;

    origin_delay_l = param_origin_delay_l;
    origin_delay_h = param_origin_delay_h;

    movement_time = param_movement_time;

    destination_hold_l = param_destination_hold_l;
    destination_hold_h = param_destination_hold_h;

    abort_timeout   = param_intertrial;    
    failure_timeout = param_intertrial;
    reward_timeout  = param_intertrial;   
    incomplete_timeout = param_intertrial;
}

static void mdlInitializeSizes(SimStruct *S)
{
    int i;
    
    ssSetNumSFcnParams(S, 18); 
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* parameter number mismatch */
    }
    for (i=0; i<ssGetNumSFcnParams(S); i++)
        ssSetSFcnParamTunable(S,i, 1);
    mdlCheckParameters(S);
    
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 2); /* First state is the state machine state (as in all other behavior controls.
							   * Second state is 0: forward trial. 1: reverse trial. */
    
    /*
     * Block has 2 input ports
     *      input port 0: (position) of width 2 (x, y)
     *      input port 1: (force) of width 2 (x, y)
     *      input port 2: (catch force) of width 2 (x, y) NOT USED
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
     *  target: 10 ( target 1, 2: 
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
    ssSetOutputPortWidth(S, 3, 10);  /* target  */
    ssSetOutputPortWidth(S, 4, 1);   /* reward  */
    ssSetOutputPortWidth(S, 5, 2);   /* tone    */
    ssSetOutputPortWidth(S, 6, 4);   /* version */
    ssSetOutputPortWidth(S, 7, 2);   /* pos     */
    
    ssSetNumSampleTimes(S, 1);
    
    /* work buffers */
    ssSetNumRWork(S, 4);  /* 0: time of last timer reset 
                             1: tone counter (incremented each time a tone is played)
                             2: tone id
                             3: target angle
                           */
    ssSetNumPWork(S, 0);
    ssSetNumIWork(S, 74);  /*    0: state_transition (true if state changed), 
                                 1: current trial index,
		                         2: stim trial (1 for yes, 0 for no)
                            [3-66]: trial presentation sequence
                                67: bump duration counter 
                                68: successes
                                69: failures
                                70: aborts 
                                71: incompletes 
                                72: counter for targets at a given angle 
                                73: stimulation flag 0=not stimulating -1=stim started 1=stimulate */
    
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
    int i;
    real_T *x0;
    
    /* initialize state to zero */
    x0 = ssGetRealDiscStates(S);
    x0[0] = 0.0; /* state-machine state */
    x0[1] = 0.0; /* begin with forward trial */
    
    /* notify that we just entered this state */
    ssSetIWorkValue(S, 0, 1);
    
    /* set target index to indicate that we need to begin a new block */
    ssSetIWorkValue(S, 1, (int)( 2*(bump_steps*2+1)-1));
    
    /* initilize the value of target angle to the parameter */
    ssSetRWorkValue(S, 3, param_req_target_angle);
    
    /* set the tone counter to zero */
    ssSetRWorkValue(S, 1, 0.0);
        
    /* set trial counters to zero */
    for (i = 68; i<=72; i++)
      ssSetIWorkValue(S, i, 0);
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
    int trial_index;
    int *trial_list;
    int num_trials;
    int bump;
    real_T target_angle;
    real_T target1[4];
    real_T target2[4];
    real_T *target_origin;
    real_T *target_destination;
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T elapsed_timer_time;
    int reset_block = 0;
        
    /* block initialization working variables */
    int tmp_trial_1[15];
    int tmp_trial_2[15];
    int tmp_sort[15];
    int i, j, tmp;
    
    /******************
     * Initialization *
     ******************/
    
    /* get current state */
    real_T *state_r = ssGetRealDiscStates(S);
    int state = (int)state_r[0];
    int direction = (int)state_r[1];
    int new_state = state;
    
    /* current cursor location */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 0);
    cursor[0] = *uPtrs[0];
    cursor[1] = *uPtrs[1];
    
    /* get elapsed time since last timer reset */
    elapsed_timer_time = (real_T)(ssGetT(S)) - ssGetRWorkValue(S, 0);
    
    /* get target bounds */
    if (num_targets_per_angle == 0) {
      target_angle = req_target_angle;
    } else {
      target_angle = ssGetRWorkValue(S, 3);
    }
    
    target1[0] = cos(target_angle)*target_radius-target_size/2;
    target1[1] = sin(target_angle)*target_radius+target_size/2;
    target1[2] = cos(target_angle)*target_radius+target_size/2;
    target1[3] = sin(target_angle)*target_radius-target_size/2;
    
    target2[0] = cos(target_angle+PI)*target_radius-target_size/2;
    target2[1] = sin(target_angle+PI)*target_radius+target_size/2;
    target2[2] = cos(target_angle+PI)*target_radius+target_size/2;
    target2[3] = sin(target_angle+PI)*target_radius-target_size/2;

    if (direction == 0) {
      /* forward trial */
      target_origin = target1;
      target_destination = target2;
    } else {
      /* reverse trial */
      target_origin = target2;
      target_destination = target1;
    }
    
    /* get bump */
    IWorkVector = ssGetIWork(S);
    trial_index = IWorkVector[1];
    trial_list = IWorkVector+2;
    bump = trial_list[trial_index];

    /*********************************
     * See if we have issued a reset *
     *********************************/
    if (param_master_reset != master_reset) {
      master_reset = param_master_reset;
      for (i = 68; i<=72; i++)
        ssSetIWorkValue(S, i, 0);
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
            if (bump_steps != param_bump_steps) {
                bump_steps = (int)param_bump_steps;
                bump_steps = ( bump_steps<=7 ? bump_steps : 7 ); /* limit bump_steps to 7 */
                reset_block = 1;
            }
            
            stim_trial_pct = param_stim_trial_pct;
            
            bump_magnitude = param_bump_magnitude;
            bump_duration = (int)param_bump_duration;

            req_target_angle = param_req_target_angle;
            num_targets_per_angle = param_num_targets_per_angle;
            target_radius = param_target_radius;
            target_size = param_target_size;
            window_size = param_window_size;

            origin_hold_l = param_origin_hold_l;
            origin_hold_h = param_origin_hold_h;

            origin_delay_l = param_origin_delay_l;
            origin_delay_h = param_origin_delay_h;

            movement_time = param_movement_time;

            destination_hold_l = param_destination_hold_l;
            destination_hold_h = param_destination_hold_h;

            abort_timeout   = param_intertrial;    
            failure_timeout = param_intertrial;
            reward_timeout  = param_intertrial;   
            incomplete_timeout = param_intertrial;
             
            num_trials = 2 * (2 * bump_steps + 1);
            ssSetIWorkValue(S, 73, 0);
            if (rand()<=stim_trial_pct) {
                ssSetIWorkValue(S, 2, 1);
                ssSetIWorkValue(S, 73, 1);
                /* if we do not have our trials initialized => new block */
            } else if (trial_index >= num_trials-1 || reset_block) {
                /* initialize the trials */
                ssSetIWorkValue(S, 2, 0);  /* not a stim trial */
                for (i=0; i<num_trials/2; i++) {
                    tmp_trial_1[i] = i - bump_steps;
                    tmp_sort[i] = rand();
                }
                for (i=0; i<num_trials/2; i++) {
                    for (j=0; j<num_trials/2; j++) {
                        if (tmp_sort[j] < tmp_sort[j+1]) {
                            tmp = tmp_sort[j];
                            tmp_sort[j] = tmp_sort[j+1];
                            tmp_sort[j+1] = tmp;
                            
                            tmp = tmp_trial_1[j];
                            tmp_trial_1[j] = tmp_trial_1[j+1];
                            tmp_trial_1[j+1] = tmp;
                        }
                    }
                }
                for (i=0; i<num_trials/2; i++) {
                    tmp_trial_2[i] = i - bump_steps;
                    tmp_sort[i] = rand();
                }
                for (i=0; i<num_trials/2; i++) {
                    for (j=0; j<num_trials/2; j++) {
                        if (tmp_sort[j] < tmp_sort[j+1]) {
                            tmp = tmp_sort[j];
                            tmp_sort[j] = tmp_sort[j+1];
                            tmp_sort[j+1] = tmp;
                            
                            tmp = tmp_trial_2[j];
                            tmp_trial_2[j] = tmp_trial_2[j+1];
                            tmp_trial_2[j+1] = tmp;
                        }
                    }
                }
                /* write them back */
                for (i=0; i<num_trials/2; i++) {
                    trial_list[2*i] = tmp_trial_1[i];
                    trial_list[2*i+1] = tmp_trial_2[i];
                }
                /* and reset the counter */
                ssSetIWorkValue(S, 1, 0);
            } else {
                /* and write it back */
                ssSetIWorkValue(S, 1, trial_index);
                bump = trial_list[trial_index];
                ssSetIWorkValue(S, 2, 0); /* not a stim trial */
            }
            
            /* choose the target angle based on the requested angle and counter */
            if (num_targets_per_angle == 0) {
              /* use requested angle */
              ssSetRWorkValue(S, 3, req_target_angle);
              ssSetIWorkValue(S, 72, 0);
            } else {
              /* increment counter */
              ssSetIWorkValue(S, 72, ssGetIWorkValue(S, 72) + 1);
              
              /* see if we have run enough trials at this angle */
              if (ssGetIWorkValue(S, 72) >= num_targets_per_angle) {
                ssSetIWorkValue(S, 72, 0); /* reset counter */
                ssSetRWorkValue(S, 3, UNI * 2.0 * PI); /* pick a new random value */
              }
            }
            
            /* In all cases, we need to decide on the random timer durations */
            if (origin_hold_h == origin_hold_l) {
                origin_hold = origin_hold_h;
            } else {
                origin_hold = origin_hold_l + (origin_hold_h - origin_hold_l)*((double)rand())/((double)RAND_MAX);
            }
            if (origin_delay_h == origin_delay_l) {
                origin_delay = origin_delay_h;
            } else {
                origin_delay = origin_delay_l + (origin_delay_h - origin_delay_l)*((double)rand())/((double)RAND_MAX);
            }
            if (destination_hold_h == destination_hold_l) {
                destination_hold = destination_hold_h;
            } else {
                destination_hold = destination_hold_l + (destination_hold_h - destination_hold_l)*((double)rand())/((double)RAND_MAX);
            }
       
            /* clear the bump counter */
            ssSetIWorkValue(S, 67, -1); 
                            
            /* and advance */
            new_state = STATE_ORIGIN_ON;
            state_changed();
            break;
        case STATE_ORIGIN_ON:
            /* center target on */
            if (cursorInTarget(cursor, target_origin)) {
                new_state = STATE_ORIGIN_HOLD;
                reset_timer(); /* start center hold timer */
                state_changed();
            }
            break;
        case STATE_ORIGIN_HOLD:
            /* center hold */
            if (!cursorInTarget(cursor, target_origin)) {
                new_state = STATE_ABORT;
                reset_timer(); /* abort timeout */
                state_changed();
            } else if (elapsed_timer_time > origin_hold) {
                new_state = STATE_ORIGIN_DELAY;
                reset_timer(); /* delay timer */
                state_changed();
            }
            break;
        case STATE_ORIGIN_DELAY:
            /* center delay (destination target on) */
            if (!cursorInTarget(cursor, target_origin)) {
                new_state = STATE_ABORT;
                reset_timer(); /* abort timeout */
                state_changed();
            } else if (elapsed_timer_time > origin_delay) {
                new_state = STATE_MOVEMENT;
                reset_timer(); /* movement timer */
                state_changed();
            }
            break;
        case STATE_MOVEMENT:
            /* movement phase (go tone on entry) */
            if (cursorInTarget(cursor, target_destination)) {
                new_state = STATE_DEST_HOLD;
                reset_timer(); /* destination hold timer */
                state_changed();
            } else if (elapsed_timer_time > movement_time) {
                new_state = STATE_FAIL;
                reset_timer(); /* failure timeout */
                state_changed();
            }
            break;
        case STATE_DEST_HOLD:
            /* destination target hold phase */
            if (!cursorInTarget(cursor, target_destination)) {
                new_state = STATE_INCOMPLETE;
                reset_timer(); /* failure timeout */
                state_changed();
            } else if (elapsed_timer_time > destination_hold) {
                new_state = STATE_REWARD;
                if (!ssGetIWorkValue(S, 2)) 
                    ssSetIWorkValue(S,1, ssGetIWorkValue(S,1)+1);
                reset_timer(); /* reward (inter-trial) timeout */
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
                state_r[1] = !state_r[1];
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
    
    UNUSED_ARG(tid);
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
    /********************
     *  Initialization
     ********************/
    int i;
    int_T *IWorkVector; 
    int_T trial_index;
    int_T *trial_list;
    int bump; /* magnitude of bump */
    int bump_duration_counter;
    int stim;
    real_T target_angle;
    real_T target1[4];
    real_T target2[4];
    real_T *target_origin;
    real_T *target_destination;
    real_T theta;
    
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T force_in[2];
    
    /* allocate holders for outputs */
    real_T force_x, force_y, word, reward, tone_cnt, tone_id, pos_x, pos_y;
    real_T target_pos[10];
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
    
	int bump_started = 0;

    /* get current state */
    real_T *state_r = ssGetRealDiscStates(S);
    int state = (int)(state_r[0]);
    int direction = (int)(state_r[1]);
    int new_state = ssGetIWorkValue(S, 0);
    ssSetIWorkValue(S, 0, 0); /* reset changed state each iteration */

    /* current target number */
    IWorkVector = ssGetIWork(S);
    trial_index = IWorkVector[1];
    trial_list = IWorkVector+2;
    
    if (ssGetIWorkValue(S,2) == 1){
        bump = 0;
    } else {
        bump = trial_list[trial_index];
    }
    
    stim = ssGetIWorkValue(S, 73);
    bump_duration_counter = ssGetIWorkValue(S, 67);
    
    /* get current tone counter */
    tone_cnt = ssGetRWorkValue(S, 1);
    tone_id = ssGetRWorkValue(S, 2);
    
    /* get target bounds */
    if (num_targets_per_angle == 0) {
      target_angle = req_target_angle;
    } else {
      target_angle = ssGetRWorkValue(S, 3);
    }
    
    target1[0] = cos(target_angle)*target_radius-target_size/2;
    target1[1] = sin(target_angle)*target_radius+target_size/2;
    target1[2] = cos(target_angle)*target_radius+target_size/2;
    target1[3] = sin(target_angle)*target_radius-target_size/2;
    
    target2[0] = cos(target_angle+PI)*target_radius-target_size/2;
    target2[1] = sin(target_angle+PI)*target_radius+target_size/2;
    target2[2] = cos(target_angle+PI)*target_radius+target_size/2;
    target2[3] = sin(target_angle+PI)*target_radius-target_size/2;

    if (direction == 0) {
        /* forward trial */
        target_origin = target1;
        target_destination = target2;
    } else {
        /* reverse trial */
        target_origin = target2;
        target_destination = target1;
    }
    
    /* current cursor location */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 0);
    cursor[0] = *uPtrs[0];
    cursor[1] = *uPtrs[1];
    
    /* input force */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 1);
    force_in[0] = *uPtrs[0];
    force_in[1] = *uPtrs[1];
    
    /********************
     * Calculate outputs
     ********************/
    
    /* force (0) */
    /* see if we are in a bump */

    if (bump_duration_counter > 0) {
        /* yes, so decrement the counter and maintain the bump */
        bump_duration_counter--;
        theta = PI/2 + target_angle;
        force_x = force_in[0] + cos(theta)*bump*bump_magnitude;
        force_y = force_in[1] + sin(theta)*bump*bump_magnitude;
    } else if ( bump_duration_counter == -1 && bump && stim == 0 &&
                state==STATE_MOVEMENT && 
                ( ( direction == 0 && cos( -target_angle )*cursor[0] - sin( -target_angle )*cursor[1] <= 0) ||
                  ( direction == 1 && cos( -target_angle )*cursor[0] - sin( -target_angle )*cursor[1] >= 0) )
              ) 
    {
        /* initiating a new bump */
        bump_started = 1;
        bump_duration_counter = (int)bump_duration;
        theta = PI/2 + target_angle;
        force_x = force_in[0] + cos(theta)*bump*bump_magnitude;
        force_y = force_in[1] + sin(theta)*bump*bump_magnitude;
    } else {
        force_x = force_in[0]; 
        force_y = force_in[1];
    }

    /* status (1) */
    if (state == STATE_REWARD && new_state)
        ssSetIWorkValue(S, 68, ssGetIWorkValue(S, 68) + 1);
    if (state == STATE_ABORT && new_state)
        ssSetIWorkValue(S, 69, ssGetIWorkValue(S, 69) + 1);
    if (state == STATE_FAIL && new_state)
        ssSetIWorkValue(S, 70, ssGetIWorkValue(S, 70) + 1);
    if (state == STATE_INCOMPLETE && new_state)
        ssSetIWorkValue(S, 71, ssGetIWorkValue(S, 71) + 1);
    
    status[0] = state;
    status[1] = bump;//ssGetIWorkValue(S, 68); /* num rewards     */
    status[2] = stim; //ssGetIWorkValue(S, 69); /* num aborts      */
    status[3] = 100*stim_trial_pct; //ssGetIWorkValue(S, 70); /* num fails       */
    status[4] = bump_duration_counter; //ssGetIWorkValue(S, 71); /* num incompletes */
    
    /* word (2) */
    if (new_state) {
        switch (state) {
            case STATE_PRETRIAL:
				if (direction == 0) {
					word = WORD_START_FORWARD_TRIAL;
				} else {
					word = WORD_START_REVERSE_TRIAL;
				}
                break;
            case STATE_ORIGIN_ON:
                word = WORD_ORIGIN_TARGET_ON;
                break;
            case STATE_ORIGIN_DELAY:
                word = WORD_DESTINATION_TARGET_ON;
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
            default:
                word = 0;
        }
    } else if ( stim == 1 &&
                state==STATE_MOVEMENT && 
                ( ( direction == 0 && cos( -target_angle )*cursor[0] - sin( -target_angle )*cursor[1] <= 0) ||
                  ( direction == 1 && cos( -target_angle )*cursor[0] - sin( -target_angle )*cursor[1] >= 0) )
              ) {
		/* stim */
		word = WORD_STIM(0);
		ssSetIWorkValue(S, 73, -1);
	} else {
        /* not a new state, but maybe we have a mid-state event */
        if (bump_started) {
            /* just started a bump */
            word = WORD_BUMP(bump);
        } else {
            word = 0;
        }
    }
    
    /* target_pos (3) */
    /* origin */
    if ( state == STATE_ORIGIN_ON || 
         state == STATE_ORIGIN_HOLD || 
         state == STATE_ORIGIN_DELAY )
    {
        /* origin target on */
        target_pos[0] = 1;
        for (i=0; i<4; i++) {
            target_pos[i+1] = target_origin[i];
        }
    } else {
        /* center target off */
        target_pos[0] = 0;
        for (i=0; i<4; i++) {
            target_pos[i+1] = 0;
        }
    }
    
	/* destination */
    if ( state == STATE_ORIGIN_DELAY ||
         state == STATE_MOVEMENT ||
         state == STATE_DEST_HOLD )
    {
        /* destination target on */
        target_pos[5] = 1;
        for (i=0; i<4; i++) {
            target_pos[i+6] = target_destination[i];
        }
    } else {
        /* destination target off */
        target_pos[5] = 0;
        for (i=0; i<4; i++) {
            target_pos[i+6] = 0;
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
        if (state == STATE_ABORT) {
            tone_cnt++;
            tone_id = TONE_ABORT;
        } else if (state == STATE_MOVEMENT) {
            tone_cnt++;
            tone_id = TONE_GO;
        } else if (state == STATE_REWARD) {
            tone_cnt++;
            tone_id = TONE_REWARD;
        }
    }
    if (bump_started) {
      tone_cnt++;
      tone_id = TONE_MASK;
    }
    
    /* version (6) */
    version[0] = BEHAVIOR_VERSION_MAJOR;
    version[1] = BEHAVIOR_VERSION_MINOR;
    version[2] = BEHAVIOR_VERSION_MICRO;
    version[3] = BEHAVIOR_VERSION_BUILD;
    
    /* pos (7) */
    if (abs(cursor[0]*cos(target_angle) + cursor[1]*sin(target_angle)) < window_size && state == STATE_MOVEMENT) {
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
    ssSetIWorkValue(S, 67, bump_duration_counter);
    
    status_p = ssGetOutputPortRealSignal(S,1);
    for (i=0; i<5; i++) 
        status_p[i] = status[i];
    
    word_p = ssGetOutputPortRealSignal(S,2);
    word_p[0] = word;
    
    target_p = ssGetOutputPortRealSignal(S,3);
    for (i=0; i<10; i++) {
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