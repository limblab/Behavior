/*
 * forced_choice_data.c
 *
 * Real-Time Workshop code generation for Simulink model "forced_choice.mdl".
 *
 * Model Version              : 1.1203
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:24 2010
 */

#include "forced_choice.h"
#include "forced_choice_private.h"

/* Block parameters (auto storage) */
Parameters_forced_choice forced_choice_P = {
  10.0,                                /* Time_Value : '<S31>/Time'
                                        */

  /*  PCIQUAD04_P1_Size : '<S13>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCIQUAD04_P1 : '<S13>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P2_Size : '<S13>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P2 : '<S13>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P3_Size : '<S13>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P3 : '<S13>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P4_Size : '<S13>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P4 : '<S13>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P5_Size : '<S13>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD04_P5 : '<S13>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P6_Size : '<S13>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD04_P6 : '<S13>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P7_Size : '<S13>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P7 : '<S13>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P8_Size : '<S13>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD04_P8 : '<S13>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P9_Size : '<S13>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD04_P9 : '<S13>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P10_Size : '<S13>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.001,                               /* PCIQUAD04_P10 : '<S13>/PCI-QUAD04 '
                                        */

  /*  PCIQUAD04_P11_Size : '<S13>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCIQUAD04_P11 : '<S13>/PCI-QUAD04 '
                                        */
  0.0003490658,                        /* Gain_Gain : '<S13>/Gain'
                                        */
  0.0,                                 /* shoulderOffset_Value : '<S13>/shoulderOffset'
                                        */
  24.0,                                /* L1_Value : '<S71>/L1'
                                        */
  -1.0,                                /* Gain_Gain_m : '<S71>/Gain'
                                        */

  /*  PCIQUAD041_P1_Size : '<S13>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCIQUAD041_P1 : '<S13>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P2_Size : '<S13>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P2 : '<S13>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P3_Size : '<S13>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD041_P3 : '<S13>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P4_Size : '<S13>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P4 : '<S13>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P5_Size : '<S13>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PCIQUAD041_P5 : '<S13>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P6_Size : '<S13>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD041_P6 : '<S13>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P7_Size : '<S13>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P7 : '<S13>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P8_Size : '<S13>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PCIQUAD041_P8 : '<S13>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P9_Size : '<S13>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* PCIQUAD041_P9 : '<S13>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P10_Size : '<S13>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.001,                               /* PCIQUAD041_P10 : '<S13>/PCI-QUAD04 1'
                                        */

  /*  PCIQUAD041_P11_Size : '<S13>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCIQUAD041_P11 : '<S13>/PCI-QUAD04 1'
                                        */
  -0.0003490658,                       /* Gain1_Gain : '<S13>/Gain1'
                                        */
  0.0,                                 /* elbowOffset_Value : '<S13>/elbowOffset'
                                        */
  23.5,                                /* L2_Value : '<S71>/L2'
                                        */
  -1.0,                                /* Gain1_Gain_m : '<S71>/Gain1'
                                        */
  -1.0,                                /* Gain2_Gain : '<S71>/Gain2'
                                        */

  /*  PCI6025EAD_P1_Size : '<S10>/PCI-6025E AD'
   */
  { 1.0, 2.0 },

  /*  PCI6025EAD_P1 : '<S10>/PCI-6025E AD'
   */
  { 1.0, 2.0 },

  /*  PCI6025EAD_P2_Size : '<S10>/PCI-6025E AD'
   */
  { 1.0, 2.0 },

  /*  PCI6025EAD_P2 : '<S10>/PCI-6025E AD'
   */
  { -10.0, -10.0 },

  /*  PCI6025EAD_P3_Size : '<S10>/PCI-6025E AD'
   */
  { 1.0, 2.0 },

  /*  PCI6025EAD_P3 : '<S10>/PCI-6025E AD'
   */
  { 0.0, 0.0 },

  /*  PCI6025EAD_P4_Size : '<S10>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  0.001,                               /* PCI6025EAD_P4 : '<S10>/PCI-6025E AD'
                                        */

  /*  PCI6025EAD_P5_Size : '<S10>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025EAD_P5 : '<S10>/PCI-6025E AD'
                                        */

  /*  PCI6025EAD_P6_Size : '<S10>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025EAD_P6 : '<S10>/PCI-6025E AD'
                                        */
  1.0,                                 /* UseTachs_Value : '<S10>/UseTachs'
                                        */
  37.0,                                /* yoffset_Value : '<S71>/yoffset'
                                        */
  -2.0,                                /* xoffset_Value : '<S71>/xoffset'
                                        */
  0.0,                                 /* AngleOffset_Value : '<S69>/AngleOffset'
                                        */
  0.0,                                 /* DigitalFilter2_ICRTP : '<S67>/Digital Filter2'
                                        */

  /*  DigitalFilter2_RTP1COEFF : '<S67>/Digital Filter2'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  1.0,                                 /* dG_Gain : '<S67>/dG'
                                        */
  0.0,                                 /* DigitalFilter_ICRTP : '<S67>/Digital Filter'
                                        */

  /*  DigitalFilter_RTP1COEFF : '<S67>/Digital Filter'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  0.0,                                 /* DigitalFilter2_ICRTP_l : '<S68>/Digital Filter2'
                                        */

  /*  DigitalFilter2_RTP1COEFF_m : '<S68>/Digital Filter2'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  1.0,                                 /* dG_Gain_d : '<S68>/dG'
                                        */
  0.0,                                 /* DigitalFilter_ICRTP_h : '<S68>/Digital Filter'
                                        */

  /*  DigitalFilter_RTP1COEFF_p : '<S68>/Digital Filter'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  0.5,                                 /* Switch_Threshold : '<S10>/Switch'
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
  10.0,                                /* Time_Value_o : '<S47>/Time'
                                        */
  4.0,                                 /* Time_Value_n : '<S43>/Time'
                                        */
  0.004,                               /* Constant_Value : '<S51>/Constant'
                                        */
  0.004,                               /* Constant_Value_l : '<S52>/Constant'
                                        */
  0.5,                                 /* Time_Value_m : '<S45>/Time'
                                        */
  5.0,                                 /* Time_Value_c : '<S44>/Time'
                                        */
  0.0,                                 /* Load_Value : '<S3>/Load'
                                        */
  0.1,                                 /* x_X0 : '<S23>/x'
                                        */
  0.1,                                 /* x_X0_f : '<S24>/x'
                                        */
  0.1,                                 /* x_X0_l : '<S25>/x'
                                        */
  0.1,                                 /* x_X0_c : '<S26>/x'
                                        */
  0.0,                                 /* Load_Value_d : '<S2>/Load'
                                        */
  0.1,                                 /* x_X0_m : '<S17>/x'
                                        */
  0.1,                                 /* x_X0_j : '<S18>/x'
                                        */
  0.1,                                 /* x_X0_g : '<S19>/x'
                                        */
  0.1,                                 /* x_X0_lz : '<S20>/x'
                                        */

  /*  BehaviorFC_P1_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  16.0,                                /* BehaviorFC_P1 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P2_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  0.2,                                 /* BehaviorFC_P2 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P3_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorFC_P3 : '<Root>/Behavior FC'
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
  2.0,                                 /* BehaviorFC_P8 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P9_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  2.0,                                 /* BehaviorFC_P9 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P10_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  3.0,                                 /* BehaviorFC_P10 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P11_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  5.0,                                 /* BehaviorFC_P11 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P12_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorFC_P12 : '<Root>/Behavior FC'
                                        */

  /*  BehaviorFC_P13_Size : '<Root>/Behavior FC'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorFC_P13 : '<Root>/Behavior FC'
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
  25.0,                                /* Constant_Value_o : '<S27>/Constant'
                                        */
  25.0,                                /* Constant_Value_l0 : '<S28>/Constant'
                                        */

  /*  Send_P1_Size : '<S9>/Send'
   */
  { 1.0, 11.0 },

  /*  Send_P1 : '<S9>/Send'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 48.0, 46.0, 50.0 },

  /*  Send_P2_Size : '<S9>/Send'
   */
  { 1.0, 1.0 },
  25000.0,                             /* Send_P2 : '<S9>/Send'
                                        */

  /*  Send_P3_Size : '<S9>/Send'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Send_P3 : '<S9>/Send'
                                        */

  /*  Send_P4_Size : '<S9>/Send'
   */
  { 1.0, 1.0 },
  0.02,                                /* Send_P4 : '<S9>/Send'
                                        */
  0.0,                                 /* UniformRandomNumber_Min : '<S6>/Uniform Random Number'
                                        */
  100.0,                               /* UniformRandomNumber_Max : '<S6>/Uniform Random Number'
                                        */
  0.0,                                 /* UniformRandomNumber_Seed : '<S6>/Uniform Random Number'
                                        */
  0.0,                                 /* JackpotChance_Value : '<S6>/JackpotChance'
                                        */
  0.1,                                 /* y_X0 : '<S17>/y'
                                        */
  28.0,                                /* rho_Value : '<S17>/rho'
                                        */
  0.1,                                 /* z_X0 : '<S17>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value : '<S17>/beta'
                                        */
  0.0001,                              /* timescale_Value : '<S17>/timescale'
                                        */
  10.0,                                /* sigma_Value : '<S17>/sigma'
                                        */
  0.2,                                 /* y_X0_b : '<S18>/y'
                                        */
  28.0,                                /* rho_Value_e : '<S18>/rho'
                                        */
  0.1,                                 /* z_X0_o : '<S18>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_g : '<S18>/beta'
                                        */
  0.0001,                              /* timescale_Value_e : '<S18>/timescale'
                                        */
  10.0,                                /* sigma_Value_b : '<S18>/sigma'
                                        */
  0.3,                                 /* y_X0_o : '<S19>/y'
                                        */
  28.0,                                /* rho_Value_k : '<S19>/rho'
                                        */
  0.1,                                 /* z_X0_c : '<S19>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_h : '<S19>/beta'
                                        */
  0.0001,                              /* timescale_Value_m : '<S19>/timescale'
                                        */
  10.0,                                /* sigma_Value_g : '<S19>/sigma'
                                        */
  0.4,                                 /* y_X0_a : '<S20>/y'
                                        */
  28.0,                                /* rho_Value_d : '<S20>/rho'
                                        */
  0.1,                                 /* z_X0_g : '<S20>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_i : '<S20>/beta'
                                        */
  0.0001,                              /* timescale_Value_b : '<S20>/timescale'
                                        */
  10.0,                                /* sigma_Value_k : '<S20>/sigma'
                                        */
  0.1,                                 /* y_X0_b0 : '<S23>/y'
                                        */
  28.0,                                /* rho_Value_i : '<S23>/rho'
                                        */
  0.1,                                 /* z_X0_f : '<S23>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_gv : '<S23>/beta'
                                        */
  0.0001,                              /* timescale_Value_c : '<S23>/timescale'
                                        */
  10.0,                                /* sigma_Value_bo : '<S23>/sigma'
                                        */
  0.2,                                 /* y_X0_f : '<S24>/y'
                                        */
  28.0,                                /* rho_Value_dl : '<S24>/rho'
                                        */
  0.1,                                 /* z_X0_p : '<S24>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_b : '<S24>/beta'
                                        */
  0.0001,                              /* timescale_Value_j : '<S24>/timescale'
                                        */
  10.0,                                /* sigma_Value_e : '<S24>/sigma'
                                        */
  0.3,                                 /* y_X0_k : '<S25>/y'
                                        */
  28.0,                                /* rho_Value_h : '<S25>/rho'
                                        */
  0.1,                                 /* z_X0_n : '<S25>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_p : '<S25>/beta'
                                        */
  0.0001,                              /* timescale_Value_d : '<S25>/timescale'
                                        */
  10.0,                                /* sigma_Value_o : '<S25>/sigma'
                                        */
  0.4,                                 /* y_X0_h : '<S26>/y'
                                        */
  28.0,                                /* rho_Value_n : '<S26>/rho'
                                        */
  0.1,                                 /* z_X0_b : '<S26>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_e : '<S26>/beta'
                                        */
  0.0001,                              /* timescale_Value_f : '<S26>/timescale'
                                        */
  10.0,                                /* sigma_Value_k4 : '<S26>/sigma'
                                        */
  0.5,                                 /* Gain_Gain_i : '<S8>/Gain'
                                        */
  0.5,                                 /* Gain1_Gain_e : '<S8>/Gain1'
                                        */
  0.0367,                              /* Gain_Gain_n : '<S2>/Gain'
                                        */
  0.0,                                 /* visAngle_Value : '<S2>/visAngle'
                                        */
  0.0,                                 /* DynamicAngle_Value : '<S2>/DynamicAngle'
                                        */
  -1.0,                                /* Inverter_Gain : '<S16>/Inverter'
                                        */
  1.0,                                 /* Gain_Gain_l : '<S16>/Gain'
                                        */
  0.0005,                              /* LorentzForceGain_Gain : '<S2>/LorentzForceGain'
                                        */
  0.0,                                 /* staticX_Value : '<S2>/staticX'
                                        */
  0.0,                                 /* staticY_Value : '<S2>/staticY'
                                        */
  0.0,                                 /* Off_Value : '<S2>/Off'
                                        */
  0.0367,                              /* Gain_Gain_d : '<S3>/Gain'
                                        */
  0.0,                                 /* visAngle_Value_i : '<S3>/visAngle'
                                        */
  0.0,                                 /* DynamicAngle_Value_c : '<S3>/DynamicAngle'
                                        */
  -1.0,                                /* Inverter_Gain_l : '<S22>/Inverter'
                                        */
  1.0,                                 /* Gain_Gain_mk : '<S22>/Gain'
                                        */
  0.0005,                              /* LorentzForceGain_Gain_m : '<S3>/LorentzForceGain'
                                        */
  0.0,                                 /* staticX_Value_i : '<S3>/staticX'
                                        */
  0.0,                                 /* staticY_Value_o : '<S3>/staticY'
                                        */
  0.0,                                 /* Off_Value_j : '<S3>/Off'
                                        */
  -0.001,                              /* Gain1_Gain_k : '<S41>/Gain1'
                                        */
  -0.0002,                             /* Gain3_Gain : '<S41>/Gain3'
                                        */
  0.01,                                /* Saturation_UpperSat : '<S41>/Saturation'
                                        */
  -0.01,                               /* Saturation_LowerSat : '<S41>/Saturation'
                                        */
  -0.0002,                             /* Gain4_Gain : '<S41>/Gain4'
                                        */
  -0.001,                              /* Gain2_Gain_f : '<S41>/Gain2'
                                        */
  0.01,                                /* Saturation1_UpperSat : '<S41>/Saturation1'
                                        */
  -0.01,                               /* Saturation1_LowerSat : '<S41>/Saturation1'
                                        */
  -0.0001,                             /* BoundingBoxViscosity_Gain : '<S5>/Bounding Box Viscosity'
                                        */
  0.0,                                 /* zeroX_Value : '<S4>/zeroX'
                                        */
  0.0,                                 /* zeroY_Value : '<S4>/zeroY'
                                        */
  -1.0,                                /* Gain_Gain_a : '<S29>/Gain'
                                        */
  0.6,                                 /* RewardJackpot_Value : '<S6>/RewardJackpot'
                                        */
  0.3,                                 /* RewardTime_Value : '<S6>/RewardTime'
                                        */
  1.29,                                /* TachGain2_Gain : '<S10>/TachGain2'
                                        */
  1.29,                                /* TachGain1_Gain : '<S10>/TachGain1'
                                        */
  0.0,                                 /* Constant2_Value : '<S70>/Constant2'
                                        */
  0.0,                                 /* Constant1_Value : '<S72>/Constant1'
                                        */
  1.0,                                 /* Constant_Value_h : '<S72>/Constant'
                                        */

  /*  xPCTargetTime_P1_Size : '<S72>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1 : '<S72>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size : '<S72>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2 : '<S72>/xPC Target  Time '
                                        */
  0.838,                               /* ScaleTouSec_Gain : '<S72>/ScaleTouSec'
                                        */
  100.0,                               /* Constant_Value_m : '<S74>/Constant'
                                        */

  /*  PCI6025E_P1_Size_i : '<S72>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P1_f : '<S72>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_Size_e : '<S72>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_h : '<S72>/PCI-6025E '
   */
  { 1.0, 1.0 },

  /*  PCI6025E_P3_Size_l : '<S72>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P3_e : '<S72>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  PCI6025E_P4_Size_p : '<S72>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P4_g : '<S72>/PCI-6025E '
                                        */

  /*  PCI6025E_P5_Size_h : '<S72>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P5_h : '<S72>/PCI-6025E '
                                        */

  /*  PCI6025E_P6_Size_h : '<S72>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P6_f : '<S72>/PCI-6025E '
                                        */

  /*  PCI6025E_P7_Size_n : '<S72>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P7_g : '<S72>/PCI-6025E '
                                        */
  200.0,                               /* Constant_Value_m2 : '<S73>/Constant'
                                        */
  2.0,                                 /* Switch_Threshold_n : '<S70>/Switch'
                                        */

  /*  PortA_P1_Size : '<S70>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P1 : '<S70>/Port A'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortA_P2_Size : '<S70>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P2 : '<S70>/Port A'
                                        */

  /*  PortA_P3_Size : '<S70>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P3 : '<S70>/Port A'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortA_P4_Size : '<S70>/Port A'
   */
  { 1.0, 8.0 },

  /*  PortA_P4 : '<S70>/Port A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortA_P5_Size : '<S70>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortA_P5 : '<S70>/Port A'
                                        */

  /*  PortA_P6_Size : '<S70>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortA_P6 : '<S70>/Port A'
                                        */

  /*  PortA_P7_Size : '<S70>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortA_P7 : '<S70>/Port A'
                                        */

  /*  PortA_P8_Size : '<S70>/Port A'
   */
  { 1.0, 1.0 },
  137.0,                               /* PortA_P8 : '<S70>/Port A'
                                        */

  /*  PortA_P9_Size : '<S70>/Port A'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortA_P9 : '<S70>/Port A'
                                        */
  32768.0,                             /* Constant_Value_i : '<S70>/Constant'
                                        */

  /*  PortB_P1_Size : '<S70>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P1 : '<S70>/Port B'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  PortB_P2_Size : '<S70>/Port B'
   */
  { 1.0, 1.0 },
  2.0,                                 /* PortB_P2 : '<S70>/Port B'
                                        */

  /*  PortB_P3_Size : '<S70>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P3 : '<S70>/Port B'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  PortB_P4_Size : '<S70>/Port B'
   */
  { 1.0, 8.0 },

  /*  PortB_P4 : '<S70>/Port B'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  PortB_P5_Size : '<S70>/Port B'
   */
  { 1.0, 1.0 },
  1.0,                                 /* PortB_P5 : '<S70>/Port B'
                                        */

  /*  PortB_P6_Size : '<S70>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortB_P6 : '<S70>/Port B'
                                        */

  /*  PortB_P7_Size : '<S70>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* PortB_P7 : '<S70>/Port B'
                                        */

  /*  PortB_P8_Size : '<S70>/Port B'
   */
  { 1.0, 1.0 },
  137.0,                               /* PortB_P8 : '<S70>/Port B'
                                        */

  /*  PortB_P9_Size : '<S70>/Port B'
   */
  { 1.0, 1.0 },
  15.0,                                /* PortB_P9 : '<S70>/Port B'
                                        */

  /*  xPCTargetTime_P1_Size_p : '<S70>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1_a : '<S70>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size_d : '<S70>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2_g : '<S70>/xPC Target  Time '
                                        */
  0U,                                  /* DelayInput1_X0 : '<S61>/Delay Input1'
                                        */
  0U,                                  /* DelayInput1_X0_f : '<S46>/Delay Input1'
                                        */
  0U,                                  /* DelayInput1_X0_c : '<S39>/Delay Input1'
                                        */
  0U,                                  /* DelayInput1_X0_d : '<S38>/Delay Input1'
                                        */
  0,                                   /* Memory_X0 : '<S31>/Memory'
                                        */
  0,                                   /* Memory_X0_m : '<S4>/Memory'
                                        */
  0,                                   /* Memory_X0_n : '<S43>/Memory'
                                        */
  0,                                   /* Memory_X0_f : '<S47>/Memory'
                                        */
  0,                                   /* Memory_X0_e : '<S45>/Memory'
                                        */
  0,                                   /* Memory_X0_a : '<S44>/Memory'
                                        */
  0,                                   /* Memory_X0_k : '<S42>/Memory'
                                        */

  /*  Logic_table : '<S42>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },

  /* Start of '<S65>/Sample and Hold' */
  {
    -1000.0                            /* _Y0 : 'synthesized block'
                                        */
  }
  /* End of '<S65>/Sample and Hold' */
  ,

  /* Start of '<S6>/Sample and Hold' */
  {
    0.0                                /* _Y0 : 'synthesized block'
                                        */
  }
  /* End of '<S6>/Sample and Hold' */
};
