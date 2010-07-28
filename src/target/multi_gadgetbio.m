function bio=multi_gadgetbio
bio = [];
bio(1).blkName='Reshape';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[80,1];
bio(1).sigWidth=80;
bio(1).sigAddress='&multi_gadget_B.Reshape[0]';
bio(getlenBIO) = bio(1);

bio(2).blkName='Behavior MG/p1';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&multi_gadget_B.BehaviorMG_o1';

bio(3).blkName='Behavior MG/p2';
bio(3).sigName='';
bio(3).portIdx=1;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&multi_gadget_B.BehaviorMG_o2';

bio(4).blkName='Behavior MG/p3';
bio(4).sigName='';
bio(4).portIdx=2;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&multi_gadget_B.BehaviorMG_o3';

bio(5).blkName='Behavior MG/p4';
bio(5).sigName='';
bio(5).portIdx=3;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&multi_gadget_B.BehaviorMG_o4';

bio(6).blkName='Behavior MG/p5';
bio(6).sigName='';
bio(6).portIdx=4;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&multi_gadget_B.BehaviorMG_o5';

bio(7).blkName='Behavior MG/p6';
bio(7).sigName='';
bio(7).portIdx=5;
bio(7).dim=[4,1];
bio(7).sigWidth=4;
bio(7).sigAddress='&multi_gadget_B.BehaviorMG_o6[0]';

bio(8).blkName='Behavior MG/p7';
bio(8).sigName='';
bio(8).portIdx=6;
bio(8).dim=[2,1];
bio(8).sigWidth=2;
bio(8).sigAddress='&multi_gadget_B.BehaviorMG_o7[0]';

bio(9).blkName='Behavior MG/p8';
bio(9).sigName='';
bio(9).portIdx=7;
bio(9).dim=[10,1];
bio(9).sigWidth=10;
bio(9).sigAddress='&multi_gadget_B.BehaviorMG_o8[0]';

bio(10).blkName='Behavior MG/p9';
bio(10).sigName='';
bio(10).portIdx=8;
bio(10).dim=[4,1];
bio(10).sigWidth=4;
bio(10).sigAddress='&multi_gadget_B.BehaviorMG_o9[0]';

bio(11).blkName='Behavior MG/p10';
bio(11).sigName='';
bio(11).portIdx=9;
bio(11).dim=[4,1];
bio(11).sigWidth=4;
bio(11).sigAddress='&multi_gadget_B.BehaviorMG_o10[0]';

bio(12).blkName='PCI-6025E DI';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&multi_gadget_B.PCI6025EDI';

bio(13).blkName='TargetTable';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[5,16];
bio(13).sigWidth=80;
bio(13).sigAddress='&multi_gadget_B.TargetTable[0]';

bio(14).blkName='CursorPos/NewtonCal1';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&multi_gadget_B.NewtonCal1';

bio(15).blkName='CursorPos/NewtonCal2';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[1,1];
bio(15).sigWidth=1;
bio(15).sigAddress='&multi_gadget_B.NewtonCal2';

bio(16).blkName='CursorPos/PCI-6025E AD/p1';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&multi_gadget_B.PCI6025EAD_o1';

bio(17).blkName='CursorPos/PCI-6025E AD/p2';
bio(17).sigName='';
bio(17).portIdx=1;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&multi_gadget_B.PCI6025EAD_o2';

bio(18).blkName='CursorPos/Add';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&multi_gadget_B.Add';

bio(19).blkName='CursorPos/Add1';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&multi_gadget_B.Add1';

bio(20).blkName='DeviceOutput/ToBits/p1';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&multi_gadget_B.ToBits_o1';

bio(21).blkName='DeviceOutput/ToBits/p2';
bio(21).sigName='';
bio(21).portIdx=1;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&multi_gadget_B.ToBits_o2';

bio(22).blkName='DeviceOutput/ToBits/p3';
bio(22).sigName='';
bio(22).portIdx=2;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&multi_gadget_B.ToBits_o3';

bio(23).blkName='DeviceOutput/ToBits/p4';
bio(23).sigName='';
bio(23).portIdx=3;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&multi_gadget_B.ToBits_o4';

bio(24).blkName='DeviceOutput/ToBits/p5';
bio(24).sigName='';
bio(24).portIdx=4;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&multi_gadget_B.ToBits_o5';

bio(25).blkName='DeviceOutput/ToBits/p6';
bio(25).sigName='';
bio(25).portIdx=5;
bio(25).dim=[1,1];
bio(25).sigWidth=1;
bio(25).sigAddress='&multi_gadget_B.ToBits_o6';

bio(26).blkName='DeviceOutput/ToBits/p7';
bio(26).sigName='';
bio(26).portIdx=6;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&multi_gadget_B.ToBits_o7';

bio(27).blkName='DeviceOutput/ToBits/p8';
bio(27).sigName='';
bio(27).portIdx=7;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&multi_gadget_B.ToBits_o8';

bio(28).blkName='RewardSbs/Data Type Conversion';
bio(28).sigName='';
bio(28).portIdx=0;
bio(28).dim=[1,1];
bio(28).sigWidth=1;
bio(28).sigAddress='&multi_gadget_B.DataTypeConversion';

bio(29).blkName='RewardSbs/Relational Operator';
bio(29).sigName='';
bio(29).portIdx=0;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&multi_gadget_B.RelationalOperator';

bio(30).blkName='RewardSbs/Switch';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&multi_gadget_B.Switch';

bio(31).blkName='RewardSbs/Uniform Random Number';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&multi_gadget_B.UniformRandomNumber';

bio(32).blkName='UDPXmit/Rate Transition';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[112,1];
bio(32).sigWidth=112;
bio(32).sigAddress='&multi_gadget_B.RateTransition[0]';

bio(33).blkName='UDPXmit/Pack';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[112,1];
bio(33).sigWidth=112;
bio(33).sigAddress='&multi_gadget_B.Pack[0]';

bio(34).blkName='WordSbs/For Iterator';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&multi_gadget_B.ForIterator';

bio(35).blkName='WordSbs/toThousandths';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[2,1];
bio(35).sigWidth=2;
bio(35).sigAddress='&multi_gadget_B.toThousandths[0]';

bio(36).blkName='WordSbs/SerialConverter';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[1,1];
bio(36).sigWidth=1;
bio(36).sigAddress='&multi_gadget_B.SerialConverter';

bio(37).blkName='WordSbs/ToBits/p1';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[1,1];
bio(37).sigWidth=1;
bio(37).sigAddress='&multi_gadget_B.ToBits_o1_f';

bio(38).blkName='WordSbs/ToBits/p2';
bio(38).sigName='';
bio(38).portIdx=1;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&multi_gadget_B.ToBits_o2_n';

bio(39).blkName='WordSbs/ToBits/p3';
bio(39).sigName='';
bio(39).portIdx=2;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&multi_gadget_B.ToBits_o3_i';

bio(40).blkName='WordSbs/ToBits/p4';
bio(40).sigName='';
bio(40).portIdx=3;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&multi_gadget_B.ToBits_o4_o';

bio(41).blkName='WordSbs/ToBits/p5';
bio(41).sigName='';
bio(41).portIdx=4;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&multi_gadget_B.ToBits_o5_n';

bio(42).blkName='WordSbs/ToBits/p6';
bio(42).sigName='';
bio(42).portIdx=5;
bio(42).dim=[1,1];
bio(42).sigWidth=1;
bio(42).sigAddress='&multi_gadget_B.ToBits_o6_a';

bio(43).blkName='WordSbs/ToBits/p7';
bio(43).sigName='';
bio(43).portIdx=6;
bio(43).dim=[1,1];
bio(43).sigWidth=1;
bio(43).sigAddress='&multi_gadget_B.ToBits_o7_j';

bio(44).blkName='WordSbs/ToBits/p8';
bio(44).sigName='';
bio(44).portIdx=7;
bio(44).dim=[1,1];
bio(44).sigWidth=1;
bio(44).sigAddress='&multi_gadget_B.ToBits_o8_f';

bio(45).blkName='WordSbs/ToBits1/p1';
bio(45).sigName='';
bio(45).portIdx=0;
bio(45).dim=[1,1];
bio(45).sigWidth=1;
bio(45).sigAddress='&multi_gadget_B.ToBits1_o1';

bio(46).blkName='WordSbs/ToBits1/p2';
bio(46).sigName='';
bio(46).portIdx=1;
bio(46).dim=[1,1];
bio(46).sigWidth=1;
bio(46).sigAddress='&multi_gadget_B.ToBits1_o2';

bio(47).blkName='WordSbs/ToBits1/p3';
bio(47).sigName='';
bio(47).portIdx=2;
bio(47).dim=[1,1];
bio(47).sigWidth=1;
bio(47).sigAddress='&multi_gadget_B.ToBits1_o3';

bio(48).blkName='WordSbs/ToBits1/p4';
bio(48).sigName='';
bio(48).portIdx=3;
bio(48).dim=[1,1];
bio(48).sigWidth=1;
bio(48).sigAddress='&multi_gadget_B.ToBits1_o4';

bio(49).blkName='WordSbs/ToBits1/p5';
bio(49).sigName='';
bio(49).portIdx=4;
bio(49).dim=[1,1];
bio(49).sigWidth=1;
bio(49).sigAddress='&multi_gadget_B.ToBits1_o5';

bio(50).blkName='WordSbs/ToBits1/p6';
bio(50).sigName='';
bio(50).portIdx=5;
bio(50).dim=[1,1];
bio(50).sigWidth=1;
bio(50).sigAddress='&multi_gadget_B.ToBits1_o6';

bio(51).blkName='WordSbs/ToBits1/p7';
bio(51).sigName='';
bio(51).portIdx=6;
bio(51).dim=[1,1];
bio(51).sigWidth=1;
bio(51).sigAddress='&multi_gadget_B.ToBits1_o7';

bio(52).blkName='WordSbs/ToBits1/p8';
bio(52).sigName='';
bio(52).portIdx=7;
bio(52).dim=[1,1];
bio(52).sigWidth=1;
bio(52).sigAddress='&multi_gadget_B.ToBits1_o8';

bio(53).blkName='WordSbs/xPC Target  Time ';
bio(53).sigName='';
bio(53).portIdx=0;
bio(53).dim=[1,1];
bio(53).sigWidth=1;
bio(53).sigAddress='&multi_gadget_B.xPCTargetTime';

bio(54).blkName='WordSbs/Add2';
bio(54).sigName='';
bio(54).portIdx=0;
bio(54).dim=[1,1];
bio(54).sigWidth=1;
bio(54).sigAddress='&multi_gadget_B.Add2';

bio(55).blkName='WordSbs/Add3';
bio(55).sigName='';
bio(55).portIdx=0;
bio(55).dim=[1,1];
bio(55).sigWidth=1;
bio(55).sigAddress='&multi_gadget_B.Add3';

bio(56).blkName='WordSbs/Switch';
bio(56).sigName='';
bio(56).portIdx=0;
bio(56).dim=[1,1];
bio(56).sigWidth=1;
bio(56).sigAddress='&multi_gadget_B.Switch_d';

bio(57).blkName='RewardSbs/Sample and Hold/In';
bio(57).sigName='';
bio(57).portIdx=0;
bio(57).dim=[1,1];
bio(57).sigWidth=1;
bio(57).sigAddress='&multi_gadget_B.SampleandHold_m.In';

bio(58).blkName='RewardSbs/Schmidt/Clock';
bio(58).sigName='';
bio(58).portIdx=0;
bio(58).dim=[1,1];
bio(58).sigWidth=1;
bio(58).sigAddress='&multi_gadget_B.Clock';

bio(59).blkName='RewardSbs/Schmidt/Relational Operator';
bio(59).sigName='';
bio(59).portIdx=0;
bio(59).dim=[1,1];
bio(59).sigWidth=1;
bio(59).sigAddress='&multi_gadget_B.RelationalOperator_c';

bio(60).blkName='RewardSbs/Schmidt/Sum';
bio(60).sigName='';
bio(60).portIdx=0;
bio(60).dim=[1,1];
bio(60).sigWidth=1;
bio(60).sigAddress='&multi_gadget_B.Sum';

bio(61).blkName='WordSbs/While Iterator Subsystem/ScaleTouSec';
bio(61).sigName='';
bio(61).portIdx=0;
bio(61).dim=[1,1];
bio(61).sigWidth=1;
bio(61).sigAddress='&multi_gadget_B.ScaleTouSec';

bio(62).blkName='WordSbs/While Iterator Subsystem/xPC Target  Time ';
bio(62).sigName='';
bio(62).portIdx=0;
bio(62).dim=[1,1];
bio(62).sigWidth=1;
bio(62).sigAddress='&multi_gadget_B.xPCTargetTime_c';

bio(63).blkName='WordSbs/While Iterator Subsystem/Subtract';
bio(63).sigName='';
bio(63).portIdx=0;
bio(63).dim=[1,1];
bio(63).sigWidth=1;
bio(63).sigAddress='&multi_gadget_B.Subtract';

bio(64).blkName='WordSbs/While Iterator Subsystem/Switch';
bio(64).sigName='';
bio(64).portIdx=0;
bio(64).dim=[1,1];
bio(64).sigWidth=1;
bio(64).sigAddress='&multi_gadget_B.Switch_j';

bio(65).blkName='RewardSbs/Schmidt/Sample and Hold/In';
bio(65).sigName='';
bio(65).portIdx=0;
bio(65).dim=[1,1];
bio(65).sigWidth=1;
bio(65).sigAddress='&multi_gadget_B.SampleandHold.In';

bio(66).blkName='WordSbs/While Iterator Subsystem/Compare To Constant/Compare';
bio(66).sigName='';
bio(66).portIdx=0;
bio(66).dim=[1,1];
bio(66).sigWidth=1;
bio(66).sigAddress='&multi_gadget_B.Compare_c';

bio(67).blkName='WordSbs/While Iterator Subsystem/Compare To Constant1/Compare';
bio(67).sigName='';
bio(67).portIdx=0;
bio(67).dim=[1,1];
bio(67).sigWidth=1;
bio(67).sigAddress='&multi_gadget_B.Compare';

function len = getlenBIO
len = 67;

