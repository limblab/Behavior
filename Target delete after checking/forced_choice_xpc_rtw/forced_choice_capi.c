/*
 * forced_choice_capi.c
 *
 * Real-Time Workshop code generation for Simulink model "forced_choice.mdl".
 *
 * Model Version              : 1.747
 * Real-Time Workshop version : 6.6  (R2007a)  01-Feb-2007
 * C source code generated on : Mon Dec 17 17:05:06 2007
 */

#include "forced_choice.h"
#include "rtw_capi.h"
#include "forced_choice_private.h"

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

  { 7, 0, "Behavior FC/p1",
    "", 0, 1, 2, 0, 0 },

  { 8, 0, "Behavior FC/p2",
    "", 1, 1, 3, 0, 0 },

  { 9, 0, "Behavior FC/p3",
    "", 2, 1, 1, 0, 0 },

  { 10, 0, "Behavior FC/p4",
    "", 3, 1, 4, 0, 0 },

  { 11, 0, "Behavior FC/p5",
    "", 4, 1, 1, 0, 0 },

  { 12, 0, "Behavior FC/p6",
    "", 5, 1, 2, 0, 0 },

  { 13, 1, "Switch",
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

  { 22, 3, "Force Generator/Gain",
    "", 0, 1, 1, 0, 0 },

  { 23, 6, "Force Generator/LorentzForceGain",
    "", 0, 1, 2, 0, 0 },

  { 24, 0, "Force Generator/Multiport Switch",
    "", 0, 1, 2, 0, 0 },

  { 25, 5, "Force Generator/dynamicAngle Switch",
    "", 0, 1, 1, 0, 0 },

  { 26, 9, "Force//Torque Transform/cos(length of Elbow)",
    "", 0, 1, 1, 0, 0 },

  { 27, 9, "Force//Torque Transform/cos(length of Shoulder)",
    "", 0, 1, 1, 0, 0 },

  { 28, 9, "Force//Torque Transform/sin(length of Elbow)",
    "", 0, 1, 1, 0, 0 },

  { 29, 9, "Force//Torque Transform/sin(length of Shoulder)",
    "", 0, 1, 1, 0, 0 },

  { 30, 9, "Force//Torque Transform/Product",
    "", 0, 1, 1, 0, 0 },

  { 31, 9, "Force//Torque Transform/Product1",
    "", 0, 1, 1, 0, 0 },

  { 32, 9, "Force//Torque Transform/Product2",
    "", 0, 1, 1, 0, 0 },

  { 33, 9, "Force//Torque Transform/Product3",
    "", 0, 1, 1, 0, 0 },

  { 34, 9, "Force//Torque Transform/Sum5",
    "", 0, 1, 1, 0, 0 },

  { 35, 9, "Force//Torque Transform/Sum6",
    "", 0, 1, 1, 0, 0 },

  { 36, 0, "Pos2VelX/Derivative",
    "", 0, 1, 1, 0, 2 },

  { 37, 0, "Pos2VelX/dG",
    "", 0, 1, 1, 0, 0 },

  { 38, 0, "Pos2VelX/Digital Filter",
    "", 0, 1, 1, 0, 0 },

  { 39, 0, "Pos2VelX/Digital Filter2",
    "", 0, 1, 1, 0, 0 },

  { 40, 0, "Pos2VelY/Derivative",
    "", 0, 1, 1, 0, 2 },

  { 41, 0, "Pos2VelY/dG",
    "", 0, 1, 1, 0, 0 },

  { 42, 0, "Pos2VelY/Digital Filter",
    "", 0, 1, 1, 0, 0 },

  { 43, 0, "Pos2VelY/Digital Filter2",
    "", 0, 1, 1, 0, 0 },

  { 44, 0, "RewardSbs/Data Type Conversion",
    "", 0, 1, 1, 0, 0 },

  { 45, 0, "RewardSbs/Memory1",
    "", 0, 0, 1, 0, 0 },

  { 46, 0, "Schmidt/Clock",
    "", 0, 1, 1, 0, 2 },

  { 47, 0, "Schmidt/Logical Operator",
    "", 0, 0, 1, 0, 0 },

  { 48, 0, "Schmidt/Logical Operator1",
    "", 0, 0, 1, 0, 0 },

  { 49, 0, "Schmidt/Logical Operator2",
    "", 0, 0, 1, 0, 0 },

  { 50, 0, "Schmidt/Memory",
    "", 0, 0, 1, 0, 0 },

  { 51, 0, "Schmidt/Relational Operator",
    "", 0, 0, 1, 0, 2 },

  { 52, 0, "Schmidt/Sum",
    "", 0, 1, 1, 0, 2 },

  { 53, 0, "Target Peek/Gain",
    "", 0, 1, 1, 0, 0 },

  { 54, 0, "Target Peek/Gain1",
    "", 0, 1, 1, 0, 0 },

  { 55, 0, "Target Peek/Add",
    "", 0, 1, 1, 0, 0 },

  { 56, 0, "Target Peek/Add1",
    "", 0, 1, 1, 0, 0 },

  { 57, 0, "UDPXmit/Rate Transition",
    "", 0, 2, 5, 0, 3 },

  { 58, 0, "UDPXmit/Pack",
    "", 0, 2, 5, 0, 0 },

  { 59, 0, "WordSbs/ToBits/p1",
    "", 0, 1, 1, 0, 0 },

  { 60, 0, "WordSbs/ToBits/p2",
    "", 1, 1, 1, 0, 0 },

  { 61, 0, "WordSbs/ToBits/p3",
    "", 2, 1, 1, 0, 0 },

  { 62, 0, "WordSbs/ToBits/p4",
    "", 3, 1, 1, 0, 0 },

  { 63, 0, "WordSbs/ToBits/p5",
    "", 4, 1, 1, 0, 0 },

  { 64, 0, "WordSbs/ToBits/p6",
    "", 5, 1, 1, 0, 0 },

  { 65, 0, "WordSbs/ToBits/p7",
    "", 6, 1, 1, 0, 0 },

  { 66, 0, "WordSbs/ToBits/p8",
    "", 7, 1, 1, 0, 0 },

  { 67, 0, "XY Position Subsystem/Gain",
    "", 0, 1, 1, 0, 0 },

  { 68, 0, "XY Position Subsystem/Gain1",
    "", 0, 1, 1, 0, 0 },

  { 69, 0, "XY Position Subsystem/PCI-QUAD04 ",
    "", 0, 1, 1, 0, 0 },

  { 70, 0, "XY Position Subsystem/PCI-QUAD04 1",
    "", 0, 1, 1, 0, 0 },

  { 71, 0, "XY Position Subsystem/Sum1",
    "", 0, 1, 1, 0, 0 },

  { 72, 0, "XY Position Subsystem/Sum3",
    "", 0, 1, 1, 0, 0 },

  { 73, 0, "Force Generator/LorentzForce/Add",
    "", 0, 1, 1, 0, 0 },

  { 74, 0, "Force Generator/LorentzForce/Add1",
    "", 0, 1, 1, 0, 0 },

  { 75, 5, "Force Generator/ViscLoadSubsystem/Gain",
    "", 0, 1, 2, 0, 0 },

  { 76, 5, "Force Generator/ViscLoadSubsystem/Product",
    "", 0, 1, 1, 0, 0 },

  { 77, 5, "Force Generator/ViscLoadSubsystem/Product1",
    "", 0, 1, 1, 0, 0 },

  { 78, 5, "Force Generator/ViscLoadSubsystem/Product2",
    "", 0, 1, 1, 0, 0 },

  { 79, 5, "Force Generator/ViscLoadSubsystem/Product3",
    "", 0, 1, 1, 0, 0 },

  { 80, 5, "Force Generator/ViscLoadSubsystem/Add",
    "", 0, 1, 1, 0, 0 },

  { 81, 5, "Force Generator/ViscLoadSubsystem/Subtract",
    "", 0, 1, 1, 0, 0 },

  { 82, 5, "Force Generator/ViscLoadSubsystem/cos",
    "", 0, 1, 1, 0, 0 },

  { 83, 5, "Force Generator/ViscLoadSubsystem/sin",
    "", 0, 1, 1, 0, 0 },

  { 84, 0, "RewardSbs/Schmidt1/Clock",
    "", 0, 1, 1, 0, 2 },

  { 85, 0, "RewardSbs/Schmidt1/Logical Operator",
    "", 0, 0, 1, 0, 0 },

  { 86, 0, "RewardSbs/Schmidt1/Logical Operator1",
    "", 0, 0, 1, 0, 0 },

  { 87, 0, "RewardSbs/Schmidt1/Logical Operator2",
    "", 0, 0, 1, 0, 0 },

  { 88, 0, "RewardSbs/Schmidt1/Memory",
    "", 0, 0, 1, 0, 0 },

  { 89, 0, "RewardSbs/Schmidt1/Relational Operator",
    "", 0, 0, 1, 0, 2 },

  { 90, 0, "RewardSbs/Schmidt1/Sum",
    "", 0, 1, 1, 0, 2 },

  { 91, 0, "Schmidt/Compare To Zero/Compare",
    "", 0, 2, 1, 0, 2 },

  { 92, 11, "Schmidt/Enabled Subsystem/In1",
    "", 0, 1, 1, 0, 2 },

  { 93, 0, "XY Position Subsystem/Cursor Rotation/sqrt(u[1]*u[1] + u[2]*u[2])",
    "", 0, 1, 1, 0, 0 },

  { 94, 0, "XY Position Subsystem/Cursor Rotation/Product",
    "", 0, 1, 1, 0, 0 },

  { 95, 0, "XY Position Subsystem/Cursor Rotation/Product1",
    "", 0, 1, 1, 0, 0 },

  { 96, 0, "XY Position Subsystem/Cursor Rotation/Sum",
    "", 0, 1, 1, 0, 0 },

  { 97, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function",
    "", 0, 1, 1, 0, 0 },

  { 98, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function1",
    "", 0, 1, 1, 0, 0 },

  { 99, 0, "XY Position Subsystem/Cursor Rotation/Trigonometric Function2",
    "", 0, 1, 1, 0, 0 },

  { 100, 15, "XY Position Subsystem/For Iterator Subsystem/For Iterator",
    "", 0, 1, 1, 0, 4 },

  { 101, 15, "XY Position Subsystem/For Iterator Subsystem/SerialConverter",
    "", 0, 1, 1, 0, 4 },

  { 102, 15, "XY Position Subsystem/For Iterator Subsystem/ToBits/p1",
    "", 0, 1, 1, 0, 4 },

  { 103, 15, "XY Position Subsystem/For Iterator Subsystem/ToBits/p2",
    "", 1, 1, 1, 0, 4 },

  { 104, 15, "XY Position Subsystem/For Iterator Subsystem/ToBits/p3",
    "", 2, 1, 1, 0, 4 },

  { 105, 15, "XY Position Subsystem/For Iterator Subsystem/ToBits/p4",
    "", 3, 1, 1, 0, 4 },

  { 106, 15, "XY Position Subsystem/For Iterator Subsystem/ToBits/p5",
    "", 4, 1, 1, 0, 4 },

  { 107, 15, "XY Position Subsystem/For Iterator Subsystem/ToBits/p6",
    "", 5, 1, 1, 0, 4 },

  { 108, 15, "XY Position Subsystem/For Iterator Subsystem/ToBits/p7",
    "", 6, 1, 1, 0, 4 },

  { 109, 15, "XY Position Subsystem/For Iterator Subsystem/ToBits/p8",
    "", 7, 1, 1, 0, 4 },

  { 110, 15, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "", 0, 1, 1, 0, 4 },

  { 111, 15, "XY Position Subsystem/For Iterator Subsystem/Add",
    "", 0, 1, 1, 0, 4 },

  { 112, 15, "XY Position Subsystem/For Iterator Subsystem/Add1",
    "", 0, 1, 1, 0, 4 },

  { 113, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/cos(length of Elbow)",
    "", 0, 1, 1, 0, 0 },

  { 114, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/cos(length of Shoulder)",
    "", 0, 1, 1, 0, 0 },

  { 115, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/sin(length of Elbow)",
    "", 0, 1, 1, 0, 0 },

  { 116, 0,
    "XY Position Subsystem/Jacobian-Cartesian Transformation/sin(length of Shoulder)",
    "", 0, 1, 1, 0, 0 },

  { 117, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum1",
    "", 0, 1, 1, 0, 0 },

  { 118, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum2",
    "", 0, 1, 1, 0, 0 },

  { 119, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum3",
    "", 0, 1, 1, 0, 0 },

  { 120, 0, "XY Position Subsystem/Jacobian-Cartesian Transformation/Sum4",
    "", 0, 1, 1, 0, 0 },

  { 121, 0, "Force Generator/LorentzForce/Lorentz/dX",
    "", 0, 1, 1, 0, 0 },

  { 122, 0, "Force Generator/LorentzForce/Lorentz/dY",
    "", 0, 1, 1, 0, 0 },

  { 123, 0, "Force Generator/LorentzForce/Lorentz/dZ",
    "", 0, 1, 1, 0, 0 },

  { 124, 0, "Force Generator/LorentzForce/Lorentz/product1",
    "", 0, 1, 1, 0, 0 },

  { 125, 0, "Force Generator/LorentzForce/Lorentz/product2",
    "", 0, 1, 1, 0, 0 },

  { 126, 0, "Force Generator/LorentzForce/Lorentz/product3",
    "", 0, 1, 1, 0, 0 },

  { 127, 0, "Force Generator/LorentzForce/Lorentz/product4",
    "", 0, 1, 1, 0, 0 },

  { 128, 0, "Force Generator/LorentzForce/Lorentz/Add1",
    "", 0, 1, 1, 0, 0 },

  { 129, 0, "Force Generator/LorentzForce/Lorentz/Add2",
    "", 0, 1, 1, 0, 0 },

  { 130, 0, "Force Generator/LorentzForce/Lorentz/Add3",
    "", 0, 1, 1, 0, 0 },

  { 131, 0, "Force Generator/LorentzForce/Lorentz/Add4",
    "", 0, 1, 1, 0, 0 },

  { 132, 0, "Force Generator/LorentzForce/Lorentz/AddX",
    "", 0, 1, 1, 0, 0 },

  { 133, 0, "Force Generator/LorentzForce/Lorentz/AddX1",
    "", 0, 1, 1, 0, 0 },

  { 134, 0, "Force Generator/LorentzForce/Lorentz/AddX2",
    "", 0, 1, 1, 0, 0 },

  { 135, 0, "Force Generator/LorentzForce/Lorentz/x",
    "", 0, 1, 1, 0, 0 },

  { 136, 0, "Force Generator/LorentzForce/Lorentz/y",
    "", 0, 1, 1, 0, 0 },

  { 137, 0, "Force Generator/LorentzForce/Lorentz/z",
    "", 0, 1, 1, 0, 0 },

  { 138, 0, "Force Generator/LorentzForce/Lorentz1/dX",
    "", 0, 1, 1, 0, 0 },

  { 139, 0, "Force Generator/LorentzForce/Lorentz1/dY",
    "", 0, 1, 1, 0, 0 },

  { 140, 0, "Force Generator/LorentzForce/Lorentz1/dZ",
    "", 0, 1, 1, 0, 0 },

  { 141, 0, "Force Generator/LorentzForce/Lorentz1/product1",
    "", 0, 1, 1, 0, 0 },

  { 142, 0, "Force Generator/LorentzForce/Lorentz1/product2",
    "", 0, 1, 1, 0, 0 },

  { 143, 0, "Force Generator/LorentzForce/Lorentz1/product3",
    "", 0, 1, 1, 0, 0 },

  { 144, 0, "Force Generator/LorentzForce/Lorentz1/product4",
    "", 0, 1, 1, 0, 0 },

  { 145, 0, "Force Generator/LorentzForce/Lorentz1/Add1",
    "", 0, 1, 1, 0, 0 },

  { 146, 0, "Force Generator/LorentzForce/Lorentz1/Add2",
    "", 0, 1, 1, 0, 0 },

  { 147, 0, "Force Generator/LorentzForce/Lorentz1/Add3",
    "", 0, 1, 1, 0, 0 },

  { 148, 0, "Force Generator/LorentzForce/Lorentz1/Add4",
    "", 0, 1, 1, 0, 0 },

  { 149, 0, "Force Generator/LorentzForce/Lorentz1/AddX",
    "", 0, 1, 1, 0, 0 },

  { 150, 0, "Force Generator/LorentzForce/Lorentz1/AddX1",
    "", 0, 1, 1, 0, 0 },

  { 151, 0, "Force Generator/LorentzForce/Lorentz1/AddX2",
    "", 0, 1, 1, 0, 0 },

  { 152, 0, "Force Generator/LorentzForce/Lorentz1/x",
    "", 0, 1, 1, 0, 0 },

  { 153, 0, "Force Generator/LorentzForce/Lorentz1/y",
    "", 0, 1, 1, 0, 0 },

  { 154, 0, "Force Generator/LorentzForce/Lorentz1/z",
    "", 0, 1, 1, 0, 0 },

  { 155, 0, "Force Generator/LorentzForce/Lorentz2/dX",
    "", 0, 1, 1, 0, 0 },

  { 156, 0, "Force Generator/LorentzForce/Lorentz2/dY",
    "", 0, 1, 1, 0, 0 },

  { 157, 0, "Force Generator/LorentzForce/Lorentz2/dZ",
    "", 0, 1, 1, 0, 0 },

  { 158, 0, "Force Generator/LorentzForce/Lorentz2/product1",
    "", 0, 1, 1, 0, 0 },

  { 159, 0, "Force Generator/LorentzForce/Lorentz2/product2",
    "", 0, 1, 1, 0, 0 },

  { 160, 0, "Force Generator/LorentzForce/Lorentz2/product3",
    "", 0, 1, 1, 0, 0 },

  { 161, 0, "Force Generator/LorentzForce/Lorentz2/product4",
    "", 0, 1, 1, 0, 0 },

  { 162, 0, "Force Generator/LorentzForce/Lorentz2/Add1",
    "", 0, 1, 1, 0, 0 },

  { 163, 0, "Force Generator/LorentzForce/Lorentz2/Add2",
    "", 0, 1, 1, 0, 0 },

  { 164, 0, "Force Generator/LorentzForce/Lorentz2/Add3",
    "", 0, 1, 1, 0, 0 },

  { 165, 0, "Force Generator/LorentzForce/Lorentz2/Add4",
    "", 0, 1, 1, 0, 0 },

  { 166, 0, "Force Generator/LorentzForce/Lorentz2/AddX",
    "", 0, 1, 1, 0, 0 },

  { 167, 0, "Force Generator/LorentzForce/Lorentz2/AddX1",
    "", 0, 1, 1, 0, 0 },

  { 168, 0, "Force Generator/LorentzForce/Lorentz2/AddX2",
    "", 0, 1, 1, 0, 0 },

  { 169, 0, "Force Generator/LorentzForce/Lorentz2/x",
    "", 0, 1, 1, 0, 0 },

  { 170, 0, "Force Generator/LorentzForce/Lorentz2/y",
    "", 0, 1, 1, 0, 0 },

  { 171, 0, "Force Generator/LorentzForce/Lorentz2/z",
    "", 0, 1, 1, 0, 0 },

  { 172, 0, "Force Generator/LorentzForce/Lorentz3/dX",
    "", 0, 1, 1, 0, 0 },

  { 173, 0, "Force Generator/LorentzForce/Lorentz3/dY",
    "", 0, 1, 1, 0, 0 },

  { 174, 0, "Force Generator/LorentzForce/Lorentz3/dZ",
    "", 0, 1, 1, 0, 0 },

  { 175, 0, "Force Generator/LorentzForce/Lorentz3/product1",
    "", 0, 1, 1, 0, 0 },

  { 176, 0, "Force Generator/LorentzForce/Lorentz3/product2",
    "", 0, 1, 1, 0, 0 },

  { 177, 0, "Force Generator/LorentzForce/Lorentz3/product3",
    "", 0, 1, 1, 0, 0 },

  { 178, 0, "Force Generator/LorentzForce/Lorentz3/product4",
    "", 0, 1, 1, 0, 0 },

  { 179, 0, "Force Generator/LorentzForce/Lorentz3/Add1",
    "", 0, 1, 1, 0, 0 },

  { 180, 0, "Force Generator/LorentzForce/Lorentz3/Add2",
    "", 0, 1, 1, 0, 0 },

  { 181, 0, "Force Generator/LorentzForce/Lorentz3/Add3",
    "", 0, 1, 1, 0, 0 },

  { 182, 0, "Force Generator/LorentzForce/Lorentz3/Add4",
    "", 0, 1, 1, 0, 0 },

  { 183, 0, "Force Generator/LorentzForce/Lorentz3/AddX",
    "", 0, 1, 1, 0, 0 },

  { 184, 0, "Force Generator/LorentzForce/Lorentz3/AddX1",
    "", 0, 1, 1, 0, 0 },

  { 185, 0, "Force Generator/LorentzForce/Lorentz3/AddX2",
    "", 0, 1, 1, 0, 0 },

  { 186, 0, "Force Generator/LorentzForce/Lorentz3/x",
    "", 0, 1, 1, 0, 0 },

  { 187, 0, "Force Generator/LorentzForce/Lorentz3/y",
    "", 0, 1, 1, 0, 0 },

  { 188, 0, "Force Generator/LorentzForce/Lorentz3/z",
    "", 0, 1, 1, 0, 0 },

  { 189, 0, "RewardSbs/Schmidt1/Compare To Zero/Compare",
    "", 0, 2, 1, 0, 2 },

  { 190, 10, "RewardSbs/Schmidt1/Enabled Subsystem/In1",
    "", 0, 1, 1, 0, 2 },

  { 191, 14,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "", 0, 1, 1, 0, 4 },

  { 192, 14,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "", 0, 1, 1, 0, 4 },

  { 193, 14,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Subtract",
    "", 0, 1, 1, 0, 4 },

  { 194, 14,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Switch",
    "", 0, 1, 1, 0, 4 },

  { 195, 14,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Compare",
    "", 0, 0, 1, 0, 4 },

  { 196, 14,
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
  { 197, "zeroX",
    "Value", 1, 1, 0 },

  { 198, "zeroY",
    "Value", 1, 1, 0 },

  { 199, "MG1",
    "Gain", 1, 1, 0 },

  { 200, "MG2",
    "Gain", 1, 1, 0 },

  { 201, "Memory",
    "X0", 0, 1, 0 },

  { 202, "Behavior FC",
    "P1", 1, 1, 0 },

  { 203, "Behavior FC",
    "P2", 1, 1, 0 },

  { 204, "Behavior FC",
    "P3", 1, 1, 0 },

  { 205, "Behavior FC",
    "P4", 1, 1, 0 },

  { 206, "Behavior FC",
    "P5", 1, 1, 0 },

  { 207, "Behavior FC",
    "P6", 1, 1, 0 },

  { 208, "Behavior FC",
    "P7", 1, 1, 0 },

  { 209, "Behavior FC",
    "P8", 1, 1, 0 },

  { 210, "Behavior FC",
    "P9", 1, 1, 0 },

  { 211, "Behavior FC",
    "P10", 1, 1, 0 },

  { 212, "Behavior FC",
    "P11", 1, 1, 0 },

  { 213, "PCI-6025E ",
    "P1", 1, 6, 0 },

  { 214, "PCI-6025E ",
    "P2", 1, 6, 0 },

  { 215, "PCI-6025E ",
    "P3", 1, 6, 0 },

  { 216, "PCI-6025E ",
    "P4", 1, 6, 0 },

  { 217, "PCI-6025E ",
    "P5", 1, 1, 0 },

  { 218, "PCI-6025E ",
    "P6", 1, 6, 0 },

  { 219, "PCI-6025E ",
    "P7", 1, 1, 0 },

  { 220, "BoundingBox/XHighLimit",
    "Value", 1, 1, 0 },

  { 221, "BoundingBox/XLowLimit",
    "Value", 1, 1, 0 },

  { 222, "BoundingBox/YHighLimit",
    "Value", 1, 1, 0 },

  { 223, "BoundingBox/YLowLimit",
    "Value", 1, 1, 0 },

  { 224, "Compare To Constant/Constant",
    "Value", 1, 1, 0 },

  { 225, "Compare To Constant1/Constant",
    "Value", 1, 1, 0 },

  { 226, "Force Generator/DynamicAngle",
    "Value", 1, 1, 0 },

  { 227, "Force Generator/Load",
    "Value", 1, 1, 0 },

  { 228, "Force Generator/Off",
    "Value", 1, 1, 0 },

  { 229, "Force Generator/staticX",
    "Value", 1, 1, 0 },

  { 230, "Force Generator/staticY",
    "Value", 1, 1, 0 },

  { 231, "Force Generator/visAngle",
    "Value", 1, 1, 0 },

  { 232, "Force Generator/Gain",
    "Gain", 1, 1, 0 },

  { 233, "Force Generator/LorentzForceGain",
    "Gain", 1, 1, 0 },

  { 234, "Pos2VelX/dG",
    "Gain", 1, 1, 0 },

  { 235, "Pos2VelX/Digital Filter",
    "ICRTP", 1, 1, 0 },

  { 236, "Pos2VelX/Digital Filter",
    "RTP1COEFF", 1, 7, 0 },

  { 237, "Pos2VelX/Digital Filter2",
    "ICRTP", 1, 1, 0 },

  { 238, "Pos2VelX/Digital Filter2",
    "RTP1COEFF", 1, 7, 0 },

  { 239, "Pos2VelY/dG",
    "Gain", 1, 1, 0 },

  { 240, "Pos2VelY/Digital Filter",
    "ICRTP", 1, 1, 0 },

  { 241, "Pos2VelY/Digital Filter",
    "RTP1COEFF", 1, 7, 0 },

  { 242, "Pos2VelY/Digital Filter2",
    "ICRTP", 1, 1, 0 },

  { 243, "Pos2VelY/Digital Filter2",
    "RTP1COEFF", 1, 7, 0 },

  { 244, "RewardSbs/Memory1",
    "X0", 0, 1, 0 },

  { 245, "Schmidt/Time",
    "Value", 1, 1, 0 },

  { 246, "Schmidt/Memory",
    "X0", 0, 1, 0 },

  { 247, "Target Peek/Gain",
    "Gain", 1, 1, 0 },

  { 248, "Target Peek/Gain1",
    "Gain", 1, 1, 0 },

  { 249, "UDPXmit/Send",
    "P1", 1, 7, 0 },

  { 250, "UDPXmit/Send",
    "P2", 1, 1, 0 },

  { 251, "UDPXmit/Send",
    "P3", 1, 1, 0 },

  { 252, "UDPXmit/Send",
    "P4", 1, 1, 0 },

  { 253, "WordSbs/Port A",
    "P1", 1, 8, 0 },

  { 254, "WordSbs/Port A",
    "P2", 1, 1, 0 },

  { 255, "WordSbs/Port A",
    "P3", 1, 8, 0 },

  { 256, "WordSbs/Port A",
    "P4", 1, 8, 0 },

  { 257, "WordSbs/Port A",
    "P5", 1, 1, 0 },

  { 258, "WordSbs/Port A",
    "P6", 1, 1, 0 },

  { 259, "WordSbs/Port A",
    "P7", 1, 6, 0 },

  { 260, "WordSbs/Port A",
    "P8", 1, 1, 0 },

  { 261, "WordSbs/Port A",
    "P9", 1, 1, 0 },

  { 262, "XY Position Subsystem/elbowOffset",
    "Value", 1, 1, 0 },

  { 263, "XY Position Subsystem/shoulderOffset",
    "Value", 1, 1, 0 },

  { 264, "XY Position Subsystem/Gain",
    "Gain", 1, 1, 0 },

  { 265, "XY Position Subsystem/Gain1",
    "Gain", 1, 1, 0 },

  { 266, "XY Position Subsystem/PCI-QUAD04 ",
    "P1", 1, 1, 0 },

  { 267, "XY Position Subsystem/PCI-QUAD04 ",
    "P2", 1, 1, 0 },

  { 268, "XY Position Subsystem/PCI-QUAD04 ",
    "P3", 1, 1, 0 },

  { 269, "XY Position Subsystem/PCI-QUAD04 ",
    "P4", 1, 1, 0 },

  { 270, "XY Position Subsystem/PCI-QUAD04 ",
    "P5", 1, 1, 0 },

  { 271, "XY Position Subsystem/PCI-QUAD04 ",
    "P6", 1, 1, 0 },

  { 272, "XY Position Subsystem/PCI-QUAD04 ",
    "P7", 1, 1, 0 },

  { 273, "XY Position Subsystem/PCI-QUAD04 ",
    "P8", 1, 1, 0 },

  { 274, "XY Position Subsystem/PCI-QUAD04 ",
    "P9", 1, 1, 0 },

  { 275, "XY Position Subsystem/PCI-QUAD04 ",
    "P10", 1, 1, 0 },

  { 276, "XY Position Subsystem/PCI-QUAD04 ",
    "P11", 1, 1, 0 },

  { 277, "XY Position Subsystem/PCI-QUAD04 1",
    "P1", 1, 1, 0 },

  { 278, "XY Position Subsystem/PCI-QUAD04 1",
    "P2", 1, 1, 0 },

  { 279, "XY Position Subsystem/PCI-QUAD04 1",
    "P3", 1, 1, 0 },

  { 280, "XY Position Subsystem/PCI-QUAD04 1",
    "P4", 1, 1, 0 },

  { 281, "XY Position Subsystem/PCI-QUAD04 1",
    "P5", 1, 1, 0 },

  { 282, "XY Position Subsystem/PCI-QUAD04 1",
    "P6", 1, 1, 0 },

  { 283, "XY Position Subsystem/PCI-QUAD04 1",
    "P7", 1, 1, 0 },

  { 284, "XY Position Subsystem/PCI-QUAD04 1",
    "P8", 1, 1, 0 },

  { 285, "XY Position Subsystem/PCI-QUAD04 1",
    "P9", 1, 1, 0 },

  { 286, "XY Position Subsystem/PCI-QUAD04 1",
    "P10", 1, 1, 0 },

  { 287, "XY Position Subsystem/PCI-QUAD04 1",
    "P11", 1, 1, 0 },

  { 288, "Force Generator/ViscLoadSubsystem/Gain",
    "Gain", 1, 1, 0 },

  { 289, "RewardSbs/Schmidt1/Time",
    "Value", 1, 1, 0 },

  { 290, "RewardSbs/Schmidt1/Memory",
    "X0", 0, 1, 0 },

  { 291, "XY Position Subsystem/Cursor Rotation/AngleOffset",
    "Value", 1, 1, 0 },

  { 292, "XY Position Subsystem/For Iterator Subsystem/Constant",
    "Value", 1, 1, 0 },

  { 293, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P1", 1, 8, 0 },

  { 294, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P2", 1, 1, 0 },

  { 295, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P3", 1, 8, 0 },

  { 296, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P4", 1, 8, 0 },

  { 297, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P5", 1, 1, 0 },

  { 298, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P6", 1, 1, 0 },

  { 299, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P7", 1, 6, 0 },

  { 300, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P8", 1, 1, 0 },

  { 301, "XY Position Subsystem/For Iterator Subsystem/Port B",
    "P9", 1, 1, 0 },

  { 302, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P1", 1, 1, 0 },

  { 303, "XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ",
    "P2", 1, 1, 0 },

  { 304, "XY Position Subsystem/Jacobian-Cartesian Transformation/xoffset",
    "Value", 1, 1, 0 },

  { 305, "XY Position Subsystem/Jacobian-Cartesian Transformation/yoffset",
    "Value", 1, 1, 0 },

  { 306, "Force Generator/LorentzForce/Lorentz/beta",
    "Value", 1, 1, 0 },

  { 307, "Force Generator/LorentzForce/Lorentz/rho",
    "Value", 1, 1, 0 },

  { 308, "Force Generator/LorentzForce/Lorentz/sigma",
    "Value", 1, 1, 0 },

  { 309, "Force Generator/LorentzForce/Lorentz/timescale",
    "Value", 1, 1, 0 },

  { 310, "Force Generator/LorentzForce/Lorentz/x",
    "X0", 1, 1, 0 },

  { 311, "Force Generator/LorentzForce/Lorentz/y",
    "X0", 1, 1, 0 },

  { 312, "Force Generator/LorentzForce/Lorentz/z",
    "X0", 1, 1, 0 },

  { 313, "Force Generator/LorentzForce/Lorentz1/beta",
    "Value", 1, 1, 0 },

  { 314, "Force Generator/LorentzForce/Lorentz1/rho",
    "Value", 1, 1, 0 },

  { 315, "Force Generator/LorentzForce/Lorentz1/sigma",
    "Value", 1, 1, 0 },

  { 316, "Force Generator/LorentzForce/Lorentz1/timescale",
    "Value", 1, 1, 0 },

  { 317, "Force Generator/LorentzForce/Lorentz1/x",
    "X0", 1, 1, 0 },

  { 318, "Force Generator/LorentzForce/Lorentz1/y",
    "X0", 1, 1, 0 },

  { 319, "Force Generator/LorentzForce/Lorentz1/z",
    "X0", 1, 1, 0 },

  { 320, "Force Generator/LorentzForce/Lorentz2/beta",
    "Value", 1, 1, 0 },

  { 321, "Force Generator/LorentzForce/Lorentz2/rho",
    "Value", 1, 1, 0 },

  { 322, "Force Generator/LorentzForce/Lorentz2/sigma",
    "Value", 1, 1, 0 },

  { 323, "Force Generator/LorentzForce/Lorentz2/timescale",
    "Value", 1, 1, 0 },

  { 324, "Force Generator/LorentzForce/Lorentz2/x",
    "X0", 1, 1, 0 },

  { 325, "Force Generator/LorentzForce/Lorentz2/y",
    "X0", 1, 1, 0 },

  { 326, "Force Generator/LorentzForce/Lorentz2/z",
    "X0", 1, 1, 0 },

  { 327, "Force Generator/LorentzForce/Lorentz3/beta",
    "Value", 1, 1, 0 },

  { 328, "Force Generator/LorentzForce/Lorentz3/rho",
    "Value", 1, 1, 0 },

  { 329, "Force Generator/LorentzForce/Lorentz3/sigma",
    "Value", 1, 1, 0 },

  { 330, "Force Generator/LorentzForce/Lorentz3/timescale",
    "Value", 1, 1, 0 },

  { 331, "Force Generator/LorentzForce/Lorentz3/x",
    "X0", 1, 1, 0 },

  { 332, "Force Generator/LorentzForce/Lorentz3/y",
    "X0", 1, 1, 0 },

  { 333, "Force Generator/LorentzForce/Lorentz3/z",
    "X0", 1, 1, 0 },

  { 334,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant",
    "Value", 1, 1, 0 },

  { 335,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant1",
    "Value", 1, 1, 0 },

  { 336,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec",
    "Gain", 1, 1, 0 },

  { 337,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P1", 1, 6, 0 },

  { 338,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P2", 1, 6, 0 },

  { 339,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P3", 1, 6, 0 },

  { 340,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P4", 1, 1, 0 },

  { 341,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P5", 1, 6, 0 },

  { 342,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P6", 1, 1, 0 },

  { 343,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ",
    "P7", 1, 1, 0 },

  { 344,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P1", 1, 1, 0 },

  { 345,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ",
    "P2", 1, 1, 0 },

  { 346,
    "XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Constant",
    "Value", 1, 1, 0 },

  { 347,
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
  &forced_choice_B.MatrixConcatenation[0],/* 0: Signal */
  &forced_choice_B.MG1,                /* 1: Signal */
  &forced_choice_B.MG2,                /* 2: Signal */
  &forced_choice_B.LogicalOperator1_l, /* 3: Signal */
  &forced_choice_B.Memory_o,           /* 4: Signal */
  &forced_choice_B.RateTransition1,    /* 5: Signal */
  &forced_choice_B.RateTransition2,    /* 6: Signal */
  &forced_choice_B.BehaviorFC_o1[0],   /* 7: Signal */
  &forced_choice_B.BehaviorFC_o2[0],   /* 8: Signal */
  &forced_choice_B.BehaviorFC_o3,      /* 9: Signal */
  &forced_choice_B.BehaviorFC_o4[0],   /* 10: Signal */
  &forced_choice_B.BehaviorFC_o5,      /* 11: Signal */
  &forced_choice_B.BehaviorFC_o6[0],   /* 12: Signal */
  &forced_choice_B.Switch_d[0],        /* 13: Signal */
  &forced_choice_B.Switch1[0],         /* 14: Signal */
  &forced_choice_B.LogicalOperator_h,  /* 15: Signal */
  &forced_choice_B.RelationalOperator_o,/* 16: Signal */
  &forced_choice_B.RelationalOperator1,/* 17: Signal */
  &forced_choice_B.RelationalOperator2,/* 18: Signal */
  &forced_choice_B.RelationalOperator3,/* 19: Signal */
  &forced_choice_B.Compare_b2,         /* 20: Signal */
  &forced_choice_B.Compare_j,          /* 21: Signal */
  &forced_choice_B.Gain_e,             /* 22: Signal */
  &forced_choice_B.LorentzForceGain[0],/* 23: Signal */
  &forced_choice_B.MultiportSwitch[0], /* 24: Signal */
  &forced_choice_B.dynamicAngleSwitch, /* 25: Signal */
  &forced_choice_B.coslengthofElbow_j, /* 26: Signal */
  &forced_choice_B.coslengthofShoulder_m,/* 27: Signal */
  &forced_choice_B.sinlengthofElbow_j, /* 28: Signal */
  &forced_choice_B.sinlengthofShoulder_e,/* 29: Signal */
  &forced_choice_B.Product_k,          /* 30: Signal */
  &forced_choice_B.Product1_a,         /* 31: Signal */
  &forced_choice_B.Product2,           /* 32: Signal */
  &forced_choice_B.Product3,           /* 33: Signal */
  &forced_choice_B.Sum5,               /* 34: Signal */
  &forced_choice_B.Sum6,               /* 35: Signal */
  &forced_choice_B.Derivative,         /* 36: Signal */
  &forced_choice_B.dG,                 /* 37: Signal */
  &forced_choice_B.DigitalFilter,      /* 38: Signal */
  &forced_choice_B.DigitalFilter2,     /* 39: Signal */
  &forced_choice_B.Derivative_l,       /* 40: Signal */
  &forced_choice_B.dG_k,               /* 41: Signal */
  &forced_choice_B.DigitalFilter_g,    /* 42: Signal */
  &forced_choice_B.DigitalFilter2_d,   /* 43: Signal */
  &forced_choice_B.DataTypeConversion, /* 44: Signal */
  &forced_choice_B.Memory1,            /* 45: Signal */
  &forced_choice_B.Clock,              /* 46: Signal */
  &forced_choice_B.LogicalOperator,    /* 47: Signal */
  &forced_choice_B.LogicalOperator1,   /* 48: Signal */
  &forced_choice_B.LogicalOperator2,   /* 49: Signal */
  &forced_choice_B.Memory,             /* 50: Signal */
  &forced_choice_B.RelationalOperator, /* 51: Signal */
  &forced_choice_B.Sum,                /* 52: Signal */
  &forced_choice_B.Gain_n,             /* 53: Signal */
  &forced_choice_B.Gain1_d,            /* 54: Signal */
  &forced_choice_B.Add_n,              /* 55: Signal */
  &forced_choice_B.Add1_m,             /* 56: Signal */
  &forced_choice_B.RateTransition[0],  /* 57: Signal */
  &forced_choice_B.Pack[0],            /* 58: Signal */
  &forced_choice_B.ToBits_o1,          /* 59: Signal */
  &forced_choice_B.ToBits_o2,          /* 60: Signal */
  &forced_choice_B.ToBits_o3,          /* 61: Signal */
  &forced_choice_B.ToBits_o4,          /* 62: Signal */
  &forced_choice_B.ToBits_o5,          /* 63: Signal */
  &forced_choice_B.ToBits_o6,          /* 64: Signal */
  &forced_choice_B.ToBits_o7,          /* 65: Signal */
  &forced_choice_B.ToBits_o8,          /* 66: Signal */
  &forced_choice_B.Gain,               /* 67: Signal */
  &forced_choice_B.Gain1,              /* 68: Signal */
  &forced_choice_B.PCIQUAD04,          /* 69: Signal */
  &forced_choice_B.PCIQUAD041,         /* 70: Signal */
  &forced_choice_B.Sum1,               /* 71: Signal */
  &forced_choice_B.Sum3,               /* 72: Signal */
  &forced_choice_B.Add,                /* 73: Signal */
  &forced_choice_B.Add1,               /* 74: Signal */
  &forced_choice_B.Gain_l[0],          /* 75: Signal */
  &forced_choice_B.Product_h,          /* 76: Signal */
  &forced_choice_B.Product1_h,         /* 77: Signal */
  &forced_choice_B.Product2_p,         /* 78: Signal */
  &forced_choice_B.Product3_g,         /* 79: Signal */
  &forced_choice_B.Add_f,              /* 80: Signal */
  &forced_choice_B.Subtract_b,         /* 81: Signal */
  &forced_choice_B.cos_n,              /* 82: Signal */
  &forced_choice_B.sin_c,              /* 83: Signal */
  &forced_choice_B.Clock_k,            /* 84: Signal */
  &forced_choice_B.LogicalOperator_a,  /* 85: Signal */
  &forced_choice_B.LogicalOperator1_m, /* 86: Signal */
  &forced_choice_B.LogicalOperator2_h, /* 87: Signal */
  &forced_choice_B.Memory_f,           /* 88: Signal */
  &forced_choice_B.RelationalOperator_m,/* 89: Signal */
  &forced_choice_B.Sum_l,              /* 90: Signal */
  &forced_choice_B.Compare,            /* 91: Signal */
  &forced_choice_B.EnabledSubsystem.In1,/* 92: Signal */
  &forced_choice_B.sqrtu1u1u2u2,       /* 93: Signal */
  &forced_choice_B.Product,            /* 94: Signal */
  &forced_choice_B.Product1,           /* 95: Signal */
  &forced_choice_B.Sum_f,              /* 96: Signal */
  &forced_choice_B.TrigonometricFunction,/* 97: Signal */
  &forced_choice_B.TrigonometricFunction1,/* 98: Signal */
  &forced_choice_B.TrigonometricFunction2,/* 99: Signal */
  &forced_choice_B.ForIterator,        /* 100: Signal */
  &forced_choice_B.SerialConverter,    /* 101: Signal */
  &forced_choice_B.ToBits_o1_n,        /* 102: Signal */
  &forced_choice_B.ToBits_o2_l,        /* 103: Signal */
  &forced_choice_B.ToBits_o3_f,        /* 104: Signal */
  &forced_choice_B.ToBits_o4_k,        /* 105: Signal */
  &forced_choice_B.ToBits_o5_a,        /* 106: Signal */
  &forced_choice_B.ToBits_o6_o,        /* 107: Signal */
  &forced_choice_B.ToBits_o7_h,        /* 108: Signal */
  &forced_choice_B.ToBits_o8_e,        /* 109: Signal */
  &forced_choice_B.xPCTargetTime,      /* 110: Signal */
  &forced_choice_B.Add_i,              /* 111: Signal */
  &forced_choice_B.Add1_k,             /* 112: Signal */
  &forced_choice_B.coslengthofElbow,   /* 113: Signal */
  &forced_choice_B.coslengthofShoulder,/* 114: Signal */
  &forced_choice_B.sinlengthofElbow,   /* 115: Signal */
  &forced_choice_B.sinlengthofShoulder,/* 116: Signal */
  &forced_choice_B.Sum1_a,             /* 117: Signal */
  &forced_choice_B.Sum2,               /* 118: Signal */
  &forced_choice_B.Sum3_n,             /* 119: Signal */
  &forced_choice_B.Sum4,               /* 120: Signal */
  &forced_choice_B.dX,                 /* 121: Signal */
  &forced_choice_B.dY,                 /* 122: Signal */
  &forced_choice_B.dZ,                 /* 123: Signal */
  &forced_choice_B.product1,           /* 124: Signal */
  &forced_choice_B.product2,           /* 125: Signal */
  &forced_choice_B.product3,           /* 126: Signal */
  &forced_choice_B.product4,           /* 127: Signal */
  &forced_choice_B.Add1_o,             /* 128: Signal */
  &forced_choice_B.Add2,               /* 129: Signal */
  &forced_choice_B.Add3,               /* 130: Signal */
  &forced_choice_B.Add4,               /* 131: Signal */
  &forced_choice_B.AddX,               /* 132: Signal */
  &forced_choice_B.AddX1,              /* 133: Signal */
  &forced_choice_B.AddX2,              /* 134: Signal */
  &forced_choice_B.x,                  /* 135: Signal */
  &forced_choice_B.y,                  /* 136: Signal */
  &forced_choice_B.z,                  /* 137: Signal */
  &forced_choice_B.dX_i,               /* 138: Signal */
  &forced_choice_B.dY_g,               /* 139: Signal */
  &forced_choice_B.dZ_k,               /* 140: Signal */
  &forced_choice_B.product1_k,         /* 141: Signal */
  &forced_choice_B.product2_n,         /* 142: Signal */
  &forced_choice_B.product3_b,         /* 143: Signal */
  &forced_choice_B.product4_n,         /* 144: Signal */
  &forced_choice_B.Add1_e,             /* 145: Signal */
  &forced_choice_B.Add2_d,             /* 146: Signal */
  &forced_choice_B.Add3_n,             /* 147: Signal */
  &forced_choice_B.Add4_c,             /* 148: Signal */
  &forced_choice_B.AddX_m,             /* 149: Signal */
  &forced_choice_B.AddX1_j,            /* 150: Signal */
  &forced_choice_B.AddX2_j,            /* 151: Signal */
  &forced_choice_B.x_h,                /* 152: Signal */
  &forced_choice_B.y_p,                /* 153: Signal */
  &forced_choice_B.z_m,                /* 154: Signal */
  &forced_choice_B.dX_l,               /* 155: Signal */
  &forced_choice_B.dY_o,               /* 156: Signal */
  &forced_choice_B.dZ_f,               /* 157: Signal */
  &forced_choice_B.product1_b,         /* 158: Signal */
  &forced_choice_B.product2_a,         /* 159: Signal */
  &forced_choice_B.product3_c,         /* 160: Signal */
  &forced_choice_B.product4_c,         /* 161: Signal */
  &forced_choice_B.Add1_l,             /* 162: Signal */
  &forced_choice_B.Add2_k,             /* 163: Signal */
  &forced_choice_B.Add3_k,             /* 164: Signal */
  &forced_choice_B.Add4_i,             /* 165: Signal */
  &forced_choice_B.AddX_k,             /* 166: Signal */
  &forced_choice_B.AddX1_k,            /* 167: Signal */
  &forced_choice_B.AddX2_b,            /* 168: Signal */
  &forced_choice_B.x_m,                /* 169: Signal */
  &forced_choice_B.y_e,                /* 170: Signal */
  &forced_choice_B.z_mc,               /* 171: Signal */
  &forced_choice_B.dX_a,               /* 172: Signal */
  &forced_choice_B.dY_p,               /* 173: Signal */
  &forced_choice_B.dZ_p,               /* 174: Signal */
  &forced_choice_B.product1_kd,        /* 175: Signal */
  &forced_choice_B.product2_j,         /* 176: Signal */
  &forced_choice_B.product3_a,         /* 177: Signal */
  &forced_choice_B.product4_p,         /* 178: Signal */
  &forced_choice_B.Add1_i,             /* 179: Signal */
  &forced_choice_B.Add2_c,             /* 180: Signal */
  &forced_choice_B.Add3_d,             /* 181: Signal */
  &forced_choice_B.Add4_h,             /* 182: Signal */
  &forced_choice_B.AddX_mq,            /* 183: Signal */
  &forced_choice_B.AddX1_e,            /* 184: Signal */
  &forced_choice_B.AddX2_f,            /* 185: Signal */
  &forced_choice_B.x_ho,               /* 186: Signal */
  &forced_choice_B.y_k,                /* 187: Signal */
  &forced_choice_B.z_n,                /* 188: Signal */
  &forced_choice_B.Compare_b,          /* 189: Signal */
  &forced_choice_B.EnabledSubsystem_h.In1,/* 190: Signal */
  &forced_choice_B.ScaleTouSec,        /* 191: Signal */
  &forced_choice_B.xPCTargetTime_n,    /* 192: Signal */
  &forced_choice_B.Subtract,           /* 193: Signal */
  &forced_choice_B.Switch,             /* 194: Signal */
  &forced_choice_B.Compare_a,          /* 195: Signal */
  &forced_choice_B.Compare_p,          /* 196: Signal */
  &forced_choice_P.zeroX_Value,        /* 197: Block Parameter */
  &forced_choice_P.zeroY_Value,        /* 198: Block Parameter */
  &forced_choice_P.MG1_Gain,           /* 199: Block Parameter */
  &forced_choice_P.MG2_Gain,           /* 200: Block Parameter */
  &forced_choice_P.Memory_X0_b,        /* 201: Block Parameter */
  &forced_choice_P.BehaviorFC_P1,      /* 202: Block Parameter */
  &forced_choice_P.BehaviorFC_P2,      /* 203: Block Parameter */
  &forced_choice_P.BehaviorFC_P3,      /* 204: Block Parameter */
  &forced_choice_P.BehaviorFC_P4,      /* 205: Block Parameter */
  &forced_choice_P.BehaviorFC_P5,      /* 206: Block Parameter */
  &forced_choice_P.BehaviorFC_P6,      /* 207: Block Parameter */
  &forced_choice_P.BehaviorFC_P7,      /* 208: Block Parameter */
  &forced_choice_P.BehaviorFC_P8,      /* 209: Block Parameter */
  &forced_choice_P.BehaviorFC_P9,      /* 210: Block Parameter */
  &forced_choice_P.BehaviorFC_P10,     /* 211: Block Parameter */
  &forced_choice_P.BehaviorFC_P11,     /* 212: Block Parameter */
  &forced_choice_P.PCI6025E_P1[0],     /* 213: Block Parameter */
  &forced_choice_P.PCI6025E_P2[0],     /* 214: Block Parameter */
  &forced_choice_P.PCI6025E_P3[0],     /* 215: Block Parameter */
  &forced_choice_P.PCI6025E_P4[0],     /* 216: Block Parameter */
  &forced_choice_P.PCI6025E_P5,        /* 217: Block Parameter */
  &forced_choice_P.PCI6025E_P6[0],     /* 218: Block Parameter */
  &forced_choice_P.PCI6025E_P7,        /* 219: Block Parameter */
  &forced_choice_P.XHighLimit_Value,   /* 220: Block Parameter */
  &forced_choice_P.XLowLimit_Value,    /* 221: Block Parameter */
  &forced_choice_P.YHighLimit_Value,   /* 222: Block Parameter */
  &forced_choice_P.YLowLimit_Value,    /* 223: Block Parameter */
  &forced_choice_P.Constant_Value,     /* 224: Block Parameter */
  &forced_choice_P.Constant_Value_d,   /* 225: Block Parameter */
  &forced_choice_P.DynamicAngle_Value, /* 226: Block Parameter */
  &forced_choice_P.Load_Value,         /* 227: Block Parameter */
  &forced_choice_P.Off_Value,          /* 228: Block Parameter */
  &forced_choice_P.staticX_Value,      /* 229: Block Parameter */
  &forced_choice_P.staticY_Value,      /* 230: Block Parameter */
  &forced_choice_P.visAngle_Value,     /* 231: Block Parameter */
  &forced_choice_P.Gain_Gain_d,        /* 232: Block Parameter */
  &forced_choice_P.LorentzForceGain_Gain,/* 233: Block Parameter */
  &forced_choice_P.dG_Gain,            /* 234: Block Parameter */
  &forced_choice_P.DigitalFilter_ICRTP,/* 235: Block Parameter */
  &forced_choice_P.DigitalFilter_RTP1COEFF[0],/* 236: Block Parameter */
  &forced_choice_P.DigitalFilter2_ICRTP,/* 237: Block Parameter */
  &forced_choice_P.DigitalFilter2_RTP1COEFF[0],/* 238: Block Parameter */
  &forced_choice_P.dG_Gain_b,          /* 239: Block Parameter */
  &forced_choice_P.DigitalFilter_ICRTP_c,/* 240: Block Parameter */
  &forced_choice_P.DigitalFilter_RTP1COEFF_n[0],/* 241: Block Parameter */
  &forced_choice_P.DigitalFilter2_ICRTP_c,/* 242: Block Parameter */
  &forced_choice_P.DigitalFilter2_RTP1COEFF_a[0],/* 243: Block Parameter */
  &forced_choice_P.Memory1_X0,         /* 244: Block Parameter */
  &forced_choice_P.Time_Value,         /* 245: Block Parameter */
  &forced_choice_P.Memory_X0,          /* 246: Block Parameter */
  &forced_choice_P.Gain_Gain_i,        /* 247: Block Parameter */
  &forced_choice_P.Gain1_Gain_e,       /* 248: Block Parameter */
  &forced_choice_P.Send_P1[0],         /* 249: Block Parameter */
  &forced_choice_P.Send_P2,            /* 250: Block Parameter */
  &forced_choice_P.Send_P3,            /* 251: Block Parameter */
  &forced_choice_P.Send_P4,            /* 252: Block Parameter */
  &forced_choice_P.PortA_P1[0],        /* 253: Block Parameter */
  &forced_choice_P.PortA_P2,           /* 254: Block Parameter */
  &forced_choice_P.PortA_P3[0],        /* 255: Block Parameter */
  &forced_choice_P.PortA_P4[0],        /* 256: Block Parameter */
  &forced_choice_P.PortA_P5,           /* 257: Block Parameter */
  &forced_choice_P.PortA_P6,           /* 258: Block Parameter */
  &forced_choice_P.PortA_P7[0],        /* 259: Block Parameter */
  &forced_choice_P.PortA_P8,           /* 260: Block Parameter */
  &forced_choice_P.PortA_P9,           /* 261: Block Parameter */
  &forced_choice_P.elbowOffset_Value,  /* 262: Block Parameter */
  &forced_choice_P.shoulderOffset_Value,/* 263: Block Parameter */
  &forced_choice_P.Gain_Gain,          /* 264: Block Parameter */
  &forced_choice_P.Gain1_Gain,         /* 265: Block Parameter */
  &forced_choice_P.PCIQUAD04_P1,       /* 266: Block Parameter */
  &forced_choice_P.PCIQUAD04_P2,       /* 267: Block Parameter */
  &forced_choice_P.PCIQUAD04_P3,       /* 268: Block Parameter */
  &forced_choice_P.PCIQUAD04_P4,       /* 269: Block Parameter */
  &forced_choice_P.PCIQUAD04_P5,       /* 270: Block Parameter */
  &forced_choice_P.PCIQUAD04_P6,       /* 271: Block Parameter */
  &forced_choice_P.PCIQUAD04_P7,       /* 272: Block Parameter */
  &forced_choice_P.PCIQUAD04_P8,       /* 273: Block Parameter */
  &forced_choice_P.PCIQUAD04_P9,       /* 274: Block Parameter */
  &forced_choice_P.PCIQUAD04_P10,      /* 275: Block Parameter */
  &forced_choice_P.PCIQUAD04_P11,      /* 276: Block Parameter */
  &forced_choice_P.PCIQUAD041_P1,      /* 277: Block Parameter */
  &forced_choice_P.PCIQUAD041_P2,      /* 278: Block Parameter */
  &forced_choice_P.PCIQUAD041_P3,      /* 279: Block Parameter */
  &forced_choice_P.PCIQUAD041_P4,      /* 280: Block Parameter */
  &forced_choice_P.PCIQUAD041_P5,      /* 281: Block Parameter */
  &forced_choice_P.PCIQUAD041_P6,      /* 282: Block Parameter */
  &forced_choice_P.PCIQUAD041_P7,      /* 283: Block Parameter */
  &forced_choice_P.PCIQUAD041_P8,      /* 284: Block Parameter */
  &forced_choice_P.PCIQUAD041_P9,      /* 285: Block Parameter */
  &forced_choice_P.PCIQUAD041_P10,     /* 286: Block Parameter */
  &forced_choice_P.PCIQUAD041_P11,     /* 287: Block Parameter */
  &forced_choice_P.Gain_Gain_m,        /* 288: Block Parameter */
  &forced_choice_P.Time_Value_b,       /* 289: Block Parameter */
  &forced_choice_P.Memory_X0_n,        /* 290: Block Parameter */
  &forced_choice_P.AngleOffset_Value,  /* 291: Block Parameter */
  &forced_choice_P.Constant_Value_i,   /* 292: Block Parameter */
  &forced_choice_P.PortB_P1[0],        /* 293: Block Parameter */
  &forced_choice_P.PortB_P2,           /* 294: Block Parameter */
  &forced_choice_P.PortB_P3[0],        /* 295: Block Parameter */
  &forced_choice_P.PortB_P4[0],        /* 296: Block Parameter */
  &forced_choice_P.PortB_P5,           /* 297: Block Parameter */
  &forced_choice_P.PortB_P6,           /* 298: Block Parameter */
  &forced_choice_P.PortB_P7[0],        /* 299: Block Parameter */
  &forced_choice_P.PortB_P8,           /* 300: Block Parameter */
  &forced_choice_P.PortB_P9,           /* 301: Block Parameter */
  &forced_choice_P.xPCTargetTime_P1_a, /* 302: Block Parameter */
  &forced_choice_P.xPCTargetTime_P2_g, /* 303: Block Parameter */
  &forced_choice_P.xoffset_Value,      /* 304: Block Parameter */
  &forced_choice_P.yoffset_Value,      /* 305: Block Parameter */
  &forced_choice_P.beta_Value,         /* 306: Block Parameter */
  &forced_choice_P.rho_Value,          /* 307: Block Parameter */
  &forced_choice_P.sigma_Value,        /* 308: Block Parameter */
  &forced_choice_P.timescale_Value,    /* 309: Block Parameter */
  &forced_choice_P.x_X0,               /* 310: Block Parameter */
  &forced_choice_P.y_X0,               /* 311: Block Parameter */
  &forced_choice_P.z_X0,               /* 312: Block Parameter */
  &forced_choice_P.beta_Value_b,       /* 313: Block Parameter */
  &forced_choice_P.rho_Value_d,        /* 314: Block Parameter */
  &forced_choice_P.sigma_Value_e,      /* 315: Block Parameter */
  &forced_choice_P.timescale_Value_j,  /* 316: Block Parameter */
  &forced_choice_P.x_X0_f,             /* 317: Block Parameter */
  &forced_choice_P.y_X0_f,             /* 318: Block Parameter */
  &forced_choice_P.z_X0_p,             /* 319: Block Parameter */
  &forced_choice_P.beta_Value_p,       /* 320: Block Parameter */
  &forced_choice_P.rho_Value_h,        /* 321: Block Parameter */
  &forced_choice_P.sigma_Value_o,      /* 322: Block Parameter */
  &forced_choice_P.timescale_Value_d,  /* 323: Block Parameter */
  &forced_choice_P.x_X0_l,             /* 324: Block Parameter */
  &forced_choice_P.y_X0_k,             /* 325: Block Parameter */
  &forced_choice_P.z_X0_n,             /* 326: Block Parameter */
  &forced_choice_P.beta_Value_e,       /* 327: Block Parameter */
  &forced_choice_P.rho_Value_n,        /* 328: Block Parameter */
  &forced_choice_P.sigma_Value_k,      /* 329: Block Parameter */
  &forced_choice_P.timescale_Value_f,  /* 330: Block Parameter */
  &forced_choice_P.x_X0_c,             /* 331: Block Parameter */
  &forced_choice_P.y_X0_h,             /* 332: Block Parameter */
  &forced_choice_P.z_X0_b,             /* 333: Block Parameter */
  &forced_choice_P.Constant_Value_h,   /* 334: Block Parameter */
  &forced_choice_P.Constant1_Value,    /* 335: Block Parameter */
  &forced_choice_P.ScaleTouSec_Gain,   /* 336: Block Parameter */
  &forced_choice_P.PCI6025E_P1_f[0],   /* 337: Block Parameter */
  &forced_choice_P.PCI6025E_P2_h[0],   /* 338: Block Parameter */
  &forced_choice_P.PCI6025E_P3_e[0],   /* 339: Block Parameter */
  &forced_choice_P.PCI6025E_P4_g,      /* 340: Block Parameter */
  &forced_choice_P.PCI6025E_P5_h[0],   /* 341: Block Parameter */
  &forced_choice_P.PCI6025E_P6_f,      /* 342: Block Parameter */
  &forced_choice_P.PCI6025E_P7_g,      /* 343: Block Parameter */
  &forced_choice_P.xPCTargetTime_P1,   /* 344: Block Parameter */
  &forced_choice_P.xPCTargetTime_P2,   /* 345: Block Parameter */
  &forced_choice_P.Constant_Value_m2,  /* 346: Block Parameter */
  &forced_choice_P.Constant_Value_m    /* 347: Block Parameter */
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

  { rtwCAPI_VECTOR, 14, 2 }
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
  8                                    /* 15 */
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
  { rtBlockSignals, 197 },

  { rtBlockParameters, 151,
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
