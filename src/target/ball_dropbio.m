function bio=ball_dropbio
bio = [];
bio(1).blkName='Behavior BD/p1';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&ball_drop_B.BehaviorBD_o1';
bio(getlenBIO) = bio(1);

bio(2).blkName='Behavior BD/p2';
bio(2).sigName='';
bio(2).portIdx=1;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&ball_drop_B.BehaviorBD_o2';

bio(3).blkName='Behavior BD/p3';
bio(3).sigName='';
bio(3).portIdx=2;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&ball_drop_B.BehaviorBD_o3';

bio(4).blkName='Behavior BD/p4';
bio(4).sigName='';
bio(4).portIdx=3;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&ball_drop_B.BehaviorBD_o4';

bio(5).blkName='Behavior BD/p5';
bio(5).sigName='';
bio(5).portIdx=4;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&ball_drop_B.BehaviorBD_o5';

bio(6).blkName='Behavior BD/p6';
bio(6).sigName='';
bio(6).portIdx=5;
bio(6).dim=[5,1];
bio(6).sigWidth=5;
bio(6).sigAddress='&ball_drop_B.BehaviorBD_o6[0]';

bio(7).blkName='Behavior BD/p7';
bio(7).sigName='';
bio(7).portIdx=6;
bio(7).dim=[2,1];
bio(7).sigWidth=2;
bio(7).sigAddress='&ball_drop_B.BehaviorBD_o7[0]';

bio(8).blkName='Behavior BD/p8';
bio(8).sigName='';
bio(8).portIdx=7;
bio(8).dim=[10,1];
bio(8).sigWidth=10;
bio(8).sigAddress='&ball_drop_B.BehaviorBD_o8[0]';

bio(9).blkName='Behavior BD/p9';
bio(9).sigName='';
bio(9).portIdx=8;
bio(9).dim=[4,1];
bio(9).sigWidth=4;
bio(9).sigAddress='&ball_drop_B.BehaviorBD_o9[0]';

bio(10).blkName='PCI-6025E DI';
bio(10).sigName='';
bio(10).portIdx=0;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&ball_drop_B.PCI6025EDI';

bio(11).blkName='Ball sensors/PCI-6025E AD/p1';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&ball_drop_B.PCI6025EAD_o1';

bio(12).blkName='Ball sensors/PCI-6025E AD/p2';
bio(12).sigName='';
bio(12).portIdx=1;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&ball_drop_B.PCI6025EAD_o2';

bio(13).blkName='Ball sensors/Switch';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[1,1];
bio(13).sigWidth=1;
bio(13).sigAddress='&ball_drop_B.Switch';

bio(14).blkName='Ball sensors/Switch1';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&ball_drop_B.Switch1';

bio(15).blkName='DeviceOutput/ToBits/p1';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[1,1];
bio(15).sigWidth=1;
bio(15).sigAddress='&ball_drop_B.ToBits_o1';

bio(16).blkName='DeviceOutput/ToBits/p2';
bio(16).sigName='';
bio(16).portIdx=1;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&ball_drop_B.ToBits_o2';

bio(17).blkName='DeviceOutput/ToBits/p3';
bio(17).sigName='';
bio(17).portIdx=2;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&ball_drop_B.ToBits_o3';

bio(18).blkName='DeviceOutput/ToBits/p4';
bio(18).sigName='';
bio(18).portIdx=3;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&ball_drop_B.ToBits_o4';

bio(19).blkName='DeviceOutput/ToBits/p5';
bio(19).sigName='';
bio(19).portIdx=4;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&ball_drop_B.ToBits_o5';

bio(20).blkName='DeviceOutput/ToBits/p6';
bio(20).sigName='';
bio(20).portIdx=5;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&ball_drop_B.ToBits_o6';

bio(21).blkName='DeviceOutput/ToBits/p7';
bio(21).sigName='';
bio(21).portIdx=6;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&ball_drop_B.ToBits_o7';

bio(22).blkName='DeviceOutput/ToBits/p8';
bio(22).sigName='';
bio(22).portIdx=7;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&ball_drop_B.ToBits_o8';

bio(23).blkName='RewardSbs/Data Type Conversion';
bio(23).sigName='';
bio(23).portIdx=0;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&ball_drop_B.DataTypeConversion';

bio(24).blkName='RewardSbs/Relational Operator';
bio(24).sigName='';
bio(24).portIdx=0;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&ball_drop_B.RelationalOperator';

bio(25).blkName='RewardSbs/Switch';
bio(25).sigName='';
bio(25).portIdx=0;
bio(25).dim=[1,1];
bio(25).sigWidth=1;
bio(25).sigAddress='&ball_drop_B.Switch_h';

bio(26).blkName='RewardSbs/Uniform Random Number';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&ball_drop_B.UniformRandomNumber';

bio(27).blkName='UDPXmit/Rate Transition';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[112,1];
bio(27).sigWidth=112;
bio(27).sigAddress='&ball_drop_B.RateTransition[0]';

bio(28).blkName='UDPXmit/Pack';
bio(28).sigName='';
bio(28).portIdx=0;
bio(28).dim=[112,1];
bio(28).sigWidth=112;
bio(28).sigAddress='&ball_drop_B.Pack[0]';

bio(29).blkName='WordSbs/ToBits/p1';
bio(29).sigName='';
bio(29).portIdx=0;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&ball_drop_B.ToBits_o1_i';

bio(30).blkName='WordSbs/ToBits/p2';
bio(30).sigName='';
bio(30).portIdx=1;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&ball_drop_B.ToBits_o2_h';

bio(31).blkName='WordSbs/ToBits/p3';
bio(31).sigName='';
bio(31).portIdx=2;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&ball_drop_B.ToBits_o3_d';

bio(32).blkName='WordSbs/ToBits/p4';
bio(32).sigName='';
bio(32).portIdx=3;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&ball_drop_B.ToBits_o4_j';

bio(33).blkName='WordSbs/ToBits/p5';
bio(33).sigName='';
bio(33).portIdx=4;
bio(33).dim=[1,1];
bio(33).sigWidth=1;
bio(33).sigAddress='&ball_drop_B.ToBits_o5_g';

bio(34).blkName='WordSbs/ToBits/p6';
bio(34).sigName='';
bio(34).portIdx=5;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&ball_drop_B.ToBits_o6_i';

bio(35).blkName='WordSbs/ToBits/p7';
bio(35).sigName='';
bio(35).portIdx=6;
bio(35).dim=[1,1];
bio(35).sigWidth=1;
bio(35).sigAddress='&ball_drop_B.ToBits_o7_p';

bio(36).blkName='WordSbs/ToBits/p8';
bio(36).sigName='';
bio(36).portIdx=7;
bio(36).dim=[1,1];
bio(36).sigWidth=1;
bio(36).sigAddress='&ball_drop_B.ToBits_o8_h';

bio(37).blkName='RewardSbs/Sample and Hold/In';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[1,1];
bio(37).sigWidth=1;
bio(37).sigAddress='&ball_drop_B.SampleandHold_i.In';

bio(38).blkName='RewardSbs/Schmidt/Clock';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&ball_drop_B.Clock';

bio(39).blkName='RewardSbs/Schmidt/Relational Operator';
bio(39).sigName='';
bio(39).portIdx=0;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&ball_drop_B.RelationalOperator_c';

bio(40).blkName='RewardSbs/Schmidt/Sum';
bio(40).sigName='';
bio(40).portIdx=0;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&ball_drop_B.Sum';

bio(41).blkName='RewardSbs/Schmidt/Sample and Hold/In';
bio(41).sigName='';
bio(41).portIdx=0;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&ball_drop_B.SampleandHold.In';

function len = getlenBIO
len = 41;

