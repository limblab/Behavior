/*
 * bump_choice_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "bump_choice.mdl".
 *
 * Model Version              : 1.1247
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Aug 04 10:30:55 2010
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
  { (char_T *)(&bump_choice_B.Clock), 0, 0, 396 },

  { (char_T *)(&bump_choice_B.Compare), 3, 0, 359 },

  { (char_T *)(&bump_choice_B.Memory), 8, 0, 59 },

  { (char_T *)(&bump_choice_B.SampleandHold.In), 0, 0, 1 },

  { (char_T *)(&bump_choice_B.SampleandHold_h.In), 0, 0, 1 },

  { (char_T *)(&bump_choice_B.EnabledSubsystem_l.In1), 0, 0, 1 },

  { (char_T *)(&bump_choice_B.EnabledSubsystem_e.In1), 0, 0, 1 },

  { (char_T *)(&bump_choice_B.EnabledSubsystem_o.In1), 0, 0, 1 },

  { (char_T *)(&bump_choice_B.EnabledSubsystem_p.In1), 0, 0, 1 },

  { (char_T *)(&bump_choice_B.EnabledSubsystem.In1), 0, 0, 1 },

  { (char_T *)(&bump_choice_DWork.DigitalFilter2_FILT_STATES[0]), 0, 0, 149 },

  { (char_T *)(&bump_choice_DWork.BehaviorBC_PWORK), 11, 0, 2 },

  { (char_T *)(&bump_choice_DWork.DigitalFilter2_CIRCBUFFIDX), 6, 0, 4 },

  { (char_T *)(&bump_choice_DWork.PCIQUAD04_IWORK), 10, 0, 114 },

  { (char_T *)(&bump_choice_DWork.DelayInput1_DSTATE), 3, 0, 4 },

  { (char_T *)(&bump_choice_DWork.Memory_PreviousInput), 8, 0, 7 },

  { (char_T *)(&bump_choice_DWork.SampleandHold.SampleandHold_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&bump_choice_DWork.SampleandHold_h.SampleandHold_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&bump_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)
    (&bump_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&bump_choice_DWork.EnabledSubsystem_e.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)
    (&bump_choice_DWork.EnabledSubsystem_e.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&bump_choice_DWork.EnabledSubsystem_o.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)
    (&bump_choice_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&bump_choice_DWork.EnabledSubsystem_p.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)
    (&bump_choice_DWork.EnabledSubsystem_p.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&bump_choice_DWork.EnabledSubsystem.EnabledSubsystem_MODE), 10, 0,
    1 },

  { (char_T *)(&bump_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  28U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&bump_choice_P.Time_Value), 0, 0, 534 },

  { (char_T *)(&bump_choice_P.PacketSpec_Value), 7, 0, 2 },

  { (char_T *)(&bump_choice_P.DelayInput1_X0), 3, 0, 4 },

  { (char_T *)(&bump_choice_P.Memory_X0), 8, 0, 23 },

  { (char_T *)(&bump_choice_P.SampleandHold._Y0), 0, 0, 1 },

  { (char_T *)(&bump_choice_P.SampleandHold_h._Y0), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] bump_choice_dt.h */
