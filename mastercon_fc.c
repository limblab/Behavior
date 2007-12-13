/* mastercon_fc.c
 *
 * Master Control block for behavior: force choice task
 */

#define S_FUNCTION_NAME mastercon_fc
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include <stdlib.h>
#include "simstruc.h"

#define TASK_FC 1
#include "words.h"

#define PI (3.141592654)

/*
 * Until we implement tunable parameters, these will act as defaults
 */

/* Stimulation parameters */

static real_T num_gradations = 16;  /* number of steps of stim intensity */
#define param_num_gradations mxGetScalar(ssGetSFcnParam(S,0))
static real_T pct_test_trials = 20; /* percent of test stim trials */
#define param_pct_test_trials mxGetScalar(ssGetSFcnParam(S,1))
static real_T training_mode = 0; /* true=show one outer target, false=show 2 */
#define param_training_mode mxGetScalar(ssGetSFcnParam(S,2))

/* Timing parameters */
static real_T center_hold;
static real_T center_hold_l = 0.5; /* shortest delay between entry of ct and stim */ 
#define param_center_hold_l mxGetScalar(ssGetSFcnParam(S,3))
static real_T center_hold_h = 1.0; /* longest delay between entry of ct and stim */ 
#define param_center_hold_h mxGetScalar(ssGetSFcnParam(S,4))

static real_T delay;
static real_T delay_l = 0.5; /* shortest delay between stim & outer target illumination */ 
#define param_delay_l mxGetScalar(ssGetSFcnParam(S,5))
static real_T delay_h = 1.0; /* longest delay between stim & outer target illuminatio */ 
#define param_delay_h mxGetScalar(ssGetSFcnParam(S,6))

static real_T movement = 2.0; /* time limit for monkey to reach an outer target after illumination*/
#define param_movement mxGetScalar(ssGetSFcnParam(S,7))
static real_T intertrial = 1.0; /* time between trials*/
#define param_intertrial mxGetScalar(ssGetSFcnParam(S,8))

/* Dimensions parameters */
static real_T target_size = 1.0; /*width of targets in cm*/
#define param_target_size mxGetScalar(ssGetSFcnParam(S,9))
static real_T target_distance = 5.0; /*distance between ct and ot in cm*/
#define param_target_distance mxGetScalar(ssGetSFcnParam(S,10))

static real_T abort_timeout   = 1.0;    /* delay after abort */
static real_T failure_timeout = 1.0;    /* delay after failure */
static real_T incomplete_timeout = 1.0; /* delay after incomplete */
static real_T center_bump_timeout  = 1.0; 
static real_T reward_timeout  = 1.0;    /* delay after reward before starting next trial
                                         * This is NOT the reward pulse length */

/* #define param_master_reset mxGetScalar(ssGetSFcnParam(S,16))      no master reset implemented */   

/* Trial types */
#define TRIAL_TYPE_NO_STIM 0
#define TRIAL_TYPE_STIM 1
#define TRIAL_TYPE_TEST 2

#define NUM_TYPES_PER_BLOCK 40

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_CT_ON 1
#define STATE_CENTER_HOLD 2
#define STATE_STIM 3
#define STATE_MOVEMENT 4
#define STATE_REWARD 82
#define STATE_ABORT 65
#define STATE_FAIL 70
#define STATE_INCOMPLETE 74

#define TONE_GO 1
#define TONE_REWARD 2
#define TONE_ABORT 3

static void mdlCheckParameters(SimStruct *S)
{
    num_gradations = param_num_gradations;
    pct_test_trials = param_pct_test_trials;
    training_mode = param_training_mode;
    
    center_hold_l = param_center_hold_l;
    center_hold_h = param_center_hold_h;
    delay_l = param_delay_l;
    delay_h = param_delay_h;
    movement = param_movement;
    intertrial = param_intertrial;

    target_size = param_target_size;
    target_distance = param_target_distance;

    abort_timeout   = param_intertrial;    
    failure_timeout = param_intertrial;
    reward_timeout  = param_intertrial;   
    incomplete_timeout = param_intertrial;
}

static void mdlInitializeSizes(SimStruct *S)
{
    int i;
    
    ssSetNumSFcnParams(S, 12);                  
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
    ssSetNumRWork(S, 3);  /* 0: time of last timer reset 
                             1: tone counter (incremented each time a tone is played)
                             2: tone id
                           */
    ssSetNumPWork(S, 0);
    ssSetNumIWork(S, 63); /*     0: state_transition (true if state changed), 
                                 1: trial type index,
                                 2: stimulus gradation index
                            [3-42]: trial type presentation sequence (e.g., test, stim, no stim)
                           [43-58]: gradation presentation sequence
                                59: successes
                                60: failures
                                61: aborts
                                62: incompletes */
    
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
    
    /* set both trial indices to indicate that we need to begin a new block */
    ssSetIWorkValue(S, 1, NUM_TYPES_PER_BLOCK-1);
    ssSetIWorkValue(S, 2, (int)num_gradations-1);
    
    /* set the tone counter to zero */
    ssSetRWorkValue(S, 1, 0.0);
        
    /* set trial counters to zero */
    ssSetIWorkValue(S, 59, 0);
    ssSetIWorkValue(S, 60, 0);
    ssSetIWorkValue(S, 61, 0);
    ssSetIWorkValue(S, 62, 0);
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
    
    int trial_type_index;
    int *trial_type_list;
    int trial_type;
    
    int gradation_index;
    int *gradation_list;
    int gradation;
    
    real_T ct[4];
    real_T ot1[4];     /* left outer target UL and LR coordinates */
    real_T ot2[4];     /* right outer target UL and LR coordinates */
    real_T ot1_type;   /* type of left outer target 0=invisible 1=red square 2=lightning bolt (?) */
    real_T ot2_type;   /* type of right outer target 0=invisible 1=red square 2=lightning bolt (?) */
    real_T *ot;
    real_T *ot_wrong;
    
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T elapsed_timer_time;
    int reset_block = 0;
        
    /* block initialization working variables */
    int tmp_trial_types[NUM_TYPES_PER_BLOCK];
    int tmp_gradations[16];
    int tmp_sort[NUM_TYPES_PER_BLOCK];
    int i, j, tmp;
    
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

    /* current trial type */
    IWorkVector = ssGetIWork(S);
    trial_type_index = IWorkVector[1];
    trial_type_list = IWorkVector + 3;
    trial_type = trial_type_list[trial_type_index];

    /* current gradation */
    gradation_index = IWorkVector[2];
    gradation_list = IWorkVector + 43;
    gradation = gradation_list[gradation_index];
    
    /* get elapsed time since last timer reset */
    elapsed_timer_time = (real_T)(ssGetT(S)) - ssGetRWorkValue(S, 0);
    
    /* get target bounds */
    ct[0] = -target_size/2;
    ct[1] = target_size/2;
    ct[2] = target_size/2;
    ct[3] = -target_size/2;

    ot1[0] = -target_distance - target_size/2; /* left outer target */
    ot1[1] = target_size/2;
    ot1[2] = -target_distance + target_size/2; 
    ot1[3] = -target_size/2;

    ot2[0] = target_distance - target_size/2; /* right outer target */
    ot2[1] = target_size/2;
    ot2[2] = target_distance + target_size/2; 
    ot2[3] = -target_size/2;   
    
    if (trial_type == TRIAL_TYPE_NO_STIM) {
        ot_wrong = ot1;
        ot = ot2;
    } else {
        ot_wrong = ot2;
        ot = ot1;
    }
    
    /*********************************
     * See if we have issued a reset *    no master reset implemented yet
     *********************************/
    /*
    if (param_master_reset != 0) {
        ssSetIWorkValue(S, 581, 0);
        ssSetIWorkValue(S, 582, 0);
        ssSetIWorkValue(S, 583, 0);
        state_r[0] = STATE_PRETRIAL;
        return;
    }
     */
    
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
            if (pct_test_trials != param_pct_test_trials || num_gradations != param_num_gradations) {
                pct_test_trials = param_pct_test_trials;
                num_gradations = param_num_gradations;
                reset_block = 1;
            }

            training_mode = param_training_mode;

            center_hold_l = param_center_hold_l;
            center_hold_h = param_center_hold_h;
            
            delay_l = param_delay_l;
            delay_h = param_delay_h;
            
            movement = param_movement;
            
            intertrial = param_intertrial;

            target_size = param_target_size;
            target_distance = param_target_distance;

            abort_timeout   = param_intertrial;    
            failure_timeout = param_intertrial; 
            reward_timeout  = param_intertrial;   
            incomplete_timeout = param_intertrial;
            
            /* If we do not have our trials initialized => new trials block */
            if (trial_type_index == NUM_TYPES_PER_BLOCK-1) {
                /* initilize our trial types */
                for (i=0; i<NUM_TYPES_PER_BLOCK-1; i++) {
                    tmp_sort[i] = rand();
                }
                
                j = 0;
                for (i=0; i < pct_test_trials / 0.1; i++) {
                    tmp_trial_types[j++] = TRIAL_TYPE_TEST;
                }
                
                for (i=0; i < (NUM_TYPES_PER_BLOCK - pct_test_trials / 0.1)/2; i++) {
                    tmp_trial_types[j++] = TRIAL_TYPE_STIM;
                }
                
                for (i=0; i < (NUM_TYPES_PER_BLOCK - pct_test_trials / 0.1)/2; i++) {
                    tmp_trial_types[j++] = TRIAL_TYPE_NO_STIM;
                }
                
                /* sort trial types */
                for (i=0; i<NUM_TYPES_PER_BLOCK-1; i++) {
                    for (j=0; j<NUM_TYPES_PER_BLOCK-1; j++) { 
                        if (tmp_sort[j] < tmp_sort[j+1]) {
                            tmp = tmp_sort[j];
                            tmp_sort[j] = tmp_sort[j+1];
                            tmp_sort[j+1] = tmp;
                            
                            tmp = tmp_trial_types[j];
                            tmp_trial_types[j] = tmp_trial_types[j+1];
                            tmp_trial_types[j+1] = tmp;
                        }
                    }
                }
                
                /* write them back */
                for (i=0; i<NUM_TYPES_PER_BLOCK; i++) {
					trial_type_list[i] = tmp_trial_types[i];
	            }
                
	            /* and reset the counter */
	            ssSetIWorkValue(S, 1, 0);
            } else {
	            /* just advance the counter */
	            trial_type_index++;
	            /* and write it back */
	            ssSetIWorkValue(S, 2, trial_type_index);
                trial_type = trial_type_list[trial_type_index];
	        }
            
            /* If we do not have our gradations initialized => new gradations block */
            if (gradation_index == num_gradations-1) {
                /* initilize our gradations */
                for (i=0; i<num_gradations-1; i++) {
                    tmp_gradations[i] = i+1;
                    tmp_sort[i] = rand();
                }
                
                /* sort gradations */
                for (i=0; i<num_gradations-1; i++) {
                    for (j=0; j<num_gradations-1; j++) { 
                        if (tmp_sort[j] < tmp_sort[j+1]) {
                            tmp = tmp_sort[j];
                            tmp_sort[j] = tmp_sort[j+1];
                            tmp_sort[j+1] = tmp;
                            
                            tmp = tmp_gradations[j];
                            tmp_gradations[j] = tmp_gradations[j+1];
                            tmp_gradations[j+1] = tmp;
                        }
                    }
                }
                
                /* write them back */
                for (i=0; i<num_gradations; i++) {
					gradation_list[i] = tmp_gradations[i];
	            }
                
	            /* and reset the counter */
	            ssSetIWorkValue(S, 2, 0);
            } else {
	            /* just advance the counter */
	            gradation_index++;
	            /* and write it back */
	            ssSetIWorkValue(S, 2, gradation_index);
                gradation = gradation_list[gradation_index];
	        }
		        
	        /* In all cases, we need to decide on the random timer durations */
	        if (center_hold_h == center_hold_l) {
	            center_hold = center_hold_h;
	        } else {
	            center_hold = center_hold_l + (center_hold_h - center_hold_l)*((double)rand())/((double)RAND_MAX);
	        }
	        if (delay_h == delay_l) {
	            delay = delay_h;
	        } else {
	            delay = delay_l + (delay_h - delay_l)*((double)rand())/((double)RAND_MAX);
	        }
	                        
	        /* and advance */
	        new_state = STATE_CT_ON;
	        state_changed();

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
                new_state = STATE_ABORT;
                reset_timer(); /* abort timeout */
                state_changed();
            } else if (elapsed_timer_time > center_hold) {
                new_state = STATE_STIM;
                reset_timer(); /* delay timer */
                state_changed();
            } 
            break;
        case STATE_STIM:
            /* stimulation */
            if (!cursorInTarget(cursor, ct)) {
                new_state = STATE_ABORT;
                reset_timer(); /* abort timeout */
                state_changed();
            } else if (elapsed_timer_time > delay) {
                new_state = STATE_MOVEMENT;
                reset_timer(); /* movement timer */
                state_changed();
            }
            break;
        case STATE_MOVEMENT:
            /* movement phase (go tone on entry) */
            if ( cursorInTarget(cursor, ot) || 
                 (cursorInTarget(cursor, ot_wrong) && trial_type == TRIAL_TYPE_TEST) )
            {
                new_state = STATE_REWARD;
                reset_timer(); /* reward timeout */
                state_changed();
            } else if (cursorInTarget(cursor, ot_wrong) && trial_type != TRIAL_TYPE_TEST && !training_mode) {
                new_state = STATE_FAIL;
                reset_timer(); /* failure timeout */
                state_changed();
            } else if (elapsed_timer_time > movement) {
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
    
    UNUSED_ARG(tid);
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
    /********************
     *  Initialization
     ********************/
    int i;
    
    int_T *IWorkVector; 
    
    int_T trial_type_index;
    int_T *trial_type_list;
    int_T trial_type;
    
    int_T gradation_index;
    int_T *gradation_list;
    int_T gradation;
    
    real_T ct[4];
    real_T ot1[4];     /* left outer target UL and LR coordinates */
    real_T ot2[4];     /* right outer target UL and LR coordinates */
    real_T ot1_type;   /* type of left outer target 0=invisible 1=red square 2=lightning bolt (?) */
    real_T ot2_type;   /* type of right outer target 0=invisible 1=red square 2=lightning bolt (?) */
    real_T *ot;
    real_T *ot_wrong;
    
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T force_in[2];
    
    /* allocate holders for outputs */
    real_T force_x, force_y, word, reward, tone_cnt, tone_id;
    real_T target_pos[10];
    real_T status[3];
    
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

    /* current trial type */
    IWorkVector = ssGetIWork(S);
    trial_type_index = IWorkVector[1];
    trial_type_list = IWorkVector + 3;
    trial_type = trial_type_list[trial_type_index];

    /* current gradation */
    gradation_index = IWorkVector[2];
    gradation_list = IWorkVector + 43;
    gradation = gradation_list[gradation_index];
        
    /* get current tone counter */
    tone_cnt = ssGetRWorkValue(S, 1);
    tone_id = ssGetRWorkValue(S, 2);
    
    /* get target bounds */
    ct[0] = -target_size/2;
    ct[1] = target_size/2;
    ct[2] = target_size/2;
    ct[3] = -target_size/2;

    ot1[0] = -target_distance - target_size/2; /* left outer target */
    ot1[1] = target_size/2;
    ot1[2] = -target_distance + target_size/2; 
    ot1[3] = -target_size/2;

    ot2[0] = target_distance - target_size/2; /* right outer target */
    ot2[1] = target_size/2;
    ot2[2] = target_distance + target_size/2; 
    ot2[3] = -target_size/2;   
    
    if (trial_type == TRIAL_TYPE_NO_STIM) {
        ot_wrong = ot1;
        ot = ot2;
    } else {
        ot_wrong = ot2;
        ot = ot1;
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
    force_x = force_in[0]; 
    force_y = force_in[1];

    /* status (1) */
    if (state == STATE_REWARD && new_state)
        ssSetIWorkValue(S,59, ssGetIWorkValue(S, 59)+1);
    if (state == STATE_FAIL && new_state)
        ssSetIWorkValue(S, 60, ssGetIWorkValue(S, 60)+1);
    if (state == STATE_ABORT && new_state)
        ssSetIWorkValue(S, 61, ssGetIWorkValue(S, 61)+1);
    if (state == STATE_INCOMPLETE && new_state)
        ssSetIWorkValue(S, 62, ssGetIWorkValue(S, 62)+1);
    
    status[0] = IWorkVector[1]; //state;
    status[1] = ssGetIWorkValue(S, 59); // num rewards
    status[2] = ssGetIWorkValue(S, 60); // num fails
    status[3] = ssGetIWorkValue(S, 61) + ssGetIWorkValue(S, 62); // num aborts and incompletes
    
    /* word (2) */
    if (new_state) {
        switch (state) {
            case STATE_PRETRIAL:
                word = WORD_START_TRIAL;
                break;
            case STATE_CT_ON:
                word = WORD_CT_ON;
                break;
            case STATE_STIM:
                if (trial_type == TRIAL_TYPE_STIM) {
                    word = WORD_STIM(0xF);
                } else if (trial_type == TRIAL_TYPE_NO_STIM) {
                    word = WORD_STIM(0x0);
                } else if (trial_type == TRIAL_TYPE_TEST) {
                    word = WORD_STIM(gradation);
                }
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
    } 
    
    /* target_pos (3) */
    
    /* start assuming no targets will be drawn */
    for (i = 0; i<10; i++)
        target_pos[i] = 0;
    
    if ( state == STATE_CT_ON || 
         state == STATE_CENTER_HOLD ||
         state == STATE_STIM)
    {
        /* center target on */
        target_pos[0] = 2;
        for (i=0; i<4; i++) {
           target_pos[i+1] = ct[i];
        }
    } else if (state == STATE_MOVEMENT) {
        /* outer target on */
        target_pos[0] = 2;
        for (i=0; i<4; i++) {
            target_pos[i+1] = ot[i];
        }
        if (!training_mode) {
            target_pos[5] = 2;
            for (i=0; i<4; i++) {
                target_pos[i+6] = ot_wrong[i];
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
    for (i=0; i<3; i++) 
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
