function pt=wrist_flexionpt
pt = [];
pt(1).blockname = 'Rad2Deg';
pt(1).paramname = 'Gain';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(getlenPT) = pt(1);

pt(2).blockname = 'Memory';
pt(2).paramname = 'X0';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';

pt(3).blockname = 'Behavior WF';
pt(3).paramname = 'P1';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';

pt(4).blockname = 'Behavior WF';
pt(4).paramname = 'P2';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';

pt(5).blockname = 'Behavior WF';
pt(5).paramname = 'P3';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';

pt(6).blockname = 'Behavior WF';
pt(6).paramname = 'P4';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';

pt(7).blockname = 'Behavior WF';
pt(7).paramname = 'P5';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';

pt(8).blockname = 'Behavior WF';
pt(8).paramname = 'P6';
pt(8).class     = 'scalar';
pt(8).nrows     = 1;
pt(8).ncols     = 1;
pt(8).subsource = 'SS_DOUBLE';

pt(9).blockname = 'Behavior WF';
pt(9).paramname = 'P7';
pt(9).class     = 'scalar';
pt(9).nrows     = 1;
pt(9).ncols     = 1;
pt(9).subsource = 'SS_DOUBLE';

pt(10).blockname = 'Behavior WF';
pt(10).paramname = 'P8';
pt(10).class     = 'scalar';
pt(10).nrows     = 1;
pt(10).ncols     = 1;
pt(10).subsource = 'SS_DOUBLE';

pt(11).blockname = 'Behavior WF';
pt(11).paramname = 'P9';
pt(11).class     = 'scalar';
pt(11).nrows     = 1;
pt(11).ncols     = 1;
pt(11).subsource = 'SS_DOUBLE';

pt(12).blockname = 'Behavior WF';
pt(12).paramname = 'P10';
pt(12).class     = 'scalar';
pt(12).nrows     = 1;
pt(12).ncols     = 1;
pt(12).subsource = 'SS_DOUBLE';

pt(13).blockname = 'Behavior WF';
pt(13).paramname = 'P11';
pt(13).class     = 'scalar';
pt(13).nrows     = 1;
pt(13).ncols     = 1;
pt(13).subsource = 'SS_DOUBLE';

pt(14).blockname = 'Behavior WF';
pt(14).paramname = 'P12';
pt(14).class     = 'scalar';
pt(14).nrows     = 1;
pt(14).ncols     = 1;
pt(14).subsource = 'SS_DOUBLE';

pt(15).blockname = 'Behavior WF';
pt(15).paramname = 'P13';
pt(15).class     = 'scalar';
pt(15).nrows     = 1;
pt(15).ncols     = 1;
pt(15).subsource = 'SS_DOUBLE';

pt(16).blockname = 'Behavior WF';
pt(16).paramname = 'P14';
pt(16).class     = 'scalar';
pt(16).nrows     = 1;
pt(16).ncols     = 1;
pt(16).subsource = 'SS_DOUBLE';

pt(17).blockname = 'Behavior WF';
pt(17).paramname = 'P15';
pt(17).class     = 'scalar';
pt(17).nrows     = 1;
pt(17).ncols     = 1;
pt(17).subsource = 'SS_DOUBLE';

pt(18).blockname = 'Behavior WF';
pt(18).paramname = 'P16';
pt(18).class     = 'scalar';
pt(18).nrows     = 1;
pt(18).ncols     = 1;
pt(18).subsource = 'SS_DOUBLE';

pt(19).blockname = 'Behavior WF';
pt(19).paramname = 'P17';
pt(19).class     = 'scalar';
pt(19).nrows     = 1;
pt(19).ncols     = 1;
pt(19).subsource = 'SS_DOUBLE';

pt(20).blockname = 'Behavior WF';
pt(20).paramname = 'P18';
pt(20).class     = 'scalar';
pt(20).nrows     = 1;
pt(20).ncols     = 1;
pt(20).subsource = 'SS_DOUBLE';

pt(21).blockname = 'Behavior WF';
pt(21).paramname = 'P19';
pt(21).class     = 'scalar';
pt(21).nrows     = 1;
pt(21).ncols     = 1;
pt(21).subsource = 'SS_DOUBLE';

pt(22).blockname = 'Behavior WF';
pt(22).paramname = 'P20';
pt(22).class     = 'scalar';
pt(22).nrows     = 1;
pt(22).ncols     = 1;
pt(22).subsource = 'SS_DOUBLE';

pt(23).blockname = 'Behavior WF';
pt(23).paramname = 'P21';
pt(23).class     = 'scalar';
pt(23).nrows     = 1;
pt(23).ncols     = 1;
pt(23).subsource = 'SS_DOUBLE';

pt(24).blockname = 'WFTargetTable';
pt(24).paramname = 'table';
pt(24).class     = 'col-mat';
pt(24).nrows     = 6;
pt(24).ncols     = 16;
pt(24).subsource = 'SS_DOUBLE';

pt(25).blockname = 'CursorPos/EnableIntegrator';
pt(25).paramname = 'Value';
pt(25).class     = 'scalar';
pt(25).nrows     = 1;
pt(25).ncols     = 1;
pt(25).subsource = 'SS_DOUBLE';

pt(26).blockname = 'CursorPos/EnablePosFilter';
pt(26).paramname = 'Value';
pt(26).class     = 'scalar';
pt(26).nrows     = 1;
pt(26).ncols     = 1;
pt(26).subsource = 'SS_DOUBLE';

pt(27).blockname = 'CursorPos/NeuralControlPct';
pt(27).paramname = 'Value';
pt(27).class     = 'scalar';
pt(27).nrows     = 1;
pt(27).ncols     = 1;
pt(27).subsource = 'SS_DOUBLE';

pt(28).blockname = 'CursorPos/OffsetX';
pt(28).paramname = 'Value';
pt(28).class     = 'scalar';
pt(28).nrows     = 1;
pt(28).ncols     = 1;
pt(28).subsource = 'SS_DOUBLE';

pt(29).blockname = 'CursorPos/OffsetY';
pt(29).paramname = 'Value';
pt(29).class     = 'scalar';
pt(29).nrows     = 1;
pt(29).ncols     = 1;
pt(29).subsource = 'SS_DOUBLE';

pt(30).blockname = 'CursorPos/ResetIntegrator';
pt(30).paramname = 'Value';
pt(30).class     = 'scalar';
pt(30).nrows     = 1;
pt(30).ncols     = 1;
pt(30).subsource = 'SS_DOUBLE';

pt(31).blockname = 'CursorPos/GainX';
pt(31).paramname = 'Gain';
pt(31).class     = 'scalar';
pt(31).nrows     = 1;
pt(31).ncols     = 1;
pt(31).subsource = 'SS_DOUBLE';

pt(32).blockname = 'CursorPos/GainY';
pt(32).paramname = 'Gain';
pt(32).class     = 'scalar';
pt(32).nrows     = 1;
pt(32).ncols     = 1;
pt(32).subsource = 'SS_DOUBLE';

pt(33).blockname = 'CursorPos/Integrator';
pt(33).paramname = 'InitialCondition';
pt(33).class     = 'scalar';
pt(33).nrows     = 1;
pt(33).ncols     = 1;
pt(33).subsource = 'SS_DOUBLE';

pt(34).blockname = 'CursorPos/Integrator';
pt(34).paramname = 'UpperSaturationLimit';
pt(34).class     = 'scalar';
pt(34).nrows     = 1;
pt(34).ncols     = 1;
pt(34).subsource = 'SS_DOUBLE';

pt(35).blockname = 'CursorPos/Integrator';
pt(35).paramname = 'LowerSaturationLimit';
pt(35).class     = 'scalar';
pt(35).nrows     = 1;
pt(35).ncols     = 1;
pt(35).subsource = 'SS_DOUBLE';

pt(36).blockname = 'CursorPos/Saturation';
pt(36).paramname = 'UpperLimit';
pt(36).class     = 'scalar';
pt(36).nrows     = 1;
pt(36).ncols     = 1;
pt(36).subsource = 'SS_DOUBLE';

pt(37).blockname = 'CursorPos/Saturation';
pt(37).paramname = 'LowerLimit';
pt(37).class     = 'scalar';
pt(37).nrows     = 1;
pt(37).ncols     = 1;
pt(37).subsource = 'SS_DOUBLE';

pt(38).blockname = 'CursorPos/PCI-6025E ';
pt(38).paramname = 'P1';
pt(38).class     = 'vector';
pt(38).nrows     = 1;
pt(38).ncols     = 2;
pt(38).subsource = 'SS_DOUBLE';

pt(39).blockname = 'CursorPos/PCI-6025E ';
pt(39).paramname = 'P2';
pt(39).class     = 'vector';
pt(39).nrows     = 1;
pt(39).ncols     = 2;
pt(39).subsource = 'SS_DOUBLE';

pt(40).blockname = 'CursorPos/PCI-6025E ';
pt(40).paramname = 'P3';
pt(40).class     = 'vector';
pt(40).nrows     = 1;
pt(40).ncols     = 2;
pt(40).subsource = 'SS_DOUBLE';

pt(41).blockname = 'CursorPos/PCI-6025E ';
pt(41).paramname = 'P4';
pt(41).class     = 'scalar';
pt(41).nrows     = 1;
pt(41).ncols     = 1;
pt(41).subsource = 'SS_DOUBLE';

pt(42).blockname = 'CursorPos/PCI-6025E ';
pt(42).paramname = 'P5';
pt(42).class     = 'scalar';
pt(42).nrows     = 1;
pt(42).ncols     = 1;
pt(42).subsource = 'SS_DOUBLE';

pt(43).blockname = 'CursorPos/PCI-6025E ';
pt(43).paramname = 'P6';
pt(43).class     = 'scalar';
pt(43).nrows     = 1;
pt(43).ncols     = 1;
pt(43).subsource = 'SS_DOUBLE';

pt(44).blockname = 'CursorPos/Receive';
pt(44).paramname = 'P1';
pt(44).class     = 'vector';
pt(44).nrows     = 1;
pt(44).ncols     = 7;
pt(44).subsource = 'SS_DOUBLE';

pt(45).blockname = 'CursorPos/Receive';
pt(45).paramname = 'P2';
pt(45).class     = 'scalar';
pt(45).nrows     = 1;
pt(45).ncols     = 1;
pt(45).subsource = 'SS_DOUBLE';

pt(46).blockname = 'CursorPos/Receive';
pt(46).paramname = 'P3';
pt(46).class     = 'scalar';
pt(46).nrows     = 1;
pt(46).ncols     = 1;
pt(46).subsource = 'SS_DOUBLE';

pt(47).blockname = 'CursorPos/Receive';
pt(47).paramname = 'P4';
pt(47).class     = 'scalar';
pt(47).nrows     = 1;
pt(47).ncols     = 1;
pt(47).subsource = 'SS_DOUBLE';

pt(48).blockname = 'CursorPos/LowPassFilterX';
pt(48).paramname = 'A';
pt(48).class     = 'vector';
pt(48).nrows     = 15;
pt(48).ncols     = 1;
pt(48).subsource = 'SS_DOUBLE';

pt(49).blockname = 'CursorPos/LowPassFilterX';
pt(49).paramname = 'B';
pt(49).class     = 'scalar';
pt(49).nrows     = 1;
pt(49).ncols     = 1;
pt(49).subsource = 'SS_DOUBLE';

pt(50).blockname = 'CursorPos/LowPassFilterX';
pt(50).paramname = 'C';
pt(50).class     = 'scalar';
pt(50).nrows     = 1;
pt(50).ncols     = 1;
pt(50).subsource = 'SS_DOUBLE';

pt(51).blockname = 'CursorPos/LowPassFilterX';
pt(51).paramname = 'X0';
pt(51).class     = 'scalar';
pt(51).nrows     = 1;
pt(51).ncols     = 1;
pt(51).subsource = 'SS_DOUBLE';

pt(52).blockname = 'CursorPos/LowPassFilterY';
pt(52).paramname = 'A';
pt(52).class     = 'vector';
pt(52).nrows     = 15;
pt(52).ncols     = 1;
pt(52).subsource = 'SS_DOUBLE';

pt(53).blockname = 'CursorPos/LowPassFilterY';
pt(53).paramname = 'B';
pt(53).class     = 'scalar';
pt(53).nrows     = 1;
pt(53).ncols     = 1;
pt(53).subsource = 'SS_DOUBLE';

pt(54).blockname = 'CursorPos/LowPassFilterY';
pt(54).paramname = 'C';
pt(54).class     = 'scalar';
pt(54).nrows     = 1;
pt(54).ncols     = 1;
pt(54).subsource = 'SS_DOUBLE';

pt(55).blockname = 'CursorPos/LowPassFilterY';
pt(55).paramname = 'X0';
pt(55).class     = 'scalar';
pt(55).nrows     = 1;
pt(55).ncols     = 1;
pt(55).subsource = 'SS_DOUBLE';

pt(56).blockname = 'RewardSbs/JackpotChance';
pt(56).paramname = 'Value';
pt(56).class     = 'scalar';
pt(56).nrows     = 1;
pt(56).ncols     = 1;
pt(56).subsource = 'SS_DOUBLE';

pt(57).blockname = 'RewardSbs/RewardJackpot';
pt(57).paramname = 'Value';
pt(57).class     = 'scalar';
pt(57).nrows     = 1;
pt(57).ncols     = 1;
pt(57).subsource = 'SS_DOUBLE';

pt(58).blockname = 'RewardSbs/RewardTime';
pt(58).paramname = 'Value';
pt(58).class     = 'scalar';
pt(58).nrows     = 1;
pt(58).ncols     = 1;
pt(58).subsource = 'SS_DOUBLE';

pt(59).blockname = 'RewardSbs/Uniform Random Number';
pt(59).paramname = 'Minimum';
pt(59).class     = 'scalar';
pt(59).nrows     = 1;
pt(59).ncols     = 1;
pt(59).subsource = 'SS_DOUBLE';

pt(60).blockname = 'RewardSbs/Uniform Random Number';
pt(60).paramname = 'Maximum';
pt(60).class     = 'scalar';
pt(60).nrows     = 1;
pt(60).ncols     = 1;
pt(60).subsource = 'SS_DOUBLE';

pt(61).blockname = 'RewardSbs/Uniform Random Number';
pt(61).paramname = 'Seed';
pt(61).class     = 'scalar';
pt(61).nrows     = 1;
pt(61).ncols     = 1;
pt(61).subsource = 'SS_DOUBLE';

pt(62).blockname = 'UDPXmit/Send';
pt(62).paramname = 'P1';
pt(62).class     = 'vector';
pt(62).nrows     = 1;
pt(62).ncols     = 11;
pt(62).subsource = 'SS_DOUBLE';

pt(63).blockname = 'UDPXmit/Send';
pt(63).paramname = 'P2';
pt(63).class     = 'scalar';
pt(63).nrows     = 1;
pt(63).ncols     = 1;
pt(63).subsource = 'SS_DOUBLE';

pt(64).blockname = 'UDPXmit/Send';
pt(64).paramname = 'P3';
pt(64).class     = 'scalar';
pt(64).nrows     = 1;
pt(64).ncols     = 1;
pt(64).subsource = 'SS_DOUBLE';

pt(65).blockname = 'UDPXmit/Send';
pt(65).paramname = 'P4';
pt(65).class     = 'scalar';
pt(65).nrows     = 1;
pt(65).ncols     = 1;
pt(65).subsource = 'SS_DOUBLE';

pt(66).blockname = 'WordSbs/Constant';
pt(66).paramname = 'Value';
pt(66).class     = 'scalar';
pt(66).nrows     = 1;
pt(66).ncols     = 1;
pt(66).subsource = 'SS_DOUBLE';

pt(67).blockname = 'WordSbs/Constant2';
pt(67).paramname = 'Value';
pt(67).class     = 'scalar';
pt(67).nrows     = 1;
pt(67).ncols     = 1;
pt(67).subsource = 'SS_DOUBLE';

pt(68).blockname = 'WordSbs/toThousandths';
pt(68).paramname = 'Gain';
pt(68).class     = 'scalar';
pt(68).nrows     = 1;
pt(68).ncols     = 1;
pt(68).subsource = 'SS_DOUBLE';

pt(69).blockname = 'WordSbs/Port A';
pt(69).paramname = 'P1';
pt(69).class     = 'vector';
pt(69).nrows     = 1;
pt(69).ncols     = 8;
pt(69).subsource = 'SS_DOUBLE';

pt(70).blockname = 'WordSbs/Port A';
pt(70).paramname = 'P2';
pt(70).class     = 'scalar';
pt(70).nrows     = 1;
pt(70).ncols     = 1;
pt(70).subsource = 'SS_DOUBLE';

pt(71).blockname = 'WordSbs/Port A';
pt(71).paramname = 'P3';
pt(71).class     = 'vector';
pt(71).nrows     = 1;
pt(71).ncols     = 8;
pt(71).subsource = 'SS_DOUBLE';

pt(72).blockname = 'WordSbs/Port A';
pt(72).paramname = 'P4';
pt(72).class     = 'vector';
pt(72).nrows     = 1;
pt(72).ncols     = 8;
pt(72).subsource = 'SS_DOUBLE';

pt(73).blockname = 'WordSbs/Port A';
pt(73).paramname = 'P5';
pt(73).class     = 'scalar';
pt(73).nrows     = 1;
pt(73).ncols     = 1;
pt(73).subsource = 'SS_DOUBLE';

pt(74).blockname = 'WordSbs/Port A';
pt(74).paramname = 'P6';
pt(74).class     = 'scalar';
pt(74).nrows     = 1;
pt(74).ncols     = 1;
pt(74).subsource = 'SS_DOUBLE';

pt(75).blockname = 'WordSbs/Port A';
pt(75).paramname = 'P7';
pt(75).class     = 'scalar';
pt(75).nrows     = 1;
pt(75).ncols     = 1;
pt(75).subsource = 'SS_DOUBLE';

pt(76).blockname = 'WordSbs/Port A';
pt(76).paramname = 'P8';
pt(76).class     = 'scalar';
pt(76).nrows     = 1;
pt(76).ncols     = 1;
pt(76).subsource = 'SS_DOUBLE';

pt(77).blockname = 'WordSbs/Port A';
pt(77).paramname = 'P9';
pt(77).class     = 'scalar';
pt(77).nrows     = 1;
pt(77).ncols     = 1;
pt(77).subsource = 'SS_DOUBLE';

pt(78).blockname = 'WordSbs/Port B';
pt(78).paramname = 'P1';
pt(78).class     = 'vector';
pt(78).nrows     = 1;
pt(78).ncols     = 8;
pt(78).subsource = 'SS_DOUBLE';

pt(79).blockname = 'WordSbs/Port B';
pt(79).paramname = 'P2';
pt(79).class     = 'scalar';
pt(79).nrows     = 1;
pt(79).ncols     = 1;
pt(79).subsource = 'SS_DOUBLE';

pt(80).blockname = 'WordSbs/Port B';
pt(80).paramname = 'P3';
pt(80).class     = 'vector';
pt(80).nrows     = 1;
pt(80).ncols     = 8;
pt(80).subsource = 'SS_DOUBLE';

pt(81).blockname = 'WordSbs/Port B';
pt(81).paramname = 'P4';
pt(81).class     = 'vector';
pt(81).nrows     = 1;
pt(81).ncols     = 8;
pt(81).subsource = 'SS_DOUBLE';

pt(82).blockname = 'WordSbs/Port B';
pt(82).paramname = 'P5';
pt(82).class     = 'scalar';
pt(82).nrows     = 1;
pt(82).ncols     = 1;
pt(82).subsource = 'SS_DOUBLE';

pt(83).blockname = 'WordSbs/Port B';
pt(83).paramname = 'P6';
pt(83).class     = 'scalar';
pt(83).nrows     = 1;
pt(83).ncols     = 1;
pt(83).subsource = 'SS_DOUBLE';

pt(84).blockname = 'WordSbs/Port B';
pt(84).paramname = 'P7';
pt(84).class     = 'scalar';
pt(84).nrows     = 1;
pt(84).ncols     = 1;
pt(84).subsource = 'SS_DOUBLE';

pt(85).blockname = 'WordSbs/Port B';
pt(85).paramname = 'P8';
pt(85).class     = 'scalar';
pt(85).nrows     = 1;
pt(85).ncols     = 1;
pt(85).subsource = 'SS_DOUBLE';

pt(86).blockname = 'WordSbs/Port B';
pt(86).paramname = 'P9';
pt(86).class     = 'scalar';
pt(86).nrows     = 1;
pt(86).ncols     = 1;
pt(86).subsource = 'SS_DOUBLE';

pt(87).blockname = 'WordSbs/xPC Target  Time ';
pt(87).paramname = 'P1';
pt(87).class     = 'scalar';
pt(87).nrows     = 1;
pt(87).ncols     = 1;
pt(87).subsource = 'SS_DOUBLE';

pt(88).blockname = 'WordSbs/xPC Target  Time ';
pt(88).paramname = 'P2';
pt(88).class     = 'scalar';
pt(88).nrows     = 1;
pt(88).ncols     = 1;
pt(88).subsource = 'SS_DOUBLE';

pt(89).blockname = 'WordSbs/Switch';
pt(89).paramname = 'Threshold';
pt(89).class     = 'scalar';
pt(89).nrows     = 1;
pt(89).ncols     = 1;
pt(89).subsource = 'SS_DOUBLE';

pt(90).blockname = 'CursorPos/Neural Control Subsystem/Constant';
pt(90).paramname = 'Value';
pt(90).class     = 'scalar';
pt(90).nrows     = 1;
pt(90).ncols     = 1;
pt(90).subsource = 'SS_DOUBLE';

pt(91).blockname = 'CursorPos/Neural Control Subsystem/Constant1';
pt(91).paramname = 'Value';
pt(91).class     = 'scalar';
pt(91).nrows     = 1;
pt(91).ncols     = 1;
pt(91).subsource = 'SS_DOUBLE';

pt(92).blockname = 'CursorPos/Neural Control Subsystem/PctToFrac';
pt(92).paramname = 'Gain';
pt(92).class     = 'scalar';
pt(92).nrows     = 1;
pt(92).ncols     = 1;
pt(92).subsource = 'SS_DOUBLE';

pt(93).blockname = 'WordSbs/While Iterator Subsystem/StobeHi';
pt(93).paramname = 'Value';
pt(93).class     = 'scalar';
pt(93).nrows     = 1;
pt(93).ncols     = 1;
pt(93).subsource = 'SS_DOUBLE';

pt(94).blockname = 'WordSbs/While Iterator Subsystem/StrobeLow';
pt(94).paramname = 'Value';
pt(94).class     = 'scalar';
pt(94).nrows     = 1;
pt(94).ncols     = 1;
pt(94).subsource = 'SS_DOUBLE';

pt(95).blockname = 'WordSbs/While Iterator Subsystem/ScaleTouSec';
pt(95).paramname = 'Gain';
pt(95).class     = 'scalar';
pt(95).nrows     = 1;
pt(95).ncols     = 1;
pt(95).subsource = 'SS_DOUBLE';

pt(96).blockname = 'WordSbs/While Iterator Subsystem/PCI-6025E ';
pt(96).paramname = 'P1';
pt(96).class     = 'vector';
pt(96).nrows     = 1;
pt(96).ncols     = 2;
pt(96).subsource = 'SS_DOUBLE';

pt(97).blockname = 'WordSbs/While Iterator Subsystem/PCI-6025E ';
pt(97).paramname = 'P2';
pt(97).class     = 'vector';
pt(97).nrows     = 1;
pt(97).ncols     = 2;
pt(97).subsource = 'SS_DOUBLE';

pt(98).blockname = 'WordSbs/While Iterator Subsystem/PCI-6025E ';
pt(98).paramname = 'P3';
pt(98).class     = 'vector';
pt(98).nrows     = 1;
pt(98).ncols     = 2;
pt(98).subsource = 'SS_DOUBLE';

pt(99).blockname = 'WordSbs/While Iterator Subsystem/PCI-6025E ';
pt(99).paramname = 'P4';
pt(99).class     = 'scalar';
pt(99).nrows     = 1;
pt(99).ncols     = 1;
pt(99).subsource = 'SS_DOUBLE';

pt(100).blockname = 'WordSbs/While Iterator Subsystem/PCI-6025E ';
pt(100).paramname = 'P5';
pt(100).class     = 'scalar';
pt(100).nrows     = 1;
pt(100).ncols     = 1;
pt(100).subsource = 'SS_DOUBLE';

pt(101).blockname = 'WordSbs/While Iterator Subsystem/PCI-6025E ';
pt(101).paramname = 'P6';
pt(101).class     = 'scalar';
pt(101).nrows     = 1;
pt(101).ncols     = 1;
pt(101).subsource = 'SS_DOUBLE';

pt(102).blockname = 'WordSbs/While Iterator Subsystem/PCI-6025E ';
pt(102).paramname = 'P7';
pt(102).class     = 'scalar';
pt(102).nrows     = 1;
pt(102).ncols     = 1;
pt(102).subsource = 'SS_DOUBLE';

pt(103).blockname = 'WordSbs/While Iterator Subsystem/xPC Target  Time ';
pt(103).paramname = 'P1';
pt(103).class     = 'scalar';
pt(103).nrows     = 1;
pt(103).ncols     = 1;
pt(103).subsource = 'SS_DOUBLE';

pt(104).blockname = 'WordSbs/While Iterator Subsystem/xPC Target  Time ';
pt(104).paramname = 'P2';
pt(104).class     = 'scalar';
pt(104).nrows     = 1;
pt(104).ncols     = 1;
pt(104).subsource = 'SS_DOUBLE';

pt(105).blockname = 'WordSbs/While Iterator Subsystem/Compare To Constant/Constant';
pt(105).paramname = 'Value';
pt(105).class     = 'scalar';
pt(105).nrows     = 1;
pt(105).ncols     = 1;
pt(105).subsource = 'SS_DOUBLE';

pt(106).blockname = 'WordSbs/While Iterator Subsystem/Compare To Constant1/Constant';
pt(106).paramname = 'Value';
pt(106).class     = 'scalar';
pt(106).nrows     = 1;
pt(106).ncols     = 1;
pt(106).subsource = 'SS_DOUBLE';

function len = getlenPT
len = 106;

