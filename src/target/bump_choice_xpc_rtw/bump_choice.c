/*
 * bump_choice.c
 *
 * Real-Time Workshop code generation for Simulink model "bump_choice.mdl".
 *
 * Model Version              : 1.1230
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:43:36 2010
 */

#include "rt_logging_mmi.h"
#include "bump_choice_capi.h"
#include "bump_choice.h"
#include "bump_choice_private.h"
#include <stdio.h>
#include "bump_choice_dt.h"

/* Block signals (auto storage) */
BlockIO_bump_choice bump_choice_B;

/* Block states (auto storage) */
D_Work_bump_choice bump_choice_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_bump_choice bump_choice_PrevZCSigState;

/* Real-time model */
rtModel_bump_choice bump_choice_rtM_;
rtModel_bump_choice *bump_choice_rtM = &bump_choice_rtM_;
static void rate_monotonic_scheduler(void);

/* Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void bump_choice_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(bump_choice_rtM, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(bump_choice_rtM, 2));
}

time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(bump_choice_rtM, 1);
  rtmSampleHitPtr[2] = rtmStepTask(bump_choice_rtM, 2);
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
  if (bump_choice_rtM->Timing.TaskCounters.TID[1] == 0) {
    bump_choice_rtM->Timing.RateInteraction.TID1_2 =
      (bump_choice_rtM->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    bump_choice_rtM->Timing.perTaskSampleHits[5] =
      bump_choice_rtM->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++bump_choice_rtM->Timing.TaskCounters.TID[2] == 20) {/* Sample time: [0.02s, 0.0s] */
    bump_choice_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  bump_choice_rtM->Timing.sampleHits[2] =
    (bump_choice_rtM->Timing.TaskCounters.TID[2] == 0);
}

/* Disable for enable system:
 *   '<S30>/Enabled Subsystem'
 *   '<S42>/Enabled Subsystem'
 *   '<S43>/Enabled Subsystem'
 *   '<S44>/Enabled Subsystem'
 *   '<S46>/Enabled Subsystem'
 */
void bump_c_EnabledSubsystem_Disable(rtDW_EnabledSubsystem_bump_choi *localDW)
{
  /* DisableFcn of enable SubSystem Block: '<S30>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE = (int_T) SUBSYS_DISABLED;
}

/* Output and update for enable system:
 *   '<S30>/Enabled Subsystem'
 *   '<S42>/Enabled Subsystem'
 *   '<S43>/Enabled Subsystem'
 *   '<S44>/Enabled Subsystem'
 *   '<S46>/Enabled Subsystem'
 */
void bump_choice_EnabledSubsystem(int_T tid, boolean_T rtu_0, real_T rtu_1,
  rtB_EnabledSubsystem_bump_choic *localB, rtDW_EnabledSubsystem_bump_choi
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
        bump_c_EnabledSubsystem_Disable(localDW);
      }
    }
  }

  /* run blocks if enabled */
  if (localDW->EnabledSubsystem_MODE == SUBSYS_ENABLED) {
    if (tid == 0 || tid == 0) {
      if (tid == 0) {
        /* Inport: '<S34>/In1' */
        localB->In1 = rtu_1;
      }

      srUpdateBC(localDW->EnabledSubsystem_SubsysRanBC);
    }
  }
}

/* Start for trigger system:
 *   '<S6>/Sample and Hold'
 *   '<S64>/Sample and Hold'
 */
void bump_choice_SampleandHold_Start(rtB_SampleandHold_bump_choice *localB,
  rtP_SampleandHold_bump_choice *localP)
{
  /* virtual outports code */

  /* (Virtual) Outport Block: '<S63>/ ' */
  localB->In = localP->_Y0;
}

/* Output and update for trigger system:
 *   '<S6>/Sample and Hold'
 *   '<S64>/Sample and Hold'
 */
void bump_choice_SampleandHold(real_T rtu_0, real_T rtu_1,
  rtB_SampleandHold_bump_choice *localB, rtDW_SampleandHold_bump_choice *localDW,
  rtZCE_SampleandHold_bump_choice *localZCE)
{
  {
    ZCEventType trigEvent;
    trigEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&(localZCE->SampleandHold_ZCE),
                         rtu_0);

    /* conditionally execute */
    if (trigEvent != NO_ZCEVENT) {
      /* Inport: '<S63>/In' */
      localB->In = rtu_1;
      localDW->SampleandHold_SubsysRanBC = SUBSYS_RAN_BC_ONE_SHOT;
    }
  }
}

/* Model output function */
void bump_choice_output(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  if (tid == 0) {
    srClearBC(bump_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC);
    srClearBC(bump_choice_DWork.EnabledSubsystem_p.EnabledSubsystem_SubsysRanBC);
    srClearBC(bump_choice_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC);
    srClearBC(bump_choice_DWork.EnabledSubsystem_e.EnabledSubsystem_SubsysRanBC);
    srClearBC(bump_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC);
    srClearBC(bump_choice_DWork.SampleandHold_h.SampleandHold_SubsysRanBC);
    srClearBC(bump_choice_DWork.SampleandHold.SampleandHold_SubsysRanBC);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S30>/Clock'
     */
    bump_choice_B.Clock = bump_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S30>/Memory' */
    bump_choice_B.Memory = bump_choice_DWork.Memory_PreviousInput;

    /* Memory: '<S4>/Memory' */
    bump_choice_B.Memory_k = bump_choice_DWork.Memory_PreviousInput_i;

    /* Logic: '<S30>/Logical Operator2' */
    bump_choice_B.LogicalOperator2 = (bump_choice_B.Memory ||
      bump_choice_B.Memory_k);

    /* Logic: '<S30>/Logical Operator1' */
    bump_choice_B.LogicalOperator1 = !bump_choice_B.LogicalOperator2;

    /* SignalConversion: '<S30>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    bump_choice_B.HiddenBuf_InsertedFor_EnabledSu =
      bump_choice_B.LogicalOperator1;
  }

  /* SubSystem Block: '<S30>/Enabled Subsystem'
   */
  bump_choice_EnabledSubsystem(tid,
    bump_choice_B.HiddenBuf_InsertedFor_EnabledSu, bump_choice_B.Clock,
    &bump_choice_B.EnabledSubsystem, &bump_choice_DWork.EnabledSubsystem);
  if (tid == 0) {
    /* Sum: '<S30>/Sum' */
    bump_choice_B.Sum = bump_choice_B.Clock - bump_choice_B.EnabledSubsystem.In1;

    /* RelationalOperator: '<S33>/Compare' */
    bump_choice_B.Compare = (bump_choice_B.Sum > 0.0);

    /* RelationalOperator: '<S30>/Relational Operator' incorporates:
     *  Constant: '<S30>/Time'
     */
    bump_choice_B.RelationalOperator = (bump_choice_B.Sum >
      bump_choice_P.Time_Value);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S30>/Logical Operator' */
    bump_choice_B.LogicalOperator = (boolean_T)((bump_choice_B.Compare != 0U) ^
      bump_choice_B.RelationalOperator);

    /* Level2 S-Function Block: '<S12>/PCI-QUAD04 ' (enccbcioquadcount) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S12>/Gain' */
    bump_choice_B.Gain = bump_choice_P.Gain_Gain * bump_choice_B.PCIQUAD04;

    /* Sum: '<S12>/Sum3' incorporates:
     *  Constant: '<S12>/shoulderOffset'
     */
    bump_choice_B.Sum3 = bump_choice_B.Gain + bump_choice_P.shoulderOffset_Value;

    /* Trigonometry: '<S70>/Trigonometric Function' */
    bump_choice_B.TrigonometricFunction = cos(bump_choice_B.Sum3);

    /* Product: '<S70>/Product' incorporates:
     *  Constant: '<S70>/L1'
     */
    bump_choice_B.Product = bump_choice_B.TrigonometricFunction *
      bump_choice_P.L1_Value;

    /* Gain: '<S70>/Gain' */
    bump_choice_B.MatrixConcatenate2[0] = bump_choice_P.Gain_Gain_a *
      bump_choice_B.Product;

    /* Trigonometry: '<S70>/Trigonometric Function1' */
    bump_choice_B.TrigonometricFunction1 = sin(bump_choice_B.Sum3);

    /* Product: '<S70>/Product1' incorporates:
     *  Constant: '<S70>/L1'
     */
    bump_choice_B.Product1 = bump_choice_B.TrigonometricFunction1 *
      bump_choice_P.L1_Value;

    /* SignalConversion: '<S70>/ConcatHiddenBufferAtMatrix ConcatenateInPort1' */
    bump_choice_B.MatrixConcatenate2[1] = bump_choice_B.Product1;

    /* Level2 S-Function Block: '<S12>/PCI-QUAD04 1' (enccbcioquadcount) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[9];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S12>/Gain1' */
    bump_choice_B.Gain1 = bump_choice_P.Gain1_Gain * bump_choice_B.PCIQUAD041;

    /* Sum: '<S12>/Sum1' incorporates:
     *  Constant: '<S12>/elbowOffset'
     */
    bump_choice_B.Sum1 = bump_choice_B.Gain1 + bump_choice_P.elbowOffset_Value;

    /* Trigonometry: '<S70>/Trigonometric Function2' */
    bump_choice_B.TrigonometricFunction2 = sin(bump_choice_B.Sum1);

    /* Product: '<S70>/Product2' incorporates:
     *  Constant: '<S70>/L2'
     */
    bump_choice_B.Product2 = bump_choice_B.TrigonometricFunction2 *
      bump_choice_P.L2_Value;

    /* Gain: '<S70>/Gain1' */
    bump_choice_B.MatrixConcatenate2[2] = bump_choice_P.Gain1_Gain_m *
      bump_choice_B.Product2;

    /* Trigonometry: '<S70>/Trigonometric Function3' */
    bump_choice_B.TrigonometricFunction3 = cos(bump_choice_B.Sum1);

    /* Product: '<S70>/Product3' incorporates:
     *  Constant: '<S70>/L2'
     */
    bump_choice_B.Product3 = bump_choice_B.TrigonometricFunction3 *
      bump_choice_P.L2_Value;

    /* Gain: '<S70>/Gain2' */
    bump_choice_B.MatrixConcatenate2[3] = bump_choice_P.Gain2_Gain *
      bump_choice_B.Product3;

    /* Level2 S-Function Block: '<S9>/PCI-6025E AD' (adnipcie) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[10];
      sfcnOutputs(rts, 1);
    }

    {
      real_T tmp;
      real_T tmp_0;

      /* Sum: '<S70>/Sum2' */
      bump_choice_B.Sum2 = (0.0 - bump_choice_B.Product) -
        bump_choice_B.Product2;

      /* Sum: '<S70>/Sum4' incorporates:
       *  Constant: '<S70>/yoffset'
       */
      bump_choice_B.Sum4 = bump_choice_B.Sum2 + bump_choice_P.yoffset_Value;

      /* Sum: '<S70>/Sum3' */
      bump_choice_B.Sum3_o = bump_choice_B.Product3 - bump_choice_B.Product1;

      /* Sum: '<S70>/Sum1' incorporates:
       *  Constant: '<S70>/xoffset'
       */
      bump_choice_B.Sum1_k = bump_choice_B.Sum3_o + bump_choice_P.xoffset_Value;

      /* Trigonometry: '<S68>/Trigonometric Function1' */
      bump_choice_B.TrigonometricFunction1_o = rt_atan2(bump_choice_B.Sum4,
        bump_choice_B.Sum1_k);

      /* Sum: '<S68>/Sum' incorporates:
       *  Constant: '<S68>/AngleOffset'
       */
      bump_choice_B.Sum_c = bump_choice_B.TrigonometricFunction1_o +
        bump_choice_P.AngleOffset_Value;

      /* Trigonometry: '<S68>/Trigonometric Function2' */
      bump_choice_B.TrigonometricFunction2_l = cos(bump_choice_B.Sum_c);

      /* Fcn: '<S68>/sqrt(u[1]*u[1] + u[2]*u[2])' */
      tmp = bump_choice_B.Sum4;
      tmp_0 = bump_choice_B.Sum1_k;
      bump_choice_B.sqrtu1u1u2u2 = sqrt(tmp * tmp + tmp_0 * tmp_0);

      /* Product: '<S68>/Product1' */
      bump_choice_B.Product1_b = bump_choice_B.TrigonometricFunction2_l *
        bump_choice_B.sqrtu1u1u2u2;
    }

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S66>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&bump_choice_B.Product1_b, &bump_choice_B.DigitalFilter2,
                    &bump_choice_DWork.DigitalFilter2_FILT_STATES[0],
                    &bump_choice_DWork.DigitalFilter2_CIRCBUFFIDX, 11, 1, 1,
                    &bump_choice_P.DigitalFilter2_RTP1COEFF[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S66>/Derivative' */
    {
      real_T t = bump_choice_rtM->Timing.t[0];
      real_T timeStampA = bump_choice_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = bump_choice_DWork.Derivative_RWORK.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        bump_choice_B.Derivative = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &bump_choice_DWork.Derivative_RWORK.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        bump_choice_B.Derivative = (bump_choice_B.DigitalFilter2 - *lastBank++) /
          deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S66>/dG' */
    bump_choice_B.dG = bump_choice_P.dG_Gain * bump_choice_B.Derivative;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S66>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&bump_choice_B.dG, &bump_choice_B.DigitalFilter,
                    &bump_choice_DWork.DigitalFilter_FILT_STATES[0],
                    &bump_choice_DWork.DigitalFilter_CIRCBUFFIDX, 11, 1, 1,
                    &bump_choice_P.DigitalFilter_RTP1COEFF[0], 1);

    /* Trigonometry: '<S68>/Trigonometric Function' */
    bump_choice_B.TrigonometricFunction_d = sin(bump_choice_B.Sum_c);

    /* Product: '<S68>/Product' */
    bump_choice_B.Product_f = bump_choice_B.sqrtu1u1u2u2 *
      bump_choice_B.TrigonometricFunction_d;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&bump_choice_B.Product_f, &bump_choice_B.DigitalFilter2_c,
                    &bump_choice_DWork.DigitalFilter2_FILT_STATES_a[0],
                    &bump_choice_DWork.DigitalFilter2_CIRCBUFFIDX_j, 11, 1, 1,
                    &bump_choice_P.DigitalFilter2_RTP1COEFF_g[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S67>/Derivative' */
    {
      real_T t = bump_choice_rtM->Timing.t[0];
      real_T timeStampA = bump_choice_DWork.Derivative_RWORK_e.TimeStampA;
      real_T timeStampB = bump_choice_DWork.Derivative_RWORK_e.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        bump_choice_B.Derivative_i = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &bump_choice_DWork.Derivative_RWORK_e.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        bump_choice_B.Derivative_i = (bump_choice_B.DigitalFilter2_c - *lastBank
          ++) / deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S67>/dG' */
    bump_choice_B.dG_c = bump_choice_P.dG_Gain_l * bump_choice_B.Derivative_i;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&bump_choice_B.dG_c, &bump_choice_B.DigitalFilter_k,
                    &bump_choice_DWork.DigitalFilter_FILT_STATES_e[0],
                    &bump_choice_DWork.DigitalFilter_CIRCBUFFIDX_c, 11, 1, 1,
                    &bump_choice_P.DigitalFilter_RTP1COEFF_a[0], 1);

    {
      real_T tmp;
      real_T tmp_0;

      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S9>/UseTachs'
       */
      if (bump_choice_P.UseTachs_Value >= bump_choice_P.Switch_Threshold) {
        {
          real_T tmp;
          real_T tmp_0;

          /* Gain: '<S9>/TachGain2' */
          bump_choice_B.TachGain2 = bump_choice_P.TachGain2_Gain *
            bump_choice_B.PCI6025EAD_o2;

          /* Gain: '<S9>/TachGain1' */
          bump_choice_B.TachGain1 = bump_choice_P.TachGain1_Gain *
            bump_choice_B.PCI6025EAD_o1;

          /* SignalConversion: '<S9>/TmpHiddenBufferAtMatrix MultiplyInport2' */
          tmp = bump_choice_B.TachGain1;
          tmp_0 = bump_choice_B.TachGain2;
          bump_choice_B.TmpHiddenBufferAtMatrixMultiply[0] = tmp;
          bump_choice_B.TmpHiddenBufferAtMatrixMultiply[1] = tmp_0;
        }

        {
          static const int_T dims[3] = { 2, 2, 1 };

          rt_MatMultRR_Dbl(bump_choice_B.MatrixMultiply,
                           bump_choice_B.MatrixConcatenate2,
                           bump_choice_B.TmpHiddenBufferAtMatrixMultiply, &dims
                           [0]);
        }

        bump_choice_B.Switch[0] = bump_choice_B.MatrixMultiply[0];
        bump_choice_B.Switch[1] = bump_choice_B.MatrixMultiply[1];
      } else {
        tmp = bump_choice_B.DigitalFilter;
        tmp_0 = bump_choice_B.DigitalFilter_k;
        bump_choice_B.Switch[0] = tmp;
        bump_choice_B.Switch[1] = tmp_0;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S42>/Clock'
     */
    bump_choice_B.Clock_k = bump_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S42>/Memory' */
    bump_choice_B.Memory_b = bump_choice_DWork.Memory_PreviousInput_d;

    /* RelationalOperator: '<S1>/Relational Operator' incorporates:
     *  Constant: '<S1>/XLowLimit'
     */
    bump_choice_B.RelationalOperator_g = (bump_choice_B.Sum3_o <
      bump_choice_P.XLowLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator1' incorporates:
     *  Constant: '<S1>/XHighLimit'
     */
    bump_choice_B.RelationalOperator1 = (bump_choice_B.Sum3_o >
      bump_choice_P.XHighLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator2' incorporates:
     *  Constant: '<S1>/YHighLimit'
     */
    bump_choice_B.RelationalOperator2 = (bump_choice_B.Sum2 <
      bump_choice_P.YHighLimit_Value);

    /* RelationalOperator: '<S1>/Relational Operator3' incorporates:
     *  Constant: '<S1>/YLowLimit'
     */
    bump_choice_B.RelationalOperator3 = (bump_choice_B.Sum2 >
      bump_choice_P.YLowLimit_Value);

    /* Logic: '<S1>/Logical Operator' */
    bump_choice_B.LogicalOperator_a = (bump_choice_B.RelationalOperator_g ||
      bump_choice_B.RelationalOperator1 || bump_choice_B.RelationalOperator2 ||
      bump_choice_B.RelationalOperator3);

    /* Logic: '<S5>/InBox' */
    bump_choice_B.InBox = !bump_choice_B.LogicalOperator_a;

    /* Logic: '<S46>/Logical Operator3' */
    bump_choice_B.LogicalOperator3 = !bump_choice_B.InBox;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S46>/Clock'
     */
    bump_choice_B.Clock_h = bump_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S46>/Memory' */
    bump_choice_B.Memory_b5 = bump_choice_DWork.Memory_PreviousInput_dp;

    /* Logic: '<S46>/Logical Operator4' */
    bump_choice_B.LogicalOperator4 = (bump_choice_B.Memory_b5 &&
      bump_choice_B.LogicalOperator3);

    /* RelationalOperator: '<S35>/Compare' */
    bump_choice_B.Compare_a = (bump_choice_B.Switch[0] == 0.0);

    /* RelationalOperator: '<S36>/Compare' */
    bump_choice_B.Compare_e = (bump_choice_B.Switch[1] == 0.0);

    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Constant: '<S5>/RecenterFlag'
     */
    bump_choice_B.LogicalOperator_j = ((bump_choice_P.RecenterFlag_Value != 0.0)
      && (bump_choice_B.Compare_a != 0U) && (bump_choice_B.Compare_e != 0U) &&
      bump_choice_B.LogicalOperator_a);

    /* Logic: '<S46>/Logical Operator2' */
    bump_choice_B.LogicalOperator2_m = (bump_choice_B.LogicalOperator4 ||
      bump_choice_B.LogicalOperator_j);

    /* Logic: '<S46>/Logical Operator1' */
    bump_choice_B.LogicalOperator1_f = !bump_choice_B.LogicalOperator2_m;

    /* SignalConversion: '<S46>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    bump_choice_B.HiddenBuf_InsertedFor_Enabled_g =
      bump_choice_B.LogicalOperator1_f;
  }

  /* SubSystem Block: '<S46>/Enabled Subsystem'
   */
  bump_choice_EnabledSubsystem(tid,
    bump_choice_B.HiddenBuf_InsertedFor_Enabled_g, bump_choice_B.Clock_h,
    &bump_choice_B.EnabledSubsystem_l, &bump_choice_DWork.EnabledSubsystem_l);
  if (tid == 0) {
    /* Sum: '<S46>/Sum' */
    bump_choice_B.Sum_n = bump_choice_B.Clock_h -
      bump_choice_B.EnabledSubsystem_l.In1;

    /* RelationalOperator: '<S59>/Compare' */
    bump_choice_B.Compare_o = (bump_choice_B.Sum_n > 0.0);

    /* RelationalOperator: '<S46>/Relational Operator' incorporates:
     *  Constant: '<S46>/Time'
     */
    bump_choice_B.RelationalOperator_i = (bump_choice_B.Sum_n >
      bump_choice_P.Time_Value_p);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S46>/Logical Operator' */
    bump_choice_B.LogicalOperator_n = (boolean_T)((bump_choice_B.Compare_o != 0U)
      ^ bump_choice_B.RelationalOperator_i);

    /* RelationalOperator: '<S62>/Compare' */
    bump_choice_B.Compare_k = (bump_choice_B.LogicalOperator_n <= FALSE);

    /* UnitDelay: '<S60>/Delay Input1' */
    bump_choice_B.Uk1 = bump_choice_DWork.DelayInput1_DSTATE;

    /* RelationalOperator: '<S60>/FixPt Relational Operator' */
    bump_choice_B.FixPtRelationalOperator = (bump_choice_B.Compare_k >
      bump_choice_B.Uk1);

    /* Logic: '<S46>/Logical Operator5' */
    bump_choice_B.LogicalOperator5 = (bump_choice_B.LogicalOperator3 &&
      (bump_choice_B.FixPtRelationalOperator != 0U));

    /* Logic: '<S42>/Logical Operator2' */
    bump_choice_B.LogicalOperator2_a = (bump_choice_B.Memory_b ||
      bump_choice_B.LogicalOperator5);

    /* Logic: '<S42>/Logical Operator1' */
    bump_choice_B.LogicalOperator1_c = !bump_choice_B.LogicalOperator2_a;

    /* SignalConversion: '<S42>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    bump_choice_B.HiddenBuf_InsertedFor_Enabled_j =
      bump_choice_B.LogicalOperator1_c;
  }

  /* SubSystem Block: '<S42>/Enabled Subsystem'
   */
  bump_choice_EnabledSubsystem(tid,
    bump_choice_B.HiddenBuf_InsertedFor_Enabled_j, bump_choice_B.Clock_k,
    &bump_choice_B.EnabledSubsystem_p, &bump_choice_DWork.EnabledSubsystem_p);
  if (tid == 0) {
    /* Sum: '<S42>/Sum' */
    bump_choice_B.Sum_l = bump_choice_B.Clock_k -
      bump_choice_B.EnabledSubsystem_p.In1;

    /* RelationalOperator: '<S52>/Compare' */
    bump_choice_B.Compare_h = (bump_choice_B.Sum_l > 0.0);

    /* RelationalOperator: '<S42>/Relational Operator' incorporates:
     *  Constant: '<S42>/Time'
     */
    bump_choice_B.RelationalOperator_l = (bump_choice_B.Sum_l >
      bump_choice_P.Time_Value_c);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S42>/Logical Operator' */
    bump_choice_B.LogicalOperator_e = (boolean_T)((bump_choice_B.Compare_h != 0U)
      ^ bump_choice_B.RelationalOperator_l);

    /* Abs: '<S39>/Abs2' */
    bump_choice_B.Abs2 = fabs(bump_choice_B.Switch[0]);

    /* RelationalOperator: '<S50>/Compare' incorporates:
     *  Constant: '<S50>/Constant'
     */
    bump_choice_B.Compare_d = (bump_choice_B.Abs2 <=
      bump_choice_P.Constant_Value);

    /* Abs: '<S39>/Abs3' */
    bump_choice_B.Abs3 = fabs(bump_choice_B.Switch[1]);

    /* RelationalOperator: '<S51>/Compare' incorporates:
     *  Constant: '<S51>/Constant'
     */
    bump_choice_B.Compare_dw = (bump_choice_B.Abs3 <=
      bump_choice_P.Constant_Value_o);

    /* Logic: '<S39>/Logical Operator1' */
    bump_choice_B.LogicalOperator1_e = ((bump_choice_B.Compare_d != 0U) &&
      (bump_choice_B.Compare_dw != 0U));

    /* Logic: '<S5>/NOT' */
    bump_choice_B.NOT = !bump_choice_B.LogicalOperator1_e;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S44>/Clock'
     */
    bump_choice_B.Clock_p = bump_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S44>/Memory' */
    bump_choice_B.Memory_n = bump_choice_DWork.Memory_PreviousInput_b;

    /* RelationalOperator: '<S58>/Compare' */
    bump_choice_B.Compare_do = (bump_choice_B.LogicalOperator1_e <= FALSE);

    /* UnitDelay: '<S45>/Delay Input1' */
    bump_choice_B.Uk1_c = bump_choice_DWork.DelayInput1_DSTATE_h;

    /* RelationalOperator: '<S45>/FixPt Relational Operator' */
    bump_choice_B.FixPtRelationalOperator_p = (bump_choice_B.Compare_do >
      bump_choice_B.Uk1_c);

    /* Logic: '<S44>/Logical Operator2' */
    bump_choice_B.LogicalOperator2_a2 = (bump_choice_B.Memory_n ||
      (bump_choice_B.FixPtRelationalOperator_p != 0U));

    /* Logic: '<S44>/Logical Operator1' */
    bump_choice_B.LogicalOperator1_i = !bump_choice_B.LogicalOperator2_a2;

    /* SignalConversion: '<S44>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    bump_choice_B.HiddenBuf_InsertedFor_Enabled_a =
      bump_choice_B.LogicalOperator1_i;
  }

  /* SubSystem Block: '<S44>/Enabled Subsystem'
   */
  bump_choice_EnabledSubsystem(tid,
    bump_choice_B.HiddenBuf_InsertedFor_Enabled_a, bump_choice_B.Clock_p,
    &bump_choice_B.EnabledSubsystem_e, &bump_choice_DWork.EnabledSubsystem_e);
  if (tid == 0) {
    /* Sum: '<S44>/Sum' */
    bump_choice_B.Sum_h = bump_choice_B.Clock_p -
      bump_choice_B.EnabledSubsystem_e.In1;

    /* RelationalOperator: '<S56>/Compare' */
    bump_choice_B.Compare_l = (bump_choice_B.Sum_h > 0.0);

    /* RelationalOperator: '<S44>/Relational Operator' incorporates:
     *  Constant: '<S44>/Time'
     */
    bump_choice_B.RelationalOperator_p = (bump_choice_B.Sum_h >
      bump_choice_P.Time_Value_o);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S44>/Logical Operator' */
    bump_choice_B.LogicalOperator_c = (boolean_T)((bump_choice_B.Compare_l != 0U)
      ^ bump_choice_B.RelationalOperator_p);

    /* RelationalOperator: '<S49>/Compare' */
    bump_choice_B.Compare_ez = (bump_choice_B.LogicalOperator_c <= FALSE);

    /* UnitDelay: '<S38>/Delay Input1' */
    bump_choice_B.Uk1_j = bump_choice_DWork.DelayInput1_DSTATE_f;

    /* RelationalOperator: '<S38>/FixPt Relational Operator' */
    bump_choice_B.FixPtRelationalOperator_j = (bump_choice_B.Compare_ez >
      bump_choice_B.Uk1_j);

    /* DataTypeConversion: '<S5>/Data Type Conversion2' */
    bump_choice_B.DataTypeConversion2 = (bump_choice_B.FixPtRelationalOperator_j
      != 0U);

    /* Logic: '<S5>/Logical Operator1' */
    bump_choice_B.LogicalOperator1_g = (bump_choice_B.NOT ||
      bump_choice_B.DataTypeConversion2);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S43>/Clock'
     */
    bump_choice_B.Clock_d = bump_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S43>/Memory' */
    bump_choice_B.Memory_m = bump_choice_DWork.Memory_PreviousInput_n;

    /* Logic: '<S43>/Logical Operator2' */
    bump_choice_B.LogicalOperator2_i = (bump_choice_B.Memory_m ||
      bump_choice_B.LogicalOperator5);

    /* Logic: '<S43>/Logical Operator1' */
    bump_choice_B.LogicalOperator1_l = !bump_choice_B.LogicalOperator2_i;

    /* SignalConversion: '<S43>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    bump_choice_B.HiddenBuf_InsertedFor_Enabled_l =
      bump_choice_B.LogicalOperator1_l;
  }

  /* SubSystem Block: '<S43>/Enabled Subsystem'
   */
  bump_choice_EnabledSubsystem(tid,
    bump_choice_B.HiddenBuf_InsertedFor_Enabled_l, bump_choice_B.Clock_d,
    &bump_choice_B.EnabledSubsystem_o, &bump_choice_DWork.EnabledSubsystem_o);
  if (tid == 0) {
    /* Sum: '<S43>/Sum' */
    bump_choice_B.Sum_hb = bump_choice_B.Clock_d -
      bump_choice_B.EnabledSubsystem_o.In1;

    /* RelationalOperator: '<S54>/Compare' */
    bump_choice_B.Compare_n = (bump_choice_B.Sum_hb > 0.0);

    /* RelationalOperator: '<S43>/Relational Operator' incorporates:
     *  Constant: '<S43>/Time'
     */
    bump_choice_B.RelationalOperator_k = (bump_choice_B.Sum_hb >
      bump_choice_P.Time_Value_h);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S43>/Logical Operator' */
    bump_choice_B.LogicalOperator_nd = (boolean_T)((bump_choice_B.Compare_n !=
      0U) ^ bump_choice_B.RelationalOperator_k);

    /* RelationalOperator: '<S48>/Compare' */
    bump_choice_B.Compare_dc = (bump_choice_B.LogicalOperator_nd <= FALSE);

    /* UnitDelay: '<S37>/Delay Input1' */
    bump_choice_B.Uk1_m = bump_choice_DWork.DelayInput1_DSTATE_l;

    /* RelationalOperator: '<S37>/FixPt Relational Operator' */
    bump_choice_B.FixPtRelationalOperator_o = (bump_choice_B.Compare_dc >
      bump_choice_B.Uk1_m);

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    bump_choice_B.DataTypeConversion1 = (bump_choice_B.FixPtRelationalOperator_o
      != 0U);

    /* Memory: '<S41>/Memory' */
    bump_choice_B.Memory_j = bump_choice_DWork.Memory_PreviousInput_iw;

    /* CombinatorialLogic Block: '<S41>/Logic'
     */
    {
      int_T rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (int_T)(bump_choice_B.LogicalOperator1_g != 0);
      rowidx = (rowidx << 1) + (int_T)(bump_choice_B.DataTypeConversion1 != 0);
      rowidx = (rowidx << 1) + (int_T)(bump_choice_B.Memory_j != 0);

      /* Copy the appropriate row of the table into the block output vector */
      bump_choice_B.Logic[0] = bump_choice_P.Logic_table[rowidx];
      bump_choice_B.Logic[1] = bump_choice_P.Logic_table[rowidx + 8];
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
      bump_choice_B.LogicalOperator5_k = (bump_choice_B.Logic[1] ||
        bump_choice_B.LogicalOperator_nd || bump_choice_B.LogicalOperator_a);

      /* UnitDelay: '<S22>/x' */
      bump_choice_B.x = bump_choice_DWork.x_DSTATE;

      /* UnitDelay: '<S23>/x' */
      bump_choice_B.x_e = bump_choice_DWork.x_DSTATE_n;

      /* Sum: '<S20>/Add' */
      bump_choice_B.Add = bump_choice_B.x - bump_choice_B.x_e;

      /* UnitDelay: '<S24>/x' */
      bump_choice_B.x_et = bump_choice_DWork.x_DSTATE_i;

      /* UnitDelay: '<S25>/x' */
      bump_choice_B.x_d = bump_choice_DWork.x_DSTATE_in;

      /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
       *  Constant: '<S3>/Load'
       *  Constant: '<S3>/Off'
       *  Constant: '<S3>/staticX'
       *  Constant: '<S3>/staticY'
       */
      switch ((int32_T)bump_choice_P.Load_Value) {
       case 0:
        tmp = bump_choice_P.Off_Value_f;
        tmp_0 = bump_choice_P.Off_Value_f;
        bump_choice_B.MultiportSwitch[0] = tmp;
        bump_choice_B.MultiportSwitch[1] = tmp_0;
        break;

       case 1:
        tmp_1 = bump_choice_P.staticX_Value_h;
        tmp_2 = bump_choice_P.staticY_Value_b;
        bump_choice_B.MultiportSwitch[0] = tmp_1;
        bump_choice_B.MultiportSwitch[1] = tmp_2;
        break;

       case 2:
        /* Sum: '<S20>/Add1' */
        bump_choice_B.Add1_f = bump_choice_B.x_et - bump_choice_B.x_d;

        /* Gain: '<S3>/LorentzForceGain' */
        tmp_7 = bump_choice_B.Add;
        tmp_8 = bump_choice_B.Add1_f;
        bump_choice_B.LorentzForceGain[0] =
          bump_choice_P.LorentzForceGain_Gain_c * tmp_7;
        bump_choice_B.LorentzForceGain[1] =
          bump_choice_P.LorentzForceGain_Gain_c * tmp_8;
        bump_choice_B.MultiportSwitch[0] = bump_choice_B.LorentzForceGain[0];
        bump_choice_B.MultiportSwitch[1] = bump_choice_B.LorentzForceGain[1];
        break;

       default:
        /* MultiPortSwitch: '<S3>/dynamicAngle Switch' incorporates:
         *  Constant: '<S3>/DynamicAngle'
         *  Constant: '<S3>/visAngle'
         */
        if ((int32_T)bump_choice_P.DynamicAngle_Value_f == 0) {
          bump_choice_B.dynamicAngleSwitch = bump_choice_P.visAngle_Value_n;
        } else {
          /* Gain: '<S3>/Gain' */
          bump_choice_B.Gain_n = bump_choice_P.Gain_Gain_b * bump_choice_B.Add;
          bump_choice_B.dynamicAngleSwitch = bump_choice_B.Gain_n;
        }

        /* Trigonometry: '<S21>/sin' */
        bump_choice_B.sin_h = sin(bump_choice_B.dynamicAngleSwitch);

        /* Gain: '<S21>/Inverter' */
        bump_choice_B.Inverter[0] = bump_choice_P.Inverter_Gain_j *
          bump_choice_B.Switch[0];
        bump_choice_B.Inverter[1] = bump_choice_P.Inverter_Gain_j *
          bump_choice_B.Switch[1];

        /* Product: '<S21>/Product3' */
        cg_in = bump_choice_B.Inverter[0];
        bump_choice_B.Product3_k = cg_in * bump_choice_B.sin_h;

        /* Trigonometry: '<S21>/cos' */
        bump_choice_B.cos_c = cos(bump_choice_B.dynamicAngleSwitch);

        /* Product: '<S21>/Product2' */
        cg_in_0 = bump_choice_B.Inverter[1];
        bump_choice_B.Product2_l = cg_in_0 * bump_choice_B.cos_c;

        /* Sum: '<S21>/Subtract' */
        bump_choice_B.Subtract_b = bump_choice_B.Product2_l -
          bump_choice_B.Product3_k;

        /* Product: '<S21>/Product1' */
        cg_in_1 = bump_choice_B.Inverter[1];
        bump_choice_B.Product1_l = cg_in_1 * bump_choice_B.sin_h;

        /* Product: '<S21>/Product' */
        cg_in_2 = bump_choice_B.Inverter[0];
        bump_choice_B.Product_a = cg_in_2 * bump_choice_B.cos_c;

        /* Sum: '<S21>/Add' */
        bump_choice_B.Add_h = bump_choice_B.Product_a + bump_choice_B.Product1_l;

        /* Gain: '<S21>/Gain' */
        tmp_9 = bump_choice_B.Add_h;
        tmp_a = bump_choice_B.Subtract_b;
        bump_choice_B.Gain_d[0] = bump_choice_P.Gain_Gain_by * tmp_9;
        bump_choice_B.Gain_d[1] = bump_choice_P.Gain_Gain_by * tmp_a;
        bump_choice_B.MultiportSwitch[0] = bump_choice_B.Gain_d[0];
        bump_choice_B.MultiportSwitch[1] = bump_choice_B.Gain_d[1];
        break;
      }

      /* UnitDelay: '<S16>/x' */
      bump_choice_B.x_b = bump_choice_DWork.x_DSTATE_m;

      /* UnitDelay: '<S17>/x' */
      bump_choice_B.x_c = bump_choice_DWork.x_DSTATE_h;

      /* Sum: '<S14>/Add' */
      bump_choice_B.Add_k = bump_choice_B.x_b - bump_choice_B.x_c;

      /* UnitDelay: '<S18>/x' */
      bump_choice_B.x_j = bump_choice_DWork.x_DSTATE_o;

      /* UnitDelay: '<S19>/x' */
      bump_choice_B.x_h = bump_choice_DWork.x_DSTATE_d;

      /* MultiPortSwitch: '<S2>/LoadSelect Switch' incorporates:
       *  Constant: '<S2>/Load'
       *  Constant: '<S2>/Off'
       *  Constant: '<S2>/staticX'
       *  Constant: '<S2>/staticY'
       */
      switch ((int32_T)bump_choice_P.Load_Value_d) {
       case 0:
        tmp_3 = bump_choice_P.Off_Value;
        tmp_4 = bump_choice_P.Off_Value;
        bump_choice_B.LoadSelectSwitch[0] = tmp_3;
        bump_choice_B.LoadSelectSwitch[1] = tmp_4;
        break;

       case 1:
        tmp_5 = bump_choice_P.staticX_Value;
        tmp_6 = bump_choice_P.staticY_Value;
        bump_choice_B.LoadSelectSwitch[0] = tmp_5;
        bump_choice_B.LoadSelectSwitch[1] = tmp_6;
        break;

       case 2:
        /* Sum: '<S14>/Add1' */
        bump_choice_B.Add1_k = bump_choice_B.x_j - bump_choice_B.x_h;

        /* Gain: '<S2>/LorentzForceGain' */
        tmp_b = bump_choice_B.Add_k;
        tmp_c = bump_choice_B.Add1_k;
        bump_choice_B.LorentzForceGain_p[0] =
          bump_choice_P.LorentzForceGain_Gain * tmp_b;
        bump_choice_B.LorentzForceGain_p[1] =
          bump_choice_P.LorentzForceGain_Gain * tmp_c;
        bump_choice_B.LoadSelectSwitch[0] = bump_choice_B.LorentzForceGain_p[0];
        bump_choice_B.LoadSelectSwitch[1] = bump_choice_B.LorentzForceGain_p[1];
        break;

       default:
        /* MultiPortSwitch: '<S2>/DynamicAngle Switch' incorporates:
         *  Constant: '<S2>/DynamicAngle'
         *  Constant: '<S2>/visAngle'
         */
        if ((int32_T)bump_choice_P.DynamicAngle_Value == 0) {
          bump_choice_B.DynamicAngleSwitch = bump_choice_P.visAngle_Value;
        } else {
          /* Gain: '<S2>/Gain' */
          bump_choice_B.Gain_a = bump_choice_P.Gain_Gain_m * bump_choice_B.Add_k;
          bump_choice_B.DynamicAngleSwitch = bump_choice_B.Gain_a;
        }

        /* Trigonometry: '<S15>/sin' */
        bump_choice_B.sin_i = sin(bump_choice_B.DynamicAngleSwitch);

        /* Gain: '<S15>/Inverter' */
        bump_choice_B.Inverter_k[0] = bump_choice_P.Inverter_Gain *
          bump_choice_B.Switch[0];
        bump_choice_B.Inverter_k[1] = bump_choice_P.Inverter_Gain *
          bump_choice_B.Switch[1];

        /* Product: '<S15>/Product3' */
        cg_in_3 = bump_choice_B.Inverter_k[0];
        bump_choice_B.Product3_h = cg_in_3 * bump_choice_B.sin_i;

        /* Trigonometry: '<S15>/cos' */
        bump_choice_B.cos_m = cos(bump_choice_B.DynamicAngleSwitch);

        /* Product: '<S15>/Product2' */
        cg_in_4 = bump_choice_B.Inverter_k[1];
        bump_choice_B.Product2_g = cg_in_4 * bump_choice_B.cos_m;

        /* Sum: '<S15>/Subtract' */
        bump_choice_B.Subtract_e = bump_choice_B.Product2_g -
          bump_choice_B.Product3_h;

        /* Product: '<S15>/Product1' */
        cg_in_5 = bump_choice_B.Inverter_k[1];
        bump_choice_B.Product1_p = cg_in_5 * bump_choice_B.sin_i;

        /* Product: '<S15>/Product' */
        cg_in_6 = bump_choice_B.Inverter_k[0];
        bump_choice_B.Product_i = cg_in_6 * bump_choice_B.cos_m;

        /* Sum: '<S15>/Add' */
        bump_choice_B.Add_ht = bump_choice_B.Product_i +
          bump_choice_B.Product1_p;

        /* Gain: '<S15>/Gain' */
        tmp_d = bump_choice_B.Add_ht;
        tmp_e = bump_choice_B.Subtract_e;
        bump_choice_B.Gain_f[0] = bump_choice_P.Gain_Gain_ap * tmp_d;
        bump_choice_B.Gain_f[1] = bump_choice_P.Gain_Gain_ap * tmp_e;
        bump_choice_B.LoadSelectSwitch[0] = bump_choice_B.Gain_f[0];
        bump_choice_B.LoadSelectSwitch[1] = bump_choice_B.Gain_f[1];
        break;
      }
    }

    /* Level2 S-Function Block: '<Root>/Behavior BC' (mastercon_bc) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[11];
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
      if (bump_choice_B.LogicalOperator) {
        tmp = bump_choice_P.zeroX_Value;
        tmp_0 = bump_choice_P.zeroY_Value;
        bump_choice_B.Switch2[0] = tmp;
        bump_choice_B.Switch2[1] = tmp_0;
      } else {
        /* Switch: '<S4>/Switch1' */
        if (bump_choice_B.LogicalOperator5_k) {
          /* Logic: '<S5>/Logical Operator6' */
          bump_choice_B.LogicalOperator6 = !bump_choice_B.LogicalOperator_e;

          /* Logic: '<S5>/Logical Operator3' */
          bump_choice_B.LogicalOperator3_d = (bump_choice_B.LogicalOperator6 &&
            bump_choice_B.LogicalOperator_a);

          /* Switch: '<S5>/Switch' */
          if (bump_choice_B.LogicalOperator3_d) {
            /* Gain: '<S5>/Bounding Box Viscosity' */
            bump_choice_B.BoundingBoxViscosity[0] =
              bump_choice_P.BoundingBoxViscosity_Gain * bump_choice_B.Switch[0];
            bump_choice_B.BoundingBoxViscosity[1] =
              bump_choice_P.BoundingBoxViscosity_Gain * bump_choice_B.Switch[1];
            bump_choice_B.Switch_j[0] = bump_choice_B.BoundingBoxViscosity[0];
            bump_choice_B.Switch_j[1] = bump_choice_B.BoundingBoxViscosity[1];
          } else {
            /* Product: '<S40>/Product' */
            bump_choice_B.Product_g = (int32_T)bump_choice_B.LogicalOperator_e ?
              bump_choice_B.Product1_b : 0.0;

            /* Gain: '<S40>/Gain1' */
            bump_choice_B.Gain1_n = bump_choice_P.Gain1_Gain_j *
              bump_choice_B.Product_g;

            /* Gain: '<S40>/Gain3' */
            bump_choice_B.Gain3 = bump_choice_P.Gain3_Gain *
              bump_choice_B.Switch[0];

            /* Sum: '<S40>/Add' */
            bump_choice_B.Add_i = bump_choice_B.Gain3 + bump_choice_B.Gain1_n;

            /* Saturate: '<S40>/Saturation' */
            rtsaturate_U0DataInY0Container = rt_SATURATE(bump_choice_B.Add_i,
              bump_choice_P.Saturation_LowerSat,
              bump_choice_P.Saturation_UpperSat);
            bump_choice_B.Saturation = rtsaturate_U0DataInY0Container;

            /* Gain: '<S40>/Gain4' */
            bump_choice_B.Gain4 = bump_choice_P.Gain4_Gain *
              bump_choice_B.Switch[1];

            /* Product: '<S40>/Product1' */
            bump_choice_B.Product1_o = (int32_T)bump_choice_B.LogicalOperator_e ?
              bump_choice_B.Product_f : 0.0;

            /* Gain: '<S40>/Gain2' */
            bump_choice_B.Gain2 = bump_choice_P.Gain2_Gain_o *
              bump_choice_B.Product1_o;

            /* Sum: '<S40>/Add1' */
            bump_choice_B.Add1_ef = bump_choice_B.Gain2 + bump_choice_B.Gain4;

            /* Saturate: '<S40>/Saturation1' */
            rtsaturate_U0DataInY0Containe_0 = rt_SATURATE(bump_choice_B.Add1_ef,
              bump_choice_P.Saturation1_LowerSat,
              bump_choice_P.Saturation1_UpperSat);
            bump_choice_B.Saturation1 = rtsaturate_U0DataInY0Containe_0;
            tmp_1 = bump_choice_B.Saturation;
            tmp_2 = bump_choice_B.Saturation1;
            bump_choice_B.Switch_j[0] = tmp_1;
            bump_choice_B.Switch_j[1] = tmp_2;
          }

          bump_choice_B.Switch1[0] = bump_choice_B.Switch_j[0];
          bump_choice_B.Switch1[1] = bump_choice_B.Switch_j[1];
        } else {
          bump_choice_B.Switch1[0] = bump_choice_B.BehaviorBC_o1[0];
          bump_choice_B.Switch1[1] = bump_choice_B.BehaviorBC_o1[1];
        }

        bump_choice_B.Switch2[0] = bump_choice_B.Switch1[0];
        bump_choice_B.Switch2[1] = bump_choice_B.Switch1[1];
      }

      /* Output and update for atomic system: '<S4>/Force//Torque Transform' */

      /* Gain: '<S28>/Gain' */
      bump_choice_B.Gain_i[0] = bump_choice_P.Gain_Gain_j *
        bump_choice_B.Switch2[0];
      bump_choice_B.Gain_i[1] = bump_choice_P.Gain_Gain_j *
        bump_choice_B.Switch2[1];

      /* Math Block: '<S32>/Math Function'
       */
      /* Operator : transpose */
      {
        uint32_T count = 0;
        uint32_T row;
        uint32_T col;
        for (row= 0; row < 2; row++) {
          for (col= 0; col < 2; col++) {
            bump_choice_B.MathFunction[row + 2 * col] =
              bump_choice_B.MatrixConcatenate2[count];
            count++;
          }
        }
      }

      {
        static const int_T dims[3] = { 2, 2, 1 };

        rt_MatMultRR_Dbl(bump_choice_B.MatrixMultiply_c,
                         bump_choice_B.MathFunction,
                         bump_choice_B.Gain_i, &dims[0]);
      }

      /* Gain: '<S4>/MG1' */
      bump_choice_B.MG1 = bump_choice_P.MG1_Gain *
        bump_choice_B.MatrixMultiply_c[0];

      /* Gain: '<S4>/MG2' */
      bump_choice_B.MG2 = bump_choice_P.MG2_Gain *
        bump_choice_B.MatrixMultiply_c[1];
    }

    /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[12];
      sfcnOutputs(rts, 1);
    }

    /* ok to acquire for <S29>/S-Function */
    bump_choice_DWork.SFunction_IWORK.AcquireOK = 1;

    /* ok to acquire for <S31>/S-Function */
    bump_choice_DWork.SFunction_IWORK_n.AcquireOK = 1;

    /* RelationalOperator: '<S26>/Compare' incorporates:
     *  Constant: '<S26>/Constant'
     */
    bump_choice_B.Compare_p = (bump_choice_B.MG1 >
      bump_choice_P.Constant_Value_j);

    /* RelationalOperator: '<S27>/Compare' incorporates:
     *  Constant: '<S27>/Constant'
     */
    bump_choice_B.Compare_hq = (bump_choice_B.MG2 >
      bump_choice_P.Constant_Value_g);

    /* SignalConversion: '<S4>/ConcatHiddenBufferAtMatrix ConcatenationInPort0' */
    bump_choice_B.MatrixConcatenation[0] = bump_choice_B.LogicalOperator5_k;

    /* SignalConversion: '<S4>/ConcatHiddenBufferAtMatrix ConcatenationInPort1' */
    bump_choice_B.MatrixConcatenation[1] = bump_choice_B.LogicalOperator;

    /* Logic: '<S4>/Logical Operator1' */
    bump_choice_B.LogicalOperator1_it = ((bump_choice_B.Compare_p != 0U) ||
      (bump_choice_B.Compare_hq != 0U));

    /* Pack: <S7>/Pack */
    (void) memcpy(bump_choice_B.Pack,&bump_choice_P.PacketSpec_Value,
                  4);
    (void) memcpy(&bump_choice_B.Pack[4],&bump_choice_P.NaNupperbytes_Value,
                  4);
    (void) memcpy(&bump_choice_B.Pack[8],&bump_choice_B.BehaviorBC_o6[0],
                  8);
    (void) memcpy(&bump_choice_B.Pack[16],&bump_choice_B.BehaviorBC_o6[1],
                  8);
    (void) memcpy(&bump_choice_B.Pack[24],&bump_choice_B.BehaviorBC_o8[0],
                  8);
    (void) memcpy(&bump_choice_B.Pack[32],&bump_choice_B.BehaviorBC_o8[1],
                  8);
    (void) memcpy(&bump_choice_B.Pack[40],&bump_choice_P.Constant_Value_d,
                  8);
    (void) memcpy(&bump_choice_B.Pack[48],bump_choice_B.BehaviorBC_o4,
                  120);
  }

  {
    int32_T i;

    /* RateTransition: '<S7>/Rate Transition' */
    if (tid == 0 && bump_choice_rtM->Timing.RateInteraction.TID1_2) {
      for (i = 0; i < 168; i++) {
        bump_choice_B.RateTransition[i] = bump_choice_B.Pack[i];
      }
    }
  }

  if (tid == 2) {                      /* Sample time: [0.02s, 0.0s] */
    /* Level2 S-Function Block: '<S7>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[13];
      sfcnOutputs(rts, 2);
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* ok to acquire for <S8>/S-Function */
    bump_choice_DWork.SFunction_IWORK_e.AcquireOK = 1;

    /* ok to acquire for <S10>/S-Function */
    bump_choice_DWork.SFunction_IWORK_g.AcquireOK = 1;

    /* ok to acquire for <S13>/S-Function */
    bump_choice_DWork.SFunction_IWORK_h.AcquireOK = 1;

    /* ok to acquire for <S47>/S-Function */
    bump_choice_DWork.SFunction_IWORK_d.AcquireOK = 1;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S64>/Clock'
     */
    bump_choice_B.Clock_o = bump_choice_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* SignalConversion: '<S64>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    bump_choice_B.HiddenBuf_InsertedFor_Sampleand = bump_choice_B.BehaviorBC_o5;
  }

  /* SubSystem Block: '<S64>/Sample and Hold'
   */
  if (tid == 0) {
    bump_choice_SampleandHold(bump_choice_B.HiddenBuf_InsertedFor_Sampleand,
      bump_choice_B.Clock_o, &bump_choice_B.SampleandHold,
      &bump_choice_DWork.SampleandHold,
      &bump_choice_PrevZCSigState.SampleandHold);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Sum: '<S64>/Sum' */
    bump_choice_B.Sum_p = bump_choice_B.Clock_o - bump_choice_B.SampleandHold.In;
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* UniformRandomNumber Block: '<S6>/Uniform Random Number'
     */
    bump_choice_B.UniformRandomNumber =
      bump_choice_DWork.UniformRandomNumber_RWORK.NextOutput;

    /* RelationalOperator: '<S6>/Relational Operator' incorporates:
     *  Constant: '<S6>/JackpotChance'
     */
    bump_choice_B.RelationalOperator_ka = (bump_choice_B.UniformRandomNumber >
      bump_choice_P.JackpotChance_Value);

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/RewardJackpot'
     *  Constant: '<S6>/RewardTime'
     */
    if (bump_choice_B.RelationalOperator_ka) {
      bump_choice_B.Switch_o = bump_choice_P.RewardTime_Value;
    } else {
      bump_choice_B.Switch_o = bump_choice_P.RewardJackpot_Value;
    }

    /* SignalConversion: '<S6>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    bump_choice_B.HiddenBuf_InsertedFor_Samplea_e = bump_choice_B.BehaviorBC_o5;
  }

  /* SubSystem Block: '<S6>/Sample and Hold'
   */
  if (tid == 0) {
    bump_choice_SampleandHold(bump_choice_B.HiddenBuf_InsertedFor_Samplea_e,
      bump_choice_B.Switch_o, &bump_choice_B.SampleandHold_h,
      &bump_choice_DWork.SampleandHold_h,
      &bump_choice_PrevZCSigState.SampleandHold_h);
  }

  {
    int32_T s69_iter;
    real_T tmp;
    real_T tmp_0;
    if (tid == 0) {
      /* RelationalOperator: '<S64>/Relational Operator' */
      bump_choice_B.RelationalOperator_b = (bump_choice_B.Sum_p <
        bump_choice_B.SampleandHold_h.In);

      /* DataTypeConversion: '<S6>/Data Type Conversion' */
      bump_choice_B.DataTypeConversion = (real_T)
        bump_choice_B.RelationalOperator_b;
    }

    if (tid == 0) {
      for (s69_iter = 0; s69_iter < 4; s69_iter++) {
        bump_choice_B.ForIterator = (real_T)s69_iter;

        /* Output and update for iterator system: '<S12>/For Iterator Subsystem' */

        /* Switch: '<S69>/Switch' incorporates:
         *  Constant: '<S69>/Constant2'
         */
        if (bump_choice_B.ForIterator >= bump_choice_P.Switch_Threshold_k) {
          bump_choice_B.Switch_b = bump_choice_B.BehaviorBC_o3;
        } else {
          bump_choice_B.Switch_b = bump_choice_P.Constant2_Value;
        }

        /* Level2 S-Function Block: '<S69>/ToBits1' (Byte2Bits) */
        {
          SimStruct *rts = bump_choice_rtM->childSfunctions[2];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S69>/Port A' (dopci8255) */
        {
          SimStruct *rts = bump_choice_rtM->childSfunctions[3];
          sfcnOutputs(rts, 1);
        }

        /* Sum: '<S69>/Add' incorporates:
         *  Constant: '<S69>/Constant'
         */
        bump_choice_B.Add_ks = bump_choice_B.PCIQUAD04 +
          bump_choice_P.Constant_Value_m;

        /* Sum: '<S69>/Add1' incorporates:
         *  Constant: '<S69>/Constant'
         */
        bump_choice_B.Add1_md = bump_choice_B.PCIQUAD041 +
          bump_choice_P.Constant_Value_m;

        /* Level2 S-Function Block: '<S69>/SerialConverter' (serPos) */
        {
          SimStruct *rts = bump_choice_rtM->childSfunctions[4];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S69>/ToBits' (Byte2Bits) */
        {
          SimStruct *rts = bump_choice_rtM->childSfunctions[5];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S69>/Port B' (dopci8255) */
        {
          SimStruct *rts = bump_choice_rtM->childSfunctions[6];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S69>/xPC Target  Time ' (xpctimeinfo) */
        {
          SimStruct *rts = bump_choice_rtM->childSfunctions[7];
          sfcnOutputs(rts, 1);
        }

        do {
          /* Output and update for iterator system: '<S69>/While Iterator Subsystem' */

          /* Level2 S-Function Block: '<S71>/xPC Target  Time ' (xpctimeinfo) */
          {
            SimStruct *rts = bump_choice_rtM->childSfunctions[0];
            sfcnOutputs(rts, 1);
          }

          /* Sum: '<S71>/Subtract' */
          bump_choice_B.Subtract = bump_choice_B.xPCTargetTime_b -
            bump_choice_B.xPCTargetTime;

          /* Gain: '<S71>/ScaleTouSec' */
          bump_choice_B.ScaleTouSec = bump_choice_P.ScaleTouSec_Gain *
            bump_choice_B.Subtract;

          /* RelationalOperator: '<S73>/Compare' incorporates:
           *  Constant: '<S73>/Constant'
           */
          bump_choice_B.Compare_c = (bump_choice_B.ScaleTouSec >
            bump_choice_P.Constant_Value_b);

          /* Switch: '<S71>/Switch' incorporates:
           *  Constant: '<S71>/Constant'
           *  Constant: '<S71>/Constant1'
           */
          if (bump_choice_B.Compare_c) {
            bump_choice_B.Switch_n = bump_choice_P.Constant_Value_h;
          } else {
            bump_choice_B.Switch_n = bump_choice_P.Constant1_Value;
          }

          /* Level2 S-Function Block: '<S71>/PCI-6025E ' (donipcie) */
          {
            SimStruct *rts = bump_choice_rtM->childSfunctions[1];
            sfcnOutputs(rts, 1);
          }

          /* RelationalOperator: '<S72>/Compare' incorporates:
           *  Constant: '<S72>/Constant'
           */
          bump_choice_B.Compare_b = (bump_choice_B.ScaleTouSec <=
            bump_choice_P.Constant_Value_jz);
        } while (bump_choice_B.Compare_b);
      }

      /* UnitDelay: '<S16>/y' */
      bump_choice_B.y = bump_choice_DWork.y_DSTATE;

      /* Sum: '<S16>/Add1' */
      bump_choice_B.Add1 = bump_choice_B.y - bump_choice_B.x_b;

      /* UnitDelay: '<S16>/z' */
      bump_choice_B.z = bump_choice_DWork.z_DSTATE;

      /* Sum: '<S16>/Add3' incorporates:
       *  Constant: '<S16>/rho'
       */
      bump_choice_B.Add3 = bump_choice_P.rho_Value - bump_choice_B.z;

      /* Product: '<S16>/product2' */
      bump_choice_B.product2 = bump_choice_B.x_b * bump_choice_B.Add3;

      /* Sum: '<S16>/Add2' */
      bump_choice_B.Add2 = bump_choice_B.product2 - bump_choice_B.y;

      /* Product: '<S16>/product3' incorporates:
       *  Constant: '<S16>/beta'
       */
      bump_choice_B.product3 = bump_choice_B.z * bump_choice_P.beta_Value;

      /* Product: '<S16>/product4' */
      bump_choice_B.product4 = bump_choice_B.y * bump_choice_B.x_b;

      /* Sum: '<S16>/Add4' */
      bump_choice_B.Add4 = bump_choice_B.product4 - bump_choice_B.product3;

      /* Product: '<S16>/product1' incorporates:
       *  Constant: '<S16>/sigma'
       */
      bump_choice_B.product1 = bump_choice_B.Add1 * bump_choice_P.sigma_Value;

      /* Product: '<S16>/dX' incorporates:
       *  Constant: '<S16>/timescale'
       */
      bump_choice_B.dX = bump_choice_P.timescale_Value * bump_choice_B.product1;

      /* Sum: '<S16>/AddX' */
      bump_choice_B.AddX = bump_choice_B.x_b + bump_choice_B.dX;

      /* Product: '<S16>/dY' incorporates:
       *  Constant: '<S16>/timescale'
       */
      bump_choice_B.dY = bump_choice_P.timescale_Value * bump_choice_B.Add2;

      /* Sum: '<S16>/AddX1' */
      bump_choice_B.AddX1 = bump_choice_B.y + bump_choice_B.dY;

      /* Product: '<S16>/dZ' incorporates:
       *  Constant: '<S16>/timescale'
       */
      bump_choice_B.dZ = bump_choice_P.timescale_Value * bump_choice_B.Add4;

      /* Sum: '<S16>/AddX2' */
      bump_choice_B.AddX2 = bump_choice_B.z + bump_choice_B.dZ;

      /* UnitDelay: '<S17>/y' */
      bump_choice_B.y_d = bump_choice_DWork.y_DSTATE_a;

      /* Sum: '<S17>/Add1' */
      bump_choice_B.Add1_l = bump_choice_B.y_d - bump_choice_B.x_c;

      /* UnitDelay: '<S17>/z' */
      bump_choice_B.z_i = bump_choice_DWork.z_DSTATE_n;

      /* Sum: '<S17>/Add3' incorporates:
       *  Constant: '<S17>/rho'
       */
      bump_choice_B.Add3_j = bump_choice_P.rho_Value_e - bump_choice_B.z_i;

      /* Product: '<S17>/product2' */
      bump_choice_B.product2_a = bump_choice_B.x_c * bump_choice_B.Add3_j;

      /* Sum: '<S17>/Add2' */
      bump_choice_B.Add2_p = bump_choice_B.product2_a - bump_choice_B.y_d;

      /* Product: '<S17>/product3' incorporates:
       *  Constant: '<S17>/beta'
       */
      bump_choice_B.product3_h = bump_choice_B.z_i * bump_choice_P.beta_Value_a;

      /* Product: '<S17>/product4' */
      bump_choice_B.product4_e = bump_choice_B.y_d * bump_choice_B.x_c;

      /* Sum: '<S17>/Add4' */
      bump_choice_B.Add4_c = bump_choice_B.product4_e - bump_choice_B.product3_h;

      /* Product: '<S17>/product1' incorporates:
       *  Constant: '<S17>/sigma'
       */
      bump_choice_B.product1_b = bump_choice_B.Add1_l *
        bump_choice_P.sigma_Value_g;

      /* Product: '<S17>/dX' incorporates:
       *  Constant: '<S17>/timescale'
       */
      bump_choice_B.dX_c = bump_choice_P.timescale_Value_m *
        bump_choice_B.product1_b;

      /* Sum: '<S17>/AddX' */
      bump_choice_B.AddX_h = bump_choice_B.x_c + bump_choice_B.dX_c;

      /* Product: '<S17>/dY' incorporates:
       *  Constant: '<S17>/timescale'
       */
      bump_choice_B.dY_d = bump_choice_P.timescale_Value_m *
        bump_choice_B.Add2_p;

      /* Sum: '<S17>/AddX1' */
      bump_choice_B.AddX1_b = bump_choice_B.y_d + bump_choice_B.dY_d;

      /* Product: '<S17>/dZ' incorporates:
       *  Constant: '<S17>/timescale'
       */
      bump_choice_B.dZ_f = bump_choice_P.timescale_Value_m *
        bump_choice_B.Add4_c;

      /* Sum: '<S17>/AddX2' */
      bump_choice_B.AddX2_d = bump_choice_B.z_i + bump_choice_B.dZ_f;

      /* UnitDelay: '<S18>/y' */
      bump_choice_B.y_a = bump_choice_DWork.y_DSTATE_n;

      /* Sum: '<S18>/Add1' */
      bump_choice_B.Add1_g = bump_choice_B.y_a - bump_choice_B.x_j;

      /* UnitDelay: '<S18>/z' */
      bump_choice_B.z_g = bump_choice_DWork.z_DSTATE_c;

      /* Sum: '<S18>/Add3' incorporates:
       *  Constant: '<S18>/rho'
       */
      bump_choice_B.Add3_o = bump_choice_P.rho_Value_eb - bump_choice_B.z_g;

      /* Product: '<S18>/product2' */
      bump_choice_B.product2_c = bump_choice_B.x_j * bump_choice_B.Add3_o;

      /* Sum: '<S18>/Add2' */
      bump_choice_B.Add2_f = bump_choice_B.product2_c - bump_choice_B.y_a;

      /* Product: '<S18>/product3' incorporates:
       *  Constant: '<S18>/beta'
       */
      bump_choice_B.product3_p = bump_choice_B.z_g * bump_choice_P.beta_Value_l;

      /* Product: '<S18>/product4' */
      bump_choice_B.product4_g = bump_choice_B.y_a * bump_choice_B.x_j;

      /* Sum: '<S18>/Add4' */
      bump_choice_B.Add4_g = bump_choice_B.product4_g - bump_choice_B.product3_p;

      /* Product: '<S18>/product1' incorporates:
       *  Constant: '<S18>/sigma'
       */
      bump_choice_B.product1_g = bump_choice_B.Add1_g *
        bump_choice_P.sigma_Value_j;

      /* Product: '<S18>/dX' incorporates:
       *  Constant: '<S18>/timescale'
       */
      bump_choice_B.dX_k = bump_choice_P.timescale_Value_l *
        bump_choice_B.product1_g;

      /* Sum: '<S18>/AddX' */
      bump_choice_B.AddX_n = bump_choice_B.x_j + bump_choice_B.dX_k;

      /* Product: '<S18>/dY' incorporates:
       *  Constant: '<S18>/timescale'
       */
      bump_choice_B.dY_l = bump_choice_P.timescale_Value_l *
        bump_choice_B.Add2_f;

      /* Sum: '<S18>/AddX1' */
      bump_choice_B.AddX1_a = bump_choice_B.y_a + bump_choice_B.dY_l;

      /* Product: '<S18>/dZ' incorporates:
       *  Constant: '<S18>/timescale'
       */
      bump_choice_B.dZ_o = bump_choice_P.timescale_Value_l *
        bump_choice_B.Add4_g;

      /* Sum: '<S18>/AddX2' */
      bump_choice_B.AddX2_e = bump_choice_B.z_g + bump_choice_B.dZ_o;

      /* UnitDelay: '<S19>/y' */
      bump_choice_B.y_k = bump_choice_DWork.y_DSTATE_i;

      /* Sum: '<S19>/Add1' */
      bump_choice_B.Add1_e = bump_choice_B.y_k - bump_choice_B.x_h;

      /* UnitDelay: '<S19>/z' */
      bump_choice_B.z_j = bump_choice_DWork.z_DSTATE_a;

      /* Sum: '<S19>/Add3' incorporates:
       *  Constant: '<S19>/rho'
       */
      bump_choice_B.Add3_m = bump_choice_P.rho_Value_n - bump_choice_B.z_j;

      /* Product: '<S19>/product2' */
      bump_choice_B.product2_l = bump_choice_B.x_h * bump_choice_B.Add3_m;

      /* Sum: '<S19>/Add2' */
      bump_choice_B.Add2_o = bump_choice_B.product2_l - bump_choice_B.y_k;

      /* Product: '<S19>/product3' incorporates:
       *  Constant: '<S19>/beta'
       */
      bump_choice_B.product3_d = bump_choice_B.z_j * bump_choice_P.beta_Value_c;

      /* Product: '<S19>/product4' */
      bump_choice_B.product4_f = bump_choice_B.y_k * bump_choice_B.x_h;

      /* Sum: '<S19>/Add4' */
      bump_choice_B.Add4_j = bump_choice_B.product4_f - bump_choice_B.product3_d;

      /* Product: '<S19>/product1' incorporates:
       *  Constant: '<S19>/sigma'
       */
      bump_choice_B.product1_l = bump_choice_B.Add1_e *
        bump_choice_P.sigma_Value_jm;

      /* Product: '<S19>/dX' incorporates:
       *  Constant: '<S19>/timescale'
       */
      bump_choice_B.dX_m = bump_choice_P.timescale_Value_f *
        bump_choice_B.product1_l;

      /* Sum: '<S19>/AddX' */
      bump_choice_B.AddX_j = bump_choice_B.x_h + bump_choice_B.dX_m;

      /* Product: '<S19>/dY' incorporates:
       *  Constant: '<S19>/timescale'
       */
      bump_choice_B.dY_b = bump_choice_P.timescale_Value_f *
        bump_choice_B.Add2_o;

      /* Sum: '<S19>/AddX1' */
      bump_choice_B.AddX1_d = bump_choice_B.y_k + bump_choice_B.dY_b;

      /* Product: '<S19>/dZ' incorporates:
       *  Constant: '<S19>/timescale'
       */
      bump_choice_B.dZ_m = bump_choice_P.timescale_Value_f *
        bump_choice_B.Add4_j;

      /* Sum: '<S19>/AddX2' */
      bump_choice_B.AddX2_eh = bump_choice_B.z_j + bump_choice_B.dZ_m;

      /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix Concatenation1InPort0' */
      tmp = bump_choice_B.Product1_b;
      tmp_0 = bump_choice_B.Product_f;
      bump_choice_B.MatrixConcatenation1[0] = tmp;
      bump_choice_B.MatrixConcatenation1[1] = tmp_0;

      /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix Concatenation1InPort1' */
      bump_choice_B.MatrixConcatenation1[2] = bump_choice_B.Switch[0];
      bump_choice_B.MatrixConcatenation1[3] = bump_choice_B.Switch[1];

      /* UnitDelay: '<S22>/y' */
      bump_choice_B.y_p = bump_choice_DWork.y_DSTATE_a5;

      /* Sum: '<S22>/Add1' */
      bump_choice_B.Add1_gp = bump_choice_B.y_p - bump_choice_B.x;

      /* UnitDelay: '<S22>/z' */
      bump_choice_B.z_o = bump_choice_DWork.z_DSTATE_e;

      /* Sum: '<S22>/Add3' incorporates:
       *  Constant: '<S22>/rho'
       */
      bump_choice_B.Add3_g = bump_choice_P.rho_Value_f - bump_choice_B.z_o;

      /* Product: '<S22>/product2' */
      bump_choice_B.product2_j = bump_choice_B.x * bump_choice_B.Add3_g;

      /* Sum: '<S22>/Add2' */
      bump_choice_B.Add2_k = bump_choice_B.product2_j - bump_choice_B.y_p;

      /* Product: '<S22>/product3' incorporates:
       *  Constant: '<S22>/beta'
       */
      bump_choice_B.product3_j = bump_choice_B.z_o * bump_choice_P.beta_Value_b;

      /* Product: '<S22>/product4' */
      bump_choice_B.product4_p = bump_choice_B.y_p * bump_choice_B.x;

      /* Sum: '<S22>/Add4' */
      bump_choice_B.Add4_o = bump_choice_B.product4_p - bump_choice_B.product3_j;

      /* Product: '<S22>/product1' incorporates:
       *  Constant: '<S22>/sigma'
       */
      bump_choice_B.product1_a = bump_choice_B.Add1_gp *
        bump_choice_P.sigma_Value_m;

      /* Product: '<S22>/dX' incorporates:
       *  Constant: '<S22>/timescale'
       */
      bump_choice_B.dX_b = bump_choice_P.timescale_Value_mg *
        bump_choice_B.product1_a;

      /* Sum: '<S22>/AddX' */
      bump_choice_B.AddX_m = bump_choice_B.x + bump_choice_B.dX_b;

      /* Product: '<S22>/dY' incorporates:
       *  Constant: '<S22>/timescale'
       */
      bump_choice_B.dY_l3 = bump_choice_P.timescale_Value_mg *
        bump_choice_B.Add2_k;

      /* Sum: '<S22>/AddX1' */
      bump_choice_B.AddX1_l = bump_choice_B.y_p + bump_choice_B.dY_l3;

      /* Product: '<S22>/dZ' incorporates:
       *  Constant: '<S22>/timescale'
       */
      bump_choice_B.dZ_l = bump_choice_P.timescale_Value_mg *
        bump_choice_B.Add4_o;

      /* Sum: '<S22>/AddX2' */
      bump_choice_B.AddX2_l = bump_choice_B.z_o + bump_choice_B.dZ_l;

      /* UnitDelay: '<S23>/y' */
      bump_choice_B.y_am = bump_choice_DWork.y_DSTATE_ae;

      /* Sum: '<S23>/Add1' */
      bump_choice_B.Add1_h = bump_choice_B.y_am - bump_choice_B.x_e;

      /* UnitDelay: '<S23>/z' */
      bump_choice_B.z_e = bump_choice_DWork.z_DSTATE_p;

      /* Sum: '<S23>/Add3' incorporates:
       *  Constant: '<S23>/rho'
       */
      bump_choice_B.Add3_f = bump_choice_P.rho_Value_b - bump_choice_B.z_e;

      /* Product: '<S23>/product2' */
      bump_choice_B.product2_n = bump_choice_B.x_e * bump_choice_B.Add3_f;

      /* Sum: '<S23>/Add2' */
      bump_choice_B.Add2_c = bump_choice_B.product2_n - bump_choice_B.y_am;

      /* Product: '<S23>/product3' incorporates:
       *  Constant: '<S23>/beta'
       */
      bump_choice_B.product3_ho = bump_choice_B.z_e * bump_choice_P.beta_Value_m;

      /* Product: '<S23>/product4' */
      bump_choice_B.product4_p1 = bump_choice_B.y_am * bump_choice_B.x_e;

      /* Sum: '<S23>/Add4' */
      bump_choice_B.Add4_e = bump_choice_B.product4_p1 -
        bump_choice_B.product3_ho;

      /* Product: '<S23>/product1' incorporates:
       *  Constant: '<S23>/sigma'
       */
      bump_choice_B.product1_e = bump_choice_B.Add1_h *
        bump_choice_P.sigma_Value_j0;

      /* Product: '<S23>/dX' incorporates:
       *  Constant: '<S23>/timescale'
       */
      bump_choice_B.dX_h = bump_choice_P.timescale_Value_e *
        bump_choice_B.product1_e;

      /* Sum: '<S23>/AddX' */
      bump_choice_B.AddX_i = bump_choice_B.x_e + bump_choice_B.dX_h;

      /* Product: '<S23>/dY' incorporates:
       *  Constant: '<S23>/timescale'
       */
      bump_choice_B.dY_d5 = bump_choice_P.timescale_Value_e *
        bump_choice_B.Add2_c;

      /* Sum: '<S23>/AddX1' */
      bump_choice_B.AddX1_bb = bump_choice_B.y_am + bump_choice_B.dY_d5;

      /* Product: '<S23>/dZ' incorporates:
       *  Constant: '<S23>/timescale'
       */
      bump_choice_B.dZ_c = bump_choice_P.timescale_Value_e *
        bump_choice_B.Add4_e;

      /* Sum: '<S23>/AddX2' */
      bump_choice_B.AddX2_ec = bump_choice_B.z_e + bump_choice_B.dZ_c;

      /* UnitDelay: '<S24>/y' */
      bump_choice_B.y_kr = bump_choice_DWork.y_DSTATE_l;

      /* Sum: '<S24>/Add1' */
      bump_choice_B.Add1_lc = bump_choice_B.y_kr - bump_choice_B.x_et;

      /* UnitDelay: '<S24>/z' */
      bump_choice_B.z_n = bump_choice_DWork.z_DSTATE_m;

      /* Sum: '<S24>/Add3' incorporates:
       *  Constant: '<S24>/rho'
       */
      bump_choice_B.Add3_p = bump_choice_P.rho_Value_h - bump_choice_B.z_n;

      /* Product: '<S24>/product2' */
      bump_choice_B.product2_f = bump_choice_B.x_et * bump_choice_B.Add3_p;

      /* Sum: '<S24>/Add2' */
      bump_choice_B.Add2_c5 = bump_choice_B.product2_f - bump_choice_B.y_kr;

      /* Product: '<S24>/product3' incorporates:
       *  Constant: '<S24>/beta'
       */
      bump_choice_B.product3_f = bump_choice_B.z_n * bump_choice_P.beta_Value_n;

      /* Product: '<S24>/product4' */
      bump_choice_B.product4_et = bump_choice_B.y_kr * bump_choice_B.x_et;

      /* Sum: '<S24>/Add4' */
      bump_choice_B.Add4_ep = bump_choice_B.product4_et -
        bump_choice_B.product3_f;

      /* Product: '<S24>/product1' incorporates:
       *  Constant: '<S24>/sigma'
       */
      bump_choice_B.product1_f = bump_choice_B.Add1_lc *
        bump_choice_P.sigma_Value_c;

      /* Product: '<S24>/dX' incorporates:
       *  Constant: '<S24>/timescale'
       */
      bump_choice_B.dX_l = bump_choice_P.timescale_Value_d *
        bump_choice_B.product1_f;

      /* Sum: '<S24>/AddX' */
      bump_choice_B.AddX_l = bump_choice_B.x_et + bump_choice_B.dX_l;

      /* Product: '<S24>/dY' incorporates:
       *  Constant: '<S24>/timescale'
       */
      bump_choice_B.dY_n = bump_choice_P.timescale_Value_d *
        bump_choice_B.Add2_c5;

      /* Sum: '<S24>/AddX1' */
      bump_choice_B.AddX1_dm = bump_choice_B.y_kr + bump_choice_B.dY_n;

      /* Product: '<S24>/dZ' incorporates:
       *  Constant: '<S24>/timescale'
       */
      bump_choice_B.dZ_p = bump_choice_P.timescale_Value_d *
        bump_choice_B.Add4_ep;

      /* Sum: '<S24>/AddX2' */
      bump_choice_B.AddX2_j = bump_choice_B.z_n + bump_choice_B.dZ_p;

      /* UnitDelay: '<S25>/y' */
      bump_choice_B.y_f = bump_choice_DWork.y_DSTATE_f;

      /* Sum: '<S25>/Add1' */
      bump_choice_B.Add1_m = bump_choice_B.y_f - bump_choice_B.x_d;

      /* UnitDelay: '<S25>/z' */
      bump_choice_B.z_n3 = bump_choice_DWork.z_DSTATE_f;

      /* Sum: '<S25>/Add3' incorporates:
       *  Constant: '<S25>/rho'
       */
      bump_choice_B.Add3_k = bump_choice_P.rho_Value_a - bump_choice_B.z_n3;

      /* Product: '<S25>/product2' */
      bump_choice_B.product2_b = bump_choice_B.x_d * bump_choice_B.Add3_k;

      /* Sum: '<S25>/Add2' */
      bump_choice_B.Add2_k3 = bump_choice_B.product2_b - bump_choice_B.y_f;

      /* Product: '<S25>/product3' incorporates:
       *  Constant: '<S25>/beta'
       */
      bump_choice_B.product3_c = bump_choice_B.z_n3 * bump_choice_P.beta_Value_g;

      /* Product: '<S25>/product4' */
      bump_choice_B.product4_eg = bump_choice_B.y_f * bump_choice_B.x_d;

      /* Sum: '<S25>/Add4' */
      bump_choice_B.Add4_l = bump_choice_B.product4_eg -
        bump_choice_B.product3_c;

      /* Product: '<S25>/product1' incorporates:
       *  Constant: '<S25>/sigma'
       */
      bump_choice_B.product1_p = bump_choice_B.Add1_m *
        bump_choice_P.sigma_Value_l;

      /* Product: '<S25>/dX' incorporates:
       *  Constant: '<S25>/timescale'
       */
      bump_choice_B.dX_h4 = bump_choice_P.timescale_Value_j *
        bump_choice_B.product1_p;

      /* Sum: '<S25>/AddX' */
      bump_choice_B.AddX_c = bump_choice_B.x_d + bump_choice_B.dX_h4;

      /* Product: '<S25>/dY' incorporates:
       *  Constant: '<S25>/timescale'
       */
      bump_choice_B.dY_be = bump_choice_P.timescale_Value_j *
        bump_choice_B.Add2_k3;

      /* Sum: '<S25>/AddX1' */
      bump_choice_B.AddX1_c = bump_choice_B.y_f + bump_choice_B.dY_be;

      /* Product: '<S25>/dZ' incorporates:
       *  Constant: '<S25>/timescale'
       */
      bump_choice_B.dZ_ft = bump_choice_P.timescale_Value_j *
        bump_choice_B.Add4_l;

      /* Sum: '<S25>/AddX2' */
      bump_choice_B.AddX2_c = bump_choice_B.z_n3 + bump_choice_B.dZ_ft;
    }
  }
}

/* Model update function */
void bump_choice_update(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S30>/Memory' */
    bump_choice_DWork.Memory_PreviousInput = bump_choice_B.LogicalOperator;

    /* Update for Memory: '<S4>/Memory' */
    bump_choice_DWork.Memory_PreviousInput_i = bump_choice_B.LogicalOperator1_it;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S66>/Derivative' */
    {
      real_T timeStampA = bump_choice_DWork.Derivative_RWORK.TimeStampA;
      real_T timeStampB = bump_choice_DWork.Derivative_RWORK.TimeStampB;
      real_T *lastBank = &bump_choice_DWork.Derivative_RWORK.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = bump_choice_rtM->Timing.t[0];
      *lastBank++ = bump_choice_B.DigitalFilter2;
    }

    /* Derivative Block: '<S67>/Derivative' */
    {
      real_T timeStampA = bump_choice_DWork.Derivative_RWORK_e.TimeStampA;
      real_T timeStampB = bump_choice_DWork.Derivative_RWORK_e.TimeStampB;
      real_T *lastBank = &bump_choice_DWork.Derivative_RWORK_e.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = bump_choice_rtM->Timing.t[0];
      *lastBank++ = bump_choice_B.DigitalFilter2_c;
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S42>/Memory' */
    bump_choice_DWork.Memory_PreviousInput_d = bump_choice_B.LogicalOperator_e;

    /* Update for Memory: '<S46>/Memory' */
    bump_choice_DWork.Memory_PreviousInput_dp = bump_choice_B.LogicalOperator_n;

    /* Update for UnitDelay: '<S60>/Delay Input1' */
    bump_choice_DWork.DelayInput1_DSTATE = bump_choice_B.Compare_k;

    /* Update for Memory: '<S44>/Memory' */
    bump_choice_DWork.Memory_PreviousInput_b = bump_choice_B.LogicalOperator_c;

    /* Update for UnitDelay: '<S45>/Delay Input1' */
    bump_choice_DWork.DelayInput1_DSTATE_h = bump_choice_B.Compare_do;

    /* Update for UnitDelay: '<S38>/Delay Input1' */
    bump_choice_DWork.DelayInput1_DSTATE_f = bump_choice_B.Compare_ez;

    /* Update for Memory: '<S43>/Memory' */
    bump_choice_DWork.Memory_PreviousInput_n = bump_choice_B.LogicalOperator_nd;

    /* Update for UnitDelay: '<S37>/Delay Input1' */
    bump_choice_DWork.DelayInput1_DSTATE_l = bump_choice_B.Compare_dc;

    /* Update for Memory: '<S41>/Memory' */
    bump_choice_DWork.Memory_PreviousInput_iw = bump_choice_B.Logic[0];

    /* Update for UnitDelay: '<S22>/x' */
    bump_choice_DWork.x_DSTATE = bump_choice_B.AddX_m;

    /* Update for UnitDelay: '<S23>/x' */
    bump_choice_DWork.x_DSTATE_n = bump_choice_B.AddX_i;

    /* Update for UnitDelay: '<S24>/x' */
    bump_choice_DWork.x_DSTATE_i = bump_choice_B.AddX_l;

    /* Update for UnitDelay: '<S25>/x' */
    bump_choice_DWork.x_DSTATE_in = bump_choice_B.AddX_c;

    /* Update for UnitDelay: '<S16>/x' */
    bump_choice_DWork.x_DSTATE_m = bump_choice_B.AddX;

    /* Update for UnitDelay: '<S17>/x' */
    bump_choice_DWork.x_DSTATE_h = bump_choice_B.AddX_h;

    /* Update for UnitDelay: '<S18>/x' */
    bump_choice_DWork.x_DSTATE_o = bump_choice_B.AddX_n;

    /* Update for UnitDelay: '<S19>/x' */
    bump_choice_DWork.x_DSTATE_d = bump_choice_B.AddX_j;

    /* Level2 S-Function Block: '<Root>/Behavior BC' (mastercon_bc) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[11];
      sfcnUpdate(rts, 1);
      if (ssGetErrorStatus(rts) != NULL)
        return;
    }

    /* UniformRandomNumber Block: '<S6>/Uniform Random Number' */
    bump_choice_DWork.UniformRandomNumber_RWORK.NextOutput = rt_Urand((uint32_T *)
      &bump_choice_DWork.UniformRandomNumber_IWORK.RandSeed) *
      (bump_choice_P.UniformRandomNumber_Max -
       bump_choice_P.UniformRandomNumber_Min) +
      bump_choice_P.UniformRandomNumber_Min;
  }

  if (tid == 0) {
    /* Update for UnitDelay: '<S16>/y' */
    bump_choice_DWork.y_DSTATE = bump_choice_B.AddX1;

    /* Update for UnitDelay: '<S16>/z' */
    bump_choice_DWork.z_DSTATE = bump_choice_B.AddX2;

    /* Update for UnitDelay: '<S17>/y' */
    bump_choice_DWork.y_DSTATE_a = bump_choice_B.AddX1_b;

    /* Update for UnitDelay: '<S17>/z' */
    bump_choice_DWork.z_DSTATE_n = bump_choice_B.AddX2_d;

    /* Update for UnitDelay: '<S18>/y' */
    bump_choice_DWork.y_DSTATE_n = bump_choice_B.AddX1_a;

    /* Update for UnitDelay: '<S18>/z' */
    bump_choice_DWork.z_DSTATE_c = bump_choice_B.AddX2_e;

    /* Update for UnitDelay: '<S19>/y' */
    bump_choice_DWork.y_DSTATE_i = bump_choice_B.AddX1_d;

    /* Update for UnitDelay: '<S19>/z' */
    bump_choice_DWork.z_DSTATE_a = bump_choice_B.AddX2_eh;

    /* Update for UnitDelay: '<S22>/y' */
    bump_choice_DWork.y_DSTATE_a5 = bump_choice_B.AddX1_l;

    /* Update for UnitDelay: '<S22>/z' */
    bump_choice_DWork.z_DSTATE_e = bump_choice_B.AddX2_l;

    /* Update for UnitDelay: '<S23>/y' */
    bump_choice_DWork.y_DSTATE_ae = bump_choice_B.AddX1_bb;

    /* Update for UnitDelay: '<S23>/z' */
    bump_choice_DWork.z_DSTATE_p = bump_choice_B.AddX2_ec;

    /* Update for UnitDelay: '<S24>/y' */
    bump_choice_DWork.y_DSTATE_l = bump_choice_B.AddX1_dm;

    /* Update for UnitDelay: '<S24>/z' */
    bump_choice_DWork.z_DSTATE_m = bump_choice_B.AddX2_j;

    /* Update for UnitDelay: '<S25>/y' */
    bump_choice_DWork.y_DSTATE_f = bump_choice_B.AddX1_c;

    /* Update for UnitDelay: '<S25>/z' */
    bump_choice_DWork.z_DSTATE_f = bump_choice_B.AddX2_c;
  }

  /* Update absolute time for base rate */
  if (tid == 0) {
    if (!(++bump_choice_rtM->Timing.clockTick0))
      ++bump_choice_rtM->Timing.clockTickH0;
    bump_choice_rtM->Timing.t[0] = bump_choice_rtM->Timing.clockTick0 *
      bump_choice_rtM->Timing.stepSize0 + bump_choice_rtM->Timing.clockTickH0 *
      bump_choice_rtM->Timing.stepSize0 * 4294967296.0;
  }

  if (tid == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++bump_choice_rtM->Timing.clockTick1))
      ++bump_choice_rtM->Timing.clockTickH1;
    bump_choice_rtM->Timing.t[1] = bump_choice_rtM->Timing.clockTick1 *
      bump_choice_rtM->Timing.stepSize1 + bump_choice_rtM->Timing.clockTickH1 *
      bump_choice_rtM->Timing.stepSize1 * 4294967296.0;
  }

  if (tid == 2) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    if (!(++bump_choice_rtM->Timing.clockTick2))
      ++bump_choice_rtM->Timing.clockTickH2;
    bump_choice_rtM->Timing.t[2] = bump_choice_rtM->Timing.clockTick2 *
      bump_choice_rtM->Timing.stepSize2 + bump_choice_rtM->Timing.clockTickH2 *
      bump_choice_rtM->Timing.stepSize2 * 4294967296.0;
  }
}

/* Model initialize function */
void bump_choice_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */
  /* initialize real-time model */
  (void) memset((char_T *)bump_choice_rtM,0,
                sizeof(rtModel_bump_choice));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&bump_choice_rtM->solverInfo,
                          &bump_choice_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&bump_choice_rtM->solverInfo, &rtmGetTPtr(bump_choice_rtM));
    rtsiSetStepSizePtr(&bump_choice_rtM->solverInfo,
                       &bump_choice_rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&bump_choice_rtM->solverInfo, (&rtmGetErrorStatus
      (bump_choice_rtM)));
    rtsiSetRTModelPtr(&bump_choice_rtM->solverInfo, bump_choice_rtM);
  }

  rtsiSetSimTimeStep(&bump_choice_rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&bump_choice_rtM->solverInfo,"FixedStepDiscrete");
  bump_choice_rtM->solverInfoPtr = (&bump_choice_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = bump_choice_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    bump_choice_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    bump_choice_rtM->Timing.sampleTimes =
      (&bump_choice_rtM->Timing.sampleTimesArray[0]);
    bump_choice_rtM->Timing.offsetTimes =
      (&bump_choice_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    bump_choice_rtM->Timing.sampleTimes[0] = (0.0);
    bump_choice_rtM->Timing.sampleTimes[1] = (0.001);
    bump_choice_rtM->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    bump_choice_rtM->Timing.offsetTimes[0] = (0.0);
    bump_choice_rtM->Timing.offsetTimes[1] = (0.0);
    bump_choice_rtM->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(bump_choice_rtM, &bump_choice_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = bump_choice_rtM->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = bump_choice_rtM->Timing.perTaskSampleHitsArray;
    bump_choice_rtM->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    bump_choice_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(bump_choice_rtM, -1);
  bump_choice_rtM->Timing.stepSize0 = 0.001;
  bump_choice_rtM->Timing.stepSize1 = 0.001;
  bump_choice_rtM->Timing.stepSize2 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    bump_choice_rtM->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(bump_choice_rtM->rtwLogInfo, 2);
    rtliSetLogMaxRows(bump_choice_rtM->rtwLogInfo, 0);
    rtliSetLogDecimation(bump_choice_rtM->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(bump_choice_rtM->rtwLogInfo, "rt_");
    rtliSetLogT(bump_choice_rtM->rtwLogInfo, "tout");
    rtliSetLogX(bump_choice_rtM->rtwLogInfo, "xout");
    rtliSetLogXFinal(bump_choice_rtM->rtwLogInfo, "");
    rtliSetSigLog(bump_choice_rtM->rtwLogInfo, "");

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
        "bump_choice/Velocity Calculation/Pos2VelX/Digital Filter2",
        "bump_choice/Velocity Calculation/Pos2VelX/Digital Filter",
        "bump_choice/Velocity Calculation/Pos2VelY/Digital Filter2",
        "bump_choice/Velocity Calculation/Pos2VelY/Digital Filter",
        "bump_choice/Force Generator/LorentzForce/Lorentz/x",
        "bump_choice/Force Generator/LorentzForce/Lorentz1/x",
        "bump_choice/Force Generator/LorentzForce/Lorentz2/x",
        "bump_choice/Force Generator/LorentzForce/Lorentz3/x",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz/x",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz1/x",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz2/x",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz3/x",
        "bump_choice/Behavior BC",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz/y",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz/z",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz1/y",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz1/z",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz2/y",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz2/z",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz3/y",
        "bump_choice/Catch Force Generator/LorentzForce/Lorentz3/z",
        "bump_choice/Force Generator/LorentzForce/Lorentz/y",
        "bump_choice/Force Generator/LorentzForce/Lorentz/z",
        "bump_choice/Force Generator/LorentzForce/Lorentz1/y",
        "bump_choice/Force Generator/LorentzForce/Lorentz1/z",
        "bump_choice/Force Generator/LorentzForce/Lorentz2/y",
        "bump_choice/Force Generator/LorentzForce/Lorentz2/z",
        "bump_choice/Force Generator/LorentzForce/Lorentz3/y",
        "bump_choice/Force Generator/LorentzForce/Lorentz3/z",
        "bump_choice/Recentering Subsystem/Timer/Detect Fall\nNonpositive/Delay Input1",
        "bump_choice/Recentering Subsystem/Start Moving/Delay Input1",
        "bump_choice/Recentering Subsystem/Falling Edge1/Delay Input1",
        "bump_choice/Recentering Subsystem/Falling Edge/Delay Input1" };

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

      rtliSetLogXSignalInfo(bump_choice_rtM->rtwLogInfo,
                            &rt_LoggedStateSignalInfo);
    }

    {
      static void * rt_LoggedStateSignalPtrs[33];
      rt_LoggedStateSignalPtrs[0] = (void*)
        &bump_choice_DWork.DigitalFilter2_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[1] = (void*)
        &bump_choice_DWork.DigitalFilter_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[2] = (void*)
        &bump_choice_DWork.DigitalFilter2_FILT_STATES_a[0];
      rt_LoggedStateSignalPtrs[3] = (void*)
        &bump_choice_DWork.DigitalFilter_FILT_STATES_e[0];
      rt_LoggedStateSignalPtrs[4] = (void*)&bump_choice_DWork.x_DSTATE;
      rt_LoggedStateSignalPtrs[5] = (void*)&bump_choice_DWork.x_DSTATE_n;
      rt_LoggedStateSignalPtrs[6] = (void*)&bump_choice_DWork.x_DSTATE_i;
      rt_LoggedStateSignalPtrs[7] = (void*)&bump_choice_DWork.x_DSTATE_in;
      rt_LoggedStateSignalPtrs[8] = (void*)&bump_choice_DWork.x_DSTATE_m;
      rt_LoggedStateSignalPtrs[9] = (void*)&bump_choice_DWork.x_DSTATE_h;
      rt_LoggedStateSignalPtrs[10] = (void*)&bump_choice_DWork.x_DSTATE_o;
      rt_LoggedStateSignalPtrs[11] = (void*)&bump_choice_DWork.x_DSTATE_d;
      rt_LoggedStateSignalPtrs[12] = (void*)&bump_choice_DWork.BehaviorBC_DSTATE;
      rt_LoggedStateSignalPtrs[13] = (void*)&bump_choice_DWork.y_DSTATE;
      rt_LoggedStateSignalPtrs[14] = (void*)&bump_choice_DWork.z_DSTATE;
      rt_LoggedStateSignalPtrs[15] = (void*)&bump_choice_DWork.y_DSTATE_a;
      rt_LoggedStateSignalPtrs[16] = (void*)&bump_choice_DWork.z_DSTATE_n;
      rt_LoggedStateSignalPtrs[17] = (void*)&bump_choice_DWork.y_DSTATE_n;
      rt_LoggedStateSignalPtrs[18] = (void*)&bump_choice_DWork.z_DSTATE_c;
      rt_LoggedStateSignalPtrs[19] = (void*)&bump_choice_DWork.y_DSTATE_i;
      rt_LoggedStateSignalPtrs[20] = (void*)&bump_choice_DWork.z_DSTATE_a;
      rt_LoggedStateSignalPtrs[21] = (void*)&bump_choice_DWork.y_DSTATE_a5;
      rt_LoggedStateSignalPtrs[22] = (void*)&bump_choice_DWork.z_DSTATE_e;
      rt_LoggedStateSignalPtrs[23] = (void*)&bump_choice_DWork.y_DSTATE_ae;
      rt_LoggedStateSignalPtrs[24] = (void*)&bump_choice_DWork.z_DSTATE_p;
      rt_LoggedStateSignalPtrs[25] = (void*)&bump_choice_DWork.y_DSTATE_l;
      rt_LoggedStateSignalPtrs[26] = (void*)&bump_choice_DWork.z_DSTATE_m;
      rt_LoggedStateSignalPtrs[27] = (void*)&bump_choice_DWork.y_DSTATE_f;
      rt_LoggedStateSignalPtrs[28] = (void*)&bump_choice_DWork.z_DSTATE_f;
      rt_LoggedStateSignalPtrs[29] = (void*)
        &bump_choice_DWork.DelayInput1_DSTATE;
      rt_LoggedStateSignalPtrs[30] = (void*)
        &bump_choice_DWork.DelayInput1_DSTATE_h;
      rt_LoggedStateSignalPtrs[31] = (void*)
        &bump_choice_DWork.DelayInput1_DSTATE_f;
      rt_LoggedStateSignalPtrs[32] = (void*)
        &bump_choice_DWork.DelayInput1_DSTATE_l;
      rtliSetLogXSignalPtrs(bump_choice_rtM->rtwLogInfo, (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
    }

    rtliSetLogY(bump_choice_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(bump_choice_rtM->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(bump_choice_rtM->rtwLogInfo, NULL);
  }

  /* external mode info */
  bump_choice_rtM->Sizes.checksums[0] = (2013274219U);
  bump_choice_rtM->Sizes.checksums[1] = (2855417463U);
  bump_choice_rtM->Sizes.checksums[2] = (3058639876U);
  bump_choice_rtM->Sizes.checksums[3] = (2880828891U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[34];
    bump_choice_rtM->extModeInfo = (&rt_ExtModeInfo);
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
      &bump_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &bump_choice_DWork.EnabledSubsystem_p.EnabledSubsystem_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &bump_choice_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &bump_choice_DWork.EnabledSubsystem_e.EnabledSubsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &bump_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)
      &bump_choice_DWork.SampleandHold_h.SampleandHold_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &bump_choice_DWork.SampleandHold.SampleandHold_SubsysRanBC;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &bump_choice_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, bump_choice_rtM->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(bump_choice_rtM));
  }

  bump_choice_rtM->solverInfoPtr = (&bump_choice_rtM->solverInfo);
  bump_choice_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&bump_choice_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&bump_choice_rtM->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  bump_choice_rtM->ModelData.blockIO = ((void *) &bump_choice_B);
  (void) memset(((void *) &bump_choice_B),0,
                sizeof(BlockIO_bump_choice));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&bump_choice_B.Clock);
    for (i = 0; i < 242; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&bump_choice_B.ForIterator);
    for (i = 0; i < 90; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    ((real_T*)&bump_choice_B.SampleandHold.In)[0] = 0.0;
    ((real_T*)&bump_choice_B.SampleandHold_h.In)[0] = 0.0;
    ((real_T*)&bump_choice_B.EnabledSubsystem_l.In1)[0] = 0.0;
    ((real_T*)&bump_choice_B.EnabledSubsystem_e.In1)[0] = 0.0;
    ((real_T*)&bump_choice_B.EnabledSubsystem_o.In1)[0] = 0.0;
    ((real_T*)&bump_choice_B.EnabledSubsystem_p.In1)[0] = 0.0;
    ((real_T*)&bump_choice_B.EnabledSubsystem.In1)[0] = 0.0;
  }

  /* parameters */
  bump_choice_rtM->ModelData.defaultParam = ((real_T *) &bump_choice_P);

  /* states (dwork) */
  bump_choice_rtM->Work.dwork = ((void *) &bump_choice_DWork);
  (void) memset((char_T *) &bump_choice_DWork,0,
                sizeof(D_Work_bump_choice));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &bump_choice_DWork.DigitalFilter2_FILT_STATES
      [0];
    for (i = 0; i < 154; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    bump_choice_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    bump_choice_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  bump_choice_InitializeDataMapInfo(bump_choice_rtM);

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &bump_choice_rtM->NonInlinedSFcns.sfcnInfo;
    bump_choice_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(bump_choice_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &bump_choice_rtM->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(bump_choice_rtM));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(bump_choice_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(bump_choice_rtM));
    rtssSetStepSizePtr(sfcnInfo, &bump_choice_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(bump_choice_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &bump_choice_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &bump_choice_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &bump_choice_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &bump_choice_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &bump_choice_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &bump_choice_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &bump_choice_rtM->solverInfoPtr);
  }

  bump_choice_rtM->Sizes.numSFcns = (14);

  /* register each child */
  {
    (void) memset((void *)&bump_choice_rtM->NonInlinedSFcns.childSFunctions[0],0,
                  14*sizeof(SimStruct));
    bump_choice_rtM->childSfunctions =
      (&bump_choice_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 14; i++) {
        bump_choice_rtM->childSfunctions[i] =
          (&bump_choice_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: bump_choice/<S71>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &bump_choice_B.xPCTargetTime_b));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "bump_choice/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,bump_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_choice_P.xPCTargetTime_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_choice_P.xPCTargetTime_P2_Size[0]);
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

    /* Level2 S-Function Block: bump_choice/<S71>/PCI-6025E  (donipcie) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &bump_choice_B.Switch_n;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &bump_choice_B.DataTypeConversion;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts,
                "bump_choice/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ");
      ssSetRTModel(rts,bump_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_choice_P.PCI6025E_P1_Size_g[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_choice_P.PCI6025E_P2_Size_j[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_choice_P.PCI6025E_P3_Size_i[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_choice_P.PCI6025E_P4_Size_j[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_choice_P.PCI6025E_P5_Size_h[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_choice_P.PCI6025E_P6_Size_c[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_choice_P.PCI6025E_P7_Size_i[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_choice_DWork.PCI6025E_IWORK_j[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn1.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_choice_DWork.PCI6025E_IWORK_j[0]);
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

    /* Level2 S-Function Block: bump_choice/<S69>/ToBits1 (Byte2Bits) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &bump_choice_B.Switch_b;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_choice_B.ToBits1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &bump_choice_B.ToBits1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &bump_choice_B.ToBits1_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &bump_choice_B.ToBits1_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &bump_choice_B.ToBits1_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &bump_choice_B.ToBits1_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &bump_choice_B.ToBits1_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &bump_choice_B.ToBits1_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits1");
      ssSetPath(rts,
                "bump_choice/XY Position Subsystem/For Iterator Subsystem/ToBits1");
      ssSetRTModel(rts,bump_choice_rtM);
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

    /* Level2 S-Function Block: bump_choice/<S69>/Port A (dopci8255) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &bump_choice_B.ToBits1_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &bump_choice_B.ToBits1_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs2;
          sfcnUPtrs[0] = &bump_choice_B.ToBits1_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs3;
          sfcnUPtrs[0] = &bump_choice_B.ToBits1_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs4;
          sfcnUPtrs[0] = &bump_choice_B.ToBits1_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs5;
          sfcnUPtrs[0] = &bump_choice_B.ToBits1_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs6;
          sfcnUPtrs[0] = &bump_choice_B.ToBits1_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn3.UPtrs7;
          sfcnUPtrs[0] = &bump_choice_B.ToBits1_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port A");
      ssSetPath(rts,
                "bump_choice/XY Position Subsystem/For Iterator Subsystem/Port A");
      ssSetRTModel(rts,bump_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_choice_P.PortA_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_choice_P.PortA_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_choice_P.PortA_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_choice_P.PortA_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_choice_P.PortA_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_choice_P.PortA_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_choice_P.PortA_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&bump_choice_P.PortA_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&bump_choice_P.PortA_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_choice_DWork.PortA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn3.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_choice_DWork.PortA_IWORK[0]);
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

    /* Level2 S-Function Block: bump_choice/<S69>/SerialConverter (serPos) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &bump_choice_B.ForIterator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &bump_choice_B.Add_ks;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn4.UPtrs2;
          sfcnUPtrs[0] = &bump_choice_B.Add1_md;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &bump_choice_B.SerialConverter));
        }
      }

      /* path info */
      ssSetModelName(rts, "SerialConverter");
      ssSetPath(rts,
                "bump_choice/XY Position Subsystem/For Iterator Subsystem/SerialConverter");
      ssSetRTModel(rts,bump_choice_rtM);
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

    /* Level2 S-Function Block: bump_choice/<S69>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[5]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &bump_choice_B.SerialConverter;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_choice_B.ToBits_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &bump_choice_B.ToBits_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &bump_choice_B.ToBits_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &bump_choice_B.ToBits_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &bump_choice_B.ToBits_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &bump_choice_B.ToBits_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &bump_choice_B.ToBits_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &bump_choice_B.ToBits_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts,
                "bump_choice/XY Position Subsystem/For Iterator Subsystem/ToBits");
      ssSetRTModel(rts,bump_choice_rtM);
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

    /* Level2 S-Function Block: bump_choice/<S69>/Port B (dopci8255) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[6]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &bump_choice_B.ToBits_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &bump_choice_B.ToBits_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs2;
          sfcnUPtrs[0] = &bump_choice_B.ToBits_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs3;
          sfcnUPtrs[0] = &bump_choice_B.ToBits_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs4;
          sfcnUPtrs[0] = &bump_choice_B.ToBits_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs5;
          sfcnUPtrs[0] = &bump_choice_B.ToBits_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs6;
          sfcnUPtrs[0] = &bump_choice_B.ToBits_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn6.UPtrs7;
          sfcnUPtrs[0] = &bump_choice_B.ToBits_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port B");
      ssSetPath(rts,
                "bump_choice/XY Position Subsystem/For Iterator Subsystem/Port B");
      ssSetRTModel(rts,bump_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_choice_P.PortB_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_choice_P.PortB_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_choice_P.PortB_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_choice_P.PortB_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_choice_P.PortB_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_choice_P.PortB_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_choice_P.PortB_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&bump_choice_P.PortB_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&bump_choice_P.PortB_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_choice_DWork.PortB_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn6.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_choice_DWork.PortB_IWORK[0]);
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

    /* Level2 S-Function Block: bump_choice/<S69>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[7]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_choice_B.xPCTargetTime));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "bump_choice/XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,bump_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_choice_P.xPCTargetTime_P1_Size_l
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_choice_P.xPCTargetTime_P2_Size_c
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

    /* Level2 S-Function Block: bump_choice/<S12>/PCI-QUAD04  (enccbcioquadcount) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[8]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_choice_B.PCIQUAD04));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 ");
      ssSetPath(rts, "bump_choice/XY Position Subsystem/PCI-QUAD04 ");
      ssSetRTModel(rts,bump_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_choice_P.PCIQUAD04_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_choice_P.PCIQUAD04_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_choice_P.PCIQUAD04_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_choice_P.PCIQUAD04_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_choice_P.PCIQUAD04_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_choice_P.PCIQUAD04_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_choice_P.PCIQUAD04_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&bump_choice_P.PCIQUAD04_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&bump_choice_P.PCIQUAD04_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&bump_choice_P.PCIQUAD04_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&bump_choice_P.PCIQUAD04_P11_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_choice_DWork.PCIQUAD04_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn8.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_choice_DWork.PCIQUAD04_IWORK);
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

    /* Level2 S-Function Block: bump_choice/<S12>/PCI-QUAD04 1 (enccbcioquadcount) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[9]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_choice_B.PCIQUAD041));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-QUAD04 1");
      ssSetPath(rts, "bump_choice/XY Position Subsystem/PCI-QUAD04 1");
      ssSetRTModel(rts,bump_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 11);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_choice_P.PCIQUAD041_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_choice_P.PCIQUAD041_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_choice_P.PCIQUAD041_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_choice_P.PCIQUAD041_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_choice_P.PCIQUAD041_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_choice_P.PCIQUAD041_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_choice_P.PCIQUAD041_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&bump_choice_P.PCIQUAD041_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&bump_choice_P.PCIQUAD041_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&bump_choice_P.PCIQUAD041_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&bump_choice_P.PCIQUAD041_P11_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_choice_DWork.PCIQUAD041_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn9.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_choice_DWork.PCIQUAD041_IWORK);
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

    /* Level2 S-Function Block: bump_choice/<S9>/PCI-6025E AD (adnipcie) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[10]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[10]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &bump_choice_B.PCI6025EAD_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &bump_choice_B.PCI6025EAD_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E AD");
      ssSetPath(rts, "bump_choice/Velocity Calculation/PCI-6025E AD");
      ssSetRTModel(rts,bump_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_choice_P.PCI6025EAD_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_choice_P.PCI6025EAD_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_choice_P.PCI6025EAD_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_choice_P.PCI6025EAD_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_choice_P.PCI6025EAD_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_choice_P.PCI6025EAD_P6_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &bump_choice_DWork.PCI6025EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &bump_choice_DWork.PCI6025EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn10.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_choice_DWork.PCI6025EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &bump_choice_DWork.PCI6025EAD_IWORK[0]);
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

    /* Level2 S-Function Block: bump_choice/<Root>/Behavior BC (mastercon_bc) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[11]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn11.UPtrs0;
          sfcnUPtrs[0] = &bump_choice_B.Product1_b;
          sfcnUPtrs[1] = &bump_choice_B.Product_f;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn11.UPtrs1;
          sfcnUPtrs[0] = bump_choice_B.MultiportSwitch;
          sfcnUPtrs[1] = &bump_choice_B.MultiportSwitch[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn11.UPtrs2;
          sfcnUPtrs[0] = bump_choice_B.LoadSelectSwitch;
          sfcnUPtrs[1] = &bump_choice_B.LoadSelectSwitch[1];
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) bump_choice_B.BehaviorBC_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 5);
          ssSetOutputPortSignal(rts, 1, ((real_T *) bump_choice_B.BehaviorBC_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &bump_choice_B.BehaviorBC_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 15);
          ssSetOutputPortSignal(rts, 3, ((real_T *) bump_choice_B.BehaviorBC_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &bump_choice_B.BehaviorBC_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 2);
          ssSetOutputPortSignal(rts, 5, ((real_T *) bump_choice_B.BehaviorBC_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 4);
          ssSetOutputPortSignal(rts, 6, ((real_T *) bump_choice_B.BehaviorBC_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 2);
          ssSetOutputPortSignal(rts, 7, ((real_T *) bump_choice_B.BehaviorBC_o8));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *) &bump_choice_DWork.BehaviorBC_DSTATE);

      /* path info */
      ssSetModelName(rts, "Behavior BC");
      ssSetPath(rts, "bump_choice/Behavior BC");
      ssSetRTModel(rts,bump_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 13);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_choice_P.BehaviorBC_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_choice_P.BehaviorBC_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_choice_P.BehaviorBC_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_choice_P.BehaviorBC_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_choice_P.BehaviorBC_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_choice_P.BehaviorBC_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_choice_P.BehaviorBC_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&bump_choice_P.BehaviorBC_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&bump_choice_P.BehaviorBC_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&bump_choice_P.BehaviorBC_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&bump_choice_P.BehaviorBC_P11_Size[0]);
        ssSetSFcnParam(rts, 11, (mxArray*)&bump_choice_P.BehaviorBC_P12_Size[0]);
        ssSetSFcnParam(rts, 12, (mxArray*)&bump_choice_P.BehaviorBC_P13_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &bump_choice_DWork.BehaviorBC_RWORK[0]);
      ssSetIWork(rts, (int_T *) &bump_choice_DWork.BehaviorBC_IWORK[0]);
      ssSetPWork(rts, (void **) &bump_choice_DWork.BehaviorBC_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn11.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 4);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_choice_DWork.BehaviorBC_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 9);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &bump_choice_DWork.BehaviorBC_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 2, 1);
        ssSetDWorkDataType(rts, 2,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &bump_choice_DWork.BehaviorBC_PWORK);

        /* DSTATE */
        ssSetDWorkWidth(rts, 3, 1);
        ssSetDWorkDataType(rts, 3,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWorkUsedAsDState(rts, 3, 1);
        ssSetDWork(rts, 3, &bump_choice_DWork.BehaviorBC_DSTATE);
      }

      /* registration */
      mastercon_bc(rts);
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

    /* Level2 S-Function Block: bump_choice/<S4>/PCI-6025E  (danipcie) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[12]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[12]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs0;
          sfcnUPtrs[0] = &bump_choice_B.MG1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &bump_choice_rtM->NonInlinedSFcns.Sfcn12.UPtrs1;
          sfcnUPtrs[0] = &bump_choice_B.MG2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts, "bump_choice/Motor Control/PCI-6025E ");
      ssSetRTModel(rts,bump_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_choice_P.PCI6025E_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_choice_P.PCI6025E_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_choice_P.PCI6025E_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_choice_P.PCI6025E_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&bump_choice_P.PCI6025E_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&bump_choice_P.PCI6025E_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&bump_choice_P.PCI6025E_P7_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &bump_choice_DWork.PCI6025E_RWORK[0]);
      ssSetIWork(rts, (int_T *) &bump_choice_DWork.PCI6025E_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn12.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_choice_DWork.PCI6025E_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &bump_choice_DWork.PCI6025E_IWORK[0]);
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

    /* Level2 S-Function Block: bump_choice/<S7>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = bump_choice_rtM->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = bump_choice_rtM->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = bump_choice_rtM->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = bump_choice_rtM->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &bump_choice_rtM->NonInlinedSFcns.blkInfo2[13]);
        ssSetRTWSfcnInfo(rts, bump_choice_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &bump_choice_rtM->NonInlinedSFcns.methods2[13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &bump_choice_rtM->NonInlinedSFcns.Sfcn13.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, bump_choice_B.RateTransition);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 168);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "bump_choice/SendPacketToGraphics1/Send");
      ssSetRTModel(rts,bump_choice_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&bump_choice_P.Send_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&bump_choice_P.Send_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&bump_choice_P.Send_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&bump_choice_P.Send_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &bump_choice_DWork.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &bump_choice_DWork.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &bump_choice_rtM->NonInlinedSFcns.Sfcn13.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &bump_choice_DWork.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &bump_choice_DWork.Send_PWORK);
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
      ssSetInputPortWidth(rts, 0, 168);
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

  bump_choice_PrevZCSigState.SampleandHold.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
  bump_choice_PrevZCSigState.SampleandHold_h.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void bump_choice_terminate(void)
{
  /* Level2 S-Function Block: '<S12>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S12>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Behavior BC' (mastercon_bc) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S12>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S69>/ToBits1' (Byte2Bits) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S69>/Port A' (dopci8255) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S69>/SerialConverter' (serPos) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S69>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S69>/Port B' (dopci8255) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S69>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S69>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S71>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S71>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[1];
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
  bump_choice_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  bump_choice_update(tid);
}

void MdlInitializeSizes(void)
{
  bump_choice_rtM->Sizes.numContStates = (0);/* Number of continuous states */
  bump_choice_rtM->Sizes.numY = (0);   /* Number of model outputs */
  bump_choice_rtM->Sizes.numU = (0);   /* Number of model inputs */
  bump_choice_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  bump_choice_rtM->Sizes.numSampTimes = (3);/* Number of sample times */
  bump_choice_rtM->Sizes.numBlocks = (479);/* Number of blocks */
  bump_choice_rtM->Sizes.numBlockIO = (371);/* Number of block outputs */
  bump_choice_rtM->Sizes.numBlockPrms = (521);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Memory: '<S30>/Memory' */
  bump_choice_DWork.Memory_PreviousInput = bump_choice_P.Memory_X0;

  /* InitializeConditions for Memory: '<S4>/Memory' */
  bump_choice_DWork.Memory_PreviousInput_i = bump_choice_P.Memory_X0_l;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S66>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &bump_choice_DWork.DigitalFilter2_FILT_STATES
      [0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&bump_choice_P.DigitalFilter2_ICRTP;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S66>/Derivative' */
  bump_choice_DWork.Derivative_RWORK.TimeStampA = rtInf;
  bump_choice_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S66>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &bump_choice_DWork.DigitalFilter_FILT_STATES[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&bump_choice_P.DigitalFilter_ICRTP;
    }

    *statePtr++ = 0.0;
  }

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *)
      &bump_choice_DWork.DigitalFilter2_FILT_STATES_a[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&bump_choice_P.DigitalFilter2_ICRTP_i;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S67>/Derivative' */
  bump_choice_DWork.Derivative_RWORK_e.TimeStampA = rtInf;
  bump_choice_DWork.Derivative_RWORK_e.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &bump_choice_DWork.DigitalFilter_FILT_STATES_e
      [0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&bump_choice_P.DigitalFilter_ICRTP_l;
    }

    *statePtr++ = 0.0;
  }

  /* InitializeConditions for Memory: '<S42>/Memory' */
  bump_choice_DWork.Memory_PreviousInput_d = bump_choice_P.Memory_X0_p;

  /* InitializeConditions for Memory: '<S46>/Memory' */
  bump_choice_DWork.Memory_PreviousInput_dp = bump_choice_P.Memory_X0_d;

  /* InitializeConditions for UnitDelay: '<S60>/Delay Input1' */
  bump_choice_DWork.DelayInput1_DSTATE = bump_choice_P.DelayInput1_X0;

  /* InitializeConditions for Memory: '<S44>/Memory' */
  bump_choice_DWork.Memory_PreviousInput_b = bump_choice_P.Memory_X0_k;

  /* InitializeConditions for UnitDelay: '<S45>/Delay Input1' */
  bump_choice_DWork.DelayInput1_DSTATE_h = bump_choice_P.DelayInput1_X0_n;

  /* InitializeConditions for UnitDelay: '<S38>/Delay Input1' */
  bump_choice_DWork.DelayInput1_DSTATE_f = bump_choice_P.DelayInput1_X0_m;

  /* InitializeConditions for Memory: '<S43>/Memory' */
  bump_choice_DWork.Memory_PreviousInput_n = bump_choice_P.Memory_X0_e;

  /* InitializeConditions for UnitDelay: '<S37>/Delay Input1' */
  bump_choice_DWork.DelayInput1_DSTATE_l = bump_choice_P.DelayInput1_X0_o;

  /* InitializeConditions for Memory: '<S41>/Memory' */
  bump_choice_DWork.Memory_PreviousInput_iw = bump_choice_P.Memory_X0_c;

  /* InitializeConditions for UnitDelay: '<S22>/x' */
  bump_choice_DWork.x_DSTATE = bump_choice_P.x_X0;

  /* InitializeConditions for UnitDelay: '<S23>/x' */
  bump_choice_DWork.x_DSTATE_n = bump_choice_P.x_X0_p;

  /* InitializeConditions for UnitDelay: '<S24>/x' */
  bump_choice_DWork.x_DSTATE_i = bump_choice_P.x_X0_n;

  /* InitializeConditions for UnitDelay: '<S25>/x' */
  bump_choice_DWork.x_DSTATE_in = bump_choice_P.x_X0_pt;

  /* InitializeConditions for UnitDelay: '<S16>/x' */
  bump_choice_DWork.x_DSTATE_m = bump_choice_P.x_X0_i;

  /* InitializeConditions for UnitDelay: '<S17>/x' */
  bump_choice_DWork.x_DSTATE_h = bump_choice_P.x_X0_k;

  /* InitializeConditions for UnitDelay: '<S18>/x' */
  bump_choice_DWork.x_DSTATE_o = bump_choice_P.x_X0_nd;

  /* InitializeConditions for UnitDelay: '<S19>/x' */
  bump_choice_DWork.x_DSTATE_d = bump_choice_P.x_X0_a;

  /* Level2 S-Function Block: '<Root>/Behavior BC' (mastercon_bc) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[11];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* InitializeConditions for UnitDelay: '<S16>/y' */
  bump_choice_DWork.y_DSTATE = bump_choice_P.y_X0;

  /* InitializeConditions for UnitDelay: '<S16>/z' */
  bump_choice_DWork.z_DSTATE = bump_choice_P.z_X0;

  /* InitializeConditions for UnitDelay: '<S17>/y' */
  bump_choice_DWork.y_DSTATE_a = bump_choice_P.y_X0_l;

  /* InitializeConditions for UnitDelay: '<S17>/z' */
  bump_choice_DWork.z_DSTATE_n = bump_choice_P.z_X0_b;

  /* InitializeConditions for UnitDelay: '<S18>/y' */
  bump_choice_DWork.y_DSTATE_n = bump_choice_P.y_X0_a;

  /* InitializeConditions for UnitDelay: '<S18>/z' */
  bump_choice_DWork.z_DSTATE_c = bump_choice_P.z_X0_bn;

  /* InitializeConditions for UnitDelay: '<S19>/y' */
  bump_choice_DWork.y_DSTATE_i = bump_choice_P.y_X0_k;

  /* InitializeConditions for UnitDelay: '<S19>/z' */
  bump_choice_DWork.z_DSTATE_a = bump_choice_P.z_X0_i;

  /* InitializeConditions for UnitDelay: '<S22>/y' */
  bump_choice_DWork.y_DSTATE_a5 = bump_choice_P.y_X0_i;

  /* InitializeConditions for UnitDelay: '<S22>/z' */
  bump_choice_DWork.z_DSTATE_e = bump_choice_P.z_X0_n;

  /* InitializeConditions for UnitDelay: '<S23>/y' */
  bump_choice_DWork.y_DSTATE_ae = bump_choice_P.y_X0_m;

  /* InitializeConditions for UnitDelay: '<S23>/z' */
  bump_choice_DWork.z_DSTATE_p = bump_choice_P.z_X0_a;

  /* InitializeConditions for UnitDelay: '<S24>/y' */
  bump_choice_DWork.y_DSTATE_l = bump_choice_P.y_X0_p;

  /* InitializeConditions for UnitDelay: '<S24>/z' */
  bump_choice_DWork.z_DSTATE_m = bump_choice_P.z_X0_i4;

  /* InitializeConditions for UnitDelay: '<S25>/y' */
  bump_choice_DWork.y_DSTATE_f = bump_choice_P.y_X0_c;

  /* InitializeConditions for UnitDelay: '<S25>/z' */
  bump_choice_DWork.z_DSTATE_f = bump_choice_P.z_X0_f;
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S12>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S12>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S9>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S29>/S-Function (scblock) */
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
        xpceScopeAcqOK(2, &bump_choice_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S31>/S-Function (scblock) */
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
        xpceScopeAcqOK(6, &bump_choice_DWork.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(6);
    }
  }

  /* Level2 S-Function Block: '<S7>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[13];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S8>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BC/p2/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BC/p2/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BC/p2/s3"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BC/p2/s4"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BC/p2/s5"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BC/p2/s1"),
          "%6.0f state");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BC/p2/s2"),
          "%6.0f rewards");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BC/p2/s3"),
          "%6.0f aborts");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BC/p2/s4"),
          "%6.0f fails");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BC/p2/s5"),
          "%6.0f incompl");
        rl32eSetScope(3, 4, 10);
        rl32eSetScope(3, 40, 0);
        rl32eSetScope(3, 7, 10);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Behavior BC/p2/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 10, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, -10.0);
        rl32eSetTargetScope(3, 10, 10.0);
        xpceScopeAcqOK(3, &bump_choice_DWork.SFunction_IWORK_e.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* S-Function Block: <S10>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior BC/p7/s1"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior BC/p7/s2"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior BC/p7/s3"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior BC/p7/s4"));
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior BC/p7/s1"),
          "%6.0f major");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior BC/p7/s2"),
          "%6.0f minor");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior BC/p7/s3"),
          "%6.0f revision");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior BC/p7/s4"),
          "%6.0f build");
        rl32eSetScope(7, 4, 10);
        rl32eSetScope(7, 40, 0);
        rl32eSetScope(7, 7, 10);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("Behavior BC/p7/s1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 10, 0);
        rl32eSetTargetScope(7, 1, 0.0);
        rl32eSetTargetScope(7, 11, -10.0);
        rl32eSetTargetScope(7, 10, 10.0);
        xpceScopeAcqOK(7, &bump_choice_DWork.SFunction_IWORK_g.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* S-Function Block: <S13>/S-Function (scblock) */
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
        xpceScopeAcqOK(1, &bump_choice_DWork.SFunction_IWORK_h.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S47>/S-Function (scblock) */
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
        xpceScopeAcqOK(5, &bump_choice_DWork.SFunction_IWORK_d.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /*trigger Subsystem Block: '<S64>/Sample and Hold' */
  bump_choice_SampleandHold_Start(&bump_choice_B.SampleandHold,
    (rtP_SampleandHold_bump_choice *) &bump_choice_P.SampleandHold);

  /* UniformRandomNumber Block: '<S6>/Uniform Random Number' */
  {
    uint32_T *RandSeed = (uint32_T *)
      &bump_choice_DWork.UniformRandomNumber_IWORK.RandSeed;
    uint32_T r, t;
    *RandSeed = (uint32_T)bump_choice_P.UniformRandomNumber_Seed;
    r = *RandSeed >> 16;
    t = *RandSeed & RT_BIT16;
    *RandSeed = ((*RandSeed - (r << 16) - t) << 16) + t + r;
    if (*RandSeed < 1) {
      *RandSeed = SEED0;
    }

    if (*RandSeed > MAXSEED) {
      *RandSeed = MAXSEED;
    }

    bump_choice_DWork.UniformRandomNumber_RWORK.NextOutput
      = rt_Urand(RandSeed++) * (bump_choice_P.UniformRandomNumber_Max -
      bump_choice_P.UniformRandomNumber_Min) +
      bump_choice_P.UniformRandomNumber_Min;
  }

  /*trigger Subsystem Block: '<S6>/Sample and Hold' */
  bump_choice_SampleandHold_Start(&bump_choice_B.SampleandHold_h,
    (rtP_SampleandHold_bump_choice *) &bump_choice_P.SampleandHold_h);

  /* Start for iterator system: '<S12>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S69>/Port A' (dopci8255) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S69>/Port B' (dopci8255) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Start for iterator system: '<S69>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S71>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = bump_choice_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  bump_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_choice_DWork.EnabledSubsystem_p.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_choice_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_choice_DWork.EnabledSubsystem_e.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_choice_DWork.SampleandHold_h.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  bump_choice_DWork.SampleandHold.SampleandHold_SubsysRanBC =
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

rtModel_bump_choice *bump_choice(void)
{
  bump_choice_initialize(1);
  return bump_choice_rtM;
}

void MdlTerminate(void)
{
  bump_choice_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
