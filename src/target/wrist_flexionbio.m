function bio=wrist_flexionbio
bio = [];
bio(1).blkName='Rad2Deg';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&wrist_flexion_B.Rad2Deg';
bio(getlenBIO) = bio(1);

bio(2).blkName='Memory';
bio(2).sigName='Rotation';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&wrist_flexion_B.Rotation';

bio(3).blkName='Reshape';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[96,1];
bio(3).sigWidth=96;
bio(3).sigAddress='&wrist_flexion_B.Reshape[0]';

bio(4).blkName='Behavior WF/p1';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&wrist_flexion_B.BehaviorWF_o1';

bio(5).blkName='Behavior WF/p2';
bio(5).sigName='';
bio(5).portIdx=1;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&wrist_flexion_B.BehaviorWF_o2';

bio(6).blkName='Behavior WF/p3';
bio(6).sigName='';
bio(6).portIdx=2;
bio(6).dim=[4,1];
bio(6).sigWidth=4;
bio(6).sigAddress='&wrist_flexion_B.BehaviorWF_o3[0]';

bio(7).blkName='Behavior WF/p4';
bio(7).sigName='';
bio(7).portIdx=3;
bio(7).dim=[2,1];
bio(7).sigWidth=2;
bio(7).sigAddress='&wrist_flexion_B.BehaviorWF_o4[0]';

bio(8).blkName='Behavior WF/p5';
bio(8).sigName='';
bio(8).portIdx=4;
bio(8).dim=[10,1];
bio(8).sigWidth=10;
bio(8).sigAddress='&wrist_flexion_B.BehaviorWF_o5[0]';

bio(9).blkName='Behavior WF/p6';
bio(9).sigName='';
bio(9).portIdx=5;
bio(9).dim=[8,1];
bio(9).sigWidth=8;
bio(9).sigAddress='&wrist_flexion_B.BehaviorWF_o6[0]';

bio(10).blkName='Behavior WF/p7';
bio(10).sigName='';
bio(10).portIdx=6;
bio(10).dim=[4,1];
bio(10).sigWidth=4;
bio(10).sigAddress='&wrist_flexion_B.BehaviorWF_o7[0]';

bio(11).blkName='Behavior WF/p8';
bio(11).sigName='';
bio(11).portIdx=7;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&wrist_flexion_B.BehaviorWF_o8';

bio(12).blkName='WFTargetTable';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[6,16];
bio(12).sigWidth=96;
bio(12).sigAddress='&wrist_flexion_B.WFTargetTable[0]';

bio(13).blkName='CursorPos/GainX';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[1,1];
bio(13).sigWidth=1;
bio(13).sigAddress='&wrist_flexion_B.GainX';

bio(14).blkName='CursorPos/GainY';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&wrist_flexion_B.GainY';

bio(15).blkName='CursorPos/Integrator';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[2,1];
bio(15).sigWidth=2;
bio(15).sigAddress='&wrist_flexion_B.Integrator[0]';

bio(16).blkName='CursorPos/Saturation';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&wrist_flexion_B.Saturation';

bio(17).blkName='CursorPos/PCI-6025E /p1';
bio(17).sigName='RawX';
bio(17).portIdx=0;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&wrist_flexion_B.RawX';

bio(18).blkName='CursorPos/PCI-6025E /p2';
bio(18).sigName='RawY';
bio(18).portIdx=1;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&wrist_flexion_B.RawY';

bio(19).blkName='CursorPos/Receive/p1';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[16,1];
bio(19).sigWidth=16;
bio(19).sigAddress='&wrist_flexion_B.Receive_o1[0]';

bio(20).blkName='CursorPos/Receive/p2';
bio(20).sigName='';
bio(20).portIdx=1;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&wrist_flexion_B.Receive_o2';

bio(21).blkName='CursorPos/Unpack';
bio(21).sigName='';
bio(21).portIdx=0;
bio(21).dim=[1,4];
bio(21).sigWidth=4;
bio(21).sigAddress='&wrist_flexion_B.Unpack[0]';

bio(22).blkName='CursorPos/LowPassFilterX';
bio(22).sigName='';
bio(22).portIdx=0;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&wrist_flexion_B.LowPassFilterX';

bio(23).blkName='CursorPos/LowPassFilterY';
bio(23).sigName='';
bio(23).portIdx=0;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&wrist_flexion_B.LowPassFilterY';

bio(24).blkName='CursorPos/Sum1';
bio(24).sigName='';
bio(24).portIdx=0;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&wrist_flexion_B.Sum1_n';

bio(25).blkName='CursorPos/Sum2';
bio(25).sigName='';
bio(25).portIdx=0;
bio(25).dim=[1,1];
bio(25).sigWidth=1;
bio(25).sigAddress='&wrist_flexion_B.Sum2_c';

bio(26).blkName='CursorPos/Switch';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&wrist_flexion_B.Switch';

bio(27).blkName='CursorPos/Switch1';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&wrist_flexion_B.Switch1';

bio(28).blkName='CursorPos/Switch2';
bio(28).sigName='';
bio(28).portIdx=0;
bio(28).dim=[2,1];
bio(28).sigWidth=2;
bio(28).sigAddress='&wrist_flexion_B.Switch2[0]';

bio(29).blkName='RewardSbs/Data Type Conversion';
bio(29).sigName='';
bio(29).portIdx=0;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&wrist_flexion_B.DataTypeConversion';

bio(30).blkName='RewardSbs/Relational Operator';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&wrist_flexion_B.RelationalOperator';

bio(31).blkName='RewardSbs/Switch';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&wrist_flexion_B.Switch_i';

bio(32).blkName='RewardSbs/Uniform Random Number';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&wrist_flexion_B.UniformRandomNumber';

bio(33).blkName='UDPXmit/Rate Transition';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[112,1];
bio(33).sigWidth=112;
bio(33).sigAddress='&wrist_flexion_B.RateTransition[0]';

bio(34).blkName='UDPXmit/Pack';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[112,1];
bio(34).sigWidth=112;
bio(34).sigAddress='&wrist_flexion_B.Pack[0]';

bio(35).blkName='WordSbs/For Iterator';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[1,1];
bio(35).sigWidth=1;
bio(35).sigAddress='&wrist_flexion_B.ForIterator';

bio(36).blkName='WordSbs/toThousandths';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[2,1];
bio(36).sigWidth=2;
bio(36).sigAddress='&wrist_flexion_B.toThousandths[0]';

bio(37).blkName='WordSbs/SerialConverter';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[1,1];
bio(37).sigWidth=1;
bio(37).sigAddress='&wrist_flexion_B.SerialConverter';

bio(38).blkName='WordSbs/ToBits/p1';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&wrist_flexion_B.ToBits_o1';

bio(39).blkName='WordSbs/ToBits/p2';
bio(39).sigName='';
bio(39).portIdx=1;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&wrist_flexion_B.ToBits_o2';

bio(40).blkName='WordSbs/ToBits/p3';
bio(40).sigName='';
bio(40).portIdx=2;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&wrist_flexion_B.ToBits_o3';

bio(41).blkName='WordSbs/ToBits/p4';
bio(41).sigName='';
bio(41).portIdx=3;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&wrist_flexion_B.ToBits_o4';

bio(42).blkName='WordSbs/ToBits/p5';
bio(42).sigName='';
bio(42).portIdx=4;
bio(42).dim=[1,1];
bio(42).sigWidth=1;
bio(42).sigAddress='&wrist_flexion_B.ToBits_o5';

bio(43).blkName='WordSbs/ToBits/p6';
bio(43).sigName='';
bio(43).portIdx=5;
bio(43).dim=[1,1];
bio(43).sigWidth=1;
bio(43).sigAddress='&wrist_flexion_B.ToBits_o6';

bio(44).blkName='WordSbs/ToBits/p7';
bio(44).sigName='';
bio(44).portIdx=6;
bio(44).dim=[1,1];
bio(44).sigWidth=1;
bio(44).sigAddress='&wrist_flexion_B.ToBits_o7';

bio(45).blkName='WordSbs/ToBits/p8';
bio(45).sigName='';
bio(45).portIdx=7;
bio(45).dim=[1,1];
bio(45).sigWidth=1;
bio(45).sigAddress='&wrist_flexion_B.ToBits_o8';

bio(46).blkName='WordSbs/ToBits1/p1';
bio(46).sigName='';
bio(46).portIdx=0;
bio(46).dim=[1,1];
bio(46).sigWidth=1;
bio(46).sigAddress='&wrist_flexion_B.ToBits1_o1';

bio(47).blkName='WordSbs/ToBits1/p2';
bio(47).sigName='';
bio(47).portIdx=1;
bio(47).dim=[1,1];
bio(47).sigWidth=1;
bio(47).sigAddress='&wrist_flexion_B.ToBits1_o2';

bio(48).blkName='WordSbs/ToBits1/p3';
bio(48).sigName='';
bio(48).portIdx=2;
bio(48).dim=[1,1];
bio(48).sigWidth=1;
bio(48).sigAddress='&wrist_flexion_B.ToBits1_o3';

bio(49).blkName='WordSbs/ToBits1/p4';
bio(49).sigName='';
bio(49).portIdx=3;
bio(49).dim=[1,1];
bio(49).sigWidth=1;
bio(49).sigAddress='&wrist_flexion_B.ToBits1_o4';

bio(50).blkName='WordSbs/ToBits1/p5';
bio(50).sigName='';
bio(50).portIdx=4;
bio(50).dim=[1,1];
bio(50).sigWidth=1;
bio(50).sigAddress='&wrist_flexion_B.ToBits1_o5';

bio(51).blkName='WordSbs/ToBits1/p6';
bio(51).sigName='';
bio(51).portIdx=5;
bio(51).dim=[1,1];
bio(51).sigWidth=1;
bio(51).sigAddress='&wrist_flexion_B.ToBits1_o6';

bio(52).blkName='WordSbs/ToBits1/p7';
bio(52).sigName='';
bio(52).portIdx=6;
bio(52).dim=[1,1];
bio(52).sigWidth=1;
bio(52).sigAddress='&wrist_flexion_B.ToBits1_o7';

bio(53).blkName='WordSbs/ToBits1/p8';
bio(53).sigName='';
bio(53).portIdx=7;
bio(53).dim=[1,1];
bio(53).sigWidth=1;
bio(53).sigAddress='&wrist_flexion_B.ToBits1_o8';

bio(54).blkName='WordSbs/xPC Target  Time ';
bio(54).sigName='';
bio(54).portIdx=0;
bio(54).dim=[1,1];
bio(54).sigWidth=1;
bio(54).sigAddress='&wrist_flexion_B.xPCTargetTime';

bio(55).blkName='WordSbs/Add2';
bio(55).sigName='';
bio(55).portIdx=0;
bio(55).dim=[1,1];
bio(55).sigWidth=1;
bio(55).sigAddress='&wrist_flexion_B.Add2';

bio(56).blkName='WordSbs/Add3';
bio(56).sigName='';
bio(56).portIdx=0;
bio(56).dim=[1,1];
bio(56).sigWidth=1;
bio(56).sigAddress='&wrist_flexion_B.Add3';

bio(57).blkName='WordSbs/Switch';
bio(57).sigName='';
bio(57).portIdx=0;
bio(57).dim=[1,1];
bio(57).sigWidth=1;
bio(57).sigAddress='&wrist_flexion_B.Switch_e';

bio(58).blkName='CursorPos/Cursor Rotation/sqrt(u[1]*u[1] + u[2]*u[2])';
bio(58).sigName='';
bio(58).portIdx=0;
bio(58).dim=[1,1];
bio(58).sigWidth=1;
bio(58).sigAddress='&wrist_flexion_B.sqrtu1u1u2u2';

bio(59).blkName='CursorPos/Cursor Rotation/Product';
bio(59).sigName='';
bio(59).portIdx=0;
bio(59).dim=[1,1];
bio(59).sigWidth=1;
bio(59).sigAddress='&wrist_flexion_B.Product_p';

bio(60).blkName='CursorPos/Cursor Rotation/Product1';
bio(60).sigName='';
bio(60).portIdx=0;
bio(60).dim=[1,1];
bio(60).sigWidth=1;
bio(60).sigAddress='&wrist_flexion_B.Product1_a';

bio(61).blkName='CursorPos/Cursor Rotation/Sum';
bio(61).sigName='';
bio(61).portIdx=0;
bio(61).dim=[1,1];
bio(61).sigWidth=1;
bio(61).sigAddress='&wrist_flexion_B.Sum_a';

bio(62).blkName='CursorPos/Cursor Rotation/Trigonometric Function';
bio(62).sigName='';
bio(62).portIdx=0;
bio(62).dim=[1,1];
bio(62).sigWidth=1;
bio(62).sigAddress='&wrist_flexion_B.TrigonometricFunction';

bio(63).blkName='CursorPos/Cursor Rotation/Trigonometric Function1';
bio(63).sigName='';
bio(63).portIdx=0;
bio(63).dim=[1,1];
bio(63).sigWidth=1;
bio(63).sigAddress='&wrist_flexion_B.TrigonometricFunction1';

bio(64).blkName='CursorPos/Cursor Rotation/Trigonometric Function2';
bio(64).sigName='';
bio(64).portIdx=0;
bio(64).dim=[1,1];
bio(64).sigWidth=1;
bio(64).sigAddress='&wrist_flexion_B.TrigonometricFunction2';

bio(65).blkName='CursorPos/Neural Control Subsystem/PctToFrac';
bio(65).sigName='';
bio(65).portIdx=0;
bio(65).dim=[1,1];
bio(65).sigWidth=1;
bio(65).sigAddress='&wrist_flexion_B.PctToFrac';

bio(66).blkName='CursorPos/Neural Control Subsystem/Product';
bio(66).sigName='';
bio(66).portIdx=0;
bio(66).dim=[2,1];
bio(66).sigWidth=2;
bio(66).sigAddress='&wrist_flexion_B.Product[0]';

bio(67).blkName='CursorPos/Neural Control Subsystem/Product1';
bio(67).sigName='';
bio(67).portIdx=0;
bio(67).dim=[2,1];
bio(67).sigWidth=2;
bio(67).sigAddress='&wrist_flexion_B.Product1[0]';

bio(68).blkName='CursorPos/Neural Control Subsystem/Sum';
bio(68).sigName='';
bio(68).portIdx=0;
bio(68).dim=[1,1];
bio(68).sigWidth=1;
bio(68).sigAddress='&wrist_flexion_B.Sum';

bio(69).blkName='CursorPos/Neural Control Subsystem/Sum1';
bio(69).sigName='';
bio(69).portIdx=0;
bio(69).dim=[1,1];
bio(69).sigWidth=1;
bio(69).sigAddress='&wrist_flexion_B.Sum1';

bio(70).blkName='CursorPos/Neural Control Subsystem/Sum2';
bio(70).sigName='';
bio(70).portIdx=0;
bio(70).dim=[1,1];
bio(70).sigWidth=1;
bio(70).sigAddress='&wrist_flexion_B.Sum2';

bio(71).blkName='CursorPos/Neural Control Subsystem/Override';
bio(71).sigName='';
bio(71).portIdx=0;
bio(71).dim=[1,1];
bio(71).sigWidth=1;
bio(71).sigAddress='&wrist_flexion_B.Override';

bio(72).blkName='RewardSbs/Sample and Hold/In';
bio(72).sigName='';
bio(72).portIdx=0;
bio(72).dim=[1,1];
bio(72).sigWidth=1;
bio(72).sigAddress='&wrist_flexion_B.SampleandHold_k.In';

bio(73).blkName='RewardSbs/Schmidt/Clock';
bio(73).sigName='';
bio(73).portIdx=0;
bio(73).dim=[1,1];
bio(73).sigWidth=1;
bio(73).sigAddress='&wrist_flexion_B.Clock';

bio(74).blkName='RewardSbs/Schmidt/Relational Operator';
bio(74).sigName='';
bio(74).portIdx=0;
bio(74).dim=[1,1];
bio(74).sigWidth=1;
bio(74).sigAddress='&wrist_flexion_B.RelationalOperator_f';

bio(75).blkName='RewardSbs/Schmidt/Sum';
bio(75).sigName='';
bio(75).portIdx=0;
bio(75).dim=[1,1];
bio(75).sigWidth=1;
bio(75).sigAddress='&wrist_flexion_B.Sum_m';

bio(76).blkName='WordSbs/While Iterator Subsystem/ScaleTouSec';
bio(76).sigName='';
bio(76).portIdx=0;
bio(76).dim=[1,1];
bio(76).sigWidth=1;
bio(76).sigAddress='&wrist_flexion_B.ScaleTouSec';

bio(77).blkName='WordSbs/While Iterator Subsystem/xPC Target  Time ';
bio(77).sigName='';
bio(77).portIdx=0;
bio(77).dim=[1,1];
bio(77).sigWidth=1;
bio(77).sigAddress='&wrist_flexion_B.xPCTargetTime_a';

bio(78).blkName='WordSbs/While Iterator Subsystem/Subtract';
bio(78).sigName='';
bio(78).portIdx=0;
bio(78).dim=[1,1];
bio(78).sigWidth=1;
bio(78).sigAddress='&wrist_flexion_B.Subtract';

bio(79).blkName='WordSbs/While Iterator Subsystem/Switch';
bio(79).sigName='';
bio(79).portIdx=0;
bio(79).dim=[1,1];
bio(79).sigWidth=1;
bio(79).sigAddress='&wrist_flexion_B.Switch_o';

bio(80).blkName='RewardSbs/Schmidt/Sample and Hold/In';
bio(80).sigName='';
bio(80).portIdx=0;
bio(80).dim=[1,1];
bio(80).sigWidth=1;
bio(80).sigAddress='&wrist_flexion_B.SampleandHold.In';

bio(81).blkName='WordSbs/While Iterator Subsystem/Compare To Constant/Compare';
bio(81).sigName='';
bio(81).portIdx=0;
bio(81).dim=[1,1];
bio(81).sigWidth=1;
bio(81).sigAddress='&wrist_flexion_B.Compare_h';

bio(82).blkName='WordSbs/While Iterator Subsystem/Compare To Constant1/Compare';
bio(82).sigName='';
bio(82).portIdx=0;
bio(82).dim=[1,1];
bio(82).sigWidth=1;
bio(82).sigAddress='&wrist_flexion_B.Compare';

function len = getlenBIO
len = 82;

