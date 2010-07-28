/*
 * center_out.h
 *
 * Real-Time Workshop code generation for Simulink model "center_out.mdl".
 *
 * Model Version              : 1.1201
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:09 2010
 */
#ifndef _RTW_HEADER_center_out_h_
#define _RTW_HEADER_center_out_h_
#include "rtw_modelmap.h"
#ifndef _center_out_COMMON_INCLUDES_
# define _center_out_COMMON_INCLUDES_
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
#endif                                 /* _center_out_COMMON_INCLUDES_ */

#include "center_out_types.h"

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
#define center_out_M                   center_out_rtM

/* Definition for use in the target main file */
#define center_out_rtModel             rtModel_center_out

/* Block signals for system '<S31>/Enabled Subsystem' */
typedef struct {
  real_T In1;                          /* '<S35>/In1' */
} rtB_EnabledSubsystem_center_out;

/* Block states (auto storage) for system '<S31>/Enabled Subsystem' */
typedef struct {
  int_T EnabledSubsystem_MODE;         /* '<S31>/Enabled Subsystem' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S31>/Enabled Subsystem' */
} rtDW_EnabledSubsystem_center_ou;

/* Block signals for system '<S6>/Sample and Hold' */
typedef struct {
  real_T In;                           /* '<S64>/In' */
} rtB_SampleandHold_center_out;

/* Block states (auto storage) for system '<S6>/Sample and Hold' */
typedef struct {
  int8_T SampleandHold_SubsysRanBC;    /* '<S6>/Sample and Hold' */
} rtDW_SampleandHold_center_out;

/* Zero-crossing (trigger) state for system '<S6>/Sample and Hold' */
typedef struct {
  ZCSigState SampleandHold_ZCE;        /* '<S6>/Sample and Hold' */
} rtZCE_SampleandHold_center_out;

/* Block signals (auto storage) */
typedef struct {
  real_T Clock;                        /* '<S31>/Clock' */
  real_T Sum;                          /* '<S31>/Sum' */
  real_T PCIQUAD04;                    /* '<S13>/PCI-QUAD04 ' */
  real_T Gain;                         /* '<S13>/Gain' */
  real_T Sum3;                         /* '<S13>/Sum3' */
  real_T TrigonometricFunction;        /* '<S71>/Trigonometric Function' */
  real_T Product;                      /* '<S71>/Product' */
  real_T TrigonometricFunction1;       /* '<S71>/Trigonometric Function1' */
  real_T Product1;                     /* '<S71>/Product1' */
  real_T PCIQUAD041;                   /* '<S13>/PCI-QUAD04 1' */
  real_T Gain1;                        /* '<S13>/Gain1' */
  real_T Sum1;                         /* '<S13>/Sum1' */
  real_T TrigonometricFunction2;       /* '<S71>/Trigonometric Function2' */
  real_T Product2;                     /* '<S71>/Product2' */
  real_T TrigonometricFunction3;       /* '<S71>/Trigonometric Function3' */
  real_T Product3;                     /* '<S71>/Product3' */
  real_T MatrixConcatenate2[4];        /* '<S71>/Matrix Concatenate2' */
  real_T PCI6025EAD_o1;                /* '<S10>/PCI-6025E AD' */
  real_T PCI6025EAD_o2;                /* '<S10>/PCI-6025E AD' */
  real_T Sum2;                         /* '<S71>/Sum2' */
  real_T Sum4;                         /* '<S71>/Sum4' */
  real_T Sum3_d;                       /* '<S71>/Sum3' */
  real_T Sum1_k;                       /* '<S71>/Sum1' */
  real_T TrigonometricFunction1_p;     /* '<S69>/Trigonometric Function1' */
  real_T Sum_j;                        /* '<S69>/Sum' */
  real_T TrigonometricFunction2_j;     /* '<S69>/Trigonometric Function2' */
  real_T sqrtu1u1u2u2;                 /* '<S69>/sqrt(u[1]*u[1] + u[2]*u[2])' */
  real_T Product1_d;                   /* '<S69>/Product1' */
  real_T DigitalFilter2;               /* '<S67>/Digital Filter2' */
  real_T Derivative;                   /* '<S67>/Derivative' */
  real_T dG;                           /* '<S67>/dG' */
  real_T DigitalFilter;                /* '<S67>/Digital Filter' */
  real_T TrigonometricFunction_d;      /* '<S69>/Trigonometric Function' */
  real_T Product_l;                    /* '<S69>/Product' */
  real_T DigitalFilter2_l;             /* '<S68>/Digital Filter2' */
  real_T Derivative_m;                 /* '<S68>/Derivative' */
  real_T dG_f;                         /* '<S68>/dG' */
  real_T DigitalFilter_m;              /* '<S68>/Digital Filter' */
  real_T Switch[2];                    /* '<S10>/Switch' */
  real_T Clock_e;                      /* '<S43>/Clock' */
  real_T Clock_o;                      /* '<S47>/Clock' */
  real_T Sum_h;                        /* '<S47>/Sum' */
  real_T Sum_n;                        /* '<S43>/Sum' */
  real_T Abs2;                         /* '<S40>/Abs2' */
  real_T Abs3;                         /* '<S40>/Abs3' */
  real_T Clock_j;                      /* '<S45>/Clock' */
  real_T Sum_d;                        /* '<S45>/Sum' */
  real_T Clock_d;                      /* '<S44>/Clock' */
  real_T Sum_ju;                       /* '<S44>/Sum' */
  real_T x;                            /* '<S23>/x' */
  real_T x_j;                          /* '<S24>/x' */
  real_T Add;                          /* '<S21>/Add' */
  real_T x_k;                          /* '<S25>/x' */
  real_T x_l;                          /* '<S26>/x' */
  real_T MultiportSwitch[2];           /* '<S3>/Multiport Switch' */
  real_T x_g;                          /* '<S17>/x' */
  real_T x_f;                          /* '<S18>/x' */
  real_T Add_g;                        /* '<S15>/Add' */
  real_T x_p;                          /* '<S19>/x' */
  real_T x_g2;                         /* '<S20>/x' */
  real_T LoadSelectSwitch[2];          /* '<S2>/LoadSelect Switch' */
  real_T BehaviorCO_o1[2];             /* '<Root>/Behavior CO' */
  real_T BehaviorCO_o2[5];             /* '<Root>/Behavior CO' */
  real_T BehaviorCO_o3;                /* '<Root>/Behavior CO' */
  real_T BehaviorCO_o4[10];            /* '<Root>/Behavior CO' */
  real_T BehaviorCO_o5;                /* '<Root>/Behavior CO' */
  real_T BehaviorCO_o6[2];             /* '<Root>/Behavior CO' */
  real_T BehaviorCO_o7[4];             /* '<Root>/Behavior CO' */
  real_T BehaviorCO_o8[2];             /* '<Root>/Behavior CO' */
  real_T Switch2[2];                   /* '<S4>/Switch2' */
  real_T MG1;                          /* '<S4>/MG1' */
  real_T MG2;                          /* '<S4>/MG2' */
  real_T Clock_a;                      /* '<S65>/Clock' */
  real_T HiddenBuf_InsertedFor_Sampleand;/* 'synthesized block' */
  real_T Sum_c;                        /* '<S65>/Sum' */
  real_T UniformRandomNumber;          /* '<S6>/Uniform Random Number' */
  real_T Switch_m;                     /* '<S6>/Switch' */
  real_T HiddenBuf_InsertedFor_Samplea_i;/* 'synthesized block' */
  real_T DataTypeConversion;           /* '<S6>/Data Type Conversion' */
  real_T y;                            /* '<S17>/y' */
  real_T Add1;                         /* '<S17>/Add1' */
  real_T z;                            /* '<S17>/z' */
  real_T Add3;                         /* '<S17>/Add3' */
  real_T product2;                     /* '<S17>/product2' */
  real_T Add2;                         /* '<S17>/Add2' */
  real_T product3;                     /* '<S17>/product3' */
  real_T product4;                     /* '<S17>/product4' */
  real_T Add4;                         /* '<S17>/Add4' */
  real_T product1;                     /* '<S17>/product1' */
  real_T dX;                           /* '<S17>/dX' */
  real_T AddX;                         /* '<S17>/AddX' */
  real_T dY;                           /* '<S17>/dY' */
  real_T AddX1;                        /* '<S17>/AddX1' */
  real_T dZ;                           /* '<S17>/dZ' */
  real_T AddX2;                        /* '<S17>/AddX2' */
  real_T y_l;                          /* '<S18>/y' */
  real_T Add1_m;                       /* '<S18>/Add1' */
  real_T z_h;                          /* '<S18>/z' */
  real_T Add3_i;                       /* '<S18>/Add3' */
  real_T product2_b;                   /* '<S18>/product2' */
  real_T Add2_i;                       /* '<S18>/Add2' */
  real_T product3_b;                   /* '<S18>/product3' */
  real_T product4_e;                   /* '<S18>/product4' */
  real_T Add4_a;                       /* '<S18>/Add4' */
  real_T product1_j;                   /* '<S18>/product1' */
  real_T dX_o;                         /* '<S18>/dX' */
  real_T AddX_m;                       /* '<S18>/AddX' */
  real_T dY_e;                         /* '<S18>/dY' */
  real_T AddX1_g;                      /* '<S18>/AddX1' */
  real_T dZ_j;                         /* '<S18>/dZ' */
  real_T AddX2_n;                      /* '<S18>/AddX2' */
  real_T y_m;                          /* '<S19>/y' */
  real_T Add1_d;                       /* '<S19>/Add1' */
  real_T z_a;                          /* '<S19>/z' */
  real_T Add3_p;                       /* '<S19>/Add3' */
  real_T product2_k;                   /* '<S19>/product2' */
  real_T Add2_e;                       /* '<S19>/Add2' */
  real_T product3_i;                   /* '<S19>/product3' */
  real_T product4_a;                   /* '<S19>/product4' */
  real_T Add4_h;                       /* '<S19>/Add4' */
  real_T product1_a;                   /* '<S19>/product1' */
  real_T dX_j;                         /* '<S19>/dX' */
  real_T AddX_l;                       /* '<S19>/AddX' */
  real_T dY_eo;                        /* '<S19>/dY' */
  real_T AddX1_a;                      /* '<S19>/AddX1' */
  real_T dZ_b;                         /* '<S19>/dZ' */
  real_T AddX2_a;                      /* '<S19>/AddX2' */
  real_T y_d;                          /* '<S20>/y' */
  real_T Add1_n;                       /* '<S20>/Add1' */
  real_T z_l;                          /* '<S20>/z' */
  real_T Add3_k;                       /* '<S20>/Add3' */
  real_T product2_g;                   /* '<S20>/product2' */
  real_T Add2_d;                       /* '<S20>/Add2' */
  real_T product3_j;                   /* '<S20>/product3' */
  real_T product4_j;                   /* '<S20>/product4' */
  real_T Add4_f;                       /* '<S20>/Add4' */
  real_T product1_p;                   /* '<S20>/product1' */
  real_T dX_l;                         /* '<S20>/dX' */
  real_T AddX_d;                       /* '<S20>/AddX' */
  real_T dY_b;                         /* '<S20>/dY' */
  real_T AddX1_d;                      /* '<S20>/AddX1' */
  real_T dZ_m;                         /* '<S20>/dZ' */
  real_T AddX2_l;                      /* '<S20>/AddX2' */
  real_T y_j;                          /* '<S23>/y' */
  real_T Add1_nw;                      /* '<S23>/Add1' */
  real_T z_f;                          /* '<S23>/z' */
  real_T Add3_k3;                      /* '<S23>/Add3' */
  real_T product2_h;                   /* '<S23>/product2' */
  real_T Add2_p;                       /* '<S23>/Add2' */
  real_T product3_m;                   /* '<S23>/product3' */
  real_T product4_b;                   /* '<S23>/product4' */
  real_T Add4_l;                       /* '<S23>/Add4' */
  real_T product1_m;                   /* '<S23>/product1' */
  real_T dX_g;                         /* '<S23>/dX' */
  real_T AddX_k;                       /* '<S23>/AddX' */
  real_T dY_i;                         /* '<S23>/dY' */
  real_T AddX1_e;                      /* '<S23>/AddX1' */
  real_T dZ_i;                         /* '<S23>/dZ' */
  real_T AddX2_c;                      /* '<S23>/AddX2' */
  real_T y_e;                          /* '<S24>/y' */
  real_T Add1_b;                       /* '<S24>/Add1' */
  real_T z_o;                          /* '<S24>/z' */
  real_T Add3_pw;                      /* '<S24>/Add3' */
  real_T product2_ka;                  /* '<S24>/product2' */
  real_T Add2_db;                      /* '<S24>/Add2' */
  real_T product3_l;                   /* '<S24>/product3' */
  real_T product4_n;                   /* '<S24>/product4' */
  real_T Add4_c;                       /* '<S24>/Add4' */
  real_T product1_d;                   /* '<S24>/product1' */
  real_T dX_e;                         /* '<S24>/dX' */
  real_T AddX_ko;                      /* '<S24>/AddX' */
  real_T dY_bm;                        /* '<S24>/dY' */
  real_T AddX1_b;                      /* '<S24>/AddX1' */
  real_T dZ_o;                         /* '<S24>/dZ' */
  real_T AddX2_f;                      /* '<S24>/AddX2' */
  real_T y_e3;                         /* '<S25>/y' */
  real_T Add1_j;                       /* '<S25>/Add1' */
  real_T z_b;                          /* '<S25>/z' */
  real_T Add3_l;                       /* '<S25>/Add3' */
  real_T product2_o;                   /* '<S25>/product2' */
  real_T Add2_a;                       /* '<S25>/Add2' */
  real_T product3_a;                   /* '<S25>/product3' */
  real_T product4_n1;                  /* '<S25>/product4' */
  real_T Add4_n;                       /* '<S25>/Add4' */
  real_T product1_d2;                  /* '<S25>/product1' */
  real_T dX_b;                         /* '<S25>/dX' */
  real_T AddX_lw;                      /* '<S25>/AddX' */
  real_T dY_k;                         /* '<S25>/dY' */
  real_T AddX1_aj;                     /* '<S25>/AddX1' */
  real_T dZ_f;                         /* '<S25>/dZ' */
  real_T AddX2_k;                      /* '<S25>/AddX2' */
  real_T y_n;                          /* '<S26>/y' */
  real_T Add1_e;                       /* '<S26>/Add1' */
  real_T z_bj;                         /* '<S26>/z' */
  real_T Add3_e;                       /* '<S26>/Add3' */
  real_T product2_i;                   /* '<S26>/product2' */
  real_T Add2_as;                      /* '<S26>/Add2' */
  real_T product3_be;                  /* '<S26>/product3' */
  real_T product4_a1;                  /* '<S26>/product4' */
  real_T Add4_e;                       /* '<S26>/Add4' */
  real_T product1_d3;                  /* '<S26>/product1' */
  real_T dX_bv;                        /* '<S26>/dX' */
  real_T AddX_n;                       /* '<S26>/AddX' */
  real_T dY_f;                         /* '<S26>/dY' */
  real_T AddX1_h;                      /* '<S26>/AddX1' */
  real_T dZ_ms;                        /* '<S26>/dZ' */
  real_T AddX2_e;                      /* '<S26>/AddX2' */
  real_T MatrixConcatenation1[4];      /* '<Root>/Matrix Concatenation1' */
  real_T Add_p;                        /* '<S8>/Add' */
  real_T Add1_l;                       /* '<S8>/Add1' */
  real_T Gain_m;                       /* '<S8>/Gain' */
  real_T Gain1_h;                      /* '<S8>/Gain1' */
  real_T ForIterator;                  /* '<S70>/For Iterator' */
  real_T Switch_e;                     /* '<S70>/Switch' */
  real_T ToBits1_o1;                   /* '<S70>/ToBits1' */
  real_T ToBits1_o2;                   /* '<S70>/ToBits1' */
  real_T ToBits1_o3;                   /* '<S70>/ToBits1' */
  real_T ToBits1_o4;                   /* '<S70>/ToBits1' */
  real_T ToBits1_o5;                   /* '<S70>/ToBits1' */
  real_T ToBits1_o6;                   /* '<S70>/ToBits1' */
  real_T ToBits1_o7;                   /* '<S70>/ToBits1' */
  real_T ToBits1_o8;                   /* '<S70>/ToBits1' */
  real_T Add_m;                        /* '<S70>/Add' */
  real_T Add1_dz;                      /* '<S70>/Add1' */
  real_T SerialConverter;              /* '<S70>/SerialConverter' */
  real_T ToBits_o1;                    /* '<S70>/ToBits' */
  real_T ToBits_o2;                    /* '<S70>/ToBits' */
  real_T ToBits_o3;                    /* '<S70>/ToBits' */
  real_T ToBits_o4;                    /* '<S70>/ToBits' */
  real_T ToBits_o5;                    /* '<S70>/ToBits' */
  real_T ToBits_o6;                    /* '<S70>/ToBits' */
  real_T ToBits_o7;                    /* '<S70>/ToBits' */
  real_T ToBits_o8;                    /* '<S70>/ToBits' */
  real_T xPCTargetTime;                /* '<S70>/xPC Target  Time ' */
  real_T xPCTargetTime_d;              /* '<S72>/xPC Target  Time ' */
  real_T Subtract;                     /* '<S72>/Subtract' */
  real_T ScaleTouSec;                  /* '<S72>/ScaleTouSec' */
  real_T Switch_a;                     /* '<S72>/Switch' */
  real_T TachGain2;                    /* '<S10>/TachGain2' */
  real_T TachGain1;                    /* '<S10>/TachGain1' */
  real_T TmpHiddenBufferAtMatrixMultiply[2];/* 'synthesized block' */
  real_T MatrixMultiply[2];            /* '<S10>/Matrix Multiply' */
  real_T Gain_e[2];                    /* '<S29>/Gain' */
  real_T MathFunction[4];              /* '<S33>/Math Function' */
  real_T MatrixMultiply_k[2];          /* '<S29>/Matrix Multiply' */
  real_T Switch1[2];                   /* '<S4>/Switch1' */
  real_T Switch_o[2];                  /* '<S5>/Switch' */
  real_T BoundingBoxViscosity[2];      /* '<S5>/Bounding Box Viscosity' */
  real_T Product_a;                    /* '<S41>/Product' */
  real_T Gain1_i;                      /* '<S41>/Gain1' */
  real_T Gain3;                        /* '<S41>/Gain3' */
  real_T Add_gi;                       /* '<S41>/Add' */
  real_T Saturation;                   /* '<S41>/Saturation' */
  real_T Gain4;                        /* '<S41>/Gain4' */
  real_T Product1_k;                   /* '<S41>/Product1' */
  real_T Gain2;                        /* '<S41>/Gain2' */
  real_T Add1_a;                       /* '<S41>/Add1' */
  real_T Saturation1;                  /* '<S41>/Saturation1' */
  real_T Add1_k;                       /* '<S21>/Add1' */
  real_T LorentzForceGain[2];          /* '<S3>/LorentzForceGain' */
  real_T dynamicAngleSwitch;           /* '<S3>/dynamicAngle Switch' */
  real_T sin_o;                        /* '<S22>/sin' */
  real_T Inverter[2];                  /* '<S22>/Inverter' */
  real_T Product3_f;                   /* '<S22>/Product3' */
  real_T cos_l;                        /* '<S22>/cos' */
  real_T Product2_k;                   /* '<S22>/Product2' */
  real_T Subtract_k;                   /* '<S22>/Subtract' */
  real_T Product1_c;                   /* '<S22>/Product1' */
  real_T Product_h;                    /* '<S22>/Product' */
  real_T Add_h;                        /* '<S22>/Add' */
  real_T Gain_k[2];                    /* '<S22>/Gain' */
  real_T Gain_l;                       /* '<S3>/Gain' */
  real_T Add1_j2;                      /* '<S15>/Add1' */
  real_T LorentzForceGain_o[2];        /* '<S2>/LorentzForceGain' */
  real_T DynamicAngleSwitch;           /* '<S2>/DynamicAngle Switch' */
  real_T sin_f;                        /* '<S16>/sin' */
  real_T Inverter_f[2];                /* '<S16>/Inverter' */
  real_T Product3_b;                   /* '<S16>/Product3' */
  real_T cos_j;                        /* '<S16>/cos' */
  real_T Product2_p;                   /* '<S16>/Product2' */
  real_T Subtract_l;                   /* '<S16>/Subtract' */
  real_T Product1_i;                   /* '<S16>/Product1' */
  real_T Product_o;                    /* '<S16>/Product' */
  real_T Add_c;                        /* '<S16>/Add' */
  real_T Gain_lz[2];                   /* '<S16>/Gain' */
  real_T Gain_d;                       /* '<S2>/Gain' */
  uint8_T Compare;                     /* '<S34>/Compare' */
  uint8_T Compare_h;                   /* '<S36>/Compare' */
  uint8_T Compare_o;                   /* '<S37>/Compare' */
  uint8_T Compare_b;                   /* '<S60>/Compare' */
  uint8_T Compare_d;                   /* '<S63>/Compare' */
  uint8_T Uk1;                         /* '<S61>/Delay Input1' */
  uint8_T FixPtRelationalOperator;     /* '<S61>/FixPt Relational Operator' */
  uint8_T Compare_c;                   /* '<S53>/Compare' */
  uint8_T Compare_l;                   /* '<S51>/Compare' */
  uint8_T Compare_e;                   /* '<S52>/Compare' */
  uint8_T Compare_m;                   /* '<S59>/Compare' */
  uint8_T Uk1_f;                       /* '<S46>/Delay Input1' */
  uint8_T FixPtRelationalOperator_e;   /* '<S46>/FixPt Relational Operator' */
  uint8_T Compare_m2;                  /* '<S57>/Compare' */
  uint8_T Compare_g;                   /* '<S50>/Compare' */
  uint8_T Uk1_e;                       /* '<S39>/Delay Input1' */
  uint8_T FixPtRelationalOperator_i;   /* '<S39>/FixPt Relational Operator' */
  uint8_T Compare_mk;                  /* '<S55>/Compare' */
  uint8_T Compare_p;                   /* '<S49>/Compare' */
  uint8_T Uk1_o;                       /* '<S38>/Delay Input1' */
  uint8_T FixPtRelationalOperator_l;   /* '<S38>/FixPt Relational Operator' */
  uint8_T Compare_ci;                  /* '<S27>/Compare' */
  uint8_T Compare_hx;                  /* '<S28>/Compare' */
  uint8_T Pack[112];                   /* '<S9>/Pack' */
  uint8_T RateTransition[112];         /* '<S9>/Rate Transition' */
  boolean_T Memory;                    /* '<S31>/Memory' */
  boolean_T Memory_o;                  /* '<S4>/Memory' */
  boolean_T LogicalOperator2;          /* '<S31>/Logical Operator2' */
  boolean_T LogicalOperator1;          /* '<S31>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_EnabledSu;/* '<S31>/Logical Operator1' */
  boolean_T RelationalOperator;        /* '<S31>/Relational Operator' */
  boolean_T LogicalOperator;           /* '<S31>/Logical Operator' */
  boolean_T Memory_p;                  /* '<S43>/Memory' */
  boolean_T RelationalOperator_e;      /* '<S1>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S1>/Relational Operator1' */
  boolean_T RelationalOperator2;       /* '<S1>/Relational Operator2' */
  boolean_T RelationalOperator3;       /* '<S1>/Relational Operator3' */
  boolean_T LogicalOperator_j;         /* '<S1>/Logical Operator' */
  boolean_T InBox;                     /* '<S5>/InBox' */
  boolean_T LogicalOperator3;          /* '<S47>/Logical Operator3' */
  boolean_T Memory_pz;                 /* '<S47>/Memory' */
  boolean_T LogicalOperator4;          /* '<S47>/Logical Operator4' */
  boolean_T LogicalOperator_p;         /* '<S5>/Logical Operator' */
  boolean_T LogicalOperator2_n;        /* '<S47>/Logical Operator2' */
  boolean_T LogicalOperator1_m;        /* '<S47>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_c;/* '<S47>/Logical Operator1' */
  boolean_T RelationalOperator_i;      /* '<S47>/Relational Operator' */
  boolean_T LogicalOperator_l;         /* '<S47>/Logical Operator' */
  boolean_T LogicalOperator5;          /* '<S47>/Logical Operator5' */
  boolean_T LogicalOperator2_h;        /* '<S43>/Logical Operator2' */
  boolean_T LogicalOperator1_i;        /* '<S43>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_d;/* '<S43>/Logical Operator1' */
  boolean_T RelationalOperator_ec;     /* '<S43>/Relational Operator' */
  boolean_T LogicalOperator_pm;        /* '<S43>/Logical Operator' */
  boolean_T LogicalOperator1_a;        /* '<S40>/Logical Operator1' */
  boolean_T NOT;                       /* '<S5>/NOT' */
  boolean_T Memory_d;                  /* '<S45>/Memory' */
  boolean_T LogicalOperator2_f;        /* '<S45>/Logical Operator2' */
  boolean_T LogicalOperator1_b;        /* '<S45>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_g;/* '<S45>/Logical Operator1' */
  boolean_T RelationalOperator_a;      /* '<S45>/Relational Operator' */
  boolean_T LogicalOperator_o;         /* '<S45>/Logical Operator' */
  boolean_T DataTypeConversion2;       /* '<S5>/Data Type Conversion2' */
  boolean_T LogicalOperator1_j;        /* '<S5>/Logical Operator1' */
  boolean_T Memory_b;                  /* '<S44>/Memory' */
  boolean_T LogicalOperator2_g;        /* '<S44>/Logical Operator2' */
  boolean_T LogicalOperator1_be;       /* '<S44>/Logical Operator1' */
  boolean_T HiddenBuf_InsertedFor_Enabled_e;/* '<S44>/Logical Operator1' */
  boolean_T RelationalOperator_j;      /* '<S44>/Relational Operator' */
  boolean_T LogicalOperator_i;         /* '<S44>/Logical Operator' */
  boolean_T DataTypeConversion1;       /* '<S5>/Data Type Conversion1' */
  boolean_T Memory_be;                 /* '<S42>/Memory' */
  boolean_T Logic[2];                  /* '<S42>/Logic' */
  boolean_T LogicalOperator5_d;        /* '<S5>/Logical Operator5' */
  boolean_T LogicalOperator1_bt;       /* '<S4>/Logical Operator1' */
  boolean_T MatrixConcatenation[2];    /* '<S4>/Matrix Concatenation' */
  boolean_T RelationalOperator_o;      /* '<S6>/Relational Operator' */
  boolean_T RelationalOperator_h;      /* '<S65>/Relational Operator' */
  boolean_T Compare_i;                 /* '<S74>/Compare' */
  boolean_T Compare_hn;                /* '<S73>/Compare' */
  boolean_T LogicalOperator6;          /* '<S5>/Logical Operator6' */
  boolean_T LogicalOperator3_b;        /* '<S5>/Logical Operator3' */
  rtB_SampleandHold_center_out SampleandHold;/* '<S65>/Sample and Hold' */
  rtB_SampleandHold_center_out SampleandHold_e;/* '<S6>/Sample and Hold' */
  rtB_EnabledSubsystem_center_out EnabledSubsystem_l;/* '<S47>/Enabled Subsystem' */
  rtB_EnabledSubsystem_center_out EnabledSubsystem_n;/* '<S45>/Enabled Subsystem' */
  rtB_EnabledSubsystem_center_out EnabledSubsystem_ir;/* '<S44>/Enabled Subsystem' */
  rtB_EnabledSubsystem_center_out EnabledSubsystem_i;/* '<S43>/Enabled Subsystem' */
  rtB_EnabledSubsystem_center_out EnabledSubsystem;/* '<S31>/Enabled Subsystem' */
} BlockIO_center_out;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DigitalFilter2_FILT_STATES[11];/* '<S67>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES[11];/* '<S67>/Digital Filter' */
  real_T DigitalFilter2_FILT_STATES_h[11];/* '<S68>/Digital Filter2' */
  real_T DigitalFilter_FILT_STATES_g[11];/* '<S68>/Digital Filter' */
  real_T x_DSTATE;                     /* '<S23>/x' */
  real_T x_DSTATE_m;                   /* '<S24>/x' */
  real_T x_DSTATE_a;                   /* '<S25>/x' */
  real_T x_DSTATE_p;                   /* '<S26>/x' */
  real_T x_DSTATE_b;                   /* '<S17>/x' */
  real_T x_DSTATE_a5;                  /* '<S18>/x' */
  real_T x_DSTATE_h;                   /* '<S19>/x' */
  real_T x_DSTATE_b2;                  /* '<S20>/x' */
  real_T BehaviorCO_DSTATE;            /* '<Root>/Behavior CO' */
  real_T y_DSTATE;                     /* '<S17>/y' */
  real_T z_DSTATE;                     /* '<S17>/z' */
  real_T y_DSTATE_b;                   /* '<S18>/y' */
  real_T z_DSTATE_c;                   /* '<S18>/z' */
  real_T y_DSTATE_j;                   /* '<S19>/y' */
  real_T z_DSTATE_p;                   /* '<S19>/z' */
  real_T y_DSTATE_b1;                  /* '<S20>/y' */
  real_T z_DSTATE_o;                   /* '<S20>/z' */
  real_T y_DSTATE_d;                   /* '<S23>/y' */
  real_T z_DSTATE_f;                   /* '<S23>/z' */
  real_T y_DSTATE_e;                   /* '<S24>/y' */
  real_T z_DSTATE_d;                   /* '<S24>/z' */
  real_T y_DSTATE_f;                   /* '<S25>/y' */
  real_T z_DSTATE_d2;                  /* '<S25>/z' */
  real_T y_DSTATE_p;                   /* '<S26>/y' */
  real_T z_DSTATE_l;                   /* '<S26>/z' */
  real_T PCI6025EAD_RWORK[64];         /* '<S10>/PCI-6025E AD' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S67>/Derivative' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK_d;                /* '<S68>/Derivative' */

  real_T BehaviorCO_RWORK[5];          /* '<Root>/Behavior CO' */
  real_T PCI6025E_RWORK[6];            /* '<S4>/PCI-6025E ' */
  struct {
    real_T NextOutput;
  } UniformRandomNumber_RWORK;         /* '<S6>/Uniform Random Number' */

  void *Send_PWORK;                    /* '<S9>/Send' */
  int32_T DigitalFilter2_CIRCBUFFIDX;  /* '<S67>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX;   /* '<S67>/Digital Filter' */
  int32_T DigitalFilter2_CIRCBUFFIDX_l;/* '<S68>/Digital Filter2' */
  int32_T DigitalFilter_CIRCBUFFIDX_g; /* '<S68>/Digital Filter' */
  int_T PCIQUAD04_IWORK;               /* '<S13>/PCI-QUAD04 ' */
  int_T PCIQUAD041_IWORK;              /* '<S13>/PCI-QUAD04 1' */
  int_T PCI6025EAD_IWORK[66];          /* '<S10>/PCI-6025E AD' */
  int_T BehaviorCO_IWORK[585];         /* '<Root>/Behavior CO' */
  int_T PCI6025E_IWORK[2];             /* '<S4>/PCI-6025E ' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S30>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_f;                 /* '<S32>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_b;                 /* '<S7>/S-Function' */

  int_T Send_IWORK[2];                 /* '<S9>/Send' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK_d;                 /* '<S11>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_p;                 /* '<S14>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_a;                 /* '<S48>/S-Function' */

  struct {
    int_T RandSeed;
  } UniformRandomNumber_IWORK;         /* '<S6>/Uniform Random Number' */

  int_T PortA_IWORK[2];                /* '<S70>/Port A' */
  int_T PortB_IWORK[2];                /* '<S70>/Port B' */
  int_T PCI6025E_IWORK_d[3];           /* '<S72>/PCI-6025E ' */
  uint8_T DelayInput1_DSTATE;          /* '<S61>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_o;        /* '<S46>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_g;        /* '<S39>/Delay Input1' */
  uint8_T DelayInput1_DSTATE_m;        /* '<S38>/Delay Input1' */
  boolean_T Memory_PreviousInput;      /* '<S31>/Memory' */
  boolean_T Memory_PreviousInput_e;    /* '<S4>/Memory' */
  boolean_T Memory_PreviousInput_i;    /* '<S43>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<S47>/Memory' */
  boolean_T Memory_PreviousInput_j;    /* '<S45>/Memory' */
  boolean_T Memory_PreviousInput_o;    /* '<S44>/Memory' */
  boolean_T Memory_PreviousInput_b;    /* '<S42>/Memory' */
  rtDW_SampleandHold_center_out SampleandHold;/* '<S65>/Sample and Hold' */
  rtDW_SampleandHold_center_out SampleandHold_e;/* '<S6>/Sample and Hold' */
  rtDW_EnabledSubsystem_center_ou EnabledSubsystem_l;/* '<S47>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_center_ou EnabledSubsystem_n;/* '<S45>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_center_ou EnabledSubsystem_ir;/* '<S44>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_center_ou EnabledSubsystem_i;/* '<S43>/Enabled Subsystem' */
  rtDW_EnabledSubsystem_center_ou EnabledSubsystem;/* '<S31>/Enabled Subsystem' */
} D_Work_center_out;

/* Zero-crossing (trigger) state */
typedef struct {
  rtZCE_SampleandHold_center_out SampleandHold;/* '<S6>/Sample and Hold' */
  rtZCE_SampleandHold_center_out SampleandHold_e;/* '<S6>/Sample and Hold' */
} PrevZCSigStates_center_out;

/* Backward compatible GRT Identifiers */
#define rtB                            center_out_B
#define BlockIO                        BlockIO_center_out
#define rtXdot                         center_out_Xdot
#define StateDerivatives               StateDerivatives_center_out
#define tXdis                          center_out_Xdis
#define StateDisabled                  StateDisabled_center_out
#define rtP                            center_out_P
#define Parameters                     Parameters_center_out
#define rtDWork                        center_out_DWork
#define D_Work                         D_Work_center_out
#define rtPrevZCSigState               center_out_PrevZCSigState
#define PrevZCSigStates                PrevZCSigStates_center_out

/* Parameters for system: '<S6>/Sample and Hold' */
struct rtP_SampleandHold_center_out {
  real_T _Y0;                          /* Expression: initCond
                                        * 'synthesized block'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_center_out {
  real_T Time_Value;                   /* Expression: Time
                                        * '<S31>/Time'
                                        */
  real_T PCIQUAD04_P1_Size[2];         /* Computed Parameter: P1Size
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P1;                 /* Expression: convbaseaddr
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P2_Size[2];         /* Computed Parameter: P2Size
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P2;                 /* Expression: channel
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P3_Size[2];         /* Computed Parameter: P3Size
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P3;                 /* Expression: resetmode
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P4_Size[2];         /* Computed Parameter: P4Size
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P4;                 /* Expression: polarity
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P5_Size[2];         /* Computed Parameter: P5Size
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P5;                 /* Expression: mode
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P6_Size[2];         /* Computed Parameter: P6Size
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P6;                 /* Expression: limit
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P7_Size[2];         /* Computed Parameter: P7Size
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P7;                 /* Expression: range
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P8_Size[2];         /* Computed Parameter: P8Size
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P8;                 /* Expression: speed
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P9_Size[2];         /* Computed Parameter: P9Size
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P9;                 /* Expression: prescale
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P10_Size[2];        /* Computed Parameter: P10Size
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P10;                /* Expression: ts
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P11_Size[2];        /* Computed Parameter: P11Size
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T PCIQUAD04_P11;                /* Expression: boardtype
                                        * '<S13>/PCI-QUAD04 '
                                        */
  real_T Gain_Gain;                    /* Expression: 3.490658e-4
                                        * '<S13>/Gain'
                                        */
  real_T shoulderOffset_Value;         /* Expression: 0
                                        * '<S13>/shoulderOffset'
                                        */
  real_T L1_Value;                     /* Expression: 24
                                        * '<S71>/L1'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * '<S71>/Gain'
                                        */
  real_T PCIQUAD041_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P1;                /* Expression: convbaseaddr
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P2;                /* Expression: channel
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P3;                /* Expression: resetmode
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P4;                /* Expression: polarity
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P5;                /* Expression: mode
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P6;                /* Expression: limit
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P7_Size[2];        /* Computed Parameter: P7Size
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P7;                /* Expression: range
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P8_Size[2];        /* Computed Parameter: P8Size
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P8;                /* Expression: speed
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P9_Size[2];        /* Computed Parameter: P9Size
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P9;                /* Expression: prescale
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P10_Size[2];       /* Computed Parameter: P10Size
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P10;               /* Expression: ts
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P11_Size[2];       /* Computed Parameter: P11Size
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T PCIQUAD041_P11;               /* Expression: boardtype
                                        * '<S13>/PCI-QUAD04 1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -3.490658e-4
                                        * '<S13>/Gain1'
                                        */
  real_T elbowOffset_Value;            /* Expression: 0
                                        * '<S13>/elbowOffset'
                                        */
  real_T L2_Value;                     /* Expression: 23.5
                                        * '<S71>/L2'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: -1
                                        * '<S71>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * '<S71>/Gain2'
                                        */
  real_T PCI6025EAD_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P1[2];             /* Expression: channel
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P2[2];             /* Expression: range
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P3[2];             /* Expression: coupling
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P4;                /* Expression: sampletime
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P5;                /* Expression: slot
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T PCI6025EAD_P6;                /* Expression: boardType
                                        * '<S10>/PCI-6025E AD'
                                        */
  real_T UseTachs_Value;               /* Expression: 1
                                        * '<S10>/UseTachs'
                                        */
  real_T yoffset_Value;                /* Expression: 37
                                        * '<S71>/yoffset'
                                        */
  real_T xoffset_Value;                /* Expression: -2
                                        * '<S71>/xoffset'
                                        */
  real_T AngleOffset_Value;            /* Expression: 0
                                        * '<S69>/AngleOffset'
                                        */
  real_T DigitalFilter2_ICRTP;         /* Expression: a.IC
                                        * '<S67>/Digital Filter2'
                                        */
  real_T DigitalFilter2_RTP1COEFF[11]; /* Expression: NumCoeffs
                                        * '<S67>/Digital Filter2'
                                        */
  real_T dG_Gain;                      /* Expression: 1
                                        * '<S67>/dG'
                                        */
  real_T DigitalFilter_ICRTP;          /* Expression: a.IC
                                        * '<S67>/Digital Filter'
                                        */
  real_T DigitalFilter_RTP1COEFF[11];  /* Expression: NumCoeffs
                                        * '<S67>/Digital Filter'
                                        */
  real_T DigitalFilter2_ICRTP_i;       /* Expression: a.IC
                                        * '<S68>/Digital Filter2'
                                        */
  real_T DigitalFilter2_RTP1COEFF_n[11];/* Expression: NumCoeffs
                                         * '<S68>/Digital Filter2'
                                         */
  real_T dG_Gain_a;                    /* Expression: 1
                                        * '<S68>/dG'
                                        */
  real_T DigitalFilter_ICRTP_h;        /* Expression: a.IC
                                        * '<S68>/Digital Filter'
                                        */
  real_T DigitalFilter_RTP1COEFF_n[11];/* Expression: NumCoeffs
                                        * '<S68>/Digital Filter'
                                        */
  real_T Switch_Threshold;             /* Expression: .5
                                        * '<S10>/Switch'
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
  real_T Time_Value_h;                 /* Expression: Time
                                        * '<S47>/Time'
                                        */
  real_T Time_Value_hl;                /* Expression: Time
                                        * '<S43>/Time'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * '<S51>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: const
                                        * '<S52>/Constant'
                                        */
  real_T Time_Value_l;                 /* Expression: Time
                                        * '<S45>/Time'
                                        */
  real_T Time_Value_d;                 /* Expression: Time
                                        * '<S44>/Time'
                                        */
  real_T Load_Value;                   /* Expression: 0
                                        * '<S3>/Load'
                                        */
  real_T x_X0;                         /* Expression: .1
                                        * '<S23>/x'
                                        */
  real_T x_X0_h;                       /* Expression: .1
                                        * '<S24>/x'
                                        */
  real_T x_X0_p;                       /* Expression: .1
                                        * '<S25>/x'
                                        */
  real_T x_X0_b;                       /* Expression: .1
                                        * '<S26>/x'
                                        */
  real_T Load_Value_m;                 /* Expression: 0
                                        * '<S2>/Load'
                                        */
  real_T x_X0_j;                       /* Expression: .1
                                        * '<S17>/x'
                                        */
  real_T x_X0_jq;                      /* Expression: .1
                                        * '<S18>/x'
                                        */
  real_T x_X0_g;                       /* Expression: .1
                                        * '<S19>/x'
                                        */
  real_T x_X0_pl;                      /* Expression: .1
                                        * '<S20>/x'
                                        */
  real_T BehaviorCO_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P1;                /* Expression: 8
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P2;                /* Expression: 10
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P3;                /* Expression: 2.5
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P4;                /* Expression: 1
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P5;                /* Expression: 1
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P6;                /* Expression: .5
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P7_Size[2];        /* Computed Parameter: P7Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P7;                /* Expression: 1.5
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P8_Size[2];        /* Computed Parameter: P8Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P8;                /* Expression: .75
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P9_Size[2];        /* Computed Parameter: P9Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P9;                /* Expression: .25
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P10_Size[2];       /* Computed Parameter: P10Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P10;               /* Expression: 1
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P11_Size[2];       /* Computed Parameter: P11Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P11;               /* Expression: 1
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P12_Size[2];       /* Computed Parameter: P12Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P12;               /* Expression: 10
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P13_Size[2];       /* Computed Parameter: P13Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P13;               /* Expression: 1
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P14_Size[2];       /* Computed Parameter: P14Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P14;               /* Expression: .02
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P15_Size[2];       /* Computed Parameter: P15Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P15;               /* Expression: 125
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P16_Size[2];       /* Computed Parameter: P16Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P16;               /* Expression: 1
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P17_Size[2];       /* Computed Parameter: P17Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P17;               /* Expression: 0
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P18_Size[2];       /* Computed Parameter: P18Size
                                        * '<Root>/Behavior CO'
                                        */
  real_T BehaviorCO_P18;               /* Expression: 0
                                        * '<Root>/Behavior CO'
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
  real_T Constant_Value_h;             /* Expression: const
                                        * '<S27>/Constant'
                                        */
  real_T Constant_Value_k;             /* Expression: const
                                        * '<S28>/Constant'
                                        */
  real_T Send_P1_Size[2];              /* Computed Parameter: P1Size
                                        * '<S9>/Send'
                                        */
  real_T Send_P1[11];                  /* Computed Parameter: P1
                                        * '<S9>/Send'
                                        */
  real_T Send_P2_Size[2];              /* Computed Parameter: P2Size
                                        * '<S9>/Send'
                                        */
  real_T Send_P2;                      /* Expression: ipPort
                                        * '<S9>/Send'
                                        */
  real_T Send_P3_Size[2];              /* Computed Parameter: P3Size
                                        * '<S9>/Send'
                                        */
  real_T Send_P3;                      /* Expression: localPort
                                        * '<S9>/Send'
                                        */
  real_T Send_P4_Size[2];              /* Computed Parameter: P4Size
                                        * '<S9>/Send'
                                        */
  real_T Send_P4;                      /* Expression: sampletime
                                        * '<S9>/Send'
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
                                        * '<S17>/y'
                                        */
  real_T rho_Value;                    /* Expression: 28
                                        * '<S17>/rho'
                                        */
  real_T z_X0;                         /* Expression: .1
                                        * '<S17>/z'
                                        */
  real_T beta_Value;                   /* Expression: 8/3
                                        * '<S17>/beta'
                                        */
  real_T timescale_Value;              /* Expression: .0001
                                        * '<S17>/timescale'
                                        */
  real_T sigma_Value;                  /* Expression: 10
                                        * '<S17>/sigma'
                                        */
  real_T y_X0_i;                       /* Expression: y0
                                        * '<S18>/y'
                                        */
  real_T rho_Value_d;                  /* Expression: 28
                                        * '<S18>/rho'
                                        */
  real_T z_X0_c;                       /* Expression: .1
                                        * '<S18>/z'
                                        */
  real_T beta_Value_e;                 /* Expression: 8/3
                                        * '<S18>/beta'
                                        */
  real_T timescale_Value_m;            /* Expression: .0001
                                        * '<S18>/timescale'
                                        */
  real_T sigma_Value_k;                /* Expression: 10
                                        * '<S18>/sigma'
                                        */
  real_T y_X0_p;                       /* Expression: y0
                                        * '<S19>/y'
                                        */
  real_T rho_Value_n;                  /* Expression: 28
                                        * '<S19>/rho'
                                        */
  real_T z_X0_j;                       /* Expression: .1
                                        * '<S19>/z'
                                        */
  real_T beta_Value_m;                 /* Expression: 8/3
                                        * '<S19>/beta'
                                        */
  real_T timescale_Value_a;            /* Expression: .0001
                                        * '<S19>/timescale'
                                        */
  real_T sigma_Value_e;                /* Expression: 10
                                        * '<S19>/sigma'
                                        */
  real_T y_X0_n;                       /* Expression: y0
                                        * '<S20>/y'
                                        */
  real_T rho_Value_d2;                 /* Expression: 28
                                        * '<S20>/rho'
                                        */
  real_T z_X0_f;                       /* Expression: .1
                                        * '<S20>/z'
                                        */
  real_T beta_Value_i;                 /* Expression: 8/3
                                        * '<S20>/beta'
                                        */
  real_T timescale_Value_l;            /* Expression: .0001
                                        * '<S20>/timescale'
                                        */
  real_T sigma_Value_p;                /* Expression: 10
                                        * '<S20>/sigma'
                                        */
  real_T y_X0_f;                       /* Expression: y0
                                        * '<S23>/y'
                                        */
  real_T rho_Value_p;                  /* Expression: 28
                                        * '<S23>/rho'
                                        */
  real_T z_X0_a;                       /* Expression: .1
                                        * '<S23>/z'
                                        */
  real_T beta_Value_ez;                /* Expression: 8/3
                                        * '<S23>/beta'
                                        */
  real_T timescale_Value_lp;           /* Expression: .0001
                                        * '<S23>/timescale'
                                        */
  real_T sigma_Value_c;                /* Expression: 10
                                        * '<S23>/sigma'
                                        */
  real_T y_X0_j;                       /* Expression: y0
                                        * '<S24>/y'
                                        */
  real_T rho_Value_f;                  /* Expression: 28
                                        * '<S24>/rho'
                                        */
  real_T z_X0_b;                       /* Expression: .1
                                        * '<S24>/z'
                                        */
  real_T beta_Value_mt;                /* Expression: 8/3
                                        * '<S24>/beta'
                                        */
  real_T timescale_Value_c;            /* Expression: .0001
                                        * '<S24>/timescale'
                                        */
  real_T sigma_Value_h;                /* Expression: 10
                                        * '<S24>/sigma'
                                        */
  real_T y_X0_o;                       /* Expression: y0
                                        * '<S25>/y'
                                        */
  real_T rho_Value_g;                  /* Expression: 28
                                        * '<S25>/rho'
                                        */
  real_T z_X0_e;                       /* Expression: .1
                                        * '<S25>/z'
                                        */
  real_T beta_Value_b;                 /* Expression: 8/3
                                        * '<S25>/beta'
                                        */
  real_T timescale_Value_k;            /* Expression: .0001
                                        * '<S25>/timescale'
                                        */
  real_T sigma_Value_m;                /* Expression: 10
                                        * '<S25>/sigma'
                                        */
  real_T y_X0_d;                       /* Expression: y0
                                        * '<S26>/y'
                                        */
  real_T rho_Value_j;                  /* Expression: 28
                                        * '<S26>/rho'
                                        */
  real_T z_X0_d;                       /* Expression: .1
                                        * '<S26>/z'
                                        */
  real_T beta_Value_a;                 /* Expression: 8/3
                                        * '<S26>/beta'
                                        */
  real_T timescale_Value_i;            /* Expression: .0001
                                        * '<S26>/timescale'
                                        */
  real_T sigma_Value_hn;               /* Expression: 10
                                        * '<S26>/sigma'
                                        */
  real_T Gain_Gain_l;                  /* Expression: .5
                                        * '<S8>/Gain'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: .5
                                        * '<S8>/Gain1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 0.0367
                                        * '<S2>/Gain'
                                        */
  real_T visAngle_Value;               /* Expression: 0
                                        * '<S2>/visAngle'
                                        */
  real_T DynamicAngle_Value;           /* Expression: 0
                                        * '<S2>/DynamicAngle'
                                        */
  real_T Inverter_Gain;                /* Expression: -1
                                        * '<S16>/Inverter'
                                        */
  real_T Gain_Gain_iu;                 /* Expression: 1
                                        * '<S16>/Gain'
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
  real_T Gain_Gain_g;                  /* Expression: 0.0367
                                        * '<S3>/Gain'
                                        */
  real_T visAngle_Value_g;             /* Expression: 0
                                        * '<S3>/visAngle'
                                        */
  real_T DynamicAngle_Value_k;         /* Expression: 0
                                        * '<S3>/DynamicAngle'
                                        */
  real_T Inverter_Gain_o;              /* Expression: -1
                                        * '<S22>/Inverter'
                                        */
  real_T Gain_Gain_lp;                 /* Expression: 1
                                        * '<S22>/Gain'
                                        */
  real_T LorentzForceGain_Gain_j;      /* Expression: .0005
                                        * '<S3>/LorentzForceGain'
                                        */
  real_T staticX_Value_c;              /* Expression: 0
                                        * '<S3>/staticX'
                                        */
  real_T staticY_Value_n;              /* Expression: 0
                                        * '<S3>/staticY'
                                        */
  real_T Off_Value_k;                  /* Expression: 0
                                        * '<S3>/Off'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: -.001
                                        * '<S41>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: -.0002
                                        * '<S41>/Gain3'
                                        */
  real_T Saturation_UpperSat;          /* Expression: .01
                                        * '<S41>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.01
                                        * '<S41>/Saturation'
                                        */
  real_T Gain4_Gain;                   /* Expression: -.0002
                                        * '<S41>/Gain4'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: -.001
                                        * '<S41>/Gain2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: .01
                                        * '<S41>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -0.01
                                        * '<S41>/Saturation1'
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
  real_T Gain_Gain_d;                  /* Expression: -1
                                        * '<S29>/Gain'
                                        */
  real_T RewardJackpot_Value;          /* Expression: 0.60
                                        * '<S6>/RewardJackpot'
                                        */
  real_T RewardTime_Value;             /* Expression: 0.30
                                        * '<S6>/RewardTime'
                                        */
  real_T TachGain2_Gain;               /* Expression: 1.29
                                        * '<S10>/TachGain2'
                                        */
  real_T TachGain1_Gain;               /* Expression: 1.29
                                        * '<S10>/TachGain1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * '<S70>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * '<S72>/Constant1'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * '<S72>/Constant'
                                        */
  real_T xPCTargetTime_P1_Size[2];     /* Computed Parameter: P1Size
                                        * '<S72>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1;             /* Expression: func
                                        * '<S72>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size[2];     /* Computed Parameter: P2Size
                                        * '<S72>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2;             /* Expression: ts
                                        * '<S72>/xPC Target  Time '
                                        */
  real_T ScaleTouSec_Gain;             /* Expression: .838
                                        * '<S72>/ScaleTouSec'
                                        */
  real_T Constant_Value_pu;            /* Expression: const
                                        * '<S74>/Constant'
                                        */
  real_T PCI6025E_P1_Size_g[2];        /* Computed Parameter: P1Size
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P1_l[2];             /* Expression: channel
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_Size_i[2];        /* Computed Parameter: P2Size
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_c[2];             /* Expression: reset
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_Size_b[2];        /* Computed Parameter: P3Size
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_i[2];             /* Expression: initValue
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_Size_p[2];        /* Computed Parameter: P4Size
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_c;                /* Expression: sampletime
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_Size_m[2];        /* Computed Parameter: P5Size
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_d;                /* Expression: slot
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_Size_g[2];        /* Computed Parameter: P6Size
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_m;                /* Expression: control
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_Size_l[2];        /* Computed Parameter: P7Size
                                        * '<S72>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_h;                /* Expression: boardType
                                        * '<S72>/PCI-6025E '
                                        */
  real_T Constant_Value_c;             /* Expression: const
                                        * '<S73>/Constant'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 2
                                        * '<S70>/Switch'
                                        */
  real_T PortA_P1_Size[2];             /* Computed Parameter: P1Size
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P1[8];                  /* Expression: channel
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P2_Size[2];             /* Computed Parameter: P2Size
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P2;                     /* Expression: port
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P3_Size[2];             /* Computed Parameter: P3Size
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P3[8];                  /* Expression: reset
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P4_Size[2];             /* Computed Parameter: P4Size
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P4[8];                  /* Expression: initValue
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P5_Size[2];             /* Computed Parameter: P5Size
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P5;                     /* Expression: chip
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P6_Size[2];             /* Computed Parameter: P6Size
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P6;                     /* Expression: sampletime
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P7_Size[2];             /* Computed Parameter: P7Size
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P7;                     /* Expression: slot
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P8_Size[2];             /* Computed Parameter: P8Size
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P8;                     /* Expression: control
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P9_Size[2];             /* Computed Parameter: P9Size
                                        * '<S70>/Port A'
                                        */
  real_T PortA_P9;                     /* Expression: boardType
                                        * '<S70>/Port A'
                                        */
  real_T Constant_Value_o;             /* Expression: 32768
                                        * '<S70>/Constant'
                                        */
  real_T PortB_P1_Size[2];             /* Computed Parameter: P1Size
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P1[8];                  /* Expression: channel
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P2_Size[2];             /* Computed Parameter: P2Size
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P2;                     /* Expression: port
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P3_Size[2];             /* Computed Parameter: P3Size
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P3[8];                  /* Expression: reset
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P4_Size[2];             /* Computed Parameter: P4Size
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P4[8];                  /* Expression: initValue
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P5_Size[2];             /* Computed Parameter: P5Size
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P5;                     /* Expression: chip
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P6_Size[2];             /* Computed Parameter: P6Size
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P6;                     /* Expression: sampletime
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P7_Size[2];             /* Computed Parameter: P7Size
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P7;                     /* Expression: slot
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P8_Size[2];             /* Computed Parameter: P8Size
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P8;                     /* Expression: control
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P9_Size[2];             /* Computed Parameter: P9Size
                                        * '<S70>/Port B'
                                        */
  real_T PortB_P9;                     /* Expression: boardType
                                        * '<S70>/Port B'
                                        */
  real_T xPCTargetTime_P1_Size_i[2];   /* Computed Parameter: P1Size
                                        * '<S70>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1_f;           /* Expression: func
                                        * '<S70>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size_a[2];   /* Computed Parameter: P2Size
                                        * '<S70>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_h;           /* Expression: ts
                                        * '<S70>/xPC Target  Time '
                                        */
  uint8_T DelayInput1_X0;              /* Computed Parameter: X0
                                        * '<S61>/Delay Input1'
                                        */
  uint8_T DelayInput1_X0_i;            /* Computed Parameter: X0
                                        * '<S46>/Delay Input1'
                                        */
  uint8_T DelayInput1_X0_e;            /* Computed Parameter: X0
                                        * '<S39>/Delay Input1'
                                        */
  uint8_T DelayInput1_X0_g;            /* Computed Parameter: X0
                                        * '<S38>/Delay Input1'
                                        */
  boolean_T Memory_X0;                 /* Computed Parameter: X0
                                        * '<S31>/Memory'
                                        */
  boolean_T Memory_X0_e;               /* Computed Parameter: X0
                                        * '<S4>/Memory'
                                        */
  boolean_T Memory_X0_ew;              /* Computed Parameter: X0
                                        * '<S43>/Memory'
                                        */
  boolean_T Memory_X0_i;               /* Computed Parameter: X0
                                        * '<S47>/Memory'
                                        */
  boolean_T Memory_X0_b;               /* Computed Parameter: X0
                                        * '<S45>/Memory'
                                        */
  boolean_T Memory_X0_l;               /* Computed Parameter: X0
                                        * '<S44>/Memory'
                                        */
  boolean_T Memory_X0_a;               /* Computed Parameter: X0
                                        * '<S42>/Memory'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: TruthTable
                                        * '<S42>/Logic'
                                        */
  rtP_SampleandHold_center_out SampleandHold;/* '<S6>/Sample and Hold' */
  rtP_SampleandHold_center_out SampleandHold_e;/* '<S6>/Sample and Hold' */
};

/* Real-time Model Data Structure */
struct rtModel_center_out {
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
      uint_T attribs[18];
      mxArray *params[18];
      struct _ssDWorkRecord dWork[3];
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
extern Parameters_center_out center_out_P;

/* Block signals (auto storage) */
extern BlockIO_center_out center_out_B;

/* Block states (auto storage) */
extern D_Work_center_out center_out_DWork;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_center_out center_out_PrevZCSigState;

/* Model entry point functions */
extern void center_out_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void center_out_initialize(boolean_T firstTime);
extern void center_out_output(int_T tid);
extern void center_out_update(int_T tid);
extern void center_out_terminate(void);

/* Real-time Model object */
extern rtModel_center_out *center_out_rtM;

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
 * '<Root>' : center_out
 * '<S1>'   : center_out/BoundingBox
 * '<S2>'   : center_out/Catch Force Generator
 * '<S3>'   : center_out/Force Generator
 * '<S4>'   : center_out/Motor Control
 * '<S5>'   : center_out/Recentering Subsystem
 * '<S6>'   : center_out/RewardSbs
 * '<S7>'   : center_out/Status
 * '<S8>'   : center_out/Target Peek
 * '<S9>'   : center_out/UDPXmit
 * '<S10>'  : center_out/Velocity Calculation
 * '<S11>'  : center_out/Version Display
 * '<S12>'  : center_out/WordSbs
 * '<S13>'  : center_out/XY Position Subsystem
 * '<S14>'  : center_out/Xpos
 * '<S15>'  : center_out/Catch Force Generator/LorentzForce
 * '<S16>'  : center_out/Catch Force Generator/ViscLoadSubsystem
 * '<S17>'  : center_out/Catch Force Generator/LorentzForce/Lorentz
 * '<S18>'  : center_out/Catch Force Generator/LorentzForce/Lorentz1
 * '<S19>'  : center_out/Catch Force Generator/LorentzForce/Lorentz2
 * '<S20>'  : center_out/Catch Force Generator/LorentzForce/Lorentz3
 * '<S21>'  : center_out/Force Generator/LorentzForce
 * '<S22>'  : center_out/Force Generator/ViscLoadSubsystem
 * '<S23>'  : center_out/Force Generator/LorentzForce/Lorentz
 * '<S24>'  : center_out/Force Generator/LorentzForce/Lorentz1
 * '<S25>'  : center_out/Force Generator/LorentzForce/Lorentz2
 * '<S26>'  : center_out/Force Generator/LorentzForce/Lorentz3
 * '<S27>'  : center_out/Motor Control/Compare To Constant
 * '<S28>'  : center_out/Motor Control/Compare To Constant1
 * '<S29>'  : center_out/Motor Control/Force//Torque Transform
 * '<S30>'  : center_out/Motor Control/Recenter//ServoKill
 * '<S31>'  : center_out/Motor Control/Schmidt
 * '<S32>'  : center_out/Motor Control/Xpos
 * '<S33>'  : center_out/Motor Control/Force//Torque Transform/Transpose
 * '<S34>'  : center_out/Motor Control/Schmidt/Compare To Zero
 * '<S35>'  : center_out/Motor Control/Schmidt/Enabled Subsystem
 * '<S36>'  : center_out/Recentering Subsystem/Compare To Zero
 * '<S37>'  : center_out/Recentering Subsystem/Compare To Zero1
 * '<S38>'  : center_out/Recentering Subsystem/Falling Edge
 * '<S39>'  : center_out/Recentering Subsystem/Falling Edge1
 * '<S40>'  : center_out/Recentering Subsystem/No Movement
 * '<S41>'  : center_out/Recentering Subsystem/PD Controller
 * '<S42>'  : center_out/Recentering Subsystem/S-R Flip-Flop
 * '<S43>'  : center_out/Recentering Subsystem/Schmidt1
 * '<S44>'  : center_out/Recentering Subsystem/Schmidt2
 * '<S45>'  : center_out/Recentering Subsystem/Schmidt3
 * '<S46>'  : center_out/Recentering Subsystem/Start Moving
 * '<S47>'  : center_out/Recentering Subsystem/Timer
 * '<S48>'  : center_out/Recentering Subsystem/Xpos1
 * '<S49>'  : center_out/Recentering Subsystem/Falling Edge/Nonpositive
 * '<S50>'  : center_out/Recentering Subsystem/Falling Edge1/Nonpositive
 * '<S51>'  : center_out/Recentering Subsystem/No Movement/Compare To Constant2
 * '<S52>'  : center_out/Recentering Subsystem/No Movement/Compare To Constant3
 * '<S53>'  : center_out/Recentering Subsystem/Schmidt1/Compare To Zero
 * '<S54>'  : center_out/Recentering Subsystem/Schmidt1/Enabled Subsystem
 * '<S55>'  : center_out/Recentering Subsystem/Schmidt2/Compare To Zero
 * '<S56>'  : center_out/Recentering Subsystem/Schmidt2/Enabled Subsystem
 * '<S57>'  : center_out/Recentering Subsystem/Schmidt3/Compare To Zero
 * '<S58>'  : center_out/Recentering Subsystem/Schmidt3/Enabled Subsystem
 * '<S59>'  : center_out/Recentering Subsystem/Start Moving/Nonpositive
 * '<S60>'  : center_out/Recentering Subsystem/Timer/Compare To Zero
 * '<S61>'  : center_out/Recentering Subsystem/Timer/Detect Fall Nonpositive
 * '<S62>'  : center_out/Recentering Subsystem/Timer/Enabled Subsystem
 * '<S63>'  : center_out/Recentering Subsystem/Timer/Detect Fall Nonpositive/Nonpositive
 * '<S64>'  : center_out/RewardSbs/Sample and Hold
 * '<S65>'  : center_out/RewardSbs/Schmidt
 * '<S66>'  : center_out/RewardSbs/Schmidt/Sample and Hold
 * '<S67>'  : center_out/Velocity Calculation/Pos2VelX
 * '<S68>'  : center_out/Velocity Calculation/Pos2VelY
 * '<S69>'  : center_out/XY Position Subsystem/Cursor Rotation
 * '<S70>'  : center_out/XY Position Subsystem/For Iterator Subsystem
 * '<S71>'  : center_out/XY Position Subsystem/Jacobian-Cartesian Transformation
 * '<S72>'  : center_out/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem
 * '<S73>'  : center_out/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant
 * '<S74>'  : center_out/XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1
 */
#endif                                 /* _RTW_HEADER_center_out_h_ */
