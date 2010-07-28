/*
 * center_out_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "center_out.mdl".
 *
 * Model Version              : 1.1201
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:09 2010
 */

#include "center_out.h"
#include "rtw_capi.h"
#include "center_out_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Matrix Concatenation1",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Behavior CO/p1",
    "", 0, 0, 1, 0, 0 },

  { 2, 0, "Behavior CO/p2",
    "", 1, 0, 2, 0, 0 },

  { 3, 0, "Behavior CO/p3",
    "", 2, 0, 3, 0, 0 },

  { 4, 0, "Behavior CO/p4",
    "", 3, 0, 4, 0, 0 },

  { 5, 0, "Behavior CO/p5",
    "", 4, 0, 3, 0, 0 },

  { 6, 0, "Behavior CO/p6",
    "", 5, 0, 1, 0, 0 },

  { 7, 0, "Behavior CO/p7",
    "", 6, 0, 0, 0, 0 },

  { 8, 0, "Behavior CO/p8",
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
  { 372, "Behavior CO",
    "P1", 0, 3, 0 },

  { 373, "Behavior CO",
    "P2", 0, 3, 0 },

  { 374, "Behavior CO",
    "P3", 0, 3, 0 },

  { 375, "Behavior CO",
    "P4", 0, 3, 0 },

  { 376, "Behavior CO",
    "P5", 0, 3, 0 },

  { 377, "Behavior CO",
    "P6", 0, 3, 0 },

  { 378, "Behavior CO",
    "P7", 0, 3, 0 },

  { 379, "Behavior CO",
    "P8", 0, 3, 0 },

  { 380, "Behavior CO",
    "P9", 0, 3, 0 },

  { 381, "Behavior CO",
    "P10", 0, 3, 0 },

  { 382, "Behavior CO",
    "P11", 0, 3, 0 },

  { 383, "Behavior CO",
    "P12", 0, 3, 0 },

  { 384, "Behavior CO",
    "P13", 0, 3, 0 },

  { 385, "Behavior CO",
    "P14", 0, 3, 0 },

  { 386, "Behavior CO",
    "P15", 0, 3, 0 },

  { 387, "Behavior CO",
    "P16", 0, 3, 0 },

  { 388, "Behavior CO",
    "P17", 0, 3, 0 },

  { 389, "Behavior CO",
    "P18", 0, 3, 0 },

  { 390, "BoundingBox/XHighLimit",
    "Value", 0, 3, 0 },

  { 391, "BoundingBox/XLowLimit",
    "Value", 0, 3, 0 },

  { 392, "BoundingBox/YHighLimit",
    "Value", 0, 3, 0 },

  { 393, "BoundingBox/YLowLimit",
    "Value", 0, 3, 0 },

  { 394, "Catch Force Generator/DynamicAngle",
    "Value", 0, 3, 0 },

  { 395, "Catch Force Generator/Load",
    "Value", 0, 3, 0 },

  { 396, "Catch Force Generator/Off",
    "Value", 0, 3, 0 },

  { 397, "Catch Force Generator/staticX",
    "Value", 0, 3, 0 },

  { 398, "Catch Force Generator/staticY",
    "Value", 0, 3, 0 },

  { 399, "Catch Force Generator/visAngle",
    "Value", 0, 3, 0 },

  { 400, "Catch Force Generator/Gain",
    "Gain", 0, 3, 0 },

  { 401, "Catch Force Generator/LorentzForceGain",
    "Gain", 0, 3, 0 },

  { 402, "Force Generator/DynamicAngle",
    "Value", 0, 3, 0 },

  { 403, "Force Generator/Load",
    "Value", 0, 3, 0 },

  { 404, "Force Generator/Off",
    "Value", 0, 3, 0 },

  { 405, "Force Generator/staticX",
    "Value", 0, 3, 0 },

  { 406, "Force Generator/staticY",
    "Value", 0, 3, 0 },

  { 407, "Force Generator/visAngle",
    "Value", 0, 3, 0 },

  { 408, "Force Generator/Gain",
    "Gain", 0, 3, 0 },

  { 409, "Force Generator/LorentzForceGain",
    "Gain", 0, 3, 0 },

  { 410, "Motor Control/zeroX",
    "Value", 0, 3, 0 },

  { 411, "Motor Control/zeroY",
    "Value", 0, 3, 0 },

  { 412, "Motor Control/MG1",
    "Gain", 0, 3, 0 },

  { 413, "Motor Control/MG2",
    "Gain", 0, 3, 0 },

  { 414, "Motor Control/Memory",
    "X0", 1, 3, 0 },

  { 415, "Motor Control/PCI-6025E ",
    "P1", 0, 7, 0 },

  { 416, "Motor Control/PCI-6025E ",
    "P2", 0, 7, 0 },

  { 417, "Motor Control/PCI-6025E ",
    "P3", 0, 7, 0 },

  { 418, "Motor Control/PCI-6025E ",
    "P4", 0, 7, 0 },

  { 419, "Motor Control/PCI-6025E ",
    "P5", 0, 3, 0 },

  { 420, "Motor Control/PCI-6025E ",
    "P6", 0, 3, 0 },

  { 421, "Motor Control/PCI-6025E ",
    "P7", 0, 3, 0 },

  { 422, "Recentering Subsystem/RecenterFlag",
    "Value", 0, 3, 0 },

  { 423, "Recentering Subsystem/Bounding Box Viscosity",
    "Gain", 0, 3, 0 },

  { 424, "RewardSbs/JackpotChance",
    "Value", 0, 3, 0 },

  { 425, "RewardSbs/RewardJackpot",
    "Value", 0, 3, 0 },

  { 426, "RewardSbs/RewardTime",
    "Value", 0, 3, 0 },

  { 427, "RewardSbs/Uniform Random Number",
    "Minimum", 0, 3, 0 },

  { 428, "RewardSbs/Uniform Random Number",
    "Maximum", 0, 3, 0 },

  { 429, "RewardSbs/Uniform Random Number",
    "Seed", 0, 3, 0 },

  { 430, "Target Peek/Gain",
    "Gain", 0, 3, 0 },

  { 431, "Target Peek/Gain1",
    "Gain", 0, 3, 0 },

  { 432, "UDPXmit/Send",
    "P1", 0, 8, 0 },

  { 433, "UDPXmit/Send",
    "P2", 0, 3, 0 },

  { 434, "UDPXmit/Send",
    "P3", 0, 3, 0 },

  { 435, "UDPXmit/Send",
    "P4", 0, 3, 0 },

  { 436, "Velocity Calculation/UseTachs",
    "Value", 0, 3, 0 },

  { 437, "Velocity Calculation/TachGain1",
    "Gain", 0, 3, 0 },

  { 438, "Velocity Calculation/TachGain2",
    "Gain", 0, 3, 0 },

  { 439, "Velocity Calculation/PCI-6025E AD",
    "P1", 0, 7, 0 },

  { 440, "Velocity Calculation/PCI-6025E AD",
    "P2", 0, 7, 0 },

  { 441, "Velocity Calculation/PCI-6025E AD",
    "P3", 0, 7, 0 },

  { 442, "Velocity Calculation/PCI-6025E AD",
    "P4", 0, 3, 0 },

  { 443, "Velocity Calculation/PCI-6025E AD",
    "P5", 0, 3, 0 },

  { 444, "Velocity Calculation/PCI-6025E AD",
    "P6", 0, 3, 0 },

  { 445, "Velocity Calculation/Switch",
    "Threshold", 0, 3, 0 },

  { 446, "XY Position Subsystem/elbowOffset",
    "Value", 0, 3, 0 },

  { 447, "XY Position Subsystem/shoulderOffset",
    "Value", 0, 3, 0 },

  { 448, "XY Position Subsystem/Gain",
    "Gain", 0, 3, 0 },

  { 449, "XY Position Subsystem/Gain1",
    "Gain", 0, 3, 0 },

  { 450, "XY Position Subsystem/PCI-QUAD04 ",
    "P1", 0, 3, 0 },

  { 451, "XY Position Subsystem/PCI-QUAD04 ",
    "P2", 0, 3, 0 },

  { 452, "XY Position Subsystem/PCI-QUAD04 ",
    "P3", 0, 3, 0 },

  { 453, "XY Position Subsystem/PCI-QUAD04 ",
    "P4", 0, 3, 0 },

  { 454, "XY Position Subsystem/PCI-QUAD04 ",
    "P5", 0, 3, 0 },

  { 455, "XY Position Subsystem/PCI-QUAD04 ",
    "P6", 0, 3, 0 },

  { 456, "XY Position Subsystem/PCI-QUAD04 ",
    "P7", 0, 3, 0 },

  { 457, "XY Position Subsystem/PCI-QUAD04 ",
    "P8", 0, 3, 0 },

  { 458, "XY Position Subsystem/PCI-QUAD04 ",
    "P9", 0, 3, 0 },

  { 459, "XY Position Subsystem/PCI-QUAD04 ",
    "P10", 0, 3, 0 },

  { 460, "XY Position Subsystem/PCI-QUAD04 ",
    "P11", 0, 3, 0 },

  { 461, "XY Position Subsystem/PCI-QUAD04 1",
    "P1", 0, 3, 0 },

  { 462, "XY Position Subsystem/PCI-QUAD04 1",
    "P2", 0, 3, 0 },

  { 463, "XY Position Subsystem/PCI-QUAD04 1",
    "P3", 0, 3, 0 },

  { 464, "XY Position Subsystem/PCI-QUAD04 1",
    "P4", 0, 3, 0 },

  { 465, "XY Position Subsystem/PCI-QUAD04 1",
    "P5", 0, 3, 0 },

  { 466, "XY Position Subsystem/PCI-QUAD04 1",
    "P6", 0, 3, 0 },

  { 467, "XY Position Subsystem/PCI-QUAD04 1",
    "P7", 0, 3, 0 },

  { 468, "XY Position Subsystem/PCI-QUAD04 1",
    "P8", 0, 3, 0 },

  { 469, "XY Position Subsystem/PCI-QUAD04 1",
    "P9", 0, 3, 0 },

  { 470, "XY Position Subsystem/PCI-QUAD04 1",
    "P10", 0, 3, 0 },

  { 471, "XY Position Subsystem/PCI-QUAD04 1",
    "P11", 0, 3, 0 },

  { 472, "Catch Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 3, 0 },

  { 473, "Catch Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 3, 0 },

  { 474, "Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 3, 0 },

  { 475, "Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 3, 0 },

  { 476, "Motor Control/Compare To Constant/Constant",
    "Value", 0, 3, 0 },

  { 477, "Motor Control/Compare To Constant1/Constant",
    "Value", 0, 3, 0 },

  { 478, "Motor Control/Force//Torque Transform/Gain",
    "Gain", 0, 3, 0 },

  { 479, "Motor Control/Schmidt/Time",
    "Value", 0, 3, 0 },

  { 480, "Motor Control/Schmidt/Memory",
    "X0", 1, 3, 0 },

  { 481, "Recentering Subsystem/Falling Edge/Delay Input1",
    "X0", 2, 3, 0 },

  { 482, "Recentering Subsystem/Falling Edge1/Delay Input1",
    "X0", 2, 3, 0 },

  { 483, "Recentering Subsystem/PD Controller/Gain1",
    "Gain", 0, 3, 0 },

  { 484, "Recentering Subsystem/PD Controller/Gain2",
    "Gain", 0, 3, 0 },

  { 485, "Recentering Subsystem/PD Controller/Gain3",
    "Gain", 0, 3, 0 },

  { 486, "Recentering Subsystem/PD Controller/Gain4",
    "Gain", 0, 3, 0 },

  { 487, "Recentering Subsystem/PD Controller/Saturation",
    "UpperLimit", 0, 3, 0 },

  { 488, "Recentering Subsystem/PD Controller/Saturation",
    "LowerLimit", 0, 3, 0 },

  { 489, "Recentering Subsystem/PD Controller/Saturation1",
    "UpperLimit", 0, 3, 0 },

  { 490, "Recentering Subsystem/PD Controller/Saturation1",
    "LowerLimit", 0, 3, 0 },

  { 491, "Recentering Subsystem/S-R Flip-Flop/Logic",
    "TruthTable", 1, 9, 0 },

  { 492, "Recentering Subsystem/S-R Flip-Flop/Memory",
    "X0", 1, 3, 0 },

  { 493, "Recentering Subsystem/Schmidt1/Time",
    "Value", 0, 3, 0 },

  { 494, "Recentering Subsystem/Schmidt1/Memory",
    "X0", 1, 3, 0 },

  { 495, "Recentering Subsystem/Schmidt2/Time",
    "Value", 0, 3, 0 },

  { 496, "Recentering Subsystem/Schmidt2/Memory",
    "X0", 1, 3, 0 },

  { 497, "Recentering Subsystem/Schmidt3/Time",
    "Value", 0, 3, 0 },

  { 498, "Recentering Subsystem/Schmidt3/Memory",
    "X0", 1, 3, 0 },

  { 499, "Recentering Subsystem/Start Moving/Delay Input1",
    "X0", 2, 3, 0 },

  { 500, "Recentering Subsystem/Timer/Time",
    "Value", 0, 3, 0 },

  { 501, "Recentering Subsystem/Timer/Memory",
    "X0", 1, 3, 0 },

  { 502, "Velocity Calculation/Pos2VelX/dG",
    "Gain", 0, 3, 0 },

  { 503, "Velocity Calculation/Pos2VelX/Digital Filter",
    "ICRTP", 0, 3, 0 },

  { 504, "Velocity Calculation/Pos2VelX/Digital Filter",
    "RTP1COEFF", 0, 8, 0 },

  { 505, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "ICRTP", 0, 3, 0 },

  { 506, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "RTP1COEFF", 0, 8, 0 },

  { 507, "Velocity Calculation/Pos2VelY/dG",
    "Gain", 0, 3, 0 },

  { 508, "Velocity Calculation/Pos2VelY/Digital Filter",
    "ICRTP", 0, 3, 0 },

  { 509, "Velocity Calculation/Pos2VelY/Digital Filter",
    "RTP1COEFF", 0, 8, 0 },

  { 510, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "ICRTP", 0, 3, 0 },

  { 511, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "RTP1COEFF", 0, 8, 0 },

  { 512, "XY Position Subsystem/Cursor Rotation/AngleOffset",
    "Value", 0, 3, 0 },

  { 513, "XY Position Subsystem/For Iterator Subsystem/Constant",
    "Value", 0, 3, 0 },

  { 514, "XY Position Subsystem/For Iterator Subsystem/Constant2",
    "Value", 0, 3, 0 },

  { 515, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P1", 0, 10, 0 },

  { 516, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P2", 0, 3, 0 },

  { 517, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P3", 0, 10, 0 },

  { 518, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P4", 0, 10, 0 },

  { 519, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P5", 0, 3, 0 },

  { 520, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P6", 0, 3, 0 },

  { 521, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P7", 0, 3, 0 },

  { 522, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P8", 0, 3, 0 },

  { 523, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P9", 0, 3, 0 },

  { 524, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P1", 0, 10, 0 },

  { 525, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P2", 0, 3, 0 },

  { 526, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P3", 0, 10, 0 },

  { 527, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P4", 0, 10, 0 },

  { 528, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P5", 0, 3, 0 },

  { 529, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P6", 0, 3, 0 },

  { 530, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P7", 0, 3, 0 },

  { 531, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P8", 0, 3, 0 },

  { 532, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P9", 0, 3, 0 },

  { 533, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 3, 0 },

  { 534, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 3, 0 },

  { 535, "XY Position Subsystem/For Iterator Subsystem/Switch",
    "Threshold", 0, 3, 0 },

  { 536, "XY Position Subsystem/Jacobian-Cartesian Transformation/L1",
    "Value", 0, 3, 0 },

  { 537, "XY Position Subsystem/Jacobian-Cartesian Transformation/L2",
    "Value", 0, 3, 0 },

  { 538, "XY Position Subsystem/Jacobian-Cartesian Transformation/xoffset",
    "Value", 0, 3, 0 },

  { 539, "XY Position Subsystem/Jacobian-Cartesian Transformation/yoffset",
    "Value", 0, 3, 0 },

  { 540, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain",
    "Gain", 0, 3, 0 },

  { 541, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain1",
    "Gain", 0, 3, 0 },

  { 542, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain2",
    "Gain", 0, 3, 0 },

  { 543, "Catch Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 3, 0 },

  { 544, "Catch Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 3, 0 },

  { 545, "Catch Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 3, 0 },

  { 546, "Catch Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 3, 0 },

  { 547, "Catch Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 3, 0 },

  { 548, "Catch Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 3, 0 },

  { 549, "Catch Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 3, 0 },

  { 550, "Catch Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 3, 0 },

  { 551, "Catch Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 3, 0 },

  { 552, "Catch Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 3, 0 },

  { 553, "Catch Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 3, 0 },

  { 554, "Catch Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 3, 0 },

  { 555, "Catch Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 3, 0 },

  { 556, "Catch Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 3, 0 },

  { 557, "Catch Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 3, 0 },

  { 558, "Catch Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 3, 0 },

  { 559, "Catch Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 3, 0 },

  { 560, "Catch Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 3, 0 },

  { 561, "Catch Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 3, 0 },

  { 562, "Catch Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 3, 0 },

  { 563, "Catch Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 3, 0 },

  { 564, "Catch Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 3, 0 },

  { 565, "Catch Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 3, 0 },

  { 566, "Catch Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 3, 0 },

  { 567, "Catch Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 3, 0 },

  { 568, "Catch Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 3, 0 },

  { 569, "Catch Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 3, 0 },

  { 570, "Catch Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 3, 0 },

  { 571, "Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 3, 0 },

  { 572, "Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 3, 0 },

  { 573, "Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 3, 0 },

  { 574, "Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 3, 0 },

  { 575, "Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 3, 0 },

  { 576, "Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 3, 0 },

  { 577, "Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 3, 0 },

  { 578, "Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 3, 0 },

  { 579, "Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 3, 0 },

  { 580, "Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 3, 0 },

  { 581, "Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 3, 0 },

  { 582, "Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 3, 0 },

  { 583, "Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 3, 0 },

  { 584, "Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 3, 0 },

  { 585, "Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 3, 0 },

  { 586, "Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 3, 0 },

  { 587, "Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 3, 0 },

  { 588, "Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 3, 0 },

  { 589, "Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 3, 0 },

  { 590, "Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 3, 0 },

  { 591, "Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 3, 0 },

  { 592, "Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 3, 0 },

  { 593, "Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 3, 0 },

  { 594, "Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 3, 0 },

  { 595, "Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 3, 0 },

  { 596, "Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 3, 0 },

  { 597, "Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 3, 0 },

  { 598, "Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 3, 0 },

  { 599, "Recentering Subsystem/No Movement/Compare To Constant2/Constant",
    "Value", 0, 3, 0 },

  { 600, "Recentering Subsystem/No Movement/Compare To Constant3/Constant",
    "Value", 0, 3, 0 },

  { 601, "Recentering Subsystem/Timer/Detect Fall Nonpositive/Delay Input1",
    "X0", 2, 3, 0 },

  { 602,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant",
    "Value", 0, 3, 0 },

  { 603,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant1",
    "Value", 0, 3, 0 },

  { 604,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "Gain", 0, 3, 0 },

  { 605,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P1", 0, 7, 0 },

  { 606,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P2", 0, 7, 0 },

  { 607,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P3", 0, 7, 0 },

  { 608,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P4", 0, 3, 0 },

  { 609,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P5", 0, 3, 0 },

  { 610,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P6", 0, 3, 0 },

  { 611,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P7", 0, 3, 0 },

  { 612,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 3, 0 },

  { 613,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 3, 0 },

  { 614,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Constant",
    "Value", 0, 3, 0 },

  { 615,
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
  &center_out_B.MatrixConcatenation1[0],/* 0: Signal */
  &center_out_B.BehaviorCO_o1[0],      /* 1: Signal */
  &center_out_B.BehaviorCO_o2[0],      /* 2: Signal */
  &center_out_B.BehaviorCO_o3,         /* 3: Signal */
  &center_out_B.BehaviorCO_o4[0],      /* 4: Signal */
  &center_out_B.BehaviorCO_o5,         /* 5: Signal */
  &center_out_B.BehaviorCO_o6[0],      /* 6: Signal */
  &center_out_B.BehaviorCO_o7[0],      /* 7: Signal */
  &center_out_B.BehaviorCO_o8[0],      /* 8: Signal */
  &center_out_B.LogicalOperator_j,     /* 9: Signal */
  &center_out_B.RelationalOperator_e,  /* 10: Signal */
  &center_out_B.RelationalOperator1,   /* 11: Signal */
  &center_out_B.RelationalOperator2,   /* 12: Signal */
  &center_out_B.RelationalOperator3,   /* 13: Signal */
  &center_out_B.Gain_d,                /* 14: Signal */
  &center_out_B.LorentzForceGain_o[0], /* 15: Signal */
  &center_out_B.DynamicAngleSwitch,    /* 16: Signal */
  &center_out_B.LoadSelectSwitch[0],   /* 17: Signal */
  &center_out_B.Gain_l,                /* 18: Signal */
  &center_out_B.LorentzForceGain[0],   /* 19: Signal */
  &center_out_B.MultiportSwitch[0],    /* 20: Signal */
  &center_out_B.dynamicAngleSwitch,    /* 21: Signal */
  &center_out_B.MatrixConcatenation[0],/* 22: Signal */
  &center_out_B.MG1,                   /* 23: Signal */
  &center_out_B.MG2,                   /* 24: Signal */
  &center_out_B.LogicalOperator1_bt,   /* 25: Signal */
  &center_out_B.Memory_o,              /* 26: Signal */
  &center_out_B.Switch1[0],            /* 27: Signal */
  &center_out_B.Switch2[0],            /* 28: Signal */
  &center_out_B.DataTypeConversion1,   /* 29: Signal */
  &center_out_B.DataTypeConversion2,   /* 30: Signal */
  &center_out_B.BoundingBoxViscosity[0],/* 31: Signal */
  &center_out_B.InBox,                 /* 32: Signal */
  &center_out_B.LogicalOperator_p,     /* 33: Signal */
  &center_out_B.LogicalOperator1_j,    /* 34: Signal */
  &center_out_B.LogicalOperator3_b,    /* 35: Signal */
  &center_out_B.LogicalOperator5_d,    /* 36: Signal */
  &center_out_B.LogicalOperator6,      /* 37: Signal */
  &center_out_B.NOT,                   /* 38: Signal */
  &center_out_B.Switch_o[0],           /* 39: Signal */
  &center_out_B.DataTypeConversion,    /* 40: Signal */
  &center_out_B.RelationalOperator_o,  /* 41: Signal */
  &center_out_B.Switch_m,              /* 42: Signal */
  &center_out_B.UniformRandomNumber,   /* 43: Signal */
  &center_out_B.Gain_m,                /* 44: Signal */
  &center_out_B.Gain1_h,               /* 45: Signal */
  &center_out_B.Add_p,                 /* 46: Signal */
  &center_out_B.Add1_l,                /* 47: Signal */
  &center_out_B.RateTransition[0],     /* 48: Signal */
  &center_out_B.Pack[0],               /* 49: Signal */
  &center_out_B.TachGain1,             /* 50: Signal */
  &center_out_B.TachGain2,             /* 51: Signal */
  &center_out_B.MatrixMultiply[0],     /* 52: Signal */
  &center_out_B.PCI6025EAD_o1,         /* 53: Signal */
  &center_out_B.PCI6025EAD_o2,         /* 54: Signal */
  &center_out_B.Switch[0],             /* 55: Signal */
  &center_out_B.Gain,                  /* 56: Signal */
  &center_out_B.Gain1,                 /* 57: Signal */
  &center_out_B.PCIQUAD04,             /* 58: Signal */
  &center_out_B.PCIQUAD041,            /* 59: Signal */
  &center_out_B.Sum1,                  /* 60: Signal */
  &center_out_B.Sum3,                  /* 61: Signal */
  &center_out_B.Add_g,                 /* 62: Signal */
  &center_out_B.Add1_j2,               /* 63: Signal */
  &center_out_B.Gain_lz[0],            /* 64: Signal */
  &center_out_B.Inverter_f[0],         /* 65: Signal */
  &center_out_B.Product_o,             /* 66: Signal */
  &center_out_B.Product1_i,            /* 67: Signal */
  &center_out_B.Product2_p,            /* 68: Signal */
  &center_out_B.Product3_b,            /* 69: Signal */
  &center_out_B.Add_c,                 /* 70: Signal */
  &center_out_B.Subtract_l,            /* 71: Signal */
  &center_out_B.cos_j,                 /* 72: Signal */
  &center_out_B.sin_f,                 /* 73: Signal */
  &center_out_B.Add,                   /* 74: Signal */
  &center_out_B.Add1_k,                /* 75: Signal */
  &center_out_B.Gain_k[0],             /* 76: Signal */
  &center_out_B.Inverter[0],           /* 77: Signal */
  &center_out_B.Product_h,             /* 78: Signal */
  &center_out_B.Product1_c,            /* 79: Signal */
  &center_out_B.Product2_k,            /* 80: Signal */
  &center_out_B.Product3_f,            /* 81: Signal */
  &center_out_B.Add_h,                 /* 82: Signal */
  &center_out_B.Subtract_k,            /* 83: Signal */
  &center_out_B.cos_l,                 /* 84: Signal */
  &center_out_B.sin_o,                 /* 85: Signal */
  &center_out_B.Compare_ci,            /* 86: Signal */
  &center_out_B.Compare_hx,            /* 87: Signal */
  &center_out_B.Gain_e[0],             /* 88: Signal */
  &center_out_B.MatrixMultiply_k[0],   /* 89: Signal */
  &center_out_B.Clock,                 /* 90: Signal */
  &center_out_B.LogicalOperator,       /* 91: Signal */
  &center_out_B.LogicalOperator1,      /* 92: Signal */
  &center_out_B.LogicalOperator2,      /* 93: Signal */
  &center_out_B.Memory,                /* 94: Signal */
  &center_out_B.RelationalOperator,    /* 95: Signal */
  &center_out_B.Sum,                   /* 96: Signal */
  &center_out_B.Compare_h,             /* 97: Signal */
  &center_out_B.Compare_o,             /* 98: Signal */
  &center_out_B.FixPtRelationalOperator_l,/* 99: Signal */
  &center_out_B.Uk1_o,                 /* 100: Signal */
  &center_out_B.FixPtRelationalOperator_i,/* 101: Signal */
  &center_out_B.Uk1_e,                 /* 102: Signal */
  &center_out_B.Abs2,                  /* 103: Signal */
  &center_out_B.Abs3,                  /* 104: Signal */
  &center_out_B.LogicalOperator1_a,    /* 105: Signal */
  &center_out_B.Gain1_i,               /* 106: Signal */
  &center_out_B.Gain2,                 /* 107: Signal */
  &center_out_B.Gain3,                 /* 108: Signal */
  &center_out_B.Gain4,                 /* 109: Signal */
  &center_out_B.Product_a,             /* 110: Signal */
  &center_out_B.Product1_k,            /* 111: Signal */
  &center_out_B.Saturation,            /* 112: Signal */
  &center_out_B.Saturation1,           /* 113: Signal */
  &center_out_B.Add_gi,                /* 114: Signal */
  &center_out_B.Add1_a,                /* 115: Signal */
  &center_out_B.Logic[0],              /* 116: Signal */
  &center_out_B.Memory_be,             /* 117: Signal */
  &center_out_B.Clock_e,               /* 118: Signal */
  &center_out_B.LogicalOperator_pm,    /* 119: Signal */
  &center_out_B.LogicalOperator1_i,    /* 120: Signal */
  &center_out_B.LogicalOperator2_h,    /* 121: Signal */
  &center_out_B.Memory_p,              /* 122: Signal */
  &center_out_B.RelationalOperator_ec, /* 123: Signal */
  &center_out_B.Sum_n,                 /* 124: Signal */
  &center_out_B.Clock_d,               /* 125: Signal */
  &center_out_B.LogicalOperator_i,     /* 126: Signal */
  &center_out_B.LogicalOperator1_be,   /* 127: Signal */
  &center_out_B.LogicalOperator2_g,    /* 128: Signal */
  &center_out_B.Memory_b,              /* 129: Signal */
  &center_out_B.RelationalOperator_j,  /* 130: Signal */
  &center_out_B.Sum_ju,                /* 131: Signal */
  &center_out_B.Clock_j,               /* 132: Signal */
  &center_out_B.LogicalOperator_o,     /* 133: Signal */
  &center_out_B.LogicalOperator1_b,    /* 134: Signal */
  &center_out_B.LogicalOperator2_f,    /* 135: Signal */
  &center_out_B.Memory_d,              /* 136: Signal */
  &center_out_B.RelationalOperator_a,  /* 137: Signal */
  &center_out_B.Sum_d,                 /* 138: Signal */
  &center_out_B.FixPtRelationalOperator_e,/* 139: Signal */
  &center_out_B.Uk1_f,                 /* 140: Signal */
  &center_out_B.Clock_o,               /* 141: Signal */
  &center_out_B.LogicalOperator_l,     /* 142: Signal */
  &center_out_B.LogicalOperator1_m,    /* 143: Signal */
  &center_out_B.LogicalOperator2_n,    /* 144: Signal */
  &center_out_B.LogicalOperator3,      /* 145: Signal */
  &center_out_B.LogicalOperator4,      /* 146: Signal */
  &center_out_B.LogicalOperator5,      /* 147: Signal */
  &center_out_B.Memory_pz,             /* 148: Signal */
  &center_out_B.RelationalOperator_i,  /* 149: Signal */
  &center_out_B.Sum_h,                 /* 150: Signal */
  &center_out_B.SampleandHold_e.In,    /* 151: Signal */
  &center_out_B.Clock_a,               /* 152: Signal */
  &center_out_B.RelationalOperator_h,  /* 153: Signal */
  &center_out_B.Sum_c,                 /* 154: Signal */
  &center_out_B.Derivative,            /* 155: Signal */
  &center_out_B.dG,                    /* 156: Signal */
  &center_out_B.DigitalFilter,         /* 157: Signal */
  &center_out_B.DigitalFilter2,        /* 158: Signal */
  &center_out_B.Derivative_m,          /* 159: Signal */
  &center_out_B.dG_f,                  /* 160: Signal */
  &center_out_B.DigitalFilter_m,       /* 161: Signal */
  &center_out_B.DigitalFilter2_l,      /* 162: Signal */
  &center_out_B.sqrtu1u1u2u2,          /* 163: Signal */
  &center_out_B.Product_l,             /* 164: Signal */
  &center_out_B.Product1_d,            /* 165: Signal */
  &center_out_B.Sum_j,                 /* 166: Signal */
  &center_out_B.TrigonometricFunction_d,/* 167: Signal */
  &center_out_B.TrigonometricFunction1_p,/* 168: Signal */
  &center_out_B.TrigonometricFunction2_j,/* 169: Signal */
  &center_out_B.ForIterator,           /* 170: Signal */
  &center_out_B.SerialConverter,       /* 171: Signal */
  &center_out_B.ToBits_o1,             /* 172: Signal */
  &center_out_B.ToBits_o2,             /* 173: Signal */
  &center_out_B.ToBits_o3,             /* 174: Signal */
  &center_out_B.ToBits_o4,             /* 175: Signal */
  &center_out_B.ToBits_o5,             /* 176: Signal */
  &center_out_B.ToBits_o6,             /* 177: Signal */
  &center_out_B.ToBits_o7,             /* 178: Signal */
  &center_out_B.ToBits_o8,             /* 179: Signal */
  &center_out_B.ToBits1_o1,            /* 180: Signal */
  &center_out_B.ToBits1_o2,            /* 181: Signal */
  &center_out_B.ToBits1_o3,            /* 182: Signal */
  &center_out_B.ToBits1_o4,            /* 183: Signal */
  &center_out_B.ToBits1_o5,            /* 184: Signal */
  &center_out_B.ToBits1_o6,            /* 185: Signal */
  &center_out_B.ToBits1_o7,            /* 186: Signal */
  &center_out_B.ToBits1_o8,            /* 187: Signal */
  &center_out_B.xPCTargetTime,         /* 188: Signal */
  &center_out_B.Add_m,                 /* 189: Signal */
  &center_out_B.Add1_dz,               /* 190: Signal */
  &center_out_B.Switch_e,              /* 191: Signal */
  &center_out_B.MatrixConcatenate2[0], /* 192: Signal */
  &center_out_B.MatrixConcatenate2[0], /* 193: Signal */
  &center_out_B.MatrixConcatenate2[0], /* 194: Signal */
  &center_out_B.MatrixConcatenate2[0], /* 195: Signal */
  &center_out_B.MatrixConcatenate2[0], /* 196: Signal */
  &center_out_B.MatrixConcatenate2[0], /* 197: Signal */
  &center_out_B.Product,               /* 198: Signal */
  &center_out_B.Product1,              /* 199: Signal */
  &center_out_B.Product2,              /* 200: Signal */
  &center_out_B.Product3,              /* 201: Signal */
  &center_out_B.Sum1_k,                /* 202: Signal */
  &center_out_B.Sum2,                  /* 203: Signal */
  &center_out_B.Sum3_d,                /* 204: Signal */
  &center_out_B.Sum4,                  /* 205: Signal */
  &center_out_B.TrigonometricFunction, /* 206: Signal */
  &center_out_B.TrigonometricFunction1,/* 207: Signal */
  &center_out_B.TrigonometricFunction2,/* 208: Signal */
  &center_out_B.TrigonometricFunction3,/* 209: Signal */
  &center_out_B.dX,                    /* 210: Signal */
  &center_out_B.dY,                    /* 211: Signal */
  &center_out_B.dZ,                    /* 212: Signal */
  &center_out_B.product1,              /* 213: Signal */
  &center_out_B.product2,              /* 214: Signal */
  &center_out_B.product3,              /* 215: Signal */
  &center_out_B.product4,              /* 216: Signal */
  &center_out_B.Add1,                  /* 217: Signal */
  &center_out_B.Add2,                  /* 218: Signal */
  &center_out_B.Add3,                  /* 219: Signal */
  &center_out_B.Add4,                  /* 220: Signal */
  &center_out_B.AddX,                  /* 221: Signal */
  &center_out_B.AddX1,                 /* 222: Signal */
  &center_out_B.AddX2,                 /* 223: Signal */
  &center_out_B.x_g,                   /* 224: Signal */
  &center_out_B.y,                     /* 225: Signal */
  &center_out_B.z,                     /* 226: Signal */
  &center_out_B.dX_o,                  /* 227: Signal */
  &center_out_B.dY_e,                  /* 228: Signal */
  &center_out_B.dZ_j,                  /* 229: Signal */
  &center_out_B.product1_j,            /* 230: Signal */
  &center_out_B.product2_b,            /* 231: Signal */
  &center_out_B.product3_b,            /* 232: Signal */
  &center_out_B.product4_e,            /* 233: Signal */
  &center_out_B.Add1_m,                /* 234: Signal */
  &center_out_B.Add2_i,                /* 235: Signal */
  &center_out_B.Add3_i,                /* 236: Signal */
  &center_out_B.Add4_a,                /* 237: Signal */
  &center_out_B.AddX_m,                /* 238: Signal */
  &center_out_B.AddX1_g,               /* 239: Signal */
  &center_out_B.AddX2_n,               /* 240: Signal */
  &center_out_B.x_f,                   /* 241: Signal */
  &center_out_B.y_l,                   /* 242: Signal */
  &center_out_B.z_h,                   /* 243: Signal */
  &center_out_B.dX_j,                  /* 244: Signal */
  &center_out_B.dY_eo,                 /* 245: Signal */
  &center_out_B.dZ_b,                  /* 246: Signal */
  &center_out_B.product1_a,            /* 247: Signal */
  &center_out_B.product2_k,            /* 248: Signal */
  &center_out_B.product3_i,            /* 249: Signal */
  &center_out_B.product4_a,            /* 250: Signal */
  &center_out_B.Add1_d,                /* 251: Signal */
  &center_out_B.Add2_e,                /* 252: Signal */
  &center_out_B.Add3_p,                /* 253: Signal */
  &center_out_B.Add4_h,                /* 254: Signal */
  &center_out_B.AddX_l,                /* 255: Signal */
  &center_out_B.AddX1_a,               /* 256: Signal */
  &center_out_B.AddX2_a,               /* 257: Signal */
  &center_out_B.x_p,                   /* 258: Signal */
  &center_out_B.y_m,                   /* 259: Signal */
  &center_out_B.z_a,                   /* 260: Signal */
  &center_out_B.dX_l,                  /* 261: Signal */
  &center_out_B.dY_b,                  /* 262: Signal */
  &center_out_B.dZ_m,                  /* 263: Signal */
  &center_out_B.product1_p,            /* 264: Signal */
  &center_out_B.product2_g,            /* 265: Signal */
  &center_out_B.product3_j,            /* 266: Signal */
  &center_out_B.product4_j,            /* 267: Signal */
  &center_out_B.Add1_n,                /* 268: Signal */
  &center_out_B.Add2_d,                /* 269: Signal */
  &center_out_B.Add3_k,                /* 270: Signal */
  &center_out_B.Add4_f,                /* 271: Signal */
  &center_out_B.AddX_d,                /* 272: Signal */
  &center_out_B.AddX1_d,               /* 273: Signal */
  &center_out_B.AddX2_l,               /* 274: Signal */
  &center_out_B.x_g2,                  /* 275: Signal */
  &center_out_B.y_d,                   /* 276: Signal */
  &center_out_B.z_l,                   /* 277: Signal */
  &center_out_B.dX_g,                  /* 278: Signal */
  &center_out_B.dY_i,                  /* 279: Signal */
  &center_out_B.dZ_i,                  /* 280: Signal */
  &center_out_B.product1_m,            /* 281: Signal */
  &center_out_B.product2_h,            /* 282: Signal */
  &center_out_B.product3_m,            /* 283: Signal */
  &center_out_B.product4_b,            /* 284: Signal */
  &center_out_B.Add1_nw,               /* 285: Signal */
  &center_out_B.Add2_p,                /* 286: Signal */
  &center_out_B.Add3_k3,               /* 287: Signal */
  &center_out_B.Add4_l,                /* 288: Signal */
  &center_out_B.AddX_k,                /* 289: Signal */
  &center_out_B.AddX1_e,               /* 290: Signal */
  &center_out_B.AddX2_c,               /* 291: Signal */
  &center_out_B.x,                     /* 292: Signal */
  &center_out_B.y_j,                   /* 293: Signal */
  &center_out_B.z_f,                   /* 294: Signal */
  &center_out_B.dX_e,                  /* 295: Signal */
  &center_out_B.dY_bm,                 /* 296: Signal */
  &center_out_B.dZ_o,                  /* 297: Signal */
  &center_out_B.product1_d,            /* 298: Signal */
  &center_out_B.product2_ka,           /* 299: Signal */
  &center_out_B.product3_l,            /* 300: Signal */
  &center_out_B.product4_n,            /* 301: Signal */
  &center_out_B.Add1_b,                /* 302: Signal */
  &center_out_B.Add2_db,               /* 303: Signal */
  &center_out_B.Add3_pw,               /* 304: Signal */
  &center_out_B.Add4_c,                /* 305: Signal */
  &center_out_B.AddX_ko,               /* 306: Signal */
  &center_out_B.AddX1_b,               /* 307: Signal */
  &center_out_B.AddX2_f,               /* 308: Signal */
  &center_out_B.x_j,                   /* 309: Signal */
  &center_out_B.y_e,                   /* 310: Signal */
  &center_out_B.z_o,                   /* 311: Signal */
  &center_out_B.dX_b,                  /* 312: Signal */
  &center_out_B.dY_k,                  /* 313: Signal */
  &center_out_B.dZ_f,                  /* 314: Signal */
  &center_out_B.product1_d2,           /* 315: Signal */
  &center_out_B.product2_o,            /* 316: Signal */
  &center_out_B.product3_a,            /* 317: Signal */
  &center_out_B.product4_n1,           /* 318: Signal */
  &center_out_B.Add1_j,                /* 319: Signal */
  &center_out_B.Add2_a,                /* 320: Signal */
  &center_out_B.Add3_l,                /* 321: Signal */
  &center_out_B.Add4_n,                /* 322: Signal */
  &center_out_B.AddX_lw,               /* 323: Signal */
  &center_out_B.AddX1_aj,              /* 324: Signal */
  &center_out_B.AddX2_k,               /* 325: Signal */
  &center_out_B.x_k,                   /* 326: Signal */
  &center_out_B.y_e3,                  /* 327: Signal */
  &center_out_B.z_b,                   /* 328: Signal */
  &center_out_B.dX_bv,                 /* 329: Signal */
  &center_out_B.dY_f,                  /* 330: Signal */
  &center_out_B.dZ_ms,                 /* 331: Signal */
  &center_out_B.product1_d3,           /* 332: Signal */
  &center_out_B.product2_i,            /* 333: Signal */
  &center_out_B.product3_be,           /* 334: Signal */
  &center_out_B.product4_a1,           /* 335: Signal */
  &center_out_B.Add1_e,                /* 336: Signal */
  &center_out_B.Add2_as,               /* 337: Signal */
  &center_out_B.Add3_e,                /* 338: Signal */
  &center_out_B.Add4_e,                /* 339: Signal */
  &center_out_B.AddX_n,                /* 340: Signal */
  &center_out_B.AddX1_h,               /* 341: Signal */
  &center_out_B.AddX2_e,               /* 342: Signal */
  &center_out_B.x_l,                   /* 343: Signal */
  &center_out_B.y_n,                   /* 344: Signal */
  &center_out_B.z_bj,                  /* 345: Signal */
  &center_out_B.MathFunction[0],       /* 346: Signal */
  &center_out_B.Compare,               /* 347: Signal */
  &center_out_B.EnabledSubsystem.In1,  /* 348: Signal */
  &center_out_B.Compare_p,             /* 349: Signal */
  &center_out_B.Compare_g,             /* 350: Signal */
  &center_out_B.Compare_l,             /* 351: Signal */
  &center_out_B.Compare_e,             /* 352: Signal */
  &center_out_B.Compare_c,             /* 353: Signal */
  &center_out_B.EnabledSubsystem_i.In1,/* 354: Signal */
  &center_out_B.Compare_mk,            /* 355: Signal */
  &center_out_B.EnabledSubsystem_ir.In1,/* 356: Signal */
  &center_out_B.Compare_m2,            /* 357: Signal */
  &center_out_B.EnabledSubsystem_n.In1,/* 358: Signal */
  &center_out_B.Compare_m,             /* 359: Signal */
  &center_out_B.Compare_b,             /* 360: Signal */
  &center_out_B.FixPtRelationalOperator,/* 361: Signal */
  &center_out_B.Uk1,                   /* 362: Signal */
  &center_out_B.EnabledSubsystem_l.In1,/* 363: Signal */
  &center_out_B.SampleandHold.In,      /* 364: Signal */
  &center_out_B.ScaleTouSec,           /* 365: Signal */
  &center_out_B.xPCTargetTime_d,       /* 366: Signal */
  &center_out_B.Subtract,              /* 367: Signal */
  &center_out_B.Switch_a,              /* 368: Signal */
  &center_out_B.Compare_d,             /* 369: Signal */
  &center_out_B.Compare_hn,            /* 370: Signal */
  &center_out_B.Compare_i,             /* 371: Signal */
  &center_out_P.BehaviorCO_P1,         /* 372: Block Parameter */
  &center_out_P.BehaviorCO_P2,         /* 373: Block Parameter */
  &center_out_P.BehaviorCO_P3,         /* 374: Block Parameter */
  &center_out_P.BehaviorCO_P4,         /* 375: Block Parameter */
  &center_out_P.BehaviorCO_P5,         /* 376: Block Parameter */
  &center_out_P.BehaviorCO_P6,         /* 377: Block Parameter */
  &center_out_P.BehaviorCO_P7,         /* 378: Block Parameter */
  &center_out_P.BehaviorCO_P8,         /* 379: Block Parameter */
  &center_out_P.BehaviorCO_P9,         /* 380: Block Parameter */
  &center_out_P.BehaviorCO_P10,        /* 381: Block Parameter */
  &center_out_P.BehaviorCO_P11,        /* 382: Block Parameter */
  &center_out_P.BehaviorCO_P12,        /* 383: Block Parameter */
  &center_out_P.BehaviorCO_P13,        /* 384: Block Parameter */
  &center_out_P.BehaviorCO_P14,        /* 385: Block Parameter */
  &center_out_P.BehaviorCO_P15,        /* 386: Block Parameter */
  &center_out_P.BehaviorCO_P16,        /* 387: Block Parameter */
  &center_out_P.BehaviorCO_P17,        /* 388: Block Parameter */
  &center_out_P.BehaviorCO_P18,        /* 389: Block Parameter */
  &center_out_P.XHighLimit_Value,      /* 390: Block Parameter */
  &center_out_P.XLowLimit_Value,       /* 391: Block Parameter */
  &center_out_P.YHighLimit_Value,      /* 392: Block Parameter */
  &center_out_P.YLowLimit_Value,       /* 393: Block Parameter */
  &center_out_P.DynamicAngle_Value,    /* 394: Block Parameter */
  &center_out_P.Load_Value_m,          /* 395: Block Parameter */
  &center_out_P.Off_Value,             /* 396: Block Parameter */
  &center_out_P.staticX_Value,         /* 397: Block Parameter */
  &center_out_P.staticY_Value,         /* 398: Block Parameter */
  &center_out_P.visAngle_Value,        /* 399: Block Parameter */
  &center_out_P.Gain_Gain_i,           /* 400: Block Parameter */
  &center_out_P.LorentzForceGain_Gain, /* 401: Block Parameter */
  &center_out_P.DynamicAngle_Value_k,  /* 402: Block Parameter */
  &center_out_P.Load_Value,            /* 403: Block Parameter */
  &center_out_P.Off_Value_k,           /* 404: Block Parameter */
  &center_out_P.staticX_Value_c,       /* 405: Block Parameter */
  &center_out_P.staticY_Value_n,       /* 406: Block Parameter */
  &center_out_P.visAngle_Value_g,      /* 407: Block Parameter */
  &center_out_P.Gain_Gain_g,           /* 408: Block Parameter */
  &center_out_P.LorentzForceGain_Gain_j,/* 409: Block Parameter */
  &center_out_P.zeroX_Value,           /* 410: Block Parameter */
  &center_out_P.zeroY_Value,           /* 411: Block Parameter */
  &center_out_P.MG1_Gain,              /* 412: Block Parameter */
  &center_out_P.MG2_Gain,              /* 413: Block Parameter */
  &center_out_P.Memory_X0_e,           /* 414: Block Parameter */
  &center_out_P.PCI6025E_P1[0],        /* 415: Block Parameter */
  &center_out_P.PCI6025E_P2[0],        /* 416: Block Parameter */
  &center_out_P.PCI6025E_P3[0],        /* 417: Block Parameter */
  &center_out_P.PCI6025E_P4[0],        /* 418: Block Parameter */
  &center_out_P.PCI6025E_P5,           /* 419: Block Parameter */
  &center_out_P.PCI6025E_P6,           /* 420: Block Parameter */
  &center_out_P.PCI6025E_P7,           /* 421: Block Parameter */
  &center_out_P.RecenterFlag_Value,    /* 422: Block Parameter */
  &center_out_P.BoundingBoxViscosity_Gain,/* 423: Block Parameter */
  &center_out_P.JackpotChance_Value,   /* 424: Block Parameter */
  &center_out_P.RewardJackpot_Value,   /* 425: Block Parameter */
  &center_out_P.RewardTime_Value,      /* 426: Block Parameter */
  &center_out_P.UniformRandomNumber_Min,/* 427: Block Parameter */
  &center_out_P.UniformRandomNumber_Max,/* 428: Block Parameter */
  &center_out_P.UniformRandomNumber_Seed,/* 429: Block Parameter */
  &center_out_P.Gain_Gain_l,           /* 430: Block Parameter */
  &center_out_P.Gain1_Gain_g,          /* 431: Block Parameter */
  &center_out_P.Send_P1[0],            /* 432: Block Parameter */
  &center_out_P.Send_P2,               /* 433: Block Parameter */
  &center_out_P.Send_P3,               /* 434: Block Parameter */
  &center_out_P.Send_P4,               /* 435: Block Parameter */
  &center_out_P.UseTachs_Value,        /* 436: Block Parameter */
  &center_out_P.TachGain1_Gain,        /* 437: Block Parameter */
  &center_out_P.TachGain2_Gain,        /* 438: Block Parameter */
  &center_out_P.PCI6025EAD_P1[0],      /* 439: Block Parameter */
  &center_out_P.PCI6025EAD_P2[0],      /* 440: Block Parameter */
  &center_out_P.PCI6025EAD_P3[0],      /* 441: Block Parameter */
  &center_out_P.PCI6025EAD_P4,         /* 442: Block Parameter */
  &center_out_P.PCI6025EAD_P5,         /* 443: Block Parameter */
  &center_out_P.PCI6025EAD_P6,         /* 444: Block Parameter */
  &center_out_P.Switch_Threshold,      /* 445: Block Parameter */
  &center_out_P.elbowOffset_Value,     /* 446: Block Parameter */
  &center_out_P.shoulderOffset_Value,  /* 447: Block Parameter */
  &center_out_P.Gain_Gain,             /* 448: Block Parameter */
  &center_out_P.Gain1_Gain,            /* 449: Block Parameter */
  &center_out_P.PCIQUAD04_P1,          /* 450: Block Parameter */
  &center_out_P.PCIQUAD04_P2,          /* 451: Block Parameter */
  &center_out_P.PCIQUAD04_P3,          /* 452: Block Parameter */
  &center_out_P.PCIQUAD04_P4,          /* 453: Block Parameter */
  &center_out_P.PCIQUAD04_P5,          /* 454: Block Parameter */
  &center_out_P.PCIQUAD04_P6,          /* 455: Block Parameter */
  &center_out_P.PCIQUAD04_P7,          /* 456: Block Parameter */
  &center_out_P.PCIQUAD04_P8,          /* 457: Block Parameter */
  &center_out_P.PCIQUAD04_P9,          /* 458: Block Parameter */
  &center_out_P.PCIQUAD04_P10,         /* 459: Block Parameter */
  &center_out_P.PCIQUAD04_P11,         /* 460: Block Parameter */
  &center_out_P.PCIQUAD041_P1,         /* 461: Block Parameter */
  &center_out_P.PCIQUAD041_P2,         /* 462: Block Parameter */
  &center_out_P.PCIQUAD041_P3,         /* 463: Block Parameter */
  &center_out_P.PCIQUAD041_P4,         /* 464: Block Parameter */
  &center_out_P.PCIQUAD041_P5,         /* 465: Block Parameter */
  &center_out_P.PCIQUAD041_P6,         /* 466: Block Parameter */
  &center_out_P.PCIQUAD041_P7,         /* 467: Block Parameter */
  &center_out_P.PCIQUAD041_P8,         /* 468: Block Parameter */
  &center_out_P.PCIQUAD041_P9,         /* 469: Block Parameter */
  &center_out_P.PCIQUAD041_P10,        /* 470: Block Parameter */
  &center_out_P.PCIQUAD041_P11,        /* 471: Block Parameter */
  &center_out_P.Gain_Gain_iu,          /* 472: Block Parameter */
  &center_out_P.Inverter_Gain,         /* 473: Block Parameter */
  &center_out_P.Gain_Gain_lp,          /* 474: Block Parameter */
  &center_out_P.Inverter_Gain_o,       /* 475: Block Parameter */
  &center_out_P.Constant_Value_h,      /* 476: Block Parameter */
  &center_out_P.Constant_Value_k,      /* 477: Block Parameter */
  &center_out_P.Gain_Gain_d,           /* 478: Block Parameter */
  &center_out_P.Time_Value,            /* 479: Block Parameter */
  &center_out_P.Memory_X0,             /* 480: Block Parameter */
  &center_out_P.DelayInput1_X0_g,      /* 481: Block Parameter */
  &center_out_P.DelayInput1_X0_e,      /* 482: Block Parameter */
  &center_out_P.Gain1_Gain_p,          /* 483: Block Parameter */
  &center_out_P.Gain2_Gain_e,          /* 484: Block Parameter */
  &center_out_P.Gain3_Gain,            /* 485: Block Parameter */
  &center_out_P.Gain4_Gain,            /* 486: Block Parameter */
  &center_out_P.Saturation_UpperSat,   /* 487: Block Parameter */
  &center_out_P.Saturation_LowerSat,   /* 488: Block Parameter */
  &center_out_P.Saturation1_UpperSat,  /* 489: Block Parameter */
  &center_out_P.Saturation1_LowerSat,  /* 490: Block Parameter */
  &center_out_P.Logic_table[0],        /* 491: Block Parameter */
  &center_out_P.Memory_X0_a,           /* 492: Block Parameter */
  &center_out_P.Time_Value_hl,         /* 493: Block Parameter */
  &center_out_P.Memory_X0_ew,          /* 494: Block Parameter */
  &center_out_P.Time_Value_d,          /* 495: Block Parameter */
  &center_out_P.Memory_X0_l,           /* 496: Block Parameter */
  &center_out_P.Time_Value_l,          /* 497: Block Parameter */
  &center_out_P.Memory_X0_b,           /* 498: Block Parameter */
  &center_out_P.DelayInput1_X0_i,      /* 499: Block Parameter */
  &center_out_P.Time_Value_h,          /* 500: Block Parameter */
  &center_out_P.Memory_X0_i,           /* 501: Block Parameter */
  &center_out_P.dG_Gain,               /* 502: Block Parameter */
  &center_out_P.DigitalFilter_ICRTP,   /* 503: Block Parameter */
  &center_out_P.DigitalFilter_RTP1COEFF[0],/* 504: Block Parameter */
  &center_out_P.DigitalFilter2_ICRTP,  /* 505: Block Parameter */
  &center_out_P.DigitalFilter2_RTP1COEFF[0],/* 506: Block Parameter */
  &center_out_P.dG_Gain_a,             /* 507: Block Parameter */
  &center_out_P.DigitalFilter_ICRTP_h, /* 508: Block Parameter */
  &center_out_P.DigitalFilter_RTP1COEFF_n[0],/* 509: Block Parameter */
  &center_out_P.DigitalFilter2_ICRTP_i,/* 510: Block Parameter */
  &center_out_P.DigitalFilter2_RTP1COEFF_n[0],/* 511: Block Parameter */
  &center_out_P.AngleOffset_Value,     /* 512: Block Parameter */
  &center_out_P.Constant_Value_o,      /* 513: Block Parameter */
  &center_out_P.Constant2_Value,       /* 514: Block Parameter */
  &center_out_P.PortA_P1[0],           /* 515: Block Parameter */
  &center_out_P.PortA_P2,              /* 516: Block Parameter */
  &center_out_P.PortA_P3[0],           /* 517: Block Parameter */
  &center_out_P.PortA_P4[0],           /* 518: Block Parameter */
  &center_out_P.PortA_P5,              /* 519: Block Parameter */
  &center_out_P.PortA_P6,              /* 520: Block Parameter */
  &center_out_P.PortA_P7,              /* 521: Block Parameter */
  &center_out_P.PortA_P8,              /* 522: Block Parameter */
  &center_out_P.PortA_P9,              /* 523: Block Parameter */
  &center_out_P.PortB_P1[0],           /* 524: Block Parameter */
  &center_out_P.PortB_P2,              /* 525: Block Parameter */
  &center_out_P.PortB_P3[0],           /* 526: Block Parameter */
  &center_out_P.PortB_P4[0],           /* 527: Block Parameter */
  &center_out_P.PortB_P5,              /* 528: Block Parameter */
  &center_out_P.PortB_P6,              /* 529: Block Parameter */
  &center_out_P.PortB_P7,              /* 530: Block Parameter */
  &center_out_P.PortB_P8,              /* 531: Block Parameter */
  &center_out_P.PortB_P9,              /* 532: Block Parameter */
  &center_out_P.xPCTargetTime_P1_f,    /* 533: Block Parameter */
  &center_out_P.xPCTargetTime_P2_h,    /* 534: Block Parameter */
  &center_out_P.Switch_Threshold_p,    /* 535: Block Parameter */
  &center_out_P.L1_Value,              /* 536: Block Parameter */
  &center_out_P.L2_Value,              /* 537: Block Parameter */
  &center_out_P.xoffset_Value,         /* 538: Block Parameter */
  &center_out_P.yoffset_Value,         /* 539: Block Parameter */
  &center_out_P.Gain_Gain_h,           /* 540: Block Parameter */
  &center_out_P.Gain1_Gain_o,          /* 541: Block Parameter */
  &center_out_P.Gain2_Gain,            /* 542: Block Parameter */
  &center_out_P.beta_Value,            /* 543: Block Parameter */
  &center_out_P.rho_Value,             /* 544: Block Parameter */
  &center_out_P.sigma_Value,           /* 545: Block Parameter */
  &center_out_P.timescale_Value,       /* 546: Block Parameter */
  &center_out_P.x_X0_j,                /* 547: Block Parameter */
  &center_out_P.y_X0,                  /* 548: Block Parameter */
  &center_out_P.z_X0,                  /* 549: Block Parameter */
  &center_out_P.beta_Value_e,          /* 550: Block Parameter */
  &center_out_P.rho_Value_d,           /* 551: Block Parameter */
  &center_out_P.sigma_Value_k,         /* 552: Block Parameter */
  &center_out_P.timescale_Value_m,     /* 553: Block Parameter */
  &center_out_P.x_X0_jq,               /* 554: Block Parameter */
  &center_out_P.y_X0_i,                /* 555: Block Parameter */
  &center_out_P.z_X0_c,                /* 556: Block Parameter */
  &center_out_P.beta_Value_m,          /* 557: Block Parameter */
  &center_out_P.rho_Value_n,           /* 558: Block Parameter */
  &center_out_P.sigma_Value_e,         /* 559: Block Parameter */
  &center_out_P.timescale_Value_a,     /* 560: Block Parameter */
  &center_out_P.x_X0_g,                /* 561: Block Parameter */
  &center_out_P.y_X0_p,                /* 562: Block Parameter */
  &center_out_P.z_X0_j,                /* 563: Block Parameter */
  &center_out_P.beta_Value_i,          /* 564: Block Parameter */
  &center_out_P.rho_Value_d2,          /* 565: Block Parameter */
  &center_out_P.sigma_Value_p,         /* 566: Block Parameter */
  &center_out_P.timescale_Value_l,     /* 567: Block Parameter */
  &center_out_P.x_X0_pl,               /* 568: Block Parameter */
  &center_out_P.y_X0_n,                /* 569: Block Parameter */
  &center_out_P.z_X0_f,                /* 570: Block Parameter */
  &center_out_P.beta_Value_ez,         /* 571: Block Parameter */
  &center_out_P.rho_Value_p,           /* 572: Block Parameter */
  &center_out_P.sigma_Value_c,         /* 573: Block Parameter */
  &center_out_P.timescale_Value_lp,    /* 574: Block Parameter */
  &center_out_P.x_X0,                  /* 575: Block Parameter */
  &center_out_P.y_X0_f,                /* 576: Block Parameter */
  &center_out_P.z_X0_a,                /* 577: Block Parameter */
  &center_out_P.beta_Value_mt,         /* 578: Block Parameter */
  &center_out_P.rho_Value_f,           /* 579: Block Parameter */
  &center_out_P.sigma_Value_h,         /* 580: Block Parameter */
  &center_out_P.timescale_Value_c,     /* 581: Block Parameter */
  &center_out_P.x_X0_h,                /* 582: Block Parameter */
  &center_out_P.y_X0_j,                /* 583: Block Parameter */
  &center_out_P.z_X0_b,                /* 584: Block Parameter */
  &center_out_P.beta_Value_b,          /* 585: Block Parameter */
  &center_out_P.rho_Value_g,           /* 586: Block Parameter */
  &center_out_P.sigma_Value_m,         /* 587: Block Parameter */
  &center_out_P.timescale_Value_k,     /* 588: Block Parameter */
  &center_out_P.x_X0_p,                /* 589: Block Parameter */
  &center_out_P.y_X0_o,                /* 590: Block Parameter */
  &center_out_P.z_X0_e,                /* 591: Block Parameter */
  &center_out_P.beta_Value_a,          /* 592: Block Parameter */
  &center_out_P.rho_Value_j,           /* 593: Block Parameter */
  &center_out_P.sigma_Value_hn,        /* 594: Block Parameter */
  &center_out_P.timescale_Value_i,     /* 595: Block Parameter */
  &center_out_P.x_X0_b,                /* 596: Block Parameter */
  &center_out_P.y_X0_d,                /* 597: Block Parameter */
  &center_out_P.z_X0_d,                /* 598: Block Parameter */
  &center_out_P.Constant_Value,        /* 599: Block Parameter */
  &center_out_P.Constant_Value_p,      /* 600: Block Parameter */
  &center_out_P.DelayInput1_X0,        /* 601: Block Parameter */
  &center_out_P.Constant_Value_i,      /* 602: Block Parameter */
  &center_out_P.Constant1_Value,       /* 603: Block Parameter */
  &center_out_P.ScaleTouSec_Gain,      /* 604: Block Parameter */
  &center_out_P.PCI6025E_P1_l[0],      /* 605: Block Parameter */
  &center_out_P.PCI6025E_P2_c[0],      /* 606: Block Parameter */
  &center_out_P.PCI6025E_P3_i[0],      /* 607: Block Parameter */
  &center_out_P.PCI6025E_P4_c,         /* 608: Block Parameter */
  &center_out_P.PCI6025E_P5_d,         /* 609: Block Parameter */
  &center_out_P.PCI6025E_P6_m,         /* 610: Block Parameter */
  &center_out_P.PCI6025E_P7_h,         /* 611: Block Parameter */
  &center_out_P.xPCTargetTime_P1,      /* 612: Block Parameter */
  &center_out_P.xPCTargetTime_P2,      /* 613: Block Parameter */
  &center_out_P.Constant_Value_c,      /* 614: Block Parameter */
  &center_out_P.Constant_Value_pu      /* 615: Block Parameter */
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

  { rtBlockParameters, 244,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void center_out_InitializeDataMapInfo(rtModel_center_out *center_out_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(center_out_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(center_out_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(center_out_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(center_out_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(center_out_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(center_out_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(center_out_rtM->DataMapInfo.mmi, 0);
}

/* EOF: center_out_capi.c */
