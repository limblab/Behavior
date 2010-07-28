/*
 * multi_gadget_data.c
 *
 * Real-Time Workshop code generation for Simulink model "multi_gadget.mdl".
 *
 * Model Version              : 1.82
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 14:02:34 2010
 */

#include "multi_gadget.h"
#include "multi_gadget_private.h"

/* Block parameters (auto storage) */
Parameters_multi_gadget multi_gadget_P = {
  /*  PCI6025EDI_P1_Size : '<Root>/PCI-6025E DI'
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025EDI_P1 : '<Root>/PCI-6025E DI'
                                        */

  /*  PCI6025EDI_P2_Size : '<Root>/PCI-6025E DI'
   */
  { 1.0, 1.0 },
  0.001,                               /* PCI6025EDI_P2 : '<Root>/PCI-6025E DI'
                                        */

  /*  PCI6025EDI_P3_Size : '<Root>/PCI-6025E DI'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025EDI_P3 : '<Root>/PCI-6025E DI'
                                        */

  /*  PCI6025EDI_P4_Size : '<Root>/PCI-6025E DI'
   */
  { 1.0, 1.0 },
  187.0,                               /* PCI6025EDI_P4 : '<Root>/PCI-6025E DI'
                                        */

  /*  PCI6025EDI_P5_Size : '<Root>/PCI-6025E DI'
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025EDI_P5 : '<Root>/PCI-6025E DI'
                                        */

  /*  PCI6025EAD_P1_Size : '<S1>/PCI-6025E AD'
   */
  { 1.0, 2.0 },

  /*  PCI6025EAD_P1 : '<S1>/PCI-6025E AD'
   */
  { 9.0, 10.0 },

  /*  PCI6025EAD_P2_Size : '<S1>/PCI-6025E AD'
   */
  { 1.0, 2.0 },

  /*  PCI6025EAD_P2 : '<S1>/PCI-6025E AD'
   */
  { -10.0, -10.0 },

  /*  PCI6025EAD_P3_Size : '<S1>/PCI-6025E AD'
   */
  { 1.0, 2.0 },

  /*  PCI6025EAD_P3 : '<S1>/PCI-6025E AD'
   */
  { 0.0, 0.0 },

  /*  PCI6025EAD_P4_Size : '<S1>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  0.001,                               /* PCI6025EAD_P4 : '<S1>/PCI-6025E AD'
                                        */

  /*  PCI6025EAD_P5_Size : '<S1>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025EAD_P5 : '<S1>/PCI-6025E AD'
                                        */

  /*  PCI6025EAD_P6_Size : '<S1>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025EAD_P6 : '<S1>/PCI-6025E AD'
                                        */
  12.0,                                /* NewtonCal1_Gain : '<S1>/NewtonCal1'
                                        */
  12.0,                                /* NewtonCal2_Gain : '<S1>/NewtonCal2'
                                        */

  /*  TargetTable_table : '<Root>/TargetTable'
   */
  { 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
    5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
    5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
    5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
    5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0,
    5.0, 5.0, 5.0, 5.0, 5.0 },

  /*  BehaviorMG_P1_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  3.0,                                 /* BehaviorMG_P1 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P2_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.25,                                /* BehaviorMG_P2 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P3_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.25,                                /* BehaviorMG_P3 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P4_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.5,                                 /* BehaviorMG_P4 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P5_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.5,                                 /* BehaviorMG_P5 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P6_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  5.0,                                 /* BehaviorMG_P6 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P7_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.5,                                 /* BehaviorMG_P7 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P8_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorMG_P8 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P9_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorMG_P9 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P10_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorMG_P10 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P11_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorMG_P11 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P12_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorMG_P12 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P13_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorMG_P13 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P14_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorMG_P14 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P15_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorMG_P15 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P16_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorMG_P16 : '<Root>/Behavior MG'
                                        */

  /*  BehaviorMG_P17_Size : '<Root>/Behavior MG'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorMG_P17 : '<Root>/Behavior MG'
                                        */

  /*  PCI6025EDO_P1_Size : '<S2>/PCI-6025E DO'
   */
  { 1.0, 4.0 },

  /*  PCI6025EDO_P1 : '<S2>/PCI-6025E DO'
   */
  { 4.0, 5.0, 6.0, 8.0 },

  /*  PCI6025EDO_P2_Size : '<S2>/PCI-6025E DO'
   */
  { 1.0, 4.0 },

  /*  PCI6025EDO_P2 : '<S2>/PCI-6025E DO'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /*  PCI6025EDO_P3_Size : '<S2>/PCI-6025E DO'
   */
  { 1.0, 4.0 },

  /*  PCI6025EDO_P3 : '<S2>/PCI-6025E DO'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  PCI6025EDO_P4_Size : '<S2>/PCI-6025E DO'
   */
  { 1.0, 1.0 },
  0.001,                               /* PCI6025EDO_P4 : '<S2>/PCI-6025E DO'
                                        */

  /*  PCI6025EDO_P5_Size : '<S2>/PCI-6025E DO'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025EDO_P5 : '<S2>/PCI-6025E DO'
                                        */

  /*  PCI6025EDO_P6_Size : '<S2>/PCI-6025E DO'
   */
  { 1.0, 1.0 },
  187.0,                               /* PCI6025EDO_P6 : '<S2>/PCI-6025E DO'
                                        */

  /*  PCI6025EDO_P7_Size : '<S2>/PCI-6025E DO'
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025EDO_P7 : '<S2>/PCI-6025E DO'
                                        */

  /*  Send_P1_Size : '<S7>/Send'
   */
  { 1.0, 11.0 },

  /*  Send_P1 : '<S7>/Send'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 48.0, 46.0, 50.0 },

  /*  Send_P2_Size : '<S7>/Send'
   */
  { 1.0, 1.0 },
  25000.0,                             /* Send_P2 : '<S7>/Send'
                                        */

  /*  Send_P3_Size : '<S7>/Send'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Send_P3 : '<S7>/Send'
                                        */

  /*  Send_P4_Size : '<S7>/Send'
   */
  { 1.0, 1.0 },
  0.02,                                /* Send_P4 : '<S7>/Send'
                                        */
  0.0,                                 /* UniformRandomNumber_Min : '<S4>/Uniform Random Number'
                                        */
  100.0,                               /* UniformRandomNumber_Max : '<S4>/Uniform Random Number'
                                        */
  0.0,                                 /* UniformRandomNumber_Seed : '<S4>/Uniform Random Number'
                                        */
  0.0,                                 /* JackpotChance_Value : '<S4>/JackpotChance'
                                        */
  0.6,                                 /* RewardJackpot_Value : '<S4>/RewardJackpot'
                                        */
  0.3,                                 /* RewardTime_Value : '<S4>/RewardTime'
                                        */
  0.0,                                 /* Constant_Value : '<S9>/Constant'
                                        */
  0.0,                                 /* StrobeLow_Value : '<S14>/StrobeLow'
                                        */
  1.0,                                 /* StobeHi_Value : '<S14>/StobeHi'
                                        */

  /*  xPCTargetTime_P1_Size : '<S14>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1 : '<S14>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size : '<S14>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2 : '<S14>/xPC Target  Time '
                                        */
  0.838,                               /* ScaleTouSec_Gain : '<S14>/ScaleTouSec'
                                        */
  100.0,                               /* Constant_Value_l : '<S16>/Constant'
                                        */

  /*  PCI6025E_P1_Size : '<S14>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P1 : '<S14>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_Size : '<S14>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2 : '<S14>/PCI-6025E '
   */
  { 1.0, 1.0 },

  /*  PCI6025E_P3_Size : '<S14>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P3 : '<S14>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  PCI6025E_P4_Size : '<S14>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P4 : '<S14>/PCI-6025E '
                                        */

  /*  PCI6025E_P5_Size : '<S14>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P5 : '<S14>/PCI-6025E '
                                        */

  /*  PCI6025E_P6_Size : '<S14>/PCI-6025E '
   */
  { 1.0, 1.0 },
  187.0,                               /* PCI6025E_P6 : '<S14>/PCI-6025E '
                                        */

  /*  PCI6025E_P7_Size : '<S14>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P7 : '<S14>/PCI-6025E '
                                        */
  200.0,                               /* Constant_Value_m : '<S15>/Constant'
                                        */

  /*  xPCTargetTime_P1_Size_b : '<S9>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1_k : '<S9>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size_o : '<S9>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2_l : '<S9>/xPC Target  Time '
                                        */
  1.0,                                 /* Switch_Threshold : '<S9>/Switch'
                                        */

  /*  PortA_P1_Size : '<S9>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P1 : '<S9>/Port A'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortA_P2_Size : '<S9>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P2 : '<S9>/Port A'
                                        */

  /*  PortA_P3_Size : '<S9>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P3 : '<S9>/Port A'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortA_P4_Size : '<S9>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P4 : '<S9>/Port A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortA_P5_Size : '<S9>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P5 : '<S9>/Port A'
                                        */

  /*  PortA_P6_Size : '<S9>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortA_P6 : '<S9>/Port A'
                                        */

  /*  PortA_P7_Size : '<S9>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortA_P7 : '<S9>/Port A'
                                        */

  /*  PortA_P8_Size : '<S9>/Port A'
   */
  { 1.0, 1.0 },
  137.0,                               /* PortA_P8 : '<S9>/Port A'
                                        */

  /*  PortA_P9_Size : '<S9>/Port A'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortA_P9 : '<S9>/Port A'
                                        */
  1000.0,                              /* toThousandths_Gain : '<S9>/toThousandths'
                                        */
  32768.0,                             /* Constant2_Value : '<S9>/Constant2'
                                        */

  /*  PortB_P1_Size : '<S9>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P1 : '<S9>/Port B'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortB_P2_Size : '<S9>/Port B'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PortB_P2 : '<S9>/Port B'
                                        */

  /*  PortB_P3_Size : '<S9>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P3 : '<S9>/Port B'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortB_P4_Size : '<S9>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P4 : '<S9>/Port B'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortB_P5_Size : '<S9>/Port B'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortB_P5 : '<S9>/Port B'
                                        */

  /*  PortB_P6_Size : '<S9>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortB_P6 : '<S9>/Port B'
                                        */

  /*  PortB_P7_Size : '<S9>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortB_P7 : '<S9>/Port B'
                                        */

  /*  PortB_P8_Size : '<S9>/Port B'
   */
  { 1.0, 1.0 },
  137.0,                               /* PortB_P8 : '<S9>/Port B'
                                        */

  /*  PortB_P9_Size : '<S9>/Port B'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortB_P9 : '<S9>/Port B'
                                        */

  /* Start of '<S12>/Sample and Hold' */
  {
    -1000.0                            /* _Y0 : 'synthesized block'
                                        */
  }
  /* End of '<S12>/Sample and Hold' */
  ,

  /* Start of '<S4>/Sample and Hold' */
  {
    0.0                                /* _Y0 : 'synthesized block'
                                        */
  }
  /* End of '<S4>/Sample and Hold' */
};
