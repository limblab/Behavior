/*
 * bump_stim_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "bump_stim.mdl".
 *
 * Model Version              : 1.1219
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:43:54 2010
 */

#include "bump_stim.h"
#include "rtw_capi.h"
#include "bump_stim_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Matrix Concatenation1",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Behavior BS/p1",
    "", 0, 0, 1, 0, 0 },

  { 2, 0, "Behavior BS/p2",
    "", 1, 0, 2, 0, 0 },

  { 3, 0, "Behavior BS/p3",
    "", 2, 0, 3, 0, 0 },

  { 4, 0, "Behavior BS/p4",
    "", 3, 0, 4, 0, 0 },

  { 5, 0, "Behavior BS/p5",
    "", 4, 0, 3, 0, 0 },

  { 6, 0, "Behavior BS/p6",
    "", 5, 0, 1, 0, 0 },

  { 7, 0, "Behavior BS/p7",
    "", 6, 0, 0, 0, 0 },

  { 8, 0, "Behavior BS/p8",
    "", 7, 0, 1, 0, 0 },

  { 9, 0, "BoundingBox/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 10, 0, "BoundingBox/Relational Operator",
    "", 0, 1, 3, 0, 0 },

  { 11, 0, "BoundingBox/Relational Operator1",
    "", 0, 1, 3, 0, 0 },

  { 12, 0, "BoundingBox/Relational Operator2",
    "", 0, 1, 3, 0, 0 },

  { 13, 0, "BoundingBox/Relational Operator3",
    "", 0, 1, 3, 0, 0 },

  { 14, 1, "Catch Force Generator/Gain",
    "", 0, 0, 3, 0, 0 },

  { 15, 4, "Catch Force Generator/LorentzForceGain",
    "", 0, 0, 1, 0, 0 },

  { 16, 3, "Catch Force Generator/DynamicAngle Switch",
    "", 0, 0, 3, 0, 0 },

  { 17, 0, "Catch Force Generator/LoadSelect Switch",
    "", 0, 0, 1, 0, 0 },

  { 18, 7, "Force Generator/Gain",
    "", 0, 0, 3, 0, 0 },

  { 19, 10, "Force Generator/LorentzForceGain",
    "", 0, 0, 1, 0, 0 },

  { 20, 0, "Force Generator/Multiport Switch",
    "", 0, 0, 1, 0, 0 },

  { 21, 9, "Force Generator/dynamicAngle Switch",
    "", 0, 0, 3, 0, 0 },

  { 22, 0, "Motor Control/Matrix Concatenation",
    "", 0, 1, 1, 0, 0 },

  { 23, 0, "Motor Control/MG1",
    "", 0, 0, 3, 0, 0 },

  { 24, 0, "Motor Control/MG2",
    "", 0, 0, 3, 0, 0 },

  { 25, 0, "Motor Control/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 26, 0, "Motor Control/Memory",
    "", 0, 1, 3, 0, 0 },

  { 27, 16, "Motor Control/Switch1",
    "", 0, 0, 1, 0, 0 },

  { 28, 0, "Motor Control/Switch2",
    "", 0, 0, 1, 0, 0 },

  { 29, 0, "Recentering Subsystem/Data Type Conversion1",
    "", 0, 1, 3, 0, 0 },

  { 30, 0, "Recentering Subsystem/Data Type Conversion2",
    "", 0, 1, 3, 0, 0 },

  { 31, 14, "Recentering Subsystem/Bounding Box Viscosity",
    "", 0, 0, 1, 0, 0 },

  { 32, 0, "Recentering Subsystem/InBox",
    "", 0, 1, 3, 0, 0 },

  { 33, 0, "Recentering Subsystem/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 34, 0, "Recentering Subsystem/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 35, 15, "Recentering Subsystem/Logical Operator3",
    "", 0, 1, 3, 0, 0 },

  { 36, 0, "Recentering Subsystem/Logical Operator5",
    "", 0, 1, 3, 0, 0 },

  { 37, 15, "Recentering Subsystem/Logical Operator6",
    "", 0, 1, 3, 0, 0 },

  { 38, 0, "Recentering Subsystem/NOT",
    "", 0, 1, 3, 0, 0 },

  { 39, 15, "Recentering Subsystem/Switch",
    "", 0, 0, 1, 0, 0 },

  { 40, 0, "RewardSbs/Data Type Conversion",
    "", 0, 0, 3, 0, 1 },

  { 41, 0, "RewardSbs/Relational Operator",
    "", 0, 1, 3, 0, 0 },

  { 42, 0, "RewardSbs/Switch",
    "", 0, 0, 3, 0, 0 },

  { 43, 0, "RewardSbs/Uniform Random Number",
    "", 0, 0, 3, 0, 0 },

  { 44, 0, "Target Peek/Gain",
    "", 0, 0, 3, 0, 0 },

  { 45, 0, "Target Peek/Gain1",
    "", 0, 0, 3, 0, 0 },

  { 46, 0, "Target Peek/Add",
    "", 0, 0, 3, 0, 0 },

  { 47, 0, "Target Peek/Add1",
    "", 0, 0, 3, 0, 0 },

  { 48, 0, "UDPXmit/Rate Transition",
    "", 0, 2, 5, 0, 2 },

  { 49, 0, "UDPXmit/Pack",
    "", 0, 2, 5, 0, 0 },

  { 50, 28, "Velocity Calculation/TachGain1",
    "", 0, 0, 3, 0, 0 },

  { 51, 28, "Velocity Calculation/TachGain2",
    "", 0, 0, 3, 0, 0 },

  { 52, 28, "Velocity Calculation/Matrix Multiply",
    "", 0, 0, 1, 0, 0 },

  { 53, 0, "Velocity Calculation/PCI-6025E AD/p1",
    "", 0, 0, 3, 0, 0 },

  { 54, 0, "Velocity Calculation/PCI-6025E AD/p2",
    "", 1, 0, 3, 0, 0 },

  { 55, 0, "Velocity Calculation/Switch",
    "", 0, 0, 1, 0, 0 },

  { 56, 0, "XY Position Subsystem/Gain",
    "", 0, 0, 3, 0, 0 },

  { 57, 0, "XY Position Subsystem/Gain1",
    "", 0, 0, 3, 0, 0 },

  { 58, 0, "XY Position Subsystem/PCI-QUAD04 ",
    "", 0, 0, 3, 0, 0 },

  { 59, 0, "XY Position Subsystem/PCI-QUAD04 1",
    "", 0, 0, 3, 0, 0 },

  { 60, 0, "XY Position Subsystem/Sum1",
    "", 0, 0, 3, 0, 0 },

  { 61, 0, "XY Position Subsystem/Sum3",
    "", 0, 0, 3, 0, 0 },

  { 62, 0, "Catch Force Generator/LorentzForce/Add",
    "", 0, 0, 3, 0, 0 },

  { 63, 4, "Catch Force Generator/LorentzForce/Add1",
    "", 0, 0, 3, 0, 0 },

  { 64, 3, "Catch Force Generator/ViscLoadSubsystem/Gain",
    "", 0, 0, 1, 0, 0 },

  { 65, 3, "Catch Force Generator/ViscLoadSubsystem/Inverter",
    "", 0, 0, 1, 0, 0 },

  { 66, 3, "Catch Force Generator/ViscLoadSubsystem/Product",
    "", 0, 0, 3, 0, 0 },

  { 67, 3, "Catch Force Generator/ViscLoadSubsystem/Product1",
    "", 0, 0, 3, 0, 0 },

  { 68, 3, "Catch Force Generator/ViscLoadSubsystem/Product2",
    "", 0, 0, 3, 0, 0 },

  { 69, 3, "Catch Force Generator/ViscLoadSubsystem/Product3",
    "", 0, 0, 3, 0, 0 },

  { 70, 3, "Catch Force Generator/ViscLoadSubsystem/Add",
    "", 0, 0, 3, 0, 0 },

  { 71, 3, "Catch Force Generator/ViscLoadSubsystem/Subtract",
    "", 0, 0, 3, 0, 0 },

  { 72, 3, "Catch Force Generator/ViscLoadSubsystem/cos",
    "", 0, 0, 3, 0, 0 },

  { 73, 3, "Catch Force Generator/ViscLoadSubsystem/sin",
    "", 0, 0, 3, 0, 0 },

  { 74, 0, "Force Generator/LorentzForce/Add",
    "", 0, 0, 3, 0, 0 },

  { 75, 10, "Force Generator/LorentzForce/Add1",
    "", 0, 0, 3, 0, 0 },

  { 76, 9, "Force Generator/ViscLoadSubsystem/Gain",
    "", 0, 0, 1, 0, 0 },

  { 77, 9, "Force Generator/ViscLoadSubsystem/Inverter",
    "", 0, 0, 1, 0, 0 },

  { 78, 9, "Force Generator/ViscLoadSubsystem/Product",
    "", 0, 0, 3, 0, 0 },

  { 79, 9, "Force Generator/ViscLoadSubsystem/Product1",
    "", 0, 0, 3, 0, 0 },

  { 80, 9, "Force Generator/ViscLoadSubsystem/Product2",
    "", 0, 0, 3, 0, 0 },

  { 81, 9, "Force Generator/ViscLoadSubsystem/Product3",
    "", 0, 0, 3, 0, 0 },

  { 82, 9, "Force Generator/ViscLoadSubsystem/Add",
    "", 0, 0, 3, 0, 0 },

  { 83, 9, "Force Generator/ViscLoadSubsystem/Subtract",
    "", 0, 0, 3, 0, 0 },

  { 84, 9, "Force Generator/ViscLoadSubsystem/cos",
    "", 0, 0, 3, 0, 0 },

  { 85, 9, "Force Generator/ViscLoadSubsystem/sin",
    "", 0, 0, 3, 0, 0 },

  { 86, 0, "Motor Control/Compare To Constant/Compare",
    "", 0, 2, 3, 0, 0 },

  { 87, 0, "Motor Control/Compare To Constant1/Compare",
    "", 0, 2, 3, 0, 0 },

  { 88, 18, "Motor Control/Force//Torque Transform/Gain",
    "", 0, 0, 1, 0, 0 },

  { 89, 18, "Motor Control/Force//Torque Transform/Matrix Multiply",
    "", 0, 0, 1, 0, 0 },

  { 90, 0, "Motor Control/Schmidt/Clock",
    "", 0, 0, 3, 0, 1 },

  { 91, 0, "Motor Control/Schmidt/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 92, 0, "Motor Control/Schmidt/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 93, 0, "Motor Control/Schmidt/Logical Operator2",
    "", 0, 1, 3, 0, 0 },

  { 94, 0, "Motor Control/Schmidt/Memory",
    "", 0, 1, 3, 0, 0 },

  { 95, 0, "Motor Control/Schmidt/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 96, 0, "Motor Control/Schmidt/Sum",
    "", 0, 0, 3, 0, 1 },

  { 97, 0, "Recentering Subsystem/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 0 },

  { 98, 0, "Recentering Subsystem/Compare To Zero1/Compare",
    "", 0, 2, 3, 0, 0 },

  { 99, 0, "Recentering Subsystem/Falling Edge/FixPt Relational Operator",
    "", 0, 2, 3, 0, 0 },

  { 100, 0, "Recentering Subsystem/Falling Edge/Delay Input1",
    "U(k-1)", 0, 2, 3, 0, 0 },

  { 101, 0, "Recentering Subsystem/Falling Edge1/FixPt Relational Operator",
    "", 0, 2, 3, 0, 0 },

  { 102, 0, "Recentering Subsystem/Falling Edge1/Delay Input1",
    "U(k-1)", 0, 2, 3, 0, 0 },

  { 103, 0, "Recentering Subsystem/No Movement/Abs2",
    "", 0, 0, 3, 0, 0 },

  { 104, 0, "Recentering Subsystem/No Movement/Abs3",
    "", 0, 0, 3, 0, 0 },

  { 105, 0, "Recentering Subsystem/No Movement/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 106, 13, "Recentering Subsystem/PD Controller/Gain1",
    "", 0, 0, 3, 0, 0 },

  { 107, 13, "Recentering Subsystem/PD Controller/Gain2",
    "", 0, 0, 3, 0, 0 },

  { 108, 13, "Recentering Subsystem/PD Controller/Gain3",
    "", 0, 0, 3, 0, 0 },

  { 109, 13, "Recentering Subsystem/PD Controller/Gain4",
    "", 0, 0, 3, 0, 0 },

  { 110, 13, "Recentering Subsystem/PD Controller/Product",
    "", 0, 0, 3, 0, 0 },

  { 111, 13, "Recentering Subsystem/PD Controller/Product1",
    "", 0, 0, 3, 0, 0 },

  { 112, 13, "Recentering Subsystem/PD Controller/Saturation",
    "", 0, 0, 3, 0, 0 },

  { 113, 13, "Recentering Subsystem/PD Controller/Saturation1",
    "", 0, 0, 3, 0, 0 },

  { 114, 13, "Recentering Subsystem/PD Controller/Add",
    "", 0, 0, 3, 0, 0 },

  { 115, 13, "Recentering Subsystem/PD Controller/Add1",
    "", 0, 0, 3, 0, 0 },

  { 116, 0, "Recentering Subsystem/S-R Flip-Flop/Logic",
    "", 0, 1, 1, 0, 0 },

  { 117, 0, "Recentering Subsystem/S-R Flip-Flop/Memory",
    "", 0, 1, 3, 0, 0 },

  { 118, 0, "Recentering Subsystem/Schmidt1/Clock",
    "", 0, 0, 3, 0, 1 },

  { 119, 0, "Recentering Subsystem/Schmidt1/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 120, 0, "Recentering Subsystem/Schmidt1/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 121, 0, "Recentering Subsystem/Schmidt1/Logical Operator2",
    "", 0, 1, 3, 0, 0 },

  { 122, 0, "Recentering Subsystem/Schmidt1/Memory",
    "", 0, 1, 3, 0, 0 },

  { 123, 0, "Recentering Subsystem/Schmidt1/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 124, 0, "Recentering Subsystem/Schmidt1/Sum",
    "", 0, 0, 3, 0, 1 },

  { 125, 0, "Recentering Subsystem/Schmidt2/Clock",
    "", 0, 0, 3, 0, 1 },

  { 126, 0, "Recentering Subsystem/Schmidt2/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 127, 0, "Recentering Subsystem/Schmidt2/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 128, 0, "Recentering Subsystem/Schmidt2/Logical Operator2",
    "", 0, 1, 3, 0, 0 },

  { 129, 0, "Recentering Subsystem/Schmidt2/Memory",
    "", 0, 1, 3, 0, 0 },

  { 130, 0, "Recentering Subsystem/Schmidt2/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 131, 0, "Recentering Subsystem/Schmidt2/Sum",
    "", 0, 0, 3, 0, 1 },

  { 132, 0, "Recentering Subsystem/Schmidt3/Clock",
    "", 0, 0, 3, 0, 1 },

  { 133, 0, "Recentering Subsystem/Schmidt3/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 134, 0, "Recentering Subsystem/Schmidt3/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 135, 0, "Recentering Subsystem/Schmidt3/Logical Operator2",
    "", 0, 1, 3, 0, 0 },

  { 136, 0, "Recentering Subsystem/Schmidt3/Memory",
    "", 0, 1, 3, 0, 0 },

  { 137, 0, "Recentering Subsystem/Schmidt3/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 138, 0, "Recentering Subsystem/Schmidt3/Sum",
    "", 0, 0, 3, 0, 1 },

  { 139, 0, "Recentering Subsystem/Start Moving/FixPt Relational Operator",
    "", 0, 2, 3, 0, 0 },

  { 140, 0, "Recentering Subsystem/Start Moving/Delay Input1",
    "U(k-1)", 0, 2, 3, 0, 0 },

  { 141, 0, "Recentering Subsystem/Timer/Clock",
    "", 0, 0, 3, 0, 1 },

  { 142, 0, "Recentering Subsystem/Timer/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 143, 0, "Recentering Subsystem/Timer/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 144, 0, "Recentering Subsystem/Timer/Logical Operator2",
    "", 0, 1, 3, 0, 0 },

  { 145, 0, "Recentering Subsystem/Timer/Logical Operator3",
    "", 0, 1, 3, 0, 0 },

  { 146, 0, "Recentering Subsystem/Timer/Logical Operator4",
    "", 0, 1, 3, 0, 0 },

  { 147, 0, "Recentering Subsystem/Timer/Logical Operator5",
    "", 0, 1, 3, 0, 0 },

  { 148, 0, "Recentering Subsystem/Timer/Memory",
    "", 0, 1, 3, 0, 0 },

  { 149, 0, "Recentering Subsystem/Timer/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 150, 0, "Recentering Subsystem/Timer/Sum",
    "", 0, 0, 3, 0, 1 },

  { 151, 26, "RewardSbs/Sample and Hold/In",
    "", 0, 0, 3, 0, 3 },

  { 152, 0, "RewardSbs/Schmidt/Clock",
    "", 0, 0, 3, 0, 1 },

  { 153, 0, "RewardSbs/Schmidt/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 154, 0, "RewardSbs/Schmidt/Sum",
    "", 0, 0, 3, 0, 1 },

  { 155, 0, "Velocity Calculation/Pos2VelX/Derivative",
    "", 0, 0, 3, 0, 1 },

  { 156, 0, "Velocity Calculation/Pos2VelX/dG",
    "", 0, 0, 3, 0, 0 },

  { 157, 0, "Velocity Calculation/Pos2VelX/Digital Filter",
    "", 0, 0, 3, 0, 0 },

  { 158, 0, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "", 0, 0, 3, 0, 0 },

  { 159, 0, "Velocity Calculation/Pos2VelY/Derivative",
    "", 0, 0, 3, 0, 1 },

  { 160, 0, "Velocity Calculation/Pos2VelY/dG",
    "", 0, 0, 3, 0, 0 },

  { 161, 0, "Velocity Calculation/Pos2VelY/Digital Filter",
    "", 0, 0, 3, 0, 0 },

  { 162, 0, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "", 0, 0, 3, 0, 0 },

  { 163, 0, "XY Position Subsystem/Cursor Rotation/sqrt(u[1]*u[1] + u[2]*u[2])",
    "", 0, 0, 3, 0, 0 },

  { 164, 0, "XY Position Subsystem/Cursor Rotation/Product",
    "", 0, 0, 3, 0, 0 },

  { 165, 0, "XY Position Subsystem/Cursor Rotation/Product1",
    "", 0, 0, 3, 0, 0 },

  { 166, 0, "XY Position Subsystem/Cursor Rotation/Sum",
    "", 0, 0, 3, 0, 0 },

  { 167, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function",
    "", 0, 0, 3, 0, 0 },

  { 168, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function1",
    "", 0, 0, 3, 0, 0 },

  { 169, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function2",
    "", 0, 0, 3, 0, 0 },

  { 170, 33, "XY Position Subsystem/For Iterator Subsystem/For Iterator",
    "", 0, 0, 3, 0, 3 },

  { 171, 33, "XY Position Subsystem/For Iterator Subsystem/SerialConverter",
    "", 0, 0, 3, 0, 3 },

  { 172, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p1",
    "", 0, 0, 3, 0, 3 },

  { 173, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p2",
    "", 1, 0, 3, 0, 3 },

  { 174, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p3",
    "", 2, 0, 3, 0, 3 },

  { 175, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p4",
    "", 3, 0, 3, 0, 3 },

  { 176, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p5",
    "", 4, 0, 3, 0, 3 },

  { 177, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p6",
    "", 5, 0, 3, 0, 3 },

  { 178, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p7",
    "", 6, 0, 3, 0, 3 },

  { 179, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p8",
    "", 7, 0, 3, 0, 3 },

  { 180, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p1",
    "", 0, 0, 3, 0, 3 },

  { 181, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p2",
    "", 1, 0, 3, 0, 3 },

  { 182, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p3",
    "", 2, 0, 3, 0, 3 },

  { 183, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p4",
    "", 3, 0, 3, 0, 3 },

  { 184, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p5",
    "", 4, 0, 3, 0, 3 },

  { 185, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p6",
    "", 5, 0, 3, 0, 3 },

  { 186, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p7",
    "", 6, 0, 3, 0, 3 },

  { 187, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p8",
    "", 7, 0, 3, 0, 3 },

  { 188, 33, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "", 0, 0, 3, 0, 3 },

  { 189, 33, "XY Position Subsystem/For Iterator Subsystem/Add",
    "", 0, 0, 3, 0, 3 },

  { 190, 33, "XY Position Subsystem/For Iterator Subsystem/Add1",
    "", 0, 0, 3, 0, 3 },

  { 191, 33, "XY Position Subsystem/For Iterator Subsystem/Switch",
    "", 0, 0, 3, 0, 3 },

  { 192, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate",
    "", 0, 0, 6, 0, 0 },

  { 193, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate1",
    "", 0, 0, 6, 0, 0 },

  { 194, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate2",
    "", 0, 0, 6, 0, 0 },

  { 195, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain",
    "", 0, 0, 6, 0, 0 },

  { 196, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain1",
    "", 0, 0, 6, 0, 0 },

  { 197, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain2",
    "", 0, 0, 6, 0, 0 },

  { 198, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product",
    "", 0, 0, 3, 0, 0 },

  { 199, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product1",
    "", 0, 0, 3, 0, 0 },

  { 200, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product2",
    "", 0, 0, 3, 0, 0 },

  { 201, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product3",
    "", 0, 0, 3, 0, 0 },

  { 202, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum1",
    "", 0, 0, 3, 0, 0 },

  { 203, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum2",
    "", 0, 0, 3, 0, 0 },

  { 204, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum3",
    "", 0, 0, 3, 0, 0 },

  { 205, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum4",
    "", 0, 0, 3, 0, 0 },

  { 206, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function",
    "", 0, 0, 3, 0, 0 },

  { 207, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function1",
    "", 0, 0, 3, 0, 0 },

  { 208, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function2",
    "", 0, 0, 3, 0, 0 },

  { 209, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function3",
    "", 0, 0, 3, 0, 0 },

  { 210, 0, "Catch Force Generator/LorentzForce/Lorentz/dX",
    "", 0, 0, 3, 0, 0 },

  { 211, 0, "Catch Force Generator/LorentzForce/Lorentz/dY",
    "", 0, 0, 3, 0, 0 },

  { 212, 0, "Catch Force Generator/LorentzForce/Lorentz/dZ",
    "", 0, 0, 3, 0, 0 },

  { 213, 0, "Catch Force Generator/LorentzForce/Lorentz/product1",
    "", 0, 0, 3, 0, 0 },

  { 214, 0, "Catch Force Generator/LorentzForce/Lorentz/product2",
    "", 0, 0, 3, 0, 0 },

  { 215, 0, "Catch Force Generator/LorentzForce/Lorentz/product3",
    "", 0, 0, 3, 0, 0 },

  { 216, 0, "Catch Force Generator/LorentzForce/Lorentz/product4",
    "", 0, 0, 3, 0, 0 },

  { 217, 0, "Catch Force Generator/LorentzForce/Lorentz/Add1",
    "", 0, 0, 3, 0, 0 },

  { 218, 0, "Catch Force Generator/LorentzForce/Lorentz/Add2",
    "", 0, 0, 3, 0, 0 },

  { 219, 0, "Catch Force Generator/LorentzForce/Lorentz/Add3",
    "", 0, 0, 3, 0, 0 },

  { 220, 0, "Catch Force Generator/LorentzForce/Lorentz/Add4",
    "", 0, 0, 3, 0, 0 },

  { 221, 0, "Catch Force Generator/LorentzForce/Lorentz/AddX",
    "", 0, 0, 3, 0, 0 },

  { 222, 0, "Catch Force Generator/LorentzForce/Lorentz/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 223, 0, "Catch Force Generator/LorentzForce/Lorentz/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 224, 0, "Catch Force Generator/LorentzForce/Lorentz/x",
    "", 0, 0, 3, 0, 0 },

  { 225, 0, "Catch Force Generator/LorentzForce/Lorentz/y",
    "", 0, 0, 3, 0, 0 },

  { 226, 0, "Catch Force Generator/LorentzForce/Lorentz/z",
    "", 0, 0, 3, 0, 0 },

  { 227, 0, "Catch Force Generator/LorentzForce/Lorentz1/dX",
    "", 0, 0, 3, 0, 0 },

  { 228, 0, "Catch Force Generator/LorentzForce/Lorentz1/dY",
    "", 0, 0, 3, 0, 0 },

  { 229, 0, "Catch Force Generator/LorentzForce/Lorentz1/dZ",
    "", 0, 0, 3, 0, 0 },

  { 230, 0, "Catch Force Generator/LorentzForce/Lorentz1/product1",
    "", 0, 0, 3, 0, 0 },

  { 231, 0, "Catch Force Generator/LorentzForce/Lorentz1/product2",
    "", 0, 0, 3, 0, 0 },

  { 232, 0, "Catch Force Generator/LorentzForce/Lorentz1/product3",
    "", 0, 0, 3, 0, 0 },

  { 233, 0, "Catch Force Generator/LorentzForce/Lorentz1/product4",
    "", 0, 0, 3, 0, 0 },

  { 234, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add1",
    "", 0, 0, 3, 0, 0 },

  { 235, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add2",
    "", 0, 0, 3, 0, 0 },

  { 236, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add3",
    "", 0, 0, 3, 0, 0 },

  { 237, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add4",
    "", 0, 0, 3, 0, 0 },

  { 238, 0, "Catch Force Generator/LorentzForce/Lorentz1/AddX",
    "", 0, 0, 3, 0, 0 },

  { 239, 0, "Catch Force Generator/LorentzForce/Lorentz1/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 240, 0, "Catch Force Generator/LorentzForce/Lorentz1/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 241, 0, "Catch Force Generator/LorentzForce/Lorentz1/x",
    "", 0, 0, 3, 0, 0 },

  { 242, 0, "Catch Force Generator/LorentzForce/Lorentz1/y",
    "", 0, 0, 3, 0, 0 },

  { 243, 0, "Catch Force Generator/LorentzForce/Lorentz1/z",
    "", 0, 0, 3, 0, 0 },

  { 244, 0, "Catch Force Generator/LorentzForce/Lorentz2/dX",
    "", 0, 0, 3, 0, 0 },

  { 245, 0, "Catch Force Generator/LorentzForce/Lorentz2/dY",
    "", 0, 0, 3, 0, 0 },

  { 246, 0, "Catch Force Generator/LorentzForce/Lorentz2/dZ",
    "", 0, 0, 3, 0, 0 },

  { 247, 0, "Catch Force Generator/LorentzForce/Lorentz2/product1",
    "", 0, 0, 3, 0, 0 },

  { 248, 0, "Catch Force Generator/LorentzForce/Lorentz2/product2",
    "", 0, 0, 3, 0, 0 },

  { 249, 0, "Catch Force Generator/LorentzForce/Lorentz2/product3",
    "", 0, 0, 3, 0, 0 },

  { 250, 0, "Catch Force Generator/LorentzForce/Lorentz2/product4",
    "", 0, 0, 3, 0, 0 },

  { 251, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add1",
    "", 0, 0, 3, 0, 0 },

  { 252, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add2",
    "", 0, 0, 3, 0, 0 },

  { 253, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add3",
    "", 0, 0, 3, 0, 0 },

  { 254, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add4",
    "", 0, 0, 3, 0, 0 },

  { 255, 0, "Catch Force Generator/LorentzForce/Lorentz2/AddX",
    "", 0, 0, 3, 0, 0 },

  { 256, 0, "Catch Force Generator/LorentzForce/Lorentz2/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 257, 0, "Catch Force Generator/LorentzForce/Lorentz2/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 258, 0, "Catch Force Generator/LorentzForce/Lorentz2/x",
    "", 0, 0, 3, 0, 0 },

  { 259, 0, "Catch Force Generator/LorentzForce/Lorentz2/y",
    "", 0, 0, 3, 0, 0 },

  { 260, 0, "Catch Force Generator/LorentzForce/Lorentz2/z",
    "", 0, 0, 3, 0, 0 },

  { 261, 0, "Catch Force Generator/LorentzForce/Lorentz3/dX",
    "", 0, 0, 3, 0, 0 },

  { 262, 0, "Catch Force Generator/LorentzForce/Lorentz3/dY",
    "", 0, 0, 3, 0, 0 },

  { 263, 0, "Catch Force Generator/LorentzForce/Lorentz3/dZ",
    "", 0, 0, 3, 0, 0 },

  { 264, 0, "Catch Force Generator/LorentzForce/Lorentz3/product1",
    "", 0, 0, 3, 0, 0 },

  { 265, 0, "Catch Force Generator/LorentzForce/Lorentz3/product2",
    "", 0, 0, 3, 0, 0 },

  { 266, 0, "Catch Force Generator/LorentzForce/Lorentz3/product3",
    "", 0, 0, 3, 0, 0 },

  { 267, 0, "Catch Force Generator/LorentzForce/Lorentz3/product4",
    "", 0, 0, 3, 0, 0 },

  { 268, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add1",
    "", 0, 0, 3, 0, 0 },

  { 269, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add2",
    "", 0, 0, 3, 0, 0 },

  { 270, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add3",
    "", 0, 0, 3, 0, 0 },

  { 271, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add4",
    "", 0, 0, 3, 0, 0 },

  { 272, 0, "Catch Force Generator/LorentzForce/Lorentz3/AddX",
    "", 0, 0, 3, 0, 0 },

  { 273, 0, "Catch Force Generator/LorentzForce/Lorentz3/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 274, 0, "Catch Force Generator/LorentzForce/Lorentz3/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 275, 0, "Catch Force Generator/LorentzForce/Lorentz3/x",
    "", 0, 0, 3, 0, 0 },

  { 276, 0, "Catch Force Generator/LorentzForce/Lorentz3/y",
    "", 0, 0, 3, 0, 0 },

  { 277, 0, "Catch Force Generator/LorentzForce/Lorentz3/z",
    "", 0, 0, 3, 0, 0 },

  { 278, 0, "Force Generator/LorentzForce/Lorentz/dX",
    "", 0, 0, 3, 0, 0 },

  { 279, 0, "Force Generator/LorentzForce/Lorentz/dY",
    "", 0, 0, 3, 0, 0 },

  { 280, 0, "Force Generator/LorentzForce/Lorentz/dZ",
    "", 0, 0, 3, 0, 0 },

  { 281, 0, "Force Generator/LorentzForce/Lorentz/product1",
    "", 0, 0, 3, 0, 0 },

  { 282, 0, "Force Generator/LorentzForce/Lorentz/product2",
    "", 0, 0, 3, 0, 0 },

  { 283, 0, "Force Generator/LorentzForce/Lorentz/product3",
    "", 0, 0, 3, 0, 0 },

  { 284, 0, "Force Generator/LorentzForce/Lorentz/product4",
    "", 0, 0, 3, 0, 0 },

  { 285, 0, "Force Generator/LorentzForce/Lorentz/Add1",
    "", 0, 0, 3, 0, 0 },

  { 286, 0, "Force Generator/LorentzForce/Lorentz/Add2",
    "", 0, 0, 3, 0, 0 },

  { 287, 0, "Force Generator/LorentzForce/Lorentz/Add3",
    "", 0, 0, 3, 0, 0 },

  { 288, 0, "Force Generator/LorentzForce/Lorentz/Add4",
    "", 0, 0, 3, 0, 0 },

  { 289, 0, "Force Generator/LorentzForce/Lorentz/AddX",
    "", 0, 0, 3, 0, 0 },

  { 290, 0, "Force Generator/LorentzForce/Lorentz/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 291, 0, "Force Generator/LorentzForce/Lorentz/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 292, 0, "Force Generator/LorentzForce/Lorentz/x",
    "", 0, 0, 3, 0, 0 },

  { 293, 0, "Force Generator/LorentzForce/Lorentz/y",
    "", 0, 0, 3, 0, 0 },

  { 294, 0, "Force Generator/LorentzForce/Lorentz/z",
    "", 0, 0, 3, 0, 0 },

  { 295, 0, "Force Generator/LorentzForce/Lorentz1/dX",
    "", 0, 0, 3, 0, 0 },

  { 296, 0, "Force Generator/LorentzForce/Lorentz1/dY",
    "", 0, 0, 3, 0, 0 },

  { 297, 0, "Force Generator/LorentzForce/Lorentz1/dZ",
    "", 0, 0, 3, 0, 0 },

  { 298, 0, "Force Generator/LorentzForce/Lorentz1/product1",
    "", 0, 0, 3, 0, 0 },

  { 299, 0, "Force Generator/LorentzForce/Lorentz1/product2",
    "", 0, 0, 3, 0, 0 },

  { 300, 0, "Force Generator/LorentzForce/Lorentz1/product3",
    "", 0, 0, 3, 0, 0 },

  { 301, 0, "Force Generator/LorentzForce/Lorentz1/product4",
    "", 0, 0, 3, 0, 0 },

  { 302, 0, "Force Generator/LorentzForce/Lorentz1/Add1",
    "", 0, 0, 3, 0, 0 },

  { 303, 0, "Force Generator/LorentzForce/Lorentz1/Add2",
    "", 0, 0, 3, 0, 0 },

  { 304, 0, "Force Generator/LorentzForce/Lorentz1/Add3",
    "", 0, 0, 3, 0, 0 },

  { 305, 0, "Force Generator/LorentzForce/Lorentz1/Add4",
    "", 0, 0, 3, 0, 0 },

  { 306, 0, "Force Generator/LorentzForce/Lorentz1/AddX",
    "", 0, 0, 3, 0, 0 },

  { 307, 0, "Force Generator/LorentzForce/Lorentz1/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 308, 0, "Force Generator/LorentzForce/Lorentz1/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 309, 0, "Force Generator/LorentzForce/Lorentz1/x",
    "", 0, 0, 3, 0, 0 },

  { 310, 0, "Force Generator/LorentzForce/Lorentz1/y",
    "", 0, 0, 3, 0, 0 },

  { 311, 0, "Force Generator/LorentzForce/Lorentz1/z",
    "", 0, 0, 3, 0, 0 },

  { 312, 0, "Force Generator/LorentzForce/Lorentz2/dX",
    "", 0, 0, 3, 0, 0 },

  { 313, 0, "Force Generator/LorentzForce/Lorentz2/dY",
    "", 0, 0, 3, 0, 0 },

  { 314, 0, "Force Generator/LorentzForce/Lorentz2/dZ",
    "", 0, 0, 3, 0, 0 },

  { 315, 0, "Force Generator/LorentzForce/Lorentz2/product1",
    "", 0, 0, 3, 0, 0 },

  { 316, 0, "Force Generator/LorentzForce/Lorentz2/product2",
    "", 0, 0, 3, 0, 0 },

  { 317, 0, "Force Generator/LorentzForce/Lorentz2/product3",
    "", 0, 0, 3, 0, 0 },

  { 318, 0, "Force Generator/LorentzForce/Lorentz2/product4",
    "", 0, 0, 3, 0, 0 },

  { 319, 0, "Force Generator/LorentzForce/Lorentz2/Add1",
    "", 0, 0, 3, 0, 0 },

  { 320, 0, "Force Generator/LorentzForce/Lorentz2/Add2",
    "", 0, 0, 3, 0, 0 },

  { 321, 0, "Force Generator/LorentzForce/Lorentz2/Add3",
    "", 0, 0, 3, 0, 0 },

  { 322, 0, "Force Generator/LorentzForce/Lorentz2/Add4",
    "", 0, 0, 3, 0, 0 },

  { 323, 0, "Force Generator/LorentzForce/Lorentz2/AddX",
    "", 0, 0, 3, 0, 0 },

  { 324, 0, "Force Generator/LorentzForce/Lorentz2/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 325, 0, "Force Generator/LorentzForce/Lorentz2/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 326, 0, "Force Generator/LorentzForce/Lorentz2/x",
    "", 0, 0, 3, 0, 0 },

  { 327, 0, "Force Generator/LorentzForce/Lorentz2/y",
    "", 0, 0, 3, 0, 0 },

  { 328, 0, "Force Generator/LorentzForce/Lorentz2/z",
    "", 0, 0, 3, 0, 0 },

  { 329, 0, "Force Generator/LorentzForce/Lorentz3/dX",
    "", 0, 0, 3, 0, 0 },

  { 330, 0, "Force Generator/LorentzForce/Lorentz3/dY",
    "", 0, 0, 3, 0, 0 },

  { 331, 0, "Force Generator/LorentzForce/Lorentz3/dZ",
    "", 0, 0, 3, 0, 0 },

  { 332, 0, "Force Generator/LorentzForce/Lorentz3/product1",
    "", 0, 0, 3, 0, 0 },

  { 333, 0, "Force Generator/LorentzForce/Lorentz3/product2",
    "", 0, 0, 3, 0, 0 },

  { 334, 0, "Force Generator/LorentzForce/Lorentz3/product3",
    "", 0, 0, 3, 0, 0 },

  { 335, 0, "Force Generator/LorentzForce/Lorentz3/product4",
    "", 0, 0, 3, 0, 0 },

  { 336, 0, "Force Generator/LorentzForce/Lorentz3/Add1",
    "", 0, 0, 3, 0, 0 },

  { 337, 0, "Force Generator/LorentzForce/Lorentz3/Add2",
    "", 0, 0, 3, 0, 0 },

  { 338, 0, "Force Generator/LorentzForce/Lorentz3/Add3",
    "", 0, 0, 3, 0, 0 },

  { 339, 0, "Force Generator/LorentzForce/Lorentz3/Add4",
    "", 0, 0, 3, 0, 0 },

  { 340, 0, "Force Generator/LorentzForce/Lorentz3/AddX",
    "", 0, 0, 3, 0, 0 },

  { 341, 0, "Force Generator/LorentzForce/Lorentz3/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 342, 0, "Force Generator/LorentzForce/Lorentz3/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 343, 0, "Force Generator/LorentzForce/Lorentz3/x",
    "", 0, 0, 3, 0, 0 },

  { 344, 0, "Force Generator/LorentzForce/Lorentz3/y",
    "", 0, 0, 3, 0, 0 },

  { 345, 0, "Force Generator/LorentzForce/Lorentz3/z",
    "", 0, 0, 3, 0, 0 },

  { 346, 18, "Motor Control/Force//Torque Transform/Transpose/Math Function",
    "", 0, 0, 6, 0, 0 },

  { 347, 0, "Motor Control/Schmidt/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 1 },

  { 348, 19, "Motor Control/Schmidt/Enabled Subsystem/In1",
    "", 0, 0, 3, 0, 1 },

  { 349, 0, "Recentering Subsystem/Falling Edge/Nonpositive/Compare",
    "", 0, 2, 3, 0, 0 },

  { 350, 0, "Recentering Subsystem/Falling Edge1/Nonpositive/Compare",
    "", 0, 2, 3, 0, 0 },

  { 351, 0, "Recentering Subsystem/No Movement/Compare To Constant2/Compare",
    "", 0, 2, 3, 0, 0 },

  { 352, 0, "Recentering Subsystem/No Movement/Compare To Constant3/Compare",
    "", 0, 2, 3, 0, 0 },

  { 353, 0, "Recentering Subsystem/Schmidt1/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 1 },

  { 354, 20, "Recentering Subsystem/Schmidt1/Enabled Subsystem/In1",
    "", 0, 0, 3, 0, 1 },

  { 355, 0, "Recentering Subsystem/Schmidt2/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 1 },

  { 356, 21, "Recentering Subsystem/Schmidt2/Enabled Subsystem/In1",
    "", 0, 0, 3, 0, 1 },

  { 357, 0, "Recentering Subsystem/Schmidt3/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 1 },

  { 358, 22, "Recentering Subsystem/Schmidt3/Enabled Subsystem/In1",
    "", 0, 0, 3, 0, 1 },

  { 359, 0, "Recentering Subsystem/Start Moving/Nonpositive/Compare",
    "", 0, 2, 3, 0, 0 },

  { 360, 0, "Recentering Subsystem/Timer/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 1 },

  { 361, 0,
    "Recentering Subsystem/Timer/Detect Fall Nonpositive/FixPt Relational Operator",
    "", 0, 2, 3, 0, 0 },

  { 362, 0, "Recentering Subsystem/Timer/Detect Fall Nonpositive/Delay Input1",
    "U(k-1)", 0, 2, 3, 0, 0 },

  { 363, 23, "Recentering Subsystem/Timer/Enabled Subsystem/In1",
    "", 0, 0, 3, 0, 1 },

  { 364, 27, "RewardSbs/Schmidt/Sample and Hold/In",
    "", 0, 0, 3, 0, 3 },

  { 365, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "", 0, 0, 3, 0, 3 },

  { 366, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "", 0, 0, 3, 0, 3 },

  { 367, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Subtract",
    "", 0, 0, 3, 0, 3 },

  { 368, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Switch",
    "", 0, 0, 3, 0, 3 },

  { 369, 0,
    "Recentering Subsystem/Timer/Detect Fall Nonpositive/Nonpositive/Compare",
    "", 0, 2, 3, 0, 0 },

  { 370, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Compare",
    "", 0, 1, 3, 0, 3 },

  { 371, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1/Compare",
    "", 0, 1, 3, 0, 3 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 372, "Behavior BS",
    "P1", 0, 3, 0 },

  { 373, "Behavior BS",
    "P2", 0, 3, 0 },

  { 374, "Behavior BS",
    "P3", 0, 3, 0 },

  { 375, "Behavior BS",
    "P4", 0, 3, 0 },

  { 376, "Behavior BS",
    "P5", 0, 3, 0 },

  { 377, "Behavior BS",
    "P6", 0, 3, 0 },

  { 378, "Behavior BS",
    "P7", 0, 3, 0 },

  { 379, "Behavior BS",
    "P8", 0, 3, 0 },

  { 380, "Behavior BS",
    "P9", 0, 3, 0 },

  { 381, "Behavior BS",
    "P10", 0, 3, 0 },

  { 382, "Behavior BS",
    "P11", 0, 3, 0 },

  { 383, "Behavior BS",
    "P12", 0, 3, 0 },

  { 384, "Behavior BS",
    "P13", 0, 3, 0 },

  { 385, "Behavior BS",
    "P14", 0, 3, 0 },

  { 386, "Behavior BS",
    "P15", 0, 3, 0 },

  { 387, "Behavior BS",
    "P16", 0, 3, 0 },

  { 388, "Behavior BS",
    "P17", 0, 3, 0 },

  { 389, "Behavior BS",
    "P18", 0, 3, 0 },

  { 390, "Behavior BS",
    "P19", 0, 3, 0 },

  { 391, "Behavior BS",
    "P20", 0, 3, 0 },

  { 392, "Behavior BS",
    "P21", 0, 3, 0 },

  { 393, "Behavior BS",
    "P22", 0, 3, 0 },

  { 394, "Behavior BS",
    "P23", 0, 3, 0 },

  { 395, "BoundingBox/XHighLimit",
    "Value", 0, 3, 0 },

  { 396, "BoundingBox/XLowLimit",
    "Value", 0, 3, 0 },

  { 397, "BoundingBox/YHighLimit",
    "Value", 0, 3, 0 },

  { 398, "BoundingBox/YLowLimit",
    "Value", 0, 3, 0 },

  { 399, "Catch Force Generator/DynamicAngle",
    "Value", 0, 3, 0 },

  { 400, "Catch Force Generator/Load",
    "Value", 0, 3, 0 },

  { 401, "Catch Force Generator/Off",
    "Value", 0, 3, 0 },

  { 402, "Catch Force Generator/staticX",
    "Value", 0, 3, 0 },

  { 403, "Catch Force Generator/staticY",
    "Value", 0, 3, 0 },

  { 404, "Catch Force Generator/visAngle",
    "Value", 0, 3, 0 },

  { 405, "Catch Force Generator/Gain",
    "Gain", 0, 3, 0 },

  { 406, "Catch Force Generator/LorentzForceGain",
    "Gain", 0, 3, 0 },

  { 407, "Force Generator/DynamicAngle",
    "Value", 0, 3, 0 },

  { 408, "Force Generator/Load",
    "Value", 0, 3, 0 },

  { 409, "Force Generator/Off",
    "Value", 0, 3, 0 },

  { 410, "Force Generator/staticX",
    "Value", 0, 3, 0 },

  { 411, "Force Generator/staticY",
    "Value", 0, 3, 0 },

  { 412, "Force Generator/visAngle",
    "Value", 0, 3, 0 },

  { 413, "Force Generator/Gain",
    "Gain", 0, 3, 0 },

  { 414, "Force Generator/LorentzForceGain",
    "Gain", 0, 3, 0 },

  { 415, "Motor Control/zeroX",
    "Value", 0, 3, 0 },

  { 416, "Motor Control/zeroY",
    "Value", 0, 3, 0 },

  { 417, "Motor Control/MG1",
    "Gain", 0, 3, 0 },

  { 418, "Motor Control/MG2",
    "Gain", 0, 3, 0 },

  { 419, "Motor Control/Memory",
    "X0", 1, 3, 0 },

  { 420, "Motor Control/PCI-6025E ",
    "P1", 0, 7, 0 },

  { 421, "Motor Control/PCI-6025E ",
    "P2", 0, 7, 0 },

  { 422, "Motor Control/PCI-6025E ",
    "P3", 0, 7, 0 },

  { 423, "Motor Control/PCI-6025E ",
    "P4", 0, 7, 0 },

  { 424, "Motor Control/PCI-6025E ",
    "P5", 0, 3, 0 },

  { 425, "Motor Control/PCI-6025E ",
    "P6", 0, 3, 0 },

  { 426, "Motor Control/PCI-6025E ",
    "P7", 0, 3, 0 },

  { 427, "Recentering Subsystem/RecenterFlag",
    "Value", 0, 3, 0 },

  { 428, "Recentering Subsystem/Bounding Box Viscosity",
    "Gain", 0, 3, 0 },

  { 429, "RewardSbs/JackpotChance",
    "Value", 0, 3, 0 },

  { 430, "RewardSbs/RewardJackpot",
    "Value", 0, 3, 0 },

  { 431, "RewardSbs/RewardTime",
    "Value", 0, 3, 0 },

  { 432, "RewardSbs/Uniform Random Number",
    "Minimum", 0, 3, 0 },

  { 433, "RewardSbs/Uniform Random Number",
    "Maximum", 0, 3, 0 },

  { 434, "RewardSbs/Uniform Random Number",
    "Seed", 0, 3, 0 },

  { 435, "Target Peek/Gain",
    "Gain", 0, 3, 0 },

  { 436, "Target Peek/Gain1",
    "Gain", 0, 3, 0 },

  { 437, "UDPXmit/Send",
    "P1", 0, 8, 0 },

  { 438, "UDPXmit/Send",
    "P2", 0, 3, 0 },

  { 439, "UDPXmit/Send",
    "P3", 0, 3, 0 },

  { 440, "UDPXmit/Send",
    "P4", 0, 3, 0 },

  { 441, "Velocity Calculation/UseTachs",
    "Value", 0, 3, 0 },

  { 442, "Velocity Calculation/TachGain1",
    "Gain", 0, 3, 0 },

  { 443, "Velocity Calculation/TachGain2",
    "Gain", 0, 3, 0 },

  { 444, "Velocity Calculation/PCI-6025E AD",
    "P1", 0, 7, 0 },

  { 445, "Velocity Calculation/PCI-6025E AD",
    "P2", 0, 7, 0 },

  { 446, "Velocity Calculation/PCI-6025E AD",
    "P3", 0, 7, 0 },

  { 447, "Velocity Calculation/PCI-6025E AD",
    "P4", 0, 3, 0 },

  { 448, "Velocity Calculation/PCI-6025E AD",
    "P5", 0, 3, 0 },

  { 449, "Velocity Calculation/PCI-6025E AD",
    "P6", 0, 3, 0 },

  { 450, "Velocity Calculation/Switch",
    "Threshold", 0, 3, 0 },

  { 451, "XY Position Subsystem/elbowOffset",
    "Value", 0, 3, 0 },

  { 452, "XY Position Subsystem/shoulderOffset",
    "Value", 0, 3, 0 },

  { 453, "XY Position Subsystem/Gain",
    "Gain", 0, 3, 0 },

  { 454, "XY Position Subsystem/Gain1",
    "Gain", 0, 3, 0 },

  { 455, "XY Position Subsystem/PCI-QUAD04 ",
    "P1", 0, 3, 0 },

  { 456, "XY Position Subsystem/PCI-QUAD04 ",
    "P2", 0, 3, 0 },

  { 457, "XY Position Subsystem/PCI-QUAD04 ",
    "P3", 0, 3, 0 },

  { 458, "XY Position Subsystem/PCI-QUAD04 ",
    "P4", 0, 3, 0 },

  { 459, "XY Position Subsystem/PCI-QUAD04 ",
    "P5", 0, 3, 0 },

  { 460, "XY Position Subsystem/PCI-QUAD04 ",
    "P6", 0, 3, 0 },

  { 461, "XY Position Subsystem/PCI-QUAD04 ",
    "P7", 0, 3, 0 },

  { 462, "XY Position Subsystem/PCI-QUAD04 ",
    "P8", 0, 3, 0 },

  { 463, "XY Position Subsystem/PCI-QUAD04 ",
    "P9", 0, 3, 0 },

  { 464, "XY Position Subsystem/PCI-QUAD04 ",
    "P10", 0, 3, 0 },

  { 465, "XY Position Subsystem/PCI-QUAD04 ",
    "P11", 0, 3, 0 },

  { 466, "XY Position Subsystem/PCI-QUAD04 1",
    "P1", 0, 3, 0 },

  { 467, "XY Position Subsystem/PCI-QUAD04 1",
    "P2", 0, 3, 0 },

  { 468, "XY Position Subsystem/PCI-QUAD04 1",
    "P3", 0, 3, 0 },

  { 469, "XY Position Subsystem/PCI-QUAD04 1",
    "P4", 0, 3, 0 },

  { 470, "XY Position Subsystem/PCI-QUAD04 1",
    "P5", 0, 3, 0 },

  { 471, "XY Position Subsystem/PCI-QUAD04 1",
    "P6", 0, 3, 0 },

  { 472, "XY Position Subsystem/PCI-QUAD04 1",
    "P7", 0, 3, 0 },

  { 473, "XY Position Subsystem/PCI-QUAD04 1",
    "P8", 0, 3, 0 },

  { 474, "XY Position Subsystem/PCI-QUAD04 1",
    "P9", 0, 3, 0 },

  { 475, "XY Position Subsystem/PCI-QUAD04 1",
    "P10", 0, 3, 0 },

  { 476, "XY Position Subsystem/PCI-QUAD04 1",
    "P11", 0, 3, 0 },

  { 477, "Catch Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 3, 0 },

  { 478, "Catch Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 3, 0 },

  { 479, "Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 3, 0 },

  { 480, "Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 3, 0 },

  { 481, "Motor Control/Compare To Constant/Constant",
    "Value", 0, 3, 0 },

  { 482, "Motor Control/Compare To Constant1/Constant",
    "Value", 0, 3, 0 },

  { 483, "Motor Control/Force//Torque Transform/Gain",
    "Gain", 0, 3, 0 },

  { 484, "Motor Control/Schmidt/Time",
    "Value", 0, 3, 0 },

  { 485, "Motor Control/Schmidt/Memory",
    "X0", 1, 3, 0 },

  { 486, "Recentering Subsystem/Falling Edge/Delay Input1",
    "X0", 2, 3, 0 },

  { 487, "Recentering Subsystem/Falling Edge1/Delay Input1",
    "X0", 2, 3, 0 },

  { 488, "Recentering Subsystem/PD Controller/Gain1",
    "Gain", 0, 3, 0 },

  { 489, "Recentering Subsystem/PD Controller/Gain2",
    "Gain", 0, 3, 0 },

  { 490, "Recentering Subsystem/PD Controller/Gain3",
    "Gain", 0, 3, 0 },

  { 491, "Recentering Subsystem/PD Controller/Gain4",
    "Gain", 0, 3, 0 },

  { 492, "Recentering Subsystem/PD Controller/Saturation",
    "UpperLimit", 0, 3, 0 },

  { 493, "Recentering Subsystem/PD Controller/Saturation",
    "LowerLimit", 0, 3, 0 },

  { 494, "Recentering Subsystem/PD Controller/Saturation1",
    "UpperLimit", 0, 3, 0 },

  { 495, "Recentering Subsystem/PD Controller/Saturation1",
    "LowerLimit", 0, 3, 0 },

  { 496, "Recentering Subsystem/S-R Flip-Flop/Logic",
    "TruthTable", 1, 9, 0 },

  { 497, "Recentering Subsystem/S-R Flip-Flop/Memory",
    "X0", 1, 3, 0 },

  { 498, "Recentering Subsystem/Schmidt1/Time",
    "Value", 0, 3, 0 },

  { 499, "Recentering Subsystem/Schmidt1/Memory",
    "X0", 1, 3, 0 },

  { 500, "Recentering Subsystem/Schmidt2/Time",
    "Value", 0, 3, 0 },

  { 501, "Recentering Subsystem/Schmidt2/Memory",
    "X0", 1, 3, 0 },

  { 502, "Recentering Subsystem/Schmidt3/Time",
    "Value", 0, 3, 0 },

  { 503, "Recentering Subsystem/Schmidt3/Memory",
    "X0", 1, 3, 0 },

  { 504, "Recentering Subsystem/Start Moving/Delay Input1",
    "X0", 2, 3, 0 },

  { 505, "Recentering Subsystem/Timer/Time",
    "Value", 0, 3, 0 },

  { 506, "Recentering Subsystem/Timer/Memory",
    "X0", 1, 3, 0 },

  { 507, "Velocity Calculation/Pos2VelX/dG",
    "Gain", 0, 3, 0 },

  { 508, "Velocity Calculation/Pos2VelX/Digital Filter",
    "ICRTP", 0, 3, 0 },

  { 509, "Velocity Calculation/Pos2VelX/Digital Filter",
    "RTP1COEFF", 0, 8, 0 },

  { 510, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "ICRTP", 0, 3, 0 },

  { 511, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "RTP1COEFF", 0, 8, 0 },

  { 512, "Velocity Calculation/Pos2VelY/dG",
    "Gain", 0, 3, 0 },

  { 513, "Velocity Calculation/Pos2VelY/Digital Filter",
    "ICRTP", 0, 3, 0 },

  { 514, "Velocity Calculation/Pos2VelY/Digital Filter",
    "RTP1COEFF", 0, 8, 0 },

  { 515, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "ICRTP", 0, 3, 0 },

  { 516, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "RTP1COEFF", 0, 8, 0 },

  { 517, "XY Position Subsystem/Cursor Rotation/AngleOffset",
    "Value", 0, 3, 0 },

  { 518, "XY Position Subsystem/For Iterator Subsystem/Constant",
    "Value", 0, 3, 0 },

  { 519, "XY Position Subsystem/For Iterator Subsystem/Constant2",
    "Value", 0, 3, 0 },

  { 520, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P1", 0, 10, 0 },

  { 521, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P2", 0, 3, 0 },

  { 522, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P3", 0, 10, 0 },

  { 523, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P4", 0, 10, 0 },

  { 524, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P5", 0, 3, 0 },

  { 525, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P6", 0, 3, 0 },

  { 526, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P7", 0, 3, 0 },

  { 527, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P8", 0, 3, 0 },

  { 528, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P9", 0, 3, 0 },

  { 529, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P1", 0, 10, 0 },

  { 530, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P2", 0, 3, 0 },

  { 531, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P3", 0, 10, 0 },

  { 532, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P4", 0, 10, 0 },

  { 533, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P5", 0, 3, 0 },

  { 534, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P6", 0, 3, 0 },

  { 535, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P7", 0, 3, 0 },

  { 536, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P8", 0, 3, 0 },

  { 537, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P9", 0, 3, 0 },

  { 538, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 3, 0 },

  { 539, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 3, 0 },

  { 540, "XY Position Subsystem/For Iterator Subsystem/Switch",
    "Threshold", 0, 3, 0 },

  { 541, "XY Position Subsystem/Jacobian-Cartesian Transformation/L1",
    "Value", 0, 3, 0 },

  { 542, "XY Position Subsystem/Jacobian-Cartesian Transformation/L2",
    "Value", 0, 3, 0 },

  { 543, "XY Position Subsystem/Jacobian-Cartesian Transformation/xoffset",
    "Value", 0, 3, 0 },

  { 544, "XY Position Subsystem/Jacobian-Cartesian Transformation/yoffset",
    "Value", 0, 3, 0 },

  { 545, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain",
    "Gain", 0, 3, 0 },

  { 546, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain1",
    "Gain", 0, 3, 0 },

  { 547, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain2",
    "Gain", 0, 3, 0 },

  { 548, "Catch Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 3, 0 },

  { 549, "Catch Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 3, 0 },

  { 550, "Catch Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 3, 0 },

  { 551, "Catch Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 3, 0 },

  { 552, "Catch Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 3, 0 },

  { 553, "Catch Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 3, 0 },

  { 554, "Catch Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 3, 0 },

  { 555, "Catch Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 3, 0 },

  { 556, "Catch Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 3, 0 },

  { 557, "Catch Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 3, 0 },

  { 558, "Catch Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 3, 0 },

  { 559, "Catch Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 3, 0 },

  { 560, "Catch Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 3, 0 },

  { 561, "Catch Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 3, 0 },

  { 562, "Catch Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 3, 0 },

  { 563, "Catch Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 3, 0 },

  { 564, "Catch Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 3, 0 },

  { 565, "Catch Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 3, 0 },

  { 566, "Catch Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 3, 0 },

  { 567, "Catch Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 3, 0 },

  { 568, "Catch Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 3, 0 },

  { 569, "Catch Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 3, 0 },

  { 570, "Catch Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 3, 0 },

  { 571, "Catch Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 3, 0 },

  { 572, "Catch Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 3, 0 },

  { 573, "Catch Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 3, 0 },

  { 574, "Catch Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 3, 0 },

  { 575, "Catch Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 3, 0 },

  { 576, "Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 3, 0 },

  { 577, "Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 3, 0 },

  { 578, "Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 3, 0 },

  { 579, "Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 3, 0 },

  { 580, "Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 3, 0 },

  { 581, "Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 3, 0 },

  { 582, "Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 3, 0 },

  { 583, "Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 3, 0 },

  { 584, "Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 3, 0 },

  { 585, "Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 3, 0 },

  { 586, "Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 3, 0 },

  { 587, "Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 3, 0 },

  { 588, "Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 3, 0 },

  { 589, "Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 3, 0 },

  { 590, "Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 3, 0 },

  { 591, "Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 3, 0 },

  { 592, "Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 3, 0 },

  { 593, "Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 3, 0 },

  { 594, "Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 3, 0 },

  { 595, "Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 3, 0 },

  { 596, "Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 3, 0 },

  { 597, "Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 3, 0 },

  { 598, "Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 3, 0 },

  { 599, "Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 3, 0 },

  { 600, "Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 3, 0 },

  { 601, "Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 3, 0 },

  { 602, "Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 3, 0 },

  { 603, "Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 3, 0 },

  { 604, "Recentering Subsystem/No Movement/Compare To Constant2/Constant",
    "Value", 0, 3, 0 },

  { 605, "Recentering Subsystem/No Movement/Compare To Constant3/Constant",
    "Value", 0, 3, 0 },

  { 606, "Recentering Subsystem/Timer/Detect Fall Nonpositive/Delay Input1",
    "X0", 2, 3, 0 },

  { 607,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant",
    "Value", 0, 3, 0 },

  { 608,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant1",
    "Value", 0, 3, 0 },

  { 609,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "Gain", 0, 3, 0 },

  { 610,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P1", 0, 7, 0 },

  { 611,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P2", 0, 7, 0 },

  { 612,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P3", 0, 7, 0 },

  { 613,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P4", 0, 3, 0 },

  { 614,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P5", 0, 3, 0 },

  { 615,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P6", 0, 3, 0 },

  { 616,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P7", 0, 3, 0 },

  { 617,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 3, 0 },

  { 618,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 3, 0 },

  { 619,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Constant",
    "Value", 0, 3, 0 },

  { 620,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1/Constant",
    "Value", 0, 3, 0 },

  {
    0, NULL, NULL, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &bump_stim_B.MatrixConcatenation1[0],/* 0: Signal */
  &bump_stim_B.BehaviorBS_o1[0],       /* 1: Signal */
  &bump_stim_B.BehaviorBS_o2[0],       /* 2: Signal */
  &bump_stim_B.BehaviorBS_o3,          /* 3: Signal */
  &bump_stim_B.BehaviorBS_o4[0],       /* 4: Signal */
  &bump_stim_B.BehaviorBS_o5,          /* 5: Signal */
  &bump_stim_B.BehaviorBS_o6[0],       /* 6: Signal */
  &bump_stim_B.BehaviorBS_o7[0],       /* 7: Signal */
  &bump_stim_B.BehaviorBS_o8[0],       /* 8: Signal */
  &bump_stim_B.LogicalOperator_n,      /* 9: Signal */
  &bump_stim_B.RelationalOperator_f,   /* 10: Signal */
  &bump_stim_B.RelationalOperator1,    /* 11: Signal */
  &bump_stim_B.RelationalOperator2,    /* 12: Signal */
  &bump_stim_B.RelationalOperator3,    /* 13: Signal */
  &bump_stim_B.Gain_p,                 /* 14: Signal */
  &bump_stim_B.LorentzForceGain_p[0],  /* 15: Signal */
  &bump_stim_B.DynamicAngleSwitch,     /* 16: Signal */
  &bump_stim_B.LoadSelectSwitch[0],    /* 17: Signal */
  &bump_stim_B.Gain_a,                 /* 18: Signal */
  &bump_stim_B.LorentzForceGain[0],    /* 19: Signal */
  &bump_stim_B.MultiportSwitch[0],     /* 20: Signal */
  &bump_stim_B.dynamicAngleSwitch,     /* 21: Signal */
  &bump_stim_B.MatrixConcatenation[0], /* 22: Signal */
  &bump_stim_B.MG1,                    /* 23: Signal */
  &bump_stim_B.MG2,                    /* 24: Signal */
  &bump_stim_B.LogicalOperator1_l,     /* 25: Signal */
  &bump_stim_B.Memory_i,               /* 26: Signal */
  &bump_stim_B.Switch1[0],             /* 27: Signal */
  &bump_stim_B.Switch2[0],             /* 28: Signal */
  &bump_stim_B.DataTypeConversion1,    /* 29: Signal */
  &bump_stim_B.DataTypeConversion2,    /* 30: Signal */
  &bump_stim_B.BoundingBoxViscosity[0],/* 31: Signal */
  &bump_stim_B.InBox,                  /* 32: Signal */
  &bump_stim_B.LogicalOperator_k,      /* 33: Signal */
  &bump_stim_B.LogicalOperator1_an,    /* 34: Signal */
  &bump_stim_B.LogicalOperator3_f,     /* 35: Signal */
  &bump_stim_B.LogicalOperator5_i,     /* 36: Signal */
  &bump_stim_B.LogicalOperator6,       /* 37: Signal */
  &bump_stim_B.NOT,                    /* 38: Signal */
  &bump_stim_B.Switch_a[0],            /* 39: Signal */
  &bump_stim_B.DataTypeConversion,     /* 40: Signal */
  &bump_stim_B.RelationalOperator_m,   /* 41: Signal */
  &bump_stim_B.Switch_n,               /* 42: Signal */
  &bump_stim_B.UniformRandomNumber,    /* 43: Signal */
  &bump_stim_B.Gain_i,                 /* 44: Signal */
  &bump_stim_B.Gain1_n,                /* 45: Signal */
  &bump_stim_B.Add_o,                  /* 46: Signal */
  &bump_stim_B.Add1_a,                 /* 47: Signal */
  &bump_stim_B.RateTransition[0],      /* 48: Signal */
  &bump_stim_B.Pack[0],                /* 49: Signal */
  &bump_stim_B.TachGain1,              /* 50: Signal */
  &bump_stim_B.TachGain2,              /* 51: Signal */
  &bump_stim_B.MatrixMultiply[0],      /* 52: Signal */
  &bump_stim_B.PCI6025EAD_o1,          /* 53: Signal */
  &bump_stim_B.PCI6025EAD_o2,          /* 54: Signal */
  &bump_stim_B.Switch[0],              /* 55: Signal */
  &bump_stim_B.Gain,                   /* 56: Signal */
  &bump_stim_B.Gain1,                  /* 57: Signal */
  &bump_stim_B.PCIQUAD04,              /* 58: Signal */
  &bump_stim_B.PCIQUAD041,             /* 59: Signal */
  &bump_stim_B.Sum1,                   /* 60: Signal */
  &bump_stim_B.Sum3,                   /* 61: Signal */
  &bump_stim_B.Add_d,                  /* 62: Signal */
  &bump_stim_B.Add1_l2,                /* 63: Signal */
  &bump_stim_B.Gain_ax[0],             /* 64: Signal */
  &bump_stim_B.Inverter_i[0],          /* 65: Signal */
  &bump_stim_B.Product_n,              /* 66: Signal */
  &bump_stim_B.Product1_k,             /* 67: Signal */
  &bump_stim_B.Product2_l,             /* 68: Signal */
  &bump_stim_B.Product3_g,             /* 69: Signal */
  &bump_stim_B.Add_lj,                 /* 70: Signal */
  &bump_stim_B.Subtract_k,             /* 71: Signal */
  &bump_stim_B.cos_kc,                 /* 72: Signal */
  &bump_stim_B.sin_k,                  /* 73: Signal */
  &bump_stim_B.Add,                    /* 74: Signal */
  &bump_stim_B.Add1_h,                 /* 75: Signal */
  &bump_stim_B.Gain_n[0],              /* 76: Signal */
  &bump_stim_B.Inverter[0],            /* 77: Signal */
  &bump_stim_B.Product_j,              /* 78: Signal */
  &bump_stim_B.Product1_j,             /* 79: Signal */
  &bump_stim_B.Product2_m,             /* 80: Signal */
  &bump_stim_B.Product3_k,             /* 81: Signal */
  &bump_stim_B.Add_l,                  /* 82: Signal */
  &bump_stim_B.Subtract_o,             /* 83: Signal */
  &bump_stim_B.cos_k,                  /* 84: Signal */
  &bump_stim_B.sin_l,                  /* 85: Signal */
  &bump_stim_B.Compare_o,              /* 86: Signal */
  &bump_stim_B.Compare_h,              /* 87: Signal */
  &bump_stim_B.Gain_g[0],              /* 88: Signal */
  &bump_stim_B.MatrixMultiply_l[0],    /* 89: Signal */
  &bump_stim_B.Clock,                  /* 90: Signal */
  &bump_stim_B.LogicalOperator,        /* 91: Signal */
  &bump_stim_B.LogicalOperator1,       /* 92: Signal */
  &bump_stim_B.LogicalOperator2,       /* 93: Signal */
  &bump_stim_B.Memory,                 /* 94: Signal */
  &bump_stim_B.RelationalOperator,     /* 95: Signal */
  &bump_stim_B.Sum,                    /* 96: Signal */
  &bump_stim_B.Compare_b,              /* 97: Signal */
  &bump_stim_B.Compare_m,              /* 98: Signal */
  &bump_stim_B.FixPtRelationalOperator_d,/* 99: Signal */
  &bump_stim_B.Uk1_d,                  /* 100: Signal */
  &bump_stim_B.FixPtRelationalOperator_n,/* 101: Signal */
  &bump_stim_B.Uk1_p,                  /* 102: Signal */
  &bump_stim_B.Abs2,                   /* 103: Signal */
  &bump_stim_B.Abs3,                   /* 104: Signal */
  &bump_stim_B.LogicalOperator1_a,     /* 105: Signal */
  &bump_stim_B.Gain1_d,                /* 106: Signal */
  &bump_stim_B.Gain2,                  /* 107: Signal */
  &bump_stim_B.Gain3,                  /* 108: Signal */
  &bump_stim_B.Gain4,                  /* 109: Signal */
  &bump_stim_B.Product_i,              /* 110: Signal */
  &bump_stim_B.Product1_o,             /* 111: Signal */
  &bump_stim_B.Saturation,             /* 112: Signal */
  &bump_stim_B.Saturation1,            /* 113: Signal */
  &bump_stim_B.Add_i,                  /* 114: Signal */
  &bump_stim_B.Add1_l,                 /* 115: Signal */
  &bump_stim_B.Logic[0],               /* 116: Signal */
  &bump_stim_B.Memory_j,               /* 117: Signal */
  &bump_stim_B.Clock_c,                /* 118: Signal */
  &bump_stim_B.LogicalOperator_g,      /* 119: Signal */
  &bump_stim_B.LogicalOperator1_m,     /* 120: Signal */
  &bump_stim_B.LogicalOperator2_b,     /* 121: Signal */
  &bump_stim_B.Memory_e,               /* 122: Signal */
  &bump_stim_B.RelationalOperator_i,   /* 123: Signal */
  &bump_stim_B.Sum_b,                  /* 124: Signal */
  &bump_stim_B.Clock_n,                /* 125: Signal */
  &bump_stim_B.LogicalOperator_f,      /* 126: Signal */
  &bump_stim_B.LogicalOperator1_n,     /* 127: Signal */
  &bump_stim_B.LogicalOperator2_o,     /* 128: Signal */
  &bump_stim_B.Memory_d,               /* 129: Signal */
  &bump_stim_B.RelationalOperator_h,   /* 130: Signal */
  &bump_stim_B.Sum_gv,                 /* 131: Signal */
  &bump_stim_B.Clock_a,                /* 132: Signal */
  &bump_stim_B.LogicalOperator_o,      /* 133: Signal */
  &bump_stim_B.LogicalOperator1_e,     /* 134: Signal */
  &bump_stim_B.LogicalOperator2_p,     /* 135: Signal */
  &bump_stim_B.Memory_em,              /* 136: Signal */
  &bump_stim_B.RelationalOperator_p,   /* 137: Signal */
  &bump_stim_B.Sum_k,                  /* 138: Signal */
  &bump_stim_B.FixPtRelationalOperator_k,/* 139: Signal */
  &bump_stim_B.Uk1_h,                  /* 140: Signal */
  &bump_stim_B.Clock_d,                /* 141: Signal */
  &bump_stim_B.LogicalOperator_j,      /* 142: Signal */
  &bump_stim_B.LogicalOperator1_f,     /* 143: Signal */
  &bump_stim_B.LogicalOperator2_h,     /* 144: Signal */
  &bump_stim_B.LogicalOperator3,       /* 145: Signal */
  &bump_stim_B.LogicalOperator4,       /* 146: Signal */
  &bump_stim_B.LogicalOperator5,       /* 147: Signal */
  &bump_stim_B.Memory_o,               /* 148: Signal */
  &bump_stim_B.RelationalOperator_a,   /* 149: Signal */
  &bump_stim_B.Sum_g,                  /* 150: Signal */
  &bump_stim_B.SampleandHold_a.In,     /* 151: Signal */
  &bump_stim_B.Clock_j,                /* 152: Signal */
  &bump_stim_B.RelationalOperator_f5,  /* 153: Signal */
  &bump_stim_B.Sum_c,                  /* 154: Signal */
  &bump_stim_B.Derivative,             /* 155: Signal */
  &bump_stim_B.dG,                     /* 156: Signal */
  &bump_stim_B.DigitalFilter,          /* 157: Signal */
  &bump_stim_B.DigitalFilter2,         /* 158: Signal */
  &bump_stim_B.Derivative_k,           /* 159: Signal */
  &bump_stim_B.dG_e,                   /* 160: Signal */
  &bump_stim_B.DigitalFilter_j,        /* 161: Signal */
  &bump_stim_B.DigitalFilter2_n,       /* 162: Signal */
  &bump_stim_B.sqrtu1u1u2u2,           /* 163: Signal */
  &bump_stim_B.Product_c,              /* 164: Signal */
  &bump_stim_B.Product1_b,             /* 165: Signal */
  &bump_stim_B.Sum_n,                  /* 166: Signal */
  &bump_stim_B.TrigonometricFunction_g,/* 167: Signal */
  &bump_stim_B.TrigonometricFunction1_k,/* 168: Signal */
  &bump_stim_B.TrigonometricFunction2_l,/* 169: Signal */
  &bump_stim_B.ForIterator,            /* 170: Signal */
  &bump_stim_B.SerialConverter,        /* 171: Signal */
  &bump_stim_B.ToBits_o1,              /* 172: Signal */
  &bump_stim_B.ToBits_o2,              /* 173: Signal */
  &bump_stim_B.ToBits_o3,              /* 174: Signal */
  &bump_stim_B.ToBits_o4,              /* 175: Signal */
  &bump_stim_B.ToBits_o5,              /* 176: Signal */
  &bump_stim_B.ToBits_o6,              /* 177: Signal */
  &bump_stim_B.ToBits_o7,              /* 178: Signal */
  &bump_stim_B.ToBits_o8,              /* 179: Signal */
  &bump_stim_B.ToBits1_o1,             /* 180: Signal */
  &bump_stim_B.ToBits1_o2,             /* 181: Signal */
  &bump_stim_B.ToBits1_o3,             /* 182: Signal */
  &bump_stim_B.ToBits1_o4,             /* 183: Signal */
  &bump_stim_B.ToBits1_o5,             /* 184: Signal */
  &bump_stim_B.ToBits1_o6,             /* 185: Signal */
  &bump_stim_B.ToBits1_o7,             /* 186: Signal */
  &bump_stim_B.ToBits1_o8,             /* 187: Signal */
  &bump_stim_B.xPCTargetTime,          /* 188: Signal */
  &bump_stim_B.Add_p,                  /* 189: Signal */
  &bump_stim_B.Add1_j,                 /* 190: Signal */
  &bump_stim_B.Switch_e,               /* 191: Signal */
  &bump_stim_B.MatrixConcatenate2[0],  /* 192: Signal */
  &bump_stim_B.MatrixConcatenate2[0],  /* 193: Signal */
  &bump_stim_B.MatrixConcatenate2[0],  /* 194: Signal */
  &bump_stim_B.MatrixConcatenate2[0],  /* 195: Signal */
  &bump_stim_B.MatrixConcatenate2[0],  /* 196: Signal */
  &bump_stim_B.MatrixConcatenate2[0],  /* 197: Signal */
  &bump_stim_B.Product,                /* 198: Signal */
  &bump_stim_B.Product1,               /* 199: Signal */
  &bump_stim_B.Product2,               /* 200: Signal */
  &bump_stim_B.Product3,               /* 201: Signal */
  &bump_stim_B.Sum1_o,                 /* 202: Signal */
  &bump_stim_B.Sum2,                   /* 203: Signal */
  &bump_stim_B.Sum3_l,                 /* 204: Signal */
  &bump_stim_B.Sum4,                   /* 205: Signal */
  &bump_stim_B.TrigonometricFunction,  /* 206: Signal */
  &bump_stim_B.TrigonometricFunction1, /* 207: Signal */
  &bump_stim_B.TrigonometricFunction2, /* 208: Signal */
  &bump_stim_B.TrigonometricFunction3, /* 209: Signal */
  &bump_stim_B.dX,                     /* 210: Signal */
  &bump_stim_B.dY,                     /* 211: Signal */
  &bump_stim_B.dZ,                     /* 212: Signal */
  &bump_stim_B.product1,               /* 213: Signal */
  &bump_stim_B.product2,               /* 214: Signal */
  &bump_stim_B.product3,               /* 215: Signal */
  &bump_stim_B.product4,               /* 216: Signal */
  &bump_stim_B.Add1,                   /* 217: Signal */
  &bump_stim_B.Add2,                   /* 218: Signal */
  &bump_stim_B.Add3,                   /* 219: Signal */
  &bump_stim_B.Add4,                   /* 220: Signal */
  &bump_stim_B.AddX,                   /* 221: Signal */
  &bump_stim_B.AddX1,                  /* 222: Signal */
  &bump_stim_B.AddX2,                  /* 223: Signal */
  &bump_stim_B.x_e,                    /* 224: Signal */
  &bump_stim_B.y,                      /* 225: Signal */
  &bump_stim_B.z,                      /* 226: Signal */
  &bump_stim_B.dX_b,                   /* 227: Signal */
  &bump_stim_B.dY_a,                   /* 228: Signal */
  &bump_stim_B.dZ_f,                   /* 229: Signal */
  &bump_stim_B.product1_o,             /* 230: Signal */
  &bump_stim_B.product2_i,             /* 231: Signal */
  &bump_stim_B.product3_g,             /* 232: Signal */
  &bump_stim_B.product4_g,             /* 233: Signal */
  &bump_stim_B.Add1_m,                 /* 234: Signal */
  &bump_stim_B.Add2_h,                 /* 235: Signal */
  &bump_stim_B.Add3_b,                 /* 236: Signal */
  &bump_stim_B.Add4_i,                 /* 237: Signal */
  &bump_stim_B.AddX_d,                 /* 238: Signal */
  &bump_stim_B.AddX1_f,                /* 239: Signal */
  &bump_stim_B.AddX2_b,                /* 240: Signal */
  &bump_stim_B.x_hx,                   /* 241: Signal */
  &bump_stim_B.y_o,                    /* 242: Signal */
  &bump_stim_B.z_e,                    /* 243: Signal */
  &bump_stim_B.dX_g,                   /* 244: Signal */
  &bump_stim_B.dY_k,                   /* 245: Signal */
  &bump_stim_B.dZ_p,                   /* 246: Signal */
  &bump_stim_B.product1_b,             /* 247: Signal */
  &bump_stim_B.product2_io,            /* 248: Signal */
  &bump_stim_B.product3_i,             /* 249: Signal */
  &bump_stim_B.product4_m,             /* 250: Signal */
  &bump_stim_B.Add1_e,                 /* 251: Signal */
  &bump_stim_B.Add2_l,                 /* 252: Signal */
  &bump_stim_B.Add3_c,                 /* 253: Signal */
  &bump_stim_B.Add4_m,                 /* 254: Signal */
  &bump_stim_B.AddX_b,                 /* 255: Signal */
  &bump_stim_B.AddX1_h,                /* 256: Signal */
  &bump_stim_B.AddX2_bo,               /* 257: Signal */
  &bump_stim_B.x_ei,                   /* 258: Signal */
  &bump_stim_B.y_g,                    /* 259: Signal */
  &bump_stim_B.z_p,                    /* 260: Signal */
  &bump_stim_B.dX_e,                   /* 261: Signal */
  &bump_stim_B.dY_c,                   /* 262: Signal */
  &bump_stim_B.dZ_h,                   /* 263: Signal */
  &bump_stim_B.product1_j,             /* 264: Signal */
  &bump_stim_B.product2_f,             /* 265: Signal */
  &bump_stim_B.product3_c,             /* 266: Signal */
  &bump_stim_B.product4_h,             /* 267: Signal */
  &bump_stim_B.Add1_f,                 /* 268: Signal */
  &bump_stim_B.Add2_m,                 /* 269: Signal */
  &bump_stim_B.Add3_e,                 /* 270: Signal */
  &bump_stim_B.Add4_l,                 /* 271: Signal */
  &bump_stim_B.AddX_i,                 /* 272: Signal */
  &bump_stim_B.AddX1_l,                /* 273: Signal */
  &bump_stim_B.AddX2_a,                /* 274: Signal */
  &bump_stim_B.x_j,                    /* 275: Signal */
  &bump_stim_B.y_h,                    /* 276: Signal */
  &bump_stim_B.z_k,                    /* 277: Signal */
  &bump_stim_B.dX_k,                   /* 278: Signal */
  &bump_stim_B.dY_p,                   /* 279: Signal */
  &bump_stim_B.dZ_n,                   /* 280: Signal */
  &bump_stim_B.product1_g,             /* 281: Signal */
  &bump_stim_B.product2_ft,            /* 282: Signal */
  &bump_stim_B.product3_a,             /* 283: Signal */
  &bump_stim_B.product4_b,             /* 284: Signal */
  &bump_stim_B.Add1_n,                 /* 285: Signal */
  &bump_stim_B.Add2_i,                 /* 286: Signal */
  &bump_stim_B.Add3_p,                 /* 287: Signal */
  &bump_stim_B.Add4_h,                 /* 288: Signal */
  &bump_stim_B.AddX_k,                 /* 289: Signal */
  &bump_stim_B.AddX1_a,                /* 290: Signal */
  &bump_stim_B.AddX2_n,                /* 291: Signal */
  &bump_stim_B.x,                      /* 292: Signal */
  &bump_stim_B.y_l,                    /* 293: Signal */
  &bump_stim_B.z_o,                    /* 294: Signal */
  &bump_stim_B.dX_f,                   /* 295: Signal */
  &bump_stim_B.dY_h,                   /* 296: Signal */
  &bump_stim_B.dZ_nw,                  /* 297: Signal */
  &bump_stim_B.product1_k,             /* 298: Signal */
  &bump_stim_B.product2_j,             /* 299: Signal */
  &bump_stim_B.product3_m,             /* 300: Signal */
  &bump_stim_B.product4_f,             /* 301: Signal */
  &bump_stim_B.Add1_b,                 /* 302: Signal */
  &bump_stim_B.Add2_d,                 /* 303: Signal */
  &bump_stim_B.Add3_cz,                /* 304: Signal */
  &bump_stim_B.Add4_c,                 /* 305: Signal */
  &bump_stim_B.AddX_p,                 /* 306: Signal */
  &bump_stim_B.AddX1_p,                /* 307: Signal */
  &bump_stim_B.AddX2_g,                /* 308: Signal */
  &bump_stim_B.x_p,                    /* 309: Signal */
  &bump_stim_B.y_m,                    /* 310: Signal */
  &bump_stim_B.z_pl,                   /* 311: Signal */
  &bump_stim_B.dX_kk,                  /* 312: Signal */
  &bump_stim_B.dY_l,                   /* 313: Signal */
  &bump_stim_B.dZ_m,                   /* 314: Signal */
  &bump_stim_B.product1_p,             /* 315: Signal */
  &bump_stim_B.product2_e,             /* 316: Signal */
  &bump_stim_B.product3_au,            /* 317: Signal */
  &bump_stim_B.product4_i,             /* 318: Signal */
  &bump_stim_B.Add1_p,                 /* 319: Signal */
  &bump_stim_B.Add2_dx,                /* 320: Signal */
  &bump_stim_B.Add3_bv,                /* 321: Signal */
  &bump_stim_B.Add4_a,                 /* 322: Signal */
  &bump_stim_B.AddX_e,                 /* 323: Signal */
  &bump_stim_B.AddX1_e,                /* 324: Signal */
  &bump_stim_B.AddX2_c,                /* 325: Signal */
  &bump_stim_B.x_b,                    /* 326: Signal */
  &bump_stim_B.y_d,                    /* 327: Signal */
  &bump_stim_B.z_m,                    /* 328: Signal */
  &bump_stim_B.dX_fv,                  /* 329: Signal */
  &bump_stim_B.dY_d,                   /* 330: Signal */
  &bump_stim_B.dZ_g,                   /* 331: Signal */
  &bump_stim_B.product1_gt,            /* 332: Signal */
  &bump_stim_B.product2_iv,            /* 333: Signal */
  &bump_stim_B.product3_n,             /* 334: Signal */
  &bump_stim_B.product4_n,             /* 335: Signal */
  &bump_stim_B.Add1_d,                 /* 336: Signal */
  &bump_stim_B.Add2_j,                 /* 337: Signal */
  &bump_stim_B.Add3_l,                 /* 338: Signal */
  &bump_stim_B.Add4_c0,                /* 339: Signal */
  &bump_stim_B.AddX_g,                 /* 340: Signal */
  &bump_stim_B.AddX1_c,                /* 341: Signal */
  &bump_stim_B.AddX2_h,                /* 342: Signal */
  &bump_stim_B.x_h,                    /* 343: Signal */
  &bump_stim_B.y_e,                    /* 344: Signal */
  &bump_stim_B.z_h,                    /* 345: Signal */
  &bump_stim_B.MathFunction[0],        /* 346: Signal */
  &bump_stim_B.Compare,                /* 347: Signal */
  &bump_stim_B.EnabledSubsystem.In1,   /* 348: Signal */
  &bump_stim_B.Compare_mv,             /* 349: Signal */
  &bump_stim_B.Compare_l,              /* 350: Signal */
  &bump_stim_B.Compare_p,              /* 351: Signal */
  &bump_stim_B.Compare_mc,             /* 352: Signal */
  &bump_stim_B.Compare_n,              /* 353: Signal */
  &bump_stim_B.EnabledSubsystem_c.In1, /* 354: Signal */
  &bump_stim_B.Compare_b1,             /* 355: Signal */
  &bump_stim_B.EnabledSubsystem_f.In1, /* 356: Signal */
  &bump_stim_B.Compare_k,              /* 357: Signal */
  &bump_stim_B.EnabledSubsystem_o.In1, /* 358: Signal */
  &bump_stim_B.Compare_g,              /* 359: Signal */
  &bump_stim_B.Compare_m5,             /* 360: Signal */
  &bump_stim_B.FixPtRelationalOperator,/* 361: Signal */
  &bump_stim_B.Uk1,                    /* 362: Signal */
  &bump_stim_B.EnabledSubsystem_l.In1, /* 363: Signal */
  &bump_stim_B.SampleandHold.In,       /* 364: Signal */
  &bump_stim_B.ScaleTouSec,            /* 365: Signal */
  &bump_stim_B.xPCTargetTime_c,        /* 366: Signal */
  &bump_stim_B.Subtract,               /* 367: Signal */
  &bump_stim_B.Switch_j,               /* 368: Signal */
  &bump_stim_B.Compare_me,             /* 369: Signal */
  &bump_stim_B.Compare_c,              /* 370: Signal */
  &bump_stim_B.Compare_a,              /* 371: Signal */
  &bump_stim_P.BehaviorBS_P1,          /* 372: Block Parameter */
  &bump_stim_P.BehaviorBS_P2,          /* 373: Block Parameter */
  &bump_stim_P.BehaviorBS_P3,          /* 374: Block Parameter */
  &bump_stim_P.BehaviorBS_P4,          /* 375: Block Parameter */
  &bump_stim_P.BehaviorBS_P5,          /* 376: Block Parameter */
  &bump_stim_P.BehaviorBS_P6,          /* 377: Block Parameter */
  &bump_stim_P.BehaviorBS_P7,          /* 378: Block Parameter */
  &bump_stim_P.BehaviorBS_P8,          /* 379: Block Parameter */
  &bump_stim_P.BehaviorBS_P9,          /* 380: Block Parameter */
  &bump_stim_P.BehaviorBS_P10,         /* 381: Block Parameter */
  &bump_stim_P.BehaviorBS_P11,         /* 382: Block Parameter */
  &bump_stim_P.BehaviorBS_P12,         /* 383: Block Parameter */
  &bump_stim_P.BehaviorBS_P13,         /* 384: Block Parameter */
  &bump_stim_P.BehaviorBS_P14,         /* 385: Block Parameter */
  &bump_stim_P.BehaviorBS_P15,         /* 386: Block Parameter */
  &bump_stim_P.BehaviorBS_P16,         /* 387: Block Parameter */
  &bump_stim_P.BehaviorBS_P17,         /* 388: Block Parameter */
  &bump_stim_P.BehaviorBS_P18,         /* 389: Block Parameter */
  &bump_stim_P.BehaviorBS_P19,         /* 390: Block Parameter */
  &bump_stim_P.BehaviorBS_P20,         /* 391: Block Parameter */
  &bump_stim_P.BehaviorBS_P21,         /* 392: Block Parameter */
  &bump_stim_P.BehaviorBS_P22,         /* 393: Block Parameter */
  &bump_stim_P.BehaviorBS_P23,         /* 394: Block Parameter */
  &bump_stim_P.XHighLimit_Value,       /* 395: Block Parameter */
  &bump_stim_P.XLowLimit_Value,        /* 396: Block Parameter */
  &bump_stim_P.YHighLimit_Value,       /* 397: Block Parameter */
  &bump_stim_P.YLowLimit_Value,        /* 398: Block Parameter */
  &bump_stim_P.DynamicAngle_Value,     /* 399: Block Parameter */
  &bump_stim_P.Load_Value_n,           /* 400: Block Parameter */
  &bump_stim_P.Off_Value,              /* 401: Block Parameter */
  &bump_stim_P.staticX_Value,          /* 402: Block Parameter */
  &bump_stim_P.staticY_Value,          /* 403: Block Parameter */
  &bump_stim_P.visAngle_Value,         /* 404: Block Parameter */
  &bump_stim_P.Gain_Gain_j,            /* 405: Block Parameter */
  &bump_stim_P.LorentzForceGain_Gain,  /* 406: Block Parameter */
  &bump_stim_P.DynamicAngle_Value_i,   /* 407: Block Parameter */
  &bump_stim_P.Load_Value,             /* 408: Block Parameter */
  &bump_stim_P.Off_Value_d,            /* 409: Block Parameter */
  &bump_stim_P.staticX_Value_j,        /* 410: Block Parameter */
  &bump_stim_P.staticY_Value_g,        /* 411: Block Parameter */
  &bump_stim_P.visAngle_Value_p,       /* 412: Block Parameter */
  &bump_stim_P.Gain_Gain_f,            /* 413: Block Parameter */
  &bump_stim_P.LorentzForceGain_Gain_l,/* 414: Block Parameter */
  &bump_stim_P.zeroX_Value,            /* 415: Block Parameter */
  &bump_stim_P.zeroY_Value,            /* 416: Block Parameter */
  &bump_stim_P.MG1_Gain,               /* 417: Block Parameter */
  &bump_stim_P.MG2_Gain,               /* 418: Block Parameter */
  &bump_stim_P.Memory_X0_n,            /* 419: Block Parameter */
  &bump_stim_P.PCI6025E_P1[0],         /* 420: Block Parameter */
  &bump_stim_P.PCI6025E_P2[0],         /* 421: Block Parameter */
  &bump_stim_P.PCI6025E_P3[0],         /* 422: Block Parameter */
  &bump_stim_P.PCI6025E_P4[0],         /* 423: Block Parameter */
  &bump_stim_P.PCI6025E_P5,            /* 424: Block Parameter */
  &bump_stim_P.PCI6025E_P6,            /* 425: Block Parameter */
  &bump_stim_P.PCI6025E_P7,            /* 426: Block Parameter */
  &bump_stim_P.RecenterFlag_Value,     /* 427: Block Parameter */
  &bump_stim_P.BoundingBoxViscosity_Gain,/* 428: Block Parameter */
  &bump_stim_P.JackpotChance_Value,    /* 429: Block Parameter */
  &bump_stim_P.RewardJackpot_Value,    /* 430: Block Parameter */
  &bump_stim_P.RewardTime_Value,       /* 431: Block Parameter */
  &bump_stim_P.UniformRandomNumber_Min,/* 432: Block Parameter */
  &bump_stim_P.UniformRandomNumber_Max,/* 433: Block Parameter */
  &bump_stim_P.UniformRandomNumber_Seed,/* 434: Block Parameter */
  &bump_stim_P.Gain_Gain_p,            /* 435: Block Parameter */
  &bump_stim_P.Gain1_Gain_a,           /* 436: Block Parameter */
  &bump_stim_P.Send_P1[0],             /* 437: Block Parameter */
  &bump_stim_P.Send_P2,                /* 438: Block Parameter */
  &bump_stim_P.Send_P3,                /* 439: Block Parameter */
  &bump_stim_P.Send_P4,                /* 440: Block Parameter */
  &bump_stim_P.UseTachs_Value,         /* 441: Block Parameter */
  &bump_stim_P.TachGain1_Gain,         /* 442: Block Parameter */
  &bump_stim_P.TachGain2_Gain,         /* 443: Block Parameter */
  &bump_stim_P.PCI6025EAD_P1[0],       /* 444: Block Parameter */
  &bump_stim_P.PCI6025EAD_P2[0],       /* 445: Block Parameter */
  &bump_stim_P.PCI6025EAD_P3[0],       /* 446: Block Parameter */
  &bump_stim_P.PCI6025EAD_P4,          /* 447: Block Parameter */
  &bump_stim_P.PCI6025EAD_P5,          /* 448: Block Parameter */
  &bump_stim_P.PCI6025EAD_P6,          /* 449: Block Parameter */
  &bump_stim_P.Switch_Threshold,       /* 450: Block Parameter */
  &bump_stim_P.elbowOffset_Value,      /* 451: Block Parameter */
  &bump_stim_P.shoulderOffset_Value,   /* 452: Block Parameter */
  &bump_stim_P.Gain_Gain,              /* 453: Block Parameter */
  &bump_stim_P.Gain1_Gain,             /* 454: Block Parameter */
  &bump_stim_P.PCIQUAD04_P1,           /* 455: Block Parameter */
  &bump_stim_P.PCIQUAD04_P2,           /* 456: Block Parameter */
  &bump_stim_P.PCIQUAD04_P3,           /* 457: Block Parameter */
  &bump_stim_P.PCIQUAD04_P4,           /* 458: Block Parameter */
  &bump_stim_P.PCIQUAD04_P5,           /* 459: Block Parameter */
  &bump_stim_P.PCIQUAD04_P6,           /* 460: Block Parameter */
  &bump_stim_P.PCIQUAD04_P7,           /* 461: Block Parameter */
  &bump_stim_P.PCIQUAD04_P8,           /* 462: Block Parameter */
  &bump_stim_P.PCIQUAD04_P9,           /* 463: Block Parameter */
  &bump_stim_P.PCIQUAD04_P10,          /* 464: Block Parameter */
  &bump_stim_P.PCIQUAD04_P11,          /* 465: Block Parameter */
  &bump_stim_P.PCIQUAD041_P1,          /* 466: Block Parameter */
  &bump_stim_P.PCIQUAD041_P2,          /* 467: Block Parameter */
  &bump_stim_P.PCIQUAD041_P3,          /* 468: Block Parameter */
  &bump_stim_P.PCIQUAD041_P4,          /* 469: Block Parameter */
  &bump_stim_P.PCIQUAD041_P5,          /* 470: Block Parameter */
  &bump_stim_P.PCIQUAD041_P6,          /* 471: Block Parameter */
  &bump_stim_P.PCIQUAD041_P7,          /* 472: Block Parameter */
  &bump_stim_P.PCIQUAD041_P8,          /* 473: Block Parameter */
  &bump_stim_P.PCIQUAD041_P9,          /* 474: Block Parameter */
  &bump_stim_P.PCIQUAD041_P10,         /* 475: Block Parameter */
  &bump_stim_P.PCIQUAD041_P11,         /* 476: Block Parameter */
  &bump_stim_P.Gain_Gain_pe,           /* 477: Block Parameter */
  &bump_stim_P.Inverter_Gain,          /* 478: Block Parameter */
  &bump_stim_P.Gain_Gain_c,            /* 479: Block Parameter */
  &bump_stim_P.Inverter_Gain_d,        /* 480: Block Parameter */
  &bump_stim_P.Constant_Value_e,       /* 481: Block Parameter */
  &bump_stim_P.Constant_Value_f,       /* 482: Block Parameter */
  &bump_stim_P.Gain_Gain_g,            /* 483: Block Parameter */
  &bump_stim_P.Time_Value,             /* 484: Block Parameter */
  &bump_stim_P.Memory_X0,              /* 485: Block Parameter */
  &bump_stim_P.DelayInput1_X0_fl,      /* 486: Block Parameter */
  &bump_stim_P.DelayInput1_X0_c,       /* 487: Block Parameter */
  &bump_stim_P.Gain1_Gain_j,           /* 488: Block Parameter */
  &bump_stim_P.Gain2_Gain_e,           /* 489: Block Parameter */
  &bump_stim_P.Gain3_Gain,             /* 490: Block Parameter */
  &bump_stim_P.Gain4_Gain,             /* 491: Block Parameter */
  &bump_stim_P.Saturation_UpperSat,    /* 492: Block Parameter */
  &bump_stim_P.Saturation_LowerSat,    /* 493: Block Parameter */
  &bump_stim_P.Saturation1_UpperSat,   /* 494: Block Parameter */
  &bump_stim_P.Saturation1_LowerSat,   /* 495: Block Parameter */
  &bump_stim_P.Logic_table[0],         /* 496: Block Parameter */
  &bump_stim_P.Memory_X0_nr,           /* 497: Block Parameter */
  &bump_stim_P.Time_Value_k,           /* 498: Block Parameter */
  &bump_stim_P.Memory_X0_l,            /* 499: Block Parameter */
  &bump_stim_P.Time_Value_p,           /* 500: Block Parameter */
  &bump_stim_P.Memory_X0_nn,           /* 501: Block Parameter */
  &bump_stim_P.Time_Value_l,           /* 502: Block Parameter */
  &bump_stim_P.Memory_X0_ll,           /* 503: Block Parameter */
  &bump_stim_P.DelayInput1_X0_f,       /* 504: Block Parameter */
  &bump_stim_P.Time_Value_j,           /* 505: Block Parameter */
  &bump_stim_P.Memory_X0_h,            /* 506: Block Parameter */
  &bump_stim_P.dG_Gain,                /* 507: Block Parameter */
  &bump_stim_P.DigitalFilter_ICRTP,    /* 508: Block Parameter */
  &bump_stim_P.DigitalFilter_RTP1COEFF[0],/* 509: Block Parameter */
  &bump_stim_P.DigitalFilter2_ICRTP,   /* 510: Block Parameter */
  &bump_stim_P.DigitalFilter2_RTP1COEFF[0],/* 511: Block Parameter */
  &bump_stim_P.dG_Gain_d,              /* 512: Block Parameter */
  &bump_stim_P.DigitalFilter_ICRTP_l,  /* 513: Block Parameter */
  &bump_stim_P.DigitalFilter_RTP1COEFF_o[0],/* 514: Block Parameter */
  &bump_stim_P.DigitalFilter2_ICRTP_e, /* 515: Block Parameter */
  &bump_stim_P.DigitalFilter2_RTP1COEFF_d[0],/* 516: Block Parameter */
  &bump_stim_P.AngleOffset_Value,      /* 517: Block Parameter */
  &bump_stim_P.Constant_Value_p,       /* 518: Block Parameter */
  &bump_stim_P.Constant2_Value,        /* 519: Block Parameter */
  &bump_stim_P.PortA_P1[0],            /* 520: Block Parameter */
  &bump_stim_P.PortA_P2,               /* 521: Block Parameter */
  &bump_stim_P.PortA_P3[0],            /* 522: Block Parameter */
  &bump_stim_P.PortA_P4[0],            /* 523: Block Parameter */
  &bump_stim_P.PortA_P5,               /* 524: Block Parameter */
  &bump_stim_P.PortA_P6,               /* 525: Block Parameter */
  &bump_stim_P.PortA_P7,               /* 526: Block Parameter */
  &bump_stim_P.PortA_P8,               /* 527: Block Parameter */
  &bump_stim_P.PortA_P9,               /* 528: Block Parameter */
  &bump_stim_P.PortB_P1[0],            /* 529: Block Parameter */
  &bump_stim_P.PortB_P2,               /* 530: Block Parameter */
  &bump_stim_P.PortB_P3[0],            /* 531: Block Parameter */
  &bump_stim_P.PortB_P4[0],            /* 532: Block Parameter */
  &bump_stim_P.PortB_P5,               /* 533: Block Parameter */
  &bump_stim_P.PortB_P6,               /* 534: Block Parameter */
  &bump_stim_P.PortB_P7,               /* 535: Block Parameter */
  &bump_stim_P.PortB_P8,               /* 536: Block Parameter */
  &bump_stim_P.PortB_P9,               /* 537: Block Parameter */
  &bump_stim_P.xPCTargetTime_P1_k,     /* 538: Block Parameter */
  &bump_stim_P.xPCTargetTime_P2_a,     /* 539: Block Parameter */
  &bump_stim_P.Switch_Threshold_m,     /* 540: Block Parameter */
  &bump_stim_P.L1_Value,               /* 541: Block Parameter */
  &bump_stim_P.L2_Value,               /* 542: Block Parameter */
  &bump_stim_P.xoffset_Value,          /* 543: Block Parameter */
  &bump_stim_P.yoffset_Value,          /* 544: Block Parameter */
  &bump_stim_P.Gain_Gain_m,            /* 545: Block Parameter */
  &bump_stim_P.Gain1_Gain_d,           /* 546: Block Parameter */
  &bump_stim_P.Gain2_Gain,             /* 547: Block Parameter */
  &bump_stim_P.beta_Value,             /* 548: Block Parameter */
  &bump_stim_P.rho_Value,              /* 549: Block Parameter */
  &bump_stim_P.sigma_Value,            /* 550: Block Parameter */
  &bump_stim_P.timescale_Value,        /* 551: Block Parameter */
  &bump_stim_P.x_X0_b,                 /* 552: Block Parameter */
  &bump_stim_P.y_X0,                   /* 553: Block Parameter */
  &bump_stim_P.z_X0,                   /* 554: Block Parameter */
  &bump_stim_P.beta_Value_f,           /* 555: Block Parameter */
  &bump_stim_P.rho_Value_p,            /* 556: Block Parameter */
  &bump_stim_P.sigma_Value_o,          /* 557: Block Parameter */
  &bump_stim_P.timescale_Value_i,      /* 558: Block Parameter */
  &bump_stim_P.x_X0_d,                 /* 559: Block Parameter */
  &bump_stim_P.y_X0_d,                 /* 560: Block Parameter */
  &bump_stim_P.z_X0_k,                 /* 561: Block Parameter */
  &bump_stim_P.beta_Value_n,           /* 562: Block Parameter */
  &bump_stim_P.rho_Value_c,            /* 563: Block Parameter */
  &bump_stim_P.sigma_Value_p,          /* 564: Block Parameter */
  &bump_stim_P.timescale_Value_n,      /* 565: Block Parameter */
  &bump_stim_P.x_X0_e,                 /* 566: Block Parameter */
  &bump_stim_P.y_X0_p,                 /* 567: Block Parameter */
  &bump_stim_P.z_X0_kn,                /* 568: Block Parameter */
  &bump_stim_P.beta_Value_b,           /* 569: Block Parameter */
  &bump_stim_P.rho_Value_k,            /* 570: Block Parameter */
  &bump_stim_P.sigma_Value_f,          /* 571: Block Parameter */
  &bump_stim_P.timescale_Value_h,      /* 572: Block Parameter */
  &bump_stim_P.x_X0_m,                 /* 573: Block Parameter */
  &bump_stim_P.y_X0_h,                 /* 574: Block Parameter */
  &bump_stim_P.z_X0_g,                 /* 575: Block Parameter */
  &bump_stim_P.beta_Value_g,           /* 576: Block Parameter */
  &bump_stim_P.rho_Value_pi,           /* 577: Block Parameter */
  &bump_stim_P.sigma_Value_h,          /* 578: Block Parameter */
  &bump_stim_P.timescale_Value_o,      /* 579: Block Parameter */
  &bump_stim_P.x_X0,                   /* 580: Block Parameter */
  &bump_stim_P.y_X0_g,                 /* 581: Block Parameter */
  &bump_stim_P.z_X0_h,                 /* 582: Block Parameter */
  &bump_stim_P.beta_Value_o,           /* 583: Block Parameter */
  &bump_stim_P.rho_Value_l,            /* 584: Block Parameter */
  &bump_stim_P.sigma_Value_d,          /* 585: Block Parameter */
  &bump_stim_P.timescale_Value_p,      /* 586: Block Parameter */
  &bump_stim_P.x_X0_c,                 /* 587: Block Parameter */
  &bump_stim_P.y_X0_k,                 /* 588: Block Parameter */
  &bump_stim_P.z_X0_j,                 /* 589: Block Parameter */
  &bump_stim_P.beta_Value_gu,          /* 590: Block Parameter */
  &bump_stim_P.rho_Value_m,            /* 591: Block Parameter */
  &bump_stim_P.sigma_Value_dt,         /* 592: Block Parameter */
  &bump_stim_P.timescale_Value_b,      /* 593: Block Parameter */
  &bump_stim_P.x_X0_p,                 /* 594: Block Parameter */
  &bump_stim_P.y_X0_f,                 /* 595: Block Parameter */
  &bump_stim_P.z_X0_l,                 /* 596: Block Parameter */
  &bump_stim_P.beta_Value_c,           /* 597: Block Parameter */
  &bump_stim_P.rho_Value_i,            /* 598: Block Parameter */
  &bump_stim_P.sigma_Value_l,          /* 599: Block Parameter */
  &bump_stim_P.timescale_Value_oi,     /* 600: Block Parameter */
  &bump_stim_P.x_X0_i,                 /* 601: Block Parameter */
  &bump_stim_P.y_X0_e,                 /* 602: Block Parameter */
  &bump_stim_P.z_X0_o,                 /* 603: Block Parameter */
  &bump_stim_P.Constant_Value,         /* 604: Block Parameter */
  &bump_stim_P.Constant_Value_a,       /* 605: Block Parameter */
  &bump_stim_P.DelayInput1_X0,         /* 606: Block Parameter */
  &bump_stim_P.Constant_Value_fq,      /* 607: Block Parameter */
  &bump_stim_P.Constant1_Value,        /* 608: Block Parameter */
  &bump_stim_P.ScaleTouSec_Gain,       /* 609: Block Parameter */
  &bump_stim_P.PCI6025E_P1_j[0],       /* 610: Block Parameter */
  &bump_stim_P.PCI6025E_P2_j[0],       /* 611: Block Parameter */
  &bump_stim_P.PCI6025E_P3_k[0],       /* 612: Block Parameter */
  &bump_stim_P.PCI6025E_P4_k,          /* 613: Block Parameter */
  &bump_stim_P.PCI6025E_P5_m,          /* 614: Block Parameter */
  &bump_stim_P.PCI6025E_P6_m,          /* 615: Block Parameter */
  &bump_stim_P.PCI6025E_P7_h,          /* 616: Block Parameter */
  &bump_stim_P.xPCTargetTime_P1,       /* 617: Block Parameter */
  &bump_stim_P.xPCTargetTime_P2,       /* 618: Block Parameter */
  &bump_stim_P.Constant_Value_j,       /* 619: Block Parameter */
  &bump_stim_P.Constant_Value_d        /* 620: Block Parameter */
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { NULL, 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_VECTOR, 0, 2 },

  { rtwCAPI_VECTOR, 2, 2 },

  { rtwCAPI_VECTOR, 4, 2 },

  { rtwCAPI_SCALAR, 6, 2 },

  { rtwCAPI_VECTOR, 8, 2 },

  { rtwCAPI_VECTOR, 10, 2 },

  { rtwCAPI_MATRIX_COL_MAJOR, 12, 2 },

  { rtwCAPI_VECTOR, 14, 2 },

  { rtwCAPI_VECTOR, 16, 2 },

  { rtwCAPI_MATRIX_COL_MAJOR, 18, 2 },

  { rtwCAPI_VECTOR, 20, 2 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  4,                                   /* 0 */
  1,                                   /* 1 */
  2,                                   /* 2 */
  1,                                   /* 3 */
  5,                                   /* 4 */
  1,                                   /* 5 */
  1,                                   /* 6 */
  1,                                   /* 7 */
  10,                                  /* 8 */
  1,                                   /* 9 */
  112,                                 /* 10 */
  1,                                   /* 11 */
  2,                                   /* 12 */
  2,                                   /* 13 */
  1,                                   /* 14 */
  2,                                   /* 15 */
  1,                                   /* 16 */
  11,                                  /* 17 */
  8,                                   /* 18 */
  2,                                   /* 19 */
  1,                                   /* 20 */
  8                                    /* 21 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0, 0.02
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    2, 0 },

  { NULL, NULL, -1, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 372 },

  { rtBlockParameters, 249,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void bump_stim_InitializeDataMapInfo(rtModel_bump_stim *bump_stim_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(bump_stim_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(bump_stim_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(bump_stim_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(bump_stim_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(bump_stim_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(bump_stim_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(bump_stim_rtM->DataMapInfo.mmi, 0);
}

/* EOF: bump_stim_capi.c */
