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
    ;% Auto data (Controle_principal_P)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Controle_principal_P.PWM_pinNumber
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Controle_principal_P.PWM_pinNumber_c
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Controle_principal_P.PWM_pinNumber_e
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% Controle_principal_P.SetPoint_Value
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Controle_principal_P.Filtro_A
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Controle_principal_P.Filtro_C
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Controle_principal_P.Temp_inicial_Value
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Controle_principal_P.Control_P_Gain
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Controle_principal_P.Proporcional_PI_Gain
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Controle_principal_P.Integrator_IC
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Controle_principal_P.I_Gain
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Controle_principal_P.I2_Gain
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Controle_principal_P.Proporcional_PID_Gain
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Controle_principal_P.Integrator_PID_IC
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Controle_principal_P.Saturao_p_UpperSat
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Controle_principal_P.Saturao_p_LowerSat
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Controle_principal_P.TransferFcn3_A
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Controle_principal_P.TransferFcn3_C
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Controle_principal_P.Saturao_pi_UpperSat
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Controle_principal_P.Saturao_pi_LowerSat
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Controle_principal_P.TransferFcn3_A_k
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Controle_principal_P.TransferFcn3_C_a
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 19;
	
	  ;% Controle_principal_P.Saturao_UpperSat
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 21;
	
	  ;% Controle_principal_P.Saturao_LowerSat
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 22;
	
	  ;% Controle_principal_P.TransferFcn3_A_p
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 23;
	
	  ;% Controle_principal_P.TransferFcn3_C_e
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 25;
	
	  ;% Controle_principal_P.Constant1_Value
	  section.data(24).logicalSrcIdx = 26;
	  section.data(24).dtTransOffset = 27;
	
	  ;% Controle_principal_P.I1_Gain
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 28;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Controle_principal_P.AnalogInput1_p1
	  section.data(1).logicalSrcIdx = 28;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Controle_principal_B)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% Controle_principal_B.Sum3
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Controle_principal_B.Sum1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Controle_principal_B.Control_P
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Controle_principal_B.Sum2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Controle_principal_B.Sum3_a
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Controle_principal_B.I2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Controle_principal_B.Sum5
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Controle_principal_B.Saturao_p
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Controle_principal_B.TransferFcn3
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Controle_principal_B.Saturao_pi
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Controle_principal_B.TransferFcn3_h
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Controle_principal_B.Saturao
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Controle_principal_B.TransferFcn3_b
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Controle_principal_B.Temperatura
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Controle_principal_B.I1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Controle_principal_B.Sum2_h
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Controle_principal_B.DataTypeConversion
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Controle_principal_B.DataTypeConversion_d
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Controle_principal_B.DataTypeConversion_o
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    nTotSects     = 2;
    sectIdxOffset = 2;
    
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
    ;% Auto data (Controle_principal_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Controle_principal_DW.TimeStampA
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Controle_principal_DW.LastUAtTimeA
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Controle_principal_DW.TimeStampB
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Controle_principal_DW.LastUAtTimeB
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Controle_principal_DW.GrficoControlePTemperaturaPWM_P.LoggedData
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Controle_principal_DW.GrficoControlePITemperaturaPWM_.LoggedData
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Controle_principal_DW.GrficoControlePIDTemperaturaPWM.LoggedData
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Controle_principal_DW.TemperaturasemFiltroTemperatura.LoggedData
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
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


  targMap.checksum0 = 3438675254;
  targMap.checksum1 = 3938842484;
  targMap.checksum2 = 2772615847;
  targMap.checksum3 = 2026578320;

