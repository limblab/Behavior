/*
 * forced_choice.c
 *
 * Real-Time Workshop code generation for Simulink model "forced_choice.mdl".
 *
 * Model Version              : 1.747
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Mon Dec 17 17:05:06 2007
 */

#include "rt_logging_mmi.h"
#include "forced_choice_capi.h"
#include "forced_choice.h"
#include "forced_choice_private.h"
#include <stdio.h>
#include "forced_choice_dt.h"

/* Block signals (auto storage) */
BlockIO_forced_choice forced_choice_B;

/* Block states (auto storage) */
D_Work_forced_choice forced_choice_DWork;

/* Real-time model */
rtModel_forced_choice forced_choice_rtM_;
rtModel_forced_choice *forced_choice_rtM = &forced_choice_rtM_;
static void rate_monotonic_scheduler(void);

/* Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void forced_choice_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(forced_choice_rtM, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(forced_choice_rtM, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(forced_choice_rtM, 3));
}

time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(forced_choice_rtM, 1);
  rtmSampleHitPtr[2] = rtmStepTask(forced_choice_rtM, 2);
  rtmSampleHitPtr[3] = rtmStepTask(forced_choice_rtM, 3);
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
  if (forced_choice_rtM->Timing.TaskCounters.TID[1] == 0) {
    forced_choice_rtM->Timing.RateInteraction.TID1_2 =
      (forced_choice_rtM->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    forced_choice_rtM->Timing.perTaskSampleHits[6] =
      forced_choice_rtM->Timing.RateInteraction.TID1_2;
    forced_choice_rtM->Timing.RateInteraction.TID1_3 =
      (forced_choice_rtM->Timing.TaskCounters.TID[3] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    forced_choice_rtM->Timing.perTaskSampleHits[7] =
      forced_choice_rtM->Timing.RateInteraction.TID1_3;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++forced_choice_rtM->Timing.TaskCounters.TID[2] == 10) {/* Sample time: [0.01s, 0.0s] */
    forced_choice_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  forced_choice_rtM->Timing.sampleHits[2] =
    (forced_choice_rtM->Timing.TaskCounters.TID[2] == 0);
  if (++forced_choice_rtM->Timing.TaskCounters.TID[3] == 20) {/* Sample time: [0.02s, 0.0s] */
    forced_choice_rtM->Timing.TaskCounters.TID[3] = 0;
  }

  forced_choice_rtM->Timing.sampleHits[3] =
    (forced_choice_rtM->Timing.TaskCounters.TID[3] == 0);
}

/* Disable for enable system:
 *   '<S28>/Enabled Subsystem'
 *   '<S9>/Enabled Subsystem'
 */
void forced_EnabledSubsystem_Disable(rtDW_EnabledSubsystem_forced_ch *localDW)
{
  /* DisableFcn of enable SubSystem Block: '<S28>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE = (int_T) SUBSYS_DISABLED;
}

/* Output and update for enable system:
 *   '<S28>/Enabled Subsystem'
 *   '<S9>/Enabled Subsystem'
 */
void forced_choice_EnabledSubsystem(int_T tid, boolean_T rtu_0, real_T rtu_1,
  rtB_EnabledSubsystem_forced_cho *localB, rtDW_EnabledSubsystem_forced_ch
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
        forced_EnabledSubsystem_Disable(localDW);
      }
    }
  }

  /* run blocks if enabled */
  if (localDW->EnabledSubsystem_MODE == SUBSYS_ENABLED) {
    if (tid == 0 || tid == 0) {
      if (tid == 0) {
        /* Inport: '<S30>/In1' */
        localB->In1 = rtu_1;
      }

      srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC);
    }
  }
}

/* Model output function */
void forced_choice_output(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  if (tid == 0) {
    srClearBC
      (forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_SubsysRanBC);
    srClearBC(forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S9>/Clock'
     */
    forced_choice_B.Clock = forced_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S9>/Memory' */
    forced_choice_B.Memory = forced_choice_DWork.Memory_PreviousInput;

    /* Memory: '<Root>/Memory' */
    forced_choice_B.Memory_o = forced_choice_DWork.Memory_PreviousInput_a;

    /* Logic: '<S9>/Logical Operator2' */
    forced_choice_B.LogicalOperator2 = (forced_choice_B.Memory ||
      forced_choice_B.Memory_o);

    /* Logic: '<S9>/Logical Operator1' */
    forced_choice_B.LogicalOperator1 = !forced_choice_B.LogicalOperator2;

    /* SignalConversion: '<S9>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    forced_choice_B.HiddenBuf_InsertedFor_EnabledSu =
      forced_choice_B.LogicalOperator1;
  }

  /* SubSystem Block: '<S9>/Enabled Subsystem'
   */
  forced_choice_EnabledSubsystem(tid,
    forced_choice_B.HiddenBuf_InsertedFor_EnabledSu, forced_choice_B.Clock,
    &forced_choice_B.EnabledSubsystem, &forced_choice_DWork.EnabledSubsystem);
  if (tid == 0) {
    /* Sum: '<S9>/Sum' */
    forced_choice_B.Sum = forced_choice_B.Clock -
      forced_choice_B.EnabledSubsystem.In1;

    /* RelationalOperator: '<S31>/Compare' */
    forced_choice_B.Compare = (forced_choice_B.Sum > 0.0);

    /* RelationalOperator: '<S9>/Relational Operator' incorporates:
     *  Constant: '<S9>/Time'
     */
    forced_choice_B.RelationalOperator = (forced_choice_B.Sum >
      forced_choice_P.Time_Value);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S9>/Logical Operator' */
    forced_choice_B.LogicalOperator = (boolean_T)((forced_choice_B.Compare != 0U)
      ^ forced_choice_B.RelationalOperator);

    /* Level2 S-Function Block: '<S14>/PCI-QUAD04 ' (enccbcioquadcount) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S14>/Gain' */
    forced_choice_B.Gain = forced_choice_P.Gain_Gain * forced_choice_B.PCIQUAD04;

    /* Sum: '<S14>/Sum3' incorporates:
     *  Constant: '<S14>/shoulderOffset'
     */
    forced_choice_B.Sum3 = forced_choice_B.Gain +
      forced_choice_P.shoulderOffset_Value;

    /* Fcn: '<S35>/sin(length of Shoulder)' */
    forced_choice_B.sinlengthofShoulder = 25.0 * cos(forced_choice_B.Sum3);

    /* Level2 S-Function Block: '<S14>/PCI-QUAD04 1' (enccbcioquadcount) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    {
      real_T tmp;
      real_T tmp_0;

      /* Gain: '<S14>/Gain1' */
      forced_choice_B.Gain1 = forced_choice_P.Gain1_Gain *
        forced_choice_B.PCIQUAD041;

      /* Sum: '<S14>/Sum1' incorporates:
       *  Constant: '<S14>/elbowOffset'
       */
      forced_choice_B.Sum1 = forced_choice_B.Gain1 +
        forced_choice_P.elbowOffset_Value;

      /* Fcn: '<S35>/sin(length of Elbow)' */
      forced_choice_B.sinlengthofElbow = 26.800000000000001 * sin
        (forced_choice_B.Sum1);

      /* Sum: '<S35>/Sum2' */
      forced_choice_B.Sum2 = (0.0 - forced_choice_B.sinlengthofShoulder) -
        forced_choice_B.sinlengthofElbow;

      /* Sum: '<S35>/Sum4' incorporates:
       *  Constant: '<S35>/yoffset'
       */
      forced_choice_B.Sum4 = forced_choice_B.Sum2 +
        forced_choice_P.yoffset_Value;

      /* Fcn: '<S35>/cos(length of Shoulder)' */
      forced_choice_B.coslengthofShoulder = 25.0 * sin(forced_choice_B.Sum3);

      /* Fcn: '<S35>/cos(length of Elbow)' */
      forced_choice_B.coslengthofElbow = 26.800000000000001 * cos
        (forced_choice_B.Sum1);

      /* Sum: '<S35>/Sum3' */
      forced_choice_B.Sum3_n = forced_choice_B.coslengthofElbow -
        forced_choice_B.coslengthofShoulder;

      /* Sum: '<S35>/Sum1' incorporates:
       *  Constant: '<S35>/xoffset'
       */
      forced_choice_B.Sum1_a = forced_choice_B.Sum3_n +
        forced_choice_P.xoffset_Value;

      /* Trigonometry: '<S33>/Trigonometric Function1' */
      forced_choice_B.TrigonometricFunction1 = rt_atan2(forced_choice_B.Sum4,
        forced_choice_B.Sum1_a);

      /* Sum: '<S33>/Sum' incorporates:
       *  Constant: '<S33>/AngleOffset'
       */
      forced_choice_B.Sum_f = forced_choice_B.TrigonometricFunction1 +
        forced_choice_P.AngleOffset_Value;

      /* Trigonometry: '<S33>/Trigonometric Function2' */
      forced_choice_B.TrigonometricFunction2 = cos(forced_choice_B.Sum_f);

      /* Fcn: '<S33>/sqrt(u[1]*u[1] + u[2]*u[2])' */
      tmp = forced_choice_B.Sum4;
      tmp_0 = forced_choice_B.Sum1_a;
      forced_choice_B.sqrtu1u1u2u2 = sqrt(tmp * tmp + tmp_0 * tmp_0);

      /* Product: '<S33>/Product1' */
      forced_choice_B.Product1 = forced_choice_B.TrigonometricFunction2 *
        forced_choice_B.sqrtu1u1u2u2;
    }

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S6>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&forced_choice_B.Product1, &forced_choice_B.DigitalFilter2,
                    &forced_choice_DWork.DigitalFilter2_FILT_STATES[0],
                    &forced_choice_DWork.DigitalFilter2_CIRCBUFFIDX, 11, 1, 1,
                    &forced_choice_P.DigitalFilter2_RTP1COEFF[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S6>/Derivative' */
    {
      real_T t = forced_choice_rtM->Timing.t[0];
      real_T timeStampA = forced_choice_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = forced_choice_DWork.Derivative_RWORK.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        forced_choice_B.Derivative = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &forced_choice_DWork.Derivative_RWORK.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        forced_choice_B.Derivative = (forced_choice_B.DigitalFilter2 - *lastBank
          ++) / deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S6>/dG' */
    forced_choice_B.dG = forced_choice_P.dG_Gain * forced_choice_B.Derivative;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S6>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&forced_choice_B.dG, &forced_choice_B.DigitalFilter,
                    &forced_choice_DWork.DigitalFilter_FILT_STATES[0],
                    &forced_choice_DWork.DigitalFilter_CIRCBUFFIDX, 11, 1, 1,
                    &forced_choice_P.DigitalFilter_RTP1COEFF[0], 1);

    /* Trigonometry: '<S33>/Trigonometric Function' */
    forced_choice_B.TrigonometricFunction = sin(forced_choice_B.Sum_f);

    /* Product: '<S33>/Product' */
    forced_choice_B.Product = forced_choice_B.sqrtu1u1u2u2 *
      forced_choice_B.TrigonometricFunction;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S7>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&forced_choice_B.Product, &forced_choice_B.DigitalFilter2_d,
                    &forced_choice_DWork.DigitalFilter2_FILT_STATES_c[0],
                    &forced_choice_DWork.DigitalFilter2_CIRCBUFFIDX_p, 11, 1, 1,
                    &forced_choice_P.DigitalFilter2_RTP1COEFF_a[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S7>/Derivative' */
    {
      real_T t = forced_choice_rtM->Timing.t[0];
      real_T timeStampA = forced_choice_DWork.Derivative_RWORK_p.TimeStampA;
      real_T timeStampB = forced_choice_DWork.Derivative_RWORK_p.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        forced_choice_B.Derivative_l = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &forced_choice_DWork.Derivative_RWORK_p.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        forced_choice_B.Derivative_l = (forced_choice_B.DigitalFilter2_d -
          *lastBank++) / deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S7>/dG' */
    forced_choice_B.dG_k = forced_choice_P.dG_Gain_b *
      forced_choice_B.Derivative_l;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S7>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&forced_choice_B.dG_k, &forced_choice_B.DigitalFilter_g,
                    &forced_choice_DWork.DigitalFilter_FILT_STATES_p[0],
                    &forced_choice_DWork.DigitalFilter_CIRCBUFFIDX_b, 11, 1, 1,
                    &forced_choice_P.DigitalFilter_RTP1COEFF_n[0], 1);

    {
      real_T tmp;
      real_T tmp_0;
      real_T tmp_1;
      real_T tmp_2;
      real_T tmp_3;
      real_T tmp_4;
      real_T tmp_5;
      real_T tmp_6;

      /* RelationalOperator: '<S1>/Relational Operator' incorporates:
       *  Constant: '<S1>/XLowLimit'
       */
      forced_choice_B.RelationalOperator_o = (forced_choice_B.Sum3_n <
        forced_choice_P.XLowLimit_Value);

      /* RelationalOperator: '<S1>/Relational Operator1' incorporates:
       *  Constant: '<S1>/XHighLimit'
       */
      forced_choice_B.RelationalOperator1 = (forced_choice_B.Sum3_n >
        forced_choice_P.XHighLimit_Value);

      /* RelationalOperator: '<S1>/Relational Operator2' incorporates:
       *  Constant: '<S1>/YHighLimit'
       */
      forced_choice_B.RelationalOperator2 = (forced_choice_B.Sum2 <
        forced_choice_P.YHighLimit_Value);

      /* RelationalOperator: '<S1>/Relational Operator3' incorporates:
       *  Constant: '<S1>/YLowLimit'
       */
      forced_choice_B.RelationalOperator3 = (forced_choice_B.Sum2 >
        forced_choice_P.YLowLimit_Value);

      /* Logic: '<S1>/Logical Operator' */
      forced_choice_B.LogicalOperator_h = (forced_choice_B.RelationalOperator_o ||
        forced_choice_B.RelationalOperator1 ||
        forced_choice_B.RelationalOperator2 ||
        forced_choice_B.RelationalOperator3);

      /* UnitDelay: '<S24>/x' */
      forced_choice_B.x = forced_choice_DWork.x_DSTATE;

      /* UnitDelay: '<S25>/x' */
      forced_choice_B.x_h = forced_choice_DWork.x_DSTATE_h;

      /* Sum: '<S20>/Add' */
      forced_choice_B.Add = forced_choice_B.x - forced_choice_B.x_h;

      /* UnitDelay: '<S26>/x' */
      forced_choice_B.x_m = forced_choice_DWork.x_DSTATE_g;

      /* UnitDelay: '<S27>/x' */
      forced_choice_B.x_ho = forced_choice_DWork.x_DSTATE_e;

      /* Sum: '<S20>/Add1' */
      forced_choice_B.Add1 = forced_choice_B.x_m - forced_choice_B.x_ho;

      /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
       *  Constant: '<S4>/Load'
       *  Constant: '<S4>/Off'
       *  Constant: '<S4>/staticX'
       *  Constant: '<S4>/staticY'
       */
      switch ((int32_T)forced_choice_P.Load_Value) {
       case 0:
        tmp = forced_choice_P.Off_Value;
        tmp_0 = forced_choice_P.Off_Value;
        forced_choice_B.MultiportSwitch[0] = tmp;
        forced_choice_B.MultiportSwitch[1] = tmp_0;
        break;

       case 1:
        tmp_1 = forced_choice_P.staticX_Value;
        tmp_2 = forced_choice_P.staticY_Value;
        forced_choice_B.MultiportSwitch[0] = tmp_1;
        forced_choice_B.MultiportSwitch[1] = tmp_2;
        break;

       case 2:
        /* Gain: '<S4>/LorentzForceGain' */
        tmp_3 = forced_choice_B.Add;
        tmp_4 = forced_choice_B.Add1;
        forced_choice_B.LorentzForceGain[0] =
          forced_choice_P.LorentzForceGain_Gain * tmp_3;
        forced_choice_B.LorentzForceGain[1] =
          forced_choice_P.LorentzForceGain_Gain * tmp_4;
        forced_choice_B.MultiportSwitch[0] = forced_choice_B.LorentzForceGain[0];
        forced_choice_B.MultiportSwitch[1] = forced_choice_B.LorentzForceGain[1];
        break;

       default:
        /* MultiPortSwitch: '<S4>/dynamicAngle Switch' incorporates:
         *  Constant: '<S4>/DynamicAngle'
         *  Constant: '<S4>/visAngle'
         */
        if ((int32_T)forced_choice_P.DynamicAngle_Value == 0) {
          forced_choice_B.dynamicAngleSwitch = forced_choice_P.visAngle_Value;
        } else {
          /* Gain: '<S4>/Gain' */
          forced_choice_B.Gain_e = forced_choice_P.Gain_Gain_d *
            forced_choice_B.Add;
          forced_choice_B.dynamicAngleSwitch = forced_choice_B.Gain_e;
        }

        /* Trigonometry: '<S21>/sin' */
        forced_choice_B.sin_c = sin(forced_choice_B.dynamicAngleSwitch);

        /* Product: '<S21>/Product3' */
        forced_choice_B.Product3_g = forced_choice_B.DigitalFilter *
          forced_choice_B.sin_c;

        /* Trigonometry: '<S21>/cos' */
        forced_choice_B.cos_n = cos(forced_choice_B.dynamicAngleSwitch);

        /* Product: '<S21>/Product2' */
        forced_choice_B.Product2_p = forced_choice_B.DigitalFilter_g *
          forced_choice_B.cos_n;

        /* Sum: '<S21>/Subtract' */
        forced_choice_B.Subtract_b = forced_choice_B.Product2_p -
          forced_choice_B.Product3_g;

        /* Product: '<S21>/Product1' */
        forced_choice_B.Product1_h = forced_choice_B.DigitalFilter_g *
          forced_choice_B.sin_c;

        /* Product: '<S21>/Product' */
        forced_choice_B.Product_h = forced_choice_B.DigitalFilter *
          forced_choice_B.cos_n;

        /* Sum: '<S21>/Add' */
        forced_choice_B.Add_f = forced_choice_B.Product_h +
          forced_choice_B.Product1_h;

        /* Gain: '<S21>/Gain' */
        tmp_5 = forced_choice_B.Add_f;
        tmp_6 = forced_choice_B.Subtract_b;
        forced_choice_B.Gain_l[0] = forced_choice_P.Gain_Gain_m * tmp_5;
        forced_choice_B.Gain_l[1] = forced_choice_P.Gain_Gain_m * tmp_6;
        forced_choice_B.MultiportSwitch[0] = forced_choice_B.Gain_l[0];
        forced_choice_B.MultiportSwitch[1] = forced_choice_B.Gain_l[1];
        break;
      }
    }

    /* Level2 S-Function Block: '<Root>/Behavior FC' (mastercon_fc) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }
  }

  {
    real_T cg_in;
    real_T cg_in_0;
    real_T cg_in_1;
    real_T cg_in_2;
    real_T tmp;
    real_T tmp_0;
    real_T tmp_1;
    real_T tmp_2;
    if (tid == 0) {
      /* Switch: '<Root>/Switch1' incorporates:
       *  Constant: '<Root>/zeroX'
       *  Constant: '<Root>/zeroY'
       */
      if (forced_choice_B.LogicalOperator) {
        tmp = forced_choice_P.zeroX_Value;
        tmp_0 = forced_choice_P.zeroY_Value;
        forced_choice_B.Switch1[0] = tmp;
        forced_choice_B.Switch1[1] = tmp_0;
      } else {
        /* Switch: '<Root>/Switch' */
        if (forced_choice_B.LogicalOperator_h) {
          tmp_1 = forced_choice_B.DigitalFilter;
          tmp_2 = forced_choice_B.DigitalFilter_g;
          forced_choice_B.Switch_d[0] = tmp_1;
          forced_choice_B.Switch_d[1] = tmp_2;
        } else {
          forced_choice_B.Switch_d[0] = forced_choice_B.BehaviorFC_o1[0];
          forced_choice_B.Switch_d[1] = forced_choice_B.BehaviorFC_o1[1];
        }

        forced_choice_B.Switch1[0] = forced_choice_B.Switch_d[0];
        forced_choice_B.Switch1[1] = forced_choice_B.Switch_d[1];
      }

      /* Outputs for atomic SubSystem: '<Root>/Force//Torque Transform' */

      /* Fcn: '<S5>/sin(length of Shoulder)' */
      forced_choice_B.sinlengthofShoulder_e = 25.0 * cos(forced_choice_B.Sum3);

      /* Product: '<S5>/Product' */
      cg_in = forced_choice_B.Switch1[0];
      forced_choice_B.Product_k = cg_in * forced_choice_B.sinlengthofShoulder_e;

      /* Fcn: '<S5>/cos(length of Shoulder)' */
      forced_choice_B.coslengthofShoulder_m = 25.0 * sin(forced_choice_B.Sum3);

      /* Product: '<S5>/Product1' */
      cg_in_0 = forced_choice_B.Switch1[1];
      forced_choice_B.Product1_a = cg_in_0 *
        forced_choice_B.coslengthofShoulder_m;

      /* Fcn: '<S5>/sin(length of Elbow)' */
      forced_choice_B.sinlengthofElbow_j = 26.800000000000001 * sin
        (forced_choice_B.Sum1);

      /* Product: '<S5>/Product2' */
      cg_in_1 = forced_choice_B.Switch1[0];
      forced_choice_B.Product2 = cg_in_1 * forced_choice_B.sinlengthofElbow_j;

      /* Fcn: '<S5>/cos(length of Elbow)' */
      forced_choice_B.coslengthofElbow_j = 26.800000000000001 * cos
        (forced_choice_B.Sum1);

      /* Product: '<S5>/Product3' */
      cg_in_2 = forced_choice_B.Switch1[1];
      forced_choice_B.Product3 = cg_in_2 * forced_choice_B.coslengthofElbow_j;

      /* Sum: '<S5>/Sum5' */
      forced_choice_B.Sum5 = forced_choice_B.Product1_a -
        forced_choice_B.Product_k;

      /* Sum: '<S5>/Sum6' */
      forced_choice_B.Sum6 = (0.0 - forced_choice_B.Product2) -
        forced_choice_B.Product3;

      /* end of Outputs for SubSystem: '<Root>/Force//Torque Transform' */

      /* Gain: '<Root>/MG2' */
      forced_choice_B.MG2 = forced_choice_P.MG2_Gain * forced_choice_B.Sum6;
    }

    /* RateTransition: '<Root>/Rate Transition2' */
    if (tid == 0 && forced_choice_rtM->Timing.RateInteraction.TID1_2) {
      forced_choice_B.RateTransition2 = forced_choice_B.MG2;
    }

    if (tid == 0) {
      /* Gain: '<Root>/MG1' */
      forced_choice_B.MG1 = forced_choice_P.MG1_Gain * forced_choice_B.Sum5;
    }

    /* RateTransition: '<Root>/Rate Transition1' */
    if (tid == 0 && forced_choice_rtM->Timing.RateInteraction.TID1_2) {
      forced_choice_B.RateTransition1 = forced_choice_B.MG1;
    }
  }

  if (tid == 2) {                      /* Sample time: [0.01s, 0.0s] */
    /* Level2 S-Function Block: '<Root>/PCI-6025E ' (danipcie) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[9];
      sfcnOutputs(rts, 2);
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* ok to acquire for <S10>/S-Function */
    forced_choice_DWork.SFunction_IWORK.AcquireOK = 1;

    /* Pack: <S12>/Pack */
    (void) memcpy(forced_choice_B.Pack,&forced_choice_B.Product1,
                  8);
    (void) memcpy(&forced_choice_B.Pack[8],&forced_choice_B.Product,
                  8);
    (void) memcpy(&forced_choice_B.Pack[16],&forced_choice_B.BehaviorFC_o4[0],
                  8);
    (void) memcpy(&forced_choice_B.Pack[24],&forced_choice_B.BehaviorFC_o4[1],
                  8);
    (void) memcpy(&forced_choice_B.Pack[32],&forced_choice_B.BehaviorFC_o4[2],
                  8);
    (void) memcpy(&forced_choice_B.Pack[40],&forced_choice_B.BehaviorFC_o4[3],
                  8);
    (void) memcpy(&forced_choice_B.Pack[48],&forced_choice_B.BehaviorFC_o4[4],
                  8);
    (void) memcpy(&forced_choice_B.Pack[56],&forced_choice_B.BehaviorFC_o4[5],
                  8);
    (void) memcpy(&forced_choice_B.Pack[64],&forced_choice_B.BehaviorFC_o4[6],
                  8);
    (void) memcpy(&forced_choice_B.Pack[72],&forced_choice_B.BehaviorFC_o4[7],
                  8);
    (void) memcpy(&forced_choice_B.Pack[80],&forced_choice_B.BehaviorFC_o4[8],
                  8);
    (void) memcpy(&forced_choice_B.Pack[88],&forced_choice_B.BehaviorFC_o4[9],
                  8);
    (void) memcpy(&forced_choice_B.Pack[96],&forced_choice_B.BehaviorFC_o6[0],
                  8);
    (void) memcpy(&forced_choice_B.Pack[104],&forced_choice_B.BehaviorFC_o6[1],
                  8);
  }

  {
    int32_T i;

    /* RateTransition: '<S12>/Rate Transition' */
    if (tid == 0 && forced_choice_rtM->Timing.RateInteraction.TID1_3) {
      for (i = 0; i < 112; i++) {
        forced_choice_B.RateTransition[i] = forced_choice_B.Pack[i];
      }
    }
  }

  if (tid == 3) {                      /* Sample time: [0.02s, 0.0s] */
    /* Level2 S-Function Block: '<S12>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[10];
      sfcnOutputs(rts, 3);
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Level2 S-Function Block: '<S13>/ToBits' (Byte2Bits) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[11];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S13>/Port A' (dopci8255) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[12];
      sfcnOutputs(rts, 1);
    }

    /* ok to acquire for <S15>/S-Function */
    forced_choice_DWork.SFunction_IWORK_i.AcquireOK = 1;

    /* ok to acquire for <S16>/S-Function */
    forced_choice_DWork.SFunction_IWORK_a.AcquireOK = 1;

    /* ok to acquire for <S17>/S-Function */
    forced_choice_DWork.SFunction_IWORK_d.AcquireOK = 1;

    /* ok to acquire for <S18>/S-Function */
    forced_choice_DWork.SFunction_IWORK_h.AcquireOK = 1;

    /* ok to acquire for <S19>/S-Function */
    forced_choice_DWork.SFunction_IWORK_ie.AcquireOK = 1;

    /* ok to acquire for <S22>/S-Function */
    forced_choice_DWork.SFunction_IWORK_b.AcquireOK = 1;

    /* ok to acquire for <S23>/S-Function */
    forced_choice_DWork.SFunction_IWORK_g.AcquireOK = 1;

    {
      int32_T s34_iter;

      /* UnitDelay: '<S24>/y' */
      forced_choice_B.y = forced_choice_DWork.y_DSTATE;

      /* Sum: '<S24>/Add1' */
      forced_choice_B.Add1_o = forced_choice_B.y - forced_choice_B.x;

      /* UnitDelay: '<S24>/z' */
      forced_choice_B.z = forced_choice_DWork.z_DSTATE;

      /* Sum: '<S24>/Add3' incorporates:
       *  Constant: '<S24>/rho'
       */
      forced_choice_B.Add3 = forced_choice_P.rho_Value - forced_choice_B.z;

      /* Product: '<S24>/product2' */
      forced_choice_B.product2 = forced_choice_B.x * forced_choice_B.Add3;

      /* Sum: '<S24>/Add2' */
      forced_choice_B.Add2 = forced_choice_B.product2 - forced_choice_B.y;

      /* Product: '<S24>/product3' incorporates:
       *  Constant: '<S24>/beta'
       */
      forced_choice_B.product3 = forced_choice_B.z * forced_choice_P.beta_Value;

      /* Product: '<S24>/product4' */
      forced_choice_B.product4 = forced_choice_B.y * forced_choice_B.x;

      /* Sum: '<S24>/Add4' */
      forced_choice_B.Add4 = forced_choice_B.product4 - forced_choice_B.product3;

      /* Product: '<S24>/product1' incorporates:
       *  Constant: '<S24>/sigma'
       */
      forced_choice_B.product1 = forced_choice_B.Add1_o *
        forced_choice_P.sigma_Value;

      /* Product: '<S24>/dX' incorporates:
       *  Constant: '<S24>/timescale'
       */
      forced_choice_B.dX = forced_choice_P.timescale_Value *
        forced_choice_B.product1;

      /* Sum: '<S24>/AddX' */
      forced_choice_B.AddX = forced_choice_B.x + forced_choice_B.dX;

      /* Product: '<S24>/dY' incorporates:
       *  Constant: '<S24>/timescale'
       */
      forced_choice_B.dY = forced_choice_P.timescale_Value *
        forced_choice_B.Add2;

      /* Sum: '<S24>/AddX1' */
      forced_choice_B.AddX1 = forced_choice_B.y + forced_choice_B.dY;

      /* Product: '<S24>/dZ' incorporates:
       *  Constant: '<S24>/timescale'
       */
      forced_choice_B.dZ = forced_choice_P.timescale_Value *
        forced_choice_B.Add4;

      /* Sum: '<S24>/AddX2' */
      forced_choice_B.AddX2 = forced_choice_B.z + forced_choice_B.dZ;

      /* UnitDelay: '<S25>/y' */
      forced_choice_B.y_p = forced_choice_DWork.y_DSTATE_a;

      /* Sum: '<S25>/Add1' */
      forced_choice_B.Add1_e = forced_choice_B.y_p - forced_choice_B.x_h;

      /* UnitDelay: '<S25>/z' */
      forced_choice_B.z_m = forced_choice_DWork.z_DSTATE_g;

      /* Sum: '<S25>/Add3' incorporates:
       *  Constant: '<S25>/rho'
       */
      forced_choice_B.Add3_n = forced_choice_P.rho_Value_d - forced_choice_B.z_m;

      /* Product: '<S25>/product2' */
      forced_choice_B.product2_n = forced_choice_B.x_h * forced_choice_B.Add3_n;

      /* Sum: '<S25>/Add2' */
      forced_choice_B.Add2_d = forced_choice_B.product2_n - forced_choice_B.y_p;

      /* Product: '<S25>/product3' incorporates:
       *  Constant: '<S25>/beta'
       */
      forced_choice_B.product3_b = forced_choice_B.z_m *
        forced_choice_P.beta_Value_b;

      /* Product: '<S25>/product4' */
      forced_choice_B.product4_n = forced_choice_B.y_p * forced_choice_B.x_h;

      /* Sum: '<S25>/Add4' */
      forced_choice_B.Add4_c = forced_choice_B.product4_n -
        forced_choice_B.product3_b;

      /* Product: '<S25>/product1' incorporates:
       *  Constant: '<S25>/sigma'
       */
      forced_choice_B.product1_k = forced_choice_B.Add1_e *
        forced_choice_P.sigma_Value_e;

      /* Product: '<S25>/dX' incorporates:
       *  Constant: '<S25>/timescale'
       */
      forced_choice_B.dX_i = forced_choice_P.timescale_Value_j *
        forced_choice_B.product1_k;

      /* Sum: '<S25>/AddX' */
      forced_choice_B.AddX_m = forced_choice_B.x_h + forced_choice_B.dX_i;

      /* Product: '<S25>/dY' incorporates:
       *  Constant: '<S25>/timescale'
       */
      forced_choice_B.dY_g = forced_choice_P.timescale_Value_j *
        forced_choice_B.Add2_d;

      /* Sum: '<S25>/AddX1' */
      forced_choice_B.AddX1_j = forced_choice_B.y_p + forced_choice_B.dY_g;

      /* Product: '<S25>/dZ' incorporates:
       *  Constant: '<S25>/timescale'
       */
      forced_choice_B.dZ_k = forced_choice_P.timescale_Value_j *
        forced_choice_B.Add4_c;

      /* Sum: '<S25>/AddX2' */
      forced_choice_B.AddX2_j = forced_choice_B.z_m + forced_choice_B.dZ_k;

      /* UnitDelay: '<S26>/y' */
      forced_choice_B.y_e = forced_choice_DWork.y_DSTATE_p;

      /* Sum: '<S26>/Add1' */
      forced_choice_B.Add1_l = forced_choice_B.y_e - forced_choice_B.x_m;

      /* UnitDelay: '<S26>/z' */
      forced_choice_B.z_mc = forced_choice_DWork.z_DSTATE_a;

      /* Sum: '<S26>/Add3' incorporates:
       *  Constant: '<S26>/rho'
       */
      forced_choice_B.Add3_k = forced_choice_P.rho_Value_h -
        forced_choice_B.z_mc;

      /* Product: '<S26>/product2' */
      forced_choice_B.product2_a = forced_choice_B.x_m * forced_choice_B.Add3_k;

      /* Sum: '<S26>/Add2' */
      forced_choice_B.Add2_k = forced_choice_B.product2_a - forced_choice_B.y_e;

      /* Product: '<S26>/product3' incorporates:
       *  Constant: '<S26>/beta'
       */
      forced_choice_B.product3_c = forced_choice_B.z_mc *
        forced_choice_P.beta_Value_p;

      /* Product: '<S26>/product4' */
      forced_choice_B.product4_c = forced_choice_B.y_e * forced_choice_B.x_m;

      /* Sum: '<S26>/Add4' */
      forced_choice_B.Add4_i = forced_choice_B.product4_c -
        forced_choice_B.product3_c;

      /* Product: '<S26>/product1' incorporates:
       *  Constant: '<S26>/sigma'
       */
      forced_choice_B.product1_b = forced_choice_B.Add1_l *
        forced_choice_P.sigma_Value_o;

      /* Product: '<S26>/dX' incorporates:
       *  Constant: '<S26>/timescale'
       */
      forced_choice_B.dX_l = forced_choice_P.timescale_Value_d *
        forced_choice_B.product1_b;

      /* Sum: '<S26>/AddX' */
      forced_choice_B.AddX_k = forced_choice_B.x_m + forced_choice_B.dX_l;

      /* Product: '<S26>/dY' incorporates:
       *  Constant: '<S26>/timescale'
       */
      forced_choice_B.dY_o = forced_choice_P.timescale_Value_d *
        forced_choice_B.Add2_k;

      /* Sum: '<S26>/AddX1' */
      forced_choice_B.AddX1_k = forced_choice_B.y_e + forced_choice_B.dY_o;

      /* Product: '<S26>/dZ' incorporates:
       *  Constant: '<S26>/timescale'
       */
      forced_choice_B.dZ_f = forced_choice_P.timescale_Value_d *
        forced_choice_B.Add4_i;

      /* Sum: '<S26>/AddX2' */
      forced_choice_B.AddX2_b = forced_choice_B.z_mc + forced_choice_B.dZ_f;

      /* UnitDelay: '<S27>/y' */
      forced_choice_B.y_k = forced_choice_DWork.y_DSTATE_g;

      /* Sum: '<S27>/Add1' */
      forced_choice_B.Add1_i = forced_choice_B.y_k - forced_choice_B.x_ho;

      /* UnitDelay: '<S27>/z' */
      forced_choice_B.z_n = forced_choice_DWork.z_DSTATE_p;

      /* Sum: '<S27>/Add3' incorporates:
       *  Constant: '<S27>/rho'
       */
      forced_choice_B.Add3_d = forced_choice_P.rho_Value_n - forced_choice_B.z_n;

      /* Product: '<S27>/product2' */
      forced_choice_B.product2_j = forced_choice_B.x_ho * forced_choice_B.Add3_d;

      /* Sum: '<S27>/Add2' */
      forced_choice_B.Add2_c = forced_choice_B.product2_j - forced_choice_B.y_k;

      /* Product: '<S27>/product3' incorporates:
       *  Constant: '<S27>/beta'
       */
      forced_choice_B.product3_a = forced_choice_B.z_n *
        forced_choice_P.beta_Value_e;

      /* Product: '<S27>/product4' */
      forced_choice_B.product4_p = forced_choice_B.y_k * forced_choice_B.x_ho;

      /* Sum: '<S27>/Add4' */
      forced_choice_B.Add4_h = forced_choice_B.product4_p -
        forced_choice_B.product3_a;

      /* Product: '<S27>/product1' incorporates:
       *  Constant: '<S27>/sigma'
       */
      forced_choice_B.product1_kd = forced_choice_B.Add1_i *
        forced_choice_P.sigma_Value_k;

      /* Product: '<S27>/dX' incorporates:
       *  Constant: '<S27>/timescale'
       */
      forced_choice_B.dX_a = forced_choice_P.timescale_Value_f *
        forced_choice_B.product1_kd;

      /* Sum: '<S27>/AddX' */
      forced_choice_B.AddX_mq = forced_choice_B.x_ho + forced_choice_B.dX_a;

      /* Product: '<S27>/dY' incorporates:
       *  Constant: '<S27>/timescale'
       */
      forced_choice_B.dY_p = forced_choice_P.timescale_Value_f *
        forced_choice_B.Add2_c;

      /* Sum: '<S27>/AddX1' */
      forced_choice_B.AddX1_e = forced_choice_B.y_k + forced_choice_B.dY_p;

      /* Product: '<S27>/dZ' incorporates:
       *  Constant: '<S27>/timescale'
       */
      forced_choice_B.dZ_p = forced_choice_P.timescale_Value_f *
        forced_choice_B.Add4_h;

      /* Sum: '<S27>/AddX2' */
      forced_choice_B.AddX2_f = forced_choice_B.z_n + forced_choice_B.dZ_p;

      /* Memory: '<S8>/Memory1' */
      forced_choice_B.Memory1 = forced_choice_DWork.Memory1_PreviousInput;

      /* DataTypeConversion: '<S8>/Data Type Conversion' */
      forced_choice_B.DataTypeConversion = (real_T)forced_choice_B.Memory1;
      for (s34_iter = 0; s34_iter < 4; s34_iter++) {
        forced_choice_B.ForIterator = (real_T)s34_iter;

        /* Output and update for iterator system: '<S14>/For Iterator Subsystem' */

        /* Sum: '<S34>/Add' incorporates:
         *  Constant: '<S34>/Constant'
         */
        forced_choice_B.Add_i = forced_choice_B.PCIQUAD04 +
          forced_choice_P.Constant_Value_i;

        /* Sum: '<S34>/Add1' incorporates:
         *  Constant: '<S34>/Constant'
         */
        forced_choice_B.Add1_k = forced_choice_B.PCIQUAD041 +
          forced_choice_P.Constant_Value_i;

        /* Level2 S-Function Block: '<S34>/SerialConverter' (serPos) */
        {
          SimStruct *rts = forced_choice_rtM->childSfunctions[2];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S34>/ToBits' (Byte2Bits) */
        {
          SimStruct *rts = forced_choice_rtM->childSfunctions[3];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S34>/Port B' (dopci8255) */
        {
          SimStruct *rts = forced_choice_rtM->childSfunctions[4];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S34>/xPC Target  Time ' (xpctimeinfo) */
        {
          SimStruct *rts = forced_choice_rtM->childSfunctions[5];
          sfcnOutputs(rts, 1);
        }

        do {
          /* Output and update for iterator system: '<S34>/While Iterator Subsystem' */

          /* Level2 S-Function Block: '<S36>/xPC Target  Time ' (xpctimeinfo) */
          {
            SimStruct *rts = forced_choice_rtM->childSfunctions[0];
            sfcnOutputs(rts, 1);
          }

          /* Sum: '<S36>/Subtract' */
          forced_choice_B.Subtract = forced_choice_B.xPCTargetTime_n -
            forced_choice_B.xPCTargetTime;

          /* Gain: '<S36>/ScaleTouSec' */
          forced_choice_B.ScaleTouSec = forced_choice_P.ScaleTouSec_Gain *
            forced_choice_B.Subtract;

          /* RelationalOperator: '<S38>/Compare' incorporates:
           *  Constant: '<S38>/Constant'
           */
          forced_choice_B.Compare_p = (forced_choice_B.ScaleTouSec >
            forced_choice_P.Constant_Value_m);

          /* Switch: '<S36>/Switch' incorporates:
           *  Constant: '<S36>/Constant'
           *  Constant: '<S36>/Constant1'
           */
          if (forced_choice_B.Compare_p) {
            forced_choice_B.Switch = forced_choice_P.Constant_Value_h;
          } else {
            forced_choice_B.Switch = forced_choice_P.Constant1_Value;
          }

          /* Level2 S-Function Block: '<S36>/PCI-6025E ' (donipcie) */
          {
            SimStruct *rts = forced_choice_rtM->childSfunctions[1];
            sfcnOutputs(rts, 1);
          }

          /* RelationalOperator: '<S37>/Compare' incorporates:
           *  Constant: '<S37>/Constant'
           */
          forced_choice_B.Compare_a = (forced_choice_B.ScaleTouSec <=
            forced_choice_P.Constant_Value_m2);
        } while (forced_choice_B.Compare_a);
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S28>/Clock'
     */
    forced_choice_B.Clock_k = forced_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S28>/Memory' */
    forced_choice_B.Memory_f = forced_choice_DWork.Memory_PreviousInput_m;

    /* Logic: '<S28>/Logical Operator2' */
    forced_choice_B.LogicalOperator2_h = (forced_choice_B.Memory_f ||
      (forced_choice_B.BehaviorFC_o5 != 0.0));

    /* Logic: '<S28>/Logical Operator1' */
    forced_choice_B.LogicalOperator1_m = !forced_choice_B.LogicalOperator2_h;

    /* SignalConversion: '<S28>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    forced_choice_B.HiddenBuf_InsertedFor_Enabled_g =
      forced_choice_B.LogicalOperator1_m;
  }

  /* SubSystem Block: '<S28>/Enabled Subsystem'
   */
  forced_choice_EnabledSubsystem(tid,
    forced_choice_B.HiddenBuf_InsertedFor_Enabled_g, forced_choice_B.Clock_k,
    &forced_choice_B.EnabledSubsystem_h, &forced_choice_DWork.EnabledSubsystem_h);
  if (tid == 0) {
    /* Sum: '<S28>/Sum' */
    forced_choice_B.Sum_l = forced_choice_B.Clock_k -
      forced_choice_B.EnabledSubsystem_h.In1;

    /* RelationalOperator: '<S29>/Compare' */
    forced_choice_B.Compare_b = (forced_choice_B.Sum_l > 0.0);

    /* RelationalOperator: '<S28>/Relational Operator' incorporates:
     *  Constant: '<S28>/Time'
     */
    forced_choice_B.RelationalOperator_m = (forced_choice_B.Sum_l >
      forced_choice_P.Time_Value_b);
  }

  if (tid == 0) {
    /* Logic: '<S28>/Logical Operator' */
    forced_choice_B.LogicalOperator_a = (boolean_T)((forced_choice_B.Compare_b
      != 0U) ^ forced_choice_B.RelationalOperator_m);

    /* RelationalOperator: '<S2>/Compare' incorporates:
     *  Constant: '<S2>/Constant'
     */
    forced_choice_B.Compare_b2 = (forced_choice_B.MG2 >
      forced_choice_P.Constant_Value);

    /* RelationalOperator: '<S3>/Compare' incorporates:
     *  Constant: '<S3>/Constant'
     */
    forced_choice_B.Compare_j = (forced_choice_B.MG1 >
      forced_choice_P.Constant_Value_d);

    /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix ConcatenationInPort0' */
    forced_choice_B.MatrixConcatenation[0] = forced_choice_B.LogicalOperator_h;

    /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix ConcatenationInPort1' */
    forced_choice_B.MatrixConcatenation[1] = forced_choice_B.LogicalOperator;

    /* Logic: '<Root>/Logical Operator1' */
    forced_choice_B.LogicalOperator1_l = ((forced_choice_B.Compare_b2 != 0U) ||
      (forced_choice_B.Compare_j != 0U));

    /* Sum: '<S11>/Add' */
    forced_choice_B.Add_n = forced_choice_B.BehaviorFC_o4[1] +
      forced_choice_B.BehaviorFC_o4[3];

    /* Sum: '<S11>/Add1' */
    forced_choice_B.Add1_m = forced_choice_B.BehaviorFC_o4[2] +
      forced_choice_B.BehaviorFC_o4[4];

    /* Gain: '<S11>/Gain' */
    forced_choice_B.Gain_n = forced_choice_P.Gain_Gain_i * forced_choice_B.Add_n;

    /* Gain: '<S11>/Gain1' */
    forced_choice_B.Gain1_d = forced_choice_P.Gain1_Gain_e *
      forced_choice_B.Add1_m;
  }
}

/* Model update function */
void forced_choice_update(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S9>/Memory' */
    forced_choice_DWork.Memory_PreviousInput = forced_choice_B.LogicalOperator;

    /* Update for Memory: '<Root>/Memory' */
    forced_choice_DWork.Memory_PreviousInput_a =
      forced_choice_B.LogicalOperator1_l;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S6>/Derivative' */
    {
      real_T timeStampA = forced_choice_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = forced_choice_DWork.Derivative_RWORK.TimeStampB;
      real_T *lastBank = &forced_choice_DWork.Derivative_RWORK.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = forced_choice_rtM->Timing.t[0];
      *lastBank++ = forced_choice_B.DigitalFilter2;
    }

    /* Derivative Block: '<S7>/Derivative' */
    {
      real_T timeStampA = forced_choice_DWork.Derivative_RWORK_p.TimeStampA;
      real_T timeStampB = forced_choice_DWork.Derivative_RWORK_p.TimeStampB;
      real_T *lastBank = &forced_choice_DWork.Derivative_RWORK_p.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = forced_choice_rtM->Timing.t[0];
      *lastBank++ = forced_choice_B.DigitalFilter2_d;
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for UnitDelay: '<S24>/x' */
    forced_choice_DWork.x_DSTATE = forced_choice_B.AddX;

    /* Update for UnitDelay: '<S25>/x' */
    forced_choice_DWork.x_DSTATE_h = forced_choice_B.AddX_m;

    /* Update for UnitDelay: '<S26>/x' */
    forced_choice_DWork.x_DSTATE_g = forced_choice_B.AddX_k;

    /* Update for UnitDelay: '<S27>/x' */
    forced_choice_DWork.x_DSTATE_e = forced_choice_B.AddX_mq;

    /* Level2 S-Function Block: '<Root>/Behavior FC' (mastercon_fc) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[8];
      sfcnUpdate(rts, 1);
      if (ssGetErrorStatus(rts) != NULL)
        return;
    }

    /* Update for UnitDelay: '<S24>/y' */
    forced_choice_DWork.y_DSTATE = forced_choice_B.AddX1;

    /* Update for UnitDelay: '<S24>/z' */
    forced_choice_DWork.z_DSTATE = forced_choice_B.AddX2;

    /* Update for UnitDelay: '<S25>/y' */
    forced_choice_DWork.y_DSTATE_a = forced_choice_B.AddX1_j;

    /* Update for UnitDelay: '<S25>/z' */
    forced_choice_DWork.z_DSTATE_g = forced_choice_B.AddX2_j;

    /* Update for UnitDelay: '<S26>/y' */
    forced_choice_DWork.y_DSTATE_p = forced_choice_B.AddX1_k;

    /* Update for UnitDelay: '<S26>/z' */
    forced_choice_DWork.z_DSTATE_a = forced_choice_B.AddX2_b;

    /* Update for UnitDelay: '<S27>/y' */
    forced_choice_DWork.y_DSTATE_g = forced_choice_B.AddX1_e;

    /* Update for UnitDelay: '<S27>/z' */
    forced_choice_DWork.z_DSTATE_p = forced_choice_B.AddX2_f;

    /* Update for Memory: '<S8>/Memory1' */
    forced_choice_DWork.Memory1_PreviousInput =
      forced_choice_B.LogicalOperator_a;

    /* Update for Memory: '<S28>/Memory' */
    forced_choice_DWork.Memory_PreviousInput_m =
      forced_choice_B.LogicalOperator_a;
  }

  /* Update absolute time for base rate */
  if (tid == 0) {
    if (!(++forced_choice_rtM->Timing.clockTick0))
      ++forced_choice_rtM->Timing.clockTickH0;
    forced_choice_rtM->Timing.t[0] = forced_choice_rtM->Timing.clockTick0 *
      forced_choice_rtM->Timing.stepSize0 +
      forced_choice_rtM->Timing.clockTickH0 *
      forced_choice_rtM->Timing.stepSize0 * 4294967296.0;
  }

  if (tid == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++forced_choice_rtM->Timing.clockTick1))
      ++forced_choice_rtM->Timing.clockTickH1;
    forced_choice_rtM->Timing.t[1] = forced_choice_rtM->Timing.clockTick1 *
      forced_choice_rtM->Timing.stepSize1 +
      forced_choice_rtM->Timing.clockTickH1 *
      forced_choice_rtM->Timing.stepSize1 * 4294967296.0;
  }

  if (tid == 2) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    if (!(++forced_choice_rtM->Timing.clockTick2))
      ++forced_choice_rtM->Timing.clockTickH2;
    forced_choice_rtM->Timing.t[2] = forced_choice_rtM->Timing.clockTick2 *
      forced_choice_rtM->Timing.stepSize2 +
      forced_choice_rtM->Timing.clockTickH2 *
      forced_choice_rtM->Timing.stepSize2 * 4294967296.0;
  }

  if (tid == 3) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    if (!(++forced_choice_rtM->Timing.clockTick3))
      ++forced_choice_rtM->Timing.clockTickH3;
    forced_choice_rtM->Timing.t[3] = forced_choice_rtM->Timing.clockTick3 *
      forced_choice_rtM->Timing.stepSize3 +
      forced_choice_rtM->Timing.clockTickH3 *
      forced_choice_rtM->Timing.stepSize3 * 4294967296.0;
  }
}

/* Model initialize function */
void forced_choice_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */
  /* initialize real-time model */
  (void) memset((char_T *)forced_choice_rtM,0,
                sizeof(rtModel_forced_choice));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&forced_choice_rtM->solverInfo,
                          &forced_choice_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&forced_choice_rtM->solverInfo, &rtmGetTPtr(forced_choice_rtM));
    rtsiSetStepSizePtr(&forced_choice_rtM->solverInfo,
                       &forced_choice_rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&forced_choice_rtM->solverInfo, (&rtmGetErrorStatus
      (forced_choice_rtM)));
    rtsiSetRTModelPtr(&forced_choice_rtM->solverInfo, forced_choice_rtM);
  }

  rtsiSetSimTimeStep(&forced_choice_rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&forced_choice_rtM->solverInfo,"FixedStepDiscrete");
  forced_choice_rtM->solverInfoPtr = (&forced_choice_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = forced_choice_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    mdlTsMap[3] = 3;
    forced_choice_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    forced_choice_rtM->Timing.sampleTimes =
      (&forced_choice_rtM->Timing.sampleTimesArray[0]);
    forced_choice_rtM->Timing.offsetTimes =
      (&forced_choice_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    forced_choice_rtM->Timing.sampleTimes[0] = (0.0);
    forced_choice_rtM->Timing.sampleTimes[1] = (0.001);
    forced_choice_rtM->Timing.sampleTimes[2] = (0.01);
    forced_choice_rtM->Timing.sampleTimes[3] = (0.02);

    /* task offsets */
    forced_choice_rtM->Timing.offsetTimes[0] = (0.0);
    forced_choice_rtM->Timing.offsetTimes[1] = (0.0);
    forced_choice_rtM->Timing.offsetTimes[2] = (0.0);
    forced_choice_rtM->Timing.offsetTimes[3] = (0.0);
  }

  rtmSetTPtr(forced_choice_rtM, &forced_choice_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = forced_choice_rtM->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      forced_choice_rtM->Timing.perTaskSampleHitsArray;
    forced_choice_rtM->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    forced_choice_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(forced_choice_rtM, -1);
  forced_choice_rtM->Timing.stepSize0 = 0.001;
  forced_choice_rtM->Timing.stepSize1 = 0.001;
  forced_choice_rtM->Timing.stepSize2 = 0.01;
  forced_choice_rtM->Timing.stepSize3 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    forced_choice_rtM->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(forced_choice_rtM->rtwLogInfo, 2);
    rtliSetLogMaxRows(forced_choice_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(forced_choice_rtM->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(forced_choice_rtM->rtwLogInfo, "rt_");
    rtliSetLogT(forced_choice_rtM->rtwLogInfo, "tout");
    rtliSetLogX(forced_choice_rtM->rtwLogInfo, "xout");
    rtliSetLogXFinal(forced_choice_rtM->rtwLogInfo, "");
    rtliSetSigLog(forced_choice_rtM->rtwLogInfo, "");

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
        SS_DOUBLE
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
        "DSTATE" };

      static const char_T *rt_LoggedStateBlockNames[] = {
        "forced_choice/Pos2VelX/Digital Filter2",
        "forced_choice/Pos2VelX/Digital Filter",
        "forced_choice/Pos2VelY/Digital Filter2",
        "forced_choice/Pos2VelY/Digital Filter",
        "forced_choice/Force Generator/LorentzForce/Lorentz/x",
        "forced_choice/Force Generator/LorentzForce/Lorentz1/x",
        "forced_choice/Force Generator/LorentzForce/Lorentz2/x",
        "forced_choice/Force Generator/LorentzForce/Lorentz3/x",
        "forced_choice/Behavior FC",
        "forced_choice/Force Generator/LorentzForce/Lorentz/y",
        "forced_choice/Force Generator/LorentzForce/Lorentz/z",
        "forced_choice/Force Generator/LorentzForce/Lorentz1/y",
        "forced_choice/Force Generator/LorentzForce/Lorentz1/z",
        "forced_choice/Force Generator/LorentzForce/Lorentz2/y",
        "forced_choice/Force Generator/LorentzForce/Lorentz2/z",
        "forced_choice/Force Generator/LorentzForce/Lorentz3/y",
        "forced_choice/Force Generator/LorentzForce/Lorentz3/z" };

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

        { 0, SS_DOUBLE, SS_DOUBLE, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
        17,
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

      rtliSetLogXSignalInfo(forced_choice_rtM->rtwLogInfo,
                            &rt_LoggedStateSignalInfo);
    }

    {
      static void * rt_LoggedStateSignalPtrs[17];
      rt_LoggedStateSignalPtrs[0] = (void*)
        &forced_choice_DWork.DigitalFilter2_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[1] = (void*)
        &forced_choice_DWork.DigitalFilter_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[2] = (void*)
        &forced_choice_DWork.DigitalFilter2_FILT_STATES_c[0];
      rt_LoggedStateSignalPtrs[3] = (void*)
        &forced_choice_DWork.DigitalFilter_FILT_STATES_p[0];
      rt_LoggedStateSignalPtrs[4] = (void*)&forced_choice_DWork.x_DSTATE;
      rt_LoggedStateSignalPtrs[5] = (void*)&forced_choice_DWork.x_DSTATE_h;
      rt_LoggedStateSignalPtrs[6] = (void*)&forced_choice_DWork.x_DSTATE_g;
      rt_LoggedStateSignalPtrs[7] = (void*)&forced_choice_DWork.x_DSTATE_e;
      rt_LoggedStateSignalPtrs[8] = (void*)
        &forced_choice_DWork.BehaviorFC_DSTATE;
      rt_LoggedStateSignalPtrs[9] = (void*)&forced_choice_DWork.y_DSTATE;
      rt_LoggedStateSignalPtrs[10] = (void*)&forced_choice_DWork.z_DSTATE;
      rt_LoggedStateSignalPtrs[11] = (void*)&forced_choice_DWork.y_DSTATE_a;
      rt_LoggedStateSignalPtrs[12] = (void*)&forced_choice_DWork.z_DSTATE_g;
      rt_LoggedStateSignalPtrs[13] = (void*)&forced_choice_DWork.y_DSTATE_p;
      rt_LoggedStateSignalPtrs[14] = (void*)&forced_choice_DWork.z_DSTATE_a;
      rt_LoggedStateSignalPtrs[15] = (void*)&forced_choice_DWork.y_DSTATE_g;
      rt_LoggedStateSignalPtrs[16] = (void*)&forced_choice_DWork.z_DSTATE_p;
      rtliSetLogXSignalPtrs(forced_choice_rtM->rtwLogInfo, (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
    }

    rtliSetLogY(forced_choice_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(forced_choice_rtM->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(forced_choice_rtM->rtwLogInfo, NULL);
  }

  /* external mode info */
  forced_choice_rtM->Sizes.checksums[0] = (549952335U);
  forced_choice_rtM->Sizes.checksums[1] = (1277274929U);
  forced_choice_rtM->Sizes.checksums[2] = (4219268999U);
  forced_choice_rtM->Sizes.checksums[3] = (484119277U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[16];
    forced_choice_rtM->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[10] = (sysRanDType *)
      &forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &forced_choice_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, forced_choice_rtM->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(forced_choice_rtM));
  }

  forced_choice_rtM->solverInfoPtr = (&forced_choice_rtM->solverInfo);
  forced_choice_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&forced_choice_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&forced_choice_rtM->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  forced_choice_rtM->ModelData.blockIO = ((void *) &forced_choice_B);
  (void) memset(((void *) &forced_choice_B),0,
                sizeof(BlockIO_forced_choice));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&forced_choice_B.Clock);
    for (i = 0; i < 144; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&forced_choice_B.ForIterator);
    for (i = 0; i < 43; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    ((real_T*)&forced_choice_B.EnabledSubsystem.In1)[0] = 0.0;
    ((real_T*)&forced_choice_B.EnabledSubsystem_h.In1)[0] = 0.0;
  }

  /* parameters */
  forced_choice_rtM->ModelData.defaultParam = ((real_T *) &forced_choice_P);

  /* states (dwork) */
  forced_choice_rtM->Work.dwork = ((void *) &forced_choice_DWork);
  (void) memset((char_T *) &forced_choice_DWork,0,
                sizeof(D_Work_forced_choice));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *)
      &forced_choice_DWork.DigitalFilter2_FILT_STATES[0];
    for (i = 0; i < 74; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    forced_choice_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    forced_choice_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  forced_choice_InitializeDataMapInfo(forced_choice_rtM);

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &forced_choice_rtM->NonInlinedSFcns.sfcnInfo;
    forced_choice_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(forced_choice_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &forced_choice_rtM->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(forced_choice_rtM));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(forced_choice_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (forced_choice_rtM));
    rtssSetStepSizePtr(sfcnInfo, &forced_choice_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(forced_choice_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &forced_choice_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &forced_choice_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &forced_choice_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &forced_choice_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &forced_choice_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &forced_choice_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &forced_choice_rtM->solverInfoPtr);
  }

  forced_choice_rtM->Sizes.numSFcns = (13);

  /* register each child */
  {
    (void) memset((void *)&forced_choice_rtM->NonInlinedSFcns.childSFunctions[0],
                  0,
                  13*sizeof(SimStruct));
    forced_choice_rtM->childSfunctions =
      (&forced_choice_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 13; i++) {
        forced_choice_rtM->childSfunctions[i] =
          (&forced_choice_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: forced_choice/<S36>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &forced_choice_B.xPCTargetTime_n));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "forced_choice/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&forced_choice_P.xPCTargetTime_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&forced_choice_P.xPCTargetTime_P2_Size
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

    /* Level2 S-Function Block: forced_choice/<S36>/PCI-6025E  (donipcie) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.Switch;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &forced_choice_B.DataTypeConversion;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts,
                "forced_choice/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&forced_choice_P.PCI6025E_P1_Size_i[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&forced_choice_P.PCI6025E_P2_Size_e[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&forced_choice_P.PCI6025E_P3_Size_l[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&forced_choice_P.PCI6025E_P4_Size_p[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&forced_choice_P.PCI6025E_P5_Size_h[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&forced_choice_P.PCI6025E_P6_Size_h[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&forced_choice_P.PCI6025E_P7_Size_n[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &forced_choice_DWork.PCI6025E_IWORK_k[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn1.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &forced_choice_DWork.PCI6025E_IWORK_k[0]);
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

    /* Level2 S-Function Block: forced_choice/<S34>/SerialConverter (serPos) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.ForIterator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = &forced_choice_B.Add_i;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn2.UPtrs2;
          sfcnUPtrs[0] = &forced_choice_B.Add1_k;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &forced_choice_B.SerialConverter));
        }
      }

      /* path info */
      ssSetModelName(rts, "SerialConverter");
      ssSetPath(rts,
                "forced_choice/XY Position Subsystem/For Iterator Subsystem/SerialConverter");
      ssSetRTModel(rts,forced_choice_rtM);
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

    /* Level2 S-Function Block: forced_choice/<S34>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.SerialConverter;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &forced_choice_B.ToBits_o1_n));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &forced_choice_B.ToBits_o2_l));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &forced_choice_B.ToBits_o3_f));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &forced_choice_B.ToBits_o4_k));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &forced_choice_B.ToBits_o5_a));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &forced_choice_B.ToBits_o6_o));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &forced_choice_B.ToBits_o7_h));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &forced_choice_B.ToBits_o8_e));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts,
                "forced_choice/XY Position Subsystem/For Iterator Subsystem/ToBits");
      ssSetRTModel(rts,forced_choice_rtM);
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

    /* Level2 S-Function Block: forced_choice/<S34>/Port B (dopci8255) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o1_n;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o2_l;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs2;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o3_f;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs3;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o4_k;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs4;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o5_a;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs5;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o6_o;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs6;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o7_h;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs7;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o8_e;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port B");
      ssSetPath(rts,
                "forced_choice/XY Position Subsystem/For Iterator Subsystem/Port B");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&forced_choice_P.PortB_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&forced_choice_P.PortB_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&forced_choice_P.PortB_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&forced_choice_P.PortB_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&forced_choice_P.PortB_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&forced_choice_P.PortB_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&forced_choice_P.PortB_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&forced_choice_P.PortB_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&forced_choice_P.PortB_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &forced_choice_DWork.PortB_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn4.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &forced_choice_DWork.PortB_IWORK[0]);
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

    /* Level2 S-Function Block: forced_choice/<S34>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[5]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &forced_choice_B.xPCTargetTime));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "forced_choice/XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &forced_choice_P.xPCTargetTime_P1_Size_p[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &forced_choice_P.xPCTargetTime_P2_Size_d[0]);
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

    /* Level2 S-Function Block: forced_choice/<S14>/PCI-QUAD04  (enccbcioquadcount) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[6]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &forced_choice_B.PCIQUAD04));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 ");
      ssSetPath(rts, "forced_choice/XY Position Subsystem/PCI-QUAD04 ");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&forced_choice_P.PCIQUAD04_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&forced_choice_P.PCIQUAD04_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&forced_choice_P.PCIQUAD04_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&forced_choice_P.PCIQUAD04_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&forced_choice_P.PCIQUAD04_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&forced_choice_P.PCIQUAD04_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&forced_choice_P.PCIQUAD04_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&forced_choice_P.PCIQUAD04_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&forced_choice_P.PCIQUAD04_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&forced_choice_P.PCIQUAD04_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&forced_choice_P.PCIQUAD04_P11_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &forced_choice_DWork.PCIQUAD04_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn6.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &forced_choice_DWork.PCIQUAD04_IWORK);
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

    /* Level2 S-Function Block: forced_choice/<S14>/PCI-QUAD04 1 (enccbcioquadcount) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[7]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &forced_choice_B.PCIQUAD041));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 1");
      ssSetPath(rts, "forced_choice/XY Position Subsystem/PCI-QUAD04 1");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&forced_choice_P.PCIQUAD041_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&forced_choice_P.PCIQUAD041_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&forced_choice_P.PCIQUAD041_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&forced_choice_P.PCIQUAD041_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&forced_choice_P.PCIQUAD041_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&forced_choice_P.PCIQUAD041_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&forced_choice_P.PCIQUAD041_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&forced_choice_P.PCIQUAD041_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&forced_choice_P.PCIQUAD041_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&forced_choice_P.PCIQUAD041_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&forced_choice_P.PCIQUAD041_P11_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &forced_choice_DWork.PCIQUAD041_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn7.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &forced_choice_DWork.PCIQUAD041_IWORK);
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

    /* Level2 S-Function Block: forced_choice/<Root>/Behavior FC (mastercon_fc) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[8]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.Product1;
          sfcnUPtrs[1] = &forced_choice_B.Product;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn8.UPtrs1;
          sfcnUPtrs[0] = forced_choice_B.MultiportSwitch;
          sfcnUPtrs[1] = &forced_choice_B.MultiportSwitch[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            forced_choice_B.BehaviorFC_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 4);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            forced_choice_B.BehaviorFC_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &forced_choice_B.BehaviorFC_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 10);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            forced_choice_B.BehaviorFC_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &forced_choice_B.BehaviorFC_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 2);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            forced_choice_B.BehaviorFC_o6));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *) &forced_choice_DWork.BehaviorFC_DSTATE);

      /* path info */
      ssSetModelName(rts, "Behavior FC");
      ssSetPath(rts, "forced_choice/Behavior FC");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&forced_choice_P.BehaviorFC_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&forced_choice_P.BehaviorFC_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&forced_choice_P.BehaviorFC_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&forced_choice_P.BehaviorFC_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&forced_choice_P.BehaviorFC_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&forced_choice_P.BehaviorFC_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&forced_choice_P.BehaviorFC_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&forced_choice_P.BehaviorFC_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&forced_choice_P.BehaviorFC_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&forced_choice_P.BehaviorFC_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&forced_choice_P.BehaviorFC_P11_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &forced_choice_DWork.BehaviorFC_RWORK[0]);
      ssSetIWork(rts, (int_T *) &forced_choice_DWork.BehaviorFC_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn8.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 3);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &forced_choice_DWork.BehaviorFC_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 63);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &forced_choice_DWork.BehaviorFC_IWORK[0]);

        /* DSTATE */
        ssSetDWorkWidth(rts, 2, 1);
        ssSetDWorkDataType(rts, 2,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWorkUsedAsDState(rts, 2, 1);
        ssSetDWork(rts, 2, &forced_choice_DWork.BehaviorFC_DSTATE);
      }

      /* registration */
      mastercon_fc(rts);
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

    /* Level2 S-Function Block: forced_choice/<Root>/PCI-6025E  (danipcie) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[9]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn9.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.RateTransition2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn9.UPtrs1;
          sfcnUPtrs[0] = &forced_choice_B.RateTransition1;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts, "forced_choice/PCI-6025E ");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&forced_choice_P.PCI6025E_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&forced_choice_P.PCI6025E_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&forced_choice_P.PCI6025E_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&forced_choice_P.PCI6025E_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&forced_choice_P.PCI6025E_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&forced_choice_P.PCI6025E_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&forced_choice_P.PCI6025E_P7_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &forced_choice_DWork.PCI6025E_RWORK[0]);
      ssSetIWork(rts, (int_T *) &forced_choice_DWork.PCI6025E_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn9.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &forced_choice_DWork.PCI6025E_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &forced_choice_DWork.PCI6025E_IWORK[0]);
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

    /* Level2 S-Function Block: forced_choice/<S12>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[10]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[10]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn10.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, forced_choice_B.RateTransition);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 112);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "forced_choice/UDPXmit/Send");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&forced_choice_P.Send_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&forced_choice_P.Send_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&forced_choice_P.Send_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&forced_choice_P.Send_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &forced_choice_DWork.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &forced_choice_DWork.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn10.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &forced_choice_DWork.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &forced_choice_DWork.Send_PWORK);
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

    /* Level2 S-Function Block: forced_choice/<S13>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[11]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn11.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.BehaviorFC_o3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &forced_choice_B.ToBits_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &forced_choice_B.ToBits_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &forced_choice_B.ToBits_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &forced_choice_B.ToBits_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &forced_choice_B.ToBits_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &forced_choice_B.ToBits_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &forced_choice_B.ToBits_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &forced_choice_B.ToBits_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts, "forced_choice/WordSbs/ToBits");
      ssSetRTModel(rts,forced_choice_rtM);
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

    /* Level2 S-Function Block: forced_choice/<S13>/Port A (dopci8255) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[12]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[12]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs1;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs2;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs3;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs4;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs5;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs6;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs7;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port A");
      ssSetPath(rts, "forced_choice/WordSbs/Port A");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&forced_choice_P.PortA_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&forced_choice_P.PortA_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&forced_choice_P.PortA_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&forced_choice_P.PortA_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&forced_choice_P.PortA_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&forced_choice_P.PortA_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&forced_choice_P.PortA_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&forced_choice_P.PortA_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&forced_choice_P.PortA_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &forced_choice_DWork.PortA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn12.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &forced_choice_DWork.PortA_IWORK[0]);
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
void forced_choice_terminate(void)
{
  /* Level2 S-Function Block: '<S14>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Behavior FC' (mastercon_fc) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S12>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/Port A' (dopci8255) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S14>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S34>/SerialConverter' (serPos) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S34>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S34>/Port B' (dopci8255) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S34>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S34>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S36>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S36>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[1];
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
  forced_choice_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  forced_choice_update(tid);
}

void MdlInitializeSizes(void)
{
  forced_choice_rtM->Sizes.numContStates = (0);/* Number of continuous states */
  forced_choice_rtM->Sizes.numY = (0); /* Number of model outputs */
  forced_choice_rtM->Sizes.numU = (0); /* Number of model inputs */
  forced_choice_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  forced_choice_rtM->Sizes.numSampTimes = (4);/* Number of sample times */
  forced_choice_rtM->Sizes.numBlocks = (252);/* Number of blocks */
  forced_choice_rtM->Sizes.numBlockIO = (199);/* Number of block outputs */
  forced_choice_rtM->Sizes.numBlockPrms = (400);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Memory: '<S9>/Memory' */
  forced_choice_DWork.Memory_PreviousInput = forced_choice_P.Memory_X0;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  forced_choice_DWork.Memory_PreviousInput_a = forced_choice_P.Memory_X0_b;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S6>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *)
      &forced_choice_DWork.DigitalFilter2_FILT_STATES[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&forced_choice_P.DigitalFilter2_ICRTP;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S6>/Derivative' */
  forced_choice_DWork.Derivative_RWORK.TimeStampA = rtInf;
  forced_choice_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S6>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &forced_choice_DWork.DigitalFilter_FILT_STATES
      [0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&forced_choice_P.DigitalFilter_ICRTP;
    }

    *statePtr++ = 0.0;
  }

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S7>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *)
      &forced_choice_DWork.DigitalFilter2_FILT_STATES_c[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&forced_choice_P.DigitalFilter2_ICRTP_c;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S7>/Derivative' */
  forced_choice_DWork.Derivative_RWORK_p.TimeStampA = rtInf;
  forced_choice_DWork.Derivative_RWORK_p.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S7>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *)
      &forced_choice_DWork.DigitalFilter_FILT_STATES_p[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&forced_choice_P.DigitalFilter_ICRTP_c;
    }

    *statePtr++ = 0.0;
  }

  /* InitializeConditions for UnitDelay: '<S24>/x' */
  forced_choice_DWork.x_DSTATE = forced_choice_P.x_X0;

  /* InitializeConditions for UnitDelay: '<S25>/x' */
  forced_choice_DWork.x_DSTATE_h = forced_choice_P.x_X0_f;

  /* InitializeConditions for UnitDelay: '<S26>/x' */
  forced_choice_DWork.x_DSTATE_g = forced_choice_P.x_X0_l;

  /* InitializeConditions for UnitDelay: '<S27>/x' */
  forced_choice_DWork.x_DSTATE_e = forced_choice_P.x_X0_c;

  /* Level2 S-Function Block: '<Root>/Behavior FC' (mastercon_fc) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[8];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* InitializeConditions for UnitDelay: '<S24>/y' */
  forced_choice_DWork.y_DSTATE = forced_choice_P.y_X0;

  /* InitializeConditions for UnitDelay: '<S24>/z' */
  forced_choice_DWork.z_DSTATE = forced_choice_P.z_X0;

  /* InitializeConditions for UnitDelay: '<S25>/y' */
  forced_choice_DWork.y_DSTATE_a = forced_choice_P.y_X0_f;

  /* InitializeConditions for UnitDelay: '<S25>/z' */
  forced_choice_DWork.z_DSTATE_g = forced_choice_P.z_X0_p;

  /* InitializeConditions for UnitDelay: '<S26>/y' */
  forced_choice_DWork.y_DSTATE_p = forced_choice_P.y_X0_k;

  /* InitializeConditions for UnitDelay: '<S26>/z' */
  forced_choice_DWork.z_DSTATE_a = forced_choice_P.z_X0_n;

  /* InitializeConditions for UnitDelay: '<S27>/y' */
  forced_choice_DWork.y_DSTATE_g = forced_choice_P.y_X0_h;

  /* InitializeConditions for UnitDelay: '<S27>/z' */
  forced_choice_DWork.z_DSTATE_p = forced_choice_P.z_X0_b;

  /* InitializeConditions for Memory: '<S8>/Memory1' */
  forced_choice_DWork.Memory1_PreviousInput = forced_choice_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S28>/Memory' */
  forced_choice_DWork.Memory_PreviousInput_m = forced_choice_P.Memory_X0_n;
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S14>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S14>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<Root>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S10>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior FC/p2/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior FC/p2/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior FC/p2/s3"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior FC/p2/s4"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior FC/p2/s1"),"%2.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior FC/p2/s2"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior FC/p2/s3"),
          "%15.6f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior FC/p2/s4"),
          "%15.6f");
        rl32eSetScope(3, 4, 10);
        rl32eSetScope(3, 40, 0);
        rl32eSetScope(3, 7, 10);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Behavior FC/p2/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 10, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, -10.0);
        rl32eSetTargetScope(3, 10, 10.0);
        xpceScopeAcqOK(3, &forced_choice_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Level2 S-Function Block: '<S12>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S13>/Port A' (dopci8255) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S15>/S-Function (scblock) */
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
        xpceScopeAcqOK(1, &forced_choice_DWork.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S16>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,2)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo("Matrix Concatenation/s1"));
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Matrix Concatenation/s1"),
          "%15.2f");
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
        xpceScopeAcqOK(5, &forced_choice_DWork.SFunction_IWORK_a.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /* S-Function Block: <S17>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Behavior FC/p6/s1"));
        rl32eAddSignal(2, rl32eGetSignalNo("Behavior FC/p6/s2"));
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("Behavior FC/p6/s1"),
          "%15.2f");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("Behavior FC/p6/s2"),
          "%15.6f");
        rl32eSetScope(2, 4, 10);
        rl32eSetScope(2, 40, 0);
        rl32eSetScope(2, 7, 10);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Behavior FC/p6/s1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 10, 0);
        rl32eSetTargetScope(2, 1, 0.0);
        rl32eSetTargetScope(2, 11, -10.0);
        rl32eSetTargetScope(2, 10, 10.0);
        xpceScopeAcqOK(2, &forced_choice_DWork.SFunction_IWORK_d.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S18>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior FC/p1/s1"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior FC/p1/s2"));
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior FC/p1/s1"),"%2.2f");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior FC/p1/s2"),
          "%15.6f");
        rl32eSetScope(7, 4, 7);
        rl32eSetScope(7, 40, 0);
        rl32eSetScope(7, 7, 1);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("Behavior FC/p1/s1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 10, 0);
        rl32eSetTargetScope(7, 1, 0.0);
        rl32eSetTargetScope(7, 11, 0.0);
        rl32eSetTargetScope(7, 10, 0.0);
        xpceScopeAcqOK(7, &forced_choice_DWork.SFunction_IWORK_h.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* S-Function Block: <S19>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("Behavior FC/p4/s1"));
        rl32eAddSignal(4, rl32eGetSignalNo("Target Peek/Gain"));
        rl32eAddSignal(4, rl32eGetSignalNo("Target Peek/Gain1"));
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Behavior FC/p4/s1"),
          "%d%2.2f%2.2f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Target Peek/Gain"),"%15.6f");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Target Peek/Gain1"),
          "%15.6f");
        rl32eSetScope(4, 4, 7);
        rl32eSetScope(4, 40, 0);
        rl32eSetScope(4, 7, 1);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("Behavior FC/p4/s1"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 10, 0);
        rl32eSetTargetScope(4, 1, 0.0);
        rl32eSetTargetScope(4, 11, 0.0);
        rl32eSetTargetScope(4, 10, 0.0);
        xpceScopeAcqOK(4, &forced_choice_DWork.SFunction_IWORK_ie.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /* S-Function Block: <S22>/S-Function (scblock) */
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
        xpceScopeAcqOK(10, &forced_choice_DWork.SFunction_IWORK_b.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(10);
    }
  }

  /* S-Function Block: <S23>/S-Function (scblock) */
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
        xpceScopeAcqOK(9, &forced_choice_DWork.SFunction_IWORK_g.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(9);
    }
  }

  /* Start for iterator system: '<S14>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S34>/Port B' (dopci8255) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Start for iterator system: '<S34>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S36>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC =
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

rtModel_forced_choice *forced_choice(void)
{
  forced_choice_initialize(1);
  return forced_choice_rtM;
}

void MdlTerminate(void)
{
  forced_choice_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
