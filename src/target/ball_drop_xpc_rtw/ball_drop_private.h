/*
 * ball_drop_private.h
 *
 * Real-Time Workshop code generation for Simulink model "ball_drop.mdl".
 *
 * Model Version              : 1.117
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Thu Aug 19 16:14:26 2010
 */
#ifndef _RTW_HEADER_ball_drop_private_h_
#define _RTW_HEADER_ball_drop_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern void xpctimeinfo(SimStruct *rts);
extern void donipcie(SimStruct *rts);
extern void Byte2Bits(SimStruct *rts);
extern void dopci8255(SimStruct *rts);
extern void dinipcie(SimStruct *rts);
extern void adnipcie(SimStruct *rts);
extern void mastercon_bd(SimStruct *rts);
extern void xpcudpbytesend(SimStruct *rts);
void ball_drop_SampleandHold_Start(rtB_SampleandHold_ball_drop *localB,
  rtP_SampleandHold_ball_drop *localP);
void ball_drop_SampleandHold(real_T rtu_0, real_T rtu_1,
  rtB_SampleandHold_ball_drop *localB, rtDW_SampleandHold_ball_drop *localDW,
  rtZCE_SampleandHold_ball_drop *localZCE);

#endif                                 /* _RTW_HEADER_ball_drop_private_h_ */
