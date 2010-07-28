#ifndef __ball_drop_XPCOPTIONS_H___
#define __ball_drop_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "ball_drop.h"
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_ball_drop))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0

/* Change all stepsize using the newBaseRateStepSize */
void ball_drop_ChangeStepSize(real_T newBaseRateStepSize, rtModel_ball_drop
  *ball_drop_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  ball_drop_rtM->Timing.stepSize0 = ball_drop_rtM->Timing.stepSize0 * ratio;
  ball_drop_rtM->Timing.stepSize1 = ball_drop_rtM->Timing.stepSize1 * ratio;
  ball_drop_rtM->Timing.stepSize2 = ball_drop_rtM->Timing.stepSize2 * ratio;
  ball_drop_rtM->Timing.stepSize = ball_drop_rtM->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  ball_drop_ChangeStepSize(stepSize, ball_drop_rtM);
}

#endif                                 /* __ball_drop_XPCOPTIONS_H___ */
