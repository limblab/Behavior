/*
 * bump_stim.c
 *
 * Real-Time Workshop code generation for Simulink model "bump_stim.mdl".
 *
 * Model Version              : 1.1219
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:43:54 2010
 */

#include "rt_logging_mmi.h"
#include "bump_stim_capi.h"
#include "bump_stim.h"
#include "bump_stim_private.h"
#include <stdio.h>
#include "bump_stim_dt.h"

/* Block signals (auto storage) */
BlockIO_bump_stim bump_stim_B;

/* Block states (auto storage) */
D_Work_bump_stim bump_stim_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_bump_stim bump_stim_PrevZCSigState;

/* Real-time model */
rtModel_bump_stim bump_stim_rtM_;
rtModel_bump_stim *bump_stim_rtM = &bump_stim_rtM_;
static void rate_monotonic_scheduler(void);

/* Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void bump_stim_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(bump_stim_rtM, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(bump_stim_rtM, 2));
}

time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(bump_stim_rtM, 1);
  rtmSampleHitPtr[2] = rtmStepTask(bump_stim_rtM, 2);
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
  if (bump_stim_rtM->Timing.TaskCounters.TID[1] == 0) {
    bump_stim_rtM->Timing.RateInteraction.TID1_2 =
      (bump_stim_rtM->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    bump_stim_rtM->Timing.perTaskSampleHits[5] =
      bump_stim_rtM->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++bump_stim_rtM->Timing.TaskCounters.TID[2] == 20) {/* Sample time: [0.02s, 0.0s] */
    bump_stim_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  bump_stim_rtM->Timing.sampleHits[2] = (bump_stim_rtM->Timing.TaskCounters.TID
    [2] == 0);
}

/* Disable for enable system:
 *   '<S31>/Enabled Subsystem'
 *   '<S43>/Enabled Subsystem'
 *   '<S44>/Enabled Subsystem'
 *   '<S45>/Enabled Subsystem'
 *   '<S47>/Enabled Subsystem'
 */
void bump_s_EnabledSubsystem_Disable(rtDW_EnabledSubsystem_bump_stim *localDW)
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
void bump_stim_EnabledSubsystem(int_T tid, boolean_T rtu_0, real_T rtu_1,
  rtB_EnabledSubsystem_bump_stim *localB, rtDW_EnabledSubsystem_bump_stim
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
        bump_s_EnabledSubsystem_Disable(localDW);
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
void bump_stim_SampleandHold_Start(rtB_SampleandHold_bump_stim *localB,
  rtP_SampleandHold_bump_stim *localP)
{
  /* virtual outports code */

  /* (Virtual) Outport Block: '<S64>/ ' */
  localB->In = localP->_Y0;
}

/* Output and update for trigger system:
 *   '<S6>/Sample and Hold'
 *   '<S65>/Sample and Hold'
 */
void bump_stim_SampleandHold(real_T rtu_0, real_T rtu_1,
  rtB_SampleandHold_bump_stim *localB, rtDW_SampleandHold_bump_stim *localDW,
  rtZCE_SampleandHold_bump_stim *localZCE)
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
void bump_stim_output(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  if (tid == 0) {
    srClearBC(bump_stim_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC);
    srClearBC(bump_stim_DWork.EnabledSubsystem_c.EnabledSubsystem_SubsysRanBC);
    srClearBC(bump_stim_DWork.EnabledSubsystem_f.EnabledSubsystem_SubsysRanBC);
    srClearBC(bump_stim_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC);
    srClearBC(bump_stim_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC);
    srClearBC(bump_stim_DWork.SampleandHold_a.SampleandHold_SubsysRanBC);
    srClearBC(bump_stim_DWork.SampleandHold.SampleandHold_SubsysRanBC);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S31>/Clock'
     */
    bump_stim_B.Clock = bump_stim_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S31>/Memory' */
    bump_stim_B.Memory = bump_stim_DWork.Memory_PreviousInput;

    /* Memory: '<S4>/Memory' */
    bump_stim_B.Memory_i = bump_stim_DWork.Memory_PreviousInput_b;

    /* Logic: '<S31>/Logical Operator2' */
    bump_stim_B.LogicalOperator2 = (bump_stim_B.Memory || bump_stim_B.Memory_i);

    /* Logic: '<S31>/Logical Operator1' */
    bump_stim_B.LogicalOperator1 = !bump_stim_B.LogicalOperator2;

    /* SignalConversion: '<S31>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    bump_stim_B.HiddenBuf_InsertedFor_EnabledSu = bump_stim_B.LogicalOperator1;
  }

  /* SubSystem Block: '<S31>/Enabled Subsystem'
   */
  bump_stim_EnabledSubsystem(tid, bump_stim_B.HiddenBuf_InsertedFor_EnabledSu,
    bump_stim_B.Clock, &bump_stim_B.EnabledSubsystem,
    &bump_stim_DWork.EnabledSubsystem);
  if (tid == 0) {
    /* Sum: '<S31>/Sum' */
    bump_stim_B.Sum = bump_stim_B.Clock - bump_stim_B.EnabledSubsystem.In1;

    /* RelationalOperator: '<S34>/Compare' */
    bump_stim_B.Compare = (bump_stim_B.Sum > 0.0);

    /* RelationalOperator: '<S31>/Relational Operator' incorporates:
     *  Constant: '<S31>/Time'
     */
    bump_stim_B.RelationalOperator = (bump_stim_B.Sum > bump_stim_P.Time_Value);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S31>/Logical Operator' */
    bump_stim_B.LogicalOperator = (boolean_T)((bump_stim_B.Compare != 0U) ^
      bump_stim_B.RelationalOperator);

    /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S13>/Gain' */
    bump_stim_B.Gain = bump_stim_P.Gain_Gain * bump_stim_B.PCIQUAD04;

    /* Sum: '<S13>/Sum3' incorporates:
     *  Constant: '<S13>/shoulderOffset'
     */
    bump_stim_B.Sum3 = bump_stim_B.Gain + bump_stim_P.shoulderOffset_Value;

    /* Trigonometry: '<S71>/Trigonometric Function' */
    bump_stim_B.TrigonometricFunction = cos(bump_stim_B.Sum3);

    /* Product: '<S71>/Product' incorporates:
     *  Constant: '<S71>/L1'
     */
    bump_stim_B.Product = bump_stim_B.TrigonometricFunction *
      bump_stim_P.L1_Value;

    /* Gain: '<S71>/Gain' */
    bump_stim_B.MatrixConcatenate2[0] = bump_stim_P.Gain_Gain_m *
      bump_stim_B.Product;

    /* Trigonometry: '<S71>/Trigonometric Function1' */
    bump_stim_B.TrigonometricFunction1 = sin(bump_stim_B.Sum3);

    /* Product: '<S71>/Product1' incorporates:
     *  Constant: '<S71>/L1'
     */
    bump_stim_B.Product1 = bump_stim_B.TrigonometricFunction1 *
      bump_stim_P.L1_Value;

    /* SignalConversion: '<S71>/ConcatHiddenBufferAtMatrix ConcatenateInPort1' */
    bump_stim_B.MatrixConcatenate2[1] = bump_stim_B.Product1;

    /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[9];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S13>/Gain1' */
    bump_stim_B.Gain1 = bump_stim_P.Gain1_Gain * bump_stim_B.PCIQUAD041;

    /* Sum: '<S13>/Sum1' incorporates:
     *  Constant: '<S13>/elbowOffset'
     */
    bump_stim_B.Sum1 = bump_stim_B.Gain1 + bump_stim_P.elbowOffset_Value;

    /* Trigonometry: '<S71>/Trigonometric Function2' */
    bump_stim_B.TrigonometricFunction2 = sin(bump_stim_B.Sum1);

    /* Product: '<S71>/Product2' incorporates:
     *  Constant: '<S71>/L2'
     */
    bump_stim_B.Product2 = bump_stim_B.TrigonometricFunction2 *
      bump_stim_P.L2_Value;

    /* Gain: '<S71>/Gain1' */
    bump_stim_B.MatrixConcatenate2[2] = bump_stim_P.Gain1_Gain_d *
      bump_stim_B.Product2;

    /* Trigonometry: '<S71>/Trigonometric Function3' */
    bump_stim_B.TrigonometricFunction3 = cos(bump_stim_B.Sum1);

    /* Product: '<S71>/Product3' incorporates:
     *  Constant: '<S71>/L2'
     */
    bump_stim_B.Product3 = bump_stim_B.TrigonometricFunction3 *
      bump_stim_P.L2_Value;

    /* Gain: '<S71>/Gain2' */
    bump_stim_B.MatrixConcatenate2[3] = bump_stim_P.Gain2_Gain *
      bump_stim_B.Product3;

    /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[10];
      sfcnOutputs(rts, 1);
    }

    {
      real_T tmp;
      real_T tmp_0;

      /* Sum: '<S71>/Sum2' */
      bump_stim_B.Sum2 = (0.0 - bump_stim_B.Product) - bump_stim_B.Product2;

      /* Sum: '<S71>/Sum4' incorporates:
       *  Constant: '<S71>/yoffset'
       */
      bump_stim_B.Sum4 = bump_stim_B.Sum2 + bump_stim_P.yoffset_Value;

      /* Sum: '<S71>/Sum3' */
      bump_stim_B.Sum3_l = bump_stim_B.Product3 - bump_stim_B.Product1;

      /* Sum: '<S71>/Sum1' incorporates:
       *  Constant: '<S71>/xoffset'
       */
      bump_stim_B.Sum1_o = bump_stim_B.Sum3_l + bump_stim_P.xoffset_Value;

      /* Trigonometry: '<S69>/Trigonometric Function1' */
      bump_stim_B.TrigonometricFunction1_k = rt_atan2(bump_stim_B.Sum4,
        bump_stim_B.Sum1_o);

      /* Sum: '<S69>/Sum' incorporates:
       *  Constant: '<S69>/AngleOffset'
       */
      bump_stim_B.Sum_n = bump_stim_B.TrigonometricFunction1_k +
        bump_stim_P.AngleOffset_Value;

      /* Trigonometry: '<S69>/Trigonometric Function2' */
      bump_stim_B.TrigonometricFunction2_l = cos(bump_stim_B.Sum_n);

      /* Fcn: '<S69>/sqrt(u[1]*u[1] + u[2]*u[2])' */
      tmp = bump_stim_B.Sum4;
      tmp_0 = bump_stim_B.Sum1_o;
      bump_stim_B.sqrtu1u1u2u2 = sqrt(tmp * tmp + tmp_0 * tmp_0);

      /* Product: '<S69>/Product1' */
      bump_stim_B.Product1_b = bump_stim_B.TrigonometricFunction2_l *
        bump_stim_B.sqrtu1u1u2u2;
    }

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&bump_stim_B.Product1_b, &bump_stim_B.DigitalFilter2,
                    &bump_stim_DWork.DigitalFilter2_FILT_STATES[0],
                    &bump_stim_DWork.DigitalFilter2_CIRCBUFFIDX, 11, 1, 1,
                    &bump_stim_P.DigitalFilter2_RTP1COEFF[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S67>/Derivative' */
    {
      real_T t = bump_stim_rtM->Timing.t[0];
      real_T timeStampA = bump_stim_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = bump_stim_DWork.Derivative_RWORK.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        bump_stim_B.Derivative = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &bump_stim_DWork.Derivative_RWORK.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        bump_stim_B.Derivative = (bump_stim_B.DigitalFilter2 - *lastBank++) /
          deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S67>/dG' */
    bump_stim_B.dG = bump_stim_P.dG_Gain * bump_stim_B.Derivative;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&bump_stim_B.dG, &bump_stim_B.DigitalFilter,
                    &bump_stim_DWork.DigitalFilter_FILT_STATES[0],
                    &bump_stim_DWork.DigitalFilter_CIRCBUFFIDX, 11, 1, 1,
                    &bump_stim_P.DigitalFilter_RTP1COEFF[0], 1);

    /* Trigonometry: '<S69>/Trigonometric Function' */
    bump_stim_B.TrigonometricFunction_g = sin(bump_stim_B.Sum_n);

    /* Product: '<S69>/Product' */
    bump_stim_B.Product_c = bump_stim_B.sqrtu1u1u2u2 *
      bump_stim_B.TrigonometricFunction_g;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&bump_stim_B.Product_c, &bump_stim_B.DigitalFilter2_n,
                    &bump_stim_DWork.DigitalFilter2_FILT_STATES_c[0],
                    &bump_stim_DWork.DigitalFilter2_CIRCBUFFIDX_k, 11, 1, 1,
                    &bump_stim_P.DigitalFilter2_RTP1COEFF_d[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S68>/Derivative' */
    {
      real_T t = bump_stim_rtM->Timing.t[0];
      real_T timeStampA = bump_stim_DWork.Derivative_RWORK_l.TimeStampA;
      real_T timeStampB = bump_stim_DWork.Derivative_RWORK_l.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        bump_stim_B.Derivative_k = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &bump_stim_DWork.Derivative_RWORK_l.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        bump_stim_B.Derivative_k = (bump_stim_B.DigitalFilter2_n - *lastBank++) /
          deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S68>/dG' */
    bump_stim_B.dG_e = bump_stim_P.dG_Gain_d * bump_stim_B.Derivative_k;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&bump_stim_B.dG_e, &bump_stim_B.DigitalFilter_j,
                    &bump_stim_DWork.DigitalFilter_FILT_STATES_g[0],
                    &bump_stim_DWork.DigitalFilter_CIRCBUFFIDX_k, 11, 1, 1,
                    &bump_stim_P.DigitalFilter_RTP1COEFF_o[0], 1);

    {
      real_T tmp;
      real_T tmp_0;

      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S10>/UseTachs'
       */
      if (bump_stim_P.UseTachs_Value >= bump_stim_P.Switch_Threshold) {
        {
          real_T tmp;
          real_T tmp_0;

          /* Gain: '<S10>/TachGain2' */
          bump_stim_B.TachGain2 = bump_stim_P.TachGain2_Gain *
            bump_stim_B.PCI6025EAD_o2;

          /* Gain: '<S10>/TachGain1' */
          bump_stim_B.TachGain1 = bump_stim_P.TachGain1_Gain *
            bump_stim_B.PCI6025EAD_o1;

          /* SignalConversion: '<S10>/TmpHiddenBufferAtMatrix MultiplyInport2' */
          tmp = bump_stim_B.TachGain1;
          tmp_0 = bump_stim_B.TachGain2;
          bump_stim_B.TmpHiddenBufferAtMatrixMultiply[0] = tmp;
          bump_stim_B.TmpHiddenBufferAtMatrixMultiply[1] = tmp_0;
        }

        {
          static const int_T dims[3] = { 2, 2, 1 };

          rt_MatMultRR_Dbl(bump_stim_B.MatrixMultiply,
                           bump_stim_B.MatrixConcatenate2,
                           bump_stim_B.TmpHiddenBufferAtMatrixMultiply, &dims[0]);
        }

        bump_stim_B.Switch[0] = bump_stim_B.MatrixMultiply[0];
        bump_stim_B.Switch[1] = bump_stim_B.MatrixMultiply[1];
      } else {
        tmp = bump_stim_B.DigitalFilter;
        tmp_0 = bump_stim_B.DigitalFilter_j;
        bump_stim_B.Switch[0] = tmp;
        bump_stim_B.Switch[1] = tmp_0;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S43>/Clock'
     */
    bump_stim_B.Clock_c = bump_stim_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S43>/Memory' */
    bump_stim_B.Memory_e = bump_stim_DWork.Memory_PreviousInput_c;

    /* RelationalOperator: '<S1>/Relational Operator' incorporates:
     *  Constant: '<S1>/XLowLimit'
     */
    bump_stim_B.RelationalOperator_f = (bump_stim_B.Sum3_l <
      bump_stim_P.XLowLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator1' incorporates:
     *  Constant: '<S1>/XHighLimit'
     */
    bump_stim_B.RelationalOperator1 = (bump_stim_B.Sum3_l >
      bump_stim_P.XHighLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator2' incorporates:
     *  Constant: '<S1>/YHighLimit'
     */
    bump_stim_B.RelationalOperator2 = (bump_stim_B.Sum2 <
      bump_stim_P.YHighLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator3' incorporates:
     *  Constant: '<S1>/YLowLimit'
     */
    bump_stim_B.RelationalOperator3 = (bump_stim_B.Sum2 >
      bump_stim_P.YLowLimit_Value);

    /* Logic: '<S1>/Logical Operator' */
    bump_stim_B.LogicalOperator_n = (bump_stim_B.RelationalOperator_f ||
      bump_stim_B.RelationalOperator1 || bump_stim_B.RelationalOperator2 ||
      bump_stim_B.RelationalOperator3);

    /* Logic: '<S5>/InBox' */
    bump_stim_B.InBox = !bump_stim_B.LogicalOperator_n;

    /* Logic: '<S47>/Logical Operator3' */
    bump_stim_B.LogicalOperator3 = !bump_stim_B.InBox;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S47>/Clock'
     */
    bump_stim_B.Clock_d = bump_stim_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S47>/Memory' */
    bump_stim_B.Memory_o = bump_stim_DWork.Memory_PreviousInput_g;

    /* Logic: '<S47>/Logical Operator4' */
    bump_stim_B.LogicalOperator4 = (bump_stim_B.Memory_o &&
      bump_stim_B.LogicalOperator3);

    /* RelationalOperator: '<S36>/Compare' */
    bump_stim_B.Compare_b = (bump_stim_B.Switch[0] == 0.0);

    /* RelationalOperator: '<S37>/Compare' */
    bump_stim_B.Compare_m = (bump_stim_B.Switch[1] == 0.0);

    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Constant: '<S5>/RecenterFlag'
     */
    bump_stim_B.LogicalOperator_k = ((bump_stim_P.RecenterFlag_Value != 0.0) &&
                                     (bump_stim_B.Compare_b != 0U) &&
      (bump_stim_B.Compare_m != 0U) && bump_stim_B.LogicalOperator_n);

    /* Logic: '<S47>/Logical Operator2' */
    bump_stim_B.LogicalOperator2_h = (bump_stim_B.LogicalOperator4 ||
      bump_stim_B.LogicalOperator_k);

    /* Logic: '<S47>/Logical Operator1' */
    bump_stim_B.LogicalOperator1_f = !bump_stim_B.LogicalOperator2_h;

    /* SignalConversion: '<S47>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    bump_stim_B.HiddenBuf_InsertedFor_Enabled_p = bump_stim_B.LogicalOperator1_f;
  }

  /* SubSystem Block: '<S47>/Enabled Subsystem'
   */
  bump_stim_EnabledSubsystem(tid, bump_stim_B.HiddenBuf_InsertedFor_Enabled_p,
    bump_stim_B.Clock_d, &bump_stim_B.EnabledSubsystem_l,
    &bump_stim_DWork.EnabledSubsystem_l);
  if (tid == 0) {
    /* Sum: '<S47>/Sum' */
    bump_stim_B.Sum_g = bump_stim_B.Clock_d - bump_stim_B.EnabledSubsystem_l.In1;

    /* RelationalOperator: '<S60>/Compare' */
    bump_stim_B.Compare_m5 = (bump_stim_B.Sum_g > 0.0);

    /* RelationalOperator: '<S47>/Relational Operator' incorporates:
     *  Constant: '<S47>/Time'
     */
    bump_stim_B.RelationalOperator_a = (bump_stim_B.Sum_g >
      bump_stim_P.Time_Value_j);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S47>/Logical Operator' */
    bump_stim_B.LogicalOperator_j = (boolean_T)((bump_stim_B.Compare_m5 != 0U) ^
      bump_stim_B.RelationalOperator_a);

    /* RelationalOperator: '<S63>/Compare' */
    bump_stim_B.Compare_me = (bump_stim_B.LogicalOperator_j <= FALSE);

    /* UnitDelay: '<S61>/Delay Input1' */
    bump_stim_B.Uk1 = bump_stim_DWork.DelayInput1_DSTATE;

    /* RelationalOperator: '<S61>/FixPt Relational Operator' */
    bump_stim_B.FixPtRelationalOperator = (bump_stim_B.Compare_me >
      bump_stim_B.Uk1);

    /* Logic: '<S47>/Logical Operator5' */
    bump_stim_B.LogicalOperator5 = (bump_stim_B.LogicalOperator3 &&
      (bump_stim_B.FixPtRelationalOperator != 0U));

    /* Logic: '<S43>/Logical Operator2' */
    bump_stim_B.LogicalOperator2_b = (bump_stim_B.Memory_e ||
      bump_stim_B.LogicalOperator5);

    /* Logic: '<S43>/Logical Operator1' */
    bump_stim_B.LogicalOperator1_m = !bump_stim_B.LogicalOperator2_b;

    /* SignalConversion: '<S43>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    bump_stim_B.HiddenBuf_InsertedFor_Enabled_e = bump_stim_B.LogicalOperator1_m;
  }

  /* SubSystem Block: '<S43>/Enabled Subsystem'
   */
  bump_stim_EnabledSubsystem(tid, bump_stim_B.HiddenBuf_InsertedFor_Enabled_e,
    bump_stim_B.Clock_c, &bump_stim_B.EnabledSubsystem_c,
    &bump_stim_DWork.EnabledSubsystem_c);
  if (tid == 0) {
    /* Sum: '<S43>/Sum' */
    bump_stim_B.Sum_b = bump_stim_B.Clock_c - bump_stim_B.EnabledSubsystem_c.In1;

    /* RelationalOperator: '<S53>/Compare' */
    bump_stim_B.Compare_n = (bump_stim_B.Sum_b > 0.0);

    /* RelationalOperator: '<S43>/Relational Operator' incorporates:
     *  Constant: '<S43>/Time'
     */
    bump_stim_B.RelationalOperator_i = (bump_stim_B.Sum_b >
      bump_stim_P.Time_Value_k);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S43>/Logical Operator' */
    bump_stim_B.LogicalOperator_g = (boolean_T)((bump_stim_B.Compare_n != 0U) ^
      bump_stim_B.RelationalOperator_i);

    /* Abs: '<S40>/Abs2' */
    bump_stim_B.Abs2 = fabs(bump_stim_B.Switch[0]);

    /* RelationalOperator: '<S51>/Compare' incorporates:
     *  Constant: '<S51>/Constant'
     */
    bump_stim_B.Compare_p = (bump_stim_B.Abs2 <= bump_stim_P.Constant_Value);

    /* Abs: '<S40>/Abs3' */
    bump_stim_B.Abs3 = fabs(bump_stim_B.Switch[1]);

    /* RelationalOperator: '<S52>/Compare' incorporates:
     *  Constant: '<S52>/Constant'
     */
    bump_stim_B.Compare_mc = (bump_stim_B.Abs3 <= bump_stim_P.Constant_Value_a);

    /* Logic: '<S40>/Logical Operator1' */
    bump_stim_B.LogicalOperator1_a = ((bump_stim_B.Compare_p != 0U) &&
      (bump_stim_B.Compare_mc != 0U));

    /* Logic: '<S5>/NOT' */
    bump_stim_B.NOT = !bump_stim_B.LogicalOperator1_a;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S45>/Clock'
     */
    bump_stim_B.Clock_a = bump_stim_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S45>/Memory' */
    bump_stim_B.Memory_em = bump_stim_DWork.Memory_PreviousInput_bt;

    /* RelationalOperator: '<S59>/Compare' */
    bump_stim_B.Compare_g = (bump_stim_B.LogicalOperator1_a <= FALSE);

    /* UnitDelay: '<S46>/Delay Input1' */
    bump_stim_B.Uk1_h = bump_stim_DWork.DelayInput1_DSTATE_a;

    /* RelationalOperator: '<S46>/FixPt Relational Operator' */
    bump_stim_B.FixPtRelationalOperator_k = (bump_stim_B.Compare_g >
      bump_stim_B.Uk1_h);

    /* Logic: '<S45>/Logical Operator2' */
    bump_stim_B.LogicalOperator2_p = (bump_stim_B.Memory_em ||
      (bump_stim_B.FixPtRelationalOperator_k != 0U));

    /* Logic: '<S45>/Logical Operator1' */
    bump_stim_B.LogicalOperator1_e = !bump_stim_B.LogicalOperator2_p;

    /* SignalConversion: '<S45>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    bump_stim_B.HiddenBuf_InsertedFor_Enabled_j = bump_stim_B.LogicalOperator1_e;
  }

  /* SubSystem Block: '<S45>/Enabled Subsystem'
   */
  bump_stim_EnabledSubsystem(tid, bump_stim_B.HiddenBuf_InsertedFor_Enabled_j,
    bump_stim_B.Clock_a, &bump_stim_B.EnabledSubsystem_o,
    &bump_stim_DWork.EnabledSubsystem_o);
  if (tid == 0) {
    /* Sum: '<S45>/Sum' */
    bump_stim_B.Sum_k = bump_stim_B.Clock_a - bump_stim_B.EnabledSubsystem_o.In1;

    /* RelationalOperator: '<S57>/Compare' */
    bump_stim_B.Compare_k = (bump_stim_B.Sum_k > 0.0);

    /* RelationalOperator: '<S45>/Relational Operator' incorporates:
     *  Constant: '<S45>/Time'
     */
    bump_stim_B.RelationalOperator_p = (bump_stim_B.Sum_k >
      bump_stim_P.Time_Value_l);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S45>/Logical Operator' */
    bump_stim_B.LogicalOperator_o = (boolean_T)((bump_stim_B.Compare_k != 0U) ^
      bump_stim_B.RelationalOperator_p);

    /* RelationalOperator: '<S50>/Compare' */
    bump_stim_B.Compare_l = (bump_stim_B.LogicalOperator_o <= FALSE);

    /* UnitDelay: '<S39>/Delay Input1' */
    bump_stim_B.Uk1_p = bump_stim_DWork.DelayInput1_DSTATE_n;

    /* RelationalOperator: '<S39>/FixPt Relational Operator' */
    bump_stim_B.FixPtRelationalOperator_n = (bump_stim_B.Compare_l >
      bump_stim_B.Uk1_p);

    /* DataTypeConversion: '<S5>/Data Type Conversion2' */
    bump_stim_B.DataTypeConversion2 = (bump_stim_B.FixPtRelationalOperator_n !=
      0U);

    /* Logic: '<S5>/Logical Operator1' */
    bump_stim_B.LogicalOperator1_an = (bump_stim_B.NOT ||
      bump_stim_B.DataTypeConversion2);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S44>/Clock'
     */
    bump_stim_B.Clock_n = bump_stim_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S44>/Memory' */
    bump_stim_B.Memory_d = bump_stim_DWork.Memory_PreviousInput_n;

    /* Logic: '<S44>/Logical Operator2' */
    bump_stim_B.LogicalOperator2_o = (bump_stim_B.Memory_d ||
      bump_stim_B.LogicalOperator5);

    /* Logic: '<S44>/Logical Operator1' */
    bump_stim_B.LogicalOperator1_n = !bump_stim_B.LogicalOperator2_o;

    /* SignalConversion: '<S44>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    bump_stim_B.HiddenBuf_InsertedFor_Enabled_b = bump_stim_B.LogicalOperator1_n;
  }

  /* SubSystem Block: '<S44>/Enabled Subsystem'
   */
  bump_stim_EnabledSubsystem(tid, bump_stim_B.HiddenBuf_InsertedFor_Enabled_b,
    bump_stim_B.Clock_n, &bump_stim_B.EnabledSubsystem_f,
    &bump_stim_DWork.EnabledSubsystem_f);
  if (tid == 0) {
    /* Sum: '<S44>/Sum' */
    bump_stim_B.Sum_gv = bump_stim_B.Clock_n -
      bump_stim_B.EnabledSubsystem_f.In1;

    /* RelationalOperator: '<S55>/Compare' */
    bump_stim_B.Compare_b1 = (bump_stim_B.Sum_gv > 0.0);

    /* RelationalOperator: '<S44>/Relational Operator' incorporates:
     *  Constant: '<S44>/Time'
     */
    bump_stim_B.RelationalOperator_h = (bump_stim_B.Sum_gv >
      bump_stim_P.Time_Value_p);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S44>/Logical Operator' */
    bump_stim_B.LogicalOperator_f = (boolean_T)((bump_stim_B.Compare_b1 != 0U) ^
      bump_stim_B.RelationalOperator_h);

    /* RelationalOperator: '<S49>/Compare' */
    bump_stim_B.Compare_mv = (bump_stim_B.LogicalOperator_f <= FALSE);

    /* UnitDelay: '<S38>/Delay Input1' */
    bump_stim_B.Uk1_d = bump_stim_DWork.DelayInput1_DSTATE_f;

    /* RelationalOperator: '<S38>/FixPt Relational Operator' */
    bump_stim_B.FixPtRelationalOperator_d = (bump_stim_B.Compare_mv >
      bump_stim_B.Uk1_d);

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    bump_stim_B.DataTypeConversion1 = (bump_stim_B.FixPtRelationalOperator_d !=
      0U);

    /* Memory: '<S42>/Memory' */
    bump_stim_B.Memory_j = bump_stim_DWork.Memory_PreviousInput_cq;

    /* CombinatorialLogic Block: '<S42>/Logic'
     */
    {
      int_T rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (int_T)(bump_stim_B.LogicalOperator1_an != 0);
      rowidx = (rowidx << 1) + (int_T)(bump_stim_B.DataTypeConversion1 != 0);
      rowidx = (rowidx << 1) + (int_T)(bump_stim_B.Memory_j != 0);

      /* Copy the appropriate row of the table into the block output vector */
      bump_stim_B.Logic[0] = bump_stim_P.Logic_table[rowidx];
      bump_stim_B.Logic[1] = bump_stim_P.Logic_table[rowidx + 8];
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
      bump_stim_B.LogicalOperator5_i = (bump_stim_B.Logic[1] ||
        bump_stim_B.LogicalOperator_f || bump_stim_B.LogicalOperator_n);

      /* UnitDelay: '<S23>/x' */
      bump_stim_B.x = bump_stim_DWork.x_DSTATE;

      /* UnitDelay: '<S24>/x' */
      bump_stim_B.x_p = bump_stim_DWork.x_DSTATE_a;

      /* Sum: '<S21>/Add' */
      bump_stim_B.Add = bump_stim_B.x - bump_stim_B.x_p;

      /* UnitDelay: '<S25>/x' */
      bump_stim_B.x_b = bump_stim_DWork.x_DSTATE_ab;

      /* UnitDelay: '<S26>/x' */
      bump_stim_B.x_h = bump_stim_DWork.x_DSTATE_j;

      /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
       *  Constant: '<S3>/Load'
       *  Constant: '<S3>/Off'
       *  Constant: '<S3>/staticX'
       *  Constant: '<S3>/staticY'
       */
      switch ((int32_T)bump_stim_P.Load_Value) {
       case 0:
        tmp = bump_stim_P.Off_Value_d;
        tmp_0 = bump_stim_P.Off_Value_d;
        bump_stim_B.MultiportSwitch[0] = tmp;
        bump_stim_B.MultiportSwitch[1] = tmp_0;
        break;

       case 1:
        tmp_1 = bump_stim_P.staticX_Value_j;
        tmp_2 = bump_stim_P.staticY_Value_g;
        bump_stim_B.MultiportSwitch[0] = tmp_1;
        bump_stim_B.MultiportSwitch[1] = tmp_2;
        break;

       case 2:
        /* Sum: '<S21>/Add1' */
        bump_stim_B.Add1_h = bump_stim_B.x_b - bump_stim_B.x_h;

        /* Gain: '<S3>/LorentzForceGain' */
        tmp_7 = bump_stim_B.Add;
        tmp_8 = bump_stim_B.Add1_h;
        bump_stim_B.LorentzForceGain[0] = bump_stim_P.LorentzForceGain_Gain_l *
          tmp_7;
        bump_stim_B.LorentzForceGain[1] = bump_stim_P.LorentzForceGain_Gain_l *
          tmp_8;
        bump_stim_B.MultiportSwitch[0] = bump_stim_B.LorentzForceGain[0];
        bump_stim_B.MultiportSwitch[1] = bump_stim_B.LorentzForceGain[1];
        break;

       default:
        /* MultiPortSwitch: '<S3>/dynamicAngle Switch' incorporates:
         *  Constant: '<S3>/DynamicAngle'
         *  Constant: '<S3>/visAngle'
         */
        if ((int32_T)bump_stim_P.DynamicAngle_Value_i == 0) {
          bump_stim_B.dynamicAngleSwitch = bump_stim_P.visAngle_Value_p;
        } else {
          /* Gain: '<S3>/Gain' */
          bump_stim_B.Gain_a = bump_stim_P.Gain_Gain_f * bump_stim_B.Add;
          bump_stim_B.dynamicAngleSwitch = bump_stim_B.Gain_a;
        }

        /* Trigonometry: '<S22>/sin' */
        bump_stim_B.sin_l = sin(bump_stim_B.dynamicAngleSwitch);

        /* Gain: '<S22>/Inverter' */
        bump_stim_B.Inverter[0] = bump_stim_P.Inverter_Gain_d *
          bump_stim_B.Switch[0];
        bump_stim_B.Inverter[1] = bump_stim_P.Inverter_Gain_d *
          bump_stim_B.Switch[1];

        /* Product: '<S22>/Product3' */
        cg_in = bump_stim_B.Inverter[0];
        bump_stim_B.Product3_k = cg_in * bump_stim_B.sin_l;

        /* Trigonometry: '<S22>/cos' */
        bump_stim_B.cos_k = cos(bump_stim_B.dynamicAngleSwitch);

        /* Product: '<S22>/Product2' */
        cg_in_0 = bump_stim_B.Inverter[1];
        bump_stim_B.Product2_m = cg_in_0 * bump_stim_B.cos_k;

        /* Sum: '<S22>/Subtract' */
        bump_stim_B.Subtract_o = bump_stim_B.Product2_m - bump_stim_B.Product3_k;

        /* Product: '<S22>/Product1' */
        cg_in_1 = bump_stim_B.Inverter[1];
        bump_stim_B.Product1_j = cg_in_1 * bump_stim_B.sin_l;

        /* Product: '<S22>/Product' */
        cg_in_2 = bump_stim_B.Inverter[0];
        bump_stim_B.Product_j = cg_in_2 * bump_stim_B.cos_k;

        /* Sum: '<S22>/Add' */
        bump_stim_B.Add_l = bump_stim_B.Product_j + bump_stim_B.Product1_j;

        /* Gain: '<S22>/Gain' */
        tmp_9 = bump_stim_B.Add_l;
        tmp_a = bump_stim_B.Subtract_o;
        bump_stim_B.Gain_n[0] = bump_stim_P.Gain_Gain_c * tmp_9;
        bump_stim_B.Gain_n[1] = bump_stim_P.Gain_Gain_c * tmp_a;
        bump_stim_B.MultiportSwitch[0] = bump_stim_B.Gain_n[0];
        bump_stim_B.MultiportSwitch[1] = bump_stim_B.Gain_n[1];
        break;
      }

      /* UnitDelay: '<S17>/x' */
      bump_stim_B.x_e = bump_stim_DWork.x_DSTATE_g;

      /* UnitDelay: '<S18>/x' */
      bump_stim_B.x_hx = bump_stim_DWork.x_DSTATE_o;

      /* Sum: '<S15>/Add' */
      bump_stim_B.Add_d = bump_stim_B.x_e - bump_stim_B.x_hx;

      /* UnitDelay: '<S19>/x' */
      bump_stim_B.x_ei = bump_stim_DWork.x_DSTATE_c;

      /* UnitDelay: '<S20>/x' */
      bump_stim_B.x_j = bump_stim_DWork.x_DSTATE_n;

      /* MultiPortSwitch: '<S2>/LoadSelect Switch' incorporates:
       *  Constant: '<S2>/Load'
       *  Constant: '<S2>/Off'
       *  Constant: '<S2>/staticX'
       *  Constant: '<S2>/staticY'
       */
      switch ((int32_T)bump_stim_P.Load_Value_n) {
       case 0:
        tmp_3 = bump_stim_P.Off_Value;
        tmp_4 = bump_stim_P.Off_Value;
        bump_stim_B.LoadSelectSwitch[0] = tmp_3;
        bump_stim_B.LoadSelectSwitch[1] = tmp_4;
        break;

       case 1:
        tmp_5 = bump_stim_P.staticX_Value;
        tmp_6 = bump_stim_P.staticY_Value;
        bump_stim_B.LoadSelectSwitch[0] = tmp_5;
        bump_stim_B.LoadSelectSwitch[1] = tmp_6;
        break;

       case 2:
        /* Sum: '<S15>/Add1' */
        bump_stim_B.Add1_l2 = bump_stim_B.x_ei - bump_stim_B.x_j;

        /* Gain: '<S2>/LorentzForceGain' */
        tmp_b = bump_stim_B.Add_d;
        tmp_c = bump_stim_B.Add1_l2;
        bump_stim_B.LorentzForceGain_p[0] = bump_stim_P.LorentzForceGain_Gain *
          tmp_b;
        bump_stim_B.LorentzForceGain_p[1] = bump_stim_P.LorentzForceGain_Gain *
          tmp_c;
        bump_stim_B.LoadSelectSwitch[0] = bump_stim_B.LorentzForceGain_p[0];
        bump_stim_B.LoadSelectSwitch[1] = bump_stim_B.LorentzForceGain_p[1];
        break;

       default:
        /* MultiPortSwitch: '<S2>/DynamicAngle Switch' incorporates:
         *  Constant: '<S2>/DynamicAngle'
         *  Constant: '<S2>/visAngle'
         */
        if ((int32_T)bump_stim_P.DynamicAngle_Value == 0) {
          bump_stim_B.DynamicAngleSwitch = bump_stim_P.visAngle_Value;
        } else {
          /* Gain: '<S2>/Gain' */
          bump_stim_B.Gain_p = bump_stim_P.Gain_Gain_j * bump_stim_B.Add_d;
          bump_stim_B.DynamicAngleSwitch = bump_stim_B.Gain_p;
        }

        /* Trigonometry: '<S16>/sin' */
        bump_stim_B.sin_k = sin(bump_stim_B.DynamicAngleSwitch);

        /* Gain: '<S16>/Inverter' */
        bump_stim_B.Inverter_i[0] = bump_stim_P.Inverter_Gain *
          bump_stim_B.Switch[0];
        bump_stim_B.Inverter_i[1] = bump_stim_P.Inverter_Gain *
          bump_stim_B.Switch[1];

        /* Product: '<S16>/Product3' */
        cg_in_3 = bump_stim_B.Inverter_i[0];
        bump_stim_B.Product3_g = cg_in_3 * bump_stim_B.sin_k;

        /* Trigonometry: '<S16>/cos' */
        bump_stim_B.cos_kc = cos(bump_stim_B.DynamicAngleSwitch);

        /* Product: '<S16>/Product2' */
        cg_in_4 = bump_stim_B.Inverter_i[1];
        bump_stim_B.Product2_l = cg_in_4 * bump_stim_B.cos_kc;

        /* Sum: '<S16>/Subtract' */
        bump_stim_B.Subtract_k = bump_stim_B.Product2_l - bump_stim_B.Product3_g;

        /* Product: '<S16>/Product1' */
        cg_in_5 = bump_stim_B.Inverter_i[1];
        bump_stim_B.Product1_k = cg_in_5 * bump_stim_B.sin_k;

        /* Product: '<S16>/Product' */
        cg_in_6 = bump_stim_B.Inverter_i[0];
        bump_stim_B.Product_n = cg_in_6 * bump_stim_B.cos_kc;

        /* Sum: '<S16>/Add' */
        bump_stim_B.Add_lj = bump_stim_B.Product_n + bump_stim_B.Product1_k;

        /* Gain: '<S16>/Gain' */
        tmp_d = bump_stim_B.Add_lj;
        tmp_e = bump_stim_B.Subtract_k;
        bump_stim_B.Gain_ax[0] = bump_stim_P.Gain_Gain_pe * tmp_d;
        bump_stim_B.Gain_ax[1] = bump_stim_P.Gain_Gain_pe * tmp_e;
        bump_stim_B.LoadSelectSwitch[0] = bump_stim_B.Gain_ax[0];
        bump_stim_B.LoadSelectSwitch[1] = bump_stim_B.Gain_ax[1];
        break;
      }
    }

    /* Level2 S-Function Block: '<Root>/Behavior BS' (mastercon_bs) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[11];
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
      if (bump_stim_B.LogicalOperator) {
        tmp = bump_stim_P.zeroX_Value;
        tmp_0 = bump_stim_P.zeroY_Value;
        bump_stim_B.Switch2[0] = tmp;
        bump_stim_B.Switch2[1] = tmp_0;
      } else {
        /* Switch: '<S4>/Switch1' */
        if (bump_stim_B.LogicalOperator5_i) {
          /* Logic: '<S5>/Logical Operator6' */
          bump_stim_B.LogicalOperator6 = !bump_stim_B.LogicalOperator_g;

          /* Logic: '<S5>/Logical Operator3' */
          bump_stim_B.LogicalOperator3_f = (bump_stim_B.LogicalOperator6 &&
            bump_stim_B.LogicalOperator_n);

          /* Switch: '<S5>/Switch' */
          if (bump_stim_B.LogicalOperator3_f) {
            /* Gain: '<S5>/Bounding Box Viscosity' */
            bump_stim_B.BoundingBoxViscosity[0] =
              bump_stim_P.BoundingBoxViscosity_Gain * bump_stim_B.Switch[0];
            bump_stim_B.BoundingBoxViscosity[1] =
              bump_stim_P.BoundingBoxViscosity_Gain * bump_stim_B.Switch[1];
            bump_stim_B.Switch_a[0] = bump_stim_B.BoundingBoxViscosity[0];
            bump_stim_B.Switch_a[1] = bump_stim_B.BoundingBoxViscosity[1];
          } else {
            /* Product: '<S41>/Product' */
            bump_stim_B.Product_i = (int32_T)bump_stim_B.LogicalOperator_g ?
              bump_stim_B.Product1_b : 0.0;

            /* Gain: '<S41>/Gain1' */
            bump_stim_B.Gain1_d = bump_stim_P.Gain1_Gain_j *
              bump_stim_B.Product_i;

            /* Gain: '<S41>/Gain3' */
            bump_stim_B.Gain3 = bump_stim_P.Gain3_Gain * bump_stim_B.Switch[0];

            /* Sum: '<S41>/Add' */
            bump_stim_B.Add_i = bump_stim_B.Gain3 + bump_stim_B.Gain1_d;

            /* Saturate: '<S41>/Saturation' */
            rtsaturate_U0DataInY0Container = rt_SATURATE(bump_stim_B.Add_i,
              bump_stim_P.Saturation_LowerSat, bump_stim_P.Saturation_UpperSat);
            bump_stim_B.Saturation = rtsaturate_U0DataInY0Container;

            /* Gain: '<S41>/Gain4' */
            bump_stim_B.Gain4 = bump_stim_P.Gain4_Gain * bump_stim_B.Switch[1];

            /* Product: '<S41>/Product1' */
            bump_stim_B.Product1_o = (int32_T)bump_stim_B.LogicalOperator_g ?
              bump_stim_B.Product_c : 0.0;

            /* Gain: '<S41>/Gain2' */
            bump_stim_B.Gain2 = bump_stim_P.Gain2_Gain_e *
              bump_stim_B.Product1_o;

            /* Sum: '<S41>/Add1' */
            bump_stim_B.Add1_l = bump_stim_B.Gain2 + bump_stim_B.Gain4;

            /* Saturate: '<S41>/Saturation1' */
            rtsaturate_U0DataInY0Containe_0 = rt_SATURATE(bump_stim_B.Add1_l,
              bump_stim_P.Saturation1_LowerSat, bump_stim_P.Saturation1_UpperSat);
            bump_stim_B.Saturation1 = rtsaturate_U0DataInY0Containe_0;
            tmp_1 = bump_stim_B.Saturation;
            tmp_2 = bump_stim_B.Saturation1;
            bump_stim_B.Switch_a[0] = tmp_1;
            bump_stim_B.Switch_a[1] = tmp_2;
          }

          bump_stim_B.Switch1[0] = bump_stim_B.Switch_a[0];
          bump_stim_B.Switch1[1] = bump_stim_B.Switch_a[1];
        } else {
          bump_stim_B.Switch1[0] = bump_stim_B.BehaviorBS_o1[0];
          bump_stim_B.Switch1[1] = bump_stim_B.BehaviorBS_o1[1];
        }

        bump_stim_B.Switch2[0] = bump_stim_B.Switch1[0];
        bump_stim_B.Switch2[1] = bump_stim_B.Switch1[1];
      }

      /* Output and update for atomic system: '<S4>/Force//Torque Transform' */

      /* Gain: '<S29>/Gain' */
      bump_stim_B.Gain_g[0] = bump_stim_P.Gain_Gain_g * bump_stim_B.Switch2[0];
      bump_stim_B.Gain_g[1] = bump_stim_P.Gain_Gain_g * bump_stim_B.Switch2[1];

      /* Math Block: '<S33>/Math Function'
       */
      /* Operator : transpose */
      {
        uint32_T count = 0;
        uint32_T row;
        uint32_T col;
        for (row= 0; row < 2; row++) {
          for (col= 0; col < 2; col++) {
            bump_stim_B.MathFunction[row + 2 * col] =
              bump_stim_B.MatrixConcatenate2[count];
            count++;
          }
        }
      }

      {
        static const int_T dims[3] = { 2, 2, 1 };

        rt_MatMultRR_Dbl(bump_stim_B.MatrixMultiply_l, bump_stim_B.MathFunction,
                         bump_stim_B.Gain_g, &dims[0]);
      }

      /* Gain: '<S4>/MG1' */
      bump_stim_B.MG1 = bump_stim_P.MG1_Gain * bump_stim_B.MatrixMultiply_l[0];

      /* Gain: '<S4>/MG2' */
      bump_stim_B.MG2 = bump_stim_P.MG2_Gain * bump_stim_B.MatrixMultiply_l[1];
    }

    /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[12];
      sfcnOutputs(rts, 1);
    }

    /* ok to acquire for <S30>/S-Function */
    bump_stim_DWork.SFunction_IWORK.AcquireOK = 1;

    /* ok to acquire for <S32>/S-Function */
    bump_stim_DWork.SFunction_IWORK_g.AcquireOK = 1;

    /* RelationalOperator: '<S27>/Compare' incorporates:
     *  Constant: '<S27>/Constant'
     */
    bump_stim_B.Compare_o = (bump_stim_B.MG1 > bump_stim_P.Constant_Value_e);

    /* RelationalOperator: '<S28>/Compare' incorporates:
     *  Constant: '<S28>/Constant'
     */
    bump_stim_B.Compare_h = (bump_stim_B.MG2 > bump_stim_P.Constant_Value_f);

    /* SignalConversion: '<S4>/ConcatHiddenBufferAtMatrix ConcatenationInPort0' */
    bump_stim_B.MatrixConcatenation[0] = bump_stim_B.LogicalOperator5_i;

    /* SignalConversion: '<S4>/ConcatHiddenBufferAtMatrix ConcatenationInPort1' */
    bump_stim_B.MatrixConcatenation[1] = bump_stim_B.LogicalOperator;

    /* Logic: '<S4>/Logical Operator1' */
    bump_stim_B.LogicalOperator1_l = ((bump_stim_B.Compare_o != 0U) ||
      (bump_stim_B.Compare_h != 0U));

    /* ok to acquire for <S7>/S-Function */
    bump_stim_DWork.SFunction_IWORK_c.AcquireOK = 1;

    /* Pack: <S9>/Pack */
    (void) memcpy(bump_stim_B.Pack,&bump_stim_B.BehaviorBS_o8[0],
                  8);
    (void) memcpy(&bump_stim_B.Pack[8],&bump_stim_B.BehaviorBS_o8[1],
                  8);
    (void) memcpy(&bump_stim_B.Pack[16],&bump_stim_B.BehaviorBS_o4[0],
                  8);
    (void) memcpy(&bump_stim_B.Pack[24],&bump_stim_B.BehaviorBS_o4[1],
                  8);
    (void) memcpy(&bump_stim_B.Pack[32],&bump_stim_B.BehaviorBS_o4[2],
                  8);
    (void) memcpy(&bump_stim_B.Pack[40],&bump_stim_B.BehaviorBS_o4[3],
                  8);
    (void) memcpy(&bump_stim_B.Pack[48],&bump_stim_B.BehaviorBS_o4[4],
                  8);
    (void) memcpy(&bump_stim_B.Pack[56],&bump_stim_B.BehaviorBS_o4[5],
                  8);
    (void) memcpy(&bump_stim_B.Pack[64],&bump_stim_B.BehaviorBS_o4[6],
                  8);
    (void) memcpy(&bump_stim_B.Pack[72],&bump_stim_B.BehaviorBS_o4[7],
                  8);
    (void) memcpy(&bump_stim_B.Pack[80],&bump_stim_B.BehaviorBS_o4[8],
                  8);
    (void) memcpy(&bump_stim_B.Pack[88],&bump_stim_B.BehaviorBS_o4[9],
                  8);
    (void) memcpy(&bump_stim_B.Pack[96],&bump_stim_B.BehaviorBS_o6[0],
                  8);
    (void) memcpy(&bump_stim_B.Pack[104],&bump_stim_B.BehaviorBS_o6[1],
                  8);
  }

  {
    int32_T i;

    /* RateTransition: '<S9>/Rate Transition' */
    if (tid == 0 && bump_stim_rtM->Timing.RateInteraction.TID1_2) {
      for (i = 0; i < 112; i++) {
        bump_stim_B.RateTransition[i] = bump_stim_B.Pack[i];
      }
    }
  }

  if (tid == 2) {                      /* Sample time: [0.02s, 0.0s] */
    /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[13];
      sfcnOutputs(rts, 2);
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* ok to acquire for <S11>/S-Function */
    bump_stim_DWork.SFunction_IWORK_d.AcquireOK = 1;

    /* ok to acquire for <S14>/S-Function */
    bump_stim_DWork.SFunction_IWORK_m.AcquireOK = 1;

    /* ok to acquire for <S48>/S-Function */
    bump_stim_DWork.SFunction_IWORK_n.AcquireOK = 1;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S65>/Clock'
     */
    bump_stim_B.Clock_j = bump_stim_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* SignalConversion: '<S65>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    bump_stim_B.HiddenBuf_InsertedFor_Sampleand = bump_stim_B.BehaviorBS_o5;
  }

  /* SubSystem Block: '<S65>/Sample and Hold'
   */
  if (tid == 0) {
    bump_stim_SampleandHold(bump_stim_B.HiddenBuf_InsertedFor_Sampleand,
      bump_stim_B.Clock_j, &bump_stim_B.SampleandHold,
      &bump_stim_DWork.SampleandHold, &bump_stim_PrevZCSigState.SampleandHold);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Sum: '<S65>/Sum' */
    bump_stim_B.Sum_c = bump_stim_B.Clock_j - bump_stim_B.SampleandHold.In;
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* UniformRandomNumber Block: '<S6>/Uniform Random Number'
     */
    bump_stim_B.UniformRandomNumber =
      bump_stim_DWork.UniformRandomNumber_RWORK.NextOutput;

    /* RelationalOperator: '<S6>/Relational Operator' incorporates:
     *  Constant: '<S6>/JackpotChance'
     */
    bump_stim_B.RelationalOperator_m = (bump_stim_B.UniformRandomNumber >
      bump_stim_P.JackpotChance_Value);

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/RewardJackpot'
     *  Constant: '<S6>/RewardTime'
     */
    if (bump_stim_B.RelationalOperator_m) {
      bump_stim_B.Switch_n = bump_stim_P.RewardTime_Value;
    } else {
      bump_stim_B.Switch_n = bump_stim_P.RewardJackpot_Value;
    }

    /* SignalConversion: '<S6>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    bump_stim_B.HiddenBuf_InsertedFor_Samplea_j = bump_stim_B.BehaviorBS_o5;
  }

  /* SubSystem Block: '<S6>/Sample and Hold'
   */
  if (tid == 0) {
    bump_stim_SampleandHold(bump_stim_B.HiddenBuf_InsertedFor_Samplea_j,
      bump_stim_B.Switch_n, &bump_stim_B.SampleandHold_a,
      &bump_stim_DWork.SampleandHold_a,
      &bump_stim_PrevZCSigState.SampleandHold_a);
  }

  {
    int32_T s70_iter;
    real_T tmp;
    real_T tmp_0;
    if (tid == 0) {
      /* RelationalOperator: '<S65>/Relational Operator' */
      bump_stim_B.RelationalOperator_f5 = (bump_stim_B.Sum_c <
        bump_stim_B.SampleandHold_a.In);

      /* DataTypeConversion: '<S6>/Data Type Conversion' */
      bump_stim_B.DataTypeConversion = (real_T)bump_stim_B.RelationalOperator_f5;
    }

    if (tid == 0) {
      for (s70_iter = 0; s70_iter < 4; s70_iter++) {
        bump_stim_B.ForIterator = (real_T)s70_iter;

        /* Output and update for iterator system: '<S13>/For Iterator Subsystem' */

        /* Switch: '<S70>/Switch' incorporates:
         *  Constant: '<S70>/Constant2'
         */
        if (bump_stim_B.ForIterator >= bump_stim_P.Switch_Threshold_m) {
          bump_stim_B.Switch_e = bump_stim_B.BehaviorBS_o3;
        } else {
          bump_stim_B.Switch_e = bump_stim_P.Constant2_Value;
        }

        /* Level2 S-Function Block: '<S70>/ToBits1' (Byte2Bits) */
        {
          SimStruct *rts = bump_stim_rtM->childSfunctions[2];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
        {
          SimStruct *rts = bump_stim_rtM->childSfunctions[3];
          sfcnOutputs(rts, 1);
        }

        /* Sum: '<S70>/Add' incorporates:
         *  Constant: '<S70>/Constant'
         */
        bump_stim_B.Add_p = bump_stim_B.PCIQUAD04 + bump_stim_P.Constant_Value_p;

        /* Sum: '<S70>/Add1' incorporates:
         *  Constant: '<S70>/Constant'
         */
        bump_stim_B.Add1_j = bump_stim_B.PCIQUAD041 +
          bump_stim_P.Constant_Value_p;

        /* Level2 S-Function Block: '<S70>/SerialConverter' (serPos) */
        {
          SimStruct *rts = bump_stim_rtM->childSfunctions[4];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/ToBits' (Byte2Bits) */
        {
          SimStruct *rts = bump_stim_rtM->childSfunctions[5];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
        {
          SimStruct *rts = bump_stim_rtM->childSfunctions[6];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/xPC Target  Time ' (xpctimeinfo) */
        {
          SimStruct *rts = bump_stim_rtM->childSfunctions[7];
          sfcnOutputs(rts, 1);
        }

        do {
          /* Output and update for iterator system: '<S70>/While Iterator Subsystem' */

          /* Level2 S-Function Block: '<S72>/xPC Target  Time ' (xpctimeinfo) */
          {
            SimStruct *rts = bump_stim_rtM->childSfunctions[0];
            sfcnOutputs(rts, 1);
          }

          /* Sum: '<S72>/Subtract' */
          bump_stim_B.Subtract = bump_stim_B.xPCTargetTime_c -
            bump_stim_B.xPCTargetTime;

          /* Gain: '<S72>/ScaleTouSec' */
          bump_stim_B.ScaleTouSec = bump_stim_P.ScaleTouSec_Gain *
            bump_stim_B.Subtract;

          /* RelationalOperator: '<S74>/Compare' incorporates:
           *  Constant: '<S74>/Constant'
           */
          bump_stim_B.Compare_a = (bump_stim_B.ScaleTouSec >
            bump_stim_P.Constant_Value_d);

          /* Switch: '<S72>/Switch' incorporates:
           *  Constant: '<S72>/Constant'
           *  Constant: '<S72>/Constant1'
           */
          if (bump_stim_B.Compare_a) {
            bump_stim_B.Switch_j = bump_stim_P.Constant_Value_fq;
          } else {
            bump_stim_B.Switch_j = bump_stim_P.Constant1_Value;
          }

          /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
          {
            SimStruct *rts = bump_stim_rtM->childSfunctions[1];
            sfcnOutputs(rts, 1);
          }

          /* RelationalOperator: '<S73>/Compare' incorporates:
           *  Constant: '<S73>/Constant'
           */
          bump_stim_B.Compare_c = (bump_stim_B.ScaleTouSec <=
            bump_stim_P.Constant_Value_j);
        } while (bump_stim_B.Compare_c);
      }

      /* UnitDelay: '<S17>/y' */
      bump_stim_B.y = bump_stim_DWork.y_DSTATE;

      /* Sum: '<S17>/Add1' */
      bump_stim_B.Add1 = bump_stim_B.y - bump_stim_B.x_e;

      /* UnitDelay: '<S17>/z' */
      bump_stim_B.z = bump_stim_DWork.z_DSTATE;

      /* Sum: '<S17>/Add3' incorporates:
       *  Constant: '<S17>/rho'
       */
      bump_stim_B.Add3 = bump_stim_P.rho_Value - bump_stim_B.z;

      /* Product: '<S17>/product2' */
      bump_stim_B.product2 = bump_stim_B.x_e * bump_stim_B.Add3;

      /* Sum: '<S17>/Add2' */
      bump_stim_B.Add2 = bump_stim_B.product2 - bump_stim_B.y;

      /* Product: '<S17>/product3' incorporates:
       *  Constant: '<S17>/beta'
       */
      bump_stim_B.product3 = bump_stim_B.z * bump_stim_P.beta_Value;

      /* Product: '<S17>/product4' */
      bump_stim_B.product4 = bump_stim_B.y * bump_stim_B.x_e;

      /* Sum: '<S17>/Add4' */
      bump_stim_B.Add4 = bump_stim_B.product4 - bump_stim_B.product3;

      /* Product: '<S17>/product1' incorporates:
       *  Constant: '<S17>/sigma'
       */
      bump_stim_B.product1 = bump_stim_B.Add1 * bump_stim_P.sigma_Value;

      /* Product: '<S17>/dX' incorporates:
       *  Constant: '<S17>/timescale'
       */
      bump_stim_B.dX = bump_stim_P.timescale_Value * bump_stim_B.product1;

      /* Sum: '<S17>/AddX' */
      bump_stim_B.AddX = bump_stim_B.x_e + bump_stim_B.dX;

      /* Product: '<S17>/dY' incorporates:
       *  Constant: '<S17>/timescale'
       */
      bump_stim_B.dY = bump_stim_P.timescale_Value * bump_stim_B.Add2;

      /* Sum: '<S17>/AddX1' */
      bump_stim_B.AddX1 = bump_stim_B.y + bump_stim_B.dY;

      /* Product: '<S17>/dZ' incorporates:
       *  Constant: '<S17>/timescale'
       */
      bump_stim_B.dZ = bump_stim_P.timescale_Value * bump_stim_B.Add4;

      /* Sum: '<S17>/AddX2' */
      bump_stim_B.AddX2 = bump_stim_B.z + bump_stim_B.dZ;

      /* UnitDelay: '<S18>/y' */
      bump_stim_B.y_o = bump_stim_DWork.y_DSTATE_d;

      /* Sum: '<S18>/Add1' */
      bump_stim_B.Add1_m = bump_stim_B.y_o - bump_stim_B.x_hx;

      /* UnitDelay: '<S18>/z' */
      bump_stim_B.z_e = bump_stim_DWork.z_DSTATE_b;

      /* Sum: '<S18>/Add3' incorporates:
       *  Constant: '<S18>/rho'
       */
      bump_stim_B.Add3_b = bump_stim_P.rho_Value_p - bump_stim_B.z_e;

      /* Product: '<S18>/product2' */
      bump_stim_B.product2_i = bump_stim_B.x_hx * bump_stim_B.Add3_b;

      /* Sum: '<S18>/Add2' */
      bump_stim_B.Add2_h = bump_stim_B.product2_i - bump_stim_B.y_o;

      /* Product: '<S18>/product3' incorporates:
       *  Constant: '<S18>/beta'
       */
      bump_stim_B.product3_g = bump_stim_B.z_e * bump_stim_P.beta_Value_f;

      /* Product: '<S18>/product4' */
      bump_stim_B.product4_g = bump_stim_B.y_o * bump_stim_B.x_hx;

      /* Sum: '<S18>/Add4' */
      bump_stim_B.Add4_i = bump_stim_B.product4_g - bump_stim_B.product3_g;

      /* Product: '<S18>/product1' incorporates:
       *  Constant: '<S18>/sigma'
       */
      bump_stim_B.product1_o = bump_stim_B.Add1_m * bump_stim_P.sigma_Value_o;

      /* Product: '<S18>/dX' incorporates:
       *  Constant: '<S18>/timescale'
       */
      bump_stim_B.dX_b = bump_stim_P.timescale_Value_i * bump_stim_B.product1_o;

      /* Sum: '<S18>/AddX' */
      bump_stim_B.AddX_d = bump_stim_B.x_hx + bump_stim_B.dX_b;

      /* Product: '<S18>/dY' incorporates:
       *  Constant: '<S18>/timescale'
       */
      bump_stim_B.dY_a = bump_stim_P.timescale_Value_i * bump_stim_B.Add2_h;

      /* Sum: '<S18>/AddX1' */
      bump_stim_B.AddX1_f = bump_stim_B.y_o + bump_stim_B.dY_a;

      /* Product: '<S18>/dZ' incorporates:
       *  Constant: '<S18>/timescale'
       */
      bump_stim_B.dZ_f = bump_stim_P.timescale_Value_i * bump_stim_B.Add4_i;

      /* Sum: '<S18>/AddX2' */
      bump_stim_B.AddX2_b = bump_stim_B.z_e + bump_stim_B.dZ_f;

      /* UnitDelay: '<S19>/y' */
      bump_stim_B.y_g = bump_stim_DWork.y_DSTATE_h;

      /* Sum: '<S19>/Add1' */
      bump_stim_B.Add1_e = bump_stim_B.y_g - bump_stim_B.x_ei;

      /* UnitDelay: '<S19>/z' */
      bump_stim_B.z_p = bump_stim_DWork.z_DSTATE_i;

      /* Sum: '<S19>/Add3' incorporates:
       *  Constant: '<S19>/rho'
       */
      bump_stim_B.Add3_c = bump_stim_P.rho_Value_c - bump_stim_B.z_p;

      /* Product: '<S19>/product2' */
      bump_stim_B.product2_io = bump_stim_B.x_ei * bump_stim_B.Add3_c;

      /* Sum: '<S19>/Add2' */
      bump_stim_B.Add2_l = bump_stim_B.product2_io - bump_stim_B.y_g;

      /* Product: '<S19>/product3' incorporates:
       *  Constant: '<S19>/beta'
       */
      bump_stim_B.product3_i = bump_stim_B.z_p * bump_stim_P.beta_Value_n;

      /* Product: '<S19>/product4' */
      bump_stim_B.product4_m = bump_stim_B.y_g * bump_stim_B.x_ei;

      /* Sum: '<S19>/Add4' */
      bump_stim_B.Add4_m = bump_stim_B.product4_m - bump_stim_B.product3_i;

      /* Product: '<S19>/product1' incorporates:
       *  Constant: '<S19>/sigma'
       */
      bump_stim_B.product1_b = bump_stim_B.Add1_e * bump_stim_P.sigma_Value_p;

      /* Product: '<S19>/dX' incorporates:
       *  Constant: '<S19>/timescale'
       */
      bump_stim_B.dX_g = bump_stim_P.timescale_Value_n * bump_stim_B.product1_b;

      /* Sum: '<S19>/AddX' */
      bump_stim_B.AddX_b = bump_stim_B.x_ei + bump_stim_B.dX_g;

      /* Product: '<S19>/dY' incorporates:
       *  Constant: '<S19>/timescale'
       */
      bump_stim_B.dY_k = bump_stim_P.timescale_Value_n * bump_stim_B.Add2_l;

      /* Sum: '<S19>/AddX1' */
      bump_stim_B.AddX1_h = bump_stim_B.y_g + bump_stim_B.dY_k;

      /* Product: '<S19>/dZ' incorporates:
       *  Constant: '<S19>/timescale'
       */
      bump_stim_B.dZ_p = bump_stim_P.timescale_Value_n * bump_stim_B.Add4_m;

      /* Sum: '<S19>/AddX2' */
      bump_stim_B.AddX2_bo = bump_stim_B.z_p + bump_stim_B.dZ_p;

      /* UnitDelay: '<S20>/y' */
      bump_stim_B.y_h = bump_stim_DWork.y_DSTATE_o;

      /* Sum: '<S20>/Add1' */
      bump_stim_B.Add1_f = bump_stim_B.y_h - bump_stim_B.x_j;

      /* UnitDelay: '<S20>/z' */
      bump_stim_B.z_k = bump_stim_DWork.z_DSTATE_c;

      /* Sum: '<S20>/Add3' incorporates:
       *  Constant: '<S20>/rho'
       */
      bump_stim_B.Add3_e = bump_stim_P.rho_Value_k - bump_stim_B.z_k;

      /* Product: '<S20>/product2' */
      bump_stim_B.product2_f = bump_stim_B.x_j * bump_stim_B.Add3_e;

      /* Sum: '<S20>/Add2' */
      bump_stim_B.Add2_m = bump_stim_B.product2_f - bump_stim_B.y_h;

      /* Product: '<S20>/product3' incorporates:
       *  Constant: '<S20>/beta'
       */
      bump_stim_B.product3_c = bump_stim_B.z_k * bump_stim_P.beta_Value_b;

      /* Product: '<S20>/product4' */
      bump_stim_B.product4_h = bump_stim_B.y_h * bump_stim_B.x_j;

      /* Sum: '<S20>/Add4' */
      bump_stim_B.Add4_l = bump_stim_B.product4_h - bump_stim_B.product3_c;

      /* Product: '<S20>/product1' incorporates:
       *  Constant: '<S20>/sigma'
       */
      bump_stim_B.product1_j = bump_stim_B.Add1_f * bump_stim_P.sigma_Value_f;

      /* Product: '<S20>/dX' incorporates:
       *  Constant: '<S20>/timescale'
       */
      bump_stim_B.dX_e = bump_stim_P.timescale_Value_h * bump_stim_B.product1_j;

      /* Sum: '<S20>/AddX' */
      bump_stim_B.AddX_i = bump_stim_B.x_j + bump_stim_B.dX_e;

      /* Product: '<S20>/dY' incorporates:
       *  Constant: '<S20>/timescale'
       */
      bump_stim_B.dY_c = bump_stim_P.timescale_Value_h * bump_stim_B.Add2_m;

      /* Sum: '<S20>/AddX1' */
      bump_stim_B.AddX1_l = bump_stim_B.y_h + bump_stim_B.dY_c;

      /* Product: '<S20>/dZ' incorporates:
       *  Constant: '<S20>/timescale'
       */
      bump_stim_B.dZ_h = bump_stim_P.timescale_Value_h * bump_stim_B.Add4_l;

      /* Sum: '<S20>/AddX2' */
      bump_stim_B.AddX2_a = bump_stim_B.z_k + bump_stim_B.dZ_h;

      /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix Concatenation1InPort0' */
      tmp = bump_stim_B.Product1_b;
      tmp_0 = bump_stim_B.Product_c;
      bump_stim_B.MatrixConcatenation1[0] = tmp;
      bump_stim_B.MatrixConcatenation1[1] = tmp_0;

      /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix Concatenation1InPort1' */
      bump_stim_B.MatrixConcatenation1[2] = bump_stim_B.Switch[0];
      bump_stim_B.MatrixConcatenation1[3] = bump_stim_B.Switch[1];

      /* UnitDelay: '<S23>/y' */
      bump_stim_B.y_l = bump_stim_DWork.y_DSTATE_g;

      /* Sum: '<S23>/Add1' */
      bump_stim_B.Add1_n = bump_stim_B.y_l - bump_stim_B.x;

      /* UnitDelay: '<S23>/z' */
      bump_stim_B.z_o = bump_stim_DWork.z_DSTATE_p;

      /* Sum: '<S23>/Add3' incorporates:
       *  Constant: '<S23>/rho'
       */
      bump_stim_B.Add3_p = bump_stim_P.rho_Value_pi - bump_stim_B.z_o;

      /* Product: '<S23>/product2' */
      bump_stim_B.product2_ft = bump_stim_B.x * bump_stim_B.Add3_p;

      /* Sum: '<S23>/Add2' */
      bump_stim_B.Add2_i = bump_stim_B.product2_ft - bump_stim_B.y_l;

      /* Product: '<S23>/product3' incorporates:
       *  Constant: '<S23>/beta'
       */
      bump_stim_B.product3_a = bump_stim_B.z_o * bump_stim_P.beta_Value_g;

      /* Product: '<S23>/product4' */
      bump_stim_B.product4_b = bump_stim_B.y_l * bump_stim_B.x;

      /* Sum: '<S23>/Add4' */
      bump_stim_B.Add4_h = bump_stim_B.product4_b - bump_stim_B.product3_a;

      /* Product: '<S23>/product1' incorporates:
       *  Constant: '<S23>/sigma'
       */
      bump_stim_B.product1_g = bump_stim_B.Add1_n * bump_stim_P.sigma_Value_h;

      /* Product: '<S23>/dX' incorporates:
       *  Constant: '<S23>/timescale'
       */
      bump_stim_B.dX_k = bump_stim_P.timescale_Value_o * bump_stim_B.product1_g;

      /* Sum: '<S23>/AddX' */
      bump_stim_B.AddX_k = bump_stim_B.x + bump_stim_B.dX_k;

      /* Product: '<S23>/dY' incorporates:
       *  Constant: '<S23>/timescale'
       */
      bump_stim_B.dY_p = bump_stim_P.timescale_Value_o * bump_stim_B.Add2_i;

      /* Sum: '<S23>/AddX1' */
      bump_stim_B.AddX1_a = bump_stim_B.y_l + bump_stim_B.dY_p;

      /* Product: '<S23>/dZ' incorporates:
       *  Constant: '<S23>/timescale'
       */
      bump_stim_B.dZ_n = bump_stim_P.timescale_Value_o * bump_stim_B.Add4_h;

      /* Sum: '<S23>/AddX2' */
      bump_stim_B.AddX2_n = bump_stim_B.z_o + bump_stim_B.dZ_n;

      /* UnitDelay: '<S24>/y' */
      bump_stim_B.y_m = bump_stim_DWork.y_DSTATE_gv;

      /* Sum: '<S24>/Add1' */
      bump_stim_B.Add1_b = bump_stim_B.y_m - bump_stim_B.x_p;

      /* UnitDelay: '<S24>/z' */
      bump_stim_B.z_pl = bump_stim_DWork.z_DSTATE_h;

      /* Sum: '<S24>/Add3' incorporates:
       *  Constant: '<S24>/rho'
       */
      bump_stim_B.Add3_cz = bump_stim_P.rho_Value_l - bump_stim_B.z_pl;

      /* Product: '<S24>/product2' */
      bump_stim_B.product2_j = bump_stim_B.x_p * bump_stim_B.Add3_cz;

      /* Sum: '<S24>/Add2' */
      bump_stim_B.Add2_d = bump_stim_B.product2_j - bump_stim_B.y_m;

      /* Product: '<S24>/product3' incorporates:
       *  Constant: '<S24>/beta'
       */
      bump_stim_B.product3_m = bump_stim_B.z_pl * bump_stim_P.beta_Value_o;

      /* Product: '<S24>/product4' */
      bump_stim_B.product4_f = bump_stim_B.y_m * bump_stim_B.x_p;

      /* Sum: '<S24>/Add4' */
      bump_stim_B.Add4_c = bump_stim_B.product4_f - bump_stim_B.product3_m;

      /* Product: '<S24>/product1' incorporates:
       *  Constant: '<S24>/sigma'
       */
      bump_stim_B.product1_k = bump_stim_B.Add1_b * bump_stim_P.sigma_Value_d;

      /* Product: '<S24>/dX' incorporates:
       *  Constant: '<S24>/timescale'
       */
      bump_stim_B.dX_f = bump_stim_P.timescale_Value_p * bump_stim_B.product1_k;

      /* Sum: '<S24>/AddX' */
      bump_stim_B.AddX_p = bump_stim_B.x_p + bump_stim_B.dX_f;

      /* Product: '<S24>/dY' incorporates:
       *  Constant: '<S24>/timescale'
       */
      bump_stim_B.dY_h = bump_stim_P.timescale_Value_p * bump_stim_B.Add2_d;

      /* Sum: '<S24>/AddX1' */
      bump_stim_B.AddX1_p = bump_stim_B.y_m + bump_stim_B.dY_h;

      /* Product: '<S24>/dZ' incorporates:
       *  Constant: '<S24>/timescale'
       */
      bump_stim_B.dZ_nw = bump_stim_P.timescale_Value_p * bump_stim_B.Add4_c;

      /* Sum: '<S24>/AddX2' */
      bump_stim_B.AddX2_g = bump_stim_B.z_pl + bump_stim_B.dZ_nw;

      /* UnitDelay: '<S25>/y' */
      bump_stim_B.y_d = bump_stim_DWork.y_DSTATE_b;

      /* Sum: '<S25>/Add1' */
      bump_stim_B.Add1_p = bump_stim_B.y_d - bump_stim_B.x_b;

      /* UnitDelay: '<S25>/z' */
      bump_stim_B.z_m = bump_stim_DWork.z_DSTATE_n;

      /* Sum: '<S25>/Add3' incorporates:
       *  Constant: '<S25>/rho'
       */
      bump_stim_B.Add3_bv = bump_stim_P.rho_Value_m - bump_stim_B.z_m;

      /* Product: '<S25>/product2' */
      bump_stim_B.product2_e = bump_stim_B.x_b * bump_stim_B.Add3_bv;

      /* Sum: '<S25>/Add2' */
      bump_stim_B.Add2_dx = bump_stim_B.product2_e - bump_stim_B.y_d;

      /* Product: '<S25>/product3' incorporates:
       *  Constant: '<S25>/beta'
       */
      bump_stim_B.product3_au = bump_stim_B.z_m * bump_stim_P.beta_Value_gu;

      /* Product: '<S25>/product4' */
      bump_stim_B.product4_i = bump_stim_B.y_d * bump_stim_B.x_b;

      /* Sum: '<S25>/Add4' */
      bump_stim_B.Add4_a = bump_stim_B.product4_i - bump_stim_B.product3_au;

      /* Product: '<S25>/product1' incorporates:
       *  Constant: '<S25>/sigma'
       */
      bump_stim_B.product1_p = bump_stim_B.Add1_p * bump_stim_P.sigma_Value_dt;

      /* Product: '<S25>/dX' incorporates:
       *  Constant: '<S25>/timescale'
       */
      bump_stim_B.dX_kk = bump_stim_P.timescale_Value_b * bump_stim_B.product1_p;

      /* Sum: '<S25>/AddX' */
      bump_stim_B.AddX_e = bump_stim_B.x_b + bump_stim_B.dX_kk;

      /* Product: '<S25>/dY' incorporates:
       *  Constant: '<S25>/timescale'
       */
      bump_stim_B.dY_l = bump_stim_P.timescale_Value_b * bump_stim_B.Add2_dx;

      /* Sum: '<S25>/AddX1' */
      bump_stim_B.AddX1_e = bump_stim_B.y_d + bump_stim_B.dY_l;

      /* Product: '<S25>/dZ' incorporates:
       *  Constant: '<S25>/timescale'
       */
      bump_stim_B.dZ_m = bump_stim_P.timescale_Value_b * bump_stim_B.Add4_a;

      /* Sum: '<S25>/AddX2' */
      bump_stim_B.AddX2_c = bump_stim_B.z_m + bump_stim_B.dZ_m;

      /* UnitDelay: '<S26>/y' */
      bump_stim_B.y_e = bump_stim_DWork.y_DSTATE_m;

      /* Sum: '<S26>/Add1' */
      bump_stim_B.Add1_d = bump_stim_B.y_e - bump_stim_B.x_h;

      /* UnitDelay: '<S26>/z' */
      bump_stim_B.z_h = bump_stim_DWork.z_DSTATE_g;

      /* Sum: '<S26>/Add3' incorporates:
       *  Constant: '<S26>/rho'
       */
      bump_stim_B.Add3_l = bump_stim_P.rho_Value_i - bump_stim_B.z_h;

      /* Product: '<S26>/product2' */
      bump_stim_B.product2_iv = bump_stim_B.x_h * bump_stim_B.Add3_l;

      /* Sum: '<S26>/Add2' */
      bump_stim_B.Add2_j = bump_stim_B.product2_iv - bump_stim_B.y_e;

      /* Product: '<S26>/product3' incorporates:
       *  Constant: '<S26>/beta'
       */
      bump_stim_B.product3_n = bump_stim_B.z_h * bump_stim_P.beta_Value_c;

      /* Product: '<S26>/product4' */
      bump_stim_B.product4_n = bump_stim_B.y_e * bump_stim_B.x_h;

      /* Sum: '<S26>/Add4' */
      bump_stim_B.Add4_c0 = bump_stim_B.product4_n - bump_stim_B.product3_n;

      /* Product: '<S26>/product1' incorporates:
       *  Constant: '<S26>/sigma'
       */
      bump_stim_B.product1_gt = bump_stim_B.Add1_d * bump_stim_P.sigma_Value_l;

      /* Product: '<S26>/dX' incorporates:
       *  Constant: '<S26>/timescale'
       */
      bump_stim_B.dX_fv = bump_stim_P.timescale_Value_oi *
        bump_stim_B.product1_gt;

      /* Sum: '<S26>/AddX' */
      bump_stim_B.AddX_g = bump_stim_B.x_h + bump_stim_B.dX_fv;

      /* Product: '<S26>/dY' incorporates:
       *  Constant: '<S26>/timescale'
       */
      bump_stim_B.dY_d = bump_stim_P.timescale_Value_oi * bump_stim_B.Add2_j;

      /* Sum: '<S26>/AddX1' */
      bump_stim_B.AddX1_c = bump_stim_B.y_e + bump_stim_B.dY_d;

      /* Product: '<S26>/dZ' incorporates:
       *  Constant: '<S26>/timescale'
       */
      bump_stim_B.dZ_g = bump_stim_P.timescale_Value_oi * bump_stim_B.Add4_c0;

      /* Sum: '<S26>/AddX2' */
      bump_stim_B.AddX2_h = bump_stim_B.z_h + bump_stim_B.dZ_g;

      /* Sum: '<S8>/Add' */
      bump_stim_B.Add_o = bump_stim_B.BehaviorBS_o4[1] +
        bump_stim_B.BehaviorBS_o4[3];

      /* Sum: '<S8>/Add1' */
      bump_stim_B.Add1_a = bump_stim_B.BehaviorBS_o4[2] +
        bump_stim_B.BehaviorBS_o4[4];

      /* Gain: '<S8>/Gain' */
      bump_stim_B.Gain_i = bump_stim_P.Gain_Gain_p * bump_stim_B.Add_o;

      /* Gain: '<S8>/Gain1' */
      bump_stim_B.Gain1_n = bump_stim_P.Gain1_Gain_a * bump_stim_B.Add1_a;
    }
  }
}

/* Model update function */
void bump_stim_update(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S31>/Memory' */
    bump_stim_DWork.Memory_PreviousInput = bump_stim_B.LogicalOperator;

    /* Update for Memory: '<S4>/Memory' */
    bump_stim_DWork.Memory_PreviousInput_b = bump_stim_B.LogicalOperator1_l;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S67>/Derivative' */
    {
      real_T timeStampA = bump_stim_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = bump_stim_DWork.Derivative_RWORK.TimeStampB;
      real_T *lastBank = &bump_stim_DWork.Derivative_RWORK.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = bump_stim_rtM->Timing.t[0];
      *lastBank++ = bump_stim_B.DigitalFilter2;
    }

    /* Derivative Block: '<S68>/Derivative' */
    {
      real_T timeStampA = bump_stim_DWork.Derivative_RWORK_l.TimeStampA;
      real_T timeStampB = bump_stim_DWork.Derivative_RWORK_l.TimeStampB;
      real_T *lastBank = &bump_stim_DWork.Derivative_RWORK_l.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = bump_stim_rtM->Timing.t[0];
      *lastBank++ = bump_stim_B.DigitalFilter2_n;
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S43>/Memory' */
    bump_stim_DWork.Memory_PreviousInput_c = bump_stim_B.LogicalOperator_g;

    /* Update for Memory: '<S47>/Memory' */
    bump_stim_DWork.Memory_PreviousInput_g = bump_stim_B.LogicalOperator_j;

    /* Update for UnitDelay: '<S61>/Delay Input1' */
    bump_stim_DWork.DelayInput1_DSTATE = bump_stim_B.Compare_me;

    /* Update for Memory: '<S45>/Memory' */
    bump_stim_DWork.Memory_PreviousInput_bt = bump_stim_B.LogicalOperator_o;

    /* Update for UnitDelay: '<S46>/Delay Input1' */
    bump_stim_DWork.DelayInput1_DSTATE_a = bump_stim_B.Compare_g;

    /* Update for UnitDelay: '<S39>/Delay Input1' */
    bump_stim_DWork.DelayInput1_DSTATE_n = bump_stim_B.Compare_l;

    /* Update for Memory: '<S44>/Memory' */
    bump_stim_DWork.Memory_PreviousInput_n = bump_stim_B.LogicalOperator_f;

    /* Update for UnitDelay: '<S38>/Delay Input1' */
    bump_stim_DWork.DelayInput1_DSTATE_f = bump_stim_B.Compare_mv;

    /* Update for Memory: '<S42>/Memory' */
    bump_stim_DWork.Memory_PreviousInput_cq = bump_stim_B.Logic[0];

    /* Update for UnitDelay: '<S23>/x' */
    bump_stim_DWork.x_DSTATE = bump_stim_B.AddX_k;

    /* Update for UnitDelay: '<S24>/x' */
    bump_stim_DWork.x_DSTATE_a = bump_stim_B.AddX_p;

    /* Update for UnitDelay: '<S25>/x' */
    bump_stim_DWork.x_DSTATE_ab = bump_stim_B.AddX_e;

    /* Update for UnitDelay: '<S26>/x' */
    bump_stim_DWork.x_DSTATE_j = bump_stim_B.AddX_g;

    /* Update for UnitDelay: '<S17>/x' */
    bump_stim_DWork.x_DSTATE_g = bump_stim_B.AddX;

    /* Update for UnitDelay: '<S18>/x' */
    bump_stim_DWork.x_DSTATE_o = bump_stim_B.AddX_d;

    /* Update for UnitDelay: '<S19>/x' */
    bump_stim_DWork.x_DSTATE_c = bump_stim_B.AddX_b;

    /* Update for UnitDelay: '<S20>/x' */
    bump_stim_DWork.x_DSTATE_n = bump_stim_B.AddX_i;

    /* Level2 S-Function Block: '<Root>/Behavior BS' (mastercon_bs) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[11];
      sfcnUpdate(rts, 1);
      if (ssGetErrorStatus(rts) != NULL)
        return;
    }

    /* UniformRandomNumber Block: '<S6>/Uniform Random Number' */
    bump_stim_DWork.UniformRandomNumber_RWORK.NextOutput = rt_Urand((uint32_T *)
      &bump_stim_DWork.UniformRandomNumber_IWORK.RandSeed) *
      (bump_stim_P.UniformRandomNumber_Max - bump_stim_P.UniformRandomNumber_Min)
      + bump_stim_P.UniformRandomNumber_Min;
  }

  if (tid == 0) {
    /* Update for UnitDelay: '<S17>/y' */
    bump_stim_DWork.y_DSTATE = bump_stim_B.AddX1;

    /* Update for UnitDelay: '<S17>/z' */
    bump_stim_DWork.z_DSTATE = bump_stim_B.AddX2;

    /* Update for UnitDelay: '<S18>/y' */
    bump_stim_DWork.y_DSTATE_d = bump_stim_B.AddX1_f;

    /* Update for UnitDelay: '<S18>/z' */
    bump_stim_DWork.z_DSTATE_b = bump_stim_B.AddX2_b;

    /* Update for UnitDelay: '<S19>/y' */
    bump_stim_DWork.y_DSTATE_h = bump_stim_B.AddX1_h;

    /* Update for UnitDelay: '<S19>/z' */
    bump_stim_DWork.z_DSTATE_i = bump_stim_B.AddX2_bo;

    /* Update for UnitDelay: '<S20>/y' */
    bump_stim_DWork.y_DSTATE_o = bump_stim_B.AddX1_l;

    /* Update for UnitDelay: '<S20>/z' */
    bump_stim_DWork.z_DSTATE_c = bump_stim_B.AddX2_a;

    /* Update for UnitDelay: '<S23>/y' */
    bump_stim_DWork.y_DSTATE_g = bump_stim_B.AddX1_a;

    /* Update for UnitDelay: '<S23>/z' */
    bump_stim_DWork.z_DSTATE_p = bump_stim_B.AddX2_n;

    /* Update for UnitDelay: '<S24>/y' */
    bump_stim_DWork.y_DSTATE_gv = bump_stim_B.AddX1_p;

    /* Update for UnitDelay: '<S24>/z' */
    bump_stim_DWork.z_DSTATE_h = bump_stim_B.AddX2_g;

    /* Update for UnitDelay: '<S25>/y' */
    bump_stim_DWork.y_DSTATE_b = bump_stim_B.AddX1_e;

    /* Update for UnitDelay: '<S25>/z' */
    bump_stim_DWork.z_DSTATE_n = bump_stim_B.AddX2_c;

    /* Update for UnitDelay: '<S26>/y' */
    bump_stim_DWork.y_DSTATE_m = bump_stim_B.AddX1_c;

    /* Update for UnitDelay: '<S26>/z' */
    bump_stim_DWork.z_DSTATE_g = bump_stim_B.AddX2_h;
  }

  /* Update absolute time for base rate */
  if (tid == 0) {
    if (!(++bump_stim_rtM->Timing.clockTick0))
      ++bump_stim_rtM->Timing.clockTickH0;
    bump_stim_rtM->Timing.t[0] = bump_stim_rtM->Timing.clockTick0 *
      bump_stim_rtM->Timing.stepSize0 + bump_stim_rtM->Timing.clockTickH0 *
      bump_stim_rtM->Timing.stepSize0 * 4294967296.0;
  }

  if (tid == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++bump_stim_rtM->Timing.clockTick1))
      ++bump_stim_rtM->Timing.clockTickH1;
    bump_stim_rtM->Timing.t[1] = bump_stim_rtM->Timing.clockTick1 *
      bump_stim_rtM->Timing.stepSize1 + bump_stim_rtM->Timing.clockTickH1 *
      bump_stim_rtM->Timing.stepSize1 * 4294967296.0;
  }

  if (tid == 2) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    if (!(++bump_stim_rtM->Timing.clockTick2))
      ++bump_stim_rtM->Timing.clockTickH2;
    bump_stim_rtM->Timing.t[2] = bump_stim_rtM->Timing.clockTick2 *
      bump_stim_rtM->Timing.stepSize2 + bump_stim_rtM->Timing.clockTickH2 *
      bump_stim_rtM->Timing.stepSize2 * 4294967296.0;
  }
}

/* Model initialize function */
void bump_stim_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */
  /* initialize real-time model */
  (void) memset((char_T *)bump_stim_rtM,0,
                sizeof(rtModel_bump_stim));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&bump_stim_rtM->solverInfo,
                          &bump_stim_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&bump_stim_rtM->solverInfo, &rtmGetTPtr(bump_stim_rtM));
    rtsiSetStepSizePtr(&bump_stim_rtM->solverInfo,
                       &bump_stim_rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&bump_stim_rtM->solverInfo, (&rtmGetErrorStatus
      (bump_stim_rtM)));
    rtsiSetRTModelPtr(&bump_stim_rtM->solverInfo, bump_stim_rtM);
  }

  rtsiSetSimTimeStep(&bump_stim_rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&bump_stim_rtM->solverInfo,"FixedStepDiscrete");
  bump_stim_rtM->solverInfoPtr = (&bump_stim_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = bump_stim_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    bump_stim_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    bump_stim_rtM->Timing.sampleTimes = (&bump_stim_rtM->Timing.sampleTimesArray
      [0]);
    bump_stim_rtM->Timing.offsetTimes = (&bump_stim_rtM->Timing.offsetTimesArray
      [0]);

    /* task periods */
    bump_stim_rtM->Timing.sampleTimes[0] = (0.0);
    bump_stim_rtM->Timing.sampleTimes[1] = (0.001);
    bump_stim_rtM->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    bump_stim_rtM->Timing.offsetTimes[0] = (0.0);
    bump_stim_rtM->Timing.offsetTimes[1] = (0.0);
    bump_stim_rtM->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(bump_stim_rtM, &bump_stim_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = bump_stim_rtM->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = bump_stim_rtM->Timing.perTaskSampleHitsArray;
    bump_stim_rtM->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    bump_stim_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(bump_stim_rtM, -1);
  bump_stim_rtM->Timing.stepSize0 = 0.001;
  bump_stim_rtM->Timing.stepSize1 = 0.001;
  bump_stim_rtM->Timing.stepSize2 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    bump_stim_rtM->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(bump_stim_rtM->rtwLogInfo, 2);
    rtliSetLogMaxRows(bump_stim_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(bump_stim_rtM->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(bump_stim_rtM->rtwLogInfo, "rt_");
    rtliSetLogT(bump_stim_rtM->rtwLogInfo, "tout");
    rtliSetLogX(bump_stim_rtM->rtwLogInfo, "xout");
    rtliSetLogXFinal(bump_stim_rtM->rtwLogInfo, "");
    rtliSetSigLog(bump_stim_rtM->rtwLogInfo, "");

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
        2,
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
        2,
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
        "bump_stim/Velocity Calculation/Pos2VelX/Digital Filter2",
        "bump_stim/Velocity Calculation/Pos2VelX/Digital Filter",
        "bump_stim/Velocity Calculation/Pos2VelY/Digital Filter2",
        "bump_stim/Velocity Calculation/Pos2VelY/Digital Filter",
        "bump_stim/Force Generator/LorentzForce/Lorentz/x",
        "bump_stim/Force Generator/LorentzForce/Lorentz1/x",
        "bump_stim/Force Generator/LorentzForce/Lorentz2/x",
        "bump_stim/Force Generator/LorentzForce/Lorentz3/x",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz/x",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz1/x",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz2/x",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz3/x",
        "bump_stim/Behavior BS",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz/y",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz/z",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz1/y",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz1/z",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz2/y",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz2/z",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz3/y",
        "bump_stim/Catch Force Generator/LorentzForce/Lorentz3/z",
        "bump_stim/Force Generator/LorentzForce/Lorentz/y",
        "bump_stim/Force Generator/LorentzForce/Lorentz/z",
        "bump_stim/Force Generator/LorentzForce/Lorentz1/y",
        "bump_stim/Force Generator/LorentzForce/Lorentz1/z",
        "bump_stim/Force Generator/LorentzForce/Lorentz2/y",
        "bump_stim/Force Generator/LorentzForce/Lorentz2/z",
        "bump_stim/Force Generator/LorentzForce/Lorentz3/y",
        "bump_stim/Force Generator/LorentzForce/Lorentz3/z",
        "bump_stim/Recentering Subsystem/Timer/Detect Fall\nNonpositive/Delay Input1",
        "bump_stim/Recentering Subsystem/Start Moving/Delay Input1",
        "bump_stim/Recentering Subsystem/Falling Edge1/Delay Input1",
        "bump_stim/Recentering Subsystem/Falling Edge/Delay Input1" };

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

      rtliSetLogXSignalInfo(bump_stim_rtM->rtwLogInfo, &rt_LoggedStateSignalInfo);
    }

    {
      static void * rt_LoggedStateSignalPtrs[33];
      rt_LoggedStateSignalPtrs[0] = (void*)
        &bump_stim_DWork.DigitalFilter2_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[1] = (void*)
        &bump_stim_DWork.DigitalFilter_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[2] = (void*)
        &bump_stim_DWork.DigitalFilter2_FILT_STATES_c[0];
      rt_LoggedStateSignalPtrs[3] = (void*)
        &bump_stim_DWork.DigitalFilter_FILT_STATES_g[0];
      rt_LoggedStateSignalPtrs[4] = (void*)&bump_stim_DWork.x_DSTATE;
      rt_LoggedStateSignalPtrs[5] = (void*)&bump_stim_DWork.x_DSTATE_a;
      rt_LoggedStateSignalPtrs[6] = (void*)&bump_stim_DWork.x_DSTATE_ab;
      rt_LoggedStateSignalPtrs[7] = (void*)&bump_stim_DWork.x_DSTATE_j;
      rt_LoggedStateSignalPtrs[8] = (void*)&bump_stim_DWork.x_DSTATE_g;
      rt_LoggedStateSignalPtrs[9] = (void*)&bump_stim_DWork.x_DSTATE_o;
      rt_LoggedStateSignalPtrs[10] = (void*)&bump_stim_DWork.x_DSTATE_c;
      rt_LoggedStateSignalPtrs[11] = (void*)&bump_stim_DWork.x_DSTATE_n;
      rt_LoggedStateSignalPtrs[12] = (void*)&bump_stim_DWork.BehaviorBS_DSTATE[0];
      rt_LoggedStateSignalPtrs[13] = (void*)&bump_stim_DWork.y_DSTATE;
      rt_LoggedStateSignalPtrs[14] = (void*)&bump_stim_DWork.z_DSTATE;
      rt_LoggedStateSignalPtrs[15] = (void*)&bump_stim_DWork.y_DSTATE_d;
      rt_LoggedStateSignalPtrs[16] = (void*)&bump_stim_DWork.z_DSTATE_b;
      rt_LoggedStateSignalPtrs[17] = (void*)&bump_stim_DWork.y_DSTATE_h;
      rt_LoggedStateSignalPtrs[18] = (void*)&bump_stim_DWork.z_DSTATE_i;
      rt_LoggedStateSignalPtrs[19] = (void*)&bump_stim_DWork.y_DSTATE_o;
      rt_LoggedStateSignalPtrs[20] = (void*)&bump_stim_DWork.z_DSTATE_c;
      rt_LoggedStateSignalPtrs[21] = (void*)&bump_stim_DWork.y_DSTATE_g;
      rt_LoggedStateSignalPtrs[22] = (void*)&bump_stim_DWork.z_DSTATE_p;
      rt_LoggedStateSignalPtrs[23] = (void*)&bump_stim_DWork.y_DSTATE_gv;
      rt_LoggedStateSignalPtrs[24] = (void*)&bump_stim_DWork.z_DSTATE_h;
      rt_LoggedStateSignalPtrs[25] = (void*)&bump_stim_DWork.y_DSTATE_b;
      rt_LoggedStateSignalPtrs[26] = (void*)&bump_stim_DWork.z_DSTATE_n;
      rt_LoggedStateSignalPtrs[27] = (void*)&bump_stim_DWork.y_DSTATE_m;
      rt_LoggedStateSignalPtrs[28] = (void*)&bump_stim_DWork.z_DSTATE_g;
      rt_LoggedStateSignalPtrs[29] = (void*)&bump_stim_DWork.DelayInput1_DSTATE;
      rt_LoggedStateSignalPtrs[30] = (void*)
        &bump_stim_DWork.DelayInput1_DSTATE_a;
      rt_LoggedStateSignalPtrs[31] = (void*)
        &bump_stim_DWork.DelayInput1_DSTATE_n;
      rt_LoggedStateSignalPtrs[32] = (void*)
        &bump_stim_DWork.DelayInput1_DSTATE_f;
      rtliSetLogXSignalPtrs(bump_stim_rtM->rtwLogInfo, (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
    }

    rtliSetLogY(bump_stim_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(bump_stim_rtM->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(bump_stim_rtM->rtwLogInfo, NULL);
  }

  /* external mode info */
  bump_stim_rtM->Sizes.checksums[0] = (1738243979U);
  bump_stim_rtM->Sizes.checksums[1] = (4268189314U);
  bump_stim_rtM->Sizes.checksums[2] = (1059711355U);
  bump_stim_rtM->Sizes.checksums[3] = (2506017364U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[34];
    bump_stim_rtM->extModeInfo = (&rt_ExtModeInfo);
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
      &bump_stim_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &bump_stim_DWork.EnabledSubsystem_c.EnabledSubsystem_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &bump_stim_DWork.EnabledSubsystem_f.EnabledSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &bump_stim_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &bump_stim_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)
      &bump_stim_DWork.SampleandHold_a.SampleandHold_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &bump_stim_DWork.SampleandHold.SampleandHold_SubsysRanBC;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &bump_stim_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, bump_stim_rtM->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(bump_stim_rtM));
  }

  bump_stim_rtM->solverInfoPtr = (&bump_stim_rtM->solverInfo);
  bump_stim_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&bump_stim_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&bump_stim_rtM->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  bump_stim_rtM->ModelData.blockIO = ((void *) &bump_stim_B);
  (void) memset(((void *) &bump_stim_B),0,
                sizeof(BlockIO_bump_stim));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&bump_stim_B.Clock);
    for (i = 0; i < 241; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&bump_stim_B.ForIterator);
    for (i = 0; i < 90; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    ((real_T*)&bump_stim_B.SampleandHold.In)[0] = 0.0;
    ((real_T*)&bump_stim_B.SampleandHold_a.In)[0] = 0.0;
    ((real_T*)&bump_stim_B.EnabledSubsystem_l.In1)[0] = 0.0;
    ((real_T*)&bump_stim_B.EnabledSubsystem_o.In1)[0] = 0.0;
    ((real_T*)&bump_stim_B.EnabledSubsystem_f.In1)[0] = 0.0;
    ((real_T*)&bump_stim_B.EnabledSubsystem_c.In1)[0] = 0.0;
    ((real_T*)&bump_stim_B.EnabledSubsystem.In1)[0] = 0.0;
  }

  /* parameters */
  bump_stim_rtM->ModelData.defaultParam = ((real_T *) &bump_stim_P);

  /* states (dwork) */
  bump_stim_rtM->Work.dwork = ((void *) &bump_stim_DWork);
  (void) memset((char_T *) &bump_stim_DWork,0,
                sizeof(D_Work_bump_stim));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &bump_stim_DWork.DigitalFilter2_FILT_STATES[0];
    for (i = 0; i < 155; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    bump_stim_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    bump_stim_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  bump_stim_InitializeDataMapInfo(bump_stim_rtM);

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &bump_stim_rtM->NonInlinedSFcns.sfcnInfo;
    bump_stim_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(bump_stim_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &bump_stim_rtM->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(bump_stim_rtM));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(bump_stim_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(bump_stim_rtM));
    rtssSetStepSizePtr(sfcnInfo, &bump_stim_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(bump_stim_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &bump_stim_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &bump_stim_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &bump_stim_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &bump_stim_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &bump_stim_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &bump_stim_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &bump_stim_rtM->solverInfoPtr);
  }

  bump_stim_rtM->Sizes.numSFcns = (14);

  /* register each child */
  {
    (void) memset((void *)&bump_stim_rtM->NonInlinedSFcns.childSFunctions[0],0,
                  14*sizeof(SimStruct));
    bump_stim_rtM->childSfunctions =
      (&bump_stim_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 14; i++) {
        bump_stim_rtM->childSfunctions[i] =
          (&bump_stim_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: bump_stim/<S72>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_stim_B.xPCTargetTime_c));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "bump_stim/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,bump_stim_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_stim_P.xPCTargetTime_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_stim_P.xPCTargetTime_P2_Size[0]);
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

    /* Level2 S-Function Block: bump_stim/<S72>/PCI-6025E  (donipcie) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &bump_stim_B.Switch_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &bump_stim_B.DataTypeConversion;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts,
                "bump_stim/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ");
      ssSetRTModel(rts,bump_stim_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_stim_P.PCI6025E_P1_Size_m[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_stim_P.PCI6025E_P2_Size_d[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_stim_P.PCI6025E_P3_Size_m[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_stim_P.PCI6025E_P4_Size_k[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_stim_P.PCI6025E_P5_Size_i[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_stim_P.PCI6025E_P6_Size_m[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_stim_P.PCI6025E_P7_Size_p[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_stim_DWork.PCI6025E_IWORK_m[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn1.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_stim_DWork.PCI6025E_IWORK_m[0]);
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

    /* Level2 S-Function Block: bump_stim/<S70>/ToBits1 (Byte2Bits) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &bump_stim_B.Switch_e;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_stim_B.ToBits1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &bump_stim_B.ToBits1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &bump_stim_B.ToBits1_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &bump_stim_B.ToBits1_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &bump_stim_B.ToBits1_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &bump_stim_B.ToBits1_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &bump_stim_B.ToBits1_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &bump_stim_B.ToBits1_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits1");
      ssSetPath(rts,
                "bump_stim/XY Position Subsystem/For Iterator Subsystem/ToBits1");
      ssSetRTModel(rts,bump_stim_rtM);
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

    /* Level2 S-Function Block: bump_stim/<S70>/Port A (dopci8255) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &bump_stim_B.ToBits1_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &bump_stim_B.ToBits1_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn3.UPtrs2;
          sfcnUPtrs[0] = &bump_stim_B.ToBits1_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn3.UPtrs3;
          sfcnUPtrs[0] = &bump_stim_B.ToBits1_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn3.UPtrs4;
          sfcnUPtrs[0] = &bump_stim_B.ToBits1_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn3.UPtrs5;
          sfcnUPtrs[0] = &bump_stim_B.ToBits1_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn3.UPtrs6;
          sfcnUPtrs[0] = &bump_stim_B.ToBits1_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn3.UPtrs7;
          sfcnUPtrs[0] = &bump_stim_B.ToBits1_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port A");
      ssSetPath(rts,
                "bump_stim/XY Position Subsystem/For Iterator Subsystem/Port A");
      ssSetRTModel(rts,bump_stim_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_stim_P.PortA_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_stim_P.PortA_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_stim_P.PortA_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_stim_P.PortA_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_stim_P.PortA_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_stim_P.PortA_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_stim_P.PortA_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&bump_stim_P.PortA_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&bump_stim_P.PortA_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_stim_DWork.PortA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn3.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_stim_DWork.PortA_IWORK[0]);
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

    /* Level2 S-Function Block: bump_stim/<S70>/SerialConverter (serPos) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &bump_stim_B.ForIterator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &bump_stim_B.Add_p;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn4.UPtrs2;
          sfcnUPtrs[0] = &bump_stim_B.Add1_j;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_stim_B.SerialConverter));
        }
      }

      /* path info */
      ssSetModelName(rts, "SerialConverter");
      ssSetPath(rts,
                "bump_stim/XY Position Subsystem/For Iterator Subsystem/SerialConverter");
      ssSetRTModel(rts,bump_stim_rtM);
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

    /* Level2 S-Function Block: bump_stim/<S70>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[5]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &bump_stim_B.SerialConverter;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_stim_B.ToBits_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &bump_stim_B.ToBits_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &bump_stim_B.ToBits_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &bump_stim_B.ToBits_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &bump_stim_B.ToBits_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &bump_stim_B.ToBits_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &bump_stim_B.ToBits_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &bump_stim_B.ToBits_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts,
                "bump_stim/XY Position Subsystem/For Iterator Subsystem/ToBits");
      ssSetRTModel(rts,bump_stim_rtM);
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

    /* Level2 S-Function Block: bump_stim/<S70>/Port B (dopci8255) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[6]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &bump_stim_B.ToBits_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &bump_stim_B.ToBits_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn6.UPtrs2;
          sfcnUPtrs[0] = &bump_stim_B.ToBits_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn6.UPtrs3;
          sfcnUPtrs[0] = &bump_stim_B.ToBits_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn6.UPtrs4;
          sfcnUPtrs[0] = &bump_stim_B.ToBits_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn6.UPtrs5;
          sfcnUPtrs[0] = &bump_stim_B.ToBits_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn6.UPtrs6;
          sfcnUPtrs[0] = &bump_stim_B.ToBits_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn6.UPtrs7;
          sfcnUPtrs[0] = &bump_stim_B.ToBits_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port B");
      ssSetPath(rts,
                "bump_stim/XY Position Subsystem/For Iterator Subsystem/Port B");
      ssSetRTModel(rts,bump_stim_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_stim_P.PortB_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_stim_P.PortB_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_stim_P.PortB_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_stim_P.PortB_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_stim_P.PortB_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_stim_P.PortB_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_stim_P.PortB_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&bump_stim_P.PortB_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&bump_stim_P.PortB_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_stim_DWork.PortB_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn6.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_stim_DWork.PortB_IWORK[0]);
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

    /* Level2 S-Function Block: bump_stim/<S70>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[7]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_stim_B.xPCTargetTime));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "bump_stim/XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,bump_stim_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_stim_P.xPCTargetTime_P1_Size_h[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_stim_P.xPCTargetTime_P2_Size_b[0]);
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

    /* Level2 S-Function Block: bump_stim/<S13>/PCI-QUAD04  (enccbcioquadcount) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[8]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_stim_B.PCIQUAD04));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 ");
      ssSetPath(rts, "bump_stim/XY Position Subsystem/PCI-QUAD04 ");
      ssSetRTModel(rts,bump_stim_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_stim_P.PCIQUAD04_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_stim_P.PCIQUAD04_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_stim_P.PCIQUAD04_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_stim_P.PCIQUAD04_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_stim_P.PCIQUAD04_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_stim_P.PCIQUAD04_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_stim_P.PCIQUAD04_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&bump_stim_P.PCIQUAD04_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&bump_stim_P.PCIQUAD04_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&bump_stim_P.PCIQUAD04_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&bump_stim_P.PCIQUAD04_P11_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_stim_DWork.PCIQUAD04_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn8.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_stim_DWork.PCIQUAD04_IWORK);
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

    /* Level2 S-Function Block: bump_stim/<S13>/PCI-QUAD04 1 (enccbcioquadcount) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[9]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_stim_B.PCIQUAD041));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 1");
      ssSetPath(rts, "bump_stim/XY Position Subsystem/PCI-QUAD04 1");
      ssSetRTModel(rts,bump_stim_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_stim_P.PCIQUAD041_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_stim_P.PCIQUAD041_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_stim_P.PCIQUAD041_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_stim_P.PCIQUAD041_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_stim_P.PCIQUAD041_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_stim_P.PCIQUAD041_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_stim_P.PCIQUAD041_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&bump_stim_P.PCIQUAD041_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&bump_stim_P.PCIQUAD041_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&bump_stim_P.PCIQUAD041_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&bump_stim_P.PCIQUAD041_P11_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_stim_DWork.PCIQUAD041_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn9.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_stim_DWork.PCIQUAD041_IWORK);
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

    /* Level2 S-Function Block: bump_stim/<S10>/PCI-6025E AD (adnipcie) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[10]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[10]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_stim_B.PCI6025EAD_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &bump_stim_B.PCI6025EAD_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E AD");
      ssSetPath(rts, "bump_stim/Velocity Calculation/PCI-6025E AD");
      ssSetRTModel(rts,bump_stim_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_stim_P.PCI6025EAD_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_stim_P.PCI6025EAD_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_stim_P.PCI6025EAD_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_stim_P.PCI6025EAD_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_stim_P.PCI6025EAD_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_stim_P.PCI6025EAD_P6_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &bump_stim_DWork.PCI6025EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &bump_stim_DWork.PCI6025EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn10.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_stim_DWork.PCI6025EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &bump_stim_DWork.PCI6025EAD_IWORK[0]);
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

    /* Level2 S-Function Block: bump_stim/<Root>/Behavior BS (mastercon_bs) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[11]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn11.UPtrs0;
          sfcnUPtrs[0] = &bump_stim_B.Product1_b;
          sfcnUPtrs[1] = &bump_stim_B.Product_c;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn11.UPtrs1;
          sfcnUPtrs[0] = bump_stim_B.MultiportSwitch;
          sfcnUPtrs[1] = &bump_stim_B.MultiportSwitch[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn11.UPtrs2;
          sfcnUPtrs[0] = bump_stim_B.LoadSelectSwitch;
          sfcnUPtrs[1] = &bump_stim_B.LoadSelectSwitch[1];
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) bump_stim_B.BehaviorBS_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 5);
          ssSetOutputPortSignal(rts, 1, ((real_T *) bump_stim_B.BehaviorBS_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &bump_stim_B.BehaviorBS_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 10);
          ssSetOutputPortSignal(rts, 3, ((real_T *) bump_stim_B.BehaviorBS_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &bump_stim_B.BehaviorBS_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 2);
          ssSetOutputPortSignal(rts, 5, ((real_T *) bump_stim_B.BehaviorBS_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 4);
          ssSetOutputPortSignal(rts, 6, ((real_T *) bump_stim_B.BehaviorBS_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 2);
          ssSetOutputPortSignal(rts, 7, ((real_T *) bump_stim_B.BehaviorBS_o8));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *) &bump_stim_DWork.BehaviorBS_DSTATE[0]);

      /* path info */
      ssSetModelName(rts, "Behavior BS");
      ssSetPath(rts, "bump_stim/Behavior BS");
      ssSetRTModel(rts,bump_stim_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 23);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_stim_P.BehaviorBS_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_stim_P.BehaviorBS_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_stim_P.BehaviorBS_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_stim_P.BehaviorBS_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_stim_P.BehaviorBS_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_stim_P.BehaviorBS_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_stim_P.BehaviorBS_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&bump_stim_P.BehaviorBS_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&bump_stim_P.BehaviorBS_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&bump_stim_P.BehaviorBS_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&bump_stim_P.BehaviorBS_P11_Size[0]);
        ssSetSFcnParam(rts, 11, (mxArray*)&bump_stim_P.BehaviorBS_P12_Size[0]);
        ssSetSFcnParam(rts, 12, (mxArray*)&bump_stim_P.BehaviorBS_P13_Size[0]);
        ssSetSFcnParam(rts, 13, (mxArray*)&bump_stim_P.BehaviorBS_P14_Size[0]);
        ssSetSFcnParam(rts, 14, (mxArray*)&bump_stim_P.BehaviorBS_P15_Size[0]);
        ssSetSFcnParam(rts, 15, (mxArray*)&bump_stim_P.BehaviorBS_P16_Size[0]);
        ssSetSFcnParam(rts, 16, (mxArray*)&bump_stim_P.BehaviorBS_P17_Size[0]);
        ssSetSFcnParam(rts, 17, (mxArray*)&bump_stim_P.BehaviorBS_P18_Size[0]);
        ssSetSFcnParam(rts, 18, (mxArray*)&bump_stim_P.BehaviorBS_P19_Size[0]);
        ssSetSFcnParam(rts, 19, (mxArray*)&bump_stim_P.BehaviorBS_P20_Size[0]);
        ssSetSFcnParam(rts, 20, (mxArray*)&bump_stim_P.BehaviorBS_P21_Size[0]);
        ssSetSFcnParam(rts, 21, (mxArray*)&bump_stim_P.BehaviorBS_P22_Size[0]);
        ssSetSFcnParam(rts, 22, (mxArray*)&bump_stim_P.BehaviorBS_P23_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &bump_stim_DWork.BehaviorBS_RWORK[0]);
      ssSetIWork(rts, (int_T *) &bump_stim_DWork.BehaviorBS_IWORK[0]);
      ssSetPWork(rts, (void **) &bump_stim_DWork.BehaviorBS_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn11.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 4);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_stim_DWork.BehaviorBS_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 75);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &bump_stim_DWork.BehaviorBS_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 2, 1);
        ssSetDWorkDataType(rts, 2,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &bump_stim_DWork.BehaviorBS_PWORK);

        /* DSTATE */
        ssSetDWorkWidth(rts, 3, 2);
        ssSetDWorkDataType(rts, 3,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWorkUsedAsDState(rts, 3, 1);
        ssSetDWork(rts, 3, &bump_stim_DWork.BehaviorBS_DSTATE[0]);
      }

      /* registration */
      mastercon_bs(rts);
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

    /* Level2 S-Function Block: bump_stim/<S4>/PCI-6025E  (danipcie) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[12]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[12]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn12.UPtrs0;
          sfcnUPtrs[0] = &bump_stim_B.MG1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_stim_rtM->NonInlinedSFcns.Sfcn12.UPtrs1;
          sfcnUPtrs[0] = &bump_stim_B.MG2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts, "bump_stim/Motor Control/PCI-6025E ");
      ssSetRTModel(rts,bump_stim_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_stim_P.PCI6025E_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_stim_P.PCI6025E_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_stim_P.PCI6025E_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_stim_P.PCI6025E_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_stim_P.PCI6025E_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_stim_P.PCI6025E_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_stim_P.PCI6025E_P7_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &bump_stim_DWork.PCI6025E_RWORK[0]);
      ssSetIWork(rts, (int_T *) &bump_stim_DWork.PCI6025E_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn12.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_stim_DWork.PCI6025E_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &bump_stim_DWork.PCI6025E_IWORK[0]);
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

    /* Level2 S-Function Block: bump_stim/<S9>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = bump_stim_rtM->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = bump_stim_rtM->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = bump_stim_rtM->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = bump_stim_rtM->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_stim_rtM->NonInlinedSFcns.blkInfo2[13]);
        ssSetRTWSfcnInfo(rts, bump_stim_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_stim_rtM->NonInlinedSFcns.methods2[13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &bump_stim_rtM->NonInlinedSFcns.Sfcn13.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, bump_stim_B.RateTransition);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 112);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "bump_stim/UDPXmit/Send");
      ssSetRTModel(rts,bump_stim_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_stim_P.Send_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_stim_P.Send_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_stim_P.Send_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_stim_P.Send_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_stim_DWork.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &bump_stim_DWork.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_stim_rtM->NonInlinedSFcns.Sfcn13.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_stim_DWork.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &bump_stim_DWork.Send_PWORK);
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

  bump_stim_PrevZCSigState.SampleandHold.SampleandHold_ZCE = UNINITIALIZED_ZCSIG;
  bump_stim_PrevZCSigState.SampleandHold_a.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void bump_stim_terminate(void)
{
  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Behavior BS' (mastercon_bs) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S13>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S70>/ToBits1' (Byte2Bits) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/SerialConverter' (serPos) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S70>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S72>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[1];
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
  bump_stim_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  bump_stim_update(tid);
}

void MdlInitializeSizes(void)
{
  bump_stim_rtM->Sizes.numContStates = (0);/* Number of continuous states */
  bump_stim_rtM->Sizes.numY = (0);     /* Number of model outputs */
  bump_stim_rtM->Sizes.numU = (0);     /* Number of model inputs */
  bump_stim_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  bump_stim_rtM->Sizes.numSampTimes = (3);/* Number of sample times */
  bump_stim_rtM->Sizes.numBlocks = (480);/* Number of blocks */
  bump_stim_rtM->Sizes.numBlockIO = (375);/* Number of block outputs */
  bump_stim_rtM->Sizes.numBlockPrms = (550);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Memory: '<S31>/Memory' */
  bump_stim_DWork.Memory_PreviousInput = bump_stim_P.Memory_X0;

  /* InitializeConditions for Memory: '<S4>/Memory' */
  bump_stim_DWork.Memory_PreviousInput_b = bump_stim_P.Memory_X0_n;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &bump_stim_DWork.DigitalFilter2_FILT_STATES[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&bump_stim_P.DigitalFilter2_ICRTP;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S67>/Derivative' */
  bump_stim_DWork.Derivative_RWORK.TimeStampA = rtInf;
  bump_stim_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &bump_stim_DWork.DigitalFilter_FILT_STATES[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&bump_stim_P.DigitalFilter_ICRTP;
    }

    *statePtr++ = 0.0;
  }

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &bump_stim_DWork.DigitalFilter2_FILT_STATES_c
      [0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&bump_stim_P.DigitalFilter2_ICRTP_e;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S68>/Derivative' */
  bump_stim_DWork.Derivative_RWORK_l.TimeStampA = rtInf;
  bump_stim_DWork.Derivative_RWORK_l.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &bump_stim_DWork.DigitalFilter_FILT_STATES_g[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&bump_stim_P.DigitalFilter_ICRTP_l;
    }

    *statePtr++ = 0.0;
  }

  /* InitializeConditions for Memory: '<S43>/Memory' */
  bump_stim_DWork.Memory_PreviousInput_c = bump_stim_P.Memory_X0_l;

  /* InitializeConditions for Memory: '<S47>/Memory' */
  bump_stim_DWork.Memory_PreviousInput_g = bump_stim_P.Memory_X0_h;

  /* InitializeConditions for UnitDelay: '<S61>/Delay Input1' */
  bump_stim_DWork.DelayInput1_DSTATE = bump_stim_P.DelayInput1_X0;

  /* InitializeConditions for Memory: '<S45>/Memory' */
  bump_stim_DWork.Memory_PreviousInput_bt = bump_stim_P.Memory_X0_ll;

  /* InitializeConditions for UnitDelay: '<S46>/Delay Input1' */
  bump_stim_DWork.DelayInput1_DSTATE_a = bump_stim_P.DelayInput1_X0_f;

  /* InitializeConditions for UnitDelay: '<S39>/Delay Input1' */
  bump_stim_DWork.DelayInput1_DSTATE_n = bump_stim_P.DelayInput1_X0_c;

  /* InitializeConditions for Memory: '<S44>/Memory' */
  bump_stim_DWork.Memory_PreviousInput_n = bump_stim_P.Memory_X0_nn;

  /* InitializeConditions for UnitDelay: '<S38>/Delay Input1' */
  bump_stim_DWork.DelayInput1_DSTATE_f = bump_stim_P.DelayInput1_X0_fl;

  /* InitializeConditions for Memory: '<S42>/Memory' */
  bump_stim_DWork.Memory_PreviousInput_cq = bump_stim_P.Memory_X0_nr;

  /* InitializeConditions for UnitDelay: '<S23>/x' */
  bump_stim_DWork.x_DSTATE = bump_stim_P.x_X0;

  /* InitializeConditions for UnitDelay: '<S24>/x' */
  bump_stim_DWork.x_DSTATE_a = bump_stim_P.x_X0_c;

  /* InitializeConditions for UnitDelay: '<S25>/x' */
  bump_stim_DWork.x_DSTATE_ab = bump_stim_P.x_X0_p;

  /* InitializeConditions for UnitDelay: '<S26>/x' */
  bump_stim_DWork.x_DSTATE_j = bump_stim_P.x_X0_i;

  /* InitializeConditions for UnitDelay: '<S17>/x' */
  bump_stim_DWork.x_DSTATE_g = bump_stim_P.x_X0_b;

  /* InitializeConditions for UnitDelay: '<S18>/x' */
  bump_stim_DWork.x_DSTATE_o = bump_stim_P.x_X0_d;

  /* InitializeConditions for UnitDelay: '<S19>/x' */
  bump_stim_DWork.x_DSTATE_c = bump_stim_P.x_X0_e;

  /* InitializeConditions for UnitDelay: '<S20>/x' */
  bump_stim_DWork.x_DSTATE_n = bump_stim_P.x_X0_m;

  /* Level2 S-Function Block: '<Root>/Behavior BS' (mastercon_bs) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[11];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* InitializeConditions for UnitDelay: '<S17>/y' */
  bump_stim_DWork.y_DSTATE = bump_stim_P.y_X0;

  /* InitializeConditions for UnitDelay: '<S17>/z' */
  bump_stim_DWork.z_DSTATE = bump_stim_P.z_X0;

  /* InitializeConditions for UnitDelay: '<S18>/y' */
  bump_stim_DWork.y_DSTATE_d = bump_stim_P.y_X0_d;

  /* InitializeConditions for UnitDelay: '<S18>/z' */
  bump_stim_DWork.z_DSTATE_b = bump_stim_P.z_X0_k;

  /* InitializeConditions for UnitDelay: '<S19>/y' */
  bump_stim_DWork.y_DSTATE_h = bump_stim_P.y_X0_p;

  /* InitializeConditions for UnitDelay: '<S19>/z' */
  bump_stim_DWork.z_DSTATE_i = bump_stim_P.z_X0_kn;

  /* InitializeConditions for UnitDelay: '<S20>/y' */
  bump_stim_DWork.y_DSTATE_o = bump_stim_P.y_X0_h;

  /* InitializeConditions for UnitDelay: '<S20>/z' */
  bump_stim_DWork.z_DSTATE_c = bump_stim_P.z_X0_g;

  /* InitializeConditions for UnitDelay: '<S23>/y' */
  bump_stim_DWork.y_DSTATE_g = bump_stim_P.y_X0_g;

  /* InitializeConditions for UnitDelay: '<S23>/z' */
  bump_stim_DWork.z_DSTATE_p = bump_stim_P.z_X0_h;

  /* InitializeConditions for UnitDelay: '<S24>/y' */
  bump_stim_DWork.y_DSTATE_gv = bump_stim_P.y_X0_k;

  /* InitializeConditions for UnitDelay: '<S24>/z' */
  bump_stim_DWork.z_DSTATE_h = bump_stim_P.z_X0_j;

  /* InitializeConditions for UnitDelay: '<S25>/y' */
  bump_stim_DWork.y_DSTATE_b = bump_stim_P.y_X0_f;

  /* InitializeConditions for UnitDelay: '<S25>/z' */
  bump_stim_DWork.z_DSTATE_n = bump_stim_P.z_X0_l;

  /* InitializeConditions for UnitDelay: '<S26>/y' */
  bump_stim_DWork.y_DSTATE_m = bump_stim_P.y_X0_e;

  /* InitializeConditions for UnitDelay: '<S26>/z' */
  bump_stim_DWork.z_DSTATE_g = bump_stim_P.z_X0_o;
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[12];
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
        xpceScopeAcqOK(2, &bump_stim_DWork.SFunction_IWORK.AcquireOK);
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
        xpceScopeAcqOK(6, &bump_stim_DWork.SFunction_IWORK_g.AcquireOK);
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
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BS/p2/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BS/p2/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BS/p2/s3"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BS/p2/s4"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BS/p2/s5"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BS/p2/s1"),
          "%6.0f state");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BS/p2/s2"),
          "%6.0f rewards");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BS/p2/s3"),
          "%6.0f aborts");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BS/p2/s4"),
          "%6.0f fails");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BS/p2/s5"),
          "%6.0f incompl");
        rl32eSetScope(3, 4, 10);
        rl32eSetScope(3, 40, 0);
        rl32eSetScope(3, 7, 10);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Behavior BS/p2/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 10, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, -10.0);
        rl32eSetTargetScope(3, 10, 10.0);
        xpceScopeAcqOK(3, &bump_stim_DWork.SFunction_IWORK_c.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[13];
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
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior BS/p7/s1"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior BS/p7/s2"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior BS/p7/s3"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior BS/p7/s4"));
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior BS/p7/s1"),
          "%6.0f major");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior BS/p7/s2"),
          "%6.0f minor");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior BS/p7/s3"),
          "%6.0f revision");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior BS/p7/s4"),
          "%6.0f build");
        rl32eSetScope(7, 4, 10);
        rl32eSetScope(7, 40, 0);
        rl32eSetScope(7, 7, 10);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("Behavior BS/p7/s1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 10, 0);
        rl32eSetTargetScope(7, 1, 0.0);
        rl32eSetTargetScope(7, 11, -10.0);
        rl32eSetTargetScope(7, 10, 10.0);
        xpceScopeAcqOK(7, &bump_stim_DWork.SFunction_IWORK_d.AcquireOK);
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
        xpceScopeAcqOK(1, &bump_stim_DWork.SFunction_IWORK_m.AcquireOK);
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
        xpceScopeAcqOK(5, &bump_stim_DWork.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /*trigger Subsystem Block: '<S65>/Sample and Hold' */
  bump_stim_SampleandHold_Start(&bump_stim_B.SampleandHold,
    (rtP_SampleandHold_bump_stim *) &bump_stim_P.SampleandHold);

  /* UniformRandomNumber Block: '<S6>/Uniform Random Number' */
  {
    uint32_T *RandSeed = (uint32_T *)
      &bump_stim_DWork.UniformRandomNumber_IWORK.RandSeed;
    uint32_T r, t;
    *RandSeed = (uint32_T)bump_stim_P.UniformRandomNumber_Seed;
    r = *RandSeed >> 16;
    t = *RandSeed & RT_BIT16;
    *RandSeed = ((*RandSeed - (r << 16) - t) << 16) + t + r;
    if (*RandSeed < 1) {
      *RandSeed = SEED0;
    }

    if (*RandSeed > MAXSEED) {
      *RandSeed = MAXSEED;
    }

    bump_stim_DWork.UniformRandomNumber_RWORK.NextOutput
      = rt_Urand(RandSeed++) * (bump_stim_P.UniformRandomNumber_Max -
      bump_stim_P.UniformRandomNumber_Min) + bump_stim_P.UniformRandomNumber_Min;
  }

  /*trigger Subsystem Block: '<S6>/Sample and Hold' */
  bump_stim_SampleandHold_Start(&bump_stim_B.SampleandHold_a,
    (rtP_SampleandHold_bump_stim *) &bump_stim_P.SampleandHold_a);

  /* Start for iterator system: '<S13>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Start for iterator system: '<S70>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = bump_stim_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  bump_stim_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_stim_DWork.EnabledSubsystem_c.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_stim_DWork.EnabledSubsystem_f.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_stim_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_stim_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_stim_DWork.SampleandHold_a.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_stim_DWork.SampleandHold.SampleandHold_SubsysRanBC =
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

rtModel_bump_stim *bump_stim(void)
{
  bump_stim_initialize(1);
  return bump_stim_rtM;
}

void MdlTerminate(void)
{
  bump_stim_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
