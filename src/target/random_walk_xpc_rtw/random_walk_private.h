/*
 * random_walk_private.h
 *
 * Real-Time Workshop code generation for Simulink model "random_walk.mdl".
 *
 * Model Version              : 1.1211
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:40 2010
 */
#ifndef _RTW_HEADER_random_walk_private_h_
#define _RTW_HEADER_random_walk_private_h_
#include "rtwtypes.h"
#include "dsp_rt.h"                    /* Signal Processing Blockset general run time support functions */
#include "dspfilter_rt.h"              /* Signal Processing Blockset run time support library */
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

extern void xpctimeinfo(SimStruct *rts);
extern void donipcie(SimStruct *rts);
extern void Byte2Bits(SimStruct *rts);
extern void dopci8255(SimStruct *rts);
extern void serPos(SimStruct *rts);
extern void enccbcioquadcount(SimStruct *rts);
extern void adnipcie(SimStruct *rts);
extern void mastercon_rw(SimStruct *rts);
extern void danipcie(SimStruct *rts);
extern void xpcudpbytesend(SimStruct *rts);
void random_EnabledSubsystem_Disable(rtDW_EnabledSubsystem_random_wa *localDW);
void random_walk_EnabledSubsystem(int_T tid, boolean_T rtu_0, real_T rtu_1,
  rtB_EnabledSubsystem_random_wal *localB, rtDW_EnabledSubsystem_random_wa
  *localDW);
void random_walk_SampleandHold_Start(rtB_SampleandHold_random_walk *localB,
  rtP_SampleandHold_random_walk *localP);
void random_walk_SampleandHold(real_T rtu_0, real_T rtu_1,
  rtB_SampleandHold_random_walk *localB, rtDW_SampleandHold_random_walk *localDW,
  rtZCE_SampleandHold_random_walk *localZCE);

#endif                                 /* _RTW_HEADER_random_walk_private_h_ */
