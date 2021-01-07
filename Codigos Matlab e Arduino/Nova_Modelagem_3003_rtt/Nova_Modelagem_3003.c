/*
 * File: Nova_Modelagem_3003.c
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
#include "Nova_Modelagem_3003_dt.h"

/* Block signals (auto storage) */
B_Nova_Modelagem_3003_T Nova_Modelagem_3003_B;

/* Continuous states */
X_Nova_Modelagem_3003_T Nova_Modelagem_3003_X;

/* Block states (auto storage) */
DW_Nova_Modelagem_3003_T Nova_Modelagem_3003_DW;

/* Real-time model */
RT_MODEL_Nova_Modelagem_3003_T Nova_Modelagem_3003_M_;
RT_MODEL_Nova_Modelagem_3003_T *const Nova_Modelagem_3003_M =
  &Nova_Modelagem_3003_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Nova_Modelagem_3003_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Nova_Modelagem_3003_output();
  Nova_Modelagem_3003_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Nova_Modelagem_3003_output();
  Nova_Modelagem_3003_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Nova_Modelagem_3003_output(void)
{
  real_T *lastU;
  uint16_T rtb_AnalogInput1_0;
  real_T rtb_Sum4;
  real_T rtb_Derivative;
  if (rtmIsMajorTimeStep(Nova_Modelagem_3003_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Nova_Modelagem_3003_M->solverInfo,
                          ((Nova_Modelagem_3003_M->Timing.clockTick0+1)*
      Nova_Modelagem_3003_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Nova_Modelagem_3003_M)) {
    Nova_Modelagem_3003_M->Timing.t[0] = rtsiGetT
      (&Nova_Modelagem_3003_M->solverInfo);
  }

  /* Sum: '<S1>/Sum3' incorporates:
   *  Constant: '<S1>/Temp_inicial'
   *  TransferFcn: '<S1>/Filtro'
   */
  Nova_Modelagem_3003_B.Sum3 = Nova_Modelagem_3003_P.Filtro_C *
    Nova_Modelagem_3003_X.Filtro_CSTATE +
    Nova_Modelagem_3003_P.Temp_inicial_Value;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/SetPoint'
   */
  Nova_Modelagem_3003_B.Sum1 = Nova_Modelagem_3003_P.SetPoint_Value -
    Nova_Modelagem_3003_B.Sum3;

  /* Gain: '<Root>/Control_P' */
  Nova_Modelagem_3003_B.Control_P = Nova_Modelagem_3003_P.Control_P_Gain *
    Nova_Modelagem_3003_B.Sum1;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/SetPoint'
   */
  Nova_Modelagem_3003_B.Sum2 = Nova_Modelagem_3003_P.SetPoint_Value -
    Nova_Modelagem_3003_B.Sum3;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Gain: '<Root>/I'
   *  Gain: '<Root>/Proporcional_PI'
   *  Integrator: '<Root>/Integrator'
   */
  Nova_Modelagem_3003_B.Sum3_a = Nova_Modelagem_3003_P.Proporcional_PI_Gain *
    Nova_Modelagem_3003_B.Sum2 + Nova_Modelagem_3003_P.I_Gain *
    Nova_Modelagem_3003_X.Integrator_CSTATE;

  /* Sum: '<Root>/Sum4' incorporates:
   *  Constant: '<Root>/SetPoint'
   */
  rtb_Sum4 = Nova_Modelagem_3003_P.SetPoint_Value - Nova_Modelagem_3003_B.Sum3;

  /* Gain: '<Root>/I2' */
  Nova_Modelagem_3003_B.I2 = Nova_Modelagem_3003_P.I2_Gain * rtb_Sum4;

  /* Derivative: '<Root>/Derivative' */
  if ((Nova_Modelagem_3003_DW.TimeStampA >= Nova_Modelagem_3003_M->Timing.t[0]) &&
      (Nova_Modelagem_3003_DW.TimeStampB >= Nova_Modelagem_3003_M->Timing.t[0]))
  {
    rtb_Derivative = 0.0;
  } else {
    rtb_Derivative = Nova_Modelagem_3003_DW.TimeStampA;
    lastU = &Nova_Modelagem_3003_DW.LastUAtTimeA;
    if (Nova_Modelagem_3003_DW.TimeStampA < Nova_Modelagem_3003_DW.TimeStampB) {
      if (Nova_Modelagem_3003_DW.TimeStampB < Nova_Modelagem_3003_M->Timing.t[0])
      {
        rtb_Derivative = Nova_Modelagem_3003_DW.TimeStampB;
        lastU = &Nova_Modelagem_3003_DW.LastUAtTimeB;
      }
    } else {
      if (Nova_Modelagem_3003_DW.TimeStampA >= Nova_Modelagem_3003_M->Timing.t[0])
      {
        rtb_Derivative = Nova_Modelagem_3003_DW.TimeStampB;
        lastU = &Nova_Modelagem_3003_DW.LastUAtTimeB;
      }
    }

    rtb_Derivative = (Nova_Modelagem_3003_B.I2 - *lastU) /
      (Nova_Modelagem_3003_M->Timing.t[0] - rtb_Derivative);
  }

  /* End of Derivative: '<Root>/Derivative' */

  /* Sum: '<Root>/Sum5' incorporates:
   *  Gain: '<Root>/Proporcional_PID'
   *  Integrator: '<Root>/Integrator_PID'
   */
  Nova_Modelagem_3003_B.Sum5 = (Nova_Modelagem_3003_P.Proporcional_PID_Gain *
    rtb_Sum4 + rtb_Derivative) + Nova_Modelagem_3003_X.Integrator_PID_CSTATE;

  /* Saturate: '<S2>/Saturação_p' */
  if (Nova_Modelagem_3003_B.Control_P > Nova_Modelagem_3003_P.Saturao_p_UpperSat)
  {
    Nova_Modelagem_3003_B.Saturao_p = Nova_Modelagem_3003_P.Saturao_p_UpperSat;
  } else if (Nova_Modelagem_3003_B.Control_P <
             Nova_Modelagem_3003_P.Saturao_p_LowerSat) {
    Nova_Modelagem_3003_B.Saturao_p = Nova_Modelagem_3003_P.Saturao_p_LowerSat;
  } else {
    Nova_Modelagem_3003_B.Saturao_p = Nova_Modelagem_3003_B.Control_P;
  }

  /* End of Saturate: '<S2>/Saturação_p' */

  /* TransferFcn: '<S2>/Transfer Fcn3' */
  Nova_Modelagem_3003_B.TransferFcn3 = 0.0;
  Nova_Modelagem_3003_B.TransferFcn3 += Nova_Modelagem_3003_P.TransferFcn3_C *
    Nova_Modelagem_3003_X.TransferFcn3_CSTATE;
  if (rtmIsMajorTimeStep(Nova_Modelagem_3003_M)) {
  }

  /* Saturate: '<S3>/Saturação_pi' */
  if (Nova_Modelagem_3003_B.Sum3_a > Nova_Modelagem_3003_P.Saturao_pi_UpperSat)
  {
    Nova_Modelagem_3003_B.Saturao_pi = Nova_Modelagem_3003_P.Saturao_pi_UpperSat;
  } else if (Nova_Modelagem_3003_B.Sum3_a <
             Nova_Modelagem_3003_P.Saturao_pi_LowerSat) {
    Nova_Modelagem_3003_B.Saturao_pi = Nova_Modelagem_3003_P.Saturao_pi_LowerSat;
  } else {
    Nova_Modelagem_3003_B.Saturao_pi = Nova_Modelagem_3003_B.Sum3_a;
  }

  /* End of Saturate: '<S3>/Saturação_pi' */

  /* TransferFcn: '<S3>/Transfer Fcn3' */
  Nova_Modelagem_3003_B.TransferFcn3_h = 0.0;
  Nova_Modelagem_3003_B.TransferFcn3_h +=
    Nova_Modelagem_3003_P.TransferFcn3_C_a[0] *
    Nova_Modelagem_3003_X.TransferFcn3_CSTATE_i[0];
  Nova_Modelagem_3003_B.TransferFcn3_h +=
    Nova_Modelagem_3003_P.TransferFcn3_C_a[1] *
    Nova_Modelagem_3003_X.TransferFcn3_CSTATE_i[1];
  if (rtmIsMajorTimeStep(Nova_Modelagem_3003_M)) {
  }

  /* Saturate: '<S4>/Saturação' */
  if (Nova_Modelagem_3003_B.Sum5 > Nova_Modelagem_3003_P.Saturao_UpperSat) {
    Nova_Modelagem_3003_B.Saturao = Nova_Modelagem_3003_P.Saturao_UpperSat;
  } else if (Nova_Modelagem_3003_B.Sum5 < Nova_Modelagem_3003_P.Saturao_LowerSat)
  {
    Nova_Modelagem_3003_B.Saturao = Nova_Modelagem_3003_P.Saturao_LowerSat;
  } else {
    Nova_Modelagem_3003_B.Saturao = Nova_Modelagem_3003_B.Sum5;
  }

  /* End of Saturate: '<S4>/Saturação' */

  /* TransferFcn: '<S4>/Transfer Fcn3' */
  Nova_Modelagem_3003_B.TransferFcn3_b = 0.0;
  Nova_Modelagem_3003_B.TransferFcn3_b +=
    Nova_Modelagem_3003_P.TransferFcn3_C_e[0] *
    Nova_Modelagem_3003_X.TransferFcn3_CSTATE_p[0];
  Nova_Modelagem_3003_B.TransferFcn3_b +=
    Nova_Modelagem_3003_P.TransferFcn3_C_e[1] *
    Nova_Modelagem_3003_X.TransferFcn3_CSTATE_p[1];
  if (rtmIsMajorTimeStep(Nova_Modelagem_3003_M)) {
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  if (Nova_Modelagem_3003_B.Saturao_p < 256.0) {
    if (Nova_Modelagem_3003_B.Saturao_p >= 0.0) {
      Nova_Modelagem_3003_B.DataTypeConversion = (uint8_T)
        Nova_Modelagem_3003_B.Saturao_p;
    } else {
      Nova_Modelagem_3003_B.DataTypeConversion = 0U;
    }
  } else {
    Nova_Modelagem_3003_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Nova_Modelagem_3003_M)) {
    /* S-Function (arduinoanalogoutput_sfcn): '<S5>/PWM' */
    MW_analogWrite(Nova_Modelagem_3003_P.PWM_pinNumber,
                   Nova_Modelagem_3003_B.DataTypeConversion);
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  if (Nova_Modelagem_3003_B.Saturao_pi < 256.0) {
    if (Nova_Modelagem_3003_B.Saturao_pi >= 0.0) {
      Nova_Modelagem_3003_B.DataTypeConversion_d = (uint8_T)
        Nova_Modelagem_3003_B.Saturao_pi;
    } else {
      Nova_Modelagem_3003_B.DataTypeConversion_d = 0U;
    }
  } else {
    Nova_Modelagem_3003_B.DataTypeConversion_d = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Nova_Modelagem_3003_M)) {
    /* S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
    MW_analogWrite(Nova_Modelagem_3003_P.PWM_pinNumber_c,
                   Nova_Modelagem_3003_B.DataTypeConversion_d);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  if (Nova_Modelagem_3003_B.Saturao < 256.0) {
    if (Nova_Modelagem_3003_B.Saturao >= 0.0) {
      Nova_Modelagem_3003_B.DataTypeConversion_o = (uint8_T)
        Nova_Modelagem_3003_B.Saturao;
    } else {
      Nova_Modelagem_3003_B.DataTypeConversion_o = 0U;
    }
  } else {
    Nova_Modelagem_3003_B.DataTypeConversion_o = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Nova_Modelagem_3003_M)) {
    /* S-Function (arduinoanalogoutput_sfcn): '<S7>/PWM' */
    MW_analogWrite(Nova_Modelagem_3003_P.PWM_pinNumber_e,
                   Nova_Modelagem_3003_B.DataTypeConversion_o);

    /* S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input1' */
    rtb_AnalogInput1_0 = MW_analogRead(Nova_Modelagem_3003_P.AnalogInput1_p1);

    /* Product: '<S1>/Temperatura' incorporates:
     *  Constant: '<S1>/Constant1'
     *  S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input1'
     */
    Nova_Modelagem_3003_B.Temperatura = (real_T)rtb_AnalogInput1_0 *
      Nova_Modelagem_3003_P.Constant1_Value;
  }

  /* Gain: '<Root>/I1' */
  Nova_Modelagem_3003_B.I1 = Nova_Modelagem_3003_P.I1_Gain * rtb_Sum4;
  if (rtmIsMajorTimeStep(Nova_Modelagem_3003_M)) {
    /* Sum: '<S1>/Sum2' incorporates:
     *  Constant: '<S1>/Temp_inicial'
     */
    Nova_Modelagem_3003_B.Sum2_h = Nova_Modelagem_3003_B.Temperatura -
      Nova_Modelagem_3003_P.Temp_inicial_Value;
  }
}

/* Model update function */
void Nova_Modelagem_3003_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative' */
  if (Nova_Modelagem_3003_DW.TimeStampA == (rtInf)) {
    Nova_Modelagem_3003_DW.TimeStampA = Nova_Modelagem_3003_M->Timing.t[0];
    lastU = &Nova_Modelagem_3003_DW.LastUAtTimeA;
  } else if (Nova_Modelagem_3003_DW.TimeStampB == (rtInf)) {
    Nova_Modelagem_3003_DW.TimeStampB = Nova_Modelagem_3003_M->Timing.t[0];
    lastU = &Nova_Modelagem_3003_DW.LastUAtTimeB;
  } else if (Nova_Modelagem_3003_DW.TimeStampA <
             Nova_Modelagem_3003_DW.TimeStampB) {
    Nova_Modelagem_3003_DW.TimeStampA = Nova_Modelagem_3003_M->Timing.t[0];
    lastU = &Nova_Modelagem_3003_DW.LastUAtTimeA;
  } else {
    Nova_Modelagem_3003_DW.TimeStampB = Nova_Modelagem_3003_M->Timing.t[0];
    lastU = &Nova_Modelagem_3003_DW.LastUAtTimeB;
  }

  *lastU = Nova_Modelagem_3003_B.I2;

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Nova_Modelagem_3003_M)!=-1) &&
        !((rtmGetTFinal(Nova_Modelagem_3003_M)-
           ((Nova_Modelagem_3003_M->Timing.clockTick1) * 0.1)) >
          ((Nova_Modelagem_3003_M->Timing.clockTick1) * 0.1) * (DBL_EPSILON))) {
      rtmSetErrorStatus(Nova_Modelagem_3003_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Nova_Modelagem_3003_M)) {
      rtmSetErrorStatus(Nova_Modelagem_3003_M, "Simulation finished");
    }
  }

  if (rtmIsMajorTimeStep(Nova_Modelagem_3003_M)) {
    rt_ertODEUpdateContinuousStates(&Nova_Modelagem_3003_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++Nova_Modelagem_3003_M->Timing.clockTick0;
  Nova_Modelagem_3003_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Nova_Modelagem_3003_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Nova_Modelagem_3003_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void Nova_Modelagem_3003_derivatives(void)
{
  XDot_Nova_Modelagem_3003_T *_rtXdot;
  _rtXdot = ((XDot_Nova_Modelagem_3003_T *)
             Nova_Modelagem_3003_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S1>/Filtro' */
  _rtXdot->Filtro_CSTATE = 0.0;
  _rtXdot->Filtro_CSTATE += Nova_Modelagem_3003_P.Filtro_A *
    Nova_Modelagem_3003_X.Filtro_CSTATE;
  _rtXdot->Filtro_CSTATE += Nova_Modelagem_3003_B.Sum2_h;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Nova_Modelagem_3003_B.Sum2;

  /* Derivatives for Integrator: '<Root>/Integrator_PID' */
  _rtXdot->Integrator_PID_CSTATE = Nova_Modelagem_3003_B.I1;

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE = 0.0;
  _rtXdot->TransferFcn3_CSTATE += Nova_Modelagem_3003_P.TransferFcn3_A *
    Nova_Modelagem_3003_X.TransferFcn3_CSTATE;
  _rtXdot->TransferFcn3_CSTATE += Nova_Modelagem_3003_B.Saturao_p;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE_i[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE_i[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE_i[0] += Nova_Modelagem_3003_P.TransferFcn3_A_k[0]
    * Nova_Modelagem_3003_X.TransferFcn3_CSTATE_i[0];
  _rtXdot->TransferFcn3_CSTATE_i[0] += Nova_Modelagem_3003_P.TransferFcn3_A_k[1]
    * Nova_Modelagem_3003_X.TransferFcn3_CSTATE_i[1];
  _rtXdot->TransferFcn3_CSTATE_i[1] +=
    Nova_Modelagem_3003_X.TransferFcn3_CSTATE_i[0];
  _rtXdot->TransferFcn3_CSTATE_i[0] += Nova_Modelagem_3003_B.Saturao_pi;

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE_p[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE_p[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE_p[0] += Nova_Modelagem_3003_P.TransferFcn3_A_p[0]
    * Nova_Modelagem_3003_X.TransferFcn3_CSTATE_p[0];
  _rtXdot->TransferFcn3_CSTATE_p[0] += Nova_Modelagem_3003_P.TransferFcn3_A_p[1]
    * Nova_Modelagem_3003_X.TransferFcn3_CSTATE_p[1];
  _rtXdot->TransferFcn3_CSTATE_p[1] +=
    Nova_Modelagem_3003_X.TransferFcn3_CSTATE_p[0];
  _rtXdot->TransferFcn3_CSTATE_p[0] += Nova_Modelagem_3003_B.Saturao;
}

/* Model initialize function */
void Nova_Modelagem_3003_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Nova_Modelagem_3003_M, 0,
                sizeof(RT_MODEL_Nova_Modelagem_3003_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Nova_Modelagem_3003_M->solverInfo,
                          &Nova_Modelagem_3003_M->Timing.simTimeStep);
    rtsiSetTPtr(&Nova_Modelagem_3003_M->solverInfo, &rtmGetTPtr
                (Nova_Modelagem_3003_M));
    rtsiSetStepSizePtr(&Nova_Modelagem_3003_M->solverInfo,
                       &Nova_Modelagem_3003_M->Timing.stepSize0);
    rtsiSetdXPtr(&Nova_Modelagem_3003_M->solverInfo,
                 &Nova_Modelagem_3003_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Nova_Modelagem_3003_M->solverInfo, (real_T **)
                         &Nova_Modelagem_3003_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Nova_Modelagem_3003_M->solverInfo,
      &Nova_Modelagem_3003_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Nova_Modelagem_3003_M->solverInfo,
                          (&rtmGetErrorStatus(Nova_Modelagem_3003_M)));
    rtsiSetRTModelPtr(&Nova_Modelagem_3003_M->solverInfo, Nova_Modelagem_3003_M);
  }

  rtsiSetSimTimeStep(&Nova_Modelagem_3003_M->solverInfo, MAJOR_TIME_STEP);
  Nova_Modelagem_3003_M->ModelData.intgData.y =
    Nova_Modelagem_3003_M->ModelData.odeY;
  Nova_Modelagem_3003_M->ModelData.intgData.f[0] =
    Nova_Modelagem_3003_M->ModelData.odeF[0];
  Nova_Modelagem_3003_M->ModelData.intgData.f[1] =
    Nova_Modelagem_3003_M->ModelData.odeF[1];
  Nova_Modelagem_3003_M->ModelData.intgData.f[2] =
    Nova_Modelagem_3003_M->ModelData.odeF[2];
  Nova_Modelagem_3003_M->ModelData.contStates = ((X_Nova_Modelagem_3003_T *)
    &Nova_Modelagem_3003_X);
  rtsiSetSolverData(&Nova_Modelagem_3003_M->solverInfo, (void *)
                    &Nova_Modelagem_3003_M->ModelData.intgData);
  rtsiSetSolverName(&Nova_Modelagem_3003_M->solverInfo,"ode3");
  rtmSetTPtr(Nova_Modelagem_3003_M, &Nova_Modelagem_3003_M->Timing.tArray[0]);
  rtmSetTFinal(Nova_Modelagem_3003_M, -1);
  Nova_Modelagem_3003_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Nova_Modelagem_3003_M->Sizes.checksums[0] = (1974061368U);
  Nova_Modelagem_3003_M->Sizes.checksums[1] = (2952134102U);
  Nova_Modelagem_3003_M->Sizes.checksums[2] = (3367422735U);
  Nova_Modelagem_3003_M->Sizes.checksums[3] = (2732634227U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Nova_Modelagem_3003_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Nova_Modelagem_3003_M->extModeInfo,
      &Nova_Modelagem_3003_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Nova_Modelagem_3003_M->extModeInfo,
                        Nova_Modelagem_3003_M->Sizes.checksums);
    rteiSetTPtr(Nova_Modelagem_3003_M->extModeInfo, rtmGetTPtr
                (Nova_Modelagem_3003_M));
  }

  /* block I/O */
  (void) memset(((void *) &Nova_Modelagem_3003_B), 0,
                sizeof(B_Nova_Modelagem_3003_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Nova_Modelagem_3003_X, 0,
                  sizeof(X_Nova_Modelagem_3003_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Nova_Modelagem_3003_DW, 0,
                sizeof(DW_Nova_Modelagem_3003_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Nova_Modelagem_3003_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S5>/PWM' */
  MW_pinModeOutput(Nova_Modelagem_3003_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
  MW_pinModeOutput(Nova_Modelagem_3003_P.PWM_pinNumber_c);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S7>/PWM' */
  MW_pinModeOutput(Nova_Modelagem_3003_P.PWM_pinNumber_e);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input1' */
  MW_pinModeAnalogInput(Nova_Modelagem_3003_P.AnalogInput1_p1);

  /* InitializeConditions for TransferFcn: '<S1>/Filtro' */
  Nova_Modelagem_3003_X.Filtro_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Nova_Modelagem_3003_X.Integrator_CSTATE = Nova_Modelagem_3003_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  Nova_Modelagem_3003_DW.TimeStampA = (rtInf);
  Nova_Modelagem_3003_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<Root>/Integrator_PID' */
  Nova_Modelagem_3003_X.Integrator_PID_CSTATE =
    Nova_Modelagem_3003_P.Integrator_PID_IC;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn3' */
  Nova_Modelagem_3003_X.TransferFcn3_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn3' */
  Nova_Modelagem_3003_X.TransferFcn3_CSTATE_i[0] = 0.0;
  Nova_Modelagem_3003_X.TransferFcn3_CSTATE_i[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn3' */
  Nova_Modelagem_3003_X.TransferFcn3_CSTATE_p[0] = 0.0;
  Nova_Modelagem_3003_X.TransferFcn3_CSTATE_p[1] = 0.0;
}

/* Model terminate function */
void Nova_Modelagem_3003_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
