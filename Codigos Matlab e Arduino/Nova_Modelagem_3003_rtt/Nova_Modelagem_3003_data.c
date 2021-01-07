/*
 * File: Nova_Modelagem_3003_data.c
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

#include "Nova_Modelagem_3003.h"
#include "Nova_Modelagem_3003_private.h"

/* Block parameters (auto storage) */
P_Nova_Modelagem_3003_T Nova_Modelagem_3003_P = {
  9U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S5>/PWM'
                                        */
  10U,                                 /* Mask Parameter: PWM_pinNumber_c
                                        * Referenced by: '<S6>/PWM'
                                        */
  8U,                                  /* Mask Parameter: PWM_pinNumber_e
                                        * Referenced by: '<S7>/PWM'
                                        */
  42.0,                                /* Expression: 42
                                        * Referenced by: '<Root>/SetPoint'
                                        */
  -0.5,                                /* Computed Parameter: Filtro_A
                                        * Referenced by: '<S1>/Filtro'
                                        */
  0.5,                                 /* Computed Parameter: Filtro_C
                                        * Referenced by: '<S1>/Filtro'
                                        */
  29.5,                                /* Expression: 29.50
                                        * Referenced by: '<S1>/Temp_inicial'
                                        */
  -195.0,                              /* Expression: -195
                                        * Referenced by: '<Root>/Control_P'
                                        */
  -195.0,                              /* Expression: -195
                                        * Referenced by: '<Root>/Proporcional_PI'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  0.16,                                /* Expression: 0.16
                                        * Referenced by: '<Root>/I'
                                        */
  12.5,                                /* Expression: 12.5
                                        * Referenced by: '<Root>/I2'
                                        */
  -195.0,                              /* Expression: -195
                                        * Referenced by: '<Root>/Proporcional_PID'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator_PID'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S2>/Saturação_p'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<S2>/Saturação_p'
                                        */
  -0.01,                               /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<S2>/Transfer Fcn3'
                                        */
  -0.009736,                           /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<S2>/Transfer Fcn3'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S3>/Saturação_pi'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<S3>/Saturação_pi'
                                        */

  /*  Computed Parameter: TransferFcn3_A_k
   * Referenced by: '<S3>/Transfer Fcn3'
   */
  { -0.08, -0.0016 },

  /*  Computed Parameter: TransferFcn3_C_a
   * Referenced by: '<S3>/Transfer Fcn3'
   */
  { 0.0, -0.00032 },
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S4>/Saturação'
                                        */
  20.0,                                /* Expression: 20
                                        * Referenced by: '<S4>/Saturação'
                                        */

  /*  Computed Parameter: TransferFcn3_A_p
   * Referenced by: '<S4>/Transfer Fcn3'
   */
  { -0.05, -0.0004 },

  /*  Computed Parameter: TransferFcn3_C_e
   * Referenced by: '<S4>/Transfer Fcn3'
   */
  { 0.0, -0.00038944 },
  0.48875855327468232,                 /* Expression: (5/1023)/0.01
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.020768431983385256,                /* Expression: 1/48.15
                                        * Referenced by: '<Root>/I1'
                                        */
  0U                                   /* Computed Parameter: AnalogInput1_p1
                                        * Referenced by: '<S1>/Analog Input1'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
