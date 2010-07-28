#ifndef __center_out_XPCOPTIONS_H___
#define __center_out_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "center_out.h"
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_center_out))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0

/* Change all stepsize using the newBaseRateStepSize */
void center_out_ChangeStepSize(real_T newBaseRateStepSize, rtModel_center_out
  *center_out_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  center_out_rtM->Timing.stepSize0 = center_out_rtM->Timing.stepSize0 * ratio;
  center_out_rtM->Timing.stepSize1 = center_out_rtM->Timing.stepSize1 * ratio;
  center_out_rtM->Timing.stepSize2 = center_out_rtM->Timing.stepSize2 * ratio;
  center_out_rtM->Timing.stepSize = center_out_rtM->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  center_out_ChangeStepSize(stepSize, center_out_rtM);
}

#endif                                 /* __center_out_XPCOPTIONS_H___ */
