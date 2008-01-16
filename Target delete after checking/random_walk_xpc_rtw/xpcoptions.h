#ifndef __random_walk_XPCOPTIONS_H___
#define __random_walk_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "random_walk.h"
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_random_walk))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0

/* Change all stepsize using the newBaseRateStepSize */
void random_walk_ChangeStepSize(real_T newBaseRateStepSize, rtModel_random_walk *
  random_walk_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  random_walk_rtM->Timing.stepSize0 = random_walk_rtM->Timing.stepSize0 * ratio;
  random_walk_rtM->Timing.stepSize1 = random_walk_rtM->Timing.stepSize1 * ratio;
  random_walk_rtM->Timing.stepSize2 = random_walk_rtM->Timing.stepSize2 * ratio;
  random_walk_rtM->Timing.stepSize3 = random_walk_rtM->Timing.stepSize3 * ratio;
  random_walk_rtM->Timing.stepSize = random_walk_rtM->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  random_walk_ChangeStepSize(stepSize, random_walk_rtM);
}

#endif                                 /* __random_walk_XPCOPTIONS_H___ */
