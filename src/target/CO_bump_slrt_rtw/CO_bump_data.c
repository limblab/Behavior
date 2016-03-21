/*
 * CO_bump_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CO_bump".
 *
 * Model version              : 1.1274
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 21 16:29:27 2016
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CO_bump.h"
#include "CO_bump_private.h"

/* Block parameters (auto storage) */
P_CO_bump_T CO_bump_P = {
  /*  Mask Parameter: DigitalFilter2_NumCoeffs
   * Referenced by: '<S69>/Digital Filter2'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },

  /*  Mask Parameter: DigitalFilter_NumCoeffs
   * Referenced by: '<S69>/Digital Filter'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },

  /*  Mask Parameter: DigitalFilter2_NumCoeffs_p
   * Referenced by: '<S70>/Digital Filter2'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },

  /*  Mask Parameter: DigitalFilter_NumCoeffs_j
   * Referenced by: '<S70>/Digital Filter'
   */
  { 0.0144, 0.0304, 0.0724, 0.1245, 0.1668, 0.183, 0.1668, 0.1245, 0.0724,
    0.0304, 0.0144 },
  10.0,                                /* Mask Parameter: Schmidt_Time
                                        * Referenced by: '<S33>/Time'
                                        */
  10.0,                                /* Mask Parameter: Timer_Time
                                        * Referenced by: '<S49>/Time'
                                        */
  4.0,                                 /* Mask Parameter: Schmidt1_Time
                                        * Referenced by: '<S45>/Time'
                                        */
  0.5,                                 /* Mask Parameter: Schmidt3_Time
                                        * Referenced by: '<S47>/Time'
                                        */
  5.0,                                 /* Mask Parameter: Schmidt2_Time
                                        * Referenced by: '<S46>/Time'
                                        */
  100.0,                               /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S81>/Constant'
                                        */
  125.0,                               /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S80>/Constant'
                                        */
  0.03,                                /* Mask Parameter: NoiseLevel_const
                                        * Referenced by: '<S83>/Constant'
                                        */
  0.004,                               /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S53>/Constant'
                                        */
  0.004,                               /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S54>/Constant'
                                        */
  250.0,                               /* Mask Parameter: CompareToConstant_const_l
                                        * Referenced by: '<S28>/Constant'
                                        */
  250.0,                               /* Mask Parameter: CompareToConstant1_const_a
                                        * Referenced by: '<S29>/Constant'
                                        */
  0.1,                                 /* Mask Parameter: Lorentz_y0
                                        * Referenced by: '<S18>/y'
                                        */
  0.2,                                 /* Mask Parameter: Lorentz1_y0
                                        * Referenced by: '<S19>/y'
                                        */
  0.3,                                 /* Mask Parameter: Lorentz2_y0
                                        * Referenced by: '<S20>/y'
                                        */
  0.4,                                 /* Mask Parameter: Lorentz3_y0
                                        * Referenced by: '<S21>/y'
                                        */
  0.1,                                 /* Mask Parameter: Lorentz_y0_e
                                        * Referenced by: '<S24>/y'
                                        */
  0.2,                                 /* Mask Parameter: Lorentz1_y0_o
                                        * Referenced by: '<S25>/y'
                                        */
  0.3,                                 /* Mask Parameter: Lorentz2_y0_h
                                        * Referenced by: '<S26>/y'
                                        */
  0.4,                                 /* Mask Parameter: Lorentz3_y0_m
                                        * Referenced by: '<S27>/y'
                                        */
  1000,                                /* Mask Parameter: CompareToConstant1_const_ah
                                        * Referenced by: '<S82>/Constant'
                                        */
  0U,                                  /* Mask Parameter: DetectFallNonpositive_vinit
                                        * Referenced by: '<S63>/Delay Input1'
                                        */
  0U,                                  /* Mask Parameter: StartMoving_vinit
                                        * Referenced by: '<S48>/Delay Input1'
                                        */
  0U,                                  /* Mask Parameter: FallingEdge1_vinit
                                        * Referenced by: '<S41>/Delay Input1'
                                        */
  0U,                                  /* Mask Parameter: FallingEdge_vinit
                                        * Referenced by: '<S40>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: SRFlipFlop_initial_condition
                                        * Referenced by: '<S44>/Memory'
                                        */
  0.0367,                              /* Expression: 0.0367
                                        * Referenced by: '<S2>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/visAngle'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/DynamicAngle'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S17>/Inverter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Gain'
                                        */
  0.0005,                              /* Expression: .0005
                                        * Referenced by: '<S2>/LorentzForceGain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/staticX'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/staticY'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Off'
                                        */
  0.0367,                              /* Expression: 0.0367
                                        * Referenced by: '<S3>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/visAngle'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/DynamicAngle'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S23>/Inverter'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S23>/Gain'
                                        */
  0.0005,                              /* Expression: .0005
                                        * Referenced by: '<S3>/LorentzForceGain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/staticX'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/staticY'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Off'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/GainM2Neg'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/GainM2Pos'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/GainM1Neg'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/GainM1Pos'
                                        */
  7.5,                                 /* Expression: 7.5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  -7.5,                                /* Expression: -7.5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  7.5,                                 /* Expression: 7.5
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  -7.5,                                /* Expression: -7.5
                                        * Referenced by: '<S4>/Saturation1'
                                        */

  /*  Expression: [0 0]
   * Referenced by: '<S4>/zero2'
   */
  { 0.0, 0.0 },
  -0.05,                               /* Expression: -.05
                                        * Referenced by: '<S43>/Gain1'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S43>/Saturation'
                                        */
  -3.0,                                /* Expression: -3
                                        * Referenced by: '<S43>/Saturation'
                                        */
  -0.03,                               /* Expression: -.03
                                        * Referenced by: '<S43>/Gain3'
                                        */
  -0.03,                               /* Expression: -.03
                                        * Referenced by: '<S43>/Gain4'
                                        */
  -0.05,                               /* Expression: -.05
                                        * Referenced by: '<S43>/Gain2'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<S43>/Saturation1'
                                        */
  -3.0,                                /* Expression: -3
                                        * Referenced by: '<S43>/Saturation1'
                                        */
  -0.08,                               /* Expression: -.08
                                        * Referenced by: '<S6>/Bounding Box Viscosity'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/zeroX'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/zeroY'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S32>/Gain'
                                        */
  0.6,                                 /* Expression: 0.60
                                        * Referenced by: '<S7>/RewardJackpot'
                                        */
  0.3,                                 /* Expression: 0.30
                                        * Referenced by: '<S7>/RewardTime'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/ReplaceIfYouWantToUseTachs2'
                                        */
  1.29,                                /* Expression: 1.29
                                        * Referenced by: '<S11>/TachGain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/ReplaceIfYouWantToUseTachs1'
                                        */
  1.29,                                /* Expression: 1.29
                                        * Referenced by: '<S11>/TachGain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/ForceToScreenGain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/UpsideDownHandle'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S75>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S79>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S79>/Constant'
                                        */

  /*  Computed Parameter: xPCTargetTime_P1_Size
   * Referenced by: '<S79>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: func
                                        * Referenced by: '<S79>/xPC Target  Time '
                                        */

  /*  Computed Parameter: xPCTargetTime_P2_Size
   * Referenced by: '<S79>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: ts
                                        * Referenced by: '<S79>/xPC Target  Time '
                                        */
  0.838,                               /* Expression: .838
                                        * Referenced by: '<S79>/ScaleTouSec'
                                        */

  /*  Computed Parameter: PCI6025E_P1_Size
   * Referenced by: '<S79>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<S79>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  Computed Parameter: PCI6025E_P2_Size
   * Referenced by: '<S79>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  Expression: reset
   * Referenced by: '<S79>/PCI-6025E '
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: PCI6025E_P3_Size
   * Referenced by: '<S79>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  Expression: initValue
   * Referenced by: '<S79>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: PCI6025E_P4_Size
   * Referenced by: '<S79>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */

  /*  Computed Parameter: PCI6025E_P5_Size
   * Referenced by: '<S79>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */

  /*  Computed Parameter: PCI6025E_P6_Size
   * Referenced by: '<S79>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: control
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */

  /*  Computed Parameter: PCI6025E_P7_Size
   * Referenced by: '<S79>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: boardType
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S75>/For Iterator'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S75>/Switch'
                                        */

  /*  Computed Parameter: PortA_P1_Size
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 8.0 },

  /*  Expression: channel
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  Computed Parameter: PortA_P2_Size
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: port
                                        * Referenced by: '<S75>/Port A'
                                        */

  /*  Computed Parameter: PortA_P3_Size
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 8.0 },

  /*  Expression: reset
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  Computed Parameter: PortA_P4_Size
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 8.0 },

  /*  Expression: initValue
   * Referenced by: '<S75>/Port A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: PortA_P5_Size
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S75>/Port A'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: PortA_P6_Size
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: chip
                                        * Referenced by: '<S75>/Port A'
                                        */

  /*  Computed Parameter: PortA_P7_Size
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S75>/Port A'
                                        */

  /*  Computed Parameter: PortA_P8_Size
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S75>/Port A'
                                        */

  /*  Computed Parameter: PortA_P9_Size
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 1.0 },
  137.0,                               /* Expression: control
                                        * Referenced by: '<S75>/Port A'
                                        */

  /*  Computed Parameter: PortA_P10_Size
   * Referenced by: '<S75>/Port A'
   */
  { 1.0, 1.0 },
  15.0,                                /* Expression: boardType
                                        * Referenced by: '<S75>/Port A'
                                        */
  32768.0,                             /* Expression: 32768
                                        * Referenced by: '<S75>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S75>/Memory'
                                        */

  /*  Computed Parameter: PortB_P1_Size
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 8.0 },

  /*  Expression: channel
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 },

  /*  Computed Parameter: PortB_P2_Size
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: port
                                        * Referenced by: '<S75>/Port B'
                                        */

  /*  Computed Parameter: PortB_P3_Size
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 8.0 },

  /*  Expression: reset
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  Computed Parameter: PortB_P4_Size
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 8.0 },

  /*  Expression: initValue
   * Referenced by: '<S75>/Port B'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: PortB_P5_Size
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 3.0 },

  /*  Expression: ival
   * Referenced by: '<S75>/Port B'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: PortB_P6_Size
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: chip
                                        * Referenced by: '<S75>/Port B'
                                        */

  /*  Computed Parameter: PortB_P7_Size
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: sampletime
                                        * Referenced by: '<S75>/Port B'
                                        */

  /*  Computed Parameter: PortB_P8_Size
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S75>/Port B'
                                        */

  /*  Computed Parameter: PortB_P9_Size
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 1.0 },
  137.0,                               /* Expression: control
                                        * Referenced by: '<S75>/Port B'
                                        */

  /*  Computed Parameter: PortB_P10_Size
   * Referenced by: '<S75>/Port B'
   */
  { 1.0, 1.0 },
  15.0,                                /* Expression: boardType
                                        * Referenced by: '<S75>/Port B'
                                        */

  /*  Computed Parameter: xPCTargetTime_P1_Size_n
   * Referenced by: '<S75>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: func
                                        * Referenced by: '<S75>/xPC Target  Time '
                                        */

  /*  Computed Parameter: xPCTargetTime_P2_Size_j
   * Referenced by: '<S75>/xPC Target  Time '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: ts
                                        * Referenced by: '<S75>/xPC Target  Time '
                                        */

  /*  Computed Parameter: Receive_P1_Size
   * Referenced by: '<S5>/Receive'
   */
  { 1.0, 7.0 },

  /*  Computed Parameter: Receive_P1
   * Referenced by: '<S5>/Receive'
   */
  { 48.0, 46.0, 48.0, 46.0, 48.0, 46.0, 48.0 },

  /*  Computed Parameter: Receive_P2_Size
   * Referenced by: '<S5>/Receive'
   */
  { 1.0, 1.0 },
  24999.0,                             /* Expression: ipPort
                                        * Referenced by: '<S5>/Receive'
                                        */

  /*  Computed Parameter: Receive_P3_Size
   * Referenced by: '<S5>/Receive'
   */
  { 1.0, 1.0 },
  48.0,                                /* Expression: width
                                        * Referenced by: '<S5>/Receive'
                                        */

  /*  Computed Parameter: Receive_P4_Size
   * Referenced by: '<S5>/Receive'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<S5>/Receive'
                                        */

  /*  Computed Parameter: Receive_P5_Size
   * Referenced by: '<S5>/Receive'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: vblLen
                                        * Referenced by: '<S5>/Receive'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Use Neural Control'
                                        */
  32.0,                                /* Expression: 32
                                        * Referenced by: '<S77>/yoffset'
                                        */

  /*  Computed Parameter: PCI6025EAD_P1_Size
   * Referenced by: '<S14>/PCI-6025E AD'
   */
  { 1.0, 6.0 },

  /*  Expression: channel
   * Referenced by: '<S14>/PCI-6025E AD'
   */
  { 11.0, 12.0, 13.0, 14.0, 15.0, 16.0 },

  /*  Computed Parameter: PCI6025EAD_P2_Size
   * Referenced by: '<S14>/PCI-6025E AD'
   */
  { 1.0, 6.0 },

  /*  Expression: range
   * Referenced by: '<S14>/PCI-6025E AD'
   */
  { -10.0, -10.0, -10.0, -10.0, -10.0, -10.0 },

  /*  Computed Parameter: PCI6025EAD_P3_Size
   * Referenced by: '<S14>/PCI-6025E AD'
   */
  { 1.0, 6.0 },

  /*  Expression: coupling
   * Referenced by: '<S14>/PCI-6025E AD'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: PCI6025EAD_P4_Size
   * Referenced by: '<S14>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */

  /*  Computed Parameter: PCI6025EAD_P5_Size
   * Referenced by: '<S14>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */

  /*  Computed Parameter: PCI6025EAD_P6_Size
   * Referenced by: '<S14>/PCI-6025E AD'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: boardType
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S78>/Unit Delay1'
                                        */
  49.0,                                /* Expression: 49
                                        * Referenced by: '<S78>/Gain'
                                        */
  0.02,                                /* Expression: 1/50
                                        * Referenced by: '<S78>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S78>/Memory'
                                        */
  -0.2059,                             /* Expression: -.2059
                                        * Referenced by: '<S14>/LoadCellYCoef1'
                                        */
  7.1801,                              /* Expression: 7.1801
                                        * Referenced by: '<S14>/LoadCellYCoef2'
                                        */
  -0.0804,                             /* Expression: -.0804
                                        * Referenced by: '<S14>/LoadCellYCoef3'
                                        */
  -3.591,                              /* Expression: -3.591
                                        * Referenced by: '<S14>/LoadCellYCoef4'
                                        */
  0.0641,                              /* Expression: 0.0641
                                        * Referenced by: '<S14>/LoadCellYCoef5'
                                        */
  -3.6077,                             /* Expression: -3.6077
                                        * Referenced by: '<S14>/LoadCellYCoef6'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S14>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S72>/Unit Delay'
                                        */
  16.0,                                /* Expression: 16
                                        * Referenced by: '<S72>/Gain'
                                        */
  0.058823529411764705,                /* Expression: 1/17
                                        * Referenced by: '<S72>/Gain1'
                                        */
  -0.0129,                             /* Expression: -.0129
                                        * Referenced by: '<S14>/LoadCellXCoef1'
                                        */
  -0.0254,                             /* Expression: -.0254
                                        * Referenced by: '<S14>/LoadCellXCoef2'
                                        */
  -0.1018,                             /* Expression: -.1018
                                        * Referenced by: '<S14>/LoadCellXCoef3'
                                        */
  -6.2876,                             /* Expression: -6.2876
                                        * Referenced by: '<S14>/LoadCellXCoef4'
                                        */
  -0.1127,                             /* Expression: -.1127
                                        * Referenced by: '<S14>/LoadCellXCoef5'
                                        */
  6.2163,                              /* Expression: 6.2163
                                        * Referenced by: '<S14>/LoadCellXCoef6'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S14>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S71>/Unit Delay'
                                        */
  16.0,                                /* Expression: 16
                                        * Referenced by: '<S71>/Gain'
                                        */
  0.058823529411764705,                /* Expression: 1/17
                                        * Referenced by: '<S71>/Gain1'
                                        */

  /*  Computed Parameter: PCIQUAD041_P1_Size
   * Referenced by: '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: convbaseaddr
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */

  /*  Computed Parameter: PCIQUAD041_P2_Size
   * Referenced by: '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: channel
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */

  /*  Computed Parameter: PCIQUAD041_P3_Size
   * Referenced by: '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: resetmode
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */

  /*  Computed Parameter: PCIQUAD041_P4_Size
   * Referenced by: '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: polarity
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */

  /*  Computed Parameter: PCIQUAD041_P5_Size
   * Referenced by: '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: mode
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */

  /*  Computed Parameter: PCIQUAD041_P6_Size
   * Referenced by: '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: limit
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */

  /*  Computed Parameter: PCIQUAD041_P7_Size
   * Referenced by: '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: range
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */

  /*  Computed Parameter: PCIQUAD041_P8_Size
   * Referenced by: '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: speed
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */

  /*  Computed Parameter: PCIQUAD041_P9_Size
   * Referenced by: '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: prescale
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */

  /*  Computed Parameter: PCIQUAD041_P10_Size
   * Referenced by: '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: ts
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */

  /*  Computed Parameter: PCIQUAD041_P11_Size
   * Referenced by: '<S14>/PCI-QUAD04 1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  -0.0003490658,                       /* Expression: -3.490658e-4
                                        * Referenced by: '<S14>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/elbowOffset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S77>/xoffset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S74>/AngleOffset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/IsometricMode'
                                        */

  /*  Computed Parameter: PCIQUAD04_P1_Size
   * Referenced by: '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: convbaseaddr
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */

  /*  Computed Parameter: PCIQUAD04_P2_Size
   * Referenced by: '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */

  /*  Computed Parameter: PCIQUAD04_P3_Size
   * Referenced by: '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: resetmode
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */

  /*  Computed Parameter: PCIQUAD04_P4_Size
   * Referenced by: '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: polarity
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */

  /*  Computed Parameter: PCIQUAD04_P5_Size
   * Referenced by: '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: mode
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */

  /*  Computed Parameter: PCIQUAD04_P6_Size
   * Referenced by: '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: limit
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */

  /*  Computed Parameter: PCIQUAD04_P7_Size
   * Referenced by: '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: range
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */

  /*  Computed Parameter: PCIQUAD04_P8_Size
   * Referenced by: '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: speed
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */

  /*  Computed Parameter: PCIQUAD04_P9_Size
   * Referenced by: '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: prescale
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */

  /*  Computed Parameter: PCIQUAD04_P10_Size
   * Referenced by: '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: ts
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */

  /*  Computed Parameter: PCIQUAD04_P11_Size
   * Referenced by: '<S14>/PCI-QUAD04 '
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  0.0003490658,                        /* Expression: 3.490658e-4
                                        * Referenced by: '<S14>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/shoulderOffset'
                                        */
  24.0,                                /* Expression: 24
                                        * Referenced by: '<S77>/L1'
                                        */
  23.5,                                /* Expression: 23.5
                                        * Referenced by: '<S77>/L2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S73>/AngleOffset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Load'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S24>/x'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S25>/x'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S26>/x'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S27>/x'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S77>/Gain'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S77>/Gain1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S77>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/UseTachs'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S69>/dG'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S70>/dG'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S11>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Load'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S18>/x'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S19>/x'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S20>/x'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S21>/x'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P1_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P2_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P3_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P4_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P5_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P6_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P7_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P8_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P9_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P10_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P11_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P12_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P13_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P14_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P15_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P16_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P17_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P18_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P19_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P20_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P21_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P22_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P23_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P24_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P25_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P26_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P27_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P28_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P29_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P30_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P31_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P32_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P33_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P34_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P35_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P36_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P37_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P38_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P39_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P40_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P41_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P42_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P43_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P44_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P45_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */

  /*  Computed Parameter: BehaviorCOBump_P46_Size
   * Referenced by: '<Root>/Behavior CO Bump'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  17.0,                                /* Expression: 17
                                        * Referenced by: '<Root>/TargetCount'
                                        */

  /*  Computed Parameter: Send_P1_Size
   * Referenced by: '<S8>/Send'
   */
  { 1.0, 11.0 },

  /*  Computed Parameter: Send_P1
   * Referenced by: '<S8>/Send'
   */
  { 49.0, 57.0, 50.0, 46.0, 49.0, 54.0, 56.0, 46.0, 48.0, 46.0, 50.0 },

  /*  Computed Parameter: Send_P2_Size
   * Referenced by: '<S8>/Send'
   */
  { 1.0, 1.0 },
  25000.0,                             /* Expression: ipPort
                                        * Referenced by: '<S8>/Send'
                                        */

  /*  Computed Parameter: Send_P3_Size
   * Referenced by: '<S8>/Send'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: localPort
                                        * Referenced by: '<S8>/Send'
                                        */

  /*  Computed Parameter: Send_P4_Size
   * Referenced by: '<S8>/Send'
   */
  { 1.0, 1.0 },
  0.02,                                /* Expression: sampletime
                                        * Referenced by: '<S8>/Send'
                                        */

  /*  Computed Parameter: Send_P5_Size
   * Referenced by: '<S8>/Send'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: vblLen
                                        * Referenced by: '<S8>/Send'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/DisableBoundingBox'
                                        */
  -30.0,                               /* Expression: -30
                                        * Referenced by: '<S1>/XLowLimit'
                                        */
  25.0,                                /* Expression: 25
                                        * Referenced by: '<S1>/XHighLimit'
                                        */
  -46.0,                               /* Expression: -46
                                        * Referenced by: '<S1>/YHighLimit'
                                        */
  -22.0,                               /* Expression: -22
                                        * Referenced by: '<S1>/YLowLimit'
                                        */
  28.0,                                /* Expression: 28
                                        * Referenced by: '<S18>/rho'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S18>/z'
                                        */
  2.6666666666666665,                  /* Expression: 8/3
                                        * Referenced by: '<S18>/beta'
                                        */
  0.0001,                              /* Expression: .0001
                                        * Referenced by: '<S18>/timescale'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S18>/sigma'
                                        */
  28.0,                                /* Expression: 28
                                        * Referenced by: '<S19>/rho'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S19>/z'
                                        */
  2.6666666666666665,                  /* Expression: 8/3
                                        * Referenced by: '<S19>/beta'
                                        */
  0.0001,                              /* Expression: .0001
                                        * Referenced by: '<S19>/timescale'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S19>/sigma'
                                        */
  28.0,                                /* Expression: 28
                                        * Referenced by: '<S20>/rho'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S20>/z'
                                        */
  2.6666666666666665,                  /* Expression: 8/3
                                        * Referenced by: '<S20>/beta'
                                        */
  0.0001,                              /* Expression: .0001
                                        * Referenced by: '<S20>/timescale'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S20>/sigma'
                                        */
  28.0,                                /* Expression: 28
                                        * Referenced by: '<S21>/rho'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S21>/z'
                                        */
  2.6666666666666665,                  /* Expression: 8/3
                                        * Referenced by: '<S21>/beta'
                                        */
  0.0001,                              /* Expression: .0001
                                        * Referenced by: '<S21>/timescale'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S21>/sigma'
                                        */
  28.0,                                /* Expression: 28
                                        * Referenced by: '<S24>/rho'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S24>/z'
                                        */
  2.6666666666666665,                  /* Expression: 8/3
                                        * Referenced by: '<S24>/beta'
                                        */
  0.0001,                              /* Expression: .0001
                                        * Referenced by: '<S24>/timescale'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S24>/sigma'
                                        */
  28.0,                                /* Expression: 28
                                        * Referenced by: '<S25>/rho'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S25>/z'
                                        */
  2.6666666666666665,                  /* Expression: 8/3
                                        * Referenced by: '<S25>/beta'
                                        */
  0.0001,                              /* Expression: .0001
                                        * Referenced by: '<S25>/timescale'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S25>/sigma'
                                        */
  28.0,                                /* Expression: 28
                                        * Referenced by: '<S26>/rho'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S26>/z'
                                        */
  2.6666666666666665,                  /* Expression: 8/3
                                        * Referenced by: '<S26>/beta'
                                        */
  0.0001,                              /* Expression: .0001
                                        * Referenced by: '<S26>/timescale'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S26>/sigma'
                                        */
  28.0,                                /* Expression: 28
                                        * Referenced by: '<S27>/rho'
                                        */
  0.1,                                 /* Expression: .1
                                        * Referenced by: '<S27>/z'
                                        */
  2.6666666666666665,                  /* Expression: 8/3
                                        * Referenced by: '<S27>/beta'
                                        */
  0.0001,                              /* Expression: .0001
                                        * Referenced by: '<S27>/timescale'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S27>/sigma'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/IsometricMode'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S35>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S39>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Discrete FIR Filter'
                                        */

  /*  Expression: [0.0069    0.0195    0.0106    0.0194    0.0217    0.0270    0.0313    0.0360    0.0404    0.0445    0.0482    0.0513    0.0538    0.0554    0.0563    0.0563    0.0554 0.0538    0.0513    0.0482    0.0445    0.0404    0.0360    0.0313    0.0270    0.0217    0.0194    0.0106    0.0195    0.0069]
   * Referenced by: '<S6>/Discrete FIR Filter'
   */
  { 0.0069, 0.0195, 0.0106, 0.0194, 0.0217, 0.027, 0.0313, 0.036, 0.0404, 0.0445,
    0.0482, 0.0513, 0.0538, 0.0554, 0.0563, 0.0563, 0.0554, 0.0538, 0.0513,
    0.0482, 0.0445, 0.0404, 0.036, 0.0313, 0.027, 0.0217, 0.0194, 0.0106, 0.0195,
    0.0069 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/RecenterFlag'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S37>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S38>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S62>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S55>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S59>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S57>/Constant'
                                        */
  0.075,                               /* Expression: 0.075
                                        * Referenced by: '<S4>/MG1'
                                        */
  -0.0915,                             /* Expression: -0.0915
                                        * Referenced by: '<S4>/MG2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S30>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S31>/Constant'
                                        */

  /*  Computed Parameter: PCI6025E_P1_Size_j
   * Referenced by: '<S4>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<S4>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  Computed Parameter: PCI6025E_P2_Size_l
   * Referenced by: '<S4>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  Expression: range
   * Referenced by: '<S4>/PCI-6025E '
   */
  { -10.0, -10.0 },

  /*  Computed Parameter: PCI6025E_P3_Size_e
   * Referenced by: '<S4>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  Expression: reset
   * Referenced by: '<S4>/PCI-6025E '
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: PCI6025E_P4_Size_j
   * Referenced by: '<S4>/PCI-6025E '
   */
  { 1.0, 2.0 },

  /*  Expression: initValue
   * Referenced by: '<S4>/PCI-6025E '
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: PCI6025E_P5_Size_m
   * Referenced by: '<S4>/PCI-6025E '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */

  /*  Computed Parameter: PCI6025E_P6_Size_o
   * Referenced by: '<S4>/PCI-6025E '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: slot
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */

  /*  Computed Parameter: PCI6025E_P7_Size_o
   * Referenced by: '<S4>/PCI-6025E '
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: boardType
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Uniform Random Number'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S7>/Uniform Random Number'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Uniform Random Number'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/JackpotChance'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S10>/Gain'
                                        */
  0.5,                                 /* Expression: .5
                                        * Referenced by: '<S10>/Gain1'
                                        */

  /*  Expression: [-.73 .08 .21 -.23 .25 .44]
   * Referenced by: '<S78>/F Offset'
   */
  { -0.73, 0.08, 0.21, -0.23, 0.25, 0.44 },
  0,                                   /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S78>/Discrete-Time Integrator'
                                        */
  1000,                                /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                                        * Referenced by: '<S78>/Discrete-Time Integrator'
                                        */
  -1,                                  /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                                        * Referenced by: '<S78>/Discrete-Time Integrator'
                                        */
  1U,                                  /* Computed Parameter: PacketSpec_Value
                                        * Referenced by: '<S8>/Packet Spec'
                                        */
  4294443008U,                         /* Computed Parameter: NaNupperbytes_Value
                                        * Referenced by: '<S8>/NaN upper bytes'
                                        */
  0,                                   /* Computed Parameter: Memory_X0_b
                                        * Referenced by: '<S33>/Memory'
                                        */
  0,                                   /* Computed Parameter: Memory_X0_p
                                        * Referenced by: '<S4>/Memory'
                                        */
  0,                                   /* Computed Parameter: Memory_X0_g
                                        * Referenced by: '<S45>/Memory'
                                        */
  0,                                   /* Computed Parameter: Memory_X0_e
                                        * Referenced by: '<S49>/Memory'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_ow
                                        * Referenced by: '<S65>/Constant'
                                        */
  0,                                   /* Computed Parameter: Memory_X0_b5
                                        * Referenced by: '<S47>/Memory'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_ch
                                        * Referenced by: '<S61>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_dl
                                        * Referenced by: '<S52>/Constant'
                                        */
  0,                                   /* Computed Parameter: Memory_X0_a
                                        * Referenced by: '<S46>/Memory'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S51>/Constant'
                                        */

  /*  Computed Parameter: Logic_table
   * Referenced by: '<S44>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 },

  /* Start of '<S67>/Sample and Hold' */
  {
    -1000.0                            /* Expression: initCond
                                        * Referenced by: '<S68>/ '
                                        */
  }
  /* End of '<S67>/Sample and Hold' */
  ,

  /* Start of '<S7>/Sample and Hold' */
  {
    0.0                                /* Expression: initCond
                                        * Referenced by: '<S66>/ '
                                        */
  }
  /* End of '<S7>/Sample and Hold' */
};
