/*
 * random_walk_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "random_walk.mdl".
 *
 * Model Version              : 1.922
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Wed Jan 09 14:56:49 2008
 */

#include "random_walk.h"
#include "rtw_capi.h"
#include "random_walk_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Matrix Concatenation",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "MG1",
    "", 0, 1, 1, 0, 0 },

  { 2, 0, "MG2",
    "", 0, 1, 1, 0, 0 },

  { 3, 0, "Logical Operator1",
    "", 0, 0, 1, 0, 0 },

  { 4, 0, "Memory",
    "", 0, 0, 1, 0, 0 },

  { 5, 0, "Rate Transition1",
    "", 0, 1, 1, 0, 1 },

  { 6, 0, "Rate Transition2",
    "", 0, 1, 1, 0, 1 },

  { 7, 0, "Behavior RW/p1",
    "", 0, 1, 2, 0, 0 },

  { 8, 0, "Behavior RW/p2",
    "", 1, 1, 3, 0, 0 },

  { 9, 0, "Behavior RW/p3",
    "", 2, 1, 1, 0, 0 },

  { 10, 0, "Behavior RW/p4",
    "", 3, 1, 4, 0, 0 },

  { 11, 0, "Behavior RW/p5",
    "", 4, 1, 1, 0, 0 },

  { 12, 0, "Behavior RW/p6",
    "", 5, 1, 2, 0, 0 },

  { 13, 3, "Switch",
    "", 0, 1, 2, 0, 0 },

  { 14, 0, "Switch1",
    "", 0, 1, 2, 0, 0 },

  { 15, 0, "BoundingBox/Logical Operator",
    "", 0, 0, 1, 0, 0 },

  { 16, 0, "BoundingBox/Relational Operator",
    "", 0, 0, 1, 0, 0 },

  { 17, 0, "BoundingBox/Relational Operator1",
    "", 0, 0, 1, 0, 0 },

  { 18, 0, "BoundingBox/Relational Operator2",
    "", 0, 0, 1, 0, 0 },

  { 19, 0, "BoundingBox/Relational Operator3",
    "", 0, 0, 1, 0, 0 },

  { 20, 0, "Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 21, 0, "Compare To Constant1/Compare",
    "", 0, 2, 1, 0, 0 },

  { 22, 5, "Force Generator/Gain",
    "", 0, 1, 1, 0, 0 },

  { 23, 8, "Force Generator/LorentzForceGain",
    "", 0, 1, 2, 0, 0 },

  { 24, 0, "Force Generator/Multiport Switch",
    "", 0, 1, 2, 0, 0 },

  { 25, 7, "Force Generator/dynamicAngle Switch",
    "", 0, 1, 1, 0, 0 },

  { 26, 1, "Force outside box/Gain1",
    "", 0, 1, 1, 0, 0 },

  { 27, 1, "Force outside box/Gain2",
    "", 0, 1, 1, 0, 0 },

  { 28, 1, "Force outside box/Gain3",
    "", 0, 1, 1, 0, 0 },

  { 29, 1, "Force outside box/Gain4",
    "", 0, 1, 1, 0, 0 },

  { 30, 0, "Force outside box/InBox",
    "", 0, 0, 1, 0, 0 },

  { 31, 0, "Force outside box/Logical Operator",
    "", 0, 0, 1, 0, 0 },

  { 32, 0, "Force outside box/Logical Operator2",
    "", 0, 0, 1, 0, 0 },

  { 33, 2, "Force outside box/Logical Operator3",
    "", 0, 0, 1, 0, 0 },

  { 34, 0, "Force outside box/Logical Operator4",
    "", 0, 0, 1, 0, 0 },

  { 35, 0, "Force outside box/Logical Operator5",
    "", 0, 0, 1, 0, 0 },

  { 36, 2, "Force outside box/Logical Operator6",
    "", 0, 0, 1, 0, 0 },

  { 37, 1, "Force outside box/Product",
    "", 0, 1, 1, 0, 0 },

  { 38, 1, "Force outside box/Product1",
    "", 0, 1, 1, 0, 0 },

  { 39, 1, "Force outside box/Saturation",
    "", 0, 1, 1, 0, 0 },

  { 40, 1, "Force outside box/Saturation1",
    "", 0, 1, 1, 0, 0 },

  { 41, 1, "Force outside box/Sum1",
    "", 0, 1, 1, 0, 0 },

  { 42, 1, "Force outside box/Sum2",
    "", 0, 1, 1, 0, 0 },

  { 43, 2, "Force outside box/Switch",
    "", 0, 1, 2, 0, 0 },

  { 44, 14, "Force//Torque Transform/cos(length of Elbow)",
    "", 0, 1, 1, 0, 0 },

  { 45, 14, "Force//Torque Transform/cos(length of Shoulder)",
    "", 0, 1, 1, 0, 0 },

  { 46, 14, "Force//Torque Transform/sin(length of Elbow)",
    "", 0, 1, 1, 0, 0 },

  { 47, 14, "Force//Torque Transform/sin(length of Shoulder)",
    "", 0, 1, 1, 0, 0 },

  { 48, 14, "Force//Torque Transform/Product",
    "", 0, 1, 1, 0, 0 },

  { 49, 14, "Force//Torque Transform/Product1",
    "", 0, 1, 1, 0, 0 },

  { 50, 14, "Force//Torque Transform/Product2",
    "", 0, 1, 1, 0, 0 },

  { 51, 14, "Force//Torque Transform/Product3",
    "", 0, 1, 1, 0, 0 },

  { 52, 14, "Force//Torque Transform/Sum5",
    "", 0, 1, 1, 0, 0 },

  { 53, 14, "Force//Torque Transform/Sum6",
    "", 0, 1, 1, 0, 0 },

  { 54, 0, "Pos2VelX/Derivative",
    "", 0, 1, 1, 0, 2 },

  { 55, 0, "Pos2VelX/dG",
    "", 0, 1, 1, 0, 0 },

  { 56, 0, "Pos2VelX/Digital Filter",
    "", 0, 1, 1, 0, 0 },

  { 57, 0, "Pos2VelX/Digital Filter2",
    "", 0, 1, 1, 0, 0 },

  { 58, 0, "Pos2VelY/Derivative",
    "", 0, 1, 1, 0, 2 },

  { 59, 0, "Pos2VelY/dG",
    "", 0, 1, 1, 0, 0 },

  { 60, 0, "Pos2VelY/Digital Filter",
    "", 0, 1, 1, 0, 0 },

  { 61, 0, "Pos2VelY/Digital Filter2",
    "", 0, 1, 1, 0, 0 },

  { 62, 0, "RewardSbs/Data Type Conversion",
    "", 0, 1, 1, 0, 0 },

  { 63, 0, "RewardSbs/Memory1",
    "", 0, 0, 1, 0, 0 },

  { 64, 0, "Schmidt/Clock",
    "", 0, 1, 1, 0, 2 },

  { 65, 0, "Schmidt/Logical Operator",
    "", 0, 0, 1, 0, 0 },

  { 66, 0, "Schmidt/Logical Operator1",
    "", 0, 0, 1, 0, 0 },

  { 67, 0, "Schmidt/Logical Operator2",
    "", 0, 0, 1, 0, 0 },

  { 68, 0, "Schmidt/Memory",
    "", 0, 0, 1, 0, 0 },

  { 69, 0, "Schmidt/Relational Operator",
    "", 0, 0, 1, 0, 2 },

  { 70, 0, "Schmidt/Sum",
    "", 0, 1, 1, 0, 2 },

  { 71, 0, "Target Peek/Gain",
    "", 0, 1, 1, 0, 0 },

  { 72, 0, "Target Peek/Gain1",
    "", 0, 1, 1, 0, 0 },

  { 73, 0, "Target Peek/Add",
    "", 0, 1, 1, 0, 0 },

  { 74, 0, "Target Peek/Add1",
    "", 0, 1, 1, 0, 0 },

  { 75, 0, "UDPXmit/Rate Transition",
    "", 0, 2, 5, 0, 3 },

  { 76, 0, "UDPXmit/Pack",
    "", 0, 2, 5, 0, 0 },

  { 77, 0, "WordSbs/ToBits/p1",
    "", 0, 1, 1, 0, 0 },

  { 78, 0, "WordSbs/ToBits/p2",
    "", 1, 1, 1, 0, 0 },

  { 79, 0, "WordSbs/ToBits/p3",
    "", 2, 1, 1, 0, 0 },

  { 80, 0, "WordSbs/ToBits/p4",
    "", 3, 1, 1, 0, 0 },

  { 81, 0, "WordSbs/ToBits/p5",
    "", 4, 1, 1, 0, 0 },

  { 82, 0, "WordSbs/ToBits/p6",
    "", 5, 1, 1, 0, 0 },

  { 83, 0, "WordSbs/ToBits/p7",
    "", 6, 1, 1, 0, 0 },

  { 84, 0, "WordSbs/ToBits/p8",
    "", 7, 1, 1, 0, 0 },

  { 85, 0, "XY Position Subsystem/Gain",
    "", 0, 1, 1, 0, 0 },

  { 86, 0, "XY Position Subsystem/Gain1",
    "", 0, 1, 1, 0, 0 },

  { 87, 0, "XY Position Subsystem/PCI-QUAD04 ",
    "", 0, 1, 1, 0, 0 },

  { 88, 0, "XY Position Subsystem/PCI-QUAD04 1",
    "", 0, 1, 1, 0, 0 },

  { 89, 0, "XY Position Subsystem/Sum1",
    "", 0, 1, 1, 0, 0 },

  { 90, 0, "XY Position Subsystem/Sum3",
    "", 0, 1, 1, 0, 0 },

  { 91, 0, "Force Generator/LorentzForce/Add",
    "", 0, 1, 1, 0, 0 },

  { 92, 0, "Force Generator/LorentzForce/Add1",
    "", 0, 1, 1, 0, 0 },

  { 93, 7, "Force Generator/ViscLoadSubsystem/Gain",
    "", 0, 1, 2, 0, 0 },

  { 94, 7, "Force Generator/ViscLoadSubsystem/Product",
    "", 0, 1, 1, 0, 0 },

  { 95, 7, "Force Generator/ViscLoadSubsystem/Product1",
    "", 0, 1, 1, 0, 0 },

  { 96, 7, "Force Generator/ViscLoadSubsystem/Product2",
    "", 0, 1, 1, 0, 0 },

  { 97, 7, "Force Generator/ViscLoadSubsystem/Product3",
    "", 0, 1, 1, 0, 0 },

  { 98, 7, "Force Generator/ViscLoadSubsystem/Add",
    "", 0, 1, 1, 0, 0 },

  { 99, 7, "Force Generator/ViscLoadSubsystem/Subtract",
    "", 0, 1, 1, 0, 0 },

  { 100, 7, "Force Generator/ViscLoadSubsystem/cos",
    "", 0, 1, 1, 0, 0 },

  { 101, 7, "Force Generator/ViscLoadSubsystem/sin",
    "", 0, 1, 1, 0, 0 },

  { 102, 0, "Force outside box/Compare To Zero/Compare",
    "", 0, 2, 1, 0, 0 },

  { 103, 0, "Force outside box/Compare To Zero1/Compare",
    "", 0, 2, 1, 0, 0 },

  { 104, 0, "Force outside box/In Center/Abs",
    "", 0, 1, 1, 0, 0 },

  { 105, 0, "Force outside box/In Center/Abs1",
    "", 0, 1, 1, 0, 0 },

  { 106, 0, "Force outside box/In Center/Abs2",
    "", 0, 1, 1, 0, 0 },

  { 107, 0, "Force outside box/In Center/Abs3",
    "", 0, 1, 1, 0, 0 },

  { 108, 0, "Force outside box/In Center/Logical Operator1",
    "", 0, 0, 1, 0, 0 },

  { 109, 0, "Force outside box/Leave center/FixPt Relational Operator",
    "", 0, 2, 1, 0, 0 },

  { 110, 0, "Force outside box/Leave center/Delay Input1",
    "U(k-1)", 0, 2, 1, 0, 0 },

  { 111, 0, "Force outside box/Leave center delay/FixPt Relational Operator",
    "", 0, 0, 1, 0, 0 },

  { 112, 0, "Force outside box/Leave center delay/Delay Input1",
    "U(k-1)", 0, 2, 1, 0, 0 },

  { 113, 0, "Force outside box/S-R Flip-Flop/Logic",
    "", 0, 0, 2, 0, 0 },

  { 114, 0, "Force outside box/S-R Flip-Flop/Memory",
    "", 0, 0, 1, 0, 0 },

  { 115, 0, "Force outside box/Schmidt1/Clock",
    "", 0, 1, 1, 0, 2 },

  { 116, 0, "Force outside box/Schmidt1/Logical Operator",
    "", 0, 0, 1, 0, 0 },

  { 117, 0, "Force outside box/Schmidt1/Logical Operator1",
    "", 0, 0, 1, 0, 0 },

  { 118, 0, "Force outside box/Schmidt1/Logical Operator2",
    "", 0, 0, 1, 0, 0 },

  { 119, 0, "Force outside box/Schmidt1/Memory",
    "", 0, 0, 1, 0, 0 },

  { 120, 0, "Force outside box/Schmidt1/Relational Operator",
    "", 0, 0, 1, 0, 2 },

  { 121, 0, "Force outside box/Schmidt1/Sum",
    "", 0, 1, 1, 0, 2 },

  { 122, 0, "Force outside box/Schmidt3/Clock",
    "", 0, 1, 1, 0, 2 },

  { 123, 0, "Force outside box/Schmidt3/Logical Operator",
    "", 0, 0, 1, 0, 0 },

  { 124, 0, "Force outside box/Schmidt3/Logical Operator1",
    "", 0, 0, 1, 0, 0 },

  { 125, 0, "Force outside box/Schmidt3/Logical Operator2",
    "", 0, 0, 1, 0, 0 },

  { 126, 0, "Force outside box/Schmidt3/Memory",
    "", 0, 0, 1, 0, 0 },

  { 127, 0, "Force outside box/Schmidt3/Relational Operator",
    "", 0, 0, 1, 0, 2 },

  { 128, 0, "Force outside box/Schmidt3/Sum",
    "", 0, 1, 1, 0, 2 },

  { 129, 0, "Force outside box/Timer/Clock",
    "", 0, 1, 1, 0, 2 },

  { 130, 0, "Force outside box/Timer/Logical Operator",
    "", 0, 0, 1, 0, 0 },

  { 131, 0, "Force outside box/Timer/Logical Operator1",
    "", 0, 0, 1, 0, 0 },

  { 132, 0, "Force outside box/Timer/Logical Operator2",
    "", 0, 0, 1, 0, 0 },

  { 133, 0, "Force outside box/Timer/Logical Operator3",
    "", 0, 0, 1, 0, 0 },

  { 134, 0, "Force outside box/Timer/Logical Operator4",
    "", 0, 0, 1, 0, 0 },

  { 135, 0, "Force outside box/Timer/Logical Operator5",
    "", 0, 0, 1, 0, 0 },

  { 136, 0, "Force outside box/Timer/Memory",
    "", 0, 0, 1, 0, 0 },

  { 137, 0, "Force outside box/Timer/Relational Operator",
    "", 0, 0, 1, 0, 2 },

  { 138, 0, "Force outside box/Timer/Sum",
    "", 0, 1, 1, 0, 2 },

  { 139, 0, "RewardSbs/Schmidt1/Clock",
    "", 0, 1, 1, 0, 2 },

  { 140, 0, "RewardSbs/Schmidt1/Logical Operator",
    "", 0, 0, 1, 0, 0 },

  { 141, 0, "RewardSbs/Schmidt1/Logical Operator1",
    "", 0, 0, 1, 0, 0 },

  { 142, 0, "RewardSbs/Schmidt1/Logical Operator2",
    "", 0, 0, 1, 0, 0 },

  { 143, 0, "RewardSbs/Schmidt1/Memory",
    "", 0, 0, 1, 0, 0 },

  { 144, 0, "RewardSbs/Schmidt1/Relational Operator",
    "", 0, 0, 1, 0, 2 },

  { 145, 0, "RewardSbs/Schmidt1/Sum",
    "", 0, 1, 1, 0, 2 },

  { 146, 0, "Schmidt/Compare To Zero/Compare",
    "", 0, 2, 1, 0, 2 },

  { 147, 16, "Schmidt/Enabled Subsystem/In1",
    "", 0, 1, 1, 0, 2 },

  { 148, 0, "XY Position Subsystem/Cursor Rotation/sqrt(u[1]*u[1] + u[2]*u[2])",
    "", 0, 1, 1, 0, 0 },

  { 149, 0, "XY Position Subsystem/Cursor Rotation/Product",
    "", 0, 1, 1, 0, 0 },

  { 150, 0, "XY Position Subsystem/Cursor Rotation/Product1",
    "", 0, 1, 1, 0, 0 },

  { 151, 0, "XY Position Subsystem/Cursor Rotation/Sum",
    "", 0, 1, 1, 0, 0 },

  { 152, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function",
    "", 0, 1, 1, 0, 0 },

  { 153, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function1",
    "", 0, 1, 1, 0, 0 },

  { 154, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function2",
    "", 0, 1, 1, 0, 0 },

  { 155, 20, "XY Position Subsystem/For Iterator Subsystem/For Iterator",
    "", 0, 1, 1, 0, 4 },

  { 156, 20, "XY Position Subsystem/For Iterator Subsystem/SerialConverter",
    "", 0, 1, 1, 0, 4 },

  { 157, 20, "XY Position Subsystem/For Iterator Subsystem/ToBits/p1",
    "", 0, 1, 1, 0, 4 },

  { 158, 20, "XY Position Subsystem/For Iterator Subsystem/ToBits/p2",
    "", 1, 1, 1, 0, 4 },

  { 159, 20, "XY Position Subsystem/For Iterator Subsystem/ToBits/p3",
    "", 2, 1, 1, 0, 4 },

  { 160, 20, "XY Position Subsystem/For Iterator Subsystem/ToBits/p4",
    "", 3, 1, 1, 0, 4 },

  { 161, 20, "XY Position Subsystem/For Iterator Subsystem/ToBits/p5",
    "", 4, 1, 1, 0, 4 },

  { 162, 20, "XY Position Subsystem/For Iterator Subsystem/ToBits/p6",
    "", 5, 1, 1, 0, 4 },

  { 163, 20, "XY Position Subsystem/For Iterator Subsystem/ToBits/p7",
    "", 6, 1, 1, 0, 4 },

  { 164, 20, "XY Position Subsystem/For Iterator Subsystem/ToBits/p8",
    "", 7, 1, 1, 0, 4 },

  { 165, 20, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "", 0, 1, 1, 0, 4 },

  { 166, 20, "XY Position Subsystem/For Iterator Subsystem/Add",
    "", 0, 1, 1, 0, 4 },

  { 167, 20, "XY Position Subsystem/For Iterator Subsystem/Add1",
    "", 0, 1, 1, 0, 4 },

  { 168, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/cos(length of Elbow)",
    "", 0, 1, 1, 0, 0 },

  { 169, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/cos(length of Shoulder)",
    "", 0, 1, 1, 0, 0 },

  { 170, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/sin(length of Elbow)",
    "", 0, 1, 1, 0, 0 },

  { 171, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/sin(length of Shoulder)",
    "", 0, 1, 1, 0, 0 },

  { 172, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum1",
    "", 0, 1, 1, 0, 0 },

  { 173, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum2",
    "", 0, 1, 1, 0, 0 },

  { 174, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum3",
    "", 0, 1, 1, 0, 0 },

  { 175, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum4",
    "", 0, 1, 1, 0, 0 },

  { 176, 0, "Force Generator/LorentzForce/Lorentz/dX",
    "", 0, 1, 1, 0, 0 },

  { 177, 0, "Force Generator/LorentzForce/Lorentz/dY",
    "", 0, 1, 1, 0, 0 },

  { 178, 0, "Force Generator/LorentzForce/Lorentz/dZ",
    "", 0, 1, 1, 0, 0 },

  { 179, 0, "Force Generator/LorentzForce/Lorentz/product1",
    "", 0, 1, 1, 0, 0 },

  { 180, 0, "Force Generator/LorentzForce/Lorentz/product2",
    "", 0, 1, 1, 0, 0 },

  { 181, 0, "Force Generator/LorentzForce/Lorentz/product3",
    "", 0, 1, 1, 0, 0 },

  { 182, 0, "Force Generator/LorentzForce/Lorentz/product4",
    "", 0, 1, 1, 0, 0 },

  { 183, 0, "Force Generator/LorentzForce/Lorentz/Add1",
    "", 0, 1, 1, 0, 0 },

  { 184, 0, "Force Generator/LorentzForce/Lorentz/Add2",
    "", 0, 1, 1, 0, 0 },

  { 185, 0, "Force Generator/LorentzForce/Lorentz/Add3",
    "", 0, 1, 1, 0, 0 },

  { 186, 0, "Force Generator/LorentzForce/Lorentz/Add4",
    "", 0, 1, 1, 0, 0 },

  { 187, 0, "Force Generator/LorentzForce/Lorentz/AddX",
    "", 0, 1, 1, 0, 0 },

  { 188, 0, "Force Generator/LorentzForce/Lorentz/AddX1",
    "", 0, 1, 1, 0, 0 },

  { 189, 0, "Force Generator/LorentzForce/Lorentz/AddX2",
    "", 0, 1, 1, 0, 0 },

  { 190, 0, "Force Generator/LorentzForce/Lorentz/x",
    "", 0, 1, 1, 0, 0 },

  { 191, 0, "Force Generator/LorentzForce/Lorentz/y",
    "", 0, 1, 1, 0, 0 },

  { 192, 0, "Force Generator/LorentzForce/Lorentz/z",
    "", 0, 1, 1, 0, 0 },

  { 193, 0, "Force Generator/LorentzForce/Lorentz1/dX",
    "", 0, 1, 1, 0, 0 },

  { 194, 0, "Force Generator/LorentzForce/Lorentz1/dY",
    "", 0, 1, 1, 0, 0 },

  { 195, 0, "Force Generator/LorentzForce/Lorentz1/dZ",
    "", 0, 1, 1, 0, 0 },

  { 196, 0, "Force Generator/LorentzForce/Lorentz1/product1",
    "", 0, 1, 1, 0, 0 },

  { 197, 0, "Force Generator/LorentzForce/Lorentz1/product2",
    "", 0, 1, 1, 0, 0 },

  { 198, 0, "Force Generator/LorentzForce/Lorentz1/product3",
    "", 0, 1, 1, 0, 0 },

  { 199, 0, "Force Generator/LorentzForce/Lorentz1/product4",
    "", 0, 1, 1, 0, 0 },

  { 200, 0, "Force Generator/LorentzForce/Lorentz1/Add1",
    "", 0, 1, 1, 0, 0 },

  { 201, 0, "Force Generator/LorentzForce/Lorentz1/Add2",
    "", 0, 1, 1, 0, 0 },

  { 202, 0, "Force Generator/LorentzForce/Lorentz1/Add3",
    "", 0, 1, 1, 0, 0 },

  { 203, 0, "Force Generator/LorentzForce/Lorentz1/Add4",
    "", 0, 1, 1, 0, 0 },

  { 204, 0, "Force Generator/LorentzForce/Lorentz1/AddX",
    "", 0, 1, 1, 0, 0 },

  { 205, 0, "Force Generator/LorentzForce/Lorentz1/AddX1",
    "", 0, 1, 1, 0, 0 },

  { 206, 0, "Force Generator/LorentzForce/Lorentz1/AddX2",
    "", 0, 1, 1, 0, 0 },

  { 207, 0, "Force Generator/LorentzForce/Lorentz1/x",
    "", 0, 1, 1, 0, 0 },

  { 208, 0, "Force Generator/LorentzForce/Lorentz1/y",
    "", 0, 1, 1, 0, 0 },

  { 209, 0, "Force Generator/LorentzForce/Lorentz1/z",
    "", 0, 1, 1, 0, 0 },

  { 210, 0, "Force Generator/LorentzForce/Lorentz2/dX",
    "", 0, 1, 1, 0, 0 },

  { 211, 0, "Force Generator/LorentzForce/Lorentz2/dY",
    "", 0, 1, 1, 0, 0 },

  { 212, 0, "Force Generator/LorentzForce/Lorentz2/dZ",
    "", 0, 1, 1, 0, 0 },

  { 213, 0, "Force Generator/LorentzForce/Lorentz2/product1",
    "", 0, 1, 1, 0, 0 },

  { 214, 0, "Force Generator/LorentzForce/Lorentz2/product2",
    "", 0, 1, 1, 0, 0 },

  { 215, 0, "Force Generator/LorentzForce/Lorentz2/product3",
    "", 0, 1, 1, 0, 0 },

  { 216, 0, "Force Generator/LorentzForce/Lorentz2/product4",
    "", 0, 1, 1, 0, 0 },

  { 217, 0, "Force Generator/LorentzForce/Lorentz2/Add1",
    "", 0, 1, 1, 0, 0 },

  { 218, 0, "Force Generator/LorentzForce/Lorentz2/Add2",
    "", 0, 1, 1, 0, 0 },

  { 219, 0, "Force Generator/LorentzForce/Lorentz2/Add3",
    "", 0, 1, 1, 0, 0 },

  { 220, 0, "Force Generator/LorentzForce/Lorentz2/Add4",
    "", 0, 1, 1, 0, 0 },

  { 221, 0, "Force Generator/LorentzForce/Lorentz2/AddX",
    "", 0, 1, 1, 0, 0 },

  { 222, 0, "Force Generator/LorentzForce/Lorentz2/AddX1",
    "", 0, 1, 1, 0, 0 },

  { 223, 0, "Force Generator/LorentzForce/Lorentz2/AddX2",
    "", 0, 1, 1, 0, 0 },

  { 224, 0, "Force Generator/LorentzForce/Lorentz2/x",
    "", 0, 1, 1, 0, 0 },

  { 225, 0, "Force Generator/LorentzForce/Lorentz2/y",
    "", 0, 1, 1, 0, 0 },

  { 226, 0, "Force Generator/LorentzForce/Lorentz2/z",
    "", 0, 1, 1, 0, 0 },

  { 227, 0, "Force Generator/LorentzForce/Lorentz3/dX",
    "", 0, 1, 1, 0, 0 },

  { 228, 0, "Force Generator/LorentzForce/Lorentz3/dY",
    "", 0, 1, 1, 0, 0 },

  { 229, 0, "Force Generator/LorentzForce/Lorentz3/dZ",
    "", 0, 1, 1, 0, 0 },

  { 230, 0, "Force Generator/LorentzForce/Lorentz3/product1",
    "", 0, 1, 1, 0, 0 },

  { 231, 0, "Force Generator/LorentzForce/Lorentz3/product2",
    "", 0, 1, 1, 0, 0 },

  { 232, 0, "Force Generator/LorentzForce/Lorentz3/product3",
    "", 0, 1, 1, 0, 0 },

  { 233, 0, "Force Generator/LorentzForce/Lorentz3/product4",
    "", 0, 1, 1, 0, 0 },

  { 234, 0, "Force Generator/LorentzForce/Lorentz3/Add1",
    "", 0, 1, 1, 0, 0 },

  { 235, 0, "Force Generator/LorentzForce/Lorentz3/Add2",
    "", 0, 1, 1, 0, 0 },

  { 236, 0, "Force Generator/LorentzForce/Lorentz3/Add3",
    "", 0, 1, 1, 0, 0 },

  { 237, 0, "Force Generator/LorentzForce/Lorentz3/Add4",
    "", 0, 1, 1, 0, 0 },

  { 238, 0, "Force Generator/LorentzForce/Lorentz3/AddX",
    "", 0, 1, 1, 0, 0 },

  { 239, 0, "Force Generator/LorentzForce/Lorentz3/AddX1",
    "", 0, 1, 1, 0, 0 },

  { 240, 0, "Force Generator/LorentzForce/Lorentz3/AddX2",
    "", 0, 1, 1, 0, 0 },

  { 241, 0, "Force Generator/LorentzForce/Lorentz3/x",
    "", 0, 1, 1, 0, 0 },

  { 242, 0, "Force Generator/LorentzForce/Lorentz3/y",
    "", 0, 1, 1, 0, 0 },

  { 243, 0, "Force Generator/LorentzForce/Lorentz3/z",
    "", 0, 1, 1, 0, 0 },

  { 244, 0, "Force outside box/In Center/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 245, 0, "Force outside box/In Center/Compare To Constant1/Compare",
    "", 0, 2, 1, 0, 0 },

  { 246, 0, "Force outside box/In Center/Compare To Constant2/Compare",
    "", 0, 2, 1, 0, 0 },

  { 247, 0, "Force outside box/In Center/Compare To Constant3/Compare",
    "", 0, 2, 1, 0, 0 },

  { 248, 0, "Force outside box/Leave center/Nonpositive/Compare",
    "", 0, 2, 1, 0, 0 },

  { 249, 0, "Force outside box/Leave center delay/Nonpositive/Compare",
    "", 0, 2, 1, 0, 0 },

  { 250, 0, "Force outside box/Schmidt1/Compare To Zero/Compare",
    "", 0, 2, 1, 0, 2 },

  { 251, 11, "Force outside box/Schmidt1/Enabled Subsystem/In1",
    "", 0, 1, 1, 0, 2 },

  { 252, 0, "Force outside box/Schmidt3/Compare To Zero/Compare",
    "", 0, 2, 1, 0, 2 },

  { 253, 12, "Force outside box/Schmidt3/Enabled Subsystem/In1",
    "", 0, 1, 1, 0, 2 },

  { 254, 0, "Force outside box/Timer/Compare To Zero/Compare",
    "", 0, 2, 1, 0, 2 },

  { 255, 0,
    "Force outside box/Timer/Detect Fall Nonpositive/FixPt Relational Operator",
    "", 0, 2, 1, 0, 0 },

  { 256, 0, "Force outside box/Timer/Detect Fall Nonpositive/Delay Input1",
    "U(k-1)", 0, 2, 1, 0, 0 },

  { 257, 13, "Force outside box/Timer/Enabled Subsystem/In1",
    "", 0, 1, 1, 0, 2 },

  { 258, 0, "RewardSbs/Schmidt1/Compare To Zero/Compare",
    "", 0, 2, 1, 0, 2 },

  { 259, 15, "RewardSbs/Schmidt1/Enabled Subsystem/In1",
    "", 0, 1, 1, 0, 2 },

  { 260, 19,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "", 0, 1, 1, 0, 4 },

  { 261, 19,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "", 0, 1, 1, 0, 4 },

  { 262, 19,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Subtract",
    "", 0, 1, 1, 0, 4 },

  { 263, 19,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Switch",
    "", 0, 1, 1, 0, 4 },

  { 264, 0,
    "Force outside box/Timer/Detect Fall Nonpositive/Nonpositive/Compare",
    "", 0, 2, 1, 0, 0 },

  { 265, 19,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Compare",
    "", 0, 0, 1, 0, 4 },

  { 266, 19,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1/Compare",
    "", 0, 0, 1, 0, 4 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Tunable block parameters */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 267, "zeroX",
    "Value", 1, 1, 0 },

  { 268, "zeroY",
    "Value", 1, 1, 0 },

  { 269, "MG1",
    "Gain", 1, 1, 0 },

  { 270, "MG2",
    "Gain", 1, 1, 0 },

  { 271, "Memory",
    "X0", 0, 1, 0 },

  { 272, "Behavior RW",
    "P1", 1, 1, 0 },

  { 273, "Behavior RW",
    "P2", 1, 1, 0 },

  { 274, "Behavior RW",
    "P3", 1, 1, 0 },

  { 275, "Behavior RW",
    "P4", 1, 1, 0 },

  { 276, "Behavior RW",
    "P5", 1, 1, 0 },

  { 277, "Behavior RW",
    "P6", 1, 1, 0 },

  { 278, "Behavior RW",
    "P7", 1, 1, 0 },

  { 279, "Behavior RW",
    "P8", 1, 1, 0 },

  { 280, "Behavior RW",
    "P9", 1, 1, 0 },

  { 281, "Behavior RW",
    "P10", 1, 1, 0 },

  { 282, "PCI-6025E ",
    "P1", 1, 6, 0 },

  { 283, "PCI-6025E ",
    "P2", 1, 6, 0 },

  { 284, "PCI-6025E ",
    "P3", 1, 6, 0 },

  { 285, "PCI-6025E ",
    "P4", 1, 6, 0 },

  { 286, "PCI-6025E ",
    "P5", 1, 1, 0 },

  { 287, "PCI-6025E ",
    "P6", 1, 6, 0 },

  { 288, "PCI-6025E ",
    "P7", 1, 1, 0 },

  { 289, "BoundingBox/XHighLimit",
    "Value", 1, 1, 0 },

  { 290, "BoundingBox/XLowLimit",
    "Value", 1, 1, 0 },

  { 291, "BoundingBox/YHighLimit",
    "Value", 1, 1, 0 },

  { 292, "BoundingBox/YLowLimit",
    "Value", 1, 1, 0 },

  { 293, "Compare To Constant/Constant",
    "Value", 1, 1, 0 },

  { 294, "Compare To Constant1/Constant",
    "Value", 1, 1, 0 },

  { 295, "Force Generator/DynamicAngle",
    "Value", 1, 1, 0 },

  { 296, "Force Generator/Load",
    "Value", 1, 1, 0 },

  { 297, "Force Generator/Off",
    "Value", 1, 1, 0 },

  { 298, "Force Generator/staticX",
    "Value", 1, 1, 0 },

  { 299, "Force Generator/staticY",
    "Value", 1, 1, 0 },

  { 300, "Force Generator/visAngle",
    "Value", 1, 1, 0 },

  { 301, "Force Generator/Gain",
    "Gain", 1, 1, 0 },

  { 302, "Force Generator/LorentzForceGain",
    "Gain", 1, 1, 0 },

  { 303, "Force outside box/Gain1",
    "Gain", 1, 1, 0 },

  { 304, "Force outside box/Gain2",
    "Gain", 1, 1, 0 },

  { 305, "Force outside box/Gain3",
    "Gain", 1, 1, 0 },

  { 306, "Force outside box/Gain4",
    "Gain", 1, 1, 0 },

  { 307, "Force outside box/Saturation",
    "UpperLimit", 1, 1, 0 },

  { 308, "Force outside box/Saturation",
    "LowerLimit", 1, 1, 0 },

  { 309, "Force outside box/Saturation1",
    "UpperLimit", 1, 1, 0 },

  { 310, "Force outside box/Saturation1",
    "LowerLimit", 1, 1, 0 },

  { 311, "Pos2VelX/dG",
    "Gain", 1, 1, 0 },

  { 312, "Pos2VelX/Digital Filter",
    "ICRTP", 1, 1, 0 },

  { 313, "Pos2VelX/Digital Filter",
    "RTP1COEFF", 1, 7, 0 },

  { 314, "Pos2VelX/Digital Filter2",
    "ICRTP", 1, 1, 0 },

  { 315, "Pos2VelX/Digital Filter2",
    "RTP1COEFF", 1, 7, 0 },

  { 316, "Pos2VelY/dG",
    "Gain", 1, 1, 0 },

  { 317, "Pos2VelY/Digital Filter",
    "ICRTP", 1, 1, 0 },

  { 318, "Pos2VelY/Digital Filter",
    "RTP1COEFF", 1, 7, 0 },

  { 319, "Pos2VelY/Digital Filter2",
    "ICRTP", 1, 1, 0 },

  { 320, "Pos2VelY/Digital Filter2",
    "RTP1COEFF", 1, 7, 0 },

  { 321, "RewardSbs/Memory1",
    "X0", 0, 1, 0 },

  { 322, "Schmidt/Time",
    "Value", 1, 1, 0 },

  { 323, "Schmidt/Memory",
    "X0", 0, 1, 0 },

  { 324, "Target Peek/Gain",
    "Gain", 1, 1, 0 },

  { 325, "Target Peek/Gain1",
    "Gain", 1, 1, 0 },

  { 326, "UDPXmit/Send",
    "P1", 1, 7, 0 },

  { 327, "UDPXmit/Send",
    "P2", 1, 1, 0 },

  { 328, "UDPXmit/Send",
    "P3", 1, 1, 0 },

  { 329, "UDPXmit/Send",
    "P4", 1, 1, 0 },

  { 330, "WordSbs/Port A",
    "P1", 1, 8, 0 },

  { 331, "WordSbs/Port A",
    "P2", 1, 1, 0 },

  { 332, "WordSbs/Port A",
    "P3", 1, 8, 0 },

  { 333, "WordSbs/Port A",
    "P4", 1, 8, 0 },

  { 334, "WordSbs/Port A",
    "P5", 1, 1, 0 },

  { 335, "WordSbs/Port A",
    "P6", 1, 1, 0 },

  { 336, "WordSbs/Port A",
    "P7", 1, 6, 0 },

  { 337, "WordSbs/Port A",
    "P8", 1, 1, 0 },

  { 338, "WordSbs/Port A",
    "P9", 1, 1, 0 },

  { 339, "XY Position Subsystem/elbowOffset",
    "Value", 1, 1, 0 },

  { 340, "XY Position Subsystem/shoulderOffset",
    "Value", 1, 1, 0 },

  { 341, "XY Position Subsystem/Gain",
    "Gain", 1, 1, 0 },

  { 342, "XY Position Subsystem/Gain1",
    "Gain", 1, 1, 0 },

  { 343, "XY Position Subsystem/PCI-QUAD04 ",
    "P1", 1, 1, 0 },

  { 344, "XY Position Subsystem/PCI-QUAD04 ",
    "P2", 1, 1, 0 },

  { 345, "XY Position Subsystem/PCI-QUAD04 ",
    "P3", 1, 1, 0 },

  { 346, "XY Position Subsystem/PCI-QUAD04 ",
    "P4", 1, 1, 0 },

  { 347, "XY Position Subsystem/PCI-QUAD04 ",
    "P5", 1, 1, 0 },

  { 348, "XY Position Subsystem/PCI-QUAD04 ",
    "P6", 1, 1, 0 },

  { 349, "XY Position Subsystem/PCI-QUAD04 ",
    "P7", 1, 1, 0 },

  { 350, "XY Position Subsystem/PCI-QUAD04 ",
    "P8", 1, 1, 0 },

  { 351, "XY Position Subsystem/PCI-QUAD04 ",
    "P9", 1, 1, 0 },

  { 352, "XY Position Subsystem/PCI-QUAD04 ",
    "P10", 1, 1, 0 },

  { 353, "XY Position Subsystem/PCI-QUAD04 ",
    "P11", 1, 1, 0 },

  { 354, "XY Position Subsystem/PCI-QUAD04 1",
    "P1", 1, 1, 0 },

  { 355, "XY Position Subsystem/PCI-QUAD04 1",
    "P2", 1, 1, 0 },

  { 356, "XY Position Subsystem/PCI-QUAD04 1",
    "P3", 1, 1, 0 },

  { 357, "XY Position Subsystem/PCI-QUAD04 1",
    "P4", 1, 1, 0 },

  { 358, "XY Position Subsystem/PCI-QUAD04 1",
    "P5", 1, 1, 0 },

  { 359, "XY Position Subsystem/PCI-QUAD04 1",
    "P6", 1, 1, 0 },

  { 360, "XY Position Subsystem/PCI-QUAD04 1",
    "P7", 1, 1, 0 },

  { 361, "XY Position Subsystem/PCI-QUAD04 1",
    "P8", 1, 1, 0 },

  { 362, "XY Position Subsystem/PCI-QUAD04 1",
    "P9", 1, 1, 0 },

  { 363, "XY Position Subsystem/PCI-QUAD04 1",
    "P10", 1, 1, 0 },

  { 364, "XY Position Subsystem/PCI-QUAD04 1",
    "P11", 1, 1, 0 },

  { 365, "Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 1, 1, 0 },

  { 366, "Force outside box/Leave center/Delay Input1",
    "X0", 2, 1, 0 },

  { 367, "Force outside box/Leave center delay/Delay Input1",
    "X0", 2, 1, 0 },

  { 368, "Force outside box/S-R Flip-Flop/Logic",
    "TruthTable", 0, 9, 0 },

  { 369, "Force outside box/S-R Flip-Flop/Memory",
    "X0", 0, 1, 0 },

  { 370, "Force outside box/Schmidt1/Time",
    "Value", 1, 1, 0 },

  { 371, "Force outside box/Schmidt1/Memory",
    "X0", 0, 1, 0 },

  { 372, "Force outside box/Schmidt3/Time",
    "Value", 1, 1, 0 },

  { 373, "Force outside box/Schmidt3/Memory",
    "X0", 0, 1, 0 },

  { 374, "Force outside box/Timer/Time",
    "Value", 1, 1, 0 },

  { 375, "Force outside box/Timer/Memory",
    "X0", 0, 1, 0 },

  { 376, "RewardSbs/Schmidt1/Time",
    "Value", 1, 1, 0 },

  { 377, "RewardSbs/Schmidt1/Memory",
    "X0", 0, 1, 0 },

  { 378, "XY Position Subsystem/Cursor Rotation/AngleOffset",
    "Value", 1, 1, 0 },

  { 379, "XY Position Subsystem/For Iterator Subsystem/Constant",
    "Value", 1, 1, 0 },

  { 380, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P1", 1, 8, 0 },

  { 381, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P2", 1, 1, 0 },

  { 382, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P3", 1, 8, 0 },

  { 383, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P4", 1, 8, 0 },

  { 384, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P5", 1, 1, 0 },

  { 385, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P6", 1, 1, 0 },

  { 386, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P7", 1, 6, 0 },

  { 387, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P8", 1, 1, 0 },

  { 388, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P9", 1, 1, 0 },

  { 389, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P1", 1, 1, 0 },

  { 390, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P2", 1, 1, 0 },

  { 391, "XY Position Subsystem/Jacobian-Cartesian Transformation/xoffset",
    "Value", 1, 1, 0 },

  { 392, "XY Position Subsystem/Jacobian-Cartesian Transformation/yoffset",
    "Value", 1, 1, 0 },

  { 393, "Force Generator/LorentzForce/Lorentz/beta",
    "Value", 1, 1, 0 },

  { 394, "Force Generator/LorentzForce/Lorentz/rho",
    "Value", 1, 1, 0 },

  { 395, "Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 1, 1, 0 },

  { 396, "Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 1, 1, 0 },

  { 397, "Force Generator/LorentzForce/Lorentz/x",
    "X0", 1, 1, 0 },

  { 398, "Force Generator/LorentzForce/Lorentz/y",
    "X0", 1, 1, 0 },

  { 399, "Force Generator/LorentzForce/Lorentz/z",
    "X0", 1, 1, 0 },

  { 400, "Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 1, 1, 0 },

  { 401, "Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 1, 1, 0 },

  { 402, "Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 1, 1, 0 },

  { 403, "Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 1, 1, 0 },

  { 404, "Force Generator/LorentzForce/Lorentz1/x",
    "X0", 1, 1, 0 },

  { 405, "Force Generator/LorentzForce/Lorentz1/y",
    "X0", 1, 1, 0 },

  { 406, "Force Generator/LorentzForce/Lorentz1/z",
    "X0", 1, 1, 0 },

  { 407, "Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 1, 1, 0 },

  { 408, "Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 1, 1, 0 },

  { 409, "Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 1, 1, 0 },

  { 410, "Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 1, 1, 0 },

  { 411, "Force Generator/LorentzForce/Lorentz2/x",
    "X0", 1, 1, 0 },

  { 412, "Force Generator/LorentzForce/Lorentz2/y",
    "X0", 1, 1, 0 },

  { 413, "Force Generator/LorentzForce/Lorentz2/z",
    "X0", 1, 1, 0 },

  { 414, "Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 1, 1, 0 },

  { 415, "Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 1, 1, 0 },

  { 416, "Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 1, 1, 0 },

  { 417, "Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 1, 1, 0 },

  { 418, "Force Generator/LorentzForce/Lorentz3/x",
    "X0", 1, 1, 0 },

  { 419, "Force Generator/LorentzForce/Lorentz3/y",
    "X0", 1, 1, 0 },

  { 420, "Force Generator/LorentzForce/Lorentz3/z",
    "X0", 1, 1, 0 },

  { 421, "Force outside box/In Center/Compare To Constant/Constant",
    "Value", 1, 1, 0 },

  { 422, "Force outside box/In Center/Compare To Constant1/Constant",
    "Value", 1, 1, 0 },

  { 423, "Force outside box/In Center/Compare To Constant2/Constant",
    "Value", 1, 1, 0 },

  { 424, "Force outside box/In Center/Compare To Constant3/Constant",
    "Value", 1, 1, 0 },

  { 425, "Force outside box/Timer/Detect Fall Nonpositive/Delay Input1",
    "X0", 2, 1, 0 },

  { 426,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant",
    "Value", 1, 1, 0 },

  { 427,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant1",
    "Value", 1, 1, 0 },

  { 428,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "Gain", 1, 1, 0 },

  { 429,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P1", 1, 6, 0 },

  { 430,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P2", 1, 6, 0 },

  { 431,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P3", 1, 6, 0 },

  { 432,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P4", 1, 1, 0 },

  { 433,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P5", 1, 6, 0 },

  { 434,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P6", 1, 1, 0 },

  { 435,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P7", 1, 1, 0 },

  { 436,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P1", 1, 1, 0 },

  { 437,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P2", 1, 1, 0 },

  { 438,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Constant",
    "Value", 1, 1, 0 },

  { 439,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1/Constant",
    "Value", 1, 1, 0 },

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
  &random_walk_B.MatrixConcatenation[0],/* 0: Signal */
  &random_walk_B.MG1,                  /* 1: Signal */
  &random_walk_B.MG2,                  /* 2: Signal */
  &random_walk_B.LogicalOperator1_c,   /* 3: Signal */
  &random_walk_B.Memory_h,             /* 4: Signal */
  &random_walk_B.RateTransition1,      /* 5: Signal */
  &random_walk_B.RateTransition2,      /* 6: Signal */
  &random_walk_B.BehaviorRW_o1[0],     /* 7: Signal */
  &random_walk_B.BehaviorRW_o2[0],     /* 8: Signal */
  &random_walk_B.BehaviorRW_o3,        /* 9: Signal */
  &random_walk_B.BehaviorRW_o4[0],     /* 10: Signal */
  &random_walk_B.BehaviorRW_o5,        /* 11: Signal */
  &random_walk_B.BehaviorRW_o6[0],     /* 12: Signal */
  &random_walk_B.Switch_i[0],          /* 13: Signal */
  &random_walk_B.Switch1[0],           /* 14: Signal */
  &random_walk_B.LogicalOperator_a,    /* 15: Signal */
  &random_walk_B.RelationalOperator_n, /* 16: Signal */
  &random_walk_B.RelationalOperator1,  /* 17: Signal */
  &random_walk_B.RelationalOperator2,  /* 18: Signal */
  &random_walk_B.RelationalOperator3,  /* 19: Signal */
  &random_walk_B.Compare_oh,           /* 20: Signal */
  &random_walk_B.Compare_c,            /* 21: Signal */
  &random_walk_B.Gain_d,               /* 22: Signal */
  &random_walk_B.LorentzForceGain[0],  /* 23: Signal */
  &random_walk_B.MultiportSwitch[0],   /* 24: Signal */
  &random_walk_B.dynamicAngleSwitch,   /* 25: Signal */
  &random_walk_B.Gain1_k,              /* 26: Signal */
  &random_walk_B.Gain2,                /* 27: Signal */
  &random_walk_B.Gain3,                /* 28: Signal */
  &random_walk_B.Gain4,                /* 29: Signal */
  &random_walk_B.InBox,                /* 30: Signal */
  &random_walk_B.LogicalOperator_b,    /* 31: Signal */
  &random_walk_B.LogicalOperator2_d,   /* 32: Signal */
  &random_walk_B.LogicalOperator3_d,   /* 33: Signal */
  &random_walk_B.LogicalOperator4_p,   /* 34: Signal */
  &random_walk_B.LogicalOperator5_l,   /* 35: Signal */
  &random_walk_B.LogicalOperator6,     /* 36: Signal */
  &random_walk_B.Product_f,            /* 37: Signal */
  &random_walk_B.Product1_b,           /* 38: Signal */
  &random_walk_B.Saturation,           /* 39: Signal */
  &random_walk_B.Saturation1,          /* 40: Signal */
  &random_walk_B.Sum1_a,               /* 41: Signal */
  &random_walk_B.Sum2_f,               /* 42: Signal */
  &random_walk_B.Switch_c[0],          /* 43: Signal */
  &random_walk_B.coslengthofElbow_m,   /* 44: Signal */
  &random_walk_B.coslengthofShoulder_l,/* 45: Signal */
  &random_walk_B.sinlengthofElbow_d,   /* 46: Signal */
  &random_walk_B.sinlengthofShoulder_d,/* 47: Signal */
  &random_walk_B.Product_h,            /* 48: Signal */
  &random_walk_B.Product1_e,           /* 49: Signal */
  &random_walk_B.Product2,             /* 50: Signal */
  &random_walk_B.Product3,             /* 51: Signal */
  &random_walk_B.Sum5,                 /* 52: Signal */
  &random_walk_B.Sum6,                 /* 53: Signal */
  &random_walk_B.Derivative,           /* 54: Signal */
  &random_walk_B.dG,                   /* 55: Signal */
  &random_walk_B.DigitalFilter,        /* 56: Signal */
  &random_walk_B.DigitalFilter2,       /* 57: Signal */
  &random_walk_B.Derivative_g,         /* 58: Signal */
  &random_walk_B.dG_l,                 /* 59: Signal */
  &random_walk_B.DigitalFilter_m,      /* 60: Signal */
  &random_walk_B.DigitalFilter2_e,     /* 61: Signal */
  &random_walk_B.DataTypeConversion,   /* 62: Signal */
  &random_walk_B.Memory1,              /* 63: Signal */
  &random_walk_B.Clock,                /* 64: Signal */
  &random_walk_B.LogicalOperator,      /* 65: Signal */
  &random_walk_B.LogicalOperator1,     /* 66: Signal */
  &random_walk_B.LogicalOperator2,     /* 67: Signal */
  &random_walk_B.Memory,               /* 68: Signal */
  &random_walk_B.RelationalOperator,   /* 69: Signal */
  &random_walk_B.Sum,                  /* 70: Signal */
  &random_walk_B.Gain_p,               /* 71: Signal */
  &random_walk_B.Gain1_c,              /* 72: Signal */
  &random_walk_B.Add_o,                /* 73: Signal */
  &random_walk_B.Add1_f,               /* 74: Signal */
  &random_walk_B.RateTransition[0],    /* 75: Signal */
  &random_walk_B.Pack[0],              /* 76: Signal */
  &random_walk_B.ToBits_o1,            /* 77: Signal */
  &random_walk_B.ToBits_o2,            /* 78: Signal */
  &random_walk_B.ToBits_o3,            /* 79: Signal */
  &random_walk_B.ToBits_o4,            /* 80: Signal */
  &random_walk_B.ToBits_o5,            /* 81: Signal */
  &random_walk_B.ToBits_o6,            /* 82: Signal */
  &random_walk_B.ToBits_o7,            /* 83: Signal */
  &random_walk_B.ToBits_o8,            /* 84: Signal */
  &random_walk_B.Gain,                 /* 85: Signal */
  &random_walk_B.Gain1,                /* 86: Signal */
  &random_walk_B.PCIQUAD04,            /* 87: Signal */
  &random_walk_B.PCIQUAD041,           /* 88: Signal */
  &random_walk_B.Sum1,                 /* 89: Signal */
  &random_walk_B.Sum3,                 /* 90: Signal */
  &random_walk_B.Add,                  /* 91: Signal */
  &random_walk_B.Add1,                 /* 92: Signal */
  &random_walk_B.Gain_n[0],            /* 93: Signal */
  &random_walk_B.Product_e,            /* 94: Signal */
  &random_walk_B.Product1_f,           /* 95: Signal */
  &random_walk_B.Product2_m,           /* 96: Signal */
  &random_walk_B.Product3_m,           /* 97: Signal */
  &random_walk_B.Add_c,                /* 98: Signal */
  &random_walk_B.Subtract_j,           /* 99: Signal */
  &random_walk_B.cos_o,                /* 100: Signal */
  &random_walk_B.sin_e,                /* 101: Signal */
  &random_walk_B.Compare_m,            /* 102: Signal */
  &random_walk_B.Compare_d,            /* 103: Signal */
  &random_walk_B.Abs,                  /* 104: Signal */
  &random_walk_B.Abs1,                 /* 105: Signal */
  &random_walk_B.Abs2,                 /* 106: Signal */
  &random_walk_B.Abs3,                 /* 107: Signal */
  &random_walk_B.LogicalOperator1_h,   /* 108: Signal */
  &random_walk_B.FixPtRelationalOperator_i,/* 109: Signal */
  &random_walk_B.Uk1_h,                /* 110: Signal */
  &random_walk_B.FixPtRelationalOperator_g,/* 111: Signal */
  &random_walk_B.Uk1_p,                /* 112: Signal */
  &random_walk_B.Logic[0],             /* 113: Signal */
  &random_walk_B.Memory_d,             /* 114: Signal */
  &random_walk_B.Clock_n,              /* 115: Signal */
  &random_walk_B.LogicalOperator_g,    /* 116: Signal */
  &random_walk_B.LogicalOperator1_e,   /* 117: Signal */
  &random_walk_B.LogicalOperator2_m,   /* 118: Signal */
  &random_walk_B.Memory_k,             /* 119: Signal */
  &random_walk_B.RelationalOperator_f, /* 120: Signal */
  &random_walk_B.Sum_a,                /* 121: Signal */
  &random_walk_B.Clock_jm,             /* 122: Signal */
  &random_walk_B.LogicalOperator_l,    /* 123: Signal */
  &random_walk_B.LogicalOperator1_b,   /* 124: Signal */
  &random_walk_B.LogicalOperator2_mo,  /* 125: Signal */
  &random_walk_B.Memory_i,             /* 126: Signal */
  &random_walk_B.RelationalOperator_k, /* 127: Signal */
  &random_walk_B.Sum_k,                /* 128: Signal */
  &random_walk_B.Clock_j,              /* 129: Signal */
  &random_walk_B.LogicalOperator_m,    /* 130: Signal */
  &random_walk_B.LogicalOperator1_o,   /* 131: Signal */
  &random_walk_B.LogicalOperator2_n,   /* 132: Signal */
  &random_walk_B.LogicalOperator3,     /* 133: Signal */
  &random_walk_B.LogicalOperator4,     /* 134: Signal */
  &random_walk_B.LogicalOperator5,     /* 135: Signal */
  &random_walk_B.Memory_o,             /* 136: Signal */
  &random_walk_B.RelationalOperator_g, /* 137: Signal */
  &random_walk_B.Sum_b,                /* 138: Signal */
  &random_walk_B.Clock_c,              /* 139: Signal */
  &random_walk_B.LogicalOperator_e,    /* 140: Signal */
  &random_walk_B.LogicalOperator1_j,   /* 141: Signal */
  &random_walk_B.LogicalOperator2_f,   /* 142: Signal */
  &random_walk_B.Memory_oz,            /* 143: Signal */
  &random_walk_B.RelationalOperator_gb,/* 144: Signal */
  &random_walk_B.Sum_i,                /* 145: Signal */
  &random_walk_B.Compare,              /* 146: Signal */
  &random_walk_B.EnabledSubsystem.In1, /* 147: Signal */
  &random_walk_B.sqrtu1u1u2u2,         /* 148: Signal */
  &random_walk_B.Product,              /* 149: Signal */
  &random_walk_B.Product1,             /* 150: Signal */
  &random_walk_B.Sum_h,                /* 151: Signal */
  &random_walk_B.TrigonometricFunction,/* 152: Signal */
  &random_walk_B.TrigonometricFunction1,/* 153: Signal */
  &random_walk_B.TrigonometricFunction2,/* 154: Signal */
  &random_walk_B.ForIterator,          /* 155: Signal */
  &random_walk_B.SerialConverter,      /* 156: Signal */
  &random_walk_B.ToBits_o1_n,          /* 157: Signal */
  &random_walk_B.ToBits_o2_f,          /* 158: Signal */
  &random_walk_B.ToBits_o3_k,          /* 159: Signal */
  &random_walk_B.ToBits_o4_n,          /* 160: Signal */
  &random_walk_B.ToBits_o5_f,          /* 161: Signal */
  &random_walk_B.ToBits_o6_i,          /* 162: Signal */
  &random_walk_B.ToBits_o7_f,          /* 163: Signal */
  &random_walk_B.ToBits_o8_d,          /* 164: Signal */
  &random_walk_B.xPCTargetTime,        /* 165: Signal */
  &random_walk_B.Add_j,                /* 166: Signal */
  &random_walk_B.Add1_oz,              /* 167: Signal */
  &random_walk_B.coslengthofElbow,     /* 168: Signal */
  &random_walk_B.coslengthofShoulder,  /* 169: Signal */
  &random_walk_B.sinlengthofElbow,     /* 170: Signal */
  &random_walk_B.sinlengthofShoulder,  /* 171: Signal */
  &random_walk_B.Sum1_g,               /* 172: Signal */
  &random_walk_B.Sum2,                 /* 173: Signal */
  &random_walk_B.Sum3_i,               /* 174: Signal */
  &random_walk_B.Sum4,                 /* 175: Signal */
  &random_walk_B.dX,                   /* 176: Signal */
  &random_walk_B.dY,                   /* 177: Signal */
  &random_walk_B.dZ,                   /* 178: Signal */
  &random_walk_B.product1,             /* 179: Signal */
  &random_walk_B.product2,             /* 180: Signal */
  &random_walk_B.product3,             /* 181: Signal */
  &random_walk_B.product4,             /* 182: Signal */
  &random_walk_B.Add1_o,               /* 183: Signal */
  &random_walk_B.Add2,                 /* 184: Signal */
  &random_walk_B.Add3,                 /* 185: Signal */
  &random_walk_B.Add4,                 /* 186: Signal */
  &random_walk_B.AddX,                 /* 187: Signal */
  &random_walk_B.AddX1,                /* 188: Signal */
  &random_walk_B.AddX2,                /* 189: Signal */
  &random_walk_B.x,                    /* 190: Signal */
  &random_walk_B.y,                    /* 191: Signal */
  &random_walk_B.z,                    /* 192: Signal */
  &random_walk_B.dX_m,                 /* 193: Signal */
  &random_walk_B.dY_f,                 /* 194: Signal */
  &random_walk_B.dZ_g,                 /* 195: Signal */
  &random_walk_B.product1_f,           /* 196: Signal */
  &random_walk_B.product2_l,           /* 197: Signal */
  &random_walk_B.product3_b,           /* 198: Signal */
  &random_walk_B.product4_d,           /* 199: Signal */
  &random_walk_B.Add1_b,               /* 200: Signal */
  &random_walk_B.Add2_b,               /* 201: Signal */
  &random_walk_B.Add3_e,               /* 202: Signal */
  &random_walk_B.Add4_b,               /* 203: Signal */
  &random_walk_B.AddX_j,               /* 204: Signal */
  &random_walk_B.AddX1_b,              /* 205: Signal */
  &random_walk_B.AddX2_e,              /* 206: Signal */
  &random_walk_B.x_f,                  /* 207: Signal */
  &random_walk_B.y_e,                  /* 208: Signal */
  &random_walk_B.z_o,                  /* 209: Signal */
  &random_walk_B.dX_f,                 /* 210: Signal */
  &random_walk_B.dY_b,                 /* 211: Signal */
  &random_walk_B.dZ_f,                 /* 212: Signal */
  &random_walk_B.product1_a,           /* 213: Signal */
  &random_walk_B.product2_g,           /* 214: Signal */
  &random_walk_B.product3_d,           /* 215: Signal */
  &random_walk_B.product4_j,           /* 216: Signal */
  &random_walk_B.Add1_l,               /* 217: Signal */
  &random_walk_B.Add2_l,               /* 218: Signal */
  &random_walk_B.Add3_p,               /* 219: Signal */
  &random_walk_B.Add4_k,               /* 220: Signal */
  &random_walk_B.AddX_o,               /* 221: Signal */
  &random_walk_B.AddX1_j,              /* 222: Signal */
  &random_walk_B.AddX2_h,              /* 223: Signal */
  &random_walk_B.x_h,                  /* 224: Signal */
  &random_walk_B.y_j,                  /* 225: Signal */
  &random_walk_B.z_n,                  /* 226: Signal */
  &random_walk_B.dX_b,                 /* 227: Signal */
  &random_walk_B.dY_n,                 /* 228: Signal */
  &random_walk_B.dZ_i,                 /* 229: Signal */
  &random_walk_B.product1_o,           /* 230: Signal */
  &random_walk_B.product2_c,           /* 231: Signal */
  &random_walk_B.product3_i,           /* 232: Signal */
  &random_walk_B.product4_p,           /* 233: Signal */
  &random_walk_B.Add1_n,               /* 234: Signal */
  &random_walk_B.Add2_d,               /* 235: Signal */
  &random_walk_B.Add3_a,               /* 236: Signal */
  &random_walk_B.Add4_h,               /* 237: Signal */
  &random_walk_B.AddX_jl,              /* 238: Signal */
  &random_walk_B.AddX1_bw,             /* 239: Signal */
  &random_walk_B.AddX2_g,              /* 240: Signal */
  &random_walk_B.x_l,                  /* 241: Signal */
  &random_walk_B.y_o,                  /* 242: Signal */
  &random_walk_B.z_j,                  /* 243: Signal */
  &random_walk_B.Compare_n,            /* 244: Signal */
  &random_walk_B.Compare_a,            /* 245: Signal */
  &random_walk_B.Compare_ht,           /* 246: Signal */
  &random_walk_B.Compare_o,            /* 247: Signal */
  &random_walk_B.Compare_l,            /* 248: Signal */
  &random_walk_B.Compare_be,           /* 249: Signal */
  &random_walk_B.Compare_h,            /* 250: Signal */
  &random_walk_B.EnabledSubsystem_b.In1,/* 251: Signal */
  &random_walk_B.Compare_n2,           /* 252: Signal */
  &random_walk_B.EnabledSubsystem_b1.In1,/* 253: Signal */
  &random_walk_B.Compare_b,            /* 254: Signal */
  &random_walk_B.FixPtRelationalOperator,/* 255: Signal */
  &random_walk_B.Uk1,                  /* 256: Signal */
  &random_walk_B.EnabledSubsystem_f.In1,/* 257: Signal */
  &random_walk_B.Compare_p,            /* 258: Signal */
  &random_walk_B.EnabledSubsystem_by.In1,/* 259: Signal */
  &random_walk_B.ScaleTouSec,          /* 260: Signal */
  &random_walk_B.xPCTargetTime_a,      /* 261: Signal */
  &random_walk_B.Subtract,             /* 262: Signal */
  &random_walk_B.Switch,               /* 263: Signal */
  &random_walk_B.Compare_f,            /* 264: Signal */
  &random_walk_B.Compare_h0,           /* 265: Signal */
  &random_walk_B.Compare_nw,           /* 266: Signal */
  &random_walk_P.zeroX_Value,          /* 267: Block Parameter */
  &random_walk_P.zeroY_Value,          /* 268: Block Parameter */
  &random_walk_P.MG1_Gain,             /* 269: Block Parameter */
  &random_walk_P.MG2_Gain,             /* 270: Block Parameter */
  &random_walk_P.Memory_X0_n,          /* 271: Block Parameter */
  &random_walk_P.BehaviorRW_P1,        /* 272: Block Parameter */
  &random_walk_P.BehaviorRW_P2,        /* 273: Block Parameter */
  &random_walk_P.BehaviorRW_P3,        /* 274: Block Parameter */
  &random_walk_P.BehaviorRW_P4,        /* 275: Block Parameter */
  &random_walk_P.BehaviorRW_P5,        /* 276: Block Parameter */
  &random_walk_P.BehaviorRW_P6,        /* 277: Block Parameter */
  &random_walk_P.BehaviorRW_P7,        /* 278: Block Parameter */
  &random_walk_P.BehaviorRW_P8,        /* 279: Block Parameter */
  &random_walk_P.BehaviorRW_P9,        /* 280: Block Parameter */
  &random_walk_P.BehaviorRW_P10,       /* 281: Block Parameter */
  &random_walk_P.PCI6025E_P1[0],       /* 282: Block Parameter */
  &random_walk_P.PCI6025E_P2[0],       /* 283: Block Parameter */
  &random_walk_P.PCI6025E_P3[0],       /* 284: Block Parameter */
  &random_walk_P.PCI6025E_P4[0],       /* 285: Block Parameter */
  &random_walk_P.PCI6025E_P5,          /* 286: Block Parameter */
  &random_walk_P.PCI6025E_P6[0],       /* 287: Block Parameter */
  &random_walk_P.PCI6025E_P7,          /* 288: Block Parameter */
  &random_walk_P.XHighLimit_Value,     /* 289: Block Parameter */
  &random_walk_P.XLowLimit_Value,      /* 290: Block Parameter */
  &random_walk_P.YHighLimit_Value,     /* 291: Block Parameter */
  &random_walk_P.YLowLimit_Value,      /* 292: Block Parameter */
  &random_walk_P.Constant_Value_a,     /* 293: Block Parameter */
  &random_walk_P.Constant_Value_nk,    /* 294: Block Parameter */
  &random_walk_P.DynamicAngle_Value,   /* 295: Block Parameter */
  &random_walk_P.Load_Value,           /* 296: Block Parameter */
  &random_walk_P.Off_Value,            /* 297: Block Parameter */
  &random_walk_P.staticX_Value,        /* 298: Block Parameter */
  &random_walk_P.staticY_Value,        /* 299: Block Parameter */
  &random_walk_P.visAngle_Value,       /* 300: Block Parameter */
  &random_walk_P.Gain_Gain_p,          /* 301: Block Parameter */
  &random_walk_P.LorentzForceGain_Gain,/* 302: Block Parameter */
  &random_walk_P.Gain1_Gain_k,         /* 303: Block Parameter */
  &random_walk_P.Gain2_Gain,           /* 304: Block Parameter */
  &random_walk_P.Gain3_Gain,           /* 305: Block Parameter */
  &random_walk_P.Gain4_Gain,           /* 306: Block Parameter */
  &random_walk_P.Saturation_UpperSat,  /* 307: Block Parameter */
  &random_walk_P.Saturation_LowerSat,  /* 308: Block Parameter */
  &random_walk_P.Saturation1_UpperSat, /* 309: Block Parameter */
  &random_walk_P.Saturation1_LowerSat, /* 310: Block Parameter */
  &random_walk_P.dG_Gain,              /* 311: Block Parameter */
  &random_walk_P.DigitalFilter_ICRTP,  /* 312: Block Parameter */
  &random_walk_P.DigitalFilter_RTP1COEFF[0],/* 313: Block Parameter */
  &random_walk_P.DigitalFilter2_ICRTP, /* 314: Block Parameter */
  &random_walk_P.DigitalFilter2_RTP1COEFF[0],/* 315: Block Parameter */
  &random_walk_P.dG_Gain_p,            /* 316: Block Parameter */
  &random_walk_P.DigitalFilter_ICRTP_f,/* 317: Block Parameter */
  &random_walk_P.DigitalFilter_RTP1COEFF_h[0],/* 318: Block Parameter */
  &random_walk_P.DigitalFilter2_ICRTP_p,/* 319: Block Parameter */
  &random_walk_P.DigitalFilter2_RTP1COEFF_k[0],/* 320: Block Parameter */
  &random_walk_P.Memory1_X0,           /* 321: Block Parameter */
  &random_walk_P.Time_Value,           /* 322: Block Parameter */
  &random_walk_P.Memory_X0,            /* 323: Block Parameter */
  &random_walk_P.Gain_Gain_g,          /* 324: Block Parameter */
  &random_walk_P.Gain1_Gain_d,         /* 325: Block Parameter */
  &random_walk_P.Send_P1[0],           /* 326: Block Parameter */
  &random_walk_P.Send_P2,              /* 327: Block Parameter */
  &random_walk_P.Send_P3,              /* 328: Block Parameter */
  &random_walk_P.Send_P4,              /* 329: Block Parameter */
  &random_walk_P.PortA_P1[0],          /* 330: Block Parameter */
  &random_walk_P.PortA_P2,             /* 331: Block Parameter */
  &random_walk_P.PortA_P3[0],          /* 332: Block Parameter */
  &random_walk_P.PortA_P4[0],          /* 333: Block Parameter */
  &random_walk_P.PortA_P5,             /* 334: Block Parameter */
  &random_walk_P.PortA_P6,             /* 335: Block Parameter */
  &random_walk_P.PortA_P7[0],          /* 336: Block Parameter */
  &random_walk_P.PortA_P8,             /* 337: Block Parameter */
  &random_walk_P.PortA_P9,             /* 338: Block Parameter */
  &random_walk_P.elbowOffset_Value,    /* 339: Block Parameter */
  &random_walk_P.shoulderOffset_Value, /* 340: Block Parameter */
  &random_walk_P.Gain_Gain,            /* 341: Block Parameter */
  &random_walk_P.Gain1_Gain,           /* 342: Block Parameter */
  &random_walk_P.PCIQUAD04_P1,         /* 343: Block Parameter */
  &random_walk_P.PCIQUAD04_P2,         /* 344: Block Parameter */
  &random_walk_P.PCIQUAD04_P3,         /* 345: Block Parameter */
  &random_walk_P.PCIQUAD04_P4,         /* 346: Block Parameter */
  &random_walk_P.PCIQUAD04_P5,         /* 347: Block Parameter */
  &random_walk_P.PCIQUAD04_P6,         /* 348: Block Parameter */
  &random_walk_P.PCIQUAD04_P7,         /* 349: Block Parameter */
  &random_walk_P.PCIQUAD04_P8,         /* 350: Block Parameter */
  &random_walk_P.PCIQUAD04_P9,         /* 351: Block Parameter */
  &random_walk_P.PCIQUAD04_P10,        /* 352: Block Parameter */
  &random_walk_P.PCIQUAD04_P11,        /* 353: Block Parameter */
  &random_walk_P.PCIQUAD041_P1,        /* 354: Block Parameter */
  &random_walk_P.PCIQUAD041_P2,        /* 355: Block Parameter */
  &random_walk_P.PCIQUAD041_P3,        /* 356: Block Parameter */
  &random_walk_P.PCIQUAD041_P4,        /* 357: Block Parameter */
  &random_walk_P.PCIQUAD041_P5,        /* 358: Block Parameter */
  &random_walk_P.PCIQUAD041_P6,        /* 359: Block Parameter */
  &random_walk_P.PCIQUAD041_P7,        /* 360: Block Parameter */
  &random_walk_P.PCIQUAD041_P8,        /* 361: Block Parameter */
  &random_walk_P.PCIQUAD041_P9,        /* 362: Block Parameter */
  &random_walk_P.PCIQUAD041_P10,       /* 363: Block Parameter */
  &random_walk_P.PCIQUAD041_P11,       /* 364: Block Parameter */
  &random_walk_P.Gain_Gain_go,         /* 365: Block Parameter */
  &random_walk_P.DelayInput1_X0_m,     /* 366: Block Parameter */
  &random_walk_P.DelayInput1_X0_f,     /* 367: Block Parameter */
  &random_walk_P.Logic_table[0],       /* 368: Block Parameter */
  &random_walk_P.Memory_X0_l,          /* 369: Block Parameter */
  &random_walk_P.Time_Value_d,         /* 370: Block Parameter */
  &random_walk_P.Memory_X0_g,          /* 371: Block Parameter */
  &random_walk_P.Time_Value_k,         /* 372: Block Parameter */
  &random_walk_P.Memory_X0_np,         /* 373: Block Parameter */
  &random_walk_P.Time_Value_c,         /* 374: Block Parameter */
  &random_walk_P.Memory_X0_p,          /* 375: Block Parameter */
  &random_walk_P.Time_Value_f,         /* 376: Block Parameter */
  &random_walk_P.Memory_X0_pd,         /* 377: Block Parameter */
  &random_walk_P.AngleOffset_Value,    /* 378: Block Parameter */
  &random_walk_P.Constant_Value_j,     /* 379: Block Parameter */
  &random_walk_P.PortB_P1[0],          /* 380: Block Parameter */
  &random_walk_P.PortB_P2,             /* 381: Block Parameter */
  &random_walk_P.PortB_P3[0],          /* 382: Block Parameter */
  &random_walk_P.PortB_P4[0],          /* 383: Block Parameter */
  &random_walk_P.PortB_P5,             /* 384: Block Parameter */
  &random_walk_P.PortB_P6,             /* 385: Block Parameter */
  &random_walk_P.PortB_P7[0],          /* 386: Block Parameter */
  &random_walk_P.PortB_P8,             /* 387: Block Parameter */
  &random_walk_P.PortB_P9,             /* 388: Block Parameter */
  &random_walk_P.xPCTargetTime_P1_e,   /* 389: Block Parameter */
  &random_walk_P.xPCTargetTime_P2_h,   /* 390: Block Parameter */
  &random_walk_P.xoffset_Value,        /* 391: Block Parameter */
  &random_walk_P.yoffset_Value,        /* 392: Block Parameter */
  &random_walk_P.beta_Value,           /* 393: Block Parameter */
  &random_walk_P.rho_Value,            /* 394: Block Parameter */
  &random_walk_P.sigma_Value,          /* 395: Block Parameter */
  &random_walk_P.timescale_Value,      /* 396: Block Parameter */
  &random_walk_P.x_X0,                 /* 397: Block Parameter */
  &random_walk_P.y_X0,                 /* 398: Block Parameter */
  &random_walk_P.z_X0,                 /* 399: Block Parameter */
  &random_walk_P.beta_Value_g,         /* 400: Block Parameter */
  &random_walk_P.rho_Value_j,          /* 401: Block Parameter */
  &random_walk_P.sigma_Value_h,        /* 402: Block Parameter */
  &random_walk_P.timescale_Value_p,    /* 403: Block Parameter */
  &random_walk_P.x_X0_f,               /* 404: Block Parameter */
  &random_walk_P.y_X0_l,               /* 405: Block Parameter */
  &random_walk_P.z_X0_j,               /* 406: Block Parameter */
  &random_walk_P.beta_Value_o,         /* 407: Block Parameter */
  &random_walk_P.rho_Value_e,          /* 408: Block Parameter */
  &random_walk_P.sigma_Value_hc,       /* 409: Block Parameter */
  &random_walk_P.timescale_Value_d,    /* 410: Block Parameter */
  &random_walk_P.x_X0_fi,              /* 411: Block Parameter */
  &random_walk_P.y_X0_p,               /* 412: Block Parameter */
  &random_walk_P.z_X0_l,               /* 413: Block Parameter */
  &random_walk_P.beta_Value_e,         /* 414: Block Parameter */
  &random_walk_P.rho_Value_m,          /* 415: Block Parameter */
  &random_walk_P.sigma_Value_m,        /* 416: Block Parameter */
  &random_walk_P.timescale_Value_h,    /* 417: Block Parameter */
  &random_walk_P.x_X0_i,               /* 418: Block Parameter */
  &random_walk_P.y_X0_lz,              /* 419: Block Parameter */
  &random_walk_P.z_X0_g,               /* 420: Block Parameter */
  &random_walk_P.Constant_Value,       /* 421: Block Parameter */
  &random_walk_P.Constant_Value_h,     /* 422: Block Parameter */
  &random_walk_P.Constant_Value_c,     /* 423: Block Parameter */
  &random_walk_P.Constant_Value_n,     /* 424: Block Parameter */
  &random_walk_P.DelayInput1_X0,       /* 425: Block Parameter */
  &random_walk_P.Constant_Value_m,     /* 426: Block Parameter */
  &random_walk_P.Constant1_Value,      /* 427: Block Parameter */
  &random_walk_P.ScaleTouSec_Gain,     /* 428: Block Parameter */
  &random_walk_P.PCI6025E_P1_o[0],     /* 429: Block Parameter */
  &random_walk_P.PCI6025E_P2_f[0],     /* 430: Block Parameter */
  &random_walk_P.PCI6025E_P3_k[0],     /* 431: Block Parameter */
  &random_walk_P.PCI6025E_P4_i,        /* 432: Block Parameter */
  &random_walk_P.PCI6025E_P5_h[0],     /* 433: Block Parameter */
  &random_walk_P.PCI6025E_P6_n,        /* 434: Block Parameter */
  &random_walk_P.PCI6025E_P7_e,        /* 435: Block Parameter */
  &random_walk_P.xPCTargetTime_P1,     /* 436: Block Parameter */
  &random_walk_P.xPCTargetTime_P2,     /* 437: Block Parameter */
  &random_walk_P.Constant_Value_ad,    /* 438: Block Parameter */
  &random_walk_P.Constant_Value_o      /* 439: Block Parameter */
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

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
  { rtwCAPI_MATRIX_COL_MAJOR, 0, 2 },

  { rtwCAPI_SCALAR, 2, 2 },

  { rtwCAPI_VECTOR, 0, 2 },

  { rtwCAPI_VECTOR, 4, 2 },

  { rtwCAPI_VECTOR, 6, 2 },

  { rtwCAPI_VECTOR, 8, 2 },

  { rtwCAPI_VECTOR, 10, 2 },

  { rtwCAPI_VECTOR, 12, 2 },

  { rtwCAPI_VECTOR, 14, 2 },

  { rtwCAPI_MATRIX_COL_MAJOR, 16, 2 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  2,                                   /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  1,                                   /* 3 */
  4,                                   /* 4 */
  1,                                   /* 5 */
  10,                                  /* 6 */
  1,                                   /* 7 */
  112,                                 /* 8 */
  1,                                   /* 9 */
  1,                                   /* 10 */
  2,                                   /* 11 */
  1,                                   /* 12 */
  11,                                  /* 13 */
  1,                                   /* 14 */
  8,                                   /* 15 */
  8,                                   /* 16 */
  2                                    /* 17 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0, 0.01, 0.02
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

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    2, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[3], (const void *) &rtcapiStoredFloats[1],
    3, 0 },

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
  { rtBlockSignals, 267 },

  { rtBlockParameters, 173,
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
