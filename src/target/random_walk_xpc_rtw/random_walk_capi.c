/*
 * random_walk_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "random_walk.mdl".
 *
 * Model Version              : 1.1211
 * Real-Time Workshop version : 6.6.1  (R2007a+)  13-Mar-2007
 * C source code generated on : Thu Jan 21 16:44:40 2010
 */

#include "random_walk.h"
#include "rtw_capi.h"
#include "random_walk_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Matrix Concatenation1",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Behavior RW/p1",
    "", 0, 0, 1, 0, 0 },

  { 2, 0, "Behavior RW/p2",
    "", 1, 0, 2, 0, 0 },

  { 3, 0, "Behavior RW/p3",
    "", 2, 0, 3, 0, 0 },

  { 4, 0, "Behavior RW/p4",
    "", 3, 0, 4, 0, 0 },

  { 5, 0, "Behavior RW/p5",
    "", 4, 0, 3, 0, 0 },

  { 6, 0, "Behavior RW/p6",
    "", 5, 0, 1, 0, 0 },

  { 7, 0, "Behavior RW/p7",
    "", 6, 0, 0, 0, 0 },

  { 8, 0, "Behavior RW/p8",
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
  { 372, "Behavior RW",
    "P1", 0, 3, 0 },

  { 373, "Behavior RW",
    "P2", 0, 3, 0 },

  { 374, "Behavior RW",
    "P3", 0, 3, 0 },

  { 375, "Behavior RW",
    "P4", 0, 3, 0 },

  { 376, "Behavior RW",
    "P5", 0, 3, 0 },

  { 377, "Behavior RW",
    "P6", 0, 3, 0 },

  { 378, "Behavior RW",
    "P7", 0, 3, 0 },

  { 379, "Behavior RW",
    "P8", 0, 3, 0 },

  { 380, "Behavior RW",
    "P9", 0, 3, 0 },

  { 381, "Behavior RW",
    "P10", 0, 3, 0 },

  { 382, "Behavior RW",
    "P11", 0, 3, 0 },

  { 383, "Behavior RW",
    "P12", 0, 3, 0 },

  { 384, "Behavior RW",
    "P13", 0, 3, 0 },

  { 385, "Behavior RW",
    "P14", 0, 3, 0 },

  { 386, "Behavior RW",
    "P15", 0, 3, 0 },

  { 387, "Behavior RW",
    "P16", 0, 3, 0 },

  { 388, "Behavior RW",
    "P17", 0, 3, 0 },

  { 389, "Behavior RW",
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
  &random_walk_B.MatrixConcatenation1[0],/* 0: Signal */
  &random_walk_B.BehaviorRW_o1[0],     /* 1: Signal */
  &random_walk_B.BehaviorRW_o2[0],     /* 2: Signal */
  &random_walk_B.BehaviorRW_o3,        /* 3: Signal */
  &random_walk_B.BehaviorRW_o4[0],     /* 4: Signal */
  &random_walk_B.BehaviorRW_o5,        /* 5: Signal */
  &random_walk_B.BehaviorRW_o6[0],     /* 6: Signal */
  &random_walk_B.BehaviorRW_o7[0],     /* 7: Signal */
  &random_walk_B.BehaviorRW_o8[0],     /* 8: Signal */
  &random_walk_B.LogicalOperator_a,    /* 9: Signal */
  &random_walk_B.RelationalOperator_n, /* 10: Signal */
  &random_walk_B.RelationalOperator1,  /* 11: Signal */
  &random_walk_B.RelationalOperator2,  /* 12: Signal */
  &random_walk_B.RelationalOperator3,  /* 13: Signal */
  &random_walk_B.Gain_b,               /* 14: Signal */
  &random_walk_B.LorentzForceGain_j[0],/* 15: Signal */
  &random_walk_B.DynamicAngleSwitch,   /* 16: Signal */
  &random_walk_B.LoadSelectSwitch[0],  /* 17: Signal */
  &random_walk_B.Gain_d,               /* 18: Signal */
  &random_walk_B.LorentzForceGain[0],  /* 19: Signal */
  &random_walk_B.MultiportSwitch[0],   /* 20: Signal */
  &random_walk_B.dynamicAngleSwitch,   /* 21: Signal */
  &random_walk_B.MatrixConcatenation[0],/* 22: Signal */
  &random_walk_B.MG1,                  /* 23: Signal */
  &random_walk_B.MG2,                  /* 24: Signal */
  &random_walk_B.LogicalOperator1_b,   /* 25: Signal */
  &random_walk_B.Memory_e,             /* 26: Signal */
  &random_walk_B.Switch1[0],           /* 27: Signal */
  &random_walk_B.Switch2[0],           /* 28: Signal */
  &random_walk_B.DataTypeConversion1,  /* 29: Signal */
  &random_walk_B.DataTypeConversion2,  /* 30: Signal */
  &random_walk_B.BoundingBoxViscosity[0],/* 31: Signal */
  &random_walk_B.InBox,                /* 32: Signal */
  &random_walk_B.LogicalOperator_i,    /* 33: Signal */
  &random_walk_B.LogicalOperator1_a,   /* 34: Signal */
  &random_walk_B.LogicalOperator3_d,   /* 35: Signal */
  &random_walk_B.LogicalOperator5_h,   /* 36: Signal */
  &random_walk_B.LogicalOperator6,     /* 37: Signal */
  &random_walk_B.NOT,                  /* 38: Signal */
  &random_walk_B.Switch_c[0],          /* 39: Signal */
  &random_walk_B.DataTypeConversion,   /* 40: Signal */
  &random_walk_B.RelationalOperator_e, /* 41: Signal */
  &random_walk_B.Switch_l,             /* 42: Signal */
  &random_walk_B.UniformRandomNumber,  /* 43: Signal */
  &random_walk_B.Gain_p,               /* 44: Signal */
  &random_walk_B.Gain1_c,              /* 45: Signal */
  &random_walk_B.Add_oe,               /* 46: Signal */
  &random_walk_B.Add1_f,               /* 47: Signal */
  &random_walk_B.RateTransition[0],    /* 48: Signal */
  &random_walk_B.Pack[0],              /* 49: Signal */
  &random_walk_B.TachGain1,            /* 50: Signal */
  &random_walk_B.TachGain2,            /* 51: Signal */
  &random_walk_B.MatrixMultiply[0],    /* 52: Signal */
  &random_walk_B.PCI6025EAD_o1,        /* 53: Signal */
  &random_walk_B.PCI6025EAD_o2,        /* 54: Signal */
  &random_walk_B.Switch[0],            /* 55: Signal */
  &random_walk_B.Gain,                 /* 56: Signal */
  &random_walk_B.Gain1,                /* 57: Signal */
  &random_walk_B.PCIQUAD04,            /* 58: Signal */
  &random_walk_B.PCIQUAD041,           /* 59: Signal */
  &random_walk_B.Sum1,                 /* 60: Signal */
  &random_walk_B.Sum3,                 /* 61: Signal */
  &random_walk_B.Add_o,                /* 62: Signal */
  &random_walk_B.Add1_b1,              /* 63: Signal */
  &random_walk_B.Gain_a[0],            /* 64: Signal */
  &random_walk_B.Inverter_a[0],        /* 65: Signal */
  &random_walk_B.Product_d,            /* 66: Signal */
  &random_walk_B.Product1_jf,          /* 67: Signal */
  &random_walk_B.Product2_j,           /* 68: Signal */
  &random_walk_B.Product3_g,           /* 69: Signal */
  &random_walk_B.Add_p,                /* 70: Signal */
  &random_walk_B.Subtract_g,           /* 71: Signal */
  &random_walk_B.cos_j,                /* 72: Signal */
  &random_walk_B.sin_l,                /* 73: Signal */
  &random_walk_B.Add,                  /* 74: Signal */
  &random_walk_B.Add1_a,               /* 75: Signal */
  &random_walk_B.Gain_n[0],            /* 76: Signal */
  &random_walk_B.Inverter[0],          /* 77: Signal */
  &random_walk_B.Product_e,            /* 78: Signal */
  &random_walk_B.Product1_f,           /* 79: Signal */
  &random_walk_B.Product2_m,           /* 80: Signal */
  &random_walk_B.Product3_m,           /* 81: Signal */
  &random_walk_B.Add_ci,               /* 82: Signal */
  &random_walk_B.Subtract_j,           /* 83: Signal */
  &random_walk_B.cos_o,                /* 84: Signal */
  &random_walk_B.sin_e,                /* 85: Signal */
  &random_walk_B.Compare_a,            /* 86: Signal */
  &random_walk_B.Compare_h2,           /* 87: Signal */
  &random_walk_B.Gain_o[0],            /* 88: Signal */
  &random_walk_B.MatrixMultiply_k[0],  /* 89: Signal */
  &random_walk_B.Clock,                /* 90: Signal */
  &random_walk_B.LogicalOperator,      /* 91: Signal */
  &random_walk_B.LogicalOperator1,     /* 92: Signal */
  &random_walk_B.LogicalOperator2,     /* 93: Signal */
  &random_walk_B.Memory,               /* 94: Signal */
  &random_walk_B.RelationalOperator,   /* 95: Signal */
  &random_walk_B.Sum,                  /* 96: Signal */
  &random_walk_B.Compare_j,            /* 97: Signal */
  &random_walk_B.Compare_m,            /* 98: Signal */
  &random_walk_B.FixPtRelationalOperator_b,/* 99: Signal */
  &random_walk_B.Uk1_i,                /* 100: Signal */
  &random_walk_B.FixPtRelationalOperator_d,/* 101: Signal */
  &random_walk_B.Uk1_n,                /* 102: Signal */
  &random_walk_B.Abs2,                 /* 103: Signal */
  &random_walk_B.Abs3,                 /* 104: Signal */
  &random_walk_B.LogicalOperator1_d,   /* 105: Signal */
  &random_walk_B.Gain1_n,              /* 106: Signal */
  &random_walk_B.Gain2,                /* 107: Signal */
  &random_walk_B.Gain3,                /* 108: Signal */
  &random_walk_B.Gain4,                /* 109: Signal */
  &random_walk_B.Product_n,            /* 110: Signal */
  &random_walk_B.Product1_j,           /* 111: Signal */
  &random_walk_B.Saturation,           /* 112: Signal */
  &random_walk_B.Saturation1,          /* 113: Signal */
  &random_walk_B.Add_c,                /* 114: Signal */
  &random_walk_B.Add1_d,               /* 115: Signal */
  &random_walk_B.Logic[0],             /* 116: Signal */
  &random_walk_B.Memory_jh,            /* 117: Signal */
  &random_walk_B.Clock_m,              /* 118: Signal */
  &random_walk_B.LogicalOperator_if,   /* 119: Signal */
  &random_walk_B.LogicalOperator1_p,   /* 120: Signal */
  &random_walk_B.LogicalOperator2_o,   /* 121: Signal */
  &random_walk_B.Memory_i,             /* 122: Signal */
  &random_walk_B.RelationalOperator_c, /* 123: Signal */
  &random_walk_B.Sum_hd,               /* 124: Signal */
  &random_walk_B.Clock_n,              /* 125: Signal */
  &random_walk_B.LogicalOperator_e,    /* 126: Signal */
  &random_walk_B.LogicalOperator1_pq,  /* 127: Signal */
  &random_walk_B.LogicalOperator2_mi,  /* 128: Signal */
  &random_walk_B.Memory_j,             /* 129: Signal */
  &random_walk_B.RelationalOperator_l, /* 130: Signal */
  &random_walk_B.Sum_ms,               /* 131: Signal */
  &random_walk_B.Clock_e,              /* 132: Signal */
  &random_walk_B.LogicalOperator_b,    /* 133: Signal */
  &random_walk_B.LogicalOperator1_i,   /* 134: Signal */
  &random_walk_B.LogicalOperator2_j,   /* 135: Signal */
  &random_walk_B.Memory_o,             /* 136: Signal */
  &random_walk_B.RelationalOperator_pq,/* 137: Signal */
  &random_walk_B.Sum_o,                /* 138: Signal */
  &random_walk_B.FixPtRelationalOperator_m,/* 139: Signal */
  &random_walk_B.Uk1_j,                /* 140: Signal */
  &random_walk_B.Clock_i,              /* 141: Signal */
  &random_walk_B.LogicalOperator_ai,   /* 142: Signal */
  &random_walk_B.LogicalOperator1_f,   /* 143: Signal */
  &random_walk_B.LogicalOperator2_m,   /* 144: Signal */
  &random_walk_B.LogicalOperator3,     /* 145: Signal */
  &random_walk_B.LogicalOperator4,     /* 146: Signal */
  &random_walk_B.LogicalOperator5,     /* 147: Signal */
  &random_walk_B.Memory_e5,            /* 148: Signal */
  &random_walk_B.RelationalOperator_p, /* 149: Signal */
  &random_walk_B.Sum_m,                /* 150: Signal */
  &random_walk_B.SampleandHold_g.In,   /* 151: Signal */
  &random_walk_B.Clock_k,              /* 152: Signal */
  &random_walk_B.RelationalOperator_o, /* 153: Signal */
  &random_walk_B.Sum_l,                /* 154: Signal */
  &random_walk_B.Derivative,           /* 155: Signal */
  &random_walk_B.dG,                   /* 156: Signal */
  &random_walk_B.DigitalFilter,        /* 157: Signal */
  &random_walk_B.DigitalFilter2,       /* 158: Signal */
  &random_walk_B.Derivative_d,         /* 159: Signal */
  &random_walk_B.dG_d,                 /* 160: Signal */
  &random_walk_B.DigitalFilter_c,      /* 161: Signal */
  &random_walk_B.DigitalFilter2_k,     /* 162: Signal */
  &random_walk_B.sqrtu1u1u2u2,         /* 163: Signal */
  &random_walk_B.Product_l,            /* 164: Signal */
  &random_walk_B.Product1_m,           /* 165: Signal */
  &random_walk_B.Sum_h,                /* 166: Signal */
  &random_walk_B.TrigonometricFunction_g,/* 167: Signal */
  &random_walk_B.TrigonometricFunction1_p,/* 168: Signal */
  &random_walk_B.TrigonometricFunction2_i,/* 169: Signal */
  &random_walk_B.ForIterator,          /* 170: Signal */
  &random_walk_B.SerialConverter,      /* 171: Signal */
  &random_walk_B.ToBits_o1,            /* 172: Signal */
  &random_walk_B.ToBits_o2,            /* 173: Signal */
  &random_walk_B.ToBits_o3,            /* 174: Signal */
  &random_walk_B.ToBits_o4,            /* 175: Signal */
  &random_walk_B.ToBits_o5,            /* 176: Signal */
  &random_walk_B.ToBits_o6,            /* 177: Signal */
  &random_walk_B.ToBits_o7,            /* 178: Signal */
  &random_walk_B.ToBits_o8,            /* 179: Signal */
  &random_walk_B.ToBits1_o1,           /* 180: Signal */
  &random_walk_B.ToBits1_o2,           /* 181: Signal */
  &random_walk_B.ToBits1_o3,           /* 182: Signal */
  &random_walk_B.ToBits1_o4,           /* 183: Signal */
  &random_walk_B.ToBits1_o5,           /* 184: Signal */
  &random_walk_B.ToBits1_o6,           /* 185: Signal */
  &random_walk_B.ToBits1_o7,           /* 186: Signal */
  &random_walk_B.ToBits1_o8,           /* 187: Signal */
  &random_walk_B.xPCTargetTime,        /* 188: Signal */
  &random_walk_B.Add_j,                /* 189: Signal */
  &random_walk_B.Add1_oz,              /* 190: Signal */
  &random_walk_B.Switch_j,             /* 191: Signal */
  &random_walk_B.MatrixConcatenate2[0],/* 192: Signal */
  &random_walk_B.MatrixConcatenate2[0],/* 193: Signal */
  &random_walk_B.MatrixConcatenate2[0],/* 194: Signal */
  &random_walk_B.MatrixConcatenate2[0],/* 195: Signal */
  &random_walk_B.MatrixConcatenate2[0],/* 196: Signal */
  &random_walk_B.MatrixConcatenate2[0],/* 197: Signal */
  &random_walk_B.Product,              /* 198: Signal */
  &random_walk_B.Product1,             /* 199: Signal */
  &random_walk_B.Product2,             /* 200: Signal */
  &random_walk_B.Product3,             /* 201: Signal */
  &random_walk_B.Sum1_g,               /* 202: Signal */
  &random_walk_B.Sum2,                 /* 203: Signal */
  &random_walk_B.Sum3_i,               /* 204: Signal */
  &random_walk_B.Sum4,                 /* 205: Signal */
  &random_walk_B.TrigonometricFunction,/* 206: Signal */
  &random_walk_B.TrigonometricFunction1,/* 207: Signal */
  &random_walk_B.TrigonometricFunction2,/* 208: Signal */
  &random_walk_B.TrigonometricFunction3,/* 209: Signal */
  &random_walk_B.dX,                   /* 210: Signal */
  &random_walk_B.dY,                   /* 211: Signal */
  &random_walk_B.dZ,                   /* 212: Signal */
  &random_walk_B.product1,             /* 213: Signal */
  &random_walk_B.product2,             /* 214: Signal */
  &random_walk_B.product3,             /* 215: Signal */
  &random_walk_B.product4,             /* 216: Signal */
  &random_walk_B.Add1,                 /* 217: Signal */
  &random_walk_B.Add2,                 /* 218: Signal */
  &random_walk_B.Add3,                 /* 219: Signal */
  &random_walk_B.Add4,                 /* 220: Signal */
  &random_walk_B.AddX,                 /* 221: Signal */
  &random_walk_B.AddX1,                /* 222: Signal */
  &random_walk_B.AddX2,                /* 223: Signal */
  &random_walk_B.x_k,                  /* 224: Signal */
  &random_walk_B.y,                    /* 225: Signal */
  &random_walk_B.z,                    /* 226: Signal */
  &random_walk_B.dX_o,                 /* 227: Signal */
  &random_walk_B.dY_g,                 /* 228: Signal */
  &random_walk_B.dZ_o,                 /* 229: Signal */
  &random_walk_B.product1_i,           /* 230: Signal */
  &random_walk_B.product2_p,           /* 231: Signal */
  &random_walk_B.product3_c,           /* 232: Signal */
  &random_walk_B.product4_j,           /* 233: Signal */
  &random_walk_B.Add1_m,               /* 234: Signal */
  &random_walk_B.Add2_e,               /* 235: Signal */
  &random_walk_B.Add3_h,               /* 236: Signal */
  &random_walk_B.Add4_e,               /* 237: Signal */
  &random_walk_B.AddX_o,               /* 238: Signal */
  &random_walk_B.AddX1_l,              /* 239: Signal */
  &random_walk_B.AddX2_l,              /* 240: Signal */
  &random_walk_B.x_m,                  /* 241: Signal */
  &random_walk_B.y_m,                  /* 242: Signal */
  &random_walk_B.z_e,                  /* 243: Signal */
  &random_walk_B.dX_p,                 /* 244: Signal */
  &random_walk_B.dY_a,                 /* 245: Signal */
  &random_walk_B.dZ_m,                 /* 246: Signal */
  &random_walk_B.product1_a,           /* 247: Signal */
  &random_walk_B.product2_e,           /* 248: Signal */
  &random_walk_B.product3_o,           /* 249: Signal */
  &random_walk_B.product4_o,           /* 250: Signal */
  &random_walk_B.Add1_mk,              /* 251: Signal */
  &random_walk_B.Add2_k,               /* 252: Signal */
  &random_walk_B.Add3_c,               /* 253: Signal */
  &random_walk_B.Add4_el,              /* 254: Signal */
  &random_walk_B.AddX_d,               /* 255: Signal */
  &random_walk_B.AddX1_p,              /* 256: Signal */
  &random_walk_B.AddX2_b,              /* 257: Signal */
  &random_walk_B.x_o,                  /* 258: Signal */
  &random_walk_B.y_f,                  /* 259: Signal */
  &random_walk_B.z_g,                  /* 260: Signal */
  &random_walk_B.dX_b,                 /* 261: Signal */
  &random_walk_B.dY_n,                 /* 262: Signal */
  &random_walk_B.dZ_n,                 /* 263: Signal */
  &random_walk_B.product1_g,           /* 264: Signal */
  &random_walk_B.product2_d,           /* 265: Signal */
  &random_walk_B.product3_i,           /* 266: Signal */
  &random_walk_B.product4_i,           /* 267: Signal */
  &random_walk_B.Add1_c,               /* 268: Signal */
  &random_walk_B.Add2_g,               /* 269: Signal */
  &random_walk_B.Add3_hn,              /* 270: Signal */
  &random_walk_B.Add4_o,               /* 271: Signal */
  &random_walk_B.AddX_b,               /* 272: Signal */
  &random_walk_B.AddX1_lw,             /* 273: Signal */
  &random_walk_B.AddX2_a,              /* 274: Signal */
  &random_walk_B.x_mw,                 /* 275: Signal */
  &random_walk_B.y_k,                  /* 276: Signal */
  &random_walk_B.z_m,                  /* 277: Signal */
  &random_walk_B.dX_l,                 /* 278: Signal */
  &random_walk_B.dY_o,                 /* 279: Signal */
  &random_walk_B.dZ_j,                 /* 280: Signal */
  &random_walk_B.product1_e,           /* 281: Signal */
  &random_walk_B.product2_c,           /* 282: Signal */
  &random_walk_B.product3_m,           /* 283: Signal */
  &random_walk_B.product4_p,           /* 284: Signal */
  &random_walk_B.Add1_o,               /* 285: Signal */
  &random_walk_B.Add2_c,               /* 286: Signal */
  &random_walk_B.Add3_j,               /* 287: Signal */
  &random_walk_B.Add4_b,               /* 288: Signal */
  &random_walk_B.AddX_f,               /* 289: Signal */
  &random_walk_B.AddX1_o,              /* 290: Signal */
  &random_walk_B.AddX2_f,              /* 291: Signal */
  &random_walk_B.x,                    /* 292: Signal */
  &random_walk_B.y_g,                  /* 293: Signal */
  &random_walk_B.z_l,                  /* 294: Signal */
  &random_walk_B.dX_m,                 /* 295: Signal */
  &random_walk_B.dY_f,                 /* 296: Signal */
  &random_walk_B.dZ_g,                 /* 297: Signal */
  &random_walk_B.product1_f,           /* 298: Signal */
  &random_walk_B.product2_l,           /* 299: Signal */
  &random_walk_B.product3_b,           /* 300: Signal */
  &random_walk_B.product4_d,           /* 301: Signal */
  &random_walk_B.Add1_b,               /* 302: Signal */
  &random_walk_B.Add2_b,               /* 303: Signal */
  &random_walk_B.Add3_e,               /* 304: Signal */
  &random_walk_B.Add4_bs,              /* 305: Signal */
  &random_walk_B.AddX_j,               /* 306: Signal */
  &random_walk_B.AddX1_b,              /* 307: Signal */
  &random_walk_B.AddX2_e,              /* 308: Signal */
  &random_walk_B.x_f,                  /* 309: Signal */
  &random_walk_B.y_e,                  /* 310: Signal */
  &random_walk_B.z_o,                  /* 311: Signal */
  &random_walk_B.dX_f,                 /* 312: Signal */
  &random_walk_B.dY_b,                 /* 313: Signal */
  &random_walk_B.dZ_f,                 /* 314: Signal */
  &random_walk_B.product1_ae,          /* 315: Signal */
  &random_walk_B.product2_g,           /* 316: Signal */
  &random_walk_B.product3_d,           /* 317: Signal */
  &random_walk_B.product4_j1,          /* 318: Signal */
  &random_walk_B.Add1_l,               /* 319: Signal */
  &random_walk_B.Add2_l,               /* 320: Signal */
  &random_walk_B.Add3_p,               /* 321: Signal */
  &random_walk_B.Add4_k,               /* 322: Signal */
  &random_walk_B.AddX_on,              /* 323: Signal */
  &random_walk_B.AddX1_j,              /* 324: Signal */
  &random_walk_B.AddX2_h,              /* 325: Signal */
  &random_walk_B.x_h,                  /* 326: Signal */
  &random_walk_B.y_j,                  /* 327: Signal */
  &random_walk_B.z_n,                  /* 328: Signal */
  &random_walk_B.dX_bi,                /* 329: Signal */
  &random_walk_B.dY_na,                /* 330: Signal */
  &random_walk_B.dZ_i,                 /* 331: Signal */
  &random_walk_B.product1_o,           /* 332: Signal */
  &random_walk_B.product2_cg,          /* 333: Signal */
  &random_walk_B.product3_im,          /* 334: Signal */
  &random_walk_B.product4_p0,          /* 335: Signal */
  &random_walk_B.Add1_n,               /* 336: Signal */
  &random_walk_B.Add2_d,               /* 337: Signal */
  &random_walk_B.Add3_a,               /* 338: Signal */
  &random_walk_B.Add4_h,               /* 339: Signal */
  &random_walk_B.AddX_jl,              /* 340: Signal */
  &random_walk_B.AddX1_bw,             /* 341: Signal */
  &random_walk_B.AddX2_g,              /* 342: Signal */
  &random_walk_B.x_l,                  /* 343: Signal */
  &random_walk_B.y_o,                  /* 344: Signal */
  &random_walk_B.z_j,                  /* 345: Signal */
  &random_walk_B.MathFunction[0],      /* 346: Signal */
  &random_walk_B.Compare,              /* 347: Signal */
  &random_walk_B.EnabledSubsystem.In1, /* 348: Signal */
  &random_walk_B.Compare_my,           /* 349: Signal */
  &random_walk_B.Compare_n,            /* 350: Signal */
  &random_walk_B.Compare_o,            /* 351: Signal */
  &random_walk_B.Compare_d,            /* 352: Signal */
  &random_walk_B.Compare_l,            /* 353: Signal */
  &random_walk_B.EnabledSubsystem_d.In1,/* 354: Signal */
  &random_walk_B.Compare_f,            /* 355: Signal */
  &random_walk_B.EnabledSubsystem_n.In1,/* 356: Signal */
  &random_walk_B.Compare_d1,           /* 357: Signal */
  &random_walk_B.EnabledSubsystem_o.In1,/* 358: Signal */
  &random_walk_B.Compare_g,            /* 359: Signal */
  &random_walk_B.Compare_j0,           /* 360: Signal */
  &random_walk_B.FixPtRelationalOperator,/* 361: Signal */
  &random_walk_B.Uk1,                  /* 362: Signal */
  &random_walk_B.EnabledSubsystem_l.In1,/* 363: Signal */
  &random_walk_B.SampleandHold.In,     /* 364: Signal */
  &random_walk_B.ScaleTouSec,          /* 365: Signal */
  &random_walk_B.xPCTargetTime_a,      /* 366: Signal */
  &random_walk_B.Subtract,             /* 367: Signal */
  &random_walk_B.Switch_g,             /* 368: Signal */
  &random_walk_B.Compare_h,            /* 369: Signal */
  &random_walk_B.Compare_h0,           /* 370: Signal */
  &random_walk_B.Compare_nw,           /* 371: Signal */
  &random_walk_P.BehaviorRW_P1,        /* 372: Block Parameter */
  &random_walk_P.BehaviorRW_P2,        /* 373: Block Parameter */
  &random_walk_P.BehaviorRW_P3,        /* 374: Block Parameter */
  &random_walk_P.BehaviorRW_P4,        /* 375: Block Parameter */
  &random_walk_P.BehaviorRW_P5,        /* 376: Block Parameter */
  &random_walk_P.BehaviorRW_P6,        /* 377: Block Parameter */
  &random_walk_P.BehaviorRW_P7,        /* 378: Block Parameter */
  &random_walk_P.BehaviorRW_P8,        /* 379: Block Parameter */
  &random_walk_P.BehaviorRW_P9,        /* 380: Block Parameter */
  &random_walk_P.BehaviorRW_P10,       /* 381: Block Parameter */
  &random_walk_P.BehaviorRW_P11,       /* 382: Block Parameter */
  &random_walk_P.BehaviorRW_P12,       /* 383: Block Parameter */
  &random_walk_P.BehaviorRW_P13,       /* 384: Block Parameter */
  &random_walk_P.BehaviorRW_P14,       /* 385: Block Parameter */
  &random_walk_P.BehaviorRW_P15,       /* 386: Block Parameter */
  &random_walk_P.BehaviorRW_P16,       /* 387: Block Parameter */
  &random_walk_P.BehaviorRW_P17,       /* 388: Block Parameter */
  &random_walk_P.BehaviorRW_P18,       /* 389: Block Parameter */
  &random_walk_P.XHighLimit_Value,     /* 390: Block Parameter */
  &random_walk_P.XLowLimit_Value,      /* 391: Block Parameter */
  &random_walk_P.YHighLimit_Value,     /* 392: Block Parameter */
  &random_walk_P.YLowLimit_Value,      /* 393: Block Parameter */
  &random_walk_P.DynamicAngle_Value,   /* 394: Block Parameter */
  &random_walk_P.Load_Value_a,         /* 395: Block Parameter */
  &random_walk_P.Off_Value,            /* 396: Block Parameter */
  &random_walk_P.staticX_Value,        /* 397: Block Parameter */
  &random_walk_P.staticY_Value,        /* 398: Block Parameter */
  &random_walk_P.visAngle_Value,       /* 399: Block Parameter */
  &random_walk_P.Gain_Gain_o,          /* 400: Block Parameter */
  &random_walk_P.LorentzForceGain_Gain,/* 401: Block Parameter */
  &random_walk_P.DynamicAngle_Value_h, /* 402: Block Parameter */
  &random_walk_P.Load_Value,           /* 403: Block Parameter */
  &random_walk_P.Off_Value_d,          /* 404: Block Parameter */
  &random_walk_P.staticX_Value_e,      /* 405: Block Parameter */
  &random_walk_P.staticY_Value_a,      /* 406: Block Parameter */
  &random_walk_P.visAngle_Value_n,     /* 407: Block Parameter */
  &random_walk_P.Gain_Gain_p,          /* 408: Block Parameter */
  &random_walk_P.LorentzForceGain_Gain_j,/* 409: Block Parameter */
  &random_walk_P.zeroX_Value,          /* 410: Block Parameter */
  &random_walk_P.zeroY_Value,          /* 411: Block Parameter */
  &random_walk_P.MG1_Gain,             /* 412: Block Parameter */
  &random_walk_P.MG2_Gain,             /* 413: Block Parameter */
  &random_walk_P.Memory_X0_e,          /* 414: Block Parameter */
  &random_walk_P.PCI6025E_P1[0],       /* 415: Block Parameter */
  &random_walk_P.PCI6025E_P2[0],       /* 416: Block Parameter */
  &random_walk_P.PCI6025E_P3[0],       /* 417: Block Parameter */
  &random_walk_P.PCI6025E_P4[0],       /* 418: Block Parameter */
  &random_walk_P.PCI6025E_P5,          /* 419: Block Parameter */
  &random_walk_P.PCI6025E_P6,          /* 420: Block Parameter */
  &random_walk_P.PCI6025E_P7,          /* 421: Block Parameter */
  &random_walk_P.RecenterFlag_Value,   /* 422: Block Parameter */
  &random_walk_P.BoundingBoxViscosity_Gain,/* 423: Block Parameter */
  &random_walk_P.JackpotChance_Value,  /* 424: Block Parameter */
  &random_walk_P.RewardJackpot_Value,  /* 425: Block Parameter */
  &random_walk_P.RewardTime_Value,     /* 426: Block Parameter */
  &random_walk_P.UniformRandomNumber_Min,/* 427: Block Parameter */
  &random_walk_P.UniformRandomNumber_Max,/* 428: Block Parameter */
  &random_walk_P.UniformRandomNumber_Seed,/* 429: Block Parameter */
  &random_walk_P.Gain_Gain_g,          /* 430: Block Parameter */
  &random_walk_P.Gain1_Gain_d,         /* 431: Block Parameter */
  &random_walk_P.Send_P1[0],           /* 432: Block Parameter */
  &random_walk_P.Send_P2,              /* 433: Block Parameter */
  &random_walk_P.Send_P3,              /* 434: Block Parameter */
  &random_walk_P.Send_P4,              /* 435: Block Parameter */
  &random_walk_P.UseTachs_Value,       /* 436: Block Parameter */
  &random_walk_P.TachGain1_Gain,       /* 437: Block Parameter */
  &random_walk_P.TachGain2_Gain,       /* 438: Block Parameter */
  &random_walk_P.PCI6025EAD_P1[0],     /* 439: Block Parameter */
  &random_walk_P.PCI6025EAD_P2[0],     /* 440: Block Parameter */
  &random_walk_P.PCI6025EAD_P3[0],     /* 441: Block Parameter */
  &random_walk_P.PCI6025EAD_P4,        /* 442: Block Parameter */
  &random_walk_P.PCI6025EAD_P5,        /* 443: Block Parameter */
  &random_walk_P.PCI6025EAD_P6,        /* 444: Block Parameter */
  &random_walk_P.Switch_Threshold,     /* 445: Block Parameter */
  &random_walk_P.elbowOffset_Value,    /* 446: Block Parameter */
  &random_walk_P.shoulderOffset_Value, /* 447: Block Parameter */
  &random_walk_P.Gain_Gain,            /* 448: Block Parameter */
  &random_walk_P.Gain1_Gain,           /* 449: Block Parameter */
  &random_walk_P.PCIQUAD04_P1,         /* 450: Block Parameter */
  &random_walk_P.PCIQUAD04_P2,         /* 451: Block Parameter */
  &random_walk_P.PCIQUAD04_P3,         /* 452: Block Parameter */
  &random_walk_P.PCIQUAD04_P4,         /* 453: Block Parameter */
  &random_walk_P.PCIQUAD04_P5,         /* 454: Block Parameter */
  &random_walk_P.PCIQUAD04_P6,         /* 455: Block Parameter */
  &random_walk_P.PCIQUAD04_P7,         /* 456: Block Parameter */
  &random_walk_P.PCIQUAD04_P8,         /* 457: Block Parameter */
  &random_walk_P.PCIQUAD04_P9,         /* 458: Block Parameter */
  &random_walk_P.PCIQUAD04_P10,        /* 459: Block Parameter */
  &random_walk_P.PCIQUAD04_P11,        /* 460: Block Parameter */
  &random_walk_P.PCIQUAD041_P1,        /* 461: Block Parameter */
  &random_walk_P.PCIQUAD041_P2,        /* 462: Block Parameter */
  &random_walk_P.PCIQUAD041_P3,        /* 463: Block Parameter */
  &random_walk_P.PCIQUAD041_P4,        /* 464: Block Parameter */
  &random_walk_P.PCIQUAD041_P5,        /* 465: Block Parameter */
  &random_walk_P.PCIQUAD041_P6,        /* 466: Block Parameter */
  &random_walk_P.PCIQUAD041_P7,        /* 467: Block Parameter */
  &random_walk_P.PCIQUAD041_P8,        /* 468: Block Parameter */
  &random_walk_P.PCIQUAD041_P9,        /* 469: Block Parameter */
  &random_walk_P.PCIQUAD041_P10,       /* 470: Block Parameter */
  &random_walk_P.PCIQUAD041_P11,       /* 471: Block Parameter */
  &random_walk_P.Gain_Gain_b,          /* 472: Block Parameter */
  &random_walk_P.Inverter_Gain,        /* 473: Block Parameter */
  &random_walk_P.Gain_Gain_go,         /* 474: Block Parameter */
  &random_walk_P.Inverter_Gain_b,      /* 475: Block Parameter */
  &random_walk_P.Constant_Value_b,     /* 476: Block Parameter */
  &random_walk_P.Constant_Value_g,     /* 477: Block Parameter */
  &random_walk_P.Gain_Gain_e,          /* 478: Block Parameter */
  &random_walk_P.Time_Value,           /* 479: Block Parameter */
  &random_walk_P.Memory_X0,            /* 480: Block Parameter */
  &random_walk_P.DelayInput1_X0_a,     /* 481: Block Parameter */
  &random_walk_P.DelayInput1_X0_j,     /* 482: Block Parameter */
  &random_walk_P.Gain1_Gain_p,         /* 483: Block Parameter */
  &random_walk_P.Gain2_Gain_d,         /* 484: Block Parameter */
  &random_walk_P.Gain3_Gain,           /* 485: Block Parameter */
  &random_walk_P.Gain4_Gain,           /* 486: Block Parameter */
  &random_walk_P.Saturation_UpperSat,  /* 487: Block Parameter */
  &random_walk_P.Saturation_LowerSat,  /* 488: Block Parameter */
  &random_walk_P.Saturation1_UpperSat, /* 489: Block Parameter */
  &random_walk_P.Saturation1_LowerSat, /* 490: Block Parameter */
  &random_walk_P.Logic_table[0],       /* 491: Block Parameter */
  &random_walk_P.Memory_X0_h,          /* 492: Block Parameter */
  &random_walk_P.Time_Value_p,         /* 493: Block Parameter */
  &random_walk_P.Memory_X0_a,          /* 494: Block Parameter */
  &random_walk_P.Time_Value_n,         /* 495: Block Parameter */
  &random_walk_P.Memory_X0_p,          /* 496: Block Parameter */
  &random_walk_P.Time_Value_m,         /* 497: Block Parameter */
  &random_walk_P.Memory_X0_c,          /* 498: Block Parameter */
  &random_walk_P.DelayInput1_X0_k,     /* 499: Block Parameter */
  &random_walk_P.Time_Value_l,         /* 500: Block Parameter */
  &random_walk_P.Memory_X0_i,          /* 501: Block Parameter */
  &random_walk_P.dG_Gain,              /* 502: Block Parameter */
  &random_walk_P.DigitalFilter_ICRTP,  /* 503: Block Parameter */
  &random_walk_P.DigitalFilter_RTP1COEFF[0],/* 504: Block Parameter */
  &random_walk_P.DigitalFilter2_ICRTP, /* 505: Block Parameter */
  &random_walk_P.DigitalFilter2_RTP1COEFF[0],/* 506: Block Parameter */
  &random_walk_P.dG_Gain_d,            /* 507: Block Parameter */
  &random_walk_P.DigitalFilter_ICRTP_p,/* 508: Block Parameter */
  &random_walk_P.DigitalFilter_RTP1COEFF_o[0],/* 509: Block Parameter */
  &random_walk_P.DigitalFilter2_ICRTP_f,/* 510: Block Parameter */
  &random_walk_P.DigitalFilter2_RTP1COEFF_f[0],/* 511: Block Parameter */
  &random_walk_P.AngleOffset_Value,    /* 512: Block Parameter */
  &random_walk_P.Constant_Value_j,     /* 513: Block Parameter */
  &random_walk_P.Constant2_Value,      /* 514: Block Parameter */
  &random_walk_P.PortA_P1[0],          /* 515: Block Parameter */
  &random_walk_P.PortA_P2,             /* 516: Block Parameter */
  &random_walk_P.PortA_P3[0],          /* 517: Block Parameter */
  &random_walk_P.PortA_P4[0],          /* 518: Block Parameter */
  &random_walk_P.PortA_P5,             /* 519: Block Parameter */
  &random_walk_P.PortA_P6,             /* 520: Block Parameter */
  &random_walk_P.PortA_P7,             /* 521: Block Parameter */
  &random_walk_P.PortA_P8,             /* 522: Block Parameter */
  &random_walk_P.PortA_P9,             /* 523: Block Parameter */
  &random_walk_P.PortB_P1[0],          /* 524: Block Parameter */
  &random_walk_P.PortB_P2,             /* 525: Block Parameter */
  &random_walk_P.PortB_P3[0],          /* 526: Block Parameter */
  &random_walk_P.PortB_P4[0],          /* 527: Block Parameter */
  &random_walk_P.PortB_P5,             /* 528: Block Parameter */
  &random_walk_P.PortB_P6,             /* 529: Block Parameter */
  &random_walk_P.PortB_P7,             /* 530: Block Parameter */
  &random_walk_P.PortB_P8,             /* 531: Block Parameter */
  &random_walk_P.PortB_P9,             /* 532: Block Parameter */
  &random_walk_P.xPCTargetTime_P1_e,   /* 533: Block Parameter */
  &random_walk_P.xPCTargetTime_P2_h,   /* 534: Block Parameter */
  &random_walk_P.Switch_Threshold_a,   /* 535: Block Parameter */
  &random_walk_P.L1_Value,             /* 536: Block Parameter */
  &random_walk_P.L2_Value,             /* 537: Block Parameter */
  &random_walk_P.xoffset_Value,        /* 538: Block Parameter */
  &random_walk_P.yoffset_Value,        /* 539: Block Parameter */
  &random_walk_P.Gain_Gain_f,          /* 540: Block Parameter */
  &random_walk_P.Gain1_Gain_c,         /* 541: Block Parameter */
  &random_walk_P.Gain2_Gain,           /* 542: Block Parameter */
  &random_walk_P.beta_Value,           /* 543: Block Parameter */
  &random_walk_P.rho_Value,            /* 544: Block Parameter */
  &random_walk_P.sigma_Value,          /* 545: Block Parameter */
  &random_walk_P.timescale_Value,      /* 546: Block Parameter */
  &random_walk_P.x_X0_d,               /* 547: Block Parameter */
  &random_walk_P.y_X0,                 /* 548: Block Parameter */
  &random_walk_P.z_X0,                 /* 549: Block Parameter */
  &random_walk_P.beta_Value_i,         /* 550: Block Parameter */
  &random_walk_P.rho_Value_a,          /* 551: Block Parameter */
  &random_walk_P.sigma_Value_l,        /* 552: Block Parameter */
  &random_walk_P.timescale_Value_m,    /* 553: Block Parameter */
  &random_walk_P.x_X0_p,               /* 554: Block Parameter */
  &random_walk_P.y_X0_d,               /* 555: Block Parameter */
  &random_walk_P.z_X0_c,               /* 556: Block Parameter */
  &random_walk_P.beta_Value_p,         /* 557: Block Parameter */
  &random_walk_P.rho_Value_m,          /* 558: Block Parameter */
  &random_walk_P.sigma_Value_j,        /* 559: Block Parameter */
  &random_walk_P.timescale_Value_d,    /* 560: Block Parameter */
  &random_walk_P.x_X0_iy,              /* 561: Block Parameter */
  &random_walk_P.y_X0_e,               /* 562: Block Parameter */
  &random_walk_P.z_X0_b,               /* 563: Block Parameter */
  &random_walk_P.beta_Value_f,         /* 564: Block Parameter */
  &random_walk_P.rho_Value_e,          /* 565: Block Parameter */
  &random_walk_P.sigma_Value_b,        /* 566: Block Parameter */
  &random_walk_P.timescale_Value_p,    /* 567: Block Parameter */
  &random_walk_P.x_X0_p3,              /* 568: Block Parameter */
  &random_walk_P.y_X0_n,               /* 569: Block Parameter */
  &random_walk_P.z_X0_a,               /* 570: Block Parameter */
  &random_walk_P.beta_Value_o,         /* 571: Block Parameter */
  &random_walk_P.rho_Value_am,         /* 572: Block Parameter */
  &random_walk_P.sigma_Value_m,        /* 573: Block Parameter */
  &random_walk_P.timescale_Value_e,    /* 574: Block Parameter */
  &random_walk_P.x_X0,                 /* 575: Block Parameter */
  &random_walk_P.y_X0_g,               /* 576: Block Parameter */
  &random_walk_P.z_X0_cv,              /* 577: Block Parameter */
  &random_walk_P.beta_Value_g,         /* 578: Block Parameter */
  &random_walk_P.rho_Value_j,          /* 579: Block Parameter */
  &random_walk_P.sigma_Value_h,        /* 580: Block Parameter */
  &random_walk_P.timescale_Value_py,   /* 581: Block Parameter */
  &random_walk_P.x_X0_f,               /* 582: Block Parameter */
  &random_walk_P.y_X0_l,               /* 583: Block Parameter */
  &random_walk_P.z_X0_j,               /* 584: Block Parameter */
  &random_walk_P.beta_Value_o2,        /* 585: Block Parameter */
  &random_walk_P.rho_Value_eo,         /* 586: Block Parameter */
  &random_walk_P.sigma_Value_hc,       /* 587: Block Parameter */
  &random_walk_P.timescale_Value_dn,   /* 588: Block Parameter */
  &random_walk_P.x_X0_fi,              /* 589: Block Parameter */
  &random_walk_P.y_X0_p,               /* 590: Block Parameter */
  &random_walk_P.z_X0_l,               /* 591: Block Parameter */
  &random_walk_P.beta_Value_e,         /* 592: Block Parameter */
  &random_walk_P.rho_Value_mm,         /* 593: Block Parameter */
  &random_walk_P.sigma_Value_mj,       /* 594: Block Parameter */
  &random_walk_P.timescale_Value_h,    /* 595: Block Parameter */
  &random_walk_P.x_X0_i,               /* 596: Block Parameter */
  &random_walk_P.y_X0_lz,              /* 597: Block Parameter */
  &random_walk_P.z_X0_g,               /* 598: Block Parameter */
  &random_walk_P.Constant_Value,       /* 599: Block Parameter */
  &random_walk_P.Constant_Value_e,     /* 600: Block Parameter */
  &random_walk_P.DelayInput1_X0,       /* 601: Block Parameter */
  &random_walk_P.Constant_Value_m,     /* 602: Block Parameter */
  &random_walk_P.Constant1_Value,      /* 603: Block Parameter */
  &random_walk_P.ScaleTouSec_Gain,     /* 604: Block Parameter */
  &random_walk_P.PCI6025E_P1_o[0],     /* 605: Block Parameter */
  &random_walk_P.PCI6025E_P2_f[0],     /* 606: Block Parameter */
  &random_walk_P.PCI6025E_P3_k[0],     /* 607: Block Parameter */
  &random_walk_P.PCI6025E_P4_i,        /* 608: Block Parameter */
  &random_walk_P.PCI6025E_P5_h,        /* 609: Block Parameter */
  &random_walk_P.PCI6025E_P6_n,        /* 610: Block Parameter */
  &random_walk_P.PCI6025E_P7_e,        /* 611: Block Parameter */
  &random_walk_P.xPCTargetTime_P1,     /* 612: Block Parameter */
  &random_walk_P.xPCTargetTime_P2,     /* 613: Block Parameter */
  &random_walk_P.Constant_Value_a,     /* 614: Block Parameter */
  &random_walk_P.Constant_Value_o      /* 615: Block Parameter */
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
void random_walk_InitializeDataMapInfo(rtModel_random_walk *random_walk_rtM
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(random_walk_rtM->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(random_walk_rtM->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(random_walk_rtM->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(random_walk_rtM->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(random_walk_rtM->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(random_walk_rtM->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(random_walk_rtM->DataMapInfo.mmi, 0);
}

/* EOF: random_walk_capi.c */
