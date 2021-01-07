/*
 * File: Controle_principal.c
 *
 * Code generated for Simulink model 'Controle_principal'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Sat Apr 13 21:36:20 2019
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Controle_principal.h"
#include "Controle_principal_private.h"
#include "Controle_principal_dt.h"

/* Block signals (auto storage) */
B_Controle_principal_T Controle_principal_B;

/* Continuous states */
X_Controle_principal_T Controle_principal_X;

/* Block states (auto storage) */
DW_Controle_principal_T Controle_principal_DW;

/* Real-time model */
RT_MODEL_Controle_principal_T Controle_principal_M_;
RT_MODEL_Controle_principal_T *const Controle_principal_M =
  &Controle_principal_M_;

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
  Controle_principal_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Controle_principal_output();
  Controle_principal_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Controle_principal_output();
  Controle_principal_derivatives();

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
void Controle_principal_output(void)
{
  real_T *lastU;
  uint16_T rtb_AnalogInput1_0;
  real_T rtb_Sum4;
  real_T rtb_Derivative;
  if (rtmIsMajorTimeStep(Controle_principal_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Controle_principal_M->solverInfo,
                          ((Controle_principal_M->Timing.clockTick0+1)*
      Controle_principal_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Controle_principal_M)) {
    Controle_principal_M->Timing.t[0] = rtsiGetT
      (&Controle_principal_M->solverInfo);
  }

  /* Sum: '<S1>/Sum3' incorporates:
   *  Constant: '<S1>/Temp_inicial'
   *  TransferFcn: '<S1>/Filtro'
   */
  Controle_principal_B.Sum3 = Controle_principal_P.Filtro_C *
    Controle_principal_X.Filtro_CSTATE + Controle_principal_P.Temp_inicial_Value;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/SetPoint'
   */
  Controle_principal_B.Sum1 = Controle_principal_P.SetPoint_Value -
    Controle_principal_B.Sum3;

  /* Gain: '<Root>/Control_P' */
  Controle_principal_B.Control_P = Controle_principal_P.Control_P_Gain *
    Controle_principal_B.Sum1;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/SetPoint'
   */
  Controle_principal_B.Sum2 = Controle_principal_P.SetPoint_Value -
    Controle_principal_B.Sum3;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Gain: '<Root>/I'
   *  Gain: '<Root>/Proporcional_PI'
   *  Integrator: '<Root>/Integrator'
   */
  Controle_principal_B.Sum3_a = Controle_principal_P.Proporcional_PI_Gain *
    Controle_principal_B.Sum2 + Controle_principal_P.I_Gain *
    Controle_principal_X.Integrator_CSTATE;

  /* Sum: '<Root>/Sum4' incorporates:
   *  Constant: '<Root>/SetPoint'
   */
  rtb_Sum4 = Controle_principal_P.SetPoint_Value - Controle_principal_B.Sum3;

  /* Gain: '<Root>/I2' */
  Controle_principal_B.I2 = Controle_principal_P.I2_Gain * rtb_Sum4;

  /* Derivative: '<Root>/Derivative' */
  if ((Controle_principal_DW.TimeStampA >= Controle_principal_M->Timing.t[0]) &&
      (Controle_principal_DW.TimeStampB >= Controle_principal_M->Timing.t[0])) {
    rtb_Derivative = 0.0;
  } else {
    rtb_Derivative = Controle_principal_DW.TimeStampA;
    lastU = &Controle_principal_DW.LastUAtTimeA;
    if (Controle_principal_DW.TimeStampA < Controle_principal_DW.TimeStampB) {
      if (Controle_principal_DW.TimeStampB < Controle_principal_M->Timing.t[0])
      {
        rtb_Derivative = Controle_principal_DW.TimeStampB;
        lastU = &Controle_principal_DW.LastUAtTimeB;
      }
    } else {
      if (Controle_principal_DW.TimeStampA >= Controle_principal_M->Timing.t[0])
      {
        rtb_Derivative = Controle_principal_DW.TimeStampB;
        lastU = &Controle_principal_DW.LastUAtTimeB;
      }
    }

    rtb_Derivative = (Controle_principal_B.I2 - *lastU) /
      (Controle_principal_M->Timing.t[0] - rtb_Derivative);
  }

  /* End of Derivative: '<Root>/Derivative' */

  /* Sum: '<Root>/Sum5' incorporates:
   *  Gain: '<Root>/Proporcional_PID'
   *  Integrator: '<Root>/Integrator_PID'
   */
  Controle_principal_B.Sum5 = (Controle_principal_P.Proporcional_PID_Gain *
    rtb_Sum4 + rtb_Derivative) + Controle_principal_X.Integrator_PID_CSTATE;

  /* Saturate: '<S2>/Saturação_p' */
  if (Controle_principal_B.Control_P > Controle_principal_P.Saturao_p_UpperSat)
  {
    Controle_principal_B.Saturao_p = Controle_principal_P.Saturao_p_UpperSat;
  } else if (Controle_principal_B.Control_P <
             Controle_principal_P.Saturao_p_LowerSat) {
    Controle_principal_B.Saturao_p = Controle_principal_P.Saturao_p_LowerSat;
  } else {
    Controle_principal_B.Saturao_p = Controle_principal_B.Control_P;
  }

  /* End of Saturate: '<S2>/Saturação_p' */

  /* TransferFcn: '<S2>/Transfer Fcn3' */
  Controle_principal_B.TransferFcn3 = 0.0;
  Controle_principal_B.TransferFcn3 += Controle_principal_P.TransferFcn3_C *
    Controle_principal_X.TransferFcn3_CSTATE;
  if (rtmIsMajorTimeStep(Controle_principal_M)) {
  }

  /* Saturate: '<S3>/Saturação_pi' */
  if (Controle_principal_B.Sum3_a > Controle_principal_P.Saturao_pi_UpperSat) {
    Controle_principal_B.Saturao_pi = Controle_principal_P.Saturao_pi_UpperSat;
  } else if (Controle_principal_B.Sum3_a <
             Controle_principal_P.Saturao_pi_LowerSat) {
    Controle_principal_B.Saturao_pi = Controle_principal_P.Saturao_pi_LowerSat;
  } else {
    Controle_principal_B.Saturao_pi = Controle_principal_B.Sum3_a;
  }

  /* End of Saturate: '<S3>/Saturação_pi' */

  /* TransferFcn: '<S3>/Transfer Fcn3' */
  Controle_principal_B.TransferFcn3_h = 0.0;
  Controle_principal_B.TransferFcn3_h += Controle_principal_P.TransferFcn3_C_a[0]
    * Controle_principal_X.TransferFcn3_CSTATE_i[0];
  Controle_principal_B.TransferFcn3_h += Controle_principal_P.TransferFcn3_C_a[1]
    * Controle_principal_X.TransferFcn3_CSTATE_i[1];
  if (rtmIsMajorTimeStep(Controle_principal_M)) {
  }

  /* Saturate: '<S4>/Saturação' */
  if (Controle_principal_B.Sum5 > Controle_principal_P.Saturao_UpperSat) {
    Controle_principal_B.Saturao = Controle_principal_P.Saturao_UpperSat;
  } else if (Controle_principal_B.Sum5 < Controle_principal_P.Saturao_LowerSat)
  {
    Controle_principal_B.Saturao = Controle_principal_P.Saturao_LowerSat;
  } else {
    Controle_principal_B.Saturao = Controle_principal_B.Sum5;
  }

  /* End of Saturate: '<S4>/Saturação' */

  /* TransferFcn: '<S4>/Transfer Fcn3' */
  Controle_principal_B.TransferFcn3_b = 0.0;
  Controle_principal_B.TransferFcn3_b += Controle_principal_P.TransferFcn3_C_e[0]
    * Controle_principal_X.TransferFcn3_CSTATE_p[0];
  Controle_principal_B.TransferFcn3_b += Controle_principal_P.TransferFcn3_C_e[1]
    * Controle_principal_X.TransferFcn3_CSTATE_p[1];
  if (rtmIsMajorTimeStep(Controle_principal_M)) {
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  if (Controle_principal_B.Saturao_p < 256.0) {
    if (Controle_principal_B.Saturao_p >= 0.0) {
      Controle_principal_B.DataTypeConversion = (uint8_T)
        Controle_principal_B.Saturao_p;
    } else {
      Controle_principal_B.DataTypeConversion = 0U;
    }
  } else {
    Controle_principal_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Controle_principal_M)) {
    /* S-Function (arduinoanalogoutput_sfcn): '<S5>/PWM' */
    MW_analogWrite(Controle_principal_P.PWM_pinNumber,
                   Controle_principal_B.DataTypeConversion);
  }

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  if (Controle_principal_B.Saturao_pi < 256.0) {
    if (Controle_principal_B.Saturao_pi >= 0.0) {
      Controle_principal_B.DataTypeConversion_d = (uint8_T)
        Controle_principal_B.Saturao_pi;
    } else {
      Controle_principal_B.DataTypeConversion_d = 0U;
    }
  } else {
    Controle_principal_B.DataTypeConversion_d = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Controle_principal_M)) {
    /* S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
    MW_analogWrite(Controle_principal_P.PWM_pinNumber_c,
                   Controle_principal_B.DataTypeConversion_d);
  }

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  if (Controle_principal_B.Saturao < 256.0) {
    if (Controle_principal_B.Saturao >= 0.0) {
      Controle_principal_B.DataTypeConversion_o = (uint8_T)
        Controle_principal_B.Saturao;
    } else {
      Controle_principal_B.DataTypeConversion_o = 0U;
    }
  } else {
    Controle_principal_B.DataTypeConversion_o = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(Controle_principal_M)) {
    /* S-Function (arduinoanalogoutput_sfcn): '<S7>/PWM' */
    MW_analogWrite(Controle_principal_P.PWM_pinNumber_e,
                   Controle_principal_B.DataTypeConversion_o);

    /* S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input1' */
    rtb_AnalogInput1_0 = MW_analogRead(Controle_principal_P.AnalogInput1_p1);

    /* Product: '<S1>/Temperatura' incorporates:
     *  Constant: '<S1>/Constant1'
     *  S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input1'
     */
    Controle_principal_B.Temperatura = (real_T)rtb_AnalogInput1_0 *
      Controle_principal_P.Constant1_Value;
  }

  /* Gain: '<Root>/I1' */
  Controle_principal_B.I1 = Controle_principal_P.I1_Gain * rtb_Sum4;
  if (rtmIsMajorTimeStep(Controle_principal_M)) {
    /* Sum: '<S1>/Sum2' incorporates:
     *  Constant: '<S1>/Temp_inicial'
     */
    Controle_principal_B.Sum2_h = Controle_principal_B.Temperatura -
      Controle_principal_P.Temp_inicial_Value;
  }
}

/* Model update function */
void Controle_principal_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/Derivative' */
  if (Controle_principal_DW.TimeStampA == (rtInf)) {
    Controle_principal_DW.TimeStampA = Controle_principal_M->Timing.t[0];
    lastU = &Controle_principal_DW.LastUAtTimeA;
  } else if (Controle_principal_DW.TimeStampB == (rtInf)) {
    Controle_principal_DW.TimeStampB = Controle_principal_M->Timing.t[0];
    lastU = &Controle_principal_DW.LastUAtTimeB;
  } else if (Controle_principal_DW.TimeStampA < Controle_principal_DW.TimeStampB)
  {
    Controle_principal_DW.TimeStampA = Controle_principal_M->Timing.t[0];
    lastU = &Controle_principal_DW.LastUAtTimeA;
  } else {
    Controle_principal_DW.TimeStampB = Controle_principal_M->Timing.t[0];
    lastU = &Controle_principal_DW.LastUAtTimeB;
  }

  *lastU = Controle_principal_B.I2;

  /* End of Update for Derivative: '<Root>/Derivative' */

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Controle_principal_M)!=-1) &&
        !((rtmGetTFinal(Controle_principal_M)-
           ((Controle_principal_M->Timing.clockTick1) * 0.1)) >
          ((Controle_principal_M->Timing.clockTick1) * 0.1) * (DBL_EPSILON))) {
      rtmSetErrorStatus(Controle_principal_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Controle_principal_M)) {
      rtmSetErrorStatus(Controle_principal_M, "Simulation finished");
    }
  }

  if (rtmIsMajorTimeStep(Controle_principal_M)) {
    rt_ertODEUpdateContinuousStates(&Controle_principal_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++Controle_principal_M->Timing.clockTick0;
  Controle_principal_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Controle_principal_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Controle_principal_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void Controle_principal_derivatives(void)
{
  XDot_Controle_principal_T *_rtXdot;
  _rtXdot = ((XDot_Controle_principal_T *)
             Controle_principal_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S1>/Filtro' */
  _rtXdot->Filtro_CSTATE = 0.0;
  _rtXdot->Filtro_CSTATE += Controle_principal_P.Filtro_A *
    Controle_principal_X.Filtro_CSTATE;
  _rtXdot->Filtro_CSTATE += Controle_principal_B.Sum2_h;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Controle_principal_B.Sum2;

  /* Derivatives for Integrator: '<Root>/Integrator_PID' */
  _rtXdot->Integrator_PID_CSTATE = Controle_principal_B.I1;

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE = 0.0;
  _rtXdot->TransferFcn3_CSTATE += Controle_principal_P.TransferFcn3_A *
    Controle_principal_X.TransferFcn3_CSTATE;
  _rtXdot->TransferFcn3_CSTATE += Controle_principal_B.Saturao_p;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE_i[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE_i[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE_i[0] += Controle_principal_P.TransferFcn3_A_k[0] *
    Controle_principal_X.TransferFcn3_CSTATE_i[0];
  _rtXdot->TransferFcn3_CSTATE_i[0] += Controle_principal_P.TransferFcn3_A_k[1] *
    Controle_principal_X.TransferFcn3_CSTATE_i[1];
  _rtXdot->TransferFcn3_CSTATE_i[1] +=
    Controle_principal_X.TransferFcn3_CSTATE_i[0];
  _rtXdot->TransferFcn3_CSTATE_i[0] += Controle_principal_B.Saturao_pi;

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE_p[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE_p[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE_p[0] += Controle_principal_P.TransferFcn3_A_p[0] *
    Controle_principal_X.TransferFcn3_CSTATE_p[0];
  _rtXdot->TransferFcn3_CSTATE_p[0] += Controle_principal_P.TransferFcn3_A_p[1] *
    Controle_principal_X.TransferFcn3_CSTATE_p[1];
  _rtXdot->TransferFcn3_CSTATE_p[1] +=
    Controle_principal_X.TransferFcn3_CSTATE_p[0];
  _rtXdot->TransferFcn3_CSTATE_p[0] += Controle_principal_B.Saturao;
}

/* Model initialize function */
void Controle_principal_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Controle_principal_M, 0,
                sizeof(RT_MODEL_Controle_principal_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Controle_principal_M->solverInfo,
                          &Controle_principal_M->Timing.simTimeStep);
    rtsiSetTPtr(&Controle_principal_M->solverInfo, &rtmGetTPtr
                (Controle_principal_M));
    rtsiSetStepSizePtr(&Controle_principal_M->solverInfo,
                       &Controle_principal_M->Timing.stepSize0);
    rtsiSetdXPtr(&Controle_principal_M->solverInfo,
                 &Controle_principal_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Controle_principal_M->solverInfo, (real_T **)
                         &Controle_principal_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Controle_principal_M->solverInfo,
      &Controle_principal_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Controle_principal_M->solverInfo, (&rtmGetErrorStatus
      (Controle_principal_M)));
    rtsiSetRTModelPtr(&Controle_principal_M->solverInfo, Controle_principal_M);
  }

  rtsiSetSimTimeStep(&Controle_principal_M->solverInfo, MAJOR_TIME_STEP);
  Controle_principal_M->ModelData.intgData.y =
    Controle_principal_M->ModelData.odeY;
  Controle_principal_M->ModelData.intgData.f[0] =
    Controle_principal_M->ModelData.odeF[0];
  Controle_principal_M->ModelData.intgData.f[1] =
    Controle_principal_M->ModelData.odeF[1];
  Controle_principal_M->ModelData.intgData.f[2] =
    Controle_principal_M->ModelData.odeF[2];
  Controle_principal_M->ModelData.contStates = ((X_Controle_principal_T *)
    &Controle_principal_X);
  rtsiSetSolverData(&Controle_principal_M->solverInfo, (void *)
                    &Controle_principal_M->ModelData.intgData);
  rtsiSetSolverName(&Controle_principal_M->solverInfo,"ode3");
  rtmSetTPtr(Controle_principal_M, &Controle_principal_M->Timing.tArray[0]);
  rtmSetTFinal(Controle_principal_M, -1);
  Controle_principal_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Controle_principal_M->Sizes.checksums[0] = (3438675254U);
  Controle_principal_M->Sizes.checksums[1] = (3938842484U);
  Controle_principal_M->Sizes.checksums[2] = (2772615847U);
  Controle_principal_M->Sizes.checksums[3] = (2026578320U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Controle_principal_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Controle_principal_M->extModeInfo,
      &Controle_principal_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Controle_principal_M->extModeInfo,
                        Controle_principal_M->Sizes.checksums);
    rteiSetTPtr(Controle_principal_M->extModeInfo, rtmGetTPtr
                (Controle_principal_M));
  }

  /* block I/O */
  (void) memset(((void *) &Controle_principal_B), 0,
                sizeof(B_Controle_principal_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Controle_principal_X, 0,
                  sizeof(X_Controle_principal_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Controle_principal_DW, 0,
                sizeof(DW_Controle_principal_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Controle_principal_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S5>/PWM' */
  MW_pinModeOutput(Controle_principal_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
  MW_pinModeOutput(Controle_principal_P.PWM_pinNumber_c);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S7>/PWM' */
  MW_pinModeOutput(Controle_principal_P.PWM_pinNumber_e);

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input1' */
  MW_pinModeAnalogInput(Controle_principal_P.AnalogInput1_p1);

  /* InitializeConditions for TransferFcn: '<S1>/Filtro' */
  Controle_principal_X.Filtro_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Controle_principal_X.Integrator_CSTATE = Controle_principal_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  Controle_principal_DW.TimeStampA = (rtInf);
  Controle_principal_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<Root>/Integrator_PID' */
  Controle_principal_X.Integrator_PID_CSTATE =
    Controle_principal_P.Integrator_PID_IC;

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn3' */
  Controle_principal_X.TransferFcn3_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn3' */
  Controle_principal_X.TransferFcn3_CSTATE_i[0] = 0.0;
  Controle_principal_X.TransferFcn3_CSTATE_i[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn3' */
  Controle_principal_X.TransferFcn3_CSTATE_p[0] = 0.0;
  Controle_principal_X.TransferFcn3_CSTATE_p[1] = 0.0;
}

/* Model terminate function */
void Controle_principal_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
