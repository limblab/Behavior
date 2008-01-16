function bio=random_walkbio
bio = [];
bio(1).blkName='Matrix Concatenation';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[2,1];
bio(1).sigWidth=2;
bio(1).sigAddress='&random_walk_B.MatrixConcatenation[0]';
bio(getlenBIO) = bio(1);

bio(2).blkName='MG1';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&random_walk_B.MG1';

bio(3).blkName='MG2';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&random_walk_B.MG2';

bio(4).blkName='Logical Operator1';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&random_walk_B.LogicalOperator1_c';

bio(5).blkName='Memory';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&random_walk_B.Memory_h';

bio(6).blkName='Rate Transition1';
bio(6).sigName='';
bio(6).portIdx=0;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&random_walk_B.RateTransition1';

bio(7).blkName='Rate Transition2';
bio(7).sigName='';
bio(7).portIdx=0;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&random_walk_B.RateTransition2';

bio(8).blkName='Behavior RW/p1';
bio(8).sigName='';
bio(8).portIdx=0;
bio(8).dim=[2,1];
bio(8).sigWidth=2;
bio(8).sigAddress='&random_walk_B.BehaviorRW_o1[0]';

bio(9).blkName='Behavior RW/p2';
bio(9).sigName='';
bio(9).portIdx=1;
bio(9).dim=[4,1];
bio(9).sigWidth=4;
bio(9).sigAddress='&random_walk_B.BehaviorRW_o2[0]';

bio(10).blkName='Behavior RW/p3';
bio(10).sigName='';
bio(10).portIdx=2;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&random_walk_B.BehaviorRW_o3';

bio(11).blkName='Behavior RW/p4';
bio(11).sigName='';
bio(11).portIdx=3;
bio(11).dim=[10,1];
bio(11).sigWidth=10;
bio(11).sigAddress='&random_walk_B.BehaviorRW_o4[0]';

bio(12).blkName='Behavior RW/p5';
bio(12).sigName='';
bio(12).portIdx=4;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&random_walk_B.BehaviorRW_o5';

bio(13).blkName='Behavior RW/p6';
bio(13).sigName='';
bio(13).portIdx=5;
bio(13).dim=[2,1];
bio(13).sigWidth=2;
bio(13).sigAddress='&random_walk_B.BehaviorRW_o6[0]';

bio(14).blkName='Switch';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[2,1];
bio(14).sigWidth=2;
bio(14).sigAddress='&random_walk_B.Switch_i[0]';

bio(15).blkName='Switch1';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[2,1];
bio(15).sigWidth=2;
bio(15).sigAddress='&random_walk_B.Switch1[0]';

bio(16).blkName='BoundingBox/Logical Operator';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&random_walk_B.LogicalOperator_a';

bio(17).blkName='BoundingBox/Relational Operator';
bio(17).sigName='';
bio(17).portIdx=0;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&random_walk_B.RelationalOperator_n';

bio(18).blkName='BoundingBox/Relational Operator1';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&random_walk_B.RelationalOperator1';

bio(19).blkName='BoundingBox/Relational Operator2';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&random_walk_B.RelationalOperator2';

bio(20).blkName='BoundingBox/Relational Operator3';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&random_walk_B.RelationalOperator3';

bio(21).blkName='Compare To Constant/Compare';
bio(21).sigName='';
bio(21).portIdx=0;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&random_walk_B.Compare_oh';

bio(22).blkName='Compare To Constant1/Compare';
bio(22).sigName='';
bio(22).portIdx=0;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&random_walk_B.Compare_c';

bio(23).blkName='Force Generator/Gain';
bio(23).sigName='';
bio(23).portIdx=0;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&random_walk_B.Gain_d';

bio(24).blkName='Force Generator/LorentzForceGain';
bio(24).sigName='';
bio(24).portIdx=0;
bio(24).dim=[2,1];
bio(24).sigWidth=2;
bio(24).sigAddress='&random_walk_B.LorentzForceGain[0]';

bio(25).blkName='Force Generator/Multiport Switch';
bio(25).sigName='';
bio(25).portIdx=0;
bio(25).dim=[2,1];
bio(25).sigWidth=2;
bio(25).sigAddress='&random_walk_B.MultiportSwitch[0]';

bio(26).blkName='Force Generator/dynamicAngle Switch';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&random_walk_B.dynamicAngleSwitch';

bio(27).blkName='Force outside box/Gain1';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&random_walk_B.Gain1_k';

bio(28).blkName='Force outside box/Gain2';
bio(28).sigName='';
bio(28).portIdx=0;
bio(28).dim=[1,1];
bio(28).sigWidth=1;
bio(28).sigAddress='&random_walk_B.Gain2';

bio(29).blkName='Force outside box/Gain3';
bio(29).sigName='';
bio(29).portIdx=0;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&random_walk_B.Gain3';

bio(30).blkName='Force outside box/Gain4';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&random_walk_B.Gain4';

bio(31).blkName='Force outside box/InBox';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&random_walk_B.InBox';

bio(32).blkName='Force outside box/Logical Operator';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&random_walk_B.LogicalOperator_b';

bio(33).blkName='Force outside box/Logical Operator2';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[1,1];
bio(33).sigWidth=1;
bio(33).sigAddress='&random_walk_B.LogicalOperator2_d';

bio(34).blkName='Force outside box/Logical Operator3';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&random_walk_B.LogicalOperator3_d';

bio(35).blkName='Force outside box/Logical Operator4';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[1,1];
bio(35).sigWidth=1;
bio(35).sigAddress='&random_walk_B.LogicalOperator4_p';

bio(36).blkName='Force outside box/Logical Operator5';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[1,1];
bio(36).sigWidth=1;
bio(36).sigAddress='&random_walk_B.LogicalOperator5_l';

bio(37).blkName='Force outside box/Logical Operator6';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[1,1];
bio(37).sigWidth=1;
bio(37).sigAddress='&random_walk_B.LogicalOperator6';

bio(38).blkName='Force outside box/Product';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&random_walk_B.Product_f';

bio(39).blkName='Force outside box/Product1';
bio(39).sigName='';
bio(39).portIdx=0;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&random_walk_B.Product1_b';

bio(40).blkName='Force outside box/Saturation';
bio(40).sigName='';
bio(40).portIdx=0;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&random_walk_B.Saturation';

bio(41).blkName='Force outside box/Saturation1';
bio(41).sigName='';
bio(41).portIdx=0;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&random_walk_B.Saturation1';

bio(42).blkName='Force outside box/Sum1';
bio(42).sigName='';
bio(42).portIdx=0;
bio(42).dim=[1,1];
bio(42).sigWidth=1;
bio(42).sigAddress='&random_walk_B.Sum1_a';

bio(43).blkName='Force outside box/Sum2';
bio(43).sigName='';
bio(43).portIdx=0;
bio(43).dim=[1,1];
bio(43).sigWidth=1;
bio(43).sigAddress='&random_walk_B.Sum2_f';

bio(44).blkName='Force outside box/Switch';
bio(44).sigName='';
bio(44).portIdx=0;
bio(44).dim=[2,1];
bio(44).sigWidth=2;
bio(44).sigAddress='&random_walk_B.Switch_c[0]';

bio(45).blkName='Force//Torque Transform/cos(length of Elbow)';
bio(45).sigName='';
bio(45).portIdx=0;
bio(45).dim=[1,1];
bio(45).sigWidth=1;
bio(45).sigAddress='&random_walk_B.coslengthofElbow_m';

bio(46).blkName='Force//Torque Transform/cos(length of Shoulder)';
bio(46).sigName='';
bio(46).portIdx=0;
bio(46).dim=[1,1];
bio(46).sigWidth=1;
bio(46).sigAddress='&random_walk_B.coslengthofShoulder_l';

bio(47).blkName='Force//Torque Transform/sin(length of Elbow)';
bio(47).sigName='';
bio(47).portIdx=0;
bio(47).dim=[1,1];
bio(47).sigWidth=1;
bio(47).sigAddress='&random_walk_B.sinlengthofElbow_d';

bio(48).blkName='Force//Torque Transform/sin(length of Shoulder)';
bio(48).sigName='';
bio(48).portIdx=0;
bio(48).dim=[1,1];
bio(48).sigWidth=1;
bio(48).sigAddress='&random_walk_B.sinlengthofShoulder_d';

bio(49).blkName='Force//Torque Transform/Product';
bio(49).sigName='';
bio(49).portIdx=0;
bio(49).dim=[1,1];
bio(49).sigWidth=1;
bio(49).sigAddress='&random_walk_B.Product_h';

bio(50).blkName='Force//Torque Transform/Product1';
bio(50).sigName='';
bio(50).portIdx=0;
bio(50).dim=[1,1];
bio(50).sigWidth=1;
bio(50).sigAddress='&random_walk_B.Product1_e';

bio(51).blkName='Force//Torque Transform/Product2';
bio(51).sigName='';
bio(51).portIdx=0;
bio(51).dim=[1,1];
bio(51).sigWidth=1;
bio(51).sigAddress='&random_walk_B.Product2';

bio(52).blkName='Force//Torque Transform/Product3';
bio(52).sigName='';
bio(52).portIdx=0;
bio(52).dim=[1,1];
bio(52).sigWidth=1;
bio(52).sigAddress='&random_walk_B.Product3';

bio(53).blkName='Force//Torque Transform/Sum5';
bio(53).sigName='';
bio(53).portIdx=0;
bio(53).dim=[1,1];
bio(53).sigWidth=1;
bio(53).sigAddress='&random_walk_B.Sum5';

bio(54).blkName='Force//Torque Transform/Sum6';
bio(54).sigName='';
bio(54).portIdx=0;
bio(54).dim=[1,1];
bio(54).sigWidth=1;
bio(54).sigAddress='&random_walk_B.Sum6';

bio(55).blkName='Pos2VelX/Derivative';
bio(55).sigName='';
bio(55).portIdx=0;
bio(55).dim=[1,1];
bio(55).sigWidth=1;
bio(55).sigAddress='&random_walk_B.Derivative';

bio(56).blkName='Pos2VelX/dG';
bio(56).sigName='';
bio(56).portIdx=0;
bio(56).dim=[1,1];
bio(56).sigWidth=1;
bio(56).sigAddress='&random_walk_B.dG';

bio(57).blkName='Pos2VelX/Digital Filter';
bio(57).sigName='';
bio(57).portIdx=0;
bio(57).dim=[1,1];
bio(57).sigWidth=1;
bio(57).sigAddress='&random_walk_B.DigitalFilter';

bio(58).blkName='Pos2VelX/Digital Filter2';
bio(58).sigName='';
bio(58).portIdx=0;
bio(58).dim=[1,1];
bio(58).sigWidth=1;
bio(58).sigAddress='&random_walk_B.DigitalFilter2';

bio(59).blkName='Pos2VelY/Derivative';
bio(59).sigName='';
bio(59).portIdx=0;
bio(59).dim=[1,1];
bio(59).sigWidth=1;
bio(59).sigAddress='&random_walk_B.Derivative_g';

bio(60).blkName='Pos2VelY/dG';
bio(60).sigName='';
bio(60).portIdx=0;
bio(60).dim=[1,1];
bio(60).sigWidth=1;
bio(60).sigAddress='&random_walk_B.dG_l';

bio(61).blkName='Pos2VelY/Digital Filter';
bio(61).sigName='';
bio(61).portIdx=0;
bio(61).dim=[1,1];
bio(61).sigWidth=1;
bio(61).sigAddress='&random_walk_B.DigitalFilter_m';

bio(62).blkName='Pos2VelY/Digital Filter2';
bio(62).sigName='';
bio(62).portIdx=0;
bio(62).dim=[1,1];
bio(62).sigWidth=1;
bio(62).sigAddress='&random_walk_B.DigitalFilter2_e';

bio(63).blkName='RewardSbs/Data Type Conversion';
bio(63).sigName='';
bio(63).portIdx=0;
bio(63).dim=[1,1];
bio(63).sigWidth=1;
bio(63).sigAddress='&random_walk_B.DataTypeConversion';

bio(64).blkName='RewardSbs/Memory1';
bio(64).sigName='';
bio(64).portIdx=0;
bio(64).dim=[1,1];
bio(64).sigWidth=1;
bio(64).sigAddress='&random_walk_B.Memory1';

bio(65).blkName='Schmidt/Clock';
bio(65).sigName='';
bio(65).portIdx=0;
bio(65).dim=[1,1];
bio(65).sigWidth=1;
bio(65).sigAddress='&random_walk_B.Clock';

bio(66).blkName='Schmidt/Logical Operator';
bio(66).sigName='';
bio(66).portIdx=0;
bio(66).dim=[1,1];
bio(66).sigWidth=1;
bio(66).sigAddress='&random_walk_B.LogicalOperator';

bio(67).blkName='Schmidt/Logical Operator1';
bio(67).sigName='';
bio(67).portIdx=0;
bio(67).dim=[1,1];
bio(67).sigWidth=1;
bio(67).sigAddress='&random_walk_B.LogicalOperator1';

bio(68).blkName='Schmidt/Logical Operator2';
bio(68).sigName='';
bio(68).portIdx=0;
bio(68).dim=[1,1];
bio(68).sigWidth=1;
bio(68).sigAddress='&random_walk_B.LogicalOperator2';

bio(69).blkName='Schmidt/Memory';
bio(69).sigName='';
bio(69).portIdx=0;
bio(69).dim=[1,1];
bio(69).sigWidth=1;
bio(69).sigAddress='&random_walk_B.Memory';

bio(70).blkName='Schmidt/Relational Operator';
bio(70).sigName='';
bio(70).portIdx=0;
bio(70).dim=[1,1];
bio(70).sigWidth=1;
bio(70).sigAddress='&random_walk_B.RelationalOperator';

bio(71).blkName='Schmidt/Sum';
bio(71).sigName='';
bio(71).portIdx=0;
bio(71).dim=[1,1];
bio(71).sigWidth=1;
bio(71).sigAddress='&random_walk_B.Sum';

bio(72).blkName='Target Peek/Gain';
bio(72).sigName='';
bio(72).portIdx=0;
bio(72).dim=[1,1];
bio(72).sigWidth=1;
bio(72).sigAddress='&random_walk_B.Gain_p';

bio(73).blkName='Target Peek/Gain1';
bio(73).sigName='';
bio(73).portIdx=0;
bio(73).dim=[1,1];
bio(73).sigWidth=1;
bio(73).sigAddress='&random_walk_B.Gain1_c';

bio(74).blkName='Target Peek/Add';
bio(74).sigName='';
bio(74).portIdx=0;
bio(74).dim=[1,1];
bio(74).sigWidth=1;
bio(74).sigAddress='&random_walk_B.Add_o';

bio(75).blkName='Target Peek/Add1';
bio(75).sigName='';
bio(75).portIdx=0;
bio(75).dim=[1,1];
bio(75).sigWidth=1;
bio(75).sigAddress='&random_walk_B.Add1_f';

bio(76).blkName='UDPXmit/Rate Transition';
bio(76).sigName='';
bio(76).portIdx=0;
bio(76).dim=[112,1];
bio(76).sigWidth=112;
bio(76).sigAddress='&random_walk_B.RateTransition[0]';

bio(77).blkName='UDPXmit/Pack';
bio(77).sigName='';
bio(77).portIdx=0;
bio(77).dim=[112,1];
bio(77).sigWidth=112;
bio(77).sigAddress='&random_walk_B.Pack[0]';

bio(78).blkName='WordSbs/ToBits/p1';
bio(78).sigName='';
bio(78).portIdx=0;
bio(78).dim=[1,1];
bio(78).sigWidth=1;
bio(78).sigAddress='&random_walk_B.ToBits_o1';

bio(79).blkName='WordSbs/ToBits/p2';
bio(79).sigName='';
bio(79).portIdx=1;
bio(79).dim=[1,1];
bio(79).sigWidth=1;
bio(79).sigAddress='&random_walk_B.ToBits_o2';

bio(80).blkName='WordSbs/ToBits/p3';
bio(80).sigName='';
bio(80).portIdx=2;
bio(80).dim=[1,1];
bio(80).sigWidth=1;
bio(80).sigAddress='&random_walk_B.ToBits_o3';

bio(81).blkName='WordSbs/ToBits/p4';
bio(81).sigName='';
bio(81).portIdx=3;
bio(81).dim=[1,1];
bio(81).sigWidth=1;
bio(81).sigAddress='&random_walk_B.ToBits_o4';

bio(82).blkName='WordSbs/ToBits/p5';
bio(82).sigName='';
bio(82).portIdx=4;
bio(82).dim=[1,1];
bio(82).sigWidth=1;
bio(82).sigAddress='&random_walk_B.ToBits_o5';

bio(83).blkName='WordSbs/ToBits/p6';
bio(83).sigName='';
bio(83).portIdx=5;
bio(83).dim=[1,1];
bio(83).sigWidth=1;
bio(83).sigAddress='&random_walk_B.ToBits_o6';

bio(84).blkName='WordSbs/ToBits/p7';
bio(84).sigName='';
bio(84).portIdx=6;
bio(84).dim=[1,1];
bio(84).sigWidth=1;
bio(84).sigAddress='&random_walk_B.ToBits_o7';

bio(85).blkName='WordSbs/ToBits/p8';
bio(85).sigName='';
bio(85).portIdx=7;
bio(85).dim=[1,1];
bio(85).sigWidth=1;
bio(85).sigAddress='&random_walk_B.ToBits_o8';

bio(86).blkName='XY Position Subsystem/Gain';
bio(86).sigName='';
bio(86).portIdx=0;
bio(86).dim=[1,1];
bio(86).sigWidth=1;
bio(86).sigAddress='&random_walk_B.Gain';

bio(87).blkName='XY Position Subsystem/Gain1';
bio(87).sigName='';
bio(87).portIdx=0;
bio(87).dim=[1,1];
bio(87).sigWidth=1;
bio(87).sigAddress='&random_walk_B.Gain1';

bio(88).blkName='XY Position Subsystem/PCI-QUAD04 ';
bio(88).sigName='';
bio(88).portIdx=0;
bio(88).dim=[1,1];
bio(88).sigWidth=1;
bio(88).sigAddress='&random_walk_B.PCIQUAD04';

bio(89).blkName='XY Position Subsystem/PCI-QUAD04 1';
bio(89).sigName='';
bio(89).portIdx=0;
bio(89).dim=[1,1];
bio(89).sigWidth=1;
bio(89).sigAddress='&random_walk_B.PCIQUAD041';

bio(90).blkName='XY Position Subsystem/Sum1';
bio(90).sigName='';
bio(90).portIdx=0;
bio(90).dim=[1,1];
bio(90).sigWidth=1;
bio(90).sigAddress='&random_walk_B.Sum1';

bio(91).blkName='XY Position Subsystem/Sum3';
bio(91).sigName='';
bio(91).portIdx=0;
bio(91).dim=[1,1];
bio(91).sigWidth=1;
bio(91).sigAddress='&random_walk_B.Sum3';

bio(92).blkName='Force Generator/LorentzForce/Add';
bio(92).sigName='';
bio(92).portIdx=0;
bio(92).dim=[1,1];
bio(92).sigWidth=1;
bio(92).sigAddress='&random_walk_B.Add';

bio(93).blkName='Force Generator/LorentzForce/Add1';
bio(93).sigName='';
bio(93).portIdx=0;
bio(93).dim=[1,1];
bio(93).sigWidth=1;
bio(93).sigAddress='&random_walk_B.Add1';

bio(94).blkName='Force Generator/ViscLoadSubsystem/Gain';
bio(94).sigName='';
bio(94).portIdx=0;
bio(94).dim=[2,1];
bio(94).sigWidth=2;
bio(94).sigAddress='&random_walk_B.Gain_n[0]';

bio(95).blkName='Force Generator/ViscLoadSubsystem/Product';
bio(95).sigName='';
bio(95).portIdx=0;
bio(95).dim=[1,1];
bio(95).sigWidth=1;
bio(95).sigAddress='&random_walk_B.Product_e';

bio(96).blkName='Force Generator/ViscLoadSubsystem/Product1';
bio(96).sigName='';
bio(96).portIdx=0;
bio(96).dim=[1,1];
bio(96).sigWidth=1;
bio(96).sigAddress='&random_walk_B.Product1_f';

bio(97).blkName='Force Generator/ViscLoadSubsystem/Product2';
bio(97).sigName='';
bio(97).portIdx=0;
bio(97).dim=[1,1];
bio(97).sigWidth=1;
bio(97).sigAddress='&random_walk_B.Product2_m';

bio(98).blkName='Force Generator/ViscLoadSubsystem/Product3';
bio(98).sigName='';
bio(98).portIdx=0;
bio(98).dim=[1,1];
bio(98).sigWidth=1;
bio(98).sigAddress='&random_walk_B.Product3_m';

bio(99).blkName='Force Generator/ViscLoadSubsystem/Add';
bio(99).sigName='';
bio(99).portIdx=0;
bio(99).dim=[1,1];
bio(99).sigWidth=1;
bio(99).sigAddress='&random_walk_B.Add_c';

bio(100).blkName='Force Generator/ViscLoadSubsystem/Subtract';
bio(100).sigName='';
bio(100).portIdx=0;
bio(100).dim=[1,1];
bio(100).sigWidth=1;
bio(100).sigAddress='&random_walk_B.Subtract_j';

bio(101).blkName='Force Generator/ViscLoadSubsystem/cos';
bio(101).sigName='';
bio(101).portIdx=0;
bio(101).dim=[1,1];
bio(101).sigWidth=1;
bio(101).sigAddress='&random_walk_B.cos_o';

bio(102).blkName='Force Generator/ViscLoadSubsystem/sin';
bio(102).sigName='';
bio(102).portIdx=0;
bio(102).dim=[1,1];
bio(102).sigWidth=1;
bio(102).sigAddress='&random_walk_B.sin_e';

bio(103).blkName='Force outside box/Compare To Zero/Compare';
bio(103).sigName='';
bio(103).portIdx=0;
bio(103).dim=[1,1];
bio(103).sigWidth=1;
bio(103).sigAddress='&random_walk_B.Compare_m';

bio(104).blkName='Force outside box/Compare To Zero1/Compare';
bio(104).sigName='';
bio(104).portIdx=0;
bio(104).dim=[1,1];
bio(104).sigWidth=1;
bio(104).sigAddress='&random_walk_B.Compare_d';

bio(105).blkName='Force outside box/In Center/Abs';
bio(105).sigName='';
bio(105).portIdx=0;
bio(105).dim=[1,1];
bio(105).sigWidth=1;
bio(105).sigAddress='&random_walk_B.Abs';

bio(106).blkName='Force outside box/In Center/Abs1';
bio(106).sigName='';
bio(106).portIdx=0;
bio(106).dim=[1,1];
bio(106).sigWidth=1;
bio(106).sigAddress='&random_walk_B.Abs1';

bio(107).blkName='Force outside box/In Center/Abs2';
bio(107).sigName='';
bio(107).portIdx=0;
bio(107).dim=[1,1];
bio(107).sigWidth=1;
bio(107).sigAddress='&random_walk_B.Abs2';

bio(108).blkName='Force outside box/In Center/Abs3';
bio(108).sigName='';
bio(108).portIdx=0;
bio(108).dim=[1,1];
bio(108).sigWidth=1;
bio(108).sigAddress='&random_walk_B.Abs3';

bio(109).blkName='Force outside box/In Center/Logical Operator1';
bio(109).sigName='';
bio(109).portIdx=0;
bio(109).dim=[1,1];
bio(109).sigWidth=1;
bio(109).sigAddress='&random_walk_B.LogicalOperator1_h';

bio(110).blkName='Force outside box/Leave center/FixPt Relational Operator';
bio(110).sigName='';
bio(110).portIdx=0;
bio(110).dim=[1,1];
bio(110).sigWidth=1;
bio(110).sigAddress='&random_walk_B.FixPtRelationalOperator_i';

bio(111).blkName='Force outside box/Leave center/Delay Input1';
bio(111).sigName='U(k-1)';
bio(111).portIdx=0;
bio(111).dim=[1,1];
bio(111).sigWidth=1;
bio(111).sigAddress='&random_walk_B.Uk1_h';

bio(112).blkName='Force outside box/Leave center delay/FixPt Relational Operator';
bio(112).sigName='';
bio(112).portIdx=0;
bio(112).dim=[1,1];
bio(112).sigWidth=1;
bio(112).sigAddress='&random_walk_B.FixPtRelationalOperator_g';

bio(113).blkName='Force outside box/Leave center delay/Delay Input1';
bio(113).sigName='U(k-1)';
bio(113).portIdx=0;
bio(113).dim=[1,1];
bio(113).sigWidth=1;
bio(113).sigAddress='&random_walk_B.Uk1_p';

bio(114).blkName='Force outside box/S-R Flip-Flop/Logic';
bio(114).sigName='';
bio(114).portIdx=0;
bio(114).dim=[2,1];
bio(114).sigWidth=2;
bio(114).sigAddress='&random_walk_B.Logic[0]';

bio(115).blkName='Force outside box/S-R Flip-Flop/Memory';
bio(115).sigName='';
bio(115).portIdx=0;
bio(115).dim=[1,1];
bio(115).sigWidth=1;
bio(115).sigAddress='&random_walk_B.Memory_d';

bio(116).blkName='Force outside box/Schmidt1/Clock';
bio(116).sigName='';
bio(116).portIdx=0;
bio(116).dim=[1,1];
bio(116).sigWidth=1;
bio(116).sigAddress='&random_walk_B.Clock_n';

bio(117).blkName='Force outside box/Schmidt1/Logical Operator';
bio(117).sigName='';
bio(117).portIdx=0;
bio(117).dim=[1,1];
bio(117).sigWidth=1;
bio(117).sigAddress='&random_walk_B.LogicalOperator_g';

bio(118).blkName='Force outside box/Schmidt1/Logical Operator1';
bio(118).sigName='';
bio(118).portIdx=0;
bio(118).dim=[1,1];
bio(118).sigWidth=1;
bio(118).sigAddress='&random_walk_B.LogicalOperator1_e';

bio(119).blkName='Force outside box/Schmidt1/Logical Operator2';
bio(119).sigName='';
bio(119).portIdx=0;
bio(119).dim=[1,1];
bio(119).sigWidth=1;
bio(119).sigAddress='&random_walk_B.LogicalOperator2_m';

bio(120).blkName='Force outside box/Schmidt1/Memory';
bio(120).sigName='';
bio(120).portIdx=0;
bio(120).dim=[1,1];
bio(120).sigWidth=1;
bio(120).sigAddress='&random_walk_B.Memory_k';

bio(121).blkName='Force outside box/Schmidt1/Relational Operator';
bio(121).sigName='';
bio(121).portIdx=0;
bio(121).dim=[1,1];
bio(121).sigWidth=1;
bio(121).sigAddress='&random_walk_B.RelationalOperator_f';

bio(122).blkName='Force outside box/Schmidt1/Sum';
bio(122).sigName='';
bio(122).portIdx=0;
bio(122).dim=[1,1];
bio(122).sigWidth=1;
bio(122).sigAddress='&random_walk_B.Sum_a';

bio(123).blkName='Force outside box/Schmidt3/Clock';
bio(123).sigName='';
bio(123).portIdx=0;
bio(123).dim=[1,1];
bio(123).sigWidth=1;
bio(123).sigAddress='&random_walk_B.Clock_jm';

bio(124).blkName='Force outside box/Schmidt3/Logical Operator';
bio(124).sigName='';
bio(124).portIdx=0;
bio(124).dim=[1,1];
bio(124).sigWidth=1;
bio(124).sigAddress='&random_walk_B.LogicalOperator_l';

bio(125).blkName='Force outside box/Schmidt3/Logical Operator1';
bio(125).sigName='';
bio(125).portIdx=0;
bio(125).dim=[1,1];
bio(125).sigWidth=1;
bio(125).sigAddress='&random_walk_B.LogicalOperator1_b';

bio(126).blkName='Force outside box/Schmidt3/Logical Operator2';
bio(126).sigName='';
bio(126).portIdx=0;
bio(126).dim=[1,1];
bio(126).sigWidth=1;
bio(126).sigAddress='&random_walk_B.LogicalOperator2_mo';

bio(127).blkName='Force outside box/Schmidt3/Memory';
bio(127).sigName='';
bio(127).portIdx=0;
bio(127).dim=[1,1];
bio(127).sigWidth=1;
bio(127).sigAddress='&random_walk_B.Memory_i';

bio(128).blkName='Force outside box/Schmidt3/Relational Operator';
bio(128).sigName='';
bio(128).portIdx=0;
bio(128).dim=[1,1];
bio(128).sigWidth=1;
bio(128).sigAddress='&random_walk_B.RelationalOperator_k';

bio(129).blkName='Force outside box/Schmidt3/Sum';
bio(129).sigName='';
bio(129).portIdx=0;
bio(129).dim=[1,1];
bio(129).sigWidth=1;
bio(129).sigAddress='&random_walk_B.Sum_k';

bio(130).blkName='Force outside box/Timer/Clock';
bio(130).sigName='';
bio(130).portIdx=0;
bio(130).dim=[1,1];
bio(130).sigWidth=1;
bio(130).sigAddress='&random_walk_B.Clock_j';

bio(131).blkName='Force outside box/Timer/Logical Operator';
bio(131).sigName='';
bio(131).portIdx=0;
bio(131).dim=[1,1];
bio(131).sigWidth=1;
bio(131).sigAddress='&random_walk_B.LogicalOperator_m';

bio(132).blkName='Force outside box/Timer/Logical Operator1';
bio(132).sigName='';
bio(132).portIdx=0;
bio(132).dim=[1,1];
bio(132).sigWidth=1;
bio(132).sigAddress='&random_walk_B.LogicalOperator1_o';

bio(133).blkName='Force outside box/Timer/Logical Operator2';
bio(133).sigName='';
bio(133).portIdx=0;
bio(133).dim=[1,1];
bio(133).sigWidth=1;
bio(133).sigAddress='&random_walk_B.LogicalOperator2_n';

bio(134).blkName='Force outside box/Timer/Logical Operator3';
bio(134).sigName='';
bio(134).portIdx=0;
bio(134).dim=[1,1];
bio(134).sigWidth=1;
bio(134).sigAddress='&random_walk_B.LogicalOperator3';

bio(135).blkName='Force outside box/Timer/Logical Operator4';
bio(135).sigName='';
bio(135).portIdx=0;
bio(135).dim=[1,1];
bio(135).sigWidth=1;
bio(135).sigAddress='&random_walk_B.LogicalOperator4';

bio(136).blkName='Force outside box/Timer/Logical Operator5';
bio(136).sigName='';
bio(136).portIdx=0;
bio(136).dim=[1,1];
bio(136).sigWidth=1;
bio(136).sigAddress='&random_walk_B.LogicalOperator5';

bio(137).blkName='Force outside box/Timer/Memory';
bio(137).sigName='';
bio(137).portIdx=0;
bio(137).dim=[1,1];
bio(137).sigWidth=1;
bio(137).sigAddress='&random_walk_B.Memory_o';

bio(138).blkName='Force outside box/Timer/Relational Operator';
bio(138).sigName='';
bio(138).portIdx=0;
bio(138).dim=[1,1];
bio(138).sigWidth=1;
bio(138).sigAddress='&random_walk_B.RelationalOperator_g';

bio(139).blkName='Force outside box/Timer/Sum';
bio(139).sigName='';
bio(139).portIdx=0;
bio(139).dim=[1,1];
bio(139).sigWidth=1;
bio(139).sigAddress='&random_walk_B.Sum_b';

bio(140).blkName='RewardSbs/Schmidt1/Clock';
bio(140).sigName='';
bio(140).portIdx=0;
bio(140).dim=[1,1];
bio(140).sigWidth=1;
bio(140).sigAddress='&random_walk_B.Clock_c';

bio(141).blkName='RewardSbs/Schmidt1/Logical Operator';
bio(141).sigName='';
bio(141).portIdx=0;
bio(141).dim=[1,1];
bio(141).sigWidth=1;
bio(141).sigAddress='&random_walk_B.LogicalOperator_e';

bio(142).blkName='RewardSbs/Schmidt1/Logical Operator1';
bio(142).sigName='';
bio(142).portIdx=0;
bio(142).dim=[1,1];
bio(142).sigWidth=1;
bio(142).sigAddress='&random_walk_B.LogicalOperator1_j';

bio(143).blkName='RewardSbs/Schmidt1/Logical Operator2';
bio(143).sigName='';
bio(143).portIdx=0;
bio(143).dim=[1,1];
bio(143).sigWidth=1;
bio(143).sigAddress='&random_walk_B.LogicalOperator2_f';

bio(144).blkName='RewardSbs/Schmidt1/Memory';
bio(144).sigName='';
bio(144).portIdx=0;
bio(144).dim=[1,1];
bio(144).sigWidth=1;
bio(144).sigAddress='&random_walk_B.Memory_oz';

bio(145).blkName='RewardSbs/Schmidt1/Relational Operator';
bio(145).sigName='';
bio(145).portIdx=0;
bio(145).dim=[1,1];
bio(145).sigWidth=1;
bio(145).sigAddress='&random_walk_B.RelationalOperator_gb';

bio(146).blkName='RewardSbs/Schmidt1/Sum';
bio(146).sigName='';
bio(146).portIdx=0;
bio(146).dim=[1,1];
bio(146).sigWidth=1;
bio(146).sigAddress='&random_walk_B.Sum_i';

bio(147).blkName='Schmidt/Compare To Zero/Compare';
bio(147).sigName='';
bio(147).portIdx=0;
bio(147).dim=[1,1];
bio(147).sigWidth=1;
bio(147).sigAddress='&random_walk_B.Compare';

bio(148).blkName='Schmidt/Enabled Subsystem/In1';
bio(148).sigName='';
bio(148).portIdx=0;
bio(148).dim=[1,1];
bio(148).sigWidth=1;
bio(148).sigAddress='&random_walk_B.EnabledSubsystem.In1';

bio(149).blkName='XY Position Subsystem/Cursor Rotation/sqrt(u[1]*u[1] + u[2]*u[2])';
bio(149).sigName='';
bio(149).portIdx=0;
bio(149).dim=[1,1];
bio(149).sigWidth=1;
bio(149).sigAddress='&random_walk_B.sqrtu1u1u2u2';

bio(150).blkName='XY Position Subsystem/Cursor Rotation/Product';
bio(150).sigName='';
bio(150).portIdx=0;
bio(150).dim=[1,1];
bio(150).sigWidth=1;
bio(150).sigAddress='&random_walk_B.Product';

bio(151).blkName='XY Position Subsystem/Cursor Rotation/Product1';
bio(151).sigName='';
bio(151).portIdx=0;
bio(151).dim=[1,1];
bio(151).sigWidth=1;
bio(151).sigAddress='&random_walk_B.Product1';

bio(152).blkName='XY Position Subsystem/Cursor Rotation/Sum';
bio(152).sigName='';
bio(152).portIdx=0;
bio(152).dim=[1,1];
bio(152).sigWidth=1;
bio(152).sigAddress='&random_walk_B.Sum_h';

bio(153).blkName='XY Position Subsystem/Cursor Rotation/Trigonometric Function';
bio(153).sigName='';
bio(153).portIdx=0;
bio(153).dim=[1,1];
bio(153).sigWidth=1;
bio(153).sigAddress='&random_walk_B.TrigonometricFunction';

bio(154).blkName='XY Position Subsystem/Cursor Rotation/Trigonometric Function1';
bio(154).sigName='';
bio(154).portIdx=0;
bio(154).dim=[1,1];
bio(154).sigWidth=1;
bio(154).sigAddress='&random_walk_B.TrigonometricFunction1';

bio(155).blkName='XY Position Subsystem/Cursor Rotation/Trigonometric Function2';
bio(155).sigName='';
bio(155).portIdx=0;
bio(155).dim=[1,1];
bio(155).sigWidth=1;
bio(155).sigAddress='&random_walk_B.TrigonometricFunction2';

bio(156).blkName='XY Position Subsystem/For Iterator Subsystem/For Iterator';
bio(156).sigName='';
bio(156).portIdx=0;
bio(156).dim=[1,1];
bio(156).sigWidth=1;
bio(156).sigAddress='&random_walk_B.ForIterator';

bio(157).blkName='XY Position Subsystem/For Iterator Subsystem/SerialConverter';
bio(157).sigName='';
bio(157).portIdx=0;
bio(157).dim=[1,1];
bio(157).sigWidth=1;
bio(157).sigAddress='&random_walk_B.SerialConverter';

bio(158).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p1';
bio(158).sigName='';
bio(158).portIdx=0;
bio(158).dim=[1,1];
bio(158).sigWidth=1;
bio(158).sigAddress='&random_walk_B.ToBits_o1_n';

bio(159).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p2';
bio(159).sigName='';
bio(159).portIdx=1;
bio(159).dim=[1,1];
bio(159).sigWidth=1;
bio(159).sigAddress='&random_walk_B.ToBits_o2_f';

bio(160).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p3';
bio(160).sigName='';
bio(160).portIdx=2;
bio(160).dim=[1,1];
bio(160).sigWidth=1;
bio(160).sigAddress='&random_walk_B.ToBits_o3_k';

bio(161).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p4';
bio(161).sigName='';
bio(161).portIdx=3;
bio(161).dim=[1,1];
bio(161).sigWidth=1;
bio(161).sigAddress='&random_walk_B.ToBits_o4_n';

bio(162).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p5';
bio(162).sigName='';
bio(162).portIdx=4;
bio(162).dim=[1,1];
bio(162).sigWidth=1;
bio(162).sigAddress='&random_walk_B.ToBits_o5_f';

bio(163).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p6';
bio(163).sigName='';
bio(163).portIdx=5;
bio(163).dim=[1,1];
bio(163).sigWidth=1;
bio(163).sigAddress='&random_walk_B.ToBits_o6_i';

bio(164).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p7';
bio(164).sigName='';
bio(164).portIdx=6;
bio(164).dim=[1,1];
bio(164).sigWidth=1;
bio(164).sigAddress='&random_walk_B.ToBits_o7_f';

bio(165).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p8';
bio(165).sigName='';
bio(165).portIdx=7;
bio(165).dim=[1,1];
bio(165).sigWidth=1;
bio(165).sigAddress='&random_walk_B.ToBits_o8_d';

bio(166).blkName='XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ';
bio(166).sigName='';
bio(166).portIdx=0;
bio(166).dim=[1,1];
bio(166).sigWidth=1;
bio(166).sigAddress='&random_walk_B.xPCTargetTime';

bio(167).blkName='XY Position Subsystem/For Iterator Subsystem/Add';
bio(167).sigName='';
bio(167).portIdx=0;
bio(167).dim=[1,1];
bio(167).sigWidth=1;
bio(167).sigAddress='&random_walk_B.Add_j';

bio(168).blkName='XY Position Subsystem/For Iterator Subsystem/Add1';
bio(168).sigName='';
bio(168).portIdx=0;
bio(168).dim=[1,1];
bio(168).sigWidth=1;
bio(168).sigAddress='&random_walk_B.Add1_oz';

bio(169).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/cos(length of Elbow)';
bio(169).sigName='';
bio(169).portIdx=0;
bio(169).dim=[1,1];
bio(169).sigWidth=1;
bio(169).sigAddress='&random_walk_B.coslengthofElbow';

bio(170).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/cos(length of Shoulder)';
bio(170).sigName='';
bio(170).portIdx=0;
bio(170).dim=[1,1];
bio(170).sigWidth=1;
bio(170).sigAddress='&random_walk_B.coslengthofShoulder';

bio(171).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/sin(length of Elbow)';
bio(171).sigName='';
bio(171).portIdx=0;
bio(171).dim=[1,1];
bio(171).sigWidth=1;
bio(171).sigAddress='&random_walk_B.sinlengthofElbow';

bio(172).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/sin(length of Shoulder)';
bio(172).sigName='';
bio(172).portIdx=0;
bio(172).dim=[1,1];
bio(172).sigWidth=1;
bio(172).sigAddress='&random_walk_B.sinlengthofShoulder';

bio(173).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum1';
bio(173).sigName='';
bio(173).portIdx=0;
bio(173).dim=[1,1];
bio(173).sigWidth=1;
bio(173).sigAddress='&random_walk_B.Sum1_g';

bio(174).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum2';
bio(174).sigName='';
bio(174).portIdx=0;
bio(174).dim=[1,1];
bio(174).sigWidth=1;
bio(174).sigAddress='&random_walk_B.Sum2';

bio(175).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum3';
bio(175).sigName='';
bio(175).portIdx=0;
bio(175).dim=[1,1];
bio(175).sigWidth=1;
bio(175).sigAddress='&random_walk_B.Sum3_i';

bio(176).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum4';
bio(176).sigName='';
bio(176).portIdx=0;
bio(176).dim=[1,1];
bio(176).sigWidth=1;
bio(176).sigAddress='&random_walk_B.Sum4';

bio(177).blkName='Force Generator/LorentzForce/Lorentz/dX';
bio(177).sigName='';
bio(177).portIdx=0;
bio(177).dim=[1,1];
bio(177).sigWidth=1;
bio(177).sigAddress='&random_walk_B.dX';

bio(178).blkName='Force Generator/LorentzForce/Lorentz/dY';
bio(178).sigName='';
bio(178).portIdx=0;
bio(178).dim=[1,1];
bio(178).sigWidth=1;
bio(178).sigAddress='&random_walk_B.dY';

bio(179).blkName='Force Generator/LorentzForce/Lorentz/dZ';
bio(179).sigName='';
bio(179).portIdx=0;
bio(179).dim=[1,1];
bio(179).sigWidth=1;
bio(179).sigAddress='&random_walk_B.dZ';

bio(180).blkName='Force Generator/LorentzForce/Lorentz/product1';
bio(180).sigName='';
bio(180).portIdx=0;
bio(180).dim=[1,1];
bio(180).sigWidth=1;
bio(180).sigAddress='&random_walk_B.product1';

bio(181).blkName='Force Generator/LorentzForce/Lorentz/product2';
bio(181).sigName='';
bio(181).portIdx=0;
bio(181).dim=[1,1];
bio(181).sigWidth=1;
bio(181).sigAddress='&random_walk_B.product2';

bio(182).blkName='Force Generator/LorentzForce/Lorentz/product3';
bio(182).sigName='';
bio(182).portIdx=0;
bio(182).dim=[1,1];
bio(182).sigWidth=1;
bio(182).sigAddress='&random_walk_B.product3';

bio(183).blkName='Force Generator/LorentzForce/Lorentz/product4';
bio(183).sigName='';
bio(183).portIdx=0;
bio(183).dim=[1,1];
bio(183).sigWidth=1;
bio(183).sigAddress='&random_walk_B.product4';

bio(184).blkName='Force Generator/LorentzForce/Lorentz/Add1';
bio(184).sigName='';
bio(184).portIdx=0;
bio(184).dim=[1,1];
bio(184).sigWidth=1;
bio(184).sigAddress='&random_walk_B.Add1_o';

bio(185).blkName='Force Generator/LorentzForce/Lorentz/Add2';
bio(185).sigName='';
bio(185).portIdx=0;
bio(185).dim=[1,1];
bio(185).sigWidth=1;
bio(185).sigAddress='&random_walk_B.Add2';

bio(186).blkName='Force Generator/LorentzForce/Lorentz/Add3';
bio(186).sigName='';
bio(186).portIdx=0;
bio(186).dim=[1,1];
bio(186).sigWidth=1;
bio(186).sigAddress='&random_walk_B.Add3';

bio(187).blkName='Force Generator/LorentzForce/Lorentz/Add4';
bio(187).sigName='';
bio(187).portIdx=0;
bio(187).dim=[1,1];
bio(187).sigWidth=1;
bio(187).sigAddress='&random_walk_B.Add4';

bio(188).blkName='Force Generator/LorentzForce/Lorentz/AddX';
bio(188).sigName='';
bio(188).portIdx=0;
bio(188).dim=[1,1];
bio(188).sigWidth=1;
bio(188).sigAddress='&random_walk_B.AddX';

bio(189).blkName='Force Generator/LorentzForce/Lorentz/AddX1';
bio(189).sigName='';
bio(189).portIdx=0;
bio(189).dim=[1,1];
bio(189).sigWidth=1;
bio(189).sigAddress='&random_walk_B.AddX1';

bio(190).blkName='Force Generator/LorentzForce/Lorentz/AddX2';
bio(190).sigName='';
bio(190).portIdx=0;
bio(190).dim=[1,1];
bio(190).sigWidth=1;
bio(190).sigAddress='&random_walk_B.AddX2';

bio(191).blkName='Force Generator/LorentzForce/Lorentz/x';
bio(191).sigName='';
bio(191).portIdx=0;
bio(191).dim=[1,1];
bio(191).sigWidth=1;
bio(191).sigAddress='&random_walk_B.x';

bio(192).blkName='Force Generator/LorentzForce/Lorentz/y';
bio(192).sigName='';
bio(192).portIdx=0;
bio(192).dim=[1,1];
bio(192).sigWidth=1;
bio(192).sigAddress='&random_walk_B.y';

bio(193).blkName='Force Generator/LorentzForce/Lorentz/z';
bio(193).sigName='';
bio(193).portIdx=0;
bio(193).dim=[1,1];
bio(193).sigWidth=1;
bio(193).sigAddress='&random_walk_B.z';

bio(194).blkName='Force Generator/LorentzForce/Lorentz1/dX';
bio(194).sigName='';
bio(194).portIdx=0;
bio(194).dim=[1,1];
bio(194).sigWidth=1;
bio(194).sigAddress='&random_walk_B.dX_m';

bio(195).blkName='Force Generator/LorentzForce/Lorentz1/dY';
bio(195).sigName='';
bio(195).portIdx=0;
bio(195).dim=[1,1];
bio(195).sigWidth=1;
bio(195).sigAddress='&random_walk_B.dY_f';

bio(196).blkName='Force Generator/LorentzForce/Lorentz1/dZ';
bio(196).sigName='';
bio(196).portIdx=0;
bio(196).dim=[1,1];
bio(196).sigWidth=1;
bio(196).sigAddress='&random_walk_B.dZ_g';

bio(197).blkName='Force Generator/LorentzForce/Lorentz1/product1';
bio(197).sigName='';
bio(197).portIdx=0;
bio(197).dim=[1,1];
bio(197).sigWidth=1;
bio(197).sigAddress='&random_walk_B.product1_f';

bio(198).blkName='Force Generator/LorentzForce/Lorentz1/product2';
bio(198).sigName='';
bio(198).portIdx=0;
bio(198).dim=[1,1];
bio(198).sigWidth=1;
bio(198).sigAddress='&random_walk_B.product2_l';

bio(199).blkName='Force Generator/LorentzForce/Lorentz1/product3';
bio(199).sigName='';
bio(199).portIdx=0;
bio(199).dim=[1,1];
bio(199).sigWidth=1;
bio(199).sigAddress='&random_walk_B.product3_b';

bio(200).blkName='Force Generator/LorentzForce/Lorentz1/product4';
bio(200).sigName='';
bio(200).portIdx=0;
bio(200).dim=[1,1];
bio(200).sigWidth=1;
bio(200).sigAddress='&random_walk_B.product4_d';

bio(201).blkName='Force Generator/LorentzForce/Lorentz1/Add1';
bio(201).sigName='';
bio(201).portIdx=0;
bio(201).dim=[1,1];
bio(201).sigWidth=1;
bio(201).sigAddress='&random_walk_B.Add1_b';

bio(202).blkName='Force Generator/LorentzForce/Lorentz1/Add2';
bio(202).sigName='';
bio(202).portIdx=0;
bio(202).dim=[1,1];
bio(202).sigWidth=1;
bio(202).sigAddress='&random_walk_B.Add2_b';

bio(203).blkName='Force Generator/LorentzForce/Lorentz1/Add3';
bio(203).sigName='';
bio(203).portIdx=0;
bio(203).dim=[1,1];
bio(203).sigWidth=1;
bio(203).sigAddress='&random_walk_B.Add3_e';

bio(204).blkName='Force Generator/LorentzForce/Lorentz1/Add4';
bio(204).sigName='';
bio(204).portIdx=0;
bio(204).dim=[1,1];
bio(204).sigWidth=1;
bio(204).sigAddress='&random_walk_B.Add4_b';

bio(205).blkName='Force Generator/LorentzForce/Lorentz1/AddX';
bio(205).sigName='';
bio(205).portIdx=0;
bio(205).dim=[1,1];
bio(205).sigWidth=1;
bio(205).sigAddress='&random_walk_B.AddX_j';

bio(206).blkName='Force Generator/LorentzForce/Lorentz1/AddX1';
bio(206).sigName='';
bio(206).portIdx=0;
bio(206).dim=[1,1];
bio(206).sigWidth=1;
bio(206).sigAddress='&random_walk_B.AddX1_b';

bio(207).blkName='Force Generator/LorentzForce/Lorentz1/AddX2';
bio(207).sigName='';
bio(207).portIdx=0;
bio(207).dim=[1,1];
bio(207).sigWidth=1;
bio(207).sigAddress='&random_walk_B.AddX2_e';

bio(208).blkName='Force Generator/LorentzForce/Lorentz1/x';
bio(208).sigName='';
bio(208).portIdx=0;
bio(208).dim=[1,1];
bio(208).sigWidth=1;
bio(208).sigAddress='&random_walk_B.x_f';

bio(209).blkName='Force Generator/LorentzForce/Lorentz1/y';
bio(209).sigName='';
bio(209).portIdx=0;
bio(209).dim=[1,1];
bio(209).sigWidth=1;
bio(209).sigAddress='&random_walk_B.y_e';

bio(210).blkName='Force Generator/LorentzForce/Lorentz1/z';
bio(210).sigName='';
bio(210).portIdx=0;
bio(210).dim=[1,1];
bio(210).sigWidth=1;
bio(210).sigAddress='&random_walk_B.z_o';

bio(211).blkName='Force Generator/LorentzForce/Lorentz2/dX';
bio(211).sigName='';
bio(211).portIdx=0;
bio(211).dim=[1,1];
bio(211).sigWidth=1;
bio(211).sigAddress='&random_walk_B.dX_f';

bio(212).blkName='Force Generator/LorentzForce/Lorentz2/dY';
bio(212).sigName='';
bio(212).portIdx=0;
bio(212).dim=[1,1];
bio(212).sigWidth=1;
bio(212).sigAddress='&random_walk_B.dY_b';

bio(213).blkName='Force Generator/LorentzForce/Lorentz2/dZ';
bio(213).sigName='';
bio(213).portIdx=0;
bio(213).dim=[1,1];
bio(213).sigWidth=1;
bio(213).sigAddress='&random_walk_B.dZ_f';

bio(214).blkName='Force Generator/LorentzForce/Lorentz2/product1';
bio(214).sigName='';
bio(214).portIdx=0;
bio(214).dim=[1,1];
bio(214).sigWidth=1;
bio(214).sigAddress='&random_walk_B.product1_a';

bio(215).blkName='Force Generator/LorentzForce/Lorentz2/product2';
bio(215).sigName='';
bio(215).portIdx=0;
bio(215).dim=[1,1];
bio(215).sigWidth=1;
bio(215).sigAddress='&random_walk_B.product2_g';

bio(216).blkName='Force Generator/LorentzForce/Lorentz2/product3';
bio(216).sigName='';
bio(216).portIdx=0;
bio(216).dim=[1,1];
bio(216).sigWidth=1;
bio(216).sigAddress='&random_walk_B.product3_d';

bio(217).blkName='Force Generator/LorentzForce/Lorentz2/product4';
bio(217).sigName='';
bio(217).portIdx=0;
bio(217).dim=[1,1];
bio(217).sigWidth=1;
bio(217).sigAddress='&random_walk_B.product4_j';

bio(218).blkName='Force Generator/LorentzForce/Lorentz2/Add1';
bio(218).sigName='';
bio(218).portIdx=0;
bio(218).dim=[1,1];
bio(218).sigWidth=1;
bio(218).sigAddress='&random_walk_B.Add1_l';

bio(219).blkName='Force Generator/LorentzForce/Lorentz2/Add2';
bio(219).sigName='';
bio(219).portIdx=0;
bio(219).dim=[1,1];
bio(219).sigWidth=1;
bio(219).sigAddress='&random_walk_B.Add2_l';

bio(220).blkName='Force Generator/LorentzForce/Lorentz2/Add3';
bio(220).sigName='';
bio(220).portIdx=0;
bio(220).dim=[1,1];
bio(220).sigWidth=1;
bio(220).sigAddress='&random_walk_B.Add3_p';

bio(221).blkName='Force Generator/LorentzForce/Lorentz2/Add4';
bio(221).sigName='';
bio(221).portIdx=0;
bio(221).dim=[1,1];
bio(221).sigWidth=1;
bio(221).sigAddress='&random_walk_B.Add4_k';

bio(222).blkName='Force Generator/LorentzForce/Lorentz2/AddX';
bio(222).sigName='';
bio(222).portIdx=0;
bio(222).dim=[1,1];
bio(222).sigWidth=1;
bio(222).sigAddress='&random_walk_B.AddX_o';

bio(223).blkName='Force Generator/LorentzForce/Lorentz2/AddX1';
bio(223).sigName='';
bio(223).portIdx=0;
bio(223).dim=[1,1];
bio(223).sigWidth=1;
bio(223).sigAddress='&random_walk_B.AddX1_j';

bio(224).blkName='Force Generator/LorentzForce/Lorentz2/AddX2';
bio(224).sigName='';
bio(224).portIdx=0;
bio(224).dim=[1,1];
bio(224).sigWidth=1;
bio(224).sigAddress='&random_walk_B.AddX2_h';

bio(225).blkName='Force Generator/LorentzForce/Lorentz2/x';
bio(225).sigName='';
bio(225).portIdx=0;
bio(225).dim=[1,1];
bio(225).sigWidth=1;
bio(225).sigAddress='&random_walk_B.x_h';

bio(226).blkName='Force Generator/LorentzForce/Lorentz2/y';
bio(226).sigName='';
bio(226).portIdx=0;
bio(226).dim=[1,1];
bio(226).sigWidth=1;
bio(226).sigAddress='&random_walk_B.y_j';

bio(227).blkName='Force Generator/LorentzForce/Lorentz2/z';
bio(227).sigName='';
bio(227).portIdx=0;
bio(227).dim=[1,1];
bio(227).sigWidth=1;
bio(227).sigAddress='&random_walk_B.z_n';

bio(228).blkName='Force Generator/LorentzForce/Lorentz3/dX';
bio(228).sigName='';
bio(228).portIdx=0;
bio(228).dim=[1,1];
bio(228).sigWidth=1;
bio(228).sigAddress='&random_walk_B.dX_b';

bio(229).blkName='Force Generator/LorentzForce/Lorentz3/dY';
bio(229).sigName='';
bio(229).portIdx=0;
bio(229).dim=[1,1];
bio(229).sigWidth=1;
bio(229).sigAddress='&random_walk_B.dY_n';

bio(230).blkName='Force Generator/LorentzForce/Lorentz3/dZ';
bio(230).sigName='';
bio(230).portIdx=0;
bio(230).dim=[1,1];
bio(230).sigWidth=1;
bio(230).sigAddress='&random_walk_B.dZ_i';

bio(231).blkName='Force Generator/LorentzForce/Lorentz3/product1';
bio(231).sigName='';
bio(231).portIdx=0;
bio(231).dim=[1,1];
bio(231).sigWidth=1;
bio(231).sigAddress='&random_walk_B.product1_o';

bio(232).blkName='Force Generator/LorentzForce/Lorentz3/product2';
bio(232).sigName='';
bio(232).portIdx=0;
bio(232).dim=[1,1];
bio(232).sigWidth=1;
bio(232).sigAddress='&random_walk_B.product2_c';

bio(233).blkName='Force Generator/LorentzForce/Lorentz3/product3';
bio(233).sigName='';
bio(233).portIdx=0;
bio(233).dim=[1,1];
bio(233).sigWidth=1;
bio(233).sigAddress='&random_walk_B.product3_i';

bio(234).blkName='Force Generator/LorentzForce/Lorentz3/product4';
bio(234).sigName='';
bio(234).portIdx=0;
bio(234).dim=[1,1];
bio(234).sigWidth=1;
bio(234).sigAddress='&random_walk_B.product4_p';

bio(235).blkName='Force Generator/LorentzForce/Lorentz3/Add1';
bio(235).sigName='';
bio(235).portIdx=0;
bio(235).dim=[1,1];
bio(235).sigWidth=1;
bio(235).sigAddress='&random_walk_B.Add1_n';

bio(236).blkName='Force Generator/LorentzForce/Lorentz3/Add2';
bio(236).sigName='';
bio(236).portIdx=0;
bio(236).dim=[1,1];
bio(236).sigWidth=1;
bio(236).sigAddress='&random_walk_B.Add2_d';

bio(237).blkName='Force Generator/LorentzForce/Lorentz3/Add3';
bio(237).sigName='';
bio(237).portIdx=0;
bio(237).dim=[1,1];
bio(237).sigWidth=1;
bio(237).sigAddress='&random_walk_B.Add3_a';

bio(238).blkName='Force Generator/LorentzForce/Lorentz3/Add4';
bio(238).sigName='';
bio(238).portIdx=0;
bio(238).dim=[1,1];
bio(238).sigWidth=1;
bio(238).sigAddress='&random_walk_B.Add4_h';

bio(239).blkName='Force Generator/LorentzForce/Lorentz3/AddX';
bio(239).sigName='';
bio(239).portIdx=0;
bio(239).dim=[1,1];
bio(239).sigWidth=1;
bio(239).sigAddress='&random_walk_B.AddX_jl';

bio(240).blkName='Force Generator/LorentzForce/Lorentz3/AddX1';
bio(240).sigName='';
bio(240).portIdx=0;
bio(240).dim=[1,1];
bio(240).sigWidth=1;
bio(240).sigAddress='&random_walk_B.AddX1_bw';

bio(241).blkName='Force Generator/LorentzForce/Lorentz3/AddX2';
bio(241).sigName='';
bio(241).portIdx=0;
bio(241).dim=[1,1];
bio(241).sigWidth=1;
bio(241).sigAddress='&random_walk_B.AddX2_g';

bio(242).blkName='Force Generator/LorentzForce/Lorentz3/x';
bio(242).sigName='';
bio(242).portIdx=0;
bio(242).dim=[1,1];
bio(242).sigWidth=1;
bio(242).sigAddress='&random_walk_B.x_l';

bio(243).blkName='Force Generator/LorentzForce/Lorentz3/y';
bio(243).sigName='';
bio(243).portIdx=0;
bio(243).dim=[1,1];
bio(243).sigWidth=1;
bio(243).sigAddress='&random_walk_B.y_o';

bio(244).blkName='Force Generator/LorentzForce/Lorentz3/z';
bio(244).sigName='';
bio(244).portIdx=0;
bio(244).dim=[1,1];
bio(244).sigWidth=1;
bio(244).sigAddress='&random_walk_B.z_j';

bio(245).blkName='Force outside box/In Center/Compare To Constant/Compare';
bio(245).sigName='';
bio(245).portIdx=0;
bio(245).dim=[1,1];
bio(245).sigWidth=1;
bio(245).sigAddress='&random_walk_B.Compare_n';

bio(246).blkName='Force outside box/In Center/Compare To Constant1/Compare';
bio(246).sigName='';
bio(246).portIdx=0;
bio(246).dim=[1,1];
bio(246).sigWidth=1;
bio(246).sigAddress='&random_walk_B.Compare_a';

bio(247).blkName='Force outside box/In Center/Compare To Constant2/Compare';
bio(247).sigName='';
bio(247).portIdx=0;
bio(247).dim=[1,1];
bio(247).sigWidth=1;
bio(247).sigAddress='&random_walk_B.Compare_ht';

bio(248).blkName='Force outside box/In Center/Compare To Constant3/Compare';
bio(248).sigName='';
bio(248).portIdx=0;
bio(248).dim=[1,1];
bio(248).sigWidth=1;
bio(248).sigAddress='&random_walk_B.Compare_o';

bio(249).blkName='Force outside box/Leave center/Nonpositive/Compare';
bio(249).sigName='';
bio(249).portIdx=0;
bio(249).dim=[1,1];
bio(249).sigWidth=1;
bio(249).sigAddress='&random_walk_B.Compare_l';

bio(250).blkName='Force outside box/Leave center delay/Nonpositive/Compare';
bio(250).sigName='';
bio(250).portIdx=0;
bio(250).dim=[1,1];
bio(250).sigWidth=1;
bio(250).sigAddress='&random_walk_B.Compare_be';

bio(251).blkName='Force outside box/Schmidt1/Compare To Zero/Compare';
bio(251).sigName='';
bio(251).portIdx=0;
bio(251).dim=[1,1];
bio(251).sigWidth=1;
bio(251).sigAddress='&random_walk_B.Compare_h';

bio(252).blkName='Force outside box/Schmidt1/Enabled Subsystem/In1';
bio(252).sigName='';
bio(252).portIdx=0;
bio(252).dim=[1,1];
bio(252).sigWidth=1;
bio(252).sigAddress='&random_walk_B.EnabledSubsystem_b.In1';

bio(253).blkName='Force outside box/Schmidt3/Compare To Zero/Compare';
bio(253).sigName='';
bio(253).portIdx=0;
bio(253).dim=[1,1];
bio(253).sigWidth=1;
bio(253).sigAddress='&random_walk_B.Compare_n2';

bio(254).blkName='Force outside box/Schmidt3/Enabled Subsystem/In1';
bio(254).sigName='';
bio(254).portIdx=0;
bio(254).dim=[1,1];
bio(254).sigWidth=1;
bio(254).sigAddress='&random_walk_B.EnabledSubsystem_b1.In1';

bio(255).blkName='Force outside box/Timer/Compare To Zero/Compare';
bio(255).sigName='';
bio(255).portIdx=0;
bio(255).dim=[1,1];
bio(255).sigWidth=1;
bio(255).sigAddress='&random_walk_B.Compare_b';

bio(256).blkName='Force outside box/Timer/Detect Fall Nonpositive/FixPt Relational Operator';
bio(256).sigName='';
bio(256).portIdx=0;
bio(256).dim=[1,1];
bio(256).sigWidth=1;
bio(256).sigAddress='&random_walk_B.FixPtRelationalOperator';

bio(257).blkName='Force outside box/Timer/Detect Fall Nonpositive/Delay Input1';
bio(257).sigName='U(k-1)';
bio(257).portIdx=0;
bio(257).dim=[1,1];
bio(257).sigWidth=1;
bio(257).sigAddress='&random_walk_B.Uk1';

bio(258).blkName='Force outside box/Timer/Enabled Subsystem/In1';
bio(258).sigName='';
bio(258).portIdx=0;
bio(258).dim=[1,1];
bio(258).sigWidth=1;
bio(258).sigAddress='&random_walk_B.EnabledSubsystem_f.In1';

bio(259).blkName='RewardSbs/Schmidt1/Compare To Zero/Compare';
bio(259).sigName='';
bio(259).portIdx=0;
bio(259).dim=[1,1];
bio(259).sigWidth=1;
bio(259).sigAddress='&random_walk_B.Compare_p';

bio(260).blkName='RewardSbs/Schmidt1/Enabled Subsystem/In1';
bio(260).sigName='';
bio(260).portIdx=0;
bio(260).dim=[1,1];
bio(260).sigWidth=1;
bio(260).sigAddress='&random_walk_B.EnabledSubsystem_by.In1';

bio(261).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec';
bio(261).sigName='';
bio(261).portIdx=0;
bio(261).dim=[1,1];
bio(261).sigWidth=1;
bio(261).sigAddress='&random_walk_B.ScaleTouSec';

bio(262).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ';
bio(262).sigName='';
bio(262).portIdx=0;
bio(262).dim=[1,1];
bio(262).sigWidth=1;
bio(262).sigAddress='&random_walk_B.xPCTargetTime_a';

bio(263).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Subtract';
bio(263).sigName='';
bio(263).portIdx=0;
bio(263).dim=[1,1];
bio(263).sigWidth=1;
bio(263).sigAddress='&random_walk_B.Subtract';

bio(264).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Switch';
bio(264).sigName='';
bio(264).portIdx=0;
bio(264).dim=[1,1];
bio(264).sigWidth=1;
bio(264).sigAddress='&random_walk_B.Switch';

bio(265).blkName='Force outside box/Timer/Detect Fall Nonpositive/Nonpositive/Compare';
bio(265).sigName='';
bio(265).portIdx=0;
bio(265).dim=[1,1];
bio(265).sigWidth=1;
bio(265).sigAddress='&random_walk_B.Compare_f';

bio(266).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Compare';
bio(266).sigName='';
bio(266).portIdx=0;
bio(266).dim=[1,1];
bio(266).sigWidth=1;
bio(266).sigAddress='&random_walk_B.Compare_h0';

bio(267).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1/Compare';
bio(267).sigName='';
bio(267).portIdx=0;
bio(267).dim=[1,1];
bio(267).sigWidth=1;
bio(267).sigAddress='&random_walk_B.Compare_nw';

function len = getlenBIO
len = 267;

