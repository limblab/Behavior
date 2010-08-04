  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (bump_choice_P)
    ;%
      section.nData     = 316;
      section.data(316)  = dumData; %prealloc
      
	  ;% bump_choice_P.Time_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_P.PCIQUAD04_P1_Size
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bump_choice_P.PCIQUAD04_P1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% bump_choice_P.PCIQUAD04_P2_Size
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% bump_choice_P.PCIQUAD04_P2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% bump_choice_P.PCIQUAD04_P3_Size
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% bump_choice_P.PCIQUAD04_P3
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% bump_choice_P.PCIQUAD04_P4_Size
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% bump_choice_P.PCIQUAD04_P4
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% bump_choice_P.PCIQUAD04_P5_Size
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% bump_choice_P.PCIQUAD04_P5
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% bump_choice_P.PCIQUAD04_P6_Size
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% bump_choice_P.PCIQUAD04_P6
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% bump_choice_P.PCIQUAD04_P7_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% bump_choice_P.PCIQUAD04_P7
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% bump_choice_P.PCIQUAD04_P8_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% bump_choice_P.PCIQUAD04_P8
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% bump_choice_P.PCIQUAD04_P9_Size
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 25;
	
	  ;% bump_choice_P.PCIQUAD04_P9
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 27;
	
	  ;% bump_choice_P.PCIQUAD04_P10_Size
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 28;
	
	  ;% bump_choice_P.PCIQUAD04_P10
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 30;
	
	  ;% bump_choice_P.PCIQUAD04_P11_Size
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 31;
	
	  ;% bump_choice_P.PCIQUAD04_P11
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 33;
	
	  ;% bump_choice_P.Gain_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 34;
	
	  ;% bump_choice_P.shoulderOffset_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 35;
	
	  ;% bump_choice_P.L1_Value
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 36;
	
	  ;% bump_choice_P.Gain_Gain_a
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 37;
	
	  ;% bump_choice_P.PCIQUAD041_P1_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 38;
	
	  ;% bump_choice_P.PCIQUAD041_P1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 40;
	
	  ;% bump_choice_P.PCIQUAD041_P2_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 41;
	
	  ;% bump_choice_P.PCIQUAD041_P2
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 43;
	
	  ;% bump_choice_P.PCIQUAD041_P3_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 44;
	
	  ;% bump_choice_P.PCIQUAD041_P3
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 46;
	
	  ;% bump_choice_P.PCIQUAD041_P4_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 47;
	
	  ;% bump_choice_P.PCIQUAD041_P4
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 49;
	
	  ;% bump_choice_P.PCIQUAD041_P5_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 50;
	
	  ;% bump_choice_P.PCIQUAD041_P5
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 52;
	
	  ;% bump_choice_P.PCIQUAD041_P6_Size
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 53;
	
	  ;% bump_choice_P.PCIQUAD041_P6
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 55;
	
	  ;% bump_choice_P.PCIQUAD041_P7_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 56;
	
	  ;% bump_choice_P.PCIQUAD041_P7
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 58;
	
	  ;% bump_choice_P.PCIQUAD041_P8_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 59;
	
	  ;% bump_choice_P.PCIQUAD041_P8
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 61;
	
	  ;% bump_choice_P.PCIQUAD041_P9_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 62;
	
	  ;% bump_choice_P.PCIQUAD041_P9
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 64;
	
	  ;% bump_choice_P.PCIQUAD041_P10_Size
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 65;
	
	  ;% bump_choice_P.PCIQUAD041_P10
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 67;
	
	  ;% bump_choice_P.PCIQUAD041_P11_Size
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 68;
	
	  ;% bump_choice_P.PCIQUAD041_P11
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 70;
	
	  ;% bump_choice_P.Gain1_Gain
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 71;
	
	  ;% bump_choice_P.elbowOffset_Value
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 72;
	
	  ;% bump_choice_P.L2_Value
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 73;
	
	  ;% bump_choice_P.Gain1_Gain_m
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 74;
	
	  ;% bump_choice_P.Gain2_Gain
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 75;
	
	  ;% bump_choice_P.PCI6025EAD_P1_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 76;
	
	  ;% bump_choice_P.PCI6025EAD_P1
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 78;
	
	  ;% bump_choice_P.PCI6025EAD_P2_Size
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 80;
	
	  ;% bump_choice_P.PCI6025EAD_P2
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 82;
	
	  ;% bump_choice_P.PCI6025EAD_P3_Size
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 84;
	
	  ;% bump_choice_P.PCI6025EAD_P3
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 86;
	
	  ;% bump_choice_P.PCI6025EAD_P4_Size
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 88;
	
	  ;% bump_choice_P.PCI6025EAD_P4
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 90;
	
	  ;% bump_choice_P.PCI6025EAD_P5_Size
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 91;
	
	  ;% bump_choice_P.PCI6025EAD_P5
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 93;
	
	  ;% bump_choice_P.PCI6025EAD_P6_Size
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 94;
	
	  ;% bump_choice_P.PCI6025EAD_P6
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 96;
	
	  ;% bump_choice_P.UseTachs_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 97;
	
	  ;% bump_choice_P.yoffset_Value
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 98;
	
	  ;% bump_choice_P.xoffset_Value
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 99;
	
	  ;% bump_choice_P.AngleOffset_Value
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 100;
	
	  ;% bump_choice_P.DigitalFilter2_ICRTP
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 101;
	
	  ;% bump_choice_P.DigitalFilter2_RTP1COEFF
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 102;
	
	  ;% bump_choice_P.dG_Gain
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 113;
	
	  ;% bump_choice_P.DigitalFilter_ICRTP
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 114;
	
	  ;% bump_choice_P.DigitalFilter_RTP1COEFF
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 115;
	
	  ;% bump_choice_P.DigitalFilter2_ICRTP_i
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 126;
	
	  ;% bump_choice_P.DigitalFilter2_RTP1COEFF_g
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 127;
	
	  ;% bump_choice_P.dG_Gain_l
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 138;
	
	  ;% bump_choice_P.DigitalFilter_ICRTP_l
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 139;
	
	  ;% bump_choice_P.DigitalFilter_RTP1COEFF_a
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 140;
	
	  ;% bump_choice_P.Switch_Threshold
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 151;
	
	  ;% bump_choice_P.XLowLimit_Value
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 152;
	
	  ;% bump_choice_P.XHighLimit_Value
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 153;
	
	  ;% bump_choice_P.YHighLimit_Value
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 154;
	
	  ;% bump_choice_P.YLowLimit_Value
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 155;
	
	  ;% bump_choice_P.RecenterFlag_Value
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 156;
	
	  ;% bump_choice_P.Time_Value_p
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 157;
	
	  ;% bump_choice_P.Time_Value_c
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 158;
	
	  ;% bump_choice_P.Constant_Value
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 159;
	
	  ;% bump_choice_P.Constant_Value_o
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 160;
	
	  ;% bump_choice_P.Time_Value_o
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 161;
	
	  ;% bump_choice_P.Time_Value_h
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 162;
	
	  ;% bump_choice_P.Load_Value
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 163;
	
	  ;% bump_choice_P.x_X0
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 164;
	
	  ;% bump_choice_P.x_X0_p
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 165;
	
	  ;% bump_choice_P.x_X0_n
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 166;
	
	  ;% bump_choice_P.x_X0_pt
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 167;
	
	  ;% bump_choice_P.Load_Value_d
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 168;
	
	  ;% bump_choice_P.x_X0_i
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 169;
	
	  ;% bump_choice_P.x_X0_k
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 170;
	
	  ;% bump_choice_P.x_X0_nd
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 171;
	
	  ;% bump_choice_P.x_X0_a
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 172;
	
	  ;% bump_choice_P.BCStimTable_table
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 173;
	
	  ;% bump_choice_P.BehaviorBC_P1_Size
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 205;
	
	  ;% bump_choice_P.BehaviorBC_P1
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 207;
	
	  ;% bump_choice_P.BehaviorBC_P2_Size
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 208;
	
	  ;% bump_choice_P.BehaviorBC_P2
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 210;
	
	  ;% bump_choice_P.BehaviorBC_P3_Size
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 211;
	
	  ;% bump_choice_P.BehaviorBC_P3
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 213;
	
	  ;% bump_choice_P.BehaviorBC_P4_Size
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 214;
	
	  ;% bump_choice_P.BehaviorBC_P4
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 216;
	
	  ;% bump_choice_P.BehaviorBC_P5_Size
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 217;
	
	  ;% bump_choice_P.BehaviorBC_P5
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 219;
	
	  ;% bump_choice_P.BehaviorBC_P6_Size
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 220;
	
	  ;% bump_choice_P.BehaviorBC_P6
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 222;
	
	  ;% bump_choice_P.BehaviorBC_P7_Size
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 223;
	
	  ;% bump_choice_P.BehaviorBC_P7
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 225;
	
	  ;% bump_choice_P.BehaviorBC_P8_Size
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 226;
	
	  ;% bump_choice_P.BehaviorBC_P8
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 228;
	
	  ;% bump_choice_P.BehaviorBC_P9_Size
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 229;
	
	  ;% bump_choice_P.BehaviorBC_P9
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 231;
	
	  ;% bump_choice_P.BehaviorBC_P10_Size
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 232;
	
	  ;% bump_choice_P.BehaviorBC_P10
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 234;
	
	  ;% bump_choice_P.BehaviorBC_P11_Size
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 235;
	
	  ;% bump_choice_P.BehaviorBC_P11
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 237;
	
	  ;% bump_choice_P.BehaviorBC_P12_Size
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 238;
	
	  ;% bump_choice_P.BehaviorBC_P12
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 240;
	
	  ;% bump_choice_P.BehaviorBC_P13_Size
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 241;
	
	  ;% bump_choice_P.BehaviorBC_P13
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 243;
	
	  ;% bump_choice_P.BehaviorBC_P14_Size
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 244;
	
	  ;% bump_choice_P.BehaviorBC_P14
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 246;
	
	  ;% bump_choice_P.BehaviorBC_P15_Size
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 247;
	
	  ;% bump_choice_P.BehaviorBC_P15
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 249;
	
	  ;% bump_choice_P.BehaviorBC_P16_Size
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 250;
	
	  ;% bump_choice_P.BehaviorBC_P16
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 252;
	
	  ;% bump_choice_P.BehaviorBC_P17_Size
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 253;
	
	  ;% bump_choice_P.BehaviorBC_P17
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 255;
	
	  ;% bump_choice_P.MG1_Gain
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 256;
	
	  ;% bump_choice_P.MG2_Gain
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 257;
	
	  ;% bump_choice_P.PCI6025E_P1_Size
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 258;
	
	  ;% bump_choice_P.PCI6025E_P1
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 260;
	
	  ;% bump_choice_P.PCI6025E_P2_Size
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 262;
	
	  ;% bump_choice_P.PCI6025E_P2
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 264;
	
	  ;% bump_choice_P.PCI6025E_P3_Size
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 266;
	
	  ;% bump_choice_P.PCI6025E_P3
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 268;
	
	  ;% bump_choice_P.PCI6025E_P4_Size
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 270;
	
	  ;% bump_choice_P.PCI6025E_P4
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 272;
	
	  ;% bump_choice_P.PCI6025E_P5_Size
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 274;
	
	  ;% bump_choice_P.PCI6025E_P5
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 276;
	
	  ;% bump_choice_P.PCI6025E_P6_Size
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 277;
	
	  ;% bump_choice_P.PCI6025E_P6
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 279;
	
	  ;% bump_choice_P.PCI6025E_P7_Size
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 280;
	
	  ;% bump_choice_P.PCI6025E_P7
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 282;
	
	  ;% bump_choice_P.Constant_Value_j
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 283;
	
	  ;% bump_choice_P.Constant_Value_g
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 284;
	
	  ;% bump_choice_P.Constant_Value_d
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 285;
	
	  ;% bump_choice_P.Send_P1_Size
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 286;
	
	  ;% bump_choice_P.Send_P1
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 288;
	
	  ;% bump_choice_P.Send_P2_Size
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 299;
	
	  ;% bump_choice_P.Send_P2
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 301;
	
	  ;% bump_choice_P.Send_P3_Size
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 302;
	
	  ;% bump_choice_P.Send_P3
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 304;
	
	  ;% bump_choice_P.Send_P4_Size
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 305;
	
	  ;% bump_choice_P.Send_P4
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 307;
	
	  ;% bump_choice_P.UniformRandomNumber_Min
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 308;
	
	  ;% bump_choice_P.UniformRandomNumber_Max
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 309;
	
	  ;% bump_choice_P.UniformRandomNumber_Seed
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 310;
	
	  ;% bump_choice_P.JackpotChance_Value
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 311;
	
	  ;% bump_choice_P.y_X0
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 312;
	
	  ;% bump_choice_P.rho_Value
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 313;
	
	  ;% bump_choice_P.z_X0
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 314;
	
	  ;% bump_choice_P.beta_Value
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 315;
	
	  ;% bump_choice_P.timescale_Value
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 316;
	
	  ;% bump_choice_P.sigma_Value
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 317;
	
	  ;% bump_choice_P.y_X0_l
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 318;
	
	  ;% bump_choice_P.rho_Value_e
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 319;
	
	  ;% bump_choice_P.z_X0_b
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 320;
	
	  ;% bump_choice_P.beta_Value_a
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 321;
	
	  ;% bump_choice_P.timescale_Value_m
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 322;
	
	  ;% bump_choice_P.sigma_Value_g
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 323;
	
	  ;% bump_choice_P.y_X0_a
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 324;
	
	  ;% bump_choice_P.rho_Value_eb
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 325;
	
	  ;% bump_choice_P.z_X0_bn
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 326;
	
	  ;% bump_choice_P.beta_Value_l
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 327;
	
	  ;% bump_choice_P.timescale_Value_l
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 328;
	
	  ;% bump_choice_P.sigma_Value_j
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 329;
	
	  ;% bump_choice_P.y_X0_k
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 330;
	
	  ;% bump_choice_P.rho_Value_n
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 331;
	
	  ;% bump_choice_P.z_X0_i
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 332;
	
	  ;% bump_choice_P.beta_Value_c
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 333;
	
	  ;% bump_choice_P.timescale_Value_f
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 334;
	
	  ;% bump_choice_P.sigma_Value_jm
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 335;
	
	  ;% bump_choice_P.y_X0_i
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 336;
	
	  ;% bump_choice_P.rho_Value_f
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 337;
	
	  ;% bump_choice_P.z_X0_n
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 338;
	
	  ;% bump_choice_P.beta_Value_b
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 339;
	
	  ;% bump_choice_P.timescale_Value_mg
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 340;
	
	  ;% bump_choice_P.sigma_Value_m
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 341;
	
	  ;% bump_choice_P.y_X0_m
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 342;
	
	  ;% bump_choice_P.rho_Value_b
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 343;
	
	  ;% bump_choice_P.z_X0_a
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 344;
	
	  ;% bump_choice_P.beta_Value_m
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 345;
	
	  ;% bump_choice_P.timescale_Value_e
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 346;
	
	  ;% bump_choice_P.sigma_Value_j0
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 347;
	
	  ;% bump_choice_P.y_X0_p
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 348;
	
	  ;% bump_choice_P.rho_Value_h
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 349;
	
	  ;% bump_choice_P.z_X0_i4
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 350;
	
	  ;% bump_choice_P.beta_Value_n
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 351;
	
	  ;% bump_choice_P.timescale_Value_d
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 352;
	
	  ;% bump_choice_P.sigma_Value_c
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 353;
	
	  ;% bump_choice_P.y_X0_c
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 354;
	
	  ;% bump_choice_P.rho_Value_a
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 355;
	
	  ;% bump_choice_P.z_X0_f
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 356;
	
	  ;% bump_choice_P.beta_Value_g
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 357;
	
	  ;% bump_choice_P.timescale_Value_j
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 358;
	
	  ;% bump_choice_P.sigma_Value_l
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 359;
	
	  ;% bump_choice_P.Gain_Gain_m
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 360;
	
	  ;% bump_choice_P.visAngle_Value
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 361;
	
	  ;% bump_choice_P.DynamicAngle_Value
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 362;
	
	  ;% bump_choice_P.Inverter_Gain
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 363;
	
	  ;% bump_choice_P.Gain_Gain_ap
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 364;
	
	  ;% bump_choice_P.LorentzForceGain_Gain
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 365;
	
	  ;% bump_choice_P.staticX_Value
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 366;
	
	  ;% bump_choice_P.staticY_Value
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 367;
	
	  ;% bump_choice_P.Off_Value
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 368;
	
	  ;% bump_choice_P.Gain_Gain_b
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 369;
	
	  ;% bump_choice_P.visAngle_Value_n
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 370;
	
	  ;% bump_choice_P.DynamicAngle_Value_f
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 371;
	
	  ;% bump_choice_P.Inverter_Gain_j
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 372;
	
	  ;% bump_choice_P.Gain_Gain_by
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 373;
	
	  ;% bump_choice_P.LorentzForceGain_Gain_c
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 374;
	
	  ;% bump_choice_P.staticX_Value_h
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 375;
	
	  ;% bump_choice_P.staticY_Value_b
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 376;
	
	  ;% bump_choice_P.Off_Value_f
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 377;
	
	  ;% bump_choice_P.Gain1_Gain_j
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 378;
	
	  ;% bump_choice_P.Gain3_Gain
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 379;
	
	  ;% bump_choice_P.Saturation_UpperSat
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 380;
	
	  ;% bump_choice_P.Saturation_LowerSat
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 381;
	
	  ;% bump_choice_P.Gain4_Gain
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 382;
	
	  ;% bump_choice_P.Gain2_Gain_o
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 383;
	
	  ;% bump_choice_P.Saturation1_UpperSat
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 384;
	
	  ;% bump_choice_P.Saturation1_LowerSat
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 385;
	
	  ;% bump_choice_P.BoundingBoxViscosity_Gain
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 386;
	
	  ;% bump_choice_P.zeroX_Value
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 387;
	
	  ;% bump_choice_P.zeroY_Value
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 388;
	
	  ;% bump_choice_P.Gain_Gain_j
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 389;
	
	  ;% bump_choice_P.RewardJackpot_Value
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 390;
	
	  ;% bump_choice_P.RewardTime_Value
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 391;
	
	  ;% bump_choice_P.TachGain2_Gain
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 392;
	
	  ;% bump_choice_P.TachGain1_Gain
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 393;
	
	  ;% bump_choice_P.Constant2_Value
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 394;
	
	  ;% bump_choice_P.Constant1_Value
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 395;
	
	  ;% bump_choice_P.Constant_Value_h
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 396;
	
	  ;% bump_choice_P.xPCTargetTime_P1_Size
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 397;
	
	  ;% bump_choice_P.xPCTargetTime_P1
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 399;
	
	  ;% bump_choice_P.xPCTargetTime_P2_Size
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 400;
	
	  ;% bump_choice_P.xPCTargetTime_P2
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 402;
	
	  ;% bump_choice_P.ScaleTouSec_Gain
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 403;
	
	  ;% bump_choice_P.Constant_Value_b
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 404;
	
	  ;% bump_choice_P.PCI6025E_P1_Size_g
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 405;
	
	  ;% bump_choice_P.PCI6025E_P1_d
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 407;
	
	  ;% bump_choice_P.PCI6025E_P2_Size_j
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 409;
	
	  ;% bump_choice_P.PCI6025E_P2_k
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 411;
	
	  ;% bump_choice_P.PCI6025E_P3_Size_i
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 413;
	
	  ;% bump_choice_P.PCI6025E_P3_l
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 415;
	
	  ;% bump_choice_P.PCI6025E_P4_Size_j
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 417;
	
	  ;% bump_choice_P.PCI6025E_P4_o
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 419;
	
	  ;% bump_choice_P.PCI6025E_P5_Size_h
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 420;
	
	  ;% bump_choice_P.PCI6025E_P5_m
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 422;
	
	  ;% bump_choice_P.PCI6025E_P6_Size_c
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 423;
	
	  ;% bump_choice_P.PCI6025E_P6_f
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 425;
	
	  ;% bump_choice_P.PCI6025E_P7_Size_i
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 426;
	
	  ;% bump_choice_P.PCI6025E_P7_f
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 428;
	
	  ;% bump_choice_P.Constant_Value_jz
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 429;
	
	  ;% bump_choice_P.Switch_Threshold_k
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 430;
	
	  ;% bump_choice_P.PortA_P1_Size
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 431;
	
	  ;% bump_choice_P.PortA_P1
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 433;
	
	  ;% bump_choice_P.PortA_P2_Size
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 441;
	
	  ;% bump_choice_P.PortA_P2
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 443;
	
	  ;% bump_choice_P.PortA_P3_Size
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 444;
	
	  ;% bump_choice_P.PortA_P3
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 446;
	
	  ;% bump_choice_P.PortA_P4_Size
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 454;
	
	  ;% bump_choice_P.PortA_P4
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 456;
	
	  ;% bump_choice_P.PortA_P5_Size
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 464;
	
	  ;% bump_choice_P.PortA_P5
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 466;
	
	  ;% bump_choice_P.PortA_P6_Size
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 467;
	
	  ;% bump_choice_P.PortA_P6
	  section.data(287).logicalSrcIdx = 286;
	  section.data(287).dtTransOffset = 469;
	
	  ;% bump_choice_P.PortA_P7_Size
	  section.data(288).logicalSrcIdx = 287;
	  section.data(288).dtTransOffset = 470;
	
	  ;% bump_choice_P.PortA_P7
	  section.data(289).logicalSrcIdx = 288;
	  section.data(289).dtTransOffset = 472;
	
	  ;% bump_choice_P.PortA_P8_Size
	  section.data(290).logicalSrcIdx = 289;
	  section.data(290).dtTransOffset = 473;
	
	  ;% bump_choice_P.PortA_P8
	  section.data(291).logicalSrcIdx = 290;
	  section.data(291).dtTransOffset = 475;
	
	  ;% bump_choice_P.PortA_P9_Size
	  section.data(292).logicalSrcIdx = 291;
	  section.data(292).dtTransOffset = 476;
	
	  ;% bump_choice_P.PortA_P9
	  section.data(293).logicalSrcIdx = 292;
	  section.data(293).dtTransOffset = 478;
	
	  ;% bump_choice_P.Constant_Value_m
	  section.data(294).logicalSrcIdx = 293;
	  section.data(294).dtTransOffset = 479;
	
	  ;% bump_choice_P.PortB_P1_Size
	  section.data(295).logicalSrcIdx = 294;
	  section.data(295).dtTransOffset = 480;
	
	  ;% bump_choice_P.PortB_P1
	  section.data(296).logicalSrcIdx = 295;
	  section.data(296).dtTransOffset = 482;
	
	  ;% bump_choice_P.PortB_P2_Size
	  section.data(297).logicalSrcIdx = 296;
	  section.data(297).dtTransOffset = 490;
	
	  ;% bump_choice_P.PortB_P2
	  section.data(298).logicalSrcIdx = 297;
	  section.data(298).dtTransOffset = 492;
	
	  ;% bump_choice_P.PortB_P3_Size
	  section.data(299).logicalSrcIdx = 298;
	  section.data(299).dtTransOffset = 493;
	
	  ;% bump_choice_P.PortB_P3
	  section.data(300).logicalSrcIdx = 299;
	  section.data(300).dtTransOffset = 495;
	
	  ;% bump_choice_P.PortB_P4_Size
	  section.data(301).logicalSrcIdx = 300;
	  section.data(301).dtTransOffset = 503;
	
	  ;% bump_choice_P.PortB_P4
	  section.data(302).logicalSrcIdx = 301;
	  section.data(302).dtTransOffset = 505;
	
	  ;% bump_choice_P.PortB_P5_Size
	  section.data(303).logicalSrcIdx = 302;
	  section.data(303).dtTransOffset = 513;
	
	  ;% bump_choice_P.PortB_P5
	  section.data(304).logicalSrcIdx = 303;
	  section.data(304).dtTransOffset = 515;
	
	  ;% bump_choice_P.PortB_P6_Size
	  section.data(305).logicalSrcIdx = 304;
	  section.data(305).dtTransOffset = 516;
	
	  ;% bump_choice_P.PortB_P6
	  section.data(306).logicalSrcIdx = 305;
	  section.data(306).dtTransOffset = 518;
	
	  ;% bump_choice_P.PortB_P7_Size
	  section.data(307).logicalSrcIdx = 306;
	  section.data(307).dtTransOffset = 519;
	
	  ;% bump_choice_P.PortB_P7
	  section.data(308).logicalSrcIdx = 307;
	  section.data(308).dtTransOffset = 521;
	
	  ;% bump_choice_P.PortB_P8_Size
	  section.data(309).logicalSrcIdx = 308;
	  section.data(309).dtTransOffset = 522;
	
	  ;% bump_choice_P.PortB_P8
	  section.data(310).logicalSrcIdx = 309;
	  section.data(310).dtTransOffset = 524;
	
	  ;% bump_choice_P.PortB_P9_Size
	  section.data(311).logicalSrcIdx = 310;
	  section.data(311).dtTransOffset = 525;
	
	  ;% bump_choice_P.PortB_P9
	  section.data(312).logicalSrcIdx = 311;
	  section.data(312).dtTransOffset = 527;
	
	  ;% bump_choice_P.xPCTargetTime_P1_Size_l
	  section.data(313).logicalSrcIdx = 312;
	  section.data(313).dtTransOffset = 528;
	
	  ;% bump_choice_P.xPCTargetTime_P1_h
	  section.data(314).logicalSrcIdx = 313;
	  section.data(314).dtTransOffset = 530;
	
	  ;% bump_choice_P.xPCTargetTime_P2_Size_c
	  section.data(315).logicalSrcIdx = 314;
	  section.data(315).dtTransOffset = 531;
	
	  ;% bump_choice_P.xPCTargetTime_P2_g
	  section.data(316).logicalSrcIdx = 315;
	  section.data(316).dtTransOffset = 533;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% bump_choice_P.PacketSpec_Value
	  section.data(1).logicalSrcIdx = 316;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_P.NaNupperbytes_Value
	  section.data(2).logicalSrcIdx = 317;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% bump_choice_P.DelayInput1_X0
	  section.data(1).logicalSrcIdx = 318;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_P.DelayInput1_X0_n
	  section.data(2).logicalSrcIdx = 319;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bump_choice_P.DelayInput1_X0_m
	  section.data(3).logicalSrcIdx = 320;
	  section.data(3).dtTransOffset = 2;
	
	  ;% bump_choice_P.DelayInput1_X0_o
	  section.data(4).logicalSrcIdx = 321;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% bump_choice_P.Memory_X0
	  section.data(1).logicalSrcIdx = 322;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_P.Memory_X0_l
	  section.data(2).logicalSrcIdx = 323;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bump_choice_P.Memory_X0_p
	  section.data(3).logicalSrcIdx = 324;
	  section.data(3).dtTransOffset = 2;
	
	  ;% bump_choice_P.Memory_X0_d
	  section.data(4).logicalSrcIdx = 325;
	  section.data(4).dtTransOffset = 3;
	
	  ;% bump_choice_P.Memory_X0_k
	  section.data(5).logicalSrcIdx = 326;
	  section.data(5).dtTransOffset = 4;
	
	  ;% bump_choice_P.Memory_X0_e
	  section.data(6).logicalSrcIdx = 327;
	  section.data(6).dtTransOffset = 5;
	
	  ;% bump_choice_P.Memory_X0_c
	  section.data(7).logicalSrcIdx = 328;
	  section.data(7).dtTransOffset = 6;
	
	  ;% bump_choice_P.Logic_table
	  section.data(8).logicalSrcIdx = 329;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_P.SampleandHold._Y0
	  section.data(1).logicalSrcIdx = 330;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_P.SampleandHold_h._Y0
	  section.data(1).logicalSrcIdx = 331;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (bump_choice_B)
    ;%
      section.nData     = 284;
      section.data(284)  = dumData; %prealloc
      
	  ;% bump_choice_B.Clock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_B.Sum
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bump_choice_B.PCIQUAD04
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% bump_choice_B.Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% bump_choice_B.Sum3
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% bump_choice_B.TrigonometricFunction
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% bump_choice_B.Product
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% bump_choice_B.TrigonometricFunction1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% bump_choice_B.Product1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% bump_choice_B.PCIQUAD041
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% bump_choice_B.Gain1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% bump_choice_B.Sum1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% bump_choice_B.TrigonometricFunction2
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% bump_choice_B.Product2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% bump_choice_B.TrigonometricFunction3
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% bump_choice_B.Product3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% bump_choice_B.MatrixConcatenate2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% bump_choice_B.PCI6025EAD_o1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 20;
	
	  ;% bump_choice_B.PCI6025EAD_o2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% bump_choice_B.Sum2
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% bump_choice_B.Sum4
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% bump_choice_B.Sum3_o
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% bump_choice_B.Sum1_k
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% bump_choice_B.TrigonometricFunction1_o
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% bump_choice_B.Sum_c
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 27;
	
	  ;% bump_choice_B.TrigonometricFunction2_l
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 28;
	
	  ;% bump_choice_B.sqrtu1u1u2u2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 29;
	
	  ;% bump_choice_B.Product1_b
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 30;
	
	  ;% bump_choice_B.DigitalFilter2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 31;
	
	  ;% bump_choice_B.Derivative
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 32;
	
	  ;% bump_choice_B.dG
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 33;
	
	  ;% bump_choice_B.DigitalFilter
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 34;
	
	  ;% bump_choice_B.TrigonometricFunction_d
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 35;
	
	  ;% bump_choice_B.Product_f
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 36;
	
	  ;% bump_choice_B.DigitalFilter2_c
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 37;
	
	  ;% bump_choice_B.Derivative_i
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 38;
	
	  ;% bump_choice_B.dG_c
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 39;
	
	  ;% bump_choice_B.DigitalFilter_k
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 40;
	
	  ;% bump_choice_B.Switch
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 41;
	
	  ;% bump_choice_B.Clock_k
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 43;
	
	  ;% bump_choice_B.Clock_h
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 44;
	
	  ;% bump_choice_B.Sum_n
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 45;
	
	  ;% bump_choice_B.Sum_l
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 46;
	
	  ;% bump_choice_B.Abs2
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 47;
	
	  ;% bump_choice_B.Abs3
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 48;
	
	  ;% bump_choice_B.Clock_p
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 49;
	
	  ;% bump_choice_B.Sum_h
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 50;
	
	  ;% bump_choice_B.Clock_d
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 51;
	
	  ;% bump_choice_B.Sum_hb
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 52;
	
	  ;% bump_choice_B.x
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 53;
	
	  ;% bump_choice_B.x_e
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 54;
	
	  ;% bump_choice_B.Add
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 55;
	
	  ;% bump_choice_B.x_et
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 56;
	
	  ;% bump_choice_B.x_d
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 57;
	
	  ;% bump_choice_B.MultiportSwitch
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 58;
	
	  ;% bump_choice_B.x_b
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 60;
	
	  ;% bump_choice_B.x_c
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 61;
	
	  ;% bump_choice_B.Add_k
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 62;
	
	  ;% bump_choice_B.x_j
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 63;
	
	  ;% bump_choice_B.x_h
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 64;
	
	  ;% bump_choice_B.LoadSelectSwitch
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 65;
	
	  ;% bump_choice_B.BCStimTable
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 67;
	
	  ;% bump_choice_B.Reshape
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 99;
	
	  ;% bump_choice_B.BehaviorBC_o1
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 131;
	
	  ;% bump_choice_B.BehaviorBC_o2
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 133;
	
	  ;% bump_choice_B.BehaviorBC_o3
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 138;
	
	  ;% bump_choice_B.BehaviorBC_o4
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 139;
	
	  ;% bump_choice_B.BehaviorBC_o5
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 154;
	
	  ;% bump_choice_B.BehaviorBC_o6
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 155;
	
	  ;% bump_choice_B.BehaviorBC_o7
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 157;
	
	  ;% bump_choice_B.BehaviorBC_o8
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 161;
	
	  ;% bump_choice_B.Switch2
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 163;
	
	  ;% bump_choice_B.MG1
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 165;
	
	  ;% bump_choice_B.MG2
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 166;
	
	  ;% bump_choice_B.Clock_o
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 167;
	
	  ;% bump_choice_B.HiddenBuf_InsertedFor_Sampleand
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 168;
	
	  ;% bump_choice_B.Sum_p
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 169;
	
	  ;% bump_choice_B.UniformRandomNumber
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 170;
	
	  ;% bump_choice_B.Switch_o
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 171;
	
	  ;% bump_choice_B.HiddenBuf_InsertedFor_Samplea_e
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 172;
	
	  ;% bump_choice_B.DataTypeConversion
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 173;
	
	  ;% bump_choice_B.y
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 174;
	
	  ;% bump_choice_B.Add1
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 175;
	
	  ;% bump_choice_B.z
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 176;
	
	  ;% bump_choice_B.Add3
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 177;
	
	  ;% bump_choice_B.product2
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 178;
	
	  ;% bump_choice_B.Add2
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 179;
	
	  ;% bump_choice_B.product3
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 180;
	
	  ;% bump_choice_B.product4
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 181;
	
	  ;% bump_choice_B.Add4
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 182;
	
	  ;% bump_choice_B.product1
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 183;
	
	  ;% bump_choice_B.dX
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 184;
	
	  ;% bump_choice_B.AddX
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 185;
	
	  ;% bump_choice_B.dY
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 186;
	
	  ;% bump_choice_B.AddX1
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 187;
	
	  ;% bump_choice_B.dZ
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 188;
	
	  ;% bump_choice_B.AddX2
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 189;
	
	  ;% bump_choice_B.y_d
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 190;
	
	  ;% bump_choice_B.Add1_l
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 191;
	
	  ;% bump_choice_B.z_i
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 192;
	
	  ;% bump_choice_B.Add3_j
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 193;
	
	  ;% bump_choice_B.product2_a
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 194;
	
	  ;% bump_choice_B.Add2_p
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 195;
	
	  ;% bump_choice_B.product3_h
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 196;
	
	  ;% bump_choice_B.product4_e
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 197;
	
	  ;% bump_choice_B.Add4_c
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 198;
	
	  ;% bump_choice_B.product1_b
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 199;
	
	  ;% bump_choice_B.dX_c
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 200;
	
	  ;% bump_choice_B.AddX_h
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 201;
	
	  ;% bump_choice_B.dY_d
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 202;
	
	  ;% bump_choice_B.AddX1_b
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 203;
	
	  ;% bump_choice_B.dZ_f
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 204;
	
	  ;% bump_choice_B.AddX2_d
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 205;
	
	  ;% bump_choice_B.y_a
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 206;
	
	  ;% bump_choice_B.Add1_g
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 207;
	
	  ;% bump_choice_B.z_g
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 208;
	
	  ;% bump_choice_B.Add3_o
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 209;
	
	  ;% bump_choice_B.product2_c
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 210;
	
	  ;% bump_choice_B.Add2_f
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 211;
	
	  ;% bump_choice_B.product3_p
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 212;
	
	  ;% bump_choice_B.product4_g
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 213;
	
	  ;% bump_choice_B.Add4_g
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 214;
	
	  ;% bump_choice_B.product1_g
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 215;
	
	  ;% bump_choice_B.dX_k
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 216;
	
	  ;% bump_choice_B.AddX_n
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 217;
	
	  ;% bump_choice_B.dY_l
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 218;
	
	  ;% bump_choice_B.AddX1_a
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 219;
	
	  ;% bump_choice_B.dZ_o
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 220;
	
	  ;% bump_choice_B.AddX2_e
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 221;
	
	  ;% bump_choice_B.y_k
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 222;
	
	  ;% bump_choice_B.Add1_e
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 223;
	
	  ;% bump_choice_B.z_j
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 224;
	
	  ;% bump_choice_B.Add3_m
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 225;
	
	  ;% bump_choice_B.product2_l
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 226;
	
	  ;% bump_choice_B.Add2_o
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 227;
	
	  ;% bump_choice_B.product3_d
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 228;
	
	  ;% bump_choice_B.product4_f
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 229;
	
	  ;% bump_choice_B.Add4_j
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 230;
	
	  ;% bump_choice_B.product1_l
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 231;
	
	  ;% bump_choice_B.dX_m
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 232;
	
	  ;% bump_choice_B.AddX_j
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 233;
	
	  ;% bump_choice_B.dY_b
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 234;
	
	  ;% bump_choice_B.AddX1_d
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 235;
	
	  ;% bump_choice_B.dZ_m
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 236;
	
	  ;% bump_choice_B.AddX2_eh
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 237;
	
	  ;% bump_choice_B.y_p
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 238;
	
	  ;% bump_choice_B.Add1_gp
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 239;
	
	  ;% bump_choice_B.z_o
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 240;
	
	  ;% bump_choice_B.Add3_g
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 241;
	
	  ;% bump_choice_B.product2_j
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 242;
	
	  ;% bump_choice_B.Add2_k
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 243;
	
	  ;% bump_choice_B.product3_j
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 244;
	
	  ;% bump_choice_B.product4_p
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 245;
	
	  ;% bump_choice_B.Add4_o
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 246;
	
	  ;% bump_choice_B.product1_a
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 247;
	
	  ;% bump_choice_B.dX_b
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 248;
	
	  ;% bump_choice_B.AddX_m
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 249;
	
	  ;% bump_choice_B.dY_l3
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 250;
	
	  ;% bump_choice_B.AddX1_l
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 251;
	
	  ;% bump_choice_B.dZ_l
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 252;
	
	  ;% bump_choice_B.AddX2_l
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 253;
	
	  ;% bump_choice_B.y_am
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 254;
	
	  ;% bump_choice_B.Add1_h
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 255;
	
	  ;% bump_choice_B.z_e
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 256;
	
	  ;% bump_choice_B.Add3_f
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 257;
	
	  ;% bump_choice_B.product2_n
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 258;
	
	  ;% bump_choice_B.Add2_c
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 259;
	
	  ;% bump_choice_B.product3_ho
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 260;
	
	  ;% bump_choice_B.product4_p1
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 261;
	
	  ;% bump_choice_B.Add4_e
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 262;
	
	  ;% bump_choice_B.product1_e
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 263;
	
	  ;% bump_choice_B.dX_h
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 264;
	
	  ;% bump_choice_B.AddX_i
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 265;
	
	  ;% bump_choice_B.dY_d5
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 266;
	
	  ;% bump_choice_B.AddX1_bb
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 267;
	
	  ;% bump_choice_B.dZ_c
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 268;
	
	  ;% bump_choice_B.AddX2_ec
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 269;
	
	  ;% bump_choice_B.y_kr
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 270;
	
	  ;% bump_choice_B.Add1_lc
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 271;
	
	  ;% bump_choice_B.z_n
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 272;
	
	  ;% bump_choice_B.Add3_p
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 273;
	
	  ;% bump_choice_B.product2_f
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 274;
	
	  ;% bump_choice_B.Add2_c5
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 275;
	
	  ;% bump_choice_B.product3_f
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 276;
	
	  ;% bump_choice_B.product4_et
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 277;
	
	  ;% bump_choice_B.Add4_ep
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 278;
	
	  ;% bump_choice_B.product1_f
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 279;
	
	  ;% bump_choice_B.dX_l
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 280;
	
	  ;% bump_choice_B.AddX_l
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 281;
	
	  ;% bump_choice_B.dY_n
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 282;
	
	  ;% bump_choice_B.AddX1_dm
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 283;
	
	  ;% bump_choice_B.dZ_p
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 284;
	
	  ;% bump_choice_B.AddX2_j
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 285;
	
	  ;% bump_choice_B.y_f
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 286;
	
	  ;% bump_choice_B.Add1_m
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 287;
	
	  ;% bump_choice_B.z_n3
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 288;
	
	  ;% bump_choice_B.Add3_k
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 289;
	
	  ;% bump_choice_B.product2_b
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 290;
	
	  ;% bump_choice_B.Add2_k3
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 291;
	
	  ;% bump_choice_B.product3_c
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 292;
	
	  ;% bump_choice_B.product4_eg
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 293;
	
	  ;% bump_choice_B.Add4_l
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 294;
	
	  ;% bump_choice_B.product1_p
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 295;
	
	  ;% bump_choice_B.dX_h4
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 296;
	
	  ;% bump_choice_B.AddX_c
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 297;
	
	  ;% bump_choice_B.dY_be
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 298;
	
	  ;% bump_choice_B.AddX1_c
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 299;
	
	  ;% bump_choice_B.dZ_ft
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 300;
	
	  ;% bump_choice_B.AddX2_c
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 301;
	
	  ;% bump_choice_B.MatrixConcatenation1
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 302;
	
	  ;% bump_choice_B.ForIterator
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 306;
	
	  ;% bump_choice_B.Switch_b
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 307;
	
	  ;% bump_choice_B.ToBits1_o1
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 308;
	
	  ;% bump_choice_B.ToBits1_o2
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 309;
	
	  ;% bump_choice_B.ToBits1_o3
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 310;
	
	  ;% bump_choice_B.ToBits1_o4
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 311;
	
	  ;% bump_choice_B.ToBits1_o5
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 312;
	
	  ;% bump_choice_B.ToBits1_o6
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 313;
	
	  ;% bump_choice_B.ToBits1_o7
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 314;
	
	  ;% bump_choice_B.ToBits1_o8
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 315;
	
	  ;% bump_choice_B.Add_ks
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 316;
	
	  ;% bump_choice_B.Add1_md
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 317;
	
	  ;% bump_choice_B.SerialConverter
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 318;
	
	  ;% bump_choice_B.ToBits_o1
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 319;
	
	  ;% bump_choice_B.ToBits_o2
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 320;
	
	  ;% bump_choice_B.ToBits_o3
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 321;
	
	  ;% bump_choice_B.ToBits_o4
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 322;
	
	  ;% bump_choice_B.ToBits_o5
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 323;
	
	  ;% bump_choice_B.ToBits_o6
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 324;
	
	  ;% bump_choice_B.ToBits_o7
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 325;
	
	  ;% bump_choice_B.ToBits_o8
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 326;
	
	  ;% bump_choice_B.xPCTargetTime
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 327;
	
	  ;% bump_choice_B.xPCTargetTime_b
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 328;
	
	  ;% bump_choice_B.Subtract
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 329;
	
	  ;% bump_choice_B.ScaleTouSec
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 330;
	
	  ;% bump_choice_B.Switch_n
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 331;
	
	  ;% bump_choice_B.TachGain2
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 332;
	
	  ;% bump_choice_B.TachGain1
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 333;
	
	  ;% bump_choice_B.TmpHiddenBufferAtMatrixMultiply
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 334;
	
	  ;% bump_choice_B.MatrixMultiply
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 336;
	
	  ;% bump_choice_B.Gain_i
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 338;
	
	  ;% bump_choice_B.MathFunction
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 340;
	
	  ;% bump_choice_B.MatrixMultiply_c
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 344;
	
	  ;% bump_choice_B.Switch1
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 346;
	
	  ;% bump_choice_B.Switch_j
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 348;
	
	  ;% bump_choice_B.BoundingBoxViscosity
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 350;
	
	  ;% bump_choice_B.Product_g
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 352;
	
	  ;% bump_choice_B.Gain1_n
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 353;
	
	  ;% bump_choice_B.Gain3
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 354;
	
	  ;% bump_choice_B.Add_i
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 355;
	
	  ;% bump_choice_B.Saturation
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 356;
	
	  ;% bump_choice_B.Gain4
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 357;
	
	  ;% bump_choice_B.Product1_o
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 358;
	
	  ;% bump_choice_B.Gain2
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 359;
	
	  ;% bump_choice_B.Add1_ef
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 360;
	
	  ;% bump_choice_B.Saturation1
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 361;
	
	  ;% bump_choice_B.Add1_f
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 362;
	
	  ;% bump_choice_B.LorentzForceGain
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 363;
	
	  ;% bump_choice_B.dynamicAngleSwitch
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 365;
	
	  ;% bump_choice_B.sin_h
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 366;
	
	  ;% bump_choice_B.Inverter
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 367;
	
	  ;% bump_choice_B.Product3_k
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 369;
	
	  ;% bump_choice_B.cos_c
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 370;
	
	  ;% bump_choice_B.Product2_l
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 371;
	
	  ;% bump_choice_B.Subtract_b
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 372;
	
	  ;% bump_choice_B.Product1_l
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 373;
	
	  ;% bump_choice_B.Product_a
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 374;
	
	  ;% bump_choice_B.Add_h
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 375;
	
	  ;% bump_choice_B.Gain_d
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 376;
	
	  ;% bump_choice_B.Gain_n
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 378;
	
	  ;% bump_choice_B.Add1_k
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 379;
	
	  ;% bump_choice_B.LorentzForceGain_p
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 380;
	
	  ;% bump_choice_B.DynamicAngleSwitch
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 382;
	
	  ;% bump_choice_B.sin_i
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 383;
	
	  ;% bump_choice_B.Inverter_k
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 384;
	
	  ;% bump_choice_B.Product3_h
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 386;
	
	  ;% bump_choice_B.cos_m
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 387;
	
	  ;% bump_choice_B.Product2_g
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 388;
	
	  ;% bump_choice_B.Subtract_e
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 389;
	
	  ;% bump_choice_B.Product1_p
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 390;
	
	  ;% bump_choice_B.Product_i
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 391;
	
	  ;% bump_choice_B.Add_ht
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 392;
	
	  ;% bump_choice_B.Gain_f
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 393;
	
	  ;% bump_choice_B.Gain_a
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 395;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% bump_choice_B.Compare
	  section.data(1).logicalSrcIdx = 284;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_B.Compare_a
	  section.data(2).logicalSrcIdx = 285;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bump_choice_B.Compare_e
	  section.data(3).logicalSrcIdx = 286;
	  section.data(3).dtTransOffset = 2;
	
	  ;% bump_choice_B.Compare_o
	  section.data(4).logicalSrcIdx = 287;
	  section.data(4).dtTransOffset = 3;
	
	  ;% bump_choice_B.Compare_k
	  section.data(5).logicalSrcIdx = 288;
	  section.data(5).dtTransOffset = 4;
	
	  ;% bump_choice_B.Uk1
	  section.data(6).logicalSrcIdx = 289;
	  section.data(6).dtTransOffset = 5;
	
	  ;% bump_choice_B.FixPtRelationalOperator
	  section.data(7).logicalSrcIdx = 290;
	  section.data(7).dtTransOffset = 6;
	
	  ;% bump_choice_B.Compare_h
	  section.data(8).logicalSrcIdx = 291;
	  section.data(8).dtTransOffset = 7;
	
	  ;% bump_choice_B.Compare_d
	  section.data(9).logicalSrcIdx = 292;
	  section.data(9).dtTransOffset = 8;
	
	  ;% bump_choice_B.Compare_dw
	  section.data(10).logicalSrcIdx = 293;
	  section.data(10).dtTransOffset = 9;
	
	  ;% bump_choice_B.Compare_do
	  section.data(11).logicalSrcIdx = 294;
	  section.data(11).dtTransOffset = 10;
	
	  ;% bump_choice_B.Uk1_c
	  section.data(12).logicalSrcIdx = 295;
	  section.data(12).dtTransOffset = 11;
	
	  ;% bump_choice_B.FixPtRelationalOperator_p
	  section.data(13).logicalSrcIdx = 296;
	  section.data(13).dtTransOffset = 12;
	
	  ;% bump_choice_B.Compare_l
	  section.data(14).logicalSrcIdx = 297;
	  section.data(14).dtTransOffset = 13;
	
	  ;% bump_choice_B.Compare_ez
	  section.data(15).logicalSrcIdx = 298;
	  section.data(15).dtTransOffset = 14;
	
	  ;% bump_choice_B.Uk1_j
	  section.data(16).logicalSrcIdx = 299;
	  section.data(16).dtTransOffset = 15;
	
	  ;% bump_choice_B.FixPtRelationalOperator_j
	  section.data(17).logicalSrcIdx = 300;
	  section.data(17).dtTransOffset = 16;
	
	  ;% bump_choice_B.Compare_n
	  section.data(18).logicalSrcIdx = 301;
	  section.data(18).dtTransOffset = 17;
	
	  ;% bump_choice_B.Compare_dc
	  section.data(19).logicalSrcIdx = 302;
	  section.data(19).dtTransOffset = 18;
	
	  ;% bump_choice_B.Uk1_m
	  section.data(20).logicalSrcIdx = 303;
	  section.data(20).dtTransOffset = 19;
	
	  ;% bump_choice_B.FixPtRelationalOperator_o
	  section.data(21).logicalSrcIdx = 304;
	  section.data(21).dtTransOffset = 20;
	
	  ;% bump_choice_B.Compare_p
	  section.data(22).logicalSrcIdx = 305;
	  section.data(22).dtTransOffset = 21;
	
	  ;% bump_choice_B.Compare_hq
	  section.data(23).logicalSrcIdx = 306;
	  section.data(23).dtTransOffset = 22;
	
	  ;% bump_choice_B.Pack
	  section.data(24).logicalSrcIdx = 307;
	  section.data(24).dtTransOffset = 23;
	
	  ;% bump_choice_B.RateTransition
	  section.data(25).logicalSrcIdx = 308;
	  section.data(25).dtTransOffset = 191;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 57;
      section.data(57)  = dumData; %prealloc
      
	  ;% bump_choice_B.Memory
	  section.data(1).logicalSrcIdx = 309;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_B.Memory_k
	  section.data(2).logicalSrcIdx = 310;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bump_choice_B.LogicalOperator2
	  section.data(3).logicalSrcIdx = 311;
	  section.data(3).dtTransOffset = 2;
	
	  ;% bump_choice_B.LogicalOperator1
	  section.data(4).logicalSrcIdx = 312;
	  section.data(4).dtTransOffset = 3;
	
	  ;% bump_choice_B.HiddenBuf_InsertedFor_EnabledSu
	  section.data(5).logicalSrcIdx = 313;
	  section.data(5).dtTransOffset = 4;
	
	  ;% bump_choice_B.RelationalOperator
	  section.data(6).logicalSrcIdx = 314;
	  section.data(6).dtTransOffset = 5;
	
	  ;% bump_choice_B.LogicalOperator
	  section.data(7).logicalSrcIdx = 315;
	  section.data(7).dtTransOffset = 6;
	
	  ;% bump_choice_B.Memory_b
	  section.data(8).logicalSrcIdx = 316;
	  section.data(8).dtTransOffset = 7;
	
	  ;% bump_choice_B.RelationalOperator_g
	  section.data(9).logicalSrcIdx = 317;
	  section.data(9).dtTransOffset = 8;
	
	  ;% bump_choice_B.RelationalOperator1
	  section.data(10).logicalSrcIdx = 318;
	  section.data(10).dtTransOffset = 9;
	
	  ;% bump_choice_B.RelationalOperator2
	  section.data(11).logicalSrcIdx = 319;
	  section.data(11).dtTransOffset = 10;
	
	  ;% bump_choice_B.RelationalOperator3
	  section.data(12).logicalSrcIdx = 320;
	  section.data(12).dtTransOffset = 11;
	
	  ;% bump_choice_B.LogicalOperator_a
	  section.data(13).logicalSrcIdx = 321;
	  section.data(13).dtTransOffset = 12;
	
	  ;% bump_choice_B.InBox
	  section.data(14).logicalSrcIdx = 322;
	  section.data(14).dtTransOffset = 13;
	
	  ;% bump_choice_B.LogicalOperator3
	  section.data(15).logicalSrcIdx = 323;
	  section.data(15).dtTransOffset = 14;
	
	  ;% bump_choice_B.Memory_b5
	  section.data(16).logicalSrcIdx = 324;
	  section.data(16).dtTransOffset = 15;
	
	  ;% bump_choice_B.LogicalOperator4
	  section.data(17).logicalSrcIdx = 325;
	  section.data(17).dtTransOffset = 16;
	
	  ;% bump_choice_B.LogicalOperator_j
	  section.data(18).logicalSrcIdx = 326;
	  section.data(18).dtTransOffset = 17;
	
	  ;% bump_choice_B.LogicalOperator2_m
	  section.data(19).logicalSrcIdx = 327;
	  section.data(19).dtTransOffset = 18;
	
	  ;% bump_choice_B.LogicalOperator1_f
	  section.data(20).logicalSrcIdx = 328;
	  section.data(20).dtTransOffset = 19;
	
	  ;% bump_choice_B.HiddenBuf_InsertedFor_Enabled_g
	  section.data(21).logicalSrcIdx = 329;
	  section.data(21).dtTransOffset = 20;
	
	  ;% bump_choice_B.RelationalOperator_i
	  section.data(22).logicalSrcIdx = 330;
	  section.data(22).dtTransOffset = 21;
	
	  ;% bump_choice_B.LogicalOperator_n
	  section.data(23).logicalSrcIdx = 331;
	  section.data(23).dtTransOffset = 22;
	
	  ;% bump_choice_B.LogicalOperator5
	  section.data(24).logicalSrcIdx = 332;
	  section.data(24).dtTransOffset = 23;
	
	  ;% bump_choice_B.LogicalOperator2_a
	  section.data(25).logicalSrcIdx = 333;
	  section.data(25).dtTransOffset = 24;
	
	  ;% bump_choice_B.LogicalOperator1_c
	  section.data(26).logicalSrcIdx = 334;
	  section.data(26).dtTransOffset = 25;
	
	  ;% bump_choice_B.HiddenBuf_InsertedFor_Enabled_j
	  section.data(27).logicalSrcIdx = 335;
	  section.data(27).dtTransOffset = 26;
	
	  ;% bump_choice_B.RelationalOperator_l
	  section.data(28).logicalSrcIdx = 336;
	  section.data(28).dtTransOffset = 27;
	
	  ;% bump_choice_B.LogicalOperator_e
	  section.data(29).logicalSrcIdx = 337;
	  section.data(29).dtTransOffset = 28;
	
	  ;% bump_choice_B.LogicalOperator1_e
	  section.data(30).logicalSrcIdx = 338;
	  section.data(30).dtTransOffset = 29;
	
	  ;% bump_choice_B.NOT
	  section.data(31).logicalSrcIdx = 339;
	  section.data(31).dtTransOffset = 30;
	
	  ;% bump_choice_B.Memory_n
	  section.data(32).logicalSrcIdx = 340;
	  section.data(32).dtTransOffset = 31;
	
	  ;% bump_choice_B.LogicalOperator2_a2
	  section.data(33).logicalSrcIdx = 341;
	  section.data(33).dtTransOffset = 32;
	
	  ;% bump_choice_B.LogicalOperator1_i
	  section.data(34).logicalSrcIdx = 342;
	  section.data(34).dtTransOffset = 33;
	
	  ;% bump_choice_B.HiddenBuf_InsertedFor_Enabled_a
	  section.data(35).logicalSrcIdx = 343;
	  section.data(35).dtTransOffset = 34;
	
	  ;% bump_choice_B.RelationalOperator_p
	  section.data(36).logicalSrcIdx = 344;
	  section.data(36).dtTransOffset = 35;
	
	  ;% bump_choice_B.LogicalOperator_c
	  section.data(37).logicalSrcIdx = 345;
	  section.data(37).dtTransOffset = 36;
	
	  ;% bump_choice_B.DataTypeConversion2
	  section.data(38).logicalSrcIdx = 346;
	  section.data(38).dtTransOffset = 37;
	
	  ;% bump_choice_B.LogicalOperator1_g
	  section.data(39).logicalSrcIdx = 347;
	  section.data(39).dtTransOffset = 38;
	
	  ;% bump_choice_B.Memory_m
	  section.data(40).logicalSrcIdx = 348;
	  section.data(40).dtTransOffset = 39;
	
	  ;% bump_choice_B.LogicalOperator2_i
	  section.data(41).logicalSrcIdx = 349;
	  section.data(41).dtTransOffset = 40;
	
	  ;% bump_choice_B.LogicalOperator1_l
	  section.data(42).logicalSrcIdx = 350;
	  section.data(42).dtTransOffset = 41;
	
	  ;% bump_choice_B.HiddenBuf_InsertedFor_Enabled_l
	  section.data(43).logicalSrcIdx = 351;
	  section.data(43).dtTransOffset = 42;
	
	  ;% bump_choice_B.RelationalOperator_k
	  section.data(44).logicalSrcIdx = 352;
	  section.data(44).dtTransOffset = 43;
	
	  ;% bump_choice_B.LogicalOperator_nd
	  section.data(45).logicalSrcIdx = 353;
	  section.data(45).dtTransOffset = 44;
	
	  ;% bump_choice_B.DataTypeConversion1
	  section.data(46).logicalSrcIdx = 354;
	  section.data(46).dtTransOffset = 45;
	
	  ;% bump_choice_B.Memory_j
	  section.data(47).logicalSrcIdx = 355;
	  section.data(47).dtTransOffset = 46;
	
	  ;% bump_choice_B.Logic
	  section.data(48).logicalSrcIdx = 356;
	  section.data(48).dtTransOffset = 47;
	
	  ;% bump_choice_B.LogicalOperator5_k
	  section.data(49).logicalSrcIdx = 357;
	  section.data(49).dtTransOffset = 49;
	
	  ;% bump_choice_B.LogicalOperator1_it
	  section.data(50).logicalSrcIdx = 358;
	  section.data(50).dtTransOffset = 50;
	
	  ;% bump_choice_B.MatrixConcatenation
	  section.data(51).logicalSrcIdx = 359;
	  section.data(51).dtTransOffset = 51;
	
	  ;% bump_choice_B.RelationalOperator_ka
	  section.data(52).logicalSrcIdx = 360;
	  section.data(52).dtTransOffset = 53;
	
	  ;% bump_choice_B.RelationalOperator_b
	  section.data(53).logicalSrcIdx = 361;
	  section.data(53).dtTransOffset = 54;
	
	  ;% bump_choice_B.Compare_c
	  section.data(54).logicalSrcIdx = 362;
	  section.data(54).dtTransOffset = 55;
	
	  ;% bump_choice_B.Compare_b
	  section.data(55).logicalSrcIdx = 363;
	  section.data(55).dtTransOffset = 56;
	
	  ;% bump_choice_B.LogicalOperator6
	  section.data(56).logicalSrcIdx = 364;
	  section.data(56).dtTransOffset = 57;
	
	  ;% bump_choice_B.LogicalOperator3_d
	  section.data(57).logicalSrcIdx = 365;
	  section.data(57).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_B.SampleandHold.In
	  section.data(1).logicalSrcIdx = 366;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_B.SampleandHold_h.In
	  section.data(1).logicalSrcIdx = 367;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_B.EnabledSubsystem_l.In1
	  section.data(1).logicalSrcIdx = 368;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_B.EnabledSubsystem_e.In1
	  section.data(1).logicalSrcIdx = 369;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_B.EnabledSubsystem_o.In1
	  section.data(1).logicalSrcIdx = 370;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_B.EnabledSubsystem_p.In1
	  section.data(1).logicalSrcIdx = 371;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_B.EnabledSubsystem.In1
	  section.data(1).logicalSrcIdx = 372;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 18;
    sectIdxOffset = 10;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (bump_choice_DWork)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.DigitalFilter2_FILT_STATES
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_DWork.DigitalFilter_FILT_STATES
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 11;
	
	  ;% bump_choice_DWork.DigitalFilter2_FILT_STATES_a
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 22;
	
	  ;% bump_choice_DWork.DigitalFilter_FILT_STATES_e
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 33;
	
	  ;% bump_choice_DWork.x_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 44;
	
	  ;% bump_choice_DWork.x_DSTATE_n
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 45;
	
	  ;% bump_choice_DWork.x_DSTATE_i
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 46;
	
	  ;% bump_choice_DWork.x_DSTATE_in
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 47;
	
	  ;% bump_choice_DWork.x_DSTATE_m
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 48;
	
	  ;% bump_choice_DWork.x_DSTATE_h
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 49;
	
	  ;% bump_choice_DWork.x_DSTATE_o
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 50;
	
	  ;% bump_choice_DWork.x_DSTATE_d
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 51;
	
	  ;% bump_choice_DWork.BehaviorBC_DSTATE
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 52;
	
	  ;% bump_choice_DWork.y_DSTATE
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 53;
	
	  ;% bump_choice_DWork.z_DSTATE
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 54;
	
	  ;% bump_choice_DWork.y_DSTATE_a
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 55;
	
	  ;% bump_choice_DWork.z_DSTATE_n
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 56;
	
	  ;% bump_choice_DWork.y_DSTATE_n
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 57;
	
	  ;% bump_choice_DWork.z_DSTATE_c
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 58;
	
	  ;% bump_choice_DWork.y_DSTATE_i
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 59;
	
	  ;% bump_choice_DWork.z_DSTATE_a
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 60;
	
	  ;% bump_choice_DWork.y_DSTATE_a5
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 61;
	
	  ;% bump_choice_DWork.z_DSTATE_e
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 62;
	
	  ;% bump_choice_DWork.y_DSTATE_ae
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 63;
	
	  ;% bump_choice_DWork.z_DSTATE_p
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 64;
	
	  ;% bump_choice_DWork.y_DSTATE_l
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 65;
	
	  ;% bump_choice_DWork.z_DSTATE_m
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 66;
	
	  ;% bump_choice_DWork.y_DSTATE_f
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 67;
	
	  ;% bump_choice_DWork.z_DSTATE_f
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 68;
	
	  ;% bump_choice_DWork.PCI6025EAD_RWORK
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 69;
	
	  ;% bump_choice_DWork.Derivative_RWORK.TimeStampA
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 133;
	
	  ;% bump_choice_DWork.Derivative_RWORK_e.TimeStampA
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 134;
	
	  ;% bump_choice_DWork.BehaviorBC_RWORK
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 135;
	
	  ;% bump_choice_DWork.PCI6025E_RWORK
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 142;
	
	  ;% bump_choice_DWork.UniformRandomNumber_RWORK.NextOutput
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 148;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.BehaviorBC_PWORK
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_DWork.Send_PWORK
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.DigitalFilter2_CIRCBUFFIDX
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_DWork.DigitalFilter_CIRCBUFFIDX
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bump_choice_DWork.DigitalFilter2_CIRCBUFFIDX_j
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
	  ;% bump_choice_DWork.DigitalFilter_CIRCBUFFIDX_c
	  section.data(4).logicalSrcIdx = 40;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.PCIQUAD04_IWORK
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_DWork.PCIQUAD041_IWORK
	  section.data(2).logicalSrcIdx = 42;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bump_choice_DWork.PCI6025EAD_IWORK
	  section.data(3).logicalSrcIdx = 43;
	  section.data(3).dtTransOffset = 2;
	
	  ;% bump_choice_DWork.BehaviorBC_IWORK
	  section.data(4).logicalSrcIdx = 44;
	  section.data(4).dtTransOffset = 68;
	
	  ;% bump_choice_DWork.PCI6025E_IWORK
	  section.data(5).logicalSrcIdx = 45;
	  section.data(5).dtTransOffset = 96;
	
	  ;% bump_choice_DWork.SFunction_IWORK.AcquireOK
	  section.data(6).logicalSrcIdx = 46;
	  section.data(6).dtTransOffset = 98;
	
	  ;% bump_choice_DWork.SFunction_IWORK_n.AcquireOK
	  section.data(7).logicalSrcIdx = 47;
	  section.data(7).dtTransOffset = 99;
	
	  ;% bump_choice_DWork.Send_IWORK
	  section.data(8).logicalSrcIdx = 48;
	  section.data(8).dtTransOffset = 100;
	
	  ;% bump_choice_DWork.SFunction_IWORK_e.AcquireOK
	  section.data(9).logicalSrcIdx = 49;
	  section.data(9).dtTransOffset = 102;
	
	  ;% bump_choice_DWork.SFunction_IWORK_g.AcquireOK
	  section.data(10).logicalSrcIdx = 50;
	  section.data(10).dtTransOffset = 103;
	
	  ;% bump_choice_DWork.SFunction_IWORK_h.AcquireOK
	  section.data(11).logicalSrcIdx = 51;
	  section.data(11).dtTransOffset = 104;
	
	  ;% bump_choice_DWork.SFunction_IWORK_d.AcquireOK
	  section.data(12).logicalSrcIdx = 52;
	  section.data(12).dtTransOffset = 105;
	
	  ;% bump_choice_DWork.UniformRandomNumber_IWORK.RandSeed
	  section.data(13).logicalSrcIdx = 53;
	  section.data(13).dtTransOffset = 106;
	
	  ;% bump_choice_DWork.PortA_IWORK
	  section.data(14).logicalSrcIdx = 54;
	  section.data(14).dtTransOffset = 107;
	
	  ;% bump_choice_DWork.PortB_IWORK
	  section.data(15).logicalSrcIdx = 55;
	  section.data(15).dtTransOffset = 109;
	
	  ;% bump_choice_DWork.PCI6025E_IWORK_j
	  section.data(16).logicalSrcIdx = 56;
	  section.data(16).dtTransOffset = 111;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.DelayInput1_DSTATE
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_DWork.DelayInput1_DSTATE_h
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bump_choice_DWork.DelayInput1_DSTATE_f
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 2;
	
	  ;% bump_choice_DWork.DelayInput1_DSTATE_l
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% bump_choice_DWork.Memory_PreviousInput_i
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 1;
	
	  ;% bump_choice_DWork.Memory_PreviousInput_d
	  section.data(3).logicalSrcIdx = 63;
	  section.data(3).dtTransOffset = 2;
	
	  ;% bump_choice_DWork.Memory_PreviousInput_dp
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 3;
	
	  ;% bump_choice_DWork.Memory_PreviousInput_b
	  section.data(5).logicalSrcIdx = 65;
	  section.data(5).dtTransOffset = 4;
	
	  ;% bump_choice_DWork.Memory_PreviousInput_n
	  section.data(6).logicalSrcIdx = 66;
	  section.data(6).dtTransOffset = 5;
	
	  ;% bump_choice_DWork.Memory_PreviousInput_iw
	  section.data(7).logicalSrcIdx = 67;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.SampleandHold.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.SampleandHold_h.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.EnabledSubsystem_e.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.EnabledSubsystem_e.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.EnabledSubsystem_o.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.EnabledSubsystem_p.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.EnabledSubsystem_p.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.EnabledSubsystem.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% bump_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 285797927;
  targMap.checksum1 = 3164372520;
  targMap.checksum2 = 2927048213;
  targMap.checksum3 = 3476318370;

