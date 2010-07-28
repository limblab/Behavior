/*
 * forced_choice_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "forced_choice.mdl".
 *
 * Model Version              : 1.1203
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:24 2010
 */

#include "forced_choice.h"
#include "rtw_capi.h"
#include "forced_choice_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Matrix Concatenation1",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Behavior FC/p1",
    "", 0, 0, 1, 0, 0 },

  { 2, 0, "Behavior FC/p2",
    "", 1, 0, 2, 0, 0 },

  { 3, 0, "Behavior FC/p3",
    "", 2, 0, 3, 0, 0 },

  { 4, 0, "Behavior FC/p4",
    "", 3, 0, 4, 0, 0 },

  { 5, 0, "Behavior FC/p5",
    "", 4, 0, 3, 0, 0 },

  { 6, 0, "Behavior FC/p6",
    "", 5, 0, 1, 0, 0 },

  { 7, 0, "Behavior FC/p7",
    "", 6, 0, 0, 0, 0 },

  { 8, 0, "Behavior FC/p8",
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
  { 372, "Behavior FC",
    "P1", 0, 3, 0 },

  { 373, "Behavior FC",
    "P2", 0, 3, 0 },

  { 374, "Behavior FC",
    "P3", 0, 3, 0 },

  { 375, "Behavior FC",
    "P4", 0, 3, 0 },

  { 376, "Behavior FC",
    "P5", 0, 3, 0 },

  { 377, "Behavior FC",
    "P6", 0, 3, 0 },

  { 378, "Behavior FC",
    "P7", 0, 3, 0 },

  { 379, "Behavior FC",
    "P8", 0, 3, 0 },

  { 380, "Behavior FC",
    "P9", 0, 3, 0 },

  { 381, "Behavior FC",
    "P10", 0, 3, 0 },

  { 382, "Behavior FC",
    "P11", 0, 3, 0 },

  { 383, "Behavior FC",
    "P12", 0, 3, 0 },

  { 384, "Behavior FC",
    "P13", 0, 3, 0 },

  { 385, "BoundingBox/XHighLimit",
    "Value", 0, 3, 0 },

  { 386, "BoundingBox/XLowLimit",
    "Value", 0, 3, 0 },

  { 387, "BoundingBox/YHighLimit",
    "Value", 0, 3, 0 },

  { 388, "BoundingBox/YLowLimit",
    "Value", 0, 3, 0 },

  { 389, "Catch Force Generator/DynamicAngle",
    "Value", 0, 3, 0 },

  { 390, "Catch Force Generator/Load",
    "Value", 0, 3, 0 },

  { 391, "Catch Force Generator/Off",
    "Value", 0, 3, 0 },

  { 392, "Catch Force Generator/staticX",
    "Value", 0, 3, 0 },

  { 393, "Catch Force Generator/staticY",
    "Value", 0, 3, 0 },

  { 394, "Catch Force Generator/visAngle",
    "Value", 0, 3, 0 },

  { 395, "Catch Force Generator/Gain",
    "Gain", 0, 3, 0 },

  { 396, "Catch Force Generator/LorentzForceGain",
    "Gain", 0, 3, 0 },

  { 397, "Force Generator/DynamicAngle",
    "Value", 0, 3, 0 },

  { 398, "Force Generator/Load",
    "Value", 0, 3, 0 },

  { 399, "Force Generator/Off",
    "Value", 0, 3, 0 },

  { 400, "Force Generator/staticX",
    "Value", 0, 3, 0 },

  { 401, "Force Generator/staticY",
    "Value", 0, 3, 0 },

  { 402, "Force Generator/visAngle",
    "Value", 0, 3, 0 },

  { 403, "Force Generator/Gain",
    "Gain", 0, 3, 0 },

  { 404, "Force Generator/LorentzForceGain",
    "Gain", 0, 3, 0 },

  { 405, "Motor Control/zeroX",
    "Value", 0, 3, 0 },

  { 406, "Motor Control/zeroY",
    "Value", 0, 3, 0 },

  { 407, "Motor Control/MG1",
    "Gain", 0, 3, 0 },

  { 408, "Motor Control/MG2",
    "Gain", 0, 3, 0 },

  { 409, "Motor Control/Memory",
    "X0", 1, 3, 0 },

  { 410, "Motor Control/PCI-6025E ",
    "P1", 0, 7, 0 },

  { 411, "Motor Control/PCI-6025E ",
    "P2", 0, 7, 0 },

  { 412, "Motor Control/PCI-6025E ",
    "P3", 0, 7, 0 },

  { 413, "Motor Control/PCI-6025E ",
    "P4", 0, 7, 0 },

  { 414, "Motor Control/PCI-6025E ",
    "P5", 0, 3, 0 },

  { 415, "Motor Control/PCI-6025E ",
    "P6", 0, 3, 0 },

  { 416, "Motor Control/PCI-6025E ",
    "P7", 0, 3, 0 },

  { 417, "Recentering Subsystem/RecenterFlag",
    "Value", 0, 3, 0 },

  { 418, "Recentering Subsystem/Bounding Box Viscosity",
    "Gain", 0, 3, 0 },

  { 419, "RewardSbs/JackpotChance",
    "Value", 0, 3, 0 },

  { 420, "RewardSbs/RewardJackpot",
    "Value", 0, 3, 0 },

  { 421, "RewardSbs/RewardTime",
    "Value", 0, 3, 0 },

  { 422, "RewardSbs/Uniform Random Number",
    "Minimum", 0, 3, 0 },

  { 423, "RewardSbs/Uniform Random Number",
    "Maximum", 0, 3, 0 },

  { 424, "RewardSbs/Uniform Random Number",
    "Seed", 0, 3, 0 },

  { 425, "Target Peek/Gain",
    "Gain", 0, 3, 0 },

  { 426, "Target Peek/Gain1",
    "Gain", 0, 3, 0 },

  { 427, "UDPXmit/Send",
    "P1", 0, 8, 0 },

  { 428, "UDPXmit/Send",
    "P2", 0, 3, 0 },

  { 429, "UDPXmit/Send",
    "P3", 0, 3, 0 },

  { 430, "UDPXmit/Send",
    "P4", 0, 3, 0 },

  { 431, "Velocity Calculation/UseTachs",
    "Value", 0, 3, 0 },

  { 432, "Velocity Calculation/TachGain1",
    "Gain", 0, 3, 0 },

  { 433, "Velocity Calculation/TachGain2",
    "Gain", 0, 3, 0 },

  { 434, "Velocity Calculation/PCI-6025E AD",
    "P1", 0, 7, 0 },

  { 435, "Velocity Calculation/PCI-6025E AD",
    "P2", 0, 7, 0 },

  { 436, "Velocity Calculation/PCI-6025E AD",
    "P3", 0, 7, 0 },

  { 437, "Velocity Calculation/PCI-6025E AD",
    "P4", 0, 3, 0 },

  { 438, "Velocity Calculation/PCI-6025E AD",
    "P5", 0, 3, 0 },

  { 439, "Velocity Calculation/PCI-6025E AD",
    "P6", 0, 3, 0 },

  { 440, "Velocity Calculation/Switch",
    "Threshold", 0, 3, 0 },

  { 441, "XY Position Subsystem/elbowOffset",
    "Value", 0, 3, 0 },

  { 442, "XY Position Subsystem/shoulderOffset",
    "Value", 0, 3, 0 },

  { 443, "XY Position Subsystem/Gain",
    "Gain", 0, 3, 0 },

  { 444, "XY Position Subsystem/Gain1",
    "Gain", 0, 3, 0 },

  { 445, "XY Position Subsystem/PCI-QUAD04 ",
    "P1", 0, 3, 0 },

  { 446, "XY Position Subsystem/PCI-QUAD04 ",
    "P2", 0, 3, 0 },

  { 447, "XY Position Subsystem/PCI-QUAD04 ",
    "P3", 0, 3, 0 },

  { 448, "XY Position Subsystem/PCI-QUAD04 ",
    "P4", 0, 3, 0 },

  { 449, "XY Position Subsystem/PCI-QUAD04 ",
    "P5", 0, 3, 0 },

  { 450, "XY Position Subsystem/PCI-QUAD04 ",
    "P6", 0, 3, 0 },

  { 451, "XY Position Subsystem/PCI-QUAD04 ",
    "P7", 0, 3, 0 },

  { 452, "XY Position Subsystem/PCI-QUAD04 ",
    "P8", 0, 3, 0 },

  { 453, "XY Position Subsystem/PCI-QUAD04 ",
    "P9", 0, 3, 0 },

  { 454, "XY Position Subsystem/PCI-QUAD04 ",
    "P10", 0, 3, 0 },

  { 455, "XY Position Subsystem/PCI-QUAD04 ",
    "P11", 0, 3, 0 },

  { 456, "XY Position Subsystem/PCI-QUAD04 1",
    "P1", 0, 3, 0 },

  { 457, "XY Position Subsystem/PCI-QUAD04 1",
    "P2", 0, 3, 0 },

  { 458, "XY Position Subsystem/PCI-QUAD04 1",
    "P3", 0, 3, 0 },

  { 459, "XY Position Subsystem/PCI-QUAD04 1",
    "P4", 0, 3, 0 },

  { 460, "XY Position Subsystem/PCI-QUAD04 1",
    "P5", 0, 3, 0 },

  { 461, "XY Position Subsystem/PCI-QUAD04 1",
    "P6", 0, 3, 0 },

  { 462, "XY Position Subsystem/PCI-QUAD04 1",
    "P7", 0, 3, 0 },

  { 463, "XY Position Subsystem/PCI-QUAD04 1",
    "P8", 0, 3, 0 },

  { 464, "XY Position Subsystem/PCI-QUAD04 1",
    "P9", 0, 3, 0 },

  { 465, "XY Position Subsystem/PCI-QUAD04 1",
    "P10", 0, 3, 0 },

  { 466, "XY Position Subsystem/PCI-QUAD04 1",
    "P11", 0, 3, 0 },

  { 467, "Catch Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 3, 0 },

  { 468, "Catch Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 3, 0 },

  { 469, "Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 3, 0 },

  { 470, "Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 3, 0 },

  { 471, "Motor Control/Compare To Constant/Constant",
    "Value", 0, 3, 0 },

  { 472, "Motor Control/Compare To Constant1/Constant",
    "Value", 0, 3, 0 },

  { 473, "Motor Control/Force//Torque Transform/Gain",
    "Gain", 0, 3, 0 },

  { 474, "Motor Control/Schmidt/Time",
    "Value", 0, 3, 0 },

  { 475, "Motor Control/Schmidt/Memory",
    "X0", 1, 3, 0 },

  { 476, "Recentering Subsystem/Falling Edge/Delay Input1",
    "X0", 2, 3, 0 },

  { 477, "Recentering Subsystem/Falling Edge1/Delay Input1",
    "X0", 2, 3, 0 },

  { 478, "Recentering Subsystem/PD Controller/Gain1",
    "Gain", 0, 3, 0 },

  { 479, "Recentering Subsystem/PD Controller/Gain2",
    "Gain", 0, 3, 0 },

  { 480, "Recentering Subsystem/PD Controller/Gain3",
    "Gain", 0, 3, 0 },

  { 481, "Recentering Subsystem/PD Controller/Gain4",
    "Gain", 0, 3, 0 },

  { 482, "Recentering Subsystem/PD Controller/Saturation",
    "UpperLimit", 0, 3, 0 },

  { 483, "Recentering Subsystem/PD Controller/Saturation",
    "LowerLimit", 0, 3, 0 },

  { 484, "Recentering Subsystem/PD Controller/Saturation1",
    "UpperLimit", 0, 3, 0 },

  { 485, "Recentering Subsystem/PD Controller/Saturation1",
    "LowerLimit", 0, 3, 0 },

  { 486, "Recentering Subsystem/S-R Flip-Flop/Logic",
    "TruthTable", 1, 9, 0 },

  { 487, "Recentering Subsystem/S-R Flip-Flop/Memory",
    "X0", 1, 3, 0 },

  { 488, "Recentering Subsystem/Schmidt1/Time",
    "Value", 0, 3, 0 },

  { 489, "Recentering Subsystem/Schmidt1/Memory",
    "X0", 1, 3, 0 },

  { 490, "Recentering Subsystem/Schmidt2/Time",
    "Value", 0, 3, 0 },

  { 491, "Recentering Subsystem/Schmidt2/Memory",
    "X0", 1, 3, 0 },

  { 492, "Recentering Subsystem/Schmidt3/Time",
    "Value", 0, 3, 0 },

  { 493, "Recentering Subsystem/Schmidt3/Memory",
    "X0", 1, 3, 0 },

  { 494, "Recentering Subsystem/Start Moving/Delay Input1",
    "X0", 2, 3, 0 },

  { 495, "Recentering Subsystem/Timer/Time",
    "Value", 0, 3, 0 },

  { 496, "Recentering Subsystem/Timer/Memory",
    "X0", 1, 3, 0 },

  { 497, "Velocity Calculation/Pos2VelX/dG",
    "Gain", 0, 3, 0 },

  { 498, "Velocity Calculation/Pos2VelX/Digital Filter",
    "ICRTP", 0, 3, 0 },

  { 499, "Velocity Calculation/Pos2VelX/Digital Filter",
    "RTP1COEFF", 0, 8, 0 },

  { 500, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "ICRTP", 0, 3, 0 },

  { 501, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "RTP1COEFF", 0, 8, 0 },

  { 502, "Velocity Calculation/Pos2VelY/dG",
    "Gain", 0, 3, 0 },

  { 503, "Velocity Calculation/Pos2VelY/Digital Filter",
    "ICRTP", 0, 3, 0 },

  { 504, "Velocity Calculation/Pos2VelY/Digital Filter",
    "RTP1COEFF", 0, 8, 0 },

  { 505, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "ICRTP", 0, 3, 0 },

  { 506, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "RTP1COEFF", 0, 8, 0 },

  { 507, "XY Position Subsystem/Cursor Rotation/AngleOffset",
    "Value", 0, 3, 0 },

  { 508, "XY Position Subsystem/For Iterator Subsystem/Constant",
    "Value", 0, 3, 0 },

  { 509, "XY Position Subsystem/For Iterator Subsystem/Constant2",
    "Value", 0, 3, 0 },

  { 510, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P1", 0, 10, 0 },

  { 511, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P2", 0, 3, 0 },

  { 512, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P3", 0, 10, 0 },

  { 513, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P4", 0, 10, 0 },

  { 514, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P5", 0, 3, 0 },

  { 515, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P6", 0, 3, 0 },

  { 516, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P7", 0, 3, 0 },

  { 517, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P8", 0, 3, 0 },

  { 518, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P9", 0, 3, 0 },

  { 519, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P1", 0, 10, 0 },

  { 520, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P2", 0, 3, 0 },

  { 521, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P3", 0, 10, 0 },

  { 522, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P4", 0, 10, 0 },

  { 523, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P5", 0, 3, 0 },

  { 524, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P6", 0, 3, 0 },

  { 525, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P7", 0, 3, 0 },

  { 526, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P8", 0, 3, 0 },

  { 527, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P9", 0, 3, 0 },

  { 528, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 3, 0 },

  { 529, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 3, 0 },

  { 530, "XY Position Subsystem/For Iterator Subsystem/Switch",
    "Threshold", 0, 3, 0 },

  { 531, "XY Position Subsystem/Jacobian-Cartesian Transformation/L1",
    "Value", 0, 3, 0 },

  { 532, "XY Position Subsystem/Jacobian-Cartesian Transformation/L2",
    "Value", 0, 3, 0 },

  { 533, "XY Position Subsystem/Jacobian-Cartesian Transformation/xoffset",
    "Value", 0, 3, 0 },

  { 534, "XY Position Subsystem/Jacobian-Cartesian Transformation/yoffset",
    "Value", 0, 3, 0 },

  { 535, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain",
    "Gain", 0, 3, 0 },

  { 536, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain1",
    "Gain", 0, 3, 0 },

  { 537, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain2",
    "Gain", 0, 3, 0 },

  { 538, "Catch Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 3, 0 },

  { 539, "Catch Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 3, 0 },

  { 540, "Catch Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 3, 0 },

  { 541, "Catch Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 3, 0 },

  { 542, "Catch Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 3, 0 },

  { 543, "Catch Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 3, 0 },

  { 544, "Catch Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 3, 0 },

  { 545, "Catch Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 3, 0 },

  { 546, "Catch Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 3, 0 },

  { 547, "Catch Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 3, 0 },

  { 548, "Catch Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 3, 0 },

  { 549, "Catch Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 3, 0 },

  { 550, "Catch Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 3, 0 },

  { 551, "Catch Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 3, 0 },

  { 552, "Catch Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 3, 0 },

  { 553, "Catch Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 3, 0 },

  { 554, "Catch Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 3, 0 },

  { 555, "Catch Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 3, 0 },

  { 556, "Catch Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 3, 0 },

  { 557, "Catch Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 3, 0 },

  { 558, "Catch Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 3, 0 },

  { 559, "Catch Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 3, 0 },

  { 560, "Catch Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 3, 0 },

  { 561, "Catch Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 3, 0 },

  { 562, "Catch Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 3, 0 },

  { 563, "Catch Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 3, 0 },

  { 564, "Catch Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 3, 0 },

  { 565, "Catch Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 3, 0 },

  { 566, "Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 3, 0 },

  { 567, "Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 3, 0 },

  { 568, "Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 3, 0 },

  { 569, "Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 3, 0 },

  { 570, "Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 3, 0 },

  { 571, "Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 3, 0 },

  { 572, "Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 3, 0 },

  { 573, "Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 3, 0 },

  { 574, "Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 3, 0 },

  { 575, "Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 3, 0 },

  { 576, "Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 3, 0 },

  { 577, "Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 3, 0 },

  { 578, "Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 3, 0 },

  { 579, "Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 3, 0 },

  { 580, "Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 3, 0 },

  { 581, "Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 3, 0 },

  { 582, "Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 3, 0 },

  { 583, "Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 3, 0 },

  { 584, "Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 3, 0 },

  { 585, "Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 3, 0 },

  { 586, "Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 3, 0 },

  { 587, "Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 3, 0 },

  { 588, "Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 3, 0 },

  { 589, "Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 3, 0 },

  { 590, "Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 3, 0 },

  { 591, "Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 3, 0 },

  { 592, "Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 3, 0 },

  { 593, "Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 3, 0 },

  { 594, "Recentering Subsystem/No Movement/Compare To Constant2/Constant",
    "Value", 0, 3, 0 },

  { 595, "Recentering Subsystem/No Movement/Compare To Constant3/Constant",
    "Value", 0, 3, 0 },

  { 596, "Recentering Subsystem/Timer/Detect Fall Nonpositive/Delay Input1",
    "X0", 2, 3, 0 },

  { 597,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant",
    "Value", 0, 3, 0 },

  { 598,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant1",
    "Value", 0, 3, 0 },

  { 599,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "Gain", 0, 3, 0 },

  { 600,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P1", 0, 7, 0 },

  { 601,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P2", 0, 7, 0 },

  { 602,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P3", 0, 7, 0 },

  { 603,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P4", 0, 3, 0 },

  { 604,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P5", 0, 3, 0 },

  { 605,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P6", 0, 3, 0 },

  { 606,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P7", 0, 3, 0 },

  { 607,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 3, 0 },

  { 608,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 3, 0 },

  { 609,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Constant",
    "Value", 0, 3, 0 },

  { 610,
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
  &forced_choice_B.MatrixConcatenation1[0],/* 0: Signal */
  &forced_choice_B.BehaviorFC_o1[0],   /* 1: Signal */
  &forced_choice_B.BehaviorFC_o2[0],   /* 2: Signal */
  &forced_choice_B.BehaviorFC_o3,      /* 3: Signal */
  &forced_choice_B.BehaviorFC_o4[0],   /* 4: Signal */
  &forced_choice_B.BehaviorFC_o5,      /* 5: Signal */
  &forced_choice_B.BehaviorFC_o6[0],   /* 6: Signal */
  &forced_choice_B.BehaviorFC_o7[0],   /* 7: Signal */
  &forced_choice_B.BehaviorFC_o8[0],   /* 8: Signal */
  &forced_choice_B.LogicalOperator_h,  /* 9: Signal */
  &forced_choice_B.RelationalOperator_o,/* 10: Signal */
  &forced_choice_B.RelationalOperator1,/* 11: Signal */
  &forced_choice_B.RelationalOperator2,/* 12: Signal */
  &forced_choice_B.RelationalOperator3,/* 13: Signal */
  &forced_choice_B.Gain_ii,            /* 14: Signal */
  &forced_choice_B.LorentzForceGain_f[0],/* 15: Signal */
  &forced_choice_B.DynamicAngleSwitch, /* 16: Signal */
  &forced_choice_B.LoadSelectSwitch[0],/* 17: Signal */
  &forced_choice_B.Gain_e,             /* 18: Signal */
  &forced_choice_B.LorentzForceGain[0],/* 19: Signal */
  &forced_choice_B.MultiportSwitch[0], /* 20: Signal */
  &forced_choice_B.dynamicAngleSwitch, /* 21: Signal */
  &forced_choice_B.MatrixConcatenation[0],/* 22: Signal */
  &forced_choice_B.MG1,                /* 23: Signal */
  &forced_choice_B.MG2,                /* 24: Signal */
  &forced_choice_B.LogicalOperator1_g, /* 25: Signal */
  &forced_choice_B.Memory_p,           /* 26: Signal */
  &forced_choice_B.Switch1[0],         /* 27: Signal */
  &forced_choice_B.Switch2[0],         /* 28: Signal */
  &forced_choice_B.DataTypeConversion1,/* 29: Signal */
  &forced_choice_B.DataTypeConversion2,/* 30: Signal */
  &forced_choice_B.BoundingBoxViscosity[0],/* 31: Signal */
  &forced_choice_B.InBox,              /* 32: Signal */
  &forced_choice_B.LogicalOperator_f,  /* 33: Signal */
  &forced_choice_B.LogicalOperator1_c, /* 34: Signal */
  &forced_choice_B.LogicalOperator3_j, /* 35: Signal */
  &forced_choice_B.LogicalOperator5_h, /* 36: Signal */
  &forced_choice_B.LogicalOperator6,   /* 37: Signal */
  &forced_choice_B.NOT,                /* 38: Signal */
  &forced_choice_B.Switch_c[0],        /* 39: Signal */
  &forced_choice_B.DataTypeConversion, /* 40: Signal */
  &forced_choice_B.RelationalOperator_f,/* 41: Signal */
  &forced_choice_B.Switch_n,           /* 42: Signal */
  &forced_choice_B.UniformRandomNumber,/* 43: Signal */
  &forced_choice_B.Gain_n,             /* 44: Signal */
  &forced_choice_B.Gain1_d,            /* 45: Signal */
  &forced_choice_B.Add_n,              /* 46: Signal */
  &forced_choice_B.Add1_m,             /* 47: Signal */
  &forced_choice_B.RateTransition[0],  /* 48: Signal */
  &forced_choice_B.Pack[0],            /* 49: Signal */
  &forced_choice_B.TachGain1,          /* 50: Signal */
  &forced_choice_B.TachGain2,          /* 51: Signal */
  &forced_choice_B.MatrixMultiply[0],  /* 52: Signal */
  &forced_choice_B.PCI6025EAD_o1,      /* 53: Signal */
  &forced_choice_B.PCI6025EAD_o2,      /* 54: Signal */
  &forced_choice_B.Switch[0],          /* 55: Signal */
  &forced_choice_B.Gain,               /* 56: Signal */
  &forced_choice_B.Gain1,              /* 57: Signal */
  &forced_choice_B.PCIQUAD04,          /* 58: Signal */
  &forced_choice_B.PCIQUAD041,         /* 59: Signal */
  &forced_choice_B.Sum1,               /* 60: Signal */
  &forced_choice_B.Sum3,               /* 61: Signal */
  &forced_choice_B.Add_c,              /* 62: Signal */
  &forced_choice_B.Add1_cy,            /* 63: Signal */
  &forced_choice_B.Gain_j[0],          /* 64: Signal */
  &forced_choice_B.Inverter_f[0],      /* 65: Signal */
  &forced_choice_B.Product_p,          /* 66: Signal */
  &forced_choice_B.Product1_l,         /* 67: Signal */
  &forced_choice_B.Product2_k,         /* 68: Signal */
  &forced_choice_B.Product3_c,         /* 69: Signal */
  &forced_choice_B.Add_cv,             /* 70: Signal */
  &forced_choice_B.Subtract_n,         /* 71: Signal */
  &forced_choice_B.cos_i,              /* 72: Signal */
  &forced_choice_B.sin_h,              /* 73: Signal */
  &forced_choice_B.Add,                /* 74: Signal */
  &forced_choice_B.Add1_c,             /* 75: Signal */
  &forced_choice_B.Gain_l[0],          /* 76: Signal */
  &forced_choice_B.Inverter[0],        /* 77: Signal */
  &forced_choice_B.Product_h,          /* 78: Signal */
  &forced_choice_B.Product1_h,         /* 79: Signal */
  &forced_choice_B.Product2_p,         /* 80: Signal */
  &forced_choice_B.Product3_g,         /* 81: Signal */
  &forced_choice_B.Add_f,              /* 82: Signal */
  &forced_choice_B.Subtract_b,         /* 83: Signal */
  &forced_choice_B.cos_n,              /* 84: Signal */
  &forced_choice_B.sin_c,              /* 85: Signal */
  &forced_choice_B.Compare_m,          /* 86: Signal */
  &forced_choice_B.Compare_d,          /* 87: Signal */
  &forced_choice_B.Gain_i[0],          /* 88: Signal */
  &forced_choice_B.MatrixMultiply_f[0],/* 89: Signal */
  &forced_choice_B.Clock,              /* 90: Signal */
  &forced_choice_B.LogicalOperator,    /* 91: Signal */
  &forced_choice_B.LogicalOperator1,   /* 92: Signal */
  &forced_choice_B.LogicalOperator2,   /* 93: Signal */
  &forced_choice_B.Memory,             /* 94: Signal */
  &forced_choice_B.RelationalOperator, /* 95: Signal */
  &forced_choice_B.Sum,                /* 96: Signal */
  &forced_choice_B.Compare_g,          /* 97: Signal */
  &forced_choice_B.Compare_j,          /* 98: Signal */
  &forced_choice_B.FixPtRelationalOperator_j,/* 99: Signal */
  &forced_choice_B.Uk1_m,              /* 100: Signal */
  &forced_choice_B.FixPtRelationalOperator_d,/* 101: Signal */
  &forced_choice_B.Uk1_k,              /* 102: Signal */
  &forced_choice_B.Abs2,               /* 103: Signal */
  &forced_choice_B.Abs3,               /* 104: Signal */
  &forced_choice_B.LogicalOperator1_e, /* 105: Signal */
  &forced_choice_B.Gain1_m,            /* 106: Signal */
  &forced_choice_B.Gain2,              /* 107: Signal */
  &forced_choice_B.Gain3,              /* 108: Signal */
  &forced_choice_B.Gain4,              /* 109: Signal */
  &forced_choice_B.Product_g,          /* 110: Signal */
  &forced_choice_B.Product1_m,         /* 111: Signal */
  &forced_choice_B.Saturation,         /* 112: Signal */
  &forced_choice_B.Saturation1,        /* 113: Signal */
  &forced_choice_B.Add_j,              /* 114: Signal */
  &forced_choice_B.Add1_p,             /* 115: Signal */
  &forced_choice_B.Logic[0],           /* 116: Signal */
  &forced_choice_B.Memory_f,           /* 117: Signal */
  &forced_choice_B.Clock_p,            /* 118: Signal */
  &forced_choice_B.LogicalOperator_p,  /* 119: Signal */
  &forced_choice_B.LogicalOperator1_h, /* 120: Signal */
  &forced_choice_B.LogicalOperator2_d, /* 121: Signal */
  &forced_choice_B.Memory_h,           /* 122: Signal */
  &forced_choice_B.RelationalOperator_n,/* 123: Signal */
  &forced_choice_B.Sum_a,              /* 124: Signal */
  &forced_choice_B.Clock_b,            /* 125: Signal */
  &forced_choice_B.LogicalOperator_fa, /* 126: Signal */
  &forced_choice_B.LogicalOperator1_hr,/* 127: Signal */
  &forced_choice_B.LogicalOperator2_e, /* 128: Signal */
  &forced_choice_B.Memory_m,           /* 129: Signal */
  &forced_choice_B.RelationalOperator_pi,/* 130: Signal */
  &forced_choice_B.Sum_p,              /* 131: Signal */
  &forced_choice_B.Clock_f,            /* 132: Signal */
  &forced_choice_B.LogicalOperator_g,  /* 133: Signal */
  &forced_choice_B.LogicalOperator1_i, /* 134: Signal */
  &forced_choice_B.LogicalOperator2_da,/* 135: Signal */
  &forced_choice_B.Memory_ha,          /* 136: Signal */
  &forced_choice_B.RelationalOperator_b,/* 137: Signal */
  &forced_choice_B.Sum_d,              /* 138: Signal */
  &forced_choice_B.FixPtRelationalOperator_l,/* 139: Signal */
  &forced_choice_B.Uk1_c,              /* 140: Signal */
  &forced_choice_B.Clock_l,            /* 141: Signal */
  &forced_choice_B.LogicalOperator_fl, /* 142: Signal */
  &forced_choice_B.LogicalOperator1_p, /* 143: Signal */
  &forced_choice_B.LogicalOperator2_b, /* 144: Signal */
  &forced_choice_B.LogicalOperator3,   /* 145: Signal */
  &forced_choice_B.LogicalOperator4,   /* 146: Signal */
  &forced_choice_B.LogicalOperator5,   /* 147: Signal */
  &forced_choice_B.Memory_k,           /* 148: Signal */
  &forced_choice_B.RelationalOperator_p,/* 149: Signal */
  &forced_choice_B.Sum_k,              /* 150: Signal */
  &forced_choice_B.SampleandHold_i.In, /* 151: Signal */
  &forced_choice_B.Clock_i,            /* 152: Signal */
  &forced_choice_B.RelationalOperator_c,/* 153: Signal */
  &forced_choice_B.Sum_f5,             /* 154: Signal */
  &forced_choice_B.Derivative,         /* 155: Signal */
  &forced_choice_B.dG,                 /* 156: Signal */
  &forced_choice_B.DigitalFilter,      /* 157: Signal */
  &forced_choice_B.DigitalFilter2,     /* 158: Signal */
  &forced_choice_B.Derivative_h,       /* 159: Signal */
  &forced_choice_B.dG_f,               /* 160: Signal */
  &forced_choice_B.DigitalFilter_k,    /* 161: Signal */
  &forced_choice_B.DigitalFilter2_b,   /* 162: Signal */
  &forced_choice_B.sqrtu1u1u2u2,       /* 163: Signal */
  &forced_choice_B.Product_d,          /* 164: Signal */
  &forced_choice_B.Product1_d,         /* 165: Signal */
  &forced_choice_B.Sum_f,              /* 166: Signal */
  &forced_choice_B.TrigonometricFunction_k,/* 167: Signal */
  &forced_choice_B.TrigonometricFunction1_j,/* 168: Signal */
  &forced_choice_B.TrigonometricFunction2_g,/* 169: Signal */
  &forced_choice_B.ForIterator,        /* 170: Signal */
  &forced_choice_B.SerialConverter,    /* 171: Signal */
  &forced_choice_B.ToBits_o1,          /* 172: Signal */
  &forced_choice_B.ToBits_o2,          /* 173: Signal */
  &forced_choice_B.ToBits_o3,          /* 174: Signal */
  &forced_choice_B.ToBits_o4,          /* 175: Signal */
  &forced_choice_B.ToBits_o5,          /* 176: Signal */
  &forced_choice_B.ToBits_o6,          /* 177: Signal */
  &forced_choice_B.ToBits_o7,          /* 178: Signal */
  &forced_choice_B.ToBits_o8,          /* 179: Signal */
  &forced_choice_B.ToBits1_o1,         /* 180: Signal */
  &forced_choice_B.ToBits1_o2,         /* 181: Signal */
  &forced_choice_B.ToBits1_o3,         /* 182: Signal */
  &forced_choice_B.ToBits1_o4,         /* 183: Signal */
  &forced_choice_B.ToBits1_o5,         /* 184: Signal */
  &forced_choice_B.ToBits1_o6,         /* 185: Signal */
  &forced_choice_B.ToBits1_o7,         /* 186: Signal */
  &forced_choice_B.ToBits1_o8,         /* 187: Signal */
  &forced_choice_B.xPCTargetTime,      /* 188: Signal */
  &forced_choice_B.Add_i,              /* 189: Signal */
  &forced_choice_B.Add1_k0,            /* 190: Signal */
  &forced_choice_B.Switch_e,           /* 191: Signal */
  &forced_choice_B.MatrixConcatenate2[0],/* 192: Signal */
  &forced_choice_B.MatrixConcatenate2[0],/* 193: Signal */
  &forced_choice_B.MatrixConcatenate2[0],/* 194: Signal */
  &forced_choice_B.MatrixConcatenate2[0],/* 195: Signal */
  &forced_choice_B.MatrixConcatenate2[0],/* 196: Signal */
  &forced_choice_B.MatrixConcatenate2[0],/* 197: Signal */
  &forced_choice_B.Product,            /* 198: Signal */
  &forced_choice_B.Product1,           /* 199: Signal */
  &forced_choice_B.Product2,           /* 200: Signal */
  &forced_choice_B.Product3,           /* 201: Signal */
  &forced_choice_B.Sum1_a,             /* 202: Signal */
  &forced_choice_B.Sum2,               /* 203: Signal */
  &forced_choice_B.Sum3_n,             /* 204: Signal */
  &forced_choice_B.Sum4,               /* 205: Signal */
  &forced_choice_B.TrigonometricFunction,/* 206: Signal */
  &forced_choice_B.TrigonometricFunction1,/* 207: Signal */
  &forced_choice_B.TrigonometricFunction2,/* 208: Signal */
  &forced_choice_B.TrigonometricFunction3,/* 209: Signal */
  &forced_choice_B.dX,                 /* 210: Signal */
  &forced_choice_B.dY,                 /* 211: Signal */
  &forced_choice_B.dZ,                 /* 212: Signal */
  &forced_choice_B.product1,           /* 213: Signal */
  &forced_choice_B.product2,           /* 214: Signal */
  &forced_choice_B.product3,           /* 215: Signal */
  &forced_choice_B.product4,           /* 216: Signal */
  &forced_choice_B.Add1,               /* 217: Signal */
  &forced_choice_B.Add2,               /* 218: Signal */
  &forced_choice_B.Add3,               /* 219: Signal */
  &forced_choice_B.Add4,               /* 220: Signal */
  &forced_choice_B.AddX,               /* 221: Signal */
  &forced_choice_B.AddX1,              /* 222: Signal */
  &forced_choice_B.AddX2,              /* 223: Signal */
  &forced_choice_B.x_o,                /* 224: Signal */
  &forced_choice_B.y,                  /* 225: Signal */
  &forced_choice_B.z,                  /* 226: Signal */
  &forced_choice_B.dX_c,               /* 227: Signal */
  &forced_choice_B.dY_j,               /* 228: Signal */
  &forced_choice_B.dZ_k,               /* 229: Signal */
  &forced_choice_B.product1_h,         /* 230: Signal */
  &forced_choice_B.product2_m,         /* 231: Signal */
  &forced_choice_B.product3_j,         /* 232: Signal */
  &forced_choice_B.product4_l,         /* 233: Signal */
  &forced_choice_B.Add1_k,             /* 234: Signal */
  &forced_choice_B.Add2_p,             /* 235: Signal */
  &forced_choice_B.Add3_m,             /* 236: Signal */
  &forced_choice_B.Add4_d,             /* 237: Signal */
  &forced_choice_B.AddX_h,             /* 238: Signal */
  &forced_choice_B.AddX1_a,            /* 239: Signal */
  &forced_choice_B.AddX2_f,            /* 240: Signal */
  &forced_choice_B.x_of,               /* 241: Signal */
  &forced_choice_B.y_i,                /* 242: Signal */
  &forced_choice_B.z_e,                /* 243: Signal */
  &forced_choice_B.dX_h,               /* 244: Signal */
  &forced_choice_B.dY_o,               /* 245: Signal */
  &forced_choice_B.dZ_m,               /* 246: Signal */
  &forced_choice_B.product1_b,         /* 247: Signal */
  &forced_choice_B.product2_g,         /* 248: Signal */
  &forced_choice_B.product3_k,         /* 249: Signal */
  &forced_choice_B.product4_h,         /* 250: Signal */
  &forced_choice_B.Add1_l,             /* 251: Signal */
  &forced_choice_B.Add2_c,             /* 252: Signal */
  &forced_choice_B.Add3_i,             /* 253: Signal */
  &forced_choice_B.Add4_i,             /* 254: Signal */
  &forced_choice_B.AddX_e,             /* 255: Signal */
  &forced_choice_B.AddX1_g,            /* 256: Signal */
  &forced_choice_B.AddX2_m,            /* 257: Signal */
  &forced_choice_B.x_n,                /* 258: Signal */
  &forced_choice_B.y_k,                /* 259: Signal */
  &forced_choice_B.z_h,                /* 260: Signal */
  &forced_choice_B.dX_i,               /* 261: Signal */
  &forced_choice_B.dY_k,               /* 262: Signal */
  &forced_choice_B.dZ_mc,              /* 263: Signal */
  &forced_choice_B.product1_o,         /* 264: Signal */
  &forced_choice_B.product2_n,         /* 265: Signal */
  &forced_choice_B.product3_ji,        /* 266: Signal */
  &forced_choice_B.product4_o,         /* 267: Signal */
  &forced_choice_B.Add1_ld,            /* 268: Signal */
  &forced_choice_B.Add2_f,             /* 269: Signal */
  &forced_choice_B.Add3_o,             /* 270: Signal */
  &forced_choice_B.Add4_h,             /* 271: Signal */
  &forced_choice_B.AddX_k,             /* 272: Signal */
  &forced_choice_B.AddX1_c,            /* 273: Signal */
  &forced_choice_B.AddX2_d,            /* 274: Signal */
  &forced_choice_B.x_p,                /* 275: Signal */
  &forced_choice_B.y_a,                /* 276: Signal */
  &forced_choice_B.z_a,                /* 277: Signal */
  &forced_choice_B.dX_b,               /* 278: Signal */
  &forced_choice_B.dY_ks,              /* 279: Signal */
  &forced_choice_B.dZ_j,               /* 280: Signal */
  &forced_choice_B.product1_k,         /* 281: Signal */
  &forced_choice_B.product2_go,        /* 282: Signal */
  &forced_choice_B.product3_m,         /* 283: Signal */
  &forced_choice_B.product4_j,         /* 284: Signal */
  &forced_choice_B.Add1_o,             /* 285: Signal */
  &forced_choice_B.Add2_n,             /* 286: Signal */
  &forced_choice_B.Add3_m2,            /* 287: Signal */
  &forced_choice_B.Add4_p,             /* 288: Signal */
  &forced_choice_B.AddX_n,             /* 289: Signal */
  &forced_choice_B.AddX1_p,            /* 290: Signal */
  &forced_choice_B.AddX2_i,            /* 291: Signal */
  &forced_choice_B.x,                  /* 292: Signal */
  &forced_choice_B.y_p,                /* 293: Signal */
  &forced_choice_B.z_p,                /* 294: Signal */
  &forced_choice_B.dX_i1,              /* 295: Signal */
  &forced_choice_B.dY_g,               /* 296: Signal */
  &forced_choice_B.dZ_k3,              /* 297: Signal */
  &forced_choice_B.product1_ka,        /* 298: Signal */
  &forced_choice_B.product2_n2,        /* 299: Signal */
  &forced_choice_B.product3_b,         /* 300: Signal */
  &forced_choice_B.product4_n,         /* 301: Signal */
  &forced_choice_B.Add1_e,             /* 302: Signal */
  &forced_choice_B.Add2_d,             /* 303: Signal */
  &forced_choice_B.Add3_n,             /* 304: Signal */
  &forced_choice_B.Add4_c,             /* 305: Signal */
  &forced_choice_B.AddX_m,             /* 306: Signal */
  &forced_choice_B.AddX1_j,            /* 307: Signal */
  &forced_choice_B.AddX2_j,            /* 308: Signal */
  &forced_choice_B.x_h,                /* 309: Signal */
  &forced_choice_B.y_pt,               /* 310: Signal */
  &forced_choice_B.z_m,                /* 311: Signal */
  &forced_choice_B.dX_l,               /* 312: Signal */
  &forced_choice_B.dY_op,              /* 313: Signal */
  &forced_choice_B.dZ_f,               /* 314: Signal */
  &forced_choice_B.product1_bp,        /* 315: Signal */
  &forced_choice_B.product2_a,         /* 316: Signal */
  &forced_choice_B.product3_c,         /* 317: Signal */
  &forced_choice_B.product4_c,         /* 318: Signal */
  &forced_choice_B.Add1_ln,            /* 319: Signal */
  &forced_choice_B.Add2_k,             /* 320: Signal */
  &forced_choice_B.Add3_k,             /* 321: Signal */
  &forced_choice_B.Add4_im,            /* 322: Signal */
  &forced_choice_B.AddX_kb,            /* 323: Signal */
  &forced_choice_B.AddX1_k,            /* 324: Signal */
  &forced_choice_B.AddX2_b,            /* 325: Signal */
  &forced_choice_B.x_m,                /* 326: Signal */
  &forced_choice_B.y_e,                /* 327: Signal */
  &forced_choice_B.z_mc,               /* 328: Signal */
  &forced_choice_B.dX_a,               /* 329: Signal */
  &forced_choice_B.dY_p,               /* 330: Signal */
  &forced_choice_B.dZ_p,               /* 331: Signal */
  &forced_choice_B.product1_kd,        /* 332: Signal */
  &forced_choice_B.product2_j,         /* 333: Signal */
  &forced_choice_B.product3_a,         /* 334: Signal */
  &forced_choice_B.product4_p,         /* 335: Signal */
  &forced_choice_B.Add1_i,             /* 336: Signal */
  &forced_choice_B.Add2_cy,            /* 337: Signal */
  &forced_choice_B.Add3_d,             /* 338: Signal */
  &forced_choice_B.Add4_hy,            /* 339: Signal */
  &forced_choice_B.AddX_mq,            /* 340: Signal */
  &forced_choice_B.AddX1_e,            /* 341: Signal */
  &forced_choice_B.AddX2_fp,           /* 342: Signal */
  &forced_choice_B.x_ho,               /* 343: Signal */
  &forced_choice_B.y_ke,               /* 344: Signal */
  &forced_choice_B.z_n,                /* 345: Signal */
  &forced_choice_B.MathFunction[0],    /* 346: Signal */
  &forced_choice_B.Compare,            /* 347: Signal */
  &forced_choice_B.EnabledSubsystem.In1,/* 348: Signal */
  &forced_choice_B.Compare_e,          /* 349: Signal */
  &forced_choice_B.Compare_l,          /* 350: Signal */
  &forced_choice_B.Compare_f,          /* 351: Signal */
  &forced_choice_B.Compare_p,          /* 352: Signal */
  &forced_choice_B.Compare_i,          /* 353: Signal */
  &forced_choice_B.EnabledSubsystem_h.In1,/* 354: Signal */
  &forced_choice_B.Compare_jc,         /* 355: Signal */
  &forced_choice_B.EnabledSubsystem_hg.In1,/* 356: Signal */
  &forced_choice_B.Compare_n,          /* 357: Signal */
  &forced_choice_B.EnabledSubsystem_i.In1,/* 358: Signal */
  &forced_choice_B.Compare_jg,         /* 359: Signal */
  &forced_choice_B.Compare_k,          /* 360: Signal */
  &forced_choice_B.FixPtRelationalOperator,/* 361: Signal */
  &forced_choice_B.Uk1,                /* 362: Signal */
  &forced_choice_B.EnabledSubsystem_l.In1,/* 363: Signal */
  &forced_choice_B.SampleandHold.In,   /* 364: Signal */
  &forced_choice_B.ScaleTouSec,        /* 365: Signal */
  &forced_choice_B.xPCTargetTime_n,    /* 366: Signal */
  &forced_choice_B.Subtract,           /* 367: Signal */
  &forced_choice_B.Switch_m,           /* 368: Signal */
  &forced_choice_B.Compare_gq,         /* 369: Signal */
  &forced_choice_B.Compare_a,          /* 370: Signal */
  &forced_choice_B.Compare_pl,         /* 371: Signal */
  &forced_choice_P.BehaviorFC_P1,      /* 372: Block Parameter */
  &forced_choice_P.BehaviorFC_P2,      /* 373: Block Parameter */
  &forced_choice_P.BehaviorFC_P3,      /* 374: Block Parameter */
  &forced_choice_P.BehaviorFC_P4,      /* 375: Block Parameter */
  &forced_choice_P.BehaviorFC_P5,      /* 376: Block Parameter */
  &forced_choice_P.BehaviorFC_P6,      /* 377: Block Parameter */
  &forced_choice_P.BehaviorFC_P7,      /* 378: Block Parameter */
  &forced_choice_P.BehaviorFC_P8,      /* 379: Block Parameter */
  &forced_choice_P.BehaviorFC_P9,      /* 380: Block Parameter */
  &forced_choice_P.BehaviorFC_P10,     /* 381: Block Parameter */
  &forced_choice_P.BehaviorFC_P11,     /* 382: Block Parameter */
  &forced_choice_P.BehaviorFC_P12,     /* 383: Block Parameter */
  &forced_choice_P.BehaviorFC_P13,     /* 384: Block Parameter */
  &forced_choice_P.XHighLimit_Value,   /* 385: Block Parameter */
  &forced_choice_P.XLowLimit_Value,    /* 386: Block Parameter */
  &forced_choice_P.YHighLimit_Value,   /* 387: Block Parameter */
  &forced_choice_P.YLowLimit_Value,    /* 388: Block Parameter */
  &forced_choice_P.DynamicAngle_Value, /* 389: Block Parameter */
  &forced_choice_P.Load_Value_d,       /* 390: Block Parameter */
  &forced_choice_P.Off_Value,          /* 391: Block Parameter */
  &forced_choice_P.staticX_Value,      /* 392: Block Parameter */
  &forced_choice_P.staticY_Value,      /* 393: Block Parameter */
  &forced_choice_P.visAngle_Value,     /* 394: Block Parameter */
  &forced_choice_P.Gain_Gain_n,        /* 395: Block Parameter */
  &forced_choice_P.LorentzForceGain_Gain,/* 396: Block Parameter */
  &forced_choice_P.DynamicAngle_Value_c,/* 397: Block Parameter */
  &forced_choice_P.Load_Value,         /* 398: Block Parameter */
  &forced_choice_P.Off_Value_j,        /* 399: Block Parameter */
  &forced_choice_P.staticX_Value_i,    /* 400: Block Parameter */
  &forced_choice_P.staticY_Value_o,    /* 401: Block Parameter */
  &forced_choice_P.visAngle_Value_i,   /* 402: Block Parameter */
  &forced_choice_P.Gain_Gain_d,        /* 403: Block Parameter */
  &forced_choice_P.LorentzForceGain_Gain_m,/* 404: Block Parameter */
  &forced_choice_P.zeroX_Value,        /* 405: Block Parameter */
  &forced_choice_P.zeroY_Value,        /* 406: Block Parameter */
  &forced_choice_P.MG1_Gain,           /* 407: Block Parameter */
  &forced_choice_P.MG2_Gain,           /* 408: Block Parameter */
  &forced_choice_P.Memory_X0_m,        /* 409: Block Parameter */
  &forced_choice_P.PCI6025E_P1[0],     /* 410: Block Parameter */
  &forced_choice_P.PCI6025E_P2[0],     /* 411: Block Parameter */
  &forced_choice_P.PCI6025E_P3[0],     /* 412: Block Parameter */
  &forced_choice_P.PCI6025E_P4[0],     /* 413: Block Parameter */
  &forced_choice_P.PCI6025E_P5,        /* 414: Block Parameter */
  &forced_choice_P.PCI6025E_P6,        /* 415: Block Parameter */
  &forced_choice_P.PCI6025E_P7,        /* 416: Block Parameter */
  &forced_choice_P.RecenterFlag_Value, /* 417: Block Parameter */
  &forced_choice_P.BoundingBoxViscosity_Gain,/* 418: Block Parameter */
  &forced_choice_P.JackpotChance_Value,/* 419: Block Parameter */
  &forced_choice_P.RewardJackpot_Value,/* 420: Block Parameter */
  &forced_choice_P.RewardTime_Value,   /* 421: Block Parameter */
  &forced_choice_P.UniformRandomNumber_Min,/* 422: Block Parameter */
  &forced_choice_P.UniformRandomNumber_Max,/* 423: Block Parameter */
  &forced_choice_P.UniformRandomNumber_Seed,/* 424: Block Parameter */
  &forced_choice_P.Gain_Gain_i,        /* 425: Block Parameter */
  &forced_choice_P.Gain1_Gain_e,       /* 426: Block Parameter */
  &forced_choice_P.Send_P1[0],         /* 427: Block Parameter */
  &forced_choice_P.Send_P2,            /* 428: Block Parameter */
  &forced_choice_P.Send_P3,            /* 429: Block Parameter */
  &forced_choice_P.Send_P4,            /* 430: Block Parameter */
  &forced_choice_P.UseTachs_Value,     /* 431: Block Parameter */
  &forced_choice_P.TachGain1_Gain,     /* 432: Block Parameter */
  &forced_choice_P.TachGain2_Gain,     /* 433: Block Parameter */
  &forced_choice_P.PCI6025EAD_P1[0],   /* 434: Block Parameter */
  &forced_choice_P.PCI6025EAD_P2[0],   /* 435: Block Parameter */
  &forced_choice_P.PCI6025EAD_P3[0],   /* 436: Block Parameter */
  &forced_choice_P.PCI6025EAD_P4,      /* 437: Block Parameter */
  &forced_choice_P.PCI6025EAD_P5,      /* 438: Block Parameter */
  &forced_choice_P.PCI6025EAD_P6,      /* 439: Block Parameter */
  &forced_choice_P.Switch_Threshold,   /* 440: Block Parameter */
  &forced_choice_P.elbowOffset_Value,  /* 441: Block Parameter */
  &forced_choice_P.shoulderOffset_Value,/* 442: Block Parameter */
  &forced_choice_P.Gain_Gain,          /* 443: Block Parameter */
  &forced_choice_P.Gain1_Gain,         /* 444: Block Parameter */
  &forced_choice_P.PCIQUAD04_P1,       /* 445: Block Parameter */
  &forced_choice_P.PCIQUAD04_P2,       /* 446: Block Parameter */
  &forced_choice_P.PCIQUAD04_P3,       /* 447: Block Parameter */
  &forced_choice_P.PCIQUAD04_P4,       /* 448: Block Parameter */
  &forced_choice_P.PCIQUAD04_P5,       /* 449: Block Parameter */
  &forced_choice_P.PCIQUAD04_P6,       /* 450: Block Parameter */
  &forced_choice_P.PCIQUAD04_P7,       /* 451: Block Parameter */
  &forced_choice_P.PCIQUAD04_P8,       /* 452: Block Parameter */
  &forced_choice_P.PCIQUAD04_P9,       /* 453: Block Parameter */
  &forced_choice_P.PCIQUAD04_P10,      /* 454: Block Parameter */
  &forced_choice_P.PCIQUAD04_P11,      /* 455: Block Parameter */
  &forced_choice_P.PCIQUAD041_P1,      /* 456: Block Parameter */
  &forced_choice_P.PCIQUAD041_P2,      /* 457: Block Parameter */
  &forced_choice_P.PCIQUAD041_P3,      /* 458: Block Parameter */
  &forced_choice_P.PCIQUAD041_P4,      /* 459: Block Parameter */
  &forced_choice_P.PCIQUAD041_P5,      /* 460: Block Parameter */
  &forced_choice_P.PCIQUAD041_P6,      /* 461: Block Parameter */
  &forced_choice_P.PCIQUAD041_P7,      /* 462: Block Parameter */
  &forced_choice_P.PCIQUAD041_P8,      /* 463: Block Parameter */
  &forced_choice_P.PCIQUAD041_P9,      /* 464: Block Parameter */
  &forced_choice_P.PCIQUAD041_P10,     /* 465: Block Parameter */
  &forced_choice_P.PCIQUAD041_P11,     /* 466: Block Parameter */
  &forced_choice_P.Gain_Gain_l,        /* 467: Block Parameter */
  &forced_choice_P.Inverter_Gain,      /* 468: Block Parameter */
  &forced_choice_P.Gain_Gain_mk,       /* 469: Block Parameter */
  &forced_choice_P.Inverter_Gain_l,    /* 470: Block Parameter */
  &forced_choice_P.Constant_Value_o,   /* 471: Block Parameter */
  &forced_choice_P.Constant_Value_l0,  /* 472: Block Parameter */
  &forced_choice_P.Gain_Gain_a,        /* 473: Block Parameter */
  &forced_choice_P.Time_Value,         /* 474: Block Parameter */
  &forced_choice_P.Memory_X0,          /* 475: Block Parameter */
  &forced_choice_P.DelayInput1_X0_d,   /* 476: Block Parameter */
  &forced_choice_P.DelayInput1_X0_c,   /* 477: Block Parameter */
  &forced_choice_P.Gain1_Gain_k,       /* 478: Block Parameter */
  &forced_choice_P.Gain2_Gain_f,       /* 479: Block Parameter */
  &forced_choice_P.Gain3_Gain,         /* 480: Block Parameter */
  &forced_choice_P.Gain4_Gain,         /* 481: Block Parameter */
  &forced_choice_P.Saturation_UpperSat,/* 482: Block Parameter */
  &forced_choice_P.Saturation_LowerSat,/* 483: Block Parameter */
  &forced_choice_P.Saturation1_UpperSat,/* 484: Block Parameter */
  &forced_choice_P.Saturation1_LowerSat,/* 485: Block Parameter */
  &forced_choice_P.Logic_table[0],     /* 486: Block Parameter */
  &forced_choice_P.Memory_X0_k,        /* 487: Block Parameter */
  &forced_choice_P.Time_Value_n,       /* 488: Block Parameter */
  &forced_choice_P.Memory_X0_n,        /* 489: Block Parameter */
  &forced_choice_P.Time_Value_c,       /* 490: Block Parameter */
  &forced_choice_P.Memory_X0_a,        /* 491: Block Parameter */
  &forced_choice_P.Time_Value_m,       /* 492: Block Parameter */
  &forced_choice_P.Memory_X0_e,        /* 493: Block Parameter */
  &forced_choice_P.DelayInput1_X0_f,   /* 494: Block Parameter */
  &forced_choice_P.Time_Value_o,       /* 495: Block Parameter */
  &forced_choice_P.Memory_X0_f,        /* 496: Block Parameter */
  &forced_choice_P.dG_Gain,            /* 497: Block Parameter */
  &forced_choice_P.DigitalFilter_ICRTP,/* 498: Block Parameter */
  &forced_choice_P.DigitalFilter_RTP1COEFF[0],/* 499: Block Parameter */
  &forced_choice_P.DigitalFilter2_ICRTP,/* 500: Block Parameter */
  &forced_choice_P.DigitalFilter2_RTP1COEFF[0],/* 501: Block Parameter */
  &forced_choice_P.dG_Gain_d,          /* 502: Block Parameter */
  &forced_choice_P.DigitalFilter_ICRTP_h,/* 503: Block Parameter */
  &forced_choice_P.DigitalFilter_RTP1COEFF_p[0],/* 504: Block Parameter */
  &forced_choice_P.DigitalFilter2_ICRTP_l,/* 505: Block Parameter */
  &forced_choice_P.DigitalFilter2_RTP1COEFF_m[0],/* 506: Block Parameter */
  &forced_choice_P.AngleOffset_Value,  /* 507: Block Parameter */
  &forced_choice_P.Constant_Value_i,   /* 508: Block Parameter */
  &forced_choice_P.Constant2_Value,    /* 509: Block Parameter */
  &forced_choice_P.PortA_P1[0],        /* 510: Block Parameter */
  &forced_choice_P.PortA_P2,           /* 511: Block Parameter */
  &forced_choice_P.PortA_P3[0],        /* 512: Block Parameter */
  &forced_choice_P.PortA_P4[0],        /* 513: Block Parameter */
  &forced_choice_P.PortA_P5,           /* 514: Block Parameter */
  &forced_choice_P.PortA_P6,           /* 515: Block Parameter */
  &forced_choice_P.PortA_P7,           /* 516: Block Parameter */
  &forced_choice_P.PortA_P8,           /* 517: Block Parameter */
  &forced_choice_P.PortA_P9,           /* 518: Block Parameter */
  &forced_choice_P.PortB_P1[0],        /* 519: Block Parameter */
  &forced_choice_P.PortB_P2,           /* 520: Block Parameter */
  &forced_choice_P.PortB_P3[0],        /* 521: Block Parameter */
  &forced_choice_P.PortB_P4[0],        /* 522: Block Parameter */
  &forced_choice_P.PortB_P5,           /* 523: Block Parameter */
  &forced_choice_P.PortB_P6,           /* 524: Block Parameter */
  &forced_choice_P.PortB_P7,           /* 525: Block Parameter */
  &forced_choice_P.PortB_P8,           /* 526: Block Parameter */
  &forced_choice_P.PortB_P9,           /* 527: Block Parameter */
  &forced_choice_P.xPCTargetTime_P1_a, /* 528: Block Parameter */
  &forced_choice_P.xPCTargetTime_P2_g, /* 529: Block Parameter */
  &forced_choice_P.Switch_Threshold_n, /* 530: Block Parameter */
  &forced_choice_P.L1_Value,           /* 531: Block Parameter */
  &forced_choice_P.L2_Value,           /* 532: Block Parameter */
  &forced_choice_P.xoffset_Value,      /* 533: Block Parameter */
  &forced_choice_P.yoffset_Value,      /* 534: Block Parameter */
  &forced_choice_P.Gain_Gain_m,        /* 535: Block Parameter */
  &forced_choice_P.Gain1_Gain_m,       /* 536: Block Parameter */
  &forced_choice_P.Gain2_Gain,         /* 537: Block Parameter */
  &forced_choice_P.beta_Value,         /* 538: Block Parameter */
  &forced_choice_P.rho_Value,          /* 539: Block Parameter */
  &forced_choice_P.sigma_Value,        /* 540: Block Parameter */
  &forced_choice_P.timescale_Value,    /* 541: Block Parameter */
  &forced_choice_P.x_X0_m,             /* 542: Block Parameter */
  &forced_choice_P.y_X0,               /* 543: Block Parameter */
  &forced_choice_P.z_X0,               /* 544: Block Parameter */
  &forced_choice_P.beta_Value_g,       /* 545: Block Parameter */
  &forced_choice_P.rho_Value_e,        /* 546: Block Parameter */
  &forced_choice_P.sigma_Value_b,      /* 547: Block Parameter */
  &forced_choice_P.timescale_Value_e,  /* 548: Block Parameter */
  &forced_choice_P.x_X0_j,             /* 549: Block Parameter */
  &forced_choice_P.y_X0_b,             /* 550: Block Parameter */
  &forced_choice_P.z_X0_o,             /* 551: Block Parameter */
  &forced_choice_P.beta_Value_h,       /* 552: Block Parameter */
  &forced_choice_P.rho_Value_k,        /* 553: Block Parameter */
  &forced_choice_P.sigma_Value_g,      /* 554: Block Parameter */
  &forced_choice_P.timescale_Value_m,  /* 555: Block Parameter */
  &forced_choice_P.x_X0_g,             /* 556: Block Parameter */
  &forced_choice_P.y_X0_o,             /* 557: Block Parameter */
  &forced_choice_P.z_X0_c,             /* 558: Block Parameter */
  &forced_choice_P.beta_Value_i,       /* 559: Block Parameter */
  &forced_choice_P.rho_Value_d,        /* 560: Block Parameter */
  &forced_choice_P.sigma_Value_k,      /* 561: Block Parameter */
  &forced_choice_P.timescale_Value_b,  /* 562: Block Parameter */
  &forced_choice_P.x_X0_lz,            /* 563: Block Parameter */
  &forced_choice_P.y_X0_a,             /* 564: Block Parameter */
  &forced_choice_P.z_X0_g,             /* 565: Block Parameter */
  &forced_choice_P.beta_Value_gv,      /* 566: Block Parameter */
  &forced_choice_P.rho_Value_i,        /* 567: Block Parameter */
  &forced_choice_P.sigma_Value_bo,     /* 568: Block Parameter */
  &forced_choice_P.timescale_Value_c,  /* 569: Block Parameter */
  &forced_choice_P.x_X0,               /* 570: Block Parameter */
  &forced_choice_P.y_X0_b0,            /* 571: Block Parameter */
  &forced_choice_P.z_X0_f,             /* 572: Block Parameter */
  &forced_choice_P.beta_Value_b,       /* 573: Block Parameter */
  &forced_choice_P.rho_Value_dl,       /* 574: Block Parameter */
  &forced_choice_P.sigma_Value_e,      /* 575: Block Parameter */
  &forced_choice_P.timescale_Value_j,  /* 576: Block Parameter */
  &forced_choice_P.x_X0_f,             /* 577: Block Parameter */
  &forced_choice_P.y_X0_f,             /* 578: Block Parameter */
  &forced_choice_P.z_X0_p,             /* 579: Block Parameter */
  &forced_choice_P.beta_Value_p,       /* 580: Block Parameter */
  &forced_choice_P.rho_Value_h,        /* 581: Block Parameter */
  &forced_choice_P.sigma_Value_o,      /* 582: Block Parameter */
  &forced_choice_P.timescale_Value_d,  /* 583: Block Parameter */
  &forced_choice_P.x_X0_l,             /* 584: Block Parameter */
  &forced_choice_P.y_X0_k,             /* 585: Block Parameter */
  &forced_choice_P.z_X0_n,             /* 586: Block Parameter */
  &forced_choice_P.beta_Value_e,       /* 587: Block Parameter */
  &forced_choice_P.rho_Value_n,        /* 588: Block Parameter */
  &forced_choice_P.sigma_Value_k4,     /* 589: Block Parameter */
  &forced_choice_P.timescale_Value_f,  /* 590: Block Parameter */
  &forced_choice_P.x_X0_c,             /* 591: Block Parameter */
  &forced_choice_P.y_X0_h,             /* 592: Block Parameter */
  &forced_choice_P.z_X0_b,             /* 593: Block Parameter */
  &forced_choice_P.Constant_Value,     /* 594: Block Parameter */
  &forced_choice_P.Constant_Value_l,   /* 595: Block Parameter */
  &forced_choice_P.DelayInput1_X0,     /* 596: Block Parameter */
  &forced_choice_P.Constant_Value_h,   /* 597: Block Parameter */
  &forced_choice_P.Constant1_Value,    /* 598: Block Parameter */
  &forced_choice_P.ScaleTouSec_Gain,   /* 599: Block Parameter */
  &forced_choice_P.PCI6025E_P1_f[0],   /* 600: Block Parameter */
  &forced_choice_P.PCI6025E_P2_h[0],   /* 601: Block Parameter */
  &forced_choice_P.PCI6025E_P3_e[0],   /* 602: Block Parameter */
  &forced_choice_P.PCI6025E_P4_g,      /* 603: Block Parameter */
  &forced_choice_P.PCI6025E_P5_h,      /* 604: Block Parameter */
  &forced_choice_P.PCI6025E_P6_f,      /* 605: Block Parameter */
  &forced_choice_P.PCI6025E_P7_g,      /* 606: Block Parameter */
  &forced_choice_P.xPCTargetTime_P1,   /* 607: Block Parameter */
  &forced_choice_P.xPCTargetTime_P2,   /* 608: Block Parameter */
  &forced_choice_P.Constant_Value_m2,  /* 609: Block Parameter */
  &forced_choice_P.Constant_Value_m    /* 610: Block Parameter */
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

  { rtBlockParameters, 239,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void forced_choice_InitializeDataMapInfo(rtModel_forced_choice
  *forced_choice_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(forced_choice_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(forced_choice_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(forced_choice_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(forced_choice_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(forced_choice_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(forced_choice_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(forced_choice_rtM->DataMapInfo.mmi, 0);
}

/* EOF: forced_choice_capi.c */
