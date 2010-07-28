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
    ;% Auto data (forced_choice_P)
    ;%
      section.nData     = 308;
      section.data(308)  = dumData; %prealloc
      
	  ;% forced_choice_P.Time_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_P.PCIQUAD04_P1_Size
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_P.PCIQUAD04_P1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% forced_choice_P.PCIQUAD04_P2_Size
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% forced_choice_P.PCIQUAD04_P2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% forced_choice_P.PCIQUAD04_P3_Size
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% forced_choice_P.PCIQUAD04_P3
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% forced_choice_P.PCIQUAD04_P4_Size
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% forced_choice_P.PCIQUAD04_P4
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% forced_choice_P.PCIQUAD04_P5_Size
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% forced_choice_P.PCIQUAD04_P5
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% forced_choice_P.PCIQUAD04_P6_Size
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% forced_choice_P.PCIQUAD04_P6
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% forced_choice_P.PCIQUAD04_P7_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% forced_choice_P.PCIQUAD04_P7
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% forced_choice_P.PCIQUAD04_P8_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% forced_choice_P.PCIQUAD04_P8
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% forced_choice_P.PCIQUAD04_P9_Size
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 25;
	
	  ;% forced_choice_P.PCIQUAD04_P9
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 27;
	
	  ;% forced_choice_P.PCIQUAD04_P10_Size
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 28;
	
	  ;% forced_choice_P.PCIQUAD04_P10
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 30;
	
	  ;% forced_choice_P.PCIQUAD04_P11_Size
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 31;
	
	  ;% forced_choice_P.PCIQUAD04_P11
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 33;
	
	  ;% forced_choice_P.Gain_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 34;
	
	  ;% forced_choice_P.shoulderOffset_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 35;
	
	  ;% forced_choice_P.L1_Value
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 36;
	
	  ;% forced_choice_P.Gain_Gain_m
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 37;
	
	  ;% forced_choice_P.PCIQUAD041_P1_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 38;
	
	  ;% forced_choice_P.PCIQUAD041_P1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 40;
	
	  ;% forced_choice_P.PCIQUAD041_P2_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 41;
	
	  ;% forced_choice_P.PCIQUAD041_P2
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 43;
	
	  ;% forced_choice_P.PCIQUAD041_P3_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 44;
	
	  ;% forced_choice_P.PCIQUAD041_P3
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 46;
	
	  ;% forced_choice_P.PCIQUAD041_P4_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 47;
	
	  ;% forced_choice_P.PCIQUAD041_P4
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 49;
	
	  ;% forced_choice_P.PCIQUAD041_P5_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 50;
	
	  ;% forced_choice_P.PCIQUAD041_P5
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 52;
	
	  ;% forced_choice_P.PCIQUAD041_P6_Size
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 53;
	
	  ;% forced_choice_P.PCIQUAD041_P6
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 55;
	
	  ;% forced_choice_P.PCIQUAD041_P7_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 56;
	
	  ;% forced_choice_P.PCIQUAD041_P7
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 58;
	
	  ;% forced_choice_P.PCIQUAD041_P8_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 59;
	
	  ;% forced_choice_P.PCIQUAD041_P8
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 61;
	
	  ;% forced_choice_P.PCIQUAD041_P9_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 62;
	
	  ;% forced_choice_P.PCIQUAD041_P9
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 64;
	
	  ;% forced_choice_P.PCIQUAD041_P10_Size
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 65;
	
	  ;% forced_choice_P.PCIQUAD041_P10
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 67;
	
	  ;% forced_choice_P.PCIQUAD041_P11_Size
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 68;
	
	  ;% forced_choice_P.PCIQUAD041_P11
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 70;
	
	  ;% forced_choice_P.Gain1_Gain
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 71;
	
	  ;% forced_choice_P.elbowOffset_Value
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 72;
	
	  ;% forced_choice_P.L2_Value
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 73;
	
	  ;% forced_choice_P.Gain1_Gain_m
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 74;
	
	  ;% forced_choice_P.Gain2_Gain
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 75;
	
	  ;% forced_choice_P.PCI6025EAD_P1_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 76;
	
	  ;% forced_choice_P.PCI6025EAD_P1
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 78;
	
	  ;% forced_choice_P.PCI6025EAD_P2_Size
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 80;
	
	  ;% forced_choice_P.PCI6025EAD_P2
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 82;
	
	  ;% forced_choice_P.PCI6025EAD_P3_Size
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 84;
	
	  ;% forced_choice_P.PCI6025EAD_P3
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 86;
	
	  ;% forced_choice_P.PCI6025EAD_P4_Size
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 88;
	
	  ;% forced_choice_P.PCI6025EAD_P4
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 90;
	
	  ;% forced_choice_P.PCI6025EAD_P5_Size
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 91;
	
	  ;% forced_choice_P.PCI6025EAD_P5
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 93;
	
	  ;% forced_choice_P.PCI6025EAD_P6_Size
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 94;
	
	  ;% forced_choice_P.PCI6025EAD_P6
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 96;
	
	  ;% forced_choice_P.UseTachs_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 97;
	
	  ;% forced_choice_P.yoffset_Value
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 98;
	
	  ;% forced_choice_P.xoffset_Value
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 99;
	
	  ;% forced_choice_P.AngleOffset_Value
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 100;
	
	  ;% forced_choice_P.DigitalFilter2_ICRTP
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 101;
	
	  ;% forced_choice_P.DigitalFilter2_RTP1COEFF
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 102;
	
	  ;% forced_choice_P.dG_Gain
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 113;
	
	  ;% forced_choice_P.DigitalFilter_ICRTP
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 114;
	
	  ;% forced_choice_P.DigitalFilter_RTP1COEFF
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 115;
	
	  ;% forced_choice_P.DigitalFilter2_ICRTP_l
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 126;
	
	  ;% forced_choice_P.DigitalFilter2_RTP1COEFF_m
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 127;
	
	  ;% forced_choice_P.dG_Gain_d
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 138;
	
	  ;% forced_choice_P.DigitalFilter_ICRTP_h
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 139;
	
	  ;% forced_choice_P.DigitalFilter_RTP1COEFF_p
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 140;
	
	  ;% forced_choice_P.Switch_Threshold
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 151;
	
	  ;% forced_choice_P.XLowLimit_Value
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 152;
	
	  ;% forced_choice_P.XHighLimit_Value
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 153;
	
	  ;% forced_choice_P.YHighLimit_Value
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 154;
	
	  ;% forced_choice_P.YLowLimit_Value
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 155;
	
	  ;% forced_choice_P.RecenterFlag_Value
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 156;
	
	  ;% forced_choice_P.Time_Value_o
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 157;
	
	  ;% forced_choice_P.Time_Value_n
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 158;
	
	  ;% forced_choice_P.Constant_Value
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 159;
	
	  ;% forced_choice_P.Constant_Value_l
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 160;
	
	  ;% forced_choice_P.Time_Value_m
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 161;
	
	  ;% forced_choice_P.Time_Value_c
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 162;
	
	  ;% forced_choice_P.Load_Value
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 163;
	
	  ;% forced_choice_P.x_X0
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 164;
	
	  ;% forced_choice_P.x_X0_f
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 165;
	
	  ;% forced_choice_P.x_X0_l
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 166;
	
	  ;% forced_choice_P.x_X0_c
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 167;
	
	  ;% forced_choice_P.Load_Value_d
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 168;
	
	  ;% forced_choice_P.x_X0_m
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 169;
	
	  ;% forced_choice_P.x_X0_j
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 170;
	
	  ;% forced_choice_P.x_X0_g
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 171;
	
	  ;% forced_choice_P.x_X0_lz
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 172;
	
	  ;% forced_choice_P.BehaviorFC_P1_Size
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 173;
	
	  ;% forced_choice_P.BehaviorFC_P1
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 175;
	
	  ;% forced_choice_P.BehaviorFC_P2_Size
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 176;
	
	  ;% forced_choice_P.BehaviorFC_P2
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 178;
	
	  ;% forced_choice_P.BehaviorFC_P3_Size
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 179;
	
	  ;% forced_choice_P.BehaviorFC_P3
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 181;
	
	  ;% forced_choice_P.BehaviorFC_P4_Size
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 182;
	
	  ;% forced_choice_P.BehaviorFC_P4
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 184;
	
	  ;% forced_choice_P.BehaviorFC_P5_Size
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 185;
	
	  ;% forced_choice_P.BehaviorFC_P5
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 187;
	
	  ;% forced_choice_P.BehaviorFC_P6_Size
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 188;
	
	  ;% forced_choice_P.BehaviorFC_P6
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 190;
	
	  ;% forced_choice_P.BehaviorFC_P7_Size
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 191;
	
	  ;% forced_choice_P.BehaviorFC_P7
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 193;
	
	  ;% forced_choice_P.BehaviorFC_P8_Size
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 194;
	
	  ;% forced_choice_P.BehaviorFC_P8
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 196;
	
	  ;% forced_choice_P.BehaviorFC_P9_Size
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 197;
	
	  ;% forced_choice_P.BehaviorFC_P9
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 199;
	
	  ;% forced_choice_P.BehaviorFC_P10_Size
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 200;
	
	  ;% forced_choice_P.BehaviorFC_P10
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 202;
	
	  ;% forced_choice_P.BehaviorFC_P11_Size
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 203;
	
	  ;% forced_choice_P.BehaviorFC_P11
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 205;
	
	  ;% forced_choice_P.BehaviorFC_P12_Size
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 206;
	
	  ;% forced_choice_P.BehaviorFC_P12
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 208;
	
	  ;% forced_choice_P.BehaviorFC_P13_Size
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 209;
	
	  ;% forced_choice_P.BehaviorFC_P13
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 211;
	
	  ;% forced_choice_P.MG1_Gain
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 212;
	
	  ;% forced_choice_P.MG2_Gain
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 213;
	
	  ;% forced_choice_P.PCI6025E_P1_Size
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 214;
	
	  ;% forced_choice_P.PCI6025E_P1
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 216;
	
	  ;% forced_choice_P.PCI6025E_P2_Size
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 218;
	
	  ;% forced_choice_P.PCI6025E_P2
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 220;
	
	  ;% forced_choice_P.PCI6025E_P3_Size
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 222;
	
	  ;% forced_choice_P.PCI6025E_P3
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 224;
	
	  ;% forced_choice_P.PCI6025E_P4_Size
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 226;
	
	  ;% forced_choice_P.PCI6025E_P4
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 228;
	
	  ;% forced_choice_P.PCI6025E_P5_Size
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 230;
	
	  ;% forced_choice_P.PCI6025E_P5
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 232;
	
	  ;% forced_choice_P.PCI6025E_P6_Size
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 233;
	
	  ;% forced_choice_P.PCI6025E_P6
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 235;
	
	  ;% forced_choice_P.PCI6025E_P7_Size
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 236;
	
	  ;% forced_choice_P.PCI6025E_P7
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 238;
	
	  ;% forced_choice_P.Constant_Value_o
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 239;
	
	  ;% forced_choice_P.Constant_Value_l0
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 240;
	
	  ;% forced_choice_P.Send_P1_Size
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 241;
	
	  ;% forced_choice_P.Send_P1
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 243;
	
	  ;% forced_choice_P.Send_P2_Size
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 254;
	
	  ;% forced_choice_P.Send_P2
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 256;
	
	  ;% forced_choice_P.Send_P3_Size
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 257;
	
	  ;% forced_choice_P.Send_P3
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 259;
	
	  ;% forced_choice_P.Send_P4_Size
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 260;
	
	  ;% forced_choice_P.Send_P4
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 262;
	
	  ;% forced_choice_P.UniformRandomNumber_Min
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 263;
	
	  ;% forced_choice_P.UniformRandomNumber_Max
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 264;
	
	  ;% forced_choice_P.UniformRandomNumber_Seed
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 265;
	
	  ;% forced_choice_P.JackpotChance_Value
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 266;
	
	  ;% forced_choice_P.y_X0
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 267;
	
	  ;% forced_choice_P.rho_Value
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 268;
	
	  ;% forced_choice_P.z_X0
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 269;
	
	  ;% forced_choice_P.beta_Value
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 270;
	
	  ;% forced_choice_P.timescale_Value
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 271;
	
	  ;% forced_choice_P.sigma_Value
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 272;
	
	  ;% forced_choice_P.y_X0_b
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 273;
	
	  ;% forced_choice_P.rho_Value_e
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 274;
	
	  ;% forced_choice_P.z_X0_o
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 275;
	
	  ;% forced_choice_P.beta_Value_g
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 276;
	
	  ;% forced_choice_P.timescale_Value_e
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 277;
	
	  ;% forced_choice_P.sigma_Value_b
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 278;
	
	  ;% forced_choice_P.y_X0_o
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 279;
	
	  ;% forced_choice_P.rho_Value_k
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 280;
	
	  ;% forced_choice_P.z_X0_c
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 281;
	
	  ;% forced_choice_P.beta_Value_h
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 282;
	
	  ;% forced_choice_P.timescale_Value_m
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 283;
	
	  ;% forced_choice_P.sigma_Value_g
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 284;
	
	  ;% forced_choice_P.y_X0_a
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 285;
	
	  ;% forced_choice_P.rho_Value_d
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 286;
	
	  ;% forced_choice_P.z_X0_g
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 287;
	
	  ;% forced_choice_P.beta_Value_i
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 288;
	
	  ;% forced_choice_P.timescale_Value_b
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 289;
	
	  ;% forced_choice_P.sigma_Value_k
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 290;
	
	  ;% forced_choice_P.y_X0_b0
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 291;
	
	  ;% forced_choice_P.rho_Value_i
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 292;
	
	  ;% forced_choice_P.z_X0_f
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 293;
	
	  ;% forced_choice_P.beta_Value_gv
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 294;
	
	  ;% forced_choice_P.timescale_Value_c
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 295;
	
	  ;% forced_choice_P.sigma_Value_bo
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 296;
	
	  ;% forced_choice_P.y_X0_f
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 297;
	
	  ;% forced_choice_P.rho_Value_dl
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 298;
	
	  ;% forced_choice_P.z_X0_p
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 299;
	
	  ;% forced_choice_P.beta_Value_b
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 300;
	
	  ;% forced_choice_P.timescale_Value_j
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 301;
	
	  ;% forced_choice_P.sigma_Value_e
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 302;
	
	  ;% forced_choice_P.y_X0_k
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 303;
	
	  ;% forced_choice_P.rho_Value_h
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 304;
	
	  ;% forced_choice_P.z_X0_n
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 305;
	
	  ;% forced_choice_P.beta_Value_p
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 306;
	
	  ;% forced_choice_P.timescale_Value_d
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 307;
	
	  ;% forced_choice_P.sigma_Value_o
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 308;
	
	  ;% forced_choice_P.y_X0_h
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 309;
	
	  ;% forced_choice_P.rho_Value_n
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 310;
	
	  ;% forced_choice_P.z_X0_b
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 311;
	
	  ;% forced_choice_P.beta_Value_e
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 312;
	
	  ;% forced_choice_P.timescale_Value_f
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 313;
	
	  ;% forced_choice_P.sigma_Value_k4
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 314;
	
	  ;% forced_choice_P.Gain_Gain_i
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 315;
	
	  ;% forced_choice_P.Gain1_Gain_e
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 316;
	
	  ;% forced_choice_P.Gain_Gain_n
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 317;
	
	  ;% forced_choice_P.visAngle_Value
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 318;
	
	  ;% forced_choice_P.DynamicAngle_Value
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 319;
	
	  ;% forced_choice_P.Inverter_Gain
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 320;
	
	  ;% forced_choice_P.Gain_Gain_l
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 321;
	
	  ;% forced_choice_P.LorentzForceGain_Gain
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 322;
	
	  ;% forced_choice_P.staticX_Value
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 323;
	
	  ;% forced_choice_P.staticY_Value
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 324;
	
	  ;% forced_choice_P.Off_Value
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 325;
	
	  ;% forced_choice_P.Gain_Gain_d
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 326;
	
	  ;% forced_choice_P.visAngle_Value_i
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 327;
	
	  ;% forced_choice_P.DynamicAngle_Value_c
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 328;
	
	  ;% forced_choice_P.Inverter_Gain_l
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 329;
	
	  ;% forced_choice_P.Gain_Gain_mk
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 330;
	
	  ;% forced_choice_P.LorentzForceGain_Gain_m
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 331;
	
	  ;% forced_choice_P.staticX_Value_i
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 332;
	
	  ;% forced_choice_P.staticY_Value_o
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 333;
	
	  ;% forced_choice_P.Off_Value_j
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 334;
	
	  ;% forced_choice_P.Gain1_Gain_k
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 335;
	
	  ;% forced_choice_P.Gain3_Gain
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 336;
	
	  ;% forced_choice_P.Saturation_UpperSat
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 337;
	
	  ;% forced_choice_P.Saturation_LowerSat
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 338;
	
	  ;% forced_choice_P.Gain4_Gain
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 339;
	
	  ;% forced_choice_P.Gain2_Gain_f
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 340;
	
	  ;% forced_choice_P.Saturation1_UpperSat
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 341;
	
	  ;% forced_choice_P.Saturation1_LowerSat
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 342;
	
	  ;% forced_choice_P.BoundingBoxViscosity_Gain
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 343;
	
	  ;% forced_choice_P.zeroX_Value
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 344;
	
	  ;% forced_choice_P.zeroY_Value
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 345;
	
	  ;% forced_choice_P.Gain_Gain_a
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 346;
	
	  ;% forced_choice_P.RewardJackpot_Value
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 347;
	
	  ;% forced_choice_P.RewardTime_Value
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 348;
	
	  ;% forced_choice_P.TachGain2_Gain
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 349;
	
	  ;% forced_choice_P.TachGain1_Gain
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 350;
	
	  ;% forced_choice_P.Constant2_Value
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 351;
	
	  ;% forced_choice_P.Constant1_Value
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 352;
	
	  ;% forced_choice_P.Constant_Value_h
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 353;
	
	  ;% forced_choice_P.xPCTargetTime_P1_Size
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 354;
	
	  ;% forced_choice_P.xPCTargetTime_P1
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 356;
	
	  ;% forced_choice_P.xPCTargetTime_P2_Size
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 357;
	
	  ;% forced_choice_P.xPCTargetTime_P2
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 359;
	
	  ;% forced_choice_P.ScaleTouSec_Gain
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 360;
	
	  ;% forced_choice_P.Constant_Value_m
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 361;
	
	  ;% forced_choice_P.PCI6025E_P1_Size_i
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 362;
	
	  ;% forced_choice_P.PCI6025E_P1_f
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 364;
	
	  ;% forced_choice_P.PCI6025E_P2_Size_e
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 366;
	
	  ;% forced_choice_P.PCI6025E_P2_h
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 368;
	
	  ;% forced_choice_P.PCI6025E_P3_Size_l
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 370;
	
	  ;% forced_choice_P.PCI6025E_P3_e
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 372;
	
	  ;% forced_choice_P.PCI6025E_P4_Size_p
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 374;
	
	  ;% forced_choice_P.PCI6025E_P4_g
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 376;
	
	  ;% forced_choice_P.PCI6025E_P5_Size_h
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 377;
	
	  ;% forced_choice_P.PCI6025E_P5_h
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 379;
	
	  ;% forced_choice_P.PCI6025E_P6_Size_h
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 380;
	
	  ;% forced_choice_P.PCI6025E_P6_f
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 382;
	
	  ;% forced_choice_P.PCI6025E_P7_Size_n
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 383;
	
	  ;% forced_choice_P.PCI6025E_P7_g
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 385;
	
	  ;% forced_choice_P.Constant_Value_m2
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 386;
	
	  ;% forced_choice_P.Switch_Threshold_n
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 387;
	
	  ;% forced_choice_P.PortA_P1_Size
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 388;
	
	  ;% forced_choice_P.PortA_P1
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 390;
	
	  ;% forced_choice_P.PortA_P2_Size
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 398;
	
	  ;% forced_choice_P.PortA_P2
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 400;
	
	  ;% forced_choice_P.PortA_P3_Size
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 401;
	
	  ;% forced_choice_P.PortA_P3
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 403;
	
	  ;% forced_choice_P.PortA_P4_Size
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 411;
	
	  ;% forced_choice_P.PortA_P4
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 413;
	
	  ;% forced_choice_P.PortA_P5_Size
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 421;
	
	  ;% forced_choice_P.PortA_P5
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 423;
	
	  ;% forced_choice_P.PortA_P6_Size
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 424;
	
	  ;% forced_choice_P.PortA_P6
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 426;
	
	  ;% forced_choice_P.PortA_P7_Size
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 427;
	
	  ;% forced_choice_P.PortA_P7
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 429;
	
	  ;% forced_choice_P.PortA_P8_Size
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 430;
	
	  ;% forced_choice_P.PortA_P8
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 432;
	
	  ;% forced_choice_P.PortA_P9_Size
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 433;
	
	  ;% forced_choice_P.PortA_P9
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 435;
	
	  ;% forced_choice_P.Constant_Value_i
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 436;
	
	  ;% forced_choice_P.PortB_P1_Size
	  section.data(287).logicalSrcIdx = 286;
	  section.data(287).dtTransOffset = 437;
	
	  ;% forced_choice_P.PortB_P1
	  section.data(288).logicalSrcIdx = 287;
	  section.data(288).dtTransOffset = 439;
	
	  ;% forced_choice_P.PortB_P2_Size
	  section.data(289).logicalSrcIdx = 288;
	  section.data(289).dtTransOffset = 447;
	
	  ;% forced_choice_P.PortB_P2
	  section.data(290).logicalSrcIdx = 289;
	  section.data(290).dtTransOffset = 449;
	
	  ;% forced_choice_P.PortB_P3_Size
	  section.data(291).logicalSrcIdx = 290;
	  section.data(291).dtTransOffset = 450;
	
	  ;% forced_choice_P.PortB_P3
	  section.data(292).logicalSrcIdx = 291;
	  section.data(292).dtTransOffset = 452;
	
	  ;% forced_choice_P.PortB_P4_Size
	  section.data(293).logicalSrcIdx = 292;
	  section.data(293).dtTransOffset = 460;
	
	  ;% forced_choice_P.PortB_P4
	  section.data(294).logicalSrcIdx = 293;
	  section.data(294).dtTransOffset = 462;
	
	  ;% forced_choice_P.PortB_P5_Size
	  section.data(295).logicalSrcIdx = 294;
	  section.data(295).dtTransOffset = 470;
	
	  ;% forced_choice_P.PortB_P5
	  section.data(296).logicalSrcIdx = 295;
	  section.data(296).dtTransOffset = 472;
	
	  ;% forced_choice_P.PortB_P6_Size
	  section.data(297).logicalSrcIdx = 296;
	  section.data(297).dtTransOffset = 473;
	
	  ;% forced_choice_P.PortB_P6
	  section.data(298).logicalSrcIdx = 297;
	  section.data(298).dtTransOffset = 475;
	
	  ;% forced_choice_P.PortB_P7_Size
	  section.data(299).logicalSrcIdx = 298;
	  section.data(299).dtTransOffset = 476;
	
	  ;% forced_choice_P.PortB_P7
	  section.data(300).logicalSrcIdx = 299;
	  section.data(300).dtTransOffset = 478;
	
	  ;% forced_choice_P.PortB_P8_Size
	  section.data(301).logicalSrcIdx = 300;
	  section.data(301).dtTransOffset = 479;
	
	  ;% forced_choice_P.PortB_P8
	  section.data(302).logicalSrcIdx = 301;
	  section.data(302).dtTransOffset = 481;
	
	  ;% forced_choice_P.PortB_P9_Size
	  section.data(303).logicalSrcIdx = 302;
	  section.data(303).dtTransOffset = 482;
	
	  ;% forced_choice_P.PortB_P9
	  section.data(304).logicalSrcIdx = 303;
	  section.data(304).dtTransOffset = 484;
	
	  ;% forced_choice_P.xPCTargetTime_P1_Size_p
	  section.data(305).logicalSrcIdx = 304;
	  section.data(305).dtTransOffset = 485;
	
	  ;% forced_choice_P.xPCTargetTime_P1_a
	  section.data(306).logicalSrcIdx = 305;
	  section.data(306).dtTransOffset = 487;
	
	  ;% forced_choice_P.xPCTargetTime_P2_Size_d
	  section.data(307).logicalSrcIdx = 306;
	  section.data(307).dtTransOffset = 488;
	
	  ;% forced_choice_P.xPCTargetTime_P2_g
	  section.data(308).logicalSrcIdx = 307;
	  section.data(308).dtTransOffset = 490;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% forced_choice_P.DelayInput1_X0
	  section.data(1).logicalSrcIdx = 308;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_P.DelayInput1_X0_f
	  section.data(2).logicalSrcIdx = 309;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_P.DelayInput1_X0_c
	  section.data(3).logicalSrcIdx = 310;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_P.DelayInput1_X0_d
	  section.data(4).logicalSrcIdx = 311;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% forced_choice_P.Memory_X0
	  section.data(1).logicalSrcIdx = 312;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_P.Memory_X0_m
	  section.data(2).logicalSrcIdx = 313;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_P.Memory_X0_n
	  section.data(3).logicalSrcIdx = 314;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_P.Memory_X0_f
	  section.data(4).logicalSrcIdx = 315;
	  section.data(4).dtTransOffset = 3;
	
	  ;% forced_choice_P.Memory_X0_e
	  section.data(5).logicalSrcIdx = 316;
	  section.data(5).dtTransOffset = 4;
	
	  ;% forced_choice_P.Memory_X0_a
	  section.data(6).logicalSrcIdx = 317;
	  section.data(6).dtTransOffset = 5;
	
	  ;% forced_choice_P.Memory_X0_k
	  section.data(7).logicalSrcIdx = 318;
	  section.data(7).dtTransOffset = 6;
	
	  ;% forced_choice_P.Logic_table
	  section.data(8).logicalSrcIdx = 319;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_P.SampleandHold._Y0
	  section.data(1).logicalSrcIdx = 320;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_P.SampleandHold_i._Y0
	  section.data(1).logicalSrcIdx = 321;
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
    ;% Auto data (forced_choice_B)
    ;%
      section.nData     = 286;
      section.data(286)  = dumData; %prealloc
      
	  ;% forced_choice_B.Clock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_B.Sum
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_B.PCIQUAD04
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_B.Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% forced_choice_B.Sum3
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% forced_choice_B.TrigonometricFunction
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% forced_choice_B.Product
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% forced_choice_B.TrigonometricFunction1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% forced_choice_B.Product1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% forced_choice_B.PCIQUAD041
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% forced_choice_B.Gain1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% forced_choice_B.Sum1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% forced_choice_B.TrigonometricFunction2
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% forced_choice_B.Product2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% forced_choice_B.TrigonometricFunction3
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% forced_choice_B.Product3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% forced_choice_B.MatrixConcatenate2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% forced_choice_B.PCI6025EAD_o1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 20;
	
	  ;% forced_choice_B.PCI6025EAD_o2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% forced_choice_B.Sum2
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% forced_choice_B.Sum4
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% forced_choice_B.Sum3_n
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% forced_choice_B.Sum1_a
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% forced_choice_B.TrigonometricFunction1_j
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% forced_choice_B.Sum_f
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 27;
	
	  ;% forced_choice_B.TrigonometricFunction2_g
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 28;
	
	  ;% forced_choice_B.sqrtu1u1u2u2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 29;
	
	  ;% forced_choice_B.Product1_d
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 30;
	
	  ;% forced_choice_B.DigitalFilter2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 31;
	
	  ;% forced_choice_B.Derivative
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 32;
	
	  ;% forced_choice_B.dG
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 33;
	
	  ;% forced_choice_B.DigitalFilter
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 34;
	
	  ;% forced_choice_B.TrigonometricFunction_k
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 35;
	
	  ;% forced_choice_B.Product_d
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 36;
	
	  ;% forced_choice_B.DigitalFilter2_b
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 37;
	
	  ;% forced_choice_B.Derivative_h
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 38;
	
	  ;% forced_choice_B.dG_f
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 39;
	
	  ;% forced_choice_B.DigitalFilter_k
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 40;
	
	  ;% forced_choice_B.Switch
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 41;
	
	  ;% forced_choice_B.Clock_p
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 43;
	
	  ;% forced_choice_B.Clock_l
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 44;
	
	  ;% forced_choice_B.Sum_k
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 45;
	
	  ;% forced_choice_B.Sum_a
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 46;
	
	  ;% forced_choice_B.Abs2
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 47;
	
	  ;% forced_choice_B.Abs3
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 48;
	
	  ;% forced_choice_B.Clock_f
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 49;
	
	  ;% forced_choice_B.Sum_d
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 50;
	
	  ;% forced_choice_B.Clock_b
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 51;
	
	  ;% forced_choice_B.Sum_p
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 52;
	
	  ;% forced_choice_B.x
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 53;
	
	  ;% forced_choice_B.x_h
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 54;
	
	  ;% forced_choice_B.Add
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 55;
	
	  ;% forced_choice_B.x_m
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 56;
	
	  ;% forced_choice_B.x_ho
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 57;
	
	  ;% forced_choice_B.MultiportSwitch
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 58;
	
	  ;% forced_choice_B.x_o
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 60;
	
	  ;% forced_choice_B.x_of
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 61;
	
	  ;% forced_choice_B.Add_c
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 62;
	
	  ;% forced_choice_B.x_n
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 63;
	
	  ;% forced_choice_B.x_p
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 64;
	
	  ;% forced_choice_B.LoadSelectSwitch
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 65;
	
	  ;% forced_choice_B.BehaviorFC_o1
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 67;
	
	  ;% forced_choice_B.BehaviorFC_o2
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 69;
	
	  ;% forced_choice_B.BehaviorFC_o3
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 74;
	
	  ;% forced_choice_B.BehaviorFC_o4
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 75;
	
	  ;% forced_choice_B.BehaviorFC_o5
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 85;
	
	  ;% forced_choice_B.BehaviorFC_o6
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 86;
	
	  ;% forced_choice_B.BehaviorFC_o7
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 88;
	
	  ;% forced_choice_B.BehaviorFC_o8
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 92;
	
	  ;% forced_choice_B.Switch2
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 94;
	
	  ;% forced_choice_B.MG1
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 96;
	
	  ;% forced_choice_B.MG2
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 97;
	
	  ;% forced_choice_B.Clock_i
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 98;
	
	  ;% forced_choice_B.HiddenBuf_InsertedFor_Sampleand
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 99;
	
	  ;% forced_choice_B.Sum_f5
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 100;
	
	  ;% forced_choice_B.UniformRandomNumber
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 101;
	
	  ;% forced_choice_B.Switch_n
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 102;
	
	  ;% forced_choice_B.HiddenBuf_InsertedFor_Samplea_o
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 103;
	
	  ;% forced_choice_B.DataTypeConversion
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 104;
	
	  ;% forced_choice_B.y
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 105;
	
	  ;% forced_choice_B.Add1
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 106;
	
	  ;% forced_choice_B.z
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 107;
	
	  ;% forced_choice_B.Add3
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 108;
	
	  ;% forced_choice_B.product2
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 109;
	
	  ;% forced_choice_B.Add2
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 110;
	
	  ;% forced_choice_B.product3
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 111;
	
	  ;% forced_choice_B.product4
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 112;
	
	  ;% forced_choice_B.Add4
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 113;
	
	  ;% forced_choice_B.product1
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 114;
	
	  ;% forced_choice_B.dX
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 115;
	
	  ;% forced_choice_B.AddX
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 116;
	
	  ;% forced_choice_B.dY
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 117;
	
	  ;% forced_choice_B.AddX1
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 118;
	
	  ;% forced_choice_B.dZ
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 119;
	
	  ;% forced_choice_B.AddX2
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 120;
	
	  ;% forced_choice_B.y_i
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 121;
	
	  ;% forced_choice_B.Add1_k
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 122;
	
	  ;% forced_choice_B.z_e
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 123;
	
	  ;% forced_choice_B.Add3_m
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 124;
	
	  ;% forced_choice_B.product2_m
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 125;
	
	  ;% forced_choice_B.Add2_p
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 126;
	
	  ;% forced_choice_B.product3_j
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 127;
	
	  ;% forced_choice_B.product4_l
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 128;
	
	  ;% forced_choice_B.Add4_d
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 129;
	
	  ;% forced_choice_B.product1_h
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 130;
	
	  ;% forced_choice_B.dX_c
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 131;
	
	  ;% forced_choice_B.AddX_h
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 132;
	
	  ;% forced_choice_B.dY_j
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 133;
	
	  ;% forced_choice_B.AddX1_a
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 134;
	
	  ;% forced_choice_B.dZ_k
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 135;
	
	  ;% forced_choice_B.AddX2_f
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 136;
	
	  ;% forced_choice_B.y_k
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 137;
	
	  ;% forced_choice_B.Add1_l
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 138;
	
	  ;% forced_choice_B.z_h
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 139;
	
	  ;% forced_choice_B.Add3_i
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 140;
	
	  ;% forced_choice_B.product2_g
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 141;
	
	  ;% forced_choice_B.Add2_c
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 142;
	
	  ;% forced_choice_B.product3_k
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 143;
	
	  ;% forced_choice_B.product4_h
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 144;
	
	  ;% forced_choice_B.Add4_i
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 145;
	
	  ;% forced_choice_B.product1_b
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 146;
	
	  ;% forced_choice_B.dX_h
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 147;
	
	  ;% forced_choice_B.AddX_e
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 148;
	
	  ;% forced_choice_B.dY_o
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 149;
	
	  ;% forced_choice_B.AddX1_g
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 150;
	
	  ;% forced_choice_B.dZ_m
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 151;
	
	  ;% forced_choice_B.AddX2_m
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 152;
	
	  ;% forced_choice_B.y_a
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 153;
	
	  ;% forced_choice_B.Add1_ld
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 154;
	
	  ;% forced_choice_B.z_a
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 155;
	
	  ;% forced_choice_B.Add3_o
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 156;
	
	  ;% forced_choice_B.product2_n
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 157;
	
	  ;% forced_choice_B.Add2_f
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 158;
	
	  ;% forced_choice_B.product3_ji
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 159;
	
	  ;% forced_choice_B.product4_o
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 160;
	
	  ;% forced_choice_B.Add4_h
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 161;
	
	  ;% forced_choice_B.product1_o
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 162;
	
	  ;% forced_choice_B.dX_i
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 163;
	
	  ;% forced_choice_B.AddX_k
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 164;
	
	  ;% forced_choice_B.dY_k
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 165;
	
	  ;% forced_choice_B.AddX1_c
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 166;
	
	  ;% forced_choice_B.dZ_mc
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 167;
	
	  ;% forced_choice_B.AddX2_d
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 168;
	
	  ;% forced_choice_B.y_p
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 169;
	
	  ;% forced_choice_B.Add1_o
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 170;
	
	  ;% forced_choice_B.z_p
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 171;
	
	  ;% forced_choice_B.Add3_m2
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 172;
	
	  ;% forced_choice_B.product2_go
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 173;
	
	  ;% forced_choice_B.Add2_n
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 174;
	
	  ;% forced_choice_B.product3_m
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 175;
	
	  ;% forced_choice_B.product4_j
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 176;
	
	  ;% forced_choice_B.Add4_p
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 177;
	
	  ;% forced_choice_B.product1_k
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 178;
	
	  ;% forced_choice_B.dX_b
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 179;
	
	  ;% forced_choice_B.AddX_n
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 180;
	
	  ;% forced_choice_B.dY_ks
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 181;
	
	  ;% forced_choice_B.AddX1_p
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 182;
	
	  ;% forced_choice_B.dZ_j
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 183;
	
	  ;% forced_choice_B.AddX2_i
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 184;
	
	  ;% forced_choice_B.y_pt
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 185;
	
	  ;% forced_choice_B.Add1_e
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 186;
	
	  ;% forced_choice_B.z_m
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 187;
	
	  ;% forced_choice_B.Add3_n
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 188;
	
	  ;% forced_choice_B.product2_n2
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 189;
	
	  ;% forced_choice_B.Add2_d
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 190;
	
	  ;% forced_choice_B.product3_b
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 191;
	
	  ;% forced_choice_B.product4_n
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 192;
	
	  ;% forced_choice_B.Add4_c
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 193;
	
	  ;% forced_choice_B.product1_ka
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 194;
	
	  ;% forced_choice_B.dX_i1
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 195;
	
	  ;% forced_choice_B.AddX_m
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 196;
	
	  ;% forced_choice_B.dY_g
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 197;
	
	  ;% forced_choice_B.AddX1_j
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 198;
	
	  ;% forced_choice_B.dZ_k3
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 199;
	
	  ;% forced_choice_B.AddX2_j
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 200;
	
	  ;% forced_choice_B.y_e
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 201;
	
	  ;% forced_choice_B.Add1_ln
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 202;
	
	  ;% forced_choice_B.z_mc
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 203;
	
	  ;% forced_choice_B.Add3_k
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 204;
	
	  ;% forced_choice_B.product2_a
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 205;
	
	  ;% forced_choice_B.Add2_k
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 206;
	
	  ;% forced_choice_B.product3_c
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 207;
	
	  ;% forced_choice_B.product4_c
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 208;
	
	  ;% forced_choice_B.Add4_im
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 209;
	
	  ;% forced_choice_B.product1_bp
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 210;
	
	  ;% forced_choice_B.dX_l
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 211;
	
	  ;% forced_choice_B.AddX_kb
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 212;
	
	  ;% forced_choice_B.dY_op
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 213;
	
	  ;% forced_choice_B.AddX1_k
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 214;
	
	  ;% forced_choice_B.dZ_f
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 215;
	
	  ;% forced_choice_B.AddX2_b
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 216;
	
	  ;% forced_choice_B.y_ke
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 217;
	
	  ;% forced_choice_B.Add1_i
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 218;
	
	  ;% forced_choice_B.z_n
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 219;
	
	  ;% forced_choice_B.Add3_d
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 220;
	
	  ;% forced_choice_B.product2_j
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 221;
	
	  ;% forced_choice_B.Add2_cy
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 222;
	
	  ;% forced_choice_B.product3_a
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 223;
	
	  ;% forced_choice_B.product4_p
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 224;
	
	  ;% forced_choice_B.Add4_hy
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 225;
	
	  ;% forced_choice_B.product1_kd
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 226;
	
	  ;% forced_choice_B.dX_a
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 227;
	
	  ;% forced_choice_B.AddX_mq
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 228;
	
	  ;% forced_choice_B.dY_p
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 229;
	
	  ;% forced_choice_B.AddX1_e
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 230;
	
	  ;% forced_choice_B.dZ_p
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 231;
	
	  ;% forced_choice_B.AddX2_fp
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 232;
	
	  ;% forced_choice_B.MatrixConcatenation1
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 233;
	
	  ;% forced_choice_B.Add_n
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 237;
	
	  ;% forced_choice_B.Add1_m
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 238;
	
	  ;% forced_choice_B.Gain_n
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 239;
	
	  ;% forced_choice_B.Gain1_d
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 240;
	
	  ;% forced_choice_B.ForIterator
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 241;
	
	  ;% forced_choice_B.Switch_e
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 242;
	
	  ;% forced_choice_B.ToBits1_o1
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 243;
	
	  ;% forced_choice_B.ToBits1_o2
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 244;
	
	  ;% forced_choice_B.ToBits1_o3
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 245;
	
	  ;% forced_choice_B.ToBits1_o4
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 246;
	
	  ;% forced_choice_B.ToBits1_o5
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 247;
	
	  ;% forced_choice_B.ToBits1_o6
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 248;
	
	  ;% forced_choice_B.ToBits1_o7
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 249;
	
	  ;% forced_choice_B.ToBits1_o8
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 250;
	
	  ;% forced_choice_B.Add_i
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 251;
	
	  ;% forced_choice_B.Add1_k0
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 252;
	
	  ;% forced_choice_B.SerialConverter
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 253;
	
	  ;% forced_choice_B.ToBits_o1
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 254;
	
	  ;% forced_choice_B.ToBits_o2
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 255;
	
	  ;% forced_choice_B.ToBits_o3
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 256;
	
	  ;% forced_choice_B.ToBits_o4
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 257;
	
	  ;% forced_choice_B.ToBits_o5
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 258;
	
	  ;% forced_choice_B.ToBits_o6
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 259;
	
	  ;% forced_choice_B.ToBits_o7
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 260;
	
	  ;% forced_choice_B.ToBits_o8
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 261;
	
	  ;% forced_choice_B.xPCTargetTime
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 262;
	
	  ;% forced_choice_B.xPCTargetTime_n
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 263;
	
	  ;% forced_choice_B.Subtract
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 264;
	
	  ;% forced_choice_B.ScaleTouSec
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 265;
	
	  ;% forced_choice_B.Switch_m
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 266;
	
	  ;% forced_choice_B.TachGain2
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 267;
	
	  ;% forced_choice_B.TachGain1
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 268;
	
	  ;% forced_choice_B.TmpHiddenBufferAtMatrixMultiply
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 269;
	
	  ;% forced_choice_B.MatrixMultiply
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 271;
	
	  ;% forced_choice_B.Gain_i
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 273;
	
	  ;% forced_choice_B.MathFunction
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 275;
	
	  ;% forced_choice_B.MatrixMultiply_f
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 279;
	
	  ;% forced_choice_B.Switch1
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 281;
	
	  ;% forced_choice_B.Switch_c
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 283;
	
	  ;% forced_choice_B.BoundingBoxViscosity
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 285;
	
	  ;% forced_choice_B.Product_g
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 287;
	
	  ;% forced_choice_B.Gain1_m
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 288;
	
	  ;% forced_choice_B.Gain3
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 289;
	
	  ;% forced_choice_B.Add_j
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 290;
	
	  ;% forced_choice_B.Saturation
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 291;
	
	  ;% forced_choice_B.Gain4
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 292;
	
	  ;% forced_choice_B.Product1_m
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 293;
	
	  ;% forced_choice_B.Gain2
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 294;
	
	  ;% forced_choice_B.Add1_p
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 295;
	
	  ;% forced_choice_B.Saturation1
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 296;
	
	  ;% forced_choice_B.Add1_c
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 297;
	
	  ;% forced_choice_B.LorentzForceGain
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 298;
	
	  ;% forced_choice_B.dynamicAngleSwitch
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 300;
	
	  ;% forced_choice_B.sin_c
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 301;
	
	  ;% forced_choice_B.Inverter
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 302;
	
	  ;% forced_choice_B.Product3_g
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 304;
	
	  ;% forced_choice_B.cos_n
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 305;
	
	  ;% forced_choice_B.Product2_p
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 306;
	
	  ;% forced_choice_B.Subtract_b
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 307;
	
	  ;% forced_choice_B.Product1_h
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 308;
	
	  ;% forced_choice_B.Product_h
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 309;
	
	  ;% forced_choice_B.Add_f
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 310;
	
	  ;% forced_choice_B.Gain_l
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 311;
	
	  ;% forced_choice_B.Gain_e
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 313;
	
	  ;% forced_choice_B.Add1_cy
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 314;
	
	  ;% forced_choice_B.LorentzForceGain_f
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 315;
	
	  ;% forced_choice_B.DynamicAngleSwitch
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 317;
	
	  ;% forced_choice_B.sin_h
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 318;
	
	  ;% forced_choice_B.Inverter_f
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 319;
	
	  ;% forced_choice_B.Product3_c
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 321;
	
	  ;% forced_choice_B.cos_i
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 322;
	
	  ;% forced_choice_B.Product2_k
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 323;
	
	  ;% forced_choice_B.Subtract_n
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 324;
	
	  ;% forced_choice_B.Product1_l
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 325;
	
	  ;% forced_choice_B.Product_p
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 326;
	
	  ;% forced_choice_B.Add_cv
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 327;
	
	  ;% forced_choice_B.Gain_j
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 328;
	
	  ;% forced_choice_B.Gain_ii
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 330;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% forced_choice_B.Compare
	  section.data(1).logicalSrcIdx = 286;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_B.Compare_g
	  section.data(2).logicalSrcIdx = 287;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_B.Compare_j
	  section.data(3).logicalSrcIdx = 288;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_B.Compare_k
	  section.data(4).logicalSrcIdx = 289;
	  section.data(4).dtTransOffset = 3;
	
	  ;% forced_choice_B.Compare_gq
	  section.data(5).logicalSrcIdx = 290;
	  section.data(5).dtTransOffset = 4;
	
	  ;% forced_choice_B.Uk1
	  section.data(6).logicalSrcIdx = 291;
	  section.data(6).dtTransOffset = 5;
	
	  ;% forced_choice_B.FixPtRelationalOperator
	  section.data(7).logicalSrcIdx = 292;
	  section.data(7).dtTransOffset = 6;
	
	  ;% forced_choice_B.Compare_i
	  section.data(8).logicalSrcIdx = 293;
	  section.data(8).dtTransOffset = 7;
	
	  ;% forced_choice_B.Compare_f
	  section.data(9).logicalSrcIdx = 294;
	  section.data(9).dtTransOffset = 8;
	
	  ;% forced_choice_B.Compare_p
	  section.data(10).logicalSrcIdx = 295;
	  section.data(10).dtTransOffset = 9;
	
	  ;% forced_choice_B.Compare_jg
	  section.data(11).logicalSrcIdx = 296;
	  section.data(11).dtTransOffset = 10;
	
	  ;% forced_choice_B.Uk1_c
	  section.data(12).logicalSrcIdx = 297;
	  section.data(12).dtTransOffset = 11;
	
	  ;% forced_choice_B.FixPtRelationalOperator_l
	  section.data(13).logicalSrcIdx = 298;
	  section.data(13).dtTransOffset = 12;
	
	  ;% forced_choice_B.Compare_n
	  section.data(14).logicalSrcIdx = 299;
	  section.data(14).dtTransOffset = 13;
	
	  ;% forced_choice_B.Compare_l
	  section.data(15).logicalSrcIdx = 300;
	  section.data(15).dtTransOffset = 14;
	
	  ;% forced_choice_B.Uk1_k
	  section.data(16).logicalSrcIdx = 301;
	  section.data(16).dtTransOffset = 15;
	
	  ;% forced_choice_B.FixPtRelationalOperator_d
	  section.data(17).logicalSrcIdx = 302;
	  section.data(17).dtTransOffset = 16;
	
	  ;% forced_choice_B.Compare_jc
	  section.data(18).logicalSrcIdx = 303;
	  section.data(18).dtTransOffset = 17;
	
	  ;% forced_choice_B.Compare_e
	  section.data(19).logicalSrcIdx = 304;
	  section.data(19).dtTransOffset = 18;
	
	  ;% forced_choice_B.Uk1_m
	  section.data(20).logicalSrcIdx = 305;
	  section.data(20).dtTransOffset = 19;
	
	  ;% forced_choice_B.FixPtRelationalOperator_j
	  section.data(21).logicalSrcIdx = 306;
	  section.data(21).dtTransOffset = 20;
	
	  ;% forced_choice_B.Compare_m
	  section.data(22).logicalSrcIdx = 307;
	  section.data(22).dtTransOffset = 21;
	
	  ;% forced_choice_B.Compare_d
	  section.data(23).logicalSrcIdx = 308;
	  section.data(23).dtTransOffset = 22;
	
	  ;% forced_choice_B.Pack
	  section.data(24).logicalSrcIdx = 309;
	  section.data(24).dtTransOffset = 23;
	
	  ;% forced_choice_B.RateTransition
	  section.data(25).logicalSrcIdx = 310;
	  section.data(25).dtTransOffset = 135;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 57;
      section.data(57)  = dumData; %prealloc
      
	  ;% forced_choice_B.Memory
	  section.data(1).logicalSrcIdx = 311;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_B.Memory_p
	  section.data(2).logicalSrcIdx = 312;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_B.LogicalOperator2
	  section.data(3).logicalSrcIdx = 313;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_B.LogicalOperator1
	  section.data(4).logicalSrcIdx = 314;
	  section.data(4).dtTransOffset = 3;
	
	  ;% forced_choice_B.HiddenBuf_InsertedFor_EnabledSu
	  section.data(5).logicalSrcIdx = 315;
	  section.data(5).dtTransOffset = 4;
	
	  ;% forced_choice_B.RelationalOperator
	  section.data(6).logicalSrcIdx = 316;
	  section.data(6).dtTransOffset = 5;
	
	  ;% forced_choice_B.LogicalOperator
	  section.data(7).logicalSrcIdx = 317;
	  section.data(7).dtTransOffset = 6;
	
	  ;% forced_choice_B.Memory_h
	  section.data(8).logicalSrcIdx = 318;
	  section.data(8).dtTransOffset = 7;
	
	  ;% forced_choice_B.RelationalOperator_o
	  section.data(9).logicalSrcIdx = 319;
	  section.data(9).dtTransOffset = 8;
	
	  ;% forced_choice_B.RelationalOperator1
	  section.data(10).logicalSrcIdx = 320;
	  section.data(10).dtTransOffset = 9;
	
	  ;% forced_choice_B.RelationalOperator2
	  section.data(11).logicalSrcIdx = 321;
	  section.data(11).dtTransOffset = 10;
	
	  ;% forced_choice_B.RelationalOperator3
	  section.data(12).logicalSrcIdx = 322;
	  section.data(12).dtTransOffset = 11;
	
	  ;% forced_choice_B.LogicalOperator_h
	  section.data(13).logicalSrcIdx = 323;
	  section.data(13).dtTransOffset = 12;
	
	  ;% forced_choice_B.InBox
	  section.data(14).logicalSrcIdx = 324;
	  section.data(14).dtTransOffset = 13;
	
	  ;% forced_choice_B.LogicalOperator3
	  section.data(15).logicalSrcIdx = 325;
	  section.data(15).dtTransOffset = 14;
	
	  ;% forced_choice_B.Memory_k
	  section.data(16).logicalSrcIdx = 326;
	  section.data(16).dtTransOffset = 15;
	
	  ;% forced_choice_B.LogicalOperator4
	  section.data(17).logicalSrcIdx = 327;
	  section.data(17).dtTransOffset = 16;
	
	  ;% forced_choice_B.LogicalOperator_f
	  section.data(18).logicalSrcIdx = 328;
	  section.data(18).dtTransOffset = 17;
	
	  ;% forced_choice_B.LogicalOperator2_b
	  section.data(19).logicalSrcIdx = 329;
	  section.data(19).dtTransOffset = 18;
	
	  ;% forced_choice_B.LogicalOperator1_p
	  section.data(20).logicalSrcIdx = 330;
	  section.data(20).dtTransOffset = 19;
	
	  ;% forced_choice_B.HiddenBuf_InsertedFor_Enabled_b
	  section.data(21).logicalSrcIdx = 331;
	  section.data(21).dtTransOffset = 20;
	
	  ;% forced_choice_B.RelationalOperator_p
	  section.data(22).logicalSrcIdx = 332;
	  section.data(22).dtTransOffset = 21;
	
	  ;% forced_choice_B.LogicalOperator_fl
	  section.data(23).logicalSrcIdx = 333;
	  section.data(23).dtTransOffset = 22;
	
	  ;% forced_choice_B.LogicalOperator5
	  section.data(24).logicalSrcIdx = 334;
	  section.data(24).dtTransOffset = 23;
	
	  ;% forced_choice_B.LogicalOperator2_d
	  section.data(25).logicalSrcIdx = 335;
	  section.data(25).dtTransOffset = 24;
	
	  ;% forced_choice_B.LogicalOperator1_h
	  section.data(26).logicalSrcIdx = 336;
	  section.data(26).dtTransOffset = 25;
	
	  ;% forced_choice_B.HiddenBuf_InsertedFor_Enabled_i
	  section.data(27).logicalSrcIdx = 337;
	  section.data(27).dtTransOffset = 26;
	
	  ;% forced_choice_B.RelationalOperator_n
	  section.data(28).logicalSrcIdx = 338;
	  section.data(28).dtTransOffset = 27;
	
	  ;% forced_choice_B.LogicalOperator_p
	  section.data(29).logicalSrcIdx = 339;
	  section.data(29).dtTransOffset = 28;
	
	  ;% forced_choice_B.LogicalOperator1_e
	  section.data(30).logicalSrcIdx = 340;
	  section.data(30).dtTransOffset = 29;
	
	  ;% forced_choice_B.NOT
	  section.data(31).logicalSrcIdx = 341;
	  section.data(31).dtTransOffset = 30;
	
	  ;% forced_choice_B.Memory_ha
	  section.data(32).logicalSrcIdx = 342;
	  section.data(32).dtTransOffset = 31;
	
	  ;% forced_choice_B.LogicalOperator2_da
	  section.data(33).logicalSrcIdx = 343;
	  section.data(33).dtTransOffset = 32;
	
	  ;% forced_choice_B.LogicalOperator1_i
	  section.data(34).logicalSrcIdx = 344;
	  section.data(34).dtTransOffset = 33;
	
	  ;% forced_choice_B.HiddenBuf_InsertedFor_Enabled_g
	  section.data(35).logicalSrcIdx = 345;
	  section.data(35).dtTransOffset = 34;
	
	  ;% forced_choice_B.RelationalOperator_b
	  section.data(36).logicalSrcIdx = 346;
	  section.data(36).dtTransOffset = 35;
	
	  ;% forced_choice_B.LogicalOperator_g
	  section.data(37).logicalSrcIdx = 347;
	  section.data(37).dtTransOffset = 36;
	
	  ;% forced_choice_B.DataTypeConversion2
	  section.data(38).logicalSrcIdx = 348;
	  section.data(38).dtTransOffset = 37;
	
	  ;% forced_choice_B.LogicalOperator1_c
	  section.data(39).logicalSrcIdx = 349;
	  section.data(39).dtTransOffset = 38;
	
	  ;% forced_choice_B.Memory_m
	  section.data(40).logicalSrcIdx = 350;
	  section.data(40).dtTransOffset = 39;
	
	  ;% forced_choice_B.LogicalOperator2_e
	  section.data(41).logicalSrcIdx = 351;
	  section.data(41).dtTransOffset = 40;
	
	  ;% forced_choice_B.LogicalOperator1_hr
	  section.data(42).logicalSrcIdx = 352;
	  section.data(42).dtTransOffset = 41;
	
	  ;% forced_choice_B.HiddenBuf_InsertedFor_Enabled_f
	  section.data(43).logicalSrcIdx = 353;
	  section.data(43).dtTransOffset = 42;
	
	  ;% forced_choice_B.RelationalOperator_pi
	  section.data(44).logicalSrcIdx = 354;
	  section.data(44).dtTransOffset = 43;
	
	  ;% forced_choice_B.LogicalOperator_fa
	  section.data(45).logicalSrcIdx = 355;
	  section.data(45).dtTransOffset = 44;
	
	  ;% forced_choice_B.DataTypeConversion1
	  section.data(46).logicalSrcIdx = 356;
	  section.data(46).dtTransOffset = 45;
	
	  ;% forced_choice_B.Memory_f
	  section.data(47).logicalSrcIdx = 357;
	  section.data(47).dtTransOffset = 46;
	
	  ;% forced_choice_B.Logic
	  section.data(48).logicalSrcIdx = 358;
	  section.data(48).dtTransOffset = 47;
	
	  ;% forced_choice_B.LogicalOperator5_h
	  section.data(49).logicalSrcIdx = 359;
	  section.data(49).dtTransOffset = 49;
	
	  ;% forced_choice_B.LogicalOperator1_g
	  section.data(50).logicalSrcIdx = 360;
	  section.data(50).dtTransOffset = 50;
	
	  ;% forced_choice_B.MatrixConcatenation
	  section.data(51).logicalSrcIdx = 361;
	  section.data(51).dtTransOffset = 51;
	
	  ;% forced_choice_B.RelationalOperator_f
	  section.data(52).logicalSrcIdx = 362;
	  section.data(52).dtTransOffset = 53;
	
	  ;% forced_choice_B.RelationalOperator_c
	  section.data(53).logicalSrcIdx = 363;
	  section.data(53).dtTransOffset = 54;
	
	  ;% forced_choice_B.Compare_pl
	  section.data(54).logicalSrcIdx = 364;
	  section.data(54).dtTransOffset = 55;
	
	  ;% forced_choice_B.Compare_a
	  section.data(55).logicalSrcIdx = 365;
	  section.data(55).dtTransOffset = 56;
	
	  ;% forced_choice_B.LogicalOperator6
	  section.data(56).logicalSrcIdx = 366;
	  section.data(56).dtTransOffset = 57;
	
	  ;% forced_choice_B.LogicalOperator3_j
	  section.data(57).logicalSrcIdx = 367;
	  section.data(57).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_B.SampleandHold.In
	  section.data(1).logicalSrcIdx = 368;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_B.SampleandHold_i.In
	  section.data(1).logicalSrcIdx = 369;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_B.EnabledSubsystem_l.In1
	  section.data(1).logicalSrcIdx = 370;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_B.EnabledSubsystem_i.In1
	  section.data(1).logicalSrcIdx = 371;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_B.EnabledSubsystem_hg.In1
	  section.data(1).logicalSrcIdx = 372;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_B.EnabledSubsystem_h.In1
	  section.data(1).logicalSrcIdx = 373;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_B.EnabledSubsystem.In1
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
    ;% Auto data (forced_choice_DWork)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.DigitalFilter2_FILT_STATES
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_DWork.DigitalFilter_FILT_STATES
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 11;
	
	  ;% forced_choice_DWork.DigitalFilter2_FILT_STATES_g
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 22;
	
	  ;% forced_choice_DWork.DigitalFilter_FILT_STATES_d
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 33;
	
	  ;% forced_choice_DWork.x_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 44;
	
	  ;% forced_choice_DWork.x_DSTATE_h
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 45;
	
	  ;% forced_choice_DWork.x_DSTATE_g
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 46;
	
	  ;% forced_choice_DWork.x_DSTATE_e
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 47;
	
	  ;% forced_choice_DWork.x_DSTATE_k
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 48;
	
	  ;% forced_choice_DWork.x_DSTATE_en
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 49;
	
	  ;% forced_choice_DWork.x_DSTATE_b
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 50;
	
	  ;% forced_choice_DWork.x_DSTATE_d
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 51;
	
	  ;% forced_choice_DWork.BehaviorFC_DSTATE
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 52;
	
	  ;% forced_choice_DWork.y_DSTATE
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 53;
	
	  ;% forced_choice_DWork.z_DSTATE
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 54;
	
	  ;% forced_choice_DWork.y_DSTATE_n
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 55;
	
	  ;% forced_choice_DWork.z_DSTATE_g
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 56;
	
	  ;% forced_choice_DWork.y_DSTATE_h
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 57;
	
	  ;% forced_choice_DWork.z_DSTATE_m
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 58;
	
	  ;% forced_choice_DWork.y_DSTATE_f
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 59;
	
	  ;% forced_choice_DWork.z_DSTATE_f
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 60;
	
	  ;% forced_choice_DWork.y_DSTATE_a
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 61;
	
	  ;% forced_choice_DWork.z_DSTATE_i
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 62;
	
	  ;% forced_choice_DWork.y_DSTATE_ag
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 63;
	
	  ;% forced_choice_DWork.z_DSTATE_gn
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 64;
	
	  ;% forced_choice_DWork.y_DSTATE_p
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 65;
	
	  ;% forced_choice_DWork.z_DSTATE_a
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 66;
	
	  ;% forced_choice_DWork.y_DSTATE_g
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 67;
	
	  ;% forced_choice_DWork.z_DSTATE_p
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 68;
	
	  ;% forced_choice_DWork.PCI6025EAD_RWORK
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 69;
	
	  ;% forced_choice_DWork.Derivative_RWORK.TimeStampA
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 133;
	
	  ;% forced_choice_DWork.Derivative_RWORK_a.TimeStampA
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 134;
	
	  ;% forced_choice_DWork.BehaviorFC_RWORK
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 135;
	
	  ;% forced_choice_DWork.PCI6025E_RWORK
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 139;
	
	  ;% forced_choice_DWork.UniformRandomNumber_RWORK.NextOutput
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 145;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.Send_PWORK
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.DigitalFilter2_CIRCBUFFIDX
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_DWork.DigitalFilter_CIRCBUFFIDX
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_DWork.DigitalFilter2_CIRCBUFFIDX_b
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_DWork.DigitalFilter_CIRCBUFFIDX_k
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.PCIQUAD04_IWORK
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_DWork.PCIQUAD041_IWORK
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_DWork.PCI6025EAD_IWORK
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_DWork.BehaviorFC_IWORK
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 68;
	
	  ;% forced_choice_DWork.PCI6025E_IWORK
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 131;
	
	  ;% forced_choice_DWork.SFunction_IWORK.AcquireOK
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 133;
	
	  ;% forced_choice_DWork.SFunction_IWORK_g.AcquireOK
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 134;
	
	  ;% forced_choice_DWork.SFunction_IWORK_f.AcquireOK
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 135;
	
	  ;% forced_choice_DWork.Send_IWORK
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 136;
	
	  ;% forced_choice_DWork.SFunction_IWORK_gk.AcquireOK
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 138;
	
	  ;% forced_choice_DWork.SFunction_IWORK_i.AcquireOK
	  section.data(11).logicalSrcIdx = 50;
	  section.data(11).dtTransOffset = 139;
	
	  ;% forced_choice_DWork.SFunction_IWORK_n.AcquireOK
	  section.data(12).logicalSrcIdx = 51;
	  section.data(12).dtTransOffset = 140;
	
	  ;% forced_choice_DWork.UniformRandomNumber_IWORK.RandSeed
	  section.data(13).logicalSrcIdx = 52;
	  section.data(13).dtTransOffset = 141;
	
	  ;% forced_choice_DWork.PortA_IWORK
	  section.data(14).logicalSrcIdx = 53;
	  section.data(14).dtTransOffset = 142;
	
	  ;% forced_choice_DWork.PortB_IWORK
	  section.data(15).logicalSrcIdx = 54;
	  section.data(15).dtTransOffset = 144;
	
	  ;% forced_choice_DWork.PCI6025E_IWORK_k
	  section.data(16).logicalSrcIdx = 55;
	  section.data(16).dtTransOffset = 146;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.DelayInput1_DSTATE
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_DWork.DelayInput1_DSTATE_d
	  section.data(2).logicalSrcIdx = 57;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_DWork.DelayInput1_DSTATE_m
	  section.data(3).logicalSrcIdx = 58;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_DWork.DelayInput1_DSTATE_b
	  section.data(4).logicalSrcIdx = 59;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_DWork.Memory_PreviousInput_l
	  section.data(2).logicalSrcIdx = 61;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_DWork.Memory_PreviousInput_e
	  section.data(3).logicalSrcIdx = 62;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_DWork.Memory_PreviousInput_n
	  section.data(4).logicalSrcIdx = 63;
	  section.data(4).dtTransOffset = 3;
	
	  ;% forced_choice_DWork.Memory_PreviousInput_eh
	  section.data(5).logicalSrcIdx = 64;
	  section.data(5).dtTransOffset = 4;
	
	  ;% forced_choice_DWork.Memory_PreviousInput_g
	  section.data(6).logicalSrcIdx = 65;
	  section.data(6).dtTransOffset = 5;
	
	  ;% forced_choice_DWork.Memory_PreviousInput_h
	  section.data(7).logicalSrcIdx = 66;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.SampleandHold.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.SampleandHold_i.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem_i.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem_i.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem_hg.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem_hg.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 78;
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


  targMap.checksum0 = 743698192;
  targMap.checksum1 = 3108080846;
  targMap.checksum2 = 1240755981;
  targMap.checksum3 = 2323727065;

