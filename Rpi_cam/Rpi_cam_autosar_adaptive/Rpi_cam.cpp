//
//  Rpi_cam.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "Rpi_cam".
//
//  Model version              : 1.94
//  Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
//  C++ source code generated on : Tue Mar 12 16:09:41 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: Intel->x86-64 (Linux 64)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#include "Rpi_cam.h"
#include <stdbool.h>
#include <stdint.h>
#include <cstring>
#include "makeConstraintMatrix_Projective_D_D.h"
#include "normPts_D_D.h"
#include <array>
#include <emmintrin.h>
#include <cmath>
#include "QRSL1_double.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

// Skipping ulong/long check: insufficient preprocessor integer range.

// Skipping ulong_long/long_long check: insufficient preprocessor integer range. 
void Rpi_cam::v4l2Capture_updateV4L2Settings
  (codertarget_raspi_internal_Raspiv4l2Capture *obj, bool forceUpdate)
{
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

  std::array<char, 11> b;
  std::array<char, 9> c;
  std::array<char, 10> e;
  std::array<char, 12> j;
  uint8_t status;

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
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
      rtDW.i_f[i] = i_0[i];
    }

    EXT_updateV4L2Control(&rtDW.i_f[0], 1.0F, 0, &status);
  }

  if ((obj->ManualFocus != obj->ManualFocusInternal) || forceUpdate) {
    obj->ManualFocusInternal = obj->ManualFocus;
    for (int32_t i{0}; i < 12; i++) {
      j[i] = j_0[i];
    }

    EXT_updateV4L2Control(&j[0], static_cast<float>(obj->ManualFocus), 0,
                          &status);
  }

  // End of Start for MATLABSystem: '<Root>/V4L2 Video Capture'
}

void Rpi_cam::SystemCore_step(codertarget_raspi_internal_Raspiv4l2Capture *obj,
  uint8_t varargout_1[307200], uint8_t varargout_2[307200], uint8_t varargout_3
  [307200])
{
  double ts;

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  v4l2Capture_updateV4L2Settings(obj, false);
  EXT_webcamReadFrame(0, &ts, &varargout_1[0], &varargout_2[0], &varargout_3[0]);
}

void Rpi_cam::QRV2Norm_double_o(const double V[], int32_t N, double v2norm[])
{
  int32_t vi;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

void Rpi_cam::QRE_double_o(double outQ[], double outR[], double outE[], double
  qrAux[], double work[], int32_t jpvt[], double sPtr[], int32_t M, int32_t N,
  bool economy)
{
  int32_t L;
  int32_t L_tmp;
  int32_t ps;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  QRDC_double_o(&outR[0], &qrAux[0], &jpvt[0], &work[0], M, N);

  // explicitly form q by manipulating identity
  if (economy) {
    if (M <= N) {
      L = M;
    } else {
      L = N;
    }
  } else {
    L = M;
  }

  L_tmp = 0;
  rtDW.j_i = 0;
  while (rtDW.j_i < M * L) {
    outQ[rtDW.j_i] = 0.0;
    rtDW.j_i++;
  }

  rtDW.j_i = 0;
  while (rtDW.j_i < L) {
    outQ[L_tmp] = 1.0;
    L_tmp = (L_tmp + M) + 1;
    rtDW.j_i++;
  }

  // Convert cols of identity into cols of q. Use info stored in lower triangle of r and in vector qraux to work on columns of identity matrix I and transform them into q*I(:,j) i.e. the columns of q. 
  L_tmp = 0;
  rtDW.j_i = 0;
  while (rtDW.j_i < L) {
    QRSL1_double(&outR[0], &qrAux[0], &outQ[L_tmp], M, N);
    L_tmp += M;
    rtDW.j_i++;
  }

  if (economy && (M > N)) {
    // Copy upper triangle of r to s
    L = 0;
    ps = 0;
    rtDW.j_i = 1;
    while (rtDW.j_i - 1 < N) {
      for (L_tmp = 0; L_tmp < rtDW.j_i; L_tmp++) {
        sPtr[ps] = outR[L];
        ps++;
        L++;
      }

      L = (L + M) - rtDW.j_i;
      for (L_tmp = 0; L_tmp < N - rtDW.j_i; L_tmp++) {
        sPtr[ps] = 0.0;
        ps++;
      }

      rtDW.j_i++;
    }
  } else {
    // Zero strict lower triangle of r
    L = M * N - 1;
    rtDW.j_i = N;
    while (rtDW.j_i - 1 >= 0) {
      for (L_tmp = M; L_tmp > rtDW.j_i; L_tmp--) {
        outR[L] = 0.0;
        L--;
      }

      if (M < rtDW.j_i) {
        L -= M;
      } else {
        L -= rtDW.j_i;
      }

      rtDW.j_i--;
    }
  }

  // form permutation vector e
  L = 0;
  L_tmp = 0;
  rtDW.j_i = 0;
  while (rtDW.j_i < N) {
    outE[L] = jpvt[L_tmp] + 1;
    L_tmp = L + 1;
    L++;
    rtDW.j_i++;
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}

void Rpi_cam::Warp_stepImpl(vision_internal_blocks_Warp *b_this, const bool
  Image[307200], const double input2[9], bool Jout[307200])
{
  __m128d tmp_0;
  __m128d tmp_1;
  std::array<bool, 2> x;
  int32_t p2;
  int32_t p3;
  bool guard1;

  // Start for MATLABSystem: '<S4>/Warp'
  std::memcpy(&b_this->TformProjective.T[0], &input2[0], 9U * sizeof(double));
  for (rtDW.p1 = 0; rtDW.p1 < 3; rtDW.p1++) {
    rtDW.B_c[3 * rtDW.p1] = b_this->TformProjective.T[rtDW.p1];
    rtDW.B_c[3 * rtDW.p1 + 1] = b_this->TformProjective.T[rtDW.p1 + 3];
    rtDW.B_c[3 * rtDW.p1 + 2] = b_this->TformProjective.T[rtDW.p1 + 6];
  }

  for (rtDW.p1 = 0; rtDW.p1 < 640; rtDW.p1++) {
    for (p2 = 0; p2 < 480; p2++) {
      p3 = 480 * rtDW.p1 + p2;

      // Start for MATLABSystem: '<S4>/Warp'
      rtDW.xp[p3] = static_cast<double>(rtDW.p1) + 1.0;
      rtDW.yp[p3] = static_cast<double>(p2) + 1.0;
    }
  }

  for (rtDW.p1 = 0; rtDW.p1 <= 307198; rtDW.p1 += 2) {
    // Start for MATLABSystem: '<S4>/Warp'
    tmp_0 = _mm_loadu_pd(&rtDW.xp[rtDW.p1]);
    tmp_1 = _mm_set1_pd(0.5);

    // Start for MATLABSystem: '<S4>/Warp'
    _mm_storeu_pd(&rtDW.xp[rtDW.p1], _mm_add_pd(_mm_sub_pd(tmp_0, tmp_1), tmp_1));
    tmp_0 = _mm_loadu_pd(&rtDW.yp[rtDW.p1]);
    _mm_storeu_pd(&rtDW.yp[rtDW.p1], _mm_add_pd(_mm_sub_pd(tmp_0, tmp_1), tmp_1));
  }

  // Start for MATLABSystem: '<S4>/Warp'
  guard1 = false;
  if (rtDW.B_c[8] == 1.0) {
    bool exitg1;
    bool y;
    x[0] = (rtDW.B_c[2] == 0.0);
    x[1] = (rtDW.B_c[5] == 0.0);
    y = true;
    rtDW.p1 = 0;
    exitg1 = false;
    while ((!exitg1) && (rtDW.p1 < 2)) {
      if (!x[rtDW.p1]) {
        y = false;
        exitg1 = true;
      } else {
        rtDW.p1++;
      }
    }

    if (y) {
      if (std::abs(rtDW.B_c[1]) > std::abs(rtDW.B_c[0])) {
        rtDW.absx11 = rtDW.B_c[0] / rtDW.B_c[1];
        rtDW.absx21 = 1.0 / (rtDW.absx11 * rtDW.B_c[4] - rtDW.B_c[3]);
        rtDW.b_B_idx_0 = rtDW.B_c[4] / rtDW.B_c[1] * rtDW.absx21;
        rtDW.b_B_idx_1 = -rtDW.absx21;
        rtDW.b_B_idx_2 = -rtDW.B_c[3] / rtDW.B_c[1] * rtDW.absx21;
        rtDW.absx21 *= rtDW.absx11;
      } else {
        rtDW.absx11 = rtDW.B_c[1] / rtDW.B_c[0];
        rtDW.absx21 = 1.0 / (rtDW.B_c[4] - rtDW.absx11 * rtDW.B_c[3]);
        rtDW.b_B_idx_0 = rtDW.B_c[4] / rtDW.B_c[0] * rtDW.absx21;
        rtDW.b_B_idx_1 = -rtDW.absx11 * rtDW.absx21;
        rtDW.b_B_idx_2 = -rtDW.B_c[3] / rtDW.B_c[0] * rtDW.absx21;
      }

      rtDW.absx11 = rtDW.B_c[6];
      rtDW.absx31 = rtDW.B_c[7];
      for (rtDW.p1 = 0; rtDW.p1 <= 307198; rtDW.p1 += 2) {
        tmp_0 = _mm_loadu_pd(&rtDW.xp[rtDW.p1]);
        tmp_0 = _mm_sub_pd(tmp_0, _mm_set1_pd(rtDW.absx11));
        tmp_1 = _mm_loadu_pd(&rtDW.yp[rtDW.p1]);
        tmp_1 = _mm_sub_pd(tmp_1, _mm_set1_pd(rtDW.absx31));
        _mm_storeu_pd(&rtDW.yp[rtDW.p1], tmp_1);
        _mm_storeu_pd(&rtDW.b_varargout_1[rtDW.p1], _mm_add_pd(_mm_mul_pd
          (_mm_set1_pd(rtDW.b_B_idx_0), tmp_0), _mm_mul_pd(_mm_set1_pd
          (rtDW.b_B_idx_2), tmp_1)));
        _mm_storeu_pd(&rtDW.xp[rtDW.p1], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
          (rtDW.b_B_idx_1), tmp_0), _mm_mul_pd(_mm_set1_pd(rtDW.absx21), tmp_1)));
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    std::memcpy(&rtDW.x[0], &rtDW.B_c[0], 9U * sizeof(double));
    rtDW.p1 = 1;
    p2 = 3;
    p3 = 6;
    rtDW.absx11 = std::abs(rtDW.B_c[0]);
    rtDW.absx21 = std::abs(rtDW.B_c[1]);
    rtDW.absx31 = std::abs(rtDW.B_c[2]);
    if ((rtDW.absx21 > rtDW.absx11) && (rtDW.absx21 > rtDW.absx31)) {
      rtDW.p1 = 4;
      p2 = 0;
      rtDW.x[0] = rtDW.B_c[1];
      rtDW.x[1] = rtDW.B_c[0];
      rtDW.x[3] = rtDW.B_c[4];
      rtDW.x[4] = rtDW.B_c[3];
      rtDW.x[6] = rtDW.B_c[7];
      rtDW.x[7] = rtDW.B_c[6];
    } else if (rtDW.absx31 > rtDW.absx11) {
      rtDW.p1 = 7;
      p3 = 0;
      rtDW.x[0] = rtDW.B_c[2];
      rtDW.x[2] = rtDW.B_c[0];
      rtDW.x[3] = rtDW.B_c[5];
      rtDW.x[5] = rtDW.B_c[3];
      rtDW.x[6] = rtDW.B_c[8];
      rtDW.x[8] = rtDW.B_c[6];
    }

    rtDW.absx31 = rtDW.x[1] / rtDW.x[0];
    rtDW.x[1] = rtDW.absx31;
    rtDW.absx11 = rtDW.x[2] / rtDW.x[0];
    rtDW.x[2] = rtDW.absx11;
    rtDW.x[4] -= rtDW.absx31 * rtDW.x[3];
    rtDW.x[5] -= rtDW.absx11 * rtDW.x[3];
    rtDW.x[7] -= rtDW.absx31 * rtDW.x[6];
    rtDW.x[8] -= rtDW.absx11 * rtDW.x[6];
    if (std::abs(rtDW.x[5]) > std::abs(rtDW.x[4])) {
      int32_t itmp;
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
    rtDW.absx11 = (rtDW.x[1] * rtDW.absx31 - rtDW.x[2]) / rtDW.x[8];
    rtDW.absx21 = -(rtDW.x[7] * rtDW.absx11 + rtDW.x[1]) / rtDW.x[4];
    rtDW.B_c[rtDW.p1 - 1] = ((1.0 - rtDW.x[3] * rtDW.absx21) - rtDW.x[6] *
      rtDW.absx11) / rtDW.x[0];
    rtDW.B_c[rtDW.p1] = rtDW.absx21;
    rtDW.B_c[rtDW.p1 + 1] = rtDW.absx11;
    rtDW.absx11 = -rtDW.absx31 / rtDW.x[8];
    rtDW.absx21 = (1.0 - rtDW.x[7] * rtDW.absx11) / rtDW.x[4];
    rtDW.B_c[p2] = -(rtDW.x[3] * rtDW.absx21 + rtDW.x[6] * rtDW.absx11) /
      rtDW.x[0];
    rtDW.B_c[p2 + 1] = rtDW.absx21;
    rtDW.B_c[p2 + 2] = rtDW.absx11;
    rtDW.absx11 = 1.0 / rtDW.x[8];
    rtDW.absx21 = -rtDW.x[7] * rtDW.absx11 / rtDW.x[4];
    rtDW.B_c[p3] = -(rtDW.x[3] * rtDW.absx21 + rtDW.x[6] * rtDW.absx11) /
      rtDW.x[0];
    rtDW.B_c[p3 + 1] = rtDW.absx21;
    rtDW.B_c[p3 + 2] = rtDW.absx11;
    rtDW.absx11 = rtDW.B_c[2];
    rtDW.absx31 = rtDW.B_c[5];
    rtDW.absx21 = rtDW.B_c[0];
    rtDW.b_B_idx_0 = rtDW.B_c[3];
    rtDW.b_B_idx_1 = rtDW.B_c[1];
    rtDW.b_B_idx_2 = rtDW.B_c[4];
    rtDW.B_f = rtDW.B_c[8];
    rtDW.B_g = rtDW.B_c[6];
    rtDW.B_g1 = rtDW.B_c[7];
    for (rtDW.p1 = 0; rtDW.p1 <= 307198; rtDW.p1 += 2) {
      __m128d tmp;
      tmp_0 = _mm_loadu_pd(&rtDW.xp[rtDW.p1]);
      tmp_1 = _mm_loadu_pd(&rtDW.yp[rtDW.p1]);
      tmp = _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd(rtDW.absx11), tmp_0),
        _mm_mul_pd(_mm_set1_pd(rtDW.absx31), tmp_1)), _mm_set1_pd(rtDW.B_f));
      _mm_storeu_pd(&rtDW.b_varargout_1[rtDW.p1], _mm_div_pd(_mm_add_pd
        (_mm_add_pd(_mm_mul_pd(_mm_set1_pd(rtDW.absx21), tmp_0), _mm_mul_pd
                    (_mm_set1_pd(rtDW.b_B_idx_0), tmp_1)), _mm_set1_pd(rtDW.B_g)),
        tmp));
      _mm_storeu_pd(&rtDW.xp[rtDW.p1], _mm_div_pd(_mm_add_pd(_mm_add_pd
        (_mm_mul_pd(_mm_set1_pd(rtDW.b_B_idx_1), tmp_0), _mm_mul_pd(_mm_set1_pd
        (rtDW.b_B_idx_2), tmp_1)), _mm_set1_pd(rtDW.B_g1)), tmp));
    }
  }

  for (rtDW.p1 = 0; rtDW.p1 < 307200; rtDW.p1++) {
    // Start for MATLABSystem: '<S4>/Warp'
    rtDW.b_varargout_1[rtDW.p1] = (rtDW.b_varargout_1[rtDW.p1] - 0.5) + 0.5;
    rtDW.xp[rtDW.p1] = (rtDW.xp[rtDW.p1] - 0.5) + 0.5;
    rtDW.inputImage_[rtDW.p1] = Image[rtDW.p1];
  }

  uint8_t fillValues;
  fillValues = 0U;

  // Start for MATLABSystem: '<S4>/Warp'
  rtDW.b_inputImageSize[0] = 480.0;
  rtDW.b_inputImageSize[1] = 640.0;
  rtDW.b_inputImageSize[2] = 1.0;
  rtDW.b_outputImageSize[0] = 480.0;
  rtDW.b_outputImageSize[1] = 640.0;
  imterp2d64f_uint8(&rtDW.inputImage_[0], &rtDW.b_inputImageSize[0], &rtDW.xp[0],
                    &rtDW.b_varargout_1[0], &rtDW.b_outputImageSize[0], 2.0,
                    true, &fillValues, &rtDW.outputImage_o[0]);
  for (rtDW.p1 = 0; rtDW.p1 < 307200; rtDW.p1++) {
    // Start for MATLABSystem: '<S4>/Warp'
    Jout[rtDW.p1] = (rtDW.outputImage_o[rtDW.p1] > 0.5);
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
void Rpi_cam::eml_find(const bool x[307200], int32_t i_data[], int32_t *i_size,
  int32_t j_data[], int32_t *j_size)
{
  int32_t idx;
  int32_t ii;
  int32_t jj;
  bool exitg1;
  idx = 0;
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 640)) {
    bool guard1;
    guard1 = false;
    if (x[((jj - 1) * 480 + ii) - 1]) {
      idx++;
      i_data[idx - 1] = ii;
      j_data[idx - 1] = jj;
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
    *i_size = 0;
    *j_size = 0;
  } else {
    *i_size = idx;
    *j_size = idx;
  }
}

void Rpi_cam::binary_expand_op_5(bool in1_data[], int32_t *in1_size, const bool
  in2_data[], const int32_t *in2_size, const int32_t in3_data[], const int32_t
  *in3_size)
{
  int32_t loop_ub;
  int32_t stride_0_0;
  int32_t stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (*in3_size == 1) {
    *in1_size = *in2_size;
  } else {
    *in1_size = *in3_size;
  }

  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (*in3_size != 1);
  if (*in3_size == 1) {
    loop_ub = *in2_size;
  } else {
    loop_ub = *in3_size;
  }

  for (int32_t i{0}; i < loop_ub; i++) {
    in1_data[i] = (in2_data[i * stride_0_0] && (in3_data[i * stride_1_0] >= 0));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

void Rpi_cam::binary_expand_op_4(bool in1_data[], int32_t *in1_size, const
  int32_t in2_data[], const int32_t *in2_size)
{
  int32_t in1_size_idx_0;
  int32_t stride_0_0;
  int32_t stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (*in2_size == 1) {
    in1_size_idx_0 = *in1_size;
  } else {
    in1_size_idx_0 = *in2_size;
  }

  stride_0_0 = (*in1_size != 1);
  stride_1_0 = (*in2_size != 1);
  if (*in2_size == 1) {
  } else {
    *in1_size = *in2_size;
  }

  for (int32_t i{0}; i < *in1_size; i++) {
    rtDW.in1_data_b[i] = (in1_data[i * stride_0_0] && (in2_data[i * stride_1_0] >=
      480));
  }

  *in1_size = in1_size_idx_0;
  if (in1_size_idx_0 - 1 >= 0) {
    std::memcpy(&in1_data[0], &rtDW.in1_data_b[0], static_cast<uint32_t>
                (in1_size_idx_0) * sizeof(bool));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

void Rpi_cam::and_o(bool in1_data[], int32_t *in1_size, const bool in2_data[],
                    const int32_t *in2_size, const bool in3_data[], const
                    int32_t *in3_size)
{
  int32_t loop_ub;
  int32_t stride_0_0;
  int32_t stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (*in3_size == 1) {
    *in1_size = *in2_size;
  } else {
    *in1_size = *in3_size;
  }

  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (*in3_size != 1);
  if (*in3_size == 1) {
    loop_ub = *in2_size;
  } else {
    loop_ub = *in3_size;
  }

  for (int32_t i{0}; i < loop_ub; i++) {
    in1_data[i] = (in2_data[i * stride_0_0] && in3_data[i * stride_1_0]);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
double Rpi_cam::mean(const double x_data[], const int32_t *x_size)
{
  double b_y;
  if (*x_size == 0) {
    b_y = 0.0;
  } else {
    int32_t firstBlockLength;
    int32_t lastBlockLength;
    int32_t nblocks;
    int32_t xblockoffset;
    if (*x_size <= 1024) {
      firstBlockLength = *x_size;
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = static_cast<int32_t>(static_cast<uint32_t>(*x_size) >> 10);
      lastBlockLength = *x_size - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }

    b_y = x_data[0];
    for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++) {
      b_y += x_data[xblockoffset - 1];
    }

    for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++)
    {
      double bsum;
      int32_t hi;
      xblockoffset = (firstBlockLength - 1) << 10;
      bsum = x_data[xblockoffset];
      if (firstBlockLength == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }

      for (int32_t b_k{2}; b_k <= hi; b_k++) {
        bsum += x_data[(xblockoffset + b_k) - 1];
      }

      b_y += bsum;
    }
  }

  return b_y / static_cast<double>(*x_size);
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
double Rpi_cam::maximum(const double x_data[], const int32_t *x_size)
{
  double ex;
  int32_t last;
  last = *x_size;
  if (*x_size <= 2) {
    if (*x_size == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[*x_size - 1];
      if (!(x_data[0] < ex)) {
        ex = x_data[0];
      }
    }
  } else {
    ex = x_data[0];
    for (int32_t k{2}; k <= last; k++) {
      double x;
      x = x_data[k - 1];
      if (ex < x) {
        ex = x;
      }
    }
  }

  return ex;
}

void Rpi_cam::binary_expand_op_1(bool in1_data[], int32_t *in1_size, const bool
  in2_data[], const int32_t *in2_size, const bool in3_data[], const bool
  in4_data[], const int32_t *in4_size)
{
  int32_t loop_ub;
  int32_t stride_0_0;
  int32_t stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (*in4_size == 1) {
    *in1_size = *in2_size;
  } else {
    *in1_size = *in4_size;
  }

  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (*in4_size != 1);
  if (*in4_size == 1) {
    loop_ub = *in2_size;
  } else {
    loop_ub = *in4_size;
  }

  for (int32_t i{0}; i < loop_ub; i++) {
    int32_t tmp;
    tmp = i * stride_0_0;
    in1_data[i] = (in2_data[tmp] && in3_data[tmp] && in4_data[i * stride_1_0]);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

void Rpi_cam::binary_expand_op(bool in1_data[], int32_t *in1_size, const bool
  in2_data[], const bool in3_data[], const int32_t *in3_size)
{
  int32_t in1_size_idx_0;
  int32_t stride_0_0;
  int32_t stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (*in3_size == 1) {
    in1_size_idx_0 = *in1_size;
  } else {
    in1_size_idx_0 = *in3_size;
  }

  stride_0_0 = (*in1_size != 1);
  stride_1_0 = (*in3_size != 1);
  if (*in3_size == 1) {
  } else {
    *in1_size = *in3_size;
  }

  for (int32_t i{0}; i < *in1_size; i++) {
    int32_t in1_tmp;
    in1_tmp = i * stride_0_0;
    rtDW.in1_data[i] = (in1_data[in1_tmp] && in2_data[in1_tmp] && in3_data[i *
                        stride_1_0]);
  }

  *in1_size = in1_size_idx_0;
  if (in1_size_idx_0 - 1 >= 0) {
    std::memcpy(&in1_data[0], &rtDW.in1_data[0], static_cast<uint32_t>
                (in1_size_idx_0) * sizeof(bool));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
double Rpi_cam::xnrm2(int32_t n, const double x_data[], int32_t ix0)
{
  double y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x_data[ix0 - 1]);
    } else {
      rtDW.scale = 3.3121686421112381E-170;
      rtDW.kend = (ix0 + n) - 1;
      for (rtDW.k_f = ix0; rtDW.k_f <= rtDW.kend; rtDW.k_f++) {
        rtDW.absxk = std::abs(x_data[rtDW.k_f - 1]);
        if (rtDW.absxk > rtDW.scale) {
          rtDW.t_m = rtDW.scale / rtDW.absxk;
          y = y * rtDW.t_m * rtDW.t_m + 1.0;
          rtDW.scale = rtDW.absxk;
        } else {
          rtDW.t_m = rtDW.absxk / rtDW.scale;
          y += rtDW.t_m * rtDW.t_m;
        }
      }

      y = rtDW.scale * std::sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
void Rpi_cam::xswap(int32_t n, double x_data[], int32_t ix0, int32_t iy0)
{
  for (rtDW.k_i = 0; rtDW.k_i < n; rtDW.k_i++) {
    rtDW.temp_tmp = (ix0 + rtDW.k_i) - 1;
    rtDW.temp = x_data[rtDW.temp_tmp];
    rtDW.i1 = (iy0 + rtDW.k_i) - 1;
    x_data[rtDW.temp_tmp] = x_data[rtDW.i1];
    x_data[rtDW.i1] = rtDW.temp;
  }
}

double Rpi_cam::rt_hypotd_snf_o(double u0, double u1)
{
  double y;
  rtDW.a = std::abs(u0);
  rtDW.b = std::abs(u1);
  if (rtDW.a < rtDW.b) {
    rtDW.a /= rtDW.b;
    y = std::sqrt(rtDW.a * rtDW.a + 1.0) * rtDW.b;
  } else if (rtDW.a > rtDW.b) {
    rtDW.b /= rtDW.a;
    y = std::sqrt(rtDW.b * rtDW.b + 1.0) * rtDW.a;
  } else if (std::isnan(rtDW.b)) {
    y = (rtNaN);
  } else {
    y = rtDW.a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
void Rpi_cam::xzlarf(int32_t m, int32_t n, int32_t iv0, double tau, double
                     C_data[], int32_t ic0, int32_t ldc, double work[3])
{
  if (tau != 0.0) {
    bool exitg2;
    rtDW.lastv = m;
    rtDW.i_o = iv0 + m;
    while ((rtDW.lastv > 0) && (C_data[rtDW.i_o - 2] == 0.0)) {
      rtDW.lastv--;
      rtDW.i_o--;
    }

    rtDW.lastc = n;
    exitg2 = false;
    while ((!exitg2) && (rtDW.lastc > 0)) {
      int32_t exitg1;
      rtDW.i_o = (rtDW.lastc - 1) * ldc + ic0;
      rtDW.jA = rtDW.i_o;
      do {
        exitg1 = 0;
        if (rtDW.jA <= (rtDW.i_o + rtDW.lastv) - 1) {
          if (C_data[rtDW.jA - 1] != 0.0) {
            exitg1 = 1;
          } else {
            rtDW.jA++;
          }
        } else {
          rtDW.lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    rtDW.lastv = 0;
    rtDW.lastc = 0;
  }

  if (rtDW.lastv > 0) {
    if (rtDW.lastc != 0) {
      rtDW.jA = static_cast<uint8_t>(rtDW.lastc);
      std::memset(&work[0], 0, static_cast<uint32_t>(rtDW.jA) * sizeof(double));
      rtDW.jy = 0;
      rtDW.d_o = (rtDW.lastc - 1) * ldc + ic0;
      for (rtDW.i_o = ic0; ldc < 0 ? rtDW.i_o >= rtDW.d_o : rtDW.i_o <= rtDW.d_o;
           rtDW.i_o += ldc) {
        rtDW.c = 0.0;
        rtDW.e = (rtDW.i_o + rtDW.lastv) - 1;
        for (rtDW.jA = rtDW.i_o; rtDW.jA <= rtDW.e; rtDW.jA++) {
          rtDW.c += C_data[((iv0 + rtDW.jA) - rtDW.i_o) - 1] * C_data[rtDW.jA -
            1];
        }

        work[rtDW.jy] += rtDW.c;
        rtDW.jy++;
      }
    }

    if (!(-tau == 0.0)) {
      rtDW.jA = ic0;
      rtDW.d_o = static_cast<uint8_t>(rtDW.lastc);
      for (rtDW.lastc = 0; rtDW.lastc < rtDW.d_o; rtDW.lastc++) {
        rtDW.c = work[rtDW.lastc];
        if (rtDW.c != 0.0) {
          rtDW.c *= -tau;
          rtDW.e = rtDW.lastv + rtDW.jA;
          for (rtDW.i_o = rtDW.jA; rtDW.i_o < rtDW.e; rtDW.i_o++) {
            C_data[rtDW.i_o - 1] += C_data[((iv0 + rtDW.i_o) - rtDW.jA) - 1] *
              rtDW.c;
          }
        }

        rtDW.jA += ldc;
      }
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
void Rpi_cam::qrpf(double A_data[], const int32_t A_size[2], int32_t m, double
                   tau_data[], int32_t jpvt[3])
{
  __m128d tmp;
  rtDW.ma = A_size[0];
  rtDW.work[0] = 0.0;
  rtDW.vn1_c = xnrm2(m, A_data, 1);
  rtDW.vn1[0] = rtDW.vn1_c;
  rtDW.vn2[0] = rtDW.vn1_c;
  rtDW.work[1] = 0.0;
  rtDW.vn1_c = xnrm2(m, A_data, A_size[0] + 1);
  rtDW.vn1[1] = rtDW.vn1_c;
  rtDW.vn2[1] = rtDW.vn1_c;
  rtDW.work[2] = 0.0;
  rtDW.vn1_c = xnrm2(m, A_data, (A_size[0] << 1) + 1);
  rtDW.vn1[2] = rtDW.vn1_c;
  rtDW.vn2[2] = rtDW.vn1_c;
  if (m <= 3) {
    rtDW.b_i = static_cast<uint8_t>(m);
  } else {
    rtDW.b_i = 3;
  }

  for (rtDW.j_a = 0; rtDW.j_a < rtDW.b_i; rtDW.j_a++) {
    rtDW.ix = rtDW.j_a * rtDW.ma;
    rtDW.ii = rtDW.ix + rtDW.j_a;
    rtDW.mmi = m - rtDW.j_a;
    rtDW.itemp = 3 - rtDW.j_a;
    rtDW.knt = 0;
    if (3 - rtDW.j_a > 1) {
      rtDW.smax = std::abs(rtDW.vn1[rtDW.j_a]);
      for (rtDW.pvt = 2; rtDW.pvt <= rtDW.itemp; rtDW.pvt++) {
        rtDW.s = std::abs(rtDW.vn1[(rtDW.j_a + rtDW.pvt) - 1]);
        if (rtDW.s > rtDW.smax) {
          rtDW.knt = rtDW.pvt - 1;
          rtDW.smax = rtDW.s;
        }
      }
    }

    rtDW.pvt = rtDW.j_a + rtDW.knt;
    if (rtDW.pvt != rtDW.j_a) {
      xswap(m, A_data, rtDW.pvt * rtDW.ma + 1, rtDW.ix + 1);
      rtDW.itemp = jpvt[rtDW.pvt];
      jpvt[rtDW.pvt] = jpvt[rtDW.j_a];
      jpvt[rtDW.j_a] = rtDW.itemp;
      rtDW.vn1[rtDW.pvt] = rtDW.vn1[rtDW.j_a];
      rtDW.vn2[rtDW.pvt] = rtDW.vn2[rtDW.j_a];
    }

    if (rtDW.j_a + 1 < m) {
      rtDW.s = A_data[rtDW.ii];
      rtDW.pvt = rtDW.ii + 2;
      tau_data[rtDW.j_a] = 0.0;
      if (rtDW.mmi > 0) {
        rtDW.vn1_c = xnrm2(rtDW.mmi - 1, A_data, rtDW.ii + 2);
        if (rtDW.vn1_c != 0.0) {
          rtDW.smax = rt_hypotd_snf_o(A_data[rtDW.ii], rtDW.vn1_c);
          if (A_data[rtDW.ii] >= 0.0) {
            rtDW.smax = -rtDW.smax;
          }

          if (std::abs(rtDW.smax) < 1.0020841800044864E-292) {
            rtDW.knt = 0;
            rtDW.itemp = rtDW.ii + rtDW.mmi;
            do {
              rtDW.knt++;
              rtDW.vectorUB_l = (((((rtDW.itemp - rtDW.ii) - 1) / 2) << 1) +
                                 rtDW.ii) + 2;
              rtDW.vectorUB_tmp = rtDW.vectorUB_l - 2;
              for (rtDW.ix = rtDW.pvt; rtDW.ix <= rtDW.vectorUB_tmp; rtDW.ix +=
                   2) {
                tmp = _mm_loadu_pd(&A_data[rtDW.ix - 1]);
                _mm_storeu_pd(&A_data[rtDW.ix - 1], _mm_mul_pd(tmp, _mm_set1_pd
                  (9.9792015476736E+291)));
              }

              for (rtDW.ix = rtDW.vectorUB_l; rtDW.ix <= rtDW.itemp; rtDW.ix++)
              {
                A_data[rtDW.ix - 1] *= 9.9792015476736E+291;
              }

              rtDW.smax *= 9.9792015476736E+291;
              rtDW.s *= 9.9792015476736E+291;
            } while ((std::abs(rtDW.smax) < 1.0020841800044864E-292) &&
                     (rtDW.knt < 20));

            rtDW.smax = rt_hypotd_snf_o(rtDW.s, xnrm2(rtDW.mmi - 1, A_data,
              rtDW.ii + 2));
            if (rtDW.s >= 0.0) {
              rtDW.smax = -rtDW.smax;
            }

            tau_data[rtDW.j_a] = (rtDW.smax - rtDW.s) / rtDW.smax;
            rtDW.s = 1.0 / (rtDW.s - rtDW.smax);
            for (rtDW.ix = rtDW.pvt; rtDW.ix <= rtDW.vectorUB_tmp; rtDW.ix += 2)
            {
              tmp = _mm_loadu_pd(&A_data[rtDW.ix - 1]);
              _mm_storeu_pd(&A_data[rtDW.ix - 1], _mm_mul_pd(tmp, _mm_set1_pd
                (rtDW.s)));
            }

            for (rtDW.ix = rtDW.vectorUB_l; rtDW.ix <= rtDW.itemp; rtDW.ix++) {
              A_data[rtDW.ix - 1] *= rtDW.s;
            }

            for (rtDW.pvt = 0; rtDW.pvt < rtDW.knt; rtDW.pvt++) {
              rtDW.smax *= 1.0020841800044864E-292;
            }

            rtDW.s = rtDW.smax;
          } else {
            tau_data[rtDW.j_a] = (rtDW.smax - A_data[rtDW.ii]) / rtDW.smax;
            rtDW.s = 1.0 / (A_data[rtDW.ii] - rtDW.smax);
            rtDW.ix = rtDW.ii + rtDW.mmi;
            rtDW.itemp = (((((rtDW.ix - rtDW.ii) - 1) / 2) << 1) + rtDW.ii) + 2;
            rtDW.vectorUB_l = rtDW.itemp - 2;
            for (rtDW.knt = rtDW.pvt; rtDW.knt <= rtDW.vectorUB_l; rtDW.knt += 2)
            {
              tmp = _mm_loadu_pd(&A_data[rtDW.knt - 1]);
              _mm_storeu_pd(&A_data[rtDW.knt - 1], _mm_mul_pd(tmp, _mm_set1_pd
                (rtDW.s)));
            }

            for (rtDW.knt = rtDW.itemp; rtDW.knt <= rtDW.ix; rtDW.knt++) {
              A_data[rtDW.knt - 1] *= rtDW.s;
            }

            rtDW.s = rtDW.smax;
          }
        }
      }

      A_data[rtDW.ii] = rtDW.s;
    } else {
      tau_data[rtDW.j_a] = 0.0;
    }

    if (rtDW.j_a + 1 < 3) {
      rtDW.smax = A_data[rtDW.ii];
      A_data[rtDW.ii] = 1.0;
      xzlarf(rtDW.mmi, 2 - rtDW.j_a, rtDW.ii + 1, tau_data[rtDW.j_a], A_data,
             (rtDW.ii + rtDW.ma) + 1, rtDW.ma, &rtDW.work[0]);
      A_data[rtDW.ii] = rtDW.smax;
    }

    for (rtDW.ii = rtDW.j_a + 2; rtDW.ii < 4; rtDW.ii++) {
      rtDW.pvt = (rtDW.ii - 1) * rtDW.ma + rtDW.j_a;
      rtDW.vn1_c = rtDW.vn1[rtDW.ii - 1];
      if (rtDW.vn1_c != 0.0) {
        rtDW.smax = std::abs(A_data[rtDW.pvt]) / rtDW.vn1_c;
        rtDW.smax = 1.0 - rtDW.smax * rtDW.smax;
        if (rtDW.smax < 0.0) {
          rtDW.smax = 0.0;
        }

        rtDW.s = rtDW.vn1_c / rtDW.vn2[rtDW.ii - 1];
        rtDW.s = rtDW.s * rtDW.s * rtDW.smax;
        if (rtDW.s <= 1.4901161193847656E-8) {
          if (rtDW.j_a + 1 < m) {
            rtDW.vn1_c = xnrm2(rtDW.mmi - 1, A_data, rtDW.pvt + 2);
            rtDW.vn1[rtDW.ii - 1] = rtDW.vn1_c;
            rtDW.vn2[rtDW.ii - 1] = rtDW.vn1_c;
          } else {
            rtDW.vn1[rtDW.ii - 1] = 0.0;
            rtDW.vn2[rtDW.ii - 1] = 0.0;
          }
        } else {
          rtDW.vn1[rtDW.ii - 1] = rtDW.vn1_c * std::sqrt(rtDW.smax);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
void Rpi_cam::xgeqp3(double A_data[], int32_t A_size[2], double tau_data[],
                     int32_t *tau_size, int32_t jpvt[3])
{
  bool guard1;
  rtDW.b_A_size_l[0] = A_size[0];
  rtDW.b_A_size_l[1] = 3;
  rtDW.loop_ub = A_size[0] * 3;
  if (rtDW.loop_ub - 1 >= 0) {
    std::memcpy(&rtDW.b_A_data_c[0], &A_data[0], static_cast<uint32_t>
                (rtDW.loop_ub) * sizeof(double));
  }

  if (A_size[0] <= 3) {
    rtDW.loop_ub = A_size[0];
  } else {
    rtDW.loop_ub = 3;
  }

  *tau_size = rtDW.loop_ub;
  if (rtDW.loop_ub - 1 >= 0) {
    std::memset(&tau_data[0], 0, static_cast<uint32_t>(rtDW.loop_ub) * sizeof
                (double));
  }

  guard1 = false;
  if (A_size[0] == 0) {
    guard1 = true;
  } else {
    if (A_size[0] <= 3) {
      rtDW.i_a = A_size[0];
    } else {
      rtDW.i_a = 3;
    }

    if (rtDW.i_a < 1) {
      guard1 = true;
    } else {
      jpvt[0] = 1;
      jpvt[1] = 2;
      jpvt[2] = 3;
      qrpf(rtDW.b_A_data_c, rtDW.b_A_size_l, A_size[0], tau_data, jpvt);
    }
  }

  if (guard1) {
    jpvt[0] = 1;
    jpvt[1] = 2;
    jpvt[2] = 3;
  }

  A_size[0] = rtDW.b_A_size_l[0];
  A_size[1] = 3;
  rtDW.loop_ub = rtDW.b_A_size_l[0];
  for (rtDW.i_a = 0; rtDW.i_a < 3; rtDW.i_a++) {
    for (rtDW.b_A = 0; rtDW.b_A < rtDW.loop_ub; rtDW.b_A++) {
      A_data[rtDW.b_A + A_size[0] * rtDW.i_a] = rtDW.b_A_data_c[rtDW.b_A_size_l
        [0] * rtDW.i_a + rtDW.b_A];
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
void Rpi_cam::qrsolve(const double A_data[], const int32_t A_size[2], const
                      double B_data[], const int32_t *B_size, double Y[3],
                      int32_t *rankA)
{
  __m128d tmp;
  __m128d tmp_0;
  rtDW.b_A_size[0] = A_size[0];
  rtDW.b_A_size[1] = 3;
  rtDW.maxmn = A_size[0] * 3;
  if (rtDW.maxmn - 1 >= 0) {
    std::memcpy(&rtDW.b_A_data[0], &A_data[0], static_cast<uint32_t>(rtDW.maxmn)
                * sizeof(double));
  }

  xgeqp3(rtDW.b_A_data, rtDW.b_A_size, rtDW.tau_data, &rtDW.tau_size,
         &rtDW.jpvt[0]);
  *rankA = 0;
  if (rtDW.b_A_size[0] < 3) {
    rtDW.minmn = rtDW.b_A_size[0];
    rtDW.maxmn = 3;
  } else {
    rtDW.minmn = 3;
    rtDW.maxmn = rtDW.b_A_size[0];
  }

  if (rtDW.minmn > 0) {
    rtDW.tol = 2.2204460492503131E-15 * static_cast<double>(rtDW.maxmn) * std::
      abs(rtDW.b_A_data[0]);
    while ((*rankA < rtDW.minmn) && (!(std::abs(rtDW.b_A_data[rtDW.b_A_size[0] *
              *rankA + *rankA]) <= rtDW.tol))) {
      (*rankA)++;
    }
  }

  rtDW.minmn = 0;
  if (rtDW.b_A_size[0] <= 3) {
    rtDW.maxmn = rtDW.b_A_size[0];
  } else {
    rtDW.maxmn = 3;
  }

  if (rtDW.maxmn > 0) {
    for (rtDW.k_p = 0; rtDW.k_p < rtDW.maxmn; rtDW.k_p++) {
      if (rtDW.b_A_data[rtDW.b_A_size[0] * rtDW.k_p + rtDW.k_p] != 0.0) {
        rtDW.minmn++;
      }
    }
  }

  rtDW.maxmn = *B_size;
  if (rtDW.maxmn - 1 >= 0) {
    std::memcpy(&rtDW.b_B_data[0], &B_data[0], static_cast<uint32_t>(rtDW.maxmn)
                * sizeof(double));
  }

  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  rtDW.maxmn = rtDW.b_A_size[0];
  if (rtDW.b_A_size[0] <= 3) {
    rtDW.k_p = rtDW.b_A_size[0];
  } else {
    rtDW.k_p = 3;
  }

  for (rtDW.b_j = 0; rtDW.b_j < rtDW.k_p; rtDW.b_j++) {
    if (rtDW.tau_data[rtDW.b_j] != 0.0) {
      rtDW.tol = rtDW.b_B_data[rtDW.b_j];
      for (rtDW.c_i = rtDW.b_j + 2; rtDW.c_i <= rtDW.maxmn; rtDW.c_i++) {
        rtDW.tol += rtDW.b_A_data[(rtDW.b_A_size[0] * rtDW.b_j + rtDW.c_i) - 1] *
          rtDW.b_B_data[rtDW.c_i - 1];
      }

      rtDW.tol *= rtDW.tau_data[rtDW.b_j];
      if (rtDW.tol != 0.0) {
        rtDW.b_B_data[rtDW.b_j] -= rtDW.tol;
        rtDW.scalarLB_a = (((((rtDW.maxmn - rtDW.b_j) - 1) / 2) << 1) + rtDW.b_j)
          + 2;
        rtDW.vectorUB_e = rtDW.scalarLB_a - 2;
        for (rtDW.c_i = rtDW.b_j + 2; rtDW.c_i <= rtDW.vectorUB_e; rtDW.c_i += 2)
        {
          tmp = _mm_loadu_pd(&rtDW.b_A_data[(rtDW.b_A_size[0] * rtDW.b_j +
            rtDW.c_i) - 1]);
          tmp_0 = _mm_loadu_pd(&rtDW.b_B_data[rtDW.c_i - 1]);
          _mm_storeu_pd(&rtDW.b_B_data[rtDW.c_i - 1], _mm_sub_pd(tmp_0,
            _mm_mul_pd(tmp, _mm_set1_pd(rtDW.tol))));
        }

        for (rtDW.c_i = rtDW.scalarLB_a; rtDW.c_i <= rtDW.maxmn; rtDW.c_i++) {
          rtDW.b_B_data[rtDW.c_i - 1] -= rtDW.b_A_data[(rtDW.b_A_size[0] *
            rtDW.b_j + rtDW.c_i) - 1] * rtDW.tol;
        }
      }
    }
  }

  for (rtDW.maxmn = 0; rtDW.maxmn < rtDW.minmn; rtDW.maxmn++) {
    Y[rtDW.jpvt[rtDW.maxmn] - 1] = rtDW.b_B_data[rtDW.maxmn];
  }

  for (rtDW.maxmn = rtDW.minmn; rtDW.maxmn >= 1; rtDW.maxmn--) {
    rtDW.k_p = rtDW.jpvt[rtDW.maxmn - 1];
    rtDW.c_i = (rtDW.maxmn - 1) * rtDW.b_A_size[0];
    Y[rtDW.k_p - 1] /= rtDW.b_A_data[(rtDW.maxmn + rtDW.c_i) - 1];
    for (rtDW.b_j = 0; rtDW.b_j <= rtDW.maxmn - 2; rtDW.b_j++) {
      Y[rtDW.jpvt[rtDW.b_j] - 1] -= Y[rtDW.k_p - 1] * rtDW.b_A_data[rtDW.b_j +
        rtDW.c_i];
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
void Rpi_cam::polyfit(const double x_data[], const int32_t *x_size, const double
                      y_data[], const int32_t *y_size, double p[3])
{
  __m128d tmp;
  __m128d tmp_0;
  rtDW.V_size[0] = *x_size;
  rtDW.V_size[1] = 3;
  if (*x_size != 0) {
    rtDW.b_px = *x_size;
    for (rtDW.k = 0; rtDW.k < rtDW.b_px; rtDW.k++) {
      rtDW.V_data[rtDW.k + (rtDW.V_size[0] << 1)] = 1.0;
    }

    rtDW.b_px = *x_size;
    for (rtDW.k = 0; rtDW.k < rtDW.b_px; rtDW.k++) {
      rtDW.V_data[rtDW.k + rtDW.V_size[0]] = x_data[rtDW.k];
    }

    rtDW.b_px = *x_size;
    rtDW.scalarLB = (*x_size / 2) << 1;
    rtDW.vectorUB = rtDW.scalarLB - 2;
    for (rtDW.k = 0; rtDW.k <= rtDW.vectorUB; rtDW.k += 2) {
      tmp = _mm_loadu_pd(&x_data[rtDW.k]);
      tmp_0 = _mm_loadu_pd(&rtDW.V_data[rtDW.k + rtDW.V_size[0]]);
      _mm_storeu_pd(&rtDW.V_data[rtDW.k], _mm_mul_pd(tmp, tmp_0));
    }

    for (rtDW.k = rtDW.scalarLB; rtDW.k < rtDW.b_px; rtDW.k++) {
      rtDW.V_data[rtDW.k] = rtDW.V_data[rtDW.k + rtDW.V_size[0]] * x_data[rtDW.k];
    }
  }

  qrsolve(rtDW.V_data, rtDW.V_size, y_data, y_size, p, &rtDW.b_px);
}

codertarget_raspi_internal_Raspiv4l2Capture *Rpi_cam::
  Raspiv4l2Capture_Raspiv4l2Capture(codertarget_raspi_internal_Raspiv4l2Capture *
  obj)
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

void Rpi_cam::SystemCore_setup(codertarget_raspi_internal_Raspiv4l2Capture *obj)
{
  static const std::array<char, 101> b_errorMessage{ { 'W', 'e', 'b', 'c', 'a',
      'm', ' ', 'c', 'a', 'n', 'n', 'o', 't', ' ', 'b', 'e', ' ', 'i', 'n', 'i',
      't', 'i', 'a', 'l', 'i', 'z', 'e', 'd', ' ', 'p', 'r', 'o', 'p', 'e', 'r',
      'l', 'y', '.', ' ', 'P', 'l', 'e', 'a', 's', 'e', ' ', 'c', 'h', 'e', 'c',
      'k', ' ', 'i', 'f', ' ', 't', 'h', 'e', ' ', 'd', 'e', 'v', 'i', 'c', 'e',
      ' ', 's', 'u', 'p', 'p', 'o', 'r', 't', 's', ' ', 't', 'h', 'e', ' ', 's',
      'p', 'e', 'c', 'i', 'f', 'i', 'e', 'd', ' ', 'r', 'e', 's', 'o', 'l', 'u',
      't', 'i', 'o', 'n', '.', '\x00' } };

  static const std::array<char, 12> devName{ { '/', 'd', 'e', 'v', '/', 'v', 'i',
      'd', 'e', 'o', '0', '\x00' } };

  int32_t i;
  int8_t resolutionStatus;
  uint8_t camIndex;
  obj->isSetupComplete = false;

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  obj->isInitialized = 1;
  getCameraList();
  for (i = 0; i < 12; i++) {
    rtDW.devName[i] = devName[i];
  }

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  camIndex = getCameraAddrIndex(&rtDW.devName[0], 11U);
  resolutionStatus = validateResolution(camIndex, 640, 480);
  if (resolutionStatus >= 0) {
    // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
    EXT_webcamInit(0, 0, 0, 0, 0, 0, 640U, 480U, 2U, 2U, 1U, 0.1);
  } else {
    // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
    std::memcpy(&rtDW.b_errorMessage[0], &b_errorMessage[0], 101U * sizeof(char));
    std::perror(&rtDW.b_errorMessage[0]);

    // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
    std::exit(0);
  }

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  v4l2Capture_updateV4L2Settings(obj, true);
  obj->isSetupComplete = true;
}

// Model step function
void Rpi_cam::step()
{
  static const std::array<int16_t, 8> tmp{ { 110, 500, 1, 639, 300, 300, 390,
      415 } };

  static const std::array<int16_t, 8> tmp_0{ { 40, 600, 40, 600, 300, 300, 480,
      480 } };

  // MATLABSystem: '<Root>/V4L2 Video Capture'
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

  SystemCore_step(&rtDW.obj, &rtDW.b_varargout_1_g[0], &rtDW.b_varargout_2[0],
                  &rtDW.b_varargout_3[0]);

  // Math: '<S3>/Transpose' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'
  //
  for (rtDW.i = 0; rtDW.i < 640; rtDW.i++) {
    for (rtDW.inlierNum = 0; rtDW.inlierNum < 480; rtDW.inlierNum++) {
      rtDW.b_varargout_1_c[rtDW.inlierNum + 480 * rtDW.i] =
        rtDW.b_varargout_1_g[640 * rtDW.inlierNum + rtDW.i];
    }
  }

  std::memcpy(&rtDW.outputImage[0], &rtDW.b_varargout_1_c[0], 307200U * sizeof
              (uint8_t));

  // End of Math: '<S3>/Transpose'

  // Math: '<S3>/Transpose1' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'
  //
  for (rtDW.i = 0; rtDW.i < 640; rtDW.i++) {
    for (rtDW.inlierNum = 0; rtDW.inlierNum < 480; rtDW.inlierNum++) {
      rtDW.b_varargout_1_g[rtDW.inlierNum + 480 * rtDW.i] = rtDW.b_varargout_2
        [640 * rtDW.inlierNum + rtDW.i];
    }
  }

  std::memcpy(&rtDW.outputImage[307200], &rtDW.b_varargout_1_g[0], 307200U *
              sizeof(uint8_t));

  // End of Math: '<S3>/Transpose1'

  // Math: '<S3>/Transpose2' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'
  //
  for (rtDW.i = 0; rtDW.i < 640; rtDW.i++) {
    for (rtDW.inlierNum = 0; rtDW.inlierNum < 480; rtDW.inlierNum++) {
      rtDW.b_varargout_2[rtDW.inlierNum + 480 * rtDW.i] = rtDW.b_varargout_3[640
        * rtDW.inlierNum + rtDW.i];
    }
  }

  std::memcpy(&rtDW.outputImage[614400], &rtDW.b_varargout_2[0], 307200U *
              sizeof(uint8_t));

  // End of Math: '<S3>/Transpose2'

  // MATLAB Function: '<Root>/MATLAB Function'
  for (rtDW.inlierNum = 0; rtDW.inlierNum < 3; rtDW.inlierNum++) {
    for (rtDW.j = 0; rtDW.j < 640; rtDW.j++) {
      for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 240; rtDW.svdRsltVar++) {
        rtDW.i = (480 * rtDW.j + rtDW.svdRsltVar) + 307200 * rtDW.inlierNum;
        rtDW.xtmp = rtDW.outputImage[rtDW.i];
        rtDW.outputImage_tmp = ((480 * rtDW.j - rtDW.svdRsltVar) + 307200 *
          rtDW.inlierNum) + 479;
        rtDW.outputImage[rtDW.i] = rtDW.outputImage[rtDW.outputImage_tmp];
        rtDW.outputImage[rtDW.outputImage_tmp] = rtDW.xtmp;
      }
    }
  }

  for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 3; rtDW.svdRsltVar++) {
    for (rtDW.inlierNum = 0; rtDW.inlierNum < 320; rtDW.inlierNum++) {
      for (rtDW.j = 0; rtDW.j < 480; rtDW.j++) {
        rtDW.i = (480 * rtDW.inlierNum + rtDW.j) + 307200 * rtDW.svdRsltVar;
        rtDW.xtmp = rtDW.outputImage[rtDW.i];
        rtDW.outputImage_tmp = ((639 - rtDW.inlierNum) * 480 + rtDW.j) + 307200 *
          rtDW.svdRsltVar;
        rtDW.outputImage[rtDW.i] = rtDW.outputImage[rtDW.outputImage_tmp];
        rtDW.outputImage[rtDW.outputImage_tmp] = rtDW.xtmp;
      }
    }
  }

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion'
  for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 921600; rtDW.svdRsltVar++) {
    rtDW.ImageDataTypeConversion[rtDW.svdRsltVar] = static_cast<double>
      (rtDW.outputImage[rtDW.svdRsltVar]) / 255.0;
  }

  // End of S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion'
  // temporary variables for in-place operation
  for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 307200; rtDW.svdRsltVar++) {
    // S-Function (svipcolorconv): '<S4>/Color Space  Conversion' incorporates:
    //   S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion'

    // First get the min and max of the RGB triplet
    rtDW.win_y_high = rtDW.ImageDataTypeConversion[rtDW.svdRsltVar];
    rtDW.ImageDataTypeConversion_b =
      rtDW.ImageDataTypeConversion[rtDW.svdRsltVar + 307200];
    if (rtDW.win_y_high > rtDW.ImageDataTypeConversion_b) {
      rtDW.ImageDataTypeConversion_p =
        rtDW.ImageDataTypeConversion[rtDW.svdRsltVar + 614400];
      if (rtDW.ImageDataTypeConversion_b < rtDW.ImageDataTypeConversion_p) {
        rtDW.count_right = rtDW.ImageDataTypeConversion_b;
      } else {
        rtDW.count_right = rtDW.ImageDataTypeConversion_p;
      }

      if (rtDW.win_y_high > rtDW.ImageDataTypeConversion_p) {
        rtDW.bestInlierDis = rtDW.win_y_high;
      } else {
        rtDW.bestInlierDis = rtDW.ImageDataTypeConversion_p;
      }
    } else {
      rtDW.ImageDataTypeConversion_p =
        rtDW.ImageDataTypeConversion[rtDW.svdRsltVar + 614400];
      if (rtDW.win_y_high < rtDW.ImageDataTypeConversion_p) {
        rtDW.count_right = rtDW.win_y_high;
      } else {
        rtDW.count_right = rtDW.ImageDataTypeConversion_p;
      }

      if (rtDW.ImageDataTypeConversion_b > rtDW.ImageDataTypeConversion_p) {
        rtDW.bestInlierDis = rtDW.ImageDataTypeConversion_b;
      } else {
        rtDW.bestInlierDis = rtDW.ImageDataTypeConversion_p;
      }
    }

    rtDW.win_y_low = rtDW.bestInlierDis - rtDW.count_right;
    if (rtDW.bestInlierDis != 0.0) {
      rtDW.count_right = rtDW.win_y_low / rtDW.bestInlierDis;
    } else {
      rtDW.count_right = 0.0;
    }

    if (rtDW.win_y_low != 0.0) {
      if (rtDW.win_y_high == rtDW.bestInlierDis) {
        rtDW.win_y_low = (rtDW.ImageDataTypeConversion_b -
                          rtDW.ImageDataTypeConversion_p) / rtDW.win_y_low;
      } else if (rtDW.ImageDataTypeConversion_b == rtDW.bestInlierDis) {
        rtDW.win_y_low = (rtDW.ImageDataTypeConversion_p - rtDW.win_y_high) /
          rtDW.win_y_low + 2.0;
      } else {
        rtDW.win_y_low = (rtDW.win_y_high - rtDW.ImageDataTypeConversion_b) /
          rtDW.win_y_low + 4.0;
      }

      rtDW.win_y_low /= 6.0;
      if (rtDW.win_y_low < 0.0) {
        rtDW.win_y_low++;
      }
    } else {
      rtDW.win_y_low = 0.0;
    }

    // assign the results
    rtDW.ColorSpaceConversion[rtDW.svdRsltVar] = rtDW.win_y_low;
    rtDW.ColorSpaceConversion[rtDW.svdRsltVar + 307200] = rtDW.count_right;

    // S-Function (svipcolorconv): '<S4>/Color Space  Conversion'
    rtDW.ColorSpaceConversion[rtDW.svdRsltVar + 614400] = rtDW.bestInlierDis;

    // MATLAB Function: '<S4>/MATLAB Function7' incorporates:
    //   S-Function (svipcolorconv): '<S4>/Color Space  Conversion'

    rtDW.V_Channel[rtDW.svdRsltVar] = rtDW.bestInlierDis;
  }

  for (rtDW.i = 0; rtDW.i < 8; rtDW.i++) {
    // MATLAB Function: '<S4>/MATLAB Function1'
    rtDW.pts1[rtDW.i] = tmp[rtDW.i];

    // MATLAB Function: '<S4>/MATLAB Function2'
    rtDW.pts2[rtDW.i] = tmp_0[rtDW.i];
  }

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
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
              &rtDW.x_current, &rtDW.cents1[0]);
  normPts_D_D((const double *)&rtDW.pts2[0], (const uint32_t *)
              &rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
              &rtDW.EstimateGeometricTransformation_DW_PTSNORM2[0],
              &rtDW.y_current, &rtDW.cents2[0]);
  makeConstraintMatrix_Projective_D_D((const double *)
    &rtDW.EstimateGeometricTransformation_DW_PTSNORM1[0], (const double *)
    &rtDW.EstimateGeometricTransformation_DW_PTSNORM2[0], 4U, 4U,
    &rtDW.Constraint[0]);
  for (rtDW.i = 0; rtDW.i < 8; rtDW.i++) {
    rtDW.JPVT[static_cast<uint32_t>(rtDW.i)] = 0;
  }

  QRE_double_o(&rtDW.Q[0], &rtDW.Constraint[0], &rtDW.E[0], &rtDW.Qraux[0],
               &rtDW.Work[0], &rtDW.JPVT[0], &rtDW.RV[0], 9, 8, true);
  rtDW.count_right = 0.0;
  for (rtDW.i = 0; rtDW.i < 9; rtDW.i++) {
    for (rtDW.j = 0; rtDW.j < 9; rtDW.j++) {
      if (static_cast<uint32_t>(rtDW.i) != static_cast<uint32_t>(rtDW.j)) {
        rtDW.win_y_low = 0.0;
      } else {
        rtDW.win_y_low = -1.0;
      }

      for (rtDW.inlierNum = 0; rtDW.inlierNum < 8; rtDW.inlierNum++) {
        rtDW.win_y_low_tmp = static_cast<uint32_t>(rtDW.inlierNum) * 9U;
        rtDW.win_y_low += rtDW.Q[rtDW.win_y_low_tmp + static_cast<uint32_t>
          (rtDW.i)] * rtDW.Q[rtDW.win_y_low_tmp + static_cast<uint32_t>(rtDW.j)];
      }

      rtDW.RV[static_cast<uint32_t>(rtDW.i) * 9U + static_cast<uint32_t>(rtDW.j)]
        = rtDW.win_y_low;
      if (!(rtDW.win_y_low >= 0.0)) {
        rtDW.win_y_low = -rtDW.win_y_low;
      }

      if (rtDW.count_right < rtDW.win_y_low) {
        rtDW.count_right = rtDW.win_y_low;
        rtDW.bestCol = static_cast<uint32_t>(rtDW.i);
      }
    }
  }

  rtDW.j = static_cast<int32_t>(rtDW.bestCol * 9U);
  for (rtDW.i = 0; rtDW.i < 9; rtDW.i++) {
    rtDW.tformCompact[static_cast<uint32_t>(rtDW.i)] = rtDW.RV
      [static_cast<uint32_t>(rtDW.j) + static_cast<uint32_t>(rtDW.i)];
  }

  rtDW.count_right = 1.0 / rtDW.y_current;
  rtDW.win_y_low = rtDW.x_current * rtDW.count_right;
  rtDW.tformCompact_k[6] = rtDW.tformCompact[6] * rtDW.x_current;
  rtDW.tformCompact_k[7] = rtDW.tformCompact[7] * rtDW.x_current;
  rtDW.tformCompact_k[8] = (rtDW.tformCompact[8] - rtDW.cents1[0] *
    rtDW.tformCompact_k[6]) - rtDW.cents1[1] * rtDW.tformCompact_k[7];
  rtDW.tformCompact_k[0] = rtDW.tformCompact[0] * rtDW.win_y_low;
  rtDW.tformCompact_k[1] = rtDW.tformCompact[1] * rtDW.win_y_low;
  rtDW.tformCompact_k[2] = ((rtDW.cents2[0] * rtDW.tformCompact_k[8] -
    rtDW.tformCompact_k[0] * rtDW.cents1[0]) - rtDW.tformCompact_k[1] *
    rtDW.cents1[1]) + rtDW.tformCompact[2] * rtDW.count_right;
  rtDW.tformCompact_k[3] = rtDW.tformCompact[3] * rtDW.win_y_low;
  rtDW.tformCompact_k[4] = rtDW.tformCompact[4] * rtDW.win_y_low;
  rtDW.tformCompact_k[5] = ((rtDW.cents2[1] * rtDW.tformCompact_k[8] -
    rtDW.cents1[0] * rtDW.tformCompact_k[3]) - rtDW.cents1[1] *
    rtDW.tformCompact_k[4]) + rtDW.tformCompact[5] * rtDW.count_right;
  rtDW.tformCompact_k[0] += rtDW.cents2[0] * rtDW.tformCompact_k[6];
  rtDW.tformCompact_k[1] += rtDW.cents2[0] * rtDW.tformCompact_k[7];
  rtDW.tformCompact_k[3] += rtDW.cents2[1] * rtDW.tformCompact_k[6];
  rtDW.tformCompact_k[4] += rtDW.cents2[1] * rtDW.tformCompact_k[7];
  if (rtDW.tformCompact_k[8U] != 0.0) {
    rtDW.count_right = 1.0 / rtDW.tformCompact_k[8];
    for (rtDW.i = 0; rtDW.i < 8; rtDW.i++) {
      rtDW.tformCompact_k[static_cast<uint32_t>(rtDW.i)] *= rtDW.count_right;
    }

    rtDW.tformCompact_k[8] = 1.0;
    rtDW.bestCol = 0U;
    for (rtDW.i = 0; rtDW.i < 4; rtDW.i++) {
      rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_t>
        (rtDW.i)] = 0.0;
      for (rtDW.j = 0; rtDW.j < 2; rtDW.j++) {
        rtDW.count_right = 0.0;
        for (rtDW.inlierNum = 0; rtDW.inlierNum < 9; rtDW.inlierNum++) {
          rtDW.count_right +=
            rtDW.EstimateGeometricTransformation_DW_CONSTRT_ALL[rtDW.bestCol +
            static_cast<uint32_t>(rtDW.inlierNum)] * rtDW.tformCompact_k[
            static_cast<uint32_t>(rtDW.inlierNum)];
        }

        rtDW.bestCol += 9U;
        rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_t>
          (rtDW.i)] += rtDW.count_right * rtDW.count_right;
      }
    }

    std::memcpy(&rtDW.bestTFormCompact[0], &rtDW.tformCompact_k[0], 9U * sizeof
                (double));
    rtDW.inlierNum = 0;
    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[0] <= 2.5) {
      rtDW.inlierNum = 1;
    }

    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[1] <= 2.5) {
      rtDW.inlierNum = static_cast<int32_t>(static_cast<uint32_t>(rtDW.inlierNum)
        + 1U);
    }

    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[2] <= 2.5) {
      rtDW.inlierNum = static_cast<int32_t>(static_cast<uint32_t>(rtDW.inlierNum)
        + 1U);
    }

    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[3] <= 2.5) {
      rtDW.inlierNum = static_cast<int32_t>(static_cast<uint32_t>(rtDW.inlierNum)
        + 1U);
    }
  } else {
    rtDW.inlierNum = 0;
  }

  if (static_cast<uint32_t>(rtDW.inlierNum) >= 4U) {
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

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'

  // MATLAB Function: '<S4>/MATLAB Function8'
  for (rtDW.i = 0; rtDW.i < 307200; rtDW.i++) {
    rtDW.rtb_V_Channel_o[rtDW.i] = (rtDW.V_Channel[rtDW.i] > 0.5);
  }

  // End of MATLAB Function: '<S4>/MATLAB Function8'

  // MATLABSystem: '<S4>/Warp' incorporates:
  //   S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'

  Warp_stepImpl(&rtDW.obj_k, &rtDW.rtb_V_Channel_o[0],
                &rtDW.EstimateGeometricTransformation[0], &rtDW.bv[0]);

  // MATLABSystem: '<S4>/Warp'
  std::memcpy(&rtDW.Warp[0], &rtDW.bv[0], 307200U * sizeof(bool));

  // MATLAB Function: '<S2>/MATLAB Function1' incorporates:
  //   MATLABSystem: '<S4>/Warp'

  std::memset(&rtDW.left_lane_index[0], 0, 200000U * sizeof(double));
  std::memset(&rtDW.right_lane_index[0], 0, 200000U * sizeof(double));
  eml_find(&rtDW.Warp[0], rtDW.ii_data, &rtDW.ii_size, rtDW.jj_data_n,
           &rtDW.jj_size);
  rtDW.b_tmp_tmp_size = rtDW.ii_size;
  rtDW.j = rtDW.ii_size;
  for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
    rtDW.outputImage_tmp = rtDW.ii_data[rtDW.i];
    rtDW.b_tmp_tmp_data[rtDW.i] = ((rtDW.outputImage_tmp >= 456) &&
      (rtDW.outputImage_tmp < 480));
  }

  if (rtDW.ii_size == rtDW.jj_size) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    rtDW.b_tmp_size = rtDW.ii_size;
    rtDW.j = rtDW.ii_size;
    for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
      rtDW.b_tmp_data[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
        (rtDW.jj_data_n[rtDW.i] >= 0));
    }
  } else {
    // MATLAB Function: '<S2>/MATLAB Function1'
    binary_expand_op_5(rtDW.b_tmp_data, &rtDW.b_tmp_size, rtDW.b_tmp_tmp_data,
                       &rtDW.b_tmp_tmp_size, rtDW.jj_data_n, &rtDW.jj_size);
  }

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtDW.r_size = rtDW.jj_size;
  rtDW.j = rtDW.jj_size;
  for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
    rtDW.r_data[rtDW.i] = (rtDW.jj_data_n[rtDW.i] < 160);
  }

  if (rtDW.ii_size == rtDW.jj_size) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    rtDW.j = rtDW.ii_size;
    for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
      rtDW.b_tmp_tmp_data[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
        (rtDW.jj_data_n[rtDW.i] >= 480));
    }
  } else {
    // MATLAB Function: '<S2>/MATLAB Function1'
    binary_expand_op_4(rtDW.b_tmp_tmp_data, &rtDW.b_tmp_tmp_size, rtDW.jj_data_n,
                       &rtDW.jj_size);
  }

  // MATLAB Function: '<S2>/MATLAB Function1'
  rtDW.t_size = rtDW.jj_size;
  rtDW.j = rtDW.jj_size;
  for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
    rtDW.t_data[rtDW.i] = (rtDW.jj_data_n[rtDW.i] < 640);
  }

  if (rtDW.b_tmp_size == rtDW.jj_size) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    rtDW.tmp_size = rtDW.b_tmp_size;
    rtDW.j = rtDW.b_tmp_size;
    for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
      rtDW.tmp_data_lm[rtDW.i] = (rtDW.b_tmp_data[rtDW.i] && rtDW.r_data[rtDW.i]);
    }
  } else {
    // MATLAB Function: '<S2>/MATLAB Function1'
    and_o(rtDW.tmp_data_lm, &rtDW.tmp_size, rtDW.b_tmp_data, &rtDW.b_tmp_size,
          rtDW.r_data, &rtDW.r_size);
  }

  rtDW.end = rtDW.tmp_size - 1;
  rtDW.outputImage_tmp = 0;
  for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    if (rtDW.tmp_data_lm[rtDW.i]) {
      rtDW.outputImage_tmp++;
    }
  }

  // MATLAB Function: '<S2>/MATLAB Function1'
  for (rtDW.inlierNum = 0; rtDW.inlierNum < rtDW.outputImage_tmp; rtDW.inlierNum
       ++) {
    rtDW.svdRsltVar = rtDW.b_tmp_size;
    if (rtDW.b_tmp_size == rtDW.r_size) {
      rtDW.tmp_size_b = rtDW.b_tmp_size;
      for (rtDW.i = 0; rtDW.i < rtDW.svdRsltVar; rtDW.i++) {
        rtDW.tmp_data_mj[rtDW.i] = (rtDW.b_tmp_data[rtDW.i] &&
          rtDW.r_data[rtDW.i]);
      }
    } else {
      and_o(rtDW.tmp_data_mj, &rtDW.tmp_size_b, rtDW.b_tmp_data,
            &rtDW.b_tmp_size, rtDW.r_data, &rtDW.r_size);
    }

    rtDW.svdRsltVar = rtDW.b_tmp_size;
    if (rtDW.b_tmp_size == rtDW.r_size) {
      rtDW.tmp_size_d = rtDW.b_tmp_size;
      for (rtDW.i = 0; rtDW.i < rtDW.svdRsltVar; rtDW.i++) {
        rtDW.tmp_data_c[rtDW.i] = (rtDW.b_tmp_data[rtDW.i] && rtDW.r_data[rtDW.i]);
      }
    } else {
      and_o(rtDW.tmp_data_c, &rtDW.tmp_size_d, rtDW.b_tmp_data, &rtDW.b_tmp_size,
            rtDW.r_data, &rtDW.r_size);
    }

    rtDW.end = rtDW.tmp_size_b - 1;
    rtDW.partialTrueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_mj[rtDW.i]) {
        rtDW.n_tmp_data[rtDW.partialTrueCount] = rtDW.i;
        rtDW.partialTrueCount++;
      }
    }

    rtDW.end = rtDW.tmp_size_d - 1;
    rtDW.partialTrueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_c[rtDW.i]) {
        rtDW.tmp_data_p[rtDW.partialTrueCount] = rtDW.i;
        rtDW.partialTrueCount++;
      }
    }

    rtDW.left_lane_index[rtDW.inlierNum] =
      rtDW.jj_data_n[rtDW.n_tmp_data[rtDW.inlierNum]];
    rtDW.left_lane_index[rtDW.inlierNum + 100000] =
      rtDW.ii_data[rtDW.tmp_data_p[rtDW.inlierNum]];
  }

  if (rtDW.b_tmp_tmp_size == rtDW.jj_size) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    rtDW.tmp_size_h = rtDW.b_tmp_tmp_size;
    rtDW.j = rtDW.b_tmp_tmp_size;
    for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
      rtDW.tmp_data_m[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
        rtDW.t_data[rtDW.i]);
    }
  } else {
    // MATLAB Function: '<S2>/MATLAB Function1'
    and_o(rtDW.tmp_data_m, &rtDW.tmp_size_h, rtDW.b_tmp_tmp_data,
          &rtDW.b_tmp_tmp_size, rtDW.t_data, &rtDW.t_size);
  }

  rtDW.end = rtDW.tmp_size_h - 1;
  rtDW.outputImage_tmp = 0;
  for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    if (rtDW.tmp_data_m[rtDW.i]) {
      rtDW.outputImage_tmp++;
    }
  }

  // MATLAB Function: '<S2>/MATLAB Function1'
  for (rtDW.inlierNum = 0; rtDW.inlierNum < rtDW.outputImage_tmp; rtDW.inlierNum
       ++) {
    rtDW.end = rtDW.b_tmp_tmp_size;
    if (rtDW.b_tmp_tmp_size == rtDW.t_size) {
      rtDW.tmp_size_bj = rtDW.b_tmp_tmp_size;
      for (rtDW.i = 0; rtDW.i < rtDW.end; rtDW.i++) {
        rtDW.tmp_data_p4[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
          rtDW.t_data[rtDW.i]);
      }
    } else {
      and_o(rtDW.tmp_data_p4, &rtDW.tmp_size_bj, rtDW.b_tmp_tmp_data,
            &rtDW.b_tmp_tmp_size, rtDW.t_data, &rtDW.t_size);
    }

    rtDW.end = rtDW.b_tmp_tmp_size;
    if (rtDW.b_tmp_tmp_size == rtDW.t_size) {
      rtDW.tmp_size_j = rtDW.b_tmp_tmp_size;
      for (rtDW.i = 0; rtDW.i < rtDW.end; rtDW.i++) {
        rtDW.tmp_data_e[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
          rtDW.t_data[rtDW.i]);
      }
    } else {
      and_o(rtDW.tmp_data_e, &rtDW.tmp_size_j, rtDW.b_tmp_tmp_data,
            &rtDW.b_tmp_tmp_size, rtDW.t_data, &rtDW.t_size);
    }

    rtDW.end = rtDW.tmp_size_bj - 1;
    rtDW.partialTrueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_p4[rtDW.i]) {
        rtDW.tmp_data_l[rtDW.partialTrueCount] = rtDW.i;
        rtDW.partialTrueCount++;
      }
    }

    rtDW.end = rtDW.tmp_size_j - 1;
    rtDW.partialTrueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_e[rtDW.i]) {
        rtDW.tmp_data_j[rtDW.partialTrueCount] = rtDW.i;
        rtDW.partialTrueCount++;
      }
    }

    rtDW.right_lane_index[rtDW.inlierNum] =
      rtDW.jj_data_n[rtDW.tmp_data_l[rtDW.inlierNum]];
    rtDW.right_lane_index[rtDW.inlierNum + 100000] =
      rtDW.ii_data[rtDW.tmp_data_j[rtDW.inlierNum]];
  }

  if (rtDW.b_tmp_tmp_size == rtDW.jj_size) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    rtDW.tmp_size_e = rtDW.b_tmp_tmp_size;
    rtDW.j = rtDW.b_tmp_tmp_size;
    for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
      rtDW.tmp_data_f[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
        rtDW.t_data[rtDW.i]);
    }
  } else {
    // MATLAB Function: '<S2>/MATLAB Function1'
    and_o(rtDW.tmp_data_f, &rtDW.tmp_size_e, rtDW.b_tmp_tmp_data,
          &rtDW.b_tmp_tmp_size, rtDW.t_data, &rtDW.t_size);
  }

  rtDW.end = rtDW.tmp_size_e - 1;
  rtDW.outputImage_tmp = 0;
  for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    if (rtDW.tmp_data_f[rtDW.i]) {
      rtDW.outputImage_tmp++;
    }
  }

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (rtDW.outputImage_tmp > 30) {
    rtDW.inlierNum = 1;
    if (rtDW.b_tmp_tmp_size == rtDW.jj_size) {
      rtDW.tmp_size_f = rtDW.b_tmp_tmp_size;
      rtDW.j = rtDW.b_tmp_tmp_size;
      for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
        rtDW.tmp_data_o4[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
          rtDW.t_data[rtDW.i]);
      }
    } else {
      and_o(rtDW.tmp_data_o4, &rtDW.tmp_size_f, rtDW.b_tmp_tmp_data,
            &rtDW.b_tmp_tmp_size, rtDW.t_data, &rtDW.t_size);
    }

    rtDW.end = rtDW.tmp_size_f - 1;
    rtDW.outputImage_tmp = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_o4[rtDW.i]) {
        rtDW.outputImage_tmp++;
      }
    }

    rtDW.partialTrueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_o4[rtDW.i]) {
        rtDW.tmp_data_d[rtDW.partialTrueCount] = rtDW.i;
        rtDW.partialTrueCount++;
      }
    }

    rtDW.jj_size_c = rtDW.outputImage_tmp;
    for (rtDW.i = 0; rtDW.i < rtDW.outputImage_tmp; rtDW.i++) {
      rtDW.jj_data[rtDW.i] = rtDW.jj_data_n[rtDW.tmp_data_d[rtDW.i]];
    }

    rtDW.x_current = mean(rtDW.jj_data, &rtDW.jj_size_c);
    if (rtDW.b_tmp_tmp_size == rtDW.jj_size) {
      rtDW.tmp_size_a = rtDW.b_tmp_tmp_size;
      rtDW.j = rtDW.b_tmp_tmp_size;
      for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
        rtDW.tmp_data_h[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
          rtDW.t_data[rtDW.i]);
      }
    } else {
      and_o(rtDW.tmp_data_h, &rtDW.tmp_size_a, rtDW.b_tmp_tmp_data,
            &rtDW.b_tmp_tmp_size, rtDW.t_data, &rtDW.t_size);
    }

    rtDW.end = rtDW.tmp_size_a - 1;
    rtDW.outputImage_tmp = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_h[rtDW.i]) {
        rtDW.outputImage_tmp++;
      }
    }

    rtDW.partialTrueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_h[rtDW.i]) {
        rtDW.tmp_data_g[rtDW.partialTrueCount] = rtDW.i;
        rtDW.partialTrueCount++;
      }
    }

    rtDW.jj_size_c = rtDW.outputImage_tmp;
    for (rtDW.i = 0; rtDW.i < rtDW.outputImage_tmp; rtDW.i++) {
      rtDW.jj_data[rtDW.i] = rtDW.ii_data[rtDW.tmp_data_g[rtDW.i]];
    }

    rtDW.y_current = maximum(rtDW.jj_data, &rtDW.jj_size_c);
  } else {
    rtDW.inlierNum = 2;
    if (rtDW.b_tmp_size == rtDW.jj_size) {
      rtDW.tmp_size_f = rtDW.b_tmp_size;
      rtDW.j = rtDW.b_tmp_size;
      for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
        rtDW.tmp_data_o4[rtDW.i] = (rtDW.b_tmp_data[rtDW.i] &&
          rtDW.r_data[rtDW.i]);
      }
    } else {
      and_o(rtDW.tmp_data_o4, &rtDW.tmp_size_f, rtDW.b_tmp_data,
            &rtDW.b_tmp_size, rtDW.r_data, &rtDW.r_size);
    }

    rtDW.end = rtDW.tmp_size_f - 1;
    rtDW.outputImage_tmp = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_o4[rtDW.i]) {
        rtDW.outputImage_tmp++;
      }
    }

    rtDW.partialTrueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_o4[rtDW.i]) {
        rtDW.tmp_data_d[rtDW.partialTrueCount] = rtDW.i;
        rtDW.partialTrueCount++;
      }
    }

    rtDW.jj_size_c = rtDW.outputImage_tmp;
    for (rtDW.i = 0; rtDW.i < rtDW.outputImage_tmp; rtDW.i++) {
      rtDW.jj_data[rtDW.i] = rtDW.jj_data_n[rtDW.tmp_data_d[rtDW.i]];
    }

    rtDW.x_current = mean(rtDW.jj_data, &rtDW.jj_size_c);
    if (rtDW.b_tmp_size == rtDW.jj_size) {
      rtDW.tmp_size_a = rtDW.b_tmp_size;
      rtDW.j = rtDW.b_tmp_size;
      for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
        rtDW.tmp_data_h[rtDW.i] = (rtDW.b_tmp_data[rtDW.i] && rtDW.r_data[rtDW.i]);
      }
    } else {
      and_o(rtDW.tmp_data_h, &rtDW.tmp_size_a, rtDW.b_tmp_data, &rtDW.b_tmp_size,
            rtDW.r_data, &rtDW.r_size);
    }

    rtDW.end = rtDW.tmp_size_a - 1;
    rtDW.outputImage_tmp = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_h[rtDW.i]) {
        rtDW.outputImage_tmp++;
      }
    }

    rtDW.partialTrueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
      if (rtDW.tmp_data_h[rtDW.i]) {
        rtDW.tmp_data_g[rtDW.partialTrueCount] = rtDW.i;
        rtDW.partialTrueCount++;
      }
    }

    rtDW.jj_size_c = rtDW.outputImage_tmp;
    for (rtDW.i = 0; rtDW.i < rtDW.outputImage_tmp; rtDW.i++) {
      rtDW.jj_data[rtDW.i] = rtDW.ii_data[rtDW.tmp_data_g[rtDW.i]];
    }

    rtDW.y_current = maximum(rtDW.jj_data, &rtDW.jj_size_c);
  }

  rtDW.bestInlierDis = 0.0;
  rtDW.count_right = 0.0;
  for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 20; rtDW.svdRsltVar++) {
    if (rtDW.inlierNum == 1) {
      rtDW.win_y_low = rtDW.y_current - ((static_cast<double>(rtDW.svdRsltVar) +
        1.0) + 1.0) * 24.0;
      rtDW.win_y_high = rtDW.y_current - (static_cast<double>(rtDW.svdRsltVar) +
        1.0) * 24.0;
      rtDW.outputImage_tmp = rtDW.ii_size;
      rtDW.n_tmp_size_idx_0 = rtDW.ii_size;
      if (rtDW.outputImage_tmp - 1 >= 0) {
        std::memcpy(&rtDW.n_tmp_data[0], &rtDW.ii_data[0], static_cast<uint32_t>
                    (rtDW.outputImage_tmp) * sizeof(int32_t));
      }

      rtDW.b_tmp_tmp_size = rtDW.ii_size;
      for (rtDW.i = 0; rtDW.i < rtDW.n_tmp_size_idx_0; rtDW.i++) {
        rtDW.outputImage_tmp = rtDW.n_tmp_data[rtDW.i];
        rtDW.b_tmp_tmp_data[rtDW.i] = (rtDW.outputImage_tmp >= rtDW.win_y_low);
        rtDW.b_tmp_data[rtDW.i] = (rtDW.outputImage_tmp < rtDW.win_y_high);
      }

      rtDW.j = rtDW.jj_size;
      rtDW.n_tmp_size_idx_0 = rtDW.jj_size;
      if (rtDW.j - 1 >= 0) {
        std::memcpy(&rtDW.n_tmp_data[0], &rtDW.jj_data_n[0],
                    static_cast<uint32_t>(rtDW.j) * sizeof(int32_t));
      }

      rtDW.t_size = rtDW.jj_size;
      for (rtDW.i = 0; rtDW.i < rtDW.n_tmp_size_idx_0; rtDW.i++) {
        rtDW.t_data[rtDW.i] = (rtDW.n_tmp_data[rtDW.i] >= rtDW.x_current - 40.0);
      }

      if (rtDW.ii_size == rtDW.jj_size) {
        rtDW.b_size = rtDW.ii_size;
        rtDW.j = rtDW.ii_size;
        for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
          rtDW.b_data[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
            rtDW.b_tmp_data[rtDW.i] && rtDW.t_data[rtDW.i]);
        }
      } else {
        binary_expand_op_1(rtDW.b_data, &rtDW.b_size, rtDW.b_tmp_tmp_data,
                           &rtDW.b_tmp_tmp_size, rtDW.b_tmp_data, rtDW.t_data,
                           &rtDW.t_size);
      }

      rtDW.r_size = rtDW.jj_size;
      for (rtDW.i = 0; rtDW.i < rtDW.n_tmp_size_idx_0; rtDW.i++) {
        rtDW.r_data[rtDW.i] = (rtDW.n_tmp_data[rtDW.i] < rtDW.x_current + 40.0);
      }

      if (rtDW.ii_size == rtDW.jj_size) {
        rtDW.j = rtDW.ii_size;
        for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
          rtDW.b_tmp_tmp_data[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
            rtDW.b_tmp_data[rtDW.i] && rtDW.t_data[rtDW.i]);
        }
      } else {
        binary_expand_op(rtDW.b_tmp_tmp_data, &rtDW.b_tmp_tmp_size,
                         rtDW.b_tmp_data, rtDW.t_data, &rtDW.t_size);
      }

      if (rtDW.b_size == rtDW.jj_size) {
        rtDW.tmp_size_jz = rtDW.b_size;
        rtDW.j = rtDW.b_size;
        for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
          rtDW.tmp_data_h2[rtDW.i] = (rtDW.b_data[rtDW.i] && rtDW.r_data[rtDW.i]);
        }
      } else {
        and_o(rtDW.tmp_data_h2, &rtDW.tmp_size_jz, rtDW.b_data, &rtDW.b_size,
              rtDW.r_data, &rtDW.r_size);
      }

      rtDW.end = rtDW.tmp_size_jz - 1;
      rtDW.outputImage_tmp = 0;
      for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
        if (rtDW.tmp_data_h2[rtDW.i]) {
          rtDW.outputImage_tmp++;
        }
      }

      if (rtDW.outputImage_tmp > 30) {
        if (rtDW.b_size == rtDW.jj_size) {
          rtDW.tmp_size_n = rtDW.b_size;
          rtDW.j = rtDW.b_size;
          for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
            rtDW.tmp_data_mc[rtDW.i] = (rtDW.b_data[rtDW.i] &&
              rtDW.r_data[rtDW.i]);
          }
        } else {
          and_o(rtDW.tmp_data_mc, &rtDW.tmp_size_n, rtDW.b_data, &rtDW.b_size,
                rtDW.r_data, &rtDW.r_size);
        }

        rtDW.end = rtDW.tmp_size_n - 1;
        rtDW.outputImage_tmp = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
          if (rtDW.tmp_data_mc[rtDW.i]) {
            rtDW.outputImage_tmp++;
          }
        }

        rtDW.partialTrueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
          if (rtDW.tmp_data_mc[rtDW.i]) {
            rtDW.tmp_data_dh[rtDW.partialTrueCount] = rtDW.i;
            rtDW.partialTrueCount++;
          }
        }

        rtDW.jj_size_c = rtDW.outputImage_tmp;
        for (rtDW.i = 0; rtDW.i < rtDW.outputImage_tmp; rtDW.i++) {
          rtDW.jj_data[rtDW.i] = rtDW.jj_data_n[rtDW.tmp_data_dh[rtDW.i]];
        }

        rtDW.x_current = mean(rtDW.jj_data, &rtDW.jj_size_c);
      }

      rtDW.win_y_high = rtDW.count_right + 1.0;
      if (rtDW.b_size == rtDW.jj_size) {
        rtDW.tmp_size_oy = rtDW.b_size;
        rtDW.j = rtDW.b_size;
        for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
          rtDW.tmp_data_cs[rtDW.i] = (rtDW.b_data[rtDW.i] && rtDW.r_data[rtDW.i]);
        }
      } else {
        and_o(rtDW.tmp_data_cs, &rtDW.tmp_size_oy, rtDW.b_data, &rtDW.b_size,
              rtDW.r_data, &rtDW.r_size);
      }

      rtDW.end = rtDW.tmp_size_oy - 1;
      rtDW.outputImage_tmp = 0;
      for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
        if (rtDW.tmp_data_cs[rtDW.i]) {
          rtDW.outputImage_tmp++;
        }
      }

      rtDW.j = static_cast<int32_t>((1.0 - (rtDW.count_right + 1.0)) +
        static_cast<double>(rtDW.outputImage_tmp));
      for (rtDW.d_j = 0; rtDW.d_j < rtDW.j; rtDW.d_j++) {
        rtDW.win_y_low = rtDW.win_y_high + static_cast<double>(rtDW.d_j);
        rtDW.outputImage_tmp = rtDW.b_size;
        if (rtDW.b_size == rtDW.n_tmp_size_idx_0) {
          rtDW.tmp_size_m = rtDW.b_size;
          for (rtDW.i = 0; rtDW.i < rtDW.outputImage_tmp; rtDW.i++) {
            rtDW.tmp_data_pc[rtDW.i] = (rtDW.b_data[rtDW.i] &&
              rtDW.r_data[rtDW.i]);
          }
        } else {
          and_o(rtDW.tmp_data_pc, &rtDW.tmp_size_m, rtDW.b_data, &rtDW.b_size,
                rtDW.r_data, &rtDW.r_size);
        }

        rtDW.end = rtDW.b_tmp_tmp_size;
        if (rtDW.b_tmp_tmp_size == rtDW.n_tmp_size_idx_0) {
          rtDW.tmp_size_md = rtDW.b_tmp_tmp_size;
          for (rtDW.i = 0; rtDW.i < rtDW.end; rtDW.i++) {
            rtDW.tmp_data_p4u[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
              rtDW.r_data[rtDW.i]);
          }
        } else {
          and_o(rtDW.tmp_data_p4u, &rtDW.tmp_size_md, rtDW.b_tmp_tmp_data,
                &rtDW.b_tmp_tmp_size, rtDW.r_data, &rtDW.r_size);
        }

        rtDW.end = rtDW.tmp_size_md - 1;
        rtDW.partialTrueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
          if (rtDW.tmp_data_p4u[rtDW.i]) {
            rtDW.tmp_data[rtDW.partialTrueCount] = rtDW.i;
            rtDW.partialTrueCount++;
          }
        }

        rtDW.end = rtDW.tmp_size_m - 1;
        rtDW.partialTrueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
          if (rtDW.tmp_data_pc[rtDW.i]) {
            rtDW.tmp_data_o[rtDW.partialTrueCount] = rtDW.i;
            rtDW.partialTrueCount++;
          }
        }

        rtDW.right_lane_index[static_cast<int32_t>(rtDW.win_y_low) - 1] =
          rtDW.jj_data_n[rtDW.tmp_data_o[static_cast<int32_t>(rtDW.win_y_low) -
          1]];
        rtDW.ImageDataTypeConversion_b = rtDW.ii_data[rtDW.tmp_data[static_cast<
          int32_t>(rtDW.win_y_low) - 1]];
        rtDW.right_lane_index[static_cast<int32_t>(rtDW.win_y_low) + 99999] =
          rtDW.ImageDataTypeConversion_b;
        rtDW.outputImage_tmp = rtDW.b_size;
        if (rtDW.b_size == rtDW.n_tmp_size_idx_0) {
          rtDW.tmp_size_ja = rtDW.b_size;
          for (rtDW.i = 0; rtDW.i < rtDW.outputImage_tmp; rtDW.i++) {
            rtDW.tmp_data_jd[rtDW.i] = (rtDW.b_data[rtDW.i] &&
              rtDW.r_data[rtDW.i]);
          }
        } else {
          and_o(rtDW.tmp_data_jd, &rtDW.tmp_size_ja, rtDW.b_data, &rtDW.b_size,
                rtDW.r_data, &rtDW.r_size);
        }

        rtDW.end = rtDW.tmp_size_ja - 1;
        rtDW.partialTrueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
          if (rtDW.tmp_data_jd[rtDW.i]) {
            rtDW.tmp_data_bs[rtDW.partialTrueCount] = rtDW.i;
            rtDW.partialTrueCount++;
          }
        }

        rtDW.left_lane_index[static_cast<int32_t>(rtDW.win_y_low) - 1] =
          static_cast<double>(rtDW.jj_data_n[rtDW.tmp_data_bs
                              [static_cast<int32_t>(rtDW.win_y_low) - 1]]) -
          520.0;
        rtDW.left_lane_index[static_cast<int32_t>(rtDW.win_y_low) + 99999] =
          rtDW.ImageDataTypeConversion_b;
        rtDW.count_right++;
      }
    }

    if (rtDW.inlierNum == 2) {
      rtDW.win_y_low = rtDW.y_current - ((static_cast<double>(rtDW.svdRsltVar) +
        1.0) + 1.0) * 24.0;
      rtDW.win_y_high = rtDW.y_current - (static_cast<double>(rtDW.svdRsltVar) +
        1.0) * 24.0;
      rtDW.outputImage_tmp = rtDW.ii_size;
      rtDW.b_tmp_tmp_size = rtDW.ii_size;
      for (rtDW.i = 0; rtDW.i < rtDW.outputImage_tmp; rtDW.i++) {
        rtDW.j = rtDW.ii_data[rtDW.i];
        rtDW.b_tmp_tmp_data[rtDW.i] = (rtDW.j >= rtDW.win_y_low);
        rtDW.b_tmp_data[rtDW.i] = (rtDW.j < rtDW.win_y_high);
      }

      rtDW.j = rtDW.jj_size;
      rtDW.t_size = rtDW.jj_size;
      for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
        rtDW.t_data[rtDW.i] = (rtDW.jj_data_n[rtDW.i] >= rtDW.x_current - 40.0);
      }

      if (rtDW.ii_size == rtDW.jj_size) {
        rtDW.b_size = rtDW.ii_size;
        rtDW.j = rtDW.ii_size;
        for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
          rtDW.b_data[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
            rtDW.b_tmp_data[rtDW.i] && rtDW.t_data[rtDW.i]);
        }
      } else {
        binary_expand_op_1(rtDW.b_data, &rtDW.b_size, rtDW.b_tmp_tmp_data,
                           &rtDW.b_tmp_tmp_size, rtDW.b_tmp_data, rtDW.t_data,
                           &rtDW.t_size);
      }

      rtDW.j = rtDW.jj_size;
      rtDW.r_size = rtDW.jj_size;
      for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
        rtDW.r_data[rtDW.i] = (rtDW.jj_data_n[rtDW.i] < rtDW.x_current + 40.0);
      }

      if (rtDW.ii_size == rtDW.jj_size) {
        rtDW.j = rtDW.ii_size;
        for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
          rtDW.b_tmp_tmp_data[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
            rtDW.b_tmp_data[rtDW.i] && rtDW.t_data[rtDW.i]);
        }
      } else {
        binary_expand_op(rtDW.b_tmp_tmp_data, &rtDW.b_tmp_tmp_size,
                         rtDW.b_tmp_data, rtDW.t_data, &rtDW.t_size);
      }

      if (rtDW.b_size == rtDW.jj_size) {
        rtDW.tmp_size_ju = rtDW.b_size;
        rtDW.j = rtDW.b_size;
        for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
          rtDW.tmp_data_l5[rtDW.i] = (rtDW.b_data[rtDW.i] && rtDW.r_data[rtDW.i]);
        }
      } else {
        and_o(rtDW.tmp_data_l5, &rtDW.tmp_size_ju, rtDW.b_data, &rtDW.b_size,
              rtDW.r_data, &rtDW.r_size);
      }

      rtDW.end = rtDW.tmp_size_ju - 1;
      rtDW.outputImage_tmp = 0;
      for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
        if (rtDW.tmp_data_l5[rtDW.i]) {
          rtDW.outputImage_tmp++;
        }
      }

      if (rtDW.outputImage_tmp > 30) {
        if (rtDW.b_size == rtDW.jj_size) {
          rtDW.tmp_size_o = rtDW.b_size;
          rtDW.j = rtDW.b_size;
          for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
            rtDW.tmp_data_me[rtDW.i] = (rtDW.b_data[rtDW.i] &&
              rtDW.r_data[rtDW.i]);
          }
        } else {
          and_o(rtDW.tmp_data_me, &rtDW.tmp_size_o, rtDW.b_data, &rtDW.b_size,
                rtDW.r_data, &rtDW.r_size);
        }

        rtDW.end = rtDW.tmp_size_o - 1;
        rtDW.outputImage_tmp = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
          if (rtDW.tmp_data_me[rtDW.i]) {
            rtDW.outputImage_tmp++;
          }
        }

        rtDW.partialTrueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
          if (rtDW.tmp_data_me[rtDW.i]) {
            rtDW.tmp_data_ld[rtDW.partialTrueCount] = rtDW.i;
            rtDW.partialTrueCount++;
          }
        }

        rtDW.jj_size_c = rtDW.outputImage_tmp;
        for (rtDW.i = 0; rtDW.i < rtDW.outputImage_tmp; rtDW.i++) {
          rtDW.jj_data[rtDW.i] = rtDW.jj_data_n[rtDW.tmp_data_ld[rtDW.i]];
        }

        rtDW.x_current = mean(rtDW.jj_data, &rtDW.jj_size_c);
      }

      rtDW.win_y_high = rtDW.bestInlierDis + 1.0;
      if (rtDW.b_size == rtDW.jj_size) {
        rtDW.tmp_size_i = rtDW.b_size;
        rtDW.j = rtDW.b_size;
        for (rtDW.i = 0; rtDW.i < rtDW.j; rtDW.i++) {
          rtDW.tmp_data_h3[rtDW.i] = (rtDW.b_data[rtDW.i] && rtDW.r_data[rtDW.i]);
        }
      } else {
        and_o(rtDW.tmp_data_h3, &rtDW.tmp_size_i, rtDW.b_data, &rtDW.b_size,
              rtDW.r_data, &rtDW.r_size);
      }

      rtDW.end = rtDW.tmp_size_i - 1;
      rtDW.outputImage_tmp = 0;
      for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
        if (rtDW.tmp_data_h3[rtDW.i]) {
          rtDW.outputImage_tmp++;
        }
      }

      rtDW.j = static_cast<int32_t>((1.0 - (rtDW.bestInlierDis + 1.0)) +
        static_cast<double>(rtDW.outputImage_tmp));
      for (rtDW.d_j = 0; rtDW.d_j < rtDW.j; rtDW.d_j++) {
        rtDW.win_y_low = rtDW.win_y_high + static_cast<double>(rtDW.d_j);
        rtDW.outputImage_tmp = rtDW.b_size;
        if (rtDW.b_size == rtDW.r_size) {
          rtDW.tmp_size_nv = rtDW.b_size;
          for (rtDW.i = 0; rtDW.i < rtDW.outputImage_tmp; rtDW.i++) {
            rtDW.tmp_data_k[rtDW.i] = (rtDW.b_data[rtDW.i] && rtDW.r_data[rtDW.i]);
          }
        } else {
          and_o(rtDW.tmp_data_k, &rtDW.tmp_size_nv, rtDW.b_data, &rtDW.b_size,
                rtDW.r_data, &rtDW.r_size);
        }

        rtDW.end = rtDW.b_tmp_tmp_size;
        if (rtDW.b_tmp_tmp_size == rtDW.r_size) {
          rtDW.tmp_size_c = rtDW.b_tmp_tmp_size;
          for (rtDW.i = 0; rtDW.i < rtDW.end; rtDW.i++) {
            rtDW.tmp_data_px[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
              rtDW.r_data[rtDW.i]);
          }
        } else {
          and_o(rtDW.tmp_data_px, &rtDW.tmp_size_c, rtDW.b_tmp_tmp_data,
                &rtDW.b_tmp_tmp_size, rtDW.r_data, &rtDW.r_size);
        }

        rtDW.end = rtDW.tmp_size_nv - 1;
        rtDW.partialTrueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
          if (rtDW.tmp_data_k[rtDW.i]) {
            rtDW.tmp_data_dy[rtDW.partialTrueCount] = rtDW.i;
            rtDW.partialTrueCount++;
          }
        }

        rtDW.end = rtDW.tmp_size_c - 1;
        rtDW.partialTrueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
          if (rtDW.tmp_data_px[rtDW.i]) {
            rtDW.tmp_data_lx[rtDW.partialTrueCount] = rtDW.i;
            rtDW.partialTrueCount++;
          }
        }

        rtDW.left_lane_index[static_cast<int32_t>(rtDW.win_y_low) - 1] =
          rtDW.jj_data_n[rtDW.tmp_data_dy[static_cast<int32_t>(rtDW.win_y_low) -
          1]];
        rtDW.left_lane_index[static_cast<int32_t>(rtDW.win_y_low) + 99999] =
          rtDW.ii_data[rtDW.tmp_data_lx[static_cast<int32_t>(rtDW.win_y_low) - 1]];
        rtDW.outputImage_tmp = rtDW.b_size;
        if (rtDW.b_size == rtDW.r_size) {
          rtDW.tmp_size_m3 = rtDW.b_size;
          for (rtDW.i = 0; rtDW.i < rtDW.outputImage_tmp; rtDW.i++) {
            rtDW.tmp_data_a[rtDW.i] = (rtDW.b_data[rtDW.i] && rtDW.r_data[rtDW.i]);
          }
        } else {
          and_o(rtDW.tmp_data_a, &rtDW.tmp_size_m3, rtDW.b_data, &rtDW.b_size,
                rtDW.r_data, &rtDW.r_size);
        }

        rtDW.end = rtDW.b_tmp_tmp_size;
        if (rtDW.b_tmp_tmp_size == rtDW.r_size) {
          rtDW.tmp_size_h5 = rtDW.b_tmp_tmp_size;
          for (rtDW.i = 0; rtDW.i < rtDW.end; rtDW.i++) {
            rtDW.tmp_data_ek[rtDW.i] = (rtDW.b_tmp_tmp_data[rtDW.i] &&
              rtDW.r_data[rtDW.i]);
          }
        } else {
          and_o(rtDW.tmp_data_ek, &rtDW.tmp_size_h5, rtDW.b_tmp_tmp_data,
                &rtDW.b_tmp_tmp_size, rtDW.r_data, &rtDW.r_size);
        }

        rtDW.end = rtDW.tmp_size_m3 - 1;
        rtDW.partialTrueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
          if (rtDW.tmp_data_a[rtDW.i]) {
            rtDW.tmp_data_b[rtDW.partialTrueCount] = rtDW.i;
            rtDW.partialTrueCount++;
          }
        }

        rtDW.end = rtDW.tmp_size_h5 - 1;
        rtDW.partialTrueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
          if (rtDW.tmp_data_ek[rtDW.i]) {
            rtDW.tmp_data_n[rtDW.partialTrueCount] = rtDW.i;
            rtDW.partialTrueCount++;
          }
        }

        rtDW.right_lane_index[static_cast<int32_t>(rtDW.win_y_low) - 1] =
          static_cast<double>(rtDW.jj_data_n[rtDW.tmp_data_b[static_cast<int32_t>
                              (rtDW.win_y_low) - 1]]) + 520.0;
        rtDW.right_lane_index[static_cast<int32_t>(rtDW.win_y_low) + 99999] =
          rtDW.ii_data[rtDW.tmp_data_n[static_cast<int32_t>(rtDW.win_y_low) - 1]];
        rtDW.bestInlierDis++;
      }
    }
  }

  if (rtDW.bestInlierDis < 1.0) {
    rtDW.svdRsltVar = -1;
  } else {
    rtDW.svdRsltVar = static_cast<int32_t>(rtDW.bestInlierDis) - 1;
  }

  if (rtDW.count_right < 1.0) {
    rtDW.inlierNum = -1;
  } else {
    rtDW.inlierNum = static_cast<int32_t>(rtDW.count_right) - 1;
  }

  rtDW.left_lane_index_size = rtDW.svdRsltVar + 1;
  rtDW.left_lane_index_size_c = rtDW.svdRsltVar + 1;
  if (rtDW.svdRsltVar >= 0) {
    std::memcpy(&rtDW.left_lane_index_data[0], &rtDW.left_lane_index[100000],
                static_cast<uint32_t>(rtDW.svdRsltVar + 1) * sizeof(double));
  }

  if (rtDW.svdRsltVar >= 0) {
    std::memcpy(&rtDW.left_lane_index_data_m[0], &rtDW.left_lane_index[0],
                static_cast<uint32_t>(rtDW.svdRsltVar + 1) * sizeof(double));
  }

  polyfit(rtDW.left_lane_index_data, &rtDW.left_lane_index_size,
          rtDW.left_lane_index_data_m, &rtDW.left_lane_index_size_c, &rtDW.p[0]);
  rtDW.left_lane_index_size = rtDW.inlierNum + 1;
  rtDW.left_lane_index_size_c = rtDW.inlierNum + 1;
  if (rtDW.inlierNum >= 0) {
    std::memcpy(&rtDW.left_lane_index_data[0], &rtDW.right_lane_index[100000],
                static_cast<uint32_t>(rtDW.inlierNum + 1) * sizeof(double));
  }

  if (rtDW.inlierNum >= 0) {
    std::memcpy(&rtDW.left_lane_index_data_m[0], &rtDW.right_lane_index[0],
                static_cast<uint32_t>(rtDW.inlierNum + 1) * sizeof(double));
  }

  polyfit(rtDW.left_lane_index_data, &rtDW.left_lane_index_size,
          rtDW.left_lane_index_data_m, &rtDW.left_lane_index_size_c, &rtDW.b_p[0]);
  for (rtDW.i = 0; rtDW.i < 481; rtDW.i++) {
    rtDW.xleft[rtDW.i] = rtDW.p[0];
  }

  for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 2; rtDW.svdRsltVar++) {
    rtDW.count_right = rtDW.p[rtDW.svdRsltVar + 1];
    for (rtDW.i = 0; rtDW.i < 481; rtDW.i++) {
      rtDW.xleft[rtDW.i] = static_cast<double>(rtDW.i) * rtDW.xleft[rtDW.i] +
        rtDW.count_right;
    }
  }

  for (rtDW.i = 0; rtDW.i < 481; rtDW.i++) {
    rtDW.xright[rtDW.i] = rtDW.b_p[0];
  }

  for (rtDW.svdRsltVar = 0; rtDW.svdRsltVar < 2; rtDW.svdRsltVar++) {
    rtDW.count_right = rtDW.b_p[rtDW.svdRsltVar + 1];
    for (rtDW.i = 0; rtDW.i < 481; rtDW.i++) {
      rtDW.xright[rtDW.i] = static_cast<double>(rtDW.i) * rtDW.xright[rtDW.i] +
        rtDW.count_right;
    }
  }

  rtDW.x_current = 320.0 - (rtDW.xleft[480] + rtDW.xright[480]) / 2.0;

  // Send: '<Root>/Event Send'
  // Send event
  ProvidedPort->Out1.Send(rtDW.x_current);

  // Copy the image from input to output.
  // Update view port.
  // Draw all rectangles.
  // Calculate FillColor times Opacity.
  // Calculate One minus Opacity.
  // Update view port.
  // Draw all circles.
  // Copy the image from input to output.
  // Calculate FillColor times Opacity.
  // Calculate One minus Opacity.
  // Update view port.
  // Draw all circles.
}

// Model initialize function
void Rpi_cam::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(double));

  {
    static const std::array<int8_t, 9> self_T{ { 1, 0, 0, 0, 1, 0, 0, 0, 1 } };

    int32_t i;

    // Start for S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' 
    srand(clock());

    // Calculate FillColor times Opacity.
    // Calculate One minus Opacity.
    // Calculate FillColor times Opacity.
    // Calculate One minus Opacity.

    // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
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

    // Start for MATLABSystem: '<S4>/Warp'
    rtDW.obj_k.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      rtDW.obj_k.TformProjective.T[i] = self_T[i];
    }

    // End of Start for MATLABSystem: '<S4>/Warp'
    // Initialize service provider instance - ProvidedPort
    ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::
      com::InstanceIdentifier(ara::core::StringView("1")), ara::com::
      MethodCallProcessingMode::kEventSingleThread);
    ProvidedPort->OfferService();
  }
}

// Model terminate function
void Rpi_cam::terminate()
{
  // Terminate for MATLABSystem: '<Root>/V4L2 Video Capture'
  if (!rtDW.obj.matlabCodegenIsDeleted) {
    rtDW.obj.matlabCodegenIsDeleted = true;
    if ((rtDW.obj.isInitialized == 1) && rtDW.obj.isSetupComplete) {
      EXT_webcamTerminate(0, 0);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/V4L2 Video Capture'
  ProvidedPort->StopOfferService();
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
