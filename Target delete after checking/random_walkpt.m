function pt=random_walkpt
pt = [];
pt(1).blockname = 'zeroX';
pt(1).paramname = 'Value';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(getlenPT) = pt(1);

pt(2).blockname = 'zeroY';
pt(2).paramname = 'Value';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';

pt(3).blockname = 'MG1';
pt(3).paramname = 'Gain';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';

pt(4).blockname = 'MG2';
pt(4).paramname = 'Gain';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';

pt(5).blockname = 'Memory';
pt(5).paramname = 'X0';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_BOOLEAN';

pt(6).blockname = 'Behavior RW';
pt(6).paramname = 'P1';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';

pt(7).blockname = 'Behavior RW';
pt(7).paramname = 'P2';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';

pt(8).blockname = 'Behavior RW';
pt(8).paramname = 'P3';
pt(8).class     = 'scalar';
pt(8).nrows     = 1;
pt(8).ncols     = 1;
pt(8).subsource = 'SS_DOUBLE';

pt(9).blockname = 'Behavior RW';
pt(9).paramname = 'P4';
pt(9).class     = 'scalar';
pt(9).nrows     = 1;
pt(9).ncols     = 1;
pt(9).subsource = 'SS_DOUBLE';

pt(10).blockname = 'Behavior RW';
pt(10).paramname = 'P5';
pt(10).class     = 'scalar';
pt(10).nrows     = 1;
pt(10).ncols     = 1;
pt(10).subsource = 'SS_DOUBLE';

pt(11).blockname = 'Behavior RW';
pt(11).paramname = 'P6';
pt(11).class     = 'scalar';
pt(11).nrows     = 1;
pt(11).ncols     = 1;
pt(11).subsource = 'SS_DOUBLE';

pt(12).blockname = 'Behavior RW';
pt(12).paramname = 'P7';
pt(12).class     = 'scalar';
pt(12).nrows     = 1;
pt(12).ncols     = 1;
pt(12).subsource = 'SS_DOUBLE';

pt(13).blockname = 'Behavior RW';
pt(13).paramname = 'P8';
pt(13).class     = 'scalar';
pt(13).nrows     = 1;
pt(13).ncols     = 1;
pt(13).subsource = 'SS_DOUBLE';

pt(14).blockname = 'Behavior RW';
pt(14).paramname = 'P9';
pt(14).class     = 'scalar';
pt(14).nrows     = 1;
pt(14).ncols     = 1;
pt(14).subsource = 'SS_DOUBLE';

pt(15).blockname = 'Behavior RW';
pt(15).paramname = 'P10';
pt(15).class     = 'scalar';
pt(15).nrows     = 1;
pt(15).ncols     = 1;
pt(15).subsource = 'SS_DOUBLE';

pt(16).blockname = 'PCI-6025E ';
pt(16).paramname = 'P1';
pt(16).class     = 'vector';
pt(16).nrows     = 1;
pt(16).ncols     = 2;
pt(16).subsource = 'SS_DOUBLE';

pt(17).blockname = 'PCI-6025E ';
pt(17).paramname = 'P2';
pt(17).class     = 'vector';
pt(17).nrows     = 1;
pt(17).ncols     = 2;
pt(17).subsource = 'SS_DOUBLE';

pt(18).blockname = 'PCI-6025E ';
pt(18).paramname = 'P3';
pt(18).class     = 'vector';
pt(18).nrows     = 1;
pt(18).ncols     = 2;
pt(18).subsource = 'SS_DOUBLE';

pt(19).blockname = 'PCI-6025E ';
pt(19).paramname = 'P4';
pt(19).class     = 'vector';
pt(19).nrows     = 1;
pt(19).ncols     = 2;
pt(19).subsource = 'SS_DOUBLE';

pt(20).blockname = 'PCI-6025E ';
pt(20).paramname = 'P5';
pt(20).class     = 'scalar';
pt(20).nrows     = 1;
pt(20).ncols     = 1;
pt(20).subsource = 'SS_DOUBLE';

pt(21).blockname = 'PCI-6025E ';
pt(21).paramname = 'P6';
pt(21).class     = 'vector';
pt(21).nrows     = 1;
pt(21).ncols     = 2;
pt(21).subsource = 'SS_DOUBLE';

pt(22).blockname = 'PCI-6025E ';
pt(22).paramname = 'P7';
pt(22).class     = 'scalar';
pt(22).nrows     = 1;
pt(22).ncols     = 1;
pt(22).subsource = 'SS_DOUBLE';

pt(23).blockname = 'BoundingBox/XHighLimit';
pt(23).paramname = 'Value';
pt(23).class     = 'scalar';
pt(23).nrows     = 1;
pt(23).ncols     = 1;
pt(23).subsource = 'SS_DOUBLE';

pt(24).blockname = 'BoundingBox/XLowLimit';
pt(24).paramname = 'Value';
pt(24).class     = 'scalar';
pt(24).nrows     = 1;
pt(24).ncols     = 1;
pt(24).subsource = 'SS_DOUBLE';

pt(25).blockname = 'BoundingBox/YHighLimit';
pt(25).paramname = 'Value';
pt(25).class     = 'scalar';
pt(25).nrows     = 1;
pt(25).ncols     = 1;
pt(25).subsource = 'SS_DOUBLE';

pt(26).blockname = 'BoundingBox/YLowLimit';
pt(26).paramname = 'Value';
pt(26).class     = 'scalar';
pt(26).nrows     = 1;
pt(26).ncols     = 1;
pt(26).subsource = 'SS_DOUBLE';

pt(27).blockname = 'Compare To Constant/Constant';
pt(27).paramname = 'Value';
pt(27).class     = 'scalar';
pt(27).nrows     = 1;
pt(27).ncols     = 1;
pt(27).subsource = 'SS_DOUBLE';

pt(28).blockname = 'Compare To Constant1/Constant';
pt(28).paramname = 'Value';
pt(28).class     = 'scalar';
pt(28).nrows     = 1;
pt(28).ncols     = 1;
pt(28).subsource = 'SS_DOUBLE';

pt(29).blockname = 'Force Generator/DynamicAngle';
pt(29).paramname = 'Value';
pt(29).class     = 'scalar';
pt(29).nrows     = 1;
pt(29).ncols     = 1;
pt(29).subsource = 'SS_DOUBLE';

pt(30).blockname = 'Force Generator/Load';
pt(30).paramname = 'Value';
pt(30).class     = 'scalar';
pt(30).nrows     = 1;
pt(30).ncols     = 1;
pt(30).subsource = 'SS_DOUBLE';

pt(31).blockname = 'Force Generator/Off';
pt(31).paramname = 'Value';
pt(31).class     = 'scalar';
pt(31).nrows     = 1;
pt(31).ncols     = 1;
pt(31).subsource = 'SS_DOUBLE';

pt(32).blockname = 'Force Generator/staticX';
pt(32).paramname = 'Value';
pt(32).class     = 'scalar';
pt(32).nrows     = 1;
pt(32).ncols     = 1;
pt(32).subsource = 'SS_DOUBLE';

pt(33).blockname = 'Force Generator/staticY';
pt(33).paramname = 'Value';
pt(33).class     = 'scalar';
pt(33).nrows     = 1;
pt(33).ncols     = 1;
pt(33).subsource = 'SS_DOUBLE';

pt(34).blockname = 'Force Generator/visAngle';
pt(34).paramname = 'Value';
pt(34).class     = 'scalar';
pt(34).nrows     = 1;
pt(34).ncols     = 1;
pt(34).subsource = 'SS_DOUBLE';

pt(35).blockname = 'Force Generator/Gain';
pt(35).paramname = 'Gain';
pt(35).class     = 'scalar';
pt(35).nrows     = 1;
pt(35).ncols     = 1;
pt(35).subsource = 'SS_DOUBLE';

pt(36).blockname = 'Force Generator/LorentzForceGain';
pt(36).paramname = 'Gain';
pt(36).class     = 'scalar';
pt(36).nrows     = 1;
pt(36).ncols     = 1;
pt(36).subsource = 'SS_DOUBLE';

pt(37).blockname = 'Force outside box/Gain1';
pt(37).paramname = 'Gain';
pt(37).class     = 'scalar';
pt(37).nrows     = 1;
pt(37).ncols     = 1;
pt(37).subsource = 'SS_DOUBLE';

pt(38).blockname = 'Force outside box/Gain2';
pt(38).paramname = 'Gain';
pt(38).class     = 'scalar';
pt(38).nrows     = 1;
pt(38).ncols     = 1;
pt(38).subsource = 'SS_DOUBLE';

pt(39).blockname = 'Force outside box/Gain3';
pt(39).paramname = 'Gain';
pt(39).class     = 'scalar';
pt(39).nrows     = 1;
pt(39).ncols     = 1;
pt(39).subsource = 'SS_DOUBLE';

pt(40).blockname = 'Force outside box/Gain4';
pt(40).paramname = 'Gain';
pt(40).class     = 'scalar';
pt(40).nrows     = 1;
pt(40).ncols     = 1;
pt(40).subsource = 'SS_DOUBLE';

pt(41).blockname = 'Force outside box/Saturation';
pt(41).paramname = 'UpperLimit';
pt(41).class     = 'scalar';
pt(41).nrows     = 1;
pt(41).ncols     = 1;
pt(41).subsource = 'SS_DOUBLE';

pt(42).blockname = 'Force outside box/Saturation';
pt(42).paramname = 'LowerLimit';
pt(42).class     = 'scalar';
pt(42).nrows     = 1;
pt(42).ncols     = 1;
pt(42).subsource = 'SS_DOUBLE';

pt(43).blockname = 'Force outside box/Saturation1';
pt(43).paramname = 'UpperLimit';
pt(43).class     = 'scalar';
pt(43).nrows     = 1;
pt(43).ncols     = 1;
pt(43).subsource = 'SS_DOUBLE';

pt(44).blockname = 'Force outside box/Saturation1';
pt(44).paramname = 'LowerLimit';
pt(44).class     = 'scalar';
pt(44).nrows     = 1;
pt(44).ncols     = 1;
pt(44).subsource = 'SS_DOUBLE';

pt(45).blockname = 'Pos2VelX/dG';
pt(45).paramname = 'Gain';
pt(45).class     = 'scalar';
pt(45).nrows     = 1;
pt(45).ncols     = 1;
pt(45).subsource = 'SS_DOUBLE';

pt(46).blockname = 'Pos2VelX/Digital Filter';
pt(46).paramname = 'ICRTP';
pt(46).class     = 'scalar';
pt(46).nrows     = 1;
pt(46).ncols     = 1;
pt(46).subsource = 'SS_DOUBLE';

pt(47).blockname = 'Pos2VelX/Digital Filter';
pt(47).paramname = 'RTP1COEFF';
pt(47).class     = 'vector';
pt(47).nrows     = 1;
pt(47).ncols     = 11;
pt(47).subsource = 'SS_DOUBLE';

pt(48).blockname = 'Pos2VelX/Digital Filter2';
pt(48).paramname = 'ICRTP';
pt(48).class     = 'scalar';
pt(48).nrows     = 1;
pt(48).ncols     = 1;
pt(48).subsource = 'SS_DOUBLE';

pt(49).blockname = 'Pos2VelX/Digital Filter2';
pt(49).paramname = 'RTP1COEFF';
pt(49).class     = 'vector';
pt(49).nrows     = 1;
pt(49).ncols     = 11;
pt(49).subsource = 'SS_DOUBLE';

pt(50).blockname = 'Pos2VelY/dG';
pt(50).paramname = 'Gain';
pt(50).class     = 'scalar';
pt(50).nrows     = 1;
pt(50).ncols     = 1;
pt(50).subsource = 'SS_DOUBLE';

pt(51).blockname = 'Pos2VelY/Digital Filter';
pt(51).paramname = 'ICRTP';
pt(51).class     = 'scalar';
pt(51).nrows     = 1;
pt(51).ncols     = 1;
pt(51).subsource = 'SS_DOUBLE';

pt(52).blockname = 'Pos2VelY/Digital Filter';
pt(52).paramname = 'RTP1COEFF';
pt(52).class     = 'vector';
pt(52).nrows     = 1;
pt(52).ncols     = 11;
pt(52).subsource = 'SS_DOUBLE';

pt(53).blockname = 'Pos2VelY/Digital Filter2';
pt(53).paramname = 'ICRTP';
pt(53).class     = 'scalar';
pt(53).nrows     = 1;
pt(53).ncols     = 1;
pt(53).subsource = 'SS_DOUBLE';

pt(54).blockname = 'Pos2VelY/Digital Filter2';
pt(54).paramname = 'RTP1COEFF';
pt(54).class     = 'vector';
pt(54).nrows     = 1;
pt(54).ncols     = 11;
pt(54).subsource = 'SS_DOUBLE';

pt(55).blockname = 'RewardSbs/Memory1';
pt(55).paramname = 'X0';
pt(55).class     = 'scalar';
pt(55).nrows     = 1;
pt(55).ncols     = 1;
pt(55).subsource = 'SS_BOOLEAN';

pt(56).blockname = 'Schmidt/Time';
pt(56).paramname = 'Value';
pt(56).class     = 'scalar';
pt(56).nrows     = 1;
pt(56).ncols     = 1;
pt(56).subsource = 'SS_DOUBLE';

pt(57).blockname = 'Schmidt/Memory';
pt(57).paramname = 'X0';
pt(57).class     = 'scalar';
pt(57).nrows     = 1;
pt(57).ncols     = 1;
pt(57).subsource = 'SS_BOOLEAN';

pt(58).blockname = 'Target Peek/Gain';
pt(58).paramname = 'Gain';
pt(58).class     = 'scalar';
pt(58).nrows     = 1;
pt(58).ncols     = 1;
pt(58).subsource = 'SS_DOUBLE';

pt(59).blockname = 'Target Peek/Gain1';
pt(59).paramname = 'Gain';
pt(59).class     = 'scalar';
pt(59).nrows     = 1;
pt(59).ncols     = 1;
pt(59).subsource = 'SS_DOUBLE';

pt(60).blockname = 'UDPXmit/Send';
pt(60).paramname = 'P1';
pt(60).class     = 'vector';
pt(60).nrows     = 1;
pt(60).ncols     = 11;
pt(60).subsource = 'SS_DOUBLE';

pt(61).blockname = 'UDPXmit/Send';
pt(61).paramname = 'P2';
pt(61).class     = 'scalar';
pt(61).nrows     = 1;
pt(61).ncols     = 1;
pt(61).subsource = 'SS_DOUBLE';

pt(62).blockname = 'UDPXmit/Send';
pt(62).paramname = 'P3';
pt(62).class     = 'scalar';
pt(62).nrows     = 1;
pt(62).ncols     = 1;
pt(62).subsource = 'SS_DOUBLE';

pt(63).blockname = 'UDPXmit/Send';
pt(63).paramname = 'P4';
pt(63).class     = 'scalar';
pt(63).nrows     = 1;
pt(63).ncols     = 1;
pt(63).subsource = 'SS_DOUBLE';

pt(64).blockname = 'WordSbs/Port A';
pt(64).paramname = 'P1';
pt(64).class     = 'vector';
pt(64).nrows     = 1;
pt(64).ncols     = 8;
pt(64).subsource = 'SS_DOUBLE';

pt(65).blockname = 'WordSbs/Port A';
pt(65).paramname = 'P2';
pt(65).class     = 'scalar';
pt(65).nrows     = 1;
pt(65).ncols     = 1;
pt(65).subsource = 'SS_DOUBLE';

pt(66).blockname = 'WordSbs/Port A';
pt(66).paramname = 'P3';
pt(66).class     = 'vector';
pt(66).nrows     = 1;
pt(66).ncols     = 8;
pt(66).subsource = 'SS_DOUBLE';

pt(67).blockname = 'WordSbs/Port A';
pt(67).paramname = 'P4';
pt(67).class     = 'vector';
pt(67).nrows     = 1;
pt(67).ncols     = 8;
pt(67).subsource = 'SS_DOUBLE';

pt(68).blockname = 'WordSbs/Port A';
pt(68).paramname = 'P5';
pt(68).class     = 'scalar';
pt(68).nrows     = 1;
pt(68).ncols     = 1;
pt(68).subsource = 'SS_DOUBLE';

pt(69).blockname = 'WordSbs/Port A';
pt(69).paramname = 'P6';
pt(69).class     = 'scalar';
pt(69).nrows     = 1;
pt(69).ncols     = 1;
pt(69).subsource = 'SS_DOUBLE';

pt(70).blockname = 'WordSbs/Port A';
pt(70).paramname = 'P7';
pt(70).class     = 'vector';
pt(70).nrows     = 1;
pt(70).ncols     = 2;
pt(70).subsource = 'SS_DOUBLE';

pt(71).blockname = 'WordSbs/Port A';
pt(71).paramname = 'P8';
pt(71).class     = 'scalar';
pt(71).nrows     = 1;
pt(71).ncols     = 1;
pt(71).subsource = 'SS_DOUBLE';

pt(72).blockname = 'WordSbs/Port A';
pt(72).paramname = 'P9';
pt(72).class     = 'scalar';
pt(72).nrows     = 1;
pt(72).ncols     = 1;
pt(72).subsource = 'SS_DOUBLE';

pt(73).blockname = 'XY Position Subsystem/elbowOffset';
pt(73).paramname = 'Value';
pt(73).class     = 'scalar';
pt(73).nrows     = 1;
pt(73).ncols     = 1;
pt(73).subsource = 'SS_DOUBLE';

pt(74).blockname = 'XY Position Subsystem/shoulderOffset';
pt(74).paramname = 'Value';
pt(74).class     = 'scalar';
pt(74).nrows     = 1;
pt(74).ncols     = 1;
pt(74).subsource = 'SS_DOUBLE';

pt(75).blockname = 'XY Position Subsystem/Gain';
pt(75).paramname = 'Gain';
pt(75).class     = 'scalar';
pt(75).nrows     = 1;
pt(75).ncols     = 1;
pt(75).subsource = 'SS_DOUBLE';

pt(76).blockname = 'XY Position Subsystem/Gain1';
pt(76).paramname = 'Gain';
pt(76).class     = 'scalar';
pt(76).nrows     = 1;
pt(76).ncols     = 1;
pt(76).subsource = 'SS_DOUBLE';

pt(77).blockname = 'XY Position Subsystem/PCI-QUAD04 ';
pt(77).paramname = 'P1';
pt(77).class     = 'scalar';
pt(77).nrows     = 1;
pt(77).ncols     = 1;
pt(77).subsource = 'SS_DOUBLE';

pt(78).blockname = 'XY Position Subsystem/PCI-QUAD04 ';
pt(78).paramname = 'P2';
pt(78).class     = 'scalar';
pt(78).nrows     = 1;
pt(78).ncols     = 1;
pt(78).subsource = 'SS_DOUBLE';

pt(79).blockname = 'XY Position Subsystem/PCI-QUAD04 ';
pt(79).paramname = 'P3';
pt(79).class     = 'scalar';
pt(79).nrows     = 1;
pt(79).ncols     = 1;
pt(79).subsource = 'SS_DOUBLE';

pt(80).blockname = 'XY Position Subsystem/PCI-QUAD04 ';
pt(80).paramname = 'P4';
pt(80).class     = 'scalar';
pt(80).nrows     = 1;
pt(80).ncols     = 1;
pt(80).subsource = 'SS_DOUBLE';

pt(81).blockname = 'XY Position Subsystem/PCI-QUAD04 ';
pt(81).paramname = 'P5';
pt(81).class     = 'scalar';
pt(81).nrows     = 1;
pt(81).ncols     = 1;
pt(81).subsource = 'SS_DOUBLE';

pt(82).blockname = 'XY Position Subsystem/PCI-QUAD04 ';
pt(82).paramname = 'P6';
pt(82).class     = 'scalar';
pt(82).nrows     = 1;
pt(82).ncols     = 1;
pt(82).subsource = 'SS_DOUBLE';

pt(83).blockname = 'XY Position Subsystem/PCI-QUAD04 ';
pt(83).paramname = 'P7';
pt(83).class     = 'scalar';
pt(83).nrows     = 1;
pt(83).ncols     = 1;
pt(83).subsource = 'SS_DOUBLE';

pt(84).blockname = 'XY Position Subsystem/PCI-QUAD04 ';
pt(84).paramname = 'P8';
pt(84).class     = 'scalar';
pt(84).nrows     = 1;
pt(84).ncols     = 1;
pt(84).subsource = 'SS_DOUBLE';

pt(85).blockname = 'XY Position Subsystem/PCI-QUAD04 ';
pt(85).paramname = 'P9';
pt(85).class     = 'scalar';
pt(85).nrows     = 1;
pt(85).ncols     = 1;
pt(85).subsource = 'SS_DOUBLE';

pt(86).blockname = 'XY Position Subsystem/PCI-QUAD04 ';
pt(86).paramname = 'P10';
pt(86).class     = 'scalar';
pt(86).nrows     = 1;
pt(86).ncols     = 1;
pt(86).subsource = 'SS_DOUBLE';

pt(87).blockname = 'XY Position Subsystem/PCI-QUAD04 ';
pt(87).paramname = 'P11';
pt(87).class     = 'scalar';
pt(87).nrows     = 1;
pt(87).ncols     = 1;
pt(87).subsource = 'SS_DOUBLE';

pt(88).blockname = 'XY Position Subsystem/PCI-QUAD04 1';
pt(88).paramname = 'P1';
pt(88).class     = 'scalar';
pt(88).nrows     = 1;
pt(88).ncols     = 1;
pt(88).subsource = 'SS_DOUBLE';

pt(89).blockname = 'XY Position Subsystem/PCI-QUAD04 1';
pt(89).paramname = 'P2';
pt(89).class     = 'scalar';
pt(89).nrows     = 1;
pt(89).ncols     = 1;
pt(89).subsource = 'SS_DOUBLE';

pt(90).blockname = 'XY Position Subsystem/PCI-QUAD04 1';
pt(90).paramname = 'P3';
pt(90).class     = 'scalar';
pt(90).nrows     = 1;
pt(90).ncols     = 1;
pt(90).subsource = 'SS_DOUBLE';

pt(91).blockname = 'XY Position Subsystem/PCI-QUAD04 1';
pt(91).paramname = 'P4';
pt(91).class     = 'scalar';
pt(91).nrows     = 1;
pt(91).ncols     = 1;
pt(91).subsource = 'SS_DOUBLE';

pt(92).blockname = 'XY Position Subsystem/PCI-QUAD04 1';
pt(92).paramname = 'P5';
pt(92).class     = 'scalar';
pt(92).nrows     = 1;
pt(92).ncols     = 1;
pt(92).subsource = 'SS_DOUBLE';

pt(93).blockname = 'XY Position Subsystem/PCI-QUAD04 1';
pt(93).paramname = 'P6';
pt(93).class     = 'scalar';
pt(93).nrows     = 1;
pt(93).ncols     = 1;
pt(93).subsource = 'SS_DOUBLE';

pt(94).blockname = 'XY Position Subsystem/PCI-QUAD04 1';
pt(94).paramname = 'P7';
pt(94).class     = 'scalar';
pt(94).nrows     = 1;
pt(94).ncols     = 1;
pt(94).subsource = 'SS_DOUBLE';

pt(95).blockname = 'XY Position Subsystem/PCI-QUAD04 1';
pt(95).paramname = 'P8';
pt(95).class     = 'scalar';
pt(95).nrows     = 1;
pt(95).ncols     = 1;
pt(95).subsource = 'SS_DOUBLE';

pt(96).blockname = 'XY Position Subsystem/PCI-QUAD04 1';
pt(96).paramname = 'P9';
pt(96).class     = 'scalar';
pt(96).nrows     = 1;
pt(96).ncols     = 1;
pt(96).subsource = 'SS_DOUBLE';

pt(97).blockname = 'XY Position Subsystem/PCI-QUAD04 1';
pt(97).paramname = 'P10';
pt(97).class     = 'scalar';
pt(97).nrows     = 1;
pt(97).ncols     = 1;
pt(97).subsource = 'SS_DOUBLE';

pt(98).blockname = 'XY Position Subsystem/PCI-QUAD04 1';
pt(98).paramname = 'P11';
pt(98).class     = 'scalar';
pt(98).nrows     = 1;
pt(98).ncols     = 1;
pt(98).subsource = 'SS_DOUBLE';

pt(99).blockname = 'Force Generator/ViscLoadSubsystem/Gain';
pt(99).paramname = 'Gain';
pt(99).class     = 'scalar';
pt(99).nrows     = 1;
pt(99).ncols     = 1;
pt(99).subsource = 'SS_DOUBLE';

pt(100).blockname = 'Force outside box/Leave center/Delay Input1';
pt(100).paramname = 'X0';
pt(100).class     = 'scalar';
pt(100).nrows     = 1;
pt(100).ncols     = 1;
pt(100).subsource = 'SS_UINT8';

pt(101).blockname = 'Force outside box/Leave center delay/Delay Input1';
pt(101).paramname = 'X0';
pt(101).class     = 'scalar';
pt(101).nrows     = 1;
pt(101).ncols     = 1;
pt(101).subsource = 'SS_UINT8';

pt(102).blockname = 'Force outside box/S-R Flip-Flop/Logic';
pt(102).paramname = 'TruthTable';
pt(102).class     = 'col-mat';
pt(102).nrows     = 8;
pt(102).ncols     = 2;
pt(102).subsource = 'SS_BOOLEAN';

pt(103).blockname = 'Force outside box/S-R Flip-Flop/Memory';
pt(103).paramname = 'X0';
pt(103).class     = 'scalar';
pt(103).nrows     = 1;
pt(103).ncols     = 1;
pt(103).subsource = 'SS_BOOLEAN';

pt(104).blockname = 'Force outside box/Schmidt1/Time';
pt(104).paramname = 'Value';
pt(104).class     = 'scalar';
pt(104).nrows     = 1;
pt(104).ncols     = 1;
pt(104).subsource = 'SS_DOUBLE';

pt(105).blockname = 'Force outside box/Schmidt1/Memory';
pt(105).paramname = 'X0';
pt(105).class     = 'scalar';
pt(105).nrows     = 1;
pt(105).ncols     = 1;
pt(105).subsource = 'SS_BOOLEAN';

pt(106).blockname = 'Force outside box/Schmidt3/Time';
pt(106).paramname = 'Value';
pt(106).class     = 'scalar';
pt(106).nrows     = 1;
pt(106).ncols     = 1;
pt(106).subsource = 'SS_DOUBLE';

pt(107).blockname = 'Force outside box/Schmidt3/Memory';
pt(107).paramname = 'X0';
pt(107).class     = 'scalar';
pt(107).nrows     = 1;
pt(107).ncols     = 1;
pt(107).subsource = 'SS_BOOLEAN';

pt(108).blockname = 'Force outside box/Timer/Time';
pt(108).paramname = 'Value';
pt(108).class     = 'scalar';
pt(108).nrows     = 1;
pt(108).ncols     = 1;
pt(108).subsource = 'SS_DOUBLE';

pt(109).blockname = 'Force outside box/Timer/Memory';
pt(109).paramname = 'X0';
pt(109).class     = 'scalar';
pt(109).nrows     = 1;
pt(109).ncols     = 1;
pt(109).subsource = 'SS_BOOLEAN';

pt(110).blockname = 'RewardSbs/Schmidt1/Time';
pt(110).paramname = 'Value';
pt(110).class     = 'scalar';
pt(110).nrows     = 1;
pt(110).ncols     = 1;
pt(110).subsource = 'SS_DOUBLE';

pt(111).blockname = 'RewardSbs/Schmidt1/Memory';
pt(111).paramname = 'X0';
pt(111).class     = 'scalar';
pt(111).nrows     = 1;
pt(111).ncols     = 1;
pt(111).subsource = 'SS_BOOLEAN';

pt(112).blockname = 'XY Position Subsystem/Cursor Rotation/AngleOffset';
pt(112).paramname = 'Value';
pt(112).class     = 'scalar';
pt(112).nrows     = 1;
pt(112).ncols     = 1;
pt(112).subsource = 'SS_DOUBLE';

pt(113).blockname = 'XY Position Subsystem/For Iterator Subsystem/Constant';
pt(113).paramname = 'Value';
pt(113).class     = 'scalar';
pt(113).nrows     = 1;
pt(113).ncols     = 1;
pt(113).subsource = 'SS_DOUBLE';

pt(114).blockname = 'XY Position Subsystem/For Iterator Subsystem/Port B';
pt(114).paramname = 'P1';
pt(114).class     = 'vector';
pt(114).nrows     = 1;
pt(114).ncols     = 8;
pt(114).subsource = 'SS_DOUBLE';

pt(115).blockname = 'XY Position Subsystem/For Iterator Subsystem/Port B';
pt(115).paramname = 'P2';
pt(115).class     = 'scalar';
pt(115).nrows     = 1;
pt(115).ncols     = 1;
pt(115).subsource = 'SS_DOUBLE';

pt(116).blockname = 'XY Position Subsystem/For Iterator Subsystem/Port B';
pt(116).paramname = 'P3';
pt(116).class     = 'vector';
pt(116).nrows     = 1;
pt(116).ncols     = 8;
pt(116).subsource = 'SS_DOUBLE';

pt(117).blockname = 'XY Position Subsystem/For Iterator Subsystem/Port B';
pt(117).paramname = 'P4';
pt(117).class     = 'vector';
pt(117).nrows     = 1;
pt(117).ncols     = 8;
pt(117).subsource = 'SS_DOUBLE';

pt(118).blockname = 'XY Position Subsystem/For Iterator Subsystem/Port B';
pt(118).paramname = 'P5';
pt(118).class     = 'scalar';
pt(118).nrows     = 1;
pt(118).ncols     = 1;
pt(118).subsource = 'SS_DOUBLE';

pt(119).blockname = 'XY Position Subsystem/For Iterator Subsystem/Port B';
pt(119).paramname = 'P6';
pt(119).class     = 'scalar';
pt(119).nrows     = 1;
pt(119).ncols     = 1;
pt(119).subsource = 'SS_DOUBLE';

pt(120).blockname = 'XY Position Subsystem/For Iterator Subsystem/Port B';
pt(120).paramname = 'P7';
pt(120).class     = 'vector';
pt(120).nrows     = 1;
pt(120).ncols     = 2;
pt(120).subsource = 'SS_DOUBLE';

pt(121).blockname = 'XY Position Subsystem/For Iterator Subsystem/Port B';
pt(121).paramname = 'P8';
pt(121).class     = 'scalar';
pt(121).nrows     = 1;
pt(121).ncols     = 1;
pt(121).subsource = 'SS_DOUBLE';

pt(122).blockname = 'XY Position Subsystem/For Iterator Subsystem/Port B';
pt(122).paramname = 'P9';
pt(122).class     = 'scalar';
pt(122).nrows     = 1;
pt(122).ncols     = 1;
pt(122).subsource = 'SS_DOUBLE';

pt(123).blockname = 'XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ';
pt(123).paramname = 'P1';
pt(123).class     = 'scalar';
pt(123).nrows     = 1;
pt(123).ncols     = 1;
pt(123).subsource = 'SS_DOUBLE';

pt(124).blockname = 'XY Position Subsystem/For Iterator Subsystem/xPC Target  Time ';
pt(124).paramname = 'P2';
pt(124).class     = 'scalar';
pt(124).nrows     = 1;
pt(124).ncols     = 1;
pt(124).subsource = 'SS_DOUBLE';

pt(125).blockname = 'XY Position Subsystem/Jacobian-Cartesian Transformation/xoffset';
pt(125).paramname = 'Value';
pt(125).class     = 'scalar';
pt(125).nrows     = 1;
pt(125).ncols     = 1;
pt(125).subsource = 'SS_DOUBLE';

pt(126).blockname = 'XY Position Subsystem/Jacobian-Cartesian Transformation/yoffset';
pt(126).paramname = 'Value';
pt(126).class     = 'scalar';
pt(126).nrows     = 1;
pt(126).ncols     = 1;
pt(126).subsource = 'SS_DOUBLE';

pt(127).blockname = 'Force Generator/LorentzForce/Lorentz/beta';
pt(127).paramname = 'Value';
pt(127).class     = 'scalar';
pt(127).nrows     = 1;
pt(127).ncols     = 1;
pt(127).subsource = 'SS_DOUBLE';

pt(128).blockname = 'Force Generator/LorentzForce/Lorentz/rho';
pt(128).paramname = 'Value';
pt(128).class     = 'scalar';
pt(128).nrows     = 1;
pt(128).ncols     = 1;
pt(128).subsource = 'SS_DOUBLE';

pt(129).blockname = 'Force Generator/LorentzForce/Lorentz/sigma';
pt(129).paramname = 'Value';
pt(129).class     = 'scalar';
pt(129).nrows     = 1;
pt(129).ncols     = 1;
pt(129).subsource = 'SS_DOUBLE';

pt(130).blockname = 'Force Generator/LorentzForce/Lorentz/timescale';
pt(130).paramname = 'Value';
pt(130).class     = 'scalar';
pt(130).nrows     = 1;
pt(130).ncols     = 1;
pt(130).subsource = 'SS_DOUBLE';

pt(131).blockname = 'Force Generator/LorentzForce/Lorentz/x';
pt(131).paramname = 'X0';
pt(131).class     = 'scalar';
pt(131).nrows     = 1;
pt(131).ncols     = 1;
pt(131).subsource = 'SS_DOUBLE';

pt(132).blockname = 'Force Generator/LorentzForce/Lorentz/y';
pt(132).paramname = 'X0';
pt(132).class     = 'scalar';
pt(132).nrows     = 1;
pt(132).ncols     = 1;
pt(132).subsource = 'SS_DOUBLE';

pt(133).blockname = 'Force Generator/LorentzForce/Lorentz/z';
pt(133).paramname = 'X0';
pt(133).class     = 'scalar';
pt(133).nrows     = 1;
pt(133).ncols     = 1;
pt(133).subsource = 'SS_DOUBLE';

pt(134).blockname = 'Force Generator/LorentzForce/Lorentz1/beta';
pt(134).paramname = 'Value';
pt(134).class     = 'scalar';
pt(134).nrows     = 1;
pt(134).ncols     = 1;
pt(134).subsource = 'SS_DOUBLE';

pt(135).blockname = 'Force Generator/LorentzForce/Lorentz1/rho';
pt(135).paramname = 'Value';
pt(135).class     = 'scalar';
pt(135).nrows     = 1;
pt(135).ncols     = 1;
pt(135).subsource = 'SS_DOUBLE';

pt(136).blockname = 'Force Generator/LorentzForce/Lorentz1/sigma';
pt(136).paramname = 'Value';
pt(136).class     = 'scalar';
pt(136).nrows     = 1;
pt(136).ncols     = 1;
pt(136).subsource = 'SS_DOUBLE';

pt(137).blockname = 'Force Generator/LorentzForce/Lorentz1/timescale';
pt(137).paramname = 'Value';
pt(137).class     = 'scalar';
pt(137).nrows     = 1;
pt(137).ncols     = 1;
pt(137).subsource = 'SS_DOUBLE';

pt(138).blockname = 'Force Generator/LorentzForce/Lorentz1/x';
pt(138).paramname = 'X0';
pt(138).class     = 'scalar';
pt(138).nrows     = 1;
pt(138).ncols     = 1;
pt(138).subsource = 'SS_DOUBLE';

pt(139).blockname = 'Force Generator/LorentzForce/Lorentz1/y';
pt(139).paramname = 'X0';
pt(139).class     = 'scalar';
pt(139).nrows     = 1;
pt(139).ncols     = 1;
pt(139).subsource = 'SS_DOUBLE';

pt(140).blockname = 'Force Generator/LorentzForce/Lorentz1/z';
pt(140).paramname = 'X0';
pt(140).class     = 'scalar';
pt(140).nrows     = 1;
pt(140).ncols     = 1;
pt(140).subsource = 'SS_DOUBLE';

pt(141).blockname = 'Force Generator/LorentzForce/Lorentz2/beta';
pt(141).paramname = 'Value';
pt(141).class     = 'scalar';
pt(141).nrows     = 1;
pt(141).ncols     = 1;
pt(141).subsource = 'SS_DOUBLE';

pt(142).blockname = 'Force Generator/LorentzForce/Lorentz2/rho';
pt(142).paramname = 'Value';
pt(142).class     = 'scalar';
pt(142).nrows     = 1;
pt(142).ncols     = 1;
pt(142).subsource = 'SS_DOUBLE';

pt(143).blockname = 'Force Generator/LorentzForce/Lorentz2/sigma';
pt(143).paramname = 'Value';
pt(143).class     = 'scalar';
pt(143).nrows     = 1;
pt(143).ncols     = 1;
pt(143).subsource = 'SS_DOUBLE';

pt(144).blockname = 'Force Generator/LorentzForce/Lorentz2/timescale';
pt(144).paramname = 'Value';
pt(144).class     = 'scalar';
pt(144).nrows     = 1;
pt(144).ncols     = 1;
pt(144).subsource = 'SS_DOUBLE';

pt(145).blockname = 'Force Generator/LorentzForce/Lorentz2/x';
pt(145).paramname = 'X0';
pt(145).class     = 'scalar';
pt(145).nrows     = 1;
pt(145).ncols     = 1;
pt(145).subsource = 'SS_DOUBLE';

pt(146).blockname = 'Force Generator/LorentzForce/Lorentz2/y';
pt(146).paramname = 'X0';
pt(146).class     = 'scalar';
pt(146).nrows     = 1;
pt(146).ncols     = 1;
pt(146).subsource = 'SS_DOUBLE';

pt(147).blockname = 'Force Generator/LorentzForce/Lorentz2/z';
pt(147).paramname = 'X0';
pt(147).class     = 'scalar';
pt(147).nrows     = 1;
pt(147).ncols     = 1;
pt(147).subsource = 'SS_DOUBLE';

pt(148).blockname = 'Force Generator/LorentzForce/Lorentz3/beta';
pt(148).paramname = 'Value';
pt(148).class     = 'scalar';
pt(148).nrows     = 1;
pt(148).ncols     = 1;
pt(148).subsource = 'SS_DOUBLE';

pt(149).blockname = 'Force Generator/LorentzForce/Lorentz3/rho';
pt(149).paramname = 'Value';
pt(149).class     = 'scalar';
pt(149).nrows     = 1;
pt(149).ncols     = 1;
pt(149).subsource = 'SS_DOUBLE';

pt(150).blockname = 'Force Generator/LorentzForce/Lorentz3/sigma';
pt(150).paramname = 'Value';
pt(150).class     = 'scalar';
pt(150).nrows     = 1;
pt(150).ncols     = 1;
pt(150).subsource = 'SS_DOUBLE';

pt(151).blockname = 'Force Generator/LorentzForce/Lorentz3/timescale';
pt(151).paramname = 'Value';
pt(151).class     = 'scalar';
pt(151).nrows     = 1;
pt(151).ncols     = 1;
pt(151).subsource = 'SS_DOUBLE';

pt(152).blockname = 'Force Generator/LorentzForce/Lorentz3/x';
pt(152).paramname = 'X0';
pt(152).class     = 'scalar';
pt(152).nrows     = 1;
pt(152).ncols     = 1;
pt(152).subsource = 'SS_DOUBLE';

pt(153).blockname = 'Force Generator/LorentzForce/Lorentz3/y';
pt(153).paramname = 'X0';
pt(153).class     = 'scalar';
pt(153).nrows     = 1;
pt(153).ncols     = 1;
pt(153).subsource = 'SS_DOUBLE';

pt(154).blockname = 'Force Generator/LorentzForce/Lorentz3/z';
pt(154).paramname = 'X0';
pt(154).class     = 'scalar';
pt(154).nrows     = 1;
pt(154).ncols     = 1;
pt(154).subsource = 'SS_DOUBLE';

pt(155).blockname = 'Force outside box/In Center/Compare To Constant/Constant';
pt(155).paramname = 'Value';
pt(155).class     = 'scalar';
pt(155).nrows     = 1;
pt(155).ncols     = 1;
pt(155).subsource = 'SS_DOUBLE';

pt(156).blockname = 'Force outside box/In Center/Compare To Constant1/Constant';
pt(156).paramname = 'Value';
pt(156).class     = 'scalar';
pt(156).nrows     = 1;
pt(156).ncols     = 1;
pt(156).subsource = 'SS_DOUBLE';

pt(157).blockname = 'Force outside box/In Center/Compare To Constant2/Constant';
pt(157).paramname = 'Value';
pt(157).class     = 'scalar';
pt(157).nrows     = 1;
pt(157).ncols     = 1;
pt(157).subsource = 'SS_DOUBLE';

pt(158).blockname = 'Force outside box/In Center/Compare To Constant3/Constant';
pt(158).paramname = 'Value';
pt(158).class     = 'scalar';
pt(158).nrows     = 1;
pt(158).ncols     = 1;
pt(158).subsource = 'SS_DOUBLE';

pt(159).blockname = 'Force outside box/Timer/Detect Fall Nonpositive/Delay Input1';
pt(159).paramname = 'X0';
pt(159).class     = 'scalar';
pt(159).nrows     = 1;
pt(159).ncols     = 1;
pt(159).subsource = 'SS_UINT8';

pt(160).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant';
pt(160).paramname = 'Value';
pt(160).class     = 'scalar';
pt(160).nrows     = 1;
pt(160).ncols     = 1;
pt(160).subsource = 'SS_DOUBLE';

pt(161).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Constant1';
pt(161).paramname = 'Value';
pt(161).class     = 'scalar';
pt(161).nrows     = 1;
pt(161).ncols     = 1;
pt(161).subsource = 'SS_DOUBLE';

pt(162).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/ScaleTouSec';
pt(162).paramname = 'Gain';
pt(162).class     = 'scalar';
pt(162).nrows     = 1;
pt(162).ncols     = 1;
pt(162).subsource = 'SS_DOUBLE';

pt(163).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ';
pt(163).paramname = 'P1';
pt(163).class     = 'vector';
pt(163).nrows     = 1;
pt(163).ncols     = 2;
pt(163).subsource = 'SS_DOUBLE';

pt(164).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ';
pt(164).paramname = 'P2';
pt(164).class     = 'vector';
pt(164).nrows     = 1;
pt(164).ncols     = 2;
pt(164).subsource = 'SS_DOUBLE';

pt(165).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ';
pt(165).paramname = 'P3';
pt(165).class     = 'vector';
pt(165).nrows     = 1;
pt(165).ncols     = 2;
pt(165).subsource = 'SS_DOUBLE';

pt(166).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ';
pt(166).paramname = 'P4';
pt(166).class     = 'scalar';
pt(166).nrows     = 1;
pt(166).ncols     = 1;
pt(166).subsource = 'SS_DOUBLE';

pt(167).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ';
pt(167).paramname = 'P5';
pt(167).class     = 'vector';
pt(167).nrows     = 1;
pt(167).ncols     = 2;
pt(167).subsource = 'SS_DOUBLE';

pt(168).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ';
pt(168).paramname = 'P6';
pt(168).class     = 'scalar';
pt(168).nrows     = 1;
pt(168).ncols     = 1;
pt(168).subsource = 'SS_DOUBLE';

pt(169).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/PCI-6025E ';
pt(169).paramname = 'P7';
pt(169).class     = 'scalar';
pt(169).nrows     = 1;
pt(169).ncols     = 1;
pt(169).subsource = 'SS_DOUBLE';

pt(170).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ';
pt(170).paramname = 'P1';
pt(170).class     = 'scalar';
pt(170).nrows     = 1;
pt(170).ncols     = 1;
pt(170).subsource = 'SS_DOUBLE';

pt(171).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/xPC Target  Time ';
pt(171).paramname = 'P2';
pt(171).class     = 'scalar';
pt(171).nrows     = 1;
pt(171).ncols     = 1;
pt(171).subsource = 'SS_DOUBLE';

pt(172).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant/Constant';
pt(172).paramname = 'Value';
pt(172).class     = 'scalar';
pt(172).nrows     = 1;
pt(172).ncols     = 1;
pt(172).subsource = 'SS_DOUBLE';

pt(173).blockname = 'XY Position Subsystem/For Iterator Subsystem/While Iterator Subsystem/Compare To Constant1/Constant';
pt(173).paramname = 'Value';
pt(173).class     = 'scalar';
pt(173).nrows     = 1;
pt(173).ncols     = 1;
pt(173).subsource = 'SS_DOUBLE';

function len = getlenPT
len = 173;

