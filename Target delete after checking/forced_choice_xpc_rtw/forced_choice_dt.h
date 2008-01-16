/*
 * forced_choice_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "forced_choice.mdl".
 *
 * Model Version              : 1.747
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Mon Dec 17 17:05:06 2007
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
  { (char_T *)(&forced_choice_B.Clock), 0, 0, 187 },

  { (char_T *)(&forced_choice_B.Compare), 3, 0, 228 },

  { (char_T *)(&forced_choice_B.Memory), 8, 0, 24 },

  { (char_T *)(&forced_choice_B.EnabledSubsystem.In1), 0, 0, 1 },

  { (char_T *)(&forced_choice_B.EnabledSubsystem_h.In1), 0, 0, 1 },

  { (char_T *)(&forced_choice_DWork.DigitalFilter2_FILT_STATES[0]), 0, 0, 68 },

  { (char_T *)(&forced_choice_DWork.Send_PWORK), 11, 0, 1 },

  { (char_T *)(&forced_choice_DWork.DigitalFilter2_CIRCBUFFIDX), 6, 0, 4 },

  { (char_T *)(&forced_choice_DWork.PCIQUAD04_IWORK), 10, 0, 84 },

  { (char_T *)(&forced_choice_DWork.Memory_PreviousInput), 8, 0, 4 },

  { (char_T *)(&forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)
    (&forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_MODE),
    10, 0, 1 },

  { (char_T *)
    (&forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  14U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&forced_choice_P.Time_Value), 0, 0, 396 },

  { (char_T *)(&forced_choice_P.Memory_X0), 8, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] forced_choice_dt.h */
