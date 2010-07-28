#ifndef __bump_choice_XPCOPTIONS_H___
#define __bump_choice_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "bump_choice.h"
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_bump_choice))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0

/* Change all stepsize using the newBaseRateStepSize */
void bump_choice_ChangeStepSize(real_T newBaseRateStepSize, rtModel_bump_choice *
  bump_choice_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  bump_choice_rtM->Timing.stepSize0 = bump_choice_rtM->Timing.stepSize0 * ratio;
  bump_choice_rtM->Timing.stepSize1 = bump_choice_rtM->Timing.stepSize1 * ratio;
  bump_choice_rtM->Timing.stepSize2 = bump_choice_rtM->Timing.stepSize2 * ratio;
  bump_choice_rtM->Timing.stepSize = bump_choice_rtM->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  bump_choice_ChangeStepSize(stepSize, bump_choice_rtM);
}

#endif                                 /* __bump_choice_XPCOPTIONS_H___ */
