  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
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
    ;% Auto data (random_walk_P)
    ;%
      section.nData     = 318;
      section.data(318)  = dumData; %prealloc
      
	  ;% random_walk_P.Time_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_P.PCIQUAD04_P1_Size
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% random_walk_P.PCIQUAD04_P1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% random_walk_P.PCIQUAD04_P2_Size
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% random_walk_P.PCIQUAD04_P2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% random_walk_P.PCIQUAD04_P3_Size
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% random_walk_P.PCIQUAD04_P3
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% random_walk_P.PCIQUAD04_P4_Size
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% random_walk_P.PCIQUAD04_P4
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% random_walk_P.PCIQUAD04_P5_Size
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% random_walk_P.PCIQUAD04_P5
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% random_walk_P.PCIQUAD04_P6_Size
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% random_walk_P.PCIQUAD04_P6
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% random_walk_P.PCIQUAD04_P7_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% random_walk_P.PCIQUAD04_P7
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% random_walk_P.PCIQUAD04_P8_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% random_walk_P.PCIQUAD04_P8
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% random_walk_P.PCIQUAD04_P9_Size
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 25;
	
	  ;% random_walk_P.PCIQUAD04_P9
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 27;
	
	  ;% random_walk_P.PCIQUAD04_P10_Size
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 28;
	
	  ;% random_walk_P.PCIQUAD04_P10
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 30;
	
	  ;% random_walk_P.PCIQUAD04_P11_Size
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 31;
	
	  ;% random_walk_P.PCIQUAD04_P11
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 33;
	
	  ;% random_walk_P.Gain_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 34;
	
	  ;% random_walk_P.shoulderOffset_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 35;
	
	  ;% random_walk_P.L1_Value
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 36;
	
	  ;% random_walk_P.Gain_Gain_f
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 37;
	
	  ;% random_walk_P.PCIQUAD041_P1_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 38;
	
	  ;% random_walk_P.PCIQUAD041_P1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 40;
	
	  ;% random_walk_P.PCIQUAD041_P2_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 41;
	
	  ;% random_walk_P.PCIQUAD041_P2
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 43;
	
	  ;% random_walk_P.PCIQUAD041_P3_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 44;
	
	  ;% random_walk_P.PCIQUAD041_P3
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 46;
	
	  ;% random_walk_P.PCIQUAD041_P4_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 47;
	
	  ;% random_walk_P.PCIQUAD041_P4
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 49;
	
	  ;% random_walk_P.PCIQUAD041_P5_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 50;
	
	  ;% random_walk_P.PCIQUAD041_P5
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 52;
	
	  ;% random_walk_P.PCIQUAD041_P6_Size
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 53;
	
	  ;% random_walk_P.PCIQUAD041_P6
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 55;
	
	  ;% random_walk_P.PCIQUAD041_P7_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 56;
	
	  ;% random_walk_P.PCIQUAD041_P7
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 58;
	
	  ;% random_walk_P.PCIQUAD041_P8_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 59;
	
	  ;% random_walk_P.PCIQUAD041_P8
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 61;
	
	  ;% random_walk_P.PCIQUAD041_P9_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 62;
	
	  ;% random_walk_P.PCIQUAD041_P9
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 64;
	
	  ;% random_walk_P.PCIQUAD041_P10_Size
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 65;
	
	  ;% random_walk_P.PCIQUAD041_P10
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 67;
	
	  ;% random_walk_P.PCIQUAD041_P11_Size
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 68;
	
	  ;% random_walk_P.PCIQUAD041_P11
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 70;
	
	  ;% random_walk_P.Gain1_Gain
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 71;
	
	  ;% random_walk_P.elbowOffset_Value
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 72;
	
	  ;% random_walk_P.L2_Value
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 73;
	
	  ;% random_walk_P.Gain1_Gain_c
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 74;
	
	  ;% random_walk_P.Gain2_Gain
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 75;
	
	  ;% random_walk_P.PCI6025EAD_P1_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 76;
	
	  ;% random_walk_P.PCI6025EAD_P1
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 78;
	
	  ;% random_walk_P.PCI6025EAD_P2_Size
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 80;
	
	  ;% random_walk_P.PCI6025EAD_P2
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 82;
	
	  ;% random_walk_P.PCI6025EAD_P3_Size
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 84;
	
	  ;% random_walk_P.PCI6025EAD_P3
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 86;
	
	  ;% random_walk_P.PCI6025EAD_P4_Size
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 88;
	
	  ;% random_walk_P.PCI6025EAD_P4
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 90;
	
	  ;% random_walk_P.PCI6025EAD_P5_Size
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 91;
	
	  ;% random_walk_P.PCI6025EAD_P5
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 93;
	
	  ;% random_walk_P.PCI6025EAD_P6_Size
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 94;
	
	  ;% random_walk_P.PCI6025EAD_P6
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 96;
	
	  ;% random_walk_P.UseTachs_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 97;
	
	  ;% random_walk_P.yoffset_Value
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 98;
	
	  ;% random_walk_P.xoffset_Value
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 99;
	
	  ;% random_walk_P.AngleOffset_Value
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 100;
	
	  ;% random_walk_P.DigitalFilter2_ICRTP
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 101;
	
	  ;% random_walk_P.DigitalFilter2_RTP1COEFF
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 102;
	
	  ;% random_walk_P.dG_Gain
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 113;
	
	  ;% random_walk_P.DigitalFilter_ICRTP
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 114;
	
	  ;% random_walk_P.DigitalFilter_RTP1COEFF
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 115;
	
	  ;% random_walk_P.DigitalFilter2_ICRTP_f
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 126;
	
	  ;% random_walk_P.DigitalFilter2_RTP1COEFF_f
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 127;
	
	  ;% random_walk_P.dG_Gain_d
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 138;
	
	  ;% random_walk_P.DigitalFilter_ICRTP_p
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 139;
	
	  ;% random_walk_P.DigitalFilter_RTP1COEFF_o
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 140;
	
	  ;% random_walk_P.Switch_Threshold
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 151;
	
	  ;% random_walk_P.XLowLimit_Value
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 152;
	
	  ;% random_walk_P.XHighLimit_Value
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 153;
	
	  ;% random_walk_P.YHighLimit_Value
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 154;
	
	  ;% random_walk_P.YLowLimit_Value
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 155;
	
	  ;% random_walk_P.RecenterFlag_Value
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 156;
	
	  ;% random_walk_P.Time_Value_l
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 157;
	
	  ;% random_walk_P.Time_Value_p
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 158;
	
	  ;% random_walk_P.Constant_Value
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 159;
	
	  ;% random_walk_P.Constant_Value_e
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 160;
	
	  ;% random_walk_P.Time_Value_m
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 161;
	
	  ;% random_walk_P.Time_Value_n
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 162;
	
	  ;% random_walk_P.Load_Value
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 163;
	
	  ;% random_walk_P.x_X0
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 164;
	
	  ;% random_walk_P.x_X0_f
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 165;
	
	  ;% random_walk_P.x_X0_fi
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 166;
	
	  ;% random_walk_P.x_X0_i
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 167;
	
	  ;% random_walk_P.Load_Value_a
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 168;
	
	  ;% random_walk_P.x_X0_d
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 169;
	
	  ;% random_walk_P.x_X0_p
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 170;
	
	  ;% random_walk_P.x_X0_iy
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 171;
	
	  ;% random_walk_P.x_X0_p3
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 172;
	
	  ;% random_walk_P.BehaviorRW_P1_Size
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 173;
	
	  ;% random_walk_P.BehaviorRW_P1
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 175;
	
	  ;% random_walk_P.BehaviorRW_P2_Size
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 176;
	
	  ;% random_walk_P.BehaviorRW_P2
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 178;
	
	  ;% random_walk_P.BehaviorRW_P3_Size
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 179;
	
	  ;% random_walk_P.BehaviorRW_P3
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 181;
	
	  ;% random_walk_P.BehaviorRW_P4_Size
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 182;
	
	  ;% random_walk_P.BehaviorRW_P4
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 184;
	
	  ;% random_walk_P.BehaviorRW_P5_Size
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 185;
	
	  ;% random_walk_P.BehaviorRW_P5
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 187;
	
	  ;% random_walk_P.BehaviorRW_P6_Size
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 188;
	
	  ;% random_walk_P.BehaviorRW_P6
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 190;
	
	  ;% random_walk_P.BehaviorRW_P7_Size
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 191;
	
	  ;% random_walk_P.BehaviorRW_P7
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 193;
	
	  ;% random_walk_P.BehaviorRW_P8_Size
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 194;
	
	  ;% random_walk_P.BehaviorRW_P8
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 196;
	
	  ;% random_walk_P.BehaviorRW_P9_Size
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 197;
	
	  ;% random_walk_P.BehaviorRW_P9
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 199;
	
	  ;% random_walk_P.BehaviorRW_P10_Size
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 200;
	
	  ;% random_walk_P.BehaviorRW_P10
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 202;
	
	  ;% random_walk_P.BehaviorRW_P11_Size
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 203;
	
	  ;% random_walk_P.BehaviorRW_P11
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 205;
	
	  ;% random_walk_P.BehaviorRW_P12_Size
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 206;
	
	  ;% random_walk_P.BehaviorRW_P12
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 208;
	
	  ;% random_walk_P.BehaviorRW_P13_Size
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 209;
	
	  ;% random_walk_P.BehaviorRW_P13
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 211;
	
	  ;% random_walk_P.BehaviorRW_P14_Size
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 212;
	
	  ;% random_walk_P.BehaviorRW_P14
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 214;
	
	  ;% random_walk_P.BehaviorRW_P15_Size
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 215;
	
	  ;% random_walk_P.BehaviorRW_P15
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 217;
	
	  ;% random_walk_P.BehaviorRW_P16_Size
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 218;
	
	  ;% random_walk_P.BehaviorRW_P16
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 220;
	
	  ;% random_walk_P.BehaviorRW_P17_Size
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 221;
	
	  ;% random_walk_P.BehaviorRW_P17
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 223;
	
	  ;% random_walk_P.BehaviorRW_P18_Size
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 224;
	
	  ;% random_walk_P.BehaviorRW_P18
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 226;
	
	  ;% random_walk_P.MG1_Gain
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 227;
	
	  ;% random_walk_P.MG2_Gain
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 228;
	
	  ;% random_walk_P.PCI6025E_P1_Size
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 229;
	
	  ;% random_walk_P.PCI6025E_P1
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 231;
	
	  ;% random_walk_P.PCI6025E_P2_Size
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 233;
	
	  ;% random_walk_P.PCI6025E_P2
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 235;
	
	  ;% random_walk_P.PCI6025E_P3_Size
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 237;
	
	  ;% random_walk_P.PCI6025E_P3
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 239;
	
	  ;% random_walk_P.PCI6025E_P4_Size
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 241;
	
	  ;% random_walk_P.PCI6025E_P4
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 243;
	
	  ;% random_walk_P.PCI6025E_P5_Size
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 245;
	
	  ;% random_walk_P.PCI6025E_P5
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 247;
	
	  ;% random_walk_P.PCI6025E_P6_Size
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 248;
	
	  ;% random_walk_P.PCI6025E_P6
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 250;
	
	  ;% random_walk_P.PCI6025E_P7_Size
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 251;
	
	  ;% random_walk_P.PCI6025E_P7
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 253;
	
	  ;% random_walk_P.Constant_Value_b
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 254;
	
	  ;% random_walk_P.Constant_Value_g
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 255;
	
	  ;% random_walk_P.Send_P1_Size
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 256;
	
	  ;% random_walk_P.Send_P1
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 258;
	
	  ;% random_walk_P.Send_P2_Size
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 269;
	
	  ;% random_walk_P.Send_P2
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 271;
	
	  ;% random_walk_P.Send_P3_Size
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 272;
	
	  ;% random_walk_P.Send_P3
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 274;
	
	  ;% random_walk_P.Send_P4_Size
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 275;
	
	  ;% random_walk_P.Send_P4
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 277;
	
	  ;% random_walk_P.UniformRandomNumber_Min
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 278;
	
	  ;% random_walk_P.UniformRandomNumber_Max
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 279;
	
	  ;% random_walk_P.UniformRandomNumber_Seed
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 280;
	
	  ;% random_walk_P.JackpotChance_Value
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 281;
	
	  ;% random_walk_P.y_X0
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 282;
	
	  ;% random_walk_P.rho_Value
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 283;
	
	  ;% random_walk_P.z_X0
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 284;
	
	  ;% random_walk_P.beta_Value
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 285;
	
	  ;% random_walk_P.timescale_Value
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 286;
	
	  ;% random_walk_P.sigma_Value
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 287;
	
	  ;% random_walk_P.y_X0_d
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 288;
	
	  ;% random_walk_P.rho_Value_a
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 289;
	
	  ;% random_walk_P.z_X0_c
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 290;
	
	  ;% random_walk_P.beta_Value_i
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 291;
	
	  ;% random_walk_P.timescale_Value_m
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 292;
	
	  ;% random_walk_P.sigma_Value_l
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 293;
	
	  ;% random_walk_P.y_X0_e
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 294;
	
	  ;% random_walk_P.rho_Value_m
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 295;
	
	  ;% random_walk_P.z_X0_b
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 296;
	
	  ;% random_walk_P.beta_Value_p
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 297;
	
	  ;% random_walk_P.timescale_Value_d
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 298;
	
	  ;% random_walk_P.sigma_Value_j
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 299;
	
	  ;% random_walk_P.y_X0_n
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 300;
	
	  ;% random_walk_P.rho_Value_e
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 301;
	
	  ;% random_walk_P.z_X0_a
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 302;
	
	  ;% random_walk_P.beta_Value_f
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 303;
	
	  ;% random_walk_P.timescale_Value_p
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 304;
	
	  ;% random_walk_P.sigma_Value_b
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 305;
	
	  ;% random_walk_P.y_X0_g
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 306;
	
	  ;% random_walk_P.rho_Value_am
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 307;
	
	  ;% random_walk_P.z_X0_cv
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 308;
	
	  ;% random_walk_P.beta_Value_o
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 309;
	
	  ;% random_walk_P.timescale_Value_e
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 310;
	
	  ;% random_walk_P.sigma_Value_m
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 311;
	
	  ;% random_walk_P.y_X0_l
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 312;
	
	  ;% random_walk_P.rho_Value_j
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 313;
	
	  ;% random_walk_P.z_X0_j
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 314;
	
	  ;% random_walk_P.beta_Value_g
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 315;
	
	  ;% random_walk_P.timescale_Value_py
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 316;
	
	  ;% random_walk_P.sigma_Value_h
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 317;
	
	  ;% random_walk_P.y_X0_p
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 318;
	
	  ;% random_walk_P.rho_Value_eo
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 319;
	
	  ;% random_walk_P.z_X0_l
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 320;
	
	  ;% random_walk_P.beta_Value_o2
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 321;
	
	  ;% random_walk_P.timescale_Value_dn
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 322;
	
	  ;% random_walk_P.sigma_Value_hc
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 323;
	
	  ;% random_walk_P.y_X0_lz
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 324;
	
	  ;% random_walk_P.rho_Value_mm
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 325;
	
	  ;% random_walk_P.z_X0_g
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 326;
	
	  ;% random_walk_P.beta_Value_e
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 327;
	
	  ;% random_walk_P.timescale_Value_h
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 328;
	
	  ;% random_walk_P.sigma_Value_mj
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 329;
	
	  ;% random_walk_P.Gain_Gain_g
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 330;
	
	  ;% random_walk_P.Gain1_Gain_d
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 331;
	
	  ;% random_walk_P.Gain_Gain_o
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 332;
	
	  ;% random_walk_P.visAngle_Value
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 333;
	
	  ;% random_walk_P.DynamicAngle_Value
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 334;
	
	  ;% random_walk_P.Inverter_Gain
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 335;
	
	  ;% random_walk_P.Gain_Gain_b
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 336;
	
	  ;% random_walk_P.LorentzForceGain_Gain
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 337;
	
	  ;% random_walk_P.staticX_Value
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 338;
	
	  ;% random_walk_P.staticY_Value
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 339;
	
	  ;% random_walk_P.Off_Value
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 340;
	
	  ;% random_walk_P.Gain_Gain_p
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 341;
	
	  ;% random_walk_P.visAngle_Value_n
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 342;
	
	  ;% random_walk_P.DynamicAngle_Value_h
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 343;
	
	  ;% random_walk_P.Inverter_Gain_b
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 344;
	
	  ;% random_walk_P.Gain_Gain_go
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 345;
	
	  ;% random_walk_P.LorentzForceGain_Gain_j
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 346;
	
	  ;% random_walk_P.staticX_Value_e
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 347;
	
	  ;% random_walk_P.staticY_Value_a
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 348;
	
	  ;% random_walk_P.Off_Value_d
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 349;
	
	  ;% random_walk_P.Gain1_Gain_p
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 350;
	
	  ;% random_walk_P.Gain3_Gain
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 351;
	
	  ;% random_walk_P.Saturation_UpperSat
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 352;
	
	  ;% random_walk_P.Saturation_LowerSat
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 353;
	
	  ;% random_walk_P.Gain4_Gain
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 354;
	
	  ;% random_walk_P.Gain2_Gain_d
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 355;
	
	  ;% random_walk_P.Saturation1_UpperSat
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 356;
	
	  ;% random_walk_P.Saturation1_LowerSat
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 357;
	
	  ;% random_walk_P.BoundingBoxViscosity_Gain
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 358;
	
	  ;% random_walk_P.zeroX_Value
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 359;
	
	  ;% random_walk_P.zeroY_Value
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 360;
	
	  ;% random_walk_P.Gain_Gain_e
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 361;
	
	  ;% random_walk_P.RewardJackpot_Value
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 362;
	
	  ;% random_walk_P.RewardTime_Value
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 363;
	
	  ;% random_walk_P.TachGain2_Gain
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 364;
	
	  ;% random_walk_P.TachGain1_Gain
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 365;
	
	  ;% random_walk_P.Constant2_Value
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 366;
	
	  ;% random_walk_P.Constant1_Value
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 367;
	
	  ;% random_walk_P.Constant_Value_m
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 368;
	
	  ;% random_walk_P.xPCTargetTime_P1_Size
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 369;
	
	  ;% random_walk_P.xPCTargetTime_P1
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 371;
	
	  ;% random_walk_P.xPCTargetTime_P2_Size
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 372;
	
	  ;% random_walk_P.xPCTargetTime_P2
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 374;
	
	  ;% random_walk_P.ScaleTouSec_Gain
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 375;
	
	  ;% random_walk_P.Constant_Value_o
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 376;
	
	  ;% random_walk_P.PCI6025E_P1_Size_g
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 377;
	
	  ;% random_walk_P.PCI6025E_P1_o
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 379;
	
	  ;% random_walk_P.PCI6025E_P2_Size_i
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 381;
	
	  ;% random_walk_P.PCI6025E_P2_f
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 383;
	
	  ;% random_walk_P.PCI6025E_P3_Size_h
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 385;
	
	  ;% random_walk_P.PCI6025E_P3_k
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 387;
	
	  ;% random_walk_P.PCI6025E_P4_Size_p
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 389;
	
	  ;% random_walk_P.PCI6025E_P4_i
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 391;
	
	  ;% random_walk_P.PCI6025E_P5_Size_o
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 392;
	
	  ;% random_walk_P.PCI6025E_P5_h
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 394;
	
	  ;% random_walk_P.PCI6025E_P6_Size_f
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 395;
	
	  ;% random_walk_P.PCI6025E_P6_n
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 397;
	
	  ;% random_walk_P.PCI6025E_P7_Size_i
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 398;
	
	  ;% random_walk_P.PCI6025E_P7_e
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 400;
	
	  ;% random_walk_P.Constant_Value_a
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 401;
	
	  ;% random_walk_P.Switch_Threshold_a
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 402;
	
	  ;% random_walk_P.PortA_P1_Size
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 403;
	
	  ;% random_walk_P.PortA_P1
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 405;
	
	  ;% random_walk_P.PortA_P2_Size
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 413;
	
	  ;% random_walk_P.PortA_P2
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 415;
	
	  ;% random_walk_P.PortA_P3_Size
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 416;
	
	  ;% random_walk_P.PortA_P3
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 418;
	
	  ;% random_walk_P.PortA_P4_Size
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 426;
	
	  ;% random_walk_P.PortA_P4
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 428;
	
	  ;% random_walk_P.PortA_P5_Size
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 436;
	
	  ;% random_walk_P.PortA_P5
	  section.data(287).logicalSrcIdx = 286;
	  section.data(287).dtTransOffset = 438;
	
	  ;% random_walk_P.PortA_P6_Size
	  section.data(288).logicalSrcIdx = 287;
	  section.data(288).dtTransOffset = 439;
	
	  ;% random_walk_P.PortA_P6
	  section.data(289).logicalSrcIdx = 288;
	  section.data(289).dtTransOffset = 441;
	
	  ;% random_walk_P.PortA_P7_Size
	  section.data(290).logicalSrcIdx = 289;
	  section.data(290).dtTransOffset = 442;
	
	  ;% random_walk_P.PortA_P7
	  section.data(291).logicalSrcIdx = 290;
	  section.data(291).dtTransOffset = 444;
	
	  ;% random_walk_P.PortA_P8_Size
	  section.data(292).logicalSrcIdx = 291;
	  section.data(292).dtTransOffset = 445;
	
	  ;% random_walk_P.PortA_P8
	  section.data(293).logicalSrcIdx = 292;
	  section.data(293).dtTransOffset = 447;
	
	  ;% random_walk_P.PortA_P9_Size
	  section.data(294).logicalSrcIdx = 293;
	  section.data(294).dtTransOffset = 448;
	
	  ;% random_walk_P.PortA_P9
	  section.data(295).logicalSrcIdx = 294;
	  section.data(295).dtTransOffset = 450;
	
	  ;% random_walk_P.Constant_Value_j
	  section.data(296).logicalSrcIdx = 295;
	  section.data(296).dtTransOffset = 451;
	
	  ;% random_walk_P.PortB_P1_Size
	  section.data(297).logicalSrcIdx = 296;
	  section.data(297).dtTransOffset = 452;
	
	  ;% random_walk_P.PortB_P1
	  section.data(298).logicalSrcIdx = 297;
	  section.data(298).dtTransOffset = 454;
	
	  ;% random_walk_P.PortB_P2_Size
	  section.data(299).logicalSrcIdx = 298;
	  section.data(299).dtTransOffset = 462;
	
	  ;% random_walk_P.PortB_P2
	  section.data(300).logicalSrcIdx = 299;
	  section.data(300).dtTransOffset = 464;
	
	  ;% random_walk_P.PortB_P3_Size
	  section.data(301).logicalSrcIdx = 300;
	  section.data(301).dtTransOffset = 465;
	
	  ;% random_walk_P.PortB_P3
	  section.data(302).logicalSrcIdx = 301;
	  section.data(302).dtTransOffset = 467;
	
	  ;% random_walk_P.PortB_P4_Size
	  section.data(303).logicalSrcIdx = 302;
	  section.data(303).dtTransOffset = 475;
	
	  ;% random_walk_P.PortB_P4
	  section.data(304).logicalSrcIdx = 303;
	  section.data(304).dtTransOffset = 477;
	
	  ;% random_walk_P.PortB_P5_Size
	  section.data(305).logicalSrcIdx = 304;
	  section.data(305).dtTransOffset = 485;
	
	  ;% random_walk_P.PortB_P5
	  section.data(306).logicalSrcIdx = 305;
	  section.data(306).dtTransOffset = 487;
	
	  ;% random_walk_P.PortB_P6_Size
	  section.data(307).logicalSrcIdx = 306;
	  section.data(307).dtTransOffset = 488;
	
	  ;% random_walk_P.PortB_P6
	  section.data(308).logicalSrcIdx = 307;
	  section.data(308).dtTransOffset = 490;
	
	  ;% random_walk_P.PortB_P7_Size
	  section.data(309).logicalSrcIdx = 308;
	  section.data(309).dtTransOffset = 491;
	
	  ;% random_walk_P.PortB_P7
	  section.data(310).logicalSrcIdx = 309;
	  section.data(310).dtTransOffset = 493;
	
	  ;% random_walk_P.PortB_P8_Size
	  section.data(311).logicalSrcIdx = 310;
	  section.data(311).dtTransOffset = 494;
	
	  ;% random_walk_P.PortB_P8
	  section.data(312).logicalSrcIdx = 311;
	  section.data(312).dtTransOffset = 496;
	
	  ;% random_walk_P.PortB_P9_Size
	  section.data(313).logicalSrcIdx = 312;
	  section.data(313).dtTransOffset = 497;
	
	  ;% random_walk_P.PortB_P9
	  section.data(314).logicalSrcIdx = 313;
	  section.data(314).dtTransOffset = 499;
	
	  ;% random_walk_P.xPCTargetTime_P1_Size_j
	  section.data(315).logicalSrcIdx = 314;
	  section.data(315).dtTransOffset = 500;
	
	  ;% random_walk_P.xPCTargetTime_P1_e
	  section.data(316).logicalSrcIdx = 315;
	  section.data(316).dtTransOffset = 502;
	
	  ;% random_walk_P.xPCTargetTime_P2_Size_h
	  section.data(317).logicalSrcIdx = 316;
	  section.data(317).dtTransOffset = 503;
	
	  ;% random_walk_P.xPCTargetTime_P2_h
	  section.data(318).logicalSrcIdx = 317;
	  section.data(318).dtTransOffset = 505;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% random_walk_P.DelayInput1_X0
	  section.data(1).logicalSrcIdx = 318;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_P.DelayInput1_X0_k
	  section.data(2).logicalSrcIdx = 319;
	  section.data(2).dtTransOffset = 1;
	
	  ;% random_walk_P.DelayInput1_X0_j
	  section.data(3).logicalSrcIdx = 320;
	  section.data(3).dtTransOffset = 2;
	
	  ;% random_walk_P.DelayInput1_X0_a
	  section.data(4).logicalSrcIdx = 321;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% random_walk_P.Memory_X0
	  section.data(1).logicalSrcIdx = 322;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_P.Memory_X0_e
	  section.data(2).logicalSrcIdx = 323;
	  section.data(2).dtTransOffset = 1;
	
	  ;% random_walk_P.Memory_X0_a
	  section.data(3).logicalSrcIdx = 324;
	  section.data(3).dtTransOffset = 2;
	
	  ;% random_walk_P.Memory_X0_i
	  section.data(4).logicalSrcIdx = 325;
	  section.data(4).dtTransOffset = 3;
	
	  ;% random_walk_P.Memory_X0_c
	  section.data(5).logicalSrcIdx = 326;
	  section.data(5).dtTransOffset = 4;
	
	  ;% random_walk_P.Memory_X0_p
	  section.data(6).logicalSrcIdx = 327;
	  section.data(6).dtTransOffset = 5;
	
	  ;% random_walk_P.Memory_X0_h
	  section.data(7).logicalSrcIdx = 328;
	  section.data(7).dtTransOffset = 6;
	
	  ;% random_walk_P.Logic_table
	  section.data(8).logicalSrcIdx = 329;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_P.SampleandHold._Y0
	  section.data(1).logicalSrcIdx = 330;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_P.SampleandHold_g._Y0
	  section.data(1).logicalSrcIdx = 331;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
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
    ;% Auto data (random_walk_B)
    ;%
      section.nData     = 286;
      section.data(286)  = dumData; %prealloc
      
	  ;% random_walk_B.Clock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_B.Sum
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% random_walk_B.PCIQUAD04
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% random_walk_B.Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% random_walk_B.Sum3
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% random_walk_B.TrigonometricFunction
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% random_walk_B.Product
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% random_walk_B.TrigonometricFunction1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% random_walk_B.Product1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% random_walk_B.PCIQUAD041
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% random_walk_B.Gain1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% random_walk_B.Sum1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% random_walk_B.TrigonometricFunction2
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% random_walk_B.Product2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% random_walk_B.TrigonometricFunction3
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% random_walk_B.Product3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% random_walk_B.MatrixConcatenate2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% random_walk_B.PCI6025EAD_o1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 20;
	
	  ;% random_walk_B.PCI6025EAD_o2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% random_walk_B.Sum2
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% random_walk_B.Sum4
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% random_walk_B.Sum3_i
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% random_walk_B.Sum1_g
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% random_walk_B.TrigonometricFunction1_p
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% random_walk_B.Sum_h
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 27;
	
	  ;% random_walk_B.TrigonometricFunction2_i
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 28;
	
	  ;% random_walk_B.sqrtu1u1u2u2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 29;
	
	  ;% random_walk_B.Product1_m
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 30;
	
	  ;% random_walk_B.DigitalFilter2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 31;
	
	  ;% random_walk_B.Derivative
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 32;
	
	  ;% random_walk_B.dG
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 33;
	
	  ;% random_walk_B.DigitalFilter
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 34;
	
	  ;% random_walk_B.TrigonometricFunction_g
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 35;
	
	  ;% random_walk_B.Product_l
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 36;
	
	  ;% random_walk_B.DigitalFilter2_k
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 37;
	
	  ;% random_walk_B.Derivative_d
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 38;
	
	  ;% random_walk_B.dG_d
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 39;
	
	  ;% random_walk_B.DigitalFilter_c
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 40;
	
	  ;% random_walk_B.Switch
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 41;
	
	  ;% random_walk_B.Clock_m
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 43;
	
	  ;% random_walk_B.Clock_i
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 44;
	
	  ;% random_walk_B.Sum_m
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 45;
	
	  ;% random_walk_B.Sum_hd
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 46;
	
	  ;% random_walk_B.Abs2
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 47;
	
	  ;% random_walk_B.Abs3
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 48;
	
	  ;% random_walk_B.Clock_e
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 49;
	
	  ;% random_walk_B.Sum_o
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 50;
	
	  ;% random_walk_B.Clock_n
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 51;
	
	  ;% random_walk_B.Sum_ms
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 52;
	
	  ;% random_walk_B.x
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 53;
	
	  ;% random_walk_B.x_f
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 54;
	
	  ;% random_walk_B.Add
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 55;
	
	  ;% random_walk_B.x_h
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 56;
	
	  ;% random_walk_B.x_l
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 57;
	
	  ;% random_walk_B.MultiportSwitch
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 58;
	
	  ;% random_walk_B.x_k
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 60;
	
	  ;% random_walk_B.x_m
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 61;
	
	  ;% random_walk_B.Add_o
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 62;
	
	  ;% random_walk_B.x_o
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 63;
	
	  ;% random_walk_B.x_mw
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 64;
	
	  ;% random_walk_B.LoadSelectSwitch
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 65;
	
	  ;% random_walk_B.BehaviorRW_o1
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 67;
	
	  ;% random_walk_B.BehaviorRW_o2
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 69;
	
	  ;% random_walk_B.BehaviorRW_o3
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 74;
	
	  ;% random_walk_B.BehaviorRW_o4
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 75;
	
	  ;% random_walk_B.BehaviorRW_o5
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 85;
	
	  ;% random_walk_B.BehaviorRW_o6
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 86;
	
	  ;% random_walk_B.BehaviorRW_o7
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 88;
	
	  ;% random_walk_B.BehaviorRW_o8
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 92;
	
	  ;% random_walk_B.Switch2
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 94;
	
	  ;% random_walk_B.MG1
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 96;
	
	  ;% random_walk_B.MG2
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 97;
	
	  ;% random_walk_B.Clock_k
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 98;
	
	  ;% random_walk_B.HiddenBuf_InsertedFor_Sampleand
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 99;
	
	  ;% random_walk_B.Sum_l
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 100;
	
	  ;% random_walk_B.UniformRandomNumber
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 101;
	
	  ;% random_walk_B.Switch_l
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 102;
	
	  ;% random_walk_B.HiddenBuf_InsertedFor_Samplea_d
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 103;
	
	  ;% random_walk_B.DataTypeConversion
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 104;
	
	  ;% random_walk_B.y
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 105;
	
	  ;% random_walk_B.Add1
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 106;
	
	  ;% random_walk_B.z
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 107;
	
	  ;% random_walk_B.Add3
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 108;
	
	  ;% random_walk_B.product2
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 109;
	
	  ;% random_walk_B.Add2
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 110;
	
	  ;% random_walk_B.product3
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 111;
	
	  ;% random_walk_B.product4
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 112;
	
	  ;% random_walk_B.Add4
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 113;
	
	  ;% random_walk_B.product1
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 114;
	
	  ;% random_walk_B.dX
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 115;
	
	  ;% random_walk_B.AddX
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 116;
	
	  ;% random_walk_B.dY
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 117;
	
	  ;% random_walk_B.AddX1
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 118;
	
	  ;% random_walk_B.dZ
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 119;
	
	  ;% random_walk_B.AddX2
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 120;
	
	  ;% random_walk_B.y_m
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 121;
	
	  ;% random_walk_B.Add1_m
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 122;
	
	  ;% random_walk_B.z_e
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 123;
	
	  ;% random_walk_B.Add3_h
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 124;
	
	  ;% random_walk_B.product2_p
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 125;
	
	  ;% random_walk_B.Add2_e
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 126;
	
	  ;% random_walk_B.product3_c
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 127;
	
	  ;% random_walk_B.product4_j
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 128;
	
	  ;% random_walk_B.Add4_e
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 129;
	
	  ;% random_walk_B.product1_i
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 130;
	
	  ;% random_walk_B.dX_o
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 131;
	
	  ;% random_walk_B.AddX_o
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 132;
	
	  ;% random_walk_B.dY_g
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 133;
	
	  ;% random_walk_B.AddX1_l
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 134;
	
	  ;% random_walk_B.dZ_o
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 135;
	
	  ;% random_walk_B.AddX2_l
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 136;
	
	  ;% random_walk_B.y_f
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 137;
	
	  ;% random_walk_B.Add1_mk
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 138;
	
	  ;% random_walk_B.z_g
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 139;
	
	  ;% random_walk_B.Add3_c
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 140;
	
	  ;% random_walk_B.product2_e
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 141;
	
	  ;% random_walk_B.Add2_k
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 142;
	
	  ;% random_walk_B.product3_o
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 143;
	
	  ;% random_walk_B.product4_o
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 144;
	
	  ;% random_walk_B.Add4_el
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 145;
	
	  ;% random_walk_B.product1_a
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 146;
	
	  ;% random_walk_B.dX_p
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 147;
	
	  ;% random_walk_B.AddX_d
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 148;
	
	  ;% random_walk_B.dY_a
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 149;
	
	  ;% random_walk_B.AddX1_p
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 150;
	
	  ;% random_walk_B.dZ_m
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 151;
	
	  ;% random_walk_B.AddX2_b
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 152;
	
	  ;% random_walk_B.y_k
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 153;
	
	  ;% random_walk_B.Add1_c
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 154;
	
	  ;% random_walk_B.z_m
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 155;
	
	  ;% random_walk_B.Add3_hn
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 156;
	
	  ;% random_walk_B.product2_d
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 157;
	
	  ;% random_walk_B.Add2_g
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 158;
	
	  ;% random_walk_B.product3_i
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 159;
	
	  ;% random_walk_B.product4_i
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 160;
	
	  ;% random_walk_B.Add4_o
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 161;
	
	  ;% random_walk_B.product1_g
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 162;
	
	  ;% random_walk_B.dX_b
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 163;
	
	  ;% random_walk_B.AddX_b
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 164;
	
	  ;% random_walk_B.dY_n
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 165;
	
	  ;% random_walk_B.AddX1_lw
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 166;
	
	  ;% random_walk_B.dZ_n
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 167;
	
	  ;% random_walk_B.AddX2_a
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 168;
	
	  ;% random_walk_B.y_g
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 169;
	
	  ;% random_walk_B.Add1_o
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 170;
	
	  ;% random_walk_B.z_l
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 171;
	
	  ;% random_walk_B.Add3_j
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 172;
	
	  ;% random_walk_B.product2_c
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 173;
	
	  ;% random_walk_B.Add2_c
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 174;
	
	  ;% random_walk_B.product3_m
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 175;
	
	  ;% random_walk_B.product4_p
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 176;
	
	  ;% random_walk_B.Add4_b
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 177;
	
	  ;% random_walk_B.product1_e
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 178;
	
	  ;% random_walk_B.dX_l
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 179;
	
	  ;% random_walk_B.AddX_f
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 180;
	
	  ;% random_walk_B.dY_o
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 181;
	
	  ;% random_walk_B.AddX1_o
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 182;
	
	  ;% random_walk_B.dZ_j
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 183;
	
	  ;% random_walk_B.AddX2_f
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 184;
	
	  ;% random_walk_B.y_e
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 185;
	
	  ;% random_walk_B.Add1_b
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 186;
	
	  ;% random_walk_B.z_o
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 187;
	
	  ;% random_walk_B.Add3_e
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 188;
	
	  ;% random_walk_B.product2_l
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 189;
	
	  ;% random_walk_B.Add2_b
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 190;
	
	  ;% random_walk_B.product3_b
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 191;
	
	  ;% random_walk_B.product4_d
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 192;
	
	  ;% random_walk_B.Add4_bs
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 193;
	
	  ;% random_walk_B.product1_f
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 194;
	
	  ;% random_walk_B.dX_m
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 195;
	
	  ;% random_walk_B.AddX_j
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 196;
	
	  ;% random_walk_B.dY_f
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 197;
	
	  ;% random_walk_B.AddX1_b
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 198;
	
	  ;% random_walk_B.dZ_g
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 199;
	
	  ;% random_walk_B.AddX2_e
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 200;
	
	  ;% random_walk_B.y_j
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 201;
	
	  ;% random_walk_B.Add1_l
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 202;
	
	  ;% random_walk_B.z_n
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 203;
	
	  ;% random_walk_B.Add3_p
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 204;
	
	  ;% random_walk_B.product2_g
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 205;
	
	  ;% random_walk_B.Add2_l
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 206;
	
	  ;% random_walk_B.product3_d
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 207;
	
	  ;% random_walk_B.product4_j1
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 208;
	
	  ;% random_walk_B.Add4_k
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 209;
	
	  ;% random_walk_B.product1_ae
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 210;
	
	  ;% random_walk_B.dX_f
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 211;
	
	  ;% random_walk_B.AddX_on
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 212;
	
	  ;% random_walk_B.dY_b
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 213;
	
	  ;% random_walk_B.AddX1_j
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 214;
	
	  ;% random_walk_B.dZ_f
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 215;
	
	  ;% random_walk_B.AddX2_h
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 216;
	
	  ;% random_walk_B.y_o
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 217;
	
	  ;% random_walk_B.Add1_n
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 218;
	
	  ;% random_walk_B.z_j
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 219;
	
	  ;% random_walk_B.Add3_a
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 220;
	
	  ;% random_walk_B.product2_cg
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 221;
	
	  ;% random_walk_B.Add2_d
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 222;
	
	  ;% random_walk_B.product3_im
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 223;
	
	  ;% random_walk_B.product4_p0
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 224;
	
	  ;% random_walk_B.Add4_h
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 225;
	
	  ;% random_walk_B.product1_o
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 226;
	
	  ;% random_walk_B.dX_bi
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 227;
	
	  ;% random_walk_B.AddX_jl
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 228;
	
	  ;% random_walk_B.dY_na
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 229;
	
	  ;% random_walk_B.AddX1_bw
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 230;
	
	  ;% random_walk_B.dZ_i
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 231;
	
	  ;% random_walk_B.AddX2_g
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 232;
	
	  ;% random_walk_B.MatrixConcatenation1
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 233;
	
	  ;% random_walk_B.Add_oe
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 237;
	
	  ;% random_walk_B.Add1_f
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 238;
	
	  ;% random_walk_B.Gain_p
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 239;
	
	  ;% random_walk_B.Gain1_c
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 240;
	
	  ;% random_walk_B.ForIterator
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 241;
	
	  ;% random_walk_B.Switch_j
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 242;
	
	  ;% random_walk_B.ToBits1_o1
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 243;
	
	  ;% random_walk_B.ToBits1_o2
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 244;
	
	  ;% random_walk_B.ToBits1_o3
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 245;
	
	  ;% random_walk_B.ToBits1_o4
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 246;
	
	  ;% random_walk_B.ToBits1_o5
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 247;
	
	  ;% random_walk_B.ToBits1_o6
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 248;
	
	  ;% random_walk_B.ToBits1_o7
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 249;
	
	  ;% random_walk_B.ToBits1_o8
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 250;
	
	  ;% random_walk_B.Add_j
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 251;
	
	  ;% random_walk_B.Add1_oz
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 252;
	
	  ;% random_walk_B.SerialConverter
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 253;
	
	  ;% random_walk_B.ToBits_o1
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 254;
	
	  ;% random_walk_B.ToBits_o2
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 255;
	
	  ;% random_walk_B.ToBits_o3
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 256;
	
	  ;% random_walk_B.ToBits_o4
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 257;
	
	  ;% random_walk_B.ToBits_o5
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 258;
	
	  ;% random_walk_B.ToBits_o6
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 259;
	
	  ;% random_walk_B.ToBits_o7
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 260;
	
	  ;% random_walk_B.ToBits_o8
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 261;
	
	  ;% random_walk_B.xPCTargetTime
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 262;
	
	  ;% random_walk_B.xPCTargetTime_a
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 263;
	
	  ;% random_walk_B.Subtract
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 264;
	
	  ;% random_walk_B.ScaleTouSec
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 265;
	
	  ;% random_walk_B.Switch_g
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 266;
	
	  ;% random_walk_B.TachGain2
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 267;
	
	  ;% random_walk_B.TachGain1
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 268;
	
	  ;% random_walk_B.TmpHiddenBufferAtMatrixMultiply
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 269;
	
	  ;% random_walk_B.MatrixMultiply
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 271;
	
	  ;% random_walk_B.Gain_o
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 273;
	
	  ;% random_walk_B.MathFunction
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 275;
	
	  ;% random_walk_B.MatrixMultiply_k
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 279;
	
	  ;% random_walk_B.Switch1
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 281;
	
	  ;% random_walk_B.Switch_c
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 283;
	
	  ;% random_walk_B.BoundingBoxViscosity
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 285;
	
	  ;% random_walk_B.Product_n
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 287;
	
	  ;% random_walk_B.Gain1_n
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 288;
	
	  ;% random_walk_B.Gain3
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 289;
	
	  ;% random_walk_B.Add_c
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 290;
	
	  ;% random_walk_B.Saturation
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 291;
	
	  ;% random_walk_B.Gain4
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 292;
	
	  ;% random_walk_B.Product1_j
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 293;
	
	  ;% random_walk_B.Gain2
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 294;
	
	  ;% random_walk_B.Add1_d
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 295;
	
	  ;% random_walk_B.Saturation1
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 296;
	
	  ;% random_walk_B.Add1_a
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 297;
	
	  ;% random_walk_B.LorentzForceGain
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 298;
	
	  ;% random_walk_B.dynamicAngleSwitch
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 300;
	
	  ;% random_walk_B.sin_e
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 301;
	
	  ;% random_walk_B.Inverter
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 302;
	
	  ;% random_walk_B.Product3_m
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 304;
	
	  ;% random_walk_B.cos_o
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 305;
	
	  ;% random_walk_B.Product2_m
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 306;
	
	  ;% random_walk_B.Subtract_j
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 307;
	
	  ;% random_walk_B.Product1_f
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 308;
	
	  ;% random_walk_B.Product_e
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 309;
	
	  ;% random_walk_B.Add_ci
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 310;
	
	  ;% random_walk_B.Gain_n
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 311;
	
	  ;% random_walk_B.Gain_d
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 313;
	
	  ;% random_walk_B.Add1_b1
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 314;
	
	  ;% random_walk_B.LorentzForceGain_j
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 315;
	
	  ;% random_walk_B.DynamicAngleSwitch
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 317;
	
	  ;% random_walk_B.sin_l
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 318;
	
	  ;% random_walk_B.Inverter_a
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 319;
	
	  ;% random_walk_B.Product3_g
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 321;
	
	  ;% random_walk_B.cos_j
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 322;
	
	  ;% random_walk_B.Product2_j
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 323;
	
	  ;% random_walk_B.Subtract_g
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 324;
	
	  ;% random_walk_B.Product1_jf
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 325;
	
	  ;% random_walk_B.Product_d
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 326;
	
	  ;% random_walk_B.Add_p
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 327;
	
	  ;% random_walk_B.Gain_a
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 328;
	
	  ;% random_walk_B.Gain_b
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 330;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% random_walk_B.Compare
	  section.data(1).logicalSrcIdx = 286;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_B.Compare_j
	  section.data(2).logicalSrcIdx = 287;
	  section.data(2).dtTransOffset = 1;
	
	  ;% random_walk_B.Compare_m
	  section.data(3).logicalSrcIdx = 288;
	  section.data(3).dtTransOffset = 2;
	
	  ;% random_walk_B.Compare_j0
	  section.data(4).logicalSrcIdx = 289;
	  section.data(4).dtTransOffset = 3;
	
	  ;% random_walk_B.Compare_h
	  section.data(5).logicalSrcIdx = 290;
	  section.data(5).dtTransOffset = 4;
	
	  ;% random_walk_B.Uk1
	  section.data(6).logicalSrcIdx = 291;
	  section.data(6).dtTransOffset = 5;
	
	  ;% random_walk_B.FixPtRelationalOperator
	  section.data(7).logicalSrcIdx = 292;
	  section.data(7).dtTransOffset = 6;
	
	  ;% random_walk_B.Compare_l
	  section.data(8).logicalSrcIdx = 293;
	  section.data(8).dtTransOffset = 7;
	
	  ;% random_walk_B.Compare_o
	  section.data(9).logicalSrcIdx = 294;
	  section.data(9).dtTransOffset = 8;
	
	  ;% random_walk_B.Compare_d
	  section.data(10).logicalSrcIdx = 295;
	  section.data(10).dtTransOffset = 9;
	
	  ;% random_walk_B.Compare_g
	  section.data(11).logicalSrcIdx = 296;
	  section.data(11).dtTransOffset = 10;
	
	  ;% random_walk_B.Uk1_j
	  section.data(12).logicalSrcIdx = 297;
	  section.data(12).dtTransOffset = 11;
	
	  ;% random_walk_B.FixPtRelationalOperator_m
	  section.data(13).logicalSrcIdx = 298;
	  section.data(13).dtTransOffset = 12;
	
	  ;% random_walk_B.Compare_d1
	  section.data(14).logicalSrcIdx = 299;
	  section.data(14).dtTransOffset = 13;
	
	  ;% random_walk_B.Compare_n
	  section.data(15).logicalSrcIdx = 300;
	  section.data(15).dtTransOffset = 14;
	
	  ;% random_walk_B.Uk1_n
	  section.data(16).logicalSrcIdx = 301;
	  section.data(16).dtTransOffset = 15;
	
	  ;% random_walk_B.FixPtRelationalOperator_d
	  section.data(17).logicalSrcIdx = 302;
	  section.data(17).dtTransOffset = 16;
	
	  ;% random_walk_B.Compare_f
	  section.data(18).logicalSrcIdx = 303;
	  section.data(18).dtTransOffset = 17;
	
	  ;% random_walk_B.Compare_my
	  section.data(19).logicalSrcIdx = 304;
	  section.data(19).dtTransOffset = 18;
	
	  ;% random_walk_B.Uk1_i
	  section.data(20).logicalSrcIdx = 305;
	  section.data(20).dtTransOffset = 19;
	
	  ;% random_walk_B.FixPtRelationalOperator_b
	  section.data(21).logicalSrcIdx = 306;
	  section.data(21).dtTransOffset = 20;
	
	  ;% random_walk_B.Compare_a
	  section.data(22).logicalSrcIdx = 307;
	  section.data(22).dtTransOffset = 21;
	
	  ;% random_walk_B.Compare_h2
	  section.data(23).logicalSrcIdx = 308;
	  section.data(23).dtTransOffset = 22;
	
	  ;% random_walk_B.Pack
	  section.data(24).logicalSrcIdx = 309;
	  section.data(24).dtTransOffset = 23;
	
	  ;% random_walk_B.RateTransition
	  section.data(25).logicalSrcIdx = 310;
	  section.data(25).dtTransOffset = 135;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 57;
      section.data(57)  = dumData; %prealloc
      
	  ;% random_walk_B.Memory
	  section.data(1).logicalSrcIdx = 311;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_B.Memory_e
	  section.data(2).logicalSrcIdx = 312;
	  section.data(2).dtTransOffset = 1;
	
	  ;% random_walk_B.LogicalOperator2
	  section.data(3).logicalSrcIdx = 313;
	  section.data(3).dtTransOffset = 2;
	
	  ;% random_walk_B.LogicalOperator1
	  section.data(4).logicalSrcIdx = 314;
	  section.data(4).dtTransOffset = 3;
	
	  ;% random_walk_B.HiddenBuf_InsertedFor_EnabledSu
	  section.data(5).logicalSrcIdx = 315;
	  section.data(5).dtTransOffset = 4;
	
	  ;% random_walk_B.RelationalOperator
	  section.data(6).logicalSrcIdx = 316;
	  section.data(6).dtTransOffset = 5;
	
	  ;% random_walk_B.LogicalOperator
	  section.data(7).logicalSrcIdx = 317;
	  section.data(7).dtTransOffset = 6;
	
	  ;% random_walk_B.Memory_i
	  section.data(8).logicalSrcIdx = 318;
	  section.data(8).dtTransOffset = 7;
	
	  ;% random_walk_B.RelationalOperator_n
	  section.data(9).logicalSrcIdx = 319;
	  section.data(9).dtTransOffset = 8;
	
	  ;% random_walk_B.RelationalOperator1
	  section.data(10).logicalSrcIdx = 320;
	  section.data(10).dtTransOffset = 9;
	
	  ;% random_walk_B.RelationalOperator2
	  section.data(11).logicalSrcIdx = 321;
	  section.data(11).dtTransOffset = 10;
	
	  ;% random_walk_B.RelationalOperator3
	  section.data(12).logicalSrcIdx = 322;
	  section.data(12).dtTransOffset = 11;
	
	  ;% random_walk_B.LogicalOperator_a
	  section.data(13).logicalSrcIdx = 323;
	  section.data(13).dtTransOffset = 12;
	
	  ;% random_walk_B.InBox
	  section.data(14).logicalSrcIdx = 324;
	  section.data(14).dtTransOffset = 13;
	
	  ;% random_walk_B.LogicalOperator3
	  section.data(15).logicalSrcIdx = 325;
	  section.data(15).dtTransOffset = 14;
	
	  ;% random_walk_B.Memory_e5
	  section.data(16).logicalSrcIdx = 326;
	  section.data(16).dtTransOffset = 15;
	
	  ;% random_walk_B.LogicalOperator4
	  section.data(17).logicalSrcIdx = 327;
	  section.data(17).dtTransOffset = 16;
	
	  ;% random_walk_B.LogicalOperator_i
	  section.data(18).logicalSrcIdx = 328;
	  section.data(18).dtTransOffset = 17;
	
	  ;% random_walk_B.LogicalOperator2_m
	  section.data(19).logicalSrcIdx = 329;
	  section.data(19).dtTransOffset = 18;
	
	  ;% random_walk_B.LogicalOperator1_f
	  section.data(20).logicalSrcIdx = 330;
	  section.data(20).dtTransOffset = 19;
	
	  ;% random_walk_B.HiddenBuf_InsertedFor_Enabled_k
	  section.data(21).logicalSrcIdx = 331;
	  section.data(21).dtTransOffset = 20;
	
	  ;% random_walk_B.RelationalOperator_p
	  section.data(22).logicalSrcIdx = 332;
	  section.data(22).dtTransOffset = 21;
	
	  ;% random_walk_B.LogicalOperator_ai
	  section.data(23).logicalSrcIdx = 333;
	  section.data(23).dtTransOffset = 22;
	
	  ;% random_walk_B.LogicalOperator5
	  section.data(24).logicalSrcIdx = 334;
	  section.data(24).dtTransOffset = 23;
	
	  ;% random_walk_B.LogicalOperator2_o
	  section.data(25).logicalSrcIdx = 335;
	  section.data(25).dtTransOffset = 24;
	
	  ;% random_walk_B.LogicalOperator1_p
	  section.data(26).logicalSrcIdx = 336;
	  section.data(26).dtTransOffset = 25;
	
	  ;% random_walk_B.HiddenBuf_InsertedFor_Enabled_m
	  section.data(27).logicalSrcIdx = 337;
	  section.data(27).dtTransOffset = 26;
	
	  ;% random_walk_B.RelationalOperator_c
	  section.data(28).logicalSrcIdx = 338;
	  section.data(28).dtTransOffset = 27;
	
	  ;% random_walk_B.LogicalOperator_if
	  section.data(29).logicalSrcIdx = 339;
	  section.data(29).dtTransOffset = 28;
	
	  ;% random_walk_B.LogicalOperator1_d
	  section.data(30).logicalSrcIdx = 340;
	  section.data(30).dtTransOffset = 29;
	
	  ;% random_walk_B.NOT
	  section.data(31).logicalSrcIdx = 341;
	  section.data(31).dtTransOffset = 30;
	
	  ;% random_walk_B.Memory_o
	  section.data(32).logicalSrcIdx = 342;
	  section.data(32).dtTransOffset = 31;
	
	  ;% random_walk_B.LogicalOperator2_j
	  section.data(33).logicalSrcIdx = 343;
	  section.data(33).dtTransOffset = 32;
	
	  ;% random_walk_B.LogicalOperator1_i
	  section.data(34).logicalSrcIdx = 344;
	  section.data(34).dtTransOffset = 33;
	
	  ;% random_walk_B.HiddenBuf_InsertedFor_Enabled_a
	  section.data(35).logicalSrcIdx = 345;
	  section.data(35).dtTransOffset = 34;
	
	  ;% random_walk_B.RelationalOperator_pq
	  section.data(36).logicalSrcIdx = 346;
	  section.data(36).dtTransOffset = 35;
	
	  ;% random_walk_B.LogicalOperator_b
	  section.data(37).logicalSrcIdx = 347;
	  section.data(37).dtTransOffset = 36;
	
	  ;% random_walk_B.DataTypeConversion2
	  section.data(38).logicalSrcIdx = 348;
	  section.data(38).dtTransOffset = 37;
	
	  ;% random_walk_B.LogicalOperator1_a
	  section.data(39).logicalSrcIdx = 349;
	  section.data(39).dtTransOffset = 38;
	
	  ;% random_walk_B.Memory_j
	  section.data(40).logicalSrcIdx = 350;
	  section.data(40).dtTransOffset = 39;
	
	  ;% random_walk_B.LogicalOperator2_mi
	  section.data(41).logicalSrcIdx = 351;
	  section.data(41).dtTransOffset = 40;
	
	  ;% random_walk_B.LogicalOperator1_pq
	  section.data(42).logicalSrcIdx = 352;
	  section.data(42).dtTransOffset = 41;
	
	  ;% random_walk_B.HiddenBuf_InsertedFor_Enabled_i
	  section.data(43).logicalSrcIdx = 353;
	  section.data(43).dtTransOffset = 42;
	
	  ;% random_walk_B.RelationalOperator_l
	  section.data(44).logicalSrcIdx = 354;
	  section.data(44).dtTransOffset = 43;
	
	  ;% random_walk_B.LogicalOperator_e
	  section.data(45).logicalSrcIdx = 355;
	  section.data(45).dtTransOffset = 44;
	
	  ;% random_walk_B.DataTypeConversion1
	  section.data(46).logicalSrcIdx = 356;
	  section.data(46).dtTransOffset = 45;
	
	  ;% random_walk_B.Memory_jh
	  section.data(47).logicalSrcIdx = 357;
	  section.data(47).dtTransOffset = 46;
	
	  ;% random_walk_B.Logic
	  section.data(48).logicalSrcIdx = 358;
	  section.data(48).dtTransOffset = 47;
	
	  ;% random_walk_B.LogicalOperator5_h
	  section.data(49).logicalSrcIdx = 359;
	  section.data(49).dtTransOffset = 49;
	
	  ;% random_walk_B.LogicalOperator1_b
	  section.data(50).logicalSrcIdx = 360;
	  section.data(50).dtTransOffset = 50;
	
	  ;% random_walk_B.MatrixConcatenation
	  section.data(51).logicalSrcIdx = 361;
	  section.data(51).dtTransOffset = 51;
	
	  ;% random_walk_B.RelationalOperator_e
	  section.data(52).logicalSrcIdx = 362;
	  section.data(52).dtTransOffset = 53;
	
	  ;% random_walk_B.RelationalOperator_o
	  section.data(53).logicalSrcIdx = 363;
	  section.data(53).dtTransOffset = 54;
	
	  ;% random_walk_B.Compare_nw
	  section.data(54).logicalSrcIdx = 364;
	  section.data(54).dtTransOffset = 55;
	
	  ;% random_walk_B.Compare_h0
	  section.data(55).logicalSrcIdx = 365;
	  section.data(55).dtTransOffset = 56;
	
	  ;% random_walk_B.LogicalOperator6
	  section.data(56).logicalSrcIdx = 366;
	  section.data(56).dtTransOffset = 57;
	
	  ;% random_walk_B.LogicalOperator3_d
	  section.data(57).logicalSrcIdx = 367;
	  section.data(57).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_B.SampleandHold.In
	  section.data(1).logicalSrcIdx = 368;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_B.SampleandHold_g.In
	  section.data(1).logicalSrcIdx = 369;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_B.EnabledSubsystem_l.In1
	  section.data(1).logicalSrcIdx = 370;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_B.EnabledSubsystem_o.In1
	  section.data(1).logicalSrcIdx = 371;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_B.EnabledSubsystem_n.In1
	  section.data(1).logicalSrcIdx = 372;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_B.EnabledSubsystem_d.In1
	  section.data(1).logicalSrcIdx = 373;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_B.EnabledSubsystem.In1
	  section.data(1).logicalSrcIdx = 374;
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
    ;% Auto data (random_walk_DWork)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% random_walk_DWork.DigitalFilter2_FILT_STATES
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_DWork.DigitalFilter_FILT_STATES
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 11;
	
	  ;% random_walk_DWork.DigitalFilter2_FILT_STATES_a
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 22;
	
	  ;% random_walk_DWork.DigitalFilter_FILT_STATES_m
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 33;
	
	  ;% random_walk_DWork.x_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 44;
	
	  ;% random_walk_DWork.x_DSTATE_m
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 45;
	
	  ;% random_walk_DWork.x_DSTATE_d
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 46;
	
	  ;% random_walk_DWork.x_DSTATE_k
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 47;
	
	  ;% random_walk_DWork.x_DSTATE_b
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 48;
	
	  ;% random_walk_DWork.x_DSTATE_g
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 49;
	
	  ;% random_walk_DWork.x_DSTATE_l
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 50;
	
	  ;% random_walk_DWork.x_DSTATE_n
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 51;
	
	  ;% random_walk_DWork.BehaviorRW_DSTATE
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 52;
	
	  ;% random_walk_DWork.y_DSTATE
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 53;
	
	  ;% random_walk_DWork.z_DSTATE
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 54;
	
	  ;% random_walk_DWork.y_DSTATE_j
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 55;
	
	  ;% random_walk_DWork.z_DSTATE_d
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 56;
	
	  ;% random_walk_DWork.y_DSTATE_c
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 57;
	
	  ;% random_walk_DWork.z_DSTATE_b
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 58;
	
	  ;% random_walk_DWork.y_DSTATE_l
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 59;
	
	  ;% random_walk_DWork.z_DSTATE_j
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 60;
	
	  ;% random_walk_DWork.y_DSTATE_k
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 61;
	
	  ;% random_walk_DWork.z_DSTATE_m
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 62;
	
	  ;% random_walk_DWork.y_DSTATE_ky
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 63;
	
	  ;% random_walk_DWork.z_DSTATE_f
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 64;
	
	  ;% random_walk_DWork.y_DSTATE_n
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 65;
	
	  ;% random_walk_DWork.z_DSTATE_dr
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 66;
	
	  ;% random_walk_DWork.y_DSTATE_d
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 67;
	
	  ;% random_walk_DWork.z_DSTATE_dv
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 68;
	
	  ;% random_walk_DWork.PCI6025EAD_RWORK
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 69;
	
	  ;% random_walk_DWork.Derivative_RWORK.TimeStampA
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 133;
	
	  ;% random_walk_DWork.Derivative_RWORK_a.TimeStampA
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 134;
	
	  ;% random_walk_DWork.BehaviorRW_RWORK
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 135;
	
	  ;% random_walk_DWork.PCI6025E_RWORK
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 647;
	
	  ;% random_walk_DWork.UniformRandomNumber_RWORK.NextOutput
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 653;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% random_walk_DWork.BehaviorRW_PWORK
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_DWork.Send_PWORK
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% random_walk_DWork.DigitalFilter2_CIRCBUFFIDX
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_DWork.DigitalFilter_CIRCBUFFIDX
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% random_walk_DWork.DigitalFilter2_CIRCBUFFIDX_a
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
	  ;% random_walk_DWork.DigitalFilter_CIRCBUFFIDX_d
	  section.data(4).logicalSrcIdx = 40;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% random_walk_DWork.PCIQUAD04_IWORK
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_DWork.PCIQUAD041_IWORK
	  section.data(2).logicalSrcIdx = 42;
	  section.data(2).dtTransOffset = 1;
	
	  ;% random_walk_DWork.PCI6025EAD_IWORK
	  section.data(3).logicalSrcIdx = 43;
	  section.data(3).dtTransOffset = 2;
	
	  ;% random_walk_DWork.BehaviorRW_IWORK
	  section.data(4).logicalSrcIdx = 44;
	  section.data(4).dtTransOffset = 68;
	
	  ;% random_walk_DWork.PCI6025E_IWORK
	  section.data(5).logicalSrcIdx = 45;
	  section.data(5).dtTransOffset = 75;
	
	  ;% random_walk_DWork.SFunction_IWORK.AcquireOK
	  section.data(6).logicalSrcIdx = 46;
	  section.data(6).dtTransOffset = 77;
	
	  ;% random_walk_DWork.SFunction_IWORK_p.AcquireOK
	  section.data(7).logicalSrcIdx = 47;
	  section.data(7).dtTransOffset = 78;
	
	  ;% random_walk_DWork.SFunction_IWORK_o.AcquireOK
	  section.data(8).logicalSrcIdx = 48;
	  section.data(8).dtTransOffset = 79;
	
	  ;% random_walk_DWork.Send_IWORK
	  section.data(9).logicalSrcIdx = 49;
	  section.data(9).dtTransOffset = 80;
	
	  ;% random_walk_DWork.SFunction_IWORK_j.AcquireOK
	  section.data(10).logicalSrcIdx = 50;
	  section.data(10).dtTransOffset = 82;
	
	  ;% random_walk_DWork.SFunction_IWORK_c.AcquireOK
	  section.data(11).logicalSrcIdx = 51;
	  section.data(11).dtTransOffset = 83;
	
	  ;% random_walk_DWork.SFunction_IWORK_i.AcquireOK
	  section.data(12).logicalSrcIdx = 52;
	  section.data(12).dtTransOffset = 84;
	
	  ;% random_walk_DWork.UniformRandomNumber_IWORK.RandSeed
	  section.data(13).logicalSrcIdx = 53;
	  section.data(13).dtTransOffset = 85;
	
	  ;% random_walk_DWork.PortA_IWORK
	  section.data(14).logicalSrcIdx = 54;
	  section.data(14).dtTransOffset = 86;
	
	  ;% random_walk_DWork.PortB_IWORK
	  section.data(15).logicalSrcIdx = 55;
	  section.data(15).dtTransOffset = 88;
	
	  ;% random_walk_DWork.PCI6025E_IWORK_d
	  section.data(16).logicalSrcIdx = 56;
	  section.data(16).dtTransOffset = 90;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% random_walk_DWork.DelayInput1_DSTATE
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_DWork.DelayInput1_DSTATE_h
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 1;
	
	  ;% random_walk_DWork.DelayInput1_DSTATE_k
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 2;
	
	  ;% random_walk_DWork.DelayInput1_DSTATE_f
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% random_walk_DWork.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% random_walk_DWork.Memory_PreviousInput_i
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 1;
	
	  ;% random_walk_DWork.Memory_PreviousInput_c
	  section.data(3).logicalSrcIdx = 63;
	  section.data(3).dtTransOffset = 2;
	
	  ;% random_walk_DWork.Memory_PreviousInput_e
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 3;
	
	  ;% random_walk_DWork.Memory_PreviousInput_d
	  section.data(5).logicalSrcIdx = 65;
	  section.data(5).dtTransOffset = 4;
	
	  ;% random_walk_DWork.Memory_PreviousInput_b
	  section.data(6).logicalSrcIdx = 66;
	  section.data(6).dtTransOffset = 5;
	
	  ;% random_walk_DWork.Memory_PreviousInput_h
	  section.data(7).logicalSrcIdx = 67;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.SampleandHold.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.SampleandHold_g.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.EnabledSubsystem_l.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.EnabledSubsystem_o.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.EnabledSubsystem_o.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.EnabledSubsystem_n.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.EnabledSubsystem_n.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.EnabledSubsystem_d.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.EnabledSubsystem_d.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.EnabledSubsystem.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% random_walk_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC
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


  targMap.checksum0 = 4260132490;
  targMap.checksum1 = 2437341772;
  targMap.checksum2 = 238009788;
  targMap.checksum3 = 3085687669;

