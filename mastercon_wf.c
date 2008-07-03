/* mastercon_wf.c
 
 * Master Control block for behavior: wrist-flexion
 */

#define S_FUNCTION_NAME mastercon_wf
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include <stdlib.h>
#include "simstruc.h"

#define TASK_WF 1
#include "words.h"
#include "random_macros.h"

#define PI (3.141592654)

/*
 * Tunable parameters
 */
static real_T num_targets = 8;      /* number of targets from which to select */
#define param_num_targets mxGetScalar(ssGetSFcnParam(S,0))

static real_T reach_time = 5;          /* Time to reach AND hold target*/
#define param_reach_time mxGetScalar(ssGetSFcnParam(S,1))
static real_T target_hold_time = .5;
#define param_target_hold_time mxGetScalar(ssGetSFcnParam(S,2))

static real_T center_hold_time = .5;			/* delay before movement */
#define param_center_hold_time mxGetScalar(ssGetSFcnParam(S,3))

#define param_intertrial mxGetScalar(ssGetSFcnParam(S,4))
static real_T abort_timeout   = 1.0;    /* delay after abort */
static real_T failure_timeout = 1.0;    /* delay after failure */
static real_T incomplete_timeout = 1.0; /* delay after incomplete */
static real_T reward_timeout  = 1.0;    /* delay after reward before starting next trial
                                         * This is NOT the reward pulse length */

static real_T center_x = 0;
#define param_center_x mxGetScalar(ssGetSFcnParam(S,5))
static real_T center_y = 0;
#define param_center_y mxGetScalar(ssGetSFcnParam(S,6))  
static real_T center_h = 2.0; 
#define param_center_h mxGetScalar(ssGetSFcnParam(S,7))
static real_T center_w = 4.0;
#define param_center_w mxGetScalar(ssGetSFcnParam(S,8))

static real_T tgt_view_delay = 0;
#define param_tgt_view_delay mxGetScalar(ssGetSFcnParam(S,9))
                           
static real_T succeed_to_continue = 0;
#define param_succeed_to_continue mxGetScalar(ssGetSFcnParam(S,10))

static real_T multiple_targets = 0;
#define param_multiple_targets mxGetScalar(ssGetSFcnParam(S,11))

static real_T MVC_routine = 0;
#define param_MVC_routine mxGetScalar(ssGetSFcnParam(S,12))

static real_T first_MVC_target = 0;
#define param_first_MVC_target mxGetScalar(ssGetSFcnParam(S,13))

static real_T master_reset = 0.0;
#define param_master_reset mxGetScalar(ssGetSFcnParam(S,14))

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_RECENTERING 1
#define STATE_CENTER_HOLD 2
#define STATE_MOVEMENT 3
#define STATE_TARGET_HOLD 4 
#define STATE_CONTINUE_MOVEMENT 5
#define STATE_CENTER_HOLD_WITH_TARGET 6
#define STATE_REWARD 82
#define STATE_ABORT 65
#define STATE_FAIL 70

#define TONE_GO 1
#define TONE_REWARD 2
#define TONE_ABORT 3


static void mdlCheckParameters(SimStruct *S)
{
  num_targets = param_num_targets;

  reach_time = param_reach_time;
  target_hold_time = param_target_hold_time;
  tgt_view_delay = param_tgt_view_delay;

  center_y = param_center_y;
  center_h = param_center_h;
  center_x = param_center_x;
  center_w = param_center_w;
  
  abort_timeout      = param_intertrial;
  failure_timeout    = param_intertrial;
  incomplete_timeout = param_intertrial;
  reward_timeout     = param_intertrial;
  
  succeed_to_continue = param_succeed_to_continue;
  multiple_targets = param_multiple_targets;
  MVC_routine = param_MVC_routine;
  first_MVC_target = param_first_MVC_target;
}

static void mdlInitializeSizes(SimStruct *S)
{
    int i;
    
    ssSetNumSFcnParams(S, 15); 
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
     *      input port 0: (position) of width 2 (horizontal and vertical cursor displacement)
     *      input port 1: (target) of width 4 (vertical displacement, height, horiz disp, width)
     */
    if (!ssSetNumInputPorts(S, 2)) return;
    ssSetInputPortWidth(S, 0, 2); /* cursor position*/
    ssSetInputPortWidth(S, 1, 4); /* target position */
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    
    /* 
     * Block has 7 output ports (reward, word, touch pad LED, gadget LED, gadget select, status, tone, target, target select, MVC Target) of widths:
     * 0: reward:         1
     * 1: word:           1
     * 2: status:         4 ( 1: state, 2: rewards, 3: aborts, 4: failures )
     * 3: tone:           2 ( 1: counter incemented for each new tone, 2: tone ID )     
     * 4: target: 10 ( target 1, 2: 
     *                  type, 
     *                  target UL corner x, 
     *                  target UL corner y,
     *                  target LR corner x, 
     *                  target LR corner y)
`    * 5: target select:  1
	 * 6: MVC Target:	  1  (1: X Pos_max)
     */
    if (!ssSetNumOutputPorts(S, 7)) return;
    ssSetOutputPortWidth(S, 0, 1);
    ssSetOutputPortWidth(S, 1, 1);
    ssSetOutputPortWidth(S, 2, 4);
    ssSetOutputPortWidth(S, 3, 2);
    ssSetOutputPortWidth(S, 4, 10);
    ssSetOutputPortWidth(S, 5, 1);
    ssSetOutputPortWidth(S, 6, 1);
    
    ssSetNumSampleTimes(S, 1);
    
    /* work buffers */
    ssSetNumRWork(S, 7);    /* 0: time of last timer reset
                               1: time of last target hold timer reset 
                               2: tone counter (incremented each time a tone is played)
                               3: tone id
                               4: time of last center hold timer reset
                               5: X value of the higher target reached (for MVC)
                               6: X value of the current MVC target
                               
                               
                           */
    ssSetNumPWork(S, 0);
    ssSetNumIWork(S, 22); /*  0: state_transition (true if state changed), 
                               1: current target index (in sequence),
                               2: successes
                               3: aborts
                               4: failures 
                          [5-20]: target_id list
                          	  21: success_flag
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
    int i;
    real_T *x0;
    
    /* initialize state to zero */
    x0 = ssGetRealDiscStates(S);
    *x0 = 0.0;
    
    /* notify that we just entered this state */
    ssSetIWorkValue(S, 0, 1);
    
    /* set target index to indicate that we need to begin a new block */
    ssSetIWorkValue(S, 1, (int)num_targets-1);
    
    /* set the tone counter to zero */
    ssSetRWorkValue(S, 2, 0.0);
    ssSetRWorkValue(S, 3, 0.0);
    
    /* set the mvc Target at 0 */
    ssSetRWorkValue(S, 5, 0.0);
    ssSetRWorkValue(S, 6, first_MVC_target);
    
    /* initialize targets at zero */
    for (i = 5 ; i<21 ; i++){
        ssSetIWorkValue(S, i, 0);
    }
    
    /* set trial counters to zero */
    ssSetIWorkValue(S, 2, 0);
    ssSetIWorkValue(S, 3, 0);
    ssSetIWorkValue(S, 4, 0);
    
    /* initialize success_flag at zero */
    ssSetIWorkValue(S, 21, 0);
    
    /* set reset counter to zero */
    master_reset = 0.0;
}

/* macro for setting state changed */
#define state_changed() (ssSetIWorkValue(S, 0, 1))
/* macros for resetting timers */
#define reset_timer() (ssSetRWorkValue(S, 0, (real_T)ssGetT(S)))
#define reset_target_hold_timer() (ssSetRWorkValue(S, 1, (real_T)ssGetT(S)))
#define reset_center_hold_timer() (ssSetRWorkValue(S, 4, (real_T)ssGetT(S)))
#define success_flag() (ssSetIWorkValue(S, 21, 1))

/* cursorInTarget
 * returns true (1) if the cursor is in the target and false (0) otherwise
 * cursor is specified as x, y = c[0], c[1]
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
    int j;    
    int *IWorkVector; 
    int target_index;
    int target_id;
    int *target_list;
    real_T target_x, target_y, target_h, target_w;
    real_T tgt[4];
    real_T center[4];
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T elapsed_timer_time;
    real_T elapsed_target_hold_time;
    real_T elapsed_center_hold_time;
    real_T success_flag;
    real_T current_MVC_target;
  
    
    int tmp_tgts[64];
    int tmp_i;
    double tmp_sort[64];
    double tmp_d;
    
    int reshuffle;
    
    /******************
     * Initialization *
     ******************/
    
    /* get current state */
    real_T *state_r = ssGetRealDiscStates(S);
    int state = (int)state_r[0];
    int new_state = state;
    ssSetIWorkValue(S, 0, 0); /* By default, clear the state-changed flag */
    
    /* current cursor location */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 0);
    cursor[0] = *uPtrs[0];
    cursor[1] = *uPtrs[1];
    
    /* Current target index*/
    target_index = ssGetIWorkValue(S, 1);
    target_id = ssGetIWorkValue(S, 5 + target_index);

    IWorkVector = ssGetIWork(S);
    target_list = IWorkVector+5;
    
    /* Success Flag */
    success_flag = ssGetIWorkValue(S, 21);
    
    /* Current Target Location */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 1);
    target_y = *uPtrs[0];
    target_h = *uPtrs[1];
    target_x = *uPtrs[2];
    target_w = *uPtrs[3];
    
    /* if we are in MVC routine mode, we may want to override the first target x value */
    current_MVC_target = ssGetRWorkValue(S, 5);
    if (MVC_routine && target_id ==0) {
		target_x = ssGetRWorkValue(S,6);
    }

    /* get target bounds */
    tgt[0] = target_x - target_w / 2.0;
    tgt[1] = target_y + target_h / 2.0;
    tgt[2] = target_x + target_w / 2.0;
    tgt[3] = target_y - target_h / 2.0;
    
    /* Current Center location */
    center_y = param_center_y;
    center_h = param_center_h;
    center_x = param_center_x;
	center_w = param_center_w;
    
    /* get center bounds */
   	center[0] = center_x - center_w / 2.0;
    center[1] = center_y + center_h / 2.0;
    center[2] = center_x + center_w / 2.0;
    center[3] = center_y - center_h / 2.0;
       
    
    /* get elapsed time since last timer reset */
    elapsed_timer_time = (real_T)(ssGetT(S)) - ssGetRWorkValue(S, 0);
    elapsed_target_hold_time = (real_T)(ssGetT(S)) - ssGetRWorkValue(S, 1);
    elapsed_center_hold_time = (real_T)(ssGetT(S)) - ssGetRWorkValue(S, 4);
    
    /*********************************
     * See if we have issued a reset *
     *********************************/
    if (param_master_reset > master_reset) {
        master_reset = param_master_reset;
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
            /* pretrial initialization */
            /* 
             * We should only be in this state for one cycle.
             * Initialize the trial and then advance to STATE_RECENTERING 
             */

            
            /* Update parameters */        
            reach_time = param_reach_time;
            tgt_view_delay = param_tgt_view_delay;
            target_hold_time = param_target_hold_time;

            center_hold_time = param_center_hold_time; 
            
            abort_timeout   = param_intertrial;    
            failure_timeout = param_intertrial;   
            reward_timeout  = param_intertrial;    
            
            succeed_to_continue = param_succeed_to_continue;
            multiple_targets = param_multiple_targets;
            MVC_routine = param_MVC_routine;

			/* To resuffle or not to reshuffle */           
            reshuffle = 0;

			//reshuffle if something has changed
            if (num_targets != param_num_targets ||
			succeed_to_continue != param_succeed_to_continue ||
			multiple_targets != param_multiple_targets) {

				num_targets = param_num_targets;
				succeed_to_continue = param_succeed_to_continue;
				multiple_targets = param_multiple_targets;
                reshuffle = 1;
            }

            //reshuffle every_new trial in this case
			if (multiple_targets) {
				reshuffle = 1;
			}

			// reshuffle by default if we reached the last target in the list, unless failure and idiot mode
			if (target_index == num_targets-1) {
				if (succeed_to_continue && success_flag == 0) {
					//we stay at the last target until success
					//so no reshuffling unless previously
					//set to 1 by previous conditions
				} else {
					reshuffle = 1;  
				}
			}
			
			/* see if we have to update MVC_Target */
			if (MVC_routine && target_id == 0){
				if (target_x > current_MVC_target && success_flag) {
					/* MVC Target reached! Increase it by 10% */					
					ssSetRWorkValue(S,5, target_x);
					ssSetRWorkValue(S, 6, target_x*1.1);
				} else {
					/* Failed to reach and hold MVC Target, decrease it by 5% */
					ssSetRWorkValue(S, 6, target_x*0.95);
				}
			}
			
            /* get current target or reshuffle at end of block */
			if (reshuffle) {
				// reshuffle
				j = 0;
				/* set up lists loop */
				for (i=0; i<num_targets; i++) {
					tmp_tgts[j] = i;
					tmp_sort[j++] = rand();
				}
				
				/* shuffle lists loop */
				for (i=0; i<num_targets-1; i++) {
					for (j=0; j<num_targets-1; j++) {
						if (tmp_sort[j] < tmp_sort[j+1]) {
							tmp_d = tmp_sort[j];
							tmp_sort[j] = tmp_sort[j+1];
							tmp_sort[j+1] = tmp_d;
							
							tmp_i = tmp_tgts[j];
							tmp_tgts[j] = tmp_tgts[j+1];
							tmp_tgts[j+1] = tmp_i;
						}
					}
				}
				
				/* write lists back to work buffer loop */
				for (i=0; i<=num_targets-1; i++) {
					target_list[i] = tmp_tgts[i];
					ssSetIWorkValue(S, i+5, target_list[i]);
				}
				
				/* and reset the counter */
				target_index = 0;
				ssSetIWorkValue(S, 1, target_index);
                
			} else if (succeed_to_continue) {
	            //    advance to next target only if previous success
                if (success_flag) ssSetIWorkValue(S, 1, ++target_index);
			} else {
				// default : advance to next target
	            ssSetIWorkValue(S, 1, ++target_index);
            }

            new_state = STATE_RECENTERING;
			ssSetIWorkValue(S, 21, 0);	// reset success flag
            state_changed();

            break;
        case STATE_RECENTERING:
            if (cursorInTarget(cursor, center)) {
                new_state = STATE_CENTER_HOLD;
                state_changed();
                reset_center_hold_timer();
                reset_timer();                
            }
            break;
        case STATE_CENTER_HOLD:
        	if (!cursorInTarget(cursor, center)) {
	        	new_state = STATE_RECENTERING;
	        	state_changed();
        	} else if ( elapsed_center_hold_time > center_hold_time) {
	        	new_state = STATE_MOVEMENT;
	        	state_changed();
	        	reset_timer();
        	} else if (elapsed_timer_time > tgt_view_delay) {
	        	new_state = STATE_CENTER_HOLD_WITH_TARGET;
	        	state_changed();
        	}
        	break;
        case STATE_CENTER_HOLD_WITH_TARGET:
        	if (!cursorInTarget(cursor, center)) {
	        	new_state = STATE_RECENTERING;
	        	state_changed();
        	} else if ( elapsed_center_hold_time > center_hold_time) {
	        	new_state = STATE_MOVEMENT;
	        	state_changed();
	        	reset_timer();
        	}
        	break;
        case STATE_MOVEMENT:
            if (elapsed_timer_time > reach_time) {
                new_state = STATE_FAIL;
                state_changed();
                reset_timer();
            } else if (cursorInTarget(cursor, tgt)) {
                new_state = STATE_TARGET_HOLD;
                state_changed();
                reset_target_hold_timer();
            }
            break;
        case STATE_TARGET_HOLD:
            if (!cursorInTarget(cursor, tgt)) {
                new_state = STATE_CONTINUE_MOVEMENT;
                state_changed();
            } else if (elapsed_target_hold_time > target_hold_time) {
				success_flag();
				/*next state depends on whether there are more targets */
				if (target_index == (int)num_targets-1 || multiple_targets == 0) {
					new_state = STATE_REWARD;
					state_changed();
					reset_timer();
				} else {
					/* more targets*/
					ssSetIWorkValue(S, 1, ++target_index);
					new_state = STATE_MOVEMENT;
					state_changed();
					reset_timer();
				}
            } else if (elapsed_timer_time > reach_time) {
	            new_state = STATE_FAIL;
	            state_changed();
	            reset_timer();
            }
            break;
		case STATE_CONTINUE_MOVEMENT:
            if (elapsed_timer_time > reach_time) {
                new_state = STATE_FAIL;
                state_changed();
                reset_timer();
            } else if (cursorInTarget(cursor, tgt)) {
                new_state = STATE_TARGET_HOLD;
                state_changed();
                reset_target_hold_timer();
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
        case STATE_REWARD:
            /* reward */
            if (elapsed_timer_time > reward_timeout) {
                new_state = STATE_PRETRIAL;
                state_changed();
                success_flag();
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

static void mdlOutputs(SimStruct *S, int_T tid)
{
    /********************
     *  Initialization
     ********************/
    int i;
    int *IWorkVector; 
    int target_index;
    int target_id;
    int *target_list;
    real_T target_x, target_y, target_h, target_w;
    real_T tgt[4];
    real_T center[4];
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T tone_cnt, tone_id;
    int new_state;
    
    /* holders for outputs */
    real_T reward, word, target_select, mvcTarget;
    real_T status[4];
    real_T target[10];
       
    /* pointers to output buffers */
    real_T *reward_p;
    real_T *word_p;
    real_T *status_p;
    real_T *tone_p;
    real_T *target_p;
    real_T *target_select_p;
    real_T *mvcTarget_p;
    
    /******************
     * Initialization *
     ******************/
    
    /* get current state */
    real_T *state_r = ssGetRealDiscStates(S);
    int state = (int)state_r[0];
    new_state = ssGetIWorkValue(S, 0);
    
    /* Current target/gadget index */
    target_index = ssGetIWorkValue(S, 1);
    target_id = ssGetIWorkValue(S, 5 + target_index);
    IWorkVector = ssGetIWork(S);
    target_list = IWorkVector+5;

    /* current cursor location */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 0);
    cursor[0] = *uPtrs[0];
	cursor[1] = *uPtrs[1];

    /* Current Target Location */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 1);
    target_y = *uPtrs[0];
    target_h = *uPtrs[1];
    target_x = *uPtrs[2];
    target_w = *uPtrs[3];
    /* if we are in MVC Routine, we may want to override the first target x value */
    if (MVC_routine && target_id == 0) {
	    target_x = ssGetRWorkValue(S,6);
    }

    /* get target bounds */
    tgt[0] = target_x - target_w / 2.0;
    tgt[1] = target_y + target_h / 2.0;
    tgt[2] = target_x + target_w / 2.0;
    tgt[3] = target_y - target_h / 2.0;
    
    /* get center bounds */
   	center[0] = center_x - center_w / 2.0;
    center[1] = center_y + center_h / 2.0;
    center[2] = center_x + center_w / 2.0;
    center[3] = center_y - center_h / 2.0;    

    /* tone counters */
    tone_cnt = ssGetRWorkValue(S, 2);
    tone_id  = ssGetRWorkValue(S, 3);
    
    /********************
     * Calculate outputs
     ********************/
    
    /* reward (0) */
    if (new_state && state == STATE_REWARD) {
        reward = 1.0;
    } else {
        reward = 0.0;
    }
    
    /* word (1) */
    if (new_state) {
        switch (state) {
            case STATE_PRETRIAL:
                word = WORD_START_TRIAL;
                break;
			case STATE_CENTER_HOLD_WITH_TARGET:
				word = WORD_OT_ON(target_id);
				break;
            case STATE_MOVEMENT:
                word = WORD_MOVEMENT_ONSET;
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
                word = 0.0;
        }
    } else {
        word = 0.0;
    }
    
    
    /* status (2) */
    if (state == STATE_REWARD && new_state)
        ssSetIWorkValue(S, 2, ssGetIWorkValue(S, 2)+1);
    if (state == STATE_ABORT && new_state)
        ssSetIWorkValue(S, 3, ssGetIWorkValue(S, 3)+1);
    if (state == STATE_FAIL && new_state)
        ssSetIWorkValue(S, 4, ssGetIWorkValue(S, 4)+1);
      
    status[0] = state;
    status[1] = ssGetIWorkValue(S,2); // num rewards
    status[2] = ssGetIWorkValue(S,3); // num aborts
    status[3] = ssGetIWorkValue(S,4); // num failures
    
    
    /* tone (3) */
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
    
    /* targets (4) */
    for (i=0; i<4; i++) {
        target[i+1] = tgt[i];
		target[i+6] = center[i];
    }
	
    switch (state) {
        case STATE_RECENTERING:
    	    /* target off */
		    target[0] = 0;
		    /* center red*/
		    target[5] = 1;
        break;
        case STATE_CENTER_HOLD:
		    /* target off */
		    target[0] = 0;
		    /* center green*/
		    target[5] = 3;
        break;
        case STATE_CENTER_HOLD_WITH_TARGET:
		    /* target white */
		    target[0] = 2;
		    /* center green*/
		    target[5] = 3;
	    break;
        case STATE_MOVEMENT:
	        /* target red */
	        target[0] = 1;
	        /* center off */
	        target[5] = 0;
        break;
        case STATE_CONTINUE_MOVEMENT:
	        /* target red */
	        target[0] = 1;
	        /* center off */
	        target[5] = 0;
        break;
        case STATE_TARGET_HOLD:
	        /* target green */
	        target[0] = 3;
	        /* center off */
	        target[5] = 0;
        break;
        default:
            /* target and center off */
	        target[0] = 0;
	        target[5] = 0;
    }   



     /* target_select (5) */
     target_select = target_id;
    
     /* MVC Target (6) */
     /* (higher target reached) */
    mvcTarget = ssGetRWorkValue(S, 5);
              
    
    
    /**********************************
     * Write outputs back to SimStruct
     **********************************/
 
     reward_p = ssGetOutputPortRealSignal(S,0);
     reward_p[0] = reward;
     
     word_p = ssGetOutputPortRealSignal(S,1);
     word_p[0] = word;
          
     status_p = ssGetOutputPortRealSignal(S,2);
     for (i=0; i<4; i++) 
         status_p[i] = (real_T)status[i];
    
     tone_p = ssGetOutputPortRealSignal(S,3);
     tone_p[0] = tone_cnt;
     tone_p[1] = tone_id;
     ssSetRWorkValue(S, 2, tone_cnt);
     ssSetRWorkValue(S, 3, tone_id);
     
     target_p = ssGetOutputPortRealSignal(S,4);
     for (i=0; i<10; i++) 
         target_p[i] = target[i];
     
     target_select_p = ssGetOutputPortRealSignal(S,5);
     target_select_p[0] = target_select;
     
     mvcTarget_p = ssGetOutputPortRealSignal(S,6);
     mvcTarget_p[0] = mvcTarget;
     
    UNUSED_ARG(tid);
}

static void mdlTerminate (SimStruct *S) { UNUSED_ARG(S); }

#ifdef MATLAB_MEX_FILE   /* Is this being compiled as a MEX-file? */
#include "simulink.c"    /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"     /* Code generation registration func */
#endif
