/*
 * ball_drop.c
 *
 * Real-Time Workshop code generation for Simulink model "ball_drop.mdl".
 *
 * Model Version              : 1.95
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 14:00:48 2010
 */

#include "rt_logging_mmi.h"
#include "ball_drop_capi.h"
#include "ball_drop.h"
#include "ball_drop_private.h"
#include <stdio.h>
#include "ball_drop_dt.h"

/* Block signals (auto storage) */
BlockIO_ball_drop ball_drop_B;

/* Block states (auto storage) */
D_Work_ball_drop ball_drop_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_ball_drop ball_drop_PrevZCSigState;

/* Real-time model */
rtModel_ball_drop ball_drop_rtM_;
rtModel_ball_drop *ball_drop_rtM = &ball_drop_rtM_;
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
  if (++ball_drop_rtM->Timing.TaskCounters.TID[2] == 20) {/* Sample time: [0.02s, 0.0s] */
    ball_drop_rtM->Timing.TaskCounters.TID[2] = 0;
  }

  ball_drop_rtM->Timing.sampleHits[2] = (ball_drop_rtM->Timing.TaskCounters.TID
    [2] == 0);
}

/* Start for trigger system:
 *   '<S3>/Sample and Hold'
 *   '<S11>/Sample and Hold'
 */
void ball_drop_SampleandHold_Start(rtB_SampleandHold_ball_drop *localB,
  rtP_SampleandHold_ball_drop *localP)
{
  /* virtual outports code */

  /* (Virtual) Outport Block: '<S10>/ ' */
  localB->In = localP->_Y0;
}

/* Output and update for trigger system:
 *   '<S3>/Sample and Hold'
 *   '<S11>/Sample and Hold'
 */
void ball_drop_SampleandHold(real_T rtu_0, real_T rtu_1,
  rtB_SampleandHold_ball_drop *localB, rtDW_SampleandHold_ball_drop *localDW,
  rtZCE_SampleandHold_ball_drop *localZCE)
{
  {
    ZCEventType trigEvent;
    trigEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&(localZCE->SampleandHold_ZCE),
                         rtu_0);

    /* conditionally execute */
    if (trigEvent != NO_ZCEVENT) {
      /* Inport: '<S10>/In' */
      localB->In = rtu_1;
      localDW->SampleandHold_SubsysRanBC = SUBSYS_RAN_BC_ONE_SHOT;
    }
  }
}

/* Model output function */
void ball_drop_output(int_T tid)
{
  /* Reset subsysRan breadcrumbs */
  srClearBC(ball_drop_DWork.SampleandHold_i.SampleandHold_SubsysRanBC);
  srClearBC(ball_drop_DWork.SampleandHold.SampleandHold_SubsysRanBC);

  {                                    /* Sample time: [0.001s, 0.0s] */
    /* Level2 S-Function Block: '<Root>/PCI-6025E DI' (dinipcie) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S1>/PCI-6025E AD' (adnipcie) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant1'
     */
    if (ball_drop_B.PCI6025EAD_o1 >= ball_drop_P.Switch_Threshold) {
      ball_drop_B.Switch = ball_drop_P.Constant_Value;
    } else {
      ball_drop_B.Switch = ball_drop_P.Constant1_Value;
    }

    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S1>/Constant1'
     */
    if (ball_drop_B.PCI6025EAD_o2 >= ball_drop_P.Switch1_Threshold) {
      ball_drop_B.Switch1 = ball_drop_P.Constant1_Value;
    } else {
      ball_drop_B.Switch1 = ball_drop_P.Constant_Value;
    }

    /* Level2 S-Function Block: '<Root>/Behavior BD' (mastercon_bd) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S2>/ToBits' (Byte2Bits) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S2>/PCI-6025E DO' (donipcie) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }
  }

  /* Clock Block: '<S11>/Clock'
   */
  ball_drop_B.Clock = ball_drop_rtM->Timing.t[0];

  {                                    /* Sample time: [0.001s, 0.0s] */
    /* SignalConversion: '<S11>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    ball_drop_B.HiddenBuf_InsertedFor_Sampleand = ball_drop_B.BehaviorBD_o1;
  }

  /* SubSystem Block: '<S11>/Sample and Hold'
   */
  ball_drop_SampleandHold(ball_drop_B.HiddenBuf_InsertedFor_Sampleand,
    ball_drop_B.Clock, &ball_drop_B.SampleandHold,
    &ball_drop_DWork.SampleandHold, &ball_drop_PrevZCSigState.SampleandHold);

  /* Sum: '<S11>/Sum' */
  ball_drop_B.Sum = ball_drop_B.Clock - ball_drop_B.SampleandHold.In;

  {                                    /* Sample time: [0.001s, 0.0s] */
    /* UniformRandomNumber Block: '<S3>/Uniform Random Number'
     */
    ball_drop_B.UniformRandomNumber =
      ball_drop_DWork.UniformRandomNumber_RWORK.NextOutput;

    /* RelationalOperator: '<S3>/Relational Operator' incorporates:
     *  Constant: '<S3>/JackpotChance'
     */
    ball_drop_B.RelationalOperator = (ball_drop_B.UniformRandomNumber >
      ball_drop_P.JackpotChance_Value);

    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/RewardJackpot'
     *  Constant: '<S3>/RewardTime'
     */
    if (ball_drop_B.RelationalOperator) {
      ball_drop_B.Switch_h = ball_drop_P.RewardTime_Value;
    } else {
      ball_drop_B.Switch_h = ball_drop_P.RewardJackpot_Value;
    }

    /* SignalConversion: '<S3>/HiddenBuf_InsertedFor_Sample and Hold_at_inport_1' */
    ball_drop_B.HiddenBuf_InsertedFor_Samplea_c = ball_drop_B.BehaviorBD_o1;
  }

  /* SubSystem Block: '<S3>/Sample and Hold'
   */
  ball_drop_SampleandHold(ball_drop_B.HiddenBuf_InsertedFor_Samplea_c,
    ball_drop_B.Switch_h, &ball_drop_B.SampleandHold_i,
    &ball_drop_DWork.SampleandHold_i, &ball_drop_PrevZCSigState.SampleandHold_i);

  /* RelationalOperator: '<S11>/Relational Operator' */
  ball_drop_B.RelationalOperator_c = (ball_drop_B.Sum <
    ball_drop_B.SampleandHold_i.In);

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  ball_drop_B.DataTypeConversion = (real_T)ball_drop_B.RelationalOperator_c;

  {                                    /* Sample time: [0.001s, 0.0s] */
    /* Level2 S-Function Block: '<Root>/PCI-6025E DO' (donipcie) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* ok to acquire for <S4>/S-Function */
    ball_drop_DWork.SFunction_IWORK.AcquireOK = 1;

    /* ok to acquire for <S5>/S-Function */
    ball_drop_DWork.SFunction_IWORK_d.AcquireOK = 1;

    /* Pack: <S6>/Pack */
    (void) memcpy(ball_drop_B.Pack,&ball_drop_P.Pos_Value,
                  8);
    (void) memcpy(&ball_drop_B.Pack[8],&ball_drop_P.Pos_Value,
                  8);
    (void) memcpy(&ball_drop_B.Pack[16],&ball_drop_B.BehaviorBD_o8[0],
                  8);
    (void) memcpy(&ball_drop_B.Pack[24],&ball_drop_B.BehaviorBD_o8[1],
                  8);
    (void) memcpy(&ball_drop_B.Pack[32],&ball_drop_B.BehaviorBD_o8[2],
                  8);
    (void) memcpy(&ball_drop_B.Pack[40],&ball_drop_B.BehaviorBD_o8[3],
                  8);
    (void) memcpy(&ball_drop_B.Pack[48],&ball_drop_B.BehaviorBD_o8[4],
                  8);
    (void) memcpy(&ball_drop_B.Pack[56],&ball_drop_B.BehaviorBD_o8[5],
                  8);
    (void) memcpy(&ball_drop_B.Pack[64],&ball_drop_B.BehaviorBD_o8[6],
                  8);
    (void) memcpy(&ball_drop_B.Pack[72],&ball_drop_B.BehaviorBD_o8[7],
                  8);
    (void) memcpy(&ball_drop_B.Pack[80],&ball_drop_B.BehaviorBD_o8[8],
                  8);
    (void) memcpy(&ball_drop_B.Pack[88],&ball_drop_B.BehaviorBD_o8[9],
                  8);
    (void) memcpy(&ball_drop_B.Pack[96],&ball_drop_B.BehaviorBD_o7[0],
                  8);
    (void) memcpy(&ball_drop_B.Pack[104],&ball_drop_B.BehaviorBD_o7[1],
                  8);
  }

  {
    int32_T i;

    /* RateTransition: '<S6>/Rate Transition' */
    if (1 && ball_drop_rtM->Timing.TaskCounters.TID[2] == 0) {
      for (i = 0; i < 112; i++) {
        ball_drop_B.RateTransition[i] = ball_drop_B.Pack[i];
      }
    }
  }

  if (ball_drop_rtM->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.02s, 0.0s] */
    /* Level2 S-Function Block: '<S6>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[6];
      sfcnOutputs(rts, 2);
    }
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    /* ok to acquire for <S7>/S-Function */
    ball_drop_DWork.SFunction_IWORK_j.AcquireOK = 1;

    /* Level2 S-Function Block: '<S8>/ToBits' (Byte2Bits) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S8>/Port A' (dopci8255) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* ok to acquire for <S9>/S-Function */
    ball_drop_DWork.SFunction_IWORK_i.AcquireOK = 1;
  }

  UNUSED_PARAMETER(tid);
}

/* Model update function */
void ball_drop_update(int_T tid)
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    /* Level2 S-Function Block: '<Root>/Behavior BD' (mastercon_bd) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[2];
      sfcnUpdate(rts, 1);
      if (ssGetErrorStatus(rts) != NULL)
        return;
    }

    /* UniformRandomNumber Block: '<S3>/Uniform Random Number' */
    ball_drop_DWork.UniformRandomNumber_RWORK.NextOutput = rt_Urand((uint32_T *)
      &ball_drop_DWork.UniformRandomNumber_IWORK.RandSeed) *
      (ball_drop_P.UniformRandomNumber_Max - ball_drop_P.UniformRandomNumber_Min)
      + ball_drop_P.UniformRandomNumber_Min;
  }

  /* Update absolute time for base rate */
  if (!(++ball_drop_rtM->Timing.clockTick0))
    ++ball_drop_rtM->Timing.clockTickH0;
  ball_drop_rtM->Timing.t[0] = ball_drop_rtM->Timing.clockTick0 *
    ball_drop_rtM->Timing.stepSize0 + ball_drop_rtM->Timing.clockTickH0 *
    ball_drop_rtM->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    if (!(++ball_drop_rtM->Timing.clockTick1))
      ++ball_drop_rtM->Timing.clockTickH1;
    ball_drop_rtM->Timing.t[1] = ball_drop_rtM->Timing.clockTick1 *
      ball_drop_rtM->Timing.stepSize1 + ball_drop_rtM->Timing.clockTickH1 *
      ball_drop_rtM->Timing.stepSize1 * 4294967296.0;
  }

  if (ball_drop_rtM->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    if (!(++ball_drop_rtM->Timing.clockTick2))
      ++ball_drop_rtM->Timing.clockTickH2;
    ball_drop_rtM->Timing.t[2] = ball_drop_rtM->Timing.clockTick2 *
      ball_drop_rtM->Timing.stepSize2 + ball_drop_rtM->Timing.clockTickH2 *
      ball_drop_rtM->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void ball_drop_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */
  /* initialize real-time model */
  (void) memset((char_T *)ball_drop_rtM,0,
                sizeof(rtModel_ball_drop));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ball_drop_rtM->solverInfo,
                          &ball_drop_rtM->Timing.simTimeStep);
    rtsiSetTPtr(&ball_drop_rtM->solverInfo, &rtmGetTPtr(ball_drop_rtM));
    rtsiSetStepSizePtr(&ball_drop_rtM->solverInfo,
                       &ball_drop_rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ball_drop_rtM->solverInfo, (&rtmGetErrorStatus
      (ball_drop_rtM)));
    rtsiSetRTModelPtr(&ball_drop_rtM->solverInfo, ball_drop_rtM);
  }

  rtsiSetSimTimeStep(&ball_drop_rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&ball_drop_rtM->solverInfo,"FixedStepDiscrete");
  ball_drop_rtM->solverInfoPtr = (&ball_drop_rtM->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ball_drop_rtM->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    ball_drop_rtM->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ball_drop_rtM->Timing.sampleTimes = (&ball_drop_rtM->Timing.sampleTimesArray
      [0]);
    ball_drop_rtM->Timing.offsetTimes = (&ball_drop_rtM->Timing.offsetTimesArray
      [0]);

    /* task periods */
    ball_drop_rtM->Timing.sampleTimes[0] = (0.0);
    ball_drop_rtM->Timing.sampleTimes[1] = (0.001);
    ball_drop_rtM->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    ball_drop_rtM->Timing.offsetTimes[0] = (0.0);
    ball_drop_rtM->Timing.offsetTimes[1] = (0.0);
    ball_drop_rtM->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(ball_drop_rtM, &ball_drop_rtM->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ball_drop_rtM->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    ball_drop_rtM->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ball_drop_rtM, -1);
  ball_drop_rtM->Timing.stepSize0 = 0.001;
  ball_drop_rtM->Timing.stepSize1 = 0.001;
  ball_drop_rtM->Timing.stepSize2 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ball_drop_rtM->rtwLogInfo = &rt_DataLoggingInfo;
    rtliSetLogFormat(ball_drop_rtM->rtwLogInfo, 0);
    rtliSetLogMaxRows(ball_drop_rtM->rtwLogInfo, 1000);
    rtliSetLogDecimation(ball_drop_rtM->rtwLogInfo, 1);
    rtliSetLogVarNameModifier(ball_drop_rtM->rtwLogInfo, "rt_");
    rtliSetLogT(ball_drop_rtM->rtwLogInfo, "tout");
    rtliSetLogX(ball_drop_rtM->rtwLogInfo, "");
    rtliSetLogXFinal(ball_drop_rtM->rtwLogInfo, "");
    rtliSetSigLog(ball_drop_rtM->rtwLogInfo, "");
    rtliSetLogXSignalInfo(ball_drop_rtM->rtwLogInfo, NULL);
    rtliSetLogXSignalPtrs(ball_drop_rtM->rtwLogInfo, NULL);
    rtliSetLogY(ball_drop_rtM->rtwLogInfo, "");
    rtliSetLogYSignalInfo(ball_drop_rtM->rtwLogInfo, NULL);
    rtliSetLogYSignalPtrs(ball_drop_rtM->rtwLogInfo, NULL);
  }

  /* external mode info */
  ball_drop_rtM->Sizes.checksums[0] = (3348203731U);
  ball_drop_rtM->Sizes.checksums[1] = (2436526730U);
  ball_drop_rtM->Sizes.checksums[2] = (2958427952U);
  ball_drop_rtM->Sizes.checksums[3] = (3764359373U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    ball_drop_rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &ball_drop_DWork.SampleandHold_i.SampleandHold_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &ball_drop_DWork.SampleandHold.SampleandHold_SubsysRanBC;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &ball_drop_rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, ball_drop_rtM->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(ball_drop_rtM));
  }

  ball_drop_rtM->solverInfoPtr = (&ball_drop_rtM->solverInfo);
  ball_drop_rtM->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&ball_drop_rtM->solverInfo, 0.001);
  rtsiSetSolverMode(&ball_drop_rtM->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ball_drop_rtM->ModelData.blockIO = ((void *) &ball_drop_B);
  (void) memset(((void *) &ball_drop_B),0,
                sizeof(BlockIO_ball_drop));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&ball_drop_B.PCI6025EDI);
    for (i = 0; i < 54; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }

    ((real_T*)&ball_drop_B.SampleandHold.In)[0] = 0.0;
    ((real_T*)&ball_drop_B.SampleandHold_i.In)[0] = 0.0;
  }

  /* parameters */
  ball_drop_rtM->ModelData.defaultParam = ((real_T *) &ball_drop_P);

  /* states (dwork) */
  ball_drop_rtM->Work.dwork = ((void *) &ball_drop_DWork);
  (void) memset((char_T *) &ball_drop_DWork,0,
                sizeof(D_Work_ball_drop));

  {
    int_T i;
    real_T *dwork_ptr = (real_T *) &ball_drop_DWork.BehaviorBD_DSTATE;
    for (i = 0; i < 76; i++) {
      dwork_ptr[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    ball_drop_rtM->SpecialInfo.mappingInfo = (&dtInfo);
    ball_drop_rtM->SpecialInfo.xpcData = ((void*) &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  ball_drop_InitializeDataMapInfo(ball_drop_rtM);

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &ball_drop_rtM->NonInlinedSFcns.sfcnInfo;
    ball_drop_rtM->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(ball_drop_rtM)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &ball_drop_rtM->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(ball_drop_rtM));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(ball_drop_rtM));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(ball_drop_rtM));
    rtssSetStepSizePtr(sfcnInfo, &ball_drop_rtM->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(ball_drop_rtM));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &ball_drop_rtM->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &ball_drop_rtM->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &ball_drop_rtM->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &ball_drop_rtM->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &ball_drop_rtM->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &ball_drop_rtM->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &ball_drop_rtM->solverInfoPtr);
  }

  ball_drop_rtM->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&ball_drop_rtM->NonInlinedSFcns.childSFunctions[0],0,
                  9*sizeof(SimStruct));
    ball_drop_rtM->childSfunctions =
      (&ball_drop_rtM->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        ball_drop_rtM->childSfunctions[i] =
          (&ball_drop_rtM->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: ball_drop/<Root>/PCI-6025E DI (dinipcie) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = ball_drop_rtM->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = ball_drop_rtM->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = ball_drop_rtM->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ball_drop_rtM->NonInlinedSFcns.blkInfo2[0]);
        ssSetRTWSfcnInfo(rts, ball_drop_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ball_drop_rtM->NonInlinedSFcns.methods2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &ball_drop_B.PCI6025EDI));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E DI");
      ssSetPath(rts, "ball_drop/PCI-6025E DI");
      ssSetRTModel(rts,ball_drop_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&ball_drop_P.PCI6025EDI_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&ball_drop_P.PCI6025EDI_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&ball_drop_P.PCI6025EDI_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&ball_drop_P.PCI6025EDI_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&ball_drop_P.PCI6025EDI_P5_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &ball_drop_DWork.PCI6025EDI_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn0.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ball_drop_DWork.PCI6025EDI_IWORK[0]);
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

    /* Level2 S-Function Block: ball_drop/<S1>/PCI-6025E AD (adnipcie) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = ball_drop_rtM->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = ball_drop_rtM->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = ball_drop_rtM->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ball_drop_rtM->NonInlinedSFcns.blkInfo2[1]);
        ssSetRTWSfcnInfo(rts, ball_drop_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ball_drop_rtM->NonInlinedSFcns.methods2[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &ball_drop_B.PCI6025EAD_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &ball_drop_B.PCI6025EAD_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E AD");
      ssSetPath(rts, "ball_drop/Ball sensors/PCI-6025E AD");
      ssSetRTModel(rts,ball_drop_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 6);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&ball_drop_P.PCI6025EAD_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&ball_drop_P.PCI6025EAD_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&ball_drop_P.PCI6025EAD_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&ball_drop_P.PCI6025EAD_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&ball_drop_P.PCI6025EAD_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&ball_drop_P.PCI6025EAD_P6_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &ball_drop_DWork.PCI6025EAD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &ball_drop_DWork.PCI6025EAD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn1.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 64);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ball_drop_DWork.PCI6025EAD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 66);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &ball_drop_DWork.PCI6025EAD_IWORK[0]);
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

    /* Level2 S-Function Block: ball_drop/<Root>/Behavior BD (mastercon_bd) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = ball_drop_rtM->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = ball_drop_rtM->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = ball_drop_rtM->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ball_drop_rtM->NonInlinedSFcns.blkInfo2[2]);
        ssSetRTWSfcnInfo(rts, ball_drop_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ball_drop_rtM->NonInlinedSFcns.methods2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &ball_drop_B.PCI6025EDI;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = &ball_drop_B.Switch;
          sfcnUPtrs[1] = &ball_drop_B.Switch1;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 9);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &ball_drop_B.BehaviorBD_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &ball_drop_B.BehaviorBD_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &ball_drop_B.BehaviorBD_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &ball_drop_B.BehaviorBD_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &ball_drop_B.BehaviorBD_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 5);
          ssSetOutputPortSignal(rts, 5, ((real_T *) ball_drop_B.BehaviorBD_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 2);
          ssSetOutputPortSignal(rts, 6, ((real_T *) ball_drop_B.BehaviorBD_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 10);
          ssSetOutputPortSignal(rts, 7, ((real_T *) ball_drop_B.BehaviorBD_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 4);
          ssSetOutputPortSignal(rts, 8, ((real_T *) ball_drop_B.BehaviorBD_o9));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *) &ball_drop_DWork.BehaviorBD_DSTATE);

      /* path info */
      ssSetModelName(rts, "Behavior BD");
      ssSetPath(rts, "ball_drop/Behavior BD");
      ssSetRTModel(rts,ball_drop_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&ball_drop_P.BehaviorBD_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&ball_drop_P.BehaviorBD_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&ball_drop_P.BehaviorBD_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&ball_drop_P.BehaviorBD_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&ball_drop_P.BehaviorBD_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&ball_drop_P.BehaviorBD_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&ball_drop_P.BehaviorBD_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&ball_drop_P.BehaviorBD_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&ball_drop_P.BehaviorBD_P9_Size[0]);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &ball_drop_DWork.BehaviorBD_RWORK[0]);
      ssSetIWork(rts, (int_T *) &ball_drop_DWork.BehaviorBD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn2.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 3);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 10);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ball_drop_DWork.BehaviorBD_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 6);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &ball_drop_DWork.BehaviorBD_IWORK[0]);

        /* DSTATE */
        ssSetDWorkWidth(rts, 2, 1);
        ssSetDWorkDataType(rts, 2,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWorkUsedAsDState(rts, 2, 1);
        ssSetDWork(rts, 2, &ball_drop_DWork.BehaviorBD_DSTATE);
      }

      /* registration */
      mastercon_bd(rts);
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
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: ball_drop/<S2>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = ball_drop_rtM->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = ball_drop_rtM->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = ball_drop_rtM->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ball_drop_rtM->NonInlinedSFcns.blkInfo2[3]);
        ssSetRTWSfcnInfo(rts, ball_drop_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ball_drop_rtM->NonInlinedSFcns.methods2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &ball_drop_B.BehaviorBD_o5;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &ball_drop_B.ToBits_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &ball_drop_B.ToBits_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &ball_drop_B.ToBits_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &ball_drop_B.ToBits_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &ball_drop_B.ToBits_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &ball_drop_B.ToBits_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &ball_drop_B.ToBits_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &ball_drop_B.ToBits_o8));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts, "ball_drop/DeviceOutput/ToBits");
      ssSetRTModel(rts,ball_drop_rtM);
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

    /* Level2 S-Function Block: ball_drop/<S2>/PCI-6025E DO (donipcie) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = ball_drop_rtM->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = ball_drop_rtM->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = ball_drop_rtM->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ball_drop_rtM->NonInlinedSFcns.blkInfo2[4]);
        ssSetRTWSfcnInfo(rts, ball_drop_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ball_drop_rtM->NonInlinedSFcns.methods2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &ball_drop_B.ToBits_o1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &ball_drop_B.ToBits_o2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn4.UPtrs2;
          sfcnUPtrs[0] = &ball_drop_B.BehaviorBD_o4;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn4.UPtrs3;
          sfcnUPtrs[0] = &ball_drop_B.BehaviorBD_o3;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E DO");
      ssSetPath(rts, "ball_drop/DeviceOutput/PCI-6025E DO");
      ssSetRTModel(rts,ball_drop_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&ball_drop_P.PCI6025EDO_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&ball_drop_P.PCI6025EDO_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&ball_drop_P.PCI6025EDO_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&ball_drop_P.PCI6025EDO_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&ball_drop_P.PCI6025EDO_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&ball_drop_P.PCI6025EDO_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&ball_drop_P.PCI6025EDO_P7_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &ball_drop_DWork.PCI6025EDO_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn4.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ball_drop_DWork.PCI6025EDO_IWORK[0]);
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

    /* Level2 S-Function Block: ball_drop/<Root>/PCI-6025E DO (donipcie) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = ball_drop_rtM->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = ball_drop_rtM->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = ball_drop_rtM->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ball_drop_rtM->NonInlinedSFcns.blkInfo2[5]);
        ssSetRTWSfcnInfo(rts, ball_drop_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ball_drop_rtM->NonInlinedSFcns.methods2[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &ball_drop_B.DataTypeConversion;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6025E DO");
      ssSetPath(rts, "ball_drop/PCI-6025E DO");
      ssSetRTModel(rts,ball_drop_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&ball_drop_P.PCI6025EDO_P1_Size_h[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&ball_drop_P.PCI6025EDO_P2_Size_f[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&ball_drop_P.PCI6025EDO_P3_Size_n[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&ball_drop_P.PCI6025EDO_P4_Size_j[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&ball_drop_P.PCI6025EDO_P5_Size_p[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&ball_drop_P.PCI6025EDO_P6_Size_n[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&ball_drop_P.PCI6025EDO_P7_Size_p[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &ball_drop_DWork.PCI6025EDO_IWORK_a[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn5.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ball_drop_DWork.PCI6025EDO_IWORK_a[0]);
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

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: ball_drop/<S6>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = ball_drop_rtM->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = ball_drop_rtM->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = ball_drop_rtM->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ball_drop_rtM->NonInlinedSFcns.blkInfo2[6]);
        ssSetRTWSfcnInfo(rts, ball_drop_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ball_drop_rtM->NonInlinedSFcns.methods2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, ball_drop_B.RateTransition);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 112);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "ball_drop/UDPXmit/Send");
      ssSetRTModel(rts,ball_drop_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&ball_drop_P.Send_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&ball_drop_P.Send_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&ball_drop_P.Send_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&ball_drop_P.Send_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &ball_drop_DWork.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &ball_drop_DWork.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn6.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ball_drop_DWork.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &ball_drop_DWork.Send_PWORK);
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

    /* Level2 S-Function Block: ball_drop/<S8>/ToBits (Byte2Bits) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = ball_drop_rtM->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = ball_drop_rtM->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = ball_drop_rtM->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ball_drop_rtM->NonInlinedSFcns.blkInfo2[7]);
        ssSetRTWSfcnInfo(rts, ball_drop_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ball_drop_rtM->NonInlinedSFcns.methods2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = &ball_drop_B.BehaviorBD_o2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &ball_drop_B.ToBits_o1_i));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &ball_drop_B.ToBits_o2_h));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &ball_drop_B.ToBits_o3_d));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &ball_drop_B.ToBits_o4_j));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &ball_drop_B.ToBits_o5_g));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &ball_drop_B.ToBits_o6_i));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((real_T *) &ball_drop_B.ToBits_o7_p));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((real_T *) &ball_drop_B.ToBits_o8_h));
        }
      }

      /* path info */
      ssSetModelName(rts, "ToBits");
      ssSetPath(rts, "ball_drop/WordSbs/ToBits");
      ssSetRTModel(rts,ball_drop_rtM);
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

    /* Level2 S-Function Block: ball_drop/<S8>/Port A (dopci8255) */
    {
      SimStruct *rts = ball_drop_rtM->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = ball_drop_rtM->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = ball_drop_rtM->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = ball_drop_rtM->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod,0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset,0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ball_drop_rtM->NonInlinedSFcns.blkInfo2[8]);
        ssSetRTWSfcnInfo(rts, ball_drop_rtM->sfcnInfo);
      }

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ball_drop_rtM->NonInlinedSFcns.methods2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 8);
        ssSetPortInfoForInputs(rts,
          &ball_drop_rtM->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = &ball_drop_B.ToBits_o1_i;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn8.UPtrs1;
          sfcnUPtrs[0] = &ball_drop_B.ToBits_o2_h;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn8.UPtrs2;
          sfcnUPtrs[0] = &ball_drop_B.ToBits_o3_d;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn8.UPtrs3;
          sfcnUPtrs[0] = &ball_drop_B.ToBits_o4_j;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }

        /* port 4 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn8.UPtrs4;
          sfcnUPtrs[0] = &ball_drop_B.ToBits_o5_g;
          ssSetInputPortSignalPtrs(rts, 4, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 4, 1);
          ssSetInputPortWidth(rts, 4, 1);
        }

        /* port 5 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn8.UPtrs5;
          sfcnUPtrs[0] = &ball_drop_B.ToBits_o6_i;
          ssSetInputPortSignalPtrs(rts, 5, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 5, 1);
          ssSetInputPortWidth(rts, 5, 1);
        }

        /* port 6 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn8.UPtrs6;
          sfcnUPtrs[0] = &ball_drop_B.ToBits_o7_p;
          ssSetInputPortSignalPtrs(rts, 6, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 6, 1);
          ssSetInputPortWidth(rts, 6, 1);
        }

        /* port 7 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ball_drop_rtM->NonInlinedSFcns.Sfcn8.UPtrs7;
          sfcnUPtrs[0] = &ball_drop_B.ToBits_o8_h;
          ssSetInputPortSignalPtrs(rts, 7, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 7, 1);
          ssSetInputPortWidth(rts, 7, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Port A");
      ssSetPath(rts, "ball_drop/WordSbs/Port A");
      ssSetRTModel(rts,ball_drop_rtM);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)&ball_drop_P.PortA_P1_Size[0]);
        ssSetSFcnParam(rts, 1, (mxArray*)&ball_drop_P.PortA_P2_Size[0]);
        ssSetSFcnParam(rts, 2, (mxArray*)&ball_drop_P.PortA_P3_Size[0]);
        ssSetSFcnParam(rts, 3, (mxArray*)&ball_drop_P.PortA_P4_Size[0]);
        ssSetSFcnParam(rts, 4, (mxArray*)&ball_drop_P.PortA_P5_Size[0]);
        ssSetSFcnParam(rts, 5, (mxArray*)&ball_drop_P.PortA_P6_Size[0]);
        ssSetSFcnParam(rts, 6, (mxArray*)&ball_drop_P.PortA_P7_Size[0]);
        ssSetSFcnParam(rts, 7, (mxArray*)&ball_drop_P.PortA_P8_Size[0]);
        ssSetSFcnParam(rts, 8, (mxArray*)&ball_drop_P.PortA_P9_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &ball_drop_DWork.PortA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &ball_drop_rtM->NonInlinedSFcns.Sfcn8.dWork;
        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &ball_drop_DWork.PortA_IWORK[0]);
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

  ball_drop_PrevZCSigState.SampleandHold.SampleandHold_ZCE = UNINITIALIZED_ZCSIG;
  ball_drop_PrevZCSigState.SampleandHold_i.SampleandHold_ZCE =
    UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void ball_drop_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/PCI-6025E DI' (dinipcie) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/Behavior BD' (mastercon_bd) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PCI-6025E DO' (donipcie) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/PCI-6025E DO' (donipcie) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S6>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/ToBits' (Byte2Bits) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S8>/Port A' (dopci8255) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[8];
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
  ball_drop_output(tid);
}

void MdlUpdate(int_T tid)
{
  ball_drop_update(tid);
}

void MdlInitializeSizes(void)
{
  ball_drop_rtM->Sizes.numContStates = (0);/* Number of continuous states */
  ball_drop_rtM->Sizes.numY = (0);     /* Number of model outputs */
  ball_drop_rtM->Sizes.numU = (0);     /* Number of model inputs */
  ball_drop_rtM->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ball_drop_rtM->Sizes.numSampTimes = (3);/* Number of sample times */
  ball_drop_rtM->Sizes.numBlocks = (37);/* Number of blocks */
  ball_drop_rtM->Sizes.numBlockIO = (43);/* Number of block outputs */
  ball_drop_rtM->Sizes.numBlockPrms = (197);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* Level2 S-Function Block: '<Root>/Behavior BD' (mastercon_bd) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[2];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }
}

void MdlStart(void)
{
  /* Level2 S-Function Block: '<Root>/PCI-6025E DI' (dinipcie) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S1>/PCI-6025E AD' (adnipcie) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* Level2 S-Function Block: '<S2>/PCI-6025E DO' (donipcie) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /*trigger Subsystem Block: '<S11>/Sample and Hold' */
  ball_drop_SampleandHold_Start(&ball_drop_B.SampleandHold,
    (rtP_SampleandHold_ball_drop *) &ball_drop_P.SampleandHold);

  /* UniformRandomNumber Block: '<S3>/Uniform Random Number' */
  {
    uint32_T *RandSeed = (uint32_T *)
      &ball_drop_DWork.UniformRandomNumber_IWORK.RandSeed;
    uint32_T r, t;
    *RandSeed = (uint32_T)ball_drop_P.UniformRandomNumber_Seed;
    r = *RandSeed >> 16;
    t = *RandSeed & RT_BIT16;
    *RandSeed = ((*RandSeed - (r << 16) - t) << 16) + t + r;
    if (*RandSeed < 1) {
      *RandSeed = SEED0;
    }

    if (*RandSeed > MAXSEED) {
      *RandSeed = MAXSEED;
    }

    ball_drop_DWork.UniformRandomNumber_RWORK.NextOutput
      = rt_Urand(RandSeed++) * (ball_drop_P.UniformRandomNumber_Max -
      ball_drop_P.UniformRandomNumber_Min) + ball_drop_P.UniformRandomNumber_Min;
  }

  /*trigger Subsystem Block: '<S3>/Sample and Hold' */
  ball_drop_SampleandHold_Start(&ball_drop_B.SampleandHold_i,
    (rtP_SampleandHold_ball_drop *) &ball_drop_P.SampleandHold_i);

  /* Level2 S-Function Block: '<Root>/PCI-6025E DO' (donipcie) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S4>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior BD/p6/s1"));
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior BD/p6/s2"));
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior BD/p6/s3"));
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior BD/p6/s4"));
        rl32eAddSignal(1, rl32eGetSignalNo("Behavior BD/p6/s5"));
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior BD/p6/s1"),
          "%6.0f State");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior BD/p6/s2"),
          "%6.0f Rewards");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior BD/p6/s3"),
          "%6.0f Aborts");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior BD/p6/s4"),
          "%6.0f Failures");
        rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Behavior BD/p6/s5"),
          "%6.0f Incompletes");
        rl32eSetScope(1, 4, 10);
        rl32eSetScope(1, 40, 0);
        rl32eSetScope(1, 7, 10);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("Behavior BD/p6/s1"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 10, 0);
        rl32eSetTargetScope(1, 1, 0.0);
        rl32eSetTargetScope(1, 11, -10.0);
        rl32eSetTargetScope(1, 10, 10.0);
        xpceScopeAcqOK(1, &ball_drop_DWork.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Ball sensors/Switch"));
        rl32eAddSignal(2, rl32eGetSignalNo("Ball sensors/Switch1"));
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("Ball sensors/Switch"),
          " %6.6f X");
        rl32eSetTargetScopeSigFt(2,rl32eGetSignalNo("Ball sensors/Switch1"),
          " %6.6f Y");
        rl32eSetScope(2, 4, 10);
        rl32eSetScope(2, 40, 0);
        rl32eSetScope(2, 7, 10);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Ball sensors/Switch"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 10, 0);
        rl32eSetTargetScope(2, 1, 0.0);
        rl32eSetTargetScope(2, 11, -10.0);
        rl32eSetTargetScope(2, 10, 10.0);
        xpceScopeAcqOK(2, &ball_drop_DWork.SFunction_IWORK_d.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Level2 S-Function Block: '<S6>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S7>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BD/p9/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BD/p9/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BD/p9/s3"));
        rl32eAddSignal(3, rl32eGetSignalNo("Behavior BD/p9/s4"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BD/p9/s1"),
          "%6.0f major");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BD/p9/s2"),
          "%6.0f minor");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BD/p9/s3"),
          "%6.0f revision");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Behavior BD/p9/s4"),
          "%6.0f build");
        rl32eSetScope(3, 4, 10);
        rl32eSetScope(3, 40, 0);
        rl32eSetScope(3, 7, 10);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Behavior BD/p9/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 10, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, -10.0);
        rl32eSetTargetScope(3, 10, 10.0);
        xpceScopeAcqOK(3, &ball_drop_DWork.SFunction_IWORK_j.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Level2 S-Function Block: '<S8>/Port A' (dopci8255) */
  {
    SimStruct *rts = ball_drop_rtM->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != NULL)
      return;
  }

  /* S-Function Block: <S9>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(4)) == 0) {
      if ((i = rl32eDefScope(4,2)) != 0) {
        printf("Error creating scope 4\n");
      } else {
        rl32eAddSignal(4, rl32eGetSignalNo("Ball sensors/PCI-6025E AD/p1"));
        rl32eAddSignal(4, rl32eGetSignalNo("Ball sensors/PCI-6025E AD/p2"));
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo(
          "Ball sensors/PCI-6025E AD/p1")," %2.2f Pick up");
        rl32eSetTargetScopeSigFt(4,rl32eGetSignalNo(
          "Ball sensors/PCI-6025E AD/p2")," %2.2f drop");
        rl32eSetScope(4, 4, 10);
        rl32eSetScope(4, 40, 0);
        rl32eSetScope(4, 7, 10);
        rl32eSetScope(4, 0, 0);
        rl32eSetScope(4, 3, rl32eGetSignalNo("Ball sensors/PCI-6025E AD/p1"));
        rl32eSetScope(4, 1, 0.0);
        rl32eSetScope(4, 2, 0);
        rl32eSetScope(4, 10, 0);
        rl32eSetTargetScope(4, 1, 0.0);
        rl32eSetTargetScope(4, 11, -10.0);
        rl32eSetTargetScope(4, 10, 10.0);
        xpceScopeAcqOK(4, &ball_drop_DWork.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(4);
    }
  }

  ball_drop_DWork.SampleandHold_i.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;
  ball_drop_DWork.SampleandHold.SampleandHold_SubsysRanBC =
    SUBSYS_RAN_BC_DISABLE;

  /* user code (Start function Trailer) */
  rl32eSetScope(1, 8, 1);
  rl32eSetScope(2, 8, 1);
  rl32eSetScope(3, 8, 1);
  rl32eSetScope(4, 8, 1);
  MdlInitialize();
}

rtModel_ball_drop *ball_drop(void)
{
  ball_drop_initialize(1);
  return ball_drop_rtM;
}

void MdlTerminate(void)
{
  ball_drop_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
