/*
 * ball_drop_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "ball_drop.mdl".
 *
 * Model Version              : 1.95
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 14:00:48 2010
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
  { (char_T *)(&ball_drop_B.PCI6025EDI), 0, 0, 54 },

  { (char_T *)(&ball_drop_B.Pack[0]), 3, 0, 224 },

  { (char_T *)(&ball_drop_B.RelationalOperator), 8, 0, 2 },

  { (char_T *)(&ball_drop_B.SampleandHold.In), 0, 0, 1 },

  { (char_T *)(&ball_drop_B.SampleandHold_i.In), 0, 0, 1 },

  { (char_T *)(&ball_drop_DWork.BehaviorBD_DSTATE), 0, 0, 76 },

  { (char_T *)(&ball_drop_DWork.Send_PWORK), 11, 0, 1 },

  { (char_T *)(&ball_drop_DWork.PCI6025EDI_IWORK[0]), 10, 0, 90 },

  { (char_T *)(&ball_drop_DWork.SampleandHold.SampleandHold_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&ball_drop_DWork.SampleandHold_i.SampleandHold_SubsysRanBC), 2, 0,
    1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&ball_drop_P.PCI6025EDI_P1_Size[0]), 0, 0, 195 },

  { (char_T *)(&ball_drop_P.SampleandHold._Y0), 0, 0, 1 },

  { (char_T *)(&ball_drop_P.SampleandHold_i._Y0), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] ball_drop_dt.h */
