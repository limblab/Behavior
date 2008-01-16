/*
 * rt_atan2.c
 *
 * Real-Time Workshop code generation for Simulink model "forced_choice.mdl".
 *
 * Model Version              : 1.747
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Mon Dec 17 17:05:06 2007
 *
 */

#include "rt_atan2.h"
#if !defined(atan2f)
#define atan2f                         atan2
#else
#endif

/* Function: rt_atan2 =======================================================
 * Abstract:
 *   Calls ATAN2 with guards against domain error and non-finites
 */
real_T rt_atan2(real_T a, real_T b)
{
  real_T retValue;
  if (((boolean_T) rtIsNaN(a)) || ((boolean_T) rtIsNaN(b))) {
    retValue = rtNaN;
  } else {
    if (((boolean_T)rtIsInf(a)) && ((boolean_T)rtIsInf(b))) {
      if (b > 0.0) {
        b = 1.0;
      } else {
        b = -1.0;
      }

      if (a > 0.0) {
        a = 1.0;
      } else {
        a = -1.0;
      }

      retValue = atan2(a, b);
    } else if (b == 0.0) {
      if (a > 0.0) {
        retValue = 1.5707963267948966E+00;
      } else if (a < 0.0) {
        retValue = -1.5707963267948966E+00;
      } else {
        retValue = 0.0;
      }
    } else {
      retValue = atan2(a, b);
    }
  }

  return retValue;
}                                      /* end rt_atan2 */

/* Function: rt_atan232 =====================================================
 * Abstract:
 *   Calls ATAN2F with guard against domain error and non-finites
 */
real32_T rt_atan232(real32_T a, real32_T b)
{
  real32_T retValue;
  if (((boolean_T) rtIsNaNF(a)) || ((boolean_T) rtIsNaNF(b))) {
    retValue = ((real32_T) rtNaN);
  } else {
    if (((boolean_T)rtIsInfF(a)) && ((boolean_T)rtIsInfF(b))) {
      if (b > 0.0F) {
        b = 1.0F;
      } else {
        b = -1.0F;
      }

      if (a > 0.0F) {
        a = 1.0F;
      } else {
        a = -1.0F;
      }

      retValue = ((real32_T) atan2f(a, b));
    } else if (b == 0.0F) {
      if (a > 0.0F) {
        retValue = 1.5707963267948966E+00F;
      } else if (a < 0.0F) {
        retValue = -1.5707963267948966E+00F;
      } else {
        retValue = 0.0F;
      }
    } else {
      retValue = ((real32_T) atan2f(a, b));
    }
  }

  return retValue;
}                                      /* end rt_atan232 */
