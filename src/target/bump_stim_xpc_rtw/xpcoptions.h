#ifndef __bump_stim_XPCOPTIONS_H___
#define __bump_stim_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "bump_stim.h"
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_bump_stim))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0

/* Change all stepsize using the newBaseRateStepSize */
void bump_stim_ChangeStepSize(real_T newBaseRateStepSize, rtModel_bump_stim
  *bump_stim_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  bump_stim_rtM->Timing.stepSize0 = bump_stim_rtM->Timing.stepSize0 * ratio;
  bump_stim_rtM->Timing.stepSize1 = bump_stim_rtM->Timing.stepSize1 * ratio;
  bump_stim_rtM->Timing.stepSize2 = bump_stim_rtM->Timing.stepSize2 * ratio;
  bump_stim_rtM->Timing.stepSize = bump_stim_rtM->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  bump_stim_ChangeStepSize(stepSize, bump_stim_rtM);
}

#endif                                 /* __bump_stim_XPCOPTIONS_H___ */
