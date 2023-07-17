/*
 * File: stills_R_Wsdfdsgfsdhfghggfh.c
 *
 * Real-Time Workshop code generated for Simulink model stills_R_Wsdfdsgfsdhfghggfh.
 *
 * Model version                        : 1.23
 * Real-Time Workshop file version      : 7.0  (R2007b)  02-Aug-2007
 * Real-Time Workshop file generated on : Wed Aug 10 05:32:20 2016
 * TLC version                          : 7.0 (Jul 26 2007)
 * C source code generated on           : Wed Aug 10 05:32:21 2016
 */

#include "stills_R_Wsdfdsgfsdhfghggfh.h"
#include "stills_R_Wsdfdsgfsdhfghggfh_private.h"

RTDX_CreateInputChannel(inputimage);   /* Channel inputimage for block <Root>/From RTDX */
RTDX_CreateOutputChannel(outputimage); /* Channel outputimage for block <Root>/To RTDX */

/* Block signals (auto storage) */
#pragma DATA_ALIGN(stills_R_Wsdfdsgfsdhfghggfh_B, 8)

BlockIO_stills_R_Wsdfdsgfsdhfgh stills_R_Wsdfdsgfsdhfghggfh_B;

/* Real-time model */
RT_MODEL_stills_R_Wsdfdsgfsdhfg stills_R_Wsdfdsgfsdhfghggfh_M_;
RT_MODEL_stills_R_Wsdfdsgfsdhfg *stills_R_Wsdfdsgfsdhfghggfh_M =
  &stills_R_Wsdfdsgfsdhfghggfh_M_;

/* Model step function */
void stills_R_Wsdfdsgfsdhfghggfh_step(void)
{
  /* local block i/o variables */
  real_T rtb_Sum1[103];
  real_T rtb_MathFunction6[103];
  real_T rtb_MathFunction5;
  uint8_T rtb_IndexVector1[103];

  {
    real_T uDiv;
    real_T uDivRound;
    int32_T yIdx;
    int32_T colIdx;
    real_T uDiv_0[103];
    real_T uDivRound_0[103];
    real_T uDiv_1[103];
    real_T uDivRound_1[103];

    /* Math: '<S2>/Math Function' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Constant: '<S2>/Constant'
     */
    if (stills_R_Wsdfdsgfsdhfghggfh_P.Constant_Value == 0.0) {
      rtb_MathFunction5 = stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value;
    } else if (stills_R_Wsdfdsgfsdhfghggfh_P.Constant_Value <= floor
               (stills_R_Wsdfdsgfsdhfghggfh_P.Constant_Value)) {
      rtb_MathFunction5 = stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value - floor
        (stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value /
         stills_R_Wsdfdsgfsdhfghggfh_P.Constant_Value) *
        stills_R_Wsdfdsgfsdhfghggfh_P.Constant_Value;
    } else {
      uDiv = stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value /
        stills_R_Wsdfdsgfsdhfghggfh_P.Constant_Value;
      uDivRound = floor(fabs(uDiv) + 0.5);
      if (uDiv < 0.0) {
        uDivRound = -uDivRound;
      }

      if (fabs(uDiv - uDivRound) <= DBL_EPSILON * fabs(uDiv)) {
        rtb_MathFunction5 = 0.0;
      } else {
        rtb_MathFunction5 = (uDiv - floor(uDiv)) *
          stills_R_Wsdfdsgfsdhfghggfh_P.Constant_Value;
      }
    }

    /* Bias: '<S2>/Bias' */
    uDiv = rtb_MathFunction5 + stills_R_Wsdfdsgfsdhfghggfh_P.Bias_Bias;

    /* S-Function Block: <Root>/From RTDX (rtdx_src) */
    RTDX_read( &inputimage, (void*) stills_R_Wsdfdsgfsdhfghggfh_B.FromRTDX,
              20085*sizeof(uint8_T));

    /* S-Function (sdspsubmtrx): '<S2>/Submatrix' */
    yIdx = 0;
    for (colIdx = 0; colIdx < 309; colIdx++) {
      stills_R_Wsdfdsgfsdhfghggfh_B.Submatrix[yIdx] =
        stills_R_Wsdfdsgfsdhfghggfh_B.FromRTDX[colIdx * 65 + 1];
      yIdx++;
    }

    /* MultiPortSwitch: '<S2>/Index Vector' */
    switch ((int32_T)uDiv) {
     case 1:
      for (yIdx = 0; yIdx < 103; yIdx++) {
        rtb_IndexVector1[yIdx] = stills_R_Wsdfdsgfsdhfghggfh_B.Submatrix[yIdx];
      }
      break;

     case 2:
      for (yIdx = 0; yIdx < 103; yIdx++) {
        rtb_IndexVector1[yIdx] = stills_R_Wsdfdsgfsdhfghggfh_B.Submatrix[yIdx +
          103];
      }
      break;

     default:
      for (yIdx = 0; yIdx < 103; yIdx++) {
        rtb_IndexVector1[yIdx] = stills_R_Wsdfdsgfsdhfghggfh_B.Submatrix[yIdx +
          206];
      }
      break;
    }

    /* Rounding: '<S2>/Rounding Function1' incorporates:
     *  Bias: '<S2>/Bias1'
     *  Constant: '<Root>/Constant5'
     *  Fcn: '<S2>/Fcn'
     *  Rounding: '<S2>/Rounding Function'
     */
    rtb_MathFunction5 = ceil(floor(log
      (stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value)) +
      stills_R_Wsdfdsgfsdhfghggfh_P.Bias1_Bias);

    /* Math: '<S2>/Math Function1' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    if ((stills_R_Wsdfdsgfsdhfghggfh_P.Constant1_Value < 0.0) &&
        (rtb_MathFunction5 > floor(rtb_MathFunction5))) {
      rtb_MathFunction5 = -pow(-stills_R_Wsdfdsgfsdhfghggfh_P.Constant1_Value,
        rtb_MathFunction5);
    } else {
      rtb_MathFunction5 = pow(stills_R_Wsdfdsgfsdhfghggfh_P.Constant1_Value,
        rtb_MathFunction5);
    }

    /* Math: '<S2>/Math Function2' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    if (rtb_MathFunction5 == 0.0) {
      uDivRound = stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value;
    } else if (rtb_MathFunction5 <= floor(rtb_MathFunction5)) {
      uDivRound = stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value - floor
        (stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value / rtb_MathFunction5) *
        rtb_MathFunction5;
    } else {
      uDiv = stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value / rtb_MathFunction5;
      uDivRound = floor(fabs(uDiv) + 0.5);
      if (uDiv < 0.0) {
        uDivRound = -uDivRound;
      }

      if (fabs(uDiv - uDivRound) <= DBL_EPSILON * fabs(uDiv)) {
        uDivRound = 0.0;
      } else {
        uDivRound = (uDiv - floor(uDiv)) * rtb_MathFunction5;
      }
    }

    /* Sum: '<S2>/Add' */
    rtb_MathFunction5 += uDivRound;

    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Constant: '<Root>/Constant3'
     *  Constant: '<Root>/Constant4'
     *  Constant: '<S2>/Constant2'
     *  Product: '<S2>/Product1'
     */
    uDivRound = stills_R_Wsdfdsgfsdhfghggfh_P.Constant2_Value *
      stills_R_Wsdfdsgfsdhfghggfh_P.Constant3_Value *
      stills_R_Wsdfdsgfsdhfghggfh_P.Constant2_Value_f +
      stills_R_Wsdfdsgfsdhfghggfh_P.Constant4_Value;

    /* Math: '<S2>/Math Function3' incorporates:
     *  Constant: '<S2>/Constant3'
     */
    if (!(stills_R_Wsdfdsgfsdhfghggfh_P.Constant3_Value_g == 0.0)) {
      if (stills_R_Wsdfdsgfsdhfghggfh_P.Constant3_Value_g <= floor
          (stills_R_Wsdfdsgfsdhfghggfh_P.Constant3_Value_g)) {
        uDivRound -= floor(uDivRound /
                           stills_R_Wsdfdsgfsdhfghggfh_P.Constant3_Value_g) *
          stills_R_Wsdfdsgfsdhfghggfh_P.Constant3_Value_g;
      } else {
        uDiv = uDivRound / stills_R_Wsdfdsgfsdhfghggfh_P.Constant3_Value_g;
        uDivRound = floor(fabs(uDiv) + 0.5);
        if (uDiv < 0.0) {
          uDivRound = -uDivRound;
        }

        if (fabs(uDiv - uDivRound) <= DBL_EPSILON * fabs(uDiv)) {
          uDivRound = 0.0;
        } else {
          uDivRound = (uDiv - floor(uDiv)) *
            stills_R_Wsdfdsgfsdhfghggfh_P.Constant3_Value_g;
        }
      }
    }

    /* Product: '<S2>/Product' */
    uDiv = rtb_MathFunction5 * uDivRound;
    for (yIdx = 0; yIdx < 103; yIdx++) {
      /* Sum: '<S2>/Sum1' */
      rtb_Sum1[yIdx] = (real_T)rtb_IndexVector1[yIdx] + uDiv;
    }

    /* Math: '<S2>/Math Function4' incorporates:
     *  Constant: '<S2>/Constant4'
     */
    if (stills_R_Wsdfdsgfsdhfghggfh_P.Constant4_Value_n == 0.0) {
      for (yIdx = 0; yIdx < 103; yIdx++) {
        rtb_MathFunction6[yIdx] = rtb_Sum1[yIdx];
      }
    } else if (stills_R_Wsdfdsgfsdhfghggfh_P.Constant4_Value_n <= floor
               (stills_R_Wsdfdsgfsdhfghggfh_P.Constant4_Value_n)) {
      for (yIdx = 0; yIdx < 103; yIdx++) {
        rtb_MathFunction6[yIdx] = rtb_Sum1[yIdx] - floor(rtb_Sum1[yIdx] /
          stills_R_Wsdfdsgfsdhfghggfh_P.Constant4_Value_n) *
          stills_R_Wsdfdsgfsdhfghggfh_P.Constant4_Value_n;
      }
    } else {
      for (yIdx = 0; yIdx < 103; yIdx++) {
        uDiv_0[yIdx] = rtb_Sum1[yIdx] /
          stills_R_Wsdfdsgfsdhfghggfh_P.Constant4_Value_n;
        uDivRound_0[yIdx] = floor(fabs(uDiv_0[yIdx]) + 0.5);
        if (uDiv_0[yIdx] < 0.0) {
          uDivRound_0[yIdx] = -uDivRound_0[yIdx];
        }

        if (fabs(uDiv_0[yIdx] - uDivRound_0[yIdx]) <= DBL_EPSILON * fabs
            (uDiv_0[yIdx])) {
          rtb_MathFunction6[yIdx] = 0.0;
        } else {
          rtb_MathFunction6[yIdx] = (uDiv_0[yIdx] - floor(uDiv_0[yIdx])) *
            stills_R_Wsdfdsgfsdhfghggfh_P.Constant4_Value_n;
        }
      }
    }

    /* S-Function (sdspsubmtrx): '<S2>/Submatrix1' */
    yIdx = 0;
    for (colIdx = 0; colIdx < 309; colIdx++) {
      stills_R_Wsdfdsgfsdhfghggfh_B.Submatrix1[yIdx] =
        stills_R_Wsdfdsgfsdhfghggfh_B.FromRTDX[colIdx * 65 + 1];
      yIdx++;
    }

    for (yIdx = 0; yIdx < 103; yIdx++) {
      /* MultiPortSwitch: '<S2>/Index Vector1' incorporates:
       *  Bias: '<S2>/Bias2'
       */
      switch ((int32_T)(rtb_MathFunction6[yIdx] +
                        stills_R_Wsdfdsgfsdhfghggfh_P.Bias2_Bias)) {
       case 1:
        rtb_IndexVector1[yIdx] = stills_R_Wsdfdsgfsdhfghggfh_B.Submatrix1[yIdx];
        break;

       case 2:
        rtb_IndexVector1[yIdx] = stills_R_Wsdfdsgfsdhfghggfh_B.Submatrix1[103 +
          yIdx];
        break;

       default:
        rtb_IndexVector1[yIdx] = stills_R_Wsdfdsgfsdhfghggfh_B.Submatrix1[206 +
          yIdx];
        break;
      }
    }

    /* Rounding: '<S2>/Rounding Function3' incorporates:
     *  Bias: '<S2>/Bias3'
     *  Fcn: '<S2>/Fcn1'
     *  Rounding: '<S2>/Rounding Function2'
     */
    rtb_MathFunction5 = ceil(floor(log(rtb_Sum1[0])) +
      stills_R_Wsdfdsgfsdhfghggfh_P.Bias3_Bias);

    /* Math: '<S2>/Math Function5' incorporates:
     *  Constant: '<S2>/Constant5'
     */
    if ((stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value_m < 0.0) &&
        (rtb_MathFunction5 > floor(rtb_MathFunction5))) {
      rtb_MathFunction5 = -pow(-stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value_m,
        rtb_MathFunction5);
    } else {
      rtb_MathFunction5 = pow(stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value_m,
        rtb_MathFunction5);
    }

    /* Math: '<S2>/Math Function6' */
    if (rtb_MathFunction5 == 0.0) {
      for (yIdx = 0; yIdx < 103; yIdx++) {
        rtb_MathFunction6[yIdx] = rtb_Sum1[yIdx];
      }
    } else if (rtb_MathFunction5 <= floor(rtb_MathFunction5)) {
      for (yIdx = 0; yIdx < 103; yIdx++) {
        rtb_MathFunction6[yIdx] = rtb_Sum1[yIdx] - floor(rtb_Sum1[yIdx] /
          rtb_MathFunction5) * rtb_MathFunction5;
      }
    } else {
      for (yIdx = 0; yIdx < 103; yIdx++) {
        uDiv_1[yIdx] = rtb_Sum1[yIdx] / rtb_MathFunction5;
        uDivRound_1[yIdx] = floor(fabs(uDiv_1[yIdx]) + 0.5);
        if (uDiv_1[yIdx] < 0.0) {
          uDivRound_1[yIdx] = -uDivRound_1[yIdx];
        }

        if (fabs(uDiv_1[yIdx] - uDivRound_1[yIdx]) <= DBL_EPSILON * fabs
            (uDiv_1[yIdx])) {
          rtb_MathFunction6[yIdx] = 0.0;
        } else {
          rtb_MathFunction6[yIdx] = (uDiv_1[yIdx] - floor(uDiv_1[yIdx])) *
            rtb_MathFunction5;
        }
      }
    }

    /* SignalConversion: '<Root>/TmpHiddenBufferAtImage Data Type ConversionInport1' incorporates:
     *  Constant: '<Root>/Constant5'
     *  Sum: '<S2>/Add1'
     */
    stills_R_Wsdfdsgfsdhfghggfh_B.TmpHiddenBufferAtImageDataTypeC[0] =
      stills_R_Wsdfdsgfsdhfghggfh_P.Constant5_Value;
    for (yIdx = 0; yIdx < 103; yIdx++) {
      /* Sum: '<S2>/Add1' */
      stills_R_Wsdfdsgfsdhfghggfh_B.Product3[yIdx] = rtb_MathFunction5 +
        rtb_MathFunction6[yIdx];

      /* Product: '<S2>/Product3' */
      stills_R_Wsdfdsgfsdhfghggfh_B.Product3[yIdx] =
        stills_R_Wsdfdsgfsdhfghggfh_B.Product3[yIdx] * uDivRound;

      /* Sum: '<S2>/Sum2' */
      stills_R_Wsdfdsgfsdhfghggfh_B.Sum2[yIdx] = (real_T)rtb_IndexVector1[yIdx]
        + stills_R_Wsdfdsgfsdhfghggfh_B.Product3[yIdx];
      stills_R_Wsdfdsgfsdhfghggfh_B.TmpHiddenBufferAtImageDataTypeC[yIdx + 1] =
        rtb_Sum1[yIdx];
    }

    for (yIdx = 0; yIdx < 103; yIdx++) {
      stills_R_Wsdfdsgfsdhfghggfh_B.TmpHiddenBufferAtImageDataTypeC[yIdx + 104] =
        stills_R_Wsdfdsgfsdhfghggfh_B.Sum2[yIdx];
    }

    for (yIdx = 0; yIdx < 207; yIdx++) {
      /* S-Function (svipscalenconvert): '<Root>/Image Data Type Conversion' */
      uDiv = stills_R_Wsdfdsgfsdhfghggfh_B.TmpHiddenBufferAtImageDataTypeC[yIdx]
        * 255.0 + 0.5;
      if (uDiv > 255.0) {
        uDiv = 255.0;
      }

      if (uDiv < 0.0) {
        uDiv = 0.0;
      }

      stills_R_Wsdfdsgfsdhfghggfh_B.ImageDataTypeConversion[yIdx] = (uint8_T)
        uDiv;
    }

    /* S-Function Block: <Root>/To RTDX (rtdx_snk) */
    if (RTDX_isOutputEnabled( &outputimage )) {
      while (RTDX_writing != NULL) {
      }                                /* waiting for rtdx write to complete */

      RTDX_write( &outputimage, (void*)
                 stills_R_Wsdfdsgfsdhfghggfh_B.ImageDataTypeConversion, 207*
                 sizeof(uint8_T));
    }
  }
}

/* Model initialize function */
void stills_R_Wsdfdsgfsdhfghggfh_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(stills_R_Wsdfdsgfsdhfghggfh_M, (const char_T *)0);

  /* block I/O */
  (void) memset(((void *) &stills_R_Wsdfdsgfsdhfghggfh_B),0,
                sizeof(BlockIO_stills_R_Wsdfdsgfsdhfgh));

  {
    int_T i;
    void *pVoidBlockIORegion;
    pVoidBlockIORegion = (void *)(&stills_R_Wsdfdsgfsdhfghggfh_B.Sum2[0]);
    for (i = 0; i < 413; i++) {
      ((real_T*)pVoidBlockIORegion)[i] = 0.0;
    }
  }

  /* S-Function Block: <Root>/From RTDX (rtdx_src) */
  {
    RTDX_enableInput(&inputimage);
  }

  RTDX_enableOutput(&outputimage);     /* S-Function Block: <Root>/To RTDX (rtdx_snk) */
}

/* Model terminate function */
void stills_R_Wsdfdsgfsdhfghggfh_terminate(void)
{
  RTDX_disableInput(&inputimage);      /* S-Function Block: <Root>/From RTDX (rtdx_src) */
  RTDX_disableOutput(&outputimage);    /* S-Function Block: <Root>/To RTDX (rtdx_snk) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
