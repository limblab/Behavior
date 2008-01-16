/*
 * rt_nonfinite.h
 *
 * Real-Time Workshop code generation for Simulink model "xpcosc.mdl".
 *
 * Model Version              : 1.9
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Fri Dec 14 14:15:23 2007
 */
#ifndef _RTW_HEADER_rt_nonfinite_h_
#define _RTW_HEADER_rt_nonfinite_h_
#include <float.h>
#include <stddef.h>
#include "rtwtypes.h"

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
extern void rt_InitInfAndNaN(size_t realSize);
extern boolean_T rtIsInf(real_T value);
extern boolean_T rtIsInfF(real32_T value);
extern boolean_T rtIsNaN(real_T value);
extern boolean_T rtIsNaNF(real32_T value);

#endif                                 /* _RTW_HEADER_rt_nonfinite_h_ */
