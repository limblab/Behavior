/*
 * multi_gadget_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "multi_gadget.mdl".
 *
 * Model Version              : 1.82
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 14:02:34 2010
 */

#include "multi_gadget.h"
#include "rtw_capi.h"
#include "multi_gadget_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Reshape",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Behavior MG/p1",
    "", 0, 0, 1, 0, 0 },

  { 2, 0, "Behavior MG/p2",
    "", 1, 0, 1, 0, 0 },

  { 3, 0, "Behavior MG/p3",
    "", 2, 0, 1, 0, 0 },

  { 4, 0, "Behavior MG/p4",
    "", 3, 0, 1, 0, 0 },

  { 5, 0, "Behavior MG/p5",
    "", 4, 0, 1, 0, 0 },

  { 6, 0, "Behavior MG/p6",
    "", 5, 0, 2, 0, 0 },

  { 7, 0, "Behavior MG/p7",
    "", 6, 0, 3, 0, 0 },

  { 8, 0, "Behavior MG/p8",
    "", 7, 0, 4, 0, 0 },

  { 9, 0, "Behavior MG/p9",
    "", 8, 0, 2, 0, 0 },

  { 10, 0, "Behavior MG/p10",
    "", 9, 0, 2, 0, 0 },

  { 11, 0, "PCI-6025E DI",
    "", 0, 0, 1, 0, 1 },

  { 12, 0, "TargetTable",
    "", 0, 0, 5, 0, 0 },

  { 13, 0, "CursorPos/NewtonCal1",
    "", 0, 0, 1, 0, 1 },

  { 14, 0, "CursorPos/NewtonCal2",
    "", 0, 0, 1, 0, 1 },

  { 15, 0, "CursorPos/PCI-6025E AD/p1",
    "", 0, 0, 1, 0, 1 },

  { 16, 0, "CursorPos/PCI-6025E AD/p2",
    "", 1, 0, 1, 0, 1 },

  { 17, 0, "CursorPos/Add",
    "", 0, 0, 1, 0, 1 },

  { 18, 0, "CursorPos/Add1",
    "", 0, 0, 1, 0, 1 },

  { 19, 0, "DeviceOutput/ToBits/p1",
    "", 0, 0, 1, 0, 0 },

  { 20, 0, "DeviceOutput/ToBits/p2",
    "", 1, 0, 1, 0, 0 },

  { 21, 0, "DeviceOutput/ToBits/p3",
    "", 2, 0, 1, 0, 0 },

  { 22, 0, "DeviceOutput/ToBits/p4",
    "", 3, 0, 1, 0, 0 },

  { 23, 0, "DeviceOutput/ToBits/p5",
    "", 4, 0, 1, 0, 0 },

  { 24, 0, "DeviceOutput/ToBits/p6",
    "", 5, 0, 1, 0, 0 },

  { 25, 0, "DeviceOutput/ToBits/p7",
    "", 6, 0, 1, 0, 0 },

  { 26, 0, "DeviceOutput/ToBits/p8",
    "", 7, 0, 1, 0, 0 },

  { 27, 0, "RewardSbs/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 28, 0, "RewardSbs/Relational Operator",
    "", 0, 1, 1, 0, 1 },

  { 29, 0, "RewardSbs/Switch",
    "", 0, 0, 1, 0, 1 },

  { 30, 0, "RewardSbs/Uniform Random Number",
    "", 0, 0, 1, 0, 1 },

  { 31, 0, "UDPXmit/Rate Transition",
    "", 0, 2, 6, 0, 2 },

  { 32, 0, "UDPXmit/Pack",
    "", 0, 2, 6, 0, 1 },

  { 33, 9, "WordSbs/For Iterator",
    "", 0, 0, 1, 0, 3 },

  { 34, 9, "WordSbs/toThousandths",
    "", 0, 0, 3, 0, 3 },

  { 35, 9, "WordSbs/SerialConverter",
    "", 0, 0, 1, 0, 3 },

  { 36, 9, "WordSbs/ToBits/p1",
    "", 0, 0, 1, 0, 3 },

  { 37, 9, "WordSbs/ToBits/p2",
    "", 1, 0, 1, 0, 3 },

  { 38, 9, "WordSbs/ToBits/p3",
    "", 2, 0, 1, 0, 3 },

  { 39, 9, "WordSbs/ToBits/p4",
    "", 3, 0, 1, 0, 3 },

  { 40, 9, "WordSbs/ToBits/p5",
    "", 4, 0, 1, 0, 3 },

  { 41, 9, "WordSbs/ToBits/p6",
    "", 5, 0, 1, 0, 3 },

  { 42, 9, "WordSbs/ToBits/p7",
    "", 6, 0, 1, 0, 3 },

  { 43, 9, "WordSbs/ToBits/p8",
    "", 7, 0, 1, 0, 3 },

  { 44, 9, "WordSbs/ToBits1/p1",
    "", 0, 0, 1, 0, 3 },

  { 45, 9, "WordSbs/ToBits1/p2",
    "", 1, 0, 1, 0, 3 },

  { 46, 9, "WordSbs/ToBits1/p3",
    "", 2, 0, 1, 0, 3 },

  { 47, 9, "WordSbs/ToBits1/p4",
    "", 3, 0, 1, 0, 3 },

  { 48, 9, "WordSbs/ToBits1/p5",
    "", 4, 0, 1, 0, 3 },

  { 49, 9, "WordSbs/ToBits1/p6",
    "", 5, 0, 1, 0, 3 },

  { 50, 9, "WordSbs/ToBits1/p7",
    "", 6, 0, 1, 0, 3 },

  { 51, 9, "WordSbs/ToBits1/p8",
    "", 7, 0, 1, 0, 3 },

  { 52, 9, "WordSbs/xPC Target  Time ",
    "", 0, 0, 1, 0, 3 },

  { 53, 9, "WordSbs/Add2",
    "", 0, 0, 1, 0, 3 },

  { 54, 9, "WordSbs/Add3",
    "", 0, 0, 1, 0, 3 },

  { 55, 9, "WordSbs/Switch",
    "", 0, 0, 1, 0, 3 },

  { 56, 3, "RewardSbs/Sample and Hold/In",
    "", 0, 0, 1, 0, 3 },

  { 57, 0, "RewardSbs/Schmidt/Clock",
    "", 0, 0, 1, 0, 0 },

  { 58, 0, "RewardSbs/Schmidt/Relational Operator",
    "", 0, 1, 1, 0, 0 },

  { 59, 0, "RewardSbs/Schmidt/Sum",
    "", 0, 0, 1, 0, 0 },

  { 60, 8, "WordSbs/While Iterator Subsystem/ScaleTouSec",
    "", 0, 0, 1, 0, 3 },

  { 61, 8, "WordSbs/While Iterator Subsystem/xPC Target  Time ",
    "", 0, 0, 1, 0, 3 },

  { 62, 8, "WordSbs/While Iterator Subsystem/Subtract",
    "", 0, 0, 1, 0, 3 },

  { 63, 8, "WordSbs/While Iterator Subsystem/Switch",
    "", 0, 0, 1, 0, 3 },

  { 64, 4, "RewardSbs/Schmidt/Sample and Hold/In",
    "", 0, 0, 1, 0, 3 },

  { 65, 8, "WordSbs/While Iterator Subsystem/Compare To Constant/Compare",
    "", 0, 1, 1, 0, 3 },

  { 66, 8, "WordSbs/While Iterator Subsystem/Compare To Constant1/Compare",
    "", 0, 1, 1, 0, 3 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 67, "Behavior MG",
    "P1", 0, 1, 0 },

  { 68, "Behavior MG",
    "P2", 0, 1, 0 },

  { 69, "Behavior MG",
    "P3", 0, 1, 0 },

  { 70, "Behavior MG",
    "P4", 0, 1, 0 },

  { 71, "Behavior MG",
    "P5", 0, 1, 0 },

  { 72, "Behavior MG",
    "P6", 0, 1, 0 },

  { 73, "Behavior MG",
    "P7", 0, 1, 0 },

  { 74, "Behavior MG",
    "P8", 0, 1, 0 },

  { 75, "Behavior MG",
    "P9", 0, 1, 0 },

  { 76, "Behavior MG",
    "P10", 0, 1, 0 },

  { 77, "Behavior MG",
    "P11", 0, 1, 0 },

  { 78, "Behavior MG",
    "P12", 0, 1, 0 },

  { 79, "Behavior MG",
    "P13", 0, 1, 0 },

  { 80, "Behavior MG",
    "P14", 0, 1, 0 },

  { 81, "Behavior MG",
    "P15", 0, 1, 0 },

  { 82, "Behavior MG",
    "P16", 0, 1, 0 },

  { 83, "Behavior MG",
    "P17", 0, 1, 0 },

  { 84, "PCI-6025E DI",
    "P1", 0, 1, 0 },

  { 85, "PCI-6025E DI",
    "P2", 0, 1, 0 },

  { 86, "PCI-6025E DI",
    "P3", 0, 1, 0 },

  { 87, "PCI-6025E DI",
    "P4", 0, 1, 0 },

  { 88, "PCI-6025E DI",
    "P5", 0, 1, 0 },

  { 89, "TargetTable",
    "table", 0, 5, 0 },

  { 90, "CursorPos/NewtonCal1",
    "Gain", 0, 1, 0 },

  { 91, "CursorPos/NewtonCal2",
    "Gain", 0, 1, 0 },

  { 92, "CursorPos/PCI-6025E AD",
    "P1", 0, 7, 0 },

  { 93, "CursorPos/PCI-6025E AD",
    "P2", 0, 7, 0 },

  { 94, "CursorPos/PCI-6025E AD",
    "P3", 0, 7, 0 },

  { 95, "CursorPos/PCI-6025E AD",
    "P4", 0, 1, 0 },

  { 96, "CursorPos/PCI-6025E AD",
    "P5", 0, 1, 0 },

  { 97, "CursorPos/PCI-6025E AD",
    "P6", 0, 1, 0 },

  { 98, "DeviceOutput/PCI-6025E DO",
    "P1", 0, 8, 0 },

  { 99, "DeviceOutput/PCI-6025E DO",
    "P2", 0, 8, 0 },

  { 100, "DeviceOutput/PCI-6025E DO",
    "P3", 0, 8, 0 },

  { 101, "DeviceOutput/PCI-6025E DO",
    "P4", 0, 1, 0 },

  { 102, "DeviceOutput/PCI-6025E DO",
    "P5", 0, 1, 0 },

  { 103, "DeviceOutput/PCI-6025E DO",
    "P6", 0, 1, 0 },

  { 104, "DeviceOutput/PCI-6025E DO",
    "P7", 0, 1, 0 },

  { 105, "RewardSbs/JackpotChance",
    "Value", 0, 1, 0 },

  { 106, "RewardSbs/RewardJackpot",
    "Value", 0, 1, 0 },

  { 107, "RewardSbs/RewardTime",
    "Value", 0, 1, 0 },

  { 108, "RewardSbs/Uniform Random Number",
    "Minimum", 0, 1, 0 },

  { 109, "RewardSbs/Uniform Random Number",
    "Maximum", 0, 1, 0 },

  { 110, "RewardSbs/Uniform Random Number",
    "Seed", 0, 1, 0 },

  { 111, "UDPXmit/Send",
    "P1", 0, 9, 0 },

  { 112, "UDPXmit/Send",
    "P2", 0, 1, 0 },

  { 113, "UDPXmit/Send",
    "P3", 0, 1, 0 },

  { 114, "UDPXmit/Send",
    "P4", 0, 1, 0 },

  { 115, "WordSbs/Constant",
    "Value", 0, 1, 0 },

  { 116, "WordSbs/Constant2",
    "Value", 0, 1, 0 },

  { 117, "WordSbs/toThousandths",
    "Gain", 0, 1, 0 },

  { 118, "WordSbs/Port A",
    "P1", 0, 10, 0 },

  { 119, "WordSbs/Port A",
    "P2", 0, 1, 0 },

  { 120, "WordSbs/Port A",
    "P3", 0, 10, 0 },

  { 121, "WordSbs/Port A",
    "P4", 0, 10, 0 },

  { 122, "WordSbs/Port A",
    "P5", 0, 1, 0 },

  { 123, "WordSbs/Port A",
    "P6", 0, 1, 0 },

  { 124, "WordSbs/Port A",
    "P7", 0, 1, 0 },

  { 125, "WordSbs/Port A",
    "P8", 0, 1, 0 },

  { 126, "WordSbs/Port A",
    "P9", 0, 1, 0 },

  { 127, "WordSbs/Port B",
    "P1", 0, 10, 0 },

  { 128, "WordSbs/Port B",
    "P2", 0, 1, 0 },

  { 129, "WordSbs/Port B",
    "P3", 0, 10, 0 },

  { 130, "WordSbs/Port B",
    "P4", 0, 10, 0 },

  { 131, "WordSbs/Port B",
    "P5", 0, 1, 0 },

  { 132, "WordSbs/Port B",
    "P6", 0, 1, 0 },

  { 133, "WordSbs/Port B",
    "P7", 0, 1, 0 },

  { 134, "WordSbs/Port B",
    "P8", 0, 1, 0 },

  { 135, "WordSbs/Port B",
    "P9", 0, 1, 0 },

  { 136, "WordSbs/xPC Target  Time ",
    "P1", 0, 1, 0 },

  { 137, "WordSbs/xPC Target  Time ",
    "P2", 0, 1, 0 },

  { 138, "WordSbs/Switch",
    "Threshold", 0, 1, 0 },

  { 139, "WordSbs/While Iterator Subsystem/StobeHi",
    "Value", 0, 1, 0 },

  { 140, "WordSbs/While Iterator Subsystem/StrobeLow",
    "Value", 0, 1, 0 },

  { 141, "WordSbs/While Iterator Subsystem/ScaleTouSec",
    "Gain", 0, 1, 0 },

  { 142, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P1", 0, 7, 0 },

  { 143, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P2", 0, 7, 0 },

  { 144, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P3", 0, 7, 0 },

  { 145, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P4", 0, 1, 0 },

  { 146, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P5", 0, 1, 0 },

  { 147, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P6", 0, 1, 0 },

  { 148, "WordSbs/While Iterator Subsystem/PCI-6025E ",
    "P7", 0, 1, 0 },

  { 149, "WordSbs/While Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 1, 0 },

  { 150, "WordSbs/While Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 1, 0 },

  { 151, "WordSbs/While Iterator Subsystem/Compare To Constant/Constant",
    "Value", 0, 1, 0 },

  { 152, "WordSbs/While Iterator Subsystem/Compare To Constant1/Constant",
    "Value", 0, 1, 0 },

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
  &multi_gadget_B.Reshape[0],          /* 0: Signal */
  &multi_gadget_B.BehaviorMG_o1,       /* 1: Signal */
  &multi_gadget_B.BehaviorMG_o2,       /* 2: Signal */
  &multi_gadget_B.BehaviorMG_o3,       /* 3: Signal */
  &multi_gadget_B.BehaviorMG_o4,       /* 4: Signal */
  &multi_gadget_B.BehaviorMG_o5,       /* 5: Signal */
  &multi_gadget_B.BehaviorMG_o6[0],    /* 6: Signal */
  &multi_gadget_B.BehaviorMG_o7[0],    /* 7: Signal */
  &multi_gadget_B.BehaviorMG_o8[0],    /* 8: Signal */
  &multi_gadget_B.BehaviorMG_o9[0],    /* 9: Signal */
  &multi_gadget_B.BehaviorMG_o10[0],   /* 10: Signal */
  &multi_gadget_B.PCI6025EDI,          /* 11: Signal */
  &multi_gadget_B.TargetTable[0],      /* 12: Signal */
  &multi_gadget_B.NewtonCal1,          /* 13: Signal */
  &multi_gadget_B.NewtonCal2,          /* 14: Signal */
  &multi_gadget_B.PCI6025EAD_o1,       /* 15: Signal */
  &multi_gadget_B.PCI6025EAD_o2,       /* 16: Signal */
  &multi_gadget_B.Add,                 /* 17: Signal */
  &multi_gadget_B.Add1,                /* 18: Signal */
  &multi_gadget_B.ToBits_o1,           /* 19: Signal */
  &multi_gadget_B.ToBits_o2,           /* 20: Signal */
  &multi_gadget_B.ToBits_o3,           /* 21: Signal */
  &multi_gadget_B.ToBits_o4,           /* 22: Signal */
  &multi_gadget_B.ToBits_o5,           /* 23: Signal */
  &multi_gadget_B.ToBits_o6,           /* 24: Signal */
  &multi_gadget_B.ToBits_o7,           /* 25: Signal */
  &multi_gadget_B.ToBits_o8,           /* 26: Signal */
  &multi_gadget_B.DataTypeConversion,  /* 27: Signal */
  &multi_gadget_B.RelationalOperator,  /* 28: Signal */
  &multi_gadget_B.Switch,              /* 29: Signal */
  &multi_gadget_B.UniformRandomNumber, /* 30: Signal */
  &multi_gadget_B.RateTransition[0],   /* 31: Signal */
  &multi_gadget_B.Pack[0],             /* 32: Signal */
  &multi_gadget_B.ForIterator,         /* 33: Signal */
  &multi_gadget_B.toThousandths[0],    /* 34: Signal */
  &multi_gadget_B.SerialConverter,     /* 35: Signal */
  &multi_gadget_B.ToBits_o1_f,         /* 36: Signal */
  &multi_gadget_B.ToBits_o2_n,         /* 37: Signal */
  &multi_gadget_B.ToBits_o3_i,         /* 38: Signal */
  &multi_gadget_B.ToBits_o4_o,         /* 39: Signal */
  &multi_gadget_B.ToBits_o5_n,         /* 40: Signal */
  &multi_gadget_B.ToBits_o6_a,         /* 41: Signal */
  &multi_gadget_B.ToBits_o7_j,         /* 42: Signal */
  &multi_gadget_B.ToBits_o8_f,         /* 43: Signal */
  &multi_gadget_B.ToBits1_o1,          /* 44: Signal */
  &multi_gadget_B.ToBits1_o2,          /* 45: Signal */
  &multi_gadget_B.ToBits1_o3,          /* 46: Signal */
  &multi_gadget_B.ToBits1_o4,          /* 47: Signal */
  &multi_gadget_B.ToBits1_o5,          /* 48: Signal */
  &multi_gadget_B.ToBits1_o6,          /* 49: Signal */
  &multi_gadget_B.ToBits1_o7,          /* 50: Signal */
  &multi_gadget_B.ToBits1_o8,          /* 51: Signal */
  &multi_gadget_B.xPCTargetTime,       /* 52: Signal */
  &multi_gadget_B.Add2,                /* 53: Signal */
  &multi_gadget_B.Add3,                /* 54: Signal */
  &multi_gadget_B.Switch_d,            /* 55: Signal */
  &multi_gadget_B.SampleandHold_m.In,  /* 56: Signal */
  &multi_gadget_B.Clock,               /* 57: Signal */
  &multi_gadget_B.RelationalOperator_c,/* 58: Signal */
  &multi_gadget_B.Sum,                 /* 59: Signal */
  &multi_gadget_B.ScaleTouSec,         /* 60: Signal */
  &multi_gadget_B.xPCTargetTime_c,     /* 61: Signal */
  &multi_gadget_B.Subtract,            /* 62: Signal */
  &multi_gadget_B.Switch_j,            /* 63: Signal */
  &multi_gadget_B.SampleandHold.In,    /* 64: Signal */
  &multi_gadget_B.Compare_c,           /* 65: Signal */
  &multi_gadget_B.Compare,             /* 66: Signal */
  &multi_gadget_P.BehaviorMG_P1,       /* 67: Block Parameter */
  &multi_gadget_P.BehaviorMG_P2,       /* 68: Block Parameter */
  &multi_gadget_P.BehaviorMG_P3,       /* 69: Block Parameter */
  &multi_gadget_P.BehaviorMG_P4,       /* 70: Block Parameter */
  &multi_gadget_P.BehaviorMG_P5,       /* 71: Block Parameter */
  &multi_gadget_P.BehaviorMG_P6,       /* 72: Block Parameter */
  &multi_gadget_P.BehaviorMG_P7,       /* 73: Block Parameter */
  &multi_gadget_P.BehaviorMG_P8,       /* 74: Block Parameter */
  &multi_gadget_P.BehaviorMG_P9,       /* 75: Block Parameter */
  &multi_gadget_P.BehaviorMG_P10,      /* 76: Block Parameter */
  &multi_gadget_P.BehaviorMG_P11,      /* 77: Block Parameter */
  &multi_gadget_P.BehaviorMG_P12,      /* 78: Block Parameter */
  &multi_gadget_P.BehaviorMG_P13,      /* 79: Block Parameter */
  &multi_gadget_P.BehaviorMG_P14,      /* 80: Block Parameter */
  &multi_gadget_P.BehaviorMG_P15,      /* 81: Block Parameter */
  &multi_gadget_P.BehaviorMG_P16,      /* 82: Block Parameter */
  &multi_gadget_P.BehaviorMG_P17,      /* 83: Block Parameter */
  &multi_gadget_P.PCI6025EDI_P1,       /* 84: Block Parameter */
  &multi_gadget_P.PCI6025EDI_P2,       /* 85: Block Parameter */
  &multi_gadget_P.PCI6025EDI_P3,       /* 86: Block Parameter */
  &multi_gadget_P.PCI6025EDI_P4,       /* 87: Block Parameter */
  &multi_gadget_P.PCI6025EDI_P5,       /* 88: Block Parameter */
  &multi_gadget_P.TargetTable_table[0],/* 89: Block Parameter */
  &multi_gadget_P.NewtonCal1_Gain,     /* 90: Block Parameter */
  &multi_gadget_P.NewtonCal2_Gain,     /* 91: Block Parameter */
  &multi_gadget_P.PCI6025EAD_P1[0],    /* 92: Block Parameter */
  &multi_gadget_P.PCI6025EAD_P2[0],    /* 93: Block Parameter */
  &multi_gadget_P.PCI6025EAD_P3[0],    /* 94: Block Parameter */
  &multi_gadget_P.PCI6025EAD_P4,       /* 95: Block Parameter */
  &multi_gadget_P.PCI6025EAD_P5,       /* 96: Block Parameter */
  &multi_gadget_P.PCI6025EAD_P6,       /* 97: Block Parameter */
  &multi_gadget_P.PCI6025EDO_P1[0],    /* 98: Block Parameter */
  &multi_gadget_P.PCI6025EDO_P2[0],    /* 99: Block Parameter */
  &multi_gadget_P.PCI6025EDO_P3[0],    /* 100: Block Parameter */
  &multi_gadget_P.PCI6025EDO_P4,       /* 101: Block Parameter */
  &multi_gadget_P.PCI6025EDO_P5,       /* 102: Block Parameter */
  &multi_gadget_P.PCI6025EDO_P6,       /* 103: Block Parameter */
  &multi_gadget_P.PCI6025EDO_P7,       /* 104: Block Parameter */
  &multi_gadget_P.JackpotChance_Value, /* 105: Block Parameter */
  &multi_gadget_P.RewardJackpot_Value, /* 106: Block Parameter */
  &multi_gadget_P.RewardTime_Value,    /* 107: Block Parameter */
  &multi_gadget_P.UniformRandomNumber_Min,/* 108: Block Parameter */
  &multi_gadget_P.UniformRandomNumber_Max,/* 109: Block Parameter */
  &multi_gadget_P.UniformRandomNumber_Seed,/* 110: Block Parameter */
  &multi_gadget_P.Send_P1[0],          /* 111: Block Parameter */
  &multi_gadget_P.Send_P2,             /* 112: Block Parameter */
  &multi_gadget_P.Send_P3,             /* 113: Block Parameter */
  &multi_gadget_P.Send_P4,             /* 114: Block Parameter */
  &multi_gadget_P.Constant_Value,      /* 115: Block Parameter */
  &multi_gadget_P.Constant2_Value,     /* 116: Block Parameter */
  &multi_gadget_P.toThousandths_Gain,  /* 117: Block Parameter */
  &multi_gadget_P.PortA_P1[0],         /* 118: Block Parameter */
  &multi_gadget_P.PortA_P2,            /* 119: Block Parameter */
  &multi_gadget_P.PortA_P3[0],         /* 120: Block Parameter */
  &multi_gadget_P.PortA_P4[0],         /* 121: Block Parameter */
  &multi_gadget_P.PortA_P5,            /* 122: Block Parameter */
  &multi_gadget_P.PortA_P6,            /* 123: Block Parameter */
  &multi_gadget_P.PortA_P7,            /* 124: Block Parameter */
  &multi_gadget_P.PortA_P8,            /* 125: Block Parameter */
  &multi_gadget_P.PortA_P9,            /* 126: Block Parameter */
  &multi_gadget_P.PortB_P1[0],         /* 127: Block Parameter */
  &multi_gadget_P.PortB_P2,            /* 128: Block Parameter */
  &multi_gadget_P.PortB_P3[0],         /* 129: Block Parameter */
  &multi_gadget_P.PortB_P4[0],         /* 130: Block Parameter */
  &multi_gadget_P.PortB_P5,            /* 131: Block Parameter */
  &multi_gadget_P.PortB_P6,            /* 132: Block Parameter */
  &multi_gadget_P.PortB_P7,            /* 133: Block Parameter */
  &multi_gadget_P.PortB_P8,            /* 134: Block Parameter */
  &multi_gadget_P.PortB_P9,            /* 135: Block Parameter */
  &multi_gadget_P.xPCTargetTime_P1_k,  /* 136: Block Parameter */
  &multi_gadget_P.xPCTargetTime_P2_l,  /* 137: Block Parameter */
  &multi_gadget_P.Switch_Threshold,    /* 138: Block Parameter */
  &multi_gadget_P.StobeHi_Value,       /* 139: Block Parameter */
  &multi_gadget_P.StrobeLow_Value,     /* 140: Block Parameter */
  &multi_gadget_P.ScaleTouSec_Gain,    /* 141: Block Parameter */
  &multi_gadget_P.PCI6025E_P1[0],      /* 142: Block Parameter */
  &multi_gadget_P.PCI6025E_P2[0],      /* 143: Block Parameter */
  &multi_gadget_P.PCI6025E_P3[0],      /* 144: Block Parameter */
  &multi_gadget_P.PCI6025E_P4,         /* 145: Block Parameter */
  &multi_gadget_P.PCI6025E_P5,         /* 146: Block Parameter */
  &multi_gadget_P.PCI6025E_P6,         /* 147: Block Parameter */
  &multi_gadget_P.PCI6025E_P7,         /* 148: Block Parameter */
  &multi_gadget_P.xPCTargetTime_P1,    /* 149: Block Parameter */
  &multi_gadget_P.xPCTargetTime_P2,    /* 150: Block Parameter */
  &multi_gadget_P.Constant_Value_m,    /* 151: Block Parameter */
  &multi_gadget_P.Constant_Value_l     /* 152: Block Parameter */
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { NULL, 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_MATRIX_COL_MAJOR, 0, 2 },

  { rtwCAPI_SCALAR, 2, 2 },

  { rtwCAPI_VECTOR, 4, 2 },

  { rtwCAPI_VECTOR, 6, 2 },

  { rtwCAPI_VECTOR, 8, 2 },

  { rtwCAPI_MATRIX_COL_MAJOR, 10, 2 },

  { rtwCAPI_VECTOR, 12, 2 },

  { rtwCAPI_VECTOR, 14, 2 },

  { rtwCAPI_VECTOR, 16, 2 },

  { rtwCAPI_VECTOR, 18, 2 },

  { rtwCAPI_VECTOR, 20, 2 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  80,                                  /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  1,                                   /* 3 */
  4,                                   /* 4 */
  1,                                   /* 5 */
  2,                                   /* 6 */
  1,                                   /* 7 */
  10,                                  /* 8 */
  1,                                   /* 9 */
  5,                                   /* 10 */
  16,                                  /* 11 */
  112,                                 /* 12 */
  1,                                   /* 13 */
  1,                                   /* 14 */
  2,                                   /* 15 */
  1,                                   /* 16 */
  4,                                   /* 17 */
  1,                                   /* 18 */
  11,                                  /* 19 */
  1,                                   /* 20 */
  8                                    /* 21 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.001, 0.02
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[0],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[0],
    2, 0 },

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
  { rtBlockSignals, 67 },

  { rtBlockParameters, 86,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void multi_gadget_InitializeDataMapInfo(rtModel_multi_gadget *multi_gadget_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(multi_gadget_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(multi_gadget_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(multi_gadget_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(multi_gadget_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(multi_gadget_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(multi_gadget_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(multi_gadget_rtM->DataMapInfo.mmi, 0);
}

/* EOF: multi_gadget_capi.c */
