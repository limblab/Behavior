  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
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
      section.nData     = 220;
      section.data(220)  = dumData; %prealloc
      
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
	
	  ;% forced_choice_P.PCIQUAD041_P1_Size
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 36;
	
	  ;% forced_choice_P.PCIQUAD041_P1
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 38;
	
	  ;% forced_choice_P.PCIQUAD041_P2_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 39;
	
	  ;% forced_choice_P.PCIQUAD041_P2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 41;
	
	  ;% forced_choice_P.PCIQUAD041_P3_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 42;
	
	  ;% forced_choice_P.PCIQUAD041_P3
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 44;
	
	  ;% forced_choice_P.PCIQUAD041_P4_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 45;
	
	  ;% forced_choice_P.PCIQUAD041_P4
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 47;
	
	  ;% forced_choice_P.PCIQUAD041_P5_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 48;
	
	  ;% forced_choice_P.PCIQUAD041_P5
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 50;
	
	  ;% forced_choice_P.PCIQUAD041_P6_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 51;
	
	  ;% forced_choice_P.PCIQUAD041_P6
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 53;
	
	  ;% forced_choice_P.PCIQUAD041_P7_Size
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 54;
	
	  ;% forced_choice_P.PCIQUAD041_P7
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 56;
	
	  ;% forced_choice_P.PCIQUAD041_P8_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 57;
	
	  ;% forced_choice_P.PCIQUAD041_P8
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 59;
	
	  ;% forced_choice_P.PCIQUAD041_P9_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 60;
	
	  ;% forced_choice_P.PCIQUAD041_P9
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 62;
	
	  ;% forced_choice_P.PCIQUAD041_P10_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 63;
	
	  ;% forced_choice_P.PCIQUAD041_P10
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 65;
	
	  ;% forced_choice_P.PCIQUAD041_P11_Size
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 66;
	
	  ;% forced_choice_P.PCIQUAD041_P11
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 68;
	
	  ;% forced_choice_P.Gain1_Gain
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 69;
	
	  ;% forced_choice_P.elbowOffset_Value
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 70;
	
	  ;% forced_choice_P.yoffset_Value
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 71;
	
	  ;% forced_choice_P.xoffset_Value
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 72;
	
	  ;% forced_choice_P.AngleOffset_Value
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 73;
	
	  ;% forced_choice_P.DigitalFilter2_ICRTP
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 74;
	
	  ;% forced_choice_P.DigitalFilter2_RTP1COEFF
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 75;
	
	  ;% forced_choice_P.dG_Gain
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 86;
	
	  ;% forced_choice_P.DigitalFilter_ICRTP
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 87;
	
	  ;% forced_choice_P.DigitalFilter_RTP1COEFF
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 88;
	
	  ;% forced_choice_P.DigitalFilter2_ICRTP_c
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 99;
	
	  ;% forced_choice_P.DigitalFilter2_RTP1COEFF_a
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 100;
	
	  ;% forced_choice_P.dG_Gain_b
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 111;
	
	  ;% forced_choice_P.DigitalFilter_ICRTP_c
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 112;
	
	  ;% forced_choice_P.DigitalFilter_RTP1COEFF_n
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 113;
	
	  ;% forced_choice_P.XLowLimit_Value
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 124;
	
	  ;% forced_choice_P.XHighLimit_Value
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 125;
	
	  ;% forced_choice_P.YHighLimit_Value
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 126;
	
	  ;% forced_choice_P.YLowLimit_Value
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 127;
	
	  ;% forced_choice_P.Load_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 128;
	
	  ;% forced_choice_P.x_X0
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 129;
	
	  ;% forced_choice_P.x_X0_f
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 130;
	
	  ;% forced_choice_P.x_X0_l
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 131;
	
	  ;% forced_choice_P.x_X0_c
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 132;
	
	  ;% forced_choice_P.BehaviorFC_P1_Size
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 133;
	
	  ;% forced_choice_P.BehaviorFC_P1
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 135;
	
	  ;% forced_choice_P.BehaviorFC_P2_Size
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 136;
	
	  ;% forced_choice_P.BehaviorFC_P2
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 138;
	
	  ;% forced_choice_P.BehaviorFC_P3_Size
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 139;
	
	  ;% forced_choice_P.BehaviorFC_P3
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 141;
	
	  ;% forced_choice_P.BehaviorFC_P4_Size
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 142;
	
	  ;% forced_choice_P.BehaviorFC_P4
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 144;
	
	  ;% forced_choice_P.BehaviorFC_P5_Size
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 145;
	
	  ;% forced_choice_P.BehaviorFC_P5
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 147;
	
	  ;% forced_choice_P.BehaviorFC_P6_Size
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 148;
	
	  ;% forced_choice_P.BehaviorFC_P6
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 150;
	
	  ;% forced_choice_P.BehaviorFC_P7_Size
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 151;
	
	  ;% forced_choice_P.BehaviorFC_P7
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 153;
	
	  ;% forced_choice_P.BehaviorFC_P8_Size
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 154;
	
	  ;% forced_choice_P.BehaviorFC_P8
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 156;
	
	  ;% forced_choice_P.BehaviorFC_P9_Size
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 157;
	
	  ;% forced_choice_P.BehaviorFC_P9
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 159;
	
	  ;% forced_choice_P.BehaviorFC_P10_Size
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 160;
	
	  ;% forced_choice_P.BehaviorFC_P10
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 162;
	
	  ;% forced_choice_P.BehaviorFC_P11_Size
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 163;
	
	  ;% forced_choice_P.BehaviorFC_P11
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 165;
	
	  ;% forced_choice_P.MG2_Gain
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 166;
	
	  ;% forced_choice_P.MG1_Gain
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 167;
	
	  ;% forced_choice_P.PCI6025E_P1_Size
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 168;
	
	  ;% forced_choice_P.PCI6025E_P1
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 170;
	
	  ;% forced_choice_P.PCI6025E_P2_Size
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 172;
	
	  ;% forced_choice_P.PCI6025E_P2
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 174;
	
	  ;% forced_choice_P.PCI6025E_P3_Size
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 176;
	
	  ;% forced_choice_P.PCI6025E_P3
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 178;
	
	  ;% forced_choice_P.PCI6025E_P4_Size
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 180;
	
	  ;% forced_choice_P.PCI6025E_P4
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 182;
	
	  ;% forced_choice_P.PCI6025E_P5_Size
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 184;
	
	  ;% forced_choice_P.PCI6025E_P5
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 186;
	
	  ;% forced_choice_P.PCI6025E_P6_Size
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 187;
	
	  ;% forced_choice_P.PCI6025E_P6
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 189;
	
	  ;% forced_choice_P.PCI6025E_P7_Size
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 191;
	
	  ;% forced_choice_P.PCI6025E_P7
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 193;
	
	  ;% forced_choice_P.Send_P1_Size
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 194;
	
	  ;% forced_choice_P.Send_P1
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 196;
	
	  ;% forced_choice_P.Send_P2_Size
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 207;
	
	  ;% forced_choice_P.Send_P2
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 209;
	
	  ;% forced_choice_P.Send_P3_Size
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 210;
	
	  ;% forced_choice_P.Send_P3
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 212;
	
	  ;% forced_choice_P.Send_P4_Size
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 213;
	
	  ;% forced_choice_P.Send_P4
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 215;
	
	  ;% forced_choice_P.PortA_P1_Size
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 216;
	
	  ;% forced_choice_P.PortA_P1
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 218;
	
	  ;% forced_choice_P.PortA_P2_Size
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 226;
	
	  ;% forced_choice_P.PortA_P2
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 228;
	
	  ;% forced_choice_P.PortA_P3_Size
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 229;
	
	  ;% forced_choice_P.PortA_P3
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 231;
	
	  ;% forced_choice_P.PortA_P4_Size
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 239;
	
	  ;% forced_choice_P.PortA_P4
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 241;
	
	  ;% forced_choice_P.PortA_P5_Size
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 249;
	
	  ;% forced_choice_P.PortA_P5
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 251;
	
	  ;% forced_choice_P.PortA_P6_Size
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 252;
	
	  ;% forced_choice_P.PortA_P6
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 254;
	
	  ;% forced_choice_P.PortA_P7_Size
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 255;
	
	  ;% forced_choice_P.PortA_P7
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 257;
	
	  ;% forced_choice_P.PortA_P8_Size
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 259;
	
	  ;% forced_choice_P.PortA_P8
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 261;
	
	  ;% forced_choice_P.PortA_P9_Size
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 262;
	
	  ;% forced_choice_P.PortA_P9
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 264;
	
	  ;% forced_choice_P.y_X0
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 265;
	
	  ;% forced_choice_P.rho_Value
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 266;
	
	  ;% forced_choice_P.z_X0
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 267;
	
	  ;% forced_choice_P.beta_Value
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 268;
	
	  ;% forced_choice_P.timescale_Value
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 269;
	
	  ;% forced_choice_P.sigma_Value
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 270;
	
	  ;% forced_choice_P.y_X0_f
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 271;
	
	  ;% forced_choice_P.rho_Value_d
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 272;
	
	  ;% forced_choice_P.z_X0_p
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 273;
	
	  ;% forced_choice_P.beta_Value_b
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 274;
	
	  ;% forced_choice_P.timescale_Value_j
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 275;
	
	  ;% forced_choice_P.sigma_Value_e
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 276;
	
	  ;% forced_choice_P.y_X0_k
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 277;
	
	  ;% forced_choice_P.rho_Value_h
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 278;
	
	  ;% forced_choice_P.z_X0_n
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 279;
	
	  ;% forced_choice_P.beta_Value_p
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 280;
	
	  ;% forced_choice_P.timescale_Value_d
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 281;
	
	  ;% forced_choice_P.sigma_Value_o
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 282;
	
	  ;% forced_choice_P.y_X0_h
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 283;
	
	  ;% forced_choice_P.rho_Value_n
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 284;
	
	  ;% forced_choice_P.z_X0_b
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 285;
	
	  ;% forced_choice_P.beta_Value_e
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 286;
	
	  ;% forced_choice_P.timescale_Value_f
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 287;
	
	  ;% forced_choice_P.sigma_Value_k
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 288;
	
	  ;% forced_choice_P.Time_Value_b
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 289;
	
	  ;% forced_choice_P.Constant_Value
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 290;
	
	  ;% forced_choice_P.Constant_Value_d
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 291;
	
	  ;% forced_choice_P.Gain_Gain_i
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 292;
	
	  ;% forced_choice_P.Gain1_Gain_e
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 293;
	
	  ;% forced_choice_P.zeroX_Value
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 294;
	
	  ;% forced_choice_P.zeroY_Value
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 295;
	
	  ;% forced_choice_P.Gain_Gain_d
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 296;
	
	  ;% forced_choice_P.visAngle_Value
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 297;
	
	  ;% forced_choice_P.DynamicAngle_Value
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 298;
	
	  ;% forced_choice_P.Gain_Gain_m
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 299;
	
	  ;% forced_choice_P.LorentzForceGain_Gain
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 300;
	
	  ;% forced_choice_P.staticX_Value
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 301;
	
	  ;% forced_choice_P.staticY_Value
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 302;
	
	  ;% forced_choice_P.Off_Value
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 303;
	
	  ;% forced_choice_P.Constant1_Value
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 304;
	
	  ;% forced_choice_P.Constant_Value_h
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 305;
	
	  ;% forced_choice_P.xPCTargetTime_P1_Size
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 306;
	
	  ;% forced_choice_P.xPCTargetTime_P1
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 308;
	
	  ;% forced_choice_P.xPCTargetTime_P2_Size
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 309;
	
	  ;% forced_choice_P.xPCTargetTime_P2
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 311;
	
	  ;% forced_choice_P.ScaleTouSec_Gain
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 312;
	
	  ;% forced_choice_P.Constant_Value_m
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 313;
	
	  ;% forced_choice_P.PCI6025E_P1_Size_i
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 314;
	
	  ;% forced_choice_P.PCI6025E_P1_f
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 316;
	
	  ;% forced_choice_P.PCI6025E_P2_Size_e
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 318;
	
	  ;% forced_choice_P.PCI6025E_P2_h
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 320;
	
	  ;% forced_choice_P.PCI6025E_P3_Size_l
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 322;
	
	  ;% forced_choice_P.PCI6025E_P3_e
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 324;
	
	  ;% forced_choice_P.PCI6025E_P4_Size_p
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 326;
	
	  ;% forced_choice_P.PCI6025E_P4_g
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 328;
	
	  ;% forced_choice_P.PCI6025E_P5_Size_h
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 329;
	
	  ;% forced_choice_P.PCI6025E_P5_h
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 331;
	
	  ;% forced_choice_P.PCI6025E_P6_Size_h
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 333;
	
	  ;% forced_choice_P.PCI6025E_P6_f
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 335;
	
	  ;% forced_choice_P.PCI6025E_P7_Size_n
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 336;
	
	  ;% forced_choice_P.PCI6025E_P7_g
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 338;
	
	  ;% forced_choice_P.Constant_Value_m2
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 339;
	
	  ;% forced_choice_P.Constant_Value_i
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 340;
	
	  ;% forced_choice_P.PortB_P1_Size
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 341;
	
	  ;% forced_choice_P.PortB_P1
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 343;
	
	  ;% forced_choice_P.PortB_P2_Size
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 351;
	
	  ;% forced_choice_P.PortB_P2
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 353;
	
	  ;% forced_choice_P.PortB_P3_Size
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 354;
	
	  ;% forced_choice_P.PortB_P3
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 356;
	
	  ;% forced_choice_P.PortB_P4_Size
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 364;
	
	  ;% forced_choice_P.PortB_P4
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 366;
	
	  ;% forced_choice_P.PortB_P5_Size
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 374;
	
	  ;% forced_choice_P.PortB_P5
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 376;
	
	  ;% forced_choice_P.PortB_P6_Size
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 377;
	
	  ;% forced_choice_P.PortB_P6
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 379;
	
	  ;% forced_choice_P.PortB_P7_Size
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 380;
	
	  ;% forced_choice_P.PortB_P7
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 382;
	
	  ;% forced_choice_P.PortB_P8_Size
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 384;
	
	  ;% forced_choice_P.PortB_P8
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 386;
	
	  ;% forced_choice_P.PortB_P9_Size
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 387;
	
	  ;% forced_choice_P.PortB_P9
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 389;
	
	  ;% forced_choice_P.xPCTargetTime_P1_Size_p
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 390;
	
	  ;% forced_choice_P.xPCTargetTime_P1_a
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 392;
	
	  ;% forced_choice_P.xPCTargetTime_P2_Size_d
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 393;
	
	  ;% forced_choice_P.xPCTargetTime_P2_g
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 395;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% forced_choice_P.Memory_X0
	  section.data(1).logicalSrcIdx = 220;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_P.Memory_X0_b
	  section.data(2).logicalSrcIdx = 221;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_P.Memory1_X0
	  section.data(3).logicalSrcIdx = 222;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_P.Memory_X0_n
	  section.data(4).logicalSrcIdx = 223;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (forced_choice_B)
    ;%
      section.nData     = 168;
      section.data(168)  = dumData; %prealloc
      
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
	
	  ;% forced_choice_B.sinlengthofShoulder
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% forced_choice_B.PCIQUAD041
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% forced_choice_B.Gain1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% forced_choice_B.Sum1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% forced_choice_B.sinlengthofElbow
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% forced_choice_B.Sum2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% forced_choice_B.Sum4
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% forced_choice_B.coslengthofShoulder
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% forced_choice_B.coslengthofElbow
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% forced_choice_B.Sum3_n
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% forced_choice_B.Sum1_a
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% forced_choice_B.TrigonometricFunction1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% forced_choice_B.Sum_f
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% forced_choice_B.TrigonometricFunction2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% forced_choice_B.sqrtu1u1u2u2
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% forced_choice_B.Product1
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% forced_choice_B.DigitalFilter2
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% forced_choice_B.Derivative
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% forced_choice_B.dG
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% forced_choice_B.DigitalFilter
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% forced_choice_B.TrigonometricFunction
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% forced_choice_B.Product
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% forced_choice_B.DigitalFilter2_d
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% forced_choice_B.Derivative_l
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% forced_choice_B.dG_k
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% forced_choice_B.DigitalFilter_g
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% forced_choice_B.x
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% forced_choice_B.x_h
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% forced_choice_B.Add
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% forced_choice_B.x_m
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% forced_choice_B.x_ho
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% forced_choice_B.Add1
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% forced_choice_B.MultiportSwitch
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% forced_choice_B.BehaviorFC_o1
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 39;
	
	  ;% forced_choice_B.BehaviorFC_o2
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 41;
	
	  ;% forced_choice_B.BehaviorFC_o3
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 45;
	
	  ;% forced_choice_B.BehaviorFC_o4
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 46;
	
	  ;% forced_choice_B.BehaviorFC_o5
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 56;
	
	  ;% forced_choice_B.BehaviorFC_o6
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 57;
	
	  ;% forced_choice_B.Switch1
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 59;
	
	  ;% forced_choice_B.MG2
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 61;
	
	  ;% forced_choice_B.RateTransition2
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 62;
	
	  ;% forced_choice_B.MG1
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 63;
	
	  ;% forced_choice_B.RateTransition1
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 64;
	
	  ;% forced_choice_B.ToBits_o1
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 65;
	
	  ;% forced_choice_B.ToBits_o2
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 66;
	
	  ;% forced_choice_B.ToBits_o3
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 67;
	
	  ;% forced_choice_B.ToBits_o4
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 68;
	
	  ;% forced_choice_B.ToBits_o5
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 69;
	
	  ;% forced_choice_B.ToBits_o6
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 70;
	
	  ;% forced_choice_B.ToBits_o7
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 71;
	
	  ;% forced_choice_B.ToBits_o8
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 72;
	
	  ;% forced_choice_B.y
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 73;
	
	  ;% forced_choice_B.Add1_o
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 74;
	
	  ;% forced_choice_B.z
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 75;
	
	  ;% forced_choice_B.Add3
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 76;
	
	  ;% forced_choice_B.product2
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 77;
	
	  ;% forced_choice_B.Add2
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 78;
	
	  ;% forced_choice_B.product3
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 79;
	
	  ;% forced_choice_B.product4
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 80;
	
	  ;% forced_choice_B.Add4
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 81;
	
	  ;% forced_choice_B.product1
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 82;
	
	  ;% forced_choice_B.dX
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 83;
	
	  ;% forced_choice_B.AddX
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 84;
	
	  ;% forced_choice_B.dY
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 85;
	
	  ;% forced_choice_B.AddX1
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 86;
	
	  ;% forced_choice_B.dZ
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 87;
	
	  ;% forced_choice_B.AddX2
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 88;
	
	  ;% forced_choice_B.y_p
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 89;
	
	  ;% forced_choice_B.Add1_e
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 90;
	
	  ;% forced_choice_B.z_m
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 91;
	
	  ;% forced_choice_B.Add3_n
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 92;
	
	  ;% forced_choice_B.product2_n
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 93;
	
	  ;% forced_choice_B.Add2_d
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 94;
	
	  ;% forced_choice_B.product3_b
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 95;
	
	  ;% forced_choice_B.product4_n
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 96;
	
	  ;% forced_choice_B.Add4_c
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 97;
	
	  ;% forced_choice_B.product1_k
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 98;
	
	  ;% forced_choice_B.dX_i
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 99;
	
	  ;% forced_choice_B.AddX_m
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 100;
	
	  ;% forced_choice_B.dY_g
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 101;
	
	  ;% forced_choice_B.AddX1_j
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 102;
	
	  ;% forced_choice_B.dZ_k
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 103;
	
	  ;% forced_choice_B.AddX2_j
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 104;
	
	  ;% forced_choice_B.y_e
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 105;
	
	  ;% forced_choice_B.Add1_l
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 106;
	
	  ;% forced_choice_B.z_mc
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 107;
	
	  ;% forced_choice_B.Add3_k
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 108;
	
	  ;% forced_choice_B.product2_a
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 109;
	
	  ;% forced_choice_B.Add2_k
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 110;
	
	  ;% forced_choice_B.product3_c
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 111;
	
	  ;% forced_choice_B.product4_c
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 112;
	
	  ;% forced_choice_B.Add4_i
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 113;
	
	  ;% forced_choice_B.product1_b
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 114;
	
	  ;% forced_choice_B.dX_l
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 115;
	
	  ;% forced_choice_B.AddX_k
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 116;
	
	  ;% forced_choice_B.dY_o
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 117;
	
	  ;% forced_choice_B.AddX1_k
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 118;
	
	  ;% forced_choice_B.dZ_f
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 119;
	
	  ;% forced_choice_B.AddX2_b
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 120;
	
	  ;% forced_choice_B.y_k
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 121;
	
	  ;% forced_choice_B.Add1_i
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 122;
	
	  ;% forced_choice_B.z_n
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 123;
	
	  ;% forced_choice_B.Add3_d
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 124;
	
	  ;% forced_choice_B.product2_j
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 125;
	
	  ;% forced_choice_B.Add2_c
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 126;
	
	  ;% forced_choice_B.product3_a
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 127;
	
	  ;% forced_choice_B.product4_p
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 128;
	
	  ;% forced_choice_B.Add4_h
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 129;
	
	  ;% forced_choice_B.product1_kd
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 130;
	
	  ;% forced_choice_B.dX_a
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 131;
	
	  ;% forced_choice_B.AddX_mq
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 132;
	
	  ;% forced_choice_B.dY_p
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 133;
	
	  ;% forced_choice_B.AddX1_e
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 134;
	
	  ;% forced_choice_B.dZ_p
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 135;
	
	  ;% forced_choice_B.AddX2_f
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 136;
	
	  ;% forced_choice_B.DataTypeConversion
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 137;
	
	  ;% forced_choice_B.Clock_k
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 138;
	
	  ;% forced_choice_B.Sum_l
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 139;
	
	  ;% forced_choice_B.Add_n
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 140;
	
	  ;% forced_choice_B.Add1_m
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 141;
	
	  ;% forced_choice_B.Gain_n
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 142;
	
	  ;% forced_choice_B.Gain1_d
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 143;
	
	  ;% forced_choice_B.ForIterator
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 144;
	
	  ;% forced_choice_B.Add_i
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 145;
	
	  ;% forced_choice_B.Add1_k
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 146;
	
	  ;% forced_choice_B.SerialConverter
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 147;
	
	  ;% forced_choice_B.ToBits_o1_n
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 148;
	
	  ;% forced_choice_B.ToBits_o2_l
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 149;
	
	  ;% forced_choice_B.ToBits_o3_f
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 150;
	
	  ;% forced_choice_B.ToBits_o4_k
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 151;
	
	  ;% forced_choice_B.ToBits_o5_a
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 152;
	
	  ;% forced_choice_B.ToBits_o6_o
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 153;
	
	  ;% forced_choice_B.ToBits_o7_h
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 154;
	
	  ;% forced_choice_B.ToBits_o8_e
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 155;
	
	  ;% forced_choice_B.xPCTargetTime
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 156;
	
	  ;% forced_choice_B.xPCTargetTime_n
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 157;
	
	  ;% forced_choice_B.Subtract
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 158;
	
	  ;% forced_choice_B.ScaleTouSec
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 159;
	
	  ;% forced_choice_B.Switch
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 160;
	
	  ;% forced_choice_B.sinlengthofShoulder_e
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 161;
	
	  ;% forced_choice_B.Product_k
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 162;
	
	  ;% forced_choice_B.coslengthofShoulder_m
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 163;
	
	  ;% forced_choice_B.Product1_a
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 164;
	
	  ;% forced_choice_B.sinlengthofElbow_j
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 165;
	
	  ;% forced_choice_B.Product2
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 166;
	
	  ;% forced_choice_B.coslengthofElbow_j
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 167;
	
	  ;% forced_choice_B.Product3
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 168;
	
	  ;% forced_choice_B.Sum5
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 169;
	
	  ;% forced_choice_B.Sum6
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 170;
	
	  ;% forced_choice_B.LorentzForceGain
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 171;
	
	  ;% forced_choice_B.dynamicAngleSwitch
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 173;
	
	  ;% forced_choice_B.sin_c
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 174;
	
	  ;% forced_choice_B.Product3_g
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 175;
	
	  ;% forced_choice_B.cos_n
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 176;
	
	  ;% forced_choice_B.Product2_p
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 177;
	
	  ;% forced_choice_B.Subtract_b
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 178;
	
	  ;% forced_choice_B.Product1_h
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 179;
	
	  ;% forced_choice_B.Product_h
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 180;
	
	  ;% forced_choice_B.Add_f
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 181;
	
	  ;% forced_choice_B.Gain_l
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 182;
	
	  ;% forced_choice_B.Gain_e
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 184;
	
	  ;% forced_choice_B.Switch_d
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 185;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% forced_choice_B.Compare
	  section.data(1).logicalSrcIdx = 168;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_B.Pack
	  section.data(2).logicalSrcIdx = 169;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_B.RateTransition
	  section.data(3).logicalSrcIdx = 170;
	  section.data(3).dtTransOffset = 113;
	
	  ;% forced_choice_B.Compare_b
	  section.data(4).logicalSrcIdx = 171;
	  section.data(4).dtTransOffset = 225;
	
	  ;% forced_choice_B.Compare_b2
	  section.data(5).logicalSrcIdx = 172;
	  section.data(5).dtTransOffset = 226;
	
	  ;% forced_choice_B.Compare_j
	  section.data(6).logicalSrcIdx = 173;
	  section.data(6).dtTransOffset = 227;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% forced_choice_B.Memory
	  section.data(1).logicalSrcIdx = 174;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_B.Memory_o
	  section.data(2).logicalSrcIdx = 175;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_B.LogicalOperator2
	  section.data(3).logicalSrcIdx = 176;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_B.LogicalOperator1
	  section.data(4).logicalSrcIdx = 177;
	  section.data(4).dtTransOffset = 3;
	
	  ;% forced_choice_B.HiddenBuf_InsertedFor_EnabledSu
	  section.data(5).logicalSrcIdx = 178;
	  section.data(5).dtTransOffset = 4;
	
	  ;% forced_choice_B.RelationalOperator
	  section.data(6).logicalSrcIdx = 179;
	  section.data(6).dtTransOffset = 5;
	
	  ;% forced_choice_B.LogicalOperator
	  section.data(7).logicalSrcIdx = 180;
	  section.data(7).dtTransOffset = 6;
	
	  ;% forced_choice_B.RelationalOperator_o
	  section.data(8).logicalSrcIdx = 181;
	  section.data(8).dtTransOffset = 7;
	
	  ;% forced_choice_B.RelationalOperator1
	  section.data(9).logicalSrcIdx = 182;
	  section.data(9).dtTransOffset = 8;
	
	  ;% forced_choice_B.RelationalOperator2
	  section.data(10).logicalSrcIdx = 183;
	  section.data(10).dtTransOffset = 9;
	
	  ;% forced_choice_B.RelationalOperator3
	  section.data(11).logicalSrcIdx = 184;
	  section.data(11).dtTransOffset = 10;
	
	  ;% forced_choice_B.LogicalOperator_h
	  section.data(12).logicalSrcIdx = 185;
	  section.data(12).dtTransOffset = 11;
	
	  ;% forced_choice_B.Memory1
	  section.data(13).logicalSrcIdx = 186;
	  section.data(13).dtTransOffset = 12;
	
	  ;% forced_choice_B.Memory_f
	  section.data(14).logicalSrcIdx = 187;
	  section.data(14).dtTransOffset = 13;
	
	  ;% forced_choice_B.LogicalOperator2_h
	  section.data(15).logicalSrcIdx = 188;
	  section.data(15).dtTransOffset = 14;
	
	  ;% forced_choice_B.LogicalOperator1_m
	  section.data(16).logicalSrcIdx = 189;
	  section.data(16).dtTransOffset = 15;
	
	  ;% forced_choice_B.HiddenBuf_InsertedFor_Enabled_g
	  section.data(17).logicalSrcIdx = 190;
	  section.data(17).dtTransOffset = 16;
	
	  ;% forced_choice_B.RelationalOperator_m
	  section.data(18).logicalSrcIdx = 191;
	  section.data(18).dtTransOffset = 17;
	
	  ;% forced_choice_B.LogicalOperator_a
	  section.data(19).logicalSrcIdx = 192;
	  section.data(19).dtTransOffset = 18;
	
	  ;% forced_choice_B.LogicalOperator1_l
	  section.data(20).logicalSrcIdx = 193;
	  section.data(20).dtTransOffset = 19;
	
	  ;% forced_choice_B.MatrixConcatenation
	  section.data(21).logicalSrcIdx = 194;
	  section.data(21).dtTransOffset = 20;
	
	  ;% forced_choice_B.Compare_p
	  section.data(22).logicalSrcIdx = 195;
	  section.data(22).dtTransOffset = 22;
	
	  ;% forced_choice_B.Compare_a
	  section.data(23).logicalSrcIdx = 196;
	  section.data(23).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_B.EnabledSubsystem.In1
	  section.data(1).logicalSrcIdx = 197;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_B.EnabledSubsystem_h.In1
	  section.data(1).logicalSrcIdx = 198;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
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
    nTotSects     = 9;
    sectIdxOffset = 5;
    
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
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.DigitalFilter2_FILT_STATES
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_DWork.DigitalFilter_FILT_STATES
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 11;
	
	  ;% forced_choice_DWork.DigitalFilter2_FILT_STATES_c
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 22;
	
	  ;% forced_choice_DWork.DigitalFilter_FILT_STATES_p
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
	
	  ;% forced_choice_DWork.BehaviorFC_DSTATE
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 48;
	
	  ;% forced_choice_DWork.y_DSTATE
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 49;
	
	  ;% forced_choice_DWork.z_DSTATE
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 50;
	
	  ;% forced_choice_DWork.y_DSTATE_a
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 51;
	
	  ;% forced_choice_DWork.z_DSTATE_g
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 52;
	
	  ;% forced_choice_DWork.y_DSTATE_p
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 53;
	
	  ;% forced_choice_DWork.z_DSTATE_a
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 54;
	
	  ;% forced_choice_DWork.y_DSTATE_g
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 55;
	
	  ;% forced_choice_DWork.z_DSTATE_p
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 56;
	
	  ;% forced_choice_DWork.Derivative_RWORK.TimeStampA
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 57;
	
	  ;% forced_choice_DWork.Derivative_RWORK_p.TimeStampA
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 58;
	
	  ;% forced_choice_DWork.BehaviorFC_RWORK
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 59;
	
	  ;% forced_choice_DWork.PCI6025E_RWORK
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 62;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.Send_PWORK
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.DigitalFilter2_CIRCBUFFIDX
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_DWork.DigitalFilter_CIRCBUFFIDX
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_DWork.DigitalFilter2_CIRCBUFFIDX_p
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_DWork.DigitalFilter_CIRCBUFFIDX_b
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.PCIQUAD04_IWORK
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_DWork.PCIQUAD041_IWORK
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_DWork.BehaviorFC_IWORK
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_DWork.PCI6025E_IWORK
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 65;
	
	  ;% forced_choice_DWork.SFunction_IWORK.AcquireOK
	  section.data(5).logicalSrcIdx = 30;
	  section.data(5).dtTransOffset = 67;
	
	  ;% forced_choice_DWork.Send_IWORK
	  section.data(6).logicalSrcIdx = 31;
	  section.data(6).dtTransOffset = 68;
	
	  ;% forced_choice_DWork.PortA_IWORK
	  section.data(7).logicalSrcIdx = 32;
	  section.data(7).dtTransOffset = 70;
	
	  ;% forced_choice_DWork.SFunction_IWORK_i.AcquireOK
	  section.data(8).logicalSrcIdx = 33;
	  section.data(8).dtTransOffset = 72;
	
	  ;% forced_choice_DWork.SFunction_IWORK_a.AcquireOK
	  section.data(9).logicalSrcIdx = 34;
	  section.data(9).dtTransOffset = 73;
	
	  ;% forced_choice_DWork.SFunction_IWORK_d.AcquireOK
	  section.data(10).logicalSrcIdx = 35;
	  section.data(10).dtTransOffset = 74;
	
	  ;% forced_choice_DWork.SFunction_IWORK_h.AcquireOK
	  section.data(11).logicalSrcIdx = 36;
	  section.data(11).dtTransOffset = 75;
	
	  ;% forced_choice_DWork.SFunction_IWORK_ie.AcquireOK
	  section.data(12).logicalSrcIdx = 37;
	  section.data(12).dtTransOffset = 76;
	
	  ;% forced_choice_DWork.SFunction_IWORK_b.AcquireOK
	  section.data(13).logicalSrcIdx = 38;
	  section.data(13).dtTransOffset = 77;
	
	  ;% forced_choice_DWork.SFunction_IWORK_g.AcquireOK
	  section.data(14).logicalSrcIdx = 39;
	  section.data(14).dtTransOffset = 78;
	
	  ;% forced_choice_DWork.PortB_IWORK
	  section.data(15).logicalSrcIdx = 40;
	  section.data(15).dtTransOffset = 79;
	
	  ;% forced_choice_DWork.PCI6025E_IWORK_k
	  section.data(16).logicalSrcIdx = 41;
	  section.data(16).dtTransOffset = 81;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% forced_choice_DWork.Memory_PreviousInput_a
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
	  ;% forced_choice_DWork.Memory1_PreviousInput
	  section.data(3).logicalSrcIdx = 44;
	  section.data(3).dtTransOffset = 2;
	
	  ;% forced_choice_DWork.Memory_PreviousInput_m
	  section.data(4).logicalSrcIdx = 45;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% forced_choice_DWork.EnabledSubsystem_h.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
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


  targMap.checksum0 = 549952335;
  targMap.checksum1 = 1277274929;
  targMap.checksum2 = 4219268999;
  targMap.checksum3 = 484119277;

