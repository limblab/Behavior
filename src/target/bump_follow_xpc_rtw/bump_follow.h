/*
 * bump_follow.h
 *
 * Real-Time Workshop code generation for Simulink model "bump_follow.mdl".
 *
 * Model Version              : 1.1247
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Mon Aug 02 10:27:51 2010
 */
#ifndef _RTW_HEADER_bump_follow_h_
#define _RTW_HEADER_bump_follow_h_
#include "rtw_modelmap.h"
#ifndef _bump_follow_COMMON_INCLUDES_
# define _bump_follow_COMMON_INCLUDES_
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
#endif                                 /* _bump_follow_COMMON_INCLUDES_ */

#include "bump_follow_types.h"

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
#define bump_follow_M                  bump_follow_rtM

/* Definition for use in the target main file */
#define bump_follow_rtModel            rtModel_bump_follow

/* Block signals for system '<S30>/Enabled Subsystem' */
typedef struct {
  real_T In1;                          /* '<S34>/In1' */
} rtB_EnabledSubsystem_bump_follo;

/* Block states (auto storage) for system '<S30>/Enabled Subsystem' */
typedef struct {
  int_T EnabledSubsystem_MODE;         /* '<S30>/Enabled Subsystem' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S30>/Enabled Subsystem' */
} rtDW_EnabledSubsystem_bump_foll;

/* Block signals for system '<S6>/Sample and Hold' */
typedef struct {
  real_T In;                           /* '<S63>/In' */
} rtB_SampleandHold_bump_follow;

/* Block states (auto storage) for system '<S6>/Sample and Hold' */
typedef struct {
  int8_T SampleandHold_SubsysRanBC;    /* '<S6>/Sample and Hold' */
} rtDW_SampleandHold_bump_follow;

/* Zero-crossing (trigger) state for system '<S6>/Sample and Hold' */
typedef struct {
  ZCSigState SampleandHold_ZCE;        /* '<S6>/Sample and Hold' */
} rtZCE_SampleandHold_bump_follow;

/* Block signals (auto storage) */
typedef struct {
  real_T Clock;                        /* '<S30>/Clock' */
  real_T Sum;                          /* '<S30>/Sum' */
  real_T PCIQUAD04;                    /* '<S12>/PCI-QUAD04 ' */
  real_T Gain;                         /* '<S12>/Gain' */
  real_T Sum3;                         /* '<S12>/Sum3' */
  real_T TrigonometricFunction;        /* '<S70>/Trigonometric Function' */
  real_T Product;                      /* '<S70>/Product' */
  real_T TrigonometricFunction1;       /* '<S70>/Trigonometric Function1' */
  real_T Product1;                     /* '<S70>/Product1' */
  real_T PCIQUAD041;                   /* '<S12>/PCI-QUAD04 1' */
  real_T Gain1;                        /* '<S12>/Gain1' */
  real_T Sum1;                         /* '<S12>/Sum1' */
  real_T TrigonometricFunction2;       /* '<S70>/Trigonometric Function2' */
  real_T Product2;                     /* '<S70>/Product2' */
  real_T TrigonometricFunction3;       /* '<S70>/Trigonometric Function3' */
  real_T Product3;                     /* '<S70>/Product3' */
  real_T MatrixConcatenate2[4];        /* '<S70>/Matrix Concatenate2' */
  real_T PCI6025EAD_o1;                /* '<S9>/PCI-6025E AD' */
  real_T PCI6025EAD_o2;                /* '<S9>/PCI-6025E AD' */
  real_T Sum2;                         /* '<S70>/Sum2' */
  real_T Sum4;                         /* '<S70>/Sum4' */
  real_T Sum3_n;                       /* '<S70>/Sum3' */
  real_T Sum1_c;                       /* '<S70>/Sum1' */
  real_T TrigonometricFunction1_p;     /* '<S68>/Trigonometric Function1' */
  real_T Sum_n;                        /* '<S68>/Sum' */
  real_T TrigonometricFunction2_p;     /* '<S68>/Trigonometric Function2' */
  real_T sqrtu1u1u2u2;                 /* '<S68>/sqrt(u[1]*u[1] + u[2]*u[2])' */
  real_T Product1_c;                   /* '<S68>/Product1' */
  real_T DigitalFilter2;               /* '<S66>/Digital Filter2' */
  real_T Derivative;                   /* '<S66>/Derivative' */
  real_T dG;                           /* '<S66>/dG' */
  real_T DigitalFilter;                /* '<S66>/Digital Filter' */
  real_T TrigonometricFunction_d;      /* '<S68>/Trigonometric Function' */
  real_T Product_a;                    /* '<S68>/Product' */
  real_T DigitalFilter2_n;             /* '<S67>/Digital Filter2' */
  real_T Derivative_l;                 /* '<S67>/Derivative' */
  real_T dG_m;                         /* '<S67>/dG' */
  real_T DigitalFilter_j;              /* '<S67>/Digital Filter' */
  real_T Switch[2];                    /* '<S9>/Switch' */
  real_T Clock_j;                      /* '<S42>/Clock' */
  real_T Clock_n;                      /* '<S46>/Clock' */
  real_T Sum_e;                        /* '<S46>/Sum' */
  real_T Sum_j;                        /* '<S42>/Sum' */
  real_T Abs2;                         /* '<S39>/Abs2' */
  real_T Abs3;                         /* '<S39>/Abs3' */
  real_T Clock_a;                      /* '<S44>/Clock' */
  real_T Sum_js;                       /* '<S44>/Sum' */
  real_T Clock_au;                     /* '<S43>/Clock' */
  real_T Sum_m;                        /* '<S43>/Sum' */
  real_T x;                            /* '<S22>/x' */
  real_T x_a;                          /* '<S23>/x' */
  real_T Add;                          /* '<S20>/Add' */
  real_T x_k;                          /* '<S24>/x' */
  real_T x_j;                          /* '<S25>/x' */
  real_T MultiportSwitch[2];           /* '<S3>/Multiport Switch' */
  real_T x_o;                          /* '<S16>/x' */
  real_T x_l;                          /* '<S17>/x' */
  real_T Add_h;                        /* '<S14>/Add' */
  real_T x_h;                          /* '<S18>/x' */
  real_T x_lk;                         /* '<S19>/x' */
  real_T LoadSelectSwitch[2];          /* '<S2>/LoadSelect Switch' */
  real_T BCStimTable[32];              /* '<Root>/BCStimTable' */
  real_T Reshape[32];                  /* '<Root>/Reshape' */
  real_T BehaviorBF_o1[2];             /* '<Root>/Behavior BF' */
  real_T BehaviorBF_o2[5];             /* '<Root>/Behavior BF' */
  real_T BehaviorBF_o3;                /* '<Root>/Behavior BF' */
  real_T BehaviorBF_o4[15];            /* '<Root>/Behavior BF' */
  real_T BehaviorBF_o5;                /* '<Root>/Behavior BF' */
  real_T BehaviorBF_o6[2];             /* '<Root>/Behavior BF' */
  real_T BehaviorBF_o7[4];             /* '<Root>/Behavior BF' */
  real_T BehaviorBF_o8[2];             /* '<Root>/Behavior BF' */
  real_T Switch2[2];                   /* '<S4>/Switch2' */
  real_T MG1;                          /* '<S4>/MG1' */
  real_T MG2;                          /* '<S4>/MG2' */
  real_T Clock_jl;                     /* '<S64>/Clock' */
  real_T HiddenBuf_InsertedFor_Sampleand;/* 'synthesized block' */
  real_T Sum_a;                        /* '<S64>/Sum' */
  real_T UniformRandomNumber;          /* '<S6>/Uniform Random Number' */
  real_T Switch_p;                     /* '<S6>/Switch' */
  real_T HiddenBuf_InsertedFor_Samplea_b;/* 'synthesized block' */
  real_T DataTypeConversion;           /* '<S6>/Data Type Conversion' */
  real_T y;                            /* '<S16>/y' */
  real_T Add1;                         /* '<S16>/Add1' */
  real_T z;                            /* '<S16>/z' */
  real_T Add3;                         /* '<S16>/Add3' */
  real_T product2;                     /* '<S16>/product2' */
  real_T Add2;                         /* '<S16>/Add2' */
  real_T product3;                     /* '<S16>/product3' */
  real_T product4;                     /* '<S16>/product4' */
  real_T Add4;                         /* '<S16>/Add4' */
  real_T product1;                     /* '<S16>/product1' */
  real_T dX;                           /* '<S16>/dX' */
  real_T AddX;                         /* '<S16>/AddX' */
  real_T dY;                           /* '<S16>/dY' */
  real_T AddX1;                        /* '<S16>/AddX1' */
  real_T dZ;                           /* '<S16>/dZ' */
  real_T AddX2;                        /* '<S16>/AddX2' */
  real_T y_e;                          /* '<S17>/y' */
  real_T Add1_a;                       /* '<S17>/Add1' */
  real_T z_o;                          /* '<S17>/z' */
  real_T Add3_d;                       /* '<S17>/Add3' */
  real_T product2_d;                   /* '<S17>/product2' */
  real_T Add2_p;                       /* '<S17>/Add2' */
  real_T product3_o;                   /* '<S17>/product3' */
  real_T product4_l;                   /* '<S17>/product4' */
  real_T Add4_j;                       /* '<S17>/Add4' */
  real_T product1_h;                   /* '<S17>/product1' */
  real_T dX_c;                         /* '<S17>/dX' */
  real_T AddX_a;                       /* '<S17>/AddX' */
  real_T dY_l;                         /* '<S17>/dY' */
  real_T AddX1_l;                      /* '<S17>/AddX1' */
  real_T dZ_h;                         /* '<S17>/dZ' */
  real_T AddX2_a;                      /* '<S17>/AddX2' */
  real_T y_g;                          /* '<S18>/y' */
  real_T Add1_e;                       /* '<S18>/Add1' */
  real_T z_d;                          /* '<S18>/z' */
  real_T Add3_n;                       /* '<S18>/Add3' */
  real_T product2_a;                   /* '<S18>/product2' */
  real_T Add2_o;                       /* '<S18>/Add2' */
  real_T product3_f;                   /* '<S18>/product3' */
  real_T product4_j;                   /* '<S18>/product4' */
  real_T Add4_k;                       /* '<S18>/Add4' */
  real_T product1_k;                   /* '<S18>/product1' */
  real_T dX_k;                         /* '<S18>/dX' */
  real_T AddX_n;                       /* '<S18>/AddX' */
  real_T dY_e;                         /* '<S18>/dY' */
  real_T AddX1_i;                      /* '<S18>/AddX1' */
  real_T dZ_d;                         /* '<S18>/dZ' */
  real_T AddX2_b;                      /* '<S18>/AddX2' */
  real_T y_h;                          /* '<S19>/y' */
  real_T Add1_k;                       /* '<S19>/Add1' */
  real_T z_a;                          /* '<S19>/z' */
  real_T Add3_e;                       /* '<S19>/Add3' */
  real_T product2_ad;                  /* '<S19>/product2' */
  real_T Add2_h;                       /* '<S19>/Add2' */
  real_T product3_m;                   /* '<S19>/product3' */
  real_T product4_b;                   /* '<S19>/product4' */
  real_T Add4_e;                       /* '<S19>/Add4' */
  real_T product1_g;                   /* '<S19>/product1' */
  real_T dX_m;                         /* '<S19>/dX' */
  real_T AddX_l;                       /* '<S19>/AddX' */
  real_T dY_k;                         /* '<S19>/dY' */
  real_T AddX1_b;                      /* '<S19>/AddX1' */
  real_T dZ_a;                         /* '<S19>/dZ' */
  real_T AddX2_k;                      /* '<S19>/AddX2' */
  real_T y_f;                          /* '<S22>/y' */
  real_T Add1_a5;                      /* '<S22>/Add1' */
  real_T z_f;                          /* '<S22>/z' */
  real_T Add3_m;                       /* '<S22>/Add3' */
  real_T product2_h;                   /* '<S22>/product2' */
  real_T Add2_m;                       /* '<S22>/Add2' */
  real_T product3_g;                   /* '<S22>/product3' */
  real_T product4_jz;                  /* '<S22>/product4' */
  real_T Add4_m;                       /* '<S22>/Add4' */
  real_T product1_d;                   /* '<S22>/product1' */
  real_T dX_e;                         /* '<S22>/dX' */
  real_T AddX_lf;                      /* '<S22>/AddX' */
  real_T dY_g;                         /* '<S22>/dY' */
  real_T AddX1_j;                      /* '<S22>/AddX1' */
  real_T dZ_o;                         /* '<S22>/dZ' */
  real_T AddX2_i;                      /* '<S22>/AddX2' */
  real_T y_m;                          /* '<S23>/y' */
  real_T Add1_h;                       /* '<S23>/Add1' */
  real_T z_dm;                         /* '<S23>/z' */
  real_T Add3_c;                       /* '<S23>/Add3' */
  real_T product2_k;                   /* '<S23>/product2' */
  real_T Add2_mo;                      /* '<S23>/Add2' */
  real_T product3_i;                   /* '<S23>/product3' */
  real_T product4_c;                   /* '<S23>/product4' */
  real_T Add4_a;                       /* '<S23>/Add4' */
  real_T product1_j;                   /* '<S23>/product1' */
  real_T dX_j;                         /* '<S23>/dX' */
  real_T AddX_o;                       /* '<S23>/AddX' */
  real_T dY_i;                         /* '<S23>/dY' */
  real_T AddX1_be;                     /* '<S23>/AddX1' */
  real_T dZ_n;                         /* '<S23>/dZ' */
  real_T AddX2_p;                      /* '<S23>/AddX2' */
  real_T y_gr;                         /* '<S24>/y' */
  real_T Add1_ap;                      /* '<S24>/Add1' */
  real_T z_h;                          /* '<S24>/z' */
  real_T Add3_j;                       /* '<S24>/Add3' */
  real_T product2_l;                   /* '<S24>/product2' */
  real_T Add2_my;                      /* '<S24>/Add2' */
  real_T product3_a;                   /* '<S24>/product3' */
  real_T product4_g;                   /* '<S24>/product4' */
  real_T Add4_c;                       /* '<S24>/Add4' */
  real_T product1_n;                   /* '<S24>/product1' */
  real_T dX_eq;                        /* '<S24>/dX' */
  real_T AddX_c;                       /* '<S24>/AddX' */
  real_T dY_m;                         /* '<S24>/dY' */
  real_T AddX1_f;                      /* '<S24>/AddX1' */
  real_T dZ_n4;                        /* '<S24>/dZ' */
  real_T AddX2_e;                      /* '<S24>/AddX2' */
  real_T y_d;                          /* '<S25>/y' */
  real_T Add1_o;                       /* '<S25>/Add1' */
  real_T z_k;                          /* '<S25>/z' */
  real_T Add3_do;                      /* '<S25>/Add3' */
  real_T product2_g;                   /* '<S25>/product2' */
  real_T Add2_l;                       /* '<S25>/Add2' */
  real_T product3_j;                   /* '<S25>/product3' */
  real_T product4_o;                   /* '<S25>/product4' */
  real_T Add4_g;                       /* '<S25>/Add4' */
  real_T product1_o;                   /* '<S25>/product1' */
  real_T dX_d;                         /* '<S25>/dX' */
  real_T AddX_k;                       /* '<S25>/AddX' */
  real_T dY_iv;                        /* '<S25>/dY' */
  real_T AddX1_m;                      /* '<S25>/AddX1' */
  real_T dZ_b;                         /* '<S25>/dZ' */
  real_T AddX2_ez;                     /* '<S25>/AddX2' */
  real_T MatrixConcatenation1[4];      /* '<Root>/Matrix Concatenation1' */
  real_T ForIterator;                  /* '<S69>/For Iterator' */
  real_T Switch_f;                     /* '<S69>/Switch' */
  real_T ToBits1_o1;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o2;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o3;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o4;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o5;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o6;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o7;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o8;                   /* '<S69>/ToBits1' */
  real_T Add_e;                        /* '<S69>/Add' */
  real_T Add1_d;                       /* '<S69>/Add1' */
  real_T SerialConverter;              /* '<S69>/SerialConverter' */
  real_T ToBits_o1;                    /* '<S69>/ToBits' */
  real_T ToBits_o2;                    /* '<S69>/ToBits' */
  real_T ToBits_o3;                    /* '<S69>/ToBits' */
  real_T ToBits_o4;                    /* '<S69>/ToBits' */
  real_T ToBits_o5;                    /* '<S69>/ToBits' */
  real_T ToBits_o6;                    /* '<S69>/ToBits' */
  real_T ToBits_o7;                    /* '<S69>/ToBits' */
  real_T ToBits_o8;                    /* '<S69>/ToBits' */
  real_T xPCTargetTime;                /* '<S69>/xPC Target  Time ' */
  real_T xPCTargetTime_h;              /* '<S71>/xPC Target  Time ' */
  real_T Subtract;                     /* '<S71>/Subtract' */
  real_T ScaleTouSec;                  /* '<S71>/ScaleTouSec' */
  real_T Switch_e;                     /* '<S71>/Switch' */
  real_T TachGain2;                    /* '<S9>/TachGain2' */
  real_T TachGain1;                    /* '<S9>/TachGain1' */
  real_T TmpHiddenBufferAtMatrixMultiply[2];/* 'synthesized block' */
  real_T MatrixMultiply[2];            /* '<S9>/Matrix Multiply' */
  real_T Gain_j[2];                    /* '<S28>/Gain' */
  real_T MathFunction[4];              /* '<S32>/Math Function' */
  real_T MatrixMultiply_g[2];          /* '<S28>/Matrix Multiply' */
  real_T Switch1[2];                   /* '<S4>/Switch1' */
  real_T Switch_g[2];                  /* '<S5>/Switch' */
  real_T BoundingBoxViscosity[2];      /* '<S5>/Bounding Box Viscosity' */
  real_T Product_m;                    /* '<S40>/Product' */
  real_T Gain1_l;                      /* '<S40>/Gain1' */
  real_T Gain3;                        /* '<S40>/Gain3' */
  real_T Add_p;                        /* '<S40>/Add' */
  real_T Saturation;                   /* '<S40>/Saturation' */
  real_T Gain4;                        /* '<S40>/Gain4' */
  real_T Product1_m;                   /* '<S40>/Product1' */
  real_T Gain2;                        /* '<S40>/Gain2' */
  real_T Add1_p;                       /* '<S40>/Add1' */
  real_T Saturation1;                  /* '<S40>/Saturation1' */
  real_T Add1_k1;                      /* '<S20>/Add1' */
  real_T LorentzForceGain[2];          /* '<S3>/LorentzForceGain' */
  real_T dynamicAngleSwitch;           /* '<S3>/dynamicAngle Switch' */
  real_T sin_h;                        /* '<S21>/sin' */
  real_T Inverter[2];                  /* '<S21>/Inverter' */
  real_T Product3_p;                   /* '<S21>/Product3' */
  real_T cos_b;                        /* '<S21>/cos' */
  real_T Product2_j;                   /* '<S21>/Product2' */
  real_T Subtract_d;                   /* '<S21>/Subtract' */
  real_T Product1_h;                   /* '<S21>/Product1' */
  real_T Product_n;                    /* '<S21>/Product' */
  real_T Add_k;                        /* '<S21>/Add' */
  real_T Gain_b[2];                    /* '<S21>/Gain' */
  real_T Gain_o;                       /* '<S3>/Gain' */
  real_T Add1_j;                       /* '<S14>/Add1' */
  real_T LorentzForceGain_a[2];        /* '<S2>/LorentzForceGain' */
  real_T DynamicAngleSwitch;           /* '<S2>/DynamicAngle Switch' */
  real_T sin_c;                        /* '<S15>/sin' */
  real_T Inverter_o[2];                /* '<S15>/Inverter' */
  real_T Product3_m;                   /* '<S15>/Product3' */
  real_T cos_n;                        /* '<S15>/cos' */
  real_T Product2_n;                   /* '<S15>/Product2' */
  real_T Subtract_k;                   /* '<S15>/Subtract' */
  real_T Product1_hu;                  /* '<S15>/Product1' */
  real_T Product_g;                    /* '<S15>/Product' */
  real_T Add_j;                        /* '<S15>/Add' */
  real_T Gain_f[2];                    /* '<S15>/Gain' */
  real_T Gain_p;                       /* '<S2>/Gain' */
  uint8_T Compare;                     /* '<S33>/Compare' */
  uint8_T Compare_k;                   /* '<S35>/Compare' */
  uint8_T Compare_i;                   /* '<S36>/Compare' */
  uint8_T Compare_m;                   /* '<S59>/Compare' */
  uint8_T Compare_n;                   /* '<S62>/Compare' */
  uint8_T Uk1;                         /* '<S60>/Delay Input1' */
  uint8_T FixPtRelationalOperator;     /* '<S60>/FixPt Relational Operator' */
  uint8_T Compare_p;                   /* '<S52>/Compare' */
  uint8_T Compare_e;                   /* '<S50>/Compare' */
  uint8_T Compare_eu;                  /* '<S51>/Compare' */
  uint8_T Compare_j;                   /* '<S58>/Compare' */
  uint8_T Uk1_k;                       /* '<S45>/Delay Input1' */
  uint8_T FixPtRelationalOperator_d;   /* '<S45>/FixPt Relational Operator' */
  uint8_T Compare_c;                   /* '<S56>/Compare' */
  uint8_T Compare_eb;                  /* '<S49>/Compare' */
  uint8_T Uk1_m;                       /* '<S38>/Delay Input1' */
  uint8_T FixPtRelationalOperator_i;   /* '<S38>/FixPt Relational Operator' */
  uint8_T Compare_cj;                  /* '<S54>/Compare' */
  uint8_T Compare_g;                   /* '<S48>/Compare' */
  uint8_T Uk1_p;                       /* '<S37>/Delay Input1' */
  uint8_T FixPtRelationalOperator_a;   /* '<S37>/FixPt Relational Operator' */
  uint8_T Compare_eo;                  /* '<S26>/Compare' */
  uint8_T Compare_pk;                  /* '<S27>/Compare' */
  uint8_T Pack[168];                   /* '<S7>/Pack' */
  uint8_T RateTransition[168];         /* '<S7>/Rate Transition' */
  boolean_T Memory;                    /* '<S30>/Memory' */
  boolean_T Memory_d;                  /* '<S4>/Memory' */
  boolean_T LogicalOperator2;          /* '<S30>/Logical Operator2' */
  boolean_T LogicalOperator1;          /* '<S30>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_EnabledSu;/* '<S30>/Logical Operator1' */
  boolean_T RelationalOperator;        /* '<S30>/Relational Operator' */
  boolean_T LogicalOperator;           /* '<S30>/Logical Operator' */
  boolean_T Memory_o;                  /* '<S42>/Memory' */
  boolean_T RelationalOperator_k;      /* '<S1>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S1>/Relational Operator1' */
  boolean_T RelationalOperator2;       /* '<S1>/Relational Operator2' */
  boolean_T RelationalOperator3;       /* '<S1>/Relational Operator3' */
  boolean_T LogicalOperator_a;         /* '<S1>/Logical Operator' */
  boolean_T InBox;                     /* '<S5>/InBox' */
  boolean_T LogicalOperator3;          /* '<S46>/Logical Operator3' */
  boolean_T Memory_m;                  /* '<S46>/Memory' */
  boolean_T LogicalOperator4;          /* '<S46>/Logical Operator4' */
  boolean_T LogicalOperator_c;         /* '<S5>/Logical Operator' */
  boolean_T LogicalOperator2_m;        /* '<S46>/Logical Operator2' */
  boolean_T LogicalOperator1_e;        /* '<S46>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_p;/* '<S46>/Logical Operator1' */
  boolean_T RelationalOperator_k4;     /* '<S46>/Relational Operator' */
  boolean_T LogicalOperator_k;         /* '<S46>/Logical Operator' */
  boolean_T LogicalOperator5;          /* '<S46>/Logical Operator5' */
  boolean_T LogicalOperator2_b;        /* '<S42>/Logical Operator2' */
  boolean_T LogicalOperator1_ef;       /* '<S42>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_k;/* '<S42>/Logical Operator1' */
  boolean_T RelationalOperator_b;      /* '<S42>/Relational Operator' */
  boolean_T LogicalOperator_d;         /* '<S42>/Logical Operator' */
  boolean_T LogicalOperator1_d;        /* '<S39>/Logical Operator1' */
  boolean_T NOT;                       /* '<S5>/NOT' */
  boolean_T Memory_oj;                 /* '<S44>/Memory' */
  boolean_T LogicalOperator2_c;        /* '<S44>/Logical Operator2' */
  boolean_T LogicalOperator1_a;        /* '<S44>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_h;/* '<S44>/Logical Operator1' */
  boolean_T RelationalOperator_o;      /* '<S44>/Relational Operator' */
  boolean_T LogicalOperator_c3;        /* '<S44>/Logical Operator' */
  boolean_T DataTypeConversion2;       /* '<S5>/Data Type Conversion2' */
  boolean_T LogicalOperator1_l;        /* '<S5>/Logical Operator1' */
  boolean_T Memory_g;                  /* '<S43>/Memory' */
  boolean_T LogicalOperator2_c2;       /* '<S43>/Logical Operator2' */
  boolean_T LogicalOperator1_o;        /* '<S43>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_g;/* '<S43>/Logical Operator1' */
  boolean_T RelationalOperator_e;      /* '<S43>/Relational Operator' */
  boolean_T LogicalOperator_b;         /* '<S43>/Logical Operator' */
  boolean_T DataTypeConversion1;       /* '<S5>/Data Type Conversion1' */
  boolean_T Memory_p;                  /* '<S41>/Memory' */
  boolean_T Logic[2];                  /* '<S41>/Logic' */
  boolean_T LogicalOperator5_k;        /* '<S5>/Logical Operator5' */
  boolean_T LogicalOperator1_n;        /* '<S4>/Logical Operator1' */
  boolean_T MatrixConcatenation[2];    /* '<S4>/Matrix Concatenation' */
  boolean_T RelationalOperator_d;      /* '<S6>/Relational Operator' */
  boolean_T RelationalOperator_h;      /* '<S64>/Relational Operator' */
  boolean_T Compare_c3;                /* '<S73>/Compare' */
  boolean_T Compare_l;                 /* '<S72>/Compare' */
  boolean_T LogicalOperator6;          /* '<S5>/Logical Operator6' */
  boolean_T LogicalOperator3_d;        /* '<S5>/Logical Operator3' */
  rtB_SampleandHold_bump_follow SampleandHold;/* '<S64>/Sample and Hold' */
  rtB_SampleandHold_bump_follow SampleandHold_k;/* '<S6>/Sample and Hold' */
  rtB_EnabledSubsystem_bump_follo EnabledSubsystem_o;/* '<S46>/Enabled Subsystem' */
  rtB_EnabledSubsystem_bump_follo EnabledSubsystem_f;/* '<S44>/Enabled Subsystem' */
  rtB_EnabledSubsystem_bump_follo EnabledSubsystem_df;/* '<S43>/Enabled Subsystem' */
  rtB_EnabledSubsystem_bump_follo EnabledSubsystem_d;/* '<S42>/Enabled Subsystem' */
  rtB_EnabledSubsystem_bump_follo EnabledSubsystem;/* '<S30>/Enabled Subsystem' */
} BlockIO_bump_follow;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DigitalFilter2_FILT_STATES[11];/* '<S66>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES[11];/* '<S66>/Digital Filter' */
  real_T DigitalFilter2_FILT_STATES_h[11];/* '<S67>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES_d[11];/* '<S67>/Digital Filter' */
  real_T x_DSTATE;                     /* '<S22>/x' */
  real_T x_DSTATE_d;                   /* '<S23>/x' */
  real_T x_DSTATE_j;                   /* '<S24>/x' */
  real_T x_DSTATE_o;                   /* '<S25>/x' */
  real_T x_DSTATE_g;                   /* '<S16>/x' */
  real_T x_DSTATE_m;                   /* '<S17>/x' */
  real_T x_DSTATE_dy;                  /* '<S18>/x' */
  real_T x_DSTATE_oe;                  /* '<S19>/x' */
  real_T BehaviorBF_DSTATE;            /* '<Root>/Behavior BF' */
  real_T y_DSTATE;                     /* '<S16>/y' */
  real_T z_DSTATE;                     /* '<S16>/z' */
  real_T y_DSTATE_o;                   /* '<S17>/y' */
  real_T z_DSTATE_m;                   /* '<S17>/z' */
  real_T y_DSTATE_d;                   /* '<S18>/y' */
  real_T z_DSTATE_h;                   /* '<S18>/z' */
  real_T y_DSTATE_j;                   /* '<S19>/y' */
  real_T z_DSTATE_e;                   /* '<S19>/z' */
  real_T y_DSTATE_g;                   /* '<S22>/y' */
  real_T z_DSTATE_g;                   /* '<S22>/z' */
  real_T y_DSTATE_jx;                  /* '<S23>/y' */
  real_T z_DSTATE_g3;                  /* '<S23>/z' */
  real_T y_DSTATE_a;                   /* '<S24>/y' */
  real_T z_DSTATE_f;                   /* '<S24>/z' */
  real_T y_DSTATE_jh;                  /* '<S25>/y' */
  real_T z_DSTATE_o;                   /* '<S25>/z' */
  real_T PCI6025EAD_RWORK[64];         /* '<S9>/PCI-6025E AD' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S66>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_d;                /* '<S67>/Derivative' */

  real_T BehaviorBF_RWORK[7];          /* '<Root>/Behavior BF' */
  real_T PCI6025E_RWORK[6];            /* '<S4>/PCI-6025E ' */
  struct {
    real_T NextOutput;
  } UniformRandomNumber_RWORK;         /* '<S6>/Uniform Random Number' */

  void *BehaviorBF_PWORK;              /* '<Root>/Behavior BF' */
  void *Send_PWORK;                    /* '<S7>/Send' */
  int32_T DigitalFilter2_CIRCBUFFIDX;  /* '<S66>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX;   /* '<S66>/Digital Filter' */
  int32_T DigitalFilter2_CIRCBUFFIDX_m;/* '<S67>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX_p; /* '<S67>/Digital Filter' */
  int_T PCIQUAD04_IWORK;               /* '<S12>/PCI-QUAD04 ' */
  int_T PCIQUAD041_IWORK;              /* '<S12>/PCI-QUAD04 1' */
  int_T PCI6025EAD_IWORK[66];          /* '<S9>/PCI-6025E AD' */
  int_T BehaviorBF_IWORK[28];          /* '<Root>/Behavior BF' */
  int_T PCI6025E_IWORK[2];             /* '<S4>/PCI-6025E ' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S29>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_i;                 /* '<S31>/S-Function' */

  int_T Send_IWORK[2];                 /* '<S7>/Send' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK_g;                 /* '<S8>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_l;                 /* '<S10>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_f;                 /* '<S13>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_h;                 /* '<S47>/S-Function' */

  struct {
    int_T RandSeed;
  } UniformRandomNumber_IWORK;         /* '<S6>/Uniform Random Number' */

  int_T PortA_IWORK[2];                /* '<S69>/Port A' */
  int_T PortB_IWORK[2];                /* '<S69>/Port B' */
  int_T PCI6025E_IWORK_c[3];           /* '<S71>/PCI-6025E ' */
  uint8_T DelayInput1_DSTATE;          /* '<S60>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_m;        /* '<S45>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_a;        /* '<S38>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_k;        /* '<S37>/Delay Input1' */
  boolean_T Memory_PreviousInput;      /* '<S30>/Memory' */
  boolean_T Memory_PreviousInput_o;    /* '<S4>/Memory' */
  boolean_T Memory_PreviousInput_f;    /* '<S42>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<S46>/Memory' */
  boolean_T Memory_PreviousInput_d;    /* '<S44>/Memory' */
  boolean_T Memory_PreviousInput_p;    /* '<S43>/Memory' */
  boolean_T Memory_PreviousInput_g;    /* '<S41>/Memory' */
  rtDW_SampleandHold_bump_follow SampleandHold;/* '<S64>/Sample and Hold' */
  rtDW_SampleandHold_bump_follow SampleandHold_k;/* '<S6>/Sample and Hold' */
  rtDW_EnabledSubsystem_bump_foll EnabledSubsystem_o;/* '<S46>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_bump_foll EnabledSubsystem_f;/* '<S44>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_bump_foll EnabledSubsystem_df;/* '<S43>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_bump_foll EnabledSubsystem_d;/* '<S42>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_bump_foll EnabledSubsystem;/* '<S30>/Enabled Subsystem' */
} D_Work_bump_follow;

/* Zero-crossing (trigger) state */
typedef struct {
  rtZCE_SampleandHold_bump_follow SampleandHold;/* '<S6>/Sample and Hold' */
  rtZCE_SampleandHold_bump_follow SampleandHold_k;/* '<S6>/Sample and Hold' */
} PrevZCSigStates_bump_follow;

/* Backward compatible GRT Identifiers */
#define rtB                            bump_follow_B
#define BlockIO                        BlockIO_bump_follow
#define rtXdot                         bump_follow_Xdot
#define StateDerivatives               StateDerivatives_bump_follow
#define tXdis                          bump_follow_Xdis
#define StateDisabled                  StateDisabled_bump_follow
#define rtP                            bump_follow_P
#define Parameters                     Parameters_bump_follow
#define rtDWork                        bump_follow_DWork
#define D_Work                         D_Work_bump_follow
#define rtPrevZCSigState               bump_follow_PrevZCSigState
#define PrevZCSigStates                PrevZCSigStates_bump_follow

/* Parameters for system: '<S6>/Sample and Hold' */
struct rtP_SampleandHold_bump_follow {
  real_T _Y0;                          /* Expression: initCond
                                        * 'synthesized block'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_bump_follow {
  real_T Time_Value;                   /* Expression: Time
                                        * '<S30>/Time'
                                        */
  real_T PCIQUAD04_P1_Size[2];         /* Computed Parameter: P1Size
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P1;                 /* Expression: convbaseaddr
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P2_Size[2];         /* Computed Parameter: P2Size
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P2;                 /* Expression: channel
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P3_Size[2];         /* Computed Parameter: P3Size
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P3;                 /* Expression: resetmode
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P4_Size[2];         /* Computed Parameter: P4Size
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P4;                 /* Expression: polarity
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P5_Size[2];         /* Computed Parameter: P5Size
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P5;                 /* Expression: mode
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P6_Size[2];         /* Computed Parameter: P6Size
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P6;                 /* Expression: limit
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P7_Size[2];         /* Computed Parameter: P7Size
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P7;                 /* Expression: range
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P8_Size[2];         /* Computed Parameter: P8Size
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P8;                 /* Expression: speed
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P9_Size[2];         /* Computed Parameter: P9Size
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P9;                 /* Expression: prescale
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P10_Size[2];        /* Computed Parameter: P10Size
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P10;                /* Expression: ts
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P11_Size[2];        /* Computed Parameter: P11Size
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P11;                /* Expression: boardtype
                                        * '<S12>/PCI-QUAD04 '
                                        */
  real_T Gain_Gain;                    /* Expression: 3.490658e-4
                                        * '<S12>/Gain'
                                        */
  real_T shoulderOffset_Value;         /* Expression: 0
                                        * '<S12>/shoulderOffset'
                                        */
  real_T L1_Value;                     /* Expression: 24
                                        * '<S70>/L1'
                                        */
  real_T Gain_Gain_e;                  /* Expression: -1
                                        * '<S70>/Gain'
                                        */
  real_T PCIQUAD041_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P1;                /* Expression: convbaseaddr
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P2;                /* Expression: channel
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P3;                /* Expression: resetmode
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P4;                /* Expression: polarity
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P5;                /* Expression: mode
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P6;                /* Expression: limit
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P7_Size[2];        /* Computed Parameter: P7Size
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P7;                /* Expression: range
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P8_Size[2];        /* Computed Parameter: P8Size
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P8;                /* Expression: speed
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P9_Size[2];        /* Computed Parameter: P9Size
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P9;                /* Expression: prescale
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P10_Size[2];       /* Computed Parameter: P10Size
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P10;               /* Expression: ts
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P11_Size[2];       /* Computed Parameter: P11Size
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P11;               /* Expression: boardtype
                                        * '<S12>/PCI-QUAD04 1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -3.490658e-4
                                        * '<S12>/Gain1'
                                        */
  real_T elbowOffset_Value;            /* Expression: 0
                                        * '<S12>/elbowOffset'
                                        */
  real_T L2_Value;                     /* Expression: 23.5
                                        * '<S70>/L2'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: -1
                                        * '<S70>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * '<S70>/Gain2'
                                        */
  real_T PCI6025EAD_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P1[2];             /* Expression: channel
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P2[2];             /* Expression: range
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P3[2];             /* Expression: coupling
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P4;                /* Expression: sampletime
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P5;                /* Expression: slot
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P6;                /* Expression: boardType
                                        * '<S9>/PCI-6025E AD'
                                        */
  real_T UseTachs_Value;               /* Expression: 1
                                        * '<S9>/UseTachs'
                                        */
  real_T yoffset_Value;                /* Expression: 32
                                        * '<S70>/yoffset'
                                        */
  real_T xoffset_Value;                /* Expression: 1
                                        * '<S70>/xoffset'
                                        */
  real_T AngleOffset_Value;            /* Expression: 0
                                        * '<S68>/AngleOffset'
                                        */
  real_T DigitalFilter2_ICRTP;         /* Expression: a.IC
                                        * '<S66>/Digital Filter2'
                                        */
  real_T DigitalFilter2_RTP1COEFF[11]; /* Expression: NumCoeffs
                                        * '<S66>/Digital Filter2'
                                        */
  real_T dG_Gain;                      /* Expression: 1
                                        * '<S66>/dG'
                                        */
  real_T DigitalFilter_ICRTP;          /* Expression: a.IC
                                        * '<S66>/Digital Filter'
                                        */
  real_T DigitalFilter_RTP1COEFF[11];  /* Expression: NumCoeffs
                                        * '<S66>/Digital Filter'
                                        */
  real_T DigitalFilter2_ICRTP_h;       /* Expression: a.IC
                                        * '<S67>/Digital Filter2'
                                        */
  real_T DigitalFilter2_RTP1COEFF_e[11];/* Expression: NumCoeffs
                                         * '<S67>/Digital Filter2'
                                         */
  real_T dG_Gain_l;                    /* Expression: 1
                                        * '<S67>/dG'
                                        */
  real_T DigitalFilter_ICRTP_n;        /* Expression: a.IC
                                        * '<S67>/Digital Filter'
                                        */
  real_T DigitalFilter_RTP1COEFF_b[11];/* Expression: NumCoeffs
                                        * '<S67>/Digital Filter'
                                        */
  real_T Switch_Threshold;             /* Expression: .5
                                        * '<S9>/Switch'
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
  real_T RecenterFlag_Value;           /* Expression: 1
                                        * '<S5>/RecenterFlag'
                                        */
  real_T Time_Value_c;                 /* Expression: Time
                                        * '<S46>/Time'
                                        */
  real_T Time_Value_o;                 /* Expression: Time
                                        * '<S42>/Time'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * '<S50>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: const
                                        * '<S51>/Constant'
                                        */
  real_T Time_Value_l;                 /* Expression: Time
                                        * '<S44>/Time'
                                        */
  real_T Time_Value_i;                 /* Expression: Time
                                        * '<S43>/Time'
                                        */
  real_T Load_Value;                   /* Expression: 0
                                        * '<S3>/Load'
                                        */
  real_T x_X0;                         /* Expression: .1
                                        * '<S22>/x'
                                        */
  real_T x_X0_o;                       /* Expression: .1
                                        * '<S23>/x'
                                        */
  real_T x_X0_h;                       /* Expression: .1
                                        * '<S24>/x'
                                        */
  real_T x_X0_g;                       /* Expression: .1
                                        * '<S25>/x'
                                        */
  real_T Load_Value_g;                 /* Expression: 0
                                        * '<S2>/Load'
                                        */
  real_T x_X0_p;                       /* Expression: .1
                                        * '<S16>/x'
                                        */
  real_T x_X0_k;                       /* Expression: .1
                                        * '<S17>/x'
                                        */
  real_T x_X0_e;                       /* Expression: .1
                                        * '<S18>/x'
                                        */
  real_T x_X0_c;                       /* Expression: .1
                                        * '<S19>/x'
                                        */
  real_T BCStimTable_table[32];        /* Expression: mxTable
                                        * '<Root>/BCStimTable'
                                        */
  real_T BehaviorBF_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P1;                /* Expression: 0
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P2;                /* Expression: 10
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P3;                /* Expression: 3
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P4;                /* Expression: 1
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P5;                /* Expression: 2
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P6;                /* Expression: 5
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P7_Size[2];        /* Computed Parameter: P7Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P7;                /* Expression: 7
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P8_Size[2];        /* Computed Parameter: P8Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P8;                /* Expression: 0.0
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P9_Size[2];        /* Computed Parameter: P9Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P9;                /* Expression: 0.05
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P10_Size[2];       /* Computed Parameter: P10Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P10;               /* Expression: 125
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P11_Size[2];       /* Computed Parameter: P11Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P11;               /* Expression: 0.5
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P12_Size[2];       /* Computed Parameter: P12Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P12;               /* Expression: 2
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P13_Size[2];       /* Computed Parameter: P13Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P13;               /* Expression: 10
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P14_Size[2];       /* Computed Parameter: P14Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P14;               /* Expression: 1
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P15_Size[2];       /* Computed Parameter: P15Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P15;               /* Expression: 2
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P16_Size[2];       /* Computed Parameter: P16Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P16;               /* Expression: 0
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P17_Size[2];       /* Computed Parameter: P17Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P17;               /* Expression: 0
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P18_Size[2];       /* Computed Parameter: P18Size
                                        * '<Root>/Behavior BF'
                                        */
  real_T BehaviorBF_P18;               /* Expression: 0
                                        * '<Root>/Behavior BF'
                                        */
  real_T MG1_Gain;                     /* Expression: -1
                                        * '<S4>/MG1'
                                        */
  real_T MG2_Gain;                     /* Expression: 1
                                        * '<S4>/MG2'
                                        */
  real_T PCI6025E_P1_Size[2];          /* Computed Parameter: P1Size
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P1[2];               /* Expression: channel
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_Size[2];          /* Computed Parameter: P2Size
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P2[2];               /* Expression: range
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_Size[2];          /* Computed Parameter: P3Size
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P3[2];               /* Expression: reset
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_Size[2];          /* Computed Parameter: P4Size
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P4[2];               /* Expression: initValue
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_Size[2];          /* Computed Parameter: P5Size
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P5;                  /* Expression: sampletime
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_Size[2];          /* Computed Parameter: P6Size
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P6;                  /* Expression: slot
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_Size[2];          /* Computed Parameter: P7Size
                                        * '<S4>/PCI-6025E '
                                        */
  real_T PCI6025E_P7;                  /* Expression: boardType
                                        * '<S4>/PCI-6025E '
                                        */
  real_T Constant_Value_d;             /* Expression: const
                                        * '<S26>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: const
                                        * '<S27>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 3
                                        * '<Root>/Constant'
                                        */
  real_T Send_P1_Size[2];              /* Computed Parameter: P1Size
                                        * '<S7>/Send'
                                        */
  real_T Send_P1[11];                  /* Computed Parameter: P1
                                        * '<S7>/Send'
                                        */
  real_T Send_P2_Size[2];              /* Computed Parameter: P2Size
                                        * '<S7>/Send'
                                        */
  real_T Send_P2;                      /* Expression: ipPort
                                        * '<S7>/Send'
                                        */
  real_T Send_P3_Size[2];              /* Computed Parameter: P3Size
                                        * '<S7>/Send'
                                        */
  real_T Send_P3;                      /* Expression: localPort
                                        * '<S7>/Send'
                                        */
  real_T Send_P4_Size[2];              /* Computed Parameter: P4Size
                                        * '<S7>/Send'
                                        */
  real_T Send_P4;                      /* Expression: sampletime
                                        * '<S7>/Send'
                                        */
  real_T UniformRandomNumber_Min;      /* Expression: 0
                                        * '<S6>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Max;      /* Expression: 100
                                        * '<S6>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * '<S6>/Uniform Random Number'
                                        */
  real_T JackpotChance_Value;          /* Expression: 0
                                        * '<S6>/JackpotChance'
                                        */
  real_T y_X0;                         /* Expression: y0
                                        * '<S16>/y'
                                        */
  real_T rho_Value;                    /* Expression: 28
                                        * '<S16>/rho'
                                        */
  real_T z_X0;                         /* Expression: .1
                                        * '<S16>/z'
                                        */
  real_T beta_Value;                   /* Expression: 8/3
                                        * '<S16>/beta'
                                        */
  real_T timescale_Value;              /* Expression: .0001
                                        * '<S16>/timescale'
                                        */
  real_T sigma_Value;                  /* Expression: 10
                                        * '<S16>/sigma'
                                        */
  real_T y_X0_e;                       /* Expression: y0
                                        * '<S17>/y'
                                        */
  real_T rho_Value_c;                  /* Expression: 28
                                        * '<S17>/rho'
                                        */
  real_T z_X0_b;                       /* Expression: .1
                                        * '<S17>/z'
                                        */
  real_T beta_Value_c;                 /* Expression: 8/3
                                        * '<S17>/beta'
                                        */
  real_T timescale_Value_p;            /* Expression: .0001
                                        * '<S17>/timescale'
                                        */
  real_T sigma_Value_c;                /* Expression: 10
                                        * '<S17>/sigma'
                                        */
  real_T y_X0_c;                       /* Expression: y0
                                        * '<S18>/y'
                                        */
  real_T rho_Value_a;                  /* Expression: 28
                                        * '<S18>/rho'
                                        */
  real_T z_X0_c;                       /* Expression: .1
                                        * '<S18>/z'
                                        */
  real_T beta_Value_h;                 /* Expression: 8/3
                                        * '<S18>/beta'
                                        */
  real_T timescale_Value_a;            /* Expression: .0001
                                        * '<S18>/timescale'
                                        */
  real_T sigma_Value_f;                /* Expression: 10
                                        * '<S18>/sigma'
                                        */
  real_T y_X0_ce;                      /* Expression: y0
                                        * '<S19>/y'
                                        */
  real_T rho_Value_e;                  /* Expression: 28
                                        * '<S19>/rho'
                                        */
  real_T z_X0_d;                       /* Expression: .1
                                        * '<S19>/z'
                                        */
  real_T beta_Value_g;                 /* Expression: 8/3
                                        * '<S19>/beta'
                                        */
  real_T timescale_Value_o;            /* Expression: .0001
                                        * '<S19>/timescale'
                                        */
  real_T sigma_Value_l;                /* Expression: 10
                                        * '<S19>/sigma'
                                        */
  real_T y_X0_p;                       /* Expression: y0
                                        * '<S22>/y'
                                        */
  real_T rho_Value_k;                  /* Expression: 28
                                        * '<S22>/rho'
                                        */
  real_T z_X0_bq;                      /* Expression: .1
                                        * '<S22>/z'
                                        */
  real_T beta_Value_o;                 /* Expression: 8/3
                                        * '<S22>/beta'
                                        */
  real_T timescale_Value_b;            /* Expression: .0001
                                        * '<S22>/timescale'
                                        */
  real_T sigma_Value_lo;               /* Expression: 10
                                        * '<S22>/sigma'
                                        */
  real_T y_X0_pj;                      /* Expression: y0
                                        * '<S23>/y'
                                        */
  real_T rho_Value_j;                  /* Expression: 28
                                        * '<S23>/rho'
                                        */
  real_T z_X0_a;                       /* Expression: .1
                                        * '<S23>/z'
                                        */
  real_T beta_Value_hu;                /* Expression: 8/3
                                        * '<S23>/beta'
                                        */
  real_T timescale_Value_j;            /* Expression: .0001
                                        * '<S23>/timescale'
                                        */
  real_T sigma_Value_m;                /* Expression: 10
                                        * '<S23>/sigma'
                                        */
  real_T y_X0_g;                       /* Expression: y0
                                        * '<S24>/y'
                                        */
  real_T rho_Value_o;                  /* Expression: 28
                                        * '<S24>/rho'
                                        */
  real_T z_X0_m;                       /* Expression: .1
                                        * '<S24>/z'
                                        */
  real_T beta_Value_oe;                /* Expression: 8/3
                                        * '<S24>/beta'
                                        */
  real_T timescale_Value_jr;           /* Expression: .0001
                                        * '<S24>/timescale'
                                        */
  real_T sigma_Value_n;                /* Expression: 10
                                        * '<S24>/sigma'
                                        */
  real_T y_X0_j;                       /* Expression: y0
                                        * '<S25>/y'
                                        */
  real_T rho_Value_ed;                 /* Expression: 28
                                        * '<S25>/rho'
                                        */
  real_T z_X0_h;                       /* Expression: .1
                                        * '<S25>/z'
                                        */
  real_T beta_Value_m;                 /* Expression: 8/3
                                        * '<S25>/beta'
                                        */
  real_T timescale_Value_c;            /* Expression: .0001
                                        * '<S25>/timescale'
                                        */
  real_T sigma_Value_j;                /* Expression: 10
                                        * '<S25>/sigma'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 0.0367
                                        * '<S2>/Gain'
                                        */
  real_T visAngle_Value;               /* Expression: 0
                                        * '<S2>/visAngle'
                                        */
  real_T DynamicAngle_Value;           /* Expression: 0
                                        * '<S2>/DynamicAngle'
                                        */
  real_T Inverter_Gain;                /* Expression: -1
                                        * '<S15>/Inverter'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 1
                                        * '<S15>/Gain'
                                        */
  real_T LorentzForceGain_Gain;        /* Expression: .0005
                                        * '<S2>/LorentzForceGain'
                                        */
  real_T staticX_Value;                /* Expression: 0
                                        * '<S2>/staticX'
                                        */
  real_T staticY_Value;                /* Expression: 0
                                        * '<S2>/staticY'
                                        */
  real_T Off_Value;                    /* Expression: 0
                                        * '<S2>/Off'
                                        */
  real_T Gain_Gain_ex;                 /* Expression: 0.0367
                                        * '<S3>/Gain'
                                        */
  real_T visAngle_Value_d;             /* Expression: 0
                                        * '<S3>/visAngle'
                                        */
  real_T DynamicAngle_Value_l;         /* Expression: 0
                                        * '<S3>/DynamicAngle'
                                        */
  real_T Inverter_Gain_f;              /* Expression: -1
                                        * '<S21>/Inverter'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 1
                                        * '<S21>/Gain'
                                        */
  real_T LorentzForceGain_Gain_e;      /* Expression: .0005
                                        * '<S3>/LorentzForceGain'
                                        */
  real_T staticX_Value_f;              /* Expression: 0
                                        * '<S3>/staticX'
                                        */
  real_T staticY_Value_h;              /* Expression: 0
                                        * '<S3>/staticY'
                                        */
  real_T Off_Value_g;                  /* Expression: 0
                                        * '<S3>/Off'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: -.001
                                        * '<S40>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: -.0002
                                        * '<S40>/Gain3'
                                        */
  real_T Saturation_UpperSat;          /* Expression: .01
                                        * '<S40>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.01
                                        * '<S40>/Saturation'
                                        */
  real_T Gain4_Gain;                   /* Expression: -.0002
                                        * '<S40>/Gain4'
                                        */
  real_T Gain2_Gain_i;                 /* Expression: -.001
                                        * '<S40>/Gain2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: .01
                                        * '<S40>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -0.01
                                        * '<S40>/Saturation1'
                                        */
  real_T BoundingBoxViscosity_Gain;    /* Expression: -0.0001
                                        * '<S5>/Bounding Box Viscosity'
                                        */
  real_T zeroX_Value;                  /* Expression: 0
                                        * '<S4>/zeroX'
                                        */
  real_T zeroY_Value;                  /* Expression: 0
                                        * '<S4>/zeroY'
                                        */
  real_T Gain_Gain_n;                  /* Expression: -1
                                        * '<S28>/Gain'
                                        */
  real_T RewardJackpot_Value;          /* Expression: 0.60
                                        * '<S6>/RewardJackpot'
                                        */
  real_T RewardTime_Value;             /* Expression: 0.30
                                        * '<S6>/RewardTime'
                                        */
  real_T TachGain2_Gain;               /* Expression: 1.29
                                        * '<S9>/TachGain2'
                                        */
  real_T TachGain1_Gain;               /* Expression: 1.29
                                        * '<S9>/TachGain1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * '<S69>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * '<S71>/Constant1'
                                        */
  real_T Constant_Value_dj;            /* Expression: 1
                                        * '<S71>/Constant'
                                        */
  real_T xPCTargetTime_P1_Size[2];     /* Computed Parameter: P1Size
                                        * '<S71>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1;             /* Expression: func
                                        * '<S71>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size[2];     /* Computed Parameter: P2Size
                                        * '<S71>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2;             /* Expression: ts
                                        * '<S71>/xPC Target  Time '
                                        */
  real_T ScaleTouSec_Gain;             /* Expression: .838
                                        * '<S71>/ScaleTouSec'
                                        */
  real_T Constant_Value_c;             /* Expression: const
                                        * '<S73>/Constant'
                                        */
  real_T PCI6025E_P1_Size_j[2];        /* Computed Parameter: P1Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P1_h[2];             /* Expression: channel
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_Size_l[2];        /* Computed Parameter: P2Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_n[2];             /* Expression: reset
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_Size_e[2];        /* Computed Parameter: P3Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_l[2];             /* Expression: initValue
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_Size_a[2];        /* Computed Parameter: P4Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_j;                /* Expression: sampletime
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_Size_h[2];        /* Computed Parameter: P5Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_c;                /* Expression: slot
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_Size_p[2];        /* Computed Parameter: P6Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_i;                /* Expression: control
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_Size_i[2];        /* Computed Parameter: P7Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_j;                /* Expression: boardType
                                        * '<S71>/PCI-6025E '
                                        */
  real_T Constant_Value_b;             /* Expression: const
                                        * '<S72>/Constant'
                                        */
  real_T Switch_Threshold_m;           /* Expression: 2
                                        * '<S69>/Switch'
                                        */
  real_T PortA_P1_Size[2];             /* Computed Parameter: P1Size
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P1[8];                  /* Expression: channel
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P2_Size[2];             /* Computed Parameter: P2Size
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P2;                     /* Expression: port
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P3_Size[2];             /* Computed Parameter: P3Size
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P3[8];                  /* Expression: reset
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P4_Size[2];             /* Computed Parameter: P4Size
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P4[8];                  /* Expression: initValue
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P5_Size[2];             /* Computed Parameter: P5Size
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P5;                     /* Expression: chip
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P6_Size[2];             /* Computed Parameter: P6Size
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P6;                     /* Expression: sampletime
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P7_Size[2];             /* Computed Parameter: P7Size
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P7;                     /* Expression: slot
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P8_Size[2];             /* Computed Parameter: P8Size
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P8;                     /* Expression: control
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P9_Size[2];             /* Computed Parameter: P9Size
                                        * '<S69>/Port A'
                                        */
  real_T PortA_P9;                     /* Expression: boardType
                                        * '<S69>/Port A'
                                        */
  real_T Constant_Value_l1;            /* Expression: 32768
                                        * '<S69>/Constant'
                                        */
  real_T PortB_P1_Size[2];             /* Computed Parameter: P1Size
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P1[8];                  /* Expression: channel
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P2_Size[2];             /* Computed Parameter: P2Size
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P2;                     /* Expression: port
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P3_Size[2];             /* Computed Parameter: P3Size
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P3[8];                  /* Expression: reset
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P4_Size[2];             /* Computed Parameter: P4Size
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P4[8];                  /* Expression: initValue
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P5_Size[2];             /* Computed Parameter: P5Size
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P5;                     /* Expression: chip
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P6_Size[2];             /* Computed Parameter: P6Size
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P6;                     /* Expression: sampletime
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P7_Size[2];             /* Computed Parameter: P7Size
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P7;                     /* Expression: slot
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P8_Size[2];             /* Computed Parameter: P8Size
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P8;                     /* Expression: control
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P9_Size[2];             /* Computed Parameter: P9Size
                                        * '<S69>/Port B'
                                        */
  real_T PortB_P9;                     /* Expression: boardType
                                        * '<S69>/Port B'
                                        */
  real_T xPCTargetTime_P1_Size_a[2];   /* Computed Parameter: P1Size
                                        * '<S69>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1_f;           /* Expression: func
                                        * '<S69>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size_k[2];   /* Computed Parameter: P2Size
                                        * '<S69>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_m;           /* Expression: ts
                                        * '<S69>/xPC Target  Time '
                                        */
  uint32_T PacketSpec_Value;           /* Computed Parameter: Value
                                        * '<S7>/Packet Spec'
                                        */
  uint32_T NaNupperbytes_Value;        /* Computed Parameter: Value
                                        * '<S7>/NaN upper bytes'
                                        */
  uint8_T DelayInput1_X0;              /* Computed Parameter: X0
                                        * '<S60>/Delay Input1'
                                        */
  uint8_T DelayInput1_X0_h;            /* Computed Parameter: X0
                                        * '<S45>/Delay Input1'
                                        */
  uint8_T DelayInput1_X0_m;            /* Computed Parameter: X0
                                        * '<S38>/Delay Input1'
                                        */
  uint8_T DelayInput1_X0_i;            /* Computed Parameter: X0
                                        * '<S37>/Delay Input1'
                                        */
  boolean_T Memory_X0;                 /* Computed Parameter: X0
                                        * '<S30>/Memory'
                                        */
  boolean_T Memory_X0_m;               /* Computed Parameter: X0
                                        * '<S4>/Memory'
                                        */
  boolean_T Memory_X0_n;               /* Computed Parameter: X0
                                        * '<S42>/Memory'
                                        */
  boolean_T Memory_X0_k;               /* Computed Parameter: X0
                                        * '<S46>/Memory'
                                        */
  boolean_T Memory_X0_p;               /* Computed Parameter: X0
                                        * '<S44>/Memory'
                                        */
  boolean_T Memory_X0_j;               /* Computed Parameter: X0
                                        * '<S43>/Memory'
                                        */
  boolean_T Memory_X0_e;               /* Computed Parameter: X0
                                        * '<S41>/Memory'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: TruthTable
                                        * '<S41>/Logic'
                                        */
  rtP_SampleandHold_bump_follow SampleandHold;/* '<S6>/Sample and Hold' */
  rtP_SampleandHold_bump_follow SampleandHold_k;/* '<S6>/Sample and Hold' */
};

/* Real-time Model Data Structure */
struct rtModel_bump_follow {
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
    SimStruct childSFunctions[14];
    SimStruct *childSFunctionPtrs[14];
    struct _ssBlkInfo2 blkInfo2[14];
    struct _ssSFcnModelMethods2 methods2[14];
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
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
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
      uint_T attribs[9];
      mxArray *params[9];
      struct _ssDWorkRecord dWork[1];
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
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[11];
      mxArray *params[11];
      struct _ssDWorkRecord dWork[1];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[11];
      mxArray *params[11];
      struct _ssDWorkRecord dWork[1];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[2];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[5];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[2];
      real_T const *UPtrs3[2];
      real_T const *UPtrs4[32];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[18];
      mxArray *params[18];
      struct _ssDWorkRecord dWork[4];
    } Sfcn11;

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
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
    } Sfcn13;
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
extern Parameters_bump_follow bump_follow_P;

/* Block signals (auto storage) */
extern BlockIO_bump_follow bump_follow_B;

/* Block states (auto storage) */
extern D_Work_bump_follow bump_follow_DWork;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_bump_follow bump_follow_PrevZCSigState;

/* Model entry point functions */
extern void bump_follow_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void bump_follow_initialize(boolean_T firstTime);
extern void bump_follow_output(int_T tid);
extern void bump_follow_update(int_T tid);
extern void bump_follow_terminate(void);

/* Real-time Model object */
extern rtModel_bump_follow *bump_follow_rtM;

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
 * '<Root>' : bump_follow
 * '<S1>'   : bump_follow/BoundingBox
 * '<S2>'   : bump_follow/Catch Force Generator
 * '<S3>'   : bump_follow/Force Generator
 * '<S4>'   : bump_follow/Motor Control
 * '<S5>'   : bump_follow/Recentering Subsystem
 * '<S6>'   : bump_follow/RewardSbs
 * '<S7>'   : bump_follow/SendPacketToGraphics1
 * '<S8>'   : bump_follow/Status
 * '<S9>'   : bump_follow/Velocity Calculation
 * '<S10>'  : bump_follow/Version Display
 * '<S11>'  : bump_follow/WordSbs
 * '<S12>'  : bump_follow/XY Position Subsystem
 * '<S13>'  : bump_follow/Xpos
 * '<S14>'  : bump_follow/Catch Force Generator/LorentzForce
 * '<S15>'  : bump_follow/Catch Force Generator/ViscLoadSubsystem
 * '<S16>'  : bump_follow/Catch Force Generator/LorentzForce/Lorentz
 * '<S17>'  : bump_follow/Catch Force Generator/LorentzForce/Lorentz1
 * '<S18>'  : bump_follow/Catch Force Generator/LorentzForce/Lorentz2
 * '<S19>'  : bump_follow/Catch Force Generator/LorentzForce/Lorentz3
 * '<S20>'  : bump_follow/Force Generator/LorentzForce
 * '<S21>'  : bump_follow/Force Generator/ViscLoadSubsystem
 * '<S22>'  : bump_follow/Force Generator/LorentzForce/Lorentz
 * '<S23>'  : bump_follow/Force Generator/LorentzForce/Lorentz1
 * '<S24>'  : bump_follow/Force Generator/LorentzForce/Lorentz2
 * '<S25>'  : bump_follow/Force Generator/LorentzForce/Lorentz3
 * '<S26>'  : bump_follow/Motor Control/Compare To Constant
 * '<S27>'  : bump_follow/Motor Control/Compare To Constant1
 * '<S28>'  : bump_follow/Motor Control/Force//Torque Transform
 * '<S29>'  : bump_follow/Motor Control/Recenter//ServoKill
 * '<S30>'  : bump_follow/Motor Control/Schmidt
 * '<S31>'  : bump_follow/Motor Control/Xpos
 * '<S32>'  : bump_follow/Motor Control/Force//Torque Transform/Transpose
 * '<S33>'  : bump_follow/Motor Control/Schmidt/Compare To Zero
 * '<S34>'  : bump_follow/Motor Control/Schmidt/Enabled Subsystem
 * '<S35>'  : bump_follow/Recentering Subsystem/Compare To Zero
 * '<S36>'  : bump_follow/Recentering Subsystem/Compare To Zero1
 * '<S37>'  : bump_follow/Recentering Subsystem/Falling Edge
 * '<S38>'  : bump_follow/Recentering Subsystem/Falling Edge1
 * '<S39>'  : bump_follow/Recentering Subsystem/No Movement
 * '<S40>'  : bump_follow/Recentering Subsystem/PD Controller
 * '<S41>'  : bump_follow/Recentering Subsystem/S-R Flip-Flop
 * '<S42>'  : bump_follow/Recentering Subsystem/Schmidt1
 * '<S43>'  : bump_follow/Recentering Subsystem/Schmidt2
 * '<S44>'  : bump_follow/Recentering Subsystem/Schmidt3
 * '<S45>'  : bump_follow/Recentering Subsystem/Start Moving
 * '<S46>'  : bump_follow/Recentering Subsystem/Timer
 * '<S47>'  : bump_follow/Recentering Subsystem/Xpos1
 * '<S48>'  : bump_follow/Recentering Subsystem/Falling Edge/Nonpositive
 * '<S49>'  : bump_follow/Recentering Subsystem/Falling Edge1/Nonpositive
 * '<S50>'  : bump_follow/Recentering Subsystem/No Movement/Compare To Constant2
 * '<S51>'  : bump_follow/Recentering Subsystem/No Movement/Compare To Constant3
 * '<S52>'  : bump_follow/Recentering Subsystem/Schmidt1/Compare To Zero
 * '<S53>'  : bump_follow/Recentering Subsystem/Schmidt1/Enabled Subsystem
 * '<S54>'  : bump_follow/Recentering Subsystem/Schmidt2/Compare To Zero
 * '<S55>'  : bump_follow/Recentering Subsystem/Schmidt2/Enabled Subsystem
 * '<S56>'  : bump_follow/Recentering Subsystem/Schmidt3/Compare To Zero
 * '<S57>'  : bump_follow/Recentering Subsystem/Schmidt3/Enabled Subsystem
 * '<S58>'  : bump_follow/Recentering Subsystem/Start Moving/Nonpositive
 * '<S59>'  : bump_follow/Recentering Subsystem/Timer/Compare To Zero
 * '<S60>'  : bump_follow/Recentering Subsystem/Timer/Detect Fall Nonpositive
 * '<S61>'  : bump_follow/Recentering Subsystem/Timer/Enabled Subsystem
 * '<S62>'  : bump_follow/Recentering Subsystem/Timer/Detect Fall Nonpositive/Nonpositive
 * '<S63>'  : bump_follow/RewardSbs/Sample and Hold
 * '<S64>'  : bump_follow/RewardSbs/Schmidt
 * '<S65>'  : bump_follow/RewardSbs/Schmidt/Sample and Hold
 * '<S66>'  : bump_follow/Velocity Calculation/Pos2VelX
 * '<S67>'  : bump_follow/Velocity Calculation/Pos2VelY
 * '<S68>'  : bump_follow/XY Position Subsystem/Cursor Rotation
 * '<S69>'  : bump_follow/XY Position Subsystem/For Iterator Subsystem
 * '<S70>'  : bump_follow/XY Position Subsystem/Jacobian-Cartesian Transformation
 * '<S71>'  : bump_follow/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem
 * '<S72>'  : bump_follow/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant
 * '<S73>'  : bump_follow/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1
 */
#endif                                 /* _RTW_HEADER_bump_follow_h_ */
