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
    ;% Auto data (wrist_flexion_P)
    ;%
      section.nData     = 170;
      section.data(170)  = dumData; %prealloc
      
	  ;% wrist_flexion_P.ResetIntegrator_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% wrist_flexion_P.Integrator_IC
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% wrist_flexion_P.Integrator_UpperSat
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% wrist_flexion_P.Integrator_LowerSat
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% wrist_flexion_P.EnableIntegrator_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% wrist_flexion_P.LowPassFilterY_A
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% wrist_flexion_P.LowPassFilterY_B
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 20;
	
	  ;% wrist_flexion_P.LowPassFilterY_C
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 21;
	
	  ;% wrist_flexion_P.LowPassFilterY_X0
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 22;
	
	  ;% wrist_flexion_P.EnablePosFilter_Value
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 23;
	
	  ;% wrist_flexion_P.PCI6025E_P1_Size
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 24;
	
	  ;% wrist_flexion_P.PCI6025E_P1
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 26;
	
	  ;% wrist_flexion_P.PCI6025E_P2_Size
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 28;
	
	  ;% wrist_flexion_P.PCI6025E_P2
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 30;
	
	  ;% wrist_flexion_P.PCI6025E_P3_Size
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 32;
	
	  ;% wrist_flexion_P.PCI6025E_P3
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 34;
	
	  ;% wrist_flexion_P.PCI6025E_P4_Size
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 36;
	
	  ;% wrist_flexion_P.PCI6025E_P4
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 38;
	
	  ;% wrist_flexion_P.PCI6025E_P5_Size
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 39;
	
	  ;% wrist_flexion_P.PCI6025E_P5
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 41;
	
	  ;% wrist_flexion_P.PCI6025E_P6_Size
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 42;
	
	  ;% wrist_flexion_P.PCI6025E_P6
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 44;
	
	  ;% wrist_flexion_P.Receive_P1_Size
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 45;
	
	  ;% wrist_flexion_P.Receive_P1
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 47;
	
	  ;% wrist_flexion_P.Receive_P2_Size
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 54;
	
	  ;% wrist_flexion_P.Receive_P2
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 56;
	
	  ;% wrist_flexion_P.Receive_P3_Size
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 57;
	
	  ;% wrist_flexion_P.Receive_P3
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 59;
	
	  ;% wrist_flexion_P.Receive_P4_Size
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 60;
	
	  ;% wrist_flexion_P.Receive_P4
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 62;
	
	  ;% wrist_flexion_P.Constant1_Value
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 63;
	
	  ;% wrist_flexion_P.OffsetY_Value
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 64;
	
	  ;% wrist_flexion_P.GainY_Gain
	  section.data(33).logicalSrcIdx = 33;
	  section.data(33).dtTransOffset = 65;
	
	  ;% wrist_flexion_P.LowPassFilterX_A
	  section.data(34).logicalSrcIdx = 34;
	  section.data(34).dtTransOffset = 66;
	
	  ;% wrist_flexion_P.LowPassFilterX_B
	  section.data(35).logicalSrcIdx = 35;
	  section.data(35).dtTransOffset = 81;
	
	  ;% wrist_flexion_P.LowPassFilterX_C
	  section.data(36).logicalSrcIdx = 36;
	  section.data(36).dtTransOffset = 82;
	
	  ;% wrist_flexion_P.LowPassFilterX_X0
	  section.data(37).logicalSrcIdx = 38;
	  section.data(37).dtTransOffset = 83;
	
	  ;% wrist_flexion_P.OffsetX_Value
	  section.data(38).logicalSrcIdx = 39;
	  section.data(38).dtTransOffset = 84;
	
	  ;% wrist_flexion_P.GainX_Gain
	  section.data(39).logicalSrcIdx = 40;
	  section.data(39).dtTransOffset = 85;
	
	  ;% wrist_flexion_P.Memory_X0
	  section.data(40).logicalSrcIdx = 41;
	  section.data(40).dtTransOffset = 86;
	
	  ;% wrist_flexion_P.WFTargetTable_table
	  section.data(41).logicalSrcIdx = 42;
	  section.data(41).dtTransOffset = 87;
	
	  ;% wrist_flexion_P.BehaviorWF_P1_Size
	  section.data(42).logicalSrcIdx = 43;
	  section.data(42).dtTransOffset = 183;
	
	  ;% wrist_flexion_P.BehaviorWF_P1
	  section.data(43).logicalSrcIdx = 44;
	  section.data(43).dtTransOffset = 185;
	
	  ;% wrist_flexion_P.BehaviorWF_P2_Size
	  section.data(44).logicalSrcIdx = 45;
	  section.data(44).dtTransOffset = 186;
	
	  ;% wrist_flexion_P.BehaviorWF_P2
	  section.data(45).logicalSrcIdx = 46;
	  section.data(45).dtTransOffset = 188;
	
	  ;% wrist_flexion_P.BehaviorWF_P3_Size
	  section.data(46).logicalSrcIdx = 47;
	  section.data(46).dtTransOffset = 189;
	
	  ;% wrist_flexion_P.BehaviorWF_P3
	  section.data(47).logicalSrcIdx = 48;
	  section.data(47).dtTransOffset = 191;
	
	  ;% wrist_flexion_P.BehaviorWF_P4_Size
	  section.data(48).logicalSrcIdx = 49;
	  section.data(48).dtTransOffset = 192;
	
	  ;% wrist_flexion_P.BehaviorWF_P4
	  section.data(49).logicalSrcIdx = 50;
	  section.data(49).dtTransOffset = 194;
	
	  ;% wrist_flexion_P.BehaviorWF_P5_Size
	  section.data(50).logicalSrcIdx = 51;
	  section.data(50).dtTransOffset = 195;
	
	  ;% wrist_flexion_P.BehaviorWF_P5
	  section.data(51).logicalSrcIdx = 52;
	  section.data(51).dtTransOffset = 197;
	
	  ;% wrist_flexion_P.BehaviorWF_P6_Size
	  section.data(52).logicalSrcIdx = 53;
	  section.data(52).dtTransOffset = 198;
	
	  ;% wrist_flexion_P.BehaviorWF_P6
	  section.data(53).logicalSrcIdx = 54;
	  section.data(53).dtTransOffset = 200;
	
	  ;% wrist_flexion_P.BehaviorWF_P7_Size
	  section.data(54).logicalSrcIdx = 55;
	  section.data(54).dtTransOffset = 201;
	
	  ;% wrist_flexion_P.BehaviorWF_P7
	  section.data(55).logicalSrcIdx = 56;
	  section.data(55).dtTransOffset = 203;
	
	  ;% wrist_flexion_P.BehaviorWF_P8_Size
	  section.data(56).logicalSrcIdx = 57;
	  section.data(56).dtTransOffset = 204;
	
	  ;% wrist_flexion_P.BehaviorWF_P8
	  section.data(57).logicalSrcIdx = 58;
	  section.data(57).dtTransOffset = 206;
	
	  ;% wrist_flexion_P.BehaviorWF_P9_Size
	  section.data(58).logicalSrcIdx = 59;
	  section.data(58).dtTransOffset = 207;
	
	  ;% wrist_flexion_P.BehaviorWF_P9
	  section.data(59).logicalSrcIdx = 60;
	  section.data(59).dtTransOffset = 209;
	
	  ;% wrist_flexion_P.BehaviorWF_P10_Size
	  section.data(60).logicalSrcIdx = 61;
	  section.data(60).dtTransOffset = 210;
	
	  ;% wrist_flexion_P.BehaviorWF_P10
	  section.data(61).logicalSrcIdx = 62;
	  section.data(61).dtTransOffset = 212;
	
	  ;% wrist_flexion_P.BehaviorWF_P11_Size
	  section.data(62).logicalSrcIdx = 63;
	  section.data(62).dtTransOffset = 213;
	
	  ;% wrist_flexion_P.BehaviorWF_P11
	  section.data(63).logicalSrcIdx = 64;
	  section.data(63).dtTransOffset = 215;
	
	  ;% wrist_flexion_P.BehaviorWF_P12_Size
	  section.data(64).logicalSrcIdx = 65;
	  section.data(64).dtTransOffset = 216;
	
	  ;% wrist_flexion_P.BehaviorWF_P12
	  section.data(65).logicalSrcIdx = 66;
	  section.data(65).dtTransOffset = 218;
	
	  ;% wrist_flexion_P.BehaviorWF_P13_Size
	  section.data(66).logicalSrcIdx = 67;
	  section.data(66).dtTransOffset = 219;
	
	  ;% wrist_flexion_P.BehaviorWF_P13
	  section.data(67).logicalSrcIdx = 68;
	  section.data(67).dtTransOffset = 221;
	
	  ;% wrist_flexion_P.BehaviorWF_P14_Size
	  section.data(68).logicalSrcIdx = 69;
	  section.data(68).dtTransOffset = 222;
	
	  ;% wrist_flexion_P.BehaviorWF_P14
	  section.data(69).logicalSrcIdx = 70;
	  section.data(69).dtTransOffset = 224;
	
	  ;% wrist_flexion_P.BehaviorWF_P15_Size
	  section.data(70).logicalSrcIdx = 71;
	  section.data(70).dtTransOffset = 225;
	
	  ;% wrist_flexion_P.BehaviorWF_P15
	  section.data(71).logicalSrcIdx = 72;
	  section.data(71).dtTransOffset = 227;
	
	  ;% wrist_flexion_P.BehaviorWF_P16_Size
	  section.data(72).logicalSrcIdx = 73;
	  section.data(72).dtTransOffset = 228;
	
	  ;% wrist_flexion_P.BehaviorWF_P16
	  section.data(73).logicalSrcIdx = 74;
	  section.data(73).dtTransOffset = 230;
	
	  ;% wrist_flexion_P.BehaviorWF_P17_Size
	  section.data(74).logicalSrcIdx = 75;
	  section.data(74).dtTransOffset = 231;
	
	  ;% wrist_flexion_P.BehaviorWF_P17
	  section.data(75).logicalSrcIdx = 76;
	  section.data(75).dtTransOffset = 233;
	
	  ;% wrist_flexion_P.BehaviorWF_P18_Size
	  section.data(76).logicalSrcIdx = 77;
	  section.data(76).dtTransOffset = 234;
	
	  ;% wrist_flexion_P.BehaviorWF_P18
	  section.data(77).logicalSrcIdx = 78;
	  section.data(77).dtTransOffset = 236;
	
	  ;% wrist_flexion_P.BehaviorWF_P19_Size
	  section.data(78).logicalSrcIdx = 79;
	  section.data(78).dtTransOffset = 237;
	
	  ;% wrist_flexion_P.BehaviorWF_P19
	  section.data(79).logicalSrcIdx = 80;
	  section.data(79).dtTransOffset = 239;
	
	  ;% wrist_flexion_P.BehaviorWF_P20_Size
	  section.data(80).logicalSrcIdx = 81;
	  section.data(80).dtTransOffset = 240;
	
	  ;% wrist_flexion_P.BehaviorWF_P20
	  section.data(81).logicalSrcIdx = 82;
	  section.data(81).dtTransOffset = 242;
	
	  ;% wrist_flexion_P.BehaviorWF_P21_Size
	  section.data(82).logicalSrcIdx = 83;
	  section.data(82).dtTransOffset = 243;
	
	  ;% wrist_flexion_P.BehaviorWF_P21
	  section.data(83).logicalSrcIdx = 84;
	  section.data(83).dtTransOffset = 245;
	
	  ;% wrist_flexion_P.Send_P1_Size
	  section.data(84).logicalSrcIdx = 85;
	  section.data(84).dtTransOffset = 246;
	
	  ;% wrist_flexion_P.Send_P1
	  section.data(85).logicalSrcIdx = 86;
	  section.data(85).dtTransOffset = 248;
	
	  ;% wrist_flexion_P.Send_P2_Size
	  section.data(86).logicalSrcIdx = 87;
	  section.data(86).dtTransOffset = 259;
	
	  ;% wrist_flexion_P.Send_P2
	  section.data(87).logicalSrcIdx = 88;
	  section.data(87).dtTransOffset = 261;
	
	  ;% wrist_flexion_P.Send_P3_Size
	  section.data(88).logicalSrcIdx = 89;
	  section.data(88).dtTransOffset = 262;
	
	  ;% wrist_flexion_P.Send_P3
	  section.data(89).logicalSrcIdx = 90;
	  section.data(89).dtTransOffset = 264;
	
	  ;% wrist_flexion_P.Send_P4_Size
	  section.data(90).logicalSrcIdx = 91;
	  section.data(90).dtTransOffset = 265;
	
	  ;% wrist_flexion_P.Send_P4
	  section.data(91).logicalSrcIdx = 92;
	  section.data(91).dtTransOffset = 267;
	
	  ;% wrist_flexion_P.UniformRandomNumber_Min
	  section.data(92).logicalSrcIdx = 93;
	  section.data(92).dtTransOffset = 268;
	
	  ;% wrist_flexion_P.UniformRandomNumber_Max
	  section.data(93).logicalSrcIdx = 94;
	  section.data(93).dtTransOffset = 269;
	
	  ;% wrist_flexion_P.UniformRandomNumber_Seed
	  section.data(94).logicalSrcIdx = 95;
	  section.data(94).dtTransOffset = 270;
	
	  ;% wrist_flexion_P.JackpotChance_Value
	  section.data(95).logicalSrcIdx = 96;
	  section.data(95).dtTransOffset = 271;
	
	  ;% wrist_flexion_P.Rad2Deg_Gain
	  section.data(96).logicalSrcIdx = 97;
	  section.data(96).dtTransOffset = 272;
	
	  ;% wrist_flexion_P.NeuralControlPct_Value
	  section.data(97).logicalSrcIdx = 98;
	  section.data(97).dtTransOffset = 273;
	
	  ;% wrist_flexion_P.Saturation_UpperSat
	  section.data(98).logicalSrcIdx = 99;
	  section.data(98).dtTransOffset = 274;
	
	  ;% wrist_flexion_P.Saturation_LowerSat
	  section.data(99).logicalSrcIdx = 100;
	  section.data(99).dtTransOffset = 275;
	
	  ;% wrist_flexion_P.PctToFrac_Gain
	  section.data(100).logicalSrcIdx = 101;
	  section.data(100).dtTransOffset = 276;
	
	  ;% wrist_flexion_P.Constant_Value
	  section.data(101).logicalSrcIdx = 102;
	  section.data(101).dtTransOffset = 277;
	
	  ;% wrist_flexion_P.RewardJackpot_Value
	  section.data(102).logicalSrcIdx = 103;
	  section.data(102).dtTransOffset = 278;
	
	  ;% wrist_flexion_P.RewardTime_Value
	  section.data(103).logicalSrcIdx = 104;
	  section.data(103).dtTransOffset = 279;
	
	  ;% wrist_flexion_P.Constant_Value_m
	  section.data(104).logicalSrcIdx = 105;
	  section.data(104).dtTransOffset = 280;
	
	  ;% wrist_flexion_P.StrobeLow_Value
	  section.data(105).logicalSrcIdx = 106;
	  section.data(105).dtTransOffset = 281;
	
	  ;% wrist_flexion_P.StobeHi_Value
	  section.data(106).logicalSrcIdx = 107;
	  section.data(106).dtTransOffset = 282;
	
	  ;% wrist_flexion_P.xPCTargetTime_P1_Size
	  section.data(107).logicalSrcIdx = 108;
	  section.data(107).dtTransOffset = 283;
	
	  ;% wrist_flexion_P.xPCTargetTime_P1
	  section.data(108).logicalSrcIdx = 109;
	  section.data(108).dtTransOffset = 285;
	
	  ;% wrist_flexion_P.xPCTargetTime_P2_Size
	  section.data(109).logicalSrcIdx = 110;
	  section.data(109).dtTransOffset = 286;
	
	  ;% wrist_flexion_P.xPCTargetTime_P2
	  section.data(110).logicalSrcIdx = 111;
	  section.data(110).dtTransOffset = 288;
	
	  ;% wrist_flexion_P.ScaleTouSec_Gain
	  section.data(111).logicalSrcIdx = 112;
	  section.data(111).dtTransOffset = 289;
	
	  ;% wrist_flexion_P.Constant_Value_h
	  section.data(112).logicalSrcIdx = 113;
	  section.data(112).dtTransOffset = 290;
	
	  ;% wrist_flexion_P.PCI6025E_P1_Size_f
	  section.data(113).logicalSrcIdx = 114;
	  section.data(113).dtTransOffset = 291;
	
	  ;% wrist_flexion_P.PCI6025E_P1_m
	  section.data(114).logicalSrcIdx = 115;
	  section.data(114).dtTransOffset = 293;
	
	  ;% wrist_flexion_P.PCI6025E_P2_Size_o
	  section.data(115).logicalSrcIdx = 116;
	  section.data(115).dtTransOffset = 295;
	
	  ;% wrist_flexion_P.PCI6025E_P2_l
	  section.data(116).logicalSrcIdx = 117;
	  section.data(116).dtTransOffset = 297;
	
	  ;% wrist_flexion_P.PCI6025E_P3_Size_g
	  section.data(117).logicalSrcIdx = 118;
	  section.data(117).dtTransOffset = 299;
	
	  ;% wrist_flexion_P.PCI6025E_P3_j
	  section.data(118).logicalSrcIdx = 119;
	  section.data(118).dtTransOffset = 301;
	
	  ;% wrist_flexion_P.PCI6025E_P4_Size_a
	  section.data(119).logicalSrcIdx = 120;
	  section.data(119).dtTransOffset = 303;
	
	  ;% wrist_flexion_P.PCI6025E_P4_b
	  section.data(120).logicalSrcIdx = 121;
	  section.data(120).dtTransOffset = 305;
	
	  ;% wrist_flexion_P.PCI6025E_P5_Size_g
	  section.data(121).logicalSrcIdx = 122;
	  section.data(121).dtTransOffset = 306;
	
	  ;% wrist_flexion_P.PCI6025E_P5_d
	  section.data(122).logicalSrcIdx = 123;
	  section.data(122).dtTransOffset = 308;
	
	  ;% wrist_flexion_P.PCI6025E_P6_Size_d
	  section.data(123).logicalSrcIdx = 124;
	  section.data(123).dtTransOffset = 309;
	
	  ;% wrist_flexion_P.PCI6025E_P6_o
	  section.data(124).logicalSrcIdx = 125;
	  section.data(124).dtTransOffset = 311;
	
	  ;% wrist_flexion_P.PCI6025E_P7_Size
	  section.data(125).logicalSrcIdx = 126;
	  section.data(125).dtTransOffset = 312;
	
	  ;% wrist_flexion_P.PCI6025E_P7
	  section.data(126).logicalSrcIdx = 127;
	  section.data(126).dtTransOffset = 314;
	
	  ;% wrist_flexion_P.Constant_Value_o
	  section.data(127).logicalSrcIdx = 128;
	  section.data(127).dtTransOffset = 315;
	
	  ;% wrist_flexion_P.Switch_Threshold
	  section.data(128).logicalSrcIdx = 129;
	  section.data(128).dtTransOffset = 316;
	
	  ;% wrist_flexion_P.PortA_P1_Size
	  section.data(129).logicalSrcIdx = 130;
	  section.data(129).dtTransOffset = 317;
	
	  ;% wrist_flexion_P.PortA_P1
	  section.data(130).logicalSrcIdx = 131;
	  section.data(130).dtTransOffset = 319;
	
	  ;% wrist_flexion_P.PortA_P2_Size
	  section.data(131).logicalSrcIdx = 132;
	  section.data(131).dtTransOffset = 327;
	
	  ;% wrist_flexion_P.PortA_P2
	  section.data(132).logicalSrcIdx = 133;
	  section.data(132).dtTransOffset = 329;
	
	  ;% wrist_flexion_P.PortA_P3_Size
	  section.data(133).logicalSrcIdx = 134;
	  section.data(133).dtTransOffset = 330;
	
	  ;% wrist_flexion_P.PortA_P3
	  section.data(134).logicalSrcIdx = 135;
	  section.data(134).dtTransOffset = 332;
	
	  ;% wrist_flexion_P.PortA_P4_Size
	  section.data(135).logicalSrcIdx = 136;
	  section.data(135).dtTransOffset = 340;
	
	  ;% wrist_flexion_P.PortA_P4
	  section.data(136).logicalSrcIdx = 137;
	  section.data(136).dtTransOffset = 342;
	
	  ;% wrist_flexion_P.PortA_P5_Size
	  section.data(137).logicalSrcIdx = 138;
	  section.data(137).dtTransOffset = 350;
	
	  ;% wrist_flexion_P.PortA_P5
	  section.data(138).logicalSrcIdx = 139;
	  section.data(138).dtTransOffset = 352;
	
	  ;% wrist_flexion_P.PortA_P6_Size
	  section.data(139).logicalSrcIdx = 140;
	  section.data(139).dtTransOffset = 353;
	
	  ;% wrist_flexion_P.PortA_P6
	  section.data(140).logicalSrcIdx = 141;
	  section.data(140).dtTransOffset = 355;
	
	  ;% wrist_flexion_P.PortA_P7_Size
	  section.data(141).logicalSrcIdx = 142;
	  section.data(141).dtTransOffset = 356;
	
	  ;% wrist_flexion_P.PortA_P7
	  section.data(142).logicalSrcIdx = 143;
	  section.data(142).dtTransOffset = 358;
	
	  ;% wrist_flexion_P.PortA_P8_Size
	  section.data(143).logicalSrcIdx = 144;
	  section.data(143).dtTransOffset = 359;
	
	  ;% wrist_flexion_P.PortA_P8
	  section.data(144).logicalSrcIdx = 145;
	  section.data(144).dtTransOffset = 361;
	
	  ;% wrist_flexion_P.PortA_P9_Size
	  section.data(145).logicalSrcIdx = 146;
	  section.data(145).dtTransOffset = 362;
	
	  ;% wrist_flexion_P.PortA_P9
	  section.data(146).logicalSrcIdx = 147;
	  section.data(146).dtTransOffset = 364;
	
	  ;% wrist_flexion_P.toThousandths_Gain
	  section.data(147).logicalSrcIdx = 148;
	  section.data(147).dtTransOffset = 365;
	
	  ;% wrist_flexion_P.Constant2_Value
	  section.data(148).logicalSrcIdx = 149;
	  section.data(148).dtTransOffset = 366;
	
	  ;% wrist_flexion_P.PortB_P1_Size
	  section.data(149).logicalSrcIdx = 150;
	  section.data(149).dtTransOffset = 367;
	
	  ;% wrist_flexion_P.PortB_P1
	  section.data(150).logicalSrcIdx = 151;
	  section.data(150).dtTransOffset = 369;
	
	  ;% wrist_flexion_P.PortB_P2_Size
	  section.data(151).logicalSrcIdx = 152;
	  section.data(151).dtTransOffset = 377;
	
	  ;% wrist_flexion_P.PortB_P2
	  section.data(152).logicalSrcIdx = 153;
	  section.data(152).dtTransOffset = 379;
	
	  ;% wrist_flexion_P.PortB_P3_Size
	  section.data(153).logicalSrcIdx = 154;
	  section.data(153).dtTransOffset = 380;
	
	  ;% wrist_flexion_P.PortB_P3
	  section.data(154).logicalSrcIdx = 155;
	  section.data(154).dtTransOffset = 382;
	
	  ;% wrist_flexion_P.PortB_P4_Size
	  section.data(155).logicalSrcIdx = 156;
	  section.data(155).dtTransOffset = 390;
	
	  ;% wrist_flexion_P.PortB_P4
	  section.data(156).logicalSrcIdx = 157;
	  section.data(156).dtTransOffset = 392;
	
	  ;% wrist_flexion_P.PortB_P5_Size
	  section.data(157).logicalSrcIdx = 158;
	  section.data(157).dtTransOffset = 400;
	
	  ;% wrist_flexion_P.PortB_P5
	  section.data(158).logicalSrcIdx = 159;
	  section.data(158).dtTransOffset = 402;
	
	  ;% wrist_flexion_P.PortB_P6_Size
	  section.data(159).logicalSrcIdx = 160;
	  section.data(159).dtTransOffset = 403;
	
	  ;% wrist_flexion_P.PortB_P6
	  section.data(160).logicalSrcIdx = 161;
	  section.data(160).dtTransOffset = 405;
	
	  ;% wrist_flexion_P.PortB_P7_Size
	  section.data(161).logicalSrcIdx = 162;
	  section.data(161).dtTransOffset = 406;
	
	  ;% wrist_flexion_P.PortB_P7
	  section.data(162).logicalSrcIdx = 163;
	  section.data(162).dtTransOffset = 408;
	
	  ;% wrist_flexion_P.PortB_P8_Size
	  section.data(163).logicalSrcIdx = 164;
	  section.data(163).dtTransOffset = 409;
	
	  ;% wrist_flexion_P.PortB_P8
	  section.data(164).logicalSrcIdx = 165;
	  section.data(164).dtTransOffset = 411;
	
	  ;% wrist_flexion_P.PortB_P9_Size
	  section.data(165).logicalSrcIdx = 166;
	  section.data(165).dtTransOffset = 412;
	
	  ;% wrist_flexion_P.PortB_P9
	  section.data(166).logicalSrcIdx = 167;
	  section.data(166).dtTransOffset = 414;
	
	  ;% wrist_flexion_P.xPCTargetTime_P1_Size_d
	  section.data(167).logicalSrcIdx = 168;
	  section.data(167).dtTransOffset = 415;
	
	  ;% wrist_flexion_P.xPCTargetTime_P1_a
	  section.data(168).logicalSrcIdx = 169;
	  section.data(168).dtTransOffset = 417;
	
	  ;% wrist_flexion_P.xPCTargetTime_P2_Size_j
	  section.data(169).logicalSrcIdx = 170;
	  section.data(169).dtTransOffset = 418;
	
	  ;% wrist_flexion_P.xPCTargetTime_P2_b
	  section.data(170).logicalSrcIdx = 171;
	  section.data(170).dtTransOffset = 420;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% wrist_flexion_P.SampleandHold._Y0
	  section.data(1).logicalSrcIdx = 172;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% wrist_flexion_P.SampleandHold_k._Y0
	  section.data(1).logicalSrcIdx = 173;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (wrist_flexion_B)
    ;%
      section.nData     = 74;
      section.data(74)  = dumData; %prealloc
      
	  ;% wrist_flexion_B.Integrator
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% wrist_flexion_B.LowPassFilterY
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% wrist_flexion_B.RawX
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% wrist_flexion_B.RawY
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% wrist_flexion_B.Receive_o2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% wrist_flexion_B.Override
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% wrist_flexion_B.Sum
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% wrist_flexion_B.Product
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% wrist_flexion_B.Product1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 10;
	
	  ;% wrist_flexion_B.Sum2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 12;
	
	  ;% wrist_flexion_B.Sum2_c
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 13;
	
	  ;% wrist_flexion_B.GainY
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 14;
	
	  ;% wrist_flexion_B.Switch
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 15;
	
	  ;% wrist_flexion_B.LowPassFilterX
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 16;
	
	  ;% wrist_flexion_B.Sum1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 17;
	
	  ;% wrist_flexion_B.Sum1_n
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 18;
	
	  ;% wrist_flexion_B.GainX
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 19;
	
	  ;% wrist_flexion_B.Switch1
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 20;
	
	  ;% wrist_flexion_B.TrigonometricFunction1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% wrist_flexion_B.Rotation
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% wrist_flexion_B.Sum_a
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% wrist_flexion_B.TrigonometricFunction2
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% wrist_flexion_B.sqrtu1u1u2u2
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% wrist_flexion_B.Product1_a
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% wrist_flexion_B.TrigonometricFunction
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 27;
	
	  ;% wrist_flexion_B.Product_p
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 28;
	
	  ;% wrist_flexion_B.Switch2
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 29;
	
	  ;% wrist_flexion_B.WFTargetTable
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 31;
	
	  ;% wrist_flexion_B.Reshape
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 127;
	
	  ;% wrist_flexion_B.BehaviorWF_o1
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 223;
	
	  ;% wrist_flexion_B.BehaviorWF_o2
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 224;
	
	  ;% wrist_flexion_B.BehaviorWF_o3
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 225;
	
	  ;% wrist_flexion_B.BehaviorWF_o4
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 229;
	
	  ;% wrist_flexion_B.BehaviorWF_o5
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 231;
	
	  ;% wrist_flexion_B.BehaviorWF_o6
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 241;
	
	  ;% wrist_flexion_B.BehaviorWF_o7
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 249;
	
	  ;% wrist_flexion_B.BehaviorWF_o8
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 253;
	
	  ;% wrist_flexion_B.Clock
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 254;
	
	  ;% wrist_flexion_B.HiddenBuf_InsertedFor_Sampleand
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 255;
	
	  ;% wrist_flexion_B.Sum_m
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 256;
	
	  ;% wrist_flexion_B.UniformRandomNumber
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 257;
	
	  ;% wrist_flexion_B.Switch_i
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 258;
	
	  ;% wrist_flexion_B.HiddenBuf_InsertedFor_Samplea_b
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 259;
	
	  ;% wrist_flexion_B.DataTypeConversion
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 260;
	
	  ;% wrist_flexion_B.Rad2Deg
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 261;
	
	  ;% wrist_flexion_B.ForIterator
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 262;
	
	  ;% wrist_flexion_B.Switch_e
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 263;
	
	  ;% wrist_flexion_B.ToBits_o1
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 264;
	
	  ;% wrist_flexion_B.ToBits_o2
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 265;
	
	  ;% wrist_flexion_B.ToBits_o3
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 266;
	
	  ;% wrist_flexion_B.ToBits_o4
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 267;
	
	  ;% wrist_flexion_B.ToBits_o5
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 268;
	
	  ;% wrist_flexion_B.ToBits_o6
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 269;
	
	  ;% wrist_flexion_B.ToBits_o7
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 270;
	
	  ;% wrist_flexion_B.ToBits_o8
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 271;
	
	  ;% wrist_flexion_B.toThousandths
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 272;
	
	  ;% wrist_flexion_B.Add2
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 274;
	
	  ;% wrist_flexion_B.Add3
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 275;
	
	  ;% wrist_flexion_B.SerialConverter
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 276;
	
	  ;% wrist_flexion_B.ToBits1_o1
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 277;
	
	  ;% wrist_flexion_B.ToBits1_o2
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 278;
	
	  ;% wrist_flexion_B.ToBits1_o3
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 279;
	
	  ;% wrist_flexion_B.ToBits1_o4
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 280;
	
	  ;% wrist_flexion_B.ToBits1_o5
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 281;
	
	  ;% wrist_flexion_B.ToBits1_o6
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 282;
	
	  ;% wrist_flexion_B.ToBits1_o7
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 283;
	
	  ;% wrist_flexion_B.ToBits1_o8
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 284;
	
	  ;% wrist_flexion_B.xPCTargetTime
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 285;
	
	  ;% wrist_flexion_B.xPCTargetTime_a
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 286;
	
	  ;% wrist_flexion_B.Subtract
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 287;
	
	  ;% wrist_flexion_B.ScaleTouSec
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 288;
	
	  ;% wrist_flexion_B.Switch_o
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 289;
	
	  ;% wrist_flexion_B.Saturation
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 290;
	
	  ;% wrist_flexion_B.PctToFrac
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 291;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% wrist_flexion_B.Unpack
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% wrist_flexion_B.Receive_o1
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
	  ;% wrist_flexion_B.Pack
	  section.data(2).logicalSrcIdx = 76;
	  section.data(2).dtTransOffset = 16;
	
	  ;% wrist_flexion_B.RateTransition
	  section.data(3).logicalSrcIdx = 77;
	  section.data(3).dtTransOffset = 128;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% wrist_flexion_B.RelationalOperator
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
	  ;% wrist_flexion_B.RelationalOperator_f
	  section.data(2).logicalSrcIdx = 79;
	  section.data(2).dtTransOffset = 1;
	
	  ;% wrist_flexion_B.Compare
	  section.data(3).logicalSrcIdx = 80;
	  section.data(3).dtTransOffset = 2;
	
	  ;% wrist_flexion_B.Compare_h
	  section.data(4).logicalSrcIdx = 81;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% wrist_flexion_B.SampleandHold.In
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% wrist_flexion_B.SampleandHold_k.In
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
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
    sectIdxOffset = 6;
    
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
    ;% Auto data (wrist_flexion_DWork)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% wrist_flexion_DWork.BehaviorWF_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% wrist_flexion_DWork.Memory_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% wrist_flexion_DWork.PCI6025E_RWORK
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% wrist_flexion_DWork.BehaviorWF_RWORK
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 66;
	
	  ;% wrist_flexion_DWork.UniformRandomNumber_RWORK.NextOutput
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 105;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% wrist_flexion_DWork.Receive_PWORK
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% wrist_flexion_DWork.BehaviorWF_PWORK
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% wrist_flexion_DWork.Send_PWORK
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% wrist_flexion_DWork.SFunction_IWORK.AcquireOK
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% wrist_flexion_DWork.SFunction_IWORK_p.AcquireOK
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% wrist_flexion_DWork.SFunction_IWORK_m.AcquireOK
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% wrist_flexion_DWork.PCI6025E_IWORK
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% wrist_flexion_DWork.Receive_IWORK
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 69;
	
	  ;% wrist_flexion_DWork.BehaviorWF_IWORK
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 71;
	
	  ;% wrist_flexion_DWork.Send_IWORK
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 96;
	
	  ;% wrist_flexion_DWork.SFunction_IWORK_pn.AcquireOK
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 98;
	
	  ;% wrist_flexion_DWork.UniformRandomNumber_IWORK.RandSeed
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 99;
	
	  ;% wrist_flexion_DWork.PortA_IWORK
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 100;
	
	  ;% wrist_flexion_DWork.PortB_IWORK
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 102;
	
	  ;% wrist_flexion_DWork.PCI6025E_IWORK_n
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 104;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% wrist_flexion_DWork.SampleandHold.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% wrist_flexion_DWork.SampleandHold_k.SampleandHold_SubsysRanBC
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


  targMap.checksum0 = 1870546500;
  targMap.checksum1 = 683336456;
  targMap.checksum2 = 165910783;
  targMap.checksum3 = 1781734223;

