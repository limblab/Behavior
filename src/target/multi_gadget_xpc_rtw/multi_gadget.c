/*
 * multi_gadget.c
 *
 * Real-Time Workshop code generation for Simulink model "multi_gadget.mdl".
 *
 * Model Version              : 1.82
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 14:02:34 2010
 */

#include "rt_logging_mmi.h"
#include "multi_gadget_capi.h"
#include "multi_gadget.h"
#include "multi_gadget_private.h"
#include <stdio.h>
#include "multi_gadget_dt.h"

/* Block signals (auto storage) */
BlockIO_multi_gadget multi_gadget_B;

/* Block states (auto storage) */
D_Work_multi_gadget multi_gadget_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_multi_gadget multi_gadget_PrevZCSigState;

/* Real-time model */
rtModel_multi_gadget multi_gadget_rtM_;
rtModel_multi_gadget *multi_gadget_rtM = &multi_gadget_rtM_;
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
  if (++multi_gadget_rtM->Timing.TaskCounters.TID[2] == 20) {/* Sample time: [0.02s, 0.0s] */
    multi_gadget_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  multi_gadget_rtM->Timing.sampleHits[2] =
    (multi_gadget_rtM->Timing.TaskCounters.TID[2] == 0);
}

/* Start for trigger system:
 *   '<S4>/Sample and Hold'
 *   '<S12>/Sample and Hold'
 */
void multi_gadge_SampleandHold_Start(rtB_SampleandHold_multi_gadget *localB,
  rtP_SampleandHold_multi_gadget *localP)
{
  /* virtual outports code */

  /* (Virtual) Outport Block: '<S11>/ ' */
  localB->In = localP->_Y0;
}

/* Output and update for trigger system:
 *   '<S4>/Sample and Hold'
 *   '<S12>/Sample and Hold'
 */
void multi_gadget_SampleandHold(real_T rtu_0, real_T rtu_1,
  rtB_SampleandHold_multi_gadget *localB, rtDW_SampleandHold_multi_gadget
  *localDW, rtZCE_SampleandHold_multi_gadge *localZCE)
{
  {
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
void multi_gadget_output(int_T tid)
{
  /* Reset subsysRan breadcrumbs */
  srClearBC(multi_gadget_DWork.SampleandHold_m.SampleandHold_SubsysRanBC);
  srClearBC(multi_gadget_DWork.SampleandHold.SampleandHold_SubsysRanBC);

  {                                    /* Sample time: [0.001s, 0.0s] */
    /* Level2 S-Function Block: '<Root>/PCI-6025E DI' (dinipcie) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S1>/PCI-6025E AD' (adnipcie) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[9];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S1>/NewtonCal1' */
    multi_gadget_B.NewtonCal1 = multi_gadget_P.NewtonCal1_Gain *
      multi_gadget_B.PCI6025EAD_o1;

    /* Gain: '<S1>/NewtonCal2' */
    multi_gadget_B.NewtonCal2 = multi_gadget_P.NewtonCal2_Gain *
      multi_gadget_B.PCI6025EAD_o2;

    /* Sum: '<S1>/Add1' */
    multi_gadget_B.Add1 = multi_gadget_B.NewtonCal1 - multi_gadget_B.NewtonCal2;

    /* Sum: '<S1>/Add' */
    multi_gadget_B.Add = multi_gadget_B.NewtonCal1 + multi_gadget_B.NewtonCal2;
  }

  /* S-Function (sfun_nddirectlook) Block: '<Root>/TargetTable'
   */

  /* LookupNDDirect: '<Root>/TargetTable' */
  /* 2-dimensional Direct Look-Up returning a 2-D Matrix */
  (void) memcpy((void *)multi_gadget_B.TargetTable,(void *)
                &multi_gadget_P.TargetTable_table[0],
                sizeof(real_T)*80U);

  {
    int32_T i;
    for (i = 0; i < 80; i++) {
      /* Reshape: '<Root>/Reshape' */
      multi_gadget_B.Reshape[i] = multi_gadget_B.TargetTable[i];
    }
  }

  /* Level2 S-Function Block: '<Root>/Behavior MG' (mastercon_mg) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[10];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S2>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[11];
    sfcnOutputs(rts, 0);
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    /* Level2 S-Function Block: '<S2>/PCI-6025E DO' (donipcie) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[12];
      sfcnOutputs(rts, 1);
    }
  }

  /* ok to acquire for <S3>/S-Function */
  multi_gadget_DWork.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S5>/S-Function */
  multi_gadget_DWork.SFunction_IWORK_k.AcquireOK = 1;

  {                                    /* Sample time: [0.001s, 0.0s] */
    /* ok to acquire for <S6>/S-Function */
    multi_gadget_DWork.SFunction_IWORK_b.AcquireOK = 1;

    /* Pack: <S7>/Pack */
    (void) memcpy(multi_gadget_B.Pack,&multi_gadget_B.Add1,
                  8);
    (void) memcpy(&multi_gadget_B.Pack[8],&multi_gadget_B.Add,
                  8);
    (void) memcpy(&multi_gadget_B.Pack[16],&multi_gadget_B.BehaviorMG_o8[0],
                  8);
    (void) memcpy(&multi_gadget_B.Pack[24],&multi_gadget_B.BehaviorMG_o8[1],
                  8);
    (void) memcpy(&multi_gadget_B.Pack[32],&multi_gadget_B.BehaviorMG_o8[2],
                  8);
    (void) memcpy(&multi_gadget_B.Pack[40],&multi_gadget_B.BehaviorMG_o8[3],
                  8);
    (void) memcpy(&multi_gadget_B.Pack[48],&multi_gadget_B.BehaviorMG_o8[4],
                  8);
    (void) memcpy(&multi_gadget_B.Pack[56],&multi_gadget_B.BehaviorMG_o8[5],
                  8);
    (void) memcpy(&multi_gadget_B.Pack[64],&multi_gadget_B.BehaviorMG_o8[6],
                  8);
    (void) memcpy(&multi_gadget_B.Pack[72],&multi_gadget_B.BehaviorMG_o8[7],
                  8);
    (void) memcpy(&multi_gadget_B.Pack[80],&multi_gadget_B.BehaviorMG_o8[8],
                  8);
    (void) memcpy(&multi_gadget_B.Pack[88],&multi_gadget_B.BehaviorMG_o8[9],
                  8);
    (void) memcpy(&multi_gadget_B.Pack[96],&multi_gadget_B.BehaviorMG_o7[0],
                  8);
    (void) memcpy(&multi_gadget_B.Pack[104],&multi_gadget_B.BehaviorMG_o7[1],
                  8);
  }

  {
    int32_T i;

    /* RateTransition: '<S7>/Rate Transition' */
    if (1 && multi_gadget_rtM->Timing.TaskCounters.TID[2] == 0) {
      for (i = 0; i < 112; i++) {
        multi_gadget_B.RateTransition[i] = multi_gadget_B.Pack[i];
      }
    }
  }

  if (multi_gadget_rtM->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.02s, 0.0s] */
    /* Level2 S-Function Block: '<S7>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[13];
      sfcnOutputs(rts, 2);
    }
  }

  /* ok to acquire for <S8>/S-Function */
  multi_gadget_DWork.SFunction_IWORK_b4.AcquireOK = 1;

  {                                    /* Sample time: [0.001s, 0.0s] */
    /* ok to acquire for <S10>/S-Function */
    multi_gadget_DWork.SFunction_IWORK_m.AcquireOK = 1;
  }

  /* Clock Block: '<S12>/Clock'
   */
  multi_gadget_B.Clock = multi_gadget_rtM->Timing.t[0];

  /* SignalConversion: '<S12>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
  multi_gadget_B.HiddenBuf_InsertedFor_Sampleand = multi_gadget_B.BehaviorMG_o1;

  /* SubSystem Block: '<S12>/Sample and Hold'
   */
  multi_gadget_SampleandHold(multi_gadget_B.HiddenBuf_InsertedFor_Sampleand,
    multi_gadget_B.Clock, &multi_gadget_B.SampleandHold,
    &multi_gadget_DWork.SampleandHold,
    &multi_gadget_PrevZCSigState.SampleandHold);

  /* Sum: '<S12>/Sum' */
  multi_gadget_B.Sum = multi_gadget_B.Clock - multi_gadget_B.SampleandHold.In;

  {                                    /* Sample time: [0.001s, 0.0s] */
    /* UniformRandomNumber Block: '<S4>/Uniform Random Number'
     */
    multi_gadget_B.UniformRandomNumber =
      multi_gadget_DWork.UniformRandomNumber_RWORK.NextOutput;

    /* RelationalOperator: '<S4>/Relational Operator' incorporates:
     *  Constant: '<S4>/JackpotChance'
     */
    multi_gadget_B.RelationalOperator = (multi_gadget_B.UniformRandomNumber >
      multi_gadget_P.JackpotChance_Value);

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/RewardJackpot'
     *  Constant: '<S4>/RewardTime'
     */
    if (multi_gadget_B.RelationalOperator) {
      multi_gadget_B.Switch = multi_gadget_P.RewardTime_Value;
    } else {
      multi_gadget_B.Switch = multi_gadget_P.RewardJackpot_Value;
    }
  }

  /* SignalConversion: '<S4>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
  multi_gadget_B.HiddenBuf_InsertedFor_Samplea_i = multi_gadget_B.BehaviorMG_o1;

  /* SubSystem Block: '<S4>/Sample and Hold'
   */
  multi_gadget_SampleandHold(multi_gadget_B.HiddenBuf_InsertedFor_Samplea_i,
    multi_gadget_B.Switch, &multi_gadget_B.SampleandHold_m,
    &multi_gadget_DWork.SampleandHold_m,
    &multi_gadget_PrevZCSigState.SampleandHold_m);

  {
    int32_T s9_iter;

    /* RelationalOperator: '<S12>/Relational Operator' */
    multi_gadget_B.RelationalOperator_c = (multi_gadget_B.Sum <
      multi_gadget_B.SampleandHold_m.In);

    /* DataTypeConversion: '<S4>/Data Type Conversion' */
    multi_gadget_B.DataTypeConversion = (real_T)
      multi_gadget_B.RelationalOperator_c;
    for (s9_iter = 0; s9_iter < 4; s9_iter++) {
      multi_gadget_B.ForIterator = (real_T)s9_iter;

      /* Output and update for iterator system: '<Root>/WordSbs' */

      /* Level2 S-Function Block: '<S9>/xPC Target  Time ' (xpctimeinfo) */
      {
        SimStruct *rts = multi_gadget_rtM->childSfunctions[2];
        sfcnOutputs(rts, 1);
      }

      /* Switch: '<S9>/Switch' incorporates:
       *  Constant: '<S9>/Constant'
       */
      if (multi_gadget_B.ForIterator >= multi_gadget_P.Switch_Threshold) {
        multi_gadget_B.Switch_d = multi_gadget_P.Constant_Value;
      } else {
        multi_gadget_B.Switch_d = multi_gadget_B.BehaviorMG_o2;
      }

      /* Level2 S-Function Block: '<S9>/ToBits' (Byte2Bits) */
      {
        SimStruct *rts = multi_gadget_rtM->childSfunctions[3];
        sfcnOutputs(rts, 1);
      }

      /* Level2 S-Function Block: '<S9>/Port A' (dopci8255) */
      {
        SimStruct *rts = multi_gadget_rtM->childSfunctions[4];
        sfcnOutputs(rts, 1);
      }

      {
        real_T cg_in;
        real_T cg_in_0;
        real_T tmp;
        real_T tmp_0;

        /* Gain: '<S9>/toThousandths' */
        tmp = multi_gadget_B.Add1;
        tmp_0 = multi_gadget_B.Add;
        multi_gadget_B.toThousandths[0] = multi_gadget_P.toThousandths_Gain *
          tmp;
        multi_gadget_B.toThousandths[1] = multi_gadget_P.toThousandths_Gain *
          tmp_0;

        /* Sum: '<S9>/Add2' incorporates:
         *  Constant: '<S9>/Constant2'
         */
        cg_in = multi_gadget_B.toThousandths[0];
        multi_gadget_B.Add2 = cg_in + multi_gadget_P.Constant2_Value;

        /* Sum: '<S9>/Add3' incorporates:
         *  Constant: '<S9>/Constant2'
         */
        cg_in_0 = multi_gadget_B.toThousandths[1];
        multi_gadget_B.Add3 = cg_in_0 + multi_gadget_P.Constant2_Value;
      }

      /* Level2 S-Function Block: '<S9>/SerialConverter' (serPos) */
      {
        SimStruct *rts = multi_gadget_rtM->childSfunctions[5];
        sfcnOutputs(rts, 1);
      }

      /* Level2 S-Function Block: '<S9>/ToBits1' (Byte2Bits) */
      {
        SimStruct *rts = multi_gadget_rtM->childSfunctions[6];
        sfcnOutputs(rts, 1);
      }

      /* Level2 S-Function Block: '<S9>/Port B' (dopci8255) */
      {
        SimStruct *rts = multi_gadget_rtM->childSfunctions[7];
        sfcnOutputs(rts, 1);
      }

      do {
        /* Output and update for iterator system: '<S9>/While Iterator Subsystem' */

        /* Level2 S-Function Block: '<S14>/xPC Target  Time ' (xpctimeinfo) */
        {
          SimStruct *rts = multi_gadget_rtM->childSfunctions[0];
          sfcnOutputs(rts, 1);
        }

        /* Sum: '<S14>/Subtract' */
        multi_gadget_B.Subtract = multi_gadget_B.xPCTargetTime_c -
          multi_gadget_B.xPCTargetTime;

        /* Gain: '<S14>/ScaleTouSec' */
        multi_gadget_B.ScaleTouSec = multi_gadget_P.ScaleTouSec_Gain *
          multi_gadget_B.Subtract;

        /* RelationalOperator: '<S16>/Compare' incorporates:
         *  Constant: '<S16>/Constant'
         */
        multi_gadget_B.Compare = (multi_gadget_B.ScaleTouSec >
          multi_gadget_P.Constant_Value_l);

        /* Switch: '<S14>/Switch' incorporates:
         *  Constant: '<S14>/StobeHi'
         *  Constant: '<S14>/StrobeLow'
         */
        if (multi_gadget_B.Compare) {
          multi_gadget_B.Switch_j = multi_gadget_P.StobeHi_Value;
        } else {
          multi_gadget_B.Switch_j = multi_gadget_P.StrobeLow_Value;
        }

        /* Level2 S-Function Block: '<S14>/PCI-6025E ' (donipcie) */
        {
          SimStruct *rts = multi_gadget_rtM->childSfunctions[1];
          sfcnOutputs(rts, 1);
        }

        /* RelationalOperator: '<S15>/Compare' incorporates:
         *  Constant: '<S15>/Constant'
         */
        multi_gadget_B.Compare_c = (multi_gadget_B.ScaleTouSec <=
          multi_gadget_P.Constant_Value_m);
      } while (multi_gadget_B.Compare_c);
    }
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void multi_gadget_update(int_T tid)
{
  /* Level2 S-Function Block: '<Root>/Behavior MG' (mastercon_mg) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[10];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    /* UniformRandomNumber Block: '<S4>/Uniform Random Number' */
    multi_gadget_DWork.UniformRandomNumber_RWORK.NextOutput = rt_Urand((uint32_T
      *)&multi_gadget_DWork.UniformRandomNumber_IWORK.RandSeed) *
      (multi_gadget_P.UniformRandomNumber_Max -
       multi_gadget_P.UniformRandomNumber_Min) +
      multi_gadget_P.UniformRandomNumber_Min;
  }

  /* Update absolute time for base rate */
  if (!(++multi_gadget_rtM->Timing.clockTick0))
    ++multi_gadget_rtM->Timing.clockTickH0;
  multi_gadget_rtM->Timing.t[0] = multi_gadget_rtM->Timing.clockTick0 *
    multi_gadget_rtM->Timing.stepSize0 + multi_gadget_rtM->Timing.clockTickH0 *
    multi_gadget_rtM->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++multi_gadget_rtM->Timing.clockTick1))
      ++multi_gadget_rtM->Timing.clockTickH1;
    multi_gadget_rtM->Timing.t[1] = multi_gadget_rtM->Timing.clockTick1 *
      multi_gadget_rtM->Timing.stepSize1 + multi_gadget_rtM->Timing.clockTickH1 *
      multi_gadget_rtM->Timing.stepSize1 * 4294967296.0;
  }

  if (multi_gadget_rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    if (!(++multi_gadget_rtM->Timing.clockTick2))
      ++multi_gadget_rtM->Timing.clockTickH2;
    multi_gadget_rtM->Timing.t[2] = multi_gadget_rtM->Timing.clockTick2 *
      multi_gadget_rtM->Timing.stepSize2 + multi_gadget_rtM->Timing.clockTickH2 *
      multi_gadget_rtM->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void multi_gadget_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */
  /* initialize real-time model */
  (void) memset((char_T *)multi_gadget_rtM,0,
                sizeof(rtModel_multi_gadget));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&multi_gadget_rtM->solverInfo,
                          &multi_gadget_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&multi_gadget_rtM->solverInfo, &rtmGetTPtr(multi_gadget_rtM));
    rtsiSetStepSizePtr(&multi_gadget_rtM->solverInfo,
                       &multi_gadget_rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&multi_gadget_rtM->solverInfo, (&rtmGetErrorStatus
      (multi_gadget_rtM)));
    rtsiSetRTModelPtr(&multi_gadget_rtM->solverInfo, multi_gadget_rtM);
  }

  rtsiSetSimTimeStep(&multi_gadget_rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&multi_gadget_rtM->solverInfo,"FixedStepDiscrete");
  multi_gadget_rtM->solverInfoPtr = (&multi_gadget_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = multi_gadget_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    multi_gadget_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    multi_gadget_rtM->Timing.sampleTimes =
      (&multi_gadget_rtM->Timing.sampleTimesArray[0]);
    multi_gadget_rtM->Timing.offsetTimes =
      (&multi_gadget_rtM->Timing.offsetTimesArray[0]);

    /* task periods */
    multi_gadget_rtM->Timing.sampleTimes[0] = (0.0);
    multi_gadget_rtM->Timing.sampleTimes[1] = (0.001);
    multi_gadget_rtM->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    multi_gadget_rtM->Timing.offsetTimes[0] = (0.0);
    multi_gadget_rtM->Timing.offsetTimes[1] = (0.0);
    multi_gadget_rtM->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(multi_gadget_rtM, &multi_gadget_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = multi_gadget_rtM->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    multi_gadget_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(multi_gadget_rtM, -1);
  multi_gadget_rtM->Timing.stepSize0 = 0.001;
  multi_gadget_rtM->Timing.stepSize1 = 0.001;
  multi_gadget_rtM->Timing.stepSize2 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    multi_gadget_rtM->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(multi_gadget_rtM->rtwLogInfo, 0);
    rtliSetLogMaxRows(multi_gadget_rtM->rtwLogInfo, 1000);
    rtliSetLogDecimation(multi_gadget_rtM->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(multi_gadget_rtM->rtwLogInfo, "rt_");
    rtliSetLogT(multi_gadget_rtM->rtwLogInfo, "tout");
    rtliSetLogX(multi_gadget_rtM->rtwLogInfo, "");
    rtliSetLogXFinal(multi_gadget_rtM->rtwLogInfo, "");
    rtliSetSigLog(multi_gadget_rtM->rtwLogInfo, "");
    rtliSetLogXSignalInfo(multi_gadget_rtM->rtwLogInfo, NULL);
    rtliSetLogXSignalPtrs(multi_gadget_rtM->rtwLogInfo, NULL);
    rtliSetLogY(multi_gadget_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(multi_gadget_rtM->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(multi_gadget_rtM->rtwLogInfo, NULL);
  }

  /* external mode info */
  multi_gadget_rtM->Sizes.checksums[0] = (1987952882U);
  multi_gadget_rtM->Sizes.checksums[1] = (3774861458U);
  multi_gadget_rtM->Sizes.checksums[2] = (2429878315U);
  multi_gadget_rtM->Sizes.checksums[3] = (4051533U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    multi_gadget_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &multi_gadget_DWork.SampleandHold_m.SampleandHold_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &multi_gadget_DWork.SampleandHold.SampleandHold_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &multi_gadget_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, multi_gadget_rtM->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(multi_gadget_rtM));
  }

  multi_gadget_rtM->solverInfoPtr = (&multi_gadget_rtM->solverInfo);
  multi_gadget_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&multi_gadget_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&multi_gadget_rtM->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  multi_gadget_rtM->ModelData.blockIO = ((void *) &multi_gadget_B);
  (void) memset(((void *) &multi_gadget_B),0,
                sizeof(BlockIO_multi_gadget));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&multi_gadget_B.PCI6025EDI);
    for (i = 0; i < 211; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    pVoidBlockIORegion = (void *)(&multi_gadget_B.xPCTargetTime);
    for (i = 0; i < 28; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    ((real_T*)&multi_gadget_B.SampleandHold.In)[0] = 0.0;
    ((real_T*)&multi_gadget_B.SampleandHold_m.In)[0] = 0.0;
  }

  /* parameters */
  multi_gadget_rtM->ModelData.defaultParam = ((real_T *) &multi_gadget_P);

  /* states (dwork) */
  multi_gadget_rtM->Work.dwork = ((void *) &multi_gadget_DWork);
  (void) memset((char_T *) &multi_gadget_DWork,0,
                sizeof(D_Work_multi_gadget));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &multi_gadget_DWork.BehaviorMG_DSTATE;
    for (i = 0; i < 103; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    multi_gadget_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    multi_gadget_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  multi_gadget_InitializeDataMapInfo(multi_gadget_rtM);

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &multi_gadget_rtM->NonInlinedSFcns.sfcnInfo;
    multi_gadget_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(multi_gadget_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &multi_gadget_rtM->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(multi_gadget_rtM));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(multi_gadget_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (multi_gadget_rtM));
    rtssSetStepSizePtr(sfcnInfo, &multi_gadget_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(multi_gadget_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &multi_gadget_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &multi_gadget_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &multi_gadget_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &multi_gadget_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &multi_gadget_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &multi_gadget_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &multi_gadget_rtM->solverInfoPtr);
  }

  multi_gadget_rtM->Sizes.numSFcns = (14);

  /* register each child */
  {
    (void) memset((void *)&multi_gadget_rtM->NonInlinedSFcns.childSFunctions[0],
                  0,
                  14*sizeof(SimStruct));
    multi_gadget_rtM->childSfunctions =
      (&multi_gadget_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 14; i++) {
        multi_gadget_rtM->childSfunctions[i] =
          (&multi_gadget_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: multi_gadget/<S14>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &multi_gadget_B.xPCTargetTime_c));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts,
                "multi_gadget/WordSbs/While Iterator Subsystem/xPC Target  Time ");
      ssSetRTModel(rts,multi_gadget_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&multi_gadget_P.xPCTargetTime_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&multi_gadget_P.xPCTargetTime_P2_Size[0]);
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

    /* Level2 S-Function Block: multi_gadget/<S14>/PCI-6025E  (donipcie) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &multi_gadget_B.Switch_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &multi_gadget_B.DataTypeConversion;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E ");
      ssSetPath(rts, "multi_gadget/WordSbs/While Iterator Subsystem/PCI-6025E ");
      ssSetRTModel(rts,multi_gadget_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&multi_gadget_P.PCI6025E_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&multi_gadget_P.PCI6025E_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&multi_gadget_P.PCI6025E_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&multi_gadget_P.PCI6025E_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&multi_gadget_P.PCI6025E_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&multi_gadget_P.PCI6025E_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&multi_gadget_P.PCI6025E_P7_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &multi_gadget_DWork.PCI6025E_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn1.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &multi_gadget_DWork.PCI6025E_IWORK[0]);
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

    /* Level2 S-Function Block: multi_gadget/<S9>/xPC Target  Time  (xpctimeinfo) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &multi_gadget_B.xPCTargetTime));
        }
      }

      /* path info */
      ssSetModelName(rts, "xPC Target\n Time ");
      ssSetPath(rts, "multi_gadget/WordSbs/xPC Target  Time ");
      ssSetRTModel(rts,multi_gadget_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&multi_gadget_P.xPCTargetTime_P1_Size_b
                       [0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&multi_gadget_P.xPCTargetTime_P2_Size_o
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

    /* Level2 S-Function Block: multi_gadget/<S9>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &multi_gadget_B.Switch_d;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &multi_gadget_B.ToBits_o1_f));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &multi_gadget_B.ToBits_o2_n));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &multi_gadget_B.ToBits_o3_i));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &multi_gadget_B.ToBits_o4_o));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &multi_gadget_B.ToBits_o5_n));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &multi_gadget_B.ToBits_o6_a));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &multi_gadget_B.ToBits_o7_j));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &multi_gadget_B.ToBits_o8_f));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts, "multi_gadget/WordSbs/ToBits");
      ssSetRTModel(rts,multi_gadget_rtM);
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

    /* Level2 S-Function Block: multi_gadget/<S9>/Port A (dopci8255) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits_o1_f;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits_o2_n;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn4.UPtrs2;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits_o3_i;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn4.UPtrs3;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits_o4_o;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn4.UPtrs4;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits_o5_n;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn4.UPtrs5;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits_o6_a;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn4.UPtrs6;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits_o7_j;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn4.UPtrs7;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits_o8_f;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port A");
      ssSetPath(rts, "multi_gadget/WordSbs/Port A");
      ssSetRTModel(rts,multi_gadget_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&multi_gadget_P.PortA_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&multi_gadget_P.PortA_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&multi_gadget_P.PortA_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&multi_gadget_P.PortA_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&multi_gadget_P.PortA_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&multi_gadget_P.PortA_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&multi_gadget_P.PortA_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&multi_gadget_P.PortA_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&multi_gadget_P.PortA_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &multi_gadget_DWork.PortA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn4.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &multi_gadget_DWork.PortA_IWORK[0]);
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

    /* Level2 S-Function Block: multi_gadget/<S9>/SerialConverter (serPos) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[5]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &multi_gadget_B.ForIterator;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn5.UPtrs1;
          sfcnUPtrs[0] = &multi_gadget_B.Add2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn5.UPtrs2;
          sfcnUPtrs[0] = &multi_gadget_B.Add3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &multi_gadget_B.SerialConverter));
        }
      }

      /* path info */
      ssSetModelName(rts, "SerialConverter");
      ssSetPath(rts, "multi_gadget/WordSbs/SerialConverter");
      ssSetRTModel(rts,multi_gadget_rtM);
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

    /* Level2 S-Function Block: multi_gadget/<S9>/ToBits1 (Byte2Bits) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[6]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &multi_gadget_B.SerialConverter;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &multi_gadget_B.ToBits1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &multi_gadget_B.ToBits1_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &multi_gadget_B.ToBits1_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &multi_gadget_B.ToBits1_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &multi_gadget_B.ToBits1_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &multi_gadget_B.ToBits1_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &multi_gadget_B.ToBits1_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &multi_gadget_B.ToBits1_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits1");
      ssSetPath(rts, "multi_gadget/WordSbs/ToBits1");
      ssSetRTModel(rts,multi_gadget_rtM);
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

    /* Level2 S-Function Block: multi_gadget/<S9>/Port B (dopci8255) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[7]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits1_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn7.UPtrs1;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits1_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn7.UPtrs2;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits1_o3;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn7.UPtrs3;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits1_o4;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn7.UPtrs4;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits1_o5;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn7.UPtrs5;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits1_o6;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn7.UPtrs6;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits1_o7;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn7.UPtrs7;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits1_o8;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port B");
      ssSetPath(rts, "multi_gadget/WordSbs/Port B");
      ssSetRTModel(rts,multi_gadget_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&multi_gadget_P.PortB_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&multi_gadget_P.PortB_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&multi_gadget_P.PortB_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&multi_gadget_P.PortB_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&multi_gadget_P.PortB_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&multi_gadget_P.PortB_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&multi_gadget_P.PortB_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&multi_gadget_P.PortB_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&multi_gadget_P.PortB_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &multi_gadget_DWork.PortB_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn7.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &multi_gadget_DWork.PortB_IWORK[0]);
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

    /* Level2 S-Function Block: multi_gadget/<Root>/PCI-6025E DI (dinipcie) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[8]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &multi_gadget_B.PCI6025EDI));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E DI");
      ssSetPath(rts, "multi_gadget/PCI-6025E DI");
      ssSetRTModel(rts,multi_gadget_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&multi_gadget_P.PCI6025EDI_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&multi_gadget_P.PCI6025EDI_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&multi_gadget_P.PCI6025EDI_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&multi_gadget_P.PCI6025EDI_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&multi_gadget_P.PCI6025EDI_P5_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &multi_gadget_DWork.PCI6025EDI_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn8.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &multi_gadget_DWork.PCI6025EDI_IWORK[0]);
      }

      /* registration */
      dinipcie(rts);
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

    /* Level2 S-Function Block: multi_gadget/<S1>/PCI-6025E AD (adnipcie) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[9]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &multi_gadget_B.PCI6025EAD_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &multi_gadget_B.PCI6025EAD_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E AD");
      ssSetPath(rts, "multi_gadget/CursorPos/PCI-6025E AD");
      ssSetRTModel(rts,multi_gadget_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&multi_gadget_P.PCI6025EAD_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&multi_gadget_P.PCI6025EAD_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&multi_gadget_P.PCI6025EAD_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&multi_gadget_P.PCI6025EAD_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&multi_gadget_P.PCI6025EAD_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&multi_gadget_P.PCI6025EAD_P6_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &multi_gadget_DWork.PCI6025EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &multi_gadget_DWork.PCI6025EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn9.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &multi_gadget_DWork.PCI6025EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &multi_gadget_DWork.PCI6025EAD_IWORK[0]);
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

    /* Level2 S-Function Block: multi_gadget/<Root>/Behavior MG (mastercon_mg) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[10]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[10]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn10.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn10.UPtrs0;
          sfcnUPtrs[0] = &multi_gadget_B.PCI6025EDI;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn10.UPtrs1;
          sfcnUPtrs[0] = &multi_gadget_B.Add1;
          sfcnUPtrs[1] = &multi_gadget_B.Add;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn10.UPtrs2;

          {
            int_T i1;
            const real_T *u2 = multi_gadget_B.Reshape;
            for (i1=0; i1 < 80; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 80);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 10);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &multi_gadget_B.BehaviorMG_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &multi_gadget_B.BehaviorMG_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &multi_gadget_B.BehaviorMG_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &multi_gadget_B.BehaviorMG_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &multi_gadget_B.BehaviorMG_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 4);
          ssSetOutputPortSignal(rts, 5, ((real_T *) multi_gadget_B.BehaviorMG_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 2);
          ssSetOutputPortSignal(rts, 6, ((real_T *) multi_gadget_B.BehaviorMG_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 10);
          ssSetOutputPortSignal(rts, 7, ((real_T *) multi_gadget_B.BehaviorMG_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 4);
          ssSetOutputPortSignal(rts, 8, ((real_T *) multi_gadget_B.BehaviorMG_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 4);
          ssSetOutputPortSignal(rts, 9, ((real_T *)
            multi_gadget_B.BehaviorMG_o10));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *) &multi_gadget_DWork.BehaviorMG_DSTATE);

      /* path info */
      ssSetModelName(rts, "Behavior MG");
      ssSetPath(rts, "multi_gadget/Behavior MG");
      ssSetRTModel(rts,multi_gadget_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 17);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&multi_gadget_P.BehaviorMG_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&multi_gadget_P.BehaviorMG_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&multi_gadget_P.BehaviorMG_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&multi_gadget_P.BehaviorMG_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&multi_gadget_P.BehaviorMG_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&multi_gadget_P.BehaviorMG_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&multi_gadget_P.BehaviorMG_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&multi_gadget_P.BehaviorMG_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&multi_gadget_P.BehaviorMG_P9_Size[0]);
        ssSetSFcnParam(rts, 9, (mxArray*)&multi_gadget_P.BehaviorMG_P10_Size[0]);
        ssSetSFcnParam(rts, 10, (mxArray*)&multi_gadget_P.BehaviorMG_P11_Size[0]);
        ssSetSFcnParam(rts, 11, (mxArray*)&multi_gadget_P.BehaviorMG_P12_Size[0]);
        ssSetSFcnParam(rts, 12, (mxArray*)&multi_gadget_P.BehaviorMG_P13_Size[0]);
        ssSetSFcnParam(rts, 13, (mxArray*)&multi_gadget_P.BehaviorMG_P14_Size[0]);
        ssSetSFcnParam(rts, 14, (mxArray*)&multi_gadget_P.BehaviorMG_P15_Size[0]);
        ssSetSFcnParam(rts, 15, (mxArray*)&multi_gadget_P.BehaviorMG_P16_Size[0]);
        ssSetSFcnParam(rts, 16, (mxArray*)&multi_gadget_P.BehaviorMG_P17_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &multi_gadget_DWork.BehaviorMG_RWORK[0]);
      ssSetIWork(rts, (int_T *) &multi_gadget_DWork.BehaviorMG_IWORK[0]);
      ssSetPWork(rts, (void **) &multi_gadget_DWork.BehaviorMG_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn10.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 4);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 37);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &multi_gadget_DWork.BehaviorMG_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 135);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &multi_gadget_DWork.BehaviorMG_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 2, 1);
        ssSetDWorkDataType(rts, 2,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &multi_gadget_DWork.BehaviorMG_PWORK);

        /* DSTATE */
        ssSetDWorkWidth(rts, 3, 1);
        ssSetDWorkDataType(rts, 3,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWorkUsedAsDState(rts, 3, 1);
        ssSetDWork(rts, 3, &multi_gadget_DWork.BehaviorMG_DSTATE);
      }

      /* registration */
      mastercon_mg(rts);
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
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: multi_gadget/<S2>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[11]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn11.UPtrs0;
          sfcnUPtrs[0] = &multi_gadget_B.BehaviorMG_o5;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &multi_gadget_B.ToBits_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &multi_gadget_B.ToBits_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &multi_gadget_B.ToBits_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &multi_gadget_B.ToBits_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &multi_gadget_B.ToBits_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &multi_gadget_B.ToBits_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &multi_gadget_B.ToBits_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &multi_gadget_B.ToBits_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts, "multi_gadget/DeviceOutput/ToBits");
      ssSetRTModel(rts,multi_gadget_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      Byte2Bits(rts);
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
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 0);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortConnected(rts, 6, 0);
      _ssSetOutputPortConnected(rts, 7, 0);
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

    /* Level2 S-Function Block: multi_gadget/<S2>/PCI-6025E DO (donipcie) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[12]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[12]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn12.UPtrs0;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn12.UPtrs1;
          sfcnUPtrs[0] = &multi_gadget_B.ToBits_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn12.UPtrs2;
          sfcnUPtrs[0] = &multi_gadget_B.BehaviorMG_o4;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &multi_gadget_rtM->NonInlinedSFcns.Sfcn12.UPtrs3;
          sfcnUPtrs[0] = &multi_gadget_B.BehaviorMG_o3;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E DO");
      ssSetPath(rts, "multi_gadget/DeviceOutput/PCI-6025E DO");
      ssSetRTModel(rts,multi_gadget_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&multi_gadget_P.PCI6025EDO_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&multi_gadget_P.PCI6025EDO_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&multi_gadget_P.PCI6025EDO_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&multi_gadget_P.PCI6025EDO_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&multi_gadget_P.PCI6025EDO_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&multi_gadget_P.PCI6025EDO_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&multi_gadget_P.PCI6025EDO_P7_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &multi_gadget_DWork.PCI6025EDO_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn12.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &multi_gadget_DWork.PCI6025EDO_IWORK[0]);
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
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }

    /* Level2 S-Function Block: multi_gadget/<S7>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = multi_gadget_rtM->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = multi_gadget_rtM->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = multi_gadget_rtM->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = multi_gadget_rtM->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &multi_gadget_rtM->NonInlinedSFcns.blkInfo2[13]);
        ssSetRTWSfcnInfo(rts, multi_gadget_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &multi_gadget_rtM->NonInlinedSFcns.methods2[13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn13.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, multi_gadget_B.RateTransition);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 112);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "multi_gadget/UDPXmit/Send");
      ssSetRTModel(rts,multi_gadget_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&multi_gadget_P.Send_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&multi_gadget_P.Send_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&multi_gadget_P.Send_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&multi_gadget_P.Send_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &multi_gadget_DWork.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &multi_gadget_DWork.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &multi_gadget_rtM->NonInlinedSFcns.Sfcn13.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &multi_gadget_DWork.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &multi_gadget_DWork.Send_PWORK);
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

  multi_gadget_PrevZCSigState.SampleandHold.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
  multi_gadget_PrevZCSigState.SampleandHold_m.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void multi_gadget_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/PCI-6025E DI' (dinipcie) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Behavior MG' (mastercon_mg) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PCI-6025E DO' (donipcie) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S7>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<Root>/WordSbs' */

  /* Level2 S-Function Block: '<S9>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/Port A' (dopci8255) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/SerialConverter' (serPos) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/ToBits1' (Byte2Bits) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S9>/Port B' (dopci8255) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for iterator system: '<S9>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S14>/xPC Target  Time ' (xpctimeinfo) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S14>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[1];
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
  multi_gadget_output(tid);
}

void MdlUpdate(int_T tid)
{
  multi_gadget_update(tid);
}

void MdlInitializeSizes(void)
{
  multi_gadget_rtM->Sizes.numContStates = (0);/* Number of continuous states */
  multi_gadget_rtM->Sizes.numY = (0);  /* Number of model outputs */
  multi_gadget_rtM->Sizes.numU = (0);  /* Number of model inputs */
  multi_gadget_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  multi_gadget_rtM->Sizes.numSampTimes = (3);/* Number of sample times */
  multi_gadget_rtM->Sizes.numBlocks = (66);/* Number of blocks */
  multi_gadget_rtM->Sizes.numBlockIO = (69);/* Number of block outputs */
  multi_gadget_rtM->Sizes.numBlockPrms = (370);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Level2 S-Function Block: '<Root>/Behavior MG' (mastercon_mg) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[10];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<Root>/PCI-6025E DI' (dinipcie) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S1>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S2>/PCI-6025E DO' (donipcie) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S3>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior MG/p9/s1"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior MG/p9/s2"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior MG/p9/s3"));
        rl32eAddSignal(7, rl32eGetSignalNo("Behavior MG/p9/s4"));
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior MG/p9/s1"),
          " Gadget 1: %6.4f");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior MG/p9/s2"),
          " Gadget 2: %6.4f");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior MG/p9/s3"),
          " Gadget 3: %6.4f");
        rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Behavior MG/p9/s4"),
          " Gadget 4: %6.4f");
        rl32eSetScope(7, 4, 10);
        rl32eSetScope(7, 40, 0);
        rl32eSetScope(7, 7, 10);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo("Behavior MG/p9/s1"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 10, 0);
        rl32eSetTargetScope(7, 1, 0.0);
        rl32eSetTargetScope(7, 11, -10.0);
        rl32eSetTargetScope(7, 10, 10.0);
        xpceScopeAcqOK(7, &multi_gadget_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior MG/p6/s1"));
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior MG/p6/s2"));
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior MG/p6/s3"));
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior MG/p6/s4"));
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior MG/p6/s1"),
          "%6.0f State");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior MG/p6/s2"),
          "%6.0f Rewards");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior MG/p6/s3"),
          "%6.0f Aborts");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior MG/p6/s4"),
          "%6.0f Failures");
        rl32eSetScope(1, 4, 10);
        rl32eSetScope(1, 40, 0);
        rl32eSetScope(1, 7, 10);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Behavior MG/p6/s1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 10, 0);
        rl32eSetTargetScope(1, 1, 0.0);
        rl32eSetTargetScope(1, 11, -10.0);
        rl32eSetTargetScope(1, 10, 10.0);
        xpceScopeAcqOK(1, &multi_gadget_DWork.SFunction_IWORK_k.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S6>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("CursorPos/Add1"));
        rl32eAddSignal(2, rl32eGetSignalNo("CursorPos/Add"));
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("CursorPos/Add1")," %6.6f X");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("CursorPos/Add")," %6.6f Y");
        rl32eSetScope(2, 4, 10);
        rl32eSetScope(2, 40, 0);
        rl32eSetScope(2, 7, 10);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("CursorPos/Add1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 10, 0);
        rl32eSetTargetScope(2, 1, 0.0);
        rl32eSetTargetScope(2, 11, -10.0);
        rl32eSetTargetScope(2, 10, 10.0);
        xpceScopeAcqOK(2, &multi_gadget_DWork.SFunction_IWORK_b.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Level2 S-Function Block: '<S7>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[13];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S8>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(5)) == 0) {
      if ((i = rl32eDefScope(5,2)) != 0) {
        printf("Error creating scope 5\n");
      } else {
        rl32eAddSignal(5, rl32eGetSignalNo("Behavior MG/p10/s1"));
        rl32eAddSignal(5, rl32eGetSignalNo("Behavior MG/p10/s2"));
        rl32eAddSignal(5, rl32eGetSignalNo("Behavior MG/p10/s3"));
        rl32eAddSignal(5, rl32eGetSignalNo("Behavior MG/p10/s4"));
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Behavior MG/p10/s1"),
          "%6.0f major");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Behavior MG/p10/s2"),
          "%6.0f minor");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Behavior MG/p10/s3"),
          "%6.0f revision");
        rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Behavior MG/p10/s4"),
          "%6.0f build");
        rl32eSetScope(5, 4, 10);
        rl32eSetScope(5, 40, 0);
        rl32eSetScope(5, 7, 10);
        rl32eSetScope(5, 0, 0);
        rl32eSetScope(5, 3, rl32eGetSignalNo("Behavior MG/p10/s1"));
        rl32eSetScope(5, 1, 0.0);
        rl32eSetScope(5, 2, 0);
        rl32eSetScope(5, 10, 0);
        rl32eSetTargetScope(5, 1, 0.0);
        rl32eSetTargetScope(5, 11, -10.0);
        rl32eSetTargetScope(5, 10, 10.0);
        xpceScopeAcqOK(5, &multi_gadget_DWork.SFunction_IWORK_b4.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(5);
    }
  }

  /* S-Function Block: <S10>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("CursorPos/PCI-6025E AD/p1"));
        rl32eAddSignal(4, rl32eGetSignalNo("CursorPos/PCI-6025E AD/p2"));
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("CursorPos/PCI-6025E AD/p1"),
          " %6.6f Raw 1");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo("CursorPos/PCI-6025E AD/p2"),
          " %6.6f Raw 2");
        rl32eSetScope(4, 4, 10);
        rl32eSetScope(4, 40, 0);
        rl32eSetScope(4, 7, 10);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("CursorPos/PCI-6025E AD/p1"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 10, 0);
        rl32eSetTargetScope(4, 1, 0.0);
        rl32eSetTargetScope(4, 11, -10.0);
        rl32eSetTargetScope(4, 10, 10.0);
        xpceScopeAcqOK(4, &multi_gadget_DWork.SFunction_IWORK_m.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  /*trigger Subsystem Block: '<S12>/Sample and Hold' */
  multi_gadge_SampleandHold_Start(&multi_gadget_B.SampleandHold,
    (rtP_SampleandHold_multi_gadget *) &multi_gadget_P.SampleandHold);

  /* UniformRandomNumber Block: '<S4>/Uniform Random Number' */
  {
    uint32_T *RandSeed = (uint32_T *)
      &multi_gadget_DWork.UniformRandomNumber_IWORK.RandSeed;
    uint32_T r, t;
    *RandSeed = (uint32_T)multi_gadget_P.UniformRandomNumber_Seed;
    r = *RandSeed >> 16;
    t = *RandSeed & RT_BIT16;
    *RandSeed = ((*RandSeed - (r << 16) - t) << 16) + t + r;
    if (*RandSeed < 1) {
      *RandSeed = SEED0;
    }

    if (*RandSeed > MAXSEED) {
      *RandSeed = MAXSEED;
    }

    multi_gadget_DWork.UniformRandomNumber_RWORK.NextOutput
      = rt_Urand(RandSeed++) * (multi_gadget_P.UniformRandomNumber_Max -
      multi_gadget_P.UniformRandomNumber_Min) +
      multi_gadget_P.UniformRandomNumber_Min;
  }

  /*trigger Subsystem Block: '<S4>/Sample and Hold' */
  multi_gadge_SampleandHold_Start(&multi_gadget_B.SampleandHold_m,
    (rtP_SampleandHold_multi_gadget *) &multi_gadget_P.SampleandHold_m);

  /* Start for iterator system: '<Root>/WordSbs' */

  /* Level2 S-Function Block: '<S9>/Port A' (dopci8255) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S9>/Port B' (dopci8255) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Start for iterator system: '<S9>/While Iterator Subsystem' */

  /* Level2 S-Function Block: '<S14>/PCI-6025E ' (donipcie) */
  {
    SimStruct *rts = multi_gadget_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  multi_gadget_DWork.SampleandHold_m.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  multi_gadget_DWork.SampleandHold.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;

  /* user code (Start function Trailer) */
  rl32eSetScope(7, 8, 1);
  rl32eSetScope(1, 8, 1);
  rl32eSetScope(2, 8, 1);
  rl32eSetScope(5, 8, 1);
  rl32eSetScope(4, 8, 1);
  MdlInitialize();
}

rtModel_multi_gadget *multi_gadget(void)
{
  multi_gadget_initialize(1);
  return multi_gadget_rtM;
}

void MdlTerminate(void)
{
  multi_gadget_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
