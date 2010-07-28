  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
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
    ;% Auto data (multi_gadget_P)
    ;%
      section.nData     = 154;
      section.data(154)  = dumData; %prealloc
      
	  ;% multi_gadget_P.PCI6025EDI_P1_Size
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% multi_gadget_P.PCI6025EDI_P1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% multi_gadget_P.PCI6025EDI_P2_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% multi_gadget_P.PCI6025EDI_P2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% multi_gadget_P.PCI6025EDI_P3_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% multi_gadget_P.PCI6025EDI_P3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% multi_gadget_P.PCI6025EDI_P4_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% multi_gadget_P.PCI6025EDI_P4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% multi_gadget_P.PCI6025EDI_P5_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% multi_gadget_P.PCI6025EDI_P5
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% multi_gadget_P.PCI6025EAD_P1_Size
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% multi_gadget_P.PCI6025EAD_P1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% multi_gadget_P.PCI6025EAD_P2_Size
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 19;
	
	  ;% multi_gadget_P.PCI6025EAD_P2
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 21;
	
	  ;% multi_gadget_P.PCI6025EAD_P3_Size
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 23;
	
	  ;% multi_gadget_P.PCI6025EAD_P3
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 25;
	
	  ;% multi_gadget_P.PCI6025EAD_P4_Size
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 27;
	
	  ;% multi_gadget_P.PCI6025EAD_P4
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 29;
	
	  ;% multi_gadget_P.PCI6025EAD_P5_Size
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 30;
	
	  ;% multi_gadget_P.PCI6025EAD_P5
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 32;
	
	  ;% multi_gadget_P.PCI6025EAD_P6_Size
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 33;
	
	  ;% multi_gadget_P.PCI6025EAD_P6
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 35;
	
	  ;% multi_gadget_P.NewtonCal1_Gain
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 36;
	
	  ;% multi_gadget_P.NewtonCal2_Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 37;
	
	  ;% multi_gadget_P.TargetTable_table
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 38;
	
	  ;% multi_gadget_P.BehaviorMG_P1_Size
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 118;
	
	  ;% multi_gadget_P.BehaviorMG_P1
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 120;
	
	  ;% multi_gadget_P.BehaviorMG_P2_Size
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 121;
	
	  ;% multi_gadget_P.BehaviorMG_P2
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 123;
	
	  ;% multi_gadget_P.BehaviorMG_P3_Size
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 124;
	
	  ;% multi_gadget_P.BehaviorMG_P3
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 126;
	
	  ;% multi_gadget_P.BehaviorMG_P4_Size
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 127;
	
	  ;% multi_gadget_P.BehaviorMG_P4
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 129;
	
	  ;% multi_gadget_P.BehaviorMG_P5_Size
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 130;
	
	  ;% multi_gadget_P.BehaviorMG_P5
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 132;
	
	  ;% multi_gadget_P.BehaviorMG_P6_Size
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 133;
	
	  ;% multi_gadget_P.BehaviorMG_P6
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 135;
	
	  ;% multi_gadget_P.BehaviorMG_P7_Size
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 136;
	
	  ;% multi_gadget_P.BehaviorMG_P7
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 138;
	
	  ;% multi_gadget_P.BehaviorMG_P8_Size
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 139;
	
	  ;% multi_gadget_P.BehaviorMG_P8
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 141;
	
	  ;% multi_gadget_P.BehaviorMG_P9_Size
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 142;
	
	  ;% multi_gadget_P.BehaviorMG_P9
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 144;
	
	  ;% multi_gadget_P.BehaviorMG_P10_Size
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 145;
	
	  ;% multi_gadget_P.BehaviorMG_P10
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 147;
	
	  ;% multi_gadget_P.BehaviorMG_P11_Size
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 148;
	
	  ;% multi_gadget_P.BehaviorMG_P11
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 150;
	
	  ;% multi_gadget_P.BehaviorMG_P12_Size
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 151;
	
	  ;% multi_gadget_P.BehaviorMG_P12
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 153;
	
	  ;% multi_gadget_P.BehaviorMG_P13_Size
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 154;
	
	  ;% multi_gadget_P.BehaviorMG_P13
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 156;
	
	  ;% multi_gadget_P.BehaviorMG_P14_Size
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 157;
	
	  ;% multi_gadget_P.BehaviorMG_P14
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 159;
	
	  ;% multi_gadget_P.BehaviorMG_P15_Size
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 160;
	
	  ;% multi_gadget_P.BehaviorMG_P15
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 162;
	
	  ;% multi_gadget_P.BehaviorMG_P16_Size
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 163;
	
	  ;% multi_gadget_P.BehaviorMG_P16
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 165;
	
	  ;% multi_gadget_P.BehaviorMG_P17_Size
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 166;
	
	  ;% multi_gadget_P.BehaviorMG_P17
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 168;
	
	  ;% multi_gadget_P.PCI6025EDO_P1_Size
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 169;
	
	  ;% multi_gadget_P.PCI6025EDO_P1
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 171;
	
	  ;% multi_gadget_P.PCI6025EDO_P2_Size
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 175;
	
	  ;% multi_gadget_P.PCI6025EDO_P2
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 177;
	
	  ;% multi_gadget_P.PCI6025EDO_P3_Size
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 181;
	
	  ;% multi_gadget_P.PCI6025EDO_P3
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 183;
	
	  ;% multi_gadget_P.PCI6025EDO_P4_Size
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 187;
	
	  ;% multi_gadget_P.PCI6025EDO_P4
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 189;
	
	  ;% multi_gadget_P.PCI6025EDO_P5_Size
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 190;
	
	  ;% multi_gadget_P.PCI6025EDO_P5
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 192;
	
	  ;% multi_gadget_P.PCI6025EDO_P6_Size
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 193;
	
	  ;% multi_gadget_P.PCI6025EDO_P6
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 195;
	
	  ;% multi_gadget_P.PCI6025EDO_P7_Size
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 196;
	
	  ;% multi_gadget_P.PCI6025EDO_P7
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 198;
	
	  ;% multi_gadget_P.Send_P1_Size
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 199;
	
	  ;% multi_gadget_P.Send_P1
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 201;
	
	  ;% multi_gadget_P.Send_P2_Size
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 212;
	
	  ;% multi_gadget_P.Send_P2
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 214;
	
	  ;% multi_gadget_P.Send_P3_Size
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 215;
	
	  ;% multi_gadget_P.Send_P3
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 217;
	
	  ;% multi_gadget_P.Send_P4_Size
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 218;
	
	  ;% multi_gadget_P.Send_P4
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 220;
	
	  ;% multi_gadget_P.UniformRandomNumber_Min
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 221;
	
	  ;% multi_gadget_P.UniformRandomNumber_Max
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 222;
	
	  ;% multi_gadget_P.UniformRandomNumber_Seed
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 223;
	
	  ;% multi_gadget_P.JackpotChance_Value
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 224;
	
	  ;% multi_gadget_P.RewardJackpot_Value
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 225;
	
	  ;% multi_gadget_P.RewardTime_Value
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 226;
	
	  ;% multi_gadget_P.Constant_Value
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 227;
	
	  ;% multi_gadget_P.StrobeLow_Value
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 228;
	
	  ;% multi_gadget_P.StobeHi_Value
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 229;
	
	  ;% multi_gadget_P.xPCTargetTime_P1_Size
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 230;
	
	  ;% multi_gadget_P.xPCTargetTime_P1
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 232;
	
	  ;% multi_gadget_P.xPCTargetTime_P2_Size
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 233;
	
	  ;% multi_gadget_P.xPCTargetTime_P2
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 235;
	
	  ;% multi_gadget_P.ScaleTouSec_Gain
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 236;
	
	  ;% multi_gadget_P.Constant_Value_l
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 237;
	
	  ;% multi_gadget_P.PCI6025E_P1_Size
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 238;
	
	  ;% multi_gadget_P.PCI6025E_P1
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 240;
	
	  ;% multi_gadget_P.PCI6025E_P2_Size
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 242;
	
	  ;% multi_gadget_P.PCI6025E_P2
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 244;
	
	  ;% multi_gadget_P.PCI6025E_P3_Size
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 246;
	
	  ;% multi_gadget_P.PCI6025E_P3
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 248;
	
	  ;% multi_gadget_P.PCI6025E_P4_Size
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 250;
	
	  ;% multi_gadget_P.PCI6025E_P4
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 252;
	
	  ;% multi_gadget_P.PCI6025E_P5_Size
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 253;
	
	  ;% multi_gadget_P.PCI6025E_P5
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 255;
	
	  ;% multi_gadget_P.PCI6025E_P6_Size
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 256;
	
	  ;% multi_gadget_P.PCI6025E_P6
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 258;
	
	  ;% multi_gadget_P.PCI6025E_P7_Size
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 259;
	
	  ;% multi_gadget_P.PCI6025E_P7
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 261;
	
	  ;% multi_gadget_P.Constant_Value_m
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 262;
	
	  ;% multi_gadget_P.xPCTargetTime_P1_Size_b
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 263;
	
	  ;% multi_gadget_P.xPCTargetTime_P1_k
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 265;
	
	  ;% multi_gadget_P.xPCTargetTime_P2_Size_o
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 266;
	
	  ;% multi_gadget_P.xPCTargetTime_P2_l
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 268;
	
	  ;% multi_gadget_P.Switch_Threshold
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 269;
	
	  ;% multi_gadget_P.PortA_P1_Size
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 270;
	
	  ;% multi_gadget_P.PortA_P1
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 272;
	
	  ;% multi_gadget_P.PortA_P2_Size
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 280;
	
	  ;% multi_gadget_P.PortA_P2
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 282;
	
	  ;% multi_gadget_P.PortA_P3_Size
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 283;
	
	  ;% multi_gadget_P.PortA_P3
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 285;
	
	  ;% multi_gadget_P.PortA_P4_Size
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 293;
	
	  ;% multi_gadget_P.PortA_P4
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 295;
	
	  ;% multi_gadget_P.PortA_P5_Size
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 303;
	
	  ;% multi_gadget_P.PortA_P5
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 305;
	
	  ;% multi_gadget_P.PortA_P6_Size
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 306;
	
	  ;% multi_gadget_P.PortA_P6
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 308;
	
	  ;% multi_gadget_P.PortA_P7_Size
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 309;
	
	  ;% multi_gadget_P.PortA_P7
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 311;
	
	  ;% multi_gadget_P.PortA_P8_Size
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 312;
	
	  ;% multi_gadget_P.PortA_P8
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 314;
	
	  ;% multi_gadget_P.PortA_P9_Size
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 315;
	
	  ;% multi_gadget_P.PortA_P9
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 317;
	
	  ;% multi_gadget_P.toThousandths_Gain
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 318;
	
	  ;% multi_gadget_P.Constant2_Value
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 319;
	
	  ;% multi_gadget_P.PortB_P1_Size
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 320;
	
	  ;% multi_gadget_P.PortB_P1
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 322;
	
	  ;% multi_gadget_P.PortB_P2_Size
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 330;
	
	  ;% multi_gadget_P.PortB_P2
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 332;
	
	  ;% multi_gadget_P.PortB_P3_Size
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 333;
	
	  ;% multi_gadget_P.PortB_P3
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 335;
	
	  ;% multi_gadget_P.PortB_P4_Size
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 343;
	
	  ;% multi_gadget_P.PortB_P4
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 345;
	
	  ;% multi_gadget_P.PortB_P5_Size
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 353;
	
	  ;% multi_gadget_P.PortB_P5
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 355;
	
	  ;% multi_gadget_P.PortB_P6_Size
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 356;
	
	  ;% multi_gadget_P.PortB_P6
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 358;
	
	  ;% multi_gadget_P.PortB_P7_Size
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 359;
	
	  ;% multi_gadget_P.PortB_P7
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 361;
	
	  ;% multi_gadget_P.PortB_P8_Size
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 362;
	
	  ;% multi_gadget_P.PortB_P8
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 364;
	
	  ;% multi_gadget_P.PortB_P9_Size
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 365;
	
	  ;% multi_gadget_P.PortB_P9
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 367;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% multi_gadget_P.SampleandHold._Y0
	  section.data(1).logicalSrcIdx = 154;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% multi_gadget_P.SampleandHold_m._Y0
	  section.data(1).logicalSrcIdx = 155;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
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
    ;% Auto data (multi_gadget_B)
    ;%
      section.nData     = 61;
      section.data(61)  = dumData; %prealloc
      
	  ;% multi_gadget_B.PCI6025EDI
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% multi_gadget_B.PCI6025EAD_o1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% multi_gadget_B.PCI6025EAD_o2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% multi_gadget_B.NewtonCal1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% multi_gadget_B.NewtonCal2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% multi_gadget_B.Add1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% multi_gadget_B.Add
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% multi_gadget_B.TargetTable
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% multi_gadget_B.Reshape
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 87;
	
	  ;% multi_gadget_B.BehaviorMG_o1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 167;
	
	  ;% multi_gadget_B.BehaviorMG_o2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 168;
	
	  ;% multi_gadget_B.BehaviorMG_o3
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 169;
	
	  ;% multi_gadget_B.BehaviorMG_o4
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 170;
	
	  ;% multi_gadget_B.BehaviorMG_o5
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 171;
	
	  ;% multi_gadget_B.BehaviorMG_o6
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 172;
	
	  ;% multi_gadget_B.BehaviorMG_o7
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 176;
	
	  ;% multi_gadget_B.BehaviorMG_o8
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 178;
	
	  ;% multi_gadget_B.BehaviorMG_o9
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 188;
	
	  ;% multi_gadget_B.BehaviorMG_o10
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 192;
	
	  ;% multi_gadget_B.ToBits_o1
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 196;
	
	  ;% multi_gadget_B.ToBits_o2
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 197;
	
	  ;% multi_gadget_B.ToBits_o3
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 198;
	
	  ;% multi_gadget_B.ToBits_o4
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 199;
	
	  ;% multi_gadget_B.ToBits_o5
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 200;
	
	  ;% multi_gadget_B.ToBits_o6
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 201;
	
	  ;% multi_gadget_B.ToBits_o7
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 202;
	
	  ;% multi_gadget_B.ToBits_o8
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 203;
	
	  ;% multi_gadget_B.Clock
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 204;
	
	  ;% multi_gadget_B.HiddenBuf_InsertedFor_Sampleand
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 205;
	
	  ;% multi_gadget_B.Sum
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 206;
	
	  ;% multi_gadget_B.UniformRandomNumber
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 207;
	
	  ;% multi_gadget_B.Switch
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 208;
	
	  ;% multi_gadget_B.HiddenBuf_InsertedFor_Samplea_i
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 209;
	
	  ;% multi_gadget_B.DataTypeConversion
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 210;
	
	  ;% multi_gadget_B.xPCTargetTime
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 211;
	
	  ;% multi_gadget_B.ForIterator
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 212;
	
	  ;% multi_gadget_B.Switch_d
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 213;
	
	  ;% multi_gadget_B.ToBits_o1_f
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 214;
	
	  ;% multi_gadget_B.ToBits_o2_n
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 215;
	
	  ;% multi_gadget_B.ToBits_o3_i
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 216;
	
	  ;% multi_gadget_B.ToBits_o4_o
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 217;
	
	  ;% multi_gadget_B.ToBits_o5_n
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 218;
	
	  ;% multi_gadget_B.ToBits_o6_a
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 219;
	
	  ;% multi_gadget_B.ToBits_o7_j
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 220;
	
	  ;% multi_gadget_B.ToBits_o8_f
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 221;
	
	  ;% multi_gadget_B.toThousandths
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 222;
	
	  ;% multi_gadget_B.Add2
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 224;
	
	  ;% multi_gadget_B.Add3
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 225;
	
	  ;% multi_gadget_B.SerialConverter
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 226;
	
	  ;% multi_gadget_B.ToBits1_o1
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 227;
	
	  ;% multi_gadget_B.ToBits1_o2
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 228;
	
	  ;% multi_gadget_B.ToBits1_o3
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 229;
	
	  ;% multi_gadget_B.ToBits1_o4
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 230;
	
	  ;% multi_gadget_B.ToBits1_o5
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 231;
	
	  ;% multi_gadget_B.ToBits1_o6
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 232;
	
	  ;% multi_gadget_B.ToBits1_o7
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 233;
	
	  ;% multi_gadget_B.ToBits1_o8
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 234;
	
	  ;% multi_gadget_B.xPCTargetTime_c
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 235;
	
	  ;% multi_gadget_B.Subtract
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 236;
	
	  ;% multi_gadget_B.ScaleTouSec
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 237;
	
	  ;% multi_gadget_B.Switch_j
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 238;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% multi_gadget_B.Pack
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% multi_gadget_B.RateTransition
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 112;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% multi_gadget_B.RelationalOperator
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
	  ;% multi_gadget_B.RelationalOperator_c
	  section.data(2).logicalSrcIdx = 64;
	  section.data(2).dtTransOffset = 1;
	
	  ;% multi_gadget_B.Compare
	  section.data(3).logicalSrcIdx = 65;
	  section.data(3).dtTransOffset = 2;
	
	  ;% multi_gadget_B.Compare_c
	  section.data(4).logicalSrcIdx = 66;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% multi_gadget_B.SampleandHold.In
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% multi_gadget_B.SampleandHold_m.In
	  section.data(1).logicalSrcIdx = 68;
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
    nTotSects     = 5;
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
    ;% Auto data (multi_gadget_DWork)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% multi_gadget_DWork.BehaviorMG_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% multi_gadget_DWork.PCI6025EAD_RWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% multi_gadget_DWork.BehaviorMG_RWORK
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 65;
	
	  ;% multi_gadget_DWork.UniformRandomNumber_RWORK.NextOutput
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 102;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% multi_gadget_DWork.BehaviorMG_PWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% multi_gadget_DWork.Send_PWORK
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% multi_gadget_DWork.PCI6025EDI_IWORK
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% multi_gadget_DWork.PCI6025EAD_IWORK
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 3;
	
	  ;% multi_gadget_DWork.BehaviorMG_IWORK
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 69;
	
	  ;% multi_gadget_DWork.PCI6025EDO_IWORK
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 204;
	
	  ;% multi_gadget_DWork.SFunction_IWORK.AcquireOK
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 207;
	
	  ;% multi_gadget_DWork.SFunction_IWORK_k.AcquireOK
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 208;
	
	  ;% multi_gadget_DWork.SFunction_IWORK_b.AcquireOK
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 209;
	
	  ;% multi_gadget_DWork.Send_IWORK
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 210;
	
	  ;% multi_gadget_DWork.SFunction_IWORK_b4.AcquireOK
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 212;
	
	  ;% multi_gadget_DWork.SFunction_IWORK_m.AcquireOK
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 213;
	
	  ;% multi_gadget_DWork.UniformRandomNumber_IWORK.RandSeed
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 214;
	
	  ;% multi_gadget_DWork.PortA_IWORK
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 215;
	
	  ;% multi_gadget_DWork.PortB_IWORK
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 217;
	
	  ;% multi_gadget_DWork.PCI6025E_IWORK
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 219;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% multi_gadget_DWork.SampleandHold.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% multi_gadget_DWork.SampleandHold_m.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
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


  targMap.checksum0 = 1987952882;
  targMap.checksum1 = 3774861458;
  targMap.checksum2 = 2429878315;
  targMap.checksum3 = 4051533;

