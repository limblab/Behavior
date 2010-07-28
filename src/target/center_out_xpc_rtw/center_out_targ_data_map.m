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
    ;% Auto data (center_out_P)
    ;%
      section.nData     = 318;
      section.data(318)  = dumData; %prealloc
      
	  ;% center_out_P.Time_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% center_out_P.PCIQUAD04_P1_Size
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% center_out_P.PCIQUAD04_P1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% center_out_P.PCIQUAD04_P2_Size
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% center_out_P.PCIQUAD04_P2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% center_out_P.PCIQUAD04_P3_Size
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 7;
	
	  ;% center_out_P.PCIQUAD04_P3
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% center_out_P.PCIQUAD04_P4_Size
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 10;
	
	  ;% center_out_P.PCIQUAD04_P4
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% center_out_P.PCIQUAD04_P5_Size
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 13;
	
	  ;% center_out_P.PCIQUAD04_P5
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% center_out_P.PCIQUAD04_P6_Size
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% center_out_P.PCIQUAD04_P6
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% center_out_P.PCIQUAD04_P7_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 19;
	
	  ;% center_out_P.PCIQUAD04_P7
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 21;
	
	  ;% center_out_P.PCIQUAD04_P8_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 22;
	
	  ;% center_out_P.PCIQUAD04_P8
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% center_out_P.PCIQUAD04_P9_Size
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 25;
	
	  ;% center_out_P.PCIQUAD04_P9
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 27;
	
	  ;% center_out_P.PCIQUAD04_P10_Size
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 28;
	
	  ;% center_out_P.PCIQUAD04_P10
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 30;
	
	  ;% center_out_P.PCIQUAD04_P11_Size
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 31;
	
	  ;% center_out_P.PCIQUAD04_P11
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 33;
	
	  ;% center_out_P.Gain_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 34;
	
	  ;% center_out_P.shoulderOffset_Value
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 35;
	
	  ;% center_out_P.L1_Value
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 36;
	
	  ;% center_out_P.Gain_Gain_h
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 37;
	
	  ;% center_out_P.PCIQUAD041_P1_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 38;
	
	  ;% center_out_P.PCIQUAD041_P1
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 40;
	
	  ;% center_out_P.PCIQUAD041_P2_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 41;
	
	  ;% center_out_P.PCIQUAD041_P2
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 43;
	
	  ;% center_out_P.PCIQUAD041_P3_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 44;
	
	  ;% center_out_P.PCIQUAD041_P3
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 46;
	
	  ;% center_out_P.PCIQUAD041_P4_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 47;
	
	  ;% center_out_P.PCIQUAD041_P4
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 49;
	
	  ;% center_out_P.PCIQUAD041_P5_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 50;
	
	  ;% center_out_P.PCIQUAD041_P5
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 52;
	
	  ;% center_out_P.PCIQUAD041_P6_Size
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 53;
	
	  ;% center_out_P.PCIQUAD041_P6
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 55;
	
	  ;% center_out_P.PCIQUAD041_P7_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 56;
	
	  ;% center_out_P.PCIQUAD041_P7
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 58;
	
	  ;% center_out_P.PCIQUAD041_P8_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 59;
	
	  ;% center_out_P.PCIQUAD041_P8
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 61;
	
	  ;% center_out_P.PCIQUAD041_P9_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 62;
	
	  ;% center_out_P.PCIQUAD041_P9
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 64;
	
	  ;% center_out_P.PCIQUAD041_P10_Size
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 65;
	
	  ;% center_out_P.PCIQUAD041_P10
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 67;
	
	  ;% center_out_P.PCIQUAD041_P11_Size
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 68;
	
	  ;% center_out_P.PCIQUAD041_P11
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 70;
	
	  ;% center_out_P.Gain1_Gain
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 71;
	
	  ;% center_out_P.elbowOffset_Value
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 72;
	
	  ;% center_out_P.L2_Value
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 73;
	
	  ;% center_out_P.Gain1_Gain_o
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 74;
	
	  ;% center_out_P.Gain2_Gain
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 75;
	
	  ;% center_out_P.PCI6025EAD_P1_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 76;
	
	  ;% center_out_P.PCI6025EAD_P1
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 78;
	
	  ;% center_out_P.PCI6025EAD_P2_Size
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 80;
	
	  ;% center_out_P.PCI6025EAD_P2
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 82;
	
	  ;% center_out_P.PCI6025EAD_P3_Size
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 84;
	
	  ;% center_out_P.PCI6025EAD_P3
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 86;
	
	  ;% center_out_P.PCI6025EAD_P4_Size
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 88;
	
	  ;% center_out_P.PCI6025EAD_P4
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 90;
	
	  ;% center_out_P.PCI6025EAD_P5_Size
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 91;
	
	  ;% center_out_P.PCI6025EAD_P5
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 93;
	
	  ;% center_out_P.PCI6025EAD_P6_Size
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 94;
	
	  ;% center_out_P.PCI6025EAD_P6
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 96;
	
	  ;% center_out_P.UseTachs_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 97;
	
	  ;% center_out_P.yoffset_Value
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 98;
	
	  ;% center_out_P.xoffset_Value
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 99;
	
	  ;% center_out_P.AngleOffset_Value
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 100;
	
	  ;% center_out_P.DigitalFilter2_ICRTP
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 101;
	
	  ;% center_out_P.DigitalFilter2_RTP1COEFF
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 102;
	
	  ;% center_out_P.dG_Gain
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 113;
	
	  ;% center_out_P.DigitalFilter_ICRTP
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 114;
	
	  ;% center_out_P.DigitalFilter_RTP1COEFF
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 115;
	
	  ;% center_out_P.DigitalFilter2_ICRTP_i
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 126;
	
	  ;% center_out_P.DigitalFilter2_RTP1COEFF_n
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 127;
	
	  ;% center_out_P.dG_Gain_a
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 138;
	
	  ;% center_out_P.DigitalFilter_ICRTP_h
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 139;
	
	  ;% center_out_P.DigitalFilter_RTP1COEFF_n
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 140;
	
	  ;% center_out_P.Switch_Threshold
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 151;
	
	  ;% center_out_P.XLowLimit_Value
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 152;
	
	  ;% center_out_P.XHighLimit_Value
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 153;
	
	  ;% center_out_P.YHighLimit_Value
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 154;
	
	  ;% center_out_P.YLowLimit_Value
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 155;
	
	  ;% center_out_P.RecenterFlag_Value
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 156;
	
	  ;% center_out_P.Time_Value_h
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 157;
	
	  ;% center_out_P.Time_Value_hl
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 158;
	
	  ;% center_out_P.Constant_Value
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 159;
	
	  ;% center_out_P.Constant_Value_p
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 160;
	
	  ;% center_out_P.Time_Value_l
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 161;
	
	  ;% center_out_P.Time_Value_d
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 162;
	
	  ;% center_out_P.Load_Value
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 163;
	
	  ;% center_out_P.x_X0
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 164;
	
	  ;% center_out_P.x_X0_h
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 165;
	
	  ;% center_out_P.x_X0_p
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 166;
	
	  ;% center_out_P.x_X0_b
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 167;
	
	  ;% center_out_P.Load_Value_m
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 168;
	
	  ;% center_out_P.x_X0_j
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 169;
	
	  ;% center_out_P.x_X0_jq
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 170;
	
	  ;% center_out_P.x_X0_g
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 171;
	
	  ;% center_out_P.x_X0_pl
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 172;
	
	  ;% center_out_P.BehaviorCO_P1_Size
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 173;
	
	  ;% center_out_P.BehaviorCO_P1
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 175;
	
	  ;% center_out_P.BehaviorCO_P2_Size
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 176;
	
	  ;% center_out_P.BehaviorCO_P2
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 178;
	
	  ;% center_out_P.BehaviorCO_P3_Size
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 179;
	
	  ;% center_out_P.BehaviorCO_P3
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 181;
	
	  ;% center_out_P.BehaviorCO_P4_Size
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 182;
	
	  ;% center_out_P.BehaviorCO_P4
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 184;
	
	  ;% center_out_P.BehaviorCO_P5_Size
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 185;
	
	  ;% center_out_P.BehaviorCO_P5
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 187;
	
	  ;% center_out_P.BehaviorCO_P6_Size
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 188;
	
	  ;% center_out_P.BehaviorCO_P6
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 190;
	
	  ;% center_out_P.BehaviorCO_P7_Size
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 191;
	
	  ;% center_out_P.BehaviorCO_P7
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 193;
	
	  ;% center_out_P.BehaviorCO_P8_Size
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 194;
	
	  ;% center_out_P.BehaviorCO_P8
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 196;
	
	  ;% center_out_P.BehaviorCO_P9_Size
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 197;
	
	  ;% center_out_P.BehaviorCO_P9
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 199;
	
	  ;% center_out_P.BehaviorCO_P10_Size
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 200;
	
	  ;% center_out_P.BehaviorCO_P10
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 202;
	
	  ;% center_out_P.BehaviorCO_P11_Size
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 203;
	
	  ;% center_out_P.BehaviorCO_P11
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 205;
	
	  ;% center_out_P.BehaviorCO_P12_Size
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 206;
	
	  ;% center_out_P.BehaviorCO_P12
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 208;
	
	  ;% center_out_P.BehaviorCO_P13_Size
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 209;
	
	  ;% center_out_P.BehaviorCO_P13
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 211;
	
	  ;% center_out_P.BehaviorCO_P14_Size
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 212;
	
	  ;% center_out_P.BehaviorCO_P14
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 214;
	
	  ;% center_out_P.BehaviorCO_P15_Size
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 215;
	
	  ;% center_out_P.BehaviorCO_P15
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 217;
	
	  ;% center_out_P.BehaviorCO_P16_Size
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 218;
	
	  ;% center_out_P.BehaviorCO_P16
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 220;
	
	  ;% center_out_P.BehaviorCO_P17_Size
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 221;
	
	  ;% center_out_P.BehaviorCO_P17
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 223;
	
	  ;% center_out_P.BehaviorCO_P18_Size
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 224;
	
	  ;% center_out_P.BehaviorCO_P18
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 226;
	
	  ;% center_out_P.MG1_Gain
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 227;
	
	  ;% center_out_P.MG2_Gain
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 228;
	
	  ;% center_out_P.PCI6025E_P1_Size
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 229;
	
	  ;% center_out_P.PCI6025E_P1
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 231;
	
	  ;% center_out_P.PCI6025E_P2_Size
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 233;
	
	  ;% center_out_P.PCI6025E_P2
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 235;
	
	  ;% center_out_P.PCI6025E_P3_Size
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 237;
	
	  ;% center_out_P.PCI6025E_P3
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 239;
	
	  ;% center_out_P.PCI6025E_P4_Size
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 241;
	
	  ;% center_out_P.PCI6025E_P4
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 243;
	
	  ;% center_out_P.PCI6025E_P5_Size
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 245;
	
	  ;% center_out_P.PCI6025E_P5
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 247;
	
	  ;% center_out_P.PCI6025E_P6_Size
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 248;
	
	  ;% center_out_P.PCI6025E_P6
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 250;
	
	  ;% center_out_P.PCI6025E_P7_Size
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 251;
	
	  ;% center_out_P.PCI6025E_P7
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 253;
	
	  ;% center_out_P.Constant_Value_h
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 254;
	
	  ;% center_out_P.Constant_Value_k
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 255;
	
	  ;% center_out_P.Send_P1_Size
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 256;
	
	  ;% center_out_P.Send_P1
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 258;
	
	  ;% center_out_P.Send_P2_Size
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 269;
	
	  ;% center_out_P.Send_P2
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 271;
	
	  ;% center_out_P.Send_P3_Size
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 272;
	
	  ;% center_out_P.Send_P3
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 274;
	
	  ;% center_out_P.Send_P4_Size
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 275;
	
	  ;% center_out_P.Send_P4
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 277;
	
	  ;% center_out_P.UniformRandomNumber_Min
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 278;
	
	  ;% center_out_P.UniformRandomNumber_Max
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 279;
	
	  ;% center_out_P.UniformRandomNumber_Seed
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 280;
	
	  ;% center_out_P.JackpotChance_Value
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 281;
	
	  ;% center_out_P.y_X0
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 282;
	
	  ;% center_out_P.rho_Value
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 283;
	
	  ;% center_out_P.z_X0
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 284;
	
	  ;% center_out_P.beta_Value
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 285;
	
	  ;% center_out_P.timescale_Value
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 286;
	
	  ;% center_out_P.sigma_Value
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 287;
	
	  ;% center_out_P.y_X0_i
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 288;
	
	  ;% center_out_P.rho_Value_d
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 289;
	
	  ;% center_out_P.z_X0_c
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 290;
	
	  ;% center_out_P.beta_Value_e
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 291;
	
	  ;% center_out_P.timescale_Value_m
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 292;
	
	  ;% center_out_P.sigma_Value_k
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 293;
	
	  ;% center_out_P.y_X0_p
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 294;
	
	  ;% center_out_P.rho_Value_n
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 295;
	
	  ;% center_out_P.z_X0_j
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 296;
	
	  ;% center_out_P.beta_Value_m
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 297;
	
	  ;% center_out_P.timescale_Value_a
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 298;
	
	  ;% center_out_P.sigma_Value_e
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 299;
	
	  ;% center_out_P.y_X0_n
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 300;
	
	  ;% center_out_P.rho_Value_d2
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 301;
	
	  ;% center_out_P.z_X0_f
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 302;
	
	  ;% center_out_P.beta_Value_i
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 303;
	
	  ;% center_out_P.timescale_Value_l
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 304;
	
	  ;% center_out_P.sigma_Value_p
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 305;
	
	  ;% center_out_P.y_X0_f
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 306;
	
	  ;% center_out_P.rho_Value_p
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 307;
	
	  ;% center_out_P.z_X0_a
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 308;
	
	  ;% center_out_P.beta_Value_ez
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 309;
	
	  ;% center_out_P.timescale_Value_lp
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 310;
	
	  ;% center_out_P.sigma_Value_c
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 311;
	
	  ;% center_out_P.y_X0_j
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 312;
	
	  ;% center_out_P.rho_Value_f
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 313;
	
	  ;% center_out_P.z_X0_b
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 314;
	
	  ;% center_out_P.beta_Value_mt
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 315;
	
	  ;% center_out_P.timescale_Value_c
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 316;
	
	  ;% center_out_P.sigma_Value_h
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 317;
	
	  ;% center_out_P.y_X0_o
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 318;
	
	  ;% center_out_P.rho_Value_g
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 319;
	
	  ;% center_out_P.z_X0_e
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 320;
	
	  ;% center_out_P.beta_Value_b
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 321;
	
	  ;% center_out_P.timescale_Value_k
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 322;
	
	  ;% center_out_P.sigma_Value_m
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 323;
	
	  ;% center_out_P.y_X0_d
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 324;
	
	  ;% center_out_P.rho_Value_j
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 325;
	
	  ;% center_out_P.z_X0_d
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 326;
	
	  ;% center_out_P.beta_Value_a
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 327;
	
	  ;% center_out_P.timescale_Value_i
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 328;
	
	  ;% center_out_P.sigma_Value_hn
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 329;
	
	  ;% center_out_P.Gain_Gain_l
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 330;
	
	  ;% center_out_P.Gain1_Gain_g
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 331;
	
	  ;% center_out_P.Gain_Gain_i
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 332;
	
	  ;% center_out_P.visAngle_Value
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 333;
	
	  ;% center_out_P.DynamicAngle_Value
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 334;
	
	  ;% center_out_P.Inverter_Gain
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 335;
	
	  ;% center_out_P.Gain_Gain_iu
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 336;
	
	  ;% center_out_P.LorentzForceGain_Gain
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 337;
	
	  ;% center_out_P.staticX_Value
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 338;
	
	  ;% center_out_P.staticY_Value
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 339;
	
	  ;% center_out_P.Off_Value
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 340;
	
	  ;% center_out_P.Gain_Gain_g
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 341;
	
	  ;% center_out_P.visAngle_Value_g
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 342;
	
	  ;% center_out_P.DynamicAngle_Value_k
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 343;
	
	  ;% center_out_P.Inverter_Gain_o
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 344;
	
	  ;% center_out_P.Gain_Gain_lp
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 345;
	
	  ;% center_out_P.LorentzForceGain_Gain_j
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 346;
	
	  ;% center_out_P.staticX_Value_c
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 347;
	
	  ;% center_out_P.staticY_Value_n
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 348;
	
	  ;% center_out_P.Off_Value_k
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 349;
	
	  ;% center_out_P.Gain1_Gain_p
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 350;
	
	  ;% center_out_P.Gain3_Gain
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 351;
	
	  ;% center_out_P.Saturation_UpperSat
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 352;
	
	  ;% center_out_P.Saturation_LowerSat
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 353;
	
	  ;% center_out_P.Gain4_Gain
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 354;
	
	  ;% center_out_P.Gain2_Gain_e
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 355;
	
	  ;% center_out_P.Saturation1_UpperSat
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 356;
	
	  ;% center_out_P.Saturation1_LowerSat
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 357;
	
	  ;% center_out_P.BoundingBoxViscosity_Gain
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 358;
	
	  ;% center_out_P.zeroX_Value
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 359;
	
	  ;% center_out_P.zeroY_Value
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 360;
	
	  ;% center_out_P.Gain_Gain_d
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 361;
	
	  ;% center_out_P.RewardJackpot_Value
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 362;
	
	  ;% center_out_P.RewardTime_Value
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 363;
	
	  ;% center_out_P.TachGain2_Gain
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 364;
	
	  ;% center_out_P.TachGain1_Gain
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 365;
	
	  ;% center_out_P.Constant2_Value
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 366;
	
	  ;% center_out_P.Constant1_Value
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 367;
	
	  ;% center_out_P.Constant_Value_i
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 368;
	
	  ;% center_out_P.xPCTargetTime_P1_Size
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 369;
	
	  ;% center_out_P.xPCTargetTime_P1
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 371;
	
	  ;% center_out_P.xPCTargetTime_P2_Size
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 372;
	
	  ;% center_out_P.xPCTargetTime_P2
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 374;
	
	  ;% center_out_P.ScaleTouSec_Gain
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 375;
	
	  ;% center_out_P.Constant_Value_pu
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 376;
	
	  ;% center_out_P.PCI6025E_P1_Size_g
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 377;
	
	  ;% center_out_P.PCI6025E_P1_l
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 379;
	
	  ;% center_out_P.PCI6025E_P2_Size_i
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 381;
	
	  ;% center_out_P.PCI6025E_P2_c
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 383;
	
	  ;% center_out_P.PCI6025E_P3_Size_b
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 385;
	
	  ;% center_out_P.PCI6025E_P3_i
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 387;
	
	  ;% center_out_P.PCI6025E_P4_Size_p
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 389;
	
	  ;% center_out_P.PCI6025E_P4_c
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 391;
	
	  ;% center_out_P.PCI6025E_P5_Size_m
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 392;
	
	  ;% center_out_P.PCI6025E_P5_d
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 394;
	
	  ;% center_out_P.PCI6025E_P6_Size_g
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 395;
	
	  ;% center_out_P.PCI6025E_P6_m
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 397;
	
	  ;% center_out_P.PCI6025E_P7_Size_l
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 398;
	
	  ;% center_out_P.PCI6025E_P7_h
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 400;
	
	  ;% center_out_P.Constant_Value_c
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 401;
	
	  ;% center_out_P.Switch_Threshold_p
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 402;
	
	  ;% center_out_P.PortA_P1_Size
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 403;
	
	  ;% center_out_P.PortA_P1
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 405;
	
	  ;% center_out_P.PortA_P2_Size
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 413;
	
	  ;% center_out_P.PortA_P2
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 415;
	
	  ;% center_out_P.PortA_P3_Size
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 416;
	
	  ;% center_out_P.PortA_P3
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 418;
	
	  ;% center_out_P.PortA_P4_Size
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 426;
	
	  ;% center_out_P.PortA_P4
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 428;
	
	  ;% center_out_P.PortA_P5_Size
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 436;
	
	  ;% center_out_P.PortA_P5
	  section.data(287).logicalSrcIdx = 286;
	  section.data(287).dtTransOffset = 438;
	
	  ;% center_out_P.PortA_P6_Size
	  section.data(288).logicalSrcIdx = 287;
	  section.data(288).dtTransOffset = 439;
	
	  ;% center_out_P.PortA_P6
	  section.data(289).logicalSrcIdx = 288;
	  section.data(289).dtTransOffset = 441;
	
	  ;% center_out_P.PortA_P7_Size
	  section.data(290).logicalSrcIdx = 289;
	  section.data(290).dtTransOffset = 442;
	
	  ;% center_out_P.PortA_P7
	  section.data(291).logicalSrcIdx = 290;
	  section.data(291).dtTransOffset = 444;
	
	  ;% center_out_P.PortA_P8_Size
	  section.data(292).logicalSrcIdx = 291;
	  section.data(292).dtTransOffset = 445;
	
	  ;% center_out_P.PortA_P8
	  section.data(293).logicalSrcIdx = 292;
	  section.data(293).dtTransOffset = 447;
	
	  ;% center_out_P.PortA_P9_Size
	  section.data(294).logicalSrcIdx = 293;
	  section.data(294).dtTransOffset = 448;
	
	  ;% center_out_P.PortA_P9
	  section.data(295).logicalSrcIdx = 294;
	  section.data(295).dtTransOffset = 450;
	
	  ;% center_out_P.Constant_Value_o
	  section.data(296).logicalSrcIdx = 295;
	  section.data(296).dtTransOffset = 451;
	
	  ;% center_out_P.PortB_P1_Size
	  section.data(297).logicalSrcIdx = 296;
	  section.data(297).dtTransOffset = 452;
	
	  ;% center_out_P.PortB_P1
	  section.data(298).logicalSrcIdx = 297;
	  section.data(298).dtTransOffset = 454;
	
	  ;% center_out_P.PortB_P2_Size
	  section.data(299).logicalSrcIdx = 298;
	  section.data(299).dtTransOffset = 462;
	
	  ;% center_out_P.PortB_P2
	  section.data(300).logicalSrcIdx = 299;
	  section.data(300).dtTransOffset = 464;
	
	  ;% center_out_P.PortB_P3_Size
	  section.data(301).logicalSrcIdx = 300;
	  section.data(301).dtTransOffset = 465;
	
	  ;% center_out_P.PortB_P3
	  section.data(302).logicalSrcIdx = 301;
	  section.data(302).dtTransOffset = 467;
	
	  ;% center_out_P.PortB_P4_Size
	  section.data(303).logicalSrcIdx = 302;
	  section.data(303).dtTransOffset = 475;
	
	  ;% center_out_P.PortB_P4
	  section.data(304).logicalSrcIdx = 303;
	  section.data(304).dtTransOffset = 477;
	
	  ;% center_out_P.PortB_P5_Size
	  section.data(305).logicalSrcIdx = 304;
	  section.data(305).dtTransOffset = 485;
	
	  ;% center_out_P.PortB_P5
	  section.data(306).logicalSrcIdx = 305;
	  section.data(306).dtTransOffset = 487;
	
	  ;% center_out_P.PortB_P6_Size
	  section.data(307).logicalSrcIdx = 306;
	  section.data(307).dtTransOffset = 488;
	
	  ;% center_out_P.PortB_P6
	  section.data(308).logicalSrcIdx = 307;
	  section.data(308).dtTransOffset = 490;
	
	  ;% center_out_P.PortB_P7_Size
	  section.data(309).logicalSrcIdx = 308;
	  section.data(309).dtTransOffset = 491;
	
	  ;% center_out_P.PortB_P7
	  section.data(310).logicalSrcIdx = 309;
	  section.data(310).dtTransOffset = 493;
	
	  ;% center_out_P.PortB_P8_Size
	  section.data(311).logicalSrcIdx = 310;
	  section.data(311).dtTransOffset = 494;
	
	  ;% center_out_P.PortB_P8
	  section.data(312).logicalSrcIdx = 311;
	  section.data(312).dtTransOffset = 496;
	
	  ;% center_out_P.PortB_P9_Size
	  section.data(313).logicalSrcIdx = 312;
	  section.data(313).dtTransOffset = 497;
	
	  ;% center_out_P.PortB_P9
	  section.data(314).logicalSrcIdx = 313;
	  section.data(314).dtTransOffset = 499;
	
	  ;% center_out_P.xPCTargetTime_P1_Size_i
	  section.data(315).logicalSrcIdx = 314;
	  section.data(315).dtTransOffset = 500;
	
	  ;% center_out_P.xPCTargetTime_P1_f
	  section.data(316).logicalSrcIdx = 315;
	  section.data(316).dtTransOffset = 502;
	
	  ;% center_out_P.xPCTargetTime_P2_Size_a
	  section.data(317).logicalSrcIdx = 316;
	  section.data(317).dtTransOffset = 503;
	
	  ;% center_out_P.xPCTargetTime_P2_h
	  section.data(318).logicalSrcIdx = 317;
	  section.data(318).dtTransOffset = 505;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% center_out_P.DelayInput1_X0
	  section.data(1).logicalSrcIdx = 318;
	  section.data(1).dtTransOffset = 0;
	
	  ;% center_out_P.DelayInput1_X0_i
	  section.data(2).logicalSrcIdx = 319;
	  section.data(2).dtTransOffset = 1;
	
	  ;% center_out_P.DelayInput1_X0_e
	  section.data(3).logicalSrcIdx = 320;
	  section.data(3).dtTransOffset = 2;
	
	  ;% center_out_P.DelayInput1_X0_g
	  section.data(4).logicalSrcIdx = 321;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% center_out_P.Memory_X0
	  section.data(1).logicalSrcIdx = 322;
	  section.data(1).dtTransOffset = 0;
	
	  ;% center_out_P.Memory_X0_e
	  section.data(2).logicalSrcIdx = 323;
	  section.data(2).dtTransOffset = 1;
	
	  ;% center_out_P.Memory_X0_ew
	  section.data(3).logicalSrcIdx = 324;
	  section.data(3).dtTransOffset = 2;
	
	  ;% center_out_P.Memory_X0_i
	  section.data(4).logicalSrcIdx = 325;
	  section.data(4).dtTransOffset = 3;
	
	  ;% center_out_P.Memory_X0_b
	  section.data(5).logicalSrcIdx = 326;
	  section.data(5).dtTransOffset = 4;
	
	  ;% center_out_P.Memory_X0_l
	  section.data(6).logicalSrcIdx = 327;
	  section.data(6).dtTransOffset = 5;
	
	  ;% center_out_P.Memory_X0_a
	  section.data(7).logicalSrcIdx = 328;
	  section.data(7).dtTransOffset = 6;
	
	  ;% center_out_P.Logic_table
	  section.data(8).logicalSrcIdx = 329;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_P.SampleandHold._Y0
	  section.data(1).logicalSrcIdx = 330;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_P.SampleandHold_e._Y0
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
    ;% Auto data (center_out_B)
    ;%
      section.nData     = 286;
      section.data(286)  = dumData; %prealloc
      
	  ;% center_out_B.Clock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% center_out_B.Sum
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% center_out_B.PCIQUAD04
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% center_out_B.Gain
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% center_out_B.Sum3
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% center_out_B.TrigonometricFunction
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% center_out_B.Product
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% center_out_B.TrigonometricFunction1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% center_out_B.Product1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% center_out_B.PCIQUAD041
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% center_out_B.Gain1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% center_out_B.Sum1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% center_out_B.TrigonometricFunction2
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% center_out_B.Product2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% center_out_B.TrigonometricFunction3
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% center_out_B.Product3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% center_out_B.MatrixConcatenate2
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% center_out_B.PCI6025EAD_o1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 20;
	
	  ;% center_out_B.PCI6025EAD_o2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% center_out_B.Sum2
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% center_out_B.Sum4
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% center_out_B.Sum3_d
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% center_out_B.Sum1_k
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% center_out_B.TrigonometricFunction1_p
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% center_out_B.Sum_j
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 27;
	
	  ;% center_out_B.TrigonometricFunction2_j
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 28;
	
	  ;% center_out_B.sqrtu1u1u2u2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 29;
	
	  ;% center_out_B.Product1_d
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 30;
	
	  ;% center_out_B.DigitalFilter2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 31;
	
	  ;% center_out_B.Derivative
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 32;
	
	  ;% center_out_B.dG
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 33;
	
	  ;% center_out_B.DigitalFilter
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 34;
	
	  ;% center_out_B.TrigonometricFunction_d
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 35;
	
	  ;% center_out_B.Product_l
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 36;
	
	  ;% center_out_B.DigitalFilter2_l
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 37;
	
	  ;% center_out_B.Derivative_m
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 38;
	
	  ;% center_out_B.dG_f
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 39;
	
	  ;% center_out_B.DigitalFilter_m
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 40;
	
	  ;% center_out_B.Switch
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 41;
	
	  ;% center_out_B.Clock_e
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 43;
	
	  ;% center_out_B.Clock_o
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 44;
	
	  ;% center_out_B.Sum_h
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 45;
	
	  ;% center_out_B.Sum_n
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 46;
	
	  ;% center_out_B.Abs2
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 47;
	
	  ;% center_out_B.Abs3
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 48;
	
	  ;% center_out_B.Clock_j
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 49;
	
	  ;% center_out_B.Sum_d
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 50;
	
	  ;% center_out_B.Clock_d
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 51;
	
	  ;% center_out_B.Sum_ju
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 52;
	
	  ;% center_out_B.x
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 53;
	
	  ;% center_out_B.x_j
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 54;
	
	  ;% center_out_B.Add
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 55;
	
	  ;% center_out_B.x_k
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 56;
	
	  ;% center_out_B.x_l
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 57;
	
	  ;% center_out_B.MultiportSwitch
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 58;
	
	  ;% center_out_B.x_g
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 60;
	
	  ;% center_out_B.x_f
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 61;
	
	  ;% center_out_B.Add_g
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 62;
	
	  ;% center_out_B.x_p
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 63;
	
	  ;% center_out_B.x_g2
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 64;
	
	  ;% center_out_B.LoadSelectSwitch
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 65;
	
	  ;% center_out_B.BehaviorCO_o1
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 67;
	
	  ;% center_out_B.BehaviorCO_o2
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 69;
	
	  ;% center_out_B.BehaviorCO_o3
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 74;
	
	  ;% center_out_B.BehaviorCO_o4
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 75;
	
	  ;% center_out_B.BehaviorCO_o5
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 85;
	
	  ;% center_out_B.BehaviorCO_o6
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 86;
	
	  ;% center_out_B.BehaviorCO_o7
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 88;
	
	  ;% center_out_B.BehaviorCO_o8
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 92;
	
	  ;% center_out_B.Switch2
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 94;
	
	  ;% center_out_B.MG1
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 96;
	
	  ;% center_out_B.MG2
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 97;
	
	  ;% center_out_B.Clock_a
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 98;
	
	  ;% center_out_B.HiddenBuf_InsertedFor_Sampleand
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 99;
	
	  ;% center_out_B.Sum_c
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 100;
	
	  ;% center_out_B.UniformRandomNumber
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 101;
	
	  ;% center_out_B.Switch_m
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 102;
	
	  ;% center_out_B.HiddenBuf_InsertedFor_Samplea_i
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 103;
	
	  ;% center_out_B.DataTypeConversion
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 104;
	
	  ;% center_out_B.y
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 105;
	
	  ;% center_out_B.Add1
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 106;
	
	  ;% center_out_B.z
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 107;
	
	  ;% center_out_B.Add3
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 108;
	
	  ;% center_out_B.product2
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 109;
	
	  ;% center_out_B.Add2
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 110;
	
	  ;% center_out_B.product3
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 111;
	
	  ;% center_out_B.product4
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 112;
	
	  ;% center_out_B.Add4
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 113;
	
	  ;% center_out_B.product1
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 114;
	
	  ;% center_out_B.dX
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 115;
	
	  ;% center_out_B.AddX
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 116;
	
	  ;% center_out_B.dY
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 117;
	
	  ;% center_out_B.AddX1
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 118;
	
	  ;% center_out_B.dZ
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 119;
	
	  ;% center_out_B.AddX2
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 120;
	
	  ;% center_out_B.y_l
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 121;
	
	  ;% center_out_B.Add1_m
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 122;
	
	  ;% center_out_B.z_h
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 123;
	
	  ;% center_out_B.Add3_i
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 124;
	
	  ;% center_out_B.product2_b
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 125;
	
	  ;% center_out_B.Add2_i
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 126;
	
	  ;% center_out_B.product3_b
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 127;
	
	  ;% center_out_B.product4_e
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 128;
	
	  ;% center_out_B.Add4_a
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 129;
	
	  ;% center_out_B.product1_j
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 130;
	
	  ;% center_out_B.dX_o
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 131;
	
	  ;% center_out_B.AddX_m
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 132;
	
	  ;% center_out_B.dY_e
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 133;
	
	  ;% center_out_B.AddX1_g
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 134;
	
	  ;% center_out_B.dZ_j
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 135;
	
	  ;% center_out_B.AddX2_n
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 136;
	
	  ;% center_out_B.y_m
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 137;
	
	  ;% center_out_B.Add1_d
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 138;
	
	  ;% center_out_B.z_a
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 139;
	
	  ;% center_out_B.Add3_p
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 140;
	
	  ;% center_out_B.product2_k
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 141;
	
	  ;% center_out_B.Add2_e
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 142;
	
	  ;% center_out_B.product3_i
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 143;
	
	  ;% center_out_B.product4_a
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 144;
	
	  ;% center_out_B.Add4_h
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 145;
	
	  ;% center_out_B.product1_a
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 146;
	
	  ;% center_out_B.dX_j
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 147;
	
	  ;% center_out_B.AddX_l
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 148;
	
	  ;% center_out_B.dY_eo
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 149;
	
	  ;% center_out_B.AddX1_a
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 150;
	
	  ;% center_out_B.dZ_b
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 151;
	
	  ;% center_out_B.AddX2_a
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 152;
	
	  ;% center_out_B.y_d
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 153;
	
	  ;% center_out_B.Add1_n
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 154;
	
	  ;% center_out_B.z_l
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 155;
	
	  ;% center_out_B.Add3_k
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 156;
	
	  ;% center_out_B.product2_g
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 157;
	
	  ;% center_out_B.Add2_d
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 158;
	
	  ;% center_out_B.product3_j
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 159;
	
	  ;% center_out_B.product4_j
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 160;
	
	  ;% center_out_B.Add4_f
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 161;
	
	  ;% center_out_B.product1_p
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 162;
	
	  ;% center_out_B.dX_l
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 163;
	
	  ;% center_out_B.AddX_d
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 164;
	
	  ;% center_out_B.dY_b
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 165;
	
	  ;% center_out_B.AddX1_d
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 166;
	
	  ;% center_out_B.dZ_m
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 167;
	
	  ;% center_out_B.AddX2_l
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 168;
	
	  ;% center_out_B.y_j
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 169;
	
	  ;% center_out_B.Add1_nw
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 170;
	
	  ;% center_out_B.z_f
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 171;
	
	  ;% center_out_B.Add3_k3
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 172;
	
	  ;% center_out_B.product2_h
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 173;
	
	  ;% center_out_B.Add2_p
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 174;
	
	  ;% center_out_B.product3_m
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 175;
	
	  ;% center_out_B.product4_b
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 176;
	
	  ;% center_out_B.Add4_l
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 177;
	
	  ;% center_out_B.product1_m
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 178;
	
	  ;% center_out_B.dX_g
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 179;
	
	  ;% center_out_B.AddX_k
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 180;
	
	  ;% center_out_B.dY_i
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 181;
	
	  ;% center_out_B.AddX1_e
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 182;
	
	  ;% center_out_B.dZ_i
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 183;
	
	  ;% center_out_B.AddX2_c
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 184;
	
	  ;% center_out_B.y_e
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 185;
	
	  ;% center_out_B.Add1_b
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 186;
	
	  ;% center_out_B.z_o
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 187;
	
	  ;% center_out_B.Add3_pw
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 188;
	
	  ;% center_out_B.product2_ka
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 189;
	
	  ;% center_out_B.Add2_db
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 190;
	
	  ;% center_out_B.product3_l
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 191;
	
	  ;% center_out_B.product4_n
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 192;
	
	  ;% center_out_B.Add4_c
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 193;
	
	  ;% center_out_B.product1_d
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 194;
	
	  ;% center_out_B.dX_e
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 195;
	
	  ;% center_out_B.AddX_ko
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 196;
	
	  ;% center_out_B.dY_bm
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 197;
	
	  ;% center_out_B.AddX1_b
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 198;
	
	  ;% center_out_B.dZ_o
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 199;
	
	  ;% center_out_B.AddX2_f
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 200;
	
	  ;% center_out_B.y_e3
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 201;
	
	  ;% center_out_B.Add1_j
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 202;
	
	  ;% center_out_B.z_b
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 203;
	
	  ;% center_out_B.Add3_l
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 204;
	
	  ;% center_out_B.product2_o
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 205;
	
	  ;% center_out_B.Add2_a
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 206;
	
	  ;% center_out_B.product3_a
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 207;
	
	  ;% center_out_B.product4_n1
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 208;
	
	  ;% center_out_B.Add4_n
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 209;
	
	  ;% center_out_B.product1_d2
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 210;
	
	  ;% center_out_B.dX_b
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 211;
	
	  ;% center_out_B.AddX_lw
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 212;
	
	  ;% center_out_B.dY_k
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 213;
	
	  ;% center_out_B.AddX1_aj
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 214;
	
	  ;% center_out_B.dZ_f
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 215;
	
	  ;% center_out_B.AddX2_k
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 216;
	
	  ;% center_out_B.y_n
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 217;
	
	  ;% center_out_B.Add1_e
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 218;
	
	  ;% center_out_B.z_bj
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 219;
	
	  ;% center_out_B.Add3_e
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 220;
	
	  ;% center_out_B.product2_i
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 221;
	
	  ;% center_out_B.Add2_as
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 222;
	
	  ;% center_out_B.product3_be
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 223;
	
	  ;% center_out_B.product4_a1
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 224;
	
	  ;% center_out_B.Add4_e
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 225;
	
	  ;% center_out_B.product1_d3
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 226;
	
	  ;% center_out_B.dX_bv
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 227;
	
	  ;% center_out_B.AddX_n
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 228;
	
	  ;% center_out_B.dY_f
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 229;
	
	  ;% center_out_B.AddX1_h
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 230;
	
	  ;% center_out_B.dZ_ms
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 231;
	
	  ;% center_out_B.AddX2_e
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 232;
	
	  ;% center_out_B.MatrixConcatenation1
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 233;
	
	  ;% center_out_B.Add_p
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 237;
	
	  ;% center_out_B.Add1_l
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 238;
	
	  ;% center_out_B.Gain_m
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 239;
	
	  ;% center_out_B.Gain1_h
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 240;
	
	  ;% center_out_B.ForIterator
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 241;
	
	  ;% center_out_B.Switch_e
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 242;
	
	  ;% center_out_B.ToBits1_o1
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 243;
	
	  ;% center_out_B.ToBits1_o2
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 244;
	
	  ;% center_out_B.ToBits1_o3
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 245;
	
	  ;% center_out_B.ToBits1_o4
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 246;
	
	  ;% center_out_B.ToBits1_o5
	  section.data(219).logicalSrcIdx = 218;
	  section.data(219).dtTransOffset = 247;
	
	  ;% center_out_B.ToBits1_o6
	  section.data(220).logicalSrcIdx = 219;
	  section.data(220).dtTransOffset = 248;
	
	  ;% center_out_B.ToBits1_o7
	  section.data(221).logicalSrcIdx = 220;
	  section.data(221).dtTransOffset = 249;
	
	  ;% center_out_B.ToBits1_o8
	  section.data(222).logicalSrcIdx = 221;
	  section.data(222).dtTransOffset = 250;
	
	  ;% center_out_B.Add_m
	  section.data(223).logicalSrcIdx = 222;
	  section.data(223).dtTransOffset = 251;
	
	  ;% center_out_B.Add1_dz
	  section.data(224).logicalSrcIdx = 223;
	  section.data(224).dtTransOffset = 252;
	
	  ;% center_out_B.SerialConverter
	  section.data(225).logicalSrcIdx = 224;
	  section.data(225).dtTransOffset = 253;
	
	  ;% center_out_B.ToBits_o1
	  section.data(226).logicalSrcIdx = 225;
	  section.data(226).dtTransOffset = 254;
	
	  ;% center_out_B.ToBits_o2
	  section.data(227).logicalSrcIdx = 226;
	  section.data(227).dtTransOffset = 255;
	
	  ;% center_out_B.ToBits_o3
	  section.data(228).logicalSrcIdx = 227;
	  section.data(228).dtTransOffset = 256;
	
	  ;% center_out_B.ToBits_o4
	  section.data(229).logicalSrcIdx = 228;
	  section.data(229).dtTransOffset = 257;
	
	  ;% center_out_B.ToBits_o5
	  section.data(230).logicalSrcIdx = 229;
	  section.data(230).dtTransOffset = 258;
	
	  ;% center_out_B.ToBits_o6
	  section.data(231).logicalSrcIdx = 230;
	  section.data(231).dtTransOffset = 259;
	
	  ;% center_out_B.ToBits_o7
	  section.data(232).logicalSrcIdx = 231;
	  section.data(232).dtTransOffset = 260;
	
	  ;% center_out_B.ToBits_o8
	  section.data(233).logicalSrcIdx = 232;
	  section.data(233).dtTransOffset = 261;
	
	  ;% center_out_B.xPCTargetTime
	  section.data(234).logicalSrcIdx = 233;
	  section.data(234).dtTransOffset = 262;
	
	  ;% center_out_B.xPCTargetTime_d
	  section.data(235).logicalSrcIdx = 234;
	  section.data(235).dtTransOffset = 263;
	
	  ;% center_out_B.Subtract
	  section.data(236).logicalSrcIdx = 235;
	  section.data(236).dtTransOffset = 264;
	
	  ;% center_out_B.ScaleTouSec
	  section.data(237).logicalSrcIdx = 236;
	  section.data(237).dtTransOffset = 265;
	
	  ;% center_out_B.Switch_a
	  section.data(238).logicalSrcIdx = 237;
	  section.data(238).dtTransOffset = 266;
	
	  ;% center_out_B.TachGain2
	  section.data(239).logicalSrcIdx = 238;
	  section.data(239).dtTransOffset = 267;
	
	  ;% center_out_B.TachGain1
	  section.data(240).logicalSrcIdx = 239;
	  section.data(240).dtTransOffset = 268;
	
	  ;% center_out_B.TmpHiddenBufferAtMatrixMultiply
	  section.data(241).logicalSrcIdx = 240;
	  section.data(241).dtTransOffset = 269;
	
	  ;% center_out_B.MatrixMultiply
	  section.data(242).logicalSrcIdx = 241;
	  section.data(242).dtTransOffset = 271;
	
	  ;% center_out_B.Gain_e
	  section.data(243).logicalSrcIdx = 242;
	  section.data(243).dtTransOffset = 273;
	
	  ;% center_out_B.MathFunction
	  section.data(244).logicalSrcIdx = 243;
	  section.data(244).dtTransOffset = 275;
	
	  ;% center_out_B.MatrixMultiply_k
	  section.data(245).logicalSrcIdx = 244;
	  section.data(245).dtTransOffset = 279;
	
	  ;% center_out_B.Switch1
	  section.data(246).logicalSrcIdx = 245;
	  section.data(246).dtTransOffset = 281;
	
	  ;% center_out_B.Switch_o
	  section.data(247).logicalSrcIdx = 246;
	  section.data(247).dtTransOffset = 283;
	
	  ;% center_out_B.BoundingBoxViscosity
	  section.data(248).logicalSrcIdx = 247;
	  section.data(248).dtTransOffset = 285;
	
	  ;% center_out_B.Product_a
	  section.data(249).logicalSrcIdx = 248;
	  section.data(249).dtTransOffset = 287;
	
	  ;% center_out_B.Gain1_i
	  section.data(250).logicalSrcIdx = 249;
	  section.data(250).dtTransOffset = 288;
	
	  ;% center_out_B.Gain3
	  section.data(251).logicalSrcIdx = 250;
	  section.data(251).dtTransOffset = 289;
	
	  ;% center_out_B.Add_gi
	  section.data(252).logicalSrcIdx = 251;
	  section.data(252).dtTransOffset = 290;
	
	  ;% center_out_B.Saturation
	  section.data(253).logicalSrcIdx = 252;
	  section.data(253).dtTransOffset = 291;
	
	  ;% center_out_B.Gain4
	  section.data(254).logicalSrcIdx = 253;
	  section.data(254).dtTransOffset = 292;
	
	  ;% center_out_B.Product1_k
	  section.data(255).logicalSrcIdx = 254;
	  section.data(255).dtTransOffset = 293;
	
	  ;% center_out_B.Gain2
	  section.data(256).logicalSrcIdx = 255;
	  section.data(256).dtTransOffset = 294;
	
	  ;% center_out_B.Add1_a
	  section.data(257).logicalSrcIdx = 256;
	  section.data(257).dtTransOffset = 295;
	
	  ;% center_out_B.Saturation1
	  section.data(258).logicalSrcIdx = 257;
	  section.data(258).dtTransOffset = 296;
	
	  ;% center_out_B.Add1_k
	  section.data(259).logicalSrcIdx = 258;
	  section.data(259).dtTransOffset = 297;
	
	  ;% center_out_B.LorentzForceGain
	  section.data(260).logicalSrcIdx = 259;
	  section.data(260).dtTransOffset = 298;
	
	  ;% center_out_B.dynamicAngleSwitch
	  section.data(261).logicalSrcIdx = 260;
	  section.data(261).dtTransOffset = 300;
	
	  ;% center_out_B.sin_o
	  section.data(262).logicalSrcIdx = 261;
	  section.data(262).dtTransOffset = 301;
	
	  ;% center_out_B.Inverter
	  section.data(263).logicalSrcIdx = 262;
	  section.data(263).dtTransOffset = 302;
	
	  ;% center_out_B.Product3_f
	  section.data(264).logicalSrcIdx = 263;
	  section.data(264).dtTransOffset = 304;
	
	  ;% center_out_B.cos_l
	  section.data(265).logicalSrcIdx = 264;
	  section.data(265).dtTransOffset = 305;
	
	  ;% center_out_B.Product2_k
	  section.data(266).logicalSrcIdx = 265;
	  section.data(266).dtTransOffset = 306;
	
	  ;% center_out_B.Subtract_k
	  section.data(267).logicalSrcIdx = 266;
	  section.data(267).dtTransOffset = 307;
	
	  ;% center_out_B.Product1_c
	  section.data(268).logicalSrcIdx = 267;
	  section.data(268).dtTransOffset = 308;
	
	  ;% center_out_B.Product_h
	  section.data(269).logicalSrcIdx = 268;
	  section.data(269).dtTransOffset = 309;
	
	  ;% center_out_B.Add_h
	  section.data(270).logicalSrcIdx = 269;
	  section.data(270).dtTransOffset = 310;
	
	  ;% center_out_B.Gain_k
	  section.data(271).logicalSrcIdx = 270;
	  section.data(271).dtTransOffset = 311;
	
	  ;% center_out_B.Gain_l
	  section.data(272).logicalSrcIdx = 271;
	  section.data(272).dtTransOffset = 313;
	
	  ;% center_out_B.Add1_j2
	  section.data(273).logicalSrcIdx = 272;
	  section.data(273).dtTransOffset = 314;
	
	  ;% center_out_B.LorentzForceGain_o
	  section.data(274).logicalSrcIdx = 273;
	  section.data(274).dtTransOffset = 315;
	
	  ;% center_out_B.DynamicAngleSwitch
	  section.data(275).logicalSrcIdx = 274;
	  section.data(275).dtTransOffset = 317;
	
	  ;% center_out_B.sin_f
	  section.data(276).logicalSrcIdx = 275;
	  section.data(276).dtTransOffset = 318;
	
	  ;% center_out_B.Inverter_f
	  section.data(277).logicalSrcIdx = 276;
	  section.data(277).dtTransOffset = 319;
	
	  ;% center_out_B.Product3_b
	  section.data(278).logicalSrcIdx = 277;
	  section.data(278).dtTransOffset = 321;
	
	  ;% center_out_B.cos_j
	  section.data(279).logicalSrcIdx = 278;
	  section.data(279).dtTransOffset = 322;
	
	  ;% center_out_B.Product2_p
	  section.data(280).logicalSrcIdx = 279;
	  section.data(280).dtTransOffset = 323;
	
	  ;% center_out_B.Subtract_l
	  section.data(281).logicalSrcIdx = 280;
	  section.data(281).dtTransOffset = 324;
	
	  ;% center_out_B.Product1_i
	  section.data(282).logicalSrcIdx = 281;
	  section.data(282).dtTransOffset = 325;
	
	  ;% center_out_B.Product_o
	  section.data(283).logicalSrcIdx = 282;
	  section.data(283).dtTransOffset = 326;
	
	  ;% center_out_B.Add_c
	  section.data(284).logicalSrcIdx = 283;
	  section.data(284).dtTransOffset = 327;
	
	  ;% center_out_B.Gain_lz
	  section.data(285).logicalSrcIdx = 284;
	  section.data(285).dtTransOffset = 328;
	
	  ;% center_out_B.Gain_d
	  section.data(286).logicalSrcIdx = 285;
	  section.data(286).dtTransOffset = 330;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% center_out_B.Compare
	  section.data(1).logicalSrcIdx = 286;
	  section.data(1).dtTransOffset = 0;
	
	  ;% center_out_B.Compare_h
	  section.data(2).logicalSrcIdx = 287;
	  section.data(2).dtTransOffset = 1;
	
	  ;% center_out_B.Compare_o
	  section.data(3).logicalSrcIdx = 288;
	  section.data(3).dtTransOffset = 2;
	
	  ;% center_out_B.Compare_b
	  section.data(4).logicalSrcIdx = 289;
	  section.data(4).dtTransOffset = 3;
	
	  ;% center_out_B.Compare_d
	  section.data(5).logicalSrcIdx = 290;
	  section.data(5).dtTransOffset = 4;
	
	  ;% center_out_B.Uk1
	  section.data(6).logicalSrcIdx = 291;
	  section.data(6).dtTransOffset = 5;
	
	  ;% center_out_B.FixPtRelationalOperator
	  section.data(7).logicalSrcIdx = 292;
	  section.data(7).dtTransOffset = 6;
	
	  ;% center_out_B.Compare_c
	  section.data(8).logicalSrcIdx = 293;
	  section.data(8).dtTransOffset = 7;
	
	  ;% center_out_B.Compare_l
	  section.data(9).logicalSrcIdx = 294;
	  section.data(9).dtTransOffset = 8;
	
	  ;% center_out_B.Compare_e
	  section.data(10).logicalSrcIdx = 295;
	  section.data(10).dtTransOffset = 9;
	
	  ;% center_out_B.Compare_m
	  section.data(11).logicalSrcIdx = 296;
	  section.data(11).dtTransOffset = 10;
	
	  ;% center_out_B.Uk1_f
	  section.data(12).logicalSrcIdx = 297;
	  section.data(12).dtTransOffset = 11;
	
	  ;% center_out_B.FixPtRelationalOperator_e
	  section.data(13).logicalSrcIdx = 298;
	  section.data(13).dtTransOffset = 12;
	
	  ;% center_out_B.Compare_m2
	  section.data(14).logicalSrcIdx = 299;
	  section.data(14).dtTransOffset = 13;
	
	  ;% center_out_B.Compare_g
	  section.data(15).logicalSrcIdx = 300;
	  section.data(15).dtTransOffset = 14;
	
	  ;% center_out_B.Uk1_e
	  section.data(16).logicalSrcIdx = 301;
	  section.data(16).dtTransOffset = 15;
	
	  ;% center_out_B.FixPtRelationalOperator_i
	  section.data(17).logicalSrcIdx = 302;
	  section.data(17).dtTransOffset = 16;
	
	  ;% center_out_B.Compare_mk
	  section.data(18).logicalSrcIdx = 303;
	  section.data(18).dtTransOffset = 17;
	
	  ;% center_out_B.Compare_p
	  section.data(19).logicalSrcIdx = 304;
	  section.data(19).dtTransOffset = 18;
	
	  ;% center_out_B.Uk1_o
	  section.data(20).logicalSrcIdx = 305;
	  section.data(20).dtTransOffset = 19;
	
	  ;% center_out_B.FixPtRelationalOperator_l
	  section.data(21).logicalSrcIdx = 306;
	  section.data(21).dtTransOffset = 20;
	
	  ;% center_out_B.Compare_ci
	  section.data(22).logicalSrcIdx = 307;
	  section.data(22).dtTransOffset = 21;
	
	  ;% center_out_B.Compare_hx
	  section.data(23).logicalSrcIdx = 308;
	  section.data(23).dtTransOffset = 22;
	
	  ;% center_out_B.Pack
	  section.data(24).logicalSrcIdx = 309;
	  section.data(24).dtTransOffset = 23;
	
	  ;% center_out_B.RateTransition
	  section.data(25).logicalSrcIdx = 310;
	  section.data(25).dtTransOffset = 135;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 57;
      section.data(57)  = dumData; %prealloc
      
	  ;% center_out_B.Memory
	  section.data(1).logicalSrcIdx = 311;
	  section.data(1).dtTransOffset = 0;
	
	  ;% center_out_B.Memory_o
	  section.data(2).logicalSrcIdx = 312;
	  section.data(2).dtTransOffset = 1;
	
	  ;% center_out_B.LogicalOperator2
	  section.data(3).logicalSrcIdx = 313;
	  section.data(3).dtTransOffset = 2;
	
	  ;% center_out_B.LogicalOperator1
	  section.data(4).logicalSrcIdx = 314;
	  section.data(4).dtTransOffset = 3;
	
	  ;% center_out_B.HiddenBuf_InsertedFor_EnabledSu
	  section.data(5).logicalSrcIdx = 315;
	  section.data(5).dtTransOffset = 4;
	
	  ;% center_out_B.RelationalOperator
	  section.data(6).logicalSrcIdx = 316;
	  section.data(6).dtTransOffset = 5;
	
	  ;% center_out_B.LogicalOperator
	  section.data(7).logicalSrcIdx = 317;
	  section.data(7).dtTransOffset = 6;
	
	  ;% center_out_B.Memory_p
	  section.data(8).logicalSrcIdx = 318;
	  section.data(8).dtTransOffset = 7;
	
	  ;% center_out_B.RelationalOperator_e
	  section.data(9).logicalSrcIdx = 319;
	  section.data(9).dtTransOffset = 8;
	
	  ;% center_out_B.RelationalOperator1
	  section.data(10).logicalSrcIdx = 320;
	  section.data(10).dtTransOffset = 9;
	
	  ;% center_out_B.RelationalOperator2
	  section.data(11).logicalSrcIdx = 321;
	  section.data(11).dtTransOffset = 10;
	
	  ;% center_out_B.RelationalOperator3
	  section.data(12).logicalSrcIdx = 322;
	  section.data(12).dtTransOffset = 11;
	
	  ;% center_out_B.LogicalOperator_j
	  section.data(13).logicalSrcIdx = 323;
	  section.data(13).dtTransOffset = 12;
	
	  ;% center_out_B.InBox
	  section.data(14).logicalSrcIdx = 324;
	  section.data(14).dtTransOffset = 13;
	
	  ;% center_out_B.LogicalOperator3
	  section.data(15).logicalSrcIdx = 325;
	  section.data(15).dtTransOffset = 14;
	
	  ;% center_out_B.Memory_pz
	  section.data(16).logicalSrcIdx = 326;
	  section.data(16).dtTransOffset = 15;
	
	  ;% center_out_B.LogicalOperator4
	  section.data(17).logicalSrcIdx = 327;
	  section.data(17).dtTransOffset = 16;
	
	  ;% center_out_B.LogicalOperator_p
	  section.data(18).logicalSrcIdx = 328;
	  section.data(18).dtTransOffset = 17;
	
	  ;% center_out_B.LogicalOperator2_n
	  section.data(19).logicalSrcIdx = 329;
	  section.data(19).dtTransOffset = 18;
	
	  ;% center_out_B.LogicalOperator1_m
	  section.data(20).logicalSrcIdx = 330;
	  section.data(20).dtTransOffset = 19;
	
	  ;% center_out_B.HiddenBuf_InsertedFor_Enabled_c
	  section.data(21).logicalSrcIdx = 331;
	  section.data(21).dtTransOffset = 20;
	
	  ;% center_out_B.RelationalOperator_i
	  section.data(22).logicalSrcIdx = 332;
	  section.data(22).dtTransOffset = 21;
	
	  ;% center_out_B.LogicalOperator_l
	  section.data(23).logicalSrcIdx = 333;
	  section.data(23).dtTransOffset = 22;
	
	  ;% center_out_B.LogicalOperator5
	  section.data(24).logicalSrcIdx = 334;
	  section.data(24).dtTransOffset = 23;
	
	  ;% center_out_B.LogicalOperator2_h
	  section.data(25).logicalSrcIdx = 335;
	  section.data(25).dtTransOffset = 24;
	
	  ;% center_out_B.LogicalOperator1_i
	  section.data(26).logicalSrcIdx = 336;
	  section.data(26).dtTransOffset = 25;
	
	  ;% center_out_B.HiddenBuf_InsertedFor_Enabled_d
	  section.data(27).logicalSrcIdx = 337;
	  section.data(27).dtTransOffset = 26;
	
	  ;% center_out_B.RelationalOperator_ec
	  section.data(28).logicalSrcIdx = 338;
	  section.data(28).dtTransOffset = 27;
	
	  ;% center_out_B.LogicalOperator_pm
	  section.data(29).logicalSrcIdx = 339;
	  section.data(29).dtTransOffset = 28;
	
	  ;% center_out_B.LogicalOperator1_a
	  section.data(30).logicalSrcIdx = 340;
	  section.data(30).dtTransOffset = 29;
	
	  ;% center_out_B.NOT
	  section.data(31).logicalSrcIdx = 341;
	  section.data(31).dtTransOffset = 30;
	
	  ;% center_out_B.Memory_d
	  section.data(32).logicalSrcIdx = 342;
	  section.data(32).dtTransOffset = 31;
	
	  ;% center_out_B.LogicalOperator2_f
	  section.data(33).logicalSrcIdx = 343;
	  section.data(33).dtTransOffset = 32;
	
	  ;% center_out_B.LogicalOperator1_b
	  section.data(34).logicalSrcIdx = 344;
	  section.data(34).dtTransOffset = 33;
	
	  ;% center_out_B.HiddenBuf_InsertedFor_Enabled_g
	  section.data(35).logicalSrcIdx = 345;
	  section.data(35).dtTransOffset = 34;
	
	  ;% center_out_B.RelationalOperator_a
	  section.data(36).logicalSrcIdx = 346;
	  section.data(36).dtTransOffset = 35;
	
	  ;% center_out_B.LogicalOperator_o
	  section.data(37).logicalSrcIdx = 347;
	  section.data(37).dtTransOffset = 36;
	
	  ;% center_out_B.DataTypeConversion2
	  section.data(38).logicalSrcIdx = 348;
	  section.data(38).dtTransOffset = 37;
	
	  ;% center_out_B.LogicalOperator1_j
	  section.data(39).logicalSrcIdx = 349;
	  section.data(39).dtTransOffset = 38;
	
	  ;% center_out_B.Memory_b
	  section.data(40).logicalSrcIdx = 350;
	  section.data(40).dtTransOffset = 39;
	
	  ;% center_out_B.LogicalOperator2_g
	  section.data(41).logicalSrcIdx = 351;
	  section.data(41).dtTransOffset = 40;
	
	  ;% center_out_B.LogicalOperator1_be
	  section.data(42).logicalSrcIdx = 352;
	  section.data(42).dtTransOffset = 41;
	
	  ;% center_out_B.HiddenBuf_InsertedFor_Enabled_e
	  section.data(43).logicalSrcIdx = 353;
	  section.data(43).dtTransOffset = 42;
	
	  ;% center_out_B.RelationalOperator_j
	  section.data(44).logicalSrcIdx = 354;
	  section.data(44).dtTransOffset = 43;
	
	  ;% center_out_B.LogicalOperator_i
	  section.data(45).logicalSrcIdx = 355;
	  section.data(45).dtTransOffset = 44;
	
	  ;% center_out_B.DataTypeConversion1
	  section.data(46).logicalSrcIdx = 356;
	  section.data(46).dtTransOffset = 45;
	
	  ;% center_out_B.Memory_be
	  section.data(47).logicalSrcIdx = 357;
	  section.data(47).dtTransOffset = 46;
	
	  ;% center_out_B.Logic
	  section.data(48).logicalSrcIdx = 358;
	  section.data(48).dtTransOffset = 47;
	
	  ;% center_out_B.LogicalOperator5_d
	  section.data(49).logicalSrcIdx = 359;
	  section.data(49).dtTransOffset = 49;
	
	  ;% center_out_B.LogicalOperator1_bt
	  section.data(50).logicalSrcIdx = 360;
	  section.data(50).dtTransOffset = 50;
	
	  ;% center_out_B.MatrixConcatenation
	  section.data(51).logicalSrcIdx = 361;
	  section.data(51).dtTransOffset = 51;
	
	  ;% center_out_B.RelationalOperator_o
	  section.data(52).logicalSrcIdx = 362;
	  section.data(52).dtTransOffset = 53;
	
	  ;% center_out_B.RelationalOperator_h
	  section.data(53).logicalSrcIdx = 363;
	  section.data(53).dtTransOffset = 54;
	
	  ;% center_out_B.Compare_i
	  section.data(54).logicalSrcIdx = 364;
	  section.data(54).dtTransOffset = 55;
	
	  ;% center_out_B.Compare_hn
	  section.data(55).logicalSrcIdx = 365;
	  section.data(55).dtTransOffset = 56;
	
	  ;% center_out_B.LogicalOperator6
	  section.data(56).logicalSrcIdx = 366;
	  section.data(56).dtTransOffset = 57;
	
	  ;% center_out_B.LogicalOperator3_b
	  section.data(57).logicalSrcIdx = 367;
	  section.data(57).dtTransOffset = 58;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_B.SampleandHold.In
	  section.data(1).logicalSrcIdx = 368;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_B.SampleandHold_e.In
	  section.data(1).logicalSrcIdx = 369;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_B.EnabledSubsystem_l.In1
	  section.data(1).logicalSrcIdx = 370;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_B.EnabledSubsystem_n.In1
	  section.data(1).logicalSrcIdx = 371;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_B.EnabledSubsystem_ir.In1
	  section.data(1).logicalSrcIdx = 372;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_B.EnabledSubsystem_i.In1
	  section.data(1).logicalSrcIdx = 373;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_B.EnabledSubsystem.In1
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
    ;% Auto data (center_out_DWork)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% center_out_DWork.DigitalFilter2_FILT_STATES
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% center_out_DWork.DigitalFilter_FILT_STATES
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 11;
	
	  ;% center_out_DWork.DigitalFilter2_FILT_STATES_h
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 22;
	
	  ;% center_out_DWork.DigitalFilter_FILT_STATES_g
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 33;
	
	  ;% center_out_DWork.x_DSTATE
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 44;
	
	  ;% center_out_DWork.x_DSTATE_m
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 45;
	
	  ;% center_out_DWork.x_DSTATE_a
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 46;
	
	  ;% center_out_DWork.x_DSTATE_p
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 47;
	
	  ;% center_out_DWork.x_DSTATE_b
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 48;
	
	  ;% center_out_DWork.x_DSTATE_a5
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 49;
	
	  ;% center_out_DWork.x_DSTATE_h
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 50;
	
	  ;% center_out_DWork.x_DSTATE_b2
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 51;
	
	  ;% center_out_DWork.BehaviorCO_DSTATE
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 52;
	
	  ;% center_out_DWork.y_DSTATE
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 53;
	
	  ;% center_out_DWork.z_DSTATE
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 54;
	
	  ;% center_out_DWork.y_DSTATE_b
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 55;
	
	  ;% center_out_DWork.z_DSTATE_c
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 56;
	
	  ;% center_out_DWork.y_DSTATE_j
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 57;
	
	  ;% center_out_DWork.z_DSTATE_p
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 58;
	
	  ;% center_out_DWork.y_DSTATE_b1
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 59;
	
	  ;% center_out_DWork.z_DSTATE_o
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 60;
	
	  ;% center_out_DWork.y_DSTATE_d
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 61;
	
	  ;% center_out_DWork.z_DSTATE_f
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 62;
	
	  ;% center_out_DWork.y_DSTATE_e
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 63;
	
	  ;% center_out_DWork.z_DSTATE_d
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 64;
	
	  ;% center_out_DWork.y_DSTATE_f
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 65;
	
	  ;% center_out_DWork.z_DSTATE_d2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 66;
	
	  ;% center_out_DWork.y_DSTATE_p
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 67;
	
	  ;% center_out_DWork.z_DSTATE_l
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 68;
	
	  ;% center_out_DWork.PCI6025EAD_RWORK
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 69;
	
	  ;% center_out_DWork.Derivative_RWORK.TimeStampA
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 133;
	
	  ;% center_out_DWork.Derivative_RWORK_d.TimeStampA
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 134;
	
	  ;% center_out_DWork.BehaviorCO_RWORK
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 135;
	
	  ;% center_out_DWork.PCI6025E_RWORK
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 140;
	
	  ;% center_out_DWork.UniformRandomNumber_RWORK.NextOutput
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 146;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.Send_PWORK
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% center_out_DWork.DigitalFilter2_CIRCBUFFIDX
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% center_out_DWork.DigitalFilter_CIRCBUFFIDX
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% center_out_DWork.DigitalFilter2_CIRCBUFFIDX_l
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% center_out_DWork.DigitalFilter_CIRCBUFFIDX_g
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% center_out_DWork.PCIQUAD04_IWORK
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% center_out_DWork.PCIQUAD041_IWORK
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% center_out_DWork.PCI6025EAD_IWORK
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% center_out_DWork.BehaviorCO_IWORK
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 68;
	
	  ;% center_out_DWork.PCI6025E_IWORK
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 653;
	
	  ;% center_out_DWork.SFunction_IWORK.AcquireOK
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 655;
	
	  ;% center_out_DWork.SFunction_IWORK_f.AcquireOK
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 656;
	
	  ;% center_out_DWork.SFunction_IWORK_b.AcquireOK
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 657;
	
	  ;% center_out_DWork.Send_IWORK
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 658;
	
	  ;% center_out_DWork.SFunction_IWORK_d.AcquireOK
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 660;
	
	  ;% center_out_DWork.SFunction_IWORK_p.AcquireOK
	  section.data(11).logicalSrcIdx = 50;
	  section.data(11).dtTransOffset = 661;
	
	  ;% center_out_DWork.SFunction_IWORK_a.AcquireOK
	  section.data(12).logicalSrcIdx = 51;
	  section.data(12).dtTransOffset = 662;
	
	  ;% center_out_DWork.UniformRandomNumber_IWORK.RandSeed
	  section.data(13).logicalSrcIdx = 52;
	  section.data(13).dtTransOffset = 663;
	
	  ;% center_out_DWork.PortA_IWORK
	  section.data(14).logicalSrcIdx = 53;
	  section.data(14).dtTransOffset = 664;
	
	  ;% center_out_DWork.PortB_IWORK
	  section.data(15).logicalSrcIdx = 54;
	  section.data(15).dtTransOffset = 666;
	
	  ;% center_out_DWork.PCI6025E_IWORK_d
	  section.data(16).logicalSrcIdx = 55;
	  section.data(16).dtTransOffset = 668;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% center_out_DWork.DelayInput1_DSTATE
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
	  ;% center_out_DWork.DelayInput1_DSTATE_o
	  section.data(2).logicalSrcIdx = 57;
	  section.data(2).dtTransOffset = 1;
	
	  ;% center_out_DWork.DelayInput1_DSTATE_g
	  section.data(3).logicalSrcIdx = 58;
	  section.data(3).dtTransOffset = 2;
	
	  ;% center_out_DWork.DelayInput1_DSTATE_m
	  section.data(4).logicalSrcIdx = 59;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% center_out_DWork.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
	  ;% center_out_DWork.Memory_PreviousInput_e
	  section.data(2).logicalSrcIdx = 61;
	  section.data(2).dtTransOffset = 1;
	
	  ;% center_out_DWork.Memory_PreviousInput_i
	  section.data(3).logicalSrcIdx = 62;
	  section.data(3).dtTransOffset = 2;
	
	  ;% center_out_DWork.Memory_PreviousInput_a
	  section.data(4).logicalSrcIdx = 63;
	  section.data(4).dtTransOffset = 3;
	
	  ;% center_out_DWork.Memory_PreviousInput_j
	  section.data(5).logicalSrcIdx = 64;
	  section.data(5).dtTransOffset = 4;
	
	  ;% center_out_DWork.Memory_PreviousInput_o
	  section.data(6).logicalSrcIdx = 65;
	  section.data(6).dtTransOffset = 5;
	
	  ;% center_out_DWork.Memory_PreviousInput_b
	  section.data(7).logicalSrcIdx = 66;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.SampleandHold.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.SampleandHold_e.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.EnabledSubsystem_l.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.EnabledSubsystem_l.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.EnabledSubsystem_n.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.EnabledSubsystem_n.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.EnabledSubsystem_ir.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.EnabledSubsystem_ir.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.EnabledSubsystem_i.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.EnabledSubsystem_i.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.EnabledSubsystem.EnabledSubsystem_MODE
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% center_out_DWork.EnabledSubsystem.EnabledSubsystem_SubsysRanBC
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


  targMap.checksum0 = 2922333750;
  targMap.checksum1 = 1640439664;
  targMap.checksum2 = 536259912;
  targMap.checksum3 = 1659165049;

