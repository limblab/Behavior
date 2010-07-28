/*
 * random_walk.c
 *
 * Real-Time Workshop code generation for Simulink model "random_walk.mdl".
 *
 * Model Version              : 1.1211
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:40 2010
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

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_random_walk random_walk_PrevZCSigState;

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
}

time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(random_walk_rtM, 1);
  rtmSampleHitPtr[2] = rtmStepTask(random_walk_rtM, 2);
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
  if (random_walk_rtM->Timing.TaskCounters.TID[1] == 0) {
    random_walk_rtM->Timing.RateInteraction.TID1_2 =
      (random_walk_rtM->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    random_walk_rtM->Timing.perTaskSampleHits[5] =
      random_walk_rtM->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++random_walk_rtM->Timing.TaskCounters.TID[2] == 20) {/* Sample time: [0.02s, 0.0s] */
    random_walk_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  random_walk_rtM->Timing.sampleHits[2] =
    (random_walk_rtM->Timing.TaskCounters.TID[2] == 0);
}

/* Disable for enable system:
 *   '<S31>/Enabled Subsystem'
 *   '<S43>/Enabled Subsystem'
 *   '<S44>/Enabled Subsystem'
 *   '<S45>/Enabled Subsystem'
 *   '<S47>/Enabled Subsystem'
 */
void random_EnabledSubsystem_Disable(rtDW_EnabledSubsystem_random_wa *localDW)
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
void random_walk_SampleandHold_Start(rtB_SampleandHold_random_walk *localB,
  rtP_SampleandHold_random_walk *localP)
{
  /* virtual outports code */

  /* (Virtual) Outport Block: '<S64>/ ' */
  localB->In = localP->_Y0;
}

/* Output and update for trigger system:
 *   '<S6>/Sample and Hold'
 *   '<S65>/Sample and Hold'
 */
void random_walk_SampleandHold(real_T rtu_0, real_T rtu_1,
  rtB_SampleandHold_random_walk *localB, rtDW_SampleandHold_random_walk *localDW,
  rtZCE_SampleandHold_random_walk *localZCE)
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
void random_walk_output(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  if (tid == 0) {
    srClearBC(random_walk_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC);
    srClearBC(random_walk_DWork.EnabledSubsystem_d.EnabledSubsystem_SubsysRanBC);
    srClearBC(random_walk_DWork.EnabledSubsystem_n.EnabledSubsystem_SubsysRanBC);
    srClearBC(random_walk_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC);
    srClearBC(random_walk_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC);
    srClearBC(random_walk_DWork.SampleandHold_g.SampleandHold_SubsysRanBC);
    srClearBC(random_walk_DWork.SampleandHold.SampleandHold_SubsysRanBC);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S31>/Clock'
     */
    random_walk_B.Clock = random_walk_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S31>/Memory' */
    random_walk_B.Memory = random_walk_DWork.Memory_PreviousInput;

    /* Memory: '<S4>/Memory' */
    random_walk_B.Memory_e = random_walk_DWork.Memory_PreviousInput_i;

    /* Logic: '<S31>/Logical Operator2' */
    random_walk_B.LogicalOperator2 = (random_walk_B.Memory ||
      random_walk_B.Memory_e);

    /* Logic: '<S31>/Logical Operator1' */
    random_walk_B.LogicalOperator1 = !random_walk_B.LogicalOperator2;

    /* SignalConversion: '<S31>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_EnabledSu =
      random_walk_B.LogicalOperator1;
  }

  /* SubSystem Block: '<S31>/Enabled Subsystem'
   */
  random_walk_EnabledSubsystem(tid,
    random_walk_B.HiddenBuf_InsertedFor_EnabledSu, random_walk_B.Clock,
    &random_walk_B.EnabledSubsystem, &random_walk_DWork.EnabledSubsystem);
  if (tid == 0) {
    /* Sum: '<S31>/Sum' */
    random_walk_B.Sum = random_walk_B.Clock - random_walk_B.EnabledSubsystem.In1;

    /* RelationalOperator: '<S34>/Compare' */
    random_walk_B.Compare = (random_walk_B.Sum > 0.0);

    /* RelationalOperator: '<S31>/Relational Operator' incorporates:
     *  Constant: '<S31>/Time'
     */
    random_walk_B.RelationalOperator = (random_walk_B.Sum >
      random_walk_P.Time_Value);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S31>/Logical Operator' */
    random_walk_B.LogicalOperator = (boolean_T)((random_walk_B.Compare != 0U) ^
      random_walk_B.RelationalOperator);

    /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S13>/Gain' */
    random_walk_B.Gain = random_walk_P.Gain_Gain * random_walk_B.PCIQUAD04;

    /* Sum: '<S13>/Sum3' incorporates:
     *  Constant: '<S13>/shoulderOffset'
     */
    random_walk_B.Sum3 = random_walk_B.Gain + random_walk_P.shoulderOffset_Value;

    /* Trigonometry: '<S71>/Trigonometric Function' */
    random_walk_B.TrigonometricFunction = cos(random_walk_B.Sum3);

    /* Product: '<S71>/Product' incorporates:
     *  Constant: '<S71>/L1'
     */
    random_walk_B.Product = random_walk_B.TrigonometricFunction *
      random_walk_P.L1_Value;

    /* Gain: '<S71>/Gain' */
    random_walk_B.MatrixConcatenate2[0] = random_walk_P.Gain_Gain_f *
      random_walk_B.Product;

    /* Trigonometry: '<S71>/Trigonometric Function1' */
    random_walk_B.TrigonometricFunction1 = sin(random_walk_B.Sum3);

    /* Product: '<S71>/Product1' incorporates:
     *  Constant: '<S71>/L1'
     */
    random_walk_B.Product1 = random_walk_B.TrigonometricFunction1 *
      random_walk_P.L1_Value;

    /* SignalConversion: '<S71>/ConcatHiddenBufferAtMatrix ConcatenateInPort1' */
    random_walk_B.MatrixConcatenate2[1] = random_walk_B.Product1;

    /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[9];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S13>/Gain1' */
    random_walk_B.Gain1 = random_walk_P.Gain1_Gain * random_walk_B.PCIQUAD041;

    /* Sum: '<S13>/Sum1' incorporates:
     *  Constant: '<S13>/elbowOffset'
     */
    random_walk_B.Sum1 = random_walk_B.Gain1 + random_walk_P.elbowOffset_Value;

    /* Trigonometry: '<S71>/Trigonometric Function2' */
    random_walk_B.TrigonometricFunction2 = sin(random_walk_B.Sum1);

    /* Product: '<S71>/Product2' incorporates:
     *  Constant: '<S71>/L2'
     */
    random_walk_B.Product2 = random_walk_B.TrigonometricFunction2 *
      random_walk_P.L2_Value;

    /* Gain: '<S71>/Gain1' */
    random_walk_B.MatrixConcatenate2[2] = random_walk_P.Gain1_Gain_c *
      random_walk_B.Product2;

    /* Trigonometry: '<S71>/Trigonometric Function3' */
    random_walk_B.TrigonometricFunction3 = cos(random_walk_B.Sum1);

    /* Product: '<S71>/Product3' incorporates:
     *  Constant: '<S71>/L2'
     */
    random_walk_B.Product3 = random_walk_B.TrigonometricFunction3 *
      random_walk_P.L2_Value;

    /* Gain: '<S71>/Gain2' */
    random_walk_B.MatrixConcatenate2[3] = random_walk_P.Gain2_Gain *
      random_walk_B.Product3;

    /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[10];
      sfcnOutputs(rts, 1);
    }

    {
      real_T tmp;
      real_T tmp_0;

      /* Sum: '<S71>/Sum2' */
      random_walk_B.Sum2 = (0.0 - random_walk_B.Product) -
        random_walk_B.Product2;

      /* Sum: '<S71>/Sum4' incorporates:
       *  Constant: '<S71>/yoffset'
       */
      random_walk_B.Sum4 = random_walk_B.Sum2 + random_walk_P.yoffset_Value;

      /* Sum: '<S71>/Sum3' */
      random_walk_B.Sum3_i = random_walk_B.Product3 - random_walk_B.Product1;

      /* Sum: '<S71>/Sum1' incorporates:
       *  Constant: '<S71>/xoffset'
       */
      random_walk_B.Sum1_g = random_walk_B.Sum3_i + random_walk_P.xoffset_Value;

      /* Trigonometry: '<S69>/Trigonometric Function1' */
      random_walk_B.TrigonometricFunction1_p = rt_atan2(random_walk_B.Sum4,
        random_walk_B.Sum1_g);

      /* Sum: '<S69>/Sum' incorporates:
       *  Constant: '<S69>/AngleOffset'
       */
      random_walk_B.Sum_h = random_walk_B.TrigonometricFunction1_p +
        random_walk_P.AngleOffset_Value;

      /* Trigonometry: '<S69>/Trigonometric Function2' */
      random_walk_B.TrigonometricFunction2_i = cos(random_walk_B.Sum_h);

      /* Fcn: '<S69>/sqrt(u[1]*u[1] + u[2]*u[2])' */
      tmp = random_walk_B.Sum4;
      tmp_0 = random_walk_B.Sum1_g;
      random_walk_B.sqrtu1u1u2u2 = sqrt(tmp * tmp + tmp_0 * tmp_0);

      /* Product: '<S69>/Product1' */
      random_walk_B.Product1_m = random_walk_B.TrigonometricFunction2_i *
        random_walk_B.sqrtu1u1u2u2;
    }

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&random_walk_B.Product1_m, &random_walk_B.DigitalFilter2,
                    &random_walk_DWork.DigitalFilter2_FILT_STATES[0],
                    &random_walk_DWork.DigitalFilter2_CIRCBUFFIDX, 11, 1, 1,
                    &random_walk_P.DigitalFilter2_RTP1COEFF[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S67>/Derivative' */
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
    /* Gain: '<S67>/dG' */
    random_walk_B.dG = random_walk_P.dG_Gain * random_walk_B.Derivative;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&random_walk_B.dG, &random_walk_B.DigitalFilter,
                    &random_walk_DWork.DigitalFilter_FILT_STATES[0],
                    &random_walk_DWork.DigitalFilter_CIRCBUFFIDX, 11, 1, 1,
                    &random_walk_P.DigitalFilter_RTP1COEFF[0], 1);

    /* Trigonometry: '<S69>/Trigonometric Function' */
    random_walk_B.TrigonometricFunction_g = sin(random_walk_B.Sum_h);

    /* Product: '<S69>/Product' */
    random_walk_B.Product_l = random_walk_B.sqrtu1u1u2u2 *
      random_walk_B.TrigonometricFunction_g;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter2' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&random_walk_B.Product_l, &random_walk_B.DigitalFilter2_k,
                    &random_walk_DWork.DigitalFilter2_FILT_STATES_a[0],
                    &random_walk_DWork.DigitalFilter2_CIRCBUFFIDX_a, 11, 1, 1,
                    &random_walk_P.DigitalFilter2_RTP1COEFF_f[0], 1);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S68>/Derivative' */
    {
      real_T t = random_walk_rtM->Timing.t[0];
      real_T timeStampA = random_walk_DWork.Derivative_RWORK_a.TimeStampA;
      real_T timeStampB = random_walk_DWork.Derivative_RWORK_a.TimeStampB;
      if (timeStampA >= t && timeStampB >= t) {
        random_walk_B.Derivative_d = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &random_walk_DWork.Derivative_RWORK_a.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }

        deltaT = t - *lastBank++;
        random_walk_B.Derivative_d = (random_walk_B.DigitalFilter2_k - *lastBank
          ++) / deltaT;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Gain: '<S68>/dG' */
    random_walk_B.dG_d = random_walk_P.dG_Gain_d * random_walk_B.Derivative_d;

    /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter' */
    /* FIR, Direct-form */
    MWDSP_FIR_DF_DD(&random_walk_B.dG_d, &random_walk_B.DigitalFilter_c,
                    &random_walk_DWork.DigitalFilter_FILT_STATES_m[0],
                    &random_walk_DWork.DigitalFilter_CIRCBUFFIDX_d, 11, 1, 1,
                    &random_walk_P.DigitalFilter_RTP1COEFF_o[0], 1);

    {
      real_T tmp;
      real_T tmp_0;

      /* Switch: '<S10>/Switch' incorporates:
       *  Constant: '<S10>/UseTachs'
       */
      if (random_walk_P.UseTachs_Value >= random_walk_P.Switch_Threshold) {
        {
          real_T tmp;
          real_T tmp_0;

          /* Gain: '<S10>/TachGain2' */
          random_walk_B.TachGain2 = random_walk_P.TachGain2_Gain *
            random_walk_B.PCI6025EAD_o2;

          /* Gain: '<S10>/TachGain1' */
          random_walk_B.TachGain1 = random_walk_P.TachGain1_Gain *
            random_walk_B.PCI6025EAD_o1;

          /* SignalConversion: '<S10>/TmpHiddenBufferAtMatrix MultiplyInport2' */
          tmp = random_walk_B.TachGain1;
          tmp_0 = random_walk_B.TachGain2;
          random_walk_B.TmpHiddenBufferAtMatrixMultiply[0] = tmp;
          random_walk_B.TmpHiddenBufferAtMatrixMultiply[1] = tmp_0;
        }

        {
          static const int_T dims[3] = { 2, 2, 1 };

          rt_MatMultRR_Dbl(random_walk_B.MatrixMultiply,
                           random_walk_B.MatrixConcatenate2,
                           random_walk_B.TmpHiddenBufferAtMatrixMultiply, &dims
                           [0]);
        }

        random_walk_B.Switch[0] = random_walk_B.MatrixMultiply[0];
        random_walk_B.Switch[1] = random_walk_B.MatrixMultiply[1];
      } else {
        tmp = random_walk_B.DigitalFilter;
        tmp_0 = random_walk_B.DigitalFilter_c;
        random_walk_B.Switch[0] = tmp;
        random_walk_B.Switch[1] = tmp_0;
      }
    }
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S43>/Clock'
     */
    random_walk_B.Clock_m = random_walk_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S43>/Memory' */
    random_walk_B.Memory_i = random_walk_DWork.Memory_PreviousInput_c;

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

    /* Logic: '<S47>/Logical Operator3' */
    random_walk_B.LogicalOperator3 = !random_walk_B.InBox;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S47>/Clock'
     */
    random_walk_B.Clock_i = random_walk_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S47>/Memory' */
    random_walk_B.Memory_e5 = random_walk_DWork.Memory_PreviousInput_e;

    /* Logic: '<S47>/Logical Operator4' */
    random_walk_B.LogicalOperator4 = (random_walk_B.Memory_e5 &&
      random_walk_B.LogicalOperator3);

    /* RelationalOperator: '<S36>/Compare' */
    random_walk_B.Compare_j = (random_walk_B.Switch[0] == 0.0);

    /* RelationalOperator: '<S37>/Compare' */
    random_walk_B.Compare_m = (random_walk_B.Switch[1] == 0.0);

    /* Logic: '<S5>/Logical Operator' incorporates:
     *  Constant: '<S5>/RecenterFlag'
     */
    random_walk_B.LogicalOperator_i = ((random_walk_P.RecenterFlag_Value != 0.0)
      && (random_walk_B.Compare_j != 0U) && (random_walk_B.Compare_m != 0U) &&
      random_walk_B.LogicalOperator_a);

    /* Logic: '<S47>/Logical Operator2' */
    random_walk_B.LogicalOperator2_m = (random_walk_B.LogicalOperator4 ||
      random_walk_B.LogicalOperator_i);

    /* Logic: '<S47>/Logical Operator1' */
    random_walk_B.LogicalOperator1_f = !random_walk_B.LogicalOperator2_m;

    /* SignalConversion: '<S47>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_Enabled_k =
      random_walk_B.LogicalOperator1_f;
  }

  /* SubSystem Block: '<S47>/Enabled Subsystem'
   */
  random_walk_EnabledSubsystem(tid,
    random_walk_B.HiddenBuf_InsertedFor_Enabled_k, random_walk_B.Clock_i,
    &random_walk_B.EnabledSubsystem_l, &random_walk_DWork.EnabledSubsystem_l);
  if (tid == 0) {
    /* Sum: '<S47>/Sum' */
    random_walk_B.Sum_m = random_walk_B.Clock_i -
      random_walk_B.EnabledSubsystem_l.In1;

    /* RelationalOperator: '<S60>/Compare' */
    random_walk_B.Compare_j0 = (random_walk_B.Sum_m > 0.0);

    /* RelationalOperator: '<S47>/Relational Operator' incorporates:
     *  Constant: '<S47>/Time'
     */
    random_walk_B.RelationalOperator_p = (random_walk_B.Sum_m >
      random_walk_P.Time_Value_l);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S47>/Logical Operator' */
    random_walk_B.LogicalOperator_ai = (boolean_T)((random_walk_B.Compare_j0 !=
      0U) ^ random_walk_B.RelationalOperator_p);

    /* RelationalOperator: '<S63>/Compare' */
    random_walk_B.Compare_h = (random_walk_B.LogicalOperator_ai <= FALSE);

    /* UnitDelay: '<S61>/Delay Input1' */
    random_walk_B.Uk1 = random_walk_DWork.DelayInput1_DSTATE;

    /* RelationalOperator: '<S61>/FixPt Relational Operator' */
    random_walk_B.FixPtRelationalOperator = (random_walk_B.Compare_h >
      random_walk_B.Uk1);

    /* Logic: '<S47>/Logical Operator5' */
    random_walk_B.LogicalOperator5 = (random_walk_B.LogicalOperator3 &&
      (random_walk_B.FixPtRelationalOperator != 0U));

    /* Logic: '<S43>/Logical Operator2' */
    random_walk_B.LogicalOperator2_o = (random_walk_B.Memory_i ||
      random_walk_B.LogicalOperator5);

    /* Logic: '<S43>/Logical Operator1' */
    random_walk_B.LogicalOperator1_p = !random_walk_B.LogicalOperator2_o;

    /* SignalConversion: '<S43>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_Enabled_m =
      random_walk_B.LogicalOperator1_p;
  }

  /* SubSystem Block: '<S43>/Enabled Subsystem'
   */
  random_walk_EnabledSubsystem(tid,
    random_walk_B.HiddenBuf_InsertedFor_Enabled_m, random_walk_B.Clock_m,
    &random_walk_B.EnabledSubsystem_d, &random_walk_DWork.EnabledSubsystem_d);
  if (tid == 0) {
    /* Sum: '<S43>/Sum' */
    random_walk_B.Sum_hd = random_walk_B.Clock_m -
      random_walk_B.EnabledSubsystem_d.In1;

    /* RelationalOperator: '<S53>/Compare' */
    random_walk_B.Compare_l = (random_walk_B.Sum_hd > 0.0);

    /* RelationalOperator: '<S43>/Relational Operator' incorporates:
     *  Constant: '<S43>/Time'
     */
    random_walk_B.RelationalOperator_c = (random_walk_B.Sum_hd >
      random_walk_P.Time_Value_p);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S43>/Logical Operator' */
    random_walk_B.LogicalOperator_if = (boolean_T)((random_walk_B.Compare_l !=
      0U) ^ random_walk_B.RelationalOperator_c);

    /* Abs: '<S40>/Abs2' */
    random_walk_B.Abs2 = fabs(random_walk_B.Switch[0]);

    /* RelationalOperator: '<S51>/Compare' incorporates:
     *  Constant: '<S51>/Constant'
     */
    random_walk_B.Compare_o = (random_walk_B.Abs2 <=
      random_walk_P.Constant_Value);

    /* Abs: '<S40>/Abs3' */
    random_walk_B.Abs3 = fabs(random_walk_B.Switch[1]);

    /* RelationalOperator: '<S52>/Compare' incorporates:
     *  Constant: '<S52>/Constant'
     */
    random_walk_B.Compare_d = (random_walk_B.Abs3 <=
      random_walk_P.Constant_Value_e);

    /* Logic: '<S40>/Logical Operator1' */
    random_walk_B.LogicalOperator1_d = ((random_walk_B.Compare_o != 0U) &&
      (random_walk_B.Compare_d != 0U));

    /* Logic: '<S5>/NOT' */
    random_walk_B.NOT = !random_walk_B.LogicalOperator1_d;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S45>/Clock'
     */
    random_walk_B.Clock_e = random_walk_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S45>/Memory' */
    random_walk_B.Memory_o = random_walk_DWork.Memory_PreviousInput_d;

    /* RelationalOperator: '<S59>/Compare' */
    random_walk_B.Compare_g = (random_walk_B.LogicalOperator1_d <= FALSE);

    /* UnitDelay: '<S46>/Delay Input1' */
    random_walk_B.Uk1_j = random_walk_DWork.DelayInput1_DSTATE_h;

    /* RelationalOperator: '<S46>/FixPt Relational Operator' */
    random_walk_B.FixPtRelationalOperator_m = (random_walk_B.Compare_g >
      random_walk_B.Uk1_j);

    /* Logic: '<S45>/Logical Operator2' */
    random_walk_B.LogicalOperator2_j = (random_walk_B.Memory_o ||
      (random_walk_B.FixPtRelationalOperator_m != 0U));

    /* Logic: '<S45>/Logical Operator1' */
    random_walk_B.LogicalOperator1_i = !random_walk_B.LogicalOperator2_j;

    /* SignalConversion: '<S45>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_Enabled_a =
      random_walk_B.LogicalOperator1_i;
  }

  /* SubSystem Block: '<S45>/Enabled Subsystem'
   */
  random_walk_EnabledSubsystem(tid,
    random_walk_B.HiddenBuf_InsertedFor_Enabled_a, random_walk_B.Clock_e,
    &random_walk_B.EnabledSubsystem_o, &random_walk_DWork.EnabledSubsystem_o);
  if (tid == 0) {
    /* Sum: '<S45>/Sum' */
    random_walk_B.Sum_o = random_walk_B.Clock_e -
      random_walk_B.EnabledSubsystem_o.In1;

    /* RelationalOperator: '<S57>/Compare' */
    random_walk_B.Compare_d1 = (random_walk_B.Sum_o > 0.0);

    /* RelationalOperator: '<S45>/Relational Operator' incorporates:
     *  Constant: '<S45>/Time'
     */
    random_walk_B.RelationalOperator_pq = (random_walk_B.Sum_o >
      random_walk_P.Time_Value_m);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S45>/Logical Operator' */
    random_walk_B.LogicalOperator_b = (boolean_T)((random_walk_B.Compare_d1 !=
      0U) ^ random_walk_B.RelationalOperator_pq);

    /* RelationalOperator: '<S50>/Compare' */
    random_walk_B.Compare_n = (random_walk_B.LogicalOperator_b <= FALSE);

    /* UnitDelay: '<S39>/Delay Input1' */
    random_walk_B.Uk1_n = random_walk_DWork.DelayInput1_DSTATE_k;

    /* RelationalOperator: '<S39>/FixPt Relational Operator' */
    random_walk_B.FixPtRelationalOperator_d = (random_walk_B.Compare_n >
      random_walk_B.Uk1_n);

    /* DataTypeConversion: '<S5>/Data Type Conversion2' */
    random_walk_B.DataTypeConversion2 = (random_walk_B.FixPtRelationalOperator_d
      != 0U);

    /* Logic: '<S5>/Logical Operator1' */
    random_walk_B.LogicalOperator1_a = (random_walk_B.NOT ||
      random_walk_B.DataTypeConversion2);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S44>/Clock'
     */
    random_walk_B.Clock_n = random_walk_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Memory: '<S44>/Memory' */
    random_walk_B.Memory_j = random_walk_DWork.Memory_PreviousInput_b;

    /* Logic: '<S44>/Logical Operator2' */
    random_walk_B.LogicalOperator2_mi = (random_walk_B.Memory_j ||
      random_walk_B.LogicalOperator5);

    /* Logic: '<S44>/Logical Operator1' */
    random_walk_B.LogicalOperator1_pq = !random_walk_B.LogicalOperator2_mi;

    /* SignalConversion: '<S44>/HiddenBuf_InsertedFor_Enabled Subsystem_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_Enabled_i =
      random_walk_B.LogicalOperator1_pq;
  }

  /* SubSystem Block: '<S44>/Enabled Subsystem'
   */
  random_walk_EnabledSubsystem(tid,
    random_walk_B.HiddenBuf_InsertedFor_Enabled_i, random_walk_B.Clock_n,
    &random_walk_B.EnabledSubsystem_n, &random_walk_DWork.EnabledSubsystem_n);
  if (tid == 0) {
    /* Sum: '<S44>/Sum' */
    random_walk_B.Sum_ms = random_walk_B.Clock_n -
      random_walk_B.EnabledSubsystem_n.In1;

    /* RelationalOperator: '<S55>/Compare' */
    random_walk_B.Compare_f = (random_walk_B.Sum_ms > 0.0);

    /* RelationalOperator: '<S44>/Relational Operator' incorporates:
     *  Constant: '<S44>/Time'
     */
    random_walk_B.RelationalOperator_l = (random_walk_B.Sum_ms >
      random_walk_P.Time_Value_n);
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Logic: '<S44>/Logical Operator' */
    random_walk_B.LogicalOperator_e = (boolean_T)((random_walk_B.Compare_f != 0U)
      ^ random_walk_B.RelationalOperator_l);

    /* RelationalOperator: '<S49>/Compare' */
    random_walk_B.Compare_my = (random_walk_B.LogicalOperator_e <= FALSE);

    /* UnitDelay: '<S38>/Delay Input1' */
    random_walk_B.Uk1_i = random_walk_DWork.DelayInput1_DSTATE_f;

    /* RelationalOperator: '<S38>/FixPt Relational Operator' */
    random_walk_B.FixPtRelationalOperator_b = (random_walk_B.Compare_my >
      random_walk_B.Uk1_i);

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    random_walk_B.DataTypeConversion1 = (random_walk_B.FixPtRelationalOperator_b
      != 0U);

    /* Memory: '<S42>/Memory' */
    random_walk_B.Memory_jh = random_walk_DWork.Memory_PreviousInput_h;

    /* CombinatorialLogic Block: '<S42>/Logic'
     */
    {
      int_T rowidx= 0;

      /* Compute the truth table row index corresponding to the input */
      rowidx = (rowidx << 1) + (int_T)(random_walk_B.LogicalOperator1_a != 0);
      rowidx = (rowidx << 1) + (int_T)(random_walk_B.DataTypeConversion1 != 0);
      rowidx = (rowidx << 1) + (int_T)(random_walk_B.Memory_jh != 0);

      /* Copy the appropriate row of the table into the block output vector */
      random_walk_B.Logic[0] = random_walk_P.Logic_table[rowidx];
      random_walk_B.Logic[1] = random_walk_P.Logic_table[rowidx + 8];
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
      random_walk_B.LogicalOperator5_h = (random_walk_B.Logic[1] ||
        random_walk_B.LogicalOperator_e || random_walk_B.LogicalOperator_a);

      /* UnitDelay: '<S23>/x' */
      random_walk_B.x = random_walk_DWork.x_DSTATE;

      /* UnitDelay: '<S24>/x' */
      random_walk_B.x_f = random_walk_DWork.x_DSTATE_m;

      /* Sum: '<S21>/Add' */
      random_walk_B.Add = random_walk_B.x - random_walk_B.x_f;

      /* UnitDelay: '<S25>/x' */
      random_walk_B.x_h = random_walk_DWork.x_DSTATE_d;

      /* UnitDelay: '<S26>/x' */
      random_walk_B.x_l = random_walk_DWork.x_DSTATE_k;

      /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
       *  Constant: '<S3>/Load'
       *  Constant: '<S3>/Off'
       *  Constant: '<S3>/staticX'
       *  Constant: '<S3>/staticY'
       */
      switch ((int32_T)random_walk_P.Load_Value) {
       case 0:
        tmp = random_walk_P.Off_Value_d;
        tmp_0 = random_walk_P.Off_Value_d;
        random_walk_B.MultiportSwitch[0] = tmp;
        random_walk_B.MultiportSwitch[1] = tmp_0;
        break;

       case 1:
        tmp_1 = random_walk_P.staticX_Value_e;
        tmp_2 = random_walk_P.staticY_Value_a;
        random_walk_B.MultiportSwitch[0] = tmp_1;
        random_walk_B.MultiportSwitch[1] = tmp_2;
        break;

       case 2:
        /* Sum: '<S21>/Add1' */
        random_walk_B.Add1_a = random_walk_B.x_h - random_walk_B.x_l;

        /* Gain: '<S3>/LorentzForceGain' */
        tmp_7 = random_walk_B.Add;
        tmp_8 = random_walk_B.Add1_a;
        random_walk_B.LorentzForceGain[0] =
          random_walk_P.LorentzForceGain_Gain_j * tmp_7;
        random_walk_B.LorentzForceGain[1] =
          random_walk_P.LorentzForceGain_Gain_j * tmp_8;
        random_walk_B.MultiportSwitch[0] = random_walk_B.LorentzForceGain[0];
        random_walk_B.MultiportSwitch[1] = random_walk_B.LorentzForceGain[1];
        break;

       default:
        /* MultiPortSwitch: '<S3>/dynamicAngle Switch' incorporates:
         *  Constant: '<S3>/DynamicAngle'
         *  Constant: '<S3>/visAngle'
         */
        if ((int32_T)random_walk_P.DynamicAngle_Value_h == 0) {
          random_walk_B.dynamicAngleSwitch = random_walk_P.visAngle_Value_n;
        } else {
          /* Gain: '<S3>/Gain' */
          random_walk_B.Gain_d = random_walk_P.Gain_Gain_p * random_walk_B.Add;
          random_walk_B.dynamicAngleSwitch = random_walk_B.Gain_d;
        }

        /* Trigonometry: '<S22>/sin' */
        random_walk_B.sin_e = sin(random_walk_B.dynamicAngleSwitch);

        /* Gain: '<S22>/Inverter' */
        random_walk_B.Inverter[0] = random_walk_P.Inverter_Gain_b *
          random_walk_B.Switch[0];
        random_walk_B.Inverter[1] = random_walk_P.Inverter_Gain_b *
          random_walk_B.Switch[1];

        /* Product: '<S22>/Product3' */
        cg_in = random_walk_B.Inverter[0];
        random_walk_B.Product3_m = cg_in * random_walk_B.sin_e;

        /* Trigonometry: '<S22>/cos' */
        random_walk_B.cos_o = cos(random_walk_B.dynamicAngleSwitch);

        /* Product: '<S22>/Product2' */
        cg_in_0 = random_walk_B.Inverter[1];
        random_walk_B.Product2_m = cg_in_0 * random_walk_B.cos_o;

        /* Sum: '<S22>/Subtract' */
        random_walk_B.Subtract_j = random_walk_B.Product2_m -
          random_walk_B.Product3_m;

        /* Product: '<S22>/Product1' */
        cg_in_1 = random_walk_B.Inverter[1];
        random_walk_B.Product1_f = cg_in_1 * random_walk_B.sin_e;

        /* Product: '<S22>/Product' */
        cg_in_2 = random_walk_B.Inverter[0];
        random_walk_B.Product_e = cg_in_2 * random_walk_B.cos_o;

        /* Sum: '<S22>/Add' */
        random_walk_B.Add_ci = random_walk_B.Product_e +
          random_walk_B.Product1_f;

        /* Gain: '<S22>/Gain' */
        tmp_9 = random_walk_B.Add_ci;
        tmp_a = random_walk_B.Subtract_j;
        random_walk_B.Gain_n[0] = random_walk_P.Gain_Gain_go * tmp_9;
        random_walk_B.Gain_n[1] = random_walk_P.Gain_Gain_go * tmp_a;
        random_walk_B.MultiportSwitch[0] = random_walk_B.Gain_n[0];
        random_walk_B.MultiportSwitch[1] = random_walk_B.Gain_n[1];
        break;
      }

      /* UnitDelay: '<S17>/x' */
      random_walk_B.x_k = random_walk_DWork.x_DSTATE_b;

      /* UnitDelay: '<S18>/x' */
      random_walk_B.x_m = random_walk_DWork.x_DSTATE_g;

      /* Sum: '<S15>/Add' */
      random_walk_B.Add_o = random_walk_B.x_k - random_walk_B.x_m;

      /* UnitDelay: '<S19>/x' */
      random_walk_B.x_o = random_walk_DWork.x_DSTATE_l;

      /* UnitDelay: '<S20>/x' */
      random_walk_B.x_mw = random_walk_DWork.x_DSTATE_n;

      /* MultiPortSwitch: '<S2>/LoadSelect Switch' incorporates:
       *  Constant: '<S2>/Load'
       *  Constant: '<S2>/Off'
       *  Constant: '<S2>/staticX'
       *  Constant: '<S2>/staticY'
       */
      switch ((int32_T)random_walk_P.Load_Value_a) {
       case 0:
        tmp_3 = random_walk_P.Off_Value;
        tmp_4 = random_walk_P.Off_Value;
        random_walk_B.LoadSelectSwitch[0] = tmp_3;
        random_walk_B.LoadSelectSwitch[1] = tmp_4;
        break;

       case 1:
        tmp_5 = random_walk_P.staticX_Value;
        tmp_6 = random_walk_P.staticY_Value;
        random_walk_B.LoadSelectSwitch[0] = tmp_5;
        random_walk_B.LoadSelectSwitch[1] = tmp_6;
        break;

       case 2:
        /* Sum: '<S15>/Add1' */
        random_walk_B.Add1_b1 = random_walk_B.x_o - random_walk_B.x_mw;

        /* Gain: '<S2>/LorentzForceGain' */
        tmp_b = random_walk_B.Add_o;
        tmp_c = random_walk_B.Add1_b1;
        random_walk_B.LorentzForceGain_j[0] =
          random_walk_P.LorentzForceGain_Gain * tmp_b;
        random_walk_B.LorentzForceGain_j[1] =
          random_walk_P.LorentzForceGain_Gain * tmp_c;
        random_walk_B.LoadSelectSwitch[0] = random_walk_B.LorentzForceGain_j[0];
        random_walk_B.LoadSelectSwitch[1] = random_walk_B.LorentzForceGain_j[1];
        break;

       default:
        /* MultiPortSwitch: '<S2>/DynamicAngle Switch' incorporates:
         *  Constant: '<S2>/DynamicAngle'
         *  Constant: '<S2>/visAngle'
         */
        if ((int32_T)random_walk_P.DynamicAngle_Value == 0) {
          random_walk_B.DynamicAngleSwitch = random_walk_P.visAngle_Value;
        } else {
          /* Gain: '<S2>/Gain' */
          random_walk_B.Gain_b = random_walk_P.Gain_Gain_o * random_walk_B.Add_o;
          random_walk_B.DynamicAngleSwitch = random_walk_B.Gain_b;
        }

        /* Trigonometry: '<S16>/sin' */
        random_walk_B.sin_l = sin(random_walk_B.DynamicAngleSwitch);

        /* Gain: '<S16>/Inverter' */
        random_walk_B.Inverter_a[0] = random_walk_P.Inverter_Gain *
          random_walk_B.Switch[0];
        random_walk_B.Inverter_a[1] = random_walk_P.Inverter_Gain *
          random_walk_B.Switch[1];

        /* Product: '<S16>/Product3' */
        cg_in_3 = random_walk_B.Inverter_a[0];
        random_walk_B.Product3_g = cg_in_3 * random_walk_B.sin_l;

        /* Trigonometry: '<S16>/cos' */
        random_walk_B.cos_j = cos(random_walk_B.DynamicAngleSwitch);

        /* Product: '<S16>/Product2' */
        cg_in_4 = random_walk_B.Inverter_a[1];
        random_walk_B.Product2_j = cg_in_4 * random_walk_B.cos_j;

        /* Sum: '<S16>/Subtract' */
        random_walk_B.Subtract_g = random_walk_B.Product2_j -
          random_walk_B.Product3_g;

        /* Product: '<S16>/Product1' */
        cg_in_5 = random_walk_B.Inverter_a[1];
        random_walk_B.Product1_jf = cg_in_5 * random_walk_B.sin_l;

        /* Product: '<S16>/Product' */
        cg_in_6 = random_walk_B.Inverter_a[0];
        random_walk_B.Product_d = cg_in_6 * random_walk_B.cos_j;

        /* Sum: '<S16>/Add' */
        random_walk_B.Add_p = random_walk_B.Product_d +
          random_walk_B.Product1_jf;

        /* Gain: '<S16>/Gain' */
        tmp_d = random_walk_B.Add_p;
        tmp_e = random_walk_B.Subtract_g;
        random_walk_B.Gain_a[0] = random_walk_P.Gain_Gain_b * tmp_d;
        random_walk_B.Gain_a[1] = random_walk_P.Gain_Gain_b * tmp_e;
        random_walk_B.LoadSelectSwitch[0] = random_walk_B.Gain_a[0];
        random_walk_B.LoadSelectSwitch[1] = random_walk_B.Gain_a[1];
        break;
      }
    }

    /* Level2 S-Function Block: '<Root>/Behavior RW' (mastercon_rw) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[11];
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
      if (random_walk_B.LogicalOperator) {
        tmp = random_walk_P.zeroX_Value;
        tmp_0 = random_walk_P.zeroY_Value;
        random_walk_B.Switch2[0] = tmp;
        random_walk_B.Switch2[1] = tmp_0;
      } else {
        /* Switch: '<S4>/Switch1' */
        if (random_walk_B.LogicalOperator5_h) {
          /* Logic: '<S5>/Logical Operator6' */
          random_walk_B.LogicalOperator6 = !random_walk_B.LogicalOperator_if;

          /* Logic: '<S5>/Logical Operator3' */
          random_walk_B.LogicalOperator3_d = (random_walk_B.LogicalOperator6 &&
            random_walk_B.LogicalOperator_a);

          /* Switch: '<S5>/Switch' */
          if (random_walk_B.LogicalOperator3_d) {
            /* Gain: '<S5>/Bounding Box Viscosity' */
            random_walk_B.BoundingBoxViscosity[0] =
              random_walk_P.BoundingBoxViscosity_Gain * random_walk_B.Switch[0];
            random_walk_B.BoundingBoxViscosity[1] =
              random_walk_P.BoundingBoxViscosity_Gain * random_walk_B.Switch[1];
            random_walk_B.Switch_c[0] = random_walk_B.BoundingBoxViscosity[0];
            random_walk_B.Switch_c[1] = random_walk_B.BoundingBoxViscosity[1];
          } else {
            /* Product: '<S41>/Product' */
            random_walk_B.Product_n = (int32_T)random_walk_B.LogicalOperator_if ?
              random_walk_B.Product1_m : 0.0;

            /* Gain: '<S41>/Gain1' */
            random_walk_B.Gain1_n = random_walk_P.Gain1_Gain_p *
              random_walk_B.Product_n;

            /* Gain: '<S41>/Gain3' */
            random_walk_B.Gain3 = random_walk_P.Gain3_Gain *
              random_walk_B.Switch[0];

            /* Sum: '<S41>/Add' */
            random_walk_B.Add_c = random_walk_B.Gain3 + random_walk_B.Gain1_n;

            /* Saturate: '<S41>/Saturation' */
            rtsaturate_U0DataInY0Container = rt_SATURATE(random_walk_B.Add_c,
              random_walk_P.Saturation_LowerSat,
              random_walk_P.Saturation_UpperSat);
            random_walk_B.Saturation = rtsaturate_U0DataInY0Container;

            /* Gain: '<S41>/Gain4' */
            random_walk_B.Gain4 = random_walk_P.Gain4_Gain *
              random_walk_B.Switch[1];

            /* Product: '<S41>/Product1' */
            random_walk_B.Product1_j = (int32_T)random_walk_B.LogicalOperator_if
              ? random_walk_B.Product_l : 0.0;

            /* Gain: '<S41>/Gain2' */
            random_walk_B.Gain2 = random_walk_P.Gain2_Gain_d *
              random_walk_B.Product1_j;

            /* Sum: '<S41>/Add1' */
            random_walk_B.Add1_d = random_walk_B.Gain2 + random_walk_B.Gain4;

            /* Saturate: '<S41>/Saturation1' */
            rtsaturate_U0DataInY0Containe_0 = rt_SATURATE(random_walk_B.Add1_d,
              random_walk_P.Saturation1_LowerSat,
              random_walk_P.Saturation1_UpperSat);
            random_walk_B.Saturation1 = rtsaturate_U0DataInY0Containe_0;
            tmp_1 = random_walk_B.Saturation;
            tmp_2 = random_walk_B.Saturation1;
            random_walk_B.Switch_c[0] = tmp_1;
            random_walk_B.Switch_c[1] = tmp_2;
          }

          random_walk_B.Switch1[0] = random_walk_B.Switch_c[0];
          random_walk_B.Switch1[1] = random_walk_B.Switch_c[1];
        } else {
          random_walk_B.Switch1[0] = random_walk_B.BehaviorRW_o1[0];
          random_walk_B.Switch1[1] = random_walk_B.BehaviorRW_o1[1];
        }

        random_walk_B.Switch2[0] = random_walk_B.Switch1[0];
        random_walk_B.Switch2[1] = random_walk_B.Switch1[1];
      }

      /* Output and update for atomic system: '<S4>/Force//Torque Transform' */

      /* Gain: '<S29>/Gain' */
      random_walk_B.Gain_o[0] = random_walk_P.Gain_Gain_e *
        random_walk_B.Switch2[0];
      random_walk_B.Gain_o[1] = random_walk_P.Gain_Gain_e *
        random_walk_B.Switch2[1];

      /* Math Block: '<S33>/Math Function'
       */
      /* Operator : transpose */
      {
        uint32_T count = 0;
        uint32_T row;
        uint32_T col;
        for (row= 0; row < 2; row++) {
          for (col= 0; col < 2; col++) {
            random_walk_B.MathFunction[row + 2 * col] =
              random_walk_B.MatrixConcatenate2[count];
            count++;
          }
        }
      }

      {
        static const int_T dims[3] = { 2, 2, 1 };

        rt_MatMultRR_Dbl(random_walk_B.MatrixMultiply_k,
                         random_walk_B.MathFunction,
                         random_walk_B.Gain_o, &dims[0]);
      }

      /* Gain: '<S4>/MG1' */
      random_walk_B.MG1 = random_walk_P.MG1_Gain *
        random_walk_B.MatrixMultiply_k[0];

      /* Gain: '<S4>/MG2' */
      random_walk_B.MG2 = random_walk_P.MG2_Gain *
        random_walk_B.MatrixMultiply_k[1];
    }

    /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[12];
      sfcnOutputs(rts, 1);
    }

    /* ok to acquire for <S30>/S-Function */
    random_walk_DWork.SFunction_IWORK.AcquireOK = 1;

    /* ok to acquire for <S32>/S-Function */
    random_walk_DWork.SFunction_IWORK_p.AcquireOK = 1;

    /* RelationalOperator: '<S27>/Compare' incorporates:
     *  Constant: '<S27>/Constant'
     */
    random_walk_B.Compare_a = (random_walk_B.MG1 >
      random_walk_P.Constant_Value_b);

    /* RelationalOperator: '<S28>/Compare' incorporates:
     *  Constant: '<S28>/Constant'
     */
    random_walk_B.Compare_h2 = (random_walk_B.MG2 >
      random_walk_P.Constant_Value_g);

    /* SignalConversion: '<S4>/ConcatHiddenBufferAtMatrix ConcatenationInPort0' */
    random_walk_B.MatrixConcatenation[0] = random_walk_B.LogicalOperator5_h;

    /* SignalConversion: '<S4>/ConcatHiddenBufferAtMatrix ConcatenationInPort1' */
    random_walk_B.MatrixConcatenation[1] = random_walk_B.LogicalOperator;

    /* Logic: '<S4>/Logical Operator1' */
    random_walk_B.LogicalOperator1_b = ((random_walk_B.Compare_a != 0U) ||
      (random_walk_B.Compare_h2 != 0U));

    /* ok to acquire for <S7>/S-Function */
    random_walk_DWork.SFunction_IWORK_o.AcquireOK = 1;

    /* Pack: <S9>/Pack */
    (void) memcpy(random_walk_B.Pack,&random_walk_B.BehaviorRW_o8[0],
                  8);
    (void) memcpy(&random_walk_B.Pack[8],&random_walk_B.BehaviorRW_o8[1],
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

    /* RateTransition: '<S9>/Rate Transition' */
    if (tid == 0 && random_walk_rtM->Timing.RateInteraction.TID1_2) {
      for (i = 0; i < 112; i++) {
        random_walk_B.RateTransition[i] = random_walk_B.Pack[i];
      }
    }
  }

  if (tid == 2) {                      /* Sample time: [0.02s, 0.0s] */
    /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[13];
      sfcnOutputs(rts, 2);
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* ok to acquire for <S11>/S-Function */
    random_walk_DWork.SFunction_IWORK_j.AcquireOK = 1;

    /* ok to acquire for <S14>/S-Function */
    random_walk_DWork.SFunction_IWORK_c.AcquireOK = 1;

    /* ok to acquire for <S48>/S-Function */
    random_walk_DWork.SFunction_IWORK_i.AcquireOK = 1;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Clock Block: '<S65>/Clock'
     */
    random_walk_B.Clock_k = random_walk_rtM->Timing.t[0];
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* SignalConversion: '<S65>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_Sampleand = random_walk_B.BehaviorRW_o5;
  }

  /* SubSystem Block: '<S65>/Sample and Hold'
   */
  if (tid == 0) {
    random_walk_SampleandHold(random_walk_B.HiddenBuf_InsertedFor_Sampleand,
      random_walk_B.Clock_k, &random_walk_B.SampleandHold,
      &random_walk_DWork.SampleandHold,
      &random_walk_PrevZCSigState.SampleandHold);
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Sum: '<S65>/Sum' */
    random_walk_B.Sum_l = random_walk_B.Clock_k - random_walk_B.SampleandHold.In;
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* UniformRandomNumber Block: '<S6>/Uniform Random Number'
     */
    random_walk_B.UniformRandomNumber =
      random_walk_DWork.UniformRandomNumber_RWORK.NextOutput;

    /* RelationalOperator: '<S6>/Relational Operator' incorporates:
     *  Constant: '<S6>/JackpotChance'
     */
    random_walk_B.RelationalOperator_e = (random_walk_B.UniformRandomNumber >
      random_walk_P.JackpotChance_Value);

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/RewardJackpot'
     *  Constant: '<S6>/RewardTime'
     */
    if (random_walk_B.RelationalOperator_e) {
      random_walk_B.Switch_l = random_walk_P.RewardTime_Value;
    } else {
      random_walk_B.Switch_l = random_walk_P.RewardJackpot_Value;
    }

    /* SignalConversion: '<S6>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    random_walk_B.HiddenBuf_InsertedFor_Samplea_d = random_walk_B.BehaviorRW_o5;
  }

  /* SubSystem Block: '<S6>/Sample and Hold'
   */
  if (tid == 0) {
    random_walk_SampleandHold(random_walk_B.HiddenBuf_InsertedFor_Samplea_d,
      random_walk_B.Switch_l, &random_walk_B.SampleandHold_g,
      &random_walk_DWork.SampleandHold_g,
      &random_walk_PrevZCSigState.SampleandHold_g);
  }

  {
    int32_T s70_iter;
    real_T tmp;
    real_T tmp_0;
    if (tid == 0) {
      /* RelationalOperator: '<S65>/Relational Operator' */
      random_walk_B.RelationalOperator_o = (random_walk_B.Sum_l <
        random_walk_B.SampleandHold_g.In);

      /* DataTypeConversion: '<S6>/Data Type Conversion' */
      random_walk_B.DataTypeConversion = (real_T)
        random_walk_B.RelationalOperator_o;
    }

    if (tid == 0) {
      for (s70_iter = 0; s70_iter < 4; s70_iter++) {
        random_walk_B.ForIterator = (real_T)s70_iter;

        /* Output and update for iterator system: '<S13>/For Iterator Subsystem' */

        /* Switch: '<S70>/Switch' incorporates:
         *  Constant: '<S70>/Constant2'
         */
        if (random_walk_B.ForIterator >= random_walk_P.Switch_Threshold_a) {
          random_walk_B.Switch_j = random_walk_B.BehaviorRW_o3;
        } else {
          random_walk_B.Switch_j = random_walk_P.Constant2_Value;
        }

        /* Level2 S-Function Block: '<S70>/ToBits1' (Byte2Bits) */
        {
          SimStruct *rts = random_walk_rtM->childSfunctions[2];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
        {
          SimStruct *rts = random_walk_rtM->childSfunctions[3];
          sfcnOutputs(rts, 1);
        }

        /* Sum: '<S70>/Add' incorporates:
         *  Constant: '<S70>/Constant'
         */
        random_walk_B.Add_j = random_walk_B.PCIQUAD04 +
          random_walk_P.Constant_Value_j;

        /* Sum: '<S70>/Add1' incorporates:
         *  Constant: '<S70>/Constant'
         */
        random_walk_B.Add1_oz = random_walk_B.PCIQUAD041 +
          random_walk_P.Constant_Value_j;

        /* Level2 S-Function Block: '<S70>/SerialConverter' (serPos) */
        {
          SimStruct *rts = random_walk_rtM->childSfunctions[4];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/ToBits' (Byte2Bits) */
        {
          SimStruct *rts = random_walk_rtM->childSfunctions[5];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
        {
          SimStruct *rts = random_walk_rtM->childSfunctions[6];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S70>/xPC Target  Time ' (xpctimeinfo) */
        {
          SimStruct *rts = random_walk_rtM->childSfunctions[7];
          sfcnOutputs(rts, 1);
        }

        do {
          /* Output and update for iterator system: '<S70>/While Iterator Subsystem' */

          /* Level2 S-Function Block: '<S72>/xPC Target  Time ' (xpctimeinfo) */
          {
            SimStruct *rts = random_walk_rtM->childSfunctions[0];
            sfcnOutputs(rts, 1);
          }

          /* Sum: '<S72>/Subtract' */
          random_walk_B.Subtract = random_walk_B.xPCTargetTime_a -
            random_walk_B.xPCTargetTime;

          /* Gain: '<S72>/ScaleTouSec' */
          random_walk_B.ScaleTouSec = random_walk_P.ScaleTouSec_Gain *
            random_walk_B.Subtract;

          /* RelationalOperator: '<S74>/Compare' incorporates:
           *  Constant: '<S74>/Constant'
           */
          random_walk_B.Compare_nw = (random_walk_B.ScaleTouSec >
            random_walk_P.Constant_Value_o);

          /* Switch: '<S72>/Switch' incorporates:
           *  Constant: '<S72>/Constant'
           *  Constant: '<S72>/Constant1'
           */
          if (random_walk_B.Compare_nw) {
            random_walk_B.Switch_g = random_walk_P.Constant_Value_m;
          } else {
            random_walk_B.Switch_g = random_walk_P.Constant1_Value;
          }

          /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
          {
            SimStruct *rts = random_walk_rtM->childSfunctions[1];
            sfcnOutputs(rts, 1);
          }

          /* RelationalOperator: '<S73>/Compare' incorporates:
           *  Constant: '<S73>/Constant'
           */
          random_walk_B.Compare_h0 = (random_walk_B.ScaleTouSec <=
            random_walk_P.Constant_Value_a);
        } while (random_walk_B.Compare_h0);
      }

      /* UnitDelay: '<S17>/y' */
      random_walk_B.y = random_walk_DWork.y_DSTATE;

      /* Sum: '<S17>/Add1' */
      random_walk_B.Add1 = random_walk_B.y - random_walk_B.x_k;

      /* UnitDelay: '<S17>/z' */
      random_walk_B.z = random_walk_DWork.z_DSTATE;

      /* Sum: '<S17>/Add3' incorporates:
       *  Constant: '<S17>/rho'
       */
      random_walk_B.Add3 = random_walk_P.rho_Value - random_walk_B.z;

      /* Product: '<S17>/product2' */
      random_walk_B.product2 = random_walk_B.x_k * random_walk_B.Add3;

      /* Sum: '<S17>/Add2' */
      random_walk_B.Add2 = random_walk_B.product2 - random_walk_B.y;

      /* Product: '<S17>/product3' incorporates:
       *  Constant: '<S17>/beta'
       */
      random_walk_B.product3 = random_walk_B.z * random_walk_P.beta_Value;

      /* Product: '<S17>/product4' */
      random_walk_B.product4 = random_walk_B.y * random_walk_B.x_k;

      /* Sum: '<S17>/Add4' */
      random_walk_B.Add4 = random_walk_B.product4 - random_walk_B.product3;

      /* Product: '<S17>/product1' incorporates:
       *  Constant: '<S17>/sigma'
       */
      random_walk_B.product1 = random_walk_B.Add1 * random_walk_P.sigma_Value;

      /* Product: '<S17>/dX' incorporates:
       *  Constant: '<S17>/timescale'
       */
      random_walk_B.dX = random_walk_P.timescale_Value * random_walk_B.product1;

      /* Sum: '<S17>/AddX' */
      random_walk_B.AddX = random_walk_B.x_k + random_walk_B.dX;

      /* Product: '<S17>/dY' incorporates:
       *  Constant: '<S17>/timescale'
       */
      random_walk_B.dY = random_walk_P.timescale_Value * random_walk_B.Add2;

      /* Sum: '<S17>/AddX1' */
      random_walk_B.AddX1 = random_walk_B.y + random_walk_B.dY;

      /* Product: '<S17>/dZ' incorporates:
       *  Constant: '<S17>/timescale'
       */
      random_walk_B.dZ = random_walk_P.timescale_Value * random_walk_B.Add4;

      /* Sum: '<S17>/AddX2' */
      random_walk_B.AddX2 = random_walk_B.z + random_walk_B.dZ;

      /* UnitDelay: '<S18>/y' */
      random_walk_B.y_m = random_walk_DWork.y_DSTATE_j;

      /* Sum: '<S18>/Add1' */
      random_walk_B.Add1_m = random_walk_B.y_m - random_walk_B.x_m;

      /* UnitDelay: '<S18>/z' */
      random_walk_B.z_e = random_walk_DWork.z_DSTATE_d;

      /* Sum: '<S18>/Add3' incorporates:
       *  Constant: '<S18>/rho'
       */
      random_walk_B.Add3_h = random_walk_P.rho_Value_a - random_walk_B.z_e;

      /* Product: '<S18>/product2' */
      random_walk_B.product2_p = random_walk_B.x_m * random_walk_B.Add3_h;

      /* Sum: '<S18>/Add2' */
      random_walk_B.Add2_e = random_walk_B.product2_p - random_walk_B.y_m;

      /* Product: '<S18>/product3' incorporates:
       *  Constant: '<S18>/beta'
       */
      random_walk_B.product3_c = random_walk_B.z_e * random_walk_P.beta_Value_i;

      /* Product: '<S18>/product4' */
      random_walk_B.product4_j = random_walk_B.y_m * random_walk_B.x_m;

      /* Sum: '<S18>/Add4' */
      random_walk_B.Add4_e = random_walk_B.product4_j - random_walk_B.product3_c;

      /* Product: '<S18>/product1' incorporates:
       *  Constant: '<S18>/sigma'
       */
      random_walk_B.product1_i = random_walk_B.Add1_m *
        random_walk_P.sigma_Value_l;

      /* Product: '<S18>/dX' incorporates:
       *  Constant: '<S18>/timescale'
       */
      random_walk_B.dX_o = random_walk_P.timescale_Value_m *
        random_walk_B.product1_i;

      /* Sum: '<S18>/AddX' */
      random_walk_B.AddX_o = random_walk_B.x_m + random_walk_B.dX_o;

      /* Product: '<S18>/dY' incorporates:
       *  Constant: '<S18>/timescale'
       */
      random_walk_B.dY_g = random_walk_P.timescale_Value_m *
        random_walk_B.Add2_e;

      /* Sum: '<S18>/AddX1' */
      random_walk_B.AddX1_l = random_walk_B.y_m + random_walk_B.dY_g;

      /* Product: '<S18>/dZ' incorporates:
       *  Constant: '<S18>/timescale'
       */
      random_walk_B.dZ_o = random_walk_P.timescale_Value_m *
        random_walk_B.Add4_e;

      /* Sum: '<S18>/AddX2' */
      random_walk_B.AddX2_l = random_walk_B.z_e + random_walk_B.dZ_o;

      /* UnitDelay: '<S19>/y' */
      random_walk_B.y_f = random_walk_DWork.y_DSTATE_c;

      /* Sum: '<S19>/Add1' */
      random_walk_B.Add1_mk = random_walk_B.y_f - random_walk_B.x_o;

      /* UnitDelay: '<S19>/z' */
      random_walk_B.z_g = random_walk_DWork.z_DSTATE_b;

      /* Sum: '<S19>/Add3' incorporates:
       *  Constant: '<S19>/rho'
       */
      random_walk_B.Add3_c = random_walk_P.rho_Value_m - random_walk_B.z_g;

      /* Product: '<S19>/product2' */
      random_walk_B.product2_e = random_walk_B.x_o * random_walk_B.Add3_c;

      /* Sum: '<S19>/Add2' */
      random_walk_B.Add2_k = random_walk_B.product2_e - random_walk_B.y_f;

      /* Product: '<S19>/product3' incorporates:
       *  Constant: '<S19>/beta'
       */
      random_walk_B.product3_o = random_walk_B.z_g * random_walk_P.beta_Value_p;

      /* Product: '<S19>/product4' */
      random_walk_B.product4_o = random_walk_B.y_f * random_walk_B.x_o;

      /* Sum: '<S19>/Add4' */
      random_walk_B.Add4_el = random_walk_B.product4_o -
        random_walk_B.product3_o;

      /* Product: '<S19>/product1' incorporates:
       *  Constant: '<S19>/sigma'
       */
      random_walk_B.product1_a = random_walk_B.Add1_mk *
        random_walk_P.sigma_Value_j;

      /* Product: '<S19>/dX' incorporates:
       *  Constant: '<S19>/timescale'
       */
      random_walk_B.dX_p = random_walk_P.timescale_Value_d *
        random_walk_B.product1_a;

      /* Sum: '<S19>/AddX' */
      random_walk_B.AddX_d = random_walk_B.x_o + random_walk_B.dX_p;

      /* Product: '<S19>/dY' incorporates:
       *  Constant: '<S19>/timescale'
       */
      random_walk_B.dY_a = random_walk_P.timescale_Value_d *
        random_walk_B.Add2_k;

      /* Sum: '<S19>/AddX1' */
      random_walk_B.AddX1_p = random_walk_B.y_f + random_walk_B.dY_a;

      /* Product: '<S19>/dZ' incorporates:
       *  Constant: '<S19>/timescale'
       */
      random_walk_B.dZ_m = random_walk_P.timescale_Value_d *
        random_walk_B.Add4_el;

      /* Sum: '<S19>/AddX2' */
      random_walk_B.AddX2_b = random_walk_B.z_g + random_walk_B.dZ_m;

      /* UnitDelay: '<S20>/y' */
      random_walk_B.y_k = random_walk_DWork.y_DSTATE_l;

      /* Sum: '<S20>/Add1' */
      random_walk_B.Add1_c = random_walk_B.y_k - random_walk_B.x_mw;

      /* UnitDelay: '<S20>/z' */
      random_walk_B.z_m = random_walk_DWork.z_DSTATE_j;

      /* Sum: '<S20>/Add3' incorporates:
       *  Constant: '<S20>/rho'
       */
      random_walk_B.Add3_hn = random_walk_P.rho_Value_e - random_walk_B.z_m;

      /* Product: '<S20>/product2' */
      random_walk_B.product2_d = random_walk_B.x_mw * random_walk_B.Add3_hn;

      /* Sum: '<S20>/Add2' */
      random_walk_B.Add2_g = random_walk_B.product2_d - random_walk_B.y_k;

      /* Product: '<S20>/product3' incorporates:
       *  Constant: '<S20>/beta'
       */
      random_walk_B.product3_i = random_walk_B.z_m * random_walk_P.beta_Value_f;

      /* Product: '<S20>/product4' */
      random_walk_B.product4_i = random_walk_B.y_k * random_walk_B.x_mw;

      /* Sum: '<S20>/Add4' */
      random_walk_B.Add4_o = random_walk_B.product4_i - random_walk_B.product3_i;

      /* Product: '<S20>/product1' incorporates:
       *  Constant: '<S20>/sigma'
       */
      random_walk_B.product1_g = random_walk_B.Add1_c *
        random_walk_P.sigma_Value_b;

      /* Product: '<S20>/dX' incorporates:
       *  Constant: '<S20>/timescale'
       */
      random_walk_B.dX_b = random_walk_P.timescale_Value_p *
        random_walk_B.product1_g;

      /* Sum: '<S20>/AddX' */
      random_walk_B.AddX_b = random_walk_B.x_mw + random_walk_B.dX_b;

      /* Product: '<S20>/dY' incorporates:
       *  Constant: '<S20>/timescale'
       */
      random_walk_B.dY_n = random_walk_P.timescale_Value_p *
        random_walk_B.Add2_g;

      /* Sum: '<S20>/AddX1' */
      random_walk_B.AddX1_lw = random_walk_B.y_k + random_walk_B.dY_n;

      /* Product: '<S20>/dZ' incorporates:
       *  Constant: '<S20>/timescale'
       */
      random_walk_B.dZ_n = random_walk_P.timescale_Value_p *
        random_walk_B.Add4_o;

      /* Sum: '<S20>/AddX2' */
      random_walk_B.AddX2_a = random_walk_B.z_m + random_walk_B.dZ_n;

      /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix Concatenation1InPort0' */
      tmp = random_walk_B.Product1_m;
      tmp_0 = random_walk_B.Product_l;
      random_walk_B.MatrixConcatenation1[0] = tmp;
      random_walk_B.MatrixConcatenation1[1] = tmp_0;

      /* SignalConversion: '<Root>/ConcatHiddenBufferAtMatrix Concatenation1InPort1' */
      random_walk_B.MatrixConcatenation1[2] = random_walk_B.Switch[0];
      random_walk_B.MatrixConcatenation1[3] = random_walk_B.Switch[1];

      /* UnitDelay: '<S23>/y' */
      random_walk_B.y_g = random_walk_DWork.y_DSTATE_k;

      /* Sum: '<S23>/Add1' */
      random_walk_B.Add1_o = random_walk_B.y_g - random_walk_B.x;

      /* UnitDelay: '<S23>/z' */
      random_walk_B.z_l = random_walk_DWork.z_DSTATE_m;

      /* Sum: '<S23>/Add3' incorporates:
       *  Constant: '<S23>/rho'
       */
      random_walk_B.Add3_j = random_walk_P.rho_Value_am - random_walk_B.z_l;

      /* Product: '<S23>/product2' */
      random_walk_B.product2_c = random_walk_B.x * random_walk_B.Add3_j;

      /* Sum: '<S23>/Add2' */
      random_walk_B.Add2_c = random_walk_B.product2_c - random_walk_B.y_g;

      /* Product: '<S23>/product3' incorporates:
       *  Constant: '<S23>/beta'
       */
      random_walk_B.product3_m = random_walk_B.z_l * random_walk_P.beta_Value_o;

      /* Product: '<S23>/product4' */
      random_walk_B.product4_p = random_walk_B.y_g * random_walk_B.x;

      /* Sum: '<S23>/Add4' */
      random_walk_B.Add4_b = random_walk_B.product4_p - random_walk_B.product3_m;

      /* Product: '<S23>/product1' incorporates:
       *  Constant: '<S23>/sigma'
       */
      random_walk_B.product1_e = random_walk_B.Add1_o *
        random_walk_P.sigma_Value_m;

      /* Product: '<S23>/dX' incorporates:
       *  Constant: '<S23>/timescale'
       */
      random_walk_B.dX_l = random_walk_P.timescale_Value_e *
        random_walk_B.product1_e;

      /* Sum: '<S23>/AddX' */
      random_walk_B.AddX_f = random_walk_B.x + random_walk_B.dX_l;

      /* Product: '<S23>/dY' incorporates:
       *  Constant: '<S23>/timescale'
       */
      random_walk_B.dY_o = random_walk_P.timescale_Value_e *
        random_walk_B.Add2_c;

      /* Sum: '<S23>/AddX1' */
      random_walk_B.AddX1_o = random_walk_B.y_g + random_walk_B.dY_o;

      /* Product: '<S23>/dZ' incorporates:
       *  Constant: '<S23>/timescale'
       */
      random_walk_B.dZ_j = random_walk_P.timescale_Value_e *
        random_walk_B.Add4_b;

      /* Sum: '<S23>/AddX2' */
      random_walk_B.AddX2_f = random_walk_B.z_l + random_walk_B.dZ_j;

      /* UnitDelay: '<S24>/y' */
      random_walk_B.y_e = random_walk_DWork.y_DSTATE_ky;

      /* Sum: '<S24>/Add1' */
      random_walk_B.Add1_b = random_walk_B.y_e - random_walk_B.x_f;

      /* UnitDelay: '<S24>/z' */
      random_walk_B.z_o = random_walk_DWork.z_DSTATE_f;

      /* Sum: '<S24>/Add3' incorporates:
       *  Constant: '<S24>/rho'
       */
      random_walk_B.Add3_e = random_walk_P.rho_Value_j - random_walk_B.z_o;

      /* Product: '<S24>/product2' */
      random_walk_B.product2_l = random_walk_B.x_f * random_walk_B.Add3_e;

      /* Sum: '<S24>/Add2' */
      random_walk_B.Add2_b = random_walk_B.product2_l - random_walk_B.y_e;

      /* Product: '<S24>/product3' incorporates:
       *  Constant: '<S24>/beta'
       */
      random_walk_B.product3_b = random_walk_B.z_o * random_walk_P.beta_Value_g;

      /* Product: '<S24>/product4' */
      random_walk_B.product4_d = random_walk_B.y_e * random_walk_B.x_f;

      /* Sum: '<S24>/Add4' */
      random_walk_B.Add4_bs = random_walk_B.product4_d -
        random_walk_B.product3_b;

      /* Product: '<S24>/product1' incorporates:
       *  Constant: '<S24>/sigma'
       */
      random_walk_B.product1_f = random_walk_B.Add1_b *
        random_walk_P.sigma_Value_h;

      /* Product: '<S24>/dX' incorporates:
       *  Constant: '<S24>/timescale'
       */
      random_walk_B.dX_m = random_walk_P.timescale_Value_py *
        random_walk_B.product1_f;

      /* Sum: '<S24>/AddX' */
      random_walk_B.AddX_j = random_walk_B.x_f + random_walk_B.dX_m;

      /* Product: '<S24>/dY' incorporates:
       *  Constant: '<S24>/timescale'
       */
      random_walk_B.dY_f = random_walk_P.timescale_Value_py *
        random_walk_B.Add2_b;

      /* Sum: '<S24>/AddX1' */
      random_walk_B.AddX1_b = random_walk_B.y_e + random_walk_B.dY_f;

      /* Product: '<S24>/dZ' incorporates:
       *  Constant: '<S24>/timescale'
       */
      random_walk_B.dZ_g = random_walk_P.timescale_Value_py *
        random_walk_B.Add4_bs;

      /* Sum: '<S24>/AddX2' */
      random_walk_B.AddX2_e = random_walk_B.z_o + random_walk_B.dZ_g;

      /* UnitDelay: '<S25>/y' */
      random_walk_B.y_j = random_walk_DWork.y_DSTATE_n;

      /* Sum: '<S25>/Add1' */
      random_walk_B.Add1_l = random_walk_B.y_j - random_walk_B.x_h;

      /* UnitDelay: '<S25>/z' */
      random_walk_B.z_n = random_walk_DWork.z_DSTATE_dr;

      /* Sum: '<S25>/Add3' incorporates:
       *  Constant: '<S25>/rho'
       */
      random_walk_B.Add3_p = random_walk_P.rho_Value_eo - random_walk_B.z_n;

      /* Product: '<S25>/product2' */
      random_walk_B.product2_g = random_walk_B.x_h * random_walk_B.Add3_p;

      /* Sum: '<S25>/Add2' */
      random_walk_B.Add2_l = random_walk_B.product2_g - random_walk_B.y_j;

      /* Product: '<S25>/product3' incorporates:
       *  Constant: '<S25>/beta'
       */
      random_walk_B.product3_d = random_walk_B.z_n * random_walk_P.beta_Value_o2;

      /* Product: '<S25>/product4' */
      random_walk_B.product4_j1 = random_walk_B.y_j * random_walk_B.x_h;

      /* Sum: '<S25>/Add4' */
      random_walk_B.Add4_k = random_walk_B.product4_j1 -
        random_walk_B.product3_d;

      /* Product: '<S25>/product1' incorporates:
       *  Constant: '<S25>/sigma'
       */
      random_walk_B.product1_ae = random_walk_B.Add1_l *
        random_walk_P.sigma_Value_hc;

      /* Product: '<S25>/dX' incorporates:
       *  Constant: '<S25>/timescale'
       */
      random_walk_B.dX_f = random_walk_P.timescale_Value_dn *
        random_walk_B.product1_ae;

      /* Sum: '<S25>/AddX' */
      random_walk_B.AddX_on = random_walk_B.x_h + random_walk_B.dX_f;

      /* Product: '<S25>/dY' incorporates:
       *  Constant: '<S25>/timescale'
       */
      random_walk_B.dY_b = random_walk_P.timescale_Value_dn *
        random_walk_B.Add2_l;

      /* Sum: '<S25>/AddX1' */
      random_walk_B.AddX1_j = random_walk_B.y_j + random_walk_B.dY_b;

      /* Product: '<S25>/dZ' incorporates:
       *  Constant: '<S25>/timescale'
       */
      random_walk_B.dZ_f = random_walk_P.timescale_Value_dn *
        random_walk_B.Add4_k;

      /* Sum: '<S25>/AddX2' */
      random_walk_B.AddX2_h = random_walk_B.z_n + random_walk_B.dZ_f;

      /* UnitDelay: '<S26>/y' */
      random_walk_B.y_o = random_walk_DWork.y_DSTATE_d;

      /* Sum: '<S26>/Add1' */
      random_walk_B.Add1_n = random_walk_B.y_o - random_walk_B.x_l;

      /* UnitDelay: '<S26>/z' */
      random_walk_B.z_j = random_walk_DWork.z_DSTATE_dv;

      /* Sum: '<S26>/Add3' incorporates:
       *  Constant: '<S26>/rho'
       */
      random_walk_B.Add3_a = random_walk_P.rho_Value_mm - random_walk_B.z_j;

      /* Product: '<S26>/product2' */
      random_walk_B.product2_cg = random_walk_B.x_l * random_walk_B.Add3_a;

      /* Sum: '<S26>/Add2' */
      random_walk_B.Add2_d = random_walk_B.product2_cg - random_walk_B.y_o;

      /* Product: '<S26>/product3' incorporates:
       *  Constant: '<S26>/beta'
       */
      random_walk_B.product3_im = random_walk_B.z_j * random_walk_P.beta_Value_e;

      /* Product: '<S26>/product4' */
      random_walk_B.product4_p0 = random_walk_B.y_o * random_walk_B.x_l;

      /* Sum: '<S26>/Add4' */
      random_walk_B.Add4_h = random_walk_B.product4_p0 -
        random_walk_B.product3_im;

      /* Product: '<S26>/product1' incorporates:
       *  Constant: '<S26>/sigma'
       */
      random_walk_B.product1_o = random_walk_B.Add1_n *
        random_walk_P.sigma_Value_mj;

      /* Product: '<S26>/dX' incorporates:
       *  Constant: '<S26>/timescale'
       */
      random_walk_B.dX_bi = random_walk_P.timescale_Value_h *
        random_walk_B.product1_o;

      /* Sum: '<S26>/AddX' */
      random_walk_B.AddX_jl = random_walk_B.x_l + random_walk_B.dX_bi;

      /* Product: '<S26>/dY' incorporates:
       *  Constant: '<S26>/timescale'
       */
      random_walk_B.dY_na = random_walk_P.timescale_Value_h *
        random_walk_B.Add2_d;

      /* Sum: '<S26>/AddX1' */
      random_walk_B.AddX1_bw = random_walk_B.y_o + random_walk_B.dY_na;

      /* Product: '<S26>/dZ' incorporates:
       *  Constant: '<S26>/timescale'
       */
      random_walk_B.dZ_i = random_walk_P.timescale_Value_h *
        random_walk_B.Add4_h;

      /* Sum: '<S26>/AddX2' */
      random_walk_B.AddX2_g = random_walk_B.z_j + random_walk_B.dZ_i;

      /* Sum: '<S8>/Add' */
      random_walk_B.Add_oe = random_walk_B.BehaviorRW_o4[1] +
        random_walk_B.BehaviorRW_o4[3];

      /* Sum: '<S8>/Add1' */
      random_walk_B.Add1_f = random_walk_B.BehaviorRW_o4[2] +
        random_walk_B.BehaviorRW_o4[4];

      /* Gain: '<S8>/Gain' */
      random_walk_B.Gain_p = random_walk_P.Gain_Gain_g * random_walk_B.Add_oe;

      /* Gain: '<S8>/Gain1' */
      random_walk_B.Gain1_c = random_walk_P.Gain1_Gain_d * random_walk_B.Add1_f;
    }
  }
}

/* Model update function */
void random_walk_update(int_T tid)
{
  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S31>/Memory' */
    random_walk_DWork.Memory_PreviousInput = random_walk_B.LogicalOperator;

    /* Update for Memory: '<S4>/Memory' */
    random_walk_DWork.Memory_PreviousInput_i = random_walk_B.LogicalOperator1_b;
  }

  if (tid == 0) {                      /* Sample time: [0.0s, 0.0s] */
    /* Derivative Block: '<S67>/Derivative' */
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

    /* Derivative Block: '<S68>/Derivative' */
    {
      real_T timeStampA = random_walk_DWork.Derivative_RWORK_a.TimeStampA;
      real_T timeStampB = random_walk_DWork.Derivative_RWORK_a.TimeStampB;
      real_T *lastBank = &random_walk_DWork.Derivative_RWORK_a.TimeStampA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }

      *lastBank++ = random_walk_rtM->Timing.t[0];
      *lastBank++ = random_walk_B.DigitalFilter2_k;
    }
  }

  if (tid == 0) {                      /* Sample time: [0.001s, 0.0s] */
    /* Update for Memory: '<S43>/Memory' */
    random_walk_DWork.Memory_PreviousInput_c = random_walk_B.LogicalOperator_if;

    /* Update for Memory: '<S47>/Memory' */
    random_walk_DWork.Memory_PreviousInput_e = random_walk_B.LogicalOperator_ai;

    /* Update for UnitDelay: '<S61>/Delay Input1' */
    random_walk_DWork.DelayInput1_DSTATE = random_walk_B.Compare_h;

    /* Update for Memory: '<S45>/Memory' */
    random_walk_DWork.Memory_PreviousInput_d = random_walk_B.LogicalOperator_b;

    /* Update for UnitDelay: '<S46>/Delay Input1' */
    random_walk_DWork.DelayInput1_DSTATE_h = random_walk_B.Compare_g;

    /* Update for UnitDelay: '<S39>/Delay Input1' */
    random_walk_DWork.DelayInput1_DSTATE_k = random_walk_B.Compare_n;

    /* Update for Memory: '<S44>/Memory' */
    random_walk_DWork.Memory_PreviousInput_b = random_walk_B.LogicalOperator_e;

    /* Update for UnitDelay: '<S38>/Delay Input1' */
    random_walk_DWork.DelayInput1_DSTATE_f = random_walk_B.Compare_my;

    /* Update for Memory: '<S42>/Memory' */
    random_walk_DWork.Memory_PreviousInput_h = random_walk_B.Logic[0];

    /* Update for UnitDelay: '<S23>/x' */
    random_walk_DWork.x_DSTATE = random_walk_B.AddX_f;

    /* Update for UnitDelay: '<S24>/x' */
    random_walk_DWork.x_DSTATE_m = random_walk_B.AddX_j;

    /* Update for UnitDelay: '<S25>/x' */
    random_walk_DWork.x_DSTATE_d = random_walk_B.AddX_on;

    /* Update for UnitDelay: '<S26>/x' */
    random_walk_DWork.x_DSTATE_k = random_walk_B.AddX_jl;

    /* Update for UnitDelay: '<S17>/x' */
    random_walk_DWork.x_DSTATE_b = random_walk_B.AddX;

    /* Update for UnitDelay: '<S18>/x' */
    random_walk_DWork.x_DSTATE_g = random_walk_B.AddX_o;

    /* Update for UnitDelay: '<S19>/x' */
    random_walk_DWork.x_DSTATE_l = random_walk_B.AddX_d;

    /* Update for UnitDelay: '<S20>/x' */
    random_walk_DWork.x_DSTATE_n = random_walk_B.AddX_b;

    /* Level2 S-Function Block: '<Root>/Behavior RW' (mastercon_rw) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[11];
      sfcnUpdate(rts, 1);
      if (ssGetErrorStatus(rts) != NULL)
        return;
    }

    /* UniformRandomNumber Block: '<S6>/Uniform Random Number' */
    random_walk_DWork.UniformRandomNumber_RWORK.NextOutput = rt_Urand((uint32_T *)
      &random_walk_DWork.UniformRandomNumber_IWORK.RandSeed) *
      (random_walk_P.UniformRandomNumber_Max -
       random_walk_P.UniformRandomNumber_Min) +
      random_walk_P.UniformRandomNumber_Min;
  }

  if (tid == 0) {
    /* Update for UnitDelay: '<S17>/y' */
    random_walk_DWork.y_DSTATE = random_walk_B.AddX1;

    /* Update for UnitDelay: '<S17>/z' */
    random_walk_DWork.z_DSTATE = random_walk_B.AddX2;

    /* Update for UnitDelay: '<S18>/y' */
    random_walk_DWork.y_DSTATE_j = random_walk_B.AddX1_l;

    /* Update for UnitDelay: '<S18>/z' */
    random_walk_DWork.z_DSTATE_d = random_walk_B.AddX2_l;

    /* Update for UnitDelay: '<S19>/y' */
    random_walk_DWork.y_DSTATE_c = random_walk_B.AddX1_p;

    /* Update for UnitDelay: '<S19>/z' */
    random_walk_DWork.z_DSTATE_b = random_walk_B.AddX2_b;

    /* Update for UnitDelay: '<S20>/y' */
    random_walk_DWork.y_DSTATE_l = random_walk_B.AddX1_lw;

    /* Update for UnitDelay: '<S20>/z' */
    random_walk_DWork.z_DSTATE_j = random_walk_B.AddX2_a;

    /* Update for UnitDelay: '<S23>/y' */
    random_walk_DWork.y_DSTATE_k = random_walk_B.AddX1_o;

    /* Update for UnitDelay: '<S23>/z' */
    random_walk_DWork.z_DSTATE_m = random_walk_B.AddX2_f;

    /* Update for UnitDelay: '<S24>/y' */
    random_walk_DWork.y_DSTATE_ky = random_walk_B.AddX1_b;

    /* Update for UnitDelay: '<S24>/z' */
    random_walk_DWork.z_DSTATE_f = random_walk_B.AddX2_e;

    /* Update for UnitDelay: '<S25>/y' */
    random_walk_DWork.y_DSTATE_n = random_walk_B.AddX1_j;

    /* Update for UnitDelay: '<S25>/z' */
    random_walk_DWork.z_DSTATE_dr = random_walk_B.AddX2_h;

    /* Update for UnitDelay: '<S26>/y' */
    random_walk_DWork.y_DSTATE_d = random_walk_B.AddX1_bw;

    /* Update for UnitDelay: '<S26>/z' */
    random_walk_DWork.z_DSTATE_dv = random_walk_B.AddX2_g;
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
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    if (!(++random_walk_rtM->Timing.clockTick2))
      ++random_walk_rtM->Timing.clockTickH2;
    random_walk_rtM->Timing.t[2] = random_walk_rtM->Timing.clockTick2 *
      random_walk_rtM->Timing.stepSize2 + random_walk_rtM->Timing.clockTickH2 *
      random_walk_rtM->Timing.stepSize2 * 4294967296.0;
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
    random_walk_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    random_walk_rtM->Timing.sampleTimes =
      (&random_walk_rtM->Timing.sampleTimesArray[0]);
    random_walk_rtM->Timing.offsetTimes =
      (&random_walk_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    random_walk_rtM->Timing.sampleTimes[0] = (0.0);
    random_walk_rtM->Timing.sampleTimes[1] = (0.001);
    random_walk_rtM->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    random_walk_rtM->Timing.offsetTimes[0] = (0.0);
    random_walk_rtM->Timing.offsetTimes[1] = (0.0);
    random_walk_rtM->Timing.offsetTimes[2] = (0.0);
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
  random_walk_rtM->Timing.stepSize2 = 0.02;

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
        1,
        1,
        1,
        1,
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
        "random_walk/Velocity Calculation/Pos2VelX/Digital Filter2",
        "random_walk/Velocity Calculation/Pos2VelX/Digital Filter",
        "random_walk/Velocity Calculation/Pos2VelY/Digital Filter2",
        "random_walk/Velocity Calculation/Pos2VelY/Digital Filter",
        "random_walk/Force Generator/LorentzForce/Lorentz/x",
        "random_walk/Force Generator/LorentzForce/Lorentz1/x",
        "random_walk/Force Generator/LorentzForce/Lorentz2/x",
        "random_walk/Force Generator/LorentzForce/Lorentz3/x",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz/x",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz1/x",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz2/x",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz3/x",
        "random_walk/Behavior RW",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz/y",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz/z",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz1/y",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz1/z",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz2/y",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz2/z",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz3/y",
        "random_walk/Catch Force Generator/LorentzForce/Lorentz3/z",
        "random_walk/Force Generator/LorentzForce/Lorentz/y",
        "random_walk/Force Generator/LorentzForce/Lorentz/z",
        "random_walk/Force Generator/LorentzForce/Lorentz1/y",
        "random_walk/Force Generator/LorentzForce/Lorentz1/z",
        "random_walk/Force Generator/LorentzForce/Lorentz2/y",
        "random_walk/Force Generator/LorentzForce/Lorentz2/z",
        "random_walk/Force Generator/LorentzForce/Lorentz3/y",
        "random_walk/Force Generator/LorentzForce/Lorentz3/z",
        "random_walk/Recentering Subsystem/Timer/Detect Fall\nNonpositive/Delay Input1",
        "random_walk/Recentering Subsystem/Start Moving/Delay Input1",
        "random_walk/Recentering Subsystem/Falling Edge1/Delay Input1",
        "random_walk/Recentering Subsystem/Falling Edge/Delay Input1" };

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

      rtliSetLogXSignalInfo(random_walk_rtM->rtwLogInfo,
                            &rt_LoggedStateSignalInfo);
    }

    {
      static void * rt_LoggedStateSignalPtrs[33];
      rt_LoggedStateSignalPtrs[0] = (void*)
        &random_walk_DWork.DigitalFilter2_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[1] = (void*)
        &random_walk_DWork.DigitalFilter_FILT_STATES[0];
      rt_LoggedStateSignalPtrs[2] = (void*)
        &random_walk_DWork.DigitalFilter2_FILT_STATES_a[0];
      rt_LoggedStateSignalPtrs[3] = (void*)
        &random_walk_DWork.DigitalFilter_FILT_STATES_m[0];
      rt_LoggedStateSignalPtrs[4] = (void*)&random_walk_DWork.x_DSTATE;
      rt_LoggedStateSignalPtrs[5] = (void*)&random_walk_DWork.x_DSTATE_m;
      rt_LoggedStateSignalPtrs[6] = (void*)&random_walk_DWork.x_DSTATE_d;
      rt_LoggedStateSignalPtrs[7] = (void*)&random_walk_DWork.x_DSTATE_k;
      rt_LoggedStateSignalPtrs[8] = (void*)&random_walk_DWork.x_DSTATE_b;
      rt_LoggedStateSignalPtrs[9] = (void*)&random_walk_DWork.x_DSTATE_g;
      rt_LoggedStateSignalPtrs[10] = (void*)&random_walk_DWork.x_DSTATE_l;
      rt_LoggedStateSignalPtrs[11] = (void*)&random_walk_DWork.x_DSTATE_n;
      rt_LoggedStateSignalPtrs[12] = (void*)&random_walk_DWork.BehaviorRW_DSTATE;
      rt_LoggedStateSignalPtrs[13] = (void*)&random_walk_DWork.y_DSTATE;
      rt_LoggedStateSignalPtrs[14] = (void*)&random_walk_DWork.z_DSTATE;
      rt_LoggedStateSignalPtrs[15] = (void*)&random_walk_DWork.y_DSTATE_j;
      rt_LoggedStateSignalPtrs[16] = (void*)&random_walk_DWork.z_DSTATE_d;
      rt_LoggedStateSignalPtrs[17] = (void*)&random_walk_DWork.y_DSTATE_c;
      rt_LoggedStateSignalPtrs[18] = (void*)&random_walk_DWork.z_DSTATE_b;
      rt_LoggedStateSignalPtrs[19] = (void*)&random_walk_DWork.y_DSTATE_l;
      rt_LoggedStateSignalPtrs[20] = (void*)&random_walk_DWork.z_DSTATE_j;
      rt_LoggedStateSignalPtrs[21] = (void*)&random_walk_DWork.y_DSTATE_k;
      rt_LoggedStateSignalPtrs[22] = (void*)&random_walk_DWork.z_DSTATE_m;
      rt_LoggedStateSignalPtrs[23] = (void*)&random_walk_DWork.y_DSTATE_ky;
      rt_LoggedStateSignalPtrs[24] = (void*)&random_walk_DWork.z_DSTATE_f;
      rt_LoggedStateSignalPtrs[25] = (void*)&random_walk_DWork.y_DSTATE_n;
      rt_LoggedStateSignalPtrs[26] = (void*)&random_walk_DWork.z_DSTATE_dr;
      rt_LoggedStateSignalPtrs[27] = (void*)&random_walk_DWork.y_DSTATE_d;
      rt_LoggedStateSignalPtrs[28] = (void*)&random_walk_DWork.z_DSTATE_dv;
      rt_LoggedStateSignalPtrs[29] = (void*)
        &random_walk_DWork.DelayInput1_DSTATE;
      rt_LoggedStateSignalPtrs[30] = (void*)
        &random_walk_DWork.DelayInput1_DSTATE_h;
      rt_LoggedStateSignalPtrs[31] = (void*)
        &random_walk_DWork.DelayInput1_DSTATE_k;
      rt_LoggedStateSignalPtrs[32] = (void*)
        &random_walk_DWork.DelayInput1_DSTATE_f;
      rtliSetLogXSignalPtrs(random_walk_rtM->rtwLogInfo, (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
    }

    rtliSetLogY(random_walk_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(random_walk_rtM->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(random_walk_rtM->rtwLogInfo, NULL);
  }

  /* external mode info */
  random_walk_rtM->Sizes.checksums[0] = (4260132490U);
  random_walk_rtM->Sizes.checksums[1] = (2437341772U);
  random_walk_rtM->Sizes.checksums[2] = (238009788U);
  random_walk_rtM->Sizes.checksums[3] = (3085687669U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[34];
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
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = (sysRanDType *)
      &random_walk_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &random_walk_DWork.EnabledSubsystem_d.EnabledSubsystem_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &random_walk_DWork.EnabledSubsystem_n.EnabledSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &random_walk_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &random_walk_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)
      &random_walk_DWork.SampleandHold_g.SampleandHold_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &random_walk_DWork.SampleandHold.SampleandHold_SubsysRanBC;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
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
    for (i = 0; i < 241; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&random_walk_B.ForIterator);
    for (i = 0; i < 90; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    ((real_T*)&random_walk_B.SampleandHold.In)[0] = 0.0;
    ((real_T*)&random_walk_B.SampleandHold_g.In)[0] = 0.0;
    ((real_T*)&random_walk_B.EnabledSubsystem_l.In1)[0] = 0.0;
    ((real_T*)&random_walk_B.EnabledSubsystem_o.In1)[0] = 0.0;
    ((real_T*)&random_walk_B.EnabledSubsystem_n.In1)[0] = 0.0;
    ((real_T*)&random_walk_B.EnabledSubsystem_d.In1)[0] = 0.0;
    ((real_T*)&random_walk_B.EnabledSubsystem.In1)[0] = 0.0;
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
    for (i = 0; i < 660; i++) {
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

  random_walk_rtM->Sizes.numSFcns = (14);

  /* register each child */
  {
    (void) memset((void *)&random_walk_rtM->NonInlinedSFcns.childSFunctions[0],0,
                  14*sizeof(SimStruct));
    random_walk_rtM->childSfunctions =
      (&random_walk_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 14; i++) {
        random_walk_rtM->childSfunctions[i] =
          (&random_walk_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: random_walk/<S72>/xPC Target  Time  (xpctimeinfo) */
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

    /* Level2 S-Function Block: random_walk/<S72>/PCI-6025E  (donipcie) */
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
          sfcnUPtrs[0] = &random_walk_B.Switch_g;
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

    /* Level2 S-Function Block: random_walk/<S70>/ToBits1 (Byte2Bits) */
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
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.Switch_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &random_walk_B.ToBits1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &random_walk_B.ToBits1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &random_walk_B.ToBits1_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &random_walk_B.ToBits1_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &random_walk_B.ToBits1_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &random_walk_B.ToBits1_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &random_walk_B.ToBits1_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &random_walk_B.ToBits1_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits1");
      ssSetPath(rts,
                "random_walk/XY Position Subsystem/For Iterator Subsystem/ToBits1");
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

    /* Level2 S-Function Block: random_walk/<S70>/Port A (dopci8255) */
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
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.ToBits1_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &random_walk_B.ToBits1_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn3.UPtrs2;
          sfcnUPtrs[0] = &random_walk_B.ToBits1_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn3.UPtrs3;
          sfcnUPtrs[0] = &random_walk_B.ToBits1_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn3.UPtrs4;
          sfcnUPtrs[0] = &random_walk_B.ToBits1_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn3.UPtrs5;
          sfcnUPtrs[0] = &random_walk_B.ToBits1_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn3.UPtrs6;
          sfcnUPtrs[0] = &random_walk_B.ToBits1_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn3.UPtrs7;
          sfcnUPtrs[0] = &random_walk_B.ToBits1_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port A");
      ssSetPath(rts,
                "random_walk/XY Position Subsystem/For Iterator Subsystem/Port A");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn3.params;
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
          &random_walk_rtM->NonInlinedSFcns.Sfcn3.dWork;
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

    /* Level2 S-Function Block: random_walk/<S70>/SerialConverter (serPos) */
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
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.ForIterator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &random_walk_B.Add_j;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn4.UPtrs2;
          sfcnUPtrs[0] = &random_walk_B.Add1_oz;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
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

    /* Level2 S-Function Block: random_walk/<S70>/ToBits (Byte2Bits) */
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

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.SerialConverter;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
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

    /* Level2 S-Function Block: random_walk/<S70>/Port B (dopci8255) */
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

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn6.UPtrs2;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn6.UPtrs3;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn6.UPtrs4;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn6.UPtrs5;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn6.UPtrs6;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn6.UPtrs7;
          sfcnUPtrs[0] = &random_walk_B.ToBits_o8;
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
          &random_walk_rtM->NonInlinedSFcns.Sfcn6.params;
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
          &random_walk_rtM->NonInlinedSFcns.Sfcn6.dWork;
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

    /* Level2 S-Function Block: random_walk/<S70>/xPC Target  Time  (xpctimeinfo) */
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
          &random_walk_rtM->NonInlinedSFcns.Sfcn7.params;
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

    /* Level2 S-Function Block: random_walk/<S13>/PCI-QUAD04  (enccbcioquadcount) */
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

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
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
          &random_walk_rtM->NonInlinedSFcns.Sfcn8.params;
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
          &random_walk_rtM->NonInlinedSFcns.Sfcn8.dWork;
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

    /* Level2 S-Function Block: random_walk/<S13>/PCI-QUAD04 1 (enccbcioquadcount) */
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

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
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
          &random_walk_rtM->NonInlinedSFcns.Sfcn9.params;
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
          &random_walk_rtM->NonInlinedSFcns.Sfcn9.dWork;
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

    /* Level2 S-Function Block: random_walk/<S10>/PCI-6025E AD (adnipcie) */
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

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &random_walk_B.PCI6025EAD_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &random_walk_B.PCI6025EAD_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E AD");
      ssSetPath(rts, "random_walk/Velocity Calculation/PCI-6025E AD");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&random_walk_P.PCI6025EAD_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&random_walk_P.PCI6025EAD_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&random_walk_P.PCI6025EAD_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&random_walk_P.PCI6025EAD_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&random_walk_P.PCI6025EAD_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&random_walk_P.PCI6025EAD_P6_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &random_walk_DWork.PCI6025EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &random_walk_DWork.PCI6025EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &random_walk_rtM->NonInlinedSFcns.Sfcn10.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &random_walk_DWork.PCI6025EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &random_walk_DWork.PCI6025EAD_IWORK[0]);
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

    /* Level2 S-Function Block: random_walk/<Root>/Behavior RW (mastercon_rw) */
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
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn11.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.Product1_m;
          sfcnUPtrs[1] = &random_walk_B.Product_l;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn11.UPtrs1;
          sfcnUPtrs[0] = random_walk_B.MultiportSwitch;
          sfcnUPtrs[1] = &random_walk_B.MultiportSwitch[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn11.UPtrs2;
          sfcnUPtrs[0] = random_walk_B.LoadSelectSwitch;
          sfcnUPtrs[1] = &random_walk_B.LoadSelectSwitch[1];
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 2);
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
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) random_walk_B.BehaviorRW_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 5);
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

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 4);
          ssSetOutputPortSignal(rts, 6, ((real_T *) random_walk_B.BehaviorRW_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 2);
          ssSetOutputPortSignal(rts, 7, ((real_T *) random_walk_B.BehaviorRW_o8));
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
          &random_walk_rtM->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 18);
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
        ssSetSFcnParam(rts, 10, (mxArray*)&random_walk_P.BehaviorRW_P11_Size[0]);
        ssSetSFcnParam(rts, 11, (mxArray*)&random_walk_P.BehaviorRW_P12_Size[0]);
        ssSetSFcnParam(rts, 12, (mxArray*)&random_walk_P.BehaviorRW_P13_Size[0]);
        ssSetSFcnParam(rts, 13, (mxArray*)&random_walk_P.BehaviorRW_P14_Size[0]);
        ssSetSFcnParam(rts, 14, (mxArray*)&random_walk_P.BehaviorRW_P15_Size[0]);
        ssSetSFcnParam(rts, 15, (mxArray*)&random_walk_P.BehaviorRW_P16_Size[0]);
        ssSetSFcnParam(rts, 16, (mxArray*)&random_walk_P.BehaviorRW_P17_Size[0]);
        ssSetSFcnParam(rts, 17, (mxArray*)&random_walk_P.BehaviorRW_P18_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &random_walk_DWork.BehaviorRW_RWORK[0]);
      ssSetIWork(rts, (int_T *) &random_walk_DWork.BehaviorRW_IWORK[0]);
      ssSetPWork(rts, (void **) &random_walk_DWork.BehaviorRW_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &random_walk_rtM->NonInlinedSFcns.Sfcn11.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 4);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 512);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &random_walk_DWork.BehaviorRW_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 7);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &random_walk_DWork.BehaviorRW_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 2, 1);
        ssSetDWorkDataType(rts, 2,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &random_walk_DWork.BehaviorRW_PWORK);

        /* DSTATE */
        ssSetDWorkWidth(rts, 3, 1);
        ssSetDWorkDataType(rts, 3,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWorkUsedAsDState(rts, 3, 1);
        ssSetDWork(rts, 3, &random_walk_DWork.BehaviorRW_DSTATE);
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

    /* Level2 S-Function Block: random_walk/<S4>/PCI-6025E  (danipcie) */
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
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn12.UPtrs0;
          sfcnUPtrs[0] = &random_walk_B.MG1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &random_walk_rtM->NonInlinedSFcns.Sfcn12.UPtrs1;
          sfcnUPtrs[0] = &random_walk_B.MG2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts, "random_walk/Motor Control/PCI-6025E ");
      ssSetRTModel(rts,random_walk_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &random_walk_rtM->NonInlinedSFcns.Sfcn12.params;
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
          &random_walk_rtM->NonInlinedSFcns.Sfcn12.dWork;
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

    /* Level2 S-Function Block: random_walk/<S9>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = random_walk_rtM->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = random_walk_rtM->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = random_walk_rtM->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = random_walk_rtM->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &random_walk_rtM->NonInlinedSFcns.blkInfo2[13]);
        ssSetRTWSfcnInfo(rts, random_walk_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &random_walk_rtM->NonInlinedSFcns.methods2[13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &random_walk_rtM->NonInlinedSFcns.Sfcn13.inputPortInfo[0]);

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
          &random_walk_rtM->NonInlinedSFcns.Sfcn13.params;
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
          &random_walk_rtM->NonInlinedSFcns.Sfcn13.dWork;
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

  random_walk_PrevZCSigState.SampleandHold.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
  random_walk_PrevZCSigState.SampleandHold_g.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void random_walk_terminate(void)
{
  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Behavior RW' (mastercon_rw) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S13>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S70>/ToBits1' (Byte2Bits) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/SerialConverter' (serPos) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S70>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S70>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S72>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[1];
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
  random_walk_rtM->Sizes.numSampTimes = (3);/* Number of sample times */
  random_walk_rtM->Sizes.numBlocks = (480);/* Number of blocks */
  random_walk_rtM->Sizes.numBlockIO = (375);/* Number of block outputs */
  random_walk_rtM->Sizes.numBlockPrms = (535);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Memory: '<S31>/Memory' */
  random_walk_DWork.Memory_PreviousInput = random_walk_P.Memory_X0;

  /* InitializeConditions for Memory: '<S4>/Memory' */
  random_walk_DWork.Memory_PreviousInput_i = random_walk_P.Memory_X0_e;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter2' */
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

  /* Derivative Block: '<S67>/Derivative' */
  random_walk_DWork.Derivative_RWORK.TimeStampA = rtInf;
  random_walk_DWork.Derivative_RWORK.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S67>/Digital Filter' */
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

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter2' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *)
      &random_walk_DWork.DigitalFilter2_FILT_STATES_a[0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&random_walk_P.DigitalFilter2_ICRTP_f;
    }

    *statePtr++ = 0.0;
  }

  /* Derivative Block: '<S68>/Derivative' */
  random_walk_DWork.Derivative_RWORK_a.TimeStampA = rtInf;
  random_walk_DWork.Derivative_RWORK_a.TimeStampB = rtInf;

  /* Signal Processing Blockset Filter Implementation (sdspfilter2) - '<S68>/Digital Filter' */
  /* FIR, Direct-form */
  {
    real_T *statePtr = (real_T *) &random_walk_DWork.DigitalFilter_FILT_STATES_m
      [0];

    /* Scalar expansion of ICs with extra zero element per channel */
    int_T numElems= 10;
    while (numElems--) {
      *statePtr++ = *(const real_T *)&random_walk_P.DigitalFilter_ICRTP_p;
    }

    *statePtr++ = 0.0;
  }

  /* InitializeConditions for Memory: '<S43>/Memory' */
  random_walk_DWork.Memory_PreviousInput_c = random_walk_P.Memory_X0_a;

  /* InitializeConditions for Memory: '<S47>/Memory' */
  random_walk_DWork.Memory_PreviousInput_e = random_walk_P.Memory_X0_i;

  /* InitializeConditions for UnitDelay: '<S61>/Delay Input1' */
  random_walk_DWork.DelayInput1_DSTATE = random_walk_P.DelayInput1_X0;

  /* InitializeConditions for Memory: '<S45>/Memory' */
  random_walk_DWork.Memory_PreviousInput_d = random_walk_P.Memory_X0_c;

  /* InitializeConditions for UnitDelay: '<S46>/Delay Input1' */
  random_walk_DWork.DelayInput1_DSTATE_h = random_walk_P.DelayInput1_X0_k;

  /* InitializeConditions for UnitDelay: '<S39>/Delay Input1' */
  random_walk_DWork.DelayInput1_DSTATE_k = random_walk_P.DelayInput1_X0_j;

  /* InitializeConditions for Memory: '<S44>/Memory' */
  random_walk_DWork.Memory_PreviousInput_b = random_walk_P.Memory_X0_p;

  /* InitializeConditions for UnitDelay: '<S38>/Delay Input1' */
  random_walk_DWork.DelayInput1_DSTATE_f = random_walk_P.DelayInput1_X0_a;

  /* InitializeConditions for Memory: '<S42>/Memory' */
  random_walk_DWork.Memory_PreviousInput_h = random_walk_P.Memory_X0_h;

  /* InitializeConditions for UnitDelay: '<S23>/x' */
  random_walk_DWork.x_DSTATE = random_walk_P.x_X0;

  /* InitializeConditions for UnitDelay: '<S24>/x' */
  random_walk_DWork.x_DSTATE_m = random_walk_P.x_X0_f;

  /* InitializeConditions for UnitDelay: '<S25>/x' */
  random_walk_DWork.x_DSTATE_d = random_walk_P.x_X0_fi;

  /* InitializeConditions for UnitDelay: '<S26>/x' */
  random_walk_DWork.x_DSTATE_k = random_walk_P.x_X0_i;

  /* InitializeConditions for UnitDelay: '<S17>/x' */
  random_walk_DWork.x_DSTATE_b = random_walk_P.x_X0_d;

  /* InitializeConditions for UnitDelay: '<S18>/x' */
  random_walk_DWork.x_DSTATE_g = random_walk_P.x_X0_p;

  /* InitializeConditions for UnitDelay: '<S19>/x' */
  random_walk_DWork.x_DSTATE_l = random_walk_P.x_X0_iy;

  /* InitializeConditions for UnitDelay: '<S20>/x' */
  random_walk_DWork.x_DSTATE_n = random_walk_P.x_X0_p3;

  /* Level2 S-Function Block: '<Root>/Behavior RW' (mastercon_rw) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[11];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* InitializeConditions for UnitDelay: '<S17>/y' */
  random_walk_DWork.y_DSTATE = random_walk_P.y_X0;

  /* InitializeConditions for UnitDelay: '<S17>/z' */
  random_walk_DWork.z_DSTATE = random_walk_P.z_X0;

  /* InitializeConditions for UnitDelay: '<S18>/y' */
  random_walk_DWork.y_DSTATE_j = random_walk_P.y_X0_d;

  /* InitializeConditions for UnitDelay: '<S18>/z' */
  random_walk_DWork.z_DSTATE_d = random_walk_P.z_X0_c;

  /* InitializeConditions for UnitDelay: '<S19>/y' */
  random_walk_DWork.y_DSTATE_c = random_walk_P.y_X0_e;

  /* InitializeConditions for UnitDelay: '<S19>/z' */
  random_walk_DWork.z_DSTATE_b = random_walk_P.z_X0_b;

  /* InitializeConditions for UnitDelay: '<S20>/y' */
  random_walk_DWork.y_DSTATE_l = random_walk_P.y_X0_n;

  /* InitializeConditions for UnitDelay: '<S20>/z' */
  random_walk_DWork.z_DSTATE_j = random_walk_P.z_X0_a;

  /* InitializeConditions for UnitDelay: '<S23>/y' */
  random_walk_DWork.y_DSTATE_k = random_walk_P.y_X0_g;

  /* InitializeConditions for UnitDelay: '<S23>/z' */
  random_walk_DWork.z_DSTATE_m = random_walk_P.z_X0_cv;

  /* InitializeConditions for UnitDelay: '<S24>/y' */
  random_walk_DWork.y_DSTATE_ky = random_walk_P.y_X0_l;

  /* InitializeConditions for UnitDelay: '<S24>/z' */
  random_walk_DWork.z_DSTATE_f = random_walk_P.z_X0_j;

  /* InitializeConditions for UnitDelay: '<S25>/y' */
  random_walk_DWork.y_DSTATE_n = random_walk_P.y_X0_p;

  /* InitializeConditions for UnitDelay: '<S25>/z' */
  random_walk_DWork.z_DSTATE_dr = random_walk_P.z_X0_l;

  /* InitializeConditions for UnitDelay: '<S26>/y' */
  random_walk_DWork.y_DSTATE_d = random_walk_P.y_X0_lz;

  /* InitializeConditions for UnitDelay: '<S26>/z' */
  random_walk_DWork.z_DSTATE_dv = random_walk_P.z_X0_g;
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 ' (enccbcioquadcount) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S13>/PCI-QUAD04 1' (enccbcioquadcount) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S10>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S4>/PCI-6025E ' (danipcie) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[12];
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
        xpceScopeAcqOK(2, &random_walk_DWork.SFunction_IWORK.AcquireOK);
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
        xpceScopeAcqOK(6, &random_walk_DWork.SFunction_IWORK_p.AcquireOK);
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
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior RW/p2/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior RW/p2/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior RW/p2/s3"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior RW/p2/s4"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior RW/p2/s5"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior RW/p2/s1"),
          "%6.0f state");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior RW/p2/s2"),
          "%6.0f rewards");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior RW/p2/s3"),
          "%6.0f aborts");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior RW/p2/s4"),
          "%6.0f fails");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior RW/p2/s5"),
          "%6.0f incompl");
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
        xpceScopeAcqOK(3, &random_walk_DWork.SFunction_IWORK_o.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Level2 S-Function Block: '<S9>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[13];
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
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior RW/p7/s1"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior RW/p7/s2"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior RW/p7/s3"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior RW/p7/s4"));
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior RW/p7/s1"),
          "%6.0f major");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior RW/p7/s2"),
          "%6.0f minor");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior RW/p7/s3"),
          "%6.0f revision");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior RW/p7/s4"),
          "%6.0f build");
        rl32eSetScope(7, 4, 10);
        rl32eSetScope(7, 40, 0);
        rl32eSetScope(7, 7, 10);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("Behavior RW/p7/s1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 10, 0);
        rl32eSetTargetScope(7, 1, 0.0);
        rl32eSetTargetScope(7, 11, -10.0);
        rl32eSetTargetScope(7, 10, 10.0);
        xpceScopeAcqOK(7, &random_walk_DWork.SFunction_IWORK_j.AcquireOK);
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
        xpceScopeAcqOK(1, &random_walk_DWork.SFunction_IWORK_c.AcquireOK);
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
        xpceScopeAcqOK(5, &random_walk_DWork.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /*trigger Subsystem Block: '<S65>/Sample and Hold' */
  random_walk_SampleandHold_Start(&random_walk_B.SampleandHold,
    (rtP_SampleandHold_random_walk *) &random_walk_P.SampleandHold);

  /* UniformRandomNumber Block: '<S6>/Uniform Random Number' */
  {
    uint32_T *RandSeed = (uint32_T *)
      &random_walk_DWork.UniformRandomNumber_IWORK.RandSeed;
    uint32_T r, t;
    *RandSeed = (uint32_T)random_walk_P.UniformRandomNumber_Seed;
    r = *RandSeed >> 16;
    t = *RandSeed & RT_BIT16;
    *RandSeed = ((*RandSeed - (r << 16) - t) << 16) + t + r;
    if (*RandSeed < 1) {
      *RandSeed = SEED0;
    }

    if (*RandSeed > MAXSEED) {
      *RandSeed = MAXSEED;
    }

    random_walk_DWork.UniformRandomNumber_RWORK.NextOutput
      = rt_Urand(RandSeed++) * (random_walk_P.UniformRandomNumber_Max -
      random_walk_P.UniformRandomNumber_Min) +
      random_walk_P.UniformRandomNumber_Min;
  }

  /*trigger Subsystem Block: '<S6>/Sample and Hold' */
  random_walk_SampleandHold_Start(&random_walk_B.SampleandHold_g,
    (rtP_SampleandHold_random_walk *) &random_walk_P.SampleandHold_g);

  /* Start for iterator system: '<S13>/For Iterator Subsystem' */

  /* Level2 S-Function Block: '<S70>/Port A' (dopci8255) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S70>/Port B' (dopci8255) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Start for iterator system: '<S70>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S72>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = random_walk_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  random_walk_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  random_walk_DWork.EnabledSubsystem_d.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  random_walk_DWork.EnabledSubsystem_n.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  random_walk_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  random_walk_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  random_walk_DWork.SampleandHold_g.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  random_walk_DWork.SampleandHold.SampleandHold_SubsysRanBC =
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
