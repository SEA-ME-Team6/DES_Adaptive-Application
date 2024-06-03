//
//  Rpi_cam.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "Rpi_cam".
//
//  Model version              : 2.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Mon Jun  3 22:43:01 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#include "Rpi_cam.h"
#include <stdbool.h>
#include <stdint.h>
#include <cmath>
#include <cstring>
#include <array>

extern void makeConstraintMatrix_Projective_D_D(const double pts1[], const
  double pts2[], uint32_t sampleNum, uint32_t maxSampleNum, double constraint[]);
extern void normPts_D_D(const double pts[], const uint32_t samples[], uint32_t
  ptsNum, uint32_t sampleNum, double ptsNorm[], double scale[], double cents[]);
extern void QRCompQy_double(double qr[], const double qrAuxj[], double y[],
  int32_t n, int32_t j);
extern void QRSL1_double(double qr[], const double qrAux[], double y[], int32_t
  n, int32_t k);
void Rpi_cam::v4l2Capture_updateV4L2Settings
  (codertarget_raspi_internal_Raspiv4l2Capture *obj, bool forceUpdate)
{
  std::array<char, 11> b;
  std::array<char, 9> c;
  std::array<char, 10> e;
  std::array<char, 12> j;
  uint8_t status;
  static const std::array<char, 11> b_0{ { 'B', 'r', 'i', 'g', 'h', 't', 'n',
      'e', 's', 's', '\x00' } };

  static const std::array<char, 9> c_0{ { 'C', 'o', 'n', 't', 'r', 'a', 's', 't',
      '\x00' } };

  static const std::array<char, 11> d{ { 'S', 'a', 't', 'u', 'r', 'a', 't', 'i',
      'o', 'n', '\x00' } };

  static const std::array<char, 10> e_0{ { 'S', 'h', 'a', 'r', 'p', 'n', 'e',
      's', 's', '\x00' } };

  static const std::array<char, 10> f{ { 'C', 'a', 'm', 'e', 'r', 'a', 'P', 'a',
      'n', '\x00' } };

  static const std::array<char, 11> g{ { 'C', 'a', 'm', 'e', 'r', 'a', 'T', 'i',
      'l', 't', '\x00' } };

  static const std::array<char, 11> h{ { 'C', 'a', 'm', 'e', 'r', 'a', 'Z', 'o',
      'o', 'm', '\x00' } };

  static const std::array<char, 18> i_0{ { 'E', 'n', 'a', 'b', 'l', 'e', 'M',
      'a', 'n', 'u', 'a', 'l', 'F', 'o', 'c', 'u', 's', '\x00' } };

  static const std::array<char, 12> j_0{ { 'M', 'a', 'n', 'u', 'a', 'l', 'F',
      'o', 'c', 'u', 's', '\x00' } };

  // Start for MATLABSystem: '<S1>/V4L2 Video Capture'
  if ((obj->Brightness != obj->BrightnessInternal) || forceUpdate) {
    obj->BrightnessInternal = obj->Brightness;
    for (int32_t i{0}; i < 11; i++) {
      b[i] = b_0[i];
    }

    EXT_updateV4L2Control(&b[0], static_cast<float>(obj->Brightness), 0, &status);
  }

  if ((obj->Contrast != obj->ContrastInternal) || forceUpdate) {
    obj->ContrastInternal = obj->Contrast;
    for (int32_t i{0}; i < 9; i++) {
      c[i] = c_0[i];
    }

    EXT_updateV4L2Control(&c[0], static_cast<float>(obj->Contrast), 0, &status);
  }

  if ((obj->Saturation != obj->SaturationInternal) || forceUpdate) {
    obj->SaturationInternal = obj->Saturation;
    for (int32_t i{0}; i < 11; i++) {
      b[i] = d[i];
    }

    EXT_updateV4L2Control(&b[0], static_cast<float>(obj->Saturation), 0, &status);
  }

  if ((obj->Sharpness != obj->SharpnessInternal) || forceUpdate) {
    obj->SharpnessInternal = obj->Sharpness;
    for (int32_t i{0}; i < 10; i++) {
      e[i] = e_0[i];
    }

    EXT_updateV4L2Control(&e[0], static_cast<float>(obj->Sharpness), 0, &status);
  }

  if ((obj->CameraPan != obj->CameraPanInternal) || forceUpdate) {
    obj->CameraPanInternal = obj->CameraPan;
    for (int32_t i{0}; i < 10; i++) {
      e[i] = f[i];
    }

    EXT_updateV4L2Control(&e[0], static_cast<float>(obj->CameraPan), 0, &status);
  }

  if ((obj->CameraTilt != obj->CameraTiltInternal) || forceUpdate) {
    obj->CameraTiltInternal = obj->CameraTilt;
    for (int32_t i{0}; i < 11; i++) {
      b[i] = g[i];
    }

    EXT_updateV4L2Control(&b[0], static_cast<float>(obj->CameraTilt), 0, &status);
  }

  if ((obj->CameraZoom != obj->CameraZoomInternal) || forceUpdate) {
    obj->CameraZoomInternal = obj->CameraZoom;
    for (int32_t i{0}; i < 11; i++) {
      b[i] = h[i];
    }

    EXT_updateV4L2Control(&b[0], static_cast<float>(obj->CameraZoom), 0, &status);
  }

  if ((!obj->EnableManualFocusInternal) || forceUpdate) {
    obj->EnableManualFocusInternal = true;
    for (int32_t i{0}; i < 18; i++) {
      rtDW.i[i] = i_0[i];
    }

    EXT_updateV4L2Control(&rtDW.i[0], 1.0F, 0, &status);
  }

  if ((obj->ManualFocus != obj->ManualFocusInternal) || forceUpdate) {
    obj->ManualFocusInternal = obj->ManualFocus;
    for (int32_t i{0}; i < 12; i++) {
      j[i] = j_0[i];
    }

    EXT_updateV4L2Control(&j[0], static_cast<float>(obj->ManualFocus), 0,
                          &status);
  }

  // End of Start for MATLABSystem: '<S1>/V4L2 Video Capture'
}

void Rpi_cam::SystemCore_step(codertarget_raspi_internal_Raspiv4l2Capture *obj,
  uint8_t varargout_1[307200], uint8_t varargout_2[307200], uint8_t varargout_3
  [307200])
{
  double ts;

  // Start for MATLABSystem: '<S1>/V4L2 Video Capture'
  v4l2Capture_updateV4L2Settings(obj, false);
  EXT_webcamReadFrame(0, &ts, &varargout_1[0], &varargout_2[0], &varargout_3[0]);
}

void makeConstraintMatrix_Projective_D_D(const double pts1[], const double pts2[],
  uint32_t sampleNum, uint32_t maxSampleNum, double constraint[])
{
  uint32_t j;
  uint32_t k;

  // S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
  // Generate the constraint matrix.
  j = 0U;
  k = 6U;
  for (uint32_t i{0U}; i < sampleNum; i++) {
    double tmp;
    double tmp_1;
    uint32_t tmp_0;
    constraint[k - 6U] = 0.0;
    constraint[k + 4294967291U] = 0.0;
    constraint[k + 4294967292U] = 0.0;
    tmp_0 = j + maxSampleNum;
    tmp = pts1[tmp_0];
    constraint[k + 4294967293U] = -tmp;
    constraint[k + 4294967294U] = -pts1[j];
    constraint[k + UINT32_MAX] = -1.0;
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

  // End of S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
}

void normPts_D_D(const double pts[], const uint32_t samples[], uint32_t ptsNum,
                 uint32_t sampleNum, double ptsNorm[], double scale[], double
                 cents[])
{
  double sumDis;

  // S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
  // Normalize the points.
  cents[0U] = 0.0;
  cents[1U] = 0.0;
  for (uint32_t i{0U}; i < sampleNum; i++) {
    sumDis = pts[samples[i] + ptsNum];
    ptsNorm[i + sampleNum] = sumDis;
    cents[0U] += sumDis;
    sumDis = pts[samples[i]];
    ptsNorm[i] = sumDis;
    cents[1U] += sumDis;
  }

  cents[0U] /= static_cast<double>(sampleNum);
  cents[1U] /= static_cast<double>(sampleNum);
  sumDis = 0.0;
  for (uint32_t i{0U}; i < sampleNum; i++) {
    uint32_t j;
    j = i + sampleNum;
    ptsNorm[j] -= cents[0U];
    ptsNorm[i] -= cents[1U];
    sumDis += std::sqrt(ptsNorm[j] * ptsNorm[j] + ptsNorm[i] * ptsNorm[i]);
  }

  if (sumDis > 0.0) {
    scale[0U] = 1.4142135623730951;
    scale[0U] *= static_cast<double>(sampleNum);
    scale[0U] /= sumDis;
    for (uint32_t i{0U}; i < sampleNum + sampleNum; i++) {
      ptsNorm[i] *= scale[0U];
    }
  }

  // End of S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
}

void Rpi_cam::QRV2Norm_double_o(const double V[], int32_t N, double v2norm[])
{
  int32_t vi;

  // S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
  rtDW.tmpQRSL = 0.0;
  vi = 0;
  for (int32_t i{0}; i < N; i++) {
    rtDW.d = rtDW.tmpQRSL;
    rtDW.d1 = std::abs(V[vi]);
    if (rtDW.tmpQRSL > rtDW.d1) {
      rtDW.tmpQRSL = V[vi] / rtDW.tmpQRSL;
      rtDW.tmpQRSL = std::sqrt(rtDW.tmpQRSL * rtDW.tmpQRSL + 1.0) * rtDW.d;
    } else if (V[vi] == 0.0) {
      rtDW.tmpQRSL = 0.0;
    } else {
      rtDW.tmpQRSL /= V[vi];
      rtDW.tmpQRSL = std::sqrt(rtDW.tmpQRSL * rtDW.tmpQRSL + 1.0) * rtDW.d1;
    }

    vi++;
  }

  v2norm[0U] = rtDW.tmpQRSL;

  // End of S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
}

void Rpi_cam::QRDC_double_o(double xVec[], double qrAux[], int32_t jpvt[],
  double work[], int32_t M, int32_t N)
{
  int32_t i;
  int32_t j;
  int32_t l;
  int32_t maxj;
  int32_t minVal;
  int32_t mml;
  int32_t pl;
  int32_t plj;
  int32_t pu;
  int32_t px;
  int32_t px2;

  // S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
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
          rtDW.maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = rtDW.maxnrm;
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
          rtDW.maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = rtDW.maxnrm;
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
    QRV2Norm_double_o(&xVec[j * M], M, &qrAux[j]);
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
      rtDW.maxnrm = 0.0;
      maxj = l;
      for (j = l; j <= pu; j++) {
        if (qrAux[j] > rtDW.maxnrm) {
          rtDW.maxnrm = qrAux[j];
          maxj = j;
        }
      }

      if (maxj != l) {
        // Swap columns l and maxj
        px = l * M;
        px2 = maxj * M;
        for (i = M; i > 0; i--) {
          rtDW.maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = rtDW.maxnrm;
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
      QRV2Norm_double_o(&xVec[maxj], mml, &rtDW.nrmxl);
      rtDW.maxnrm = std::abs(rtDW.nrmxl);
      if (rtDW.maxnrm != 0.0) {
        if (std::abs(xVec[maxj]) != 0.0) {
          if (xVec[maxj] >= 0.0) {
            rtDW.nrmxl = rtDW.maxnrm;
          } else {
            rtDW.nrmxl = -rtDW.maxnrm;
          }
        }

        // Check if it's safe to multiply by 1/nrmxl instead of dividing by nrmxl 
        px2 = maxj;
        if (5.0E-20 * rtDW.nrmxl != 0.0) {
          rtDW.maxnrm = 1.0 / rtDW.nrmxl;
          for (i = mml; i > 0; i--) {
            xVec[px2] *= rtDW.maxnrm;
            px2++;
          }
        } else {
          for (i = mml; i > 0; i--) {
            xVec[px2] /= rtDW.nrmxl;
            px2++;
          }
        }

        xVec[maxj]++;

        // apply the transformation to the remaining columns, updating the norms. 
        for (j = l + 1; j < N; j++) {
          plj = j * M + l;
          px2 = plj;
          rtDW.t = 0.0;
          for (i = mml; i > 0; i--) {
            rtDW.t -= xVec[px] * xVec[px2];
            px++;
            px2++;
          }

          px = maxj;
          px2 = plj;
          rtDW.t /= xVec[maxj];
          for (i = mml; i > 0; i--) {
            xVec[px2] += rtDW.t * xVec[px];
            px++;
            px2++;
          }

          px = maxj;
          px2 = 0;
          if (qrAux[j] == 0.0) {
            px2 = 1;
          }

          if ((j >= pl) && (j <= pu) && (px2 == 0)) {
            rtDW.maxnrm = std::abs(xVec[plj]) / qrAux[j];
            rtDW.tt = 1.0 - rtDW.maxnrm * rtDW.maxnrm;
            if (rtDW.tt < 0.0) {
              rtDW.tt = 0.0;
            }

            rtDW.t = rtDW.tt;
            rtDW.maxnrm = qrAux[j] / work[j];
            rtDW.tt = 0.05 * rtDW.tt * rtDW.maxnrm * rtDW.maxnrm + 1.0;
            if (rtDW.tt != 1.0) {
              qrAux[j] *= std::sqrt(rtDW.t);
            } else {
              QRV2Norm_double_o(&xVec[plj + 1], mml - 1, &rtDW.maxnrm);
              qrAux[j] = rtDW.maxnrm;
              work[j] = qrAux[j];
            }
          }
        }

        // save the transformation.
        qrAux[l] = xVec[px];
        xVec[px] = -rtDW.nrmxl;
      }
    }
  }

  // End of S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
}

void QRCompQy_double(double qr[], const double qrAuxj[], double y[], int32_t n,
                     int32_t j)
{
  // S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
  if (std::abs(qrAuxj[0U]) != 0.0) {
    double t;
    double temp;
    int32_t nmj;
    int32_t pjj;
    int32_t pqr;
    int32_t py;
    nmj = n - j;
    pjj = (n + 1) * j;
    pqr = pjj;
    temp = qr[pjj];
    qr[pjj] = qrAuxj[0U];
    t = 0.0;
    py = 0;
    for (int32_t i{nmj}; i > 0; i--) {
      t -= y[py] * qr[pqr];
      pqr++;
      py++;
    }

    pqr = pjj;
    t /= qr[pjj];
    py = 0;
    for (int32_t i{nmj}; i > 0; i--) {
      y[py] += t * qr[pqr];
      pqr++;
      py++;
    }

    qr[pjj] = temp;
  }

  // End of S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
}

void QRSL1_double(double qr[], const double qrAux[], double y[], int32_t n,
                  int32_t k)
{
  int32_t j;
  int32_t pqraux;
  int32_t y_0;

  // S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
  if (k <= n - 1) {
    y_0 = k;
    pqraux = k;
  } else {
    y_0 = n - 1;
    pqraux = n - 1;
  }

  j = pqraux - 1;
  if (y_0 != 0) {
    pqraux--;
    y_0--;
    while (j + 1 > 0) {
      QRCompQy_double(&qr[0], &qrAux[pqraux], &y[y_0], n, j);
      y_0 = pqraux - 1;
      pqraux--;
      j--;
    }
  }

  // End of S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
}

void Rpi_cam::QRE_double_o(double outQ[], double outR[], double outE[], double
  qrAux[], double work[], int32_t jpvt[], double sPtr[], int32_t M, int32_t N,
  bool economy)
{
  int32_t L_tmp;

  // S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
  QRDC_double_o(&outR[0], &qrAux[0], &jpvt[0], &work[0], M, N);

  // explicitly form q by manipulating identity
  if (economy) {
    if (M <= N) {
      rtDW.L = M;
    } else {
      rtDW.L = N;
    }
  } else {
    rtDW.L = M;
  }

  L_tmp = 0;
  rtDW.j = 0;
  while (rtDW.j < M * rtDW.L) {
    outQ[rtDW.j] = 0.0;
    rtDW.j++;
  }

  rtDW.j = 0;
  while (rtDW.j < rtDW.L) {
    outQ[L_tmp] = 1.0;
    L_tmp = (L_tmp + M) + 1;
    rtDW.j++;
  }

  // Convert cols of identity into cols of q. Use info stored in lower triangle of r and in vector qraux to work on columns of identity matrix I and transform them into q*I(:,j) i.e. the columns of q. 
  L_tmp = 0;
  rtDW.j = 0;
  while (rtDW.j < rtDW.L) {
    QRSL1_double(&outR[0], &qrAux[0], &outQ[L_tmp], M, N);
    L_tmp += M;
    rtDW.j++;
  }

  if (economy && (M > N)) {
    // Copy upper triangle of r to s
    rtDW.L = 0;
    rtDW.ps = 0;
    rtDW.j = 1;
    while (rtDW.j - 1 < N) {
      for (L_tmp = 0; L_tmp < rtDW.j; L_tmp++) {
        sPtr[rtDW.ps] = outR[rtDW.L];
        rtDW.ps++;
        rtDW.L++;
      }

      rtDW.L = (rtDW.L + M) - rtDW.j;
      for (L_tmp = 0; L_tmp < N - rtDW.j; L_tmp++) {
        sPtr[rtDW.ps] = 0.0;
        rtDW.ps++;
      }

      rtDW.j++;
    }
  } else {
    // Zero strict lower triangle of r
    rtDW.L = M * N - 1;
    rtDW.j = N;
    while (rtDW.j - 1 >= 0) {
      for (L_tmp = M; L_tmp > rtDW.j; L_tmp--) {
        outR[rtDW.L] = 0.0;
        rtDW.L--;
      }

      if (M < rtDW.j) {
        rtDW.L -= M;
      } else {
        rtDW.L -= rtDW.j;
      }

      rtDW.j--;
    }
  }

  // form permutation vector e
  rtDW.L = 0;
  L_tmp = 0;
  rtDW.j = 0;
  while (rtDW.j < N) {
    outE[rtDW.L] = jpvt[L_tmp] + 1;
    L_tmp = rtDW.L + 1;
    rtDW.L++;
    rtDW.j++;
  }

  // End of S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
}

void Rpi_cam::Warp_stepImpl(vision_internal_blocks_Warp *b_this, const bool
  Image[307200], const double input2[9], bool Jout[307200])
{
  int32_t itmp;
  int32_t p1;
  int32_t p2;
  int32_t p3;
  for (p2 = 0; p2 < 9; p2++) {
    // Start for MATLABSystem: '<S5>/Warp'
    rtDW.absx11 = input2[p2];
    b_this->TformProjective.T[p2] = rtDW.absx11;
    rtDW.x[p2] = rtDW.absx11;
  }

  p1 = 1;
  p2 = 3;
  p3 = 6;

  // Start for MATLABSystem: '<S5>/Warp'
  rtDW.absx11 = std::abs(b_this->TformProjective.T[0]);
  rtDW.absx21 = std::abs(b_this->TformProjective.T[1]);
  rtDW.absx31 = std::abs(b_this->TformProjective.T[2]);
  if ((rtDW.absx21 > rtDW.absx11) && (rtDW.absx21 > rtDW.absx31)) {
    p1 = 4;
    p2 = 0;
    rtDW.x[0] = b_this->TformProjective.T[1];
    rtDW.x[1] = b_this->TformProjective.T[0];
    rtDW.x[3] = b_this->TformProjective.T[4];
    rtDW.x[4] = b_this->TformProjective.T[3];
    rtDW.x[6] = b_this->TformProjective.T[7];
    rtDW.x[7] = b_this->TformProjective.T[6];
  } else if (rtDW.absx31 > rtDW.absx11) {
    p1 = 7;
    p3 = 0;
    rtDW.x[0] = b_this->TformProjective.T[2];
    rtDW.x[2] = b_this->TformProjective.T[0];
    rtDW.x[3] = b_this->TformProjective.T[5];
    rtDW.x[5] = b_this->TformProjective.T[3];
    rtDW.x[6] = b_this->TformProjective.T[8];
    rtDW.x[8] = b_this->TformProjective.T[6];
  }

  rtDW.absx31 = rtDW.x[1] / rtDW.x[0];
  rtDW.x[1] = rtDW.absx31;

  // Start for MATLABSystem: '<S5>/Warp'
  rtDW.absx11 = rtDW.x[2] / rtDW.x[0];
  rtDW.x[2] = rtDW.absx11;
  rtDW.x[4] -= rtDW.absx31 * rtDW.x[3];
  rtDW.x[5] -= rtDW.absx11 * rtDW.x[3];
  rtDW.x[7] -= rtDW.absx31 * rtDW.x[6];
  rtDW.x[8] -= rtDW.absx11 * rtDW.x[6];

  // Start for MATLABSystem: '<S5>/Warp'
  if (std::abs(rtDW.x[5]) > std::abs(rtDW.x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    rtDW.x[1] = rtDW.absx11;
    rtDW.x[2] = rtDW.absx31;
    rtDW.absx11 = rtDW.x[4];
    rtDW.x[4] = rtDW.x[5];
    rtDW.x[5] = rtDW.absx11;
    rtDW.absx11 = rtDW.x[7];
    rtDW.x[7] = rtDW.x[8];
    rtDW.x[8] = rtDW.absx11;
  }

  rtDW.absx31 = rtDW.x[5] / rtDW.x[4];
  rtDW.x[8] -= rtDW.absx31 * rtDW.x[7];

  // Start for MATLABSystem: '<S5>/Warp'
  rtDW.absx11 = (rtDW.x[1] * rtDW.absx31 - rtDW.x[2]) / rtDW.x[8];
  rtDW.absx21 = -(rtDW.x[7] * rtDW.absx11 + rtDW.x[1]) / rtDW.x[4];
  rtDW.tinv[p1 - 1] = ((1.0 - rtDW.x[3] * rtDW.absx21) - rtDW.x[6] * rtDW.absx11)
    / rtDW.x[0];
  rtDW.tinv[p1] = rtDW.absx21;
  rtDW.tinv[p1 + 1] = rtDW.absx11;
  rtDW.absx11 = -rtDW.absx31 / rtDW.x[8];
  rtDW.absx21 = (1.0 - rtDW.x[7] * rtDW.absx11) / rtDW.x[4];
  rtDW.tinv[p2] = -(rtDW.x[3] * rtDW.absx21 + rtDW.x[6] * rtDW.absx11) / rtDW.x
    [0];
  rtDW.tinv[p2 + 1] = rtDW.absx21;
  rtDW.tinv[p2 + 2] = rtDW.absx11;
  rtDW.absx11 = 1.0 / rtDW.x[8];
  rtDW.absx21 = -rtDW.x[7] * rtDW.absx11 / rtDW.x[4];
  rtDW.tinv[p3] = -(rtDW.x[3] * rtDW.absx21 + rtDW.x[6] * rtDW.absx11) / rtDW.x
    [0];
  rtDW.tinv[p3 + 1] = rtDW.absx21;
  rtDW.tinv[p3 + 2] = rtDW.absx11;
  rtDW.absx21 = rtDW.tinv[6];
  rtDW.absx31 = rtDW.tinv[7];
  rtDW.tinv_b = rtDW.tinv[8];

  // Start for MATLABSystem: '<S5>/Warp'
  rtDW.tinv_p = rtDW.tinv[0];
  rtDW.tinv_c = rtDW.tinv[1];
  rtDW.tinv_f = rtDW.tinv[2];
  rtDW.tinv_g = rtDW.tinv[3];
  rtDW.tinv_g1 = rtDW.tinv[4];
  rtDW.tinv_m = rtDW.tinv[5];
  for (p1 = 0; p1 < 640; p1++) {
    for (p2 = 0; p2 < 480; p2++) {
      // Start for MATLABSystem: '<S5>/Warp'
      rtDW.absx11 = ((((static_cast<double>(p1) + 1.0) - 0.5) + 0.5) *
                     rtDW.absx21 + (((static_cast<double>(p2) + 1.0) - 0.5) +
        0.5) * rtDW.absx31) + rtDW.tinv_b;
      itmp = 480 * p1 + p2;
      rtDW.srcXIntrinsic[itmp] = ((((((static_cast<double>(p1) + 1.0) - 0.5) +
        0.5) * rtDW.tinv_p + (((static_cast<double>(p2) + 1.0) - 0.5) + 0.5) *
        rtDW.tinv_c) + rtDW.tinv_f) / rtDW.absx11 - 0.5) + 0.5;
      rtDW.srcYIntrinsic[itmp] = ((((((static_cast<double>(p1) + 1.0) - 0.5) +
        0.5) * rtDW.tinv_g + (((static_cast<double>(p2) + 1.0) - 0.5) + 0.5) *
        rtDW.tinv_g1) + rtDW.tinv_m) / rtDW.absx11 - 0.5) + 0.5;
    }
  }

  for (p2 = 0; p2 < 307200; p2++) {
    // Start for MATLABSystem: '<S5>/Warp'
    rtDW.inputImage[p2] = static_cast<int8_t>(Image[p2]);
  }

  for (p1 = 0; p1 < 307200; p1++) {
    float qx2;

    // Start for MATLABSystem: '<S5>/Warp'
    rtDW.absx11 = rtDW.srcXIntrinsic[p1];
    if ((rtDW.absx11 >= 1.0) && (rtDW.absx11 <= 640.0)) {
      rtDW.absx21 = rtDW.srcYIntrinsic[p1];
      if ((rtDW.absx21 >= 1.0) && (rtDW.absx21 <= 480.0)) {
        float qx1;
        if (rtDW.absx11 <= 1.0) {
          p3 = 1;
        } else if (rtDW.absx11 <= 639.0) {
          p3 = static_cast<int32_t>(std::floor(rtDW.absx11));
        } else {
          p3 = 639;
        }

        rtDW.absx21 = rtDW.srcYIntrinsic[p1];
        if (rtDW.absx21 <= 1.0) {
          itmp = 1;
        } else if (rtDW.absx21 <= 479.0) {
          itmp = static_cast<int32_t>(std::floor(rtDW.absx21));
        } else {
          itmp = 479;
        }

        if (rtDW.absx11 == p3) {
          p2 = (p3 - 1) * 480 + itmp;
          qx1 = rtDW.inputImage[p2 - 1];
          qx2 = rtDW.inputImage[p2];
        } else if (static_cast<double>(p3) + 1.0 == rtDW.absx11) {
          p2 = 480 * p3 + itmp;
          qx1 = rtDW.inputImage[p2 - 1];
          qx2 = rtDW.inputImage[p2];
        } else {
          int8_t tmp;
          int8_t tmp_0;
          rtDW.absx11 -= static_cast<double>(p3);
          p2 = (p3 - 1) * 480 + itmp;
          tmp = rtDW.inputImage[p2 - 1];
          p3 = 480 * p3 + itmp;
          tmp_0 = rtDW.inputImage[p3 - 1];
          if (tmp == tmp_0) {
            qx1 = tmp;
          } else {
            qx1 = static_cast<float>(1.0 - rtDW.absx11) * static_cast<float>(tmp)
              + static_cast<float>(tmp_0) * static_cast<float>(rtDW.absx11);
          }

          tmp = rtDW.inputImage[p2];
          tmp_0 = rtDW.inputImage[p3];
          if (tmp == tmp_0) {
            qx2 = tmp;
          } else {
            qx2 = static_cast<float>(1.0 - rtDW.absx11) * static_cast<float>(tmp)
              + static_cast<float>(tmp_0) * static_cast<float>(rtDW.absx11);
          }
        }

        if ((rtDW.absx21 == itmp) || (qx1 == qx2)) {
          qx2 = qx1;
        } else if (!(static_cast<double>(itmp) + 1.0 == rtDW.absx21)) {
          rtDW.absx11 = rtDW.absx21 - static_cast<double>(itmp);
          qx2 = static_cast<float>(1.0 - rtDW.absx11) * qx1 + static_cast<float>
            (rtDW.absx11) * qx2;
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

codertarget_raspi_internal_Raspiv4l2Capture *Rpi_cam::
  Raspiv4l2Capture_Raspiv4l2Capture(codertarget_raspi_internal_Raspiv4l2Capture *
  obj)
{
  codertarget_raspi_internal_Raspiv4l2Capture *b_obj;

  // Start for MATLABSystem: '<S1>/V4L2 Video Capture'
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

void Rpi_cam::SystemCore_setup(codertarget_raspi_internal_Raspiv4l2Capture *obj)
{
  int32_t i;
  int8_t resolutionStatus;
  uint8_t camIndex;
  static const std::array<char, 12> devName{ { '/', 'd', 'e', 'v', '/', 'v', 'i',
      'd', 'e', 'o', '0', '\x00' } };

  static const std::array<char, 101> b_errorMessage{ { 'W', 'e', 'b', 'c', 'a',
      'm', ' ', 'c', 'a', 'n', 'n', 'o', 't', ' ', 'b', 'e', ' ', 'i', 'n', 'i',
      't', 'i', 'a', 'l', 'i', 'z', 'e', 'd', ' ', 'p', 'r', 'o', 'p', 'e', 'r',
      'l', 'y', '.', ' ', 'P', 'l', 'e', 'a', 's', 'e', ' ', 'c', 'h', 'e', 'c',
      'k', ' ', 'i', 'f', ' ', 't', 'h', 'e', ' ', 'd', 'e', 'v', 'i', 'c', 'e',
      ' ', 's', 'u', 'p', 'p', 'o', 'r', 't', 's', ' ', 't', 'h', 'e', ' ', 's',
      'p', 'e', 'c', 'i', 'f', 'i', 'e', 'd', ' ', 'r', 'e', 's', 'o', 'l', 'u',
      't', 'i', 'o', 'n', '.', '\x00' } };

  obj->isSetupComplete = false;

  // Start for MATLABSystem: '<S1>/V4L2 Video Capture'
  obj->isInitialized = 1;
  getCameraList();
  for (i = 0; i < 12; i++) {
    rtDW.devName[i] = devName[i];
  }

  // Start for MATLABSystem: '<S1>/V4L2 Video Capture'
  camIndex = getCameraAddrIndex(&rtDW.devName[0], 11U);
  resolutionStatus = validateResolution(camIndex, 640, 480);
  if (resolutionStatus >= 0) {
    // Start for MATLABSystem: '<S1>/V4L2 Video Capture'
    EXT_webcamInit(0, 0, 0, 0, 0, 0, 640U, 480U, 2U, 2U, 1U, 0.1);
  } else {
    // Start for MATLABSystem: '<S1>/V4L2 Video Capture'
    std::memcpy(&rtDW.b_errorMessage[0], &b_errorMessage[0], 101U * sizeof(char));
    std::perror(&rtDW.b_errorMessage[0]);

    // Start for MATLABSystem: '<S1>/V4L2 Video Capture'
    std::exit(0);
  }

  // Start for MATLABSystem: '<S1>/V4L2 Video Capture'
  v4l2Capture_updateV4L2Settings(obj, true);
  obj->isSetupComplete = true;
}

void Rpi_cam::SystemCore_setup_o(codertarget_raspi_internal_RaspiTCPReceive *obj)
{
  std::array<char, 14> ipaddr;
  double tmp;
  int16_t errorNo;
  uint16_t tmp_0;
  uint8_t isLittleEndian;
  static const std::array<char, 14> ipaddr_0{ { '1', '9', '2', '.', '1', '6',
      '8', '.', '1', '.', '1', '5', '5', '\x00' } };

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  obj->isInitialized = 1;
  obj->isServer_ = 0.0;
  for (int32_t i{0}; i < 14; i++) {
    ipaddr[i] = ipaddr_0[i];
  }

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  tmp = std::round(obj->isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_t>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = UINT16_MAX;
  }

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  TCPStreamSetup(3333, 0, &obj->connStream_, tmp_0, 0.0, &errorNo, &ipaddr[0]);
  littleEndianCheck(&isLittleEndian);
}

// Model step function
void Rpi_cam::step()
{
  int16_t errorNo;
  uint16_t tmp;
  int8_t b_varargout_2;
  uint8_t xtmp;
  static const std::array<int16_t, 8> tmp_0{ { 145, 500, 27, 639, 300, 300, 415,
      415 } };

  static const std::array<int16_t, 8> tmp_1{ { 40, 600, 40, 600, 300, 300, 480,
      480 } };

  // MATLABSystem: '<Root>/TCP//IP Receive'
  rtDW.ImageDataTypeConversion_c = std::round(rtDW.obj_e.isServer_);
  if (rtDW.ImageDataTypeConversion_c < 65536.0) {
    if (rtDW.ImageDataTypeConversion_c >= 0.0) {
      tmp = static_cast<uint16_t>(rtDW.ImageDataTypeConversion_c);
    } else {
      tmp = 0U;
    }
  } else {
    tmp = UINT16_MAX;
  }

  TCPStreamStepRecv(&xtmp, &b_varargout_2, 1, rtDW.obj_e.connStream_, &errorNo,
                    tmp);

  // Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1>/Enable'

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  if (xtmp > 0) {
    // MATLABSystem: '<S1>/V4L2 Video Capture'
    if (rtDW.obj.Brightness != 0.5) {
      rtDW.obj.Brightness = 0.5;
    }

    if (rtDW.obj.Saturation != 0.5) {
      rtDW.obj.Saturation = 0.5;
    }

    if (rtDW.obj.Contrast != 0.5) {
      rtDW.obj.Contrast = 0.5;
    }

    if (rtDW.obj.Sharpness != 0.5) {
      rtDW.obj.Sharpness = 0.5;
    }

    if (rtDW.obj.CameraPan != 0.0) {
      rtDW.obj.CameraPan = 0.0;
    }

    if (rtDW.obj.CameraTilt != 0.0) {
      rtDW.obj.CameraTilt = 0.0;
    }

    if (rtDW.obj.CameraZoom != 0.5) {
      rtDW.obj.CameraZoom = 0.5;
    }

    if (rtDW.obj.ManualFocus != 0.5) {
      rtDW.obj.ManualFocus = 0.5;
    }

    SystemCore_step(&rtDW.obj, &rtDW.uv[0], &rtDW.uv1[0], &rtDW.uv2[0]);

    // Math: '<S4>/Transpose' incorporates:
    //   MATLABSystem: '<S1>/V4L2 Video Capture'

    for (rtDW.bestInlierNum = 0; rtDW.bestInlierNum < 640; rtDW.bestInlierNum++)
    {
      for (rtDW.inlierNum = 0; rtDW.inlierNum < 480; rtDW.inlierNum++) {
        rtDW.uv3[rtDW.inlierNum + 480 * rtDW.bestInlierNum] = rtDW.uv[640 *
          rtDW.inlierNum + rtDW.bestInlierNum];
      }
    }

    std::memcpy(&rtDW.outputImage[0], &rtDW.uv3[0], 307200U * sizeof(uint8_t));

    // End of Math: '<S4>/Transpose'

    // Math: '<S4>/Transpose1' incorporates:
    //   MATLABSystem: '<S1>/V4L2 Video Capture'

    for (rtDW.bestInlierNum = 0; rtDW.bestInlierNum < 640; rtDW.bestInlierNum++)
    {
      for (rtDW.inlierNum = 0; rtDW.inlierNum < 480; rtDW.inlierNum++) {
        rtDW.uv[rtDW.inlierNum + 480 * rtDW.bestInlierNum] = rtDW.uv1[640 *
          rtDW.inlierNum + rtDW.bestInlierNum];
      }
    }

    std::memcpy(&rtDW.outputImage[307200], &rtDW.uv[0], 307200U * sizeof(uint8_t));

    // End of Math: '<S4>/Transpose1'

    // Math: '<S4>/Transpose2' incorporates:
    //   MATLABSystem: '<S1>/V4L2 Video Capture'

    for (rtDW.bestInlierNum = 0; rtDW.bestInlierNum < 640; rtDW.bestInlierNum++)
    {
      for (rtDW.inlierNum = 0; rtDW.inlierNum < 480; rtDW.inlierNum++) {
        rtDW.uv[rtDW.inlierNum + 480 * rtDW.bestInlierNum] = rtDW.uv2[640 *
          rtDW.inlierNum + rtDW.bestInlierNum];
      }
    }

    std::memcpy(&rtDW.outputImage[614400], &rtDW.uv[0], 307200U * sizeof(uint8_t));

    // End of Math: '<S4>/Transpose2'

    // MATLAB Function: '<S1>/MATLAB Function'
    for (rtDW.inlierNum = 0; rtDW.inlierNum < 3; rtDW.inlierNum++) {
      for (rtDW.bestInlierNum = 0; rtDW.bestInlierNum < 640; rtDW.bestInlierNum
           ++) {
        for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 240; rtDW.svdRsltVar++) {
          rtDW.xtmp_tmp = (480 * rtDW.bestInlierNum + rtDW.svdRsltVar) + 307200 *
            rtDW.inlierNum;
          xtmp = rtDW.outputImage[rtDW.xtmp_tmp];
          rtDW.outputImage_tmp = ((480 * rtDW.bestInlierNum - rtDW.svdRsltVar) +
            307200 * rtDW.inlierNum) + 479;
          rtDW.outputImage[rtDW.xtmp_tmp] =
            rtDW.outputImage[rtDW.outputImage_tmp];
          rtDW.outputImage[rtDW.outputImage_tmp] = xtmp;
        }
      }
    }

    for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 3; rtDW.svdRsltVar++) {
      for (rtDW.inlierNum = 0; rtDW.inlierNum < 320; rtDW.inlierNum++) {
        for (rtDW.bestInlierNum = 0; rtDW.bestInlierNum < 480;
             rtDW.bestInlierNum++) {
          rtDW.xtmp_tmp = (480 * rtDW.inlierNum + rtDW.bestInlierNum) + 307200 *
            rtDW.svdRsltVar;
          xtmp = rtDW.outputImage[rtDW.xtmp_tmp];
          rtDW.outputImage_tmp = ((639 - rtDW.inlierNum) * 480 +
            rtDW.bestInlierNum) + 307200 * rtDW.svdRsltVar;
          rtDW.outputImage[rtDW.xtmp_tmp] =
            rtDW.outputImage[rtDW.outputImage_tmp];
          rtDW.outputImage[rtDW.outputImage_tmp] = xtmp;
        }
      }
    }

    // End of MATLAB Function: '<S1>/MATLAB Function'

    // S-Function (svipscalenconvert): '<S5>/Image Data Type Conversion'
    for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 921600; rtDW.svdRsltVar++) {
      rtDW.ImageDataTypeConversion[rtDW.svdRsltVar] = static_cast<double>
        (rtDW.outputImage[rtDW.svdRsltVar]) / 255.0;
    }

    // End of S-Function (svipscalenconvert): '<S5>/Image Data Type Conversion'
    // temporary variables for in-place operation
    for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 307200; rtDW.svdRsltVar++) {
      // S-Function (svipcolorconv): '<S5>/Color Space  Conversion' incorporates:
      //   S-Function (svipscalenconvert): '<S5>/Image Data Type Conversion'

      // First get the min and max of the RGB triplet
      rtDW.ImageDataTypeConversion_c =
        rtDW.ImageDataTypeConversion[rtDW.svdRsltVar];
      rtDW.ImageDataTypeConversion_k =
        rtDW.ImageDataTypeConversion[rtDW.svdRsltVar + 307200];
      if (rtDW.ImageDataTypeConversion_c > rtDW.ImageDataTypeConversion_k) {
        rtDW.ImageDataTypeConversion_cx =
          rtDW.ImageDataTypeConversion[rtDW.svdRsltVar + 614400];
        if (rtDW.ImageDataTypeConversion_k < rtDW.ImageDataTypeConversion_cx) {
          rtDW.maxSum = rtDW.ImageDataTypeConversion_k;
        } else {
          rtDW.maxSum = rtDW.ImageDataTypeConversion_cx;
        }

        if (rtDW.ImageDataTypeConversion_c > rtDW.ImageDataTypeConversion_cx) {
          rtDW.bestInlierDis = rtDW.ImageDataTypeConversion_c;
        } else {
          rtDW.bestInlierDis = rtDW.ImageDataTypeConversion_cx;
        }
      } else {
        rtDW.ImageDataTypeConversion_cx =
          rtDW.ImageDataTypeConversion[rtDW.svdRsltVar + 614400];
        if (rtDW.ImageDataTypeConversion_c < rtDW.ImageDataTypeConversion_cx) {
          rtDW.maxSum = rtDW.ImageDataTypeConversion_c;
        } else {
          rtDW.maxSum = rtDW.ImageDataTypeConversion_cx;
        }

        if (rtDW.ImageDataTypeConversion_k > rtDW.ImageDataTypeConversion_cx) {
          rtDW.bestInlierDis = rtDW.ImageDataTypeConversion_k;
        } else {
          rtDW.bestInlierDis = rtDW.ImageDataTypeConversion_cx;
        }
      }

      rtDW.s1DivS2 = rtDW.bestInlierDis - rtDW.maxSum;
      if (rtDW.bestInlierDis != 0.0) {
        rtDW.maxSum = rtDW.s1DivS2 / rtDW.bestInlierDis;
      } else {
        rtDW.maxSum = 0.0;
      }

      if (rtDW.s1DivS2 != 0.0) {
        if (rtDW.ImageDataTypeConversion_c == rtDW.bestInlierDis) {
          rtDW.s1DivS2 = (rtDW.ImageDataTypeConversion_k -
                          rtDW.ImageDataTypeConversion_cx) / rtDW.s1DivS2;
        } else if (rtDW.ImageDataTypeConversion_k == rtDW.bestInlierDis) {
          rtDW.s1DivS2 = (rtDW.ImageDataTypeConversion_cx -
                          rtDW.ImageDataTypeConversion_c) / rtDW.s1DivS2 + 2.0;
        } else {
          rtDW.s1DivS2 = (rtDW.ImageDataTypeConversion_c -
                          rtDW.ImageDataTypeConversion_k) / rtDW.s1DivS2 + 4.0;
        }

        rtDW.s1DivS2 /= 6.0;
        if (rtDW.s1DivS2 < 0.0) {
          rtDW.s1DivS2++;
        }
      } else {
        rtDW.s1DivS2 = 0.0;
      }

      // assign the results
      rtDW.ColorSpaceConversion[rtDW.svdRsltVar] = rtDW.s1DivS2;
      rtDW.ColorSpaceConversion[rtDW.svdRsltVar + 307200] = rtDW.maxSum;

      // S-Function (svipcolorconv): '<S5>/Color Space  Conversion'
      rtDW.ColorSpaceConversion[rtDW.svdRsltVar + 614400] = rtDW.bestInlierDis;

      // MATLAB Function: '<S5>/MATLAB Function7' incorporates:
      //   S-Function (svipcolorconv): '<S5>/Color Space  Conversion'

      rtDW.V_Channel[rtDW.svdRsltVar] = rtDW.bestInlierDis;
    }

    for (rtDW.bestInlierNum = 0; rtDW.bestInlierNum < 8; rtDW.bestInlierNum++) {
      // MATLAB Function: '<S5>/MATLAB Function1'
      rtDW.pts1[rtDW.bestInlierNum] = tmp_0[rtDW.bestInlierNum];

      // MATLAB Function: '<S5>/MATLAB Function2'
      rtDW.pts2[rtDW.bestInlierNum] = tmp_1[rtDW.bestInlierNum];
    }

    // S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
    std::memset(&rtDW.EstimateGeometricTransformation[0], 0, 9U * sizeof(double));
    rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[0] = 0;
    rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[1] = 1;
    rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[2] = 2;
    rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[3] = 3;
    makeConstraintMatrix_Projective_D_D((const double *)&rtDW.pts1[0], (const
      double *)&rtDW.pts2[0], 4U, 4U,
      &rtDW.EstimateGeometricTransformation_DW_CONSTRT_ALL[0]);
    rtDW.svdRsltVar = 0;
    while (rtDW.svdRsltVar < 4) {
      rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[rtDW.svdRsltVar] =
        static_cast<uint32_t>
        (rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[rtDW.svdRsltVar]);
      rtDW.svdRsltVar++;
    }

    rtDW.bestCol = 0U;
    normPts_D_D((const double *)&rtDW.pts1[0], (const uint32_t *)
                &rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
                &rtDW.EstimateGeometricTransformation_DW_PTSNORM1[0],
                &rtDW.scale1, &rtDW.cents1[0]);
    normPts_D_D((const double *)&rtDW.pts2[0], (const uint32_t *)
                &rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
                &rtDW.EstimateGeometricTransformation_DW_PTSNORM2[0],
                &rtDW.scale2, &rtDW.cents2[0]);
    makeConstraintMatrix_Projective_D_D((const double *)
      &rtDW.EstimateGeometricTransformation_DW_PTSNORM1[0], (const double *)
      &rtDW.EstimateGeometricTransformation_DW_PTSNORM2[0], 4U, 4U,
      &rtDW.Constraint[0]);
    for (rtDW.inlierNum = 0; rtDW.inlierNum < 8; rtDW.inlierNum++) {
      rtDW.JPVT[static_cast<uint32_t>(rtDW.inlierNum)] = 0;
    }

    QRE_double_o(&rtDW.Q[0], &rtDW.Constraint[0], &rtDW.E[0], &rtDW.Qraux[0],
                 &rtDW.Work[0], &rtDW.JPVT[0], &rtDW.RV[0], 9, 8, true);
    rtDW.maxSum = 0.0;
    for (rtDW.inlierNum = 0; rtDW.inlierNum < 9; rtDW.inlierNum++) {
      for (rtDW.bestInlierNum = 0; rtDW.bestInlierNum < 9; rtDW.bestInlierNum++)
      {
        if (static_cast<uint32_t>(rtDW.inlierNum) != static_cast<uint32_t>
            (rtDW.bestInlierNum)) {
          rtDW.s1DivS2 = 0.0;
        } else {
          rtDW.s1DivS2 = -1.0;
        }

        for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 8; rtDW.svdRsltVar++) {
          rtDW.s1DivS2_tmp = static_cast<uint32_t>(rtDW.svdRsltVar) * 9U;
          rtDW.s1DivS2 += rtDW.Q[rtDW.s1DivS2_tmp + static_cast<uint32_t>
            (rtDW.inlierNum)] * rtDW.Q[rtDW.s1DivS2_tmp + static_cast<uint32_t>
            (rtDW.bestInlierNum)];
        }

        rtDW.RV[static_cast<uint32_t>(rtDW.inlierNum) * 9U +
          static_cast<uint32_t>(rtDW.bestInlierNum)] = rtDW.s1DivS2;
        if (!(rtDW.s1DivS2 >= 0.0)) {
          rtDW.s1DivS2 = -rtDW.s1DivS2;
        }

        if (rtDW.maxSum < rtDW.s1DivS2) {
          rtDW.maxSum = rtDW.s1DivS2;
          rtDW.bestCol = static_cast<uint32_t>(rtDW.inlierNum);
        }
      }
    }

    rtDW.bestInlierNum = static_cast<int32_t>(rtDW.bestCol * 9U);
    for (rtDW.inlierNum = 0; rtDW.inlierNum < 9; rtDW.inlierNum++) {
      rtDW.tformCompact[static_cast<uint32_t>(rtDW.inlierNum)] = rtDW.RV[
        static_cast<uint32_t>(rtDW.bestInlierNum) + static_cast<uint32_t>
        (rtDW.inlierNum)];
    }

    rtDW.maxSum = 1.0 / rtDW.scale2;
    rtDW.s1DivS2 = rtDW.scale1 * rtDW.maxSum;
    rtDW.tformCompact_m[6] = rtDW.tformCompact[6] * rtDW.scale1;
    rtDW.tformCompact_m[7] = rtDW.tformCompact[7] * rtDW.scale1;
    rtDW.tformCompact_m[8] = (rtDW.tformCompact[8] - rtDW.cents1[0] *
      rtDW.tformCompact_m[6]) - rtDW.cents1[1] * rtDW.tformCompact_m[7];
    rtDW.tformCompact_m[0] = rtDW.tformCompact[0] * rtDW.s1DivS2;
    rtDW.tformCompact_m[1] = rtDW.tformCompact[1] * rtDW.s1DivS2;
    rtDW.tformCompact_m[2] = ((rtDW.cents2[0] * rtDW.tformCompact_m[8] -
      rtDW.tformCompact_m[0] * rtDW.cents1[0]) - rtDW.tformCompact_m[1] *
      rtDW.cents1[1]) + rtDW.tformCompact[2] * rtDW.maxSum;
    rtDW.tformCompact_m[3] = rtDW.tformCompact[3] * rtDW.s1DivS2;
    rtDW.tformCompact_m[4] = rtDW.tformCompact[4] * rtDW.s1DivS2;
    rtDW.tformCompact_m[5] = ((rtDW.cents2[1] * rtDW.tformCompact_m[8] -
      rtDW.cents1[0] * rtDW.tformCompact_m[3]) - rtDW.cents1[1] *
      rtDW.tformCompact_m[4]) + rtDW.tformCompact[5] * rtDW.maxSum;
    rtDW.tformCompact_m[0] += rtDW.cents2[0] * rtDW.tformCompact_m[6];
    rtDW.tformCompact_m[1] += rtDW.cents2[0] * rtDW.tformCompact_m[7];
    rtDW.tformCompact_m[3] += rtDW.cents2[1] * rtDW.tformCompact_m[6];
    rtDW.tformCompact_m[4] += rtDW.cents2[1] * rtDW.tformCompact_m[7];
    if (rtDW.tformCompact_m[8U] != 0.0) {
      rtDW.maxSum = 1.0 / rtDW.tformCompact_m[8];
      for (rtDW.inlierNum = 0; rtDW.inlierNum < 8; rtDW.inlierNum++) {
        rtDW.tformCompact_m[static_cast<uint32_t>(rtDW.inlierNum)] *=
          rtDW.maxSum;
      }

      rtDW.tformCompact_m[8] = 1.0;
      rtDW.bestCol = 0U;
      for (rtDW.inlierNum = 0; rtDW.inlierNum < 4; rtDW.inlierNum++) {
        rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_t>
          (rtDW.inlierNum)] = 0.0;
        for (rtDW.bestInlierNum = 0; rtDW.bestInlierNum < 2; rtDW.bestInlierNum
             ++) {
          rtDW.maxSum = 0.0;
          for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 9; rtDW.svdRsltVar++) {
            rtDW.maxSum +=
              rtDW.EstimateGeometricTransformation_DW_CONSTRT_ALL[rtDW.bestCol +
              static_cast<uint32_t>(rtDW.svdRsltVar)] * rtDW.tformCompact_m[
              static_cast<uint32_t>(rtDW.svdRsltVar)];
          }

          rtDW.bestCol += 9U;
          rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_t>
            (rtDW.inlierNum)] += rtDW.maxSum * rtDW.maxSum;
        }
      }

      std::memcpy(&rtDW.bestTFormCompact[0], &rtDW.tformCompact_m[0], 9U *
                  sizeof(double));
      rtDW.bestInlierNum = 0;
      if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[0] <= 2.5) {
        rtDW.bestInlierNum = 1;
      }

      if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[1] <= 2.5) {
        rtDW.bestInlierNum = static_cast<int32_t>(static_cast<uint32_t>
          (rtDW.bestInlierNum) + 1U);
      }

      if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[2] <= 2.5) {
        rtDW.bestInlierNum = static_cast<int32_t>(static_cast<uint32_t>
          (rtDW.bestInlierNum) + 1U);
      }

      if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[3] <= 2.5) {
        rtDW.bestInlierNum = static_cast<int32_t>(static_cast<uint32_t>
          (rtDW.bestInlierNum) + 1U);
      }
    } else {
      rtDW.bestInlierNum = 0;
    }

    if (static_cast<uint32_t>(rtDW.bestInlierNum) >= 4U) {
      rtDW.EstimateGeometricTransformation[0] = rtDW.bestTFormCompact[4];
      rtDW.EstimateGeometricTransformation[1] = rtDW.bestTFormCompact[3];
      rtDW.EstimateGeometricTransformation[2] = rtDW.bestTFormCompact[5];
      rtDW.EstimateGeometricTransformation[3] = rtDW.bestTFormCompact[1];
      rtDW.EstimateGeometricTransformation[4] = rtDW.bestTFormCompact[0];
      rtDW.EstimateGeometricTransformation[5] = rtDW.bestTFormCompact[2];
      rtDW.EstimateGeometricTransformation[6] = rtDW.bestTFormCompact[7];
      rtDW.EstimateGeometricTransformation[7] = rtDW.bestTFormCompact[6];
      rtDW.EstimateGeometricTransformation[8] = rtDW.bestTFormCompact[8];
    }

    // End of S-Function (svipesttform): '<S5>/Estimate Geometric Transformation' 

    // MATLAB Function: '<S5>/MATLAB Function8'
    for (rtDW.bestInlierNum = 0; rtDW.bestInlierNum < 307200; rtDW.bestInlierNum
         ++) {
      rtDW.rtb_V_Channel_n[rtDW.bestInlierNum] =
        (rtDW.V_Channel[rtDW.bestInlierNum] > 0.5);
    }

    // End of MATLAB Function: '<S5>/MATLAB Function8'

    // MATLABSystem: '<S5>/Warp' incorporates:
    //   S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'

    Warp_stepImpl(&rtDW.obj_k, &rtDW.rtb_V_Channel_n[0],
                  &rtDW.EstimateGeometricTransformation[0], rtDW.unusedExpr);
  }

  // End of Outputs for SubSystem: '<Root>/Enabled Subsystem'
}

// Model initialize function
void Rpi_cam::initialize()
{
  {
    int32_t i;
    static const std::array<int8_t, 9> self_T{ { 1, 0, 0, 0, 1, 0, 0, 0, 1 } };

    // SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem'
    // Start for S-Function (svipesttform): '<S5>/Estimate Geometric Transformation' 
    srand(clock());

    // Start for MATLABSystem: '<S1>/V4L2 Video Capture'
    rtDW.obj.matlabCodegenIsDeleted = true;
    Raspiv4l2Capture_Raspiv4l2Capture(&rtDW.obj);
    rtDW.obj.Brightness = 0.5;
    rtDW.obj.Saturation = 0.5;
    rtDW.obj.Contrast = 0.5;
    rtDW.obj.Sharpness = 0.5;
    rtDW.obj.CameraPan = 0.0;
    rtDW.obj.CameraTilt = 0.0;
    rtDW.obj.CameraZoom = 0.5;
    rtDW.obj.ManualFocus = 0.5;
    SystemCore_setup(&rtDW.obj);

    // Start for MATLABSystem: '<S5>/Warp'
    rtDW.obj_k.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      rtDW.obj_k.TformProjective.T[i] = self_T[i];
    }

    // End of Start for MATLABSystem: '<S5>/Warp'
    // End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem'

    // Start for MATLABSystem: '<Root>/TCP//IP Receive'
    SystemCore_setup_o(&rtDW.obj_e);
  }
}

// Model terminate function
void Rpi_cam::terminate()
{
  // Terminate for Enabled SubSystem: '<Root>/Enabled Subsystem'
  // Terminate for MATLABSystem: '<S1>/V4L2 Video Capture'
  if (!rtDW.obj.matlabCodegenIsDeleted) {
    rtDW.obj.matlabCodegenIsDeleted = true;
    if ((rtDW.obj.isInitialized == 1) && rtDW.obj.isSetupComplete) {
      EXT_webcamTerminate(0, 0);
    }
  }

  // End of Terminate for MATLABSystem: '<S1>/V4L2 Video Capture'
  // End of Terminate for SubSystem: '<Root>/Enabled Subsystem'
}

// Constructor
Rpi_cam::Rpi_cam():
  rtDW()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Rpi_cam::~Rpi_cam() = default;
