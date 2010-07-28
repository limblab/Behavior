/*
 * center_out_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "center_out.mdl".
 *
 * Model Version              : 1.1201
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:09 2010
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
  { (char_T *)(&center_out_B.Clock), 0, 0, 331 },

  { (char_T *)(&center_out_B.Compare), 3, 0, 247 },

  { (char_T *)(&center_out_B.Memory), 8, 0, 59 },

  { (char_T *)(&center_out_B.SampleandHold.In), 0, 0, 1 },

  { (char_T *)(&center_out_B.SampleandHold_e.In), 0, 0, 1 },

  { (char_T *)(&center_out_B.EnabledSubsystem_l.In1), 0, 0, 1 },

  { (char_T *)(&center_out_B.EnabledSubsystem_n.In1), 0, 0, 1 },

  { (char_T *)(&center_out_B.EnabledSubsystem_ir.In1), 0, 0, 1 },

  { (char_T *)(&center_out_B.EnabledSubsystem_i.In1), 0, 0, 1 },

  { (char_T *)(&center_out_B.EnabledSubsystem.In1), 0, 0, 1 },

  { (char_T *)(&center_out_DWork.DigitalFilter2_FILT_STATES[0]), 0, 0, 147 },

  { (char_T *)(&center_out_DWork.Send_PWORK), 11, 0, 1 },

  { (char_T *)(&center_out_DWork.DigitalFilter2_CIRCBUFFIDX), 6, 0, 4 },

  { (char_T *)(&center_out_DWork.PCIQUAD04_IWORK), 10, 0, 671 },

  { (char_T *)(&center_out_DWork.DelayInput1_DSTATE), 3, 0, 4 },

  { (char_T *)(&center_out_DWork.Memory_PreviousInput), 8, 0, 7 },

  { (char_T *)(&center_out_DWork.SampleandHold.SampleandHold_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&center_out_DWork.SampleandHold_e.SampleandHold_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&center_out_DWork.EnabledSubsystem_l.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)(&center_out_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&center_out_DWork.EnabledSubsystem_n.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)(&center_out_DWork.EnabledSubsystem_n.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&center_out_DWork.EnabledSubsystem_ir.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)
    (&center_out_DWork.EnabledSubsystem_ir.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&center_out_DWork.EnabledSubsystem_i.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)(&center_out_DWork.EnabledSubsystem_i.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&center_out_DWork.EnabledSubsystem.EnabledSubsystem_MODE), 10, 0,
    1 },

  { (char_T *)(&center_out_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  28U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&center_out_P.Time_Value), 0, 0, 506 },

  { (char_T *)(&center_out_P.DelayInput1_X0), 3, 0, 4 },

  { (char_T *)(&center_out_P.Memory_X0), 8, 0, 23 },

  { (char_T *)(&center_out_P.SampleandHold._Y0), 0, 0, 1 },

  { (char_T *)(&center_out_P.SampleandHold_e._Y0), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] center_out_dt.h */
