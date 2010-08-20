/*
 * ball_drop_data.c
 *
 * Real-Time Workshop code generation for Simulink model "ball_drop.mdl".
 *
 * Model Version              : 1.117
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Thu Aug 19 16:14:26 2010
 */

#include "ball_drop.h"
#include "ball_drop_private.h"

/* Block parameters (auto storage) */
Parameters_ball_drop ball_drop_P = {
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
  1.0,                                 /* Constant_Value : '<S1>/Constant'
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
  0.0,                                 /* Constant1_Value : '<S1>/Constant1'
                                        */
  2.5,                                 /* Switch_Threshold : '<S1>/Switch'
                                        */
  2.5,                                 /* Switch1_Threshold : '<S1>/Switch1'
                                        */

  /*  BehaviorBD_P1_Size : '<Root>/Behavior BD'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorBD_P1 : '<Root>/Behavior BD'
                                        */

  /*  BehaviorBD_P2_Size : '<Root>/Behavior BD'
   */
  { 1.0, 1.0 },
  2.0,                                 /* BehaviorBD_P2 : '<Root>/Behavior BD'
                                        */

  /*  BehaviorBD_P3_Size : '<Root>/Behavior BD'
   */
  { 1.0, 1.0 },
  3.0,                                 /* BehaviorBD_P3 : '<Root>/Behavior BD'
                                        */

  /*  BehaviorBD_P4_Size : '<Root>/Behavior BD'
   */
  { 1.0, 1.0 },
  4.0,                                 /* BehaviorBD_P4 : '<Root>/Behavior BD'
                                        */

  /*  BehaviorBD_P5_Size : '<Root>/Behavior BD'
   */
  { 1.0, 1.0 },
  5.0,                                 /* BehaviorBD_P5 : '<Root>/Behavior BD'
                                        */

  /*  BehaviorBD_P6_Size : '<Root>/Behavior BD'
   */
  { 1.0, 1.0 },
  6.0,                                 /* BehaviorBD_P6 : '<Root>/Behavior BD'
                                        */

  /*  BehaviorBD_P7_Size : '<Root>/Behavior BD'
   */
  { 1.0, 1.0 },
  7.0,                                 /* BehaviorBD_P7 : '<Root>/Behavior BD'
                                        */

  /*  BehaviorBD_P8_Size : '<Root>/Behavior BD'
   */
  { 1.0, 1.0 },
  8.0,                                 /* BehaviorBD_P8 : '<Root>/Behavior BD'
                                        */

  /*  BehaviorBD_P9_Size : '<Root>/Behavior BD'
   */
  { 1.0, 1.0 },
  9.0,                                 /* BehaviorBD_P9 : '<Root>/Behavior BD'
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
  0.0,                                 /* Pos_Value : '<S6>/Pos'
                                        */

  /*  Send_P1_Size : '<S6>/Send'
   */
  { 1.0, 11.0 },

  /*  Send_P1 : '<S6>/Send'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 48.0, 46.0, 50.0 },

  /*  Send_P2_Size : '<S6>/Send'
   */
  { 1.0, 1.0 },
  25000.0,                             /* Send_P2 : '<S6>/Send'
                                        */

  /*  Send_P3_Size : '<S6>/Send'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Send_P3 : '<S6>/Send'
                                        */

  /*  Send_P4_Size : '<S6>/Send'
   */
  { 1.0, 1.0 },
  0.02,                                /* Send_P4 : '<S6>/Send'
                                        */
  0.0,                                 /* UniformRandomNumber_Min : '<S3>/Uniform Random Number'
                                        */
  100.0,                               /* UniformRandomNumber_Max : '<S3>/Uniform Random Number'
                                        */
  0.0,                                 /* UniformRandomNumber_Seed : '<S3>/Uniform Random Number'
                                        */
  0.0,                                 /* JackpotChance_Value : '<S3>/JackpotChance'
                                        */
  0.6,                                 /* RewardJackpot_Value : '<S3>/RewardJackpot'
                                        */
  0.3,                                 /* RewardTime_Value : '<S3>/RewardTime'
                                        */
  0.0,                                 /* Constant_Value_f : '<S8>/Constant'
                                        */
  0.0,                                 /* Constant1_Value_h : '<S14>/Constant1'
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
  100.0,                               /* Constant_Value_n : '<S16>/Constant'
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
  200.0,                               /* Constant_Value_a : '<S15>/Constant'
                                        */
  2.0,                                 /* Switch_Threshold_j : '<S8>/Switch'
                                        */

  /*  PortA_P1_Size : '<S8>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P1 : '<S8>/Port A'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortA_P2_Size : '<S8>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P2 : '<S8>/Port A'
                                        */

  /*  PortA_P3_Size : '<S8>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P3 : '<S8>/Port A'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortA_P4_Size : '<S8>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P4 : '<S8>/Port A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortA_P5_Size : '<S8>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P5 : '<S8>/Port A'
                                        */

  /*  PortA_P6_Size : '<S8>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortA_P6 : '<S8>/Port A'
                                        */

  /*  PortA_P7_Size : '<S8>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortA_P7 : '<S8>/Port A'
                                        */

  /*  PortA_P8_Size : '<S8>/Port A'
   */
  { 1.0, 1.0 },
  139.0,                               /* PortA_P8 : '<S8>/Port A'
                                        */

  /*  PortA_P9_Size : '<S8>/Port A'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortA_P9 : '<S8>/Port A'
                                        */

  /*  xPCTargetTime_P1_Size_a : '<S8>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1_f : '<S8>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size_c : '<S8>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2_c : '<S8>/xPC Target  Time '
                                        */
  0.0,                                 /* DelayInput1_X0 : '<S13>/Delay Input1'
                                        */

  /* Start of '<S11>/Sample and Hold' */
  {
    -1000.0                            /* _Y0 : 'synthesized block'
                                        */
  }
  /* End of '<S11>/Sample and Hold' */
  ,

  /* Start of '<S3>/Sample and Hold' */
  {
    0.0                                /* _Y0 : 'synthesized block'
                                        */
  }
  /* End of '<S3>/Sample and Hold' */
};
