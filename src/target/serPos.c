/* $Id$
 *
 * used to output the position data to TDT by cycling through the two 16
 * bit encoder signals one byte at a time.
 * New encoding scheme (implemented on Dec 2015) gets rid of dropped bytes 
 * by including a "clock" signal that is switched for every new byte. This
 * requires the addition of a new byte to the output (16 bits per decoder *
 * 2 decoders + 1 clock tick per byte * 5 bytes = 37 bits. The last 3 bits
 * of the fifth byte are zeros.
 * This is what the encoding looks like (bit 1 is most significant, bit 16
 * is least significant):
 * Byte 1 = [clock encoder1(1:7)]
 * Byte 2 = [clock encoder1(8:14)];
 * Byte 3 = [clock encoder1(15:16) encoder2(1:5)];
 * Byte 4 = [clock encoder2(6:12)];
 * Byte 5 = [clock encoder2(13:16) 0 0 0];
 */

#define S_FUNCTION_NAME serPos
#define S_FUNCTION_LEVEL 2

#include "simstruc.h" 

static void mdlInitializeSizes(SimStruct *S)
{
    int i; /* used for batch initilizing inputs */
    
    ssSetNumSFcnParams(S, 0); 
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* parameter number mismatch */
    }
        
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);
    
    /*
     * Block has 3 input ports (index, sh, el)
     */
    if (!ssSetNumInputPorts(S, 4)) return;
    for (i=0; i<ssGetNumInputPorts(S); i++) {
        ssSetInputPortWidth(S, i, 1);
        ssSetInputPortDirectFeedThrough(S, i, 1);
    }
    
    /* 
     * Block has 1 output port coresponding to the one output byte
     */
    if (!ssSetNumOutputPorts(S, 1)) return;
    ssSetOutputPortWidth(S, 0, 1);
    
    ssSetNumSampleTimes(S, 1);
    
    /* we have no zero crossing detection or modes */
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}


static void mdlOutputs(SimStruct *S, int_T tid)
{
    InputRealPtrsType uPtrs;
    real_T index, sh, el, clock;
    int i, s, e, t;
    
    real_T *byteOut;
    
    /* Get input */
    uPtrs = ssGetInputPortRealSignalPtrs(S, 0);
    index = *uPtrs[0];
    uPtrs = ssGetInputPortRealSignalPtrs(S, 1);
    sh = *uPtrs[0];
    uPtrs = ssGetInputPortRealSignalPtrs(S, 2);
    el = *uPtrs[0];
    uPtrs = ssGetInputPortRealSignalPtrs(S, 3);
    clock = *uPtrs[0];
    
    /* Get outputs */
    byteOut = ssGetOutputPortRealSignal(S,0);
    
    i = (int)index;
    s = (int)sh;
    e = (int)el;
    t = (int)clock;    
    t = t >> 7;
    // Swap clock value (to force switch change in at least one byte of output
    t = ~t;
    
    // Encoding    
    if (i==0){
        byteOut[0] = t*128 + (((s & 0xff00) >> 8) >> 1);
    } else if (i==1){
        byteOut[0] = t*128 + ((s >> 8) & 1)*64 + ((s & 0x00ff) >> 2);
    } else if (i==2){
        byteOut[0] = t*128 + (s & 3)*32 + (((e & 0xff00) >> 8) >> 3);
    } else if (i==3){
        byteOut[0] = t*128 + ((e >> 8) & 7)*16 + ((e & 0x00ff) >> 4);
    } else if (i==4){
        byteOut[0] = t*128 + (e & 15)*8;
    }

    UNUSED_ARG(tid);
}

static void mdlTerminate (SimStruct *S) { UNUSED_ARG(S); }

#ifdef MATLAB_MEX_FILE   /* Is this being compiled as a MEX-file? */
#include "simulink.c"    /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"     /* Code generation registration func */
#endif
