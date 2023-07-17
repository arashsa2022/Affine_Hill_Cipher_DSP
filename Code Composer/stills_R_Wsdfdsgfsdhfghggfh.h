/*
 * File: stills_R_Wsdfdsgfsdhfghggfh.h
 *
 * Real-Time Workshop code generated for Simulink model stills_R_Wsdfdsgfsdhfghggfh.
 *
 * Model version                        : 1.23
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Wed Aug 10 05:32:20 2016
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Wed Aug 10 05:32:21 2016
 */

#ifndef RTW_HEADER_stills_R_Wsdfdsgfsdhfghggfh_h_
#define RTW_HEADER_stills_R_Wsdfdsgfsdhfghggfh_h_
#ifndef stills_R_Wsdfdsgfsdhfghggfh_COMMON_INCLUDES_
# define stills_R_Wsdfdsgfsdhfghggfh_COMMON_INCLUDES_
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* stills_R_Wsdfdsgfsdhfghggfh_COMMON_INCLUDES_ */

#include "stills_R_Wsdfdsgfsdhfghggfh_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#ifndef INT40_T
#define INT40_T                        signed long

typedef INT40_T int40_T;

#endif

#ifndef CINT40_T

typedef struct {
  int40_T re, im;
} cint40_T;

#define CINT40_T                       cint40_T
#endif

#ifndef UINT40_T
#define UINT40_T                       unsigned long

typedef UINT40_T uint40_T;

#endif

#ifndef CUINT40_T

typedef struct {
  int40_T re, im;
} cuint40_T;

#define CUINT40_T                      cuint40_T
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Sum2[103];                    /* '<S2>/Sum2' */
  real_T TmpHiddenBufferAtImageDataTypeC[207];/* '<Root>/Subsystem' */
  real_T Product3[103];                /* '<S2>/Product3' */
  uint8_T FromRTDX[20085];             /* '<Root>/From RTDX' */
  char pad_FromRTDX[3];
  uint8_T Submatrix[309];              /* '<S2>/Submatrix' */
  char pad_Submatrix[3];
  uint8_T Submatrix1[309];             /* '<S2>/Submatrix1' */
  char pad_Submatrix1[3];
  uint8_T ImageDataTypeConversion[207];/* '<Root>/Image Data Type Conversion' */
  char pad_ImageDataTypeConversion;
} BlockIO_stills_R_Wsdfdsgfsdhfgh;

/* Parameters (auto storage) */
struct Parameters_stills_R_Wsdfdsgfsdh {
  real_T Constant5_Value;              /* Expression: 2
                                        * '<Root>/Constant5'
                                        */
  real_T Constant_Value;               /* Expression: 3
                                        * '<S2>/Constant'
                                        */
  real_T Bias_Bias;                    /* Expression: 1
                                        * '<S2>/Bias'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * '<S2>/Constant1'
                                        */
  real_T Bias1_Bias;                   /* Expression: 1
                                        * '<S2>/Bias1'
                                        */
  real_T Constant2_Value;              /* Expression: 2
                                        * '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 2
                                        * '<Root>/Constant3'
                                        */
  real_T Constant2_Value_f;            /* Expression: 10
                                        * '<S2>/Constant2'
                                        */
  real_T Constant4_Value;              /* Expression: 2
                                        * '<Root>/Constant4'
                                        */
  real_T Constant3_Value_g;            /* Expression: 113
                                        * '<S2>/Constant3'
                                        */
  real_T Constant4_Value_n;            /* Expression: 3
                                        * '<S2>/Constant4'
                                        */
  real_T Bias2_Bias;                   /* Expression: 1
                                        * '<S2>/Bias2'
                                        */
  real_T Constant5_Value_m;            /* Expression: 2
                                        * '<S2>/Constant5'
                                        */
  real_T Bias3_Bias;                   /* Expression: 1
                                        * '<S2>/Bias3'
                                        */
  uint8_T FromRTDX_IC;                 /* Computed Parameter: IC
                                        * '<Root>/From RTDX'
                                        */
  char pad_FromRTDX_IC[7];
};

/* Real-time Model Data Structure */
struct RT_MODEL_stills_R_Wsdfdsgfsdhfg {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_stills_R_Wsdfdsgfsdh stills_R_Wsdfdsgfsdhfghggfh_P;

/* Block signals (auto storage) */
extern BlockIO_stills_R_Wsdfdsgfsdhfgh stills_R_Wsdfdsgfsdhfghggfh_B;

/* Model entry point functions */
extern void stills_R_Wsdfdsgfsdhfghggfh_initialize(boolean_T firstTime);
extern void stills_R_Wsdfdsgfsdhfghggfh_step(void);
extern void stills_R_Wsdfdsgfsdhfghggfh_terminate(void);

/* Real-time Model object */
extern RT_MODEL_stills_R_Wsdfdsgfsdhfg *stills_R_Wsdfdsgfsdhfghggfh_M;

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
 * '<Root>' : stills_R_Wsdfdsgfsdhfghggfh
 * '<S1>'   : stills_R_Wsdfdsgfsdhfghggfh/C6416DSK
 * '<S2>'   : stills_R_Wsdfdsgfsdhfghggfh/Subsystem
 */
#endif                                 /* RTW_HEADER_stills_R_Wsdfdsgfsdhfghggfh_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
