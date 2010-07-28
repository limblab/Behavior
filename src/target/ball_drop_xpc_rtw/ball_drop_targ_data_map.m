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
    ;% Auto data (ball_drop_P)
    ;%
      section.nData     = 105;
      section.data(105)  = dumData; %prealloc
      
	  ;% ball_drop_P.PCI6025EDI_P1_Size
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ball_drop_P.PCI6025EDI_P1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% ball_drop_P.PCI6025EDI_P2_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% ball_drop_P.PCI6025EDI_P2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% ball_drop_P.PCI6025EDI_P3_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% ball_drop_P.PCI6025EDI_P3
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% ball_drop_P.PCI6025EDI_P4_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 9;
	
	  ;% ball_drop_P.PCI6025EDI_P4
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 11;
	
	  ;% ball_drop_P.PCI6025EDI_P5_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 12;
	
	  ;% ball_drop_P.PCI6025EDI_P5
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% ball_drop_P.Constant_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 15;
	
	  ;% ball_drop_P.PCI6025EAD_P1_Size
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 16;
	
	  ;% ball_drop_P.PCI6025EAD_P1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 18;
	
	  ;% ball_drop_P.PCI6025EAD_P2_Size
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 20;
	
	  ;% ball_drop_P.PCI6025EAD_P2
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 22;
	
	  ;% ball_drop_P.PCI6025EAD_P3_Size
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 24;
	
	  ;% ball_drop_P.PCI6025EAD_P3
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 26;
	
	  ;% ball_drop_P.PCI6025EAD_P4_Size
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 28;
	
	  ;% ball_drop_P.PCI6025EAD_P4
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 30;
	
	  ;% ball_drop_P.PCI6025EAD_P5_Size
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 31;
	
	  ;% ball_drop_P.PCI6025EAD_P5
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 33;
	
	  ;% ball_drop_P.PCI6025EAD_P6_Size
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 34;
	
	  ;% ball_drop_P.PCI6025EAD_P6
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 36;
	
	  ;% ball_drop_P.Constant1_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 37;
	
	  ;% ball_drop_P.Switch_Threshold
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 38;
	
	  ;% ball_drop_P.Switch1_Threshold
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 39;
	
	  ;% ball_drop_P.BehaviorBD_P1_Size
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 40;
	
	  ;% ball_drop_P.BehaviorBD_P1
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 42;
	
	  ;% ball_drop_P.BehaviorBD_P2_Size
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 43;
	
	  ;% ball_drop_P.BehaviorBD_P2
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 45;
	
	  ;% ball_drop_P.BehaviorBD_P3_Size
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 46;
	
	  ;% ball_drop_P.BehaviorBD_P3
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 48;
	
	  ;% ball_drop_P.BehaviorBD_P4_Size
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 49;
	
	  ;% ball_drop_P.BehaviorBD_P4
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 51;
	
	  ;% ball_drop_P.BehaviorBD_P5_Size
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 52;
	
	  ;% ball_drop_P.BehaviorBD_P5
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 54;
	
	  ;% ball_drop_P.BehaviorBD_P6_Size
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 55;
	
	  ;% ball_drop_P.BehaviorBD_P6
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 57;
	
	  ;% ball_drop_P.BehaviorBD_P7_Size
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 58;
	
	  ;% ball_drop_P.BehaviorBD_P7
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 60;
	
	  ;% ball_drop_P.BehaviorBD_P8_Size
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 61;
	
	  ;% ball_drop_P.BehaviorBD_P8
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 63;
	
	  ;% ball_drop_P.BehaviorBD_P9_Size
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 64;
	
	  ;% ball_drop_P.BehaviorBD_P9
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 66;
	
	  ;% ball_drop_P.PCI6025EDO_P1_Size
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 67;
	
	  ;% ball_drop_P.PCI6025EDO_P1
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 69;
	
	  ;% ball_drop_P.PCI6025EDO_P2_Size
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 73;
	
	  ;% ball_drop_P.PCI6025EDO_P2
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 75;
	
	  ;% ball_drop_P.PCI6025EDO_P3_Size
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 79;
	
	  ;% ball_drop_P.PCI6025EDO_P3
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 81;
	
	  ;% ball_drop_P.PCI6025EDO_P4_Size
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 85;
	
	  ;% ball_drop_P.PCI6025EDO_P4
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 87;
	
	  ;% ball_drop_P.PCI6025EDO_P5_Size
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 88;
	
	  ;% ball_drop_P.PCI6025EDO_P5
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 90;
	
	  ;% ball_drop_P.PCI6025EDO_P6_Size
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 91;
	
	  ;% ball_drop_P.PCI6025EDO_P6
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 93;
	
	  ;% ball_drop_P.PCI6025EDO_P7_Size
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 94;
	
	  ;% ball_drop_P.PCI6025EDO_P7
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 96;
	
	  ;% ball_drop_P.UniformRandomNumber_Min
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 97;
	
	  ;% ball_drop_P.UniformRandomNumber_Max
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 98;
	
	  ;% ball_drop_P.UniformRandomNumber_Seed
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 99;
	
	  ;% ball_drop_P.JackpotChance_Value
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 100;
	
	  ;% ball_drop_P.PCI6025EDO_P1_Size_h
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 101;
	
	  ;% ball_drop_P.PCI6025EDO_P1_h
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 103;
	
	  ;% ball_drop_P.PCI6025EDO_P2_Size_f
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 104;
	
	  ;% ball_drop_P.PCI6025EDO_P2_i
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 106;
	
	  ;% ball_drop_P.PCI6025EDO_P3_Size_n
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 107;
	
	  ;% ball_drop_P.PCI6025EDO_P3_b
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 109;
	
	  ;% ball_drop_P.PCI6025EDO_P4_Size_j
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 110;
	
	  ;% ball_drop_P.PCI6025EDO_P4_c
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 112;
	
	  ;% ball_drop_P.PCI6025EDO_P5_Size_p
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 113;
	
	  ;% ball_drop_P.PCI6025EDO_P5_k
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 115;
	
	  ;% ball_drop_P.PCI6025EDO_P6_Size_n
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 116;
	
	  ;% ball_drop_P.PCI6025EDO_P6_k
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 118;
	
	  ;% ball_drop_P.PCI6025EDO_P7_Size_p
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 119;
	
	  ;% ball_drop_P.PCI6025EDO_P7_c
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 121;
	
	  ;% ball_drop_P.Pos_Value
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 122;
	
	  ;% ball_drop_P.Send_P1_Size
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 123;
	
	  ;% ball_drop_P.Send_P1
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 125;
	
	  ;% ball_drop_P.Send_P2_Size
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 136;
	
	  ;% ball_drop_P.Send_P2
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 138;
	
	  ;% ball_drop_P.Send_P3_Size
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 139;
	
	  ;% ball_drop_P.Send_P3
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 141;
	
	  ;% ball_drop_P.Send_P4_Size
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 142;
	
	  ;% ball_drop_P.Send_P4
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 144;
	
	  ;% ball_drop_P.PortA_P1_Size
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 145;
	
	  ;% ball_drop_P.PortA_P1
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 147;
	
	  ;% ball_drop_P.PortA_P2_Size
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 155;
	
	  ;% ball_drop_P.PortA_P2
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 157;
	
	  ;% ball_drop_P.PortA_P3_Size
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 158;
	
	  ;% ball_drop_P.PortA_P3
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 160;
	
	  ;% ball_drop_P.PortA_P4_Size
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 168;
	
	  ;% ball_drop_P.PortA_P4
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 170;
	
	  ;% ball_drop_P.PortA_P5_Size
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 178;
	
	  ;% ball_drop_P.PortA_P5
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 180;
	
	  ;% ball_drop_P.PortA_P6_Size
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 181;
	
	  ;% ball_drop_P.PortA_P6
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 183;
	
	  ;% ball_drop_P.PortA_P7_Size
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 184;
	
	  ;% ball_drop_P.PortA_P7
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 186;
	
	  ;% ball_drop_P.PortA_P8_Size
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 187;
	
	  ;% ball_drop_P.PortA_P8
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 189;
	
	  ;% ball_drop_P.PortA_P9_Size
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 190;
	
	  ;% ball_drop_P.PortA_P9
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 192;
	
	  ;% ball_drop_P.RewardJackpot_Value
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 193;
	
	  ;% ball_drop_P.RewardTime_Value
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 194;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ball_drop_P.SampleandHold._Y0
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ball_drop_P.SampleandHold_i._Y0
	  section.data(1).logicalSrcIdx = 106;
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
    ;% Auto data (ball_drop_B)
    ;%
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% ball_drop_B.PCI6025EDI
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ball_drop_B.PCI6025EAD_o1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ball_drop_B.PCI6025EAD_o2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% ball_drop_B.Switch
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% ball_drop_B.Switch1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% ball_drop_B.BehaviorBD_o1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% ball_drop_B.BehaviorBD_o2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% ball_drop_B.BehaviorBD_o3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% ball_drop_B.BehaviorBD_o4
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% ball_drop_B.BehaviorBD_o5
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% ball_drop_B.BehaviorBD_o6
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% ball_drop_B.BehaviorBD_o7
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% ball_drop_B.BehaviorBD_o8
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 17;
	
	  ;% ball_drop_B.BehaviorBD_o9
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 27;
	
	  ;% ball_drop_B.ToBits_o1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 31;
	
	  ;% ball_drop_B.ToBits_o2
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 32;
	
	  ;% ball_drop_B.ToBits_o3
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 33;
	
	  ;% ball_drop_B.ToBits_o4
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 34;
	
	  ;% ball_drop_B.ToBits_o5
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 35;
	
	  ;% ball_drop_B.ToBits_o6
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 36;
	
	  ;% ball_drop_B.ToBits_o7
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 37;
	
	  ;% ball_drop_B.ToBits_o8
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 38;
	
	  ;% ball_drop_B.Clock
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 39;
	
	  ;% ball_drop_B.HiddenBuf_InsertedFor_Sampleand
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 40;
	
	  ;% ball_drop_B.Sum
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 41;
	
	  ;% ball_drop_B.UniformRandomNumber
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 42;
	
	  ;% ball_drop_B.Switch_h
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 43;
	
	  ;% ball_drop_B.HiddenBuf_InsertedFor_Samplea_c
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 44;
	
	  ;% ball_drop_B.DataTypeConversion
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 45;
	
	  ;% ball_drop_B.ToBits_o1_i
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 46;
	
	  ;% ball_drop_B.ToBits_o2_h
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 47;
	
	  ;% ball_drop_B.ToBits_o3_d
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 48;
	
	  ;% ball_drop_B.ToBits_o4_j
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 49;
	
	  ;% ball_drop_B.ToBits_o5_g
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 50;
	
	  ;% ball_drop_B.ToBits_o6_i
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 51;
	
	  ;% ball_drop_B.ToBits_o7_p
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 52;
	
	  ;% ball_drop_B.ToBits_o8_h
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 53;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ball_drop_B.Pack
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ball_drop_B.RateTransition
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 112;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% ball_drop_B.RelationalOperator
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ball_drop_B.RelationalOperator_c
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ball_drop_B.SampleandHold.In
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ball_drop_B.SampleandHold_i.In
	  section.data(1).logicalSrcIdx = 42;
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
    ;% Auto data (ball_drop_DWork)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% ball_drop_DWork.BehaviorBD_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ball_drop_DWork.PCI6025EAD_RWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% ball_drop_DWork.BehaviorBD_RWORK
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 65;
	
	  ;% ball_drop_DWork.UniformRandomNumber_RWORK.NextOutput
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 75;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ball_drop_DWork.Send_PWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% ball_drop_DWork.PCI6025EDI_IWORK
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% ball_drop_DWork.PCI6025EAD_IWORK
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 3;
	
	  ;% ball_drop_DWork.BehaviorBD_IWORK
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 69;
	
	  ;% ball_drop_DWork.PCI6025EDO_IWORK
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 75;
	
	  ;% ball_drop_DWork.UniformRandomNumber_IWORK.RandSeed
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 78;
	
	  ;% ball_drop_DWork.PCI6025EDO_IWORK_a
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 79;
	
	  ;% ball_drop_DWork.SFunction_IWORK.AcquireOK
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 82;
	
	  ;% ball_drop_DWork.SFunction_IWORK_d.AcquireOK
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 83;
	
	  ;% ball_drop_DWork.Send_IWORK
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 84;
	
	  ;% ball_drop_DWork.SFunction_IWORK_j.AcquireOK
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 86;
	
	  ;% ball_drop_DWork.PortA_IWORK
	  section.data(11).logicalSrcIdx = 15;
	  section.data(11).dtTransOffset = 87;
	
	  ;% ball_drop_DWork.SFunction_IWORK_i.AcquireOK
	  section.data(12).logicalSrcIdx = 16;
	  section.data(12).dtTransOffset = 89;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ball_drop_DWork.SampleandHold.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% ball_drop_DWork.SampleandHold_i.SampleandHold_SubsysRanBC
	  section.data(1).logicalSrcIdx = 18;
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


  targMap.checksum0 = 3348203731;
  targMap.checksum1 = 2436526730;
  targMap.checksum2 = 2958427952;
  targMap.checksum3 = 3764359373;

