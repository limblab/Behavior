/*
 * random_walk.h
 *
 * Real-Time Workshop code generation for Simulink model "random_walk.mdl".
 *
 * Model Version              : 1.922
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Jan 09 14:56:49 2008
 */
#ifndef _RTW_HEADER_random_walk_h_
#define _RTW_HEADER_random_walk_h_
#include "rtw_modelmap.h"
#ifndef _random_walk_COMMON_INCLUDES_
# define _random_walk_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <windows.h>
#include <xpcimports.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "rtlibsrc.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rt_atan2.h"
#include "rt_nonfinite.h"
#endif                                 /* _random_walk_COMMON_INCLUDES_ */

#include "random_walk_types.h"

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
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ((rtm)->Timing.mdlref_GlobalTID)
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ((rtm)->Timing.mdlref_GlobalTID = (val))
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ((rtm)->Timing.mdlref_TriggerTID)
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ((rtm)->Timing.mdlref_TriggerTID = (val))
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

#ifndef rtmGetNonsampledZCs
# define rtmGetNonsampledZCs(rtm)      ((rtm)->ModelData.nonsampledZCs)
#endif

#ifndef rtmSetNonsampledZCs
# define rtmSetNonsampledZCs(rtm, val) ((rtm)->ModelData.nonsampledZCs = (val))
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
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
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
# define rtmGetParamIsMalloced(rtm)    ((rtm)->ModelData.paramIsMalloced)
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ((rtm)->ModelData.paramIsMalloced = (val))
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
# define rtmGetRTWRTModelMethodsInfo(rtm) ((rtm)->modelMethodsInfo)
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ((rtm)->modelMethodsInfo = (val))
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
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
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
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
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

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
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
#define random_walk_M                  random_walk_rtM

/* Definition for use in the target main file */
#define random_walk_rtModel            rtModel_random_walk

/* Block signals for system '<S35>/Enabled Subsystem' */
typedef struct {
  real_T In1;                          /* '<S45>/In1' */
} rtB_EnabledSubsystem_random_wal;

/* Block states (auto storage) for system '<S35>/Enabled Subsystem' */
typedef struct {
  int_T EnabledSubsystem_MODE;         /* '<S35>/Enabled Subsystem' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S35>/Enabled Subsystem' */
} rtDW_EnabledSubsystem_random_wa;

/* Block signals (auto storage) */
typedef struct {
  real_T Clock;                        /* '<S10>/Clock' */
  real_T Sum;                          /* '<S10>/Sum' */
  real_T PCIQUAD04;                    /* '<S15>/PCI-QUAD04 ' */
  real_T Gain;                         /* '<S15>/Gain' */
  real_T Sum3;                         /* '<S15>/Sum3' */
  real_T sinlengthofShoulder;          /* '<S59>/sin(length of Shoulder)' */
  real_T PCIQUAD041;                   /* '<S15>/PCI-QUAD04 1' */
  real_T Gain1;                        /* '<S15>/Gain1' */
  real_T Sum1;                         /* '<S15>/Sum1' */
  real_T sinlengthofElbow;             /* '<S59>/sin(length of Elbow)' */
  real_T Sum2;                         /* '<S59>/Sum2' */
  real_T Sum4;                         /* '<S59>/Sum4' */
  real_T coslengthofShoulder;          /* '<S59>/cos(length of Shoulder)' */
  real_T coslengthofElbow;             /* '<S59>/cos(length of Elbow)' */
  real_T Sum3_i;                       /* '<S59>/Sum3' */
  real_T Sum1_g;                       /* '<S59>/Sum1' */
  real_T TrigonometricFunction1;       /* '<S57>/Trigonometric Function1' */
  real_T Sum_h;                        /* '<S57>/Sum' */
  real_T TrigonometricFunction2;       /* '<S57>/Trigonometric Function2' */
  real_T sqrtu1u1u2u2;                 /* '<S57>/sqrt(u[1]*u[1] + u[2]*u[2])' */
  real_T Product1;                     /* '<S57>/Product1' */
  real_T DigitalFilter2;               /* '<S7>/Digital Filter2' */
  real_T Derivative;                   /* '<S7>/Derivative' */
  real_T dG;                           /* '<S7>/dG' */
  real_T DigitalFilter;                /* '<S7>/Digital Filter' */
  real_T TrigonometricFunction;        /* '<S57>/Trigonometric Function' */
  real_T Product;                      /* '<S57>/Product' */
  real_T DigitalFilter2_e;             /* '<S8>/Digital Filter2' */
  real_T Derivative_g;                 /* '<S8>/Derivative' */
  real_T dG_l;                         /* '<S8>/dG' */
  real_T DigitalFilter_m;              /* '<S8>/Digital Filter' */
  real_T Clock_n;                      /* '<S35>/Clock' */
  real_T Clock_j;                      /* '<S37>/Clock' */
  real_T Sum_b;                        /* '<S37>/Sum' */
  real_T Sum_a;                        /* '<S35>/Sum' */
  real_T Clock_jm;                     /* '<S36>/Clock' */
  real_T Abs;                          /* '<S31>/Abs' */
  real_T Abs2;                         /* '<S31>/Abs2' */
  real_T Abs1;                         /* '<S31>/Abs1' */
  real_T Abs3;                         /* '<S31>/Abs3' */
  real_T Sum_k;                        /* '<S36>/Sum' */
  real_T x;                            /* '<S25>/x' */
  real_T x_f;                          /* '<S26>/x' */
  real_T Add;                          /* '<S21>/Add' */
  real_T x_h;                          /* '<S27>/x' */
  real_T x_l;                          /* '<S28>/x' */
  real_T Add1;                         /* '<S21>/Add1' */
  real_T MultiportSwitch[2];           /* '<S4>/Multiport Switch' */
  real_T BehaviorRW_o1[2];             /* '<Root>/Behavior RW' */
  real_T BehaviorRW_o2[4];             /* '<Root>/Behavior RW' */
  real_T BehaviorRW_o3;                /* '<Root>/Behavior RW' */
  real_T BehaviorRW_o4[10];            /* '<Root>/Behavior RW' */
  real_T BehaviorRW_o5;                /* '<Root>/Behavior RW' */
  real_T BehaviorRW_o6[2];             /* '<Root>/Behavior RW' */
  real_T Switch1[2];                   /* '<Root>/Switch1' */
  real_T MG2;                          /* '<Root>/MG2' */
  real_T RateTransition2;              /* '<Root>/Rate Transition2' */
  real_T MG1;                          /* '<Root>/MG1' */
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  real_T ToBits_o1;                    /* '<S14>/ToBits' */
  real_T ToBits_o2;                    /* '<S14>/ToBits' */
  real_T ToBits_o3;                    /* '<S14>/ToBits' */
  real_T ToBits_o4;                    /* '<S14>/ToBits' */
  real_T ToBits_o5;                    /* '<S14>/ToBits' */
  real_T ToBits_o6;                    /* '<S14>/ToBits' */
  real_T ToBits_o7;                    /* '<S14>/ToBits' */
  real_T ToBits_o8;                    /* '<S14>/ToBits' */
  real_T y;                            /* '<S25>/y' */
  real_T Add1_o;                       /* '<S25>/Add1' */
  real_T z;                            /* '<S25>/z' */
  real_T Add3;                         /* '<S25>/Add3' */
  real_T product2;                     /* '<S25>/product2' */
  real_T Add2;                         /* '<S25>/Add2' */
  real_T product3;                     /* '<S25>/product3' */
  real_T product4;                     /* '<S25>/product4' */
  real_T Add4;                         /* '<S25>/Add4' */
  real_T product1;                     /* '<S25>/product1' */
  real_T dX;                           /* '<S25>/dX' */
  real_T AddX;                         /* '<S25>/AddX' */
  real_T dY;                           /* '<S25>/dY' */
  real_T AddX1;                        /* '<S25>/AddX1' */
  real_T dZ;                           /* '<S25>/dZ' */
  real_T AddX2;                        /* '<S25>/AddX2' */
  real_T y_e;                          /* '<S26>/y' */
  real_T Add1_b;                       /* '<S26>/Add1' */
  real_T z_o;                          /* '<S26>/z' */
  real_T Add3_e;                       /* '<S26>/Add3' */
  real_T product2_l;                   /* '<S26>/product2' */
  real_T Add2_b;                       /* '<S26>/Add2' */
  real_T product3_b;                   /* '<S26>/product3' */
  real_T product4_d;                   /* '<S26>/product4' */
  real_T Add4_b;                       /* '<S26>/Add4' */
  real_T product1_f;                   /* '<S26>/product1' */
  real_T dX_m;                         /* '<S26>/dX' */
  real_T AddX_j;                       /* '<S26>/AddX' */
  real_T dY_f;                         /* '<S26>/dY' */
  real_T AddX1_b;                      /* '<S26>/AddX1' */
  real_T dZ_g;                         /* '<S26>/dZ' */
  real_T AddX2_e;                      /* '<S26>/AddX2' */
  real_T y_j;                          /* '<S27>/y' */
  real_T Add1_l;                       /* '<S27>/Add1' */
  real_T z_n;                          /* '<S27>/z' */
  real_T Add3_p;                       /* '<S27>/Add3' */
  real_T product2_g;                   /* '<S27>/product2' */
  real_T Add2_l;                       /* '<S27>/Add2' */
  real_T product3_d;                   /* '<S27>/product3' */
  real_T product4_j;                   /* '<S27>/product4' */
  real_T Add4_k;                       /* '<S27>/Add4' */
  real_T product1_a;                   /* '<S27>/product1' */
  real_T dX_f;                         /* '<S27>/dX' */
  real_T AddX_o;                       /* '<S27>/AddX' */
  real_T dY_b;                         /* '<S27>/dY' */
  real_T AddX1_j;                      /* '<S27>/AddX1' */
  real_T dZ_f;                         /* '<S27>/dZ' */
  real_T AddX2_h;                      /* '<S27>/AddX2' */
  real_T y_o;                          /* '<S28>/y' */
  real_T Add1_n;                       /* '<S28>/Add1' */
  real_T z_j;                          /* '<S28>/z' */
  real_T Add3_a;                       /* '<S28>/Add3' */
  real_T product2_c;                   /* '<S28>/product2' */
  real_T Add2_d;                       /* '<S28>/Add2' */
  real_T product3_i;                   /* '<S28>/product3' */
  real_T product4_p;                   /* '<S28>/product4' */
  real_T Add4_h;                       /* '<S28>/Add4' */
  real_T product1_o;                   /* '<S28>/product1' */
  real_T dX_b;                         /* '<S28>/dX' */
  real_T AddX_jl;                      /* '<S28>/AddX' */
  real_T dY_n;                         /* '<S28>/dY' */
  real_T AddX1_bw;                     /* '<S28>/AddX1' */
  real_T dZ_i;                         /* '<S28>/dZ' */
  real_T AddX2_g;                      /* '<S28>/AddX2' */
  real_T DataTypeConversion;           /* '<S9>/Data Type Conversion' */
  real_T Clock_c;                      /* '<S52>/Clock' */
  real_T Sum_i;                        /* '<S52>/Sum' */
  real_T Add_o;                        /* '<S12>/Add' */
  real_T Add1_f;                       /* '<S12>/Add1' */
  real_T Gain_p;                       /* '<S12>/Gain' */
  real_T Gain1_c;                      /* '<S12>/Gain1' */
  real_T ForIterator;                  /* '<S58>/For Iterator' */
  real_T Add_j;                        /* '<S58>/Add' */
  real_T Add1_oz;                      /* '<S58>/Add1' */
  real_T SerialConverter;              /* '<S58>/SerialConverter' */
  real_T ToBits_o1_n;                  /* '<S58>/ToBits' */
  real_T ToBits_o2_f;                  /* '<S58>/ToBits' */
  real_T ToBits_o3_k;                  /* '<S58>/ToBits' */
  real_T ToBits_o4_n;                  /* '<S58>/ToBits' */
  real_T ToBits_o5_f;                  /* '<S58>/ToBits' */
  real_T ToBits_o6_i;                  /* '<S58>/ToBits' */
  real_T ToBits_o7_f;                  /* '<S58>/ToBits' */
  real_T ToBits_o8_d;                  /* '<S58>/ToBits' */
  real_T xPCTargetTime;                /* '<S58>/xPC Target  Time ' */
  real_T xPCTargetTime_a;              /* '<S60>/xPC Target  Time ' */
  real_T Subtract;                     /* '<S60>/Subtract' */
  real_T ScaleTouSec;                  /* '<S60>/ScaleTouSec' */
  real_T Switch;                       /* '<S60>/Switch' */
  real_T sinlengthofShoulder_d;        /* '<S6>/sin(length of Shoulder)' */
  real_T Product_h;                    /* '<S6>/Product' */
  real_T coslengthofShoulder_l;        /* '<S6>/cos(length of Shoulder)' */
  real_T Product1_e;                   /* '<S6>/Product1' */
  real_T sinlengthofElbow_d;           /* '<S6>/sin(length of Elbow)' */
  real_T Product2;                     /* '<S6>/Product2' */
  real_T coslengthofElbow_m;           /* '<S6>/cos(length of Elbow)' */
  real_T Product3;                     /* '<S6>/Product3' */
  real_T Sum5;                         /* '<S6>/Sum5' */
  real_T Sum6;                         /* '<S6>/Sum6' */
  real_T LorentzForceGain[2];          /* '<S4>/LorentzForceGain' */
  real_T dynamicAngleSwitch;           /* '<S4>/dynamicAngle Switch' */
  real_T sin_e;                        /* '<S22>/sin' */
  real_T Product3_m;                   /* '<S22>/Product3' */
  real_T cos_o;                        /* '<S22>/cos' */
  real_T Product2_m;                   /* '<S22>/Product2' */
  real_T Subtract_j;                   /* '<S22>/Subtract' */
  real_T Product1_f;                   /* '<S22>/Product1' */
  real_T Product_e;                    /* '<S22>/Product' */
  real_T Add_c;                        /* '<S22>/Add' */
  real_T Gain_n[2];                    /* '<S22>/Gain' */
  real_T Gain_d;                       /* '<S4>/Gain' */
  real_T Switch_i[2];                  /* '<Root>/Switch' */
  real_T Switch_c[2];                  /* '<S5>/Switch' */
  real_T Product_f;                    /* '<S5>/Product' */
  real_T Gain1_k;                      /* '<S5>/Gain1' */
  real_T Gain3;                        /* '<S5>/Gain3' */
  real_T Sum2_f;                       /* '<S5>/Sum2' */
  real_T Saturation;                   /* '<S5>/Saturation' */
  real_T Gain4;                        /* '<S5>/Gain4' */
  real_T Product1_b;                   /* '<S5>/Product1' */
  real_T Gain2;                        /* '<S5>/Gain2' */
  real_T Sum1_a;                       /* '<S5>/Sum1' */
  real_T Saturation1;                  /* '<S5>/Saturation1' */
  uint8_T Compare;                     /* '<S55>/Compare' */
  uint8_T Compare_m;                   /* '<S29>/Compare' */
  uint8_T Compare_d;                   /* '<S30>/Compare' */
  uint8_T Compare_b;                   /* '<S48>/Compare' */
  uint8_T Compare_f;                   /* '<S51>/Compare' */
  uint8_T Uk1;                         /* '<S49>/Delay Input1' */
  uint8_T FixPtRelationalOperator;     /* '<S49>/FixPt Relational Operator' */
  uint8_T Compare_h;                   /* '<S44>/Compare' */
  uint8_T Compare_n;                   /* '<S38>/Compare' */
  uint8_T Compare_ht;                  /* '<S40>/Compare' */
  uint8_T Compare_a;                   /* '<S39>/Compare' */
  uint8_T Compare_o;                   /* '<S41>/Compare' */
  uint8_T Compare_l;                   /* '<S42>/Compare' */
  uint8_T Uk1_h;                       /* '<S32>/Delay Input1' */
  uint8_T FixPtRelationalOperator_i;   /* '<S32>/FixPt Relational Operator' */
  uint8_T Compare_n2;                  /* '<S46>/Compare' */
  uint8_T Compare_be;                  /* '<S43>/Compare' */
  uint8_T Uk1_p;                       /* '<S33>/Delay Input1' */
  uint8_T Pack[112];                   /* '<S13>/Pack' */
  uint8_T RateTransition[112];         /* '<S13>/Rate Transition' */
  uint8_T Compare_p;                   /* '<S53>/Compare' */
  uint8_T Compare_oh;                  /* '<S2>/Compare' */
  uint8_T Compare_c;                   /* '<S3>/Compare' */
  boolean_T Memory;                    /* '<S10>/Memory' */
  boolean_T Memory_h;                  /* '<Root>/Memory' */
  boolean_T LogicalOperator2;          /* '<S10>/Logical Operator2' */
  boolean_T LogicalOperator1;          /* '<S10>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_EnabledSu;/* '<S10>/Logical Operator1' */
  boolean_T RelationalOperator;        /* '<S10>/Relational Operator' */
  boolean_T LogicalOperator;           /* '<S10>/Logical Operator' */
  boolean_T Memory_k;                  /* '<S35>/Memory' */
  boolean_T RelationalOperator_n;      /* '<S1>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S1>/Relational Operator1' */
  boolean_T RelationalOperator2;       /* '<S1>/Relational Operator2' */
  boolean_T RelationalOperator3;       /* '<S1>/Relational Operator3' */
  boolean_T LogicalOperator_a;         /* '<S1>/Logical Operator' */
  boolean_T InBox;                     /* '<S5>/InBox' */
  boolean_T LogicalOperator3;          /* '<S37>/Logical Operator3' */
  boolean_T Memory_o;                  /* '<S37>/Memory' */
  boolean_T LogicalOperator4;          /* '<S37>/Logical Operator4' */
  boolean_T LogicalOperator_b;         /* '<S5>/Logical Operator' */
  boolean_T LogicalOperator2_n;        /* '<S37>/Logical Operator2' */
  boolean_T LogicalOperator1_o;        /* '<S37>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_l;/* '<S37>/Logical Operator1' */
  boolean_T RelationalOperator_g;      /* '<S37>/Relational Operator' */
  boolean_T LogicalOperator_m;         /* '<S37>/Logical Operator' */
  boolean_T LogicalOperator5;          /* '<S37>/Logical Operator5' */
  boolean_T LogicalOperator2_m;        /* '<S35>/Logical Operator2' */
  boolean_T LogicalOperator1_e;        /* '<S35>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_d;/* '<S35>/Logical Operator1' */
  boolean_T RelationalOperator_f;      /* '<S35>/Relational Operator' */
  boolean_T LogicalOperator_g;         /* '<S35>/Logical Operator' */
  boolean_T Memory_i;                  /* '<S36>/Memory' */
  boolean_T LogicalOperator1_h;        /* '<S31>/Logical Operator1' */
  boolean_T LogicalOperator2_mo;       /* '<S36>/Logical Operator2' */
  boolean_T LogicalOperator1_b;        /* '<S36>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_j;/* '<S36>/Logical Operator1' */
  boolean_T RelationalOperator_k;      /* '<S36>/Relational Operator' */
  boolean_T LogicalOperator_l;         /* '<S36>/Logical Operator' */
  boolean_T FixPtRelationalOperator_g; /* '<S33>/FixPt Relational Operator' */
  boolean_T LogicalOperator4_p;        /* '<S5>/Logical Operator4' */
  boolean_T Memory_d;                  /* '<S34>/Memory' */
  boolean_T Logic[2];                  /* '<S34>/Logic' */
  boolean_T LogicalOperator2_d;        /* '<S5>/Logical Operator2' */
  boolean_T LogicalOperator5_l;        /* '<S5>/Logical Operator5' */
  boolean_T Memory1;                   /* '<S9>/Memory1' */
  boolean_T Memory_oz;                 /* '<S52>/Memory' */
  boolean_T LogicalOperator2_f;        /* '<S52>/Logical Operator2' */
  boolean_T LogicalOperator1_j;        /* '<S52>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_k;/* '<S52>/Logical Operator1' */
  boolean_T RelationalOperator_gb;     /* '<S52>/Relational Operator' */
  boolean_T LogicalOperator_e;         /* '<S52>/Logical Operator' */
  boolean_T LogicalOperator1_c;        /* '<Root>/Logical Operator1' */
  boolean_T MatrixConcatenation[2];    /* '<Root>/Matrix Concatenation' */
  boolean_T Compare_nw;                /* '<S62>/Compare' */
  boolean_T Compare_h0;                /* '<S61>/Compare' */
  boolean_T LogicalOperator6;          /* '<S5>/Logical Operator6' */
  boolean_T LogicalOperator3_d;        /* '<S5>/Logical Operator3' */
  rtB_EnabledSubsystem_random_wal EnabledSubsystem;/* '<S10>/Enabled Subsystem' */
  rtB_EnabledSubsystem_random_wal EnabledSubsystem_by;/* '<S52>/Enabled Subsystem' */
  rtB_EnabledSubsystem_random_wal EnabledSubsystem_f;/* '<S37>/Enabled Subsystem' */
  rtB_EnabledSubsystem_random_wal EnabledSubsystem_b1;/* '<S36>/Enabled Subsystem' */
  rtB_EnabledSubsystem_random_wal EnabledSubsystem_b;/* '<S35>/Enabled Subsystem' */
} BlockIO_random_walk;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DigitalFilter2_FILT_STATES[11];/* '<S7>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES[11];/* '<S7>/Digital Filter' */
  real_T DigitalFilter2_FILT_STATES_i[11];/* '<S8>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES_a[11];/* '<S8>/Digital Filter' */
  real_T x_DSTATE;                     /* '<S25>/x' */
  real_T x_DSTATE_m;                   /* '<S26>/x' */
  real_T x_DSTATE_d;                   /* '<S27>/x' */
  real_T x_DSTATE_k;                   /* '<S28>/x' */
  real_T BehaviorRW_DSTATE;            /* '<Root>/Behavior RW' */
  real_T y_DSTATE;                     /* '<S25>/y' */
  real_T z_DSTATE;                     /* '<S25>/z' */
  real_T y_DSTATE_k;                   /* '<S26>/y' */
  real_T z_DSTATE_f;                   /* '<S26>/z' */
  real_T y_DSTATE_n;                   /* '<S27>/y' */
  real_T z_DSTATE_d;                   /* '<S27>/z' */
  real_T y_DSTATE_d;                   /* '<S28>/y' */
  real_T z_DSTATE_dv;                  /* '<S28>/z' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S7>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_n;                /* '<S8>/Derivative' */

  real_T BehaviorRW_RWORK[512];        /* '<Root>/Behavior RW' */
  real_T PCI6025E_RWORK[6];            /* '<Root>/PCI-6025E ' */
  void *Send_PWORK;                    /* '<S13>/Send' */
  int32_T DigitalFilter2_CIRCBUFFIDX;  /* '<S7>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX;   /* '<S7>/Digital Filter' */
  int32_T DigitalFilter2_CIRCBUFFIDX_l;/* '<S8>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX_f; /* '<S8>/Digital Filter' */
  int_T PCIQUAD04_IWORK;               /* '<S15>/PCI-QUAD04 ' */
  int_T PCIQUAD041_IWORK;              /* '<S15>/PCI-QUAD04 1' */
  int_T BehaviorRW_IWORK[5];           /* '<Root>/Behavior RW' */
  int_T PCI6025E_IWORK[2];             /* '<Root>/PCI-6025E ' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S11>/S-Function' */

  int_T Send_IWORK[2];                 /* '<S13>/Send' */
  int_T PortA_IWORK[2];                /* '<S14>/Port A' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK_c;                 /* '<S16>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_e;                 /* '<S17>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_o;                 /* '<S18>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_i;                 /* '<S19>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_d;                 /* '<S20>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_k;                 /* '<S23>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_p;                 /* '<S24>/S-Function' */

  int_T PortB_IWORK[2];                /* '<S58>/Port B' */
  int_T PCI6025E_IWORK_d[3];           /* '<S60>/PCI-6025E ' */
  uint8_T DelayInput1_DSTATE;          /* '<S49>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_d;        /* '<S32>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_c;        /* '<S33>/Delay Input1' */
  boolean_T Memory_PreviousInput;      /* '<S10>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<Root>/Memory' */
  boolean_T Memory_PreviousInput_na;   /* '<S35>/Memory' */
  boolean_T Memory_PreviousInput_k;    /* '<S37>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S36>/Memory' */
  boolean_T Memory_PreviousInput_d;    /* '<S34>/Memory' */
  boolean_T Memory1_PreviousInput;     /* '<S9>/Memory1' */
  boolean_T Memory_PreviousInput_a;    /* '<S52>/Memory' */
  rtDW_EnabledSubsystem_random_wa EnabledSubsystem;/* '<S10>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_random_wa EnabledSubsystem_by;/* '<S52>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_random_wa EnabledSubsystem_f;/* '<S37>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_random_wa EnabledSubsystem_b1;/* '<S36>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_random_wa EnabledSubsystem_b;/* '<S35>/Enabled Subsystem' */
} D_Work_random_walk;

/* Backward compatible GRT Identifiers */
#define rtB                            random_walk_B
#define BlockIO                        BlockIO_random_walk
#define rtXdot                         random_walk_Xdot
#define StateDerivatives               StateDerivatives_random_walk
#define tXdis                          random_walk_Xdis
#define StateDisabled                  StateDisabled_random_walk
#define rtP                            random_walk_P
#define Parameters                     Parameters_random_walk
#define rtDWork                        random_walk_DWork
#define D_Work                         D_Work_random_walk

/* Parameters (auto storage) */
struct Parameters_random_walk {
  real_T Time_Value;                   /* Expression: Time
                                        * '<S10>/Time'
                                        */
  real_T PCIQUAD04_P1_Size[2];         /* Computed Parameter: P1Size
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P1;                 /* Expression: convbaseaddr
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P2_Size[2];         /* Computed Parameter: P2Size
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P2;                 /* Expression: channel
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P3_Size[2];         /* Computed Parameter: P3Size
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P3;                 /* Expression: resetmode
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P4_Size[2];         /* Computed Parameter: P4Size
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P4;                 /* Expression: polarity
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P5_Size[2];         /* Computed Parameter: P5Size
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P5;                 /* Expression: mode
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P6_Size[2];         /* Computed Parameter: P6Size
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P6;                 /* Expression: limit
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P7_Size[2];         /* Computed Parameter: P7Size
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P7;                 /* Expression: range
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P8_Size[2];         /* Computed Parameter: P8Size
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P8;                 /* Expression: speed
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P9_Size[2];         /* Computed Parameter: P9Size
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P9;                 /* Expression: prescale
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P10_Size[2];        /* Computed Parameter: P10Size
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P10;                /* Expression: ts
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P11_Size[2];        /* Computed Parameter: P11Size
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P11;                /* Expression: boardtype
                                        * '<S15>/PCI-QUAD04 '
                                        */
  real_T Gain_Gain;                    /* Expression: 3.490658e-4
                                        * '<S15>/Gain'
                                        */
  real_T shoulderOffset_Value;         /* Expression: 0
                                        * '<S15>/shoulderOffset'
                                        */
  real_T PCIQUAD041_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P1;                /* Expression: convbaseaddr
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P2;                /* Expression: channel
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P3;                /* Expression: resetmode
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P4;                /* Expression: polarity
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P5;                /* Expression: mode
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P6;                /* Expression: limit
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P7_Size[2];        /* Computed Parameter: P7Size
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P7;                /* Expression: range
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P8_Size[2];        /* Computed Parameter: P8Size
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P8;                /* Expression: speed
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P9_Size[2];        /* Computed Parameter: P9Size
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P9;                /* Expression: prescale
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P10_Size[2];       /* Computed Parameter: P10Size
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P10;               /* Expression: ts
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P11_Size[2];       /* Computed Parameter: P11Size
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P11;               /* Expression: boardtype
                                        * '<S15>/PCI-QUAD04 1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -3.490658e-4
                                        * '<S15>/Gain1'
                                        */
  real_T elbowOffset_Value;            /* Expression: 0
                                        * '<S15>/elbowOffset'
                                        */
  real_T yoffset_Value;                /* Expression: 37
                                        * '<S59>/yoffset'
                                        */
  real_T xoffset_Value;                /* Expression: -2
                                        * '<S59>/xoffset'
                                        */
  real_T AngleOffset_Value;            /* Expression: 0
                                        * '<S57>/AngleOffset'
                                        */
  real_T DigitalFilter2_ICRTP;         /* Expression: a.IC
                                        * '<S7>/Digital Filter2'
                                        */
  real_T DigitalFilter2_RTP1COEFF[11]; /* Expression: NumCoeffs
                                        * '<S7>/Digital Filter2'
                                        */
  real_T dG_Gain;                      /* Expression: -.0001
                                        * '<S7>/dG'
                                        */
  real_T DigitalFilter_ICRTP;          /* Expression: a.IC
                                        * '<S7>/Digital Filter'
                                        */
  real_T DigitalFilter_RTP1COEFF[11];  /* Expression: NumCoeffs
                                        * '<S7>/Digital Filter'
                                        */
  real_T DigitalFilter2_ICRTP_p;       /* Expression: a.IC
                                        * '<S8>/Digital Filter2'
                                        */
  real_T DigitalFilter2_RTP1COEFF_k[11];/* Expression: NumCoeffs
                                         * '<S8>/Digital Filter2'
                                         */
  real_T dG_Gain_p;                    /* Expression: -.0001
                                        * '<S8>/dG'
                                        */
  real_T DigitalFilter_ICRTP_f;        /* Expression: a.IC
                                        * '<S8>/Digital Filter'
                                        */
  real_T DigitalFilter_RTP1COEFF_h[11];/* Expression: NumCoeffs
                                        * '<S8>/Digital Filter'
                                        */
  real_T XLowLimit_Value;              /* Expression: -30
                                        * '<S1>/XLowLimit'
                                        */
  real_T XHighLimit_Value;             /* Expression: 25
                                        * '<S1>/XHighLimit'
                                        */
  real_T YHighLimit_Value;             /* Expression: -46
                                        * '<S1>/YHighLimit'
                                        */
  real_T YLowLimit_Value;              /* Expression: -22
                                        * '<S1>/YLowLimit'
                                        */
  real_T Time_Value_c;                 /* Expression: Time
                                        * '<S37>/Time'
                                        */
  real_T Time_Value_d;                 /* Expression: Time
                                        * '<S35>/Time'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * '<S38>/Constant'
                                        */
  real_T Constant_Value_c;             /* Expression: const
                                        * '<S40>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: const
                                        * '<S39>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: const
                                        * '<S41>/Constant'
                                        */
  real_T Time_Value_k;                 /* Expression: Time
                                        * '<S36>/Time'
                                        */
  real_T Load_Value;                   /* Expression: 0
                                        * '<S4>/Load'
                                        */
  real_T x_X0;                         /* Expression: .1
                                        * '<S25>/x'
                                        */
  real_T x_X0_f;                       /* Expression: .1
                                        * '<S26>/x'
                                        */
  real_T x_X0_fi;                      /* Expression: .1
                                        * '<S27>/x'
                                        */
  real_T x_X0_i;                       /* Expression: .1
                                        * '<S28>/x'
                                        */
  real_T BehaviorRW_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P1;                /* Expression: 8
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P2;                /* Expression: 4
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P3;                /* Expression: 30
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P4;                /* Expression: 30
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P5;                /* Expression: 0
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P6;                /* Expression: 0
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P7_Size[2];        /* Computed Parameter: P7Size
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P7;                /* Expression: 3
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P8_Size[2];        /* Computed Parameter: P8Size
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P8;                /* Expression: 10
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P9_Size[2];        /* Computed Parameter: P9Size
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P9;                /* Expression: 3
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P10_Size[2];       /* Computed Parameter: P10Size
                                        * '<Root>/Behavior RW'
                                        */
  real_T BehaviorRW_P10;               /* Expression: 0
                                        * '<Root>/Behavior RW'
                                        */
  real_T MG2_Gain;                     /* Expression: -1
                                        * '<Root>/MG2'
                                        */
  real_T MG1_Gain;                     /* Expression: 1
                                        * '<Root>/MG1'
                                        */
  real_T PCI6025E_P1_Size[2];          /* Computed Parameter: P1Size
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P1[2];               /* Expression: channel
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_Size[2];          /* Computed Parameter: P2Size
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P2[2];               /* Expression: range
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_Size[2];          /* Computed Parameter: P3Size
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P3[2];               /* Expression: reset
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_Size[2];          /* Computed Parameter: P4Size
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P4[2];               /* Expression: initValue
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_Size[2];          /* Computed Parameter: P5Size
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P5;                  /* Expression: sampletime
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_Size[2];          /* Computed Parameter: P6Size
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P6[2];               /* Expression: slot
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_Size[2];          /* Computed Parameter: P7Size
                                        * '<Root>/PCI-6025E '
                                        */
  real_T PCI6025E_P7;                  /* Expression: boardType
                                        * '<Root>/PCI-6025E '
                                        */
  real_T Send_P1_Size[2];              /* Computed Parameter: P1Size
                                        * '<S13>/Send'
                                        */
  real_T Send_P1[11];                  /* Computed Parameter: P1
                                        * '<S13>/Send'
                                        */
  real_T Send_P2_Size[2];              /* Computed Parameter: P2Size
                                        * '<S13>/Send'
                                        */
  real_T Send_P2;                      /* Expression: ipPort
                                        * '<S13>/Send'
                                        */
  real_T Send_P3_Size[2];              /* Computed Parameter: P3Size
                                        * '<S13>/Send'
                                        */
  real_T Send_P3;                      /* Expression: localPort
                                        * '<S13>/Send'
                                        */
  real_T Send_P4_Size[2];              /* Computed Parameter: P4Size
                                        * '<S13>/Send'
                                        */
  real_T Send_P4;                      /* Expression: sampletime
                                        * '<S13>/Send'
                                        */
  real_T PortA_P1_Size[2];             /* Computed Parameter: P1Size
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P1[8];                  /* Expression: channel
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P2_Size[2];             /* Computed Parameter: P2Size
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P2;                     /* Expression: port
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P3_Size[2];             /* Computed Parameter: P3Size
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P3[8];                  /* Expression: reset
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P4_Size[2];             /* Computed Parameter: P4Size
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P4[8];                  /* Expression: initValue
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P5_Size[2];             /* Computed Parameter: P5Size
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P5;                     /* Expression: chip
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P6_Size[2];             /* Computed Parameter: P6Size
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P6;                     /* Expression: sampletime
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P7_Size[2];             /* Computed Parameter: P7Size
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P7[2];                  /* Expression: slot
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P8_Size[2];             /* Computed Parameter: P8Size
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P8;                     /* Expression: control
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P9_Size[2];             /* Computed Parameter: P9Size
                                        * '<S14>/Port A'
                                        */
  real_T PortA_P9;                     /* Expression: boardType
                                        * '<S14>/Port A'
                                        */
  real_T y_X0;                         /* Expression: y0
                                        * '<S25>/y'
                                        */
  real_T rho_Value;                    /* Expression: 28
                                        * '<S25>/rho'
                                        */
  real_T z_X0;                         /* Expression: .1
                                        * '<S25>/z'
                                        */
  real_T beta_Value;                   /* Expression: 8/3
                                        * '<S25>/beta'
                                        */
  real_T timescale_Value;              /* Expression: .0001
                                        * '<S25>/timescale'
                                        */
  real_T sigma_Value;                  /* Expression: 10
                                        * '<S25>/sigma'
                                        */
  real_T y_X0_l;                       /* Expression: y0
                                        * '<S26>/y'
                                        */
  real_T rho_Value_j;                  /* Expression: 28
                                        * '<S26>/rho'
                                        */
  real_T z_X0_j;                       /* Expression: .1
                                        * '<S26>/z'
                                        */
  real_T beta_Value_g;                 /* Expression: 8/3
                                        * '<S26>/beta'
                                        */
  real_T timescale_Value_p;            /* Expression: .0001
                                        * '<S26>/timescale'
                                        */
  real_T sigma_Value_h;                /* Expression: 10
                                        * '<S26>/sigma'
                                        */
  real_T y_X0_p;                       /* Expression: y0
                                        * '<S27>/y'
                                        */
  real_T rho_Value_e;                  /* Expression: 28
                                        * '<S27>/rho'
                                        */
  real_T z_X0_l;                       /* Expression: .1
                                        * '<S27>/z'
                                        */
  real_T beta_Value_o;                 /* Expression: 8/3
                                        * '<S27>/beta'
                                        */
  real_T timescale_Value_d;            /* Expression: .0001
                                        * '<S27>/timescale'
                                        */
  real_T sigma_Value_hc;               /* Expression: 10
                                        * '<S27>/sigma'
                                        */
  real_T y_X0_lz;                      /* Expression: y0
                                        * '<S28>/y'
                                        */
  real_T rho_Value_m;                  /* Expression: 28
                                        * '<S28>/rho'
                                        */
  real_T z_X0_g;                       /* Expression: .1
                                        * '<S28>/z'
                                        */
  real_T beta_Value_e;                 /* Expression: 8/3
                                        * '<S28>/beta'
                                        */
  real_T timescale_Value_h;            /* Expression: .0001
                                        * '<S28>/timescale'
                                        */
  real_T sigma_Value_m;                /* Expression: 10
                                        * '<S28>/sigma'
                                        */
  real_T Time_Value_f;                 /* Expression: Time
                                        * '<S52>/Time'
                                        */
  real_T Constant_Value_a;             /* Expression: const
                                        * '<S2>/Constant'
                                        */
  real_T Constant_Value_nk;            /* Expression: const
                                        * '<S3>/Constant'
                                        */
  real_T Gain_Gain_g;                  /* Expression: .5
                                        * '<S12>/Gain'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: .5
                                        * '<S12>/Gain1'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: -.001
                                        * '<S5>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 2
                                        * '<S5>/Gain3'
                                        */
  real_T Saturation_UpperSat;          /* Expression: .01
                                        * '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.01
                                        * '<S5>/Saturation'
                                        */
  real_T Gain4_Gain;                   /* Expression: 2
                                        * '<S5>/Gain4'
                                        */
  real_T Gain2_Gain;                   /* Expression: -.001
                                        * '<S5>/Gain2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: .01
                                        * '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -0.01
                                        * '<S5>/Saturation1'
                                        */
  real_T zeroX_Value;                  /* Expression: 0
                                        * '<Root>/zeroX'
                                        */
  real_T zeroY_Value;                  /* Expression: 0
                                        * '<Root>/zeroY'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 0.0367
                                        * '<S4>/Gain'
                                        */
  real_T visAngle_Value;               /* Expression: 0
                                        * '<S4>/visAngle'
                                        */
  real_T DynamicAngle_Value;           /* Expression: 0
                                        * '<S4>/DynamicAngle'
                                        */
  real_T Gain_Gain_go;                 /* Expression: 1
                                        * '<S22>/Gain'
                                        */
  real_T LorentzForceGain_Gain;        /* Expression: .0005
                                        * '<S4>/LorentzForceGain'
                                        */
  real_T staticX_Value;                /* Expression: 0
                                        * '<S4>/staticX'
                                        */
  real_T staticY_Value;                /* Expression: 0
                                        * '<S4>/staticY'
                                        */
  real_T Off_Value;                    /* Expression: 0
                                        * '<S4>/Off'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * '<S60>/Constant1'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * '<S60>/Constant'
                                        */
  real_T xPCTargetTime_P1_Size[2];     /* Computed Parameter: P1Size
                                        * '<S60>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1;             /* Expression: func
                                        * '<S60>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size[2];     /* Computed Parameter: P2Size
                                        * '<S60>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2;             /* Expression: ts
                                        * '<S60>/xPC Target  Time '
                                        */
  real_T ScaleTouSec_Gain;             /* Expression: .838
                                        * '<S60>/ScaleTouSec'
                                        */
  real_T Constant_Value_o;             /* Expression: const
                                        * '<S62>/Constant'
                                        */
  real_T PCI6025E_P1_Size_g[2];        /* Computed Parameter: P1Size
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P1_o[2];             /* Expression: channel
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_Size_i[2];        /* Computed Parameter: P2Size
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_f[2];             /* Expression: reset
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_Size_h[2];        /* Computed Parameter: P3Size
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_k[2];             /* Expression: initValue
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_Size_p[2];        /* Computed Parameter: P4Size
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_i;                /* Expression: sampletime
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_Size_o[2];        /* Computed Parameter: P5Size
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_h[2];             /* Expression: slot
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_Size_f[2];        /* Computed Parameter: P6Size
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_n;                /* Expression: control
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_Size_i[2];        /* Computed Parameter: P7Size
                                        * '<S60>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_e;                /* Expression: boardType
                                        * '<S60>/PCI-6025E '
                                        */
  real_T Constant_Value_ad;            /* Expression: const
                                        * '<S61>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 32768
                                        * '<S58>/Constant'
                                        */
  real_T PortB_P1_Size[2];             /* Computed Parameter: P1Size
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P1[8];                  /* Expression: channel
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P2_Size[2];             /* Computed Parameter: P2Size
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P2;                     /* Expression: port
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P3_Size[2];             /* Computed Parameter: P3Size
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P3[8];                  /* Expression: reset
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P4_Size[2];             /* Computed Parameter: P4Size
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P4[8];                  /* Expression: initValue
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P5_Size[2];             /* Computed Parameter: P5Size
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P5;                     /* Expression: chip
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P6_Size[2];             /* Computed Parameter: P6Size
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P6;                     /* Expression: sampletime
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P7_Size[2];             /* Computed Parameter: P7Size
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P7[2];                  /* Expression: slot
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P8_Size[2];             /* Computed Parameter: P8Size
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P8;                     /* Expression: control
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P9_Size[2];             /* Computed Parameter: P9Size
                                        * '<S58>/Port B'
                                        */
  real_T PortB_P9;                     /* Expression: boardType
                                        * '<S58>/Port B'
                                        */
  real_T xPCTargetTime_P1_Size_j[2];   /* Computed Parameter: P1Size
                                        * '<S58>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1_e;           /* Expression: func
                                        * '<S58>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size_h[2];   /* Computed Parameter: P2Size
                                        * '<S58>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_h;           /* Expression: ts
                                        * '<S58>/xPC Target  Time '
                                        */
  uint8_T DelayInput1_X0;              /* Computed Parameter: X0
                                        * '<S49>/Delay Input1'
                                        */
  uint8_T DelayInput1_X0_m;            /* Computed Parameter: X0
                                        * '<S32>/Delay Input1'
                                        */
  uint8_T DelayInput1_X0_f;            /* Computed Parameter: X0
                                        * '<S33>/Delay Input1'
                                        */
  boolean_T Memory_X0;                 /* Computed Parameter: X0
                                        * '<S10>/Memory'
                                        */
  boolean_T Memory_X0_n;               /* Computed Parameter: X0
                                        * '<Root>/Memory'
                                        */
  boolean_T Memory_X0_g;               /* Computed Parameter: X0
                                        * '<S35>/Memory'
                                        */
  boolean_T Memory_X0_p;               /* Computed Parameter: X0
                                        * '<S37>/Memory'
                                        */
  boolean_T Memory_X0_np;              /* Computed Parameter: X0
                                        * '<S36>/Memory'
                                        */
  boolean_T Memory_X0_l;               /* Computed Parameter: X0
                                        * '<S34>/Memory'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: TruthTable
                                        * '<S34>/Logic'
                                        */
  boolean_T Memory1_X0;                /* Computed Parameter: X0
                                        * '<S9>/Memory1'
                                        */
  boolean_T Memory_X0_pd;              /* Computed Parameter: X0
                                        * '<S52>/Memory'
                                        */
};

/* Real-time Model Data Structure */
struct rtModel_random_walk {
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
    SimStruct childSFunctions[13];
    SimStruct *childSFunctionPtrs[13];
    struct _ssBlkInfo2 blkInfo2[13];
    struct _ssSFcnModelMethods2 methods2[13];
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
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
      struct _ssPortOutputs outputPortInfo[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[8];
    } Sfcn3;

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
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[11];
      mxArray *params[11];
      struct _ssDWorkRecord dWork[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[11];
      mxArray *params[11];
      struct _ssDWorkRecord dWork[1];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[2];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[3];
    } Sfcn8;

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
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[8];
    } Sfcn11;

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
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
    } Sfcn12;
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
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *nonsampledZCs;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
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
    uint32_T clockTick3;
    uint32_T clockTickH3;
    time_T stepSize3;
    struct {
      uint8_T TID[4];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
      boolean_T TID1_3;
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
    time_T sampleTimesArray[4];
    time_T offsetTimesArray[4];
    int_T sampleTimeTaskIDArray[4];
    int_T sampleHitArray[4];
    int_T perTaskSampleHitsArray[16];
    time_T tArray[4];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_random_walk random_walk_P;

/* Block signals (auto storage) */
extern BlockIO_random_walk random_walk_B;

/* Block states (auto storage) */
extern D_Work_random_walk random_walk_DWork;

/* Model entry point functions */
extern void random_walk_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void random_walk_initialize(boolean_T firstTime);
extern void random_walk_output(int_T tid);
extern void random_walk_update(int_T tid);
extern void random_walk_terminate(void);

/* Real-time Model object */
extern rtModel_random_walk *random_walk_rtM;

/*
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
 * '<Root>' : random_walk
 * '<S1>'   : random_walk/BoundingBox
 * '<S2>'   : random_walk/Compare To Constant
 * '<S3>'   : random_walk/Compare To Constant1
 * '<S4>'   : random_walk/Force Generator
 * '<S5>'   : random_walk/Force outside box
 * '<S6>'   : random_walk/Force//Torque Transform
 * '<S7>'   : random_walk/Pos2VelX
 * '<S8>'   : random_walk/Pos2VelY
 * '<S9>'   : random_walk/RewardSbs
 * '<S10>'  : random_walk/Schmidt
 * '<S11>'  : random_walk/Status
 * '<S12>'  : random_walk/Target Peek
 * '<S13>'  : random_walk/UDPXmit
 * '<S14>'  : random_walk/WordSbs
 * '<S15>'  : random_walk/XY Position Subsystem
 * '<S16>'  : random_walk/Xpos
 * '<S17>'  : random_walk/Xpos1
 * '<S18>'  : random_walk/Ypos
 * '<S19>'  : random_walk/forceScope
 * '<S20>'  : random_walk/th1
 * '<S21>'  : random_walk/Force Generator/LorentzForce
 * '<S22>'  : random_walk/Force Generator/ViscLoadSubsystem
 * '<S23>'  : random_walk/Force Generator/Ypos1
 * '<S24>'  : random_walk/Force Generator/Ypos4
 * '<S25>'  : random_walk/Force Generator/LorentzForce/Lorentz
 * '<S26>'  : random_walk/Force Generator/LorentzForce/Lorentz1
 * '<S27>'  : random_walk/Force Generator/LorentzForce/Lorentz2
 * '<S28>'  : random_walk/Force Generator/LorentzForce/Lorentz3
 * '<S29>'  : random_walk/Force outside box/Compare To Zero
 * '<S30>'  : random_walk/Force outside box/Compare To Zero1
 * '<S31>'  : random_walk/Force outside box/In Center
 * '<S32>'  : random_walk/Force outside box/Leave center
 * '<S33>'  : random_walk/Force outside box/Leave center delay
 * '<S34>'  : random_walk/Force outside box/S-R Flip-Flop
 * '<S35>'  : random_walk/Force outside box/Schmidt1
 * '<S36>'  : random_walk/Force outside box/Schmidt3
 * '<S37>'  : random_walk/Force outside box/Timer
 * '<S38>'  : random_walk/Force outside box/In Center/Compare To Constant
 * '<S39>'  : random_walk/Force outside box/In Center/Compare To Constant1
 * '<S40>'  : random_walk/Force outside box/In Center/Compare To Constant2
 * '<S41>'  : random_walk/Force outside box/In Center/Compare To Constant3
 * '<S42>'  : random_walk/Force outside box/Leave center/Nonpositive
 * '<S43>'  : random_walk/Force outside box/Leave center delay/Nonpositive
 * '<S44>'  : random_walk/Force outside box/Schmidt1/Compare To Zero
 * '<S45>'  : random_walk/Force outside box/Schmidt1/Enabled Subsystem
 * '<S46>'  : random_walk/Force outside box/Schmidt3/Compare To Zero
 * '<S47>'  : random_walk/Force outside box/Schmidt3/Enabled Subsystem
 * '<S48>'  : random_walk/Force outside box/Timer/Compare To Zero
 * '<S49>'  : random_walk/Force outside box/Timer/Detect Fall Nonpositive
 * '<S50>'  : random_walk/Force outside box/Timer/Enabled Subsystem
 * '<S51>'  : random_walk/Force outside box/Timer/Detect Fall Nonpositive/Nonpositive
 * '<S52>'  : random_walk/RewardSbs/Schmidt1
 * '<S53>'  : random_walk/RewardSbs/Schmidt1/Compare To Zero
 * '<S54>'  : random_walk/RewardSbs/Schmidt1/Enabled Subsystem
 * '<S55>'  : random_walk/Schmidt/Compare To Zero
 * '<S56>'  : random_walk/Schmidt/Enabled Subsystem
 * '<S57>'  : random_walk/XY Position Subsystem/Cursor Rotation
 * '<S58>'  : random_walk/XY Position Subsystem/For Iterator Subsystem
 * '<S59>'  : random_walk/XY Position Subsystem/Jacobian-Cartesian Transformation
 * '<S60>'  : random_walk/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem
 * '<S61>'  : random_walk/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant
 * '<S62>'  : random_walk/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1
 */
#endif                                 /* _RTW_HEADER_random_walk_h_ */
