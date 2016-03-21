/*
 * CO_bump.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CO_bump".
 *
 * Model version              : 1.1274
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Mar 21 16:29:27 2016
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CO_bump_h_
#define RTW_HEADER_CO_bump_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include "rtw_modelmap.h"
#ifndef CO_bump_COMMON_INCLUDES_
# define CO_bump_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* CO_bump_COMMON_INCLUDES_ */

#include "CO_bump_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define rtModel_CO_bump                RT_MODEL_CO_bump_T

/* Definition for use in the target main file */
#define CO_bump_rtModel                RT_MODEL_CO_bump_T

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals for system '<S33>/Enabled Subsystem' */
typedef struct {
  real_T In1;                          /* '<S36>/In1' */
} B_EnabledSubsystem_CO_bump_T;

/* Block states (auto storage) for system '<S33>/Enabled Subsystem' */
typedef struct {
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S33>/Enabled Subsystem' */
  boolean_T EnabledSubsystem_MODE;     /* '<S33>/Enabled Subsystem' */
} DW_EnabledSubsystem_CO_bump_T;

/* Block signals for system '<S7>/Sample and Hold' */
typedef struct {
  real_T In;                           /* '<S66>/In' */
} B_SampleandHold_CO_bump_T;

/* Block states (auto storage) for system '<S7>/Sample and Hold' */
typedef struct {
  int8_T SampleandHold_SubsysRanBC;    /* '<S7>/Sample and Hold' */
} DW_SampleandHold_CO_bump_T;

/* Zero-crossing (trigger) state for system '<S7>/Sample and Hold' */
typedef struct {
  ZCSigState SampleandHold_Trig_ZCE;   /* '<S7>/Sample and Hold' */
} ZCE_SampleandHold_CO_bump_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Receive_o2;                   /* '<S5>/Receive' */
  real_T yoffset;                      /* '<S77>/yoffset' */
  real_T PCI6025EAD_o1;                /* '<S14>/PCI-6025E AD' */
  real_T PCI6025EAD_o2;                /* '<S14>/PCI-6025E AD' */
  real_T PCI6025EAD_o3;                /* '<S14>/PCI-6025E AD' */
  real_T PCI6025EAD_o4;                /* '<S14>/PCI-6025E AD' */
  real_T PCI6025EAD_o5;                /* '<S14>/PCI-6025E AD' */
  real_T PCI6025EAD_o6;                /* '<S14>/PCI-6025E AD' */
  real_T UnitDelay1[6];                /* '<S78>/Unit Delay1' */
  real_T Gain[6];                      /* '<S78>/Gain' */
  real_T Sum[6];                       /* '<S78>/Sum' */
  real_T Gain1[6];                     /* '<S78>/Gain1' */
  real_T Add[6];                       /* '<S78>/Add' */
  real_T Abs[6];                       /* '<S78>/Abs' */
  real_T SumofElements;                /* '<S78>/Sum of Elements' */
  real_T Memory[6];                    /* '<S78>/Memory' */
  real_T Switch[6];                    /* '<S78>/Switch' */
  real_T Add2[6];                      /* '<S14>/Add2' */
  real_T VectorConcatenate1[6];        /* '<S14>/Vector Concatenate1' */
  real_T Gain3[6];                     /* '<S14>/Gain3' */
  real_T DotProductY;                  /* '<S14>/Dot Product Y' */
  real_T UnitDelay;                    /* '<S72>/Unit Delay' */
  real_T Gain_f;                       /* '<S72>/Gain' */
  real_T Sum_m;                        /* '<S72>/Sum' */
  real_T Gain1_m;                      /* '<S72>/Gain1' */
  real_T VectorConcatenate[6];         /* '<S14>/Vector Concatenate' */
  real_T Gain2[6];                     /* '<S14>/Gain2' */
  real_T DotProductX;                  /* '<S14>/Dot Product X' */
  real_T UnitDelay_n;                  /* '<S71>/Unit Delay' */
  real_T Gain_d;                       /* '<S71>/Gain' */
  real_T Sum_f;                        /* '<S71>/Sum' */
  real_T Gain1_c;                      /* '<S71>/Gain1' */
  real_T PCIQUAD041;                   /* '<S14>/PCI-QUAD04 1' */
  real_T Gain1_n;                      /* '<S14>/Gain1' */
  real_T Sum1;                         /* '<S14>/Sum1' */
  real_T xoffset;                      /* '<S77>/xoffset' */
  real_T PCIQUAD04;                    /* '<S14>/PCI-QUAD04 ' */
  real_T Gain_g;                       /* '<S14>/Gain' */
  real_T Sum3;                         /* '<S14>/Sum3' */
  real_T TrigonometricFunction;        /* '<S77>/Trigonometric Function' */
  real_T Product;                      /* '<S77>/Product' */
  real_T TrigonometricFunction2;       /* '<S77>/Trigonometric Function2' */
  real_T Product2;                     /* '<S77>/Product2' */
  real_T Sum2;                         /* '<S77>/Sum2' */
  real_T TrigonometricFunction1;       /* '<S77>/Trigonometric Function1' */
  real_T Product1;                     /* '<S77>/Product1' */
  real_T TrigonometricFunction3;       /* '<S77>/Trigonometric Function3' */
  real_T Product3;                     /* '<S77>/Product3' */
  real_T Sum3_c;                       /* '<S77>/Sum3' */
  real_T Switch_d[2];                  /* '<S14>/Switch' */
  real_T NeuralOverride[2];            /* '<Root>/Neural Override' */
  real_T x;                            /* '<S24>/x' */
  real_T x_m;                          /* '<S25>/x' */
  real_T Add_m;                        /* '<S22>/Add' */
  real_T x_f;                          /* '<S26>/x' */
  real_T x_g;                          /* '<S27>/x' */
  real_T MatrixConcatenate2[4];        /* '<S77>/Matrix Concatenate2' */
  real_T DigitalFilter2;               /* '<S69>/Digital Filter2' */
  real_T Derivative;                   /* '<S69>/Derivative' */
  real_T dG;                           /* '<S69>/dG' */
  real_T DigitalFilter;                /* '<S69>/Digital Filter' */
  real_T DigitalFilter2_p;             /* '<S70>/Digital Filter2' */
  real_T Derivative_e;                 /* '<S70>/Derivative' */
  real_T dG_o;                         /* '<S70>/dG' */
  real_T DigitalFilter_p;              /* '<S70>/Digital Filter' */
  real_T Switch_j[2];                  /* '<S11>/Switch' */
  real_T MultiportSwitch[2];           /* '<S3>/Multiport Switch' */
  real_T x_o;                          /* '<S18>/x' */
  real_T x_b;                          /* '<S19>/x' */
  real_T Add_h;                        /* '<S16>/Add' */
  real_T x_ox;                         /* '<S20>/x' */
  real_T x_e;                          /* '<S21>/x' */
  real_T LoadSelectSwitch[2];          /* '<S2>/LoadSelect Switch' */
  real_T BehaviorCOBump_o1[2];         /* '<Root>/Behavior CO Bump' */
  real_T BehaviorCOBump_o2[5];         /* '<Root>/Behavior CO Bump' */
  real_T BehaviorCOBump_o3;            /* '<Root>/Behavior CO Bump' */
  real_T BehaviorCOBump_o4[85];        /* '<Root>/Behavior CO Bump' */
  real_T BehaviorCOBump_o5;            /* '<Root>/Behavior CO Bump' */
  real_T BehaviorCOBump_o6[2];         /* '<Root>/Behavior CO Bump' */
  real_T BehaviorCOBump_o7[4];         /* '<Root>/Behavior CO Bump' */
  real_T BehaviorCOBump_o8[2];         /* '<Root>/Behavior CO Bump' */
  real_T y;                            /* '<S18>/y' */
  real_T Add1;                         /* '<S18>/Add1' */
  real_T z;                            /* '<S18>/z' */
  real_T Add3;                         /* '<S18>/Add3' */
  real_T product2;                     /* '<S18>/product2' */
  real_T Add2_o;                       /* '<S18>/Add2' */
  real_T product3;                     /* '<S18>/product3' */
  real_T product4;                     /* '<S18>/product4' */
  real_T Add4;                         /* '<S18>/Add4' */
  real_T product1;                     /* '<S18>/product1' */
  real_T dX;                           /* '<S18>/dX' */
  real_T AddX;                         /* '<S18>/AddX' */
  real_T dY;                           /* '<S18>/dY' */
  real_T AddX1;                        /* '<S18>/AddX1' */
  real_T dZ;                           /* '<S18>/dZ' */
  real_T AddX2;                        /* '<S18>/AddX2' */
  real_T y_m;                          /* '<S19>/y' */
  real_T Add1_l;                       /* '<S19>/Add1' */
  real_T z_g;                          /* '<S19>/z' */
  real_T Add3_n;                       /* '<S19>/Add3' */
  real_T product2_i;                   /* '<S19>/product2' */
  real_T Add2_i;                       /* '<S19>/Add2' */
  real_T product3_d;                   /* '<S19>/product3' */
  real_T product4_c;                   /* '<S19>/product4' */
  real_T Add4_i;                       /* '<S19>/Add4' */
  real_T product1_j;                   /* '<S19>/product1' */
  real_T dX_a;                         /* '<S19>/dX' */
  real_T AddX_g;                       /* '<S19>/AddX' */
  real_T dY_o;                         /* '<S19>/dY' */
  real_T AddX1_j;                      /* '<S19>/AddX1' */
  real_T dZ_o;                         /* '<S19>/dZ' */
  real_T AddX2_l;                      /* '<S19>/AddX2' */
  real_T y_f;                          /* '<S20>/y' */
  real_T Add1_g;                       /* '<S20>/Add1' */
  real_T z_p;                          /* '<S20>/z' */
  real_T Add3_i;                       /* '<S20>/Add3' */
  real_T product2_j;                   /* '<S20>/product2' */
  real_T Add2_p;                       /* '<S20>/Add2' */
  real_T product3_o;                   /* '<S20>/product3' */
  real_T product4_o;                   /* '<S20>/product4' */
  real_T Add4_j;                       /* '<S20>/Add4' */
  real_T product1_a;                   /* '<S20>/product1' */
  real_T dX_p;                         /* '<S20>/dX' */
  real_T AddX_n;                       /* '<S20>/AddX' */
  real_T dY_h;                         /* '<S20>/dY' */
  real_T AddX1_d;                      /* '<S20>/AddX1' */
  real_T dZ_k;                         /* '<S20>/dZ' */
  real_T AddX2_h;                      /* '<S20>/AddX2' */
  real_T y_c;                          /* '<S21>/y' */
  real_T Add1_l1;                      /* '<S21>/Add1' */
  real_T z_i;                          /* '<S21>/z' */
  real_T Add3_g;                       /* '<S21>/Add3' */
  real_T product2_e;                   /* '<S21>/product2' */
  real_T Add2_n;                       /* '<S21>/Add2' */
  real_T product3_b;                   /* '<S21>/product3' */
  real_T product4_i;                   /* '<S21>/product4' */
  real_T Add4_n;                       /* '<S21>/Add4' */
  real_T product1_h;                   /* '<S21>/product1' */
  real_T dX_o;                         /* '<S21>/dX' */
  real_T AddX_c;                       /* '<S21>/AddX' */
  real_T dY_m;                         /* '<S21>/dY' */
  real_T AddX1_o;                      /* '<S21>/AddX1' */
  real_T dZ_om;                        /* '<S21>/dZ' */
  real_T AddX2_a;                      /* '<S21>/AddX2' */
  real_T y_o;                          /* '<S24>/y' */
  real_T Add1_b;                       /* '<S24>/Add1' */
  real_T z_e;                          /* '<S24>/z' */
  real_T Add3_a;                       /* '<S24>/Add3' */
  real_T product2_l;                   /* '<S24>/product2' */
  real_T Add2_l;                       /* '<S24>/Add2' */
  real_T product3_j;                   /* '<S24>/product3' */
  real_T product4_a;                   /* '<S24>/product4' */
  real_T Add4_g;                       /* '<S24>/Add4' */
  real_T product1_i;                   /* '<S24>/product1' */
  real_T dX_b;                         /* '<S24>/dX' */
  real_T AddX_f;                       /* '<S24>/AddX' */
  real_T dY_a;                         /* '<S24>/dY' */
  real_T AddX1_f;                      /* '<S24>/AddX1' */
  real_T dZ_h;                         /* '<S24>/dZ' */
  real_T AddX2_g;                      /* '<S24>/AddX2' */
  real_T y_i;                          /* '<S25>/y' */
  real_T Add1_h;                       /* '<S25>/Add1' */
  real_T z_pw;                         /* '<S25>/z' */
  real_T Add3_f;                       /* '<S25>/Add3' */
  real_T product2_li;                  /* '<S25>/product2' */
  real_T Add2_m;                       /* '<S25>/Add2' */
  real_T product3_e;                   /* '<S25>/product3' */
  real_T product4_iq;                  /* '<S25>/product4' */
  real_T Add4_gm;                      /* '<S25>/Add4' */
  real_T product1_l;                   /* '<S25>/product1' */
  real_T dX_f;                         /* '<S25>/dX' */
  real_T AddX_d;                       /* '<S25>/AddX' */
  real_T dY_f;                         /* '<S25>/dY' */
  real_T AddX1_g;                      /* '<S25>/AddX1' */
  real_T dZ_g;                         /* '<S25>/dZ' */
  real_T AddX2_o;                      /* '<S25>/AddX2' */
  real_T y_od;                         /* '<S26>/y' */
  real_T Add1_a;                       /* '<S26>/Add1' */
  real_T z_n;                          /* '<S26>/z' */
  real_T Add3_b;                       /* '<S26>/Add3' */
  real_T product2_m;                   /* '<S26>/product2' */
  real_T Add2_oy;                      /* '<S26>/Add2' */
  real_T product3_n;                   /* '<S26>/product3' */
  real_T product4_cs;                  /* '<S26>/product4' */
  real_T Add4_d;                       /* '<S26>/Add4' */
  real_T product1_ap;                  /* '<S26>/product1' */
  real_T dX_d;                         /* '<S26>/dX' */
  real_T AddX_j;                       /* '<S26>/AddX' */
  real_T dY_oz;                        /* '<S26>/dY' */
  real_T AddX1_k;                      /* '<S26>/AddX1' */
  real_T dZ_i;                         /* '<S26>/dZ' */
  real_T AddX2_l1;                     /* '<S26>/AddX2' */
  real_T y_k;                          /* '<S27>/y' */
  real_T Add1_n;                       /* '<S27>/Add1' */
  real_T z_gt;                         /* '<S27>/z' */
  real_T Add3_j;                       /* '<S27>/Add3' */
  real_T product2_c;                   /* '<S27>/product2' */
  real_T Add2_e;                       /* '<S27>/Add2' */
  real_T product3_f;                   /* '<S27>/product3' */
  real_T product4_m;                   /* '<S27>/product4' */
  real_T Add4_k;                       /* '<S27>/Add4' */
  real_T product1_m;                   /* '<S27>/product1' */
  real_T dX_aq;                        /* '<S27>/dX' */
  real_T AddX_a;                       /* '<S27>/AddX' */
  real_T dY_p;                         /* '<S27>/dY' */
  real_T AddX1_m;                      /* '<S27>/AddX1' */
  real_T dZ_b;                         /* '<S27>/dZ' */
  real_T AddX2_ok;                     /* '<S27>/AddX2' */
  real_T MatrixConcatenation1[4];      /* '<Root>/Matrix Concatenation1' */
  real_T Clock;                        /* '<S33>/Clock' */
  real_T Sum_h;                        /* '<S33>/Sum' */
  real_T Time;                         /* '<S33>/Time' */
  real_T DiscreteFIRFilter[2];         /* '<S6>/Discrete FIR Filter' */
  real_T Clock_c;                      /* '<S45>/Clock' */
  real_T Clock_l;                      /* '<S49>/Clock' */
  real_T Sum_fl;                       /* '<S49>/Sum' */
  real_T Time_b;                       /* '<S49>/Time' */
  real_T Sum_n;                        /* '<S45>/Sum' */
  real_T Time_h;                       /* '<S45>/Time' */
  real_T Abs2;                         /* '<S42>/Abs2' */
  real_T Abs3;                         /* '<S42>/Abs3' */
  real_T Clock_i;                      /* '<S47>/Clock' */
  real_T Sum_flx;                      /* '<S47>/Sum' */
  real_T Time_k;                       /* '<S47>/Time' */
  real_T Clock_e;                      /* '<S46>/Clock' */
  real_T Sum_a;                        /* '<S46>/Sum' */
  real_T Time_j;                       /* '<S46>/Time' */
  real_T Switch2[2];                   /* '<S4>/Switch2' */
  real_T MG1;                          /* '<S4>/MG1' */
  real_T MG2;                          /* '<S4>/MG2' */
  real_T Switch3[2];                   /* '<S4>/Switch3' */
  real_T Switch4;                      /* '<S4>/Switch4' */
  real_T Switch5;                      /* '<S4>/Switch5' */
  real_T Abs_h;                        /* '<S4>/Abs' */
  real_T Abs1;                         /* '<S4>/Abs1' */
  real_T Clock_j;                      /* '<S67>/Clock' */
  real_T Sum_ap;                       /* '<S67>/Sum' */
  real_T UniformRandomNumber;          /* '<S7>/Uniform Random Number' */
  real_T Switch_c;                     /* '<S7>/Switch' */
  real_T DataTypeConversion;           /* '<S7>/Data Type Conversion' */
  real_T Add_o[9];                     /* '<S10>/Add' */
  real_T Add1_k[9];                    /* '<S10>/Add1' */
  real_T Gain_o[9];                    /* '<S10>/Gain' */
  real_T Gain1_a[9];                   /* '<S10>/Gain1' */
  real_T FOffset[6];                   /* '<S78>/F Offset' */
  real_T ForIterator;                  /* '<S75>/For Iterator' */
  real_T Switch_m;                     /* '<S75>/Switch' */
  real_T ToBits1_o1;                   /* '<S75>/ToBits1' */
  real_T ToBits1_o2;                   /* '<S75>/ToBits1' */
  real_T ToBits1_o3;                   /* '<S75>/ToBits1' */
  real_T ToBits1_o4;                   /* '<S75>/ToBits1' */
  real_T ToBits1_o5;                   /* '<S75>/ToBits1' */
  real_T ToBits1_o6;                   /* '<S75>/ToBits1' */
  real_T ToBits1_o7;                   /* '<S75>/ToBits1' */
  real_T ToBits1_o8;                   /* '<S75>/ToBits1' */
  real_T Add_hr;                       /* '<S75>/Add' */
  real_T Add1_c;                       /* '<S75>/Add1' */
  real_T Memory_i;                     /* '<S75>/Memory' */
  real_T SerialConverter;              /* '<S75>/SerialConverter' */
  real_T ToBits_o1;                    /* '<S75>/ToBits' */
  real_T ToBits_o2;                    /* '<S75>/ToBits' */
  real_T ToBits_o3;                    /* '<S75>/ToBits' */
  real_T ToBits_o4;                    /* '<S75>/ToBits' */
  real_T ToBits_o5;                    /* '<S75>/ToBits' */
  real_T ToBits_o6;                    /* '<S75>/ToBits' */
  real_T ToBits_o7;                    /* '<S75>/ToBits' */
  real_T ToBits_o8;                    /* '<S75>/ToBits' */
  real_T xPCTargetTime;                /* '<S75>/xPC Target  Time ' */
  real_T xPCTargetTime_k;              /* '<S79>/xPC Target  Time ' */
  real_T Subtract;                     /* '<S79>/Subtract' */
  real_T ScaleTouSec;                  /* '<S79>/ScaleTouSec' */
  real_T Switch_o;                     /* '<S79>/Switch' */
  real_T TrigonometricFunction1_b;     /* '<S76>/Trigonometric Function1' */
  real_T Sum_hr;                       /* '<S76>/Sum' */
  real_T TrigonometricFunction2_e;     /* '<S76>/Trigonometric Function2' */
  real_T sqrtu1u1u2u2;                 /* '<S76>/sqrt(u[1]*u[1] + u[2]*u[2])' */
  real_T Product1_m;                   /* '<S76>/Product1' */
  real_T DotProduct2;                  /* '<S14>/Dot Product2' */
  real_T Fcn;                          /* '<S14>/Fcn' */
  real_T DotProduct;                   /* '<S14>/Dot Product' */
  real_T Add_e;                        /* '<S14>/Add' */
  real_T TrigonometricFunction_c;      /* '<S76>/Trigonometric Function' */
  real_T Product_a;                    /* '<S76>/Product' */
  real_T DotProduct1;                  /* '<S14>/Dot Product1' */
  real_T Add1_o;                       /* '<S14>/Add1' */
  real_T sqrtu1u1u2u2_d;               /* '<S74>/sqrt(u[1]*u[1] + u[2]*u[2])' */
  real_T TrigonometricFunction1_a;     /* '<S74>/Trigonometric Function1' */
  real_T Sum_j;                        /* '<S74>/Sum' */
  real_T TrigonometricFunction2_h;     /* '<S74>/Trigonometric Function2' */
  real_T Product1_g;                   /* '<S74>/Product1' */
  real_T TrigonometricFunction_i;      /* '<S74>/Trigonometric Function' */
  real_T Product_d;                    /* '<S74>/Product' */
  real_T Sum1_m;                       /* '<S77>/Sum1' */
  real_T Sum4;                         /* '<S77>/Sum4' */
  real_T sqrtu1u1u2u2_p;               /* '<S73>/sqrt(u[1]*u[1] + u[2]*u[2])' */
  real_T TrigonometricFunction1_av;    /* '<S73>/Trigonometric Function1' */
  real_T Sum_e;                        /* '<S73>/Sum' */
  real_T TrigonometricFunction2_hb;    /* '<S73>/Trigonometric Function2' */
  real_T Product1_c;                   /* '<S73>/Product1' */
  real_T TrigonometricFunction_n;      /* '<S73>/Trigonometric Function' */
  real_T Product_f;                    /* '<S73>/Product' */
  real_T TachGain2;                    /* '<S11>/TachGain2' */
  real_T TachGain1;                    /* '<S11>/TachGain1' */
  real_T TmpSignalConversionAtMatrixMult[2];
  real_T MatrixMultiply[2];            /* '<S11>/Matrix Multiply' */
  real_T Gain_fi[2];                   /* '<S32>/Gain' */
  real_T Transpose[4];                 /* '<S32>/Transpose' */
  real_T MatrixMultiply_e[2];          /* '<S32>/Matrix Multiply' */
  real_T Switch1[2];                   /* '<S4>/Switch1' */
  real_T Switch_cu[2];                 /* '<S6>/Switch' */
  real_T BoundingBoxViscosity[2];      /* '<S6>/Bounding Box Viscosity' */
  real_T Add_j;                        /* '<S6>/Add' */
  real_T Product_l[2];                 /* '<S6>/Product' */
  real_T Product_o;                    /* '<S43>/Product' */
  real_T Gain1_ay;                     /* '<S43>/Gain1' */
  real_T Saturation;                   /* '<S43>/Saturation' */
  real_T Gain3_d;                      /* '<S43>/Gain3' */
  real_T Add_jr;                       /* '<S43>/Add' */
  real_T Gain4;                        /* '<S43>/Gain4' */
  real_T Product1_mk;                  /* '<S43>/Product1' */
  real_T Gain2_f;                      /* '<S43>/Gain2' */
  real_T Saturation1;                  /* '<S43>/Saturation1' */
  real_T Add1_g3;                      /* '<S43>/Add1' */
  real_T Saturation_g;                 /* '<S4>/Saturation' */
  real_T Saturation1_f;                /* '<S4>/Saturation1' */
  real_T GainM1Pos;                    /* '<S4>/GainM1Pos' */
  real_T GainM1Neg;                    /* '<S4>/GainM1Neg' */
  real_T GainM2Pos;                    /* '<S4>/GainM2Pos' */
  real_T GainM2Neg;                    /* '<S4>/GainM2Neg' */
  real_T Add1_ce;                      /* '<S22>/Add1' */
  real_T LorentzForceGain[2];          /* '<S3>/LorentzForceGain' */
  real_T dynamicAngleSwitch;           /* '<S3>/dynamicAngle Switch' */
  real_T sin_a;                        /* '<S23>/sin' */
  real_T Inverter[2];                  /* '<S23>/Inverter' */
  real_T Product3_o;                   /* '<S23>/Product3' */
  real_T cos_k;                        /* '<S23>/cos' */
  real_T Product2_g;                   /* '<S23>/Product2' */
  real_T Subtract_i;                   /* '<S23>/Subtract' */
  real_T Product1_a;                   /* '<S23>/Product1' */
  real_T Product_c;                    /* '<S23>/Product' */
  real_T Add_a;                        /* '<S23>/Add' */
  real_T Gain_h[2];                    /* '<S23>/Gain' */
  real_T Gain_b;                       /* '<S3>/Gain' */
  real_T Add1_li;                      /* '<S16>/Add1' */
  real_T LorentzForceGain_f[2];        /* '<S2>/LorentzForceGain' */
  real_T DynamicAngleSwitch;           /* '<S2>/DynamicAngle Switch' */
  real_T sin_i;                        /* '<S17>/sin' */
  real_T Inverter_c[2];                /* '<S17>/Inverter' */
  real_T Product3_d;                   /* '<S17>/Product3' */
  real_T cos_d;                        /* '<S17>/cos' */
  real_T Product2_o;                   /* '<S17>/Product2' */
  real_T Subtract_h;                   /* '<S17>/Subtract' */
  real_T Product1_d;                   /* '<S17>/Product1' */
  real_T Product_p;                    /* '<S17>/Product' */
  real_T Add_c;                        /* '<S17>/Add' */
  real_T Gain_a[2];                    /* '<S17>/Gain' */
  real_T Gain_c;                       /* '<S2>/Gain' */
  real32_T Unpack[12];                 /* '<S5>/Unpack' */
  int32_T DiscreteTimeIntegrator;      /* '<S78>/Discrete-Time Integrator' */
  uint8_T Receive_o1[48];              /* '<S5>/Receive' */
  uint8_T Compare;                     /* '<S83>/Compare' */
  uint8_T Pack[728];                   /* '<S8>/Pack' */
  uint8_T RateTransition[728];         /* '<S8>/Rate Transition' */
  uint8_T Compare_h;                   /* '<S35>/Compare' */
  uint8_T Compare_c;                   /* '<S37>/Compare' */
  uint8_T Compare_d;                   /* '<S38>/Compare' */
  uint8_T Compare_n;                   /* '<S62>/Compare' */
  uint8_T Compare_d2;                  /* '<S65>/Compare' */
  uint8_T Uk1;                         /* '<S63>/Delay Input1' */
  uint8_T FixPtRelationalOperator;     /* '<S63>/FixPt Relational Operator' */
  uint8_T Compare_g;                   /* '<S55>/Compare' */
  uint8_T Compare_b;                   /* '<S53>/Compare' */
  uint8_T Compare_ha;                  /* '<S54>/Compare' */
  uint8_T Compare_m;                   /* '<S61>/Compare' */
  uint8_T Uk1_m;                       /* '<S48>/Delay Input1' */
  uint8_T FixPtRelationalOperator_e;   /* '<S48>/FixPt Relational Operator' */
  uint8_T Compare_m3;                  /* '<S59>/Compare' */
  uint8_T Compare_l;                   /* '<S52>/Compare' */
  uint8_T Uk1_a;                       /* '<S41>/Delay Input1' */
  uint8_T FixPtRelationalOperator_n;   /* '<S41>/FixPt Relational Operator' */
  uint8_T Compare_bi;                  /* '<S57>/Compare' */
  uint8_T Compare_p;                   /* '<S51>/Compare' */
  uint8_T Uk1_b;                       /* '<S40>/Delay Input1' */
  uint8_T FixPtRelationalOperator_j;   /* '<S40>/FixPt Relational Operator' */
  uint8_T Compare_e;                   /* '<S28>/Compare' */
  uint8_T Compare_k;                   /* '<S29>/Compare' */
  boolean_T Compare_ea;                /* '<S82>/Compare' */
  boolean_T RelationalOperator;        /* '<S1>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S1>/Relational Operator1' */
  boolean_T RelationalOperator2;       /* '<S1>/Relational Operator2' */
  boolean_T RelationalOperator3;       /* '<S1>/Relational Operator3' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T LogicalOperator2;          /* '<S1>/Logical Operator2' */
  boolean_T LogicalOperator1;          /* '<S1>/Logical Operator1' */
  boolean_T LogicalOperator2_h;        /* '<S4>/Logical Operator2' */
  boolean_T Memory_a;                  /* '<S33>/Memory' */
  boolean_T Memory_f;                  /* '<S4>/Memory' */
  boolean_T LogicalOperator2_g;        /* '<S33>/Logical Operator2' */
  boolean_T LogicalOperator1_b;        /* '<S33>/Logical Operator1' */
  boolean_T RelationalOperator_e;      /* '<S33>/Relational Operator' */
  boolean_T LogicalOperator_l;         /* '<S33>/Logical Operator' */
  boolean_T Memory_iz;                 /* '<S45>/Memory' */
  boolean_T InBox;                     /* '<S6>/InBox' */
  boolean_T LogicalOperator3;          /* '<S49>/Logical Operator3' */
  boolean_T Memory_m;                  /* '<S49>/Memory' */
  boolean_T LogicalOperator4;          /* '<S49>/Logical Operator4' */
  boolean_T LogicalOperator_m;         /* '<S6>/Logical Operator' */
  boolean_T LogicalOperator2_a;        /* '<S49>/Logical Operator2' */
  boolean_T LogicalOperator1_p;        /* '<S49>/Logical Operator1' */
  boolean_T RelationalOperator_l;      /* '<S49>/Relational Operator' */
  boolean_T LogicalOperator_k;         /* '<S49>/Logical Operator' */
  boolean_T LogicalOperator5;          /* '<S49>/Logical Operator5' */
  boolean_T LogicalOperator2_k;        /* '<S45>/Logical Operator2' */
  boolean_T LogicalOperator1_o;        /* '<S45>/Logical Operator1' */
  boolean_T RelationalOperator_b;      /* '<S45>/Relational Operator' */
  boolean_T LogicalOperator_m1;        /* '<S45>/Logical Operator' */
  boolean_T LogicalOperator1_a;        /* '<S42>/Logical Operator1' */
  boolean_T NOT;                       /* '<S6>/NOT' */
  boolean_T Memory_j;                  /* '<S47>/Memory' */
  boolean_T LogicalOperator2_m;        /* '<S47>/Logical Operator2' */
  boolean_T LogicalOperator1_bp;       /* '<S47>/Logical Operator1' */
  boolean_T RelationalOperator_e0;     /* '<S47>/Relational Operator' */
  boolean_T LogicalOperator_b;         /* '<S47>/Logical Operator' */
  boolean_T DataTypeConversion2;       /* '<S6>/Data Type Conversion2' */
  boolean_T LogicalOperator1_i;        /* '<S6>/Logical Operator1' */
  boolean_T Memory_h;                  /* '<S46>/Memory' */
  boolean_T LogicalOperator2_j;        /* '<S46>/Logical Operator2' */
  boolean_T LogicalOperator1_m;        /* '<S46>/Logical Operator1' */
  boolean_T RelationalOperator_ew;     /* '<S46>/Relational Operator' */
  boolean_T LogicalOperator_bx;        /* '<S46>/Logical Operator' */
  boolean_T DataTypeConversion1;       /* '<S6>/Data Type Conversion1' */
  boolean_T Memory_jb;                 /* '<S44>/Memory' */
  boolean_T Logic[2];                  /* '<S44>/Logic' */
  boolean_T LogicalOperator5_l;        /* '<S6>/Logical Operator5' */
  boolean_T Compare_a;                 /* '<S30>/Compare' */
  boolean_T Compare_lx;                /* '<S31>/Compare' */
  boolean_T LogicalOperator1_h;        /* '<S4>/Logical Operator1' */
  boolean_T LogicalOperator_i;         /* '<S4>/Logical Operator' */
  boolean_T MatrixConcatenation[2];    /* '<S4>/Matrix Concatenation' */
  boolean_T RelationalOperator_i;      /* '<S7>/Relational Operator' */
  boolean_T RelationalOperator_f;      /* '<S67>/Relational Operator' */
  boolean_T Compare_kk;                /* '<S81>/Compare' */
  boolean_T Compare_pp;                /* '<S80>/Compare' */
  boolean_T LogicalOperator6;          /* '<S6>/Logical Operator6' */
  boolean_T LogicalOperator3_p;        /* '<S6>/Logical Operator3' */
  boolean_T Compare_mm;                /* '<S39>/Compare' */
  B_SampleandHold_CO_bump_T SampleandHold;/* '<S67>/Sample and Hold' */
  B_SampleandHold_CO_bump_T SampleandHold_j;/* '<S7>/Sample and Hold' */
  B_EnabledSubsystem_CO_bump_T EnabledSubsystem_e;/* '<S49>/Enabled Subsystem' */
  B_EnabledSubsystem_CO_bump_T EnabledSubsystem_l;/* '<S47>/Enabled Subsystem' */
  B_EnabledSubsystem_CO_bump_T EnabledSubsystem_d;/* '<S46>/Enabled Subsystem' */
  B_EnabledSubsystem_CO_bump_T EnabledSubsystem_m;/* '<S45>/Enabled Subsystem' */
  B_EnabledSubsystem_CO_bump_T EnabledSubsystem;/* '<S33>/Enabled Subsystem' */
} B_CO_bump_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE[6];         /* '<S78>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S72>/Unit Delay' */
  real_T UnitDelay_DSTATE_e;           /* '<S71>/Unit Delay' */
  real_T x_DSTATE;                     /* '<S24>/x' */
  real_T x_DSTATE_i;                   /* '<S25>/x' */
  real_T x_DSTATE_o;                   /* '<S26>/x' */
  real_T x_DSTATE_a;                   /* '<S27>/x' */
  real_T DigitalFilter2_FILT_STATES[11];/* '<S69>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES[11];/* '<S69>/Digital Filter' */
  real_T DigitalFilter2_FILT_STATES_k[11];/* '<S70>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES_o[11];/* '<S70>/Digital Filter' */
  real_T x_DSTATE_p;                   /* '<S18>/x' */
  real_T x_DSTATE_ix;                  /* '<S19>/x' */
  real_T x_DSTATE_f;                   /* '<S20>/x' */
  real_T x_DSTATE_l;                   /* '<S21>/x' */
  real_T y_DSTATE;                     /* '<S18>/y' */
  real_T z_DSTATE;                     /* '<S18>/z' */
  real_T y_DSTATE_n;                   /* '<S19>/y' */
  real_T z_DSTATE_f;                   /* '<S19>/z' */
  real_T y_DSTATE_k;                   /* '<S20>/y' */
  real_T z_DSTATE_l;                   /* '<S20>/z' */
  real_T y_DSTATE_a;                   /* '<S21>/y' */
  real_T z_DSTATE_a;                   /* '<S21>/z' */
  real_T y_DSTATE_g;                   /* '<S24>/y' */
  real_T z_DSTATE_k;                   /* '<S24>/z' */
  real_T y_DSTATE_b;                   /* '<S25>/y' */
  real_T z_DSTATE_m;                   /* '<S25>/z' */
  real_T y_DSTATE_kn;                  /* '<S26>/y' */
  real_T z_DSTATE_d;                   /* '<S26>/z' */
  real_T y_DSTATE_j;                   /* '<S27>/y' */
  real_T z_DSTATE_d0;                  /* '<S27>/z' */
  real_T DiscreteFIRFilter_states[58]; /* '<S6>/Discrete FIR Filter' */
  real_T Memory_PreviousInput[6];      /* '<S78>/Memory' */
  real_T TimeStampA;                   /* '<S69>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S69>/Derivative' */
  real_T TimeStampB;                   /* '<S69>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S69>/Derivative' */
  real_T TimeStampA_o;                 /* '<S70>/Derivative' */
  real_T LastUAtTimeA_h;               /* '<S70>/Derivative' */
  real_T TimeStampB_a;                 /* '<S70>/Derivative' */
  real_T LastUAtTimeB_m;               /* '<S70>/Derivative' */
  real_T UniformRandomNumber_NextOutput;/* '<S7>/Uniform Random Number' */
  real_T Memory_PreviousInput_i;       /* '<S75>/Memory' */
  real_T PCI6025EAD_RWORK[64];         /* '<S14>/PCI-6025E AD' */
  real_T PCI6025E_RWORK[6];            /* '<S4>/PCI-6025E ' */
  void *Receive_PWORK;                 /* '<S5>/Receive' */
  void *BehaviorCOBump_PWORK;          /* '<Root>/Behavior CO Bump' */
  void *Send_PWORK;                    /* '<S8>/Send' */
  int32_T DiscreteTimeIntegrator_DSTATE;/* '<S78>/Discrete-Time Integrator' */
  int32_T DiscreteFIRFilter_circBuf;   /* '<S6>/Discrete FIR Filter' */
  int32_T DigitalFilter2_CIRCBUFFIDX;  /* '<S69>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX;   /* '<S69>/Digital Filter' */
  int32_T DigitalFilter2_CIRCBUFFIDX_c;/* '<S70>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX_o; /* '<S70>/Digital Filter' */
  uint32_T RandSeed;                   /* '<S7>/Uniform Random Number' */
  int_T IntelChipsetDisableSMI_IWORK[5];/* '<Root>/Intel Chipset Disable SMI' */
  int_T Receive_IWORK[2];              /* '<S5>/Receive' */
  int_T PCI6025EAD_IWORK[66];          /* '<S14>/PCI-6025E AD' */
  int_T PCIQUAD041_IWORK;              /* '<S14>/PCI-QUAD04 1' */
  int_T PCIQUAD04_IWORK;               /* '<S14>/PCI-QUAD04 ' */
  int_T Send_IWORK[2];                 /* '<S8>/Send' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S9>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_e;                 /* '<S12>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_c;                 /* '<S15>/S-Function' */

  int_T PCI6025E_IWORK[2];             /* '<S4>/PCI-6025E ' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK_f;                 /* '<S34>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_eu;                /* '<S50>/S-Function' */

  int_T PortA_IWORK[2];                /* '<S75>/Port A' */
  int_T PortB_IWORK[2];                /* '<S75>/Port B' */
  int_T PCI6025E_IWORK_o[3];           /* '<S79>/PCI-6025E ' */
  uint8_T DelayInput1_DSTATE;          /* '<S63>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_d;        /* '<S48>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_m;        /* '<S41>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_p;        /* '<S40>/Delay Input1' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S78>/Discrete-Time Integrator' */
  boolean_T Memory_PreviousInput_h;    /* '<S33>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S4>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S45>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S49>/Memory' */
  boolean_T Memory_PreviousInput_is;   /* '<S47>/Memory' */
  boolean_T Memory_PreviousInput_k;    /* '<S46>/Memory' */
  boolean_T Memory_PreviousInput_d;    /* '<S44>/Memory' */
  DW_SampleandHold_CO_bump_T SampleandHold;/* '<S67>/Sample and Hold' */
  DW_SampleandHold_CO_bump_T SampleandHold_j;/* '<S7>/Sample and Hold' */
  DW_EnabledSubsystem_CO_bump_T EnabledSubsystem_e;/* '<S49>/Enabled Subsystem' */
  DW_EnabledSubsystem_CO_bump_T EnabledSubsystem_l;/* '<S47>/Enabled Subsystem' */
  DW_EnabledSubsystem_CO_bump_T EnabledSubsystem_d;/* '<S46>/Enabled Subsystem' */
  DW_EnabledSubsystem_CO_bump_T EnabledSubsystem_m;/* '<S45>/Enabled Subsystem' */
  DW_EnabledSubsystem_CO_bump_T EnabledSubsystem;/* '<S33>/Enabled Subsystem' */
} DW_CO_bump_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_SampleandHold_CO_bump_T SampleandHold;/* '<S7>/Sample and Hold' */
  ZCE_SampleandHold_CO_bump_T SampleandHold_j;/* '<S7>/Sample and Hold' */
} PrevZCX_CO_bump_T;

/* Backward compatible GRT Identifiers */
#define rtB                            CO_bump_B
#define BlockIO                        B_CO_bump_T
#define rtP                            CO_bump_P
#define Parameters                     P_CO_bump_T
#define rtDWork                        CO_bump_DW
#define D_Work                         DW_CO_bump_T
#define rtPrevZCSigState               CO_bump_PrevZCX
#define PrevZCSigStates                PrevZCX_CO_bump_T

/* Parameters for system: '<S7>/Sample and Hold' */
struct P_SampleandHold_CO_bump_T_ {
  real_T _Y0;                          /* Expression: initCond
                                        * Referenced by: '<S66>/ '
                                        */
};

/* Parameters (auto storage) */
struct P_CO_bump_T_ {
  real_T DigitalFilter2_NumCoeffs[11]; /* Mask Parameter: DigitalFilter2_NumCoeffs
                                        * Referenced by: '<S69>/Digital Filter2'
                                        */
  real_T DigitalFilter_NumCoeffs[11];  /* Mask Parameter: DigitalFilter_NumCoeffs
                                        * Referenced by: '<S69>/Digital Filter'
                                        */
  real_T DigitalFilter2_NumCoeffs_p[11];/* Mask Parameter: DigitalFilter2_NumCoeffs_p
                                         * Referenced by: '<S70>/Digital Filter2'
                                         */
  real_T DigitalFilter_NumCoeffs_j[11];/* Mask Parameter: DigitalFilter_NumCoeffs_j
                                        * Referenced by: '<S70>/Digital Filter'
                                        */
  real_T Schmidt_Time;                 /* Mask Parameter: Schmidt_Time
                                        * Referenced by: '<S33>/Time'
                                        */
  real_T Timer_Time;                   /* Mask Parameter: Timer_Time
                                        * Referenced by: '<S49>/Time'
                                        */
  real_T Schmidt1_Time;                /* Mask Parameter: Schmidt1_Time
                                        * Referenced by: '<S45>/Time'
                                        */
  real_T Schmidt3_Time;                /* Mask Parameter: Schmidt3_Time
                                        * Referenced by: '<S47>/Time'
                                        */
  real_T Schmidt2_Time;                /* Mask Parameter: Schmidt2_Time
                                        * Referenced by: '<S46>/Time'
                                        */
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S81>/Constant'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S80>/Constant'
                                        */
  real_T NoiseLevel_const;             /* Mask Parameter: NoiseLevel_const
                                        * Referenced by: '<S83>/Constant'
                                        */
  real_T CompareToConstant2_const;     /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T CompareToConstant3_const;     /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T CompareToConstant_const_l;    /* Mask Parameter: CompareToConstant_const_l
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T CompareToConstant1_const_a;   /* Mask Parameter: CompareToConstant1_const_a
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T Lorentz_y0;                   /* Mask Parameter: Lorentz_y0
                                        * Referenced by: '<S18>/y'
                                        */
  real_T Lorentz1_y0;                  /* Mask Parameter: Lorentz1_y0
                                        * Referenced by: '<S19>/y'
                                        */
  real_T Lorentz2_y0;                  /* Mask Parameter: Lorentz2_y0
                                        * Referenced by: '<S20>/y'
                                        */
  real_T Lorentz3_y0;                  /* Mask Parameter: Lorentz3_y0
                                        * Referenced by: '<S21>/y'
                                        */
  real_T Lorentz_y0_e;                 /* Mask Parameter: Lorentz_y0_e
                                        * Referenced by: '<S24>/y'
                                        */
  real_T Lorentz1_y0_o;                /* Mask Parameter: Lorentz1_y0_o
                                        * Referenced by: '<S25>/y'
                                        */
  real_T Lorentz2_y0_h;                /* Mask Parameter: Lorentz2_y0_h
                                        * Referenced by: '<S26>/y'
                                        */
  real_T Lorentz3_y0_m;                /* Mask Parameter: Lorentz3_y0_m
                                        * Referenced by: '<S27>/y'
                                        */
  int32_T CompareToConstant1_const_ah; /* Mask Parameter: CompareToConstant1_const_ah
                                        * Referenced by: '<S82>/Constant'
                                        */
  uint8_T DetectFallNonpositive_vinit; /* Mask Parameter: DetectFallNonpositive_vinit
                                        * Referenced by: '<S63>/Delay Input1'
                                        */
  uint8_T StartMoving_vinit;           /* Mask Parameter: StartMoving_vinit
                                        * Referenced by: '<S48>/Delay Input1'
                                        */
  uint8_T FallingEdge1_vinit;          /* Mask Parameter: FallingEdge1_vinit
                                        * Referenced by: '<S41>/Delay Input1'
                                        */
  uint8_T FallingEdge_vinit;           /* Mask Parameter: FallingEdge_vinit
                                        * Referenced by: '<S40>/Delay Input1'
                                        */
  boolean_T SRFlipFlop_initial_condition;/* Mask Parameter: SRFlipFlop_initial_condition
                                          * Referenced by: '<S44>/Memory'
                                          */
  real_T Gain_Gain;                    /* Expression: 0.0367
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T visAngle_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/visAngle'
                                        */
  real_T DynamicAngle_Value;           /* Expression: 0
                                        * Referenced by: '<S2>/DynamicAngle'
                                        */
  real_T Inverter_Gain;                /* Expression: -1
                                        * Referenced by: '<S17>/Inverter'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 1
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T LorentzForceGain_Gain;        /* Expression: .0005
                                        * Referenced by: '<S2>/LorentzForceGain'
                                        */
  real_T staticX_Value;                /* Expression: 0
                                        * Referenced by: '<S2>/staticX'
                                        */
  real_T staticY_Value;                /* Expression: 0
                                        * Referenced by: '<S2>/staticY'
                                        */
  real_T Off_Value;                    /* Expression: 0
                                        * Referenced by: '<S2>/Off'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 0.0367
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T visAngle_Value_f;             /* Expression: 0
                                        * Referenced by: '<S3>/visAngle'
                                        */
  real_T DynamicAngle_Value_p;         /* Expression: 0
                                        * Referenced by: '<S3>/DynamicAngle'
                                        */
  real_T Inverter_Gain_b;              /* Expression: -1
                                        * Referenced by: '<S23>/Inverter'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 1
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T LorentzForceGain_Gain_l;      /* Expression: .0005
                                        * Referenced by: '<S3>/LorentzForceGain'
                                        */
  real_T staticX_Value_m;              /* Expression: 0
                                        * Referenced by: '<S3>/staticX'
                                        */
  real_T staticY_Value_k;              /* Expression: 0
                                        * Referenced by: '<S3>/staticY'
                                        */
  real_T Off_Value_p;                  /* Expression: 0
                                        * Referenced by: '<S3>/Off'
                                        */
  real_T GainM2Neg_Gain;               /* Expression: 1
                                        * Referenced by: '<S4>/GainM2Neg'
                                        */
  real_T GainM2Pos_Gain;               /* Expression: 1
                                        * Referenced by: '<S4>/GainM2Pos'
                                        */
  real_T GainM1Neg_Gain;               /* Expression: 1
                                        * Referenced by: '<S4>/GainM1Neg'
                                        */
  real_T GainM1Pos_Gain;               /* Expression: 1
                                        * Referenced by: '<S4>/GainM1Pos'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 7.5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -7.5
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 7.5
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -7.5
                                        * Referenced by: '<S4>/Saturation1'
                                        */
  real_T zero2_Value[2];               /* Expression: [0 0]
                                        * Referenced by: '<S4>/zero2'
                                        */
  real_T Gain1_Gain;                   /* Expression: -.05
                                        * Referenced by: '<S43>/Gain1'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 3
                                        * Referenced by: '<S43>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -3
                                        * Referenced by: '<S43>/Saturation'
                                        */
  real_T Gain3_Gain;                   /* Expression: -.03
                                        * Referenced by: '<S43>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: -.03
                                        * Referenced by: '<S43>/Gain4'
                                        */
  real_T Gain2_Gain;                   /* Expression: -.05
                                        * Referenced by: '<S43>/Gain2'
                                        */
  real_T Saturation1_UpperSat_j;       /* Expression: 3
                                        * Referenced by: '<S43>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_c;       /* Expression: -3
                                        * Referenced by: '<S43>/Saturation1'
                                        */
  real_T BoundingBoxViscosity_Gain;    /* Expression: -.08
                                        * Referenced by: '<S6>/Bounding Box Viscosity'
                                        */
  real_T zeroX_Value;                  /* Expression: 0
                                        * Referenced by: '<S4>/zeroX'
                                        */
  real_T zeroY_Value;                  /* Expression: 0
                                        * Referenced by: '<S4>/zeroY'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T RewardJackpot_Value;          /* Expression: 0.60
                                        * Referenced by: '<S7>/RewardJackpot'
                                        */
  real_T RewardTime_Value;             /* Expression: 0.30
                                        * Referenced by: '<S7>/RewardTime'
                                        */
  real_T ReplaceIfYouWantToUseTachs2_Val;/* Expression: 0
                                          * Referenced by: '<S11>/ReplaceIfYouWantToUseTachs2'
                                          */
  real_T TachGain2_Gain;               /* Expression: 1.29
                                        * Referenced by: '<S11>/TachGain2'
                                        */
  real_T ReplaceIfYouWantToUseTachs1_Val;/* Expression: 0
                                          * Referenced by: '<S11>/ReplaceIfYouWantToUseTachs1'
                                          */
  real_T TachGain1_Gain;               /* Expression: 1.29
                                        * Referenced by: '<S11>/TachGain1'
                                        */
  real_T ForceToScreenGain_Value;      /* Expression: 1
                                        * Referenced by: '<S14>/ForceToScreenGain'
                                        */
  real_T UpsideDownHandle_Value;       /* Expression: 0
                                        * Referenced by: '<S14>/UpsideDownHandle'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S75>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S79>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T xPCTargetTime_P1_Size[2];     /* Computed Parameter: xPCTargetTime_P1_Size
                                        * Referenced by: '<S79>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1;             /* Expression: func
                                        * Referenced by: '<S79>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size[2];     /* Computed Parameter: xPCTargetTime_P2_Size
                                        * Referenced by: '<S79>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2;             /* Expression: ts
                                        * Referenced by: '<S79>/xPC Target  Time '
                                        */
  real_T ScaleTouSec_Gain;             /* Expression: .838
                                        * Referenced by: '<S79>/ScaleTouSec'
                                        */
  real_T PCI6025E_P1_Size[2];          /* Computed Parameter: PCI6025E_P1_Size
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P1[2];               /* Expression: channel
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_Size[2];          /* Computed Parameter: PCI6025E_P2_Size
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P2[2];               /* Expression: reset
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_Size[2];          /* Computed Parameter: PCI6025E_P3_Size
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P3[2];               /* Expression: initValue
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_Size[2];          /* Computed Parameter: PCI6025E_P4_Size
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P4;                  /* Expression: sampletime
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_Size[2];          /* Computed Parameter: PCI6025E_P5_Size
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P5;                  /* Expression: slot
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_Size[2];          /* Computed Parameter: PCI6025E_P6_Size
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P6;                  /* Expression: control
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_Size[2];          /* Computed Parameter: PCI6025E_P7_Size
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T PCI6025E_P7;                  /* Expression: boardType
                                        * Referenced by: '<S79>/PCI-6025E '
                                        */
  real_T ForIterator_IterationLimit;   /* Expression: 5
                                        * Referenced by: '<S75>/For Iterator'
                                        */
  real_T Switch_Threshold;             /* Expression: 2
                                        * Referenced by: '<S75>/Switch'
                                        */
  real_T PortA_P1_Size[2];             /* Computed Parameter: PortA_P1_Size
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P1[8];                  /* Expression: channel
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P2_Size[2];             /* Computed Parameter: PortA_P2_Size
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P2;                     /* Expression: port
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P3_Size[2];             /* Computed Parameter: PortA_P3_Size
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P3[8];                  /* Expression: reset
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P4_Size[2];             /* Computed Parameter: PortA_P4_Size
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P4[8];                  /* Expression: initValue
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P5_Size[2];             /* Computed Parameter: PortA_P5_Size
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P5[3];                  /* Expression: ival
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P6_Size[2];             /* Computed Parameter: PortA_P6_Size
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P6;                     /* Expression: chip
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P7_Size[2];             /* Computed Parameter: PortA_P7_Size
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P7;                     /* Expression: sampletime
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P8_Size[2];             /* Computed Parameter: PortA_P8_Size
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P8;                     /* Expression: slot
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P9_Size[2];             /* Computed Parameter: PortA_P9_Size
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P9;                     /* Expression: control
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P10_Size[2];            /* Computed Parameter: PortA_P10_Size
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T PortA_P10;                    /* Expression: boardType
                                        * Referenced by: '<S75>/Port A'
                                        */
  real_T Constant_Value_e;             /* Expression: 32768
                                        * Referenced by: '<S75>/Constant'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S75>/Memory'
                                        */
  real_T PortB_P1_Size[2];             /* Computed Parameter: PortB_P1_Size
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P1[8];                  /* Expression: channel
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P2_Size[2];             /* Computed Parameter: PortB_P2_Size
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P2;                     /* Expression: port
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P3_Size[2];             /* Computed Parameter: PortB_P3_Size
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P3[8];                  /* Expression: reset
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P4_Size[2];             /* Computed Parameter: PortB_P4_Size
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P4[8];                  /* Expression: initValue
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P5_Size[2];             /* Computed Parameter: PortB_P5_Size
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P5[3];                  /* Expression: ival
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P6_Size[2];             /* Computed Parameter: PortB_P6_Size
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P6;                     /* Expression: chip
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P7_Size[2];             /* Computed Parameter: PortB_P7_Size
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P7;                     /* Expression: sampletime
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P8_Size[2];             /* Computed Parameter: PortB_P8_Size
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P8;                     /* Expression: slot
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P9_Size[2];             /* Computed Parameter: PortB_P9_Size
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P9;                     /* Expression: control
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P10_Size[2];            /* Computed Parameter: PortB_P10_Size
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T PortB_P10;                    /* Expression: boardType
                                        * Referenced by: '<S75>/Port B'
                                        */
  real_T xPCTargetTime_P1_Size_n[2];   /* Computed Parameter: xPCTargetTime_P1_Size_n
                                        * Referenced by: '<S75>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1_b;           /* Expression: func
                                        * Referenced by: '<S75>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size_j[2];   /* Computed Parameter: xPCTargetTime_P2_Size_j
                                        * Referenced by: '<S75>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_n;           /* Expression: ts
                                        * Referenced by: '<S75>/xPC Target  Time '
                                        */
  real_T Receive_P1_Size[2];           /* Computed Parameter: Receive_P1_Size
                                        * Referenced by: '<S5>/Receive'
                                        */
  real_T Receive_P1[7];                /* Computed Parameter: Receive_P1
                                        * Referenced by: '<S5>/Receive'
                                        */
  real_T Receive_P2_Size[2];           /* Computed Parameter: Receive_P2_Size
                                        * Referenced by: '<S5>/Receive'
                                        */
  real_T Receive_P2;                   /* Expression: ipPort
                                        * Referenced by: '<S5>/Receive'
                                        */
  real_T Receive_P3_Size[2];           /* Computed Parameter: Receive_P3_Size
                                        * Referenced by: '<S5>/Receive'
                                        */
  real_T Receive_P3;                   /* Expression: width
                                        * Referenced by: '<S5>/Receive'
                                        */
  real_T Receive_P4_Size[2];           /* Computed Parameter: Receive_P4_Size
                                        * Referenced by: '<S5>/Receive'
                                        */
  real_T Receive_P4;                   /* Expression: sampletime
                                        * Referenced by: '<S5>/Receive'
                                        */
  real_T Receive_P5_Size[2];           /* Computed Parameter: Receive_P5_Size
                                        * Referenced by: '<S5>/Receive'
                                        */
  real_T Receive_P5;                   /* Expression: vblLen
                                        * Referenced by: '<S5>/Receive'
                                        */
  real_T UseNeuralControl_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/Use Neural Control'
                                        */
  real_T yoffset_Value;                /* Expression: 32
                                        * Referenced by: '<S77>/yoffset'
                                        */
  real_T PCI6025EAD_P1_Size[2];        /* Computed Parameter: PCI6025EAD_P1_Size
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P1[6];             /* Expression: channel
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P2_Size[2];        /* Computed Parameter: PCI6025EAD_P2_Size
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P2[6];             /* Expression: range
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P3_Size[2];        /* Computed Parameter: PCI6025EAD_P3_Size
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P3[6];             /* Expression: coupling
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P4_Size[2];        /* Computed Parameter: PCI6025EAD_P4_Size
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P4;                /* Expression: sampletime
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P5_Size[2];        /* Computed Parameter: PCI6025EAD_P5_Size
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P5;                /* Expression: slot
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P6_Size[2];        /* Computed Parameter: PCI6025EAD_P6_Size
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P6;                /* Expression: boardType
                                        * Referenced by: '<S14>/PCI-6025E AD'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S78>/Unit Delay1'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 49
                                        * Referenced by: '<S78>/Gain'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 1/50
                                        * Referenced by: '<S78>/Gain1'
                                        */
  real_T Memory_X0_j;                  /* Expression: 0
                                        * Referenced by: '<S78>/Memory'
                                        */
  real_T LoadCellYCoef1_Value;         /* Expression: -.2059
                                        * Referenced by: '<S14>/LoadCellYCoef1'
                                        */
  real_T LoadCellYCoef2_Value;         /* Expression: 7.1801
                                        * Referenced by: '<S14>/LoadCellYCoef2'
                                        */
  real_T LoadCellYCoef3_Value;         /* Expression: -.0804
                                        * Referenced by: '<S14>/LoadCellYCoef3'
                                        */
  real_T LoadCellYCoef4_Value;         /* Expression: -3.591
                                        * Referenced by: '<S14>/LoadCellYCoef4'
                                        */
  real_T LoadCellYCoef5_Value;         /* Expression: 0.0641
                                        * Referenced by: '<S14>/LoadCellYCoef5'
                                        */
  real_T LoadCellYCoef6_Value;         /* Expression: -3.6077
                                        * Referenced by: '<S14>/LoadCellYCoef6'
                                        */
  real_T Gain3_Gain_o;                 /* Expression: -1
                                        * Referenced by: '<S14>/Gain3'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S72>/Unit Delay'
                                        */
  real_T Gain_Gain_i4;                 /* Expression: 16
                                        * Referenced by: '<S72>/Gain'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 1/17
                                        * Referenced by: '<S72>/Gain1'
                                        */
  real_T LoadCellXCoef1_Value;         /* Expression: -.0129
                                        * Referenced by: '<S14>/LoadCellXCoef1'
                                        */
  real_T LoadCellXCoef2_Value;         /* Expression: -.0254
                                        * Referenced by: '<S14>/LoadCellXCoef2'
                                        */
  real_T LoadCellXCoef3_Value;         /* Expression: -.1018
                                        * Referenced by: '<S14>/LoadCellXCoef3'
                                        */
  real_T LoadCellXCoef4_Value;         /* Expression: -6.2876
                                        * Referenced by: '<S14>/LoadCellXCoef4'
                                        */
  real_T LoadCellXCoef5_Value;         /* Expression: -.1127
                                        * Referenced by: '<S14>/LoadCellXCoef5'
                                        */
  real_T LoadCellXCoef6_Value;         /* Expression: 6.2163
                                        * Referenced by: '<S14>/LoadCellXCoef6'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: -1
                                        * Referenced by: '<S14>/Gain2'
                                        */
  real_T UnitDelay_InitialCondition_o; /* Expression: 0
                                        * Referenced by: '<S71>/Unit Delay'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 16
                                        * Referenced by: '<S71>/Gain'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 1/17
                                        * Referenced by: '<S71>/Gain1'
                                        */
  real_T PCIQUAD041_P1_Size[2];        /* Computed Parameter: PCIQUAD041_P1_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P1;                /* Expression: convbaseaddr
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P2_Size[2];        /* Computed Parameter: PCIQUAD041_P2_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P2;                /* Expression: channel
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P3_Size[2];        /* Computed Parameter: PCIQUAD041_P3_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P3;                /* Expression: resetmode
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P4_Size[2];        /* Computed Parameter: PCIQUAD041_P4_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P4;                /* Expression: polarity
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P5_Size[2];        /* Computed Parameter: PCIQUAD041_P5_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P5;                /* Expression: mode
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P6_Size[2];        /* Computed Parameter: PCIQUAD041_P6_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P6;                /* Expression: limit
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P7_Size[2];        /* Computed Parameter: PCIQUAD041_P7_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P7;                /* Expression: range
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P8_Size[2];        /* Computed Parameter: PCIQUAD041_P8_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P8;                /* Expression: speed
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P9_Size[2];        /* Computed Parameter: PCIQUAD041_P9_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P9;                /* Expression: prescale
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P10_Size[2];       /* Computed Parameter: PCIQUAD041_P10_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P10;               /* Expression: ts
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P11_Size[2];       /* Computed Parameter: PCIQUAD041_P11_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P11;               /* Expression: boardtype
                                        * Referenced by: '<S14>/PCI-QUAD04 1'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: -3.490658e-4
                                        * Referenced by: '<S14>/Gain1'
                                        */
  real_T elbowOffset_Value;            /* Expression: 0
                                        * Referenced by: '<S14>/elbowOffset'
                                        */
  real_T xoffset_Value;                /* Expression: 1
                                        * Referenced by: '<S77>/xoffset'
                                        */
  real_T AngleOffset_Value;            /* Expression: 0
                                        * Referenced by: '<S74>/AngleOffset'
                                        */
  real_T IsometricMode_Value;          /* Expression: 0
                                        * Referenced by: '<S14>/IsometricMode'
                                        */
  real_T PCIQUAD04_P1_Size[2];         /* Computed Parameter: PCIQUAD04_P1_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P1;                 /* Expression: convbaseaddr
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P2_Size[2];         /* Computed Parameter: PCIQUAD04_P2_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P2;                 /* Expression: channel
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P3_Size[2];         /* Computed Parameter: PCIQUAD04_P3_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P3;                 /* Expression: resetmode
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P4_Size[2];         /* Computed Parameter: PCIQUAD04_P4_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P4;                 /* Expression: polarity
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P5_Size[2];         /* Computed Parameter: PCIQUAD04_P5_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P5;                 /* Expression: mode
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P6_Size[2];         /* Computed Parameter: PCIQUAD04_P6_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P6;                 /* Expression: limit
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P7_Size[2];         /* Computed Parameter: PCIQUAD04_P7_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P7;                 /* Expression: range
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P8_Size[2];         /* Computed Parameter: PCIQUAD04_P8_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P8;                 /* Expression: speed
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P9_Size[2];         /* Computed Parameter: PCIQUAD04_P9_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P9;                 /* Expression: prescale
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P10_Size[2];        /* Computed Parameter: PCIQUAD04_P10_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P10;                /* Expression: ts
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P11_Size[2];        /* Computed Parameter: PCIQUAD04_P11_Size
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P11;                /* Expression: boardtype
                                        * Referenced by: '<S14>/PCI-QUAD04 '
                                        */
  real_T Gain_Gain_b;                  /* Expression: 3.490658e-4
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T shoulderOffset_Value;         /* Expression: 0
                                        * Referenced by: '<S14>/shoulderOffset'
                                        */
  real_T L1_Value;                     /* Expression: 24
                                        * Referenced by: '<S77>/L1'
                                        */
  real_T L2_Value;                     /* Expression: 23.5
                                        * Referenced by: '<S77>/L2'
                                        */
  real_T AngleOffset_Value_n;          /* Expression: 0
                                        * Referenced by: '<S73>/AngleOffset'
                                        */
  real_T Load_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/Load'
                                        */
  real_T x_InitialCondition;           /* Expression: .1
                                        * Referenced by: '<S24>/x'
                                        */
  real_T x_InitialCondition_d;         /* Expression: .1
                                        * Referenced by: '<S25>/x'
                                        */
  real_T x_InitialCondition_p;         /* Expression: .1
                                        * Referenced by: '<S26>/x'
                                        */
  real_T x_InitialCondition_c;         /* Expression: .1
                                        * Referenced by: '<S27>/x'
                                        */
  real_T Gain_Gain_du;                 /* Expression: -1
                                        * Referenced by: '<S77>/Gain'
                                        */
  real_T Gain1_Gain_bo;                /* Expression: -1
                                        * Referenced by: '<S77>/Gain1'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: -1
                                        * Referenced by: '<S77>/Gain2'
                                        */
  real_T UseTachs_Value;               /* Expression: 0
                                        * Referenced by: '<S11>/UseTachs'
                                        */
  real_T dG_Gain;                      /* Expression: 1
                                        * Referenced by: '<S69>/dG'
                                        */
  real_T dG_Gain_p;                    /* Expression: 1
                                        * Referenced by: '<S70>/dG'
                                        */
  real_T Switch_Threshold_b;           /* Expression: .5
                                        * Referenced by: '<S11>/Switch'
                                        */
  real_T Load_Value_e;                 /* Expression: 0
                                        * Referenced by: '<S2>/Load'
                                        */
  real_T x_InitialCondition_a;         /* Expression: .1
                                        * Referenced by: '<S18>/x'
                                        */
  real_T x_InitialCondition_m;         /* Expression: .1
                                        * Referenced by: '<S19>/x'
                                        */
  real_T x_InitialCondition_j;         /* Expression: .1
                                        * Referenced by: '<S20>/x'
                                        */
  real_T x_InitialCondition_g;         /* Expression: .1
                                        * Referenced by: '<S21>/x'
                                        */
  real_T BehaviorCOBump_P1_Size[2];    /* Computed Parameter: BehaviorCOBump_P1_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P1;            /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P2_Size[2];    /* Computed Parameter: BehaviorCOBump_P2_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P2;            /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P3_Size[2];    /* Computed Parameter: BehaviorCOBump_P3_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P3;            /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P4_Size[2];    /* Computed Parameter: BehaviorCOBump_P4_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P4;            /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P5_Size[2];    /* Computed Parameter: BehaviorCOBump_P5_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P5;            /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P6_Size[2];    /* Computed Parameter: BehaviorCOBump_P6_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P6;            /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P7_Size[2];    /* Computed Parameter: BehaviorCOBump_P7_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P7;            /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P8_Size[2];    /* Computed Parameter: BehaviorCOBump_P8_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P8;            /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P9_Size[2];    /* Computed Parameter: BehaviorCOBump_P9_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P9;            /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P10_Size[2];   /* Computed Parameter: BehaviorCOBump_P10_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P10;           /* Expression: 3
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P11_Size[2];   /* Computed Parameter: BehaviorCOBump_P11_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P11;           /* Expression: 10
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P12_Size[2];   /* Computed Parameter: BehaviorCOBump_P12_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P12;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P13_Size[2];   /* Computed Parameter: BehaviorCOBump_P13_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P13;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P14_Size[2];   /* Computed Parameter: BehaviorCOBump_P14_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P14;           /* Expression: 5
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P15_Size[2];   /* Computed Parameter: BehaviorCOBump_P15_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P15;           /* Expression: 10
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P16_Size[2];   /* Computed Parameter: BehaviorCOBump_P16_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P16;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P17_Size[2];   /* Computed Parameter: BehaviorCOBump_P17_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P17;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P18_Size[2];   /* Computed Parameter: BehaviorCOBump_P18_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P18;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P19_Size[2];   /* Computed Parameter: BehaviorCOBump_P19_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P19;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P20_Size[2];   /* Computed Parameter: BehaviorCOBump_P20_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P20;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P21_Size[2];   /* Computed Parameter: BehaviorCOBump_P21_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P21;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P22_Size[2];   /* Computed Parameter: BehaviorCOBump_P22_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P22;           /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P23_Size[2];   /* Computed Parameter: BehaviorCOBump_P23_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P23;           /* Expression: 1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P24_Size[2];   /* Computed Parameter: BehaviorCOBump_P24_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P24;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P25_Size[2];   /* Computed Parameter: BehaviorCOBump_P25_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P25;           /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P26_Size[2];   /* Computed Parameter: BehaviorCOBump_P26_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P26;           /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P27_Size[2];   /* Computed Parameter: BehaviorCOBump_P27_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P27;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P28_Size[2];   /* Computed Parameter: BehaviorCOBump_P28_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P28;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P29_Size[2];   /* Computed Parameter: BehaviorCOBump_P29_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P29;           /* Expression: 5
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P30_Size[2];   /* Computed Parameter: BehaviorCOBump_P30_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P30;           /* Expression: 10
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P31_Size[2];   /* Computed Parameter: BehaviorCOBump_P31_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P31;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P32_Size[2];   /* Computed Parameter: BehaviorCOBump_P32_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P32;           /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P33_Size[2];   /* Computed Parameter: BehaviorCOBump_P33_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P33;           /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P34_Size[2];   /* Computed Parameter: BehaviorCOBump_P34_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P34;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P35_Size[2];   /* Computed Parameter: BehaviorCOBump_P35_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P35;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P36_Size[2];   /* Computed Parameter: BehaviorCOBump_P36_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P36;           /* Expression: 5
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P37_Size[2];   /* Computed Parameter: BehaviorCOBump_P37_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P37;           /* Expression: 10
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P38_Size[2];   /* Computed Parameter: BehaviorCOBump_P38_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P38;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P39_Size[2];   /* Computed Parameter: BehaviorCOBump_P39_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P39;           /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P40_Size[2];   /* Computed Parameter: BehaviorCOBump_P40_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P40;           /* Expression: .1
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P41_Size[2];   /* Computed Parameter: BehaviorCOBump_P41_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P41;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P42_Size[2];   /* Computed Parameter: BehaviorCOBump_P42_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P42;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P43_Size[2];   /* Computed Parameter: BehaviorCOBump_P43_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P43;           /* Expression: 5
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P44_Size[2];   /* Computed Parameter: BehaviorCOBump_P44_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P44;           /* Expression: 10
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P45_Size[2];   /* Computed Parameter: BehaviorCOBump_P45_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P45;           /* Expression: 0
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P46_Size[2];   /* Computed Parameter: BehaviorCOBump_P46_Size
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T BehaviorCOBump_P46;           /* Expression: 3
                                        * Referenced by: '<Root>/Behavior CO Bump'
                                        */
  real_T TargetCount_Value;            /* Expression: 17
                                        * Referenced by: '<Root>/TargetCount'
                                        */
  real_T Send_P1_Size[2];              /* Computed Parameter: Send_P1_Size
                                        * Referenced by: '<S8>/Send'
                                        */
  real_T Send_P1[11];                  /* Computed Parameter: Send_P1
                                        * Referenced by: '<S8>/Send'
                                        */
  real_T Send_P2_Size[2];              /* Computed Parameter: Send_P2_Size
                                        * Referenced by: '<S8>/Send'
                                        */
  real_T Send_P2;                      /* Expression: ipPort
                                        * Referenced by: '<S8>/Send'
                                        */
  real_T Send_P3_Size[2];              /* Computed Parameter: Send_P3_Size
                                        * Referenced by: '<S8>/Send'
                                        */
  real_T Send_P3;                      /* Expression: localPort
                                        * Referenced by: '<S8>/Send'
                                        */
  real_T Send_P4_Size[2];              /* Computed Parameter: Send_P4_Size
                                        * Referenced by: '<S8>/Send'
                                        */
  real_T Send_P4;                      /* Expression: sampletime
                                        * Referenced by: '<S8>/Send'
                                        */
  real_T Send_P5_Size[2];              /* Computed Parameter: Send_P5_Size
                                        * Referenced by: '<S8>/Send'
                                        */
  real_T Send_P5;                      /* Expression: vblLen
                                        * Referenced by: '<S8>/Send'
                                        */
  real_T DisableBoundingBox_Value;     /* Expression: 0
                                        * Referenced by: '<S1>/DisableBoundingBox'
                                        */
  real_T XLowLimit_Value;              /* Expression: -30
                                        * Referenced by: '<S1>/XLowLimit'
                                        */
  real_T XHighLimit_Value;             /* Expression: 25
                                        * Referenced by: '<S1>/XHighLimit'
                                        */
  real_T YHighLimit_Value;             /* Expression: -46
                                        * Referenced by: '<S1>/YHighLimit'
                                        */
  real_T YLowLimit_Value;              /* Expression: -22
                                        * Referenced by: '<S1>/YLowLimit'
                                        */
  real_T rho_Value;                    /* Expression: 28
                                        * Referenced by: '<S18>/rho'
                                        */
  real_T z_InitialCondition;           /* Expression: .1
                                        * Referenced by: '<S18>/z'
                                        */
  real_T beta_Value;                   /* Expression: 8/3
                                        * Referenced by: '<S18>/beta'
                                        */
  real_T timescale_Value;              /* Expression: .0001
                                        * Referenced by: '<S18>/timescale'
                                        */
  real_T sigma_Value;                  /* Expression: 10
                                        * Referenced by: '<S18>/sigma'
                                        */
  real_T rho_Value_k;                  /* Expression: 28
                                        * Referenced by: '<S19>/rho'
                                        */
  real_T z_InitialCondition_i;         /* Expression: .1
                                        * Referenced by: '<S19>/z'
                                        */
  real_T beta_Value_d;                 /* Expression: 8/3
                                        * Referenced by: '<S19>/beta'
                                        */
  real_T timescale_Value_a;            /* Expression: .0001
                                        * Referenced by: '<S19>/timescale'
                                        */
  real_T sigma_Value_g;                /* Expression: 10
                                        * Referenced by: '<S19>/sigma'
                                        */
  real_T rho_Value_c;                  /* Expression: 28
                                        * Referenced by: '<S20>/rho'
                                        */
  real_T z_InitialCondition_f;         /* Expression: .1
                                        * Referenced by: '<S20>/z'
                                        */
  real_T beta_Value_a;                 /* Expression: 8/3
                                        * Referenced by: '<S20>/beta'
                                        */
  real_T timescale_Value_i;            /* Expression: .0001
                                        * Referenced by: '<S20>/timescale'
                                        */
  real_T sigma_Value_gy;               /* Expression: 10
                                        * Referenced by: '<S20>/sigma'
                                        */
  real_T rho_Value_e;                  /* Expression: 28
                                        * Referenced by: '<S21>/rho'
                                        */
  real_T z_InitialCondition_n;         /* Expression: .1
                                        * Referenced by: '<S21>/z'
                                        */
  real_T beta_Value_o;                 /* Expression: 8/3
                                        * Referenced by: '<S21>/beta'
                                        */
  real_T timescale_Value_h;            /* Expression: .0001
                                        * Referenced by: '<S21>/timescale'
                                        */
  real_T sigma_Value_a;                /* Expression: 10
                                        * Referenced by: '<S21>/sigma'
                                        */
  real_T rho_Value_c0;                 /* Expression: 28
                                        * Referenced by: '<S24>/rho'
                                        */
  real_T z_InitialCondition_p;         /* Expression: .1
                                        * Referenced by: '<S24>/z'
                                        */
  real_T beta_Value_k;                 /* Expression: 8/3
                                        * Referenced by: '<S24>/beta'
                                        */
  real_T timescale_Value_b;            /* Expression: .0001
                                        * Referenced by: '<S24>/timescale'
                                        */
  real_T sigma_Value_ax;               /* Expression: 10
                                        * Referenced by: '<S24>/sigma'
                                        */
  real_T rho_Value_h;                  /* Expression: 28
                                        * Referenced by: '<S25>/rho'
                                        */
  real_T z_InitialCondition_o;         /* Expression: .1
                                        * Referenced by: '<S25>/z'
                                        */
  real_T beta_Value_ko;                /* Expression: 8/3
                                        * Referenced by: '<S25>/beta'
                                        */
  real_T timescale_Value_ab;           /* Expression: .0001
                                        * Referenced by: '<S25>/timescale'
                                        */
  real_T sigma_Value_k;                /* Expression: 10
                                        * Referenced by: '<S25>/sigma'
                                        */
  real_T rho_Value_cw;                 /* Expression: 28
                                        * Referenced by: '<S26>/rho'
                                        */
  real_T z_InitialCondition_d;         /* Expression: .1
                                        * Referenced by: '<S26>/z'
                                        */
  real_T beta_Value_i;                 /* Expression: 8/3
                                        * Referenced by: '<S26>/beta'
                                        */
  real_T timescale_Value_p;            /* Expression: .0001
                                        * Referenced by: '<S26>/timescale'
                                        */
  real_T sigma_Value_h;                /* Expression: 10
                                        * Referenced by: '<S26>/sigma'
                                        */
  real_T rho_Value_f;                  /* Expression: 28
                                        * Referenced by: '<S27>/rho'
                                        */
  real_T z_InitialCondition_fg;        /* Expression: .1
                                        * Referenced by: '<S27>/z'
                                        */
  real_T beta_Value_ix;                /* Expression: 8/3
                                        * Referenced by: '<S27>/beta'
                                        */
  real_T timescale_Value_j;            /* Expression: .0001
                                        * Referenced by: '<S27>/timescale'
                                        */
  real_T sigma_Value_hl;               /* Expression: 10
                                        * Referenced by: '<S27>/sigma'
                                        */
  real_T IsometricMode_Value_i;        /* Expression: 0
                                        * Referenced by: '<S4>/IsometricMode'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T DiscreteFIRFilter_InitialStates;/* Expression: 0
                                          * Referenced by: '<S6>/Discrete FIR Filter'
                                          */
  real_T DiscreteFIRFilter_Coefficients[30];/* Expression: [0.0069    0.0195    0.0106    0.0194    0.0217    0.0270    0.0313    0.0360    0.0404    0.0445    0.0482    0.0513    0.0538    0.0554    0.0563    0.0563    0.0554 0.0538    0.0513    0.0482    0.0445    0.0404    0.0360    0.0313    0.0270    0.0217    0.0194    0.0106    0.0195    0.0069]
                                             * Referenced by: '<S6>/Discrete FIR Filter'
                                             */
  real_T RecenterFlag_Value;           /* Expression: 1
                                        * Referenced by: '<S6>/RecenterFlag'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T Constant_Value_nu;            /* Expression: 0
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T MG1_Gain;                     /* Expression: 0.075
                                        * Referenced by: '<S4>/MG1'
                                        */
  real_T MG2_Gain;                     /* Expression: -0.0915
                                        * Referenced by: '<S4>/MG2'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T PCI6025E_P1_Size_j[2];        /* Computed Parameter: PCI6025E_P1_Size_j
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P1_e[2];             /* Expression: channel
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_Size_l[2];        /* Computed Parameter: PCI6025E_P2_Size_l
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_n[2];             /* Expression: range
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_Size_e[2];        /* Computed Parameter: PCI6025E_P3_Size_e
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_b[2];             /* Expression: reset
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_Size_j[2];        /* Computed Parameter: PCI6025E_P4_Size_j
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_e[2];             /* Expression: initValue
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_Size_m[2];        /* Computed Parameter: PCI6025E_P5_Size_m
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_i;                /* Expression: sampletime
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_Size_o[2];        /* Computed Parameter: PCI6025E_P6_Size_o
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_f;                /* Expression: slot
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_Size_o[2];        /* Computed Parameter: PCI6025E_P7_Size_o
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_d;                /* Expression: boardType
                                        * Referenced by: '<S4>/PCI-6025E '
                                        */
  real_T UniformRandomNumber_Minimum;  /* Expression: 0
                                        * Referenced by: '<S7>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Maximum;  /* Expression: 100
                                        * Referenced by: '<S7>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * Referenced by: '<S7>/Uniform Random Number'
                                        */
  real_T JackpotChance_Value;          /* Expression: 0
                                        * Referenced by: '<S7>/JackpotChance'
                                        */
  real_T Gain_Gain_o0;                 /* Expression: .5
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: .5
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T FOffset_Value[6];             /* Expression: [-.73 .08 .21 -.23 .25 .44]
                                        * Referenced by: '<S78>/F Offset'
                                        */
  int32_T DiscreteTimeIntegrator_IC;   /* Computed Parameter: DiscreteTimeIntegrator_IC
                                        * Referenced by: '<S78>/Discrete-Time Integrator'
                                        */
  int32_T DiscreteTimeIntegrator_UpperSat;/* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                                           * Referenced by: '<S78>/Discrete-Time Integrator'
                                           */
  int32_T DiscreteTimeIntegrator_LowerSat;/* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                                           * Referenced by: '<S78>/Discrete-Time Integrator'
                                           */
  uint32_T PacketSpec_Value;           /* Computed Parameter: PacketSpec_Value
                                        * Referenced by: '<S8>/Packet Spec'
                                        */
  uint32_T NaNupperbytes_Value;        /* Computed Parameter: NaNupperbytes_Value
                                        * Referenced by: '<S8>/NaN upper bytes'
                                        */
  boolean_T Memory_X0_b;               /* Computed Parameter: Memory_X0_b
                                        * Referenced by: '<S33>/Memory'
                                        */
  boolean_T Memory_X0_p;               /* Computed Parameter: Memory_X0_p
                                        * Referenced by: '<S4>/Memory'
                                        */
  boolean_T Memory_X0_g;               /* Computed Parameter: Memory_X0_g
                                        * Referenced by: '<S45>/Memory'
                                        */
  boolean_T Memory_X0_e;               /* Computed Parameter: Memory_X0_e
                                        * Referenced by: '<S49>/Memory'
                                        */
  boolean_T Constant_Value_ow;         /* Computed Parameter: Constant_Value_ow
                                        * Referenced by: '<S65>/Constant'
                                        */
  boolean_T Memory_X0_b5;              /* Computed Parameter: Memory_X0_b5
                                        * Referenced by: '<S47>/Memory'
                                        */
  boolean_T Constant_Value_ch;         /* Computed Parameter: Constant_Value_ch
                                        * Referenced by: '<S61>/Constant'
                                        */
  boolean_T Constant_Value_dl;         /* Computed Parameter: Constant_Value_dl
                                        * Referenced by: '<S52>/Constant'
                                        */
  boolean_T Memory_X0_a;               /* Computed Parameter: Memory_X0_a
                                        * Referenced by: '<S46>/Memory'
                                        */
  boolean_T Constant_Value_f;          /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S51>/Constant'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S44>/Logic'
                                        */
  P_SampleandHold_CO_bump_T SampleandHold;/* '<S67>/Sample and Hold' */
  P_SampleandHold_CO_bump_T SampleandHold_j;/* '<S7>/Sample and Hold' */
};

/* Real-time Model Data Structure */
struct tag_RTM_CO_bump_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[3];
    SimStruct childSFunctions[16];
    SimStruct *childSFunctionPtrs[16];
    struct _ssBlkInfo2 blkInfo2[16];
    struct _ssSFcnModelMethods2 methods2[16];
    struct _ssSFcnModelMethods3 methods3[16];
    struct _ssStatesInfo2 statesInfo2[16];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[8];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[8];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[1];
      real_T const *UPtrs4[1];
      real_T const *UPtrs5[1];
      real_T const *UPtrs6[1];
      real_T const *UPtrs7[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[1];
      struct _ssPortOutputs outputPortInfo[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[8];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[8];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[1];
      real_T const *UPtrs4[1];
      real_T const *UPtrs5[1];
      real_T const *UPtrs6[1];
      real_T const *UPtrs7[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[11];
      mxArray *params[11];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[11];
      mxArray *params[11];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[7];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[2];
      real_T const *UPtrs3[2];
      real_T const *UPtrs4[2];
      real_T const *UPtrs5[2];
      real_T const *UPtrs6[2];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[46];
      mxArray *params[46];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn14;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn15;
  } NonInlinedSFcns;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_CO_bump_T CO_bump_P;

/* Block signals (auto storage) */
extern B_CO_bump_T CO_bump_B;

/* Block states (auto storage) */
extern DW_CO_bump_T CO_bump_DW;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* External data declarations for dependent source files */
extern const real_T CO_bump_RGND;      /* real_T ground */

/* Zero-crossing (trigger) state */
extern PrevZCX_CO_bump_T CO_bump_PrevZCX;

/*====================*
 * External functions *
 *====================*/
extern CO_bump_rtModel *CO_bump(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_CO_bump_T *const CO_bump_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CO_bump'
 * '<S1>'   : 'CO_bump/BoundingBox'
 * '<S2>'   : 'CO_bump/Catch Force Generator'
 * '<S3>'   : 'CO_bump/Force Generator'
 * '<S4>'   : 'CO_bump/Motor Control1'
 * '<S5>'   : 'CO_bump/Neural Position Subsystem'
 * '<S6>'   : 'CO_bump/Recentering Subsystem1'
 * '<S7>'   : 'CO_bump/RewardSbs'
 * '<S8>'   : 'CO_bump/SendPacketToGraphics'
 * '<S9>'   : 'CO_bump/Status'
 * '<S10>'  : 'CO_bump/Target Peek'
 * '<S11>'  : 'CO_bump/Velocity Calculation'
 * '<S12>'  : 'CO_bump/Version Display'
 * '<S13>'  : 'CO_bump/WordSbs'
 * '<S14>'  : 'CO_bump/XY Position Subsystem1'
 * '<S15>'  : 'CO_bump/Xpos'
 * '<S16>'  : 'CO_bump/Catch Force Generator/LorentzForce'
 * '<S17>'  : 'CO_bump/Catch Force Generator/ViscLoadSubsystem'
 * '<S18>'  : 'CO_bump/Catch Force Generator/LorentzForce/Lorentz'
 * '<S19>'  : 'CO_bump/Catch Force Generator/LorentzForce/Lorentz1'
 * '<S20>'  : 'CO_bump/Catch Force Generator/LorentzForce/Lorentz2'
 * '<S21>'  : 'CO_bump/Catch Force Generator/LorentzForce/Lorentz3'
 * '<S22>'  : 'CO_bump/Force Generator/LorentzForce'
 * '<S23>'  : 'CO_bump/Force Generator/ViscLoadSubsystem'
 * '<S24>'  : 'CO_bump/Force Generator/LorentzForce/Lorentz'
 * '<S25>'  : 'CO_bump/Force Generator/LorentzForce/Lorentz1'
 * '<S26>'  : 'CO_bump/Force Generator/LorentzForce/Lorentz2'
 * '<S27>'  : 'CO_bump/Force Generator/LorentzForce/Lorentz3'
 * '<S28>'  : 'CO_bump/Motor Control1/Compare To Constant'
 * '<S29>'  : 'CO_bump/Motor Control1/Compare To Constant1'
 * '<S30>'  : 'CO_bump/Motor Control1/Compare To Zero'
 * '<S31>'  : 'CO_bump/Motor Control1/Compare To Zero1'
 * '<S32>'  : 'CO_bump/Motor Control1/Force//Torque Transform'
 * '<S33>'  : 'CO_bump/Motor Control1/Schmidt'
 * '<S34>'  : 'CO_bump/Motor Control1/Xpos'
 * '<S35>'  : 'CO_bump/Motor Control1/Schmidt/Compare To Zero'
 * '<S36>'  : 'CO_bump/Motor Control1/Schmidt/Enabled Subsystem'
 * '<S37>'  : 'CO_bump/Recentering Subsystem1/Compare To Zero'
 * '<S38>'  : 'CO_bump/Recentering Subsystem1/Compare To Zero1'
 * '<S39>'  : 'CO_bump/Recentering Subsystem1/Compare To Zero2'
 * '<S40>'  : 'CO_bump/Recentering Subsystem1/Falling Edge'
 * '<S41>'  : 'CO_bump/Recentering Subsystem1/Falling Edge1'
 * '<S42>'  : 'CO_bump/Recentering Subsystem1/No Movement'
 * '<S43>'  : 'CO_bump/Recentering Subsystem1/PD Controller'
 * '<S44>'  : 'CO_bump/Recentering Subsystem1/S-R Flip-Flop'
 * '<S45>'  : 'CO_bump/Recentering Subsystem1/Schmidt1'
 * '<S46>'  : 'CO_bump/Recentering Subsystem1/Schmidt2'
 * '<S47>'  : 'CO_bump/Recentering Subsystem1/Schmidt3'
 * '<S48>'  : 'CO_bump/Recentering Subsystem1/Start Moving'
 * '<S49>'  : 'CO_bump/Recentering Subsystem1/Timer'
 * '<S50>'  : 'CO_bump/Recentering Subsystem1/Xpos1'
 * '<S51>'  : 'CO_bump/Recentering Subsystem1/Falling Edge/Nonpositive'
 * '<S52>'  : 'CO_bump/Recentering Subsystem1/Falling Edge1/Nonpositive'
 * '<S53>'  : 'CO_bump/Recentering Subsystem1/No Movement/Compare To Constant2'
 * '<S54>'  : 'CO_bump/Recentering Subsystem1/No Movement/Compare To Constant3'
 * '<S55>'  : 'CO_bump/Recentering Subsystem1/Schmidt1/Compare To Zero'
 * '<S56>'  : 'CO_bump/Recentering Subsystem1/Schmidt1/Enabled Subsystem'
 * '<S57>'  : 'CO_bump/Recentering Subsystem1/Schmidt2/Compare To Zero'
 * '<S58>'  : 'CO_bump/Recentering Subsystem1/Schmidt2/Enabled Subsystem'
 * '<S59>'  : 'CO_bump/Recentering Subsystem1/Schmidt3/Compare To Zero'
 * '<S60>'  : 'CO_bump/Recentering Subsystem1/Schmidt3/Enabled Subsystem'
 * '<S61>'  : 'CO_bump/Recentering Subsystem1/Start Moving/Nonpositive'
 * '<S62>'  : 'CO_bump/Recentering Subsystem1/Timer/Compare To Zero'
 * '<S63>'  : 'CO_bump/Recentering Subsystem1/Timer/Detect Fall Nonpositive'
 * '<S64>'  : 'CO_bump/Recentering Subsystem1/Timer/Enabled Subsystem'
 * '<S65>'  : 'CO_bump/Recentering Subsystem1/Timer/Detect Fall Nonpositive/Nonpositive'
 * '<S66>'  : 'CO_bump/RewardSbs/Sample and Hold'
 * '<S67>'  : 'CO_bump/RewardSbs/Schmidt'
 * '<S68>'  : 'CO_bump/RewardSbs/Schmidt/Sample and Hold'
 * '<S69>'  : 'CO_bump/Velocity Calculation/Pos2VelX'
 * '<S70>'  : 'CO_bump/Velocity Calculation/Pos2VelY'
 * '<S71>'  : 'CO_bump/XY Position Subsystem1/Avg'
 * '<S72>'  : 'CO_bump/XY Position Subsystem1/Avg1'
 * '<S73>'  : 'CO_bump/XY Position Subsystem1/Cursor Rotation'
 * '<S74>'  : 'CO_bump/XY Position Subsystem1/Cursor Rotation1'
 * '<S75>'  : 'CO_bump/XY Position Subsystem1/For Iterator Subsystem'
 * '<S76>'  : 'CO_bump/XY Position Subsystem1/Handle Rotation'
 * '<S77>'  : 'CO_bump/XY Position Subsystem1/Jacobian-Cartesian Transformation'
 * '<S78>'  : 'CO_bump/XY Position Subsystem1/OffsetCalculation'
 * '<S79>'  : 'CO_bump/XY Position Subsystem1/For Iterator Subsystem/Whiltor Subsystem'
 * '<S80>'  : 'CO_bump/XY Position Subsystem1/For Iterator Subsystem/Whiltor Subsystem/Compare To Constant'
 * '<S81>'  : 'CO_bump/XY Position Subsystem1/For Iterator Subsystem/Whiltor Subsystem/Compare To Constant1'
 * '<S82>'  : 'CO_bump/XY Position Subsystem1/OffsetCalculation/Compare To Constant1'
 * '<S83>'  : 'CO_bump/XY Position Subsystem1/OffsetCalculation/NoiseLevel'
 */
#endif                                 /* RTW_HEADER_CO_bump_h_ */
