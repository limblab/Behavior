/*
 * bump_follow_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "bump_follow.mdl".
 *
 * Model Version              : 1.1247
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Mon Aug 02 10:27:51 2010
 */

#include "bump_follow.h"
#include "rtw_capi.h"
#include "bump_follow_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Matrix Concatenation1",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Reshape",
    "", 0, 0, 1, 0, 0 },

  { 2, 0, "BCStimTable",
    "", 0, 0, 2, 0, 0 },

  { 3, 0, "Behavior BF/p1",
    "", 0, 0, 3, 0, 0 },

  { 4, 0, "Behavior BF/p2",
    "", 1, 0, 4, 0, 0 },

  { 5, 0, "Behavior BF/p3",
    "", 2, 0, 5, 0, 0 },

  { 6, 0, "Behavior BF/p4",
    "", 3, 0, 6, 0, 0 },

  { 7, 0, "Behavior BF/p5",
    "", 4, 0, 5, 0, 0 },

  { 8, 0, "Behavior BF/p6",
    "", 5, 0, 3, 0, 0 },

  { 9, 0, "Behavior BF/p7",
    "", 6, 0, 0, 0, 0 },

  { 10, 0, "Behavior BF/p8",
    "", 7, 0, 3, 0, 0 },

  { 11, 0, "BoundingBox/Logical Operator",
    "", 0, 1, 5, 0, 0 },

  { 12, 0, "BoundingBox/Relational Operator",
    "", 0, 1, 5, 0, 0 },

  { 13, 0, "BoundingBox/Relational Operator1",
    "", 0, 1, 5, 0, 0 },

  { 14, 0, "BoundingBox/Relational Operator2",
    "", 0, 1, 5, 0, 0 },

  { 15, 0, "BoundingBox/Relational Operator3",
    "", 0, 1, 5, 0, 0 },

  { 16, 1, "Catch Force Generator/Gain",
    "", 0, 0, 5, 0, 0 },

  { 17, 4, "Catch Force Generator/LorentzForceGain",
    "", 0, 0, 3, 0, 0 },

  { 18, 3, "Catch Force Generator/DynamicAngle Switch",
    "", 0, 0, 5, 0, 0 },

  { 19, 0, "Catch Force Generator/LoadSelect Switch",
    "", 0, 0, 3, 0, 0 },

  { 20, 7, "Force Generator/Gain",
    "", 0, 0, 5, 0, 0 },

  { 21, 10, "Force Generator/LorentzForceGain",
    "", 0, 0, 3, 0, 0 },

  { 22, 0, "Force Generator/Multiport Switch",
    "", 0, 0, 3, 0, 0 },

  { 23, 9, "Force Generator/dynamicAngle Switch",
    "", 0, 0, 5, 0, 0 },

  { 24, 0, "Motor Control/Matrix Concatenation",
    "", 0, 1, 3, 0, 0 },

  { 25, 0, "Motor Control/MG1",
    "", 0, 0, 5, 0, 0 },

  { 26, 0, "Motor Control/MG2",
    "", 0, 0, 5, 0, 0 },

  { 27, 0, "Motor Control/Logical Operator1",
    "", 0, 1, 5, 0, 0 },

  { 28, 0, "Motor Control/Memory",
    "", 0, 1, 5, 0, 0 },

  { 29, 16, "Motor Control/Switch1",
    "", 0, 0, 3, 0, 0 },

  { 30, 0, "Motor Control/Switch2",
    "", 0, 0, 3, 0, 0 },

  { 31, 0, "Recentering Subsystem/Data Type Conversion1",
    "", 0, 1, 5, 0, 0 },

  { 32, 0, "Recentering Subsystem/Data Type Conversion2",
    "", 0, 1, 5, 0, 0 },

  { 33, 14, "Recentering Subsystem/Bounding Box Viscosity",
    "", 0, 0, 3, 0, 0 },

  { 34, 0, "Recentering Subsystem/InBox",
    "", 0, 1, 5, 0, 0 },

  { 35, 0, "Recentering Subsystem/Logical Operator",
    "", 0, 1, 5, 0, 0 },

  { 36, 0, "Recentering Subsystem/Logical Operator1",
    "", 0, 1, 5, 0, 0 },

  { 37, 15, "Recentering Subsystem/Logical Operator3",
    "", 0, 1, 5, 0, 0 },

  { 38, 0, "Recentering Subsystem/Logical Operator5",
    "", 0, 1, 5, 0, 0 },

  { 39, 15, "Recentering Subsystem/Logical Operator6",
    "", 0, 1, 5, 0, 0 },

  { 40, 0, "Recentering Subsystem/NOT",
    "", 0, 1, 5, 0, 0 },

  { 41, 15, "Recentering Subsystem/Switch",
    "", 0, 0, 3, 0, 0 },

  { 42, 0, "RewardSbs/Data Type Conversion",
    "", 0, 0, 5, 0, 1 },

  { 43, 0, "RewardSbs/Relational Operator",
    "", 0, 1, 5, 0, 0 },

  { 44, 0, "RewardSbs/Switch",
    "", 0, 0, 5, 0, 0 },

  { 45, 0, "RewardSbs/Uniform Random Number",
    "", 0, 0, 5, 0, 0 },

  { 46, 0, "SendPacketToGraphics1/Rate Transition",
    "", 0, 2, 7, 0, 2 },

  { 47, 0, "SendPacketToGraphics1/Pack",
    "", 0, 2, 7, 0, 0 },

  { 48, 28, "Velocity Calculation/TachGain1",
    "", 0, 0, 5, 0, 0 },

  { 49, 28, "Velocity Calculation/TachGain2",
    "", 0, 0, 5, 0, 0 },

  { 50, 28, "Velocity Calculation/Matrix Multiply",
    "", 0, 0, 3, 0, 0 },

  { 51, 0, "Velocity Calculation/PCI-6025E AD/p1",
    "", 0, 0, 5, 0, 0 },

  { 52, 0, "Velocity Calculation/PCI-6025E AD/p2",
    "", 1, 0, 5, 0, 0 },

  { 53, 0, "Velocity Calculation/Switch",
    "", 0, 0, 3, 0, 0 },

  { 54, 0, "XY Position Subsystem/Gain",
    "", 0, 0, 5, 0, 0 },

  { 55, 0, "XY Position Subsystem/Gain1",
    "", 0, 0, 5, 0, 0 },

  { 56, 0, "XY Position Subsystem/PCI-QUAD04 ",
    "", 0, 0, 5, 0, 0 },

  { 57, 0, "XY Position Subsystem/PCI-QUAD04 1",
    "", 0, 0, 5, 0, 0 },

  { 58, 0, "XY Position Subsystem/Sum1",
    "", 0, 0, 5, 0, 0 },

  { 59, 0, "XY Position Subsystem/Sum3",
    "", 0, 0, 5, 0, 0 },

  { 60, 0, "Catch Force Generator/LorentzForce/Add",
    "", 0, 0, 5, 0, 0 },

  { 61, 4, "Catch Force Generator/LorentzForce/Add1",
    "", 0, 0, 5, 0, 0 },

  { 62, 3, "Catch Force Generator/ViscLoadSubsystem/Gain",
    "", 0, 0, 3, 0, 0 },

  { 63, 3, "Catch Force Generator/ViscLoadSubsystem/Inverter",
    "", 0, 0, 3, 0, 0 },

  { 64, 3, "Catch Force Generator/ViscLoadSubsystem/Product",
    "", 0, 0, 5, 0, 0 },

  { 65, 3, "Catch Force Generator/ViscLoadSubsystem/Product1",
    "", 0, 0, 5, 0, 0 },

  { 66, 3, "Catch Force Generator/ViscLoadSubsystem/Product2",
    "", 0, 0, 5, 0, 0 },

  { 67, 3, "Catch Force Generator/ViscLoadSubsystem/Product3",
    "", 0, 0, 5, 0, 0 },

  { 68, 3, "Catch Force Generator/ViscLoadSubsystem/Add",
    "", 0, 0, 5, 0, 0 },

  { 69, 3, "Catch Force Generator/ViscLoadSubsystem/Subtract",
    "", 0, 0, 5, 0, 0 },

  { 70, 3, "Catch Force Generator/ViscLoadSubsystem/cos",
    "", 0, 0, 5, 0, 0 },

  { 71, 3, "Catch Force Generator/ViscLoadSubsystem/sin",
    "", 0, 0, 5, 0, 0 },

  { 72, 0, "Force Generator/LorentzForce/Add",
    "", 0, 0, 5, 0, 0 },

  { 73, 10, "Force Generator/LorentzForce/Add1",
    "", 0, 0, 5, 0, 0 },

  { 74, 9, "Force Generator/ViscLoadSubsystem/Gain",
    "", 0, 0, 3, 0, 0 },

  { 75, 9, "Force Generator/ViscLoadSubsystem/Inverter",
    "", 0, 0, 3, 0, 0 },

  { 76, 9, "Force Generator/ViscLoadSubsystem/Product",
    "", 0, 0, 5, 0, 0 },

  { 77, 9, "Force Generator/ViscLoadSubsystem/Product1",
    "", 0, 0, 5, 0, 0 },

  { 78, 9, "Force Generator/ViscLoadSubsystem/Product2",
    "", 0, 0, 5, 0, 0 },

  { 79, 9, "Force Generator/ViscLoadSubsystem/Product3",
    "", 0, 0, 5, 0, 0 },

  { 80, 9, "Force Generator/ViscLoadSubsystem/Add",
    "", 0, 0, 5, 0, 0 },

  { 81, 9, "Force Generator/ViscLoadSubsystem/Subtract",
    "", 0, 0, 5, 0, 0 },

  { 82, 9, "Force Generator/ViscLoadSubsystem/cos",
    "", 0, 0, 5, 0, 0 },

  { 83, 9, "Force Generator/ViscLoadSubsystem/sin",
    "", 0, 0, 5, 0, 0 },

  { 84, 0, "Motor Control/Compare To Constant/Compare",
    "", 0, 2, 5, 0, 0 },

  { 85, 0, "Motor Control/Compare To Constant1/Compare",
    "", 0, 2, 5, 0, 0 },

  { 86, 18, "Motor Control/Force//Torque Transform/Gain",
    "", 0, 0, 3, 0, 0 },

  { 87, 18, "Motor Control/Force//Torque Transform/Matrix Multiply",
    "", 0, 0, 3, 0, 0 },

  { 88, 0, "Motor Control/Schmidt/Clock",
    "", 0, 0, 5, 0, 1 },

  { 89, 0, "Motor Control/Schmidt/Logical Operator",
    "", 0, 1, 5, 0, 0 },

  { 90, 0, "Motor Control/Schmidt/Logical Operator1",
    "", 0, 1, 5, 0, 0 },

  { 91, 0, "Motor Control/Schmidt/Logical Operator2",
    "", 0, 1, 5, 0, 0 },

  { 92, 0, "Motor Control/Schmidt/Memory",
    "", 0, 1, 5, 0, 0 },

  { 93, 0, "Motor Control/Schmidt/Relational Operator",
    "", 0, 1, 5, 0, 1 },

  { 94, 0, "Motor Control/Schmidt/Sum",
    "", 0, 0, 5, 0, 1 },

  { 95, 0, "Recentering Subsystem/Compare To Zero/Compare",
    "", 0, 2, 5, 0, 0 },

  { 96, 0, "Recentering Subsystem/Compare To Zero1/Compare",
    "", 0, 2, 5, 0, 0 },

  { 97, 0, "Recentering Subsystem/Falling Edge/FixPt Relational Operator",
    "", 0, 2, 5, 0, 0 },

  { 98, 0, "Recentering Subsystem/Falling Edge/Delay Input1",
    "U(k-1)", 0, 2, 5, 0, 0 },

  { 99, 0, "Recentering Subsystem/Falling Edge1/FixPt Relational Operator",
    "", 0, 2, 5, 0, 0 },

  { 100, 0, "Recentering Subsystem/Falling Edge1/Delay Input1",
    "U(k-1)", 0, 2, 5, 0, 0 },

  { 101, 0, "Recentering Subsystem/No Movement/Abs2",
    "", 0, 0, 5, 0, 0 },

  { 102, 0, "Recentering Subsystem/No Movement/Abs3",
    "", 0, 0, 5, 0, 0 },

  { 103, 0, "Recentering Subsystem/No Movement/Logical Operator1",
    "", 0, 1, 5, 0, 0 },

  { 104, 13, "Recentering Subsystem/PD Controller/Gain1",
    "", 0, 0, 5, 0, 0 },

  { 105, 13, "Recentering Subsystem/PD Controller/Gain2",
    "", 0, 0, 5, 0, 0 },

  { 106, 13, "Recentering Subsystem/PD Controller/Gain3",
    "", 0, 0, 5, 0, 0 },

  { 107, 13, "Recentering Subsystem/PD Controller/Gain4",
    "", 0, 0, 5, 0, 0 },

  { 108, 13, "Recentering Subsystem/PD Controller/Product",
    "", 0, 0, 5, 0, 0 },

  { 109, 13, "Recentering Subsystem/PD Controller/Product1",
    "", 0, 0, 5, 0, 0 },

  { 110, 13, "Recentering Subsystem/PD Controller/Saturation",
    "", 0, 0, 5, 0, 0 },

  { 111, 13, "Recentering Subsystem/PD Controller/Saturation1",
    "", 0, 0, 5, 0, 0 },

  { 112, 13, "Recentering Subsystem/PD Controller/Add",
    "", 0, 0, 5, 0, 0 },

  { 113, 13, "Recentering Subsystem/PD Controller/Add1",
    "", 0, 0, 5, 0, 0 },

  { 114, 0, "Recentering Subsystem/S-R Flip-Flop/Logic",
    "", 0, 1, 3, 0, 0 },

  { 115, 0, "Recentering Subsystem/S-R Flip-Flop/Memory",
    "", 0, 1, 5, 0, 0 },

  { 116, 0, "Recentering Subsystem/Schmidt1/Clock",
    "", 0, 0, 5, 0, 1 },

  { 117, 0, "Recentering Subsystem/Schmidt1/Logical Operator",
    "", 0, 1, 5, 0, 0 },

  { 118, 0, "Recentering Subsystem/Schmidt1/Logical Operator1",
    "", 0, 1, 5, 0, 0 },

  { 119, 0, "Recentering Subsystem/Schmidt1/Logical Operator2",
    "", 0, 1, 5, 0, 0 },

  { 120, 0, "Recentering Subsystem/Schmidt1/Memory",
    "", 0, 1, 5, 0, 0 },

  { 121, 0, "Recentering Subsystem/Schmidt1/Relational Operator",
    "", 0, 1, 5, 0, 1 },

  { 122, 0, "Recentering Subsystem/Schmidt1/Sum",
    "", 0, 0, 5, 0, 1 },

  { 123, 0, "Recentering Subsystem/Schmidt2/Clock",
    "", 0, 0, 5, 0, 1 },

  { 124, 0, "Recentering Subsystem/Schmidt2/Logical Operator",
    "", 0, 1, 5, 0, 0 },

  { 125, 0, "Recentering Subsystem/Schmidt2/Logical Operator1",
    "", 0, 1, 5, 0, 0 },

  { 126, 0, "Recentering Subsystem/Schmidt2/Logical Operator2",
    "", 0, 1, 5, 0, 0 },

  { 127, 0, "Recentering Subsystem/Schmidt2/Memory",
    "", 0, 1, 5, 0, 0 },

  { 128, 0, "Recentering Subsystem/Schmidt2/Relational Operator",
    "", 0, 1, 5, 0, 1 },

  { 129, 0, "Recentering Subsystem/Schmidt2/Sum",
    "", 0, 0, 5, 0, 1 },

  { 130, 0, "Recentering Subsystem/Schmidt3/Clock",
    "", 0, 0, 5, 0, 1 },

  { 131, 0, "Recentering Subsystem/Schmidt3/Logical Operator",
    "", 0, 1, 5, 0, 0 },

  { 132, 0, "Recentering Subsystem/Schmidt3/Logical Operator1",
    "", 0, 1, 5, 0, 0 },

  { 133, 0, "Recentering Subsystem/Schmidt3/Logical Operator2",
    "", 0, 1, 5, 0, 0 },

  { 134, 0, "Recentering Subsystem/Schmidt3/Memory",
    "", 0, 1, 5, 0, 0 },

  { 135, 0, "Recentering Subsystem/Schmidt3/Relational Operator",
    "", 0, 1, 5, 0, 1 },

  { 136, 0, "Recentering Subsystem/Schmidt3/Sum",
    "", 0, 0, 5, 0, 1 },

  { 137, 0, "Recentering Subsystem/Start Moving/FixPt Relational Operator",
    "", 0, 2, 5, 0, 0 },

  { 138, 0, "Recentering Subsystem/Start Moving/Delay Input1",
    "U(k-1)", 0, 2, 5, 0, 0 },

  { 139, 0, "Recentering Subsystem/Timer/Clock",
    "", 0, 0, 5, 0, 1 },

  { 140, 0, "Recentering Subsystem/Timer/Logical Operator",
    "", 0, 1, 5, 0, 0 },

  { 141, 0, "Recentering Subsystem/Timer/Logical Operator1",
    "", 0, 1, 5, 0, 0 },

  { 142, 0, "Recentering Subsystem/Timer/Logical Operator2",
    "", 0, 1, 5, 0, 0 },

  { 143, 0, "Recentering Subsystem/Timer/Logical Operator3",
    "", 0, 1, 5, 0, 0 },

  { 144, 0, "Recentering Subsystem/Timer/Logical Operator4",
    "", 0, 1, 5, 0, 0 },

  { 145, 0, "Recentering Subsystem/Timer/Logical Operator5",
    "", 0, 1, 5, 0, 0 },

  { 146, 0, "Recentering Subsystem/Timer/Memory",
    "", 0, 1, 5, 0, 0 },

  { 147, 0, "Recentering Subsystem/Timer/Relational Operator",
    "", 0, 1, 5, 0, 1 },

  { 148, 0, "Recentering Subsystem/Timer/Sum",
    "", 0, 0, 5, 0, 1 },

  { 149, 26, "RewardSbs/Sample and Hold/In",
    "", 0, 0, 5, 0, 3 },

  { 150, 0, "RewardSbs/Schmidt/Clock",
    "", 0, 0, 5, 0, 1 },

  { 151, 0, "RewardSbs/Schmidt/Relational Operator",
    "", 0, 1, 5, 0, 1 },

  { 152, 0, "RewardSbs/Schmidt/Sum",
    "", 0, 0, 5, 0, 1 },

  { 153, 0, "Velocity Calculation/Pos2VelX/Derivative",
    "", 0, 0, 5, 0, 1 },

  { 154, 0, "Velocity Calculation/Pos2VelX/dG",
    "", 0, 0, 5, 0, 0 },

  { 155, 0, "Velocity Calculation/Pos2VelX/Digital Filter",
    "", 0, 0, 5, 0, 0 },

  { 156, 0, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "", 0, 0, 5, 0, 0 },

  { 157, 0, "Velocity Calculation/Pos2VelY/Derivative",
    "", 0, 0, 5, 0, 1 },

  { 158, 0, "Velocity Calculation/Pos2VelY/dG",
    "", 0, 0, 5, 0, 0 },

  { 159, 0, "Velocity Calculation/Pos2VelY/Digital Filter",
    "", 0, 0, 5, 0, 0 },

  { 160, 0, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "", 0, 0, 5, 0, 0 },

  { 161, 0, "XY Position Subsystem/Cursor Rotation/sqrt(u[1]*u[1] + u[2]*u[2])",
    "", 0, 0, 5, 0, 0 },

  { 162, 0, "XY Position Subsystem/Cursor Rotation/Product",
    "", 0, 0, 5, 0, 0 },

  { 163, 0, "XY Position Subsystem/Cursor Rotation/Product1",
    "", 0, 0, 5, 0, 0 },

  { 164, 0, "XY Position Subsystem/Cursor Rotation/Sum",
    "", 0, 0, 5, 0, 0 },

  { 165, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function",
    "", 0, 0, 5, 0, 0 },

  { 166, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function1",
    "", 0, 0, 5, 0, 0 },

  { 167, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function2",
    "", 0, 0, 5, 0, 0 },

  { 168, 33, "XY Position Subsystem/For Iterator Subsystem/For Iterator",
    "", 0, 0, 5, 0, 3 },

  { 169, 33, "XY Position Subsystem/For Iterator Subsystem/SerialConverter",
    "", 0, 0, 5, 0, 3 },

  { 170, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p1",
    "", 0, 0, 5, 0, 3 },

  { 171, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p2",
    "", 1, 0, 5, 0, 3 },

  { 172, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p3",
    "", 2, 0, 5, 0, 3 },

  { 173, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p4",
    "", 3, 0, 5, 0, 3 },

  { 174, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p5",
    "", 4, 0, 5, 0, 3 },

  { 175, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p6",
    "", 5, 0, 5, 0, 3 },

  { 176, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p7",
    "", 6, 0, 5, 0, 3 },

  { 177, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p8",
    "", 7, 0, 5, 0, 3 },

  { 178, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p1",
    "", 0, 0, 5, 0, 3 },

  { 179, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p2",
    "", 1, 0, 5, 0, 3 },

  { 180, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p3",
    "", 2, 0, 5, 0, 3 },

  { 181, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p4",
    "", 3, 0, 5, 0, 3 },

  { 182, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p5",
    "", 4, 0, 5, 0, 3 },

  { 183, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p6",
    "", 5, 0, 5, 0, 3 },

  { 184, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p7",
    "", 6, 0, 5, 0, 3 },

  { 185, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p8",
    "", 7, 0, 5, 0, 3 },

  { 186, 33, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "", 0, 0, 5, 0, 3 },

  { 187, 33, "XY Position Subsystem/For Iterator Subsystem/Add",
    "", 0, 0, 5, 0, 3 },

  { 188, 33, "XY Position Subsystem/For Iterator Subsystem/Add1",
    "", 0, 0, 5, 0, 3 },

  { 189, 33, "XY Position Subsystem/For Iterator Subsystem/Switch",
    "", 0, 0, 5, 0, 3 },

  { 190, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate",
    "", 0, 0, 8, 0, 0 },

  { 191, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate1",
    "", 0, 0, 8, 0, 0 },

  { 192, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate2",
    "", 0, 0, 8, 0, 0 },

  { 193, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain",
    "", 0, 0, 8, 0, 0 },

  { 194, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain1",
    "", 0, 0, 8, 0, 0 },

  { 195, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain2",
    "", 0, 0, 8, 0, 0 },

  { 196, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product",
    "", 0, 0, 5, 0, 0 },

  { 197, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product1",
    "", 0, 0, 5, 0, 0 },

  { 198, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product2",
    "", 0, 0, 5, 0, 0 },

  { 199, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product3",
    "", 0, 0, 5, 0, 0 },

  { 200, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum1",
    "", 0, 0, 5, 0, 0 },

  { 201, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum2",
    "", 0, 0, 5, 0, 0 },

  { 202, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum3",
    "", 0, 0, 5, 0, 0 },

  { 203, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum4",
    "", 0, 0, 5, 0, 0 },

  { 204, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function",
    "", 0, 0, 5, 0, 0 },

  { 205, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function1",
    "", 0, 0, 5, 0, 0 },

  { 206, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function2",
    "", 0, 0, 5, 0, 0 },

  { 207, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function3",
    "", 0, 0, 5, 0, 0 },

  { 208, 0, "Catch Force Generator/LorentzForce/Lorentz/dX",
    "", 0, 0, 5, 0, 0 },

  { 209, 0, "Catch Force Generator/LorentzForce/Lorentz/dY",
    "", 0, 0, 5, 0, 0 },

  { 210, 0, "Catch Force Generator/LorentzForce/Lorentz/dZ",
    "", 0, 0, 5, 0, 0 },

  { 211, 0, "Catch Force Generator/LorentzForce/Lorentz/product1",
    "", 0, 0, 5, 0, 0 },

  { 212, 0, "Catch Force Generator/LorentzForce/Lorentz/product2",
    "", 0, 0, 5, 0, 0 },

  { 213, 0, "Catch Force Generator/LorentzForce/Lorentz/product3",
    "", 0, 0, 5, 0, 0 },

  { 214, 0, "Catch Force Generator/LorentzForce/Lorentz/product4",
    "", 0, 0, 5, 0, 0 },

  { 215, 0, "Catch Force Generator/LorentzForce/Lorentz/Add1",
    "", 0, 0, 5, 0, 0 },

  { 216, 0, "Catch Force Generator/LorentzForce/Lorentz/Add2",
    "", 0, 0, 5, 0, 0 },

  { 217, 0, "Catch Force Generator/LorentzForce/Lorentz/Add3",
    "", 0, 0, 5, 0, 0 },

  { 218, 0, "Catch Force Generator/LorentzForce/Lorentz/Add4",
    "", 0, 0, 5, 0, 0 },

  { 219, 0, "Catch Force Generator/LorentzForce/Lorentz/AddX",
    "", 0, 0, 5, 0, 0 },

  { 220, 0, "Catch Force Generator/LorentzForce/Lorentz/AddX1",
    "", 0, 0, 5, 0, 0 },

  { 221, 0, "Catch Force Generator/LorentzForce/Lorentz/AddX2",
    "", 0, 0, 5, 0, 0 },

  { 222, 0, "Catch Force Generator/LorentzForce/Lorentz/x",
    "", 0, 0, 5, 0, 0 },

  { 223, 0, "Catch Force Generator/LorentzForce/Lorentz/y",
    "", 0, 0, 5, 0, 0 },

  { 224, 0, "Catch Force Generator/LorentzForce/Lorentz/z",
    "", 0, 0, 5, 0, 0 },

  { 225, 0, "Catch Force Generator/LorentzForce/Lorentz1/dX",
    "", 0, 0, 5, 0, 0 },

  { 226, 0, "Catch Force Generator/LorentzForce/Lorentz1/dY",
    "", 0, 0, 5, 0, 0 },

  { 227, 0, "Catch Force Generator/LorentzForce/Lorentz1/dZ",
    "", 0, 0, 5, 0, 0 },

  { 228, 0, "Catch Force Generator/LorentzForce/Lorentz1/product1",
    "", 0, 0, 5, 0, 0 },

  { 229, 0, "Catch Force Generator/LorentzForce/Lorentz1/product2",
    "", 0, 0, 5, 0, 0 },

  { 230, 0, "Catch Force Generator/LorentzForce/Lorentz1/product3",
    "", 0, 0, 5, 0, 0 },

  { 231, 0, "Catch Force Generator/LorentzForce/Lorentz1/product4",
    "", 0, 0, 5, 0, 0 },

  { 232, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add1",
    "", 0, 0, 5, 0, 0 },

  { 233, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add2",
    "", 0, 0, 5, 0, 0 },

  { 234, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add3",
    "", 0, 0, 5, 0, 0 },

  { 235, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add4",
    "", 0, 0, 5, 0, 0 },

  { 236, 0, "Catch Force Generator/LorentzForce/Lorentz1/AddX",
    "", 0, 0, 5, 0, 0 },

  { 237, 0, "Catch Force Generator/LorentzForce/Lorentz1/AddX1",
    "", 0, 0, 5, 0, 0 },

  { 238, 0, "Catch Force Generator/LorentzForce/Lorentz1/AddX2",
    "", 0, 0, 5, 0, 0 },

  { 239, 0, "Catch Force Generator/LorentzForce/Lorentz1/x",
    "", 0, 0, 5, 0, 0 },

  { 240, 0, "Catch Force Generator/LorentzForce/Lorentz1/y",
    "", 0, 0, 5, 0, 0 },

  { 241, 0, "Catch Force Generator/LorentzForce/Lorentz1/z",
    "", 0, 0, 5, 0, 0 },

  { 242, 0, "Catch Force Generator/LorentzForce/Lorentz2/dX",
    "", 0, 0, 5, 0, 0 },

  { 243, 0, "Catch Force Generator/LorentzForce/Lorentz2/dY",
    "", 0, 0, 5, 0, 0 },

  { 244, 0, "Catch Force Generator/LorentzForce/Lorentz2/dZ",
    "", 0, 0, 5, 0, 0 },

  { 245, 0, "Catch Force Generator/LorentzForce/Lorentz2/product1",
    "", 0, 0, 5, 0, 0 },

  { 246, 0, "Catch Force Generator/LorentzForce/Lorentz2/product2",
    "", 0, 0, 5, 0, 0 },

  { 247, 0, "Catch Force Generator/LorentzForce/Lorentz2/product3",
    "", 0, 0, 5, 0, 0 },

  { 248, 0, "Catch Force Generator/LorentzForce/Lorentz2/product4",
    "", 0, 0, 5, 0, 0 },

  { 249, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add1",
    "", 0, 0, 5, 0, 0 },

  { 250, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add2",
    "", 0, 0, 5, 0, 0 },

  { 251, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add3",
    "", 0, 0, 5, 0, 0 },

  { 252, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add4",
    "", 0, 0, 5, 0, 0 },

  { 253, 0, "Catch Force Generator/LorentzForce/Lorentz2/AddX",
    "", 0, 0, 5, 0, 0 },

  { 254, 0, "Catch Force Generator/LorentzForce/Lorentz2/AddX1",
    "", 0, 0, 5, 0, 0 },

  { 255, 0, "Catch Force Generator/LorentzForce/Lorentz2/AddX2",
    "", 0, 0, 5, 0, 0 },

  { 256, 0, "Catch Force Generator/LorentzForce/Lorentz2/x",
    "", 0, 0, 5, 0, 0 },

  { 257, 0, "Catch Force Generator/LorentzForce/Lorentz2/y",
    "", 0, 0, 5, 0, 0 },

  { 258, 0, "Catch Force Generator/LorentzForce/Lorentz2/z",
    "", 0, 0, 5, 0, 0 },

  { 259, 0, "Catch Force Generator/LorentzForce/Lorentz3/dX",
    "", 0, 0, 5, 0, 0 },

  { 260, 0, "Catch Force Generator/LorentzForce/Lorentz3/dY",
    "", 0, 0, 5, 0, 0 },

  { 261, 0, "Catch Force Generator/LorentzForce/Lorentz3/dZ",
    "", 0, 0, 5, 0, 0 },

  { 262, 0, "Catch Force Generator/LorentzForce/Lorentz3/product1",
    "", 0, 0, 5, 0, 0 },

  { 263, 0, "Catch Force Generator/LorentzForce/Lorentz3/product2",
    "", 0, 0, 5, 0, 0 },

  { 264, 0, "Catch Force Generator/LorentzForce/Lorentz3/product3",
    "", 0, 0, 5, 0, 0 },

  { 265, 0, "Catch Force Generator/LorentzForce/Lorentz3/product4",
    "", 0, 0, 5, 0, 0 },

  { 266, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add1",
    "", 0, 0, 5, 0, 0 },

  { 267, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add2",
    "", 0, 0, 5, 0, 0 },

  { 268, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add3",
    "", 0, 0, 5, 0, 0 },

  { 269, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add4",
    "", 0, 0, 5, 0, 0 },

  { 270, 0, "Catch Force Generator/LorentzForce/Lorentz3/AddX",
    "", 0, 0, 5, 0, 0 },

  { 271, 0, "Catch Force Generator/LorentzForce/Lorentz3/AddX1",
    "", 0, 0, 5, 0, 0 },

  { 272, 0, "Catch Force Generator/LorentzForce/Lorentz3/AddX2",
    "", 0, 0, 5, 0, 0 },

  { 273, 0, "Catch Force Generator/LorentzForce/Lorentz3/x",
    "", 0, 0, 5, 0, 0 },

  { 274, 0, "Catch Force Generator/LorentzForce/Lorentz3/y",
    "", 0, 0, 5, 0, 0 },

  { 275, 0, "Catch Force Generator/LorentzForce/Lorentz3/z",
    "", 0, 0, 5, 0, 0 },

  { 276, 0, "Force Generator/LorentzForce/Lorentz/dX",
    "", 0, 0, 5, 0, 0 },

  { 277, 0, "Force Generator/LorentzForce/Lorentz/dY",
    "", 0, 0, 5, 0, 0 },

  { 278, 0, "Force Generator/LorentzForce/Lorentz/dZ",
    "", 0, 0, 5, 0, 0 },

  { 279, 0, "Force Generator/LorentzForce/Lorentz/product1",
    "", 0, 0, 5, 0, 0 },

  { 280, 0, "Force Generator/LorentzForce/Lorentz/product2",
    "", 0, 0, 5, 0, 0 },

  { 281, 0, "Force Generator/LorentzForce/Lorentz/product3",
    "", 0, 0, 5, 0, 0 },

  { 282, 0, "Force Generator/LorentzForce/Lorentz/product4",
    "", 0, 0, 5, 0, 0 },

  { 283, 0, "Force Generator/LorentzForce/Lorentz/Add1",
    "", 0, 0, 5, 0, 0 },

  { 284, 0, "Force Generator/LorentzForce/Lorentz/Add2",
    "", 0, 0, 5, 0, 0 },

  { 285, 0, "Force Generator/LorentzForce/Lorentz/Add3",
    "", 0, 0, 5, 0, 0 },

  { 286, 0, "Force Generator/LorentzForce/Lorentz/Add4",
    "", 0, 0, 5, 0, 0 },

  { 287, 0, "Force Generator/LorentzForce/Lorentz/AddX",
    "", 0, 0, 5, 0, 0 },

  { 288, 0, "Force Generator/LorentzForce/Lorentz/AddX1",
    "", 0, 0, 5, 0, 0 },

  { 289, 0, "Force Generator/LorentzForce/Lorentz/AddX2",
    "", 0, 0, 5, 0, 0 },

  { 290, 0, "Force Generator/LorentzForce/Lorentz/x",
    "", 0, 0, 5, 0, 0 },

  { 291, 0, "Force Generator/LorentzForce/Lorentz/y",
    "", 0, 0, 5, 0, 0 },

  { 292, 0, "Force Generator/LorentzForce/Lorentz/z",
    "", 0, 0, 5, 0, 0 },

  { 293, 0, "Force Generator/LorentzForce/Lorentz1/dX",
    "", 0, 0, 5, 0, 0 },

  { 294, 0, "Force Generator/LorentzForce/Lorentz1/dY",
    "", 0, 0, 5, 0, 0 },

  { 295, 0, "Force Generator/LorentzForce/Lorentz1/dZ",
    "", 0, 0, 5, 0, 0 },

  { 296, 0, "Force Generator/LorentzForce/Lorentz1/product1",
    "", 0, 0, 5, 0, 0 },

  { 297, 0, "Force Generator/LorentzForce/Lorentz1/product2",
    "", 0, 0, 5, 0, 0 },

  { 298, 0, "Force Generator/LorentzForce/Lorentz1/product3",
    "", 0, 0, 5, 0, 0 },

  { 299, 0, "Force Generator/LorentzForce/Lorentz1/product4",
    "", 0, 0, 5, 0, 0 },

  { 300, 0, "Force Generator/LorentzForce/Lorentz1/Add1",
    "", 0, 0, 5, 0, 0 },

  { 301, 0, "Force Generator/LorentzForce/Lorentz1/Add2",
    "", 0, 0, 5, 0, 0 },

  { 302, 0, "Force Generator/LorentzForce/Lorentz1/Add3",
    "", 0, 0, 5, 0, 0 },

  { 303, 0, "Force Generator/LorentzForce/Lorentz1/Add4",
    "", 0, 0, 5, 0, 0 },

  { 304, 0, "Force Generator/LorentzForce/Lorentz1/AddX",
    "", 0, 0, 5, 0, 0 },

  { 305, 0, "Force Generator/LorentzForce/Lorentz1/AddX1",
    "", 0, 0, 5, 0, 0 },

  { 306, 0, "Force Generator/LorentzForce/Lorentz1/AddX2",
    "", 0, 0, 5, 0, 0 },

  { 307, 0, "Force Generator/LorentzForce/Lorentz1/x",
    "", 0, 0, 5, 0, 0 },

  { 308, 0, "Force Generator/LorentzForce/Lorentz1/y",
    "", 0, 0, 5, 0, 0 },

  { 309, 0, "Force Generator/LorentzForce/Lorentz1/z",
    "", 0, 0, 5, 0, 0 },

  { 310, 0, "Force Generator/LorentzForce/Lorentz2/dX",
    "", 0, 0, 5, 0, 0 },

  { 311, 0, "Force Generator/LorentzForce/Lorentz2/dY",
    "", 0, 0, 5, 0, 0 },

  { 312, 0, "Force Generator/LorentzForce/Lorentz2/dZ",
    "", 0, 0, 5, 0, 0 },

  { 313, 0, "Force Generator/LorentzForce/Lorentz2/product1",
    "", 0, 0, 5, 0, 0 },

  { 314, 0, "Force Generator/LorentzForce/Lorentz2/product2",
    "", 0, 0, 5, 0, 0 },

  { 315, 0, "Force Generator/LorentzForce/Lorentz2/product3",
    "", 0, 0, 5, 0, 0 },

  { 316, 0, "Force Generator/LorentzForce/Lorentz2/product4",
    "", 0, 0, 5, 0, 0 },

  { 317, 0, "Force Generator/LorentzForce/Lorentz2/Add1",
    "", 0, 0, 5, 0, 0 },

  { 318, 0, "Force Generator/LorentzForce/Lorentz2/Add2",
    "", 0, 0, 5, 0, 0 },

  { 319, 0, "Force Generator/LorentzForce/Lorentz2/Add3",
    "", 0, 0, 5, 0, 0 },

  { 320, 0, "Force Generator/LorentzForce/Lorentz2/Add4",
    "", 0, 0, 5, 0, 0 },

  { 321, 0, "Force Generator/LorentzForce/Lorentz2/AddX",
    "", 0, 0, 5, 0, 0 },

  { 322, 0, "Force Generator/LorentzForce/Lorentz2/AddX1",
    "", 0, 0, 5, 0, 0 },

  { 323, 0, "Force Generator/LorentzForce/Lorentz2/AddX2",
    "", 0, 0, 5, 0, 0 },

  { 324, 0, "Force Generator/LorentzForce/Lorentz2/x",
    "", 0, 0, 5, 0, 0 },

  { 325, 0, "Force Generator/LorentzForce/Lorentz2/y",
    "", 0, 0, 5, 0, 0 },

  { 326, 0, "Force Generator/LorentzForce/Lorentz2/z",
    "", 0, 0, 5, 0, 0 },

  { 327, 0, "Force Generator/LorentzForce/Lorentz3/dX",
    "", 0, 0, 5, 0, 0 },

  { 328, 0, "Force Generator/LorentzForce/Lorentz3/dY",
    "", 0, 0, 5, 0, 0 },

  { 329, 0, "Force Generator/LorentzForce/Lorentz3/dZ",
    "", 0, 0, 5, 0, 0 },

  { 330, 0, "Force Generator/LorentzForce/Lorentz3/product1",
    "", 0, 0, 5, 0, 0 },

  { 331, 0, "Force Generator/LorentzForce/Lorentz3/product2",
    "", 0, 0, 5, 0, 0 },

  { 332, 0, "Force Generator/LorentzForce/Lorentz3/product3",
    "", 0, 0, 5, 0, 0 },

  { 333, 0, "Force Generator/LorentzForce/Lorentz3/product4",
    "", 0, 0, 5, 0, 0 },

  { 334, 0, "Force Generator/LorentzForce/Lorentz3/Add1",
    "", 0, 0, 5, 0, 0 },

  { 335, 0, "Force Generator/LorentzForce/Lorentz3/Add2",
    "", 0, 0, 5, 0, 0 },

  { 336, 0, "Force Generator/LorentzForce/Lorentz3/Add3",
    "", 0, 0, 5, 0, 0 },

  { 337, 0, "Force Generator/LorentzForce/Lorentz3/Add4",
    "", 0, 0, 5, 0, 0 },

  { 338, 0, "Force Generator/LorentzForce/Lorentz3/AddX",
    "", 0, 0, 5, 0, 0 },

  { 339, 0, "Force Generator/LorentzForce/Lorentz3/AddX1",
    "", 0, 0, 5, 0, 0 },

  { 340, 0, "Force Generator/LorentzForce/Lorentz3/AddX2",
    "", 0, 0, 5, 0, 0 },

  { 341, 0, "Force Generator/LorentzForce/Lorentz3/x",
    "", 0, 0, 5, 0, 0 },

  { 342, 0, "Force Generator/LorentzForce/Lorentz3/y",
    "", 0, 0, 5, 0, 0 },

  { 343, 0, "Force Generator/LorentzForce/Lorentz3/z",
    "", 0, 0, 5, 0, 0 },

  { 344, 18, "Motor Control/Force//Torque Transform/Transpose/Math Function",
    "", 0, 0, 8, 0, 0 },

  { 345, 0, "Motor Control/Schmidt/Compare To Zero/Compare",
    "", 0, 2, 5, 0, 1 },

  { 346, 19, "Motor Control/Schmidt/Enabled Subsystem/In1",
    "", 0, 0, 5, 0, 1 },

  { 347, 0, "Recentering Subsystem/Falling Edge/Nonpositive/Compare",
    "", 0, 2, 5, 0, 0 },

  { 348, 0, "Recentering Subsystem/Falling Edge1/Nonpositive/Compare",
    "", 0, 2, 5, 0, 0 },

  { 349, 0, "Recentering Subsystem/No Movement/Compare To Constant2/Compare",
    "", 0, 2, 5, 0, 0 },

  { 350, 0, "Recentering Subsystem/No Movement/Compare To Constant3/Compare",
    "", 0, 2, 5, 0, 0 },

  { 351, 0, "Recentering Subsystem/Schmidt1/Compare To Zero/Compare",
    "", 0, 2, 5, 0, 1 },

  { 352, 20, "Recentering Subsystem/Schmidt1/Enabled Subsystem/In1",
    "", 0, 0, 5, 0, 1 },

  { 353, 0, "Recentering Subsystem/Schmidt2/Compare To Zero/Compare",
    "", 0, 2, 5, 0, 1 },

  { 354, 21, "Recentering Subsystem/Schmidt2/Enabled Subsystem/In1",
    "", 0, 0, 5, 0, 1 },

  { 355, 0, "Recentering Subsystem/Schmidt3/Compare To Zero/Compare",
    "", 0, 2, 5, 0, 1 },

  { 356, 22, "Recentering Subsystem/Schmidt3/Enabled Subsystem/In1",
    "", 0, 0, 5, 0, 1 },

  { 357, 0, "Recentering Subsystem/Start Moving/Nonpositive/Compare",
    "", 0, 2, 5, 0, 0 },

  { 358, 0, "Recentering Subsystem/Timer/Compare To Zero/Compare",
    "", 0, 2, 5, 0, 1 },

  { 359, 0,
    "Recentering Subsystem/Timer/Detect Fall Nonpositive/FixPt Relational Operator",
    "", 0, 2, 5, 0, 0 },

  { 360, 0, "Recentering Subsystem/Timer/Detect Fall Nonpositive/Delay Input1",
    "U(k-1)", 0, 2, 5, 0, 0 },

  { 361, 23, "Recentering Subsystem/Timer/Enabled Subsystem/In1",
    "", 0, 0, 5, 0, 1 },

  { 362, 27, "RewardSbs/Schmidt/Sample and Hold/In",
    "", 0, 0, 5, 0, 3 },

  { 363, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "", 0, 0, 5, 0, 3 },

  { 364, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "", 0, 0, 5, 0, 3 },

  { 365, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Subtract",
    "", 0, 0, 5, 0, 3 },

  { 366, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Switch",
    "", 0, 0, 5, 0, 3 },

  { 367, 0,
    "Recentering Subsystem/Timer/Detect Fall Nonpositive/Nonpositive/Compare",
    "", 0, 2, 5, 0, 0 },

  { 368, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Compare",
    "", 0, 1, 5, 0, 3 },

  { 369, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1/Compare",
    "", 0, 1, 5, 0, 3 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 370, "Constant",
    "Value", 0, 5, 0 },

  { 371, "BCStimTable",
    "table", 0, 2, 0 },

  { 372, "Behavior BF",
    "P1", 0, 5, 0 },

  { 373, "Behavior BF",
    "P2", 0, 5, 0 },

  { 374, "Behavior BF",
    "P3", 0, 5, 0 },

  { 375, "Behavior BF",
    "P4", 0, 5, 0 },

  { 376, "Behavior BF",
    "P5", 0, 5, 0 },

  { 377, "Behavior BF",
    "P6", 0, 5, 0 },

  { 378, "Behavior BF",
    "P7", 0, 5, 0 },

  { 379, "Behavior BF",
    "P8", 0, 5, 0 },

  { 380, "Behavior BF",
    "P9", 0, 5, 0 },

  { 381, "Behavior BF",
    "P10", 0, 5, 0 },

  { 382, "Behavior BF",
    "P11", 0, 5, 0 },

  { 383, "Behavior BF",
    "P12", 0, 5, 0 },

  { 384, "Behavior BF",
    "P13", 0, 5, 0 },

  { 385, "Behavior BF",
    "P14", 0, 5, 0 },

  { 386, "Behavior BF",
    "P15", 0, 5, 0 },

  { 387, "Behavior BF",
    "P16", 0, 5, 0 },

  { 388, "Behavior BF",
    "P17", 0, 5, 0 },

  { 389, "Behavior BF",
    "P18", 0, 5, 0 },

  { 390, "BoundingBox/XHighLimit",
    "Value", 0, 5, 0 },

  { 391, "BoundingBox/XLowLimit",
    "Value", 0, 5, 0 },

  { 392, "BoundingBox/YHighLimit",
    "Value", 0, 5, 0 },

  { 393, "BoundingBox/YLowLimit",
    "Value", 0, 5, 0 },

  { 394, "Catch Force Generator/DynamicAngle",
    "Value", 0, 5, 0 },

  { 395, "Catch Force Generator/Load",
    "Value", 0, 5, 0 },

  { 396, "Catch Force Generator/Off",
    "Value", 0, 5, 0 },

  { 397, "Catch Force Generator/staticX",
    "Value", 0, 5, 0 },

  { 398, "Catch Force Generator/staticY",
    "Value", 0, 5, 0 },

  { 399, "Catch Force Generator/visAngle",
    "Value", 0, 5, 0 },

  { 400, "Catch Force Generator/Gain",
    "Gain", 0, 5, 0 },

  { 401, "Catch Force Generator/LorentzForceGain",
    "Gain", 0, 5, 0 },

  { 402, "Force Generator/DynamicAngle",
    "Value", 0, 5, 0 },

  { 403, "Force Generator/Load",
    "Value", 0, 5, 0 },

  { 404, "Force Generator/Off",
    "Value", 0, 5, 0 },

  { 405, "Force Generator/staticX",
    "Value", 0, 5, 0 },

  { 406, "Force Generator/staticY",
    "Value", 0, 5, 0 },

  { 407, "Force Generator/visAngle",
    "Value", 0, 5, 0 },

  { 408, "Force Generator/Gain",
    "Gain", 0, 5, 0 },

  { 409, "Force Generator/LorentzForceGain",
    "Gain", 0, 5, 0 },

  { 410, "Motor Control/zeroX",
    "Value", 0, 5, 0 },

  { 411, "Motor Control/zeroY",
    "Value", 0, 5, 0 },

  { 412, "Motor Control/MG1",
    "Gain", 0, 5, 0 },

  { 413, "Motor Control/MG2",
    "Gain", 0, 5, 0 },

  { 414, "Motor Control/Memory",
    "X0", 1, 5, 0 },

  { 415, "Motor Control/PCI-6025E ",
    "P1", 0, 9, 0 },

  { 416, "Motor Control/PCI-6025E ",
    "P2", 0, 9, 0 },

  { 417, "Motor Control/PCI-6025E ",
    "P3", 0, 9, 0 },

  { 418, "Motor Control/PCI-6025E ",
    "P4", 0, 9, 0 },

  { 419, "Motor Control/PCI-6025E ",
    "P5", 0, 5, 0 },

  { 420, "Motor Control/PCI-6025E ",
    "P6", 0, 5, 0 },

  { 421, "Motor Control/PCI-6025E ",
    "P7", 0, 5, 0 },

  { 422, "Recentering Subsystem/RecenterFlag",
    "Value", 0, 5, 0 },

  { 423, "Recentering Subsystem/Bounding Box Viscosity",
    "Gain", 0, 5, 0 },

  { 424, "RewardSbs/JackpotChance",
    "Value", 0, 5, 0 },

  { 425, "RewardSbs/RewardJackpot",
    "Value", 0, 5, 0 },

  { 426, "RewardSbs/RewardTime",
    "Value", 0, 5, 0 },

  { 427, "RewardSbs/Uniform Random Number",
    "Minimum", 0, 5, 0 },

  { 428, "RewardSbs/Uniform Random Number",
    "Maximum", 0, 5, 0 },

  { 429, "RewardSbs/Uniform Random Number",
    "Seed", 0, 5, 0 },

  { 430, "SendPacketToGraphics1/NaN upper bytes",
    "Value", 3, 5, 0 },

  { 431, "SendPacketToGraphics1/Packet Spec",
    "Value", 3, 5, 0 },

  { 432, "SendPacketToGraphics1/Send",
    "P1", 0, 10, 0 },

  { 433, "SendPacketToGraphics1/Send",
    "P2", 0, 5, 0 },

  { 434, "SendPacketToGraphics1/Send",
    "P3", 0, 5, 0 },

  { 435, "SendPacketToGraphics1/Send",
    "P4", 0, 5, 0 },

  { 436, "Velocity Calculation/UseTachs",
    "Value", 0, 5, 0 },

  { 437, "Velocity Calculation/TachGain1",
    "Gain", 0, 5, 0 },

  { 438, "Velocity Calculation/TachGain2",
    "Gain", 0, 5, 0 },

  { 439, "Velocity Calculation/PCI-6025E AD",
    "P1", 0, 9, 0 },

  { 440, "Velocity Calculation/PCI-6025E AD",
    "P2", 0, 9, 0 },

  { 441, "Velocity Calculation/PCI-6025E AD",
    "P3", 0, 9, 0 },

  { 442, "Velocity Calculation/PCI-6025E AD",
    "P4", 0, 5, 0 },

  { 443, "Velocity Calculation/PCI-6025E AD",
    "P5", 0, 5, 0 },

  { 444, "Velocity Calculation/PCI-6025E AD",
    "P6", 0, 5, 0 },

  { 445, "Velocity Calculation/Switch",
    "Threshold", 0, 5, 0 },

  { 446, "XY Position Subsystem/elbowOffset",
    "Value", 0, 5, 0 },

  { 447, "XY Position Subsystem/shoulderOffset",
    "Value", 0, 5, 0 },

  { 448, "XY Position Subsystem/Gain",
    "Gain", 0, 5, 0 },

  { 449, "XY Position Subsystem/Gain1",
    "Gain", 0, 5, 0 },

  { 450, "XY Position Subsystem/PCI-QUAD04 ",
    "P1", 0, 5, 0 },

  { 451, "XY Position Subsystem/PCI-QUAD04 ",
    "P2", 0, 5, 0 },

  { 452, "XY Position Subsystem/PCI-QUAD04 ",
    "P3", 0, 5, 0 },

  { 453, "XY Position Subsystem/PCI-QUAD04 ",
    "P4", 0, 5, 0 },

  { 454, "XY Position Subsystem/PCI-QUAD04 ",
    "P5", 0, 5, 0 },

  { 455, "XY Position Subsystem/PCI-QUAD04 ",
    "P6", 0, 5, 0 },

  { 456, "XY Position Subsystem/PCI-QUAD04 ",
    "P7", 0, 5, 0 },

  { 457, "XY Position Subsystem/PCI-QUAD04 ",
    "P8", 0, 5, 0 },

  { 458, "XY Position Subsystem/PCI-QUAD04 ",
    "P9", 0, 5, 0 },

  { 459, "XY Position Subsystem/PCI-QUAD04 ",
    "P10", 0, 5, 0 },

  { 460, "XY Position Subsystem/PCI-QUAD04 ",
    "P11", 0, 5, 0 },

  { 461, "XY Position Subsystem/PCI-QUAD04 1",
    "P1", 0, 5, 0 },

  { 462, "XY Position Subsystem/PCI-QUAD04 1",
    "P2", 0, 5, 0 },

  { 463, "XY Position Subsystem/PCI-QUAD04 1",
    "P3", 0, 5, 0 },

  { 464, "XY Position Subsystem/PCI-QUAD04 1",
    "P4", 0, 5, 0 },

  { 465, "XY Position Subsystem/PCI-QUAD04 1",
    "P5", 0, 5, 0 },

  { 466, "XY Position Subsystem/PCI-QUAD04 1",
    "P6", 0, 5, 0 },

  { 467, "XY Position Subsystem/PCI-QUAD04 1",
    "P7", 0, 5, 0 },

  { 468, "XY Position Subsystem/PCI-QUAD04 1",
    "P8", 0, 5, 0 },

  { 469, "XY Position Subsystem/PCI-QUAD04 1",
    "P9", 0, 5, 0 },

  { 470, "XY Position Subsystem/PCI-QUAD04 1",
    "P10", 0, 5, 0 },

  { 471, "XY Position Subsystem/PCI-QUAD04 1",
    "P11", 0, 5, 0 },

  { 472, "Catch Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 5, 0 },

  { 473, "Catch Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 5, 0 },

  { 474, "Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 5, 0 },

  { 475, "Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 5, 0 },

  { 476, "Motor Control/Compare To Constant/Constant",
    "Value", 0, 5, 0 },

  { 477, "Motor Control/Compare To Constant1/Constant",
    "Value", 0, 5, 0 },

  { 478, "Motor Control/Force//Torque Transform/Gain",
    "Gain", 0, 5, 0 },

  { 479, "Motor Control/Schmidt/Time",
    "Value", 0, 5, 0 },

  { 480, "Motor Control/Schmidt/Memory",
    "X0", 1, 5, 0 },

  { 481, "Recentering Subsystem/Falling Edge/Delay Input1",
    "X0", 2, 5, 0 },

  { 482, "Recentering Subsystem/Falling Edge1/Delay Input1",
    "X0", 2, 5, 0 },

  { 483, "Recentering Subsystem/PD Controller/Gain1",
    "Gain", 0, 5, 0 },

  { 484, "Recentering Subsystem/PD Controller/Gain2",
    "Gain", 0, 5, 0 },

  { 485, "Recentering Subsystem/PD Controller/Gain3",
    "Gain", 0, 5, 0 },

  { 486, "Recentering Subsystem/PD Controller/Gain4",
    "Gain", 0, 5, 0 },

  { 487, "Recentering Subsystem/PD Controller/Saturation",
    "UpperLimit", 0, 5, 0 },

  { 488, "Recentering Subsystem/PD Controller/Saturation",
    "LowerLimit", 0, 5, 0 },

  { 489, "Recentering Subsystem/PD Controller/Saturation1",
    "UpperLimit", 0, 5, 0 },

  { 490, "Recentering Subsystem/PD Controller/Saturation1",
    "LowerLimit", 0, 5, 0 },

  { 491, "Recentering Subsystem/S-R Flip-Flop/Logic",
    "TruthTable", 1, 11, 0 },

  { 492, "Recentering Subsystem/S-R Flip-Flop/Memory",
    "X0", 1, 5, 0 },

  { 493, "Recentering Subsystem/Schmidt1/Time",
    "Value", 0, 5, 0 },

  { 494, "Recentering Subsystem/Schmidt1/Memory",
    "X0", 1, 5, 0 },

  { 495, "Recentering Subsystem/Schmidt2/Time",
    "Value", 0, 5, 0 },

  { 496, "Recentering Subsystem/Schmidt2/Memory",
    "X0", 1, 5, 0 },

  { 497, "Recentering Subsystem/Schmidt3/Time",
    "Value", 0, 5, 0 },

  { 498, "Recentering Subsystem/Schmidt3/Memory",
    "X0", 1, 5, 0 },

  { 499, "Recentering Subsystem/Start Moving/Delay Input1",
    "X0", 2, 5, 0 },

  { 500, "Recentering Subsystem/Timer/Time",
    "Value", 0, 5, 0 },

  { 501, "Recentering Subsystem/Timer/Memory",
    "X0", 1, 5, 0 },

  { 502, "Velocity Calculation/Pos2VelX/dG",
    "Gain", 0, 5, 0 },

  { 503, "Velocity Calculation/Pos2VelX/Digital Filter",
    "ICRTP", 0, 5, 0 },

  { 504, "Velocity Calculation/Pos2VelX/Digital Filter",
    "RTP1COEFF", 0, 10, 0 },

  { 505, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "ICRTP", 0, 5, 0 },

  { 506, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "RTP1COEFF", 0, 10, 0 },

  { 507, "Velocity Calculation/Pos2VelY/dG",
    "Gain", 0, 5, 0 },

  { 508, "Velocity Calculation/Pos2VelY/Digital Filter",
    "ICRTP", 0, 5, 0 },

  { 509, "Velocity Calculation/Pos2VelY/Digital Filter",
    "RTP1COEFF", 0, 10, 0 },

  { 510, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "ICRTP", 0, 5, 0 },

  { 511, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "RTP1COEFF", 0, 10, 0 },

  { 512, "XY Position Subsystem/Cursor Rotation/AngleOffset",
    "Value", 0, 5, 0 },

  { 513, "XY Position Subsystem/For Iterator Subsystem/Constant",
    "Value", 0, 5, 0 },

  { 514, "XY Position Subsystem/For Iterator Subsystem/Constant2",
    "Value", 0, 5, 0 },

  { 515, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P1", 0, 12, 0 },

  { 516, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P2", 0, 5, 0 },

  { 517, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P3", 0, 12, 0 },

  { 518, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P4", 0, 12, 0 },

  { 519, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P5", 0, 5, 0 },

  { 520, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P6", 0, 5, 0 },

  { 521, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P7", 0, 5, 0 },

  { 522, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P8", 0, 5, 0 },

  { 523, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P9", 0, 5, 0 },

  { 524, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P1", 0, 12, 0 },

  { 525, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P2", 0, 5, 0 },

  { 526, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P3", 0, 12, 0 },

  { 527, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P4", 0, 12, 0 },

  { 528, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P5", 0, 5, 0 },

  { 529, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P6", 0, 5, 0 },

  { 530, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P7", 0, 5, 0 },

  { 531, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P8", 0, 5, 0 },

  { 532, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P9", 0, 5, 0 },

  { 533, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 5, 0 },

  { 534, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 5, 0 },

  { 535, "XY Position Subsystem/For Iterator Subsystem/Switch",
    "Threshold", 0, 5, 0 },

  { 536, "XY Position Subsystem/Jacobian-Cartesian Transformation/L1",
    "Value", 0, 5, 0 },

  { 537, "XY Position Subsystem/Jacobian-Cartesian Transformation/L2",
    "Value", 0, 5, 0 },

  { 538, "XY Position Subsystem/Jacobian-Cartesian Transformation/xoffset",
    "Value", 0, 5, 0 },

  { 539, "XY Position Subsystem/Jacobian-Cartesian Transformation/yoffset",
    "Value", 0, 5, 0 },

  { 540, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain",
    "Gain", 0, 5, 0 },

  { 541, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain1",
    "Gain", 0, 5, 0 },

  { 542, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain2",
    "Gain", 0, 5, 0 },

  { 543, "Catch Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 5, 0 },

  { 544, "Catch Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 5, 0 },

  { 545, "Catch Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 5, 0 },

  { 546, "Catch Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 5, 0 },

  { 547, "Catch Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 5, 0 },

  { 548, "Catch Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 5, 0 },

  { 549, "Catch Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 5, 0 },

  { 550, "Catch Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 5, 0 },

  { 551, "Catch Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 5, 0 },

  { 552, "Catch Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 5, 0 },

  { 553, "Catch Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 5, 0 },

  { 554, "Catch Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 5, 0 },

  { 555, "Catch Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 5, 0 },

  { 556, "Catch Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 5, 0 },

  { 557, "Catch Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 5, 0 },

  { 558, "Catch Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 5, 0 },

  { 559, "Catch Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 5, 0 },

  { 560, "Catch Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 5, 0 },

  { 561, "Catch Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 5, 0 },

  { 562, "Catch Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 5, 0 },

  { 563, "Catch Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 5, 0 },

  { 564, "Catch Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 5, 0 },

  { 565, "Catch Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 5, 0 },

  { 566, "Catch Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 5, 0 },

  { 567, "Catch Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 5, 0 },

  { 568, "Catch Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 5, 0 },

  { 569, "Catch Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 5, 0 },

  { 570, "Catch Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 5, 0 },

  { 571, "Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 5, 0 },

  { 572, "Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 5, 0 },

  { 573, "Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 5, 0 },

  { 574, "Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 5, 0 },

  { 575, "Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 5, 0 },

  { 576, "Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 5, 0 },

  { 577, "Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 5, 0 },

  { 578, "Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 5, 0 },

  { 579, "Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 5, 0 },

  { 580, "Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 5, 0 },

  { 581, "Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 5, 0 },

  { 582, "Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 5, 0 },

  { 583, "Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 5, 0 },

  { 584, "Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 5, 0 },

  { 585, "Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 5, 0 },

  { 586, "Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 5, 0 },

  { 587, "Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 5, 0 },

  { 588, "Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 5, 0 },

  { 589, "Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 5, 0 },

  { 590, "Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 5, 0 },

  { 591, "Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 5, 0 },

  { 592, "Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 5, 0 },

  { 593, "Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 5, 0 },

  { 594, "Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 5, 0 },

  { 595, "Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 5, 0 },

  { 596, "Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 5, 0 },

  { 597, "Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 5, 0 },

  { 598, "Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 5, 0 },

  { 599, "Recentering Subsystem/No Movement/Compare To Constant2/Constant",
    "Value", 0, 5, 0 },

  { 600, "Recentering Subsystem/No Movement/Compare To Constant3/Constant",
    "Value", 0, 5, 0 },

  { 601, "Recentering Subsystem/Timer/Detect Fall Nonpositive/Delay Input1",
    "X0", 2, 5, 0 },

  { 602,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant",
    "Value", 0, 5, 0 },

  { 603,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant1",
    "Value", 0, 5, 0 },

  { 604,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "Gain", 0, 5, 0 },

  { 605,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P1", 0, 9, 0 },

  { 606,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P2", 0, 9, 0 },

  { 607,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P3", 0, 9, 0 },

  { 608,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P4", 0, 5, 0 },

  { 609,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P5", 0, 5, 0 },

  { 610,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P6", 0, 5, 0 },

  { 611,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P7", 0, 5, 0 },

  { 612,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 5, 0 },

  { 613,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 5, 0 },

  { 614,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Constant",
    "Value", 0, 5, 0 },

  { 615,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1/Constant",
    "Value", 0, 5, 0 },

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
  &bump_follow_B.MatrixConcatenation1[0],/* 0: Signal */
  &bump_follow_B.Reshape[0],           /* 1: Signal */
  &bump_follow_B.BCStimTable[0],       /* 2: Signal */
  &bump_follow_B.BehaviorBF_o1[0],     /* 3: Signal */
  &bump_follow_B.BehaviorBF_o2[0],     /* 4: Signal */
  &bump_follow_B.BehaviorBF_o3,        /* 5: Signal */
  &bump_follow_B.BehaviorBF_o4[0],     /* 6: Signal */
  &bump_follow_B.BehaviorBF_o5,        /* 7: Signal */
  &bump_follow_B.BehaviorBF_o6[0],     /* 8: Signal */
  &bump_follow_B.BehaviorBF_o7[0],     /* 9: Signal */
  &bump_follow_B.BehaviorBF_o8[0],     /* 10: Signal */
  &bump_follow_B.LogicalOperator_a,    /* 11: Signal */
  &bump_follow_B.RelationalOperator_k, /* 12: Signal */
  &bump_follow_B.RelationalOperator1,  /* 13: Signal */
  &bump_follow_B.RelationalOperator2,  /* 14: Signal */
  &bump_follow_B.RelationalOperator3,  /* 15: Signal */
  &bump_follow_B.Gain_p,               /* 16: Signal */
  &bump_follow_B.LorentzForceGain_a[0],/* 17: Signal */
  &bump_follow_B.DynamicAngleSwitch,   /* 18: Signal */
  &bump_follow_B.LoadSelectSwitch[0],  /* 19: Signal */
  &bump_follow_B.Gain_o,               /* 20: Signal */
  &bump_follow_B.LorentzForceGain[0],  /* 21: Signal */
  &bump_follow_B.MultiportSwitch[0],   /* 22: Signal */
  &bump_follow_B.dynamicAngleSwitch,   /* 23: Signal */
  &bump_follow_B.MatrixConcatenation[0],/* 24: Signal */
  &bump_follow_B.MG1,                  /* 25: Signal */
  &bump_follow_B.MG2,                  /* 26: Signal */
  &bump_follow_B.LogicalOperator1_n,   /* 27: Signal */
  &bump_follow_B.Memory_d,             /* 28: Signal */
  &bump_follow_B.Switch1[0],           /* 29: Signal */
  &bump_follow_B.Switch2[0],           /* 30: Signal */
  &bump_follow_B.DataTypeConversion1,  /* 31: Signal */
  &bump_follow_B.DataTypeConversion2,  /* 32: Signal */
  &bump_follow_B.BoundingBoxViscosity[0],/* 33: Signal */
  &bump_follow_B.InBox,                /* 34: Signal */
  &bump_follow_B.LogicalOperator_c,    /* 35: Signal */
  &bump_follow_B.LogicalOperator1_l,   /* 36: Signal */
  &bump_follow_B.LogicalOperator3_d,   /* 37: Signal */
  &bump_follow_B.LogicalOperator5_k,   /* 38: Signal */
  &bump_follow_B.LogicalOperator6,     /* 39: Signal */
  &bump_follow_B.NOT,                  /* 40: Signal */
  &bump_follow_B.Switch_g[0],          /* 41: Signal */
  &bump_follow_B.DataTypeConversion,   /* 42: Signal */
  &bump_follow_B.RelationalOperator_d, /* 43: Signal */
  &bump_follow_B.Switch_p,             /* 44: Signal */
  &bump_follow_B.UniformRandomNumber,  /* 45: Signal */
  &bump_follow_B.RateTransition[0],    /* 46: Signal */
  &bump_follow_B.Pack[0],              /* 47: Signal */
  &bump_follow_B.TachGain1,            /* 48: Signal */
  &bump_follow_B.TachGain2,            /* 49: Signal */
  &bump_follow_B.MatrixMultiply[0],    /* 50: Signal */
  &bump_follow_B.PCI6025EAD_o1,        /* 51: Signal */
  &bump_follow_B.PCI6025EAD_o2,        /* 52: Signal */
  &bump_follow_B.Switch[0],            /* 53: Signal */
  &bump_follow_B.Gain,                 /* 54: Signal */
  &bump_follow_B.Gain1,                /* 55: Signal */
  &bump_follow_B.PCIQUAD04,            /* 56: Signal */
  &bump_follow_B.PCIQUAD041,           /* 57: Signal */
  &bump_follow_B.Sum1,                 /* 58: Signal */
  &bump_follow_B.Sum3,                 /* 59: Signal */
  &bump_follow_B.Add_h,                /* 60: Signal */
  &bump_follow_B.Add1_j,               /* 61: Signal */
  &bump_follow_B.Gain_f[0],            /* 62: Signal */
  &bump_follow_B.Inverter_o[0],        /* 63: Signal */
  &bump_follow_B.Product_g,            /* 64: Signal */
  &bump_follow_B.Product1_hu,          /* 65: Signal */
  &bump_follow_B.Product2_n,           /* 66: Signal */
  &bump_follow_B.Product3_m,           /* 67: Signal */
  &bump_follow_B.Add_j,                /* 68: Signal */
  &bump_follow_B.Subtract_k,           /* 69: Signal */
  &bump_follow_B.cos_n,                /* 70: Signal */
  &bump_follow_B.sin_c,                /* 71: Signal */
  &bump_follow_B.Add,                  /* 72: Signal */
  &bump_follow_B.Add1_k1,              /* 73: Signal */
  &bump_follow_B.Gain_b[0],            /* 74: Signal */
  &bump_follow_B.Inverter[0],          /* 75: Signal */
  &bump_follow_B.Product_n,            /* 76: Signal */
  &bump_follow_B.Product1_h,           /* 77: Signal */
  &bump_follow_B.Product2_j,           /* 78: Signal */
  &bump_follow_B.Product3_p,           /* 79: Signal */
  &bump_follow_B.Add_k,                /* 80: Signal */
  &bump_follow_B.Subtract_d,           /* 81: Signal */
  &bump_follow_B.cos_b,                /* 82: Signal */
  &bump_follow_B.sin_h,                /* 83: Signal */
  &bump_follow_B.Compare_eo,           /* 84: Signal */
  &bump_follow_B.Compare_pk,           /* 85: Signal */
  &bump_follow_B.Gain_j[0],            /* 86: Signal */
  &bump_follow_B.MatrixMultiply_g[0],  /* 87: Signal */
  &bump_follow_B.Clock,                /* 88: Signal */
  &bump_follow_B.LogicalOperator,      /* 89: Signal */
  &bump_follow_B.LogicalOperator1,     /* 90: Signal */
  &bump_follow_B.LogicalOperator2,     /* 91: Signal */
  &bump_follow_B.Memory,               /* 92: Signal */
  &bump_follow_B.RelationalOperator,   /* 93: Signal */
  &bump_follow_B.Sum,                  /* 94: Signal */
  &bump_follow_B.Compare_k,            /* 95: Signal */
  &bump_follow_B.Compare_i,            /* 96: Signal */
  &bump_follow_B.FixPtRelationalOperator_a,/* 97: Signal */
  &bump_follow_B.Uk1_p,                /* 98: Signal */
  &bump_follow_B.FixPtRelationalOperator_i,/* 99: Signal */
  &bump_follow_B.Uk1_m,                /* 100: Signal */
  &bump_follow_B.Abs2,                 /* 101: Signal */
  &bump_follow_B.Abs3,                 /* 102: Signal */
  &bump_follow_B.LogicalOperator1_d,   /* 103: Signal */
  &bump_follow_B.Gain1_l,              /* 104: Signal */
  &bump_follow_B.Gain2,                /* 105: Signal */
  &bump_follow_B.Gain3,                /* 106: Signal */
  &bump_follow_B.Gain4,                /* 107: Signal */
  &bump_follow_B.Product_m,            /* 108: Signal */
  &bump_follow_B.Product1_m,           /* 109: Signal */
  &bump_follow_B.Saturation,           /* 110: Signal */
  &bump_follow_B.Saturation1,          /* 111: Signal */
  &bump_follow_B.Add_p,                /* 112: Signal */
  &bump_follow_B.Add1_p,               /* 113: Signal */
  &bump_follow_B.Logic[0],             /* 114: Signal */
  &bump_follow_B.Memory_p,             /* 115: Signal */
  &bump_follow_B.Clock_j,              /* 116: Signal */
  &bump_follow_B.LogicalOperator_d,    /* 117: Signal */
  &bump_follow_B.LogicalOperator1_ef,  /* 118: Signal */
  &bump_follow_B.LogicalOperator2_b,   /* 119: Signal */
  &bump_follow_B.Memory_o,             /* 120: Signal */
  &bump_follow_B.RelationalOperator_b, /* 121: Signal */
  &bump_follow_B.Sum_j,                /* 122: Signal */
  &bump_follow_B.Clock_au,             /* 123: Signal */
  &bump_follow_B.LogicalOperator_b,    /* 124: Signal */
  &bump_follow_B.LogicalOperator1_o,   /* 125: Signal */
  &bump_follow_B.LogicalOperator2_c2,  /* 126: Signal */
  &bump_follow_B.Memory_g,             /* 127: Signal */
  &bump_follow_B.RelationalOperator_e, /* 128: Signal */
  &bump_follow_B.Sum_m,                /* 129: Signal */
  &bump_follow_B.Clock_a,              /* 130: Signal */
  &bump_follow_B.LogicalOperator_c3,   /* 131: Signal */
  &bump_follow_B.LogicalOperator1_a,   /* 132: Signal */
  &bump_follow_B.LogicalOperator2_c,   /* 133: Signal */
  &bump_follow_B.Memory_oj,            /* 134: Signal */
  &bump_follow_B.RelationalOperator_o, /* 135: Signal */
  &bump_follow_B.Sum_js,               /* 136: Signal */
  &bump_follow_B.FixPtRelationalOperator_d,/* 137: Signal */
  &bump_follow_B.Uk1_k,                /* 138: Signal */
  &bump_follow_B.Clock_n,              /* 139: Signal */
  &bump_follow_B.LogicalOperator_k,    /* 140: Signal */
  &bump_follow_B.LogicalOperator1_e,   /* 141: Signal */
  &bump_follow_B.LogicalOperator2_m,   /* 142: Signal */
  &bump_follow_B.LogicalOperator3,     /* 143: Signal */
  &bump_follow_B.LogicalOperator4,     /* 144: Signal */
  &bump_follow_B.LogicalOperator5,     /* 145: Signal */
  &bump_follow_B.Memory_m,             /* 146: Signal */
  &bump_follow_B.RelationalOperator_k4,/* 147: Signal */
  &bump_follow_B.Sum_e,                /* 148: Signal */
  &bump_follow_B.SampleandHold_k.In,   /* 149: Signal */
  &bump_follow_B.Clock_jl,             /* 150: Signal */
  &bump_follow_B.RelationalOperator_h, /* 151: Signal */
  &bump_follow_B.Sum_a,                /* 152: Signal */
  &bump_follow_B.Derivative,           /* 153: Signal */
  &bump_follow_B.dG,                   /* 154: Signal */
  &bump_follow_B.DigitalFilter,        /* 155: Signal */
  &bump_follow_B.DigitalFilter2,       /* 156: Signal */
  &bump_follow_B.Derivative_l,         /* 157: Signal */
  &bump_follow_B.dG_m,                 /* 158: Signal */
  &bump_follow_B.DigitalFilter_j,      /* 159: Signal */
  &bump_follow_B.DigitalFilter2_n,     /* 160: Signal */
  &bump_follow_B.sqrtu1u1u2u2,         /* 161: Signal */
  &bump_follow_B.Product_a,            /* 162: Signal */
  &bump_follow_B.Product1_c,           /* 163: Signal */
  &bump_follow_B.Sum_n,                /* 164: Signal */
  &bump_follow_B.TrigonometricFunction_d,/* 165: Signal */
  &bump_follow_B.TrigonometricFunction1_p,/* 166: Signal */
  &bump_follow_B.TrigonometricFunction2_p,/* 167: Signal */
  &bump_follow_B.ForIterator,          /* 168: Signal */
  &bump_follow_B.SerialConverter,      /* 169: Signal */
  &bump_follow_B.ToBits_o1,            /* 170: Signal */
  &bump_follow_B.ToBits_o2,            /* 171: Signal */
  &bump_follow_B.ToBits_o3,            /* 172: Signal */
  &bump_follow_B.ToBits_o4,            /* 173: Signal */
  &bump_follow_B.ToBits_o5,            /* 174: Signal */
  &bump_follow_B.ToBits_o6,            /* 175: Signal */
  &bump_follow_B.ToBits_o7,            /* 176: Signal */
  &bump_follow_B.ToBits_o8,            /* 177: Signal */
  &bump_follow_B.ToBits1_o1,           /* 178: Signal */
  &bump_follow_B.ToBits1_o2,           /* 179: Signal */
  &bump_follow_B.ToBits1_o3,           /* 180: Signal */
  &bump_follow_B.ToBits1_o4,           /* 181: Signal */
  &bump_follow_B.ToBits1_o5,           /* 182: Signal */
  &bump_follow_B.ToBits1_o6,           /* 183: Signal */
  &bump_follow_B.ToBits1_o7,           /* 184: Signal */
  &bump_follow_B.ToBits1_o8,           /* 185: Signal */
  &bump_follow_B.xPCTargetTime,        /* 186: Signal */
  &bump_follow_B.Add_e,                /* 187: Signal */
  &bump_follow_B.Add1_d,               /* 188: Signal */
  &bump_follow_B.Switch_f,             /* 189: Signal */
  &bump_follow_B.MatrixConcatenate2[0],/* 190: Signal */
  &bump_follow_B.MatrixConcatenate2[0],/* 191: Signal */
  &bump_follow_B.MatrixConcatenate2[0],/* 192: Signal */
  &bump_follow_B.MatrixConcatenate2[0],/* 193: Signal */
  &bump_follow_B.MatrixConcatenate2[0],/* 194: Signal */
  &bump_follow_B.MatrixConcatenate2[0],/* 195: Signal */
  &bump_follow_B.Product,              /* 196: Signal */
  &bump_follow_B.Product1,             /* 197: Signal */
  &bump_follow_B.Product2,             /* 198: Signal */
  &bump_follow_B.Product3,             /* 199: Signal */
  &bump_follow_B.Sum1_c,               /* 200: Signal */
  &bump_follow_B.Sum2,                 /* 201: Signal */
  &bump_follow_B.Sum3_n,               /* 202: Signal */
  &bump_follow_B.Sum4,                 /* 203: Signal */
  &bump_follow_B.TrigonometricFunction,/* 204: Signal */
  &bump_follow_B.TrigonometricFunction1,/* 205: Signal */
  &bump_follow_B.TrigonometricFunction2,/* 206: Signal */
  &bump_follow_B.TrigonometricFunction3,/* 207: Signal */
  &bump_follow_B.dX,                   /* 208: Signal */
  &bump_follow_B.dY,                   /* 209: Signal */
  &bump_follow_B.dZ,                   /* 210: Signal */
  &bump_follow_B.product1,             /* 211: Signal */
  &bump_follow_B.product2,             /* 212: Signal */
  &bump_follow_B.product3,             /* 213: Signal */
  &bump_follow_B.product4,             /* 214: Signal */
  &bump_follow_B.Add1,                 /* 215: Signal */
  &bump_follow_B.Add2,                 /* 216: Signal */
  &bump_follow_B.Add3,                 /* 217: Signal */
  &bump_follow_B.Add4,                 /* 218: Signal */
  &bump_follow_B.AddX,                 /* 219: Signal */
  &bump_follow_B.AddX1,                /* 220: Signal */
  &bump_follow_B.AddX2,                /* 221: Signal */
  &bump_follow_B.x_o,                  /* 222: Signal */
  &bump_follow_B.y,                    /* 223: Signal */
  &bump_follow_B.z,                    /* 224: Signal */
  &bump_follow_B.dX_c,                 /* 225: Signal */
  &bump_follow_B.dY_l,                 /* 226: Signal */
  &bump_follow_B.dZ_h,                 /* 227: Signal */
  &bump_follow_B.product1_h,           /* 228: Signal */
  &bump_follow_B.product2_d,           /* 229: Signal */
  &bump_follow_B.product3_o,           /* 230: Signal */
  &bump_follow_B.product4_l,           /* 231: Signal */
  &bump_follow_B.Add1_a,               /* 232: Signal */
  &bump_follow_B.Add2_p,               /* 233: Signal */
  &bump_follow_B.Add3_d,               /* 234: Signal */
  &bump_follow_B.Add4_j,               /* 235: Signal */
  &bump_follow_B.AddX_a,               /* 236: Signal */
  &bump_follow_B.AddX1_l,              /* 237: Signal */
  &bump_follow_B.AddX2_a,              /* 238: Signal */
  &bump_follow_B.x_l,                  /* 239: Signal */
  &bump_follow_B.y_e,                  /* 240: Signal */
  &bump_follow_B.z_o,                  /* 241: Signal */
  &bump_follow_B.dX_k,                 /* 242: Signal */
  &bump_follow_B.dY_e,                 /* 243: Signal */
  &bump_follow_B.dZ_d,                 /* 244: Signal */
  &bump_follow_B.product1_k,           /* 245: Signal */
  &bump_follow_B.product2_a,           /* 246: Signal */
  &bump_follow_B.product3_f,           /* 247: Signal */
  &bump_follow_B.product4_j,           /* 248: Signal */
  &bump_follow_B.Add1_e,               /* 249: Signal */
  &bump_follow_B.Add2_o,               /* 250: Signal */
  &bump_follow_B.Add3_n,               /* 251: Signal */
  &bump_follow_B.Add4_k,               /* 252: Signal */
  &bump_follow_B.AddX_n,               /* 253: Signal */
  &bump_follow_B.AddX1_i,              /* 254: Signal */
  &bump_follow_B.AddX2_b,              /* 255: Signal */
  &bump_follow_B.x_h,                  /* 256: Signal */
  &bump_follow_B.y_g,                  /* 257: Signal */
  &bump_follow_B.z_d,                  /* 258: Signal */
  &bump_follow_B.dX_m,                 /* 259: Signal */
  &bump_follow_B.dY_k,                 /* 260: Signal */
  &bump_follow_B.dZ_a,                 /* 261: Signal */
  &bump_follow_B.product1_g,           /* 262: Signal */
  &bump_follow_B.product2_ad,          /* 263: Signal */
  &bump_follow_B.product3_m,           /* 264: Signal */
  &bump_follow_B.product4_b,           /* 265: Signal */
  &bump_follow_B.Add1_k,               /* 266: Signal */
  &bump_follow_B.Add2_h,               /* 267: Signal */
  &bump_follow_B.Add3_e,               /* 268: Signal */
  &bump_follow_B.Add4_e,               /* 269: Signal */
  &bump_follow_B.AddX_l,               /* 270: Signal */
  &bump_follow_B.AddX1_b,              /* 271: Signal */
  &bump_follow_B.AddX2_k,              /* 272: Signal */
  &bump_follow_B.x_lk,                 /* 273: Signal */
  &bump_follow_B.y_h,                  /* 274: Signal */
  &bump_follow_B.z_a,                  /* 275: Signal */
  &bump_follow_B.dX_e,                 /* 276: Signal */
  &bump_follow_B.dY_g,                 /* 277: Signal */
  &bump_follow_B.dZ_o,                 /* 278: Signal */
  &bump_follow_B.product1_d,           /* 279: Signal */
  &bump_follow_B.product2_h,           /* 280: Signal */
  &bump_follow_B.product3_g,           /* 281: Signal */
  &bump_follow_B.product4_jz,          /* 282: Signal */
  &bump_follow_B.Add1_a5,              /* 283: Signal */
  &bump_follow_B.Add2_m,               /* 284: Signal */
  &bump_follow_B.Add3_m,               /* 285: Signal */
  &bump_follow_B.Add4_m,               /* 286: Signal */
  &bump_follow_B.AddX_lf,              /* 287: Signal */
  &bump_follow_B.AddX1_j,              /* 288: Signal */
  &bump_follow_B.AddX2_i,              /* 289: Signal */
  &bump_follow_B.x,                    /* 290: Signal */
  &bump_follow_B.y_f,                  /* 291: Signal */
  &bump_follow_B.z_f,                  /* 292: Signal */
  &bump_follow_B.dX_j,                 /* 293: Signal */
  &bump_follow_B.dY_i,                 /* 294: Signal */
  &bump_follow_B.dZ_n,                 /* 295: Signal */
  &bump_follow_B.product1_j,           /* 296: Signal */
  &bump_follow_B.product2_k,           /* 297: Signal */
  &bump_follow_B.product3_i,           /* 298: Signal */
  &bump_follow_B.product4_c,           /* 299: Signal */
  &bump_follow_B.Add1_h,               /* 300: Signal */
  &bump_follow_B.Add2_mo,              /* 301: Signal */
  &bump_follow_B.Add3_c,               /* 302: Signal */
  &bump_follow_B.Add4_a,               /* 303: Signal */
  &bump_follow_B.AddX_o,               /* 304: Signal */
  &bump_follow_B.AddX1_be,             /* 305: Signal */
  &bump_follow_B.AddX2_p,              /* 306: Signal */
  &bump_follow_B.x_a,                  /* 307: Signal */
  &bump_follow_B.y_m,                  /* 308: Signal */
  &bump_follow_B.z_dm,                 /* 309: Signal */
  &bump_follow_B.dX_eq,                /* 310: Signal */
  &bump_follow_B.dY_m,                 /* 311: Signal */
  &bump_follow_B.dZ_n4,                /* 312: Signal */
  &bump_follow_B.product1_n,           /* 313: Signal */
  &bump_follow_B.product2_l,           /* 314: Signal */
  &bump_follow_B.product3_a,           /* 315: Signal */
  &bump_follow_B.product4_g,           /* 316: Signal */
  &bump_follow_B.Add1_ap,              /* 317: Signal */
  &bump_follow_B.Add2_my,              /* 318: Signal */
  &bump_follow_B.Add3_j,               /* 319: Signal */
  &bump_follow_B.Add4_c,               /* 320: Signal */
  &bump_follow_B.AddX_c,               /* 321: Signal */
  &bump_follow_B.AddX1_f,              /* 322: Signal */
  &bump_follow_B.AddX2_e,              /* 323: Signal */
  &bump_follow_B.x_k,                  /* 324: Signal */
  &bump_follow_B.y_gr,                 /* 325: Signal */
  &bump_follow_B.z_h,                  /* 326: Signal */
  &bump_follow_B.dX_d,                 /* 327: Signal */
  &bump_follow_B.dY_iv,                /* 328: Signal */
  &bump_follow_B.dZ_b,                 /* 329: Signal */
  &bump_follow_B.product1_o,           /* 330: Signal */
  &bump_follow_B.product2_g,           /* 331: Signal */
  &bump_follow_B.product3_j,           /* 332: Signal */
  &bump_follow_B.product4_o,           /* 333: Signal */
  &bump_follow_B.Add1_o,               /* 334: Signal */
  &bump_follow_B.Add2_l,               /* 335: Signal */
  &bump_follow_B.Add3_do,              /* 336: Signal */
  &bump_follow_B.Add4_g,               /* 337: Signal */
  &bump_follow_B.AddX_k,               /* 338: Signal */
  &bump_follow_B.AddX1_m,              /* 339: Signal */
  &bump_follow_B.AddX2_ez,             /* 340: Signal */
  &bump_follow_B.x_j,                  /* 341: Signal */
  &bump_follow_B.y_d,                  /* 342: Signal */
  &bump_follow_B.z_k,                  /* 343: Signal */
  &bump_follow_B.MathFunction[0],      /* 344: Signal */
  &bump_follow_B.Compare,              /* 345: Signal */
  &bump_follow_B.EnabledSubsystem.In1, /* 346: Signal */
  &bump_follow_B.Compare_g,            /* 347: Signal */
  &bump_follow_B.Compare_eb,           /* 348: Signal */
  &bump_follow_B.Compare_e,            /* 349: Signal */
  &bump_follow_B.Compare_eu,           /* 350: Signal */
  &bump_follow_B.Compare_p,            /* 351: Signal */
  &bump_follow_B.EnabledSubsystem_d.In1,/* 352: Signal */
  &bump_follow_B.Compare_cj,           /* 353: Signal */
  &bump_follow_B.EnabledSubsystem_df.In1,/* 354: Signal */
  &bump_follow_B.Compare_c,            /* 355: Signal */
  &bump_follow_B.EnabledSubsystem_f.In1,/* 356: Signal */
  &bump_follow_B.Compare_j,            /* 357: Signal */
  &bump_follow_B.Compare_m,            /* 358: Signal */
  &bump_follow_B.FixPtRelationalOperator,/* 359: Signal */
  &bump_follow_B.Uk1,                  /* 360: Signal */
  &bump_follow_B.EnabledSubsystem_o.In1,/* 361: Signal */
  &bump_follow_B.SampleandHold.In,     /* 362: Signal */
  &bump_follow_B.ScaleTouSec,          /* 363: Signal */
  &bump_follow_B.xPCTargetTime_h,      /* 364: Signal */
  &bump_follow_B.Subtract,             /* 365: Signal */
  &bump_follow_B.Switch_e,             /* 366: Signal */
  &bump_follow_B.Compare_n,            /* 367: Signal */
  &bump_follow_B.Compare_l,            /* 368: Signal */
  &bump_follow_B.Compare_c3,           /* 369: Signal */
  &bump_follow_P.Constant_Value_l,     /* 370: Block Parameter */
  &bump_follow_P.BCStimTable_table[0], /* 371: Block Parameter */
  &bump_follow_P.BehaviorBF_P1,        /* 372: Block Parameter */
  &bump_follow_P.BehaviorBF_P2,        /* 373: Block Parameter */
  &bump_follow_P.BehaviorBF_P3,        /* 374: Block Parameter */
  &bump_follow_P.BehaviorBF_P4,        /* 375: Block Parameter */
  &bump_follow_P.BehaviorBF_P5,        /* 376: Block Parameter */
  &bump_follow_P.BehaviorBF_P6,        /* 377: Block Parameter */
  &bump_follow_P.BehaviorBF_P7,        /* 378: Block Parameter */
  &bump_follow_P.BehaviorBF_P8,        /* 379: Block Parameter */
  &bump_follow_P.BehaviorBF_P9,        /* 380: Block Parameter */
  &bump_follow_P.BehaviorBF_P10,       /* 381: Block Parameter */
  &bump_follow_P.BehaviorBF_P11,       /* 382: Block Parameter */
  &bump_follow_P.BehaviorBF_P12,       /* 383: Block Parameter */
  &bump_follow_P.BehaviorBF_P13,       /* 384: Block Parameter */
  &bump_follow_P.BehaviorBF_P14,       /* 385: Block Parameter */
  &bump_follow_P.BehaviorBF_P15,       /* 386: Block Parameter */
  &bump_follow_P.BehaviorBF_P16,       /* 387: Block Parameter */
  &bump_follow_P.BehaviorBF_P17,       /* 388: Block Parameter */
  &bump_follow_P.BehaviorBF_P18,       /* 389: Block Parameter */
  &bump_follow_P.XHighLimit_Value,     /* 390: Block Parameter */
  &bump_follow_P.XLowLimit_Value,      /* 391: Block Parameter */
  &bump_follow_P.YHighLimit_Value,     /* 392: Block Parameter */
  &bump_follow_P.YLowLimit_Value,      /* 393: Block Parameter */
  &bump_follow_P.DynamicAngle_Value,   /* 394: Block Parameter */
  &bump_follow_P.Load_Value_g,         /* 395: Block Parameter */
  &bump_follow_P.Off_Value,            /* 396: Block Parameter */
  &bump_follow_P.staticX_Value,        /* 397: Block Parameter */
  &bump_follow_P.staticY_Value,        /* 398: Block Parameter */
  &bump_follow_P.visAngle_Value,       /* 399: Block Parameter */
  &bump_follow_P.Gain_Gain_m,          /* 400: Block Parameter */
  &bump_follow_P.LorentzForceGain_Gain,/* 401: Block Parameter */
  &bump_follow_P.DynamicAngle_Value_l, /* 402: Block Parameter */
  &bump_follow_P.Load_Value,           /* 403: Block Parameter */
  &bump_follow_P.Off_Value_g,          /* 404: Block Parameter */
  &bump_follow_P.staticX_Value_f,      /* 405: Block Parameter */
  &bump_follow_P.staticY_Value_h,      /* 406: Block Parameter */
  &bump_follow_P.visAngle_Value_d,     /* 407: Block Parameter */
  &bump_follow_P.Gain_Gain_ex,         /* 408: Block Parameter */
  &bump_follow_P.LorentzForceGain_Gain_e,/* 409: Block Parameter */
  &bump_follow_P.zeroX_Value,          /* 410: Block Parameter */
  &bump_follow_P.zeroY_Value,          /* 411: Block Parameter */
  &bump_follow_P.MG1_Gain,             /* 412: Block Parameter */
  &bump_follow_P.MG2_Gain,             /* 413: Block Parameter */
  &bump_follow_P.Memory_X0_m,          /* 414: Block Parameter */
  &bump_follow_P.PCI6025E_P1[0],       /* 415: Block Parameter */
  &bump_follow_P.PCI6025E_P2[0],       /* 416: Block Parameter */
  &bump_follow_P.PCI6025E_P3[0],       /* 417: Block Parameter */
  &bump_follow_P.PCI6025E_P4[0],       /* 418: Block Parameter */
  &bump_follow_P.PCI6025E_P5,          /* 419: Block Parameter */
  &bump_follow_P.PCI6025E_P6,          /* 420: Block Parameter */
  &bump_follow_P.PCI6025E_P7,          /* 421: Block Parameter */
  &bump_follow_P.RecenterFlag_Value,   /* 422: Block Parameter */
  &bump_follow_P.BoundingBoxViscosity_Gain,/* 423: Block Parameter */
  &bump_follow_P.JackpotChance_Value,  /* 424: Block Parameter */
  &bump_follow_P.RewardJackpot_Value,  /* 425: Block Parameter */
  &bump_follow_P.RewardTime_Value,     /* 426: Block Parameter */
  &bump_follow_P.UniformRandomNumber_Min,/* 427: Block Parameter */
  &bump_follow_P.UniformRandomNumber_Max,/* 428: Block Parameter */
  &bump_follow_P.UniformRandomNumber_Seed,/* 429: Block Parameter */
  &bump_follow_P.NaNupperbytes_Value,  /* 430: Block Parameter */
  &bump_follow_P.PacketSpec_Value,     /* 431: Block Parameter */
  &bump_follow_P.Send_P1[0],           /* 432: Block Parameter */
  &bump_follow_P.Send_P2,              /* 433: Block Parameter */
  &bump_follow_P.Send_P3,              /* 434: Block Parameter */
  &bump_follow_P.Send_P4,              /* 435: Block Parameter */
  &bump_follow_P.UseTachs_Value,       /* 436: Block Parameter */
  &bump_follow_P.TachGain1_Gain,       /* 437: Block Parameter */
  &bump_follow_P.TachGain2_Gain,       /* 438: Block Parameter */
  &bump_follow_P.PCI6025EAD_P1[0],     /* 439: Block Parameter */
  &bump_follow_P.PCI6025EAD_P2[0],     /* 440: Block Parameter */
  &bump_follow_P.PCI6025EAD_P3[0],     /* 441: Block Parameter */
  &bump_follow_P.PCI6025EAD_P4,        /* 442: Block Parameter */
  &bump_follow_P.PCI6025EAD_P5,        /* 443: Block Parameter */
  &bump_follow_P.PCI6025EAD_P6,        /* 444: Block Parameter */
  &bump_follow_P.Switch_Threshold,     /* 445: Block Parameter */
  &bump_follow_P.elbowOffset_Value,    /* 446: Block Parameter */
  &bump_follow_P.shoulderOffset_Value, /* 447: Block Parameter */
  &bump_follow_P.Gain_Gain,            /* 448: Block Parameter */
  &bump_follow_P.Gain1_Gain,           /* 449: Block Parameter */
  &bump_follow_P.PCIQUAD04_P1,         /* 450: Block Parameter */
  &bump_follow_P.PCIQUAD04_P2,         /* 451: Block Parameter */
  &bump_follow_P.PCIQUAD04_P3,         /* 452: Block Parameter */
  &bump_follow_P.PCIQUAD04_P4,         /* 453: Block Parameter */
  &bump_follow_P.PCIQUAD04_P5,         /* 454: Block Parameter */
  &bump_follow_P.PCIQUAD04_P6,         /* 455: Block Parameter */
  &bump_follow_P.PCIQUAD04_P7,         /* 456: Block Parameter */
  &bump_follow_P.PCIQUAD04_P8,         /* 457: Block Parameter */
  &bump_follow_P.PCIQUAD04_P9,         /* 458: Block Parameter */
  &bump_follow_P.PCIQUAD04_P10,        /* 459: Block Parameter */
  &bump_follow_P.PCIQUAD04_P11,        /* 460: Block Parameter */
  &bump_follow_P.PCIQUAD041_P1,        /* 461: Block Parameter */
  &bump_follow_P.PCIQUAD041_P2,        /* 462: Block Parameter */
  &bump_follow_P.PCIQUAD041_P3,        /* 463: Block Parameter */
  &bump_follow_P.PCIQUAD041_P4,        /* 464: Block Parameter */
  &bump_follow_P.PCIQUAD041_P5,        /* 465: Block Parameter */
  &bump_follow_P.PCIQUAD041_P6,        /* 466: Block Parameter */
  &bump_follow_P.PCIQUAD041_P7,        /* 467: Block Parameter */
  &bump_follow_P.PCIQUAD041_P8,        /* 468: Block Parameter */
  &bump_follow_P.PCIQUAD041_P9,        /* 469: Block Parameter */
  &bump_follow_P.PCIQUAD041_P10,       /* 470: Block Parameter */
  &bump_follow_P.PCIQUAD041_P11,       /* 471: Block Parameter */
  &bump_follow_P.Gain_Gain_l,          /* 472: Block Parameter */
  &bump_follow_P.Inverter_Gain,        /* 473: Block Parameter */
  &bump_follow_P.Gain_Gain_j,          /* 474: Block Parameter */
  &bump_follow_P.Inverter_Gain_f,      /* 475: Block Parameter */
  &bump_follow_P.Constant_Value_d,     /* 476: Block Parameter */
  &bump_follow_P.Constant_Value_a,     /* 477: Block Parameter */
  &bump_follow_P.Gain_Gain_n,          /* 478: Block Parameter */
  &bump_follow_P.Time_Value,           /* 479: Block Parameter */
  &bump_follow_P.Memory_X0,            /* 480: Block Parameter */
  &bump_follow_P.DelayInput1_X0_i,     /* 481: Block Parameter */
  &bump_follow_P.DelayInput1_X0_m,     /* 482: Block Parameter */
  &bump_follow_P.Gain1_Gain_d,         /* 483: Block Parameter */
  &bump_follow_P.Gain2_Gain_i,         /* 484: Block Parameter */
  &bump_follow_P.Gain3_Gain,           /* 485: Block Parameter */
  &bump_follow_P.Gain4_Gain,           /* 486: Block Parameter */
  &bump_follow_P.Saturation_UpperSat,  /* 487: Block Parameter */
  &bump_follow_P.Saturation_LowerSat,  /* 488: Block Parameter */
  &bump_follow_P.Saturation1_UpperSat, /* 489: Block Parameter */
  &bump_follow_P.Saturation1_LowerSat, /* 490: Block Parameter */
  &bump_follow_P.Logic_table[0],       /* 491: Block Parameter */
  &bump_follow_P.Memory_X0_e,          /* 492: Block Parameter */
  &bump_follow_P.Time_Value_o,         /* 493: Block Parameter */
  &bump_follow_P.Memory_X0_n,          /* 494: Block Parameter */
  &bump_follow_P.Time_Value_i,         /* 495: Block Parameter */
  &bump_follow_P.Memory_X0_j,          /* 496: Block Parameter */
  &bump_follow_P.Time_Value_l,         /* 497: Block Parameter */
  &bump_follow_P.Memory_X0_p,          /* 498: Block Parameter */
  &bump_follow_P.DelayInput1_X0_h,     /* 499: Block Parameter */
  &bump_follow_P.Time_Value_c,         /* 500: Block Parameter */
  &bump_follow_P.Memory_X0_k,          /* 501: Block Parameter */
  &bump_follow_P.dG_Gain,              /* 502: Block Parameter */
  &bump_follow_P.DigitalFilter_ICRTP,  /* 503: Block Parameter */
  &bump_follow_P.DigitalFilter_RTP1COEFF[0],/* 504: Block Parameter */
  &bump_follow_P.DigitalFilter2_ICRTP, /* 505: Block Parameter */
  &bump_follow_P.DigitalFilter2_RTP1COEFF[0],/* 506: Block Parameter */
  &bump_follow_P.dG_Gain_l,            /* 507: Block Parameter */
  &bump_follow_P.DigitalFilter_ICRTP_n,/* 508: Block Parameter */
  &bump_follow_P.DigitalFilter_RTP1COEFF_b[0],/* 509: Block Parameter */
  &bump_follow_P.DigitalFilter2_ICRTP_h,/* 510: Block Parameter */
  &bump_follow_P.DigitalFilter2_RTP1COEFF_e[0],/* 511: Block Parameter */
  &bump_follow_P.AngleOffset_Value,    /* 512: Block Parameter */
  &bump_follow_P.Constant_Value_l1,    /* 513: Block Parameter */
  &bump_follow_P.Constant2_Value,      /* 514: Block Parameter */
  &bump_follow_P.PortA_P1[0],          /* 515: Block Parameter */
  &bump_follow_P.PortA_P2,             /* 516: Block Parameter */
  &bump_follow_P.PortA_P3[0],          /* 517: Block Parameter */
  &bump_follow_P.PortA_P4[0],          /* 518: Block Parameter */
  &bump_follow_P.PortA_P5,             /* 519: Block Parameter */
  &bump_follow_P.PortA_P6,             /* 520: Block Parameter */
  &bump_follow_P.PortA_P7,             /* 521: Block Parameter */
  &bump_follow_P.PortA_P8,             /* 522: Block Parameter */
  &bump_follow_P.PortA_P9,             /* 523: Block Parameter */
  &bump_follow_P.PortB_P1[0],          /* 524: Block Parameter */
  &bump_follow_P.PortB_P2,             /* 525: Block Parameter */
  &bump_follow_P.PortB_P3[0],          /* 526: Block Parameter */
  &bump_follow_P.PortB_P4[0],          /* 527: Block Parameter */
  &bump_follow_P.PortB_P5,             /* 528: Block Parameter */
  &bump_follow_P.PortB_P6,             /* 529: Block Parameter */
  &bump_follow_P.PortB_P7,             /* 530: Block Parameter */
  &bump_follow_P.PortB_P8,             /* 531: Block Parameter */
  &bump_follow_P.PortB_P9,             /* 532: Block Parameter */
  &bump_follow_P.xPCTargetTime_P1_f,   /* 533: Block Parameter */
  &bump_follow_P.xPCTargetTime_P2_m,   /* 534: Block Parameter */
  &bump_follow_P.Switch_Threshold_m,   /* 535: Block Parameter */
  &bump_follow_P.L1_Value,             /* 536: Block Parameter */
  &bump_follow_P.L2_Value,             /* 537: Block Parameter */
  &bump_follow_P.xoffset_Value,        /* 538: Block Parameter */
  &bump_follow_P.yoffset_Value,        /* 539: Block Parameter */
  &bump_follow_P.Gain_Gain_e,          /* 540: Block Parameter */
  &bump_follow_P.Gain1_Gain_o,         /* 541: Block Parameter */
  &bump_follow_P.Gain2_Gain,           /* 542: Block Parameter */
  &bump_follow_P.beta_Value,           /* 543: Block Parameter */
  &bump_follow_P.rho_Value,            /* 544: Block Parameter */
  &bump_follow_P.sigma_Value,          /* 545: Block Parameter */
  &bump_follow_P.timescale_Value,      /* 546: Block Parameter */
  &bump_follow_P.x_X0_p,               /* 547: Block Parameter */
  &bump_follow_P.y_X0,                 /* 548: Block Parameter */
  &bump_follow_P.z_X0,                 /* 549: Block Parameter */
  &bump_follow_P.beta_Value_c,         /* 550: Block Parameter */
  &bump_follow_P.rho_Value_c,          /* 551: Block Parameter */
  &bump_follow_P.sigma_Value_c,        /* 552: Block Parameter */
  &bump_follow_P.timescale_Value_p,    /* 553: Block Parameter */
  &bump_follow_P.x_X0_k,               /* 554: Block Parameter */
  &bump_follow_P.y_X0_e,               /* 555: Block Parameter */
  &bump_follow_P.z_X0_b,               /* 556: Block Parameter */
  &bump_follow_P.beta_Value_h,         /* 557: Block Parameter */
  &bump_follow_P.rho_Value_a,          /* 558: Block Parameter */
  &bump_follow_P.sigma_Value_f,        /* 559: Block Parameter */
  &bump_follow_P.timescale_Value_a,    /* 560: Block Parameter */
  &bump_follow_P.x_X0_e,               /* 561: Block Parameter */
  &bump_follow_P.y_X0_c,               /* 562: Block Parameter */
  &bump_follow_P.z_X0_c,               /* 563: Block Parameter */
  &bump_follow_P.beta_Value_g,         /* 564: Block Parameter */
  &bump_follow_P.rho_Value_e,          /* 565: Block Parameter */
  &bump_follow_P.sigma_Value_l,        /* 566: Block Parameter */
  &bump_follow_P.timescale_Value_o,    /* 567: Block Parameter */
  &bump_follow_P.x_X0_c,               /* 568: Block Parameter */
  &bump_follow_P.y_X0_ce,              /* 569: Block Parameter */
  &bump_follow_P.z_X0_d,               /* 570: Block Parameter */
  &bump_follow_P.beta_Value_o,         /* 571: Block Parameter */
  &bump_follow_P.rho_Value_k,          /* 572: Block Parameter */
  &bump_follow_P.sigma_Value_lo,       /* 573: Block Parameter */
  &bump_follow_P.timescale_Value_b,    /* 574: Block Parameter */
  &bump_follow_P.x_X0,                 /* 575: Block Parameter */
  &bump_follow_P.y_X0_p,               /* 576: Block Parameter */
  &bump_follow_P.z_X0_bq,              /* 577: Block Parameter */
  &bump_follow_P.beta_Value_hu,        /* 578: Block Parameter */
  &bump_follow_P.rho_Value_j,          /* 579: Block Parameter */
  &bump_follow_P.sigma_Value_m,        /* 580: Block Parameter */
  &bump_follow_P.timescale_Value_j,    /* 581: Block Parameter */
  &bump_follow_P.x_X0_o,               /* 582: Block Parameter */
  &bump_follow_P.y_X0_pj,              /* 583: Block Parameter */
  &bump_follow_P.z_X0_a,               /* 584: Block Parameter */
  &bump_follow_P.beta_Value_oe,        /* 585: Block Parameter */
  &bump_follow_P.rho_Value_o,          /* 586: Block Parameter */
  &bump_follow_P.sigma_Value_n,        /* 587: Block Parameter */
  &bump_follow_P.timescale_Value_jr,   /* 588: Block Parameter */
  &bump_follow_P.x_X0_h,               /* 589: Block Parameter */
  &bump_follow_P.y_X0_g,               /* 590: Block Parameter */
  &bump_follow_P.z_X0_m,               /* 591: Block Parameter */
  &bump_follow_P.beta_Value_m,         /* 592: Block Parameter */
  &bump_follow_P.rho_Value_ed,         /* 593: Block Parameter */
  &bump_follow_P.sigma_Value_j,        /* 594: Block Parameter */
  &bump_follow_P.timescale_Value_c,    /* 595: Block Parameter */
  &bump_follow_P.x_X0_g,               /* 596: Block Parameter */
  &bump_follow_P.y_X0_j,               /* 597: Block Parameter */
  &bump_follow_P.z_X0_h,               /* 598: Block Parameter */
  &bump_follow_P.Constant_Value,       /* 599: Block Parameter */
  &bump_follow_P.Constant_Value_e,     /* 600: Block Parameter */
  &bump_follow_P.DelayInput1_X0,       /* 601: Block Parameter */
  &bump_follow_P.Constant_Value_dj,    /* 602: Block Parameter */
  &bump_follow_P.Constant1_Value,      /* 603: Block Parameter */
  &bump_follow_P.ScaleTouSec_Gain,     /* 604: Block Parameter */
  &bump_follow_P.PCI6025E_P1_h[0],     /* 605: Block Parameter */
  &bump_follow_P.PCI6025E_P2_n[0],     /* 606: Block Parameter */
  &bump_follow_P.PCI6025E_P3_l[0],     /* 607: Block Parameter */
  &bump_follow_P.PCI6025E_P4_j,        /* 608: Block Parameter */
  &bump_follow_P.PCI6025E_P5_c,        /* 609: Block Parameter */
  &bump_follow_P.PCI6025E_P6_i,        /* 610: Block Parameter */
  &bump_follow_P.PCI6025E_P7_j,        /* 611: Block Parameter */
  &bump_follow_P.xPCTargetTime_P1,     /* 612: Block Parameter */
  &bump_follow_P.xPCTargetTime_P2,     /* 613: Block Parameter */
  &bump_follow_P.Constant_Value_b,     /* 614: Block Parameter */
  &bump_follow_P.Constant_Value_c      /* 615: Block Parameter */
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 }
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

  { rtwCAPI_MATRIX_COL_MAJOR, 2, 2 },

  { rtwCAPI_MATRIX_COL_MAJOR, 4, 2 },

  { rtwCAPI_VECTOR, 6, 2 },

  { rtwCAPI_VECTOR, 8, 2 },

  { rtwCAPI_SCALAR, 10, 2 },

  { rtwCAPI_VECTOR, 12, 2 },

  { rtwCAPI_VECTOR, 14, 2 },

  { rtwCAPI_MATRIX_COL_MAJOR, 16, 2 },

  { rtwCAPI_VECTOR, 18, 2 },

  { rtwCAPI_VECTOR, 20, 2 },

  { rtwCAPI_MATRIX_COL_MAJOR, 22, 2 },

  { rtwCAPI_VECTOR, 24, 2 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  4,                                   /* 0 */
  1,                                   /* 1 */
  32,                                  /* 2 */
  1,                                   /* 3 */
  2,                                   /* 4 */
  16,                                  /* 5 */
  2,                                   /* 6 */
  1,                                   /* 7 */
  5,                                   /* 8 */
  1,                                   /* 9 */
  1,                                   /* 10 */
  1,                                   /* 11 */
  15,                                  /* 12 */
  1,                                   /* 13 */
  168,                                 /* 14 */
  1,                                   /* 15 */
  2,                                   /* 16 */
  2,                                   /* 17 */
  1,                                   /* 18 */
  2,                                   /* 19 */
  1,                                   /* 20 */
  11,                                  /* 21 */
  8,                                   /* 22 */
  2,                                   /* 23 */
  1,                                   /* 24 */
  8                                    /* 25 */
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
  { rtBlockSignals, 370 },

  { rtBlockParameters, 246,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void bump_follow_InitializeDataMapInfo(rtModel_bump_follow *bump_follow_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(bump_follow_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(bump_follow_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(bump_follow_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(bump_follow_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(bump_follow_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(bump_follow_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(bump_follow_rtM->DataMapInfo.mmi, 0);
}

/* EOF: bump_follow_capi.c */
