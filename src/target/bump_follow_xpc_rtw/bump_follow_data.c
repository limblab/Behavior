/*
 * bump_follow_data.c
 *
 * Real-Time Workshop code generation for Simulink model "bump_follow.mdl".
 *
 * Model Version              : 1.1247
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Mon Aug 02 10:27:51 2010
 */

#include "bump_follow.h"
#include "bump_follow_private.h"

/* Block parameters (auto storage) */
Parameters_bump_follow bump_follow_P = {
  10.0,                                /* Time_Value : '<S30>/Time'
                                        */

  /*  PCIQUAD04_P1_Size : '<S12>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCIQUAD04_P1 : '<S12>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P2_Size : '<S12>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P2 : '<S12>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P3_Size : '<S12>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P3 : '<S12>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P4_Size : '<S12>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P4 : '<S12>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P5_Size : '<S12>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P5 : '<S12>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P6_Size : '<S12>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD04_P6 : '<S12>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P7_Size : '<S12>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P7 : '<S12>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P8_Size : '<S12>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P8 : '<S12>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P9_Size : '<S12>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD04_P9 : '<S12>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P10_Size : '<S12>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.001,                               /* PCIQUAD04_P10 : '<S12>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P11_Size : '<S12>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCIQUAD04_P11 : '<S12>/PCI-QUAD04 '
                                        */
  0.0003490658,                        /* Gain_Gain : '<S12>/Gain'
                                        */
  0.0,                                 /* shoulderOffset_Value : '<S12>/shoulderOffset'
                                        */
  24.0,                                /* L1_Value : '<S70>/L1'
                                        */
  -1.0,                                /* Gain_Gain_e : '<S70>/Gain'
                                        */

  /*  PCIQUAD041_P1_Size : '<S12>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCIQUAD041_P1 : '<S12>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P2_Size : '<S12>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P2 : '<S12>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P3_Size : '<S12>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD041_P3 : '<S12>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P4_Size : '<S12>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P4 : '<S12>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P5_Size : '<S12>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD041_P5 : '<S12>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P6_Size : '<S12>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD041_P6 : '<S12>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P7_Size : '<S12>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P7 : '<S12>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P8_Size : '<S12>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P8 : '<S12>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P9_Size : '<S12>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD041_P9 : '<S12>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P10_Size : '<S12>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.001,                               /* PCIQUAD041_P10 : '<S12>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P11_Size : '<S12>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCIQUAD041_P11 : '<S12>/PCI-QUAD04 1'
                                        */
  -0.0003490658,                       /* Gain1_Gain : '<S12>/Gain1'
                                        */
  0.0,                                 /* elbowOffset_Value : '<S12>/elbowOffset'
                                        */
  23.5,                                /* L2_Value : '<S70>/L2'
                                        */
  -1.0,                                /* Gain1_Gain_o : '<S70>/Gain1'
                                        */
  -1.0,                                /* Gain2_Gain : '<S70>/Gain2'
                                        */

  /*  PCI6025EAD_P1_Size : '<S9>/PCI-6025E AD'
   */
  { 1.0, 2.0 },

  /*  PCI6025EAD_P1 : '<S9>/PCI-6025E AD'
   */
  { 1.0, 2.0 },

  /*  PCI6025EAD_P2_Size : '<S9>/PCI-6025E AD'
   */
  { 1.0, 2.0 },

  /*  PCI6025EAD_P2 : '<S9>/PCI-6025E AD'
   */
  { -10.0, -10.0 },

  /*  PCI6025EAD_P3_Size : '<S9>/PCI-6025E AD'
   */
  { 1.0, 2.0 },

  /*  PCI6025EAD_P3 : '<S9>/PCI-6025E AD'
   */
  { 0.0, 0.0 },

  /*  PCI6025EAD_P4_Size : '<S9>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  0.001,                               /* PCI6025EAD_P4 : '<S9>/PCI-6025E AD'
                                        */

  /*  PCI6025EAD_P5_Size : '<S9>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025EAD_P5 : '<S9>/PCI-6025E AD'
                                        */

  /*  PCI6025EAD_P6_Size : '<S9>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025EAD_P6 : '<S9>/PCI-6025E AD'
                                        */
  1.0,                                 /* UseTachs_Value : '<S9>/UseTachs'
                                        */
  32.0,                                /* yoffset_Value : '<S70>/yoffset'
                                        */
  1.0,                                 /* xoffset_Value : '<S70>/xoffset'
                                        */
  0.0,                                 /* AngleOffset_Value : '<S68>/AngleOffset'
                                        */
  0.0,                                 /* DigitalFilter2_ICRTP : '<S66>/Digital Filter2'
                                        */

  /*  DigitalFilter2_RTP1COEFF : '<S66>/Digital Filter2'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  1.0,                                 /* dG_Gain : '<S66>/dG'
                                        */
  0.0,                                 /* DigitalFilter_ICRTP : '<S66>/Digital Filter'
                                        */

  /*  DigitalFilter_RTP1COEFF : '<S66>/Digital Filter'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  0.0,                                 /* DigitalFilter2_ICRTP_h : '<S67>/Digital Filter2'
                                        */

  /*  DigitalFilter2_RTP1COEFF_e : '<S67>/Digital Filter2'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  1.0,                                 /* dG_Gain_l : '<S67>/dG'
                                        */
  0.0,                                 /* DigitalFilter_ICRTP_n : '<S67>/Digital Filter'
                                        */

  /*  DigitalFilter_RTP1COEFF_b : '<S67>/Digital Filter'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  0.5,                                 /* Switch_Threshold : '<S9>/Switch'
                                        */
  -30.0,                               /* XLowLimit_Value : '<S1>/XLowLimit'
                                        */
  25.0,                                /* XHighLimit_Value : '<S1>/XHighLimit'
                                        */
  -46.0,                               /* YHighLimit_Value : '<S1>/YHighLimit'
                                        */
  -22.0,                               /* YLowLimit_Value : '<S1>/YLowLimit'
                                        */
  1.0,                                 /* RecenterFlag_Value : '<S5>/RecenterFlag'
                                        */
  10.0,                                /* Time_Value_c : '<S46>/Time'
                                        */
  4.0,                                 /* Time_Value_o : '<S42>/Time'
                                        */
  0.004,                               /* Constant_Value : '<S50>/Constant'
                                        */
  0.004,                               /* Constant_Value_e : '<S51>/Constant'
                                        */
  0.5,                                 /* Time_Value_l : '<S44>/Time'
                                        */
  5.0,                                 /* Time_Value_i : '<S43>/Time'
                                        */
  0.0,                                 /* Load_Value : '<S3>/Load'
                                        */
  0.1,                                 /* x_X0 : '<S22>/x'
                                        */
  0.1,                                 /* x_X0_o : '<S23>/x'
                                        */
  0.1,                                 /* x_X0_h : '<S24>/x'
                                        */
  0.1,                                 /* x_X0_g : '<S25>/x'
                                        */
  0.0,                                 /* Load_Value_g : '<S2>/Load'
                                        */
  0.1,                                 /* x_X0_p : '<S16>/x'
                                        */
  0.1,                                 /* x_X0_k : '<S17>/x'
                                        */
  0.1,                                 /* x_X0_e : '<S18>/x'
                                        */
  0.1,                                 /* x_X0_c : '<S19>/x'
                                        */

  /*  BCStimTable_table : '<Root>/BCStimTable'
   */
  { -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0,
    -1.0, -1.0, -1.0, -1.0, -1.0, -1.0 },

  /*  BehaviorBF_P1_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorBF_P1 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P2_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  10.0,                                /* BehaviorBF_P2 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P3_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  3.0,                                 /* BehaviorBF_P3 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P4_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorBF_P4 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P5_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  2.0,                                 /* BehaviorBF_P5 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P6_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  5.0,                                 /* BehaviorBF_P6 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P7_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  7.0,                                 /* BehaviorBF_P7 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P8_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorBF_P8 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P9_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  0.05,                                /* BehaviorBF_P9 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P10_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  125.0,                               /* BehaviorBF_P10 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P11_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  0.5,                                 /* BehaviorBF_P11 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P12_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  2.0,                                 /* BehaviorBF_P12 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P13_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  10.0,                                /* BehaviorBF_P13 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P14_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorBF_P14 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P15_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  2.0,                                 /* BehaviorBF_P15 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P16_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorBF_P16 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P17_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorBF_P17 : '<Root>/Behavior BF'
                                        */

  /*  BehaviorBF_P18_Size : '<Root>/Behavior BF'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorBF_P18 : '<Root>/Behavior BF'
                                        */
  -1.0,                                /* MG1_Gain : '<S4>/MG1'
                                        */
  1.0,                                 /* MG2_Gain : '<S4>/MG2'
                                        */

  /*  PCI6025E_P1_Size : '<S4>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P1 : '<S4>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_Size : '<S4>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2 : '<S4>/PCI-6025E '
   */
  { -10.0, -10.0 },

  /*  PCI6025E_P3_Size : '<S4>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P3 : '<S4>/PCI-6025E '
   */
  { 1.0, 1.0 },

  /*  PCI6025E_P4_Size : '<S4>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P4 : '<S4>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  PCI6025E_P5_Size : '<S4>/PCI-6025E '
   */
  { 1.0, 1.0 },
  0.001,                               /* PCI6025E_P5 : '<S4>/PCI-6025E '
                                        */

  /*  PCI6025E_P6_Size : '<S4>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P6 : '<S4>/PCI-6025E '
                                        */

  /*  PCI6025E_P7_Size : '<S4>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P7 : '<S4>/PCI-6025E '
                                        */
  25.0,                                /* Constant_Value_d : '<S26>/Constant'
                                        */
  25.0,                                /* Constant_Value_a : '<S27>/Constant'
                                        */
  3.0,                                 /* Constant_Value_l : '<Root>/Constant'
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
  0.0,                                 /* UniformRandomNumber_Min : '<S6>/Uniform Random Number'
                                        */
  100.0,                               /* UniformRandomNumber_Max : '<S6>/Uniform Random Number'
                                        */
  0.0,                                 /* UniformRandomNumber_Seed : '<S6>/Uniform Random Number'
                                        */
  0.0,                                 /* JackpotChance_Value : '<S6>/JackpotChance'
                                        */
  0.1,                                 /* y_X0 : '<S16>/y'
                                        */
  28.0,                                /* rho_Value : '<S16>/rho'
                                        */
  0.1,                                 /* z_X0 : '<S16>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value : '<S16>/beta'
                                        */
  0.0001,                              /* timescale_Value : '<S16>/timescale'
                                        */
  10.0,                                /* sigma_Value : '<S16>/sigma'
                                        */
  0.2,                                 /* y_X0_e : '<S17>/y'
                                        */
  28.0,                                /* rho_Value_c : '<S17>/rho'
                                        */
  0.1,                                 /* z_X0_b : '<S17>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_c : '<S17>/beta'
                                        */
  0.0001,                              /* timescale_Value_p : '<S17>/timescale'
                                        */
  10.0,                                /* sigma_Value_c : '<S17>/sigma'
                                        */
  0.3,                                 /* y_X0_c : '<S18>/y'
                                        */
  28.0,                                /* rho_Value_a : '<S18>/rho'
                                        */
  0.1,                                 /* z_X0_c : '<S18>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_h : '<S18>/beta'
                                        */
  0.0001,                              /* timescale_Value_a : '<S18>/timescale'
                                        */
  10.0,                                /* sigma_Value_f : '<S18>/sigma'
                                        */
  0.4,                                 /* y_X0_ce : '<S19>/y'
                                        */
  28.0,                                /* rho_Value_e : '<S19>/rho'
                                        */
  0.1,                                 /* z_X0_d : '<S19>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_g : '<S19>/beta'
                                        */
  0.0001,                              /* timescale_Value_o : '<S19>/timescale'
                                        */
  10.0,                                /* sigma_Value_l : '<S19>/sigma'
                                        */
  0.1,                                 /* y_X0_p : '<S22>/y'
                                        */
  28.0,                                /* rho_Value_k : '<S22>/rho'
                                        */
  0.1,                                 /* z_X0_bq : '<S22>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_o : '<S22>/beta'
                                        */
  0.0001,                              /* timescale_Value_b : '<S22>/timescale'
                                        */
  10.0,                                /* sigma_Value_lo : '<S22>/sigma'
                                        */
  0.2,                                 /* y_X0_pj : '<S23>/y'
                                        */
  28.0,                                /* rho_Value_j : '<S23>/rho'
                                        */
  0.1,                                 /* z_X0_a : '<S23>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_hu : '<S23>/beta'
                                        */
  0.0001,                              /* timescale_Value_j : '<S23>/timescale'
                                        */
  10.0,                                /* sigma_Value_m : '<S23>/sigma'
                                        */
  0.3,                                 /* y_X0_g : '<S24>/y'
                                        */
  28.0,                                /* rho_Value_o : '<S24>/rho'
                                        */
  0.1,                                 /* z_X0_m : '<S24>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_oe : '<S24>/beta'
                                        */
  0.0001,                              /* timescale_Value_jr : '<S24>/timescale'
                                        */
  10.0,                                /* sigma_Value_n : '<S24>/sigma'
                                        */
  0.4,                                 /* y_X0_j : '<S25>/y'
                                        */
  28.0,                                /* rho_Value_ed : '<S25>/rho'
                                        */
  0.1,                                 /* z_X0_h : '<S25>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_m : '<S25>/beta'
                                        */
  0.0001,                              /* timescale_Value_c : '<S25>/timescale'
                                        */
  10.0,                                /* sigma_Value_j : '<S25>/sigma'
                                        */
  0.0367,                              /* Gain_Gain_m : '<S2>/Gain'
                                        */
  0.0,                                 /* visAngle_Value : '<S2>/visAngle'
                                        */
  0.0,                                 /* DynamicAngle_Value : '<S2>/DynamicAngle'
                                        */
  -1.0,                                /* Inverter_Gain : '<S15>/Inverter'
                                        */
  1.0,                                 /* Gain_Gain_l : '<S15>/Gain'
                                        */
  0.0005,                              /* LorentzForceGain_Gain : '<S2>/LorentzForceGain'
                                        */
  0.0,                                 /* staticX_Value : '<S2>/staticX'
                                        */
  0.0,                                 /* staticY_Value : '<S2>/staticY'
                                        */
  0.0,                                 /* Off_Value : '<S2>/Off'
                                        */
  0.0367,                              /* Gain_Gain_ex : '<S3>/Gain'
                                        */
  0.0,                                 /* visAngle_Value_d : '<S3>/visAngle'
                                        */
  0.0,                                 /* DynamicAngle_Value_l : '<S3>/DynamicAngle'
                                        */
  -1.0,                                /* Inverter_Gain_f : '<S21>/Inverter'
                                        */
  1.0,                                 /* Gain_Gain_j : '<S21>/Gain'
                                        */
  0.0005,                              /* LorentzForceGain_Gain_e : '<S3>/LorentzForceGain'
                                        */
  0.0,                                 /* staticX_Value_f : '<S3>/staticX'
                                        */
  0.0,                                 /* staticY_Value_h : '<S3>/staticY'
                                        */
  0.0,                                 /* Off_Value_g : '<S3>/Off'
                                        */
  -0.001,                              /* Gain1_Gain_d : '<S40>/Gain1'
                                        */
  -0.0002,                             /* Gain3_Gain : '<S40>/Gain3'
                                        */
  0.01,                                /* Saturation_UpperSat : '<S40>/Saturation'
                                        */
  -0.01,                               /* Saturation_LowerSat : '<S40>/Saturation'
                                        */
  -0.0002,                             /* Gain4_Gain : '<S40>/Gain4'
                                        */
  -0.001,                              /* Gain2_Gain_i : '<S40>/Gain2'
                                        */
  0.01,                                /* Saturation1_UpperSat : '<S40>/Saturation1'
                                        */
  -0.01,                               /* Saturation1_LowerSat : '<S40>/Saturation1'
                                        */
  -0.0001,                             /* BoundingBoxViscosity_Gain : '<S5>/Bounding Box Viscosity'
                                        */
  0.0,                                 /* zeroX_Value : '<S4>/zeroX'
                                        */
  0.0,                                 /* zeroY_Value : '<S4>/zeroY'
                                        */
  -1.0,                                /* Gain_Gain_n : '<S28>/Gain'
                                        */
  0.6,                                 /* RewardJackpot_Value : '<S6>/RewardJackpot'
                                        */
  0.3,                                 /* RewardTime_Value : '<S6>/RewardTime'
                                        */
  1.29,                                /* TachGain2_Gain : '<S9>/TachGain2'
                                        */
  1.29,                                /* TachGain1_Gain : '<S9>/TachGain1'
                                        */
  0.0,                                 /* Constant2_Value : '<S69>/Constant2'
                                        */
  0.0,                                 /* Constant1_Value : '<S71>/Constant1'
                                        */
  1.0,                                 /* Constant_Value_dj : '<S71>/Constant'
                                        */

  /*  xPCTargetTime_P1_Size : '<S71>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1 : '<S71>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size : '<S71>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2 : '<S71>/xPC Target  Time '
                                        */
  0.838,                               /* ScaleTouSec_Gain : '<S71>/ScaleTouSec'
                                        */
  100.0,                               /* Constant_Value_c : '<S73>/Constant'
                                        */

  /*  PCI6025E_P1_Size_j : '<S71>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P1_h : '<S71>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_Size_l : '<S71>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_n : '<S71>/PCI-6025E '
   */
  { 1.0, 1.0 },

  /*  PCI6025E_P3_Size_e : '<S71>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P3_l : '<S71>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  PCI6025E_P4_Size_a : '<S71>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P4_j : '<S71>/PCI-6025E '
                                        */

  /*  PCI6025E_P5_Size_h : '<S71>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P5_c : '<S71>/PCI-6025E '
                                        */

  /*  PCI6025E_P6_Size_p : '<S71>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P6_i : '<S71>/PCI-6025E '
                                        */

  /*  PCI6025E_P7_Size_i : '<S71>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P7_j : '<S71>/PCI-6025E '
                                        */
  200.0,                               /* Constant_Value_b : '<S72>/Constant'
                                        */
  2.0,                                 /* Switch_Threshold_m : '<S69>/Switch'
                                        */

  /*  PortA_P1_Size : '<S69>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P1 : '<S69>/Port A'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortA_P2_Size : '<S69>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P2 : '<S69>/Port A'
                                        */

  /*  PortA_P3_Size : '<S69>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P3 : '<S69>/Port A'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortA_P4_Size : '<S69>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P4 : '<S69>/Port A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortA_P5_Size : '<S69>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P5 : '<S69>/Port A'
                                        */

  /*  PortA_P6_Size : '<S69>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortA_P6 : '<S69>/Port A'
                                        */

  /*  PortA_P7_Size : '<S69>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortA_P7 : '<S69>/Port A'
                                        */

  /*  PortA_P8_Size : '<S69>/Port A'
   */
  { 1.0, 1.0 },
  137.0,                               /* PortA_P8 : '<S69>/Port A'
                                        */

  /*  PortA_P9_Size : '<S69>/Port A'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortA_P9 : '<S69>/Port A'
                                        */
  32768.0,                             /* Constant_Value_l1 : '<S69>/Constant'
                                        */

  /*  PortB_P1_Size : '<S69>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P1 : '<S69>/Port B'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortB_P2_Size : '<S69>/Port B'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PortB_P2 : '<S69>/Port B'
                                        */

  /*  PortB_P3_Size : '<S69>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P3 : '<S69>/Port B'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortB_P4_Size : '<S69>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P4 : '<S69>/Port B'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortB_P5_Size : '<S69>/Port B'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortB_P5 : '<S69>/Port B'
                                        */

  /*  PortB_P6_Size : '<S69>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortB_P6 : '<S69>/Port B'
                                        */

  /*  PortB_P7_Size : '<S69>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortB_P7 : '<S69>/Port B'
                                        */

  /*  PortB_P8_Size : '<S69>/Port B'
   */
  { 1.0, 1.0 },
  137.0,                               /* PortB_P8 : '<S69>/Port B'
                                        */

  /*  PortB_P9_Size : '<S69>/Port B'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortB_P9 : '<S69>/Port B'
                                        */

  /*  xPCTargetTime_P1_Size_a : '<S69>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1_f : '<S69>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size_k : '<S69>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2_m : '<S69>/xPC Target  Time '
                                        */
  1U,                                  /* PacketSpec_Value : '<S7>/Packet Spec'
                                        */
  4294443008U,                         /* NaNupperbytes_Value : '<S7>/NaN upper bytes'
                                        */
  0U,                                  /* DelayInput1_X0 : '<S60>/Delay Input1'
                                        */
  0U,                                  /* DelayInput1_X0_h : '<S45>/Delay Input1'
                                        */
  0U,                                  /* DelayInput1_X0_m : '<S38>/Delay Input1'
                                        */
  0U,                                  /* DelayInput1_X0_i : '<S37>/Delay Input1'
                                        */
  0,                                   /* Memory_X0 : '<S30>/Memory'
                                        */
  0,                                   /* Memory_X0_m : '<S4>/Memory'
                                        */
  0,                                   /* Memory_X0_n : '<S42>/Memory'
                                        */
  0,                                   /* Memory_X0_k : '<S46>/Memory'
                                        */
  0,                                   /* Memory_X0_p : '<S44>/Memory'
                                        */
  0,                                   /* Memory_X0_j : '<S43>/Memory'
                                        */
  0,                                   /* Memory_X0_e : '<S41>/Memory'
                                        */

  /*  Logic_table : '<S41>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },

  /* Start of '<S64>/Sample and Hold' */
  {
    -1000.0                            /* _Y0 : 'synthesized block'
                                        */
  }
  /* End of '<S64>/Sample and Hold' */
  ,

  /* Start of '<S6>/Sample and Hold' */
  {
    0.0                                /* _Y0 : 'synthesized block'
                                        */
  }
  /* End of '<S6>/Sample and Hold' */
};
