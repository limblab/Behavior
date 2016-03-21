/*
 * CO_bump_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CO_bump".
 *
 * Model version              : 1.1274
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 21 16:29:27 2016
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CO_bump_private_h_
#define RTW_HEADER_CO_bump_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern const char *getRefMdlPath(const char *refMdl);
extern int getRefMdlSignalNumber(const char *mdlBlock, const char *signalName);
extern void xpctimeinfo(SimStruct *rts);
extern void donipcie(SimStruct *rts);
extern void Byte2Bits(SimStruct *rts);
extern void dopci8255(SimStruct *rts);
extern void serPos(SimStruct *rts);
extern void ich5(SimStruct *rts);
extern void xpcudpbytereceive(SimStruct *rts);
extern void adnipcie(SimStruct *rts);
extern void enccbcioquadcount(SimStruct *rts);
extern void mastercon_CO_bump(SimStruct *rts);
extern void xpcudpbytesend(SimStruct *rts);
extern void danipcie(SimStruct *rts);
extern void CO_bump_EnabledSubsystem_Start(DW_EnabledSubsystem_CO_bump_T
  *localDW);
extern void CO_bum_EnabledSubsystem_Disable(DW_EnabledSubsystem_CO_bump_T
  *localDW);
extern void CO_bump_EnabledSubsystem(boolean_T rtu_Enable, real_T rtu_In1,
  B_EnabledSubsystem_CO_bump_T *localB, DW_EnabledSubsystem_CO_bump_T *localDW);
extern void CO_bump_SampleandHold_Start(B_SampleandHold_CO_bump_T *localB,
  P_SampleandHold_CO_bump_T *localP);
extern void CO_bump_SampleandHold(real_T rtu_Trigger, real_T rtu_In,
  B_SampleandHold_CO_bump_T *localB, DW_SampleandHold_CO_bump_T *localDW,
  ZCE_SampleandHold_CO_bump_T *localZCE);

#endif                                 /* RTW_HEADER_CO_bump_private_h_ */
