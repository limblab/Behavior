/*
 * forced_choice_private.h
 *
 * Real-Time Workshop code generation for Simulink model "forced_choice.mdl".
 *
 * Model Version              : 1.1203
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:24 2010
 */
#ifndef _RTW_HEADER_forced_choice_private_h_
#define _RTW_HEADER_forced_choice_private_h_
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
extern void mastercon_fc(SimStruct *rts);
extern void danipcie(SimStruct *rts);
extern void xpcudpbytesend(SimStruct *rts);
void forced_EnabledSubsystem_Disable(rtDW_EnabledSubsystem_forced_ch *localDW);
void forced_choice_EnabledSubsystem(int_T tid, boolean_T rtu_0, real_T rtu_1,
  rtB_EnabledSubsystem_forced_cho *localB, rtDW_EnabledSubsystem_forced_ch
  *localDW);
void forced_choi_SampleandHold_Start(rtB_SampleandHold_forced_choice *localB,
  rtP_SampleandHold_forced_choice *localP);
void forced_choice_SampleandHold(real_T rtu_0, real_T rtu_1,
  rtB_SampleandHold_forced_choice *localB, rtDW_SampleandHold_forced_choic
  *localDW, rtZCE_SampleandHold_forced_choi *localZCE);

#endif                                 /* _RTW_HEADER_forced_choice_private_h_ */
