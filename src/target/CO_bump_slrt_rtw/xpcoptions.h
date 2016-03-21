#ifndef __CO_bump_XPCOPTIONS_H___
#define __CO_bump_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "CO_bump.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_CO_bump_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            512
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0

/* Change all stepsize using the newBaseRateStepSize */
void CO_bump_ChangeStepSize(real_T newBaseRateStepSize, RT_MODEL_CO_bump_T *
  const CO_bump_M)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  CO_bump_M->Timing.stepSize0 = CO_bump_M->Timing.stepSize0 * ratio;
  CO_bump_M->Timing.stepSize1 = CO_bump_M->Timing.stepSize1 * ratio;
  CO_bump_M->Timing.stepSize2 = CO_bump_M->Timing.stepSize2 * ratio;
  CO_bump_M->Timing.stepSize = CO_bump_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  CO_bump_ChangeStepSize(stepSize, CO_bump_M);
}

#endif                                 /* __CO_bump_XPCOPTIONS_H___ */
