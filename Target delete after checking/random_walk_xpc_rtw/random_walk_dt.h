/*
 * random_walk_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "random_walk.mdl".
 *
 * Model Version              : 1.922
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Jan 09 14:56:49 2008
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
  { (char_T *)(&random_walk_B.Clock), 0, 0, 209 },

  { (char_T *)(&random_walk_B.Compare), 3, 0, 245 },

  { (char_T *)(&random_walk_B.Memory), 8, 0, 57 },

  { (char_T *)(&random_walk_B.EnabledSubsystem.In1), 0, 0, 1 },

  { (char_T *)(&random_walk_B.EnabledSubsystem_by.In1), 0, 0, 1 },

  { (char_T *)(&random_walk_B.EnabledSubsystem_f.In1), 0, 0, 1 },

  { (char_T *)(&random_walk_B.EnabledSubsystem_b1.In1), 0, 0, 1 },

  { (char_T *)(&random_walk_B.EnabledSubsystem_b.In1), 0, 0, 1 },

  { (char_T *)(&random_walk_DWork.DigitalFilter2_FILT_STATES[0]), 0, 0, 577 },

  { (char_T *)(&random_walk_DWork.Send_PWORK), 11, 0, 1 },

  { (char_T *)(&random_walk_DWork.DigitalFilter2_CIRCBUFFIDX), 6, 0, 4 },

  { (char_T *)(&random_walk_DWork.PCIQUAD04_IWORK), 10, 0, 26 },

  { (char_T *)(&random_walk_DWork.DelayInput1_DSTATE), 3, 0, 3 },

  { (char_T *)(&random_walk_DWork.Memory_PreviousInput), 8, 0, 8 },

  { (char_T *)(&random_walk_DWork.EnabledSubsystem.EnabledSubsystem_MODE), 10, 0,
    1 },

  { (char_T *)(&random_walk_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&random_walk_DWork.EnabledSubsystem_by.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)
    (&random_walk_DWork.EnabledSubsystem_by.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&random_walk_DWork.EnabledSubsystem_f.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)
    (&random_walk_DWork.EnabledSubsystem_f.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&random_walk_DWork.EnabledSubsystem_b1.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)
    (&random_walk_DWork.EnabledSubsystem_b1.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&random_walk_DWork.EnabledSubsystem_b.EnabledSubsystem_MODE), 10,
    0, 1 },

  { (char_T *)
    (&random_walk_DWork.EnabledSubsystem_b.EnabledSubsystem_SubsysRanBC), 2, 0,
    1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  24U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&random_walk_P.Time_Value), 0, 0, 408 },

  { (char_T *)(&random_walk_P.DelayInput1_X0), 3, 0, 3 },

  { (char_T *)(&random_walk_P.Memory_X0), 8, 0, 24 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] random_walk_dt.h */
