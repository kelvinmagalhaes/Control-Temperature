/*
 * Nova_Modelagem_3003_dt.h
 *
 * Code generation for model "Nova_Modelagem_3003".
 *
 * Model version              : 1.32
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Sat Apr 13 20:21:38 2019
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Nova_Modelagem_3003_B.Sum3), 0, 0, 16 },

  { (char_T *)(&Nova_Modelagem_3003_B.DataTypeConversion), 3, 0, 3 }
  ,

  { (char_T *)(&Nova_Modelagem_3003_DW.TimeStampA), 0, 0, 4 },

  { (char_T *)
    (&Nova_Modelagem_3003_DW.GrficoControlePTemperaturaPWM_P.LoggedData), 11, 0,
    4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  4U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Nova_Modelagem_3003_P.PWM_pinNumber), 7, 0, 3 },

  { (char_T *)(&Nova_Modelagem_3003_P.SetPoint_Value), 0, 0, 29 },

  { (char_T *)(&Nova_Modelagem_3003_P.AnalogInput1_p1), 7, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] Nova_Modelagem_3003_dt.h */
