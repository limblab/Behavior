/* $Id$
 *
 * defines word codes for center out and random walk tasks.
 *
 * word 0 is reserved and has the meaning, "no word this cycle."
 */

#ifndef WORDS_CO_H
#define WORDS_CO_H

/*********** DO NOT EDIT IN THE REGION ***********************/
/* 
 * MAJOR and/or MINOR version numbers should be updated on every new behavior 
 * release.
 *
 * MICRO and BUILD versions are set from update_version.pl, which is 
 * called by the build script.  Do not update them by hand, and do not edit 
 */
#define BEHAVIOR_VERSION_MAJOR 1
#define BEHAVIOR_VERSION_MINOR 5
#define BEHAVIOR_VERSION_MICRO 224 
#define BEHAVIOR_VERSION_BUILD 100

#ifndef __BUILD_UPDATED__
#error This project must be built from the build script. 
#endif
/************ END OF AUTOMATICALLY UPDATED REGION *************/

/* task specific setup */
#if TASK_CO
#define WORD_TASK_CODE 0x01
#elif TASK_RW
#define WORD_TASK_CODE 0x02
#elif TASK_FC
#define WORD_TASK_CODE 0x03
/* 0x04 and 0x05 are reserved for the bump-stim task. */
#elif TASK_MG
#define WORD_TASK_CODE 0x06
#elif TASK_WF
#define WORD_TASK_CODE 0x07
#elif TASK_UC
#define WORD_TASK_CODE 0x08
#elif TASK_BD
#define WORD_TASK_CODE 0x09
#endif

/* trial start */
#define WORD_START_TRIAL_GENERIC 0x10
#define WORD_START_TRIAL (WORD_START_TRIAL_GENERIC | WORD_TASK_CODE)

#define WORD_START_FORWARD_TRIAL 0x14
#define WORD_START_REVERSE_TRIAL 0x15

/* trial complete */
#define WORD_END_TRIAL 0x20

#define WORD_REWARD_END_CODE 0x00
#define WORD_REWARD ( WORD_END_TRIAL | WORD_REWARD_END_CODE )

#define WORD_ABORT_END_CODE 0x01
#define WORD_ABORT ( WORD_END_TRIAL | WORD_ABORT_END_CODE )

#define WORD_FAIL_END_CODE 0x02
#define WORD_FAIL ( WORD_END_TRIAL | WORD_FAIL_END_CODE )

#define WORD_INCOMPLETE_END_CODE 0x03
#define WORD_INCOMPLETE ( WORD_END_TRIAL | WORD_FAIL_END_CODE )

/* 
 * intra-trial events 
 */
 
/* center target on */
#define WORD_CT_ON 0x30
#define WORD_ORIGIN_TARGET_ON 0x30
#define WORD_HAND_ON_TOUCH_PAD 0x30

/* go cue */
#define WORD_GO_CUE 0x31

/* catch trial go cue (random walk, center-out, and wrist flexion modes) */
#define WORD_CATCH  0x32

/* outer target (t) on */
#define WORD_OT_ON(t) ( 0x40 | (t) )
#define WORD_DESTINATION_TARGET_ON 0x40
#define WORD_GADGET_ON(g) ( 0x40 | (g) )

/* The meaning of d in the WORD_BUMP macro depends on context.
 * In CO: d is the direction of the bump, where the direction is 
 *		  equivalent to a target number and the bump is in the 
 *        same direction as target d is from the origin.
 *
 * In BS: d is a 4-bit two's-complement value between -7 and 7 
 *		  indicated the direction and magnitude of the bump.
 *		  0 indicates no bump.  1 indicates a bump of bump_magnitude
 *        in the direction target_direction + pi/2. 2 indicates a
 *        bump_magnitude*2 bump in the direction target_direction + 
 *        pi/2.  -1 indicates a bump of bump_magnitude in the direction
 *        target_direction + 3*pi/2
 */

/* bump initiated in direction d */
#define WORD_BUMP(d) ( 0x50 | (0x0F & (d)) )

/* feedback */
#define WORD_FEEDBACK(f) ( 0x60 | (0x0F & (f)) )

/* stimulation with gradation g */
#define WORD_STIM(g) ( 0x60 | (g) )

/* multi-gadget reach */
#define WORD_REACH(t) ( 0x70 | (t) )
#define WORD_MOVEMENT_ONSET 0x80

#endif /* WORDS_CO_H */