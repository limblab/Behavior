/*
 * wrist_flexion_data.c
 *
 * Real-Time Workshop code generation for Simulink model "wrist_flexion.mdl".
 *
 * Model Version              : 1.345
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 14:04:42 2010
 */

#include "wrist_flexion.h"
#include "wrist_flexion_private.h"

/* Block parameters (auto storage) */
Parameters_wrist_flexion wrist_flexion_P = {
  0.0,                                 /* ResetIntegrator_Value : '<S2>/ResetIntegrator'
                                        */
  0.0,                                 /* Integrator_IC : '<S2>/Integrator'
                                        */
  15.0,                                /* Integrator_UpperSat : '<S2>/Integrator'
                                        */
  -15.0,                               /* Integrator_LowerSat : '<S2>/Integrator'
                                        */
  0.0,                                 /* EnableIntegrator_Value : '<S2>/EnableIntegrator'
                                        */

  /*  LowPassFilterY_A : '<S2>/LowPassFilterY'
   */
  { -1.9615705608064609E+001, -1.0000000000000002E+001, 10.0, 10.0,
    -1.6629392246050905E+001, -10.0, 10.0, 10.0, -1.1111404660392040E+001, -10.0,
    9.9999999999999982E+000, 1.0000000000000002E+001, -3.9018064403225639E+000,
    -1.0000000000000002E+001, 9.9999999999999982E+000 },
  10.0,                                /* LowPassFilterY_B : '<S2>/LowPassFilterY'
                                        */
  1.0000000000000004E+000,             /* LowPassFilterY_C : '<S2>/LowPassFilterY'
                                        */
  0.0,                                 /* LowPassFilterY_X0 : '<S2>/LowPassFilterY'
                                        */
  0.0,                                 /* EnablePosFilter_Value : '<S2>/EnablePosFilter'
                                        */

  /*  PCI6025E_P1_Size : '<S2>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P1 : '<S2>/PCI-6025E '
   */
  { 9.0, 10.0 },

  /*  PCI6025E_P2_Size : '<S2>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2 : '<S2>/PCI-6025E '
   */
  { -10.0, -10.0 },

  /*  PCI6025E_P3_Size : '<S2>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P3 : '<S2>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  PCI6025E_P4_Size : '<S2>/PCI-6025E '
   */
  { 1.0, 1.0 },
  0.001,                               /* PCI6025E_P4 : '<S2>/PCI-6025E '
                                        */

  /*  PCI6025E_P5_Size : '<S2>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P5 : '<S2>/PCI-6025E '
                                        */

  /*  PCI6025E_P6_Size : '<S2>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P6 : '<S2>/PCI-6025E '
                                        */

  /*  Receive_P1_Size : '<S2>/Receive'
   */
  { 1.0, 7.0 },

  /*  Receive_P1 : '<S2>/Receive'
   */
  { 48.0, 46.0, 48.0, 46.0, 48.0, 46.0, 48.0 },

  /*  Receive_P2_Size : '<S2>/Receive'
   */
  { 1.0, 1.0 },
  24999.0,                             /* Receive_P2 : '<S2>/Receive'
                                        */

  /*  Receive_P3_Size : '<S2>/Receive'
   */
  { 1.0, 1.0 },
  16.0,                                /* Receive_P3 : '<S2>/Receive'
                                        */

  /*  Receive_P4_Size : '<S2>/Receive'
   */
  { 1.0, 1.0 },
  0.01,                                /* Receive_P4 : '<S2>/Receive'
                                        */
  1.0,                                 /* Constant1_Value : '<S10>/Constant1'
                                        */
  0.0,                                 /* OffsetY_Value : '<S2>/OffsetY'
                                        */
  15.0,                                /* GainY_Gain : '<S2>/GainY'
                                        */

  /*  LowPassFilterX_A : '<S2>/LowPassFilterX'
   */
  { -1.9615705608064609E+001, -1.0000000000000002E+001, 10.0, 10.0,
    -1.6629392246050905E+001, -10.0, 10.0, 10.0, -1.1111404660392040E+001, -10.0,
    9.9999999999999982E+000, 1.0000000000000002E+001, -3.9018064403225639E+000,
    -1.0000000000000002E+001, 9.9999999999999982E+000 },
  10.0,                                /* LowPassFilterX_B : '<S2>/LowPassFilterX'
                                        */
  1.0000000000000004E+000,             /* LowPassFilterX_C : '<S2>/LowPassFilterX'
                                        */
  0.0,                                 /* LowPassFilterX_X0 : '<S2>/LowPassFilterX'
                                        */
  0.0,                                 /* OffsetX_Value : '<S2>/OffsetX'
                                        */
  15.0,                                /* GainX_Gain : '<S2>/GainX'
                                        */
  0.0,                                 /* Memory_X0 : '<Root>/Memory'
                                        */

  /*  WFTargetTable_table : '<Root>/WFTargetTable'
   */
  { 5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 5.0, 5.0, 5.0,
    5.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0,
    5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 5.0, 5.0, 5.0,
    5.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0,
    5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 5.0, 5.0, 5.0,
    5.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0, 5.0, 5.0, 5.0, 5.0, 0.0, 0.0,
    5.0, 5.0, 5.0, 5.0, 0.0, 0.0 },

  /*  BehaviorWF_P1_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  8.0,                                 /* BehaviorWF_P1 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P2_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  5.0,                                 /* BehaviorWF_P2 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P3_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.5,                                 /* BehaviorWF_P3 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P4_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.5,                                 /* BehaviorWF_P4 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P5_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorWF_P5 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P6_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  2.0,                                 /* BehaviorWF_P6 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P7_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  2.0,                                 /* BehaviorWF_P7 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P8_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  2.0,                                 /* BehaviorWF_P8 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P9_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  2.0,                                 /* BehaviorWF_P9 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P10_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  2.0,                                 /* BehaviorWF_P10 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P11_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorWF_P11 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P12_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorWF_P12 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P13_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorWF_P13 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P14_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorWF_P14 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P15_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorWF_P15 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P16_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorWF_P16 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P17_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorWF_P17 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P18_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.7854,                              /* BehaviorWF_P18 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P19_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorWF_P19 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P20_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.5,                                 /* BehaviorWF_P20 : '<Root>/Behavior WF'
                                        */

  /*  BehaviorWF_P21_Size : '<Root>/Behavior WF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorWF_P21 : '<Root>/Behavior WF'
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
  0.0,                                 /* UniformRandomNumber_Min : '<S4>/Uniform Random Number'
                                        */
  100.0,                               /* UniformRandomNumber_Max : '<S4>/Uniform Random Number'
                                        */
  0.0,                                 /* UniformRandomNumber_Seed : '<S4>/Uniform Random Number'
                                        */
  0.0,                                 /* JackpotChance_Value : '<S4>/JackpotChance'
                                        */
  57.29578,                            /* Rad2Deg_Gain : '<Root>/Rad2Deg'
                                        */
  0.0,                                 /* NeuralControlPct_Value : '<S2>/NeuralControlPct'
                                        */
  100.0,                               /* Saturation_UpperSat : '<S2>/Saturation'
                                        */
  0.0,                                 /* Saturation_LowerSat : '<S2>/Saturation'
                                        */
  0.01,                                /* PctToFrac_Gain : '<S10>/PctToFrac'
                                        */
  0.0,                                 /* Constant_Value : '<S10>/Constant'
                                        */
  0.6,                                 /* RewardJackpot_Value : '<S4>/RewardJackpot'
                                        */
  0.3,                                 /* RewardTime_Value : '<S4>/RewardTime'
                                        */
  0.0,                                 /* Constant_Value_m : '<S8>/Constant'
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
  100.0,                               /* Constant_Value_h : '<S16>/Constant'
                                        */

  /*  PCI6025E_P1_Size_f : '<S14>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P1_m : '<S14>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_Size_o : '<S14>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_l : '<S14>/PCI-6025E '
   */
  { 1.0, 1.0 },

  /*  PCI6025E_P3_Size_g : '<S14>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P3_j : '<S14>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  PCI6025E_P4_Size_a : '<S14>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P4_b : '<S14>/PCI-6025E '
                                        */

  /*  PCI6025E_P5_Size_g : '<S14>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P5_d : '<S14>/PCI-6025E '
                                        */

  /*  PCI6025E_P6_Size_d : '<S14>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P6_o : '<S14>/PCI-6025E '
                                        */

  /*  PCI6025E_P7_Size : '<S14>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P7 : '<S14>/PCI-6025E '
                                        */
  200.0,                               /* Constant_Value_o : '<S15>/Constant'
                                        */
  1.0,                                 /* Switch_Threshold : '<S8>/Switch'
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
  137.0,                               /* PortA_P8 : '<S8>/Port A'
                                        */

  /*  PortA_P9_Size : '<S8>/Port A'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortA_P9 : '<S8>/Port A'
                                        */
  1000.0,                              /* toThousandths_Gain : '<S8>/toThousandths'
                                        */
  32768.0,                             /* Constant2_Value : '<S8>/Constant2'
                                        */

  /*  PortB_P1_Size : '<S8>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P1 : '<S8>/Port B'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortB_P2_Size : '<S8>/Port B'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PortB_P2 : '<S8>/Port B'
                                        */

  /*  PortB_P3_Size : '<S8>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P3 : '<S8>/Port B'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortB_P4_Size : '<S8>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P4 : '<S8>/Port B'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortB_P5_Size : '<S8>/Port B'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortB_P5 : '<S8>/Port B'
                                        */

  /*  PortB_P6_Size : '<S8>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortB_P6 : '<S8>/Port B'
                                        */

  /*  PortB_P7_Size : '<S8>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortB_P7 : '<S8>/Port B'
                                        */

  /*  PortB_P8_Size : '<S8>/Port B'
   */
  { 1.0, 1.0 },
  137.0,                               /* PortB_P8 : '<S8>/Port B'
                                        */

  /*  PortB_P9_Size : '<S8>/Port B'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortB_P9 : '<S8>/Port B'
                                        */

  /*  xPCTargetTime_P1_Size_d : '<S8>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1_a : '<S8>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size_j : '<S8>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2_b : '<S8>/xPC Target  Time '
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
