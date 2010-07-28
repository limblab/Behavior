/*
 * wrist_flexion_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "wrist_flexion.mdl".
 *
 * Model Version              : 1.345
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 14:04:42 2010
 */

#include "wrist_flexion.h"
#include "rtw_capi.h"
#include "wrist_flexion_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Rad2Deg",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Memory",
    "Rotation", 0, 0, 0, 0, 0 },

  { 2, 0, "Reshape",
    "", 0, 0, 1, 0, 0 },

  { 3, 0, "Behavior WF/p1",
    "", 0, 0, 0, 0, 1 },

  { 4, 0, "Behavior WF/p2",
    "", 1, 0, 0, 0, 1 },

  { 5, 0, "Behavior WF/p3",
    "", 2, 0, 2, 0, 1 },

  { 6, 0, "Behavior WF/p4",
    "", 3, 0, 3, 0, 1 },

  { 7, 0, "Behavior WF/p5",
    "", 4, 0, 4, 0, 1 },

  { 8, 0, "Behavior WF/p6",
    "", 5, 0, 5, 0, 1 },

  { 9, 0, "Behavior WF/p7",
    "", 6, 0, 2, 0, 1 },

  { 10, 0, "Behavior WF/p8",
    "", 7, 0, 0, 0, 1 },

  { 11, 0, "WFTargetTable",
    "", 0, 0, 6, 0, 0 },

  { 12, 0, "CursorPos/GainX",
    "", 0, 0, 0, 0, 0 },

  { 13, 0, "CursorPos/GainY",
    "", 0, 0, 0, 0, 0 },

  { 14, 0, "CursorPos/Integrator",
    "", 0, 0, 3, 0, 1 },

  { 15, 1, "CursorPos/Saturation",
    "", 0, 0, 0, 0, 0 },

  { 16, 0, "CursorPos/PCI-6025E /p1",
    "RawX", 0, 0, 0, 0, 0 },

  { 17, 0, "CursorPos/PCI-6025E /p2",
    "RawY", 1, 0, 0, 0, 0 },

  { 18, 0, "CursorPos/Receive/p1",
    "", 0, 1, 7, 0, 2 },

  { 19, 0, "CursorPos/Receive/p2",
    "", 1, 0, 0, 0, 2 },

  { 20, 0, "CursorPos/Unpack",
    "", 0, 2, 8, 0, 2 },

  { 21, 0, "CursorPos/LowPassFilterX",
    "", 0, 0, 0, 0, 1 },

  { 22, 0, "CursorPos/LowPassFilterY",
    "", 0, 0, 0, 0, 1 },

  { 23, 0, "CursorPos/Sum1",
    "", 0, 0, 0, 0, 0 },

  { 24, 0, "CursorPos/Sum2",
    "", 0, 0, 0, 0, 0 },

  { 25, 0, "CursorPos/Switch",
    "", 0, 0, 0, 0, 1 },

  { 26, 0, "CursorPos/Switch1",
    "", 0, 0, 0, 0, 1 },

  { 27, 0, "CursorPos/Switch2",
    "", 0, 0, 3, 0, 1 },

  { 28, 0, "RewardSbs/Data Type Conversion",
    "", 0, 0, 0, 0, 1 },

  { 29, 0, "RewardSbs/Relational Operator",
    "", 0, 3, 0, 0, 0 },

  { 30, 0, "RewardSbs/Switch",
    "", 0, 0, 0, 0, 0 },

  { 31, 0, "RewardSbs/Uniform Random Number",
    "", 0, 0, 0, 0, 0 },

  { 32, 0, "UDPXmit/Rate Transition",
    "", 0, 1, 9, 0, 3 },

  { 33, 0, "UDPXmit/Pack",
    "", 0, 1, 9, 0, 0 },

  { 34, 11, "WordSbs/For Iterator",
    "", 0, 0, 0, 0, 4 },

  { 35, 11, "WordSbs/toThousandths",
    "", 0, 0, 3, 0, 4 },

  { 36, 11, "WordSbs/SerialConverter",
    "", 0, 0, 0, 0, 4 },

  { 37, 11, "WordSbs/ToBits/p1",
    "", 0, 0, 0, 0, 4 },

  { 38, 11, "WordSbs/ToBits/p2",
    "", 1, 0, 0, 0, 4 },

  { 39, 11, "WordSbs/ToBits/p3",
    "", 2, 0, 0, 0, 4 },

  { 40, 11, "WordSbs/ToBits/p4",
    "", 3, 0, 0, 0, 4 },

  { 41, 11, "WordSbs/ToBits/p5",
    "", 4, 0, 0, 0, 4 },

  { 42, 11, "WordSbs/ToBits/p6",
    "", 5, 0, 0, 0, 4 },

  { 43, 11, "WordSbs/ToBits/p7",
    "", 6, 0, 0, 0, 4 },

  { 44, 11, "WordSbs/ToBits/p8",
    "", 7, 0, 0, 0, 4 },

  { 45, 11, "WordSbs/ToBits1/p1",
    "", 0, 0, 0, 0, 4 },

  { 46, 11, "WordSbs/ToBits1/p2",
    "", 1, 0, 0, 0, 4 },

  { 47, 11, "WordSbs/ToBits1/p3",
    "", 2, 0, 0, 0, 4 },

  { 48, 11, "WordSbs/ToBits1/p4",
    "", 3, 0, 0, 0, 4 },

  { 49, 11, "WordSbs/ToBits1/p5",
    "", 4, 0, 0, 0, 4 },

  { 50, 11, "WordSbs/ToBits1/p6",
    "", 5, 0, 0, 0, 4 },

  { 51, 11, "WordSbs/ToBits1/p7",
    "", 6, 0, 0, 0, 4 },

  { 52, 11, "WordSbs/ToBits1/p8",
    "", 7, 0, 0, 0, 4 },

  { 53, 11, "WordSbs/xPC Target  Time ",
    "", 0, 0, 0, 0, 4 },

  { 54, 11, "WordSbs/Add2",
    "", 0, 0, 0, 0, 4 },

  { 55, 11, "WordSbs/Add3",
    "", 0, 0, 0, 0, 4 },

  { 56, 11, "WordSbs/Switch",
    "", 0, 0, 0, 0, 4 },

  { 57, 0, "CursorPos/Cursor Rotation/sqrt(u[1]*u[1] + u[2]*u[2])",
    "", 0, 0, 0, 0, 1 },

  { 58, 0, "CursorPos/Cursor Rotation/Product",
    "", 0, 0, 0, 0, 1 },

  { 59, 0, "CursorPos/Cursor Rotation/Product1",
    "", 0, 0, 0, 0, 1 },

  { 60, 0, "CursorPos/Cursor Rotation/Sum",
    "", 0, 0, 0, 0, 1 },

  { 61, 0, "CursorPos/Cursor Rotation/Trigonometric Function",
    "", 0, 0, 0, 0, 1 },

  { 62, 0, "CursorPos/Cursor Rotation/Trigonometric Function1",
    "", 0, 0, 0, 0, 1 },

  { 63, 0, "CursorPos/Cursor Rotation/Trigonometric Function2",
    "", 0, 0, 0, 0, 1 },

  { 64, 1, "CursorPos/Neural Control Subsystem/PctToFrac",
    "", 0, 0, 0, 0, 0 },

  { 65, 0, "CursorPos/Neural Control Subsystem/Product",
    "", 0, 0, 3, 0, 0 },

  { 66, 0, "CursorPos/Neural Control Subsystem/Product1",
    "", 0, 0, 3, 0, 0 },

  { 67, 0, "CursorPos/Neural Control Subsystem/Sum",
    "", 0, 0, 0, 0, 0 },

  { 68, 0, "CursorPos/Neural Control Subsystem/Sum1",
    "", 0, 0, 0, 0, 0 },

  { 69, 0, "CursorPos/Neural Control Subsystem/Sum2",
    "", 0, 0, 0, 0, 0 },

  { 70, 0, "CursorPos/Neural Control Subsystem/Override",
    "", 0, 0, 0, 0, 0 },

  { 71, 5, "RewardSbs/Sample and Hold/In",
    "", 0, 0, 0, 0, 4 },

  { 72, 0, "RewardSbs/Schmidt/Clock",
    "", 0, 0, 0, 0, 1 },

  { 73, 0, "RewardSbs/Schmidt/Relational Operator",
    "", 0, 3, 0, 0, 1 },

  { 74, 0, "RewardSbs/Schmidt/Sum",
    "", 0, 0, 0, 0, 1 },

  { 75, 10, "WordSbs/While Iterator Subsystem/ScaleTouSec",
    "", 0, 0, 0, 0, 4 },

  { 76, 10, "WordSbs/While Iterator Subsystem/xPC Target  Time ",
    "", 0, 0, 0, 0, 4 },

  { 77, 10, "WordSbs/While Iterator Subsystem/Subtract",
    "", 0, 0, 0, 0, 4 },

  { 78, 10, "WordSbs/While Iterator Subsystem/Switch",
    "", 0, 0, 0, 0, 4 },

  { 79, 6, "RewardSbs/Schmidt/Sample and Hold/In",
    "", 0, 0, 0, 0, 4 },

  { 80, 10, "WordSbs/While Iterator Subsystem/Compare To Constant/Compare",
    "", 0, 3, 0, 0, 4 },

  { 81, 10, "WordSbs/While Iterator Subsystem/Compare To Constant1/Compare",
    "", 0, 3, 0, 0, 4 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 82, "Rad2Deg",
    "Gain", 0, 0, 0 },

  { 83, "Memory",
    "X0", 0, 0, 0 },

  { 84, "Behavior WF",
    "P1", 0, 0, 0 },

  { 85, "Behavior WF",
    "P2", 0, 0, 0 },

  { 86, "Behavior WF",
    "P3", 0, 0, 0 },

  { 87, "Behavior WF",
    "P4", 0, 0, 0 },

  { 88, "Behavior WF",
    "P5", 0, 0, 0 },

  { 89, "Behavior WF",
    "P6", 0, 0, 0 },

  { 90, "Behavior WF",
    "P7", 0, 0, 0 },

  { 91, "Behavior WF",
    "P8", 0, 0, 0 },

  { 92, "Behavior WF",
    "P9", 0, 0, 0 },

  { 93, "Behavior WF",
    "P10", 0, 0, 0 },

  { 94, "Behavior WF",
    "P11", 0, 0, 0 },

  { 95, "Behavior WF",
    "P12", 0, 0, 0 },

  { 96, "Behavior WF",
    "P13", 0, 0, 0 },

  { 97, "Behavior WF",
    "P14", 0, 0, 0 },

  { 98, "Behavior WF",
    "P15", 0, 0, 0 },

  { 99, "Behavior WF",
    "P16", 0, 0, 0 },

  { 100, "Behavior WF",
    "P17", 0, 0, 0 },

  { 101, "Behavior WF",
    "P18", 0, 0, 0 },

  { 102, "Behavior WF",
    "P19", 0, 0, 0 },

  { 103, "Behavior WF",
    "P20", 0, 0, 0 },

  { 104, "Behavior WF",
    "P21", 0, 0, 0 },

  { 105, "WFTargetTable",
    "table", 0, 6, 0 },

  { 106, "CursorPos/EnableIntegrator",
    "Value", 0, 0, 0 },

  { 107, "CursorPos/EnablePosFilter",
    "Value", 0, 0, 0 },

  { 108, "CursorPos/NeuralControlPct",
    "Value", 0, 0, 0 },

  { 109, "CursorPos/OffsetX",
    "Value", 0, 0, 0 },

  { 110, "CursorPos/OffsetY",
    "Value", 0, 0, 0 },

  { 111, "CursorPos/ResetIntegrator",
    "Value", 0, 0, 0 },

  { 112, "CursorPos/GainX",
    "Gain", 0, 0, 0 },

  { 113, "CursorPos/GainY",
    "Gain", 0, 0, 0 },

  { 114, "CursorPos/Integrator",
    "InitialCondition", 0, 0, 0 },

  { 115, "CursorPos/Integrator",
    "UpperSaturationLimit", 0, 0, 0 },

  { 116, "CursorPos/Integrator",
    "LowerSaturationLimit", 0, 0, 0 },

  { 117, "CursorPos/Saturation",
    "UpperLimit", 0, 0, 0 },

  { 118, "CursorPos/Saturation",
    "LowerLimit", 0, 0, 0 },

  { 119, "CursorPos/PCI-6025E ",
    "P1", 0, 10, 0 },

  { 120, "CursorPos/PCI-6025E ",
    "P2", 0, 10, 0 },

  { 121, "CursorPos/PCI-6025E ",
    "P3", 0, 10, 0 },

  { 122, "CursorPos/PCI-6025E ",
    "P4", 0, 0, 0 },

  { 123, "CursorPos/PCI-6025E ",
    "P5", 0, 0, 0 },

  { 124, "CursorPos/PCI-6025E ",
    "P6", 0, 0, 0 },

  { 125, "CursorPos/Receive",
    "P1", 0, 11, 0 },

  { 126, "CursorPos/Receive",
    "P2", 0, 0, 0 },

  { 127, "CursorPos/Receive",
    "P3", 0, 0, 0 },

  { 128, "CursorPos/Receive",
    "P4", 0, 0, 0 },

  { 129, "CursorPos/LowPassFilterX",
    "A", 0, 12, 0 },

  { 130, "CursorPos/LowPassFilterX",
    "B", 0, 0, 0 },

  { 131, "CursorPos/LowPassFilterX",
    "C", 0, 0, 0 },

  { 132, "CursorPos/LowPassFilterX",
    "X0", 0, 0, 0 },

  { 133, "CursorPos/LowPassFilterY",
    "A", 0, 12, 0 },

  { 134, "CursorPos/LowPassFilterY",
    "B", 0, 0, 0 },

  { 135, "CursorPos/LowPassFilterY",
    "C", 0, 0, 0 },

  { 136, "CursorPos/LowPassFilterY",
    "X0", 0, 0, 0 },

  { 137, "RewardSbs/JackpotChance",
    "Value", 0, 0, 0 },

  { 138, "RewardSbs/RewardJackpot",
    "Value", 0, 0, 0 },

  { 139, "RewardSbs/RewardTime",
    "Value", 0, 0, 0 },

  { 140, "RewardSbs/Uniform Random Number",
    "Minimum", 0, 0, 0 },

  { 141, "RewardSbs/Uniform Random Number",
    "Maximum", 0, 0, 0 },

  { 142, "RewardSbs/Uniform Random Number",
    "Seed", 0, 0, 0 },

  { 143, "UDPXmit/Send",
    "P1", 0, 13, 0 },

  { 144, "UDPXmit/Send",
    "P2", 0, 0, 0 },

  { 145, "UDPXmit/Send",
    "P3", 0, 0, 0 },

  { 146, "UDPXmit/Send",
    "P4", 0, 0, 0 },

  { 147, "WordSbs/Constant",
    "Value", 0, 0, 0 },

  { 148, "WordSbs/Constant2",
    "Value", 0, 0, 0 },

  { 149, "WordSbs/toThousandths",
    "Gain", 0, 0, 0 },

  { 150, "WordSbs/Port A",
    "P1", 0, 14, 0 },

  { 151, "WordSbs/Port A",
    "P2", 0, 0, 0 },

  { 152, "WordSbs/Port A",
    "P3", 0, 14, 0 },

  { 153, "WordSbs/Port A",
    "P4", 0, 14, 0 },

  { 154, "WordSbs/Port A",
    "P5", 0, 0, 0 },

  { 155, "WordSbs/Port A",
    "P6", 0, 0, 0 },

  { 156, "WordSbs/Port A",
    "P7", 0, 0, 0 },

  { 157, "WordSbs/Port A",
    "P8", 0, 0, 0 },

  { 158, "WordSbs/Port A",
    "P9", 0, 0, 0 },

  { 159, "WordSbs/Port B",
    "P1", 0, 14, 0 },

  { 160, "WordSbs/Port B",
    "P2", 0, 0, 0 },

  { 161, "WordSbs/Port B",
    "P3", 0, 14, 0 },

  { 162, "WordSbs/Port B",
    "P4", 0, 14, 0 },

  { 163, "WordSbs/Port B",
    "P5", 0, 0, 0 },

  { 164, "WordSbs/Port B",
    "P6", 0, 0, 0 },

  { 165, "WordSbs/Port B",
    "P7", 0, 0, 0 },

  { 166, "WordSbs/Port B",
    "P8", 0, 0, 0 },

  { 167, "WordSbs/Port B",
    "P9", 0, 0, 0 },

  { 168, "WordSbs/xPC Target  Time ",
    "P1", 0, 0, 0 },

  { 169, "WordSbs/xPC Target  Time ",
    "P2", 0, 0, 0 },

  { 170, "WordSbs/Switch",
    "Threshold", 0, 0, 0 },

  { 171, "CursorPos/Neural Control Subsystem/Constant",
    "Value", 0, 0, 0 },

  { 172, "CursorPos/Neural Control Subsystem/Constant1",
    "Value", 0, 0, 0 },

  { 173, "CursorPos/Neural Control Subsystem/PctToFrac",
    "Gain", 0, 0, 0 },

  { 174, "WordSbs/While Iterator Subsystem/StobeHi",
    "Value", 0, 0, 0 },

  { 175, "WordSbs/While Iterator Subsystem/StrobeLow",
    "Value", 0, 0, 0 },

  { 176, "WordSbs/While Iterator Subsystem/ScaleTouSec",
    "Gain", 0, 0, 0 },

  { 177, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P1", 0, 10, 0 },

  { 178, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P2", 0, 10, 0 },

  { 179, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P3", 0, 10, 0 },

  { 180, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P4", 0, 0, 0 },

  { 181, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P5", 0, 0, 0 },

  { 182, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P6", 0, 0, 0 },

  { 183, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P7", 0, 0, 0 },

  { 184, "WordSbs/While Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 0, 0 },

  { 185, "WordSbs/While Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 0, 0 },

  { 186, "WordSbs/While Iterator Subsystem/Compare To Constant/Constant",
    "Value", 0, 0, 0 },

  { 187, "WordSbs/While Iterator Subsystem/Compare To Constant1/Constant",
    "Value", 0, 0, 0 },

  {
    0, NULL, NULL, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &wrist_flexion_B.Rad2Deg,            /* 0: Signal */
  &wrist_flexion_B.Rotation,           /* 1: Signal */
  &wrist_flexion_B.Reshape[0],         /* 2: Signal */
  &wrist_flexion_B.BehaviorWF_o1,      /* 3: Signal */
  &wrist_flexion_B.BehaviorWF_o2,      /* 4: Signal */
  &wrist_flexion_B.BehaviorWF_o3[0],   /* 5: Signal */
  &wrist_flexion_B.BehaviorWF_o4[0],   /* 6: Signal */
  &wrist_flexion_B.BehaviorWF_o5[0],   /* 7: Signal */
  &wrist_flexion_B.BehaviorWF_o6[0],   /* 8: Signal */
  &wrist_flexion_B.BehaviorWF_o7[0],   /* 9: Signal */
  &wrist_flexion_B.BehaviorWF_o8,      /* 10: Signal */
  &wrist_flexion_B.WFTargetTable[0],   /* 11: Signal */
  &wrist_flexion_B.GainX,              /* 12: Signal */
  &wrist_flexion_B.GainY,              /* 13: Signal */
  &wrist_flexion_B.Integrator[0],      /* 14: Signal */
  &wrist_flexion_B.Saturation,         /* 15: Signal */
  &wrist_flexion_B.RawX,               /* 16: Signal */
  &wrist_flexion_B.RawY,               /* 17: Signal */
  &wrist_flexion_B.Receive_o1[0],      /* 18: Signal */
  &wrist_flexion_B.Receive_o2,         /* 19: Signal */
  &wrist_flexion_B.Unpack[0],          /* 20: Signal */
  &wrist_flexion_B.LowPassFilterX,     /* 21: Signal */
  &wrist_flexion_B.LowPassFilterY,     /* 22: Signal */
  &wrist_flexion_B.Sum1_n,             /* 23: Signal */
  &wrist_flexion_B.Sum2_c,             /* 24: Signal */
  &wrist_flexion_B.Switch,             /* 25: Signal */
  &wrist_flexion_B.Switch1,            /* 26: Signal */
  &wrist_flexion_B.Switch2[0],         /* 27: Signal */
  &wrist_flexion_B.DataTypeConversion, /* 28: Signal */
  &wrist_flexion_B.RelationalOperator, /* 29: Signal */
  &wrist_flexion_B.Switch_i,           /* 30: Signal */
  &wrist_flexion_B.UniformRandomNumber,/* 31: Signal */
  &wrist_flexion_B.RateTransition[0],  /* 32: Signal */
  &wrist_flexion_B.Pack[0],            /* 33: Signal */
  &wrist_flexion_B.ForIterator,        /* 34: Signal */
  &wrist_flexion_B.toThousandths[0],   /* 35: Signal */
  &wrist_flexion_B.SerialConverter,    /* 36: Signal */
  &wrist_flexion_B.ToBits_o1,          /* 37: Signal */
  &wrist_flexion_B.ToBits_o2,          /* 38: Signal */
  &wrist_flexion_B.ToBits_o3,          /* 39: Signal */
  &wrist_flexion_B.ToBits_o4,          /* 40: Signal */
  &wrist_flexion_B.ToBits_o5,          /* 41: Signal */
  &wrist_flexion_B.ToBits_o6,          /* 42: Signal */
  &wrist_flexion_B.ToBits_o7,          /* 43: Signal */
  &wrist_flexion_B.ToBits_o8,          /* 44: Signal */
  &wrist_flexion_B.ToBits1_o1,         /* 45: Signal */
  &wrist_flexion_B.ToBits1_o2,         /* 46: Signal */
  &wrist_flexion_B.ToBits1_o3,         /* 47: Signal */
  &wrist_flexion_B.ToBits1_o4,         /* 48: Signal */
  &wrist_flexion_B.ToBits1_o5,         /* 49: Signal */
  &wrist_flexion_B.ToBits1_o6,         /* 50: Signal */
  &wrist_flexion_B.ToBits1_o7,         /* 51: Signal */
  &wrist_flexion_B.ToBits1_o8,         /* 52: Signal */
  &wrist_flexion_B.xPCTargetTime,      /* 53: Signal */
  &wrist_flexion_B.Add2,               /* 54: Signal */
  &wrist_flexion_B.Add3,               /* 55: Signal */
  &wrist_flexion_B.Switch_e,           /* 56: Signal */
  &wrist_flexion_B.sqrtu1u1u2u2,       /* 57: Signal */
  &wrist_flexion_B.Product_p,          /* 58: Signal */
  &wrist_flexion_B.Product1_a,         /* 59: Signal */
  &wrist_flexion_B.Sum_a,              /* 60: Signal */
  &wrist_flexion_B.TrigonometricFunction,/* 61: Signal */
  &wrist_flexion_B.TrigonometricFunction1,/* 62: Signal */
  &wrist_flexion_B.TrigonometricFunction2,/* 63: Signal */
  &wrist_flexion_B.PctToFrac,          /* 64: Signal */
  &wrist_flexion_B.Product[0],         /* 65: Signal */
  &wrist_flexion_B.Product1[0],        /* 66: Signal */
  &wrist_flexion_B.Sum,                /* 67: Signal */
  &wrist_flexion_B.Sum1,               /* 68: Signal */
  &wrist_flexion_B.Sum2,               /* 69: Signal */
  &wrist_flexion_B.Override,           /* 70: Signal */
  &wrist_flexion_B.SampleandHold_k.In, /* 71: Signal */
  &wrist_flexion_B.Clock,              /* 72: Signal */
  &wrist_flexion_B.RelationalOperator_f,/* 73: Signal */
  &wrist_flexion_B.Sum_m,              /* 74: Signal */
  &wrist_flexion_B.ScaleTouSec,        /* 75: Signal */
  &wrist_flexion_B.xPCTargetTime_a,    /* 76: Signal */
  &wrist_flexion_B.Subtract,           /* 77: Signal */
  &wrist_flexion_B.Switch_o,           /* 78: Signal */
  &wrist_flexion_B.SampleandHold.In,   /* 79: Signal */
  &wrist_flexion_B.Compare_h,          /* 80: Signal */
  &wrist_flexion_B.Compare,            /* 81: Signal */
  &wrist_flexion_P.Rad2Deg_Gain,       /* 82: Block Parameter */
  &wrist_flexion_P.Memory_X0,          /* 83: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P1,      /* 84: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P2,      /* 85: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P3,      /* 86: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P4,      /* 87: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P5,      /* 88: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P6,      /* 89: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P7,      /* 90: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P8,      /* 91: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P9,      /* 92: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P10,     /* 93: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P11,     /* 94: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P12,     /* 95: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P13,     /* 96: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P14,     /* 97: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P15,     /* 98: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P16,     /* 99: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P17,     /* 100: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P18,     /* 101: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P19,     /* 102: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P20,     /* 103: Block Parameter */
  &wrist_flexion_P.BehaviorWF_P21,     /* 104: Block Parameter */
  &wrist_flexion_P.WFTargetTable_table[0],/* 105: Block Parameter */
  &wrist_flexion_P.EnableIntegrator_Value,/* 106: Block Parameter */
  &wrist_flexion_P.EnablePosFilter_Value,/* 107: Block Parameter */
  &wrist_flexion_P.NeuralControlPct_Value,/* 108: Block Parameter */
  &wrist_flexion_P.OffsetX_Value,      /* 109: Block Parameter */
  &wrist_flexion_P.OffsetY_Value,      /* 110: Block Parameter */
  &wrist_flexion_P.ResetIntegrator_Value,/* 111: Block Parameter */
  &wrist_flexion_P.GainX_Gain,         /* 112: Block Parameter */
  &wrist_flexion_P.GainY_Gain,         /* 113: Block Parameter */
  &wrist_flexion_P.Integrator_IC,      /* 114: Block Parameter */
  &wrist_flexion_P.Integrator_UpperSat,/* 115: Block Parameter */
  &wrist_flexion_P.Integrator_LowerSat,/* 116: Block Parameter */
  &wrist_flexion_P.Saturation_UpperSat,/* 117: Block Parameter */
  &wrist_flexion_P.Saturation_LowerSat,/* 118: Block Parameter */
  &wrist_flexion_P.PCI6025E_P1[0],     /* 119: Block Parameter */
  &wrist_flexion_P.PCI6025E_P2[0],     /* 120: Block Parameter */
  &wrist_flexion_P.PCI6025E_P3[0],     /* 121: Block Parameter */
  &wrist_flexion_P.PCI6025E_P4,        /* 122: Block Parameter */
  &wrist_flexion_P.PCI6025E_P5,        /* 123: Block Parameter */
  &wrist_flexion_P.PCI6025E_P6,        /* 124: Block Parameter */
  &wrist_flexion_P.Receive_P1[0],      /* 125: Block Parameter */
  &wrist_flexion_P.Receive_P2,         /* 126: Block Parameter */
  &wrist_flexion_P.Receive_P3,         /* 127: Block Parameter */
  &wrist_flexion_P.Receive_P4,         /* 128: Block Parameter */
  &wrist_flexion_P.LowPassFilterX_A[0],/* 129: Block Parameter */
  &wrist_flexion_P.LowPassFilterX_B,   /* 130: Block Parameter */
  &wrist_flexion_P.LowPassFilterX_C,   /* 131: Block Parameter */
  &wrist_flexion_P.LowPassFilterX_X0,  /* 132: Block Parameter */
  &wrist_flexion_P.LowPassFilterY_A[0],/* 133: Block Parameter */
  &wrist_flexion_P.LowPassFilterY_B,   /* 134: Block Parameter */
  &wrist_flexion_P.LowPassFilterY_C,   /* 135: Block Parameter */
  &wrist_flexion_P.LowPassFilterY_X0,  /* 136: Block Parameter */
  &wrist_flexion_P.JackpotChance_Value,/* 137: Block Parameter */
  &wrist_flexion_P.RewardJackpot_Value,/* 138: Block Parameter */
  &wrist_flexion_P.RewardTime_Value,   /* 139: Block Parameter */
  &wrist_flexion_P.UniformRandomNumber_Min,/* 140: Block Parameter */
  &wrist_flexion_P.UniformRandomNumber_Max,/* 141: Block Parameter */
  &wrist_flexion_P.UniformRandomNumber_Seed,/* 142: Block Parameter */
  &wrist_flexion_P.Send_P1[0],         /* 143: Block Parameter */
  &wrist_flexion_P.Send_P2,            /* 144: Block Parameter */
  &wrist_flexion_P.Send_P3,            /* 145: Block Parameter */
  &wrist_flexion_P.Send_P4,            /* 146: Block Parameter */
  &wrist_flexion_P.Constant_Value_m,   /* 147: Block Parameter */
  &wrist_flexion_P.Constant2_Value,    /* 148: Block Parameter */
  &wrist_flexion_P.toThousandths_Gain, /* 149: Block Parameter */
  &wrist_flexion_P.PortA_P1[0],        /* 150: Block Parameter */
  &wrist_flexion_P.PortA_P2,           /* 151: Block Parameter */
  &wrist_flexion_P.PortA_P3[0],        /* 152: Block Parameter */
  &wrist_flexion_P.PortA_P4[0],        /* 153: Block Parameter */
  &wrist_flexion_P.PortA_P5,           /* 154: Block Parameter */
  &wrist_flexion_P.PortA_P6,           /* 155: Block Parameter */
  &wrist_flexion_P.PortA_P7,           /* 156: Block Parameter */
  &wrist_flexion_P.PortA_P8,           /* 157: Block Parameter */
  &wrist_flexion_P.PortA_P9,           /* 158: Block Parameter */
  &wrist_flexion_P.PortB_P1[0],        /* 159: Block Parameter */
  &wrist_flexion_P.PortB_P2,           /* 160: Block Parameter */
  &wrist_flexion_P.PortB_P3[0],        /* 161: Block Parameter */
  &wrist_flexion_P.PortB_P4[0],        /* 162: Block Parameter */
  &wrist_flexion_P.PortB_P5,           /* 163: Block Parameter */
  &wrist_flexion_P.PortB_P6,           /* 164: Block Parameter */
  &wrist_flexion_P.PortB_P7,           /* 165: Block Parameter */
  &wrist_flexion_P.PortB_P8,           /* 166: Block Parameter */
  &wrist_flexion_P.PortB_P9,           /* 167: Block Parameter */
  &wrist_flexion_P.xPCTargetTime_P1_a, /* 168: Block Parameter */
  &wrist_flexion_P.xPCTargetTime_P2_b, /* 169: Block Parameter */
  &wrist_flexion_P.Switch_Threshold,   /* 170: Block Parameter */
  &wrist_flexion_P.Constant_Value,     /* 171: Block Parameter */
  &wrist_flexion_P.Constant1_Value,    /* 172: Block Parameter */
  &wrist_flexion_P.PctToFrac_Gain,     /* 173: Block Parameter */
  &wrist_flexion_P.StobeHi_Value,      /* 174: Block Parameter */
  &wrist_flexion_P.StrobeLow_Value,    /* 175: Block Parameter */
  &wrist_flexion_P.ScaleTouSec_Gain,   /* 176: Block Parameter */
  &wrist_flexion_P.PCI6025E_P1_m[0],   /* 177: Block Parameter */
  &wrist_flexion_P.PCI6025E_P2_l[0],   /* 178: Block Parameter */
  &wrist_flexion_P.PCI6025E_P3_j[0],   /* 179: Block Parameter */
  &wrist_flexion_P.PCI6025E_P4_b,      /* 180: Block Parameter */
  &wrist_flexion_P.PCI6025E_P5_d,      /* 181: Block Parameter */
  &wrist_flexion_P.PCI6025E_P6_o,      /* 182: Block Parameter */
  &wrist_flexion_P.PCI6025E_P7,        /* 183: Block Parameter */
  &wrist_flexion_P.xPCTargetTime_P1,   /* 184: Block Parameter */
  &wrist_flexion_P.xPCTargetTime_P2,   /* 185: Block Parameter */
  &wrist_flexion_P.Constant_Value_o,   /* 186: Block Parameter */
  &wrist_flexion_P.Constant_Value_h    /* 187: Block Parameter */
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "float", "real32_T", 0, 0, sizeof(real32_T), SS_SINGLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { NULL, 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 },

  { rtwCAPI_MATRIX_COL_MAJOR, 2, 2 },

  { rtwCAPI_VECTOR, 4, 2 },

  { rtwCAPI_VECTOR, 6, 2 },

  { rtwCAPI_VECTOR, 8, 2 },

  { rtwCAPI_VECTOR, 10, 2 },

  { rtwCAPI_MATRIX_COL_MAJOR, 12, 2 },

  { rtwCAPI_VECTOR, 14, 2 },

  { rtwCAPI_MATRIX_COL_MAJOR, 16, 2 },

  { rtwCAPI_VECTOR, 18, 2 },

  { rtwCAPI_VECTOR, 20, 2 },

  { rtwCAPI_VECTOR, 22, 2 },

  { rtwCAPI_VECTOR, 24, 2 },

  { rtwCAPI_VECTOR, 26, 2 },

  { rtwCAPI_VECTOR, 28, 2 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  96,                                  /* 2 */
  1,                                   /* 3 */
  4,                                   /* 4 */
  1,                                   /* 5 */
  2,                                   /* 6 */
  1,                                   /* 7 */
  10,                                  /* 8 */
  1,                                   /* 9 */
  8,                                   /* 10 */
  1,                                   /* 11 */
  6,                                   /* 12 */
  16,                                  /* 13 */
  16,                                  /* 14 */
  1,                                   /* 15 */
  1,                                   /* 16 */
  4,                                   /* 17 */
  112,                                 /* 18 */
  1,                                   /* 19 */
  1,                                   /* 20 */
  2,                                   /* 21 */
  1,                                   /* 22 */
  7,                                   /* 23 */
  15,                                  /* 24 */
  1,                                   /* 25 */
  1,                                   /* 26 */
  11,                                  /* 27 */
  1,                                   /* 28 */
  8                                    /* 29 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0, 0.01, 0.02
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    2, 0 },

  { (const void *) &rtcapiStoredFloats[3], (const void *) &rtcapiStoredFloats[1],
    3, 0 },

  { NULL, NULL, -1, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 82 },

  { rtBlockParameters, 106,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void wrist_flexion_InitializeDataMapInfo(rtModel_wrist_flexion
  *wrist_flexion_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(wrist_flexion_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(wrist_flexion_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(wrist_flexion_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(wrist_flexion_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(wrist_flexion_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(wrist_flexion_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(wrist_flexion_rtM->DataMapInfo.mmi, 0);
}

/* EOF: wrist_flexion_capi.c */
