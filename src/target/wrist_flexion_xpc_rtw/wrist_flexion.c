/*
 * wrist_flexion.c
 *
 * Real-Time Workshop code generation for Simulink model "wrist_flexion.mdl".
 *
 * Model Version              : 1.345
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 14:04:42 2010
 */

#include "rt_logging_mmi.h"
#include "wrist_flexion_capi.h"
#include "wrist_flexion.h"
#include "wrist_flexion_private.h"
#include <stdio.h>
#include "wrist_flexion_dt.h"

/* Block signals (auto storage) */
BlockIO_wrist_flexion wrist_flexion_B;

/* Continuous states */
ContinuousStates_wrist_flexion wrist_flexion_X;

/* Solver Matrices */

/* A and B matrices used by ODE3 fixed-step solver */
static const real_T rt_ODE3_A[3] = {
  1.0/2.0, 3.0/4.0, 1.0
};

static const real_T rt_ODE3_B[3][3] = {
  { 1.0/2.0, 0.0, 0.0 },

  { 0.0, 3.0/4.0, 0.0 },

  { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
};

/* Block states (auto storage) */
D_Work_wrist_flexion wrist_flexion_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_wrist_flexion wrist_flexion_PrevZCSigState;

/* Real-time model */
rtModel_wrist_flexion wrist_flexion_rtM_;
rtModel_wrist_flexion *wrist_flexion_rtM = &wrist_flexion_rtM_;
static void rate_scheduler(void);

/*
 * This function updates active task flag for each subrate.
 * The function must be is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++wrist_flexion_rtM->Timing.TaskCounters.TID[2] == 10) {/* Sample time: [0.01s, 0.0s] */
    wrist_flexion_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  wrist_flexion_rtM->Timing.sampleHits[2] =
    (wrist_flexion_rtM->Timing.TaskCounters.TID[2] == 0);
  if (++wrist_flexion_rtM->Timing.TaskCounters.TID[3] == 20) {/* Sample time: [0.02s, 0.0s] */
    wrist_flexion_rtM->Timing.TaskCounters.TID[3] = 0;
  }

  wrist_flexion_rtM->Timing.sampleHits[3] =
    (wrist_flexion_rtM->Timing.TaskCounters.TID[3] == 0);
}

/* This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 18;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y,x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  wrist_flexion_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  wrist_flexion_output(0);
  wrist_flexion_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++)
    hB[i] = h * rt_ODE3_B[1][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  wrist_flexion_output(0);
  wrist_flexion_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++)
    hB[i] = h * rt_ODE3_B[2][i];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Start for trigger system:
 *   '<S4>/Sample and Hold'
 *   '<S12>/Sample and Hold'
 */
void wrist_flexi_SampleandHold_Start(rtB_SampleandHold_wrist_flexion *localB,
  rtP_SampleandHold_wrist_flexion *localP)
{
  /* virtual outports code */

  /* (Virtual) Outport Block: '<S11>/ ' */
  localB->In = localP->_Y0;
}

/* Output and update for trigger system:
 *   '<S4>/Sample and Hold'
 *   '<S12>/Sample and Hold'
 */
void wrist_flexion_SampleandHold(real_T rtu_0, real_T rtu_1,
  rtModel_wrist_flexion *wrist_flexion_rtM, rtB_SampleandHold_wrist_flexion
  *localB, rtDW_SampleandHold_wrist_flexio *localDW,
  rtZCE_SampleandHold_wrist_flexi *localZCE)
{
  if (rtmIsMajorTimeStep(wrist_flexion_rtM)) {
    ZCEventType trigEvent;
    trigEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&(localZCE->SampleandHold_ZCE),
                         rtu_0);

    /* conditionally execute */
    if (trigEvent != NO_ZCEVENT) {
      /* Inport: '<S11>/In' */
      localB->In = rtu_1;
      localDW->SampleandHold_SubsysRanBC = SUBSYS_RAN_BC_ONE_SHOT;
    }
  }
}

/* Model output function */
void wrist_flexion_output(int_T tid)
{
  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(wrist_flexion_rtM)) {
    wrist_flexion_rtM->Timing.t[0] = rtsiGetT(&wrist_flexion_rtM->solverInfo);
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&wrist_flexion_rtM->solverInfo,
                          ((wrist_flexion_rtM->Timing.clockTick0+1)*
      wrist_flexion_rtM->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Reset subsysRan breadcrumbs */
  srClearBC(wrist_flexion_DWork.SampleandHold_k.SampleandHold_SubsysRanBC);
  srClearBC(wrist_flexion_DWork.SampleandHold.SampleandHold_SubsysRanBC);

  /* ok to acquire for <S1>/S-Function */
  wrist_flexion_DWork.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S3>/S-Function */
  wrist_flexion_DWork.SFunction_IWORK_p.AcquireOK = 1;

  /* ok to acquire for <S5>/S-Function */
  wrist_flexion_DWork.SFunction_IWORK_m.AcquireOK = 1;

  /* Integrator Block: '<S2>/Integrator'
   */
  if (rtmIsMajorTimeStep(wrist_flexion_rtM)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &wrist_flexion_PrevZCSigState.Integrator_ZCE,
                       wrist_flexion_P.ResetIntegrator_Value);

    /* evaluate zero-crossings */
    if (zcEvent) {
      wrist_flexion_X.Integrator_CSTATE[0] = wrist_flexion_P.Integrator_IC;
      wrist_flexion_X.Integrator_CSTATE[1] = wrist_flexion_P.Integrator_IC;
    }
  }

  if (wrist_flexion_X.Integrator_CSTATE[0] >=
      wrist_flexion_P.Integrator_UpperSat ) {
    wrist_flexion_X.Integrator_CSTATE[0] = wrist_flexion_P.Integrator_UpperSat;
  } else if (wrist_flexion_X.Integrator_CSTATE[0] <=
             wrist_flexion_P.Integrator_LowerSat ) {
    wrist_flexion_X.Integrator_CSTATE[0] = wrist_flexion_P.Integrator_LowerSat;
  }

  if (wrist_flexion_X.Integrator_CSTATE[1] >=
      wrist_flexion_P.Integrator_UpperSat ) {
    wrist_flexion_X.Integrator_CSTATE[1] = wrist_flexion_P.Integrator_UpperSat;
  } else if (wrist_flexion_X.Integrator_CSTATE[1] <=
             wrist_flexion_P.Integrator_LowerSat ) {
    wrist_flexion_X.Integrator_CSTATE[1] = wrist_flexion_P.Integrator_LowerSat;
  }

  wrist_flexion_B.Integrator[0] = wrist_flexion_X.Integrator_CSTATE[0];
  wrist_flexion_B.Integrator[1] = wrist_flexion_X.Integrator_CSTATE[1];

  /* StateSpace Block: '<S2>/LowPassFilterY' */
  {
    wrist_flexion_B.LowPassFilterY = wrist_flexion_P.LowPassFilterY_C*
      wrist_flexion_X.LowPassFilterY_CSTATE[7];
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.001s, 0.0s] */
    /* Level2 S-Function Block: '<S2>/PCI-6025E ' (adnipcie) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.01s, 0.0s] */
    /* Level2 S-Function Block: '<S2>/Receive' (xpcudpbytereceive) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[9];
      sfcnOutputs(rts, 2);
    }

    /* Unpack: <S2>/Unpack */
    (void) memcpy(wrist_flexion_B.Unpack,wrist_flexion_B.Receive_o1,
                  16);
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.001s, 0.0s] */
    {
      real_T rtsaturate_U0DataInY0Container;
      real_T cg_in;
      real_T cg_in_0;
      real_T tmp;
      real_T tmp_0;

      /* Switch: '<S10>/Override' incorporates:
       *  Constant: '<S10>/Constant'
       */
      if (wrist_flexion_B.Unpack[1] != 0.0F) {
        wrist_flexion_B.Override = wrist_flexion_P.Constant_Value;
      } else {
        /* Saturate: '<S2>/Saturation' incorporates:
         *  Constant: '<S2>/NeuralControlPct'
         */
        rtsaturate_U0DataInY0Container = rt_SATURATE
          (wrist_flexion_P.NeuralControlPct_Value,
           wrist_flexion_P.Saturation_LowerSat,
           wrist_flexion_P.Saturation_UpperSat);
        wrist_flexion_B.Saturation = rtsaturate_U0DataInY0Container;

        /* Gain: '<S10>/PctToFrac' */
        wrist_flexion_B.PctToFrac = wrist_flexion_P.PctToFrac_Gain *
          wrist_flexion_B.Saturation;
        wrist_flexion_B.Override = wrist_flexion_B.PctToFrac;
      }

      /* Sum: '<S10>/Sum' incorporates:
       *  Constant: '<S10>/Constant1'
       */
      wrist_flexion_B.Sum = wrist_flexion_P.Constant1_Value -
        wrist_flexion_B.Override;

      /* Product: '<S10>/Product' */
      tmp = wrist_flexion_B.RawX;
      tmp_0 = wrist_flexion_B.RawY;
      wrist_flexion_B.Product[0] = tmp * wrist_flexion_B.Sum;
      wrist_flexion_B.Product[1] = tmp_0 * wrist_flexion_B.Sum;

      /* Product: '<S10>/Product1' */
      wrist_flexion_B.Product1[0] = wrist_flexion_B.Override * (real_T)
        wrist_flexion_B.Unpack[2];
      wrist_flexion_B.Product1[1] = wrist_flexion_B.Override * (real_T)
        wrist_flexion_B.Unpack[3];

      /* Sum: '<S10>/Sum2' */
      cg_in = wrist_flexion_B.Product[1];
      cg_in_0 = wrist_flexion_B.Product1[1];
      wrist_flexion_B.Sum2 = cg_in + cg_in_0;

      /* Sum: '<S2>/Sum2' incorporates:
       *  Constant: '<S2>/OffsetY'
       */
      wrist_flexion_B.Sum2_c = wrist_flexion_B.Sum2 +
        wrist_flexion_P.OffsetY_Value;

      /* Gain: '<S2>/GainY' */
      wrist_flexion_B.GainY = wrist_flexion_P.GainY_Gain *
        wrist_flexion_B.Sum2_c;
    }
  }

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/EnablePosFilter'
   */
  if (wrist_flexion_P.EnablePosFilter_Value != 0.0) {
    wrist_flexion_B.Switch = wrist_flexion_B.LowPassFilterY;
  } else {
    wrist_flexion_B.Switch = wrist_flexion_B.GainY;
  }

  /* StateSpace Block: '<S2>/LowPassFilterX' */
  {
    wrist_flexion_B.LowPassFilterX = wrist_flexion_P.LowPassFilterX_C*
      wrist_flexion_X.LowPassFilterX_CSTATE[7];
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S10>/Sum1' */
    wrist_flexion_B.Sum1 = wrist_flexion_B.Product[0] + wrist_flexion_B.Product1
      [0];

    /* Sum: '<S2>/Sum1' incorporates:
     *  Constant: '<S2>/OffsetX'
     */
    wrist_flexion_B.Sum1_n = wrist_flexion_B.Sum1 +
      wrist_flexion_P.OffsetX_Value;

    /* Gain: '<S2>/GainX' */
    wrist_flexion_B.GainX = wrist_flexion_P.GainX_Gain * wrist_flexion_B.Sum1_n;
  }

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/EnablePosFilter'
   */
  if (wrist_flexion_P.EnablePosFilter_Value != 0.0) {
    wrist_flexion_B.Switch1 = wrist_flexion_B.LowPassFilterX;
  } else {
    wrist_flexion_B.Switch1 = wrist_flexion_B.GainX;
  }

  /* Trigonometry: '<S9>/Trigonometric Function1' */
  wrist_flexion_B.TrigonometricFunction1 = rt_atan2(wrist_flexion_B.Switch,
    wrist_flexion_B.Switch1);
  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Memory: '<Root>/Memory' */
    wrist_flexion_B.Rotation = wrist_flexion_DWork.Memory_PreviousInput;
  }

  {
    real_T tmp;
    real_T tmp_0;
    real_T tmp_1;
    real_T tmp_2;

    /* Sum: '<S9>/Sum' */
    wrist_flexion_B.Sum_a = wrist_flexion_B.TrigonometricFunction1 +
      wrist_flexion_B.Rotation;

    /* Trigonometry: '<S9>/Trigonometric Function2' */
    wrist_flexion_B.TrigonometricFunction2 = cos(wrist_flexion_B.Sum_a);

    /* Fcn: '<S9>/sqrt(u[1]*u[1] + u[2]*u[2])' */
    tmp = wrist_flexion_B.Switch;
    tmp_0 = wrist_flexion_B.Switch1;
    wrist_flexion_B.sqrtu1u1u2u2 = sqrt(tmp * tmp + tmp_0 * tmp_0);

    /* Product: '<S9>/Product1' */
    wrist_flexion_B.Product1_a = wrist_flexion_B.TrigonometricFunction2 *
      wrist_flexion_B.sqrtu1u1u2u2;

    /* Trigonometry: '<S9>/Trigonometric Function' */
    wrist_flexion_B.TrigonometricFunction = sin(wrist_flexion_B.Sum_a);

    /* Product: '<S9>/Product' */
    wrist_flexion_B.Product_p = wrist_flexion_B.sqrtu1u1u2u2 *
      wrist_flexion_B.TrigonometricFunction;

    /* Switch: '<S2>/Switch2' incorporates:
     *  Constant: '<S2>/EnableIntegrator'
     */
    if (wrist_flexion_P.EnableIntegrator_Value != 0.0) {
      wrist_flexion_B.Switch2[0] = wrist_flexion_B.Integrator[0];
      wrist_flexion_B.Switch2[1] = wrist_flexion_B.Integrator[1];
    } else {
      tmp_1 = wrist_flexion_B.Product1_a;
      tmp_2 = wrist_flexion_B.Product_p;
      wrist_flexion_B.Switch2[0] = tmp_1;
      wrist_flexion_B.Switch2[1] = tmp_2;
    }
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.001s, 0.0s] */
    /* S-Function (sfun_nddirectlook) Block: '<Root>/WFTargetTable'
     */

    /* LookupNDDirect: '<Root>/WFTargetTable' */
    /* 2-dimensional Direct Look-Up returning a 2-D Matrix */
    (void) memcpy((void *)wrist_flexion_B.WFTargetTable,(void *)
                  &wrist_flexion_P.WFTargetTable_table[0],
                  sizeof(real_T)*96U);

    {
      int32_T i;
      for (i = 0; i < 96; i++) {
        /* Reshape: '<Root>/Reshape' */
        wrist_flexion_B.Reshape[i] = wrist_flexion_B.WFTargetTable[i];
      }
    }
  }

  /* Level2 S-Function Block: '<Root>/Behavior WF' (mastercon_wf) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[10];
    sfcnOutputs(rts, 0);
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.001s, 0.0s] */
    /* Pack: <S6>/Pack */
    (void) memcpy(wrist_flexion_B.Pack,&wrist_flexion_B.Switch2[0],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[8],&wrist_flexion_B.Switch2[1],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[16],&wrist_flexion_B.BehaviorWF_o5[0],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[24],&wrist_flexion_B.BehaviorWF_o5[1],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[32],&wrist_flexion_B.BehaviorWF_o5[2],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[40],&wrist_flexion_B.BehaviorWF_o5[3],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[48],&wrist_flexion_B.BehaviorWF_o5[4],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[56],&wrist_flexion_B.BehaviorWF_o5[5],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[64],&wrist_flexion_B.BehaviorWF_o5[6],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[72],&wrist_flexion_B.BehaviorWF_o5[7],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[80],&wrist_flexion_B.BehaviorWF_o5[8],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[88],&wrist_flexion_B.BehaviorWF_o5[9],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[96],&wrist_flexion_B.BehaviorWF_o4[0],
                  8);
    (void) memcpy(&wrist_flexion_B.Pack[104],&wrist_flexion_B.BehaviorWF_o4[1],
                  8);
  }

  {
    int32_T i;

    /* RateTransition: '<S6>/Rate Transition' */
    if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
        wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0 && rtmIsMajorTimeStep
        (wrist_flexion_rtM) &&
        wrist_flexion_rtM->Timing.TaskCounters.TID[3] == 0) {
      for (i = 0; i < 112; i++) {
        wrist_flexion_B.RateTransition[i] = wrist_flexion_B.Pack[i];
      }
    }
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[3] == 0) {/* Sample time: [0.02s, 0.0s] */
    /* Level2 S-Function Block: '<S6>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[11];
      sfcnOutputs(rts, 3);
    }
  }

  /* ok to acquire for <S7>/S-Function */
  wrist_flexion_DWork.SFunction_IWORK_pn.AcquireOK = 1;

  /* Clock Block: '<S12>/Clock'
   */
  wrist_flexion_B.Clock = wrist_flexion_rtM->Timing.t[0];

  /* SignalConversion: '<S12>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
  wrist_flexion_B.HiddenBuf_InsertedFor_Sampleand =
    wrist_flexion_B.BehaviorWF_o1;

  /* SubSystem Block: '<S12>/Sample and Hold'
   */
  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {
    wrist_flexion_SampleandHold(wrist_flexion_B.HiddenBuf_InsertedFor_Sampleand,
      wrist_flexion_B.Clock, wrist_flexion_rtM, &wrist_flexion_B.SampleandHold,
      &wrist_flexion_DWork.SampleandHold,
      &wrist_flexion_PrevZCSigState.SampleandHold);
  }

  /* Sum: '<S12>/Sum' */
  wrist_flexion_B.Sum_m = wrist_flexion_B.Clock -
    wrist_flexion_B.SampleandHold.In;
  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.001s, 0.0s] */
    /* UniformRandomNumber Block: '<S4>/Uniform Random Number'
     */
    wrist_flexion_B.UniformRandomNumber =
      wrist_flexion_DWork.UniformRandomNumber_RWORK.NextOutput;

    /* RelationalOperator: '<S4>/Relational Operator' incorporates:
     *  Constant: '<S4>/JackpotChance'
     */
    wrist_flexion_B.RelationalOperator = (wrist_flexion_B.UniformRandomNumber >
      wrist_flexion_P.JackpotChance_Value);

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/RewardJackpot'
     *  Constant: '<S4>/RewardTime'
     */
    if (wrist_flexion_B.RelationalOperator) {
      wrist_flexion_B.Switch_i = wrist_flexion_P.RewardTime_Value;
    } else {
      wrist_flexion_B.Switch_i = wrist_flexion_P.RewardJackpot_Value;
    }
  }

  /* SignalConversion: '<S4>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
  wrist_flexion_B.HiddenBuf_InsertedFor_Samplea_b =
    wrist_flexion_B.BehaviorWF_o1;

  /* SubSystem Block: '<S4>/Sample and Hold'
   */
  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {
    wrist_flexion_SampleandHold(wrist_flexion_B.HiddenBuf_InsertedFor_Samplea_b,
      wrist_flexion_B.Switch_i, wrist_flexion_rtM,
      &wrist_flexion_B.SampleandHold_k, &wrist_flexion_DWork.SampleandHold_k,
      &wrist_flexion_PrevZCSigState.SampleandHold_k);
  }

  {
    int32_T s8_iter;

    /* RelationalOperator: '<S12>/Relational Operator' */
    wrist_flexion_B.RelationalOperator_f = (wrist_flexion_B.Sum_m <
      wrist_flexion_B.SampleandHold_k.In);

    /* DataTypeConversion: '<S4>/Data Type Conversion' */
    wrist_flexion_B.DataTypeConversion = (real_T)
      wrist_flexion_B.RelationalOperator_f;
    if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
        wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {
      for (s8_iter = 0; s8_iter < 4; s8_iter++) {
        wrist_flexion_B.ForIterator = (real_T)s8_iter;

        /* Output and update for iterator system: '<Root>/WordSbs' */

        /* Switch: '<S8>/Switch' incorporates:
         *  Constant: '<S8>/Constant'
         */
        if (wrist_flexion_B.ForIterator >= wrist_flexion_P.Switch_Threshold) {
          wrist_flexion_B.Switch_e = wrist_flexion_P.Constant_Value_m;
        } else {
          wrist_flexion_B.Switch_e = wrist_flexion_B.BehaviorWF_o2;
        }

        /* Level2 S-Function Block: '<S8>/ToBits' (Byte2Bits) */
        {
          SimStruct *rts = wrist_flexion_rtM->childSfunctions[2];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S8>/Port A' (dopci8255) */
        {
          SimStruct *rts = wrist_flexion_rtM->childSfunctions[3];
          sfcnOutputs(rts, 1);
        }

        {
          real_T cg_in;
          real_T cg_in_0;

          /* Gain: '<S8>/toThousandths' */
          wrist_flexion_B.toThousandths[0] = wrist_flexion_P.toThousandths_Gain *
            wrist_flexion_B.Switch2[0];
          wrist_flexion_B.toThousandths[1] = wrist_flexion_P.toThousandths_Gain *
            wrist_flexion_B.Switch2[1];

          /* Sum: '<S8>/Add2' incorporates:
           *  Constant: '<S8>/Constant2'
           */
          cg_in = wrist_flexion_B.toThousandths[0];
          wrist_flexion_B.Add2 = cg_in + wrist_flexion_P.Constant2_Value;

          /* Sum: '<S8>/Add3' incorporates:
           *  Constant: '<S8>/Constant2'
           */
          cg_in_0 = wrist_flexion_B.toThousandths[1];
          wrist_flexion_B.Add3 = cg_in_0 + wrist_flexion_P.Constant2_Value;
        }

        /* Level2 S-Function Block: '<S8>/SerialConverter' (serPos) */
        {
          SimStruct *rts = wrist_flexion_rtM->childSfunctions[4];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S8>/ToBits1' (Byte2Bits) */
        {
          SimStruct *rts = wrist_flexion_rtM->childSfunctions[5];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S8>/Port B' (dopci8255) */
        {
          SimStruct *rts = wrist_flexion_rtM->childSfunctions[6];
          sfcnOutputs(rts, 1);
        }

        /* Level2 S-Function Block: '<S8>/xPC Target  Time ' (xpctimeinfo) */
        {
          SimStruct *rts = wrist_flexion_rtM->childSfunctions[7];
          sfcnOutputs(rts, 1);
        }

        do {
          /* Output and update for iterator system: '<S8>/While Iterator Subsystem' */

          /* Level2 S-Function Block: '<S14>/xPC Target  Time ' (xpctimeinfo) */
          {
            SimStruct *rts = wrist_flexion_rtM->childSfunctions[0];
            sfcnOutputs(rts, 1);
          }

          /* Sum: '<S14>/Subtract' */
          wrist_flexion_B.Subtract = wrist_flexion_B.xPCTargetTime_a -
            wrist_flexion_B.xPCTargetTime;

          /* Gain: '<S14>/ScaleTouSec' */
          wrist_flexion_B.ScaleTouSec = wrist_flexion_P.ScaleTouSec_Gain *
            wrist_flexion_B.Subtract;

          /* RelationalOperator: '<S16>/Compare' incorporates:
           *  Constant: '<S16>/Constant'
           */
          wrist_flexion_B.Compare = (wrist_flexion_B.ScaleTouSec >
            wrist_flexion_P.Constant_Value_h);

          /* Switch: '<S14>/Switch' incorporates:
           *  Constant: '<S14>/StobeHi'
           *  Constant: '<S14>/StrobeLow'
           */
          if (wrist_flexion_B.Compare) {
            wrist_flexion_B.Switch_o = wrist_flexion_P.StobeHi_Value;
          } else {
            wrist_flexion_B.Switch_o = wrist_flexion_P.StrobeLow_Value;
          }

          /* Level2 S-Function Block: '<S14>/PCI-6025E ' (donipcie) */
          {
            SimStruct *rts = wrist_flexion_rtM->childSfunctions[1];
            sfcnOutputs(rts, 1);
          }

          /* RelationalOperator: '<S15>/Compare' incorporates:
           *  Constant: '<S15>/Constant'
           */
          wrist_flexion_B.Compare_h = (wrist_flexion_B.ScaleTouSec <=
            wrist_flexion_P.Constant_Value_o);
        } while (wrist_flexion_B.Compare_h);
      }

      /* Gain: '<Root>/Rad2Deg' */
      wrist_flexion_B.Rad2Deg = wrist_flexion_P.Rad2Deg_Gain *
        wrist_flexion_B.Rotation;
    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void wrist_flexion_update(int_T tid)
{
  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Update for Memory: '<Root>/Memory' */
    wrist_flexion_DWork.Memory_PreviousInput = wrist_flexion_B.BehaviorWF_o8;
  }

  /* Level2 S-Function Block: '<Root>/Behavior WF' (mastercon_wf) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[10];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.001s, 0.0s] */
    /* UniformRandomNumber Block: '<S4>/Uniform Random Number' */
    wrist_flexion_DWork.UniformRandomNumber_RWORK.NextOutput = rt_Urand
      ((uint32_T *)&wrist_flexion_DWork.UniformRandomNumber_IWORK.RandSeed) *
      (wrist_flexion_P.UniformRandomNumber_Max -
       wrist_flexion_P.UniformRandomNumber_Min) +
      wrist_flexion_P.UniformRandomNumber_Min;
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM)) {
    rt_ertODEUpdateContinuousStates(&wrist_flexion_rtM->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++wrist_flexion_rtM->Timing.clockTick0))
    ++wrist_flexion_rtM->Timing.clockTickH0;
  wrist_flexion_rtM->Timing.t[0] = wrist_flexion_rtM->Timing.clockTick0 *
    wrist_flexion_rtM->Timing.stepSize0 + wrist_flexion_rtM->Timing.clockTickH0 *
    wrist_flexion_rtM->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++wrist_flexion_rtM->Timing.clockTick1))
      ++wrist_flexion_rtM->Timing.clockTickH1;
    wrist_flexion_rtM->Timing.t[1] = wrist_flexion_rtM->Timing.clockTick1 *
      wrist_flexion_rtM->Timing.stepSize1 +
      wrist_flexion_rtM->Timing.clockTickH1 *
      wrist_flexion_rtM->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    if (!(++wrist_flexion_rtM->Timing.clockTick2))
      ++wrist_flexion_rtM->Timing.clockTickH2;
    wrist_flexion_rtM->Timing.t[2] = wrist_flexion_rtM->Timing.clockTick2 *
      wrist_flexion_rtM->Timing.stepSize2 +
      wrist_flexion_rtM->Timing.clockTickH2 *
      wrist_flexion_rtM->Timing.stepSize2 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(wrist_flexion_rtM) &&
      wrist_flexion_rtM->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    if (!(++wrist_flexion_rtM->Timing.clockTick3))
      ++wrist_flexion_rtM->Timing.clockTickH3;
    wrist_flexion_rtM->Timing.t[3] = wrist_flexion_rtM->Timing.clockTick3 *
      wrist_flexion_rtM->Timing.stepSize3 +
      wrist_flexion_rtM->Timing.clockTickH3 *
      wrist_flexion_rtM->Timing.stepSize3 * 4294967296.0;
  }

  rate_scheduler();
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void wrist_flexion_derivatives(void)
{
  /* Limited Integrator Block: '<S2>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( wrist_flexion_X.Integrator_CSTATE[0] <=
            wrist_flexion_P.Integrator_LowerSat );
    usat = ( wrist_flexion_X.Integrator_CSTATE[0] >=
            wrist_flexion_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (wrist_flexion_B.Product1_a > 0)) ||
        (usat && (wrist_flexion_B.Product1_a < 0)) ) {
      ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
        ->Integrator_CSTATE[0] = wrist_flexion_B.Product1_a;
    } else {
      /* in saturation */
      ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
        ->Integrator_CSTATE[0] = 0.0;
    }

    lsat = ( wrist_flexion_X.Integrator_CSTATE[1] <=
            wrist_flexion_P.Integrator_LowerSat );
    usat = ( wrist_flexion_X.Integrator_CSTATE[1] >=
            wrist_flexion_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (wrist_flexion_B.Product_p > 0)) ||
        (usat && (wrist_flexion_B.Product_p < 0)) ) {
      ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
        ->Integrator_CSTATE[1] = wrist_flexion_B.Product_p;
    } else {
      /* in saturation */
      ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
        ->Integrator_CSTATE[1] = 0.0;
    }
  }

  /* StateSpace Block: '<S2>/LowPassFilterY' */
  {
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterY_CSTATE[0] = wrist_flexion_P.LowPassFilterY_B*
      wrist_flexion_B.GainY;
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterY_CSTATE[0] += (wrist_flexion_P.LowPassFilterY_A[0])*
      wrist_flexion_X.LowPassFilterY_CSTATE[0]
      + (wrist_flexion_P.LowPassFilterY_A[1])*
      wrist_flexion_X.LowPassFilterY_CSTATE[1];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterY_CSTATE[1] = (wrist_flexion_P.LowPassFilterY_A[2])*
      wrist_flexion_X.LowPassFilterY_CSTATE[0];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterY_CSTATE[2] = (wrist_flexion_P.LowPassFilterY_A[3])*
      wrist_flexion_X.LowPassFilterY_CSTATE[1]
      + (wrist_flexion_P.LowPassFilterY_A[4])*
      wrist_flexion_X.LowPassFilterY_CSTATE[2]
      + (wrist_flexion_P.LowPassFilterY_A[5])*
      wrist_flexion_X.LowPassFilterY_CSTATE[3];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterY_CSTATE[3] = (wrist_flexion_P.LowPassFilterY_A[6])*
      wrist_flexion_X.LowPassFilterY_CSTATE[2];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterY_CSTATE[4] = (wrist_flexion_P.LowPassFilterY_A[7])*
      wrist_flexion_X.LowPassFilterY_CSTATE[3]
      + (wrist_flexion_P.LowPassFilterY_A[8])*
      wrist_flexion_X.LowPassFilterY_CSTATE[4]
      + (wrist_flexion_P.LowPassFilterY_A[9])*
      wrist_flexion_X.LowPassFilterY_CSTATE[5];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterY_CSTATE[5] = (wrist_flexion_P.LowPassFilterY_A[10])*
      wrist_flexion_X.LowPassFilterY_CSTATE[4];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterY_CSTATE[6] = (wrist_flexion_P.LowPassFilterY_A[11])*
      wrist_flexion_X.LowPassFilterY_CSTATE[5]
      + (wrist_flexion_P.LowPassFilterY_A[12])*
      wrist_flexion_X.LowPassFilterY_CSTATE[6]
      + (wrist_flexion_P.LowPassFilterY_A[13])*
      wrist_flexion_X.LowPassFilterY_CSTATE[7];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterY_CSTATE[7] = (wrist_flexion_P.LowPassFilterY_A[14])*
      wrist_flexion_X.LowPassFilterY_CSTATE[6];
  }

  /* StateSpace Block: '<S2>/LowPassFilterX' */
  {
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterX_CSTATE[0] = wrist_flexion_P.LowPassFilterX_B*
      wrist_flexion_B.GainX;
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterX_CSTATE[0] += (wrist_flexion_P.LowPassFilterX_A[0])*
      wrist_flexion_X.LowPassFilterX_CSTATE[0]
      + (wrist_flexion_P.LowPassFilterX_A[1])*
      wrist_flexion_X.LowPassFilterX_CSTATE[1];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterX_CSTATE[1] = (wrist_flexion_P.LowPassFilterX_A[2])*
      wrist_flexion_X.LowPassFilterX_CSTATE[0];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterX_CSTATE[2] = (wrist_flexion_P.LowPassFilterX_A[3])*
      wrist_flexion_X.LowPassFilterX_CSTATE[1]
      + (wrist_flexion_P.LowPassFilterX_A[4])*
      wrist_flexion_X.LowPassFilterX_CSTATE[2]
      + (wrist_flexion_P.LowPassFilterX_A[5])*
      wrist_flexion_X.LowPassFilterX_CSTATE[3];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterX_CSTATE[3] = (wrist_flexion_P.LowPassFilterX_A[6])*
      wrist_flexion_X.LowPassFilterX_CSTATE[2];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterX_CSTATE[4] = (wrist_flexion_P.LowPassFilterX_A[7])*
      wrist_flexion_X.LowPassFilterX_CSTATE[3]
      + (wrist_flexion_P.LowPassFilterX_A[8])*
      wrist_flexion_X.LowPassFilterX_CSTATE[4]
      + (wrist_flexion_P.LowPassFilterX_A[9])*
      wrist_flexion_X.LowPassFilterX_CSTATE[5];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterX_CSTATE[5] = (wrist_flexion_P.LowPassFilterX_A[10])*
      wrist_flexion_X.LowPassFilterX_CSTATE[4];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterX_CSTATE[6] = (wrist_flexion_P.LowPassFilterX_A[11])*
      wrist_flexion_X.LowPassFilterX_CSTATE[5]
      + (wrist_flexion_P.LowPassFilterX_A[12])*
      wrist_flexion_X.LowPassFilterX_CSTATE[6]
      + (wrist_flexion_P.LowPassFilterX_A[13])*
      wrist_flexion_X.LowPassFilterX_CSTATE[7];
    ((StateDerivatives_wrist_flexion *) wrist_flexion_rtM->ModelData.derivs)
      ->LowPassFilterX_CSTATE[7] = (wrist_flexion_P.LowPassFilterX_A[14])*
      wrist_flexion_X.LowPassFilterX_CSTATE[6];
  }
}

/* Model initialize function */
void wrist_flexion_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */
  /* initialize real-time model */
  (void) memset((char_T *)wrist_flexion_rtM,0,
                sizeof(rtModel_wrist_flexion));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&wrist_flexion_rtM->solverInfo,
                          &wrist_flexion_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&wrist_flexion_rtM->solverInfo, &rtmGetTPtr(wrist_flexion_rtM));
    rtsiSetStepSizePtr(&wrist_flexion_rtM->solverInfo,
                       &wrist_flexion_rtM->Timing.stepSize0);
    rtsiSetdXPtr(&wrist_flexion_rtM->solverInfo,
                 &wrist_flexion_rtM->ModelData.derivs);
    rtsiSetContStatesPtr(&wrist_flexion_rtM->solverInfo,
                         &wrist_flexion_rtM->ModelData.contStates);
    rtsiSetNumContStatesPtr(&wrist_flexion_rtM->solverInfo,
      &wrist_flexion_rtM->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&wrist_flexion_rtM->solverInfo, (&rtmGetErrorStatus
      (wrist_flexion_rtM)));
    rtsiSetRTModelPtr(&wrist_flexion_rtM->solverInfo, wrist_flexion_rtM);
  }

  rtsiSetSimTimeStep(&wrist_flexion_rtM->solverInfo, MAJOR_TIME_STEP);
  wrist_flexion_rtM->ModelData.intgData.y = wrist_flexion_rtM->ModelData.odeY;
  wrist_flexion_rtM->ModelData.intgData.f[0] = wrist_flexion_rtM->ModelData.odeF
    [0];
  wrist_flexion_rtM->ModelData.intgData.f[1] = wrist_flexion_rtM->ModelData.odeF
    [1];
  wrist_flexion_rtM->ModelData.intgData.f[2] = wrist_flexion_rtM->ModelData.odeF
    [2];
  wrist_flexion_rtM->ModelData.contStates = ((real_T *) &wrist_flexion_X);
  rtsiSetSolverData(&wrist_flexion_rtM->solverInfo, (void *)
                    &wrist_flexion_rtM->ModelData.intgData);
  rtsiSetSolverName(&wrist_flexion_rtM->solverInfo,"ode3");
  wrist_flexion_rtM->solverInfoPtr = (&wrist_flexion_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = wrist_flexion_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    mdlTsMap[3] = 3;
    wrist_flexion_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    wrist_flexion_rtM->Timing.sampleTimes =
      (&wrist_flexion_rtM->Timing.sampleTimesArray[0]);
    wrist_flexion_rtM->Timing.offsetTimes =
      (&wrist_flexion_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    wrist_flexion_rtM->Timing.sampleTimes[0] = (0.0);
    wrist_flexion_rtM->Timing.sampleTimes[1] = (0.001);
    wrist_flexion_rtM->Timing.sampleTimes[2] = (0.01);
    wrist_flexion_rtM->Timing.sampleTimes[3] = (0.02);

    /* task offsets */
    wrist_flexion_rtM->Timing.offsetTimes[0] = (0.0);
    wrist_flexion_rtM->Timing.offsetTimes[1] = (0.0);
    wrist_flexion_rtM->Timing.offsetTimes[2] = (0.0);
    wrist_flexion_rtM->Timing.offsetTimes[3] = (0.0);
  }

  rtmSetTPtr(wrist_flexion_rtM, &wrist_flexion_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = wrist_flexion_rtM->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    mdlSampleHits[3] = 1;
    wrist_flexion_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(wrist_flexion_rtM, -1);
  wrist_flexion_rtM->Timing.stepSize0 = 0.001;
  wrist_flexion_rtM->Timing.stepSize1 = 0.001;
  wrist_flexion_rtM->Timing.stepSize2 = 0.01;
  wrist_flexion_rtM->Timing.stepSize3 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    wrist_flexion_rtM->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(wrist_flexion_rtM->rtwLogInfo, 0);
    rtliSetLogMaxRows(wrist_flexion_rtM->rtwLogInfo, 1000);
    rtliSetLogDecimation(wrist_flexion_rtM->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(wrist_flexion_rtM->rtwLogInfo, "rt_");
    rtliSetLogT(wrist_flexion_rtM->rtwLogInfo, "tout");
    rtliSetLogX(wrist_flexion_rtM->rtwLogInfo, "");
    rtliSetLogXFinal(wrist_flexion_rtM->rtwLogInfo, "");
    rtliSetSigLog(wrist_flexion_rtM->rtwLogInfo, "");
    rtliSetLogXSignalInfo(wrist_flexion_rtM->rtwLogInfo, NULL);
    rtliSetLogXSignalPtrs(wrist_flexion_rtM->rtwLogInfo, NULL);
    rtliSetLogY(wrist_flexion_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(wrist_flexion_rtM->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(wrist_flexion_rtM->rtwLogInfo, NULL);
  }

  /* external mode info */
  wrist_flexion_rtM->Sizes.checksums[0] = (1870546500U);
  wrist_flexion_rtM->Sizes.checksums[1] = (683336456U);
  wrist_flexion_rtM->Sizes.checksums[2] = (165910783U);
  wrist_flexion_rtM->Sizes.checksums[3] = (1781734223U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    wrist_flexion_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &wrist_flexion_DWork.SampleandHold_k.SampleandHold_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &wrist_flexion_DWork.SampleandHold.SampleandHold_SubsysRanBC;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &wrist_flexion_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, wrist_flexion_rtM->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(wrist_flexion_rtM));
  }

  wrist_flexion_rtM->solverInfoPtr = (&wrist_flexion_rtM->solverInfo);
  wrist_flexion_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&wrist_flexion_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&wrist_flexion_rtM->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  wrist_flexion_rtM->ModelData.blockIO = ((void *) &wrist_flexion_B);
  (void) memset(((void *) &wrist_flexion_B),0,
                sizeof(BlockIO_wrist_flexion));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&wrist_flexion_B.Integrator[0]);
    for (i = 0; i < 262; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&wrist_flexion_B.ForIterator);
    for (i = 0; i < 30; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&wrist_flexion_B.Unpack[0]);
    for (i = 0; i < 4; i++) {
      ((real32_T*)pVoidBlockIORegion)[i] = 0.0F;
    }

    ((real_T*)&wrist_flexion_B.SampleandHold.In)[0] = 0.0;
    ((real_T*)&wrist_flexion_B.SampleandHold_k.In)[0] = 0.0;
  }

  /* parameters */
  wrist_flexion_rtM->ModelData.defaultParam = ((real_T *) &wrist_flexion_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &wrist_flexion_X;
    wrist_flexion_rtM->ModelData.contStates = (x);
    (void) memset((char_T *)x,0,
                  sizeof(ContinuousStates_wrist_flexion));
  }

  /* states (dwork) */
  wrist_flexion_rtM->Work.dwork = ((void *) &wrist_flexion_DWork);
  (void) memset((char_T *) &wrist_flexion_DWork,0,
                sizeof(D_Work_wrist_flexion));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &wrist_flexion_DWork.BehaviorWF_DSTATE;
    for (i = 0; i < 106; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    wrist_flexion_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    wrist_flexion_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  wrist_flexion_InitializeDataMapInfo(wrist_flexion_rtM);

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &wrist_flexion_rtM->NonInlinedSFcns.sfcnInfo;
    wrist_flexion_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(wrist_flexion_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &wrist_flexion_rtM->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(wrist_flexion_rtM));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(wrist_flexion_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (wrist_flexion_rtM));
    rtssSetStepSizePtr(sfcnInfo, &wrist_flexion_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(wrist_flexion_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &wrist_flexion_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &wrist_flexion_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &wrist_flexion_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &wrist_flexion_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &wrist_flexion_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &wrist_flexion_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &wrist_flexion_rtM->solverInfoPtr);
  }

  wrist_flexion_rtM->Sizes.numSFcns = (12);

  /* register each child */
  {
    (void) memset((void *)&wrist_flexion_rtM->NonInlinedSFcns.childSFunctions[0],
                  0,
                  12*sizeof(SimStruct));
    wrist_flexion_rtM->childSfunctions =
      (&wrist_flexion_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 12; i++) {
        wrist_flexion_rtM->childSfunctions[i] =
          (&wrist_flexion_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: wrist_flexion/<S14>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &wrist_flexion_B.xPCTargetTime_a));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "wrist_flexion/WordSbs/While Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,wrist_flexion_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&wrist_flexion_P.xPCTargetTime_P1_Size
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&wrist_flexion_P.xPCTargetTime_P2_Size
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

    /* Level2 S-Function Block: wrist_flexion/<S14>/PCI-6025E  (donipcie) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &wrist_flexion_B.Switch_o;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &wrist_flexion_B.DataTypeConversion;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts, "wrist_flexion/WordSbs/While Iterator Subsystem/PCI-6025E ");
      ssSetRTModel(rts,wrist_flexion_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&wrist_flexion_P.PCI6025E_P1_Size_f[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&wrist_flexion_P.PCI6025E_P2_Size_o[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&wrist_flexion_P.PCI6025E_P3_Size_g[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&wrist_flexion_P.PCI6025E_P4_Size_a[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&wrist_flexion_P.PCI6025E_P5_Size_g[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&wrist_flexion_P.PCI6025E_P6_Size_d[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&wrist_flexion_P.PCI6025E_P7_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &wrist_flexion_DWork.PCI6025E_IWORK_n[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn1.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &wrist_flexion_DWork.PCI6025E_IWORK_n[0]);
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

    /* Level2 S-Function Block: wrist_flexion/<S8>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &wrist_flexion_B.Switch_e;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &wrist_flexion_B.ToBits_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &wrist_flexion_B.ToBits_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &wrist_flexion_B.ToBits_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &wrist_flexion_B.ToBits_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &wrist_flexion_B.ToBits_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &wrist_flexion_B.ToBits_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &wrist_flexion_B.ToBits_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &wrist_flexion_B.ToBits_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts, "wrist_flexion/WordSbs/ToBits");
      ssSetRTModel(rts,wrist_flexion_rtM);
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

    /* Level2 S-Function Block: wrist_flexion/<S8>/Port A (dopci8255) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.UPtrs2;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.UPtrs3;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.UPtrs4;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.UPtrs5;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.UPtrs6;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.UPtrs7;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port A");
      ssSetPath(rts, "wrist_flexion/WordSbs/Port A");
      ssSetRTModel(rts,wrist_flexion_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&wrist_flexion_P.PortA_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&wrist_flexion_P.PortA_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&wrist_flexion_P.PortA_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&wrist_flexion_P.PortA_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&wrist_flexion_P.PortA_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&wrist_flexion_P.PortA_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&wrist_flexion_P.PortA_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&wrist_flexion_P.PortA_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&wrist_flexion_P.PortA_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &wrist_flexion_DWork.PortA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn3.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &wrist_flexion_DWork.PortA_IWORK[0]);
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

    /* Level2 S-Function Block: wrist_flexion/<S8>/SerialConverter (serPos) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &wrist_flexion_B.ForIterator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &wrist_flexion_B.Add2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn4.UPtrs2;
          sfcnUPtrs[0] = &wrist_flexion_B.Add3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &wrist_flexion_B.SerialConverter));
        }
      }

      /* path info */
      ssSetModelName(rts, "SerialConverter");
      ssSetPath(rts, "wrist_flexion/WordSbs/SerialConverter");
      ssSetRTModel(rts,wrist_flexion_rtM);
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

    /* Level2 S-Function Block: wrist_flexion/<S8>/ToBits1 (Byte2Bits) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[5]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &wrist_flexion_B.SerialConverter;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &wrist_flexion_B.ToBits1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &wrist_flexion_B.ToBits1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &wrist_flexion_B.ToBits1_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &wrist_flexion_B.ToBits1_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &wrist_flexion_B.ToBits1_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &wrist_flexion_B.ToBits1_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &wrist_flexion_B.ToBits1_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &wrist_flexion_B.ToBits1_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits1");
      ssSetPath(rts, "wrist_flexion/WordSbs/ToBits1");
      ssSetRTModel(rts,wrist_flexion_rtM);
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

    /* Level2 S-Function Block: wrist_flexion/<S8>/Port B (dopci8255) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[6]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits1_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits1_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.UPtrs2;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits1_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.UPtrs3;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits1_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.UPtrs4;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits1_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.UPtrs5;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits1_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.UPtrs6;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits1_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.UPtrs7;
          sfcnUPtrs[0] = &wrist_flexion_B.ToBits1_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port B");
      ssSetPath(rts, "wrist_flexion/WordSbs/Port B");
      ssSetRTModel(rts,wrist_flexion_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&wrist_flexion_P.PortB_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&wrist_flexion_P.PortB_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&wrist_flexion_P.PortB_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&wrist_flexion_P.PortB_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&wrist_flexion_P.PortB_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&wrist_flexion_P.PortB_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&wrist_flexion_P.PortB_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&wrist_flexion_P.PortB_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&wrist_flexion_P.PortB_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &wrist_flexion_DWork.PortB_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn6.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &wrist_flexion_DWork.PortB_IWORK[0]);
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

    /* Level2 S-Function Block: wrist_flexion/<S8>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[7]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &wrist_flexion_B.xPCTargetTime));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts, "wrist_flexion/WordSbs/xPC Target  Time ");
      ssSetRTModel(rts,wrist_flexion_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       &wrist_flexion_P.xPCTargetTime_P1_Size_d[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       &wrist_flexion_P.xPCTargetTime_P2_Size_j[0]);
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

    /* Level2 S-Function Block: wrist_flexion/<S2>/PCI-6025E  (adnipcie) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[8]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &wrist_flexion_B.RawX));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &wrist_flexion_B.RawY));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts, "wrist_flexion/CursorPos/PCI-6025E ");
      ssSetRTModel(rts,wrist_flexion_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&wrist_flexion_P.PCI6025E_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&wrist_flexion_P.PCI6025E_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&wrist_flexion_P.PCI6025E_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&wrist_flexion_P.PCI6025E_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&wrist_flexion_P.PCI6025E_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&wrist_flexion_P.PCI6025E_P6_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &wrist_flexion_DWork.PCI6025E_RWORK[0]);
      ssSetIWork(rts, (int_T *) &wrist_flexion_DWork.PCI6025E_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn8.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &wrist_flexion_DWork.PCI6025E_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &wrist_flexion_DWork.PCI6025E_IWORK[0]);
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

    /* Level2 S-Function Block: wrist_flexion/<S2>/Receive (xpcudpbytereceive) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[9]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 16);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) wrist_flexion_B.Receive_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &wrist_flexion_B.Receive_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Receive");
      ssSetPath(rts, "wrist_flexion/CursorPos/Receive");
      ssSetRTModel(rts,wrist_flexion_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&wrist_flexion_P.Receive_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&wrist_flexion_P.Receive_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&wrist_flexion_P.Receive_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&wrist_flexion_P.Receive_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &wrist_flexion_DWork.Receive_IWORK[0]);
      ssSetPWork(rts, (void **) &wrist_flexion_DWork.Receive_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn9.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &wrist_flexion_DWork.Receive_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &wrist_flexion_DWork.Receive_PWORK);
      }

      /* registration */
      xpcudpbytereceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: wrist_flexion/<Root>/Behavior WF (mastercon_wf) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[10]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[10]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn10.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn10.UPtrs0;
          sfcnUPtrs[0] = wrist_flexion_B.Switch2;
          sfcnUPtrs[1] = &wrist_flexion_B.Switch2[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &wrist_flexion_rtM->NonInlinedSFcns.Sfcn10.UPtrs1;

          {
            int_T i1;
            const real_T *u1 = wrist_flexion_B.Reshape;
            for (i1=0; i1 < 96; i1++) {
              sfcnUPtrs[i1] = &u1[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 96);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &wrist_flexion_B.BehaviorWF_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &wrist_flexion_B.BehaviorWF_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 4);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            wrist_flexion_B.BehaviorWF_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 2);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            wrist_flexion_B.BehaviorWF_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 10);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            wrist_flexion_B.BehaviorWF_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 8);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            wrist_flexion_B.BehaviorWF_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 4);
          ssSetOutputPortSignal(rts, 6, ((real_T *)
            wrist_flexion_B.BehaviorWF_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *)
            &wrist_flexion_B.BehaviorWF_o8));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *) &wrist_flexion_DWork.BehaviorWF_DSTATE);

      /* path info */
      ssSetModelName(rts, "Behavior WF");
      ssSetPath(rts, "wrist_flexion/Behavior WF");
      ssSetRTModel(rts,wrist_flexion_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 21);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&wrist_flexion_P.BehaviorWF_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&wrist_flexion_P.BehaviorWF_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&wrist_flexion_P.BehaviorWF_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&wrist_flexion_P.BehaviorWF_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&wrist_flexion_P.BehaviorWF_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&wrist_flexion_P.BehaviorWF_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&wrist_flexion_P.BehaviorWF_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&wrist_flexion_P.BehaviorWF_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&wrist_flexion_P.BehaviorWF_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&wrist_flexion_P.BehaviorWF_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&wrist_flexion_P.BehaviorWF_P11_Size[0]);
        ssSetSFcnParam(rts, 11, (mxArray*)&wrist_flexion_P.BehaviorWF_P12_Size[0]);
        ssSetSFcnParam(rts, 12, (mxArray*)&wrist_flexion_P.BehaviorWF_P13_Size[0]);
        ssSetSFcnParam(rts, 13, (mxArray*)&wrist_flexion_P.BehaviorWF_P14_Size[0]);
        ssSetSFcnParam(rts, 14, (mxArray*)&wrist_flexion_P.BehaviorWF_P15_Size[0]);
        ssSetSFcnParam(rts, 15, (mxArray*)&wrist_flexion_P.BehaviorWF_P16_Size[0]);
        ssSetSFcnParam(rts, 16, (mxArray*)&wrist_flexion_P.BehaviorWF_P17_Size[0]);
        ssSetSFcnParam(rts, 17, (mxArray*)&wrist_flexion_P.BehaviorWF_P18_Size[0]);
        ssSetSFcnParam(rts, 18, (mxArray*)&wrist_flexion_P.BehaviorWF_P19_Size[0]);
        ssSetSFcnParam(rts, 19, (mxArray*)&wrist_flexion_P.BehaviorWF_P20_Size[0]);
        ssSetSFcnParam(rts, 20, (mxArray*)&wrist_flexion_P.BehaviorWF_P21_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &wrist_flexion_DWork.BehaviorWF_RWORK[0]);
      ssSetIWork(rts, (int_T *) &wrist_flexion_DWork.BehaviorWF_IWORK[0]);
      ssSetPWork(rts, (void **) &wrist_flexion_DWork.BehaviorWF_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn10.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 4);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 39);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &wrist_flexion_DWork.BehaviorWF_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 25);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &wrist_flexion_DWork.BehaviorWF_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 2, 1);
        ssSetDWorkDataType(rts, 2,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &wrist_flexion_DWork.BehaviorWF_PWORK);

        /* DSTATE */
        ssSetDWorkWidth(rts, 3, 1);
        ssSetDWorkDataType(rts, 3,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWorkUsedAsDState(rts, 3, 1);
        ssSetDWork(rts, 3, &wrist_flexion_DWork.BehaviorWF_DSTATE);
      }

      /* registration */
      mastercon_wf(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

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
    }

    /* Level2 S-Function Block: wrist_flexion/<S6>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = wrist_flexion_rtM->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = wrist_flexion_rtM->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = wrist_flexion_rtM->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = wrist_flexion_rtM->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &wrist_flexion_rtM->NonInlinedSFcns.blkInfo2[11]);
        ssSetRTWSfcnInfo(rts, wrist_flexion_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &wrist_flexion_rtM->NonInlinedSFcns.methods2[11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, wrist_flexion_B.RateTransition);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 112);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "wrist_flexion/UDPXmit/Send");
      ssSetRTModel(rts,wrist_flexion_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&wrist_flexion_P.Send_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&wrist_flexion_P.Send_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&wrist_flexion_P.Send_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&wrist_flexion_P.Send_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &wrist_flexion_DWork.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &wrist_flexion_DWork.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &wrist_flexion_rtM->NonInlinedSFcns.Sfcn11.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &wrist_flexion_DWork.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &wrist_flexion_DWork.Send_PWORK);
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
  }

  wrist_flexion_PrevZCSigState.Integrator_ZCE = UNINITIALIZED_ZCSIG;
  wrist_flexion_PrevZCSigState.SampleandHold.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
  wrist_flexion_PrevZCSigState.SampleandHold_k.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void wrist_flexion_terminate(void)
{
  /* Level2 S-Function Block: '<S2>/PCI-6025E ' (adnipcie) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Behavior WF' (mastercon_wf) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S6>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<Root>/WordSbs' */

  /* Level2 S-Function Block: '<S8>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/Port A' (dopci8255) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/SerialConverter' (serPos) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/ToBits1' (Byte2Bits) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/Port B' (dopci8255) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S8>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S14>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[1];
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
  wrist_flexion_output(tid);
}

void MdlUpdate(int_T tid)
{
  wrist_flexion_update(tid);
}

void MdlInitializeSizes(void)
{
  wrist_flexion_rtM->Sizes.numContStates = (18);/* Number of continuous states */
  wrist_flexion_rtM->Sizes.numY = (0); /* Number of model outputs */
  wrist_flexion_rtM->Sizes.numU = (0); /* Number of model inputs */
  wrist_flexion_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  wrist_flexion_rtM->Sizes.numSampTimes = (4);/* Number of sample times */
  wrist_flexion_rtM->Sizes.numBlocks = (97);/* Number of blocks */
  wrist_flexion_rtM->Sizes.numBlockIO = (84);/* Number of block outputs */
  wrist_flexion_rtM->Sizes.numBlockPrms = (423);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Limited Integrator Block: '<S2>/Integrator' */
  wrist_flexion_X.Integrator_CSTATE[0] = wrist_flexion_P.Integrator_IC;
  wrist_flexion_X.Integrator_CSTATE[1] = wrist_flexion_P.Integrator_IC;

  /* StateSpace Block: '<S2>/LowPassFilterY' */
  {
    int_T i1;
    real_T *xc = &wrist_flexion_X.LowPassFilterY_CSTATE[0];
    for (i1=0; i1 < 8; i1++) {
      xc[i1] = wrist_flexion_P.LowPassFilterY_X0;
    }
  }

  /* StateSpace Block: '<S2>/LowPassFilterX' */
  {
    int_T i1;
    real_T *xc = &wrist_flexion_X.LowPassFilterX_CSTATE[0];
    for (i1=0; i1 < 8; i1++) {
      xc[i1] = wrist_flexion_P.LowPassFilterX_X0;
    }
  }

  /* InitializeConditions for Memory: '<Root>/Memory' */
  wrist_flexion_DWork.Memory_PreviousInput = wrist_flexion_P.Memory_X0;

  /* Level2 S-Function Block: '<Root>/Behavior WF' (mastercon_wf) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[10];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }
}

void MdlStart(void)
{
  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("CursorPos/Switch2/s1"));
        rl32eAddSignal(2, rl32eGetSignalNo("CursorPos/Switch2/s2"));
        rl32eAddSignal(2, rl32eGetSignalNo("Rad2Deg"));
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("CursorPos/Switch2/s1"),
          " X: %4.6f   ");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("CursorPos/Switch2/s2"),
          " Y: %4.6f   ");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("Rad2Deg"),
          " (Rotated %6.2f degrees)  ");
        rl32eSetScope(2, 4, 10);
        rl32eSetScope(2, 40, 0);
        rl32eSetScope(2, 7, 10);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("CursorPos/Switch2/s1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 10, 0);
        rl32eSetTargetScope(2, 1, 0.0);
        rl32eSetTargetScope(2, 11, -10.0);
        rl32eSetTargetScope(2, 10, 10.0);
        xpceScopeAcqOK(2, &wrist_flexion_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* S-Function Block: <S3>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(6)) == 0) {
      if ((i = rl32eDefScope(6,2)) != 0) {
        printf("Error creating scope 6\n");
      } else {
        rl32eAddSignal(6, rl32eGetSignalNo("Behavior WF/p6/s1"));
        rl32eAddSignal(6, rl32eGetSignalNo("Behavior WF/p6/s2"));
        rl32eAddSignal(6, rl32eGetSignalNo("Behavior WF/p6/s3"));
        rl32eAddSignal(6, rl32eGetSignalNo("Behavior WF/p6/s4"));
        rl32eAddSignal(6, rl32eGetSignalNo("Behavior WF/p6/s5"));
        rl32eAddSignal(6, rl32eGetSignalNo("Behavior WF/p6/s6"));
        rl32eAddSignal(6, rl32eGetSignalNo("Behavior WF/p6/s7"));
        rl32eAddSignal(6, rl32eGetSignalNo("Behavior WF/p6/s8"));
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Behavior WF/p6/s1"),
          " Quad 1: %6.4f X  ");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Behavior WF/p6/s2"),
          " Quad 1: %6.4f Y  ");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Behavior WF/p6/s3"),
          " Quad 2: %6.4f X  ");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Behavior WF/p6/s4"),
          " Quad 2: %6.4f Y  ");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Behavior WF/p6/s5"),
          " Quad 3: %6.4f X  ");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Behavior WF/p6/s6"),
          " Quad 3: %6.4f Y  ");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Behavior WF/p6/s7"),
          " Quad 4: %6.4f X  ");
        rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Behavior WF/p6/s8"),
          " Quad 4: %6.4f Y  ");
        rl32eSetScope(6, 4, 10);
        rl32eSetScope(6, 40, 0);
        rl32eSetScope(6, 7, 10);
        rl32eSetScope(6, 0, 0);
        rl32eSetScope(6, 3, rl32eGetSignalNo("Behavior WF/p6/s1"));
        rl32eSetScope(6, 1, 0.0);
        rl32eSetScope(6, 2, 0);
        rl32eSetScope(6, 10, 0);
        rl32eSetTargetScope(6, 1, 0.0);
        rl32eSetTargetScope(6, 11, -10.0);
        rl32eSetTargetScope(6, 10, 10.0);
        xpceScopeAcqOK(6, &wrist_flexion_DWork.SFunction_IWORK_p.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(6);
    }
  }

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior WF/p3/s1"));
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior WF/p3/s2"));
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior WF/p3/s3"));
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior WF/p3/s4"));
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior WF/p3/s1"),
          "%6.0f State");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior WF/p3/s2"),
          "%6.0f Rewards");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior WF/p3/s3"),
          "%6.0f Aborts");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior WF/p3/s4"),
          "%6.0f Failures");
        rl32eSetScope(1, 4, 10);
        rl32eSetScope(1, 40, 0);
        rl32eSetScope(1, 7, 10);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Behavior WF/p3/s1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 10, 0);
        rl32eSetTargetScope(1, 1, 0.0);
        rl32eSetTargetScope(1, 11, -10.0);
        rl32eSetTargetScope(1, 10, 10.0);
        xpceScopeAcqOK(1, &wrist_flexion_DWork.SFunction_IWORK_m.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Level2 S-Function Block: '<S2>/PCI-6025E ' (adnipcie) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S2>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S6>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[11];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S7>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("Behavior WF/p7/s1"));
        rl32eAddSignal(4, rl32eGetSignalNo("Behavior WF/p7/s2"));
        rl32eAddSignal(4, rl32eGetSignalNo("Behavior WF/p7/s3"));
        rl32eAddSignal(4, rl32eGetSignalNo("Behavior WF/p7/s4"));
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Behavior WF/p7/s1"),
          "%6.0f major");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Behavior WF/p7/s2"),
          "%6.0f minor");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Behavior WF/p7/s3"),
          "%6.0f revision");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("Behavior WF/p7/s4"),
          "%6.0f build");
        rl32eSetScope(4, 4, 10);
        rl32eSetScope(4, 40, 0);
        rl32eSetScope(4, 7, 10);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("Behavior WF/p7/s1"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 10, 0);
        rl32eSetTargetScope(4, 1, 0.0);
        rl32eSetTargetScope(4, 11, -10.0);
        rl32eSetTargetScope(4, 10, 10.0);
        xpceScopeAcqOK(4, &wrist_flexion_DWork.SFunction_IWORK_pn.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /*trigger Subsystem Block: '<S12>/Sample and Hold' */
  wrist_flexi_SampleandHold_Start(&wrist_flexion_B.SampleandHold,
    (rtP_SampleandHold_wrist_flexion *) &wrist_flexion_P.SampleandHold);

  /* UniformRandomNumber Block: '<S4>/Uniform Random Number' */
  {
    uint32_T *RandSeed = (uint32_T *)
      &wrist_flexion_DWork.UniformRandomNumber_IWORK.RandSeed;
    uint32_T r, t;
    *RandSeed = (uint32_T)wrist_flexion_P.UniformRandomNumber_Seed;
    r = *RandSeed >> 16;
    t = *RandSeed & RT_BIT16;
    *RandSeed = ((*RandSeed - (r << 16) - t) << 16) + t + r;
    if (*RandSeed < 1) {
      *RandSeed = SEED0;
    }

    if (*RandSeed > MAXSEED) {
      *RandSeed = MAXSEED;
    }

    wrist_flexion_DWork.UniformRandomNumber_RWORK.NextOutput
      = rt_Urand(RandSeed++) * (wrist_flexion_P.UniformRandomNumber_Max -
      wrist_flexion_P.UniformRandomNumber_Min) +
      wrist_flexion_P.UniformRandomNumber_Min;
  }

  /*trigger Subsystem Block: '<S4>/Sample and Hold' */
  wrist_flexi_SampleandHold_Start(&wrist_flexion_B.SampleandHold_k,
    (rtP_SampleandHold_wrist_flexion *) &wrist_flexion_P.SampleandHold_k);

  /* Start for iterator system: '<Root>/WordSbs' */

  /* Level2 S-Function Block: '<S8>/Port A' (dopci8255) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S8>/Port B' (dopci8255) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Start for iterator system: '<S8>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S14>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = wrist_flexion_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  wrist_flexion_DWork.SampleandHold_k.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  wrist_flexion_DWork.SampleandHold.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;

  /* user code (Start function Trailer) */
  rl32eSetScope(2, 8, 1);
  rl32eSetScope(6, 8, 1);
  rl32eSetScope(1, 8, 1);
  rl32eSetScope(4, 8, 1);
  MdlInitialize();
}

rtModel_wrist_flexion *wrist_flexion(void)
{
  wrist_flexion_initialize(1);
  return wrist_flexion_rtM;
}

void MdlTerminate(void)
{
  wrist_flexion_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
