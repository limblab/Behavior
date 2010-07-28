/*
 * bump_choice.h
 *
 * Real-Time Workshop code generation for Simulink model "bump_choice.mdl".
 *
 * Model Version              : 1.1230
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:43:36 2010
 */
#ifndef _RTW_HEADER_bump_choice_h_
#define _RTW_HEADER_bump_choice_h_
#include "rtw_modelmap.h"
#ifndef _bump_choice_COMMON_INCLUDES_
# define _bump_choice_COMMON_INCLUDES_
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
#endif                                 /* _bump_choice_COMMON_INCLUDES_ */

#include "bump_choice_types.h"

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
#define bump_choice_M                  bump_choice_rtM

/* Definition for use in the target main file */
#define bump_choice_rtModel            rtModel_bump_choice

/* Block signals for system '<S30>/Enabled Subsystem' */
typedef struct {
  real_T In1;                          /* '<S34>/In1' */
} rtB_EnabledSubsystem_bump_choic;

/* Block states (auto storage) for system '<S30>/Enabled Subsystem' */
typedef struct {
  int_T EnabledSubsystem_MODE;         /* '<S30>/Enabled Subsystem' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S30>/Enabled Subsystem' */
} rtDW_EnabledSubsystem_bump_choi;

/* Block signals for system '<S6>/Sample and Hold' */
typedef struct {
  real_T In;                           /* '<S63>/In' */
} rtB_SampleandHold_bump_choice;

/* Block states (auto storage) for system '<S6>/Sample and Hold' */
typedef struct {
  int8_T SampleandHold_SubsysRanBC;    /* '<S6>/Sample and Hold' */
} rtDW_SampleandHold_bump_choice;

/* Zero-crossing (trigger) state for system '<S6>/Sample and Hold' */
typedef struct {
  ZCSigState SampleandHold_ZCE;        /* '<S6>/Sample and Hold' */
} rtZCE_SampleandHold_bump_choice;

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
  real_T Sum3_o;                       /* '<S70>/Sum3' */
  real_T Sum1_k;                       /* '<S70>/Sum1' */
  real_T TrigonometricFunction1_o;     /* '<S68>/Trigonometric Function1' */
  real_T Sum_c;                        /* '<S68>/Sum' */
  real_T TrigonometricFunction2_l;     /* '<S68>/Trigonometric Function2' */
  real_T sqrtu1u1u2u2;                 /* '<S68>/sqrt(u[1]*u[1] + u[2]*u[2])' */
  real_T Product1_b;                   /* '<S68>/Product1' */
  real_T DigitalFilter2;               /* '<S66>/Digital Filter2' */
  real_T Derivative;                   /* '<S66>/Derivative' */
  real_T dG;                           /* '<S66>/dG' */
  real_T DigitalFilter;                /* '<S66>/Digital Filter' */
  real_T TrigonometricFunction_d;      /* '<S68>/Trigonometric Function' */
  real_T Product_f;                    /* '<S68>/Product' */
  real_T DigitalFilter2_c;             /* '<S67>/Digital Filter2' */
  real_T Derivative_i;                 /* '<S67>/Derivative' */
  real_T dG_c;                         /* '<S67>/dG' */
  real_T DigitalFilter_k;              /* '<S67>/Digital Filter' */
  real_T Switch[2];                    /* '<S9>/Switch' */
  real_T Clock_k;                      /* '<S42>/Clock' */
  real_T Clock_h;                      /* '<S46>/Clock' */
  real_T Sum_n;                        /* '<S46>/Sum' */
  real_T Sum_l;                        /* '<S42>/Sum' */
  real_T Abs2;                         /* '<S39>/Abs2' */
  real_T Abs3;                         /* '<S39>/Abs3' */
  real_T Clock_p;                      /* '<S44>/Clock' */
  real_T Sum_h;                        /* '<S44>/Sum' */
  real_T Clock_d;                      /* '<S43>/Clock' */
  real_T Sum_hb;                       /* '<S43>/Sum' */
  real_T x;                            /* '<S22>/x' */
  real_T x_e;                          /* '<S23>/x' */
  real_T Add;                          /* '<S20>/Add' */
  real_T x_et;                         /* '<S24>/x' */
  real_T x_d;                          /* '<S25>/x' */
  real_T MultiportSwitch[2];           /* '<S3>/Multiport Switch' */
  real_T x_b;                          /* '<S16>/x' */
  real_T x_c;                          /* '<S17>/x' */
  real_T Add_k;                        /* '<S14>/Add' */
  real_T x_j;                          /* '<S18>/x' */
  real_T x_h;                          /* '<S19>/x' */
  real_T LoadSelectSwitch[2];          /* '<S2>/LoadSelect Switch' */
  real_T BehaviorBC_o1[2];             /* '<Root>/Behavior BC' */
  real_T BehaviorBC_o2[5];             /* '<Root>/Behavior BC' */
  real_T BehaviorBC_o3;                /* '<Root>/Behavior BC' */
  real_T BehaviorBC_o4[15];            /* '<Root>/Behavior BC' */
  real_T BehaviorBC_o5;                /* '<Root>/Behavior BC' */
  real_T BehaviorBC_o6[2];             /* '<Root>/Behavior BC' */
  real_T BehaviorBC_o7[4];             /* '<Root>/Behavior BC' */
  real_T BehaviorBC_o8[2];             /* '<Root>/Behavior BC' */
  real_T Switch2[2];                   /* '<S4>/Switch2' */
  real_T MG1;                          /* '<S4>/MG1' */
  real_T MG2;                          /* '<S4>/MG2' */
  real_T Clock_o;                      /* '<S64>/Clock' */
  real_T HiddenBuf_InsertedFor_Sampleand;/* 'synthesized block' */
  real_T Sum_p;                        /* '<S64>/Sum' */
  real_T UniformRandomNumber;          /* '<S6>/Uniform Random Number' */
  real_T Switch_o;                     /* '<S6>/Switch' */
  real_T HiddenBuf_InsertedFor_Samplea_e;/* 'synthesized block' */
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
  real_T y_d;                          /* '<S17>/y' */
  real_T Add1_l;                       /* '<S17>/Add1' */
  real_T z_i;                          /* '<S17>/z' */
  real_T Add3_j;                       /* '<S17>/Add3' */
  real_T product2_a;                   /* '<S17>/product2' */
  real_T Add2_p;                       /* '<S17>/Add2' */
  real_T product3_h;                   /* '<S17>/product3' */
  real_T product4_e;                   /* '<S17>/product4' */
  real_T Add4_c;                       /* '<S17>/Add4' */
  real_T product1_b;                   /* '<S17>/product1' */
  real_T dX_c;                         /* '<S17>/dX' */
  real_T AddX_h;                       /* '<S17>/AddX' */
  real_T dY_d;                         /* '<S17>/dY' */
  real_T AddX1_b;                      /* '<S17>/AddX1' */
  real_T dZ_f;                         /* '<S17>/dZ' */
  real_T AddX2_d;                      /* '<S17>/AddX2' */
  real_T y_a;                          /* '<S18>/y' */
  real_T Add1_g;                       /* '<S18>/Add1' */
  real_T z_g;                          /* '<S18>/z' */
  real_T Add3_o;                       /* '<S18>/Add3' */
  real_T product2_c;                   /* '<S18>/product2' */
  real_T Add2_f;                       /* '<S18>/Add2' */
  real_T product3_p;                   /* '<S18>/product3' */
  real_T product4_g;                   /* '<S18>/product4' */
  real_T Add4_g;                       /* '<S18>/Add4' */
  real_T product1_g;                   /* '<S18>/product1' */
  real_T dX_k;                         /* '<S18>/dX' */
  real_T AddX_n;                       /* '<S18>/AddX' */
  real_T dY_l;                         /* '<S18>/dY' */
  real_T AddX1_a;                      /* '<S18>/AddX1' */
  real_T dZ_o;                         /* '<S18>/dZ' */
  real_T AddX2_e;                      /* '<S18>/AddX2' */
  real_T y_k;                          /* '<S19>/y' */
  real_T Add1_e;                       /* '<S19>/Add1' */
  real_T z_j;                          /* '<S19>/z' */
  real_T Add3_m;                       /* '<S19>/Add3' */
  real_T product2_l;                   /* '<S19>/product2' */
  real_T Add2_o;                       /* '<S19>/Add2' */
  real_T product3_d;                   /* '<S19>/product3' */
  real_T product4_f;                   /* '<S19>/product4' */
  real_T Add4_j;                       /* '<S19>/Add4' */
  real_T product1_l;                   /* '<S19>/product1' */
  real_T dX_m;                         /* '<S19>/dX' */
  real_T AddX_j;                       /* '<S19>/AddX' */
  real_T dY_b;                         /* '<S19>/dY' */
  real_T AddX1_d;                      /* '<S19>/AddX1' */
  real_T dZ_m;                         /* '<S19>/dZ' */
  real_T AddX2_eh;                     /* '<S19>/AddX2' */
  real_T y_p;                          /* '<S22>/y' */
  real_T Add1_gp;                      /* '<S22>/Add1' */
  real_T z_o;                          /* '<S22>/z' */
  real_T Add3_g;                       /* '<S22>/Add3' */
  real_T product2_j;                   /* '<S22>/product2' */
  real_T Add2_k;                       /* '<S22>/Add2' */
  real_T product3_j;                   /* '<S22>/product3' */
  real_T product4_p;                   /* '<S22>/product4' */
  real_T Add4_o;                       /* '<S22>/Add4' */
  real_T product1_a;                   /* '<S22>/product1' */
  real_T dX_b;                         /* '<S22>/dX' */
  real_T AddX_m;                       /* '<S22>/AddX' */
  real_T dY_l3;                        /* '<S22>/dY' */
  real_T AddX1_l;                      /* '<S22>/AddX1' */
  real_T dZ_l;                         /* '<S22>/dZ' */
  real_T AddX2_l;                      /* '<S22>/AddX2' */
  real_T y_am;                         /* '<S23>/y' */
  real_T Add1_h;                       /* '<S23>/Add1' */
  real_T z_e;                          /* '<S23>/z' */
  real_T Add3_f;                       /* '<S23>/Add3' */
  real_T product2_n;                   /* '<S23>/product2' */
  real_T Add2_c;                       /* '<S23>/Add2' */
  real_T product3_ho;                  /* '<S23>/product3' */
  real_T product4_p1;                  /* '<S23>/product4' */
  real_T Add4_e;                       /* '<S23>/Add4' */
  real_T product1_e;                   /* '<S23>/product1' */
  real_T dX_h;                         /* '<S23>/dX' */
  real_T AddX_i;                       /* '<S23>/AddX' */
  real_T dY_d5;                        /* '<S23>/dY' */
  real_T AddX1_bb;                     /* '<S23>/AddX1' */
  real_T dZ_c;                         /* '<S23>/dZ' */
  real_T AddX2_ec;                     /* '<S23>/AddX2' */
  real_T y_kr;                         /* '<S24>/y' */
  real_T Add1_lc;                      /* '<S24>/Add1' */
  real_T z_n;                          /* '<S24>/z' */
  real_T Add3_p;                       /* '<S24>/Add3' */
  real_T product2_f;                   /* '<S24>/product2' */
  real_T Add2_c5;                      /* '<S24>/Add2' */
  real_T product3_f;                   /* '<S24>/product3' */
  real_T product4_et;                  /* '<S24>/product4' */
  real_T Add4_ep;                      /* '<S24>/Add4' */
  real_T product1_f;                   /* '<S24>/product1' */
  real_T dX_l;                         /* '<S24>/dX' */
  real_T AddX_l;                       /* '<S24>/AddX' */
  real_T dY_n;                         /* '<S24>/dY' */
  real_T AddX1_dm;                     /* '<S24>/AddX1' */
  real_T dZ_p;                         /* '<S24>/dZ' */
  real_T AddX2_j;                      /* '<S24>/AddX2' */
  real_T y_f;                          /* '<S25>/y' */
  real_T Add1_m;                       /* '<S25>/Add1' */
  real_T z_n3;                         /* '<S25>/z' */
  real_T Add3_k;                       /* '<S25>/Add3' */
  real_T product2_b;                   /* '<S25>/product2' */
  real_T Add2_k3;                      /* '<S25>/Add2' */
  real_T product3_c;                   /* '<S25>/product3' */
  real_T product4_eg;                  /* '<S25>/product4' */
  real_T Add4_l;                       /* '<S25>/Add4' */
  real_T product1_p;                   /* '<S25>/product1' */
  real_T dX_h4;                        /* '<S25>/dX' */
  real_T AddX_c;                       /* '<S25>/AddX' */
  real_T dY_be;                        /* '<S25>/dY' */
  real_T AddX1_c;                      /* '<S25>/AddX1' */
  real_T dZ_ft;                        /* '<S25>/dZ' */
  real_T AddX2_c;                      /* '<S25>/AddX2' */
  real_T MatrixConcatenation1[4];      /* '<Root>/Matrix Concatenation1' */
  real_T ForIterator;                  /* '<S69>/For Iterator' */
  real_T Switch_b;                     /* '<S69>/Switch' */
  real_T ToBits1_o1;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o2;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o3;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o4;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o5;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o6;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o7;                   /* '<S69>/ToBits1' */
  real_T ToBits1_o8;                   /* '<S69>/ToBits1' */
  real_T Add_ks;                       /* '<S69>/Add' */
  real_T Add1_md;                      /* '<S69>/Add1' */
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
  real_T xPCTargetTime_b;              /* '<S71>/xPC Target  Time ' */
  real_T Subtract;                     /* '<S71>/Subtract' */
  real_T ScaleTouSec;                  /* '<S71>/ScaleTouSec' */
  real_T Switch_n;                     /* '<S71>/Switch' */
  real_T TachGain2;                    /* '<S9>/TachGain2' */
  real_T TachGain1;                    /* '<S9>/TachGain1' */
  real_T TmpHiddenBufferAtMatrixMultiply[2];/* 'synthesized block' */
  real_T MatrixMultiply[2];            /* '<S9>/Matrix Multiply' */
  real_T Gain_i[2];                    /* '<S28>/Gain' */
  real_T MathFunction[4];              /* '<S32>/Math Function' */
  real_T MatrixMultiply_c[2];          /* '<S28>/Matrix Multiply' */
  real_T Switch1[2];                   /* '<S4>/Switch1' */
  real_T Switch_j[2];                  /* '<S5>/Switch' */
  real_T BoundingBoxViscosity[2];      /* '<S5>/Bounding Box Viscosity' */
  real_T Product_g;                    /* '<S40>/Product' */
  real_T Gain1_n;                      /* '<S40>/Gain1' */
  real_T Gain3;                        /* '<S40>/Gain3' */
  real_T Add_i;                        /* '<S40>/Add' */
  real_T Saturation;                   /* '<S40>/Saturation' */
  real_T Gain4;                        /* '<S40>/Gain4' */
  real_T Product1_o;                   /* '<S40>/Product1' */
  real_T Gain2;                        /* '<S40>/Gain2' */
  real_T Add1_ef;                      /* '<S40>/Add1' */
  real_T Saturation1;                  /* '<S40>/Saturation1' */
  real_T Add1_f;                       /* '<S20>/Add1' */
  real_T LorentzForceGain[2];          /* '<S3>/LorentzForceGain' */
  real_T dynamicAngleSwitch;           /* '<S3>/dynamicAngle Switch' */
  real_T sin_h;                        /* '<S21>/sin' */
  real_T Inverter[2];                  /* '<S21>/Inverter' */
  real_T Product3_k;                   /* '<S21>/Product3' */
  real_T cos_c;                        /* '<S21>/cos' */
  real_T Product2_l;                   /* '<S21>/Product2' */
  real_T Subtract_b;                   /* '<S21>/Subtract' */
  real_T Product1_l;                   /* '<S21>/Product1' */
  real_T Product_a;                    /* '<S21>/Product' */
  real_T Add_h;                        /* '<S21>/Add' */
  real_T Gain_d[2];                    /* '<S21>/Gain' */
  real_T Gain_n;                       /* '<S3>/Gain' */
  real_T Add1_k;                       /* '<S14>/Add1' */
  real_T LorentzForceGain_p[2];        /* '<S2>/LorentzForceGain' */
  real_T DynamicAngleSwitch;           /* '<S2>/DynamicAngle Switch' */
  real_T sin_i;                        /* '<S15>/sin' */
  real_T Inverter_k[2];                /* '<S15>/Inverter' */
  real_T Product3_h;                   /* '<S15>/Product3' */
  real_T cos_m;                        /* '<S15>/cos' */
  real_T Product2_g;                   /* '<S15>/Product2' */
  real_T Subtract_e;                   /* '<S15>/Subtract' */
  real_T Product1_p;                   /* '<S15>/Product1' */
  real_T Product_i;                    /* '<S15>/Product' */
  real_T Add_ht;                       /* '<S15>/Add' */
  real_T Gain_f[2];                    /* '<S15>/Gain' */
  real_T Gain_a;                       /* '<S2>/Gain' */
  uint8_T Compare;                     /* '<S33>/Compare' */
  uint8_T Compare_a;                   /* '<S35>/Compare' */
  uint8_T Compare_e;                   /* '<S36>/Compare' */
  uint8_T Compare_o;                   /* '<S59>/Compare' */
  uint8_T Compare_k;                   /* '<S62>/Compare' */
  uint8_T Uk1;                         /* '<S60>/Delay Input1' */
  uint8_T FixPtRelationalOperator;     /* '<S60>/FixPt Relational Operator' */
  uint8_T Compare_h;                   /* '<S52>/Compare' */
  uint8_T Compare_d;                   /* '<S50>/Compare' */
  uint8_T Compare_dw;                  /* '<S51>/Compare' */
  uint8_T Compare_do;                  /* '<S58>/Compare' */
  uint8_T Uk1_c;                       /* '<S45>/Delay Input1' */
  uint8_T FixPtRelationalOperator_p;   /* '<S45>/FixPt Relational Operator' */
  uint8_T Compare_l;                   /* '<S56>/Compare' */
  uint8_T Compare_ez;                  /* '<S49>/Compare' */
  uint8_T Uk1_j;                       /* '<S38>/Delay Input1' */
  uint8_T FixPtRelationalOperator_j;   /* '<S38>/FixPt Relational Operator' */
  uint8_T Compare_n;                   /* '<S54>/Compare' */
  uint8_T Compare_dc;                  /* '<S48>/Compare' */
  uint8_T Uk1_m;                       /* '<S37>/Delay Input1' */
  uint8_T FixPtRelationalOperator_o;   /* '<S37>/FixPt Relational Operator' */
  uint8_T Compare_p;                   /* '<S26>/Compare' */
  uint8_T Compare_hq;                  /* '<S27>/Compare' */
  uint8_T Pack[168];                   /* '<S7>/Pack' */
  uint8_T RateTransition[168];         /* '<S7>/Rate Transition' */
  boolean_T Memory;                    /* '<S30>/Memory' */
  boolean_T Memory_k;                  /* '<S4>/Memory' */
  boolean_T LogicalOperator2;          /* '<S30>/Logical Operator2' */
  boolean_T LogicalOperator1;          /* '<S30>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_EnabledSu;/* '<S30>/Logical Operator1' */
  boolean_T RelationalOperator;        /* '<S30>/Relational Operator' */
  boolean_T LogicalOperator;           /* '<S30>/Logical Operator' */
  boolean_T Memory_b;                  /* '<S42>/Memory' */
  boolean_T RelationalOperator_g;      /* '<S1>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S1>/Relational Operator1' */
  boolean_T RelationalOperator2;       /* '<S1>/Relational Operator2' */
  boolean_T RelationalOperator3;       /* '<S1>/Relational Operator3' */
  boolean_T LogicalOperator_a;         /* '<S1>/Logical Operator' */
  boolean_T InBox;                     /* '<S5>/InBox' */
  boolean_T LogicalOperator3;          /* '<S46>/Logical Operator3' */
  boolean_T Memory_b5;                 /* '<S46>/Memory' */
  boolean_T LogicalOperator4;          /* '<S46>/Logical Operator4' */
  boolean_T LogicalOperator_j;         /* '<S5>/Logical Operator' */
  boolean_T LogicalOperator2_m;        /* '<S46>/Logical Operator2' */
  boolean_T LogicalOperator1_f;        /* '<S46>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_g;/* '<S46>/Logical Operator1' */
  boolean_T RelationalOperator_i;      /* '<S46>/Relational Operator' */
  boolean_T LogicalOperator_n;         /* '<S46>/Logical Operator' */
  boolean_T LogicalOperator5;          /* '<S46>/Logical Operator5' */
  boolean_T LogicalOperator2_a;        /* '<S42>/Logical Operator2' */
  boolean_T LogicalOperator1_c;        /* '<S42>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_j;/* '<S42>/Logical Operator1' */
  boolean_T RelationalOperator_l;      /* '<S42>/Relational Operator' */
  boolean_T LogicalOperator_e;         /* '<S42>/Logical Operator' */
  boolean_T LogicalOperator1_e;        /* '<S39>/Logical Operator1' */
  boolean_T NOT;                       /* '<S5>/NOT' */
  boolean_T Memory_n;                  /* '<S44>/Memory' */
  boolean_T LogicalOperator2_a2;       /* '<S44>/Logical Operator2' */
  boolean_T LogicalOperator1_i;        /* '<S44>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_a;/* '<S44>/Logical Operator1' */
  boolean_T RelationalOperator_p;      /* '<S44>/Relational Operator' */
  boolean_T LogicalOperator_c;         /* '<S44>/Logical Operator' */
  boolean_T DataTypeConversion2;       /* '<S5>/Data Type Conversion2' */
  boolean_T LogicalOperator1_g;        /* '<S5>/Logical Operator1' */
  boolean_T Memory_m;                  /* '<S43>/Memory' */
  boolean_T LogicalOperator2_i;        /* '<S43>/Logical Operator2' */
  boolean_T LogicalOperator1_l;        /* '<S43>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_l;/* '<S43>/Logical Operator1' */
  boolean_T RelationalOperator_k;      /* '<S43>/Relational Operator' */
  boolean_T LogicalOperator_nd;        /* '<S43>/Logical Operator' */
  boolean_T DataTypeConversion1;       /* '<S5>/Data Type Conversion1' */
  boolean_T Memory_j;                  /* '<S41>/Memory' */
  boolean_T Logic[2];                  /* '<S41>/Logic' */
  boolean_T LogicalOperator5_k;        /* '<S5>/Logical Operator5' */
  boolean_T LogicalOperator1_it;       /* '<S4>/Logical Operator1' */
  boolean_T MatrixConcatenation[2];    /* '<S4>/Matrix Concatenation' */
  boolean_T RelationalOperator_ka;     /* '<S6>/Relational Operator' */
  boolean_T RelationalOperator_b;      /* '<S64>/Relational Operator' */
  boolean_T Compare_c;                 /* '<S73>/Compare' */
  boolean_T Compare_b;                 /* '<S72>/Compare' */
  boolean_T LogicalOperator6;          /* '<S5>/Logical Operator6' */
  boolean_T LogicalOperator3_d;        /* '<S5>/Logical Operator3' */
  rtB_SampleandHold_bump_choice SampleandHold;/* '<S64>/Sample and Hold' */
  rtB_SampleandHold_bump_choice SampleandHold_h;/* '<S6>/Sample and Hold' */
  rtB_EnabledSubsystem_bump_choic EnabledSubsystem_l;/* '<S46>/Enabled Subsystem' */
  rtB_EnabledSubsystem_bump_choic EnabledSubsystem_e;/* '<S44>/Enabled Subsystem' */
  rtB_EnabledSubsystem_bump_choic EnabledSubsystem_o;/* '<S43>/Enabled Subsystem' */
  rtB_EnabledSubsystem_bump_choic EnabledSubsystem_p;/* '<S42>/Enabled Subsystem' */
  rtB_EnabledSubsystem_bump_choic EnabledSubsystem;/* '<S30>/Enabled Subsystem' */
} BlockIO_bump_choice;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DigitalFilter2_FILT_STATES[11];/* '<S66>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES[11];/* '<S66>/Digital Filter' */
  real_T DigitalFilter2_FILT_STATES_a[11];/* '<S67>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES_e[11];/* '<S67>/Digital Filter' */
  real_T x_DSTATE;                     /* '<S22>/x' */
  real_T x_DSTATE_n;                   /* '<S23>/x' */
  real_T x_DSTATE_i;                   /* '<S24>/x' */
  real_T x_DSTATE_in;                  /* '<S25>/x' */
  real_T x_DSTATE_m;                   /* '<S16>/x' */
  real_T x_DSTATE_h;                   /* '<S17>/x' */
  real_T x_DSTATE_o;                   /* '<S18>/x' */
  real_T x_DSTATE_d;                   /* '<S19>/x' */
  real_T BehaviorBC_DSTATE;            /* '<Root>/Behavior BC' */
  real_T y_DSTATE;                     /* '<S16>/y' */
  real_T z_DSTATE;                     /* '<S16>/z' */
  real_T y_DSTATE_a;                   /* '<S17>/y' */
  real_T z_DSTATE_n;                   /* '<S17>/z' */
  real_T y_DSTATE_n;                   /* '<S18>/y' */
  real_T z_DSTATE_c;                   /* '<S18>/z' */
  real_T y_DSTATE_i;                   /* '<S19>/y' */
  real_T z_DSTATE_a;                   /* '<S19>/z' */
  real_T y_DSTATE_a5;                  /* '<S22>/y' */
  real_T z_DSTATE_e;                   /* '<S22>/z' */
  real_T y_DSTATE_ae;                  /* '<S23>/y' */
  real_T z_DSTATE_p;                   /* '<S23>/z' */
  real_T y_DSTATE_l;                   /* '<S24>/y' */
  real_T z_DSTATE_m;                   /* '<S24>/z' */
  real_T y_DSTATE_f;                   /* '<S25>/y' */
  real_T z_DSTATE_f;                   /* '<S25>/z' */
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
  } Derivative_RWORK_e;                /* '<S67>/Derivative' */

  real_T BehaviorBC_RWORK[6];          /* '<Root>/Behavior BC' */
  real_T PCI6025E_RWORK[6];            /* '<S4>/PCI-6025E ' */
  struct {
    real_T NextOutput;
  } UniformRandomNumber_RWORK;         /* '<S6>/Uniform Random Number' */

  void *BehaviorBC_PWORK;              /* '<Root>/Behavior BC' */
  void *Send_PWORK;                    /* '<S7>/Send' */
  int32_T DigitalFilter2_CIRCBUFFIDX;  /* '<S66>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX;   /* '<S66>/Digital Filter' */
  int32_T DigitalFilter2_CIRCBUFFIDX_j;/* '<S67>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX_c; /* '<S67>/Digital Filter' */
  int_T PCIQUAD04_IWORK;               /* '<S12>/PCI-QUAD04 ' */
  int_T PCIQUAD041_IWORK;              /* '<S12>/PCI-QUAD04 1' */
  int_T PCI6025EAD_IWORK[66];          /* '<S9>/PCI-6025E AD' */
  int_T BehaviorBC_IWORK[9];           /* '<Root>/Behavior BC' */
  int_T PCI6025E_IWORK[2];             /* '<S4>/PCI-6025E ' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S29>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_n;                 /* '<S31>/S-Function' */

  int_T Send_IWORK[2];                 /* '<S7>/Send' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK_e;                 /* '<S8>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_g;                 /* '<S10>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_h;                 /* '<S13>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_d;                 /* '<S47>/S-Function' */

  struct {
    int_T RandSeed;
  } UniformRandomNumber_IWORK;         /* '<S6>/Uniform Random Number' */

  int_T PortA_IWORK[2];                /* '<S69>/Port A' */
  int_T PortB_IWORK[2];                /* '<S69>/Port B' */
  int_T PCI6025E_IWORK_j[3];           /* '<S71>/PCI-6025E ' */
  uint8_T DelayInput1_DSTATE;          /* '<S60>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_h;        /* '<S45>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_f;        /* '<S38>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_l;        /* '<S37>/Delay Input1' */
  boolean_T Memory_PreviousInput;      /* '<S30>/Memory' */
  boolean_T Memory_PreviousInput_i;    /* '<S4>/Memory' */
  boolean_T Memory_PreviousInput_d;    /* '<S42>/Memory' */
  boolean_T Memory_PreviousInput_dp;   /* '<S46>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S44>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<S43>/Memory' */
  boolean_T Memory_PreviousInput_iw;   /* '<S41>/Memory' */
  rtDW_SampleandHold_bump_choice SampleandHold;/* '<S64>/Sample and Hold' */
  rtDW_SampleandHold_bump_choice SampleandHold_h;/* '<S6>/Sample and Hold' */
  rtDW_EnabledSubsystem_bump_choi EnabledSubsystem_l;/* '<S46>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_bump_choi EnabledSubsystem_e;/* '<S44>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_bump_choi EnabledSubsystem_o;/* '<S43>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_bump_choi EnabledSubsystem_p;/* '<S42>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_bump_choi EnabledSubsystem;/* '<S30>/Enabled Subsystem' */
} D_Work_bump_choice;

/* Zero-crossing (trigger) state */
typedef struct {
  rtZCE_SampleandHold_bump_choice SampleandHold;/* '<S6>/Sample and Hold' */
  rtZCE_SampleandHold_bump_choice SampleandHold_h;/* '<S6>/Sample and Hold' */
} PrevZCSigStates_bump_choice;

/* Backward compatible GRT Identifiers */
#define rtB                            bump_choice_B
#define BlockIO                        BlockIO_bump_choice
#define rtXdot                         bump_choice_Xdot
#define StateDerivatives               StateDerivatives_bump_choice
#define tXdis                          bump_choice_Xdis
#define StateDisabled                  StateDisabled_bump_choice
#define rtP                            bump_choice_P
#define Parameters                     Parameters_bump_choice
#define rtDWork                        bump_choice_DWork
#define D_Work                         D_Work_bump_choice
#define rtPrevZCSigState               bump_choice_PrevZCSigState
#define PrevZCSigStates                PrevZCSigStates_bump_choice

/* Parameters for system: '<S6>/Sample and Hold' */
struct rtP_SampleandHold_bump_choice {
  real_T _Y0;                          /* Expression: initCond
                                        * 'synthesized block'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_bump_choice {
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
  real_T Gain_Gain_a;                  /* Expression: -1
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
  real_T Gain1_Gain_m;                 /* Expression: -1
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
  real_T DigitalFilter2_ICRTP_i;       /* Expression: a.IC
                                        * '<S67>/Digital Filter2'
                                        */
  real_T DigitalFilter2_RTP1COEFF_g[11];/* Expression: NumCoeffs
                                         * '<S67>/Digital Filter2'
                                         */
  real_T dG_Gain_l;                    /* Expression: 1
                                        * '<S67>/dG'
                                        */
  real_T DigitalFilter_ICRTP_l;        /* Expression: a.IC
                                        * '<S67>/Digital Filter'
                                        */
  real_T DigitalFilter_RTP1COEFF_a[11];/* Expression: NumCoeffs
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
  real_T Time_Value_p;                 /* Expression: Time
                                        * '<S46>/Time'
                                        */
  real_T Time_Value_c;                 /* Expression: Time
                                        * '<S42>/Time'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * '<S50>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: const
                                        * '<S51>/Constant'
                                        */
  real_T Time_Value_o;                 /* Expression: Time
                                        * '<S44>/Time'
                                        */
  real_T Time_Value_h;                 /* Expression: Time
                                        * '<S43>/Time'
                                        */
  real_T Load_Value;                   /* Expression: 0
                                        * '<S3>/Load'
                                        */
  real_T x_X0;                         /* Expression: .1
                                        * '<S22>/x'
                                        */
  real_T x_X0_p;                       /* Expression: .1
                                        * '<S23>/x'
                                        */
  real_T x_X0_n;                       /* Expression: .1
                                        * '<S24>/x'
                                        */
  real_T x_X0_pt;                      /* Expression: .1
                                        * '<S25>/x'
                                        */
  real_T Load_Value_d;                 /* Expression: 0
                                        * '<S2>/Load'
                                        */
  real_T x_X0_i;                       /* Expression: .1
                                        * '<S16>/x'
                                        */
  real_T x_X0_k;                       /* Expression: .1
                                        * '<S17>/x'
                                        */
  real_T x_X0_nd;                      /* Expression: .1
                                        * '<S18>/x'
                                        */
  real_T x_X0_a;                       /* Expression: .1
                                        * '<S19>/x'
                                        */
  real_T BehaviorBC_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P1;                /* Expression: 10
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P2;                /* Expression: 3
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P3;                /* Expression: 5
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P4;                /* Expression: 7
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P5;                /* Expression: 0.0
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P6;                /* Expression: 0.05
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P7_Size[2];        /* Computed Parameter: P7Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P7;                /* Expression: 125
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P8_Size[2];        /* Computed Parameter: P8Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P8;                /* Expression: 0.5
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P9_Size[2];        /* Computed Parameter: P9Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P9;                /* Expression: 2
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P10_Size[2];       /* Computed Parameter: P10Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P10;               /* Expression: 10
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P11_Size[2];       /* Computed Parameter: P11Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P11;               /* Expression: 1
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P12_Size[2];       /* Computed Parameter: P12Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P12;               /* Expression: 0
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P13_Size[2];       /* Computed Parameter: P13Size
                                        * '<Root>/Behavior BC'
                                        */
  real_T BehaviorBC_P13;               /* Expression: 0
                                        * '<Root>/Behavior BC'
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
  real_T Constant_Value_j;             /* Expression: const
                                        * '<S26>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: const
                                        * '<S27>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 3
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
  real_T y_X0_l;                       /* Expression: y0
                                        * '<S17>/y'
                                        */
  real_T rho_Value_e;                  /* Expression: 28
                                        * '<S17>/rho'
                                        */
  real_T z_X0_b;                       /* Expression: .1
                                        * '<S17>/z'
                                        */
  real_T beta_Value_a;                 /* Expression: 8/3
                                        * '<S17>/beta'
                                        */
  real_T timescale_Value_m;            /* Expression: .0001
                                        * '<S17>/timescale'
                                        */
  real_T sigma_Value_g;                /* Expression: 10
                                        * '<S17>/sigma'
                                        */
  real_T y_X0_a;                       /* Expression: y0
                                        * '<S18>/y'
                                        */
  real_T rho_Value_eb;                 /* Expression: 28
                                        * '<S18>/rho'
                                        */
  real_T z_X0_bn;                      /* Expression: .1
                                        * '<S18>/z'
                                        */
  real_T beta_Value_l;                 /* Expression: 8/3
                                        * '<S18>/beta'
                                        */
  real_T timescale_Value_l;            /* Expression: .0001
                                        * '<S18>/timescale'
                                        */
  real_T sigma_Value_j;                /* Expression: 10
                                        * '<S18>/sigma'
                                        */
  real_T y_X0_k;                       /* Expression: y0
                                        * '<S19>/y'
                                        */
  real_T rho_Value_n;                  /* Expression: 28
                                        * '<S19>/rho'
                                        */
  real_T z_X0_i;                       /* Expression: .1
                                        * '<S19>/z'
                                        */
  real_T beta_Value_c;                 /* Expression: 8/3
                                        * '<S19>/beta'
                                        */
  real_T timescale_Value_f;            /* Expression: .0001
                                        * '<S19>/timescale'
                                        */
  real_T sigma_Value_jm;               /* Expression: 10
                                        * '<S19>/sigma'
                                        */
  real_T y_X0_i;                       /* Expression: y0
                                        * '<S22>/y'
                                        */
  real_T rho_Value_f;                  /* Expression: 28
                                        * '<S22>/rho'
                                        */
  real_T z_X0_n;                       /* Expression: .1
                                        * '<S22>/z'
                                        */
  real_T beta_Value_b;                 /* Expression: 8/3
                                        * '<S22>/beta'
                                        */
  real_T timescale_Value_mg;           /* Expression: .0001
                                        * '<S22>/timescale'
                                        */
  real_T sigma_Value_m;                /* Expression: 10
                                        * '<S22>/sigma'
                                        */
  real_T y_X0_m;                       /* Expression: y0
                                        * '<S23>/y'
                                        */
  real_T rho_Value_b;                  /* Expression: 28
                                        * '<S23>/rho'
                                        */
  real_T z_X0_a;                       /* Expression: .1
                                        * '<S23>/z'
                                        */
  real_T beta_Value_m;                 /* Expression: 8/3
                                        * '<S23>/beta'
                                        */
  real_T timescale_Value_e;            /* Expression: .0001
                                        * '<S23>/timescale'
                                        */
  real_T sigma_Value_j0;               /* Expression: 10
                                        * '<S23>/sigma'
                                        */
  real_T y_X0_p;                       /* Expression: y0
                                        * '<S24>/y'
                                        */
  real_T rho_Value_h;                  /* Expression: 28
                                        * '<S24>/rho'
                                        */
  real_T z_X0_i4;                      /* Expression: .1
                                        * '<S24>/z'
                                        */
  real_T beta_Value_n;                 /* Expression: 8/3
                                        * '<S24>/beta'
                                        */
  real_T timescale_Value_d;            /* Expression: .0001
                                        * '<S24>/timescale'
                                        */
  real_T sigma_Value_c;                /* Expression: 10
                                        * '<S24>/sigma'
                                        */
  real_T y_X0_c;                       /* Expression: y0
                                        * '<S25>/y'
                                        */
  real_T rho_Value_a;                  /* Expression: 28
                                        * '<S25>/rho'
                                        */
  real_T z_X0_f;                       /* Expression: .1
                                        * '<S25>/z'
                                        */
  real_T beta_Value_g;                 /* Expression: 8/3
                                        * '<S25>/beta'
                                        */
  real_T timescale_Value_j;            /* Expression: .0001
                                        * '<S25>/timescale'
                                        */
  real_T sigma_Value_l;                /* Expression: 10
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
  real_T Gain_Gain_ap;                 /* Expression: 1
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
  real_T Gain_Gain_b;                  /* Expression: 0.0367
                                        * '<S3>/Gain'
                                        */
  real_T visAngle_Value_n;             /* Expression: 0
                                        * '<S3>/visAngle'
                                        */
  real_T DynamicAngle_Value_f;         /* Expression: 0
                                        * '<S3>/DynamicAngle'
                                        */
  real_T Inverter_Gain_j;              /* Expression: -1
                                        * '<S21>/Inverter'
                                        */
  real_T Gain_Gain_by;                 /* Expression: 1
                                        * '<S21>/Gain'
                                        */
  real_T LorentzForceGain_Gain_c;      /* Expression: .0005
                                        * '<S3>/LorentzForceGain'
                                        */
  real_T staticX_Value_h;              /* Expression: 0
                                        * '<S3>/staticX'
                                        */
  real_T staticY_Value_b;              /* Expression: 0
                                        * '<S3>/staticY'
                                        */
  real_T Off_Value_f;                  /* Expression: 0
                                        * '<S3>/Off'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: -.001
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
  real_T Gain2_Gain_o;                 /* Expression: -.001
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
  real_T Gain_Gain_j;                  /* Expression: -1
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
  real_T Constant_Value_h;             /* Expression: 1
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
  real_T Constant_Value_b;             /* Expression: const
                                        * '<S73>/Constant'
                                        */
  real_T PCI6025E_P1_Size_g[2];        /* Computed Parameter: P1Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P1_d[2];             /* Expression: channel
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_Size_j[2];        /* Computed Parameter: P2Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_k[2];             /* Expression: reset
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_Size_i[2];        /* Computed Parameter: P3Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_l[2];             /* Expression: initValue
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_Size_j[2];        /* Computed Parameter: P4Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_o;                /* Expression: sampletime
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_Size_h[2];        /* Computed Parameter: P5Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_m;                /* Expression: slot
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_Size_c[2];        /* Computed Parameter: P6Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_f;                /* Expression: control
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_Size_i[2];        /* Computed Parameter: P7Size
                                        * '<S71>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_f;                /* Expression: boardType
                                        * '<S71>/PCI-6025E '
                                        */
  real_T Constant_Value_jz;            /* Expression: const
                                        * '<S72>/Constant'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 2
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
  real_T Constant_Value_m;             /* Expression: 32768
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
  real_T xPCTargetTime_P1_Size_l[2];   /* Computed Parameter: P1Size
                                        * '<S69>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1_h;           /* Expression: func
                                        * '<S69>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size_c[2];   /* Computed Parameter: P2Size
                                        * '<S69>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_g;           /* Expression: ts
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
  uint8_T DelayInput1_X0_n;            /* Computed Parameter: X0
                                        * '<S45>/Delay Input1'
                                        */
  uint8_T DelayInput1_X0_m;            /* Computed Parameter: X0
                                        * '<S38>/Delay Input1'
                                        */
  uint8_T DelayInput1_X0_o;            /* Computed Parameter: X0
                                        * '<S37>/Delay Input1'
                                        */
  boolean_T Memory_X0;                 /* Computed Parameter: X0
                                        * '<S30>/Memory'
                                        */
  boolean_T Memory_X0_l;               /* Computed Parameter: X0
                                        * '<S4>/Memory'
                                        */
  boolean_T Memory_X0_p;               /* Computed Parameter: X0
                                        * '<S42>/Memory'
                                        */
  boolean_T Memory_X0_d;               /* Computed Parameter: X0
                                        * '<S46>/Memory'
                                        */
  boolean_T Memory_X0_k;               /* Computed Parameter: X0
                                        * '<S44>/Memory'
                                        */
  boolean_T Memory_X0_e;               /* Computed Parameter: X0
                                        * '<S43>/Memory'
                                        */
  boolean_T Memory_X0_c;               /* Computed Parameter: X0
                                        * '<S41>/Memory'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: TruthTable
                                        * '<S41>/Logic'
                                        */
  rtP_SampleandHold_bump_choice SampleandHold;/* '<S6>/Sample and Hold' */
  rtP_SampleandHold_bump_choice SampleandHold_h;/* '<S6>/Sample and Hold' */
};

/* Real-time Model Data Structure */
struct rtModel_bump_choice {
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
      struct _ssPortInputs inputPortInfo[3];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[2];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[13];
      mxArray *params[13];
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
extern Parameters_bump_choice bump_choice_P;

/* Block signals (auto storage) */
extern BlockIO_bump_choice bump_choice_B;

/* Block states (auto storage) */
extern D_Work_bump_choice bump_choice_DWork;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_bump_choice bump_choice_PrevZCSigState;

/* Model entry point functions */
extern void bump_choice_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void bump_choice_initialize(boolean_T firstTime);
extern void bump_choice_output(int_T tid);
extern void bump_choice_update(int_T tid);
extern void bump_choice_terminate(void);

/* Real-time Model object */
extern rtModel_bump_choice *bump_choice_rtM;

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
 * '<Root>' : bump_choice
 * '<S1>'   : bump_choice/BoundingBox
 * '<S2>'   : bump_choice/Catch Force Generator
 * '<S3>'   : bump_choice/Force Generator
 * '<S4>'   : bump_choice/Motor Control
 * '<S5>'   : bump_choice/Recentering Subsystem
 * '<S6>'   : bump_choice/RewardSbs
 * '<S7>'   : bump_choice/SendPacketToGraphics1
 * '<S8>'   : bump_choice/Status
 * '<S9>'   : bump_choice/Velocity Calculation
 * '<S10>'  : bump_choice/Version Display
 * '<S11>'  : bump_choice/WordSbs
 * '<S12>'  : bump_choice/XY Position Subsystem
 * '<S13>'  : bump_choice/Xpos
 * '<S14>'  : bump_choice/Catch Force Generator/LorentzForce
 * '<S15>'  : bump_choice/Catch Force Generator/ViscLoadSubsystem
 * '<S16>'  : bump_choice/Catch Force Generator/LorentzForce/Lorentz
 * '<S17>'  : bump_choice/Catch Force Generator/LorentzForce/Lorentz1
 * '<S18>'  : bump_choice/Catch Force Generator/LorentzForce/Lorentz2
 * '<S19>'  : bump_choice/Catch Force Generator/LorentzForce/Lorentz3
 * '<S20>'  : bump_choice/Force Generator/LorentzForce
 * '<S21>'  : bump_choice/Force Generator/ViscLoadSubsystem
 * '<S22>'  : bump_choice/Force Generator/LorentzForce/Lorentz
 * '<S23>'  : bump_choice/Force Generator/LorentzForce/Lorentz1
 * '<S24>'  : bump_choice/Force Generator/LorentzForce/Lorentz2
 * '<S25>'  : bump_choice/Force Generator/LorentzForce/Lorentz3
 * '<S26>'  : bump_choice/Motor Control/Compare To Constant
 * '<S27>'  : bump_choice/Motor Control/Compare To Constant1
 * '<S28>'  : bump_choice/Motor Control/Force//Torque Transform
 * '<S29>'  : bump_choice/Motor Control/Recenter//ServoKill
 * '<S30>'  : bump_choice/Motor Control/Schmidt
 * '<S31>'  : bump_choice/Motor Control/Xpos
 * '<S32>'  : bump_choice/Motor Control/Force//Torque Transform/Transpose
 * '<S33>'  : bump_choice/Motor Control/Schmidt/Compare To Zero
 * '<S34>'  : bump_choice/Motor Control/Schmidt/Enabled Subsystem
 * '<S35>'  : bump_choice/Recentering Subsystem/Compare To Zero
 * '<S36>'  : bump_choice/Recentering Subsystem/Compare To Zero1
 * '<S37>'  : bump_choice/Recentering Subsystem/Falling Edge
 * '<S38>'  : bump_choice/Recentering Subsystem/Falling Edge1
 * '<S39>'  : bump_choice/Recentering Subsystem/No Movement
 * '<S40>'  : bump_choice/Recentering Subsystem/PD Controller
 * '<S41>'  : bump_choice/Recentering Subsystem/S-R Flip-Flop
 * '<S42>'  : bump_choice/Recentering Subsystem/Schmidt1
 * '<S43>'  : bump_choice/Recentering Subsystem/Schmidt2
 * '<S44>'  : bump_choice/Recentering Subsystem/Schmidt3
 * '<S45>'  : bump_choice/Recentering Subsystem/Start Moving
 * '<S46>'  : bump_choice/Recentering Subsystem/Timer
 * '<S47>'  : bump_choice/Recentering Subsystem/Xpos1
 * '<S48>'  : bump_choice/Recentering Subsystem/Falling Edge/Nonpositive
 * '<S49>'  : bump_choice/Recentering Subsystem/Falling Edge1/Nonpositive
 * '<S50>'  : bump_choice/Recentering Subsystem/No Movement/Compare To Constant2
 * '<S51>'  : bump_choice/Recentering Subsystem/No Movement/Compare To Constant3
 * '<S52>'  : bump_choice/Recentering Subsystem/Schmidt1/Compare To Zero
 * '<S53>'  : bump_choice/Recentering Subsystem/Schmidt1/Enabled Subsystem
 * '<S54>'  : bump_choice/Recentering Subsystem/Schmidt2/Compare To Zero
 * '<S55>'  : bump_choice/Recentering Subsystem/Schmidt2/Enabled Subsystem
 * '<S56>'  : bump_choice/Recentering Subsystem/Schmidt3/Compare To Zero
 * '<S57>'  : bump_choice/Recentering Subsystem/Schmidt3/Enabled Subsystem
 * '<S58>'  : bump_choice/Recentering Subsystem/Start Moving/Nonpositive
 * '<S59>'  : bump_choice/Recentering Subsystem/Timer/Compare To Zero
 * '<S60>'  : bump_choice/Recentering Subsystem/Timer/Detect Fall Nonpositive
 * '<S61>'  : bump_choice/Recentering Subsystem/Timer/Enabled Subsystem
 * '<S62>'  : bump_choice/Recentering Subsystem/Timer/Detect Fall Nonpositive/Nonpositive
 * '<S63>'  : bump_choice/RewardSbs/Sample and Hold
 * '<S64>'  : bump_choice/RewardSbs/Schmidt
 * '<S65>'  : bump_choice/RewardSbs/Schmidt/Sample and Hold
 * '<S66>'  : bump_choice/Velocity Calculation/Pos2VelX
 * '<S67>'  : bump_choice/Velocity Calculation/Pos2VelY
 * '<S68>'  : bump_choice/XY Position Subsystem/Cursor Rotation
 * '<S69>'  : bump_choice/XY Position Subsystem/For Iterator Subsystem
 * '<S70>'  : bump_choice/XY Position Subsystem/Jacobian-Cartesian Transformation
 * '<S71>'  : bump_choice/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem
 * '<S72>'  : bump_choice/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant
 * '<S73>'  : bump_choice/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1
 */
#endif                                 /* _RTW_HEADER_bump_choice_h_ */
