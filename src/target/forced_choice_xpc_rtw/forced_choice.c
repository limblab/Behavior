/*
 * forced_choice.c
 *
 * Real-Time Workshop code generation for Simulink model "forced_choice.mdl".
 *
 * Model Version              : 1.1203
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:24 2010
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

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_forced_choice forced_choice_PrevZCSigState;

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
}

time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(forced_choice_rtM, 1);
  rtmSampleHitPtr[2] = rtmStepTask(forced_choice_rtM, 2);
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

  /* tid 1 shares data with slower tid rate: 2 */
  if (forced_choice_rtM->Timing.TaskCounters.TID[1] == 0) {
    forced_choice_rtM->Timing.RateInteraction.TID1_2 =
      (forced_choice_rtM->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    forced_choice_rtM->Timing.perTaskSampleHits[5] =
      forced_choice_rtM->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++forced_choice_rtM->Timing.TaskCounters.TID[2] == 20) {/* Sample time: [0.02s, 0.0s] */
    forced_choice_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  forced_choice_rtM->Timing.sampleHits[2] =
    (forced_choice_rtM->Timing.TaskCounters.TID[2] == 0);
}

/* Disable for enable system:
 *   '<S31>/Enabled Subsystem'
 *   '<S43>/Enabled Subsystem'
 *   '<S44>/Enabled Subsystem'
 *   '<S45>/Enabled Subsystem'
 *   '<S47>/Enabled Subsystem'
 */
void forced_EnabledSubsystem_Disable(rtDW_EnabledSubsystem_forced_ch *localDW)
{
  /* DisableFcn of enable SubSystem Block: '<S31>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE = (int_T) SUBSYS_DISABLED;
}

/* Output and update for enable system:
 *   '<S31>/Enabled Subsystem'
 *   '<S43>/Enabled Subsystem'
 *   '<S44>/Enabled Subsystem'
 *   '<S45>/Enabled Subsystem'
 *   '<S47>/Enabled Subsystem'
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
        /* Inport: '<S35>/In1' */
        localB->In1 = rtu_1;
      }

      srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC);
    }
  }
}

/* Start for trigger system:
 *   '<S6>/Sample and Hold'
 *   '<S65>/Sample and Hold'
 */
void forced_choi_SampleandHold_Start(rtB_SampleandHold_forced_choice *localB,
  rtP_SampleandHold_forced_choice *localP)
{
  /* virtual outports code */

  /* (Virtual) Outport Block: '<S64>/ ' */
  localB->In = localP->_Y0;
}

/* Output and update for trigger system:
 *   '<S6>/Sample and Hold'
 *   '<S65>/Sample and Hold'
 */
void forced_choice_SampleandHold(real_T rtu_0, real_T rtu_1,
  rtB_SampleandHold_forced_choice *localB, rtDW_SampleandHold_forced_choic
  *localDW, rtZCE_SampleandHold_forced_choi *localZCE)
{
  {
    ZCEventType trigEvent;
    trigEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&(localZCE->SampleandHold_ZCE),
                         rtu_0);

    /* conditionally execute */
    if (trigEvent != NO_ZCEVENT) {
      /* Inport: '<S64>/In' */
      localB->In = rtu_1;
      localDW->SampleandHold_SubsysRanBC = SUBSYS_RAN_BC_ONE_SHOT;
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
    srClearBC(forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC);
    srClearBC
      (forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_SubsysRanBC);
    srClearBC
      (forced_choice_DWork.EnabledSubsystem_hg.EnabledSubsystem_SubsysRanBC);
    srClearBC
      (forced_choice_DWork.EnabledSubsystem_i.EnabledSubsystem_SubsysRanBC);
    srClearBC
      (forced_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC);
    srClearBC(forced_choice_DWork.SampleandHold_i.SampleandHold_SubsysRanBC);
    srClearBC(forced_choice_DWork.SampleandHold.SampleandHold_SubsysRanBC);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S31>/Clock'
     */
    forced_choice_B.Clock = forced_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S31>/Memory' */
    forced_choice_B.Memory = forced_choice_DWork.Memory_PreviousInput;

    /* Memory: '<S4>/Memory' */
    forced_choice_B.Memory_p = forced_choice_DWork.Memory_PreviousInput_l;

    /* Logic: '<S31>/Logical Operator2' */
    forced_choice_B.LogicalOperator2 = (forced_choice_B.Memory ||
      forced_choice_B.Memory_p);

    /* Logic: '<S31>/Logical Operator1' */
    forced_choice_B.LogicalOperator1 = !forced_choice_B.LogicalOperator2;

    /* SignalConversion: '<S31>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    forced_choice_B.HiddenBuf_InsertedFor_EnabledSu =
      forced_choice_B.LogicalOperator1;
  }

  /* SubSystem Block: '<S31>/Enabled Subsystem'
   */
  forced_choice_EnabledSubsystem(tid,
    forced_choice_B.HiddenBuf_InsertedFor_EnabledSu, forced_choice_B.Clock,
    &forced_choice_B.EnabledSubsystem, &forced_choice_DWork.EnabledSubsystem);
  if (tid == 0) {
    /* Sum: '<S31>/Sum' */
    forced_choice_B.Sum = forced_choice_B.Clock -
      forced_choice_B.EnabledSubsystem.In1;

    /* RelationalOperator: '<S34>/Compare' */
    forced_choice_B.Compare = (forced_choice_B.Sum > 0.0);

    /* RelationalOperator: '<S31>/Relational Operator' incorporates:
     *  Constant: '<S31>/Time'
     */
    forced_choice_B.RelationalOperator = (forced_choice_B.Sum >
      forced_choice_P.Time_Value);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S31>/Logical Operator' */
    forced_choice_B.LogicalOperator = (boolean_T)((forced_choice_B.Compare != 0U)
      ^ forced_choice_B.RelationalOperator);

    /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S13>/Gain' */
    forced_choice_B.Gain = forced_choice_P.Gain_Gain * forced_choice_B.PCIQUAD04;

    /* Sum: '<S13>/Sum3' incorporates:
     *  Constant: '<S13>/shoulderOffset'
     */
    forced_choice_B.Sum3 = forced_choice_B.Gain +
      forced_choice_P.shoulderOffset_Value;

    /* Trigonometry: '<S71>/Trigonometric Function' */
    forced_choice_B.TrigonometricFunction = cos(forced_choice_B.Sum3);

    /* Product: '<S71>/Product' incorporates:
     *  Constant: '<S71>/L1'
     */
    forced_choice_B.Product = forced_choice_B.TrigonometricFunction *
      forced_choice_P.L1_Value;

    /* Gain: '<S71>/Gain' */
    forced_choice_B.MatrixConcatenate2[0] = forced_choice_P.Gain_Gain_m *
      forced_choice_B.Product;

    /* Trigonometry: '<S71>/Trigonometric Function1' */
    forced_choice_B.TrigonometricFunction1 = sin(forced_choice_B.Sum3);

    /* Product: '<S71>/Product1' incorporates:
     *  Constant: '<S71>/L1'
     */
    forced_choice_B.Product1 = forced_choice_B.TrigonometricFunction1 *
      forced_choice_P.L1_Value;

    /* SignalConversion: '<S71>/ConcatHiddenBufferAtMatrix ConcatenateInPort1' */
    forced_choice_B.MatrixConcatenate2[1] = forced_choice_B.Product1;

    /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[9];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S13>/Gain1' */
    forced_choice_B.Gain1 = forced_choice_P.Gain1_Gain *
      forced_choice_B.PCIQUAD041;

    /* Sum: '<S13>/Sum1' incorporates:
     *  Constant: '<S13>/elbowOffset'
     */
    forced_choice_B.Sum1 = forced_choice_B.Gain1 +
      forced_choice_P.elbowOffset_Value;

    /* Trigonometry: '<S71>/Trigonometric Function2' */
    forced_choice_B.TrigonometricFunction2 = sin(forced_choice_B.Sum1);

    /* Product: '<S71>/Product2' incorporates:
     *  Constant: '<S71>/L2'
     */
    forced_choice_B.Product2 = forced_choice_B.TrigonometricFunction2 *
      forced_choice_P.L2_Value;

    /* Gain: '<S71>/Gain1' */
    forced_choice_B.MatrixConcatenate2[2] = forced_choice_P.Gain1_Gain_m *
      forced_choice_B.Product2;

    /* Trigonometry: '<S71>/Trigonometric Function3' */
    forced_choice_B.TrigonometricFunction3 = cos(forced_choice_B.Sum1);

    /* Product: '<S71>/Product3' incorporates:
     *  Constant: '<S71>/L2'
     */
    forced_choice_B.Product3 = forced_choice_B.TrigonometricFunction3 *
      forced_choice_P.L2_Value;

    /* Gain: '<S71>/Gain2' */
    forced_choice_B.MatrixConcatenate2[3] = forced_choice_P.Gain2_Gain *
      forced_choice_B.Product3;

    /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[10];
      sfcnOutputs(rts, 1);
    }

    {
      real_T tmp;
      real_T tmp_0;

      /* Sum: '<S71>/Sum2' */
      forced_choice_B.Sum2 = (0.0 - forced_choice_B.Product) -
        forced_choice_B.Product2;

      /* Sum: '<S71>/Sum4' incorporates:
       *  Constant: '<S71>/yoffset'
       */
      forced_choice_B.Sum4 = forced_choice_B.Sum2 +
        forced_choice_P.yoffset_Value;

      /* Sum: '<S71>/Sum3' */
      forced_choice_B.Sum3_n = forced_choice_B.Product3 -
        forced_choice_B.Product1;

      /* Sum: '<S71>/Sum1' incorporates:
       *  Constant: '<S71>/xoffset'
       */
      forced_choice_B.Sum1_a = forced_choice_B.Sum3_n +
        forced_choice_P.xoffset_Value;

      /* Trigonometry: '<S69>/Trigonometric Function1' */
      forced_choice_B.TrigonometricFunction1_j = rt_atan2(forced_choice_B.Sum4,
        forced_choice_B.Sum1_a);

      /* Sum: '<S69>/Sum' incorporates:
       *  Constant: '<S69>/AngleOffset'
       */
      forced_choice_B.Sum_f = forced_choice_B.TrigonometricFunction1_j +
        forced_choice_P.AngleOffset_Value;

      /* Trigonometry: '<S69>/Trigonometric Function2' */
      forced_choice_B.TrigonometricFunction2_g = cos(forced_choice_B.Sum_f);

      /* Fcn: '<S69>/sqrt(u[1]*u[1] + u[2]*u[2])' */
      tmp = forced_choice_B.Sum4;
      tmp_0 = forced_choice_B.Sum1_a;
      forced_choice_B.sqrtu1u1u2u2 = sqrt(tmp * tmp + tmp_0 * tmp_0);

      /* Product: '<S69>/Product1' */
      forced_choice_B.Product1_d = forced_choice_B.TrigonometricFunction2_g *
        forced_choice_B.sqrtu1u1u2u2;
    }

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&forced_choice_B.Product1_d, &forced_choice_B.DigitalFilter2,
                    &forced_choice_DWork.DigitalFilter2_FILT_STATES[0],
                    &forced_choice_DWork.DigitalFilter2_CIRCBUFFIDX, 11, 1, 1,
                    &forced_choice_P.DigitalFilter2_RTP1COEFF[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S67>/Derivative' */
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
    /* Gain: '<S67>/dG' */
    forced_choice_B.dG = forced_choice_P.dG_Gain * forced_choice_B.Derivative;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&forced_choice_B.dG, &forced_choice_B.DigitalFilter,
                    &forced_choice_DWork.DigitalFilter_FILT_STATES[0],
                    &forced_choice_DWork.DigitalFilter_CIRCBUFFIDX, 11, 1, 1,
                    &forced_choice_P.DigitalFilter_RTP1COEFF[0], 1);

    /* Trigonometry: '<S69>/Trigonometric Function' */
    forced_choice_B.TrigonometricFunction_k = sin(forced_choice_B.Sum_f);

    /* Product: '<S69>/Product' */
    forced_choice_B.Product_d = forced_choice_B.sqrtu1u1u2u2 *
      forced_choice_B.TrigonometricFunction_k;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&forced_choice_B.Product_d,
                    &forced_choice_B.DigitalFilter2_b,
                    &forced_choice_DWork.DigitalFilter2_FILT_STATES_g[0],
                    &forced_choice_DWork.DigitalFilter2_CIRCBUFFIDX_b, 11, 1, 1,
                    &forced_choice_P.DigitalFilter2_RTP1COEFF_m[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S68>/Derivative' */
    {
      real_T t = forced_choice_rtM->Timing.t[0];
      real_T timeStampA = forced_choice_DWork.Derivative_RWORK_a.TimeStampA;
      real_T timeStampB = forced_choice_DWork.Derivative_RWORK_a.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        forced_choice_B.Derivative_h = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &forced_choice_DWork.Derivative_RWORK_a.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        forced_choice_B.Derivative_h = (forced_choice_B.DigitalFilter2_b -
          *lastBank++) / deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S68>/dG' */
    forced_choice_B.dG_f = forced_choice_P.dG_Gain_d *
      forced_choice_B.Derivative_h;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&forced_choice_B.dG_f, &forced_choice_B.DigitalFilter_k,
                    &forced_choice_DWork.DigitalFilter_FILT_STATES_d[0],
                    &forced_choice_DWork.DigitalFilter_CIRCBUFFIDX_k, 11, 1, 1,
                    &forced_choice_P.DigitalFilter_RTP1COEFF_p[0], 1);

    {
      real_T tmp;
      real_T tmp_0;

      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S10>/UseTachs'
       */
      if (forced_choice_P.UseTachs_Value >= forced_choice_P.Switch_Threshold) {
        {
          real_T tmp;
          real_T tmp_0;

          /* Gain: '<S10>/TachGain2' */
          forced_choice_B.TachGain2 = forced_choice_P.TachGain2_Gain *
            forced_choice_B.PCI6025EAD_o2;

          /* Gain: '<S10>/TachGain1' */
          forced_choice_B.TachGain1 = forced_choice_P.TachGain1_Gain *
            forced_choice_B.PCI6025EAD_o1;

          /* SignalConversion: '<S10>/TmpHiddenBufferAtMatrix MultiplyInport2' */
          tmp = forced_choice_B.TachGain1;
          tmp_0 = forced_choice_B.TachGain2;
          forced_choice_B.TmpHiddenBufferAtMatrixMultiply[0] = tmp;
          forced_choice_B.TmpHiddenBufferAtMatrixMultiply[1] = tmp_0;
        }

        {
          static const int_T dims[3] = { 2, 2, 1 };

          rt_MatMultRR_Dbl(forced_choice_B.MatrixMultiply,
                           forced_choice_B.MatrixConcatenate2,
                           forced_choice_B.TmpHiddenBufferAtMatrixMultiply,
                           &dims[0]);
        }

        forced_choice_B.Switch[0] = forced_choice_B.MatrixMultiply[0];
        forced_choice_B.Switch[1] = forced_choice_B.MatrixMultiply[1];
      } else {
        tmp = forced_choice_B.DigitalFilter;
        tmp_0 = forced_choice_B.DigitalFilter_k;
        forced_choice_B.Switch[0] = tmp;
        forced_choice_B.Switch[1] = tmp_0;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S43>/Clock'
     */
    forced_choice_B.Clock_p = forced_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S43>/Memory' */
    forced_choice_B.Memory_h = forced_choice_DWork.Memory_PreviousInput_e;

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
      forced_choice_B.RelationalOperator1 || forced_choice_B.RelationalOperator2
      || forced_choice_B.RelationalOperator3);

    /* Logic: '<S5>/InBox' */
    forced_choice_B.InBox = !forced_choice_B.LogicalOperator_h;

    /* Logic: '<S47>/Logical Operator3' */
    forced_choice_B.LogicalOperator3 = !forced_choice_B.InBox;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S47>/Clock'
     */
    forced_choice_B.Clock_l = forced_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S47>/Memory' */
    forced_choice_B.Memory_k = forced_choice_DWork.Memory_PreviousInput_n;

    /* Logic: '<S47>/Logical Operator4' */
    forced_choice_B.LogicalOperator4 = (forced_choice_B.Memory_k &&
      forced_choice_B.LogicalOperator3);

    /* RelationalOperator: '<S36>/Compare' */
    forced_choice_B.Compare_g = (forced_choice_B.Switch[0] == 0.0);

    /* RelationalOperator: '<S37>/Compare' */
    forced_choice_B.Compare_j = (forced_choice_B.Switch[1] == 0.0);

    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Constant: '<S5>/RecenterFlag'
     */
    forced_choice_B.LogicalOperator_f = ((forced_choice_P.RecenterFlag_Value !=
      0.0) && (forced_choice_B.Compare_g != 0U) && (forced_choice_B.Compare_j !=
      0U) && forced_choice_B.LogicalOperator_h);

    /* Logic: '<S47>/Logical Operator2' */
    forced_choice_B.LogicalOperator2_b = (forced_choice_B.LogicalOperator4 ||
      forced_choice_B.LogicalOperator_f);

    /* Logic: '<S47>/Logical Operator1' */
    forced_choice_B.LogicalOperator1_p = !forced_choice_B.LogicalOperator2_b;

    /* SignalConversion: '<S47>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    forced_choice_B.HiddenBuf_InsertedFor_Enabled_b =
      forced_choice_B.LogicalOperator1_p;
  }

  /* SubSystem Block: '<S47>/Enabled Subsystem'
   */
  forced_choice_EnabledSubsystem(tid,
    forced_choice_B.HiddenBuf_InsertedFor_Enabled_b, forced_choice_B.Clock_l,
    &forced_choice_B.EnabledSubsystem_l, &forced_choice_DWork.EnabledSubsystem_l);
  if (tid == 0) {
    /* Sum: '<S47>/Sum' */
    forced_choice_B.Sum_k = forced_choice_B.Clock_l -
      forced_choice_B.EnabledSubsystem_l.In1;

    /* RelationalOperator: '<S60>/Compare' */
    forced_choice_B.Compare_k = (forced_choice_B.Sum_k > 0.0);

    /* RelationalOperator: '<S47>/Relational Operator' incorporates:
     *  Constant: '<S47>/Time'
     */
    forced_choice_B.RelationalOperator_p = (forced_choice_B.Sum_k >
      forced_choice_P.Time_Value_o);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S47>/Logical Operator' */
    forced_choice_B.LogicalOperator_fl = (boolean_T)((forced_choice_B.Compare_k
      != 0U) ^ forced_choice_B.RelationalOperator_p);

    /* RelationalOperator: '<S63>/Compare' */
    forced_choice_B.Compare_gq = (forced_choice_B.LogicalOperator_fl <= FALSE);

    /* UnitDelay: '<S61>/Delay Input1' */
    forced_choice_B.Uk1 = forced_choice_DWork.DelayInput1_DSTATE;

    /* RelationalOperator: '<S61>/FixPt Relational Operator' */
    forced_choice_B.FixPtRelationalOperator = (forced_choice_B.Compare_gq >
      forced_choice_B.Uk1);

    /* Logic: '<S47>/Logical Operator5' */
    forced_choice_B.LogicalOperator5 = (forced_choice_B.LogicalOperator3 &&
      (forced_choice_B.FixPtRelationalOperator != 0U));

    /* Logic: '<S43>/Logical Operator2' */
    forced_choice_B.LogicalOperator2_d = (forced_choice_B.Memory_h ||
      forced_choice_B.LogicalOperator5);

    /* Logic: '<S43>/Logical Operator1' */
    forced_choice_B.LogicalOperator1_h = !forced_choice_B.LogicalOperator2_d;

    /* SignalConversion: '<S43>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    forced_choice_B.HiddenBuf_InsertedFor_Enabled_i =
      forced_choice_B.LogicalOperator1_h;
  }

  /* SubSystem Block: '<S43>/Enabled Subsystem'
   */
  forced_choice_EnabledSubsystem(tid,
    forced_choice_B.HiddenBuf_InsertedFor_Enabled_i, forced_choice_B.Clock_p,
    &forced_choice_B.EnabledSubsystem_h, &forced_choice_DWork.EnabledSubsystem_h);
  if (tid == 0) {
    /* Sum: '<S43>/Sum' */
    forced_choice_B.Sum_a = forced_choice_B.Clock_p -
      forced_choice_B.EnabledSubsystem_h.In1;

    /* RelationalOperator: '<S53>/Compare' */
    forced_choice_B.Compare_i = (forced_choice_B.Sum_a > 0.0);

    /* RelationalOperator: '<S43>/Relational Operator' incorporates:
     *  Constant: '<S43>/Time'
     */
    forced_choice_B.RelationalOperator_n = (forced_choice_B.Sum_a >
      forced_choice_P.Time_Value_n);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S43>/Logical Operator' */
    forced_choice_B.LogicalOperator_p = (boolean_T)((forced_choice_B.Compare_i
      != 0U) ^ forced_choice_B.RelationalOperator_n);

    /* Abs: '<S40>/Abs2' */
    forced_choice_B.Abs2 = fabs(forced_choice_B.Switch[0]);

    /* RelationalOperator: '<S51>/Compare' incorporates:
     *  Constant: '<S51>/Constant'
     */
    forced_choice_B.Compare_f = (forced_choice_B.Abs2 <=
      forced_choice_P.Constant_Value);

    /* Abs: '<S40>/Abs3' */
    forced_choice_B.Abs3 = fabs(forced_choice_B.Switch[1]);

    /* RelationalOperator: '<S52>/Compare' incorporates:
     *  Constant: '<S52>/Constant'
     */
    forced_choice_B.Compare_p = (forced_choice_B.Abs3 <=
      forced_choice_P.Constant_Value_l);

    /* Logic: '<S40>/Logical Operator1' */
    forced_choice_B.LogicalOperator1_e = ((forced_choice_B.Compare_f != 0U) &&
      (forced_choice_B.Compare_p != 0U));

    /* Logic: '<S5>/NOT' */
    forced_choice_B.NOT = !forced_choice_B.LogicalOperator1_e;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S45>/Clock'
     */
    forced_choice_B.Clock_f = forced_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S45>/Memory' */
    forced_choice_B.Memory_ha = forced_choice_DWork.Memory_PreviousInput_eh;

    /* RelationalOperator: '<S59>/Compare' */
    forced_choice_B.Compare_jg = (forced_choice_B.LogicalOperator1_e <= FALSE);

    /* UnitDelay: '<S46>/Delay Input1' */
    forced_choice_B.Uk1_c = forced_choice_DWork.DelayInput1_DSTATE_d;

    /* RelationalOperator: '<S46>/FixPt Relational Operator' */
    forced_choice_B.FixPtRelationalOperator_l = (forced_choice_B.Compare_jg >
      forced_choice_B.Uk1_c);

    /* Logic: '<S45>/Logical Operator2' */
    forced_choice_B.LogicalOperator2_da = (forced_choice_B.Memory_ha ||
      (forced_choice_B.FixPtRelationalOperator_l != 0U));

    /* Logic: '<S45>/Logical Operator1' */
    forced_choice_B.LogicalOperator1_i = !forced_choice_B.LogicalOperator2_da;

    /* SignalConversion: '<S45>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    forced_choice_B.HiddenBuf_InsertedFor_Enabled_g =
      forced_choice_B.LogicalOperator1_i;
  }

  /* SubSystem Block: '<S45>/Enabled Subsystem'
   */
  forced_choice_EnabledSubsystem(tid,
    forced_choice_B.HiddenBuf_InsertedFor_Enabled_g, forced_choice_B.Clock_f,
    &forced_choice_B.EnabledSubsystem_i, &forced_choice_DWork.EnabledSubsystem_i);
  if (tid == 0) {
    /* Sum: '<S45>/Sum' */
    forced_choice_B.Sum_d = forced_choice_B.Clock_f -
      forced_choice_B.EnabledSubsystem_i.In1;

    /* RelationalOperator: '<S57>/Compare' */
    forced_choice_B.Compare_n = (forced_choice_B.Sum_d > 0.0);

    /* RelationalOperator: '<S45>/Relational Operator' incorporates:
     *  Constant: '<S45>/Time'
     */
    forced_choice_B.RelationalOperator_b = (forced_choice_B.Sum_d >
      forced_choice_P.Time_Value_m);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S45>/Logical Operator' */
    forced_choice_B.LogicalOperator_g = (boolean_T)((forced_choice_B.Compare_n
      != 0U) ^ forced_choice_B.RelationalOperator_b);

    /* RelationalOperator: '<S50>/Compare' */
    forced_choice_B.Compare_l = (forced_choice_B.LogicalOperator_g <= FALSE);

    /* UnitDelay: '<S39>/Delay Input1' */
    forced_choice_B.Uk1_k = forced_choice_DWork.DelayInput1_DSTATE_m;

    /* RelationalOperator: '<S39>/FixPt Relational Operator' */
    forced_choice_B.FixPtRelationalOperator_d = (forced_choice_B.Compare_l >
      forced_choice_B.Uk1_k);

    /* DataTypeConversion: '<S5>/Data Type Conversion2' */
    forced_choice_B.DataTypeConversion2 =
      (forced_choice_B.FixPtRelationalOperator_d != 0U);

    /* Logic: '<S5>/Logical Operator1' */
    forced_choice_B.LogicalOperator1_c = (forced_choice_B.NOT ||
      forced_choice_B.DataTypeConversion2);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S44>/Clock'
     */
    forced_choice_B.Clock_b = forced_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S44>/Memory' */
    forced_choice_B.Memory_m = forced_choice_DWork.Memory_PreviousInput_g;

    /* Logic: '<S44>/Logical Operator2' */
    forced_choice_B.LogicalOperator2_e = (forced_choice_B.Memory_m ||
      forced_choice_B.LogicalOperator5);

    /* Logic: '<S44>/Logical Operator1' */
    forced_choice_B.LogicalOperator1_hr = !forced_choice_B.LogicalOperator2_e;

    /* SignalConversion: '<S44>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    forced_choice_B.HiddenBuf_InsertedFor_Enabled_f =
      forced_choice_B.LogicalOperator1_hr;
  }

  /* SubSystem Block: '<S44>/Enabled Subsystem'
   */
  forced_choice_EnabledSubsystem(tid,
    forced_choice_B.HiddenBuf_InsertedFor_Enabled_f, forced_choice_B.Clock_b,
    &forced_choice_B.EnabledSubsystem_hg,
    &forced_choice_DWork.EnabledSubsystem_hg);
  if (tid == 0) {
    /* Sum: '<S44>/Sum' */
    forced_choice_B.Sum_p = forced_choice_B.Clock_b -
      forced_choice_B.EnabledSubsystem_hg.In1;

    /* RelationalOperator: '<S55>/Compare' */
    forced_choice_B.Compare_jc = (forced_choice_B.Sum_p > 0.0);

    /* RelationalOperator: '<S44>/Relational Operator' incorporates:
     *  Constant: '<S44>/Time'
     */
    forced_choice_B.RelationalOperator_pi = (forced_choice_B.Sum_p >
      forced_choice_P.Time_Value_c);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S44>/Logical Operator' */
    forced_choice_B.LogicalOperator_fa = (boolean_T)((forced_choice_B.Compare_jc
      != 0U) ^ forced_choice_B.RelationalOperator_pi);

    /* RelationalOperator: '<S49>/Compare' */
    forced_choice_B.Compare_e = (forced_choice_B.LogicalOperator_fa <= FALSE);

    /* UnitDelay: '<S38>/Delay Input1' */
    forced_choice_B.Uk1_m = forced_choice_DWork.DelayInput1_DSTATE_b;

    /* RelationalOperator: '<S38>/FixPt Relational Operator' */
    forced_choice_B.FixPtRelationalOperator_j = (forced_choice_B.Compare_e >
      forced_choice_B.Uk1_m);

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    forced_choice_B.DataTypeConversion1 =
      (forced_choice_B.FixPtRelationalOperator_j != 0U);

    /* Memory: '<S42>/Memory' */
    forced_choice_B.Memory_f = forced_choice_DWork.Memory_PreviousInput_h;

    /* CombinatorialLogic Block: '<S42>/Logic'
     */
    {
      int_T rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (int_T)(forced_choice_B.LogicalOperator1_c != 0);
      rowidx = (rowidx << 1) + (int_T)(forced_choice_B.DataTypeConversion1 != 0);
      rowidx = (rowidx << 1) + (int_T)(forced_choice_B.Memory_f != 0);

      /* Copy the appropriate row of the table into the block output vector */
      forced_choice_B.Logic[0] = forced_choice_P.Logic_table[rowidx];
      forced_choice_B.Logic[1] = forced_choice_P.Logic_table[rowidx + 8];
    }

    {
      real_T cg_in;
      real_T cg_in_0;
      real_T cg_in_1;
      real_T cg_in_2;
      real_T cg_in_3;
      real_T cg_in_4;
      real_T cg_in_5;
      real_T cg_in_6;
      real_T tmp;
      real_T tmp_0;
      real_T tmp_1;
      real_T tmp_2;
      real_T tmp_3;
      real_T tmp_4;
      real_T tmp_5;
      real_T tmp_6;
      real_T tmp_7;
      real_T tmp_8;
      real_T tmp_9;
      real_T tmp_a;
      real_T tmp_b;
      real_T tmp_c;
      real_T tmp_d;
      real_T tmp_e;

      /* Logic: '<S5>/Logical Operator5' */
      forced_choice_B.LogicalOperator5_h = (forced_choice_B.Logic[1] ||
        forced_choice_B.LogicalOperator_fa || forced_choice_B.LogicalOperator_h);

      /* UnitDelay: '<S23>/x' */
      forced_choice_B.x = forced_choice_DWork.x_DSTATE;

      /* UnitDelay: '<S24>/x' */
      forced_choice_B.x_h = forced_choice_DWork.x_DSTATE_h;

      /* Sum: '<S21>/Add' */
      forced_choice_B.Add = forced_choice_B.x - forced_choice_B.x_h;

      /* UnitDelay: '<S25>/x' */
      forced_choice_B.x_m = forced_choice_DWork.x_DSTATE_g;

      /* UnitDelay: '<S26>/x' */
      forced_choice_B.x_ho = forced_choice_DWork.x_DSTATE_e;

      /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
       *  Constant: '<S3>/Load'
       *  Constant: '<S3>/Off'
       *  Constant: '<S3>/staticX'
       *  Constant: '<S3>/staticY'
       */
      switch ((int32_T)forced_choice_P.Load_Value) {
       case 0:
        tmp = forced_choice_P.Off_Value_j;
        tmp_0 = forced_choice_P.Off_Value_j;
        forced_choice_B.MultiportSwitch[0] = tmp;
        forced_choice_B.MultiportSwitch[1] = tmp_0;
        break;

       case 1:
        tmp_1 = forced_choice_P.staticX_Value_i;
        tmp_2 = forced_choice_P.staticY_Value_o;
        forced_choice_B.MultiportSwitch[0] = tmp_1;
        forced_choice_B.MultiportSwitch[1] = tmp_2;
        break;

       case 2:
        /* Sum: '<S21>/Add1' */
        forced_choice_B.Add1_c = forced_choice_B.x_m - forced_choice_B.x_ho;

        /* Gain: '<S3>/LorentzForceGain' */
        tmp_7 = forced_choice_B.Add;
        tmp_8 = forced_choice_B.Add1_c;
        forced_choice_B.LorentzForceGain[0] =
          forced_choice_P.LorentzForceGain_Gain_m * tmp_7;
        forced_choice_B.LorentzForceGain[1] =
          forced_choice_P.LorentzForceGain_Gain_m * tmp_8;
        forced_choice_B.MultiportSwitch[0] = forced_choice_B.LorentzForceGain[0];
        forced_choice_B.MultiportSwitch[1] = forced_choice_B.LorentzForceGain[1];
        break;

       default:
        /* MultiPortSwitch: '<S3>/dynamicAngle Switch' incorporates:
         *  Constant: '<S3>/DynamicAngle'
         *  Constant: '<S3>/visAngle'
         */
        if ((int32_T)forced_choice_P.DynamicAngle_Value_c == 0) {
          forced_choice_B.dynamicAngleSwitch = forced_choice_P.visAngle_Value_i;
        } else {
          /* Gain: '<S3>/Gain' */
          forced_choice_B.Gain_e = forced_choice_P.Gain_Gain_d *
            forced_choice_B.Add;
          forced_choice_B.dynamicAngleSwitch = forced_choice_B.Gain_e;
        }

        /* Trigonometry: '<S22>/sin' */
        forced_choice_B.sin_c = sin(forced_choice_B.dynamicAngleSwitch);

        /* Gain: '<S22>/Inverter' */
        forced_choice_B.Inverter[0] = forced_choice_P.Inverter_Gain_l *
          forced_choice_B.Switch[0];
        forced_choice_B.Inverter[1] = forced_choice_P.Inverter_Gain_l *
          forced_choice_B.Switch[1];

        /* Product: '<S22>/Product3' */
        cg_in = forced_choice_B.Inverter[0];
        forced_choice_B.Product3_g = cg_in * forced_choice_B.sin_c;

        /* Trigonometry: '<S22>/cos' */
        forced_choice_B.cos_n = cos(forced_choice_B.dynamicAngleSwitch);

        /* Product: '<S22>/Product2' */
        cg_in_0 = forced_choice_B.Inverter[1];
        forced_choice_B.Product2_p = cg_in_0 * forced_choice_B.cos_n;

        /* Sum: '<S22>/Subtract' */
        forced_choice_B.Subtract_b = forced_choice_B.Product2_p -
          forced_choice_B.Product3_g;

        /* Product: '<S22>/Product1' */
        cg_in_1 = forced_choice_B.Inverter[1];
        forced_choice_B.Product1_h = cg_in_1 * forced_choice_B.sin_c;

        /* Product: '<S22>/Product' */
        cg_in_2 = forced_choice_B.Inverter[0];
        forced_choice_B.Product_h = cg_in_2 * forced_choice_B.cos_n;

        /* Sum: '<S22>/Add' */
        forced_choice_B.Add_f = forced_choice_B.Product_h +
          forced_choice_B.Product1_h;

        /* Gain: '<S22>/Gain' */
        tmp_9 = forced_choice_B.Add_f;
        tmp_a = forced_choice_B.Subtract_b;
        forced_choice_B.Gain_l[0] = forced_choice_P.Gain_Gain_mk * tmp_9;
        forced_choice_B.Gain_l[1] = forced_choice_P.Gain_Gain_mk * tmp_a;
        forced_choice_B.MultiportSwitch[0] = forced_choice_B.Gain_l[0];
        forced_choice_B.MultiportSwitch[1] = forced_choice_B.Gain_l[1];
        break;
      }

      /* UnitDelay: '<S17>/x' */
      forced_choice_B.x_o = forced_choice_DWork.x_DSTATE_k;

      /* UnitDelay: '<S18>/x' */
      forced_choice_B.x_of = forced_choice_DWork.x_DSTATE_en;

      /* Sum: '<S15>/Add' */
      forced_choice_B.Add_c = forced_choice_B.x_o - forced_choice_B.x_of;

      /* UnitDelay: '<S19>/x' */
      forced_choice_B.x_n = forced_choice_DWork.x_DSTATE_b;

      /* UnitDelay: '<S20>/x' */
      forced_choice_B.x_p = forced_choice_DWork.x_DSTATE_d;

      /* MultiPortSwitch: '<S2>/LoadSelect Switch' incorporates:
       *  Constant: '<S2>/Load'
       *  Constant: '<S2>/Off'
       *  Constant: '<S2>/staticX'
       *  Constant: '<S2>/staticY'
       */
      switch ((int32_T)forced_choice_P.Load_Value_d) {
       case 0:
        tmp_3 = forced_choice_P.Off_Value;
        tmp_4 = forced_choice_P.Off_Value;
        forced_choice_B.LoadSelectSwitch[0] = tmp_3;
        forced_choice_B.LoadSelectSwitch[1] = tmp_4;
        break;

       case 1:
        tmp_5 = forced_choice_P.staticX_Value;
        tmp_6 = forced_choice_P.staticY_Value;
        forced_choice_B.LoadSelectSwitch[0] = tmp_5;
        forced_choice_B.LoadSelectSwitch[1] = tmp_6;
        break;

       case 2:
        /* Sum: '<S15>/Add1' */
        forced_choice_B.Add1_cy = forced_choice_B.x_n - forced_choice_B.x_p;

        /* Gain: '<S2>/LorentzForceGain' */
        tmp_b = forced_choice_B.Add_c;
        tmp_c = forced_choice_B.Add1_cy;
        forced_choice_B.LorentzForceGain_f[0] =
          forced_choice_P.LorentzForceGain_Gain * tmp_b;
        forced_choice_B.LorentzForceGain_f[1] =
          forced_choice_P.LorentzForceGain_Gain * tmp_c;
        forced_choice_B.LoadSelectSwitch[0] = forced_choice_B.LorentzForceGain_f
          [0];
        forced_choice_B.LoadSelectSwitch[1] = forced_choice_B.LorentzForceGain_f
          [1];
        break;

       default:
        /* MultiPortSwitch: '<S2>/DynamicAngle Switch' incorporates:
         *  Constant: '<S2>/DynamicAngle'
         *  Constant: '<S2>/visAngle'
         */
        if ((int32_T)forced_choice_P.DynamicAngle_Value == 0) {
          forced_choice_B.DynamicAngleSwitch = forced_choice_P.visAngle_Value;
        } else {
          /* Gain: '<S2>/Gain' */
          forced_choice_B.Gain_ii = forced_choice_P.Gain_Gain_n *
            forced_choice_B.Add_c;
          forced_choice_B.DynamicAngleSwitch = forced_choice_B.Gain_ii;
        }

        /* Trigonometry: '<S16>/sin' */
        forced_choice_B.sin_h = sin(forced_choice_B.DynamicAngleSwitch);

        /* Gain: '<S16>/Inverter' */
        forced_choice_B.Inverter_f[0] = forced_choice_P.Inverter_Gain *
          forced_choice_B.Switch[0];
        forced_choice_B.Inverter_f[1] = forced_choice_P.Inverter_Gain *
          forced_choice_B.Switch[1];

        /* Product: '<S16>/Product3' */
        cg_in_3 = forced_choice_B.Inverter_f[0];
        forced_choice_B.Product3_c = cg_in_3 * forced_choice_B.sin_h;

        /* Trigonometry: '<S16>/cos' */
        forced_choice_B.cos_i = cos(forced_choice_B.DynamicAngleSwitch);

        /* Product: '<S16>/Product2' */
        cg_in_4 = forced_choice_B.Inverter_f[1];
        forced_choice_B.Product2_k = cg_in_4 * forced_choice_B.cos_i;

        /* Sum: '<S16>/Subtract' */
        forced_choice_B.Subtract_n = forced_choice_B.Product2_k -
          forced_choice_B.Product3_c;

        /* Product: '<S16>/Product1' */
        cg_in_5 = forced_choice_B.Inverter_f[1];
        forced_choice_B.Product1_l = cg_in_5 * forced_choice_B.sin_h;

        /* Product: '<S16>/Product' */
        cg_in_6 = forced_choice_B.Inverter_f[0];
        forced_choice_B.Product_p = cg_in_6 * forced_choice_B.cos_i;

        /* Sum: '<S16>/Add' */
        forced_choice_B.Add_cv = forced_choice_B.Product_p +
          forced_choice_B.Product1_l;

        /* Gain: '<S16>/Gain' */
        tmp_d = forced_choice_B.Add_cv;
        tmp_e = forced_choice_B.Subtract_n;
        forced_choice_B.Gain_j[0] = forced_choice_P.Gain_Gain_l * tmp_d;
        forced_choice_B.Gain_j[1] = forced_choice_P.Gain_Gain_l * tmp_e;
        forced_choice_B.LoadSelectSwitch[0] = forced_choice_B.Gain_j[0];
        forced_choice_B.LoadSelectSwitch[1] = forced_choice_B.Gain_j[1];
        break;
      }
    }

    /* Level2 S-Function Block: '<Root>/Behavior FC' (mastercon_fc) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[11];
      sfcnOutputs(rts, 1);
    }

    {
      real_T rtsaturate_U0DataInY0Container;
      real_T rtsaturate_U0DataInY0Containe_0;
      real_T tmp;
      real_T tmp_0;
      real_T tmp_1;
      real_T tmp_2;

      /* Switch: '<S4>/Switch2' incorporates:
       *  Constant: '<S4>/zeroX'
       *  Constant: '<S4>/zeroY'
       */
      if (forced_choice_B.LogicalOperator) {
        tmp = forced_choice_P.zeroX_Value;
        tmp_0 = forced_choice_P.zeroY_Value;
        forced_choice_B.Switch2[0] = tmp;
        forced_choice_B.Switch2[1] = tmp_0;
      } else {
        /* Switch: '<S4>/Switch1' */
        if (forced_choice_B.LogicalOperator5_h) {
          /* Logic: '<S5>/Logical Operator6' */
          forced_choice_B.LogicalOperator6 = !forced_choice_B.LogicalOperator_p;

          /* Logic: '<S5>/Logical Operator3' */
          forced_choice_B.LogicalOperator3_j = (forced_choice_B.LogicalOperator6
            && forced_choice_B.LogicalOperator_h);

          /* Switch: '<S5>/Switch' */
          if (forced_choice_B.LogicalOperator3_j) {
            /* Gain: '<S5>/Bounding Box Viscosity' */
            forced_choice_B.BoundingBoxViscosity[0] =
              forced_choice_P.BoundingBoxViscosity_Gain * forced_choice_B.Switch
              [0];
            forced_choice_B.BoundingBoxViscosity[1] =
              forced_choice_P.BoundingBoxViscosity_Gain * forced_choice_B.Switch
              [1];
            forced_choice_B.Switch_c[0] = forced_choice_B.BoundingBoxViscosity[0];
            forced_choice_B.Switch_c[1] = forced_choice_B.BoundingBoxViscosity[1];
          } else {
            /* Product: '<S41>/Product' */
            forced_choice_B.Product_g = (int32_T)
              forced_choice_B.LogicalOperator_p ? forced_choice_B.Product1_d :
              0.0;

            /* Gain: '<S41>/Gain1' */
            forced_choice_B.Gain1_m = forced_choice_P.Gain1_Gain_k *
              forced_choice_B.Product_g;

            /* Gain: '<S41>/Gain3' */
            forced_choice_B.Gain3 = forced_choice_P.Gain3_Gain *
              forced_choice_B.Switch[0];

            /* Sum: '<S41>/Add' */
            forced_choice_B.Add_j = forced_choice_B.Gain3 +
              forced_choice_B.Gain1_m;

            /* Saturate: '<S41>/Saturation' */
            rtsaturate_U0DataInY0Container = rt_SATURATE(forced_choice_B.Add_j,
              forced_choice_P.Saturation_LowerSat,
              forced_choice_P.Saturation_UpperSat);
            forced_choice_B.Saturation = rtsaturate_U0DataInY0Container;

            /* Gain: '<S41>/Gain4' */
            forced_choice_B.Gain4 = forced_choice_P.Gain4_Gain *
              forced_choice_B.Switch[1];

            /* Product: '<S41>/Product1' */
            forced_choice_B.Product1_m = (int32_T)
              forced_choice_B.LogicalOperator_p ? forced_choice_B.Product_d :
              0.0;

            /* Gain: '<S41>/Gain2' */
            forced_choice_B.Gain2 = forced_choice_P.Gain2_Gain_f *
              forced_choice_B.Product1_m;

            /* Sum: '<S41>/Add1' */
            forced_choice_B.Add1_p = forced_choice_B.Gain2 +
              forced_choice_B.Gain4;

            /* Saturate: '<S41>/Saturation1' */
            rtsaturate_U0DataInY0Containe_0 = rt_SATURATE(forced_choice_B.Add1_p,
              forced_choice_P.Saturation1_LowerSat,
              forced_choice_P.Saturation1_UpperSat);
            forced_choice_B.Saturation1 = rtsaturate_U0DataInY0Containe_0;
            tmp_1 = forced_choice_B.Saturation;
            tmp_2 = forced_choice_B.Saturation1;
            forced_choice_B.Switch_c[0] = tmp_1;
            forced_choice_B.Switch_c[1] = tmp_2;
          }

          forced_choice_B.Switch1[0] = forced_choice_B.Switch_c[0];
          forced_choice_B.Switch1[1] = forced_choice_B.Switch_c[1];
        } else {
          forced_choice_B.Switch1[0] = forced_choice_B.BehaviorFC_o1[0];
          forced_choice_B.Switch1[1] = forced_choice_B.BehaviorFC_o1[1];
        }

        forced_choice_B.Switch2[0] = forced_choice_B.Switch1[0];
        forced_choice_B.Switch2[1] = forced_choice_B.Switch1[1];
      }

      /* Output and update for atomic system: '<S4>/Force//Torque Transform' */

      /* Gain: '<S29>/Gain' */
      forced_choice_B.Gain_i[0] = forced_choice_P.Gain_Gain_a *
        forced_choice_B.Switch2[0];
      forced_choice_B.Gain_i[1] = forced_choice_P.Gain_Gain_a *
        forced_choice_B.Switch2[1];

      /* Math Block: '<S33>/Math Function'
       */
      /* Operator : transpose */
      {
        uint32_T count = 0;
        uint32_T row;
        uint32_T col;
        for (row= 0; row < 2; row++) {
          for (col= 0; col < 2; col++) {
            forced_choice_B.MathFunction[row + 2 * col] =
              forced_choice_B.MatrixConcatenate2[count];
            count++;
          }
        }
      }

      {
        static const int_T dims[3] = { 2, 2, 1 };

        rt_MatMultRR_Dbl(forced_choice_B.MatrixMultiply_f,
                         forced_choice_B.MathFunction,
                         forced_choice_B.Gain_i, &dims[0]);
      }

      /* Gain: '<S4>/MG1' */
      forced_choice_B.MG1 = forced_choice_P.MG1_Gain *
        forced_choice_B.MatrixMultiply_f[0];

      /* Gain: '<S4>/MG2' */
      forced_choice_B.MG2 = forced_choice_P.MG2_Gain *
        forced_choice_B.MatrixMultiply_f[1];
    }

    /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[12];
      sfcnOutputs(rts, 1);
    }

    /* ok to acquire for <S30>/S-Function */
    forced_choice_DWork.SFunction_IWORK.AcquireOK = 1;

    /* ok to acquire for <S32>/S-Function */
    forced_choice_DWork.SFunction_IWORK_g.AcquireOK = 1;

    /* RelationalOperator: '<S27>/Compare' incorporates:
     *  Constant: '<S27>/Constant'
     */
    forced_choice_B.Compare_m = (forced_choice_B.MG1 >
      forced_choice_P.Constant_Value_o);

    /* RelationalOperator: '<S28>/Compare' incorporates:
     *  Constant: '<S28>/Constant'
     */
    forced_choice_B.Compare_d = (forced_choice_B.MG2 >
      forced_choice_P.Constant_Value_l0);

    /* SignalConversion: '<S4>/ConcatHiddenBufferAtMatrix ConcatenationInPort0' */
    forced_choice_B.MatrixConcatenation[0] = forced_choice_B.LogicalOperator5_h;

    /* SignalConversion: '<S4>/ConcatHiddenBufferAtMatrix ConcatenationInPort1' */
    forced_choice_B.MatrixConcatenation[1] = forced_choice_B.LogicalOperator;

    /* Logic: '<S4>/Logical Operator1' */
    forced_choice_B.LogicalOperator1_g = ((forced_choice_B.Compare_m != 0U) ||
      (forced_choice_B.Compare_d != 0U));

    /* ok to acquire for <S7>/S-Function */
    forced_choice_DWork.SFunction_IWORK_f.AcquireOK = 1;

    /* Pack: <S9>/Pack */
    (void) memcpy(forced_choice_B.Pack,&forced_choice_B.BehaviorFC_o8[0],
                  8);
    (void) memcpy(&forced_choice_B.Pack[8],&forced_choice_B.BehaviorFC_o8[1],
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

    /* RateTransition: '<S9>/Rate Transition' */
    if (tid == 0 && forced_choice_rtM->Timing.RateInteraction.TID1_2) {
      for (i = 0; i < 112; i++) {
        forced_choice_B.RateTransition[i] = forced_choice_B.Pack[i];
      }
    }
  }

  if (tid == 2) {                      /* Sample time: [0.02s, 0.0s] */
    /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[13];
      sfcnOutputs(rts, 2);
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* ok to acquire for <S11>/S-Function */
    forced_choice_DWork.SFunction_IWORK_gk.AcquireOK = 1;

    /* ok to acquire for <S14>/S-Function */
    forced_choice_DWork.SFunction_IWORK_i.AcquireOK = 1;

    /* ok to acquire for <S48>/S-Function */
    forced_choice_DWork.SFunction_IWORK_n.AcquireOK = 1;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S65>/Clock'
     */
    forced_choice_B.Clock_i = forced_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* SignalConversion: '<S65>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    forced_choice_B.HiddenBuf_InsertedFor_Sampleand =
      forced_choice_B.BehaviorFC_o5;
  }

  /* SubSystem Block: '<S65>/Sample and Hold'
   */
  if (tid == 0) {
    forced_choice_SampleandHold(forced_choice_B.HiddenBuf_InsertedFor_Sampleand,
      forced_choice_B.Clock_i, &forced_choice_B.SampleandHold,
      &forced_choice_DWork.SampleandHold,
      &forced_choice_PrevZCSigState.SampleandHold);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Sum: '<S65>/Sum' */
    forced_choice_B.Sum_f5 = forced_choice_B.Clock_i -
      forced_choice_B.SampleandHold.In;
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* UniformRandomNumber Block: '<S6>/Uniform Random Number'
     */
    forced_choice_B.UniformRandomNumber =
      forced_choice_DWork.UniformRandomNumber_RWORK.NextOutput;

    /* RelationalOperator: '<S6>/Relational Operator' incorporates:
     *  Constant: '<S6>/JackpotChance'
     */
    forced_choice_B.RelationalOperator_f = (forced_choice_B.UniformRandomNumber >
      forced_choice_P.JackpotChance_Value);

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/RewardJackpot'
     *  Constant: '<S6>/RewardTime'
     */
    if (forced_choice_B.RelationalOperator_f) {
      forced_choice_B.Switch_n = forced_choice_P.RewardTime_Value;
    } else {
      forced_choice_B.Switch_n = forced_choice_P.RewardJackpot_Value;
    }

    /* SignalConversion: '<S6>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    forced_choice_B.HiddenBuf_InsertedFor_Samplea_o =
      forced_choice_B.BehaviorFC_o5;
  }

  /* SubSystem Block: '<S6>/Sample and Hold'
   */
  if (tid == 0) {
    forced_choice_SampleandHold(forced_choice_B.HiddenBuf_InsertedFor_Samplea_o,
      forced_choice_B.Switch_n, &forced_choice_B.SampleandHold_i,
      &forced_choice_DWork.SampleandHold_i,
      &forced_choice_PrevZCSigState.SampleandHold_i);
  }

  {
    int32_T s70_iter;
    real_T tmp;
    real_T tmp_0;
    if (tid == 0) {
      /* RelationalOperator: '<S65>/Relational Operator' */
      forced_choice_B.RelationalOperator_c = (forced_choice_B.Sum_f5 <
        forced_choice_B.SampleandHold_i.In);

      /* DataTypeConversion: '<S6>/Data Type Conversion' */
      forced_choice_B.DataTypeConversion = (real_T)
        forced_choice_B.RelationalOperator_c;
    }

    if (tid == 0) {
      for (s70_iter = 0; s70_iter < 4; s70_iter++) {
        forced_choice_B.ForIterator = (real_T)s70_iter;

        /* Output and update for iterator system: '<S13>/For Iterator Subsystem' */

        /* Switch: '<S70>/Switch' incorporates:
         *  Constant: '<S70>/Constant2'
         */
        if (forced_choice_B.ForIterator >= forced_choice_P.Switch_Threshold_n) {
          forced_choice_B.Switch_e = forced_choice_B.BehaviorFC_o3;
        } else {
          forced_choice_B.Switch_e = forced_choice_P.Constant2_Value;
        }

        /* Level2 S-Function Block: '<S70>/ToBits1' (Byte2Bits) */
        {
          SimStruct *rts = forced_choice_rtM->childSfunctions[2];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
        {
          SimStruct *rts = forced_choice_rtM->childSfunctions[3];
          sfcnOutputs(rts, 1);
        }

        /* Sum: '<S70>/Add' incorporates:
         *  Constant: '<S70>/Constant'
         */
        forced_choice_B.Add_i = forced_choice_B.PCIQUAD04 +
          forced_choice_P.Constant_Value_i;

        /* Sum: '<S70>/Add1' incorporates:
         *  Constant: '<S70>/Constant'
         */
        forced_choice_B.Add1_k0 = forced_choice_B.PCIQUAD041 +
          forced_choice_P.Constant_Value_i;

        /* Level2 S-Function Block: '<S70>/SerialConverter' (serPos) */
        {
          SimStruct *rts = forced_choice_rtM->childSfunctions[4];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/ToBits' (Byte2Bits) */
        {
          SimStruct *rts = forced_choice_rtM->childSfunctions[5];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
        {
          SimStruct *rts = forced_choice_rtM->childSfunctions[6];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/xPC Target  Time ' (xpctimeinfo) */
        {
          SimStruct *rts = forced_choice_rtM->childSfunctions[7];
          sfcnOutputs(rts, 1);
        }

        do {
          /* Output and update for iterator system: '<S70>/While Iterator Subsystem' */

          /* Level2 S-Function Block: '<S72>/xPC Target  Time ' (xpctimeinfo) */
          {
            SimStruct *rts = forced_choice_rtM->childSfunctions[0];
            sfcnOutputs(rts, 1);
          }

          /* Sum: '<S72>/Subtract' */
          forced_choice_B.Subtract = forced_choice_B.xPCTargetTime_n -
            forced_choice_B.xPCTargetTime;

          /* Gain: '<S72>/ScaleTouSec' */
          forced_choice_B.ScaleTouSec = forced_choice_P.ScaleTouSec_Gain *
            forced_choice_B.Subtract;

          /* RelationalOperator: '<S74>/Compare' incorporates:
           *  Constant: '<S74>/Constant'
           */
          forced_choice_B.Compare_pl = (forced_choice_B.ScaleTouSec >
            forced_choice_P.Constant_Value_m);

          /* Switch: '<S72>/Switch' incorporates:
           *  Constant: '<S72>/Constant'
           *  Constant: '<S72>/Constant1'
           */
          if (forced_choice_B.Compare_pl) {
            forced_choice_B.Switch_m = forced_choice_P.Constant_Value_h;
          } else {
            forced_choice_B.Switch_m = forced_choice_P.Constant1_Value;
          }

          /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
          {
            SimStruct *rts = forced_choice_rtM->childSfunctions[1];
            sfcnOutputs(rts, 1);
          }

          /* RelationalOperator: '<S73>/Compare' incorporates:
           *  Constant: '<S73>/Constant'
           */
          forced_choice_B.Compare_a = (forced_choice_B.ScaleTouSec <=
            forced_choice_P.Constant_Value_m2);
        } while (forced_choice_B.Compare_a);
      }

      /* UnitDelay: '<S17>/y' */
      forced_choice_B.y = forced_choice_DWork.y_DSTATE;

      /* Sum: '<S17>/Add1' */
      forced_choice_B.Add1 = forced_choice_B.y - forced_choice_B.x_o;

      /* UnitDelay: '<S17>/z' */
      forced_choice_B.z = forced_choice_DWork.z_DSTATE;

      /* Sum: '<S17>/Add3' incorporates:
       *  Constant: '<S17>/rho'
       */
      forced_choice_B.Add3 = forced_choice_P.rho_Value - forced_choice_B.z;

      /* Product: '<S17>/product2' */
      forced_choice_B.product2 = forced_choice_B.x_o * forced_choice_B.Add3;

      /* Sum: '<S17>/Add2' */
      forced_choice_B.Add2 = forced_choice_B.product2 - forced_choice_B.y;

      /* Product: '<S17>/product3' incorporates:
       *  Constant: '<S17>/beta'
       */
      forced_choice_B.product3 = forced_choice_B.z * forced_choice_P.beta_Value;

      /* Product: '<S17>/product4' */
      forced_choice_B.product4 = forced_choice_B.y * forced_choice_B.x_o;

      /* Sum: '<S17>/Add4' */
      forced_choice_B.Add4 = forced_choice_B.product4 - forced_choice_B.product3;

      /* Product: '<S17>/product1' incorporates:
       *  Constant: '<S17>/sigma'
       */
      forced_choice_B.product1 = forced_choice_B.Add1 *
        forced_choice_P.sigma_Value;

      /* Product: '<S17>/dX' incorporates:
       *  Constant: '<S17>/timescale'
       */
      forced_choice_B.dX = forced_choice_P.timescale_Value *
        forced_choice_B.product1;

      /* Sum: '<S17>/AddX' */
      forced_choice_B.AddX = forced_choice_B.x_o + forced_choice_B.dX;

      /* Product: '<S17>/dY' incorporates:
       *  Constant: '<S17>/timescale'
       */
      forced_choice_B.dY = forced_choice_P.timescale_Value *
        forced_choice_B.Add2;

      /* Sum: '<S17>/AddX1' */
      forced_choice_B.AddX1 = forced_choice_B.y + forced_choice_B.dY;

      /* Product: '<S17>/dZ' incorporates:
       *  Constant: '<S17>/timescale'
       */
      forced_choice_B.dZ = forced_choice_P.timescale_Value *
        forced_choice_B.Add4;

      /* Sum: '<S17>/AddX2' */
      forced_choice_B.AddX2 = forced_choice_B.z + forced_choice_B.dZ;

      /* UnitDelay: '<S18>/y' */
      forced_choice_B.y_i = forced_choice_DWork.y_DSTATE_n;

      /* Sum: '<S18>/Add1' */
      forced_choice_B.Add1_k = forced_choice_B.y_i - forced_choice_B.x_of;

      /* UnitDelay: '<S18>/z' */
      forced_choice_B.z_e = forced_choice_DWork.z_DSTATE_g;

      /* Sum: '<S18>/Add3' incorporates:
       *  Constant: '<S18>/rho'
       */
      forced_choice_B.Add3_m = forced_choice_P.rho_Value_e - forced_choice_B.z_e;

      /* Product: '<S18>/product2' */
      forced_choice_B.product2_m = forced_choice_B.x_of * forced_choice_B.Add3_m;

      /* Sum: '<S18>/Add2' */
      forced_choice_B.Add2_p = forced_choice_B.product2_m - forced_choice_B.y_i;

      /* Product: '<S18>/product3' incorporates:
       *  Constant: '<S18>/beta'
       */
      forced_choice_B.product3_j = forced_choice_B.z_e *
        forced_choice_P.beta_Value_g;

      /* Product: '<S18>/product4' */
      forced_choice_B.product4_l = forced_choice_B.y_i * forced_choice_B.x_of;

      /* Sum: '<S18>/Add4' */
      forced_choice_B.Add4_d = forced_choice_B.product4_l -
        forced_choice_B.product3_j;

      /* Product: '<S18>/product1' incorporates:
       *  Constant: '<S18>/sigma'
       */
      forced_choice_B.product1_h = forced_choice_B.Add1_k *
        forced_choice_P.sigma_Value_b;

      /* Product: '<S18>/dX' incorporates:
       *  Constant: '<S18>/timescale'
       */
      forced_choice_B.dX_c = forced_choice_P.timescale_Value_e *
        forced_choice_B.product1_h;

      /* Sum: '<S18>/AddX' */
      forced_choice_B.AddX_h = forced_choice_B.x_of + forced_choice_B.dX_c;

      /* Product: '<S18>/dY' incorporates:
       *  Constant: '<S18>/timescale'
       */
      forced_choice_B.dY_j = forced_choice_P.timescale_Value_e *
        forced_choice_B.Add2_p;

      /* Sum: '<S18>/AddX1' */
      forced_choice_B.AddX1_a = forced_choice_B.y_i + forced_choice_B.dY_j;

      /* Product: '<S18>/dZ' incorporates:
       *  Constant: '<S18>/timescale'
       */
      forced_choice_B.dZ_k = forced_choice_P.timescale_Value_e *
        forced_choice_B.Add4_d;

      /* Sum: '<S18>/AddX2' */
      forced_choice_B.AddX2_f = forced_choice_B.z_e + forced_choice_B.dZ_k;

      /* UnitDelay: '<S19>/y' */
      forced_choice_B.y_k = forced_choice_DWork.y_DSTATE_h;

      /* Sum: '<S19>/Add1' */
      forced_choice_B.Add1_l = forced_choice_B.y_k - forced_choice_B.x_n;

      /* UnitDelay: '<S19>/z' */
      forced_choice_B.z_h = forced_choice_DWork.z_DSTATE_m;

      /* Sum: '<S19>/Add3' incorporates:
       *  Constant: '<S19>/rho'
       */
      forced_choice_B.Add3_i = forced_choice_P.rho_Value_k - forced_choice_B.z_h;

      /* Product: '<S19>/product2' */
      forced_choice_B.product2_g = forced_choice_B.x_n * forced_choice_B.Add3_i;

      /* Sum: '<S19>/Add2' */
      forced_choice_B.Add2_c = forced_choice_B.product2_g - forced_choice_B.y_k;

      /* Product: '<S19>/product3' incorporates:
       *  Constant: '<S19>/beta'
       */
      forced_choice_B.product3_k = forced_choice_B.z_h *
        forced_choice_P.beta_Value_h;

      /* Product: '<S19>/product4' */
      forced_choice_B.product4_h = forced_choice_B.y_k * forced_choice_B.x_n;

      /* Sum: '<S19>/Add4' */
      forced_choice_B.Add4_i = forced_choice_B.product4_h -
        forced_choice_B.product3_k;

      /* Product: '<S19>/product1' incorporates:
       *  Constant: '<S19>/sigma'
       */
      forced_choice_B.product1_b = forced_choice_B.Add1_l *
        forced_choice_P.sigma_Value_g;

      /* Product: '<S19>/dX' incorporates:
       *  Constant: '<S19>/timescale'
       */
      forced_choice_B.dX_h = forced_choice_P.timescale_Value_m *
        forced_choice_B.product1_b;

      /* Sum: '<S19>/AddX' */
      forced_choice_B.AddX_e = forced_choice_B.x_n + forced_choice_B.dX_h;

      /* Product: '<S19>/dY' incorporates:
       *  Constant: '<S19>/timescale'
       */
      forced_choice_B.dY_o = forced_choice_P.timescale_Value_m *
        forced_choice_B.Add2_c;

      /* Sum: '<S19>/AddX1' */
      forced_choice_B.AddX1_g = forced_choice_B.y_k + forced_choice_B.dY_o;

      /* Product: '<S19>/dZ' incorporates:
       *  Constant: '<S19>/timescale'
       */
      forced_choice_B.dZ_m = forced_choice_P.timescale_Value_m *
        forced_choice_B.Add4_i;

      /* Sum: '<S19>/AddX2' */
      forced_choice_B.AddX2_m = forced_choice_B.z_h + forced_choice_B.dZ_m;

      /* UnitDelay: '<S20>/y' */
      forced_choice_B.y_a = forced_choice_DWork.y_DSTATE_f;

      /* Sum: '<S20>/Add1' */
      forced_choice_B.Add1_ld = forced_choice_B.y_a - forced_choice_B.x_p;

      /* UnitDelay: '<S20>/z' */
      forced_choice_B.z_a = forced_choice_DWork.z_DSTATE_f;

      /* Sum: '<S20>/Add3' incorporates:
       *  Constant: '<S20>/rho'
       */
      forced_choice_B.Add3_o = forced_choice_P.rho_Value_d - forced_choice_B.z_a;

      /* Product: '<S20>/product2' */
      forced_choice_B.product2_n = forced_choice_B.x_p * forced_choice_B.Add3_o;

      /* Sum: '<S20>/Add2' */
      forced_choice_B.Add2_f = forced_choice_B.product2_n - forced_choice_B.y_a;

      /* Product: '<S20>/product3' incorporates:
       *  Constant: '<S20>/beta'
       */
      forced_choice_B.product3_ji = forced_choice_B.z_a *
        forced_choice_P.beta_Value_i;

      /* Product: '<S20>/product4' */
      forced_choice_B.product4_o = forced_choice_B.y_a * forced_choice_B.x_p;

      /* Sum: '<S20>/Add4' */
      forced_choice_B.Add4_h = forced_choice_B.product4_o -
        forced_choice_B.product3_ji;

      /* Product: '<S20>/product1' incorporates:
       *  Constant: '<S20>/sigma'
       */
      forced_choice_B.product1_o = forced_choice_B.Add1_ld *
        forced_choice_P.sigma_Value_k;

      /* Product: '<S20>/dX' incorporates:
       *  Constant: '<S20>/timescale'
       */
      forced_choice_B.dX_i = forced_choice_P.timescale_Value_b *
        forced_choice_B.product1_o;

      /* Sum: '<S20>/AddX' */
      forced_choice_B.AddX_k = forced_choice_B.x_p + forced_choice_B.dX_i;

      /* Product: '<S20>/dY' incorporates:
       *  Constant: '<S20>/timescale'
       */
      forced_choice_B.dY_k = forced_choice_P.timescale_Value_b *
        forced_choice_B.Add2_f;

      /* Sum: '<S20>/AddX1' */
      forced_choice_B.AddX1_c = forced_choice_B.y_a + forced_choice_B.dY_k;

      /* Product: '<S20>/dZ' incorporates:
       *  Constant: '<S20>/timescale'
       */
      forced_choice_B.dZ_mc = forced_choice_P.timescale_Value_b *
        forced_choice_B.Add4_h;

      /* Sum: '<S20>/AddX2' */
      forced_choice_B.AddX2_d = forced_choice_B.z_a + forced_choice_B.dZ_mc;

      /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix Concatenation1InPort0' */
      tmp = forced_choice_B.Product1_d;
      tmp_0 = forced_choice_B.Product_d;
      forced_choice_B.MatrixConcatenation1[0] = tmp;
      forced_choice_B.MatrixConcatenation1[1] = tmp_0;

      /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix Concatenation1InPort1' */
      forced_choice_B.MatrixConcatenation1[2] = forced_choice_B.Switch[0];
      forced_choice_B.MatrixConcatenation1[3] = forced_choice_B.Switch[1];

      /* UnitDelay: '<S23>/y' */
      forced_choice_B.y_p = forced_choice_DWork.y_DSTATE_a;

      /* Sum: '<S23>/Add1' */
      forced_choice_B.Add1_o = forced_choice_B.y_p - forced_choice_B.x;

      /* UnitDelay: '<S23>/z' */
      forced_choice_B.z_p = forced_choice_DWork.z_DSTATE_i;

      /* Sum: '<S23>/Add3' incorporates:
       *  Constant: '<S23>/rho'
       */
      forced_choice_B.Add3_m2 = forced_choice_P.rho_Value_i -
        forced_choice_B.z_p;

      /* Product: '<S23>/product2' */
      forced_choice_B.product2_go = forced_choice_B.x * forced_choice_B.Add3_m2;

      /* Sum: '<S23>/Add2' */
      forced_choice_B.Add2_n = forced_choice_B.product2_go - forced_choice_B.y_p;

      /* Product: '<S23>/product3' incorporates:
       *  Constant: '<S23>/beta'
       */
      forced_choice_B.product3_m = forced_choice_B.z_p *
        forced_choice_P.beta_Value_gv;

      /* Product: '<S23>/product4' */
      forced_choice_B.product4_j = forced_choice_B.y_p * forced_choice_B.x;

      /* Sum: '<S23>/Add4' */
      forced_choice_B.Add4_p = forced_choice_B.product4_j -
        forced_choice_B.product3_m;

      /* Product: '<S23>/product1' incorporates:
       *  Constant: '<S23>/sigma'
       */
      forced_choice_B.product1_k = forced_choice_B.Add1_o *
        forced_choice_P.sigma_Value_bo;

      /* Product: '<S23>/dX' incorporates:
       *  Constant: '<S23>/timescale'
       */
      forced_choice_B.dX_b = forced_choice_P.timescale_Value_c *
        forced_choice_B.product1_k;

      /* Sum: '<S23>/AddX' */
      forced_choice_B.AddX_n = forced_choice_B.x + forced_choice_B.dX_b;

      /* Product: '<S23>/dY' incorporates:
       *  Constant: '<S23>/timescale'
       */
      forced_choice_B.dY_ks = forced_choice_P.timescale_Value_c *
        forced_choice_B.Add2_n;

      /* Sum: '<S23>/AddX1' */
      forced_choice_B.AddX1_p = forced_choice_B.y_p + forced_choice_B.dY_ks;

      /* Product: '<S23>/dZ' incorporates:
       *  Constant: '<S23>/timescale'
       */
      forced_choice_B.dZ_j = forced_choice_P.timescale_Value_c *
        forced_choice_B.Add4_p;

      /* Sum: '<S23>/AddX2' */
      forced_choice_B.AddX2_i = forced_choice_B.z_p + forced_choice_B.dZ_j;

      /* UnitDelay: '<S24>/y' */
      forced_choice_B.y_pt = forced_choice_DWork.y_DSTATE_ag;

      /* Sum: '<S24>/Add1' */
      forced_choice_B.Add1_e = forced_choice_B.y_pt - forced_choice_B.x_h;

      /* UnitDelay: '<S24>/z' */
      forced_choice_B.z_m = forced_choice_DWork.z_DSTATE_gn;

      /* Sum: '<S24>/Add3' incorporates:
       *  Constant: '<S24>/rho'
       */
      forced_choice_B.Add3_n = forced_choice_P.rho_Value_dl -
        forced_choice_B.z_m;

      /* Product: '<S24>/product2' */
      forced_choice_B.product2_n2 = forced_choice_B.x_h * forced_choice_B.Add3_n;

      /* Sum: '<S24>/Add2' */
      forced_choice_B.Add2_d = forced_choice_B.product2_n2 -
        forced_choice_B.y_pt;

      /* Product: '<S24>/product3' incorporates:
       *  Constant: '<S24>/beta'
       */
      forced_choice_B.product3_b = forced_choice_B.z_m *
        forced_choice_P.beta_Value_b;

      /* Product: '<S24>/product4' */
      forced_choice_B.product4_n = forced_choice_B.y_pt * forced_choice_B.x_h;

      /* Sum: '<S24>/Add4' */
      forced_choice_B.Add4_c = forced_choice_B.product4_n -
        forced_choice_B.product3_b;

      /* Product: '<S24>/product1' incorporates:
       *  Constant: '<S24>/sigma'
       */
      forced_choice_B.product1_ka = forced_choice_B.Add1_e *
        forced_choice_P.sigma_Value_e;

      /* Product: '<S24>/dX' incorporates:
       *  Constant: '<S24>/timescale'
       */
      forced_choice_B.dX_i1 = forced_choice_P.timescale_Value_j *
        forced_choice_B.product1_ka;

      /* Sum: '<S24>/AddX' */
      forced_choice_B.AddX_m = forced_choice_B.x_h + forced_choice_B.dX_i1;

      /* Product: '<S24>/dY' incorporates:
       *  Constant: '<S24>/timescale'
       */
      forced_choice_B.dY_g = forced_choice_P.timescale_Value_j *
        forced_choice_B.Add2_d;

      /* Sum: '<S24>/AddX1' */
      forced_choice_B.AddX1_j = forced_choice_B.y_pt + forced_choice_B.dY_g;

      /* Product: '<S24>/dZ' incorporates:
       *  Constant: '<S24>/timescale'
       */
      forced_choice_B.dZ_k3 = forced_choice_P.timescale_Value_j *
        forced_choice_B.Add4_c;

      /* Sum: '<S24>/AddX2' */
      forced_choice_B.AddX2_j = forced_choice_B.z_m + forced_choice_B.dZ_k3;

      /* UnitDelay: '<S25>/y' */
      forced_choice_B.y_e = forced_choice_DWork.y_DSTATE_p;

      /* Sum: '<S25>/Add1' */
      forced_choice_B.Add1_ln = forced_choice_B.y_e - forced_choice_B.x_m;

      /* UnitDelay: '<S25>/z' */
      forced_choice_B.z_mc = forced_choice_DWork.z_DSTATE_a;

      /* Sum: '<S25>/Add3' incorporates:
       *  Constant: '<S25>/rho'
       */
      forced_choice_B.Add3_k = forced_choice_P.rho_Value_h -
        forced_choice_B.z_mc;

      /* Product: '<S25>/product2' */
      forced_choice_B.product2_a = forced_choice_B.x_m * forced_choice_B.Add3_k;

      /* Sum: '<S25>/Add2' */
      forced_choice_B.Add2_k = forced_choice_B.product2_a - forced_choice_B.y_e;

      /* Product: '<S25>/product3' incorporates:
       *  Constant: '<S25>/beta'
       */
      forced_choice_B.product3_c = forced_choice_B.z_mc *
        forced_choice_P.beta_Value_p;

      /* Product: '<S25>/product4' */
      forced_choice_B.product4_c = forced_choice_B.y_e * forced_choice_B.x_m;

      /* Sum: '<S25>/Add4' */
      forced_choice_B.Add4_im = forced_choice_B.product4_c -
        forced_choice_B.product3_c;

      /* Product: '<S25>/product1' incorporates:
       *  Constant: '<S25>/sigma'
       */
      forced_choice_B.product1_bp = forced_choice_B.Add1_ln *
        forced_choice_P.sigma_Value_o;

      /* Product: '<S25>/dX' incorporates:
       *  Constant: '<S25>/timescale'
       */
      forced_choice_B.dX_l = forced_choice_P.timescale_Value_d *
        forced_choice_B.product1_bp;

      /* Sum: '<S25>/AddX' */
      forced_choice_B.AddX_kb = forced_choice_B.x_m + forced_choice_B.dX_l;

      /* Product: '<S25>/dY' incorporates:
       *  Constant: '<S25>/timescale'
       */
      forced_choice_B.dY_op = forced_choice_P.timescale_Value_d *
        forced_choice_B.Add2_k;

      /* Sum: '<S25>/AddX1' */
      forced_choice_B.AddX1_k = forced_choice_B.y_e + forced_choice_B.dY_op;

      /* Product: '<S25>/dZ' incorporates:
       *  Constant: '<S25>/timescale'
       */
      forced_choice_B.dZ_f = forced_choice_P.timescale_Value_d *
        forced_choice_B.Add4_im;

      /* Sum: '<S25>/AddX2' */
      forced_choice_B.AddX2_b = forced_choice_B.z_mc + forced_choice_B.dZ_f;

      /* UnitDelay: '<S26>/y' */
      forced_choice_B.y_ke = forced_choice_DWork.y_DSTATE_g;

      /* Sum: '<S26>/Add1' */
      forced_choice_B.Add1_i = forced_choice_B.y_ke - forced_choice_B.x_ho;

      /* UnitDelay: '<S26>/z' */
      forced_choice_B.z_n = forced_choice_DWork.z_DSTATE_p;

      /* Sum: '<S26>/Add3' incorporates:
       *  Constant: '<S26>/rho'
       */
      forced_choice_B.Add3_d = forced_choice_P.rho_Value_n - forced_choice_B.z_n;

      /* Product: '<S26>/product2' */
      forced_choice_B.product2_j = forced_choice_B.x_ho * forced_choice_B.Add3_d;

      /* Sum: '<S26>/Add2' */
      forced_choice_B.Add2_cy = forced_choice_B.product2_j -
        forced_choice_B.y_ke;

      /* Product: '<S26>/product3' incorporates:
       *  Constant: '<S26>/beta'
       */
      forced_choice_B.product3_a = forced_choice_B.z_n *
        forced_choice_P.beta_Value_e;

      /* Product: '<S26>/product4' */
      forced_choice_B.product4_p = forced_choice_B.y_ke * forced_choice_B.x_ho;

      /* Sum: '<S26>/Add4' */
      forced_choice_B.Add4_hy = forced_choice_B.product4_p -
        forced_choice_B.product3_a;

      /* Product: '<S26>/product1' incorporates:
       *  Constant: '<S26>/sigma'
       */
      forced_choice_B.product1_kd = forced_choice_B.Add1_i *
        forced_choice_P.sigma_Value_k4;

      /* Product: '<S26>/dX' incorporates:
       *  Constant: '<S26>/timescale'
       */
      forced_choice_B.dX_a = forced_choice_P.timescale_Value_f *
        forced_choice_B.product1_kd;

      /* Sum: '<S26>/AddX' */
      forced_choice_B.AddX_mq = forced_choice_B.x_ho + forced_choice_B.dX_a;

      /* Product: '<S26>/dY' incorporates:
       *  Constant: '<S26>/timescale'
       */
      forced_choice_B.dY_p = forced_choice_P.timescale_Value_f *
        forced_choice_B.Add2_cy;

      /* Sum: '<S26>/AddX1' */
      forced_choice_B.AddX1_e = forced_choice_B.y_ke + forced_choice_B.dY_p;

      /* Product: '<S26>/dZ' incorporates:
       *  Constant: '<S26>/timescale'
       */
      forced_choice_B.dZ_p = forced_choice_P.timescale_Value_f *
        forced_choice_B.Add4_hy;

      /* Sum: '<S26>/AddX2' */
      forced_choice_B.AddX2_fp = forced_choice_B.z_n + forced_choice_B.dZ_p;

      /* Sum: '<S8>/Add' */
      forced_choice_B.Add_n = forced_choice_B.BehaviorFC_o4[1] +
        forced_choice_B.BehaviorFC_o4[3];

      /* Sum: '<S8>/Add1' */
      forced_choice_B.Add1_m = forced_choice_B.BehaviorFC_o4[2] +
        forced_choice_B.BehaviorFC_o4[4];

      /* Gain: '<S8>/Gain' */
      forced_choice_B.Gain_n = forced_choice_P.Gain_Gain_i *
        forced_choice_B.Add_n;

      /* Gain: '<S8>/Gain1' */
      forced_choice_B.Gain1_d = forced_choice_P.Gain1_Gain_e *
        forced_choice_B.Add1_m;
    }
  }
}

/* Model update function */
void forced_choice_update(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S31>/Memory' */
    forced_choice_DWork.Memory_PreviousInput = forced_choice_B.LogicalOperator;

    /* Update for Memory: '<S4>/Memory' */
    forced_choice_DWork.Memory_PreviousInput_l =
      forced_choice_B.LogicalOperator1_g;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S67>/Derivative' */
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

    /* Derivative Block: '<S68>/Derivative' */
    {
      real_T timeStampA = forced_choice_DWork.Derivative_RWORK_a.TimeStampA;
      real_T timeStampB = forced_choice_DWork.Derivative_RWORK_a.TimeStampB;
      real_T *lastBank = &forced_choice_DWork.Derivative_RWORK_a.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = forced_choice_rtM->Timing.t[0];
      *lastBank++ = forced_choice_B.DigitalFilter2_b;
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S43>/Memory' */
    forced_choice_DWork.Memory_PreviousInput_e =
      forced_choice_B.LogicalOperator_p;

    /* Update for Memory: '<S47>/Memory' */
    forced_choice_DWork.Memory_PreviousInput_n =
      forced_choice_B.LogicalOperator_fl;

    /* Update for UnitDelay: '<S61>/Delay Input1' */
    forced_choice_DWork.DelayInput1_DSTATE = forced_choice_B.Compare_gq;

    /* Update for Memory: '<S45>/Memory' */
    forced_choice_DWork.Memory_PreviousInput_eh =
      forced_choice_B.LogicalOperator_g;

    /* Update for UnitDelay: '<S46>/Delay Input1' */
    forced_choice_DWork.DelayInput1_DSTATE_d = forced_choice_B.Compare_jg;

    /* Update for UnitDelay: '<S39>/Delay Input1' */
    forced_choice_DWork.DelayInput1_DSTATE_m = forced_choice_B.Compare_l;

    /* Update for Memory: '<S44>/Memory' */
    forced_choice_DWork.Memory_PreviousInput_g =
      forced_choice_B.LogicalOperator_fa;

    /* Update for UnitDelay: '<S38>/Delay Input1' */
    forced_choice_DWork.DelayInput1_DSTATE_b = forced_choice_B.Compare_e;

    /* Update for Memory: '<S42>/Memory' */
    forced_choice_DWork.Memory_PreviousInput_h = forced_choice_B.Logic[0];

    /* Update for UnitDelay: '<S23>/x' */
    forced_choice_DWork.x_DSTATE = forced_choice_B.AddX_n;

    /* Update for UnitDelay: '<S24>/x' */
    forced_choice_DWork.x_DSTATE_h = forced_choice_B.AddX_m;

    /* Update for UnitDelay: '<S25>/x' */
    forced_choice_DWork.x_DSTATE_g = forced_choice_B.AddX_kb;

    /* Update for UnitDelay: '<S26>/x' */
    forced_choice_DWork.x_DSTATE_e = forced_choice_B.AddX_mq;

    /* Update for UnitDelay: '<S17>/x' */
    forced_choice_DWork.x_DSTATE_k = forced_choice_B.AddX;

    /* Update for UnitDelay: '<S18>/x' */
    forced_choice_DWork.x_DSTATE_en = forced_choice_B.AddX_h;

    /* Update for UnitDelay: '<S19>/x' */
    forced_choice_DWork.x_DSTATE_b = forced_choice_B.AddX_e;

    /* Update for UnitDelay: '<S20>/x' */
    forced_choice_DWork.x_DSTATE_d = forced_choice_B.AddX_k;

    /* Level2 S-Function Block: '<Root>/Behavior FC' (mastercon_fc) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[11];
      sfcnUpdate(rts, 1);
      if (ssGetErrorStatus(rts) != NULL)
        return;
    }

    /* UniformRandomNumber Block: '<S6>/Uniform Random Number' */
    forced_choice_DWork.UniformRandomNumber_RWORK.NextOutput = rt_Urand
      ((uint32_T *)&forced_choice_DWork.UniformRandomNumber_IWORK.RandSeed) *
      (forced_choice_P.UniformRandomNumber_Max -
       forced_choice_P.UniformRandomNumber_Min) +
      forced_choice_P.UniformRandomNumber_Min;
  }

  if (tid == 0) {
    /* Update for UnitDelay: '<S17>/y' */
    forced_choice_DWork.y_DSTATE = forced_choice_B.AddX1;

    /* Update for UnitDelay: '<S17>/z' */
    forced_choice_DWork.z_DSTATE = forced_choice_B.AddX2;

    /* Update for UnitDelay: '<S18>/y' */
    forced_choice_DWork.y_DSTATE_n = forced_choice_B.AddX1_a;

    /* Update for UnitDelay: '<S18>/z' */
    forced_choice_DWork.z_DSTATE_g = forced_choice_B.AddX2_f;

    /* Update for UnitDelay: '<S19>/y' */
    forced_choice_DWork.y_DSTATE_h = forced_choice_B.AddX1_g;

    /* Update for UnitDelay: '<S19>/z' */
    forced_choice_DWork.z_DSTATE_m = forced_choice_B.AddX2_m;

    /* Update for UnitDelay: '<S20>/y' */
    forced_choice_DWork.y_DSTATE_f = forced_choice_B.AddX1_c;

    /* Update for UnitDelay: '<S20>/z' */
    forced_choice_DWork.z_DSTATE_f = forced_choice_B.AddX2_d;

    /* Update for UnitDelay: '<S23>/y' */
    forced_choice_DWork.y_DSTATE_a = forced_choice_B.AddX1_p;

    /* Update for UnitDelay: '<S23>/z' */
    forced_choice_DWork.z_DSTATE_i = forced_choice_B.AddX2_i;

    /* Update for UnitDelay: '<S24>/y' */
    forced_choice_DWork.y_DSTATE_ag = forced_choice_B.AddX1_j;

    /* Update for UnitDelay: '<S24>/z' */
    forced_choice_DWork.z_DSTATE_gn = forced_choice_B.AddX2_j;

    /* Update for UnitDelay: '<S25>/y' */
    forced_choice_DWork.y_DSTATE_p = forced_choice_B.AddX1_k;

    /* Update for UnitDelay: '<S25>/z' */
    forced_choice_DWork.z_DSTATE_a = forced_choice_B.AddX2_b;

    /* Update for UnitDelay: '<S26>/y' */
    forced_choice_DWork.y_DSTATE_g = forced_choice_B.AddX1_e;

    /* Update for UnitDelay: '<S26>/z' */
    forced_choice_DWork.z_DSTATE_p = forced_choice_B.AddX2_fp;
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
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    if (!(++forced_choice_rtM->Timing.clockTick2))
      ++forced_choice_rtM->Timing.clockTickH2;
    forced_choice_rtM->Timing.t[2] = forced_choice_rtM->Timing.clockTick2 *
      forced_choice_rtM->Timing.stepSize2 +
      forced_choice_rtM->Timing.clockTickH2 *
      forced_choice_rtM->Timing.stepSize2 * 4294967296.0;
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
    forced_choice_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    forced_choice_rtM->Timing.sampleTimes =
      (&forced_choice_rtM->Timing.sampleTimesArray[0]);
    forced_choice_rtM->Timing.offsetTimes =
      (&forced_choice_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    forced_choice_rtM->Timing.sampleTimes[0] = (0.0);
    forced_choice_rtM->Timing.sampleTimes[1] = (0.001);
    forced_choice_rtM->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    forced_choice_rtM->Timing.offsetTimes[0] = (0.0);
    forced_choice_rtM->Timing.offsetTimes[1] = (0.0);
    forced_choice_rtM->Timing.offsetTimes[2] = (0.0);
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
  forced_choice_rtM->Timing.stepSize2 = 0.02;

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
        "forced_choice/Velocity Calculation/Pos2VelX/Digital Filter2",
        "forced_choice/Velocity Calculation/Pos2VelX/Digital Filter",
        "forced_choice/Velocity Calculation/Pos2VelY/Digital Filter2",
        "forced_choice/Velocity Calculation/Pos2VelY/Digital Filter",
        "forced_choice/Force Generator/LorentzForce/Lorentz/x",
        "forced_choice/Force Generator/LorentzForce/Lorentz1/x",
        "forced_choice/Force Generator/LorentzForce/Lorentz2/x",
        "forced_choice/Force Generator/LorentzForce/Lorentz3/x",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz/x",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz1/x",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz2/x",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz3/x",
        "forced_choice/Behavior FC",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz/y",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz/z",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz1/y",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz1/z",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz2/y",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz2/z",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz3/y",
        "forced_choice/Catch Force Generator/LorentzForce/Lorentz3/z",
        "forced_choice/Force Generator/LorentzForce/Lorentz/y",
        "forced_choice/Force Generator/LorentzForce/Lorentz/z",
        "forced_choice/Force Generator/LorentzForce/Lorentz1/y",
        "forced_choice/Force Generator/LorentzForce/Lorentz1/z",
        "forced_choice/Force Generator/LorentzForce/Lorentz2/y",
        "forced_choice/Force Generator/LorentzForce/Lorentz2/z",
        "forced_choice/Force Generator/LorentzForce/Lorentz3/y",
        "forced_choice/Force Generator/LorentzForce/Lorentz3/z",
        "forced_choice/Recentering Subsystem/Timer/Detect Fall\nNonpositive/Delay Input1",
        "forced_choice/Recentering Subsystem/Start Moving/Delay Input1",
        "forced_choice/Recentering Subsystem/Falling Edge1/Delay Input1",
        "forced_choice/Recentering Subsystem/Falling Edge/Delay Input1" };

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

        { 0, SS_UINT8, SS_UINT8, 1.0, 0, 0.0 },

        { 0, SS_UINT8, SS_UINT8, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
        33,
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
      static void * rt_LoggedStateSignalPtrs[33];
      rt_LoggedStateSignalPtrs[0] = (void*)
        &forced_choice_DWork.DigitalFilter2_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[1] = (void*)
        &forced_choice_DWork.DigitalFilter_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[2] = (void*)
        &forced_choice_DWork.DigitalFilter2_FILT_STATES_g[0];
      rt_LoggedStateSignalPtrs[3] = (void*)
        &forced_choice_DWork.DigitalFilter_FILT_STATES_d[0];
      rt_LoggedStateSignalPtrs[4] = (void*)&forced_choice_DWork.x_DSTATE;
      rt_LoggedStateSignalPtrs[5] = (void*)&forced_choice_DWork.x_DSTATE_h;
      rt_LoggedStateSignalPtrs[6] = (void*)&forced_choice_DWork.x_DSTATE_g;
      rt_LoggedStateSignalPtrs[7] = (void*)&forced_choice_DWork.x_DSTATE_e;
      rt_LoggedStateSignalPtrs[8] = (void*)&forced_choice_DWork.x_DSTATE_k;
      rt_LoggedStateSignalPtrs[9] = (void*)&forced_choice_DWork.x_DSTATE_en;
      rt_LoggedStateSignalPtrs[10] = (void*)&forced_choice_DWork.x_DSTATE_b;
      rt_LoggedStateSignalPtrs[11] = (void*)&forced_choice_DWork.x_DSTATE_d;
      rt_LoggedStateSignalPtrs[12] = (void*)
        &forced_choice_DWork.BehaviorFC_DSTATE;
      rt_LoggedStateSignalPtrs[13] = (void*)&forced_choice_DWork.y_DSTATE;
      rt_LoggedStateSignalPtrs[14] = (void*)&forced_choice_DWork.z_DSTATE;
      rt_LoggedStateSignalPtrs[15] = (void*)&forced_choice_DWork.y_DSTATE_n;
      rt_LoggedStateSignalPtrs[16] = (void*)&forced_choice_DWork.z_DSTATE_g;
      rt_LoggedStateSignalPtrs[17] = (void*)&forced_choice_DWork.y_DSTATE_h;
      rt_LoggedStateSignalPtrs[18] = (void*)&forced_choice_DWork.z_DSTATE_m;
      rt_LoggedStateSignalPtrs[19] = (void*)&forced_choice_DWork.y_DSTATE_f;
      rt_LoggedStateSignalPtrs[20] = (void*)&forced_choice_DWork.z_DSTATE_f;
      rt_LoggedStateSignalPtrs[21] = (void*)&forced_choice_DWork.y_DSTATE_a;
      rt_LoggedStateSignalPtrs[22] = (void*)&forced_choice_DWork.z_DSTATE_i;
      rt_LoggedStateSignalPtrs[23] = (void*)&forced_choice_DWork.y_DSTATE_ag;
      rt_LoggedStateSignalPtrs[24] = (void*)&forced_choice_DWork.z_DSTATE_gn;
      rt_LoggedStateSignalPtrs[25] = (void*)&forced_choice_DWork.y_DSTATE_p;
      rt_LoggedStateSignalPtrs[26] = (void*)&forced_choice_DWork.z_DSTATE_a;
      rt_LoggedStateSignalPtrs[27] = (void*)&forced_choice_DWork.y_DSTATE_g;
      rt_LoggedStateSignalPtrs[28] = (void*)&forced_choice_DWork.z_DSTATE_p;
      rt_LoggedStateSignalPtrs[29] = (void*)
        &forced_choice_DWork.DelayInput1_DSTATE;
      rt_LoggedStateSignalPtrs[30] = (void*)
        &forced_choice_DWork.DelayInput1_DSTATE_d;
      rt_LoggedStateSignalPtrs[31] = (void*)
        &forced_choice_DWork.DelayInput1_DSTATE_m;
      rt_LoggedStateSignalPtrs[32] = (void*)
        &forced_choice_DWork.DelayInput1_DSTATE_b;
      rtliSetLogXSignalPtrs(forced_choice_rtM->rtwLogInfo, (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
    }

    rtliSetLogY(forced_choice_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(forced_choice_rtM->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(forced_choice_rtM->rtwLogInfo, NULL);
  }

  /* external mode info */
  forced_choice_rtM->Sizes.checksums[0] = (743698192U);
  forced_choice_rtM->Sizes.checksums[1] = (3108080846U);
  forced_choice_rtM->Sizes.checksums[2] = (1240755981U);
  forced_choice_rtM->Sizes.checksums[3] = (2323727065U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[34];
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
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = (sysRanDType *)
      &forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &forced_choice_DWork.EnabledSubsystem_hg.EnabledSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &forced_choice_DWork.EnabledSubsystem_i.EnabledSubsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &forced_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)
      &forced_choice_DWork.SampleandHold_i.SampleandHold_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &forced_choice_DWork.SampleandHold.SampleandHold_SubsysRanBC;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
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
    for (i = 0; i < 241; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&forced_choice_B.ForIterator);
    for (i = 0; i < 90; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    ((real_T*)&forced_choice_B.SampleandHold.In)[0] = 0.0;
    ((real_T*)&forced_choice_B.SampleandHold_i.In)[0] = 0.0;
    ((real_T*)&forced_choice_B.EnabledSubsystem_l.In1)[0] = 0.0;
    ((real_T*)&forced_choice_B.EnabledSubsystem_i.In1)[0] = 0.0;
    ((real_T*)&forced_choice_B.EnabledSubsystem_hg.In1)[0] = 0.0;
    ((real_T*)&forced_choice_B.EnabledSubsystem_h.In1)[0] = 0.0;
    ((real_T*)&forced_choice_B.EnabledSubsystem.In1)[0] = 0.0;
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
    for (i = 0; i < 152; i++) {
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

  forced_choice_rtM->Sizes.numSFcns = (14);

  /* register each child */
  {
    (void) memset((void *)&forced_choice_rtM->NonInlinedSFcns.childSFunctions[0],
                  0,
                  14*sizeof(SimStruct));
    forced_choice_rtM->childSfunctions =
      (&forced_choice_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 14; i++) {
        forced_choice_rtM->childSfunctions[i] =
          (&forced_choice_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: forced_choice/<S72>/xPC Target  Time  (xpctimeinfo) */
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

    /* Level2 S-Function Block: forced_choice/<S72>/PCI-6025E  (donipcie) */
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
          sfcnUPtrs[0] = &forced_choice_B.Switch_m;
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

    /* Level2 S-Function Block: forced_choice/<S70>/ToBits1 (Byte2Bits) */
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
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.Switch_e;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &forced_choice_B.ToBits1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &forced_choice_B.ToBits1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &forced_choice_B.ToBits1_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &forced_choice_B.ToBits1_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &forced_choice_B.ToBits1_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &forced_choice_B.ToBits1_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &forced_choice_B.ToBits1_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &forced_choice_B.ToBits1_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits1");
      ssSetPath(rts,
                "forced_choice/XY Position Subsystem/For Iterator Subsystem/ToBits1");
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

    /* Level2 S-Function Block: forced_choice/<S70>/Port A (dopci8255) */
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
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.ToBits1_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &forced_choice_B.ToBits1_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs2;
          sfcnUPtrs[0] = &forced_choice_B.ToBits1_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs3;
          sfcnUPtrs[0] = &forced_choice_B.ToBits1_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs4;
          sfcnUPtrs[0] = &forced_choice_B.ToBits1_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs5;
          sfcnUPtrs[0] = &forced_choice_B.ToBits1_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs6;
          sfcnUPtrs[0] = &forced_choice_B.ToBits1_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs7;
          sfcnUPtrs[0] = &forced_choice_B.ToBits1_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port A");
      ssSetPath(rts,
                "forced_choice/XY Position Subsystem/For Iterator Subsystem/Port A");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn3.params;
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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn3.dWork;
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

    /* Level2 S-Function Block: forced_choice/<S70>/SerialConverter (serPos) */
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
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.ForIterator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &forced_choice_B.Add_i;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs2;
          sfcnUPtrs[0] = &forced_choice_B.Add1_k0;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
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

    /* Level2 S-Function Block: forced_choice/<S70>/ToBits (Byte2Bits) */
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

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.SerialConverter;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
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

    /* Level2 S-Function Block: forced_choice/<S70>/Port B (dopci8255) */
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

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs2;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs3;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs4;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs5;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs6;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs7;
          sfcnUPtrs[0] = &forced_choice_B.ToBits_o8;
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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn6.params;
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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn6.dWork;
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

    /* Level2 S-Function Block: forced_choice/<S70>/xPC Target  Time  (xpctimeinfo) */
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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn7.params;
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

    /* Level2 S-Function Block: forced_choice/<S13>/PCI-QUAD04  (enccbcioquadcount) */
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

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn8.params;
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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn8.dWork;
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

    /* Level2 S-Function Block: forced_choice/<S13>/PCI-QUAD04 1 (enccbcioquadcount) */
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

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn9.params;
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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn9.dWork;
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

    /* Level2 S-Function Block: forced_choice/<S10>/PCI-6025E AD (adnipcie) */
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

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &forced_choice_B.PCI6025EAD_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &forced_choice_B.PCI6025EAD_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E AD");
      ssSetPath(rts, "forced_choice/Velocity Calculation/PCI-6025E AD");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&forced_choice_P.PCI6025EAD_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&forced_choice_P.PCI6025EAD_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&forced_choice_P.PCI6025EAD_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&forced_choice_P.PCI6025EAD_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&forced_choice_P.PCI6025EAD_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&forced_choice_P.PCI6025EAD_P6_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &forced_choice_DWork.PCI6025EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &forced_choice_DWork.PCI6025EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn10.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &forced_choice_DWork.PCI6025EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &forced_choice_DWork.PCI6025EAD_IWORK[0]);
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
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: forced_choice/<Root>/Behavior FC (mastercon_fc) */
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
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn11.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.Product1_d;
          sfcnUPtrs[1] = &forced_choice_B.Product_d;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn11.UPtrs1;
          sfcnUPtrs[0] = forced_choice_B.MultiportSwitch;
          sfcnUPtrs[1] = &forced_choice_B.MultiportSwitch[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn11.UPtrs2;
          sfcnUPtrs[0] = forced_choice_B.LoadSelectSwitch;
          sfcnUPtrs[1] = &forced_choice_B.LoadSelectSwitch[1];
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 2);
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
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            forced_choice_B.BehaviorFC_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 5);
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

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 4);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            forced_choice_B.BehaviorFC_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 2);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            forced_choice_B.BehaviorFC_o8));
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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 13);
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
        ssSetSFcnParam(rts, 11, (mxArray*)&forced_choice_P.BehaviorFC_P12_Size[0]);
        ssSetSFcnParam(rts, 12, (mxArray*)&forced_choice_P.BehaviorFC_P13_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &forced_choice_DWork.BehaviorFC_RWORK[0]);
      ssSetIWork(rts, (int_T *) &forced_choice_DWork.BehaviorFC_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn11.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 3);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 4);
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
      _ssSetInputPortConnected(rts, 2, 1);
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
    }

    /* Level2 S-Function Block: forced_choice/<S4>/PCI-6025E  (danipcie) */
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
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs0;
          sfcnUPtrs[0] = &forced_choice_B.MG1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &forced_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs1;
          sfcnUPtrs[0] = &forced_choice_B.MG2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts, "forced_choice/Motor Control/PCI-6025E ");
      ssSetRTModel(rts,forced_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &forced_choice_rtM->NonInlinedSFcns.Sfcn12.params;
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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn12.dWork;
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

    /* Level2 S-Function Block: forced_choice/<S9>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = forced_choice_rtM->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = forced_choice_rtM->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = forced_choice_rtM->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = forced_choice_rtM->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &forced_choice_rtM->NonInlinedSFcns.blkInfo2[13]);
        ssSetRTWSfcnInfo(rts, forced_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &forced_choice_rtM->NonInlinedSFcns.methods2[13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &forced_choice_rtM->NonInlinedSFcns.Sfcn13.inputPortInfo[0]);

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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn13.params;
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
          &forced_choice_rtM->NonInlinedSFcns.Sfcn13.dWork;
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
      sfcnTsMap[0] = 2;

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
  }

  forced_choice_PrevZCSigState.SampleandHold.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
  forced_choice_PrevZCSigState.SampleandHold_i.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void forced_choice_terminate(void)
{
  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Behavior FC' (mastercon_fc) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S13>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S70>/ToBits1' (Byte2Bits) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/SerialConverter' (serPos) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S70>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S72>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* External mode */
  rtExtModeShutdown(3);
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
  forced_choice_rtM->Sizes.numSampTimes = (3);/* Number of sample times */
  forced_choice_rtM->Sizes.numBlocks = (480);/* Number of blocks */
  forced_choice_rtM->Sizes.numBlockIO = (375);/* Number of block outputs */
  forced_choice_rtM->Sizes.numBlockPrms = (520);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Memory: '<S31>/Memory' */
  forced_choice_DWork.Memory_PreviousInput = forced_choice_P.Memory_X0;

  /* InitializeConditions for Memory: '<S4>/Memory' */
  forced_choice_DWork.Memory_PreviousInput_l = forced_choice_P.Memory_X0_m;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter2' */
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

  /* Derivative Block: '<S67>/Derivative' */
  forced_choice_DWork.Derivative_RWORK.TimeStampA = rtInf;
  forced_choice_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter' */
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

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *)
      &forced_choice_DWork.DigitalFilter2_FILT_STATES_g[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&forced_choice_P.DigitalFilter2_ICRTP_l;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S68>/Derivative' */
  forced_choice_DWork.Derivative_RWORK_a.TimeStampA = rtInf;
  forced_choice_DWork.Derivative_RWORK_a.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *)
      &forced_choice_DWork.DigitalFilter_FILT_STATES_d[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&forced_choice_P.DigitalFilter_ICRTP_h;
    }

    *statePtr++ = 0.0;
  }

  /* InitializeConditions for Memory: '<S43>/Memory' */
  forced_choice_DWork.Memory_PreviousInput_e = forced_choice_P.Memory_X0_n;

  /* InitializeConditions for Memory: '<S47>/Memory' */
  forced_choice_DWork.Memory_PreviousInput_n = forced_choice_P.Memory_X0_f;

  /* InitializeConditions for UnitDelay: '<S61>/Delay Input1' */
  forced_choice_DWork.DelayInput1_DSTATE = forced_choice_P.DelayInput1_X0;

  /* InitializeConditions for Memory: '<S45>/Memory' */
  forced_choice_DWork.Memory_PreviousInput_eh = forced_choice_P.Memory_X0_e;

  /* InitializeConditions for UnitDelay: '<S46>/Delay Input1' */
  forced_choice_DWork.DelayInput1_DSTATE_d = forced_choice_P.DelayInput1_X0_f;

  /* InitializeConditions for UnitDelay: '<S39>/Delay Input1' */
  forced_choice_DWork.DelayInput1_DSTATE_m = forced_choice_P.DelayInput1_X0_c;

  /* InitializeConditions for Memory: '<S44>/Memory' */
  forced_choice_DWork.Memory_PreviousInput_g = forced_choice_P.Memory_X0_a;

  /* InitializeConditions for UnitDelay: '<S38>/Delay Input1' */
  forced_choice_DWork.DelayInput1_DSTATE_b = forced_choice_P.DelayInput1_X0_d;

  /* InitializeConditions for Memory: '<S42>/Memory' */
  forced_choice_DWork.Memory_PreviousInput_h = forced_choice_P.Memory_X0_k;

  /* InitializeConditions for UnitDelay: '<S23>/x' */
  forced_choice_DWork.x_DSTATE = forced_choice_P.x_X0;

  /* InitializeConditions for UnitDelay: '<S24>/x' */
  forced_choice_DWork.x_DSTATE_h = forced_choice_P.x_X0_f;

  /* InitializeConditions for UnitDelay: '<S25>/x' */
  forced_choice_DWork.x_DSTATE_g = forced_choice_P.x_X0_l;

  /* InitializeConditions for UnitDelay: '<S26>/x' */
  forced_choice_DWork.x_DSTATE_e = forced_choice_P.x_X0_c;

  /* InitializeConditions for UnitDelay: '<S17>/x' */
  forced_choice_DWork.x_DSTATE_k = forced_choice_P.x_X0_m;

  /* InitializeConditions for UnitDelay: '<S18>/x' */
  forced_choice_DWork.x_DSTATE_en = forced_choice_P.x_X0_j;

  /* InitializeConditions for UnitDelay: '<S19>/x' */
  forced_choice_DWork.x_DSTATE_b = forced_choice_P.x_X0_g;

  /* InitializeConditions for UnitDelay: '<S20>/x' */
  forced_choice_DWork.x_DSTATE_d = forced_choice_P.x_X0_lz;

  /* Level2 S-Function Block: '<Root>/Behavior FC' (mastercon_fc) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[11];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* InitializeConditions for UnitDelay: '<S17>/y' */
  forced_choice_DWork.y_DSTATE = forced_choice_P.y_X0;

  /* InitializeConditions for UnitDelay: '<S17>/z' */
  forced_choice_DWork.z_DSTATE = forced_choice_P.z_X0;

  /* InitializeConditions for UnitDelay: '<S18>/y' */
  forced_choice_DWork.y_DSTATE_n = forced_choice_P.y_X0_b;

  /* InitializeConditions for UnitDelay: '<S18>/z' */
  forced_choice_DWork.z_DSTATE_g = forced_choice_P.z_X0_o;

  /* InitializeConditions for UnitDelay: '<S19>/y' */
  forced_choice_DWork.y_DSTATE_h = forced_choice_P.y_X0_o;

  /* InitializeConditions for UnitDelay: '<S19>/z' */
  forced_choice_DWork.z_DSTATE_m = forced_choice_P.z_X0_c;

  /* InitializeConditions for UnitDelay: '<S20>/y' */
  forced_choice_DWork.y_DSTATE_f = forced_choice_P.y_X0_a;

  /* InitializeConditions for UnitDelay: '<S20>/z' */
  forced_choice_DWork.z_DSTATE_f = forced_choice_P.z_X0_g;

  /* InitializeConditions for UnitDelay: '<S23>/y' */
  forced_choice_DWork.y_DSTATE_a = forced_choice_P.y_X0_b0;

  /* InitializeConditions for UnitDelay: '<S23>/z' */
  forced_choice_DWork.z_DSTATE_i = forced_choice_P.z_X0_f;

  /* InitializeConditions for UnitDelay: '<S24>/y' */
  forced_choice_DWork.y_DSTATE_ag = forced_choice_P.y_X0_f;

  /* InitializeConditions for UnitDelay: '<S24>/z' */
  forced_choice_DWork.z_DSTATE_gn = forced_choice_P.z_X0_p;

  /* InitializeConditions for UnitDelay: '<S25>/y' */
  forced_choice_DWork.y_DSTATE_p = forced_choice_P.y_X0_k;

  /* InitializeConditions for UnitDelay: '<S25>/z' */
  forced_choice_DWork.z_DSTATE_a = forced_choice_P.z_X0_n;

  /* InitializeConditions for UnitDelay: '<S26>/y' */
  forced_choice_DWork.y_DSTATE_g = forced_choice_P.y_X0_h;

  /* InitializeConditions for UnitDelay: '<S26>/z' */
  forced_choice_DWork.z_DSTATE_p = forced_choice_P.z_X0_b;
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S30>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Motor Control/Matrix Concatenation/s1"));
        rl32eAddSignal(2, rl32eGetSignalNo(
          "Motor Control/Matrix Concatenation/s2"));
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Motor Control/Matrix Concatenation/s1"),"%6.0f Control");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo(
          "Motor Control/Matrix Concatenation/s2"),"%6.0f ServoKill");
        rl32eSetScope(2, 4, 10);
        rl32eSetScope(2, 40, 0);
        rl32eSetScope(2, 7, 10);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo(
          "Motor Control/Matrix Concatenation/s1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 10, 0);
        rl32eSetTargetScope(2, 1, 0.0);
        rl32eSetTargetScope(2, 11, -10.0);
        rl32eSetTargetScope(2, 10, 10.0);
        xpceScopeAcqOK(2, &forced_choice_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S32>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(6)) == 0) {
      if ((i = rl32eDefScope(6,2)) != 0) {
        printf("Error creating scope 6\n");
      } else {
        rl32eAddSignal(6, rl32eGetSignalNo("Motor Control/Switch2/s1"));
        rl32eAddSignal(6, rl32eGetSignalNo("Motor Control/Switch2/s2"));
        rl32eAddSignal(6, rl32eGetSignalNo("Motor Control/MG1"));
        rl32eAddSignal(6, rl32eGetSignalNo("Motor Control/MG2"));
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Motor Control/Switch2/s1"),
          "%15.2f Fx");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Motor Control/Switch2/s2"),
          "%15.2f Fy");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Motor Control/MG1"),
          "%15.2f T1");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Motor Control/MG2"),
          "%15.2f T2");
        rl32eSetScope(6, 4, 10);
        rl32eSetScope(6, 40, 0);
        rl32eSetScope(6, 7, 10);
        rl32eSetScope(6, 0, 0);
        rl32eSetScope(6, 3, rl32eGetSignalNo("Motor Control/Switch2/s1"));
        rl32eSetScope(6, 1, 0.0);
        rl32eSetScope(6, 2, 0);
        rl32eSetScope(6, 10, 0);
        rl32eSetTargetScope(6, 1, 0.0);
        rl32eSetTargetScope(6, 11, -10.0);
        rl32eSetTargetScope(6, 10, 10.0);
        xpceScopeAcqOK(6, &forced_choice_DWork.SFunction_IWORK_g.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(6);
    }
  }

  /* S-Function Block: <S7>/S-Function (scblock) */
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
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior FC/p2/s5"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior FC/p2/s1"),
          "%6.0f state");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior FC/p2/s2"),
          "%6.0f rewards");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior FC/p2/s3"),
          "%6.0f aborts");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior FC/p2/s4"),
          "%6.0f fails");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior FC/p2/s5"),
          "%6.0f incompl");
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
        xpceScopeAcqOK(3, &forced_choice_DWork.SFunction_IWORK_f.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[13];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S11>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior FC/p7/s1"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior FC/p7/s2"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior FC/p7/s3"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior FC/p7/s4"));
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior FC/p7/s1"),
          "%6.0f major");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior FC/p7/s2"),
          "%6.0f minor");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior FC/p7/s3"),
          "%6.0f revision");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior FC/p7/s4"),
          "%6.0f build");
        rl32eSetScope(7, 4, 10);
        rl32eSetScope(7, 40, 0);
        rl32eSetScope(7, 7, 10);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("Behavior FC/p7/s1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 10, 0);
        rl32eSetTargetScope(7, 1, 0.0);
        rl32eSetTargetScope(7, 11, -10.0);
        rl32eSetTargetScope(7, 10, 10.0);
        xpceScopeAcqOK(7, &forced_choice_DWork.SFunction_IWORK_gk.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* S-Function Block: <S14>/S-Function (scblock) */
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
        rl32eSetScope(1, 40, 0);
        rl32eSetScope(1, 7, 10);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Matrix Concatenation1/s1"));
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

  /* S-Function Block: <S48>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,2)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo("BoundingBox/Logical Operator"));
        rl32eAddSignal(5, rl32eGetSignalNo(
          "Recentering Subsystem/Logical Operator"));
        rl32eAddSignal(5, rl32eGetSignalNo(
          "Recentering Subsystem/S-R Flip-Flop/Logic/s1"));
        rl32eAddSignal(5, rl32eGetSignalNo(
          "Recentering Subsystem/Schmidt1/Logical Operator"));
        rl32eAddSignal(5, rl32eGetSignalNo(
          "Recentering Subsystem/No Movement/Logical Operator1"));
        rl32eAddSignal(5, rl32eGetSignalNo(
          "Recentering Subsystem/Logical Operator5"));
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "BoundingBox/Logical Operator"),"%2.0f OutsideBox");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "Recentering Subsystem/Logical Operator"),"%2.0f Activate");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "Recentering Subsystem/S-R Flip-Flop/Logic/s1"),"%2.0f SR");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "Recentering Subsystem/Schmidt1/Logical Operator"),"%2.0f OD On");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "Recentering Subsystem/No Movement/Logical Operator1"),
          "%2.0f no movement");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo(
          "Recentering Subsystem/Logical Operator5"),"%2.0f claimed");
        rl32eSetScope(5, 4, 10);
        rl32eSetScope(5, 40, 0);
        rl32eSetScope(5, 7, 10);
        rl32eSetScope(5, 0, 0);
        rl32eSetScope(5, 3, rl32eGetSignalNo("BoundingBox/Logical Operator"));
        rl32eSetScope(5, 1, 0.0);
        rl32eSetScope(5, 2, 0);
        rl32eSetScope(5, 10, 0);
        rl32eSetTargetScope(5, 1, 0.0);
        rl32eSetTargetScope(5, 11, -10.0);
        rl32eSetTargetScope(5, 10, 10.0);
        xpceScopeAcqOK(5, &forced_choice_DWork.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /*trigger Subsystem Block: '<S65>/Sample and Hold' */
  forced_choi_SampleandHold_Start(&forced_choice_B.SampleandHold,
    (rtP_SampleandHold_forced_choice *) &forced_choice_P.SampleandHold);

  /* UniformRandomNumber Block: '<S6>/Uniform Random Number' */
  {
    uint32_T *RandSeed = (uint32_T *)
      &forced_choice_DWork.UniformRandomNumber_IWORK.RandSeed;
    uint32_T r, t;
    *RandSeed = (uint32_T)forced_choice_P.UniformRandomNumber_Seed;
    r = *RandSeed >> 16;
    t = *RandSeed & RT_BIT16;
    *RandSeed = ((*RandSeed - (r << 16) - t) << 16) + t + r;
    if (*RandSeed < 1) {
      *RandSeed = SEED0;
    }

    if (*RandSeed > MAXSEED) {
      *RandSeed = MAXSEED;
    }

    forced_choice_DWork.UniformRandomNumber_RWORK.NextOutput
      = rt_Urand(RandSeed++) * (forced_choice_P.UniformRandomNumber_Max -
      forced_choice_P.UniformRandomNumber_Min) +
      forced_choice_P.UniformRandomNumber_Min;
  }

  /*trigger Subsystem Block: '<S6>/Sample and Hold' */
  forced_choi_SampleandHold_Start(&forced_choice_B.SampleandHold_i,
    (rtP_SampleandHold_forced_choice *) &forced_choice_P.SampleandHold_i);

  /* Start for iterator system: '<S13>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Start for iterator system: '<S70>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = forced_choice_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  forced_choice_DWork.EnabledSubsystem_hg.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  forced_choice_DWork.EnabledSubsystem_i.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  forced_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  forced_choice_DWork.SampleandHold_i.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  forced_choice_DWork.SampleandHold.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;

  /* user code (Start function Trailer) */
  rl32eSetScope(2, 8, 1);
  rl32eSetScope(6, 8, 1);
  rl32eSetScope(3, 8, 1);
  rl32eSetScope(7, 8, 1);
  rl32eSetScope(1, 8, 1);
  rl32eSetScope(5, 8, 1);
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
