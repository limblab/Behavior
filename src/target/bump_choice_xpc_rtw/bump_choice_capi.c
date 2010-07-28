/*
 * bump_choice_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "bump_choice.mdl".
 *
 * Model Version              : 1.1230
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:43:36 2010
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

  { 1, 0, "Behavior BC/p1",
    "", 0, 0, 1, 0, 0 },

  { 2, 0, "Behavior BC/p2",
    "", 1, 0, 2, 0, 0 },

  { 3, 0, "Behavior BC/p3",
    "", 2, 0, 3, 0, 0 },

  { 4, 0, "Behavior BC/p4",
    "", 3, 0, 4, 0, 0 },

  { 5, 0, "Behavior BC/p5",
    "", 4, 0, 3, 0, 0 },

  { 6, 0, "Behavior BC/p6",
    "", 5, 0, 1, 0, 0 },

  { 7, 0, "Behavior BC/p7",
    "", 6, 0, 0, 0, 0 },

  { 8, 0, "Behavior BC/p8",
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

  { 44, 0, "SendPacketToGraphics1/Rate Transition",
    "", 0, 2, 5, 0, 2 },

  { 45, 0, "SendPacketToGraphics1/Pack",
    "", 0, 2, 5, 0, 0 },

  { 46, 28, "Velocity Calculation/TachGain1",
    "", 0, 0, 3, 0, 0 },

  { 47, 28, "Velocity Calculation/TachGain2",
    "", 0, 0, 3, 0, 0 },

  { 48, 28, "Velocity Calculation/Matrix Multiply",
    "", 0, 0, 1, 0, 0 },

  { 49, 0, "Velocity Calculation/PCI-6025E AD/p1",
    "", 0, 0, 3, 0, 0 },

  { 50, 0, "Velocity Calculation/PCI-6025E AD/p2",
    "", 1, 0, 3, 0, 0 },

  { 51, 0, "Velocity Calculation/Switch",
    "", 0, 0, 1, 0, 0 },

  { 52, 0, "XY Position Subsystem/Gain",
    "", 0, 0, 3, 0, 0 },

  { 53, 0, "XY Position Subsystem/Gain1",
    "", 0, 0, 3, 0, 0 },

  { 54, 0, "XY Position Subsystem/PCI-QUAD04 ",
    "", 0, 0, 3, 0, 0 },

  { 55, 0, "XY Position Subsystem/PCI-QUAD04 1",
    "", 0, 0, 3, 0, 0 },

  { 56, 0, "XY Position Subsystem/Sum1",
    "", 0, 0, 3, 0, 0 },

  { 57, 0, "XY Position Subsystem/Sum3",
    "", 0, 0, 3, 0, 0 },

  { 58, 0, "Catch Force Generator/LorentzForce/Add",
    "", 0, 0, 3, 0, 0 },

  { 59, 4, "Catch Force Generator/LorentzForce/Add1",
    "", 0, 0, 3, 0, 0 },

  { 60, 3, "Catch Force Generator/ViscLoadSubsystem/Gain",
    "", 0, 0, 1, 0, 0 },

  { 61, 3, "Catch Force Generator/ViscLoadSubsystem/Inverter",
    "", 0, 0, 1, 0, 0 },

  { 62, 3, "Catch Force Generator/ViscLoadSubsystem/Product",
    "", 0, 0, 3, 0, 0 },

  { 63, 3, "Catch Force Generator/ViscLoadSubsystem/Product1",
    "", 0, 0, 3, 0, 0 },

  { 64, 3, "Catch Force Generator/ViscLoadSubsystem/Product2",
    "", 0, 0, 3, 0, 0 },

  { 65, 3, "Catch Force Generator/ViscLoadSubsystem/Product3",
    "", 0, 0, 3, 0, 0 },

  { 66, 3, "Catch Force Generator/ViscLoadSubsystem/Add",
    "", 0, 0, 3, 0, 0 },

  { 67, 3, "Catch Force Generator/ViscLoadSubsystem/Subtract",
    "", 0, 0, 3, 0, 0 },

  { 68, 3, "Catch Force Generator/ViscLoadSubsystem/cos",
    "", 0, 0, 3, 0, 0 },

  { 69, 3, "Catch Force Generator/ViscLoadSubsystem/sin",
    "", 0, 0, 3, 0, 0 },

  { 70, 0, "Force Generator/LorentzForce/Add",
    "", 0, 0, 3, 0, 0 },

  { 71, 10, "Force Generator/LorentzForce/Add1",
    "", 0, 0, 3, 0, 0 },

  { 72, 9, "Force Generator/ViscLoadSubsystem/Gain",
    "", 0, 0, 1, 0, 0 },

  { 73, 9, "Force Generator/ViscLoadSubsystem/Inverter",
    "", 0, 0, 1, 0, 0 },

  { 74, 9, "Force Generator/ViscLoadSubsystem/Product",
    "", 0, 0, 3, 0, 0 },

  { 75, 9, "Force Generator/ViscLoadSubsystem/Product1",
    "", 0, 0, 3, 0, 0 },

  { 76, 9, "Force Generator/ViscLoadSubsystem/Product2",
    "", 0, 0, 3, 0, 0 },

  { 77, 9, "Force Generator/ViscLoadSubsystem/Product3",
    "", 0, 0, 3, 0, 0 },

  { 78, 9, "Force Generator/ViscLoadSubsystem/Add",
    "", 0, 0, 3, 0, 0 },

  { 79, 9, "Force Generator/ViscLoadSubsystem/Subtract",
    "", 0, 0, 3, 0, 0 },

  { 80, 9, "Force Generator/ViscLoadSubsystem/cos",
    "", 0, 0, 3, 0, 0 },

  { 81, 9, "Force Generator/ViscLoadSubsystem/sin",
    "", 0, 0, 3, 0, 0 },

  { 82, 0, "Motor Control/Compare To Constant/Compare",
    "", 0, 2, 3, 0, 0 },

  { 83, 0, "Motor Control/Compare To Constant1/Compare",
    "", 0, 2, 3, 0, 0 },

  { 84, 18, "Motor Control/Force//Torque Transform/Gain",
    "", 0, 0, 1, 0, 0 },

  { 85, 18, "Motor Control/Force//Torque Transform/Matrix Multiply",
    "", 0, 0, 1, 0, 0 },

  { 86, 0, "Motor Control/Schmidt/Clock",
    "", 0, 0, 3, 0, 1 },

  { 87, 0, "Motor Control/Schmidt/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 88, 0, "Motor Control/Schmidt/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 89, 0, "Motor Control/Schmidt/Logical Operator2",
    "", 0, 1, 3, 0, 0 },

  { 90, 0, "Motor Control/Schmidt/Memory",
    "", 0, 1, 3, 0, 0 },

  { 91, 0, "Motor Control/Schmidt/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 92, 0, "Motor Control/Schmidt/Sum",
    "", 0, 0, 3, 0, 1 },

  { 93, 0, "Recentering Subsystem/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 0 },

  { 94, 0, "Recentering Subsystem/Compare To Zero1/Compare",
    "", 0, 2, 3, 0, 0 },

  { 95, 0, "Recentering Subsystem/Falling Edge/FixPt Relational Operator",
    "", 0, 2, 3, 0, 0 },

  { 96, 0, "Recentering Subsystem/Falling Edge/Delay Input1",
    "U(k-1)", 0, 2, 3, 0, 0 },

  { 97, 0, "Recentering Subsystem/Falling Edge1/FixPt Relational Operator",
    "", 0, 2, 3, 0, 0 },

  { 98, 0, "Recentering Subsystem/Falling Edge1/Delay Input1",
    "U(k-1)", 0, 2, 3, 0, 0 },

  { 99, 0, "Recentering Subsystem/No Movement/Abs2",
    "", 0, 0, 3, 0, 0 },

  { 100, 0, "Recentering Subsystem/No Movement/Abs3",
    "", 0, 0, 3, 0, 0 },

  { 101, 0, "Recentering Subsystem/No Movement/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 102, 13, "Recentering Subsystem/PD Controller/Gain1",
    "", 0, 0, 3, 0, 0 },

  { 103, 13, "Recentering Subsystem/PD Controller/Gain2",
    "", 0, 0, 3, 0, 0 },

  { 104, 13, "Recentering Subsystem/PD Controller/Gain3",
    "", 0, 0, 3, 0, 0 },

  { 105, 13, "Recentering Subsystem/PD Controller/Gain4",
    "", 0, 0, 3, 0, 0 },

  { 106, 13, "Recentering Subsystem/PD Controller/Product",
    "", 0, 0, 3, 0, 0 },

  { 107, 13, "Recentering Subsystem/PD Controller/Product1",
    "", 0, 0, 3, 0, 0 },

  { 108, 13, "Recentering Subsystem/PD Controller/Saturation",
    "", 0, 0, 3, 0, 0 },

  { 109, 13, "Recentering Subsystem/PD Controller/Saturation1",
    "", 0, 0, 3, 0, 0 },

  { 110, 13, "Recentering Subsystem/PD Controller/Add",
    "", 0, 0, 3, 0, 0 },

  { 111, 13, "Recentering Subsystem/PD Controller/Add1",
    "", 0, 0, 3, 0, 0 },

  { 112, 0, "Recentering Subsystem/S-R Flip-Flop/Logic",
    "", 0, 1, 1, 0, 0 },

  { 113, 0, "Recentering Subsystem/S-R Flip-Flop/Memory",
    "", 0, 1, 3, 0, 0 },

  { 114, 0, "Recentering Subsystem/Schmidt1/Clock",
    "", 0, 0, 3, 0, 1 },

  { 115, 0, "Recentering Subsystem/Schmidt1/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 116, 0, "Recentering Subsystem/Schmidt1/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 117, 0, "Recentering Subsystem/Schmidt1/Logical Operator2",
    "", 0, 1, 3, 0, 0 },

  { 118, 0, "Recentering Subsystem/Schmidt1/Memory",
    "", 0, 1, 3, 0, 0 },

  { 119, 0, "Recentering Subsystem/Schmidt1/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 120, 0, "Recentering Subsystem/Schmidt1/Sum",
    "", 0, 0, 3, 0, 1 },

  { 121, 0, "Recentering Subsystem/Schmidt2/Clock",
    "", 0, 0, 3, 0, 1 },

  { 122, 0, "Recentering Subsystem/Schmidt2/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 123, 0, "Recentering Subsystem/Schmidt2/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 124, 0, "Recentering Subsystem/Schmidt2/Logical Operator2",
    "", 0, 1, 3, 0, 0 },

  { 125, 0, "Recentering Subsystem/Schmidt2/Memory",
    "", 0, 1, 3, 0, 0 },

  { 126, 0, "Recentering Subsystem/Schmidt2/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 127, 0, "Recentering Subsystem/Schmidt2/Sum",
    "", 0, 0, 3, 0, 1 },

  { 128, 0, "Recentering Subsystem/Schmidt3/Clock",
    "", 0, 0, 3, 0, 1 },

  { 129, 0, "Recentering Subsystem/Schmidt3/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 130, 0, "Recentering Subsystem/Schmidt3/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 131, 0, "Recentering Subsystem/Schmidt3/Logical Operator2",
    "", 0, 1, 3, 0, 0 },

  { 132, 0, "Recentering Subsystem/Schmidt3/Memory",
    "", 0, 1, 3, 0, 0 },

  { 133, 0, "Recentering Subsystem/Schmidt3/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 134, 0, "Recentering Subsystem/Schmidt3/Sum",
    "", 0, 0, 3, 0, 1 },

  { 135, 0, "Recentering Subsystem/Start Moving/FixPt Relational Operator",
    "", 0, 2, 3, 0, 0 },

  { 136, 0, "Recentering Subsystem/Start Moving/Delay Input1",
    "U(k-1)", 0, 2, 3, 0, 0 },

  { 137, 0, "Recentering Subsystem/Timer/Clock",
    "", 0, 0, 3, 0, 1 },

  { 138, 0, "Recentering Subsystem/Timer/Logical Operator",
    "", 0, 1, 3, 0, 0 },

  { 139, 0, "Recentering Subsystem/Timer/Logical Operator1",
    "", 0, 1, 3, 0, 0 },

  { 140, 0, "Recentering Subsystem/Timer/Logical Operator2",
    "", 0, 1, 3, 0, 0 },

  { 141, 0, "Recentering Subsystem/Timer/Logical Operator3",
    "", 0, 1, 3, 0, 0 },

  { 142, 0, "Recentering Subsystem/Timer/Logical Operator4",
    "", 0, 1, 3, 0, 0 },

  { 143, 0, "Recentering Subsystem/Timer/Logical Operator5",
    "", 0, 1, 3, 0, 0 },

  { 144, 0, "Recentering Subsystem/Timer/Memory",
    "", 0, 1, 3, 0, 0 },

  { 145, 0, "Recentering Subsystem/Timer/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 146, 0, "Recentering Subsystem/Timer/Sum",
    "", 0, 0, 3, 0, 1 },

  { 147, 26, "RewardSbs/Sample and Hold/In",
    "", 0, 0, 3, 0, 3 },

  { 148, 0, "RewardSbs/Schmidt/Clock",
    "", 0, 0, 3, 0, 1 },

  { 149, 0, "RewardSbs/Schmidt/Relational Operator",
    "", 0, 1, 3, 0, 1 },

  { 150, 0, "RewardSbs/Schmidt/Sum",
    "", 0, 0, 3, 0, 1 },

  { 151, 0, "Velocity Calculation/Pos2VelX/Derivative",
    "", 0, 0, 3, 0, 1 },

  { 152, 0, "Velocity Calculation/Pos2VelX/dG",
    "", 0, 0, 3, 0, 0 },

  { 153, 0, "Velocity Calculation/Pos2VelX/Digital Filter",
    "", 0, 0, 3, 0, 0 },

  { 154, 0, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "", 0, 0, 3, 0, 0 },

  { 155, 0, "Velocity Calculation/Pos2VelY/Derivative",
    "", 0, 0, 3, 0, 1 },

  { 156, 0, "Velocity Calculation/Pos2VelY/dG",
    "", 0, 0, 3, 0, 0 },

  { 157, 0, "Velocity Calculation/Pos2VelY/Digital Filter",
    "", 0, 0, 3, 0, 0 },

  { 158, 0, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "", 0, 0, 3, 0, 0 },

  { 159, 0, "XY Position Subsystem/Cursor Rotation/sqrt(u[1]*u[1] + u[2]*u[2])",
    "", 0, 0, 3, 0, 0 },

  { 160, 0, "XY Position Subsystem/Cursor Rotation/Product",
    "", 0, 0, 3, 0, 0 },

  { 161, 0, "XY Position Subsystem/Cursor Rotation/Product1",
    "", 0, 0, 3, 0, 0 },

  { 162, 0, "XY Position Subsystem/Cursor Rotation/Sum",
    "", 0, 0, 3, 0, 0 },

  { 163, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function",
    "", 0, 0, 3, 0, 0 },

  { 164, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function1",
    "", 0, 0, 3, 0, 0 },

  { 165, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function2",
    "", 0, 0, 3, 0, 0 },

  { 166, 33, "XY Position Subsystem/For Iterator Subsystem/For Iterator",
    "", 0, 0, 3, 0, 3 },

  { 167, 33, "XY Position Subsystem/For Iterator Subsystem/SerialConverter",
    "", 0, 0, 3, 0, 3 },

  { 168, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p1",
    "", 0, 0, 3, 0, 3 },

  { 169, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p2",
    "", 1, 0, 3, 0, 3 },

  { 170, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p3",
    "", 2, 0, 3, 0, 3 },

  { 171, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p4",
    "", 3, 0, 3, 0, 3 },

  { 172, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p5",
    "", 4, 0, 3, 0, 3 },

  { 173, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p6",
    "", 5, 0, 3, 0, 3 },

  { 174, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p7",
    "", 6, 0, 3, 0, 3 },

  { 175, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits/p8",
    "", 7, 0, 3, 0, 3 },

  { 176, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p1",
    "", 0, 0, 3, 0, 3 },

  { 177, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p2",
    "", 1, 0, 3, 0, 3 },

  { 178, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p3",
    "", 2, 0, 3, 0, 3 },

  { 179, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p4",
    "", 3, 0, 3, 0, 3 },

  { 180, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p5",
    "", 4, 0, 3, 0, 3 },

  { 181, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p6",
    "", 5, 0, 3, 0, 3 },

  { 182, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p7",
    "", 6, 0, 3, 0, 3 },

  { 183, 33, "XY Position Subsystem/For Iterator Subsystem/ToBits1/p8",
    "", 7, 0, 3, 0, 3 },

  { 184, 33, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "", 0, 0, 3, 0, 3 },

  { 185, 33, "XY Position Subsystem/For Iterator Subsystem/Add",
    "", 0, 0, 3, 0, 3 },

  { 186, 33, "XY Position Subsystem/For Iterator Subsystem/Add1",
    "", 0, 0, 3, 0, 3 },

  { 187, 33, "XY Position Subsystem/For Iterator Subsystem/Switch",
    "", 0, 0, 3, 0, 3 },

  { 188, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate",
    "", 0, 0, 6, 0, 0 },

  { 189, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate1",
    "", 0, 0, 6, 0, 0 },

  { 190, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate2",
    "", 0, 0, 6, 0, 0 },

  { 191, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain",
    "", 0, 0, 6, 0, 0 },

  { 192, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain1",
    "", 0, 0, 6, 0, 0 },

  { 193, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain2",
    "", 0, 0, 6, 0, 0 },

  { 194, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product",
    "", 0, 0, 3, 0, 0 },

  { 195, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product1",
    "", 0, 0, 3, 0, 0 },

  { 196, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product2",
    "", 0, 0, 3, 0, 0 },

  { 197, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Product3",
    "", 0, 0, 3, 0, 0 },

  { 198, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum1",
    "", 0, 0, 3, 0, 0 },

  { 199, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum2",
    "", 0, 0, 3, 0, 0 },

  { 200, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum3",
    "", 0, 0, 3, 0, 0 },

  { 201, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum4",
    "", 0, 0, 3, 0, 0 },

  { 202, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function",
    "", 0, 0, 3, 0, 0 },

  { 203, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function1",
    "", 0, 0, 3, 0, 0 },

  { 204, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function2",
    "", 0, 0, 3, 0, 0 },

  { 205, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function3",
    "", 0, 0, 3, 0, 0 },

  { 206, 0, "Catch Force Generator/LorentzForce/Lorentz/dX",
    "", 0, 0, 3, 0, 0 },

  { 207, 0, "Catch Force Generator/LorentzForce/Lorentz/dY",
    "", 0, 0, 3, 0, 0 },

  { 208, 0, "Catch Force Generator/LorentzForce/Lorentz/dZ",
    "", 0, 0, 3, 0, 0 },

  { 209, 0, "Catch Force Generator/LorentzForce/Lorentz/product1",
    "", 0, 0, 3, 0, 0 },

  { 210, 0, "Catch Force Generator/LorentzForce/Lorentz/product2",
    "", 0, 0, 3, 0, 0 },

  { 211, 0, "Catch Force Generator/LorentzForce/Lorentz/product3",
    "", 0, 0, 3, 0, 0 },

  { 212, 0, "Catch Force Generator/LorentzForce/Lorentz/product4",
    "", 0, 0, 3, 0, 0 },

  { 213, 0, "Catch Force Generator/LorentzForce/Lorentz/Add1",
    "", 0, 0, 3, 0, 0 },

  { 214, 0, "Catch Force Generator/LorentzForce/Lorentz/Add2",
    "", 0, 0, 3, 0, 0 },

  { 215, 0, "Catch Force Generator/LorentzForce/Lorentz/Add3",
    "", 0, 0, 3, 0, 0 },

  { 216, 0, "Catch Force Generator/LorentzForce/Lorentz/Add4",
    "", 0, 0, 3, 0, 0 },

  { 217, 0, "Catch Force Generator/LorentzForce/Lorentz/AddX",
    "", 0, 0, 3, 0, 0 },

  { 218, 0, "Catch Force Generator/LorentzForce/Lorentz/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 219, 0, "Catch Force Generator/LorentzForce/Lorentz/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 220, 0, "Catch Force Generator/LorentzForce/Lorentz/x",
    "", 0, 0, 3, 0, 0 },

  { 221, 0, "Catch Force Generator/LorentzForce/Lorentz/y",
    "", 0, 0, 3, 0, 0 },

  { 222, 0, "Catch Force Generator/LorentzForce/Lorentz/z",
    "", 0, 0, 3, 0, 0 },

  { 223, 0, "Catch Force Generator/LorentzForce/Lorentz1/dX",
    "", 0, 0, 3, 0, 0 },

  { 224, 0, "Catch Force Generator/LorentzForce/Lorentz1/dY",
    "", 0, 0, 3, 0, 0 },

  { 225, 0, "Catch Force Generator/LorentzForce/Lorentz1/dZ",
    "", 0, 0, 3, 0, 0 },

  { 226, 0, "Catch Force Generator/LorentzForce/Lorentz1/product1",
    "", 0, 0, 3, 0, 0 },

  { 227, 0, "Catch Force Generator/LorentzForce/Lorentz1/product2",
    "", 0, 0, 3, 0, 0 },

  { 228, 0, "Catch Force Generator/LorentzForce/Lorentz1/product3",
    "", 0, 0, 3, 0, 0 },

  { 229, 0, "Catch Force Generator/LorentzForce/Lorentz1/product4",
    "", 0, 0, 3, 0, 0 },

  { 230, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add1",
    "", 0, 0, 3, 0, 0 },

  { 231, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add2",
    "", 0, 0, 3, 0, 0 },

  { 232, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add3",
    "", 0, 0, 3, 0, 0 },

  { 233, 0, "Catch Force Generator/LorentzForce/Lorentz1/Add4",
    "", 0, 0, 3, 0, 0 },

  { 234, 0, "Catch Force Generator/LorentzForce/Lorentz1/AddX",
    "", 0, 0, 3, 0, 0 },

  { 235, 0, "Catch Force Generator/LorentzForce/Lorentz1/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 236, 0, "Catch Force Generator/LorentzForce/Lorentz1/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 237, 0, "Catch Force Generator/LorentzForce/Lorentz1/x",
    "", 0, 0, 3, 0, 0 },

  { 238, 0, "Catch Force Generator/LorentzForce/Lorentz1/y",
    "", 0, 0, 3, 0, 0 },

  { 239, 0, "Catch Force Generator/LorentzForce/Lorentz1/z",
    "", 0, 0, 3, 0, 0 },

  { 240, 0, "Catch Force Generator/LorentzForce/Lorentz2/dX",
    "", 0, 0, 3, 0, 0 },

  { 241, 0, "Catch Force Generator/LorentzForce/Lorentz2/dY",
    "", 0, 0, 3, 0, 0 },

  { 242, 0, "Catch Force Generator/LorentzForce/Lorentz2/dZ",
    "", 0, 0, 3, 0, 0 },

  { 243, 0, "Catch Force Generator/LorentzForce/Lorentz2/product1",
    "", 0, 0, 3, 0, 0 },

  { 244, 0, "Catch Force Generator/LorentzForce/Lorentz2/product2",
    "", 0, 0, 3, 0, 0 },

  { 245, 0, "Catch Force Generator/LorentzForce/Lorentz2/product3",
    "", 0, 0, 3, 0, 0 },

  { 246, 0, "Catch Force Generator/LorentzForce/Lorentz2/product4",
    "", 0, 0, 3, 0, 0 },

  { 247, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add1",
    "", 0, 0, 3, 0, 0 },

  { 248, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add2",
    "", 0, 0, 3, 0, 0 },

  { 249, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add3",
    "", 0, 0, 3, 0, 0 },

  { 250, 0, "Catch Force Generator/LorentzForce/Lorentz2/Add4",
    "", 0, 0, 3, 0, 0 },

  { 251, 0, "Catch Force Generator/LorentzForce/Lorentz2/AddX",
    "", 0, 0, 3, 0, 0 },

  { 252, 0, "Catch Force Generator/LorentzForce/Lorentz2/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 253, 0, "Catch Force Generator/LorentzForce/Lorentz2/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 254, 0, "Catch Force Generator/LorentzForce/Lorentz2/x",
    "", 0, 0, 3, 0, 0 },

  { 255, 0, "Catch Force Generator/LorentzForce/Lorentz2/y",
    "", 0, 0, 3, 0, 0 },

  { 256, 0, "Catch Force Generator/LorentzForce/Lorentz2/z",
    "", 0, 0, 3, 0, 0 },

  { 257, 0, "Catch Force Generator/LorentzForce/Lorentz3/dX",
    "", 0, 0, 3, 0, 0 },

  { 258, 0, "Catch Force Generator/LorentzForce/Lorentz3/dY",
    "", 0, 0, 3, 0, 0 },

  { 259, 0, "Catch Force Generator/LorentzForce/Lorentz3/dZ",
    "", 0, 0, 3, 0, 0 },

  { 260, 0, "Catch Force Generator/LorentzForce/Lorentz3/product1",
    "", 0, 0, 3, 0, 0 },

  { 261, 0, "Catch Force Generator/LorentzForce/Lorentz3/product2",
    "", 0, 0, 3, 0, 0 },

  { 262, 0, "Catch Force Generator/LorentzForce/Lorentz3/product3",
    "", 0, 0, 3, 0, 0 },

  { 263, 0, "Catch Force Generator/LorentzForce/Lorentz3/product4",
    "", 0, 0, 3, 0, 0 },

  { 264, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add1",
    "", 0, 0, 3, 0, 0 },

  { 265, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add2",
    "", 0, 0, 3, 0, 0 },

  { 266, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add3",
    "", 0, 0, 3, 0, 0 },

  { 267, 0, "Catch Force Generator/LorentzForce/Lorentz3/Add4",
    "", 0, 0, 3, 0, 0 },

  { 268, 0, "Catch Force Generator/LorentzForce/Lorentz3/AddX",
    "", 0, 0, 3, 0, 0 },

  { 269, 0, "Catch Force Generator/LorentzForce/Lorentz3/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 270, 0, "Catch Force Generator/LorentzForce/Lorentz3/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 271, 0, "Catch Force Generator/LorentzForce/Lorentz3/x",
    "", 0, 0, 3, 0, 0 },

  { 272, 0, "Catch Force Generator/LorentzForce/Lorentz3/y",
    "", 0, 0, 3, 0, 0 },

  { 273, 0, "Catch Force Generator/LorentzForce/Lorentz3/z",
    "", 0, 0, 3, 0, 0 },

  { 274, 0, "Force Generator/LorentzForce/Lorentz/dX",
    "", 0, 0, 3, 0, 0 },

  { 275, 0, "Force Generator/LorentzForce/Lorentz/dY",
    "", 0, 0, 3, 0, 0 },

  { 276, 0, "Force Generator/LorentzForce/Lorentz/dZ",
    "", 0, 0, 3, 0, 0 },

  { 277, 0, "Force Generator/LorentzForce/Lorentz/product1",
    "", 0, 0, 3, 0, 0 },

  { 278, 0, "Force Generator/LorentzForce/Lorentz/product2",
    "", 0, 0, 3, 0, 0 },

  { 279, 0, "Force Generator/LorentzForce/Lorentz/product3",
    "", 0, 0, 3, 0, 0 },

  { 280, 0, "Force Generator/LorentzForce/Lorentz/product4",
    "", 0, 0, 3, 0, 0 },

  { 281, 0, "Force Generator/LorentzForce/Lorentz/Add1",
    "", 0, 0, 3, 0, 0 },

  { 282, 0, "Force Generator/LorentzForce/Lorentz/Add2",
    "", 0, 0, 3, 0, 0 },

  { 283, 0, "Force Generator/LorentzForce/Lorentz/Add3",
    "", 0, 0, 3, 0, 0 },

  { 284, 0, "Force Generator/LorentzForce/Lorentz/Add4",
    "", 0, 0, 3, 0, 0 },

  { 285, 0, "Force Generator/LorentzForce/Lorentz/AddX",
    "", 0, 0, 3, 0, 0 },

  { 286, 0, "Force Generator/LorentzForce/Lorentz/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 287, 0, "Force Generator/LorentzForce/Lorentz/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 288, 0, "Force Generator/LorentzForce/Lorentz/x",
    "", 0, 0, 3, 0, 0 },

  { 289, 0, "Force Generator/LorentzForce/Lorentz/y",
    "", 0, 0, 3, 0, 0 },

  { 290, 0, "Force Generator/LorentzForce/Lorentz/z",
    "", 0, 0, 3, 0, 0 },

  { 291, 0, "Force Generator/LorentzForce/Lorentz1/dX",
    "", 0, 0, 3, 0, 0 },

  { 292, 0, "Force Generator/LorentzForce/Lorentz1/dY",
    "", 0, 0, 3, 0, 0 },

  { 293, 0, "Force Generator/LorentzForce/Lorentz1/dZ",
    "", 0, 0, 3, 0, 0 },

  { 294, 0, "Force Generator/LorentzForce/Lorentz1/product1",
    "", 0, 0, 3, 0, 0 },

  { 295, 0, "Force Generator/LorentzForce/Lorentz1/product2",
    "", 0, 0, 3, 0, 0 },

  { 296, 0, "Force Generator/LorentzForce/Lorentz1/product3",
    "", 0, 0, 3, 0, 0 },

  { 297, 0, "Force Generator/LorentzForce/Lorentz1/product4",
    "", 0, 0, 3, 0, 0 },

  { 298, 0, "Force Generator/LorentzForce/Lorentz1/Add1",
    "", 0, 0, 3, 0, 0 },

  { 299, 0, "Force Generator/LorentzForce/Lorentz1/Add2",
    "", 0, 0, 3, 0, 0 },

  { 300, 0, "Force Generator/LorentzForce/Lorentz1/Add3",
    "", 0, 0, 3, 0, 0 },

  { 301, 0, "Force Generator/LorentzForce/Lorentz1/Add4",
    "", 0, 0, 3, 0, 0 },

  { 302, 0, "Force Generator/LorentzForce/Lorentz1/AddX",
    "", 0, 0, 3, 0, 0 },

  { 303, 0, "Force Generator/LorentzForce/Lorentz1/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 304, 0, "Force Generator/LorentzForce/Lorentz1/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 305, 0, "Force Generator/LorentzForce/Lorentz1/x",
    "", 0, 0, 3, 0, 0 },

  { 306, 0, "Force Generator/LorentzForce/Lorentz1/y",
    "", 0, 0, 3, 0, 0 },

  { 307, 0, "Force Generator/LorentzForce/Lorentz1/z",
    "", 0, 0, 3, 0, 0 },

  { 308, 0, "Force Generator/LorentzForce/Lorentz2/dX",
    "", 0, 0, 3, 0, 0 },

  { 309, 0, "Force Generator/LorentzForce/Lorentz2/dY",
    "", 0, 0, 3, 0, 0 },

  { 310, 0, "Force Generator/LorentzForce/Lorentz2/dZ",
    "", 0, 0, 3, 0, 0 },

  { 311, 0, "Force Generator/LorentzForce/Lorentz2/product1",
    "", 0, 0, 3, 0, 0 },

  { 312, 0, "Force Generator/LorentzForce/Lorentz2/product2",
    "", 0, 0, 3, 0, 0 },

  { 313, 0, "Force Generator/LorentzForce/Lorentz2/product3",
    "", 0, 0, 3, 0, 0 },

  { 314, 0, "Force Generator/LorentzForce/Lorentz2/product4",
    "", 0, 0, 3, 0, 0 },

  { 315, 0, "Force Generator/LorentzForce/Lorentz2/Add1",
    "", 0, 0, 3, 0, 0 },

  { 316, 0, "Force Generator/LorentzForce/Lorentz2/Add2",
    "", 0, 0, 3, 0, 0 },

  { 317, 0, "Force Generator/LorentzForce/Lorentz2/Add3",
    "", 0, 0, 3, 0, 0 },

  { 318, 0, "Force Generator/LorentzForce/Lorentz2/Add4",
    "", 0, 0, 3, 0, 0 },

  { 319, 0, "Force Generator/LorentzForce/Lorentz2/AddX",
    "", 0, 0, 3, 0, 0 },

  { 320, 0, "Force Generator/LorentzForce/Lorentz2/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 321, 0, "Force Generator/LorentzForce/Lorentz2/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 322, 0, "Force Generator/LorentzForce/Lorentz2/x",
    "", 0, 0, 3, 0, 0 },

  { 323, 0, "Force Generator/LorentzForce/Lorentz2/y",
    "", 0, 0, 3, 0, 0 },

  { 324, 0, "Force Generator/LorentzForce/Lorentz2/z",
    "", 0, 0, 3, 0, 0 },

  { 325, 0, "Force Generator/LorentzForce/Lorentz3/dX",
    "", 0, 0, 3, 0, 0 },

  { 326, 0, "Force Generator/LorentzForce/Lorentz3/dY",
    "", 0, 0, 3, 0, 0 },

  { 327, 0, "Force Generator/LorentzForce/Lorentz3/dZ",
    "", 0, 0, 3, 0, 0 },

  { 328, 0, "Force Generator/LorentzForce/Lorentz3/product1",
    "", 0, 0, 3, 0, 0 },

  { 329, 0, "Force Generator/LorentzForce/Lorentz3/product2",
    "", 0, 0, 3, 0, 0 },

  { 330, 0, "Force Generator/LorentzForce/Lorentz3/product3",
    "", 0, 0, 3, 0, 0 },

  { 331, 0, "Force Generator/LorentzForce/Lorentz3/product4",
    "", 0, 0, 3, 0, 0 },

  { 332, 0, "Force Generator/LorentzForce/Lorentz3/Add1",
    "", 0, 0, 3, 0, 0 },

  { 333, 0, "Force Generator/LorentzForce/Lorentz3/Add2",
    "", 0, 0, 3, 0, 0 },

  { 334, 0, "Force Generator/LorentzForce/Lorentz3/Add3",
    "", 0, 0, 3, 0, 0 },

  { 335, 0, "Force Generator/LorentzForce/Lorentz3/Add4",
    "", 0, 0, 3, 0, 0 },

  { 336, 0, "Force Generator/LorentzForce/Lorentz3/AddX",
    "", 0, 0, 3, 0, 0 },

  { 337, 0, "Force Generator/LorentzForce/Lorentz3/AddX1",
    "", 0, 0, 3, 0, 0 },

  { 338, 0, "Force Generator/LorentzForce/Lorentz3/AddX2",
    "", 0, 0, 3, 0, 0 },

  { 339, 0, "Force Generator/LorentzForce/Lorentz3/x",
    "", 0, 0, 3, 0, 0 },

  { 340, 0, "Force Generator/LorentzForce/Lorentz3/y",
    "", 0, 0, 3, 0, 0 },

  { 341, 0, "Force Generator/LorentzForce/Lorentz3/z",
    "", 0, 0, 3, 0, 0 },

  { 342, 18, "Motor Control/Force//Torque Transform/Transpose/Math Function",
    "", 0, 0, 6, 0, 0 },

  { 343, 0, "Motor Control/Schmidt/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 1 },

  { 344, 19, "Motor Control/Schmidt/Enabled Subsystem/In1",
    "", 0, 0, 3, 0, 1 },

  { 345, 0, "Recentering Subsystem/Falling Edge/Nonpositive/Compare",
    "", 0, 2, 3, 0, 0 },

  { 346, 0, "Recentering Subsystem/Falling Edge1/Nonpositive/Compare",
    "", 0, 2, 3, 0, 0 },

  { 347, 0, "Recentering Subsystem/No Movement/Compare To Constant2/Compare",
    "", 0, 2, 3, 0, 0 },

  { 348, 0, "Recentering Subsystem/No Movement/Compare To Constant3/Compare",
    "", 0, 2, 3, 0, 0 },

  { 349, 0, "Recentering Subsystem/Schmidt1/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 1 },

  { 350, 20, "Recentering Subsystem/Schmidt1/Enabled Subsystem/In1",
    "", 0, 0, 3, 0, 1 },

  { 351, 0, "Recentering Subsystem/Schmidt2/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 1 },

  { 352, 21, "Recentering Subsystem/Schmidt2/Enabled Subsystem/In1",
    "", 0, 0, 3, 0, 1 },

  { 353, 0, "Recentering Subsystem/Schmidt3/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 1 },

  { 354, 22, "Recentering Subsystem/Schmidt3/Enabled Subsystem/In1",
    "", 0, 0, 3, 0, 1 },

  { 355, 0, "Recentering Subsystem/Start Moving/Nonpositive/Compare",
    "", 0, 2, 3, 0, 0 },

  { 356, 0, "Recentering Subsystem/Timer/Compare To Zero/Compare",
    "", 0, 2, 3, 0, 1 },

  { 357, 0,
    "Recentering Subsystem/Timer/Detect Fall Nonpositive/FixPt Relational Operator",
    "", 0, 2, 3, 0, 0 },

  { 358, 0, "Recentering Subsystem/Timer/Detect Fall Nonpositive/Delay Input1",
    "U(k-1)", 0, 2, 3, 0, 0 },

  { 359, 23, "Recentering Subsystem/Timer/Enabled Subsystem/In1",
    "", 0, 0, 3, 0, 1 },

  { 360, 27, "RewardSbs/Schmidt/Sample and Hold/In",
    "", 0, 0, 3, 0, 3 },

  { 361, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "", 0, 0, 3, 0, 3 },

  { 362, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "", 0, 0, 3, 0, 3 },

  { 363, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Subtract",
    "", 0, 0, 3, 0, 3 },

  { 364, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Switch",
    "", 0, 0, 3, 0, 3 },

  { 365, 0,
    "Recentering Subsystem/Timer/Detect Fall Nonpositive/Nonpositive/Compare",
    "", 0, 2, 3, 0, 0 },

  { 366, 32,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Compare",
    "", 0, 1, 3, 0, 3 },

  { 367, 32,
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
  { 368, "Constant",
    "Value", 0, 3, 0 },

  { 369, "Behavior BC",
    "P1", 0, 3, 0 },

  { 370, "Behavior BC",
    "P2", 0, 3, 0 },

  { 371, "Behavior BC",
    "P3", 0, 3, 0 },

  { 372, "Behavior BC",
    "P4", 0, 3, 0 },

  { 373, "Behavior BC",
    "P5", 0, 3, 0 },

  { 374, "Behavior BC",
    "P6", 0, 3, 0 },

  { 375, "Behavior BC",
    "P7", 0, 3, 0 },

  { 376, "Behavior BC",
    "P8", 0, 3, 0 },

  { 377, "Behavior BC",
    "P9", 0, 3, 0 },

  { 378, "Behavior BC",
    "P10", 0, 3, 0 },

  { 379, "Behavior BC",
    "P11", 0, 3, 0 },

  { 380, "Behavior BC",
    "P12", 0, 3, 0 },

  { 381, "Behavior BC",
    "P13", 0, 3, 0 },

  { 382, "BoundingBox/XHighLimit",
    "Value", 0, 3, 0 },

  { 383, "BoundingBox/XLowLimit",
    "Value", 0, 3, 0 },

  { 384, "BoundingBox/YHighLimit",
    "Value", 0, 3, 0 },

  { 385, "BoundingBox/YLowLimit",
    "Value", 0, 3, 0 },

  { 386, "Catch Force Generator/DynamicAngle",
    "Value", 0, 3, 0 },

  { 387, "Catch Force Generator/Load",
    "Value", 0, 3, 0 },

  { 388, "Catch Force Generator/Off",
    "Value", 0, 3, 0 },

  { 389, "Catch Force Generator/staticX",
    "Value", 0, 3, 0 },

  { 390, "Catch Force Generator/staticY",
    "Value", 0, 3, 0 },

  { 391, "Catch Force Generator/visAngle",
    "Value", 0, 3, 0 },

  { 392, "Catch Force Generator/Gain",
    "Gain", 0, 3, 0 },

  { 393, "Catch Force Generator/LorentzForceGain",
    "Gain", 0, 3, 0 },

  { 394, "Force Generator/DynamicAngle",
    "Value", 0, 3, 0 },

  { 395, "Force Generator/Load",
    "Value", 0, 3, 0 },

  { 396, "Force Generator/Off",
    "Value", 0, 3, 0 },

  { 397, "Force Generator/staticX",
    "Value", 0, 3, 0 },

  { 398, "Force Generator/staticY",
    "Value", 0, 3, 0 },

  { 399, "Force Generator/visAngle",
    "Value", 0, 3, 0 },

  { 400, "Force Generator/Gain",
    "Gain", 0, 3, 0 },

  { 401, "Force Generator/LorentzForceGain",
    "Gain", 0, 3, 0 },

  { 402, "Motor Control/zeroX",
    "Value", 0, 3, 0 },

  { 403, "Motor Control/zeroY",
    "Value", 0, 3, 0 },

  { 404, "Motor Control/MG1",
    "Gain", 0, 3, 0 },

  { 405, "Motor Control/MG2",
    "Gain", 0, 3, 0 },

  { 406, "Motor Control/Memory",
    "X0", 1, 3, 0 },

  { 407, "Motor Control/PCI-6025E ",
    "P1", 0, 7, 0 },

  { 408, "Motor Control/PCI-6025E ",
    "P2", 0, 7, 0 },

  { 409, "Motor Control/PCI-6025E ",
    "P3", 0, 7, 0 },

  { 410, "Motor Control/PCI-6025E ",
    "P4", 0, 7, 0 },

  { 411, "Motor Control/PCI-6025E ",
    "P5", 0, 3, 0 },

  { 412, "Motor Control/PCI-6025E ",
    "P6", 0, 3, 0 },

  { 413, "Motor Control/PCI-6025E ",
    "P7", 0, 3, 0 },

  { 414, "Recentering Subsystem/RecenterFlag",
    "Value", 0, 3, 0 },

  { 415, "Recentering Subsystem/Bounding Box Viscosity",
    "Gain", 0, 3, 0 },

  { 416, "RewardSbs/JackpotChance",
    "Value", 0, 3, 0 },

  { 417, "RewardSbs/RewardJackpot",
    "Value", 0, 3, 0 },

  { 418, "RewardSbs/RewardTime",
    "Value", 0, 3, 0 },

  { 419, "RewardSbs/Uniform Random Number",
    "Minimum", 0, 3, 0 },

  { 420, "RewardSbs/Uniform Random Number",
    "Maximum", 0, 3, 0 },

  { 421, "RewardSbs/Uniform Random Number",
    "Seed", 0, 3, 0 },

  { 422, "SendPacketToGraphics1/NaN upper bytes",
    "Value", 3, 3, 0 },

  { 423, "SendPacketToGraphics1/Packet Spec",
    "Value", 3, 3, 0 },

  { 424, "SendPacketToGraphics1/Send",
    "P1", 0, 8, 0 },

  { 425, "SendPacketToGraphics1/Send",
    "P2", 0, 3, 0 },

  { 426, "SendPacketToGraphics1/Send",
    "P3", 0, 3, 0 },

  { 427, "SendPacketToGraphics1/Send",
    "P4", 0, 3, 0 },

  { 428, "Velocity Calculation/UseTachs",
    "Value", 0, 3, 0 },

  { 429, "Velocity Calculation/TachGain1",
    "Gain", 0, 3, 0 },

  { 430, "Velocity Calculation/TachGain2",
    "Gain", 0, 3, 0 },

  { 431, "Velocity Calculation/PCI-6025E AD",
    "P1", 0, 7, 0 },

  { 432, "Velocity Calculation/PCI-6025E AD",
    "P2", 0, 7, 0 },

  { 433, "Velocity Calculation/PCI-6025E AD",
    "P3", 0, 7, 0 },

  { 434, "Velocity Calculation/PCI-6025E AD",
    "P4", 0, 3, 0 },

  { 435, "Velocity Calculation/PCI-6025E AD",
    "P5", 0, 3, 0 },

  { 436, "Velocity Calculation/PCI-6025E AD",
    "P6", 0, 3, 0 },

  { 437, "Velocity Calculation/Switch",
    "Threshold", 0, 3, 0 },

  { 438, "XY Position Subsystem/elbowOffset",
    "Value", 0, 3, 0 },

  { 439, "XY Position Subsystem/shoulderOffset",
    "Value", 0, 3, 0 },

  { 440, "XY Position Subsystem/Gain",
    "Gain", 0, 3, 0 },

  { 441, "XY Position Subsystem/Gain1",
    "Gain", 0, 3, 0 },

  { 442, "XY Position Subsystem/PCI-QUAD04 ",
    "P1", 0, 3, 0 },

  { 443, "XY Position Subsystem/PCI-QUAD04 ",
    "P2", 0, 3, 0 },

  { 444, "XY Position Subsystem/PCI-QUAD04 ",
    "P3", 0, 3, 0 },

  { 445, "XY Position Subsystem/PCI-QUAD04 ",
    "P4", 0, 3, 0 },

  { 446, "XY Position Subsystem/PCI-QUAD04 ",
    "P5", 0, 3, 0 },

  { 447, "XY Position Subsystem/PCI-QUAD04 ",
    "P6", 0, 3, 0 },

  { 448, "XY Position Subsystem/PCI-QUAD04 ",
    "P7", 0, 3, 0 },

  { 449, "XY Position Subsystem/PCI-QUAD04 ",
    "P8", 0, 3, 0 },

  { 450, "XY Position Subsystem/PCI-QUAD04 ",
    "P9", 0, 3, 0 },

  { 451, "XY Position Subsystem/PCI-QUAD04 ",
    "P10", 0, 3, 0 },

  { 452, "XY Position Subsystem/PCI-QUAD04 ",
    "P11", 0, 3, 0 },

  { 453, "XY Position Subsystem/PCI-QUAD04 1",
    "P1", 0, 3, 0 },

  { 454, "XY Position Subsystem/PCI-QUAD04 1",
    "P2", 0, 3, 0 },

  { 455, "XY Position Subsystem/PCI-QUAD04 1",
    "P3", 0, 3, 0 },

  { 456, "XY Position Subsystem/PCI-QUAD04 1",
    "P4", 0, 3, 0 },

  { 457, "XY Position Subsystem/PCI-QUAD04 1",
    "P5", 0, 3, 0 },

  { 458, "XY Position Subsystem/PCI-QUAD04 1",
    "P6", 0, 3, 0 },

  { 459, "XY Position Subsystem/PCI-QUAD04 1",
    "P7", 0, 3, 0 },

  { 460, "XY Position Subsystem/PCI-QUAD04 1",
    "P8", 0, 3, 0 },

  { 461, "XY Position Subsystem/PCI-QUAD04 1",
    "P9", 0, 3, 0 },

  { 462, "XY Position Subsystem/PCI-QUAD04 1",
    "P10", 0, 3, 0 },

  { 463, "XY Position Subsystem/PCI-QUAD04 1",
    "P11", 0, 3, 0 },

  { 464, "Catch Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 3, 0 },

  { 465, "Catch Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 3, 0 },

  { 466, "Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 0, 3, 0 },

  { 467, "Force Generator/ViscLoadSubsystem/Inverter",
    "Gain", 0, 3, 0 },

  { 468, "Motor Control/Compare To Constant/Constant",
    "Value", 0, 3, 0 },

  { 469, "Motor Control/Compare To Constant1/Constant",
    "Value", 0, 3, 0 },

  { 470, "Motor Control/Force//Torque Transform/Gain",
    "Gain", 0, 3, 0 },

  { 471, "Motor Control/Schmidt/Time",
    "Value", 0, 3, 0 },

  { 472, "Motor Control/Schmidt/Memory",
    "X0", 1, 3, 0 },

  { 473, "Recentering Subsystem/Falling Edge/Delay Input1",
    "X0", 2, 3, 0 },

  { 474, "Recentering Subsystem/Falling Edge1/Delay Input1",
    "X0", 2, 3, 0 },

  { 475, "Recentering Subsystem/PD Controller/Gain1",
    "Gain", 0, 3, 0 },

  { 476, "Recentering Subsystem/PD Controller/Gain2",
    "Gain", 0, 3, 0 },

  { 477, "Recentering Subsystem/PD Controller/Gain3",
    "Gain", 0, 3, 0 },

  { 478, "Recentering Subsystem/PD Controller/Gain4",
    "Gain", 0, 3, 0 },

  { 479, "Recentering Subsystem/PD Controller/Saturation",
    "UpperLimit", 0, 3, 0 },

  { 480, "Recentering Subsystem/PD Controller/Saturation",
    "LowerLimit", 0, 3, 0 },

  { 481, "Recentering Subsystem/PD Controller/Saturation1",
    "UpperLimit", 0, 3, 0 },

  { 482, "Recentering Subsystem/PD Controller/Saturation1",
    "LowerLimit", 0, 3, 0 },

  { 483, "Recentering Subsystem/S-R Flip-Flop/Logic",
    "TruthTable", 1, 9, 0 },

  { 484, "Recentering Subsystem/S-R Flip-Flop/Memory",
    "X0", 1, 3, 0 },

  { 485, "Recentering Subsystem/Schmidt1/Time",
    "Value", 0, 3, 0 },

  { 486, "Recentering Subsystem/Schmidt1/Memory",
    "X0", 1, 3, 0 },

  { 487, "Recentering Subsystem/Schmidt2/Time",
    "Value", 0, 3, 0 },

  { 488, "Recentering Subsystem/Schmidt2/Memory",
    "X0", 1, 3, 0 },

  { 489, "Recentering Subsystem/Schmidt3/Time",
    "Value", 0, 3, 0 },

  { 490, "Recentering Subsystem/Schmidt3/Memory",
    "X0", 1, 3, 0 },

  { 491, "Recentering Subsystem/Start Moving/Delay Input1",
    "X0", 2, 3, 0 },

  { 492, "Recentering Subsystem/Timer/Time",
    "Value", 0, 3, 0 },

  { 493, "Recentering Subsystem/Timer/Memory",
    "X0", 1, 3, 0 },

  { 494, "Velocity Calculation/Pos2VelX/dG",
    "Gain", 0, 3, 0 },

  { 495, "Velocity Calculation/Pos2VelX/Digital Filter",
    "ICRTP", 0, 3, 0 },

  { 496, "Velocity Calculation/Pos2VelX/Digital Filter",
    "RTP1COEFF", 0, 8, 0 },

  { 497, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "ICRTP", 0, 3, 0 },

  { 498, "Velocity Calculation/Pos2VelX/Digital Filter2",
    "RTP1COEFF", 0, 8, 0 },

  { 499, "Velocity Calculation/Pos2VelY/dG",
    "Gain", 0, 3, 0 },

  { 500, "Velocity Calculation/Pos2VelY/Digital Filter",
    "ICRTP", 0, 3, 0 },

  { 501, "Velocity Calculation/Pos2VelY/Digital Filter",
    "RTP1COEFF", 0, 8, 0 },

  { 502, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "ICRTP", 0, 3, 0 },

  { 503, "Velocity Calculation/Pos2VelY/Digital Filter2",
    "RTP1COEFF", 0, 8, 0 },

  { 504, "XY Position Subsystem/Cursor Rotation/AngleOffset",
    "Value", 0, 3, 0 },

  { 505, "XY Position Subsystem/For Iterator Subsystem/Constant",
    "Value", 0, 3, 0 },

  { 506, "XY Position Subsystem/For Iterator Subsystem/Constant2",
    "Value", 0, 3, 0 },

  { 507, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P1", 0, 10, 0 },

  { 508, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P2", 0, 3, 0 },

  { 509, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P3", 0, 10, 0 },

  { 510, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P4", 0, 10, 0 },

  { 511, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P5", 0, 3, 0 },

  { 512, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P6", 0, 3, 0 },

  { 513, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P7", 0, 3, 0 },

  { 514, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P8", 0, 3, 0 },

  { 515, "XY Position Subsystem/For Iterator Subsystem/Port A",
    "P9", 0, 3, 0 },

  { 516, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P1", 0, 10, 0 },

  { 517, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P2", 0, 3, 0 },

  { 518, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P3", 0, 10, 0 },

  { 519, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P4", 0, 10, 0 },

  { 520, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P5", 0, 3, 0 },

  { 521, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P6", 0, 3, 0 },

  { 522, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P7", 0, 3, 0 },

  { 523, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P8", 0, 3, 0 },

  { 524, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P9", 0, 3, 0 },

  { 525, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 3, 0 },

  { 526, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 3, 0 },

  { 527, "XY Position Subsystem/For Iterator Subsystem/Switch",
    "Threshold", 0, 3, 0 },

  { 528, "XY Position Subsystem/Jacobian-Cartesian Transformation/L1",
    "Value", 0, 3, 0 },

  { 529, "XY Position Subsystem/Jacobian-Cartesian Transformation/L2",
    "Value", 0, 3, 0 },

  { 530, "XY Position Subsystem/Jacobian-Cartesian Transformation/xoffset",
    "Value", 0, 3, 0 },

  { 531, "XY Position Subsystem/Jacobian-Cartesian Transformation/yoffset",
    "Value", 0, 3, 0 },

  { 532, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain",
    "Gain", 0, 3, 0 },

  { 533, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain1",
    "Gain", 0, 3, 0 },

  { 534, "XY Position Subsystem/Jacobian-Cartesian Transformation/Gain2",
    "Gain", 0, 3, 0 },

  { 535, "Catch Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 3, 0 },

  { 536, "Catch Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 3, 0 },

  { 537, "Catch Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 3, 0 },

  { 538, "Catch Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 3, 0 },

  { 539, "Catch Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 3, 0 },

  { 540, "Catch Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 3, 0 },

  { 541, "Catch Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 3, 0 },

  { 542, "Catch Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 3, 0 },

  { 543, "Catch Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 3, 0 },

  { 544, "Catch Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 3, 0 },

  { 545, "Catch Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 3, 0 },

  { 546, "Catch Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 3, 0 },

  { 547, "Catch Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 3, 0 },

  { 548, "Catch Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 3, 0 },

  { 549, "Catch Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 3, 0 },

  { 550, "Catch Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 3, 0 },

  { 551, "Catch Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 3, 0 },

  { 552, "Catch Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 3, 0 },

  { 553, "Catch Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 3, 0 },

  { 554, "Catch Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 3, 0 },

  { 555, "Catch Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 3, 0 },

  { 556, "Catch Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 3, 0 },

  { 557, "Catch Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 3, 0 },

  { 558, "Catch Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 3, 0 },

  { 559, "Catch Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 3, 0 },

  { 560, "Catch Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 3, 0 },

  { 561, "Catch Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 3, 0 },

  { 562, "Catch Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 3, 0 },

  { 563, "Force Generator/LorentzForce/Lorentz/beta",
    "Value", 0, 3, 0 },

  { 564, "Force Generator/LorentzForce/Lorentz/rho",
    "Value", 0, 3, 0 },

  { 565, "Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 0, 3, 0 },

  { 566, "Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 0, 3, 0 },

  { 567, "Force Generator/LorentzForce/Lorentz/x",
    "X0", 0, 3, 0 },

  { 568, "Force Generator/LorentzForce/Lorentz/y",
    "X0", 0, 3, 0 },

  { 569, "Force Generator/LorentzForce/Lorentz/z",
    "X0", 0, 3, 0 },

  { 570, "Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 0, 3, 0 },

  { 571, "Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 0, 3, 0 },

  { 572, "Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 0, 3, 0 },

  { 573, "Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 0, 3, 0 },

  { 574, "Force Generator/LorentzForce/Lorentz1/x",
    "X0", 0, 3, 0 },

  { 575, "Force Generator/LorentzForce/Lorentz1/y",
    "X0", 0, 3, 0 },

  { 576, "Force Generator/LorentzForce/Lorentz1/z",
    "X0", 0, 3, 0 },

  { 577, "Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 0, 3, 0 },

  { 578, "Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 0, 3, 0 },

  { 579, "Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 0, 3, 0 },

  { 580, "Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 0, 3, 0 },

  { 581, "Force Generator/LorentzForce/Lorentz2/x",
    "X0", 0, 3, 0 },

  { 582, "Force Generator/LorentzForce/Lorentz2/y",
    "X0", 0, 3, 0 },

  { 583, "Force Generator/LorentzForce/Lorentz2/z",
    "X0", 0, 3, 0 },

  { 584, "Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 0, 3, 0 },

  { 585, "Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 0, 3, 0 },

  { 586, "Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 0, 3, 0 },

  { 587, "Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 0, 3, 0 },

  { 588, "Force Generator/LorentzForce/Lorentz3/x",
    "X0", 0, 3, 0 },

  { 589, "Force Generator/LorentzForce/Lorentz3/y",
    "X0", 0, 3, 0 },

  { 590, "Force Generator/LorentzForce/Lorentz3/z",
    "X0", 0, 3, 0 },

  { 591, "Recentering Subsystem/No Movement/Compare To Constant2/Constant",
    "Value", 0, 3, 0 },

  { 592, "Recentering Subsystem/No Movement/Compare To Constant3/Constant",
    "Value", 0, 3, 0 },

  { 593, "Recentering Subsystem/Timer/Detect Fall Nonpositive/Delay Input1",
    "X0", 2, 3, 0 },

  { 594,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant",
    "Value", 0, 3, 0 },

  { 595,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant1",
    "Value", 0, 3, 0 },

  { 596,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "Gain", 0, 3, 0 },

  { 597,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P1", 0, 7, 0 },

  { 598,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P2", 0, 7, 0 },

  { 599,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P3", 0, 7, 0 },

  { 600,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P4", 0, 3, 0 },

  { 601,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P5", 0, 3, 0 },

  { 602,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P6", 0, 3, 0 },

  { 603,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P7", 0, 3, 0 },

  { 604,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P1", 0, 3, 0 },

  { 605,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P2", 0, 3, 0 },

  { 606,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Constant",
    "Value", 0, 3, 0 },

  { 607,
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
  &bump_choice_B.MatrixConcatenation1[0],/* 0: Signal */
  &bump_choice_B.BehaviorBC_o1[0],     /* 1: Signal */
  &bump_choice_B.BehaviorBC_o2[0],     /* 2: Signal */
  &bump_choice_B.BehaviorBC_o3,        /* 3: Signal */
  &bump_choice_B.BehaviorBC_o4[0],     /* 4: Signal */
  &bump_choice_B.BehaviorBC_o5,        /* 5: Signal */
  &bump_choice_B.BehaviorBC_o6[0],     /* 6: Signal */
  &bump_choice_B.BehaviorBC_o7[0],     /* 7: Signal */
  &bump_choice_B.BehaviorBC_o8[0],     /* 8: Signal */
  &bump_choice_B.LogicalOperator_a,    /* 9: Signal */
  &bump_choice_B.RelationalOperator_g, /* 10: Signal */
  &bump_choice_B.RelationalOperator1,  /* 11: Signal */
  &bump_choice_B.RelationalOperator2,  /* 12: Signal */
  &bump_choice_B.RelationalOperator3,  /* 13: Signal */
  &bump_choice_B.Gain_a,               /* 14: Signal */
  &bump_choice_B.LorentzForceGain_p[0],/* 15: Signal */
  &bump_choice_B.DynamicAngleSwitch,   /* 16: Signal */
  &bump_choice_B.LoadSelectSwitch[0],  /* 17: Signal */
  &bump_choice_B.Gain_n,               /* 18: Signal */
  &bump_choice_B.LorentzForceGain[0],  /* 19: Signal */
  &bump_choice_B.MultiportSwitch[0],   /* 20: Signal */
  &bump_choice_B.dynamicAngleSwitch,   /* 21: Signal */
  &bump_choice_B.MatrixConcatenation[0],/* 22: Signal */
  &bump_choice_B.MG1,                  /* 23: Signal */
  &bump_choice_B.MG2,                  /* 24: Signal */
  &bump_choice_B.LogicalOperator1_it,  /* 25: Signal */
  &bump_choice_B.Memory_k,             /* 26: Signal */
  &bump_choice_B.Switch1[0],           /* 27: Signal */
  &bump_choice_B.Switch2[0],           /* 28: Signal */
  &bump_choice_B.DataTypeConversion1,  /* 29: Signal */
  &bump_choice_B.DataTypeConversion2,  /* 30: Signal */
  &bump_choice_B.BoundingBoxViscosity[0],/* 31: Signal */
  &bump_choice_B.InBox,                /* 32: Signal */
  &bump_choice_B.LogicalOperator_j,    /* 33: Signal */
  &bump_choice_B.LogicalOperator1_g,   /* 34: Signal */
  &bump_choice_B.LogicalOperator3_d,   /* 35: Signal */
  &bump_choice_B.LogicalOperator5_k,   /* 36: Signal */
  &bump_choice_B.LogicalOperator6,     /* 37: Signal */
  &bump_choice_B.NOT,                  /* 38: Signal */
  &bump_choice_B.Switch_j[0],          /* 39: Signal */
  &bump_choice_B.DataTypeConversion,   /* 40: Signal */
  &bump_choice_B.RelationalOperator_ka,/* 41: Signal */
  &bump_choice_B.Switch_o,             /* 42: Signal */
  &bump_choice_B.UniformRandomNumber,  /* 43: Signal */
  &bump_choice_B.RateTransition[0],    /* 44: Signal */
  &bump_choice_B.Pack[0],              /* 45: Signal */
  &bump_choice_B.TachGain1,            /* 46: Signal */
  &bump_choice_B.TachGain2,            /* 47: Signal */
  &bump_choice_B.MatrixMultiply[0],    /* 48: Signal */
  &bump_choice_B.PCI6025EAD_o1,        /* 49: Signal */
  &bump_choice_B.PCI6025EAD_o2,        /* 50: Signal */
  &bump_choice_B.Switch[0],            /* 51: Signal */
  &bump_choice_B.Gain,                 /* 52: Signal */
  &bump_choice_B.Gain1,                /* 53: Signal */
  &bump_choice_B.PCIQUAD04,            /* 54: Signal */
  &bump_choice_B.PCIQUAD041,           /* 55: Signal */
  &bump_choice_B.Sum1,                 /* 56: Signal */
  &bump_choice_B.Sum3,                 /* 57: Signal */
  &bump_choice_B.Add_k,                /* 58: Signal */
  &bump_choice_B.Add1_k,               /* 59: Signal */
  &bump_choice_B.Gain_f[0],            /* 60: Signal */
  &bump_choice_B.Inverter_k[0],        /* 61: Signal */
  &bump_choice_B.Product_i,            /* 62: Signal */
  &bump_choice_B.Product1_p,           /* 63: Signal */
  &bump_choice_B.Product2_g,           /* 64: Signal */
  &bump_choice_B.Product3_h,           /* 65: Signal */
  &bump_choice_B.Add_ht,               /* 66: Signal */
  &bump_choice_B.Subtract_e,           /* 67: Signal */
  &bump_choice_B.cos_m,                /* 68: Signal */
  &bump_choice_B.sin_i,                /* 69: Signal */
  &bump_choice_B.Add,                  /* 70: Signal */
  &bump_choice_B.Add1_f,               /* 71: Signal */
  &bump_choice_B.Gain_d[0],            /* 72: Signal */
  &bump_choice_B.Inverter[0],          /* 73: Signal */
  &bump_choice_B.Product_a,            /* 74: Signal */
  &bump_choice_B.Product1_l,           /* 75: Signal */
  &bump_choice_B.Product2_l,           /* 76: Signal */
  &bump_choice_B.Product3_k,           /* 77: Signal */
  &bump_choice_B.Add_h,                /* 78: Signal */
  &bump_choice_B.Subtract_b,           /* 79: Signal */
  &bump_choice_B.cos_c,                /* 80: Signal */
  &bump_choice_B.sin_h,                /* 81: Signal */
  &bump_choice_B.Compare_p,            /* 82: Signal */
  &bump_choice_B.Compare_hq,           /* 83: Signal */
  &bump_choice_B.Gain_i[0],            /* 84: Signal */
  &bump_choice_B.MatrixMultiply_c[0],  /* 85: Signal */
  &bump_choice_B.Clock,                /* 86: Signal */
  &bump_choice_B.LogicalOperator,      /* 87: Signal */
  &bump_choice_B.LogicalOperator1,     /* 88: Signal */
  &bump_choice_B.LogicalOperator2,     /* 89: Signal */
  &bump_choice_B.Memory,               /* 90: Signal */
  &bump_choice_B.RelationalOperator,   /* 91: Signal */
  &bump_choice_B.Sum,                  /* 92: Signal */
  &bump_choice_B.Compare_a,            /* 93: Signal */
  &bump_choice_B.Compare_e,            /* 94: Signal */
  &bump_choice_B.FixPtRelationalOperator_o,/* 95: Signal */
  &bump_choice_B.Uk1_m,                /* 96: Signal */
  &bump_choice_B.FixPtRelationalOperator_j,/* 97: Signal */
  &bump_choice_B.Uk1_j,                /* 98: Signal */
  &bump_choice_B.Abs2,                 /* 99: Signal */
  &bump_choice_B.Abs3,                 /* 100: Signal */
  &bump_choice_B.LogicalOperator1_e,   /* 101: Signal */
  &bump_choice_B.Gain1_n,              /* 102: Signal */
  &bump_choice_B.Gain2,                /* 103: Signal */
  &bump_choice_B.Gain3,                /* 104: Signal */
  &bump_choice_B.Gain4,                /* 105: Signal */
  &bump_choice_B.Product_g,            /* 106: Signal */
  &bump_choice_B.Product1_o,           /* 107: Signal */
  &bump_choice_B.Saturation,           /* 108: Signal */
  &bump_choice_B.Saturation1,          /* 109: Signal */
  &bump_choice_B.Add_i,                /* 110: Signal */
  &bump_choice_B.Add1_ef,              /* 111: Signal */
  &bump_choice_B.Logic[0],             /* 112: Signal */
  &bump_choice_B.Memory_j,             /* 113: Signal */
  &bump_choice_B.Clock_k,              /* 114: Signal */
  &bump_choice_B.LogicalOperator_e,    /* 115: Signal */
  &bump_choice_B.LogicalOperator1_c,   /* 116: Signal */
  &bump_choice_B.LogicalOperator2_a,   /* 117: Signal */
  &bump_choice_B.Memory_b,             /* 118: Signal */
  &bump_choice_B.RelationalOperator_l, /* 119: Signal */
  &bump_choice_B.Sum_l,                /* 120: Signal */
  &bump_choice_B.Clock_d,              /* 121: Signal */
  &bump_choice_B.LogicalOperator_nd,   /* 122: Signal */
  &bump_choice_B.LogicalOperator1_l,   /* 123: Signal */
  &bump_choice_B.LogicalOperator2_i,   /* 124: Signal */
  &bump_choice_B.Memory_m,             /* 125: Signal */
  &bump_choice_B.RelationalOperator_k, /* 126: Signal */
  &bump_choice_B.Sum_hb,               /* 127: Signal */
  &bump_choice_B.Clock_p,              /* 128: Signal */
  &bump_choice_B.LogicalOperator_c,    /* 129: Signal */
  &bump_choice_B.LogicalOperator1_i,   /* 130: Signal */
  &bump_choice_B.LogicalOperator2_a2,  /* 131: Signal */
  &bump_choice_B.Memory_n,             /* 132: Signal */
  &bump_choice_B.RelationalOperator_p, /* 133: Signal */
  &bump_choice_B.Sum_h,                /* 134: Signal */
  &bump_choice_B.FixPtRelationalOperator_p,/* 135: Signal */
  &bump_choice_B.Uk1_c,                /* 136: Signal */
  &bump_choice_B.Clock_h,              /* 137: Signal */
  &bump_choice_B.LogicalOperator_n,    /* 138: Signal */
  &bump_choice_B.LogicalOperator1_f,   /* 139: Signal */
  &bump_choice_B.LogicalOperator2_m,   /* 140: Signal */
  &bump_choice_B.LogicalOperator3,     /* 141: Signal */
  &bump_choice_B.LogicalOperator4,     /* 142: Signal */
  &bump_choice_B.LogicalOperator5,     /* 143: Signal */
  &bump_choice_B.Memory_b5,            /* 144: Signal */
  &bump_choice_B.RelationalOperator_i, /* 145: Signal */
  &bump_choice_B.Sum_n,                /* 146: Signal */
  &bump_choice_B.SampleandHold_h.In,   /* 147: Signal */
  &bump_choice_B.Clock_o,              /* 148: Signal */
  &bump_choice_B.RelationalOperator_b, /* 149: Signal */
  &bump_choice_B.Sum_p,                /* 150: Signal */
  &bump_choice_B.Derivative,           /* 151: Signal */
  &bump_choice_B.dG,                   /* 152: Signal */
  &bump_choice_B.DigitalFilter,        /* 153: Signal */
  &bump_choice_B.DigitalFilter2,       /* 154: Signal */
  &bump_choice_B.Derivative_i,         /* 155: Signal */
  &bump_choice_B.dG_c,                 /* 156: Signal */
  &bump_choice_B.DigitalFilter_k,      /* 157: Signal */
  &bump_choice_B.DigitalFilter2_c,     /* 158: Signal */
  &bump_choice_B.sqrtu1u1u2u2,         /* 159: Signal */
  &bump_choice_B.Product_f,            /* 160: Signal */
  &bump_choice_B.Product1_b,           /* 161: Signal */
  &bump_choice_B.Sum_c,                /* 162: Signal */
  &bump_choice_B.TrigonometricFunction_d,/* 163: Signal */
  &bump_choice_B.TrigonometricFunction1_o,/* 164: Signal */
  &bump_choice_B.TrigonometricFunction2_l,/* 165: Signal */
  &bump_choice_B.ForIterator,          /* 166: Signal */
  &bump_choice_B.SerialConverter,      /* 167: Signal */
  &bump_choice_B.ToBits_o1,            /* 168: Signal */
  &bump_choice_B.ToBits_o2,            /* 169: Signal */
  &bump_choice_B.ToBits_o3,            /* 170: Signal */
  &bump_choice_B.ToBits_o4,            /* 171: Signal */
  &bump_choice_B.ToBits_o5,            /* 172: Signal */
  &bump_choice_B.ToBits_o6,            /* 173: Signal */
  &bump_choice_B.ToBits_o7,            /* 174: Signal */
  &bump_choice_B.ToBits_o8,            /* 175: Signal */
  &bump_choice_B.ToBits1_o1,           /* 176: Signal */
  &bump_choice_B.ToBits1_o2,           /* 177: Signal */
  &bump_choice_B.ToBits1_o3,           /* 178: Signal */
  &bump_choice_B.ToBits1_o4,           /* 179: Signal */
  &bump_choice_B.ToBits1_o5,           /* 180: Signal */
  &bump_choice_B.ToBits1_o6,           /* 181: Signal */
  &bump_choice_B.ToBits1_o7,           /* 182: Signal */
  &bump_choice_B.ToBits1_o8,           /* 183: Signal */
  &bump_choice_B.xPCTargetTime,        /* 184: Signal */
  &bump_choice_B.Add_ks,               /* 185: Signal */
  &bump_choice_B.Add1_md,              /* 186: Signal */
  &bump_choice_B.Switch_b,             /* 187: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 188: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 189: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 190: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 191: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 192: Signal */
  &bump_choice_B.MatrixConcatenate2[0],/* 193: Signal */
  &bump_choice_B.Product,              /* 194: Signal */
  &bump_choice_B.Product1,             /* 195: Signal */
  &bump_choice_B.Product2,             /* 196: Signal */
  &bump_choice_B.Product3,             /* 197: Signal */
  &bump_choice_B.Sum1_k,               /* 198: Signal */
  &bump_choice_B.Sum2,                 /* 199: Signal */
  &bump_choice_B.Sum3_o,               /* 200: Signal */
  &bump_choice_B.Sum4,                 /* 201: Signal */
  &bump_choice_B.TrigonometricFunction,/* 202: Signal */
  &bump_choice_B.TrigonometricFunction1,/* 203: Signal */
  &bump_choice_B.TrigonometricFunction2,/* 204: Signal */
  &bump_choice_B.TrigonometricFunction3,/* 205: Signal */
  &bump_choice_B.dX,                   /* 206: Signal */
  &bump_choice_B.dY,                   /* 207: Signal */
  &bump_choice_B.dZ,                   /* 208: Signal */
  &bump_choice_B.product1,             /* 209: Signal */
  &bump_choice_B.product2,             /* 210: Signal */
  &bump_choice_B.product3,             /* 211: Signal */
  &bump_choice_B.product4,             /* 212: Signal */
  &bump_choice_B.Add1,                 /* 213: Signal */
  &bump_choice_B.Add2,                 /* 214: Signal */
  &bump_choice_B.Add3,                 /* 215: Signal */
  &bump_choice_B.Add4,                 /* 216: Signal */
  &bump_choice_B.AddX,                 /* 217: Signal */
  &bump_choice_B.AddX1,                /* 218: Signal */
  &bump_choice_B.AddX2,                /* 219: Signal */
  &bump_choice_B.x_b,                  /* 220: Signal */
  &bump_choice_B.y,                    /* 221: Signal */
  &bump_choice_B.z,                    /* 222: Signal */
  &bump_choice_B.dX_c,                 /* 223: Signal */
  &bump_choice_B.dY_d,                 /* 224: Signal */
  &bump_choice_B.dZ_f,                 /* 225: Signal */
  &bump_choice_B.product1_b,           /* 226: Signal */
  &bump_choice_B.product2_a,           /* 227: Signal */
  &bump_choice_B.product3_h,           /* 228: Signal */
  &bump_choice_B.product4_e,           /* 229: Signal */
  &bump_choice_B.Add1_l,               /* 230: Signal */
  &bump_choice_B.Add2_p,               /* 231: Signal */
  &bump_choice_B.Add3_j,               /* 232: Signal */
  &bump_choice_B.Add4_c,               /* 233: Signal */
  &bump_choice_B.AddX_h,               /* 234: Signal */
  &bump_choice_B.AddX1_b,              /* 235: Signal */
  &bump_choice_B.AddX2_d,              /* 236: Signal */
  &bump_choice_B.x_c,                  /* 237: Signal */
  &bump_choice_B.y_d,                  /* 238: Signal */
  &bump_choice_B.z_i,                  /* 239: Signal */
  &bump_choice_B.dX_k,                 /* 240: Signal */
  &bump_choice_B.dY_l,                 /* 241: Signal */
  &bump_choice_B.dZ_o,                 /* 242: Signal */
  &bump_choice_B.product1_g,           /* 243: Signal */
  &bump_choice_B.product2_c,           /* 244: Signal */
  &bump_choice_B.product3_p,           /* 245: Signal */
  &bump_choice_B.product4_g,           /* 246: Signal */
  &bump_choice_B.Add1_g,               /* 247: Signal */
  &bump_choice_B.Add2_f,               /* 248: Signal */
  &bump_choice_B.Add3_o,               /* 249: Signal */
  &bump_choice_B.Add4_g,               /* 250: Signal */
  &bump_choice_B.AddX_n,               /* 251: Signal */
  &bump_choice_B.AddX1_a,              /* 252: Signal */
  &bump_choice_B.AddX2_e,              /* 253: Signal */
  &bump_choice_B.x_j,                  /* 254: Signal */
  &bump_choice_B.y_a,                  /* 255: Signal */
  &bump_choice_B.z_g,                  /* 256: Signal */
  &bump_choice_B.dX_m,                 /* 257: Signal */
  &bump_choice_B.dY_b,                 /* 258: Signal */
  &bump_choice_B.dZ_m,                 /* 259: Signal */
  &bump_choice_B.product1_l,           /* 260: Signal */
  &bump_choice_B.product2_l,           /* 261: Signal */
  &bump_choice_B.product3_d,           /* 262: Signal */
  &bump_choice_B.product4_f,           /* 263: Signal */
  &bump_choice_B.Add1_e,               /* 264: Signal */
  &bump_choice_B.Add2_o,               /* 265: Signal */
  &bump_choice_B.Add3_m,               /* 266: Signal */
  &bump_choice_B.Add4_j,               /* 267: Signal */
  &bump_choice_B.AddX_j,               /* 268: Signal */
  &bump_choice_B.AddX1_d,              /* 269: Signal */
  &bump_choice_B.AddX2_eh,             /* 270: Signal */
  &bump_choice_B.x_h,                  /* 271: Signal */
  &bump_choice_B.y_k,                  /* 272: Signal */
  &bump_choice_B.z_j,                  /* 273: Signal */
  &bump_choice_B.dX_b,                 /* 274: Signal */
  &bump_choice_B.dY_l3,                /* 275: Signal */
  &bump_choice_B.dZ_l,                 /* 276: Signal */
  &bump_choice_B.product1_a,           /* 277: Signal */
  &bump_choice_B.product2_j,           /* 278: Signal */
  &bump_choice_B.product3_j,           /* 279: Signal */
  &bump_choice_B.product4_p,           /* 280: Signal */
  &bump_choice_B.Add1_gp,              /* 281: Signal */
  &bump_choice_B.Add2_k,               /* 282: Signal */
  &bump_choice_B.Add3_g,               /* 283: Signal */
  &bump_choice_B.Add4_o,               /* 284: Signal */
  &bump_choice_B.AddX_m,               /* 285: Signal */
  &bump_choice_B.AddX1_l,              /* 286: Signal */
  &bump_choice_B.AddX2_l,              /* 287: Signal */
  &bump_choice_B.x,                    /* 288: Signal */
  &bump_choice_B.y_p,                  /* 289: Signal */
  &bump_choice_B.z_o,                  /* 290: Signal */
  &bump_choice_B.dX_h,                 /* 291: Signal */
  &bump_choice_B.dY_d5,                /* 292: Signal */
  &bump_choice_B.dZ_c,                 /* 293: Signal */
  &bump_choice_B.product1_e,           /* 294: Signal */
  &bump_choice_B.product2_n,           /* 295: Signal */
  &bump_choice_B.product3_ho,          /* 296: Signal */
  &bump_choice_B.product4_p1,          /* 297: Signal */
  &bump_choice_B.Add1_h,               /* 298: Signal */
  &bump_choice_B.Add2_c,               /* 299: Signal */
  &bump_choice_B.Add3_f,               /* 300: Signal */
  &bump_choice_B.Add4_e,               /* 301: Signal */
  &bump_choice_B.AddX_i,               /* 302: Signal */
  &bump_choice_B.AddX1_bb,             /* 303: Signal */
  &bump_choice_B.AddX2_ec,             /* 304: Signal */
  &bump_choice_B.x_e,                  /* 305: Signal */
  &bump_choice_B.y_am,                 /* 306: Signal */
  &bump_choice_B.z_e,                  /* 307: Signal */
  &bump_choice_B.dX_l,                 /* 308: Signal */
  &bump_choice_B.dY_n,                 /* 309: Signal */
  &bump_choice_B.dZ_p,                 /* 310: Signal */
  &bump_choice_B.product1_f,           /* 311: Signal */
  &bump_choice_B.product2_f,           /* 312: Signal */
  &bump_choice_B.product3_f,           /* 313: Signal */
  &bump_choice_B.product4_et,          /* 314: Signal */
  &bump_choice_B.Add1_lc,              /* 315: Signal */
  &bump_choice_B.Add2_c5,              /* 316: Signal */
  &bump_choice_B.Add3_p,               /* 317: Signal */
  &bump_choice_B.Add4_ep,              /* 318: Signal */
  &bump_choice_B.AddX_l,               /* 319: Signal */
  &bump_choice_B.AddX1_dm,             /* 320: Signal */
  &bump_choice_B.AddX2_j,              /* 321: Signal */
  &bump_choice_B.x_et,                 /* 322: Signal */
  &bump_choice_B.y_kr,                 /* 323: Signal */
  &bump_choice_B.z_n,                  /* 324: Signal */
  &bump_choice_B.dX_h4,                /* 325: Signal */
  &bump_choice_B.dY_be,                /* 326: Signal */
  &bump_choice_B.dZ_ft,                /* 327: Signal */
  &bump_choice_B.product1_p,           /* 328: Signal */
  &bump_choice_B.product2_b,           /* 329: Signal */
  &bump_choice_B.product3_c,           /* 330: Signal */
  &bump_choice_B.product4_eg,          /* 331: Signal */
  &bump_choice_B.Add1_m,               /* 332: Signal */
  &bump_choice_B.Add2_k3,              /* 333: Signal */
  &bump_choice_B.Add3_k,               /* 334: Signal */
  &bump_choice_B.Add4_l,               /* 335: Signal */
  &bump_choice_B.AddX_c,               /* 336: Signal */
  &bump_choice_B.AddX1_c,              /* 337: Signal */
  &bump_choice_B.AddX2_c,              /* 338: Signal */
  &bump_choice_B.x_d,                  /* 339: Signal */
  &bump_choice_B.y_f,                  /* 340: Signal */
  &bump_choice_B.z_n3,                 /* 341: Signal */
  &bump_choice_B.MathFunction[0],      /* 342: Signal */
  &bump_choice_B.Compare,              /* 343: Signal */
  &bump_choice_B.EnabledSubsystem.In1, /* 344: Signal */
  &bump_choice_B.Compare_dc,           /* 345: Signal */
  &bump_choice_B.Compare_ez,           /* 346: Signal */
  &bump_choice_B.Compare_d,            /* 347: Signal */
  &bump_choice_B.Compare_dw,           /* 348: Signal */
  &bump_choice_B.Compare_h,            /* 349: Signal */
  &bump_choice_B.EnabledSubsystem_p.In1,/* 350: Signal */
  &bump_choice_B.Compare_n,            /* 351: Signal */
  &bump_choice_B.EnabledSubsystem_o.In1,/* 352: Signal */
  &bump_choice_B.Compare_l,            /* 353: Signal */
  &bump_choice_B.EnabledSubsystem_e.In1,/* 354: Signal */
  &bump_choice_B.Compare_do,           /* 355: Signal */
  &bump_choice_B.Compare_o,            /* 356: Signal */
  &bump_choice_B.FixPtRelationalOperator,/* 357: Signal */
  &bump_choice_B.Uk1,                  /* 358: Signal */
  &bump_choice_B.EnabledSubsystem_l.In1,/* 359: Signal */
  &bump_choice_B.SampleandHold.In,     /* 360: Signal */
  &bump_choice_B.ScaleTouSec,          /* 361: Signal */
  &bump_choice_B.xPCTargetTime_b,      /* 362: Signal */
  &bump_choice_B.Subtract,             /* 363: Signal */
  &bump_choice_B.Switch_n,             /* 364: Signal */
  &bump_choice_B.Compare_k,            /* 365: Signal */
  &bump_choice_B.Compare_b,            /* 366: Signal */
  &bump_choice_B.Compare_c,            /* 367: Signal */
  &bump_choice_P.Constant_Value_d,     /* 368: Block Parameter */
  &bump_choice_P.BehaviorBC_P1,        /* 369: Block Parameter */
  &bump_choice_P.BehaviorBC_P2,        /* 370: Block Parameter */
  &bump_choice_P.BehaviorBC_P3,        /* 371: Block Parameter */
  &bump_choice_P.BehaviorBC_P4,        /* 372: Block Parameter */
  &bump_choice_P.BehaviorBC_P5,        /* 373: Block Parameter */
  &bump_choice_P.BehaviorBC_P6,        /* 374: Block Parameter */
  &bump_choice_P.BehaviorBC_P7,        /* 375: Block Parameter */
  &bump_choice_P.BehaviorBC_P8,        /* 376: Block Parameter */
  &bump_choice_P.BehaviorBC_P9,        /* 377: Block Parameter */
  &bump_choice_P.BehaviorBC_P10,       /* 378: Block Parameter */
  &bump_choice_P.BehaviorBC_P11,       /* 379: Block Parameter */
  &bump_choice_P.BehaviorBC_P12,       /* 380: Block Parameter */
  &bump_choice_P.BehaviorBC_P13,       /* 381: Block Parameter */
  &bump_choice_P.XHighLimit_Value,     /* 382: Block Parameter */
  &bump_choice_P.XLowLimit_Value,      /* 383: Block Parameter */
  &bump_choice_P.YHighLimit_Value,     /* 384: Block Parameter */
  &bump_choice_P.YLowLimit_Value,      /* 385: Block Parameter */
  &bump_choice_P.DynamicAngle_Value,   /* 386: Block Parameter */
  &bump_choice_P.Load_Value_d,         /* 387: Block Parameter */
  &bump_choice_P.Off_Value,            /* 388: Block Parameter */
  &bump_choice_P.staticX_Value,        /* 389: Block Parameter */
  &bump_choice_P.staticY_Value,        /* 390: Block Parameter */
  &bump_choice_P.visAngle_Value,       /* 391: Block Parameter */
  &bump_choice_P.Gain_Gain_m,          /* 392: Block Parameter */
  &bump_choice_P.LorentzForceGain_Gain,/* 393: Block Parameter */
  &bump_choice_P.DynamicAngle_Value_f, /* 394: Block Parameter */
  &bump_choice_P.Load_Value,           /* 395: Block Parameter */
  &bump_choice_P.Off_Value_f,          /* 396: Block Parameter */
  &bump_choice_P.staticX_Value_h,      /* 397: Block Parameter */
  &bump_choice_P.staticY_Value_b,      /* 398: Block Parameter */
  &bump_choice_P.visAngle_Value_n,     /* 399: Block Parameter */
  &bump_choice_P.Gain_Gain_b,          /* 400: Block Parameter */
  &bump_choice_P.LorentzForceGain_Gain_c,/* 401: Block Parameter */
  &bump_choice_P.zeroX_Value,          /* 402: Block Parameter */
  &bump_choice_P.zeroY_Value,          /* 403: Block Parameter */
  &bump_choice_P.MG1_Gain,             /* 404: Block Parameter */
  &bump_choice_P.MG2_Gain,             /* 405: Block Parameter */
  &bump_choice_P.Memory_X0_l,          /* 406: Block Parameter */
  &bump_choice_P.PCI6025E_P1[0],       /* 407: Block Parameter */
  &bump_choice_P.PCI6025E_P2[0],       /* 408: Block Parameter */
  &bump_choice_P.PCI6025E_P3[0],       /* 409: Block Parameter */
  &bump_choice_P.PCI6025E_P4[0],       /* 410: Block Parameter */
  &bump_choice_P.PCI6025E_P5,          /* 411: Block Parameter */
  &bump_choice_P.PCI6025E_P6,          /* 412: Block Parameter */
  &bump_choice_P.PCI6025E_P7,          /* 413: Block Parameter */
  &bump_choice_P.RecenterFlag_Value,   /* 414: Block Parameter */
  &bump_choice_P.BoundingBoxViscosity_Gain,/* 415: Block Parameter */
  &bump_choice_P.JackpotChance_Value,  /* 416: Block Parameter */
  &bump_choice_P.RewardJackpot_Value,  /* 417: Block Parameter */
  &bump_choice_P.RewardTime_Value,     /* 418: Block Parameter */
  &bump_choice_P.UniformRandomNumber_Min,/* 419: Block Parameter */
  &bump_choice_P.UniformRandomNumber_Max,/* 420: Block Parameter */
  &bump_choice_P.UniformRandomNumber_Seed,/* 421: Block Parameter */
  &bump_choice_P.NaNupperbytes_Value,  /* 422: Block Parameter */
  &bump_choice_P.PacketSpec_Value,     /* 423: Block Parameter */
  &bump_choice_P.Send_P1[0],           /* 424: Block Parameter */
  &bump_choice_P.Send_P2,              /* 425: Block Parameter */
  &bump_choice_P.Send_P3,              /* 426: Block Parameter */
  &bump_choice_P.Send_P4,              /* 427: Block Parameter */
  &bump_choice_P.UseTachs_Value,       /* 428: Block Parameter */
  &bump_choice_P.TachGain1_Gain,       /* 429: Block Parameter */
  &bump_choice_P.TachGain2_Gain,       /* 430: Block Parameter */
  &bump_choice_P.PCI6025EAD_P1[0],     /* 431: Block Parameter */
  &bump_choice_P.PCI6025EAD_P2[0],     /* 432: Block Parameter */
  &bump_choice_P.PCI6025EAD_P3[0],     /* 433: Block Parameter */
  &bump_choice_P.PCI6025EAD_P4,        /* 434: Block Parameter */
  &bump_choice_P.PCI6025EAD_P5,        /* 435: Block Parameter */
  &bump_choice_P.PCI6025EAD_P6,        /* 436: Block Parameter */
  &bump_choice_P.Switch_Threshold,     /* 437: Block Parameter */
  &bump_choice_P.elbowOffset_Value,    /* 438: Block Parameter */
  &bump_choice_P.shoulderOffset_Value, /* 439: Block Parameter */
  &bump_choice_P.Gain_Gain,            /* 440: Block Parameter */
  &bump_choice_P.Gain1_Gain,           /* 441: Block Parameter */
  &bump_choice_P.PCIQUAD04_P1,         /* 442: Block Parameter */
  &bump_choice_P.PCIQUAD04_P2,         /* 443: Block Parameter */
  &bump_choice_P.PCIQUAD04_P3,         /* 444: Block Parameter */
  &bump_choice_P.PCIQUAD04_P4,         /* 445: Block Parameter */
  &bump_choice_P.PCIQUAD04_P5,         /* 446: Block Parameter */
  &bump_choice_P.PCIQUAD04_P6,         /* 447: Block Parameter */
  &bump_choice_P.PCIQUAD04_P7,         /* 448: Block Parameter */
  &bump_choice_P.PCIQUAD04_P8,         /* 449: Block Parameter */
  &bump_choice_P.PCIQUAD04_P9,         /* 450: Block Parameter */
  &bump_choice_P.PCIQUAD04_P10,        /* 451: Block Parameter */
  &bump_choice_P.PCIQUAD04_P11,        /* 452: Block Parameter */
  &bump_choice_P.PCIQUAD041_P1,        /* 453: Block Parameter */
  &bump_choice_P.PCIQUAD041_P2,        /* 454: Block Parameter */
  &bump_choice_P.PCIQUAD041_P3,        /* 455: Block Parameter */
  &bump_choice_P.PCIQUAD041_P4,        /* 456: Block Parameter */
  &bump_choice_P.PCIQUAD041_P5,        /* 457: Block Parameter */
  &bump_choice_P.PCIQUAD041_P6,        /* 458: Block Parameter */
  &bump_choice_P.PCIQUAD041_P7,        /* 459: Block Parameter */
  &bump_choice_P.PCIQUAD041_P8,        /* 460: Block Parameter */
  &bump_choice_P.PCIQUAD041_P9,        /* 461: Block Parameter */
  &bump_choice_P.PCIQUAD041_P10,       /* 462: Block Parameter */
  &bump_choice_P.PCIQUAD041_P11,       /* 463: Block Parameter */
  &bump_choice_P.Gain_Gain_ap,         /* 464: Block Parameter */
  &bump_choice_P.Inverter_Gain,        /* 465: Block Parameter */
  &bump_choice_P.Gain_Gain_by,         /* 466: Block Parameter */
  &bump_choice_P.Inverter_Gain_j,      /* 467: Block Parameter */
  &bump_choice_P.Constant_Value_j,     /* 468: Block Parameter */
  &bump_choice_P.Constant_Value_g,     /* 469: Block Parameter */
  &bump_choice_P.Gain_Gain_j,          /* 470: Block Parameter */
  &bump_choice_P.Time_Value,           /* 471: Block Parameter */
  &bump_choice_P.Memory_X0,            /* 472: Block Parameter */
  &bump_choice_P.DelayInput1_X0_o,     /* 473: Block Parameter */
  &bump_choice_P.DelayInput1_X0_m,     /* 474: Block Parameter */
  &bump_choice_P.Gain1_Gain_j,         /* 475: Block Parameter */
  &bump_choice_P.Gain2_Gain_o,         /* 476: Block Parameter */
  &bump_choice_P.Gain3_Gain,           /* 477: Block Parameter */
  &bump_choice_P.Gain4_Gain,           /* 478: Block Parameter */
  &bump_choice_P.Saturation_UpperSat,  /* 479: Block Parameter */
  &bump_choice_P.Saturation_LowerSat,  /* 480: Block Parameter */
  &bump_choice_P.Saturation1_UpperSat, /* 481: Block Parameter */
  &bump_choice_P.Saturation1_LowerSat, /* 482: Block Parameter */
  &bump_choice_P.Logic_table[0],       /* 483: Block Parameter */
  &bump_choice_P.Memory_X0_c,          /* 484: Block Parameter */
  &bump_choice_P.Time_Value_c,         /* 485: Block Parameter */
  &bump_choice_P.Memory_X0_p,          /* 486: Block Parameter */
  &bump_choice_P.Time_Value_h,         /* 487: Block Parameter */
  &bump_choice_P.Memory_X0_e,          /* 488: Block Parameter */
  &bump_choice_P.Time_Value_o,         /* 489: Block Parameter */
  &bump_choice_P.Memory_X0_k,          /* 490: Block Parameter */
  &bump_choice_P.DelayInput1_X0_n,     /* 491: Block Parameter */
  &bump_choice_P.Time_Value_p,         /* 492: Block Parameter */
  &bump_choice_P.Memory_X0_d,          /* 493: Block Parameter */
  &bump_choice_P.dG_Gain,              /* 494: Block Parameter */
  &bump_choice_P.DigitalFilter_ICRTP,  /* 495: Block Parameter */
  &bump_choice_P.DigitalFilter_RTP1COEFF[0],/* 496: Block Parameter */
  &bump_choice_P.DigitalFilter2_ICRTP, /* 497: Block Parameter */
  &bump_choice_P.DigitalFilter2_RTP1COEFF[0],/* 498: Block Parameter */
  &bump_choice_P.dG_Gain_l,            /* 499: Block Parameter */
  &bump_choice_P.DigitalFilter_ICRTP_l,/* 500: Block Parameter */
  &bump_choice_P.DigitalFilter_RTP1COEFF_a[0],/* 501: Block Parameter */
  &bump_choice_P.DigitalFilter2_ICRTP_i,/* 502: Block Parameter */
  &bump_choice_P.DigitalFilter2_RTP1COEFF_g[0],/* 503: Block Parameter */
  &bump_choice_P.AngleOffset_Value,    /* 504: Block Parameter */
  &bump_choice_P.Constant_Value_m,     /* 505: Block Parameter */
  &bump_choice_P.Constant2_Value,      /* 506: Block Parameter */
  &bump_choice_P.PortA_P1[0],          /* 507: Block Parameter */
  &bump_choice_P.PortA_P2,             /* 508: Block Parameter */
  &bump_choice_P.PortA_P3[0],          /* 509: Block Parameter */
  &bump_choice_P.PortA_P4[0],          /* 510: Block Parameter */
  &bump_choice_P.PortA_P5,             /* 511: Block Parameter */
  &bump_choice_P.PortA_P6,             /* 512: Block Parameter */
  &bump_choice_P.PortA_P7,             /* 513: Block Parameter */
  &bump_choice_P.PortA_P8,             /* 514: Block Parameter */
  &bump_choice_P.PortA_P9,             /* 515: Block Parameter */
  &bump_choice_P.PortB_P1[0],          /* 516: Block Parameter */
  &bump_choice_P.PortB_P2,             /* 517: Block Parameter */
  &bump_choice_P.PortB_P3[0],          /* 518: Block Parameter */
  &bump_choice_P.PortB_P4[0],          /* 519: Block Parameter */
  &bump_choice_P.PortB_P5,             /* 520: Block Parameter */
  &bump_choice_P.PortB_P6,             /* 521: Block Parameter */
  &bump_choice_P.PortB_P7,             /* 522: Block Parameter */
  &bump_choice_P.PortB_P8,             /* 523: Block Parameter */
  &bump_choice_P.PortB_P9,             /* 524: Block Parameter */
  &bump_choice_P.xPCTargetTime_P1_h,   /* 525: Block Parameter */
  &bump_choice_P.xPCTargetTime_P2_g,   /* 526: Block Parameter */
  &bump_choice_P.Switch_Threshold_k,   /* 527: Block Parameter */
  &bump_choice_P.L1_Value,             /* 528: Block Parameter */
  &bump_choice_P.L2_Value,             /* 529: Block Parameter */
  &bump_choice_P.xoffset_Value,        /* 530: Block Parameter */
  &bump_choice_P.yoffset_Value,        /* 531: Block Parameter */
  &bump_choice_P.Gain_Gain_a,          /* 532: Block Parameter */
  &bump_choice_P.Gain1_Gain_m,         /* 533: Block Parameter */
  &bump_choice_P.Gain2_Gain,           /* 534: Block Parameter */
  &bump_choice_P.beta_Value,           /* 535: Block Parameter */
  &bump_choice_P.rho_Value,            /* 536: Block Parameter */
  &bump_choice_P.sigma_Value,          /* 537: Block Parameter */
  &bump_choice_P.timescale_Value,      /* 538: Block Parameter */
  &bump_choice_P.x_X0_i,               /* 539: Block Parameter */
  &bump_choice_P.y_X0,                 /* 540: Block Parameter */
  &bump_choice_P.z_X0,                 /* 541: Block Parameter */
  &bump_choice_P.beta_Value_a,         /* 542: Block Parameter */
  &bump_choice_P.rho_Value_e,          /* 543: Block Parameter */
  &bump_choice_P.sigma_Value_g,        /* 544: Block Parameter */
  &bump_choice_P.timescale_Value_m,    /* 545: Block Parameter */
  &bump_choice_P.x_X0_k,               /* 546: Block Parameter */
  &bump_choice_P.y_X0_l,               /* 547: Block Parameter */
  &bump_choice_P.z_X0_b,               /* 548: Block Parameter */
  &bump_choice_P.beta_Value_l,         /* 549: Block Parameter */
  &bump_choice_P.rho_Value_eb,         /* 550: Block Parameter */
  &bump_choice_P.sigma_Value_j,        /* 551: Block Parameter */
  &bump_choice_P.timescale_Value_l,    /* 552: Block Parameter */
  &bump_choice_P.x_X0_nd,              /* 553: Block Parameter */
  &bump_choice_P.y_X0_a,               /* 554: Block Parameter */
  &bump_choice_P.z_X0_bn,              /* 555: Block Parameter */
  &bump_choice_P.beta_Value_c,         /* 556: Block Parameter */
  &bump_choice_P.rho_Value_n,          /* 557: Block Parameter */
  &bump_choice_P.sigma_Value_jm,       /* 558: Block Parameter */
  &bump_choice_P.timescale_Value_f,    /* 559: Block Parameter */
  &bump_choice_P.x_X0_a,               /* 560: Block Parameter */
  &bump_choice_P.y_X0_k,               /* 561: Block Parameter */
  &bump_choice_P.z_X0_i,               /* 562: Block Parameter */
  &bump_choice_P.beta_Value_b,         /* 563: Block Parameter */
  &bump_choice_P.rho_Value_f,          /* 564: Block Parameter */
  &bump_choice_P.sigma_Value_m,        /* 565: Block Parameter */
  &bump_choice_P.timescale_Value_mg,   /* 566: Block Parameter */
  &bump_choice_P.x_X0,                 /* 567: Block Parameter */
  &bump_choice_P.y_X0_i,               /* 568: Block Parameter */
  &bump_choice_P.z_X0_n,               /* 569: Block Parameter */
  &bump_choice_P.beta_Value_m,         /* 570: Block Parameter */
  &bump_choice_P.rho_Value_b,          /* 571: Block Parameter */
  &bump_choice_P.sigma_Value_j0,       /* 572: Block Parameter */
  &bump_choice_P.timescale_Value_e,    /* 573: Block Parameter */
  &bump_choice_P.x_X0_p,               /* 574: Block Parameter */
  &bump_choice_P.y_X0_m,               /* 575: Block Parameter */
  &bump_choice_P.z_X0_a,               /* 576: Block Parameter */
  &bump_choice_P.beta_Value_n,         /* 577: Block Parameter */
  &bump_choice_P.rho_Value_h,          /* 578: Block Parameter */
  &bump_choice_P.sigma_Value_c,        /* 579: Block Parameter */
  &bump_choice_P.timescale_Value_d,    /* 580: Block Parameter */
  &bump_choice_P.x_X0_n,               /* 581: Block Parameter */
  &bump_choice_P.y_X0_p,               /* 582: Block Parameter */
  &bump_choice_P.z_X0_i4,              /* 583: Block Parameter */
  &bump_choice_P.beta_Value_g,         /* 584: Block Parameter */
  &bump_choice_P.rho_Value_a,          /* 585: Block Parameter */
  &bump_choice_P.sigma_Value_l,        /* 586: Block Parameter */
  &bump_choice_P.timescale_Value_j,    /* 587: Block Parameter */
  &bump_choice_P.x_X0_pt,              /* 588: Block Parameter */
  &bump_choice_P.y_X0_c,               /* 589: Block Parameter */
  &bump_choice_P.z_X0_f,               /* 590: Block Parameter */
  &bump_choice_P.Constant_Value,       /* 591: Block Parameter */
  &bump_choice_P.Constant_Value_o,     /* 592: Block Parameter */
  &bump_choice_P.DelayInput1_X0,       /* 593: Block Parameter */
  &bump_choice_P.Constant_Value_h,     /* 594: Block Parameter */
  &bump_choice_P.Constant1_Value,      /* 595: Block Parameter */
  &bump_choice_P.ScaleTouSec_Gain,     /* 596: Block Parameter */
  &bump_choice_P.PCI6025E_P1_d[0],     /* 597: Block Parameter */
  &bump_choice_P.PCI6025E_P2_k[0],     /* 598: Block Parameter */
  &bump_choice_P.PCI6025E_P3_l[0],     /* 599: Block Parameter */
  &bump_choice_P.PCI6025E_P4_o,        /* 600: Block Parameter */
  &bump_choice_P.PCI6025E_P5_m,        /* 601: Block Parameter */
  &bump_choice_P.PCI6025E_P6_f,        /* 602: Block Parameter */
  &bump_choice_P.PCI6025E_P7_f,        /* 603: Block Parameter */
  &bump_choice_P.xPCTargetTime_P1,     /* 604: Block Parameter */
  &bump_choice_P.xPCTargetTime_P2,     /* 605: Block Parameter */
  &bump_choice_P.Constant_Value_jz,    /* 606: Block Parameter */
  &bump_choice_P.Constant_Value_b      /* 607: Block Parameter */
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
  15,                                  /* 8 */
  1,                                   /* 9 */
  168,                                 /* 10 */
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
  { rtBlockSignals, 368 },

  { rtBlockParameters, 240,
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
