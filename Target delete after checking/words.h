/* wordso.h
 *
 * defines word codes for center out and random walk tasks
 */
 
#ifndef WORDS_CO_H
#define WORDS_CO_H

/* task specific setup */
#if TASK_CO
#define WORD_TASK_CODE 0x01
#elif TASK_RW
#define WORD_TASK_CODE 0x02
#elif TASK_FC
#define WORD_TASK_CODE 0x03
#endif

/* trial start */
#define WORD_START_TRIAL_GENERIC 0x10
#define WORD_START_TRIAL (WORD_START_TRIAL_GENERIC | WORD_TASK_CODE)

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

/* go cue */
#define WORD_GO_CUE 0x31

/* outer target (t) on */
#define WORD_OT_ON(t) ( 0x40 | (t) )

/* bump initiated in direction d */
#define WORD_BUMP(d) ( 0x50 | (d) )

/* stimulation with gradation d*/
#define WORD_STIM(g) ( 0x60 | (g) )

#endif /* WORDS_CO_H */
