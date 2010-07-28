/*
 * bump_stim_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "bump_stim.mdl".
 *
 * Model Version              : 1.1219
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:43:54 2010
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
  { (char_T *)(&bump_stim_B.Clock), 0, 0, 331 },

  { (char_T *)(&bump_stim_B.Compare), 3, 0, 247 },

  { (char_T *)(&bump_stim_B.Memory), 8, 0, 59 },

  { (char_T *)(&bump_stim_B.SampleandHold.In), 0, 0, 1 },

  { (char_T *)(&bump_stim_B.SampleandHold_a.In), 0, 0, 1 },

  { (char_T *)(&bump_stim_B.EnabledSubsystem_l.In1), 0, 0, 1 },

  { (char_T *)(&bump_stim_B.EnabledSubsystem_o.In1), 0, 0, 1 },

  { (char_T *)(&bump_stim_B.EnabledSubsystem_f.In1), 0, 0, 1 },

  { (char_T *)(&bump_stim_B.EnabledSubsystem_c.In1), 0, 0, 1 },

  { (char_T *)(&bump_stim_B.EnabledSubsystem.In1), 0, 0, 1 },

  { (char_T *)(&bump_stim_DWork.DigitalFilter2_FILT_STATES[0]), 0, 0, 149 },

  { (char_T *)(&bump_stim_DWork.BehaviorBS_PWORK), 11, 0, 2 },

  { (char_T *)(&bump_stim_DWork.DigitalFilter2_CIRCBUFFIDX), 6, 0, 4 },

  { (char_T *)(&bump_stim_DWork.PCIQUAD04_IWORK), 10, 0, 161 },

  { (char_T *)(&bump_stim_DWork.DelayInput1_DSTATE), 3, 0, 4 },

  { (char_T *)(&bump_stim_DWork.Memory_PreviousInput), 8, 0, 7 },

  { (char_T *)(&bump_stim_DWork.SampleandHold.SampleandHold_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&bump_stim_DWork.SampleandHold_a.SampleandHold_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&bump_stim_DWork.EnabledSubsystem_l.EnabledSubsystem_MODE), 10, 0,
    1 },

  { (char_T *)(&bump_stim_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&bump_stim_DWork.EnabledSubsystem_o.EnabledSubsystem_MODE), 10, 0,
    1 },

  { (char_T *)(&bump_stim_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&bump_stim_DWork.EnabledSubsystem_f.EnabledSubsystem_MODE), 10, 0,
    1 },

  { (char_T *)(&bump_stim_DWork.EnabledSubsystem_f.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&bump_stim_DWork.EnabledSubsystem_c.EnabledSubsystem_MODE), 10, 0,
    1 },

  { (char_T *)(&bump_stim_DWork.EnabledSubsystem_c.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&bump_stim_DWork.EnabledSubsystem.EnabledSubsystem_MODE), 10, 0,
    1 },

  { (char_T *)(&bump_stim_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  28U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&bump_stim_P.Time_Value), 0, 0, 521 },

  { (char_T *)(&bump_stim_P.DelayInput1_X0), 3, 0, 4 },

  { (char_T *)(&bump_stim_P.Memory_X0), 8, 0, 23 },

  { (char_T *)(&bump_stim_P.SampleandHold._Y0), 0, 0, 1 },

  { (char_T *)(&bump_stim_P.SampleandHold_a._Y0), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] bump_stim_dt.h */
