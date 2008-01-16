/*
 * random_walk.c
 *
 * Real-Time Workshop code generation for Simulink model "random_walk.mdl".
 *
 * Model Version              : 1.922
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Jan 09 14:56:49 2008
 */

#include "rt_logging_mmi.h"
#include "random_walk_capi.h"
#include "random_walk.h"
#include "random_walk_private.h"
#include <stdio.h>
#include "random_walk_dt.h"

/* Block signals (auto storage) */
BlockIO_random_walk random_walk_B;

/* Block states (auto storage) */
D_Work_random_walk random_walk_DWork;

/* Real-time model */
rtModel_random_walk random_walk_rtM_;
rtModel_random_walk *random_walk_rtM = &random_walk_rtM_;
static void rate_monotonic_scheduler(void);

/* Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void random_walk_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(random_walk_rtM, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(random_walk_rtM, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(random_walk_rtM, 3));
}

time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(random_walk_rtM, 1);
  rtmSampleHitPtr[2] = rtmStepTask(random_walk_rtM, 2);
  rtmSampleHitPtr[3] = rtmStepTask(random_walk_rtM, 3);
  return(-1);
}

/* This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchagne data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a safe and deterministic data transfer between two rates,
   * data is transfered at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rates: 2, 3 */
  if (random_walk_rtM->Timing.TaskCounters.TID[1] == 0) {
    random_walk_rtM->Timing.RateInteraction.TID1_2 =
      (random_walk_rtM->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    random_walk_rtM->Timing.perTaskSampleHits[6] =
      random_walk_rtM->Timing.RateInteraction.TID1_2;
    random_walk_rtM->Timing.RateInteraction.TID1_3 =
      (random_walk_rtM->Timing.TaskCounters.TID[3] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    random_walk_rtM->Timing.perTaskSampleHits[7] =
      random_walk_rtM->Timing.RateInteraction.TID1_3;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++random_walk_rtM->Timing.TaskCounters.TID[2] == 10) {/* Sample time: [0.01s, 0.0s] */
    random_walk_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  random_walk_rtM->Timing.sampleHits[2] =
    (random_walk_rtM->Timing.TaskCounters.TID[2] == 0);
  if (++random_walk_rtM->Timing.TaskCounters.TID[3] == 20) {/* Sample time: [0.02s, 0.0s] */
    random_walk_rtM->Timing.TaskCounters.TID[3] = 0;
  }

  random_walk_rtM->Timing.sampleHits[3] =
    (random_walk_rtM->Timing.TaskCounters.TID[3] == 0);
}

/* Disable for enable system:
 *   '<S35>/Enabled Subsystem'
 *   '<S36>/Enabled Subsystem'
 *   '<S37>/Enabled Subsystem'
 *   '<S52>/Enabled Subsystem'
 *   '<S10>/Enabled Subsystem'
 */
void random_EnabledSubsystem_Disable(rtDW_EnabledSubsystem_random_wa *localDW)
{
  /* DisableFcn of enable SubSystem Block: '<S35>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE = (int_T) SUBSYS_DISABLED;
}

/* Output and update for enable system:
 *   '<S35>/Enabled Subsystem'
 *   '<S36>/Enabled Subsystem'
 *   '<S37>/Enabled Subsystem'
 *   '<S52>/Enabled Subsystem'
 *   '<S10>/Enabled Subsystem'
 */
void random_walk_EnabledSubsystem(int_T tid, boolean_T rtu_0, real_T rtu_1,
  rtB_EnabledSubsystem_random_wal *localB, rtDW_EnabledSubsystem_random_wa
  *localDW)
{
  /* detect enable/disable transitions */
  if (tid == 0) {
    CondStates prevEnableState = (CondStates) localDW->EnabledSubsystem_MODE;
    CondStates enableState;

    {
      localDW->EnabledSubsystem_MODE = (rtu_0) ? SUBSYS_ENABLED :
        SUBSYS_DISABLED;
    }

    enableState = (CondStates) localDW->EnabledSubsystem_MODE;
    if (enableState == SUBSYS_ENABLED) {
      if (prevEnableState == SUBSYS_DISABLED) {
        /* SUBSYS_BECOMING_ENABLED */
        /* (system enable function is empty) */
        localDW->EnabledSubsystem_MODE = (int_T) SUBSYS_ENABLED;
      }
    } else {
      if (prevEnableState == SUBSYS_ENABLED) {
        /* SUBSYS_BECOMING_DISABLED */
        random_EnabledSubsystem_Disable(localDW);
      }
    }
  }

  /* run blocks if enabled */
  if (localDW->EnabledSubsystem_MODE == SUBSYS_ENABLED) {
    if (tid == 0 || tid == 0) {
      if (tid == 0) {
        /* Inport: '<S45>/In1' */
        localB->In1 = rtu_1;
      }

      srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC);
    }
  }
}

/* Model output function */
void random_walk_output(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  if (tid == 0) {
    srClearBC(random_walk_DWork.EnabledSubsystem_b.EnabledSubsystem_SubsysRanBC);
    srClearBC(random_walk_DWork.EnabledSubsystem_b1.EnabledSubsystem_SubsysRanBC);
    srClearBC(random_walk_DWork.EnabledSubsystem_f.EnabledSubsystem_SubsysRanBC);
    srClearBC(random_walk_DWork.EnabledSubsystem_by.EnabledSubsystem_SubsysRanBC);
    srClearBC(random_walk_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S10>/Clock'
     */
    random_walk_B.Clock = random_walk_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S10>/Memory' */
    random_walk_B.Memory = random_walk_DWork.Memory_PreviousInput;

    /* Memory: '<Root>/Memory' */
    random_walk_B.Memory_h = random_walk_DWork.Memory_PreviousInput_n;

    /* Logic: '<S10>/Logical Operator2' */
    random_walk_B.LogicalOperator2 = (random_walk_B.Memory ||
      random_walk_B.Memory_h);

    /* Logic: '<S10>/Logical Operator1' */
    random_walk_B.LogicalOperator1 = !random_walk_B.LogicalOperator2;

    /* SignalConversion: '<S10>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_EnabledSu =
      random_walk_B.LogicalOperator1;
  }

  /* SubSystem Block: '<S10>/Enabled Subsystem'
   */
  random_walk_EnabledSubsystem(tid,
    random_walk_B.HiddenBuf_InsertedFor_EnabledSu, random_walk_B.Clock,
    &random_walk_B.EnabledSubsystem, &random_walk_DWork.EnabledSubsystem);
  if (tid == 0) {
    /* Sum: '<S10>/Sum' */
    random_walk_B.Sum = random_walk_B.Clock - random_walk_B.EnabledSubsystem.In1;

    /* RelationalOperator: '<S55>/Compare' */
    random_walk_B.Compare = (random_walk_B.Sum > 0.0);

    /* RelationalOperator: '<S10>/Relational Operator' incorporates:
     *  Constant: '<S10>/Time'
     */
    random_walk_B.RelationalOperator = (random_walk_B.Sum >
      random_walk_P.Time_Value);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S10>/Logical Operator' */
    random_walk_B.LogicalOperator = (boolean_T)((random_walk_B.Compare != 0U) ^
      random_walk_B.RelationalOperator);

    /* Level2 S-Function Block: '<S15>/PCI-QUAD04 ' (enccbcioquadcount) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S15>/Gain' */
    random_walk_B.Gain = random_walk_P.Gain_Gain * random_walk_B.PCIQUAD04;

    /* Sum: '<S15>/Sum3' incorporates:
     *  Constant: '<S15>/shoulderOffset'
     */
    random_walk_B.Sum3 = random_walk_B.Gain + random_walk_P.shoulderOffset_Value;

    /* Fcn: '<S59>/sin(length of Shoulder)' */
    random_walk_B.sinlengthofShoulder = 25.0 * cos(random_walk_B.Sum3);

    /* Level2 S-Function Block: '<S15>/PCI-QUAD04 1' (enccbcioquadcount) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    {
      real_T tmp;
      real_T tmp_0;

      /* Gain: '<S15>/Gain1' */
      random_walk_B.Gain1 = random_walk_P.Gain1_Gain * random_walk_B.PCIQUAD041;

      /* Sum: '<S15>/Sum1' incorporates:
       *  Constant: '<S15>/elbowOffset'
       */
      random_walk_B.Sum1 = random_walk_B.Gain1 + random_walk_P.elbowOffset_Value;

      /* Fcn: '<S59>/sin(length of Elbow)' */
      random_walk_B.sinlengthofElbow = 26.800000000000001 * sin
        (random_walk_B.Sum1);

      /* Sum: '<S59>/Sum2' */
      random_walk_B.Sum2 = (0.0 - random_walk_B.sinlengthofShoulder) -
        random_walk_B.sinlengthofElbow;

      /* Sum: '<S59>/Sum4' incorporates:
       *  Constant: '<S59>/yoffset'
       */
      random_walk_B.Sum4 = random_walk_B.Sum2 + random_walk_P.yoffset_Value;

      /* Fcn: '<S59>/cos(length of Shoulder)' */
      random_walk_B.coslengthofShoulder = 25.0 * sin(random_walk_B.Sum3);

      /* Fcn: '<S59>/cos(length of Elbow)' */
      random_walk_B.coslengthofElbow = 26.800000000000001 * cos
        (random_walk_B.Sum1);

      /* Sum: '<S59>/Sum3' */
      random_walk_B.Sum3_i = random_walk_B.coslengthofElbow -
        random_walk_B.coslengthofShoulder;

      /* Sum: '<S59>/Sum1' incorporates:
       *  Constant: '<S59>/xoffset'
       */
      random_walk_B.Sum1_g = random_walk_B.Sum3_i + random_walk_P.xoffset_Value;

      /* Trigonometry: '<S57>/Trigonometric Function1' */
      random_walk_B.TrigonometricFunction1 = rt_atan2(random_walk_B.Sum4,
        random_walk_B.Sum1_g);

      /* Sum: '<S57>/Sum' incorporates:
       *  Constant: '<S57>/AngleOffset'
       */
      random_walk_B.Sum_h = random_walk_B.TrigonometricFunction1 +
        random_walk_P.AngleOffset_Value;

      /* Trigonometry: '<S57>/Trigonometric Function2' */
      random_walk_B.TrigonometricFunction2 = cos(random_walk_B.Sum_h);

      /* Fcn: '<S57>/sqrt(u[1]*u[1] + u[2]*u[2])' */
      tmp = random_walk_B.Sum4;
      tmp_0 = random_walk_B.Sum1_g;
      random_walk_B.sqrtu1u1u2u2 = sqrt(tmp * tmp + tmp_0 * tmp_0);

      /* Product: '<S57>/Product1' */
      random_walk_B.Product1 = random_walk_B.TrigonometricFunction2 *
        random_walk_B.sqrtu1u1u2u2;
    }

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S7>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&random_walk_B.Product1, &random_walk_B.DigitalFilter2,
                    &random_walk_DWork.DigitalFilter2_FILT_STATES[0],
                    &random_walk_DWork.DigitalFilter2_CIRCBUFFIDX, 11, 1, 1,
                    &random_walk_P.DigitalFilter2_RTP1COEFF[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S7>/Derivative' */
    {
      real_T t = random_walk_rtM->Timing.t[0];
      real_T timeStampA = random_walk_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = random_walk_DWork.Derivative_RWORK.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        random_walk_B.Derivative = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &random_walk_DWork.Derivative_RWORK.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        random_walk_B.Derivative = (random_walk_B.DigitalFilter2 - *lastBank++) /
          deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S7>/dG' */
    random_walk_B.dG = random_walk_P.dG_Gain * random_walk_B.Derivative;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S7>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&random_walk_B.dG, &random_walk_B.DigitalFilter,
                    &random_walk_DWork.DigitalFilter_FILT_STATES[0],
                    &random_walk_DWork.DigitalFilter_CIRCBUFFIDX, 11, 1, 1,
                    &random_walk_P.DigitalFilter_RTP1COEFF[0], 1);

    /* Trigonometry: '<S57>/Trigonometric Function' */
    random_walk_B.TrigonometricFunction = sin(random_walk_B.Sum_h);

    /* Product: '<S57>/Product' */
    random_walk_B.Product = random_walk_B.sqrtu1u1u2u2 *
      random_walk_B.TrigonometricFunction;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S8>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&random_walk_B.Product, &random_walk_B.DigitalFilter2_e,
                    &random_walk_DWork.DigitalFilter2_FILT_STATES_i[0],
                    &random_walk_DWork.DigitalFilter2_CIRCBUFFIDX_l, 11, 1, 1,
                    &random_walk_P.DigitalFilter2_RTP1COEFF_k[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S8>/Derivative' */
    {
      real_T t = random_walk_rtM->Timing.t[0];
      real_T timeStampA = random_walk_DWork.Derivative_RWORK_n.TimeStampA;
      real_T timeStampB = random_walk_DWork.Derivative_RWORK_n.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        random_walk_B.Derivative_g = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &random_walk_DWork.Derivative_RWORK_n.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        random_walk_B.Derivative_g = (random_walk_B.DigitalFilter2_e - *lastBank
          ++) / deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S8>/dG' */
    random_walk_B.dG_l = random_walk_P.dG_Gain_p * random_walk_B.Derivative_g;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S8>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&random_walk_B.dG_l, &random_walk_B.DigitalFilter_m,
                    &random_walk_DWork.DigitalFilter_FILT_STATES_a[0],
                    &random_walk_DWork.DigitalFilter_CIRCBUFFIDX_f, 11, 1, 1,
                    &random_walk_P.DigitalFilter_RTP1COEFF_h[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S35>/Clock'
     */
    random_walk_B.Clock_n = random_walk_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S35>/Memory' */
    random_walk_B.Memory_k = random_walk_DWork.Memory_PreviousInput_na;

    /* RelationalOperator: '<S1>/Relational Operator' incorporates:
     *  Constant: '<S1>/XLowLimit'
     */
    random_walk_B.RelationalOperator_n = (random_walk_B.Sum3_i <
      random_walk_P.XLowLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator1' incorporates:
     *  Constant: '<S1>/XHighLimit'
     */
    random_walk_B.RelationalOperator1 = (random_walk_B.Sum3_i >
      random_walk_P.XHighLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator2' incorporates:
     *  Constant: '<S1>/YHighLimit'
     */
    random_walk_B.RelationalOperator2 = (random_walk_B.Sum2 <
      random_walk_P.YHighLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator3' incorporates:
     *  Constant: '<S1>/YLowLimit'
     */
    random_walk_B.RelationalOperator3 = (random_walk_B.Sum2 >
      random_walk_P.YLowLimit_Value);

    /* Logic: '<S1>/Logical Operator' */
    random_walk_B.LogicalOperator_a = (random_walk_B.RelationalOperator_n ||
      random_walk_B.RelationalOperator1 || random_walk_B.RelationalOperator2 ||
      random_walk_B.RelationalOperator3);

    /* Logic: '<S5>/InBox' */
    random_walk_B.InBox = !random_walk_B.LogicalOperator_a;

    /* Logic: '<S37>/Logical Operator3' */
    random_walk_B.LogicalOperator3 = !random_walk_B.InBox;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S37>/Clock'
     */
    random_walk_B.Clock_j = random_walk_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S37>/Memory' */
    random_walk_B.Memory_o = random_walk_DWork.Memory_PreviousInput_k;

    /* Logic: '<S37>/Logical Operator4' */
    random_walk_B.LogicalOperator4 = (random_walk_B.Memory_o &&
      random_walk_B.LogicalOperator3);

    /* RelationalOperator: '<S29>/Compare' */
    random_walk_B.Compare_m = (random_walk_B.DigitalFilter == 0.0);

    /* RelationalOperator: '<S30>/Compare' */
    random_walk_B.Compare_d = (random_walk_B.DigitalFilter_m == 0.0);

    /* Logic: '<S5>/Logical Operator' */
    random_walk_B.LogicalOperator_b = ((random_walk_B.Compare_m != 0U) &&
      (random_walk_B.Compare_d != 0U) && random_walk_B.LogicalOperator_a);

    /* Logic: '<S37>/Logical Operator2' */
    random_walk_B.LogicalOperator2_n = (random_walk_B.LogicalOperator4 ||
      random_walk_B.LogicalOperator_b);

    /* Logic: '<S37>/Logical Operator1' */
    random_walk_B.LogicalOperator1_o = !random_walk_B.LogicalOperator2_n;

    /* SignalConversion: '<S37>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_Enabled_l =
      random_walk_B.LogicalOperator1_o;
  }

  /* SubSystem Block: '<S37>/Enabled Subsystem'
   */
  random_walk_EnabledSubsystem(tid,
    random_walk_B.HiddenBuf_InsertedFor_Enabled_l, random_walk_B.Clock_j,
    &random_walk_B.EnabledSubsystem_f, &random_walk_DWork.EnabledSubsystem_f);
  if (tid == 0) {
    /* Sum: '<S37>/Sum' */
    random_walk_B.Sum_b = random_walk_B.Clock_j -
      random_walk_B.EnabledSubsystem_f.In1;

    /* RelationalOperator: '<S48>/Compare' */
    random_walk_B.Compare_b = (random_walk_B.Sum_b > 0.0);

    /* RelationalOperator: '<S37>/Relational Operator' incorporates:
     *  Constant: '<S37>/Time'
     */
    random_walk_B.RelationalOperator_g = (random_walk_B.Sum_b >
      random_walk_P.Time_Value_c);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S37>/Logical Operator' */
    random_walk_B.LogicalOperator_m = (boolean_T)((random_walk_B.Compare_b != 0U)
      ^ random_walk_B.RelationalOperator_g);

    /* RelationalOperator: '<S51>/Compare' */
    random_walk_B.Compare_f = (random_walk_B.LogicalOperator_m <= FALSE);

    /* UnitDelay: '<S49>/Delay Input1' */
    random_walk_B.Uk1 = random_walk_DWork.DelayInput1_DSTATE;

    /* RelationalOperator: '<S49>/FixPt Relational Operator' */
    random_walk_B.FixPtRelationalOperator = (random_walk_B.Compare_f >
      random_walk_B.Uk1);

    /* Logic: '<S37>/Logical Operator5' */
    random_walk_B.LogicalOperator5 = (random_walk_B.LogicalOperator3 &&
      (random_walk_B.FixPtRelationalOperator != 0U));

    /* Logic: '<S35>/Logical Operator2' */
    random_walk_B.LogicalOperator2_m = (random_walk_B.Memory_k ||
      random_walk_B.LogicalOperator5);

    /* Logic: '<S35>/Logical Operator1' */
    random_walk_B.LogicalOperator1_e = !random_walk_B.LogicalOperator2_m;

    /* SignalConversion: '<S35>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_Enabled_d =
      random_walk_B.LogicalOperator1_e;
  }

  /* SubSystem Block: '<S35>/Enabled Subsystem'
   */
  random_walk_EnabledSubsystem(tid,
    random_walk_B.HiddenBuf_InsertedFor_Enabled_d, random_walk_B.Clock_n,
    &random_walk_B.EnabledSubsystem_b, &random_walk_DWork.EnabledSubsystem_b);
  if (tid == 0) {
    /* Sum: '<S35>/Sum' */
    random_walk_B.Sum_a = random_walk_B.Clock_n -
      random_walk_B.EnabledSubsystem_b.In1;

    /* RelationalOperator: '<S44>/Compare' */
    random_walk_B.Compare_h = (random_walk_B.Sum_a > 0.0);

    /* RelationalOperator: '<S35>/Relational Operator' incorporates:
     *  Constant: '<S35>/Time'
     */
    random_walk_B.RelationalOperator_f = (random_walk_B.Sum_a >
      random_walk_P.Time_Value_d);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S35>/Logical Operator' */
    random_walk_B.LogicalOperator_g = (boolean_T)((random_walk_B.Compare_h != 0U)
      ^ random_walk_B.RelationalOperator_f);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S36>/Clock'
     */
    random_walk_B.Clock_jm = random_walk_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S36>/Memory' */
    random_walk_B.Memory_i = random_walk_DWork.Memory_PreviousInput_l;

    /* Abs: '<S31>/Abs' */
    random_walk_B.Abs = fabs(random_walk_B.Product1);

    /* RelationalOperator: '<S38>/Compare' incorporates:
     *  Constant: '<S38>/Constant'
     */
    random_walk_B.Compare_n = (random_walk_B.Abs <= random_walk_P.Constant_Value);

    /* Abs: '<S31>/Abs2' */
    random_walk_B.Abs2 = fabs(random_walk_B.DigitalFilter);

    /* RelationalOperator: '<S40>/Compare' incorporates:
     *  Constant: '<S40>/Constant'
     */
    random_walk_B.Compare_ht = (random_walk_B.Abs2 <=
      random_walk_P.Constant_Value_c);

    /* Abs: '<S31>/Abs1' */
    random_walk_B.Abs1 = fabs(random_walk_B.Product);

    /* RelationalOperator: '<S39>/Compare' incorporates:
     *  Constant: '<S39>/Constant'
     */
    random_walk_B.Compare_a = (random_walk_B.Abs1 <=
      random_walk_P.Constant_Value_h);

    /* Abs: '<S31>/Abs3' */
    random_walk_B.Abs3 = fabs(random_walk_B.DigitalFilter_m);

    /* RelationalOperator: '<S41>/Compare' incorporates:
     *  Constant: '<S41>/Constant'
     */
    random_walk_B.Compare_o = (random_walk_B.Abs3 <=
      random_walk_P.Constant_Value_n);

    /* Logic: '<S31>/Logical Operator1' */
    random_walk_B.LogicalOperator1_h = ((random_walk_B.Compare_n != 0U) &&
      (random_walk_B.Compare_ht != 0U) && (random_walk_B.Compare_a != 0U) &&
      (random_walk_B.Compare_o != 0U));

    /* RelationalOperator: '<S42>/Compare' */
    random_walk_B.Compare_l = (random_walk_B.LogicalOperator1_h <= FALSE);

    /* UnitDelay: '<S32>/Delay Input1' */
    random_walk_B.Uk1_h = random_walk_DWork.DelayInput1_DSTATE_d;

    /* RelationalOperator: '<S32>/FixPt Relational Operator' */
    random_walk_B.FixPtRelationalOperator_i = (random_walk_B.Compare_l >
      random_walk_B.Uk1_h);

    /* Logic: '<S36>/Logical Operator2' */
    random_walk_B.LogicalOperator2_mo = (random_walk_B.Memory_i ||
      (random_walk_B.FixPtRelationalOperator_i != 0U));

    /* Logic: '<S36>/Logical Operator1' */
    random_walk_B.LogicalOperator1_b = !random_walk_B.LogicalOperator2_mo;

    /* SignalConversion: '<S36>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_Enabled_j =
      random_walk_B.LogicalOperator1_b;
  }

  /* SubSystem Block: '<S36>/Enabled Subsystem'
   */
  random_walk_EnabledSubsystem(tid,
    random_walk_B.HiddenBuf_InsertedFor_Enabled_j, random_walk_B.Clock_jm,
    &random_walk_B.EnabledSubsystem_b1, &random_walk_DWork.EnabledSubsystem_b1);
  if (tid == 0) {
    /* Sum: '<S36>/Sum' */
    random_walk_B.Sum_k = random_walk_B.Clock_jm -
      random_walk_B.EnabledSubsystem_b1.In1;

    /* RelationalOperator: '<S46>/Compare' */
    random_walk_B.Compare_n2 = (random_walk_B.Sum_k > 0.0);

    /* RelationalOperator: '<S36>/Relational Operator' incorporates:
     *  Constant: '<S36>/Time'
     */
    random_walk_B.RelationalOperator_k = (random_walk_B.Sum_k >
      random_walk_P.Time_Value_k);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S36>/Logical Operator' */
    random_walk_B.LogicalOperator_l = (boolean_T)((random_walk_B.Compare_n2 !=
      0U) ^ random_walk_B.RelationalOperator_k);

    /* RelationalOperator: '<S43>/Compare' */
    random_walk_B.Compare_be = (random_walk_B.LogicalOperator_l <= FALSE);

    /* UnitDelay: '<S33>/Delay Input1' */
    random_walk_B.Uk1_p = random_walk_DWork.DelayInput1_DSTATE_c;

    /* RelationalOperator: '<S33>/FixPt Relational Operator' */
    random_walk_B.FixPtRelationalOperator_g = (random_walk_B.Compare_be >
      random_walk_B.Uk1_p);

    /* Logic: '<S5>/Logical Operator4' */
    random_walk_B.LogicalOperator4_p = !random_walk_B.FixPtRelationalOperator_g;

    /* Memory: '<S34>/Memory' */
    random_walk_B.Memory_d = random_walk_DWork.Memory_PreviousInput_d;

    /* CombinatorialLogic Block: '<S34>/Logic'
     */
    {
      int_T rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (int_T)(random_walk_B.LogicalOperator5 != 0);
      rowidx = (rowidx << 1) + (int_T)(random_walk_B.FixPtRelationalOperator_g
        != 0);
      rowidx = (rowidx << 1) + (int_T)(random_walk_B.Memory_d != 0);

      /* Copy the appropriate row of the table into the block output vector */
      random_walk_B.Logic[0] = random_walk_P.Logic_table[rowidx];
      random_walk_B.Logic[1] = random_walk_P.Logic_table[rowidx + 8];
    }

    {
      real_T tmp;
      real_T tmp_0;
      real_T tmp_1;
      real_T tmp_2;
      real_T tmp_3;
      real_T tmp_4;
      real_T tmp_5;
      real_T tmp_6;

      /* Logic: '<S5>/Logical Operator2' */
      random_walk_B.LogicalOperator2_d = (random_walk_B.LogicalOperator4_p &&
        random_walk_B.Logic[0]);

      /* Logic: '<S5>/Logical Operator5' */
      random_walk_B.LogicalOperator5_l = (random_walk_B.LogicalOperator2_d ||
        random_walk_B.LogicalOperator_a);

      /* UnitDelay: '<S25>/x' */
      random_walk_B.x = random_walk_DWork.x_DSTATE;

      /* UnitDelay: '<S26>/x' */
      random_walk_B.x_f = random_walk_DWork.x_DSTATE_m;

      /* Sum: '<S21>/Add' */
      random_walk_B.Add = random_walk_B.x - random_walk_B.x_f;

      /* UnitDelay: '<S27>/x' */
      random_walk_B.x_h = random_walk_DWork.x_DSTATE_d;

      /* UnitDelay: '<S28>/x' */
      random_walk_B.x_l = random_walk_DWork.x_DSTATE_k;

      /* Sum: '<S21>/Add1' */
      random_walk_B.Add1 = random_walk_B.x_h - random_walk_B.x_l;

      /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
       *  Constant: '<S4>/Load'
       *  Constant: '<S4>/Off'
       *  Constant: '<S4>/staticX'
       *  Constant: '<S4>/staticY'
       */
      switch ((int32_T)random_walk_P.Load_Value) {
       case 0:
        tmp = random_walk_P.Off_Value;
        tmp_0 = random_walk_P.Off_Value;
        random_walk_B.MultiportSwitch[0] = tmp;
        random_walk_B.MultiportSwitch[1] = tmp_0;
        break;

       case 1:
        tmp_1 = random_walk_P.staticX_Value;
        tmp_2 = random_walk_P.staticY_Value;
        random_walk_B.MultiportSwitch[0] = tmp_1;
        random_walk_B.MultiportSwitch[1] = tmp_2;
        break;

       case 2:
        /* Gain: '<S4>/LorentzForceGain' */
        tmp_3 = random_walk_B.Add;
        tmp_4 = random_walk_B.Add1;
        random_walk_B.LorentzForceGain[0] = random_walk_P.LorentzForceGain_Gain *
          tmp_3;
        random_walk_B.LorentzForceGain[1] = random_walk_P.LorentzForceGain_Gain *
          tmp_4;
        random_walk_B.MultiportSwitch[0] = random_walk_B.LorentzForceGain[0];
        random_walk_B.MultiportSwitch[1] = random_walk_B.LorentzForceGain[1];
        break;

       default:
        /* MultiPortSwitch: '<S4>/dynamicAngle Switch' incorporates:
         *  Constant: '<S4>/DynamicAngle'
         *  Constant: '<S4>/visAngle'
         */
        if ((int32_T)random_walk_P.DynamicAngle_Value == 0) {
          random_walk_B.dynamicAngleSwitch = random_walk_P.visAngle_Value;
        } else {
          /* Gain: '<S4>/Gain' */
          random_walk_B.Gain_d = random_walk_P.Gain_Gain_p * random_walk_B.Add;
          random_walk_B.dynamicAngleSwitch = random_walk_B.Gain_d;
        }

        /* Trigonometry: '<S22>/sin' */
        random_walk_B.sin_e = sin(random_walk_B.dynamicAngleSwitch);

        /* Product: '<S22>/Product3' */
        random_walk_B.Product3_m = random_walk_B.DigitalFilter *
          random_walk_B.sin_e;

        /* Trigonometry: '<S22>/cos' */
        random_walk_B.cos_o = cos(random_walk_B.dynamicAngleSwitch);

        /* Product: '<S22>/Product2' */
        random_walk_B.Product2_m = random_walk_B.DigitalFilter_m *
          random_walk_B.cos_o;

        /* Sum: '<S22>/Subtract' */
        random_walk_B.Subtract_j = random_walk_B.Product2_m -
          random_walk_B.Product3_m;

        /* Product: '<S22>/Product1' */
        random_walk_B.Product1_f = random_walk_B.DigitalFilter_m *
          random_walk_B.sin_e;

        /* Product: '<S22>/Product' */
        random_walk_B.Product_e = random_walk_B.DigitalFilter *
          random_walk_B.cos_o;

        /* Sum: '<S22>/Add' */
        random_walk_B.Add_c = random_walk_B.Product_e + random_walk_B.Product1_f;

        /* Gain: '<S22>/Gain' */
        tmp_5 = random_walk_B.Add_c;
        tmp_6 = random_walk_B.Subtract_j;
        random_walk_B.Gain_n[0] = random_walk_P.Gain_Gain_go * tmp_5;
        random_walk_B.Gain_n[1] = random_walk_P.Gain_Gain_go * tmp_6;
        random_walk_B.MultiportSwitch[0] = random_walk_B.Gain_n[0];
        random_walk_B.MultiportSwitch[1] = random_walk_B.Gain_n[1];
        break;
      }
    }

    /* Level2 S-Function Block: '<Root>/Behavior RW' (mastercon_rw) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }
  }

  {
    real_T rtsaturate_U0DataInY0Container;
    real_T rtsaturate_U0DataInY0Containe_0;
    real_T cg_in;
    real_T cg_in_0;
    real_T cg_in_1;
    real_T cg_in_2;
    real_T tmp;
    real_T tmp_0;
    real_T tmp_1;
    real_T tmp_2;
    real_T tmp_3;
    real_T tmp_4;
    if (tid == 0) {
      /* Switch: '<Root>/Switch1' incorporates:
       *  Constant: '<Root>/zeroX'
       *  Constant: '<Root>/zeroY'
       */
      if (random_walk_B.LogicalOperator) {
        tmp = random_walk_P.zeroX_Value;
        tmp_0 = random_walk_P.zeroY_Value;
        random_walk_B.Switch1[0] = tmp;
        random_walk_B.Switch1[1] = tmp_0;
      } else {
        /* Switch: '<Root>/Switch' */
        if (random_walk_B.LogicalOperator5_l) {
          /* Logic: '<S5>/Logical Operator6' */
          random_walk_B.LogicalOperator6 = !random_walk_B.LogicalOperator_g;

          /* Logic: '<S5>/Logical Operator3' */
          random_walk_B.LogicalOperator3_d = (random_walk_B.LogicalOperator6 &&
            random_walk_B.LogicalOperator_a);

          /* Switch: '<S5>/Switch' */
          if (random_walk_B.LogicalOperator3_d) {
            tmp_1 = random_walk_B.DigitalFilter;
            tmp_2 = random_walk_B.DigitalFilter_m;
            random_walk_B.Switch_c[0] = tmp_1;
            random_walk_B.Switch_c[1] = tmp_2;
          } else {
            /* Product: '<S5>/Product' */
            random_walk_B.Product_f = (int32_T)random_walk_B.LogicalOperator_g ?
              random_walk_B.Product1 : 0.0;

            /* Gain: '<S5>/Gain1' */
            random_walk_B.Gain1_k = random_walk_P.Gain1_Gain_k *
              random_walk_B.Product_f;

            /* Gain: '<S5>/Gain3' */
            random_walk_B.Gain3 = random_walk_P.Gain3_Gain *
              random_walk_B.DigitalFilter;

            /* Sum: '<S5>/Sum2' */
            random_walk_B.Sum2_f = random_walk_B.Gain3 + random_walk_B.Gain1_k;

            /* Saturate: '<S5>/Saturation' */
            rtsaturate_U0DataInY0Container = rt_SATURATE(random_walk_B.Sum2_f,
              random_walk_P.Saturation_LowerSat,
              random_walk_P.Saturation_UpperSat);
            random_walk_B.Saturation = rtsaturate_U0DataInY0Container;

            /* Gain: '<S5>/Gain4' */
            random_walk_B.Gain4 = random_walk_P.Gain4_Gain *
              random_walk_B.DigitalFilter_m;

            /* Product: '<S5>/Product1' */
            random_walk_B.Product1_b = (int32_T)random_walk_B.LogicalOperator_g ?
              random_walk_B.Product : 0.0;

            /* Gain: '<S5>/Gain2' */
            random_walk_B.Gain2 = random_walk_P.Gain2_Gain *
              random_walk_B.Product1_b;

            /* Sum: '<S5>/Sum1' */
            random_walk_B.Sum1_a = random_walk_B.Gain2 + random_walk_B.Gain4;

            /* Saturate: '<S5>/Saturation1' */
            rtsaturate_U0DataInY0Containe_0 = rt_SATURATE(random_walk_B.Sum1_a,
              random_walk_P.Saturation1_LowerSat,
              random_walk_P.Saturation1_UpperSat);
            random_walk_B.Saturation1 = rtsaturate_U0DataInY0Containe_0;
            tmp_3 = random_walk_B.Saturation;
            tmp_4 = random_walk_B.Saturation1;
            random_walk_B.Switch_c[0] = tmp_3;
            random_walk_B.Switch_c[1] = tmp_4;
          }

          random_walk_B.Switch_i[0] = random_walk_B.Switch_c[0];
          random_walk_B.Switch_i[1] = random_walk_B.Switch_c[1];
        } else {
          random_walk_B.Switch_i[0] = random_walk_B.BehaviorRW_o1[0];
          random_walk_B.Switch_i[1] = random_walk_B.BehaviorRW_o1[1];
        }

        random_walk_B.Switch1[0] = random_walk_B.Switch_i[0];
        random_walk_B.Switch1[1] = random_walk_B.Switch_i[1];
      }

      /* Outputs for atomic SubSystem: '<Root>/Force//Torque Transform' */

      /* Fcn: '<S6>/sin(length of Shoulder)' */
      random_walk_B.sinlengthofShoulder_d = 25.0 * cos(random_walk_B.Sum3);

      /* Product: '<S6>/Product' */
      cg_in = random_walk_B.Switch1[0];
      random_walk_B.Product_h = cg_in * random_walk_B.sinlengthofShoulder_d;

      /* Fcn: '<S6>/cos(length of Shoulder)' */
      random_walk_B.coslengthofShoulder_l = 25.0 * sin(random_walk_B.Sum3);

      /* Product: '<S6>/Product1' */
      cg_in_0 = random_walk_B.Switch1[1];
      random_walk_B.Product1_e = cg_in_0 * random_walk_B.coslengthofShoulder_l;

      /* Fcn: '<S6>/sin(length of Elbow)' */
      random_walk_B.sinlengthofElbow_d = 26.800000000000001 * sin
        (random_walk_B.Sum1);

      /* Product: '<S6>/Product2' */
      cg_in_1 = random_walk_B.Switch1[0];
      random_walk_B.Product2 = cg_in_1 * random_walk_B.sinlengthofElbow_d;

      /* Fcn: '<S6>/cos(length of Elbow)' */
      random_walk_B.coslengthofElbow_m = 26.800000000000001 * cos
        (random_walk_B.Sum1);

      /* Product: '<S6>/Product3' */
      cg_in_2 = random_walk_B.Switch1[1];
      random_walk_B.Product3 = cg_in_2 * random_walk_B.coslengthofElbow_m;

      /* Sum: '<S6>/Sum5' */
      random_walk_B.Sum5 = random_walk_B.Product1_e - random_walk_B.Product_h;

      /* Sum: '<S6>/Sum6' */
      random_walk_B.Sum6 = (0.0 - random_walk_B.Product2) -
        random_walk_B.Product3;

      /* end of Outputs for SubSystem: '<Root>/Force//Torque Transform' */

      /* Gain: '<Root>/MG2' */
      random_walk_B.MG2 = random_walk_P.MG2_Gain * random_walk_B.Sum6;
    }

    /* RateTransition: '<Root>/Rate Transition2' */
    if (tid == 0 && random_walk_rtM->Timing.RateInteraction.TID1_2) {
      random_walk_B.RateTransition2 = random_walk_B.MG2;
    }

    if (tid == 0) {
      /* Gain: '<Root>/MG1' */
      random_walk_B.MG1 = random_walk_P.MG1_Gain * random_walk_B.Sum5;
    }

    /* RateTransition: '<Root>/Rate Transition1' */
    if (tid == 0 && random_walk_rtM->Timing.RateInteraction.TID1_2) {
      random_walk_B.RateTransition1 = random_walk_B.MG1;
    }
  }

  if (tid == 2) {                      /* Sample time: [0.01s, 0.0s] */
    /* Level2 S-Function Block: '<Root>/PCI-6025E ' (danipcie) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[9];
      sfcnOutputs(rts, 2);
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* ok to acquire for <S11>/S-Function */
    random_walk_DWork.SFunction_IWORK.AcquireOK = 1;

    /* Pack: <S13>/Pack */
    (void) memcpy(random_walk_B.Pack,&random_walk_B.Product1,
                  8);
    (void) memcpy(&random_walk_B.Pack[8],&random_walk_B.Product,
                  8);
    (void) memcpy(&random_walk_B.Pack[16],&random_walk_B.BehaviorRW_o4[0],
                  8);
    (void) memcpy(&random_walk_B.Pack[24],&random_walk_B.BehaviorRW_o4[1],
                  8);
    (void) memcpy(&random_walk_B.Pack[32],&random_walk_B.BehaviorRW_o4[2],
                  8);
    (void) memcpy(&random_walk_B.Pack[40],&random_walk_B.BehaviorRW_o4[3],
                  8);
    (void) memcpy(&random_walk_B.Pack[48],&random_walk_B.BehaviorRW_o4[4],
                  8);
    (void) memcpy(&random_walk_B.Pack[56],&random_walk_B.BehaviorRW_o4[5],
                  8);
    (void) memcpy(&random_walk_B.Pack[64],&random_walk_B.BehaviorRW_o4[6],
                  8);
    (void) memcpy(&random_walk_B.Pack[72],&random_walk_B.BehaviorRW_o4[7],
                  8);
    (void) memcpy(&random_walk_B.Pack[80],&random_walk_B.BehaviorRW_o4[8],
                  8);
    (void) memcpy(&random_walk_B.Pack[88],&random_walk_B.BehaviorRW_o4[9],
                  8);
    (void) memcpy(&random_walk_B.Pack[96],&random_walk_B.BehaviorRW_o6[0],
                  8);
    (void) memcpy(&random_walk_B.Pack[104],&random_walk_B.BehaviorRW_o6[1],
                  8);
  }

  {
    int32_T i;

    /* RateTransition: '<S13>/Rate Transition' */
    if (tid == 0 && random_walk_rtM->Timing.RateInteraction.TID1_3) {
      for (i = 0; i < 112; i++) {
        random_walk_B.RateTransition[i] = random_walk_B.Pack[i];
      }
    }
  }

  if (tid == 3) {                      /* Sample time: [0.02s, 0.0s] */
    /* Level2 S-Function Block: '<S13>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[10];
      sfcnOutputs(rts, 3);
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Level2 S-Function Block: '<S14>/ToBits' (Byte2Bits) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[11];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S14>/Port A' (dopci8255) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[12];
      sfcnOutputs(rts, 1);
    }

    /* ok to acquire for <S16>/S-Function */
    random_walk_DWork.SFunction_IWORK_c.AcquireOK = 1;

    /* ok to acquire for <S17>/S-Function */
    random_walk_DWork.SFunction_IWORK_e.AcquireOK = 1;

    /* ok to acquire for <S18>/S-Function */
    random_walk_DWork.SFunction_IWORK_o.AcquireOK = 1;

    /* ok to acquire for <S19>/S-Function */
    random_walk_DWork.SFunction_IWORK_i.AcquireOK = 1;

    /* ok to acquire for <S20>/S-Function */
    random_walk_DWork.SFunction_IWORK_d.AcquireOK = 1;

    /* ok to acquire for <S23>/S-Function */
    random_walk_DWork.SFunction_IWORK_k.AcquireOK = 1;

    /* ok to acquire for <S24>/S-Function */
    random_walk_DWork.SFunction_IWORK_p.AcquireOK = 1;

    {
      int32_T s58_iter;

      /* UnitDelay: '<S25>/y' */
      random_walk_B.y = random_walk_DWork.y_DSTATE;

      /* Sum: '<S25>/Add1' */
      random_walk_B.Add1_o = random_walk_B.y - random_walk_B.x;

      /* UnitDelay: '<S25>/z' */
      random_walk_B.z = random_walk_DWork.z_DSTATE;

      /* Sum: '<S25>/Add3' incorporates:
       *  Constant: '<S25>/rho'
       */
      random_walk_B.Add3 = random_walk_P.rho_Value - random_walk_B.z;

      /* Product: '<S25>/product2' */
      random_walk_B.product2 = random_walk_B.x * random_walk_B.Add3;

      /* Sum: '<S25>/Add2' */
      random_walk_B.Add2 = random_walk_B.product2 - random_walk_B.y;

      /* Product: '<S25>/product3' incorporates:
       *  Constant: '<S25>/beta'
       */
      random_walk_B.product3 = random_walk_B.z * random_walk_P.beta_Value;

      /* Product: '<S25>/product4' */
      random_walk_B.product4 = random_walk_B.y * random_walk_B.x;

      /* Sum: '<S25>/Add4' */
      random_walk_B.Add4 = random_walk_B.product4 - random_walk_B.product3;

      /* Product: '<S25>/product1' incorporates:
       *  Constant: '<S25>/sigma'
       */
      random_walk_B.product1 = random_walk_B.Add1_o * random_walk_P.sigma_Value;

      /* Product: '<S25>/dX' incorporates:
       *  Constant: '<S25>/timescale'
       */
      random_walk_B.dX = random_walk_P.timescale_Value * random_walk_B.product1;

      /* Sum: '<S25>/AddX' */
      random_walk_B.AddX = random_walk_B.x + random_walk_B.dX;

      /* Product: '<S25>/dY' incorporates:
       *  Constant: '<S25>/timescale'
       */
      random_walk_B.dY = random_walk_P.timescale_Value * random_walk_B.Add2;

      /* Sum: '<S25>/AddX1' */
      random_walk_B.AddX1 = random_walk_B.y + random_walk_B.dY;

      /* Product: '<S25>/dZ' incorporates:
       *  Constant: '<S25>/timescale'
       */
      random_walk_B.dZ = random_walk_P.timescale_Value * random_walk_B.Add4;

      /* Sum: '<S25>/AddX2' */
      random_walk_B.AddX2 = random_walk_B.z + random_walk_B.dZ;

      /* UnitDelay: '<S26>/y' */
      random_walk_B.y_e = random_walk_DWork.y_DSTATE_k;

      /* Sum: '<S26>/Add1' */
      random_walk_B.Add1_b = random_walk_B.y_e - random_walk_B.x_f;

      /* UnitDelay: '<S26>/z' */
      random_walk_B.z_o = random_walk_DWork.z_DSTATE_f;

      /* Sum: '<S26>/Add3' incorporates:
       *  Constant: '<S26>/rho'
       */
      random_walk_B.Add3_e = random_walk_P.rho_Value_j - random_walk_B.z_o;

      /* Product: '<S26>/product2' */
      random_walk_B.product2_l = random_walk_B.x_f * random_walk_B.Add3_e;

      /* Sum: '<S26>/Add2' */
      random_walk_B.Add2_b = random_walk_B.product2_l - random_walk_B.y_e;

      /* Product: '<S26>/product3' incorporates:
       *  Constant: '<S26>/beta'
       */
      random_walk_B.product3_b = random_walk_B.z_o * random_walk_P.beta_Value_g;

      /* Product: '<S26>/product4' */
      random_walk_B.product4_d = random_walk_B.y_e * random_walk_B.x_f;

      /* Sum: '<S26>/Add4' */
      random_walk_B.Add4_b = random_walk_B.product4_d - random_walk_B.product3_b;

      /* Product: '<S26>/product1' incorporates:
       *  Constant: '<S26>/sigma'
       */
      random_walk_B.product1_f = random_walk_B.Add1_b *
        random_walk_P.sigma_Value_h;

      /* Product: '<S26>/dX' incorporates:
       *  Constant: '<S26>/timescale'
       */
      random_walk_B.dX_m = random_walk_P.timescale_Value_p *
        random_walk_B.product1_f;

      /* Sum: '<S26>/AddX' */
      random_walk_B.AddX_j = random_walk_B.x_f + random_walk_B.dX_m;

      /* Product: '<S26>/dY' incorporates:
       *  Constant: '<S26>/timescale'
       */
      random_walk_B.dY_f = random_walk_P.timescale_Value_p *
        random_walk_B.Add2_b;

      /* Sum: '<S26>/AddX1' */
      random_walk_B.AddX1_b = random_walk_B.y_e + random_walk_B.dY_f;

      /* Product: '<S26>/dZ' incorporates:
       *  Constant: '<S26>/timescale'
       */
      random_walk_B.dZ_g = random_walk_P.timescale_Value_p *
        random_walk_B.Add4_b;

      /* Sum: '<S26>/AddX2' */
      random_walk_B.AddX2_e = random_walk_B.z_o + random_walk_B.dZ_g;

      /* UnitDelay: '<S27>/y' */
      random_walk_B.y_j = random_walk_DWork.y_DSTATE_n;

      /* Sum: '<S27>/Add1' */
      random_walk_B.Add1_l = random_walk_B.y_j - random_walk_B.x_h;

      /* UnitDelay: '<S27>/z' */
      random_walk_B.z_n = random_walk_DWork.z_DSTATE_d;

      /* Sum: '<S27>/Add3' incorporates:
       *  Constant: '<S27>/rho'
       */
      random_walk_B.Add3_p = random_walk_P.rho_Value_e - random_walk_B.z_n;

      /* Product: '<S27>/product2' */
      random_walk_B.product2_g = random_walk_B.x_h * random_walk_B.Add3_p;

      /* Sum: '<S27>/Add2' */
      random_walk_B.Add2_l = random_walk_B.product2_g - random_walk_B.y_j;

      /* Product: '<S27>/product3' incorporates:
       *  Constant: '<S27>/beta'
       */
      random_walk_B.product3_d = random_walk_B.z_n * random_walk_P.beta_Value_o;

      /* Product: '<S27>/product4' */
      random_walk_B.product4_j = random_walk_B.y_j * random_walk_B.x_h;

      /* Sum: '<S27>/Add4' */
      random_walk_B.Add4_k = random_walk_B.product4_j - random_walk_B.product3_d;

      /* Product: '<S27>/product1' incorporates:
       *  Constant: '<S27>/sigma'
       */
      random_walk_B.product1_a = random_walk_B.Add1_l *
        random_walk_P.sigma_Value_hc;

      /* Product: '<S27>/dX' incorporates:
       *  Constant: '<S27>/timescale'
       */
      random_walk_B.dX_f = random_walk_P.timescale_Value_d *
        random_walk_B.product1_a;

      /* Sum: '<S27>/AddX' */
      random_walk_B.AddX_o = random_walk_B.x_h + random_walk_B.dX_f;

      /* Product: '<S27>/dY' incorporates:
       *  Constant: '<S27>/timescale'
       */
      random_walk_B.dY_b = random_walk_P.timescale_Value_d *
        random_walk_B.Add2_l;

      /* Sum: '<S27>/AddX1' */
      random_walk_B.AddX1_j = random_walk_B.y_j + random_walk_B.dY_b;

      /* Product: '<S27>/dZ' incorporates:
       *  Constant: '<S27>/timescale'
       */
      random_walk_B.dZ_f = random_walk_P.timescale_Value_d *
        random_walk_B.Add4_k;

      /* Sum: '<S27>/AddX2' */
      random_walk_B.AddX2_h = random_walk_B.z_n + random_walk_B.dZ_f;

      /* UnitDelay: '<S28>/y' */
      random_walk_B.y_o = random_walk_DWork.y_DSTATE_d;

      /* Sum: '<S28>/Add1' */
      random_walk_B.Add1_n = random_walk_B.y_o - random_walk_B.x_l;

      /* UnitDelay: '<S28>/z' */
      random_walk_B.z_j = random_walk_DWork.z_DSTATE_dv;

      /* Sum: '<S28>/Add3' incorporates:
       *  Constant: '<S28>/rho'
       */
      random_walk_B.Add3_a = random_walk_P.rho_Value_m - random_walk_B.z_j;

      /* Product: '<S28>/product2' */
      random_walk_B.product2_c = random_walk_B.x_l * random_walk_B.Add3_a;

      /* Sum: '<S28>/Add2' */
      random_walk_B.Add2_d = random_walk_B.product2_c - random_walk_B.y_o;

      /* Product: '<S28>/product3' incorporates:
       *  Constant: '<S28>/beta'
       */
      random_walk_B.product3_i = random_walk_B.z_j * random_walk_P.beta_Value_e;

      /* Product: '<S28>/product4' */
      random_walk_B.product4_p = random_walk_B.y_o * random_walk_B.x_l;

      /* Sum: '<S28>/Add4' */
      random_walk_B.Add4_h = random_walk_B.product4_p - random_walk_B.product3_i;

      /* Product: '<S28>/product1' incorporates:
       *  Constant: '<S28>/sigma'
       */
      random_walk_B.product1_o = random_walk_B.Add1_n *
        random_walk_P.sigma_Value_m;

      /* Product: '<S28>/dX' incorporates:
       *  Constant: '<S28>/timescale'
       */
      random_walk_B.dX_b = random_walk_P.timescale_Value_h *
        random_walk_B.product1_o;

      /* Sum: '<S28>/AddX' */
      random_walk_B.AddX_jl = random_walk_B.x_l + random_walk_B.dX_b;

      /* Product: '<S28>/dY' incorporates:
       *  Constant: '<S28>/timescale'
       */
      random_walk_B.dY_n = random_walk_P.timescale_Value_h *
        random_walk_B.Add2_d;

      /* Sum: '<S28>/AddX1' */
      random_walk_B.AddX1_bw = random_walk_B.y_o + random_walk_B.dY_n;

      /* Product: '<S28>/dZ' incorporates:
       *  Constant: '<S28>/timescale'
       */
      random_walk_B.dZ_i = random_walk_P.timescale_Value_h *
        random_walk_B.Add4_h;

      /* Sum: '<S28>/AddX2' */
      random_walk_B.AddX2_g = random_walk_B.z_j + random_walk_B.dZ_i;

      /* Memory: '<S9>/Memory1' */
      random_walk_B.Memory1 = random_walk_DWork.Memory1_PreviousInput;

      /* DataTypeConversion: '<S9>/Data Type Conversion' */
      random_walk_B.DataTypeConversion = (real_T)random_walk_B.Memory1;
      for (s58_iter = 0; s58_iter < 4; s58_iter++) {
        random_walk_B.ForIterator = (real_T)s58_iter;

        /* Output and update for iterator system: '<S15>/For Iterator Subsystem' */

        /* Sum: '<S58>/Add' incorporates:
         *  Constant: '<S58>/Constant'
         */
        random_walk_B.Add_j = random_walk_B.PCIQUAD04 +
          random_walk_P.Constant_Value_j;

        /* Sum: '<S58>/Add1' incorporates:
         *  Constant: '<S58>/Constant'
         */
        random_walk_B.Add1_oz = random_walk_B.PCIQUAD041 +
          random_walk_P.Constant_Value_j;

        /* Level2 S-Function Block: '<S58>/SerialConverter' (serPos) */
        {
          SimStruct *rts = random_walk_rtM->childSfunctions[2];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S58>/ToBits' (Byte2Bits) */
        {
          SimStruct *rts = random_walk_rtM->childSfunctions[3];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S58>/Port B' (dopci8255) */
        {
          SimStruct *rts = random_walk_rtM->childSfunctions[4];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S58>/xPC Target  Time ' (xpctimeinfo) */
        {
          SimStruct *rts = random_walk_rtM->childSfunctions[5];
          sfcnOutputs(rts, 1);
        }

        do {
          /* Output and update for iterator system: '<S58>/While Iterator Subsystem' */

          /* Level2 S-Function Block: '<S60>/xPC Target  Time ' (xpctimeinfo) */
          {
            SimStruct *rts = random_walk_rtM->childSfunctions[0];
            sfcnOutputs(rts, 1);
          }

          /* Sum: '<S60>/Subtract' */
          random_walk_B.Subtract = random_walk_B.xPCTargetTime_a -
            random_walk_B.xPCTargetTime;

          /* Gain: '<S60>/ScaleTouSec' */
          random_walk_B.ScaleTouSec = random_walk_P.ScaleTouSec_Gain *
            random_walk_B.Subtract;

          /* RelationalOperator: '<S62>/Compare' incorporates:
           *  Constant: '<S62>/Constant'
           */
          random_walk_B.Compare_nw = (random_walk_B.ScaleTouSec >
            random_walk_P.Constant_Value_o);

          /* Switch: '<S60>/Switch' incorporates:
           *  Constant: '<S60>/Constant'
           *  Constant: '<S60>/Constant1'
           */
          if (random_walk_B.Compare_nw) {
            random_walk_B.Switch = random_walk_P.Constant_Value_m;
          } else {
            random_walk_B.Switch = random_walk_P.Constant1_Value;
          }

          /* Level2 S-Function Block: '<S60>/PCI-6025E ' (donipcie) */
          {
            SimStruct *rts = random_walk_rtM->childSfunctions[1];
            sfcnOutputs(rts, 1);
          }

          /* RelationalOperator: '<S61>/Compare' incorporates:
           *  Constant: '<S61>/Constant'
           */
          random_walk_B.Compare_h0 = (random_walk_B.ScaleTouSec <=
            random_walk_P.Constant_Value_ad);
        } while (random_walk_B.Compare_h0);
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S52>/Clock'
     */
    random_walk_B.Clock_c = random_walk_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S52>/Memory' */
    random_walk_B.Memory_oz = random_walk_DWork.Memory_PreviousInput_a;

    /* Logic: '<S52>/Logical Operator2' */
    random_walk_B.LogicalOperator2_f = (random_walk_B.Memory_oz ||
      (random_walk_B.BehaviorRW_o5 != 0.0));

    /* Logic: '<S52>/Logical Operator1' */
    random_walk_B.LogicalOperator1_j = !random_walk_B.LogicalOperator2_f;

    /* SignalConversion: '<S52>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_Enabled_k =
      random_walk_B.LogicalOperator1_j;
  }

  /* SubSystem Block: '<S52>/Enabled Subsystem'
   */
  random_walk_EnabledSubsystem(tid,
    random_walk_B.HiddenBuf_InsertedFor_Enabled_k, random_walk_B.Clock_c,
    &random_walk_B.EnabledSubsystem_by, &random_walk_DWork.EnabledSubsystem_by);
  if (tid == 0) {
    /* Sum: '<S52>/Sum' */
    random_walk_B.Sum_i = random_walk_B.Clock_c -
      random_walk_B.EnabledSubsystem_by.In1;

    /* RelationalOperator: '<S53>/Compare' */
    random_walk_B.Compare_p = (random_walk_B.Sum_i > 0.0);

    /* RelationalOperator: '<S52>/Relational Operator' incorporates:
     *  Constant: '<S52>/Time'
     */
    random_walk_B.RelationalOperator_gb = (random_walk_B.Sum_i >
      random_walk_P.Time_Value_f);
  }

  if (tid == 0) {
    /* Logic: '<S52>/Logical Operator' */
    random_walk_B.LogicalOperator_e = (boolean_T)((random_walk_B.Compare_p != 0U)
      ^ random_walk_B.RelationalOperator_gb);

    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    random_walk_B.Compare_oh = (random_walk_B.MG2 >
      random_walk_P.Constant_Value_a);

    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     */
    random_walk_B.Compare_c = (random_walk_B.MG1 >
      random_walk_P.Constant_Value_nk);

    /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix ConcatenationInPort0' */
    random_walk_B.MatrixConcatenation[0] = random_walk_B.LogicalOperator5_l;

    /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix ConcatenationInPort1' */
    random_walk_B.MatrixConcatenation[1] = random_walk_B.LogicalOperator;

    /* Logic: '<Root>/Logical Operator1' */
    random_walk_B.LogicalOperator1_c = ((random_walk_B.Compare_oh != 0U) ||
      (random_walk_B.Compare_c != 0U));

    /* Sum: '<S12>/Add' */
    random_walk_B.Add_o = random_walk_B.BehaviorRW_o4[1] +
      random_walk_B.BehaviorRW_o4[3];

    /* Sum: '<S12>/Add1' */
    random_walk_B.Add1_f = random_walk_B.BehaviorRW_o4[2] +
      random_walk_B.BehaviorRW_o4[4];

    /* Gain: '<S12>/Gain' */
    random_walk_B.Gain_p = random_walk_P.Gain_Gain_g * random_walk_B.Add_o;

    /* Gain: '<S12>/Gain1' */
    random_walk_B.Gain1_c = random_walk_P.Gain1_Gain_d * random_walk_B.Add1_f;
  }
}

/* Model update function */
void random_walk_update(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S10>/Memory' */
    random_walk_DWork.Memory_PreviousInput = random_walk_B.LogicalOperator;

    /* Update for Memory: '<Root>/Memory' */
    random_walk_DWork.Memory_PreviousInput_n = random_walk_B.LogicalOperator1_c;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S7>/Derivative' */
    {
      real_T timeStampA = random_walk_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = random_walk_DWork.Derivative_RWORK.TimeStampB;
      real_T *lastBank = &random_walk_DWork.Derivative_RWORK.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = random_walk_rtM->Timing.t[0];
      *lastBank++ = random_walk_B.DigitalFilter2;
    }

    /* Derivative Block: '<S8>/Derivative' */
    {
      real_T timeStampA = random_walk_DWork.Derivative_RWORK_n.TimeStampA;
      real_T timeStampB = random_walk_DWork.Derivative_RWORK_n.TimeStampB;
      real_T *lastBank = &random_walk_DWork.Derivative_RWORK_n.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = random_walk_rtM->Timing.t[0];
      *lastBank++ = random_walk_B.DigitalFilter2_e;
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S35>/Memory' */
    random_walk_DWork.Memory_PreviousInput_na = random_walk_B.LogicalOperator_g;

    /* Update for Memory: '<S37>/Memory' */
    random_walk_DWork.Memory_PreviousInput_k = random_walk_B.LogicalOperator_m;

    /* Update for UnitDelay: '<S49>/Delay Input1' */
    random_walk_DWork.DelayInput1_DSTATE = random_walk_B.Compare_f;

    /* Update for Memory: '<S36>/Memory' */
    random_walk_DWork.Memory_PreviousInput_l = random_walk_B.LogicalOperator_l;

    /* Update for UnitDelay: '<S32>/Delay Input1' */
    random_walk_DWork.DelayInput1_DSTATE_d = random_walk_B.Compare_l;

    /* Update for UnitDelay: '<S33>/Delay Input1' */
    random_walk_DWork.DelayInput1_DSTATE_c = random_walk_B.Compare_be;

    /* Update for Memory: '<S34>/Memory' */
    random_walk_DWork.Memory_PreviousInput_d = random_walk_B.Logic[0];

    /* Update for UnitDelay: '<S25>/x' */
    random_walk_DWork.x_DSTATE = random_walk_B.AddX;

    /* Update for UnitDelay: '<S26>/x' */
    random_walk_DWork.x_DSTATE_m = random_walk_B.AddX_j;

    /* Update for UnitDelay: '<S27>/x' */
    random_walk_DWork.x_DSTATE_d = random_walk_B.AddX_o;

    /* Update for UnitDelay: '<S28>/x' */
    random_walk_DWork.x_DSTATE_k = random_walk_B.AddX_jl;

    /* Level2 S-Function Block: '<Root>/Behavior RW' (mastercon_rw) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[8];
      sfcnUpdate(rts, 1);
      if (ssGetErrorStatus(rts) != NULL)
        return;
    }

    /* Update for UnitDelay: '<S25>/y' */
    random_walk_DWork.y_DSTATE = random_walk_B.AddX1;

    /* Update for UnitDelay: '<S25>/z' */
    random_walk_DWork.z_DSTATE = random_walk_B.AddX2;

    /* Update for UnitDelay: '<S26>/y' */
    random_walk_DWork.y_DSTATE_k = random_walk_B.AddX1_b;

    /* Update for UnitDelay: '<S26>/z' */
    random_walk_DWork.z_DSTATE_f = random_walk_B.AddX2_e;

    /* Update for UnitDelay: '<S27>/y' */
    random_walk_DWork.y_DSTATE_n = random_walk_B.AddX1_j;

    /* Update for UnitDelay: '<S27>/z' */
    random_walk_DWork.z_DSTATE_d = random_walk_B.AddX2_h;

    /* Update for UnitDelay: '<S28>/y' */
    random_walk_DWork.y_DSTATE_d = random_walk_B.AddX1_bw;

    /* Update for UnitDelay: '<S28>/z' */
    random_walk_DWork.z_DSTATE_dv = random_walk_B.AddX2_g;

    /* Update for Memory: '<S9>/Memory1' */
    random_walk_DWork.Memory1_PreviousInput = random_walk_B.LogicalOperator_e;

    /* Update for Memory: '<S52>/Memory' */
    random_walk_DWork.Memory_PreviousInput_a = random_walk_B.LogicalOperator_e;
  }

  /* Update absolute time for base rate */
  if (tid == 0) {
    if (!(++random_walk_rtM->Timing.clockTick0))
      ++random_walk_rtM->Timing.clockTickH0;
    random_walk_rtM->Timing.t[0] = random_walk_rtM->Timing.clockTick0 *
      random_walk_rtM->Timing.stepSize0 + random_walk_rtM->Timing.clockTickH0 *
      random_walk_rtM->Timing.stepSize0 * 4294967296.0;
  }

  if (tid == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++random_walk_rtM->Timing.clockTick1))
      ++random_walk_rtM->Timing.clockTickH1;
    random_walk_rtM->Timing.t[1] = random_walk_rtM->Timing.clockTick1 *
      random_walk_rtM->Timing.stepSize1 + random_walk_rtM->Timing.clockTickH1 *
      random_walk_rtM->Timing.stepSize1 * 4294967296.0;
  }

  if (tid == 2) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    if (!(++random_walk_rtM->Timing.clockTick2))
      ++random_walk_rtM->Timing.clockTickH2;
    random_walk_rtM->Timing.t[2] = random_walk_rtM->Timing.clockTick2 *
      random_walk_rtM->Timing.stepSize2 + random_walk_rtM->Timing.clockTickH2 *
      random_walk_rtM->Timing.stepSize2 * 4294967296.0;
  }

  if (tid == 3) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    if (!(++random_walk_rtM->Timing.clockTick3))
      ++random_walk_rtM->Timing.clockTickH3;
    random_walk_rtM->Timing.t[3] = random_walk_rtM->Timing.clockTick3 *
      random_walk_rtM->Timing.stepSize3 + random_walk_rtM->Timing.clockTickH3 *
      random_walk_rtM->Timing.stepSize3 * 4294967296.0;
  }
}

/* Model initialize function */
void random_walk_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */
  /* initialize real-time model */
  (void) memset((char_T *)random_walk_rtM,0,
                sizeof(rtModel_random_walk));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&random_walk_rtM->solverInfo,
                          &random_walk_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&random_walk_rtM->solverInfo, &rtmGetTPtr(random_walk_rtM));
    rtsiSetStepSizePtr(&random_walk_rtM->solverInfo,
                       &random_walk_rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&random_walk_rtM->solverInfo, (&rtmGetErrorStatus
      (random_walk_rtM)));
    rtsiSetRTModelPtr(&random_walk_rtM->solverInfo, random_walk_rtM);
  }

  rtsiSetSimTimeStep(&random_walk_rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&random_walk_rtM->solverInfo,"FixedStepDiscrete");
  random_walk_rtM->solverInfoPtr = (&random_walk_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = random_walk_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    mdlTsMap[3] = 3;
    random_walk_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    random_walk_rtM->Timing.sampleTimes =
      (&random_walk_rtM->Timing.sampleTimesArray[0]);
    random_walk_rtM->Timing.offsetTimes =
      (&random_walk_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    random_walk_rtM->Timing.sampleTimes[0] = (0.0);
    random_walk_rtM->Timing.sampleTimes[1] = (0.001);
    random_walk_rtM->Timing.sampleTimes[2] = (0.01);
    random_walk_rtM->Timing.sampleTimes[3] = (0.02);

    /* task offsets */
    random_walk_rtM->Timing.offsetTimes[0] = (0.0);
    random_walk_rtM->Timing.offsetTimes[1] = (0.0);
    random_walk_rtM->Timing.offsetTimes[2] = (0.0);
    random_walk_rtM->Timing.offsetTimes[3] = (0.0);
  }

  rtmSetTPtr(random_walk_rtM, &random_walk_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = random_walk_rtM->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = random_walk_rtM->Timing.perTaskSampleHitsArray;
    random_walk_rtM->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    random_walk_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(random_walk_rtM, -1);
  random_walk_rtM->Timing.stepSize0 = 0.001;
  random_walk_rtM->Timing.stepSize1 = 0.001;
  random_walk_rtM->Timing.stepSize2 = 0.01;
  random_walk_rtM->Timing.stepSize3 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    random_walk_rtM->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(random_walk_rtM->rtwLogInfo, 2);
    rtliSetLogMaxRows(random_walk_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(random_walk_rtM->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(random_walk_rtM->rtwLogInfo, "rt_");
    rtliSetLogT(random_walk_rtM->rtwLogInfo, "tout");
    rtliSetLogX(random_walk_rtM->rtwLogInfo, "xout");
    rtliSetLogXFinal(random_walk_rtM->rtwLogInfo, "");
    rtliSetSigLog(random_walk_rtM->rtwLogInfo, "");

    /*
     * Set pointers to the data and signal info each state
     */
    {
      static int_T rt_LoggedStateWidths[] = {
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
        1
      };

      static int_T rt_LoggedStateDimensions[] = {
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
        1
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
        "DSTATE" };

      static const char_T *rt_LoggedStateBlockNames[] = {
        "random_walk/Pos2VelX/Digital Filter2",
        "random_walk/Pos2VelX/Digital Filter",
        "random_walk/Pos2VelY/Digital Filter2",
        "random_walk/Pos2VelY/Digital Filter",
        "random_walk/Force Generator/LorentzForce/Lorentz/x",
        "random_walk/Force Generator/LorentzForce/Lorentz1/x",
        "random_walk/Force Generator/LorentzForce/Lorentz2/x",
        "random_walk/Force Generator/LorentzForce/Lorentz3/x",
        "random_walk/Behavior RW",
        "random_walk/Force Generator/LorentzForce/Lorentz/y",
        "random_walk/Force Generator/LorentzForce/Lorentz/z",
        "random_walk/Force Generator/LorentzForce/Lorentz1/y",
        "random_walk/Force Generator/LorentzForce/Lorentz1/z",
        "random_walk/Force Generator/LorentzForce/Lorentz2/y",
        "random_walk/Force Generator/LorentzForce/Lorentz2/z",
        "random_walk/Force Generator/LorentzForce/Lorentz3/y",
        "random_walk/Force Generator/LorentzForce/Lorentz3/z",
        "random_walk/Force outside box/Timer/Detect Fall\nNonpositive/Delay Input1",
        "random_walk/Force outside box/Leave center/Delay Input1",
        "random_walk/Force outside box/Leave center delay/Delay Input1" };

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
        "" };

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
        0
      };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
        20,
        rt_LoggedStateWidths,
        rt_LoggedStateNumDimensions,
        rt_LoggedStateDimensions,
        rt_LoggedStateDataTypeIds,
        rt_LoggedStateComplexSignals,
        NULL,

        { rt_LoggedStateLabels },
        NULL,
        NULL,
        NULL,

        { rt_LoggedStateBlockNames },

        { rt_LoggedStateNames },
        rt_LoggedStateCrossMdlRef,
        rt_RTWLogDataTypeConvert
      };

      rtliSetLogXSignalInfo(random_walk_rtM->rtwLogInfo,
                            &rt_LoggedStateSignalInfo);
    }

    {
      static void * rt_LoggedStateSignalPtrs[20];
      rt_LoggedStateSignalPtrs[0] = (void*)
        &random_walk_DWork.DigitalFilter2_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[1] = (void*)
        &random_walk_DWork.DigitalFilter_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[2] = (void*)
        &random_walk_DWork.DigitalFilter2_FILT_STATES_i[0];
      rt_LoggedStateSignalPtrs[3] = (void*)
        &random_walk_DWork.DigitalFilter_FILT_STATES_a[0];
      rt_LoggedStateSignalPtrs[4] = (void*)&random_walk_DWork.x_DSTATE;
      rt_LoggedStateSignalPtrs[5] = (void*)&random_walk_DWork.x_DSTATE_m;
      rt_LoggedStateSignalPtrs[6] = (void*)&random_walk_DWork.x_DSTATE_d;
      rt_LoggedStateSignalPtrs[7] = (void*)&random_walk_DWork.x_DSTATE_k;
      rt_LoggedStateSignalPtrs[8] = (void*)&random_walk_DWork.BehaviorRW_DSTATE;
      rt_LoggedStateSignalPtrs[9] = (void*)&random_walk_DWork.y_DSTATE;
      rt_LoggedStateSignalPtrs[10] = (void*)&random_walk_DWork.z_DSTATE;
      rt_LoggedStateSignalPtrs[11] = (void*)&random_walk_DWork.y_DSTATE_k;
      rt_LoggedStateSignalPtrs[12] = (void*)&random_walk_DWork.z_DSTATE_f;
      rt_LoggedStateSignalPtrs[13] = (void*)&random_walk_DWork.y_DSTATE_n;
      rt_LoggedStateSignalPtrs[14] = (void*)&random_walk_DWork.z_DSTATE_d;
      rt_LoggedStateSignalPtrs[15] = (void*)&random_walk_DWork.y_DSTATE_d;
      rt_LoggedStateSignalPtrs[16] = (void*)&random_walk_DWork.z_DSTATE_dv;
      rt_LoggedStateSignalPtrs[17] = (void*)
        &random_walk_DWork.DelayInput1_DSTATE;
      rt_LoggedStateSignalPtrs[18] = (void*)
        &random_walk_DWork.DelayInput1_DSTATE_d;
      rt_LoggedStateSignalPtrs[19] = (void*)
        &random_walk_DWork.DelayInput1_DSTATE_c;
      rtliSetLogXSignalPtrs(random_walk_rtM->rtwLogInfo, (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
    }

    rtliSetLogY(random_walk_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(random_walk_rtM->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(random_walk_rtM->rtwLogInfo, NULL);
  }

  /* external mode info */
  random_walk_rtM->Sizes.checksums[0] = (3841592559U);
  random_walk_rtM->Sizes.checksums[1] = (547910702U);
  random_walk_rtM->Sizes.checksums[2] = (4204012172U);
  random_walk_rtM->Sizes.checksums[3] = (2815468213U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[21];
    random_walk_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = (sysRanDType *)
      &random_walk_DWork.EnabledSubsystem_b.EnabledSubsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &random_walk_DWork.EnabledSubsystem_b1.EnabledSubsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &random_walk_DWork.EnabledSubsystem_f.EnabledSubsystem_SubsysRanBC;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = (sysRanDType *)
      &random_walk_DWork.EnabledSubsystem_by.EnabledSubsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &random_walk_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &random_walk_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, random_walk_rtM->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(random_walk_rtM));
  }

  random_walk_rtM->solverInfoPtr = (&random_walk_rtM->solverInfo);
  random_walk_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&random_walk_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&random_walk_rtM->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  random_walk_rtM->ModelData.blockIO = ((void *) &random_walk_B);
  (void) memset(((void *) &random_walk_B),0,
                sizeof(BlockIO_random_walk));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&random_walk_B.Clock);
    for (i = 0; i < 154; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&random_walk_B.ForIterator);
    for (i = 0; i < 55; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    ((real_T*)&random_walk_B.EnabledSubsystem.In1)[0] = 0.0;
    ((real_T*)&random_walk_B.EnabledSubsystem_by.In1)[0] = 0.0;
    ((real_T*)&random_walk_B.EnabledSubsystem_f.In1)[0] = 0.0;
    ((real_T*)&random_walk_B.EnabledSubsystem_b1.In1)[0] = 0.0;
    ((real_T*)&random_walk_B.EnabledSubsystem_b.In1)[0] = 0.0;
  }

  /* parameters */
  random_walk_rtM->ModelData.defaultParam = ((real_T *) &random_walk_P);

  /* states (dwork) */
  random_walk_rtM->Work.dwork = ((void *) &random_walk_DWork);
  (void) memset((char_T *) &random_walk_DWork,0,
                sizeof(D_Work_random_walk));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &random_walk_DWork.DigitalFilter2_FILT_STATES
      [0];
    for (i = 0; i < 583; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    random_walk_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    random_walk_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  random_walk_InitializeDataMapInfo(random_walk_rtM);

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &random_walk_rtM->NonInlinedSFcns.sfcnInfo;
    random_walk_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(random_walk_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &random_walk_rtM->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(random_walk_rtM));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(random_walk_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(random_walk_rtM));
    rtssSetStepSizePtr(sfcnInfo, &random_walk_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(random_walk_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &random_walk_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &random_walk_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &random_walk_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &random_walk_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &random_walk_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &random_walk_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &random_walk_rtM->solverInfoPtr);
  }

  random_walk_rtM->Sizes.numSFcns = (13);

  /* register each child */
  {
    (void) memset((void *)&random_walk_rtM->NonInlinedSFcns.childSFunctions[0],0,
                  13*sizeof(SimStruct));
    random_walk_rtM->childSfunctions =
      (&random_walk_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 13; i++) {
        random_walk_rtM->childSfunctions[i] =
          (&random_walk_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: random_walk/<S60>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &random_walk_B.xPCTargetTime_a));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "random_walk/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&random_walk_P.xPCTargetTime_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&random_walk_P.xPCTargetTime_P2_Size[0]);
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

    /* Level2 S-Function Block: random_walk/<S60>/PCI-6025E  (donipcie) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.Switch;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &random_walk_B.DataTypeConversion;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts,
                "random_walk/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&random_walk_P.PCI6025E_P1_Size_g[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&random_walk_P.PCI6025E_P2_Size_i[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&random_walk_P.PCI6025E_P3_Size_h[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&random_walk_P.PCI6025E_P4_Size_p[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&random_walk_P.PCI6025E_P5_Size_o[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&random_walk_P.PCI6025E_P6_Size_f[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&random_walk_P.PCI6025E_P7_Size_i[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &random_walk_DWork.PCI6025E_IWORK_d[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &random_walk_rtM->NonInlinedSFcns.Sfcn1.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &random_walk_DWork.PCI6025E_IWORK_d[0]);
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

    /* Level2 S-Function Block: random_walk/<S58>/SerialConverter (serPos) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.ForIterator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = &random_walk_B.Add_j;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn2.UPtrs2;
          sfcnUPtrs[0] = &random_walk_B.Add1_oz;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &random_walk_B.SerialConverter));
        }
      }

      /* path info */
      ssSetModelName(rts, "SerialConverter");
      ssSetPath(rts,
                "random_walk/XY Position Subsystem/For Iterator Subsystem/SerialConverter");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
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
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: random_walk/<S58>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.SerialConverter;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &random_walk_B.ToBits_o1_n));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &random_walk_B.ToBits_o2_f));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &random_walk_B.ToBits_o3_k));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &random_walk_B.ToBits_o4_n));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &random_walk_B.ToBits_o5_f));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &random_walk_B.ToBits_o6_i));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &random_walk_B.ToBits_o7_f));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &random_walk_B.ToBits_o8_d));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts,
                "random_walk/XY Position Subsystem/For Iterator Subsystem/ToBits");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
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

    /* Level2 S-Function Block: random_walk/<S58>/Port B (dopci8255) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o1_n;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o2_f;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn4.UPtrs2;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o3_k;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn4.UPtrs3;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o4_n;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn4.UPtrs4;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o5_f;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn4.UPtrs5;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o6_i;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn4.UPtrs6;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o7_f;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn4.UPtrs7;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o8_d;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port B");
      ssSetPath(rts,
                "random_walk/XY Position Subsystem/For Iterator Subsystem/Port B");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&random_walk_P.PortB_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&random_walk_P.PortB_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&random_walk_P.PortB_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&random_walk_P.PortB_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&random_walk_P.PortB_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&random_walk_P.PortB_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&random_walk_P.PortB_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&random_walk_P.PortB_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&random_walk_P.PortB_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &random_walk_DWork.PortB_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &random_walk_rtM->NonInlinedSFcns.Sfcn4.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &random_walk_DWork.PortB_IWORK[0]);
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

    /* Level2 S-Function Block: random_walk/<S58>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[5]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &random_walk_B.xPCTargetTime));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "random_walk/XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&random_walk_P.xPCTargetTime_P1_Size_j
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&random_walk_P.xPCTargetTime_P2_Size_h
                       [0]);
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

    /* Level2 S-Function Block: random_walk/<S15>/PCI-QUAD04  (enccbcioquadcount) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[6]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &random_walk_B.PCIQUAD04));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 ");
      ssSetPath(rts, "random_walk/XY Position Subsystem/PCI-QUAD04 ");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&random_walk_P.PCIQUAD04_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&random_walk_P.PCIQUAD04_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&random_walk_P.PCIQUAD04_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&random_walk_P.PCIQUAD04_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&random_walk_P.PCIQUAD04_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&random_walk_P.PCIQUAD04_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&random_walk_P.PCIQUAD04_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&random_walk_P.PCIQUAD04_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&random_walk_P.PCIQUAD04_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&random_walk_P.PCIQUAD04_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&random_walk_P.PCIQUAD04_P11_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &random_walk_DWork.PCIQUAD04_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &random_walk_rtM->NonInlinedSFcns.Sfcn6.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &random_walk_DWork.PCIQUAD04_IWORK);
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

    /* Level2 S-Function Block: random_walk/<S15>/PCI-QUAD04 1 (enccbcioquadcount) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[7]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &random_walk_B.PCIQUAD041));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 1");
      ssSetPath(rts, "random_walk/XY Position Subsystem/PCI-QUAD04 1");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&random_walk_P.PCIQUAD041_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&random_walk_P.PCIQUAD041_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&random_walk_P.PCIQUAD041_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&random_walk_P.PCIQUAD041_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&random_walk_P.PCIQUAD041_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&random_walk_P.PCIQUAD041_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&random_walk_P.PCIQUAD041_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&random_walk_P.PCIQUAD041_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&random_walk_P.PCIQUAD041_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&random_walk_P.PCIQUAD041_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&random_walk_P.PCIQUAD041_P11_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &random_walk_DWork.PCIQUAD041_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &random_walk_rtM->NonInlinedSFcns.Sfcn7.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &random_walk_DWork.PCIQUAD041_IWORK);
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

    /* Level2 S-Function Block: random_walk/<Root>/Behavior RW (mastercon_rw) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[8]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.Product1;
          sfcnUPtrs[1] = &random_walk_B.Product;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn8.UPtrs1;
          sfcnUPtrs[0] = random_walk_B.MultiportSwitch;
          sfcnUPtrs[1] = &random_walk_B.MultiportSwitch[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) random_walk_B.BehaviorRW_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 4);
          ssSetOutputPortSignal(rts, 1, ((real_T *) random_walk_B.BehaviorRW_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &random_walk_B.BehaviorRW_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 10);
          ssSetOutputPortSignal(rts, 3, ((real_T *) random_walk_B.BehaviorRW_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &random_walk_B.BehaviorRW_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 2);
          ssSetOutputPortSignal(rts, 5, ((real_T *) random_walk_B.BehaviorRW_o6));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *) &random_walk_DWork.BehaviorRW_DSTATE);

      /* path info */
      ssSetModelName(rts, "Behavior RW");
      ssSetPath(rts, "random_walk/Behavior RW");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&random_walk_P.BehaviorRW_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&random_walk_P.BehaviorRW_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&random_walk_P.BehaviorRW_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&random_walk_P.BehaviorRW_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&random_walk_P.BehaviorRW_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&random_walk_P.BehaviorRW_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&random_walk_P.BehaviorRW_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&random_walk_P.BehaviorRW_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&random_walk_P.BehaviorRW_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&random_walk_P.BehaviorRW_P10_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &random_walk_DWork.BehaviorRW_RWORK[0]);
      ssSetIWork(rts, (int_T *) &random_walk_DWork.BehaviorRW_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &random_walk_rtM->NonInlinedSFcns.Sfcn8.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 3);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 512);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &random_walk_DWork.BehaviorRW_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &random_walk_DWork.BehaviorRW_IWORK[0]);

        /* DSTATE */
        ssSetDWorkWidth(rts, 2, 1);
        ssSetDWorkDataType(rts, 2,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWorkUsedAsDState(rts, 2, 1);
        ssSetDWork(rts, 2, &random_walk_DWork.BehaviorRW_DSTATE);
      }

      /* registration */
      mastercon_rw(rts);
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
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: random_walk/<Root>/PCI-6025E  (danipcie) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[9]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn9.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.RateTransition2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn9.UPtrs1;
          sfcnUPtrs[0] = &random_walk_B.RateTransition1;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts, "random_walk/PCI-6025E ");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&random_walk_P.PCI6025E_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&random_walk_P.PCI6025E_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&random_walk_P.PCI6025E_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&random_walk_P.PCI6025E_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&random_walk_P.PCI6025E_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&random_walk_P.PCI6025E_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&random_walk_P.PCI6025E_P7_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &random_walk_DWork.PCI6025E_RWORK[0]);
      ssSetIWork(rts, (int_T *) &random_walk_DWork.PCI6025E_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &random_walk_rtM->NonInlinedSFcns.Sfcn9.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &random_walk_DWork.PCI6025E_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &random_walk_DWork.PCI6025E_IWORK[0]);
      }

      /* registration */
      danipcie(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: random_walk/<S13>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[10]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[10]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn10.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, random_walk_B.RateTransition);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 112);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "random_walk/UDPXmit/Send");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&random_walk_P.Send_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&random_walk_P.Send_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&random_walk_P.Send_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&random_walk_P.Send_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &random_walk_DWork.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &random_walk_DWork.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &random_walk_rtM->NonInlinedSFcns.Sfcn10.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &random_walk_DWork.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &random_walk_DWork.Send_PWORK);
      }

      /* registration */
      xpcudpbytesend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.02);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 3;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 112);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: random_walk/<S14>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[11]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn11.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.BehaviorRW_o3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &random_walk_B.ToBits_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &random_walk_B.ToBits_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &random_walk_B.ToBits_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &random_walk_B.ToBits_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &random_walk_B.ToBits_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &random_walk_B.ToBits_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &random_walk_B.ToBits_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &random_walk_B.ToBits_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts, "random_walk/WordSbs/ToBits");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
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

    /* Level2 S-Function Block: random_walk/<S14>/Port A (dopci8255) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[12]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[12]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn12.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn12.UPtrs1;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn12.UPtrs2;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn12.UPtrs3;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn12.UPtrs4;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn12.UPtrs5;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn12.UPtrs6;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn12.UPtrs7;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port A");
      ssSetPath(rts, "random_walk/WordSbs/Port A");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&random_walk_P.PortA_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&random_walk_P.PortA_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&random_walk_P.PortA_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&random_walk_P.PortA_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&random_walk_P.PortA_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&random_walk_P.PortA_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&random_walk_P.PortA_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&random_walk_P.PortA_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&random_walk_P.PortA_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &random_walk_DWork.PortA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &random_walk_rtM->NonInlinedSFcns.Sfcn12.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &random_walk_DWork.PortA_IWORK[0]);
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
  }
}

/* Model terminate function */
void random_walk_terminate(void)
{
  /* Level2 S-Function Block: '<S15>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S15>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Behavior RW' (mastercon_rw) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/Port A' (dopci8255) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S15>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S58>/SerialConverter' (serPos) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S58>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S58>/Port B' (dopci8255) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S58>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S58>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S60>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S60>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* External mode */
  rtExtModeShutdown(4);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  random_walk_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  random_walk_update(tid);
}

void MdlInitializeSizes(void)
{
  random_walk_rtM->Sizes.numContStates = (0);/* Number of continuous states */
  random_walk_rtM->Sizes.numY = (0);   /* Number of model outputs */
  random_walk_rtM->Sizes.numU = (0);   /* Number of model inputs */
  random_walk_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  random_walk_rtM->Sizes.numSampTimes = (4);/* Number of sample times */
  random_walk_rtM->Sizes.numBlocks = (334);/* Number of blocks */
  random_walk_rtM->Sizes.numBlockIO = (272);/* Number of block outputs */
  random_walk_rtM->Sizes.numBlockPrms = (435);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Memory: '<S10>/Memory' */
  random_walk_DWork.Memory_PreviousInput = random_walk_P.Memory_X0;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  random_walk_DWork.Memory_PreviousInput_n = random_walk_P.Memory_X0_n;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S7>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &random_walk_DWork.DigitalFilter2_FILT_STATES
      [0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&random_walk_P.DigitalFilter2_ICRTP;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S7>/Derivative' */
  random_walk_DWork.Derivative_RWORK.TimeStampA = rtInf;
  random_walk_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S7>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &random_walk_DWork.DigitalFilter_FILT_STATES[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&random_walk_P.DigitalFilter_ICRTP;
    }

    *statePtr++ = 0.0;
  }

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S8>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *)
      &random_walk_DWork.DigitalFilter2_FILT_STATES_i[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&random_walk_P.DigitalFilter2_ICRTP_p;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S8>/Derivative' */
  random_walk_DWork.Derivative_RWORK_n.TimeStampA = rtInf;
  random_walk_DWork.Derivative_RWORK_n.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S8>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &random_walk_DWork.DigitalFilter_FILT_STATES_a
      [0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&random_walk_P.DigitalFilter_ICRTP_f;
    }

    *statePtr++ = 0.0;
  }

  /* InitializeConditions for Memory: '<S35>/Memory' */
  random_walk_DWork.Memory_PreviousInput_na = random_walk_P.Memory_X0_g;

  /* InitializeConditions for Memory: '<S37>/Memory' */
  random_walk_DWork.Memory_PreviousInput_k = random_walk_P.Memory_X0_p;

  /* InitializeConditions for UnitDelay: '<S49>/Delay Input1' */
  random_walk_DWork.DelayInput1_DSTATE = random_walk_P.DelayInput1_X0;

  /* InitializeConditions for Memory: '<S36>/Memory' */
  random_walk_DWork.Memory_PreviousInput_l = random_walk_P.Memory_X0_np;

  /* InitializeConditions for UnitDelay: '<S32>/Delay Input1' */
  random_walk_DWork.DelayInput1_DSTATE_d = random_walk_P.DelayInput1_X0_m;

  /* InitializeConditions for UnitDelay: '<S33>/Delay Input1' */
  random_walk_DWork.DelayInput1_DSTATE_c = random_walk_P.DelayInput1_X0_f;

  /* InitializeConditions for Memory: '<S34>/Memory' */
  random_walk_DWork.Memory_PreviousInput_d = random_walk_P.Memory_X0_l;

  /* InitializeConditions for UnitDelay: '<S25>/x' */
  random_walk_DWork.x_DSTATE = random_walk_P.x_X0;

  /* InitializeConditions for UnitDelay: '<S26>/x' */
  random_walk_DWork.x_DSTATE_m = random_walk_P.x_X0_f;

  /* InitializeConditions for UnitDelay: '<S27>/x' */
  random_walk_DWork.x_DSTATE_d = random_walk_P.x_X0_fi;

  /* InitializeConditions for UnitDelay: '<S28>/x' */
  random_walk_DWork.x_DSTATE_k = random_walk_P.x_X0_i;

  /* Level2 S-Function Block: '<Root>/Behavior RW' (mastercon_rw) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[8];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* InitializeConditions for UnitDelay: '<S25>/y' */
  random_walk_DWork.y_DSTATE = random_walk_P.y_X0;

  /* InitializeConditions for UnitDelay: '<S25>/z' */
  random_walk_DWork.z_DSTATE = random_walk_P.z_X0;

  /* InitializeConditions for UnitDelay: '<S26>/y' */
  random_walk_DWork.y_DSTATE_k = random_walk_P.y_X0_l;

  /* InitializeConditions for UnitDelay: '<S26>/z' */
  random_walk_DWork.z_DSTATE_f = random_walk_P.z_X0_j;

  /* InitializeConditions for UnitDelay: '<S27>/y' */
  random_walk_DWork.y_DSTATE_n = random_walk_P.y_X0_p;

  /* InitializeConditions for UnitDelay: '<S27>/z' */
  random_walk_DWork.z_DSTATE_d = random_walk_P.z_X0_l;

  /* InitializeConditions for UnitDelay: '<S28>/y' */
  random_walk_DWork.y_DSTATE_d = random_walk_P.y_X0_lz;

  /* InitializeConditions for UnitDelay: '<S28>/z' */
  random_walk_DWork.z_DSTATE_dv = random_walk_P.z_X0_g;

  /* InitializeConditions for Memory: '<S9>/Memory1' */
  random_walk_DWork.Memory1_PreviousInput = random_walk_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S52>/Memory' */
  random_walk_DWork.Memory_PreviousInput_a = random_walk_P.Memory_X0_pd;
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S15>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S15>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<Root>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S11>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior RW/p2/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior RW/p2/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior RW/p2/s3"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior RW/p2/s4"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior RW/p2/s1"),
          "%3.0f%3.2f%1.0f%1.0f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior RW/p2/s2"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior RW/p2/s3"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior RW/p2/s4"),
          "%15.6f");
        rl32eSetScope(3, 4, 10);
        rl32eSetScope(3, 40, 0);
        rl32eSetScope(3, 7, 10);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Behavior RW/p2/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 10, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, -10.0);
        rl32eSetTargetScope(3, 10, 10.0);
        xpceScopeAcqOK(3, &random_walk_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Level2 S-Function Block: '<S13>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S14>/Port A' (dopci8255) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S16>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo(
          "XY Position Subsystem/Cursor Rotation/Product1"));
        rl32eAddSignal(1, rl32eGetSignalNo(
          "XY Position Subsystem/Cursor Rotation/Product"));
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo(
          "XY Position Subsystem/Cursor Rotation/Product1"),"%15.2f%15.2f");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo(
          "XY Position Subsystem/Cursor Rotation/Product"),"%15.6f");
        rl32eSetScope(1, 4, 10);
        rl32eSetScope(1, 40, 0);
        rl32eSetScope(1, 7, 10);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo(
          "XY Position Subsystem/Cursor Rotation/Product1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 10, 0);
        rl32eSetTargetScope(1, 1, 0.0);
        rl32eSetTargetScope(1, 11, -10.0);
        rl32eSetTargetScope(1, 10, 10.0);
        xpceScopeAcqOK(1, &random_walk_DWork.SFunction_IWORK_c.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S17>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,2)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo("Matrix Concatenation/s1"));
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Matrix Concatenation/s1"),
          "%15.2f%15.2f");
        rl32eSetScope(5, 4, 10);
        rl32eSetScope(5, 40, 0);
        rl32eSetScope(5, 7, 10);
        rl32eSetScope(5, 0, 0);
        rl32eSetScope(5, 3, rl32eGetSignalNo("Matrix Concatenation/s1"));
        rl32eSetScope(5, 1, 0.0);
        rl32eSetScope(5, 2, 0);
        rl32eSetScope(5, 10, 0);
        rl32eSetTargetScope(5, 1, 0.0);
        rl32eSetTargetScope(5, 11, -10.0);
        rl32eSetTargetScope(5, 10, 10.0);
        xpceScopeAcqOK(5, &random_walk_DWork.SFunction_IWORK_e.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /* S-Function Block: <S18>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Behavior RW/p6/s1"));
        rl32eAddSignal(2, rl32eGetSignalNo("Behavior RW/p6/s2"));
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("Behavior RW/p6/s1"),
          "%15.2f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("Behavior RW/p6/s2"),
          "%15.6f");
        rl32eSetScope(2, 4, 10);
        rl32eSetScope(2, 40, 0);
        rl32eSetScope(2, 7, 10);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Behavior RW/p6/s1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 10, 0);
        rl32eSetTargetScope(2, 1, 0.0);
        rl32eSetTargetScope(2, 11, -10.0);
        rl32eSetTargetScope(2, 10, 10.0);
        xpceScopeAcqOK(2, &random_walk_DWork.SFunction_IWORK_o.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S19>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior RW/p1/s1"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior RW/p1/s2"));
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior RW/p1/s1"),"%2.2f");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior RW/p1/s2"),
          "%15.6f");
        rl32eSetScope(7, 4, 7);
        rl32eSetScope(7, 40, 0);
        rl32eSetScope(7, 7, 1);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("Behavior RW/p1/s1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 10, 0);
        rl32eSetTargetScope(7, 1, 0.0);
        rl32eSetTargetScope(7, 11, 0.0);
        rl32eSetTargetScope(7, 10, 0.0);
        xpceScopeAcqOK(7, &random_walk_DWork.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* S-Function Block: <S20>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("Behavior RW/p4/s1"));
        rl32eAddSignal(4, rl32eGetSignalNo("Target Peek/Gain"));
        rl32eAddSignal(4, rl32eGetSignalNo("Target Peek/Gain1"));
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Behavior RW/p4/s1"),
          "%d%2.2f%2.2f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Target Peek/Gain"),"%15.6f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Target Peek/Gain1"),
          "%15.6f");
        rl32eSetScope(4, 4, 7);
        rl32eSetScope(4, 40, 0);
        rl32eSetScope(4, 7, 1);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("Behavior RW/p4/s1"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 10, 0);
        rl32eSetTargetScope(4, 1, 0.0);
        rl32eSetTargetScope(4, 11, 0.0);
        rl32eSetTargetScope(4, 10, 0.0);
        xpceScopeAcqOK(4, &random_walk_DWork.SFunction_IWORK_d.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* S-Function Block: <S23>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(10)) == 0) {
      if ((i = rl32eDefScope(10,2)) != 0) {
        printf("Error creating scope 10\n");
      } else {
        rl32eAddSignal(10, rl32eGetSignalNo("Force Generator/LorentzForce/Add1"));
        rl32eSetScope(10, 4, 200);
        rl32eSetScope(10, 40, 0);
        rl32eSetScope(10, 7, 10);
        rl32eSetScope(10, 0, 0);
        rl32eSetScope(10, 3, rl32eGetSignalNo(
          "Force Generator/LorentzForce/Add1"));
        rl32eSetScope(10, 1, 0.0);
        rl32eSetScope(10, 2, 0);
        rl32eSetScope(10, 10, 0);
        rl32eSetTargetScope(10, 1, 3.0);
        rl32eSetTargetScope(10, 3, 0.0);
        rl32eSetTargetScope(10, 11, -30.0);
        rl32eSetTargetScope(10, 10, 30.0);
        xpceScopeAcqOK(10, &random_walk_DWork.SFunction_IWORK_k.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(10);
    }
  }

  /* S-Function Block: <S24>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(9)) == 0) {
      if ((i = rl32eDefScope(9,2)) != 0) {
        printf("Error creating scope 9\n");
      } else {
        rl32eAddSignal(9, rl32eGetSignalNo("Force Generator/LorentzForce/Add"));
        rl32eSetScope(9, 4, 200);
        rl32eSetScope(9, 40, 0);
        rl32eSetScope(9, 7, 10);
        rl32eSetScope(9, 0, 0);
        rl32eSetScope(9, 3, rl32eGetSignalNo("Force Generator/LorentzForce/Add"));
        rl32eSetScope(9, 1, 0.0);
        rl32eSetScope(9, 2, 0);
        rl32eSetScope(9, 10, 0);
        rl32eSetTargetScope(9, 1, 3.0);
        rl32eSetTargetScope(9, 11, -30.0);
        rl32eSetTargetScope(9, 10, 30.0);
        xpceScopeAcqOK(9, &random_walk_DWork.SFunction_IWORK_p.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(9);
    }
  }

  /* Start for iterator system: '<S15>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S58>/Port B' (dopci8255) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Start for iterator system: '<S58>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S60>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  random_walk_DWork.EnabledSubsystem_b.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  random_walk_DWork.EnabledSubsystem_b1.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  random_walk_DWork.EnabledSubsystem_f.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  random_walk_DWork.EnabledSubsystem_by.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  random_walk_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;

  /* user code (Start function Trailer) */
  rl32eSetScope(3, 8, 1);
  rl32eSetScope(1, 8, 1);
  rl32eSetScope(5, 8, 1);
  rl32eSetScope(2, 8, 1);
  rl32eSetScope(7, 8, 1);
  rl32eSetScope(4, 8, 1);
  rl32eSetScope(10, 8, 1);
  rl32eSetScope(9, 8, 1);
  MdlInitialize();
}

rtModel_random_walk *random_walk(void)
{
  random_walk_initialize(1);
  return random_walk_rtM;
}

void MdlTerminate(void)
{
  random_walk_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
