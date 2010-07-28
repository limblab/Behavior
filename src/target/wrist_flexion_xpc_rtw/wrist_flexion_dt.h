/*
 * wrist_flexion_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "wrist_flexion.mdl".
 *
 * Model Version              : 1.345
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 14:04:42 2010
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&wrist_flexion_B.Integrator[0]), 0, 0, 292 },

  { (char_T *)(&wrist_flexion_B.Unpack[0]), 1, 0, 4 },

  { (char_T *)(&wrist_flexion_B.Receive_o1[0]), 3, 0, 240 },

  { (char_T *)(&wrist_flexion_B.RelationalOperator), 8, 0, 4 },

  { (char_T *)(&wrist_flexion_B.SampleandHold.In), 0, 0, 1 },

  { (char_T *)(&wrist_flexion_B.SampleandHold_k.In), 0, 0, 1 },

  { (char_T *)(&wrist_flexion_DWork.BehaviorWF_DSTATE), 0, 0, 106 },

  { (char_T *)(&wrist_flexion_DWork.Receive_PWORK), 11, 0, 3 },

  { (char_T *)(&wrist_flexion_DWork.SFunction_IWORK.AcquireOK), 10, 0, 107 },

  { (char_T *)(&wrist_flexion_DWork.SampleandHold.SampleandHold_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&wrist_flexion_DWork.SampleandHold_k.SampleandHold_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&wrist_flexion_P.ResetIntegrator_Value), 0, 0, 421 },

  { (char_T *)(&wrist_flexion_P.SampleandHold._Y0), 0, 0, 1 },

  { (char_T *)(&wrist_flexion_P.SampleandHold_k._Y0), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] wrist_flexion_dt.h */
