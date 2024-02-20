//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: LKAS.cpp
//
// Code generated for Simulink model 'LKAS'.
//
// Model version                  : 12.33
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Mon Feb 19 16:04:43 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "LKAS.h"
#include <stdint.h>
#include <stdbool.h>
#include <cstring>
#include <stddef.h>
#include <cmath>
#include <emmintrin.h>
#define NumBitsPerChar                 8U

extern void makeConstraintMatrix_Projective_D_D(const double pts1[], const
  double pts2[], uint32_t sampleNum, uint32_t maxSampleNum, double constraint[]);
extern void normPts_D_D(const double pts[], const uint32_t samples[], uint32_t
  ptsNum, uint32_t sampleNum, double ptsNorm[], double scale[], double cents[]);
extern void QRV2Norm_double(const double V[], int32_t N, double v2norm[]);
extern void QRDC_double(double xVec[], double qrAux[], int32_t jpvt[], double
  work[], int32_t M, int32_t N);
extern void QRCompQy_double(double qr[], const double qrAuxj[], double y[],
  int32_t n, int32_t j);
extern void QRSL1_double(double qr[], const double qrAux[], double y[], int32_t
  n, int32_t k);
extern void QRE_double(double outQ[], double outR[], double outE[], double
  qrAux[], double work[], int32_t jpvt[], double sPtr[], int32_t M, int32_t N,
  bool economy);
extern double rt_hypotd_snf(double u0, double u1);
extern "C"
{
  double rtInf;
  double rtMinusInf;
  double rtNaN;
  float rtInfF;
  float rtMinusInfF;
  float rtNaNF;
}

extern "C"
{
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static double rtGetInf(void)
  {
    size_t bitsPerReal{ sizeof(double) * (NumBitsPerChar) };

    double inf{ 0.0 };

    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        double fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static float rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static double rtGetMinusInf(void)
  {
    size_t bitsPerReal{ sizeof(double) * (NumBitsPerChar) };

    double minf{ 0.0 };

    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        double fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static float rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}

extern "C"
{
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static double rtGetNaN(void)
  {
    size_t bitsPerReal{ sizeof(double) * (NumBitsPerChar) };

    double nan{ 0.0 };

    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        double fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static float rtGetNaNF(void)
  {
    IEEESingle nanF{ { 0.0F } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}

extern "C"
{
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  static void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  static bool rtIsInf(double value)
  {
    return (bool)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  static bool rtIsInfF(float value)
  {
    return (bool)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  static bool rtIsNaN(double value)
  {
    bool result{ (bool) 0 };

    size_t bitsPerReal{ sizeof(double) * (NumBitsPerChar) };

    if (bitsPerReal == 32U) {
      result = rtIsNaNF((float)value);
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        double fltVal;
      } tmpVal;

      tmpVal.fltVal = value;
      result = (bool)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                      ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                       (tmpVal.bitVal.words.wordL != 0) ));
    }

    return result;
  }

  // Test if single-precision value is not a number
  static bool rtIsNaNF(float value)
  {
    IEEESingle tmp;
    tmp.wordL.wordLreal = value;
    return (bool)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                  (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
  }
}

void makeConstraintMatrix_Projective_D_D(const double pts1[], const double pts2[],
  uint32_t sampleNum, uint32_t maxSampleNum, double constraint[])
{
  uint32_t j;
  uint32_t k;

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

void normPts_D_D(const double pts[], const uint32_t samples[], uint32_t ptsNum,
                 uint32_t sampleNum, double ptsNorm[], double scale[], double
                 cents[])
{
  double sumDis;

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

void QRV2Norm_double(const double V[], int32_t N, double v2norm[])
{
  double tmpQRSL;
  int32_t vi;

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
  tmpQRSL = 0.0;
  vi = 0;
  for (int32_t i{0}; i < N; i++) {
    double tmp;
    double tmp_0;
    tmp = tmpQRSL;
    tmp_0 = std::abs(V[vi]);
    if (tmpQRSL > tmp_0) {
      tmpQRSL = V[vi] / tmpQRSL;
      tmpQRSL = std::sqrt(tmpQRSL * tmpQRSL + 1.0) * tmp;
    } else if (V[vi] == 0.0) {
      tmpQRSL = 0.0;
    } else {
      tmpQRSL /= V[vi];
      tmpQRSL = std::sqrt(tmpQRSL * tmpQRSL + 1.0) * tmp_0;
    }

    vi++;
  }

  v2norm[0U] = tmpQRSL;

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

void QRDC_double(double xVec[], double qrAux[], int32_t jpvt[], double work[],
                 int32_t M, int32_t N)
{
  double maxnrm;
  double nrmxl;
  double t;
  double tt;
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

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
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
          maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = maxnrm;
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
          maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = maxnrm;
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
    QRV2Norm_double(&xVec[j * M], M, &qrAux[j]);
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
      maxnrm = 0.0;
      maxj = l;
      for (j = l; j <= pu; j++) {
        if (qrAux[j] > maxnrm) {
          maxnrm = qrAux[j];
          maxj = j;
        }
      }

      if (maxj != l) {
        // Swap columns l and maxj
        px = l * M;
        px2 = maxj * M;
        for (i = M; i > 0; i--) {
          maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = maxnrm;
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
      QRV2Norm_double(&xVec[maxj], mml, &nrmxl);
      maxnrm = std::abs(nrmxl);
      if (maxnrm != 0.0) {
        if (std::abs(xVec[maxj]) != 0.0) {
          if (xVec[maxj] >= 0.0) {
            nrmxl = maxnrm;
          } else {
            nrmxl = -maxnrm;
          }
        }

        // Check if it's safe to multiply by 1/nrmxl instead of dividing by nrmxl 
        px2 = maxj;
        if (5.0E-20 * nrmxl != 0.0) {
          maxnrm = 1.0 / nrmxl;
          for (i = mml; i > 0; i--) {
            xVec[px2] *= maxnrm;
            px2++;
          }
        } else {
          for (i = mml; i > 0; i--) {
            xVec[px2] /= nrmxl;
            px2++;
          }
        }

        xVec[maxj]++;

        // apply the transformation to the remaining columns, updating the norms. 
        for (j = l + 1; j < N; j++) {
          plj = j * M + l;
          px2 = plj;
          t = 0.0;
          for (i = mml; i > 0; i--) {
            t -= xVec[px] * xVec[px2];
            px++;
            px2++;
          }

          px = maxj;
          px2 = plj;
          t /= xVec[maxj];
          for (i = mml; i > 0; i--) {
            xVec[px2] += t * xVec[px];
            px++;
            px2++;
          }

          px = maxj;
          px2 = 0;
          if (qrAux[j] == 0.0) {
            px2 = 1;
          }

          if ((j >= pl) && (j <= pu) && (px2 == 0)) {
            maxnrm = std::abs(xVec[plj]) / qrAux[j];
            tt = 1.0 - maxnrm * maxnrm;
            if (tt < 0.0) {
              tt = 0.0;
            }

            t = tt;
            maxnrm = qrAux[j] / work[j];
            tt = 0.05 * tt * maxnrm * maxnrm + 1.0;
            if (tt != 1.0) {
              qrAux[j] *= std::sqrt(t);
            } else {
              QRV2Norm_double(&xVec[plj + 1], mml - 1, &maxnrm);
              qrAux[j] = maxnrm;
              work[j] = qrAux[j];
            }
          }
        }

        // save the transformation.
        qrAux[l] = xVec[px];
        xVec[px] = -nrmxl;
      }
    }
  }

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

void QRCompQy_double(double qr[], const double qrAuxj[], double y[], int32_t n,
                     int32_t j)
{
  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

void QRSL1_double(double qr[], const double qrAux[], double y[], int32_t n,
                  int32_t k)
{
  int32_t j;
  int32_t pqraux;
  int32_t y_0;

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

void QRE_double(double outQ[], double outR[], double outE[], double qrAux[],
                double work[], int32_t jpvt[], double sPtr[], int32_t M, int32_t
                N, bool economy)
{
  int32_t L;
  int32_t L_tmp;
  int32_t j;
  int32_t ps;

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
  QRDC_double(&outR[0], &qrAux[0], &jpvt[0], &work[0], M, N);

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
  for (j = 0; j < M * L; j++) {
    outQ[j] = 0.0;
  }

  for (j = 0; j < L; j++) {
    outQ[L_tmp] = 1.0;
    L_tmp = (L_tmp + M) + 1;
  }

  // Convert cols of identity into cols of q. Use info stored in lower triangle of r and in vector qraux to work on columns of identity matrix I and transform them into q*I(:,j) i.e. the columns of q. 
  L_tmp = 0;
  for (j = 0; j < L; j++) {
    QRSL1_double(&outR[0], &qrAux[0], &outQ[L_tmp], M, N);
    L_tmp += M;
  }

  if (economy && (M > N)) {
    // Copy upper triangle of r to s
    L = 0;
    ps = 0;
    for (j = 1; j - 1 < N; j++) {
      for (L_tmp = 0; L_tmp < j; L_tmp++) {
        sPtr[ps] = outR[L];
        ps++;
        L++;
      }

      L = (L + M) - j;
      for (L_tmp = 0; L_tmp < N - j; L_tmp++) {
        sPtr[ps] = 0.0;
        ps++;
      }
    }
  } else {
    // Zero strict lower triangle of r
    L = M * N - 1;
    for (j = N; j - 1 >= 0; j--) {
      for (L_tmp = M; L_tmp > j; L_tmp--) {
        outR[L] = 0.0;
        L--;
      }

      if (M < j) {
        L -= M;
      } else {
        L -= j;
      }
    }
  }

  // form permutation vector e
  L = 0;
  L_tmp = 0;
  for (j = 0; j < N; j++) {
    outE[L] = jpvt[L_tmp] + 1;
    L_tmp = L + 1;
    L++;
  }

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

void LKAS::Warp_stepImpl(vision_internal_blocks_Warp *b_this, const bool Image
  [900000], const double input2[9], bool Jout[900000])
{
  __m128d tmp_0;
  __m128d tmp_1;
  double B_0[9];
  double x_0[9];
  double b_inputImageSize[3];
  double b_outputImageSize[2];
  double absx11;
  double absx21;
  double absx31;
  double b_B_idx_0;
  double b_B_idx_1;
  double b_B_idx_2;
  int32_t p1;
  int32_t p2;
  int32_t p3;
  bool x[2];
  bool guard1;

  // Start for MATLABSystem: '<S2>/Warp'
  std::memcpy(&b_this->TformProjective.T[0], &input2[0], 9U * sizeof(double));
  for (p1 = 0; p1 < 3; p1++) {
    B_0[3 * p1] = b_this->TformProjective.T[p1];
    B_0[3 * p1 + 1] = b_this->TformProjective.T[p1 + 3];
    B_0[3 * p1 + 2] = b_this->TformProjective.T[p1 + 6];
  }

  for (p1 = 0; p1 < 1200; p1++) {
    for (p2 = 0; p2 < 750; p2++) {
      p3 = 750 * p1 + p2;

      // Start for MATLABSystem: '<S2>/Warp'
      rtDW.xp[p3] = static_cast<double>(p1) + 1.0;
      rtDW.yp[p3] = static_cast<double>(p2) + 1.0;
    }
  }

  for (p1 = 0; p1 <= 899998; p1 += 2) {
    // Start for MATLABSystem: '<S2>/Warp'
    tmp_0 = _mm_loadu_pd(&rtDW.xp[p1]);
    tmp_1 = _mm_set1_pd(0.5);

    // Start for MATLABSystem: '<S2>/Warp'
    _mm_storeu_pd(&rtDW.xp[p1], _mm_add_pd(_mm_sub_pd(tmp_0, tmp_1), tmp_1));
    tmp_0 = _mm_loadu_pd(&rtDW.yp[p1]);
    _mm_storeu_pd(&rtDW.yp[p1], _mm_add_pd(_mm_sub_pd(tmp_0, tmp_1), tmp_1));
  }

  // Start for MATLABSystem: '<S2>/Warp'
  guard1 = false;
  if (B_0[8] == 1.0) {
    bool exitg1;
    bool y;
    x[0] = (B_0[2] == 0.0);
    x[1] = (B_0[5] == 0.0);
    y = true;
    p1 = 0;
    exitg1 = false;
    while ((!exitg1) && (p1 < 2)) {
      if (!x[p1]) {
        y = false;
        exitg1 = true;
      } else {
        p1++;
      }
    }

    if (y) {
      if (std::abs(B_0[1]) > std::abs(B_0[0])) {
        absx11 = B_0[0] / B_0[1];
        absx21 = 1.0 / (absx11 * B_0[4] - B_0[3]);
        b_B_idx_0 = B_0[4] / B_0[1] * absx21;
        b_B_idx_1 = -absx21;
        b_B_idx_2 = -B_0[3] / B_0[1] * absx21;
        absx21 *= absx11;
      } else {
        absx11 = B_0[1] / B_0[0];
        absx21 = 1.0 / (B_0[4] - absx11 * B_0[3]);
        b_B_idx_0 = B_0[4] / B_0[0] * absx21;
        b_B_idx_1 = -absx11 * absx21;
        b_B_idx_2 = -B_0[3] / B_0[0] * absx21;
      }

      absx11 = B_0[6];
      absx31 = B_0[7];
      for (p1 = 0; p1 <= 899998; p1 += 2) {
        tmp_0 = _mm_loadu_pd(&rtDW.xp[p1]);
        tmp_0 = _mm_sub_pd(tmp_0, _mm_set1_pd(absx11));
        tmp_1 = _mm_loadu_pd(&rtDW.yp[p1]);
        tmp_1 = _mm_sub_pd(tmp_1, _mm_set1_pd(absx31));
        _mm_storeu_pd(&rtDW.yp[p1], tmp_1);
        _mm_storeu_pd(&rtDW.b_varargout_1[p1], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
          (b_B_idx_0), tmp_0), _mm_mul_pd(_mm_set1_pd(b_B_idx_2), tmp_1)));
        _mm_storeu_pd(&rtDW.xp[p1], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(b_B_idx_1),
          tmp_0), _mm_mul_pd(_mm_set1_pd(absx21), tmp_1)));
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    double B_1;
    double B_2;
    double B_3;
    std::memcpy(&x_0[0], &B_0[0], 9U * sizeof(double));
    p1 = 1;
    p2 = 3;
    p3 = 6;
    absx11 = std::abs(B_0[0]);
    absx21 = std::abs(B_0[1]);
    absx31 = std::abs(B_0[2]);
    if ((absx21 > absx11) && (absx21 > absx31)) {
      p1 = 4;
      p2 = 0;
      x_0[0] = B_0[1];
      x_0[1] = B_0[0];
      x_0[3] = B_0[4];
      x_0[4] = B_0[3];
      x_0[6] = B_0[7];
      x_0[7] = B_0[6];
    } else if (absx31 > absx11) {
      p1 = 7;
      p3 = 0;
      x_0[0] = B_0[2];
      x_0[2] = B_0[0];
      x_0[3] = B_0[5];
      x_0[5] = B_0[3];
      x_0[6] = B_0[8];
      x_0[8] = B_0[6];
    }

    absx31 = x_0[1] / x_0[0];
    x_0[1] = absx31;
    absx11 = x_0[2] / x_0[0];
    x_0[2] = absx11;
    x_0[4] -= absx31 * x_0[3];
    x_0[5] -= absx11 * x_0[3];
    x_0[7] -= absx31 * x_0[6];
    x_0[8] -= absx11 * x_0[6];
    if (std::abs(x_0[5]) > std::abs(x_0[4])) {
      int32_t itmp;
      itmp = p2;
      p2 = p3;
      p3 = itmp;
      x_0[1] = absx11;
      x_0[2] = absx31;
      absx11 = x_0[4];
      x_0[4] = x_0[5];
      x_0[5] = absx11;
      absx11 = x_0[7];
      x_0[7] = x_0[8];
      x_0[8] = absx11;
    }

    absx31 = x_0[5] / x_0[4];
    x_0[8] -= absx31 * x_0[7];
    absx11 = (x_0[1] * absx31 - x_0[2]) / x_0[8];
    absx21 = -(x_0[7] * absx11 + x_0[1]) / x_0[4];
    B_0[p1 - 1] = ((1.0 - x_0[3] * absx21) - x_0[6] * absx11) / x_0[0];
    B_0[p1] = absx21;
    B_0[p1 + 1] = absx11;
    absx11 = -absx31 / x_0[8];
    absx21 = (1.0 - x_0[7] * absx11) / x_0[4];
    B_0[p2] = -(x_0[3] * absx21 + x_0[6] * absx11) / x_0[0];
    B_0[p2 + 1] = absx21;
    B_0[p2 + 2] = absx11;
    absx11 = 1.0 / x_0[8];
    absx21 = -x_0[7] * absx11 / x_0[4];
    B_0[p3] = -(x_0[3] * absx21 + x_0[6] * absx11) / x_0[0];
    B_0[p3 + 1] = absx21;
    B_0[p3 + 2] = absx11;
    absx11 = B_0[2];
    absx31 = B_0[5];
    absx21 = B_0[0];
    b_B_idx_0 = B_0[3];
    b_B_idx_1 = B_0[1];
    b_B_idx_2 = B_0[4];
    B_1 = B_0[8];
    B_2 = B_0[6];
    B_3 = B_0[7];
    for (p1 = 0; p1 <= 899998; p1 += 2) {
      __m128d tmp;
      tmp_0 = _mm_loadu_pd(&rtDW.xp[p1]);
      tmp_1 = _mm_loadu_pd(&rtDW.yp[p1]);
      tmp = _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd(absx11), tmp_0),
        _mm_mul_pd(_mm_set1_pd(absx31), tmp_1)), _mm_set1_pd(B_1));
      _mm_storeu_pd(&rtDW.b_varargout_1[p1], _mm_div_pd(_mm_add_pd(_mm_add_pd
        (_mm_mul_pd(_mm_set1_pd(absx21), tmp_0), _mm_mul_pd(_mm_set1_pd
        (b_B_idx_0), tmp_1)), _mm_set1_pd(B_2)), tmp));
      _mm_storeu_pd(&rtDW.xp[p1], _mm_div_pd(_mm_add_pd(_mm_add_pd(_mm_mul_pd
        (_mm_set1_pd(b_B_idx_1), tmp_0), _mm_mul_pd(_mm_set1_pd(b_B_idx_2),
        tmp_1)), _mm_set1_pd(B_3)), tmp));
    }
  }

  for (p1 = 0; p1 < 900000; p1++) {
    // Start for MATLABSystem: '<S2>/Warp'
    rtDW.b_varargout_1[p1] = (rtDW.b_varargout_1[p1] - 0.5) + 0.5;
    rtDW.xp[p1] = (rtDW.xp[p1] - 0.5) + 0.5;
    rtDW.inputImage_[p1] = Image[p1];
  }

  uint8_t fillValues;
  fillValues = 0U;

  // Start for MATLABSystem: '<S2>/Warp'
  b_inputImageSize[0] = 750.0;
  b_inputImageSize[1] = 1200.0;
  b_inputImageSize[2] = 1.0;
  b_outputImageSize[0] = 750.0;
  b_outputImageSize[1] = 1200.0;
  imterp2d64f_uint8(&rtDW.inputImage_[0], &b_inputImageSize[0], &rtDW.xp[0],
                    &rtDW.b_varargout_1[0], &b_outputImageSize[0], 2.0, true,
                    &fillValues, &rtDW.outputImage[0]);
  for (p1 = 0; p1 < 900000; p1++) {
    // Start for MATLABSystem: '<S2>/Warp'
    Jout[p1] = (rtDW.outputImage[p1] > 0.5);
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
void LKAS::do_vectors(const int32_t a_data[], const int32_t *a_size, const
                      int32_t b_data[], const int32_t *b_size, int32_t c_data[],
                      int32_t *c_size, int32_t ia_data[], int32_t *ia_size,
                      int32_t ib_data[], int32_t *ib_size)
{
  int32_t c_ialast;
  int32_t iafirst;
  int32_t ialast;
  int32_t ibfirst;
  int32_t iblast;
  int32_t nc;
  int32_t ncmax;
  int32_t nia;
  int32_t nib;
  ncmax = *a_size + *b_size;
  *c_size = ncmax;
  *ia_size = *a_size;
  *ib_size = *b_size;
  nc = -1;
  nia = -1;
  nib = 0;
  iafirst = 1;
  ialast = 0;
  ibfirst = 0;
  iblast = 0;
  while ((ialast + 1 <= *a_size) && (iblast + 1 <= *b_size)) {
    int32_t ak;
    int32_t b_iblast;
    int32_t bk;
    c_ialast = ialast + 1;
    ak = a_data[ialast];
    while ((c_ialast < *a_size) && (a_data[c_ialast] == ak)) {
      c_ialast++;
    }

    ialast = c_ialast - 1;
    b_iblast = iblast + 1;
    bk = b_data[iblast];
    while ((b_iblast < *b_size) && (b_data[b_iblast] == bk)) {
      b_iblast++;
    }

    iblast = b_iblast - 1;
    if (ak == bk) {
      nc++;
      c_data[nc] = ak;
      nia++;
      ia_data[nia] = iafirst;
      ialast = c_ialast;
      iafirst = c_ialast + 1;
      iblast = b_iblast;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      nc++;
      nia++;
      c_data[nc] = ak;
      ia_data[nia] = iafirst;
      ialast = c_ialast;
      iafirst = c_ialast + 1;
    } else {
      nc++;
      nib++;
      c_data[nc] = bk;
      ib_data[nib - 1] = ibfirst + 1;
      iblast = b_iblast;
      ibfirst = b_iblast;
    }
  }

  while (ialast + 1 <= *a_size) {
    c_ialast = ialast + 1;
    while ((c_ialast < *a_size) && (a_data[c_ialast] == a_data[ialast])) {
      c_ialast++;
    }

    nc++;
    nia++;
    c_data[nc] = a_data[ialast];
    ia_data[nia] = iafirst;
    ialast = c_ialast;
    iafirst = c_ialast + 1;
  }

  while (iblast + 1 <= *b_size) {
    iafirst = iblast + 1;
    while ((iafirst < *b_size) && (b_data[iafirst] == b_data[iblast])) {
      iafirst++;
    }

    nc++;
    nib++;
    c_data[nc] = b_data[iblast];
    ib_data[nib - 1] = ibfirst + 1;
    iblast = iafirst;
    ibfirst = iafirst;
  }

  if (*a_size > 0) {
    if (nia + 1 < 1) {
      *ia_size = 0;
    } else {
      *ia_size = nia + 1;
    }
  }

  if (*b_size > 0) {
    if (nib < 1) {
      *ib_size = 0;
    } else {
      *ib_size = nib;
    }
  }

  if (ncmax > 0) {
    if (nc + 1 < 1) {
      *c_size = 0;
    } else {
      *c_size = nc + 1;
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
void LKAS::findpeaks(const double Yin[1200], double Ypk_data[], int32_t
                     Ypk_size[2], double Xpk_data[], int32_t Xpk_size[2])
{
  double Yin_0;
  double ykfirst;
  int32_t fPk;
  int32_t ib_size;
  int32_t k;
  int32_t kfirst;
  int32_t nPk;
  char dir;
  char previousdir;
  bool isinfykfirst;
  nPk = -1;
  dir = 'n';
  kfirst = -1;
  ykfirst = (rtInf);
  isinfykfirst = true;
  for (k = 0; k < 1200; k++) {
    Yin_0 = Yin[k];
    if (Yin_0 != ykfirst) {
      previousdir = dir;
      if (isinfykfirst) {
        dir = 'n';
      } else if (Yin_0 < ykfirst) {
        dir = 'd';
        if (previousdir == 'i') {
          nPk++;
          rtDW.fPk_data[nPk] = kfirst + 1;
        }
      } else {
        dir = 'i';
      }

      ykfirst = Yin_0;
      kfirst = k;
      isinfykfirst = false;
    }
  }

  if (nPk + 1 < 1) {
    nPk = -1;
  }

  kfirst = 0;
  for (k = 0; k <= nPk; k++) {
    fPk = rtDW.fPk_data[k];
    if (Yin[fPk - 1] - std::fmax(Yin[fPk - 2], Yin[fPk]) >= 0.0) {
      kfirst++;
      rtDW.b_iPk_data[kfirst - 1] = fPk;
    }
  }

  if (kfirst < 1) {
    k = 0;
  } else {
    k = kfirst;
  }

  kfirst = 0;
  do_vectors(rtDW.b_iPk_data, &k, rtDW.b_iPk_data, &kfirst, rtDW.iPk_data, &nPk,
             rtDW.fPk_data, &fPk, rtDW.ib_data, &ib_size);
  if (nPk > 0) {
    rtDW.y_data[0] = 1;
    kfirst = 1;
    for (k = 2; k <= nPk; k++) {
      kfirst++;
      rtDW.y_data[k - 1] = static_cast<int16_t>(kfirst);
    }
  }

  if (nPk - 1 >= 0) {
    std::memcpy(&rtDW.idx_data[0], &rtDW.y_data[0], static_cast<uint32_t>(nPk) *
                sizeof(int16_t));
  }

  if (nPk > 1200) {
    fPk = 1200;
  } else {
    fPk = nPk;
  }

  if (fPk < 1) {
    nPk = -1;
  } else {
    nPk = fPk - 1;
  }

  k = nPk + 1;
  for (kfirst = 0; kfirst <= nPk; kfirst++) {
    rtDW.b_iPk_data[kfirst] = rtDW.iPk_data[rtDW.idx_data[kfirst] - 1];
  }

  Ypk_size[0] = 1;
  Ypk_size[1] = nPk + 1;
  nPk++;
  Xpk_size[0] = 1;
  Xpk_size[1] = k;
  for (kfirst = 0; kfirst < nPk; kfirst++) {
    k = rtDW.b_iPk_data[kfirst];
    Ypk_data[kfirst] = Yin[k - 1];
    Xpk_data[kfirst] = static_cast<int16_t>(static_cast<int16_t>(k - 1) + 1);
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
void LKAS::eml_find(const bool x[900000], int32_t i_data[], int32_t *i_size,
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
  while ((!exitg1) && (jj <= 1200)) {
    bool guard1;
    guard1 = false;
    if (x[((jj - 1) * 750 + ii) - 1]) {
      idx++;
      i_data[idx - 1] = ii;
      j_data[idx - 1] = jj;
      if (idx >= 900000) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
      if (ii > 750) {
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

void LKAS::binary_expand_op_1(bool in1_data[], int32_t *in1_size, const bool
  in2_data[], const int32_t *in2_size, const double in3_data[], const int32_t
  *in3_size, double in4)
{
  int32_t loop_ub;
  int32_t stride_0_0;
  int32_t stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function3'
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
    in1_data[i] = (in2_data[i * stride_0_0] && (in3_data[i * stride_1_0] >= in4
      - 80.0));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function3'
}

void LKAS::binary_expand_op(bool in1_data[], int32_t *in1_size, const double
  in2_data[], const int32_t *in2_size, double in3)
{
  int32_t in1_size_idx_0;
  int32_t stride_0_0;
  int32_t stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function3'
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
    rtDW.in1_data[i] = (in1_data[i * stride_0_0] && (in2_data[i * stride_1_0] >=
      in3 - 80.0));
  }

  *in1_size = in1_size_idx_0;
  if (in1_size_idx_0 - 1 >= 0) {
    std::memcpy(&in1_data[0], &rtDW.in1_data[0], static_cast<uint32_t>
                (in1_size_idx_0) * sizeof(bool));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function3'
}

void LKAS::and_j(bool in1_data[], int32_t *in1_size, const bool in2_data[],
                 const int32_t *in2_size, const bool in3_data[], const int32_t
                 *in3_size)
{
  int32_t loop_ub;
  int32_t stride_0_0;
  int32_t stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function3'
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

  // End of MATLAB Function: '<S2>/MATLAB Function3'
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
double LKAS::mean(const double x_data[], const int32_t *x_size)
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

// Function for MATLAB Function: '<S2>/MATLAB Function3'
double LKAS::xnrm2(int32_t n, const double x_data[], int32_t ix0)
{
  double y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x_data[ix0 - 1]);
    } else {
      double scale;
      int32_t kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_t k{ix0}; k <= kend; k++) {
        double absxk;
        absxk = std::abs(x_data[k - 1]);
        if (absxk > scale) {
          double t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          double t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
void LKAS::xswap(int32_t n, double x_data[], int32_t ix0, int32_t iy0)
{
  for (int32_t k{0}; k < n; k++) {
    double temp;
    int32_t temp_tmp;
    int32_t tmp;
    temp_tmp = (ix0 + k) - 1;
    temp = x_data[temp_tmp];
    tmp = (iy0 + k) - 1;
    x_data[temp_tmp] = x_data[tmp];
    x_data[tmp] = temp;
  }
}

double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double b;
  double y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = std::sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = std::sqrt(b * b + 1.0) * a;
  } else if (std::isnan(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
void LKAS::xzlarf(int32_t m, int32_t n, int32_t iv0, double tau, double C_data[],
                  int32_t ic0, int32_t ldc, double work[3])
{
  int32_t i;
  int32_t jA;
  int32_t lastc;
  int32_t lastv;
  if (tau != 0.0) {
    bool exitg2;
    lastv = m;
    i = iv0 + m;
    while ((lastv > 0) && (C_data[i - 2] == 0.0)) {
      lastv--;
      i--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_t exitg1;
      i = (lastc - 1) * ldc + ic0;
      jA = i;
      do {
        exitg1 = 0;
        if (jA <= (i + lastv) - 1) {
          if (C_data[jA - 1] != 0.0) {
            exitg1 = 1;
          } else {
            jA++;
          }
        } else {
          lastc--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    double c;
    int32_t d;
    int32_t e;
    if (lastc != 0) {
      int32_t jy;
      std::memset(&work[0], 0, static_cast<uint8_t>(lastc) * sizeof(double));
      jy = 0;
      d = (lastc - 1) * ldc + ic0;
      for (i = ic0; ldc < 0 ? i >= d : i <= d; i += ldc) {
        c = 0.0;
        e = (i + lastv) - 1;
        for (jA = i; jA <= e; jA++) {
          c += C_data[((iv0 + jA) - i) - 1] * C_data[jA - 1];
        }

        work[jy] += c;
        jy++;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      d = static_cast<uint8_t>(lastc);
      for (lastc = 0; lastc < d; lastc++) {
        c = work[lastc];
        if (c != 0.0) {
          c *= -tau;
          e = lastv + jA;
          for (i = jA; i < e; i++) {
            C_data[i - 1] += C_data[((iv0 + i) - jA) - 1] * c;
          }
        }

        jA += ldc;
      }
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
void LKAS::qrpf(double A_data[], const int32_t A_size[2], int32_t m, double
                tau_data[], int32_t jpvt[3])
{
  __m128d tmp;
  double vn1[3];
  double vn2[3];
  double work[3];
  double s;
  double smax;
  double vn1_0;
  int32_t b;
  int32_t ii;
  int32_t itemp;
  int32_t ix;
  int32_t j;
  int32_t knt;
  int32_t ma;
  int32_t mmi;
  int32_t pvt;
  int32_t vectorUB;
  int32_t vectorUB_tmp;
  ma = A_size[0];
  work[0] = 0.0;
  vn1_0 = xnrm2(m, A_data, 1);
  vn1[0] = vn1_0;
  vn2[0] = vn1_0;
  work[1] = 0.0;
  vn1_0 = xnrm2(m, A_data, A_size[0] + 1);
  vn1[1] = vn1_0;
  vn2[1] = vn1_0;
  work[2] = 0.0;
  vn1_0 = xnrm2(m, A_data, (A_size[0] << 1) + 1);
  vn1[2] = vn1_0;
  vn2[2] = vn1_0;
  if (m <= 3) {
    b = static_cast<uint8_t>(m);
  } else {
    b = 3;
  }

  for (j = 0; j < b; j++) {
    ix = j * ma;
    ii = ix + j;
    mmi = m - j;
    itemp = 3 - j;
    knt = 0;
    if (3 - j > 1) {
      smax = std::abs(vn1[j]);
      for (pvt = 2; pvt <= itemp; pvt++) {
        s = std::abs(vn1[(j + pvt) - 1]);
        if (s > smax) {
          knt = pvt - 1;
          smax = s;
        }
      }
    }

    pvt = j + knt;
    if (pvt != j) {
      xswap(m, A_data, pvt * ma + 1, ix + 1);
      itemp = jpvt[pvt];
      jpvt[pvt] = jpvt[j];
      jpvt[j] = itemp;
      vn1[pvt] = vn1[j];
      vn2[pvt] = vn2[j];
    }

    if (j + 1 < m) {
      s = A_data[ii];
      pvt = ii + 2;
      tau_data[j] = 0.0;
      if (mmi > 0) {
        vn1_0 = xnrm2(mmi - 1, A_data, ii + 2);
        if (vn1_0 != 0.0) {
          smax = rt_hypotd_snf(A_data[ii], vn1_0);
          if (A_data[ii] >= 0.0) {
            smax = -smax;
          }

          if (std::abs(smax) < 1.0020841800044864E-292) {
            knt = 0;
            itemp = ii + mmi;
            do {
              knt++;
              vectorUB = (((((itemp - ii) - 1) / 2) << 1) + ii) + 2;
              vectorUB_tmp = vectorUB - 2;
              for (ix = pvt; ix <= vectorUB_tmp; ix += 2) {
                tmp = _mm_loadu_pd(&A_data[ix - 1]);
                _mm_storeu_pd(&A_data[ix - 1], _mm_mul_pd(tmp, _mm_set1_pd
                  (9.9792015476736E+291)));
              }

              for (ix = vectorUB; ix <= itemp; ix++) {
                A_data[ix - 1] *= 9.9792015476736E+291;
              }

              smax *= 9.9792015476736E+291;
              s *= 9.9792015476736E+291;
            } while ((std::abs(smax) < 1.0020841800044864E-292) && (knt < 20));

            smax = rt_hypotd_snf(s, xnrm2(mmi - 1, A_data, ii + 2));
            if (s >= 0.0) {
              smax = -smax;
            }

            tau_data[j] = (smax - s) / smax;
            s = 1.0 / (s - smax);
            for (ix = pvt; ix <= vectorUB_tmp; ix += 2) {
              tmp = _mm_loadu_pd(&A_data[ix - 1]);
              _mm_storeu_pd(&A_data[ix - 1], _mm_mul_pd(tmp, _mm_set1_pd(s)));
            }

            for (ix = vectorUB; ix <= itemp; ix++) {
              A_data[ix - 1] *= s;
            }

            for (pvt = 0; pvt < knt; pvt++) {
              smax *= 1.0020841800044864E-292;
            }

            s = smax;
          } else {
            tau_data[j] = (smax - A_data[ii]) / smax;
            s = 1.0 / (A_data[ii] - smax);
            ix = ii + mmi;
            itemp = (((((ix - ii) - 1) / 2) << 1) + ii) + 2;
            vectorUB = itemp - 2;
            for (knt = pvt; knt <= vectorUB; knt += 2) {
              tmp = _mm_loadu_pd(&A_data[knt - 1]);
              _mm_storeu_pd(&A_data[knt - 1], _mm_mul_pd(tmp, _mm_set1_pd(s)));
            }

            for (knt = itemp; knt <= ix; knt++) {
              A_data[knt - 1] *= s;
            }

            s = smax;
          }
        }
      }

      A_data[ii] = s;
    } else {
      tau_data[j] = 0.0;
    }

    if (j + 1 < 3) {
      smax = A_data[ii];
      A_data[ii] = 1.0;
      xzlarf(mmi, 2 - j, ii + 1, tau_data[j], A_data, (ii + ma) + 1, ma, work);
      A_data[ii] = smax;
    }

    for (ii = j + 2; ii < 4; ii++) {
      pvt = (ii - 1) * ma + j;
      vn1_0 = vn1[ii - 1];
      if (vn1_0 != 0.0) {
        smax = std::abs(A_data[pvt]) / vn1_0;
        smax = 1.0 - smax * smax;
        if (smax < 0.0) {
          smax = 0.0;
        }

        s = vn1_0 / vn2[ii - 1];
        s = s * s * smax;
        if (s <= 1.4901161193847656E-8) {
          if (j + 1 < m) {
            vn1_0 = xnrm2(mmi - 1, A_data, pvt + 2);
            vn1[ii - 1] = vn1_0;
            vn2[ii - 1] = vn1_0;
          } else {
            vn1[ii - 1] = 0.0;
            vn2[ii - 1] = 0.0;
          }
        } else {
          vn1[ii - 1] = vn1_0 * std::sqrt(smax);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
void LKAS::xgeqp3(double A_data[], int32_t A_size[2], double tau_data[], int32_t
                  *tau_size, int32_t jpvt[3])
{
  int32_t b_A_size[2];
  int32_t b_A;
  int32_t i;
  int32_t loop_ub;
  bool guard1;
  b_A_size[0] = A_size[0];
  b_A_size[1] = 3;
  loop_ub = A_size[0] * 3;
  if (loop_ub - 1 >= 0) {
    std::memcpy(&rtDW.b_A_data_c[0], &A_data[0], static_cast<uint32_t>(loop_ub) *
                sizeof(double));
  }

  if (A_size[0] <= 3) {
    loop_ub = A_size[0];
  } else {
    loop_ub = 3;
  }

  *tau_size = loop_ub;
  if (loop_ub - 1 >= 0) {
    std::memset(&tau_data[0], 0, static_cast<uint32_t>(loop_ub) * sizeof(double));
  }

  guard1 = false;
  if (A_size[0] == 0) {
    guard1 = true;
  } else {
    if (A_size[0] <= 3) {
      i = A_size[0];
    } else {
      i = 3;
    }

    if (i < 1) {
      guard1 = true;
    } else {
      jpvt[0] = 1;
      jpvt[1] = 2;
      jpvt[2] = 3;
      qrpf(rtDW.b_A_data_c, b_A_size, A_size[0], tau_data, jpvt);
    }
  }

  if (guard1) {
    jpvt[0] = 1;
    jpvt[1] = 2;
    jpvt[2] = 3;
  }

  A_size[0] = b_A_size[0];
  A_size[1] = 3;
  loop_ub = b_A_size[0];
  for (i = 0; i < 3; i++) {
    for (b_A = 0; b_A < loop_ub; b_A++) {
      A_data[b_A + A_size[0] * i] = rtDW.b_A_data_c[b_A_size[0] * i + b_A];
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
void LKAS::qrsolve(const double A_data[], const int32_t A_size[2], const double
                   B_data[], const int32_t *B_size, double Y[3], int32_t *rankA)
{
  __m128d tmp;
  __m128d tmp_0;
  double tau_data[3];
  double tol;
  int32_t jpvt[3];
  int32_t b_A_size[2];
  int32_t b_j;
  int32_t c_i;
  int32_t k;
  int32_t maxmn;
  int32_t minmn;
  int32_t scalarLB;
  int32_t vectorUB;
  b_A_size[0] = A_size[0];
  b_A_size[1] = 3;
  maxmn = A_size[0] * 3;
  if (maxmn - 1 >= 0) {
    std::memcpy(&rtDW.b_A_data[0], &A_data[0], static_cast<uint32_t>(maxmn) *
                sizeof(double));
  }

  xgeqp3(rtDW.b_A_data, b_A_size, tau_data, &maxmn, jpvt);
  *rankA = 0;
  if (b_A_size[0] < 3) {
    minmn = b_A_size[0];
    maxmn = 3;
  } else {
    minmn = 3;
    maxmn = b_A_size[0];
  }

  if (minmn > 0) {
    tol = 2.2204460492503131E-15 * static_cast<double>(maxmn) * std::abs
      (rtDW.b_A_data[0]);
    while ((*rankA < minmn) && (!(std::abs(rtDW.b_A_data[b_A_size[0] * *rankA + *
              rankA]) <= tol))) {
      (*rankA)++;
    }
  }

  minmn = 0;
  if (b_A_size[0] <= 3) {
    maxmn = b_A_size[0];
  } else {
    maxmn = 3;
  }

  if (maxmn > 0) {
    for (k = 0; k < maxmn; k++) {
      if (rtDW.b_A_data[b_A_size[0] * k + k] != 0.0) {
        minmn++;
      }
    }
  }

  if (*B_size - 1 >= 0) {
    std::memcpy(&rtDW.b_B_data[0], &B_data[0], static_cast<uint32_t>(*B_size) *
                sizeof(double));
  }

  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  maxmn = b_A_size[0];
  if (b_A_size[0] <= 3) {
    k = b_A_size[0];
  } else {
    k = 3;
  }

  for (b_j = 0; b_j < k; b_j++) {
    if (tau_data[b_j] != 0.0) {
      tol = rtDW.b_B_data[b_j];
      for (c_i = b_j + 2; c_i <= maxmn; c_i++) {
        tol += rtDW.b_A_data[(b_A_size[0] * b_j + c_i) - 1] * rtDW.b_B_data[c_i
          - 1];
      }

      tol *= tau_data[b_j];
      if (tol != 0.0) {
        rtDW.b_B_data[b_j] -= tol;
        scalarLB = (((((maxmn - b_j) - 1) / 2) << 1) + b_j) + 2;
        vectorUB = scalarLB - 2;
        for (c_i = b_j + 2; c_i <= vectorUB; c_i += 2) {
          tmp = _mm_loadu_pd(&rtDW.b_A_data[(b_A_size[0] * b_j + c_i) - 1]);
          tmp_0 = _mm_loadu_pd(&rtDW.b_B_data[c_i - 1]);
          _mm_storeu_pd(&rtDW.b_B_data[c_i - 1], _mm_sub_pd(tmp_0, _mm_mul_pd
            (tmp, _mm_set1_pd(tol))));
        }

        for (c_i = scalarLB; c_i <= maxmn; c_i++) {
          rtDW.b_B_data[c_i - 1] -= rtDW.b_A_data[(b_A_size[0] * b_j + c_i) - 1]
            * tol;
        }
      }
    }
  }

  for (maxmn = 0; maxmn < minmn; maxmn++) {
    Y[jpvt[maxmn] - 1] = rtDW.b_B_data[maxmn];
  }

  for (maxmn = minmn; maxmn >= 1; maxmn--) {
    k = jpvt[maxmn - 1];
    c_i = (maxmn - 1) * b_A_size[0];
    Y[k - 1] /= rtDW.b_A_data[(maxmn + c_i) - 1];
    for (b_j = 0; b_j <= maxmn - 2; b_j++) {
      Y[jpvt[b_j] - 1] -= Y[k - 1] * rtDW.b_A_data[b_j + c_i];
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
void LKAS::polyfit(const double x_data[], const int32_t *x_size, const double
                   y_data[], const int32_t *y_size, double p[3])
{
  __m128d tmp;
  __m128d tmp_0;
  int32_t V_size[2];
  int32_t b;
  int32_t k;
  int32_t scalarLB;
  int32_t vectorUB;
  V_size[0] = *x_size;
  V_size[1] = 3;
  if (*x_size != 0) {
    b = *x_size;
    for (k = 0; k < b; k++) {
      rtDW.V_data[k + (V_size[0] << 1)] = 1.0;
    }

    for (k = 0; k < b; k++) {
      rtDW.V_data[k + V_size[0]] = x_data[k];
    }

    scalarLB = (*x_size / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      tmp = _mm_loadu_pd(&x_data[k]);
      tmp_0 = _mm_loadu_pd(&rtDW.V_data[k + V_size[0]]);
      _mm_storeu_pd(&rtDW.V_data[k], _mm_mul_pd(tmp, tmp_0));
    }

    for (k = scalarLB; k < b; k++) {
      rtDW.V_data[k] = rtDW.V_data[k + V_size[0]] * x_data[k];
    }
  }

  qrsolve(rtDW.V_data, V_size, y_data, y_size, p, &b);
}

// Model step function
void LKAS::step()
{
  std::cout << "step: " << i++ << std::endl;
  static const int16_t tmp[8]{ 519, 675, 113, 1049, 411, 411, 587, 587 };

  static const int16_t tmp_0[8]{ 450, 750, 450, 750, 0, 0, 750, 750 };

  double RV[81];
  double Constraint[72];
  double EstimateGeometricTransformation_DW_CONSTRT_ALL[72];
  double Q[72];
  double bestTFormCompact[9];
  double rtb_EstimateGeometricTransformation[9];
  double tformCompact[9];
  double tformCompact_0[9];
  double E[8];
  double EstimateGeometricTransformation_DW_PTSNORM1[8];
  double EstimateGeometricTransformation_DW_PTSNORM2[8];
  double Qraux[8];
  double Work[8];
  double rtb_pts1[8];
  double rtb_pts2[8];
  double EstimateGeometricTransformation_DW_DISTANCE[4];
  double b_p[3];
  double p[3];
  double cents1[2];
  double cents2[2];
  double ImageDataTypeConversion;
  double ImageDataTypeConversion_0;
  double ImageDataTypeConversion_1;
  double bestInlierDis;
  double count_right;
  double leftx_current;
  double rightx_current;
  double s1DivS2;
  int32_t JPVT[8];
  int32_t a__1_size[2];
  int32_t locs_size[2];
  int32_t b_tmp_size;
  int32_t b_tmp_tmp_size;
  int32_t end;
  int32_t i;
  int32_t i_0;
  int32_t j;
  int32_t jj_size;
  int32_t m;
  int32_t s;
  int32_t tmp_size;
  int32_t trueCount;
  uint32_t EstimateGeometricTransformation_DW_SAMPLEIDX[4];
  uint32_t bestCol;
  uint32_t s1DivS2_tmp;
  int16_t tmp_data[1200];
  char *sErr;
  int8_t EstimateGeometricTransformation_DW_BEST_SAMPLE[4];
  void *source_R;

  // S-Function (sdspwmmfi2): '<Root>/From Multimedia File'
  sErr = GetErrorBuffer(&rtDW.FromMultimediaFile_HostLib[0U]);
  source_R = (void *)&rtDW.FromMultimediaFile[0U];
  LibOutputs_FromMMFile(&rtDW.FromMultimediaFile_HostLib[0U], GetNullPointer(),
                        GetNullPointer(), source_R, GetNullPointer(),
                        GetNullPointer());
  if (*sErr != 0) {
    rtmSetErrorStatus((&rtM), sErr);
    rtmSetStopRequested((&rtM), 1);
  }

  // End of S-Function (sdspwmmfi2): '<Root>/From Multimedia File'

  // S-Function (svipscalenconvert): '<S2>/Image Data Type Conversion' incorporates:
  //   S-Function (sdspwmmfi2): '<Root>/From Multimedia File'

  for (i = 0; i < 2700000; i++) {
    if (rtDW.FromMultimediaFile[i] > 1.0F) {
      rtDW.ImageDataTypeConversion[i] = 1.0;
    } else if (rtDW.FromMultimediaFile[i] < 0.0F) {
      rtDW.ImageDataTypeConversion[i] = 0.0;
    } else {
      rtDW.ImageDataTypeConversion[i] = rtDW.FromMultimediaFile[i];
    }
  }

  // End of S-Function (svipscalenconvert): '<S2>/Image Data Type Conversion'
  // temporary variables for in-place operation
  for (i = 0; i < 900000; i++) {
    // S-Function (svipcolorconv): '<S2>/Color Space  Conversion' incorporates:
    //   S-Function (svipscalenconvert): '<S2>/Image Data Type Conversion'

    // First get the min and max of the RGB triplet
    ImageDataTypeConversion = rtDW.ImageDataTypeConversion[i];
    ImageDataTypeConversion_0 = rtDW.ImageDataTypeConversion[i + 900000];
    if (ImageDataTypeConversion > ImageDataTypeConversion_0) {
      ImageDataTypeConversion_1 = rtDW.ImageDataTypeConversion[i + 1800000];
      if (ImageDataTypeConversion_0 < ImageDataTypeConversion_1) {
        count_right = ImageDataTypeConversion_0;
      } else {
        count_right = ImageDataTypeConversion_1;
      }

      if (ImageDataTypeConversion > ImageDataTypeConversion_1) {
        bestInlierDis = ImageDataTypeConversion;
      } else {
        bestInlierDis = ImageDataTypeConversion_1;
      }
    } else {
      ImageDataTypeConversion_1 = rtDW.ImageDataTypeConversion[i + 1800000];
      if (ImageDataTypeConversion < ImageDataTypeConversion_1) {
        count_right = ImageDataTypeConversion;
      } else {
        count_right = ImageDataTypeConversion_1;
      }

      if (ImageDataTypeConversion_0 > ImageDataTypeConversion_1) {
        bestInlierDis = ImageDataTypeConversion_0;
      } else {
        bestInlierDis = ImageDataTypeConversion_1;
      }
    }

    s1DivS2 = bestInlierDis - count_right;
    if (bestInlierDis != 0.0) {
      count_right = s1DivS2 / bestInlierDis;
    } else {
      count_right = 0.0;
    }

    if (s1DivS2 != 0.0) {
      if (ImageDataTypeConversion == bestInlierDis) {
        s1DivS2 = (ImageDataTypeConversion_0 - ImageDataTypeConversion_1) /
          s1DivS2;
      } else if (ImageDataTypeConversion_0 == bestInlierDis) {
        s1DivS2 = (ImageDataTypeConversion_1 - ImageDataTypeConversion) /
          s1DivS2 + 2.0;
      } else {
        s1DivS2 = (ImageDataTypeConversion - ImageDataTypeConversion_0) /
          s1DivS2 + 4.0;
      }

      s1DivS2 /= 6.0;
      if (s1DivS2 < 0.0) {
        s1DivS2++;
      }
    } else {
      s1DivS2 = 0.0;
    }

    // assign the results
    rtDW.ColorSpaceConversion[i] = s1DivS2;

    // S-Function (svipcolorconv): '<S2>/Color Space  Conversion'
    rtDW.ColorSpaceConversion[i + 900000] = count_right;

    // S-Function (svipcolorconv): '<S2>/Color Space  Conversion'
    rtDW.ColorSpaceConversion[i + 1800000] = bestInlierDis;

    // MATLAB Function: '<S2>/MATLAB Function4' incorporates:
    //   S-Function (svipcolorconv): '<S2>/Color Space  Conversion'

    rtDW.S_Channel[i] = count_right;
  }

  for (i_0 = 0; i_0 < 8; i_0++) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    rtb_pts1[i_0] = tmp[i_0];

    // MATLAB Function: '<S2>/MATLAB Function2'
    rtb_pts2[i_0] = tmp_0[i_0];
  }

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
  std::memset(&rtb_EstimateGeometricTransformation[0], 0, 9U * sizeof(double));
  EstimateGeometricTransformation_DW_BEST_SAMPLE[0] = 0;
  EstimateGeometricTransformation_DW_BEST_SAMPLE[1] = 1;
  EstimateGeometricTransformation_DW_BEST_SAMPLE[2] = 2;
  EstimateGeometricTransformation_DW_BEST_SAMPLE[3] = 3;
  makeConstraintMatrix_Projective_D_D((const double *)&rtb_pts1[0], (const
    double *)&rtb_pts2[0], 4U, 4U,
    &EstimateGeometricTransformation_DW_CONSTRT_ALL[0]);
  for (i = 0; i < 4; i++) {
    EstimateGeometricTransformation_DW_SAMPLEIDX[i] = static_cast<uint32_t>
      (EstimateGeometricTransformation_DW_BEST_SAMPLE[i]);
  }

  bestCol = 0U;
  normPts_D_D((const double *)&rtb_pts1[0], (const uint32_t *)
              &EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
              &EstimateGeometricTransformation_DW_PTSNORM1[0], &rightx_current,
              &cents1[0]);
  normPts_D_D((const double *)&rtb_pts2[0], (const uint32_t *)
              &EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
              &EstimateGeometricTransformation_DW_PTSNORM2[0], &leftx_current,
              &cents2[0]);
  makeConstraintMatrix_Projective_D_D((const double *)
    &EstimateGeometricTransformation_DW_PTSNORM1[0], (const double *)
    &EstimateGeometricTransformation_DW_PTSNORM2[0], 4U, 4U, &Constraint[0]);
  for (i = 0; i < 8; i++) {
    JPVT[static_cast<uint32_t>(i)] = 0;
  }

  QRE_double(&Q[0], &Constraint[0], &E[0], &Qraux[0], &Work[0], &JPVT[0], &RV[0],
             9, 8, true);
  count_right = 0.0;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (static_cast<uint32_t>(i) != static_cast<uint32_t>(j)) {
        s1DivS2 = 0.0;
      } else {
        s1DivS2 = -1.0;
      }

      for (m = 0; m < 8; m++) {
        s1DivS2_tmp = static_cast<uint32_t>(m) * 9U;
        s1DivS2 += Q[s1DivS2_tmp + static_cast<uint32_t>(i)] * Q[s1DivS2_tmp +
          static_cast<uint32_t>(j)];
      }

      RV[static_cast<uint32_t>(i) * 9U + static_cast<uint32_t>(j)] = s1DivS2;
      if (!(s1DivS2 >= 0.0)) {
        s1DivS2 = -s1DivS2;
      }

      if (count_right < s1DivS2) {
        count_right = s1DivS2;
        bestCol = static_cast<uint32_t>(i);
      }
    }
  }

  j = static_cast<int32_t>(bestCol * 9U);
  for (i = 0; i < 9; i++) {
    tformCompact[static_cast<uint32_t>(i)] = RV[static_cast<uint32_t>(j) +
      static_cast<uint32_t>(i)];
  }

  count_right = 1.0 / leftx_current;
  s1DivS2 = rightx_current * count_right;
  tformCompact_0[6] = tformCompact[6] * rightx_current;
  tformCompact_0[7] = tformCompact[7] * rightx_current;
  tformCompact_0[8] = (tformCompact[8] - cents1[0] * tformCompact_0[6]) -
    cents1[1] * tformCompact_0[7];
  tformCompact_0[0] = tformCompact[0] * s1DivS2;
  tformCompact_0[1] = tformCompact[1] * s1DivS2;
  tformCompact_0[2] = ((cents2[0] * tformCompact_0[8] - tformCompact_0[0] *
                        cents1[0]) - tformCompact_0[1] * cents1[1]) +
    tformCompact[2] * count_right;
  tformCompact_0[3] = tformCompact[3] * s1DivS2;
  tformCompact_0[4] = tformCompact[4] * s1DivS2;
  tformCompact_0[5] = ((cents2[1] * tformCompact_0[8] - cents1[0] *
                        tformCompact_0[3]) - cents1[1] * tformCompact_0[4]) +
    tformCompact[5] * count_right;
  tformCompact_0[0] += cents2[0] * tformCompact_0[6];
  tformCompact_0[1] += cents2[0] * tformCompact_0[7];
  tformCompact_0[3] += cents2[1] * tformCompact_0[6];
  tformCompact_0[4] += cents2[1] * tformCompact_0[7];
  if (tformCompact_0[8U] != 0.0) {
    count_right = 1.0 / tformCompact_0[8];
    for (i = 0; i < 8; i++) {
      tformCompact_0[static_cast<uint32_t>(i)] *= count_right;
    }

    tformCompact_0[8] = 1.0;
    bestCol = 0U;
    for (i = 0; i < 4; i++) {
      EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_t>(i)] =
        0.0;
      for (j = 0; j < 2; j++) {
        count_right = 0.0;
        for (m = 0; m < 9; m++) {
          count_right += EstimateGeometricTransformation_DW_CONSTRT_ALL[bestCol
            + static_cast<uint32_t>(m)] * tformCompact_0[static_cast<uint32_t>(m)];
        }

        bestCol += 9U;
        EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_t>(i)] +=
          count_right * count_right;
      }
    }

    std::memcpy(&bestTFormCompact[0], &tformCompact_0[0], 9U * sizeof(double));
    i = 0;
    if (EstimateGeometricTransformation_DW_DISTANCE[0] <= 2.5) {
      i = 1;
    }

    if (EstimateGeometricTransformation_DW_DISTANCE[1] <= 2.5) {
      i = static_cast<int32_t>(static_cast<uint32_t>(i) + 1U);
    }

    if (EstimateGeometricTransformation_DW_DISTANCE[2] <= 2.5) {
      i = static_cast<int32_t>(static_cast<uint32_t>(i) + 1U);
    }

    if (EstimateGeometricTransformation_DW_DISTANCE[3] <= 2.5) {
      i = static_cast<int32_t>(static_cast<uint32_t>(i) + 1U);
    }
  } else {
    i = 0;
  }

  if (static_cast<uint32_t>(i) >= 4U) {
    rtb_EstimateGeometricTransformation[0] = bestTFormCompact[4];
    rtb_EstimateGeometricTransformation[1] = bestTFormCompact[3];
    rtb_EstimateGeometricTransformation[2] = bestTFormCompact[5];
    rtb_EstimateGeometricTransformation[3] = bestTFormCompact[1];
    rtb_EstimateGeometricTransformation[4] = bestTFormCompact[0];
    rtb_EstimateGeometricTransformation[5] = bestTFormCompact[2];
    rtb_EstimateGeometricTransformation[6] = bestTFormCompact[7];
    rtb_EstimateGeometricTransformation[7] = bestTFormCompact[6];
    rtb_EstimateGeometricTransformation[8] = bestTFormCompact[8];
  }

  // MATLAB Function: '<S2>/MATLAB Function6'
  for (i_0 = 0; i_0 < 900000; i_0++) {
    rtDW.rtb_S_Channel_l[i_0] = (rtDW.S_Channel[i_0] > 0.75);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function6'

  // MATLABSystem: '<S2>/Warp' incorporates:
  //   S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'

  Warp_stepImpl(&rtDW.obj, rtDW.rtb_S_Channel_l,
                rtb_EstimateGeometricTransformation, rtDW.o_data);

  // MATLAB Function: '<S2>/MATLAB Function3' incorporates:
  //   MATLABSystem: '<S2>/Warp'

  for (i = 0; i < 1200; i++) {
    m = i * 376;
    i_0 = rtDW.o_data[(m / 376 * 750 + m % 376) + 374];
    for (j = 0; j < 375; j++) {
      s = (m + j) + 1;
      i_0 += rtDW.o_data[(s / 376 * 750 + s % 376) + 374];
    }

    rtDW.nz[i] = i_0;
  }

  findpeaks(rtDW.nz, rtDW.a__1_data, a__1_size, rtDW.locs_data, locs_size);
  end = locs_size[1] - 1;
  trueCount = 0;
  for (i = 0; i <= end; i++) {
    // MATLAB Function: '<S2>/MATLAB Function3'
    if (rtDW.locs_data[i] - rtDW.locs_data[0] > 200.0) {
      trueCount++;
    }
  }

  i_0 = trueCount;
  trueCount = 0;
  for (i = 0; i <= end; i++) {
    // MATLAB Function: '<S2>/MATLAB Function3'
    if (rtDW.locs_data[i] - rtDW.locs_data[0] > 200.0) {
      tmp_data[trueCount] = static_cast<int16_t>(i);
      trueCount++;
    }
  }

  // MATLAB Function: '<S2>/MATLAB Function3' incorporates:
  //   Gain: '<S37>/Filter Coefficient'
  //   MATLABSystem: '<S2>/Warp'
  //   S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'

  rightx_current = rtDW.locs_data[tmp_data[i_0 - 1]];
  leftx_current = rtDW.locs_data[0];
  std::memset(&rtDW.left_lane_index[0], 0, 200000U * sizeof(int32_t));
  std::memset(&rtDW.right_lane_index[0], 0, 200000U * sizeof(int32_t));
  eml_find(rtDW.o_data, rtDW.ii_data, &s, rtDW.jj_data, &jj_size);
  bestInlierDis = 0.0;
  count_right = 0.0;
  for (i = 0; i < 10; i++) {
    j = 750 - (i + 1) * 75;
    m = 750 - i * 75;
    for (i_0 = 0; i_0 < jj_size; i_0++) {
      rtDW.S_Channel[i_0] = rtDW.jj_data[i_0];
    }

    b_tmp_tmp_size = s;
    for (i_0 = 0; i_0 < s; i_0++) {
      end = rtDW.ii_data[i_0];
      rtDW.rtb_S_Channel_l[i_0] = ((end >= j) && (end < m));
    }

    if (s == jj_size) {
      b_tmp_size = s;
      for (i_0 = 0; i_0 < s; i_0++) {
        rtDW.b_tmp_data[i_0] = (rtDW.rtb_S_Channel_l[i_0] && (rtDW.S_Channel[i_0]
          >= leftx_current - 80.0));
      }
    } else {
      binary_expand_op_1(rtDW.b_tmp_data, &b_tmp_size, rtDW.rtb_S_Channel_l, &s,
                         rtDW.S_Channel, &jj_size, leftx_current);
    }

    for (i_0 = 0; i_0 < jj_size; i_0++) {
      rtDW.o_data[i_0] = (rtDW.S_Channel[i_0] < leftx_current + 80.0);
    }

    if (s == jj_size) {
      for (i_0 = 0; i_0 < s; i_0++) {
        rtDW.rtb_S_Channel_l[i_0] = (rtDW.rtb_S_Channel_l[i_0] &&
          (rtDW.S_Channel[i_0] >= rightx_current - 80.0));
      }
    } else {
      binary_expand_op(rtDW.rtb_S_Channel_l, &b_tmp_tmp_size, rtDW.S_Channel,
                       &jj_size, rightx_current);
    }

    for (i_0 = 0; i_0 < jj_size; i_0++) {
      rtDW.r_data[i_0] = (rtDW.S_Channel[i_0] < rightx_current + 80.0);
    }

    ImageDataTypeConversion = bestInlierDis + 1.0;
    if (b_tmp_size == jj_size) {
      end = b_tmp_size;
      for (i_0 = 0; i_0 < b_tmp_size; i_0++) {
        rtDW.tmp_data_f[i_0] = (rtDW.b_tmp_data[i_0] && rtDW.o_data[i_0]);
      }
    } else {
      and_j(rtDW.tmp_data_f, &end, rtDW.b_tmp_data, &b_tmp_size, rtDW.o_data,
            &jj_size);
    }

    end--;
    trueCount = 0;
    for (i_0 = 0; i_0 <= end; i_0++) {
      if (rtDW.tmp_data_f[i_0]) {
        trueCount++;
      }
    }

    m = static_cast<int32_t>((1.0 - (bestInlierDis + 1.0)) + static_cast<double>
      (trueCount));
    for (j = 0; j < m; j++) {
      s1DivS2 = ImageDataTypeConversion + static_cast<double>(j);
      if (b_tmp_size == jj_size) {
        end = b_tmp_size;
        for (i_0 = 0; i_0 < b_tmp_size; i_0++) {
          rtDW.tmp_data_g1[i_0] = (rtDW.b_tmp_data[i_0] && rtDW.o_data[i_0]);
        }
      } else {
        and_j(rtDW.tmp_data_g1, &end, rtDW.b_tmp_data, &b_tmp_size, rtDW.o_data,
              &jj_size);
      }

      if (b_tmp_size == jj_size) {
        tmp_size = b_tmp_size;
        for (i_0 = 0; i_0 < b_tmp_size; i_0++) {
          rtDW.tmp_data_m[i_0] = (rtDW.b_tmp_data[i_0] && rtDW.o_data[i_0]);
        }
      } else {
        and_j(rtDW.tmp_data_m, &tmp_size, rtDW.b_tmp_data, &b_tmp_size,
              rtDW.o_data, &jj_size);
      }

      end--;
      trueCount = 0;
      for (i_0 = 0; i_0 <= end; i_0++) {
        if (rtDW.tmp_data_g1[i_0]) {
          rtDW.tmp_data[trueCount] = i_0;
          trueCount++;
        }
      }

      end = tmp_size - 1;
      trueCount = 0;
      for (i_0 = 0; i_0 <= end; i_0++) {
        if (rtDW.tmp_data_m[i_0]) {
          rtDW.tmp_data_k[trueCount] = i_0;
          trueCount++;
        }
      }

      rtDW.left_lane_index[static_cast<int32_t>(s1DivS2) - 1] =
        rtDW.jj_data[rtDW.tmp_data[static_cast<int32_t>(s1DivS2) - 1]];
      rtDW.left_lane_index[static_cast<int32_t>(s1DivS2) + 99999] =
        rtDW.ii_data[rtDW.tmp_data_k[static_cast<int32_t>(s1DivS2) - 1]];
      bestInlierDis++;
    }

    ImageDataTypeConversion = count_right + 1.0;
    if (b_tmp_tmp_size == jj_size) {
      end = b_tmp_tmp_size;
      for (i_0 = 0; i_0 < b_tmp_tmp_size; i_0++) {
        rtDW.tmp_data_g[i_0] = (rtDW.rtb_S_Channel_l[i_0] && rtDW.r_data[i_0]);
      }
    } else {
      and_j(rtDW.tmp_data_g, &end, rtDW.rtb_S_Channel_l, &b_tmp_tmp_size,
            rtDW.r_data, &jj_size);
    }

    end--;
    trueCount = 0;
    for (i_0 = 0; i_0 <= end; i_0++) {
      if (rtDW.tmp_data_g[i_0]) {
        trueCount++;
      }
    }

    m = static_cast<int32_t>((1.0 - (count_right + 1.0)) + static_cast<double>
      (trueCount));
    for (j = 0; j < m; j++) {
      s1DivS2 = ImageDataTypeConversion + static_cast<double>(j);
      if (b_tmp_tmp_size == jj_size) {
        end = b_tmp_tmp_size;
        for (i_0 = 0; i_0 < b_tmp_tmp_size; i_0++) {
          rtDW.tmp_data_l[i_0] = (rtDW.rtb_S_Channel_l[i_0] && rtDW.r_data[i_0]);
        }
      } else {
        and_j(rtDW.tmp_data_l, &end, rtDW.rtb_S_Channel_l, &b_tmp_tmp_size,
              rtDW.r_data, &jj_size);
      }

      if (b_tmp_tmp_size == jj_size) {
        tmp_size = b_tmp_tmp_size;
        for (i_0 = 0; i_0 < b_tmp_tmp_size; i_0++) {
          rtDW.tmp_data_d[i_0] = (rtDW.rtb_S_Channel_l[i_0] && rtDW.r_data[i_0]);
        }
      } else {
        and_j(rtDW.tmp_data_d, &tmp_size, rtDW.rtb_S_Channel_l, &b_tmp_tmp_size,
              rtDW.r_data, &jj_size);
      }

      end--;
      trueCount = 0;
      for (i_0 = 0; i_0 <= end; i_0++) {
        if (rtDW.tmp_data_l[i_0]) {
          rtDW.tmp_data_b[trueCount] = i_0;
          trueCount++;
        }
      }

      end = tmp_size - 1;
      trueCount = 0;
      for (i_0 = 0; i_0 <= end; i_0++) {
        if (rtDW.tmp_data_d[i_0]) {
          rtDW.tmp_data_p[trueCount] = i_0;
          trueCount++;
        }
      }

      rtDW.right_lane_index[static_cast<int32_t>(s1DivS2) - 1] =
        rtDW.jj_data[rtDW.tmp_data_b[static_cast<int32_t>(s1DivS2) - 1]];
      rtDW.right_lane_index[static_cast<int32_t>(s1DivS2) + 99999] =
        rtDW.ii_data[rtDW.tmp_data_p[static_cast<int32_t>(s1DivS2) - 1]];
      count_right++;
    }

    if (b_tmp_size == jj_size) {
      end = b_tmp_size;
      for (i_0 = 0; i_0 < b_tmp_size; i_0++) {
        rtDW.tmp_data_n[i_0] = (rtDW.b_tmp_data[i_0] && rtDW.o_data[i_0]);
      }
    } else {
      and_j(rtDW.tmp_data_n, &end, rtDW.b_tmp_data, &b_tmp_size, rtDW.o_data,
            &jj_size);
    }

    end--;
    trueCount = 0;
    for (i_0 = 0; i_0 <= end; i_0++) {
      if (rtDW.tmp_data_n[i_0]) {
        trueCount++;
      }
    }

    if (trueCount > 40) {
      if (b_tmp_size == jj_size) {
        end = b_tmp_size;
        for (i_0 = 0; i_0 < b_tmp_size; i_0++) {
          rtDW.tmp_data_pp[i_0] = (rtDW.b_tmp_data[i_0] && rtDW.o_data[i_0]);
        }
      } else {
        and_j(rtDW.tmp_data_pp, &end, rtDW.b_tmp_data, &b_tmp_size, rtDW.o_data,
              &jj_size);
      }

      end--;
      trueCount = 0;
      for (i_0 = 0; i_0 <= end; i_0++) {
        if (rtDW.tmp_data_pp[i_0]) {
          trueCount++;
        }
      }

      j = trueCount;
      trueCount = 0;
      for (i_0 = 0; i_0 <= end; i_0++) {
        if (rtDW.tmp_data_pp[i_0]) {
          rtDW.tmp_data_c[trueCount] = i_0;
          trueCount++;
        }
      }

      for (i_0 = 0; i_0 < j; i_0++) {
        rtDW.S_Channel[i_0] = rtDW.jj_data[rtDW.tmp_data_c[i_0]];
      }

      leftx_current = mean(rtDW.S_Channel, &j);
    }

    if (b_tmp_tmp_size == jj_size) {
      end = b_tmp_tmp_size;
      for (i_0 = 0; i_0 < b_tmp_tmp_size; i_0++) {
        rtDW.tmp_data_j[i_0] = (rtDW.rtb_S_Channel_l[i_0] && rtDW.r_data[i_0]);
      }
    } else {
      and_j(rtDW.tmp_data_j, &end, rtDW.rtb_S_Channel_l, &b_tmp_tmp_size,
            rtDW.r_data, &jj_size);
    }

    end--;
    trueCount = 0;
    for (i_0 = 0; i_0 <= end; i_0++) {
      if (rtDW.tmp_data_j[i_0]) {
        trueCount++;
      }
    }

    if (trueCount > 40) {
      if (b_tmp_tmp_size == jj_size) {
        end = b_tmp_tmp_size;
        for (i_0 = 0; i_0 < b_tmp_tmp_size; i_0++) {
          rtDW.tmp_data_gu[i_0] = (rtDW.rtb_S_Channel_l[i_0] && rtDW.r_data[i_0]);
        }
      } else {
        and_j(rtDW.tmp_data_gu, &end, rtDW.rtb_S_Channel_l, &b_tmp_tmp_size,
              rtDW.r_data, &jj_size);
      }

      end--;
      trueCount = 0;
      for (i_0 = 0; i_0 <= end; i_0++) {
        if (rtDW.tmp_data_gu[i_0]) {
          trueCount++;
        }
      }

      j = trueCount;
      trueCount = 0;
      for (i_0 = 0; i_0 <= end; i_0++) {
        if (rtDW.tmp_data_gu[i_0]) {
          rtDW.tmp_data_cv[trueCount] = i_0;
          trueCount++;
        }
      }

      for (i_0 = 0; i_0 < j; i_0++) {
        rtDW.S_Channel[i_0] = rtDW.jj_data[rtDW.tmp_data_cv[i_0]];
      }

      rightx_current = mean(rtDW.S_Channel, &j);
    }
  }

  if (bestInlierDis < 1.0) {
    i = -1;
  } else {
    i = static_cast<int32_t>(bestInlierDis) - 1;
  }

  if (count_right < 1.0) {
    j = -1;
  } else {
    j = static_cast<int32_t>(count_right) - 1;
  }

  m = i + 1;
  s = i + 1;
  for (i_0 = 0; i_0 <= i; i_0++) {
    rtDW.left_lane_index_data[i_0] = rtDW.left_lane_index[i_0 + 100000];
    rtDW.left_lane_index_data_m[i_0] = rtDW.left_lane_index[i_0];
  }

  polyfit(rtDW.left_lane_index_data, &m, rtDW.left_lane_index_data_m, &s, p);
  m = j + 1;
  s = j + 1;
  for (i_0 = 0; i_0 <= j; i_0++) {
    rtDW.left_lane_index_data[i_0] = rtDW.right_lane_index[i_0 + 100000];
    rtDW.left_lane_index_data_m[i_0] = rtDW.right_lane_index[i_0];
  }

  polyfit(rtDW.left_lane_index_data, &m, rtDW.left_lane_index_data_m, &s, b_p);
  for (i_0 = 0; i_0 < 751; i_0++) {
    rtDW.xleft[i_0] = p[0];
  }

  for (i = 0; i < 2; i++) {
    count_right = p[i + 1];
    for (i_0 = 0; i_0 < 751; i_0++) {
      rtDW.xleft[i_0] = static_cast<double>(i_0) * rtDW.xleft[i_0] + count_right;
    }
  }

  for (i_0 = 0; i_0 < 751; i_0++) {
    rtDW.xright[i_0] = b_p[0];
  }

  for (i = 0; i < 2; i++) {
    count_right = b_p[i + 1];
    for (i_0 = 0; i_0 < 751; i_0++) {
      rtDW.xright[i_0] = static_cast<double>(i_0) * rtDW.xright[i_0] +
        count_right;
    }
  }

  rightx_current = 600.0 - (rtDW.xleft[750] + rtDW.xright[750]) / 2.0;

  finish = time(NULL);
  duration = (double)(finish - start);
  std::cout << "Time: " << duration << std::endl;
  std::cout << "Error: " << rightx_current << std::endl;
  std::cout << "cnt_flag: " << cnt_flag << std::endl;
  if (rightx_current >= 111.133 && cnt_flag == 0){
    std::cout << "@@@@@@@@@@@@@@@@@@@" << std::endl;
    cnt_flag = 1;
  }
  else if (rightx_current >= 111.133 && cnt_flag == 1){
    exit(0);
  }


  // Gain: '<S37>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S29>/Filter'
  //   Gain: '<S28>/Derivative Gain'
  //   Sum: '<S29>/SumD'

  leftx_current = (0.012 * rightx_current - rtDW.Filter_DSTATE) * 100.0;

  // Sum: '<S43>/Sum' incorporates:
  //   DiscreteIntegrator: '<S34>/Integrator'
  //   Gain: '<S39>/Proportional Gain'

  bestInlierDis = (0.015 * rightx_current + rtDW.Integrator_DSTATE) +
    leftx_current;

  // Saturate: '<S41>/Saturation'
  if (bestInlierDis > 1.5707963267948966) {
    count_right = 1.5707963267948966;
  } else if (bestInlierDis < -1.5707963267948966) {
    count_right = -1.5707963267948966;
  } else {
    count_right = bestInlierDis;
  }

  // End of Saturate: '<S41>/Saturation'

  // Outport: '<Root>/Out1'
  rtY.Out1 = count_right;

  // Update for DiscreteIntegrator: '<S34>/Integrator' incorporates:
  //   Gain: '<S31>/Integral Gain'
  //   Sum: '<S27>/SumI2'
  //   Sum: '<S27>/SumI4'

  rtDW.Integrator_DSTATE += ((count_right - bestInlierDis) + 0.02 *
    rightx_current) * 0.2;

  // Update for DiscreteIntegrator: '<S29>/Filter'
  rtDW.Filter_DSTATE += 0.2 * leftx_current;
}

// Model initialize function
void LKAS::initialize()
{
  // Registration code
  start = time(NULL);
  // initialize non-finites
  rt_InitInfAndNaN(sizeof(double));

  {
    static const int8_t self_T[9]{ 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    int32_t i;
    char *sErr;

    // Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File'
    sErr = GetErrorBuffer(&rtDW.FromMultimediaFile_HostLib[0U]);
    CreateHostLibrary("libmwfrommmfile.so", &rtDW.FromMultimediaFile_HostLib[0U]);
    createAudioInfo(&rtDW.FromMultimediaFile_AudioInfo[0U], 0U, 0U, 0.0, 0, 0, 0,
                    0, GetNullPointer());
    createVideoInfo(&rtDW.FromMultimediaFile_VideoInfo[0U], 1U, 5.0, 5.0, "RGB ",
                    1, 3, 1200, 750, 1U, 1, 1, GetNullPointer());
    if (*sErr == 0) {
      LibCreate_FromMMFile(&rtDW.FromMultimediaFile_HostLib[0U], nullptr,
                           "/home/seame-workstation09/DES_Adaptive-Application/Perception/Final.mp4",
                           1,
                           "/usr/local/MATLAB/R2023b/toolbox/shared/multimedia/bin/glnxa64/video/libmwvideofilegstreaderplugin.so",
                           "/usr/local/MATLAB/R2023b/toolbox/shared/multimedia/bin/glnxa64/video/libmwvideoreaderslconverter.so",
                           &rtDW.FromMultimediaFile_AudioInfo[0U],
                           &rtDW.FromMultimediaFile_VideoInfo[0U], 0U, 1U, 1U,
                           0U, 0U, 1U, 1.0, 9.2233720368547758E+18, 0U);
    }

    if (*sErr == 0) {
      LibStart(&rtDW.FromMultimediaFile_HostLib[0U]);
    }

    if (*sErr != 0) {
      DestroyHostLibrary(&rtDW.FromMultimediaFile_HostLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus((&rtM), sErr);
        rtmSetStopRequested((&rtM), 1);
      }
    }

    // End of Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File'

    // Start for S-Function (svipesttform): '<S2>/Estimate Geometric Transformation' 
    srand(clock());

    // InitializeConditions for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' 
    LibReset(&rtDW.FromMultimediaFile_HostLib[0U]);

    // Start for MATLABSystem: '<S2>/Warp'
    rtDW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      rtDW.obj.TformProjective.T[i] = self_T[i];
    }

    // End of Start for MATLABSystem: '<S2>/Warp'
  }
}

// Constructor
LKAS::LKAS() :
  rtY(),
  rtDW(),
  rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
LKAS::~LKAS() = default;

// Real-Time Model get method
LKAS::RT_MODEL * LKAS::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
