/* mastercon_rw.c
 *
 * Master Control block for behavior: center-out task
 */

#define S_FUNCTION_NAME mastercon_rw
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include <stdlib.h>
#include "simstruc.h"

#define TASK_RW 1
#include "words.h"
#include "random_macros.h"

#define PI (3.141592654)

/*
 * Tunable parameters
 */
static real_T num_targets = 8;      /* number of sequential targets */
#define param_num_targets mxGetScalar(ssGetSFcnParam(S,0))
static real_T target_size = 3.0;    /* width and height of targets in cm */
#define param_target_size mxGetScalar(ssGetSFcnParam(S,1))

static real_T work_area_width = 30.0; /* width of area in which to display tgts */
#define param_work_area_width mxGetScalar(ssGetSFcnParam(S,2))
static real_T work_area_height = 30.0; /* height of area in which to display tgts */
#define param_work_area_height mxGetScalar(ssGetSFcnParam(S,3))

/* dwell time in state 2 */
static real_T target_hold_l = .5;
#define param_target_hold_l mxGetScalar(ssGetSFcnParam(S,4))
static real_T target_hold_h = .5;
#define param_target_hold_h mxGetScalar(ssGetSFcnParam(S,5))

static real_T movement_time = 10.0;  /* movement time */
#define param_movement_time mxGetScalar(ssGetSFcnParam(S,6))

static real_T initial_movement_time = 10.0;  /* movement time */
#define param_initial_movement_time mxGetScalar(ssGetSFcnParam(S,7))

#define param_intertrial mxGetScalar(ssGetSFcnParam(S,8))
static real_T abort_timeout   = 1.0;    /* delay after abort */
static real_T failure_timeout = 1.0;    /* delay after failure */
static real_T incomplete_timeout = 1.0; /* delay after incomplete */
static real_T reward_timeout  = 1.0;    /* delay after reward before starting next trial
                                         * This is NOT the reward pulse length */

#define param_master_reset mxGetScalar(ssGetSFcnParam(S,9))

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_INITIAL_MOVEMENT 1
#define STATE_TARGET_HOLD 2
#define STATE_MOVEMENT 3
#define STATE_REWARD 82
#define STATE_ABORT 65
#define STATE_FAIL 70
#define STATE_INCOMPLETE 74

#define TONE_GO 1
#define TONE_REWARD 2
#define TONE_ABORT 3

static void mdlCheckParameters(SimStruct *S)
{
    num_targets = param_num_targets;
    target_size = param_target_size;
    
    target_hold_l = param_target_hold_l;
    target_hold_h = param_target_hold_h;

    movement_time = param_movement_time;
    initial_movement_time = param_initial_movement_time;

    abort_timeout   = param_intertrial;    
    failure_timeout = param_intertrial;
    reward_timeout  = param_intertrial;   
    incomplete_timeout = param_intertrial;
}

static void mdlInitializeSizes(SimStruct *S)
{
    int i;
    
    ssSetNumSFcnParams(S, 10); 
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* parameter number mismatch */
    }
    for (i=0; i<ssGetNumSFcnParams(S); i++)
        ssSetSFcnParamTunable(S,i, 1);
    mdlCheckParameters(S);
    
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 1);
    
    /*
     * Block has 2 input ports
     *      input port 0: (position) of width 2 (x, y)
     *      input port 1: (force) of width 2 (x, y)
     */
    if (!ssSetNumInputPorts(S, 2)) return;
    ssSetInputPortWidth(S, 0, 2);
    ssSetInputPortWidth(S, 1, 2);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    
    /* 
     * Block has 6 output ports (force, status, word, targets, reward, tone) of widths:
     *  force: 2
     *  status: 4 ( block counter, successes, aborts, failures )
     *  word:  1 (8 bits)
     *  target: 10 ( target 1, 2: 
     *                  on/off, 
     *                  target UL corner x, 
     *                  target UL corner y,
     *                  target LR corner x, 
     *                  target LR corner y)
     *  reward: 1
     *  tone: 2     ( 1: counter incemented for each new tone, 2: tone ID )
     */
    if (!ssSetNumOutputPorts(S, 6)) return;
    ssSetOutputPortWidth(S, 0, 2);
    ssSetOutputPortWidth(S, 1, 4);
    ssSetOutputPortWidth(S, 2, 1);
    ssSetOutputPortWidth(S, 3, 10);
    ssSetOutputPortWidth(S, 4, 1);
    ssSetOutputPortWidth(S, 5, 2);
    
    ssSetNumSampleTimes(S, 1);
    
    /* work buffers */
    ssSetNumRWork(S, 512);  /* 0: time of last timer reset 
                               1: tone counter (incremented each time a tone is played)
                               2: tone id
                               3: current target hold time
                         [4-511]: positions of targets stored as (x, y)
                           */
    ssSetNumPWork(S, 0);
    ssSetNumIWork(S, 5); /*    0: state_transition (true if state changed), 
                               1: current target index (in sequence),
                               2: successes
                               3: failures
                               4: aborts */
    
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
    
    /* initialize state to zero */
    x0 = ssGetRealDiscStates(S);
    *x0 = 0.0;
    
    /* notify that we just entered this state */
    ssSetIWorkValue(S, 0, 1);
    
    /* set target index to indicate that we need to begin a new block */
    ssSetIWorkValue(S, 1, (int)num_targets-1);
    
    /* set the tone counter to zero */
    ssSetRWorkValue(S, 1, 0.0);
    ssSetRWorkValue(S, 2, 0.0);
    
    /* set trial counters to zero */
    ssSetIWorkValue(S, 2, 0);
    ssSetIWorkValue(S, 3, 0);
    ssSetIWorkValue(S, 4, 0);
}

/* macro for setting state changed */
#define state_changed() (ssSetIWorkValue(S, 0, 1))
/* macro for resetting timer */
#define reset_timer() (ssSetRWorkValue(S, 0, (real_T)ssGetT(S)))

/* macro for assigning a random (if needed) time to the target hold time */
#define set_random_hold_time() if (target_hold_l == target_hold_h) { ssSetRWorkValue(S, 3, target_hold_l);} \
                               else {ssSetRWorkValue(S, 3, target_hold_l + UNI*(target_hold_h-target_hold_l));}

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
    /****************
     * Declarations *
     ****************/
    
    /* stupidly declare all variables at the begining of the function */
    int i;
    int *IWorkVector; 
    int target_index;
    real_T *RWorkVector;
    real_T *target_list;
    real_T target_x, target_y;
    real_T tgt[4];
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T elapsed_timer_time;
            
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

    /* get elapsed time since last timer reset */
    elapsed_timer_time = (real_T)(ssGetT(S)) - ssGetRWorkValue(S, 0);
    
    /* current target position */
    IWorkVector = ssGetIWork(S);
    target_index = IWorkVector[1];
    RWorkVector = ssGetRWork(S);
    target_list = RWorkVector+4;
    target_x = target_list[2*target_index];
    target_y = target_list[2*target_index+1];
    
    /* get target bounds */
    tgt[0] = target_x-target_size/2;
    tgt[1] = target_y+target_size/2;
    tgt[2] = target_x+target_size/2;
    tgt[3] = target_y-target_size/2;
    
    /*********************************
     * See if we have issued a reset *
     *********************************/
    if (param_master_reset != 0) {
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
            
            /* Update parameters */
            num_targets = param_num_targets;
            target_size = param_target_size;

            work_area_width = param_work_area_width;
            work_area_height = param_work_area_height;
           
            target_hold_l = param_target_hold_l;
            target_hold_h = param_target_hold_h;
           
            movement_time = param_movement_time;

            initial_movement_time = param_initial_movement_time;
           
            abort_timeout   = param_intertrial;
            failure_timeout = param_intertrial;
            incomplete_timeout = param_intertrial;
            reward_timeout  = param_intertrial;
            
            /* initilize target positions */
            for (i=0; i<num_targets; i++) {
                target_list[i*2]   = VNI * work_area_width / 2.0;  /* x position */
                target_list[i*2+1] = VNI * work_area_height / 2.0; /* y position */
            }

            /* and reset the counter */
            ssSetIWorkValue(S, 1, 0);
            
            new_state = STATE_INITIAL_MOVEMENT;

            break;
        case STATE_INITIAL_MOVEMENT:
            /* first target on */
            if (cursorInTarget(cursor, tgt)) {
                set_random_hold_time();
                new_state = STATE_TARGET_HOLD;
                reset_timer(); /* start target hold timer */
                state_changed();
            } else if (elapsed_timer_time > initial_movement_time) {
                new_state = STATE_INCOMPLETE;
                reset_timer(); /* start incomplete timeout */
                state_changed();
            }
            break;
        case STATE_MOVEMENT:
            /* new target on */
            if (cursorInTarget(cursor, tgt)) {
                set_random_hold_time();                
                new_state = STATE_TARGET_HOLD;
                reset_timer(); /* start target hold timer */
                state_changed();
            } else if (elapsed_timer_time > movement_time) {
                new_state = STATE_FAIL;
                reset_timer(); /* start incomplete timeout */
                state_changed();
            }
            break;
        case STATE_TARGET_HOLD:
            /* dwell time in target */
            if (!cursorInTarget(cursor, tgt)) {
                new_state = STATE_ABORT;
                reset_timer(); /* abort timeout */
                state_changed();
            } else if (elapsed_timer_time > ssGetRWorkValue(S,3)) {
                /* next state depends on whether there are more targets */
                if (target_index == (int)num_targets-1) {
                  /* no more targets */
                  new_state = STATE_REWARD;
                  reset_timer(); /* reward timer */
                  state_changed();
                } else {
                  /* more targets */
                  target_index++;
                  ssSetIWorkValue(S, 1, target_index);
                  new_state = STATE_MOVEMENT;
                  reset_timer(); /* movement timer */
                  state_changed();                
                }
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
    
    KISS; /* burn a place in the prng */
    
    UNUSED_ARG(tid);
}

/*** HERE ***/

static void mdlOutputs(SimStruct *S, int_T tid)
{
    /********************
     *  Initialization
     ********************/
    int i;
    int_T *IWorkVector;
    real_T *RWorkVector;
    int_T target_index;
    real_T *target_list;
    real_T target_x, target_y;
    real_T tgt[4];
    
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T force_in[2];
    
    /* allocate holders for outputs */
    real_T force_x, force_y, word, reward, tone_cnt, tone_id;
    real_T target_pos[10];
    real_T status[4];
    
    /* pointers to output buffers */
    real_T *force_p;
    real_T *word_p;
    real_T *target_p;
    real_T *status_p;
    real_T *reward_p;
    real_T *tone_p;
    
    /* get current state */
    real_T *state_r = ssGetRealDiscStates(S);
    int state = (int)(state_r[0]);
    int new_state = ssGetIWorkValue(S, 0);
    ssSetIWorkValue(S, 0, 0); /* reset changed state each iteration */

    /* target position */
    IWorkVector = ssGetIWork(S);
    target_index = IWorkVector[1];
    RWorkVector = ssGetRWork(S);
    target_list = RWorkVector+4;
    target_x = target_list[2*target_index];
    target_y = target_list[2*target_index+1];
    
    /* get current tone counter */
    tone_cnt = ssGetRWorkValue(S, 1);
    tone_id = ssGetRWorkValue(S, 2);
    
    /* get target bounds */
    tgt[0] = target_x-target_size/2;
    tgt[1] = target_y+target_size/2;
    tgt[2] = target_x+target_size/2;
    tgt[3] = target_y-target_size/2;
    
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
    force_x = force_in[0]; 
    force_y = force_in[1]; 
  
    /* status (1) */
    if (state == STATE_REWARD && new_state)
        ssSetIWorkValue(S, 2, ssGetIWorkValue(S, 2)+1);
    if (state == STATE_ABORT && new_state)
        ssSetIWorkValue(S, 3, ssGetIWorkValue(S, 3)+1);
    if (state == STATE_FAIL && new_state)
        ssSetIWorkValue(S, 4, ssGetIWorkValue(S, 4)+1);
    
    status[0] = state;
    status[1] = ssGetIWorkValue(S, 2); // num rewards
    status[2] = ssGetIWorkValue(S, 3); // num aborts
    status[3] = ssGetIWorkValue(S, 4); // num fails
    
    /* word (2) */
    if (new_state) {
        switch (state) {
            case STATE_PRETRIAL:
                word = WORD_START_TRIAL;
                break;
            case STATE_INITIAL_MOVEMENT:
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
    } else {
        /* not a new state */
        word = 0;
    }
    
    /* target_pos (3) */
    if ( state == STATE_INITIAL_MOVEMENT || 
         state == STATE_MOVEMENT || 
         state == STATE_TARGET_HOLD )
    {
        /* target on */
        target_pos[0] = 1;
        for (i=0; i<4; i++) {
            target_pos[i+1] = tgt[i];
        }
    } 
    else 
    {
        /* target off */
        target_pos[0] = 0;
        for (i=0; i<4; i++) {
            target_pos[i+1] = 0;
        }
    }
    
    /* we never need a second target */
    target_pos[5] = 0;
    for (i=0; i<4; i++) {
        target_pos[i+6] = 0;
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
        

    /**********************************
     * Write outputs back to SimStruct
     **********************************/
    force_p = ssGetOutputPortRealSignal(S,0);
    force_p[0] = force_x;
    force_p[1] = force_y;
    
    status_p = ssGetOutputPortRealSignal(S,1);
    for (i=0; i<4; i++) 
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
    
    UNUSED_ARG(tid);
}

static void mdlTerminate (SimStruct *S) { UNUSED_ARG(S); }

#ifdef MATLAB_MEX_FILE   /* Is this being compiled as a MEX-file? */
#include "simulink.c"    /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"     /* Code generation registration func */
#endif