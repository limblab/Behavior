/*
 * forced_choice_data.c
 *
 * Real-Time Workshop code generation for Simulink model "forced_choice.mdl".
 *
 * Model Version              : 1.747
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Mon Dec 17 17:05:06 2007
 */

#include "forced_choice.h"
#include "forced_choice_private.h"

/* Block parameters (auto storage) */
Parameters_forced_choice forced_choice_P = {
  10.0,                                /* Time_Value : '<S9>/Time'
                                        */

  /*  PCIQUAD04_P1_Size : '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCIQUAD04_P1 : '<S14>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P2_Size : '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P2 : '<S14>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P3_Size : '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P3 : '<S14>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P4_Size : '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P4 : '<S14>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P5_Size : '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P5 : '<S14>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P6_Size : '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD04_P6 : '<S14>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P7_Size : '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P7 : '<S14>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P8_Size : '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P8 : '<S14>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P9_Size : '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD04_P9 : '<S14>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P10_Size : '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.001,                               /* PCIQUAD04_P10 : '<S14>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P11_Size : '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCIQUAD04_P11 : '<S14>/PCI-QUAD04 '
                                        */
  0.0003490658,                        /* Gain_Gain : '<S14>/Gain'
                                        */
  0.0,                                 /* shoulderOffset_Value : '<S14>/shoulderOffset'
                                        */

  /*  PCIQUAD041_P1_Size : '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCIQUAD041_P1 : '<S14>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P2_Size : '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P2 : '<S14>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P3_Size : '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD041_P3 : '<S14>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P4_Size : '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P4 : '<S14>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P5_Size : '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD041_P5 : '<S14>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P6_Size : '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD041_P6 : '<S14>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P7_Size : '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P7 : '<S14>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P8_Size : '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P8 : '<S14>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P9_Size : '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD041_P9 : '<S14>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P10_Size : '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.001,                               /* PCIQUAD041_P10 : '<S14>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P11_Size : '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCIQUAD041_P11 : '<S14>/PCI-QUAD04 1'
                                        */
  -0.0003490658,                       /* Gain1_Gain : '<S14>/Gain1'
                                        */
  0.0,                                 /* elbowOffset_Value : '<S14>/elbowOffset'
                                        */
  37.0,                                /* yoffset_Value : '<S35>/yoffset'
                                        */
  -2.0,                                /* xoffset_Value : '<S35>/xoffset'
                                        */
  0.0,                                 /* AngleOffset_Value : '<S33>/AngleOffset'
                                        */
  0.0,                                 /* DigitalFilter2_ICRTP : '<S6>/Digital Filter2'
                                        */

  /*  DigitalFilter2_RTP1COEFF : '<S6>/Digital Filter2'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  -0.0001,                             /* dG_Gain : '<S6>/dG'
                                        */
  0.0,                                 /* DigitalFilter_ICRTP : '<S6>/Digital Filter'
                                        */

  /*  DigitalFilter_RTP1COEFF : '<S6>/Digital Filter'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  0.0,                                 /* DigitalFilter2_ICRTP_c : '<S7>/Digital Filter2'
                                        */

  /*  DigitalFilter2_RTP1COEFF_a : '<S7>/Digital Filter2'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  -0.0001,                             /* dG_Gain_b : '<S7>/dG'
                                        */
  0.0,                                 /* DigitalFilter_ICRTP_c : '<S7>/Digital Filter'
                                        */

  /*  DigitalFilter_RTP1COEFF_n : '<S7>/Digital Filter'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  -20.0,                               /* XLowLimit_Value : '<S1>/XLowLimit'
                                        */
  25.0,                                /* XHighLimit_Value : '<S1>/XHighLimit'
                                        */
  -46.0,                               /* YHighLimit_Value : '<S1>/YHighLimit'
                                        */
  -18.0,                               /* YLowLimit_Value : '<S1>/YLowLimit'
                                        */
  0.0,                                 /* Load_Value : '<S4>/Load'
                                        */
  0.1,                                 /* x_X0 : '<S24>/x'
                                        */
  0.1,                                 /* x_X0_f : '<S25>/x'
                                        */
  0.1,                                 /* x_X0_l : '<S26>/x'
                                        */
  0.1,                                 /* x_X0_c : '<S27>/x'
                                        */

  /*  BehaviorFC_P1_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  3.0,                                 /* BehaviorFC_P1 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P2_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorFC_P2 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P3_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorFC_P3 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P4_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  0.5,                                 /* BehaviorFC_P4 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P5_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorFC_P5 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P6_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  0.5,                                 /* BehaviorFC_P6 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P7_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorFC_P7 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P8_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  10.0,                                /* BehaviorFC_P8 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P9_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  3.0,                                 /* BehaviorFC_P9 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P10_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  3.0,                                 /* BehaviorFC_P10 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P11_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  10.0,                                /* BehaviorFC_P11 : '<Root>/Behavior FC'
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

  /*  Send_P1_Size : '<S12>/Send'
   */
  { 1.0, 11.0 },

  /*  Send_P1 : '<S12>/Send'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 48.0, 46.0, 50.0 },

  /*  Send_P2_Size : '<S12>/Send'
   */
  { 1.0, 1.0 },
  25000.0,                             /* Send_P2 : '<S12>/Send'
                                        */

  /*  Send_P3_Size : '<S12>/Send'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Send_P3 : '<S12>/Send'
                                        */

  /*  Send_P4_Size : '<S12>/Send'
   */
  { 1.0, 1.0 },
  0.02,                                /* Send_P4 : '<S12>/Send'
                                        */

  /*  PortA_P1_Size : '<S13>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P1 : '<S13>/Port A'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortA_P2_Size : '<S13>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P2 : '<S13>/Port A'
                                        */

  /*  PortA_P3_Size : '<S13>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P3 : '<S13>/Port A'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortA_P4_Size : '<S13>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P4 : '<S13>/Port A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortA_P5_Size : '<S13>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P5 : '<S13>/Port A'
                                        */

  /*  PortA_P6_Size : '<S13>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortA_P6 : '<S13>/Port A'
                                        */

  /*  PortA_P7_Size : '<S13>/Port A'
   */
  { 1.0, 2.0 },

  /*  PortA_P7 : '<S13>/Port A'
   */
  { 0.0, 16.0 },

  /*  PortA_P8_Size : '<S13>/Port A'
   */
  { 1.0, 1.0 },
  137.0,                               /* PortA_P8 : '<S13>/Port A'
                                        */

  /*  PortA_P9_Size : '<S13>/Port A'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortA_P9 : '<S13>/Port A'
                                        */
  0.1,                                 /* y_X0 : '<S24>/y'
                                        */
  28.0,                                /* rho_Value : '<S24>/rho'
                                        */
  0.1,                                 /* z_X0 : '<S24>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value : '<S24>/beta'
                                        */
  0.0001,                              /* timescale_Value : '<S24>/timescale'
                                        */
  10.0,                                /* sigma_Value : '<S24>/sigma'
                                        */
  0.2,                                 /* y_X0_f : '<S25>/y'
                                        */
  28.0,                                /* rho_Value_d : '<S25>/rho'
                                        */
  0.1,                                 /* z_X0_p : '<S25>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_b : '<S25>/beta'
                                        */
  0.0001,                              /* timescale_Value_j : '<S25>/timescale'
                                        */
  10.0,                                /* sigma_Value_e : '<S25>/sigma'
                                        */
  0.3,                                 /* y_X0_k : '<S26>/y'
                                        */
  28.0,                                /* rho_Value_h : '<S26>/rho'
                                        */
  0.1,                                 /* z_X0_n : '<S26>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_p : '<S26>/beta'
                                        */
  0.0001,                              /* timescale_Value_d : '<S26>/timescale'
                                        */
  10.0,                                /* sigma_Value_o : '<S26>/sigma'
                                        */
  0.4,                                 /* y_X0_h : '<S27>/y'
                                        */
  28.0,                                /* rho_Value_n : '<S27>/rho'
                                        */
  0.1,                                 /* z_X0_b : '<S27>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_e : '<S27>/beta'
                                        */
  0.0001,                              /* timescale_Value_f : '<S27>/timescale'
                                        */
  10.0,                                /* sigma_Value_k : '<S27>/sigma'
                                        */
  0.3,                                 /* Time_Value_b : '<S28>/Time'
                                        */
  1.0,                                 /* Constant_Value : '<S2>/Constant'
                                        */
  1.0,                                 /* Constant_Value_d : '<S3>/Constant'
                                        */
  0.5,                                 /* Gain_Gain_i : '<S11>/Gain'
                                        */
  0.5,                                 /* Gain1_Gain_e : '<S11>/Gain1'
                                        */
  0.0,                                 /* zeroX_Value : '<Root>/zeroX'
                                        */
  0.0,                                 /* zeroY_Value : '<Root>/zeroY'
                                        */
  0.0367,                              /* Gain_Gain_d : '<S4>/Gain'
                                        */
  0.0,                                 /* visAngle_Value : '<S4>/visAngle'
                                        */
  0.0,                                 /* DynamicAngle_Value : '<S4>/DynamicAngle'
                                        */
  1.0,                                 /* Gain_Gain_m : '<S21>/Gain'
                                        */
  0.0005,                              /* LorentzForceGain_Gain : '<S4>/LorentzForceGain'
                                        */
  0.0,                                 /* staticX_Value : '<S4>/staticX'
                                        */
  0.0,                                 /* staticY_Value : '<S4>/staticY'
                                        */
  0.0,                                 /* Off_Value : '<S4>/Off'
                                        */
  0.0,                                 /* Constant1_Value : '<S36>/Constant1'
                                        */
  1.0,                                 /* Constant_Value_h : '<S36>/Constant'
                                        */

  /*  xPCTargetTime_P1_Size : '<S36>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1 : '<S36>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size : '<S36>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2 : '<S36>/xPC Target  Time '
                                        */
  0.838,                               /* ScaleTouSec_Gain : '<S36>/ScaleTouSec'
                                        */
  50.0,                                /* Constant_Value_m : '<S38>/Constant'
                                        */

  /*  PCI6025E_P1_Size_i : '<S36>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P1_f : '<S36>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_Size_e : '<S36>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_h : '<S36>/PCI-6025E '
   */
  { 1.0, 1.0 },

  /*  PCI6025E_P3_Size_l : '<S36>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P3_e : '<S36>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  PCI6025E_P4_Size_p : '<S36>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P4_g : '<S36>/PCI-6025E '
                                        */

  /*  PCI6025E_P5_Size_h : '<S36>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P5_h : '<S36>/PCI-6025E '
   */
  { 0.0, 16.0 },

  /*  PCI6025E_P6_Size_h : '<S36>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P6_f : '<S36>/PCI-6025E '
                                        */

  /*  PCI6025E_P7_Size_n : '<S36>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P7_g : '<S36>/PCI-6025E '
                                        */
  100.0,                               /* Constant_Value_m2 : '<S37>/Constant'
                                        */
  32768.0,                             /* Constant_Value_i : '<S34>/Constant'
                                        */

  /*  PortB_P1_Size : '<S34>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P1 : '<S34>/Port B'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortB_P2_Size : '<S34>/Port B'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PortB_P2 : '<S34>/Port B'
                                        */

  /*  PortB_P3_Size : '<S34>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P3 : '<S34>/Port B'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortB_P4_Size : '<S34>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P4 : '<S34>/Port B'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortB_P5_Size : '<S34>/Port B'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortB_P5 : '<S34>/Port B'
                                        */

  /*  PortB_P6_Size : '<S34>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortB_P6 : '<S34>/Port B'
                                        */

  /*  PortB_P7_Size : '<S34>/Port B'
   */
  { 1.0, 2.0 },

  /*  PortB_P7 : '<S34>/Port B'
   */
  { 0.0, 16.0 },

  /*  PortB_P8_Size : '<S34>/Port B'
   */
  { 1.0, 1.0 },
  137.0,                               /* PortB_P8 : '<S34>/Port B'
                                        */

  /*  PortB_P9_Size : '<S34>/Port B'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortB_P9 : '<S34>/Port B'
                                        */

  /*  xPCTargetTime_P1_Size_p : '<S34>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1_a : '<S34>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size_d : '<S34>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2_g : '<S34>/xPC Target  Time '
                                        */
  0,                                   /* Memory_X0 : '<S9>/Memory'
                                        */
  0,                                   /* Memory_X0_b : '<Root>/Memory'
                                        */
  0,                                   /* Memory1_X0 : '<S8>/Memory1'
                                        */
  0                                    /* Memory_X0_n : '<S28>/Memory'
                                        */
};
