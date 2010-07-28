#ifndef __multi_gadget_XPCOPTIONS_H___
#define __multi_gadget_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "multi_gadget.h"
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(Parameters_multi_gadget))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0

/* Change all stepsize using the newBaseRateStepSize */
void multi_gadget_ChangeStepSize(real_T newBaseRateStepSize,
  rtModel_multi_gadget *multi_gadget_rtM)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  multi_gadget_rtM->Timing.stepSize0 = multi_gadget_rtM->Timing.stepSize0 *
    ratio;
  multi_gadget_rtM->Timing.stepSize1 = multi_gadget_rtM->Timing.stepSize1 *
    ratio;
  multi_gadget_rtM->Timing.stepSize2 = multi_gadget_rtM->Timing.stepSize2 *
    ratio;
  multi_gadget_rtM->Timing.stepSize = multi_gadget_rtM->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  multi_gadget_ChangeStepSize(stepSize, multi_gadget_rtM);
}

#endif                                 /* __multi_gadget_XPCOPTIONS_H___ */
