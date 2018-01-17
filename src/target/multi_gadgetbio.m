function bio=multi_gadgetbio
bio = [];
bio(1).blkName='Reshape';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[80,1];
bio(1).sigWidth=80;
bio(1).sigAddress='&multi_gadget_B.Reshape[0]';
bio(1).ndims=2;
bio(1).size=[];

bio(getlenBIO) = bio(1);

bio(2).blkName='Behavior MG/p1';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&multi_gadget_B.BehaviorMG_o1';
bio(2).ndims=2;
bio(2).size=[];


bio(3).blkName='Behavior MG/p2';
bio(3).sigName='';
bio(3).portIdx=1;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&multi_gadget_B.BehaviorMG_o2';
bio(3).ndims=2;
bio(3).size=[];


bio(4).blkName='Behavior MG/p3';
bio(4).sigName='';
bio(4).portIdx=2;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&multi_gadget_B.BehaviorMG_o3';
bio(4).ndims=2;
bio(4).size=[];


bio(5).blkName='Behavior MG/p4';
bio(5).sigName='';
bio(5).portIdx=3;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&multi_gadget_B.BehaviorMG_o4';
bio(5).ndims=2;
bio(5).size=[];


bio(6).blkName='Behavior MG/p5';
bio(6).sigName='';
bio(6).portIdx=4;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&multi_gadget_B.BehaviorMG_o5';
bio(6).ndims=2;
bio(6).size=[];


bio(7).blkName='Behavior MG/p6';
bio(7).sigName='';
bio(7).portIdx=5;
bio(7).dim=[4,1];
bio(7).sigWidth=4;
bio(7).sigAddress='&multi_gadget_B.BehaviorMG_o6[0]';
bio(7).ndims=2;
bio(7).size=[];


bio(8).blkName='Behavior MG/p7';
bio(8).sigName='';
bio(8).portIdx=6;
bio(8).dim=[2,1];
bio(8).sigWidth=2;
bio(8).sigAddress='&multi_gadget_B.BehaviorMG_o7[0]';
bio(8).ndims=2;
bio(8).size=[];


bio(9).blkName='Behavior MG/p8';
bio(9).sigName='';
bio(9).portIdx=7;
bio(9).dim=[10,1];
bio(9).sigWidth=10;
bio(9).sigAddress='&multi_gadget_B.BehaviorMG_o8[0]';
bio(9).ndims=2;
bio(9).size=[];


bio(10).blkName='Behavior MG/p9';
bio(10).sigName='';
bio(10).portIdx=8;
bio(10).dim=[4,1];
bio(10).sigWidth=4;
bio(10).sigAddress='&multi_gadget_B.BehaviorMG_o9[0]';
bio(10).ndims=2;
bio(10).size=[];


bio(11).blkName='Behavior MG/p10';
bio(11).sigName='';
bio(11).portIdx=9;
bio(11).dim=[4,1];
bio(11).sigWidth=4;
bio(11).sigAddress='&multi_gadget_B.BehaviorMG_o10[0]';
bio(11).ndims=2;
bio(11).size=[];


bio(12).blkName='PCI-6025E DI';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&multi_gadget_B.PCI6025EDI';
bio(12).ndims=2;
bio(12).size=[];


bio(13).blkName='TargetTable';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[5,16];
bio(13).sigWidth=80;
bio(13).sigAddress='&multi_gadget_B.TargetTable[0]';
bio(13).ndims=2;
bio(13).size=[];


bio(14).blkName='CursorPos/Memory';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&multi_gadget_B.Memory';
bio(14).ndims=2;
bio(14).size=[];


bio(15).blkName='CursorPos/Gain1';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[1,1];
bio(15).sigWidth=1;
bio(15).sigAddress='&multi_gadget_B.Gain1';
bio(15).ndims=2;
bio(15).size=[];


bio(16).blkName='CursorPos/Gain2';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&multi_gadget_B.Gain2';
bio(16).ndims=2;
bio(16).size=[];


bio(17).blkName='CursorPos/PCI-6025E AD/p1';
bio(17).sigName='';
bio(17).portIdx=0;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&multi_gadget_B.PCI6025EAD_o1';
bio(17).ndims=2;
bio(17).size=[];


bio(18).blkName='CursorPos/PCI-6025E AD/p2';
bio(18).sigName='';
bio(18).portIdx=1;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&multi_gadget_B.PCI6025EAD_o2';
bio(18).ndims=2;
bio(18).size=[];


bio(19).blkName='CursorPos/Add';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&multi_gadget_B.Add';
bio(19).ndims=2;
bio(19).size=[];


bio(20).blkName='CursorPos/Add1';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&multi_gadget_B.Add1';
bio(20).ndims=2;
bio(20).size=[];


bio(21).blkName='CursorPos/GadgetGain';
bio(21).sigName='';
bio(21).portIdx=0;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&multi_gadget_B.GadgetGain';
bio(21).ndims=2;
bio(21).size=[];


bio(22).blkName='DeviceOutput/ToBits/p1';
bio(22).sigName='';
bio(22).portIdx=0;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&multi_gadget_B.ToBits_o1';
bio(22).ndims=2;
bio(22).size=[];


bio(23).blkName='DeviceOutput/ToBits/p2';
bio(23).sigName='';
bio(23).portIdx=1;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&multi_gadget_B.ToBits_o2';
bio(23).ndims=2;
bio(23).size=[];


bio(24).blkName='DeviceOutput/ToBits/p3';
bio(24).sigName='';
bio(24).portIdx=2;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&multi_gadget_B.ToBits_o3';
bio(24).ndims=2;
bio(24).size=[];


bio(25).blkName='DeviceOutput/ToBits/p4';
bio(25).sigName='';
bio(25).portIdx=3;
bio(25).dim=[1,1];
bio(25).sigWidth=1;
bio(25).sigAddress='&multi_gadget_B.ToBits_o4';
bio(25).ndims=2;
bio(25).size=[];


bio(26).blkName='DeviceOutput/ToBits/p5';
bio(26).sigName='';
bio(26).portIdx=4;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&multi_gadget_B.ToBits_o5';
bio(26).ndims=2;
bio(26).size=[];


bio(27).blkName='DeviceOutput/ToBits/p6';
bio(27).sigName='';
bio(27).portIdx=5;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&multi_gadget_B.ToBits_o6';
bio(27).ndims=2;
bio(27).size=[];


bio(28).blkName='DeviceOutput/ToBits/p7';
bio(28).sigName='';
bio(28).portIdx=6;
bio(28).dim=[1,1];
bio(28).sigWidth=1;
bio(28).sigAddress='&multi_gadget_B.ToBits_o7';
bio(28).ndims=2;
bio(28).size=[];


bio(29).blkName='DeviceOutput/ToBits/p8';
bio(29).sigName='';
bio(29).portIdx=7;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&multi_gadget_B.ToBits_o8';
bio(29).ndims=2;
bio(29).size=[];


bio(30).blkName='RewardSbs/Data Type Conversion';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&multi_gadget_B.DataTypeConversion';
bio(30).ndims=2;
bio(30).size=[];


bio(31).blkName='RewardSbs/Relational Operator';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&multi_gadget_B.RelationalOperator';
bio(31).ndims=2;
bio(31).size=[];


bio(32).blkName='RewardSbs/Switch';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&multi_gadget_B.Switch';
bio(32).ndims=2;
bio(32).size=[];


bio(33).blkName='RewardSbs/Uniform Random Number';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[1,1];
bio(33).sigWidth=1;
bio(33).sigAddress='&multi_gadget_B.UniformRandomNumber';
bio(33).ndims=2;
bio(33).size=[];


bio(34).blkName='UDPXmit/Rate Transition';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[112,1];
bio(34).sigWidth=112;
bio(34).sigAddress='&multi_gadget_B.RateTransition[0]';
bio(34).ndims=2;
bio(34).size=[];


bio(35).blkName='UDPXmit/Pack';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[112,1];
bio(35).sigWidth=112;
bio(35).sigAddress='&multi_gadget_B.Pack[0]';
bio(35).ndims=2;
bio(35).size=[];


bio(36).blkName='WordSbs/For Iterator';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[1,1];
bio(36).sigWidth=1;
bio(36).sigAddress='&multi_gadget_B.ForIterator';
bio(36).ndims=2;
bio(36).size=[];


bio(37).blkName='WordSbs/toThousandths';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[2,1];
bio(37).sigWidth=2;
bio(37).sigAddress='&multi_gadget_B.toThousandths[0]';
bio(37).ndims=2;
bio(37).size=[];


bio(38).blkName='WordSbs/SerialConverter';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&multi_gadget_B.SerialConverter';
bio(38).ndims=2;
bio(38).size=[];


bio(39).blkName='WordSbs/ToBits/p1';
bio(39).sigName='';
bio(39).portIdx=0;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&multi_gadget_B.ToBits_o1_n';
bio(39).ndims=2;
bio(39).size=[];


bio(40).blkName='WordSbs/ToBits/p2';
bio(40).sigName='';
bio(40).portIdx=1;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&multi_gadget_B.ToBits_o2_g';
bio(40).ndims=2;
bio(40).size=[];


bio(41).blkName='WordSbs/ToBits/p3';
bio(41).sigName='';
bio(41).portIdx=2;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&multi_gadget_B.ToBits_o3_n';
bio(41).ndims=2;
bio(41).size=[];


bio(42).blkName='WordSbs/ToBits/p4';
bio(42).sigName='';
bio(42).portIdx=3;
bio(42).dim=[1,1];
bio(42).sigWidth=1;
bio(42).sigAddress='&multi_gadget_B.ToBits_o4_m';
bio(42).ndims=2;
bio(42).size=[];


bio(43).blkName='WordSbs/ToBits/p5';
bio(43).sigName='';
bio(43).portIdx=4;
bio(43).dim=[1,1];
bio(43).sigWidth=1;
bio(43).sigAddress='&multi_gadget_B.ToBits_o5_i';
bio(43).ndims=2;
bio(43).size=[];


bio(44).blkName='WordSbs/ToBits/p6';
bio(44).sigName='';
bio(44).portIdx=5;
bio(44).dim=[1,1];
bio(44).sigWidth=1;
bio(44).sigAddress='&multi_gadget_B.ToBits_o6_d';
bio(44).ndims=2;
bio(44).size=[];


bio(45).blkName='WordSbs/ToBits/p7';
bio(45).sigName='';
bio(45).portIdx=6;
bio(45).dim=[1,1];
bio(45).sigWidth=1;
bio(45).sigAddress='&multi_gadget_B.ToBits_o7_c';
bio(45).ndims=2;
bio(45).size=[];


bio(46).blkName='WordSbs/ToBits/p8';
bio(46).sigName='';
bio(46).portIdx=7;
bio(46).dim=[1,1];
bio(46).sigWidth=1;
bio(46).sigAddress='&multi_gadget_B.ToBits_o8_f';
bio(46).ndims=2;
bio(46).size=[];


bio(47).blkName='WordSbs/ToBits1/p1';
bio(47).sigName='';
bio(47).portIdx=0;
bio(47).dim=[1,1];
bio(47).sigWidth=1;
bio(47).sigAddress='&multi_gadget_B.ToBits1_o1';
bio(47).ndims=2;
bio(47).size=[];


bio(48).blkName='WordSbs/ToBits1/p2';
bio(48).sigName='';
bio(48).portIdx=1;
bio(48).dim=[1,1];
bio(48).sigWidth=1;
bio(48).sigAddress='&multi_gadget_B.ToBits1_o2';
bio(48).ndims=2;
bio(48).size=[];


bio(49).blkName='WordSbs/ToBits1/p3';
bio(49).sigName='';
bio(49).portIdx=2;
bio(49).dim=[1,1];
bio(49).sigWidth=1;
bio(49).sigAddress='&multi_gadget_B.ToBits1_o3';
bio(49).ndims=2;
bio(49).size=[];


bio(50).blkName='WordSbs/ToBits1/p4';
bio(50).sigName='';
bio(50).portIdx=3;
bio(50).dim=[1,1];
bio(50).sigWidth=1;
bio(50).sigAddress='&multi_gadget_B.ToBits1_o4';
bio(50).ndims=2;
bio(50).size=[];


bio(51).blkName='WordSbs/ToBits1/p5';
bio(51).sigName='';
bio(51).portIdx=4;
bio(51).dim=[1,1];
bio(51).sigWidth=1;
bio(51).sigAddress='&multi_gadget_B.ToBits1_o5';
bio(51).ndims=2;
bio(51).size=[];


bio(52).blkName='WordSbs/ToBits1/p6';
bio(52).sigName='';
bio(52).portIdx=5;
bio(52).dim=[1,1];
bio(52).sigWidth=1;
bio(52).sigAddress='&multi_gadget_B.ToBits1_o6';
bio(52).ndims=2;
bio(52).size=[];


bio(53).blkName='WordSbs/ToBits1/p7';
bio(53).sigName='';
bio(53).portIdx=6;
bio(53).dim=[1,1];
bio(53).sigWidth=1;
bio(53).sigAddress='&multi_gadget_B.ToBits1_o7';
bio(53).ndims=2;
bio(53).size=[];


bio(54).blkName='WordSbs/ToBits1/p8';
bio(54).sigName='';
bio(54).portIdx=7;
bio(54).dim=[1,1];
bio(54).sigWidth=1;
bio(54).sigAddress='&multi_gadget_B.ToBits1_o8';
bio(54).ndims=2;
bio(54).size=[];


bio(55).blkName='WordSbs/xPC Target  Time ';
bio(55).sigName='';
bio(55).portIdx=0;
bio(55).dim=[1,1];
bio(55).sigWidth=1;
bio(55).sigAddress='&multi_gadget_B.xPCTargetTime';
bio(55).ndims=2;
bio(55).size=[];


bio(56).blkName='WordSbs/Add2';
bio(56).sigName='';
bio(56).portIdx=0;
bio(56).dim=[1,1];
bio(56).sigWidth=1;
bio(56).sigAddress='&multi_gadget_B.Add2';
bio(56).ndims=2;
bio(56).size=[];


bio(57).blkName='WordSbs/Add3';
bio(57).sigName='';
bio(57).portIdx=0;
bio(57).dim=[1,1];
bio(57).sigWidth=1;
bio(57).sigAddress='&multi_gadget_B.Add3';
bio(57).ndims=2;
bio(57).size=[];


bio(58).blkName='WordSbs/Switch';
bio(58).sigName='';
bio(58).portIdx=0;
bio(58).dim=[1,1];
bio(58).sigWidth=1;
bio(58).sigAddress='&multi_gadget_B.Switch_n';
bio(58).ndims=2;
bio(58).size=[];


bio(59).blkName='RewardSbs/Sample and Hold/In';
bio(59).sigName='';
bio(59).portIdx=0;
bio(59).dim=[1,1];
bio(59).sigWidth=1;
bio(59).sigAddress='&multi_gadget_B.SampleandHold_f.In';
bio(59).ndims=2;
bio(59).size=[];


bio(60).blkName='RewardSbs/Schmidt/Clock';
bio(60).sigName='';
bio(60).portIdx=0;
bio(60).dim=[1,1];
bio(60).sigWidth=1;
bio(60).sigAddress='&multi_gadget_B.Clock';
bio(60).ndims=2;
bio(60).size=[];


bio(61).blkName='RewardSbs/Schmidt/Relational Operator';
bio(61).sigName='';
bio(61).portIdx=0;
bio(61).dim=[1,1];
bio(61).sigWidth=1;
bio(61).sigAddress='&multi_gadget_B.RelationalOperator_i';
bio(61).ndims=2;
bio(61).size=[];


bio(62).blkName='RewardSbs/Schmidt/Sum';
bio(62).sigName='';
bio(62).portIdx=0;
bio(62).dim=[1,1];
bio(62).sigWidth=1;
bio(62).sigAddress='&multi_gadget_B.Sum';
bio(62).ndims=2;
bio(62).size=[];


bio(63).blkName='WordSbs/While Iterator Subsystem/ScaleTouSec';
bio(63).sigName='';
bio(63).portIdx=0;
bio(63).dim=[1,1];
bio(63).sigWidth=1;
bio(63).sigAddress='&multi_gadget_B.ScaleTouSec';
bio(63).ndims=2;
bio(63).size=[];


bio(64).blkName='WordSbs/While Iterator Subsystem/xPC Target  Time ';
bio(64).sigName='';
bio(64).portIdx=0;
bio(64).dim=[1,1];
bio(64).sigWidth=1;
bio(64).sigAddress='&multi_gadget_B.xPCTargetTime_e';
bio(64).ndims=2;
bio(64).size=[];


bio(65).blkName='WordSbs/While Iterator Subsystem/Subtract';
bio(65).sigName='';
bio(65).portIdx=0;
bio(65).dim=[1,1];
bio(65).sigWidth=1;
bio(65).sigAddress='&multi_gadget_B.Subtract';
bio(65).ndims=2;
bio(65).size=[];


bio(66).blkName='WordSbs/While Iterator Subsystem/Switch';
bio(66).sigName='';
bio(66).portIdx=0;
bio(66).dim=[1,1];
bio(66).sigWidth=1;
bio(66).sigAddress='&multi_gadget_B.Switch_f';
bio(66).ndims=2;
bio(66).size=[];


bio(67).blkName='RewardSbs/Schmidt/Sample and Hold/In';
bio(67).sigName='';
bio(67).portIdx=0;
bio(67).dim=[1,1];
bio(67).sigWidth=1;
bio(67).sigAddress='&multi_gadget_B.SampleandHold.In';
bio(67).ndims=2;
bio(67).size=[];


bio(68).blkName='WordSbs/While Iterator Subsystem/Compare To Constant/Compare';
bio(68).sigName='';
bio(68).portIdx=0;
bio(68).dim=[1,1];
bio(68).sigWidth=1;
bio(68).sigAddress='&multi_gadget_B.Compare_l';
bio(68).ndims=2;
bio(68).size=[];


bio(69).blkName='WordSbs/While Iterator Subsystem/Compare To Constant1/Compare';
bio(69).sigName='';
bio(69).portIdx=0;
bio(69).dim=[1,1];
bio(69).sigWidth=1;
bio(69).sigAddress='&multi_gadget_B.Compare';
bio(69).ndims=2;
bio(69).size=[];


function len = getlenBIO
len = 69;

