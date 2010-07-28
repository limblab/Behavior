/*
 * center_out.c
 *
 * Real-Time Workshop code generation for Simulink model "center_out.mdl".
 *
 * Model Version              : 1.1201
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:09 2010
 */

#include "rt_logging_mmi.h"
#include "center_out_capi.h"
#include "center_out.h"
#include "center_out_private.h"
#include <stdio.h>
#include "center_out_dt.h"

/* Block signals (auto storage) */
BlockIO_center_out center_out_B;

/* Block states (auto storage) */
D_Work_center_out center_out_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_center_out center_out_PrevZCSigState;

/* Real-time model */
rtModel_center_out center_out_rtM_;
rtModel_center_out *center_out_rtM = &center_out_rtM_;
static void rate_monotonic_scheduler(void);

/* Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void center_out_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(center_out_rtM, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(center_out_rtM, 2));
}

time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(center_out_rtM, 1);
  rtmSampleHitPtr[2] = rtmStepTask(center_out_rtM, 2);
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
  if (center_out_rtM->Timing.TaskCounters.TID[1] == 0) {
    center_out_rtM->Timing.RateInteraction.TID1_2 =
      (center_out_rtM->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    center_out_rtM->Timing.perTaskSampleHits[5] =
      center_out_rtM->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++center_out_rtM->Timing.TaskCounters.TID[2] == 20) {/* Sample time: [0.02s, 0.0s] */
    center_out_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  center_out_rtM->Timing.sampleHits[2] =
    (center_out_rtM->Timing.TaskCounters.TID[2] == 0);
}

/* Disable for enable system:
 *   '<S31>/Enabled Subsystem'
 *   '<S43>/Enabled Subsystem'
 *   '<S44>/Enabled Subsystem'
 *   '<S45>/Enabled Subsystem'
 *   '<S47>/Enabled Subsystem'
 */
void center_EnabledSubsystem_Disable(rtDW_EnabledSubsystem_center_ou *localDW)
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
void center_out_EnabledSubsystem(int_T tid, boolean_T rtu_0, real_T rtu_1,
  rtB_EnabledSubsystem_center_out *localB, rtDW_EnabledSubsystem_center_ou
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
        center_EnabledSubsystem_Disable(localDW);
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
void center_out_SampleandHold_Start(rtB_SampleandHold_center_out *localB,
  rtP_SampleandHold_center_out *localP)
{
  /* virtual outports code */

  /* (Virtual) Outport Block: '<S64>/ ' */
  localB->In = localP->_Y0;
}

/* Output and update for trigger system:
 *   '<S6>/Sample and Hold'
 *   '<S65>/Sample and Hold'
 */
void center_out_SampleandHold(real_T rtu_0, real_T rtu_1,
  rtB_SampleandHold_center_out *localB, rtDW_SampleandHold_center_out *localDW,
  rtZCE_SampleandHold_center_out *localZCE)
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
void center_out_output(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  if (tid == 0) {
    srClearBC(center_out_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC);
    srClearBC(center_out_DWork.EnabledSubsystem_i.EnabledSubsystem_SubsysRanBC);
    srClearBC(center_out_DWork.EnabledSubsystem_ir.EnabledSubsystem_SubsysRanBC);
    srClearBC(center_out_DWork.EnabledSubsystem_n.EnabledSubsystem_SubsysRanBC);
    srClearBC(center_out_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC);
    srClearBC(center_out_DWork.SampleandHold_e.SampleandHold_SubsysRanBC);
    srClearBC(center_out_DWork.SampleandHold.SampleandHold_SubsysRanBC);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S31>/Clock'
     */
    center_out_B.Clock = center_out_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S31>/Memory' */
    center_out_B.Memory = center_out_DWork.Memory_PreviousInput;

    /* Memory: '<S4>/Memory' */
    center_out_B.Memory_o = center_out_DWork.Memory_PreviousInput_e;

    /* Logic: '<S31>/Logical Operator2' */
    center_out_B.LogicalOperator2 = (center_out_B.Memory ||
      center_out_B.Memory_o);

    /* Logic: '<S31>/Logical Operator1' */
    center_out_B.LogicalOperator1 = !center_out_B.LogicalOperator2;

    /* SignalConversion: '<S31>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    center_out_B.HiddenBuf_InsertedFor_EnabledSu = center_out_B.LogicalOperator1;
  }

  /* SubSystem Block: '<S31>/Enabled Subsystem'
   */
  center_out_EnabledSubsystem(tid, center_out_B.HiddenBuf_InsertedFor_EnabledSu,
    center_out_B.Clock, &center_out_B.EnabledSubsystem,
    &center_out_DWork.EnabledSubsystem);
  if (tid == 0) {
    /* Sum: '<S31>/Sum' */
    center_out_B.Sum = center_out_B.Clock - center_out_B.EnabledSubsystem.In1;

    /* RelationalOperator: '<S34>/Compare' */
    center_out_B.Compare = (center_out_B.Sum > 0.0);

    /* RelationalOperator: '<S31>/Relational Operator' incorporates:
     *  Constant: '<S31>/Time'
     */
    center_out_B.RelationalOperator = (center_out_B.Sum >
      center_out_P.Time_Value);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S31>/Logical Operator' */
    center_out_B.LogicalOperator = (boolean_T)((center_out_B.Compare != 0U) ^
      center_out_B.RelationalOperator);

    /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S13>/Gain' */
    center_out_B.Gain = center_out_P.Gain_Gain * center_out_B.PCIQUAD04;

    /* Sum: '<S13>/Sum3' incorporates:
     *  Constant: '<S13>/shoulderOffset'
     */
    center_out_B.Sum3 = center_out_B.Gain + center_out_P.shoulderOffset_Value;

    /* Trigonometry: '<S71>/Trigonometric Function' */
    center_out_B.TrigonometricFunction = cos(center_out_B.Sum3);

    /* Product: '<S71>/Product' incorporates:
     *  Constant: '<S71>/L1'
     */
    center_out_B.Product = center_out_B.TrigonometricFunction *
      center_out_P.L1_Value;

    /* Gain: '<S71>/Gain' */
    center_out_B.MatrixConcatenate2[0] = center_out_P.Gain_Gain_h *
      center_out_B.Product;

    /* Trigonometry: '<S71>/Trigonometric Function1' */
    center_out_B.TrigonometricFunction1 = sin(center_out_B.Sum3);

    /* Product: '<S71>/Product1' incorporates:
     *  Constant: '<S71>/L1'
     */
    center_out_B.Product1 = center_out_B.TrigonometricFunction1 *
      center_out_P.L1_Value;

    /* SignalConversion: '<S71>/ConcatHiddenBufferAtMatrix ConcatenateInPort1' */
    center_out_B.MatrixConcatenate2[1] = center_out_B.Product1;

    /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[9];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S13>/Gain1' */
    center_out_B.Gain1 = center_out_P.Gain1_Gain * center_out_B.PCIQUAD041;

    /* Sum: '<S13>/Sum1' incorporates:
     *  Constant: '<S13>/elbowOffset'
     */
    center_out_B.Sum1 = center_out_B.Gain1 + center_out_P.elbowOffset_Value;

    /* Trigonometry: '<S71>/Trigonometric Function2' */
    center_out_B.TrigonometricFunction2 = sin(center_out_B.Sum1);

    /* Product: '<S71>/Product2' incorporates:
     *  Constant: '<S71>/L2'
     */
    center_out_B.Product2 = center_out_B.TrigonometricFunction2 *
      center_out_P.L2_Value;

    /* Gain: '<S71>/Gain1' */
    center_out_B.MatrixConcatenate2[2] = center_out_P.Gain1_Gain_o *
      center_out_B.Product2;

    /* Trigonometry: '<S71>/Trigonometric Function3' */
    center_out_B.TrigonometricFunction3 = cos(center_out_B.Sum1);

    /* Product: '<S71>/Product3' incorporates:
     *  Constant: '<S71>/L2'
     */
    center_out_B.Product3 = center_out_B.TrigonometricFunction3 *
      center_out_P.L2_Value;

    /* Gain: '<S71>/Gain2' */
    center_out_B.MatrixConcatenate2[3] = center_out_P.Gain2_Gain *
      center_out_B.Product3;

    /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[10];
      sfcnOutputs(rts, 1);
    }

    {
      real_T tmp;
      real_T tmp_0;

      /* Sum: '<S71>/Sum2' */
      center_out_B.Sum2 = (0.0 - center_out_B.Product) - center_out_B.Product2;

      /* Sum: '<S71>/Sum4' incorporates:
       *  Constant: '<S71>/yoffset'
       */
      center_out_B.Sum4 = center_out_B.Sum2 + center_out_P.yoffset_Value;

      /* Sum: '<S71>/Sum3' */
      center_out_B.Sum3_d = center_out_B.Product3 - center_out_B.Product1;

      /* Sum: '<S71>/Sum1' incorporates:
       *  Constant: '<S71>/xoffset'
       */
      center_out_B.Sum1_k = center_out_B.Sum3_d + center_out_P.xoffset_Value;

      /* Trigonometry: '<S69>/Trigonometric Function1' */
      center_out_B.TrigonometricFunction1_p = rt_atan2(center_out_B.Sum4,
        center_out_B.Sum1_k);

      /* Sum: '<S69>/Sum' incorporates:
       *  Constant: '<S69>/AngleOffset'
       */
      center_out_B.Sum_j = center_out_B.TrigonometricFunction1_p +
        center_out_P.AngleOffset_Value;

      /* Trigonometry: '<S69>/Trigonometric Function2' */
      center_out_B.TrigonometricFunction2_j = cos(center_out_B.Sum_j);

      /* Fcn: '<S69>/sqrt(u[1]*u[1] + u[2]*u[2])' */
      tmp = center_out_B.Sum4;
      tmp_0 = center_out_B.Sum1_k;
      center_out_B.sqrtu1u1u2u2 = sqrt(tmp * tmp + tmp_0 * tmp_0);

      /* Product: '<S69>/Product1' */
      center_out_B.Product1_d = center_out_B.TrigonometricFunction2_j *
        center_out_B.sqrtu1u1u2u2;
    }

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&center_out_B.Product1_d, &center_out_B.DigitalFilter2,
                    &center_out_DWork.DigitalFilter2_FILT_STATES[0],
                    &center_out_DWork.DigitalFilter2_CIRCBUFFIDX, 11, 1, 1,
                    &center_out_P.DigitalFilter2_RTP1COEFF[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S67>/Derivative' */
    {
      real_T t = center_out_rtM->Timing.t[0];
      real_T timeStampA = center_out_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = center_out_DWork.Derivative_RWORK.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        center_out_B.Derivative = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &center_out_DWork.Derivative_RWORK.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        center_out_B.Derivative = (center_out_B.DigitalFilter2 - *lastBank++) /
          deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S67>/dG' */
    center_out_B.dG = center_out_P.dG_Gain * center_out_B.Derivative;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&center_out_B.dG, &center_out_B.DigitalFilter,
                    &center_out_DWork.DigitalFilter_FILT_STATES[0],
                    &center_out_DWork.DigitalFilter_CIRCBUFFIDX, 11, 1, 1,
                    &center_out_P.DigitalFilter_RTP1COEFF[0], 1);

    /* Trigonometry: '<S69>/Trigonometric Function' */
    center_out_B.TrigonometricFunction_d = sin(center_out_B.Sum_j);

    /* Product: '<S69>/Product' */
    center_out_B.Product_l = center_out_B.sqrtu1u1u2u2 *
      center_out_B.TrigonometricFunction_d;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&center_out_B.Product_l, &center_out_B.DigitalFilter2_l,
                    &center_out_DWork.DigitalFilter2_FILT_STATES_h[0],
                    &center_out_DWork.DigitalFilter2_CIRCBUFFIDX_l, 11, 1, 1,
                    &center_out_P.DigitalFilter2_RTP1COEFF_n[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S68>/Derivative' */
    {
      real_T t = center_out_rtM->Timing.t[0];
      real_T timeStampA = center_out_DWork.Derivative_RWORK_d.TimeStampA;
      real_T timeStampB = center_out_DWork.Derivative_RWORK_d.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        center_out_B.Derivative_m = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &center_out_DWork.Derivative_RWORK_d.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        center_out_B.Derivative_m = (center_out_B.DigitalFilter2_l - *lastBank++)
          / deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S68>/dG' */
    center_out_B.dG_f = center_out_P.dG_Gain_a * center_out_B.Derivative_m;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&center_out_B.dG_f, &center_out_B.DigitalFilter_m,
                    &center_out_DWork.DigitalFilter_FILT_STATES_g[0],
                    &center_out_DWork.DigitalFilter_CIRCBUFFIDX_g, 11, 1, 1,
                    &center_out_P.DigitalFilter_RTP1COEFF_n[0], 1);

    {
      real_T tmp;
      real_T tmp_0;

      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S10>/UseTachs'
       */
      if (center_out_P.UseTachs_Value >= center_out_P.Switch_Threshold) {
        {
          real_T tmp;
          real_T tmp_0;

          /* Gain: '<S10>/TachGain2' */
          center_out_B.TachGain2 = center_out_P.TachGain2_Gain *
            center_out_B.PCI6025EAD_o2;

          /* Gain: '<S10>/TachGain1' */
          center_out_B.TachGain1 = center_out_P.TachGain1_Gain *
            center_out_B.PCI6025EAD_o1;

          /* SignalConversion: '<S10>/TmpHiddenBufferAtMatrix MultiplyInport2' */
          tmp = center_out_B.TachGain1;
          tmp_0 = center_out_B.TachGain2;
          center_out_B.TmpHiddenBufferAtMatrixMultiply[0] = tmp;
          center_out_B.TmpHiddenBufferAtMatrixMultiply[1] = tmp_0;
        }

        {
          static const int_T dims[3] = { 2, 2, 1 };

          rt_MatMultRR_Dbl(center_out_B.MatrixMultiply,
                           center_out_B.MatrixConcatenate2,
                           center_out_B.TmpHiddenBufferAtMatrixMultiply, &dims[0]);
        }

        center_out_B.Switch[0] = center_out_B.MatrixMultiply[0];
        center_out_B.Switch[1] = center_out_B.MatrixMultiply[1];
      } else {
        tmp = center_out_B.DigitalFilter;
        tmp_0 = center_out_B.DigitalFilter_m;
        center_out_B.Switch[0] = tmp;
        center_out_B.Switch[1] = tmp_0;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S43>/Clock'
     */
    center_out_B.Clock_e = center_out_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S43>/Memory' */
    center_out_B.Memory_p = center_out_DWork.Memory_PreviousInput_i;

    /* RelationalOperator: '<S1>/Relational Operator' incorporates:
     *  Constant: '<S1>/XLowLimit'
     */
    center_out_B.RelationalOperator_e = (center_out_B.Sum3_d <
      center_out_P.XLowLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator1' incorporates:
     *  Constant: '<S1>/XHighLimit'
     */
    center_out_B.RelationalOperator1 = (center_out_B.Sum3_d >
      center_out_P.XHighLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator2' incorporates:
     *  Constant: '<S1>/YHighLimit'
     */
    center_out_B.RelationalOperator2 = (center_out_B.Sum2 <
      center_out_P.YHighLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator3' incorporates:
     *  Constant: '<S1>/YLowLimit'
     */
    center_out_B.RelationalOperator3 = (center_out_B.Sum2 >
      center_out_P.YLowLimit_Value);

    /* Logic: '<S1>/Logical Operator' */
    center_out_B.LogicalOperator_j = (center_out_B.RelationalOperator_e ||
      center_out_B.RelationalOperator1 || center_out_B.RelationalOperator2 ||
      center_out_B.RelationalOperator3);

    /* Logic: '<S5>/InBox' */
    center_out_B.InBox = !center_out_B.LogicalOperator_j;

    /* Logic: '<S47>/Logical Operator3' */
    center_out_B.LogicalOperator3 = !center_out_B.InBox;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S47>/Clock'
     */
    center_out_B.Clock_o = center_out_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S47>/Memory' */
    center_out_B.Memory_pz = center_out_DWork.Memory_PreviousInput_a;

    /* Logic: '<S47>/Logical Operator4' */
    center_out_B.LogicalOperator4 = (center_out_B.Memory_pz &&
      center_out_B.LogicalOperator3);

    /* RelationalOperator: '<S36>/Compare' */
    center_out_B.Compare_h = (center_out_B.Switch[0] == 0.0);

    /* RelationalOperator: '<S37>/Compare' */
    center_out_B.Compare_o = (center_out_B.Switch[1] == 0.0);

    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Constant: '<S5>/RecenterFlag'
     */
    center_out_B.LogicalOperator_p = ((center_out_P.RecenterFlag_Value != 0.0) &&
                                      (center_out_B.Compare_h != 0U) &&
      (center_out_B.Compare_o != 0U) && center_out_B.LogicalOperator_j);

    /* Logic: '<S47>/Logical Operator2' */
    center_out_B.LogicalOperator2_n = (center_out_B.LogicalOperator4 ||
      center_out_B.LogicalOperator_p);

    /* Logic: '<S47>/Logical Operator1' */
    center_out_B.LogicalOperator1_m = !center_out_B.LogicalOperator2_n;

    /* SignalConversion: '<S47>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    center_out_B.HiddenBuf_InsertedFor_Enabled_c =
      center_out_B.LogicalOperator1_m;
  }

  /* SubSystem Block: '<S47>/Enabled Subsystem'
   */
  center_out_EnabledSubsystem(tid, center_out_B.HiddenBuf_InsertedFor_Enabled_c,
    center_out_B.Clock_o, &center_out_B.EnabledSubsystem_l,
    &center_out_DWork.EnabledSubsystem_l);
  if (tid == 0) {
    /* Sum: '<S47>/Sum' */
    center_out_B.Sum_h = center_out_B.Clock_o -
      center_out_B.EnabledSubsystem_l.In1;

    /* RelationalOperator: '<S60>/Compare' */
    center_out_B.Compare_b = (center_out_B.Sum_h > 0.0);

    /* RelationalOperator: '<S47>/Relational Operator' incorporates:
     *  Constant: '<S47>/Time'
     */
    center_out_B.RelationalOperator_i = (center_out_B.Sum_h >
      center_out_P.Time_Value_h);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S47>/Logical Operator' */
    center_out_B.LogicalOperator_l = (boolean_T)((center_out_B.Compare_b != 0U) ^
      center_out_B.RelationalOperator_i);

    /* RelationalOperator: '<S63>/Compare' */
    center_out_B.Compare_d = (center_out_B.LogicalOperator_l <= FALSE);

    /* UnitDelay: '<S61>/Delay Input1' */
    center_out_B.Uk1 = center_out_DWork.DelayInput1_DSTATE;

    /* RelationalOperator: '<S61>/FixPt Relational Operator' */
    center_out_B.FixPtRelationalOperator = (center_out_B.Compare_d >
      center_out_B.Uk1);

    /* Logic: '<S47>/Logical Operator5' */
    center_out_B.LogicalOperator5 = (center_out_B.LogicalOperator3 &&
      (center_out_B.FixPtRelationalOperator != 0U));

    /* Logic: '<S43>/Logical Operator2' */
    center_out_B.LogicalOperator2_h = (center_out_B.Memory_p ||
      center_out_B.LogicalOperator5);

    /* Logic: '<S43>/Logical Operator1' */
    center_out_B.LogicalOperator1_i = !center_out_B.LogicalOperator2_h;

    /* SignalConversion: '<S43>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    center_out_B.HiddenBuf_InsertedFor_Enabled_d =
      center_out_B.LogicalOperator1_i;
  }

  /* SubSystem Block: '<S43>/Enabled Subsystem'
   */
  center_out_EnabledSubsystem(tid, center_out_B.HiddenBuf_InsertedFor_Enabled_d,
    center_out_B.Clock_e, &center_out_B.EnabledSubsystem_i,
    &center_out_DWork.EnabledSubsystem_i);
  if (tid == 0) {
    /* Sum: '<S43>/Sum' */
    center_out_B.Sum_n = center_out_B.Clock_e -
      center_out_B.EnabledSubsystem_i.In1;

    /* RelationalOperator: '<S53>/Compare' */
    center_out_B.Compare_c = (center_out_B.Sum_n > 0.0);

    /* RelationalOperator: '<S43>/Relational Operator' incorporates:
     *  Constant: '<S43>/Time'
     */
    center_out_B.RelationalOperator_ec = (center_out_B.Sum_n >
      center_out_P.Time_Value_hl);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S43>/Logical Operator' */
    center_out_B.LogicalOperator_pm = (boolean_T)((center_out_B.Compare_c != 0U)
      ^ center_out_B.RelationalOperator_ec);

    /* Abs: '<S40>/Abs2' */
    center_out_B.Abs2 = fabs(center_out_B.Switch[0]);

    /* RelationalOperator: '<S51>/Compare' incorporates:
     *  Constant: '<S51>/Constant'
     */
    center_out_B.Compare_l = (center_out_B.Abs2 <= center_out_P.Constant_Value);

    /* Abs: '<S40>/Abs3' */
    center_out_B.Abs3 = fabs(center_out_B.Switch[1]);

    /* RelationalOperator: '<S52>/Compare' incorporates:
     *  Constant: '<S52>/Constant'
     */
    center_out_B.Compare_e = (center_out_B.Abs3 <= center_out_P.Constant_Value_p);

    /* Logic: '<S40>/Logical Operator1' */
    center_out_B.LogicalOperator1_a = ((center_out_B.Compare_l != 0U) &&
      (center_out_B.Compare_e != 0U));

    /* Logic: '<S5>/NOT' */
    center_out_B.NOT = !center_out_B.LogicalOperator1_a;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S45>/Clock'
     */
    center_out_B.Clock_j = center_out_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S45>/Memory' */
    center_out_B.Memory_d = center_out_DWork.Memory_PreviousInput_j;

    /* RelationalOperator: '<S59>/Compare' */
    center_out_B.Compare_m = (center_out_B.LogicalOperator1_a <= FALSE);

    /* UnitDelay: '<S46>/Delay Input1' */
    center_out_B.Uk1_f = center_out_DWork.DelayInput1_DSTATE_o;

    /* RelationalOperator: '<S46>/FixPt Relational Operator' */
    center_out_B.FixPtRelationalOperator_e = (center_out_B.Compare_m >
      center_out_B.Uk1_f);

    /* Logic: '<S45>/Logical Operator2' */
    center_out_B.LogicalOperator2_f = (center_out_B.Memory_d ||
      (center_out_B.FixPtRelationalOperator_e != 0U));

    /* Logic: '<S45>/Logical Operator1' */
    center_out_B.LogicalOperator1_b = !center_out_B.LogicalOperator2_f;

    /* SignalConversion: '<S45>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    center_out_B.HiddenBuf_InsertedFor_Enabled_g =
      center_out_B.LogicalOperator1_b;
  }

  /* SubSystem Block: '<S45>/Enabled Subsystem'
   */
  center_out_EnabledSubsystem(tid, center_out_B.HiddenBuf_InsertedFor_Enabled_g,
    center_out_B.Clock_j, &center_out_B.EnabledSubsystem_n,
    &center_out_DWork.EnabledSubsystem_n);
  if (tid == 0) {
    /* Sum: '<S45>/Sum' */
    center_out_B.Sum_d = center_out_B.Clock_j -
      center_out_B.EnabledSubsystem_n.In1;

    /* RelationalOperator: '<S57>/Compare' */
    center_out_B.Compare_m2 = (center_out_B.Sum_d > 0.0);

    /* RelationalOperator: '<S45>/Relational Operator' incorporates:
     *  Constant: '<S45>/Time'
     */
    center_out_B.RelationalOperator_a = (center_out_B.Sum_d >
      center_out_P.Time_Value_l);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S45>/Logical Operator' */
    center_out_B.LogicalOperator_o = (boolean_T)((center_out_B.Compare_m2 != 0U)
      ^ center_out_B.RelationalOperator_a);

    /* RelationalOperator: '<S50>/Compare' */
    center_out_B.Compare_g = (center_out_B.LogicalOperator_o <= FALSE);

    /* UnitDelay: '<S39>/Delay Input1' */
    center_out_B.Uk1_e = center_out_DWork.DelayInput1_DSTATE_g;

    /* RelationalOperator: '<S39>/FixPt Relational Operator' */
    center_out_B.FixPtRelationalOperator_i = (center_out_B.Compare_g >
      center_out_B.Uk1_e);

    /* DataTypeConversion: '<S5>/Data Type Conversion2' */
    center_out_B.DataTypeConversion2 = (center_out_B.FixPtRelationalOperator_i
      != 0U);

    /* Logic: '<S5>/Logical Operator1' */
    center_out_B.LogicalOperator1_j = (center_out_B.NOT ||
      center_out_B.DataTypeConversion2);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S44>/Clock'
     */
    center_out_B.Clock_d = center_out_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S44>/Memory' */
    center_out_B.Memory_b = center_out_DWork.Memory_PreviousInput_o;

    /* Logic: '<S44>/Logical Operator2' */
    center_out_B.LogicalOperator2_g = (center_out_B.Memory_b ||
      center_out_B.LogicalOperator5);

    /* Logic: '<S44>/Logical Operator1' */
    center_out_B.LogicalOperator1_be = !center_out_B.LogicalOperator2_g;

    /* SignalConversion: '<S44>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    center_out_B.HiddenBuf_InsertedFor_Enabled_e =
      center_out_B.LogicalOperator1_be;
  }

  /* SubSystem Block: '<S44>/Enabled Subsystem'
   */
  center_out_EnabledSubsystem(tid, center_out_B.HiddenBuf_InsertedFor_Enabled_e,
    center_out_B.Clock_d, &center_out_B.EnabledSubsystem_ir,
    &center_out_DWork.EnabledSubsystem_ir);
  if (tid == 0) {
    /* Sum: '<S44>/Sum' */
    center_out_B.Sum_ju = center_out_B.Clock_d -
      center_out_B.EnabledSubsystem_ir.In1;

    /* RelationalOperator: '<S55>/Compare' */
    center_out_B.Compare_mk = (center_out_B.Sum_ju > 0.0);

    /* RelationalOperator: '<S44>/Relational Operator' incorporates:
     *  Constant: '<S44>/Time'
     */
    center_out_B.RelationalOperator_j = (center_out_B.Sum_ju >
      center_out_P.Time_Value_d);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S44>/Logical Operator' */
    center_out_B.LogicalOperator_i = (boolean_T)((center_out_B.Compare_mk != 0U)
      ^ center_out_B.RelationalOperator_j);

    /* RelationalOperator: '<S49>/Compare' */
    center_out_B.Compare_p = (center_out_B.LogicalOperator_i <= FALSE);

    /* UnitDelay: '<S38>/Delay Input1' */
    center_out_B.Uk1_o = center_out_DWork.DelayInput1_DSTATE_m;

    /* RelationalOperator: '<S38>/FixPt Relational Operator' */
    center_out_B.FixPtRelationalOperator_l = (center_out_B.Compare_p >
      center_out_B.Uk1_o);

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    center_out_B.DataTypeConversion1 = (center_out_B.FixPtRelationalOperator_l
      != 0U);

    /* Memory: '<S42>/Memory' */
    center_out_B.Memory_be = center_out_DWork.Memory_PreviousInput_b;

    /* CombinatorialLogic Block: '<S42>/Logic'
     */
    {
      int_T rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (int_T)(center_out_B.LogicalOperator1_j != 0);
      rowidx = (rowidx << 1) + (int_T)(center_out_B.DataTypeConversion1 != 0);
      rowidx = (rowidx << 1) + (int_T)(center_out_B.Memory_be != 0);

      /* Copy the appropriate row of the table into the block output vector */
      center_out_B.Logic[0] = center_out_P.Logic_table[rowidx];
      center_out_B.Logic[1] = center_out_P.Logic_table[rowidx + 8];
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
      center_out_B.LogicalOperator5_d = (center_out_B.Logic[1] ||
        center_out_B.LogicalOperator_i || center_out_B.LogicalOperator_j);

      /* UnitDelay: '<S23>/x' */
      center_out_B.x = center_out_DWork.x_DSTATE;

      /* UnitDelay: '<S24>/x' */
      center_out_B.x_j = center_out_DWork.x_DSTATE_m;

      /* Sum: '<S21>/Add' */
      center_out_B.Add = center_out_B.x - center_out_B.x_j;

      /* UnitDelay: '<S25>/x' */
      center_out_B.x_k = center_out_DWork.x_DSTATE_a;

      /* UnitDelay: '<S26>/x' */
      center_out_B.x_l = center_out_DWork.x_DSTATE_p;

      /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
       *  Constant: '<S3>/Load'
       *  Constant: '<S3>/Off'
       *  Constant: '<S3>/staticX'
       *  Constant: '<S3>/staticY'
       */
      switch ((int32_T)center_out_P.Load_Value) {
       case 0:
        tmp = center_out_P.Off_Value_k;
        tmp_0 = center_out_P.Off_Value_k;
        center_out_B.MultiportSwitch[0] = tmp;
        center_out_B.MultiportSwitch[1] = tmp_0;
        break;

       case 1:
        tmp_1 = center_out_P.staticX_Value_c;
        tmp_2 = center_out_P.staticY_Value_n;
        center_out_B.MultiportSwitch[0] = tmp_1;
        center_out_B.MultiportSwitch[1] = tmp_2;
        break;

       case 2:
        /* Sum: '<S21>/Add1' */
        center_out_B.Add1_k = center_out_B.x_k - center_out_B.x_l;

        /* Gain: '<S3>/LorentzForceGain' */
        tmp_7 = center_out_B.Add;
        tmp_8 = center_out_B.Add1_k;
        center_out_B.LorentzForceGain[0] = center_out_P.LorentzForceGain_Gain_j *
          tmp_7;
        center_out_B.LorentzForceGain[1] = center_out_P.LorentzForceGain_Gain_j *
          tmp_8;
        center_out_B.MultiportSwitch[0] = center_out_B.LorentzForceGain[0];
        center_out_B.MultiportSwitch[1] = center_out_B.LorentzForceGain[1];
        break;

       default:
        /* MultiPortSwitch: '<S3>/dynamicAngle Switch' incorporates:
         *  Constant: '<S3>/DynamicAngle'
         *  Constant: '<S3>/visAngle'
         */
        if ((int32_T)center_out_P.DynamicAngle_Value_k == 0) {
          center_out_B.dynamicAngleSwitch = center_out_P.visAngle_Value_g;
        } else {
          /* Gain: '<S3>/Gain' */
          center_out_B.Gain_l = center_out_P.Gain_Gain_g * center_out_B.Add;
          center_out_B.dynamicAngleSwitch = center_out_B.Gain_l;
        }

        /* Trigonometry: '<S22>/sin' */
        center_out_B.sin_o = sin(center_out_B.dynamicAngleSwitch);

        /* Gain: '<S22>/Inverter' */
        center_out_B.Inverter[0] = center_out_P.Inverter_Gain_o *
          center_out_B.Switch[0];
        center_out_B.Inverter[1] = center_out_P.Inverter_Gain_o *
          center_out_B.Switch[1];

        /* Product: '<S22>/Product3' */
        cg_in = center_out_B.Inverter[0];
        center_out_B.Product3_f = cg_in * center_out_B.sin_o;

        /* Trigonometry: '<S22>/cos' */
        center_out_B.cos_l = cos(center_out_B.dynamicAngleSwitch);

        /* Product: '<S22>/Product2' */
        cg_in_0 = center_out_B.Inverter[1];
        center_out_B.Product2_k = cg_in_0 * center_out_B.cos_l;

        /* Sum: '<S22>/Subtract' */
        center_out_B.Subtract_k = center_out_B.Product2_k -
          center_out_B.Product3_f;

        /* Product: '<S22>/Product1' */
        cg_in_1 = center_out_B.Inverter[1];
        center_out_B.Product1_c = cg_in_1 * center_out_B.sin_o;

        /* Product: '<S22>/Product' */
        cg_in_2 = center_out_B.Inverter[0];
        center_out_B.Product_h = cg_in_2 * center_out_B.cos_l;

        /* Sum: '<S22>/Add' */
        center_out_B.Add_h = center_out_B.Product_h + center_out_B.Product1_c;

        /* Gain: '<S22>/Gain' */
        tmp_9 = center_out_B.Add_h;
        tmp_a = center_out_B.Subtract_k;
        center_out_B.Gain_k[0] = center_out_P.Gain_Gain_lp * tmp_9;
        center_out_B.Gain_k[1] = center_out_P.Gain_Gain_lp * tmp_a;
        center_out_B.MultiportSwitch[0] = center_out_B.Gain_k[0];
        center_out_B.MultiportSwitch[1] = center_out_B.Gain_k[1];
        break;
      }

      /* UnitDelay: '<S17>/x' */
      center_out_B.x_g = center_out_DWork.x_DSTATE_b;

      /* UnitDelay: '<S18>/x' */
      center_out_B.x_f = center_out_DWork.x_DSTATE_a5;

      /* Sum: '<S15>/Add' */
      center_out_B.Add_g = center_out_B.x_g - center_out_B.x_f;

      /* UnitDelay: '<S19>/x' */
      center_out_B.x_p = center_out_DWork.x_DSTATE_h;

      /* UnitDelay: '<S20>/x' */
      center_out_B.x_g2 = center_out_DWork.x_DSTATE_b2;

      /* MultiPortSwitch: '<S2>/LoadSelect Switch' incorporates:
       *  Constant: '<S2>/Load'
       *  Constant: '<S2>/Off'
       *  Constant: '<S2>/staticX'
       *  Constant: '<S2>/staticY'
       */
      switch ((int32_T)center_out_P.Load_Value_m) {
       case 0:
        tmp_3 = center_out_P.Off_Value;
        tmp_4 = center_out_P.Off_Value;
        center_out_B.LoadSelectSwitch[0] = tmp_3;
        center_out_B.LoadSelectSwitch[1] = tmp_4;
        break;

       case 1:
        tmp_5 = center_out_P.staticX_Value;
        tmp_6 = center_out_P.staticY_Value;
        center_out_B.LoadSelectSwitch[0] = tmp_5;
        center_out_B.LoadSelectSwitch[1] = tmp_6;
        break;

       case 2:
        /* Sum: '<S15>/Add1' */
        center_out_B.Add1_j2 = center_out_B.x_p - center_out_B.x_g2;

        /* Gain: '<S2>/LorentzForceGain' */
        tmp_b = center_out_B.Add_g;
        tmp_c = center_out_B.Add1_j2;
        center_out_B.LorentzForceGain_o[0] = center_out_P.LorentzForceGain_Gain *
          tmp_b;
        center_out_B.LorentzForceGain_o[1] = center_out_P.LorentzForceGain_Gain *
          tmp_c;
        center_out_B.LoadSelectSwitch[0] = center_out_B.LorentzForceGain_o[0];
        center_out_B.LoadSelectSwitch[1] = center_out_B.LorentzForceGain_o[1];
        break;

       default:
        /* MultiPortSwitch: '<S2>/DynamicAngle Switch' incorporates:
         *  Constant: '<S2>/DynamicAngle'
         *  Constant: '<S2>/visAngle'
         */
        if ((int32_T)center_out_P.DynamicAngle_Value == 0) {
          center_out_B.DynamicAngleSwitch = center_out_P.visAngle_Value;
        } else {
          /* Gain: '<S2>/Gain' */
          center_out_B.Gain_d = center_out_P.Gain_Gain_i * center_out_B.Add_g;
          center_out_B.DynamicAngleSwitch = center_out_B.Gain_d;
        }

        /* Trigonometry: '<S16>/sin' */
        center_out_B.sin_f = sin(center_out_B.DynamicAngleSwitch);

        /* Gain: '<S16>/Inverter' */
        center_out_B.Inverter_f[0] = center_out_P.Inverter_Gain *
          center_out_B.Switch[0];
        center_out_B.Inverter_f[1] = center_out_P.Inverter_Gain *
          center_out_B.Switch[1];

        /* Product: '<S16>/Product3' */
        cg_in_3 = center_out_B.Inverter_f[0];
        center_out_B.Product3_b = cg_in_3 * center_out_B.sin_f;

        /* Trigonometry: '<S16>/cos' */
        center_out_B.cos_j = cos(center_out_B.DynamicAngleSwitch);

        /* Product: '<S16>/Product2' */
        cg_in_4 = center_out_B.Inverter_f[1];
        center_out_B.Product2_p = cg_in_4 * center_out_B.cos_j;

        /* Sum: '<S16>/Subtract' */
        center_out_B.Subtract_l = center_out_B.Product2_p -
          center_out_B.Product3_b;

        /* Product: '<S16>/Product1' */
        cg_in_5 = center_out_B.Inverter_f[1];
        center_out_B.Product1_i = cg_in_5 * center_out_B.sin_f;

        /* Product: '<S16>/Product' */
        cg_in_6 = center_out_B.Inverter_f[0];
        center_out_B.Product_o = cg_in_6 * center_out_B.cos_j;

        /* Sum: '<S16>/Add' */
        center_out_B.Add_c = center_out_B.Product_o + center_out_B.Product1_i;

        /* Gain: '<S16>/Gain' */
        tmp_d = center_out_B.Add_c;
        tmp_e = center_out_B.Subtract_l;
        center_out_B.Gain_lz[0] = center_out_P.Gain_Gain_iu * tmp_d;
        center_out_B.Gain_lz[1] = center_out_P.Gain_Gain_iu * tmp_e;
        center_out_B.LoadSelectSwitch[0] = center_out_B.Gain_lz[0];
        center_out_B.LoadSelectSwitch[1] = center_out_B.Gain_lz[1];
        break;
      }
    }

    /* Level2 S-Function Block: '<Root>/Behavior CO' (mastercon_co) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[11];
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
      if (center_out_B.LogicalOperator) {
        tmp = center_out_P.zeroX_Value;
        tmp_0 = center_out_P.zeroY_Value;
        center_out_B.Switch2[0] = tmp;
        center_out_B.Switch2[1] = tmp_0;
      } else {
        /* Switch: '<S4>/Switch1' */
        if (center_out_B.LogicalOperator5_d) {
          /* Logic: '<S5>/Logical Operator6' */
          center_out_B.LogicalOperator6 = !center_out_B.LogicalOperator_pm;

          /* Logic: '<S5>/Logical Operator3' */
          center_out_B.LogicalOperator3_b = (center_out_B.LogicalOperator6 &&
            center_out_B.LogicalOperator_j);

          /* Switch: '<S5>/Switch' */
          if (center_out_B.LogicalOperator3_b) {
            /* Gain: '<S5>/Bounding Box Viscosity' */
            center_out_B.BoundingBoxViscosity[0] =
              center_out_P.BoundingBoxViscosity_Gain * center_out_B.Switch[0];
            center_out_B.BoundingBoxViscosity[1] =
              center_out_P.BoundingBoxViscosity_Gain * center_out_B.Switch[1];
            center_out_B.Switch_o[0] = center_out_B.BoundingBoxViscosity[0];
            center_out_B.Switch_o[1] = center_out_B.BoundingBoxViscosity[1];
          } else {
            /* Product: '<S41>/Product' */
            center_out_B.Product_a = (int32_T)center_out_B.LogicalOperator_pm ?
              center_out_B.Product1_d : 0.0;

            /* Gain: '<S41>/Gain1' */
            center_out_B.Gain1_i = center_out_P.Gain1_Gain_p *
              center_out_B.Product_a;

            /* Gain: '<S41>/Gain3' */
            center_out_B.Gain3 = center_out_P.Gain3_Gain * center_out_B.Switch[0];

            /* Sum: '<S41>/Add' */
            center_out_B.Add_gi = center_out_B.Gain3 + center_out_B.Gain1_i;

            /* Saturate: '<S41>/Saturation' */
            rtsaturate_U0DataInY0Container = rt_SATURATE(center_out_B.Add_gi,
              center_out_P.Saturation_LowerSat, center_out_P.Saturation_UpperSat);
            center_out_B.Saturation = rtsaturate_U0DataInY0Container;

            /* Gain: '<S41>/Gain4' */
            center_out_B.Gain4 = center_out_P.Gain4_Gain * center_out_B.Switch[1];

            /* Product: '<S41>/Product1' */
            center_out_B.Product1_k = (int32_T)center_out_B.LogicalOperator_pm ?
              center_out_B.Product_l : 0.0;

            /* Gain: '<S41>/Gain2' */
            center_out_B.Gain2 = center_out_P.Gain2_Gain_e *
              center_out_B.Product1_k;

            /* Sum: '<S41>/Add1' */
            center_out_B.Add1_a = center_out_B.Gain2 + center_out_B.Gain4;

            /* Saturate: '<S41>/Saturation1' */
            rtsaturate_U0DataInY0Containe_0 = rt_SATURATE(center_out_B.Add1_a,
              center_out_P.Saturation1_LowerSat,
              center_out_P.Saturation1_UpperSat);
            center_out_B.Saturation1 = rtsaturate_U0DataInY0Containe_0;
            tmp_1 = center_out_B.Saturation;
            tmp_2 = center_out_B.Saturation1;
            center_out_B.Switch_o[0] = tmp_1;
            center_out_B.Switch_o[1] = tmp_2;
          }

          center_out_B.Switch1[0] = center_out_B.Switch_o[0];
          center_out_B.Switch1[1] = center_out_B.Switch_o[1];
        } else {
          center_out_B.Switch1[0] = center_out_B.BehaviorCO_o1[0];
          center_out_B.Switch1[1] = center_out_B.BehaviorCO_o1[1];
        }

        center_out_B.Switch2[0] = center_out_B.Switch1[0];
        center_out_B.Switch2[1] = center_out_B.Switch1[1];
      }

      /* Output and update for atomic system: '<S4>/Force//Torque Transform' */

      /* Gain: '<S29>/Gain' */
      center_out_B.Gain_e[0] = center_out_P.Gain_Gain_d * center_out_B.Switch2[0];
      center_out_B.Gain_e[1] = center_out_P.Gain_Gain_d * center_out_B.Switch2[1];

      /* Math Block: '<S33>/Math Function'
       */
      /* Operator : transpose */
      {
        uint32_T count = 0;
        uint32_T row;
        uint32_T col;
        for (row= 0; row < 2; row++) {
          for (col= 0; col < 2; col++) {
            center_out_B.MathFunction[row + 2 * col] =
              center_out_B.MatrixConcatenate2[count];
            count++;
          }
        }
      }

      {
        static const int_T dims[3] = { 2, 2, 1 };

        rt_MatMultRR_Dbl(center_out_B.MatrixMultiply_k,
                         center_out_B.MathFunction,
                         center_out_B.Gain_e, &dims[0]);
      }

      /* Gain: '<S4>/MG1' */
      center_out_B.MG1 = center_out_P.MG1_Gain * center_out_B.MatrixMultiply_k[0];

      /* Gain: '<S4>/MG2' */
      center_out_B.MG2 = center_out_P.MG2_Gain * center_out_B.MatrixMultiply_k[1];
    }

    /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[12];
      sfcnOutputs(rts, 1);
    }

    /* ok to acquire for <S30>/S-Function */
    center_out_DWork.SFunction_IWORK.AcquireOK = 1;

    /* ok to acquire for <S32>/S-Function */
    center_out_DWork.SFunction_IWORK_f.AcquireOK = 1;

    /* RelationalOperator: '<S27>/Compare' incorporates:
     *  Constant: '<S27>/Constant'
     */
    center_out_B.Compare_ci = (center_out_B.MG1 > center_out_P.Constant_Value_h);

    /* RelationalOperator: '<S28>/Compare' incorporates:
     *  Constant: '<S28>/Constant'
     */
    center_out_B.Compare_hx = (center_out_B.MG2 > center_out_P.Constant_Value_k);

    /* SignalConversion: '<S4>/ConcatHiddenBufferAtMatrix ConcatenationInPort0' */
    center_out_B.MatrixConcatenation[0] = center_out_B.LogicalOperator5_d;

    /* SignalConversion: '<S4>/ConcatHiddenBufferAtMatrix ConcatenationInPort1' */
    center_out_B.MatrixConcatenation[1] = center_out_B.LogicalOperator;

    /* Logic: '<S4>/Logical Operator1' */
    center_out_B.LogicalOperator1_bt = ((center_out_B.Compare_ci != 0U) ||
      (center_out_B.Compare_hx != 0U));

    /* ok to acquire for <S7>/S-Function */
    center_out_DWork.SFunction_IWORK_b.AcquireOK = 1;

    /* Pack: <S9>/Pack */
    (void) memcpy(center_out_B.Pack,&center_out_B.BehaviorCO_o8[0],
                  8);
    (void) memcpy(&center_out_B.Pack[8],&center_out_B.BehaviorCO_o8[1],
                  8);
    (void) memcpy(&center_out_B.Pack[16],&center_out_B.BehaviorCO_o4[0],
                  8);
    (void) memcpy(&center_out_B.Pack[24],&center_out_B.BehaviorCO_o4[1],
                  8);
    (void) memcpy(&center_out_B.Pack[32],&center_out_B.BehaviorCO_o4[2],
                  8);
    (void) memcpy(&center_out_B.Pack[40],&center_out_B.BehaviorCO_o4[3],
                  8);
    (void) memcpy(&center_out_B.Pack[48],&center_out_B.BehaviorCO_o4[4],
                  8);
    (void) memcpy(&center_out_B.Pack[56],&center_out_B.BehaviorCO_o4[5],
                  8);
    (void) memcpy(&center_out_B.Pack[64],&center_out_B.BehaviorCO_o4[6],
                  8);
    (void) memcpy(&center_out_B.Pack[72],&center_out_B.BehaviorCO_o4[7],
                  8);
    (void) memcpy(&center_out_B.Pack[80],&center_out_B.BehaviorCO_o4[8],
                  8);
    (void) memcpy(&center_out_B.Pack[88],&center_out_B.BehaviorCO_o4[9],
                  8);
    (void) memcpy(&center_out_B.Pack[96],&center_out_B.BehaviorCO_o6[0],
                  8);
    (void) memcpy(&center_out_B.Pack[104],&center_out_B.BehaviorCO_o6[1],
                  8);
  }

  {
    int32_T i;

    /* RateTransition: '<S9>/Rate Transition' */
    if (tid == 0 && center_out_rtM->Timing.RateInteraction.TID1_2) {
      for (i = 0; i < 112; i++) {
        center_out_B.RateTransition[i] = center_out_B.Pack[i];
      }
    }
  }

  if (tid == 2) {                      /* Sample time: [0.02s, 0.0s] */
    /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[13];
      sfcnOutputs(rts, 2);
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* ok to acquire for <S11>/S-Function */
    center_out_DWork.SFunction_IWORK_d.AcquireOK = 1;

    /* ok to acquire for <S14>/S-Function */
    center_out_DWork.SFunction_IWORK_p.AcquireOK = 1;

    /* ok to acquire for <S48>/S-Function */
    center_out_DWork.SFunction_IWORK_a.AcquireOK = 1;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S65>/Clock'
     */
    center_out_B.Clock_a = center_out_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* SignalConversion: '<S65>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    center_out_B.HiddenBuf_InsertedFor_Sampleand = center_out_B.BehaviorCO_o5;
  }

  /* SubSystem Block: '<S65>/Sample and Hold'
   */
  if (tid == 0) {
    center_out_SampleandHold(center_out_B.HiddenBuf_InsertedFor_Sampleand,
      center_out_B.Clock_a, &center_out_B.SampleandHold,
      &center_out_DWork.SampleandHold, &center_out_PrevZCSigState.SampleandHold);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Sum: '<S65>/Sum' */
    center_out_B.Sum_c = center_out_B.Clock_a - center_out_B.SampleandHold.In;
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* UniformRandomNumber Block: '<S6>/Uniform Random Number'
     */
    center_out_B.UniformRandomNumber =
      center_out_DWork.UniformRandomNumber_RWORK.NextOutput;

    /* RelationalOperator: '<S6>/Relational Operator' incorporates:
     *  Constant: '<S6>/JackpotChance'
     */
    center_out_B.RelationalOperator_o = (center_out_B.UniformRandomNumber >
      center_out_P.JackpotChance_Value);

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/RewardJackpot'
     *  Constant: '<S6>/RewardTime'
     */
    if (center_out_B.RelationalOperator_o) {
      center_out_B.Switch_m = center_out_P.RewardTime_Value;
    } else {
      center_out_B.Switch_m = center_out_P.RewardJackpot_Value;
    }

    /* SignalConversion: '<S6>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    center_out_B.HiddenBuf_InsertedFor_Samplea_i = center_out_B.BehaviorCO_o5;
  }

  /* SubSystem Block: '<S6>/Sample and Hold'
   */
  if (tid == 0) {
    center_out_SampleandHold(center_out_B.HiddenBuf_InsertedFor_Samplea_i,
      center_out_B.Switch_m, &center_out_B.SampleandHold_e,
      &center_out_DWork.SampleandHold_e,
      &center_out_PrevZCSigState.SampleandHold_e);
  }

  {
    int32_T s70_iter;
    real_T tmp;
    real_T tmp_0;
    if (tid == 0) {
      /* RelationalOperator: '<S65>/Relational Operator' */
      center_out_B.RelationalOperator_h = (center_out_B.Sum_c <
        center_out_B.SampleandHold_e.In);

      /* DataTypeConversion: '<S6>/Data Type Conversion' */
      center_out_B.DataTypeConversion = (real_T)
        center_out_B.RelationalOperator_h;
    }

    if (tid == 0) {
      for (s70_iter = 0; s70_iter < 4; s70_iter++) {
        center_out_B.ForIterator = (real_T)s70_iter;

        /* Output and update for iterator system: '<S13>/For Iterator Subsystem' */

        /* Switch: '<S70>/Switch' incorporates:
         *  Constant: '<S70>/Constant2'
         */
        if (center_out_B.ForIterator >= center_out_P.Switch_Threshold_p) {
          center_out_B.Switch_e = center_out_B.BehaviorCO_o3;
        } else {
          center_out_B.Switch_e = center_out_P.Constant2_Value;
        }

        /* Level2 S-Function Block: '<S70>/ToBits1' (Byte2Bits) */
        {
          SimStruct *rts = center_out_rtM->childSfunctions[2];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
        {
          SimStruct *rts = center_out_rtM->childSfunctions[3];
          sfcnOutputs(rts, 1);
        }

        /* Sum: '<S70>/Add' incorporates:
         *  Constant: '<S70>/Constant'
         */
        center_out_B.Add_m = center_out_B.PCIQUAD04 +
          center_out_P.Constant_Value_o;

        /* Sum: '<S70>/Add1' incorporates:
         *  Constant: '<S70>/Constant'
         */
        center_out_B.Add1_dz = center_out_B.PCIQUAD041 +
          center_out_P.Constant_Value_o;

        /* Level2 S-Function Block: '<S70>/SerialConverter' (serPos) */
        {
          SimStruct *rts = center_out_rtM->childSfunctions[4];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/ToBits' (Byte2Bits) */
        {
          SimStruct *rts = center_out_rtM->childSfunctions[5];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
        {
          SimStruct *rts = center_out_rtM->childSfunctions[6];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/xPC Target  Time ' (xpctimeinfo) */
        {
          SimStruct *rts = center_out_rtM->childSfunctions[7];
          sfcnOutputs(rts, 1);
        }

        do {
          /* Output and update for iterator system: '<S70>/While Iterator Subsystem' */

          /* Level2 S-Function Block: '<S72>/xPC Target  Time ' (xpctimeinfo) */
          {
            SimStruct *rts = center_out_rtM->childSfunctions[0];
            sfcnOutputs(rts, 1);
          }

          /* Sum: '<S72>/Subtract' */
          center_out_B.Subtract = center_out_B.xPCTargetTime_d -
            center_out_B.xPCTargetTime;

          /* Gain: '<S72>/ScaleTouSec' */
          center_out_B.ScaleTouSec = center_out_P.ScaleTouSec_Gain *
            center_out_B.Subtract;

          /* RelationalOperator: '<S74>/Compare' incorporates:
           *  Constant: '<S74>/Constant'
           */
          center_out_B.Compare_i = (center_out_B.ScaleTouSec >
            center_out_P.Constant_Value_pu);

          /* Switch: '<S72>/Switch' incorporates:
           *  Constant: '<S72>/Constant'
           *  Constant: '<S72>/Constant1'
           */
          if (center_out_B.Compare_i) {
            center_out_B.Switch_a = center_out_P.Constant_Value_i;
          } else {
            center_out_B.Switch_a = center_out_P.Constant1_Value;
          }

          /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
          {
            SimStruct *rts = center_out_rtM->childSfunctions[1];
            sfcnOutputs(rts, 1);
          }

          /* RelationalOperator: '<S73>/Compare' incorporates:
           *  Constant: '<S73>/Constant'
           */
          center_out_B.Compare_hn = (center_out_B.ScaleTouSec <=
            center_out_P.Constant_Value_c);
        } while (center_out_B.Compare_hn);
      }

      /* UnitDelay: '<S17>/y' */
      center_out_B.y = center_out_DWork.y_DSTATE;

      /* Sum: '<S17>/Add1' */
      center_out_B.Add1 = center_out_B.y - center_out_B.x_g;

      /* UnitDelay: '<S17>/z' */
      center_out_B.z = center_out_DWork.z_DSTATE;

      /* Sum: '<S17>/Add3' incorporates:
       *  Constant: '<S17>/rho'
       */
      center_out_B.Add3 = center_out_P.rho_Value - center_out_B.z;

      /* Product: '<S17>/product2' */
      center_out_B.product2 = center_out_B.x_g * center_out_B.Add3;

      /* Sum: '<S17>/Add2' */
      center_out_B.Add2 = center_out_B.product2 - center_out_B.y;

      /* Product: '<S17>/product3' incorporates:
       *  Constant: '<S17>/beta'
       */
      center_out_B.product3 = center_out_B.z * center_out_P.beta_Value;

      /* Product: '<S17>/product4' */
      center_out_B.product4 = center_out_B.y * center_out_B.x_g;

      /* Sum: '<S17>/Add4' */
      center_out_B.Add4 = center_out_B.product4 - center_out_B.product3;

      /* Product: '<S17>/product1' incorporates:
       *  Constant: '<S17>/sigma'
       */
      center_out_B.product1 = center_out_B.Add1 * center_out_P.sigma_Value;

      /* Product: '<S17>/dX' incorporates:
       *  Constant: '<S17>/timescale'
       */
      center_out_B.dX = center_out_P.timescale_Value * center_out_B.product1;

      /* Sum: '<S17>/AddX' */
      center_out_B.AddX = center_out_B.x_g + center_out_B.dX;

      /* Product: '<S17>/dY' incorporates:
       *  Constant: '<S17>/timescale'
       */
      center_out_B.dY = center_out_P.timescale_Value * center_out_B.Add2;

      /* Sum: '<S17>/AddX1' */
      center_out_B.AddX1 = center_out_B.y + center_out_B.dY;

      /* Product: '<S17>/dZ' incorporates:
       *  Constant: '<S17>/timescale'
       */
      center_out_B.dZ = center_out_P.timescale_Value * center_out_B.Add4;

      /* Sum: '<S17>/AddX2' */
      center_out_B.AddX2 = center_out_B.z + center_out_B.dZ;

      /* UnitDelay: '<S18>/y' */
      center_out_B.y_l = center_out_DWork.y_DSTATE_b;

      /* Sum: '<S18>/Add1' */
      center_out_B.Add1_m = center_out_B.y_l - center_out_B.x_f;

      /* UnitDelay: '<S18>/z' */
      center_out_B.z_h = center_out_DWork.z_DSTATE_c;

      /* Sum: '<S18>/Add3' incorporates:
       *  Constant: '<S18>/rho'
       */
      center_out_B.Add3_i = center_out_P.rho_Value_d - center_out_B.z_h;

      /* Product: '<S18>/product2' */
      center_out_B.product2_b = center_out_B.x_f * center_out_B.Add3_i;

      /* Sum: '<S18>/Add2' */
      center_out_B.Add2_i = center_out_B.product2_b - center_out_B.y_l;

      /* Product: '<S18>/product3' incorporates:
       *  Constant: '<S18>/beta'
       */
      center_out_B.product3_b = center_out_B.z_h * center_out_P.beta_Value_e;

      /* Product: '<S18>/product4' */
      center_out_B.product4_e = center_out_B.y_l * center_out_B.x_f;

      /* Sum: '<S18>/Add4' */
      center_out_B.Add4_a = center_out_B.product4_e - center_out_B.product3_b;

      /* Product: '<S18>/product1' incorporates:
       *  Constant: '<S18>/sigma'
       */
      center_out_B.product1_j = center_out_B.Add1_m * center_out_P.sigma_Value_k;

      /* Product: '<S18>/dX' incorporates:
       *  Constant: '<S18>/timescale'
       */
      center_out_B.dX_o = center_out_P.timescale_Value_m *
        center_out_B.product1_j;

      /* Sum: '<S18>/AddX' */
      center_out_B.AddX_m = center_out_B.x_f + center_out_B.dX_o;

      /* Product: '<S18>/dY' incorporates:
       *  Constant: '<S18>/timescale'
       */
      center_out_B.dY_e = center_out_P.timescale_Value_m * center_out_B.Add2_i;

      /* Sum: '<S18>/AddX1' */
      center_out_B.AddX1_g = center_out_B.y_l + center_out_B.dY_e;

      /* Product: '<S18>/dZ' incorporates:
       *  Constant: '<S18>/timescale'
       */
      center_out_B.dZ_j = center_out_P.timescale_Value_m * center_out_B.Add4_a;

      /* Sum: '<S18>/AddX2' */
      center_out_B.AddX2_n = center_out_B.z_h + center_out_B.dZ_j;

      /* UnitDelay: '<S19>/y' */
      center_out_B.y_m = center_out_DWork.y_DSTATE_j;

      /* Sum: '<S19>/Add1' */
      center_out_B.Add1_d = center_out_B.y_m - center_out_B.x_p;

      /* UnitDelay: '<S19>/z' */
      center_out_B.z_a = center_out_DWork.z_DSTATE_p;

      /* Sum: '<S19>/Add3' incorporates:
       *  Constant: '<S19>/rho'
       */
      center_out_B.Add3_p = center_out_P.rho_Value_n - center_out_B.z_a;

      /* Product: '<S19>/product2' */
      center_out_B.product2_k = center_out_B.x_p * center_out_B.Add3_p;

      /* Sum: '<S19>/Add2' */
      center_out_B.Add2_e = center_out_B.product2_k - center_out_B.y_m;

      /* Product: '<S19>/product3' incorporates:
       *  Constant: '<S19>/beta'
       */
      center_out_B.product3_i = center_out_B.z_a * center_out_P.beta_Value_m;

      /* Product: '<S19>/product4' */
      center_out_B.product4_a = center_out_B.y_m * center_out_B.x_p;

      /* Sum: '<S19>/Add4' */
      center_out_B.Add4_h = center_out_B.product4_a - center_out_B.product3_i;

      /* Product: '<S19>/product1' incorporates:
       *  Constant: '<S19>/sigma'
       */
      center_out_B.product1_a = center_out_B.Add1_d * center_out_P.sigma_Value_e;

      /* Product: '<S19>/dX' incorporates:
       *  Constant: '<S19>/timescale'
       */
      center_out_B.dX_j = center_out_P.timescale_Value_a *
        center_out_B.product1_a;

      /* Sum: '<S19>/AddX' */
      center_out_B.AddX_l = center_out_B.x_p + center_out_B.dX_j;

      /* Product: '<S19>/dY' incorporates:
       *  Constant: '<S19>/timescale'
       */
      center_out_B.dY_eo = center_out_P.timescale_Value_a * center_out_B.Add2_e;

      /* Sum: '<S19>/AddX1' */
      center_out_B.AddX1_a = center_out_B.y_m + center_out_B.dY_eo;

      /* Product: '<S19>/dZ' incorporates:
       *  Constant: '<S19>/timescale'
       */
      center_out_B.dZ_b = center_out_P.timescale_Value_a * center_out_B.Add4_h;

      /* Sum: '<S19>/AddX2' */
      center_out_B.AddX2_a = center_out_B.z_a + center_out_B.dZ_b;

      /* UnitDelay: '<S20>/y' */
      center_out_B.y_d = center_out_DWork.y_DSTATE_b1;

      /* Sum: '<S20>/Add1' */
      center_out_B.Add1_n = center_out_B.y_d - center_out_B.x_g2;

      /* UnitDelay: '<S20>/z' */
      center_out_B.z_l = center_out_DWork.z_DSTATE_o;

      /* Sum: '<S20>/Add3' incorporates:
       *  Constant: '<S20>/rho'
       */
      center_out_B.Add3_k = center_out_P.rho_Value_d2 - center_out_B.z_l;

      /* Product: '<S20>/product2' */
      center_out_B.product2_g = center_out_B.x_g2 * center_out_B.Add3_k;

      /* Sum: '<S20>/Add2' */
      center_out_B.Add2_d = center_out_B.product2_g - center_out_B.y_d;

      /* Product: '<S20>/product3' incorporates:
       *  Constant: '<S20>/beta'
       */
      center_out_B.product3_j = center_out_B.z_l * center_out_P.beta_Value_i;

      /* Product: '<S20>/product4' */
      center_out_B.product4_j = center_out_B.y_d * center_out_B.x_g2;

      /* Sum: '<S20>/Add4' */
      center_out_B.Add4_f = center_out_B.product4_j - center_out_B.product3_j;

      /* Product: '<S20>/product1' incorporates:
       *  Constant: '<S20>/sigma'
       */
      center_out_B.product1_p = center_out_B.Add1_n * center_out_P.sigma_Value_p;

      /* Product: '<S20>/dX' incorporates:
       *  Constant: '<S20>/timescale'
       */
      center_out_B.dX_l = center_out_P.timescale_Value_l *
        center_out_B.product1_p;

      /* Sum: '<S20>/AddX' */
      center_out_B.AddX_d = center_out_B.x_g2 + center_out_B.dX_l;

      /* Product: '<S20>/dY' incorporates:
       *  Constant: '<S20>/timescale'
       */
      center_out_B.dY_b = center_out_P.timescale_Value_l * center_out_B.Add2_d;

      /* Sum: '<S20>/AddX1' */
      center_out_B.AddX1_d = center_out_B.y_d + center_out_B.dY_b;

      /* Product: '<S20>/dZ' incorporates:
       *  Constant: '<S20>/timescale'
       */
      center_out_B.dZ_m = center_out_P.timescale_Value_l * center_out_B.Add4_f;

      /* Sum: '<S20>/AddX2' */
      center_out_B.AddX2_l = center_out_B.z_l + center_out_B.dZ_m;

      /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix Concatenation1InPort0' */
      tmp = center_out_B.Product1_d;
      tmp_0 = center_out_B.Product_l;
      center_out_B.MatrixConcatenation1[0] = tmp;
      center_out_B.MatrixConcatenation1[1] = tmp_0;

      /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix Concatenation1InPort1' */
      center_out_B.MatrixConcatenation1[2] = center_out_B.Switch[0];
      center_out_B.MatrixConcatenation1[3] = center_out_B.Switch[1];

      /* UnitDelay: '<S23>/y' */
      center_out_B.y_j = center_out_DWork.y_DSTATE_d;

      /* Sum: '<S23>/Add1' */
      center_out_B.Add1_nw = center_out_B.y_j - center_out_B.x;

      /* UnitDelay: '<S23>/z' */
      center_out_B.z_f = center_out_DWork.z_DSTATE_f;

      /* Sum: '<S23>/Add3' incorporates:
       *  Constant: '<S23>/rho'
       */
      center_out_B.Add3_k3 = center_out_P.rho_Value_p - center_out_B.z_f;

      /* Product: '<S23>/product2' */
      center_out_B.product2_h = center_out_B.x * center_out_B.Add3_k3;

      /* Sum: '<S23>/Add2' */
      center_out_B.Add2_p = center_out_B.product2_h - center_out_B.y_j;

      /* Product: '<S23>/product3' incorporates:
       *  Constant: '<S23>/beta'
       */
      center_out_B.product3_m = center_out_B.z_f * center_out_P.beta_Value_ez;

      /* Product: '<S23>/product4' */
      center_out_B.product4_b = center_out_B.y_j * center_out_B.x;

      /* Sum: '<S23>/Add4' */
      center_out_B.Add4_l = center_out_B.product4_b - center_out_B.product3_m;

      /* Product: '<S23>/product1' incorporates:
       *  Constant: '<S23>/sigma'
       */
      center_out_B.product1_m = center_out_B.Add1_nw *
        center_out_P.sigma_Value_c;

      /* Product: '<S23>/dX' incorporates:
       *  Constant: '<S23>/timescale'
       */
      center_out_B.dX_g = center_out_P.timescale_Value_lp *
        center_out_B.product1_m;

      /* Sum: '<S23>/AddX' */
      center_out_B.AddX_k = center_out_B.x + center_out_B.dX_g;

      /* Product: '<S23>/dY' incorporates:
       *  Constant: '<S23>/timescale'
       */
      center_out_B.dY_i = center_out_P.timescale_Value_lp * center_out_B.Add2_p;

      /* Sum: '<S23>/AddX1' */
      center_out_B.AddX1_e = center_out_B.y_j + center_out_B.dY_i;

      /* Product: '<S23>/dZ' incorporates:
       *  Constant: '<S23>/timescale'
       */
      center_out_B.dZ_i = center_out_P.timescale_Value_lp * center_out_B.Add4_l;

      /* Sum: '<S23>/AddX2' */
      center_out_B.AddX2_c = center_out_B.z_f + center_out_B.dZ_i;

      /* UnitDelay: '<S24>/y' */
      center_out_B.y_e = center_out_DWork.y_DSTATE_e;

      /* Sum: '<S24>/Add1' */
      center_out_B.Add1_b = center_out_B.y_e - center_out_B.x_j;

      /* UnitDelay: '<S24>/z' */
      center_out_B.z_o = center_out_DWork.z_DSTATE_d;

      /* Sum: '<S24>/Add3' incorporates:
       *  Constant: '<S24>/rho'
       */
      center_out_B.Add3_pw = center_out_P.rho_Value_f - center_out_B.z_o;

      /* Product: '<S24>/product2' */
      center_out_B.product2_ka = center_out_B.x_j * center_out_B.Add3_pw;

      /* Sum: '<S24>/Add2' */
      center_out_B.Add2_db = center_out_B.product2_ka - center_out_B.y_e;

      /* Product: '<S24>/product3' incorporates:
       *  Constant: '<S24>/beta'
       */
      center_out_B.product3_l = center_out_B.z_o * center_out_P.beta_Value_mt;

      /* Product: '<S24>/product4' */
      center_out_B.product4_n = center_out_B.y_e * center_out_B.x_j;

      /* Sum: '<S24>/Add4' */
      center_out_B.Add4_c = center_out_B.product4_n - center_out_B.product3_l;

      /* Product: '<S24>/product1' incorporates:
       *  Constant: '<S24>/sigma'
       */
      center_out_B.product1_d = center_out_B.Add1_b * center_out_P.sigma_Value_h;

      /* Product: '<S24>/dX' incorporates:
       *  Constant: '<S24>/timescale'
       */
      center_out_B.dX_e = center_out_P.timescale_Value_c *
        center_out_B.product1_d;

      /* Sum: '<S24>/AddX' */
      center_out_B.AddX_ko = center_out_B.x_j + center_out_B.dX_e;

      /* Product: '<S24>/dY' incorporates:
       *  Constant: '<S24>/timescale'
       */
      center_out_B.dY_bm = center_out_P.timescale_Value_c * center_out_B.Add2_db;

      /* Sum: '<S24>/AddX1' */
      center_out_B.AddX1_b = center_out_B.y_e + center_out_B.dY_bm;

      /* Product: '<S24>/dZ' incorporates:
       *  Constant: '<S24>/timescale'
       */
      center_out_B.dZ_o = center_out_P.timescale_Value_c * center_out_B.Add4_c;

      /* Sum: '<S24>/AddX2' */
      center_out_B.AddX2_f = center_out_B.z_o + center_out_B.dZ_o;

      /* UnitDelay: '<S25>/y' */
      center_out_B.y_e3 = center_out_DWork.y_DSTATE_f;

      /* Sum: '<S25>/Add1' */
      center_out_B.Add1_j = center_out_B.y_e3 - center_out_B.x_k;

      /* UnitDelay: '<S25>/z' */
      center_out_B.z_b = center_out_DWork.z_DSTATE_d2;

      /* Sum: '<S25>/Add3' incorporates:
       *  Constant: '<S25>/rho'
       */
      center_out_B.Add3_l = center_out_P.rho_Value_g - center_out_B.z_b;

      /* Product: '<S25>/product2' */
      center_out_B.product2_o = center_out_B.x_k * center_out_B.Add3_l;

      /* Sum: '<S25>/Add2' */
      center_out_B.Add2_a = center_out_B.product2_o - center_out_B.y_e3;

      /* Product: '<S25>/product3' incorporates:
       *  Constant: '<S25>/beta'
       */
      center_out_B.product3_a = center_out_B.z_b * center_out_P.beta_Value_b;

      /* Product: '<S25>/product4' */
      center_out_B.product4_n1 = center_out_B.y_e3 * center_out_B.x_k;

      /* Sum: '<S25>/Add4' */
      center_out_B.Add4_n = center_out_B.product4_n1 - center_out_B.product3_a;

      /* Product: '<S25>/product1' incorporates:
       *  Constant: '<S25>/sigma'
       */
      center_out_B.product1_d2 = center_out_B.Add1_j *
        center_out_P.sigma_Value_m;

      /* Product: '<S25>/dX' incorporates:
       *  Constant: '<S25>/timescale'
       */
      center_out_B.dX_b = center_out_P.timescale_Value_k *
        center_out_B.product1_d2;

      /* Sum: '<S25>/AddX' */
      center_out_B.AddX_lw = center_out_B.x_k + center_out_B.dX_b;

      /* Product: '<S25>/dY' incorporates:
       *  Constant: '<S25>/timescale'
       */
      center_out_B.dY_k = center_out_P.timescale_Value_k * center_out_B.Add2_a;

      /* Sum: '<S25>/AddX1' */
      center_out_B.AddX1_aj = center_out_B.y_e3 + center_out_B.dY_k;

      /* Product: '<S25>/dZ' incorporates:
       *  Constant: '<S25>/timescale'
       */
      center_out_B.dZ_f = center_out_P.timescale_Value_k * center_out_B.Add4_n;

      /* Sum: '<S25>/AddX2' */
      center_out_B.AddX2_k = center_out_B.z_b + center_out_B.dZ_f;

      /* UnitDelay: '<S26>/y' */
      center_out_B.y_n = center_out_DWork.y_DSTATE_p;

      /* Sum: '<S26>/Add1' */
      center_out_B.Add1_e = center_out_B.y_n - center_out_B.x_l;

      /* UnitDelay: '<S26>/z' */
      center_out_B.z_bj = center_out_DWork.z_DSTATE_l;

      /* Sum: '<S26>/Add3' incorporates:
       *  Constant: '<S26>/rho'
       */
      center_out_B.Add3_e = center_out_P.rho_Value_j - center_out_B.z_bj;

      /* Product: '<S26>/product2' */
      center_out_B.product2_i = center_out_B.x_l * center_out_B.Add3_e;

      /* Sum: '<S26>/Add2' */
      center_out_B.Add2_as = center_out_B.product2_i - center_out_B.y_n;

      /* Product: '<S26>/product3' incorporates:
       *  Constant: '<S26>/beta'
       */
      center_out_B.product3_be = center_out_B.z_bj * center_out_P.beta_Value_a;

      /* Product: '<S26>/product4' */
      center_out_B.product4_a1 = center_out_B.y_n * center_out_B.x_l;

      /* Sum: '<S26>/Add4' */
      center_out_B.Add4_e = center_out_B.product4_a1 - center_out_B.product3_be;

      /* Product: '<S26>/product1' incorporates:
       *  Constant: '<S26>/sigma'
       */
      center_out_B.product1_d3 = center_out_B.Add1_e *
        center_out_P.sigma_Value_hn;

      /* Product: '<S26>/dX' incorporates:
       *  Constant: '<S26>/timescale'
       */
      center_out_B.dX_bv = center_out_P.timescale_Value_i *
        center_out_B.product1_d3;

      /* Sum: '<S26>/AddX' */
      center_out_B.AddX_n = center_out_B.x_l + center_out_B.dX_bv;

      /* Product: '<S26>/dY' incorporates:
       *  Constant: '<S26>/timescale'
       */
      center_out_B.dY_f = center_out_P.timescale_Value_i * center_out_B.Add2_as;

      /* Sum: '<S26>/AddX1' */
      center_out_B.AddX1_h = center_out_B.y_n + center_out_B.dY_f;

      /* Product: '<S26>/dZ' incorporates:
       *  Constant: '<S26>/timescale'
       */
      center_out_B.dZ_ms = center_out_P.timescale_Value_i * center_out_B.Add4_e;

      /* Sum: '<S26>/AddX2' */
      center_out_B.AddX2_e = center_out_B.z_bj + center_out_B.dZ_ms;

      /* Sum: '<S8>/Add' */
      center_out_B.Add_p = center_out_B.BehaviorCO_o4[1] +
        center_out_B.BehaviorCO_o4[3];

      /* Sum: '<S8>/Add1' */
      center_out_B.Add1_l = center_out_B.BehaviorCO_o4[2] +
        center_out_B.BehaviorCO_o4[4];

      /* Gain: '<S8>/Gain' */
      center_out_B.Gain_m = center_out_P.Gain_Gain_l * center_out_B.Add_p;

      /* Gain: '<S8>/Gain1' */
      center_out_B.Gain1_h = center_out_P.Gain1_Gain_g * center_out_B.Add1_l;
    }
  }
}

/* Model update function */
void center_out_update(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S31>/Memory' */
    center_out_DWork.Memory_PreviousInput = center_out_B.LogicalOperator;

    /* Update for Memory: '<S4>/Memory' */
    center_out_DWork.Memory_PreviousInput_e = center_out_B.LogicalOperator1_bt;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S67>/Derivative' */
    {
      real_T timeStampA = center_out_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = center_out_DWork.Derivative_RWORK.TimeStampB;
      real_T *lastBank = &center_out_DWork.Derivative_RWORK.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = center_out_rtM->Timing.t[0];
      *lastBank++ = center_out_B.DigitalFilter2;
    }

    /* Derivative Block: '<S68>/Derivative' */
    {
      real_T timeStampA = center_out_DWork.Derivative_RWORK_d.TimeStampA;
      real_T timeStampB = center_out_DWork.Derivative_RWORK_d.TimeStampB;
      real_T *lastBank = &center_out_DWork.Derivative_RWORK_d.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = center_out_rtM->Timing.t[0];
      *lastBank++ = center_out_B.DigitalFilter2_l;
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S43>/Memory' */
    center_out_DWork.Memory_PreviousInput_i = center_out_B.LogicalOperator_pm;

    /* Update for Memory: '<S47>/Memory' */
    center_out_DWork.Memory_PreviousInput_a = center_out_B.LogicalOperator_l;

    /* Update for UnitDelay: '<S61>/Delay Input1' */
    center_out_DWork.DelayInput1_DSTATE = center_out_B.Compare_d;

    /* Update for Memory: '<S45>/Memory' */
    center_out_DWork.Memory_PreviousInput_j = center_out_B.LogicalOperator_o;

    /* Update for UnitDelay: '<S46>/Delay Input1' */
    center_out_DWork.DelayInput1_DSTATE_o = center_out_B.Compare_m;

    /* Update for UnitDelay: '<S39>/Delay Input1' */
    center_out_DWork.DelayInput1_DSTATE_g = center_out_B.Compare_g;

    /* Update for Memory: '<S44>/Memory' */
    center_out_DWork.Memory_PreviousInput_o = center_out_B.LogicalOperator_i;

    /* Update for UnitDelay: '<S38>/Delay Input1' */
    center_out_DWork.DelayInput1_DSTATE_m = center_out_B.Compare_p;

    /* Update for Memory: '<S42>/Memory' */
    center_out_DWork.Memory_PreviousInput_b = center_out_B.Logic[0];

    /* Update for UnitDelay: '<S23>/x' */
    center_out_DWork.x_DSTATE = center_out_B.AddX_k;

    /* Update for UnitDelay: '<S24>/x' */
    center_out_DWork.x_DSTATE_m = center_out_B.AddX_ko;

    /* Update for UnitDelay: '<S25>/x' */
    center_out_DWork.x_DSTATE_a = center_out_B.AddX_lw;

    /* Update for UnitDelay: '<S26>/x' */
    center_out_DWork.x_DSTATE_p = center_out_B.AddX_n;

    /* Update for UnitDelay: '<S17>/x' */
    center_out_DWork.x_DSTATE_b = center_out_B.AddX;

    /* Update for UnitDelay: '<S18>/x' */
    center_out_DWork.x_DSTATE_a5 = center_out_B.AddX_m;

    /* Update for UnitDelay: '<S19>/x' */
    center_out_DWork.x_DSTATE_h = center_out_B.AddX_l;

    /* Update for UnitDelay: '<S20>/x' */
    center_out_DWork.x_DSTATE_b2 = center_out_B.AddX_d;

    /* Level2 S-Function Block: '<Root>/Behavior CO' (mastercon_co) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[11];
      sfcnUpdate(rts, 1);
      if (ssGetErrorStatus(rts) != NULL)
        return;
    }

    /* UniformRandomNumber Block: '<S6>/Uniform Random Number' */
    center_out_DWork.UniformRandomNumber_RWORK.NextOutput = rt_Urand((uint32_T *)
      &center_out_DWork.UniformRandomNumber_IWORK.RandSeed) *
      (center_out_P.UniformRandomNumber_Max -
       center_out_P.UniformRandomNumber_Min) +
      center_out_P.UniformRandomNumber_Min;
  }

  if (tid == 0) {
    /* Update for UnitDelay: '<S17>/y' */
    center_out_DWork.y_DSTATE = center_out_B.AddX1;

    /* Update for UnitDelay: '<S17>/z' */
    center_out_DWork.z_DSTATE = center_out_B.AddX2;

    /* Update for UnitDelay: '<S18>/y' */
    center_out_DWork.y_DSTATE_b = center_out_B.AddX1_g;

    /* Update for UnitDelay: '<S18>/z' */
    center_out_DWork.z_DSTATE_c = center_out_B.AddX2_n;

    /* Update for UnitDelay: '<S19>/y' */
    center_out_DWork.y_DSTATE_j = center_out_B.AddX1_a;

    /* Update for UnitDelay: '<S19>/z' */
    center_out_DWork.z_DSTATE_p = center_out_B.AddX2_a;

    /* Update for UnitDelay: '<S20>/y' */
    center_out_DWork.y_DSTATE_b1 = center_out_B.AddX1_d;

    /* Update for UnitDelay: '<S20>/z' */
    center_out_DWork.z_DSTATE_o = center_out_B.AddX2_l;

    /* Update for UnitDelay: '<S23>/y' */
    center_out_DWork.y_DSTATE_d = center_out_B.AddX1_e;

    /* Update for UnitDelay: '<S23>/z' */
    center_out_DWork.z_DSTATE_f = center_out_B.AddX2_c;

    /* Update for UnitDelay: '<S24>/y' */
    center_out_DWork.y_DSTATE_e = center_out_B.AddX1_b;

    /* Update for UnitDelay: '<S24>/z' */
    center_out_DWork.z_DSTATE_d = center_out_B.AddX2_f;

    /* Update for UnitDelay: '<S25>/y' */
    center_out_DWork.y_DSTATE_f = center_out_B.AddX1_aj;

    /* Update for UnitDelay: '<S25>/z' */
    center_out_DWork.z_DSTATE_d2 = center_out_B.AddX2_k;

    /* Update for UnitDelay: '<S26>/y' */
    center_out_DWork.y_DSTATE_p = center_out_B.AddX1_h;

    /* Update for UnitDelay: '<S26>/z' */
    center_out_DWork.z_DSTATE_l = center_out_B.AddX2_e;
  }

  /* Update absolute time for base rate */
  if (tid == 0) {
    if (!(++center_out_rtM->Timing.clockTick0))
      ++center_out_rtM->Timing.clockTickH0;
    center_out_rtM->Timing.t[0] = center_out_rtM->Timing.clockTick0 *
      center_out_rtM->Timing.stepSize0 + center_out_rtM->Timing.clockTickH0 *
      center_out_rtM->Timing.stepSize0 * 4294967296.0;
  }

  if (tid == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++center_out_rtM->Timing.clockTick1))
      ++center_out_rtM->Timing.clockTickH1;
    center_out_rtM->Timing.t[1] = center_out_rtM->Timing.clockTick1 *
      center_out_rtM->Timing.stepSize1 + center_out_rtM->Timing.clockTickH1 *
      center_out_rtM->Timing.stepSize1 * 4294967296.0;
  }

  if (tid == 2) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    if (!(++center_out_rtM->Timing.clockTick2))
      ++center_out_rtM->Timing.clockTickH2;
    center_out_rtM->Timing.t[2] = center_out_rtM->Timing.clockTick2 *
      center_out_rtM->Timing.stepSize2 + center_out_rtM->Timing.clockTickH2 *
      center_out_rtM->Timing.stepSize2 * 4294967296.0;
  }
}

/* Model initialize function */
void center_out_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */
  /* initialize real-time model */
  (void) memset((char_T *)center_out_rtM,0,
                sizeof(rtModel_center_out));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&center_out_rtM->solverInfo,
                          &center_out_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&center_out_rtM->solverInfo, &rtmGetTPtr(center_out_rtM));
    rtsiSetStepSizePtr(&center_out_rtM->solverInfo,
                       &center_out_rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&center_out_rtM->solverInfo, (&rtmGetErrorStatus
      (center_out_rtM)));
    rtsiSetRTModelPtr(&center_out_rtM->solverInfo, center_out_rtM);
  }

  rtsiSetSimTimeStep(&center_out_rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&center_out_rtM->solverInfo,"FixedStepDiscrete");
  center_out_rtM->solverInfoPtr = (&center_out_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = center_out_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    center_out_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    center_out_rtM->Timing.sampleTimes =
      (&center_out_rtM->Timing.sampleTimesArray[0]);
    center_out_rtM->Timing.offsetTimes =
      (&center_out_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    center_out_rtM->Timing.sampleTimes[0] = (0.0);
    center_out_rtM->Timing.sampleTimes[1] = (0.001);
    center_out_rtM->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    center_out_rtM->Timing.offsetTimes[0] = (0.0);
    center_out_rtM->Timing.offsetTimes[1] = (0.0);
    center_out_rtM->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(center_out_rtM, &center_out_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = center_out_rtM->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = center_out_rtM->Timing.perTaskSampleHitsArray;
    center_out_rtM->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    center_out_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(center_out_rtM, -1);
  center_out_rtM->Timing.stepSize0 = 0.001;
  center_out_rtM->Timing.stepSize1 = 0.001;
  center_out_rtM->Timing.stepSize2 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    center_out_rtM->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(center_out_rtM->rtwLogInfo, 2);
    rtliSetLogMaxRows(center_out_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(center_out_rtM->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(center_out_rtM->rtwLogInfo, "rt_");
    rtliSetLogT(center_out_rtM->rtwLogInfo, "tout");
    rtliSetLogX(center_out_rtM->rtwLogInfo, "xout");
    rtliSetLogXFinal(center_out_rtM->rtwLogInfo, "");
    rtliSetSigLog(center_out_rtM->rtwLogInfo, "");

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
        "center_out/Velocity Calculation/Pos2VelX/Digital Filter2",
        "center_out/Velocity Calculation/Pos2VelX/Digital Filter",
        "center_out/Velocity Calculation/Pos2VelY/Digital Filter2",
        "center_out/Velocity Calculation/Pos2VelY/Digital Filter",
        "center_out/Force Generator/LorentzForce/Lorentz/x",
        "center_out/Force Generator/LorentzForce/Lorentz1/x",
        "center_out/Force Generator/LorentzForce/Lorentz2/x",
        "center_out/Force Generator/LorentzForce/Lorentz3/x",
        "center_out/Catch Force Generator/LorentzForce/Lorentz/x",
        "center_out/Catch Force Generator/LorentzForce/Lorentz1/x",
        "center_out/Catch Force Generator/LorentzForce/Lorentz2/x",
        "center_out/Catch Force Generator/LorentzForce/Lorentz3/x",
        "center_out/Behavior CO",
        "center_out/Catch Force Generator/LorentzForce/Lorentz/y",
        "center_out/Catch Force Generator/LorentzForce/Lorentz/z",
        "center_out/Catch Force Generator/LorentzForce/Lorentz1/y",
        "center_out/Catch Force Generator/LorentzForce/Lorentz1/z",
        "center_out/Catch Force Generator/LorentzForce/Lorentz2/y",
        "center_out/Catch Force Generator/LorentzForce/Lorentz2/z",
        "center_out/Catch Force Generator/LorentzForce/Lorentz3/y",
        "center_out/Catch Force Generator/LorentzForce/Lorentz3/z",
        "center_out/Force Generator/LorentzForce/Lorentz/y",
        "center_out/Force Generator/LorentzForce/Lorentz/z",
        "center_out/Force Generator/LorentzForce/Lorentz1/y",
        "center_out/Force Generator/LorentzForce/Lorentz1/z",
        "center_out/Force Generator/LorentzForce/Lorentz2/y",
        "center_out/Force Generator/LorentzForce/Lorentz2/z",
        "center_out/Force Generator/LorentzForce/Lorentz3/y",
        "center_out/Force Generator/LorentzForce/Lorentz3/z",
        "center_out/Recentering Subsystem/Timer/Detect Fall\nNonpositive/Delay Input1",
        "center_out/Recentering Subsystem/Start Moving/Delay Input1",
        "center_out/Recentering Subsystem/Falling Edge1/Delay Input1",
        "center_out/Recentering Subsystem/Falling Edge/Delay Input1" };

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

      rtliSetLogXSignalInfo(center_out_rtM->rtwLogInfo,
                            &rt_LoggedStateSignalInfo);
    }

    {
      static void * rt_LoggedStateSignalPtrs[33];
      rt_LoggedStateSignalPtrs[0] = (void*)
        &center_out_DWork.DigitalFilter2_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[1] = (void*)
        &center_out_DWork.DigitalFilter_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[2] = (void*)
        &center_out_DWork.DigitalFilter2_FILT_STATES_h[0];
      rt_LoggedStateSignalPtrs[3] = (void*)
        &center_out_DWork.DigitalFilter_FILT_STATES_g[0];
      rt_LoggedStateSignalPtrs[4] = (void*)&center_out_DWork.x_DSTATE;
      rt_LoggedStateSignalPtrs[5] = (void*)&center_out_DWork.x_DSTATE_m;
      rt_LoggedStateSignalPtrs[6] = (void*)&center_out_DWork.x_DSTATE_a;
      rt_LoggedStateSignalPtrs[7] = (void*)&center_out_DWork.x_DSTATE_p;
      rt_LoggedStateSignalPtrs[8] = (void*)&center_out_DWork.x_DSTATE_b;
      rt_LoggedStateSignalPtrs[9] = (void*)&center_out_DWork.x_DSTATE_a5;
      rt_LoggedStateSignalPtrs[10] = (void*)&center_out_DWork.x_DSTATE_h;
      rt_LoggedStateSignalPtrs[11] = (void*)&center_out_DWork.x_DSTATE_b2;
      rt_LoggedStateSignalPtrs[12] = (void*)&center_out_DWork.BehaviorCO_DSTATE;
      rt_LoggedStateSignalPtrs[13] = (void*)&center_out_DWork.y_DSTATE;
      rt_LoggedStateSignalPtrs[14] = (void*)&center_out_DWork.z_DSTATE;
      rt_LoggedStateSignalPtrs[15] = (void*)&center_out_DWork.y_DSTATE_b;
      rt_LoggedStateSignalPtrs[16] = (void*)&center_out_DWork.z_DSTATE_c;
      rt_LoggedStateSignalPtrs[17] = (void*)&center_out_DWork.y_DSTATE_j;
      rt_LoggedStateSignalPtrs[18] = (void*)&center_out_DWork.z_DSTATE_p;
      rt_LoggedStateSignalPtrs[19] = (void*)&center_out_DWork.y_DSTATE_b1;
      rt_LoggedStateSignalPtrs[20] = (void*)&center_out_DWork.z_DSTATE_o;
      rt_LoggedStateSignalPtrs[21] = (void*)&center_out_DWork.y_DSTATE_d;
      rt_LoggedStateSignalPtrs[22] = (void*)&center_out_DWork.z_DSTATE_f;
      rt_LoggedStateSignalPtrs[23] = (void*)&center_out_DWork.y_DSTATE_e;
      rt_LoggedStateSignalPtrs[24] = (void*)&center_out_DWork.z_DSTATE_d;
      rt_LoggedStateSignalPtrs[25] = (void*)&center_out_DWork.y_DSTATE_f;
      rt_LoggedStateSignalPtrs[26] = (void*)&center_out_DWork.z_DSTATE_d2;
      rt_LoggedStateSignalPtrs[27] = (void*)&center_out_DWork.y_DSTATE_p;
      rt_LoggedStateSignalPtrs[28] = (void*)&center_out_DWork.z_DSTATE_l;
      rt_LoggedStateSignalPtrs[29] = (void*)&center_out_DWork.DelayInput1_DSTATE;
      rt_LoggedStateSignalPtrs[30] = (void*)
        &center_out_DWork.DelayInput1_DSTATE_o;
      rt_LoggedStateSignalPtrs[31] = (void*)
        &center_out_DWork.DelayInput1_DSTATE_g;
      rt_LoggedStateSignalPtrs[32] = (void*)
        &center_out_DWork.DelayInput1_DSTATE_m;
      rtliSetLogXSignalPtrs(center_out_rtM->rtwLogInfo, (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
    }

    rtliSetLogY(center_out_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(center_out_rtM->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(center_out_rtM->rtwLogInfo, NULL);
  }

  /* external mode info */
  center_out_rtM->Sizes.checksums[0] = (2922333750U);
  center_out_rtM->Sizes.checksums[1] = (1640439664U);
  center_out_rtM->Sizes.checksums[2] = (536259912U);
  center_out_rtM->Sizes.checksums[3] = (1659165049U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[34];
    center_out_rtM->extModeInfo = (&rt_ExtModeInfo);
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
      &center_out_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &center_out_DWork.EnabledSubsystem_i.EnabledSubsystem_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &center_out_DWork.EnabledSubsystem_ir.EnabledSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &center_out_DWork.EnabledSubsystem_n.EnabledSubsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &center_out_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)
      &center_out_DWork.SampleandHold_e.SampleandHold_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &center_out_DWork.SampleandHold.SampleandHold_SubsysRanBC;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &center_out_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, center_out_rtM->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(center_out_rtM));
  }

  center_out_rtM->solverInfoPtr = (&center_out_rtM->solverInfo);
  center_out_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&center_out_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&center_out_rtM->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  center_out_rtM->ModelData.blockIO = ((void *) &center_out_B);
  (void) memset(((void *) &center_out_B),0,
                sizeof(BlockIO_center_out));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&center_out_B.Clock);
    for (i = 0; i < 241; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&center_out_B.ForIterator);
    for (i = 0; i < 90; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    ((real_T*)&center_out_B.SampleandHold.In)[0] = 0.0;
    ((real_T*)&center_out_B.SampleandHold_e.In)[0] = 0.0;
    ((real_T*)&center_out_B.EnabledSubsystem_l.In1)[0] = 0.0;
    ((real_T*)&center_out_B.EnabledSubsystem_n.In1)[0] = 0.0;
    ((real_T*)&center_out_B.EnabledSubsystem_ir.In1)[0] = 0.0;
    ((real_T*)&center_out_B.EnabledSubsystem_i.In1)[0] = 0.0;
    ((real_T*)&center_out_B.EnabledSubsystem.In1)[0] = 0.0;
  }

  /* parameters */
  center_out_rtM->ModelData.defaultParam = ((real_T *) &center_out_P);

  /* states (dwork) */
  center_out_rtM->Work.dwork = ((void *) &center_out_DWork);
  (void) memset((char_T *) &center_out_DWork,0,
                sizeof(D_Work_center_out));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &center_out_DWork.DigitalFilter2_FILT_STATES
      [0];
    for (i = 0; i < 153; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    center_out_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    center_out_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  center_out_InitializeDataMapInfo(center_out_rtM);

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &center_out_rtM->NonInlinedSFcns.sfcnInfo;
    center_out_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(center_out_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &center_out_rtM->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(center_out_rtM));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(center_out_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(center_out_rtM));
    rtssSetStepSizePtr(sfcnInfo, &center_out_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(center_out_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &center_out_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &center_out_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &center_out_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &center_out_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &center_out_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &center_out_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &center_out_rtM->solverInfoPtr);
  }

  center_out_rtM->Sizes.numSFcns = (14);

  /* register each child */
  {
    (void) memset((void *)&center_out_rtM->NonInlinedSFcns.childSFunctions[0],0,
                  14*sizeof(SimStruct));
    center_out_rtM->childSfunctions =
      (&center_out_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 14; i++) {
        center_out_rtM->childSfunctions[i] =
          (&center_out_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: center_out/<S72>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &center_out_B.xPCTargetTime_d));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "center_out/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,center_out_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &center_out_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&center_out_P.xPCTargetTime_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&center_out_P.xPCTargetTime_P2_Size[0]);
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

    /* Level2 S-Function Block: center_out/<S72>/PCI-6025E  (donipcie) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &center_out_B.Switch_a;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &center_out_B.DataTypeConversion;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts,
                "center_out/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ");
      ssSetRTModel(rts,center_out_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &center_out_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&center_out_P.PCI6025E_P1_Size_g[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&center_out_P.PCI6025E_P2_Size_i[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&center_out_P.PCI6025E_P3_Size_b[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&center_out_P.PCI6025E_P4_Size_p[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&center_out_P.PCI6025E_P5_Size_m[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&center_out_P.PCI6025E_P6_Size_g[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&center_out_P.PCI6025E_P7_Size_l[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &center_out_DWork.PCI6025E_IWORK_d[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &center_out_rtM->NonInlinedSFcns.Sfcn1.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &center_out_DWork.PCI6025E_IWORK_d[0]);
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

    /* Level2 S-Function Block: center_out/<S70>/ToBits1 (Byte2Bits) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &center_out_B.Switch_e;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &center_out_B.ToBits1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &center_out_B.ToBits1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &center_out_B.ToBits1_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &center_out_B.ToBits1_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &center_out_B.ToBits1_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &center_out_B.ToBits1_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &center_out_B.ToBits1_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &center_out_B.ToBits1_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits1");
      ssSetPath(rts,
                "center_out/XY Position Subsystem/For Iterator Subsystem/ToBits1");
      ssSetRTModel(rts,center_out_rtM);
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

    /* Level2 S-Function Block: center_out/<S70>/Port A (dopci8255) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &center_out_B.ToBits1_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &center_out_B.ToBits1_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn3.UPtrs2;
          sfcnUPtrs[0] = &center_out_B.ToBits1_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn3.UPtrs3;
          sfcnUPtrs[0] = &center_out_B.ToBits1_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn3.UPtrs4;
          sfcnUPtrs[0] = &center_out_B.ToBits1_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn3.UPtrs5;
          sfcnUPtrs[0] = &center_out_B.ToBits1_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn3.UPtrs6;
          sfcnUPtrs[0] = &center_out_B.ToBits1_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn3.UPtrs7;
          sfcnUPtrs[0] = &center_out_B.ToBits1_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port A");
      ssSetPath(rts,
                "center_out/XY Position Subsystem/For Iterator Subsystem/Port A");
      ssSetRTModel(rts,center_out_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &center_out_rtM->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&center_out_P.PortA_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&center_out_P.PortA_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&center_out_P.PortA_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&center_out_P.PortA_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&center_out_P.PortA_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&center_out_P.PortA_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&center_out_P.PortA_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&center_out_P.PortA_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&center_out_P.PortA_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &center_out_DWork.PortA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &center_out_rtM->NonInlinedSFcns.Sfcn3.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &center_out_DWork.PortA_IWORK[0]);
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

    /* Level2 S-Function Block: center_out/<S70>/SerialConverter (serPos) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &center_out_B.ForIterator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &center_out_B.Add_m;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn4.UPtrs2;
          sfcnUPtrs[0] = &center_out_B.Add1_dz;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &center_out_B.SerialConverter));
        }
      }

      /* path info */
      ssSetModelName(rts, "SerialConverter");
      ssSetPath(rts,
                "center_out/XY Position Subsystem/For Iterator Subsystem/SerialConverter");
      ssSetRTModel(rts,center_out_rtM);
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

    /* Level2 S-Function Block: center_out/<S70>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[5]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &center_out_B.SerialConverter;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &center_out_B.ToBits_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &center_out_B.ToBits_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &center_out_B.ToBits_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &center_out_B.ToBits_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &center_out_B.ToBits_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &center_out_B.ToBits_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &center_out_B.ToBits_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &center_out_B.ToBits_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts,
                "center_out/XY Position Subsystem/For Iterator Subsystem/ToBits");
      ssSetRTModel(rts,center_out_rtM);
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

    /* Level2 S-Function Block: center_out/<S70>/Port B (dopci8255) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[6]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &center_out_B.ToBits_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &center_out_B.ToBits_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn6.UPtrs2;
          sfcnUPtrs[0] = &center_out_B.ToBits_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn6.UPtrs3;
          sfcnUPtrs[0] = &center_out_B.ToBits_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn6.UPtrs4;
          sfcnUPtrs[0] = &center_out_B.ToBits_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn6.UPtrs5;
          sfcnUPtrs[0] = &center_out_B.ToBits_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn6.UPtrs6;
          sfcnUPtrs[0] = &center_out_B.ToBits_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn6.UPtrs7;
          sfcnUPtrs[0] = &center_out_B.ToBits_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port B");
      ssSetPath(rts,
                "center_out/XY Position Subsystem/For Iterator Subsystem/Port B");
      ssSetRTModel(rts,center_out_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &center_out_rtM->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&center_out_P.PortB_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&center_out_P.PortB_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&center_out_P.PortB_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&center_out_P.PortB_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&center_out_P.PortB_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&center_out_P.PortB_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&center_out_P.PortB_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&center_out_P.PortB_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&center_out_P.PortB_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &center_out_DWork.PortB_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &center_out_rtM->NonInlinedSFcns.Sfcn6.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &center_out_DWork.PortB_IWORK[0]);
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

    /* Level2 S-Function Block: center_out/<S70>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[7]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &center_out_B.xPCTargetTime));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "center_out/XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,center_out_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &center_out_rtM->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&center_out_P.xPCTargetTime_P1_Size_i[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&center_out_P.xPCTargetTime_P2_Size_a[0]);
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

    /* Level2 S-Function Block: center_out/<S13>/PCI-QUAD04  (enccbcioquadcount) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[8]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &center_out_B.PCIQUAD04));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 ");
      ssSetPath(rts, "center_out/XY Position Subsystem/PCI-QUAD04 ");
      ssSetRTModel(rts,center_out_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &center_out_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&center_out_P.PCIQUAD04_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&center_out_P.PCIQUAD04_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&center_out_P.PCIQUAD04_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&center_out_P.PCIQUAD04_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&center_out_P.PCIQUAD04_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&center_out_P.PCIQUAD04_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&center_out_P.PCIQUAD04_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&center_out_P.PCIQUAD04_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&center_out_P.PCIQUAD04_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&center_out_P.PCIQUAD04_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&center_out_P.PCIQUAD04_P11_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &center_out_DWork.PCIQUAD04_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &center_out_rtM->NonInlinedSFcns.Sfcn8.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &center_out_DWork.PCIQUAD04_IWORK);
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

    /* Level2 S-Function Block: center_out/<S13>/PCI-QUAD04 1 (enccbcioquadcount) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[9]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &center_out_B.PCIQUAD041));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 1");
      ssSetPath(rts, "center_out/XY Position Subsystem/PCI-QUAD04 1");
      ssSetRTModel(rts,center_out_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &center_out_rtM->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&center_out_P.PCIQUAD041_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&center_out_P.PCIQUAD041_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&center_out_P.PCIQUAD041_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&center_out_P.PCIQUAD041_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&center_out_P.PCIQUAD041_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&center_out_P.PCIQUAD041_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&center_out_P.PCIQUAD041_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&center_out_P.PCIQUAD041_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&center_out_P.PCIQUAD041_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&center_out_P.PCIQUAD041_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&center_out_P.PCIQUAD041_P11_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &center_out_DWork.PCIQUAD041_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &center_out_rtM->NonInlinedSFcns.Sfcn9.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &center_out_DWork.PCIQUAD041_IWORK);
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

    /* Level2 S-Function Block: center_out/<S10>/PCI-6025E AD (adnipcie) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[10]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[10]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &center_out_B.PCI6025EAD_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &center_out_B.PCI6025EAD_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E AD");
      ssSetPath(rts, "center_out/Velocity Calculation/PCI-6025E AD");
      ssSetRTModel(rts,center_out_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &center_out_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&center_out_P.PCI6025EAD_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&center_out_P.PCI6025EAD_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&center_out_P.PCI6025EAD_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&center_out_P.PCI6025EAD_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&center_out_P.PCI6025EAD_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&center_out_P.PCI6025EAD_P6_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &center_out_DWork.PCI6025EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &center_out_DWork.PCI6025EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &center_out_rtM->NonInlinedSFcns.Sfcn10.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &center_out_DWork.PCI6025EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &center_out_DWork.PCI6025EAD_IWORK[0]);
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

    /* Level2 S-Function Block: center_out/<Root>/Behavior CO (mastercon_co) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[11]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn11.UPtrs0;
          sfcnUPtrs[0] = &center_out_B.Product1_d;
          sfcnUPtrs[1] = &center_out_B.Product_l;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn11.UPtrs1;
          sfcnUPtrs[0] = center_out_B.MultiportSwitch;
          sfcnUPtrs[1] = &center_out_B.MultiportSwitch[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn11.UPtrs2;
          sfcnUPtrs[0] = center_out_B.LoadSelectSwitch;
          sfcnUPtrs[1] = &center_out_B.LoadSelectSwitch[1];
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) center_out_B.BehaviorCO_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 5);
          ssSetOutputPortSignal(rts, 1, ((real_T *) center_out_B.BehaviorCO_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &center_out_B.BehaviorCO_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 10);
          ssSetOutputPortSignal(rts, 3, ((real_T *) center_out_B.BehaviorCO_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &center_out_B.BehaviorCO_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 2);
          ssSetOutputPortSignal(rts, 5, ((real_T *) center_out_B.BehaviorCO_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 4);
          ssSetOutputPortSignal(rts, 6, ((real_T *) center_out_B.BehaviorCO_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 2);
          ssSetOutputPortSignal(rts, 7, ((real_T *) center_out_B.BehaviorCO_o8));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *) &center_out_DWork.BehaviorCO_DSTATE);

      /* path info */
      ssSetModelName(rts, "Behavior CO");
      ssSetPath(rts, "center_out/Behavior CO");
      ssSetRTModel(rts,center_out_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &center_out_rtM->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 18);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&center_out_P.BehaviorCO_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&center_out_P.BehaviorCO_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&center_out_P.BehaviorCO_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&center_out_P.BehaviorCO_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&center_out_P.BehaviorCO_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&center_out_P.BehaviorCO_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&center_out_P.BehaviorCO_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&center_out_P.BehaviorCO_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&center_out_P.BehaviorCO_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&center_out_P.BehaviorCO_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&center_out_P.BehaviorCO_P11_Size[0]);
        ssSetSFcnParam(rts, 11, (mxArray*)&center_out_P.BehaviorCO_P12_Size[0]);
        ssSetSFcnParam(rts, 12, (mxArray*)&center_out_P.BehaviorCO_P13_Size[0]);
        ssSetSFcnParam(rts, 13, (mxArray*)&center_out_P.BehaviorCO_P14_Size[0]);
        ssSetSFcnParam(rts, 14, (mxArray*)&center_out_P.BehaviorCO_P15_Size[0]);
        ssSetSFcnParam(rts, 15, (mxArray*)&center_out_P.BehaviorCO_P16_Size[0]);
        ssSetSFcnParam(rts, 16, (mxArray*)&center_out_P.BehaviorCO_P17_Size[0]);
        ssSetSFcnParam(rts, 17, (mxArray*)&center_out_P.BehaviorCO_P18_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &center_out_DWork.BehaviorCO_RWORK[0]);
      ssSetIWork(rts, (int_T *) &center_out_DWork.BehaviorCO_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &center_out_rtM->NonInlinedSFcns.Sfcn11.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 3);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &center_out_DWork.BehaviorCO_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 585);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &center_out_DWork.BehaviorCO_IWORK[0]);

        /* DSTATE */
        ssSetDWorkWidth(rts, 2, 1);
        ssSetDWorkDataType(rts, 2,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWorkUsedAsDState(rts, 2, 1);
        ssSetDWork(rts, 2, &center_out_DWork.BehaviorCO_DSTATE);
      }

      /* registration */
      mastercon_co(rts);
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

    /* Level2 S-Function Block: center_out/<S4>/PCI-6025E  (danipcie) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[12]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[12]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn12.UPtrs0;
          sfcnUPtrs[0] = &center_out_B.MG1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &center_out_rtM->NonInlinedSFcns.Sfcn12.UPtrs1;
          sfcnUPtrs[0] = &center_out_B.MG2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts, "center_out/Motor Control/PCI-6025E ");
      ssSetRTModel(rts,center_out_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &center_out_rtM->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&center_out_P.PCI6025E_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&center_out_P.PCI6025E_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&center_out_P.PCI6025E_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&center_out_P.PCI6025E_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&center_out_P.PCI6025E_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&center_out_P.PCI6025E_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&center_out_P.PCI6025E_P7_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &center_out_DWork.PCI6025E_RWORK[0]);
      ssSetIWork(rts, (int_T *) &center_out_DWork.PCI6025E_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &center_out_rtM->NonInlinedSFcns.Sfcn12.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &center_out_DWork.PCI6025E_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &center_out_DWork.PCI6025E_IWORK[0]);
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

    /* Level2 S-Function Block: center_out/<S9>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = center_out_rtM->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = center_out_rtM->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = center_out_rtM->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = center_out_rtM->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &center_out_rtM->NonInlinedSFcns.blkInfo2[13]);
        ssSetRTWSfcnInfo(rts, center_out_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &center_out_rtM->NonInlinedSFcns.methods2[13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &center_out_rtM->NonInlinedSFcns.Sfcn13.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, center_out_B.RateTransition);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 112);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "center_out/UDPXmit/Send");
      ssSetRTModel(rts,center_out_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &center_out_rtM->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&center_out_P.Send_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&center_out_P.Send_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&center_out_P.Send_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&center_out_P.Send_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &center_out_DWork.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &center_out_DWork.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &center_out_rtM->NonInlinedSFcns.Sfcn13.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &center_out_DWork.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &center_out_DWork.Send_PWORK);
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

  center_out_PrevZCSigState.SampleandHold.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
  center_out_PrevZCSigState.SampleandHold_e.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void center_out_terminate(void)
{
  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Behavior CO' (mastercon_co) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S13>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S70>/ToBits1' (Byte2Bits) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/SerialConverter' (serPos) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S70>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S72>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[1];
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
  center_out_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  center_out_update(tid);
}

void MdlInitializeSizes(void)
{
  center_out_rtM->Sizes.numContStates = (0);/* Number of continuous states */
  center_out_rtM->Sizes.numY = (0);    /* Number of model outputs */
  center_out_rtM->Sizes.numU = (0);    /* Number of model inputs */
  center_out_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  center_out_rtM->Sizes.numSampTimes = (3);/* Number of sample times */
  center_out_rtM->Sizes.numBlocks = (480);/* Number of blocks */
  center_out_rtM->Sizes.numBlockIO = (375);/* Number of block outputs */
  center_out_rtM->Sizes.numBlockPrms = (535);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Memory: '<S31>/Memory' */
  center_out_DWork.Memory_PreviousInput = center_out_P.Memory_X0;

  /* InitializeConditions for Memory: '<S4>/Memory' */
  center_out_DWork.Memory_PreviousInput_e = center_out_P.Memory_X0_e;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &center_out_DWork.DigitalFilter2_FILT_STATES[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&center_out_P.DigitalFilter2_ICRTP;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S67>/Derivative' */
  center_out_DWork.Derivative_RWORK.TimeStampA = rtInf;
  center_out_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &center_out_DWork.DigitalFilter_FILT_STATES[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&center_out_P.DigitalFilter_ICRTP;
    }

    *statePtr++ = 0.0;
  }

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &center_out_DWork.DigitalFilter2_FILT_STATES_h
      [0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&center_out_P.DigitalFilter2_ICRTP_i;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S68>/Derivative' */
  center_out_DWork.Derivative_RWORK_d.TimeStampA = rtInf;
  center_out_DWork.Derivative_RWORK_d.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &center_out_DWork.DigitalFilter_FILT_STATES_g
      [0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&center_out_P.DigitalFilter_ICRTP_h;
    }

    *statePtr++ = 0.0;
  }

  /* InitializeConditions for Memory: '<S43>/Memory' */
  center_out_DWork.Memory_PreviousInput_i = center_out_P.Memory_X0_ew;

  /* InitializeConditions for Memory: '<S47>/Memory' */
  center_out_DWork.Memory_PreviousInput_a = center_out_P.Memory_X0_i;

  /* InitializeConditions for UnitDelay: '<S61>/Delay Input1' */
  center_out_DWork.DelayInput1_DSTATE = center_out_P.DelayInput1_X0;

  /* InitializeConditions for Memory: '<S45>/Memory' */
  center_out_DWork.Memory_PreviousInput_j = center_out_P.Memory_X0_b;

  /* InitializeConditions for UnitDelay: '<S46>/Delay Input1' */
  center_out_DWork.DelayInput1_DSTATE_o = center_out_P.DelayInput1_X0_i;

  /* InitializeConditions for UnitDelay: '<S39>/Delay Input1' */
  center_out_DWork.DelayInput1_DSTATE_g = center_out_P.DelayInput1_X0_e;

  /* InitializeConditions for Memory: '<S44>/Memory' */
  center_out_DWork.Memory_PreviousInput_o = center_out_P.Memory_X0_l;

  /* InitializeConditions for UnitDelay: '<S38>/Delay Input1' */
  center_out_DWork.DelayInput1_DSTATE_m = center_out_P.DelayInput1_X0_g;

  /* InitializeConditions for Memory: '<S42>/Memory' */
  center_out_DWork.Memory_PreviousInput_b = center_out_P.Memory_X0_a;

  /* InitializeConditions for UnitDelay: '<S23>/x' */
  center_out_DWork.x_DSTATE = center_out_P.x_X0;

  /* InitializeConditions for UnitDelay: '<S24>/x' */
  center_out_DWork.x_DSTATE_m = center_out_P.x_X0_h;

  /* InitializeConditions for UnitDelay: '<S25>/x' */
  center_out_DWork.x_DSTATE_a = center_out_P.x_X0_p;

  /* InitializeConditions for UnitDelay: '<S26>/x' */
  center_out_DWork.x_DSTATE_p = center_out_P.x_X0_b;

  /* InitializeConditions for UnitDelay: '<S17>/x' */
  center_out_DWork.x_DSTATE_b = center_out_P.x_X0_j;

  /* InitializeConditions for UnitDelay: '<S18>/x' */
  center_out_DWork.x_DSTATE_a5 = center_out_P.x_X0_jq;

  /* InitializeConditions for UnitDelay: '<S19>/x' */
  center_out_DWork.x_DSTATE_h = center_out_P.x_X0_g;

  /* InitializeConditions for UnitDelay: '<S20>/x' */
  center_out_DWork.x_DSTATE_b2 = center_out_P.x_X0_pl;

  /* Level2 S-Function Block: '<Root>/Behavior CO' (mastercon_co) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[11];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* InitializeConditions for UnitDelay: '<S17>/y' */
  center_out_DWork.y_DSTATE = center_out_P.y_X0;

  /* InitializeConditions for UnitDelay: '<S17>/z' */
  center_out_DWork.z_DSTATE = center_out_P.z_X0;

  /* InitializeConditions for UnitDelay: '<S18>/y' */
  center_out_DWork.y_DSTATE_b = center_out_P.y_X0_i;

  /* InitializeConditions for UnitDelay: '<S18>/z' */
  center_out_DWork.z_DSTATE_c = center_out_P.z_X0_c;

  /* InitializeConditions for UnitDelay: '<S19>/y' */
  center_out_DWork.y_DSTATE_j = center_out_P.y_X0_p;

  /* InitializeConditions for UnitDelay: '<S19>/z' */
  center_out_DWork.z_DSTATE_p = center_out_P.z_X0_j;

  /* InitializeConditions for UnitDelay: '<S20>/y' */
  center_out_DWork.y_DSTATE_b1 = center_out_P.y_X0_n;

  /* InitializeConditions for UnitDelay: '<S20>/z' */
  center_out_DWork.z_DSTATE_o = center_out_P.z_X0_f;

  /* InitializeConditions for UnitDelay: '<S23>/y' */
  center_out_DWork.y_DSTATE_d = center_out_P.y_X0_f;

  /* InitializeConditions for UnitDelay: '<S23>/z' */
  center_out_DWork.z_DSTATE_f = center_out_P.z_X0_a;

  /* InitializeConditions for UnitDelay: '<S24>/y' */
  center_out_DWork.y_DSTATE_e = center_out_P.y_X0_j;

  /* InitializeConditions for UnitDelay: '<S24>/z' */
  center_out_DWork.z_DSTATE_d = center_out_P.z_X0_b;

  /* InitializeConditions for UnitDelay: '<S25>/y' */
  center_out_DWork.y_DSTATE_f = center_out_P.y_X0_o;

  /* InitializeConditions for UnitDelay: '<S25>/z' */
  center_out_DWork.z_DSTATE_d2 = center_out_P.z_X0_e;

  /* InitializeConditions for UnitDelay: '<S26>/y' */
  center_out_DWork.y_DSTATE_p = center_out_P.y_X0_d;

  /* InitializeConditions for UnitDelay: '<S26>/z' */
  center_out_DWork.z_DSTATE_l = center_out_P.z_X0_d;
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[12];
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
        xpceScopeAcqOK(2, &center_out_DWork.SFunction_IWORK.AcquireOK);
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
        xpceScopeAcqOK(6, &center_out_DWork.SFunction_IWORK_f.AcquireOK);
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
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior CO/p2/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior CO/p2/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior CO/p2/s3"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior CO/p2/s4"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior CO/p2/s5"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior CO/p2/s1"),
          "%6.0f state");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior CO/p2/s2"),
          "%6.0f rewards");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior CO/p2/s3"),
          "%6.0f aborts");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior CO/p2/s4"),
          "%6.0f fails");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior CO/p2/s5"),
          "%6.0f incompl");
        rl32eSetScope(3, 4, 10);
        rl32eSetScope(3, 40, 0);
        rl32eSetScope(3, 7, 10);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Behavior CO/p2/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 10, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, -10.0);
        rl32eSetTargetScope(3, 10, 10.0);
        xpceScopeAcqOK(3, &center_out_DWork.SFunction_IWORK_b.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[13];
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
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior CO/p7/s1"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior CO/p7/s2"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior CO/p7/s3"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior CO/p7/s4"));
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior CO/p7/s1"),
          "%6.0f major");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior CO/p7/s2"),
          "%6.0f minor");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior CO/p7/s3"),
          "%6.0f revision");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior CO/p7/s4"),
          "%6.0f build");
        rl32eSetScope(7, 4, 10);
        rl32eSetScope(7, 40, 0);
        rl32eSetScope(7, 7, 10);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("Behavior CO/p7/s1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 10, 0);
        rl32eSetTargetScope(7, 1, 0.0);
        rl32eSetTargetScope(7, 11, -10.0);
        rl32eSetTargetScope(7, 10, 10.0);
        xpceScopeAcqOK(7, &center_out_DWork.SFunction_IWORK_d.AcquireOK);
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
        xpceScopeAcqOK(1, &center_out_DWork.SFunction_IWORK_p.AcquireOK);
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
        xpceScopeAcqOK(5, &center_out_DWork.SFunction_IWORK_a.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /*trigger Subsystem Block: '<S65>/Sample and Hold' */
  center_out_SampleandHold_Start(&center_out_B.SampleandHold,
    (rtP_SampleandHold_center_out *) &center_out_P.SampleandHold);

  /* UniformRandomNumber Block: '<S6>/Uniform Random Number' */
  {
    uint32_T *RandSeed = (uint32_T *)
      &center_out_DWork.UniformRandomNumber_IWORK.RandSeed;
    uint32_T r, t;
    *RandSeed = (uint32_T)center_out_P.UniformRandomNumber_Seed;
    r = *RandSeed >> 16;
    t = *RandSeed & RT_BIT16;
    *RandSeed = ((*RandSeed - (r << 16) - t) << 16) + t + r;
    if (*RandSeed < 1) {
      *RandSeed = SEED0;
    }

    if (*RandSeed > MAXSEED) {
      *RandSeed = MAXSEED;
    }

    center_out_DWork.UniformRandomNumber_RWORK.NextOutput
      = rt_Urand(RandSeed++) * (center_out_P.UniformRandomNumber_Max -
      center_out_P.UniformRandomNumber_Min) +
      center_out_P.UniformRandomNumber_Min;
  }

  /*trigger Subsystem Block: '<S6>/Sample and Hold' */
  center_out_SampleandHold_Start(&center_out_B.SampleandHold_e,
    (rtP_SampleandHold_center_out *) &center_out_P.SampleandHold_e);

  /* Start for iterator system: '<S13>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Start for iterator system: '<S70>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = center_out_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  center_out_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  center_out_DWork.EnabledSubsystem_i.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  center_out_DWork.EnabledSubsystem_ir.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  center_out_DWork.EnabledSubsystem_n.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  center_out_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  center_out_DWork.SampleandHold_e.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  center_out_DWork.SampleandHold.SampleandHold_SubsysRanBC =
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

rtModel_center_out *center_out(void)
{
  center_out_initialize(1);
  return center_out_rtM;
}

void MdlTerminate(void)
{
  center_out_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
