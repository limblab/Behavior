/*
 * random_walk_data.c
 *
 * Real-Time Workshop code generation for Simulink model "random_walk.mdl".
 *
 * Model Version              : 1.922
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Jan 09 14:56:49 2008
 */

#include "random_walk.h"
#include "random_walk_private.h"

/* Block parameters (auto storage) */
Parameters_random_walk random_walk_P = {
  10.0,                                /* Time_Value : '<S10>/Time'
                                        */

  /*  PCIQUAD04_P1_Size : '<S15>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCIQUAD04_P1 : '<S15>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P2_Size : '<S15>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P2 : '<S15>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P3_Size : '<S15>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P3 : '<S15>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P4_Size : '<S15>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P4 : '<S15>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P5_Size : '<S15>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P5 : '<S15>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P6_Size : '<S15>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD04_P6 : '<S15>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P7_Size : '<S15>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P7 : '<S15>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P8_Size : '<S15>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P8 : '<S15>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P9_Size : '<S15>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD04_P9 : '<S15>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P10_Size : '<S15>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.001,                               /* PCIQUAD04_P10 : '<S15>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P11_Size : '<S15>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCIQUAD04_P11 : '<S15>/PCI-QUAD04 '
                                        */
  0.0003490658,                        /* Gain_Gain : '<S15>/Gain'
                                        */
  0.0,                                 /* shoulderOffset_Value : '<S15>/shoulderOffset'
                                        */

  /*  PCIQUAD041_P1_Size : '<S15>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCIQUAD041_P1 : '<S15>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P2_Size : '<S15>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P2 : '<S15>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P3_Size : '<S15>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD041_P3 : '<S15>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P4_Size : '<S15>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P4 : '<S15>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P5_Size : '<S15>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD041_P5 : '<S15>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P6_Size : '<S15>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD041_P6 : '<S15>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P7_Size : '<S15>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P7 : '<S15>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P8_Size : '<S15>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P8 : '<S15>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P9_Size : '<S15>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD041_P9 : '<S15>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P10_Size : '<S15>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.001,                               /* PCIQUAD041_P10 : '<S15>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P11_Size : '<S15>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCIQUAD041_P11 : '<S15>/PCI-QUAD04 1'
                                        */
  -0.0003490658,                       /* Gain1_Gain : '<S15>/Gain1'
                                        */
  0.0,                                 /* elbowOffset_Value : '<S15>/elbowOffset'
                                        */
  37.0,                                /* yoffset_Value : '<S59>/yoffset'
                                        */
  -2.0,                                /* xoffset_Value : '<S59>/xoffset'
                                        */
  0.0,                                 /* AngleOffset_Value : '<S57>/AngleOffset'
                                        */
  0.0,                                 /* DigitalFilter2_ICRTP : '<S7>/Digital Filter2'
                                        */

  /*  DigitalFilter2_RTP1COEFF : '<S7>/Digital Filter2'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  -0.0001,                             /* dG_Gain : '<S7>/dG'
                                        */
  0.0,                                 /* DigitalFilter_ICRTP : '<S7>/Digital Filter'
                                        */

  /*  DigitalFilter_RTP1COEFF : '<S7>/Digital Filter'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  0.0,                                 /* DigitalFilter2_ICRTP_p : '<S8>/Digital Filter2'
                                        */

  /*  DigitalFilter2_RTP1COEFF_k : '<S8>/Digital Filter2'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  -0.0001,                             /* dG_Gain_p : '<S8>/dG'
                                        */
  0.0,                                 /* DigitalFilter_ICRTP_f : '<S8>/Digital Filter'
                                        */

  /*  DigitalFilter_RTP1COEFF_h : '<S8>/Digital Filter'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  -30.0,                               /* XLowLimit_Value : '<S1>/XLowLimit'
                                        */
  25.0,                                /* XHighLimit_Value : '<S1>/XHighLimit'
                                        */
  -46.0,                               /* YHighLimit_Value : '<S1>/YHighLimit'
                                        */
  -22.0,                               /* YLowLimit_Value : '<S1>/YLowLimit'
                                        */
  10.0,                                /* Time_Value_c : '<S37>/Time'
                                        */
  6.0,                                 /* Time_Value_d : '<S35>/Time'
                                        */
  3.0,                                 /* Constant_Value : '<S38>/Constant'
                                        */
  0.001,                               /* Constant_Value_c : '<S40>/Constant'
                                        */
  3.0,                                 /* Constant_Value_h : '<S39>/Constant'
                                        */
  0.001,                               /* Constant_Value_n : '<S41>/Constant'
                                        */
  0.5,                                 /* Time_Value_k : '<S36>/Time'
                                        */
  0.0,                                 /* Load_Value : '<S4>/Load'
                                        */
  0.1,                                 /* x_X0 : '<S25>/x'
                                        */
  0.1,                                 /* x_X0_f : '<S26>/x'
                                        */
  0.1,                                 /* x_X0_fi : '<S27>/x'
                                        */
  0.1,                                 /* x_X0_i : '<S28>/x'
                                        */

  /*  BehaviorRW_P1_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  8.0,                                 /* BehaviorRW_P1 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P2_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  4.0,                                 /* BehaviorRW_P2 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P3_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  30.0,                                /* BehaviorRW_P3 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P4_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  30.0,                                /* BehaviorRW_P4 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P5_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P5 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P6_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P6 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P7_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  3.0,                                 /* BehaviorRW_P7 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P8_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  10.0,                                /* BehaviorRW_P8 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P9_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  3.0,                                 /* BehaviorRW_P9 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P10_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P10 : '<Root>/Behavior RW'
                                        */
  -1.0,                                /* MG2_Gain : '<Root>/MG2'
                                        */
  1.0,                                 /* MG1_Gain : '<Root>/MG1'
                                        */

  /*  PCI6025E_P1_Size : '<Root>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P1 : '<Root>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_Size : '<Root>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2 : '<Root>/PCI-6025E '
   */
  { -10.0, -10.0 },

  /*  PCI6025E_P3_Size : '<Root>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P3 : '<Root>/PCI-6025E '
   */
  { 1.0, 1.0 },

  /*  PCI6025E_P4_Size : '<Root>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P4 : '<Root>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  PCI6025E_P5_Size : '<Root>/PCI-6025E '
   */
  { 1.0, 1.0 },
  0.01,                                /* PCI6025E_P5 : '<Root>/PCI-6025E '
                                        */

  /*  PCI6025E_P6_Size : '<Root>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P6 : '<Root>/PCI-6025E '
   */
  { 0.0, 18.0 },

  /*  PCI6025E_P7_Size : '<Root>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P7 : '<Root>/PCI-6025E '
                                        */

  /*  Send_P1_Size : '<S13>/Send'
   */
  { 1.0, 11.0 },

  /*  Send_P1 : '<S13>/Send'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 48.0, 46.0, 50.0 },

  /*  Send_P2_Size : '<S13>/Send'
   */
  { 1.0, 1.0 },
  25000.0,                             /* Send_P2 : '<S13>/Send'
                                        */

  /*  Send_P3_Size : '<S13>/Send'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Send_P3 : '<S13>/Send'
                                        */

  /*  Send_P4_Size : '<S13>/Send'
   */
  { 1.0, 1.0 },
  0.02,                                /* Send_P4 : '<S13>/Send'
                                        */

  /*  PortA_P1_Size : '<S14>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P1 : '<S14>/Port A'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortA_P2_Size : '<S14>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P2 : '<S14>/Port A'
                                        */

  /*  PortA_P3_Size : '<S14>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P3 : '<S14>/Port A'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortA_P4_Size : '<S14>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P4 : '<S14>/Port A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortA_P5_Size : '<S14>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P5 : '<S14>/Port A'
                                        */

  /*  PortA_P6_Size : '<S14>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortA_P6 : '<S14>/Port A'
                                        */

  /*  PortA_P7_Size : '<S14>/Port A'
   */
  { 1.0, 2.0 },

  /*  PortA_P7 : '<S14>/Port A'
   */
  { 0.0, 16.0 },

  /*  PortA_P8_Size : '<S14>/Port A'
   */
  { 1.0, 1.0 },
  137.0,                               /* PortA_P8 : '<S14>/Port A'
                                        */

  /*  PortA_P9_Size : '<S14>/Port A'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortA_P9 : '<S14>/Port A'
                                        */
  0.1,                                 /* y_X0 : '<S25>/y'
                                        */
  28.0,                                /* rho_Value : '<S25>/rho'
                                        */
  0.1,                                 /* z_X0 : '<S25>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value : '<S25>/beta'
                                        */
  0.0001,                              /* timescale_Value : '<S25>/timescale'
                                        */
  10.0,                                /* sigma_Value : '<S25>/sigma'
                                        */
  0.2,                                 /* y_X0_l : '<S26>/y'
                                        */
  28.0,                                /* rho_Value_j : '<S26>/rho'
                                        */
  0.1,                                 /* z_X0_j : '<S26>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_g : '<S26>/beta'
                                        */
  0.0001,                              /* timescale_Value_p : '<S26>/timescale'
                                        */
  10.0,                                /* sigma_Value_h : '<S26>/sigma'
                                        */
  0.3,                                 /* y_X0_p : '<S27>/y'
                                        */
  28.0,                                /* rho_Value_e : '<S27>/rho'
                                        */
  0.1,                                 /* z_X0_l : '<S27>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_o : '<S27>/beta'
                                        */
  0.0001,                              /* timescale_Value_d : '<S27>/timescale'
                                        */
  10.0,                                /* sigma_Value_hc : '<S27>/sigma'
                                        */
  0.4,                                 /* y_X0_lz : '<S28>/y'
                                        */
  28.0,                                /* rho_Value_m : '<S28>/rho'
                                        */
  0.1,                                 /* z_X0_g : '<S28>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_e : '<S28>/beta'
                                        */
  0.0001,                              /* timescale_Value_h : '<S28>/timescale'
                                        */
  10.0,                                /* sigma_Value_m : '<S28>/sigma'
                                        */
  0.3,                                 /* Time_Value_f : '<S52>/Time'
                                        */
  1.0,                                 /* Constant_Value_a : '<S2>/Constant'
                                        */
  1.0,                                 /* Constant_Value_nk : '<S3>/Constant'
                                        */
  0.5,                                 /* Gain_Gain_g : '<S12>/Gain'
                                        */
  0.5,                                 /* Gain1_Gain_d : '<S12>/Gain1'
                                        */
  -0.001,                              /* Gain1_Gain_k : '<S5>/Gain1'
                                        */
  2.0,                                 /* Gain3_Gain : '<S5>/Gain3'
                                        */
  0.01,                                /* Saturation_UpperSat : '<S5>/Saturation'
                                        */
  -0.01,                               /* Saturation_LowerSat : '<S5>/Saturation'
                                        */
  2.0,                                 /* Gain4_Gain : '<S5>/Gain4'
                                        */
  -0.001,                              /* Gain2_Gain : '<S5>/Gain2'
                                        */
  0.01,                                /* Saturation1_UpperSat : '<S5>/Saturation1'
                                        */
  -0.01,                               /* Saturation1_LowerSat : '<S5>/Saturation1'
                                        */
  0.0,                                 /* zeroX_Value : '<Root>/zeroX'
                                        */
  0.0,                                 /* zeroY_Value : '<Root>/zeroY'
                                        */
  0.0367,                              /* Gain_Gain_p : '<S4>/Gain'
                                        */
  0.0,                                 /* visAngle_Value : '<S4>/visAngle'
                                        */
  0.0,                                 /* DynamicAngle_Value : '<S4>/DynamicAngle'
                                        */
  1.0,                                 /* Gain_Gain_go : '<S22>/Gain'
                                        */
  0.0005,                              /* LorentzForceGain_Gain : '<S4>/LorentzForceGain'
                                        */
  0.0,                                 /* staticX_Value : '<S4>/staticX'
                                        */
  0.0,                                 /* staticY_Value : '<S4>/staticY'
                                        */
  0.0,                                 /* Off_Value : '<S4>/Off'
                                        */
  0.0,                                 /* Constant1_Value : '<S60>/Constant1'
                                        */
  1.0,                                 /* Constant_Value_m : '<S60>/Constant'
                                        */

  /*  xPCTargetTime_P1_Size : '<S60>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1 : '<S60>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size : '<S60>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2 : '<S60>/xPC Target  Time '
                                        */
  0.838,                               /* ScaleTouSec_Gain : '<S60>/ScaleTouSec'
                                        */
  50.0,                                /* Constant_Value_o : '<S62>/Constant'
                                        */

  /*  PCI6025E_P1_Size_g : '<S60>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P1_o : '<S60>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_Size_i : '<S60>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_f : '<S60>/PCI-6025E '
   */
  { 1.0, 1.0 },

  /*  PCI6025E_P3_Size_h : '<S60>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P3_k : '<S60>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  PCI6025E_P4_Size_p : '<S60>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P4_i : '<S60>/PCI-6025E '
                                        */

  /*  PCI6025E_P5_Size_o : '<S60>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P5_h : '<S60>/PCI-6025E '
   */
  { 0.0, 16.0 },

  /*  PCI6025E_P6_Size_f : '<S60>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P6_n : '<S60>/PCI-6025E '
                                        */

  /*  PCI6025E_P7_Size_i : '<S60>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P7_e : '<S60>/PCI-6025E '
                                        */
  100.0,                               /* Constant_Value_ad : '<S61>/Constant'
                                        */
  32768.0,                             /* Constant_Value_j : '<S58>/Constant'
                                        */

  /*  PortB_P1_Size : '<S58>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P1 : '<S58>/Port B'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortB_P2_Size : '<S58>/Port B'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PortB_P2 : '<S58>/Port B'
                                        */

  /*  PortB_P3_Size : '<S58>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P3 : '<S58>/Port B'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortB_P4_Size : '<S58>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P4 : '<S58>/Port B'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortB_P5_Size : '<S58>/Port B'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortB_P5 : '<S58>/Port B'
                                        */

  /*  PortB_P6_Size : '<S58>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortB_P6 : '<S58>/Port B'
                                        */

  /*  PortB_P7_Size : '<S58>/Port B'
   */
  { 1.0, 2.0 },

  /*  PortB_P7 : '<S58>/Port B'
   */
  { 0.0, 16.0 },

  /*  PortB_P8_Size : '<S58>/Port B'
   */
  { 1.0, 1.0 },
  137.0,                               /* PortB_P8 : '<S58>/Port B'
                                        */

  /*  PortB_P9_Size : '<S58>/Port B'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortB_P9 : '<S58>/Port B'
                                        */

  /*  xPCTargetTime_P1_Size_j : '<S58>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1_e : '<S58>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size_h : '<S58>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2_h : '<S58>/xPC Target  Time '
                                        */
  0U,                                  /* DelayInput1_X0 : '<S49>/Delay Input1'
                                        */
  0U,                                  /* DelayInput1_X0_m : '<S32>/Delay Input1'
                                        */
  0U,                                  /* DelayInput1_X0_f : '<S33>/Delay Input1'
                                        */
  0,                                   /* Memory_X0 : '<S10>/Memory'
                                        */
  0,                                   /* Memory_X0_n : '<Root>/Memory'
                                        */
  0,                                   /* Memory_X0_g : '<S35>/Memory'
                                        */
  0,                                   /* Memory_X0_p : '<S37>/Memory'
                                        */
  0,                                   /* Memory_X0_np : '<S36>/Memory'
                                        */
  0,                                   /* Memory_X0_l : '<S34>/Memory'
                                        */

  /*  Logic_table : '<S34>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },
  0,                                   /* Memory1_X0 : '<S9>/Memory1'
                                        */
  0                                    /* Memory_X0_pd : '<S52>/Memory'
                                        */
};
