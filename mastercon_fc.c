/* mastercon_co.c
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

static real_T num_steps = 16;  /* number of steps of stim intensity */
#define param_num_steps mxGetScalar(ssGetSFcnParam(S,0))
static real_T pct_test_trials = 20; /* percent of test stim trials */
#define param_pct_test_trials mxGetScalar(ssGetSFcnParam(S,1))
static real_T training_mode = 0; /* true=show one outer target, false=show 2 */
#define param_training_mode mxGetScalar(ssGetSFcnParam(S,2))

static real_T num_trials_per_block = 160;      /* number of peripheral targets    CHECK!*/
#define param_num_trials_per_block ceil(100*2*param_num_steps/param_pct_test_trials)

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

/* Modes */
#define MODE_TRAINING 0
#define MODE_TESTING 1  

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
    num_steps = param_num_steps;
    pct_test_trials = param_pct_test_trials;
    training_mode = param_training_mode;
    num_trials_per_block = param_num_trials_per_block;

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
    ssSetNumRWork(S, 4);  /* 0: time of last timer reset 
                             1: tone counter (incremented each time a tone is played)
                             2: tone id
                             3: catch trial (1 for yes, 0 for no)
                           */
    ssSetNumPWork(S, 0);
    ssSetNumIWork(S, 584); /*    0: state_transition (true if state changed), 
                                 1: current target index,
                            [2-17]: target presentation sequence (block/catch mode) 
                           [2-579]: target presentation sequence (bump mode) 
			   			   [2-~162]: target presentation sequence (force choice mode)
						   [~163-~335]: stimulus gradation sequence
                               580: bump duration counter 
                               581: successes
                               582: failures
                               583: aborts */
    
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
    ssSetIWorkValue(S, 1, 1);
    /* ssSetIWorkValue(S, 1, (int)num_trials_per_block-1); */
    
    /* set the tone counter to zero */
    ssSetRWorkValue(S, 1, 0.0);
    
    /* set catch trial to zero (init only) */
    ssSetRWorkValue(S, 3, 0.0);
    
    /* set trial counters to zero */
    ssSetIWorkValue(S, 581, 0);
    ssSetIWorkValue(S, 582, 0);
    ssSetIWorkValue(S, 583, 0);
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
    int target_index;
    int *target_list;
	int *gradation_list;
    int target;
       /*int bump;*/
       /* real_T theta; */
    real_T ct[4];
	real_T ot[4];
	real_T ot_wrong[4];
    real_T ot1[4];     /* left outer target UL and LR coordinates */
    real_T ot2[4];     /* right outer target UL and LR coordinates */
    real_T ot1_type;   /* type of left outer target 0=invisible 1=red square 2=lightning bolt (?) */
    real_T ot2_type;   /* type of right outer target 0=invisible 1=red square 2=lightning bolt (?) */
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T elapsed_timer_time;
    int reset_block = 0;
        
    /* block initialization working variables */
    int tmp_tgts[256];
    int tmp_sort[256];
    int tmp_gradation[256];
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

    /* current target number */
    IWorkVector = ssGetIWork(S);
    target_index = IWorkVector[1];
    target_list = IWorkVector+2;
	gradation_list = IWorkVector + num_trials_per_block + 2;

    target = target_list[target_index];
	gradation = gradation_list[target_index];
    
    /* get elapsed time since last timer reset */
    elapsed_timer_time = (real_T)(ssGetT(S)) - ssGetRWorkValue(S, 0);
    
    /* get target bounds */
    /*theta = PI/2 - target*2*PI/num_trials_per_block;*/
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

	ot1_type = 0;
	ot2_type = 0;

    if (training_mode = MODE_TRAINING && target == 0) {  /* show left target */
	ot[0] = ot1[0];
	ot[1] = ot1[1];
	ot[2] = ot1[2];
	ot[3] = ot1[3];	
	ot_wrong[0] = ot2[0];
	ot_wrong[1] = ot2[1];
	ot_wrong[2] = ot2[2];
	ot_wrong[3] = ot2[3];	
	ot1_type = 2; 
	ot2_type = 0; 

    } else if (training_mode = MODE_TRAINING && target == 1) { /* show right target */
	ot[0] = ot2[0];
	ot[1] = ot2[1];
	ot[2] = ot2[2];
	ot[3] = ot2[3];
	ot_wrong[0] = ot1[0];
	ot_wrong[1] = ot1[1];
	ot_wrong[2] = ot1[2];
	ot_wrong[3] = ot1[3];	
	ot1_type = 0;
	ot2_type = 2;
    } else if (training_mode = MODE_TESTING && target == 0) {   /* show both targets in testing mode */
	ot[0] = ot1[0];
	ot[1] = ot1[1];
	ot[2] = ot1[2];
	ot[3] = ot1[3];
	ot_wrong[0] = ot2[0];
	ot_wrong[1] = ot2[1];
	ot_wrong[2] = ot2[2];
	ot_wrong[3] = ot2[3];
	ot1_type = 2;
	ot2_type = 2;
    } else if (training_mode = MODE_TESTING && target == 1) { /* show both targets */
	ot[0] = ot2[0];
	ot[1] = ot2[1];
	ot[2] = ot2[2];
	ot[3] = ot2[3];
	ot_wrong[0] = ot1[0];
	ot_wrong[1] = ot1[1];
	ot_wrong[2] = ot1[2];
	ot_wrong[3] = ot1[3];	
	ot1_type = 2;
	ot2_type = 2;
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
            if (num_trials_per_block != param_num_trials_per_block) {
                num_trials_per_block = param_num_trials_per_block;
                reset_block = 1;
            }

			num_steps = param_num_steps;
			pct_test_trials = param_pct_test_trials;
			training_mode = param_training_mode;
			num_trials_per_block = param_num_trials_per_block;

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
            
            /* see if mode has changed.  If so we need a reset. */
            if (training_mode != param_training_mode) {
                reset_block = 1;
                training_mode = param_training_mode;
            }

            /* if we do not have our targets initialized => new block */
            if (target_index == num_trials_per_block-1 || reset_block) {
                /* initialize the targets */
				if (training_mode == MODE_TRAINING){
					for (i=0; i<num_trials_per_block; i++){
						tmp_tgts[i] = i%2;
						tmp_sort[i] = rand();
						tmp_gradation[i] = num_steps;
						/*	tmp_gradation[i] = 1;
							tmp_gradation[i] = 0x0F;   /* stimulus is given at 100% */
					}
					
				}

				if (training_mode == MODE_TESTING){
					for (i=0; i<num_steps; i=i+2){
						tmp_tgts[i] = 0;     /* toggle between 0 and 1 */
						tmp_tgts[i+1] = 1; 
						tmp_gradation[i] = int(i%num_steps);   /* should ROUND!!! */
						tmp_gradation[i+1] = int(i%num_steps);
						/*
						tmp_gradation[i] = i%num_steps * 1/num_steps;  /* gradation has a number between 0 and 1 
						tmp_gradation[i+1] = i%num_steps * 1/num_steps;   */
						tmp_sort[i] = rand();
						tmp_sort[i+1] = rand();
					}

					for (i=num_steps; i<num_trials_per_block; i++) {   
						tmp_tgts[i] = i%2;
						tmp_sort[i] = rand();
						tmp_gradation[i] = num_steps;   /* stimulus is given at 100% for the rest of the trials */
					}
				}


				for (i=0; i<num_trials_per_block-1; i++) {
					for (j=0; j<num_trials_per_block-1; j++) {
					    if (tmp_sort[j] < tmp_sort[j+1]) {
					        tmp = tmp_sort[j];
					        tmp_sort[j] = tmp_sort[j+1];
					        tmp_sort[j+1] = tmp;
					        
					        tmp = tmp_tgts[j];
					        tmp_tgts[j] = tmp_tgts[j+1];
					        tmp_tgts[j+1] = tmp;

							tmp = tmp_gradation[j];
							tmp_gradation[j] = tmp_gradation[j+1];
							tmp_gradation[j+1] = tmp;
					    }
					}
				}
	            /* write them back */
	            for (i=0; i<num_trials_per_block; i++) {
	                target_list[i] = tmp_tgts[i];
					gradation_list[i] = tmp_gradation[i];
	            }
	            /* and reset the counter */
	            ssSetIWorkValue(S, 1, 0);
		        
	        } else {
	            /* just advance the counter */
	            target_index++;
	            /* and write it back */
	            ssSetIWorkValue(S, 1, target_index);
				target = target_list[target_index];
				gradation = gradation_list[target_index];
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
            if (cursorInTarget(cursor, ot) || (training_mode==MODE_TESTING && gradation!=num_steps && cursorInTarget(cursor,ot_wrong))) { /*reward in testing mode*/
                new_state = STATE_REWARD;
                reset_timer(); /* outer hold timer */
                state_changed();
            } else if (elapsed_timer_time > movement) {
                new_state = STATE_INCOMPLETE;
                reset_timer(); /* failure timeout */
                state_changed();
            } 
            break;
        case STATE_ABORT:
            /* abort */
            if (elapsed_timer_time > intertrial) {
                new_state = STATE_PRETRIAL;
                state_changed();
			}
            break;
        case STATE_FAIL:
            /* failure */
            if (elapsed_timer_time > intertrial) {
                new_state = STATE_PRETRIAL;
                state_changed();
            }
            break;
        case STATE_INCOMPLETE:
            /* incomplete */
            if (elapsed_timer_time > intertrial) {
                new_state = STATE_PRETRIAL;
                state_changed();
            }
            break;
        case STATE_REWARD:
            /* reward */
            if (elapsed_timer_time > intertrial) {
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
    int_T target_index;
    int_T *target_list;
	int_T *gradation_list;
    int target;
	int gradation;
    real_T ct[4];
    real_T ot[4];
	real_T ot1[4];
	real_T ot2[4];
    
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

    /* current target number */
    IWorkVector = ssGetIWork(S);
    target_index = IWorkVector[1];
    target_list = IWorkVector+2;  
	gradation_list = IWorkVector+num_trials_per_block+2;  
    target = target_list[target_index];

	training_mode = param_training_mode;
    
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

	if (training_mode = MODE_TRAINING && target == 0) {  /* show left target */
		ot[0] = ot1[0];
		ot[1] = ot1[1];
		ot[2] = ot1[2];
		ot[3] = ot1[3];	
		ot1_type = 2; 
		ot2_type = 0; 
	} else if (training_mode = MODE_TRAINING && target == 1) { /* show right target */
		ot[0] = ot2[0];
		ot[1] = ot2[1];
		ot[2] = ot2[2];
		ot[3] = ot2[3];	
		ot1_type = 0;
		ot2_type = 2;
    } else if (training_mode = MODE_TESTING && target == 0) {   /* show both targets in testing mode */
		ot[0] = ot1[0];
		ot[1] = ot1[1];
		ot[2] = ot1[2];
		ot[3] = ot1[3];
		ot1_type = 2;
		ot2_type = 2;
    } else if (training_mode = MODE_TESTING && target == 1) { /* show both targets */
		ot[0] = ot2[0];
		ot[1] = ot2[1];
		ot[2] = ot2[2];
		ot[3] = ot2[3];	
		ot1_type = 2;
		ot2_type = 2;
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
    
    /* force (0) *
    if (mode == MODE_BLOCK_CATCH) {
        if (get_catch_trial() && (
                state == STATE_CENTER_DELAY ||
                state == STATE_MOVEMENT ||
                state == STATE_OUTER_HOLD
            )) 
        {
            force_x = 0;
            force_y = 0;
        } else {
            force_x = force_in[0]; 
            force_y = force_in[1]; 
        }
    } else {
        /* mode == MODE_BUMP *
        /* see if we are in a bump *
        if (bump_duration_counter > 0) {
            /* yes, so decrement the counter and maintain the bump *
            bump_duration_counter--;
            if (bump_duration_counter == 0)
                bump_duration_counter = -1; // don't bump again
            theta = PI/2 - bump*2*PI/num_trials_per_block;
            force_x = force_in[0] + cos(theta)*bump_magnitude;
            force_y = force_in[1] + sin(theta)*bump_magnitude;
        } else if ( bump != -1 && 
                    bump_duration_counter != -1 && 
                    ( (state==STATE_MOVEMENT && sqrt(cursor[0]*cursor[0]+cursor[1]*cursor[1]) > target_radius / 2) || 
                       state==STATE_CENTER_HOLD_BUMP
                    )
                  ) 
        {
            /* initiating a new bump *
            bump_duration_counter = bump_duration;
            theta = PI/2 - bump*2*PI/num_trials_per_block;
            force_x = force_in[0] + cos(theta)*bump_magnitude;
            force_y = force_in[1] + sin(theta)*bump_magnitude;
        } else {
            force_x = force_in[0]; 
            force_y = force_in[1];
        }
    } */
    
    /* status (1) */
    if (state == STATE_REWARD && new_state)
        ssSetIWorkValue(S, 581, ssGetIWorkValue(S, 581)+1);
    if (state == STATE_ABORT && new_state)
        ssSetIWorkValue(S, 582, ssGetIWorkValue(S, 582)+1);
    if (state == STATE_FAIL && new_state)
        ssSetIWorkValue(S, 583, ssGetIWorkValue(S, 583)+1);
    
    status[0] = IWorkVector[1]; //state;
    status[1] = ssGetIWorkValue(S, 581); // num rewards
    status[2] = ssGetIWorkValue(S, 582); // num aborts
    status[3] = ssGetIWorkValue(S, 583); // num fails
    
    /* word (2) */
    if (new_state) {
        switch (state) {
            case STATE_PRETRIAL:
                word = WORD_START_TRIAL;
                break;
            case STATE_CT_ON:
                word = WORD_CT_ON;
                break;
            /*case STATE_CENTER_HOLD:
                word = WORD_HOLD;
                break;             CHECK! */
            case STATE_STIM:
                word = WORD_STIM(gradation);
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
    } 
    
    /* target_pos (3) */
    if ( state == STATE_CT_ON || 
         state == STATE_CENTER_HOLD)
    {
        /* center target on */
		target_pos[0] = 1;
        for (i=0; i<4; i++) {
            target_pos[i+1] = ct[i];
        }
    } 
    else 
    {
        /* center target off */
        target_pos[0] = 0;
        for (i=0; i<4; i++) {
            target_pos[i+1] = 0;
        }
    }
    
    if ( state == STATE_CENTER_HOLD ||
         state == STATE_MOVEMENT)
    {
        /* outer target on */
		target_pos[0] = ot1_type;
        for (i=0; i<4; i++) {
            target_pos[i+1] = ot1[i];
        }
		target_pos[5] = ot2_type;
        for (i=0; i<4; i++) {
            target_pos[i+6] = ot2[i];
        }
    } 
    else 
    {
        /* outer target off */
		target_pos[0] = 0;
        target_pos[5] = 0;
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
    /*ssSetIWorkValue(S, 580, bump_duration_counter);*/
    
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
