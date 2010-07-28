/*
 * wrist_flexion.h
 *
 * Real-Time Workshop code generation for Simulink model "wrist_flexion.mdl".
 *
 * Model Version              : 1.345
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 14:04:42 2010
 */
#ifndef _RTW_HEADER_wrist_flexion_h_
#define _RTW_HEADER_wrist_flexion_h_
#include "rtw_modelmap.h"
#ifndef _wrist_flexion_COMMON_INCLUDES_
# define _wrist_flexion_COMMON_INCLUDES_
#include <stddef.h>
#include <windows.h>
#include <xpcimports.h>
#include <math.h>
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
#endif                                 /* _wrist_flexion_COMMON_INCLUDES_ */

#include "wrist_flexion_types.h"

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
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
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
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
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
#define wrist_flexion_M                wrist_flexion_rtM

/* Definition for use in the target main file */
#define wrist_flexion_rtModel          rtModel_wrist_flexion

/* Block signals for system '<S4>/Sample and Hold' */
typedef struct {
  real_T In;                           /* '<S11>/In' */
} rtB_SampleandHold_wrist_flexion;

/* Block states (auto storage) for system '<S4>/Sample and Hold' */
typedef struct {
  int8_T SampleandHold_SubsysRanBC;    /* '<S4>/Sample and Hold' */
} rtDW_SampleandHold_wrist_flexio;

/* Zero-crossing (trigger) state for system '<S4>/Sample and Hold' */
typedef struct {
  ZCSigState SampleandHold_ZCE;        /* '<S4>/Sample and Hold' */
} rtZCE_SampleandHold_wrist_flexi;

/* Block signals (auto storage) */
typedef struct {
  real_T Integrator[2];                /* '<S2>/Integrator' */
  real_T LowPassFilterY;               /* '<S2>/LowPassFilterY' */
  real_T RawX;                         /* '<S2>/PCI-6025E ' */
  real_T RawY;                         /* '<S2>/PCI-6025E ' */
  real_T Receive_o2;                   /* '<S2>/Receive' */
  real_T Override;                     /* '<S10>/Override' */
  real_T Sum;                          /* '<S10>/Sum' */
  real_T Product[2];                   /* '<S10>/Product' */
  real_T Product1[2];                  /* '<S10>/Product1' */
  real_T Sum2;                         /* '<S10>/Sum2' */
  real_T Sum2_c;                       /* '<S2>/Sum2' */
  real_T GainY;                        /* '<S2>/GainY' */
  real_T Switch;                       /* '<S2>/Switch' */
  real_T LowPassFilterX;               /* '<S2>/LowPassFilterX' */
  real_T Sum1;                         /* '<S10>/Sum1' */
  real_T Sum1_n;                       /* '<S2>/Sum1' */
  real_T GainX;                        /* '<S2>/GainX' */
  real_T Switch1;                      /* '<S2>/Switch1' */
  real_T TrigonometricFunction1;       /* '<S9>/Trigonometric Function1' */
  real_T Rotation;                     /* '<Root>/Memory' */
  real_T Sum_a;                        /* '<S9>/Sum' */
  real_T TrigonometricFunction2;       /* '<S9>/Trigonometric Function2' */
  real_T sqrtu1u1u2u2;                 /* '<S9>/sqrt(u[1]*u[1] + u[2]*u[2])' */
  real_T Product1_a;                   /* '<S9>/Product1' */
  real_T TrigonometricFunction;        /* '<S9>/Trigonometric Function' */
  real_T Product_p;                    /* '<S9>/Product' */
  real_T Switch2[2];                   /* '<S2>/Switch2' */
  real_T WFTargetTable[96];            /* '<Root>/WFTargetTable' */
  real_T Reshape[96];                  /* '<Root>/Reshape' */
  real_T BehaviorWF_o1;                /* '<Root>/Behavior WF' */
  real_T BehaviorWF_o2;                /* '<Root>/Behavior WF' */
  real_T BehaviorWF_o3[4];             /* '<Root>/Behavior WF' */
  real_T BehaviorWF_o4[2];             /* '<Root>/Behavior WF' */
  real_T BehaviorWF_o5[10];            /* '<Root>/Behavior WF' */
  real_T BehaviorWF_o6[8];             /* '<Root>/Behavior WF' */
  real_T BehaviorWF_o7[4];             /* '<Root>/Behavior WF' */
  real_T BehaviorWF_o8;                /* '<Root>/Behavior WF' */
  real_T Clock;                        /* '<S12>/Clock' */
  real_T HiddenBuf_InsertedFor_Sampleand;/* 'synthesized block' */
  real_T Sum_m;                        /* '<S12>/Sum' */
  real_T UniformRandomNumber;          /* '<S4>/Uniform Random Number' */
  real_T Switch_i;                     /* '<S4>/Switch' */
  real_T HiddenBuf_InsertedFor_Samplea_b;/* 'synthesized block' */
  real_T DataTypeConversion;           /* '<S4>/Data Type Conversion' */
  real_T Rad2Deg;                      /* '<Root>/Rad2Deg' */
  real_T ForIterator;                  /* '<S8>/For Iterator' */
  real_T Switch_e;                     /* '<S8>/Switch' */
  real_T ToBits_o1;                    /* '<S8>/ToBits' */
  real_T ToBits_o2;                    /* '<S8>/ToBits' */
  real_T ToBits_o3;                    /* '<S8>/ToBits' */
  real_T ToBits_o4;                    /* '<S8>/ToBits' */
  real_T ToBits_o5;                    /* '<S8>/ToBits' */
  real_T ToBits_o6;                    /* '<S8>/ToBits' */
  real_T ToBits_o7;                    /* '<S8>/ToBits' */
  real_T ToBits_o8;                    /* '<S8>/ToBits' */
  real_T toThousandths[2];             /* '<S8>/toThousandths' */
  real_T Add2;                         /* '<S8>/Add2' */
  real_T Add3;                         /* '<S8>/Add3' */
  real_T SerialConverter;              /* '<S8>/SerialConverter' */
  real_T ToBits1_o1;                   /* '<S8>/ToBits1' */
  real_T ToBits1_o2;                   /* '<S8>/ToBits1' */
  real_T ToBits1_o3;                   /* '<S8>/ToBits1' */
  real_T ToBits1_o4;                   /* '<S8>/ToBits1' */
  real_T ToBits1_o5;                   /* '<S8>/ToBits1' */
  real_T ToBits1_o6;                   /* '<S8>/ToBits1' */
  real_T ToBits1_o7;                   /* '<S8>/ToBits1' */
  real_T ToBits1_o8;                   /* '<S8>/ToBits1' */
  real_T xPCTargetTime;                /* '<S8>/xPC Target  Time ' */
  real_T xPCTargetTime_a;              /* '<S14>/xPC Target  Time ' */
  real_T Subtract;                     /* '<S14>/Subtract' */
  real_T ScaleTouSec;                  /* '<S14>/ScaleTouSec' */
  real_T Switch_o;                     /* '<S14>/Switch' */
  real_T Saturation;                   /* '<S2>/Saturation' */
  real_T PctToFrac;                    /* '<S10>/PctToFrac' */
  real32_T Unpack[4];                  /* '<S2>/Unpack' */
  uint8_T Receive_o1[16];              /* '<S2>/Receive' */
  uint8_T Pack[112];                   /* '<S6>/Pack' */
  uint8_T RateTransition[112];         /* '<S6>/Rate Transition' */
  boolean_T RelationalOperator;        /* '<S4>/Relational Operator' */
  boolean_T RelationalOperator_f;      /* '<S12>/Relational Operator' */
  boolean_T Compare;                   /* '<S16>/Compare' */
  boolean_T Compare_h;                 /* '<S15>/Compare' */
  rtB_SampleandHold_wrist_flexion SampleandHold;/* '<S12>/Sample and Hold' */
  rtB_SampleandHold_wrist_flexion SampleandHold_k;/* '<S4>/Sample and Hold' */
} BlockIO_wrist_flexion;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T BehaviorWF_DSTATE;            /* '<Root>/Behavior WF' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  real_T PCI6025E_RWORK[64];           /* '<S2>/PCI-6025E ' */
  real_T BehaviorWF_RWORK[39];         /* '<Root>/Behavior WF' */
  struct {
    real_T NextOutput;
  } UniformRandomNumber_RWORK;         /* '<S4>/Uniform Random Number' */

  void *Receive_PWORK;                 /* '<S2>/Receive' */
  void *BehaviorWF_PWORK;              /* '<Root>/Behavior WF' */
  void *Send_PWORK;                    /* '<S6>/Send' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S1>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_p;                 /* '<S3>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_m;                 /* '<S5>/S-Function' */

  int_T PCI6025E_IWORK[66];            /* '<S2>/PCI-6025E ' */
  int_T Receive_IWORK[2];              /* '<S2>/Receive' */
  int_T BehaviorWF_IWORK[25];          /* '<Root>/Behavior WF' */
  int_T Send_IWORK[2];                 /* '<S6>/Send' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK_pn;                /* '<S7>/S-Function' */

  struct {
    int_T RandSeed;
  } UniformRandomNumber_IWORK;         /* '<S4>/Uniform Random Number' */

  int_T PortA_IWORK[2];                /* '<S8>/Port A' */
  int_T PortB_IWORK[2];                /* '<S8>/Port B' */
  int_T PCI6025E_IWORK_n[3];           /* '<S14>/PCI-6025E ' */
  rtDW_SampleandHold_wrist_flexio SampleandHold;/* '<S12>/Sample and Hold' */
  rtDW_SampleandHold_wrist_flexio SampleandHold_k;/* '<S4>/Sample and Hold' */
} D_Work_wrist_flexion;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[2];         /* '<S2>/Integrator' */
  real_T LowPassFilterY_CSTATE[8];     /* '<S2>/LowPassFilterY' */
  real_T LowPassFilterX_CSTATE[8];     /* '<S2>/LowPassFilterX' */
} ContinuousStates_wrist_flexion;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator_CSTATE[2];         /* '<S2>/Integrator' */
  real_T LowPassFilterY_CSTATE[8];     /* '<S2>/LowPassFilterY' */
  real_T LowPassFilterX_CSTATE[8];     /* '<S2>/LowPassFilterX' */
} StateDerivatives_wrist_flexion;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[2];      /* '<S2>/Integrator' */
  boolean_T LowPassFilterY_CSTATE[8];  /* '<S2>/LowPassFilterY' */
  boolean_T LowPassFilterX_CSTATE[8];  /* '<S2>/LowPassFilterX' */
} StateDisabled_wrist_flexion;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_ZCE;           /* '<S2>/Integrator' */
  rtZCE_SampleandHold_wrist_flexi SampleandHold;/* '<S4>/Sample and Hold' */
  rtZCE_SampleandHold_wrist_flexi SampleandHold_k;/* '<S4>/Sample and Hold' */
} PrevZCSigStates_wrist_flexion;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            wrist_flexion_B
#define BlockIO                        BlockIO_wrist_flexion
#define rtX                            wrist_flexion_X
#define ContinuousStates               ContinuousStates_wrist_flexion
#define rtP                            wrist_flexion_P
#define Parameters                     Parameters_wrist_flexion
#define rtDWork                        wrist_flexion_DWork
#define D_Work                         D_Work_wrist_flexion
#define rtPrevZCSigState               wrist_flexion_PrevZCSigState
#define PrevZCSigStates                PrevZCSigStates_wrist_flexion

/* Parameters for system: '<S4>/Sample and Hold' */
struct rtP_SampleandHold_wrist_flexion {
  real_T _Y0;                          /* Expression: initCond
                                        * 'synthesized block'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_wrist_flexion {
  real_T ResetIntegrator_Value;        /* Expression: 0
                                        * '<S2>/ResetIntegrator'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * '<S2>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 15
                                        * '<S2>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: -15
                                        * '<S2>/Integrator'
                                        */
  real_T EnableIntegrator_Value;       /* Expression: 0
                                        * '<S2>/EnableIntegrator'
                                        */
  real_T LowPassFilterY_A[15];         /* Computed Parameter: A
                                        * '<S2>/LowPassFilterY'
                                        */
  real_T LowPassFilterY_B;             /* Computed Parameter: B
                                        * '<S2>/LowPassFilterY'
                                        */
  real_T LowPassFilterY_C;             /* Computed Parameter: C
                                        * '<S2>/LowPassFilterY'
                                        */
  real_T LowPassFilterY_X0;            /* Expression: 0
                                        * '<S2>/LowPassFilterY'
                                        */
  real_T EnablePosFilter_Value;        /* Expression: 0
                                        * '<S2>/EnablePosFilter'
                                        */
  real_T PCI6025E_P1_Size[2];          /* Computed Parameter: P1Size
                                        * '<S2>/PCI-6025E '
                                        */
  real_T PCI6025E_P1[2];               /* Expression: channel
                                        * '<S2>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_Size[2];          /* Computed Parameter: P2Size
                                        * '<S2>/PCI-6025E '
                                        */
  real_T PCI6025E_P2[2];               /* Expression: range
                                        * '<S2>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_Size[2];          /* Computed Parameter: P3Size
                                        * '<S2>/PCI-6025E '
                                        */
  real_T PCI6025E_P3[2];               /* Expression: coupling
                                        * '<S2>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_Size[2];          /* Computed Parameter: P4Size
                                        * '<S2>/PCI-6025E '
                                        */
  real_T PCI6025E_P4;                  /* Expression: sampletime
                                        * '<S2>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_Size[2];          /* Computed Parameter: P5Size
                                        * '<S2>/PCI-6025E '
                                        */
  real_T PCI6025E_P5;                  /* Expression: slot
                                        * '<S2>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_Size[2];          /* Computed Parameter: P6Size
                                        * '<S2>/PCI-6025E '
                                        */
  real_T PCI6025E_P6;                  /* Expression: boardType
                                        * '<S2>/PCI-6025E '
                                        */
  real_T Receive_P1_Size[2];           /* Computed Parameter: P1Size
                                        * '<S2>/Receive'
                                        */
  real_T Receive_P1[7];                /* Computed Parameter: P1
                                        * '<S2>/Receive'
                                        */
  real_T Receive_P2_Size[2];           /* Computed Parameter: P2Size
                                        * '<S2>/Receive'
                                        */
  real_T Receive_P2;                   /* Expression: ipPort
                                        * '<S2>/Receive'
                                        */
  real_T Receive_P3_Size[2];           /* Computed Parameter: P3Size
                                        * '<S2>/Receive'
                                        */
  real_T Receive_P3;                   /* Expression: width
                                        * '<S2>/Receive'
                                        */
  real_T Receive_P4_Size[2];           /* Computed Parameter: P4Size
                                        * '<S2>/Receive'
                                        */
  real_T Receive_P4;                   /* Expression: sampletime
                                        * '<S2>/Receive'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * '<S10>/Constant1'
                                        */
  real_T OffsetY_Value;                /* Expression: 0
                                        * '<S2>/OffsetY'
                                        */
  real_T GainY_Gain;                   /* Expression: 15
                                        * '<S2>/GainY'
                                        */
  real_T LowPassFilterX_A[15];         /* Computed Parameter: A
                                        * '<S2>/LowPassFilterX'
                                        */
  real_T LowPassFilterX_B;             /* Computed Parameter: B
                                        * '<S2>/LowPassFilterX'
                                        */
  real_T LowPassFilterX_C;             /* Computed Parameter: C
                                        * '<S2>/LowPassFilterX'
                                        */
  real_T LowPassFilterX_X0;            /* Expression: 0
                                        * '<S2>/LowPassFilterX'
                                        */
  real_T OffsetX_Value;                /* Expression: 0
                                        * '<S2>/OffsetX'
                                        */
  real_T GainX_Gain;                   /* Expression: 15
                                        * '<S2>/GainX'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * '<Root>/Memory'
                                        */
  real_T WFTargetTable_table[96];      /* Expression: mxTable
                                        * '<Root>/WFTargetTable'
                                        */
  real_T BehaviorWF_P1_Size[2];        /* Computed Parameter: P1Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P1;                /* Expression: 8
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P2_Size[2];        /* Computed Parameter: P2Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P2;                /* Expression: 5
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P3_Size[2];        /* Computed Parameter: P3Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P3;                /* Expression: .5
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P4_Size[2];        /* Computed Parameter: P4Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P4;                /* Expression: .5
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P5_Size[2];        /* Computed Parameter: P5Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P5;                /* Expression: 1
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P6_Size[2];        /* Computed Parameter: P6Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P6;                /* Expression: 2
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P7_Size[2];        /* Computed Parameter: P7Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P7;                /* Expression: 2
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P8_Size[2];        /* Computed Parameter: P8Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P8;                /* Expression: 2
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P9_Size[2];        /* Computed Parameter: P9Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P9;                /* Expression: 2
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P10_Size[2];       /* Computed Parameter: P10Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P10;               /* Expression: 2
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P11_Size[2];       /* Computed Parameter: P11Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P11;               /* Expression: 0
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P12_Size[2];       /* Computed Parameter: P12Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P12;               /* Expression: 0
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P13_Size[2];       /* Computed Parameter: P13Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P13;               /* Expression: 0
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P14_Size[2];       /* Computed Parameter: P14Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P14;               /* Expression: 0
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P15_Size[2];       /* Computed Parameter: P15Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P15;               /* Expression: 0
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P16_Size[2];       /* Computed Parameter: P16Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P16;               /* Expression: 0
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P17_Size[2];       /* Computed Parameter: P17Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P17;               /* Expression: 0
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P18_Size[2];       /* Computed Parameter: P18Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P18;               /* Expression: 0.7854
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P19_Size[2];       /* Computed Parameter: P19Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P19;               /* Expression: 0
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P20_Size[2];       /* Computed Parameter: P20Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P20;               /* Expression: .5
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P21_Size[2];       /* Computed Parameter: P21Size
                                        * '<Root>/Behavior WF'
                                        */
  real_T BehaviorWF_P21;               /* Expression: 0
                                        * '<Root>/Behavior WF'
                                        */
  real_T Send_P1_Size[2];              /* Computed Parameter: P1Size
                                        * '<S6>/Send'
                                        */
  real_T Send_P1[11];                  /* Computed Parameter: P1
                                        * '<S6>/Send'
                                        */
  real_T Send_P2_Size[2];              /* Computed Parameter: P2Size
                                        * '<S6>/Send'
                                        */
  real_T Send_P2;                      /* Expression: ipPort
                                        * '<S6>/Send'
                                        */
  real_T Send_P3_Size[2];              /* Computed Parameter: P3Size
                                        * '<S6>/Send'
                                        */
  real_T Send_P3;                      /* Expression: localPort
                                        * '<S6>/Send'
                                        */
  real_T Send_P4_Size[2];              /* Computed Parameter: P4Size
                                        * '<S6>/Send'
                                        */
  real_T Send_P4;                      /* Expression: sampletime
                                        * '<S6>/Send'
                                        */
  real_T UniformRandomNumber_Min;      /* Expression: 0
                                        * '<S4>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Max;      /* Expression: 100
                                        * '<S4>/Uniform Random Number'
                                        */
  real_T UniformRandomNumber_Seed;     /* Expression: 0
                                        * '<S4>/Uniform Random Number'
                                        */
  real_T JackpotChance_Value;          /* Expression: 0
                                        * '<S4>/JackpotChance'
                                        */
  real_T Rad2Deg_Gain;                 /* Expression: 57.29578
                                        * '<Root>/Rad2Deg'
                                        */
  real_T NeuralControlPct_Value;       /* Expression: 0
                                        * '<S2>/NeuralControlPct'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * '<S2>/Saturation'
                                        */
  real_T PctToFrac_Gain;               /* Expression: 0.01
                                        * '<S10>/PctToFrac'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * '<S10>/Constant'
                                        */
  real_T RewardJackpot_Value;          /* Expression: 0.60
                                        * '<S4>/RewardJackpot'
                                        */
  real_T RewardTime_Value;             /* Expression: 0.30
                                        * '<S4>/RewardTime'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * '<S8>/Constant'
                                        */
  real_T StrobeLow_Value;              /* Expression: 0
                                        * '<S14>/StrobeLow'
                                        */
  real_T StobeHi_Value;                /* Expression: 1
                                        * '<S14>/StobeHi'
                                        */
  real_T xPCTargetTime_P1_Size[2];     /* Computed Parameter: P1Size
                                        * '<S14>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1;             /* Expression: func
                                        * '<S14>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size[2];     /* Computed Parameter: P2Size
                                        * '<S14>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2;             /* Expression: ts
                                        * '<S14>/xPC Target  Time '
                                        */
  real_T ScaleTouSec_Gain;             /* Expression: .838
                                        * '<S14>/ScaleTouSec'
                                        */
  real_T Constant_Value_h;             /* Expression: const
                                        * '<S16>/Constant'
                                        */
  real_T PCI6025E_P1_Size_f[2];        /* Computed Parameter: P1Size
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P1_m[2];             /* Expression: channel
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_Size_o[2];        /* Computed Parameter: P2Size
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P2_l[2];             /* Expression: reset
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_Size_g[2];        /* Computed Parameter: P3Size
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P3_j[2];             /* Expression: initValue
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_Size_a[2];        /* Computed Parameter: P4Size
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P4_b;                /* Expression: sampletime
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_Size_g[2];        /* Computed Parameter: P5Size
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P5_d;                /* Expression: slot
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_Size_d[2];        /* Computed Parameter: P6Size
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P6_o;                /* Expression: control
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P7_Size[2];          /* Computed Parameter: P7Size
                                        * '<S14>/PCI-6025E '
                                        */
  real_T PCI6025E_P7;                  /* Expression: boardType
                                        * '<S14>/PCI-6025E '
                                        */
  real_T Constant_Value_o;             /* Expression: const
                                        * '<S15>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * '<S8>/Switch'
                                        */
  real_T PortA_P1_Size[2];             /* Computed Parameter: P1Size
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P1[8];                  /* Expression: channel
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P2_Size[2];             /* Computed Parameter: P2Size
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P2;                     /* Expression: port
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P3_Size[2];             /* Computed Parameter: P3Size
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P3[8];                  /* Expression: reset
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P4_Size[2];             /* Computed Parameter: P4Size
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P4[8];                  /* Expression: initValue
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P5_Size[2];             /* Computed Parameter: P5Size
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P5;                     /* Expression: chip
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P6_Size[2];             /* Computed Parameter: P6Size
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P6;                     /* Expression: sampletime
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P7_Size[2];             /* Computed Parameter: P7Size
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P7;                     /* Expression: slot
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P8_Size[2];             /* Computed Parameter: P8Size
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P8;                     /* Expression: control
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P9_Size[2];             /* Computed Parameter: P9Size
                                        * '<S8>/Port A'
                                        */
  real_T PortA_P9;                     /* Expression: boardType
                                        * '<S8>/Port A'
                                        */
  real_T toThousandths_Gain;           /* Expression: 1000
                                        * '<S8>/toThousandths'
                                        */
  real_T Constant2_Value;              /* Expression: 32768
                                        * '<S8>/Constant2'
                                        */
  real_T PortB_P1_Size[2];             /* Computed Parameter: P1Size
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P1[8];                  /* Expression: channel
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P2_Size[2];             /* Computed Parameter: P2Size
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P2;                     /* Expression: port
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P3_Size[2];             /* Computed Parameter: P3Size
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P3[8];                  /* Expression: reset
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P4_Size[2];             /* Computed Parameter: P4Size
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P4[8];                  /* Expression: initValue
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P5_Size[2];             /* Computed Parameter: P5Size
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P5;                     /* Expression: chip
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P6_Size[2];             /* Computed Parameter: P6Size
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P6;                     /* Expression: sampletime
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P7_Size[2];             /* Computed Parameter: P7Size
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P7;                     /* Expression: slot
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P8_Size[2];             /* Computed Parameter: P8Size
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P8;                     /* Expression: control
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P9_Size[2];             /* Computed Parameter: P9Size
                                        * '<S8>/Port B'
                                        */
  real_T PortB_P9;                     /* Expression: boardType
                                        * '<S8>/Port B'
                                        */
  real_T xPCTargetTime_P1_Size_d[2];   /* Computed Parameter: P1Size
                                        * '<S8>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P1_a;           /* Expression: func
                                        * '<S8>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_Size_j[2];   /* Computed Parameter: P2Size
                                        * '<S8>/xPC Target  Time '
                                        */
  real_T xPCTargetTime_P2_b;           /* Expression: ts
                                        * '<S8>/xPC Target  Time '
                                        */
  rtP_SampleandHold_wrist_flexion SampleandHold;/* '<S4>/Sample and Hold' */
  rtP_SampleandHold_wrist_flexion SampleandHold_k;/* '<S4>/Sample and Hold' */
};

/* Real-time Model Data Structure */
struct rtModel_wrist_flexion {
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
    SimStruct childSFunctions[12];
    SimStruct *childSFunctionPtrs[12];
    struct _ssBlkInfo2 blkInfo2[12];
    struct _ssSFcnModelMethods2 methods2[12];
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
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[2];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[96];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[21];
      mxArray *params[21];
      struct _ssDWorkRecord dWork[4];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
    } Sfcn11;
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
    real_T odeY[18];
    real_T odeF[3][18];
    ODE3_IntgData intgData;
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
extern Parameters_wrist_flexion wrist_flexion_P;

/* Block signals (auto storage) */
extern BlockIO_wrist_flexion wrist_flexion_B;

/* Continuous states (auto storage) */
extern ContinuousStates_wrist_flexion wrist_flexion_X;

/* Block states (auto storage) */
extern D_Work_wrist_flexion wrist_flexion_DWork;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_wrist_flexion wrist_flexion_PrevZCSigState;

/* Model entry point functions */
extern void wrist_flexion_initialize(boolean_T firstTime);
extern void wrist_flexion_output(int_T tid);
extern void wrist_flexion_update(int_T tid);
extern void wrist_flexion_terminate(void);

/* Real-time Model object */
extern rtModel_wrist_flexion *wrist_flexion_rtM;

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
 * '<Root>' : wrist_flexion
 * '<S1>'   : wrist_flexion/Cursor Pos
 * '<S2>'   : wrist_flexion/CursorPos
 * '<S3>'   : wrist_flexion/MVC Target
 * '<S4>'   : wrist_flexion/RewardSbs
 * '<S5>'   : wrist_flexion/Status
 * '<S6>'   : wrist_flexion/UDPXmit
 * '<S7>'   : wrist_flexion/Version Display
 * '<S8>'   : wrist_flexion/WordSbs
 * '<S9>'   : wrist_flexion/CursorPos/Cursor Rotation
 * '<S10>'  : wrist_flexion/CursorPos/Neural Control Subsystem
 * '<S11>'  : wrist_flexion/RewardSbs/Sample and Hold
 * '<S12>'  : wrist_flexion/RewardSbs/Schmidt
 * '<S13>'  : wrist_flexion/RewardSbs/Schmidt/Sample and Hold
 * '<S14>'  : wrist_flexion/WordSbs/While Iterator Subsystem
 * '<S15>'  : wrist_flexion/WordSbs/While Iterator Subsystem/Compare To Constant
 * '<S16>'  : wrist_flexion/WordSbs/While Iterator Subsystem/Compare To Constant1
 */
#endif                                 /* _RTW_HEADER_wrist_flexion_h_ */
