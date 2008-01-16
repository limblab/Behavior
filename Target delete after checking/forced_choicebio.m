function bio=forced_choicebio
bio = [];
bio(1).blkName='Matrix Concatenation';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[2,1];
bio(1).sigWidth=2;
bio(1).sigAddress='&forced_choice_B.MatrixConcatenation[0]';
bio(getlenBIO) = bio(1);

bio(2).blkName='MG1';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&forced_choice_B.MG1';

bio(3).blkName='MG2';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&forced_choice_B.MG2';

bio(4).blkName='Logical Operator1';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&forced_choice_B.LogicalOperator1_l';

bio(5).blkName='Memory';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&forced_choice_B.Memory_o';

bio(6).blkName='Rate Transition1';
bio(6).sigName='';
bio(6).portIdx=0;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&forced_choice_B.RateTransition1';

bio(7).blkName='Rate Transition2';
bio(7).sigName='';
bio(7).portIdx=0;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&forced_choice_B.RateTransition2';

bio(8).blkName='Behavior FC/p1';
bio(8).sigName='';
bio(8).portIdx=0;
bio(8).dim=[2,1];
bio(8).sigWidth=2;
bio(8).sigAddress='&forced_choice_B.BehaviorFC_o1[0]';

bio(9).blkName='Behavior FC/p2';
bio(9).sigName='';
bio(9).portIdx=1;
bio(9).dim=[4,1];
bio(9).sigWidth=4;
bio(9).sigAddress='&forced_choice_B.BehaviorFC_o2[0]';

bio(10).blkName='Behavior FC/p3';
bio(10).sigName='';
bio(10).portIdx=2;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&forced_choice_B.BehaviorFC_o3';

bio(11).blkName='Behavior FC/p4';
bio(11).sigName='';
bio(11).portIdx=3;
bio(11).dim=[10,1];
bio(11).sigWidth=10;
bio(11).sigAddress='&forced_choice_B.BehaviorFC_o4[0]';

bio(12).blkName='Behavior FC/p5';
bio(12).sigName='';
bio(12).portIdx=4;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&forced_choice_B.BehaviorFC_o5';

bio(13).blkName='Behavior FC/p6';
bio(13).sigName='';
bio(13).portIdx=5;
bio(13).dim=[2,1];
bio(13).sigWidth=2;
bio(13).sigAddress='&forced_choice_B.BehaviorFC_o6[0]';

bio(14).blkName='Switch';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[2,1];
bio(14).sigWidth=2;
bio(14).sigAddress='&forced_choice_B.Switch_d[0]';

bio(15).blkName='Switch1';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[2,1];
bio(15).sigWidth=2;
bio(15).sigAddress='&forced_choice_B.Switch1[0]';

bio(16).blkName='BoundingBox/Logical Operator';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&forced_choice_B.LogicalOperator_h';

bio(17).blkName='BoundingBox/Relational Operator';
bio(17).sigName='';
bio(17).portIdx=0;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&forced_choice_B.RelationalOperator_o';

bio(18).blkName='BoundingBox/Relational Operator1';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&forced_choice_B.RelationalOperator1';

bio(19).blkName='BoundingBox/Relational Operator2';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&forced_choice_B.RelationalOperator2';

bio(20).blkName='BoundingBox/Relational Operator3';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&forced_choice_B.RelationalOperator3';

bio(21).blkName='Compare To Constant/Compare';
bio(21).sigName='';
bio(21).portIdx=0;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&forced_choice_B.Compare_b2';

bio(22).blkName='Compare To Constant1/Compare';
bio(22).sigName='';
bio(22).portIdx=0;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&forced_choice_B.Compare_j';

bio(23).blkName='Force Generator/Gain';
bio(23).sigName='';
bio(23).portIdx=0;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&forced_choice_B.Gain_e';

bio(24).blkName='Force Generator/LorentzForceGain';
bio(24).sigName='';
bio(24).portIdx=0;
bio(24).dim=[2,1];
bio(24).sigWidth=2;
bio(24).sigAddress='&forced_choice_B.LorentzForceGain[0]';

bio(25).blkName='Force Generator/Multiport Switch';
bio(25).sigName='';
bio(25).portIdx=0;
bio(25).dim=[2,1];
bio(25).sigWidth=2;
bio(25).sigAddress='&forced_choice_B.MultiportSwitch[0]';

bio(26).blkName='Force Generator/dynamicAngle Switch';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&forced_choice_B.dynamicAngleSwitch';

bio(27).blkName='Force//Torque Transform/cos(length of Elbow)';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&forced_choice_B.coslengthofElbow_j';

bio(28).blkName='Force//Torque Transform/cos(length of Shoulder)';
bio(28).sigName='';
bio(28).portIdx=0;
bio(28).dim=[1,1];
bio(28).sigWidth=1;
bio(28).sigAddress='&forced_choice_B.coslengthofShoulder_m';

bio(29).blkName='Force//Torque Transform/sin(length of Elbow)';
bio(29).sigName='';
bio(29).portIdx=0;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&forced_choice_B.sinlengthofElbow_j';

bio(30).blkName='Force//Torque Transform/sin(length of Shoulder)';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&forced_choice_B.sinlengthofShoulder_e';

bio(31).blkName='Force//Torque Transform/Product';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&forced_choice_B.Product_k';

bio(32).blkName='Force//Torque Transform/Product1';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&forced_choice_B.Product1_a';

bio(33).blkName='Force//Torque Transform/Product2';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[1,1];
bio(33).sigWidth=1;
bio(33).sigAddress='&forced_choice_B.Product2';

bio(34).blkName='Force//Torque Transform/Product3';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&forced_choice_B.Product3';

bio(35).blkName='Force//Torque Transform/Sum5';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[1,1];
bio(35).sigWidth=1;
bio(35).sigAddress='&forced_choice_B.Sum5';

bio(36).blkName='Force//Torque Transform/Sum6';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[1,1];
bio(36).sigWidth=1;
bio(36).sigAddress='&forced_choice_B.Sum6';

bio(37).blkName='Pos2VelX/Derivative';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[1,1];
bio(37).sigWidth=1;
bio(37).sigAddress='&forced_choice_B.Derivative';

bio(38).blkName='Pos2VelX/dG';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&forced_choice_B.dG';

bio(39).blkName='Pos2VelX/Digital Filter';
bio(39).sigName='';
bio(39).portIdx=0;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&forced_choice_B.DigitalFilter';

bio(40).blkName='Pos2VelX/Digital Filter2';
bio(40).sigName='';
bio(40).portIdx=0;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&forced_choice_B.DigitalFilter2';

bio(41).blkName='Pos2VelY/Derivative';
bio(41).sigName='';
bio(41).portIdx=0;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&forced_choice_B.Derivative_l';

bio(42).blkName='Pos2VelY/dG';
bio(42).sigName='';
bio(42).portIdx=0;
bio(42).dim=[1,1];
bio(42).sigWidth=1;
bio(42).sigAddress='&forced_choice_B.dG_k';

bio(43).blkName='Pos2VelY/Digital Filter';
bio(43).sigName='';
bio(43).portIdx=0;
bio(43).dim=[1,1];
bio(43).sigWidth=1;
bio(43).sigAddress='&forced_choice_B.DigitalFilter_g';

bio(44).blkName='Pos2VelY/Digital Filter2';
bio(44).sigName='';
bio(44).portIdx=0;
bio(44).dim=[1,1];
bio(44).sigWidth=1;
bio(44).sigAddress='&forced_choice_B.DigitalFilter2_d';

bio(45).blkName='RewardSbs/Data Type Conversion';
bio(45).sigName='';
bio(45).portIdx=0;
bio(45).dim=[1,1];
bio(45).sigWidth=1;
bio(45).sigAddress='&forced_choice_B.DataTypeConversion';

bio(46).blkName='RewardSbs/Memory1';
bio(46).sigName='';
bio(46).portIdx=0;
bio(46).dim=[1,1];
bio(46).sigWidth=1;
bio(46).sigAddress='&forced_choice_B.Memory1';

bio(47).blkName='Schmidt/Clock';
bio(47).sigName='';
bio(47).portIdx=0;
bio(47).dim=[1,1];
bio(47).sigWidth=1;
bio(47).sigAddress='&forced_choice_B.Clock';

bio(48).blkName='Schmidt/Logical Operator';
bio(48).sigName='';
bio(48).portIdx=0;
bio(48).dim=[1,1];
bio(48).sigWidth=1;
bio(48).sigAddress='&forced_choice_B.LogicalOperator';

bio(49).blkName='Schmidt/Logical Operator1';
bio(49).sigName='';
bio(49).portIdx=0;
bio(49).dim=[1,1];
bio(49).sigWidth=1;
bio(49).sigAddress='&forced_choice_B.LogicalOperator1';

bio(50).blkName='Schmidt/Logical Operator2';
bio(50).sigName='';
bio(50).portIdx=0;
bio(50).dim=[1,1];
bio(50).sigWidth=1;
bio(50).sigAddress='&forced_choice_B.LogicalOperator2';

bio(51).blkName='Schmidt/Memory';
bio(51).sigName='';
bio(51).portIdx=0;
bio(51).dim=[1,1];
bio(51).sigWidth=1;
bio(51).sigAddress='&forced_choice_B.Memory';

bio(52).blkName='Schmidt/Relational Operator';
bio(52).sigName='';
bio(52).portIdx=0;
bio(52).dim=[1,1];
bio(52).sigWidth=1;
bio(52).sigAddress='&forced_choice_B.RelationalOperator';

bio(53).blkName='Schmidt/Sum';
bio(53).sigName='';
bio(53).portIdx=0;
bio(53).dim=[1,1];
bio(53).sigWidth=1;
bio(53).sigAddress='&forced_choice_B.Sum';

bio(54).blkName='Target Peek/Gain';
bio(54).sigName='';
bio(54).portIdx=0;
bio(54).dim=[1,1];
bio(54).sigWidth=1;
bio(54).sigAddress='&forced_choice_B.Gain_n';

bio(55).blkName='Target Peek/Gain1';
bio(55).sigName='';
bio(55).portIdx=0;
bio(55).dim=[1,1];
bio(55).sigWidth=1;
bio(55).sigAddress='&forced_choice_B.Gain1_d';

bio(56).blkName='Target Peek/Add';
bio(56).sigName='';
bio(56).portIdx=0;
bio(56).dim=[1,1];
bio(56).sigWidth=1;
bio(56).sigAddress='&forced_choice_B.Add_n';

bio(57).blkName='Target Peek/Add1';
bio(57).sigName='';
bio(57).portIdx=0;
bio(57).dim=[1,1];
bio(57).sigWidth=1;
bio(57).sigAddress='&forced_choice_B.Add1_m';

bio(58).blkName='UDPXmit/Rate Transition';
bio(58).sigName='';
bio(58).portIdx=0;
bio(58).dim=[112,1];
bio(58).sigWidth=112;
bio(58).sigAddress='&forced_choice_B.RateTransition[0]';

bio(59).blkName='UDPXmit/Pack';
bio(59).sigName='';
bio(59).portIdx=0;
bio(59).dim=[112,1];
bio(59).sigWidth=112;
bio(59).sigAddress='&forced_choice_B.Pack[0]';

bio(60).blkName='WordSbs/ToBits/p1';
bio(60).sigName='';
bio(60).portIdx=0;
bio(60).dim=[1,1];
bio(60).sigWidth=1;
bio(60).sigAddress='&forced_choice_B.ToBits_o1';

bio(61).blkName='WordSbs/ToBits/p2';
bio(61).sigName='';
bio(61).portIdx=1;
bio(61).dim=[1,1];
bio(61).sigWidth=1;
bio(61).sigAddress='&forced_choice_B.ToBits_o2';

bio(62).blkName='WordSbs/ToBits/p3';
bio(62).sigName='';
bio(62).portIdx=2;
bio(62).dim=[1,1];
bio(62).sigWidth=1;
bio(62).sigAddress='&forced_choice_B.ToBits_o3';

bio(63).blkName='WordSbs/ToBits/p4';
bio(63).sigName='';
bio(63).portIdx=3;
bio(63).dim=[1,1];
bio(63).sigWidth=1;
bio(63).sigAddress='&forced_choice_B.ToBits_o4';

bio(64).blkName='WordSbs/ToBits/p5';
bio(64).sigName='';
bio(64).portIdx=4;
bio(64).dim=[1,1];
bio(64).sigWidth=1;
bio(64).sigAddress='&forced_choice_B.ToBits_o5';

bio(65).blkName='WordSbs/ToBits/p6';
bio(65).sigName='';
bio(65).portIdx=5;
bio(65).dim=[1,1];
bio(65).sigWidth=1;
bio(65).sigAddress='&forced_choice_B.ToBits_o6';

bio(66).blkName='WordSbs/ToBits/p7';
bio(66).sigName='';
bio(66).portIdx=6;
bio(66).dim=[1,1];
bio(66).sigWidth=1;
bio(66).sigAddress='&forced_choice_B.ToBits_o7';

bio(67).blkName='WordSbs/ToBits/p8';
bio(67).sigName='';
bio(67).portIdx=7;
bio(67).dim=[1,1];
bio(67).sigWidth=1;
bio(67).sigAddress='&forced_choice_B.ToBits_o8';

bio(68).blkName='XY Position Subsystem/Gain';
bio(68).sigName='';
bio(68).portIdx=0;
bio(68).dim=[1,1];
bio(68).sigWidth=1;
bio(68).sigAddress='&forced_choice_B.Gain';

bio(69).blkName='XY Position Subsystem/Gain1';
bio(69).sigName='';
bio(69).portIdx=0;
bio(69).dim=[1,1];
bio(69).sigWidth=1;
bio(69).sigAddress='&forced_choice_B.Gain1';

bio(70).blkName='XY Position Subsystem/PCI-QUAD04 ';
bio(70).sigName='';
bio(70).portIdx=0;
bio(70).dim=[1,1];
bio(70).sigWidth=1;
bio(70).sigAddress='&forced_choice_B.PCIQUAD04';

bio(71).blkName='XY Position Subsystem/PCI-QUAD04 1';
bio(71).sigName='';
bio(71).portIdx=0;
bio(71).dim=[1,1];
bio(71).sigWidth=1;
bio(71).sigAddress='&forced_choice_B.PCIQUAD041';

bio(72).blkName='XY Position Subsystem/Sum1';
bio(72).sigName='';
bio(72).portIdx=0;
bio(72).dim=[1,1];
bio(72).sigWidth=1;
bio(72).sigAddress='&forced_choice_B.Sum1';

bio(73).blkName='XY Position Subsystem/Sum3';
bio(73).sigName='';
bio(73).portIdx=0;
bio(73).dim=[1,1];
bio(73).sigWidth=1;
bio(73).sigAddress='&forced_choice_B.Sum3';

bio(74).blkName='Force Generator/LorentzForce/Add';
bio(74).sigName='';
bio(74).portIdx=0;
bio(74).dim=[1,1];
bio(74).sigWidth=1;
bio(74).sigAddress='&forced_choice_B.Add';

bio(75).blkName='Force Generator/LorentzForce/Add1';
bio(75).sigName='';
bio(75).portIdx=0;
bio(75).dim=[1,1];
bio(75).sigWidth=1;
bio(75).sigAddress='&forced_choice_B.Add1';

bio(76).blkName='Force Generator/ViscLoadSubsystem/Gain';
bio(76).sigName='';
bio(76).portIdx=0;
bio(76).dim=[2,1];
bio(76).sigWidth=2;
bio(76).sigAddress='&forced_choice_B.Gain_l[0]';

bio(77).blkName='Force Generator/ViscLoadSubsystem/Product';
bio(77).sigName='';
bio(77).portIdx=0;
bio(77).dim=[1,1];
bio(77).sigWidth=1;
bio(77).sigAddress='&forced_choice_B.Product_h';

bio(78).blkName='Force Generator/ViscLoadSubsystem/Product1';
bio(78).sigName='';
bio(78).portIdx=0;
bio(78).dim=[1,1];
bio(78).sigWidth=1;
bio(78).sigAddress='&forced_choice_B.Product1_h';

bio(79).blkName='Force Generator/ViscLoadSubsystem/Product2';
bio(79).sigName='';
bio(79).portIdx=0;
bio(79).dim=[1,1];
bio(79).sigWidth=1;
bio(79).sigAddress='&forced_choice_B.Product2_p';

bio(80).blkName='Force Generator/ViscLoadSubsystem/Product3';
bio(80).sigName='';
bio(80).portIdx=0;
bio(80).dim=[1,1];
bio(80).sigWidth=1;
bio(80).sigAddress='&forced_choice_B.Product3_g';

bio(81).blkName='Force Generator/ViscLoadSubsystem/Add';
bio(81).sigName='';
bio(81).portIdx=0;
bio(81).dim=[1,1];
bio(81).sigWidth=1;
bio(81).sigAddress='&forced_choice_B.Add_f';

bio(82).blkName='Force Generator/ViscLoadSubsystem/Subtract';
bio(82).sigName='';
bio(82).portIdx=0;
bio(82).dim=[1,1];
bio(82).sigWidth=1;
bio(82).sigAddress='&forced_choice_B.Subtract_b';

bio(83).blkName='Force Generator/ViscLoadSubsystem/cos';
bio(83).sigName='';
bio(83).portIdx=0;
bio(83).dim=[1,1];
bio(83).sigWidth=1;
bio(83).sigAddress='&forced_choice_B.cos_n';

bio(84).blkName='Force Generator/ViscLoadSubsystem/sin';
bio(84).sigName='';
bio(84).portIdx=0;
bio(84).dim=[1,1];
bio(84).sigWidth=1;
bio(84).sigAddress='&forced_choice_B.sin_c';

bio(85).blkName='RewardSbs/Schmidt1/Clock';
bio(85).sigName='';
bio(85).portIdx=0;
bio(85).dim=[1,1];
bio(85).sigWidth=1;
bio(85).sigAddress='&forced_choice_B.Clock_k';

bio(86).blkName='RewardSbs/Schmidt1/Logical Operator';
bio(86).sigName='';
bio(86).portIdx=0;
bio(86).dim=[1,1];
bio(86).sigWidth=1;
bio(86).sigAddress='&forced_choice_B.LogicalOperator_a';

bio(87).blkName='RewardSbs/Schmidt1/Logical Operator1';
bio(87).sigName='';
bio(87).portIdx=0;
bio(87).dim=[1,1];
bio(87).sigWidth=1;
bio(87).sigAddress='&forced_choice_B.LogicalOperator1_m';

bio(88).blkName='RewardSbs/Schmidt1/Logical Operator2';
bio(88).sigName='';
bio(88).portIdx=0;
bio(88).dim=[1,1];
bio(88).sigWidth=1;
bio(88).sigAddress='&forced_choice_B.LogicalOperator2_h';

bio(89).blkName='RewardSbs/Schmidt1/Memory';
bio(89).sigName='';
bio(89).portIdx=0;
bio(89).dim=[1,1];
bio(89).sigWidth=1;
bio(89).sigAddress='&forced_choice_B.Memory_f';

bio(90).blkName='RewardSbs/Schmidt1/Relational Operator';
bio(90).sigName='';
bio(90).portIdx=0;
bio(90).dim=[1,1];
bio(90).sigWidth=1;
bio(90).sigAddress='&forced_choice_B.RelationalOperator_m';

bio(91).blkName='RewardSbs/Schmidt1/Sum';
bio(91).sigName='';
bio(91).portIdx=0;
bio(91).dim=[1,1];
bio(91).sigWidth=1;
bio(91).sigAddress='&forced_choice_B.Sum_l';

bio(92).blkName='Schmidt/Compare To Zero/Compare';
bio(92).sigName='';
bio(92).portIdx=0;
bio(92).dim=[1,1];
bio(92).sigWidth=1;
bio(92).sigAddress='&forced_choice_B.Compare';

bio(93).blkName='Schmidt/Enabled Subsystem/In1';
bio(93).sigName='';
bio(93).portIdx=0;
bio(93).dim=[1,1];
bio(93).sigWidth=1;
bio(93).sigAddress='&forced_choice_B.EnabledSubsystem.In1';

bio(94).blkName='XY Position Subsystem/Cursor Rotation/sqrt(u[1]*u[1] + u[2]*u[2])';
bio(94).sigName='';
bio(94).portIdx=0;
bio(94).dim=[1,1];
bio(94).sigWidth=1;
bio(94).sigAddress='&forced_choice_B.sqrtu1u1u2u2';

bio(95).blkName='XY Position Subsystem/Cursor Rotation/Product';
bio(95).sigName='';
bio(95).portIdx=0;
bio(95).dim=[1,1];
bio(95).sigWidth=1;
bio(95).sigAddress='&forced_choice_B.Product';

bio(96).blkName='XY Position Subsystem/Cursor Rotation/Product1';
bio(96).sigName='';
bio(96).portIdx=0;
bio(96).dim=[1,1];
bio(96).sigWidth=1;
bio(96).sigAddress='&forced_choice_B.Product1';

bio(97).blkName='XY Position Subsystem/Cursor Rotation/Sum';
bio(97).sigName='';
bio(97).portIdx=0;
bio(97).dim=[1,1];
bio(97).sigWidth=1;
bio(97).sigAddress='&forced_choice_B.Sum_f';

bio(98).blkName='XY Position Subsystem/Cursor Rotation/Trigonometric Function';
bio(98).sigName='';
bio(98).portIdx=0;
bio(98).dim=[1,1];
bio(98).sigWidth=1;
bio(98).sigAddress='&forced_choice_B.TrigonometricFunction';

bio(99).blkName='XY Position Subsystem/Cursor Rotation/Trigonometric Function1';
bio(99).sigName='';
bio(99).portIdx=0;
bio(99).dim=[1,1];
bio(99).sigWidth=1;
bio(99).sigAddress='&forced_choice_B.TrigonometricFunction1';

bio(100).blkName='XY Position Subsystem/Cursor Rotation/Trigonometric Function2';
bio(100).sigName='';
bio(100).portIdx=0;
bio(100).dim=[1,1];
bio(100).sigWidth=1;
bio(100).sigAddress='&forced_choice_B.TrigonometricFunction2';

bio(101).blkName='XY Position Subsystem/For Iterator Subsystem/For Iterator';
bio(101).sigName='';
bio(101).portIdx=0;
bio(101).dim=[1,1];
bio(101).sigWidth=1;
bio(101).sigAddress='&forced_choice_B.ForIterator';

bio(102).blkName='XY Position Subsystem/For Iterator Subsystem/SerialConverter';
bio(102).sigName='';
bio(102).portIdx=0;
bio(102).dim=[1,1];
bio(102).sigWidth=1;
bio(102).sigAddress='&forced_choice_B.SerialConverter';

bio(103).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p1';
bio(103).sigName='';
bio(103).portIdx=0;
bio(103).dim=[1,1];
bio(103).sigWidth=1;
bio(103).sigAddress='&forced_choice_B.ToBits_o1_n';

bio(104).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p2';
bio(104).sigName='';
bio(104).portIdx=1;
bio(104).dim=[1,1];
bio(104).sigWidth=1;
bio(104).sigAddress='&forced_choice_B.ToBits_o2_l';

bio(105).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p3';
bio(105).sigName='';
bio(105).portIdx=2;
bio(105).dim=[1,1];
bio(105).sigWidth=1;
bio(105).sigAddress='&forced_choice_B.ToBits_o3_f';

bio(106).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p4';
bio(106).sigName='';
bio(106).portIdx=3;
bio(106).dim=[1,1];
bio(106).sigWidth=1;
bio(106).sigAddress='&forced_choice_B.ToBits_o4_k';

bio(107).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p5';
bio(107).sigName='';
bio(107).portIdx=4;
bio(107).dim=[1,1];
bio(107).sigWidth=1;
bio(107).sigAddress='&forced_choice_B.ToBits_o5_a';

bio(108).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p6';
bio(108).sigName='';
bio(108).portIdx=5;
bio(108).dim=[1,1];
bio(108).sigWidth=1;
bio(108).sigAddress='&forced_choice_B.ToBits_o6_o';

bio(109).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p7';
bio(109).sigName='';
bio(109).portIdx=6;
bio(109).dim=[1,1];
bio(109).sigWidth=1;
bio(109).sigAddress='&forced_choice_B.ToBits_o7_h';

bio(110).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p8';
bio(110).sigName='';
bio(110).portIdx=7;
bio(110).dim=[1,1];
bio(110).sigWidth=1;
bio(110).sigAddress='&forced_choice_B.ToBits_o8_e';

bio(111).blkName='XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ';
bio(111).sigName='';
bio(111).portIdx=0;
bio(111).dim=[1,1];
bio(111).sigWidth=1;
bio(111).sigAddress='&forced_choice_B.xPCTargetTime';

bio(112).blkName='XY Position Subsystem/For Iterator Subsystem/Add';
bio(112).sigName='';
bio(112).portIdx=0;
bio(112).dim=[1,1];
bio(112).sigWidth=1;
bio(112).sigAddress='&forced_choice_B.Add_i';

bio(113).blkName='XY Position Subsystem/For Iterator Subsystem/Add1';
bio(113).sigName='';
bio(113).portIdx=0;
bio(113).dim=[1,1];
bio(113).sigWidth=1;
bio(113).sigAddress='&forced_choice_B.Add1_k';

bio(114).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/cos(length of Elbow)';
bio(114).sigName='';
bio(114).portIdx=0;
bio(114).dim=[1,1];
bio(114).sigWidth=1;
bio(114).sigAddress='&forced_choice_B.coslengthofElbow';

bio(115).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/cos(length of Shoulder)';
bio(115).sigName='';
bio(115).portIdx=0;
bio(115).dim=[1,1];
bio(115).sigWidth=1;
bio(115).sigAddress='&forced_choice_B.coslengthofShoulder';

bio(116).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/sin(length of Elbow)';
bio(116).sigName='';
bio(116).portIdx=0;
bio(116).dim=[1,1];
bio(116).sigWidth=1;
bio(116).sigAddress='&forced_choice_B.sinlengthofElbow';

bio(117).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/sin(length of Shoulder)';
bio(117).sigName='';
bio(117).portIdx=0;
bio(117).dim=[1,1];
bio(117).sigWidth=1;
bio(117).sigAddress='&forced_choice_B.sinlengthofShoulder';

bio(118).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum1';
bio(118).sigName='';
bio(118).portIdx=0;
bio(118).dim=[1,1];
bio(118).sigWidth=1;
bio(118).sigAddress='&forced_choice_B.Sum1_a';

bio(119).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum2';
bio(119).sigName='';
bio(119).portIdx=0;
bio(119).dim=[1,1];
bio(119).sigWidth=1;
bio(119).sigAddress='&forced_choice_B.Sum2';

bio(120).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum3';
bio(120).sigName='';
bio(120).portIdx=0;
bio(120).dim=[1,1];
bio(120).sigWidth=1;
bio(120).sigAddress='&forced_choice_B.Sum3_n';

bio(121).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum4';
bio(121).sigName='';
bio(121).portIdx=0;
bio(121).dim=[1,1];
bio(121).sigWidth=1;
bio(121).sigAddress='&forced_choice_B.Sum4';

bio(122).blkName='Force Generator/LorentzForce/Lorentz/dX';
bio(122).sigName='';
bio(122).portIdx=0;
bio(122).dim=[1,1];
bio(122).sigWidth=1;
bio(122).sigAddress='&forced_choice_B.dX';

bio(123).blkName='Force Generator/LorentzForce/Lorentz/dY';
bio(123).sigName='';
bio(123).portIdx=0;
bio(123).dim=[1,1];
bio(123).sigWidth=1;
bio(123).sigAddress='&forced_choice_B.dY';

bio(124).blkName='Force Generator/LorentzForce/Lorentz/dZ';
bio(124).sigName='';
bio(124).portIdx=0;
bio(124).dim=[1,1];
bio(124).sigWidth=1;
bio(124).sigAddress='&forced_choice_B.dZ';

bio(125).blkName='Force Generator/LorentzForce/Lorentz/product1';
bio(125).sigName='';
bio(125).portIdx=0;
bio(125).dim=[1,1];
bio(125).sigWidth=1;
bio(125).sigAddress='&forced_choice_B.product1';

bio(126).blkName='Force Generator/LorentzForce/Lorentz/product2';
bio(126).sigName='';
bio(126).portIdx=0;
bio(126).dim=[1,1];
bio(126).sigWidth=1;
bio(126).sigAddress='&forced_choice_B.product2';

bio(127).blkName='Force Generator/LorentzForce/Lorentz/product3';
bio(127).sigName='';
bio(127).portIdx=0;
bio(127).dim=[1,1];
bio(127).sigWidth=1;
bio(127).sigAddress='&forced_choice_B.product3';

bio(128).blkName='Force Generator/LorentzForce/Lorentz/product4';
bio(128).sigName='';
bio(128).portIdx=0;
bio(128).dim=[1,1];
bio(128).sigWidth=1;
bio(128).sigAddress='&forced_choice_B.product4';

bio(129).blkName='Force Generator/LorentzForce/Lorentz/Add1';
bio(129).sigName='';
bio(129).portIdx=0;
bio(129).dim=[1,1];
bio(129).sigWidth=1;
bio(129).sigAddress='&forced_choice_B.Add1_o';

bio(130).blkName='Force Generator/LorentzForce/Lorentz/Add2';
bio(130).sigName='';
bio(130).portIdx=0;
bio(130).dim=[1,1];
bio(130).sigWidth=1;
bio(130).sigAddress='&forced_choice_B.Add2';

bio(131).blkName='Force Generator/LorentzForce/Lorentz/Add3';
bio(131).sigName='';
bio(131).portIdx=0;
bio(131).dim=[1,1];
bio(131).sigWidth=1;
bio(131).sigAddress='&forced_choice_B.Add3';

bio(132).blkName='Force Generator/LorentzForce/Lorentz/Add4';
bio(132).sigName='';
bio(132).portIdx=0;
bio(132).dim=[1,1];
bio(132).sigWidth=1;
bio(132).sigAddress='&forced_choice_B.Add4';

bio(133).blkName='Force Generator/LorentzForce/Lorentz/AddX';
bio(133).sigName='';
bio(133).portIdx=0;
bio(133).dim=[1,1];
bio(133).sigWidth=1;
bio(133).sigAddress='&forced_choice_B.AddX';

bio(134).blkName='Force Generator/LorentzForce/Lorentz/AddX1';
bio(134).sigName='';
bio(134).portIdx=0;
bio(134).dim=[1,1];
bio(134).sigWidth=1;
bio(134).sigAddress='&forced_choice_B.AddX1';

bio(135).blkName='Force Generator/LorentzForce/Lorentz/AddX2';
bio(135).sigName='';
bio(135).portIdx=0;
bio(135).dim=[1,1];
bio(135).sigWidth=1;
bio(135).sigAddress='&forced_choice_B.AddX2';

bio(136).blkName='Force Generator/LorentzForce/Lorentz/x';
bio(136).sigName='';
bio(136).portIdx=0;
bio(136).dim=[1,1];
bio(136).sigWidth=1;
bio(136).sigAddress='&forced_choice_B.x';

bio(137).blkName='Force Generator/LorentzForce/Lorentz/y';
bio(137).sigName='';
bio(137).portIdx=0;
bio(137).dim=[1,1];
bio(137).sigWidth=1;
bio(137).sigAddress='&forced_choice_B.y';

bio(138).blkName='Force Generator/LorentzForce/Lorentz/z';
bio(138).sigName='';
bio(138).portIdx=0;
bio(138).dim=[1,1];
bio(138).sigWidth=1;
bio(138).sigAddress='&forced_choice_B.z';

bio(139).blkName='Force Generator/LorentzForce/Lorentz1/dX';
bio(139).sigName='';
bio(139).portIdx=0;
bio(139).dim=[1,1];
bio(139).sigWidth=1;
bio(139).sigAddress='&forced_choice_B.dX_i';

bio(140).blkName='Force Generator/LorentzForce/Lorentz1/dY';
bio(140).sigName='';
bio(140).portIdx=0;
bio(140).dim=[1,1];
bio(140).sigWidth=1;
bio(140).sigAddress='&forced_choice_B.dY_g';

bio(141).blkName='Force Generator/LorentzForce/Lorentz1/dZ';
bio(141).sigName='';
bio(141).portIdx=0;
bio(141).dim=[1,1];
bio(141).sigWidth=1;
bio(141).sigAddress='&forced_choice_B.dZ_k';

bio(142).blkName='Force Generator/LorentzForce/Lorentz1/product1';
bio(142).sigName='';
bio(142).portIdx=0;
bio(142).dim=[1,1];
bio(142).sigWidth=1;
bio(142).sigAddress='&forced_choice_B.product1_k';

bio(143).blkName='Force Generator/LorentzForce/Lorentz1/product2';
bio(143).sigName='';
bio(143).portIdx=0;
bio(143).dim=[1,1];
bio(143).sigWidth=1;
bio(143).sigAddress='&forced_choice_B.product2_n';

bio(144).blkName='Force Generator/LorentzForce/Lorentz1/product3';
bio(144).sigName='';
bio(144).portIdx=0;
bio(144).dim=[1,1];
bio(144).sigWidth=1;
bio(144).sigAddress='&forced_choice_B.product3_b';

bio(145).blkName='Force Generator/LorentzForce/Lorentz1/product4';
bio(145).sigName='';
bio(145).portIdx=0;
bio(145).dim=[1,1];
bio(145).sigWidth=1;
bio(145).sigAddress='&forced_choice_B.product4_n';

bio(146).blkName='Force Generator/LorentzForce/Lorentz1/Add1';
bio(146).sigName='';
bio(146).portIdx=0;
bio(146).dim=[1,1];
bio(146).sigWidth=1;
bio(146).sigAddress='&forced_choice_B.Add1_e';

bio(147).blkName='Force Generator/LorentzForce/Lorentz1/Add2';
bio(147).sigName='';
bio(147).portIdx=0;
bio(147).dim=[1,1];
bio(147).sigWidth=1;
bio(147).sigAddress='&forced_choice_B.Add2_d';

bio(148).blkName='Force Generator/LorentzForce/Lorentz1/Add3';
bio(148).sigName='';
bio(148).portIdx=0;
bio(148).dim=[1,1];
bio(148).sigWidth=1;
bio(148).sigAddress='&forced_choice_B.Add3_n';

bio(149).blkName='Force Generator/LorentzForce/Lorentz1/Add4';
bio(149).sigName='';
bio(149).portIdx=0;
bio(149).dim=[1,1];
bio(149).sigWidth=1;
bio(149).sigAddress='&forced_choice_B.Add4_c';

bio(150).blkName='Force Generator/LorentzForce/Lorentz1/AddX';
bio(150).sigName='';
bio(150).portIdx=0;
bio(150).dim=[1,1];
bio(150).sigWidth=1;
bio(150).sigAddress='&forced_choice_B.AddX_m';

bio(151).blkName='Force Generator/LorentzForce/Lorentz1/AddX1';
bio(151).sigName='';
bio(151).portIdx=0;
bio(151).dim=[1,1];
bio(151).sigWidth=1;
bio(151).sigAddress='&forced_choice_B.AddX1_j';

bio(152).blkName='Force Generator/LorentzForce/Lorentz1/AddX2';
bio(152).sigName='';
bio(152).portIdx=0;
bio(152).dim=[1,1];
bio(152).sigWidth=1;
bio(152).sigAddress='&forced_choice_B.AddX2_j';

bio(153).blkName='Force Generator/LorentzForce/Lorentz1/x';
bio(153).sigName='';
bio(153).portIdx=0;
bio(153).dim=[1,1];
bio(153).sigWidth=1;
bio(153).sigAddress='&forced_choice_B.x_h';

bio(154).blkName='Force Generator/LorentzForce/Lorentz1/y';
bio(154).sigName='';
bio(154).portIdx=0;
bio(154).dim=[1,1];
bio(154).sigWidth=1;
bio(154).sigAddress='&forced_choice_B.y_p';

bio(155).blkName='Force Generator/LorentzForce/Lorentz1/z';
bio(155).sigName='';
bio(155).portIdx=0;
bio(155).dim=[1,1];
bio(155).sigWidth=1;
bio(155).sigAddress='&forced_choice_B.z_m';

bio(156).blkName='Force Generator/LorentzForce/Lorentz2/dX';
bio(156).sigName='';
bio(156).portIdx=0;
bio(156).dim=[1,1];
bio(156).sigWidth=1;
bio(156).sigAddress='&forced_choice_B.dX_l';

bio(157).blkName='Force Generator/LorentzForce/Lorentz2/dY';
bio(157).sigName='';
bio(157).portIdx=0;
bio(157).dim=[1,1];
bio(157).sigWidth=1;
bio(157).sigAddress='&forced_choice_B.dY_o';

bio(158).blkName='Force Generator/LorentzForce/Lorentz2/dZ';
bio(158).sigName='';
bio(158).portIdx=0;
bio(158).dim=[1,1];
bio(158).sigWidth=1;
bio(158).sigAddress='&forced_choice_B.dZ_f';

bio(159).blkName='Force Generator/LorentzForce/Lorentz2/product1';
bio(159).sigName='';
bio(159).portIdx=0;
bio(159).dim=[1,1];
bio(159).sigWidth=1;
bio(159).sigAddress='&forced_choice_B.product1_b';

bio(160).blkName='Force Generator/LorentzForce/Lorentz2/product2';
bio(160).sigName='';
bio(160).portIdx=0;
bio(160).dim=[1,1];
bio(160).sigWidth=1;
bio(160).sigAddress='&forced_choice_B.product2_a';

bio(161).blkName='Force Generator/LorentzForce/Lorentz2/product3';
bio(161).sigName='';
bio(161).portIdx=0;
bio(161).dim=[1,1];
bio(161).sigWidth=1;
bio(161).sigAddress='&forced_choice_B.product3_c';

bio(162).blkName='Force Generator/LorentzForce/Lorentz2/product4';
bio(162).sigName='';
bio(162).portIdx=0;
bio(162).dim=[1,1];
bio(162).sigWidth=1;
bio(162).sigAddress='&forced_choice_B.product4_c';

bio(163).blkName='Force Generator/LorentzForce/Lorentz2/Add1';
bio(163).sigName='';
bio(163).portIdx=0;
bio(163).dim=[1,1];
bio(163).sigWidth=1;
bio(163).sigAddress='&forced_choice_B.Add1_l';

bio(164).blkName='Force Generator/LorentzForce/Lorentz2/Add2';
bio(164).sigName='';
bio(164).portIdx=0;
bio(164).dim=[1,1];
bio(164).sigWidth=1;
bio(164).sigAddress='&forced_choice_B.Add2_k';

bio(165).blkName='Force Generator/LorentzForce/Lorentz2/Add3';
bio(165).sigName='';
bio(165).portIdx=0;
bio(165).dim=[1,1];
bio(165).sigWidth=1;
bio(165).sigAddress='&forced_choice_B.Add3_k';

bio(166).blkName='Force Generator/LorentzForce/Lorentz2/Add4';
bio(166).sigName='';
bio(166).portIdx=0;
bio(166).dim=[1,1];
bio(166).sigWidth=1;
bio(166).sigAddress='&forced_choice_B.Add4_i';

bio(167).blkName='Force Generator/LorentzForce/Lorentz2/AddX';
bio(167).sigName='';
bio(167).portIdx=0;
bio(167).dim=[1,1];
bio(167).sigWidth=1;
bio(167).sigAddress='&forced_choice_B.AddX_k';

bio(168).blkName='Force Generator/LorentzForce/Lorentz2/AddX1';
bio(168).sigName='';
bio(168).portIdx=0;
bio(168).dim=[1,1];
bio(168).sigWidth=1;
bio(168).sigAddress='&forced_choice_B.AddX1_k';

bio(169).blkName='Force Generator/LorentzForce/Lorentz2/AddX2';
bio(169).sigName='';
bio(169).portIdx=0;
bio(169).dim=[1,1];
bio(169).sigWidth=1;
bio(169).sigAddress='&forced_choice_B.AddX2_b';

bio(170).blkName='Force Generator/LorentzForce/Lorentz2/x';
bio(170).sigName='';
bio(170).portIdx=0;
bio(170).dim=[1,1];
bio(170).sigWidth=1;
bio(170).sigAddress='&forced_choice_B.x_m';

bio(171).blkName='Force Generator/LorentzForce/Lorentz2/y';
bio(171).sigName='';
bio(171).portIdx=0;
bio(171).dim=[1,1];
bio(171).sigWidth=1;
bio(171).sigAddress='&forced_choice_B.y_e';

bio(172).blkName='Force Generator/LorentzForce/Lorentz2/z';
bio(172).sigName='';
bio(172).portIdx=0;
bio(172).dim=[1,1];
bio(172).sigWidth=1;
bio(172).sigAddress='&forced_choice_B.z_mc';

bio(173).blkName='Force Generator/LorentzForce/Lorentz3/dX';
bio(173).sigName='';
bio(173).portIdx=0;
bio(173).dim=[1,1];
bio(173).sigWidth=1;
bio(173).sigAddress='&forced_choice_B.dX_a';

bio(174).blkName='Force Generator/LorentzForce/Lorentz3/dY';
bio(174).sigName='';
bio(174).portIdx=0;
bio(174).dim=[1,1];
bio(174).sigWidth=1;
bio(174).sigAddress='&forced_choice_B.dY_p';

bio(175).blkName='Force Generator/LorentzForce/Lorentz3/dZ';
bio(175).sigName='';
bio(175).portIdx=0;
bio(175).dim=[1,1];
bio(175).sigWidth=1;
bio(175).sigAddress='&forced_choice_B.dZ_p';

bio(176).blkName='Force Generator/LorentzForce/Lorentz3/product1';
bio(176).sigName='';
bio(176).portIdx=0;
bio(176).dim=[1,1];
bio(176).sigWidth=1;
bio(176).sigAddress='&forced_choice_B.product1_kd';

bio(177).blkName='Force Generator/LorentzForce/Lorentz3/product2';
bio(177).sigName='';
bio(177).portIdx=0;
bio(177).dim=[1,1];
bio(177).sigWidth=1;
bio(177).sigAddress='&forced_choice_B.product2_j';

bio(178).blkName='Force Generator/LorentzForce/Lorentz3/product3';
bio(178).sigName='';
bio(178).portIdx=0;
bio(178).dim=[1,1];
bio(178).sigWidth=1;
bio(178).sigAddress='&forced_choice_B.product3_a';

bio(179).blkName='Force Generator/LorentzForce/Lorentz3/product4';
bio(179).sigName='';
bio(179).portIdx=0;
bio(179).dim=[1,1];
bio(179).sigWidth=1;
bio(179).sigAddress='&forced_choice_B.product4_p';

bio(180).blkName='Force Generator/LorentzForce/Lorentz3/Add1';
bio(180).sigName='';
bio(180).portIdx=0;
bio(180).dim=[1,1];
bio(180).sigWidth=1;
bio(180).sigAddress='&forced_choice_B.Add1_i';

bio(181).blkName='Force Generator/LorentzForce/Lorentz3/Add2';
bio(181).sigName='';
bio(181).portIdx=0;
bio(181).dim=[1,1];
bio(181).sigWidth=1;
bio(181).sigAddress='&forced_choice_B.Add2_c';

bio(182).blkName='Force Generator/LorentzForce/Lorentz3/Add3';
bio(182).sigName='';
bio(182).portIdx=0;
bio(182).dim=[1,1];
bio(182).sigWidth=1;
bio(182).sigAddress='&forced_choice_B.Add3_d';

bio(183).blkName='Force Generator/LorentzForce/Lorentz3/Add4';
bio(183).sigName='';
bio(183).portIdx=0;
bio(183).dim=[1,1];
bio(183).sigWidth=1;
bio(183).sigAddress='&forced_choice_B.Add4_h';

bio(184).blkName='Force Generator/LorentzForce/Lorentz3/AddX';
bio(184).sigName='';
bio(184).portIdx=0;
bio(184).dim=[1,1];
bio(184).sigWidth=1;
bio(184).sigAddress='&forced_choice_B.AddX_mq';

bio(185).blkName='Force Generator/LorentzForce/Lorentz3/AddX1';
bio(185).sigName='';
bio(185).portIdx=0;
bio(185).dim=[1,1];
bio(185).sigWidth=1;
bio(185).sigAddress='&forced_choice_B.AddX1_e';

bio(186).blkName='Force Generator/LorentzForce/Lorentz3/AddX2';
bio(186).sigName='';
bio(186).portIdx=0;
bio(186).dim=[1,1];
bio(186).sigWidth=1;
bio(186).sigAddress='&forced_choice_B.AddX2_f';

bio(187).blkName='Force Generator/LorentzForce/Lorentz3/x';
bio(187).sigName='';
bio(187).portIdx=0;
bio(187).dim=[1,1];
bio(187).sigWidth=1;
bio(187).sigAddress='&forced_choice_B.x_ho';

bio(188).blkName='Force Generator/LorentzForce/Lorentz3/y';
bio(188).sigName='';
bio(188).portIdx=0;
bio(188).dim=[1,1];
bio(188).sigWidth=1;
bio(188).sigAddress='&forced_choice_B.y_k';

bio(189).blkName='Force Generator/LorentzForce/Lorentz3/z';
bio(189).sigName='';
bio(189).portIdx=0;
bio(189).dim=[1,1];
bio(189).sigWidth=1;
bio(189).sigAddress='&forced_choice_B.z_n';

bio(190).blkName='RewardSbs/Schmidt1/Compare To Zero/Compare';
bio(190).sigName='';
bio(190).portIdx=0;
bio(190).dim=[1,1];
bio(190).sigWidth=1;
bio(190).sigAddress='&forced_choice_B.Compare_b';

bio(191).blkName='RewardSbs/Schmidt1/Enabled Subsystem/In1';
bio(191).sigName='';
bio(191).portIdx=0;
bio(191).dim=[1,1];
bio(191).sigWidth=1;
bio(191).sigAddress='&forced_choice_B.EnabledSubsystem_h.In1';

bio(192).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec';
bio(192).sigName='';
bio(192).portIdx=0;
bio(192).dim=[1,1];
bio(192).sigWidth=1;
bio(192).sigAddress='&forced_choice_B.ScaleTouSec';

bio(193).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ';
bio(193).sigName='';
bio(193).portIdx=0;
bio(193).dim=[1,1];
bio(193).sigWidth=1;
bio(193).sigAddress='&forced_choice_B.xPCTargetTime_n';

bio(194).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Subtract';
bio(194).sigName='';
bio(194).portIdx=0;
bio(194).dim=[1,1];
bio(194).sigWidth=1;
bio(194).sigAddress='&forced_choice_B.Subtract';

bio(195).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Switch';
bio(195).sigName='';
bio(195).portIdx=0;
bio(195).dim=[1,1];
bio(195).sigWidth=1;
bio(195).sigAddress='&forced_choice_B.Switch';

bio(196).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Compare';
bio(196).sigName='';
bio(196).portIdx=0;
bio(196).dim=[1,1];
bio(196).sigWidth=1;
bio(196).sigAddress='&forced_choice_B.Compare_a';

bio(197).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1/Compare';
bio(197).sigName='';
bio(197).portIdx=0;
bio(197).dim=[1,1];
bio(197).sigWidth=1;
bio(197).sigAddress='&forced_choice_B.Compare_p';

function len = getlenBIO
len = 197;

