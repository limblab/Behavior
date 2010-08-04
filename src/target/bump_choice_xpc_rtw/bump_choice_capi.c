/*
 * bump_choice_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "bump_choice.mdl".
 *
 * Model Version              : 1.1247
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Aug 04 10:30:55 2010
 */

#include "bump_choice.h"
#include "rtw_capi.h"
#include "bump_choice_private.h"

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

  { 3, 0, "Behavior BC/p1",
    "", 0, 0, 3, 0, 0 },

  { 4, 0, "Behavior BC/p2",
    "", 1, 0, 4, 0, 0 },

  { 5, 0, "Behavior BC/p3",
    "", 2, 0, 5, 0, 0 },

  { 6, 0, "Behavior BC/p4",
    "", 3, 0, 6, 0, 0 },

  { 7, 0, "Behavior BC/p5",
    "", 4, 0, 5, 0, 0 },

  { 8, 0, "Behavior BC/p6",
    "", 5, 0, 3, 0, 0 },

  { 9, 0, "Behavior BC/p7",
    "", 6, 0, 0, 0, 0 },

  { 10, 0, "Behavior BC/p8",
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

  { 372, "Behavior BC",
    "P1", 0, 5, 0 },

  { 373, "Behavior BC",
    "P2", 0, 5, 0 },

  { 374, "Behavior BC",
    "P3", 0, 5, 0 },

  { 375, "Behavior BC",
    "P4", 0, 5, 0 },

  { 376, "Behavior BC",
    "P5", 0, 5, 0 },

  { 377, "Behavior BC",
    "P6", 0, 5, 0 },

  { 378, "Behavior BC",
    "P7", 0, 5, 0 },

  { 379, "Behavior BC",
    "P8", 0, 5, 0 },

  { 380, "Behavior BC",
    "P9", 0, 5, 0 },

  { 381, "Behavior BC",
    "P10", 0, 5, 0 },

  { 382, "Behavior BC",
    "P11", 0, 5, 0 },

  { 383, "Behavior BC",
    "P12", 0, 5, 0 },

  { 384, "Behavior BC",
    "P13", 0, 5, 0 },

  { 385, "Behavior BC",
    "P14", 0, 5, 0 },

  { 386, "Behavior BC",
    "P15", 0, 5, 0 },

  { 387, "Behavior BC",
    "P16", 0, 5, 0 },

  { 388, "Behavior BC",
    "P17", 0, 5, 0 },

  { 389, "BoundingBox/XHighLimit",
    "Value", 0, 5, 0 },

  { 390, "BoundingBox/XLowLimit",
    "Value", 0, 5, 0 },

  { 391, "BoundingBox/YHighLimit",
    "Value", 0, 5, 0 },

  { 392, "BoundingBox/YLowLimit",
    "Value", 0, 5, 0 },

  { 393, "Catch Force Generator/DynamicAngle",
    "Value", 0, 5, 0 },

  { 394, "Catch Force Generator/Load",
    "Value", 0, 5, 0 },

  { 395, "Catch Force Generator/Off",
    "Value", 0, 5, 0 },

  { 396, "Catch Force Generator/staticX",
    "Value", 0, 5, 0 },

  { 397, "Catch Force Generator/staticY",
    "Value", 0, 5, 0 },

  { 398, "Catch Force Generator/visAngle",
    "Value", 0, 5, 0 },

  { 399, "Catch Force Generator/Gain",
    "Gain", 0, 5, 0 },

  { 400, "Catch Force Generator/LorentzForceGain",
    "Gain", 0, 5, 0 },

  { 401, "Force Generator/DynamicAngle",
    "Value", 0, 5, 0 },

  { 402, "Force Generator/Load",
    "Value", 0, 5, 0 },

  { 403, "Force Generator/Off",
    "Value", 0, 5, 0 },

  { 404, "Force Generator/staticX",
    "Value", 0, 5, 0 },

  { 405, "Force Generator/staticY",
    "Value", 0, 5, 0 },

  { 406, "Force Generator/visAngle",
    "Value", 0, 5, 0 },

  { 407, "Force Generator/Gain",
    "Gain", 0, 5, 0 },

  { 408, "Force Generator/LorentzForceGain",
    "Gain", 0, 5, 0 },

  { 409, "Motor Control/zeroX",
    "Value", 0, 5, 0 },

  { 410, "Motor Control/zeroY",
    "Value", 0, 5, 0 },

  { 411, "Motor Control/MG1",
    "Gain", 0, 5, 0 },

  { 412, "Motor Control/MG2",
    "Gain", 0, 5, 0 },

  { 413, "Motor Control/Memory",
    "X0", 1, 5, 0 },

  { 414, "Motor Control/PCI-6025E ",
    "P1", 0, 9, 0 },

  { 415, "Motor Control/PCI-6025E ",
    "P2", 0, 9, 0 },

  { 416, "Motor Control/PCI-6025E ",
    "P3", 0, 9, 0 },

  { 417, "Motor Control/PCI-6025E ",
    "P4", 0, 9, 0 },

  { 418, "Motor Control/PCI-6025E ",
    "P5", 0, 5, 0 },

  { 419, "Motor Control/PCI-6025E ",
    "P6", 0, 5, 0 },

  { 420, "Motor Control/PCI-6025E ",
    "P7", 0, 5, 0 },

  { 421, "Recentering Subsystem/RecenterFlag",
    "Value", 0, 5, 0 },

  { 422, "Recentering Subsystem/Bounding Box Viscosity",
    "Gain", 0, 5, 0 },

  { 423, "RewardSbs/JackpotChance",
    "Value", 0, 5, 0 },

  { 424, "RewardSbs/RewardJackpot",
    "Value", 0, 5, 0 },

  { 425, "RewardSbs/RewardTime",
    "Value", 0, 5, 0 },

  { 426, "RewardSbs/Uniform Random Number",
    "Minimum", 0, 5, 0 },

  { 427, "RewardSbs/Uniform Random Number",
    "Maximum", 0, 5, 0 },

  { 428, "RewardSbs/Uniform Random Number",
    "Seed", 0, 5, 0 },

  { 429, "SendPacketToGraphics1/NaN upper bytes",
    "Value", 3, 5, 0 },

  { 430, "SendPacketToGraphics1/Packet Spec",
    "Value", 3, 5, 0 },

  { 431, "SendPacketToGraphics1/Send",
    "P1", 0, 10, 0 },

  { 432, "SendPacketToGraphics1/Send",
    "P2", 0, 5, 0 },

  { 433, "SendPacketToGraphics1/Send",
    "P3", 0, 5, 0 },

  { 434, "SendPacketToGraphics1/Send",
    "P4", 0, 5, 0 },

  { 435, "Velocity Calculation/UseTachs",
    "Value", 0, 5, 0 },

  { 436, "Velocity Calculation/TachGain1",
    "Gain", 0, 5, 0 },

  { 437, "Velocity Calculation/TachGain2",
    "Gain", 0, 5, 0 },

  { 438, "Velocity Calculation/PCI-6025E AD",
    "P1", 0, 9, 0 },

  { 439, "Velocity Calculation/PCI-6025E AD",
    "P2", 0, 9, 0 },

  { 440, "Velocity Calculation/PCI-6025E AD",
    "P3", 0, 9, 0 },

  { 441, "Velocity Calculation/PCI-6025E AD",
    "P4", 0, 5, 0 },

  { 442, "Velocity Calculation/PCI-6025E AD",
    "P5", 0, 5, 0 },

  { 443, "Velocity Calculation/PCI-6025E AD",
    "P6", 0, 5, 0 },

  { 444, "Velocity Calculation/Switch",
    "Threshold", 0, 5, 0 },

  { 445, "XY Position Subsystem/elbowOffset",
    "Value", 0, 5, 0 },

  { 446, "XY Position Subsystem/shoulderOffset",
    "Value", 0, 5, 0 },

  { 447, "XY Position Subsystem/Gain",
    "Gain", 0, 5, 0 },

  { 448, "XY Position Subsystem/Gain1",
    "Gain", 0, 5, 0 },

  { 449, "XY Position Subsystem/PCI-QUAD04 ",
    "P1", 0, 5, 0 },

  { 450, "XY Position Subsystem/PCI-QUAD04 ",
    "P2", 0, 5, 0 },

  { 451, "XY Position Subsystem/PCI-QUAD04 ",
    "P3", 0, 5, 0 },

  { 452, "XY Position Subsystem/PCI-QUAD04 ",
    "P4", 0, 5, 0 },

  { 453, "XY Position Subsystem/PCI-QUAD04 ",
    "P5", 0, 5, 0 },

  { 454, "XY Position Subsystem/PCI-QUAD04 ",
    "P6", 0, 5, 0 },

  { 455, "XY Position Subsystem/PCI-QUAD04 ",
    "P7", 0, 5, 0 },

  { 456, "XY Position Subsystem/PCI-QUAD04 ",
    "P8", 0, 5, 0 },

  { 457, "XY Position Subsystem/PCI-QUAD04 ",
    "P9", 0, 5, 0 },

  { 458, "XY Position Subsystem/PCI-QUAD04 ",
    "P10", 0, 5, 0 },

  { 459, "XY Position Subsystem/PCI-QUAD04 ",
    "P11", 0, 5, 0 },

  { 460, "XY Position Subsystem/PCI-QUAD04 1",
    "P1", 0, 5, 0 },

  { 461, "XY Position Subsystem/PCI-QUAD04 1",
    "P2", 0, 5, 0 },

  { 462, "XY Position Subsystem/PCI-QUAD04 1",
    "P3", 0, 5, 0 },

  { 463, "XY Position Subsystem/PCI-QUAD04 1",
    "P4", 0, 5, 0 },

  { 464, "XY Position Subsystem/PCI-QUAD04 1",
    "P5", 0, 5, 0 },

  { 465, "XY Position Subsystem/PCI-QUAD04 1",
    "P6", 0, 5, 0 },

  { 466, "XY Position Subsystem/PCI-QUAD04 1",
    "P7", 0, 5, 0 },

  { 467, "XY Position Subsystem/PCI-QUAD04 1",
    "P8", 0, 5, 0 },

  { 468, "XY Position Subsystem/PCI-QUAD04 1",
    "P9", 0, 5, 0 },

  { 469, "XY Position Subsystem/PCI-QUAD04 1",
    "P10", 0, 5, 0 },

  { 470, "XY Position Subsystem/PCI-QUAD04 1",
    "P11", 0, 5, 0 },

  { 471, "Catch Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 5, 0 },

  { 472, "Catch Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 5, 0 },

  { 473, "Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 5, 0 },

  { 474, "Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 5, 0 },

  { 475, "Motor Control/Compare To Constant/Constant",
    "Value", 0, 5, 0 },

  { 476, "Motor Control/Compare To Constant1/Constant",
    "Value", 0, 5, 0 },

  { 477, "Motor Control/Force//Torque Transform/Gain",
    "Gain", 0, 5, 0 },

  { 478, "Motor Control/Schmidt/Time",
    "Value", 0, 5, 0 },

  { 479, "Motor Control/Schmidt/Memory",
    "X0", 1, 5, 0 },

  { 480, "Recentering Subsystem/Falling Edge/Delay Input1",
    "X0", 2, 5, 0 },

  { 481, "Recentering Subsystem/Falling Edge1/Delay Input1",
    "X0", 2, 5, 0 },

  { 482, "Recentering Subsystem/PD Controller/Gain1",
    "Gain", 0, 5, 0 },

  { 483, "Recentering Subsystem/PD Controller/Gain2",
    "Gain", 0, 5, 0 },

  { 484, "Recentering Subsystem/PD Controller/Gain3",
    "Gain", 0, 5, 0 },

  { 485, "Recentering Subsystem/PD Controller/Gain4",
    "Gain", 0, 5, 0 },

  { 486, "Recentering Subsystem/PD Controller/Saturation",
    "UpperLimit", 0, 5, 0 },

  { 487, "Recentering Subsystem/PD Controller/Saturation",
    "LowerLimit", 0, 5, 0 },

  { 488, "Recentering Subsystem/PD Controller/Saturation1",
    "UpperLimit", 0, 5, 0 },

  { 489, "Recentering Subsystem/PD Controller/Saturation1",
    "LowerLimit", 0, 5, 0 },

  { 490, "Recentering Subsystem/S-R Flip-Flop/Logic",
    "TruthTable", 1, 11, 0 },

  { 491, "Recentering Subsystem/S-R Flip-Flop/Memory",
    "X0", 1, 5, 0 },

  { 492, "Recentering Subsystem/Schmidt1/Time",
    "Value", 0, 5, 0 },

  { 493, "Recentering Subsystem/Schmidt1/Memory",
    "X0", 1, 5, 0 },

  { 494, "Recentering Subsystem/Schmidt2/Time",
    "Value", 0, 5, 0 },

  { 495, "Recentering Subsystem/Schmidt2/Memory",
    "X0", 1, 5, 0 },

  { 496, "Recentering Subsystem/Schmidt3/Time",
    "Value", 0, 5, 0 },

  { 497, "Recentering Subsystem/Schmidt3/Memory",
    "X0", 1, 5, 0 },

  { 498, "Recentering Subsystem/Start Moving/Delay Input1",
    "X0", 2, 5, 0 },

  { 499, "Recentering Subsystem/Timer/Time",
    "Value", 0, 5, 0 },

  { 500, "Recentering Subsystem/Timer/Memory",
    "X0", 1, 5, 0 },

  { 501, "Velocity Calculation/Pos2VelX/dG",
    "Gain", 0, 5, 0 },

  { 502, "Velocity Calculation/Pos2VelX/Digital Filter",
    "ICRTP", 0, 5, 0 },

  { 503, "Velocity Calculation/Pos2VelX/Digital Filter",
    "RTP1COEFF", 0, 10, 0 },

  { 504, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "ICRTP", 0, 5, 0 },

  { 505, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "RTP1COEFF", 0, 10, 0 },

  { 506, "Velocity Calculation/Pos2VelY/dG",
    "Gain", 0, 5, 0 },

  { 507, "Velocity Calculation/Pos2VelY/Digital Filter",
    "ICRTP", 0, 5, 0 },

  { 508, "Velocity Calculation/Pos2VelY/Digital Filter",
    "RTP1COEFF", 0, 10, 0 },

  { 509, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "ICRTP", 0, 5, 0 },

  { 510, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "RTP1COEFF", 0, 10, 0 },

  { 511, "XY Position Subsystem/Cursor Rotation/AngleOffset",
    "Value", 0, 5, 0 },

  { 512, "XY Position Subsystem/For Iterator Subsystem/Constant",
    "Value", 0, 5, 0 },

  { 513, "XY Position Subsystem/For Iterator Subsystem/Constant2",
    "Value", 0, 5, 0 },

  { 514, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P1", 0, 12, 0 },

  { 515, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P2", 0, 5, 0 },

  { 516, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P3", 0, 12, 0 },

  { 517, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P4", 0, 12, 0 },

  { 518, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P5", 0, 5, 0 },

  { 519, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P6", 0, 5, 0 },

  { 520, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P7", 0, 5, 0 },

  { 521, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P8", 0, 5, 0 },

  { 522, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P9", 0, 5, 0 },

  { 523, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P1", 0, 12, 0 },

  { 524, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P2", 0, 5, 0 },

  { 525, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P3", 0, 12, 0 },

  { 526, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P4", 0, 12, 0 },

  { 527, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P5", 0, 5, 0 },

  { 528, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P6", 0, 5, 0 },

  { 529, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P7", 0, 5, 0 },

  { 530, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P8", 0, 5, 0 },

  { 531, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P9", 0, 5, 0 },

  { 532, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 5, 0 },

  { 533, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 5, 0 },

  { 534, "XY Position Subsystem/For Iterator Subsystem/Switch",
    "Threshold", 0, 5, 0 },

  { 535, "XY Position Subsystem/Jacobian-Cartesian Transformation/L1",
    "Value", 0, 5, 0 },

  { 536, "XY Position Subsystem/Jacobian-Cartesian Transformation/L2",
    "Value", 0, 5, 0 },

  { 537, "XY Position Subsystem/Jacobian-Cartesian Transformation/xoffset",
    "Value", 0, 5, 0 },

  { 538, "XY Position Subsystem/Jacobian-Cartesian Transformation/yoffset",
    "Value", 0, 5, 0 },

  { 539, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain",
    "Gain", 0, 5, 0 },

  { 540, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain1",
    "Gain", 0, 5, 0 },

  { 541, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain2",
    "Gain", 0, 5, 0 },

  { 542, "Catch Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 5, 0 },

  { 543, "Catch Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 5, 0 },

  { 544, "Catch Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 5, 0 },

  { 545, "Catch Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 5, 0 },

  { 546, "Catch Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 5, 0 },

  { 547, "Catch Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 5, 0 },

  { 548, "Catch Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 5, 0 },

  { 549, "Catch Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 5, 0 },

  { 550, "Catch Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 5, 0 },

  { 551, "Catch Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 5, 0 },

  { 552, "Catch Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 5, 0 },

  { 553, "Catch Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 5, 0 },

  { 554, "Catch Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 5, 0 },

  { 555, "Catch Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 5, 0 },

  { 556, "Catch Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 5, 0 },

  { 557, "Catch Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 5, 0 },

  { 558, "Catch Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 5, 0 },

  { 559, "Catch Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 5, 0 },

  { 560, "Catch Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 5, 0 },

  { 561, "Catch Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 5, 0 },

  { 562, "Catch Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 5, 0 },

  { 563, "Catch Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 5, 0 },

  { 564, "Catch Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 5, 0 },

  { 565, "Catch Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 5, 0 },

  { 566, "Catch Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 5, 0 },

  { 567, "Catch Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 5, 0 },

  { 568, "Catch Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 5, 0 },

  { 569, "Catch Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 5, 0 },

  { 570, "Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 5, 0 },

  { 571, "Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 5, 0 },

  { 572, "Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 5, 0 },

  { 573, "Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 5, 0 },

  { 574, "Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 5, 0 },

  { 575, "Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 5, 0 },

  { 576, "Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 5, 0 },

  { 577, "Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 5, 0 },

  { 578, "Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 5, 0 },

  { 579, "Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 5, 0 },

  { 580, "Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 5, 0 },

  { 581, "Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 5, 0 },

  { 582, "Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 5, 0 },

  { 583, "Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 5, 0 },

  { 584, "Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 5, 0 },

  { 585, "Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 5, 0 },

  { 586, "Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 5, 0 },

  { 587, "Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 5, 0 },

  { 588, "Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 5, 0 },

  { 589, "Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 5, 0 },

  { 590, "Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 5, 0 },

  { 591, "Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 5, 0 },

  { 592, "Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 5, 0 },

  { 593, "Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 5, 0 },

  { 594, "Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 5, 0 },

  { 595, "Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 5, 0 },

  { 596, "Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 5, 0 },

  { 597, "Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 5, 0 },

  { 598, "Recentering Subsystem/No Movement/Compare To Constant2/Constant",
    "Value", 0, 5, 0 },

  { 599, "Recentering Subsystem/No Movement/Compare To Constant3/Constant",
    "Value", 0, 5, 0 },

  { 600, "Recentering Subsystem/Timer/Detect Fall Nonpositive/Delay Input1",
    "X0", 2, 5, 0 },

  { 601,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant",
    "Value", 0, 5, 0 },

  { 602,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant1",
    "Value", 0, 5, 0 },

  { 603,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "Gain", 0, 5, 0 },

  { 604,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P1", 0, 9, 0 },

  { 605,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P2", 0, 9, 0 },

  { 606,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P3", 0, 9, 0 },

  { 607,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P4", 0, 5, 0 },

  { 608,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P5", 0, 5, 0 },

  { 609,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P6", 0, 5, 0 },

  { 610,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P7", 0, 5, 0 },

  { 611,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 5, 0 },

  { 612,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 5, 0 },

  { 613,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Constant",
    "Value", 0, 5, 0 },

  { 614,
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
  &bump_choice_B.MatrixConcatenation1[0],/* 0: Signal */
  &bump_choice_B.Reshape[0],           /* 1: Signal */
  &bump_choice_B.BCStimTable[0],       /* 2: Signal */
  &bump_choice_B.BehaviorBC_o1[0],     /* 3: Signal */
  &bump_choice_B.BehaviorBC_o2[0],     /* 4: Signal */
  &bump_choice_B.BehaviorBC_o3,        /* 5: Signal */
  &bump_choice_B.BehaviorBC_o4[0],     /* 6: Signal */
  &bump_choice_B.BehaviorBC_o5,        /* 7: Signal */
  &bump_choice_B.BehaviorBC_o6[0],     /* 8: Signal */
  &bump_choice_B.BehaviorBC_o7[0],     /* 9: Signal */
  &bump_choice_B.BehaviorBC_o8[0],     /* 10: Signal */
  &bump_choice_B.LogicalOperator_a,    /* 11: Signal */
  &bump_choice_B.RelationalOperator_g, /* 12: Signal */
  &bump_choice_B.RelationalOperator1,  /* 13: Signal */
  &bump_choice_B.RelationalOperator2,  /* 14: Signal */
  &bump_choice_B.RelationalOperator3,  /* 15: Signal */
  &bump_choice_B.Gain_a,               /* 16: Signal */
  &bump_choice_B.LorentzForceGain_p[0],/* 17: Signal */
  &bump_choice_B.DynamicAngleSwitch,   /* 18: Signal */
  &bump_choice_B.LoadSelectSwitch[0],  /* 19: Signal */
  &bump_choice_B.Gain_n,               /* 20: Signal */
  &bump_choice_B.LorentzForceGain[0],  /* 21: Signal */
  &bump_choice_B.MultiportSwitch[0],   /* 22: Signal */
  &bump_choice_B.dynamicAngleSwitch,   /* 23: Signal */
  &bump_choice_B.MatrixConcatenation[0],/* 24: Signal */
  &bump_choice_B.MG1,                  /* 25: Signal */
  &bump_choice_B.MG2,                  /* 26: Signal */
  &bump_choice_B.LogicalOperator1_it,  /* 27: Signal */
  &bump_choice_B.Memory_k,             /* 28: Signal */
  &bump_choice_B.Switch1[0],           /* 29: Signal */
  &bump_choice_B.Switch2[0],           /* 30: Signal */
  &bump_choice_B.DataTypeConversion1,  /* 31: Signal */
  &bump_choice_B.DataTypeConversion2,  /* 32: Signal */
  &bump_choice_B.BoundingBoxViscosity[0],/* 33: Signal */
  &bump_choice_B.InBox,                /* 34: Signal */
  &bump_choice_B.LogicalOperator_j,    /* 35: Signal */
  &bump_choice_B.LogicalOperator1_g,   /* 36: Signal */
  &bump_choice_B.LogicalOperator3_d,   /* 37: Signal */
  &bump_choice_B.LogicalOperator5_k,   /* 38: Signal */
  &bump_choice_B.LogicalOperator6,     /* 39: Signal */
  &bump_choice_B.NOT,                  /* 40: Signal */
  &bump_choice_B.Switch_j[0],          /* 41: Signal */
  &bump_choice_B.DataTypeConversion,   /* 42: Signal */
  &bump_choice_B.RelationalOperator_ka,/* 43: Signal */
  &bump_choice_B.Switch_o,             /* 44: Signal */
  &bump_choice_B.UniformRandomNumber,  /* 45: Signal */
  &bump_choice_B.RateTransition[0],    /* 46: Signal */
  &bump_choice_B.Pack[0],              /* 47: Signal */
  &bump_choice_B.TachGain1,            /* 48: Signal */
  &bump_choice_B.TachGain2,            /* 49: Signal */
  &bump_choice_B.MatrixMultiply[0],    /* 50: Signal */
  &bump_choice_B.PCI6025EAD_o1,        /* 51: Signal */
  &bump_choice_B.PCI6025EAD_o2,        /* 52: Signal */
  &bump_choice_B.Switch[0],            /* 53: Signal */
  &bump_choice_B.Gain,                 /* 54: Signal */
  &bump_choice_B.Gain1,                /* 55: Signal */
  &bump_choice_B.PCIQUAD04,            /* 56: Signal */
  &bump_choice_B.PCIQUAD041,           /* 57: Signal */
  &bump_choice_B.Sum1,                 /* 58: Signal */
  &bump_choice_B.Sum3,                 /* 59: Signal */
  &bump_choice_B.Add_k,                /* 60: Signal */
  &bump_choice_B.Add1_k,               /* 61: Signal */
  &bump_choice_B.Gain_f[0],            /* 62: Signal */
  &bump_choice_B.Inverter_k[0],        /* 63: Signal */
  &bump_choice_B.Product_i,            /* 64: Signal */
  &bump_choice_B.Product1_p,           /* 65: Signal */
  &bump_choice_B.Product2_g,           /* 66: Signal */
  &bump_choice_B.Product3_h,           /* 67: Signal */
  &bump_choice_B.Add_ht,               /* 68: Signal */
  &bump_choice_B.Subtract_e,           /* 69: Signal */
  &bump_choice_B.cos_m,                /* 70: Signal */
  &bump_choice_B.sin_i,                /* 71: Signal */
  &bump_choice_B.Add,                  /* 72: Signal */
  &bump_choice_B.Add1_f,               /* 73: Signal */
  &bump_choice_B.Gain_d[0],            /* 74: Signal */
  &bump_choice_B.Inverter[0],          /* 75: Signal */
  &bump_choice_B.Product_a,            /* 76: Signal */
  &bump_choice_B.Product1_l,           /* 77: Signal */
  &bump_choice_B.Product2_l,           /* 78: Signal */
  &bump_choice_B.Product3_k,           /* 79: Signal */
  &bump_choice_B.Add_h,                /* 80: Signal */
  &bump_choice_B.Subtract_b,           /* 81: Signal */
  &bump_choice_B.cos_c,                /* 82: Signal */
  &bump_choice_B.sin_h,                /* 83: Signal */
  &bump_choice_B.Compare_p,            /* 84: Signal */
  &bump_choice_B.Compare_hq,           /* 85: Signal */
  &bump_choice_B.Gain_i[0],            /* 86: Signal */
  &bump_choice_B.MatrixMultiply_c[0],  /* 87: Signal */
  &bump_choice_B.Clock,                /* 88: Signal */
  &bump_choice_B.LogicalOperator,      /* 89: Signal */
  &bump_choice_B.LogicalOperator1,     /* 90: Signal */
  &bump_choice_B.LogicalOperator2,     /* 91: Signal */
  &bump_choice_B.Memory,               /* 92: Signal */
  &bump_choice_B.RelationalOperator,   /* 93: Signal */
  &bump_choice_B.Sum,                  /* 94: Signal */
  &bump_choice_B.Compare_a,            /* 95: Signal */
  &bump_choice_B.Compare_e,            /* 96: Signal */
  &bump_choice_B.FixPtRelationalOperator_o,/* 97: Signal */
  &bump_choice_B.Uk1_m,                /* 98: Signal */
  &bump_choice_B.FixPtRelationalOperator_j,/* 99: Signal */
  &bump_choice_B.Uk1_j,                /* 100: Signal */
  &bump_choice_B.Abs2,                 /* 101: Signal */
  &bump_choice_B.Abs3,                 /* 102: Signal */
  &bump_choice_B.LogicalOperator1_e,   /* 103: Signal */
  &bump_choice_B.Gain1_n,              /* 104: Signal */
  &bump_choice_B.Gain2,                /* 105: Signal */
  &bump_choice_B.Gain3,                /* 106: Signal */
  &bump_choice_B.Gain4,                /* 107: Signal */
  &bump_choice_B.Product_g,            /* 108: Signal */
  &bump_choice_B.Product1_o,           /* 109: Signal */
  &bump_choice_B.Saturation,           /* 110: Signal */
  &bump_choice_B.Saturation1,          /* 111: Signal */
  &bump_choice_B.Add_i,                /* 112: Signal */
  &bump_choice_B.Add1_ef,              /* 113: Signal */
  &bump_choice_B.Logic[0],             /* 114: Signal */
  &bump_choice_B.Memory_j,             /* 115: Signal */
  &bump_choice_B.Clock_k,              /* 116: Signal */
  &bump_choice_B.LogicalOperator_e,    /* 117: Signal */
  &bump_choice_B.LogicalOperator1_c,   /* 118: Signal */
  &bump_choice_B.LogicalOperator2_a,   /* 119: Signal */
  &bump_choice_B.Memory_b,             /* 120: Signal */
  &bump_choice_B.RelationalOperator_l, /* 121: Signal */
  &bump_choice_B.Sum_l,                /* 122: Signal */
  &bump_choice_B.Clock_d,              /* 123: Signal */
  &bump_choice_B.LogicalOperator_nd,   /* 124: Signal */
  &bump_choice_B.LogicalOperator1_l,   /* 125: Signal */
  &bump_choice_B.LogicalOperator2_i,   /* 126: Signal */
  &bump_choice_B.Memory_m,             /* 127: Signal */
  &bump_choice_B.RelationalOperator_k, /* 128: Signal */
  &bump_choice_B.Sum_hb,               /* 129: Signal */
  &bump_choice_B.Clock_p,              /* 130: Signal */
  &bump_choice_B.LogicalOperator_c,    /* 131: Signal */
  &bump_choice_B.LogicalOperator1_i,   /* 132: Signal */
  &bump_choice_B.LogicalOperator2_a2,  /* 133: Signal */
  &bump_choice_B.Memory_n,             /* 134: Signal */
  &bump_choice_B.RelationalOperator_p, /* 135: Signal */
  &bump_choice_B.Sum_h,                /* 136: Signal */
  &bump_choice_B.FixPtRelationalOperator_p,/* 137: Signal */
  &bump_choice_B.Uk1_c,                /* 138: Signal */
  &bump_choice_B.Clock_h,              /* 139: Signal */
  &bump_choice_B.LogicalOperator_n,    /* 140: Signal */
  &bump_choice_B.LogicalOperator1_f,   /* 141: Signal */
  &bump_choice_B.LogicalOperator2_m,   /* 142: Signal */
  &bump_choice_B.LogicalOperator3,     /* 143: Signal */
  &bump_choice_B.LogicalOperator4,     /* 144: Signal */
  &bump_choice_B.LogicalOperator5,     /* 145: Signal */
  &bump_choice_B.Memory_b5,            /* 146: Signal */
  &bump_choice_B.RelationalOperator_i, /* 147: Signal */
  &bump_choice_B.Sum_n,                /* 148: Signal */
  &bump_choice_B.SampleandHold_h.In,   /* 149: Signal */
  &bump_choice_B.Clock_o,              /* 150: Signal */
  &bump_choice_B.RelationalOperator_b, /* 151: Signal */
  &bump_choice_B.Sum_p,                /* 152: Signal */
  &bump_choice_B.Derivative,           /* 153: Signal */
  &bump_choice_B.dG,                   /* 154: Signal */
  &bump_choice_B.DigitalFilter,        /* 155: Signal */
  &bump_choice_B.DigitalFilter2,       /* 156: Signal */
  &bump_choice_B.Derivative_i,         /* 157: Signal */
  &bump_choice_B.dG_c,                 /* 158: Signal */
  &bump_choice_B.DigitalFilter_k,      /* 159: Signal */
  &bump_choice_B.DigitalFilter2_c,     /* 160: Signal */
  &bump_choice_B.sqrtu1u1u2u2,         /* 161: Signal */
  &bump_choice_B.Product_f,            /* 162: Signal */
  &bump_choice_B.Product1_b,           /* 163: Signal */
  &bump_choice_B.Sum_c,                /* 164: Signal */
  &bump_choice_B.TrigonometricFunction_d,/* 165: Signal */
  &bump_choice_B.TrigonometricFunction1_o,/* 166: Signal */
  &bump_choice_B.TrigonometricFunction2_l,/* 167: Signal */
  &bump_choice_B.ForIterator,          /* 168: Signal */
  &bump_choice_B.SerialConverter,      /* 169: Signal */
  &bump_choice_B.ToBits_o1,            /* 170: Signal */
  &bump_choice_B.ToBits_o2,            /* 171: Signal */
  &bump_choice_B.ToBits_o3,            /* 172: Signal */
  &bump_choice_B.ToBits_o4,            /* 173: Signal */
  &bump_choice_B.ToBits_o5,            /* 174: Signal */
  &bump_choice_B.ToBits_o6,            /* 175: Signal */
  &bump_choice_B.ToBits_o7,            /* 176: Signal */
  &bump_choice_B.ToBits_o8,            /* 177: Signal */
  &bump_choice_B.ToBits1_o1,           /* 178: Signal */
  &bump_choice_B.ToBits1_o2,           /* 179: Signal */
  &bump_choice_B.ToBits1_o3,           /* 180: Signal */
  &bump_choice_B.ToBits1_o4,           /* 181: Signal */
  &bump_choice_B.ToBits1_o5,           /* 182: Signal */
  &bump_choice_B.ToBits1_o6,           /* 183: Signal */
  &bump_choice_B.ToBits1_o7,           /* 184: Signal */
  &bump_choice_B.ToBits1_o8,           /* 185: Signal */
  &bump_choice_B.xPCTargetTime,        /* 186: Signal */
  &bump_choice_B.Add_ks,               /* 187: Signal */
  &bump_choice_B.Add1_md,              /* 188: Signal */
  &bump_choice_B.Switch_b,             /* 189: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 190: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 191: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 192: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 193: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 194: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 195: Signal */
  &bump_choice_B.Product,              /* 196: Signal */
  &bump_choice_B.Product1,             /* 197: Signal */
  &bump_choice_B.Product2,             /* 198: Signal */
  &bump_choice_B.Product3,             /* 199: Signal */
  &bump_choice_B.Sum1_k,               /* 200: Signal */
  &bump_choice_B.Sum2,                 /* 201: Signal */
  &bump_choice_B.Sum3_o,               /* 202: Signal */
  &bump_choice_B.Sum4,                 /* 203: Signal */
  &bump_choice_B.TrigonometricFunction,/* 204: Signal */
  &bump_choice_B.TrigonometricFunction1,/* 205: Signal */
  &bump_choice_B.TrigonometricFunction2,/* 206: Signal */
  &bump_choice_B.TrigonometricFunction3,/* 207: Signal */
  &bump_choice_B.dX,                   /* 208: Signal */
  &bump_choice_B.dY,                   /* 209: Signal */
  &bump_choice_B.dZ,                   /* 210: Signal */
  &bump_choice_B.product1,             /* 211: Signal */
  &bump_choice_B.product2,             /* 212: Signal */
  &bump_choice_B.product3,             /* 213: Signal */
  &bump_choice_B.product4,             /* 214: Signal */
  &bump_choice_B.Add1,                 /* 215: Signal */
  &bump_choice_B.Add2,                 /* 216: Signal */
  &bump_choice_B.Add3,                 /* 217: Signal */
  &bump_choice_B.Add4,                 /* 218: Signal */
  &bump_choice_B.AddX,                 /* 219: Signal */
  &bump_choice_B.AddX1,                /* 220: Signal */
  &bump_choice_B.AddX2,                /* 221: Signal */
  &bump_choice_B.x_b,                  /* 222: Signal */
  &bump_choice_B.y,                    /* 223: Signal */
  &bump_choice_B.z,                    /* 224: Signal */
  &bump_choice_B.dX_c,                 /* 225: Signal */
  &bump_choice_B.dY_d,                 /* 226: Signal */
  &bump_choice_B.dZ_f,                 /* 227: Signal */
  &bump_choice_B.product1_b,           /* 228: Signal */
  &bump_choice_B.product2_a,           /* 229: Signal */
  &bump_choice_B.product3_h,           /* 230: Signal */
  &bump_choice_B.product4_e,           /* 231: Signal */
  &bump_choice_B.Add1_l,               /* 232: Signal */
  &bump_choice_B.Add2_p,               /* 233: Signal */
  &bump_choice_B.Add3_j,               /* 234: Signal */
  &bump_choice_B.Add4_c,               /* 235: Signal */
  &bump_choice_B.AddX_h,               /* 236: Signal */
  &bump_choice_B.AddX1_b,              /* 237: Signal */
  &bump_choice_B.AddX2_d,              /* 238: Signal */
  &bump_choice_B.x_c,                  /* 239: Signal */
  &bump_choice_B.y_d,                  /* 240: Signal */
  &bump_choice_B.z_i,                  /* 241: Signal */
  &bump_choice_B.dX_k,                 /* 242: Signal */
  &bump_choice_B.dY_l,                 /* 243: Signal */
  &bump_choice_B.dZ_o,                 /* 244: Signal */
  &bump_choice_B.product1_g,           /* 245: Signal */
  &bump_choice_B.product2_c,           /* 246: Signal */
  &bump_choice_B.product3_p,           /* 247: Signal */
  &bump_choice_B.product4_g,           /* 248: Signal */
  &bump_choice_B.Add1_g,               /* 249: Signal */
  &bump_choice_B.Add2_f,               /* 250: Signal */
  &bump_choice_B.Add3_o,               /* 251: Signal */
  &bump_choice_B.Add4_g,               /* 252: Signal */
  &bump_choice_B.AddX_n,               /* 253: Signal */
  &bump_choice_B.AddX1_a,              /* 254: Signal */
  &bump_choice_B.AddX2_e,              /* 255: Signal */
  &bump_choice_B.x_j,                  /* 256: Signal */
  &bump_choice_B.y_a,                  /* 257: Signal */
  &bump_choice_B.z_g,                  /* 258: Signal */
  &bump_choice_B.dX_m,                 /* 259: Signal */
  &bump_choice_B.dY_b,                 /* 260: Signal */
  &bump_choice_B.dZ_m,                 /* 261: Signal */
  &bump_choice_B.product1_l,           /* 262: Signal */
  &bump_choice_B.product2_l,           /* 263: Signal */
  &bump_choice_B.product3_d,           /* 264: Signal */
  &bump_choice_B.product4_f,           /* 265: Signal */
  &bump_choice_B.Add1_e,               /* 266: Signal */
  &bump_choice_B.Add2_o,               /* 267: Signal */
  &bump_choice_B.Add3_m,               /* 268: Signal */
  &bump_choice_B.Add4_j,               /* 269: Signal */
  &bump_choice_B.AddX_j,               /* 270: Signal */
  &bump_choice_B.AddX1_d,              /* 271: Signal */
  &bump_choice_B.AddX2_eh,             /* 272: Signal */
  &bump_choice_B.x_h,                  /* 273: Signal */
  &bump_choice_B.y_k,                  /* 274: Signal */
  &bump_choice_B.z_j,                  /* 275: Signal */
  &bump_choice_B.dX_b,                 /* 276: Signal */
  &bump_choice_B.dY_l3,                /* 277: Signal */
  &bump_choice_B.dZ_l,                 /* 278: Signal */
  &bump_choice_B.product1_a,           /* 279: Signal */
  &bump_choice_B.product2_j,           /* 280: Signal */
  &bump_choice_B.product3_j,           /* 281: Signal */
  &bump_choice_B.product4_p,           /* 282: Signal */
  &bump_choice_B.Add1_gp,              /* 283: Signal */
  &bump_choice_B.Add2_k,               /* 284: Signal */
  &bump_choice_B.Add3_g,               /* 285: Signal */
  &bump_choice_B.Add4_o,               /* 286: Signal */
  &bump_choice_B.AddX_m,               /* 287: Signal */
  &bump_choice_B.AddX1_l,              /* 288: Signal */
  &bump_choice_B.AddX2_l,              /* 289: Signal */
  &bump_choice_B.x,                    /* 290: Signal */
  &bump_choice_B.y_p,                  /* 291: Signal */
  &bump_choice_B.z_o,                  /* 292: Signal */
  &bump_choice_B.dX_h,                 /* 293: Signal */
  &bump_choice_B.dY_d5,                /* 294: Signal */
  &bump_choice_B.dZ_c,                 /* 295: Signal */
  &bump_choice_B.product1_e,           /* 296: Signal */
  &bump_choice_B.product2_n,           /* 297: Signal */
  &bump_choice_B.product3_ho,          /* 298: Signal */
  &bump_choice_B.product4_p1,          /* 299: Signal */
  &bump_choice_B.Add1_h,               /* 300: Signal */
  &bump_choice_B.Add2_c,               /* 301: Signal */
  &bump_choice_B.Add3_f,               /* 302: Signal */
  &bump_choice_B.Add4_e,               /* 303: Signal */
  &bump_choice_B.AddX_i,               /* 304: Signal */
  &bump_choice_B.AddX1_bb,             /* 305: Signal */
  &bump_choice_B.AddX2_ec,             /* 306: Signal */
  &bump_choice_B.x_e,                  /* 307: Signal */
  &bump_choice_B.y_am,                 /* 308: Signal */
  &bump_choice_B.z_e,                  /* 309: Signal */
  &bump_choice_B.dX_l,                 /* 310: Signal */
  &bump_choice_B.dY_n,                 /* 311: Signal */
  &bump_choice_B.dZ_p,                 /* 312: Signal */
  &bump_choice_B.product1_f,           /* 313: Signal */
  &bump_choice_B.product2_f,           /* 314: Signal */
  &bump_choice_B.product3_f,           /* 315: Signal */
  &bump_choice_B.product4_et,          /* 316: Signal */
  &bump_choice_B.Add1_lc,              /* 317: Signal */
  &bump_choice_B.Add2_c5,              /* 318: Signal */
  &bump_choice_B.Add3_p,               /* 319: Signal */
  &bump_choice_B.Add4_ep,              /* 320: Signal */
  &bump_choice_B.AddX_l,               /* 321: Signal */
  &bump_choice_B.AddX1_dm,             /* 322: Signal */
  &bump_choice_B.AddX2_j,              /* 323: Signal */
  &bump_choice_B.x_et,                 /* 324: Signal */
  &bump_choice_B.y_kr,                 /* 325: Signal */
  &bump_choice_B.z_n,                  /* 326: Signal */
  &bump_choice_B.dX_h4,                /* 327: Signal */
  &bump_choice_B.dY_be,                /* 328: Signal */
  &bump_choice_B.dZ_ft,                /* 329: Signal */
  &bump_choice_B.product1_p,           /* 330: Signal */
  &bump_choice_B.product2_b,           /* 331: Signal */
  &bump_choice_B.product3_c,           /* 332: Signal */
  &bump_choice_B.product4_eg,          /* 333: Signal */
  &bump_choice_B.Add1_m,               /* 334: Signal */
  &bump_choice_B.Add2_k3,              /* 335: Signal */
  &bump_choice_B.Add3_k,               /* 336: Signal */
  &bump_choice_B.Add4_l,               /* 337: Signal */
  &bump_choice_B.AddX_c,               /* 338: Signal */
  &bump_choice_B.AddX1_c,              /* 339: Signal */
  &bump_choice_B.AddX2_c,              /* 340: Signal */
  &bump_choice_B.x_d,                  /* 341: Signal */
  &bump_choice_B.y_f,                  /* 342: Signal */
  &bump_choice_B.z_n3,                 /* 343: Signal */
  &bump_choice_B.MathFunction[0],      /* 344: Signal */
  &bump_choice_B.Compare,              /* 345: Signal */
  &bump_choice_B.EnabledSubsystem.In1, /* 346: Signal */
  &bump_choice_B.Compare_dc,           /* 347: Signal */
  &bump_choice_B.Compare_ez,           /* 348: Signal */
  &bump_choice_B.Compare_d,            /* 349: Signal */
  &bump_choice_B.Compare_dw,           /* 350: Signal */
  &bump_choice_B.Compare_h,            /* 351: Signal */
  &bump_choice_B.EnabledSubsystem_p.In1,/* 352: Signal */
  &bump_choice_B.Compare_n,            /* 353: Signal */
  &bump_choice_B.EnabledSubsystem_o.In1,/* 354: Signal */
  &bump_choice_B.Compare_l,            /* 355: Signal */
  &bump_choice_B.EnabledSubsystem_e.In1,/* 356: Signal */
  &bump_choice_B.Compare_do,           /* 357: Signal */
  &bump_choice_B.Compare_o,            /* 358: Signal */
  &bump_choice_B.FixPtRelationalOperator,/* 359: Signal */
  &bump_choice_B.Uk1,                  /* 360: Signal */
  &bump_choice_B.EnabledSubsystem_l.In1,/* 361: Signal */
  &bump_choice_B.SampleandHold.In,     /* 362: Signal */
  &bump_choice_B.ScaleTouSec,          /* 363: Signal */
  &bump_choice_B.xPCTargetTime_b,      /* 364: Signal */
  &bump_choice_B.Subtract,             /* 365: Signal */
  &bump_choice_B.Switch_n,             /* 366: Signal */
  &bump_choice_B.Compare_k,            /* 367: Signal */
  &bump_choice_B.Compare_b,            /* 368: Signal */
  &bump_choice_B.Compare_c,            /* 369: Signal */
  &bump_choice_P.Constant_Value_d,     /* 370: Block Parameter */
  &bump_choice_P.BCStimTable_table[0], /* 371: Block Parameter */
  &bump_choice_P.BehaviorBC_P1,        /* 372: Block Parameter */
  &bump_choice_P.BehaviorBC_P2,        /* 373: Block Parameter */
  &bump_choice_P.BehaviorBC_P3,        /* 374: Block Parameter */
  &bump_choice_P.BehaviorBC_P4,        /* 375: Block Parameter */
  &bump_choice_P.BehaviorBC_P5,        /* 376: Block Parameter */
  &bump_choice_P.BehaviorBC_P6,        /* 377: Block Parameter */
  &bump_choice_P.BehaviorBC_P7,        /* 378: Block Parameter */
  &bump_choice_P.BehaviorBC_P8,        /* 379: Block Parameter */
  &bump_choice_P.BehaviorBC_P9,        /* 380: Block Parameter */
  &bump_choice_P.BehaviorBC_P10,       /* 381: Block Parameter */
  &bump_choice_P.BehaviorBC_P11,       /* 382: Block Parameter */
  &bump_choice_P.BehaviorBC_P12,       /* 383: Block Parameter */
  &bump_choice_P.BehaviorBC_P13,       /* 384: Block Parameter */
  &bump_choice_P.BehaviorBC_P14,       /* 385: Block Parameter */
  &bump_choice_P.BehaviorBC_P15,       /* 386: Block Parameter */
  &bump_choice_P.BehaviorBC_P16,       /* 387: Block Parameter */
  &bump_choice_P.BehaviorBC_P17,       /* 388: Block Parameter */
  &bump_choice_P.XHighLimit_Value,     /* 389: Block Parameter */
  &bump_choice_P.XLowLimit_Value,      /* 390: Block Parameter */
  &bump_choice_P.YHighLimit_Value,     /* 391: Block Parameter */
  &bump_choice_P.YLowLimit_Value,      /* 392: Block Parameter */
  &bump_choice_P.DynamicAngle_Value,   /* 393: Block Parameter */
  &bump_choice_P.Load_Value_d,         /* 394: Block Parameter */
  &bump_choice_P.Off_Value,            /* 395: Block Parameter */
  &bump_choice_P.staticX_Value,        /* 396: Block Parameter */
  &bump_choice_P.staticY_Value,        /* 397: Block Parameter */
  &bump_choice_P.visAngle_Value,       /* 398: Block Parameter */
  &bump_choice_P.Gain_Gain_m,          /* 399: Block Parameter */
  &bump_choice_P.LorentzForceGain_Gain,/* 400: Block Parameter */
  &bump_choice_P.DynamicAngle_Value_f, /* 401: Block Parameter */
  &bump_choice_P.Load_Value,           /* 402: Block Parameter */
  &bump_choice_P.Off_Value_f,          /* 403: Block Parameter */
  &bump_choice_P.staticX_Value_h,      /* 404: Block Parameter */
  &bump_choice_P.staticY_Value_b,      /* 405: Block Parameter */
  &bump_choice_P.visAngle_Value_n,     /* 406: Block Parameter */
  &bump_choice_P.Gain_Gain_b,          /* 407: Block Parameter */
  &bump_choice_P.LorentzForceGain_Gain_c,/* 408: Block Parameter */
  &bump_choice_P.zeroX_Value,          /* 409: Block Parameter */
  &bump_choice_P.zeroY_Value,          /* 410: Block Parameter */
  &bump_choice_P.MG1_Gain,             /* 411: Block Parameter */
  &bump_choice_P.MG2_Gain,             /* 412: Block Parameter */
  &bump_choice_P.Memory_X0_l,          /* 413: Block Parameter */
  &bump_choice_P.PCI6025E_P1[0],       /* 414: Block Parameter */
  &bump_choice_P.PCI6025E_P2[0],       /* 415: Block Parameter */
  &bump_choice_P.PCI6025E_P3[0],       /* 416: Block Parameter */
  &bump_choice_P.PCI6025E_P4[0],       /* 417: Block Parameter */
  &bump_choice_P.PCI6025E_P5,          /* 418: Block Parameter */
  &bump_choice_P.PCI6025E_P6,          /* 419: Block Parameter */
  &bump_choice_P.PCI6025E_P7,          /* 420: Block Parameter */
  &bump_choice_P.RecenterFlag_Value,   /* 421: Block Parameter */
  &bump_choice_P.BoundingBoxViscosity_Gain,/* 422: Block Parameter */
  &bump_choice_P.JackpotChance_Value,  /* 423: Block Parameter */
  &bump_choice_P.RewardJackpot_Value,  /* 424: Block Parameter */
  &bump_choice_P.RewardTime_Value,     /* 425: Block Parameter */
  &bump_choice_P.UniformRandomNumber_Min,/* 426: Block Parameter */
  &bump_choice_P.UniformRandomNumber_Max,/* 427: Block Parameter */
  &bump_choice_P.UniformRandomNumber_Seed,/* 428: Block Parameter */
  &bump_choice_P.NaNupperbytes_Value,  /* 429: Block Parameter */
  &bump_choice_P.PacketSpec_Value,     /* 430: Block Parameter */
  &bump_choice_P.Send_P1[0],           /* 431: Block Parameter */
  &bump_choice_P.Send_P2,              /* 432: Block Parameter */
  &bump_choice_P.Send_P3,              /* 433: Block Parameter */
  &bump_choice_P.Send_P4,              /* 434: Block Parameter */
  &bump_choice_P.UseTachs_Value,       /* 435: Block Parameter */
  &bump_choice_P.TachGain1_Gain,       /* 436: Block Parameter */
  &bump_choice_P.TachGain2_Gain,       /* 437: Block Parameter */
  &bump_choice_P.PCI6025EAD_P1[0],     /* 438: Block Parameter */
  &bump_choice_P.PCI6025EAD_P2[0],     /* 439: Block Parameter */
  &bump_choice_P.PCI6025EAD_P3[0],     /* 440: Block Parameter */
  &bump_choice_P.PCI6025EAD_P4,        /* 441: Block Parameter */
  &bump_choice_P.PCI6025EAD_P5,        /* 442: Block Parameter */
  &bump_choice_P.PCI6025EAD_P6,        /* 443: Block Parameter */
  &bump_choice_P.Switch_Threshold,     /* 444: Block Parameter */
  &bump_choice_P.elbowOffset_Value,    /* 445: Block Parameter */
  &bump_choice_P.shoulderOffset_Value, /* 446: Block Parameter */
  &bump_choice_P.Gain_Gain,            /* 447: Block Parameter */
  &bump_choice_P.Gain1_Gain,           /* 448: Block Parameter */
  &bump_choice_P.PCIQUAD04_P1,         /* 449: Block Parameter */
  &bump_choice_P.PCIQUAD04_P2,         /* 450: Block Parameter */
  &bump_choice_P.PCIQUAD04_P3,         /* 451: Block Parameter */
  &bump_choice_P.PCIQUAD04_P4,         /* 452: Block Parameter */
  &bump_choice_P.PCIQUAD04_P5,         /* 453: Block Parameter */
  &bump_choice_P.PCIQUAD04_P6,         /* 454: Block Parameter */
  &bump_choice_P.PCIQUAD04_P7,         /* 455: Block Parameter */
  &bump_choice_P.PCIQUAD04_P8,         /* 456: Block Parameter */
  &bump_choice_P.PCIQUAD04_P9,         /* 457: Block Parameter */
  &bump_choice_P.PCIQUAD04_P10,        /* 458: Block Parameter */
  &bump_choice_P.PCIQUAD04_P11,        /* 459: Block Parameter */
  &bump_choice_P.PCIQUAD041_P1,        /* 460: Block Parameter */
  &bump_choice_P.PCIQUAD041_P2,        /* 461: Block Parameter */
  &bump_choice_P.PCIQUAD041_P3,        /* 462: Block Parameter */
  &bump_choice_P.PCIQUAD041_P4,        /* 463: Block Parameter */
  &bump_choice_P.PCIQUAD041_P5,        /* 464: Block Parameter */
  &bump_choice_P.PCIQUAD041_P6,        /* 465: Block Parameter */
  &bump_choice_P.PCIQUAD041_P7,        /* 466: Block Parameter */
  &bump_choice_P.PCIQUAD041_P8,        /* 467: Block Parameter */
  &bump_choice_P.PCIQUAD041_P9,        /* 468: Block Parameter */
  &bump_choice_P.PCIQUAD041_P10,       /* 469: Block Parameter */
  &bump_choice_P.PCIQUAD041_P11,       /* 470: Block Parameter */
  &bump_choice_P.Gain_Gain_ap,         /* 471: Block Parameter */
  &bump_choice_P.Inverter_Gain,        /* 472: Block Parameter */
  &bump_choice_P.Gain_Gain_by,         /* 473: Block Parameter */
  &bump_choice_P.Inverter_Gain_j,      /* 474: Block Parameter */
  &bump_choice_P.Constant_Value_j,     /* 475: Block Parameter */
  &bump_choice_P.Constant_Value_g,     /* 476: Block Parameter */
  &bump_choice_P.Gain_Gain_j,          /* 477: Block Parameter */
  &bump_choice_P.Time_Value,           /* 478: Block Parameter */
  &bump_choice_P.Memory_X0,            /* 479: Block Parameter */
  &bump_choice_P.DelayInput1_X0_o,     /* 480: Block Parameter */
  &bump_choice_P.DelayInput1_X0_m,     /* 481: Block Parameter */
  &bump_choice_P.Gain1_Gain_j,         /* 482: Block Parameter */
  &bump_choice_P.Gain2_Gain_o,         /* 483: Block Parameter */
  &bump_choice_P.Gain3_Gain,           /* 484: Block Parameter */
  &bump_choice_P.Gain4_Gain,           /* 485: Block Parameter */
  &bump_choice_P.Saturation_UpperSat,  /* 486: Block Parameter */
  &bump_choice_P.Saturation_LowerSat,  /* 487: Block Parameter */
  &bump_choice_P.Saturation1_UpperSat, /* 488: Block Parameter */
  &bump_choice_P.Saturation1_LowerSat, /* 489: Block Parameter */
  &bump_choice_P.Logic_table[0],       /* 490: Block Parameter */
  &bump_choice_P.Memory_X0_c,          /* 491: Block Parameter */
  &bump_choice_P.Time_Value_c,         /* 492: Block Parameter */
  &bump_choice_P.Memory_X0_p,          /* 493: Block Parameter */
  &bump_choice_P.Time_Value_h,         /* 494: Block Parameter */
  &bump_choice_P.Memory_X0_e,          /* 495: Block Parameter */
  &bump_choice_P.Time_Value_o,         /* 496: Block Parameter */
  &bump_choice_P.Memory_X0_k,          /* 497: Block Parameter */
  &bump_choice_P.DelayInput1_X0_n,     /* 498: Block Parameter */
  &bump_choice_P.Time_Value_p,         /* 499: Block Parameter */
  &bump_choice_P.Memory_X0_d,          /* 500: Block Parameter */
  &bump_choice_P.dG_Gain,              /* 501: Block Parameter */
  &bump_choice_P.DigitalFilter_ICRTP,  /* 502: Block Parameter */
  &bump_choice_P.DigitalFilter_RTP1COEFF[0],/* 503: Block Parameter */
  &bump_choice_P.DigitalFilter2_ICRTP, /* 504: Block Parameter */
  &bump_choice_P.DigitalFilter2_RTP1COEFF[0],/* 505: Block Parameter */
  &bump_choice_P.dG_Gain_l,            /* 506: Block Parameter */
  &bump_choice_P.DigitalFilter_ICRTP_l,/* 507: Block Parameter */
  &bump_choice_P.DigitalFilter_RTP1COEFF_a[0],/* 508: Block Parameter */
  &bump_choice_P.DigitalFilter2_ICRTP_i,/* 509: Block Parameter */
  &bump_choice_P.DigitalFilter2_RTP1COEFF_g[0],/* 510: Block Parameter */
  &bump_choice_P.AngleOffset_Value,    /* 511: Block Parameter */
  &bump_choice_P.Constant_Value_m,     /* 512: Block Parameter */
  &bump_choice_P.Constant2_Value,      /* 513: Block Parameter */
  &bump_choice_P.PortA_P1[0],          /* 514: Block Parameter */
  &bump_choice_P.PortA_P2,             /* 515: Block Parameter */
  &bump_choice_P.PortA_P3[0],          /* 516: Block Parameter */
  &bump_choice_P.PortA_P4[0],          /* 517: Block Parameter */
  &bump_choice_P.PortA_P5,             /* 518: Block Parameter */
  &bump_choice_P.PortA_P6,             /* 519: Block Parameter */
  &bump_choice_P.PortA_P7,             /* 520: Block Parameter */
  &bump_choice_P.PortA_P8,             /* 521: Block Parameter */
  &bump_choice_P.PortA_P9,             /* 522: Block Parameter */
  &bump_choice_P.PortB_P1[0],          /* 523: Block Parameter */
  &bump_choice_P.PortB_P2,             /* 524: Block Parameter */
  &bump_choice_P.PortB_P3[0],          /* 525: Block Parameter */
  &bump_choice_P.PortB_P4[0],          /* 526: Block Parameter */
  &bump_choice_P.PortB_P5,             /* 527: Block Parameter */
  &bump_choice_P.PortB_P6,             /* 528: Block Parameter */
  &bump_choice_P.PortB_P7,             /* 529: Block Parameter */
  &bump_choice_P.PortB_P8,             /* 530: Block Parameter */
  &bump_choice_P.PortB_P9,             /* 531: Block Parameter */
  &bump_choice_P.xPCTargetTime_P1_h,   /* 532: Block Parameter */
  &bump_choice_P.xPCTargetTime_P2_g,   /* 533: Block Parameter */
  &bump_choice_P.Switch_Threshold_k,   /* 534: Block Parameter */
  &bump_choice_P.L1_Value,             /* 535: Block Parameter */
  &bump_choice_P.L2_Value,             /* 536: Block Parameter */
  &bump_choice_P.xoffset_Value,        /* 537: Block Parameter */
  &bump_choice_P.yoffset_Value,        /* 538: Block Parameter */
  &bump_choice_P.Gain_Gain_a,          /* 539: Block Parameter */
  &bump_choice_P.Gain1_Gain_m,         /* 540: Block Parameter */
  &bump_choice_P.Gain2_Gain,           /* 541: Block Parameter */
  &bump_choice_P.beta_Value,           /* 542: Block Parameter */
  &bump_choice_P.rho_Value,            /* 543: Block Parameter */
  &bump_choice_P.sigma_Value,          /* 544: Block Parameter */
  &bump_choice_P.timescale_Value,      /* 545: Block Parameter */
  &bump_choice_P.x_X0_i,               /* 546: Block Parameter */
  &bump_choice_P.y_X0,                 /* 547: Block Parameter */
  &bump_choice_P.z_X0,                 /* 548: Block Parameter */
  &bump_choice_P.beta_Value_a,         /* 549: Block Parameter */
  &bump_choice_P.rho_Value_e,          /* 550: Block Parameter */
  &bump_choice_P.sigma_Value_g,        /* 551: Block Parameter */
  &bump_choice_P.timescale_Value_m,    /* 552: Block Parameter */
  &bump_choice_P.x_X0_k,               /* 553: Block Parameter */
  &bump_choice_P.y_X0_l,               /* 554: Block Parameter */
  &bump_choice_P.z_X0_b,               /* 555: Block Parameter */
  &bump_choice_P.beta_Value_l,         /* 556: Block Parameter */
  &bump_choice_P.rho_Value_eb,         /* 557: Block Parameter */
  &bump_choice_P.sigma_Value_j,        /* 558: Block Parameter */
  &bump_choice_P.timescale_Value_l,    /* 559: Block Parameter */
  &bump_choice_P.x_X0_nd,              /* 560: Block Parameter */
  &bump_choice_P.y_X0_a,               /* 561: Block Parameter */
  &bump_choice_P.z_X0_bn,              /* 562: Block Parameter */
  &bump_choice_P.beta_Value_c,         /* 563: Block Parameter */
  &bump_choice_P.rho_Value_n,          /* 564: Block Parameter */
  &bump_choice_P.sigma_Value_jm,       /* 565: Block Parameter */
  &bump_choice_P.timescale_Value_f,    /* 566: Block Parameter */
  &bump_choice_P.x_X0_a,               /* 567: Block Parameter */
  &bump_choice_P.y_X0_k,               /* 568: Block Parameter */
  &bump_choice_P.z_X0_i,               /* 569: Block Parameter */
  &bump_choice_P.beta_Value_b,         /* 570: Block Parameter */
  &bump_choice_P.rho_Value_f,          /* 571: Block Parameter */
  &bump_choice_P.sigma_Value_m,        /* 572: Block Parameter */
  &bump_choice_P.timescale_Value_mg,   /* 573: Block Parameter */
  &bump_choice_P.x_X0,                 /* 574: Block Parameter */
  &bump_choice_P.y_X0_i,               /* 575: Block Parameter */
  &bump_choice_P.z_X0_n,               /* 576: Block Parameter */
  &bump_choice_P.beta_Value_m,         /* 577: Block Parameter */
  &bump_choice_P.rho_Value_b,          /* 578: Block Parameter */
  &bump_choice_P.sigma_Value_j0,       /* 579: Block Parameter */
  &bump_choice_P.timescale_Value_e,    /* 580: Block Parameter */
  &bump_choice_P.x_X0_p,               /* 581: Block Parameter */
  &bump_choice_P.y_X0_m,               /* 582: Block Parameter */
  &bump_choice_P.z_X0_a,               /* 583: Block Parameter */
  &bump_choice_P.beta_Value_n,         /* 584: Block Parameter */
  &bump_choice_P.rho_Value_h,          /* 585: Block Parameter */
  &bump_choice_P.sigma_Value_c,        /* 586: Block Parameter */
  &bump_choice_P.timescale_Value_d,    /* 587: Block Parameter */
  &bump_choice_P.x_X0_n,               /* 588: Block Parameter */
  &bump_choice_P.y_X0_p,               /* 589: Block Parameter */
  &bump_choice_P.z_X0_i4,              /* 590: Block Parameter */
  &bump_choice_P.beta_Value_g,         /* 591: Block Parameter */
  &bump_choice_P.rho_Value_a,          /* 592: Block Parameter */
  &bump_choice_P.sigma_Value_l,        /* 593: Block Parameter */
  &bump_choice_P.timescale_Value_j,    /* 594: Block Parameter */
  &bump_choice_P.x_X0_pt,              /* 595: Block Parameter */
  &bump_choice_P.y_X0_c,               /* 596: Block Parameter */
  &bump_choice_P.z_X0_f,               /* 597: Block Parameter */
  &bump_choice_P.Constant_Value,       /* 598: Block Parameter */
  &bump_choice_P.Constant_Value_o,     /* 599: Block Parameter */
  &bump_choice_P.DelayInput1_X0,       /* 600: Block Parameter */
  &bump_choice_P.Constant_Value_h,     /* 601: Block Parameter */
  &bump_choice_P.Constant1_Value,      /* 602: Block Parameter */
  &bump_choice_P.ScaleTouSec_Gain,     /* 603: Block Parameter */
  &bump_choice_P.PCI6025E_P1_d[0],     /* 604: Block Parameter */
  &bump_choice_P.PCI6025E_P2_k[0],     /* 605: Block Parameter */
  &bump_choice_P.PCI6025E_P3_l[0],     /* 606: Block Parameter */
  &bump_choice_P.PCI6025E_P4_o,        /* 607: Block Parameter */
  &bump_choice_P.PCI6025E_P5_m,        /* 608: Block Parameter */
  &bump_choice_P.PCI6025E_P6_f,        /* 609: Block Parameter */
  &bump_choice_P.PCI6025E_P7_f,        /* 610: Block Parameter */
  &bump_choice_P.xPCTargetTime_P1,     /* 611: Block Parameter */
  &bump_choice_P.xPCTargetTime_P2,     /* 612: Block Parameter */
  &bump_choice_P.Constant_Value_jz,    /* 613: Block Parameter */
  &bump_choice_P.Constant_Value_b      /* 614: Block Parameter */
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

  { rtBlockParameters, 245,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float", NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void bump_choice_InitializeDataMapInfo(rtModel_bump_choice *bump_choice_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(bump_choice_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(bump_choice_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(bump_choice_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(bump_choice_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(bump_choice_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(bump_choice_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(bump_choice_rtM->DataMapInfo.mmi, 0);
}

/* EOF: bump_choice_capi.c */
