#ifndef __xpcosc_XPCOPTIONS_H___
#define __xpcosc_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "xpcosc.h"
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_xpcosc))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0

/* Change all stepsize using the newBaseRateStepSize */
void xpcosc_ChangeStepSize(real_T newBaseRateStepSize, rtModel_xpcosc
  *xpcosc_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.00025;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  xpcosc_rtM->Timing.stepSize0 = xpcosc_rtM->Timing.stepSize0 * ratio;
  xpcosc_rtM->Timing.stepSize1 = xpcosc_rtM->Timing.stepSize1 * ratio;
  xpcosc_rtM->Timing.stepSize = xpcosc_rtM->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  xpcosc_ChangeStepSize(stepSize, xpcosc_rtM);
}

#endif                                 /* __xpcosc_XPCOPTIONS_H___ */
