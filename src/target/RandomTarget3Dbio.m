function bio=RandomTarget3Dbio
bio = [];
bio(1).blkName='Rate Transition';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&RandomTarget3D_B.RateTransition';
bio(1).ndims=2;
bio(1).size=[];

bio(getlenBIO) = bio(1);

bio(2).blkName='Behavior RandomTarget3D/p1';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[5,1];
bio(2).sigWidth=5;
bio(2).sigAddress='&RandomTarget3D_B.BehaviorRandomTarget3D_o1[0]';
bio(2).ndims=2;
bio(2).size=[];


bio(3).blkName='Behavior RandomTarget3D/p2';
bio(3).sigName='';
bio(3).portIdx=1;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&RandomTarget3D_B.BehaviorRandomTarget3D_o2';
bio(3).ndims=2;
bio(3).size=[];


bio(4).blkName='Behavior RandomTarget3D/p3';
bio(4).sigName='';
bio(4).portIdx=2;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&RandomTarget3D_B.BehaviorRandomTarget3D_o3';
bio(4).ndims=2;
bio(4).size=[];


bio(5).blkName='Behavior RandomTarget3D/p4';
bio(5).sigName='';
bio(5).portIdx=3;
bio(5).dim=[2,1];
bio(5).sigWidth=2;
bio(5).sigAddress='&RandomTarget3D_B.BehaviorRandomTarget3D_o4[0]';
bio(5).ndims=2;
bio(5).size=[];


bio(6).blkName='Behavior RandomTarget3D/p5';
bio(6).sigName='';
bio(6).portIdx=4;
bio(6).dim=[4,1];
bio(6).sigWidth=4;
bio(6).sigAddress='&RandomTarget3D_B.BehaviorRandomTarget3D_o5[0]';
bio(6).ndims=2;
bio(6).size=[];


bio(7).blkName='Behavior RandomTarget3D/p6';
bio(7).sigName='';
bio(7).portIdx=5;
bio(7).dim=[3,1];
bio(7).sigWidth=3;
bio(7).sigAddress='&RandomTarget3D_B.BehaviorRandomTarget3D_o6[0]';
bio(7).ndims=2;
bio(7).size=[];


bio(8).blkName='Behavior RandomTarget3D/p7';
bio(8).sigName='';
bio(8).portIdx=6;
bio(8).dim=[1,1];
bio(8).sigWidth=1;
bio(8).sigAddress='&RandomTarget3D_B.BehaviorRandomTarget3D_o7';
bio(8).ndims=2;
bio(8).size=[];


bio(9).blkName='PCI-6025E AD';
bio(9).sigName='';
bio(9).portIdx=0;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&RandomTarget3D_B.PCI6025EAD';
bio(9).ndims=2;
bio(9).size=[];


bio(10).blkName='RewardSbs/Data Type Conversion';
bio(10).sigName='';
bio(10).portIdx=0;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&RandomTarget3D_B.DataTypeConversion';
bio(10).ndims=2;
bio(10).size=[];


bio(11).blkName='RewardSbs/Relational Operator';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&RandomTarget3D_B.RelationalOperator';
bio(11).ndims=2;
bio(11).size=[];


bio(12).blkName='RewardSbs/Switch';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&RandomTarget3D_B.Switch';
bio(12).ndims=2;
bio(12).size=[];


bio(13).blkName='RewardSbs/Uniform Random Number';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[1,1];
bio(13).sigWidth=1;
bio(13).sigAddress='&RandomTarget3D_B.UniformRandomNumber';
bio(13).ndims=2;
bio(13).size=[];


bio(14).blkName='UDPXmit/Rate Transition';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[112,1];
bio(14).sigWidth=112;
bio(14).sigAddress='&RandomTarget3D_B.RateTransition_j[0]';
bio(14).ndims=2;
bio(14).size=[];


bio(15).blkName='UDPXmit/Pack';
bio(15).sigName='';
bio(15).portIdx=0;
bio(15).dim=[112,1];
bio(15).sigWidth=112;
bio(15).sigAddress='&RandomTarget3D_B.Pack[0]';
bio(15).ndims=2;
bio(15).size=[];


bio(16).blkName='Words to Cerebus and /For Iterator';
bio(16).sigName='';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&RandomTarget3D_B.ForIterator';
bio(16).ndims=2;
bio(16).size=[];


bio(17).blkName='Words to Cerebus and /ToBits1/p1';
bio(17).sigName='';
bio(17).portIdx=0;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&RandomTarget3D_B.ToBits1_o1';
bio(17).ndims=2;
bio(17).size=[];


bio(18).blkName='Words to Cerebus and /ToBits1/p2';
bio(18).sigName='';
bio(18).portIdx=1;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&RandomTarget3D_B.ToBits1_o2';
bio(18).ndims=2;
bio(18).size=[];


bio(19).blkName='Words to Cerebus and /ToBits1/p3';
bio(19).sigName='';
bio(19).portIdx=2;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&RandomTarget3D_B.ToBits1_o3';
bio(19).ndims=2;
bio(19).size=[];


bio(20).blkName='Words to Cerebus and /ToBits1/p4';
bio(20).sigName='';
bio(20).portIdx=3;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&RandomTarget3D_B.ToBits1_o4';
bio(20).ndims=2;
bio(20).size=[];


bio(21).blkName='Words to Cerebus and /ToBits1/p5';
bio(21).sigName='';
bio(21).portIdx=4;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&RandomTarget3D_B.ToBits1_o5';
bio(21).ndims=2;
bio(21).size=[];


bio(22).blkName='Words to Cerebus and /ToBits1/p6';
bio(22).sigName='';
bio(22).portIdx=5;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&RandomTarget3D_B.ToBits1_o6';
bio(22).ndims=2;
bio(22).size=[];


bio(23).blkName='Words to Cerebus and /ToBits1/p7';
bio(23).sigName='';
bio(23).portIdx=6;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&RandomTarget3D_B.ToBits1_o7';
bio(23).ndims=2;
bio(23).size=[];


bio(24).blkName='Words to Cerebus and /ToBits1/p8';
bio(24).sigName='';
bio(24).portIdx=7;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&RandomTarget3D_B.ToBits1_o8';
bio(24).ndims=2;
bio(24).size=[];


bio(25).blkName='Words to Cerebus and /xPC Target  Time ';
bio(25).sigName='';
bio(25).portIdx=0;
bio(25).dim=[1,1];
bio(25).sigWidth=1;
bio(25).sigAddress='&RandomTarget3D_B.xPCTargetTime';
bio(25).ndims=2;
bio(25).size=[];


bio(26).blkName='Words to Cerebus and /Switch';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&RandomTarget3D_B.Switch_l';
bio(26).ndims=2;
bio(26).size=[];


bio(27).blkName='RewardSbs/Sample and Hold/In';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&RandomTarget3D_B.SampleandHold_j.In';
bio(27).ndims=2;
bio(27).size=[];


bio(28).blkName='RewardSbs/Schmidt/Clock';
bio(28).sigName='';
bio(28).portIdx=0;
bio(28).dim=[1,1];
bio(28).sigWidth=1;
bio(28).sigAddress='&RandomTarget3D_B.Clock';
bio(28).ndims=2;
bio(28).size=[];


bio(29).blkName='RewardSbs/Schmidt/Relational Operator';
bio(29).sigName='';
bio(29).portIdx=0;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&RandomTarget3D_B.RelationalOperator_f';
bio(29).ndims=2;
bio(29).size=[];


bio(30).blkName='RewardSbs/Schmidt/Sum';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&RandomTarget3D_B.Sum';
bio(30).ndims=2;
bio(30).size=[];


bio(31).blkName='Words to Cerebus and /Whiltor Subsystem/ScaleTouSec';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&RandomTarget3D_B.ScaleTouSec';
bio(31).ndims=2;
bio(31).size=[];


bio(32).blkName='Words to Cerebus and /Whiltor Subsystem/xPC Target  Time ';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&RandomTarget3D_B.xPCTargetTime_d';
bio(32).ndims=2;
bio(32).size=[];


bio(33).blkName='Words to Cerebus and /Whiltor Subsystem/Subtract';
bio(33).sigName='';
bio(33).portIdx=0;
bio(33).dim=[1,1];
bio(33).sigWidth=1;
bio(33).sigAddress='&RandomTarget3D_B.Subtract';
bio(33).ndims=2;
bio(33).size=[];


bio(34).blkName='Words to Cerebus and /Whiltor Subsystem/Switch';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&RandomTarget3D_B.Switch_p';
bio(34).ndims=2;
bio(34).size=[];


bio(35).blkName='RewardSbs/Schmidt/Sample and Hold/In';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[1,1];
bio(35).sigWidth=1;
bio(35).sigAddress='&RandomTarget3D_B.SampleandHold.In';
bio(35).ndims=2;
bio(35).size=[];


bio(36).blkName='Words to Cerebus and /Whiltor Subsystem/Compare To Constant/Compare';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[1,1];
bio(36).sigWidth=1;
bio(36).sigAddress='&RandomTarget3D_B.Compare_c';
bio(36).ndims=2;
bio(36).size=[];


bio(37).blkName='Words to Cerebus and /Whiltor Subsystem/Compare To Constant1/Compare';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[1,1];
bio(37).sigWidth=1;
bio(37).sigAddress='&RandomTarget3D_B.Compare';
bio(37).ndims=2;
bio(37).size=[];


function len = getlenBIO
len = 37;

