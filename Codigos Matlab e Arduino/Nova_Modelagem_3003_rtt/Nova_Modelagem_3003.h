/*
 * File: Nova_Modelagem_3003.h
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

#ifndef RTW_HEADER_Nova_Modelagem_3003_h_
#define RTW_HEADER_Nova_Modelagem_3003_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Nova_Modelagem_3003_COMMON_INCLUDES_
# define Nova_Modelagem_3003_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_analogoutput_lct.h"
#include "arduino_analoginput_lct.h"
#endif                                 /* Nova_Modelagem_3003_COMMON_INCLUDES_ */

#include "Nova_Modelagem_3003_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Sum3;                         /* '<S1>/Sum3' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Control_P;                    /* '<Root>/Control_P' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Sum3_a;                       /* '<Root>/Sum3' */
  real_T I2;                           /* '<Root>/I2' */
  real_T Sum5;                         /* '<Root>/Sum5' */
  real_T Saturao_p;                    /* '<S2>/Saturação_p' */
  real_T TransferFcn3;                 /* '<S2>/Transfer Fcn3' */
  real_T Saturao_pi;                   /* '<S3>/Saturação_pi' */
  real_T TransferFcn3_h;               /* '<S3>/Transfer Fcn3' */
  real_T Saturao;                      /* '<S4>/Saturação' */
  real_T TransferFcn3_b;               /* '<S4>/Transfer Fcn3' */
  real_T Temperatura;                  /* '<S1>/Temperatura' */
  real_T I1;                           /* '<Root>/I1' */
  real_T Sum2_h;                       /* '<S1>/Sum2' */
  uint8_T DataTypeConversion;          /* '<S5>/Data Type Conversion' */
  uint8_T DataTypeConversion_d;        /* '<S6>/Data Type Conversion' */
  uint8_T DataTypeConversion_o;        /* '<S7>/Data Type Conversion' */
} B_Nova_Modelagem_3003_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  struct {
    void *LoggedData;
  } GrficoControlePTemperaturaPWM_P;   /* '<Root>/Gráfico Controle P //Temperatura//PWM' */

  struct {
    void *LoggedData;
  } GrficoControlePITemperaturaPWM_;   /* '<Root>/Gráfico Controle PI //Temperatura//PWM' */

  struct {
    void *LoggedData;
  } GrficoControlePIDTemperaturaPWM;   /* '<Root>/Gráfico Controle PID //Temperatura//PWM' */

  struct {
    void *LoggedData;
  } TemperaturasemFiltroTemperatura;   /* '<Root>/Temperatura sem Filtro //Temperatura  Filtrada' */
} DW_Nova_Modelagem_3003_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Filtro_CSTATE;                /* '<S1>/Filtro' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator_PID_CSTATE;        /* '<Root>/Integrator_PID' */
  real_T TransferFcn3_CSTATE;          /* '<S2>/Transfer Fcn3' */
  real_T TransferFcn3_CSTATE_i[2];     /* '<S3>/Transfer Fcn3' */
  real_T TransferFcn3_CSTATE_p[2];     /* '<S4>/Transfer Fcn3' */
} X_Nova_Modelagem_3003_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Filtro_CSTATE;                /* '<S1>/Filtro' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator_PID_CSTATE;        /* '<Root>/Integrator_PID' */
  real_T TransferFcn3_CSTATE;          /* '<S2>/Transfer Fcn3' */
  real_T TransferFcn3_CSTATE_i[2];     /* '<S3>/Transfer Fcn3' */
  real_T TransferFcn3_CSTATE_p[2];     /* '<S4>/Transfer Fcn3' */
} XDot_Nova_Modelagem_3003_T;

/* State disabled  */
typedef struct {
  boolean_T Filtro_CSTATE;             /* '<S1>/Filtro' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator_PID_CSTATE;     /* '<Root>/Integrator_PID' */
  boolean_T TransferFcn3_CSTATE;       /* '<S2>/Transfer Fcn3' */
  boolean_T TransferFcn3_CSTATE_i[2];  /* '<S3>/Transfer Fcn3' */
  boolean_T TransferFcn3_CSTATE_p[2];  /* '<S4>/Transfer Fcn3' */
} XDis_Nova_Modelagem_3003_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_Nova_Modelagem_3003_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S5>/PWM'
                                        */
  uint32_T PWM_pinNumber_c;            /* Mask Parameter: PWM_pinNumber_c
                                        * Referenced by: '<S6>/PWM'
                                        */
  uint32_T PWM_pinNumber_e;            /* Mask Parameter: PWM_pinNumber_e
                                        * Referenced by: '<S7>/PWM'
                                        */
  real_T SetPoint_Value;               /* Expression: 42
                                        * Referenced by: '<Root>/SetPoint'
                                        */
  real_T Filtro_A;                     /* Computed Parameter: Filtro_A
                                        * Referenced by: '<S1>/Filtro'
                                        */
  real_T Filtro_C;                     /* Computed Parameter: Filtro_C
                                        * Referenced by: '<S1>/Filtro'
                                        */
  real_T Temp_inicial_Value;           /* Expression: 29.50
                                        * Referenced by: '<S1>/Temp_inicial'
                                        */
  real_T Control_P_Gain;               /* Expression: -195
                                        * Referenced by: '<Root>/Control_P'
                                        */
  real_T Proporcional_PI_Gain;         /* Expression: -195
                                        * Referenced by: '<Root>/Proporcional_PI'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T I_Gain;                       /* Expression: 0.16
                                        * Referenced by: '<Root>/I'
                                        */
  real_T I2_Gain;                      /* Expression: 12.5
                                        * Referenced by: '<Root>/I2'
                                        */
  real_T Proporcional_PID_Gain;        /* Expression: -195
                                        * Referenced by: '<Root>/Proporcional_PID'
                                        */
  real_T Integrator_PID_IC;            /* Expression: 0
                                        * Referenced by: '<Root>/Integrator_PID'
                                        */
  real_T Saturao_p_UpperSat;           /* Expression: 255
                                        * Referenced by: '<S2>/Saturação_p'
                                        */
  real_T Saturao_p_LowerSat;           /* Expression: 20
                                        * Referenced by: '<S2>/Saturação_p'
                                        */
  real_T TransferFcn3_A;               /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<S2>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C;               /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<S2>/Transfer Fcn3'
                                        */
  real_T Saturao_pi_UpperSat;          /* Expression: 255
                                        * Referenced by: '<S3>/Saturação_pi'
                                        */
  real_T Saturao_pi_LowerSat;          /* Expression: 20
                                        * Referenced by: '<S3>/Saturação_pi'
                                        */
  real_T TransferFcn3_A_k[2];          /* Computed Parameter: TransferFcn3_A_k
                                        * Referenced by: '<S3>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C_a[2];          /* Computed Parameter: TransferFcn3_C_a
                                        * Referenced by: '<S3>/Transfer Fcn3'
                                        */
  real_T Saturao_UpperSat;             /* Expression: 255
                                        * Referenced by: '<S4>/Saturação'
                                        */
  real_T Saturao_LowerSat;             /* Expression: 20
                                        * Referenced by: '<S4>/Saturação'
                                        */
  real_T TransferFcn3_A_p[2];          /* Computed Parameter: TransferFcn3_A_p
                                        * Referenced by: '<S4>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C_e[2];          /* Computed Parameter: TransferFcn3_C_e
                                        * Referenced by: '<S4>/Transfer Fcn3'
                                        */
  real_T Constant1_Value;              /* Expression: (5/1023)/0.01
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T I1_Gain;                      /* Expression: 1/48.15
                                        * Referenced by: '<Root>/I1'
                                        */
  uint32_T AnalogInput1_p1;            /* Computed Parameter: AnalogInput1_p1
                                        * Referenced by: '<S1>/Analog Input1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Nova_Modelagem_3003_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_Nova_Modelagem_3003_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[8];
    real_T odeF[3][8];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Nova_Modelagem_3003_T Nova_Modelagem_3003_P;

/* Block signals (auto storage) */
extern B_Nova_Modelagem_3003_T Nova_Modelagem_3003_B;

/* Continuous states (auto storage) */
extern X_Nova_Modelagem_3003_T Nova_Modelagem_3003_X;

/* Block states (auto storage) */
extern DW_Nova_Modelagem_3003_T Nova_Modelagem_3003_DW;

/* Model entry point functions */
extern void Nova_Modelagem_3003_initialize(void);
extern void Nova_Modelagem_3003_output(void);
extern void Nova_Modelagem_3003_update(void);
extern void Nova_Modelagem_3003_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Nova_Modelagem_3003_T *const Nova_Modelagem_3003_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Nova_Modelagem_3003'
 * '<S1>'   : 'Nova_Modelagem_3003/Medida'
 * '<S2>'   : 'Nova_Modelagem_3003/P '
 * '<S3>'   : 'Nova_Modelagem_3003/PI '
 * '<S4>'   : 'Nova_Modelagem_3003/PID'
 * '<S5>'   : 'Nova_Modelagem_3003/PWM1'
 * '<S6>'   : 'Nova_Modelagem_3003/PWM2'
 * '<S7>'   : 'Nova_Modelagem_3003/PWM3'
 */
#endif                                 /* RTW_HEADER_Nova_Modelagem_3003_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
