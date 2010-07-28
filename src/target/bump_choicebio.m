function bio=bump_choicebio
bio = [];
bio(1).blkName='Matrix Concatenation1';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[4,1];
bio(1).sigWidth=4;
bio(1).sigAddress='&bump_choice_B.MatrixConcatenation1[0]';
bio(getlenBIO) = bio(1);

bio(2).blkName='Behavior BC/p1';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[2,1];
bio(2).sigWidth=2;
bio(2).sigAddress='&bump_choice_B.BehaviorBC_o1[0]';

bio(3).blkName='Behavior BC/p2';
bio(3).sigName='';
bio(3).portIdx=1;
bio(3).dim=[5,1];
bio(3).sigWidth=5;
bio(3).sigAddress='&bump_choice_B.BehaviorBC_o2[0]';

bio(4).blkName='Behavior BC/p3';
bio(4).sigName='';
bio(4).portIdx=2;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&bump_choice_B.BehaviorBC_o3';

bio(5).blkName='Behavior BC/p4';
bio(5).sigName='';
bio(5).portIdx=3;
bio(5).dim=[15,1];
bio(5).sigWidth=15;
bio(5).sigAddress='&bump_choice_B.BehaviorBC_o4[0]';

bio(6).blkName='Behavior BC/p5';
bio(6).sigName='';
bio(6).portIdx=4;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&bump_choice_B.BehaviorBC_o5';

bio(7).blkName='Behavior BC/p6';
bio(7).sigName='';
bio(7).portIdx=5;
bio(7).dim=[2,1];
bio(7).sigWidth=2;
bio(7).sigAddress='&bump_choice_B.BehaviorBC_o6[0]';

bio(8).blkName='Behavior BC/p7';
bio(8).sigName='';
bio(8).portIdx=6;
bio(8).dim=[4,1];
bio(8).sigWidth=4;
bio(8).sigAddress='&bump_choice_B.BehaviorBC_o7[0]';

bio(9).blkName='Behavior BC/p8';
bio(9).sigName='';
bio(9).portIdx=7;
bio(9).dim=[2,1];
bio(9).sigWidth=2;
bio(9).sigAddress='&bump_choice_B.BehaviorBC_o8[0]';

bio(10).blkName='BoundingBox/Logical Operator';
bio(10).sigName='';
bio(10).portIdx=0;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&bump_choice_B.LogicalOperator_a';

bio(11).blkName='BoundingBox/Relational Operator';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&bump_choice_B.RelationalOperator_g';

bio(12).blkName='BoundingBox/Relational Operator1';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&bump_choice_B.RelationalOperator1';

bio(13).blkName='BoundingBox/Relational Operator2';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[1,1];
bio(13).sigWidth=1;
bio(13).sigAddress='&bump_choice_B.RelationalOperator2';

bio(14).blkName='BoundingBox/Relational Operator3';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&bump_choice_B.RelationalOperator3';

bio(15).blkName='Catch Force Generator/Gain';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[1,1];
bio(15).sigWidth=1;
bio(15).sigAddress='&bump_choice_B.Gain_a';

bio(16).blkName='Catch Force Generator/LorentzForceGain';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[2,1];
bio(16).sigWidth=2;
bio(16).sigAddress='&bump_choice_B.LorentzForceGain_p[0]';

bio(17).blkName='Catch Force Generator/DynamicAngle Switch';
bio(17).sigName='';
bio(17).portIdx=0;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&bump_choice_B.DynamicAngleSwitch';

bio(18).blkName='Catch Force Generator/LoadSelect Switch';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[2,1];
bio(18).sigWidth=2;
bio(18).sigAddress='&bump_choice_B.LoadSelectSwitch[0]';

bio(19).blkName='Force Generator/Gain';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&bump_choice_B.Gain_n';

bio(20).blkName='Force Generator/LorentzForceGain';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[2,1];
bio(20).sigWidth=2;
bio(20).sigAddress='&bump_choice_B.LorentzForceGain[0]';

bio(21).blkName='Force Generator/Multiport Switch';
bio(21).sigName='';
bio(21).portIdx=0;
bio(21).dim=[2,1];
bio(21).sigWidth=2;
bio(21).sigAddress='&bump_choice_B.MultiportSwitch[0]';

bio(22).blkName='Force Generator/dynamicAngle Switch';
bio(22).sigName='';
bio(22).portIdx=0;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&bump_choice_B.dynamicAngleSwitch';

bio(23).blkName='Motor Control/Matrix Concatenation';
bio(23).sigName='';
bio(23).portIdx=0;
bio(23).dim=[2,1];
bio(23).sigWidth=2;
bio(23).sigAddress='&bump_choice_B.MatrixConcatenation[0]';

bio(24).blkName='Motor Control/MG1';
bio(24).sigName='';
bio(24).portIdx=0;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&bump_choice_B.MG1';

bio(25).blkName='Motor Control/MG2';
bio(25).sigName='';
bio(25).portIdx=0;
bio(25).dim=[1,1];
bio(25).sigWidth=1;
bio(25).sigAddress='&bump_choice_B.MG2';

bio(26).blkName='Motor Control/Logical Operator1';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&bump_choice_B.LogicalOperator1_it';

bio(27).blkName='Motor Control/Memory';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&bump_choice_B.Memory_k';

bio(28).blkName='Motor Control/Switch1';
bio(28).sigName='';
bio(28).portIdx=0;
bio(28).dim=[2,1];
bio(28).sigWidth=2;
bio(28).sigAddress='&bump_choice_B.Switch1[0]';

bio(29).blkName='Motor Control/Switch2';
bio(29).sigName='';
bio(29).portIdx=0;
bio(29).dim=[2,1];
bio(29).sigWidth=2;
bio(29).sigAddress='&bump_choice_B.Switch2[0]';

bio(30).blkName='Recentering Subsystem/Data Type Conversion1';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&bump_choice_B.DataTypeConversion1';

bio(31).blkName='Recentering Subsystem/Data Type Conversion2';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&bump_choice_B.DataTypeConversion2';

bio(32).blkName='Recentering Subsystem/Bounding Box Viscosity';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[2,1];
bio(32).sigWidth=2;
bio(32).sigAddress='&bump_choice_B.BoundingBoxViscosity[0]';

bio(33).blkName='Recentering Subsystem/InBox';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[1,1];
bio(33).sigWidth=1;
bio(33).sigAddress='&bump_choice_B.InBox';

bio(34).blkName='Recentering Subsystem/Logical Operator';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&bump_choice_B.LogicalOperator_j';

bio(35).blkName='Recentering Subsystem/Logical Operator1';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[1,1];
bio(35).sigWidth=1;
bio(35).sigAddress='&bump_choice_B.LogicalOperator1_g';

bio(36).blkName='Recentering Subsystem/Logical Operator3';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[1,1];
bio(36).sigWidth=1;
bio(36).sigAddress='&bump_choice_B.LogicalOperator3_d';

bio(37).blkName='Recentering Subsystem/Logical Operator5';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[1,1];
bio(37).sigWidth=1;
bio(37).sigAddress='&bump_choice_B.LogicalOperator5_k';

bio(38).blkName='Recentering Subsystem/Logical Operator6';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&bump_choice_B.LogicalOperator6';

bio(39).blkName='Recentering Subsystem/NOT';
bio(39).sigName='';
bio(39).portIdx=0;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&bump_choice_B.NOT';

bio(40).blkName='Recentering Subsystem/Switch';
bio(40).sigName='';
bio(40).portIdx=0;
bio(40).dim=[2,1];
bio(40).sigWidth=2;
bio(40).sigAddress='&bump_choice_B.Switch_j[0]';

bio(41).blkName='RewardSbs/Data Type Conversion';
bio(41).sigName='';
bio(41).portIdx=0;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&bump_choice_B.DataTypeConversion';

bio(42).blkName='RewardSbs/Relational Operator';
bio(42).sigName='';
bio(42).portIdx=0;
bio(42).dim=[1,1];
bio(42).sigWidth=1;
bio(42).sigAddress='&bump_choice_B.RelationalOperator_ka';

bio(43).blkName='RewardSbs/Switch';
bio(43).sigName='';
bio(43).portIdx=0;
bio(43).dim=[1,1];
bio(43).sigWidth=1;
bio(43).sigAddress='&bump_choice_B.Switch_o';

bio(44).blkName='RewardSbs/Uniform Random Number';
bio(44).sigName='';
bio(44).portIdx=0;
bio(44).dim=[1,1];
bio(44).sigWidth=1;
bio(44).sigAddress='&bump_choice_B.UniformRandomNumber';

bio(45).blkName='SendPacketToGraphics1/Rate Transition';
bio(45).sigName='';
bio(45).portIdx=0;
bio(45).dim=[168,1];
bio(45).sigWidth=168;
bio(45).sigAddress='&bump_choice_B.RateTransition[0]';

bio(46).blkName='SendPacketToGraphics1/Pack';
bio(46).sigName='';
bio(46).portIdx=0;
bio(46).dim=[168,1];
bio(46).sigWidth=168;
bio(46).sigAddress='&bump_choice_B.Pack[0]';

bio(47).blkName='Velocity Calculation/TachGain1';
bio(47).sigName='';
bio(47).portIdx=0;
bio(47).dim=[1,1];
bio(47).sigWidth=1;
bio(47).sigAddress='&bump_choice_B.TachGain1';

bio(48).blkName='Velocity Calculation/TachGain2';
bio(48).sigName='';
bio(48).portIdx=0;
bio(48).dim=[1,1];
bio(48).sigWidth=1;
bio(48).sigAddress='&bump_choice_B.TachGain2';

bio(49).blkName='Velocity Calculation/Matrix Multiply';
bio(49).sigName='';
bio(49).portIdx=0;
bio(49).dim=[2,1];
bio(49).sigWidth=2;
bio(49).sigAddress='&bump_choice_B.MatrixMultiply[0]';

bio(50).blkName='Velocity Calculation/PCI-6025E AD/p1';
bio(50).sigName='';
bio(50).portIdx=0;
bio(50).dim=[1,1];
bio(50).sigWidth=1;
bio(50).sigAddress='&bump_choice_B.PCI6025EAD_o1';

bio(51).blkName='Velocity Calculation/PCI-6025E AD/p2';
bio(51).sigName='';
bio(51).portIdx=1;
bio(51).dim=[1,1];
bio(51).sigWidth=1;
bio(51).sigAddress='&bump_choice_B.PCI6025EAD_o2';

bio(52).blkName='Velocity Calculation/Switch';
bio(52).sigName='';
bio(52).portIdx=0;
bio(52).dim=[2,1];
bio(52).sigWidth=2;
bio(52).sigAddress='&bump_choice_B.Switch[0]';

bio(53).blkName='XY Position Subsystem/Gain';
bio(53).sigName='';
bio(53).portIdx=0;
bio(53).dim=[1,1];
bio(53).sigWidth=1;
bio(53).sigAddress='&bump_choice_B.Gain';

bio(54).blkName='XY Position Subsystem/Gain1';
bio(54).sigName='';
bio(54).portIdx=0;
bio(54).dim=[1,1];
bio(54).sigWidth=1;
bio(54).sigAddress='&bump_choice_B.Gain1';

bio(55).blkName='XY Position Subsystem/PCI-QUAD04 ';
bio(55).sigName='';
bio(55).portIdx=0;
bio(55).dim=[1,1];
bio(55).sigWidth=1;
bio(55).sigAddress='&bump_choice_B.PCIQUAD04';

bio(56).blkName='XY Position Subsystem/PCI-QUAD04 1';
bio(56).sigName='';
bio(56).portIdx=0;
bio(56).dim=[1,1];
bio(56).sigWidth=1;
bio(56).sigAddress='&bump_choice_B.PCIQUAD041';

bio(57).blkName='XY Position Subsystem/Sum1';
bio(57).sigName='';
bio(57).portIdx=0;
bio(57).dim=[1,1];
bio(57).sigWidth=1;
bio(57).sigAddress='&bump_choice_B.Sum1';

bio(58).blkName='XY Position Subsystem/Sum3';
bio(58).sigName='';
bio(58).portIdx=0;
bio(58).dim=[1,1];
bio(58).sigWidth=1;
bio(58).sigAddress='&bump_choice_B.Sum3';

bio(59).blkName='Catch Force Generator/LorentzForce/Add';
bio(59).sigName='';
bio(59).portIdx=0;
bio(59).dim=[1,1];
bio(59).sigWidth=1;
bio(59).sigAddress='&bump_choice_B.Add_k';

bio(60).blkName='Catch Force Generator/LorentzForce/Add1';
bio(60).sigName='';
bio(60).portIdx=0;
bio(60).dim=[1,1];
bio(60).sigWidth=1;
bio(60).sigAddress='&bump_choice_B.Add1_k';

bio(61).blkName='Catch Force Generator/ViscLoadSubsystem/Gain';
bio(61).sigName='';
bio(61).portIdx=0;
bio(61).dim=[2,1];
bio(61).sigWidth=2;
bio(61).sigAddress='&bump_choice_B.Gain_f[0]';

bio(62).blkName='Catch Force Generator/ViscLoadSubsystem/Inverter';
bio(62).sigName='';
bio(62).portIdx=0;
bio(62).dim=[2,1];
bio(62).sigWidth=2;
bio(62).sigAddress='&bump_choice_B.Inverter_k[0]';

bio(63).blkName='Catch Force Generator/ViscLoadSubsystem/Product';
bio(63).sigName='';
bio(63).portIdx=0;
bio(63).dim=[1,1];
bio(63).sigWidth=1;
bio(63).sigAddress='&bump_choice_B.Product_i';

bio(64).blkName='Catch Force Generator/ViscLoadSubsystem/Product1';
bio(64).sigName='';
bio(64).portIdx=0;
bio(64).dim=[1,1];
bio(64).sigWidth=1;
bio(64).sigAddress='&bump_choice_B.Product1_p';

bio(65).blkName='Catch Force Generator/ViscLoadSubsystem/Product2';
bio(65).sigName='';
bio(65).portIdx=0;
bio(65).dim=[1,1];
bio(65).sigWidth=1;
bio(65).sigAddress='&bump_choice_B.Product2_g';

bio(66).blkName='Catch Force Generator/ViscLoadSubsystem/Product3';
bio(66).sigName='';
bio(66).portIdx=0;
bio(66).dim=[1,1];
bio(66).sigWidth=1;
bio(66).sigAddress='&bump_choice_B.Product3_h';

bio(67).blkName='Catch Force Generator/ViscLoadSubsystem/Add';
bio(67).sigName='';
bio(67).portIdx=0;
bio(67).dim=[1,1];
bio(67).sigWidth=1;
bio(67).sigAddress='&bump_choice_B.Add_ht';

bio(68).blkName='Catch Force Generator/ViscLoadSubsystem/Subtract';
bio(68).sigName='';
bio(68).portIdx=0;
bio(68).dim=[1,1];
bio(68).sigWidth=1;
bio(68).sigAddress='&bump_choice_B.Subtract_e';

bio(69).blkName='Catch Force Generator/ViscLoadSubsystem/cos';
bio(69).sigName='';
bio(69).portIdx=0;
bio(69).dim=[1,1];
bio(69).sigWidth=1;
bio(69).sigAddress='&bump_choice_B.cos_m';

bio(70).blkName='Catch Force Generator/ViscLoadSubsystem/sin';
bio(70).sigName='';
bio(70).portIdx=0;
bio(70).dim=[1,1];
bio(70).sigWidth=1;
bio(70).sigAddress='&bump_choice_B.sin_i';

bio(71).blkName='Force Generator/LorentzForce/Add';
bio(71).sigName='';
bio(71).portIdx=0;
bio(71).dim=[1,1];
bio(71).sigWidth=1;
bio(71).sigAddress='&bump_choice_B.Add';

bio(72).blkName='Force Generator/LorentzForce/Add1';
bio(72).sigName='';
bio(72).portIdx=0;
bio(72).dim=[1,1];
bio(72).sigWidth=1;
bio(72).sigAddress='&bump_choice_B.Add1_f';

bio(73).blkName='Force Generator/ViscLoadSubsystem/Gain';
bio(73).sigName='';
bio(73).portIdx=0;
bio(73).dim=[2,1];
bio(73).sigWidth=2;
bio(73).sigAddress='&bump_choice_B.Gain_d[0]';

bio(74).blkName='Force Generator/ViscLoadSubsystem/Inverter';
bio(74).sigName='';
bio(74).portIdx=0;
bio(74).dim=[2,1];
bio(74).sigWidth=2;
bio(74).sigAddress='&bump_choice_B.Inverter[0]';

bio(75).blkName='Force Generator/ViscLoadSubsystem/Product';
bio(75).sigName='';
bio(75).portIdx=0;
bio(75).dim=[1,1];
bio(75).sigWidth=1;
bio(75).sigAddress='&bump_choice_B.Product_a';

bio(76).blkName='Force Generator/ViscLoadSubsystem/Product1';
bio(76).sigName='';
bio(76).portIdx=0;
bio(76).dim=[1,1];
bio(76).sigWidth=1;
bio(76).sigAddress='&bump_choice_B.Product1_l';

bio(77).blkName='Force Generator/ViscLoadSubsystem/Product2';
bio(77).sigName='';
bio(77).portIdx=0;
bio(77).dim=[1,1];
bio(77).sigWidth=1;
bio(77).sigAddress='&bump_choice_B.Product2_l';

bio(78).blkName='Force Generator/ViscLoadSubsystem/Product3';
bio(78).sigName='';
bio(78).portIdx=0;
bio(78).dim=[1,1];
bio(78).sigWidth=1;
bio(78).sigAddress='&bump_choice_B.Product3_k';

bio(79).blkName='Force Generator/ViscLoadSubsystem/Add';
bio(79).sigName='';
bio(79).portIdx=0;
bio(79).dim=[1,1];
bio(79).sigWidth=1;
bio(79).sigAddress='&bump_choice_B.Add_h';

bio(80).blkName='Force Generator/ViscLoadSubsystem/Subtract';
bio(80).sigName='';
bio(80).portIdx=0;
bio(80).dim=[1,1];
bio(80).sigWidth=1;
bio(80).sigAddress='&bump_choice_B.Subtract_b';

bio(81).blkName='Force Generator/ViscLoadSubsystem/cos';
bio(81).sigName='';
bio(81).portIdx=0;
bio(81).dim=[1,1];
bio(81).sigWidth=1;
bio(81).sigAddress='&bump_choice_B.cos_c';

bio(82).blkName='Force Generator/ViscLoadSubsystem/sin';
bio(82).sigName='';
bio(82).portIdx=0;
bio(82).dim=[1,1];
bio(82).sigWidth=1;
bio(82).sigAddress='&bump_choice_B.sin_h';

bio(83).blkName='Motor Control/Compare To Constant/Compare';
bio(83).sigName='';
bio(83).portIdx=0;
bio(83).dim=[1,1];
bio(83).sigWidth=1;
bio(83).sigAddress='&bump_choice_B.Compare_p';

bio(84).blkName='Motor Control/Compare To Constant1/Compare';
bio(84).sigName='';
bio(84).portIdx=0;
bio(84).dim=[1,1];
bio(84).sigWidth=1;
bio(84).sigAddress='&bump_choice_B.Compare_hq';

bio(85).blkName='Motor Control/Force//Torque Transform/Gain';
bio(85).sigName='';
bio(85).portIdx=0;
bio(85).dim=[2,1];
bio(85).sigWidth=2;
bio(85).sigAddress='&bump_choice_B.Gain_i[0]';

bio(86).blkName='Motor Control/Force//Torque Transform/Matrix Multiply';
bio(86).sigName='';
bio(86).portIdx=0;
bio(86).dim=[2,1];
bio(86).sigWidth=2;
bio(86).sigAddress='&bump_choice_B.MatrixMultiply_c[0]';

bio(87).blkName='Motor Control/Schmidt/Clock';
bio(87).sigName='';
bio(87).portIdx=0;
bio(87).dim=[1,1];
bio(87).sigWidth=1;
bio(87).sigAddress='&bump_choice_B.Clock';

bio(88).blkName='Motor Control/Schmidt/Logical Operator';
bio(88).sigName='';
bio(88).portIdx=0;
bio(88).dim=[1,1];
bio(88).sigWidth=1;
bio(88).sigAddress='&bump_choice_B.LogicalOperator';

bio(89).blkName='Motor Control/Schmidt/Logical Operator1';
bio(89).sigName='';
bio(89).portIdx=0;
bio(89).dim=[1,1];
bio(89).sigWidth=1;
bio(89).sigAddress='&bump_choice_B.LogicalOperator1';

bio(90).blkName='Motor Control/Schmidt/Logical Operator2';
bio(90).sigName='';
bio(90).portIdx=0;
bio(90).dim=[1,1];
bio(90).sigWidth=1;
bio(90).sigAddress='&bump_choice_B.LogicalOperator2';

bio(91).blkName='Motor Control/Schmidt/Memory';
bio(91).sigName='';
bio(91).portIdx=0;
bio(91).dim=[1,1];
bio(91).sigWidth=1;
bio(91).sigAddress='&bump_choice_B.Memory';

bio(92).blkName='Motor Control/Schmidt/Relational Operator';
bio(92).sigName='';
bio(92).portIdx=0;
bio(92).dim=[1,1];
bio(92).sigWidth=1;
bio(92).sigAddress='&bump_choice_B.RelationalOperator';

bio(93).blkName='Motor Control/Schmidt/Sum';
bio(93).sigName='';
bio(93).portIdx=0;
bio(93).dim=[1,1];
bio(93).sigWidth=1;
bio(93).sigAddress='&bump_choice_B.Sum';

bio(94).blkName='Recentering Subsystem/Compare To Zero/Compare';
bio(94).sigName='';
bio(94).portIdx=0;
bio(94).dim=[1,1];
bio(94).sigWidth=1;
bio(94).sigAddress='&bump_choice_B.Compare_a';

bio(95).blkName='Recentering Subsystem/Compare To Zero1/Compare';
bio(95).sigName='';
bio(95).portIdx=0;
bio(95).dim=[1,1];
bio(95).sigWidth=1;
bio(95).sigAddress='&bump_choice_B.Compare_e';

bio(96).blkName='Recentering Subsystem/Falling Edge/FixPt Relational Operator';
bio(96).sigName='';
bio(96).portIdx=0;
bio(96).dim=[1,1];
bio(96).sigWidth=1;
bio(96).sigAddress='&bump_choice_B.FixPtRelationalOperator_o';

bio(97).blkName='Recentering Subsystem/Falling Edge/Delay Input1';
bio(97).sigName='U(k-1)';
bio(97).portIdx=0;
bio(97).dim=[1,1];
bio(97).sigWidth=1;
bio(97).sigAddress='&bump_choice_B.Uk1_m';

bio(98).blkName='Recentering Subsystem/Falling Edge1/FixPt Relational Operator';
bio(98).sigName='';
bio(98).portIdx=0;
bio(98).dim=[1,1];
bio(98).sigWidth=1;
bio(98).sigAddress='&bump_choice_B.FixPtRelationalOperator_j';

bio(99).blkName='Recentering Subsystem/Falling Edge1/Delay Input1';
bio(99).sigName='U(k-1)';
bio(99).portIdx=0;
bio(99).dim=[1,1];
bio(99).sigWidth=1;
bio(99).sigAddress='&bump_choice_B.Uk1_j';

bio(100).blkName='Recentering Subsystem/No Movement/Abs2';
bio(100).sigName='';
bio(100).portIdx=0;
bio(100).dim=[1,1];
bio(100).sigWidth=1;
bio(100).sigAddress='&bump_choice_B.Abs2';

bio(101).blkName='Recentering Subsystem/No Movement/Abs3';
bio(101).sigName='';
bio(101).portIdx=0;
bio(101).dim=[1,1];
bio(101).sigWidth=1;
bio(101).sigAddress='&bump_choice_B.Abs3';

bio(102).blkName='Recentering Subsystem/No Movement/Logical Operator1';
bio(102).sigName='';
bio(102).portIdx=0;
bio(102).dim=[1,1];
bio(102).sigWidth=1;
bio(102).sigAddress='&bump_choice_B.LogicalOperator1_e';

bio(103).blkName='Recentering Subsystem/PD Controller/Gain1';
bio(103).sigName='';
bio(103).portIdx=0;
bio(103).dim=[1,1];
bio(103).sigWidth=1;
bio(103).sigAddress='&bump_choice_B.Gain1_n';

bio(104).blkName='Recentering Subsystem/PD Controller/Gain2';
bio(104).sigName='';
bio(104).portIdx=0;
bio(104).dim=[1,1];
bio(104).sigWidth=1;
bio(104).sigAddress='&bump_choice_B.Gain2';

bio(105).blkName='Recentering Subsystem/PD Controller/Gain3';
bio(105).sigName='';
bio(105).portIdx=0;
bio(105).dim=[1,1];
bio(105).sigWidth=1;
bio(105).sigAddress='&bump_choice_B.Gain3';

bio(106).blkName='Recentering Subsystem/PD Controller/Gain4';
bio(106).sigName='';
bio(106).portIdx=0;
bio(106).dim=[1,1];
bio(106).sigWidth=1;
bio(106).sigAddress='&bump_choice_B.Gain4';

bio(107).blkName='Recentering Subsystem/PD Controller/Product';
bio(107).sigName='';
bio(107).portIdx=0;
bio(107).dim=[1,1];
bio(107).sigWidth=1;
bio(107).sigAddress='&bump_choice_B.Product_g';

bio(108).blkName='Recentering Subsystem/PD Controller/Product1';
bio(108).sigName='';
bio(108).portIdx=0;
bio(108).dim=[1,1];
bio(108).sigWidth=1;
bio(108).sigAddress='&bump_choice_B.Product1_o';

bio(109).blkName='Recentering Subsystem/PD Controller/Saturation';
bio(109).sigName='';
bio(109).portIdx=0;
bio(109).dim=[1,1];
bio(109).sigWidth=1;
bio(109).sigAddress='&bump_choice_B.Saturation';

bio(110).blkName='Recentering Subsystem/PD Controller/Saturation1';
bio(110).sigName='';
bio(110).portIdx=0;
bio(110).dim=[1,1];
bio(110).sigWidth=1;
bio(110).sigAddress='&bump_choice_B.Saturation1';

bio(111).blkName='Recentering Subsystem/PD Controller/Add';
bio(111).sigName='';
bio(111).portIdx=0;
bio(111).dim=[1,1];
bio(111).sigWidth=1;
bio(111).sigAddress='&bump_choice_B.Add_i';

bio(112).blkName='Recentering Subsystem/PD Controller/Add1';
bio(112).sigName='';
bio(112).portIdx=0;
bio(112).dim=[1,1];
bio(112).sigWidth=1;
bio(112).sigAddress='&bump_choice_B.Add1_ef';

bio(113).blkName='Recentering Subsystem/S-R Flip-Flop/Logic';
bio(113).sigName='';
bio(113).portIdx=0;
bio(113).dim=[2,1];
bio(113).sigWidth=2;
bio(113).sigAddress='&bump_choice_B.Logic[0]';

bio(114).blkName='Recentering Subsystem/S-R Flip-Flop/Memory';
bio(114).sigName='';
bio(114).portIdx=0;
bio(114).dim=[1,1];
bio(114).sigWidth=1;
bio(114).sigAddress='&bump_choice_B.Memory_j';

bio(115).blkName='Recentering Subsystem/Schmidt1/Clock';
bio(115).sigName='';
bio(115).portIdx=0;
bio(115).dim=[1,1];
bio(115).sigWidth=1;
bio(115).sigAddress='&bump_choice_B.Clock_k';

bio(116).blkName='Recentering Subsystem/Schmidt1/Logical Operator';
bio(116).sigName='';
bio(116).portIdx=0;
bio(116).dim=[1,1];
bio(116).sigWidth=1;
bio(116).sigAddress='&bump_choice_B.LogicalOperator_e';

bio(117).blkName='Recentering Subsystem/Schmidt1/Logical Operator1';
bio(117).sigName='';
bio(117).portIdx=0;
bio(117).dim=[1,1];
bio(117).sigWidth=1;
bio(117).sigAddress='&bump_choice_B.LogicalOperator1_c';

bio(118).blkName='Recentering Subsystem/Schmidt1/Logical Operator2';
bio(118).sigName='';
bio(118).portIdx=0;
bio(118).dim=[1,1];
bio(118).sigWidth=1;
bio(118).sigAddress='&bump_choice_B.LogicalOperator2_a';

bio(119).blkName='Recentering Subsystem/Schmidt1/Memory';
bio(119).sigName='';
bio(119).portIdx=0;
bio(119).dim=[1,1];
bio(119).sigWidth=1;
bio(119).sigAddress='&bump_choice_B.Memory_b';

bio(120).blkName='Recentering Subsystem/Schmidt1/Relational Operator';
bio(120).sigName='';
bio(120).portIdx=0;
bio(120).dim=[1,1];
bio(120).sigWidth=1;
bio(120).sigAddress='&bump_choice_B.RelationalOperator_l';

bio(121).blkName='Recentering Subsystem/Schmidt1/Sum';
bio(121).sigName='';
bio(121).portIdx=0;
bio(121).dim=[1,1];
bio(121).sigWidth=1;
bio(121).sigAddress='&bump_choice_B.Sum_l';

bio(122).blkName='Recentering Subsystem/Schmidt2/Clock';
bio(122).sigName='';
bio(122).portIdx=0;
bio(122).dim=[1,1];
bio(122).sigWidth=1;
bio(122).sigAddress='&bump_choice_B.Clock_d';

bio(123).blkName='Recentering Subsystem/Schmidt2/Logical Operator';
bio(123).sigName='';
bio(123).portIdx=0;
bio(123).dim=[1,1];
bio(123).sigWidth=1;
bio(123).sigAddress='&bump_choice_B.LogicalOperator_nd';

bio(124).blkName='Recentering Subsystem/Schmidt2/Logical Operator1';
bio(124).sigName='';
bio(124).portIdx=0;
bio(124).dim=[1,1];
bio(124).sigWidth=1;
bio(124).sigAddress='&bump_choice_B.LogicalOperator1_l';

bio(125).blkName='Recentering Subsystem/Schmidt2/Logical Operator2';
bio(125).sigName='';
bio(125).portIdx=0;
bio(125).dim=[1,1];
bio(125).sigWidth=1;
bio(125).sigAddress='&bump_choice_B.LogicalOperator2_i';

bio(126).blkName='Recentering Subsystem/Schmidt2/Memory';
bio(126).sigName='';
bio(126).portIdx=0;
bio(126).dim=[1,1];
bio(126).sigWidth=1;
bio(126).sigAddress='&bump_choice_B.Memory_m';

bio(127).blkName='Recentering Subsystem/Schmidt2/Relational Operator';
bio(127).sigName='';
bio(127).portIdx=0;
bio(127).dim=[1,1];
bio(127).sigWidth=1;
bio(127).sigAddress='&bump_choice_B.RelationalOperator_k';

bio(128).blkName='Recentering Subsystem/Schmidt2/Sum';
bio(128).sigName='';
bio(128).portIdx=0;
bio(128).dim=[1,1];
bio(128).sigWidth=1;
bio(128).sigAddress='&bump_choice_B.Sum_hb';

bio(129).blkName='Recentering Subsystem/Schmidt3/Clock';
bio(129).sigName='';
bio(129).portIdx=0;
bio(129).dim=[1,1];
bio(129).sigWidth=1;
bio(129).sigAddress='&bump_choice_B.Clock_p';

bio(130).blkName='Recentering Subsystem/Schmidt3/Logical Operator';
bio(130).sigName='';
bio(130).portIdx=0;
bio(130).dim=[1,1];
bio(130).sigWidth=1;
bio(130).sigAddress='&bump_choice_B.LogicalOperator_c';

bio(131).blkName='Recentering Subsystem/Schmidt3/Logical Operator1';
bio(131).sigName='';
bio(131).portIdx=0;
bio(131).dim=[1,1];
bio(131).sigWidth=1;
bio(131).sigAddress='&bump_choice_B.LogicalOperator1_i';

bio(132).blkName='Recentering Subsystem/Schmidt3/Logical Operator2';
bio(132).sigName='';
bio(132).portIdx=0;
bio(132).dim=[1,1];
bio(132).sigWidth=1;
bio(132).sigAddress='&bump_choice_B.LogicalOperator2_a2';

bio(133).blkName='Recentering Subsystem/Schmidt3/Memory';
bio(133).sigName='';
bio(133).portIdx=0;
bio(133).dim=[1,1];
bio(133).sigWidth=1;
bio(133).sigAddress='&bump_choice_B.Memory_n';

bio(134).blkName='Recentering Subsystem/Schmidt3/Relational Operator';
bio(134).sigName='';
bio(134).portIdx=0;
bio(134).dim=[1,1];
bio(134).sigWidth=1;
bio(134).sigAddress='&bump_choice_B.RelationalOperator_p';

bio(135).blkName='Recentering Subsystem/Schmidt3/Sum';
bio(135).sigName='';
bio(135).portIdx=0;
bio(135).dim=[1,1];
bio(135).sigWidth=1;
bio(135).sigAddress='&bump_choice_B.Sum_h';

bio(136).blkName='Recentering Subsystem/Start Moving/FixPt Relational Operator';
bio(136).sigName='';
bio(136).portIdx=0;
bio(136).dim=[1,1];
bio(136).sigWidth=1;
bio(136).sigAddress='&bump_choice_B.FixPtRelationalOperator_p';

bio(137).blkName='Recentering Subsystem/Start Moving/Delay Input1';
bio(137).sigName='U(k-1)';
bio(137).portIdx=0;
bio(137).dim=[1,1];
bio(137).sigWidth=1;
bio(137).sigAddress='&bump_choice_B.Uk1_c';

bio(138).blkName='Recentering Subsystem/Timer/Clock';
bio(138).sigName='';
bio(138).portIdx=0;
bio(138).dim=[1,1];
bio(138).sigWidth=1;
bio(138).sigAddress='&bump_choice_B.Clock_h';

bio(139).blkName='Recentering Subsystem/Timer/Logical Operator';
bio(139).sigName='';
bio(139).portIdx=0;
bio(139).dim=[1,1];
bio(139).sigWidth=1;
bio(139).sigAddress='&bump_choice_B.LogicalOperator_n';

bio(140).blkName='Recentering Subsystem/Timer/Logical Operator1';
bio(140).sigName='';
bio(140).portIdx=0;
bio(140).dim=[1,1];
bio(140).sigWidth=1;
bio(140).sigAddress='&bump_choice_B.LogicalOperator1_f';

bio(141).blkName='Recentering Subsystem/Timer/Logical Operator2';
bio(141).sigName='';
bio(141).portIdx=0;
bio(141).dim=[1,1];
bio(141).sigWidth=1;
bio(141).sigAddress='&bump_choice_B.LogicalOperator2_m';

bio(142).blkName='Recentering Subsystem/Timer/Logical Operator3';
bio(142).sigName='';
bio(142).portIdx=0;
bio(142).dim=[1,1];
bio(142).sigWidth=1;
bio(142).sigAddress='&bump_choice_B.LogicalOperator3';

bio(143).blkName='Recentering Subsystem/Timer/Logical Operator4';
bio(143).sigName='';
bio(143).portIdx=0;
bio(143).dim=[1,1];
bio(143).sigWidth=1;
bio(143).sigAddress='&bump_choice_B.LogicalOperator4';

bio(144).blkName='Recentering Subsystem/Timer/Logical Operator5';
bio(144).sigName='';
bio(144).portIdx=0;
bio(144).dim=[1,1];
bio(144).sigWidth=1;
bio(144).sigAddress='&bump_choice_B.LogicalOperator5';

bio(145).blkName='Recentering Subsystem/Timer/Memory';
bio(145).sigName='';
bio(145).portIdx=0;
bio(145).dim=[1,1];
bio(145).sigWidth=1;
bio(145).sigAddress='&bump_choice_B.Memory_b5';

bio(146).blkName='Recentering Subsystem/Timer/Relational Operator';
bio(146).sigName='';
bio(146).portIdx=0;
bio(146).dim=[1,1];
bio(146).sigWidth=1;
bio(146).sigAddress='&bump_choice_B.RelationalOperator_i';

bio(147).blkName='Recentering Subsystem/Timer/Sum';
bio(147).sigName='';
bio(147).portIdx=0;
bio(147).dim=[1,1];
bio(147).sigWidth=1;
bio(147).sigAddress='&bump_choice_B.Sum_n';

bio(148).blkName='RewardSbs/Sample and Hold/In';
bio(148).sigName='';
bio(148).portIdx=0;
bio(148).dim=[1,1];
bio(148).sigWidth=1;
bio(148).sigAddress='&bump_choice_B.SampleandHold_h.In';

bio(149).blkName='RewardSbs/Schmidt/Clock';
bio(149).sigName='';
bio(149).portIdx=0;
bio(149).dim=[1,1];
bio(149).sigWidth=1;
bio(149).sigAddress='&bump_choice_B.Clock_o';

bio(150).blkName='RewardSbs/Schmidt/Relational Operator';
bio(150).sigName='';
bio(150).portIdx=0;
bio(150).dim=[1,1];
bio(150).sigWidth=1;
bio(150).sigAddress='&bump_choice_B.RelationalOperator_b';

bio(151).blkName='RewardSbs/Schmidt/Sum';
bio(151).sigName='';
bio(151).portIdx=0;
bio(151).dim=[1,1];
bio(151).sigWidth=1;
bio(151).sigAddress='&bump_choice_B.Sum_p';

bio(152).blkName='Velocity Calculation/Pos2VelX/Derivative';
bio(152).sigName='';
bio(152).portIdx=0;
bio(152).dim=[1,1];
bio(152).sigWidth=1;
bio(152).sigAddress='&bump_choice_B.Derivative';

bio(153).blkName='Velocity Calculation/Pos2VelX/dG';
bio(153).sigName='';
bio(153).portIdx=0;
bio(153).dim=[1,1];
bio(153).sigWidth=1;
bio(153).sigAddress='&bump_choice_B.dG';

bio(154).blkName='Velocity Calculation/Pos2VelX/Digital Filter';
bio(154).sigName='';
bio(154).portIdx=0;
bio(154).dim=[1,1];
bio(154).sigWidth=1;
bio(154).sigAddress='&bump_choice_B.DigitalFilter';

bio(155).blkName='Velocity Calculation/Pos2VelX/Digital Filter2';
bio(155).sigName='';
bio(155).portIdx=0;
bio(155).dim=[1,1];
bio(155).sigWidth=1;
bio(155).sigAddress='&bump_choice_B.DigitalFilter2';

bio(156).blkName='Velocity Calculation/Pos2VelY/Derivative';
bio(156).sigName='';
bio(156).portIdx=0;
bio(156).dim=[1,1];
bio(156).sigWidth=1;
bio(156).sigAddress='&bump_choice_B.Derivative_i';

bio(157).blkName='Velocity Calculation/Pos2VelY/dG';
bio(157).sigName='';
bio(157).portIdx=0;
bio(157).dim=[1,1];
bio(157).sigWidth=1;
bio(157).sigAddress='&bump_choice_B.dG_c';

bio(158).blkName='Velocity Calculation/Pos2VelY/Digital Filter';
bio(158).sigName='';
bio(158).portIdx=0;
bio(158).dim=[1,1];
bio(158).sigWidth=1;
bio(158).sigAddress='&bump_choice_B.DigitalFilter_k';

bio(159).blkName='Velocity Calculation/Pos2VelY/Digital Filter2';
bio(159).sigName='';
bio(159).portIdx=0;
bio(159).dim=[1,1];
bio(159).sigWidth=1;
bio(159).sigAddress='&bump_choice_B.DigitalFilter2_c';

bio(160).blkName='XY Position Subsystem/Cursor Rotation/sqrt(u[1]*u[1] + u[2]*u[2])';
bio(160).sigName='';
bio(160).portIdx=0;
bio(160).dim=[1,1];
bio(160).sigWidth=1;
bio(160).sigAddress='&bump_choice_B.sqrtu1u1u2u2';

bio(161).blkName='XY Position Subsystem/Cursor Rotation/Product';
bio(161).sigName='';
bio(161).portIdx=0;
bio(161).dim=[1,1];
bio(161).sigWidth=1;
bio(161).sigAddress='&bump_choice_B.Product_f';

bio(162).blkName='XY Position Subsystem/Cursor Rotation/Product1';
bio(162).sigName='';
bio(162).portIdx=0;
bio(162).dim=[1,1];
bio(162).sigWidth=1;
bio(162).sigAddress='&bump_choice_B.Product1_b';

bio(163).blkName='XY Position Subsystem/Cursor Rotation/Sum';
bio(163).sigName='';
bio(163).portIdx=0;
bio(163).dim=[1,1];
bio(163).sigWidth=1;
bio(163).sigAddress='&bump_choice_B.Sum_c';

bio(164).blkName='XY Position Subsystem/Cursor Rotation/Trigonometric Function';
bio(164).sigName='';
bio(164).portIdx=0;
bio(164).dim=[1,1];
bio(164).sigWidth=1;
bio(164).sigAddress='&bump_choice_B.TrigonometricFunction_d';

bio(165).blkName='XY Position Subsystem/Cursor Rotation/Trigonometric Function1';
bio(165).sigName='';
bio(165).portIdx=0;
bio(165).dim=[1,1];
bio(165).sigWidth=1;
bio(165).sigAddress='&bump_choice_B.TrigonometricFunction1_o';

bio(166).blkName='XY Position Subsystem/Cursor Rotation/Trigonometric Function2';
bio(166).sigName='';
bio(166).portIdx=0;
bio(166).dim=[1,1];
bio(166).sigWidth=1;
bio(166).sigAddress='&bump_choice_B.TrigonometricFunction2_l';

bio(167).blkName='XY Position Subsystem/For Iterator Subsystem/For Iterator';
bio(167).sigName='';
bio(167).portIdx=0;
bio(167).dim=[1,1];
bio(167).sigWidth=1;
bio(167).sigAddress='&bump_choice_B.ForIterator';

bio(168).blkName='XY Position Subsystem/For Iterator Subsystem/SerialConverter';
bio(168).sigName='';
bio(168).portIdx=0;
bio(168).dim=[1,1];
bio(168).sigWidth=1;
bio(168).sigAddress='&bump_choice_B.SerialConverter';

bio(169).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p1';
bio(169).sigName='';
bio(169).portIdx=0;
bio(169).dim=[1,1];
bio(169).sigWidth=1;
bio(169).sigAddress='&bump_choice_B.ToBits_o1';

bio(170).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p2';
bio(170).sigName='';
bio(170).portIdx=1;
bio(170).dim=[1,1];
bio(170).sigWidth=1;
bio(170).sigAddress='&bump_choice_B.ToBits_o2';

bio(171).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p3';
bio(171).sigName='';
bio(171).portIdx=2;
bio(171).dim=[1,1];
bio(171).sigWidth=1;
bio(171).sigAddress='&bump_choice_B.ToBits_o3';

bio(172).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p4';
bio(172).sigName='';
bio(172).portIdx=3;
bio(172).dim=[1,1];
bio(172).sigWidth=1;
bio(172).sigAddress='&bump_choice_B.ToBits_o4';

bio(173).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p5';
bio(173).sigName='';
bio(173).portIdx=4;
bio(173).dim=[1,1];
bio(173).sigWidth=1;
bio(173).sigAddress='&bump_choice_B.ToBits_o5';

bio(174).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p6';
bio(174).sigName='';
bio(174).portIdx=5;
bio(174).dim=[1,1];
bio(174).sigWidth=1;
bio(174).sigAddress='&bump_choice_B.ToBits_o6';

bio(175).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p7';
bio(175).sigName='';
bio(175).portIdx=6;
bio(175).dim=[1,1];
bio(175).sigWidth=1;
bio(175).sigAddress='&bump_choice_B.ToBits_o7';

bio(176).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits/p8';
bio(176).sigName='';
bio(176).portIdx=7;
bio(176).dim=[1,1];
bio(176).sigWidth=1;
bio(176).sigAddress='&bump_choice_B.ToBits_o8';

bio(177).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits1/p1';
bio(177).sigName='';
bio(177).portIdx=0;
bio(177).dim=[1,1];
bio(177).sigWidth=1;
bio(177).sigAddress='&bump_choice_B.ToBits1_o1';

bio(178).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits1/p2';
bio(178).sigName='';
bio(178).portIdx=1;
bio(178).dim=[1,1];
bio(178).sigWidth=1;
bio(178).sigAddress='&bump_choice_B.ToBits1_o2';

bio(179).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits1/p3';
bio(179).sigName='';
bio(179).portIdx=2;
bio(179).dim=[1,1];
bio(179).sigWidth=1;
bio(179).sigAddress='&bump_choice_B.ToBits1_o3';

bio(180).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits1/p4';
bio(180).sigName='';
bio(180).portIdx=3;
bio(180).dim=[1,1];
bio(180).sigWidth=1;
bio(180).sigAddress='&bump_choice_B.ToBits1_o4';

bio(181).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits1/p5';
bio(181).sigName='';
bio(181).portIdx=4;
bio(181).dim=[1,1];
bio(181).sigWidth=1;
bio(181).sigAddress='&bump_choice_B.ToBits1_o5';

bio(182).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits1/p6';
bio(182).sigName='';
bio(182).portIdx=5;
bio(182).dim=[1,1];
bio(182).sigWidth=1;
bio(182).sigAddress='&bump_choice_B.ToBits1_o6';

bio(183).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits1/p7';
bio(183).sigName='';
bio(183).portIdx=6;
bio(183).dim=[1,1];
bio(183).sigWidth=1;
bio(183).sigAddress='&bump_choice_B.ToBits1_o7';

bio(184).blkName='XY Position Subsystem/For Iterator Subsystem/ToBits1/p8';
bio(184).sigName='';
bio(184).portIdx=7;
bio(184).dim=[1,1];
bio(184).sigWidth=1;
bio(184).sigAddress='&bump_choice_B.ToBits1_o8';

bio(185).blkName='XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ';
bio(185).sigName='';
bio(185).portIdx=0;
bio(185).dim=[1,1];
bio(185).sigWidth=1;
bio(185).sigAddress='&bump_choice_B.xPCTargetTime';

bio(186).blkName='XY Position Subsystem/For Iterator Subsystem/Add';
bio(186).sigName='';
bio(186).portIdx=0;
bio(186).dim=[1,1];
bio(186).sigWidth=1;
bio(186).sigAddress='&bump_choice_B.Add_ks';

bio(187).blkName='XY Position Subsystem/For Iterator Subsystem/Add1';
bio(187).sigName='';
bio(187).portIdx=0;
bio(187).dim=[1,1];
bio(187).sigWidth=1;
bio(187).sigAddress='&bump_choice_B.Add1_md';

bio(188).blkName='XY Position Subsystem/For Iterator Subsystem/Switch';
bio(188).sigName='';
bio(188).portIdx=0;
bio(188).dim=[1,1];
bio(188).sigWidth=1;
bio(188).sigAddress='&bump_choice_B.Switch_b';

bio(189).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate';
bio(189).sigName='';
bio(189).portIdx=0;
bio(189).dim=[2,2];
bio(189).sigWidth=4;
bio(189).sigAddress='&bump_choice_B.MatrixConcatenate2[0]';

bio(190).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate1';
bio(190).sigName='';
bio(190).portIdx=0;
bio(190).dim=[2,2];
bio(190).sigWidth=4;
bio(190).sigAddress='&bump_choice_B.MatrixConcatenate2[0]';

bio(191).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Matrix Concatenate2';
bio(191).sigName='';
bio(191).portIdx=0;
bio(191).dim=[2,2];
bio(191).sigWidth=4;
bio(191).sigAddress='&bump_choice_B.MatrixConcatenate2[0]';

bio(192).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Gain';
bio(192).sigName='';
bio(192).portIdx=0;
bio(192).dim=[2,2];
bio(192).sigWidth=4;
bio(192).sigAddress='&bump_choice_B.MatrixConcatenate2[0]';

bio(193).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Gain1';
bio(193).sigName='';
bio(193).portIdx=0;
bio(193).dim=[2,2];
bio(193).sigWidth=4;
bio(193).sigAddress='&bump_choice_B.MatrixConcatenate2[0]';

bio(194).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Gain2';
bio(194).sigName='';
bio(194).portIdx=0;
bio(194).dim=[2,2];
bio(194).sigWidth=4;
bio(194).sigAddress='&bump_choice_B.MatrixConcatenate2[0]';

bio(195).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Product';
bio(195).sigName='';
bio(195).portIdx=0;
bio(195).dim=[1,1];
bio(195).sigWidth=1;
bio(195).sigAddress='&bump_choice_B.Product';

bio(196).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Product1';
bio(196).sigName='';
bio(196).portIdx=0;
bio(196).dim=[1,1];
bio(196).sigWidth=1;
bio(196).sigAddress='&bump_choice_B.Product1';

bio(197).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Product2';
bio(197).sigName='';
bio(197).portIdx=0;
bio(197).dim=[1,1];
bio(197).sigWidth=1;
bio(197).sigAddress='&bump_choice_B.Product2';

bio(198).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Product3';
bio(198).sigName='';
bio(198).portIdx=0;
bio(198).dim=[1,1];
bio(198).sigWidth=1;
bio(198).sigAddress='&bump_choice_B.Product3';

bio(199).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum1';
bio(199).sigName='';
bio(199).portIdx=0;
bio(199).dim=[1,1];
bio(199).sigWidth=1;
bio(199).sigAddress='&bump_choice_B.Sum1_k';

bio(200).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum2';
bio(200).sigName='';
bio(200).portIdx=0;
bio(200).dim=[1,1];
bio(200).sigWidth=1;
bio(200).sigAddress='&bump_choice_B.Sum2';

bio(201).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum3';
bio(201).sigName='';
bio(201).portIdx=0;
bio(201).dim=[1,1];
bio(201).sigWidth=1;
bio(201).sigAddress='&bump_choice_B.Sum3_o';

bio(202).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Sum4';
bio(202).sigName='';
bio(202).portIdx=0;
bio(202).dim=[1,1];
bio(202).sigWidth=1;
bio(202).sigAddress='&bump_choice_B.Sum4';

bio(203).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function';
bio(203).sigName='';
bio(203).portIdx=0;
bio(203).dim=[1,1];
bio(203).sigWidth=1;
bio(203).sigAddress='&bump_choice_B.TrigonometricFunction';

bio(204).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function1';
bio(204).sigName='';
bio(204).portIdx=0;
bio(204).dim=[1,1];
bio(204).sigWidth=1;
bio(204).sigAddress='&bump_choice_B.TrigonometricFunction1';

bio(205).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function2';
bio(205).sigName='';
bio(205).portIdx=0;
bio(205).dim=[1,1];
bio(205).sigWidth=1;
bio(205).sigAddress='&bump_choice_B.TrigonometricFunction2';

bio(206).blkName='XY Position Subsystem/Jacobian-Cartesian Transformation/Trigonometric Function3';
bio(206).sigName='';
bio(206).portIdx=0;
bio(206).dim=[1,1];
bio(206).sigWidth=1;
bio(206).sigAddress='&bump_choice_B.TrigonometricFunction3';

bio(207).blkName='Catch Force Generator/LorentzForce/Lorentz/dX';
bio(207).sigName='';
bio(207).portIdx=0;
bio(207).dim=[1,1];
bio(207).sigWidth=1;
bio(207).sigAddress='&bump_choice_B.dX';

bio(208).blkName='Catch Force Generator/LorentzForce/Lorentz/dY';
bio(208).sigName='';
bio(208).portIdx=0;
bio(208).dim=[1,1];
bio(208).sigWidth=1;
bio(208).sigAddress='&bump_choice_B.dY';

bio(209).blkName='Catch Force Generator/LorentzForce/Lorentz/dZ';
bio(209).sigName='';
bio(209).portIdx=0;
bio(209).dim=[1,1];
bio(209).sigWidth=1;
bio(209).sigAddress='&bump_choice_B.dZ';

bio(210).blkName='Catch Force Generator/LorentzForce/Lorentz/product1';
bio(210).sigName='';
bio(210).portIdx=0;
bio(210).dim=[1,1];
bio(210).sigWidth=1;
bio(210).sigAddress='&bump_choice_B.product1';

bio(211).blkName='Catch Force Generator/LorentzForce/Lorentz/product2';
bio(211).sigName='';
bio(211).portIdx=0;
bio(211).dim=[1,1];
bio(211).sigWidth=1;
bio(211).sigAddress='&bump_choice_B.product2';

bio(212).blkName='Catch Force Generator/LorentzForce/Lorentz/product3';
bio(212).sigName='';
bio(212).portIdx=0;
bio(212).dim=[1,1];
bio(212).sigWidth=1;
bio(212).sigAddress='&bump_choice_B.product3';

bio(213).blkName='Catch Force Generator/LorentzForce/Lorentz/product4';
bio(213).sigName='';
bio(213).portIdx=0;
bio(213).dim=[1,1];
bio(213).sigWidth=1;
bio(213).sigAddress='&bump_choice_B.product4';

bio(214).blkName='Catch Force Generator/LorentzForce/Lorentz/Add1';
bio(214).sigName='';
bio(214).portIdx=0;
bio(214).dim=[1,1];
bio(214).sigWidth=1;
bio(214).sigAddress='&bump_choice_B.Add1';

bio(215).blkName='Catch Force Generator/LorentzForce/Lorentz/Add2';
bio(215).sigName='';
bio(215).portIdx=0;
bio(215).dim=[1,1];
bio(215).sigWidth=1;
bio(215).sigAddress='&bump_choice_B.Add2';

bio(216).blkName='Catch Force Generator/LorentzForce/Lorentz/Add3';
bio(216).sigName='';
bio(216).portIdx=0;
bio(216).dim=[1,1];
bio(216).sigWidth=1;
bio(216).sigAddress='&bump_choice_B.Add3';

bio(217).blkName='Catch Force Generator/LorentzForce/Lorentz/Add4';
bio(217).sigName='';
bio(217).portIdx=0;
bio(217).dim=[1,1];
bio(217).sigWidth=1;
bio(217).sigAddress='&bump_choice_B.Add4';

bio(218).blkName='Catch Force Generator/LorentzForce/Lorentz/AddX';
bio(218).sigName='';
bio(218).portIdx=0;
bio(218).dim=[1,1];
bio(218).sigWidth=1;
bio(218).sigAddress='&bump_choice_B.AddX';

bio(219).blkName='Catch Force Generator/LorentzForce/Lorentz/AddX1';
bio(219).sigName='';
bio(219).portIdx=0;
bio(219).dim=[1,1];
bio(219).sigWidth=1;
bio(219).sigAddress='&bump_choice_B.AddX1';

bio(220).blkName='Catch Force Generator/LorentzForce/Lorentz/AddX2';
bio(220).sigName='';
bio(220).portIdx=0;
bio(220).dim=[1,1];
bio(220).sigWidth=1;
bio(220).sigAddress='&bump_choice_B.AddX2';

bio(221).blkName='Catch Force Generator/LorentzForce/Lorentz/x';
bio(221).sigName='';
bio(221).portIdx=0;
bio(221).dim=[1,1];
bio(221).sigWidth=1;
bio(221).sigAddress='&bump_choice_B.x_b';

bio(222).blkName='Catch Force Generator/LorentzForce/Lorentz/y';
bio(222).sigName='';
bio(222).portIdx=0;
bio(222).dim=[1,1];
bio(222).sigWidth=1;
bio(222).sigAddress='&bump_choice_B.y';

bio(223).blkName='Catch Force Generator/LorentzForce/Lorentz/z';
bio(223).sigName='';
bio(223).portIdx=0;
bio(223).dim=[1,1];
bio(223).sigWidth=1;
bio(223).sigAddress='&bump_choice_B.z';

bio(224).blkName='Catch Force Generator/LorentzForce/Lorentz1/dX';
bio(224).sigName='';
bio(224).portIdx=0;
bio(224).dim=[1,1];
bio(224).sigWidth=1;
bio(224).sigAddress='&bump_choice_B.dX_c';

bio(225).blkName='Catch Force Generator/LorentzForce/Lorentz1/dY';
bio(225).sigName='';
bio(225).portIdx=0;
bio(225).dim=[1,1];
bio(225).sigWidth=1;
bio(225).sigAddress='&bump_choice_B.dY_d';

bio(226).blkName='Catch Force Generator/LorentzForce/Lorentz1/dZ';
bio(226).sigName='';
bio(226).portIdx=0;
bio(226).dim=[1,1];
bio(226).sigWidth=1;
bio(226).sigAddress='&bump_choice_B.dZ_f';

bio(227).blkName='Catch Force Generator/LorentzForce/Lorentz1/product1';
bio(227).sigName='';
bio(227).portIdx=0;
bio(227).dim=[1,1];
bio(227).sigWidth=1;
bio(227).sigAddress='&bump_choice_B.product1_b';

bio(228).blkName='Catch Force Generator/LorentzForce/Lorentz1/product2';
bio(228).sigName='';
bio(228).portIdx=0;
bio(228).dim=[1,1];
bio(228).sigWidth=1;
bio(228).sigAddress='&bump_choice_B.product2_a';

bio(229).blkName='Catch Force Generator/LorentzForce/Lorentz1/product3';
bio(229).sigName='';
bio(229).portIdx=0;
bio(229).dim=[1,1];
bio(229).sigWidth=1;
bio(229).sigAddress='&bump_choice_B.product3_h';

bio(230).blkName='Catch Force Generator/LorentzForce/Lorentz1/product4';
bio(230).sigName='';
bio(230).portIdx=0;
bio(230).dim=[1,1];
bio(230).sigWidth=1;
bio(230).sigAddress='&bump_choice_B.product4_e';

bio(231).blkName='Catch Force Generator/LorentzForce/Lorentz1/Add1';
bio(231).sigName='';
bio(231).portIdx=0;
bio(231).dim=[1,1];
bio(231).sigWidth=1;
bio(231).sigAddress='&bump_choice_B.Add1_l';

bio(232).blkName='Catch Force Generator/LorentzForce/Lorentz1/Add2';
bio(232).sigName='';
bio(232).portIdx=0;
bio(232).dim=[1,1];
bio(232).sigWidth=1;
bio(232).sigAddress='&bump_choice_B.Add2_p';

bio(233).blkName='Catch Force Generator/LorentzForce/Lorentz1/Add3';
bio(233).sigName='';
bio(233).portIdx=0;
bio(233).dim=[1,1];
bio(233).sigWidth=1;
bio(233).sigAddress='&bump_choice_B.Add3_j';

bio(234).blkName='Catch Force Generator/LorentzForce/Lorentz1/Add4';
bio(234).sigName='';
bio(234).portIdx=0;
bio(234).dim=[1,1];
bio(234).sigWidth=1;
bio(234).sigAddress='&bump_choice_B.Add4_c';

bio(235).blkName='Catch Force Generator/LorentzForce/Lorentz1/AddX';
bio(235).sigName='';
bio(235).portIdx=0;
bio(235).dim=[1,1];
bio(235).sigWidth=1;
bio(235).sigAddress='&bump_choice_B.AddX_h';

bio(236).blkName='Catch Force Generator/LorentzForce/Lorentz1/AddX1';
bio(236).sigName='';
bio(236).portIdx=0;
bio(236).dim=[1,1];
bio(236).sigWidth=1;
bio(236).sigAddress='&bump_choice_B.AddX1_b';

bio(237).blkName='Catch Force Generator/LorentzForce/Lorentz1/AddX2';
bio(237).sigName='';
bio(237).portIdx=0;
bio(237).dim=[1,1];
bio(237).sigWidth=1;
bio(237).sigAddress='&bump_choice_B.AddX2_d';

bio(238).blkName='Catch Force Generator/LorentzForce/Lorentz1/x';
bio(238).sigName='';
bio(238).portIdx=0;
bio(238).dim=[1,1];
bio(238).sigWidth=1;
bio(238).sigAddress='&bump_choice_B.x_c';

bio(239).blkName='Catch Force Generator/LorentzForce/Lorentz1/y';
bio(239).sigName='';
bio(239).portIdx=0;
bio(239).dim=[1,1];
bio(239).sigWidth=1;
bio(239).sigAddress='&bump_choice_B.y_d';

bio(240).blkName='Catch Force Generator/LorentzForce/Lorentz1/z';
bio(240).sigName='';
bio(240).portIdx=0;
bio(240).dim=[1,1];
bio(240).sigWidth=1;
bio(240).sigAddress='&bump_choice_B.z_i';

bio(241).blkName='Catch Force Generator/LorentzForce/Lorentz2/dX';
bio(241).sigName='';
bio(241).portIdx=0;
bio(241).dim=[1,1];
bio(241).sigWidth=1;
bio(241).sigAddress='&bump_choice_B.dX_k';

bio(242).blkName='Catch Force Generator/LorentzForce/Lorentz2/dY';
bio(242).sigName='';
bio(242).portIdx=0;
bio(242).dim=[1,1];
bio(242).sigWidth=1;
bio(242).sigAddress='&bump_choice_B.dY_l';

bio(243).blkName='Catch Force Generator/LorentzForce/Lorentz2/dZ';
bio(243).sigName='';
bio(243).portIdx=0;
bio(243).dim=[1,1];
bio(243).sigWidth=1;
bio(243).sigAddress='&bump_choice_B.dZ_o';

bio(244).blkName='Catch Force Generator/LorentzForce/Lorentz2/product1';
bio(244).sigName='';
bio(244).portIdx=0;
bio(244).dim=[1,1];
bio(244).sigWidth=1;
bio(244).sigAddress='&bump_choice_B.product1_g';

bio(245).blkName='Catch Force Generator/LorentzForce/Lorentz2/product2';
bio(245).sigName='';
bio(245).portIdx=0;
bio(245).dim=[1,1];
bio(245).sigWidth=1;
bio(245).sigAddress='&bump_choice_B.product2_c';

bio(246).blkName='Catch Force Generator/LorentzForce/Lorentz2/product3';
bio(246).sigName='';
bio(246).portIdx=0;
bio(246).dim=[1,1];
bio(246).sigWidth=1;
bio(246).sigAddress='&bump_choice_B.product3_p';

bio(247).blkName='Catch Force Generator/LorentzForce/Lorentz2/product4';
bio(247).sigName='';
bio(247).portIdx=0;
bio(247).dim=[1,1];
bio(247).sigWidth=1;
bio(247).sigAddress='&bump_choice_B.product4_g';

bio(248).blkName='Catch Force Generator/LorentzForce/Lorentz2/Add1';
bio(248).sigName='';
bio(248).portIdx=0;
bio(248).dim=[1,1];
bio(248).sigWidth=1;
bio(248).sigAddress='&bump_choice_B.Add1_g';

bio(249).blkName='Catch Force Generator/LorentzForce/Lorentz2/Add2';
bio(249).sigName='';
bio(249).portIdx=0;
bio(249).dim=[1,1];
bio(249).sigWidth=1;
bio(249).sigAddress='&bump_choice_B.Add2_f';

bio(250).blkName='Catch Force Generator/LorentzForce/Lorentz2/Add3';
bio(250).sigName='';
bio(250).portIdx=0;
bio(250).dim=[1,1];
bio(250).sigWidth=1;
bio(250).sigAddress='&bump_choice_B.Add3_o';

bio(251).blkName='Catch Force Generator/LorentzForce/Lorentz2/Add4';
bio(251).sigName='';
bio(251).portIdx=0;
bio(251).dim=[1,1];
bio(251).sigWidth=1;
bio(251).sigAddress='&bump_choice_B.Add4_g';

bio(252).blkName='Catch Force Generator/LorentzForce/Lorentz2/AddX';
bio(252).sigName='';
bio(252).portIdx=0;
bio(252).dim=[1,1];
bio(252).sigWidth=1;
bio(252).sigAddress='&bump_choice_B.AddX_n';

bio(253).blkName='Catch Force Generator/LorentzForce/Lorentz2/AddX1';
bio(253).sigName='';
bio(253).portIdx=0;
bio(253).dim=[1,1];
bio(253).sigWidth=1;
bio(253).sigAddress='&bump_choice_B.AddX1_a';

bio(254).blkName='Catch Force Generator/LorentzForce/Lorentz2/AddX2';
bio(254).sigName='';
bio(254).portIdx=0;
bio(254).dim=[1,1];
bio(254).sigWidth=1;
bio(254).sigAddress='&bump_choice_B.AddX2_e';

bio(255).blkName='Catch Force Generator/LorentzForce/Lorentz2/x';
bio(255).sigName='';
bio(255).portIdx=0;
bio(255).dim=[1,1];
bio(255).sigWidth=1;
bio(255).sigAddress='&bump_choice_B.x_j';

bio(256).blkName='Catch Force Generator/LorentzForce/Lorentz2/y';
bio(256).sigName='';
bio(256).portIdx=0;
bio(256).dim=[1,1];
bio(256).sigWidth=1;
bio(256).sigAddress='&bump_choice_B.y_a';

bio(257).blkName='Catch Force Generator/LorentzForce/Lorentz2/z';
bio(257).sigName='';
bio(257).portIdx=0;
bio(257).dim=[1,1];
bio(257).sigWidth=1;
bio(257).sigAddress='&bump_choice_B.z_g';

bio(258).blkName='Catch Force Generator/LorentzForce/Lorentz3/dX';
bio(258).sigName='';
bio(258).portIdx=0;
bio(258).dim=[1,1];
bio(258).sigWidth=1;
bio(258).sigAddress='&bump_choice_B.dX_m';

bio(259).blkName='Catch Force Generator/LorentzForce/Lorentz3/dY';
bio(259).sigName='';
bio(259).portIdx=0;
bio(259).dim=[1,1];
bio(259).sigWidth=1;
bio(259).sigAddress='&bump_choice_B.dY_b';

bio(260).blkName='Catch Force Generator/LorentzForce/Lorentz3/dZ';
bio(260).sigName='';
bio(260).portIdx=0;
bio(260).dim=[1,1];
bio(260).sigWidth=1;
bio(260).sigAddress='&bump_choice_B.dZ_m';

bio(261).blkName='Catch Force Generator/LorentzForce/Lorentz3/product1';
bio(261).sigName='';
bio(261).portIdx=0;
bio(261).dim=[1,1];
bio(261).sigWidth=1;
bio(261).sigAddress='&bump_choice_B.product1_l';

bio(262).blkName='Catch Force Generator/LorentzForce/Lorentz3/product2';
bio(262).sigName='';
bio(262).portIdx=0;
bio(262).dim=[1,1];
bio(262).sigWidth=1;
bio(262).sigAddress='&bump_choice_B.product2_l';

bio(263).blkName='Catch Force Generator/LorentzForce/Lorentz3/product3';
bio(263).sigName='';
bio(263).portIdx=0;
bio(263).dim=[1,1];
bio(263).sigWidth=1;
bio(263).sigAddress='&bump_choice_B.product3_d';

bio(264).blkName='Catch Force Generator/LorentzForce/Lorentz3/product4';
bio(264).sigName='';
bio(264).portIdx=0;
bio(264).dim=[1,1];
bio(264).sigWidth=1;
bio(264).sigAddress='&bump_choice_B.product4_f';

bio(265).blkName='Catch Force Generator/LorentzForce/Lorentz3/Add1';
bio(265).sigName='';
bio(265).portIdx=0;
bio(265).dim=[1,1];
bio(265).sigWidth=1;
bio(265).sigAddress='&bump_choice_B.Add1_e';

bio(266).blkName='Catch Force Generator/LorentzForce/Lorentz3/Add2';
bio(266).sigName='';
bio(266).portIdx=0;
bio(266).dim=[1,1];
bio(266).sigWidth=1;
bio(266).sigAddress='&bump_choice_B.Add2_o';

bio(267).blkName='Catch Force Generator/LorentzForce/Lorentz3/Add3';
bio(267).sigName='';
bio(267).portIdx=0;
bio(267).dim=[1,1];
bio(267).sigWidth=1;
bio(267).sigAddress='&bump_choice_B.Add3_m';

bio(268).blkName='Catch Force Generator/LorentzForce/Lorentz3/Add4';
bio(268).sigName='';
bio(268).portIdx=0;
bio(268).dim=[1,1];
bio(268).sigWidth=1;
bio(268).sigAddress='&bump_choice_B.Add4_j';

bio(269).blkName='Catch Force Generator/LorentzForce/Lorentz3/AddX';
bio(269).sigName='';
bio(269).portIdx=0;
bio(269).dim=[1,1];
bio(269).sigWidth=1;
bio(269).sigAddress='&bump_choice_B.AddX_j';

bio(270).blkName='Catch Force Generator/LorentzForce/Lorentz3/AddX1';
bio(270).sigName='';
bio(270).portIdx=0;
bio(270).dim=[1,1];
bio(270).sigWidth=1;
bio(270).sigAddress='&bump_choice_B.AddX1_d';

bio(271).blkName='Catch Force Generator/LorentzForce/Lorentz3/AddX2';
bio(271).sigName='';
bio(271).portIdx=0;
bio(271).dim=[1,1];
bio(271).sigWidth=1;
bio(271).sigAddress='&bump_choice_B.AddX2_eh';

bio(272).blkName='Catch Force Generator/LorentzForce/Lorentz3/x';
bio(272).sigName='';
bio(272).portIdx=0;
bio(272).dim=[1,1];
bio(272).sigWidth=1;
bio(272).sigAddress='&bump_choice_B.x_h';

bio(273).blkName='Catch Force Generator/LorentzForce/Lorentz3/y';
bio(273).sigName='';
bio(273).portIdx=0;
bio(273).dim=[1,1];
bio(273).sigWidth=1;
bio(273).sigAddress='&bump_choice_B.y_k';

bio(274).blkName='Catch Force Generator/LorentzForce/Lorentz3/z';
bio(274).sigName='';
bio(274).portIdx=0;
bio(274).dim=[1,1];
bio(274).sigWidth=1;
bio(274).sigAddress='&bump_choice_B.z_j';

bio(275).blkName='Force Generator/LorentzForce/Lorentz/dX';
bio(275).sigName='';
bio(275).portIdx=0;
bio(275).dim=[1,1];
bio(275).sigWidth=1;
bio(275).sigAddress='&bump_choice_B.dX_b';

bio(276).blkName='Force Generator/LorentzForce/Lorentz/dY';
bio(276).sigName='';
bio(276).portIdx=0;
bio(276).dim=[1,1];
bio(276).sigWidth=1;
bio(276).sigAddress='&bump_choice_B.dY_l3';

bio(277).blkName='Force Generator/LorentzForce/Lorentz/dZ';
bio(277).sigName='';
bio(277).portIdx=0;
bio(277).dim=[1,1];
bio(277).sigWidth=1;
bio(277).sigAddress='&bump_choice_B.dZ_l';

bio(278).blkName='Force Generator/LorentzForce/Lorentz/product1';
bio(278).sigName='';
bio(278).portIdx=0;
bio(278).dim=[1,1];
bio(278).sigWidth=1;
bio(278).sigAddress='&bump_choice_B.product1_a';

bio(279).blkName='Force Generator/LorentzForce/Lorentz/product2';
bio(279).sigName='';
bio(279).portIdx=0;
bio(279).dim=[1,1];
bio(279).sigWidth=1;
bio(279).sigAddress='&bump_choice_B.product2_j';

bio(280).blkName='Force Generator/LorentzForce/Lorentz/product3';
bio(280).sigName='';
bio(280).portIdx=0;
bio(280).dim=[1,1];
bio(280).sigWidth=1;
bio(280).sigAddress='&bump_choice_B.product3_j';

bio(281).blkName='Force Generator/LorentzForce/Lorentz/product4';
bio(281).sigName='';
bio(281).portIdx=0;
bio(281).dim=[1,1];
bio(281).sigWidth=1;
bio(281).sigAddress='&bump_choice_B.product4_p';

bio(282).blkName='Force Generator/LorentzForce/Lorentz/Add1';
bio(282).sigName='';
bio(282).portIdx=0;
bio(282).dim=[1,1];
bio(282).sigWidth=1;
bio(282).sigAddress='&bump_choice_B.Add1_gp';

bio(283).blkName='Force Generator/LorentzForce/Lorentz/Add2';
bio(283).sigName='';
bio(283).portIdx=0;
bio(283).dim=[1,1];
bio(283).sigWidth=1;
bio(283).sigAddress='&bump_choice_B.Add2_k';

bio(284).blkName='Force Generator/LorentzForce/Lorentz/Add3';
bio(284).sigName='';
bio(284).portIdx=0;
bio(284).dim=[1,1];
bio(284).sigWidth=1;
bio(284).sigAddress='&bump_choice_B.Add3_g';

bio(285).blkName='Force Generator/LorentzForce/Lorentz/Add4';
bio(285).sigName='';
bio(285).portIdx=0;
bio(285).dim=[1,1];
bio(285).sigWidth=1;
bio(285).sigAddress='&bump_choice_B.Add4_o';

bio(286).blkName='Force Generator/LorentzForce/Lorentz/AddX';
bio(286).sigName='';
bio(286).portIdx=0;
bio(286).dim=[1,1];
bio(286).sigWidth=1;
bio(286).sigAddress='&bump_choice_B.AddX_m';

bio(287).blkName='Force Generator/LorentzForce/Lorentz/AddX1';
bio(287).sigName='';
bio(287).portIdx=0;
bio(287).dim=[1,1];
bio(287).sigWidth=1;
bio(287).sigAddress='&bump_choice_B.AddX1_l';

bio(288).blkName='Force Generator/LorentzForce/Lorentz/AddX2';
bio(288).sigName='';
bio(288).portIdx=0;
bio(288).dim=[1,1];
bio(288).sigWidth=1;
bio(288).sigAddress='&bump_choice_B.AddX2_l';

bio(289).blkName='Force Generator/LorentzForce/Lorentz/x';
bio(289).sigName='';
bio(289).portIdx=0;
bio(289).dim=[1,1];
bio(289).sigWidth=1;
bio(289).sigAddress='&bump_choice_B.x';

bio(290).blkName='Force Generator/LorentzForce/Lorentz/y';
bio(290).sigName='';
bio(290).portIdx=0;
bio(290).dim=[1,1];
bio(290).sigWidth=1;
bio(290).sigAddress='&bump_choice_B.y_p';

bio(291).blkName='Force Generator/LorentzForce/Lorentz/z';
bio(291).sigName='';
bio(291).portIdx=0;
bio(291).dim=[1,1];
bio(291).sigWidth=1;
bio(291).sigAddress='&bump_choice_B.z_o';

bio(292).blkName='Force Generator/LorentzForce/Lorentz1/dX';
bio(292).sigName='';
bio(292).portIdx=0;
bio(292).dim=[1,1];
bio(292).sigWidth=1;
bio(292).sigAddress='&bump_choice_B.dX_h';

bio(293).blkName='Force Generator/LorentzForce/Lorentz1/dY';
bio(293).sigName='';
bio(293).portIdx=0;
bio(293).dim=[1,1];
bio(293).sigWidth=1;
bio(293).sigAddress='&bump_choice_B.dY_d5';

bio(294).blkName='Force Generator/LorentzForce/Lorentz1/dZ';
bio(294).sigName='';
bio(294).portIdx=0;
bio(294).dim=[1,1];
bio(294).sigWidth=1;
bio(294).sigAddress='&bump_choice_B.dZ_c';

bio(295).blkName='Force Generator/LorentzForce/Lorentz1/product1';
bio(295).sigName='';
bio(295).portIdx=0;
bio(295).dim=[1,1];
bio(295).sigWidth=1;
bio(295).sigAddress='&bump_choice_B.product1_e';

bio(296).blkName='Force Generator/LorentzForce/Lorentz1/product2';
bio(296).sigName='';
bio(296).portIdx=0;
bio(296).dim=[1,1];
bio(296).sigWidth=1;
bio(296).sigAddress='&bump_choice_B.product2_n';

bio(297).blkName='Force Generator/LorentzForce/Lorentz1/product3';
bio(297).sigName='';
bio(297).portIdx=0;
bio(297).dim=[1,1];
bio(297).sigWidth=1;
bio(297).sigAddress='&bump_choice_B.product3_ho';

bio(298).blkName='Force Generator/LorentzForce/Lorentz1/product4';
bio(298).sigName='';
bio(298).portIdx=0;
bio(298).dim=[1,1];
bio(298).sigWidth=1;
bio(298).sigAddress='&bump_choice_B.product4_p1';

bio(299).blkName='Force Generator/LorentzForce/Lorentz1/Add1';
bio(299).sigName='';
bio(299).portIdx=0;
bio(299).dim=[1,1];
bio(299).sigWidth=1;
bio(299).sigAddress='&bump_choice_B.Add1_h';

bio(300).blkName='Force Generator/LorentzForce/Lorentz1/Add2';
bio(300).sigName='';
bio(300).portIdx=0;
bio(300).dim=[1,1];
bio(300).sigWidth=1;
bio(300).sigAddress='&bump_choice_B.Add2_c';

bio(301).blkName='Force Generator/LorentzForce/Lorentz1/Add3';
bio(301).sigName='';
bio(301).portIdx=0;
bio(301).dim=[1,1];
bio(301).sigWidth=1;
bio(301).sigAddress='&bump_choice_B.Add3_f';

bio(302).blkName='Force Generator/LorentzForce/Lorentz1/Add4';
bio(302).sigName='';
bio(302).portIdx=0;
bio(302).dim=[1,1];
bio(302).sigWidth=1;
bio(302).sigAddress='&bump_choice_B.Add4_e';

bio(303).blkName='Force Generator/LorentzForce/Lorentz1/AddX';
bio(303).sigName='';
bio(303).portIdx=0;
bio(303).dim=[1,1];
bio(303).sigWidth=1;
bio(303).sigAddress='&bump_choice_B.AddX_i';

bio(304).blkName='Force Generator/LorentzForce/Lorentz1/AddX1';
bio(304).sigName='';
bio(304).portIdx=0;
bio(304).dim=[1,1];
bio(304).sigWidth=1;
bio(304).sigAddress='&bump_choice_B.AddX1_bb';

bio(305).blkName='Force Generator/LorentzForce/Lorentz1/AddX2';
bio(305).sigName='';
bio(305).portIdx=0;
bio(305).dim=[1,1];
bio(305).sigWidth=1;
bio(305).sigAddress='&bump_choice_B.AddX2_ec';

bio(306).blkName='Force Generator/LorentzForce/Lorentz1/x';
bio(306).sigName='';
bio(306).portIdx=0;
bio(306).dim=[1,1];
bio(306).sigWidth=1;
bio(306).sigAddress='&bump_choice_B.x_e';

bio(307).blkName='Force Generator/LorentzForce/Lorentz1/y';
bio(307).sigName='';
bio(307).portIdx=0;
bio(307).dim=[1,1];
bio(307).sigWidth=1;
bio(307).sigAddress='&bump_choice_B.y_am';

bio(308).blkName='Force Generator/LorentzForce/Lorentz1/z';
bio(308).sigName='';
bio(308).portIdx=0;
bio(308).dim=[1,1];
bio(308).sigWidth=1;
bio(308).sigAddress='&bump_choice_B.z_e';

bio(309).blkName='Force Generator/LorentzForce/Lorentz2/dX';
bio(309).sigName='';
bio(309).portIdx=0;
bio(309).dim=[1,1];
bio(309).sigWidth=1;
bio(309).sigAddress='&bump_choice_B.dX_l';

bio(310).blkName='Force Generator/LorentzForce/Lorentz2/dY';
bio(310).sigName='';
bio(310).portIdx=0;
bio(310).dim=[1,1];
bio(310).sigWidth=1;
bio(310).sigAddress='&bump_choice_B.dY_n';

bio(311).blkName='Force Generator/LorentzForce/Lorentz2/dZ';
bio(311).sigName='';
bio(311).portIdx=0;
bio(311).dim=[1,1];
bio(311).sigWidth=1;
bio(311).sigAddress='&bump_choice_B.dZ_p';

bio(312).blkName='Force Generator/LorentzForce/Lorentz2/product1';
bio(312).sigName='';
bio(312).portIdx=0;
bio(312).dim=[1,1];
bio(312).sigWidth=1;
bio(312).sigAddress='&bump_choice_B.product1_f';

bio(313).blkName='Force Generator/LorentzForce/Lorentz2/product2';
bio(313).sigName='';
bio(313).portIdx=0;
bio(313).dim=[1,1];
bio(313).sigWidth=1;
bio(313).sigAddress='&bump_choice_B.product2_f';

bio(314).blkName='Force Generator/LorentzForce/Lorentz2/product3';
bio(314).sigName='';
bio(314).portIdx=0;
bio(314).dim=[1,1];
bio(314).sigWidth=1;
bio(314).sigAddress='&bump_choice_B.product3_f';

bio(315).blkName='Force Generator/LorentzForce/Lorentz2/product4';
bio(315).sigName='';
bio(315).portIdx=0;
bio(315).dim=[1,1];
bio(315).sigWidth=1;
bio(315).sigAddress='&bump_choice_B.product4_et';

bio(316).blkName='Force Generator/LorentzForce/Lorentz2/Add1';
bio(316).sigName='';
bio(316).portIdx=0;
bio(316).dim=[1,1];
bio(316).sigWidth=1;
bio(316).sigAddress='&bump_choice_B.Add1_lc';

bio(317).blkName='Force Generator/LorentzForce/Lorentz2/Add2';
bio(317).sigName='';
bio(317).portIdx=0;
bio(317).dim=[1,1];
bio(317).sigWidth=1;
bio(317).sigAddress='&bump_choice_B.Add2_c5';

bio(318).blkName='Force Generator/LorentzForce/Lorentz2/Add3';
bio(318).sigName='';
bio(318).portIdx=0;
bio(318).dim=[1,1];
bio(318).sigWidth=1;
bio(318).sigAddress='&bump_choice_B.Add3_p';

bio(319).blkName='Force Generator/LorentzForce/Lorentz2/Add4';
bio(319).sigName='';
bio(319).portIdx=0;
bio(319).dim=[1,1];
bio(319).sigWidth=1;
bio(319).sigAddress='&bump_choice_B.Add4_ep';

bio(320).blkName='Force Generator/LorentzForce/Lorentz2/AddX';
bio(320).sigName='';
bio(320).portIdx=0;
bio(320).dim=[1,1];
bio(320).sigWidth=1;
bio(320).sigAddress='&bump_choice_B.AddX_l';

bio(321).blkName='Force Generator/LorentzForce/Lorentz2/AddX1';
bio(321).sigName='';
bio(321).portIdx=0;
bio(321).dim=[1,1];
bio(321).sigWidth=1;
bio(321).sigAddress='&bump_choice_B.AddX1_dm';

bio(322).blkName='Force Generator/LorentzForce/Lorentz2/AddX2';
bio(322).sigName='';
bio(322).portIdx=0;
bio(322).dim=[1,1];
bio(322).sigWidth=1;
bio(322).sigAddress='&bump_choice_B.AddX2_j';

bio(323).blkName='Force Generator/LorentzForce/Lorentz2/x';
bio(323).sigName='';
bio(323).portIdx=0;
bio(323).dim=[1,1];
bio(323).sigWidth=1;
bio(323).sigAddress='&bump_choice_B.x_et';

bio(324).blkName='Force Generator/LorentzForce/Lorentz2/y';
bio(324).sigName='';
bio(324).portIdx=0;
bio(324).dim=[1,1];
bio(324).sigWidth=1;
bio(324).sigAddress='&bump_choice_B.y_kr';

bio(325).blkName='Force Generator/LorentzForce/Lorentz2/z';
bio(325).sigName='';
bio(325).portIdx=0;
bio(325).dim=[1,1];
bio(325).sigWidth=1;
bio(325).sigAddress='&bump_choice_B.z_n';

bio(326).blkName='Force Generator/LorentzForce/Lorentz3/dX';
bio(326).sigName='';
bio(326).portIdx=0;
bio(326).dim=[1,1];
bio(326).sigWidth=1;
bio(326).sigAddress='&bump_choice_B.dX_h4';

bio(327).blkName='Force Generator/LorentzForce/Lorentz3/dY';
bio(327).sigName='';
bio(327).portIdx=0;
bio(327).dim=[1,1];
bio(327).sigWidth=1;
bio(327).sigAddress='&bump_choice_B.dY_be';

bio(328).blkName='Force Generator/LorentzForce/Lorentz3/dZ';
bio(328).sigName='';
bio(328).portIdx=0;
bio(328).dim=[1,1];
bio(328).sigWidth=1;
bio(328).sigAddress='&bump_choice_B.dZ_ft';

bio(329).blkName='Force Generator/LorentzForce/Lorentz3/product1';
bio(329).sigName='';
bio(329).portIdx=0;
bio(329).dim=[1,1];
bio(329).sigWidth=1;
bio(329).sigAddress='&bump_choice_B.product1_p';

bio(330).blkName='Force Generator/LorentzForce/Lorentz3/product2';
bio(330).sigName='';
bio(330).portIdx=0;
bio(330).dim=[1,1];
bio(330).sigWidth=1;
bio(330).sigAddress='&bump_choice_B.product2_b';

bio(331).blkName='Force Generator/LorentzForce/Lorentz3/product3';
bio(331).sigName='';
bio(331).portIdx=0;
bio(331).dim=[1,1];
bio(331).sigWidth=1;
bio(331).sigAddress='&bump_choice_B.product3_c';

bio(332).blkName='Force Generator/LorentzForce/Lorentz3/product4';
bio(332).sigName='';
bio(332).portIdx=0;
bio(332).dim=[1,1];
bio(332).sigWidth=1;
bio(332).sigAddress='&bump_choice_B.product4_eg';

bio(333).blkName='Force Generator/LorentzForce/Lorentz3/Add1';
bio(333).sigName='';
bio(333).portIdx=0;
bio(333).dim=[1,1];
bio(333).sigWidth=1;
bio(333).sigAddress='&bump_choice_B.Add1_m';

bio(334).blkName='Force Generator/LorentzForce/Lorentz3/Add2';
bio(334).sigName='';
bio(334).portIdx=0;
bio(334).dim=[1,1];
bio(334).sigWidth=1;
bio(334).sigAddress='&bump_choice_B.Add2_k3';

bio(335).blkName='Force Generator/LorentzForce/Lorentz3/Add3';
bio(335).sigName='';
bio(335).portIdx=0;
bio(335).dim=[1,1];
bio(335).sigWidth=1;
bio(335).sigAddress='&bump_choice_B.Add3_k';

bio(336).blkName='Force Generator/LorentzForce/Lorentz3/Add4';
bio(336).sigName='';
bio(336).portIdx=0;
bio(336).dim=[1,1];
bio(336).sigWidth=1;
bio(336).sigAddress='&bump_choice_B.Add4_l';

bio(337).blkName='Force Generator/LorentzForce/Lorentz3/AddX';
bio(337).sigName='';
bio(337).portIdx=0;
bio(337).dim=[1,1];
bio(337).sigWidth=1;
bio(337).sigAddress='&bump_choice_B.AddX_c';

bio(338).blkName='Force Generator/LorentzForce/Lorentz3/AddX1';
bio(338).sigName='';
bio(338).portIdx=0;
bio(338).dim=[1,1];
bio(338).sigWidth=1;
bio(338).sigAddress='&bump_choice_B.AddX1_c';

bio(339).blkName='Force Generator/LorentzForce/Lorentz3/AddX2';
bio(339).sigName='';
bio(339).portIdx=0;
bio(339).dim=[1,1];
bio(339).sigWidth=1;
bio(339).sigAddress='&bump_choice_B.AddX2_c';

bio(340).blkName='Force Generator/LorentzForce/Lorentz3/x';
bio(340).sigName='';
bio(340).portIdx=0;
bio(340).dim=[1,1];
bio(340).sigWidth=1;
bio(340).sigAddress='&bump_choice_B.x_d';

bio(341).blkName='Force Generator/LorentzForce/Lorentz3/y';
bio(341).sigName='';
bio(341).portIdx=0;
bio(341).dim=[1,1];
bio(341).sigWidth=1;
bio(341).sigAddress='&bump_choice_B.y_f';

bio(342).blkName='Force Generator/LorentzForce/Lorentz3/z';
bio(342).sigName='';
bio(342).portIdx=0;
bio(342).dim=[1,1];
bio(342).sigWidth=1;
bio(342).sigAddress='&bump_choice_B.z_n3';

bio(343).blkName='Motor Control/Force//Torque Transform/Transpose/Math Function';
bio(343).sigName='';
bio(343).portIdx=0;
bio(343).dim=[2,2];
bio(343).sigWidth=4;
bio(343).sigAddress='&bump_choice_B.MathFunction[0]';

bio(344).blkName='Motor Control/Schmidt/Compare To Zero/Compare';
bio(344).sigName='';
bio(344).portIdx=0;
bio(344).dim=[1,1];
bio(344).sigWidth=1;
bio(344).sigAddress='&bump_choice_B.Compare';

bio(345).blkName='Motor Control/Schmidt/Enabled Subsystem/In1';
bio(345).sigName='';
bio(345).portIdx=0;
bio(345).dim=[1,1];
bio(345).sigWidth=1;
bio(345).sigAddress='&bump_choice_B.EnabledSubsystem.In1';

bio(346).blkName='Recentering Subsystem/Falling Edge/Nonpositive/Compare';
bio(346).sigName='';
bio(346).portIdx=0;
bio(346).dim=[1,1];
bio(346).sigWidth=1;
bio(346).sigAddress='&bump_choice_B.Compare_dc';

bio(347).blkName='Recentering Subsystem/Falling Edge1/Nonpositive/Compare';
bio(347).sigName='';
bio(347).portIdx=0;
bio(347).dim=[1,1];
bio(347).sigWidth=1;
bio(347).sigAddress='&bump_choice_B.Compare_ez';

bio(348).blkName='Recentering Subsystem/No Movement/Compare To Constant2/Compare';
bio(348).sigName='';
bio(348).portIdx=0;
bio(348).dim=[1,1];
bio(348).sigWidth=1;
bio(348).sigAddress='&bump_choice_B.Compare_d';

bio(349).blkName='Recentering Subsystem/No Movement/Compare To Constant3/Compare';
bio(349).sigName='';
bio(349).portIdx=0;
bio(349).dim=[1,1];
bio(349).sigWidth=1;
bio(349).sigAddress='&bump_choice_B.Compare_dw';

bio(350).blkName='Recentering Subsystem/Schmidt1/Compare To Zero/Compare';
bio(350).sigName='';
bio(350).portIdx=0;
bio(350).dim=[1,1];
bio(350).sigWidth=1;
bio(350).sigAddress='&bump_choice_B.Compare_h';

bio(351).blkName='Recentering Subsystem/Schmidt1/Enabled Subsystem/In1';
bio(351).sigName='';
bio(351).portIdx=0;
bio(351).dim=[1,1];
bio(351).sigWidth=1;
bio(351).sigAddress='&bump_choice_B.EnabledSubsystem_p.In1';

bio(352).blkName='Recentering Subsystem/Schmidt2/Compare To Zero/Compare';
bio(352).sigName='';
bio(352).portIdx=0;
bio(352).dim=[1,1];
bio(352).sigWidth=1;
bio(352).sigAddress='&bump_choice_B.Compare_n';

bio(353).blkName='Recentering Subsystem/Schmidt2/Enabled Subsystem/In1';
bio(353).sigName='';
bio(353).portIdx=0;
bio(353).dim=[1,1];
bio(353).sigWidth=1;
bio(353).sigAddress='&bump_choice_B.EnabledSubsystem_o.In1';

bio(354).blkName='Recentering Subsystem/Schmidt3/Compare To Zero/Compare';
bio(354).sigName='';
bio(354).portIdx=0;
bio(354).dim=[1,1];
bio(354).sigWidth=1;
bio(354).sigAddress='&bump_choice_B.Compare_l';

bio(355).blkName='Recentering Subsystem/Schmidt3/Enabled Subsystem/In1';
bio(355).sigName='';
bio(355).portIdx=0;
bio(355).dim=[1,1];
bio(355).sigWidth=1;
bio(355).sigAddress='&bump_choice_B.EnabledSubsystem_e.In1';

bio(356).blkName='Recentering Subsystem/Start Moving/Nonpositive/Compare';
bio(356).sigName='';
bio(356).portIdx=0;
bio(356).dim=[1,1];
bio(356).sigWidth=1;
bio(356).sigAddress='&bump_choice_B.Compare_do';

bio(357).blkName='Recentering Subsystem/Timer/Compare To Zero/Compare';
bio(357).sigName='';
bio(357).portIdx=0;
bio(357).dim=[1,1];
bio(357).sigWidth=1;
bio(357).sigAddress='&bump_choice_B.Compare_o';

bio(358).blkName='Recentering Subsystem/Timer/Detect Fall Nonpositive/FixPt Relational Operator';
bio(358).sigName='';
bio(358).portIdx=0;
bio(358).dim=[1,1];
bio(358).sigWidth=1;
bio(358).sigAddress='&bump_choice_B.FixPtRelationalOperator';

bio(359).blkName='Recentering Subsystem/Timer/Detect Fall Nonpositive/Delay Input1';
bio(359).sigName='U(k-1)';
bio(359).portIdx=0;
bio(359).dim=[1,1];
bio(359).sigWidth=1;
bio(359).sigAddress='&bump_choice_B.Uk1';

bio(360).blkName='Recentering Subsystem/Timer/Enabled Subsystem/In1';
bio(360).sigName='';
bio(360).portIdx=0;
bio(360).dim=[1,1];
bio(360).sigWidth=1;
bio(360).sigAddress='&bump_choice_B.EnabledSubsystem_l.In1';

bio(361).blkName='RewardSbs/Schmidt/Sample and Hold/In';
bio(361).sigName='';
bio(361).portIdx=0;
bio(361).dim=[1,1];
bio(361).sigWidth=1;
bio(361).sigAddress='&bump_choice_B.SampleandHold.In';

bio(362).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec';
bio(362).sigName='';
bio(362).portIdx=0;
bio(362).dim=[1,1];
bio(362).sigWidth=1;
bio(362).sigAddress='&bump_choice_B.ScaleTouSec';

bio(363).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ';
bio(363).sigName='';
bio(363).portIdx=0;
bio(363).dim=[1,1];
bio(363).sigWidth=1;
bio(363).sigAddress='&bump_choice_B.xPCTargetTime_b';

bio(364).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Subtract';
bio(364).sigName='';
bio(364).portIdx=0;
bio(364).dim=[1,1];
bio(364).sigWidth=1;
bio(364).sigAddress='&bump_choice_B.Subtract';

bio(365).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Switch';
bio(365).sigName='';
bio(365).portIdx=0;
bio(365).dim=[1,1];
bio(365).sigWidth=1;
bio(365).sigAddress='&bump_choice_B.Switch_n';

bio(366).blkName='Recentering Subsystem/Timer/Detect Fall Nonpositive/Nonpositive/Compare';
bio(366).sigName='';
bio(366).portIdx=0;
bio(366).dim=[1,1];
bio(366).sigWidth=1;
bio(366).sigAddress='&bump_choice_B.Compare_k';

bio(367).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Compare';
bio(367).sigName='';
bio(367).portIdx=0;
bio(367).dim=[1,1];
bio(367).sigWidth=1;
bio(367).sigAddress='&bump_choice_B.Compare_b';

bio(368).blkName='XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1/Compare';
bio(368).sigName='';
bio(368).portIdx=0;
bio(368).dim=[1,1];
bio(368).sigWidth=1;
bio(368).sigAddress='&bump_choice_B.Compare_c';

function len = getlenBIO
len = 368;

