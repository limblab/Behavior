/*
 * forced_choice.h
 *
 * Real-Time Workshop code generation for Simulink model "forced_choice.mdl".
 *
 * Model Version              : 1.747
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Mon Dec 17 17:05:06 2007
 */
#ifndef _RTW_HEADER_forced_choice_h_
#define _RTW_HEADER_forced_choice_h_
#include "rtw_modelmap.h"
#ifndef _forced_choice_COMMON_INCLUDES_
# define _forced_choice_COMMON_INCLUDES_
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
#endif                                 /* _forced_choice_COMMON_INCLUDES_ */

#include "forced_choice_types.h"

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
#define forced_choice_M                forced_choice_rtM

/* Definition for use in the target main file */
#define forced_choice_rtModel          rtModel_forced_choice

/* Block signals for system '<S28>/Enabled Subsystem' */
typedef struct {
  real_T In1;                          /* '<S30>/In1' */
} rtB_EnabledSubsystem_forced_cho;

/* Block states (auto storage) for system '<S28>/Enabled Subsystem' */
typedef struct {
  int_T EnabledSubsystem_MODE;         /* '<S28>/Enabled Subsystem' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S28>/Enabled Subsystem' */
} rtDW_EnabledSubsystem_forced_ch;

/* Block signals (auto storage) */
typedef struct {
  real_T Clock;                        /* '<S9>/Clock' */
  real_T Sum;                          /* '<S9>/Sum' */
  real_T PCIQUAD04;                    /* '<S14>/PCI-QUAD04 ' */
  real_T Gain;                         /* '<S14>/Gain' */
  real_T Sum3;                         /* '<S14>/Sum3' */
  real_T sinlengthofShoulder;          /* '<S35>/sin(length of Shoulder)' */
  real_T PCIQUAD041;                   /* '<S14>/PCI-QUAD04 1' */
  real_T Gain1;                        /* '<S14>/Gain1' */
  real_T Sum1;                         /* '<S14>/Sum1' */
  real_T sinlengthofElbow;             /* '<S35>/sin(length of Elbow)' */
  real_T Sum2;                         /* '<S35>/Sum2' */
  real_T Sum4;                         /* '<S35>/Sum4' */
  real_T coslengthofShoulder;          /* '<S35>/cos(length of Shoulder)' */
  real_T coslengthofElbow;             /* '<S35>/cos(length of Elbow)' */
  real_T Sum3_n;                       /* '<S35>/Sum3' */
  real_T Sum1_a;                       /* '<S35>/Sum1' */
  real_T TrigonometricFunction1;       /* '<S33>/Trigonometric Function1' */
  real_T Sum_f;                        /* '<S33>/Sum' */
  real_T TrigonometricFunction2;       /* '<S33>/Trigonometric Function2' */
  real_T sqrtu1u1u2u2;                 /* '<S33>/sqrt(u[1]*u[1] + u[2]*u[2])' */
  real_T Product1;                     /* '<S33>/Product1' */
  real_T DigitalFilter2;               /* '<S6>/Digital Filter2' */
  real_T Derivative;                   /* '<S6>/Derivative' */
  real_T dG;                           /* '<S6>/dG' */
  real_T DigitalFilter;                /* '<S6>/Digital Filter' */
  real_T TrigonometricFunction;        /* '<S33>/Trigonometric Function' */
  real_T Product;                      /* '<S33>/Product' */
  real_T DigitalFilter2_d;             /* '<S7>/Digital Filter2' */
  real_T Derivative_l;                 /* '<S7>/Derivative' */
  real_T dG_k;                         /* '<S7>/dG' */
  real_T DigitalFilter_g;              /* '<S7>/Digital Filter' */
  real_T x;                            /* '<S24>/x' */
  real_T x_h;                          /* '<S25>/x' */
  real_T Add;                          /* '<S20>/Add' */
  real_T x_m;                          /* '<S26>/x' */
  real_T x_ho;                         /* '<S27>/x' */
  real_T Add1;                         /* '<S20>/Add1' */
  real_T MultiportSwitch[2];           /* '<S4>/Multiport Switch' */
  real_T BehaviorFC_o1[2];             /* '<Root>/Behavior FC' */
  real_T BehaviorFC_o2[4];             /* '<Root>/Behavior FC' */
  real_T BehaviorFC_o3;                /* '<Root>/Behavior FC' */
  real_T BehaviorFC_o4[10];            /* '<Root>/Behavior FC' */
  real_T BehaviorFC_o5;                /* '<Root>/Behavior FC' */
  real_T BehaviorFC_o6[2];             /* '<Root>/Behavior FC' */
  real_T Switch1[2];                   /* '<Root>/Switch1' */
  real_T MG2;                          /* '<Root>/MG2' */
  real_T RateTransition2;              /* '<Root>/Rate Transition2' */
  real_T MG1;                          /* '<Root>/MG1' */
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  real_T ToBits_o1;                    /* '<S13>/ToBits' */
  real_T ToBits_o2;                    /* '<S13>/ToBits' */
  real_T ToBits_o3;                    /* '<S13>/ToBits' */
  real_T ToBits_o4;                    /* '<S13>/ToBits' */
  real_T ToBits_o5;                    /* '<S13>/ToBits' */
  real_T ToBits_o6;                    /* '<S13>/ToBits' */
  real_T ToBits_o7;                    /* '<S13>/ToBits' */
  real_T ToBits_o8;                    /* '<S13>/ToBits' */
  real_T y;                            /* '<S24>/y' */
  real_T Add1_o;                       /* '<S24>/Add1' */
  real_T z;                            /* '<S24>/z' */
  real_T Add3;                         /* '<S24>/Add3' */
  real_T product2;                     /* '<S24>/product2' */
  real_T Add2;                         /* '<S24>/Add2' */
  real_T product3;                     /* '<S24>/product3' */
  real_T product4;                     /* '<S24>/product4' */
  real_T Add4;                         /* '<S24>/Add4' */
  real_T product1;                     /* '<S24>/product1' */
  real_T dX;                           /* '<S24>/dX' */
  real_T AddX;                         /* '<S24>/AddX' */
  real_T dY;                           /* '<S24>/dY' */
  real_T AddX1;                        /* '<S24>/AddX1' */
  real_T dZ;                           /* '<S24>/dZ' */
  real_T AddX2;                        /* '<S24>/AddX2' */
  real_T y_p;                          /* '<S25>/y' */
  real_T Add1_e;                       /* '<S25>/Add1' */
  real_T z_m;                          /* '<S25>/z' */
  real_T Add3_n;                       /* '<S25>/Add3' */
  real_T product2_n;                   /* '<S25>/product2' */
  real_T Add2_d;                       /* '<S25>/Add2' */
  real_T product3_b;                   /* '<S25>/product3' */
  real_T product4_n;                   /* '<S25>/product4' */
  real_T Add4_c;                       /* '<S25>/Add4' */
  real_T product1_k;                   /* '<S25>/product1' */
  real_T dX_i;                         /* '<S25>/dX' */
  real_T AddX_m;                       /* '<S25>/AddX' */
  real_T dY_g;                         /* '<S25>/dY' */
  real_T AddX1_j;                      /* '<S25>/AddX1' */
  real_T dZ_k;                         /* '<S25>/dZ' */
  real_T AddX2_j;                      /* '<S25>/AddX2' */
  real_T y_e;                          /* '<S26>/y' */
  real_T Add1_l;                       /* '<S26>/Add1' */
  real_T z_mc;                         /* '<S26>/z' */
  real_T Add3_k;                       /* '<S26>/Add3' */
  real_T product2_a;                   /* '<S26>/product2' */
  real_T Add2_k;                       /* '<S26>/Add2' */
  real_T product3_c;                   /* '<S26>/product3' */
  real_T product4_c;                   /* '<S26>/product4' */
  real_T Add4_i;                       /* '<S26>/Add4' */
  real_T product1_b;                   /* '<S26>/product1' */
  real_T dX_l;                         /* '<S26>/dX' */
  real_T AddX_k;                       /* '<S26>/AddX' */
  real_T dY_o;                         /* '<S26>/dY' */
  real_T AddX1_k;                      /* '<S26>/AddX1' */
  real_T dZ_f;                         /* '<S26>/dZ' */
  real_T AddX2_b;                      /* '<S26>/AddX2' */
  real_T y_k;                          /* '<S27>/y' */
  real_T Add1_i;                       /* '<S27>/Add1' */
  real_T z_n;                          /* '<S27>/z' */
  real_T Add3_d;                       /* '<S27>/Add3' */
  real_T product2_j;                   /* '<S27>/product2' */
  real_T Add2_c;                       /* '<S27>/Add2' */
  real_T product3_a;                   /* '<S27>/product3' */
  real_T product4_p;                   /* '<S27>/product4' */
  real_T Add4_h;                       /* '<S27>/Add4' */
  real_T product1_kd;                  /* '<S27>/product1' */
  real_T dX_a;                         /* '<S27>/dX' */
  real_T AddX_mq;                      /* '<S27>/AddX' */
  real_T dY_p;                         /* '<S27>/dY' */
  real_T AddX1_e;                      /* '<S27>/AddX1' */
  real_T dZ_p;                         /* '<S27>/dZ' */
  real_T AddX2_f;                      /* '<S27>/AddX2' */
  real_T DataTypeConversion;           /* '<S8>/Data Type Conversion' */
  real_T Clock_k;                      /* '<S28>/Clock' */
  real_T Sum_l;                        /* '<S28>/Sum' */
  real_T Add_n;                        /* '<S11>/Add' */
  real_T Add1_m;                       /* '<S11>/Add1' */
  real_T Gain_n;                       /* '<S11>/Gain' */
  real_T Gain1_d;                      /* '<S11>/Gain1' */
  real_T ForIterator;                  /* '<S34>/For Iterator' */
  real_T Add_i;                        /* '<S34>/Add' */
  real_T Add1_k;                       /* '<S34>/Add1' */
  real_T SerialConverter;              /* '<S34>/SerialConverter' */
  real_T ToBits_o1_n;                  /* '<S34>/ToBits' */
  real_T ToBits_o2_l;                  /* '<S34>/ToBits' */
  real_T ToBits_o3_f;                  /* '<S34>/ToBits' */
  real_T ToBits_o4_k;                  /* '<S34>/ToBits' */
  real_T ToBits_o5_a;                  /* '<S34>/ToBits' */
  real_T ToBits_o6_o;                  /* '<S34>/ToBits' */
  real_T ToBits_o7_h;                  /* '<S34>/ToBits' */
  real_T ToBits_o8_e;                  /* '<S34>/ToBits' */
  real_T xPCTargetTime;                /* '<S34>/xPC Target  Time ' */
  real_T xPCTargetTime_n;              /* '<S36>/xPC Target  Time ' */
  real_T Subtract;                     /* '<S36>/Subtract' */
  real_T ScaleTouSec;                  /* '<S36>/ScaleTouSec' */
  real_T Switch;                       /* '<S36>/Switch' */
  real_T sinlengthofShoulder_e;        /* '<S5>/sin(length of Shoulder)' */
  real_T Product_k;                    /* '<S5>/Product' */
  real_T coslengthofShoulder_m;        /* '<S5>/cos(length of Shoulder)' */
  real_T Product1_a;                   /* '<S5>/Product1' */
  real_T sinlengthofElbow_j;           /* '<S5>/sin(length of Elbow)' */
  real_T Product2;                     /* '<S5>/Product2' */
  real_T coslengthofElbow_j;           /* '<S5>/cos(length of Elbow)' */
  real_T Product3;                     /* '<S5>/Product3' */
  real_T Sum5;                         /* '<S5>/Sum5' */
  real_T Sum6;                         /* '<S5>/Sum6' */
  real_T LorentzForceGain[2];          /* '<S4>/LorentzForceGain' */
  real_T dynamicAngleSwitch;           /* '<S4>/dynamicAngle Switch' */
  real_T sin_c;                        /* '<S21>/sin' */
  real_T Product3_g;                   /* '<S21>/Product3' */
  real_T cos_n;                        /* '<S21>/cos' */
  real_T Product2_p;                   /* '<S21>/Product2' */
  real_T Subtract_b;                   /* '<S21>/Subtract' */
  real_T Product1_h;                   /* '<S21>/Product1' */
  real_T Product_h;                    /* '<S21>/Product' */
  real_T Add_f;                        /* '<S21>/Add' */
  real_T Gain_l[2];                    /* '<S21>/Gain' */
  real_T Gain_e;                       /* '<S4>/Gain' */
  real_T Switch_d[2];                  /* '<Root>/Switch' */
  uint8_T Compare;                     /* '<S31>/Compare' */
  uint8_T Pack[112];                   /* '<S12>/Pack' */
  uint8_T RateTransition[112];         /* '<S12>/Rate Transition' */
  uint8_T Compare_b;                   /* '<S29>/Compare' */
  uint8_T Compare_b2;                  /* '<S2>/Compare' */
  uint8_T Compare_j;                   /* '<S3>/Compare' */
  boolean_T Memory;                    /* '<S9>/Memory' */
  boolean_T Memory_o;                  /* '<Root>/Memory' */
  boolean_T LogicalOperator2;          /* '<S9>/Logical Operator2' */
  boolean_T LogicalOperator1;          /* '<S9>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_EnabledSu;/* '<S9>/Logical Operator1' */
  boolean_T RelationalOperator;        /* '<S9>/Relational Operator' */
  boolean_T LogicalOperator;           /* '<S9>/Logical Operator' */
  boolean_T RelationalOperator_o;      /* '<S1>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S1>/Relational Operator1' */
  boolean_T RelationalOperator2;       /* '<S1>/Relational Operator2' */
  boolean_T RelationalOperator3;       /* '<S1>/Relational Operator3' */
  boolean_T LogicalOperator_h;         /* '<S1>/Logical Operator' */
  boolean_T Memory1;                   /* '<S8>/Memory1' */
  boolean_T Memory_f;                  /* '<S28>/Memory' */
  boolean_T LogicalOperator2_h;        /* '<S28>/Logical Operator2' */
  boolean_T LogicalOperator1_m;        /* '<S28>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_g;/* '<S28>/Logical Operator1' */
  boolean_T RelationalOperator_m;      /* '<S28>/Relational Operator' */
  boolean_T LogicalOperator_a;         /* '<S28>/Logical Operator' */
  boolean_T LogicalOperator1_l;        /* '<Root>/Logical Operator1' */
  boolean_T MatrixConcatenation[2];    /* '<Root>/Matrix Concatenation' */
  boolean_T Compare_p;                 /* '<S38>/Compare' */
  boolean_T Compare_a;                 /* '<S37>/Compare' */
  rtB_EnabledSubsystem_forced_cho EnabledSubsystem;/* '<S9>/Enabled Subsystem' */
  rtB_EnabledSubsystem_forced_cho EnabledSubsystem_h;/* '<S28>/Enabled Subsystem' */
} BlockIO_forced_choice;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DigitalFilter2_FILT_STATES[11];/* '<S6>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES[11];/* '<S6>/Digital Filter' */
  real_T DigitalFilter2_FILT_STATES_c[11];/* '<S7>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES_p[11];/* '<S7>/Digital Filter' */
  real_T x_DSTATE;                     /* '<S24>/x' */
  real_T x_DSTATE_h;                   /* '<S25>/x' */
  real_T x_DSTATE_g;                   /* '<S26>/x' */
  real_T x_DSTATE_e;                   /* '<S27>/x' */
  real_T BehaviorFC_DSTATE;            /* '<Root>/Behavior FC' */
  real_T y_DSTATE;                     /* '<S24>/y' */
  real_T z_DSTATE;                     /* '<S24>/z' */
  real_T y_DSTATE_a;                   /* '<S25>/y' */
  real_T z_DSTATE_g;                   /* '<S25>/z' */
  real_T y_DSTATE_p;                   /* '<S26>/y' */
  real_T z_DSTATE_a;                   /* '<S26>/z' */
  real_T y_DSTATE_g;                   /* '<S27>/y' */
  real_T z_DSTATE_p;                   /* '<S27>/z' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S6>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_p;                /* '<S7>/Derivative' */

  real_T BehaviorFC_RWORK[3];          /* '<Root>/Behavior FC' */
  real_T PCI6025E_RWORK[6];            /* '<Root>/PCI-6025E ' */
  void *Send_PWORK;                    /* '<S12>/Send' */
  int32_T DigitalFilter2_CIRCBUFFIDX;  /* '<S6>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX;   /* '<S6>/Digital Filter' */
  int32_T DigitalFilter2_CIRCBUFFIDX_p;/* '<S7>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX_b; /* '<S7>/Digital Filter' */
  int_T PCIQUAD04_IWORK;               /* '<S14>/PCI-QUAD04 ' */
  int_T PCIQUAD041_IWORK;              /* '<S14>/PCI-QUAD04 1' */
  int_T BehaviorFC_IWORK[63];          /* '<Root>/Behavior FC' */
  int_T PCI6025E_IWORK[2];             /* '<Root>/PCI-6025E ' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S10>/S-Function' */

  int_T Send_IWORK[2];                 /* '<S12>/Send' */
  int_T PortA_IWORK[2];                /* '<S13>/Port A' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK_i;                 /* '<S15>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_a;                 /* '<S16>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_d;                 /* '<S17>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_h;                 /* '<S18>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_ie;                /* '<S19>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_b;                 /* '<S22>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_g;                 /* '<S23>/S-Function' */

  int_T PortB_IWORK[2];                /* '<S34>/Port B' */
  int_T PCI6025E_IWORK_k[3];           /* '<S36>/PCI-6025E ' */
  boolean_T Memory_PreviousInput;      /* '<S9>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<Root>/Memory' */
  boolean_T Memory1_PreviousInput;     /* '<S8>/Memory1' */
  boolean_T Memory_PreviousInput_m;    /* '<S28>/Memory' */
  rtDW_EnabledSubsystem_forced_ch EnabledSubsystem;/* '<S9>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_forced_ch EnabledSubsystem_h;/* '<S28>/Enabled Subsystem' */
} D_Work_forced_choice;

/* Backward compatible GRT Identifiers */
#define rtB                            forced_choice_B
#define BlockIO                        BlockIO_forced_choice
#define rtXdot                         forced_choice_Xdot
#define StateDerivatives               StateDerivatives_forced_choice
#define tXdis                          forced_choice_Xdis
#define StateDisabled                  StateDisabled_forced_choice
#define rtP                            forced_choice_P
#define Parameters                     Parameters_forced_choice
#define rtDWork                        forced_choice_DWork
#define D_Work                         D_Work_forced_choice

/* Parameters (auto storage) */
struct Parameters_forced_choice {
  real_T Time_Value;                   /* Expression: Time
                                        * '<S9>/Time'
                                        */
  real_T PCIQUAD04_P1_Size[2];         /* Computed Parameter: P1Size
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P1;                 /* Expression: convbaseaddr
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P2_Size[2];         /* Computed Parameter: P2Size
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P2;                 /* Expression: channel
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P3_Size[2];         /* Computed Parameter: P3Size
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P3;                 /* Expression: resetmode
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P4_Size[2];         /* Computed Parameter: P4Size
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P4;                 /* Expression: polarity
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P5_Size[2];         /* Computed Parameter: P5Size
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P5;                 /* Expression: mode
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P6_Size[2];         /* Computed Parameter: P6Size
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P6;                 /* Expression: limit
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P7_Size[2];         /* Computed Parameter: P7Size
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P7;                 /* Expression: range
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P8_Size[2];         /* Computed Parameter: P8Size
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P8;                 /* Expression: speed
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P9_Size[2];         /* Computed Parameter: P9Size
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P9;                 /* Expression: prescale
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P10_Size[2];        /* Computed Parameter: P10Size
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P10;                /* Expression: ts
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P11_Size[2];        /* Computed Parameter: P11Size
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P11;                /* Expression: boardtype
                                        * '<S14>/PCI-QUAD04 '
                                        */
  real_T Gain_Gain;                    /* Expression: 3.490658e-4
                                        * '<S14>/Gain'
                                        */
  real_T shoulderOffset_Value;         /* Expression: 0
                                        * '<S14>/shoulderOffset'
                                        */
  real_T PCIQUAD041_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P1;                /* Expression: convbaseaddr
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P2;                /* Expression: channel
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P3;                /* Expression: resetmode
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P4;                /* Expression: polarity
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P5;                /* Expression: mode
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P6;                /* Expression: limit
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P7_Size[2];        /* Computed Parameter: P7Size
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P7;                /* Expression: range
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P8_Size[2];        /* Computed Parameter: P8Size
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P8;                /* Expression: speed
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P9_Size[2];        /* Computed Parameter: P9Size
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P9;                /* Expression: prescale
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P10_Size[2];       /* Computed Parameter: P10Size
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P10;               /* Expression: ts
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P11_Size[2];       /* Computed Parameter: P11Size
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P11;               /* Expression: boardtype
                                        * '<S14>/PCI-QUAD04 1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -3.490658e-4
                                        * '<S14>/Gain1'
                                        */
  real_T elbowOffset_Value;            /* Expression: 0
                                        * '<S14>/elbowOffset'
                                        */
  real_T yoffset_Value;                /* Expression: 37
                                        * '<S35>/yoffset'
                                        */
  real_T xoffset_Value;                /* Expression: -2
                                        * '<S35>/xoffset'
                                        */
  real_T AngleOffset_Value;            /* Expression: 0
                                        * '<S33>/AngleOffset'
                                        */
  real_T DigitalFilter2_ICRTP;         /* Expression: a.IC
                                        * '<S6>/Digital Filter2'
                                        */
  real_T DigitalFilter2_RTP1COEFF[11]; /* Expression: NumCoeffs
                                        * '<S6>/Digital Filter2'
                                        */
  real_T dG_Gain;                      /* Expression: -.0001
                                        * '<S6>/dG'
                                        */
  real_T DigitalFilter_ICRTP;          /* Expression: a.IC
                                        * '<S6>/Digital Filter'
                                        */
  real_T DigitalFilter_RTP1COEFF[11];  /* Expression: NumCoeffs
                                        * '<S6>/Digital Filter'
                                        */
  real_T DigitalFilter2_ICRTP_c;       /* Expression: a.IC
                                        * '<S7>/Digital Filter2'
                                        */
  real_T DigitalFilter2_RTP1COEFF_a[11];/* Expression: NumCoeffs
                                         * '<S7>/Digital Filter2'
                                         */
  real_T dG_Gain_b;                    /* Expression: -.0001
                                        * '<S7>/dG'
                                        */
  real_T DigitalFilter_ICRTP_c;        /* Expression: a.IC
                                        * '<S7>/Digital Filter'
                                        */
  real_T DigitalFilter_RTP1COEFF_n[11];/* Expression: NumCoeffs
                                        * '<S7>/Digital Filter'
                                        */
  real_T XLowLimit_Value;              /* Expression: -20
                                        * '<S1>/XLowLimit'
                                        */
  real_T XHighLimit_Value;             /* Expression: 25
                                        * '<S1>/XHighLimit'
                                        */
  real_T YHighLimit_Value;             /* Expression: -46
                                        * '<S1>/YHighLimit'
                                        */
  real_T YLowLimit_Value;              /* Expression: -18
                                        * '<S1>/YLowLimit'
                                        */
  real_T Load_Value;                   /* Expression: 0
                                        * '<S4>/Load'
                                        */
  real_T x_X0;                         /* Expression: .1
                                        * '<S24>/x'
                                        */
  real_T x_X0_f;                       /* Expression: .1
                                        * '<S25>/x'
                                        */
  real_T x_X0_l;                       /* Expression: .1
                                        * '<S26>/x'
                                        */
  real_T x_X0_c;                       /* Expression: .1
                                        * '<S27>/x'
                                        */
  real_T BehaviorFC_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P1;                /* Expression: 3
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P2;                /* Expression: 0
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P3;                /* Expression: 1
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P4;                /* Expression: .5
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P5;                /* Expression: 1
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P6;                /* Expression: .5
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P7_Size[2];        /* Computed Parameter: P7Size
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P7;                /* Expression: 1
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P8_Size[2];        /* Computed Parameter: P8Size
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P8;                /* Expression: 10
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P9_Size[2];        /* Computed Parameter: P9Size
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P9;                /* Expression: 3
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P10_Size[2];       /* Computed Parameter: P10Size
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P10;               /* Expression: 3
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P11_Size[2];       /* Computed Parameter: P11Size
                                        * '<Root>/Behavior FC'
                                        */
  real_T BehaviorFC_P11;               /* Expression: 10
                                        * '<Root>/Behavior FC'
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
                                        * '<S12>/Send'
                                        */
  real_T Send_P1[11];                  /* Computed Parameter: P1
                                        * '<S12>/Send'
                                        */
  real_T Send_P2_Size[2];              /* Computed Parameter: P2Size
                                        * '<S12>/Send'
                                        */
  real_T Send_P2;                      /* Expression: ipPort
                                        * '<S12>/Send'
                                        */
  real_T Send_P3_Size[2];              /* Computed Parameter: P3Size
                                        * '<S12>/Send'
                                        */
  real_T Send_P3;                      /* Expression: localPort
                                        * '<S12>/Send'
                                        */
  real_T Send_P4_Size[2];              /* Computed Parameter: P4Size
                                        * '<S12>/Send'
                                        */
  real_T Send_P4;                      /* Expression: sampletime
                                        * '<S12>/Send'
                                        */
  real_T PortA_P1_Size[2];             /* Computed Parameter: P1Size
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P1[8];                  /* Expression: channel
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P2_Size[2];             /* Computed Parameter: P2Size
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P2;                     /* Expression: port
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P3_Size[2];             /* Computed Parameter: P3Size
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P3[8];                  /* Expression: reset
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P4_Size[2];             /* Computed Parameter: P4Size
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P4[8];                  /* Expression: initValue
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P5_Size[2];             /* Computed Parameter: P5Size
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P5;                     /* Expression: chip
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P6_Size[2];             /* Computed Parameter: P6Size
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P6;                     /* Expression: sampletime
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P7_Size[2];             /* Computed Parameter: P7Size
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P7[2];                  /* Expression: slot
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P8_Size[2];             /* Computed Parameter: P8Size
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P8;                     /* Expression: control
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P9_Size[2];             /* Computed Parameter: P9Size
                                        * '<S13>/Port A'
                                        */
  real_T PortA_P9;                     /* Expression: boardType
                                        * '<S13>/Port A'
                                        */
  real_T y_X0;                         /* Expression: y0
                                        * '<S24>/y'
                                        */
  real_T rho_Value;                    /* Expression: 28
                                        * '<S24>/rho'
                                        */
  real_T z_X0;                         /* Expression: .1
                                        * '<S24>/z'
                                        */
  real_T beta_Value;                   /* Expression: 8/3
                                        * '<S24>/beta'
                                        */
  real_T timescale_Value;              /* Expression: .0001
                                        * '<S24>/timescale'
                                        */
  real_T sigma_Value;                  /* Expression: 10
                                        * '<S24>/sigma'
                                        */
  real_T y_X0_f;                       /* Expression: y0
                                        * '<S25>/y'
                                        */
  real_T rho_Value_d;                  /* Expression: 28
                                        * '<S25>/rho'
                                        */
  real_T z_X0_p;                       /* Expression: .1
                                        * '<S25>/z'
                                        */
  real_T beta_Value_b;                 /* Expression: 8/3
                                        * '<S25>/beta'
                                        */
  real_T timescale_Value_j;            /* Expression: .0001
                                        * '<S25>/timescale'
                                        */
  real_T sigma_Value_e;                /* Expression: 10
                                        * '<S25>/sigma'
                                        */
  real_T y_X0_k;                       /* Expression: y0
                                        * '<S26>/y'
                                        */
  real_T rho_Value_h;                  /* Expression: 28
                                        * '<S26>/rho'
                                        */
  real_T z_X0_n;                       /* Expression: .1
                                        * '<S26>/z'
                                        */
  real_T beta_Value_p;                 /* Expression: 8/3
                                        * '<S26>/beta'
                                        */
  real_T timescale_Value_d;            /* Expression: .0001
                                        * '<S26>/timescale'
                                        */
  real_T sigma_Value_o;                /* Expression: 10
                                        * '<S26>/sigma'
                                        */
  real_T y_X0_h;                       /* Expression: y0
                                        * '<S27>/y'
                                        */
  real_T rho_Value_n;                  /* Expression: 28
                                        * '<S27>/rho'
                                        */
  real_T z_X0_b;                       /* Expression: .1
                                        * '<S27>/z'
                                        */
  real_T beta_Value_e;                 /* Expression: 8/3
                                        * '<S27>/beta'
                                        */
  real_T timescale_Value_f;            /* Expression: .0001
                                        * '<S27>/timescale'
                                        */
  real_T sigma_Value_k;                /* Expression: 10
                                        * '<S27>/sigma'
                                        */
  real_T Time_Value_b;                 /* Expression: Time
                                        * '<S28>/Time'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * '<S2>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: const
                                        * '<S3>/Constant'
                                        */
  real_T Gain_Gain_i;                  /* Expression: .5
                                        * '<S11>/Gain'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: .5
                                        * '<S11>/Gain1'
                                        */
  real_T zeroX_Value;                  /* Expression: 0
                                        * '<Root>/zeroX'
                                        */
  real_T zeroY_Value;                  /* Expression: 0
                                        * '<Root>/zeroY'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 0.0367
                                        * '<S4>/Gain'
                                        */
  real_T visAngle_Value;               /* Expression: 0
                                        * '<S4>/visAngle'
                                        */
  real_T DynamicAngle_Value;           /* Expression: 0
                                        * '<S4>/DynamicAngle'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 1
                                        * '<S21>/Gain'
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
                                        * '<S36>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * '<S36>/Constant'
                                        */
  real_T xPCTargetTime_P1_Size[2];     /* Computed Parameter: P1Size
                                        * '<S36>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1;             /* Expression: func
                                        * '<S36>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size[2];     /* Computed Parameter: P2Size
                                        * '<S36>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2;             /* Expression: ts
                                        * '<S36>/xPC Target  Time '
                                        */
  real_T ScaleTouSec_Gain;             /* Expression: .838
                                        * '<S36>/ScaleTouSec'
                                        */
  real_T Constant_Value_m;             /* Expression: const
                                        * '<S38>/Constant'
                                        */
  real_T PCI6025E_P1_Size_i[2];        /* Computed Parameter: P1Size
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P1_f[2];             /* Expression: channel
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_Size_e[2];        /* Computed Parameter: P2Size
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_h[2];             /* Expression: reset
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_Size_l[2];        /* Computed Parameter: P3Size
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_e[2];             /* Expression: initValue
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_Size_p[2];        /* Computed Parameter: P4Size
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_g;                /* Expression: sampletime
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_Size_h[2];        /* Computed Parameter: P5Size
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_h[2];             /* Expression: slot
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_Size_h[2];        /* Computed Parameter: P6Size
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_f;                /* Expression: control
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_Size_n[2];        /* Computed Parameter: P7Size
                                        * '<S36>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_g;                /* Expression: boardType
                                        * '<S36>/PCI-6025E '
                                        */
  real_T Constant_Value_m2;            /* Expression: const
                                        * '<S37>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: 32768
                                        * '<S34>/Constant'
                                        */
  real_T PortB_P1_Size[2];             /* Computed Parameter: P1Size
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P1[8];                  /* Expression: channel
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P2_Size[2];             /* Computed Parameter: P2Size
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P2;                     /* Expression: port
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P3_Size[2];             /* Computed Parameter: P3Size
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P3[8];                  /* Expression: reset
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P4_Size[2];             /* Computed Parameter: P4Size
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P4[8];                  /* Expression: initValue
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P5_Size[2];             /* Computed Parameter: P5Size
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P5;                     /* Expression: chip
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P6_Size[2];             /* Computed Parameter: P6Size
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P6;                     /* Expression: sampletime
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P7_Size[2];             /* Computed Parameter: P7Size
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P7[2];                  /* Expression: slot
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P8_Size[2];             /* Computed Parameter: P8Size
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P8;                     /* Expression: control
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P9_Size[2];             /* Computed Parameter: P9Size
                                        * '<S34>/Port B'
                                        */
  real_T PortB_P9;                     /* Expression: boardType
                                        * '<S34>/Port B'
                                        */
  real_T xPCTargetTime_P1_Size_p[2];   /* Computed Parameter: P1Size
                                        * '<S34>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1_a;           /* Expression: func
                                        * '<S34>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size_d[2];   /* Computed Parameter: P2Size
                                        * '<S34>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_g;           /* Expression: ts
                                        * '<S34>/xPC Target  Time '
                                        */
  boolean_T Memory_X0;                 /* Computed Parameter: X0
                                        * '<S9>/Memory'
                                        */
  boolean_T Memory_X0_b;               /* Computed Parameter: X0
                                        * '<Root>/Memory'
                                        */
  boolean_T Memory1_X0;                /* Computed Parameter: X0
                                        * '<S8>/Memory1'
                                        */
  boolean_T Memory_X0_n;               /* Computed Parameter: X0
                                        * '<S28>/Memory'
                                        */
};

/* Real-time Model Data Structure */
struct rtModel_forced_choice {
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
      uint_T attribs[11];
      mxArray *params[11];
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
extern Parameters_forced_choice forced_choice_P;

/* Block signals (auto storage) */
extern BlockIO_forced_choice forced_choice_B;

/* Block states (auto storage) */
extern D_Work_forced_choice forced_choice_DWork;

/* Model entry point functions */
extern void forced_choice_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void forced_choice_initialize(boolean_T firstTime);
extern void forced_choice_output(int_T tid);
extern void forced_choice_update(int_T tid);
extern void forced_choice_terminate(void);

/* Real-time Model object */
extern rtModel_forced_choice *forced_choice_rtM;

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
 * '<Root>' : forced_choice
 * '<S1>'   : forced_choice/BoundingBox
 * '<S2>'   : forced_choice/Compare To Constant
 * '<S3>'   : forced_choice/Compare To Constant1
 * '<S4>'   : forced_choice/Force Generator
 * '<S5>'   : forced_choice/Force//Torque Transform
 * '<S6>'   : forced_choice/Pos2VelX
 * '<S7>'   : forced_choice/Pos2VelY
 * '<S8>'   : forced_choice/RewardSbs
 * '<S9>'   : forced_choice/Schmidt
 * '<S10>'  : forced_choice/Status
 * '<S11>'  : forced_choice/Target Peek
 * '<S12>'  : forced_choice/UDPXmit
 * '<S13>'  : forced_choice/WordSbs
 * '<S14>'  : forced_choice/XY Position Subsystem
 * '<S15>'  : forced_choice/Xpos
 * '<S16>'  : forced_choice/Xpos1
 * '<S17>'  : forced_choice/Ypos
 * '<S18>'  : forced_choice/forceScope
 * '<S19>'  : forced_choice/th1
 * '<S20>'  : forced_choice/Force Generator/LorentzForce
 * '<S21>'  : forced_choice/Force Generator/ViscLoadSubsystem
 * '<S22>'  : forced_choice/Force Generator/Ypos1
 * '<S23>'  : forced_choice/Force Generator/Ypos4
 * '<S24>'  : forced_choice/Force Generator/LorentzForce/Lorentz
 * '<S25>'  : forced_choice/Force Generator/LorentzForce/Lorentz1
 * '<S26>'  : forced_choice/Force Generator/LorentzForce/Lorentz2
 * '<S27>'  : forced_choice/Force Generator/LorentzForce/Lorentz3
 * '<S28>'  : forced_choice/RewardSbs/Schmidt1
 * '<S29>'  : forced_choice/RewardSbs/Schmidt1/Compare To Zero
 * '<S30>'  : forced_choice/RewardSbs/Schmidt1/Enabled Subsystem
 * '<S31>'  : forced_choice/Schmidt/Compare To Zero
 * '<S32>'  : forced_choice/Schmidt/Enabled Subsystem
 * '<S33>'  : forced_choice/XY Position Subsystem/Cursor Rotation
 * '<S34>'  : forced_choice/XY Position Subsystem/For Iterator Subsystem
 * '<S35>'  : forced_choice/XY Position Subsystem/Jacobian-Cartesian Transformation
 * '<S36>'  : forced_choice/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem
 * '<S37>'  : forced_choice/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant
 * '<S38>'  : forced_choice/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1
 */
#endif                                 /* _RTW_HEADER_forced_choice_h_ */
