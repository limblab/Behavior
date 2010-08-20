/*
 * ball_drop_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "ball_drop.mdl".
 *
 * Model Version              : 1.117
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Thu Aug 19 16:14:26 2010
 */

#include "ball_drop.h"
#include "rtw_capi.h"
#include "ball_drop_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Behavior BD/p1",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Behavior BD/p2",
    "", 1, 0, 0, 0, 0 },

  { 2, 0, "Behavior BD/p3",
    "", 2, 0, 0, 0, 0 },

  { 3, 0, "Behavior BD/p4",
    "", 3, 0, 0, 0, 0 },

  { 4, 0, "Behavior BD/p5",
    "", 4, 0, 0, 0, 0 },

  { 5, 0, "Behavior BD/p6",
    "", 5, 0, 1, 0, 0 },

  { 6, 0, "Behavior BD/p7",
    "", 6, 0, 2, 0, 0 },

  { 7, 0, "Behavior BD/p8",
    "", 7, 0, 3, 0, 0 },

  { 8, 0, "Behavior BD/p9",
    "", 8, 0, 4, 0, 0 },

  { 9, 0, "PCI-6025E DI",
    "", 0, 0, 0, 0, 0 },

  { 10, 0, "Ball sensors/PCI-6025E AD/p1",
    "", 0, 0, 0, 0, 0 },

  { 11, 0, "Ball sensors/PCI-6025E AD/p2",
    "", 1, 0, 0, 0, 0 },

  { 12, 0, "Ball sensors/Switch",
    "", 0, 0, 0, 0, 0 },

  { 13, 0, "Ball sensors/Switch1",
    "", 0, 0, 0, 0, 0 },

  { 14, 0, "DeviceOutput/ToBits/p1",
    "", 0, 0, 0, 0, 0 },

  { 15, 0, "DeviceOutput/ToBits/p2",
    "", 1, 0, 0, 0, 0 },

  { 16, 0, "DeviceOutput/ToBits/p3",
    "", 2, 0, 0, 0, 0 },

  { 17, 0, "DeviceOutput/ToBits/p4",
    "", 3, 0, 0, 0, 0 },

  { 18, 0, "DeviceOutput/ToBits/p5",
    "", 4, 0, 0, 0, 0 },

  { 19, 0, "DeviceOutput/ToBits/p6",
    "", 5, 0, 0, 0, 0 },

  { 20, 0, "DeviceOutput/ToBits/p7",
    "", 6, 0, 0, 0, 0 },

  { 21, 0, "DeviceOutput/ToBits/p8",
    "", 7, 0, 0, 0, 0 },

  { 22, 0, "RewardSbs/Data Type Conversion",
    "", 0, 0, 0, 0, 1 },

  { 23, 0, "RewardSbs/Relational Operator",
    "", 0, 1, 0, 0, 0 },

  { 24, 0, "RewardSbs/Switch",
    "", 0, 0, 0, 0, 0 },

  { 25, 0, "RewardSbs/Uniform Random Number",
    "", 0, 0, 0, 0, 0 },

  { 26, 0, "UDPXmit/Rate Transition",
    "", 0, 2, 5, 0, 2 },

  { 27, 0, "UDPXmit/Pack",
    "", 0, 2, 5, 0, 0 },

  { 28, 9, "WordSbs/For Iterator",
    "", 0, 0, 0, 0, 3 },

  { 29, 9, "WordSbs/ToBits/p1",
    "", 0, 0, 0, 0, 3 },

  { 30, 9, "WordSbs/ToBits/p2",
    "", 1, 0, 0, 0, 3 },

  { 31, 9, "WordSbs/ToBits/p3",
    "", 2, 0, 0, 0, 3 },

  { 32, 9, "WordSbs/ToBits/p4",
    "", 3, 0, 0, 0, 3 },

  { 33, 9, "WordSbs/ToBits/p5",
    "", 4, 0, 0, 0, 3 },

  { 34, 9, "WordSbs/ToBits/p6",
    "", 5, 0, 0, 0, 3 },

  { 35, 9, "WordSbs/ToBits/p7",
    "", 6, 0, 0, 0, 3 },

  { 36, 9, "WordSbs/ToBits/p8",
    "", 7, 0, 0, 0, 3 },

  { 37, 9, "WordSbs/xPC Target  Time ",
    "", 0, 0, 0, 0, 3 },

  { 38, 9, "WordSbs/Switch",
    "", 0, 0, 0, 0, 3 },

  { 39, 3, "RewardSbs/Sample and Hold/In",
    "", 0, 0, 0, 0, 3 },

  { 40, 0, "RewardSbs/Schmidt/Clock",
    "", 0, 0, 0, 0, 1 },

  { 41, 0, "RewardSbs/Schmidt/Relational Operator",
    "", 0, 1, 0, 0, 1 },

  { 42, 0, "RewardSbs/Schmidt/Sum",
    "", 0, 0, 0, 0, 1 },

  { 43, 7, "WordSbs/Detect Change/FixPt Relational Operator",
    "", 0, 2, 0, 0, 3 },

  { 44, 9, "WordSbs/Detect Change/Delay Input1",
    "U(k-1)", 0, 0, 0, 0, 3 },

  { 45, 7, "WordSbs/Strobe // Reward Delay Subsystem/Data Type Conversion",
    "", 0, 0, 0, 0, 3 },

  { 46, 8, "WordSbs/Strobe // Reward Delay Subsystem/ScaleTouSec",
    "", 0, 0, 0, 0, 3 },

  { 47, 8, "WordSbs/Strobe // Reward Delay Subsystem/xPC Target  Time ",
    "", 0, 0, 0, 0, 3 },

  { 48, 8, "WordSbs/Strobe // Reward Delay Subsystem/Subtract",
    "", 0, 0, 0, 0, 3 },

  { 49, 8, "WordSbs/Strobe // Reward Delay Subsystem/Switch",
    "", 0, 0, 0, 0, 3 },

  { 50, 4, "RewardSbs/Schmidt/Sample and Hold/In",
    "", 0, 0, 0, 0, 3 },

  { 51, 8,
    "WordSbs/Strobe // Reward Delay Subsystem/Compare To Constant/Compare",
    "", 0, 1, 0, 0, 3 },

  { 52, 8,
    "WordSbs/Strobe // Reward Delay Subsystem/Compare To Constant1/Compare",
    "", 0, 1, 0, 0, 3 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 53, "Behavior BD",
    "P1", 0, 0, 0 },

  { 54, "Behavior BD",
    "P2", 0, 0, 0 },

  { 55, "Behavior BD",
    "P3", 0, 0, 0 },

  { 56, "Behavior BD",
    "P4", 0, 0, 0 },

  { 57, "Behavior BD",
    "P5", 0, 0, 0 },

  { 58, "Behavior BD",
    "P6", 0, 0, 0 },

  { 59, "Behavior BD",
    "P7", 0, 0, 0 },

  { 60, "Behavior BD",
    "P8", 0, 0, 0 },

  { 61, "Behavior BD",
    "P9", 0, 0, 0 },

  { 62, "PCI-6025E DI",
    "P1", 0, 0, 0 },

  { 63, "PCI-6025E DI",
    "P2", 0, 0, 0 },

  { 64, "PCI-6025E DI",
    "P3", 0, 0, 0 },

  { 65, "PCI-6025E DI",
    "P4", 0, 0, 0 },

  { 66, "PCI-6025E DI",
    "P5", 0, 0, 0 },

  { 67, "Ball sensors/Constant",
    "Value", 0, 0, 0 },

  { 68, "Ball sensors/Constant1",
    "Value", 0, 0, 0 },

  { 69, "Ball sensors/PCI-6025E AD",
    "P1", 0, 6, 0 },

  { 70, "Ball sensors/PCI-6025E AD",
    "P2", 0, 6, 0 },

  { 71, "Ball sensors/PCI-6025E AD",
    "P3", 0, 6, 0 },

  { 72, "Ball sensors/PCI-6025E AD",
    "P4", 0, 0, 0 },

  { 73, "Ball sensors/PCI-6025E AD",
    "P5", 0, 0, 0 },

  { 74, "Ball sensors/PCI-6025E AD",
    "P6", 0, 0, 0 },

  { 75, "Ball sensors/Switch",
    "Threshold", 0, 0, 0 },

  { 76, "Ball sensors/Switch1",
    "Threshold", 0, 0, 0 },

  { 77, "DeviceOutput/PCI-6025E DO",
    "P1", 0, 7, 0 },

  { 78, "DeviceOutput/PCI-6025E DO",
    "P2", 0, 7, 0 },

  { 79, "DeviceOutput/PCI-6025E DO",
    "P3", 0, 7, 0 },

  { 80, "DeviceOutput/PCI-6025E DO",
    "P4", 0, 0, 0 },

  { 81, "DeviceOutput/PCI-6025E DO",
    "P5", 0, 0, 0 },

  { 82, "DeviceOutput/PCI-6025E DO",
    "P6", 0, 0, 0 },

  { 83, "DeviceOutput/PCI-6025E DO",
    "P7", 0, 0, 0 },

  { 84, "RewardSbs/JackpotChance",
    "Value", 0, 0, 0 },

  { 85, "RewardSbs/RewardJackpot",
    "Value", 0, 0, 0 },

  { 86, "RewardSbs/RewardTime",
    "Value", 0, 0, 0 },

  { 87, "RewardSbs/Uniform Random Number",
    "Minimum", 0, 0, 0 },

  { 88, "RewardSbs/Uniform Random Number",
    "Maximum", 0, 0, 0 },

  { 89, "RewardSbs/Uniform Random Number",
    "Seed", 0, 0, 0 },

  { 90, "UDPXmit/Pos",
    "Value", 0, 0, 0 },

  { 91, "UDPXmit/Send",
    "P1", 0, 8, 0 },

  { 92, "UDPXmit/Send",
    "P2", 0, 0, 0 },

  { 93, "UDPXmit/Send",
    "P3", 0, 0, 0 },

  { 94, "UDPXmit/Send",
    "P4", 0, 0, 0 },

  { 95, "WordSbs/Constant",
    "Value", 0, 0, 0 },

  { 96, "WordSbs/Port A",
    "P1", 0, 9, 0 },

  { 97, "WordSbs/Port A",
    "P2", 0, 0, 0 },

  { 98, "WordSbs/Port A",
    "P3", 0, 9, 0 },

  { 99, "WordSbs/Port A",
    "P4", 0, 9, 0 },

  { 100, "WordSbs/Port A",
    "P5", 0, 0, 0 },

  { 101, "WordSbs/Port A",
    "P6", 0, 0, 0 },

  { 102, "WordSbs/Port A",
    "P7", 0, 0, 0 },

  { 103, "WordSbs/Port A",
    "P8", 0, 0, 0 },

  { 104, "WordSbs/Port A",
    "P9", 0, 0, 0 },

  { 105, "WordSbs/xPC Target  Time ",
    "P1", 0, 0, 0 },

  { 106, "WordSbs/xPC Target  Time ",
    "P2", 0, 0, 0 },

  { 107, "WordSbs/Switch",
    "Threshold", 0, 0, 0 },

  { 108, "WordSbs/Detect Change/Delay Input1",
    "X0", 0, 0, 0 },

  { 109, "WordSbs/Strobe // Reward Delay Subsystem/Constant1",
    "Value", 0, 0, 0 },

  { 110, "WordSbs/Strobe // Reward Delay Subsystem/ScaleTouSec",
    "Gain", 0, 0, 0 },

  { 111, "WordSbs/Strobe // Reward Delay Subsystem/PCI-6025E ",
    "P1", 0, 6, 0 },

  { 112, "WordSbs/Strobe // Reward Delay Subsystem/PCI-6025E ",
    "P2", 0, 6, 0 },

  { 113, "WordSbs/Strobe // Reward Delay Subsystem/PCI-6025E ",
    "P3", 0, 6, 0 },

  { 114, "WordSbs/Strobe // Reward Delay Subsystem/PCI-6025E ",
    "P4", 0, 0, 0 },

  { 115, "WordSbs/Strobe // Reward Delay Subsystem/PCI-6025E ",
    "P5", 0, 0, 0 },

  { 116, "WordSbs/Strobe // Reward Delay Subsystem/PCI-6025E ",
    "P6", 0, 0, 0 },

  { 117, "WordSbs/Strobe // Reward Delay Subsystem/PCI-6025E ",
    "P7", 0, 0, 0 },

  { 118, "WordSbs/Strobe // Reward Delay Subsystem/xPC Target  Time ",
    "P1", 0, 0, 0 },

  { 119, "WordSbs/Strobe // Reward Delay Subsystem/xPC Target  Time ",
    "P2", 0, 0, 0 },

  { 120, "WordSbs/Strobe // Reward Delay Subsystem/Compare To Constant/Constant",
    "Value", 0, 0, 0 },

  { 121,
    "WordSbs/Strobe // Reward Delay Subsystem/Compare To Constant1/Constant",
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
  &ball_drop_B.BehaviorBD_o1,          /* 0: Signal */
  &ball_drop_B.BehaviorBD_o2,          /* 1: Signal */
  &ball_drop_B.BehaviorBD_o3,          /* 2: Signal */
  &ball_drop_B.BehaviorBD_o4,          /* 3: Signal */
  &ball_drop_B.BehaviorBD_o5,          /* 4: Signal */
  &ball_drop_B.BehaviorBD_o6[0],       /* 5: Signal */
  &ball_drop_B.BehaviorBD_o7[0],       /* 6: Signal */
  &ball_drop_B.BehaviorBD_o8[0],       /* 7: Signal */
  &ball_drop_B.BehaviorBD_o9[0],       /* 8: Signal */
  &ball_drop_B.PCI6025EDI,             /* 9: Signal */
  &ball_drop_B.PCI6025EAD_o1,          /* 10: Signal */
  &ball_drop_B.PCI6025EAD_o2,          /* 11: Signal */
  &ball_drop_B.Switch,                 /* 12: Signal */
  &ball_drop_B.Switch1,                /* 13: Signal */
  &ball_drop_B.ToBits_o1,              /* 14: Signal */
  &ball_drop_B.ToBits_o2,              /* 15: Signal */
  &ball_drop_B.ToBits_o3,              /* 16: Signal */
  &ball_drop_B.ToBits_o4,              /* 17: Signal */
  &ball_drop_B.ToBits_o5,              /* 18: Signal */
  &ball_drop_B.ToBits_o6,              /* 19: Signal */
  &ball_drop_B.ToBits_o7,              /* 20: Signal */
  &ball_drop_B.ToBits_o8,              /* 21: Signal */
  &ball_drop_B.DataTypeConversion,     /* 22: Signal */
  &ball_drop_B.RelationalOperator,     /* 23: Signal */
  &ball_drop_B.Switch_h,               /* 24: Signal */
  &ball_drop_B.UniformRandomNumber,    /* 25: Signal */
  &ball_drop_B.RateTransition[0],      /* 26: Signal */
  &ball_drop_B.Pack[0],                /* 27: Signal */
  &ball_drop_B.ForIterator,            /* 28: Signal */
  &ball_drop_B.ToBits_o1_i,            /* 29: Signal */
  &ball_drop_B.ToBits_o2_h,            /* 30: Signal */
  &ball_drop_B.ToBits_o3_d,            /* 31: Signal */
  &ball_drop_B.ToBits_o4_j,            /* 32: Signal */
  &ball_drop_B.ToBits_o5_g,            /* 33: Signal */
  &ball_drop_B.ToBits_o6_i,            /* 34: Signal */
  &ball_drop_B.ToBits_o7_p,            /* 35: Signal */
  &ball_drop_B.ToBits_o8_h,            /* 36: Signal */
  &ball_drop_B.xPCTargetTime,          /* 37: Signal */
  &ball_drop_B.Switch_e,               /* 38: Signal */
  &ball_drop_B.SampleandHold_i.In,     /* 39: Signal */
  &ball_drop_B.Clock,                  /* 40: Signal */
  &ball_drop_B.RelationalOperator_c,   /* 41: Signal */
  &ball_drop_B.Sum,                    /* 42: Signal */
  &ball_drop_B.FixPtRelationalOperator,/* 43: Signal */
  &ball_drop_B.Uk1,                    /* 44: Signal */
  &ball_drop_B.DataTypeConversion_g,   /* 45: Signal */
  &ball_drop_B.ScaleTouSec,            /* 46: Signal */
  &ball_drop_B.xPCTargetTime_f,        /* 47: Signal */
  &ball_drop_B.Subtract,               /* 48: Signal */
  &ball_drop_B.Switch_g,               /* 49: Signal */
  &ball_drop_B.SampleandHold.In,       /* 50: Signal */
  &ball_drop_B.Compare_f,              /* 51: Signal */
  &ball_drop_B.Compare,                /* 52: Signal */
  &ball_drop_P.BehaviorBD_P1,          /* 53: Block Parameter */
  &ball_drop_P.BehaviorBD_P2,          /* 54: Block Parameter */
  &ball_drop_P.BehaviorBD_P3,          /* 55: Block Parameter */
  &ball_drop_P.BehaviorBD_P4,          /* 56: Block Parameter */
  &ball_drop_P.BehaviorBD_P5,          /* 57: Block Parameter */
  &ball_drop_P.BehaviorBD_P6,          /* 58: Block Parameter */
  &ball_drop_P.BehaviorBD_P7,          /* 59: Block Parameter */
  &ball_drop_P.BehaviorBD_P8,          /* 60: Block Parameter */
  &ball_drop_P.BehaviorBD_P9,          /* 61: Block Parameter */
  &ball_drop_P.PCI6025EDI_P1,          /* 62: Block Parameter */
  &ball_drop_P.PCI6025EDI_P2,          /* 63: Block Parameter */
  &ball_drop_P.PCI6025EDI_P3,          /* 64: Block Parameter */
  &ball_drop_P.PCI6025EDI_P4,          /* 65: Block Parameter */
  &ball_drop_P.PCI6025EDI_P5,          /* 66: Block Parameter */
  &ball_drop_P.Constant_Value,         /* 67: Block Parameter */
  &ball_drop_P.Constant1_Value,        /* 68: Block Parameter */
  &ball_drop_P.PCI6025EAD_P1[0],       /* 69: Block Parameter */
  &ball_drop_P.PCI6025EAD_P2[0],       /* 70: Block Parameter */
  &ball_drop_P.PCI6025EAD_P3[0],       /* 71: Block Parameter */
  &ball_drop_P.PCI6025EAD_P4,          /* 72: Block Parameter */
  &ball_drop_P.PCI6025EAD_P5,          /* 73: Block Parameter */
  &ball_drop_P.PCI6025EAD_P6,          /* 74: Block Parameter */
  &ball_drop_P.Switch_Threshold,       /* 75: Block Parameter */
  &ball_drop_P.Switch1_Threshold,      /* 76: Block Parameter */
  &ball_drop_P.PCI6025EDO_P1[0],       /* 77: Block Parameter */
  &ball_drop_P.PCI6025EDO_P2[0],       /* 78: Block Parameter */
  &ball_drop_P.PCI6025EDO_P3[0],       /* 79: Block Parameter */
  &ball_drop_P.PCI6025EDO_P4,          /* 80: Block Parameter */
  &ball_drop_P.PCI6025EDO_P5,          /* 81: Block Parameter */
  &ball_drop_P.PCI6025EDO_P6,          /* 82: Block Parameter */
  &ball_drop_P.PCI6025EDO_P7,          /* 83: Block Parameter */
  &ball_drop_P.JackpotChance_Value,    /* 84: Block Parameter */
  &ball_drop_P.RewardJackpot_Value,    /* 85: Block Parameter */
  &ball_drop_P.RewardTime_Value,       /* 86: Block Parameter */
  &ball_drop_P.UniformRandomNumber_Min,/* 87: Block Parameter */
  &ball_drop_P.UniformRandomNumber_Max,/* 88: Block Parameter */
  &ball_drop_P.UniformRandomNumber_Seed,/* 89: Block Parameter */
  &ball_drop_P.Pos_Value,              /* 90: Block Parameter */
  &ball_drop_P.Send_P1[0],             /* 91: Block Parameter */
  &ball_drop_P.Send_P2,                /* 92: Block Parameter */
  &ball_drop_P.Send_P3,                /* 93: Block Parameter */
  &ball_drop_P.Send_P4,                /* 94: Block Parameter */
  &ball_drop_P.Constant_Value_f,       /* 95: Block Parameter */
  &ball_drop_P.PortA_P1[0],            /* 96: Block Parameter */
  &ball_drop_P.PortA_P2,               /* 97: Block Parameter */
  &ball_drop_P.PortA_P3[0],            /* 98: Block Parameter */
  &ball_drop_P.PortA_P4[0],            /* 99: Block Parameter */
  &ball_drop_P.PortA_P5,               /* 100: Block Parameter */
  &ball_drop_P.PortA_P6,               /* 101: Block Parameter */
  &ball_drop_P.PortA_P7,               /* 102: Block Parameter */
  &ball_drop_P.PortA_P8,               /* 103: Block Parameter */
  &ball_drop_P.PortA_P9,               /* 104: Block Parameter */
  &ball_drop_P.xPCTargetTime_P1_f,     /* 105: Block Parameter */
  &ball_drop_P.xPCTargetTime_P2_c,     /* 106: Block Parameter */
  &ball_drop_P.Switch_Threshold_j,     /* 107: Block Parameter */
  &ball_drop_P.DelayInput1_X0,         /* 108: Block Parameter */
  &ball_drop_P.Constant1_Value_h,      /* 109: Block Parameter */
  &ball_drop_P.ScaleTouSec_Gain,       /* 110: Block Parameter */
  &ball_drop_P.PCI6025E_P1[0],         /* 111: Block Parameter */
  &ball_drop_P.PCI6025E_P2[0],         /* 112: Block Parameter */
  &ball_drop_P.PCI6025E_P3[0],         /* 113: Block Parameter */
  &ball_drop_P.PCI6025E_P4,            /* 114: Block Parameter */
  &ball_drop_P.PCI6025E_P5,            /* 115: Block Parameter */
  &ball_drop_P.PCI6025E_P6,            /* 116: Block Parameter */
  &ball_drop_P.PCI6025E_P7,            /* 117: Block Parameter */
  &ball_drop_P.xPCTargetTime_P1,       /* 118: Block Parameter */
  &ball_drop_P.xPCTargetTime_P2,       /* 119: Block Parameter */
  &ball_drop_P.Constant_Value_a,       /* 120: Block Parameter */
  &ball_drop_P.Constant_Value_n        /* 121: Block Parameter */
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
  { rtwCAPI_SCALAR, 0, 2 },

  { rtwCAPI_VECTOR, 2, 2 },

  { rtwCAPI_VECTOR, 4, 2 },

  { rtwCAPI_VECTOR, 6, 2 },

  { rtwCAPI_VECTOR, 8, 2 },

  { rtwCAPI_VECTOR, 10, 2 },

  { rtwCAPI_VECTOR, 12, 2 },

  { rtwCAPI_VECTOR, 14, 2 },

  { rtwCAPI_VECTOR, 16, 2 },

  { rtwCAPI_VECTOR, 18, 2 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  5,                                   /* 2 */
  1,                                   /* 3 */
  2,                                   /* 4 */
  1,                                   /* 5 */
  10,                                  /* 6 */
  1,                                   /* 7 */
  4,                                   /* 8 */
  1,                                   /* 9 */
  112,                                 /* 10 */
  1,                                   /* 11 */
  1,                                   /* 12 */
  2,                                   /* 13 */
  1,                                   /* 14 */
  4,                                   /* 15 */
  1,                                   /* 16 */
  11,                                  /* 17 */
  1,                                   /* 18 */
  8                                    /* 19 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0, 0.02
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
  { rtBlockSignals, 53 },

  { rtBlockParameters, 69,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void ball_drop_InitializeDataMapInfo(rtModel_ball_drop *ball_drop_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(ball_drop_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(ball_drop_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(ball_drop_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(ball_drop_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(ball_drop_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(ball_drop_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(ball_drop_rtM->DataMapInfo.mmi, 0);
}

/* EOF: ball_drop_capi.c */
