//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Rpi_cam.cpp
//
// Code generated for Simulink model 'Rpi_cam'.
//
// Model version                  : 1.153
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Apr  9 15:11:19 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Rpi_cam.h"
#include "Rpi_cam_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "Rpi_cam_private.h"
#include <stddef.h>
#include <stdlib.h>

// Block signals (default storage)
B rtB;

// Block states (default storage)
DW rtDW;

// Real-time model
RT_MODEL rtM_ = RT_MODEL();
RT_MODEL *const rtM = &rtM_;

// Forward declaration for local functions
static void v4l2Capture_updateV4L2Settings
  (codertarget_raspi_internal_Raspiv4l2Capture *obj, boolean_T forceUpdate);
static void SystemCore_step(codertarget_raspi_internal_Raspiv4l2Capture *obj,
  uint8_T varargout_1[307200], uint8_T varargout_2[307200], uint8_T varargout_3
  [307200]);
static void makeConstraintMatrix_Projective_D_D(const real_T pts1[], const
  real_T pts2[], uint32_T sampleNum, uint32_T maxSampleNum, real_T constraint[]);
static void normPts_D_D_o(const real_T pts[], const uint32_T samples[], uint32_T
  ptsNum, uint32_T sampleNum, real_T ptsNorm[], real_T scale[], real_T cents[]);
static void QRV2Norm_real_T_o(const real_T V[], int32_T N, real_T v2norm[]);
static void QRDC_real_T_o(real_T xVec[], real_T qrAux[], int32_T jpvt[], real_T
  work[], int32_T M, int32_T N);
static void QRCompQy_real_T_o(real_T qr[], const real_T qrAuxj[], real_T y[],
  int32_T n, int32_T j);
static void QRSL1_real_T_o(real_T qr[], const real_T qrAux[], real_T y[],
  int32_T n, int32_T k);
static void QRE_real_T_o(real_T outQ[], real_T outR[], real_T outE[], real_T
  qrAux[], real_T work[], int32_T jpvt[], real_T sPtr[], int32_T M, int32_T N,
  boolean_T economy);
static void Warp_stepImpl(vision_internal_blocks_Warp *b_this, const boolean_T
  Image[307200], const real_T input2[9], boolean_T Jout[307200]);
static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions);
static void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int32_T
  oldNumel);
static void eml_find(const boolean_T x[307200], emxArray_int32_T *i,
                     emxArray_int32_T *j);
static void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions);
static void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int32_T
  oldNumel);
static void and_o(emxArray_boolean_T *in1, const emxArray_boolean_T *in2, const
                  emxArray_boolean_T *in3);
static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void binary_expand_op_3(emxArray_boolean_T *in1, const emxArray_boolean_T
  *in2, const emxArray_int32_T *in3);
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);
static real_T mean(const emxArray_real_T *x);
static real_T maximum(const emxArray_real_T *x);
static void binary_expand_op_2(emxArray_boolean_T *in1, const emxArray_boolean_T
  *in2, const emxArray_boolean_T *in3, const emxArray_boolean_T *in4, const
  emxArray_boolean_T *in5);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void binary_expand_op(emxArray_boolean_T *in1, const emxArray_int32_T
  *in2, real_T in3, real_T in4, const emxArray_int32_T *in5, real_T in6);
static void binary_expand_op_1(emxArray_boolean_T *in1, const emxArray_real_T
  *in2, real_T in3, real_T in4, const emxArray_real_T *in5, real_T in6);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static codertarget_raspi_internal_Raspiv4l2Capture
  *Raspiv4l2Capture_Raspiv4l2Capture(codertarget_raspi_internal_Raspiv4l2Capture
  *obj);
static void SystemCore_setup(codertarget_raspi_internal_RaspiTCPSend *obj);
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

static void v4l2Capture_updateV4L2Settings
  (codertarget_raspi_internal_Raspiv4l2Capture *obj, boolean_T forceUpdate)
{
  static const char_T b[11] = "Brightness";
  static const char_T c[9] = "Contrast";
  static const char_T d[11] = "Saturation";
  static const char_T e[10] = "Sharpness";
  static const char_T f[10] = "CameraPan";
  static const char_T g[11] = "CameraTilt";
  static const char_T h[11] = "CameraZoom";
  static const char_T i[18] = "EnableManualFocus";
  static const char_T j[12] = "ManualFocus";

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  if ((obj->Brightness != obj->BrightnessInternal) || forceUpdate) {
    obj->BrightnessInternal = obj->Brightness;
    for (rtB.i_l = 0; rtB.i_l < 11; rtB.i_l++) {
      rtB.b[rtB.i_l] = b[rtB.i_l];
    }

    EXT_updateV4L2Control(&rtB.b[0], static_cast<real32_T>(obj->Brightness), 0,
                          &rtB.status);
  }

  if ((obj->Contrast != obj->ContrastInternal) || forceUpdate) {
    obj->ContrastInternal = obj->Contrast;
    for (rtB.i_l = 0; rtB.i_l < 9; rtB.i_l++) {
      rtB.c[rtB.i_l] = c[rtB.i_l];
    }

    EXT_updateV4L2Control(&rtB.c[0], static_cast<real32_T>(obj->Contrast), 0,
                          &rtB.status);
  }

  if ((obj->Saturation != obj->SaturationInternal) || forceUpdate) {
    obj->SaturationInternal = obj->Saturation;
    for (rtB.i_l = 0; rtB.i_l < 11; rtB.i_l++) {
      rtB.b[rtB.i_l] = d[rtB.i_l];
    }

    EXT_updateV4L2Control(&rtB.b[0], static_cast<real32_T>(obj->Saturation), 0,
                          &rtB.status);
  }

  if ((obj->Sharpness != obj->SharpnessInternal) || forceUpdate) {
    obj->SharpnessInternal = obj->Sharpness;
    for (rtB.i_l = 0; rtB.i_l < 10; rtB.i_l++) {
      rtB.e[rtB.i_l] = e[rtB.i_l];
    }

    EXT_updateV4L2Control(&rtB.e[0], static_cast<real32_T>(obj->Sharpness), 0,
                          &rtB.status);
  }

  if ((obj->CameraPan != obj->CameraPanInternal) || forceUpdate) {
    obj->CameraPanInternal = obj->CameraPan;
    for (rtB.i_l = 0; rtB.i_l < 10; rtB.i_l++) {
      rtB.e[rtB.i_l] = f[rtB.i_l];
    }

    EXT_updateV4L2Control(&rtB.e[0], static_cast<real32_T>(obj->CameraPan), 0,
                          &rtB.status);
  }

  if ((obj->CameraTilt != obj->CameraTiltInternal) || forceUpdate) {
    obj->CameraTiltInternal = obj->CameraTilt;
    for (rtB.i_l = 0; rtB.i_l < 11; rtB.i_l++) {
      rtB.b[rtB.i_l] = g[rtB.i_l];
    }

    EXT_updateV4L2Control(&rtB.b[0], static_cast<real32_T>(obj->CameraTilt), 0,
                          &rtB.status);
  }

  if ((obj->CameraZoom != obj->CameraZoomInternal) || forceUpdate) {
    obj->CameraZoomInternal = obj->CameraZoom;
    for (rtB.i_l = 0; rtB.i_l < 11; rtB.i_l++) {
      rtB.b[rtB.i_l] = h[rtB.i_l];
    }

    EXT_updateV4L2Control(&rtB.b[0], static_cast<real32_T>(obj->CameraZoom), 0,
                          &rtB.status);
  }

  if ((!obj->EnableManualFocusInternal) || forceUpdate) {
    obj->EnableManualFocusInternal = true;
    for (rtB.i_l = 0; rtB.i_l < 18; rtB.i_l++) {
      rtB.i[rtB.i_l] = i[rtB.i_l];
    }

    EXT_updateV4L2Control(&rtB.i[0], 1.0F, 0, &rtB.status);
  }

  if ((obj->ManualFocus != obj->ManualFocusInternal) || forceUpdate) {
    obj->ManualFocusInternal = obj->ManualFocus;
    for (rtB.i_l = 0; rtB.i_l < 12; rtB.i_l++) {
      rtB.j[rtB.i_l] = j[rtB.i_l];
    }

    EXT_updateV4L2Control(&rtB.j[0], static_cast<real32_T>(obj->ManualFocus), 0,
                          &rtB.status);
  }

  // End of Start for MATLABSystem: '<Root>/V4L2 Video Capture'
}

static void SystemCore_step(codertarget_raspi_internal_Raspiv4l2Capture *obj,
  uint8_T varargout_1[307200], uint8_T varargout_2[307200], uint8_T varargout_3
  [307200])
{
  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  v4l2Capture_updateV4L2Settings(obj, false);
  EXT_webcamCapture(0, 0, &rtB.ts, &varargout_1[0], &varargout_2[0],
                    &varargout_3[0]);
}

static void makeConstraintMatrix_Projective_D_D(const real_T pts1[], const
  real_T pts2[], uint32_T sampleNum, uint32_T maxSampleNum, real_T constraint[])
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  // Generate the constraint matrix.
  rtB.j_m = 0U;
  rtB.k_m = 6U;
  rtB.i_c = 0U;
  while (rtB.i_c < sampleNum) {
    constraint[rtB.k_m - 6U] = 0.0;
    constraint[rtB.k_m + 4294967291U] = 0.0;
    constraint[rtB.k_m + 4294967292U] = 0.0;
    rtB.u = rtB.j_m + maxSampleNum;
    rtB.d3 = pts1[rtB.u];
    constraint[rtB.k_m + 4294967293U] = -rtB.d3;
    constraint[rtB.k_m + 4294967294U] = -pts1[rtB.j_m];
    constraint[rtB.k_m + MAX_uint32_T] = -1.0;
    constraint[rtB.k_m] = pts2[rtB.j_m];
    constraint[rtB.k_m] *= rtB.d3;
    constraint[rtB.k_m + 1U] = pts2[rtB.j_m];
    constraint[rtB.k_m + 1U] *= pts1[rtB.j_m];
    constraint[rtB.k_m + 2U] = pts2[rtB.j_m];
    constraint[rtB.k_m + 3U] = rtB.d3;
    constraint[rtB.k_m + 4U] = pts1[rtB.j_m];
    constraint[rtB.k_m + 5U] = 1.0;
    constraint[rtB.k_m + 6U] = 0.0;
    constraint[rtB.k_m + 7U] = 0.0;
    constraint[rtB.k_m + 8U] = 0.0;
    rtB.d4 = -pts2[rtB.u];
    constraint[rtB.k_m + 9U] = rtB.d4;
    constraint[rtB.k_m + 9U] *= rtB.d3;
    constraint[rtB.k_m + 10U] = rtB.d4;
    constraint[rtB.k_m + 10U] *= pts1[rtB.j_m];
    constraint[rtB.k_m + 11U] = rtB.d4;
    rtB.k_m += 18U;
    rtB.j_m++;
    rtB.i_c++;
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void normPts_D_D_o(const real_T pts[], const uint32_T samples[], uint32_T
  ptsNum, uint32_T sampleNum, real_T ptsNorm[], real_T scale[], real_T cents[])
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  // Normalize the points.
  cents[0U] = 0.0;
  cents[1U] = 0.0;
  rtB.i_ja = 0U;
  while (rtB.i_ja < sampleNum) {
    rtB.sumDis = pts[samples[rtB.i_ja] + ptsNum];
    ptsNorm[rtB.i_ja + sampleNum] = rtB.sumDis;
    cents[0U] += rtB.sumDis;
    rtB.sumDis = pts[samples[rtB.i_ja]];
    ptsNorm[rtB.i_ja] = rtB.sumDis;
    cents[1U] += rtB.sumDis;
    rtB.i_ja++;
  }

  cents[0U] /= static_cast<real_T>(sampleNum);
  cents[1U] /= static_cast<real_T>(sampleNum);
  rtB.sumDis = 0.0;
  rtB.i_ja = 0U;
  while (rtB.i_ja < sampleNum) {
    rtB.j_h = rtB.i_ja + sampleNum;
    ptsNorm[rtB.j_h] -= cents[0U];
    ptsNorm[rtB.i_ja] -= cents[1U];
    rtB.sumDis += sqrt(ptsNorm[rtB.j_h] * ptsNorm[rtB.j_h] + ptsNorm[rtB.i_ja] *
                       ptsNorm[rtB.i_ja]);
    rtB.i_ja++;
  }

  if (rtB.sumDis > 0.0) {
    scale[0U] = 1.4142135623730951;
    scale[0U] *= static_cast<real_T>(sampleNum);
    scale[0U] /= rtB.sumDis;
    rtB.i_ja = 0U;
    while (rtB.i_ja < sampleNum + sampleNum) {
      ptsNorm[rtB.i_ja] *= scale[0U];
      rtB.i_ja++;
    }
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void QRV2Norm_real_T_o(const real_T V[], int32_T N, real_T v2norm[])
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  rtB.val = 0.0;
  rtB.vi = 0;
  rtB.i_g = 0;
  while (rtB.i_g < N) {
    rtB.d = fabs(V[rtB.vi]);
    if (rtB.val > rtB.d) {
      rtB.tmpQRSL = V[rtB.vi] / rtB.val;
      rtB.val *= sqrt(rtB.tmpQRSL * rtB.tmpQRSL + 1.0);
    } else if (V[rtB.vi] == 0.0) {
      rtB.val = 0.0;
    } else {
      rtB.tmpQRSL = rtB.val / V[rtB.vi];
      rtB.val = sqrt(rtB.tmpQRSL * rtB.tmpQRSL + 1.0) * rtB.d;
    }

    rtB.vi++;
    rtB.i_g++;
  }

  v2norm[0U] = rtB.val;

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void QRDC_real_T_o(real_T xVec[], real_T qrAux[], int32_T jpvt[], real_T
  work[], int32_T M, int32_T N)
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  rtB.pl = 0;
  rtB.j_j = 0;
  while (rtB.j_j < N) {
    rtB.pu = (jpvt[rtB.j_j] > 0);
    if (jpvt[rtB.j_j] < 0) {
      jpvt[rtB.j_j] = -rtB.j_j;
    } else {
      jpvt[rtB.j_j] = rtB.j_j;
    }

    if (rtB.pu == 1) {
      if (rtB.j_j != rtB.pl) {
        // Swap columns pl and j
        rtB.px = rtB.pl * M;
        rtB.px2 = rtB.j_j * M;
        rtB.i_d = M;
        while (rtB.i_d > 0) {
          rtB.maxnrm = xVec[rtB.px];
          xVec[rtB.px] = xVec[rtB.px2];
          xVec[rtB.px2] = rtB.maxnrm;
          rtB.px++;
          rtB.px2++;
          rtB.i_d--;
        }
      }

      jpvt[rtB.j_j] = jpvt[rtB.pl];
      jpvt[rtB.pl] = rtB.j_j;
      rtB.pl++;
    }

    rtB.j_j++;
  }

  rtB.pu = N - 1;
  rtB.j_j = N - 1;
  while (rtB.j_j >= 0) {
    if (jpvt[rtB.j_j] < 0) {
      jpvt[rtB.j_j] = -jpvt[rtB.j_j];
      if (rtB.j_j != rtB.pu) {
        // Swap columns pu and j
        rtB.px = rtB.pu * M;
        rtB.px2 = rtB.j_j * M;
        rtB.i_d = M;
        while (rtB.i_d > 0) {
          rtB.maxnrm = xVec[rtB.px];
          xVec[rtB.px] = xVec[rtB.px2];
          xVec[rtB.px2] = rtB.maxnrm;
          rtB.px++;
          rtB.px2++;
          rtB.i_d--;
        }

        rtB.px = jpvt[rtB.pu];
        jpvt[rtB.pu] = jpvt[rtB.j_j];
        jpvt[rtB.j_j] = rtB.px;
      }

      rtB.pu--;
    }

    rtB.j_j--;
  }

  // compute the norms of the free columns
  rtB.j_j = rtB.pl;
  while (rtB.j_j <= rtB.pu) {
    QRV2Norm_real_T_o(&xVec[rtB.j_j * M], M, &qrAux[rtB.j_j]);
    work[rtB.j_j] = qrAux[rtB.j_j];
    rtB.j_j++;
  }

  // perform the Householder reduction of x
  if (M <= N) {
    rtB.minVal = M;
  } else {
    rtB.minVal = N;
  }

  rtB.l = 0;
  while (rtB.l < rtB.minVal) {
    rtB.mml = M - rtB.l;

    // locate the column of largest norm and bring it into the pivot position
    if ((rtB.l >= rtB.pl) && (rtB.l < rtB.pu)) {
      rtB.maxnrm = 0.0;
      rtB.maxj = rtB.l;
      rtB.j_j = rtB.l;
      while (rtB.j_j <= rtB.pu) {
        if (qrAux[rtB.j_j] > rtB.maxnrm) {
          rtB.maxnrm = qrAux[rtB.j_j];
          rtB.maxj = rtB.j_j;
        }

        rtB.j_j++;
      }

      if (rtB.maxj != rtB.l) {
        // Swap columns l and maxj
        rtB.px = rtB.l * M;
        rtB.px2 = rtB.maxj * M;
        rtB.i_d = M;
        while (rtB.i_d > 0) {
          rtB.maxnrm = xVec[rtB.px];
          xVec[rtB.px] = xVec[rtB.px2];
          xVec[rtB.px2] = rtB.maxnrm;
          rtB.px++;
          rtB.px2++;
          rtB.i_d--;
        }

        qrAux[rtB.maxj] = qrAux[rtB.l];
        work[rtB.maxj] = work[rtB.l];
        rtB.px = jpvt[rtB.maxj];
        jpvt[rtB.maxj] = jpvt[rtB.l];
        jpvt[rtB.l] = rtB.px;
      }
    }

    qrAux[rtB.l] = 0.0;
    if (M - 1 != rtB.l) {
      // Compute the Householder transformation for column l
      rtB.maxj = (M + 1) * rtB.l;
      rtB.px = rtB.maxj;
      QRV2Norm_real_T_o(&xVec[rtB.maxj], rtB.mml, &rtB.nrmxl);
      rtB.maxnrm = fabs(rtB.nrmxl);
      if (rtB.maxnrm != 0.0) {
        if (fabs(xVec[rtB.maxj]) != 0.0) {
          if (xVec[rtB.maxj] >= 0.0) {
            rtB.nrmxl = rtB.maxnrm;
          } else {
            rtB.nrmxl = -rtB.maxnrm;
          }
        }

        // Check if it's safe to multiply by 1/nrmxl instead of dividing by nrmxl 
        rtB.px2 = rtB.maxj;
        if (5.0E-20 * rtB.nrmxl != 0.0) {
          rtB.maxnrm = 1.0 / rtB.nrmxl;
          rtB.i_d = rtB.mml;
          while (rtB.i_d > 0) {
            xVec[rtB.px2] *= rtB.maxnrm;
            rtB.px2++;
            rtB.i_d--;
          }
        } else {
          rtB.i_d = rtB.mml;
          while (rtB.i_d > 0) {
            xVec[rtB.px2] /= rtB.nrmxl;
            rtB.px2++;
            rtB.i_d--;
          }
        }

        xVec[rtB.maxj]++;

        // apply the transformation to the remaining columns, updating the norms. 
        rtB.j_j = rtB.l + 1;
        while (rtB.j_j < N) {
          rtB.plj = rtB.j_j * M + rtB.l;
          rtB.px2 = rtB.plj;
          rtB.t = 0.0;
          rtB.i_d = rtB.mml;
          while (rtB.i_d > 0) {
            rtB.t -= xVec[rtB.px] * xVec[rtB.px2];
            rtB.px++;
            rtB.px2++;
            rtB.i_d--;
          }

          rtB.px = rtB.maxj;
          rtB.px2 = rtB.plj;
          rtB.t /= xVec[rtB.maxj];
          rtB.i_d = rtB.mml;
          while (rtB.i_d > 0) {
            xVec[rtB.px2] += rtB.t * xVec[rtB.px];
            rtB.px++;
            rtB.px2++;
            rtB.i_d--;
          }

          rtB.px = rtB.maxj;
          rtB.px2 = 0;
          if (qrAux[rtB.j_j] == 0.0) {
            rtB.px2 = 1;
          }

          if ((rtB.j_j >= rtB.pl) && (rtB.j_j <= rtB.pu) && (rtB.px2 == 0)) {
            rtB.maxnrm = fabs(xVec[rtB.plj]) / qrAux[rtB.j_j];
            rtB.tt = 1.0 - rtB.maxnrm * rtB.maxnrm;
            if (rtB.tt < 0.0) {
              rtB.tt = 0.0;
            }

            rtB.t = rtB.tt;
            rtB.maxnrm = qrAux[rtB.j_j] / work[rtB.j_j];
            rtB.tt = 0.05 * rtB.tt * rtB.maxnrm * rtB.maxnrm + 1.0;
            if (rtB.tt != 1.0) {
              qrAux[rtB.j_j] *= sqrt(rtB.t);
            } else {
              QRV2Norm_real_T_o(&xVec[rtB.plj + 1], rtB.mml - 1, &rtB.maxnrm);
              qrAux[rtB.j_j] = rtB.maxnrm;
              work[rtB.j_j] = qrAux[rtB.j_j];
            }
          }

          rtB.j_j++;
        }

        // save the transformation.
        qrAux[rtB.l] = xVec[rtB.px];
        xVec[rtB.px] = -rtB.nrmxl;
      }
    }

    rtB.l++;
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void QRCompQy_real_T_o(real_T qr[], const real_T qrAuxj[], real_T y[],
  int32_T n, int32_T j)
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  if (fabs(qrAuxj[0U]) != 0.0) {
    rtB.nmj = n - j;
    rtB.pjj = (n + 1) * j;
    rtB.pqr = rtB.pjj;
    rtB.temp = qr[rtB.pjj];
    qr[rtB.pjj] = qrAuxj[0U];
    rtB.t_n = 0.0;
    rtB.py = 0;
    rtB.i_lx = rtB.nmj;
    while (rtB.i_lx > 0) {
      rtB.t_n -= y[rtB.py] * qr[rtB.pqr];
      rtB.pqr++;
      rtB.py++;
      rtB.i_lx--;
    }

    rtB.pqr = rtB.pjj;
    rtB.t_n /= qr[rtB.pjj];
    rtB.py = 0;
    rtB.i_lx = rtB.nmj;
    while (rtB.i_lx > 0) {
      y[rtB.py] += rtB.t_n * qr[rtB.pqr];
      rtB.pqr++;
      rtB.py++;
      rtB.i_lx--;
    }

    qr[rtB.pjj] = rtB.temp;
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void QRSL1_real_T_o(real_T qr[], const real_T qrAux[], real_T y[],
  int32_T n, int32_T k)
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  if (k <= n - 1) {
    rtB.j_d = k;
  } else {
    rtB.j_d = n - 1;
  }

  if (rtB.j_d != 0) {
    rtB.pqraux_tmp = rtB.j_d;
    rtB.i_dy = rtB.j_d;
    while (rtB.i_dy > 0) {
      QRCompQy_real_T_o(&qr[0], &qrAux[rtB.j_d - 1], &y[rtB.pqraux_tmp - 1], n,
                        rtB.i_dy - 1);
      rtB.pqraux_tmp = rtB.j_d - 1;
      rtB.j_d--;
      rtB.i_dy--;
    }
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void QRE_real_T_o(real_T outQ[], real_T outR[], real_T outE[], real_T
  qrAux[], real_T work[], int32_T jpvt[], real_T sPtr[], int32_T M, int32_T N,
  boolean_T economy)
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  QRDC_real_T_o(&outR[0], &qrAux[0], &jpvt[0], &work[0], M, N);

  // explicitly form q by manipulating identity
  if (economy) {
    if (M <= N) {
      rtB.L = M;
    } else {
      rtB.L = N;
    }
  } else {
    rtB.L = M;
  }

  rtB.pq = 0;
  rtB.j_l = 0;
  while (rtB.j_l < M * rtB.L) {
    outQ[rtB.j_l] = 0.0;
    rtB.j_l++;
  }

  rtB.j_l = 0;
  while (rtB.j_l < rtB.L) {
    outQ[rtB.pq] = 1.0;
    rtB.pq = (rtB.pq + M) + 1;
    rtB.j_l++;
  }

  // Convert cols of identity into cols of q. Use info stored in lower triangle of r and in vector qraux to work on columns of identity matrix I and transform them into q*I(:,j) i.e. the columns of q. 
  rtB.pq = 0;
  rtB.j_l = 0;
  while (rtB.j_l < rtB.L) {
    QRSL1_real_T_o(&outR[0], &qrAux[0], &outQ[rtB.pq], M, N);
    rtB.pq += M;
    rtB.j_l++;
  }

  if (economy && (M > N)) {
    // Copy upper triangle of r to s
    rtB.L = 0;
    rtB.ps = 0;
    rtB.j_l = 1;
    while (rtB.j_l - 1 < N) {
      rtB.pq = 0;
      while (rtB.pq <= rtB.j_l - 1) {
        sPtr[rtB.ps] = outR[rtB.L];
        rtB.ps++;
        rtB.L++;
        rtB.pq++;
      }

      rtB.L = (rtB.L + M) - rtB.j_l;
      rtB.pq = 0;
      while (rtB.pq < N - rtB.j_l) {
        sPtr[rtB.ps] = 0.0;
        rtB.ps++;
        rtB.pq++;
      }

      rtB.j_l++;
    }
  } else {
    // Zero strict lower triangle of r
    rtB.L = M * N - 1;
    rtB.j_l = N;
    while (rtB.j_l - 1 >= 0) {
      rtB.pq = M;
      while (rtB.pq > rtB.j_l) {
        outR[rtB.L] = 0.0;
        rtB.L--;
        rtB.pq--;
      }

      if (M < rtB.j_l) {
        rtB.L -= M;
      } else {
        rtB.L -= rtB.j_l;
      }

      rtB.j_l--;
    }
  }

  // form permutation vector e
  rtB.L = 0;
  rtB.pq = 0;
  rtB.j_l = 0;
  while (rtB.j_l < N) {
    outE[rtB.L] = jpvt[rtB.pq] + 1;
    rtB.pq = rtB.L + 1;
    rtB.L++;
    rtB.j_l++;
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void Warp_stepImpl(vision_internal_blocks_Warp *b_this, const boolean_T
  Image[307200], const real_T input2[9], boolean_T Jout[307200])
{
  for (rtB.p2 = 0; rtB.p2 < 9; rtB.p2++) {
    // Start for MATLABSystem: '<S4>/Warp'
    rtB.absx11 = input2[rtB.p2];
    b_this->TformProjective.T[rtB.p2] = rtB.absx11;
    rtB.x[rtB.p2] = rtB.absx11;
  }

  rtB.p1 = 1;
  rtB.p2 = 3;
  rtB.p3 = 6;

  // Start for MATLABSystem: '<S4>/Warp'
  rtB.absx11 = fabs(b_this->TformProjective.T[0]);
  rtB.absx21 = fabs(b_this->TformProjective.T[1]);
  rtB.absx31 = fabs(b_this->TformProjective.T[2]);
  if ((rtB.absx21 > rtB.absx11) && (rtB.absx21 > rtB.absx31)) {
    rtB.p1 = 4;
    rtB.p2 = 0;
    rtB.x[0] = b_this->TformProjective.T[1];
    rtB.x[1] = b_this->TformProjective.T[0];
    rtB.x[3] = b_this->TformProjective.T[4];
    rtB.x[4] = b_this->TformProjective.T[3];
    rtB.x[6] = b_this->TformProjective.T[7];
    rtB.x[7] = b_this->TformProjective.T[6];
  } else if (rtB.absx31 > rtB.absx11) {
    rtB.p1 = 7;
    rtB.p3 = 0;
    rtB.x[0] = b_this->TformProjective.T[2];
    rtB.x[2] = b_this->TformProjective.T[0];
    rtB.x[3] = b_this->TformProjective.T[5];
    rtB.x[5] = b_this->TformProjective.T[3];
    rtB.x[6] = b_this->TformProjective.T[8];
    rtB.x[8] = b_this->TformProjective.T[6];
  }

  rtB.absx11 = rtB.x[1] / rtB.x[0];
  rtB.x[1] = rtB.absx11;

  // Start for MATLABSystem: '<S4>/Warp'
  rtB.absx21 = rtB.x[2] / rtB.x[0];
  rtB.x[2] = rtB.absx21;
  rtB.x[4] -= rtB.absx11 * rtB.x[3];
  rtB.x[5] -= rtB.absx21 * rtB.x[3];
  rtB.x[7] -= rtB.absx11 * rtB.x[6];
  rtB.x[8] -= rtB.absx21 * rtB.x[6];

  // Start for MATLABSystem: '<S4>/Warp'
  if (fabs(rtB.x[5]) > fabs(rtB.x[4])) {
    rtB.itmp = rtB.p2;
    rtB.p2 = rtB.p3;
    rtB.p3 = rtB.itmp;
    rtB.x[1] = rtB.absx21;
    rtB.x[2] = rtB.absx11;
    rtB.absx11 = rtB.x[4];
    rtB.x[4] = rtB.x[5];
    rtB.x[5] = rtB.absx11;
    rtB.absx11 = rtB.x[7];
    rtB.x[7] = rtB.x[8];
    rtB.x[8] = rtB.absx11;
  }

  rtB.absx11 = rtB.x[5] / rtB.x[4];
  rtB.x[8] -= rtB.absx11 * rtB.x[7];

  // Start for MATLABSystem: '<S4>/Warp'
  rtB.absx21 = (rtB.x[1] * rtB.absx11 - rtB.x[2]) / rtB.x[8];
  rtB.absx31 = -(rtB.x[7] * rtB.absx21 + rtB.x[1]) / rtB.x[4];
  rtB.tinv[rtB.p1 - 1] = ((1.0 - rtB.x[3] * rtB.absx31) - rtB.x[6] * rtB.absx21)
    / rtB.x[0];
  rtB.tinv[rtB.p1] = rtB.absx31;
  rtB.tinv[rtB.p1 + 1] = rtB.absx21;
  rtB.absx21 = -rtB.absx11 / rtB.x[8];
  rtB.absx31 = (1.0 - rtB.x[7] * rtB.absx21) / rtB.x[4];
  rtB.tinv[rtB.p2] = -(rtB.x[3] * rtB.absx31 + rtB.x[6] * rtB.absx21) / rtB.x[0];
  rtB.tinv[rtB.p2 + 1] = rtB.absx31;
  rtB.tinv[rtB.p2 + 2] = rtB.absx21;
  rtB.absx21 = 1.0 / rtB.x[8];
  rtB.absx31 = -rtB.x[7] * rtB.absx21 / rtB.x[4];
  rtB.tinv[rtB.p3] = -(rtB.x[3] * rtB.absx31 + rtB.x[6] * rtB.absx21) / rtB.x[0];
  rtB.tinv[rtB.p3 + 1] = rtB.absx31;
  rtB.tinv[rtB.p3 + 2] = rtB.absx21;
  rtB.absx11 = rtB.tinv[6];
  rtB.absx21 = rtB.tinv[7];
  rtB.absx31 = rtB.tinv[8];

  // Start for MATLABSystem: '<S4>/Warp'
  rtB.tinv_p = rtB.tinv[0];
  rtB.tinv_c = rtB.tinv[1];
  rtB.tinv_f = rtB.tinv[2];
  rtB.tinv_g = rtB.tinv[3];
  rtB.tinv_g1 = rtB.tinv[4];
  rtB.tinv_m = rtB.tinv[5];
  for (rtB.p1 = 0; rtB.p1 < 640; rtB.p1++) {
    for (rtB.p2 = 0; rtB.p2 < 480; rtB.p2++) {
      // Start for MATLABSystem: '<S4>/Warp'
      rtB.srczWorld_val = ((((static_cast<real_T>(rtB.p1) + 1.0) - 0.5) + 0.5) *
                           rtB.absx11 + (((static_cast<real_T>(rtB.p2) + 1.0) -
        0.5) + 0.5) * rtB.absx21) + rtB.absx31;
      rtB.p3 = 480 * rtB.p1 + rtB.p2;
      rtB.srcXIntrinsic[rtB.p3] = ((((((static_cast<real_T>(rtB.p1) + 1.0) - 0.5)
        + 0.5) * rtB.tinv_p + (((static_cast<real_T>(rtB.p2) + 1.0) - 0.5) + 0.5)
        * rtB.tinv_c) + rtB.tinv_f) / rtB.srczWorld_val - 0.5) + 0.5;
      rtB.srcYIntrinsic[rtB.p3] = ((((((static_cast<real_T>(rtB.p1) + 1.0) - 0.5)
        + 0.5) * rtB.tinv_g + (((static_cast<real_T>(rtB.p2) + 1.0) - 0.5) + 0.5)
        * rtB.tinv_g1) + rtB.tinv_m) / rtB.srczWorld_val - 0.5) + 0.5;
    }
  }

  for (rtB.p2 = 0; rtB.p2 < 307200; rtB.p2++) {
    // Start for MATLABSystem: '<S4>/Warp'
    rtB.inputImage[rtB.p2] = static_cast<int8_T>(Image[rtB.p2]);
  }

  for (rtB.p1 = 0; rtB.p1 < 307200; rtB.p1++) {
    // Start for MATLABSystem: '<S4>/Warp'
    rtB.absx21 = rtB.srcXIntrinsic[rtB.p1];
    if ((rtB.absx21 >= 1.0) && (rtB.absx21 <= 640.0)) {
      rtB.absx11 = rtB.srcYIntrinsic[rtB.p1];
      if ((rtB.absx11 >= 1.0) && (rtB.absx11 <= 480.0)) {
        if (rtB.absx21 <= 1.0) {
          rtB.itmp = 1;
        } else if (rtB.absx21 <= 639.0) {
          rtB.itmp = static_cast<int32_T>(floor(rtB.absx21));
        } else {
          rtB.itmp = 639;
        }

        rtB.absx11 = rtB.srcYIntrinsic[rtB.p1];
        if (rtB.absx11 <= 1.0) {
          rtB.p3 = 1;
        } else if (rtB.absx11 <= 479.0) {
          rtB.p3 = static_cast<int32_T>(floor(rtB.absx11));
        } else {
          rtB.p3 = 479;
        }

        if (rtB.absx21 == rtB.itmp) {
          rtB.p2 = (rtB.itmp - 1) * 480 + rtB.p3;
          rtB.qx1 = rtB.inputImage[rtB.p2 - 1];
          rtB.qx2 = rtB.inputImage[rtB.p2];
        } else if (static_cast<real_T>(rtB.itmp) + 1.0 == rtB.absx21) {
          rtB.p2 = 480 * rtB.itmp + rtB.p3;
          rtB.qx1 = rtB.inputImage[rtB.p2 - 1];
          rtB.qx2 = rtB.inputImage[rtB.p2];
        } else {
          rtB.absx21 -= static_cast<real_T>(rtB.itmp);
          rtB.p2 = (rtB.itmp - 1) * 480 + rtB.p3;
          rtB.i8 = rtB.inputImage[rtB.p2 - 1];
          rtB.itmp = 480 * rtB.itmp + rtB.p3;
          rtB.i9 = rtB.inputImage[rtB.itmp - 1];
          if (rtB.i8 == rtB.i9) {
            rtB.qx1 = rtB.i8;
          } else {
            rtB.qx1 = static_cast<real32_T>(1.0 - rtB.absx21) *
              static_cast<real32_T>(rtB.i8) + static_cast<real32_T>(rtB.i9) *
              static_cast<real32_T>(rtB.absx21);
          }

          rtB.i8 = rtB.inputImage[rtB.p2];
          rtB.i9 = rtB.inputImage[rtB.itmp];
          if (rtB.i8 == rtB.i9) {
            rtB.qx2 = rtB.i8;
          } else {
            rtB.qx2 = static_cast<real32_T>(1.0 - rtB.absx21) *
              static_cast<real32_T>(rtB.i8) + static_cast<real32_T>(rtB.i9) *
              static_cast<real32_T>(rtB.absx21);
          }
        }

        if ((rtB.absx11 == rtB.p3) || (rtB.qx1 == rtB.qx2)) {
          rtB.qx2 = rtB.qx1;
        } else if (!(static_cast<real_T>(rtB.p3) + 1.0 == rtB.absx11)) {
          rtB.absx11 -= static_cast<real_T>(rtB.p3);
          rtB.qx2 = static_cast<real32_T>(1.0 - rtB.absx11) * rtB.qx1 +
            static_cast<real32_T>(rtB.absx11) * rtB.qx2;
        }
      } else {
        rtB.qx2 = 0.0F;
      }
    } else {
      rtB.qx2 = 0.0F;
    }

    Jout[rtB.p1] = (rtB.qx2 > 0.5F);
  }
}

static void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions)
{
  emxArray_int32_T *emxArray;
  *pEmxArray = static_cast<emxArray_int32_T *>(malloc(sizeof(emxArray_int32_T)));
  emxArray = *pEmxArray;
  emxArray->data = static_cast<int32_T *>(NULL);
  emxArray->numDimensions = numDimensions;
  emxArray->size = static_cast<int32_T *>(malloc(sizeof(int32_T)
    * static_cast<uint32_T>(numDimensions)));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (rtB.i_i = 0; rtB.i_i < numDimensions; rtB.i_i++) {
    emxArray->size[rtB.i_i] = 0;
  }
}

static void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int32_T
  oldNumel)
{
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  rtB.newNumel_b = 1;
  for (rtB.i_j = 0; rtB.i_j < emxArray->numDimensions; rtB.i_j++) {
    rtB.newNumel_b *= emxArray->size[rtB.i_j];
  }

  if (rtB.newNumel_b > emxArray->allocatedSize) {
    rtB.i_j = emxArray->allocatedSize;
    if (rtB.i_j < 16) {
      rtB.i_j = 16;
    }

    while (rtB.i_j < rtB.newNumel_b) {
      if (rtB.i_j > 1073741823) {
        rtB.i_j = MAX_int32_T;
      } else {
        rtB.i_j <<= 1;
      }
    }

    newData = malloc(static_cast<uint32_T>(rtB.i_j) * sizeof(int32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * static_cast<uint32_T>
             (oldNumel));
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = static_cast<int32_T *>(newData);
    emxArray->allocatedSize = rtB.i_j;
    emxArray->canFreeData = true;
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static void eml_find(const boolean_T x[307200], emxArray_int32_T *i,
                     emxArray_int32_T *j)
{
  boolean_T exitg1;
  boolean_T guard1;
  rtB.idx = 0;
  rtB.ii = i->size[0];
  i->size[0] = 307200;
  emxEnsureCapacity_int32_T(i, rtB.ii);
  rtB.ii = j->size[0];
  j->size[0] = 307200;
  emxEnsureCapacity_int32_T(j, rtB.ii);
  rtB.ii = 1;
  rtB.jj = 1;
  exitg1 = false;
  while ((!exitg1) && (rtB.jj <= 640)) {
    guard1 = false;
    if (x[((rtB.jj - 1) * 480 + rtB.ii) - 1]) {
      rtB.idx++;
      i->data[rtB.idx - 1] = rtB.ii;
      j->data[rtB.idx - 1] = rtB.jj;
      if (rtB.idx >= 307200) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      rtB.ii++;
      if (rtB.ii > 480) {
        rtB.ii = 1;
        rtB.jj++;
      }
    }
  }

  if (rtB.idx < 1) {
    i->size[0] = 0;
    j->size[0] = 0;
  } else {
    rtB.ii = i->size[0];
    i->size[0] = rtB.idx;
    emxEnsureCapacity_int32_T(i, rtB.ii);
    rtB.ii = j->size[0];
    j->size[0] = rtB.idx;
    emxEnsureCapacity_int32_T(j, rtB.ii);
  }
}

static void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions)
{
  emxArray_boolean_T *emxArray;
  *pEmxArray = static_cast<emxArray_boolean_T *>(malloc(sizeof
    (emxArray_boolean_T)));
  emxArray = *pEmxArray;
  emxArray->data = static_cast<boolean_T *>(NULL);
  emxArray->numDimensions = numDimensions;
  emxArray->size = static_cast<int32_T *>(malloc(sizeof(int32_T)
    * static_cast<uint32_T>(numDimensions)));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (rtB.i_oy = 0; rtB.i_oy < numDimensions; rtB.i_oy++) {
    emxArray->size[rtB.i_oy] = 0;
  }
}

static void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int32_T
  oldNumel)
{
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  rtB.newNumel = 1;
  for (rtB.i_o = 0; rtB.i_o < emxArray->numDimensions; rtB.i_o++) {
    rtB.newNumel *= emxArray->size[rtB.i_o];
  }

  if (rtB.newNumel > emxArray->allocatedSize) {
    rtB.i_o = emxArray->allocatedSize;
    if (rtB.i_o < 16) {
      rtB.i_o = 16;
    }

    while (rtB.i_o < rtB.newNumel) {
      if (rtB.i_o > 1073741823) {
        rtB.i_o = MAX_int32_T;
      } else {
        rtB.i_o <<= 1;
      }
    }

    newData = malloc(static_cast<uint32_T>(rtB.i_o) * sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * static_cast<uint32_T>
             (oldNumel));
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = static_cast<boolean_T *>(newData);
    emxArray->allocatedSize = rtB.i_o;
    emxArray->canFreeData = true;
  }
}

static void and_o(emxArray_boolean_T *in1, const emxArray_boolean_T *in2, const
                  emxArray_boolean_T *in3)
{
  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.loop_ub_j = in3->size[0] == 1 ? in2->size[0] : in3->size[0];
  rtB.i7 = in1->size[0];
  in1->size[0] = rtB.loop_ub_j;
  emxEnsureCapacity_boolean_T(in1, rtB.i7);
  rtB.stride_0_0_f = (in2->size[0] != 1);
  rtB.stride_1_0_a = (in3->size[0] != 1);
  for (rtB.i7 = 0; rtB.i7 < rtB.loop_ub_j; rtB.i7++) {
    in1->data[rtB.i7] = (in2->data[rtB.i7 * rtB.stride_0_0_f] && in3->
                         data[rtB.i7 * rtB.stride_1_0_a]);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != static_cast<emxArray_boolean_T *>(NULL)) {
    if (((*pEmxArray)->data != static_cast<boolean_T *>(NULL)) && (*pEmxArray)
        ->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = static_cast<emxArray_boolean_T *>(NULL);
  }
}

static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T *emxArray;
  *pEmxArray = static_cast<emxArray_real_T *>(malloc(sizeof(emxArray_real_T)));
  emxArray = *pEmxArray;
  emxArray->data = static_cast<real_T *>(NULL);
  emxArray->numDimensions = numDimensions;
  emxArray->size = static_cast<int32_T *>(malloc(sizeof(int32_T)
    * static_cast<uint32_T>(numDimensions)));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (rtB.i_n = 0; rtB.i_n < numDimensions; rtB.i_n++) {
    emxArray->size[rtB.i_n] = 0;
  }
}

static void binary_expand_op_3(emxArray_boolean_T *in1, const emxArray_boolean_T
  *in2, const emxArray_int32_T *in3)
{
  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.loop_ub_e = in3->size[0] == 1 ? in3->size[0] == 1 ? in2->size[0] :
    in3->size[0] : in3->size[0];
  rtB.i6 = in1->size[0];
  in1->size[0] = rtB.loop_ub_e;
  emxEnsureCapacity_boolean_T(in1, rtB.i6);
  rtB.stride_0_0_d = (in2->size[0] != 1);
  rtB.stride_1_0_tmp = (in3->size[0] != 1);
  for (rtB.i6 = 0; rtB.i6 < rtB.loop_ub_e; rtB.i6++) {
    rtB.i5 = in3->data[rtB.i6 * rtB.stride_1_0_tmp];
    in1->data[rtB.i6] = (in2->data[rtB.i6 * rtB.stride_0_0_d] && (rtB.i5 >= 0) &&
                         (rtB.i5 < 160));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel)
{
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  rtB.newNumel_j = 1;
  for (rtB.i_o4 = 0; rtB.i_o4 < emxArray->numDimensions; rtB.i_o4++) {
    rtB.newNumel_j *= emxArray->size[rtB.i_o4];
  }

  if (rtB.newNumel_j > emxArray->allocatedSize) {
    rtB.i_o4 = emxArray->allocatedSize;
    if (rtB.i_o4 < 16) {
      rtB.i_o4 = 16;
    }

    while (rtB.i_o4 < rtB.newNumel_j) {
      if (rtB.i_o4 > 1073741823) {
        rtB.i_o4 = MAX_int32_T;
      } else {
        rtB.i_o4 <<= 1;
      }
    }

    newData = malloc(static_cast<uint32_T>(rtB.i_o4) * sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * static_cast<uint32_T>
             (oldNumel));
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = static_cast<real_T *>(newData);
    emxArray->allocatedSize = rtB.i_o4;
    emxArray->canFreeData = true;
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static real_T mean(const emxArray_real_T *x)
{
  if (x->size[0] == 0) {
    rtB.b_y = 0.0;
  } else {
    if (x->size[0] <= 1024) {
      rtB.firstBlockLength = x->size[0];
      rtB.lastBlockLength = 0;
      rtB.nblocks = 1;
    } else {
      rtB.firstBlockLength = 1024;
      rtB.nblocks = static_cast<int32_T>(static_cast<uint32_T>(x->size[0]) >> 10);
      rtB.lastBlockLength = x->size[0] - (rtB.nblocks << 10);
      if (rtB.lastBlockLength > 0) {
        rtB.nblocks++;
      } else {
        rtB.lastBlockLength = 1024;
      }
    }

    rtB.b_y = x->data[0];
    for (rtB.xblockoffset = 2; rtB.xblockoffset <= rtB.firstBlockLength;
         rtB.xblockoffset++) {
      rtB.b_y += x->data[rtB.xblockoffset - 1];
    }

    for (rtB.firstBlockLength = 2; rtB.firstBlockLength <= rtB.nblocks;
         rtB.firstBlockLength++) {
      rtB.xblockoffset = (rtB.firstBlockLength - 1) << 10;
      rtB.bsum = x->data[rtB.xblockoffset];
      if (rtB.firstBlockLength == rtB.nblocks) {
        rtB.hi = rtB.lastBlockLength;
      } else {
        rtB.hi = 1024;
      }

      for (rtB.b_k = 2; rtB.b_k <= rtB.hi; rtB.b_k++) {
        rtB.bsum += x->data[(rtB.xblockoffset + rtB.b_k) - 1];
      }

      rtB.b_y += rtB.bsum;
    }
  }

  return rtB.b_y / static_cast<real_T>(x->size[0]);
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static real_T maximum(const emxArray_real_T *x)
{
  real_T ex;
  rtB.last = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x->data[0];
    } else {
      ex = x->data[x->size[0] - 1];
      if (!(x->data[0] < ex)) {
        ex = x->data[0];
      }
    }
  } else {
    ex = x->data[0];
    for (rtB.k_n = 2; rtB.k_n <= rtB.last; rtB.k_n++) {
      rtB.x_p = x->data[rtB.k_n - 1];
      if (ex < rtB.x_p) {
        ex = rtB.x_p;
      }
    }
  }

  return ex;
}

static void binary_expand_op_2(emxArray_boolean_T *in1, const emxArray_boolean_T
  *in2, const emxArray_boolean_T *in3, const emxArray_boolean_T *in4, const
  emxArray_boolean_T *in5)
{
  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.loop_ub_bn = in5->size[0] == 1 ? in4->size[0] == 1 ? in2->size[0] :
    in4->size[0] : in5->size[0];
  rtB.i4 = in1->size[0];
  in1->size[0] = rtB.loop_ub_bn;
  emxEnsureCapacity_boolean_T(in1, rtB.i4);
  rtB.stride_0_0_l = (in2->size[0] != 1);
  rtB.stride_1_0_h = (in4->size[0] != 1);
  rtB.stride_2_0 = (in5->size[0] != 1);
  for (rtB.i4 = 0; rtB.i4 < rtB.loop_ub_bn; rtB.i4++) {
    rtB.i3 = rtB.i4 * rtB.stride_0_0_l;
    in1->data[rtB.i4] = (in2->data[rtB.i3] && in3->data[rtB.i3] && in4->
                         data[rtB.i4 * rtB.stride_1_0_h] && in5->data[rtB.i4 *
                         rtB.stride_2_0]);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

static void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != static_cast<emxArray_int32_T *>(NULL)) {
    if (((*pEmxArray)->data != static_cast<int32_T *>(NULL)) && (*pEmxArray)
        ->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = static_cast<emxArray_int32_T *>(NULL);
  }
}

static void binary_expand_op(emxArray_boolean_T *in1, const emxArray_int32_T
  *in2, real_T in3, real_T in4, const emxArray_int32_T *in5, real_T in6)
{
  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.loop_ub_b = in5->size[0] == 1 ? in2->size[0] : in5->size[0];
  rtB.i2 = in1->size[0];
  in1->size[0] = rtB.loop_ub_b;
  emxEnsureCapacity_boolean_T(in1, rtB.i2);
  rtB.stride_0_0_b = (in2->size[0] != 1);
  rtB.stride_1_0_n = (in5->size[0] != 1);
  for (rtB.i2 = 0; rtB.i2 < rtB.loop_ub_b; rtB.i2++) {
    rtB.d2 = in2->data[rtB.i2 * rtB.stride_0_0_b];
    in1->data[rtB.i2] = ((rtB.d2 >= in3) && (rtB.d2 < in4) && (in5->data[rtB.i2 *
      rtB.stride_1_0_n] >= in6 - 40.0));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

static void binary_expand_op_1(emxArray_boolean_T *in1, const emxArray_real_T
  *in2, real_T in3, real_T in4, const emxArray_real_T *in5, real_T in6)
{
  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.loop_ub = in5->size[0] == 1 ? in2->size[0] : in5->size[0];
  rtB.i1 = in1->size[0];
  in1->size[0] = rtB.loop_ub;
  emxEnsureCapacity_boolean_T(in1, rtB.i1);
  rtB.stride_0_0 = (in2->size[0] != 1);
  rtB.stride_1_0 = (in5->size[0] != 1);
  for (rtB.i1 = 0; rtB.i1 < rtB.loop_ub; rtB.i1++) {
    rtB.d1 = in2->data[rtB.i1 * rtB.stride_0_0];
    in1->data[rtB.i1] = ((rtB.d1 >= in3) && (rtB.d1 < in4) && (in5->data[rtB.i1 *
      rtB.stride_1_0] >= in6 - 40.0));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != static_cast<emxArray_real_T *>(NULL)) {
    if (((*pEmxArray)->data != static_cast<real_T *>(NULL)) && (*pEmxArray)
        ->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = static_cast<emxArray_real_T *>(NULL);
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static codertarget_raspi_internal_Raspiv4l2Capture
  *Raspiv4l2Capture_Raspiv4l2Capture(codertarget_raspi_internal_Raspiv4l2Capture
  *obj)
{
  codertarget_raspi_internal_Raspiv4l2Capture *b_obj;

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  obj->BrightnessInternal = 0.5;
  obj->SaturationInternal = 0.5;
  obj->ContrastInternal = 0.5;
  obj->SharpnessInternal = 0.5;
  obj->CameraZoomInternal = 0.5;
  obj->ManualFocusInternal = 0.5;
  obj->CameraPanInternal = 0.0;
  obj->CameraTiltInternal = 0.0;
  obj->EnableManualFocusInternal = true;
  obj->isInitialized = 0;
  b_obj = obj;
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void SystemCore_setup(codertarget_raspi_internal_RaspiTCPSend *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T ipaddr[14];
  static const char_T ipaddr_0[14] = "192.168.1.118";

  // Start for MATLABSystem: '<Root>/TCP//IP Send1'
  obj->isInitialized = 1;
  obj->isServer_ = 0.0;
  for (i = 0; i < 14; i++) {
    ipaddr[i] = ipaddr_0[i];
  }

  // Start for MATLABSystem: '<Root>/TCP//IP Send1'
  tmp = rt_roundd_snf(obj->isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_T>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  // Start for MATLABSystem: '<Root>/TCP//IP Send1'
  TCPStreamSetup(3333, 0, &obj->connStream_, tmp_0, 0.0, &errorNo, &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
}

// Model step function
void Rpi_cam_step(void)
{
  emxArray_boolean_T *b;
  emxArray_boolean_T *b_tmp;
  emxArray_boolean_T *c;
  emxArray_boolean_T *d;
  emxArray_boolean_T *g;
  emxArray_boolean_T *h;
  emxArray_boolean_T *tmp_0;
  emxArray_boolean_T *tmp_1;
  emxArray_boolean_T *tmp_2;
  emxArray_boolean_T *tmp_3;
  emxArray_boolean_T *tmp_4;
  emxArray_boolean_T *tmp_5;
  emxArray_boolean_T *tmp_6;
  emxArray_int32_T *ii;
  emxArray_int32_T *jj;
  emxArray_int32_T *tmp;
  emxArray_int32_T *tmp_7;
  emxArray_int32_T *tmp_8;
  emxArray_int32_T *tmp_9;
  emxArray_real_T *c_tmp;
  emxArray_real_T *jj_0;
  static const int16_T tmp_a[8] = { 145, 500, 27, 639, 300, 300, 415, 415 };

  static const int16_T tmp_b[8] = { 40, 600, 40, 600, 300, 300, 480, 480 };

  // MATLABSystem: '<Root>/V4L2 Video Capture'
  if (rtDW.obj.Brightness != rtP.V4L2VideoCapture_Brightness) {
    rtDW.obj.Brightness = rtP.V4L2VideoCapture_Brightness;
  }

  if (rtDW.obj.Saturation != rtP.V4L2VideoCapture_Saturation) {
    rtDW.obj.Saturation = rtP.V4L2VideoCapture_Saturation;
  }

  if (rtDW.obj.Contrast != rtP.V4L2VideoCapture_Contrast) {
    rtDW.obj.Contrast = rtP.V4L2VideoCapture_Contrast;
  }

  if (rtDW.obj.Sharpness != rtP.V4L2VideoCapture_Sharpness) {
    rtDW.obj.Sharpness = rtP.V4L2VideoCapture_Sharpness;
  }

  if (rtDW.obj.CameraPan != rtP.V4L2VideoCapture_CameraPan) {
    rtDW.obj.CameraPan = rtP.V4L2VideoCapture_CameraPan;
  }

  if (rtDW.obj.CameraTilt != rtP.V4L2VideoCapture_CameraTilt) {
    rtDW.obj.CameraTilt = rtP.V4L2VideoCapture_CameraTilt;
  }

  if (rtDW.obj.CameraZoom != rtP.V4L2VideoCapture_CameraZoom) {
    rtDW.obj.CameraZoom = rtP.V4L2VideoCapture_CameraZoom;
  }

  if (rtDW.obj.ManualFocus != rtP.V4L2VideoCapture_ManualFocus) {
    rtDW.obj.ManualFocus = rtP.V4L2VideoCapture_ManualFocus;
  }

  SystemCore_step(&rtDW.obj, rtB.b_varargout_1_k, rtB.b_varargout_2,
                  rtB.b_varargout_3);

  // Math: '<S3>/Transpose' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'
  //
  for (rtB.bestCol = 0; rtB.bestCol < 640; rtB.bestCol++) {
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 480; rtB.bestInlierNum++) {
      rtB.b_varargout_1[rtB.bestInlierNum + 480 * rtB.bestCol] =
        rtB.b_varargout_1_k[640 * rtB.bestInlierNum + rtB.bestCol];
    }
  }

  memcpy(&rtB.outputImage[0], &rtB.b_varargout_1[0], 307200U * sizeof(uint8_T));

  // End of Math: '<S3>/Transpose'

  // Math: '<S3>/Transpose1' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'
  //
  for (rtB.bestCol = 0; rtB.bestCol < 640; rtB.bestCol++) {
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 480; rtB.bestInlierNum++) {
      rtB.b_varargout_1_k[rtB.bestInlierNum + 480 * rtB.bestCol] =
        rtB.b_varargout_2[640 * rtB.bestInlierNum + rtB.bestCol];
    }
  }

  memcpy(&rtB.outputImage[307200], &rtB.b_varargout_1_k[0], 307200U * sizeof
         (uint8_T));

  // End of Math: '<S3>/Transpose1'

  // Math: '<S3>/Transpose2' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'
  //
  for (rtB.bestCol = 0; rtB.bestCol < 640; rtB.bestCol++) {
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 480; rtB.bestInlierNum++) {
      rtB.b_varargout_2[rtB.bestInlierNum + 480 * rtB.bestCol] =
        rtB.b_varargout_3[640 * rtB.bestInlierNum + rtB.bestCol];
    }
  }

  memcpy(&rtB.outputImage[614400], &rtB.b_varargout_2[0], 307200U * sizeof
         (uint8_T));

  // End of Math: '<S3>/Transpose2'

  // MATLAB Function: '<Root>/MATLAB Function'
  for (rtB.k = 0; rtB.k < 3; rtB.k++) {
    for (rtB.rtb_DataTypeConversion1_idx_0 = 0;
         rtB.rtb_DataTypeConversion1_idx_0 < 640;
         rtB.rtb_DataTypeConversion1_idx_0++) {
      for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 240; rtB.bestInlierNum++)
      {
        rtB.xtmp_tmp = (480 * rtB.rtb_DataTypeConversion1_idx_0 +
                        rtB.bestInlierNum) + 307200 * rtB.k;
        rtB.xtmp = rtB.outputImage[rtB.xtmp_tmp];
        rtB.bestCol = ((480 * rtB.rtb_DataTypeConversion1_idx_0 -
                        rtB.bestInlierNum) + 307200 * rtB.k) + 479;
        rtB.outputImage[rtB.xtmp_tmp] = rtB.outputImage[rtB.bestCol];
        rtB.outputImage[rtB.bestCol] = rtB.xtmp;
      }
    }

    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 320; rtB.bestInlierNum++) {
      for (rtB.rtb_DataTypeConversion1_idx_0 = 0;
           rtB.rtb_DataTypeConversion1_idx_0 < 480;
           rtB.rtb_DataTypeConversion1_idx_0++) {
        rtB.xtmp_tmp = (480 * rtB.bestInlierNum +
                        rtB.rtb_DataTypeConversion1_idx_0) + 307200 * rtB.k;
        rtB.xtmp = rtB.outputImage[rtB.xtmp_tmp];
        rtB.bestCol = ((639 - rtB.bestInlierNum) * 480 +
                       rtB.rtb_DataTypeConversion1_idx_0) + 307200 * rtB.k;
        rtB.outputImage[rtB.xtmp_tmp] = rtB.outputImage[rtB.bestCol];
        rtB.outputImage[rtB.bestCol] = rtB.xtmp;
      }
    }
  }

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion'
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 921600; rtB.bestInlierNum++) {
    rtB.ImageDataTypeConversion[rtB.bestInlierNum] = static_cast<real_T>
      (rtB.outputImage[rtB.bestInlierNum]) / 255.0;
  }

  // End of S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion'
  // temporary variables for in-place operation
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 307200; rtB.bestInlierNum++) {
    // S-Function (svipcolorconv): '<S4>/Color Space  Conversion' incorporates:
    //   S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion'

    // First get the min and max of the RGB triplet
    rtB.sum = rtB.ImageDataTypeConversion[rtB.bestInlierNum];
    rtB.ImageDataTypeConversion_c =
      rtB.ImageDataTypeConversion[rtB.bestInlierNum + 307200];
    if (rtB.sum > rtB.ImageDataTypeConversion_c) {
      rtB.ImageDataTypeConversion_b =
        rtB.ImageDataTypeConversion[rtB.bestInlierNum + 614400];
      if (rtB.ImageDataTypeConversion_c < rtB.ImageDataTypeConversion_b) {
        rtB.min = rtB.ImageDataTypeConversion_c;
      } else {
        rtB.min = rtB.ImageDataTypeConversion_b;
      }

      if (rtB.sum > rtB.ImageDataTypeConversion_b) {
        rtB.maxSum = rtB.sum;
      } else {
        rtB.maxSum = rtB.ImageDataTypeConversion_b;
      }
    } else {
      rtB.ImageDataTypeConversion_b =
        rtB.ImageDataTypeConversion[rtB.bestInlierNum + 614400];
      if (rtB.sum < rtB.ImageDataTypeConversion_b) {
        rtB.min = rtB.sum;
      } else {
        rtB.min = rtB.ImageDataTypeConversion_b;
      }

      if (rtB.ImageDataTypeConversion_c > rtB.ImageDataTypeConversion_b) {
        rtB.maxSum = rtB.ImageDataTypeConversion_c;
      } else {
        rtB.maxSum = rtB.ImageDataTypeConversion_b;
      }
    }

    rtB.s = rtB.maxSum - rtB.min;
    if (rtB.maxSum != 0.0) {
      rtB.min = rtB.s / rtB.maxSum;
    } else {
      rtB.min = 0.0;
    }

    if (rtB.s != 0.0) {
      if (rtB.sum == rtB.maxSum) {
        rtB.sum = (rtB.ImageDataTypeConversion_c - rtB.ImageDataTypeConversion_b)
          / rtB.s;
      } else if (rtB.ImageDataTypeConversion_c == rtB.maxSum) {
        rtB.sum = (rtB.ImageDataTypeConversion_b - rtB.sum) / rtB.s + 2.0;
      } else {
        rtB.sum = (rtB.sum - rtB.ImageDataTypeConversion_c) / rtB.s + 4.0;
      }

      rtB.sum /= 6.0;
      if (rtB.sum < 0.0) {
        rtB.sum++;
      }
    } else {
      rtB.sum = 0.0;
    }

    // assign the results
    rtB.ColorSpaceConversion[rtB.bestInlierNum] = rtB.sum;
    rtB.ColorSpaceConversion[rtB.bestInlierNum + 307200] = rtB.min;

    // S-Function (svipcolorconv): '<S4>/Color Space  Conversion'
    rtB.ColorSpaceConversion[rtB.bestInlierNum + 614400] = rtB.maxSum;

    // MATLAB Function: '<S4>/MATLAB Function7' incorporates:
    //   S-Function (svipcolorconv): '<S4>/Color Space  Conversion'

    rtB.V_Channel[rtB.bestInlierNum] = rtB.maxSum;
  }

  for (rtB.bestCol = 0; rtB.bestCol < 8; rtB.bestCol++) {
    // MATLAB Function: '<S4>/MATLAB Function1'
    rtB.pts1[rtB.bestCol] = tmp_a[rtB.bestCol];

    // MATLAB Function: '<S4>/MATLAB Function2'
    rtB.pts2[rtB.bestCol] = tmp_b[rtB.bestCol];
  }

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  memset(&rtB.EstimateGeometricTransformation[0], 0, 9U * sizeof(real_T));
  rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[0] = 0;
  rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[1] = 1;
  rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[2] = 2;
  rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[3] = 3;
  makeConstraintMatrix_Projective_D_D((const real_T *)&rtB.pts1[0], (const
    real_T *)&rtB.pts2[0], 4U, 4U,
    &rtDW.EstimateGeometricTransformation_DW_CONSTRT_ALL[0]);
  rtB.bestInlierNum = 0;
  while (rtB.bestInlierNum < 4) {
    rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[rtB.bestInlierNum] =
      static_cast<uint32_T>
      (rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[rtB.bestInlierNum]);
    rtB.bestInlierNum++;
  }

  rtB.bestCol = 0;
  normPts_D_D_o((const real_T *)&rtB.pts1[0], (const uint32_T *)
                &rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
                &rtDW.EstimateGeometricTransformation_DW_PTSNORM1[0],
                &rtB.scale1, &rtB.cents1[0]);
  normPts_D_D_o((const real_T *)&rtB.pts2[0], (const uint32_T *)
                &rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
                &rtDW.EstimateGeometricTransformation_DW_PTSNORM2[0],
                &rtB.scale2, &rtB.cents2[0]);
  makeConstraintMatrix_Projective_D_D((const real_T *)
    &rtDW.EstimateGeometricTransformation_DW_PTSNORM1[0], (const real_T *)
    &rtDW.EstimateGeometricTransformation_DW_PTSNORM2[0], 4U, 4U,
    &rtB.Constraint[0]);
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 8; rtB.bestInlierNum++) {
    rtB.JPVT[static_cast<uint32_T>(rtB.bestInlierNum)] = 0;
  }

  QRE_real_T_o(&rtB.Q[0], &rtB.Constraint[0], &rtB.E[0], &rtB.Qraux[0],
               &rtB.Work[0], &rtB.JPVT[0], &rtB.RV[0], 9, 8, true);
  rtB.maxSum = 0.0;
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 9; rtB.bestInlierNum++) {
    for (rtB.rtb_DataTypeConversion1_idx_0 = 0;
         rtB.rtb_DataTypeConversion1_idx_0 < 9;
         rtB.rtb_DataTypeConversion1_idx_0++) {
      if (static_cast<uint32_T>(rtB.bestInlierNum) != static_cast<uint32_T>
          (rtB.rtb_DataTypeConversion1_idx_0)) {
        rtB.sum = 0.0;
      } else {
        rtB.sum = -1.0;
      }

      for (rtB.k = 0; rtB.k < 8; rtB.k++) {
        rtB.idx_m = static_cast<uint32_T>(rtB.k) * 9U;
        rtB.sum += rtB.Q[rtB.idx_m + static_cast<uint32_T>(rtB.bestInlierNum)] *
          rtB.Q[rtB.idx_m + static_cast<uint32_T>
          (rtB.rtb_DataTypeConversion1_idx_0)];
      }

      rtB.RV[static_cast<uint32_T>(rtB.bestInlierNum) * 9U +
        static_cast<uint32_T>(rtB.rtb_DataTypeConversion1_idx_0)] = rtB.sum;
      if (!(rtB.sum >= 0.0)) {
        rtB.sum = -rtB.sum;
      }

      if (rtB.maxSum < rtB.sum) {
        rtB.maxSum = rtB.sum;
        rtB.bestCol = rtB.bestInlierNum;
      }
    }
  }

  rtB.rtb_DataTypeConversion1_idx_0 = static_cast<int32_T>(static_cast<uint32_T>
    (rtB.bestCol) * 9U);
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 9; rtB.bestInlierNum++) {
    rtB.tformCompact[static_cast<uint32_T>(rtB.bestInlierNum)] = rtB.RV[
      static_cast<uint32_T>(rtB.rtb_DataTypeConversion1_idx_0) +
      static_cast<uint32_T>(rtB.bestInlierNum)];
  }

  rtB.scale2 = 1.0 / rtB.scale2;
  rtB.maxSum = rtB.scale1 * rtB.scale2;
  rtB.tformCompact_c[6] = rtB.tformCompact[6] * rtB.scale1;
  rtB.tformCompact_c[7] = rtB.tformCompact[7] * rtB.scale1;
  rtB.tformCompact_c[8] = (rtB.tformCompact[8] - rtB.cents1[0] *
    rtB.tformCompact_c[6]) - rtB.cents1[1] * rtB.tformCompact_c[7];
  rtB.tformCompact_c[0] = rtB.tformCompact[0] * rtB.maxSum;
  rtB.tformCompact_c[1] = rtB.tformCompact[1] * rtB.maxSum;
  rtB.tformCompact_c[2] = ((rtB.cents2[0] * rtB.tformCompact_c[8] -
    rtB.tformCompact_c[0] * rtB.cents1[0]) - rtB.tformCompact_c[1] * rtB.cents1
    [1]) + rtB.tformCompact[2] * rtB.scale2;
  rtB.tformCompact_c[3] = rtB.tformCompact[3] * rtB.maxSum;
  rtB.tformCompact_c[4] = rtB.tformCompact[4] * rtB.maxSum;
  rtB.tformCompact_c[5] = ((rtB.cents2[1] * rtB.tformCompact_c[8] - rtB.cents1[0]
    * rtB.tformCompact_c[3]) - rtB.cents1[1] * rtB.tformCompact_c[4]) +
    rtB.tformCompact[5] * rtB.scale2;
  rtB.tformCompact_c[0] += rtB.cents2[0] * rtB.tformCompact_c[6];
  rtB.tformCompact_c[1] += rtB.cents2[0] * rtB.tformCompact_c[7];
  rtB.tformCompact_c[3] += rtB.cents2[1] * rtB.tformCompact_c[6];
  rtB.tformCompact_c[4] += rtB.cents2[1] * rtB.tformCompact_c[7];
  if (rtB.tformCompact_c[8U] != 0.0) {
    rtB.scale1 = 1.0 / rtB.tformCompact_c[8];
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 8; rtB.bestInlierNum++) {
      rtB.tformCompact_c[static_cast<uint32_T>(rtB.bestInlierNum)] *= rtB.scale1;
    }

    rtB.tformCompact_c[8] = 1.0;
    rtB.idx_m = 0U;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 4; rtB.bestInlierNum++) {
      rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_T>
        (rtB.bestInlierNum)] = 0.0;
      for (rtB.rtb_DataTypeConversion1_idx_0 = 0;
           rtB.rtb_DataTypeConversion1_idx_0 < 2;
           rtB.rtb_DataTypeConversion1_idx_0++) {
        rtB.scale1 = 0.0;
        for (rtB.k = 0; rtB.k < 9; rtB.k++) {
          rtB.scale1 +=
            rtDW.EstimateGeometricTransformation_DW_CONSTRT_ALL[rtB.idx_m +
            static_cast<uint32_T>(rtB.k)] * rtB.tformCompact_c
            [static_cast<uint32_T>(rtB.k)];
        }

        rtB.idx_m += 9U;
        rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_T>
          (rtB.bestInlierNum)] += rtB.scale1 * rtB.scale1;
      }
    }

    memcpy(&rtB.bestTFormCompact[0], &rtB.tformCompact_c[0], 9U * sizeof(real_T));
    rtB.bestInlierNum = 0;
    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[0] <=
        rtP.EstimateGeometricTransformation_distanceAlg) {
      rtB.bestInlierNum = 1;
    }

    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[1] <=
        rtP.EstimateGeometricTransformation_distanceAlg) {
      rtB.bestInlierNum = static_cast<int32_T>(static_cast<uint32_T>
        (rtB.bestInlierNum) + 1U);
    }

    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[2] <=
        rtP.EstimateGeometricTransformation_distanceAlg) {
      rtB.bestInlierNum = static_cast<int32_T>(static_cast<uint32_T>
        (rtB.bestInlierNum) + 1U);
    }

    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[3] <=
        rtP.EstimateGeometricTransformation_distanceAlg) {
      rtB.bestInlierNum = static_cast<int32_T>(static_cast<uint32_T>
        (rtB.bestInlierNum) + 1U);
    }
  } else {
    rtB.bestInlierNum = 0;
  }

  if (static_cast<uint32_T>(rtB.bestInlierNum) >= 4U) {
    rtB.EstimateGeometricTransformation[0] = rtB.bestTFormCompact[4];
    rtB.EstimateGeometricTransformation[1] = rtB.bestTFormCompact[3];
    rtB.EstimateGeometricTransformation[2] = rtB.bestTFormCompact[5];
    rtB.EstimateGeometricTransformation[3] = rtB.bestTFormCompact[1];
    rtB.EstimateGeometricTransformation[4] = rtB.bestTFormCompact[0];
    rtB.EstimateGeometricTransformation[5] = rtB.bestTFormCompact[2];
    rtB.EstimateGeometricTransformation[6] = rtB.bestTFormCompact[7];
    rtB.EstimateGeometricTransformation[7] = rtB.bestTFormCompact[6];
    rtB.EstimateGeometricTransformation[8] = rtB.bestTFormCompact[8];
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'

  // MATLAB Function: '<S4>/MATLAB Function8'
  for (rtB.bestCol = 0; rtB.bestCol < 307200; rtB.bestCol++) {
    rtB.V_Channel_m[rtB.bestCol] = (rtB.V_Channel[rtB.bestCol] > 0.5);
  }

  // End of MATLAB Function: '<S4>/MATLAB Function8'

  // MATLABSystem: '<S4>/Warp' incorporates:
  //   S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'

  Warp_stepImpl(&rtDW.obj_k, rtB.V_Channel_m,
                rtB.EstimateGeometricTransformation, rtB.DrawShapes1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.x_location = 320.0;
  emxInit_int32_T(&ii, 1);
  emxInit_int32_T(&jj, 1);

  // MATLAB Function: '<S2>/MATLAB Function1' incorporates:
  //   MATLABSystem: '<S4>/Warp'

  eml_find(rtB.DrawShapes1, ii, jj);
  memset(&rtB.rectangle_points[0], 0, 168U * sizeof(real_T));
  rtB.rectangle_points[40] = 0.0;
  rtB.rectangle_points[41] = 480.0;
  rtB.rectangle_points[82] = 456.0;
  rtB.rectangle_points[83] = 456.0;
  rtB.rectangle_points[124] = 160.0;
  rtB.rectangle_points[125] = 160.0;
  rtB.rectangle_points[166] = 24.0;
  rtB.rectangle_points[167] = 24.0;
  emxInit_boolean_T(&c, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.lastRow = c->size[0];
  c->size[0] = ii->size[0];
  emxEnsureCapacity_boolean_T(c, rtB.lastRow);
  rtB.xtmp_tmp = ii->size[0];
  emxInit_boolean_T(&d, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.lastRow = d->size[0];
  d->size[0] = ii->size[0];
  emxEnsureCapacity_boolean_T(d, rtB.lastRow);
  for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
    rtB.rtb_DataTypeConversion1_idx_0 = ii->data[rtB.bestCol];
    c->data[rtB.bestCol] = (rtB.rtb_DataTypeConversion1_idx_0 >= 456);
    d->data[rtB.bestCol] = (rtB.rtb_DataTypeConversion1_idx_0 < 480);
  }

  emxInit_boolean_T(&g, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.lastRow = g->size[0];
  g->size[0] = jj->size[0];
  emxEnsureCapacity_boolean_T(g, rtB.lastRow);
  rtB.xtmp_tmp = jj->size[0];
  for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
    g->data[rtB.bestCol] = (jj->data[rtB.bestCol] >= 480);
  }

  emxInit_boolean_T(&b_tmp, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.lastRow = b_tmp->size[0];
  b_tmp->size[0] = c->size[0];
  emxEnsureCapacity_boolean_T(b_tmp, rtB.lastRow);
  rtB.xtmp_tmp = c->size[0];
  for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
    b_tmp->data[rtB.bestCol] = (c->data[rtB.bestCol] && d->data[rtB.bestCol]);
  }

  emxInit_boolean_T(&b, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (b_tmp->size[0] == g->size[0]) {
    rtB.lastRow = b->size[0];
    b->size[0] = b_tmp->size[0];
    emxEnsureCapacity_boolean_T(b, rtB.lastRow);
    rtB.xtmp_tmp = b_tmp->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
      b->data[rtB.bestCol] = (b_tmp->data[rtB.bestCol] && g->data[rtB.bestCol]);
    }
  } else {
    and_o(b, b_tmp, g);
  }

  emxInit_boolean_T(&h, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.lastRow = h->size[0];
  h->size[0] = jj->size[0];
  emxEnsureCapacity_boolean_T(h, rtB.lastRow);
  rtB.xtmp_tmp = jj->size[0];
  for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
    h->data[rtB.bestCol] = (jj->data[rtB.bestCol] < 640);
  }

  emxInit_boolean_T(&tmp_0, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (b->size[0] == h->size[0]) {
    rtB.lastRow = tmp_0->size[0];
    tmp_0->size[0] = b->size[0];
    emxEnsureCapacity_boolean_T(tmp_0, rtB.lastRow);
    rtB.xtmp_tmp = b->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
      tmp_0->data[rtB.bestCol] = (b->data[rtB.bestCol] && h->data[rtB.bestCol]);
    }
  } else {
    and_o(tmp_0, b, h);
  }

  rtB.bestCol = tmp_0->size[0] - 1;
  rtB.xtmp_tmp = 0;
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
       rtB.bestInlierNum++) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    if (tmp_0->data[rtB.bestInlierNum]) {
      rtB.xtmp_tmp++;
    }
  }

  emxFree_boolean_T(&tmp_0);
  emxInit_int32_T(&tmp, 1);
  emxInit_boolean_T(&tmp_1, 1);
  emxInit_real_T(&jj_0, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (rtB.xtmp_tmp > 30) {
    rtB.k = 1;
    if (b->size[0] == h->size[0]) {
      rtB.lastRow = tmp_1->size[0];
      tmp_1->size[0] = b->size[0];
      emxEnsureCapacity_boolean_T(tmp_1, rtB.lastRow);
      rtB.xtmp_tmp = b->size[0];
      for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
        tmp_1->data[rtB.bestCol] = (b->data[rtB.bestCol] && h->data[rtB.bestCol]);
      }
    } else {
      and_o(tmp_1, b, h);
    }

    rtB.bestCol = tmp_1->size[0] - 1;
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_1->data[rtB.bestInlierNum]) {
        rtB.xtmp_tmp++;
      }
    }

    rtB.lastRow = tmp->size[0];
    tmp->size[0] = rtB.xtmp_tmp;
    emxEnsureCapacity_int32_T(tmp, rtB.lastRow);
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_1->data[rtB.bestInlierNum]) {
        tmp->data[rtB.xtmp_tmp] = rtB.bestInlierNum;
        rtB.xtmp_tmp++;
      }
    }

    rtB.lastRow = jj_0->size[0];
    jj_0->size[0] = tmp->size[0];
    emxEnsureCapacity_real_T(jj_0, rtB.lastRow);
    rtB.xtmp_tmp = tmp->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
      jj_0->data[rtB.bestCol] = jj->data[tmp->data[rtB.bestCol]];
    }

    rtB.scale1 = mean(jj_0);
    emxInit_boolean_T(&tmp_2, 1);
    if ((c->size[0] == g->size[0]) && ((c->size[0] == 1 ? g->size[0] : c->size[0])
         == h->size[0])) {
      rtB.lastRow = tmp_2->size[0];
      tmp_2->size[0] = c->size[0];
      emxEnsureCapacity_boolean_T(tmp_2, rtB.lastRow);
      rtB.xtmp_tmp = c->size[0];
      for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
        tmp_2->data[rtB.bestCol] = (c->data[rtB.bestCol] && d->data[rtB.bestCol]
          && g->data[rtB.bestCol] && h->data[rtB.bestCol]);
      }
    } else {
      binary_expand_op_2(tmp_2, c, d, g, h);
    }

    rtB.bestCol = tmp_2->size[0] - 1;
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_2->data[rtB.bestInlierNum]) {
        rtB.xtmp_tmp++;
      }
    }

    emxInit_int32_T(&tmp_7, 1);
    rtB.lastRow = tmp_7->size[0];
    tmp_7->size[0] = rtB.xtmp_tmp;
    emxEnsureCapacity_int32_T(tmp_7, rtB.lastRow);
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_2->data[rtB.bestInlierNum]) {
        tmp_7->data[rtB.xtmp_tmp] = rtB.bestInlierNum;
        rtB.xtmp_tmp++;
      }
    }

    emxFree_boolean_T(&tmp_2);
    rtB.lastRow = jj_0->size[0];
    jj_0->size[0] = tmp_7->size[0];
    emxEnsureCapacity_real_T(jj_0, rtB.lastRow);
    rtB.xtmp_tmp = tmp_7->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
      jj_0->data[rtB.bestCol] = ii->data[tmp_7->data[rtB.bestCol]];
    }

    emxFree_int32_T(&tmp_7);
    rtB.scale2 = maximum(jj_0);
  } else {
    rtB.k = 2;
    if ((b_tmp->size[0] == jj->size[0]) && ((b_tmp->size[0] == 1 ? jj->size[0] :
          b_tmp->size[0]) == jj->size[0])) {
      rtB.lastRow = tmp_1->size[0];
      tmp_1->size[0] = b_tmp->size[0];
      emxEnsureCapacity_boolean_T(tmp_1, rtB.lastRow);
      rtB.xtmp_tmp = b_tmp->size[0];
      for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
        rtB.rtb_DataTypeConversion1_idx_0 = jj->data[rtB.bestCol];
        tmp_1->data[rtB.bestCol] = (b_tmp->data[rtB.bestCol] &&
          (rtB.rtb_DataTypeConversion1_idx_0 >= 0) &&
          (rtB.rtb_DataTypeConversion1_idx_0 < 160));
      }
    } else {
      binary_expand_op_3(tmp_1, b_tmp, jj);
    }

    rtB.bestCol = tmp_1->size[0] - 1;
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_1->data[rtB.bestInlierNum]) {
        rtB.xtmp_tmp++;
      }
    }

    rtB.lastRow = tmp->size[0];
    tmp->size[0] = rtB.xtmp_tmp;
    emxEnsureCapacity_int32_T(tmp, rtB.lastRow);
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_1->data[rtB.bestInlierNum]) {
        tmp->data[rtB.xtmp_tmp] = rtB.bestInlierNum;
        rtB.xtmp_tmp++;
      }
    }

    rtB.lastRow = jj_0->size[0];
    jj_0->size[0] = tmp->size[0];
    emxEnsureCapacity_real_T(jj_0, rtB.lastRow);
    rtB.xtmp_tmp = tmp->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
      jj_0->data[rtB.bestCol] = jj->data[tmp->data[rtB.bestCol]];
    }

    rtB.scale1 = mean(jj_0);
    rtB.lastRow = jj_0->size[0];
    jj_0->size[0] = tmp->size[0];
    emxEnsureCapacity_real_T(jj_0, rtB.lastRow);
    rtB.xtmp_tmp = tmp->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
      jj_0->data[rtB.bestCol] = ii->data[tmp->data[rtB.bestCol]];
    }

    rtB.scale2 = maximum(jj_0);
  }

  emxFree_boolean_T(&tmp_1);
  emxFree_int32_T(&tmp);
  emxFree_boolean_T(&b_tmp);
  emxFree_boolean_T(&h);
  emxFree_boolean_T(&g);
  emxFree_boolean_T(&b);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.maxSum = rtB.scale1;
  emxInit_real_T(&c_tmp, 1);
  emxInit_boolean_T(&tmp_3, 1);
  emxInit_boolean_T(&tmp_4, 1);
  emxInit_boolean_T(&tmp_5, 1);
  emxInit_boolean_T(&tmp_6, 1);
  emxInit_int32_T(&tmp_8, 1);
  emxInit_int32_T(&tmp_9, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 20; rtB.bestInlierNum++) {
    if (rtB.k == 1) {
      rtB.win_y_low = rtB.scale2 - ((static_cast<real_T>(rtB.bestInlierNum) +
        1.0) + 1.0) * 24.0;
      rtB.sum = rtB.scale2 - (static_cast<real_T>(rtB.bestInlierNum) + 1.0) *
        24.0;
      rtB.rectangle_points[rtB.bestInlierNum] = rtB.scale1 - 40.0;
      rtB.rectangle_points[rtB.bestInlierNum + 42] = rtB.win_y_low;
      rtB.rectangle_points[rtB.bestInlierNum + 84] = 80.0;
      rtB.rectangle_points[rtB.bestInlierNum + 126] = 24.0;
      rtB.rectangle_points[rtB.bestInlierNum + 20] = (rtB.scale1 - 40.0) - 520.0;
      rtB.rectangle_points[rtB.bestInlierNum + 62] = rtB.win_y_low;
      rtB.rectangle_points[rtB.bestInlierNum + 104] = 80.0;
      rtB.rectangle_points[rtB.bestInlierNum + 146] = 24.0;
      rtB.rtb_DataTypeConversion1_idx_0 = ii->size[0];
      rtB.lastRow = jj_0->size[0];
      jj_0->size[0] = ii->size[0];
      emxEnsureCapacity_real_T(jj_0, rtB.lastRow);
      for (rtB.bestCol = 0; rtB.bestCol < rtB.rtb_DataTypeConversion1_idx_0;
           rtB.bestCol++) {
        jj_0->data[rtB.bestCol] = ii->data[rtB.bestCol];
      }

      rtB.rtb_DataTypeConversion1_idx_0 = jj->size[0];
      rtB.lastRow = c_tmp->size[0];
      c_tmp->size[0] = jj->size[0];
      emxEnsureCapacity_real_T(c_tmp, rtB.lastRow);
      for (rtB.bestCol = 0; rtB.bestCol < rtB.rtb_DataTypeConversion1_idx_0;
           rtB.bestCol++) {
        c_tmp->data[rtB.bestCol] = jj->data[rtB.bestCol];
      }

      if (jj_0->size[0] == c_tmp->size[0]) {
        rtB.lastRow = c->size[0];
        c->size[0] = jj_0->size[0];
        emxEnsureCapacity_boolean_T(c, rtB.lastRow);
        rtB.xtmp_tmp = jj_0->size[0];
        for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
          rtB.rtb_DataTypeConversion1_idx_0 = static_cast<int32_T>(jj_0->
            data[rtB.bestCol]);
          c->data[rtB.bestCol] = ((rtB.rtb_DataTypeConversion1_idx_0 >=
            rtB.win_y_low) && (rtB.rtb_DataTypeConversion1_idx_0 < rtB.sum) &&
            (c_tmp->data[rtB.bestCol] >= rtB.scale1 - 40.0));
        }
      } else {
        binary_expand_op_1(c, jj_0, rtB.win_y_low, rtB.sum, c_tmp, rtB.scale1);
      }

      rtB.lastRow = d->size[0];
      d->size[0] = c_tmp->size[0];
      emxEnsureCapacity_boolean_T(d, rtB.lastRow);
      rtB.xtmp_tmp = c_tmp->size[0];
      for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
        d->data[rtB.bestCol] = (c_tmp->data[rtB.bestCol] < rtB.scale1 + 40.0);
      }

      if (c->size[0] == d->size[0]) {
        rtB.lastRow = tmp_4->size[0];
        tmp_4->size[0] = c->size[0];
        emxEnsureCapacity_boolean_T(tmp_4, rtB.lastRow);
        rtB.xtmp_tmp = c->size[0];
        for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
          tmp_4->data[rtB.bestCol] = (c->data[rtB.bestCol] && d->
            data[rtB.bestCol]);
        }
      } else {
        and_o(tmp_4, c, d);
      }

      rtB.bestCol = tmp_4->size[0] - 1;
      rtB.xtmp_tmp = 0;
      for (rtB.rtb_DataTypeConversion1_idx_0 = 0;
           rtB.rtb_DataTypeConversion1_idx_0 <= rtB.bestCol;
           rtB.rtb_DataTypeConversion1_idx_0++) {
        if (tmp_4->data[rtB.rtb_DataTypeConversion1_idx_0]) {
          rtB.xtmp_tmp++;
        }
      }

      if (rtB.xtmp_tmp > 30) {
        if (c->size[0] == d->size[0]) {
          rtB.lastRow = tmp_6->size[0];
          tmp_6->size[0] = c->size[0];
          emxEnsureCapacity_boolean_T(tmp_6, rtB.lastRow);
          rtB.xtmp_tmp = c->size[0];
          for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
            tmp_6->data[rtB.bestCol] = (c->data[rtB.bestCol] && d->
              data[rtB.bestCol]);
          }
        } else {
          and_o(tmp_6, c, d);
        }

        rtB.bestCol = tmp_6->size[0] - 1;
        rtB.xtmp_tmp = 0;
        for (rtB.rtb_DataTypeConversion1_idx_0 = 0;
             rtB.rtb_DataTypeConversion1_idx_0 <= rtB.bestCol;
             rtB.rtb_DataTypeConversion1_idx_0++) {
          if (tmp_6->data[rtB.rtb_DataTypeConversion1_idx_0]) {
            rtB.xtmp_tmp++;
          }
        }

        rtB.lastRow = tmp_9->size[0];
        tmp_9->size[0] = rtB.xtmp_tmp;
        emxEnsureCapacity_int32_T(tmp_9, rtB.lastRow);
        rtB.xtmp_tmp = 0;
        for (rtB.rtb_DataTypeConversion1_idx_0 = 0;
             rtB.rtb_DataTypeConversion1_idx_0 <= rtB.bestCol;
             rtB.rtb_DataTypeConversion1_idx_0++) {
          if (tmp_6->data[rtB.rtb_DataTypeConversion1_idx_0]) {
            tmp_9->data[rtB.xtmp_tmp] = rtB.rtb_DataTypeConversion1_idx_0;
            rtB.xtmp_tmp++;
          }
        }

        rtB.xtmp_tmp = tmp_9->size[0];
        rtB.lastRow = jj_0->size[0];
        jj_0->size[0] = tmp_9->size[0];
        emxEnsureCapacity_real_T(jj_0, rtB.lastRow);
        for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
          jj_0->data[rtB.bestCol] = jj->data[tmp_9->data[rtB.bestCol]];
        }

        rtB.scale1 = mean(jj_0);
      }

      if ((rtB.win_y_low > 300.0) && (rtB.win_y_low < 340.0)) {
        rtB.x_location = rtB.scale1 - 220.0;
      }
    } else {
      rtB.win_y_low = rtB.scale2 - ((static_cast<real_T>(rtB.bestInlierNum) +
        1.0) + 1.0) * 24.0;
      rtB.sum = rtB.scale2 - (static_cast<real_T>(rtB.bestInlierNum) + 1.0) *
        24.0;
      rtB.rectangle_points[rtB.bestInlierNum] = rtB.scale1 - 40.0;
      rtB.rectangle_points[rtB.bestInlierNum + 42] = rtB.win_y_low;
      rtB.rectangle_points[rtB.bestInlierNum + 84] = 80.0;
      rtB.rectangle_points[rtB.bestInlierNum + 126] = 24.0;
      rtB.rectangle_points[rtB.bestInlierNum + 20] = (rtB.scale1 - 40.0) + 520.0;
      rtB.rectangle_points[rtB.bestInlierNum + 62] = rtB.win_y_low;
      rtB.rectangle_points[rtB.bestInlierNum + 104] = 80.0;
      rtB.rectangle_points[rtB.bestInlierNum + 146] = 24.0;
      rtB.rtb_DataTypeConversion1_idx_0 = ii->size[0];
      if (ii->size[0] == jj->size[0]) {
        rtB.lastRow = c->size[0];
        c->size[0] = ii->size[0];
        emxEnsureCapacity_boolean_T(c, rtB.lastRow);
        for (rtB.bestCol = 0; rtB.bestCol < rtB.rtb_DataTypeConversion1_idx_0;
             rtB.bestCol++) {
          rtB.xtmp_tmp = ii->data[rtB.bestCol];
          c->data[rtB.bestCol] = ((rtB.xtmp_tmp >= rtB.win_y_low) &&
            (rtB.xtmp_tmp < rtB.sum) && (jj->data[rtB.bestCol] >= rtB.scale1 -
            40.0));
        }
      } else {
        binary_expand_op(c, ii, rtB.win_y_low, rtB.sum, jj, rtB.scale1);
      }

      rtB.rtb_DataTypeConversion1_idx_0 = jj->size[0];
      rtB.lastRow = d->size[0];
      d->size[0] = jj->size[0];
      emxEnsureCapacity_boolean_T(d, rtB.lastRow);
      for (rtB.bestCol = 0; rtB.bestCol < rtB.rtb_DataTypeConversion1_idx_0;
           rtB.bestCol++) {
        d->data[rtB.bestCol] = (jj->data[rtB.bestCol] < rtB.scale1 + 40.0);
      }

      if (c->size[0] == d->size[0]) {
        rtB.lastRow = tmp_3->size[0];
        tmp_3->size[0] = c->size[0];
        emxEnsureCapacity_boolean_T(tmp_3, rtB.lastRow);
        rtB.xtmp_tmp = c->size[0];
        for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
          tmp_3->data[rtB.bestCol] = (c->data[rtB.bestCol] && d->
            data[rtB.bestCol]);
        }
      } else {
        and_o(tmp_3, c, d);
      }

      rtB.bestCol = tmp_3->size[0] - 1;
      rtB.xtmp_tmp = 0;
      for (rtB.rtb_DataTypeConversion1_idx_0 = 0;
           rtB.rtb_DataTypeConversion1_idx_0 <= rtB.bestCol;
           rtB.rtb_DataTypeConversion1_idx_0++) {
        if (tmp_3->data[rtB.rtb_DataTypeConversion1_idx_0]) {
          rtB.xtmp_tmp++;
        }
      }

      if (rtB.xtmp_tmp > 30) {
        if (c->size[0] == d->size[0]) {
          rtB.lastRow = tmp_5->size[0];
          tmp_5->size[0] = c->size[0];
          emxEnsureCapacity_boolean_T(tmp_5, rtB.lastRow);
          rtB.xtmp_tmp = c->size[0];
          for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
            tmp_5->data[rtB.bestCol] = (c->data[rtB.bestCol] && d->
              data[rtB.bestCol]);
          }
        } else {
          and_o(tmp_5, c, d);
        }

        rtB.bestCol = tmp_5->size[0] - 1;
        rtB.xtmp_tmp = 0;
        for (rtB.rtb_DataTypeConversion1_idx_0 = 0;
             rtB.rtb_DataTypeConversion1_idx_0 <= rtB.bestCol;
             rtB.rtb_DataTypeConversion1_idx_0++) {
          if (tmp_5->data[rtB.rtb_DataTypeConversion1_idx_0]) {
            rtB.xtmp_tmp++;
          }
        }

        rtB.lastRow = tmp_8->size[0];
        tmp_8->size[0] = rtB.xtmp_tmp;
        emxEnsureCapacity_int32_T(tmp_8, rtB.lastRow);
        rtB.xtmp_tmp = 0;
        for (rtB.rtb_DataTypeConversion1_idx_0 = 0;
             rtB.rtb_DataTypeConversion1_idx_0 <= rtB.bestCol;
             rtB.rtb_DataTypeConversion1_idx_0++) {
          if (tmp_5->data[rtB.rtb_DataTypeConversion1_idx_0]) {
            tmp_8->data[rtB.xtmp_tmp] = rtB.rtb_DataTypeConversion1_idx_0;
            rtB.xtmp_tmp++;
          }
        }

        rtB.xtmp_tmp = tmp_8->size[0];
        rtB.lastRow = jj_0->size[0];
        jj_0->size[0] = tmp_8->size[0];
        emxEnsureCapacity_real_T(jj_0, rtB.lastRow);
        for (rtB.bestCol = 0; rtB.bestCol < rtB.xtmp_tmp; rtB.bestCol++) {
          jj_0->data[rtB.bestCol] = jj->data[tmp_8->data[rtB.bestCol]];
        }

        rtB.scale1 = mean(jj_0);
      }

      if ((rtB.win_y_low > 300.0) && (rtB.win_y_low < 340.0)) {
        rtB.x_location = rtB.scale1 + 290.0;
      }
    }

    rtB.win_y_low = rtB.x_location;
    rtB.error = 340.0 - rtB.x_location;
  }

  emxFree_real_T(&jj_0);
  emxFree_int32_T(&tmp_9);
  emxFree_int32_T(&tmp_8);
  emxFree_boolean_T(&tmp_6);
  emxFree_boolean_T(&tmp_5);
  emxFree_boolean_T(&tmp_4);
  emxFree_boolean_T(&tmp_3);
  emxFree_real_T(&c_tmp);
  emxFree_boolean_T(&d);
  emxFree_boolean_T(&c);
  emxFree_int32_T(&jj);
  emxFree_int32_T(&ii);

  // DataTypeConversion: '<S2>/Data Type Conversion3'
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 168; rtB.bestInlierNum++) {
    rtB.DataTypeConversion3[rtB.bestInlierNum] = static_cast<int32_T>(floor
      (rtB.rectangle_points[rtB.bestInlierNum]));
  }

  // End of DataTypeConversion: '<S2>/Data Type Conversion3'

  // S-Function (svipdrawshapes): '<S2>/Draw Shapes2' incorporates:
  //   DataTypeConversion: '<S2>/Data Type Conversion3'
  //   S-Function (svipdrawshapes): '<S2>/Draw Shapes3'

  // Update view port.
  // Draw all rectangles.
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 42; rtB.bestInlierNum++) {
    // DataTypeConversion: '<S2>/Data Type Conversion3'
    rtB.k = rtB.DataTypeConversion3[rtB.bestInlierNum + 42];
    rtB.bestCol = rtB.k - 1;

    // DataTypeConversion: '<S2>/Data Type Conversion3'
    rtB.rtb_DataTypeConversion1_idx_0 =
      rtB.DataTypeConversion3[rtB.bestInlierNum];
    rtB.xtmp_tmp = rtB.rtb_DataTypeConversion1_idx_0 - 1;
    rtB.lastRow = (rtB.DataTypeConversion3[rtB.bestInlierNum + 126] + rtB.k) - 2;
    rtB.lastCol = (rtB.DataTypeConversion3[rtB.bestInlierNum + 84] +
                   rtB.rtb_DataTypeConversion1_idx_0) - 2;
    if (rtP.DrawShapes2_lineWidth > 1) {
      rtB.halfLineWidth = rtP.DrawShapes2_lineWidth >> 1;
      rtB.bestCol = (rtB.k - rtB.halfLineWidth) - 1;
      rtB.lastRow += rtB.halfLineWidth;
      rtB.xtmp_tmp = (rtB.rtb_DataTypeConversion1_idx_0 - rtB.halfLineWidth) - 1;
      rtB.lastCol += rtB.halfLineWidth;
    }

    if ((rtB.bestCol <= rtB.lastRow) && (rtB.xtmp_tmp <= rtB.lastCol)) {
      rtB.rtb_DataTypeConversion1_idx_0 = 0;
      while (rtB.rtb_DataTypeConversion1_idx_0 < rtP.DrawShapes2_lineWidth) {
        rtB.line_idx_0_tmp = rtB.bestCol + rtB.rtb_DataTypeConversion1_idx_0;
        rtB.DrawShapes1_DW_FillColorAdd = false;

        // Find the visible portion of a line.
        rtB.visited1 = false;
        rtB.visited2 = false;
        rtB.done = false;
        rtB.halfLineWidth = rtB.line_idx_0_tmp;
        rtB.line_idx_1 = rtB.xtmp_tmp;
        rtB.line_idx_2 = rtB.line_idx_0_tmp;
        rtB.line_idx_3 = rtB.lastCol;
        while (!rtB.done) {
          rtB.OutCode1 = 0;
          rtB.OutCode2 = 0;

          // Determine viewport violations.
          if (rtB.halfLineWidth < 0) {
            rtB.OutCode1 = 4;
          } else if (rtB.halfLineWidth > 479) {
            rtB.OutCode1 = 8;
          }

          if (rtB.line_idx_2 < 0) {
            rtB.OutCode2 = 4;
          } else if (rtB.line_idx_2 > 479) {
            rtB.OutCode2 = 8;
          }

          if (rtB.line_idx_1 < 0) {
            rtB.OutCode1 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode1) | 1U);
          } else if (rtB.line_idx_1 > 639) {
            rtB.OutCode1 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode1) | 2U);
          }

          if (rtB.line_idx_3 < 0) {
            rtB.OutCode2 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode2) | 1U);
          } else if (rtB.line_idx_3 > 639) {
            rtB.OutCode2 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode2) | 2U);
          }

          if ((static_cast<uint32_T>(rtB.OutCode1) | static_cast<uint32_T>
               (rtB.OutCode2)) == 0U) {
            // Line falls completely within bounds.
            rtB.done = true;
            rtB.DrawShapes1_DW_FillColorAdd = true;
          } else if ((static_cast<uint32_T>(rtB.OutCode1) & static_cast<uint32_T>
                      (rtB.OutCode2)) != 0U) {
            // Line falls completely out of bounds.
            rtB.done = true;
            rtB.DrawShapes1_DW_FillColorAdd = false;
          } else if (static_cast<uint32_T>(rtB.OutCode1) != 0U) {
            // Clip 1st point; if it's in-bounds, clip 2nd point.
            if (rtB.visited1) {
              rtB.halfLineWidth = rtB.line_idx_0_tmp;
              rtB.line_idx_1 = rtB.xtmp_tmp;
            }

            rtB.k = rtB.line_idx_2 - rtB.halfLineWidth;
            rtB.dc = rtB.line_idx_3 - rtB.line_idx_1;
            if ((rtB.k > 1073741824) || (rtB.k < -1073741824) || ((rtB.dc >
                  1073741824) || (rtB.dc < -1073741824))) {
              // Possible Inf or Nan.
              rtB.done = true;
              rtB.DrawShapes1_DW_FillColorAdd = false;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 4U) != 0U) {
              // Violated RMin.
              rtB.OutCode1 = -rtB.halfLineWidth * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_1 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_1 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.halfLineWidth = 0;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 8U) != 0U) {
              // Violated RMax.
              rtB.OutCode1 = (479 - rtB.halfLineWidth) * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_1 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_1 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.halfLineWidth = 479;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 1U) != 0U) {
              // Violated CMin.
              rtB.OutCode1 = -rtB.line_idx_1 * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.halfLineWidth += (div_nde_s32_floor(rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              } else {
                rtB.halfLineWidth -= (div_nde_s32_floor(-rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              }

              rtB.line_idx_1 = 0;
              rtB.visited1 = true;
            } else {
              // Violated CMax.
              rtB.OutCode1 = (639 - rtB.line_idx_1) * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.halfLineWidth += (div_nde_s32_floor(rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              } else {
                rtB.halfLineWidth -= (div_nde_s32_floor(-rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              }

              rtB.line_idx_1 = 639;
              rtB.visited1 = true;
            }
          } else {
            // Clip the 2nd point.
            if (rtB.visited2) {
              rtB.line_idx_2 = rtB.line_idx_0_tmp;
              rtB.line_idx_3 = rtB.lastCol;
            }

            rtB.k = rtB.line_idx_2 - rtB.halfLineWidth;
            rtB.dc = rtB.line_idx_3 - rtB.line_idx_1;
            if ((rtB.k > 1073741824) || (rtB.k < -1073741824) || ((rtB.dc >
                  1073741824) || (rtB.dc < -1073741824))) {
              // Possible Inf or Nan.
              rtB.done = true;
              rtB.DrawShapes1_DW_FillColorAdd = false;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 4U) != 0U) {
              // Violated RMin.
              rtB.OutCode1 = -rtB.line_idx_2 * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_3 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_3 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.line_idx_2 = 0;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 8U) != 0U) {
              // Violated RMax.
              rtB.OutCode1 = (479 - rtB.line_idx_2) * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_3 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_3 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.line_idx_2 = 479;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 1U) != 0U) {
              // Violated CMin.
              rtB.OutCode1 = -rtB.line_idx_3 * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.line_idx_2 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              } else {
                rtB.line_idx_2 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              }

              rtB.line_idx_3 = 0;
              rtB.visited2 = true;
            } else {
              // Violated CMax.
              rtB.OutCode1 = (639 - rtB.line_idx_3) * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.line_idx_2 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              } else {
                rtB.line_idx_2 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              }

              rtB.line_idx_3 = 639;
              rtB.visited2 = true;
            }
          }
        }

        if (rtB.DrawShapes1_DW_FillColorAdd) {
          rtB.k = rtB.line_idx_1 * 480 + rtB.halfLineWidth;
          while (rtB.line_idx_1 <= rtB.line_idx_3) {
            rtB.DrawShapes1[rtB.k] = true;
            rtB.k += 480;
            rtB.line_idx_1++;
          }
        }

        rtB.line_idx_0_tmp = rtB.xtmp_tmp + rtB.rtb_DataTypeConversion1_idx_0;
        rtB.DrawShapes1_DW_FillColorAdd = false;

        // Find the visible portion of a line.
        rtB.visited1 = false;
        rtB.visited2 = false;
        rtB.done = false;
        rtB.halfLineWidth = rtB.bestCol;
        rtB.line_idx_1 = rtB.line_idx_0_tmp;
        rtB.line_idx_2 = rtB.lastRow;
        rtB.line_idx_3 = rtB.line_idx_0_tmp;
        while (!rtB.done) {
          rtB.OutCode1 = 0;
          rtB.OutCode2 = 0;

          // Determine viewport violations.
          if (rtB.halfLineWidth < 0) {
            rtB.OutCode1 = 4;
          } else if (rtB.halfLineWidth > 479) {
            rtB.OutCode1 = 8;
          }

          if (rtB.line_idx_2 < 0) {
            rtB.OutCode2 = 4;
          } else if (rtB.line_idx_2 > 479) {
            rtB.OutCode2 = 8;
          }

          if (rtB.line_idx_1 < 0) {
            rtB.OutCode1 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode1) | 1U);
          } else if (rtB.line_idx_1 > 639) {
            rtB.OutCode1 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode1) | 2U);
          }

          if (rtB.line_idx_3 < 0) {
            rtB.OutCode2 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode2) | 1U);
          } else if (rtB.line_idx_3 > 639) {
            rtB.OutCode2 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode2) | 2U);
          }

          if ((static_cast<uint32_T>(rtB.OutCode1) | static_cast<uint32_T>
               (rtB.OutCode2)) == 0U) {
            // Line falls completely within bounds.
            rtB.done = true;
            rtB.DrawShapes1_DW_FillColorAdd = true;
          } else if ((static_cast<uint32_T>(rtB.OutCode1) & static_cast<uint32_T>
                      (rtB.OutCode2)) != 0U) {
            // Line falls completely out of bounds.
            rtB.done = true;
            rtB.DrawShapes1_DW_FillColorAdd = false;
          } else if (static_cast<uint32_T>(rtB.OutCode1) != 0U) {
            // Clip 1st point; if it's in-bounds, clip 2nd point.
            if (rtB.visited1) {
              rtB.halfLineWidth = rtB.bestCol;
              rtB.line_idx_1 = rtB.line_idx_0_tmp;
            }

            rtB.k = rtB.line_idx_2 - rtB.halfLineWidth;
            rtB.dc = rtB.line_idx_3 - rtB.line_idx_1;
            if ((rtB.k > 1073741824) || (rtB.k < -1073741824) || ((rtB.dc >
                  1073741824) || (rtB.dc < -1073741824))) {
              // Possible Inf or Nan.
              rtB.done = true;
              rtB.DrawShapes1_DW_FillColorAdd = false;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 4U) != 0U) {
              // Violated RMin.
              rtB.OutCode1 = -rtB.halfLineWidth * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_1 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_1 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.halfLineWidth = 0;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 8U) != 0U) {
              // Violated RMax.
              rtB.OutCode1 = (479 - rtB.halfLineWidth) * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_1 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_1 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.halfLineWidth = 479;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 1U) != 0U) {
              // Violated CMin.
              rtB.OutCode1 = -rtB.line_idx_1 * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.halfLineWidth += (div_nde_s32_floor(rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              } else {
                rtB.halfLineWidth -= (div_nde_s32_floor(-rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              }

              rtB.line_idx_1 = 0;
              rtB.visited1 = true;
            } else {
              // Violated CMax.
              rtB.OutCode1 = (639 - rtB.line_idx_1) * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.halfLineWidth += (div_nde_s32_floor(rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              } else {
                rtB.halfLineWidth -= (div_nde_s32_floor(-rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              }

              rtB.line_idx_1 = 639;
              rtB.visited1 = true;
            }
          } else {
            // Clip the 2nd point.
            if (rtB.visited2) {
              rtB.line_idx_2 = rtB.lastRow;
              rtB.line_idx_3 = rtB.line_idx_0_tmp;
            }

            rtB.k = rtB.line_idx_2 - rtB.halfLineWidth;
            rtB.dc = rtB.line_idx_3 - rtB.line_idx_1;
            if ((rtB.k > 1073741824) || (rtB.k < -1073741824) || ((rtB.dc >
                  1073741824) || (rtB.dc < -1073741824))) {
              // Possible Inf or Nan.
              rtB.done = true;
              rtB.DrawShapes1_DW_FillColorAdd = false;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 4U) != 0U) {
              // Violated RMin.
              rtB.OutCode1 = -rtB.line_idx_2 * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_3 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_3 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.line_idx_2 = 0;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 8U) != 0U) {
              // Violated RMax.
              rtB.OutCode1 = (479 - rtB.line_idx_2) * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_3 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_3 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.line_idx_2 = 479;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 1U) != 0U) {
              // Violated CMin.
              rtB.OutCode1 = -rtB.line_idx_3 * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.line_idx_2 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              } else {
                rtB.line_idx_2 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              }

              rtB.line_idx_3 = 0;
              rtB.visited2 = true;
            } else {
              // Violated CMax.
              rtB.OutCode1 = (639 - rtB.line_idx_3) * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.line_idx_2 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              } else {
                rtB.line_idx_2 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              }

              rtB.line_idx_3 = 639;
              rtB.visited2 = true;
            }
          }
        }

        if (rtB.DrawShapes1_DW_FillColorAdd) {
          rtB.k = rtB.line_idx_1 * 480 + rtB.halfLineWidth;
          while (rtB.halfLineWidth <= rtB.line_idx_2) {
            rtB.DrawShapes1[rtB.k] = true;
            rtB.k++;
            rtB.halfLineWidth++;
          }
        }

        rtB.line_idx_0_tmp = rtB.lastRow - rtB.rtb_DataTypeConversion1_idx_0;
        rtB.DrawShapes1_DW_FillColorAdd = false;

        // Find the visible portion of a line.
        rtB.visited1 = false;
        rtB.visited2 = false;
        rtB.done = false;
        rtB.halfLineWidth = rtB.line_idx_0_tmp;
        rtB.line_idx_1 = rtB.xtmp_tmp;
        rtB.line_idx_2 = rtB.line_idx_0_tmp;
        rtB.line_idx_3 = rtB.lastCol;
        while (!rtB.done) {
          rtB.OutCode1 = 0;
          rtB.OutCode2 = 0;

          // Determine viewport violations.
          if (rtB.halfLineWidth < 0) {
            rtB.OutCode1 = 4;
          } else if (rtB.halfLineWidth > 479) {
            rtB.OutCode1 = 8;
          }

          if (rtB.line_idx_2 < 0) {
            rtB.OutCode2 = 4;
          } else if (rtB.line_idx_2 > 479) {
            rtB.OutCode2 = 8;
          }

          if (rtB.line_idx_1 < 0) {
            rtB.OutCode1 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode1) | 1U);
          } else if (rtB.line_idx_1 > 639) {
            rtB.OutCode1 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode1) | 2U);
          }

          if (rtB.line_idx_3 < 0) {
            rtB.OutCode2 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode2) | 1U);
          } else if (rtB.line_idx_3 > 639) {
            rtB.OutCode2 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode2) | 2U);
          }

          if ((static_cast<uint32_T>(rtB.OutCode1) | static_cast<uint32_T>
               (rtB.OutCode2)) == 0U) {
            // Line falls completely within bounds.
            rtB.done = true;
            rtB.DrawShapes1_DW_FillColorAdd = true;
          } else if ((static_cast<uint32_T>(rtB.OutCode1) & static_cast<uint32_T>
                      (rtB.OutCode2)) != 0U) {
            // Line falls completely out of bounds.
            rtB.done = true;
            rtB.DrawShapes1_DW_FillColorAdd = false;
          } else if (static_cast<uint32_T>(rtB.OutCode1) != 0U) {
            // Clip 1st point; if it's in-bounds, clip 2nd point.
            if (rtB.visited1) {
              rtB.halfLineWidth = rtB.line_idx_0_tmp;
              rtB.line_idx_1 = rtB.xtmp_tmp;
            }

            rtB.k = rtB.line_idx_2 - rtB.halfLineWidth;
            rtB.dc = rtB.line_idx_3 - rtB.line_idx_1;
            if ((rtB.k > 1073741824) || (rtB.k < -1073741824) || ((rtB.dc >
                  1073741824) || (rtB.dc < -1073741824))) {
              // Possible Inf or Nan.
              rtB.done = true;
              rtB.DrawShapes1_DW_FillColorAdd = false;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 4U) != 0U) {
              // Violated RMin.
              rtB.OutCode1 = -rtB.halfLineWidth * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_1 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_1 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.halfLineWidth = 0;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 8U) != 0U) {
              // Violated RMax.
              rtB.OutCode1 = (479 - rtB.halfLineWidth) * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_1 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_1 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.halfLineWidth = 479;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 1U) != 0U) {
              // Violated CMin.
              rtB.OutCode1 = -rtB.line_idx_1 * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.halfLineWidth += (div_nde_s32_floor(rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              } else {
                rtB.halfLineWidth -= (div_nde_s32_floor(-rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              }

              rtB.line_idx_1 = 0;
              rtB.visited1 = true;
            } else {
              // Violated CMax.
              rtB.OutCode1 = (639 - rtB.line_idx_1) * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.halfLineWidth += (div_nde_s32_floor(rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              } else {
                rtB.halfLineWidth -= (div_nde_s32_floor(-rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              }

              rtB.line_idx_1 = 639;
              rtB.visited1 = true;
            }
          } else {
            // Clip the 2nd point.
            if (rtB.visited2) {
              rtB.line_idx_2 = rtB.line_idx_0_tmp;
              rtB.line_idx_3 = rtB.lastCol;
            }

            rtB.k = rtB.line_idx_2 - rtB.halfLineWidth;
            rtB.dc = rtB.line_idx_3 - rtB.line_idx_1;
            if ((rtB.k > 1073741824) || (rtB.k < -1073741824) || ((rtB.dc >
                  1073741824) || (rtB.dc < -1073741824))) {
              // Possible Inf or Nan.
              rtB.done = true;
              rtB.DrawShapes1_DW_FillColorAdd = false;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 4U) != 0U) {
              // Violated RMin.
              rtB.OutCode1 = -rtB.line_idx_2 * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_3 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_3 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.line_idx_2 = 0;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 8U) != 0U) {
              // Violated RMax.
              rtB.OutCode1 = (479 - rtB.line_idx_2) * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_3 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_3 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.line_idx_2 = 479;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 1U) != 0U) {
              // Violated CMin.
              rtB.OutCode1 = -rtB.line_idx_3 * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.line_idx_2 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              } else {
                rtB.line_idx_2 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              }

              rtB.line_idx_3 = 0;
              rtB.visited2 = true;
            } else {
              // Violated CMax.
              rtB.OutCode1 = (639 - rtB.line_idx_3) * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.line_idx_2 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              } else {
                rtB.line_idx_2 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              }

              rtB.line_idx_3 = 639;
              rtB.visited2 = true;
            }
          }
        }

        if (rtB.DrawShapes1_DW_FillColorAdd) {
          rtB.k = rtB.line_idx_1 * 480 + rtB.halfLineWidth;
          while (rtB.line_idx_1 <= rtB.line_idx_3) {
            rtB.DrawShapes1[rtB.k] = true;
            rtB.k += 480;
            rtB.line_idx_1++;
          }
        }

        rtB.line_idx_0_tmp = rtB.lastCol - rtB.rtb_DataTypeConversion1_idx_0;
        rtB.DrawShapes1_DW_FillColorAdd = false;

        // Find the visible portion of a line.
        rtB.visited1 = false;
        rtB.visited2 = false;
        rtB.done = false;
        rtB.halfLineWidth = rtB.bestCol;
        rtB.line_idx_1 = rtB.line_idx_0_tmp;
        rtB.line_idx_2 = rtB.lastRow;
        rtB.line_idx_3 = rtB.line_idx_0_tmp;
        while (!rtB.done) {
          rtB.OutCode1 = 0;
          rtB.OutCode2 = 0;

          // Determine viewport violations.
          if (rtB.halfLineWidth < 0) {
            rtB.OutCode1 = 4;
          } else if (rtB.halfLineWidth > 479) {
            rtB.OutCode1 = 8;
          }

          if (rtB.line_idx_2 < 0) {
            rtB.OutCode2 = 4;
          } else if (rtB.line_idx_2 > 479) {
            rtB.OutCode2 = 8;
          }

          if (rtB.line_idx_1 < 0) {
            rtB.OutCode1 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode1) | 1U);
          } else if (rtB.line_idx_1 > 639) {
            rtB.OutCode1 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode1) | 2U);
          }

          if (rtB.line_idx_3 < 0) {
            rtB.OutCode2 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode2) | 1U);
          } else if (rtB.line_idx_3 > 639) {
            rtB.OutCode2 = static_cast<int32_T>(static_cast<uint32_T>
              (rtB.OutCode2) | 2U);
          }

          if ((static_cast<uint32_T>(rtB.OutCode1) | static_cast<uint32_T>
               (rtB.OutCode2)) == 0U) {
            // Line falls completely within bounds.
            rtB.done = true;
            rtB.DrawShapes1_DW_FillColorAdd = true;
          } else if ((static_cast<uint32_T>(rtB.OutCode1) & static_cast<uint32_T>
                      (rtB.OutCode2)) != 0U) {
            // Line falls completely out of bounds.
            rtB.done = true;
            rtB.DrawShapes1_DW_FillColorAdd = false;
          } else if (static_cast<uint32_T>(rtB.OutCode1) != 0U) {
            // Clip 1st point; if it's in-bounds, clip 2nd point.
            if (rtB.visited1) {
              rtB.halfLineWidth = rtB.bestCol;
              rtB.line_idx_1 = rtB.line_idx_0_tmp;
            }

            rtB.k = rtB.line_idx_2 - rtB.halfLineWidth;
            rtB.dc = rtB.line_idx_3 - rtB.line_idx_1;
            if ((rtB.k > 1073741824) || (rtB.k < -1073741824) || ((rtB.dc >
                  1073741824) || (rtB.dc < -1073741824))) {
              // Possible Inf or Nan.
              rtB.done = true;
              rtB.DrawShapes1_DW_FillColorAdd = false;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 4U) != 0U) {
              // Violated RMin.
              rtB.OutCode1 = -rtB.halfLineWidth * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_1 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_1 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.halfLineWidth = 0;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 8U) != 0U) {
              // Violated RMax.
              rtB.OutCode1 = (479 - rtB.halfLineWidth) * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_1 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_1 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.halfLineWidth = 479;
              rtB.visited1 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode1) & 1U) != 0U) {
              // Violated CMin.
              rtB.OutCode1 = -rtB.line_idx_1 * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.halfLineWidth += (div_nde_s32_floor(rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              } else {
                rtB.halfLineWidth -= (div_nde_s32_floor(-rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              }

              rtB.line_idx_1 = 0;
              rtB.visited1 = true;
            } else {
              // Violated CMax.
              rtB.OutCode1 = (639 - rtB.line_idx_1) * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.halfLineWidth += (div_nde_s32_floor(rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              } else {
                rtB.halfLineWidth -= (div_nde_s32_floor(-rtB.OutCode1 << 1,
                  rtB.dc) + 1) >> 1;
              }

              rtB.line_idx_1 = 639;
              rtB.visited1 = true;
            }
          } else {
            // Clip the 2nd point.
            if (rtB.visited2) {
              rtB.line_idx_2 = rtB.lastRow;
              rtB.line_idx_3 = rtB.line_idx_0_tmp;
            }

            rtB.k = rtB.line_idx_2 - rtB.halfLineWidth;
            rtB.dc = rtB.line_idx_3 - rtB.line_idx_1;
            if ((rtB.k > 1073741824) || (rtB.k < -1073741824) || ((rtB.dc >
                  1073741824) || (rtB.dc < -1073741824))) {
              // Possible Inf or Nan.
              rtB.done = true;
              rtB.DrawShapes1_DW_FillColorAdd = false;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 4U) != 0U) {
              // Violated RMin.
              rtB.OutCode1 = -rtB.line_idx_2 * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_3 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_3 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.line_idx_2 = 0;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 8U) != 0U) {
              // Violated RMax.
              rtB.OutCode1 = (479 - rtB.line_idx_2) * rtB.dc;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.k >= 0)) || ((rtB.OutCode1
                < 0) && (rtB.k < 0))) {
                rtB.line_idx_3 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.k) +
                                   1) >> 1;
              } else {
                rtB.line_idx_3 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.k)
                                   + 1) >> 1;
              }

              rtB.line_idx_2 = 479;
              rtB.visited2 = true;
            } else if ((static_cast<uint32_T>(rtB.OutCode2) & 1U) != 0U) {
              // Violated CMin.
              rtB.OutCode1 = -rtB.line_idx_3 * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.line_idx_2 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              } else {
                rtB.line_idx_2 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              }

              rtB.line_idx_3 = 0;
              rtB.visited2 = true;
            } else {
              // Violated CMax.
              rtB.OutCode1 = (639 - rtB.line_idx_3) * rtB.k;
              if ((rtB.OutCode1 > 1073741824) || (rtB.OutCode1 < -1073741824)) {
                // Check for Inf or Nan.
                rtB.done = true;
                rtB.DrawShapes1_DW_FillColorAdd = false;
              } else if (((rtB.OutCode1 >= 0) && (rtB.dc >= 0)) ||
                         ((rtB.OutCode1 < 0) && (rtB.dc < 0))) {
                rtB.line_idx_2 += (div_nde_s32_floor(rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              } else {
                rtB.line_idx_2 -= (div_nde_s32_floor(-rtB.OutCode1 << 1, rtB.dc)
                                   + 1) >> 1;
              }

              rtB.line_idx_3 = 639;
              rtB.visited2 = true;
            }
          }
        }

        if (rtB.DrawShapes1_DW_FillColorAdd) {
          rtB.k = rtB.line_idx_1 * 480 + rtB.halfLineWidth;
          while (rtB.halfLineWidth <= rtB.line_idx_2) {
            rtB.DrawShapes1[rtB.k] = true;
            rtB.k++;
            rtB.halfLineWidth++;
          }
        }

        rtB.rtb_DataTypeConversion1_idx_0++;
      }
    }
  }

  // End of S-Function (svipdrawshapes): '<S2>/Draw Shapes2'

  // DataTypeConversion: '<S2>/Data Type Conversion4' incorporates:
  //   DataTypeConversion: '<S2>/Data Type Conversion1'
  //   MATLAB Function: '<S2>/MATLAB Function1'

  rtB.rtb_DataTypeConversion1_idx_0 = static_cast<int32_T>(floor(rtB.maxSum));
  rtB.bestInlierNum = static_cast<int32_T>(floor(rtB.scale2));

  // S-Function (svipdrawshapes): '<S2>/Draw Shapes3' incorporates:
  //   DataTypeConversion: '<S2>/Data Type Conversion1'

  // Calculate FillColor times Opacity.
  // Calculate One minus Opacity.
  // Update view port.
  // Draw all circles.
  if ((rtB.bestInlierNum - 1 >= -2) && (rtB.bestInlierNum - 1 <= 481) &&
      (rtB.rtb_DataTypeConversion1_idx_0 - 1 >= -2) &&
      (rtB.rtb_DataTypeConversion1_idx_0 - 1 <= 641)) {
    rtB.bestCol = -2;
    rtB.xtmp_tmp = -4;
    rtB.lastRow = 2;
    if ((rtB.rtb_DataTypeConversion1_idx_0 - 1 >= 0) &&
        (rtB.rtb_DataTypeConversion1_idx_0 - 1 <= 639)) {
      if (rtB.bestInlierNum - 3 >= 0) {
        rtB.line_idx_2 = rtB.bestInlierNum - 3;
      } else {
        rtB.line_idx_2 = 0;
      }

      if (rtB.bestInlierNum + 1 <= 479) {
        rtB.line_idx_3 = rtB.bestInlierNum + 1;
      } else {
        rtB.line_idx_3 = 479;
      }

      if (rtB.line_idx_2 <= rtB.line_idx_3) {
        rtB.k = (rtB.rtb_DataTypeConversion1_idx_0 - 1) * 480 + rtB.line_idx_2;
        while (rtB.line_idx_2 <= rtB.line_idx_3) {
          rtB.DrawShapes1[rtB.k] = ((rtB.DrawShapes1[rtB.k] ?
            static_cast<int32_T>(static_cast<int16_T>(16384 -
            rtP.DrawShapes3_opacity)) : 0) != 0);
          rtB.k++;
          rtB.line_idx_2++;
        }
      }
    }

    rtB.lastCol = 1;
    rtB.halfLineWidth = 3;
    rtB.line_idx_1 = 2;
    while (rtB.lastCol <= rtB.lastRow) {
      rtB.k = (rtB.rtb_DataTypeConversion1_idx_0 - rtB.lastCol) - 1;
      if ((rtB.k >= 0) && (rtB.k <= 639)) {
        rtB.line_idx_2 = (rtB.bestInlierNum - rtB.lastRow) - 1;
        if (rtB.line_idx_2 < 0) {
          rtB.line_idx_2 = 0;
        }

        rtB.line_idx_3 = (rtB.bestInlierNum + rtB.lastRow) - 1;
        if (rtB.line_idx_3 > 479) {
          rtB.line_idx_3 = 479;
        }

        if (rtB.line_idx_2 <= rtB.line_idx_3) {
          rtB.k = rtB.k * 480 + rtB.line_idx_2;
          while (rtB.line_idx_2 <= rtB.line_idx_3) {
            rtB.DrawShapes1[rtB.k] = ((rtB.DrawShapes1[rtB.k] ?
              static_cast<int32_T>(static_cast<int16_T>(16384 -
              rtP.DrawShapes3_opacity)) : 0) != 0);
            rtB.k++;
            rtB.line_idx_2++;
          }
        }
      }

      rtB.k = (rtB.rtb_DataTypeConversion1_idx_0 + rtB.lastCol) - 1;
      if ((rtB.k >= 0) && (rtB.k <= 639)) {
        rtB.line_idx_2 = (rtB.bestInlierNum - rtB.lastRow) - 1;
        if (rtB.line_idx_2 < 0) {
          rtB.line_idx_2 = 0;
        }

        rtB.line_idx_3 = (rtB.bestInlierNum + rtB.lastRow) - 1;
        if (rtB.line_idx_3 > 479) {
          rtB.line_idx_3 = 479;
        }

        if (rtB.line_idx_2 <= rtB.line_idx_3) {
          rtB.k = rtB.k * 480 + rtB.line_idx_2;
          while (rtB.line_idx_2 <= rtB.line_idx_3) {
            rtB.DrawShapes1[rtB.k] = ((rtB.DrawShapes1[rtB.k] ?
              static_cast<int32_T>(static_cast<int16_T>(16384 -
              rtP.DrawShapes3_opacity)) : 0) != 0);
            rtB.k++;
            rtB.line_idx_2++;
          }
        }
      }

      if (rtB.bestCol + 4 >= 0) {
        rtB.line_idx_1--;
        rtB.xtmp_tmp += 2;
        rtB.bestCol += rtB.xtmp_tmp;
      }

      rtB.halfLineWidth += 2;
      rtB.bestCol += rtB.halfLineWidth;
      if (((rtB.lastRow != rtB.line_idx_1) && (rtB.lastCol < rtB.lastRow)) ||
          (rtB.lastCol + 1 == rtB.lastRow)) {
        rtB.k = (rtB.rtb_DataTypeConversion1_idx_0 - rtB.lastRow) - 1;
        if ((rtB.k >= 0) && (rtB.k <= 639)) {
          rtB.line_idx_2 = (rtB.bestInlierNum - rtB.lastCol) - 1;
          if (rtB.line_idx_2 < 0) {
            rtB.line_idx_2 = 0;
          }

          rtB.line_idx_3 = (rtB.bestInlierNum + rtB.lastCol) - 1;
          if (rtB.line_idx_3 > 479) {
            rtB.line_idx_3 = 479;
          }

          if (rtB.line_idx_2 <= rtB.line_idx_3) {
            rtB.k = rtB.k * 480 + rtB.line_idx_2;
            while (rtB.line_idx_2 <= rtB.line_idx_3) {
              rtB.DrawShapes1[rtB.k] = ((rtB.DrawShapes1[rtB.k] ?
                static_cast<int32_T>(static_cast<int16_T>(16384 -
                rtP.DrawShapes3_opacity)) : 0) != 0);
              rtB.k++;
              rtB.line_idx_2++;
            }
          }
        }

        rtB.k = (rtB.rtb_DataTypeConversion1_idx_0 + rtB.lastRow) - 1;
        if ((rtB.k >= 0) && (rtB.k <= 639)) {
          rtB.line_idx_2 = (rtB.bestInlierNum - rtB.lastCol) - 1;
          if (rtB.line_idx_2 < 0) {
            rtB.line_idx_2 = 0;
          }

          rtB.line_idx_3 = (rtB.bestInlierNum + rtB.lastCol) - 1;
          if (rtB.line_idx_3 > 479) {
            rtB.line_idx_3 = 479;
          }

          if (rtB.line_idx_2 <= rtB.line_idx_3) {
            rtB.k = rtB.k * 480 + rtB.line_idx_2;
            while (rtB.line_idx_2 <= rtB.line_idx_3) {
              rtB.DrawShapes1[rtB.k] = ((rtB.DrawShapes1[rtB.k] ?
                static_cast<int32_T>(static_cast<int16_T>(16384 -
                rtP.DrawShapes3_opacity)) : 0) != 0);
              rtB.k++;
              rtB.line_idx_2++;
            }
          }
        }
      }

      rtB.lastCol++;
      rtB.lastRow = rtB.line_idx_1;
    }
  }

  // End of S-Function (svipdrawshapes): '<S2>/Draw Shapes3'

  // DataTypeConversion: '<S2>/Data Type Conversion1'
  rtB.rtb_DataTypeConversion1_idx_0 = static_cast<int32_T>(floor(rtB.win_y_low));

  // S-Function (svipdrawshapes): '<S2>/Draw Shapes1' incorporates:
  //   DataTypeConversion: '<S2>/Data Type Conversion1'

  // Copy the image from input to output.
  // Calculate FillColor times Opacity.
  rtB.DrawShapes1_DW_FillColorAdd = (rtP.DrawShapes1_opacity != 0);

  // Calculate One minus Opacity.
  // Update view port.
  // Draw all circles.
  if ((rtB.rtb_DataTypeConversion1_idx_0 - 1 >= -2) &&
      (rtB.rtb_DataTypeConversion1_idx_0 - 1 <= 641)) {
    rtB.bestCol = -2;
    rtB.xtmp_tmp = -4;
    rtB.lastRow = 2;
    if ((rtB.rtb_DataTypeConversion1_idx_0 - 1 >= 0) &&
        (rtB.rtb_DataTypeConversion1_idx_0 - 1 <= 639)) {
      rtB.k = (rtB.rtb_DataTypeConversion1_idx_0 - 1) * 480 + 317;
      rtB.bestInlierNum = 317;
      while (rtB.bestInlierNum <= 321) {
        rtB.DrawShapes1[rtB.k] = ((rtB.DrawShapes1[rtB.k] ? static_cast<int32_T>
          (static_cast<int16_T>(16384 - rtP.DrawShapes1_opacity)) : 0) != 0);
        rtB.DrawShapes1[rtB.k] = (static_cast<uint32_T>(rtB.DrawShapes1[rtB.k])
          + rtB.DrawShapes1_DW_FillColorAdd != 0U);
        rtB.k++;
        rtB.bestInlierNum++;
      }
    }

    rtB.lastCol = 1;
    rtB.halfLineWidth = 3;
    rtB.line_idx_1 = 2;
    while (rtB.lastCol <= rtB.lastRow) {
      rtB.k = (rtB.rtb_DataTypeConversion1_idx_0 - rtB.lastCol) - 1;
      if ((rtB.k >= 0) && (rtB.k <= 639)) {
        if (319 - rtB.lastRow >= 0) {
          rtB.line_idx_2 = 319 - rtB.lastRow;
        } else {
          rtB.line_idx_2 = 0;
        }

        if (rtB.lastRow + 319 <= 479) {
          rtB.line_idx_3 = rtB.lastRow + 319;
        } else {
          rtB.line_idx_3 = 479;
        }

        if (rtB.line_idx_2 <= rtB.line_idx_3) {
          rtB.k = rtB.k * 480 + rtB.line_idx_2;
          while (rtB.line_idx_2 <= rtB.line_idx_3) {
            rtB.DrawShapes1[rtB.k] = ((rtB.DrawShapes1[rtB.k] ?
              static_cast<int32_T>(static_cast<int16_T>(16384 -
              rtP.DrawShapes1_opacity)) : 0) != 0);
            rtB.DrawShapes1[rtB.k] = (static_cast<uint32_T>
              (rtB.DrawShapes1[rtB.k]) + rtB.DrawShapes1_DW_FillColorAdd != 0U);
            rtB.k++;
            rtB.line_idx_2++;
          }
        }
      }

      rtB.k = (rtB.rtb_DataTypeConversion1_idx_0 + rtB.lastCol) - 1;
      if ((rtB.k >= 0) && (rtB.k <= 639)) {
        if (319 - rtB.lastRow >= 0) {
          rtB.line_idx_2 = 319 - rtB.lastRow;
        } else {
          rtB.line_idx_2 = 0;
        }

        if (rtB.lastRow + 319 <= 479) {
          rtB.line_idx_3 = rtB.lastRow + 319;
        } else {
          rtB.line_idx_3 = 479;
        }

        if (rtB.line_idx_2 <= rtB.line_idx_3) {
          rtB.k = rtB.k * 480 + rtB.line_idx_2;
          while (rtB.line_idx_2 <= rtB.line_idx_3) {
            rtB.DrawShapes1[rtB.k] = ((rtB.DrawShapes1[rtB.k] ?
              static_cast<int32_T>(static_cast<int16_T>(16384 -
              rtP.DrawShapes1_opacity)) : 0) != 0);
            rtB.DrawShapes1[rtB.k] = (static_cast<uint32_T>
              (rtB.DrawShapes1[rtB.k]) + rtB.DrawShapes1_DW_FillColorAdd != 0U);
            rtB.k++;
            rtB.line_idx_2++;
          }
        }
      }

      if (rtB.bestCol + 4 >= 0) {
        rtB.line_idx_1--;
        rtB.xtmp_tmp += 2;
        rtB.bestCol += rtB.xtmp_tmp;
      }

      rtB.halfLineWidth += 2;
      rtB.bestCol += rtB.halfLineWidth;
      if (((rtB.lastRow != rtB.line_idx_1) && (rtB.lastCol < rtB.lastRow)) ||
          (rtB.lastCol + 1 == rtB.lastRow)) {
        rtB.k = (rtB.rtb_DataTypeConversion1_idx_0 - rtB.lastRow) - 1;
        if ((rtB.k >= 0) && (rtB.k <= 639)) {
          if (319 - rtB.lastCol >= 0) {
            rtB.line_idx_2 = 319 - rtB.lastCol;
          } else {
            rtB.line_idx_2 = 0;
          }

          if (rtB.lastCol + 319 <= 479) {
            rtB.line_idx_3 = rtB.lastCol + 319;
          } else {
            rtB.line_idx_3 = 479;
          }

          if (rtB.line_idx_2 <= rtB.line_idx_3) {
            rtB.k = rtB.k * 480 + rtB.line_idx_2;
            while (rtB.line_idx_2 <= rtB.line_idx_3) {
              rtB.DrawShapes1[rtB.k] = ((rtB.DrawShapes1[rtB.k] ?
                static_cast<int32_T>(static_cast<int16_T>(16384 -
                rtP.DrawShapes1_opacity)) : 0) != 0);
              rtB.DrawShapes1[rtB.k] = (static_cast<uint32_T>
                (rtB.DrawShapes1[rtB.k]) + rtB.DrawShapes1_DW_FillColorAdd != 0U);
              rtB.k++;
              rtB.line_idx_2++;
            }
          }
        }

        rtB.k = (rtB.rtb_DataTypeConversion1_idx_0 + rtB.lastRow) - 1;
        if ((rtB.k >= 0) && (rtB.k <= 639)) {
          if (319 - rtB.lastCol >= 0) {
            rtB.line_idx_2 = 319 - rtB.lastCol;
          } else {
            rtB.line_idx_2 = 0;
          }

          if (rtB.lastCol + 319 <= 479) {
            rtB.line_idx_3 = rtB.lastCol + 319;
          } else {
            rtB.line_idx_3 = 479;
          }

          if (rtB.line_idx_2 <= rtB.line_idx_3) {
            rtB.k = rtB.k * 480 + rtB.line_idx_2;
            while (rtB.line_idx_2 <= rtB.line_idx_3) {
              rtB.DrawShapes1[rtB.k] = ((rtB.DrawShapes1[rtB.k] ?
                static_cast<int32_T>(static_cast<int16_T>(16384 -
                rtP.DrawShapes1_opacity)) : 0) != 0);
              rtB.DrawShapes1[rtB.k] = (static_cast<uint32_T>
                (rtB.DrawShapes1[rtB.k]) + rtB.DrawShapes1_DW_FillColorAdd != 0U);
              rtB.k++;
              rtB.line_idx_2++;
            }
          }
        }
      }

      rtB.lastCol++;
      rtB.lastRow = rtB.line_idx_1;
    }
  }

  // End of S-Function (svipdrawshapes): '<S2>/Draw Shapes1'
  // MATLABSystem: '<Root>/TCP//IP Send1'
  rtB.win_y_low = rtB.error;
  if (rtDW.obj_d.isLittleEnd_ == 1) {
    memcpy((void *)&rtB.b_x[0], (void *)&rtB.error, (size_t)8 * sizeof(uint8_T));
    rtB.xtmp = rtB.b_x[0];
    rtB.b_x[0] = rtB.b_x[7];
    rtB.b_x[7] = rtB.xtmp;
    rtB.xtmp = rtB.b_x[1];
    rtB.b_x[1] = rtB.b_x[6];
    rtB.b_x[6] = rtB.xtmp;
    rtB.xtmp = rtB.b_x[2];
    rtB.b_x[2] = rtB.b_x[5];
    rtB.b_x[5] = rtB.xtmp;
    rtB.xtmp = rtB.b_x[3];
    rtB.b_x[3] = rtB.b_x[4];
    rtB.b_x[4] = rtB.xtmp;
    memcpy((void *)&rtB.win_y_low, (void *)&rtB.b_x[0], (size_t)1 * sizeof
           (real_T));
  }

  rtB.scale1 = rt_roundd_snf(rtDW.obj_d.isServer_);
  if (rtB.scale1 < 65536.0) {
    if (rtB.scale1 >= 0.0) {
      rtB.u1 = static_cast<uint16_T>(rtB.scale1);
    } else {
      rtB.u1 = 0U;
    }
  } else {
    rtB.u1 = MAX_uint16_T;
  }

  TCPStreamStepSend(&rtB.win_y_low, 8U, rtDW.obj_d.connStream_, rtB.u1,
                    &rtB.errorNo);

  // End of MATLABSystem: '<Root>/TCP//IP Send1'
  {                                    // Sample time: [0.1s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  rtM->Timing.taskTime0 =
    ((time_T)(++rtM->Timing.clockTick0)) * rtM->Timing.stepSize0;
}

// Model initialize function
void Rpi_cam_initialize(void)
{
  // Registration code
  rtmSetTFinal(rtM, 50.0);
  rtM->Timing.stepSize0 = 0.1;

  // External mode info
  rtM->Sizes.checksums[0] = (1959083739U);
  rtM->Sizes.checksums[1] = (1934739538U);
  rtM->Sizes.checksums[2] = (1178481082U);
  rtM->Sizes.checksums[3] = (2974607786U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(rtM->extModeInfo, &rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(rtM->extModeInfo, rtM->Sizes.checksums);
    rteiSetTPtr(rtM->extModeInfo, rtmGetTPtr(rtM));
  }

  {
    int32_T i;
    char_T devName[12];
    static const char_T devName_0[12] = "/dev/video0";
    static const int8_T self_T[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    // Start for S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' 
    srand(clock());

    // Start for ToAsyncQueueBlock generated from: '<S2>/Draw Shapes1'
    // Calculate FillColor times Opacity.
    // Calculate One minus Opacity.
    // Calculate FillColor times Opacity.
    // Calculate One minus Opacity.

    // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
    rtDW.obj.matlabCodegenIsDeleted = true;
    Raspiv4l2Capture_Raspiv4l2Capture(&rtDW.obj);
    rtDW.obj.Brightness = rtP.V4L2VideoCapture_Brightness;
    rtDW.obj.Saturation = rtP.V4L2VideoCapture_Saturation;
    rtDW.obj.Contrast = rtP.V4L2VideoCapture_Contrast;
    rtDW.obj.Sharpness = rtP.V4L2VideoCapture_Sharpness;
    rtDW.obj.CameraPan = rtP.V4L2VideoCapture_CameraPan;
    rtDW.obj.CameraTilt = rtP.V4L2VideoCapture_CameraTilt;
    rtDW.obj.CameraZoom = rtP.V4L2VideoCapture_CameraZoom;
    rtDW.obj.ManualFocus = rtP.V4L2VideoCapture_ManualFocus;
    rtDW.obj.isSetupComplete = false;
    rtDW.obj.isInitialized = 1;
    getCameraList();
    for (i = 0; i < 12; i++) {
      devName[i] = devName_0[i];
    }

    getCameraAddrIndex(&devName[0], 11U);
    EXT_webcamInit(0, 0, 0, 0, 0, 0, 640U, 480U, 2U, 2U, 1U, 0.1);
    v4l2Capture_updateV4L2Settings(&rtDW.obj, true);
    rtDW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/V4L2 Video Capture'

    // Start for MATLABSystem: '<S4>/Warp'
    rtDW.obj_k.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      rtDW.obj_k.TformProjective.T[i] = self_T[i];
    }

    // End of Start for MATLABSystem: '<S4>/Warp'

    // Start for MATLABSystem: '<Root>/TCP//IP Send1'
    SystemCore_setup(&rtDW.obj_d);
  }
}

// Model terminate function
void Rpi_cam_terminate(void)
{
  // Terminate for MATLABSystem: '<Root>/V4L2 Video Capture'
  if (!rtDW.obj.matlabCodegenIsDeleted) {
    rtDW.obj.matlabCodegenIsDeleted = true;
    if ((rtDW.obj.isInitialized == 1) && rtDW.obj.isSetupComplete) {
      EXT_webcamTerminate(0, 0);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/V4L2 Video Capture'
}

//
// File trailer for generated code.
//
// [EOF]
//
