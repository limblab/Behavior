/* $Id: $
 *
 * Master Control block for behavior: center-out + uncertainty task
 *
 */
#define S_FUNCTION_NAME mastercon_uc
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "simstruc.h"

#define TASK_UC 1
#include "words.h"

#define PI (3.141592654)

/*
 * Until we implement tunable parameters, these will act as defaults
 */
static real_T num_targets = 8;      /* number of peripheral targets */
#define param_num_targets mxGetScalar(ssGetSFcnParam(S,0))
static real_T target_radius = 10.0; /* radius of target circle in cm */
#define param_target_radius mxGetScalar(ssGetSFcnParam(S,1))
static real_T target_size = 5.0;    /* width and height of targets in cm */
#define param_target_size mxGetScalar(ssGetSFcnParam(S,2))
static real_T target_width = 5.0;   /* width of the outer target */
#define param_target_width mxGetScalar(ssGetSFcnParam(S,3))

static real_T center_hold;     /* dwell time in state 2 */
static real_T center_hold_l = .5;     
#define param_center_hold_l mxGetScalar(ssGetSFcnParam(S,4))
static real_T center_hold_h = 2.0;     
#define param_center_hold_h mxGetScalar(ssGetSFcnParam(S,5))

static real_T center_delay;     /* delay between outer target and go tone */
static real_T center_delay_l = 0.0;
#define param_center_delay_l mxGetScalar(ssGetSFcnParam(S,6))
static real_T center_delay_h = 0.0;
#define param_center_delay_h mxGetScalar(ssGetSFcnParam(S,7))

static real_T movement_time = 10.0;  /* movement time */
#define param_movement_time mxGetScalar(ssGetSFcnParam(S,8))

static real_T outer_hold;      /* outer target hold time */
static real_T outer_hold_l = 1.0;      
#define param_outer_hold_l mxGetScalar(ssGetSFcnParam(S,9))
static real_T outer_hold_h = 1.0; 
#define param_outer_hold_h mxGetScalar(ssGetSFcnParam(S,10))

#define param_intertrial mxGetScalar(ssGetSFcnParam(S,11))
static real_T abort_timeout   = 1.0;    /* delay after abort */
#define param_failure_timeout mxGetScalar(ssGetSFcnParam(S,12))
static real_T failure_timeout = 1.0;    /* delay after failure */
static real_T incomplete_timeout = 1.0; /* delay after incomplete */
static real_T reward_timeout  = 1.0;    /* delay after reward before starting next trial
                                         * This is NOT the reward pulse length */

static real_T catch_trial_pct = 0.0;    /* fraction of catch trials */
#define param_catch_trial_pct mxGetScalar(ssGetSFcnParam(S,13))
#define set_catch_trial(x) ssSetRWorkValue(S, 3, (x))
#define get_catch_trial() ssGetRWorkValue(S, 3)

static int idiot_mode = 0;
#define param_idiot_mode mxGetScalar(ssGetSFcnParam(S,14))

static real_T vperturb_mu = 2.0;
#define param_vperturb_mu mxGetScalar(ssGetSFcnParam(S,15))
static real_T vperturb_sigma = 2.0;
#define param_vperturb_sigma mxGetScalar(ssGetSFcnParam(S,16))
static real_T vperturb_percent_vis = 1.0;
#define param_vperturb_percent_vis mxGetScalar(ssGetSFcnParam(S,17))
static real_T visual_rotation = 0;
#define param_visual_rotation mxGetScalar(ssGetSFcnParam(S,18))

static real_T percent_no_feedback = 0.0;
#define param_percent_no_feedback mxGetScalar(ssGetSFcnParam(S,19))
static real_T percent_med_feedback = 0.0;
#define param_percent_med_feedback mxGetScalar(ssGetSFcnParam(S,20))
static real_T percent_big_feedback = 0.0;
#define param_percent_big_feedback mxGetScalar(ssGetSFcnParam(S,21))

static int show_endpoint_time = 10;
#define param_show_endpoint_time mxGetScalar(ssGetSFcnParam(S,22))

static real_T master_reset = 0.0;
#define param_master_reset mxGetScalar(ssGetSFcnParam(S,23))

static void updateVersion(SimStruct *S)
{
    /* set variable to file version for display on screen */
    /* DO NOT change this version string by hand.  CVS will update it upon commit */
    char version_str[256] = "$Revision: 1.5 $";
    char* version;
    
    version_str[strlen(version_str)-1] = 0; // set last "$" to zero
    version = version_str + 11 * sizeof(char); // Skip over "$Revision: "
    ssSetRWorkValue(S, 4, atof(version));
}

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_CT_ON 1
#define STATE_CENTER_HOLD 2
#define STATE_CENTER_DELAY 3
#define STATE_MOVEMENT 4
#define STATE_OUTER_HOLD 5
#define STATE_REWARD 82
#define STATE_ABORT 65
#define STATE_FAIL 70
#define STATE_INCOMPLETE 74
#define STATE_OUTPUT_DISPLACEMENT 6
#define STATE_SHOW_ENDPOINT 7

#define TONE_GO 1
#define TONE_REWARD 2
#define TONE_ABORT 3

static void mdlCheckParameters(SimStruct *S)
{
    num_targets = param_num_targets;
    target_radius = param_target_radius;
    target_size = param_target_size;
    
    center_hold_l = param_center_hold_l;
    center_hold_h = param_center_hold_h;

    center_delay_l = param_center_delay_l;
    center_delay_h = param_center_delay_h;

    movement_time = param_movement_time;

    outer_hold_l = param_outer_hold_l;
    outer_hold_h = param_outer_hold_h;

    abort_timeout   = param_intertrial;    
    failure_timeout = param_failure_timeout;
    reward_timeout  = param_intertrial;   
    incomplete_timeout = param_intertrial;
    
    idiot_mode = (int)param_idiot_mode;
    
    vperturb_mu = param_vperturb_mu;
    vperturb_sigma = param_vperturb_sigma;
    vperturb_percent_vis = param_vperturb_percent_vis;
    visual_rotation = param_visual_rotation;
    
    percent_no_feedback = param_percent_no_feedback;
    percent_med_feedback = param_percent_med_feedback;
    percent_big_feedback = param_percent_big_feedback;
    
    show_endpoint_time = param_show_endpoint_time;
}

static void mdlInitializeSizes(SimStruct *S)
{
    int i;
    
    ssSetNumSFcnParams(S, 24);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* parameter number mismatch */
    }
    for (i=0; i<ssGetNumSFcnParams(S); i++)
        ssSetSFcnParamTunable(S,i, 1);
    mdlCheckParameters(S);
    
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 1);
    
    /*
     * Block has 3 input ports
     *      input port 0: (position) of width 2 (x, y)
     *      input port 1: (force) of width 2 (x, y)
     *      input port 2: (catch force) of width 2 (x, y)
     */
    if (!ssSetNumInputPorts(S, 3)) return;
    ssSetInputPortWidth(S, 0, 2);
    ssSetInputPortWidth(S, 1, 2);
    ssSetInputPortWidth(S, 2, 2);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortDirectFeedThrough(S, 2, 1);
    
    /* 
     * Block has 6 output ports (force, status, word, targets, reward, tone) of widths:
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
     */
    if (!ssSetNumOutputPorts(S, 7)) return;
    ssSetOutputPortWidth(S, 0, 2);
    ssSetOutputPortWidth(S, 1, 5);
    ssSetOutputPortWidth(S, 2, 1);
    ssSetOutputPortWidth(S, 3, 10);
    ssSetOutputPortWidth(S, 4, 1);
    ssSetOutputPortWidth(S, 5, 2);
    ssSetOutputPortWidth(S, 6, 1);
    
    ssSetNumSampleTimes(S, 1);
    
    /* work buffers */
    ssSetNumRWork(S, 8);  /* 0: time of last timer reset 
                             1: tone counter (incremented each time a tone is played)
                             2: tone id
                             3: catch trial (1 for yes, 0 for no)
                             4: mastercon version
                             5: displacement (vis_perturbation mode)
                             6: endpoint[0]
                             7: endpoint[1]
                           */
    ssSetNumPWork(S, 0);
    ssSetNumIWork(S, 25); /*    0: state_transition (true if state changed), 
                                 1: current target index,
                            [2-17]: target presentation sequence (block/catch mode or vis_perturbation mode)
                                18: feedback type (vis_perturbation mode)
                                19: counter to output displacement
                                20: counter for showing endpoint
                                21: successes
                                22: failures
                                23: aborts 
                                24: incompletes */
    
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
    
    /* set catch trial to zero (init only) */
    ssSetRWorkValue(S, 3, 0.0);
    
    /* set the displacement output counter to -1 */
    ssSetIWorkValue(S, 19, -1);
    
    /* set the endpoint counter to 0 */
    ssSetIWorkValue(S, 20, 0);
    /* and position to 0 */
    ssSetRWorkValue(S, 6, 0);
    ssSetRWorkValue(S, 7, 0);
    
    /* set trial counters to zero */
    ssSetIWorkValue(S, 21, 0);
    ssSetIWorkValue(S, 22, 0);
    ssSetIWorkValue(S, 23, 0);
    ssSetIWorkValue(S, 24, 0);
    
    updateVersion(S);
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

static int cursorOutofCircle(real_T *c, real_T r)
{
    return ( sqrt(c[0]*c[0] + c[1]*c[1]) > r );
}

static int cursorInSection(real_T *c, real_T theta, real_T rad, real_T bound)
{
//    return ( (atan(c[0]/c[1]) > asin(sin(theta-w/2))) && (atan(c[0]/c[1]) < asin(sin(theta+w/2))) );

    real_T otc[2];
    real_T ang;
    
    otc[0] = cos(theta);
    otc[1] = sin(theta);
    ang = acos((otc[0]*c[0] + otc[1]*c[1])/(sqrt(c[0]*c[0] + c[1]*c[1])));
    return ( abs(ang) < bound );
}

#define MDL_UPDATE
static void mdlUpdate(SimStruct *S, int_T tid) 
{
    /********************
     * Declarations     *
     ********************/
    
    /* stupidly declare all variables at the begining of the function */
    int *IWorkVector; 
    int target_index;
    int *target_list;
    int target;

    int feedback;
    real_T displacement;
    int displacement_output_counter;
    int endpoint_timer;
    real_T endpoint[2];
    double x1, x2, w, rn; // params for drawing displacement and feedback
    real_T target_pos[2];
    
    real_T theta;
    real_T ct[4];
    real_T ot[4];
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T elapsed_timer_time;
    int reset_block = 0;
        
    /* block initialization working variables */
    int tmp_tgts[256];
    int tmp_sort[256];
    int i, j, tmp;
    
    /******************
     * Initialization *
     ******************/
    
    /* get current state */
    real_T *state_r = ssGetRealDiscStates(S);
    int state = (int)state_r[0];
    int new_state = state;
    
    double targaFileNum = 20.0;
    
    /* current cursor location */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 0);
    cursor[0] = *uPtrs[0];
    cursor[1] = *uPtrs[1];

    /* current target number */
    IWorkVector = ssGetIWork(S);
    target_index = IWorkVector[1];
    target_list = IWorkVector+2;
 
    target = target_list[target_index];
    
    /* get elapsed time since last timer reset */
    elapsed_timer_time = (real_T)(ssGetT(S)) - ssGetRWorkValue(S, 0);
    
    displacement_output_counter = ssGetIWorkValue(S, 19);
    endpoint_timer = ssGetIWorkValue(S, 20);
    endpoint[0] = ssGetRWorkValue(S, 6);
    endpoint[1] = ssGetRWorkValue(S, 7);
    
    /* get target bounds */
    theta = PI/2 - target*2*PI/num_targets;
    ct[0] = -target_size/2;
    ct[1] = target_size/2;
    ct[2] = target_size/2;
    ct[3] = -target_size/2;
    
    ot[0] = cos(theta)*target_radius-target_width/2;
    ot[1] = sin(theta)*target_radius+target_size/2;
    ot[2] = cos(theta)*target_radius+target_width/2;
    ot[3] = sin(theta)*target_radius-target_size/2;
    
    /* Awkward, but get the target (dummy cursor) position */
    displacement = ssGetRWorkValue(S, 5);
    if (visual_rotation) {
        // Visual Rotation
        target_pos[0] = (cos(displacement)*cursor[0] - sin(displacement)*cursor[1]);
        target_pos[1] = (sin(displacement)*cursor[0] + cos(displacement)*cursor[1]);
    } else {
        // Perpendicular displacement
        target_pos[0] = cursor[0]+displacement*sin(theta);
        target_pos[1] = cursor[1]-displacement*cos(theta);
    }
    
    /*********************************
     * See if we have issued a reset *
     *********************************/
    if (param_master_reset != master_reset) {
        master_reset = param_master_reset;
        ssSetIWorkValue(S, 19, -1);
        ssSetIWorkValue(S, 20, 0);
        ssSetIWorkValue(S, 21, 0);
        ssSetIWorkValue(S, 22, 0);
        ssSetIWorkValue(S, 23, 0);
        ssSetIWorkValue(S, 24, 0);
        state_r[0] = STATE_PRETRIAL;
        updateVersion(S);
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
            if (num_targets != param_num_targets) {
                num_targets = param_num_targets;
                reset_block = 1;
            }
            target_radius = param_target_radius;
            target_size = param_target_size;
            target_width = param_target_width;
    
            center_hold_l = param_center_hold_l;
            center_hold_h = param_center_hold_h;

            center_delay_l = param_center_delay_l;
            center_delay_h = param_center_delay_h;

            movement_time = param_movement_time;

            outer_hold_l = param_outer_hold_l;
            outer_hold_h = param_outer_hold_h;

            abort_timeout   = param_failure_timeout;    
            failure_timeout = param_failure_timeout;
            reward_timeout  = param_intertrial;
            incomplete_timeout = param_intertrial;
            
            catch_trial_pct = param_catch_trial_pct;
                       
            idiot_mode = (int)param_idiot_mode;
            
            vperturb_mu = param_vperturb_mu;
            vperturb_sigma = param_vperturb_sigma;
            vperturb_percent_vis = param_vperturb_percent_vis;

            percent_no_feedback = param_percent_no_feedback;
            percent_med_feedback = param_percent_med_feedback;
            percent_big_feedback = param_percent_big_feedback;
            
            show_endpoint_time = param_show_endpoint_time;

            /* if we do not have our targets initialized => new block */
            if ((target_index == num_targets-1 || reset_block)) {
                /* initialize the targets */
                for (i=0; i<num_targets; i++) {
                    tmp_tgts[i] = i;
                    tmp_sort[i] = rand();
                }
                for (i=0; i<num_targets-1; i++) {
                    for (j=0; j<num_targets-1; j++) {
                        if (tmp_sort[j] < tmp_sort[j+1]) {
                            tmp = tmp_sort[j];
                            tmp_sort[j] = tmp_sort[j+1];
                            tmp_sort[j+1] = tmp;
                            
                            tmp = tmp_tgts[j];
                            tmp_tgts[j] = tmp_tgts[j+1];
                            tmp_tgts[j+1] = tmp;
                        }
                    }
                }
                /* write them back */
                for (i=0; i<num_targets; i++) {
                    target_list[i] = tmp_tgts[i];
                }
                /* and reset the counter */
                ssSetIWorkValue(S, 1, 0);
            } else {
                /* just advance the counter */
                target_index++;
                /* and write it back */
                ssSetIWorkValue(S, 1, target_index);

                target = target_list[target_index];
            }
          
            // ihs: pick feedback type and displacement for this trial...
                       
            rn = ((double)rand())/((double)RAND_MAX);
            if (rn < percent_no_feedback) {feedback = 0;}
            else if (rn < percent_no_feedback+percent_big_feedback) {feedback = ceil(((double)rand())/((double)RAND_MAX)*targaFileNum) + 4;}
            else if (rn < percent_no_feedback+percent_big_feedback+percent_med_feedback) {feedback = ceil(((double)rand())/((double)RAND_MAX)*targaFileNum) + targaFileNum + 4;}
            else {feedback = 4;}
            ssSetIWorkValue(S, 18, feedback);

            /* Polar form of the Box-Muller Transform (much faster) */
            w = 1.0;
            for (i=0; i<100; i++) {
               if (w >= 1.0) {
                  x1 = 2.0 * ((double)rand())/((double)RAND_MAX) - 1.0;
                  x2 = 2.0 * ((double)rand())/((double)RAND_MAX) - 1.0;
                  w = x1 * x1 + x2 * x2;
               }
            }

            w = sqrt( (-2.0 * log( w ) ) / w );
            displacement = vperturb_mu + x1*w*vperturb_sigma;
            ssSetRWorkValue(S, 5, displacement);
            
            /* In all cases, we need to decide on the random timer durations */
            if (center_hold_h == center_hold_l) {
                center_hold = center_hold_h;
            } else {
                center_hold = center_hold_l + (center_hold_h - center_hold_l)*((double)rand())/((double)RAND_MAX);
            }
            if (center_delay_h == center_delay_l) {
                center_delay = center_delay_h;
            } else {
                center_delay = center_delay_l + (center_delay_h - center_delay_l)*((double)rand())/((double)RAND_MAX);
            }
            if (outer_hold_h == outer_hold_l) {
                outer_hold = outer_hold_h;
            } else {
                outer_hold = outer_hold_l + (outer_hold_h - outer_hold_l)*((double)rand())/((double)RAND_MAX);
            }
                                                 
            /* and advance */
            // ihs: new_state = STATE_CT_ON;
            new_state = STATE_OUTPUT_DISPLACEMENT;
            state_changed();

            /* skip target -1 */
            if (target == -1) {
                new_state = STATE_PRETRIAL;
            }

            break;
        case STATE_OUTPUT_DISPLACEMENT:
            /* State to output displacement */
            // ihs: adjust this one to change precision on the displacement
            if (displacement_output_counter>4) {
                ssSetIWorkValue(S, 19, -1);
                new_state = STATE_CT_ON;
                state_changed();
            } else {
                ssSetIWorkValue(S, 19, displacement_output_counter+1);
            }
            break;
        case STATE_CT_ON:
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
                new_state = STATE_INCOMPLETE;
                reset_timer(); /* abort timeout */
                state_changed();
            } else if (elapsed_timer_time > center_hold && target != -1) {
                new_state = STATE_CENTER_DELAY;
                reset_timer(); /* delay timer */
                state_changed();
            }
            break;
        case STATE_CENTER_DELAY:
            /* center delay (outer target on) */
            if (!cursorInTarget(cursor, ct)) {
                new_state = STATE_ABORT;
                reset_timer(); /* abort timeout */
                state_changed();
            } else if (elapsed_timer_time > center_delay) {
                new_state = STATE_MOVEMENT;
                reset_timer(); /* movement timer */
                state_changed();
            }
            break;
        case STATE_MOVEMENT:
            /* movement phase (go tone on entry) */
            if (idiot_mode==0) {
                if (cursorOutofCircle(target_pos, target_radius)) {
                    new_state = STATE_SHOW_ENDPOINT;                    
                    reset_timer();  /* endpoint timer */
                    state_changed();
                } else if (elapsed_timer_time > movement_time) {
                    new_state = STATE_INCOMPLETE;
                    reset_timer(); /* failure timeout */
                    state_changed();
                }
            } else {
                if (cursorInTarget(target_pos, ot)) {
                    new_state = STATE_OUTER_HOLD;
                    reset_timer(); /* outer hold timer */
                    state_changed();
                } else if (elapsed_timer_time > movement_time) {
                    new_state = STATE_INCOMPLETE;
                    reset_timer(); /* failure timeout */
                    state_changed();
                }
            }
            break;
        case STATE_OUTER_HOLD:
            /* outer target hold phase */
            if (!cursorInTarget(target_pos, ot)) {
                new_state = STATE_INCOMPLETE;
                reset_timer(); /* failure timeout */
                state_changed();
            } else if (elapsed_timer_time > outer_hold) {
                new_state = STATE_REWARD;
                reset_timer(); /* reward (inter-trial) timeout */
                state_changed();
            }
            break;
        case STATE_ABORT:
            /* abort */
            if (elapsed_timer_time > abort_timeout) {
                new_state = STATE_PRETRIAL;
                state_changed();
                
                if (idiot_mode) {
                    target_index--;
                    ssSetIWorkValue(S, 1, target_index);
                }
            }
            break;
        case STATE_FAIL:
            /* failure */
            if (elapsed_timer_time > failure_timeout) {
                new_state = STATE_PRETRIAL;
                state_changed();
                if (idiot_mode) {
                    target_index--;
                    ssSetIWorkValue(S, 1, target_index);
                }
            }
            break;
        case STATE_INCOMPLETE:
            /* incomplete */
            if (elapsed_timer_time > incomplete_timeout) {
                new_state = STATE_PRETRIAL;
                state_changed();
                if (idiot_mode) {
                    target_index--;
                    ssSetIWorkValue(S, 1, target_index);
                }
            }
            break;
        case STATE_REWARD:
            /* reward */
            if (elapsed_timer_time > reward_timeout) {
                new_state = STATE_PRETRIAL;
                state_changed();
            }
            break;
        case STATE_SHOW_ENDPOINT:
            /* feedback at the end of a reach */
            if (endpoint_timer < show_endpoint_time) {
                ssSetIWorkValue(S, 20, endpoint_timer+1);
            } else {
                ssSetIWorkValue(S, 20, 0);
                // double check for reward
                // if (cursorInSection(endpoint, asin(sin(theta)), target_radius, asin(target_width/4/target_radius))) {
                
                // hack for the one target version
                if (abs(endpoint[0]) < (target_width/2 - 0.2)) {
                    new_state = STATE_REWARD;
                } else {
                    new_state = STATE_ABORT;
                }
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
    int_T target_index;
    int_T *target_list;
    int target;
    
    int feedback;
    real_T displacement;
    int displacement_output_counter;
    int endpoint_timer;
	real_T endpoint[2];
    
    float dispvalue;
    float *dispvalue_p;
    char *bytes;

    real_T theta;
    real_T ct[4];
    real_T ot[4];
    
    float otc[2];
    float d2target;
    float dotprod;
    float a2target;
    
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T force_in[2];
    real_T catch_force_in[2];
    
    /* allocate holders for outputs */
    real_T force_x, force_y, word, reward, tone_cnt, tone_id;
    real_T target_pos[10];
    real_T status[5];
    real_T version;
    
    /* pointers to output buffers */
    real_T *force_p;
    real_T *word_p;
    real_T *target_p;
    real_T *status_p;
    real_T *reward_p;
    real_T *tone_p;
    real_T *version_p;
    
    /* get current state */
    real_T *state_r = ssGetRealDiscStates(S);
    int state = (int)(state_r[0]);
    int new_state = ssGetIWorkValue(S, 0);
    ssSetIWorkValue(S, 0, 0); /* reset changed state each iteration */

    /* current target number */
    IWorkVector = ssGetIWork(S);
    target_index = IWorkVector[1];
    target_list = IWorkVector+2;

    target = target_list[target_index];
    
    feedback = ssGetIWorkValue(S, 18);
    displacement = ssGetRWorkValue(S, 5);
    displacement_output_counter = ssGetIWorkValue(S, 19);
    endpoint_timer = ssGetIWorkValue(S, 20);
    endpoint[0] = ssGetRWorkValue(S, 6);
    endpoint[1] = ssGetRWorkValue(S, 7);
    
    /* get current tone counter */
    tone_cnt = ssGetRWorkValue(S, 1);
    tone_id = ssGetRWorkValue(S, 2);
    
    /* get target bounds */
    theta = PI/2 - target*2*PI/num_targets;
    ct[0] = -target_size/2;
    ct[1] = target_size/2;
    ct[2] = target_size/2;
    ct[3] = -target_size/2;
    
    ot[0] = cos(theta)*target_radius-target_width/2;
    ot[1] = sin(theta)*target_radius+target_size/2;
    ot[2] = cos(theta)*target_radius+target_width/2;
    ot[3] = sin(theta)*target_radius-target_size/2;
    
    /* current cursor location */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 0);
    cursor[0] = *uPtrs[0];
    cursor[1] = *uPtrs[1];
    
    /* input force */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 1);
    force_in[0] = *uPtrs[0];
    force_in[1] = *uPtrs[1];
    
    /* input catch force */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 2);
    catch_force_in[0] = *uPtrs[0];
    catch_force_in[1] = *uPtrs[1];
    
    /********************
     * Calculate outputs
     ********************/
    
    /* force (0) */
    if (get_catch_trial() && (
            state == STATE_CENTER_DELAY ||
            state == STATE_MOVEMENT ||
            state == STATE_OUTER_HOLD
        )) 
    {
        force_x = catch_force_in[0];
        force_y = catch_force_in[1];
    } else {
        force_x = force_in[0]; 
        force_y = force_in[1]; 
    }
    
    /* status (1) */
    if (state == STATE_REWARD && new_state)
        ssSetIWorkValue(S, 21, ssGetIWorkValue(S, 21)+1);
    if (state == STATE_ABORT && new_state)
        ssSetIWorkValue(S, 22, ssGetIWorkValue(S, 22)+1);
    if (state == STATE_FAIL && new_state)
        ssSetIWorkValue(S, 23, ssGetIWorkValue(S, 23)+1);
    if (state == STATE_INCOMPLETE && new_state)
        ssSetIWorkValue(S, 24, ssGetIWorkValue(S, 24)+1);

    status[0] = state;   //IWorkVector[1];
    status[1] = ssGetIWorkValue(S, 21); // num rewards
    status[2] = ssGetIWorkValue(S, 22); // num aborts
    status[3] = ssGetIWorkValue(S, 23); // num fails
    status[4] = ssGetIWorkValue(S, 24); // num incompletes

    /* word (2) */
    if (new_state) {
        switch (state) {
            case STATE_PRETRIAL:
                word = WORD_START_TRIAL;
                break;
            case STATE_CT_ON:
                word = WORD_CT_ON;
                break;
            case STATE_OUTPUT_DISPLACEMENT:
                word = WORD_FEEDBACK(feedback);
                break;
            case STATE_CENTER_DELAY:
                word = WORD_OT_ON(target);
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
            case STATE_SHOW_ENDPOINT:
                word = WORD_ENDPOINT;
                ssSetRWorkValue(S, 6, target_pos[1]);
                ssSetRWorkValue(S, 7, target_pos[2]);
                break;
            default:
                word = 0;
        }
    } else {
        /* not a new state, but maybe we have a mid-state event */
        if (state == STATE_OUTPUT_DISPLACEMENT) {
            // ihs: outputs the displacement_output_counter-th byte
            
            
            if (displacement_output_counter<5) {
                dispvalue = (float)displacement;
                dispvalue_p = &dispvalue;
                bytes = (char *)dispvalue_p;
                word = bytes[displacement_output_counter-1];
            } else {
                word = WORD_OUTPUT_BLOCK;
            }
            
            // Just output the counter for now...
            //word = displacement_output_counter;
         } else {
            word = 0;
         }
    }
    
    /* target_pos (3) */
    // Map T1 to the cursor...

    /* Initialize target_pos */
    target_pos[0] = 1;
    target_pos[1] = cursor[0];
    target_pos[2] = cursor[1];
    target_pos[3] = cursor[0];
    target_pos[4] = cursor[1];
   
    if ( state == STATE_MOVEMENT || 
         state == STATE_OUTER_HOLD || 
         state == STATE_SHOW_ENDPOINT) {
        // Only display for a percentage of the movement
        /*
        otc[0] = cos(theta)*target_radius;    
        otc[1] = sin(theta)*target_radius;
        dotprod = (-otc[0]+cursor[0])*(-otc[0]) + (-otc[1]+cursor[1])*(-otc[1]);
        a2target = dotprod/target_radius;
        if ((abs(a2target - target_radius/2)/target_radius) < vperturb_percent_vis/2) {
            target_pos[0] = feedback;
        } else {
            target_pos[0] = 0;
        }
         */
        
        if (cursor[1] < target_radius*vperturb_percent_vis) {
            target_pos[0] = feedback;
        } else {
            target_pos[0] = 0;
        }
        
        if (visual_rotation) {
            // Visual Rotation
            target_pos[1] = (cos(displacement)*cursor[0] - sin(displacement)*cursor[1]);
            target_pos[2] = (sin(displacement)*cursor[0] + cos(displacement)*cursor[1]);
            target_pos[3] = (cos(displacement)*cursor[0] - sin(displacement)*cursor[1]);
            target_pos[4] = (sin(displacement)*cursor[0] + cos(displacement)*cursor[1]);
        } else {
            // Perpendicular displacement
            target_pos[1] = cursor[0]+displacement*sin(theta);
            target_pos[2] = cursor[1]-displacement*cos(theta);
            target_pos[3] = cursor[0]+displacement*sin(theta);
            target_pos[4] = cursor[1]-displacement*cos(theta);
        }
        
        if (idiot_mode==1) {
            ssSetRWorkValue(S, 6, target_pos[1]);
            ssSetRWorkValue(S, 7, target_pos[2]);
        }
    } else if (state == STATE_CT_ON ||
            state == STATE_CENTER_HOLD ||
            state == STATE_CENTER_DELAY ||
            state == STATE_REWARD ||
            state == STATE_FAIL ||
            state == STATE_INCOMPLETE ||
            state == STATE_ABORT ||
            state == STATE_PRETRIAL) {
        // only display the cursor close the to the center target
        if (sqrt(cursor[0]*cursor[0] + cursor[1]*cursor[1]) < target_radius/2) {
            target_pos[0] = 4;  // Exact cursor
            target_pos[1] = cursor[0];
            target_pos[2] = cursor[1];
            target_pos[3] = cursor[0];
        } else {
            target_pos[0] = 0;
        }
    } else {
        /* don't draw */
        target_pos[0] = 0;
    }
    
    if (state == STATE_SHOW_ENDPOINT) {
        // show the cursor where it crossed the line
        target_pos[0] = 4;  // Exact cursor
        target_pos[1] = endpoint[0];
        target_pos[2] = endpoint[1];
        target_pos[3] = endpoint[0];
        target_pos[4] = endpoint[1];
    }
    
    // Make T2 switch between center and outer targets...
    if ( state == STATE_CT_ON || 
         state == STATE_CENTER_HOLD || 
         state == STATE_CENTER_DELAY ) {
        /* draw as center target */
        target_pos[5] = 1;
        for (i=0; i<4; i++) {
            target_pos[i+6] = ct[i];
        }
    } else if ( state == STATE_MOVEMENT ||
         state == STATE_OUTER_HOLD ||
         state == STATE_SHOW_ENDPOINT) {
        /* draw as outer target */
        target_pos[5] = 2;
        for (i=0; i<4; i++) {
            target_pos[i+6] = ot[i];
        }
    } else {
        /* don't draw */
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
    
    /* version (6) */
    version = ssGetRWorkValue(S, 4);
       
    /**********************************
     * Write outputs back to SimStruct
     **********************************/
    force_p = ssGetOutputPortRealSignal(S,0);
    force_p[0] = force_x;
    force_p[1] = force_y;
    
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
    version_p[0] = (real_T)version;
    
    UNUSED_ARG(tid);
}

static void mdlTerminate (SimStruct *S) { UNUSED_ARG(S); }

#ifdef MATLAB_MEX_FILE   /* Is this being compiled as a MEX-file? */
#include "simulink.c"    /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"     /* Code generation registration func */
#endif