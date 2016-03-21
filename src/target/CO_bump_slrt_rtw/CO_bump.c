/*
 * CO_bump.c
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

#include "rt_logging_mmi.h"
#include "CO_bump_capi.h"
#include "CO_bump.h"
#include "CO_bump_private.h"

const real_T CO_bump_RGND = 0.0;       /* real_T ground */

/* Block signals (auto storage) */
B_CO_bump_T CO_bump_B;

/* Block states (auto storage) */
DW_CO_bump_T CO_bump_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_CO_bump_T CO_bump_PrevZCX;

/* Real-time model */
RT_MODEL_CO_bump_T CO_bump_M_;
RT_MODEL_CO_bump_T *const CO_bump_M = &CO_bump_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(CO_bump_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(CO_bump_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (CO_bump_M->Timing.TaskCounters.TID[1] == 0) {
    CO_bump_M->Timing.RateInteraction.TID1_2 =
      (CO_bump_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    CO_bump_M->Timing.perTaskSampleHits[5] =
      CO_bump_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (CO_bump_M->Timing.TaskCounters.TID[2])++;
  if ((CO_bump_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.02s, 0.0s] */
    CO_bump_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Disable for enable system:
 *    '<S33>/Enabled Subsystem'
 *    '<S45>/Enabled Subsystem'
 *    '<S46>/Enabled Subsystem'
 *    '<S47>/Enabled Subsystem'
 *    '<S49>/Enabled Subsystem'
 */
void CO_bum_EnabledSubsystem_Disable(DW_EnabledSubsystem_CO_bump_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Start for enable system:
 *    '<S33>/Enabled Subsystem'
 *    '<S45>/Enabled Subsystem'
 *    '<S46>/Enabled Subsystem'
 *    '<S47>/Enabled Subsystem'
 *    '<S49>/Enabled Subsystem'
 */
void CO_bump_EnabledSubsystem_Start(DW_EnabledSubsystem_CO_bump_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S33>/Enabled Subsystem'
 *    '<S45>/Enabled Subsystem'
 *    '<S46>/Enabled Subsystem'
 *    '<S47>/Enabled Subsystem'
 *    '<S49>/Enabled Subsystem'
 */
void CO_bump_EnabledSubsystem(boolean_T rtu_Enable, real_T rtu_In1,
  B_EnabledSubsystem_CO_bump_T *localB, DW_EnabledSubsystem_CO_bump_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S33>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S36>/Enable'
   */
  if (rtu_Enable) {
    if (!localDW->EnabledSubsystem_MODE) {
      localDW->EnabledSubsystem_MODE = true;
    }
  } else {
    if (localDW->EnabledSubsystem_MODE) {
      CO_bum_EnabledSubsystem_Disable(localDW);
    }
  }

  if (localDW->EnabledSubsystem_MODE) {
    /* Inport: '<S36>/In1' */
    localB->In1 = rtu_In1;
    srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S33>/Enabled Subsystem' */
}

/*
 * Start for trigger system:
 *    '<S7>/Sample and Hold'
 *    '<S67>/Sample and Hold'
 */
void CO_bump_SampleandHold_Start(B_SampleandHold_CO_bump_T *localB,
  P_SampleandHold_CO_bump_T *localP)
{
  /* VirtualOutportStart for Outport: '<S66>/ ' */
  localB->In = localP->_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S7>/Sample and Hold'
 *    '<S67>/Sample and Hold'
 */
void CO_bump_SampleandHold(real_T rtu_Trigger, real_T rtu_In,
  B_SampleandHold_CO_bump_T *localB, DW_SampleandHold_CO_bump_T *localDW,
  ZCE_SampleandHold_CO_bump_T *localZCE)
{
  ZCEventType zcEvent;

  /* Outputs for Triggered SubSystem: '<S7>/Sample and Hold' incorporates:
   *  TriggerPort: '<S66>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&localZCE->SampleandHold_Trig_ZCE,
                     (rtu_Trigger));
  if (zcEvent != NO_ZCEVENT) {
    /* Inport: '<S66>/In' */
    localB->In = rtu_In;
    localDW->SampleandHold_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S7>/Sample and Hold' */
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function for TID0 */
static void CO_bump_output0(void)      /* Sample time: [0.0s, 0.0s] */
{
  int32_T idxN;
  real_T *lastU;
  real_T acc2;
  int32_T tmp;
  real_T Bias;
  int32_T i;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  real_T tmp_4;
  boolean_T tmp_5;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(CO_bump_DW.EnabledSubsystem.EnabledSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CO_bump_DW.SampleandHold_j.SampleandHold_SubsysRanBC);

  /* Level2 S-Function Block: '<Root>/Intel Chipset Disable SMI' (ich5) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[8];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S5>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[9];
    sfcnOutputs(rts, 0);
  }

  /* Unpack: <S5>/Unpack */
  (void) memcpy(&CO_bump_B.Unpack[0], &CO_bump_B.Receive_o1[0],
                48);

  /* Constant: '<S77>/yoffset' */
  CO_bump_B.yoffset = CO_bump_P.yoffset_Value;

  /* Level2 S-Function Block: '<S14>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[10];
    sfcnOutputs(rts, 0);
  }

  for (i = 0; i < 6; i++) {
    /* UnitDelay: '<S78>/Unit Delay1' */
    CO_bump_B.UnitDelay1[i] = CO_bump_DW.UnitDelay1_DSTATE[i];

    /* Gain: '<S78>/Gain' */
    CO_bump_B.Gain[i] = CO_bump_P.Gain_Gain_g * CO_bump_B.UnitDelay1[i];
  }

  CO_bump_B.Sum[0] = CO_bump_B.PCI6025EAD_o1 + CO_bump_B.Gain[0];
  CO_bump_B.Sum[1] = CO_bump_B.PCI6025EAD_o2 + CO_bump_B.Gain[1];
  CO_bump_B.Sum[2] = CO_bump_B.PCI6025EAD_o3 + CO_bump_B.Gain[2];
  CO_bump_B.Sum[3] = CO_bump_B.PCI6025EAD_o4 + CO_bump_B.Gain[3];
  CO_bump_B.Sum[4] = CO_bump_B.PCI6025EAD_o5 + CO_bump_B.Gain[4];
  CO_bump_B.Sum[5] = CO_bump_B.PCI6025EAD_o6 + CO_bump_B.Gain[5];

  /* Gain: '<S78>/Gain1' */
  for (i = 0; i < 6; i++) {
    CO_bump_B.Gain1[i] = CO_bump_P.Gain1_Gain_n * CO_bump_B.Sum[i];
  }

  /* End of Gain: '<S78>/Gain1' */

  /* Sum: '<S78>/Add' */
  CO_bump_B.Add[0] = CO_bump_B.PCI6025EAD_o1 - CO_bump_B.Gain1[0];
  CO_bump_B.Add[1] = CO_bump_B.PCI6025EAD_o2 - CO_bump_B.Gain1[1];
  CO_bump_B.Add[2] = CO_bump_B.PCI6025EAD_o3 - CO_bump_B.Gain1[2];
  CO_bump_B.Add[3] = CO_bump_B.PCI6025EAD_o4 - CO_bump_B.Gain1[3];
  CO_bump_B.Add[4] = CO_bump_B.PCI6025EAD_o5 - CO_bump_B.Gain1[4];
  CO_bump_B.Add[5] = CO_bump_B.PCI6025EAD_o6 - CO_bump_B.Gain1[5];

  /* Abs: '<S78>/Abs' */
  for (i = 0; i < 6; i++) {
    CO_bump_B.Abs[i] = fabs(CO_bump_B.Add[i]);
  }

  /* End of Abs: '<S78>/Abs' */

  /* Sum: '<S78>/Sum of Elements' */
  Bias = CO_bump_B.Abs[0];
  for (i = 0; i < 5; i++) {
    tmp = i + 1;
    Bias += CO_bump_B.Abs[tmp];
  }

  CO_bump_B.SumofElements = Bias;

  /* End of Sum: '<S78>/Sum of Elements' */

  /* RelationalOperator: '<S83>/Compare' incorporates:
   *  Constant: '<S83>/Constant'
   */
  CO_bump_B.Compare = (uint8_T)(CO_bump_B.SumofElements <=
    CO_bump_P.NoiseLevel_const);

  /* DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
  if ((CO_bump_B.Compare <= 0) && (CO_bump_DW.DiscreteTimeIntegrator_PrevRese ==
       1)) {
    CO_bump_DW.DiscreteTimeIntegrator_DSTATE =
      CO_bump_P.DiscreteTimeIntegrator_IC;
  }

  if (CO_bump_DW.DiscreteTimeIntegrator_DSTATE >=
      CO_bump_P.DiscreteTimeIntegrator_UpperSat) {
    CO_bump_DW.DiscreteTimeIntegrator_DSTATE =
      CO_bump_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (CO_bump_DW.DiscreteTimeIntegrator_DSTATE <=
        CO_bump_P.DiscreteTimeIntegrator_LowerSat) {
      CO_bump_DW.DiscreteTimeIntegrator_DSTATE =
        CO_bump_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  CO_bump_B.DiscreteTimeIntegrator = CO_bump_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */

  /* RelationalOperator: '<S82>/Compare' incorporates:
   *  Constant: '<S82>/Constant'
   */
  CO_bump_B.Compare_ea = (CO_bump_B.DiscreteTimeIntegrator >=
    CO_bump_P.CompareToConstant1_const_ah);
  for (i = 0; i < 6; i++) {
    /* Memory: '<S78>/Memory' */
    CO_bump_B.Memory[i] = CO_bump_DW.Memory_PreviousInput[i];

    /* Switch: '<S78>/Switch' */
    if (CO_bump_B.Compare_ea) {
      CO_bump_B.Switch[i] = CO_bump_B.Gain1[i];
    } else {
      CO_bump_B.Switch[i] = CO_bump_B.Memory[i];
    }

    /* End of Switch: '<S78>/Switch' */
  }

  /* Sum: '<S14>/Add2' */
  CO_bump_B.Add2[0] = CO_bump_B.PCI6025EAD_o1 - CO_bump_B.Switch[0];
  CO_bump_B.Add2[1] = CO_bump_B.PCI6025EAD_o2 - CO_bump_B.Switch[1];
  CO_bump_B.Add2[2] = CO_bump_B.PCI6025EAD_o3 - CO_bump_B.Switch[2];
  CO_bump_B.Add2[3] = CO_bump_B.PCI6025EAD_o4 - CO_bump_B.Switch[3];
  CO_bump_B.Add2[4] = CO_bump_B.PCI6025EAD_o5 - CO_bump_B.Switch[4];
  CO_bump_B.Add2[5] = CO_bump_B.PCI6025EAD_o6 - CO_bump_B.Switch[5];

  /* Constant: '<S14>/LoadCellYCoef1' */
  CO_bump_B.VectorConcatenate1[0] = CO_bump_P.LoadCellYCoef1_Value;

  /* Constant: '<S14>/LoadCellYCoef2' */
  CO_bump_B.VectorConcatenate1[1] = CO_bump_P.LoadCellYCoef2_Value;

  /* Constant: '<S14>/LoadCellYCoef3' */
  CO_bump_B.VectorConcatenate1[2] = CO_bump_P.LoadCellYCoef3_Value;

  /* Constant: '<S14>/LoadCellYCoef4' */
  CO_bump_B.VectorConcatenate1[3] = CO_bump_P.LoadCellYCoef4_Value;

  /* Constant: '<S14>/LoadCellYCoef5' */
  CO_bump_B.VectorConcatenate1[4] = CO_bump_P.LoadCellYCoef5_Value;

  /* Constant: '<S14>/LoadCellYCoef6' */
  CO_bump_B.VectorConcatenate1[5] = CO_bump_P.LoadCellYCoef6_Value;

  /* DotProduct: '<S14>/Dot Product Y' */
  Bias = 0.0;
  for (i = 0; i < 6; i++) {
    /* Gain: '<S14>/Gain3' */
    CO_bump_B.Gain3[i] = CO_bump_P.Gain3_Gain_o * CO_bump_B.VectorConcatenate1[i];
    acc2 = CO_bump_B.Add2[i];
    tmp_0 = CO_bump_B.Gain3[i];
    Bias += acc2 * tmp_0;
  }

  CO_bump_B.DotProductY = Bias;

  /* End of DotProduct: '<S14>/Dot Product Y' */

  /* UnitDelay: '<S72>/Unit Delay' */
  CO_bump_B.UnitDelay = CO_bump_DW.UnitDelay_DSTATE;

  /* Gain: '<S72>/Gain' */
  CO_bump_B.Gain_f = CO_bump_P.Gain_Gain_i4 * CO_bump_B.UnitDelay;

  /* Sum: '<S72>/Sum' */
  CO_bump_B.Sum_m = CO_bump_B.DotProductY + CO_bump_B.Gain_f;

  /* Gain: '<S72>/Gain1' */
  CO_bump_B.Gain1_m = CO_bump_P.Gain1_Gain_c * CO_bump_B.Sum_m;

  /* Constant: '<S14>/LoadCellXCoef1' */
  CO_bump_B.VectorConcatenate[0] = CO_bump_P.LoadCellXCoef1_Value;

  /* Constant: '<S14>/LoadCellXCoef2' */
  CO_bump_B.VectorConcatenate[1] = CO_bump_P.LoadCellXCoef2_Value;

  /* Constant: '<S14>/LoadCellXCoef3' */
  CO_bump_B.VectorConcatenate[2] = CO_bump_P.LoadCellXCoef3_Value;

  /* Constant: '<S14>/LoadCellXCoef4' */
  CO_bump_B.VectorConcatenate[3] = CO_bump_P.LoadCellXCoef4_Value;

  /* Constant: '<S14>/LoadCellXCoef5' */
  CO_bump_B.VectorConcatenate[4] = CO_bump_P.LoadCellXCoef5_Value;

  /* Constant: '<S14>/LoadCellXCoef6' */
  CO_bump_B.VectorConcatenate[5] = CO_bump_P.LoadCellXCoef6_Value;

  /* DotProduct: '<S14>/Dot Product X' */
  Bias = 0.0;
  for (i = 0; i < 6; i++) {
    /* Gain: '<S14>/Gain2' */
    CO_bump_B.Gain2[i] = CO_bump_P.Gain2_Gain_b * CO_bump_B.VectorConcatenate[i];
    acc2 = CO_bump_B.Add2[i];
    tmp_0 = CO_bump_B.Gain2[i];
    Bias += acc2 * tmp_0;
  }

  CO_bump_B.DotProductX = Bias;

  /* End of DotProduct: '<S14>/Dot Product X' */

  /* UnitDelay: '<S71>/Unit Delay' */
  CO_bump_B.UnitDelay_n = CO_bump_DW.UnitDelay_DSTATE_e;

  /* Gain: '<S71>/Gain' */
  CO_bump_B.Gain_d = CO_bump_P.Gain_Gain_o * CO_bump_B.UnitDelay_n;

  /* Sum: '<S71>/Sum' */
  CO_bump_B.Sum_f = CO_bump_B.DotProductX + CO_bump_B.Gain_d;

  /* Gain: '<S71>/Gain1' */
  CO_bump_B.Gain1_c = CO_bump_P.Gain1_Gain_p * CO_bump_B.Sum_f;

  /* Level2 S-Function Block: '<S14>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[11];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<S14>/Gain1' */
  CO_bump_B.Gain1_n = CO_bump_P.Gain1_Gain_b * CO_bump_B.PCIQUAD041;

  /* Sum: '<S14>/Sum1' incorporates:
   *  Constant: '<S14>/elbowOffset'
   */
  CO_bump_B.Sum1 = CO_bump_B.Gain1_n + CO_bump_P.elbowOffset_Value;

  /* Constant: '<S77>/xoffset' */
  CO_bump_B.xoffset = CO_bump_P.xoffset_Value;

  /* Level2 S-Function Block: '<S14>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[12];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<S14>/Gain' */
  CO_bump_B.Gain_g = CO_bump_P.Gain_Gain_b * CO_bump_B.PCIQUAD04;

  /* Sum: '<S14>/Sum3' incorporates:
   *  Constant: '<S14>/shoulderOffset'
   */
  CO_bump_B.Sum3 = CO_bump_B.Gain_g + CO_bump_P.shoulderOffset_Value;

  /* Trigonometry: '<S77>/Trigonometric Function' */
  CO_bump_B.TrigonometricFunction = cos(CO_bump_B.Sum3);

  /* Product: '<S77>/Product' incorporates:
   *  Constant: '<S77>/L1'
   */
  CO_bump_B.Product = CO_bump_B.TrigonometricFunction * CO_bump_P.L1_Value;

  /* Trigonometry: '<S77>/Trigonometric Function2' */
  CO_bump_B.TrigonometricFunction2 = sin(CO_bump_B.Sum1);

  /* Product: '<S77>/Product2' incorporates:
   *  Constant: '<S77>/L2'
   */
  CO_bump_B.Product2 = CO_bump_B.TrigonometricFunction2 * CO_bump_P.L2_Value;

  /* Sum: '<S77>/Sum2' */
  CO_bump_B.Sum2 = (0.0 - CO_bump_B.Product) - CO_bump_B.Product2;

  /* Trigonometry: '<S77>/Trigonometric Function1' */
  CO_bump_B.TrigonometricFunction1 = sin(CO_bump_B.Sum3);

  /* Product: '<S77>/Product1' incorporates:
   *  Constant: '<S77>/L1'
   */
  CO_bump_B.Product1 = CO_bump_B.TrigonometricFunction1 * CO_bump_P.L1_Value;

  /* Trigonometry: '<S77>/Trigonometric Function3' */
  CO_bump_B.TrigonometricFunction3 = cos(CO_bump_B.Sum1);

  /* Product: '<S77>/Product3' incorporates:
   *  Constant: '<S77>/L2'
   */
  CO_bump_B.Product3 = CO_bump_B.TrigonometricFunction3 * CO_bump_P.L2_Value;

  /* Sum: '<S77>/Sum3' */
  CO_bump_B.Sum3_c = CO_bump_B.Product3 - CO_bump_B.Product1;

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/IsometricMode'
   */
  if (CO_bump_P.IsometricMode_Value != 0.0) {
    /* Trigonometry: '<S76>/Trigonometric Function1' */
    CO_bump_B.TrigonometricFunction1_b = rt_atan2d_snf(CO_bump_B.Gain1_m,
      CO_bump_B.Gain1_c);

    /* Sum: '<S76>/Sum' */
    CO_bump_B.Sum_hr = CO_bump_B.TrigonometricFunction1_b + CO_bump_B.Sum1;

    /* Trigonometry: '<S76>/Trigonometric Function2' */
    CO_bump_B.TrigonometricFunction2_e = cos(CO_bump_B.Sum_hr);

    /* Fcn: '<S76>/sqrt(u[1]*u[1] + u[2]*u[2])' */
    Bias = CO_bump_B.Gain1_m * CO_bump_B.Gain1_m + CO_bump_B.Gain1_c *
      CO_bump_B.Gain1_c;
    if (Bias < 0.0) {
      Bias = -sqrt(-Bias);
    } else {
      Bias = sqrt(Bias);
    }

    CO_bump_B.sqrtu1u1u2u2 = Bias;

    /* End of Fcn: '<S76>/sqrt(u[1]*u[1] + u[2]*u[2])' */

    /* Product: '<S76>/Product1' */
    CO_bump_B.Product1_m = CO_bump_B.TrigonometricFunction2_e *
      CO_bump_B.sqrtu1u1u2u2;

    /* DotProduct: '<S14>/Dot Product2' incorporates:
     *  Constant: '<S14>/ForceToScreenGain'
     */
    Bias = CO_bump_B.Product1_m;
    acc2 = CO_bump_P.ForceToScreenGain_Value;
    CO_bump_B.DotProduct2 = Bias * acc2;

    /* Fcn: '<S14>/Fcn' incorporates:
     *  Constant: '<S14>/UpsideDownHandle'
     */
    CO_bump_B.Fcn = -2.0 * CO_bump_P.UpsideDownHandle_Value + 1.0;

    /* DotProduct: '<S14>/Dot Product' */
    Bias = CO_bump_B.Fcn;
    acc2 = CO_bump_B.DotProduct2;
    CO_bump_B.DotProduct = Bias * acc2;

    /* Sum: '<S14>/Add' */
    CO_bump_B.Add_e = CO_bump_B.xoffset + CO_bump_B.DotProduct;

    /* Trigonometry: '<S76>/Trigonometric Function' */
    CO_bump_B.TrigonometricFunction_c = sin(CO_bump_B.Sum_hr);

    /* Product: '<S76>/Product' */
    CO_bump_B.Product_a = CO_bump_B.sqrtu1u1u2u2 *
      CO_bump_B.TrigonometricFunction_c;

    /* DotProduct: '<S14>/Dot Product1' incorporates:
     *  Constant: '<S14>/ForceToScreenGain'
     */
    Bias = CO_bump_B.Product_a;
    acc2 = CO_bump_P.ForceToScreenGain_Value;
    CO_bump_B.DotProduct1 = Bias * acc2;

    /* Sum: '<S14>/Add1' */
    CO_bump_B.Add1_o = CO_bump_B.yoffset + CO_bump_B.DotProduct1;

    /* Fcn: '<S74>/sqrt(u[1]*u[1] + u[2]*u[2])' */
    Bias = CO_bump_B.Add1_o * CO_bump_B.Add1_o + CO_bump_B.Add_e *
      CO_bump_B.Add_e;
    if (Bias < 0.0) {
      Bias = -sqrt(-Bias);
    } else {
      Bias = sqrt(Bias);
    }

    CO_bump_B.sqrtu1u1u2u2_d = Bias;

    /* End of Fcn: '<S74>/sqrt(u[1]*u[1] + u[2]*u[2])' */

    /* Trigonometry: '<S74>/Trigonometric Function1' */
    CO_bump_B.TrigonometricFunction1_a = rt_atan2d_snf(CO_bump_B.Add1_o,
      CO_bump_B.Add_e);

    /* Sum: '<S74>/Sum' incorporates:
     *  Constant: '<S74>/AngleOffset'
     */
    CO_bump_B.Sum_j = CO_bump_B.TrigonometricFunction1_a +
      CO_bump_P.AngleOffset_Value;

    /* Trigonometry: '<S74>/Trigonometric Function2' */
    CO_bump_B.TrigonometricFunction2_h = cos(CO_bump_B.Sum_j);

    /* Product: '<S74>/Product1' */
    CO_bump_B.Product1_g = CO_bump_B.TrigonometricFunction2_h *
      CO_bump_B.sqrtu1u1u2u2_d;

    /* Trigonometry: '<S74>/Trigonometric Function' */
    CO_bump_B.TrigonometricFunction_i = sin(CO_bump_B.Sum_j);

    /* Product: '<S74>/Product' */
    CO_bump_B.Product_d = CO_bump_B.sqrtu1u1u2u2_d *
      CO_bump_B.TrigonometricFunction_i;
    CO_bump_B.Switch_d[0] = CO_bump_B.Product1_g;
    CO_bump_B.Switch_d[1] = CO_bump_B.Product_d;
  } else {
    /* Sum: '<S77>/Sum1' */
    CO_bump_B.Sum1_m = CO_bump_B.Sum3_c + CO_bump_B.xoffset;

    /* Sum: '<S77>/Sum4' */
    CO_bump_B.Sum4 = CO_bump_B.Sum2 + CO_bump_B.yoffset;

    /* Fcn: '<S73>/sqrt(u[1]*u[1] + u[2]*u[2])' */
    Bias = CO_bump_B.Sum4 * CO_bump_B.Sum4 + CO_bump_B.Sum1_m * CO_bump_B.Sum1_m;
    if (Bias < 0.0) {
      Bias = -sqrt(-Bias);
    } else {
      Bias = sqrt(Bias);
    }

    CO_bump_B.sqrtu1u1u2u2_p = Bias;

    /* End of Fcn: '<S73>/sqrt(u[1]*u[1] + u[2]*u[2])' */

    /* Trigonometry: '<S73>/Trigonometric Function1' */
    CO_bump_B.TrigonometricFunction1_av = rt_atan2d_snf(CO_bump_B.Sum4,
      CO_bump_B.Sum1_m);

    /* Sum: '<S73>/Sum' incorporates:
     *  Constant: '<S73>/AngleOffset'
     */
    CO_bump_B.Sum_e = CO_bump_B.TrigonometricFunction1_av +
      CO_bump_P.AngleOffset_Value_n;

    /* Trigonometry: '<S73>/Trigonometric Function2' */
    CO_bump_B.TrigonometricFunction2_hb = cos(CO_bump_B.Sum_e);

    /* Product: '<S73>/Product1' */
    CO_bump_B.Product1_c = CO_bump_B.TrigonometricFunction2_hb *
      CO_bump_B.sqrtu1u1u2u2_p;

    /* Trigonometry: '<S73>/Trigonometric Function' */
    CO_bump_B.TrigonometricFunction_n = sin(CO_bump_B.Sum_e);

    /* Product: '<S73>/Product' */
    CO_bump_B.Product_f = CO_bump_B.sqrtu1u1u2u2_p *
      CO_bump_B.TrigonometricFunction_n;
    CO_bump_B.Switch_d[0] = CO_bump_B.Product1_c;
    CO_bump_B.Switch_d[1] = CO_bump_B.Product_f;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Switch: '<Root>/Neural Override' incorporates:
   *  Constant: '<Root>/Use Neural Control'
   */
  if (CO_bump_P.UseNeuralControl_Value != 0.0) {
    CO_bump_B.NeuralOverride[0] = CO_bump_B.Unpack[2];
    CO_bump_B.NeuralOverride[1] = CO_bump_B.Unpack[3];
  } else {
    CO_bump_B.NeuralOverride[0] = CO_bump_B.Switch_d[0];
    CO_bump_B.NeuralOverride[1] = CO_bump_B.Switch_d[1];
  }

  /* End of Switch: '<Root>/Neural Override' */

  /* UnitDelay: '<S24>/x' */
  CO_bump_B.x = CO_bump_DW.x_DSTATE;

  /* UnitDelay: '<S25>/x' */
  CO_bump_B.x_m = CO_bump_DW.x_DSTATE_i;

  /* Sum: '<S22>/Add' */
  CO_bump_B.Add_m = CO_bump_B.x - CO_bump_B.x_m;

  /* UnitDelay: '<S26>/x' */
  CO_bump_B.x_f = CO_bump_DW.x_DSTATE_o;

  /* UnitDelay: '<S27>/x' */
  CO_bump_B.x_g = CO_bump_DW.x_DSTATE_a;

  /* Gain: '<S77>/Gain' */
  CO_bump_B.MatrixConcatenate2[0] = CO_bump_P.Gain_Gain_du * CO_bump_B.Product;

  /* SignalConversion: '<S77>/ConcatBufferAtMatrix ConcatenateIn2' */
  CO_bump_B.MatrixConcatenate2[1] = CO_bump_B.Product1;

  /* Gain: '<S77>/Gain1' */
  CO_bump_B.MatrixConcatenate2[2] = CO_bump_P.Gain1_Gain_bo * CO_bump_B.Product2;

  /* Gain: '<S77>/Gain2' */
  CO_bump_B.MatrixConcatenate2[3] = CO_bump_P.Gain2_Gain_k * CO_bump_B.Product3;

  /* S-Function (sdspfilter2): '<S69>/Digital Filter2' */
  idxN = CO_bump_DW.DigitalFilter2_CIRCBUFFIDX;
  tmp = 1;
  Bias = CO_bump_B.Switch_d[0] * CO_bump_P.DigitalFilter2_NumCoeffs[0];
  for (i = idxN; i < 10; i++) {
    Bias += CO_bump_DW.DigitalFilter2_FILT_STATES[i] *
      CO_bump_P.DigitalFilter2_NumCoeffs[tmp];
    tmp++;
  }

  for (i = 0; i < idxN; i++) {
    Bias += CO_bump_DW.DigitalFilter2_FILT_STATES[i] *
      CO_bump_P.DigitalFilter2_NumCoeffs[tmp];
    tmp++;
  }

  idxN--;
  if (idxN < 0) {
    idxN = 9;
  }

  CO_bump_DW.DigitalFilter2_FILT_STATES[idxN] = CO_bump_B.Switch_d[0];
  CO_bump_B.DigitalFilter2 = Bias;
  CO_bump_DW.DigitalFilter2_CIRCBUFFIDX = idxN;

  /* End of S-Function (sdspfilter2): '<S69>/Digital Filter2' */

  /* Derivative: '<S69>/Derivative' */
  if ((CO_bump_DW.TimeStampA >= CO_bump_M->Timing.t[0]) &&
      (CO_bump_DW.TimeStampB >= CO_bump_M->Timing.t[0])) {
    CO_bump_B.Derivative = 0.0;
  } else {
    Bias = CO_bump_DW.TimeStampA;
    lastU = &CO_bump_DW.LastUAtTimeA;
    if (CO_bump_DW.TimeStampA < CO_bump_DW.TimeStampB) {
      if (CO_bump_DW.TimeStampB < CO_bump_M->Timing.t[0]) {
        Bias = CO_bump_DW.TimeStampB;
        lastU = &CO_bump_DW.LastUAtTimeB;
      }
    } else {
      if (CO_bump_DW.TimeStampA >= CO_bump_M->Timing.t[0]) {
        Bias = CO_bump_DW.TimeStampB;
        lastU = &CO_bump_DW.LastUAtTimeB;
      }
    }

    Bias = CO_bump_M->Timing.t[0] - Bias;
    CO_bump_B.Derivative = (CO_bump_B.DigitalFilter2 - *lastU) / Bias;
  }

  /* End of Derivative: '<S69>/Derivative' */

  /* Gain: '<S69>/dG' */
  CO_bump_B.dG = CO_bump_P.dG_Gain * CO_bump_B.Derivative;

  /* S-Function (sdspfilter2): '<S69>/Digital Filter' */
  idxN = CO_bump_DW.DigitalFilter_CIRCBUFFIDX;
  tmp = 1;
  Bias = CO_bump_B.dG * CO_bump_P.DigitalFilter_NumCoeffs[0];
  for (i = idxN; i < 10; i++) {
    Bias += CO_bump_DW.DigitalFilter_FILT_STATES[i] *
      CO_bump_P.DigitalFilter_NumCoeffs[tmp];
    tmp++;
  }

  for (i = 0; i < idxN; i++) {
    Bias += CO_bump_DW.DigitalFilter_FILT_STATES[i] *
      CO_bump_P.DigitalFilter_NumCoeffs[tmp];
    tmp++;
  }

  idxN--;
  if (idxN < 0) {
    idxN = 9;
  }

  CO_bump_DW.DigitalFilter_FILT_STATES[idxN] = CO_bump_B.dG;
  CO_bump_B.DigitalFilter = Bias;
  CO_bump_DW.DigitalFilter_CIRCBUFFIDX = idxN;

  /* End of S-Function (sdspfilter2): '<S69>/Digital Filter' */

  /* S-Function (sdspfilter2): '<S70>/Digital Filter2' */
  idxN = CO_bump_DW.DigitalFilter2_CIRCBUFFIDX_c;
  tmp = 1;
  Bias = CO_bump_B.Switch_d[1] * CO_bump_P.DigitalFilter2_NumCoeffs_p[0];
  for (i = idxN; i < 10; i++) {
    Bias += CO_bump_DW.DigitalFilter2_FILT_STATES_k[i] *
      CO_bump_P.DigitalFilter2_NumCoeffs_p[tmp];
    tmp++;
  }

  for (i = 0; i < idxN; i++) {
    Bias += CO_bump_DW.DigitalFilter2_FILT_STATES_k[i] *
      CO_bump_P.DigitalFilter2_NumCoeffs_p[tmp];
    tmp++;
  }

  idxN--;
  if (idxN < 0) {
    idxN = 9;
  }

  CO_bump_DW.DigitalFilter2_FILT_STATES_k[idxN] = CO_bump_B.Switch_d[1];
  CO_bump_B.DigitalFilter2_p = Bias;
  CO_bump_DW.DigitalFilter2_CIRCBUFFIDX_c = idxN;

  /* End of S-Function (sdspfilter2): '<S70>/Digital Filter2' */

  /* Derivative: '<S70>/Derivative' */
  if ((CO_bump_DW.TimeStampA_o >= CO_bump_M->Timing.t[0]) &&
      (CO_bump_DW.TimeStampB_a >= CO_bump_M->Timing.t[0])) {
    CO_bump_B.Derivative_e = 0.0;
  } else {
    Bias = CO_bump_DW.TimeStampA_o;
    lastU = &CO_bump_DW.LastUAtTimeA_h;
    if (CO_bump_DW.TimeStampA_o < CO_bump_DW.TimeStampB_a) {
      if (CO_bump_DW.TimeStampB_a < CO_bump_M->Timing.t[0]) {
        Bias = CO_bump_DW.TimeStampB_a;
        lastU = &CO_bump_DW.LastUAtTimeB_m;
      }
    } else {
      if (CO_bump_DW.TimeStampA_o >= CO_bump_M->Timing.t[0]) {
        Bias = CO_bump_DW.TimeStampB_a;
        lastU = &CO_bump_DW.LastUAtTimeB_m;
      }
    }

    Bias = CO_bump_M->Timing.t[0] - Bias;
    CO_bump_B.Derivative_e = (CO_bump_B.DigitalFilter2_p - *lastU) / Bias;
  }

  /* End of Derivative: '<S70>/Derivative' */

  /* Gain: '<S70>/dG' */
  CO_bump_B.dG_o = CO_bump_P.dG_Gain_p * CO_bump_B.Derivative_e;

  /* S-Function (sdspfilter2): '<S70>/Digital Filter' */
  idxN = CO_bump_DW.DigitalFilter_CIRCBUFFIDX_o;
  tmp = 1;
  Bias = CO_bump_B.dG_o * CO_bump_P.DigitalFilter_NumCoeffs_j[0];
  for (i = idxN; i < 10; i++) {
    Bias += CO_bump_DW.DigitalFilter_FILT_STATES_o[i] *
      CO_bump_P.DigitalFilter_NumCoeffs_j[tmp];
    tmp++;
  }

  for (i = 0; i < idxN; i++) {
    Bias += CO_bump_DW.DigitalFilter_FILT_STATES_o[i] *
      CO_bump_P.DigitalFilter_NumCoeffs_j[tmp];
    tmp++;
  }

  idxN--;
  if (idxN < 0) {
    idxN = 9;
  }

  CO_bump_DW.DigitalFilter_FILT_STATES_o[idxN] = CO_bump_B.dG_o;
  CO_bump_B.DigitalFilter_p = Bias;
  CO_bump_DW.DigitalFilter_CIRCBUFFIDX_o = idxN;

  /* End of S-Function (sdspfilter2): '<S70>/Digital Filter' */

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/UseTachs'
   *  Product: '<S11>/Matrix Multiply'
   */
  if (CO_bump_P.UseTachs_Value >= CO_bump_P.Switch_Threshold_b) {
    /* Gain: '<S11>/TachGain2' incorporates:
     *  Constant: '<S11>/ReplaceIfYouWantToUseTachs2'
     */
    CO_bump_B.TachGain2 = CO_bump_P.TachGain2_Gain *
      CO_bump_P.ReplaceIfYouWantToUseTachs2_Val;

    /* Gain: '<S11>/TachGain1' incorporates:
     *  Constant: '<S11>/ReplaceIfYouWantToUseTachs1'
     */
    CO_bump_B.TachGain1 = CO_bump_P.TachGain1_Gain *
      CO_bump_P.ReplaceIfYouWantToUseTachs1_Val;

    /* SignalConversion: '<S11>/TmpSignal ConversionAtMatrix MultiplyInport2' */
    CO_bump_B.TmpSignalConversionAtMatrixMult[0] = CO_bump_B.TachGain1;
    CO_bump_B.TmpSignalConversionAtMatrixMult[1] = CO_bump_B.TachGain2;

    /* Product: '<S11>/Matrix Multiply' */
    Bias = CO_bump_B.MatrixConcatenate2[0];
    acc2 = CO_bump_B.MatrixConcatenate2[1];
    tmp_0 = CO_bump_B.MatrixConcatenate2[2];
    tmp_1 = CO_bump_B.MatrixConcatenate2[3];
    tmp_2 = CO_bump_B.TmpSignalConversionAtMatrixMult[0];
    tmp_3 = CO_bump_B.TmpSignalConversionAtMatrixMult[1];
    tmp_4 = Bias * tmp_2;
    tmp_4 += tmp_0 * tmp_3;
    Bias = tmp_4;

    /* Product: '<S11>/Matrix Multiply' */
    tmp_4 = acc2 * tmp_2;
    tmp_4 += tmp_1 * tmp_3;
    CO_bump_B.MatrixMultiply[0] = Bias;
    CO_bump_B.MatrixMultiply[1] = tmp_4;
    CO_bump_B.Switch_j[0] = CO_bump_B.MatrixMultiply[0];
    CO_bump_B.Switch_j[1] = CO_bump_B.MatrixMultiply[1];
  } else {
    CO_bump_B.Switch_j[0] = CO_bump_B.DigitalFilter;
    CO_bump_B.Switch_j[1] = CO_bump_B.DigitalFilter_p;
  }

  /* End of Switch: '<S11>/Switch' */

  /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
   *  Constant: '<S3>/Load'
   *  Constant: '<S3>/Off'
   *  Constant: '<S3>/staticX'
   *  Constant: '<S3>/staticY'
   */
  switch ((int32_T)CO_bump_P.Load_Value) {
   case 0:
    CO_bump_B.MultiportSwitch[0] = CO_bump_P.Off_Value_p;
    CO_bump_B.MultiportSwitch[1] = CO_bump_P.Off_Value_p;
    break;

   case 1:
    CO_bump_B.MultiportSwitch[0] = CO_bump_P.staticX_Value_m;
    CO_bump_B.MultiportSwitch[1] = CO_bump_P.staticY_Value_k;
    break;

   case 2:
    /* Sum: '<S22>/Add1' */
    CO_bump_B.Add1_ce = CO_bump_B.x_f - CO_bump_B.x_g;

    /* Gain: '<S3>/LorentzForceGain' */
    CO_bump_B.LorentzForceGain[0] = CO_bump_P.LorentzForceGain_Gain_l *
      CO_bump_B.Add_m;
    CO_bump_B.LorentzForceGain[1] = CO_bump_P.LorentzForceGain_Gain_l *
      CO_bump_B.Add1_ce;
    CO_bump_B.MultiportSwitch[0] = CO_bump_B.LorentzForceGain[0];
    CO_bump_B.MultiportSwitch[1] = CO_bump_B.LorentzForceGain[1];
    break;

   default:
    /* MultiPortSwitch: '<S3>/dynamicAngle Switch' incorporates:
     *  Constant: '<S3>/DynamicAngle'
     *  Constant: '<S3>/visAngle'
     */
    if ((int32_T)CO_bump_P.DynamicAngle_Value_p == 0) {
      CO_bump_B.dynamicAngleSwitch = CO_bump_P.visAngle_Value_f;
    } else {
      /* Gain: '<S3>/Gain' */
      CO_bump_B.Gain_b = CO_bump_P.Gain_Gain_m * CO_bump_B.Add_m;
      CO_bump_B.dynamicAngleSwitch = CO_bump_B.Gain_b;
    }

    /* End of MultiPortSwitch: '<S3>/dynamicAngle Switch' */

    /* Trigonometry: '<S23>/sin' */
    CO_bump_B.sin_a = sin(CO_bump_B.dynamicAngleSwitch);

    /* Gain: '<S23>/Inverter' */
    CO_bump_B.Inverter[0] = CO_bump_P.Inverter_Gain_b * CO_bump_B.Switch_j[0];
    CO_bump_B.Inverter[1] = CO_bump_P.Inverter_Gain_b * CO_bump_B.Switch_j[1];

    /* Product: '<S23>/Product3' */
    CO_bump_B.Product3_o = CO_bump_B.Inverter[0] * CO_bump_B.sin_a;

    /* Trigonometry: '<S23>/cos' */
    CO_bump_B.cos_k = cos(CO_bump_B.dynamicAngleSwitch);

    /* Product: '<S23>/Product2' */
    CO_bump_B.Product2_g = CO_bump_B.Inverter[1] * CO_bump_B.cos_k;

    /* Sum: '<S23>/Subtract' */
    CO_bump_B.Subtract_i = CO_bump_B.Product2_g - CO_bump_B.Product3_o;

    /* Product: '<S23>/Product1' */
    CO_bump_B.Product1_a = CO_bump_B.Inverter[1] * CO_bump_B.sin_a;

    /* Product: '<S23>/Product' */
    CO_bump_B.Product_c = CO_bump_B.Inverter[0] * CO_bump_B.cos_k;

    /* Sum: '<S23>/Add' */
    CO_bump_B.Add_a = CO_bump_B.Product_c + CO_bump_B.Product1_a;

    /* Gain: '<S23>/Gain' */
    CO_bump_B.Gain_h[0] = CO_bump_P.Gain_Gain_d * CO_bump_B.Add_a;
    CO_bump_B.Gain_h[1] = CO_bump_P.Gain_Gain_d * CO_bump_B.Subtract_i;
    CO_bump_B.MultiportSwitch[0] = CO_bump_B.Gain_h[0];
    CO_bump_B.MultiportSwitch[1] = CO_bump_B.Gain_h[1];
    break;
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch' */

  /* UnitDelay: '<S18>/x' */
  CO_bump_B.x_o = CO_bump_DW.x_DSTATE_p;

  /* UnitDelay: '<S19>/x' */
  CO_bump_B.x_b = CO_bump_DW.x_DSTATE_ix;

  /* Sum: '<S16>/Add' */
  CO_bump_B.Add_h = CO_bump_B.x_o - CO_bump_B.x_b;

  /* UnitDelay: '<S20>/x' */
  CO_bump_B.x_ox = CO_bump_DW.x_DSTATE_f;

  /* UnitDelay: '<S21>/x' */
  CO_bump_B.x_e = CO_bump_DW.x_DSTATE_l;

  /* MultiPortSwitch: '<S2>/LoadSelect Switch' incorporates:
   *  Constant: '<S2>/Load'
   *  Constant: '<S2>/Off'
   *  Constant: '<S2>/staticX'
   *  Constant: '<S2>/staticY'
   */
  switch ((int32_T)CO_bump_P.Load_Value_e) {
   case 0:
    CO_bump_B.LoadSelectSwitch[0] = CO_bump_P.Off_Value;
    CO_bump_B.LoadSelectSwitch[1] = CO_bump_P.Off_Value;
    break;

   case 1:
    CO_bump_B.LoadSelectSwitch[0] = CO_bump_P.staticX_Value;
    CO_bump_B.LoadSelectSwitch[1] = CO_bump_P.staticY_Value;
    break;

   case 2:
    /* Sum: '<S16>/Add1' */
    CO_bump_B.Add1_li = CO_bump_B.x_ox - CO_bump_B.x_e;

    /* Gain: '<S2>/LorentzForceGain' */
    CO_bump_B.LorentzForceGain_f[0] = CO_bump_P.LorentzForceGain_Gain *
      CO_bump_B.Add_h;
    CO_bump_B.LorentzForceGain_f[1] = CO_bump_P.LorentzForceGain_Gain *
      CO_bump_B.Add1_li;
    CO_bump_B.LoadSelectSwitch[0] = CO_bump_B.LorentzForceGain_f[0];
    CO_bump_B.LoadSelectSwitch[1] = CO_bump_B.LorentzForceGain_f[1];
    break;

   default:
    /* MultiPortSwitch: '<S2>/DynamicAngle Switch' incorporates:
     *  Constant: '<S2>/DynamicAngle'
     *  Constant: '<S2>/visAngle'
     */
    if ((int32_T)CO_bump_P.DynamicAngle_Value == 0) {
      CO_bump_B.DynamicAngleSwitch = CO_bump_P.visAngle_Value;
    } else {
      /* Gain: '<S2>/Gain' */
      CO_bump_B.Gain_c = CO_bump_P.Gain_Gain * CO_bump_B.Add_h;
      CO_bump_B.DynamicAngleSwitch = CO_bump_B.Gain_c;
    }

    /* End of MultiPortSwitch: '<S2>/DynamicAngle Switch' */

    /* Trigonometry: '<S17>/sin' */
    CO_bump_B.sin_i = sin(CO_bump_B.DynamicAngleSwitch);

    /* Gain: '<S17>/Inverter' */
    CO_bump_B.Inverter_c[0] = CO_bump_P.Inverter_Gain * CO_bump_B.Switch_j[0];
    CO_bump_B.Inverter_c[1] = CO_bump_P.Inverter_Gain * CO_bump_B.Switch_j[1];

    /* Product: '<S17>/Product3' */
    CO_bump_B.Product3_d = CO_bump_B.Inverter_c[0] * CO_bump_B.sin_i;

    /* Trigonometry: '<S17>/cos' */
    CO_bump_B.cos_d = cos(CO_bump_B.DynamicAngleSwitch);

    /* Product: '<S17>/Product2' */
    CO_bump_B.Product2_o = CO_bump_B.Inverter_c[1] * CO_bump_B.cos_d;

    /* Sum: '<S17>/Subtract' */
    CO_bump_B.Subtract_h = CO_bump_B.Product2_o - CO_bump_B.Product3_d;

    /* Product: '<S17>/Product1' */
    CO_bump_B.Product1_d = CO_bump_B.Inverter_c[1] * CO_bump_B.sin_i;

    /* Product: '<S17>/Product' */
    CO_bump_B.Product_p = CO_bump_B.Inverter_c[0] * CO_bump_B.cos_d;

    /* Sum: '<S17>/Add' */
    CO_bump_B.Add_c = CO_bump_B.Product_p + CO_bump_B.Product1_d;

    /* Gain: '<S17>/Gain' */
    CO_bump_B.Gain_a[0] = CO_bump_P.Gain_Gain_i * CO_bump_B.Add_c;
    CO_bump_B.Gain_a[1] = CO_bump_P.Gain_Gain_i * CO_bump_B.Subtract_h;
    CO_bump_B.LoadSelectSwitch[0] = CO_bump_B.Gain_a[0];
    CO_bump_B.LoadSelectSwitch[1] = CO_bump_B.Gain_a[1];
    break;
  }

  /* End of MultiPortSwitch: '<S2>/LoadSelect Switch' */

  /* Level2 S-Function Block: '<Root>/Behavior CO Bump' (mastercon_CO_bump) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[13];
    sfcnOutputs(rts, 0);
  }

  /* Pack: <S8>/Pack */
  (void) memcpy(&CO_bump_B.Pack[0], &CO_bump_P.PacketSpec_Value,
                4);
  (void) memcpy(&CO_bump_B.Pack[4], &CO_bump_P.NaNupperbytes_Value,
                4);
  (void) memcpy(&CO_bump_B.Pack[8], &CO_bump_B.BehaviorCOBump_o6[0],
                8);
  (void) memcpy(&CO_bump_B.Pack[16], &CO_bump_B.BehaviorCOBump_o6[1],
                8);
  (void) memcpy(&CO_bump_B.Pack[24], &CO_bump_B.BehaviorCOBump_o8[0],
                8);
  (void) memcpy(&CO_bump_B.Pack[32], &CO_bump_B.BehaviorCOBump_o8[1],
                8);
  (void) memcpy(&CO_bump_B.Pack[40], &CO_bump_P.TargetCount_Value,
                8);
  (void) memcpy(&CO_bump_B.Pack[48], &CO_bump_B.BehaviorCOBump_o4[0],
                680);

  /* RateTransition: '<S8>/Rate Transition' */
  if (CO_bump_M->Timing.RateInteraction.TID1_2) {
    memcpy(&CO_bump_B.RateTransition[0], &CO_bump_B.Pack[0], 728U * sizeof
           (uint8_T));
  }

  /* End of RateTransition: '<S8>/Rate Transition' */
  /* ok to acquire for <S9>/S-Function */
  CO_bump_DW.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S12>/S-Function */
  CO_bump_DW.SFunction_IWORK_e.AcquireOK = 1;

  /* ok to acquire for <S15>/S-Function */
  CO_bump_DW.SFunction_IWORK_c.AcquireOK = 1;

  /* RelationalOperator: '<S1>/Relational Operator' incorporates:
   *  Constant: '<S1>/XLowLimit'
   */
  CO_bump_B.RelationalOperator = (CO_bump_B.Sum3_c < CO_bump_P.XLowLimit_Value);

  /* RelationalOperator: '<S1>/Relational Operator1' incorporates:
   *  Constant: '<S1>/XHighLimit'
   */
  CO_bump_B.RelationalOperator1 = (CO_bump_B.Sum3_c > CO_bump_P.XHighLimit_Value);

  /* RelationalOperator: '<S1>/Relational Operator2' incorporates:
   *  Constant: '<S1>/YHighLimit'
   */
  CO_bump_B.RelationalOperator2 = (CO_bump_B.Sum2 < CO_bump_P.YHighLimit_Value);

  /* RelationalOperator: '<S1>/Relational Operator3' incorporates:
   *  Constant: '<S1>/YLowLimit'
   */
  CO_bump_B.RelationalOperator3 = (CO_bump_B.Sum2 > CO_bump_P.YLowLimit_Value);

  /* Logic: '<S1>/Logical Operator' */
  CO_bump_B.LogicalOperator = (CO_bump_B.RelationalOperator ||
    CO_bump_B.RelationalOperator1 || CO_bump_B.RelationalOperator2 ||
    CO_bump_B.RelationalOperator3);

  /* Logic: '<S1>/Logical Operator2' incorporates:
   *  Constant: '<S1>/DisableBoundingBox'
   */
  CO_bump_B.LogicalOperator2 = !(CO_bump_P.DisableBoundingBox_Value != 0.0);

  /* Logic: '<S1>/Logical Operator1' */
  CO_bump_B.LogicalOperator1 = (CO_bump_B.LogicalOperator2 &&
    CO_bump_B.LogicalOperator);

  /* UnitDelay: '<S18>/y' */
  CO_bump_B.y = CO_bump_DW.y_DSTATE;

  /* Sum: '<S18>/Add1' */
  CO_bump_B.Add1 = CO_bump_B.y - CO_bump_B.x_o;

  /* UnitDelay: '<S18>/z' */
  CO_bump_B.z = CO_bump_DW.z_DSTATE;

  /* Sum: '<S18>/Add3' incorporates:
   *  Constant: '<S18>/rho'
   */
  CO_bump_B.Add3 = CO_bump_P.rho_Value - CO_bump_B.z;

  /* Product: '<S18>/product2' */
  CO_bump_B.product2 = CO_bump_B.x_o * CO_bump_B.Add3;

  /* Sum: '<S18>/Add2' */
  CO_bump_B.Add2_o = CO_bump_B.product2 - CO_bump_B.y;

  /* Product: '<S18>/product3' incorporates:
   *  Constant: '<S18>/beta'
   */
  CO_bump_B.product3 = CO_bump_B.z * CO_bump_P.beta_Value;

  /* Product: '<S18>/product4' */
  CO_bump_B.product4 = CO_bump_B.y * CO_bump_B.x_o;

  /* Sum: '<S18>/Add4' */
  CO_bump_B.Add4 = CO_bump_B.product4 - CO_bump_B.product3;

  /* Product: '<S18>/product1' incorporates:
   *  Constant: '<S18>/sigma'
   */
  CO_bump_B.product1 = CO_bump_B.Add1 * CO_bump_P.sigma_Value;

  /* Product: '<S18>/dX' incorporates:
   *  Constant: '<S18>/timescale'
   */
  CO_bump_B.dX = CO_bump_P.timescale_Value * CO_bump_B.product1;

  /* Sum: '<S18>/AddX' */
  CO_bump_B.AddX = CO_bump_B.x_o + CO_bump_B.dX;

  /* Product: '<S18>/dY' incorporates:
   *  Constant: '<S18>/timescale'
   */
  CO_bump_B.dY = CO_bump_P.timescale_Value * CO_bump_B.Add2_o;

  /* Sum: '<S18>/AddX1' */
  CO_bump_B.AddX1 = CO_bump_B.y + CO_bump_B.dY;

  /* Product: '<S18>/dZ' incorporates:
   *  Constant: '<S18>/timescale'
   */
  CO_bump_B.dZ = CO_bump_P.timescale_Value * CO_bump_B.Add4;

  /* Sum: '<S18>/AddX2' */
  CO_bump_B.AddX2 = CO_bump_B.z + CO_bump_B.dZ;

  /* UnitDelay: '<S19>/y' */
  CO_bump_B.y_m = CO_bump_DW.y_DSTATE_n;

  /* Sum: '<S19>/Add1' */
  CO_bump_B.Add1_l = CO_bump_B.y_m - CO_bump_B.x_b;

  /* UnitDelay: '<S19>/z' */
  CO_bump_B.z_g = CO_bump_DW.z_DSTATE_f;

  /* Sum: '<S19>/Add3' incorporates:
   *  Constant: '<S19>/rho'
   */
  CO_bump_B.Add3_n = CO_bump_P.rho_Value_k - CO_bump_B.z_g;

  /* Product: '<S19>/product2' */
  CO_bump_B.product2_i = CO_bump_B.x_b * CO_bump_B.Add3_n;

  /* Sum: '<S19>/Add2' */
  CO_bump_B.Add2_i = CO_bump_B.product2_i - CO_bump_B.y_m;

  /* Product: '<S19>/product3' incorporates:
   *  Constant: '<S19>/beta'
   */
  CO_bump_B.product3_d = CO_bump_B.z_g * CO_bump_P.beta_Value_d;

  /* Product: '<S19>/product4' */
  CO_bump_B.product4_c = CO_bump_B.y_m * CO_bump_B.x_b;

  /* Sum: '<S19>/Add4' */
  CO_bump_B.Add4_i = CO_bump_B.product4_c - CO_bump_B.product3_d;

  /* Product: '<S19>/product1' incorporates:
   *  Constant: '<S19>/sigma'
   */
  CO_bump_B.product1_j = CO_bump_B.Add1_l * CO_bump_P.sigma_Value_g;

  /* Product: '<S19>/dX' incorporates:
   *  Constant: '<S19>/timescale'
   */
  CO_bump_B.dX_a = CO_bump_P.timescale_Value_a * CO_bump_B.product1_j;

  /* Sum: '<S19>/AddX' */
  CO_bump_B.AddX_g = CO_bump_B.x_b + CO_bump_B.dX_a;

  /* Product: '<S19>/dY' incorporates:
   *  Constant: '<S19>/timescale'
   */
  CO_bump_B.dY_o = CO_bump_P.timescale_Value_a * CO_bump_B.Add2_i;

  /* Sum: '<S19>/AddX1' */
  CO_bump_B.AddX1_j = CO_bump_B.y_m + CO_bump_B.dY_o;

  /* Product: '<S19>/dZ' incorporates:
   *  Constant: '<S19>/timescale'
   */
  CO_bump_B.dZ_o = CO_bump_P.timescale_Value_a * CO_bump_B.Add4_i;

  /* Sum: '<S19>/AddX2' */
  CO_bump_B.AddX2_l = CO_bump_B.z_g + CO_bump_B.dZ_o;

  /* UnitDelay: '<S20>/y' */
  CO_bump_B.y_f = CO_bump_DW.y_DSTATE_k;

  /* Sum: '<S20>/Add1' */
  CO_bump_B.Add1_g = CO_bump_B.y_f - CO_bump_B.x_ox;

  /* UnitDelay: '<S20>/z' */
  CO_bump_B.z_p = CO_bump_DW.z_DSTATE_l;

  /* Sum: '<S20>/Add3' incorporates:
   *  Constant: '<S20>/rho'
   */
  CO_bump_B.Add3_i = CO_bump_P.rho_Value_c - CO_bump_B.z_p;

  /* Product: '<S20>/product2' */
  CO_bump_B.product2_j = CO_bump_B.x_ox * CO_bump_B.Add3_i;

  /* Sum: '<S20>/Add2' */
  CO_bump_B.Add2_p = CO_bump_B.product2_j - CO_bump_B.y_f;

  /* Product: '<S20>/product3' incorporates:
   *  Constant: '<S20>/beta'
   */
  CO_bump_B.product3_o = CO_bump_B.z_p * CO_bump_P.beta_Value_a;

  /* Product: '<S20>/product4' */
  CO_bump_B.product4_o = CO_bump_B.y_f * CO_bump_B.x_ox;

  /* Sum: '<S20>/Add4' */
  CO_bump_B.Add4_j = CO_bump_B.product4_o - CO_bump_B.product3_o;

  /* Product: '<S20>/product1' incorporates:
   *  Constant: '<S20>/sigma'
   */
  CO_bump_B.product1_a = CO_bump_B.Add1_g * CO_bump_P.sigma_Value_gy;

  /* Product: '<S20>/dX' incorporates:
   *  Constant: '<S20>/timescale'
   */
  CO_bump_B.dX_p = CO_bump_P.timescale_Value_i * CO_bump_B.product1_a;

  /* Sum: '<S20>/AddX' */
  CO_bump_B.AddX_n = CO_bump_B.x_ox + CO_bump_B.dX_p;

  /* Product: '<S20>/dY' incorporates:
   *  Constant: '<S20>/timescale'
   */
  CO_bump_B.dY_h = CO_bump_P.timescale_Value_i * CO_bump_B.Add2_p;

  /* Sum: '<S20>/AddX1' */
  CO_bump_B.AddX1_d = CO_bump_B.y_f + CO_bump_B.dY_h;

  /* Product: '<S20>/dZ' incorporates:
   *  Constant: '<S20>/timescale'
   */
  CO_bump_B.dZ_k = CO_bump_P.timescale_Value_i * CO_bump_B.Add4_j;

  /* Sum: '<S20>/AddX2' */
  CO_bump_B.AddX2_h = CO_bump_B.z_p + CO_bump_B.dZ_k;

  /* UnitDelay: '<S21>/y' */
  CO_bump_B.y_c = CO_bump_DW.y_DSTATE_a;

  /* Sum: '<S21>/Add1' */
  CO_bump_B.Add1_l1 = CO_bump_B.y_c - CO_bump_B.x_e;

  /* UnitDelay: '<S21>/z' */
  CO_bump_B.z_i = CO_bump_DW.z_DSTATE_a;

  /* Sum: '<S21>/Add3' incorporates:
   *  Constant: '<S21>/rho'
   */
  CO_bump_B.Add3_g = CO_bump_P.rho_Value_e - CO_bump_B.z_i;

  /* Product: '<S21>/product2' */
  CO_bump_B.product2_e = CO_bump_B.x_e * CO_bump_B.Add3_g;

  /* Sum: '<S21>/Add2' */
  CO_bump_B.Add2_n = CO_bump_B.product2_e - CO_bump_B.y_c;

  /* Product: '<S21>/product3' incorporates:
   *  Constant: '<S21>/beta'
   */
  CO_bump_B.product3_b = CO_bump_B.z_i * CO_bump_P.beta_Value_o;

  /* Product: '<S21>/product4' */
  CO_bump_B.product4_i = CO_bump_B.y_c * CO_bump_B.x_e;

  /* Sum: '<S21>/Add4' */
  CO_bump_B.Add4_n = CO_bump_B.product4_i - CO_bump_B.product3_b;

  /* Product: '<S21>/product1' incorporates:
   *  Constant: '<S21>/sigma'
   */
  CO_bump_B.product1_h = CO_bump_B.Add1_l1 * CO_bump_P.sigma_Value_a;

  /* Product: '<S21>/dX' incorporates:
   *  Constant: '<S21>/timescale'
   */
  CO_bump_B.dX_o = CO_bump_P.timescale_Value_h * CO_bump_B.product1_h;

  /* Sum: '<S21>/AddX' */
  CO_bump_B.AddX_c = CO_bump_B.x_e + CO_bump_B.dX_o;

  /* Product: '<S21>/dY' incorporates:
   *  Constant: '<S21>/timescale'
   */
  CO_bump_B.dY_m = CO_bump_P.timescale_Value_h * CO_bump_B.Add2_n;

  /* Sum: '<S21>/AddX1' */
  CO_bump_B.AddX1_o = CO_bump_B.y_c + CO_bump_B.dY_m;

  /* Product: '<S21>/dZ' incorporates:
   *  Constant: '<S21>/timescale'
   */
  CO_bump_B.dZ_om = CO_bump_P.timescale_Value_h * CO_bump_B.Add4_n;

  /* Sum: '<S21>/AddX2' */
  CO_bump_B.AddX2_a = CO_bump_B.z_i + CO_bump_B.dZ_om;

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix Concatenation1In1' */
  CO_bump_B.MatrixConcatenation1[0] = CO_bump_B.Switch_d[0];
  CO_bump_B.MatrixConcatenation1[1] = CO_bump_B.Switch_d[1];

  /* SignalConversion: '<Root>/ConcatBufferAtMatrix Concatenation1In2' */
  CO_bump_B.MatrixConcatenation1[2] = CO_bump_B.Switch_j[0];
  CO_bump_B.MatrixConcatenation1[3] = CO_bump_B.Switch_j[1];

  /* UnitDelay: '<S24>/y' */
  CO_bump_B.y_o = CO_bump_DW.y_DSTATE_g;

  /* Sum: '<S24>/Add1' */
  CO_bump_B.Add1_b = CO_bump_B.y_o - CO_bump_B.x;

  /* UnitDelay: '<S24>/z' */
  CO_bump_B.z_e = CO_bump_DW.z_DSTATE_k;

  /* Sum: '<S24>/Add3' incorporates:
   *  Constant: '<S24>/rho'
   */
  CO_bump_B.Add3_a = CO_bump_P.rho_Value_c0 - CO_bump_B.z_e;

  /* Product: '<S24>/product2' */
  CO_bump_B.product2_l = CO_bump_B.x * CO_bump_B.Add3_a;

  /* Sum: '<S24>/Add2' */
  CO_bump_B.Add2_l = CO_bump_B.product2_l - CO_bump_B.y_o;

  /* Product: '<S24>/product3' incorporates:
   *  Constant: '<S24>/beta'
   */
  CO_bump_B.product3_j = CO_bump_B.z_e * CO_bump_P.beta_Value_k;

  /* Product: '<S24>/product4' */
  CO_bump_B.product4_a = CO_bump_B.y_o * CO_bump_B.x;

  /* Sum: '<S24>/Add4' */
  CO_bump_B.Add4_g = CO_bump_B.product4_a - CO_bump_B.product3_j;

  /* Product: '<S24>/product1' incorporates:
   *  Constant: '<S24>/sigma'
   */
  CO_bump_B.product1_i = CO_bump_B.Add1_b * CO_bump_P.sigma_Value_ax;

  /* Product: '<S24>/dX' incorporates:
   *  Constant: '<S24>/timescale'
   */
  CO_bump_B.dX_b = CO_bump_P.timescale_Value_b * CO_bump_B.product1_i;

  /* Sum: '<S24>/AddX' */
  CO_bump_B.AddX_f = CO_bump_B.x + CO_bump_B.dX_b;

  /* Product: '<S24>/dY' incorporates:
   *  Constant: '<S24>/timescale'
   */
  CO_bump_B.dY_a = CO_bump_P.timescale_Value_b * CO_bump_B.Add2_l;

  /* Sum: '<S24>/AddX1' */
  CO_bump_B.AddX1_f = CO_bump_B.y_o + CO_bump_B.dY_a;

  /* Product: '<S24>/dZ' incorporates:
   *  Constant: '<S24>/timescale'
   */
  CO_bump_B.dZ_h = CO_bump_P.timescale_Value_b * CO_bump_B.Add4_g;

  /* Sum: '<S24>/AddX2' */
  CO_bump_B.AddX2_g = CO_bump_B.z_e + CO_bump_B.dZ_h;

  /* UnitDelay: '<S25>/y' */
  CO_bump_B.y_i = CO_bump_DW.y_DSTATE_b;

  /* Sum: '<S25>/Add1' */
  CO_bump_B.Add1_h = CO_bump_B.y_i - CO_bump_B.x_m;

  /* UnitDelay: '<S25>/z' */
  CO_bump_B.z_pw = CO_bump_DW.z_DSTATE_m;

  /* Sum: '<S25>/Add3' incorporates:
   *  Constant: '<S25>/rho'
   */
  CO_bump_B.Add3_f = CO_bump_P.rho_Value_h - CO_bump_B.z_pw;

  /* Product: '<S25>/product2' */
  CO_bump_B.product2_li = CO_bump_B.x_m * CO_bump_B.Add3_f;

  /* Sum: '<S25>/Add2' */
  CO_bump_B.Add2_m = CO_bump_B.product2_li - CO_bump_B.y_i;

  /* Product: '<S25>/product3' incorporates:
   *  Constant: '<S25>/beta'
   */
  CO_bump_B.product3_e = CO_bump_B.z_pw * CO_bump_P.beta_Value_ko;

  /* Product: '<S25>/product4' */
  CO_bump_B.product4_iq = CO_bump_B.y_i * CO_bump_B.x_m;

  /* Sum: '<S25>/Add4' */
  CO_bump_B.Add4_gm = CO_bump_B.product4_iq - CO_bump_B.product3_e;

  /* Product: '<S25>/product1' incorporates:
   *  Constant: '<S25>/sigma'
   */
  CO_bump_B.product1_l = CO_bump_B.Add1_h * CO_bump_P.sigma_Value_k;

  /* Product: '<S25>/dX' incorporates:
   *  Constant: '<S25>/timescale'
   */
  CO_bump_B.dX_f = CO_bump_P.timescale_Value_ab * CO_bump_B.product1_l;

  /* Sum: '<S25>/AddX' */
  CO_bump_B.AddX_d = CO_bump_B.x_m + CO_bump_B.dX_f;

  /* Product: '<S25>/dY' incorporates:
   *  Constant: '<S25>/timescale'
   */
  CO_bump_B.dY_f = CO_bump_P.timescale_Value_ab * CO_bump_B.Add2_m;

  /* Sum: '<S25>/AddX1' */
  CO_bump_B.AddX1_g = CO_bump_B.y_i + CO_bump_B.dY_f;

  /* Product: '<S25>/dZ' incorporates:
   *  Constant: '<S25>/timescale'
   */
  CO_bump_B.dZ_g = CO_bump_P.timescale_Value_ab * CO_bump_B.Add4_gm;

  /* Sum: '<S25>/AddX2' */
  CO_bump_B.AddX2_o = CO_bump_B.z_pw + CO_bump_B.dZ_g;

  /* UnitDelay: '<S26>/y' */
  CO_bump_B.y_od = CO_bump_DW.y_DSTATE_kn;

  /* Sum: '<S26>/Add1' */
  CO_bump_B.Add1_a = CO_bump_B.y_od - CO_bump_B.x_f;

  /* UnitDelay: '<S26>/z' */
  CO_bump_B.z_n = CO_bump_DW.z_DSTATE_d;

  /* Sum: '<S26>/Add3' incorporates:
   *  Constant: '<S26>/rho'
   */
  CO_bump_B.Add3_b = CO_bump_P.rho_Value_cw - CO_bump_B.z_n;

  /* Product: '<S26>/product2' */
  CO_bump_B.product2_m = CO_bump_B.x_f * CO_bump_B.Add3_b;

  /* Sum: '<S26>/Add2' */
  CO_bump_B.Add2_oy = CO_bump_B.product2_m - CO_bump_B.y_od;

  /* Product: '<S26>/product3' incorporates:
   *  Constant: '<S26>/beta'
   */
  CO_bump_B.product3_n = CO_bump_B.z_n * CO_bump_P.beta_Value_i;

  /* Product: '<S26>/product4' */
  CO_bump_B.product4_cs = CO_bump_B.y_od * CO_bump_B.x_f;

  /* Sum: '<S26>/Add4' */
  CO_bump_B.Add4_d = CO_bump_B.product4_cs - CO_bump_B.product3_n;

  /* Product: '<S26>/product1' incorporates:
   *  Constant: '<S26>/sigma'
   */
  CO_bump_B.product1_ap = CO_bump_B.Add1_a * CO_bump_P.sigma_Value_h;

  /* Product: '<S26>/dX' incorporates:
   *  Constant: '<S26>/timescale'
   */
  CO_bump_B.dX_d = CO_bump_P.timescale_Value_p * CO_bump_B.product1_ap;

  /* Sum: '<S26>/AddX' */
  CO_bump_B.AddX_j = CO_bump_B.x_f + CO_bump_B.dX_d;

  /* Product: '<S26>/dY' incorporates:
   *  Constant: '<S26>/timescale'
   */
  CO_bump_B.dY_oz = CO_bump_P.timescale_Value_p * CO_bump_B.Add2_oy;

  /* Sum: '<S26>/AddX1' */
  CO_bump_B.AddX1_k = CO_bump_B.y_od + CO_bump_B.dY_oz;

  /* Product: '<S26>/dZ' incorporates:
   *  Constant: '<S26>/timescale'
   */
  CO_bump_B.dZ_i = CO_bump_P.timescale_Value_p * CO_bump_B.Add4_d;

  /* Sum: '<S26>/AddX2' */
  CO_bump_B.AddX2_l1 = CO_bump_B.z_n + CO_bump_B.dZ_i;

  /* UnitDelay: '<S27>/y' */
  CO_bump_B.y_k = CO_bump_DW.y_DSTATE_j;

  /* Sum: '<S27>/Add1' */
  CO_bump_B.Add1_n = CO_bump_B.y_k - CO_bump_B.x_g;

  /* UnitDelay: '<S27>/z' */
  CO_bump_B.z_gt = CO_bump_DW.z_DSTATE_d0;

  /* Sum: '<S27>/Add3' incorporates:
   *  Constant: '<S27>/rho'
   */
  CO_bump_B.Add3_j = CO_bump_P.rho_Value_f - CO_bump_B.z_gt;

  /* Product: '<S27>/product2' */
  CO_bump_B.product2_c = CO_bump_B.x_g * CO_bump_B.Add3_j;

  /* Sum: '<S27>/Add2' */
  CO_bump_B.Add2_e = CO_bump_B.product2_c - CO_bump_B.y_k;

  /* Product: '<S27>/product3' incorporates:
   *  Constant: '<S27>/beta'
   */
  CO_bump_B.product3_f = CO_bump_B.z_gt * CO_bump_P.beta_Value_ix;

  /* Product: '<S27>/product4' */
  CO_bump_B.product4_m = CO_bump_B.y_k * CO_bump_B.x_g;

  /* Sum: '<S27>/Add4' */
  CO_bump_B.Add4_k = CO_bump_B.product4_m - CO_bump_B.product3_f;

  /* Product: '<S27>/product1' incorporates:
   *  Constant: '<S27>/sigma'
   */
  CO_bump_B.product1_m = CO_bump_B.Add1_n * CO_bump_P.sigma_Value_hl;

  /* Product: '<S27>/dX' incorporates:
   *  Constant: '<S27>/timescale'
   */
  CO_bump_B.dX_aq = CO_bump_P.timescale_Value_j * CO_bump_B.product1_m;

  /* Sum: '<S27>/AddX' */
  CO_bump_B.AddX_a = CO_bump_B.x_g + CO_bump_B.dX_aq;

  /* Product: '<S27>/dY' incorporates:
   *  Constant: '<S27>/timescale'
   */
  CO_bump_B.dY_p = CO_bump_P.timescale_Value_j * CO_bump_B.Add2_e;

  /* Sum: '<S27>/AddX1' */
  CO_bump_B.AddX1_m = CO_bump_B.y_k + CO_bump_B.dY_p;

  /* Product: '<S27>/dZ' incorporates:
   *  Constant: '<S27>/timescale'
   */
  CO_bump_B.dZ_b = CO_bump_P.timescale_Value_j * CO_bump_B.Add4_k;

  /* Sum: '<S27>/AddX2' */
  CO_bump_B.AddX2_ok = CO_bump_B.z_gt + CO_bump_B.dZ_b;

  /* Logic: '<S4>/Logical Operator2' incorporates:
   *  Constant: '<Root>/Use Neural Control'
   *  Constant: '<S4>/IsometricMode'
   */
  CO_bump_B.LogicalOperator2_h = ((CO_bump_P.UseNeuralControl_Value != 0.0) ||
    (CO_bump_P.IsometricMode_Value_i != 0.0));

  /* Clock: '<S33>/Clock' */
  CO_bump_B.Clock = CO_bump_M->Timing.t[0];

  /* Memory: '<S33>/Memory' */
  CO_bump_B.Memory_a = CO_bump_DW.Memory_PreviousInput_h;

  /* Memory: '<S4>/Memory' */
  CO_bump_B.Memory_f = CO_bump_DW.Memory_PreviousInput_f;

  /* Logic: '<S33>/Logical Operator2' */
  CO_bump_B.LogicalOperator2_g = (CO_bump_B.Memory_a || CO_bump_B.Memory_f);

  /* Logic: '<S33>/Logical Operator1' */
  CO_bump_B.LogicalOperator1_b = !CO_bump_B.LogicalOperator2_g;

  /* Outputs for Enabled SubSystem: '<S33>/Enabled Subsystem' */
  CO_bump_EnabledSubsystem(CO_bump_B.LogicalOperator1_b, CO_bump_B.Clock,
    &CO_bump_B.EnabledSubsystem, &CO_bump_DW.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S33>/Enabled Subsystem' */

  /* Sum: '<S33>/Sum' */
  CO_bump_B.Sum_h = CO_bump_B.Clock - CO_bump_B.EnabledSubsystem.In1;

  /* RelationalOperator: '<S35>/Compare' incorporates:
   *  Constant: '<S35>/Constant'
   */
  CO_bump_B.Compare_h = (uint8_T)(CO_bump_B.Sum_h > CO_bump_P.Constant_Value_l);

  /* Constant: '<S33>/Time' */
  CO_bump_B.Time = CO_bump_P.Schmidt_Time;

  /* RelationalOperator: '<S33>/Relational Operator' */
  CO_bump_B.RelationalOperator_e = (CO_bump_B.Sum_h > CO_bump_B.Time);

  /* Logic: '<S33>/Logical Operator' */
  CO_bump_B.LogicalOperator_l = (CO_bump_B.Compare_h != 0) ^
    CO_bump_B.RelationalOperator_e;

  /* DiscreteFir: '<S6>/Discrete FIR Filter' */
  tmp = 1;
  Bias = CO_bump_B.Switch_j[0] * CO_bump_P.DiscreteFIRFilter_Coefficients[0];
  for (i = CO_bump_DW.DiscreteFIRFilter_circBuf; i < 29; i++) {
    acc2 = CO_bump_DW.DiscreteFIRFilter_states[i] *
      CO_bump_P.DiscreteFIRFilter_Coefficients[tmp];
    Bias += acc2;
    tmp++;
  }

  for (i = 0; i < CO_bump_DW.DiscreteFIRFilter_circBuf; i++) {
    acc2 = CO_bump_DW.DiscreteFIRFilter_states[i] *
      CO_bump_P.DiscreteFIRFilter_Coefficients[tmp];
    Bias += acc2;
    tmp++;
  }

  CO_bump_B.DiscreteFIRFilter[0] = Bias;
  tmp = 1;
  Bias = CO_bump_B.Switch_j[1] * CO_bump_P.DiscreteFIRFilter_Coefficients[0];
  for (i = CO_bump_DW.DiscreteFIRFilter_circBuf; i < 29; i++) {
    acc2 = CO_bump_DW.DiscreteFIRFilter_states[29 + i] *
      CO_bump_P.DiscreteFIRFilter_Coefficients[tmp];
    Bias += acc2;
    tmp++;
  }

  for (i = 0; i < CO_bump_DW.DiscreteFIRFilter_circBuf; i++) {
    acc2 = CO_bump_DW.DiscreteFIRFilter_states[29 + i] *
      CO_bump_P.DiscreteFIRFilter_Coefficients[tmp];
    Bias += acc2;
    tmp++;
  }

  CO_bump_B.DiscreteFIRFilter[1] = Bias;

  /* End of DiscreteFir: '<S6>/Discrete FIR Filter' */

  /* Clock: '<S45>/Clock' */
  CO_bump_B.Clock_c = CO_bump_M->Timing.t[0];

  /* Memory: '<S45>/Memory' */
  CO_bump_B.Memory_iz = CO_bump_DW.Memory_PreviousInput_j;

  /* Logic: '<S6>/InBox' */
  CO_bump_B.InBox = !CO_bump_B.LogicalOperator1;

  /* Logic: '<S49>/Logical Operator3' */
  CO_bump_B.LogicalOperator3 = !CO_bump_B.InBox;

  /* Clock: '<S49>/Clock' */
  CO_bump_B.Clock_l = CO_bump_M->Timing.t[0];

  /* Memory: '<S49>/Memory' */
  CO_bump_B.Memory_m = CO_bump_DW.Memory_PreviousInput_b;

  /* Logic: '<S49>/Logical Operator4' */
  CO_bump_B.LogicalOperator4 = (CO_bump_B.Memory_m && CO_bump_B.LogicalOperator3);

  /* RelationalOperator: '<S37>/Compare' incorporates:
   *  Constant: '<S37>/Constant'
   */
  CO_bump_B.Compare_c = (uint8_T)(CO_bump_B.Switch_j[0] ==
    CO_bump_P.Constant_Value_c);

  /* RelationalOperator: '<S38>/Compare' incorporates:
   *  Constant: '<S38>/Constant'
   */
  CO_bump_B.Compare_d = (uint8_T)(CO_bump_B.Switch_j[1] ==
    CO_bump_P.Constant_Value_o);

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Constant: '<S6>/RecenterFlag'
   */
  CO_bump_B.LogicalOperator_m = ((CO_bump_P.RecenterFlag_Value != 0.0) &&
    (CO_bump_B.Compare_c != 0) && (CO_bump_B.Compare_d != 0) &&
    CO_bump_B.LogicalOperator1);

  /* Logic: '<S49>/Logical Operator2' */
  CO_bump_B.LogicalOperator2_a = (CO_bump_B.LogicalOperator4 ||
    CO_bump_B.LogicalOperator_m);

  /* Logic: '<S49>/Logical Operator1' */
  CO_bump_B.LogicalOperator1_p = !CO_bump_B.LogicalOperator2_a;

  /* Outputs for Enabled SubSystem: '<S49>/Enabled Subsystem' */
  CO_bump_EnabledSubsystem(CO_bump_B.LogicalOperator1_p, CO_bump_B.Clock_l,
    &CO_bump_B.EnabledSubsystem_e, &CO_bump_DW.EnabledSubsystem_e);

  /* End of Outputs for SubSystem: '<S49>/Enabled Subsystem' */

  /* Sum: '<S49>/Sum' */
  CO_bump_B.Sum_fl = CO_bump_B.Clock_l - CO_bump_B.EnabledSubsystem_e.In1;

  /* RelationalOperator: '<S62>/Compare' incorporates:
   *  Constant: '<S62>/Constant'
   */
  CO_bump_B.Compare_n = (uint8_T)(CO_bump_B.Sum_fl > CO_bump_P.Constant_Value_h);

  /* Constant: '<S49>/Time' */
  CO_bump_B.Time_b = CO_bump_P.Timer_Time;

  /* RelationalOperator: '<S49>/Relational Operator' */
  CO_bump_B.RelationalOperator_l = (CO_bump_B.Sum_fl > CO_bump_B.Time_b);

  /* Logic: '<S49>/Logical Operator' */
  CO_bump_B.LogicalOperator_k = (CO_bump_B.Compare_n != 0) ^
    CO_bump_B.RelationalOperator_l;

  /* RelationalOperator: '<S65>/Compare' incorporates:
   *  Constant: '<S65>/Constant'
   */
  CO_bump_B.Compare_d2 = (uint8_T)((int32_T)CO_bump_B.LogicalOperator_k <=
    (int32_T)CO_bump_P.Constant_Value_ow);

  /* UnitDelay: '<S63>/Delay Input1' */
  CO_bump_B.Uk1 = CO_bump_DW.DelayInput1_DSTATE;

  /* RelationalOperator: '<S63>/FixPt Relational Operator' */
  CO_bump_B.FixPtRelationalOperator = (uint8_T)(CO_bump_B.Compare_d2 >
    CO_bump_B.Uk1);

  /* Logic: '<S49>/Logical Operator5' */
  CO_bump_B.LogicalOperator5 = (CO_bump_B.LogicalOperator3 &&
    (CO_bump_B.FixPtRelationalOperator != 0));

  /* Logic: '<S45>/Logical Operator2' */
  CO_bump_B.LogicalOperator2_k = (CO_bump_B.Memory_iz ||
    CO_bump_B.LogicalOperator5);

  /* Logic: '<S45>/Logical Operator1' */
  CO_bump_B.LogicalOperator1_o = !CO_bump_B.LogicalOperator2_k;

  /* Outputs for Enabled SubSystem: '<S45>/Enabled Subsystem' */
  CO_bump_EnabledSubsystem(CO_bump_B.LogicalOperator1_o, CO_bump_B.Clock_c,
    &CO_bump_B.EnabledSubsystem_m, &CO_bump_DW.EnabledSubsystem_m);

  /* End of Outputs for SubSystem: '<S45>/Enabled Subsystem' */

  /* Sum: '<S45>/Sum' */
  CO_bump_B.Sum_n = CO_bump_B.Clock_c - CO_bump_B.EnabledSubsystem_m.In1;

  /* RelationalOperator: '<S55>/Compare' incorporates:
   *  Constant: '<S55>/Constant'
   */
  CO_bump_B.Compare_g = (uint8_T)(CO_bump_B.Sum_n > CO_bump_P.Constant_Value_n);

  /* Constant: '<S45>/Time' */
  CO_bump_B.Time_h = CO_bump_P.Schmidt1_Time;

  /* RelationalOperator: '<S45>/Relational Operator' */
  CO_bump_B.RelationalOperator_b = (CO_bump_B.Sum_n > CO_bump_B.Time_h);

  /* Logic: '<S45>/Logical Operator' */
  CO_bump_B.LogicalOperator_m1 = (CO_bump_B.Compare_g != 0) ^
    CO_bump_B.RelationalOperator_b;

  /* Abs: '<S42>/Abs2' */
  CO_bump_B.Abs2 = fabs(CO_bump_B.DiscreteFIRFilter[0]);

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Constant: '<S53>/Constant'
   */
  CO_bump_B.Compare_b = (uint8_T)(CO_bump_B.Abs2 <=
    CO_bump_P.CompareToConstant2_const);

  /* Abs: '<S42>/Abs3' */
  CO_bump_B.Abs3 = fabs(CO_bump_B.DiscreteFIRFilter[1]);

  /* RelationalOperator: '<S54>/Compare' incorporates:
   *  Constant: '<S54>/Constant'
   */
  CO_bump_B.Compare_ha = (uint8_T)(CO_bump_B.Abs3 <=
    CO_bump_P.CompareToConstant3_const);

  /* Logic: '<S42>/Logical Operator1' */
  CO_bump_B.LogicalOperator1_a = ((CO_bump_B.Compare_b != 0) &&
    (CO_bump_B.Compare_ha != 0));

  /* Logic: '<S6>/NOT' */
  CO_bump_B.NOT = !CO_bump_B.LogicalOperator1_a;

  /* Clock: '<S47>/Clock' */
  CO_bump_B.Clock_i = CO_bump_M->Timing.t[0];

  /* Memory: '<S47>/Memory' */
  CO_bump_B.Memory_j = CO_bump_DW.Memory_PreviousInput_is;

  /* RelationalOperator: '<S61>/Compare' incorporates:
   *  Constant: '<S61>/Constant'
   */
  CO_bump_B.Compare_m = (uint8_T)((int32_T)CO_bump_B.LogicalOperator1_a <=
    (int32_T)CO_bump_P.Constant_Value_ch);

  /* UnitDelay: '<S48>/Delay Input1' */
  CO_bump_B.Uk1_m = CO_bump_DW.DelayInput1_DSTATE_d;

  /* RelationalOperator: '<S48>/FixPt Relational Operator' */
  CO_bump_B.FixPtRelationalOperator_e = (uint8_T)(CO_bump_B.Compare_m >
    CO_bump_B.Uk1_m);

  /* Logic: '<S47>/Logical Operator2' */
  CO_bump_B.LogicalOperator2_m = (CO_bump_B.Memory_j ||
    (CO_bump_B.FixPtRelationalOperator_e != 0));

  /* Logic: '<S47>/Logical Operator1' */
  CO_bump_B.LogicalOperator1_bp = !CO_bump_B.LogicalOperator2_m;

  /* Outputs for Enabled SubSystem: '<S47>/Enabled Subsystem' */
  CO_bump_EnabledSubsystem(CO_bump_B.LogicalOperator1_bp, CO_bump_B.Clock_i,
    &CO_bump_B.EnabledSubsystem_l, &CO_bump_DW.EnabledSubsystem_l);

  /* End of Outputs for SubSystem: '<S47>/Enabled Subsystem' */

  /* Sum: '<S47>/Sum' */
  CO_bump_B.Sum_flx = CO_bump_B.Clock_i - CO_bump_B.EnabledSubsystem_l.In1;

  /* RelationalOperator: '<S59>/Compare' incorporates:
   *  Constant: '<S59>/Constant'
   */
  CO_bump_B.Compare_m3 = (uint8_T)(CO_bump_B.Sum_flx >
    CO_bump_P.Constant_Value_g);

  /* Constant: '<S47>/Time' */
  CO_bump_B.Time_k = CO_bump_P.Schmidt3_Time;

  /* RelationalOperator: '<S47>/Relational Operator' */
  CO_bump_B.RelationalOperator_e0 = (CO_bump_B.Sum_flx > CO_bump_B.Time_k);

  /* Logic: '<S47>/Logical Operator' */
  CO_bump_B.LogicalOperator_b = (CO_bump_B.Compare_m3 != 0) ^
    CO_bump_B.RelationalOperator_e0;

  /* RelationalOperator: '<S52>/Compare' incorporates:
   *  Constant: '<S52>/Constant'
   */
  CO_bump_B.Compare_l = (uint8_T)((int32_T)CO_bump_B.LogicalOperator_b <=
    (int32_T)CO_bump_P.Constant_Value_dl);

  /* UnitDelay: '<S41>/Delay Input1' */
  CO_bump_B.Uk1_a = CO_bump_DW.DelayInput1_DSTATE_m;

  /* RelationalOperator: '<S41>/FixPt Relational Operator' */
  CO_bump_B.FixPtRelationalOperator_n = (uint8_T)(CO_bump_B.Compare_l >
    CO_bump_B.Uk1_a);

  /* DataTypeConversion: '<S6>/Data Type Conversion2' */
  CO_bump_B.DataTypeConversion2 = (CO_bump_B.FixPtRelationalOperator_n != 0);

  /* Logic: '<S6>/Logical Operator1' */
  CO_bump_B.LogicalOperator1_i = (CO_bump_B.NOT || CO_bump_B.DataTypeConversion2);

  /* Clock: '<S46>/Clock' */
  CO_bump_B.Clock_e = CO_bump_M->Timing.t[0];

  /* Memory: '<S46>/Memory' */
  CO_bump_B.Memory_h = CO_bump_DW.Memory_PreviousInput_k;

  /* Logic: '<S46>/Logical Operator2' */
  CO_bump_B.LogicalOperator2_j = (CO_bump_B.Memory_h ||
    CO_bump_B.LogicalOperator5);

  /* Logic: '<S46>/Logical Operator1' */
  CO_bump_B.LogicalOperator1_m = !CO_bump_B.LogicalOperator2_j;

  /* Outputs for Enabled SubSystem: '<S46>/Enabled Subsystem' */
  CO_bump_EnabledSubsystem(CO_bump_B.LogicalOperator1_m, CO_bump_B.Clock_e,
    &CO_bump_B.EnabledSubsystem_d, &CO_bump_DW.EnabledSubsystem_d);

  /* End of Outputs for SubSystem: '<S46>/Enabled Subsystem' */

  /* Sum: '<S46>/Sum' */
  CO_bump_B.Sum_a = CO_bump_B.Clock_e - CO_bump_B.EnabledSubsystem_d.In1;

  /* RelationalOperator: '<S57>/Compare' incorporates:
   *  Constant: '<S57>/Constant'
   */
  CO_bump_B.Compare_bi = (uint8_T)(CO_bump_B.Sum_a > CO_bump_P.Constant_Value_nu);

  /* Constant: '<S46>/Time' */
  CO_bump_B.Time_j = CO_bump_P.Schmidt2_Time;

  /* RelationalOperator: '<S46>/Relational Operator' */
  CO_bump_B.RelationalOperator_ew = (CO_bump_B.Sum_a > CO_bump_B.Time_j);

  /* Logic: '<S46>/Logical Operator' */
  CO_bump_B.LogicalOperator_bx = (CO_bump_B.Compare_bi != 0) ^
    CO_bump_B.RelationalOperator_ew;

  /* RelationalOperator: '<S51>/Compare' incorporates:
   *  Constant: '<S51>/Constant'
   */
  CO_bump_B.Compare_p = (uint8_T)((int32_T)CO_bump_B.LogicalOperator_bx <=
    (int32_T)CO_bump_P.Constant_Value_f);

  /* UnitDelay: '<S40>/Delay Input1' */
  CO_bump_B.Uk1_b = CO_bump_DW.DelayInput1_DSTATE_p;

  /* RelationalOperator: '<S40>/FixPt Relational Operator' */
  CO_bump_B.FixPtRelationalOperator_j = (uint8_T)(CO_bump_B.Compare_p >
    CO_bump_B.Uk1_b);

  /* DataTypeConversion: '<S6>/Data Type Conversion1' */
  CO_bump_B.DataTypeConversion1 = (CO_bump_B.FixPtRelationalOperator_j != 0);

  /* Memory: '<S44>/Memory' */
  CO_bump_B.Memory_jb = CO_bump_DW.Memory_PreviousInput_d;

  /* CombinatorialLogic: '<S44>/Logic' */
  tmp_5 = CO_bump_B.LogicalOperator1_i;
  i = tmp_5;
  tmp_5 = CO_bump_B.DataTypeConversion1;
  i = (int32_T)(((uint32_T)i << 1) + tmp_5);
  tmp_5 = CO_bump_B.Memory_jb;
  i = (int32_T)(((uint32_T)i << 1) + tmp_5);
  CO_bump_B.Logic[0U] = CO_bump_P.Logic_table[(uint32_T)i];
  CO_bump_B.Logic[1U] = CO_bump_P.Logic_table[i + 8U];

  /* Logic: '<S6>/Logical Operator5' */
  CO_bump_B.LogicalOperator5_l = (CO_bump_B.Logic[1] ||
    CO_bump_B.LogicalOperator_bx || CO_bump_B.LogicalOperator1);

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S4>/zeroX'
   *  Constant: '<S4>/zeroY'
   *  Switch: '<S4>/Switch1'
   */
  if (CO_bump_B.LogicalOperator_l) {
    CO_bump_B.Switch2[0] = CO_bump_P.zeroX_Value;
    CO_bump_B.Switch2[1] = CO_bump_P.zeroY_Value;
  } else {
    if (CO_bump_B.LogicalOperator5_l) {
      /* Logic: '<S6>/Logical Operator6' incorporates:
       *  Switch: '<S4>/Switch1'
       */
      CO_bump_B.LogicalOperator6 = !CO_bump_B.LogicalOperator_m1;

      /* Logic: '<S6>/Logical Operator3' incorporates:
       *  Switch: '<S4>/Switch1'
       */
      CO_bump_B.LogicalOperator3_p = (CO_bump_B.LogicalOperator6 &&
        CO_bump_B.LogicalOperator1);

      /* Switch: '<S6>/Switch' incorporates:
       *  Switch: '<S4>/Switch1'
       */
      if (CO_bump_B.LogicalOperator3_p) {
        /* Gain: '<S6>/Bounding Box Viscosity' */
        CO_bump_B.BoundingBoxViscosity[0] = CO_bump_P.BoundingBoxViscosity_Gain *
          CO_bump_B.DiscreteFIRFilter[0];
        CO_bump_B.BoundingBoxViscosity[1] = CO_bump_P.BoundingBoxViscosity_Gain *
          CO_bump_B.DiscreteFIRFilter[1];

        /* Sum: '<S6>/Add' */
        CO_bump_B.Add_j = CO_bump_B.Switch_d[1] - CO_bump_B.yoffset;

        /* RelationalOperator: '<S39>/Compare' incorporates:
         *  Constant: '<S39>/Constant'
         */
        CO_bump_B.Compare_mm = (CO_bump_B.Add_j <= CO_bump_P.Constant_Value_d);

        /* Product: '<S6>/Product' */
        CO_bump_B.Product_l[0] = (real_T)CO_bump_B.Compare_mm *
          CO_bump_B.BoundingBoxViscosity[0];
        CO_bump_B.Product_l[1] = (real_T)CO_bump_B.Compare_mm *
          CO_bump_B.BoundingBoxViscosity[1];
        CO_bump_B.Switch_cu[0] = CO_bump_B.Product_l[0];
        CO_bump_B.Switch_cu[1] = CO_bump_B.Product_l[1];
      } else {
        /* Product: '<S43>/Product' */
        CO_bump_B.Product_o = CO_bump_B.Switch_d[0] * (real_T)
          CO_bump_B.LogicalOperator_m1;

        /* Gain: '<S43>/Gain1' */
        CO_bump_B.Gain1_ay = CO_bump_P.Gain1_Gain * CO_bump_B.Product_o;

        /* Saturate: '<S43>/Saturation' */
        Bias = CO_bump_B.Gain1_ay;
        acc2 = CO_bump_P.Saturation_LowerSat_a;
        tmp_0 = CO_bump_P.Saturation_UpperSat_l;
        if (Bias > tmp_0) {
          CO_bump_B.Saturation = tmp_0;
        } else if (Bias < acc2) {
          CO_bump_B.Saturation = acc2;
        } else {
          CO_bump_B.Saturation = Bias;
        }

        /* End of Saturate: '<S43>/Saturation' */

        /* Gain: '<S43>/Gain3' */
        CO_bump_B.Gain3_d = CO_bump_P.Gain3_Gain * CO_bump_B.DiscreteFIRFilter[0];

        /* Sum: '<S43>/Add' */
        CO_bump_B.Add_jr = CO_bump_B.Gain3_d + CO_bump_B.Saturation;

        /* Gain: '<S43>/Gain4' */
        CO_bump_B.Gain4 = CO_bump_P.Gain4_Gain * CO_bump_B.DiscreteFIRFilter[1];

        /* Product: '<S43>/Product1' */
        CO_bump_B.Product1_mk = (real_T)CO_bump_B.LogicalOperator_m1 *
          CO_bump_B.Switch_d[1];

        /* Gain: '<S43>/Gain2' */
        CO_bump_B.Gain2_f = CO_bump_P.Gain2_Gain * CO_bump_B.Product1_mk;

        /* Saturate: '<S43>/Saturation1' */
        Bias = CO_bump_B.Gain2_f;
        acc2 = CO_bump_P.Saturation1_LowerSat_c;
        tmp_0 = CO_bump_P.Saturation1_UpperSat_j;
        if (Bias > tmp_0) {
          CO_bump_B.Saturation1 = tmp_0;
        } else if (Bias < acc2) {
          CO_bump_B.Saturation1 = acc2;
        } else {
          CO_bump_B.Saturation1 = Bias;
        }

        /* End of Saturate: '<S43>/Saturation1' */

        /* Sum: '<S43>/Add1' */
        CO_bump_B.Add1_g3 = CO_bump_B.Saturation1 + CO_bump_B.Gain4;
        CO_bump_B.Switch_cu[0] = CO_bump_B.Add_jr;
        CO_bump_B.Switch_cu[1] = CO_bump_B.Add1_g3;
      }

      /* End of Switch: '<S6>/Switch' */

      /* Switch: '<S4>/Switch1' */
      CO_bump_B.Switch1[0] = CO_bump_B.Switch_cu[0];
      CO_bump_B.Switch1[1] = CO_bump_B.Switch_cu[1];
    } else {
      /* Switch: '<S4>/Switch1' */
      CO_bump_B.Switch1[0] = CO_bump_B.BehaviorCOBump_o1[0];
      CO_bump_B.Switch1[1] = CO_bump_B.BehaviorCOBump_o1[1];
    }

    CO_bump_B.Switch2[0] = CO_bump_B.Switch1[0];
    CO_bump_B.Switch2[1] = CO_bump_B.Switch1[1];
  }

  /* End of Switch: '<S4>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S4>/Force//Torque Transform' */
  /* Gain: '<S32>/Gain' */
  CO_bump_B.Gain_fi[0] = CO_bump_P.Gain_Gain_c * CO_bump_B.Switch2[0];
  CO_bump_B.Gain_fi[1] = CO_bump_P.Gain_Gain_c * CO_bump_B.Switch2[1];

  /* Math: '<S32>/Transpose' */
  CO_bump_B.Transpose[0] = CO_bump_B.MatrixConcatenate2[0];
  CO_bump_B.Transpose[1] = CO_bump_B.MatrixConcatenate2[2];
  CO_bump_B.Transpose[2] = CO_bump_B.MatrixConcatenate2[1];
  CO_bump_B.Transpose[3] = CO_bump_B.MatrixConcatenate2[3];

  /* Product: '<S32>/Matrix Multiply' */
  Bias = CO_bump_B.Transpose[0];
  acc2 = CO_bump_B.Transpose[1];
  tmp_0 = CO_bump_B.Transpose[2];
  tmp_1 = CO_bump_B.Transpose[3];
  tmp_2 = CO_bump_B.Gain_fi[0];
  tmp_3 = CO_bump_B.Gain_fi[1];
  tmp_4 = Bias * tmp_2;
  tmp_4 += tmp_0 * tmp_3;
  Bias = tmp_4;
  tmp_4 = acc2 * tmp_2;
  tmp_4 += tmp_1 * tmp_3;
  CO_bump_B.MatrixMultiply_e[0] = Bias;
  CO_bump_B.MatrixMultiply_e[1] = tmp_4;

  /* End of Outputs for SubSystem: '<S4>/Force//Torque Transform' */

  /* Gain: '<S4>/MG1' */
  CO_bump_B.MG1 = CO_bump_P.MG1_Gain * CO_bump_B.MatrixMultiply_e[0];

  /* Gain: '<S4>/MG2' */
  CO_bump_B.MG2 = CO_bump_P.MG2_Gain * CO_bump_B.MatrixMultiply_e[1];

  /* Switch: '<S4>/Switch3' incorporates:
   *  Constant: '<S4>/zero2'
   */
  if (CO_bump_B.LogicalOperator2_h) {
    CO_bump_B.Switch3[0] = CO_bump_P.zero2_Value[0];
    CO_bump_B.Switch3[1] = CO_bump_P.zero2_Value[1];
  } else {
    /* Saturate: '<S4>/Saturation' */
    Bias = CO_bump_B.MG1;
    acc2 = CO_bump_P.Saturation_LowerSat;
    tmp_0 = CO_bump_P.Saturation_UpperSat;
    if (Bias > tmp_0) {
      CO_bump_B.Saturation_g = tmp_0;
    } else if (Bias < acc2) {
      CO_bump_B.Saturation_g = acc2;
    } else {
      CO_bump_B.Saturation_g = Bias;
    }

    /* End of Saturate: '<S4>/Saturation' */

    /* Saturate: '<S4>/Saturation1' */
    Bias = CO_bump_B.MG2;
    acc2 = CO_bump_P.Saturation1_LowerSat;
    tmp_0 = CO_bump_P.Saturation1_UpperSat;
    if (Bias > tmp_0) {
      CO_bump_B.Saturation1_f = tmp_0;
    } else if (Bias < acc2) {
      CO_bump_B.Saturation1_f = acc2;
    } else {
      CO_bump_B.Saturation1_f = Bias;
    }

    /* End of Saturate: '<S4>/Saturation1' */
    CO_bump_B.Switch3[0] = CO_bump_B.Saturation_g;
    CO_bump_B.Switch3[1] = CO_bump_B.Saturation1_f;
  }

  /* End of Switch: '<S4>/Switch3' */

  /* RelationalOperator: '<S30>/Compare' incorporates:
   *  Constant: '<S30>/Constant'
   */
  CO_bump_B.Compare_a = (CO_bump_B.Switch3[0] >= CO_bump_P.Constant_Value_i);

  /* Switch: '<S4>/Switch4' */
  if (CO_bump_B.Compare_a) {
    /* Gain: '<S4>/GainM1Pos' */
    CO_bump_B.GainM1Pos = CO_bump_P.GainM1Pos_Gain * CO_bump_B.Switch3[0];
    CO_bump_B.Switch4 = CO_bump_B.GainM1Pos;
  } else {
    /* Gain: '<S4>/GainM1Neg' */
    CO_bump_B.GainM1Neg = CO_bump_P.GainM1Neg_Gain * CO_bump_B.Switch3[0];
    CO_bump_B.Switch4 = CO_bump_B.GainM1Neg;
  }

  /* End of Switch: '<S4>/Switch4' */

  /* RelationalOperator: '<S31>/Compare' incorporates:
   *  Constant: '<S31>/Constant'
   */
  CO_bump_B.Compare_lx = (CO_bump_B.Switch3[1] >= CO_bump_P.Constant_Value_a);

  /* Switch: '<S4>/Switch5' */
  if (CO_bump_B.Compare_lx) {
    /* Gain: '<S4>/GainM2Pos' */
    CO_bump_B.GainM2Pos = CO_bump_P.GainM2Pos_Gain * CO_bump_B.Switch3[1];
    CO_bump_B.Switch5 = CO_bump_B.GainM2Pos;
  } else {
    /* Gain: '<S4>/GainM2Neg' */
    CO_bump_B.GainM2Neg = CO_bump_P.GainM2Neg_Gain * CO_bump_B.Switch3[1];
    CO_bump_B.Switch5 = CO_bump_B.GainM2Neg;
  }

  /* End of Switch: '<S4>/Switch5' */

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[15];
    sfcnOutputs(rts, 0);
  }

  /* ok to acquire for <S34>/S-Function */
  CO_bump_DW.SFunction_IWORK_f.AcquireOK = 1;

  /* Abs: '<S4>/Abs' */
  CO_bump_B.Abs_h = fabs(CO_bump_B.MG1);

  /* Abs: '<S4>/Abs1' */
  CO_bump_B.Abs1 = fabs(CO_bump_B.MG2);

  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S28>/Constant'
   */
  CO_bump_B.Compare_e = (uint8_T)(CO_bump_B.Abs_h >
    CO_bump_P.CompareToConstant_const_l);

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   */
  CO_bump_B.Compare_k = (uint8_T)(CO_bump_B.Abs1 >
    CO_bump_P.CompareToConstant1_const_a);

  /* SignalConversion: '<S4>/ConcatBufferAtMatrix ConcatenationIn1' */
  CO_bump_B.MatrixConcatenation[0] = CO_bump_B.LogicalOperator5_l;

  /* SignalConversion: '<S4>/ConcatBufferAtMatrix ConcatenationIn2' */
  CO_bump_B.MatrixConcatenation[1] = CO_bump_B.LogicalOperator_l;

  /* Logic: '<S4>/Logical Operator1' */
  CO_bump_B.LogicalOperator1_h = ((CO_bump_B.Compare_e != 0) ||
    (CO_bump_B.Compare_k != 0));

  /* Logic: '<S4>/Logical Operator' */
  CO_bump_B.LogicalOperator_i = (CO_bump_B.LogicalOperator_l ||
    CO_bump_B.LogicalOperator5_l);

  /* ok to acquire for <S50>/S-Function */
  CO_bump_DW.SFunction_IWORK_eu.AcquireOK = 1;

  /* Clock: '<S67>/Clock' */
  CO_bump_B.Clock_j = CO_bump_M->Timing.t[0];

  /* Outputs for Triggered SubSystem: '<S67>/Sample and Hold' */
  CO_bump_SampleandHold(CO_bump_B.BehaviorCOBump_o5, CO_bump_B.Clock_j,
                        &CO_bump_B.SampleandHold, &CO_bump_DW.SampleandHold,
                        &CO_bump_PrevZCX.SampleandHold);

  /* End of Outputs for SubSystem: '<S67>/Sample and Hold' */

  /* Sum: '<S67>/Sum' */
  CO_bump_B.Sum_ap = CO_bump_B.Clock_j - CO_bump_B.SampleandHold.In;

  /* UniformRandomNumber: '<S7>/Uniform Random Number' */
  CO_bump_B.UniformRandomNumber = CO_bump_DW.UniformRandomNumber_NextOutput;

  /* RelationalOperator: '<S7>/Relational Operator' incorporates:
   *  Constant: '<S7>/JackpotChance'
   */
  CO_bump_B.RelationalOperator_i = (CO_bump_B.UniformRandomNumber >
    CO_bump_P.JackpotChance_Value);

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/RewardJackpot'
   *  Constant: '<S7>/RewardTime'
   */
  if (CO_bump_B.RelationalOperator_i) {
    CO_bump_B.Switch_c = CO_bump_P.RewardTime_Value;
  } else {
    CO_bump_B.Switch_c = CO_bump_P.RewardJackpot_Value;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Outputs for Triggered SubSystem: '<S7>/Sample and Hold' */
  CO_bump_SampleandHold(CO_bump_B.BehaviorCOBump_o5, CO_bump_B.Switch_c,
                        &CO_bump_B.SampleandHold_j, &CO_bump_DW.SampleandHold_j,
                        &CO_bump_PrevZCX.SampleandHold_j);

  /* End of Outputs for SubSystem: '<S7>/Sample and Hold' */

  /* RelationalOperator: '<S67>/Relational Operator' */
  CO_bump_B.RelationalOperator_f = (CO_bump_B.Sum_ap <
    CO_bump_B.SampleandHold_j.In);

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  CO_bump_B.DataTypeConversion = CO_bump_B.RelationalOperator_f;
  for (i = 0; i < 9; i++) {
    /* Sum: '<S10>/Add' */
    CO_bump_B.Add_o[i] = CO_bump_B.BehaviorCOBump_o4[i + 9] +
      CO_bump_B.BehaviorCOBump_o4[i + 27];

    /* Sum: '<S10>/Add1' */
    CO_bump_B.Add1_k[i] = CO_bump_B.BehaviorCOBump_o4[i + 18] +
      CO_bump_B.BehaviorCOBump_o4[i + 36];

    /* Gain: '<S10>/Gain' */
    CO_bump_B.Gain_o[i] = CO_bump_P.Gain_Gain_o0 * CO_bump_B.Add_o[i];

    /* Gain: '<S10>/Gain1' */
    CO_bump_B.Gain1_a[i] = CO_bump_P.Gain1_Gain_f * CO_bump_B.Add1_k[i];
  }

  /* Outputs for Iterator SubSystem: '<S14>/For Iterator Subsystem' incorporates:
   *  ForIterator: '<S75>/For Iterator'
   */
  for (i = 0; i < CO_bump_P.ForIterator_IterationLimit; i++) {
    CO_bump_B.ForIterator = i;

    /* Switch: '<S75>/Switch' incorporates:
     *  Constant: '<S75>/Constant2'
     */
    if (CO_bump_B.ForIterator >= CO_bump_P.Switch_Threshold) {
      CO_bump_B.Switch_m = CO_bump_B.BehaviorCOBump_o3;
    } else {
      CO_bump_B.Switch_m = CO_bump_P.Constant2_Value;
    }

    /* End of Switch: '<S75>/Switch' */

    /* Level2 S-Function Block: '<S75>/ToBits1' (Byte2Bits) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S75>/Port A' (dopci8255) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Sum: '<S75>/Add' incorporates:
     *  Constant: '<S75>/Constant'
     */
    CO_bump_B.Add_hr = CO_bump_B.PCIQUAD04 + CO_bump_P.Constant_Value_e;

    /* Sum: '<S75>/Add1' incorporates:
     *  Constant: '<S75>/Constant'
     */
    CO_bump_B.Add1_c = CO_bump_B.PCIQUAD041 + CO_bump_P.Constant_Value_e;

    /* Memory: '<S75>/Memory' */
    CO_bump_B.Memory_i = CO_bump_DW.Memory_PreviousInput_i;

    /* Level2 S-Function Block: '<S75>/SerialConverter' (serPos) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S75>/ToBits' (Byte2Bits) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S75>/Port B' (dopci8255) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S75>/xPC Target  Time ' (xpctimeinfo) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    do {
      /* Level2 S-Function Block: '<S79>/xPC Target  Time ' (xpctimeinfo) */
      {
        SimStruct *rts = CO_bump_M->childSfunctions[0];
        sfcnOutputs(rts, 1);
      }

      CO_bump_B.Subtract = CO_bump_B.xPCTargetTime_k - CO_bump_B.xPCTargetTime;
      CO_bump_B.ScaleTouSec = CO_bump_P.ScaleTouSec_Gain * CO_bump_B.Subtract;
      CO_bump_B.Compare_kk = (CO_bump_B.ScaleTouSec >
        CO_bump_P.CompareToConstant1_const);
      if (CO_bump_B.Compare_kk) {
        CO_bump_B.Switch_o = CO_bump_P.Constant_Value;
      } else {
        CO_bump_B.Switch_o = CO_bump_P.Constant1_Value;
      }

      /* Level2 S-Function Block: '<S79>/PCI-6025E ' (donipcie) */
      {
        SimStruct *rts = CO_bump_M->childSfunctions[1];
        sfcnOutputs(rts, 1);
      }

      CO_bump_B.Compare_pp = (CO_bump_B.ScaleTouSec <=
        CO_bump_P.CompareToConstant_const);
    } while (CO_bump_B.Compare_pp);

    /* Update for Memory: '<S75>/Memory' */
    CO_bump_DW.Memory_PreviousInput_i = CO_bump_B.SerialConverter;
  }

  /* End of Outputs for SubSystem: '<S14>/For Iterator Subsystem' */

  /* Constant: '<S78>/F Offset' */
  for (i = 0; i < 6; i++) {
    CO_bump_B.FOffset[i] = CO_bump_P.FOffset_Value[i];
  }

  /* End of Constant: '<S78>/F Offset' */
}

/* Model update function for TID0 */
static void CO_bump_update0(void)      /* Sample time: [0.0s, 0.0s] */
{
  real_T *lastU;
  real_T tmin;
  int32_T i;

  /* Update for UnitDelay: '<S78>/Unit Delay1' */
  for (i = 0; i < 6; i++) {
    CO_bump_DW.UnitDelay1_DSTATE[i] = CO_bump_B.Gain1[i];
  }

  /* End of Update for UnitDelay: '<S78>/Unit Delay1' */

  /* Update for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
  CO_bump_DW.DiscreteTimeIntegrator_DSTATE += CO_bump_B.Compare;
  if (CO_bump_DW.DiscreteTimeIntegrator_DSTATE >=
      CO_bump_P.DiscreteTimeIntegrator_UpperSat) {
    CO_bump_DW.DiscreteTimeIntegrator_DSTATE =
      CO_bump_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (CO_bump_DW.DiscreteTimeIntegrator_DSTATE <=
        CO_bump_P.DiscreteTimeIntegrator_LowerSat) {
      CO_bump_DW.DiscreteTimeIntegrator_DSTATE =
        CO_bump_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  CO_bump_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)(CO_bump_B.Compare > 0);

  /* End of Update for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */

  /* Update for Memory: '<S78>/Memory' */
  for (i = 0; i < 6; i++) {
    CO_bump_DW.Memory_PreviousInput[i] = CO_bump_B.Switch[i];
  }

  /* End of Update for Memory: '<S78>/Memory' */

  /* Update for UnitDelay: '<S72>/Unit Delay' */
  CO_bump_DW.UnitDelay_DSTATE = CO_bump_B.Gain1_m;

  /* Update for UnitDelay: '<S71>/Unit Delay' */
  CO_bump_DW.UnitDelay_DSTATE_e = CO_bump_B.Gain1_c;

  /* Update for UnitDelay: '<S24>/x' */
  CO_bump_DW.x_DSTATE = CO_bump_B.AddX_f;

  /* Update for UnitDelay: '<S25>/x' */
  CO_bump_DW.x_DSTATE_i = CO_bump_B.AddX_d;

  /* Update for UnitDelay: '<S26>/x' */
  CO_bump_DW.x_DSTATE_o = CO_bump_B.AddX_j;

  /* Update for UnitDelay: '<S27>/x' */
  CO_bump_DW.x_DSTATE_a = CO_bump_B.AddX_a;

  /* Update for Derivative: '<S69>/Derivative' */
  if (CO_bump_DW.TimeStampA == (rtInf)) {
    CO_bump_DW.TimeStampA = CO_bump_M->Timing.t[0];
    lastU = &CO_bump_DW.LastUAtTimeA;
  } else if (CO_bump_DW.TimeStampB == (rtInf)) {
    CO_bump_DW.TimeStampB = CO_bump_M->Timing.t[0];
    lastU = &CO_bump_DW.LastUAtTimeB;
  } else if (CO_bump_DW.TimeStampA < CO_bump_DW.TimeStampB) {
    CO_bump_DW.TimeStampA = CO_bump_M->Timing.t[0];
    lastU = &CO_bump_DW.LastUAtTimeA;
  } else {
    CO_bump_DW.TimeStampB = CO_bump_M->Timing.t[0];
    lastU = &CO_bump_DW.LastUAtTimeB;
  }

  *lastU = CO_bump_B.DigitalFilter2;

  /* End of Update for Derivative: '<S69>/Derivative' */

  /* Update for Derivative: '<S70>/Derivative' */
  if (CO_bump_DW.TimeStampA_o == (rtInf)) {
    CO_bump_DW.TimeStampA_o = CO_bump_M->Timing.t[0];
    lastU = &CO_bump_DW.LastUAtTimeA_h;
  } else if (CO_bump_DW.TimeStampB_a == (rtInf)) {
    CO_bump_DW.TimeStampB_a = CO_bump_M->Timing.t[0];
    lastU = &CO_bump_DW.LastUAtTimeB_m;
  } else if (CO_bump_DW.TimeStampA_o < CO_bump_DW.TimeStampB_a) {
    CO_bump_DW.TimeStampA_o = CO_bump_M->Timing.t[0];
    lastU = &CO_bump_DW.LastUAtTimeA_h;
  } else {
    CO_bump_DW.TimeStampB_a = CO_bump_M->Timing.t[0];
    lastU = &CO_bump_DW.LastUAtTimeB_m;
  }

  *lastU = CO_bump_B.DigitalFilter2_p;

  /* End of Update for Derivative: '<S70>/Derivative' */

  /* Update for UnitDelay: '<S18>/x' */
  CO_bump_DW.x_DSTATE_p = CO_bump_B.AddX;

  /* Update for UnitDelay: '<S19>/x' */
  CO_bump_DW.x_DSTATE_ix = CO_bump_B.AddX_g;

  /* Update for UnitDelay: '<S20>/x' */
  CO_bump_DW.x_DSTATE_f = CO_bump_B.AddX_n;

  /* Update for UnitDelay: '<S21>/x' */
  CO_bump_DW.x_DSTATE_l = CO_bump_B.AddX_c;

  /* Level2 S-Function Block: '<Root>/Behavior CO Bump' (mastercon_CO_bump) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[13];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S18>/y' */
  CO_bump_DW.y_DSTATE = CO_bump_B.AddX1;

  /* Update for UnitDelay: '<S18>/z' */
  CO_bump_DW.z_DSTATE = CO_bump_B.AddX2;

  /* Update for UnitDelay: '<S19>/y' */
  CO_bump_DW.y_DSTATE_n = CO_bump_B.AddX1_j;

  /* Update for UnitDelay: '<S19>/z' */
  CO_bump_DW.z_DSTATE_f = CO_bump_B.AddX2_l;

  /* Update for UnitDelay: '<S20>/y' */
  CO_bump_DW.y_DSTATE_k = CO_bump_B.AddX1_d;

  /* Update for UnitDelay: '<S20>/z' */
  CO_bump_DW.z_DSTATE_l = CO_bump_B.AddX2_h;

  /* Update for UnitDelay: '<S21>/y' */
  CO_bump_DW.y_DSTATE_a = CO_bump_B.AddX1_o;

  /* Update for UnitDelay: '<S21>/z' */
  CO_bump_DW.z_DSTATE_a = CO_bump_B.AddX2_a;

  /* Update for UnitDelay: '<S24>/y' */
  CO_bump_DW.y_DSTATE_g = CO_bump_B.AddX1_f;

  /* Update for UnitDelay: '<S24>/z' */
  CO_bump_DW.z_DSTATE_k = CO_bump_B.AddX2_g;

  /* Update for UnitDelay: '<S25>/y' */
  CO_bump_DW.y_DSTATE_b = CO_bump_B.AddX1_g;

  /* Update for UnitDelay: '<S25>/z' */
  CO_bump_DW.z_DSTATE_m = CO_bump_B.AddX2_o;

  /* Update for UnitDelay: '<S26>/y' */
  CO_bump_DW.y_DSTATE_kn = CO_bump_B.AddX1_k;

  /* Update for UnitDelay: '<S26>/z' */
  CO_bump_DW.z_DSTATE_d = CO_bump_B.AddX2_l1;

  /* Update for UnitDelay: '<S27>/y' */
  CO_bump_DW.y_DSTATE_j = CO_bump_B.AddX1_m;

  /* Update for UnitDelay: '<S27>/z' */
  CO_bump_DW.z_DSTATE_d0 = CO_bump_B.AddX2_ok;

  /* Update for Memory: '<S33>/Memory' */
  CO_bump_DW.Memory_PreviousInput_h = CO_bump_B.LogicalOperator_l;

  /* Update for Memory: '<S4>/Memory' */
  CO_bump_DW.Memory_PreviousInput_f = CO_bump_B.LogicalOperator1_h;

  /* Update for DiscreteFir: '<S6>/Discrete FIR Filter' */
  /* Update circular buffer index */
  CO_bump_DW.DiscreteFIRFilter_circBuf--;
  if (CO_bump_DW.DiscreteFIRFilter_circBuf < 0) {
    CO_bump_DW.DiscreteFIRFilter_circBuf = 28;
  }

  /* Update circular buffer */
  CO_bump_DW.DiscreteFIRFilter_states[CO_bump_DW.DiscreteFIRFilter_circBuf] =
    CO_bump_B.Switch_j[0];
  CO_bump_DW.DiscreteFIRFilter_states[CO_bump_DW.DiscreteFIRFilter_circBuf + 29]
    = CO_bump_B.Switch_j[1];

  /* End of Update for DiscreteFir: '<S6>/Discrete FIR Filter' */

  /* Update for Memory: '<S45>/Memory' */
  CO_bump_DW.Memory_PreviousInput_j = CO_bump_B.LogicalOperator_m1;

  /* Update for Memory: '<S49>/Memory' */
  CO_bump_DW.Memory_PreviousInput_b = CO_bump_B.LogicalOperator_k;

  /* Update for UnitDelay: '<S63>/Delay Input1' */
  CO_bump_DW.DelayInput1_DSTATE = CO_bump_B.Compare_d2;

  /* Update for Memory: '<S47>/Memory' */
  CO_bump_DW.Memory_PreviousInput_is = CO_bump_B.LogicalOperator_b;

  /* Update for UnitDelay: '<S48>/Delay Input1' */
  CO_bump_DW.DelayInput1_DSTATE_d = CO_bump_B.Compare_m;

  /* Update for UnitDelay: '<S41>/Delay Input1' */
  CO_bump_DW.DelayInput1_DSTATE_m = CO_bump_B.Compare_l;

  /* Update for Memory: '<S46>/Memory' */
  CO_bump_DW.Memory_PreviousInput_k = CO_bump_B.LogicalOperator_bx;

  /* Update for UnitDelay: '<S40>/Delay Input1' */
  CO_bump_DW.DelayInput1_DSTATE_p = CO_bump_B.Compare_p;

  /* Update for Memory: '<S44>/Memory' */
  CO_bump_DW.Memory_PreviousInput_d = CO_bump_B.Logic[0];

  /* Update for UniformRandomNumber: '<S7>/Uniform Random Number' */
  tmin = CO_bump_P.UniformRandomNumber_Minimum;
  CO_bump_DW.UniformRandomNumber_NextOutput =
    (CO_bump_P.UniformRandomNumber_Maximum - tmin) * rt_urand_Upu32_Yd_f_pw_snf(
    &CO_bump_DW.RandSeed) + tmin;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++CO_bump_M->Timing.clockTick0)) {
    ++CO_bump_M->Timing.clockTickH0;
  }

  CO_bump_M->Timing.t[0] = CO_bump_M->Timing.clockTick0 *
    CO_bump_M->Timing.stepSize0 + CO_bump_M->Timing.clockTickH0 *
    CO_bump_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++CO_bump_M->Timing.clockTick1)) {
    ++CO_bump_M->Timing.clockTickH1;
  }

  CO_bump_M->Timing.t[1] = CO_bump_M->Timing.clockTick1 *
    CO_bump_M->Timing.stepSize1 + CO_bump_M->Timing.clockTickH1 *
    CO_bump_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output function for TID2 */
static void CO_bump_output2(void)      /* Sample time: [0.02s, 0.0s] */
{
  /* Level2 S-Function Block: '<S8>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[14];
    sfcnOutputs(rts, 2);
  }
}

/* Model update function for TID2 */
static void CO_bump_update2(void)      /* Sample time: [0.02s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++CO_bump_M->Timing.clockTick2)) {
    ++CO_bump_M->Timing.clockTickH2;
  }

  CO_bump_M->Timing.t[2] = CO_bump_M->Timing.clockTick2 *
    CO_bump_M->Timing.stepSize2 + CO_bump_M->Timing.clockTickH2 *
    CO_bump_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
static void CO_bump_output(int_T tid)
{
  switch (tid) {
   case 0 :
    CO_bump_output0();
    break;

   case 2 :
    CO_bump_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
static void CO_bump_update(int_T tid)
{
  switch (tid) {
   case 0 :
    CO_bump_update0();
    break;

   case 2 :
    CO_bump_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
static void CO_bump_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/Intel Chipset Disable SMI' (ich5) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S5>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S77>/yoffset' */
  CO_bump_B.yoffset = CO_bump_P.yoffset_Value;

  /* Level2 S-Function Block: '<S14>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S14>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[11];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S77>/xoffset' */
  CO_bump_B.xoffset = CO_bump_P.xoffset_Value;

  /* Level2 S-Function Block: '<S14>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<Root>/Behavior CO Bump' (mastercon_CO_bump) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[13];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S8>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[14];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S9>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior CO Bump/p2/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior CO Bump/p2/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior CO Bump/p2/s3"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior CO Bump/p2/s4"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior CO Bump/p2/s5"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior CO Bump/p2/s1"),
          "%6.0f state");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior CO Bump/p2/s2"),
          "%6.0f rewards");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior CO Bump/p2/s3"),
          "%6.0f aborts");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior CO Bump/p2/s4"),
          "%6.0f fails");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior CO Bump/p2/s5"),
          "%6.0f incompl");
        rl32eSetScope(3, 4, 10);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 10);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Behavior CO Bump/p2/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, -10.0);
        rl32eSetTargetScope(3, 10, 10.0);
        xpceScopeAcqOK(3, &CO_bump_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* S-Function Block: <S12>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior CO Bump/p7/s1"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior CO Bump/p7/s2"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior CO Bump/p7/s3"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior CO Bump/p7/s4"));
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior CO Bump/p7/s1"),
          "%6.0f major");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior CO Bump/p7/s2"),
          "%6.0f minor");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior CO Bump/p7/s3"),
          "%6.0f revision");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior CO Bump/p7/s4"),
          "%6.0f build");
        rl32eSetScope(7, 4, 10);
        rl32eSetScope(7, 5, 0);
        rl32eSetScope(7, 6, 10);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("Behavior CO Bump/p7/s1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 9, 0);
        rl32eSetTargetScope(7, 1, 0.0);
        rl32eSetTargetScope(7, 11, -10.0);
        rl32eSetTargetScope(7, 10, 10.0);
        xpceScopeAcqOK(7, &CO_bump_DW.SFunction_IWORK_e.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* S-Function Block: <S15>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Matrix Concatenation1/s1"));
        rl32eAddSignal(1, rl32eGetSignalNo("Matrix Concatenation1/s2"));
        rl32eAddSignal(1, rl32eGetSignalNo("Matrix Concatenation1/s3"));
        rl32eAddSignal(1, rl32eGetSignalNo("Matrix Concatenation1/s4"));
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Matrix Concatenation1/s1"),
          "%15.2f X");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Matrix Concatenation1/s2"),
          "%15.2f Y");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Matrix Concatenation1/s3"),
          "%15.2f dX");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Matrix Concatenation1/s4"),
          "%15.2f dY");
        rl32eSetScope(1, 4, 10);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 10);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Matrix Concatenation1/s1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 0.0);
        rl32eSetTargetScope(1, 11, -10.0);
        rl32eSetTargetScope(1, 10, 10.0);
        xpceScopeAcqOK(1, &CO_bump_DW.SFunction_IWORK_c.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for Enabled SubSystem: '<S33>/Enabled Subsystem' */
  CO_bump_EnabledSubsystem_Start(&CO_bump_DW.EnabledSubsystem);

  /* End of Start for SubSystem: '<S33>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S49>/Enabled Subsystem' */
  CO_bump_EnabledSubsystem_Start(&CO_bump_DW.EnabledSubsystem_e);

  /* End of Start for SubSystem: '<S49>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S45>/Enabled Subsystem' */
  CO_bump_EnabledSubsystem_Start(&CO_bump_DW.EnabledSubsystem_m);

  /* End of Start for SubSystem: '<S45>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S47>/Enabled Subsystem' */
  CO_bump_EnabledSubsystem_Start(&CO_bump_DW.EnabledSubsystem_l);

  /* End of Start for SubSystem: '<S47>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S46>/Enabled Subsystem' */
  CO_bump_EnabledSubsystem_Start(&CO_bump_DW.EnabledSubsystem_d);

  /* End of Start for SubSystem: '<S46>/Enabled Subsystem' */

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[15];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* S-Function Block: <S34>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("Motor Control1/Switch2/s1"));
        rl32eAddSignal(4, rl32eGetSignalNo("Motor Control1/Switch2/s2"));
        rl32eAddSignal(4, rl32eGetSignalNo("Motor Control1/MG1"));
        rl32eAddSignal(4, rl32eGetSignalNo("Motor Control1/MG2"));
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Motor Control1/Switch2/s1"),
          "%15.2f Fx");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Motor Control1/Switch2/s2"),
          "%15.2f Fy");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Motor Control1/MG1"),
          "%15.2f T1");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Motor Control1/MG2"),
          "%15.2f T2");
        rl32eSetScope(4, 4, 10);
        rl32eSetScope(4, 5, 0);
        rl32eSetScope(4, 6, 10);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("Motor Control1/Switch2/s1"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 9, 0);
        rl32eSetTargetScope(4, 1, 0.0);
        rl32eSetTargetScope(4, 11, -10.0);
        rl32eSetTargetScope(4, 10, 10.0);
        xpceScopeAcqOK(4, &CO_bump_DW.SFunction_IWORK_f.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* S-Function Block: <S50>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("BoundingBox/Logical Operator1"));
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Recentering Subsystem1/Logical Operator"));
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Recentering Subsystem1/S-R Flip-Flop/Logic/s1"));
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Recentering Subsystem1/Schmidt1/Logical Operator"));
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Recentering Subsystem1/No Movement/Logical Operator1"));
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Recentering Subsystem1/Logical Operator5"));
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "BoundingBox/Logical Operator1"),"%2.0f OutsideBox");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Recentering Subsystem1/Logical Operator"),"%2.0f Activate");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Recentering Subsystem1/S-R Flip-Flop/Logic/s1"),"%2.0f SR");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Recentering Subsystem1/Schmidt1/Logical Operator"),"%2.0f OD On");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Recentering Subsystem1/No Movement/Logical Operator1"),
          "%2.0f no movement");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Recentering Subsystem1/Logical Operator5"),"%2.0f claimed");
        rl32eSetScope(2, 4, 10);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 10);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("BoundingBox/Logical Operator1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 0.0);
        rl32eSetTargetScope(2, 11, -10.0);
        rl32eSetTargetScope(2, 10, 10.0);
        xpceScopeAcqOK(2, &CO_bump_DW.SFunction_IWORK_eu.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for Triggered SubSystem: '<S67>/Sample and Hold' */
  CO_bump_SampleandHold_Start(&CO_bump_B.SampleandHold,
    (P_SampleandHold_CO_bump_T *)&CO_bump_P.SampleandHold);

  /* End of Start for SubSystem: '<S67>/Sample and Hold' */

  /* Start for Triggered SubSystem: '<S7>/Sample and Hold' */
  CO_bump_SampleandHold_Start(&CO_bump_B.SampleandHold_j,
    (P_SampleandHold_CO_bump_T *)&CO_bump_P.SampleandHold_j);

  /* End of Start for SubSystem: '<S7>/Sample and Hold' */

  /* Start for Iterator SubSystem: '<S14>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S75>/Port A' (dopci8255) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S75>/Port B' (dopci8255) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Iterator SubSystem: '<S75>/Whiltor Subsystem' */

  /* Level2 S-Function Block: '<S79>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S75>/Whiltor Subsystem' */

  /* End of Start for SubSystem: '<S14>/For Iterator Subsystem' */

  /* InitializeConditions for Iterator SubSystem: '<S14>/For Iterator Subsystem' */
  /* InitializeConditions for Memory: '<S75>/Memory' */
  CO_bump_DW.Memory_PreviousInput_i = CO_bump_P.Memory_X0;

  /* End of InitializeConditions for SubSystem: '<S14>/For Iterator Subsystem' */
  CO_bump_PrevZCX.SampleandHold.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;
  CO_bump_PrevZCX.SampleandHold_j.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;

  {
    uint32_T tseed;
    int32_T t;
    real_T tmin;
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S78>/Discrete-Time Integrator' */
    CO_bump_DW.DiscreteTimeIntegrator_DSTATE =
      CO_bump_P.DiscreteTimeIntegrator_IC;
    CO_bump_DW.DiscreteTimeIntegrator_PrevRese = 2;
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for UnitDelay: '<S78>/Unit Delay1' */
      CO_bump_DW.UnitDelay1_DSTATE[i] = CO_bump_P.UnitDelay1_InitialCondition;

      /* InitializeConditions for Memory: '<S78>/Memory' */
      CO_bump_DW.Memory_PreviousInput[i] = CO_bump_P.Memory_X0_j;
    }

    /* InitializeConditions for UnitDelay: '<S72>/Unit Delay' */
    CO_bump_DW.UnitDelay_DSTATE = CO_bump_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S71>/Unit Delay' */
    CO_bump_DW.UnitDelay_DSTATE_e = CO_bump_P.UnitDelay_InitialCondition_o;

    /* InitializeConditions for UnitDelay: '<S24>/x' */
    CO_bump_DW.x_DSTATE = CO_bump_P.x_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S25>/x' */
    CO_bump_DW.x_DSTATE_i = CO_bump_P.x_InitialCondition_d;

    /* InitializeConditions for UnitDelay: '<S26>/x' */
    CO_bump_DW.x_DSTATE_o = CO_bump_P.x_InitialCondition_p;

    /* InitializeConditions for UnitDelay: '<S27>/x' */
    CO_bump_DW.x_DSTATE_a = CO_bump_P.x_InitialCondition_c;

    /* InitializeConditions for S-Function (sdspfilter2): '<S69>/Digital Filter2' */
    CO_bump_DW.DigitalFilter2_CIRCBUFFIDX = 0;
    for (i = 0; i < 10; i++) {
      /* InitializeConditions for S-Function (sdspfilter2): '<S69>/Digital Filter2' */
      CO_bump_DW.DigitalFilter2_FILT_STATES[i] = 0.0;

      /* InitializeConditions for S-Function (sdspfilter2): '<S69>/Digital Filter' */
      CO_bump_DW.DigitalFilter_FILT_STATES[i] = 0.0;

      /* InitializeConditions for S-Function (sdspfilter2): '<S70>/Digital Filter2' */
      CO_bump_DW.DigitalFilter2_FILT_STATES_k[i] = 0.0;

      /* InitializeConditions for S-Function (sdspfilter2): '<S70>/Digital Filter' */
      CO_bump_DW.DigitalFilter_FILT_STATES_o[i] = 0.0;
    }

    /* InitializeConditions for S-Function (sdspfilter2): '<S69>/Digital Filter2' */
    CO_bump_DW.DigitalFilter2_FILT_STATES[10] = 0.0;

    /* InitializeConditions for Derivative: '<S69>/Derivative' */
    CO_bump_DW.TimeStampA = (rtInf);
    CO_bump_DW.TimeStampB = (rtInf);

    /* InitializeConditions for S-Function (sdspfilter2): '<S69>/Digital Filter' */
    CO_bump_DW.DigitalFilter_CIRCBUFFIDX = 0;
    CO_bump_DW.DigitalFilter_FILT_STATES[10] = 0.0;

    /* InitializeConditions for S-Function (sdspfilter2): '<S70>/Digital Filter2' */
    CO_bump_DW.DigitalFilter2_CIRCBUFFIDX_c = 0;
    CO_bump_DW.DigitalFilter2_FILT_STATES_k[10] = 0.0;

    /* InitializeConditions for Derivative: '<S70>/Derivative' */
    CO_bump_DW.TimeStampA_o = (rtInf);
    CO_bump_DW.TimeStampB_a = (rtInf);

    /* InitializeConditions for S-Function (sdspfilter2): '<S70>/Digital Filter' */
    CO_bump_DW.DigitalFilter_CIRCBUFFIDX_o = 0;
    CO_bump_DW.DigitalFilter_FILT_STATES_o[10] = 0.0;

    /* InitializeConditions for UnitDelay: '<S18>/x' */
    CO_bump_DW.x_DSTATE_p = CO_bump_P.x_InitialCondition_a;

    /* InitializeConditions for UnitDelay: '<S19>/x' */
    CO_bump_DW.x_DSTATE_ix = CO_bump_P.x_InitialCondition_m;

    /* InitializeConditions for UnitDelay: '<S20>/x' */
    CO_bump_DW.x_DSTATE_f = CO_bump_P.x_InitialCondition_j;

    /* InitializeConditions for UnitDelay: '<S21>/x' */
    CO_bump_DW.x_DSTATE_l = CO_bump_P.x_InitialCondition_g;

    /* InitializeConditions for UnitDelay: '<S18>/y' */
    CO_bump_DW.y_DSTATE = CO_bump_P.Lorentz_y0;

    /* InitializeConditions for UnitDelay: '<S18>/z' */
    CO_bump_DW.z_DSTATE = CO_bump_P.z_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S19>/y' */
    CO_bump_DW.y_DSTATE_n = CO_bump_P.Lorentz1_y0;

    /* InitializeConditions for UnitDelay: '<S19>/z' */
    CO_bump_DW.z_DSTATE_f = CO_bump_P.z_InitialCondition_i;

    /* InitializeConditions for UnitDelay: '<S20>/y' */
    CO_bump_DW.y_DSTATE_k = CO_bump_P.Lorentz2_y0;

    /* InitializeConditions for UnitDelay: '<S20>/z' */
    CO_bump_DW.z_DSTATE_l = CO_bump_P.z_InitialCondition_f;

    /* InitializeConditions for UnitDelay: '<S21>/y' */
    CO_bump_DW.y_DSTATE_a = CO_bump_P.Lorentz3_y0;

    /* InitializeConditions for UnitDelay: '<S21>/z' */
    CO_bump_DW.z_DSTATE_a = CO_bump_P.z_InitialCondition_n;

    /* InitializeConditions for UnitDelay: '<S24>/y' */
    CO_bump_DW.y_DSTATE_g = CO_bump_P.Lorentz_y0_e;

    /* InitializeConditions for UnitDelay: '<S24>/z' */
    CO_bump_DW.z_DSTATE_k = CO_bump_P.z_InitialCondition_p;

    /* InitializeConditions for UnitDelay: '<S25>/y' */
    CO_bump_DW.y_DSTATE_b = CO_bump_P.Lorentz1_y0_o;

    /* InitializeConditions for UnitDelay: '<S25>/z' */
    CO_bump_DW.z_DSTATE_m = CO_bump_P.z_InitialCondition_o;

    /* InitializeConditions for UnitDelay: '<S26>/y' */
    CO_bump_DW.y_DSTATE_kn = CO_bump_P.Lorentz2_y0_h;

    /* InitializeConditions for UnitDelay: '<S26>/z' */
    CO_bump_DW.z_DSTATE_d = CO_bump_P.z_InitialCondition_d;

    /* InitializeConditions for UnitDelay: '<S27>/y' */
    CO_bump_DW.y_DSTATE_j = CO_bump_P.Lorentz3_y0_m;

    /* InitializeConditions for UnitDelay: '<S27>/z' */
    CO_bump_DW.z_DSTATE_d0 = CO_bump_P.z_InitialCondition_fg;

    /* InitializeConditions for Memory: '<S33>/Memory' */
    CO_bump_DW.Memory_PreviousInput_h = CO_bump_P.Memory_X0_b;

    /* InitializeConditions for Memory: '<S4>/Memory' */
    CO_bump_DW.Memory_PreviousInput_f = CO_bump_P.Memory_X0_p;

    /* InitializeConditions for DiscreteFir: '<S6>/Discrete FIR Filter' */
    CO_bump_DW.DiscreteFIRFilter_circBuf = 0;
    for (i = 0; i < 58; i++) {
      CO_bump_DW.DiscreteFIRFilter_states[i] =
        CO_bump_P.DiscreteFIRFilter_InitialStates;
    }

    /* End of InitializeConditions for DiscreteFir: '<S6>/Discrete FIR Filter' */

    /* InitializeConditions for Memory: '<S45>/Memory' */
    CO_bump_DW.Memory_PreviousInput_j = CO_bump_P.Memory_X0_g;

    /* InitializeConditions for Memory: '<S49>/Memory' */
    CO_bump_DW.Memory_PreviousInput_b = CO_bump_P.Memory_X0_e;

    /* InitializeConditions for UnitDelay: '<S63>/Delay Input1' */
    CO_bump_DW.DelayInput1_DSTATE = CO_bump_P.DetectFallNonpositive_vinit;

    /* InitializeConditions for Memory: '<S47>/Memory' */
    CO_bump_DW.Memory_PreviousInput_is = CO_bump_P.Memory_X0_b5;

    /* InitializeConditions for UnitDelay: '<S48>/Delay Input1' */
    CO_bump_DW.DelayInput1_DSTATE_d = CO_bump_P.StartMoving_vinit;

    /* InitializeConditions for UnitDelay: '<S41>/Delay Input1' */
    CO_bump_DW.DelayInput1_DSTATE_m = CO_bump_P.FallingEdge1_vinit;

    /* InitializeConditions for Memory: '<S46>/Memory' */
    CO_bump_DW.Memory_PreviousInput_k = CO_bump_P.Memory_X0_a;

    /* InitializeConditions for UnitDelay: '<S40>/Delay Input1' */
    CO_bump_DW.DelayInput1_DSTATE_p = CO_bump_P.FallingEdge_vinit;

    /* InitializeConditions for Memory: '<S44>/Memory' */
    CO_bump_DW.Memory_PreviousInput_d = CO_bump_P.SRFlipFlop_initial_condition;

    /* InitializeConditions for UniformRandomNumber: '<S7>/Uniform Random Number' */
    tmin = floor(CO_bump_P.UniformRandomNumber_Seed);
    if (rtIsNaN(tmin) || rtIsInf(tmin)) {
      tmin = 0.0;
    } else {
      tmin = fmod(tmin, 4.294967296E+9);
    }

    tseed = tmin < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmin : (uint32_T)tmin;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    CO_bump_DW.RandSeed = tseed;
    tmin = CO_bump_P.UniformRandomNumber_Minimum;
    CO_bump_DW.UniformRandomNumber_NextOutput =
      (CO_bump_P.UniformRandomNumber_Maximum - tmin) *
      rt_urand_Upu32_Yd_f_pw_snf(&CO_bump_DW.RandSeed) + tmin;

    /* End of InitializeConditions for UniformRandomNumber: '<S7>/Uniform Random Number' */
  }
}

/* Model terminate function */
static void CO_bump_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/Intel Chipset Disable SMI' (ich5) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Behavior CO Bump' (mastercon_CO_bump) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[14];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[15];
    sfcnTerminate(rts);
  }

  /* Terminate for Iterator SubSystem: '<S14>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S75>/ToBits1' (Byte2Bits) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S75>/Port A' (dopci8255) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S75>/SerialConverter' (serPos) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S75>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S75>/Port B' (dopci8255) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S75>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for Iterator SubSystem: '<S75>/Whiltor Subsystem' */

  /* Level2 S-Function Block: '<S79>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S79>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = CO_bump_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S75>/Whiltor Subsystem' */

  /* End of Terminate for SubSystem: '<S14>/For Iterator Subsystem' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  CO_bump_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  CO_bump_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  CO_bump_initialize();
}

void MdlTerminate(void)
{
  CO_bump_terminate();
}

/* Registration function */
RT_MODEL_CO_bump_T *CO_bump(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)CO_bump_M, 0,
                sizeof(RT_MODEL_CO_bump_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&CO_bump_M->solverInfo, &CO_bump_M->Timing.simTimeStep);
    rtsiSetTPtr(&CO_bump_M->solverInfo, &rtmGetTPtr(CO_bump_M));
    rtsiSetStepSizePtr(&CO_bump_M->solverInfo, &CO_bump_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&CO_bump_M->solverInfo, (&rtmGetErrorStatus(CO_bump_M)));
    rtsiSetRTModelPtr(&CO_bump_M->solverInfo, CO_bump_M);
  }

  rtsiSetSimTimeStep(&CO_bump_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&CO_bump_M->solverInfo,"FixedStepDiscrete");
  CO_bump_M->solverInfoPtr = (&CO_bump_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = CO_bump_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    CO_bump_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    CO_bump_M->Timing.sampleTimes = (&CO_bump_M->Timing.sampleTimesArray[0]);
    CO_bump_M->Timing.offsetTimes = (&CO_bump_M->Timing.offsetTimesArray[0]);

    /* task periods */
    CO_bump_M->Timing.sampleTimes[0] = (0.0);
    CO_bump_M->Timing.sampleTimes[1] = (0.001);
    CO_bump_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    CO_bump_M->Timing.offsetTimes[0] = (0.0);
    CO_bump_M->Timing.offsetTimes[1] = (0.0);
    CO_bump_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(CO_bump_M, &CO_bump_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = CO_bump_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = CO_bump_M->Timing.perTaskSampleHitsArray;
    CO_bump_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    CO_bump_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(CO_bump_M, -1);
  CO_bump_M->Timing.stepSize0 = 0.001;
  CO_bump_M->Timing.stepSize1 = 0.001;
  CO_bump_M->Timing.stepSize2 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    CO_bump_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    /*
     * Set pointers to the data and signal info each state
     */
    {
      static int_T rt_LoggedStateWidths[] = {
        6,
        1,
        1,
        1,
        1,
        1,
        1,
        11,
        11,
        11,
        11,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        58,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedStateNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedStateDimensions[] = {
        6,
        1,
        1,
        1,
        1,
        1,
        1,
        11,
        11,
        11,
        11,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        58,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedStateIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static BuiltInDTypeId rt_LoggedStateDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_INT32,
        SS_INT32,
        SS_UINT8,
        SS_UINT8,
        SS_UINT8,
        SS_UINT8
      };

      static int_T rt_LoggedStateComplexSignals[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedStateLabels[] = {
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "FILT_STATES",
        "FILT_STATES",
        "FILT_STATES",
        "FILT_STATES",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "states",
        "DSTATE",
        "circBuf",
        "DSTATE",
        "DSTATE",
        "DSTATE",
        "DSTATE"
      };

      static const char_T *rt_LoggedStateBlockNames[] = {
        "CO_bump/XY Position Subsystem1/OffsetCalculation/Unit Delay1",
        "CO_bump/XY Position Subsystem1/Avg1/Unit Delay",
        "CO_bump/XY Position Subsystem1/Avg/Unit Delay",
        "CO_bump/Force Generator/LorentzForce/Lorentz/x",
        "CO_bump/Force Generator/LorentzForce/Lorentz1/x",
        "CO_bump/Force Generator/LorentzForce/Lorentz2/x",
        "CO_bump/Force Generator/LorentzForce/Lorentz3/x",
        "CO_bump/Velocity Calculation/Pos2VelX/Digital Filter2",
        "CO_bump/Velocity Calculation/Pos2VelX/Digital Filter",
        "CO_bump/Velocity Calculation/Pos2VelY/Digital Filter2",
        "CO_bump/Velocity Calculation/Pos2VelY/Digital Filter",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz/x",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz1/x",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz2/x",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz3/x",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz/y",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz/z",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz1/y",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz1/z",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz2/y",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz2/z",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz3/y",
        "CO_bump/Catch Force Generator/LorentzForce/Lorentz3/z",
        "CO_bump/Force Generator/LorentzForce/Lorentz/y",
        "CO_bump/Force Generator/LorentzForce/Lorentz/z",
        "CO_bump/Force Generator/LorentzForce/Lorentz1/y",
        "CO_bump/Force Generator/LorentzForce/Lorentz1/z",
        "CO_bump/Force Generator/LorentzForce/Lorentz2/y",
        "CO_bump/Force Generator/LorentzForce/Lorentz2/z",
        "CO_bump/Force Generator/LorentzForce/Lorentz3/y",
        "CO_bump/Force Generator/LorentzForce/Lorentz3/z",
        "CO_bump/Recentering Subsystem1/Discrete FIR Filter",
        "CO_bump/XY Position Subsystem1/OffsetCalculation/Discrete-Time Integrator",
        "CO_bump/Recentering Subsystem1/Discrete FIR Filter",
        "CO_bump/Recentering Subsystem1/Timer/Detect Fall\nNonpositive/Delay Input1",
        "CO_bump/Recentering Subsystem1/Start Moving/Delay Input1",
        "CO_bump/Recentering Subsystem1/Falling Edge1/Delay Input1",
        "CO_bump/Recentering Subsystem1/Falling Edge/Delay Input1"
      };

      static const char_T *rt_LoggedStateNames[] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
      };

      static boolean_T rt_LoggedStateCrossMdlRef[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_INT32, SS_INT32, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_INT32, SS_INT32, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
        38,
        rt_LoggedStateWidths,
        rt_LoggedStateNumDimensions,
        rt_LoggedStateDimensions,
        rt_LoggedStateIsVarDims,
        (NULL),
        (NULL),
        rt_LoggedStateDataTypeIds,
        rt_LoggedStateComplexSignals,
        (NULL),

        { rt_LoggedStateLabels },
        (NULL),
        (NULL),
        (NULL),

        { rt_LoggedStateBlockNames },

        { rt_LoggedStateNames },
        rt_LoggedStateCrossMdlRef,
        rt_RTWLogDataTypeConvert
      };

      static void * rt_LoggedStateSignalPtrs[38];
      rtliSetLogXSignalPtrs(CO_bump_M->rtwLogInfo, (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
      rtliSetLogXSignalInfo(CO_bump_M->rtwLogInfo, &rt_LoggedStateSignalInfo);
      rt_LoggedStateSignalPtrs[0] = (void*)CO_bump_DW.UnitDelay1_DSTATE;
      rt_LoggedStateSignalPtrs[1] = (void*)&CO_bump_DW.UnitDelay_DSTATE;
      rt_LoggedStateSignalPtrs[2] = (void*)&CO_bump_DW.UnitDelay_DSTATE_e;
      rt_LoggedStateSignalPtrs[3] = (void*)&CO_bump_DW.x_DSTATE;
      rt_LoggedStateSignalPtrs[4] = (void*)&CO_bump_DW.x_DSTATE_i;
      rt_LoggedStateSignalPtrs[5] = (void*)&CO_bump_DW.x_DSTATE_o;
      rt_LoggedStateSignalPtrs[6] = (void*)&CO_bump_DW.x_DSTATE_a;
      rt_LoggedStateSignalPtrs[7] = (void*)CO_bump_DW.DigitalFilter2_FILT_STATES;
      rt_LoggedStateSignalPtrs[8] = (void*)CO_bump_DW.DigitalFilter_FILT_STATES;
      rt_LoggedStateSignalPtrs[9] = (void*)
        CO_bump_DW.DigitalFilter2_FILT_STATES_k;
      rt_LoggedStateSignalPtrs[10] = (void*)
        CO_bump_DW.DigitalFilter_FILT_STATES_o;
      rt_LoggedStateSignalPtrs[11] = (void*)&CO_bump_DW.x_DSTATE_p;
      rt_LoggedStateSignalPtrs[12] = (void*)&CO_bump_DW.x_DSTATE_ix;
      rt_LoggedStateSignalPtrs[13] = (void*)&CO_bump_DW.x_DSTATE_f;
      rt_LoggedStateSignalPtrs[14] = (void*)&CO_bump_DW.x_DSTATE_l;
      rt_LoggedStateSignalPtrs[15] = (void*)&CO_bump_DW.y_DSTATE;
      rt_LoggedStateSignalPtrs[16] = (void*)&CO_bump_DW.z_DSTATE;
      rt_LoggedStateSignalPtrs[17] = (void*)&CO_bump_DW.y_DSTATE_n;
      rt_LoggedStateSignalPtrs[18] = (void*)&CO_bump_DW.z_DSTATE_f;
      rt_LoggedStateSignalPtrs[19] = (void*)&CO_bump_DW.y_DSTATE_k;
      rt_LoggedStateSignalPtrs[20] = (void*)&CO_bump_DW.z_DSTATE_l;
      rt_LoggedStateSignalPtrs[21] = (void*)&CO_bump_DW.y_DSTATE_a;
      rt_LoggedStateSignalPtrs[22] = (void*)&CO_bump_DW.z_DSTATE_a;
      rt_LoggedStateSignalPtrs[23] = (void*)&CO_bump_DW.y_DSTATE_g;
      rt_LoggedStateSignalPtrs[24] = (void*)&CO_bump_DW.z_DSTATE_k;
      rt_LoggedStateSignalPtrs[25] = (void*)&CO_bump_DW.y_DSTATE_b;
      rt_LoggedStateSignalPtrs[26] = (void*)&CO_bump_DW.z_DSTATE_m;
      rt_LoggedStateSignalPtrs[27] = (void*)&CO_bump_DW.y_DSTATE_kn;
      rt_LoggedStateSignalPtrs[28] = (void*)&CO_bump_DW.z_DSTATE_d;
      rt_LoggedStateSignalPtrs[29] = (void*)&CO_bump_DW.y_DSTATE_j;
      rt_LoggedStateSignalPtrs[30] = (void*)&CO_bump_DW.z_DSTATE_d0;
      rt_LoggedStateSignalPtrs[31] = (void*)CO_bump_DW.DiscreteFIRFilter_states;
      rt_LoggedStateSignalPtrs[32] = (void*)
        &CO_bump_DW.DiscreteTimeIntegrator_DSTATE;
      rt_LoggedStateSignalPtrs[33] = (void*)
        &CO_bump_DW.DiscreteFIRFilter_circBuf;
      rt_LoggedStateSignalPtrs[34] = (void*)&CO_bump_DW.DelayInput1_DSTATE;
      rt_LoggedStateSignalPtrs[35] = (void*)&CO_bump_DW.DelayInput1_DSTATE_d;
      rt_LoggedStateSignalPtrs[36] = (void*)&CO_bump_DW.DelayInput1_DSTATE_m;
      rt_LoggedStateSignalPtrs[37] = (void*)&CO_bump_DW.DelayInput1_DSTATE_p;
    }

    rtliSetLogT(CO_bump_M->rtwLogInfo, "tout");
    rtliSetLogX(CO_bump_M->rtwLogInfo, "xout");
    rtliSetLogXFinal(CO_bump_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(CO_bump_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(CO_bump_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(CO_bump_M->rtwLogInfo, 0);
    rtliSetLogDecimation(CO_bump_M->rtwLogInfo, 1);
    rtliSetLogY(CO_bump_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(CO_bump_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(CO_bump_M->rtwLogInfo, (NULL));
  }

  CO_bump_M->solverInfoPtr = (&CO_bump_M->solverInfo);
  CO_bump_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&CO_bump_M->solverInfo, 0.001);
  rtsiSetSolverMode(&CO_bump_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  CO_bump_M->ModelData.blockIO = ((void *) &CO_bump_B);
  (void) memset(((void *) &CO_bump_B), 0,
                sizeof(B_CO_bump_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      CO_bump_B.UnitDelay1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.Gain[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.Sum[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.Gain1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.Add[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.Abs[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.Memory[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.Add2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.VectorConcatenate1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.Gain3[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.VectorConcatenate[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.Gain2[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      CO_bump_B.BehaviorCOBump_o2[i] = 0.0;
    }

    for (i = 0; i < 85; i++) {
      CO_bump_B.BehaviorCOBump_o4[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      CO_bump_B.Add_o[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      CO_bump_B.Add1_k[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      CO_bump_B.Gain_o[i] = 0.0;
    }

    for (i = 0; i < 9; i++) {
      CO_bump_B.Gain1_a[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      CO_bump_B.FOffset[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      CO_bump_B.Unpack[i] = 0.0F;
    }

    CO_bump_B.Receive_o2 = 0.0;
    CO_bump_B.yoffset = 0.0;
    CO_bump_B.PCI6025EAD_o1 = 0.0;
    CO_bump_B.PCI6025EAD_o2 = 0.0;
    CO_bump_B.PCI6025EAD_o3 = 0.0;
    CO_bump_B.PCI6025EAD_o4 = 0.0;
    CO_bump_B.PCI6025EAD_o5 = 0.0;
    CO_bump_B.PCI6025EAD_o6 = 0.0;
    CO_bump_B.SumofElements = 0.0;
    CO_bump_B.DotProductY = 0.0;
    CO_bump_B.UnitDelay = 0.0;
    CO_bump_B.Gain_f = 0.0;
    CO_bump_B.Sum_m = 0.0;
    CO_bump_B.Gain1_m = 0.0;
    CO_bump_B.DotProductX = 0.0;
    CO_bump_B.UnitDelay_n = 0.0;
    CO_bump_B.Gain_d = 0.0;
    CO_bump_B.Sum_f = 0.0;
    CO_bump_B.Gain1_c = 0.0;
    CO_bump_B.PCIQUAD041 = 0.0;
    CO_bump_B.Gain1_n = 0.0;
    CO_bump_B.Sum1 = 0.0;
    CO_bump_B.xoffset = 0.0;
    CO_bump_B.PCIQUAD04 = 0.0;
    CO_bump_B.Gain_g = 0.0;
    CO_bump_B.Sum3 = 0.0;
    CO_bump_B.TrigonometricFunction = 0.0;
    CO_bump_B.Product = 0.0;
    CO_bump_B.TrigonometricFunction2 = 0.0;
    CO_bump_B.Product2 = 0.0;
    CO_bump_B.Sum2 = 0.0;
    CO_bump_B.TrigonometricFunction1 = 0.0;
    CO_bump_B.Product1 = 0.0;
    CO_bump_B.TrigonometricFunction3 = 0.0;
    CO_bump_B.Product3 = 0.0;
    CO_bump_B.Sum3_c = 0.0;
    CO_bump_B.Switch_d[0] = 0.0;
    CO_bump_B.Switch_d[1] = 0.0;
    CO_bump_B.NeuralOverride[0] = 0.0;
    CO_bump_B.NeuralOverride[1] = 0.0;
    CO_bump_B.x = 0.0;
    CO_bump_B.x_m = 0.0;
    CO_bump_B.Add_m = 0.0;
    CO_bump_B.x_f = 0.0;
    CO_bump_B.x_g = 0.0;
    CO_bump_B.MatrixConcatenate2[0] = 0.0;
    CO_bump_B.MatrixConcatenate2[1] = 0.0;
    CO_bump_B.MatrixConcatenate2[2] = 0.0;
    CO_bump_B.MatrixConcatenate2[3] = 0.0;
    CO_bump_B.DigitalFilter2 = 0.0;
    CO_bump_B.Derivative = 0.0;
    CO_bump_B.dG = 0.0;
    CO_bump_B.DigitalFilter = 0.0;
    CO_bump_B.DigitalFilter2_p = 0.0;
    CO_bump_B.Derivative_e = 0.0;
    CO_bump_B.dG_o = 0.0;
    CO_bump_B.DigitalFilter_p = 0.0;
    CO_bump_B.Switch_j[0] = 0.0;
    CO_bump_B.Switch_j[1] = 0.0;
    CO_bump_B.MultiportSwitch[0] = 0.0;
    CO_bump_B.MultiportSwitch[1] = 0.0;
    CO_bump_B.x_o = 0.0;
    CO_bump_B.x_b = 0.0;
    CO_bump_B.Add_h = 0.0;
    CO_bump_B.x_ox = 0.0;
    CO_bump_B.x_e = 0.0;
    CO_bump_B.LoadSelectSwitch[0] = 0.0;
    CO_bump_B.LoadSelectSwitch[1] = 0.0;
    CO_bump_B.BehaviorCOBump_o1[0] = 0.0;
    CO_bump_B.BehaviorCOBump_o1[1] = 0.0;
    CO_bump_B.BehaviorCOBump_o3 = 0.0;
    CO_bump_B.BehaviorCOBump_o5 = 0.0;
    CO_bump_B.BehaviorCOBump_o6[0] = 0.0;
    CO_bump_B.BehaviorCOBump_o6[1] = 0.0;
    CO_bump_B.BehaviorCOBump_o7[0] = 0.0;
    CO_bump_B.BehaviorCOBump_o7[1] = 0.0;
    CO_bump_B.BehaviorCOBump_o7[2] = 0.0;
    CO_bump_B.BehaviorCOBump_o7[3] = 0.0;
    CO_bump_B.BehaviorCOBump_o8[0] = 0.0;
    CO_bump_B.BehaviorCOBump_o8[1] = 0.0;
    CO_bump_B.y = 0.0;
    CO_bump_B.Add1 = 0.0;
    CO_bump_B.z = 0.0;
    CO_bump_B.Add3 = 0.0;
    CO_bump_B.product2 = 0.0;
    CO_bump_B.Add2_o = 0.0;
    CO_bump_B.product3 = 0.0;
    CO_bump_B.product4 = 0.0;
    CO_bump_B.Add4 = 0.0;
    CO_bump_B.product1 = 0.0;
    CO_bump_B.dX = 0.0;
    CO_bump_B.AddX = 0.0;
    CO_bump_B.dY = 0.0;
    CO_bump_B.AddX1 = 0.0;
    CO_bump_B.dZ = 0.0;
    CO_bump_B.AddX2 = 0.0;
    CO_bump_B.y_m = 0.0;
    CO_bump_B.Add1_l = 0.0;
    CO_bump_B.z_g = 0.0;
    CO_bump_B.Add3_n = 0.0;
    CO_bump_B.product2_i = 0.0;
    CO_bump_B.Add2_i = 0.0;
    CO_bump_B.product3_d = 0.0;
    CO_bump_B.product4_c = 0.0;
    CO_bump_B.Add4_i = 0.0;
    CO_bump_B.product1_j = 0.0;
    CO_bump_B.dX_a = 0.0;
    CO_bump_B.AddX_g = 0.0;
    CO_bump_B.dY_o = 0.0;
    CO_bump_B.AddX1_j = 0.0;
    CO_bump_B.dZ_o = 0.0;
    CO_bump_B.AddX2_l = 0.0;
    CO_bump_B.y_f = 0.0;
    CO_bump_B.Add1_g = 0.0;
    CO_bump_B.z_p = 0.0;
    CO_bump_B.Add3_i = 0.0;
    CO_bump_B.product2_j = 0.0;
    CO_bump_B.Add2_p = 0.0;
    CO_bump_B.product3_o = 0.0;
    CO_bump_B.product4_o = 0.0;
    CO_bump_B.Add4_j = 0.0;
    CO_bump_B.product1_a = 0.0;
    CO_bump_B.dX_p = 0.0;
    CO_bump_B.AddX_n = 0.0;
    CO_bump_B.dY_h = 0.0;
    CO_bump_B.AddX1_d = 0.0;
    CO_bump_B.dZ_k = 0.0;
    CO_bump_B.AddX2_h = 0.0;
    CO_bump_B.y_c = 0.0;
    CO_bump_B.Add1_l1 = 0.0;
    CO_bump_B.z_i = 0.0;
    CO_bump_B.Add3_g = 0.0;
    CO_bump_B.product2_e = 0.0;
    CO_bump_B.Add2_n = 0.0;
    CO_bump_B.product3_b = 0.0;
    CO_bump_B.product4_i = 0.0;
    CO_bump_B.Add4_n = 0.0;
    CO_bump_B.product1_h = 0.0;
    CO_bump_B.dX_o = 0.0;
    CO_bump_B.AddX_c = 0.0;
    CO_bump_B.dY_m = 0.0;
    CO_bump_B.AddX1_o = 0.0;
    CO_bump_B.dZ_om = 0.0;
    CO_bump_B.AddX2_a = 0.0;
    CO_bump_B.y_o = 0.0;
    CO_bump_B.Add1_b = 0.0;
    CO_bump_B.z_e = 0.0;
    CO_bump_B.Add3_a = 0.0;
    CO_bump_B.product2_l = 0.0;
    CO_bump_B.Add2_l = 0.0;
    CO_bump_B.product3_j = 0.0;
    CO_bump_B.product4_a = 0.0;
    CO_bump_B.Add4_g = 0.0;
    CO_bump_B.product1_i = 0.0;
    CO_bump_B.dX_b = 0.0;
    CO_bump_B.AddX_f = 0.0;
    CO_bump_B.dY_a = 0.0;
    CO_bump_B.AddX1_f = 0.0;
    CO_bump_B.dZ_h = 0.0;
    CO_bump_B.AddX2_g = 0.0;
    CO_bump_B.y_i = 0.0;
    CO_bump_B.Add1_h = 0.0;
    CO_bump_B.z_pw = 0.0;
    CO_bump_B.Add3_f = 0.0;
    CO_bump_B.product2_li = 0.0;
    CO_bump_B.Add2_m = 0.0;
    CO_bump_B.product3_e = 0.0;
    CO_bump_B.product4_iq = 0.0;
    CO_bump_B.Add4_gm = 0.0;
    CO_bump_B.product1_l = 0.0;
    CO_bump_B.dX_f = 0.0;
    CO_bump_B.AddX_d = 0.0;
    CO_bump_B.dY_f = 0.0;
    CO_bump_B.AddX1_g = 0.0;
    CO_bump_B.dZ_g = 0.0;
    CO_bump_B.AddX2_o = 0.0;
    CO_bump_B.y_od = 0.0;
    CO_bump_B.Add1_a = 0.0;
    CO_bump_B.z_n = 0.0;
    CO_bump_B.Add3_b = 0.0;
    CO_bump_B.product2_m = 0.0;
    CO_bump_B.Add2_oy = 0.0;
    CO_bump_B.product3_n = 0.0;
    CO_bump_B.product4_cs = 0.0;
    CO_bump_B.Add4_d = 0.0;
    CO_bump_B.product1_ap = 0.0;
    CO_bump_B.dX_d = 0.0;
    CO_bump_B.AddX_j = 0.0;
    CO_bump_B.dY_oz = 0.0;
    CO_bump_B.AddX1_k = 0.0;
    CO_bump_B.dZ_i = 0.0;
    CO_bump_B.AddX2_l1 = 0.0;
    CO_bump_B.y_k = 0.0;
    CO_bump_B.Add1_n = 0.0;
    CO_bump_B.z_gt = 0.0;
    CO_bump_B.Add3_j = 0.0;
    CO_bump_B.product2_c = 0.0;
    CO_bump_B.Add2_e = 0.0;
    CO_bump_B.product3_f = 0.0;
    CO_bump_B.product4_m = 0.0;
    CO_bump_B.Add4_k = 0.0;
    CO_bump_B.product1_m = 0.0;
    CO_bump_B.dX_aq = 0.0;
    CO_bump_B.AddX_a = 0.0;
    CO_bump_B.dY_p = 0.0;
    CO_bump_B.AddX1_m = 0.0;
    CO_bump_B.dZ_b = 0.0;
    CO_bump_B.AddX2_ok = 0.0;
    CO_bump_B.MatrixConcatenation1[0] = 0.0;
    CO_bump_B.MatrixConcatenation1[1] = 0.0;
    CO_bump_B.MatrixConcatenation1[2] = 0.0;
    CO_bump_B.MatrixConcatenation1[3] = 0.0;
    CO_bump_B.Clock = 0.0;
    CO_bump_B.Sum_h = 0.0;
    CO_bump_B.Time = 0.0;
    CO_bump_B.DiscreteFIRFilter[0] = 0.0;
    CO_bump_B.DiscreteFIRFilter[1] = 0.0;
    CO_bump_B.Clock_c = 0.0;
    CO_bump_B.Clock_l = 0.0;
    CO_bump_B.Sum_fl = 0.0;
    CO_bump_B.Time_b = 0.0;
    CO_bump_B.Sum_n = 0.0;
    CO_bump_B.Time_h = 0.0;
    CO_bump_B.Abs2 = 0.0;
    CO_bump_B.Abs3 = 0.0;
    CO_bump_B.Clock_i = 0.0;
    CO_bump_B.Sum_flx = 0.0;
    CO_bump_B.Time_k = 0.0;
    CO_bump_B.Clock_e = 0.0;
    CO_bump_B.Sum_a = 0.0;
    CO_bump_B.Time_j = 0.0;
    CO_bump_B.Switch2[0] = 0.0;
    CO_bump_B.Switch2[1] = 0.0;
    CO_bump_B.MG1 = 0.0;
    CO_bump_B.MG2 = 0.0;
    CO_bump_B.Switch3[0] = 0.0;
    CO_bump_B.Switch3[1] = 0.0;
    CO_bump_B.Switch4 = 0.0;
    CO_bump_B.Switch5 = 0.0;
    CO_bump_B.Abs_h = 0.0;
    CO_bump_B.Abs1 = 0.0;
    CO_bump_B.Clock_j = 0.0;
    CO_bump_B.Sum_ap = 0.0;
    CO_bump_B.UniformRandomNumber = 0.0;
    CO_bump_B.Switch_c = 0.0;
    CO_bump_B.DataTypeConversion = 0.0;
    CO_bump_B.ForIterator = 0.0;
    CO_bump_B.Switch_m = 0.0;
    CO_bump_B.ToBits1_o1 = 0.0;
    CO_bump_B.ToBits1_o2 = 0.0;
    CO_bump_B.ToBits1_o3 = 0.0;
    CO_bump_B.ToBits1_o4 = 0.0;
    CO_bump_B.ToBits1_o5 = 0.0;
    CO_bump_B.ToBits1_o6 = 0.0;
    CO_bump_B.ToBits1_o7 = 0.0;
    CO_bump_B.ToBits1_o8 = 0.0;
    CO_bump_B.Add_hr = 0.0;
    CO_bump_B.Add1_c = 0.0;
    CO_bump_B.Memory_i = 0.0;
    CO_bump_B.SerialConverter = 0.0;
    CO_bump_B.ToBits_o1 = 0.0;
    CO_bump_B.ToBits_o2 = 0.0;
    CO_bump_B.ToBits_o3 = 0.0;
    CO_bump_B.ToBits_o4 = 0.0;
    CO_bump_B.ToBits_o5 = 0.0;
    CO_bump_B.ToBits_o6 = 0.0;
    CO_bump_B.ToBits_o7 = 0.0;
    CO_bump_B.ToBits_o8 = 0.0;
    CO_bump_B.xPCTargetTime = 0.0;
    CO_bump_B.xPCTargetTime_k = 0.0;
    CO_bump_B.Subtract = 0.0;
    CO_bump_B.ScaleTouSec = 0.0;
    CO_bump_B.Switch_o = 0.0;
    CO_bump_B.TrigonometricFunction1_b = 0.0;
    CO_bump_B.Sum_hr = 0.0;
    CO_bump_B.TrigonometricFunction2_e = 0.0;
    CO_bump_B.sqrtu1u1u2u2 = 0.0;
    CO_bump_B.Product1_m = 0.0;
    CO_bump_B.DotProduct2 = 0.0;
    CO_bump_B.Fcn = 0.0;
    CO_bump_B.DotProduct = 0.0;
    CO_bump_B.Add_e = 0.0;
    CO_bump_B.TrigonometricFunction_c = 0.0;
    CO_bump_B.Product_a = 0.0;
    CO_bump_B.DotProduct1 = 0.0;
    CO_bump_B.Add1_o = 0.0;
    CO_bump_B.sqrtu1u1u2u2_d = 0.0;
    CO_bump_B.TrigonometricFunction1_a = 0.0;
    CO_bump_B.Sum_j = 0.0;
    CO_bump_B.TrigonometricFunction2_h = 0.0;
    CO_bump_B.Product1_g = 0.0;
    CO_bump_B.TrigonometricFunction_i = 0.0;
    CO_bump_B.Product_d = 0.0;
    CO_bump_B.Sum1_m = 0.0;
    CO_bump_B.Sum4 = 0.0;
    CO_bump_B.sqrtu1u1u2u2_p = 0.0;
    CO_bump_B.TrigonometricFunction1_av = 0.0;
    CO_bump_B.Sum_e = 0.0;
    CO_bump_B.TrigonometricFunction2_hb = 0.0;
    CO_bump_B.Product1_c = 0.0;
    CO_bump_B.TrigonometricFunction_n = 0.0;
    CO_bump_B.Product_f = 0.0;
    CO_bump_B.TachGain2 = 0.0;
    CO_bump_B.TachGain1 = 0.0;
    CO_bump_B.TmpSignalConversionAtMatrixMult[0] = 0.0;
    CO_bump_B.TmpSignalConversionAtMatrixMult[1] = 0.0;
    CO_bump_B.MatrixMultiply[0] = 0.0;
    CO_bump_B.MatrixMultiply[1] = 0.0;
    CO_bump_B.Gain_fi[0] = 0.0;
    CO_bump_B.Gain_fi[1] = 0.0;
    CO_bump_B.Transpose[0] = 0.0;
    CO_bump_B.Transpose[1] = 0.0;
    CO_bump_B.Transpose[2] = 0.0;
    CO_bump_B.Transpose[3] = 0.0;
    CO_bump_B.MatrixMultiply_e[0] = 0.0;
    CO_bump_B.MatrixMultiply_e[1] = 0.0;
    CO_bump_B.Switch1[0] = 0.0;
    CO_bump_B.Switch1[1] = 0.0;
    CO_bump_B.Switch_cu[0] = 0.0;
    CO_bump_B.Switch_cu[1] = 0.0;
    CO_bump_B.BoundingBoxViscosity[0] = 0.0;
    CO_bump_B.BoundingBoxViscosity[1] = 0.0;
    CO_bump_B.Add_j = 0.0;
    CO_bump_B.Product_l[0] = 0.0;
    CO_bump_B.Product_l[1] = 0.0;
    CO_bump_B.Product_o = 0.0;
    CO_bump_B.Gain1_ay = 0.0;
    CO_bump_B.Saturation = 0.0;
    CO_bump_B.Gain3_d = 0.0;
    CO_bump_B.Add_jr = 0.0;
    CO_bump_B.Gain4 = 0.0;
    CO_bump_B.Product1_mk = 0.0;
    CO_bump_B.Gain2_f = 0.0;
    CO_bump_B.Saturation1 = 0.0;
    CO_bump_B.Add1_g3 = 0.0;
    CO_bump_B.Saturation_g = 0.0;
    CO_bump_B.Saturation1_f = 0.0;
    CO_bump_B.GainM1Pos = 0.0;
    CO_bump_B.GainM1Neg = 0.0;
    CO_bump_B.GainM2Pos = 0.0;
    CO_bump_B.GainM2Neg = 0.0;
    CO_bump_B.Add1_ce = 0.0;
    CO_bump_B.LorentzForceGain[0] = 0.0;
    CO_bump_B.LorentzForceGain[1] = 0.0;
    CO_bump_B.dynamicAngleSwitch = 0.0;
    CO_bump_B.sin_a = 0.0;
    CO_bump_B.Inverter[0] = 0.0;
    CO_bump_B.Inverter[1] = 0.0;
    CO_bump_B.Product3_o = 0.0;
    CO_bump_B.cos_k = 0.0;
    CO_bump_B.Product2_g = 0.0;
    CO_bump_B.Subtract_i = 0.0;
    CO_bump_B.Product1_a = 0.0;
    CO_bump_B.Product_c = 0.0;
    CO_bump_B.Add_a = 0.0;
    CO_bump_B.Gain_h[0] = 0.0;
    CO_bump_B.Gain_h[1] = 0.0;
    CO_bump_B.Gain_b = 0.0;
    CO_bump_B.Add1_li = 0.0;
    CO_bump_B.LorentzForceGain_f[0] = 0.0;
    CO_bump_B.LorentzForceGain_f[1] = 0.0;
    CO_bump_B.DynamicAngleSwitch = 0.0;
    CO_bump_B.sin_i = 0.0;
    CO_bump_B.Inverter_c[0] = 0.0;
    CO_bump_B.Inverter_c[1] = 0.0;
    CO_bump_B.Product3_d = 0.0;
    CO_bump_B.cos_d = 0.0;
    CO_bump_B.Product2_o = 0.0;
    CO_bump_B.Subtract_h = 0.0;
    CO_bump_B.Product1_d = 0.0;
    CO_bump_B.Product_p = 0.0;
    CO_bump_B.Add_c = 0.0;
    CO_bump_B.Gain_a[0] = 0.0;
    CO_bump_B.Gain_a[1] = 0.0;
    CO_bump_B.Gain_c = 0.0;
    CO_bump_B.SampleandHold.In = 0.0;
    CO_bump_B.SampleandHold_j.In = 0.0;
    CO_bump_B.EnabledSubsystem_e.In1 = 0.0;
    CO_bump_B.EnabledSubsystem_l.In1 = 0.0;
    CO_bump_B.EnabledSubsystem_d.In1 = 0.0;
    CO_bump_B.EnabledSubsystem_m.In1 = 0.0;
    CO_bump_B.EnabledSubsystem.In1 = 0.0;
  }

  /* parameters */
  CO_bump_M->ModelData.defaultParam = ((real_T *)&CO_bump_P);

  /* states (dwork) */
  CO_bump_M->ModelData.dwork = ((void *) &CO_bump_DW);
  (void) memset((void *)&CO_bump_DW, 0,
                sizeof(DW_CO_bump_T));

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      CO_bump_DW.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  CO_bump_DW.UnitDelay_DSTATE = 0.0;
  CO_bump_DW.UnitDelay_DSTATE_e = 0.0;
  CO_bump_DW.x_DSTATE = 0.0;
  CO_bump_DW.x_DSTATE_i = 0.0;
  CO_bump_DW.x_DSTATE_o = 0.0;
  CO_bump_DW.x_DSTATE_a = 0.0;

  {
    int32_T i;
    for (i = 0; i < 11; i++) {
      CO_bump_DW.DigitalFilter2_FILT_STATES[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 11; i++) {
      CO_bump_DW.DigitalFilter_FILT_STATES[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 11; i++) {
      CO_bump_DW.DigitalFilter2_FILT_STATES_k[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 11; i++) {
      CO_bump_DW.DigitalFilter_FILT_STATES_o[i] = 0.0;
    }
  }

  CO_bump_DW.x_DSTATE_p = 0.0;
  CO_bump_DW.x_DSTATE_ix = 0.0;
  CO_bump_DW.x_DSTATE_f = 0.0;
  CO_bump_DW.x_DSTATE_l = 0.0;
  CO_bump_DW.y_DSTATE = 0.0;
  CO_bump_DW.z_DSTATE = 0.0;
  CO_bump_DW.y_DSTATE_n = 0.0;
  CO_bump_DW.z_DSTATE_f = 0.0;
  CO_bump_DW.y_DSTATE_k = 0.0;
  CO_bump_DW.z_DSTATE_l = 0.0;
  CO_bump_DW.y_DSTATE_a = 0.0;
  CO_bump_DW.z_DSTATE_a = 0.0;
  CO_bump_DW.y_DSTATE_g = 0.0;
  CO_bump_DW.z_DSTATE_k = 0.0;
  CO_bump_DW.y_DSTATE_b = 0.0;
  CO_bump_DW.z_DSTATE_m = 0.0;
  CO_bump_DW.y_DSTATE_kn = 0.0;
  CO_bump_DW.z_DSTATE_d = 0.0;
  CO_bump_DW.y_DSTATE_j = 0.0;
  CO_bump_DW.z_DSTATE_d0 = 0.0;

  {
    int32_T i;
    for (i = 0; i < 58; i++) {
      CO_bump_DW.DiscreteFIRFilter_states[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      CO_bump_DW.Memory_PreviousInput[i] = 0.0;
    }
  }

  CO_bump_DW.TimeStampA = 0.0;
  CO_bump_DW.LastUAtTimeA = 0.0;
  CO_bump_DW.TimeStampB = 0.0;
  CO_bump_DW.LastUAtTimeB = 0.0;
  CO_bump_DW.TimeStampA_o = 0.0;
  CO_bump_DW.LastUAtTimeA_h = 0.0;
  CO_bump_DW.TimeStampB_a = 0.0;
  CO_bump_DW.LastUAtTimeB_m = 0.0;
  CO_bump_DW.UniformRandomNumber_NextOutput = 0.0;
  CO_bump_DW.Memory_PreviousInput_i = 0.0;

  {
    int32_T i;
    for (i = 0; i < 64; i++) {
      CO_bump_DW.PCI6025EAD_RWORK[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      CO_bump_DW.PCI6025E_RWORK[i] = 0.0;
    }
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  CO_bump_InitializeDataMapInfo(CO_bump_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &CO_bump_M->NonInlinedSFcns.sfcnInfo;
    CO_bump_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(CO_bump_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &CO_bump_M->Sizes.numSampTimes);
    CO_bump_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(CO_bump_M)[0]);
    CO_bump_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(CO_bump_M)[1]);
    CO_bump_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr(CO_bump_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,CO_bump_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(CO_bump_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(CO_bump_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(CO_bump_M));
    rtssSetStepSizePtr(sfcnInfo, &CO_bump_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(CO_bump_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &CO_bump_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &CO_bump_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &CO_bump_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &CO_bump_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &CO_bump_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &CO_bump_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &CO_bump_M->solverInfoPtr);
  }

  CO_bump_M->Sizes.numSFcns = (16);

  /* register each child */
  {
    (void) memset((void *)&CO_bump_M->NonInlinedSFcns.childSFunctions[0], 0,
                  16*sizeof(SimStruct));
    CO_bump_M->childSfunctions = (&CO_bump_M->
      NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 16; i++) {
        CO_bump_M->childSfunctions[i] =
          (&CO_bump_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: CO_bump/<S79>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &CO_bump_B.xPCTargetTime_k));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "CO_bump/XY Position Subsystem1/For Iterator Subsystem/Whiltor Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.xPCTargetTime_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.xPCTargetTime_P2_Size);
      }

      /* registration */
      xpctimeinfo(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: CO_bump/<S79>/PCI-6025E  (donipcie) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &CO_bump_B.Switch_o;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &CO_bump_B.DataTypeConversion;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts,
                "CO_bump/XY Position Subsystem1/For Iterator Subsystem/Whiltor Subsystem/PCI-6025E ");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.PCI6025E_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.PCI6025E_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)CO_bump_P.PCI6025E_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)CO_bump_P.PCI6025E_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)CO_bump_P.PCI6025E_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)CO_bump_P.PCI6025E_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)CO_bump_P.PCI6025E_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &CO_bump_DW.PCI6025E_IWORK_o[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CO_bump_DW.PCI6025E_IWORK_o[0]);
      }

      /* registration */
      donipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: CO_bump/<S75>/ToBits1 (Byte2Bits) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &CO_bump_B.Switch_m;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &CO_bump_B.ToBits1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &CO_bump_B.ToBits1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &CO_bump_B.ToBits1_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &CO_bump_B.ToBits1_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &CO_bump_B.ToBits1_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &CO_bump_B.ToBits1_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &CO_bump_B.ToBits1_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &CO_bump_B.ToBits1_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits1");
      ssSetPath(rts,
                "CO_bump/XY Position Subsystem1/For Iterator Subsystem/ToBits1");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      Byte2Bits(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: CO_bump/<S75>/Port A (dopci8255) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &CO_bump_B.ToBits1_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &CO_bump_B.ToBits1_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn3.UPtrs2;
          sfcnUPtrs[0] = &CO_bump_B.ToBits1_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn3.UPtrs3;
          sfcnUPtrs[0] = &CO_bump_B.ToBits1_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn3.UPtrs4;
          sfcnUPtrs[0] = &CO_bump_B.ToBits1_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn3.UPtrs5;
          sfcnUPtrs[0] = &CO_bump_B.ToBits1_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn3.UPtrs6;
          sfcnUPtrs[0] = &CO_bump_B.ToBits1_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn3.UPtrs7;
          sfcnUPtrs[0] = &CO_bump_B.ToBits1_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port A");
      ssSetPath(rts,
                "CO_bump/XY Position Subsystem1/For Iterator Subsystem/Port A");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.PortA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.PortA_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)CO_bump_P.PortA_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)CO_bump_P.PortA_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)CO_bump_P.PortA_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)CO_bump_P.PortA_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)CO_bump_P.PortA_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)CO_bump_P.PortA_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)CO_bump_P.PortA_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)CO_bump_P.PortA_P10_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &CO_bump_DW.PortA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CO_bump_DW.PortA_IWORK[0]);
      }

      /* registration */
      dopci8255(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetInputPortConnected(rts, 4, 1);
      _ssSetInputPortConnected(rts, 5, 1);
      _ssSetInputPortConnected(rts, 6, 1);
      _ssSetInputPortConnected(rts, 7, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
      ssSetInputPortBufferDstPort(rts, 4, -1);
      ssSetInputPortBufferDstPort(rts, 5, -1);
      ssSetInputPortBufferDstPort(rts, 6, -1);
      ssSetInputPortBufferDstPort(rts, 7, -1);
    }

    /* Level2 S-Function Block: CO_bump/<S75>/SerialConverter (serPos) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &CO_bump_B.ForIterator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &CO_bump_B.Add_hr;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn4.UPtrs2;
          sfcnUPtrs[0] = &CO_bump_B.Add1_c;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn4.UPtrs3;
          sfcnUPtrs[0] = &CO_bump_B.Memory_i;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &CO_bump_B.SerialConverter));
        }
      }

      /* path info */
      ssSetModelName(rts, "SerialConverter");
      ssSetPath(rts,
                "CO_bump/XY Position Subsystem1/For Iterator Subsystem/SerialConverter");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      serPos(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }

    /* Level2 S-Function Block: CO_bump/<S75>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &CO_bump_B.SerialConverter;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &CO_bump_B.ToBits_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &CO_bump_B.ToBits_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &CO_bump_B.ToBits_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &CO_bump_B.ToBits_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &CO_bump_B.ToBits_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &CO_bump_B.ToBits_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &CO_bump_B.ToBits_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &CO_bump_B.ToBits_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts,
                "CO_bump/XY Position Subsystem1/For Iterator Subsystem/ToBits");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      Byte2Bits(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: CO_bump/<S75>/Port B (dopci8255) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &CO_bump_B.ToBits_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &CO_bump_B.ToBits_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn6.UPtrs2;
          sfcnUPtrs[0] = &CO_bump_B.ToBits_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn6.UPtrs3;
          sfcnUPtrs[0] = &CO_bump_B.ToBits_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn6.UPtrs4;
          sfcnUPtrs[0] = &CO_bump_B.ToBits_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn6.UPtrs5;
          sfcnUPtrs[0] = &CO_bump_B.ToBits_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn6.UPtrs6;
          sfcnUPtrs[0] = &CO_bump_B.ToBits_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn6.UPtrs7;
          sfcnUPtrs[0] = &CO_bump_B.ToBits_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port B");
      ssSetPath(rts,
                "CO_bump/XY Position Subsystem1/For Iterator Subsystem/Port B");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.PortB_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.PortB_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)CO_bump_P.PortB_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)CO_bump_P.PortB_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)CO_bump_P.PortB_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)CO_bump_P.PortB_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)CO_bump_P.PortB_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)CO_bump_P.PortB_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)CO_bump_P.PortB_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)CO_bump_P.PortB_P10_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &CO_bump_DW.PortB_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CO_bump_DW.PortB_IWORK[0]);
      }

      /* registration */
      dopci8255(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetInputPortConnected(rts, 4, 1);
      _ssSetInputPortConnected(rts, 5, 1);
      _ssSetInputPortConnected(rts, 6, 1);
      _ssSetInputPortConnected(rts, 7, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
      ssSetInputPortBufferDstPort(rts, 4, -1);
      ssSetInputPortBufferDstPort(rts, 5, -1);
      ssSetInputPortBufferDstPort(rts, 6, -1);
      ssSetInputPortBufferDstPort(rts, 7, -1);
    }

    /* Level2 S-Function Block: CO_bump/<S75>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &CO_bump_B.xPCTargetTime));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "CO_bump/XY Position Subsystem1/For Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.xPCTargetTime_P1_Size_n);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.xPCTargetTime_P2_Size_j);
      }

      /* registration */
      xpctimeinfo(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: CO_bump/<Root>/Intel Chipset Disable SMI (ich5) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* path info */
      ssSetModelName(rts, "Intel Chipset\nDisable SMI");
      ssSetPath(rts, "CO_bump/Intel Chipset Disable SMI");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetIWork(rts, (int_T *) &CO_bump_DW.IntelChipsetDisableSMI_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CO_bump_DW.IntelChipsetDisableSMI_IWORK[0]);
      }

      /* registration */
      ich5(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: CO_bump/<S5>/Receive (xpcudpbytereceive) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[9]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 48);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) CO_bump_B.Receive_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &CO_bump_B.Receive_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Receive");
      ssSetPath(rts, "CO_bump/Neural Position Subsystem/Receive");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.Receive_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.Receive_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)CO_bump_P.Receive_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)CO_bump_P.Receive_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)CO_bump_P.Receive_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &CO_bump_DW.Receive_IWORK[0]);
      ssSetPWork(rts, (void **) &CO_bump_DW.Receive_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn9.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn9.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CO_bump_DW.Receive_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &CO_bump_DW.Receive_PWORK);
      }

      /* registration */
      xpcudpbytereceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: CO_bump/<S14>/PCI-6025E AD (adnipcie) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[10]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[10]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[10]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &CO_bump_B.PCI6025EAD_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &CO_bump_B.PCI6025EAD_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &CO_bump_B.PCI6025EAD_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &CO_bump_B.PCI6025EAD_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &CO_bump_B.PCI6025EAD_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &CO_bump_B.PCI6025EAD_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E AD");
      ssSetPath(rts, "CO_bump/XY Position Subsystem1/PCI-6025E AD");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.PCI6025EAD_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.PCI6025EAD_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)CO_bump_P.PCI6025EAD_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)CO_bump_P.PCI6025EAD_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)CO_bump_P.PCI6025EAD_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)CO_bump_P.PCI6025EAD_P6_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &CO_bump_DW.PCI6025EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &CO_bump_DW.PCI6025EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn10.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn10.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CO_bump_DW.PCI6025EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &CO_bump_DW.PCI6025EAD_IWORK[0]);
      }

      /* registration */
      adnipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: CO_bump/<S14>/PCI-QUAD04 1 (enccbcioquadcount) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[11]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[11]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[11]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &CO_bump_B.PCIQUAD041));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 1");
      ssSetPath(rts, "CO_bump/XY Position Subsystem1/PCI-QUAD04 1");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.PCIQUAD041_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.PCIQUAD041_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)CO_bump_P.PCIQUAD041_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)CO_bump_P.PCIQUAD041_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)CO_bump_P.PCIQUAD041_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)CO_bump_P.PCIQUAD041_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)CO_bump_P.PCIQUAD041_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)CO_bump_P.PCIQUAD041_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)CO_bump_P.PCIQUAD041_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)CO_bump_P.PCIQUAD041_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)CO_bump_P.PCIQUAD041_P11_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &CO_bump_DW.PCIQUAD041_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CO_bump_DW.PCIQUAD041_IWORK);
      }

      /* registration */
      enccbcioquadcount(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: CO_bump/<S14>/PCI-QUAD04  (enccbcioquadcount) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[12]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[12]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[12]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn12.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &CO_bump_B.PCIQUAD04));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 ");
      ssSetPath(rts, "CO_bump/XY Position Subsystem1/PCI-QUAD04 ");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.PCIQUAD04_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.PCIQUAD04_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)CO_bump_P.PCIQUAD04_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)CO_bump_P.PCIQUAD04_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)CO_bump_P.PCIQUAD04_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)CO_bump_P.PCIQUAD04_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)CO_bump_P.PCIQUAD04_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)CO_bump_P.PCIQUAD04_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)CO_bump_P.PCIQUAD04_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)CO_bump_P.PCIQUAD04_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)CO_bump_P.PCIQUAD04_P11_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &CO_bump_DW.PCIQUAD04_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn12.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn12.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CO_bump_DW.PCIQUAD04_IWORK);
      }

      /* registration */
      enccbcioquadcount(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: CO_bump/<Root>/Behavior CO Bump (mastercon_CO_bump) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[13]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[13]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[13]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 7);
        ssSetPortInfoForInputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn13.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn13.UPtrs0;
          sfcnUPtrs[0] = CO_bump_B.NeuralOverride;
          sfcnUPtrs[1] = &CO_bump_B.NeuralOverride[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn13.UPtrs1;
          sfcnUPtrs[0] = &CO_bump_B.xoffset;
          sfcnUPtrs[1] = &CO_bump_B.yoffset;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn13.UPtrs2;
          sfcnUPtrs[0] = CO_bump_B.MultiportSwitch;
          sfcnUPtrs[1] = &CO_bump_B.MultiportSwitch[1];
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 2);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn13.UPtrs3;
          sfcnUPtrs[0] = CO_bump_B.LoadSelectSwitch;
          sfcnUPtrs[1] = &CO_bump_B.LoadSelectSwitch[1];
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 2);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn13.UPtrs4;
          sfcnUPtrs[0] = (real_T*)&CO_bump_RGND;
          sfcnUPtrs[1] = (real_T*)&CO_bump_RGND;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 2);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn13.UPtrs5;
          sfcnUPtrs[0] = (real_T*)&CO_bump_RGND;
          sfcnUPtrs[1] = (real_T*)&CO_bump_RGND;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 2);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn13.UPtrs6;
          sfcnUPtrs[0] = (real_T*)&CO_bump_RGND;
          sfcnUPtrs[1] = (real_T*)&CO_bump_RGND;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn13.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) CO_bump_B.BehaviorCOBump_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 5);
          ssSetOutputPortSignal(rts, 1, ((real_T *) CO_bump_B.BehaviorCOBump_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &CO_bump_B.BehaviorCOBump_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 85);
          ssSetOutputPortSignal(rts, 3, ((real_T *) CO_bump_B.BehaviorCOBump_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &CO_bump_B.BehaviorCOBump_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 2);
          ssSetOutputPortSignal(rts, 5, ((real_T *) CO_bump_B.BehaviorCOBump_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 4);
          ssSetOutputPortSignal(rts, 6, ((real_T *) CO_bump_B.BehaviorCOBump_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 2);
          ssSetOutputPortSignal(rts, 7, ((real_T *) CO_bump_B.BehaviorCOBump_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "Behavior CO Bump");
      ssSetPath(rts, "CO_bump/Behavior CO Bump");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 46);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.BehaviorCOBump_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.BehaviorCOBump_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)CO_bump_P.BehaviorCOBump_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)CO_bump_P.BehaviorCOBump_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)CO_bump_P.BehaviorCOBump_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)CO_bump_P.BehaviorCOBump_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)CO_bump_P.BehaviorCOBump_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)CO_bump_P.BehaviorCOBump_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)CO_bump_P.BehaviorCOBump_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)CO_bump_P.BehaviorCOBump_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)CO_bump_P.BehaviorCOBump_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)CO_bump_P.BehaviorCOBump_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)CO_bump_P.BehaviorCOBump_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)CO_bump_P.BehaviorCOBump_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)CO_bump_P.BehaviorCOBump_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)CO_bump_P.BehaviorCOBump_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)CO_bump_P.BehaviorCOBump_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)CO_bump_P.BehaviorCOBump_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)CO_bump_P.BehaviorCOBump_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)CO_bump_P.BehaviorCOBump_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)CO_bump_P.BehaviorCOBump_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)CO_bump_P.BehaviorCOBump_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)CO_bump_P.BehaviorCOBump_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)CO_bump_P.BehaviorCOBump_P24_Size);
        ssSetSFcnParam(rts, 24, (mxArray*)CO_bump_P.BehaviorCOBump_P25_Size);
        ssSetSFcnParam(rts, 25, (mxArray*)CO_bump_P.BehaviorCOBump_P26_Size);
        ssSetSFcnParam(rts, 26, (mxArray*)CO_bump_P.BehaviorCOBump_P27_Size);
        ssSetSFcnParam(rts, 27, (mxArray*)CO_bump_P.BehaviorCOBump_P28_Size);
        ssSetSFcnParam(rts, 28, (mxArray*)CO_bump_P.BehaviorCOBump_P29_Size);
        ssSetSFcnParam(rts, 29, (mxArray*)CO_bump_P.BehaviorCOBump_P30_Size);
        ssSetSFcnParam(rts, 30, (mxArray*)CO_bump_P.BehaviorCOBump_P31_Size);
        ssSetSFcnParam(rts, 31, (mxArray*)CO_bump_P.BehaviorCOBump_P32_Size);
        ssSetSFcnParam(rts, 32, (mxArray*)CO_bump_P.BehaviorCOBump_P33_Size);
        ssSetSFcnParam(rts, 33, (mxArray*)CO_bump_P.BehaviorCOBump_P34_Size);
        ssSetSFcnParam(rts, 34, (mxArray*)CO_bump_P.BehaviorCOBump_P35_Size);
        ssSetSFcnParam(rts, 35, (mxArray*)CO_bump_P.BehaviorCOBump_P36_Size);
        ssSetSFcnParam(rts, 36, (mxArray*)CO_bump_P.BehaviorCOBump_P37_Size);
        ssSetSFcnParam(rts, 37, (mxArray*)CO_bump_P.BehaviorCOBump_P38_Size);
        ssSetSFcnParam(rts, 38, (mxArray*)CO_bump_P.BehaviorCOBump_P39_Size);
        ssSetSFcnParam(rts, 39, (mxArray*)CO_bump_P.BehaviorCOBump_P40_Size);
        ssSetSFcnParam(rts, 40, (mxArray*)CO_bump_P.BehaviorCOBump_P41_Size);
        ssSetSFcnParam(rts, 41, (mxArray*)CO_bump_P.BehaviorCOBump_P42_Size);
        ssSetSFcnParam(rts, 42, (mxArray*)CO_bump_P.BehaviorCOBump_P43_Size);
        ssSetSFcnParam(rts, 43, (mxArray*)CO_bump_P.BehaviorCOBump_P44_Size);
        ssSetSFcnParam(rts, 44, (mxArray*)CO_bump_P.BehaviorCOBump_P45_Size);
        ssSetSFcnParam(rts, 45, (mxArray*)CO_bump_P.BehaviorCOBump_P46_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &CO_bump_DW.BehaviorCOBump_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn13.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn13.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CO_bump_DW.BehaviorCOBump_PWORK);
      }

      /* registration */
      mastercon_CO_bump(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetInputPortConnected(rts, 4, 0);
      _ssSetInputPortConnected(rts, 5, 0);
      _ssSetInputPortConnected(rts, 6, 0);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
      ssSetInputPortBufferDstPort(rts, 4, -1);
      ssSetInputPortBufferDstPort(rts, 5, -1);
      ssSetInputPortBufferDstPort(rts, 6, -1);
    }

    /* Level2 S-Function Block: CO_bump/<S8>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[14];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn14.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn14.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn14.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[14]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[14]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[14]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[14]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn14.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, CO_bump_B.RateTransition);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 728);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "CO_bump/SendPacketToGraphics/Send");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.Send_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.Send_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)CO_bump_P.Send_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)CO_bump_P.Send_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)CO_bump_P.Send_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &CO_bump_DW.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &CO_bump_DW.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn14.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn14.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CO_bump_DW.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &CO_bump_DW.Send_PWORK);
      }

      /* registration */
      xpcudpbytesend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.02);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 728);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: CO_bump/<S4>/PCI-6025E  (danipcie) */
    {
      SimStruct *rts = CO_bump_M->childSfunctions[15];

      /* timing info */
      time_T *sfcnPeriod = CO_bump_M->NonInlinedSFcns.Sfcn15.sfcnPeriod;
      time_T *sfcnOffset = CO_bump_M->NonInlinedSFcns.Sfcn15.sfcnOffset;
      int_T *sfcnTsMap = CO_bump_M->NonInlinedSFcns.Sfcn15.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &CO_bump_M->NonInlinedSFcns.blkInfo2[15]);
      }

      ssSetRTWSfcnInfo(rts, CO_bump_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &CO_bump_M->NonInlinedSFcns.methods2[15]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &CO_bump_M->NonInlinedSFcns.methods3[15]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &CO_bump_M->NonInlinedSFcns.statesInfo2[15]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &CO_bump_M->NonInlinedSFcns.Sfcn15.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn15.UPtrs0;
          sfcnUPtrs[0] = &CO_bump_B.Switch4;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &CO_bump_M->NonInlinedSFcns.Sfcn15.UPtrs1;
          sfcnUPtrs[0] = &CO_bump_B.Switch5;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts, "CO_bump/Motor Control1/PCI-6025E ");
      ssSetRTModel(rts,CO_bump_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &CO_bump_M->NonInlinedSFcns.Sfcn15.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)CO_bump_P.PCI6025E_P1_Size_j);
        ssSetSFcnParam(rts, 1, (mxArray*)CO_bump_P.PCI6025E_P2_Size_l);
        ssSetSFcnParam(rts, 2, (mxArray*)CO_bump_P.PCI6025E_P3_Size_e);
        ssSetSFcnParam(rts, 3, (mxArray*)CO_bump_P.PCI6025E_P4_Size_j);
        ssSetSFcnParam(rts, 4, (mxArray*)CO_bump_P.PCI6025E_P5_Size_m);
        ssSetSFcnParam(rts, 5, (mxArray*)CO_bump_P.PCI6025E_P6_Size_o);
        ssSetSFcnParam(rts, 6, (mxArray*)CO_bump_P.PCI6025E_P7_Size_o);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &CO_bump_DW.PCI6025E_RWORK[0]);
      ssSetIWork(rts, (int_T *) &CO_bump_DW.PCI6025E_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn15.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &CO_bump_M->NonInlinedSFcns.Sfcn15.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &CO_bump_DW.PCI6025E_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &CO_bump_DW.PCI6025E_IWORK[0]);
      }

      /* registration */
      danipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  CO_bump_M->Sizes.numContStates = (0);/* Number of continuous states */
  CO_bump_M->Sizes.numY = (0);         /* Number of model outputs */
  CO_bump_M->Sizes.numU = (0);         /* Number of model inputs */
  CO_bump_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  CO_bump_M->Sizes.numSampTimes = (3); /* Number of sample times */
  CO_bump_M->Sizes.numBlocks = (596);  /* Number of blocks */
  CO_bump_M->Sizes.numBlockIO = (454); /* Number of block outputs */
  CO_bump_M->Sizes.numBlockPrms = (765);/* Sum of parameter "widths" */
  return CO_bump_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
