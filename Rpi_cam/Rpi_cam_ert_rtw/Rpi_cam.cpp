//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Rpi_cam.cpp
//
// Code generated for Simulink model 'Rpi_cam'.
//
// Model version                  : 1.154
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Apr 18 13:37:00 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Rpi_cam.h"
#include "Rpi_cam_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <string.h>
#include "Rpi_cam_private.h"
#include <stddef.h>
#include <math.h>

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
static void QRV2Norm_real_T_o(const real_T V[], int32_T N, real_T v2norm[]);
static void QRDC_real_T_o(real_T xVec[], real_T qrAux[], int32_T jpvt[], real_T
  work[], int32_T M, int32_T N);
static void QRE_real_T_o(real_T outQ[], real_T outR[], real_T outE[], real_T
  qrAux[], real_T work[], int32_T jpvt[], real_T sPtr[], int32_T M, int32_T N,
  boolean_T economy);
static void Warp_stepImpl(vision_internal_blocks_Warp *b_this, const boolean_T
  Image[307200], const real_T input2[9], boolean_T Jout[307200]);
static void eml_find(const boolean_T x[307200], coder::array<int32_T, 1U> &i,
                     coder::array<int32_T, 1U> &j);
static void and_o(coder::array<boolean_T, 1U> &in1, const coder::array<boolean_T,
                  1U> &in2, const coder::array<boolean_T, 1U> &in3);
static void binary_expand_op_3(coder::array<boolean_T, 1U> &in1, const coder::
  array<boolean_T, 1U> &in2, const coder::array<int32_T, 1U> &in3);
static real_T mean(const coder::array<real_T, 1U> &x);
static real_T maximum(const coder::array<real_T, 1U> &x);
static void binary_expand_op_2(coder::array<boolean_T, 1U> &in1, const coder::
  array<boolean_T, 1U> &in2, const coder::array<boolean_T, 1U> &in3, const coder::
  array<boolean_T, 1U> &in4, const coder::array<boolean_T, 1U> &in5);
static void binary_expand_op(coder::array<boolean_T, 1U> &in1, const coder::
  array<int32_T, 1U> &in2, real_T in3, real_T in4, const coder::array<int32_T,
  1U> &in5, real_T in6);
static void binary_expand_op_1(coder::array<boolean_T, 1U> &in1, const coder::
  array<real_T, 1U> &in2, real_T in3, real_T in4, const coder::array<real_T, 1U>
  &in5, real_T in6);
static codertarget_raspi_internal_Raspiv4l2Capture
  *Raspiv4l2Capture_Raspiv4l2Capture(codertarget_raspi_internal_Raspiv4l2Capture
  *obj);
static void SystemCore_setup(codertarget_raspi_internal_RaspiTCPSend *obj);
static void v4l2Capture_updateV4L2Settings
  (codertarget_raspi_internal_Raspiv4l2Capture *obj, boolean_T forceUpdate)
{
  char_T j[12];
  char_T b[11];
  char_T e[10];
  char_T c[9];
  uint8_T status;
  static const char_T b_0[11] = "Brightness";
  static const char_T c_0[9] = "Contrast";
  static const char_T d[11] = "Saturation";
  static const char_T e_0[10] = "Sharpness";
  static const char_T f[10] = "CameraPan";
  static const char_T g[11] = "CameraTilt";
  static const char_T h[11] = "CameraZoom";
  static const char_T i_0[18] = "EnableManualFocus";
  static const char_T j_0[12] = "ManualFocus";

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  if ((obj->Brightness != obj->BrightnessInternal) || forceUpdate) {
    obj->BrightnessInternal = obj->Brightness;
    for (int32_T i = 0; i < 11; i++) {
      b[i] = b_0[i];
    }

    EXT_updateV4L2Control(&b[0], static_cast<real32_T>(obj->Brightness), 0,
                          &status);
  }

  if ((obj->Contrast != obj->ContrastInternal) || forceUpdate) {
    obj->ContrastInternal = obj->Contrast;
    for (int32_T i = 0; i < 9; i++) {
      c[i] = c_0[i];
    }

    EXT_updateV4L2Control(&c[0], static_cast<real32_T>(obj->Contrast), 0,
                          &status);
  }

  if ((obj->Saturation != obj->SaturationInternal) || forceUpdate) {
    obj->SaturationInternal = obj->Saturation;
    for (int32_T i = 0; i < 11; i++) {
      b[i] = d[i];
    }

    EXT_updateV4L2Control(&b[0], static_cast<real32_T>(obj->Saturation), 0,
                          &status);
  }

  if ((obj->Sharpness != obj->SharpnessInternal) || forceUpdate) {
    obj->SharpnessInternal = obj->Sharpness;
    for (int32_T i = 0; i < 10; i++) {
      e[i] = e_0[i];
    }

    EXT_updateV4L2Control(&e[0], static_cast<real32_T>(obj->Sharpness), 0,
                          &status);
  }

  if ((obj->CameraPan != obj->CameraPanInternal) || forceUpdate) {
    obj->CameraPanInternal = obj->CameraPan;
    for (int32_T i = 0; i < 10; i++) {
      e[i] = f[i];
    }

    EXT_updateV4L2Control(&e[0], static_cast<real32_T>(obj->CameraPan), 0,
                          &status);
  }

  if ((obj->CameraTilt != obj->CameraTiltInternal) || forceUpdate) {
    obj->CameraTiltInternal = obj->CameraTilt;
    for (int32_T i = 0; i < 11; i++) {
      b[i] = g[i];
    }

    EXT_updateV4L2Control(&b[0], static_cast<real32_T>(obj->CameraTilt), 0,
                          &status);
  }

  if ((obj->CameraZoom != obj->CameraZoomInternal) || forceUpdate) {
    obj->CameraZoomInternal = obj->CameraZoom;
    for (int32_T i = 0; i < 11; i++) {
      b[i] = h[i];
    }

    EXT_updateV4L2Control(&b[0], static_cast<real32_T>(obj->CameraZoom), 0,
                          &status);
  }

  if ((!obj->EnableManualFocusInternal) || forceUpdate) {
    obj->EnableManualFocusInternal = true;
    for (int32_T i = 0; i < 18; i++) {
      rtB.i[i] = i_0[i];
    }

    EXT_updateV4L2Control(&rtB.i[0], 1.0F, 0, &status);
  }

  if ((obj->ManualFocus != obj->ManualFocusInternal) || forceUpdate) {
    obj->ManualFocusInternal = obj->ManualFocus;
    for (int32_T i = 0; i < 12; i++) {
      j[i] = j_0[i];
    }

    EXT_updateV4L2Control(&j[0], static_cast<real32_T>(obj->ManualFocus), 0,
                          &status);
  }

  // End of Start for MATLABSystem: '<Root>/V4L2 Video Capture'
}

static void SystemCore_step(codertarget_raspi_internal_Raspiv4l2Capture *obj,
  uint8_T varargout_1[307200], uint8_T varargout_2[307200], uint8_T varargout_3
  [307200])
{
  real_T ts;

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  v4l2Capture_updateV4L2Settings(obj, false);
  EXT_webcamCapture(0, 0, &ts, &varargout_1[0], &varargout_2[0], &varargout_3[0]);
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
  int32_T vi;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  rtB.val = 0.0;
  vi = 0;
  for (int32_T i = 0; i < N; i++) {
    rtB.d_p = fabs(V[vi]);
    if (rtB.val > rtB.d_p) {
      rtB.tmpQRSL = V[vi] / rtB.val;
      rtB.val *= sqrt(rtB.tmpQRSL * rtB.tmpQRSL + 1.0);
    } else if (V[vi] == 0.0) {
      rtB.val = 0.0;
    } else {
      rtB.tmpQRSL = rtB.val / V[vi];
      rtB.val = sqrt(rtB.tmpQRSL * rtB.tmpQRSL + 1.0) * rtB.d_p;
    }

    vi++;
  }

  v2norm[0U] = rtB.val;

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void QRDC_real_T_o(real_T xVec[], real_T qrAux[], int32_T jpvt[], real_T
  work[], int32_T M, int32_T N)
{
  int32_T i;
  int32_T j;
  int32_T l;
  int32_T maxj;
  int32_T minVal;
  int32_T mml;
  int32_T pl;
  int32_T plj;
  int32_T pu;
  int32_T px;
  int32_T px2;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  pl = 0;
  for (j = 0; j < N; j++) {
    pu = (jpvt[j] > 0);
    if (jpvt[j] < 0) {
      jpvt[j] = -j;
    } else {
      jpvt[j] = j;
    }

    if (pu == 1) {
      if (j != pl) {
        // Swap columns pl and j
        px = pl * M;
        px2 = j * M;
        for (i = M; i > 0; i--) {
          rtB.maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = rtB.maxnrm;
          px++;
          px2++;
        }
      }

      jpvt[j] = jpvt[pl];
      jpvt[pl] = j;
      pl++;
    }
  }

  pu = N - 1;
  for (j = N - 1; j >= 0; j--) {
    if (jpvt[j] < 0) {
      jpvt[j] = -jpvt[j];
      if (j != pu) {
        // Swap columns pu and j
        px = pu * M;
        px2 = j * M;
        for (i = M; i > 0; i--) {
          rtB.maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = rtB.maxnrm;
          px++;
          px2++;
        }

        px = jpvt[pu];
        jpvt[pu] = jpvt[j];
        jpvt[j] = px;
      }

      pu--;
    }
  }

  // compute the norms of the free columns
  for (j = pl; j <= pu; j++) {
    QRV2Norm_real_T_o(&xVec[j * M], M, &qrAux[j]);
    work[j] = qrAux[j];
  }

  // perform the Householder reduction of x
  if (M <= N) {
    minVal = M;
  } else {
    minVal = N;
  }

  for (l = 0; l < minVal; l++) {
    mml = M - l;

    // locate the column of largest norm and bring it into the pivot position
    if ((l >= pl) && (l < pu)) {
      rtB.maxnrm = 0.0;
      maxj = l;
      for (j = l; j <= pu; j++) {
        if (qrAux[j] > rtB.maxnrm) {
          rtB.maxnrm = qrAux[j];
          maxj = j;
        }
      }

      if (maxj != l) {
        // Swap columns l and maxj
        px = l * M;
        px2 = maxj * M;
        for (i = M; i > 0; i--) {
          rtB.maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = rtB.maxnrm;
          px++;
          px2++;
        }

        qrAux[maxj] = qrAux[l];
        work[maxj] = work[l];
        px = jpvt[maxj];
        jpvt[maxj] = jpvt[l];
        jpvt[l] = px;
      }
    }

    qrAux[l] = 0.0;
    if (M - 1 != l) {
      // Compute the Householder transformation for column l
      maxj = (M + 1) * l;
      px = maxj;
      QRV2Norm_real_T_o(&xVec[maxj], mml, &rtB.nrmxl);
      rtB.maxnrm = fabs(rtB.nrmxl);
      if (rtB.maxnrm != 0.0) {
        if (fabs(xVec[maxj]) != 0.0) {
          if (xVec[maxj] >= 0.0) {
            rtB.nrmxl = rtB.maxnrm;
          } else {
            rtB.nrmxl = -rtB.maxnrm;
          }
        }

        // Check if it's safe to multiply by 1/nrmxl instead of dividing by nrmxl 
        px2 = maxj;
        if (5.0E-20 * rtB.nrmxl != 0.0) {
          rtB.maxnrm = 1.0 / rtB.nrmxl;
          for (i = mml; i > 0; i--) {
            xVec[px2] *= rtB.maxnrm;
            px2++;
          }
        } else {
          for (i = mml; i > 0; i--) {
            xVec[px2] /= rtB.nrmxl;
            px2++;
          }
        }

        xVec[maxj]++;

        // apply the transformation to the remaining columns, updating the norms. 
        for (j = l + 1; j < N; j++) {
          plj = j * M + l;
          px2 = plj;
          rtB.t = 0.0;
          for (i = mml; i > 0; i--) {
            rtB.t -= xVec[px] * xVec[px2];
            px++;
            px2++;
          }

          px = maxj;
          px2 = plj;
          rtB.t /= xVec[maxj];
          for (i = mml; i > 0; i--) {
            xVec[px2] += rtB.t * xVec[px];
            px++;
            px2++;
          }

          px = maxj;
          px2 = 0;
          if (qrAux[j] == 0.0) {
            px2 = 1;
          }

          if ((j >= pl) && (j <= pu) && (px2 == 0)) {
            rtB.maxnrm = fabs(xVec[plj]) / qrAux[j];
            rtB.tt = 1.0 - rtB.maxnrm * rtB.maxnrm;
            if (rtB.tt < 0.0) {
              rtB.tt = 0.0;
            }

            rtB.t = rtB.tt;
            rtB.maxnrm = qrAux[j] / work[j];
            rtB.tt = 0.05 * rtB.tt * rtB.maxnrm * rtB.maxnrm + 1.0;
            if (rtB.tt != 1.0) {
              qrAux[j] *= sqrt(rtB.t);
            } else {
              QRV2Norm_real_T_o(&xVec[plj + 1], mml - 1, &rtB.maxnrm);
              qrAux[j] = rtB.maxnrm;
              work[j] = qrAux[j];
            }
          }
        }

        // save the transformation.
        qrAux[l] = xVec[px];
        xVec[px] = -rtB.nrmxl;
      }
    }
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

void QRCompQy_real_T(real_T qr[], const real_T qrAuxj[], real_T y[], int32_T n,
                     int32_T j)
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  if (fabs(qrAuxj[0U]) != 0.0) {
    real_T t;
    real_T temp;
    int32_T nmj;
    int32_T pjj;
    int32_T pqr;
    int32_T py;
    nmj = n - j;
    pjj = (n + 1) * j;
    pqr = pjj;
    temp = qr[pjj];
    qr[pjj] = qrAuxj[0U];
    t = 0.0;
    py = 0;
    for (int32_T i = nmj; i > 0; i--) {
      t -= y[py] * qr[pqr];
      pqr++;
      py++;
    }

    pqr = pjj;
    t /= qr[pjj];
    py = 0;
    for (int32_T i = nmj; i > 0; i--) {
      y[py] += t * qr[pqr];
      pqr++;
      py++;
    }

    qr[pjj] = temp;
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

void QRSL1_real_T(real_T qr[], const real_T qrAux[], real_T y[], int32_T n,
                  int32_T k)
{
  int32_T i;
  int32_T j;
  int32_T pqraux_tmp;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  if (k <= n - 1) {
    j = k;
  } else {
    j = n - 1;
  }

  if (j != 0) {
    pqraux_tmp = j;
    for (i = j; i > 0; i--) {
      QRCompQy_real_T(&qr[0], &qrAux[j - 1], &y[pqraux_tmp - 1], n, i - 1);
      pqraux_tmp = j - 1;
      j--;
    }
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

static void QRE_real_T_o(real_T outQ[], real_T outR[], real_T outE[], real_T
  qrAux[], real_T work[], int32_T jpvt[], real_T sPtr[], int32_T M, int32_T N,
  boolean_T economy)
{
  int32_T ps;

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
    QRSL1_real_T(&outR[0], &qrAux[0], &outQ[rtB.pq], M, N);
    rtB.pq += M;
    rtB.j_l++;
  }

  if (economy && (M > N)) {
    // Copy upper triangle of r to s
    rtB.L = 0;
    ps = 0;
    rtB.j_l = 1;
    while (rtB.j_l - 1 < N) {
      rtB.pq = 0;
      while (rtB.pq <= rtB.j_l - 1) {
        sPtr[ps] = outR[rtB.L];
        ps++;
        rtB.L++;
        rtB.pq++;
      }

      rtB.L = (rtB.L + M) - rtB.j_l;
      rtB.pq = 0;
      while (rtB.pq < N - rtB.j_l) {
        sPtr[ps] = 0.0;
        ps++;
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
  int32_T itmp;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  for (p2 = 0; p2 < 9; p2++) {
    // Start for MATLABSystem: '<S4>/Warp'
    rtB.absx11 = input2[p2];
    b_this->TformProjective.T[p2] = rtB.absx11;
    rtB.x[p2] = rtB.absx11;
  }

  p1 = 1;
  p2 = 3;
  p3 = 6;

  // Start for MATLABSystem: '<S4>/Warp'
  rtB.absx11 = fabs(b_this->TformProjective.T[0]);
  rtB.absx21 = fabs(b_this->TformProjective.T[1]);
  rtB.absx31 = fabs(b_this->TformProjective.T[2]);
  if ((rtB.absx21 > rtB.absx11) && (rtB.absx21 > rtB.absx31)) {
    p1 = 4;
    p2 = 0;
    rtB.x[0] = b_this->TformProjective.T[1];
    rtB.x[1] = b_this->TformProjective.T[0];
    rtB.x[3] = b_this->TformProjective.T[4];
    rtB.x[4] = b_this->TformProjective.T[3];
    rtB.x[6] = b_this->TformProjective.T[7];
    rtB.x[7] = b_this->TformProjective.T[6];
  } else if (rtB.absx31 > rtB.absx11) {
    p1 = 7;
    p3 = 0;
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
    itmp = p2;
    p2 = p3;
    p3 = itmp;
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
  rtB.tinv[p1 - 1] = ((1.0 - rtB.x[3] * rtB.absx31) - rtB.x[6] * rtB.absx21) /
    rtB.x[0];
  rtB.tinv[p1] = rtB.absx31;
  rtB.tinv[p1 + 1] = rtB.absx21;
  rtB.absx21 = -rtB.absx11 / rtB.x[8];
  rtB.absx31 = (1.0 - rtB.x[7] * rtB.absx21) / rtB.x[4];
  rtB.tinv[p2] = -(rtB.x[3] * rtB.absx31 + rtB.x[6] * rtB.absx21) / rtB.x[0];
  rtB.tinv[p2 + 1] = rtB.absx31;
  rtB.tinv[p2 + 2] = rtB.absx21;
  rtB.absx21 = 1.0 / rtB.x[8];
  rtB.absx31 = -rtB.x[7] * rtB.absx21 / rtB.x[4];
  rtB.tinv[p3] = -(rtB.x[3] * rtB.absx31 + rtB.x[6] * rtB.absx21) / rtB.x[0];
  rtB.tinv[p3 + 1] = rtB.absx31;
  rtB.tinv[p3 + 2] = rtB.absx21;
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
  for (p1 = 0; p1 < 640; p1++) {
    for (p2 = 0; p2 < 480; p2++) {
      // Start for MATLABSystem: '<S4>/Warp'
      rtB.srczWorld_val = ((((static_cast<real_T>(p1) + 1.0) - 0.5) + 0.5) *
                           rtB.absx11 + (((static_cast<real_T>(p2) + 1.0) - 0.5)
        + 0.5) * rtB.absx21) + rtB.absx31;
      p3 = 480 * p1 + p2;
      rtB.srcXIntrinsic[p3] = ((((((static_cast<real_T>(p1) + 1.0) - 0.5) + 0.5)
        * rtB.tinv_c + (((static_cast<real_T>(p2) + 1.0) - 0.5) + 0.5) *
        rtB.tinv_f) + rtB.tinv_g) / rtB.srczWorld_val - 0.5) + 0.5;
      rtB.srcYIntrinsic[p3] = ((((((static_cast<real_T>(p1) + 1.0) - 0.5) + 0.5)
        * rtB.tinv_g1 + (((static_cast<real_T>(p2) + 1.0) - 0.5) + 0.5) *
        rtB.tinv_m) + rtB.tinv_n) / rtB.srczWorld_val - 0.5) + 0.5;
    }
  }

  for (p2 = 0; p2 < 307200; p2++) {
    // Start for MATLABSystem: '<S4>/Warp'
    rtB.inputImage[p2] = static_cast<int8_T>(Image[p2]);
  }

  for (p1 = 0; p1 < 307200; p1++) {
    real32_T qx2;

    // Start for MATLABSystem: '<S4>/Warp'
    rtB.absx21 = rtB.srcXIntrinsic[p1];
    if ((rtB.absx21 >= 1.0) && (rtB.absx21 <= 640.0)) {
      rtB.absx11 = rtB.srcYIntrinsic[p1];
      if ((rtB.absx11 >= 1.0) && (rtB.absx11 <= 480.0)) {
        real32_T qx1;
        if (rtB.absx21 <= 1.0) {
          itmp = 1;
        } else if (rtB.absx21 <= 639.0) {
          itmp = static_cast<int32_T>(floor(rtB.absx21));
        } else {
          itmp = 639;
        }

        rtB.absx11 = rtB.srcYIntrinsic[p1];
        if (rtB.absx11 <= 1.0) {
          p3 = 1;
        } else if (rtB.absx11 <= 479.0) {
          p3 = static_cast<int32_T>(floor(rtB.absx11));
        } else {
          p3 = 479;
        }

        if (rtB.absx21 == itmp) {
          p2 = (itmp - 1) * 480 + p3;
          qx1 = rtB.inputImage[p2 - 1];
          qx2 = rtB.inputImage[p2];
        } else if (static_cast<real_T>(itmp) + 1.0 == rtB.absx21) {
          p2 = 480 * itmp + p3;
          qx1 = rtB.inputImage[p2 - 1];
          qx2 = rtB.inputImage[p2];
        } else {
          int8_T tmp;
          int8_T tmp_0;
          rtB.absx21 -= static_cast<real_T>(itmp);
          p2 = (itmp - 1) * 480 + p3;
          tmp = rtB.inputImage[p2 - 1];
          itmp = 480 * itmp + p3;
          tmp_0 = rtB.inputImage[itmp - 1];
          if (tmp == tmp_0) {
            qx1 = tmp;
          } else {
            qx1 = static_cast<real32_T>(1.0 - rtB.absx21) * static_cast<real32_T>
              (tmp) + static_cast<real32_T>(tmp_0) * static_cast<real32_T>
              (rtB.absx21);
          }

          tmp = rtB.inputImage[p2];
          tmp_0 = rtB.inputImage[itmp];
          if (tmp == tmp_0) {
            qx2 = tmp;
          } else {
            qx2 = static_cast<real32_T>(1.0 - rtB.absx21) * static_cast<real32_T>
              (tmp) + static_cast<real32_T>(tmp_0) * static_cast<real32_T>
              (rtB.absx21);
          }
        }

        if ((rtB.absx11 == p3) || (qx1 == qx2)) {
          qx2 = qx1;
        } else if (!(static_cast<real_T>(p3) + 1.0 == rtB.absx11)) {
          rtB.absx11 -= static_cast<real_T>(p3);
          qx2 = static_cast<real32_T>(1.0 - rtB.absx11) * qx1 +
            static_cast<real32_T>(rtB.absx11) * qx2;
        }
      } else {
        qx2 = 0.0F;
      }
    } else {
      qx2 = 0.0F;
    }

    Jout[p1] = (qx2 > 0.5F);
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static void eml_find(const boolean_T x[307200], coder::array<int32_T, 1U> &i,
                     coder::array<int32_T, 1U> &j)
{
  int32_T idx;
  int32_T ii;
  int32_T jj;
  boolean_T exitg1;
  idx = 0;
  i.set_size(307200);
  j.set_size(307200);
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 640)) {
    boolean_T guard1;
    guard1 = false;
    if (x[((jj - 1) * 480 + ii) - 1]) {
      idx++;
      i[idx - 1] = ii;
      j[idx - 1] = jj;
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
    i.set_size(0);
    j.set_size(0);
  } else {
    i.set_size(idx);
    j.set_size(idx);
  }
}

static void and_o(coder::array<boolean_T, 1U> &in1, const coder::array<boolean_T,
                  1U> &in2, const coder::array<boolean_T, 1U> &in3)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  loop_ub = in3.size(0) == 1 ? in2.size(0) : in3.size(0);
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i = 0; i < loop_ub; i++) {
    in1[i] = (in2[i * stride_0_0] && in3[i * stride_1_0]);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

static void binary_expand_op_3(coder::array<boolean_T, 1U> &in1, const coder::
  array<boolean_T, 1U> &in2, const coder::array<int32_T, 1U> &in3)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0_tmp;

  // MATLAB Function: '<S2>/MATLAB Function1'
  loop_ub = in3.size(0) == 1 ? in3.size(0) == 1 ? in2.size(0) : in3.size(0) :
    in3.size(0);
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0_tmp = (in3.size(0) != 1);
  for (int32_T i = 0; i < loop_ub; i++) {
    int32_T tmp;
    tmp = in3[i * stride_1_0_tmp];
    in1[i] = (in2[i * stride_0_0] && (tmp >= 0) && (tmp < 160));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static real_T mean(const coder::array<real_T, 1U> &x)
{
  real_T b_y;
  if (x.size(0) == 0) {
    b_y = 0.0;
  } else {
    int32_T firstBlockLength;
    int32_T lastBlockLength;
    int32_T nblocks;
    int32_T xblockoffset;
    if (x.size(0) <= 1024) {
      firstBlockLength = x.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = static_cast<int32_T>(static_cast<uint32_T>(x.size(0)) >> 10);
      lastBlockLength = x.size(0) - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }

    b_y = x[0];
    for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++) {
      b_y += x[xblockoffset - 1];
    }

    for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++)
    {
      real_T bsum;
      int32_T hi;
      xblockoffset = (firstBlockLength - 1) << 10;
      bsum = x[xblockoffset];
      if (firstBlockLength == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }

      for (int32_T b_k = 2; b_k <= hi; b_k++) {
        bsum += x[(xblockoffset + b_k) - 1];
      }

      b_y += bsum;
    }
  }

  return b_y / static_cast<real_T>(x.size(0));
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
static real_T maximum(const coder::array<real_T, 1U> &x)
{
  real_T ex;
  int32_T last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      ex = x[0];
    } else {
      ex = x[x.size(0) - 1];
      if (!(x[0] < ex)) {
        ex = x[0];
      }
    }
  } else {
    ex = x[0];
    for (int32_T k = 2; k <= last; k++) {
      real_T x_0;
      x_0 = x[k - 1];
      if (ex < x_0) {
        ex = x_0;
      }
    }
  }

  return ex;
}

static void binary_expand_op_2(coder::array<boolean_T, 1U> &in1, const coder::
  array<boolean_T, 1U> &in2, const coder::array<boolean_T, 1U> &in3, const coder::
  array<boolean_T, 1U> &in4, const coder::array<boolean_T, 1U> &in5)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T stride_2_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  loop_ub = in5.size(0) == 1 ? in4.size(0) == 1 ? in2.size(0) : in4.size(0) :
    in5.size(0);
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  stride_2_0 = (in5.size(0) != 1);
  for (int32_T i = 0; i < loop_ub; i++) {
    int32_T tmp;
    tmp = i * stride_0_0;
    in1[i] = (in2[tmp] && in3[tmp] && in4[i * stride_1_0] && in5[i * stride_2_0]);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

static void binary_expand_op(coder::array<boolean_T, 1U> &in1, const coder::
  array<int32_T, 1U> &in2, real_T in3, real_T in4, const coder::array<int32_T,
  1U> &in5, real_T in6)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  loop_ub = in5.size(0) == 1 ? in2.size(0) : in5.size(0);
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in5.size(0) != 1);
  for (int32_T i = 0; i < loop_ub; i++) {
    real_T tmp;
    tmp = in2[i * stride_0_0];
    in1[i] = ((tmp >= in3) && (tmp < in4) && (in5[i * stride_1_0] >= in6 - 40.0));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

static void binary_expand_op_1(coder::array<boolean_T, 1U> &in1, const coder::
  array<real_T, 1U> &in2, real_T in3, real_T in4, const coder::array<real_T, 1U>
  &in5, real_T in6)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  loop_ub = in5.size(0) == 1 ? in2.size(0) : in5.size(0);
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in5.size(0) != 1);
  for (int32_T i = 0; i < loop_ub; i++) {
    real_T tmp;
    tmp = in2[i * stride_0_0];
    in1[i] = ((tmp >= in3) && (tmp < in4) && (in5[i * stride_1_0] >= in6 - 40.0));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
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
  static const char_T ipaddr_0[14] = "192.168.1.155";

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
  int16_T errorNo;
  uint16_T tmp;
  uint8_T xtmp;
  static const int16_T tmp_0[8] = { 145, 500, 27, 639, 300, 300, 415, 415 };

  static const int16_T tmp_1[8] = { 40, 600, 40, 600, 300, 300, 480, 480 };

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
  for (rtB.k = 0; rtB.k < 640; rtB.k++) {
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 480; rtB.bestInlierNum++) {
      rtB.b_varargout_1_k[rtB.bestInlierNum + 480 * rtB.k] = rtB.b_varargout_1
        [640 * rtB.bestInlierNum + rtB.k];
    }
  }

  memcpy(&rtB.outputImage[0], &rtB.b_varargout_1_k[0], 307200U * sizeof(uint8_T));

  // End of Math: '<S3>/Transpose'

  // Math: '<S3>/Transpose1' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'
  //
  for (rtB.k = 0; rtB.k < 640; rtB.k++) {
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 480; rtB.bestInlierNum++) {
      rtB.b_varargout_1[rtB.bestInlierNum + 480 * rtB.k] = rtB.b_varargout_2[640
        * rtB.bestInlierNum + rtB.k];
    }
  }

  memcpy(&rtB.outputImage[307200], &rtB.b_varargout_1[0], 307200U * sizeof
         (uint8_T));

  // End of Math: '<S3>/Transpose1'

  // Math: '<S3>/Transpose2' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'
  //
  for (rtB.k = 0; rtB.k < 640; rtB.k++) {
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 480; rtB.bestInlierNum++) {
      rtB.b_varargout_2[rtB.bestInlierNum + 480 * rtB.k] = rtB.b_varargout_3[640
        * rtB.bestInlierNum + rtB.k];
    }
  }

  memcpy(&rtB.outputImage[614400], &rtB.b_varargout_2[0], 307200U * sizeof
         (uint8_T));

  // End of Math: '<S3>/Transpose2'

  // MATLAB Function: '<Root>/MATLAB Function'
  for (rtB.bestCol = 0; rtB.bestCol < 3; rtB.bestCol++) {
    for (rtB.j = 0; rtB.j < 640; rtB.j++) {
      for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 240; rtB.bestInlierNum++)
      {
        rtB.xtmp_tmp = (480 * rtB.j + rtB.bestInlierNum) + 307200 * rtB.bestCol;
        xtmp = rtB.outputImage[rtB.xtmp_tmp];
        rtB.k = ((480 * rtB.j - rtB.bestInlierNum) + 307200 * rtB.bestCol) + 479;
        rtB.outputImage[rtB.xtmp_tmp] = rtB.outputImage[rtB.k];
        rtB.outputImage[rtB.k] = xtmp;
      }
    }

    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 320; rtB.bestInlierNum++) {
      for (rtB.j = 0; rtB.j < 480; rtB.j++) {
        rtB.xtmp_tmp = (480 * rtB.bestInlierNum + rtB.j) + 307200 * rtB.bestCol;
        xtmp = rtB.outputImage[rtB.xtmp_tmp];
        rtB.k = ((639 - rtB.bestInlierNum) * 480 + rtB.j) + 307200 * rtB.bestCol;
        rtB.outputImage[rtB.xtmp_tmp] = rtB.outputImage[rtB.k];
        rtB.outputImage[rtB.k] = xtmp;
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
    rtB.ImageDataTypeConversion_b =
      rtB.ImageDataTypeConversion[rtB.bestInlierNum + 307200];
    if (rtB.sum > rtB.ImageDataTypeConversion_b) {
      rtB.ImageDataTypeConversion_p =
        rtB.ImageDataTypeConversion[rtB.bestInlierNum + 614400];
      if (rtB.ImageDataTypeConversion_b < rtB.ImageDataTypeConversion_p) {
        rtB.min = rtB.ImageDataTypeConversion_b;
      } else {
        rtB.min = rtB.ImageDataTypeConversion_p;
      }

      if (rtB.sum > rtB.ImageDataTypeConversion_p) {
        rtB.maxSum = rtB.sum;
      } else {
        rtB.maxSum = rtB.ImageDataTypeConversion_p;
      }
    } else {
      rtB.ImageDataTypeConversion_p =
        rtB.ImageDataTypeConversion[rtB.bestInlierNum + 614400];
      if (rtB.sum < rtB.ImageDataTypeConversion_p) {
        rtB.min = rtB.sum;
      } else {
        rtB.min = rtB.ImageDataTypeConversion_p;
      }

      if (rtB.ImageDataTypeConversion_b > rtB.ImageDataTypeConversion_p) {
        rtB.maxSum = rtB.ImageDataTypeConversion_b;
      } else {
        rtB.maxSum = rtB.ImageDataTypeConversion_p;
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
        rtB.sum = (rtB.ImageDataTypeConversion_b - rtB.ImageDataTypeConversion_p)
          / rtB.s;
      } else if (rtB.ImageDataTypeConversion_b == rtB.maxSum) {
        rtB.sum = (rtB.ImageDataTypeConversion_p - rtB.sum) / rtB.s + 2.0;
      } else {
        rtB.sum = (rtB.sum - rtB.ImageDataTypeConversion_b) / rtB.s + 4.0;
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

  for (rtB.k = 0; rtB.k < 8; rtB.k++) {
    // MATLAB Function: '<S4>/MATLAB Function1'
    rtB.pts1[rtB.k] = tmp_0[rtB.k];

    // MATLAB Function: '<S4>/MATLAB Function2'
    rtB.pts2[rtB.k] = tmp_1[rtB.k];
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
    for (rtB.j = 0; rtB.j < 9; rtB.j++) {
      if (static_cast<uint32_T>(rtB.bestInlierNum) != static_cast<uint32_T>
          (rtB.j)) {
        rtB.sum = 0.0;
      } else {
        rtB.sum = -1.0;
      }

      for (rtB.k = 0; rtB.k < 8; rtB.k++) {
        rtB.idx = static_cast<uint32_T>(rtB.k) * 9U;
        rtB.sum += rtB.Q[rtB.idx + static_cast<uint32_T>(rtB.bestInlierNum)] *
          rtB.Q[rtB.idx + static_cast<uint32_T>(rtB.j)];
      }

      rtB.RV[static_cast<uint32_T>(rtB.bestInlierNum) * 9U +
        static_cast<uint32_T>(rtB.j)] = rtB.sum;
      if (!(rtB.sum >= 0.0)) {
        rtB.sum = -rtB.sum;
      }

      if (rtB.maxSum < rtB.sum) {
        rtB.maxSum = rtB.sum;
        rtB.bestCol = rtB.bestInlierNum;
      }
    }
  }

  rtB.j = static_cast<int32_T>(static_cast<uint32_T>(rtB.bestCol) * 9U);
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 9; rtB.bestInlierNum++) {
    rtB.tformCompact[static_cast<uint32_T>(rtB.bestInlierNum)] = rtB.RV[
      static_cast<uint32_T>(rtB.j) + static_cast<uint32_T>(rtB.bestInlierNum)];
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
    rtB.idx = 0U;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 4; rtB.bestInlierNum++) {
      rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_T>
        (rtB.bestInlierNum)] = 0.0;
      for (rtB.j = 0; rtB.j < 2; rtB.j++) {
        rtB.scale1 = 0.0;
        for (rtB.k = 0; rtB.k < 9; rtB.k++) {
          rtB.scale1 +=
            rtDW.EstimateGeometricTransformation_DW_CONSTRT_ALL[rtB.idx +
            static_cast<uint32_T>(rtB.k)] * rtB.tformCompact_c
            [static_cast<uint32_T>(rtB.k)];
        }

        rtB.idx += 9U;
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
  for (rtB.k = 0; rtB.k < 307200; rtB.k++) {
    rtB.rtb_V_Channel_c[rtB.k] = (rtB.V_Channel[rtB.k] > 0.5);
  }

  // End of MATLAB Function: '<S4>/MATLAB Function8'

  // MATLABSystem: '<S4>/Warp' incorporates:
  //   S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'

  Warp_stepImpl(&rtDW.obj_k, rtB.rtb_V_Channel_c,
                rtB.EstimateGeometricTransformation, rtB.bv);

  // MATLAB Function: '<S2>/MATLAB Function1' incorporates:
  //   MATLABSystem: '<S4>/Warp'

  rtB.scale1 = 320.0;
  eml_find(rtB.bv, rtB.ii, rtB.jj);
  rtB.c.set_size(rtB.ii.size(0));
  rtB.j = rtB.ii.size(0);
  rtB.d.set_size(rtB.ii.size(0));
  for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
    rtB.xtmp_tmp = rtB.ii[rtB.k];
    rtB.c[rtB.k] = (rtB.xtmp_tmp >= 456);
    rtB.d[rtB.k] = (rtB.xtmp_tmp < 480);
  }

  rtB.g.set_size(rtB.jj.size(0));
  rtB.j = rtB.jj.size(0);
  for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
    rtB.g[rtB.k] = (rtB.jj[rtB.k] >= 480);
  }

  rtB.b_tmp.set_size(rtB.c.size(0));
  rtB.j = rtB.c.size(0);
  for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
    rtB.b_tmp[rtB.k] = (rtB.c[rtB.k] && rtB.d[rtB.k]);
  }

  if (rtB.b_tmp.size(0) == rtB.g.size(0)) {
    rtB.b.set_size(rtB.b_tmp.size(0));
    rtB.j = rtB.b_tmp.size(0);
    for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
      rtB.b[rtB.k] = (rtB.b_tmp[rtB.k] && rtB.g[rtB.k]);
    }
  } else {
    and_o(rtB.b, rtB.b_tmp, rtB.g);
  }

  rtB.h.set_size(rtB.jj.size(0));
  rtB.j = rtB.jj.size(0);
  for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
    rtB.h[rtB.k] = (rtB.jj[rtB.k] < 640);
  }

  if (rtB.b.size(0) == rtB.h.size(0)) {
    rtB.r1.set_size(rtB.b.size(0));
    rtB.j = rtB.b.size(0);
    for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
      rtB.r1[rtB.k] = (rtB.b[rtB.k] && rtB.h[rtB.k]);
    }
  } else {
    and_o(rtB.r1, rtB.b, rtB.h);
  }

  rtB.k = rtB.r1.size(0) - 1;
  rtB.xtmp_tmp = 0;
  for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.k; rtB.bestInlierNum++) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    if (rtB.r1[rtB.bestInlierNum]) {
      rtB.xtmp_tmp++;
    }
  }

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (rtB.xtmp_tmp > 30) {
    rtB.bestCol = 1;
    if (rtB.b.size(0) == rtB.h.size(0)) {
      rtB.r2.set_size(rtB.b.size(0));
      rtB.j = rtB.b.size(0);
      for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
        rtB.r2[rtB.k] = (rtB.b[rtB.k] && rtB.h[rtB.k]);
      }
    } else {
      and_o(rtB.r2, rtB.b, rtB.h);
    }

    rtB.k = rtB.r2.size(0) - 1;
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.k; rtB.bestInlierNum++)
    {
      if (rtB.r2[rtB.bestInlierNum]) {
        rtB.xtmp_tmp++;
      }
    }

    rtB.r.set_size(rtB.xtmp_tmp);
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.k; rtB.bestInlierNum++)
    {
      if (rtB.r2[rtB.bestInlierNum]) {
        rtB.r[rtB.xtmp_tmp] = rtB.bestInlierNum;
        rtB.xtmp_tmp++;
      }
    }

    rtB.jj_m.set_size(rtB.r.size(0));
    rtB.j = rtB.r.size(0);
    for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
      rtB.jj_m[rtB.k] = rtB.jj[rtB.r[rtB.k]];
    }

    rtB.scale2 = mean(rtB.jj_m);
    if ((rtB.c.size(0) == rtB.g.size(0)) && ((rtB.c.size(0) == 1 ? rtB.g.size(0)
          : rtB.c.size(0)) == rtB.h.size(0))) {
      rtB.r3.set_size(rtB.c.size(0));
      rtB.j = rtB.c.size(0);
      for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
        rtB.r3[rtB.k] = (rtB.c[rtB.k] && rtB.d[rtB.k] && rtB.g[rtB.k] &&
                         rtB.h[rtB.k]);
      }
    } else {
      binary_expand_op_2(rtB.r3, rtB.c, rtB.d, rtB.g, rtB.h);
    }

    rtB.k = rtB.r3.size(0) - 1;
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.k; rtB.bestInlierNum++)
    {
      if (rtB.r3[rtB.bestInlierNum]) {
        rtB.xtmp_tmp++;
      }
    }

    rtB.r8.set_size(rtB.xtmp_tmp);
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.k; rtB.bestInlierNum++)
    {
      if (rtB.r3[rtB.bestInlierNum]) {
        rtB.r8[rtB.xtmp_tmp] = rtB.bestInlierNum;
        rtB.xtmp_tmp++;
      }
    }

    rtB.jj_m.set_size(rtB.r8.size(0));
    rtB.j = rtB.r8.size(0);
    for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
      rtB.jj_m[rtB.k] = rtB.ii[rtB.r8[rtB.k]];
    }

    rtB.maxSum = maximum(rtB.jj_m);
  } else {
    rtB.bestCol = 2;
    if ((rtB.b_tmp.size(0) == rtB.jj.size(0)) && ((rtB.b_tmp.size(0) == 1 ?
          rtB.jj.size(0) : rtB.b_tmp.size(0)) == rtB.jj.size(0))) {
      rtB.r2.set_size(rtB.b_tmp.size(0));
      rtB.j = rtB.b_tmp.size(0);
      for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
        rtB.xtmp_tmp = rtB.jj[rtB.k];
        rtB.r2[rtB.k] = (rtB.b_tmp[rtB.k] && (rtB.xtmp_tmp >= 0) &&
                         (rtB.xtmp_tmp < 160));
      }
    } else {
      binary_expand_op_3(rtB.r2, rtB.b_tmp, rtB.jj);
    }

    rtB.k = rtB.r2.size(0) - 1;
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.k; rtB.bestInlierNum++)
    {
      if (rtB.r2[rtB.bestInlierNum]) {
        rtB.xtmp_tmp++;
      }
    }

    rtB.r.set_size(rtB.xtmp_tmp);
    rtB.xtmp_tmp = 0;
    for (rtB.bestInlierNum = 0; rtB.bestInlierNum <= rtB.k; rtB.bestInlierNum++)
    {
      if (rtB.r2[rtB.bestInlierNum]) {
        rtB.r[rtB.xtmp_tmp] = rtB.bestInlierNum;
        rtB.xtmp_tmp++;
      }
    }

    rtB.jj_m.set_size(rtB.r.size(0));
    rtB.j = rtB.r.size(0);
    for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
      rtB.jj_m[rtB.k] = rtB.jj[rtB.r[rtB.k]];
    }

    rtB.scale2 = mean(rtB.jj_m);
    rtB.jj_m.set_size(rtB.r.size(0));
    rtB.j = rtB.r.size(0);
    for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
      rtB.jj_m[rtB.k] = rtB.ii[rtB.r[rtB.k]];
    }

    rtB.maxSum = maximum(rtB.jj_m);
  }

  for (rtB.bestInlierNum = 0; rtB.bestInlierNum < 20; rtB.bestInlierNum++) {
    if (rtB.bestCol == 1) {
      rtB.win_y_low = rtB.maxSum - ((static_cast<real_T>(rtB.bestInlierNum) +
        1.0) + 1.0) * 24.0;
      rtB.sum = rtB.maxSum - (static_cast<real_T>(rtB.bestInlierNum) + 1.0) *
        24.0;
      rtB.xtmp_tmp = rtB.ii.size(0);
      rtB.jj_m.set_size(rtB.ii.size(0));
      for (rtB.k = 0; rtB.k < rtB.xtmp_tmp; rtB.k++) {
        rtB.jj_m[rtB.k] = rtB.ii[rtB.k];
      }

      rtB.xtmp_tmp = rtB.jj.size(0);
      rtB.c_tmp.set_size(rtB.jj.size(0));
      for (rtB.k = 0; rtB.k < rtB.xtmp_tmp; rtB.k++) {
        rtB.c_tmp[rtB.k] = rtB.jj[rtB.k];
      }

      if (rtB.jj_m.size(0) == rtB.c_tmp.size(0)) {
        rtB.c.set_size(rtB.jj_m.size(0));
        rtB.j = rtB.jj_m.size(0);
        for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
          rtB.xtmp_tmp = static_cast<int32_T>(rtB.jj_m[rtB.k]);
          rtB.c[rtB.k] = ((rtB.xtmp_tmp >= rtB.win_y_low) && (rtB.xtmp_tmp <
            rtB.sum) && (rtB.c_tmp[rtB.k] >= rtB.scale2 - 40.0));
        }
      } else {
        binary_expand_op_1(rtB.c, rtB.jj_m, rtB.win_y_low, rtB.sum, rtB.c_tmp,
                           rtB.scale2);
      }

      rtB.d.set_size(rtB.c_tmp.size(0));
      rtB.j = rtB.c_tmp.size(0);
      for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
        rtB.d[rtB.k] = (rtB.c_tmp[rtB.k] < rtB.scale2 + 40.0);
      }

      if (rtB.c.size(0) == rtB.d.size(0)) {
        rtB.r5.set_size(rtB.c.size(0));
        rtB.j = rtB.c.size(0);
        for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
          rtB.r5[rtB.k] = (rtB.c[rtB.k] && rtB.d[rtB.k]);
        }
      } else {
        and_o(rtB.r5, rtB.c, rtB.d);
      }

      rtB.k = rtB.r5.size(0) - 1;
      rtB.xtmp_tmp = 0;
      for (rtB.j = 0; rtB.j <= rtB.k; rtB.j++) {
        if (rtB.r5[rtB.j]) {
          rtB.xtmp_tmp++;
        }
      }

      if (rtB.xtmp_tmp > 30) {
        if (rtB.c.size(0) == rtB.d.size(0)) {
          rtB.r7.set_size(rtB.c.size(0));
          rtB.j = rtB.c.size(0);
          for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
            rtB.r7[rtB.k] = (rtB.c[rtB.k] && rtB.d[rtB.k]);
          }
        } else {
          and_o(rtB.r7, rtB.c, rtB.d);
        }

        rtB.k = rtB.r7.size(0) - 1;
        rtB.xtmp_tmp = 0;
        for (rtB.j = 0; rtB.j <= rtB.k; rtB.j++) {
          if (rtB.r7[rtB.j]) {
            rtB.xtmp_tmp++;
          }
        }

        rtB.r10.set_size(rtB.xtmp_tmp);
        rtB.xtmp_tmp = 0;
        for (rtB.j = 0; rtB.j <= rtB.k; rtB.j++) {
          if (rtB.r7[rtB.j]) {
            rtB.r10[rtB.xtmp_tmp] = rtB.j;
            rtB.xtmp_tmp++;
          }
        }

        rtB.j = rtB.r10.size(0);
        rtB.jj_m.set_size(rtB.r10.size(0));
        for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
          rtB.jj_m[rtB.k] = rtB.jj[rtB.r10[rtB.k]];
        }

        rtB.scale2 = mean(rtB.jj_m);
      }

      if ((rtB.win_y_low > 300.0) && (rtB.win_y_low < 340.0)) {
        rtB.scale1 = rtB.scale2 - 220.0;
      }
    } else {
      rtB.win_y_low = rtB.maxSum - ((static_cast<real_T>(rtB.bestInlierNum) +
        1.0) + 1.0) * 24.0;
      rtB.sum = rtB.maxSum - (static_cast<real_T>(rtB.bestInlierNum) + 1.0) *
        24.0;
      rtB.xtmp_tmp = rtB.ii.size(0);
      if (rtB.ii.size(0) == rtB.jj.size(0)) {
        rtB.c.set_size(rtB.ii.size(0));
        for (rtB.k = 0; rtB.k < rtB.xtmp_tmp; rtB.k++) {
          rtB.j = rtB.ii[rtB.k];
          rtB.c[rtB.k] = ((rtB.j >= rtB.win_y_low) && (rtB.j < rtB.sum) &&
                          (rtB.jj[rtB.k] >= rtB.scale2 - 40.0));
        }
      } else {
        binary_expand_op(rtB.c, rtB.ii, rtB.win_y_low, rtB.sum, rtB.jj,
                         rtB.scale2);
      }

      rtB.xtmp_tmp = rtB.jj.size(0);
      rtB.d.set_size(rtB.jj.size(0));
      for (rtB.k = 0; rtB.k < rtB.xtmp_tmp; rtB.k++) {
        rtB.d[rtB.k] = (rtB.jj[rtB.k] < rtB.scale2 + 40.0);
      }

      if (rtB.c.size(0) == rtB.d.size(0)) {
        rtB.r4.set_size(rtB.c.size(0));
        rtB.j = rtB.c.size(0);
        for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
          rtB.r4[rtB.k] = (rtB.c[rtB.k] && rtB.d[rtB.k]);
        }
      } else {
        and_o(rtB.r4, rtB.c, rtB.d);
      }

      rtB.k = rtB.r4.size(0) - 1;
      rtB.xtmp_tmp = 0;
      for (rtB.j = 0; rtB.j <= rtB.k; rtB.j++) {
        if (rtB.r4[rtB.j]) {
          rtB.xtmp_tmp++;
        }
      }

      if (rtB.xtmp_tmp > 30) {
        if (rtB.c.size(0) == rtB.d.size(0)) {
          rtB.r6.set_size(rtB.c.size(0));
          rtB.j = rtB.c.size(0);
          for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
            rtB.r6[rtB.k] = (rtB.c[rtB.k] && rtB.d[rtB.k]);
          }
        } else {
          and_o(rtB.r6, rtB.c, rtB.d);
        }

        rtB.k = rtB.r6.size(0) - 1;
        rtB.xtmp_tmp = 0;
        for (rtB.j = 0; rtB.j <= rtB.k; rtB.j++) {
          if (rtB.r6[rtB.j]) {
            rtB.xtmp_tmp++;
          }
        }

        rtB.r9.set_size(rtB.xtmp_tmp);
        rtB.xtmp_tmp = 0;
        for (rtB.j = 0; rtB.j <= rtB.k; rtB.j++) {
          if (rtB.r6[rtB.j]) {
            rtB.r9[rtB.xtmp_tmp] = rtB.j;
            rtB.xtmp_tmp++;
          }
        }

        rtB.j = rtB.r9.size(0);
        rtB.jj_m.set_size(rtB.r9.size(0));
        for (rtB.k = 0; rtB.k < rtB.j; rtB.k++) {
          rtB.jj_m[rtB.k] = rtB.jj[rtB.r9[rtB.k]];
        }

        rtB.scale2 = mean(rtB.jj_m);
      }

      if ((rtB.win_y_low > 300.0) && (rtB.win_y_low < 340.0)) {
        rtB.scale1 = rtB.scale2 + 290.0;
      }
    }

    rtB.win_y_low = 340.0 - rtB.scale1;
  }

  // MATLABSystem: '<Root>/TCP//IP Send1' incorporates:
  //   MATLAB Function: '<S2>/MATLAB Function1'

  // Update view port.
  // Draw all rectangles.
  // Calculate FillColor times Opacity.
  // Calculate One minus Opacity.
  // Update view port.
  // Draw all circles.
  // Calculate FillColor times Opacity.
  // Calculate One minus Opacity.
  // Update view port.
  // Draw all circles.
  if (rtDW.obj_d.isLittleEnd_ == 1) {
    memcpy((void *)&rtB.b_x[0], (void *)&rtB.win_y_low, (size_t)8 * sizeof
           (uint8_T));
    xtmp = rtB.b_x[0];
    rtB.b_x[0] = rtB.b_x[7];
    rtB.b_x[7] = xtmp;
    xtmp = rtB.b_x[1];
    rtB.b_x[1] = rtB.b_x[6];
    rtB.b_x[6] = xtmp;
    xtmp = rtB.b_x[2];
    rtB.b_x[2] = rtB.b_x[5];
    rtB.b_x[5] = xtmp;
    xtmp = rtB.b_x[3];
    rtB.b_x[3] = rtB.b_x[4];
    rtB.b_x[4] = xtmp;
    memcpy((void *)&rtB.win_y_low, (void *)&rtB.b_x[0], (size_t)1 * sizeof
           (real_T));
  }

  rtB.scale1 = rt_roundd_snf(rtDW.obj_d.isServer_);
  if (rtB.scale1 < 65536.0) {
    if (rtB.scale1 >= 0.0) {
      tmp = static_cast<uint16_T>(rtB.scale1);
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint16_T;
  }

  TCPStreamStepSend(&rtB.win_y_low, 8U, rtDW.obj_d.connStream_, tmp, &errorNo);

  // End of MATLABSystem: '<Root>/TCP//IP Send1'
}

// Model initialize function
void Rpi_cam_initialize(void)
{
  {
    int32_T i;
    char_T devName[12];
    static const char_T devName_0[12] = "/dev/video0";
    static const int8_T self_T[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    // Start for S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' 
    srand(clock());

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
