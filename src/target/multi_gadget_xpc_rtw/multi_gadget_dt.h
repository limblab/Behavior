/*
 * multi_gadget_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "multi_gadget.mdl".
 *
 * Model Version              : 1.82
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 14:02:34 2010
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
  { (char_T *)(&multi_gadget_B.PCI6025EDI), 0, 0, 239 },

  { (char_T *)(&multi_gadget_B.Pack[0]), 3, 0, 224 },

  { (char_T *)(&multi_gadget_B.RelationalOperator), 8, 0, 4 },

  { (char_T *)(&multi_gadget_B.SampleandHold.In), 0, 0, 1 },

  { (char_T *)(&multi_gadget_B.SampleandHold_m.In), 0, 0, 1 },

  { (char_T *)(&multi_gadget_DWork.BehaviorMG_DSTATE), 0, 0, 103 },

  { (char_T *)(&multi_gadget_DWork.BehaviorMG_PWORK), 11, 0, 2 },

  { (char_T *)(&multi_gadget_DWork.PCI6025EDI_IWORK[0]), 10, 0, 222 },

  { (char_T *)(&multi_gadget_DWork.SampleandHold.SampleandHold_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&multi_gadget_DWork.SampleandHold_m.SampleandHold_SubsysRanBC), 2,
    0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&multi_gadget_P.PCI6025EDI_P1_Size[0]), 0, 0, 368 },

  { (char_T *)(&multi_gadget_P.SampleandHold._Y0), 0, 0, 1 },

  { (char_T *)(&multi_gadget_P.SampleandHold_m._Y0), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] multi_gadget_dt.h */
