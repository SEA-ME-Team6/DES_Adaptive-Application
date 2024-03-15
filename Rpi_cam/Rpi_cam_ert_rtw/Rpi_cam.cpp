//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Rpi_cam.cpp
//
// Code generated for Simulink model 'Rpi_cam'.
//
// Model version                  : 1.104
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Mar 15 11:10:11 2024
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
#include "Rpi_cam_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stdlib.h>
#include <stddef.h>

// Block signals (default storage)
B rtB;

// Block states (default storage)
DW rtDW;

// External outputs (root outports fed by signals with default storage)
ExtY rtY;

// Real-time model
RT_MODEL rtM_ = RT_MODEL();
RT_MODEL *const rtM = &rtM_;

// Forward declaration for local functions
static void v4l2Capture_updateV4L2Settings
  (codertarget_raspi_internal_Raspiv4l2Capture *obj, boolean_T forceUpdate);
static void SystemCore_step(codertarget_raspi_internal_Raspiv4l2Capture *obj,
  uint8_T varargout_1[307200], uint8_T varargout_2[307200], uint8_T varargout_3
  [307200]);
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
static void binary_expand_op_5(emxArray_boolean_T *in1, const emxArray_boolean_T
  *in2, const emxArray_int32_T *in3);
static void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
static void binary_expand_op_4(emxArray_boolean_T *in1, const emxArray_int32_T
  *in2);
static void and_o(emxArray_boolean_T *in1, const emxArray_boolean_T *in2, const
                  emxArray_boolean_T *in3);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions);
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);
static real_T mean(const emxArray_real_T *x);
static real_T maximum(const emxArray_real_T *x);
static void binary_expand_op_1(emxArray_boolean_T *in1, const emxArray_boolean_T
  *in2, const emxArray_boolean_T *in3, const emxArray_boolean_T *in4);
static void binary_expand_op(emxArray_boolean_T *in1, const emxArray_boolean_T
  *in2, const emxArray_boolean_T *in3);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static real_T xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0);
static void xswap(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0);
static real_T rt_hypotd_snf_o(real_T u0, real_T u1);
static void xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
                   emxArray_real_T *C, int32_T ic0, int32_T ldc, real_T work[3]);
static void qrpf(emxArray_real_T *A, int32_T m, real_T tau_data[], int32_T jpvt
                 [3]);
static void xgeqp3(emxArray_real_T *A, real_T tau_data[], int32_T *tau_size,
                   int32_T jpvt[3]);
static void qrsolve(const emxArray_real_T *A, const emxArray_real_T *B_0, real_T
                    Y[3], int32_T *rankA);
static void polyfit(const emxArray_real_T *x, const emxArray_real_T *y, real_T
                    p[3]);
static codertarget_raspi_internal_Raspiv4l2Capture
  *Raspiv4l2Capture_Raspiv4l2Capture(codertarget_raspi_internal_Raspiv4l2Capture
  *obj);
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
    for (rtB.i1 = 0; rtB.i1 < 11; rtB.i1++) {
      rtB.b[rtB.i1] = b[rtB.i1];
    }

    EXT_updateV4L2Control(&rtB.b[0], static_cast<real32_T>(obj->Brightness), 0,
                          &rtB.status);
  }

  if ((obj->Contrast != obj->ContrastInternal) || forceUpdate) {
    obj->ContrastInternal = obj->Contrast;
    for (rtB.i1 = 0; rtB.i1 < 9; rtB.i1++) {
      rtB.c[rtB.i1] = c[rtB.i1];
    }

    EXT_updateV4L2Control(&rtB.c[0], static_cast<real32_T>(obj->Contrast), 0,
                          &rtB.status);
  }

  if ((obj->Saturation != obj->SaturationInternal) || forceUpdate) {
    obj->SaturationInternal = obj->Saturation;
    for (rtB.i1 = 0; rtB.i1 < 11; rtB.i1++) {
      rtB.b[rtB.i1] = d[rtB.i1];
    }

    EXT_updateV4L2Control(&rtB.b[0], static_cast<real32_T>(obj->Saturation), 0,
                          &rtB.status);
  }

  if ((obj->Sharpness != obj->SharpnessInternal) || forceUpdate) {
    obj->SharpnessInternal = obj->Sharpness;
    for (rtB.i1 = 0; rtB.i1 < 10; rtB.i1++) {
      rtB.e[rtB.i1] = e[rtB.i1];
    }

    EXT_updateV4L2Control(&rtB.e[0], static_cast<real32_T>(obj->Sharpness), 0,
                          &rtB.status);
  }

  if ((obj->CameraPan != obj->CameraPanInternal) || forceUpdate) {
    obj->CameraPanInternal = obj->CameraPan;
    for (rtB.i1 = 0; rtB.i1 < 10; rtB.i1++) {
      rtB.e[rtB.i1] = f[rtB.i1];
    }

    EXT_updateV4L2Control(&rtB.e[0], static_cast<real32_T>(obj->CameraPan), 0,
                          &rtB.status);
  }

  if ((obj->CameraTilt != obj->CameraTiltInternal) || forceUpdate) {
    obj->CameraTiltInternal = obj->CameraTilt;
    for (rtB.i1 = 0; rtB.i1 < 11; rtB.i1++) {
      rtB.b[rtB.i1] = g[rtB.i1];
    }

    EXT_updateV4L2Control(&rtB.b[0], static_cast<real32_T>(obj->CameraTilt), 0,
                          &rtB.status);
  }

  if ((obj->CameraZoom != obj->CameraZoomInternal) || forceUpdate) {
    obj->CameraZoomInternal = obj->CameraZoom;
    for (rtB.i1 = 0; rtB.i1 < 11; rtB.i1++) {
      rtB.b[rtB.i1] = h[rtB.i1];
    }

    EXT_updateV4L2Control(&rtB.b[0], static_cast<real32_T>(obj->CameraZoom), 0,
                          &rtB.status);
  }

  if ((!obj->EnableManualFocusInternal) || forceUpdate) {
    obj->EnableManualFocusInternal = true;
    for (rtB.i1 = 0; rtB.i1 < 18; rtB.i1++) {
      rtB.i[rtB.i1] = i[rtB.i1];
    }

    EXT_updateV4L2Control(&rtB.i[0], 1.0F, 0, &rtB.status);
  }

  if ((obj->ManualFocus != obj->ManualFocusInternal) || forceUpdate) {
    obj->ManualFocusInternal = obj->ManualFocus;
    for (rtB.i1 = 0; rtB.i1 < 12; rtB.i1++) {
      rtB.j[rtB.i1] = j[rtB.i1];
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

void makeConstraintMatrix_Projective_D_D(const real_T pts1[], const real_T pts2[],
  uint32_T sampleNum, uint32_T maxSampleNum, real_T constraint[])
{
  uint32_T j;
  uint32_T k;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  // Generate the constraint matrix.
  j = 0U;
  k = 6U;
  for (uint32_T i = 0U; i < sampleNum; i++) {
    real_T tmp;
    real_T tmp_1;
    uint32_T tmp_0;
    constraint[k - 6U] = 0.0;
    constraint[k + 4294967291U] = 0.0;
    constraint[k + 4294967292U] = 0.0;
    tmp_0 = j + maxSampleNum;
    tmp = pts1[tmp_0];
    constraint[k + 4294967293U] = -tmp;
    constraint[k + 4294967294U] = -pts1[j];
    constraint[k + MAX_uint32_T] = -1.0;
    constraint[k] = pts2[j];
    constraint[k] *= tmp;
    constraint[k + 1U] = pts2[j];
    constraint[k + 1U] *= pts1[j];
    constraint[k + 2U] = pts2[j];
    constraint[k + 3U] = tmp;
    constraint[k + 4U] = pts1[j];
    constraint[k + 5U] = 1.0;
    constraint[k + 6U] = 0.0;
    constraint[k + 7U] = 0.0;
    constraint[k + 8U] = 0.0;
    tmp_1 = -pts2[tmp_0];
    constraint[k + 9U] = tmp_1;
    constraint[k + 9U] *= tmp;
    constraint[k + 10U] = tmp_1;
    constraint[k + 10U] *= pts1[j];
    constraint[k + 11U] = tmp_1;
    k += 18U;
    j++;
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

void normPts_D_D(const real_T pts[], const uint32_T samples[], uint32_T ptsNum,
                 uint32_T sampleNum, real_T ptsNorm[], real_T scale[], real_T
                 cents[])
{
  real_T sumDis;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  // Normalize the points.
  cents[0U] = 0.0;
  cents[1U] = 0.0;
  for (uint32_T i = 0U; i < sampleNum; i++) {
    sumDis = pts[samples[i] + ptsNum];
    ptsNorm[i + sampleNum] = sumDis;
    cents[0U] += sumDis;
    sumDis = pts[samples[i]];
    ptsNorm[i] = sumDis;
    cents[1U] += sumDis;
  }

  cents[0U] /= static_cast<real_T>(sampleNum);
  cents[1U] /= static_cast<real_T>(sampleNum);
  sumDis = 0.0;
  for (uint32_T i = 0U; i < sampleNum; i++) {
    uint32_T j;
    j = i + sampleNum;
    ptsNorm[j] -= cents[0U];
    ptsNorm[i] -= cents[1U];
    sumDis += sqrt(ptsNorm[j] * ptsNorm[j] + ptsNorm[i] * ptsNorm[i]);
  }

  if (sumDis > 0.0) {
    scale[0U] = 1.4142135623730951;
    scale[0U] *= static_cast<real_T>(sampleNum);
    scale[0U] /= sumDis;
    for (uint32_T i = 0U; i < sampleNum + sampleNum; i++) {
      ptsNorm[i] *= scale[0U];
    }
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void QRV2Norm_real_T_o(const real_T V[], int32_T N, real_T v2norm[])
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  rtB.val = 0.0;
  rtB.vi = 0;
  rtB.i_e = 0;
  while (rtB.i_e < N) {
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
    rtB.i_e++;
  }

  v2norm[0U] = rtB.val;

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void QRDC_real_T_o(real_T xVec[], real_T qrAux[], int32_T jpvt[], real_T
  work[], int32_T M, int32_T N)
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  rtB.pl = 0;
  rtB.j_b = 0;
  while (rtB.j_b < N) {
    rtB.pu = (jpvt[rtB.j_b] > 0);
    if (jpvt[rtB.j_b] < 0) {
      jpvt[rtB.j_b] = -rtB.j_b;
    } else {
      jpvt[rtB.j_b] = rtB.j_b;
    }

    if (rtB.pu == 1) {
      if (rtB.j_b != rtB.pl) {
        // Swap columns pl and j
        rtB.px = rtB.pl * M;
        rtB.px2 = rtB.j_b * M;
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

      jpvt[rtB.j_b] = jpvt[rtB.pl];
      jpvt[rtB.pl] = rtB.j_b;
      rtB.pl++;
    }

    rtB.j_b++;
  }

  rtB.pu = N - 1;
  rtB.j_b = N - 1;
  while (rtB.j_b >= 0) {
    if (jpvt[rtB.j_b] < 0) {
      jpvt[rtB.j_b] = -jpvt[rtB.j_b];
      if (rtB.j_b != rtB.pu) {
        // Swap columns pu and j
        rtB.px = rtB.pu * M;
        rtB.px2 = rtB.j_b * M;
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
        jpvt[rtB.pu] = jpvt[rtB.j_b];
        jpvt[rtB.j_b] = rtB.px;
      }

      rtB.pu--;
    }

    rtB.j_b--;
  }

  // compute the norms of the free columns
  rtB.j_b = rtB.pl;
  while (rtB.j_b <= rtB.pu) {
    QRV2Norm_real_T_o(&xVec[rtB.j_b * M], M, &qrAux[rtB.j_b]);
    work[rtB.j_b] = qrAux[rtB.j_b];
    rtB.j_b++;
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
      rtB.j_b = rtB.l;
      while (rtB.j_b <= rtB.pu) {
        if (qrAux[rtB.j_b] > rtB.maxnrm) {
          rtB.maxnrm = qrAux[rtB.j_b];
          rtB.maxj = rtB.j_b;
        }

        rtB.j_b++;
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
        rtB.j_b = rtB.l + 1;
        while (rtB.j_b < N) {
          rtB.plj = rtB.j_b * M + rtB.l;
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
          if (qrAux[rtB.j_b] == 0.0) {
            rtB.px2 = 1;
          }

          if ((rtB.j_b >= rtB.pl) && (rtB.j_b <= rtB.pu) && (rtB.px2 == 0)) {
            rtB.maxnrm = fabs(xVec[rtB.plj]) / qrAux[rtB.j_b];
            rtB.tt = 1.0 - rtB.maxnrm * rtB.maxnrm;
            if (rtB.tt < 0.0) {
              rtB.tt = 0.0;
            }

            rtB.t = rtB.tt;
            rtB.maxnrm = qrAux[rtB.j_b] / work[rtB.j_b];
            rtB.tt = 0.05 * rtB.tt * rtB.maxnrm * rtB.maxnrm + 1.0;
            if (rtB.tt != 1.0) {
              qrAux[rtB.j_b] *= sqrt(rtB.t);
            } else {
              QRV2Norm_real_T_o(&xVec[rtB.plj + 1], rtB.mml - 1, &rtB.maxnrm);
              qrAux[rtB.j_b] = rtB.maxnrm;
              work[rtB.j_b] = qrAux[rtB.j_b];
            }
          }

          rtB.j_b++;
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
    rtB.temp_d = qr[rtB.pjj];
    qr[rtB.pjj] = qrAuxj[0U];
    rtB.t_j = 0.0;
    rtB.py = 0;
    rtB.i_jz = rtB.nmj;
    while (rtB.i_jz > 0) {
      rtB.t_j -= y[rtB.py] * qr[rtB.pqr];
      rtB.pqr++;
      rtB.py++;
      rtB.i_jz--;
    }

    rtB.pqr = rtB.pjj;
    rtB.t_j /= qr[rtB.pjj];
    rtB.py = 0;
    rtB.i_jz = rtB.nmj;
    while (rtB.i_jz > 0) {
      y[rtB.py] += rtB.t_j * qr[rtB.pqr];
      rtB.pqr++;
      rtB.py++;
      rtB.i_jz--;
    }

    qr[rtB.pjj] = rtB.temp_d;
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void QRSL1_real_T_o(real_T qr[], const real_T qrAux[], real_T y[],
  int32_T n, int32_T k)
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  if (k <= n - 1) {
    rtB.j_a = k;
  } else {
    rtB.j_a = n - 1;
  }

  if (rtB.j_a != 0) {
    rtB.pqraux_tmp = rtB.j_a;
    rtB.i_j = rtB.j_a;
    while (rtB.i_j > 0) {
      QRCompQy_real_T_o(&qr[0], &qrAux[rtB.j_a - 1], &y[rtB.pqraux_tmp - 1], n,
                        rtB.i_j - 1);
      rtB.pqraux_tmp = rtB.j_a - 1;
      rtB.j_a--;
      rtB.i_j--;
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
  rtB.j_h = 0;
  while (rtB.j_h < M * rtB.L) {
    outQ[rtB.j_h] = 0.0;
    rtB.j_h++;
  }

  rtB.j_h = 0;
  while (rtB.j_h < rtB.L) {
    outQ[rtB.pq] = 1.0;
    rtB.pq = (rtB.pq + M) + 1;
    rtB.j_h++;
  }

  // Convert cols of identity into cols of q. Use info stored in lower triangle of r and in vector qraux to work on columns of identity matrix I and transform them into q*I(:,j) i.e. the columns of q. 
  rtB.pq = 0;
  rtB.j_h = 0;
  while (rtB.j_h < rtB.L) {
    QRSL1_real_T_o(&outR[0], &qrAux[0], &outQ[rtB.pq], M, N);
    rtB.pq += M;
    rtB.j_h++;
  }

  if (economy && (M > N)) {
    // Copy upper triangle of r to s
    rtB.L = 0;
    rtB.ps = 0;
    rtB.j_h = 1;
    while (rtB.j_h - 1 < N) {
      rtB.pq = 0;
      while (rtB.pq <= rtB.j_h - 1) {
        sPtr[rtB.ps] = outR[rtB.L];
        rtB.ps++;
        rtB.L++;
        rtB.pq++;
      }

      rtB.L = (rtB.L + M) - rtB.j_h;
      rtB.pq = 0;
      while (rtB.pq < N - rtB.j_h) {
        sPtr[rtB.ps] = 0.0;
        rtB.ps++;
        rtB.pq++;
      }

      rtB.j_h++;
    }
  } else {
    // Zero strict lower triangle of r
    rtB.L = M * N - 1;
    rtB.j_h = N;
    while (rtB.j_h - 1 >= 0) {
      rtB.pq = M;
      while (rtB.pq > rtB.j_h) {
        outR[rtB.L] = 0.0;
        rtB.L--;
        rtB.pq--;
      }

      if (M < rtB.j_h) {
        rtB.L -= M;
      } else {
        rtB.L -= rtB.j_h;
      }

      rtB.j_h--;
    }
  }

  // form permutation vector e
  rtB.L = 0;
  rtB.pq = 0;
  rtB.j_h = 0;
  while (rtB.j_h < N) {
    outE[rtB.L] = jpvt[rtB.pq] + 1;
    rtB.pq = rtB.L + 1;
    rtB.L++;
    rtB.j_h++;
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
  rtB.tinv_c = rtB.tinv[0];
  rtB.tinv_f = rtB.tinv[1];
  rtB.tinv_g = rtB.tinv[2];
  rtB.tinv_g1 = rtB.tinv[3];
  rtB.tinv_m = rtB.tinv[4];
  rtB.tinv_n = rtB.tinv[5];
  for (rtB.p1 = 0; rtB.p1 < 640; rtB.p1++) {
    for (rtB.p2 = 0; rtB.p2 < 480; rtB.p2++) {
      // Start for MATLABSystem: '<S4>/Warp'
      rtB.srczWorld_val = ((((static_cast<real_T>(rtB.p1) + 1.0) - 0.5) + 0.5) *
                           rtB.absx11 + (((static_cast<real_T>(rtB.p2) + 1.0) -
        0.5) + 0.5) * rtB.absx21) + rtB.absx31;
      rtB.p3 = 480 * rtB.p1 + rtB.p2;
      rtB.srcXIntrinsic[rtB.p3] = ((((((static_cast<real_T>(rtB.p1) + 1.0) - 0.5)
        + 0.5) * rtB.tinv_c + (((static_cast<real_T>(rtB.p2) + 1.0) - 0.5) + 0.5)
        * rtB.tinv_f) + rtB.tinv_g) / rtB.srczWorld_val - 0.5) + 0.5;
      rtB.srcYIntrinsic[rtB.p3] = ((((((static_cast<real_T>(rtB.p1) + 1.0) - 0.5)
        + 0.5) * rtB.tinv_g1 + (((static_cast<real_T>(rtB.p2) + 1.0) - 0.5) +
        0.5) * rtB.tinv_m) + rtB.tinv_n) / rtB.srczWorld_val - 0.5) + 0.5;
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
          rtB.i4 = rtB.inputImage[rtB.p2 - 1];
          rtB.itmp = 480 * rtB.itmp + rtB.p3;
          rtB.i5 = rtB.inputImage[rtB.itmp - 1];
          if (rtB.i4 == rtB.i5) {
            rtB.qx1 = rtB.i4;
          } else {
            rtB.qx1 = static_cast<real32_T>(1.0 - rtB.absx21) *
              static_cast<real32_T>(rtB.i4) + static_cast<real32_T>(rtB.i5) *
              static_cast<real32_T>(rtB.absx21);
          }

          rtB.i4 = rtB.inputImage[rtB.p2];
          rtB.i5 = rtB.inputImage[rtB.itmp];
          if (rtB.i4 == rtB.i5) {
            rtB.qx2 = rtB.i4;
          } else {
            rtB.qx2 = static_cast<real32_T>(1.0 - rtB.absx21) *
              static_cast<real32_T>(rtB.i4) + static_cast<real32_T>(rtB.i5) *
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
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int32_T
  oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc(static_cast<uint32_T>(i) * sizeof(int32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * static_cast<uint32_T>
             (oldNumel));
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = static_cast<int32_T *>(newData);
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static void eml_find(const boolean_T x[307200], emxArray_int32_T *i,
                     emxArray_int32_T *j)
{
  int32_T idx;
  int32_T ii;
  int32_T jj;
  boolean_T exitg1;
  boolean_T guard1;
  idx = 0;
  ii = i->size[0];
  i->size[0] = 307200;
  emxEnsureCapacity_int32_T(i, ii);
  ii = j->size[0];
  j->size[0] = 307200;
  emxEnsureCapacity_int32_T(j, ii);
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 640)) {
    guard1 = false;
    if (x[((jj - 1) * 480 + ii) - 1]) {
      idx++;
      i->data[idx - 1] = ii;
      j->data[idx - 1] = jj;
      if (idx >= 307200) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
      if (ii > 480) {
        ii = 1;
        jj++;
      }
    }
  }

  if (idx < 1) {
    i->size[0] = 0;
    j->size[0] = 0;
  } else {
    ii = i->size[0];
    i->size[0] = idx;
    emxEnsureCapacity_int32_T(i, ii);
    ii = j->size[0];
    j->size[0] = idx;
    emxEnsureCapacity_int32_T(j, ii);
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
  for (int32_T i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int32_T
  oldNumel)
{
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  rtB.newNumel_i = 1;
  for (rtB.i_oy = 0; rtB.i_oy < emxArray->numDimensions; rtB.i_oy++) {
    rtB.newNumel_i *= emxArray->size[rtB.i_oy];
  }

  if (rtB.newNumel_i > emxArray->allocatedSize) {
    rtB.i_oy = emxArray->allocatedSize;
    if (rtB.i_oy < 16) {
      rtB.i_oy = 16;
    }

    while (rtB.i_oy < rtB.newNumel_i) {
      if (rtB.i_oy > 1073741823) {
        rtB.i_oy = MAX_int32_T;
      } else {
        rtB.i_oy <<= 1;
      }
    }

    newData = malloc(static_cast<uint32_T>(rtB.i_oy) * sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * static_cast<uint32_T>
             (oldNumel));
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = static_cast<boolean_T *>(newData);
    emxArray->allocatedSize = rtB.i_oy;
    emxArray->canFreeData = true;
  }
}

static void binary_expand_op_5(emxArray_boolean_T *in1, const emxArray_boolean_T
  *in2, const emxArray_int32_T *in3)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  loop_ub = in3->size[0] == 1 ? in2->size[0] : in3->size[0];
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1->data[i] = (in2->data[i * stride_0_0] && (in3->data[i * stride_1_0] >= 0));
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

static void binary_expand_op_4(emxArray_boolean_T *in1, const emxArray_int32_T
  *in2)
{
  emxArray_boolean_T *in1_0;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emxInit_boolean_T(&in1_0, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  loop_ub = in2->size[0] == 1 ? in1->size[0] : in2->size[0];
  i = in1_0->size[0];
  in1_0->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1_0, i);
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_0->data[i] = (in1->data[i * stride_0_0] && (in2->data[i * stride_1_0] >=
      480));
  }

  i = in1->size[0];
  in1->size[0] = in1_0->size[0];
  emxEnsureCapacity_boolean_T(in1, i);
  loop_ub = in1_0->size[0];
  if (loop_ub - 1 >= 0) {
    memcpy(&in1->data[0], &in1_0->data[0], static_cast<uint32_T>(loop_ub) *
           sizeof(boolean_T));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
  emxFree_boolean_T(&in1_0);
}

static void and_o(emxArray_boolean_T *in1, const emxArray_boolean_T *in2, const
                  emxArray_boolean_T *in3)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  loop_ub = in3->size[0] == 1 ? in2->size[0] : in3->size[0];
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1->data[i] = (in2->data[i * stride_0_0] && in3->data[i * stride_1_0]);
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
  for (rtB.i_o4 = 0; rtB.i_o4 < numDimensions; rtB.i_o4++) {
    emxArray->size[rtB.i_o4] = 0;
  }
}

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel)
{
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  rtB.newNumel = 1;
  for (rtB.i_f = 0; rtB.i_f < emxArray->numDimensions; rtB.i_f++) {
    rtB.newNumel *= emxArray->size[rtB.i_f];
  }

  if (rtB.newNumel > emxArray->allocatedSize) {
    rtB.i_f = emxArray->allocatedSize;
    if (rtB.i_f < 16) {
      rtB.i_f = 16;
    }

    while (rtB.i_f < rtB.newNumel) {
      if (rtB.i_f > 1073741823) {
        rtB.i_f = MAX_int32_T;
      } else {
        rtB.i_f <<= 1;
      }
    }

    newData = malloc(static_cast<uint32_T>(rtB.i_f) * sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * static_cast<uint32_T>
             (oldNumel));
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = static_cast<real_T *>(newData);
    emxArray->allocatedSize = rtB.i_f;
    emxArray->canFreeData = true;
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static real_T mean(const emxArray_real_T *x)
{
  real_T b_y;
  if (x->size[0] == 0) {
    b_y = 0.0;
  } else {
    int32_T firstBlockLength;
    int32_T lastBlockLength;
    int32_T nblocks;
    int32_T xblockoffset;
    if (x->size[0] <= 1024) {
      firstBlockLength = x->size[0];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = static_cast<int32_T>(static_cast<uint32_T>(x->size[0]) >> 10);
      lastBlockLength = x->size[0] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }

    b_y = x->data[0];
    for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++) {
      b_y += x->data[xblockoffset - 1];
    }

    for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++)
    {
      real_T bsum;
      int32_T hi;
      xblockoffset = (firstBlockLength - 1) << 10;
      bsum = x->data[xblockoffset];
      if (firstBlockLength == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }

      for (int32_T b_k = 2; b_k <= hi; b_k++) {
        bsum += x->data[(xblockoffset + b_k) - 1];
      }

      b_y += bsum;
    }
  }

  return b_y / static_cast<real_T>(x->size[0]);
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static real_T maximum(const emxArray_real_T *x)
{
  real_T ex;
  int32_T last;
  last = x->size[0];
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
    for (int32_T k = 2; k <= last; k++) {
      real_T x_0;
      x_0 = x->data[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

static void binary_expand_op_1(emxArray_boolean_T *in1, const emxArray_boolean_T
  *in2, const emxArray_boolean_T *in3, const emxArray_boolean_T *in4)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T tmp;

  // MATLAB Function: '<S2>/MATLAB Function1'
  loop_ub = in4->size[0] == 1 ? in2->size[0] : in4->size[0];
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    tmp = i * stride_0_0;
    in1->data[i] = (in2->data[tmp] && in3->data[tmp] && in4->data[i * stride_1_0]);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

static void binary_expand_op(emxArray_boolean_T *in1, const emxArray_boolean_T
  *in2, const emxArray_boolean_T *in3)
{
  emxArray_boolean_T *in1_0;
  emxInit_boolean_T(&in1_0, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.loop_ub_n = in3->size[0] == 1 ? in1->size[0] : in3->size[0];
  rtB.i3 = in1_0->size[0];
  in1_0->size[0] = rtB.loop_ub_n;
  emxEnsureCapacity_boolean_T(in1_0, rtB.i3);
  rtB.stride_0_0 = (in1->size[0] != 1);
  rtB.stride_1_0 = (in3->size[0] != 1);
  for (rtB.i3 = 0; rtB.i3 < rtB.loop_ub_n; rtB.i3++) {
    rtB.in1_tmp = rtB.i3 * rtB.stride_0_0;
    in1_0->data[rtB.i3] = (in1->data[rtB.in1_tmp] && in2->data[rtB.in1_tmp] &&
      in3->data[rtB.i3 * rtB.stride_1_0]);
  }

  rtB.i3 = in1->size[0];
  in1->size[0] = in1_0->size[0];
  emxEnsureCapacity_boolean_T(in1, rtB.i3);
  rtB.loop_ub_n = in1_0->size[0];
  if (rtB.loop_ub_n - 1 >= 0) {
    memcpy(&in1->data[0], &in1_0->data[0], static_cast<uint32_T>(rtB.loop_ub_n) *
           sizeof(boolean_T));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
  emxFree_boolean_T(&in1_0);
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

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static real_T xnrm2(int32_T n, const emxArray_real_T *x, int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x->data[ix0 - 1]);
    } else {
      rtB.scale = 3.3121686421112381E-170;
      rtB.kend = (ix0 + n) - 1;
      for (rtB.k_b = ix0; rtB.k_b <= rtB.kend; rtB.k_b++) {
        rtB.absxk = fabs(x->data[rtB.k_b - 1]);
        if (rtB.absxk > rtB.scale) {
          rtB.t_p = rtB.scale / rtB.absxk;
          y = y * rtB.t_p * rtB.t_p + 1.0;
          rtB.scale = rtB.absxk;
        } else {
          rtB.t_p = rtB.absxk / rtB.scale;
          y += rtB.t_p * rtB.t_p;
        }
      }

      y = rtB.scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static void xswap(int32_T n, emxArray_real_T *x, int32_T ix0, int32_T iy0)
{
  for (rtB.k_j = 0; rtB.k_j < n; rtB.k_j++) {
    rtB.temp_tmp = (ix0 + rtB.k_j) - 1;
    rtB.temp = x->data[rtB.temp_tmp];
    rtB.i2 = (iy0 + rtB.k_j) - 1;
    x->data[rtB.temp_tmp] = x->data[rtB.i2];
    x->data[rtB.i2] = rtB.temp;
  }
}

static real_T rt_hypotd_snf_o(real_T u0, real_T u1)
{
  real_T y;
  rtB.a = fabs(u0);
  rtB.b_l = fabs(u1);
  if (rtB.a < rtB.b_l) {
    rtB.a /= rtB.b_l;
    y = sqrt(rtB.a * rtB.a + 1.0) * rtB.b_l;
  } else if (rtB.a > rtB.b_l) {
    rtB.b_l /= rtB.a;
    y = sqrt(rtB.b_l * rtB.b_l + 1.0) * rtB.a;
  } else if (rtIsNaN(rtB.b_l)) {
    y = (rtNaN);
  } else {
    y = rtB.a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static void xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau,
                   emxArray_real_T *C, int32_T ic0, int32_T ldc, real_T work[3])
{
  if (tau != 0.0) {
    boolean_T exitg2;
    rtB.lastv = m;
    rtB.lastc = iv0 + m;
    while ((rtB.lastv > 0) && (C->data[rtB.lastc - 2] == 0.0)) {
      rtB.lastv--;
      rtB.lastc--;
    }

    rtB.lastc = n;
    exitg2 = false;
    while ((!exitg2) && (rtB.lastc > 0)) {
      int32_T exitg1;
      rtB.coltop = (rtB.lastc - 1) * ldc + ic0;
      rtB.jA = rtB.coltop;
      do {
        exitg1 = 0;
        if (rtB.jA <= (rtB.coltop + rtB.lastv) - 1) {
          if (C->data[rtB.jA - 1] != 0.0) {
            exitg1 = 1;
          } else {
            rtB.jA++;
          }
        } else {
          rtB.lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    rtB.lastv = 0;
    rtB.lastc = 0;
  }

  if (rtB.lastv > 0) {
    if (rtB.lastc != 0) {
      rtB.jA = static_cast<uint8_T>(rtB.lastc);
      memset(&work[0], 0, static_cast<uint32_T>(rtB.jA) * sizeof(real_T));
      rtB.iy = 0;
      rtB.d_b = (rtB.lastc - 1) * ldc + ic0;
      for (rtB.coltop = ic0; ldc < 0 ? rtB.coltop >= rtB.d_b : rtB.coltop <=
           rtB.d_b; rtB.coltop += ldc) {
        rtB.c_p = 0.0;
        rtB.e_l = (rtB.coltop + rtB.lastv) - 1;
        for (rtB.jA = rtB.coltop; rtB.jA <= rtB.e_l; rtB.jA++) {
          rtB.c_p += C->data[((iv0 + rtB.jA) - rtB.coltop) - 1] * C->data[rtB.jA
            - 1];
        }

        work[rtB.iy] += rtB.c_p;
        rtB.iy++;
      }
    }

    if (!(-tau == 0.0)) {
      rtB.jA = ic0;
      rtB.iy = static_cast<uint8_T>(rtB.lastc);
      for (rtB.lastc = 0; rtB.lastc < rtB.iy; rtB.lastc++) {
        rtB.c_p = work[rtB.lastc];
        if (rtB.c_p != 0.0) {
          rtB.c_p *= -tau;
          rtB.d_b = rtB.lastv + rtB.jA;
          for (rtB.coltop = rtB.jA; rtB.coltop < rtB.d_b; rtB.coltop++) {
            C->data[rtB.coltop - 1] += C->data[((iv0 + rtB.coltop) - rtB.jA) - 1]
              * rtB.c_p;
          }
        }

        rtB.jA += ldc;
      }
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static void qrpf(emxArray_real_T *A, int32_T m, real_T tau_data[], int32_T jpvt
                 [3])
{
  rtB.ma = A->size[0];
  rtB.work[0] = 0.0;
  rtB.smax = xnrm2(m, A, 1);
  rtB.vn1[0] = rtB.smax;
  rtB.vn2[0] = rtB.smax;
  rtB.work[1] = 0.0;
  rtB.smax = xnrm2(m, A, A->size[0] + 1);
  rtB.vn1[1] = rtB.smax;
  rtB.vn2[1] = rtB.smax;
  rtB.work[2] = 0.0;
  rtB.smax = xnrm2(m, A, (A->size[0] << 1) + 1);
  rtB.vn1[2] = rtB.smax;
  rtB.vn2[2] = rtB.smax;
  if (m <= 3) {
    rtB.b_b = static_cast<uint8_T>(m);
  } else {
    rtB.b_b = 3;
  }

  for (rtB.i_n = 0; rtB.i_n < rtB.b_b; rtB.i_n++) {
    rtB.itemp = rtB.i_n * rtB.ma;
    rtB.ii = rtB.itemp + rtB.i_n;
    rtB.mmi = m - rtB.i_n;
    rtB.knt = 3 - rtB.i_n;
    rtB.idxmax = 0;
    if (3 - rtB.i_n > 1) {
      rtB.smax = fabs(rtB.vn1[rtB.i_n]);
      for (rtB.pvt = 2; rtB.pvt <= rtB.knt; rtB.pvt++) {
        rtB.s_b = fabs(rtB.vn1[(rtB.i_n + rtB.pvt) - 1]);
        if (rtB.s_b > rtB.smax) {
          rtB.idxmax = rtB.pvt - 1;
          rtB.smax = rtB.s_b;
        }
      }
    }

    rtB.pvt = rtB.i_n + rtB.idxmax;
    if (rtB.pvt != rtB.i_n) {
      xswap(m, A, rtB.pvt * rtB.ma + 1, rtB.itemp + 1);
      rtB.itemp = jpvt[rtB.pvt];
      jpvt[rtB.pvt] = jpvt[rtB.i_n];
      jpvt[rtB.i_n] = rtB.itemp;
      rtB.vn1[rtB.pvt] = rtB.vn1[rtB.i_n];
      rtB.vn2[rtB.pvt] = rtB.vn2[rtB.i_n];
    }

    if (rtB.i_n + 1 < m) {
      rtB.s_b = A->data[rtB.ii];
      rtB.pvt = rtB.ii + 2;
      tau_data[rtB.i_n] = 0.0;
      if (rtB.mmi > 0) {
        rtB.smax = xnrm2(rtB.mmi - 1, A, rtB.ii + 2);
        if (rtB.smax != 0.0) {
          rtB.smax = rt_hypotd_snf_o(A->data[rtB.ii], rtB.smax);
          if (A->data[rtB.ii] >= 0.0) {
            rtB.smax = -rtB.smax;
          }

          if (fabs(rtB.smax) < 1.0020841800044864E-292) {
            rtB.knt = 0;
            rtB.idxmax = rtB.ii + rtB.mmi;
            do {
              rtB.knt++;
              for (rtB.itemp = rtB.pvt; rtB.itemp <= rtB.idxmax; rtB.itemp++) {
                A->data[rtB.itemp - 1] *= 9.9792015476736E+291;
              }

              rtB.smax *= 9.9792015476736E+291;
              rtB.s_b *= 9.9792015476736E+291;
            } while ((fabs(rtB.smax) < 1.0020841800044864E-292) && (rtB.knt < 20));

            rtB.smax = rt_hypotd_snf_o(rtB.s_b, xnrm2(rtB.mmi - 1, A, rtB.ii + 2));
            if (rtB.s_b >= 0.0) {
              rtB.smax = -rtB.smax;
            }

            tau_data[rtB.i_n] = (rtB.smax - rtB.s_b) / rtB.smax;
            rtB.s_b = 1.0 / (rtB.s_b - rtB.smax);
            for (rtB.itemp = rtB.pvt; rtB.itemp <= rtB.idxmax; rtB.itemp++) {
              A->data[rtB.itemp - 1] *= rtB.s_b;
            }

            for (rtB.pvt = 0; rtB.pvt < rtB.knt; rtB.pvt++) {
              rtB.smax *= 1.0020841800044864E-292;
            }

            rtB.s_b = rtB.smax;
          } else {
            tau_data[rtB.i_n] = (rtB.smax - A->data[rtB.ii]) / rtB.smax;
            rtB.s_b = 1.0 / (A->data[rtB.ii] - rtB.smax);
            rtB.knt = rtB.ii + rtB.mmi;
            for (rtB.itemp = rtB.pvt; rtB.itemp <= rtB.knt; rtB.itemp++) {
              A->data[rtB.itemp - 1] *= rtB.s_b;
            }

            rtB.s_b = rtB.smax;
          }
        }
      }

      A->data[rtB.ii] = rtB.s_b;
    } else {
      tau_data[rtB.i_n] = 0.0;
    }

    if (rtB.i_n + 1 < 3) {
      rtB.smax = A->data[rtB.ii];
      A->data[rtB.ii] = 1.0;
      xzlarf(rtB.mmi, 2 - rtB.i_n, rtB.ii + 1, tau_data[rtB.i_n], A, (rtB.ii +
              rtB.ma) + 1, rtB.ma, rtB.work);
      A->data[rtB.ii] = rtB.smax;
    }

    for (rtB.ii = rtB.i_n + 2; rtB.ii < 4; rtB.ii++) {
      rtB.pvt = (rtB.ii - 1) * rtB.ma + rtB.i_n;
      rtB.smax = rtB.vn1[rtB.ii - 1];
      if (rtB.smax != 0.0) {
        rtB.s_b = fabs(A->data[rtB.pvt]) / rtB.smax;
        rtB.s_b = 1.0 - rtB.s_b * rtB.s_b;
        if (rtB.s_b < 0.0) {
          rtB.s_b = 0.0;
        }

        rtB.temp2 = rtB.smax / rtB.vn2[rtB.ii - 1];
        rtB.temp2 = rtB.temp2 * rtB.temp2 * rtB.s_b;
        if (rtB.temp2 <= 1.4901161193847656E-8) {
          if (rtB.i_n + 1 < m) {
            rtB.smax = xnrm2(rtB.mmi - 1, A, rtB.pvt + 2);
            rtB.vn1[rtB.ii - 1] = rtB.smax;
            rtB.vn2[rtB.ii - 1] = rtB.smax;
          } else {
            rtB.vn1[rtB.ii - 1] = 0.0;
            rtB.vn2[rtB.ii - 1] = 0.0;
          }
        } else {
          rtB.vn1[rtB.ii - 1] = rtB.smax * sqrt(rtB.s_b);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static void xgeqp3(emxArray_real_T *A, real_T tau_data[], int32_T *tau_size,
                   int32_T jpvt[3])
{
  emxArray_real_T *b_A;
  boolean_T guard1;
  emxInit_real_T(&b_A, 2);
  rtB.i_o = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = 3;
  emxEnsureCapacity_real_T(b_A, rtB.i_o);
  rtB.loop_ub = A->size[0] * 3;
  if (rtB.loop_ub - 1 >= 0) {
    memcpy(&b_A->data[0], &A->data[0], static_cast<uint32_T>(rtB.loop_ub) *
           sizeof(real_T));
  }

  if (A->size[0] <= 3) {
    rtB.loop_ub = A->size[0];
  } else {
    rtB.loop_ub = 3;
  }

  *tau_size = rtB.loop_ub;
  if (rtB.loop_ub - 1 >= 0) {
    memset(&tau_data[0], 0, static_cast<uint32_T>(rtB.loop_ub) * sizeof(real_T));
  }

  guard1 = false;
  if (A->size[0] == 0) {
    guard1 = true;
  } else {
    if (A->size[0] <= 3) {
      rtB.i_o = A->size[0];
    } else {
      rtB.i_o = 3;
    }

    if (rtB.i_o < 1) {
      guard1 = true;
    } else {
      jpvt[0] = 1;
      jpvt[1] = 2;
      jpvt[2] = 3;
      qrpf(b_A, A->size[0], tau_data, jpvt);
    }
  }

  if (guard1) {
    jpvt[0] = 1;
    jpvt[1] = 2;
    jpvt[2] = 3;
  }

  rtB.i_o = A->size[0] * A->size[1];
  A->size[0] = b_A->size[0];
  A->size[1] = 3;
  emxEnsureCapacity_real_T(A, rtB.i_o);
  rtB.loop_ub = b_A->size[0];
  for (rtB.i_o = 0; rtB.i_o < 3; rtB.i_o++) {
    for (rtB.b_A = 0; rtB.b_A < rtB.loop_ub; rtB.b_A++) {
      A->data[rtB.b_A + A->size[0] * rtB.i_o] = b_A->data[b_A->size[0] * rtB.i_o
        + rtB.b_A];
    }
  }

  emxFree_real_T(&b_A);
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static void qrsolve(const emxArray_real_T *A, const emxArray_real_T *B_0, real_T
                    Y[3], int32_T *rankA)
{
  emxArray_real_T *b_A;
  emxArray_real_T *b_B;
  emxInit_real_T(&b_A, 2);
  rtB.maxmn = b_A->size[0] * b_A->size[1];
  b_A->size[0] = A->size[0];
  b_A->size[1] = 3;
  emxEnsureCapacity_real_T(b_A, rtB.maxmn);
  rtB.maxmn = A->size[0] * 3;
  if (rtB.maxmn - 1 >= 0) {
    memcpy(&b_A->data[0], &A->data[0], static_cast<uint32_T>(rtB.maxmn) * sizeof
           (real_T));
  }

  xgeqp3(b_A, rtB.tau_data, &rtB.tau_size, rtB.jpvt);
  *rankA = 0;
  if (b_A->size[0] < 3) {
    rtB.minmn = b_A->size[0];
    rtB.maxmn = 3;
  } else {
    rtB.minmn = 3;
    rtB.maxmn = b_A->size[0];
  }

  if (rtB.minmn > 0) {
    rtB.tol = 2.2204460492503131E-15 * static_cast<real_T>(rtB.maxmn) * fabs
      (b_A->data[0]);
    while ((*rankA < rtB.minmn) && (!(fabs(b_A->data[b_A->size[0] * *rankA +
              *rankA]) <= rtB.tol))) {
      (*rankA)++;
    }
  }

  rtB.minmn = 0;
  if (b_A->size[0] <= 3) {
    rtB.maxmn = b_A->size[0];
  } else {
    rtB.maxmn = 3;
  }

  if (rtB.maxmn > 0) {
    for (rtB.k_l = 0; rtB.k_l < rtB.maxmn; rtB.k_l++) {
      if (b_A->data[b_A->size[0] * rtB.k_l + rtB.k_l] != 0.0) {
        rtB.minmn++;
      }
    }
  }

  emxInit_real_T(&b_B, 1);
  rtB.maxmn = b_B->size[0];
  b_B->size[0] = B_0->size[0];
  emxEnsureCapacity_real_T(b_B, rtB.maxmn);
  rtB.maxmn = B_0->size[0];
  if (rtB.maxmn - 1 >= 0) {
    memcpy(&b_B->data[0], &B_0->data[0], static_cast<uint32_T>(rtB.maxmn) *
           sizeof(real_T));
  }

  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  rtB.maxmn = b_A->size[0];
  if (b_A->size[0] <= 3) {
    rtB.k_l = b_A->size[0];
  } else {
    rtB.k_l = 3;
  }

  for (rtB.b_j = 0; rtB.b_j < rtB.k_l; rtB.b_j++) {
    if (rtB.tau_data[rtB.b_j] != 0.0) {
      rtB.tol = b_B->data[rtB.b_j];
      for (rtB.c_i = rtB.b_j + 2; rtB.c_i <= rtB.maxmn; rtB.c_i++) {
        rtB.tol += b_A->data[(b_A->size[0] * rtB.b_j + rtB.c_i) - 1] * b_B->
          data[rtB.c_i - 1];
      }

      rtB.tol *= rtB.tau_data[rtB.b_j];
      if (rtB.tol != 0.0) {
        b_B->data[rtB.b_j] -= rtB.tol;
        for (rtB.c_i = rtB.b_j + 2; rtB.c_i <= rtB.maxmn; rtB.c_i++) {
          b_B->data[rtB.c_i - 1] -= b_A->data[(b_A->size[0] * rtB.b_j + rtB.c_i)
            - 1] * rtB.tol;
        }
      }
    }
  }

  for (rtB.maxmn = 0; rtB.maxmn < rtB.minmn; rtB.maxmn++) {
    Y[rtB.jpvt[rtB.maxmn] - 1] = b_B->data[rtB.maxmn];
  }

  emxFree_real_T(&b_B);
  for (rtB.maxmn = rtB.minmn; rtB.maxmn >= 1; rtB.maxmn--) {
    rtB.k_l = rtB.jpvt[rtB.maxmn - 1];
    Y[rtB.k_l - 1] /= b_A->data[((rtB.maxmn - 1) * b_A->size[0] + rtB.maxmn) - 1];
    for (rtB.b_j = 0; rtB.b_j <= rtB.maxmn - 2; rtB.b_j++) {
      Y[rtB.jpvt[rtB.b_j] - 1] -= b_A->data[(rtB.maxmn - 1) * b_A->size[0] +
        rtB.b_j] * Y[rtB.k_l - 1];
    }
  }

  emxFree_real_T(&b_A);
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static void polyfit(const emxArray_real_T *x, const emxArray_real_T *y, real_T
                    p[3])
{
  emxArray_real_T *V;
  emxInit_real_T(&V, 2);
  rtB.k_d = V->size[0] * V->size[1];
  V->size[0] = x->size[0];
  V->size[1] = 3;
  emxEnsureCapacity_real_T(V, rtB.k_d);
  if (x->size[0] != 0) {
    rtB.b_d = x->size[0];
    for (rtB.k_d = 0; rtB.k_d < rtB.b_d; rtB.k_d++) {
      V->data[rtB.k_d + (V->size[0] << 1)] = 1.0;
      rtB.x_c = x->data[rtB.k_d];
      V->data[rtB.k_d + V->size[0]] = rtB.x_c;
      V->data[rtB.k_d] = rtB.x_c * rtB.x_c;
    }
  }

  qrsolve(V, y, p, &rtB.b_d);
  emxFree_real_T(&V);
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

// Model step function
void Rpi_cam_step(void)
{
  emxArray_boolean_T *b;
  emxArray_boolean_T *b_tmp;
  emxArray_boolean_T *b_tmp_tmp;
  emxArray_boolean_T *r;
  emxArray_boolean_T *t;
  emxArray_boolean_T *tmp_0;
  emxArray_boolean_T *tmp_1;
  emxArray_boolean_T *tmp_2;
  emxArray_boolean_T *tmp_3;
  emxArray_boolean_T *tmp_4;
  emxArray_boolean_T *tmp_5;
  emxArray_boolean_T *tmp_6;
  emxArray_boolean_T *tmp_7;
  emxArray_boolean_T *tmp_8;
  emxArray_boolean_T *tmp_9;
  emxArray_boolean_T *tmp_a;
  emxArray_boolean_T *tmp_b;
  emxArray_boolean_T *tmp_c;
  emxArray_boolean_T *tmp_d;
  emxArray_boolean_T *tmp_e;
  emxArray_boolean_T *tmp_f;
  emxArray_boolean_T *tmp_g;
  emxArray_boolean_T *tmp_h;
  emxArray_boolean_T *tmp_i;
  emxArray_boolean_T *tmp_j;
  emxArray_boolean_T *tmp_k;
  emxArray_boolean_T *tmp_l;
  emxArray_int32_T *ii;
  emxArray_int32_T *jj;
  emxArray_int32_T *n_tmp;
  emxArray_int32_T *tmp;
  emxArray_int32_T *tmp_m;
  emxArray_int32_T *tmp_n;
  emxArray_int32_T *tmp_o;
  emxArray_int32_T *tmp_p;
  emxArray_int32_T *tmp_q;
  emxArray_int32_T *tmp_r;
  emxArray_int32_T *tmp_s;
  emxArray_int32_T *tmp_t;
  emxArray_int32_T *tmp_u;
  emxArray_int32_T *tmp_v;
  emxArray_int32_T *tmp_w;
  emxArray_int32_T *tmp_x;
  emxArray_int32_T *tmp_y;
  emxArray_real_T *jj_0;
  emxArray_real_T *left_lane_index;
  emxArray_real_T *left_lane_index_0;
  static const int16_T tmp_z[8] = { 110, 500, 1, 639, 300, 300, 390, 415 };

  static const int16_T tmp_10[8] = { 40, 600, 40, 600, 300, 300, 480, 480 };

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

  SystemCore_step(&rtDW.obj, rtB.b_varargout_1, rtB.b_varargout_2,
                  rtB.b_varargout_3);

  // Math: '<S3>/Transpose' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'
  //
  for (rtB.bestCol = 0; rtB.bestCol < 640; rtB.bestCol++) {
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 480; rtB.bestInlierNum++) {
      rtB.b_varargout_1_c[rtB.bestInlierNum + 480 * rtB.bestCol] =
        rtB.b_varargout_1[640 * rtB.bestInlierNum + rtB.bestCol];
    }
  }

  memcpy(&rtB.outputImage[0], &rtB.b_varargout_1_c[0], 307200U * sizeof(uint8_T));

  // End of Math: '<S3>/Transpose'

  // Math: '<S3>/Transpose1' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'
  //
  for (rtB.bestCol = 0; rtB.bestCol < 640; rtB.bestCol++) {
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 480; rtB.bestInlierNum++) {
      rtB.b_varargout_1[rtB.bestInlierNum + 480 * rtB.bestCol] =
        rtB.b_varargout_2[640 * rtB.bestInlierNum + rtB.bestCol];
    }
  }

  memcpy(&rtB.outputImage[307200], &rtB.b_varargout_1[0], 307200U * sizeof
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
  for (rtB.bestCol = 0; rtB.bestCol < 3; rtB.bestCol++) {
    for (rtB.j_g = 0; rtB.j_g < 640; rtB.j_g++) {
      for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 240; rtB.bestInlierNum++)
      {
        rtB.k = (480 * rtB.j_g + rtB.bestInlierNum) + 307200 * rtB.bestCol;
        rtB.xtmp = rtB.outputImage[rtB.k];
        rtB.line_flag = ((480 * rtB.j_g - rtB.bestInlierNum) + 307200 *
                         rtB.bestCol) + 479;
        rtB.outputImage[rtB.k] = rtB.outputImage[rtB.line_flag];
        rtB.outputImage[rtB.line_flag] = rtB.xtmp;
      }
    }

    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 320; rtB.bestInlierNum++) {
      for (rtB.j_g = 0; rtB.j_g < 480; rtB.j_g++) {
        rtB.k = (480 * rtB.bestInlierNum + rtB.j_g) + 307200 * rtB.bestCol;
        rtB.xtmp = rtB.outputImage[rtB.k];
        rtB.line_flag = ((639 - rtB.bestInlierNum) * 480 + rtB.j_g) + 307200 *
          rtB.bestCol;
        rtB.outputImage[rtB.k] = rtB.outputImage[rtB.line_flag];
        rtB.outputImage[rtB.line_flag] = rtB.xtmp;
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
    rtB.win_y_low = rtB.ImageDataTypeConversion[rtB.bestInlierNum + 307200];
    if (rtB.sum > rtB.win_y_low) {
      rtB.win_y_high = rtB.ImageDataTypeConversion[rtB.bestInlierNum + 614400];
      if (rtB.win_y_low < rtB.win_y_high) {
        rtB.min = rtB.win_y_low;
      } else {
        rtB.min = rtB.win_y_high;
      }

      if (rtB.sum > rtB.win_y_high) {
        rtB.maxSum = rtB.sum;
      } else {
        rtB.maxSum = rtB.win_y_high;
      }
    } else {
      rtB.win_y_high = rtB.ImageDataTypeConversion[rtB.bestInlierNum + 614400];
      if (rtB.sum < rtB.win_y_high) {
        rtB.min = rtB.sum;
      } else {
        rtB.min = rtB.win_y_high;
      }

      if (rtB.win_y_low > rtB.win_y_high) {
        rtB.maxSum = rtB.win_y_low;
      } else {
        rtB.maxSum = rtB.win_y_high;
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
        rtB.sum = (rtB.win_y_low - rtB.win_y_high) / rtB.s;
      } else if (rtB.win_y_low == rtB.maxSum) {
        rtB.sum = (rtB.win_y_high - rtB.sum) / rtB.s + 2.0;
      } else {
        rtB.sum = (rtB.sum - rtB.win_y_low) / rtB.s + 4.0;
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
    rtB.pts1[rtB.bestCol] = tmp_z[rtB.bestCol];

    // MATLAB Function: '<S4>/MATLAB Function2'
    rtB.pts2[rtB.bestCol] = tmp_10[rtB.bestCol];
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
  normPts_D_D((const real_T *)&rtB.pts1[0], (const uint32_T *)
              &rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
              &rtDW.EstimateGeometricTransformation_DW_PTSNORM1[0], &rtB.scale1,
              &rtB.cents1[0]);
  normPts_D_D((const real_T *)&rtB.pts2[0], (const uint32_T *)
              &rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
              &rtDW.EstimateGeometricTransformation_DW_PTSNORM2[0], &rtB.scale2,
              &rtB.cents2[0]);
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
    for (rtB.j_g = 0; rtB.j_g < 9; rtB.j_g++) {
      if (static_cast<uint32_T>(rtB.bestInlierNum) != static_cast<uint32_T>
          (rtB.j_g)) {
        rtB.sum = 0.0;
      } else {
        rtB.sum = -1.0;
      }

      for (rtB.k = 0; rtB.k < 8; rtB.k++) {
        rtB.idx = static_cast<uint32_T>(rtB.k) * 9U;
        rtB.sum += rtB.Q[rtB.idx + static_cast<uint32_T>(rtB.bestInlierNum)] *
          rtB.Q[rtB.idx + static_cast<uint32_T>(rtB.j_g)];
      }

      rtB.RV[static_cast<uint32_T>(rtB.bestInlierNum) * 9U +
        static_cast<uint32_T>(rtB.j_g)] = rtB.sum;
      if (!(rtB.sum >= 0.0)) {
        rtB.sum = -rtB.sum;
      }

      if (rtB.maxSum < rtB.sum) {
        rtB.maxSum = rtB.sum;
        rtB.bestCol = rtB.bestInlierNum;
      }
    }
  }

  rtB.j_g = static_cast<int32_T>(static_cast<uint32_T>(rtB.bestCol) * 9U);
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 9; rtB.bestInlierNum++) {
    rtB.tformCompact[static_cast<uint32_T>(rtB.bestInlierNum)] = rtB.RV[
      static_cast<uint32_T>(rtB.j_g) + static_cast<uint32_T>(rtB.bestInlierNum)];
  }

  rtB.scale2 = 1.0 / rtB.scale2;
  rtB.maxSum = rtB.scale1 * rtB.scale2;
  rtB.tformCompact_k[6] = rtB.tformCompact[6] * rtB.scale1;
  rtB.tformCompact_k[7] = rtB.tformCompact[7] * rtB.scale1;
  rtB.tformCompact_k[8] = (rtB.tformCompact[8] - rtB.cents1[0] *
    rtB.tformCompact_k[6]) - rtB.cents1[1] * rtB.tformCompact_k[7];
  rtB.tformCompact_k[0] = rtB.tformCompact[0] * rtB.maxSum;
  rtB.tformCompact_k[1] = rtB.tformCompact[1] * rtB.maxSum;
  rtB.tformCompact_k[2] = ((rtB.cents2[0] * rtB.tformCompact_k[8] -
    rtB.tformCompact_k[0] * rtB.cents1[0]) - rtB.tformCompact_k[1] * rtB.cents1
    [1]) + rtB.tformCompact[2] * rtB.scale2;
  rtB.tformCompact_k[3] = rtB.tformCompact[3] * rtB.maxSum;
  rtB.tformCompact_k[4] = rtB.tformCompact[4] * rtB.maxSum;
  rtB.tformCompact_k[5] = ((rtB.cents2[1] * rtB.tformCompact_k[8] - rtB.cents1[0]
    * rtB.tformCompact_k[3]) - rtB.cents1[1] * rtB.tformCompact_k[4]) +
    rtB.tformCompact[5] * rtB.scale2;
  rtB.tformCompact_k[0] += rtB.cents2[0] * rtB.tformCompact_k[6];
  rtB.tformCompact_k[1] += rtB.cents2[0] * rtB.tformCompact_k[7];
  rtB.tformCompact_k[3] += rtB.cents2[1] * rtB.tformCompact_k[6];
  rtB.tformCompact_k[4] += rtB.cents2[1] * rtB.tformCompact_k[7];
  if (rtB.tformCompact_k[8U] != 0.0) {
    rtB.scale1 = 1.0 / rtB.tformCompact_k[8];
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 8; rtB.bestInlierNum++) {
      rtB.tformCompact_k[static_cast<uint32_T>(rtB.bestInlierNum)] *= rtB.scale1;
    }

    rtB.tformCompact_k[8] = 1.0;
    rtB.idx = 0U;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 4; rtB.bestInlierNum++) {
      rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_T>
        (rtB.bestInlierNum)] = 0.0;
      for (rtB.j_g = 0; rtB.j_g < 2; rtB.j_g++) {
        rtB.scale1 = 0.0;
        for (rtB.k = 0; rtB.k < 9; rtB.k++) {
          rtB.scale1 +=
            rtDW.EstimateGeometricTransformation_DW_CONSTRT_ALL[rtB.idx +
            static_cast<uint32_T>(rtB.k)] * rtB.tformCompact_k
            [static_cast<uint32_T>(rtB.k)];
        }

        rtB.idx += 9U;
        rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_T>
          (rtB.bestInlierNum)] += rtB.scale1 * rtB.scale1;
      }
    }

    memcpy(&rtB.bestTFormCompact[0], &rtB.tformCompact_k[0], 9U * sizeof(real_T));
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
                rtB.EstimateGeometricTransformation, rtB.bv);

  // MATLAB Function: '<S2>/ImageToRGB'
  for (rtB.bestCol = 0; rtB.bestCol < 480; rtB.bestCol++) {
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 640; rtB.bestInlierNum++) {
      rtB.line_flag = 480 * rtB.bestInlierNum + rtB.bestCol;
      rtB.j_g = 640 * rtB.bestCol + rtB.bestInlierNum;
      rtB.R[rtB.j_g] = rtB.outputImage[rtB.line_flag];
      rtB.G[rtB.j_g] = rtB.outputImage[rtB.line_flag + 307200];
      rtB.B_n[rtB.j_g] = rtB.outputImage[rtB.line_flag + 614400];
    }
  }

  // End of MATLAB Function: '<S2>/ImageToRGB'
  // MATLABSystem: '<S7>/MATLAB System'
  memcpy(&rtB.b_varargout_1[0], &rtB.R[0], 307200U * sizeof(uint8_T));
  memcpy(&rtB.b_varargout_2[0], &rtB.G[0], 307200U * sizeof(uint8_T));
  memcpy(&rtB.b_varargout_3[0], &rtB.B_n[0], 307200U * sizeof(uint8_T));
  MW_SDL_videoDisplayOutput(&rtB.b_varargout_1[0], &rtB.b_varargout_2[0],
    &rtB.b_varargout_3[0], rtDW.obj_a.displayId);

  // MATLAB Function: '<S2>/MATLAB Function1'
  memset(&rtB.left_lane_index[0], 0, 200000U * sizeof(real_T));
  memset(&rtB.right_lane_index[0], 0, 200000U * sizeof(real_T));
  emxInit_int32_T(&ii, 1);
  emxInit_int32_T(&jj, 1);

  // MATLAB Function: '<S2>/MATLAB Function1' incorporates:
  //   MATLABSystem: '<S4>/Warp'

  eml_find(rtB.bv, ii, jj);
  emxInit_boolean_T(&b_tmp_tmp, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.i_l = b_tmp_tmp->size[0];
  b_tmp_tmp->size[0] = ii->size[0];
  emxEnsureCapacity_boolean_T(b_tmp_tmp, rtB.i_l);
  rtB.j_g = ii->size[0];
  for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
    rtB.k = ii->data[rtB.bestCol];
    b_tmp_tmp->data[rtB.bestCol] = ((rtB.k >= 456) && (rtB.k < 480));
  }

  emxInit_boolean_T(&b_tmp, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (b_tmp_tmp->size[0] == jj->size[0]) {
    rtB.i_l = b_tmp->size[0];
    b_tmp->size[0] = b_tmp_tmp->size[0];
    emxEnsureCapacity_boolean_T(b_tmp, rtB.i_l);
    rtB.j_g = b_tmp_tmp->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
      b_tmp->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && (jj->
        data[rtB.bestCol] >= 0));
    }
  } else {
    binary_expand_op_5(b_tmp, b_tmp_tmp, jj);
  }

  emxInit_boolean_T(&r, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.i_l = r->size[0];
  r->size[0] = jj->size[0];
  emxEnsureCapacity_boolean_T(r, rtB.i_l);
  rtB.j_g = jj->size[0];
  for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
    r->data[rtB.bestCol] = (jj->data[rtB.bestCol] < 160);
  }

  if (b_tmp_tmp->size[0] == jj->size[0]) {
    rtB.j_g = b_tmp_tmp->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
      b_tmp_tmp->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && (jj->
        data[rtB.bestCol] >= 480));
    }
  } else {
    binary_expand_op_4(b_tmp_tmp, jj);
  }

  emxInit_boolean_T(&t, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.i_l = t->size[0];
  t->size[0] = jj->size[0];
  emxEnsureCapacity_boolean_T(t, rtB.i_l);
  rtB.j_g = jj->size[0];
  for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
    t->data[rtB.bestCol] = (jj->data[rtB.bestCol] < 640);
  }

  emxInit_boolean_T(&tmp_0, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (b_tmp->size[0] == r->size[0]) {
    rtB.i_l = tmp_0->size[0];
    tmp_0->size[0] = b_tmp->size[0];
    emxEnsureCapacity_boolean_T(tmp_0, rtB.i_l);
    rtB.j_g = b_tmp->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
      tmp_0->data[rtB.bestCol] = (b_tmp->data[rtB.bestCol] && r->
        data[rtB.bestCol]);
    }
  } else {
    and_o(tmp_0, b_tmp, r);
  }

  rtB.bestCol = tmp_0->size[0] - 1;
  rtB.j_g = 0;
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
       rtB.bestInlierNum++) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    if (tmp_0->data[rtB.bestInlierNum]) {
      rtB.j_g++;
    }
  }

  emxFree_boolean_T(&tmp_0);
  emxInit_int32_T(&n_tmp, 1);
  emxInit_boolean_T(&tmp_2, 1);
  emxInit_boolean_T(&tmp_3, 1);
  emxInit_int32_T(&tmp_m, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  for (rtB.line_flag = 0; rtB.line_flag < rtB.j_g; rtB.line_flag++) {
    rtB.bestInlierNum = b_tmp->size[0];
    if (b_tmp->size[0] == r->size[0]) {
      rtB.i_l = tmp_2->size[0];
      tmp_2->size[0] = b_tmp->size[0];
      emxEnsureCapacity_boolean_T(tmp_2, rtB.i_l);
      for (rtB.bestCol = 0; rtB.bestCol < rtB.bestInlierNum; rtB.bestCol++) {
        tmp_2->data[rtB.bestCol] = (b_tmp->data[rtB.bestCol] && r->
          data[rtB.bestCol]);
      }
    } else {
      and_o(tmp_2, b_tmp, r);
    }

    rtB.bestInlierNum = b_tmp->size[0];
    if (b_tmp->size[0] == r->size[0]) {
      rtB.i_l = tmp_3->size[0];
      tmp_3->size[0] = b_tmp->size[0];
      emxEnsureCapacity_boolean_T(tmp_3, rtB.i_l);
      for (rtB.bestCol = 0; rtB.bestCol < rtB.bestInlierNum; rtB.bestCol++) {
        tmp_3->data[rtB.bestCol] = (b_tmp->data[rtB.bestCol] && r->
          data[rtB.bestCol]);
      }
    } else {
      and_o(tmp_3, b_tmp, r);
    }

    rtB.bestCol = tmp_2->size[0] - 1;
    rtB.k = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_2->data[rtB.bestInlierNum]) {
        rtB.k++;
      }
    }

    rtB.i_l = n_tmp->size[0];
    n_tmp->size[0] = rtB.k;
    emxEnsureCapacity_int32_T(n_tmp, rtB.i_l);
    rtB.partialTrueCount = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_2->data[rtB.bestInlierNum]) {
        n_tmp->data[rtB.partialTrueCount] = rtB.bestInlierNum;
        rtB.partialTrueCount++;
      }
    }

    rtB.bestCol = tmp_3->size[0] - 1;
    rtB.k = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_3->data[rtB.bestInlierNum]) {
        rtB.k++;
      }
    }

    rtB.i_l = tmp_m->size[0];
    tmp_m->size[0] = rtB.k;
    emxEnsureCapacity_int32_T(tmp_m, rtB.i_l);
    rtB.partialTrueCount = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_3->data[rtB.bestInlierNum]) {
        tmp_m->data[rtB.partialTrueCount] = rtB.bestInlierNum;
        rtB.partialTrueCount++;
      }
    }

    rtB.left_lane_index[rtB.line_flag] = jj->data[n_tmp->data[rtB.line_flag]];
    rtB.left_lane_index[rtB.line_flag + 100000] = ii->data[tmp_m->
      data[rtB.line_flag]];
  }

  emxFree_int32_T(&tmp_m);
  emxFree_boolean_T(&tmp_3);
  emxFree_boolean_T(&tmp_2);
  emxInit_boolean_T(&tmp_1, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (b_tmp_tmp->size[0] == t->size[0]) {
    rtB.i_l = tmp_1->size[0];
    tmp_1->size[0] = b_tmp_tmp->size[0];
    emxEnsureCapacity_boolean_T(tmp_1, rtB.i_l);
    rtB.j_g = b_tmp_tmp->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
      tmp_1->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && t->
        data[rtB.bestCol]);
    }
  } else {
    and_o(tmp_1, b_tmp_tmp, t);
  }

  rtB.bestCol = tmp_1->size[0] - 1;
  rtB.j_g = 0;
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
       rtB.bestInlierNum++) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    if (tmp_1->data[rtB.bestInlierNum]) {
      rtB.j_g++;
    }
  }

  emxFree_boolean_T(&tmp_1);
  emxInit_boolean_T(&tmp_5, 1);
  emxInit_boolean_T(&tmp_6, 1);
  emxInit_int32_T(&tmp_n, 1);
  emxInit_int32_T(&tmp_o, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  for (rtB.line_flag = 0; rtB.line_flag < rtB.j_g; rtB.line_flag++) {
    rtB.partialTrueCount = b_tmp_tmp->size[0];
    if (b_tmp_tmp->size[0] == t->size[0]) {
      rtB.i_l = tmp_5->size[0];
      tmp_5->size[0] = b_tmp_tmp->size[0];
      emxEnsureCapacity_boolean_T(tmp_5, rtB.i_l);
      for (rtB.bestCol = 0; rtB.bestCol < rtB.partialTrueCount; rtB.bestCol++) {
        tmp_5->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && t->
          data[rtB.bestCol]);
      }
    } else {
      and_o(tmp_5, b_tmp_tmp, t);
    }

    rtB.partialTrueCount = b_tmp_tmp->size[0];
    if (b_tmp_tmp->size[0] == t->size[0]) {
      rtB.i_l = tmp_6->size[0];
      tmp_6->size[0] = b_tmp_tmp->size[0];
      emxEnsureCapacity_boolean_T(tmp_6, rtB.i_l);
      for (rtB.bestCol = 0; rtB.bestCol < rtB.partialTrueCount; rtB.bestCol++) {
        tmp_6->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && t->
          data[rtB.bestCol]);
      }
    } else {
      and_o(tmp_6, b_tmp_tmp, t);
    }

    rtB.bestCol = tmp_5->size[0] - 1;
    rtB.k = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_5->data[rtB.bestInlierNum]) {
        rtB.k++;
      }
    }

    rtB.i_l = tmp_n->size[0];
    tmp_n->size[0] = rtB.k;
    emxEnsureCapacity_int32_T(tmp_n, rtB.i_l);
    rtB.partialTrueCount = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_5->data[rtB.bestInlierNum]) {
        tmp_n->data[rtB.partialTrueCount] = rtB.bestInlierNum;
        rtB.partialTrueCount++;
      }
    }

    rtB.bestCol = tmp_6->size[0] - 1;
    rtB.k = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_6->data[rtB.bestInlierNum]) {
        rtB.k++;
      }
    }

    rtB.i_l = tmp_o->size[0];
    tmp_o->size[0] = rtB.k;
    emxEnsureCapacity_int32_T(tmp_o, rtB.i_l);
    rtB.partialTrueCount = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_6->data[rtB.bestInlierNum]) {
        tmp_o->data[rtB.partialTrueCount] = rtB.bestInlierNum;
        rtB.partialTrueCount++;
      }
    }

    rtB.right_lane_index[rtB.line_flag] = jj->data[tmp_n->data[rtB.line_flag]];
    rtB.right_lane_index[rtB.line_flag + 100000] = ii->data[tmp_o->
      data[rtB.line_flag]];
  }

  emxFree_int32_T(&tmp_o);
  emxFree_int32_T(&tmp_n);
  emxFree_boolean_T(&tmp_6);
  emxFree_boolean_T(&tmp_5);
  emxInit_boolean_T(&tmp_4, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (b_tmp_tmp->size[0] == t->size[0]) {
    rtB.i_l = tmp_4->size[0];
    tmp_4->size[0] = b_tmp_tmp->size[0];
    emxEnsureCapacity_boolean_T(tmp_4, rtB.i_l);
    rtB.j_g = b_tmp_tmp->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
      tmp_4->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && t->
        data[rtB.bestCol]);
    }
  } else {
    and_o(tmp_4, b_tmp_tmp, t);
  }

  rtB.bestCol = tmp_4->size[0] - 1;
  rtB.j_g = 0;
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
       rtB.bestInlierNum++) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    if (tmp_4->data[rtB.bestInlierNum]) {
      rtB.j_g++;
    }
  }

  emxFree_boolean_T(&tmp_4);
  emxInit_boolean_T(&tmp_7, 1);
  emxInit_boolean_T(&tmp_8, 1);
  emxInit_int32_T(&tmp_p, 1);
  emxInit_int32_T(&tmp_q, 1);
  emxInit_real_T(&jj_0, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (rtB.j_g > 30) {
    rtB.line_flag = 1;
    if (b_tmp_tmp->size[0] == t->size[0]) {
      rtB.i_l = tmp_7->size[0];
      tmp_7->size[0] = b_tmp_tmp->size[0];
      emxEnsureCapacity_boolean_T(tmp_7, rtB.i_l);
      rtB.j_g = b_tmp_tmp->size[0];
      for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
        tmp_7->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && t->
          data[rtB.bestCol]);
      }
    } else {
      and_o(tmp_7, b_tmp_tmp, t);
    }

    rtB.bestCol = tmp_7->size[0] - 1;
    rtB.j_g = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_7->data[rtB.bestInlierNum]) {
        rtB.j_g++;
      }
    }

    rtB.i_l = tmp_p->size[0];
    tmp_p->size[0] = rtB.j_g;
    emxEnsureCapacity_int32_T(tmp_p, rtB.i_l);
    rtB.partialTrueCount = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_7->data[rtB.bestInlierNum]) {
        tmp_p->data[rtB.partialTrueCount] = rtB.bestInlierNum;
        rtB.partialTrueCount++;
      }
    }

    rtB.i_l = jj_0->size[0];
    jj_0->size[0] = tmp_p->size[0];
    emxEnsureCapacity_real_T(jj_0, rtB.i_l);
    rtB.j_g = tmp_p->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
      jj_0->data[rtB.bestCol] = jj->data[tmp_p->data[rtB.bestCol]];
    }

    rtB.scale1 = mean(jj_0);
    if (b_tmp_tmp->size[0] == t->size[0]) {
      rtB.i_l = tmp_8->size[0];
      tmp_8->size[0] = b_tmp_tmp->size[0];
      emxEnsureCapacity_boolean_T(tmp_8, rtB.i_l);
      rtB.j_g = b_tmp_tmp->size[0];
      for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
        tmp_8->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && t->
          data[rtB.bestCol]);
      }
    } else {
      and_o(tmp_8, b_tmp_tmp, t);
    }

    rtB.bestCol = tmp_8->size[0] - 1;
    rtB.j_g = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_8->data[rtB.bestInlierNum]) {
        rtB.j_g++;
      }
    }

    rtB.i_l = tmp_q->size[0];
    tmp_q->size[0] = rtB.j_g;
    emxEnsureCapacity_int32_T(tmp_q, rtB.i_l);
    rtB.partialTrueCount = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_8->data[rtB.bestInlierNum]) {
        tmp_q->data[rtB.partialTrueCount] = rtB.bestInlierNum;
        rtB.partialTrueCount++;
      }
    }

    rtB.i_l = jj_0->size[0];
    jj_0->size[0] = tmp_q->size[0];
    emxEnsureCapacity_real_T(jj_0, rtB.i_l);
    rtB.j_g = tmp_q->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
      jj_0->data[rtB.bestCol] = ii->data[tmp_q->data[rtB.bestCol]];
    }

    rtB.scale2 = maximum(jj_0);
  } else {
    rtB.line_flag = 2;
    if (b_tmp->size[0] == r->size[0]) {
      rtB.i_l = tmp_7->size[0];
      tmp_7->size[0] = b_tmp->size[0];
      emxEnsureCapacity_boolean_T(tmp_7, rtB.i_l);
      rtB.j_g = b_tmp->size[0];
      for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
        tmp_7->data[rtB.bestCol] = (b_tmp->data[rtB.bestCol] && r->
          data[rtB.bestCol]);
      }
    } else {
      and_o(tmp_7, b_tmp, r);
    }

    rtB.bestCol = tmp_7->size[0] - 1;
    rtB.j_g = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_7->data[rtB.bestInlierNum]) {
        rtB.j_g++;
      }
    }

    rtB.i_l = tmp_p->size[0];
    tmp_p->size[0] = rtB.j_g;
    emxEnsureCapacity_int32_T(tmp_p, rtB.i_l);
    rtB.partialTrueCount = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_7->data[rtB.bestInlierNum]) {
        tmp_p->data[rtB.partialTrueCount] = rtB.bestInlierNum;
        rtB.partialTrueCount++;
      }
    }

    rtB.i_l = jj_0->size[0];
    jj_0->size[0] = tmp_p->size[0];
    emxEnsureCapacity_real_T(jj_0, rtB.i_l);
    rtB.j_g = tmp_p->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
      jj_0->data[rtB.bestCol] = jj->data[tmp_p->data[rtB.bestCol]];
    }

    rtB.scale1 = mean(jj_0);
    if (b_tmp->size[0] == r->size[0]) {
      rtB.i_l = tmp_8->size[0];
      tmp_8->size[0] = b_tmp->size[0];
      emxEnsureCapacity_boolean_T(tmp_8, rtB.i_l);
      rtB.j_g = b_tmp->size[0];
      for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
        tmp_8->data[rtB.bestCol] = (b_tmp->data[rtB.bestCol] && r->
          data[rtB.bestCol]);
      }
    } else {
      and_o(tmp_8, b_tmp, r);
    }

    rtB.bestCol = tmp_8->size[0] - 1;
    rtB.j_g = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_8->data[rtB.bestInlierNum]) {
        rtB.j_g++;
      }
    }

    rtB.i_l = tmp_q->size[0];
    tmp_q->size[0] = rtB.j_g;
    emxEnsureCapacity_int32_T(tmp_q, rtB.i_l);
    rtB.partialTrueCount = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.bestCol;
         rtB.bestInlierNum++) {
      if (tmp_8->data[rtB.bestInlierNum]) {
        tmp_q->data[rtB.partialTrueCount] = rtB.bestInlierNum;
        rtB.partialTrueCount++;
      }
    }

    rtB.i_l = jj_0->size[0];
    jj_0->size[0] = tmp_q->size[0];
    emxEnsureCapacity_real_T(jj_0, rtB.i_l);
    rtB.j_g = tmp_q->size[0];
    for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
      jj_0->data[rtB.bestCol] = ii->data[tmp_q->data[rtB.bestCol]];
    }

    rtB.scale2 = maximum(jj_0);
  }

  emxFree_int32_T(&tmp_q);
  emxFree_int32_T(&tmp_p);
  emxFree_boolean_T(&tmp_8);
  emxFree_boolean_T(&tmp_7);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.maxSum = 0.0;
  rtB.sum = 0.0;
  emxInit_boolean_T(&b, 1);
  emxInit_int32_T(&tmp, 1);
  emxInit_boolean_T(&tmp_9, 1);
  emxInit_boolean_T(&tmp_a, 1);
  emxInit_boolean_T(&tmp_b, 1);
  emxInit_boolean_T(&tmp_c, 1);
  emxInit_boolean_T(&tmp_d, 1);
  emxInit_boolean_T(&tmp_e, 1);
  emxInit_boolean_T(&tmp_f, 1);
  emxInit_boolean_T(&tmp_g, 1);
  emxInit_boolean_T(&tmp_h, 1);
  emxInit_boolean_T(&tmp_i, 1);
  emxInit_boolean_T(&tmp_j, 1);
  emxInit_boolean_T(&tmp_k, 1);
  emxInit_boolean_T(&tmp_l, 1);
  emxInit_int32_T(&tmp_r, 1);
  emxInit_int32_T(&tmp_s, 1);
  emxInit_int32_T(&tmp_t, 1);
  emxInit_int32_T(&tmp_u, 1);
  emxInit_int32_T(&tmp_v, 1);
  emxInit_int32_T(&tmp_w, 1);
  emxInit_int32_T(&tmp_x, 1);
  emxInit_int32_T(&tmp_y, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 20; rtB.bestInlierNum++) {
    if (rtB.line_flag == 1) {
      rtB.win_y_low = rtB.scale2 - ((static_cast<real_T>(rtB.bestInlierNum) +
        1.0) + 1.0) * 24.0;
      rtB.win_y_high = rtB.scale2 - (static_cast<real_T>(rtB.bestInlierNum) +
        1.0) * 24.0;
      rtB.k = ii->size[0];
      rtB.i_l = n_tmp->size[0];
      n_tmp->size[0] = ii->size[0];
      emxEnsureCapacity_int32_T(n_tmp, rtB.i_l);
      if (rtB.k - 1 >= 0) {
        memcpy(&n_tmp->data[0], &ii->data[0], static_cast<uint32_T>(rtB.k) *
               sizeof(int32_T));
      }

      rtB.i_l = b_tmp_tmp->size[0];
      b_tmp_tmp->size[0] = n_tmp->size[0];
      emxEnsureCapacity_boolean_T(b_tmp_tmp, rtB.i_l);
      rtB.j_g = n_tmp->size[0];
      rtB.i_l = b_tmp->size[0];
      b_tmp->size[0] = n_tmp->size[0];
      emxEnsureCapacity_boolean_T(b_tmp, rtB.i_l);
      for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
        rtB.k = n_tmp->data[rtB.bestCol];
        b_tmp_tmp->data[rtB.bestCol] = (rtB.k >= rtB.win_y_low);
        b_tmp->data[rtB.bestCol] = (rtB.k < rtB.win_y_high);
      }

      rtB.j_g = jj->size[0];
      rtB.i_l = n_tmp->size[0];
      n_tmp->size[0] = jj->size[0];
      emxEnsureCapacity_int32_T(n_tmp, rtB.i_l);
      if (rtB.j_g - 1 >= 0) {
        memcpy(&n_tmp->data[0], &jj->data[0], static_cast<uint32_T>(rtB.j_g) *
               sizeof(int32_T));
      }

      rtB.i_l = t->size[0];
      t->size[0] = n_tmp->size[0];
      emxEnsureCapacity_boolean_T(t, rtB.i_l);
      rtB.j_g = n_tmp->size[0];
      for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
        t->data[rtB.bestCol] = (n_tmp->data[rtB.bestCol] >= rtB.scale1 - 40.0);
      }

      if (b_tmp_tmp->size[0] == t->size[0]) {
        rtB.i_l = b->size[0];
        b->size[0] = b_tmp_tmp->size[0];
        emxEnsureCapacity_boolean_T(b, rtB.i_l);
        rtB.j_g = b_tmp_tmp->size[0];
        for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
          b->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && b_tmp->
            data[rtB.bestCol] && t->data[rtB.bestCol]);
        }
      } else {
        binary_expand_op_1(b, b_tmp_tmp, b_tmp, t);
      }

      rtB.i_l = r->size[0];
      r->size[0] = n_tmp->size[0];
      emxEnsureCapacity_boolean_T(r, rtB.i_l);
      rtB.j_g = n_tmp->size[0];
      for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
        r->data[rtB.bestCol] = (n_tmp->data[rtB.bestCol] < rtB.scale1 + 40.0);
      }

      if (b_tmp_tmp->size[0] == t->size[0]) {
        rtB.j_g = b_tmp_tmp->size[0];
        for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
          b_tmp_tmp->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] &&
            b_tmp->data[rtB.bestCol] && t->data[rtB.bestCol]);
        }
      } else {
        binary_expand_op(b_tmp_tmp, b_tmp, t);
      }

      if (b->size[0] == r->size[0]) {
        rtB.i_l = tmp_a->size[0];
        tmp_a->size[0] = b->size[0];
        emxEnsureCapacity_boolean_T(tmp_a, rtB.i_l);
        rtB.j_g = b->size[0];
        for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
          tmp_a->data[rtB.bestCol] = (b->data[rtB.bestCol] && r->
            data[rtB.bestCol]);
        }
      } else {
        and_o(tmp_a, b, r);
      }

      rtB.bestCol = tmp_a->size[0] - 1;
      rtB.j_g = 0;
      for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
        if (tmp_a->data[rtB.i_l]) {
          rtB.j_g++;
        }
      }

      if (rtB.j_g > 30) {
        if (b->size[0] == r->size[0]) {
          rtB.i_l = tmp_c->size[0];
          tmp_c->size[0] = b->size[0];
          emxEnsureCapacity_boolean_T(tmp_c, rtB.i_l);
          rtB.j_g = b->size[0];
          for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
            tmp_c->data[rtB.bestCol] = (b->data[rtB.bestCol] && r->
              data[rtB.bestCol]);
          }
        } else {
          and_o(tmp_c, b, r);
        }

        rtB.bestCol = tmp_c->size[0] - 1;
        rtB.j_g = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_c->data[rtB.i_l]) {
            rtB.j_g++;
          }
        }

        rtB.i_l = tmp_s->size[0];
        tmp_s->size[0] = rtB.j_g;
        emxEnsureCapacity_int32_T(tmp_s, rtB.i_l);
        rtB.partialTrueCount = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_c->data[rtB.i_l]) {
            tmp_s->data[rtB.partialTrueCount] = rtB.i_l;
            rtB.partialTrueCount++;
          }
        }

        rtB.j_g = tmp_s->size[0];
        rtB.i_l = jj_0->size[0];
        jj_0->size[0] = tmp_s->size[0];
        emxEnsureCapacity_real_T(jj_0, rtB.i_l);
        for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
          jj_0->data[rtB.bestCol] = jj->data[tmp_s->data[rtB.bestCol]];
        }

        rtB.scale1 = mean(jj_0);
      }

      rtB.win_y_high = rtB.sum + 1.0;
      if (b->size[0] == r->size[0]) {
        rtB.i_l = tmp_e->size[0];
        tmp_e->size[0] = b->size[0];
        emxEnsureCapacity_boolean_T(tmp_e, rtB.i_l);
        rtB.j_g = b->size[0];
        for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
          tmp_e->data[rtB.bestCol] = (b->data[rtB.bestCol] && r->
            data[rtB.bestCol]);
        }
      } else {
        and_o(tmp_e, b, r);
      }

      rtB.bestCol = tmp_e->size[0] - 1;
      rtB.j_g = 0;
      for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
        if (tmp_e->data[rtB.i_l]) {
          rtB.j_g++;
        }
      }

      rtB.k = static_cast<int32_T>((1.0 - (rtB.sum + 1.0)) + static_cast<real_T>
        (rtB.j_g));
      for (rtB.d_j = 0; rtB.d_j < rtB.k; rtB.d_j++) {
        rtB.win_y_low = rtB.win_y_high + static_cast<real_T>(rtB.d_j);
        rtB.j_g = b->size[0];
        if (b->size[0] == r->size[0]) {
          rtB.i_l = tmp_g->size[0];
          tmp_g->size[0] = b->size[0];
          emxEnsureCapacity_boolean_T(tmp_g, rtB.i_l);
          for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
            tmp_g->data[rtB.bestCol] = (b->data[rtB.bestCol] && r->
              data[rtB.bestCol]);
          }
        } else {
          and_o(tmp_g, b, r);
        }

        rtB.partialTrueCount = b_tmp_tmp->size[0];
        if (b_tmp_tmp->size[0] == r->size[0]) {
          rtB.i_l = tmp_i->size[0];
          tmp_i->size[0] = b_tmp_tmp->size[0];
          emxEnsureCapacity_boolean_T(tmp_i, rtB.i_l);
          for (rtB.bestCol = 0; rtB.bestCol < rtB.partialTrueCount; rtB.bestCol
               ++) {
            tmp_i->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && r->
              data[rtB.bestCol]);
          }
        } else {
          and_o(tmp_i, b_tmp_tmp, r);
        }

        rtB.bestCol = tmp_i->size[0] - 1;
        rtB.j_g = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_i->data[rtB.i_l]) {
            rtB.j_g++;
          }
        }

        rtB.i_l = tmp->size[0];
        tmp->size[0] = rtB.j_g;
        emxEnsureCapacity_int32_T(tmp, rtB.i_l);
        rtB.partialTrueCount = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_i->data[rtB.i_l]) {
            tmp->data[rtB.partialTrueCount] = rtB.i_l;
            rtB.partialTrueCount++;
          }
        }

        rtB.bestCol = tmp_g->size[0] - 1;
        rtB.j_g = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_g->data[rtB.i_l]) {
            rtB.j_g++;
          }
        }

        rtB.i_l = tmp_v->size[0];
        tmp_v->size[0] = rtB.j_g;
        emxEnsureCapacity_int32_T(tmp_v, rtB.i_l);
        rtB.partialTrueCount = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_g->data[rtB.i_l]) {
            tmp_v->data[rtB.partialTrueCount] = rtB.i_l;
            rtB.partialTrueCount++;
          }
        }

        rtB.right_lane_index[static_cast<int32_T>(rtB.win_y_low) - 1] = jj->
          data[tmp_v->data[static_cast<int32_T>(rtB.win_y_low) - 1]];
        rtB.min = ii->data[tmp->data[static_cast<int32_T>(rtB.win_y_low) - 1]];
        rtB.right_lane_index[static_cast<int32_T>(rtB.win_y_low) + 99999] =
          rtB.min;
        rtB.j_g = b->size[0];
        if (b->size[0] == r->size[0]) {
          rtB.i_l = tmp_k->size[0];
          tmp_k->size[0] = b->size[0];
          emxEnsureCapacity_boolean_T(tmp_k, rtB.i_l);
          for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
            tmp_k->data[rtB.bestCol] = (b->data[rtB.bestCol] && r->
              data[rtB.bestCol]);
          }
        } else {
          and_o(tmp_k, b, r);
        }

        rtB.bestCol = tmp_k->size[0] - 1;
        rtB.j_g = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_k->data[rtB.i_l]) {
            rtB.j_g++;
          }
        }

        rtB.i_l = tmp_y->size[0];
        tmp_y->size[0] = rtB.j_g;
        emxEnsureCapacity_int32_T(tmp_y, rtB.i_l);
        rtB.partialTrueCount = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_k->data[rtB.i_l]) {
            tmp_y->data[rtB.partialTrueCount] = rtB.i_l;
            rtB.partialTrueCount++;
          }
        }

        rtB.left_lane_index[static_cast<int32_T>(rtB.win_y_low) - 1] =
          static_cast<real_T>(jj->data[tmp_y->data[static_cast<int32_T>
                              (rtB.win_y_low) - 1]]) - 520.0;
        rtB.left_lane_index[static_cast<int32_T>(rtB.win_y_low) + 99999] =
          rtB.min;
        rtB.sum++;
      }
    }

    if (rtB.line_flag == 2) {
      rtB.win_y_low = rtB.scale2 - ((static_cast<real_T>(rtB.bestInlierNum) +
        1.0) + 1.0) * 24.0;
      rtB.win_y_high = rtB.scale2 - (static_cast<real_T>(rtB.bestInlierNum) +
        1.0) * 24.0;
      rtB.k = ii->size[0];
      rtB.i_l = b_tmp_tmp->size[0];
      b_tmp_tmp->size[0] = ii->size[0];
      emxEnsureCapacity_boolean_T(b_tmp_tmp, rtB.i_l);
      rtB.i_l = b_tmp->size[0];
      b_tmp->size[0] = ii->size[0];
      emxEnsureCapacity_boolean_T(b_tmp, rtB.i_l);
      for (rtB.bestCol = 0; rtB.bestCol < rtB.k; rtB.bestCol++) {
        rtB.j_g = ii->data[rtB.bestCol];
        b_tmp_tmp->data[rtB.bestCol] = (rtB.j_g >= rtB.win_y_low);
        b_tmp->data[rtB.bestCol] = (rtB.j_g < rtB.win_y_high);
      }

      rtB.j_g = jj->size[0];
      rtB.i_l = t->size[0];
      t->size[0] = jj->size[0];
      emxEnsureCapacity_boolean_T(t, rtB.i_l);
      for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
        t->data[rtB.bestCol] = (jj->data[rtB.bestCol] >= rtB.scale1 - 40.0);
      }

      if (b_tmp_tmp->size[0] == t->size[0]) {
        rtB.i_l = b->size[0];
        b->size[0] = b_tmp_tmp->size[0];
        emxEnsureCapacity_boolean_T(b, rtB.i_l);
        rtB.j_g = b_tmp_tmp->size[0];
        for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
          b->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && b_tmp->
            data[rtB.bestCol] && t->data[rtB.bestCol]);
        }
      } else {
        binary_expand_op_1(b, b_tmp_tmp, b_tmp, t);
      }

      rtB.j_g = jj->size[0];
      rtB.i_l = r->size[0];
      r->size[0] = jj->size[0];
      emxEnsureCapacity_boolean_T(r, rtB.i_l);
      for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
        r->data[rtB.bestCol] = (jj->data[rtB.bestCol] < rtB.scale1 + 40.0);
      }

      if (b_tmp_tmp->size[0] == t->size[0]) {
        rtB.j_g = b_tmp_tmp->size[0];
        for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
          b_tmp_tmp->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] &&
            b_tmp->data[rtB.bestCol] && t->data[rtB.bestCol]);
        }
      } else {
        binary_expand_op(b_tmp_tmp, b_tmp, t);
      }

      if (b->size[0] == r->size[0]) {
        rtB.i_l = tmp_9->size[0];
        tmp_9->size[0] = b->size[0];
        emxEnsureCapacity_boolean_T(tmp_9, rtB.i_l);
        rtB.j_g = b->size[0];
        for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
          tmp_9->data[rtB.bestCol] = (b->data[rtB.bestCol] && r->
            data[rtB.bestCol]);
        }
      } else {
        and_o(tmp_9, b, r);
      }

      rtB.bestCol = tmp_9->size[0] - 1;
      rtB.j_g = 0;
      for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
        if (tmp_9->data[rtB.i_l]) {
          rtB.j_g++;
        }
      }

      if (rtB.j_g > 30) {
        if (b->size[0] == r->size[0]) {
          rtB.i_l = tmp_b->size[0];
          tmp_b->size[0] = b->size[0];
          emxEnsureCapacity_boolean_T(tmp_b, rtB.i_l);
          rtB.j_g = b->size[0];
          for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
            tmp_b->data[rtB.bestCol] = (b->data[rtB.bestCol] && r->
              data[rtB.bestCol]);
          }
        } else {
          and_o(tmp_b, b, r);
        }

        rtB.bestCol = tmp_b->size[0] - 1;
        rtB.j_g = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_b->data[rtB.i_l]) {
            rtB.j_g++;
          }
        }

        rtB.i_l = tmp_r->size[0];
        tmp_r->size[0] = rtB.j_g;
        emxEnsureCapacity_int32_T(tmp_r, rtB.i_l);
        rtB.partialTrueCount = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_b->data[rtB.i_l]) {
            tmp_r->data[rtB.partialTrueCount] = rtB.i_l;
            rtB.partialTrueCount++;
          }
        }

        rtB.j_g = tmp_r->size[0];
        rtB.i_l = jj_0->size[0];
        jj_0->size[0] = tmp_r->size[0];
        emxEnsureCapacity_real_T(jj_0, rtB.i_l);
        for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
          jj_0->data[rtB.bestCol] = jj->data[tmp_r->data[rtB.bestCol]];
        }

        rtB.scale1 = mean(jj_0);
      }

      rtB.win_y_high = rtB.maxSum + 1.0;
      if (b->size[0] == r->size[0]) {
        rtB.i_l = tmp_d->size[0];
        tmp_d->size[0] = b->size[0];
        emxEnsureCapacity_boolean_T(tmp_d, rtB.i_l);
        rtB.j_g = b->size[0];
        for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
          tmp_d->data[rtB.bestCol] = (b->data[rtB.bestCol] && r->
            data[rtB.bestCol]);
        }
      } else {
        and_o(tmp_d, b, r);
      }

      rtB.bestCol = tmp_d->size[0] - 1;
      rtB.j_g = 0;
      for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
        if (tmp_d->data[rtB.i_l]) {
          rtB.j_g++;
        }
      }

      rtB.k = static_cast<int32_T>((1.0 - (rtB.maxSum + 1.0)) +
        static_cast<real_T>(rtB.j_g));
      for (rtB.d_j = 0; rtB.d_j < rtB.k; rtB.d_j++) {
        rtB.win_y_low = rtB.win_y_high + static_cast<real_T>(rtB.d_j);
        rtB.j_g = b->size[0];
        if (b->size[0] == r->size[0]) {
          rtB.i_l = tmp_f->size[0];
          tmp_f->size[0] = b->size[0];
          emxEnsureCapacity_boolean_T(tmp_f, rtB.i_l);
          for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
            tmp_f->data[rtB.bestCol] = (b->data[rtB.bestCol] && r->
              data[rtB.bestCol]);
          }
        } else {
          and_o(tmp_f, b, r);
        }

        rtB.partialTrueCount = b_tmp_tmp->size[0];
        if (b_tmp_tmp->size[0] == r->size[0]) {
          rtB.i_l = tmp_h->size[0];
          tmp_h->size[0] = b_tmp_tmp->size[0];
          emxEnsureCapacity_boolean_T(tmp_h, rtB.i_l);
          for (rtB.bestCol = 0; rtB.bestCol < rtB.partialTrueCount; rtB.bestCol
               ++) {
            tmp_h->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && r->
              data[rtB.bestCol]);
          }
        } else {
          and_o(tmp_h, b_tmp_tmp, r);
        }

        rtB.bestCol = tmp_f->size[0] - 1;
        rtB.j_g = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_f->data[rtB.i_l]) {
            rtB.j_g++;
          }
        }

        rtB.i_l = tmp_t->size[0];
        tmp_t->size[0] = rtB.j_g;
        emxEnsureCapacity_int32_T(tmp_t, rtB.i_l);
        rtB.partialTrueCount = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_f->data[rtB.i_l]) {
            tmp_t->data[rtB.partialTrueCount] = rtB.i_l;
            rtB.partialTrueCount++;
          }
        }

        rtB.bestCol = tmp_h->size[0] - 1;
        rtB.j_g = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_h->data[rtB.i_l]) {
            rtB.j_g++;
          }
        }

        rtB.i_l = tmp_u->size[0];
        tmp_u->size[0] = rtB.j_g;
        emxEnsureCapacity_int32_T(tmp_u, rtB.i_l);
        rtB.partialTrueCount = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_h->data[rtB.i_l]) {
            tmp_u->data[rtB.partialTrueCount] = rtB.i_l;
            rtB.partialTrueCount++;
          }
        }

        rtB.left_lane_index[static_cast<int32_T>(rtB.win_y_low) - 1] = jj->
          data[tmp_t->data[static_cast<int32_T>(rtB.win_y_low) - 1]];
        rtB.left_lane_index[static_cast<int32_T>(rtB.win_y_low) + 99999] =
          ii->data[tmp_u->data[static_cast<int32_T>(rtB.win_y_low) - 1]];
        rtB.j_g = b->size[0];
        if (b->size[0] == r->size[0]) {
          rtB.i_l = tmp_j->size[0];
          tmp_j->size[0] = b->size[0];
          emxEnsureCapacity_boolean_T(tmp_j, rtB.i_l);
          for (rtB.bestCol = 0; rtB.bestCol < rtB.j_g; rtB.bestCol++) {
            tmp_j->data[rtB.bestCol] = (b->data[rtB.bestCol] && r->
              data[rtB.bestCol]);
          }
        } else {
          and_o(tmp_j, b, r);
        }

        rtB.partialTrueCount = b_tmp_tmp->size[0];
        if (b_tmp_tmp->size[0] == r->size[0]) {
          rtB.i_l = tmp_l->size[0];
          tmp_l->size[0] = b_tmp_tmp->size[0];
          emxEnsureCapacity_boolean_T(tmp_l, rtB.i_l);
          for (rtB.bestCol = 0; rtB.bestCol < rtB.partialTrueCount; rtB.bestCol
               ++) {
            tmp_l->data[rtB.bestCol] = (b_tmp_tmp->data[rtB.bestCol] && r->
              data[rtB.bestCol]);
          }
        } else {
          and_o(tmp_l, b_tmp_tmp, r);
        }

        rtB.bestCol = tmp_j->size[0] - 1;
        rtB.j_g = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_j->data[rtB.i_l]) {
            rtB.j_g++;
          }
        }

        rtB.i_l = tmp_w->size[0];
        tmp_w->size[0] = rtB.j_g;
        emxEnsureCapacity_int32_T(tmp_w, rtB.i_l);
        rtB.partialTrueCount = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_j->data[rtB.i_l]) {
            tmp_w->data[rtB.partialTrueCount] = rtB.i_l;
            rtB.partialTrueCount++;
          }
        }

        rtB.bestCol = tmp_l->size[0] - 1;
        rtB.j_g = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_l->data[rtB.i_l]) {
            rtB.j_g++;
          }
        }

        rtB.i_l = tmp_x->size[0];
        tmp_x->size[0] = rtB.j_g;
        emxEnsureCapacity_int32_T(tmp_x, rtB.i_l);
        rtB.partialTrueCount = 0;
        for (rtB.i_l = 0; rtB.i_l <= rtB.bestCol; rtB.i_l++) {
          if (tmp_l->data[rtB.i_l]) {
            tmp_x->data[rtB.partialTrueCount] = rtB.i_l;
            rtB.partialTrueCount++;
          }
        }

        rtB.right_lane_index[static_cast<int32_T>(rtB.win_y_low) - 1] =
          static_cast<real_T>(jj->data[tmp_w->data[static_cast<int32_T>
                              (rtB.win_y_low) - 1]]) + 520.0;
        rtB.right_lane_index[static_cast<int32_T>(rtB.win_y_low) + 99999] =
          ii->data[tmp_x->data[static_cast<int32_T>(rtB.win_y_low) - 1]];
        rtB.maxSum++;
      }
    }
  }

  emxFree_real_T(&jj_0);
  emxFree_int32_T(&tmp_y);
  emxFree_int32_T(&tmp_x);
  emxFree_int32_T(&tmp_w);
  emxFree_int32_T(&tmp_v);
  emxFree_int32_T(&tmp_u);
  emxFree_int32_T(&tmp_t);
  emxFree_int32_T(&tmp_s);
  emxFree_int32_T(&tmp_r);
  emxFree_boolean_T(&tmp_l);
  emxFree_boolean_T(&tmp_k);
  emxFree_boolean_T(&tmp_j);
  emxFree_boolean_T(&tmp_i);
  emxFree_boolean_T(&tmp_h);
  emxFree_boolean_T(&tmp_g);
  emxFree_boolean_T(&tmp_f);
  emxFree_boolean_T(&tmp_e);
  emxFree_boolean_T(&tmp_d);
  emxFree_boolean_T(&tmp_c);
  emxFree_boolean_T(&tmp_b);
  emxFree_boolean_T(&tmp_a);
  emxFree_boolean_T(&tmp_9);
  emxFree_int32_T(&tmp);
  emxFree_int32_T(&n_tmp);
  emxFree_boolean_T(&b_tmp_tmp);
  emxFree_boolean_T(&b_tmp);
  emxFree_boolean_T(&t);
  emxFree_boolean_T(&r);
  emxFree_int32_T(&jj);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&b);

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (rtB.maxSum < 1.0) {
    rtB.bestInlierNum = -1;
  } else {
    rtB.bestInlierNum = static_cast<int32_T>(rtB.maxSum) - 1;
  }

  if (rtB.sum < 1.0) {
    rtB.line_flag = -1;
  } else {
    rtB.line_flag = static_cast<int32_T>(rtB.sum) - 1;
  }

  emxInit_real_T(&left_lane_index, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.i_l = left_lane_index->size[0];
  left_lane_index->size[0] = rtB.bestInlierNum + 1;
  emxEnsureCapacity_real_T(left_lane_index, rtB.i_l);
  emxInit_real_T(&left_lane_index_0, 1);

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtB.i_l = left_lane_index_0->size[0];
  left_lane_index_0->size[0] = rtB.bestInlierNum + 1;
  emxEnsureCapacity_real_T(left_lane_index_0, rtB.i_l);
  if (rtB.bestInlierNum >= 0) {
    memcpy(&left_lane_index->data[0], &rtB.left_lane_index[100000], static_cast<
           uint32_T>(rtB.bestInlierNum + 1) * sizeof(real_T));
  }

  if (rtB.bestInlierNum >= 0) {
    memcpy(&left_lane_index_0->data[0], &rtB.left_lane_index[0],
           static_cast<uint32_T>(rtB.bestInlierNum + 1) * sizeof(real_T));
  }

  polyfit(left_lane_index, left_lane_index_0, rtB.p);
  rtB.i_l = left_lane_index->size[0];
  left_lane_index->size[0] = rtB.line_flag + 1;
  emxEnsureCapacity_real_T(left_lane_index, rtB.i_l);
  rtB.i_l = left_lane_index_0->size[0];
  left_lane_index_0->size[0] = rtB.line_flag + 1;
  emxEnsureCapacity_real_T(left_lane_index_0, rtB.i_l);
  if (rtB.line_flag >= 0) {
    memcpy(&left_lane_index->data[0], &rtB.right_lane_index[100000],
           static_cast<uint32_T>(rtB.line_flag + 1) * sizeof(real_T));
  }

  if (rtB.line_flag >= 0) {
    memcpy(&left_lane_index_0->data[0], &rtB.right_lane_index[0],
           static_cast<uint32_T>(rtB.line_flag + 1) * sizeof(real_T));
  }

  polyfit(left_lane_index, left_lane_index_0, rtB.b_p);
  emxFree_real_T(&left_lane_index_0);
  emxFree_real_T(&left_lane_index);

  // MATLAB Function: '<S2>/MATLAB Function1'
  for (rtB.bestCol = 0; rtB.bestCol < 481; rtB.bestCol++) {
    rtB.xleft[rtB.bestCol] = rtB.p[0];
  }

  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 2; rtB.bestInlierNum++) {
    rtB.scale1 = rtB.p[rtB.bestInlierNum + 1];
    for (rtB.bestCol = 0; rtB.bestCol < 481; rtB.bestCol++) {
      rtB.xleft[rtB.bestCol] = static_cast<real_T>(rtB.bestCol) *
        rtB.xleft[rtB.bestCol] + rtB.scale1;
    }
  }

  for (rtB.bestCol = 0; rtB.bestCol < 481; rtB.bestCol++) {
    rtB.xright[rtB.bestCol] = rtB.b_p[0];
  }

  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 2; rtB.bestInlierNum++) {
    rtB.scale1 = rtB.b_p[rtB.bestInlierNum + 1];
    for (rtB.bestCol = 0; rtB.bestCol < 481; rtB.bestCol++) {
      rtB.xright[rtB.bestCol] = static_cast<real_T>(rtB.bestCol) *
        rtB.xright[rtB.bestCol] + rtB.scale1;
    }
  }

  rtB.error = 320.0 - (rtB.xleft[480] + rtB.xright[480]) / 2.0;

  // Outport: '<Root>/Out1'
  rtY.Out1 = rtB.error;

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

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(rtM, 50.0);
  rtM->Timing.stepSize0 = 0.1;

  // External mode info
  rtM->Sizes.checksums[0] = (1598647381U);
  rtM->Sizes.checksums[1] = (3648621129U);
  rtM->Sizes.checksums[2] = (814697067U);
  rtM->Sizes.checksums[3] = (1198618048U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
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
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(rtM->extModeInfo, &rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(rtM->extModeInfo, rtM->Sizes.checksums);
    rteiSetTPtr(rtM->extModeInfo, rtmGetTPtr(rtM));
  }

  {
    int32_T i;
    char_T b[18];
    char_T devName[12];
    static const char_T b_0[18] = "SDL Video Display";
    static const char_T devName_0[12] = "/dev/video0";
    static const int8_T self_T[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    // Start for S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' 
    srand(clock());

    // Start for MATLABSystem: '<S7>/MATLAB System'
    rtDW.obj_a.displayId = -1;
    rtDW.obj_a.matlabCodegenIsDeleted = false;
    if (rtDW.obj_a.displayId != -1) {
      for (i = 0; i < 18; i++) {
        b[i] = b_0[i];
      }

      MW_SDL_videoDisplayTitle(&b[0], rtDW.obj_a.displayId);
    }

    rtDW.obj_a.isInitialized = 1;
    rtDW.obj_a.PixelFormatEnum = 1;
    for (i = 0; i < 18; i++) {
      b[i] = b_0[i];
    }

    rtDW.obj_a.displayId = MW_SDL_videoDisplayInit(rtDW.obj_a.PixelFormatEnum, 1,
      1, 640.0, 480.0, &b[0]);
    rtDW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/MATLAB System'
    // End of SystemInitialize for SubSystem: '<S2>/SDL Video Display'

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
  // Terminate for MATLABSystem: '<S7>/MATLAB System'
  if (!rtDW.obj_a.matlabCodegenIsDeleted) {
    rtDW.obj_a.matlabCodegenIsDeleted = true;
    if ((rtDW.obj_a.isInitialized == 1) && rtDW.obj_a.isSetupComplete) {
      MW_SDL_videoDisplayTerminate(0, 0, rtDW.obj_a.displayId);
    }
  }

  // End of Terminate for MATLABSystem: '<S7>/MATLAB System'
}

//
// File trailer for generated code.
//
// [EOF]
//
