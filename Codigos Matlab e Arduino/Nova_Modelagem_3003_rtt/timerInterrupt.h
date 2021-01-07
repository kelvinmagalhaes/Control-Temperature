/*
 * File: timerInterrupt.h
 *
 * Code generated for Simulink model 'Nova_Modelagem_3003'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Sat Apr 13 20:21:38 2019
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_timerInterrupt_h_
#define RTW_HEADER_timerInterrupt_h_
#include "Arduino.h"
#define disable_Timer_Interrupt        TIMSK5 &= ~(1<<TOIE5)
#define enable_Timer_Interrupt         TIMSK5 |= (1<<TOIE5)
#endif                                 /* RTW_HEADER_timerInterrupt_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
