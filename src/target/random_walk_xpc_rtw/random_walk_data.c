/*
 * random_walk_data.c
 *
 * Real-Time Workshop code generation for Simulink model "random_walk.mdl".
 *
 * Model Version              : 1.1211
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:40 2010
 */

#include "random_walk.h"
#include "random_walk_private.h"

/* Block parameters (auto storage) */
Parameters_random_walk random_walk_P = {
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
  -1.0,                                /* Gain_Gain_f : '<S71>/Gain'
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
  -1.0,                                /* Gain1_Gain_c : '<S71>/Gain1'
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
  0.0,                                 /* DigitalFilter2_ICRTP_f : '<S68>/Digital Filter2'
                                        */

  /*  DigitalFilter2_RTP1COEFF_f : '<S68>/Digital Filter2'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  1.0,                                 /* dG_Gain_d : '<S68>/dG'
                                        */
  0.0,                                 /* DigitalFilter_ICRTP_p : '<S68>/Digital Filter'
                                        */

  /*  DigitalFilter_RTP1COEFF_o : '<S68>/Digital Filter'
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
  10.0,                                /* Time_Value_l : '<S47>/Time'
                                        */
  4.0,                                 /* Time_Value_p : '<S43>/Time'
                                        */
  0.004,                               /* Constant_Value : '<S51>/Constant'
                                        */
  0.004,                               /* Constant_Value_e : '<S52>/Constant'
                                        */
  0.5,                                 /* Time_Value_m : '<S45>/Time'
                                        */
  5.0,                                 /* Time_Value_n : '<S44>/Time'
                                        */
  0.0,                                 /* Load_Value : '<S3>/Load'
                                        */
  0.1,                                 /* x_X0 : '<S23>/x'
                                        */
  0.1,                                 /* x_X0_f : '<S24>/x'
                                        */
  0.1,                                 /* x_X0_fi : '<S25>/x'
                                        */
  0.1,                                 /* x_X0_i : '<S26>/x'
                                        */
  0.0,                                 /* Load_Value_a : '<S2>/Load'
                                        */
  0.1,                                 /* x_X0_d : '<S17>/x'
                                        */
  0.1,                                 /* x_X0_p : '<S18>/x'
                                        */
  0.1,                                 /* x_X0_iy : '<S19>/x'
                                        */
  0.1,                                 /* x_X0_p3 : '<S20>/x'
                                        */

  /*  BehaviorRW_P1_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  8.0,                                 /* BehaviorRW_P1 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P2_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  3.0,                                 /* BehaviorRW_P2 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P3_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P3 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P4_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  -10.0,                               /* BehaviorRW_P4 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P5_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  10.0,                                /* BehaviorRW_P5 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P6_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  -10.0,                               /* BehaviorRW_P6 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P7_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  10.0,                                /* BehaviorRW_P7 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P8_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P8 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P9_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P9 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P10_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P10 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P11_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P11 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P12_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  10.0,                                /* BehaviorRW_P12 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P13_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  10.0,                                /* BehaviorRW_P13 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P14_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  1.0,                                 /* BehaviorRW_P14 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P15_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P15 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P16_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P16 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P17_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P17 : '<Root>/Behavior RW'
                                        */

  /*  BehaviorRW_P18_Size : '<Root>/Behavior RW'
   */
  { 1.0, 1.0 },
  0.0,                                 /* BehaviorRW_P18 : '<Root>/Behavior RW'
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
  25.0,                                /* Constant_Value_b : '<S27>/Constant'
                                        */
  25.0,                                /* Constant_Value_g : '<S28>/Constant'
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
  0.2,                                 /* y_X0_d : '<S18>/y'
                                        */
  28.0,                                /* rho_Value_a : '<S18>/rho'
                                        */
  0.1,                                 /* z_X0_c : '<S18>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_i : '<S18>/beta'
                                        */
  0.0001,                              /* timescale_Value_m : '<S18>/timescale'
                                        */
  10.0,                                /* sigma_Value_l : '<S18>/sigma'
                                        */
  0.3,                                 /* y_X0_e : '<S19>/y'
                                        */
  28.0,                                /* rho_Value_m : '<S19>/rho'
                                        */
  0.1,                                 /* z_X0_b : '<S19>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_p : '<S19>/beta'
                                        */
  0.0001,                              /* timescale_Value_d : '<S19>/timescale'
                                        */
  10.0,                                /* sigma_Value_j : '<S19>/sigma'
                                        */
  0.4,                                 /* y_X0_n : '<S20>/y'
                                        */
  28.0,                                /* rho_Value_e : '<S20>/rho'
                                        */
  0.1,                                 /* z_X0_a : '<S20>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_f : '<S20>/beta'
                                        */
  0.0001,                              /* timescale_Value_p : '<S20>/timescale'
                                        */
  10.0,                                /* sigma_Value_b : '<S20>/sigma'
                                        */
  0.1,                                 /* y_X0_g : '<S23>/y'
                                        */
  28.0,                                /* rho_Value_am : '<S23>/rho'
                                        */
  0.1,                                 /* z_X0_cv : '<S23>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_o : '<S23>/beta'
                                        */
  0.0001,                              /* timescale_Value_e : '<S23>/timescale'
                                        */
  10.0,                                /* sigma_Value_m : '<S23>/sigma'
                                        */
  0.2,                                 /* y_X0_l : '<S24>/y'
                                        */
  28.0,                                /* rho_Value_j : '<S24>/rho'
                                        */
  0.1,                                 /* z_X0_j : '<S24>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_g : '<S24>/beta'
                                        */
  0.0001,                              /* timescale_Value_py : '<S24>/timescale'
                                        */
  10.0,                                /* sigma_Value_h : '<S24>/sigma'
                                        */
  0.3,                                 /* y_X0_p : '<S25>/y'
                                        */
  28.0,                                /* rho_Value_eo : '<S25>/rho'
                                        */
  0.1,                                 /* z_X0_l : '<S25>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_o2 : '<S25>/beta'
                                        */
  0.0001,                              /* timescale_Value_dn : '<S25>/timescale'
                                        */
  10.0,                                /* sigma_Value_hc : '<S25>/sigma'
                                        */
  0.4,                                 /* y_X0_lz : '<S26>/y'
                                        */
  28.0,                                /* rho_Value_mm : '<S26>/rho'
                                        */
  0.1,                                 /* z_X0_g : '<S26>/z'
                                        */
  2.6666666666666665E+000,             /* beta_Value_e : '<S26>/beta'
                                        */
  0.0001,                              /* timescale_Value_h : '<S26>/timescale'
                                        */
  10.0,                                /* sigma_Value_mj : '<S26>/sigma'
                                        */
  0.5,                                 /* Gain_Gain_g : '<S8>/Gain'
                                        */
  0.5,                                 /* Gain1_Gain_d : '<S8>/Gain1'
                                        */
  0.0367,                              /* Gain_Gain_o : '<S2>/Gain'
                                        */
  0.0,                                 /* visAngle_Value : '<S2>/visAngle'
                                        */
  0.0,                                 /* DynamicAngle_Value : '<S2>/DynamicAngle'
                                        */
  -1.0,                                /* Inverter_Gain : '<S16>/Inverter'
                                        */
  1.0,                                 /* Gain_Gain_b : '<S16>/Gain'
                                        */
  0.0005,                              /* LorentzForceGain_Gain : '<S2>/LorentzForceGain'
                                        */
  0.0,                                 /* staticX_Value : '<S2>/staticX'
                                        */
  0.0,                                 /* staticY_Value : '<S2>/staticY'
                                        */
  0.0,                                 /* Off_Value : '<S2>/Off'
                                        */
  0.0367,                              /* Gain_Gain_p : '<S3>/Gain'
                                        */
  0.0,                                 /* visAngle_Value_n : '<S3>/visAngle'
                                        */
  0.0,                                 /* DynamicAngle_Value_h : '<S3>/DynamicAngle'
                                        */
  -1.0,                                /* Inverter_Gain_b : '<S22>/Inverter'
                                        */
  1.0,                                 /* Gain_Gain_go : '<S22>/Gain'
                                        */
  0.0005,                              /* LorentzForceGain_Gain_j : '<S3>/LorentzForceGain'
                                        */
  0.0,                                 /* staticX_Value_e : '<S3>/staticX'
                                        */
  0.0,                                 /* staticY_Value_a : '<S3>/staticY'
                                        */
  0.0,                                 /* Off_Value_d : '<S3>/Off'
                                        */
  -0.001,                              /* Gain1_Gain_p : '<S41>/Gain1'
                                        */
  -0.0002,                             /* Gain3_Gain : '<S41>/Gain3'
                                        */
  0.01,                                /* Saturation_UpperSat : '<S41>/Saturation'
                                        */
  -0.01,                               /* Saturation_LowerSat : '<S41>/Saturation'
                                        */
  -0.0002,                             /* Gain4_Gain : '<S41>/Gain4'
                                        */
  -0.001,                              /* Gain2_Gain_d : '<S41>/Gain2'
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
  -1.0,                                /* Gain_Gain_e : '<S29>/Gain'
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
  1.0,                                 /* Constant_Value_m : '<S72>/Constant'
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
  100.0,                               /* Constant_Value_o : '<S74>/Constant'
                                        */

  /*  PCI6025E_P1_Size_g : '<S72>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P1_o : '<S72>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_Size_i : '<S72>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P2_f : '<S72>/PCI-6025E '
   */
  { 1.0, 1.0 },

  /*  PCI6025E_P3_Size_h : '<S72>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  PCI6025E_P3_k : '<S72>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  PCI6025E_P4_Size_p : '<S72>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P4_i : '<S72>/PCI-6025E '
                                        */

  /*  PCI6025E_P5_Size_o : '<S72>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* PCI6025E_P5_h : '<S72>/PCI-6025E '
                                        */

  /*  PCI6025E_P6_Size_f : '<S72>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P6_n : '<S72>/PCI-6025E '
                                        */

  /*  PCI6025E_P7_Size_i : '<S72>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* PCI6025E_P7_e : '<S72>/PCI-6025E '
                                        */
  200.0,                               /* Constant_Value_a : '<S73>/Constant'
                                        */
  2.0,                                 /* Switch_Threshold_a : '<S70>/Switch'
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
  32768.0,                             /* Constant_Value_j : '<S70>/Constant'
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

  /*  xPCTargetTime_P1_Size_j : '<S70>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* xPCTargetTime_P1_e : '<S70>/xPC Target  Time '
                                        */

  /*  xPCTargetTime_P2_Size_h : '<S70>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* xPCTargetTime_P2_h : '<S70>/xPC Target  Time '
                                        */
  0U,                                  /* DelayInput1_X0 : '<S61>/Delay Input1'
                                        */
  0U,                                  /* DelayInput1_X0_k : '<S46>/Delay Input1'
                                        */
  0U,                                  /* DelayInput1_X0_j : '<S39>/Delay Input1'
                                        */
  0U,                                  /* DelayInput1_X0_a : '<S38>/Delay Input1'
                                        */
  0,                                   /* Memory_X0 : '<S31>/Memory'
                                        */
  0,                                   /* Memory_X0_e : '<S4>/Memory'
                                        */
  0,                                   /* Memory_X0_a : '<S43>/Memory'
                                        */
  0,                                   /* Memory_X0_i : '<S47>/Memory'
                                        */
  0,                                   /* Memory_X0_c : '<S45>/Memory'
                                        */
  0,                                   /* Memory_X0_p : '<S44>/Memory'
                                        */
  0,                                   /* Memory_X0_h : '<S42>/Memory'
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
