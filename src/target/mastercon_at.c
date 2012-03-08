#define S_FUNCTION_NAME mastercon_at
#define S_FUNCTION_LEVEL 2

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "simstruc.h"

#define TASK_AT 1
#include "words.h"
#include "random_macros.h"

#define PI (3.141592654)

/* 
 * Current Databurst version: 0
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
 * byte         0: uchar => number of bytes to be transmitted
 * byte         1: uchar => databurst version number (in this case one)
 * byte         2: uchar => model version major
 * byte         3: uchar => model version minor
 * bytes   4 to 5: short => model version micro
 * bytes   6 to 9: float => x offset (cm)
 * bytes 10 to 13: float => y offset (cm)
 * byte        14: uchar => trial type (0=visual, 1=proprioceptive)
 * bytes 15 to 18: float => bump magnitude (N)
 * bytes 19 to 22: float => bump angle (rad)
 * bytes 23 to 26: float => reward target angle (rad)
 * bytes 27 to 30: float => fail target angle (rad)
 * bytes 31 to 34: float => reward target size (cm)
 * bytes 35 to 38: float => fail target size (cm)
 * bytes 39 to 42: float => outer target delay after bump (ms, if -1 outer
 *                          targets visible during center hold)
 * byte        43: uchar => training mode (0=normal, 1=training 
 *                          only one target shown)
 * bytes 44 to 47: float => direction (rad) - angle between two outer targets
 */

typedef unsigned char byte;
#define DATABURST_VERSION (0x00) 

/*
 * Until we implement tunable parameters, these will act as defaults
 */

static real_T master_reset = 0.0;
#define param_master_reset mxGetScalar(ssGetSFcnParam(S,0))

/* Update counter */
static real_T master_update = 0.0;
#define param_master_update mxGetScalar(ssGetSFcnParam(S,1))

/* Timing parameters */
static real_T center_hold_l = 1.0;
#define param_center_hold_l mxGetScalar(ssGetSFcnParam(S,2))
static real_T center_hold_h = 2.0;
#define param_center_hold_h mxGetScalar(ssGetSFcnParam(S,3))
static real_T movement_time = 5.0;
#define param_movement_time mxGetScalar(ssGetSFcnParam(S,4))
static real_T reward_timeout = 1.0;
#define param_reward_timeout mxGetScalar(ssGetSFcnParam(S,5))
static real_T fail_timeout = 1.0;
#define param_fail_timeout mxGetScalar(ssGetSFcnParam(S,6))
static real_T abort_timeout = 1.0;
#define param_abort_timeout mxGetScalar(ssGetSFcnParam(S,7))
static real_T outer_target_delay = 0.0;
#define param_outer_target_delay mxGetScalar(ssGetSFcnParam(S,8))

/* Stimuli parameters */
static real_T percent_visual_trials = 50.0;
#define param_percent_visual_trials mxGetScalar(ssGetSFcnParam(S,9))
static int trial_block_size = 10;
#define param_trial_block_size (int)mxGetScalar(ssGetSFcnParam(S,10))
static int staircase = 1;
#define param_staircase (int)mxGetScalar(ssGetSFcnParam(S,11))
static real_T performance_objective = 0.7;
#define param_performance_objective mxGetScalar(ssGetSFcnParam(S,12))
static int staircase_length = 10;
#define param_staircase_length (int)mxGetScalar(ssGetSFcnParam(S,13))
static real_T visual_start_ratio_1 = 0.5;
#define param_visual_start_ratio_1 mxGetScalar(ssGetSFcnParam(S,14))
static real_T visual_start_ratio_2 = 1.5;
#define param_visual_start_ratio_2 mxGetScalar(ssGetSFcnParam(S,15))
static real_T visual_start_step_size = 0.05;
#define param_visual_start_step_size mxGetScalar(ssGetSFcnParam(S,16))
static real_T proprio_start_angle_1 = 0.2;
#define param_proprio_start_angle_1 mxGetScalar(ssGetSFcnParam(S,17))
static real_T proprio_start_angle_2 = 1;
#define param_proprio_start_angle_2 mxGetScalar(ssGetSFcnParam(S,18))
static real_T proprio_start_step_size = 0.05;
#define param_proprio_start_step_size mxGetScalar(ssGetSFcnParam(S,19))
static real_T visual_target_min_ratio = 0.8;
#define param_visual_target_min_ratio mxGetScalar(ssGetSFcnParam(S,20))
static real_T visual_target_max_ratio = 1.2;
#define param_visual_target_max_ratio mxGetScalar(ssGetSFcnParam(S,21))
static int visual_num_steps = 5;
#define param_visual_num_steps (int)mxGetScalar(ssGetSFcnParam(S,22))
static real_T proprio_target_min_angle = 0.5;
#define param_proprio_target_min_angle mxGetScalar(ssGetSFcnParam(S,23))
static real_T proprio_target_max_angle = 1.0;
#define param_proprio_target_max_angle mxGetScalar(ssGetSFcnParam(S,24))
static int proprio_num_steps = 5;
#define param_proprio_num_steps (int)mxGetScalar(ssGetSFcnParam(S,25))

/* Bump parameters */
static real_T bump_mag_min = 0.01;
#define param_bump_mag_min mxGetScalar(ssGetSFcnParam(S,26))
static real_T bump_mag_max = 0.03;
#define param_bump_mag_max mxGetScalar(ssGetSFcnParam(S,27))
static int num_bump_magnitudes = 3;
#define param_num_bump_magnitudes (int)mxGetScalar(ssGetSFcnParam(S,28))
static real_T bump_duration = 125;
#define param_bump_duration mxGetScalar(ssGetSFcnParam(S,29))
static int num_directions = 4;
#define param_num_directions (int)mxGetScalar(ssGetSFcnParam(S,30))
static real_T first_bump_direction = 0.0;
#define param_first_bump_direction mxGetScalar(ssGetSFcnParam(S,31))

/* Reward parameters */
static real_T min_reward = 0.1;
#define param_min_reward mxGetScalar(ssGetSFcnParam(S,32))
static real_T max_reward = 0.3;
#define param_max_reward mxGetScalar(ssGetSFcnParam(S,33))

/* Target parameters */
static real_T target_size = 3.0;
#define param_target_size mxGetScalar(ssGetSFcnParam(S,34))
static real_T target_radius = 10.0;
#define param_target_radius mxGetScalar(ssGetSFcnParam(S,35))
static real_T blocking_window_radius = 0.0;
#define param_blocking_window_radius mxGetScalar(ssGetSFcnParam(S,36))
static int visual_target_color = 1;
#define param_visual_target_color (int)mxGetScalar(ssGetSFcnParam(S,37))
static int proprio_target_color = 2;
#define param_proprio_target_color (int)mxGetScalar(ssGetSFcnParam(S,38))
static int return_center_target = 0;
#define param_return_center_target (int)mxGetScalar(ssGetSFcnParam(S,39))
static real_T percent_training_trials = 0.0;
#define param_percent_training_trials mxGetScalar(ssGetSFcnParam(S,40))

/*
 * State IDs
 */
#define STATE_PRETRIAL 0
#define STATE_CENTER_TARGET_ON 1
#define STATE_CENTER_HOLD 2
#define STATE_BUMP 3
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

/* 
 * RWorkVector Indexes
 */
#define rWorkBumpDirection 4
#define rWorkBumpMagnitude 5
#define rWorkMasterUpdateCounter 6
#define rWorkMovementDuration 7
#define rWorkTargetSeparation 8
#define rWorkTargetSizeRatio 9
#define rWorkProprioStairAngles 10
// #define rWorkProprioStair2Angles 30
#define rWorkVisualStairRatios 30
// #define rWorkVisualStair2Ratios 70
#define rWorkRewardTargetDirection 50
#define rWorkFailTargetDirection 51
#define rWorkRewardTargetSize 52
#define rWorkFailTargetSize 53
#define rWorkDirection 54

/*
 * IWorkVector Indexes
 */
#define iWorkRewards 1
#define iWorkFailures 2
#define iWorkAborts 3
#define iWorkIncompletes 4
#define iWorkTrainingMode 5
#define iWorkProprioStairCounter 6
// #define iWorkProprioStair2Counter 7
#define iWorkVisualStairCounter 7
// #define iWorkVisualStair2Counter 9
#define iWorkProprioStairResponses 8
// #define iWorkProprioStair2Responses 30
#define iWorkVisualStairResponses 28
// #define iWorkVisualStair2Responses 70
#define iWorkDataburstCounter 48
#define iWorkBumpDurationCounter 49
#define iWorkBumpStep 50
#define iWorkTestStep 51
#define iWorkTrialType 52
#define iWorkBlockCount 53

static void mdlCheckParameters(SimStruct *S)
{
    center_hold_l = param_center_hold_l;
    center_hold_h = param_center_hold_h;
    movement_time = param_movement_time;
    reward_timeout = param_reward_timeout;
    fail_timeout = param_fail_timeout;
    abort_timeout = param_abort_timeout;
    outer_target_delay = param_outer_target_delay;
    
    percent_visual_trials = param_percent_visual_trials;
    trial_block_size = param_trial_block_size;
    staircase = param_staircase;
    performance_objective = param_performance_objective;
    staircase_length = param_staircase_length;
    visual_start_ratio_1 = param_visual_start_ratio_1; 
    visual_start_ratio_2 = param_visual_start_ratio_2; 
    visual_start_step_size = param_visual_start_step_size; 
    proprio_start_angle_1 = param_proprio_start_angle_1; 
    proprio_start_angle_2 = param_proprio_start_angle_2;
    proprio_start_step_size = param_proprio_start_step_size; 
    visual_target_min_ratio = param_visual_target_min_ratio; 
    visual_target_max_ratio = param_visual_target_max_ratio; 
    visual_num_steps = param_visual_num_steps;
    proprio_target_min_angle = param_proprio_target_min_angle;
    proprio_target_max_angle = param_proprio_target_max_angle;
    proprio_num_steps = param_proprio_num_steps;
    
    bump_mag_min = param_bump_mag_min;
    bump_mag_max = param_bump_mag_max;
    num_bump_magnitudes = param_num_bump_magnitudes;
    bump_duration = param_bump_duration;
    num_directions = param_num_directions;
    first_bump_direction = param_first_bump_direction;
    
    min_reward = param_min_reward; 
    max_reward = param_max_reward; 
    
    target_size = param_target_size; 
    target_radius = param_target_radius; 
    blocking_window_radius = param_blocking_window_radius;
    visual_target_color = param_visual_target_color; 
    proprio_target_color = param_proprio_target_color; 
    return_center_target = param_return_center_target;
    percent_training_trials = param_percent_training_trials;
}
    
static void mdlInitializeSizes(SimStruct *S)
{
    int i;
    
    ssSetNumSFcnParams(S, 41);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* parameter number mismatch */
    }
    for (i=0; i<ssGetNumSFcnParams(S); i++)
        ssSetSFcnParamTunable(S, i, 1);
    mdlCheckParameters(S);
    
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 1);
    
    /*
     * Block has 5 input ports
     *      input port 0: (position) of width 2 (x, y)
	 *      input port 1: (position offsets) of width 2 (x, y)
     *      input port 2: (force) of width 2 (x, y)
     *      input port 3: (catch force) of width 2 (x,y) NOT USED
     */
    if (!ssSetNumInputPorts(S, 4)) return;
    ssSetInputPortWidth(S, 0, 2);
    ssSetInputPortWidth(S, 1, 2);
    ssSetInputPortWidth(S, 2, 2);
	ssSetInputPortWidth(S, 3, 2);
    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortDirectFeedThrough(S, 3, 1);
    
    /* 
     * Block has 8 output ports (force, status, word, targets, reward, tone, version, pos) of widths:
     *  force: 2
     *  status: 5 ( block counter, successes, aborts, failures, incompletes )
     *  word:  1 (8 bits)
     *  target: 45 ( targets 1:9 (only 3 implemented): 
     *                  on/off, 
     *                  target UL corner x, 
     *                  target UL corner y,
     *                  target LR corner x, 
     *                  target LR corner y)
     *  reward: 1
     *  reward pulse duration: 1
     *  tone: 2     ( 1: counter incemented for each new tone, 2: tone ID )
     *  version: 1 ( the cvs revision of the current .c file )
     *  pos: 2 (x and y position of the cursor)
     */
    if (!ssSetNumOutputPorts(S, 9)) return;
    ssSetOutputPortWidth(S, 0, 2);   /* force   */
    ssSetOutputPortWidth(S, 1, 5);   /* status  */
    ssSetOutputPortWidth(S, 2, 1);   /* word    */
    ssSetOutputPortWidth(S, 3, 45);  /* target  */
    ssSetOutputPortWidth(S, 4, 1);   /* reward  */
    ssSetOutputPortWidth(S, 5, 1);   /* reward pulse duration */
    ssSetOutputPortWidth(S, 6, 2);   /* tone    */
    ssSetOutputPortWidth(S, 7, 4);   /* version */
    ssSetOutputPortWidth(S, 8, 2);   /* pos     */
    
    ssSetNumSampleTimes(S, 1);
    
    /* work buffers */
    ssSetNumRWork(S, 55);  /* 0: time of last timer reset 
                             1: tone counter (incremented each time a tone is played)
                             2: tone id
							 3: mastercon version
                             4: bump direction
                             5: bump magnitude   
                             6: master update counter 
                             7: duration of movement (for calculating reward length)
                             8: target separation
                             9: target size difference
                             10-29: proprioceptive staircase 1 bumps                             
                             30-49: visual staircase 1 ratios
                             50: reward target direction
                             51: fail target direction
                             52: reward target size
                             53: fail target size
                             54: direction (angle halfway between RT and FT)
                           */
    
    ssSetNumPWork(S, 1);   /* 0: pointer to databurst array
                           */
    
    ssSetNumIWork(S, 53);     /* 0: state_transition (true if state changed), 
                                1: successes
                                2: failures
                                3: aborts
                                4: incompletes   
                                5: training mode 
                                6: proprioceptive staircase counter                                
                                7: visual staircase counter                                
                                8-27: proprioceptive staircase responses                                                        
                                28-47: visual staircase responses                                
                                48: databurst counter
                                49: bump duration counter
                                50: bump step
                                51: test step (target separation for proprio trials or
                                    target size ratio for visual trials)
                                52: trial block count
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
    int i;
    
    /* initialize state to zero */
    x0 = ssGetRealDiscStates(S);
    *x0 = 0.0;
    
    /* notify that we just entered this state */
    ssSetIWorkValue(S, 0, 1);
       
    /* set the tone counter to zero */
    ssSetRWorkValue(S, 1, 0.0);
        
    /* set trial counters to zero */
    ssSetIWorkValue(S, iWorkRewards, 0);
    ssSetIWorkValue(S, iWorkFailures, 0);
    ssSetIWorkValue(S, iWorkAborts, 0);
    ssSetIWorkValue(S, iWorkIncompletes, 0);
    
    /* setup databurst */
    databurst = malloc(256);
    ssSetPWorkValue(S, 0, databurst);
    ssSetIWorkValue(S, iWorkDataburstCounter, 0);
    
    /* set staircase counters to zero*/
    ssSetIWorkValue(S,iWorkProprioStairCounter,0);    
    ssSetIWorkValue(S,iWorkVisualStairCounter,0);
    
    /* set the initial last update time to 0 */
    ssSetRWorkValue(S,rWorkMasterUpdateCounter,0.0); 
    
    /* set duration of movement to zero */
    ssSetRWorkValue(S,rWorkMovementDuration,0);
    
    /* initialize staircases (randomly?) */
    for (i=0; i<20; i++){
        ssSetRWorkValue(S,rWorkProprioStairAngles+i,UNI);
        ssSetRWorkValue(S,rWorkVisualStairRatios+i,0.5+UNI);
        ssSetIWorkValue(S,iWorkProprioStairResponses+i, UNI>0.5 ? 1:0);
        ssSetIWorkValue(S,iWorkVisualStairResponses+i, UNI>0.5 ? 1:0);
    }    
    
    ssSetRWorkValue(S,iWorkRewardTargetSize,3);
    ssSetRWorkValue(S,iWorkFailTargetSize,2);
    ssSetRWorkValue(S,rWorkRewardTargetAngle,0);
    ssSetRWorkValue(S,rWorkFailTargetAngle,PI);
    
    ssSetRWorkValue(S,rWorkBumpMagnitude,0);
    ssSetRWorkValue(S,rWorkBumpDirection,0);
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
    int i;
    int j;
    
    real_T ct[4];
    real_T rt[4];     /* reward target UL and LR coordinates */
    real_T ft[4];     /* fail target UL and LR coordinates */
    real_T direction;
    real_T reward_target_side;
    real_T previous_visual_stair_ratio;
    real_T new_visual_stair_ratio;
    real_T previous_proprio_stair_angle;
    real_T new_proprio_stair_angle;
    int nshift
    
    InputRealPtrsType uPtrs;
    real_T cursor[2];
    real_T elapsed_timer_time;
    int reset_block = 0;
    
    /* Trial parameters from IWorkVector*/
    int trial_type; /* 0=visual, 1=proprioceptive */
    int test_step;
    int temp_int;
    int training_mode;
    int proprio_stair_counter;
    int visual_stair_counter;
    int proprio_stair_responses[20];
    int visual_stair_responses[20];
    int trial_block_count;

    /* from RWorkVector */
    real_T bump_magnitude;
    real_T bump_direction;
    real_T reward_target_angle;
    real_T fail_target_angle;
    real_T reward_target_size;
    real_T fail_target_size;
    real_T target_size_ratio;
    real_T target_separation;
    real_T proprio_stair_angles[20];
    real_T visual_stair_ratios[20];
    
    /* databurst variables */
    byte *databurst;
	float *databurst_offsets;
    byte *databurst_trial_type;
    float *databurst_bump_mag;
    float *databurst_bump_angle;
    float *databurst_reward_target_angle;
    float *databurst_fail_target_angle;
    float *databurst_reward_target_size;
    float *databurst_fail_target_size;
    float *databurst_outer_target_delay;
    float *databurst_direction;
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
    
    if ( param_master_update > master_update ) {
        master_update = param_master_update;
        ssSetRWorkValue(S, 6, (real_T)ssGetT(S));
    }
    
    /* Read staircase data */
    for (i=0 ; i<20 ; i++) {
        proprio_stair_responses[i] = ssGetIWorkValue(S,iWorkProprioStairResponses+i);
        visual_stair_responses[i] = ssGetIWorkValue(S,iWorkVisualStairResponses+i);
    
        proprio_stair_angles[i] = ssGetRWorkValue(S,rWorkProprioStairAngles+i);
        visual_stair_ratios[i] = ssGetRWorkValue(S,rWorkVisualStairRatios+i);
    }
    
    proprio_stair_counter = ssGetIWorkValue(S,iWorkProprioStairCounter);
    visual_stair_counter = ssGetIWorkValue(S,iWorkVisualStairCounter);
    
    reward_target_size = ssGetRWorkValue(S,rWorkRewardTargetSize);
    fail_target_size = ssGetRWorkValue(S,rWorkFailTargetSize);
    reward_target_angle = ssGetRWorkValue(S,rWorkRewardTargetAngle);
    fail_target_angle = ssGetRWorkValue(S,rWorkFailTargetAngle);
    
    /* get elapsed time since last timer reset */
    elapsed_timer_time = (real_T)(ssGetT(S)) - ssGetRWorkValue(S, 0);
    
    /* get target bounds */
    ct[0] = -target_size/2;
    ct[1] = target_size/2;
    ct[2] = target_size/2;
    ct[3] = -target_size/2;
       
    rt[0] = target_radius*cos(reward_target_angle) - reward_target_size/2; /* reward target */
    rt[1] = target_radius*sin(reward_target_angle) + reward_target_size/2;
    rt[2] = target_radius*cos(reward_target_angle) + reward_target_size/2;
    rt[3] = target_radius*sin(reward_target_angle) - reward_target_size/2;

    ft[0] = target_radius*cos(fail_target_angle) - fail_target_size/2; /* reward target */
    ft[1] = target_radius*sin(fail_target_angle) + fail_target_size/2;
    ft[2] = target_radius*cos(fail_target_angle) + fail_target_size/2;
    ft[3] = target_radius*sin(fail_target_angle) - fail_target_size/2;
    
    /* databurst pointers */
    databurst_counter = ssGetIWorkValue(S,iWorkDataburstCounter);
    databurst = ssGetPWorkValue(S,0);
    databurst_offsets = (float *)(databurst + 6);
    databurst_trial_type = (int *)(databurst_offsets + 2);
    databurst_bump_mag = (float *)(databurst_trial_type + 1);
    databurst_bump_angle = (float *)(databurst_bump_mag + 1);
    databurst_reward_target_angle = (float *)(databurst_bump_angle + 1);
    databurst_fail_target_angle = (float *)(databurst_reward_target_angle + 1);
    databurst_reward_target_size = (float *)(databurst_fail_target_angle + 1);
    databurst_fail_target_size = (float *)(databurst_reward_target_size + 1);
    databurst_outer_target_delay = (float *)(databurst_fail_target_size + 1);
    databurst_direction = (float *)(databurst_outer_target_delay + 1);
    
     /*********************************
     * See if we have issued a reset *  
     *********************************/
    if (param_master_reset != master_reset) {
        master_reset = param_master_reset;
        ssSetIWorkValue(S, iWorkRewards, 0);
        ssSetIWorkValue(S, iWorkFailuress, 0);
        ssSetIWorkValue(S, iWorkAborts, 0);
        ssSetIWorkValue(S, iWorkIncompletes, 0);
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
            center_hold_l = param_center_hold_l;
            center_hold_h = param_center_hold_h;
            movement_time = param_movement_time;
            reward_timeout = param_reward_timeout;
            fail_timeout = param_fail_timeout;
            abort_timeout = param_abort_timeout;
            outer_target_delay = param_outer_target_delay;

            percent_visual_trials = param_percent_visual_trials;
            trial_block_size = param_trial_block_size;
            staircase = param_staircase;
            performance_objective = param_performance_objective;
            staircase_length = param_staircase_length;
            visual_start_ratio_1 = param_visual_start_ratio_1; 
            visual_start_ratio_2 = param_visual_start_ratio_2; 
            visual_start_step_size = param_visual_start_step_size; 
            proprio_start_angle_1 = param_proprio_start_angle_1; 
            proprio_start_angle_2 = param_proprio_start_angle_2;
            proprio_start_step_size = param_proprio_start_step_size; 
            visual_target_min_ratio = param_visual_target_min_ratio; 
            visual_target_max_ratio = param_visual_target_max_ratio; 
            visual_num_steps = param_visual_num_steps;
            proprio_target_min_angle = param_proprio_target_min_angle;
            proprio_target_max_angle = param_proprio_target_max_angle;
            proprio_num_steps = param_proprio_num_steps;

            bump_mag_min = param_bump_mag_min;
            bump_mag_max = param_bump_mag_max;
            num_bump_magnitudes = param_num_bump_magnitudes;
            bump_duration = param_bump_duration;
            num_directions = param_num_directions;
            first_bump_direction = param_first_bump_direction;

            min_reward = param_min_reward; 
            max_reward = param_max_reward; 

            target_size = param_target_size; 
            target_radius = param_target_radius; 
            blocking_window_radius = param_blocking_window_radius;
            visual_target_color = param_visual_target_color; 
            proprio_target_color = param_proprio_target_color; 
            return_center_target = param_return_center_target;
            percent_training_trials = param_percent_training_trials; 
             
            /* decide if it is a training trial */ 
            training_mode = (100*UNI<percent_training_trials) ? 1 : 0;
            ssSetIWorkValue(S,iWorkTrainingMode,training_mode); 
            
            /* decide if it is a visual trial */
            trial_type = (100*UNI<percent_visual_trials) ? 1 : 0;
            ssSetIWorkValue(S,iWorkTrialType,trial_type); 
            
            /* pick a random bump magnitude */
            temp_int = (int)(UNI*num_bump_magnitudes);               
            bump_magnitude = bump_mag_min + ((float)temp_int)*(bump_mag_max-bump_mag_min)/((float)num_bump_magnitudes-1);
            ssSetRWorkValue(S,rWorkBumpMagnitude,bump_magnitude);
            ssSetIWorkValue(S,iWorkBumpStep,temp_int);
            
            /* Pick target directions */
            if (num_directions < 1 ) {
                direction = UNI*2*pi;
            } else {
                direction = (float)((int)(UNI*num_directions))*2*pi/num_directions + first_bump_direction;
            }                        
            reward_target_side = 2*(UNI>0.5)-1;  
                    
            /* Visual trials */            
            if ( trial_type == 0 ){
                bump_direction = direction+(2*(UNI>0.5)-1)*target_separation; /* Randomly selected bump direction */
                if (staircase){    
                    if (visual_stair_counter>0){
                        previous_visual_stair_ratio = visual_stair_ratios[visual_stair_counter-1];
                    } else {
                        previous_visual_stair_ratio = visual_stair_ratios[19];
                    }
                    /* ADD STAIRCASE CODE HERE
                        nshift = 0;
                        for (i=1;i<20;i++)
                            visual_stair_responses[i]-visual_stair_responses[i-1]
                     *
                     * new_visual_stair_ratio;
                    */
                
                    visual_stair_counter++;
                    if (visual_stair_counter>19)
                        visual_stair_counter = 0;                    
                } else {
                    temp_int = (int)(UNI*visual_num_steps);
                    new_visual_stair_ratio = visual_target_min_ratio + ((float)temp_int)*(visual_target_max_ratio-visual_target_min_ratio)/((float)visual_num_steps-1);                    
                }
                if (new_visual_stair_ratio > 1) {
                        reward_target_size = target_size*new_visual_stair_ratio;
                        fail_target_size = target_size;
                } else {
                        reward_target_size = target_size;
                        fail_target_size = target_size*new_visual_stair_ratio;
                }    
            }
                
                
                
                
                
                
                
                
                
             