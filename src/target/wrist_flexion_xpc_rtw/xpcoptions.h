#ifndef __wrist_flexion_XPCOPTIONS_H___
#define __wrist_flexion_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "wrist_flexion.h"
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_wrist_flexion))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0

/* Change all stepsize using the newBaseRateStepSize */
void wrist_flexion_ChangeStepSize(real_T newBaseRateStepSize,
  rtModel_wrist_flexion *wrist_flexion_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  wrist_flexion_rtM->Timing.stepSize0 = wrist_flexion_rtM->Timing.stepSize0 *
    ratio;
  wrist_flexion_rtM->Timing.stepSize1 = wrist_flexion_rtM->Timing.stepSize1 *
    ratio;
  wrist_flexion_rtM->Timing.stepSize2 = wrist_flexion_rtM->Timing.stepSize2 *
    ratio;
  wrist_flexion_rtM->Timing.stepSize3 = wrist_flexion_rtM->Timing.stepSize3 *
    ratio;
  wrist_flexion_rtM->Timing.stepSize = wrist_flexion_rtM->Timing.stepSize *
    ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  wrist_flexion_ChangeStepSize(stepSize, wrist_flexion_rtM);
}

#endif                                 /* __wrist_flexion_XPCOPTIONS_H___ */
