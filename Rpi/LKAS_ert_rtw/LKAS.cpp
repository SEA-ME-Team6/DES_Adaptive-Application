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
// C/C++ source code generated on : Tue Feb 27 14:47:06 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Emulation hardware selection:
//    Differs from embedded hardware (MATLAB Host)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "LKAS.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <string.h>
#include <stddef.h>
#include <emmintrin.h>
#include <math.h>
#define NumBitsPerChar                 8U

// Block signals and states (default storage)
DW rtDW;

// External outputs (root outports fed by signals with default storage)
ExtY rtY;

// Real-time model
RT_MODEL rtM_ = RT_MODEL();
RT_MODEL *const rtM = &rtM_;
extern void makeConstraintMatrix_Projective_D_D(const real_T pts1[], const
  real_T pts2[], uint32_T sampleNum, uint32_T maxSampleNum, real_T constraint[]);
extern void normPts_D_D(const real_T pts[], const uint32_T samples[], uint32_T
  ptsNum, uint32_T sampleNum, real_T ptsNorm[], real_T scale[], real_T cents[]);
extern void QRCompQy_real_T(real_T qr[], const real_T qrAuxj[], real_T y[],
  int32_T n, int32_T j);
extern void QRSL1_real_T(real_T qr[], const real_T qrAux[], real_T y[], int32_T
  n, int32_T k);

// Forward declaration for local functions
static void QRV2Norm_real_T_j(const real_T V[], int32_T N, real_T v2norm[]);
static void QRDC_real_T_j(real_T xVec[], real_T qrAux[], int32_T jpvt[], real_T
  work[], int32_T M, int32_T N);
static void QRE_real_T_j(real_T outQ[], real_T outR[], real_T outE[], real_T
  qrAux[], real_T work[], int32_T jpvt[], real_T sPtr[], int32_T M, int32_T N,
  boolean_T economy);
static void Warp_stepImpl(vision_internal_blocks_Warp *b_this, const boolean_T
  Image[900000], const real_T input2[9], boolean_T Jout[900000]);
static void do_vectors(const coder::array<int32_T, 1U> &a, const coder::array<
  int32_T, 1U> &b, coder::array<int32_T, 1U> &c, coder::array<int32_T, 1U> &ia,
  coder::array<int32_T, 1U> &ib);
static void findpeaks(const real_T Yin[1200], coder::array<real_T, 2U> &Ypk,
                      coder::array<real_T, 2U> &Xpk);
static void binary_expand_op_1(coder::array<boolean_T, 1U> &in1, const coder::
  array<boolean_T, 1U> &in2, const coder::array<real_T, 1U> &in3, real_T in4);
static void binary_expand_op(coder::array<boolean_T, 1U> &in1, const coder::
  array<real_T, 1U> &in2, real_T in3);
static void and_j(coder::array<boolean_T, 1U> &in1, const coder::array<boolean_T,
                  1U> &in2, const coder::array<boolean_T, 1U> &in3);
static real_T mean(const coder::array<real_T, 1U> &x);
static real_T xnrm2(int32_T n, const coder::array<real_T, 2U> &x, int32_T ix0);
static real_T rt_hypotd_snf_j(real_T u0, real_T u1);
static void xgeqp3(coder::array<real_T, 2U> &A, coder::array<real_T, 1U> &tau,
                   int32_T jpvt[3]);
static void polyfit(const coder::array<real_T, 1U> &x, const coder::array<real_T,
                    1U> &y, real_T p[3]);
extern "C"
{
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}

extern "C"
{
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T inf = 0.0;
    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
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
  static real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T minf = 0.0;
    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
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
  static real32_T rtGetMinusInfF(void)
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
  static real_T rtGetNaN(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;
    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
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
  static real32_T rtGetNaNF(void)
  {
    IEEESingle nanF = { { 0.0F } };

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
  static boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    boolean_T result = (boolean_T) 0;
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    if (bitsPerReal == 32U) {
      result = rtIsNaNF((real32_T)value);
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.fltVal = value;
      result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) ==
                           0x7FF00000 &&
                           ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                            (tmpVal.bitVal.words.wordL != 0) ));
    }

    return result;
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    IEEESingle tmp;
    tmp.wordL.wordLreal = value;
    return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                       (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
  }
}

void makeConstraintMatrix_Projective_D_D(const real_T pts1[], const real_T pts2[],
  uint32_T sampleNum, uint32_T maxSampleNum, real_T constraint[])
{
  uint32_T j;
  uint32_T k;

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

void normPts_D_D(const real_T pts[], const uint32_T samples[], uint32_T ptsNum,
                 uint32_T sampleNum, real_T ptsNorm[], real_T scale[], real_T
                 cents[])
{
  real_T sumDis;

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

static void QRV2Norm_real_T_j(const real_T V[], int32_T N, real_T v2norm[])
{
  int32_T vi;

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
  rtDW.tmpQRSL = 0.0;
  vi = 0;
  for (int32_T i = 0; i < N; i++) {
    rtDW.d = rtDW.tmpQRSL;
    rtDW.d1 = fabs(V[vi]);
    if (rtDW.tmpQRSL > rtDW.d1) {
      rtDW.tmpQRSL = V[vi] / rtDW.tmpQRSL;
      rtDW.tmpQRSL = sqrt(rtDW.tmpQRSL * rtDW.tmpQRSL + 1.0) * rtDW.d;
    } else if (V[vi] == 0.0) {
      rtDW.tmpQRSL = 0.0;
    } else {
      rtDW.tmpQRSL /= V[vi];
      rtDW.tmpQRSL = sqrt(rtDW.tmpQRSL * rtDW.tmpQRSL + 1.0) * rtDW.d1;
    }

    vi++;
  }

  v2norm[0U] = rtDW.tmpQRSL;

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

static void QRDC_real_T_j(real_T xVec[], real_T qrAux[], int32_T jpvt[], real_T
  work[], int32_T M, int32_T N)
{
  int32_T i;
  int32_T l;
  int32_T maxj;
  int32_T minVal;
  int32_T mml;
  int32_T pl;
  int32_T plj;
  int32_T pu;
  int32_T px;
  int32_T px2;

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
  pl = 0;
  rtDW.j_l = 0;
  while (rtDW.j_l < N) {
    pu = (jpvt[rtDW.j_l] > 0);
    if (jpvt[rtDW.j_l] < 0) {
      jpvt[rtDW.j_l] = -rtDW.j_l;
    } else {
      jpvt[rtDW.j_l] = rtDW.j_l;
    }

    if (pu == 1) {
      if (rtDW.j_l != pl) {
        // Swap columns pl and j
        px = pl * M;
        px2 = rtDW.j_l * M;
        for (i = M; i > 0; i--) {
          rtDW.maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = rtDW.maxnrm;
          px++;
          px2++;
        }
      }

      jpvt[rtDW.j_l] = jpvt[pl];
      jpvt[pl] = rtDW.j_l;
      pl++;
    }

    rtDW.j_l++;
  }

  pu = N - 1;
  rtDW.j_l = N - 1;
  while (rtDW.j_l >= 0) {
    if (jpvt[rtDW.j_l] < 0) {
      jpvt[rtDW.j_l] = -jpvt[rtDW.j_l];
      if (rtDW.j_l != pu) {
        // Swap columns pu and j
        px = pu * M;
        px2 = rtDW.j_l * M;
        for (i = M; i > 0; i--) {
          rtDW.maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = rtDW.maxnrm;
          px++;
          px2++;
        }

        px = jpvt[pu];
        jpvt[pu] = jpvt[rtDW.j_l];
        jpvt[rtDW.j_l] = px;
      }

      pu--;
    }

    rtDW.j_l--;
  }

  // compute the norms of the free columns
  rtDW.j_l = pl;
  while (rtDW.j_l <= pu) {
    QRV2Norm_real_T_j(&xVec[rtDW.j_l * M], M, &qrAux[rtDW.j_l]);
    work[rtDW.j_l] = qrAux[rtDW.j_l];
    rtDW.j_l++;
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
      rtDW.j_l = l;
      while (rtDW.j_l <= pu) {
        if (qrAux[rtDW.j_l] > rtDW.maxnrm) {
          rtDW.maxnrm = qrAux[rtDW.j_l];
          maxj = rtDW.j_l;
        }

        rtDW.j_l++;
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
      QRV2Norm_real_T_j(&xVec[maxj], mml, &rtDW.nrmxl);
      rtDW.maxnrm = fabs(rtDW.nrmxl);
      if (rtDW.maxnrm != 0.0) {
        if (fabs(xVec[maxj]) != 0.0) {
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
        rtDW.j_l = l + 1;
        while (rtDW.j_l < N) {
          plj = rtDW.j_l * M + l;
          px2 = plj;
          rtDW.t_p = 0.0;
          for (i = mml; i > 0; i--) {
            rtDW.t_p -= xVec[px] * xVec[px2];
            px++;
            px2++;
          }

          px = maxj;
          px2 = plj;
          rtDW.t_p /= xVec[maxj];
          for (i = mml; i > 0; i--) {
            xVec[px2] += rtDW.t_p * xVec[px];
            px++;
            px2++;
          }

          px = maxj;
          px2 = 0;
          if (qrAux[rtDW.j_l] == 0.0) {
            px2 = 1;
          }

          if ((rtDW.j_l >= pl) && (rtDW.j_l <= pu) && (px2 == 0)) {
            rtDW.maxnrm = fabs(xVec[plj]) / qrAux[rtDW.j_l];
            rtDW.tt = 1.0 - rtDW.maxnrm * rtDW.maxnrm;
            if (rtDW.tt < 0.0) {
              rtDW.tt = 0.0;
            }

            rtDW.t_p = rtDW.tt;
            rtDW.maxnrm = qrAux[rtDW.j_l] / work[rtDW.j_l];
            rtDW.tt = 0.05 * rtDW.tt * rtDW.maxnrm * rtDW.maxnrm + 1.0;
            if (rtDW.tt != 1.0) {
              qrAux[rtDW.j_l] *= sqrt(rtDW.t_p);
            } else {
              QRV2Norm_real_T_j(&xVec[plj + 1], mml - 1, &rtDW.maxnrm);
              qrAux[rtDW.j_l] = rtDW.maxnrm;
              work[rtDW.j_l] = qrAux[rtDW.j_l];
            }
          }

          rtDW.j_l++;
        }

        // save the transformation.
        qrAux[l] = xVec[px];
        xVec[px] = -rtDW.nrmxl;
      }
    }
  }

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

void QRCompQy_real_T(real_T qr[], const real_T qrAuxj[], real_T y[], int32_T n,
                     int32_T j)
{
  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

void QRSL1_real_T(real_T qr[], const real_T qrAux[], real_T y[], int32_T n,
                  int32_T k)
{
  int32_T j;
  int32_T pqraux;
  int32_T y_0;

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
      QRCompQy_real_T(&qr[0], &qrAux[pqraux], &y[y_0], n, j);
      y_0 = pqraux - 1;
      pqraux--;
      j--;
    }
  }

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

static void QRE_real_T_j(real_T outQ[], real_T outR[], real_T outE[], real_T
  qrAux[], real_T work[], int32_T jpvt[], real_T sPtr[], int32_T M, int32_T N,
  boolean_T economy)
{
  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
  QRDC_real_T_j(&outR[0], &qrAux[0], &jpvt[0], &work[0], M, N);

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

  rtDW.L_tmp = 0;
  rtDW.j_d = 0;
  while (rtDW.j_d < M * rtDW.L) {
    outQ[rtDW.j_d] = 0.0;
    rtDW.j_d++;
  }

  rtDW.j_d = 0;
  while (rtDW.j_d < rtDW.L) {
    outQ[rtDW.L_tmp] = 1.0;
    rtDW.L_tmp = (rtDW.L_tmp + M) + 1;
    rtDW.j_d++;
  }

  // Convert cols of identity into cols of q. Use info stored in lower triangle of r and in vector qraux to work on columns of identity matrix I and transform them into q*I(:,j) i.e. the columns of q. 
  rtDW.L_tmp = 0;
  rtDW.j_d = 0;
  while (rtDW.j_d < rtDW.L) {
    QRSL1_real_T(&outR[0], &qrAux[0], &outQ[rtDW.L_tmp], M, N);
    rtDW.L_tmp += M;
    rtDW.j_d++;
  }

  if (economy && (M > N)) {
    // Copy upper triangle of r to s
    rtDW.L = 0;
    rtDW.ps = 0;
    rtDW.j_d = 1;
    while (rtDW.j_d - 1 < N) {
      rtDW.L_tmp = 0;
      while (rtDW.L_tmp <= rtDW.j_d - 1) {
        sPtr[rtDW.ps] = outR[rtDW.L];
        rtDW.ps++;
        rtDW.L++;
        rtDW.L_tmp++;
      }

      rtDW.L = (rtDW.L + M) - rtDW.j_d;
      rtDW.L_tmp = 0;
      while (rtDW.L_tmp < N - rtDW.j_d) {
        sPtr[rtDW.ps] = 0.0;
        rtDW.ps++;
        rtDW.L_tmp++;
      }

      rtDW.j_d++;
    }
  } else {
    // Zero strict lower triangle of r
    rtDW.L = M * N - 1;
    rtDW.j_d = N;
    while (rtDW.j_d - 1 >= 0) {
      rtDW.L_tmp = M;
      while (rtDW.L_tmp > rtDW.j_d) {
        outR[rtDW.L] = 0.0;
        rtDW.L--;
        rtDW.L_tmp--;
      }

      if (M < rtDW.j_d) {
        rtDW.L -= M;
      } else {
        rtDW.L -= rtDW.j_d;
      }

      rtDW.j_d--;
    }
  }

  // form permutation vector e
  rtDW.L = 0;
  rtDW.L_tmp = 0;
  rtDW.j_d = 0;
  while (rtDW.j_d < N) {
    outE[rtDW.L] = jpvt[rtDW.L_tmp] + 1;
    rtDW.L_tmp = rtDW.L + 1;
    rtDW.L++;
    rtDW.j_d++;
  }

  // End of S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
}

static void Warp_stepImpl(vision_internal_blocks_Warp *b_this, const boolean_T
  Image[900000], const real_T input2[9], boolean_T Jout[900000])
{
  __m128d tmp_0;
  __m128d tmp_1;
  boolean_T guard1;

  // Start for MATLABSystem: '<S2>/Warp'
  memcpy(&b_this->TformProjective.T[0], &input2[0], 9U * sizeof(real_T));
  for (rtDW.p1 = 0; rtDW.p1 < 3; rtDW.p1++) {
    rtDW.B_c[3 * rtDW.p1] = b_this->TformProjective.T[rtDW.p1];
    rtDW.B_c[3 * rtDW.p1 + 1] = b_this->TformProjective.T[rtDW.p1 + 3];
    rtDW.B_c[3 * rtDW.p1 + 2] = b_this->TformProjective.T[rtDW.p1 + 6];
  }

  for (rtDW.p1 = 0; rtDW.p1 < 1200; rtDW.p1++) {
    for (rtDW.p2 = 0; rtDW.p2 < 750; rtDW.p2++) {
      rtDW.p3 = 750 * rtDW.p1 + rtDW.p2;

      // Start for MATLABSystem: '<S2>/Warp'
      rtDW.xp[rtDW.p3] = static_cast<real_T>(rtDW.p1) + 1.0;
      rtDW.yp[rtDW.p3] = static_cast<real_T>(rtDW.p2) + 1.0;
    }
  }

  for (rtDW.p1 = 0; rtDW.p1 <= 899998; rtDW.p1 += 2) {
    // Start for MATLABSystem: '<S2>/Warp'
    tmp_0 = _mm_loadu_pd(&rtDW.xp[rtDW.p1]);
    tmp_1 = _mm_set1_pd(0.5);

    // Start for MATLABSystem: '<S2>/Warp'
    _mm_storeu_pd(&rtDW.xp[rtDW.p1], _mm_add_pd(_mm_sub_pd(tmp_0, tmp_1), tmp_1));
    tmp_0 = _mm_loadu_pd(&rtDW.yp[rtDW.p1]);
    _mm_storeu_pd(&rtDW.yp[rtDW.p1], _mm_add_pd(_mm_sub_pd(tmp_0, tmp_1), tmp_1));
  }

  // Start for MATLABSystem: '<S2>/Warp'
  guard1 = false;
  if (rtDW.B_c[8] == 1.0) {
    boolean_T exitg1;
    rtDW.x_b[0] = (rtDW.B_c[2] == 0.0);
    rtDW.x_b[1] = (rtDW.B_c[5] == 0.0);
    rtDW.y_n = true;
    rtDW.p1 = 0;
    exitg1 = false;
    while ((!exitg1) && (rtDW.p1 <= 1)) {
      if (!rtDW.x_b[rtDW.p1]) {
        rtDW.y_n = false;
        exitg1 = true;
      } else {
        rtDW.p1++;
      }
    }

    if (rtDW.y_n) {
      if (fabs(rtDW.B_c[1]) > fabs(rtDW.B_c[0])) {
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
      for (rtDW.p1 = 0; rtDW.p1 <= 899998; rtDW.p1 += 2) {
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
    memcpy(&rtDW.x[0], &rtDW.B_c[0], 9U * sizeof(real_T));
    rtDW.p1 = 1;
    rtDW.p2 = 3;
    rtDW.p3 = 6;
    rtDW.absx11 = fabs(rtDW.B_c[0]);
    rtDW.absx21 = fabs(rtDW.B_c[1]);
    rtDW.absx31 = fabs(rtDW.B_c[2]);
    if ((rtDW.absx21 > rtDW.absx11) && (rtDW.absx21 > rtDW.absx31)) {
      rtDW.p1 = 4;
      rtDW.p2 = 0;
      rtDW.x[0] = rtDW.B_c[1];
      rtDW.x[1] = rtDW.B_c[0];
      rtDW.x[3] = rtDW.B_c[4];
      rtDW.x[4] = rtDW.B_c[3];
      rtDW.x[6] = rtDW.B_c[7];
      rtDW.x[7] = rtDW.B_c[6];
    } else if (rtDW.absx31 > rtDW.absx11) {
      rtDW.p1 = 7;
      rtDW.p3 = 0;
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
    if (fabs(rtDW.x[5]) > fabs(rtDW.x[4])) {
      rtDW.itmp = rtDW.p2;
      rtDW.p2 = rtDW.p3;
      rtDW.p3 = rtDW.itmp;
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
    rtDW.B_c[rtDW.p2] = -(rtDW.x[3] * rtDW.absx21 + rtDW.x[6] * rtDW.absx11) /
      rtDW.x[0];
    rtDW.B_c[rtDW.p2 + 1] = rtDW.absx21;
    rtDW.B_c[rtDW.p2 + 2] = rtDW.absx11;
    rtDW.absx11 = 1.0 / rtDW.x[8];
    rtDW.absx21 = -rtDW.x[7] * rtDW.absx11 / rtDW.x[4];
    rtDW.B_c[rtDW.p3] = -(rtDW.x[3] * rtDW.absx21 + rtDW.x[6] * rtDW.absx11) /
      rtDW.x[0];
    rtDW.B_c[rtDW.p3 + 1] = rtDW.absx21;
    rtDW.B_c[rtDW.p3 + 2] = rtDW.absx11;
    rtDW.absx11 = rtDW.B_c[2];
    rtDW.absx31 = rtDW.B_c[5];
    rtDW.absx21 = rtDW.B_c[0];
    rtDW.b_B_idx_0 = rtDW.B_c[3];
    rtDW.b_B_idx_1 = rtDW.B_c[1];
    rtDW.b_B_idx_2 = rtDW.B_c[4];
    rtDW.B_g = rtDW.B_c[8];
    rtDW.B_me = rtDW.B_c[6];
    rtDW.B_n = rtDW.B_c[7];
    for (rtDW.p1 = 0; rtDW.p1 <= 899998; rtDW.p1 += 2) {
      __m128d tmp;
      tmp_0 = _mm_loadu_pd(&rtDW.xp[rtDW.p1]);
      tmp_1 = _mm_loadu_pd(&rtDW.yp[rtDW.p1]);
      tmp = _mm_add_pd(_mm_add_pd(_mm_mul_pd(_mm_set1_pd(rtDW.absx11), tmp_0),
        _mm_mul_pd(_mm_set1_pd(rtDW.absx31), tmp_1)), _mm_set1_pd(rtDW.B_g));
      _mm_storeu_pd(&rtDW.b_varargout_1[rtDW.p1], _mm_div_pd(_mm_add_pd
        (_mm_add_pd(_mm_mul_pd(_mm_set1_pd(rtDW.absx21), tmp_0), _mm_mul_pd
                    (_mm_set1_pd(rtDW.b_B_idx_0), tmp_1)), _mm_set1_pd(rtDW.B_me)),
        tmp));
      _mm_storeu_pd(&rtDW.xp[rtDW.p1], _mm_div_pd(_mm_add_pd(_mm_add_pd
        (_mm_mul_pd(_mm_set1_pd(rtDW.b_B_idx_1), tmp_0), _mm_mul_pd(_mm_set1_pd
        (rtDW.b_B_idx_2), tmp_1)), _mm_set1_pd(rtDW.B_n)), tmp));
    }
  }

  for (rtDW.p1 = 0; rtDW.p1 < 900000; rtDW.p1++) {
    // Start for MATLABSystem: '<S2>/Warp'
    rtDW.b_varargout_1[rtDW.p1] = (rtDW.b_varargout_1[rtDW.p1] - 0.5) + 0.5;
    rtDW.xp[rtDW.p1] = (rtDW.xp[rtDW.p1] - 0.5) + 0.5;
    rtDW.inputImage_[rtDW.p1] = Image[rtDW.p1];
  }

  rtDW.fillValues = 0U;

  // Start for MATLABSystem: '<S2>/Warp'
  rtDW.b_inputImageSize[0] = 750.0;
  rtDW.b_inputImageSize[1] = 1200.0;
  rtDW.b_inputImageSize[2] = 1.0;
  rtDW.b_outputImageSize[0] = 750.0;
  rtDW.b_outputImageSize[1] = 1200.0;
  imterp2d64f_uint8(&rtDW.inputImage_[0], &rtDW.b_inputImageSize[0], &rtDW.xp[0],
                    &rtDW.b_varargout_1[0], &rtDW.b_outputImageSize[0], 2.0,
                    true, &rtDW.fillValues, &rtDW.outputImage[0]);
  for (rtDW.p1 = 0; rtDW.p1 < 900000; rtDW.p1++) {
    // Start for MATLABSystem: '<S2>/Warp'
    Jout[rtDW.p1] = (rtDW.outputImage[rtDW.p1] > 0.5);
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
static void do_vectors(const coder::array<int32_T, 1U> &a, const coder::array<
  int32_T, 1U> &b, coder::array<int32_T, 1U> &c, coder::array<int32_T, 1U> &ia,
  coder::array<int32_T, 1U> &ib)
{
  int32_T c_ialast;
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T nc;
  int32_T nia;
  int32_T nib;
  rtDW.na = a.size(0);
  rtDW.nb = b.size(0);
  rtDW.ncmax = a.size(0) + b.size(0);
  c.set_size(rtDW.ncmax);
  ia.set_size(a.size(0));
  ib.set_size(b.size(0));
  nc = -1;
  nia = -1;
  nib = 0;
  iafirst = 1;
  ialast = 0;
  ibfirst = 0;
  iblast = 0;
  while ((ialast + 1 <= rtDW.na) && (iblast + 1 <= rtDW.nb)) {
    int32_T ak;
    int32_T b_iblast;
    int32_T bk;
    c_ialast = ialast + 1;
    ak = a[ialast];
    while ((c_ialast < a.size(0)) && (a[c_ialast] == ak)) {
      c_ialast++;
    }

    ialast = c_ialast - 1;
    b_iblast = iblast + 1;
    bk = b[iblast];
    while ((b_iblast < b.size(0)) && (b[b_iblast] == bk)) {
      b_iblast++;
    }

    iblast = b_iblast - 1;
    if (ak == bk) {
      nc++;
      c[nc] = ak;
      nia++;
      ia[nia] = iafirst;
      ialast = c_ialast;
      iafirst = c_ialast + 1;
      iblast = b_iblast;
      ibfirst = b_iblast;
    } else if (ak < bk) {
      nc++;
      nia++;
      c[nc] = ak;
      ia[nia] = iafirst;
      ialast = c_ialast;
      iafirst = c_ialast + 1;
    } else {
      nc++;
      nib++;
      c[nc] = bk;
      ib[nib - 1] = ibfirst + 1;
      iblast = b_iblast;
      ibfirst = b_iblast;
    }
  }

  while (ialast + 1 <= rtDW.na) {
    c_ialast = ialast + 1;
    while ((c_ialast < a.size(0)) && (a[c_ialast] == a[ialast])) {
      c_ialast++;
    }

    nc++;
    nia++;
    c[nc] = a[ialast];
    ia[nia] = iafirst;
    ialast = c_ialast;
    iafirst = c_ialast + 1;
  }

  while (iblast + 1 <= rtDW.nb) {
    rtDW.na = iblast + 1;
    while ((rtDW.na < b.size(0)) && (b[rtDW.na] == b[iblast])) {
      rtDW.na++;
    }

    nc++;
    nib++;
    c[nc] = b[iblast];
    ib[nib - 1] = ibfirst + 1;
    iblast = rtDW.na;
    ibfirst = rtDW.na;
  }

  if (a.size(0) > 0) {
    if (nia + 1 < 1) {
      ia.set_size(0);
    } else {
      ia.set_size(nia + 1);
    }
  }

  if (b.size(0) > 0) {
    if (nib < 1) {
      ib.set_size(0);
    } else {
      ib.set_size(nib);
    }
  }

  if (rtDW.ncmax > 0) {
    if (nc + 1 < 1) {
      c.set_size(0);
    } else {
      c.set_size(nc + 1);
    }
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
static void findpeaks(const real_T Yin[1200], coder::array<real_T, 2U> &Ypk,
                      coder::array<real_T, 2U> &Xpk)
{
  char_T dir;
  char_T previousdir;
  boolean_T isinfyk;
  boolean_T isinfykfirst;
  rtDW.fPk.set_size(1200);
  rtDW.iInfinite.set_size(1200);
  rtDW.nPk = 0;
  rtDW.nInf = -1;
  dir = 'n';
  rtDW.kfirst = -1;
  rtDW.ykfirst = (rtInf);
  isinfykfirst = true;
  for (rtDW.k_l = 0; rtDW.k_l < 1200; rtDW.k_l++) {
    rtDW.yk = Yin[rtDW.k_l];
    if (rtIsNaN(rtDW.yk)) {
      rtDW.yk = (rtInf);
      isinfyk = true;
    } else if (rtIsInf(rtDW.yk)) {
      if (rtDW.yk > 0.0) {
        isinfyk = true;
        rtDW.nInf++;
        rtDW.iInfinite[rtDW.nInf] = static_cast<int16_T>(rtDW.k_l + 1);
      } else {
        isinfyk = false;
      }
    } else {
      isinfyk = false;
    }

    if (rtDW.yk != rtDW.ykfirst) {
      previousdir = dir;
      if (isinfyk || isinfykfirst) {
        dir = 'n';
      } else if (rtDW.yk < rtDW.ykfirst) {
        dir = 'd';
        if (previousdir == 'i') {
          rtDW.nPk++;
          rtDW.fPk[rtDW.nPk - 1] = rtDW.kfirst + 1;
        }
      } else {
        dir = 'i';
      }

      rtDW.ykfirst = rtDW.yk;
      rtDW.kfirst = rtDW.k_l;
      isinfykfirst = isinfyk;
    }
  }

  if (rtDW.nPk < 1) {
    rtDW.kfirst = 0;
  } else {
    rtDW.kfirst = rtDW.nPk;
  }

  rtDW.iPk.set_size(rtDW.kfirst);
  rtDW.nPk = -1;
  for (rtDW.k_l = 0; rtDW.k_l < rtDW.kfirst; rtDW.k_l++) {
    rtDW.fPk_d = rtDW.fPk[rtDW.k_l];
    rtDW.ykfirst = Yin[rtDW.fPk_d - 1];
    if (rtDW.ykfirst > (rtMinusInf)) {
      rtDW.yk = Yin[rtDW.fPk_d - 2];
      rtDW.u1 = Yin[rtDW.fPk_d];
      if ((rtDW.yk >= rtDW.u1) || rtIsNaN(rtDW.u1)) {
        rtDW.u1 = rtDW.yk;
      }

      if (rtDW.ykfirst - rtDW.u1 >= 0.0) {
        rtDW.nPk++;
        rtDW.iPk[rtDW.nPk] = rtDW.fPk_d;
      }
    }
  }

  if (rtDW.nPk + 1 < 1) {
    rtDW.nPk = -1;
  }

  rtDW.iPk_c.set_size(rtDW.nPk + 1);
  for (rtDW.kfirst = 0; rtDW.kfirst <= rtDW.nPk; rtDW.kfirst++) {
    rtDW.iPk_c[rtDW.kfirst] = rtDW.iPk[rtDW.kfirst];
  }

  if (rtDW.nInf + 1 < 1) {
    rtDW.nInf = -1;
  }

  rtDW.iPk.set_size(rtDW.nInf + 1);
  for (rtDW.kfirst = 0; rtDW.kfirst <= rtDW.nInf; rtDW.kfirst++) {
    rtDW.iPk[rtDW.kfirst] = rtDW.iInfinite[rtDW.kfirst];
  }

  do_vectors(rtDW.iPk_c, rtDW.iPk, rtDW.b_iPk, rtDW.fPk, rtDW.idx);
  rtDW.nInf = rtDW.b_iPk.size(0);
  rtDW.y.set_size(1, rtDW.b_iPk.size(0));
  if (rtDW.b_iPk.size(0) > 0) {
    rtDW.y[0] = 1;
    rtDW.nPk = 1;
    for (rtDW.kfirst = 2; rtDW.kfirst <= rtDW.nInf; rtDW.kfirst++) {
      rtDW.nPk++;
      rtDW.y[rtDW.kfirst - 1] = rtDW.nPk;
    }
  }

  rtDW.idx.set_size(rtDW.y.size(1));
  rtDW.nPk = rtDW.y.size(1);
  for (rtDW.kfirst = 0; rtDW.kfirst < rtDW.nPk; rtDW.kfirst++) {
    rtDW.idx[rtDW.kfirst] = rtDW.y[rtDW.kfirst];
  }

  if (rtDW.idx.size(0) > 1200) {
    rtDW.fPk.set_size(1200);
    rtDW.idx.set_size(1200);
  } else {
    rtDW.fPk.set_size(rtDW.idx.size(0));
  }

  if (rtDW.fPk.size(0) < 1) {
    rtDW.nPk = -1;
  } else {
    rtDW.nPk = rtDW.fPk.size(0) - 1;
  }

  rtDW.iPk.set_size(rtDW.nPk + 1);
  for (rtDW.kfirst = 0; rtDW.kfirst <= rtDW.nPk; rtDW.kfirst++) {
    rtDW.iPk[rtDW.kfirst] = rtDW.b_iPk[rtDW.idx[rtDW.kfirst] - 1];
  }

  Ypk.set_size(1, rtDW.iPk.size(0));
  rtDW.nPk = rtDW.iPk.size(0);
  Xpk.set_size(1, rtDW.iPk.size(0));
  for (rtDW.kfirst = 0; rtDW.kfirst < rtDW.nPk; rtDW.kfirst++) {
    rtDW.nInf = rtDW.iPk[rtDW.kfirst];
    Ypk[rtDW.kfirst] = Yin[rtDW.nInf - 1];
    Xpk[rtDW.kfirst] = static_cast<int16_T>(static_cast<int16_T>(rtDW.nInf - 1)
      + 1);
  }
}

static void binary_expand_op_1(coder::array<boolean_T, 1U> &in1, const coder::
  array<boolean_T, 1U> &in2, const coder::array<real_T, 1U> &in3, real_T in4)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function3'
  if (in3.size(0) == 1) {
    in1.set_size(in2.size(0));
  } else {
    in1.set_size(in3.size(0));
  }

  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }

  for (int32_T i = 0; i < loop_ub; i++) {
    in1[i] = (in2[i * stride_0_0] && (in3[i * stride_1_0] >= in4 - 80.0));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function3'
}

static void binary_expand_op(coder::array<boolean_T, 1U> &in1, const coder::
  array<real_T, 1U> &in2, real_T in3)
{
  coder::array<boolean_T, 1U> in1_0;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function3'
  if (in2.size(0) == 1) {
    in1_0.set_size(in1.size(0));
  } else {
    in1_0.set_size(in2.size(0));
  }

  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }

  for (int32_T i = 0; i < loop_ub; i++) {
    in1_0[i] = (in1[i * stride_0_0] && (in2[i * stride_1_0] >= in3 - 80.0));
  }

  in1.set_size(in1_0.size(0));
  loop_ub = in1_0.size(0);
  for (int32_T i = 0; i < loop_ub; i++) {
    in1[i] = in1_0[i];
  }

  // End of MATLAB Function: '<S2>/MATLAB Function3'
}

static void and_j(coder::array<boolean_T, 1U> &in1, const coder::array<boolean_T,
                  1U> &in2, const coder::array<boolean_T, 1U> &in3)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function3'
  if (in3.size(0) == 1) {
    in1.set_size(in2.size(0));
  } else {
    in1.set_size(in3.size(0));
  }

  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }

  for (int32_T i = 0; i < loop_ub; i++) {
    in1[i] = (in2[i * stride_0_0] && in3[i * stride_1_0]);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function3'
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
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

// Function for MATLAB Function: '<S2>/MATLAB Function3'
static real_T xnrm2(int32_T n, const coder::array<real_T, 2U> &x, int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      rtDW.scale = 3.3121686421112381E-170;
      rtDW.kend = (ix0 + n) - 1;
      for (rtDW.k = ix0; rtDW.k <= rtDW.kend; rtDW.k++) {
        rtDW.absxk = fabs(x[rtDW.k - 1]);
        if (rtDW.absxk > rtDW.scale) {
          rtDW.t_g = rtDW.scale / rtDW.absxk;
          y = y * rtDW.t_g * rtDW.t_g + 1.0;
          rtDW.scale = rtDW.absxk;
        } else {
          rtDW.t_g = rtDW.absxk / rtDW.scale;
          y += rtDW.t_g * rtDW.t_g;
        }
      }

      y = rtDW.scale * sqrt(y);
    }
  }

  return y;
}

static real_T rt_hypotd_snf_j(real_T u0, real_T u1)
{
  real_T y;
  rtDW.a = fabs(u0);
  rtDW.b = fabs(u1);
  if (rtDW.a < rtDW.b) {
    rtDW.a /= rtDW.b;
    y = sqrt(rtDW.a * rtDW.a + 1.0) * rtDW.b;
  } else if (rtDW.a > rtDW.b) {
    rtDW.b /= rtDW.a;
    y = sqrt(rtDW.b * rtDW.b + 1.0) * rtDW.a;
  } else if (rtIsNaN(rtDW.b)) {
    y = (rtNaN);
  } else {
    y = rtDW.a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
static void xgeqp3(coder::array<real_T, 2U> &A, coder::array<real_T, 1U> &tau,
                   int32_T jpvt[3])
{
  __m128d tmp;
  int32_T exitg1;
  boolean_T exitg2;
  boolean_T guard1;
  rtDW.m_d = A.size(0);
  if (A.size(0) <= 3) {
    rtDW.minmana = A.size(0);
  } else {
    rtDW.minmana = 3;
  }

  tau.set_size(rtDW.minmana);
  for (rtDW.itemp = 0; rtDW.itemp < rtDW.minmana; rtDW.itemp++) {
    tau[rtDW.itemp] = 0.0;
  }

  guard1 = false;
  if (A.size(0) == 0) {
    guard1 = true;
  } else {
    if (A.size(0) <= 3) {
      rtDW.itemp = A.size(0);
    } else {
      rtDW.itemp = 3;
    }

    if (rtDW.itemp < 1) {
      guard1 = true;
    } else {
      jpvt[0] = 1;
      jpvt[1] = 2;
      jpvt[2] = 3;
      tau.set_size(rtDW.minmana);
      for (rtDW.itemp = 0; rtDW.itemp < rtDW.minmana; rtDW.itemp++) {
        tau[rtDW.itemp] = 0.0;
      }

      rtDW.ma = A.size(0);
      if (A.size(0) <= 3) {
        rtDW.minmana = A.size(0);
      } else {
        rtDW.minmana = 3;
      }

      rtDW.work[0] = 0.0;
      rtDW.vn1_f = xnrm2(A.size(0), A, 1);
      rtDW.vn1[0] = rtDW.vn1_f;
      rtDW.vn2[0] = rtDW.vn1_f;
      rtDW.work[1] = 0.0;
      rtDW.vn1_f = xnrm2(A.size(0), A, A.size(0) + 1);
      rtDW.vn1[1] = rtDW.vn1_f;
      rtDW.vn2[1] = rtDW.vn1_f;
      rtDW.work[2] = 0.0;
      rtDW.vn1_f = xnrm2(A.size(0), A, (A.size(0) << 1) + 1);
      rtDW.vn1[2] = rtDW.vn1_f;
      rtDW.vn2[2] = rtDW.vn1_f;
      for (rtDW.b_j_g = 0; rtDW.b_j_g < rtDW.minmana; rtDW.b_j_g++) {
        rtDW.iy = rtDW.b_j_g * rtDW.ma;
        rtDW.ii = rtDW.iy + rtDW.b_j_g;
        rtDW.mmi = rtDW.m_d - rtDW.b_j_g;
        rtDW.pvt = 3 - rtDW.b_j_g;
        rtDW.knt = 0;
        if (3 - rtDW.b_j_g > 1) {
          rtDW.smax = fabs(rtDW.vn1[rtDW.b_j_g]);
          for (rtDW.itemp = 2; rtDW.itemp <= rtDW.pvt; rtDW.itemp++) {
            rtDW.s = fabs(rtDW.vn1[(rtDW.b_j_g + rtDW.itemp) - 1]);
            if (rtDW.s > rtDW.smax) {
              rtDW.knt = rtDW.itemp - 1;
              rtDW.smax = rtDW.s;
            }
          }
        }

        rtDW.pvt = rtDW.b_j_g + rtDW.knt;
        if (rtDW.pvt != rtDW.b_j_g) {
          rtDW.ix = rtDW.pvt * rtDW.ma;
          for (rtDW.knt = 0; rtDW.knt < rtDW.m_d; rtDW.knt++) {
            rtDW.jy = rtDW.ix + rtDW.knt;
            rtDW.smax = A[rtDW.jy];
            rtDW.itemp = rtDW.iy + rtDW.knt;
            A[rtDW.jy] = A[rtDW.itemp];
            A[rtDW.itemp] = rtDW.smax;
          }

          rtDW.itemp = jpvt[rtDW.pvt];
          jpvt[rtDW.pvt] = jpvt[rtDW.b_j_g];
          jpvt[rtDW.b_j_g] = rtDW.itemp;
          rtDW.vn1[rtDW.pvt] = rtDW.vn1[rtDW.b_j_g];
          rtDW.vn2[rtDW.pvt] = rtDW.vn2[rtDW.b_j_g];
        }

        if (rtDW.b_j_g + 1 < rtDW.m_d) {
          rtDW.s = A[rtDW.ii];
          rtDW.pvt = rtDW.ii + 2;
          tau[rtDW.b_j_g] = 0.0;
          if (rtDW.mmi > 0) {
            rtDW.smax = xnrm2(rtDW.mmi - 1, A, rtDW.ii + 2);
            if (rtDW.smax != 0.0) {
              rtDW.smax = rt_hypotd_snf_j(A[rtDW.ii], rtDW.smax);
              if (A[rtDW.ii] >= 0.0) {
                rtDW.smax = -rtDW.smax;
              }

              if (fabs(rtDW.smax) < 1.0020841800044864E-292) {
                rtDW.knt = 0;
                rtDW.itemp = rtDW.ii + rtDW.mmi;
                do {
                  rtDW.knt++;
                  rtDW.iy = (((((rtDW.itemp - rtDW.ii) - 1) / 2) << 1) + rtDW.ii)
                    + 2;
                  rtDW.jy = rtDW.iy - 2;
                  for (rtDW.ix = rtDW.pvt; rtDW.ix <= rtDW.jy; rtDW.ix += 2) {
                    tmp = _mm_loadu_pd(&A[rtDW.ix - 1]);
                    _mm_storeu_pd(&A[rtDW.ix - 1], _mm_mul_pd(tmp, _mm_set1_pd
                      (9.9792015476736E+291)));
                  }

                  for (rtDW.ix = rtDW.iy; rtDW.ix <= rtDW.itemp; rtDW.ix++) {
                    A[rtDW.ix - 1] = A[rtDW.ix - 1] * 9.9792015476736E+291;
                  }

                  rtDW.smax *= 9.9792015476736E+291;
                  rtDW.s *= 9.9792015476736E+291;
                } while ((fabs(rtDW.smax) < 1.0020841800044864E-292) &&
                         (rtDW.knt < 20));

                rtDW.smax = rt_hypotd_snf_j(rtDW.s, xnrm2(rtDW.mmi - 1, A,
                  rtDW.ii + 2));
                if (rtDW.s >= 0.0) {
                  rtDW.smax = -rtDW.smax;
                }

                tau[rtDW.b_j_g] = (rtDW.smax - rtDW.s) / rtDW.smax;
                rtDW.s = 1.0 / (rtDW.s - rtDW.smax);
                for (rtDW.ix = rtDW.pvt; rtDW.ix <= rtDW.jy; rtDW.ix += 2) {
                  tmp = _mm_loadu_pd(&A[rtDW.ix - 1]);
                  _mm_storeu_pd(&A[rtDW.ix - 1], _mm_mul_pd(tmp, _mm_set1_pd
                    (rtDW.s)));
                }

                for (rtDW.ix = rtDW.iy; rtDW.ix <= rtDW.itemp; rtDW.ix++) {
                  A[rtDW.ix - 1] = A[rtDW.ix - 1] * rtDW.s;
                }

                for (rtDW.itemp = 0; rtDW.itemp < rtDW.knt; rtDW.itemp++) {
                  rtDW.smax *= 1.0020841800044864E-292;
                }

                rtDW.s = rtDW.smax;
              } else {
                tau[rtDW.b_j_g] = (rtDW.smax - A[rtDW.ii]) / rtDW.smax;
                rtDW.s = 1.0 / (A[rtDW.ii] - rtDW.smax);
                rtDW.ix = rtDW.ii + rtDW.mmi;
                rtDW.itemp = (((((rtDW.ix - rtDW.ii) - 1) / 2) << 1) + rtDW.ii)
                  + 2;
                rtDW.iy = rtDW.itemp - 2;
                for (rtDW.knt = rtDW.pvt; rtDW.knt <= rtDW.iy; rtDW.knt += 2) {
                  tmp = _mm_loadu_pd(&A[rtDW.knt - 1]);
                  _mm_storeu_pd(&A[rtDW.knt - 1], _mm_mul_pd(tmp, _mm_set1_pd
                    (rtDW.s)));
                }

                for (rtDW.knt = rtDW.itemp; rtDW.knt <= rtDW.ix; rtDW.knt++) {
                  A[rtDW.knt - 1] = A[rtDW.knt - 1] * rtDW.s;
                }

                rtDW.s = rtDW.smax;
              }
            }
          }

          A[rtDW.ii] = rtDW.s;
        } else {
          tau[rtDW.b_j_g] = 0.0;
        }

        if (rtDW.b_j_g + 1 < 3) {
          rtDW.smax = A[rtDW.ii];
          A[rtDW.ii] = 1.0;
          rtDW.knt = (rtDW.ii + rtDW.ma) + 1;
          if (tau[rtDW.b_j_g] != 0.0) {
            rtDW.pvt = rtDW.mmi - 1;
            rtDW.itemp = (rtDW.ii + rtDW.mmi) - 1;
            while ((rtDW.pvt + 1 > 0) && (A[rtDW.itemp] == 0.0)) {
              rtDW.pvt--;
              rtDW.itemp--;
            }

            rtDW.ix = 1 - rtDW.b_j_g;
            exitg2 = false;
            while ((!exitg2) && (rtDW.ix + 1 > 0)) {
              rtDW.itemp = rtDW.ix * rtDW.ma + rtDW.knt;
              rtDW.iy = rtDW.itemp;
              do {
                exitg1 = 0;
                if (rtDW.iy <= rtDW.itemp + rtDW.pvt) {
                  if (A[rtDW.iy - 1] != 0.0) {
                    exitg1 = 1;
                  } else {
                    rtDW.iy++;
                  }
                } else {
                  rtDW.ix--;
                  exitg1 = 2;
                }
              } while (exitg1 == 0);

              if (exitg1 == 1) {
                exitg2 = true;
              }
            }
          } else {
            rtDW.pvt = -1;
            rtDW.ix = -1;
          }

          if (rtDW.pvt + 1 > 0) {
            if (rtDW.ix + 1 != 0) {
              memset(&rtDW.work[0], 0, static_cast<uint32_T>(rtDW.ix + 1) *
                     sizeof(real_T));
              rtDW.jy = 0;
              rtDW.d_ix = rtDW.ma * rtDW.ix + rtDW.knt;
              for (rtDW.itemp = rtDW.knt; rtDW.ma < 0 ? rtDW.itemp >= rtDW.d_ix :
                   rtDW.itemp <= rtDW.d_ix; rtDW.itemp += rtDW.ma) {
                rtDW.s = 0.0;
                rtDW.e = rtDW.itemp + rtDW.pvt;
                for (rtDW.iy = rtDW.itemp; rtDW.iy <= rtDW.e; rtDW.iy++) {
                  rtDW.s += A[(rtDW.ii + rtDW.iy) - rtDW.itemp] * A[rtDW.iy - 1];
                }

                rtDW.work[rtDW.jy] += rtDW.s;
                rtDW.jy++;
              }
            }

            if (!(-tau[rtDW.b_j_g] == 0.0)) {
              for (rtDW.itemp = 0; rtDW.itemp <= rtDW.ix; rtDW.itemp++) {
                rtDW.s = rtDW.work[rtDW.itemp];
                if (rtDW.s != 0.0) {
                  rtDW.s *= -tau[rtDW.b_j_g];
                  rtDW.jy = rtDW.pvt + rtDW.knt;
                  for (rtDW.iy = rtDW.knt; rtDW.iy <= rtDW.jy; rtDW.iy++) {
                    A[rtDW.iy - 1] = A[(rtDW.ii + rtDW.iy) - rtDW.knt] * rtDW.s
                      + A[rtDW.iy - 1];
                  }
                }

                rtDW.knt += rtDW.ma;
              }
            }
          }

          A[rtDW.ii] = rtDW.smax;
        }

        for (rtDW.ii = rtDW.b_j_g + 2; rtDW.ii < 4; rtDW.ii++) {
          rtDW.itemp = (rtDW.ii - 1) * rtDW.ma + rtDW.b_j_g;
          rtDW.vn1_f = rtDW.vn1[rtDW.ii - 1];
          if (rtDW.vn1_f != 0.0) {
            rtDW.smax = fabs(A[rtDW.itemp]) / rtDW.vn1_f;
            rtDW.smax = 1.0 - rtDW.smax * rtDW.smax;
            if (rtDW.smax < 0.0) {
              rtDW.smax = 0.0;
            }

            rtDW.s = rtDW.vn1_f / rtDW.vn2[rtDW.ii - 1];
            rtDW.s = rtDW.s * rtDW.s * rtDW.smax;
            if (rtDW.s <= 1.4901161193847656E-8) {
              if (rtDW.b_j_g + 1 < rtDW.m_d) {
                rtDW.vn1_f = xnrm2(rtDW.mmi - 1, A, rtDW.itemp + 2);
                rtDW.vn1[rtDW.ii - 1] = rtDW.vn1_f;
                rtDW.vn2[rtDW.ii - 1] = rtDW.vn1_f;
              } else {
                rtDW.vn1[rtDW.ii - 1] = 0.0;
                rtDW.vn2[rtDW.ii - 1] = 0.0;
              }
            } else {
              rtDW.vn1[rtDW.ii - 1] = rtDW.vn1_f * sqrt(rtDW.smax);
            }
          }
        }
      }
    }
  }

  if (guard1) {
    jpvt[0] = 1;
    jpvt[1] = 2;
    jpvt[2] = 3;
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function3'
static void polyfit(const coder::array<real_T, 1U> &x, const coder::array<real_T,
                    1U> &y, real_T p[3])
{
  __m128d tmp;
  __m128d tmp_0;
  rtDW.V.set_size(x.size(0), 3);
  if (x.size(0) != 0) {
    rtDW.assumedRank = x.size(0);
    for (rtDW.mn = 0; rtDW.mn < rtDW.assumedRank; rtDW.mn++) {
      rtDW.V[rtDW.mn + (rtDW.V.size(0) << 1)] = 1.0;
    }

    rtDW.assumedRank = x.size(0);
    for (rtDW.mn = 0; rtDW.mn < rtDW.assumedRank; rtDW.mn++) {
      rtDW.V[rtDW.mn + rtDW.V.size(0)] = x[rtDW.mn];
    }

    rtDW.assumedRank = x.size(0);
    rtDW.scalarLB = (rtDW.assumedRank / 2) << 1;
    rtDW.vectorUB = rtDW.scalarLB - 2;
    for (rtDW.mn = 0; rtDW.mn <= rtDW.vectorUB; rtDW.mn += 2) {
      tmp = _mm_loadu_pd(&(*(coder::array<real_T, 1U> *)&x)[rtDW.mn]);
      tmp_0 = _mm_loadu_pd(&rtDW.V[rtDW.mn + rtDW.V.size(0)]);
      _mm_storeu_pd(&rtDW.V[rtDW.mn], _mm_mul_pd(tmp, tmp_0));
    }

    for (rtDW.mn = rtDW.scalarLB; rtDW.mn < rtDW.assumedRank; rtDW.mn++) {
      rtDW.V[rtDW.mn] = rtDW.V[rtDW.mn + rtDW.V.size(0)] * x[rtDW.mn];
    }
  }

  rtDW.B_m.set_size(y.size(0));
  rtDW.assumedRank = y.size(0);
  for (rtDW.mn = 0; rtDW.mn < rtDW.assumedRank; rtDW.mn++) {
    rtDW.B_m[rtDW.mn] = y[rtDW.mn];
  }

  xgeqp3(rtDW.V, rtDW.tau, rtDW.jpvt);
  rtDW.assumedRank = 0;
  if (rtDW.V.size(0) <= 3) {
    rtDW.mn = rtDW.V.size(0);
  } else {
    rtDW.mn = 3;
  }

  if (rtDW.mn > 0) {
    for (rtDW.b_mn = 0; rtDW.b_mn < rtDW.mn; rtDW.b_mn++) {
      if (rtDW.V[rtDW.V.size(0) * rtDW.b_mn + rtDW.b_mn] != 0.0) {
        rtDW.assumedRank++;
      }
    }
  }

  p[0] = 0.0;
  p[1] = 0.0;
  p[2] = 0.0;
  rtDW.mn = rtDW.V.size(0);
  if (rtDW.V.size(0) < 3) {
    rtDW.b_mn = rtDW.V.size(0) - 1;
  } else {
    rtDW.b_mn = 2;
  }

  for (rtDW.b_j = 0; rtDW.b_j <= rtDW.b_mn; rtDW.b_j++) {
    if (rtDW.tau[rtDW.b_j] != 0.0) {
      rtDW.wj = rtDW.B_m[rtDW.b_j];
      for (rtDW.c_i = rtDW.b_j + 2; rtDW.c_i <= rtDW.mn; rtDW.c_i++) {
        rtDW.wj += rtDW.V[(rtDW.V.size(0) * rtDW.b_j + rtDW.c_i) - 1] *
          rtDW.B_m[rtDW.c_i - 1];
      }

      rtDW.wj *= rtDW.tau[rtDW.b_j];
      if (rtDW.wj != 0.0) {
        rtDW.B_m[rtDW.b_j] = rtDW.B_m[rtDW.b_j] - rtDW.wj;
        rtDW.scalarLB = (((((rtDW.mn - rtDW.b_j) - 1) / 2) << 1) + rtDW.b_j) + 2;
        rtDW.vectorUB = rtDW.scalarLB - 2;
        for (rtDW.c_i = rtDW.b_j + 2; rtDW.c_i <= rtDW.vectorUB; rtDW.c_i += 2)
        {
          tmp = _mm_loadu_pd(&rtDW.V[(rtDW.V.size(0) * rtDW.b_j + rtDW.c_i) - 1]);
          tmp_0 = _mm_loadu_pd(&rtDW.B_m[rtDW.c_i - 1]);
          _mm_storeu_pd(&rtDW.B_m[rtDW.c_i - 1], _mm_sub_pd(tmp_0, _mm_mul_pd
            (tmp, _mm_set1_pd(rtDW.wj))));
        }

        for (rtDW.c_i = rtDW.scalarLB; rtDW.c_i <= rtDW.mn; rtDW.c_i++) {
          rtDW.B_m[rtDW.c_i - 1] = rtDW.B_m[rtDW.c_i - 1] - rtDW.V[(rtDW.V.size
            (0) * rtDW.b_j + rtDW.c_i) - 1] * rtDW.wj;
        }
      }
    }
  }

  for (rtDW.mn = 0; rtDW.mn < rtDW.assumedRank; rtDW.mn++) {
    p[rtDW.jpvt[rtDW.mn] - 1] = rtDW.B_m[rtDW.mn];
  }

  for (rtDW.mn = rtDW.assumedRank; rtDW.mn >= 1; rtDW.mn--) {
    rtDW.scalarLB = rtDW.jpvt[rtDW.mn - 1];
    p[rtDW.scalarLB - 1] /= rtDW.V[((rtDW.mn - 1) * rtDW.V.size(0) + rtDW.mn) -
      1];
    for (rtDW.b_j = 0; rtDW.b_j <= rtDW.mn - 2; rtDW.b_j++) {
      p[rtDW.jpvt[rtDW.b_j] - 1] -= rtDW.V[(rtDW.mn - 1) * rtDW.V.size(0) +
        rtDW.b_j] * p[rtDW.scalarLB - 1];
    }
  }
}

// Model step function
void LKAS_step(void)
{
  char_T *sErr;
  void *source_R;
  static const int16_T tmp[8] = { 519, 675, 113, 1049, 411, 411, 587, 587 };

  static const int16_T tmp_0[8] = { 450, 750, 450, 750, 0, 0, 750, 750 };

  boolean_T exitg1;
  boolean_T guard1;

  // S-Function (sdspwmmfi2): '<Root>/From Multimedia File'
  sErr = GetErrorBuffer(&rtDW.FromMultimediaFile_HostLib[0U]);
  source_R = (void *)&rtDW.FromMultimediaFile[0U];
  LibOutputs_FromMMFile(&rtDW.FromMultimediaFile_HostLib[0U], GetNullPointer(),
                        GetNullPointer(), source_R, GetNullPointer(),
                        GetNullPointer());
  if (*sErr != 0) {
    rtmSetErrorStatus(rtM, sErr);
    rtmSetStopRequested(rtM, 1);
  }

  // End of S-Function (sdspwmmfi2): '<Root>/From Multimedia File'

  // S-Function (svipscalenconvert): '<S2>/Image Data Type Conversion' incorporates:
  //   S-Function (sdspwmmfi2): '<Root>/From Multimedia File'

  for (rtDW.i = 0; rtDW.i < 2700000; rtDW.i++) {
    if (rtDW.FromMultimediaFile[rtDW.i] > 1.0F) {
      rtDW.ImageDataTypeConversion[rtDW.i] = 1.0;
    } else if (rtDW.FromMultimediaFile[rtDW.i] < 0.0F) {
      rtDW.ImageDataTypeConversion[rtDW.i] = 0.0;
    } else {
      rtDW.ImageDataTypeConversion[rtDW.i] = rtDW.FromMultimediaFile[rtDW.i];
    }
  }

  // End of S-Function (svipscalenconvert): '<S2>/Image Data Type Conversion'
  // temporary variables for in-place operation
  for (rtDW.i = 0; rtDW.i < 900000; rtDW.i++) {
    // S-Function (svipcolorconv): '<S2>/Color Space  Conversion' incorporates:
    //   S-Function (svipscalenconvert): '<S2>/Image Data Type Conversion'

    // First get the min and max of the RGB triplet
    rtDW.ImageDataTypeConversion_b = rtDW.ImageDataTypeConversion[rtDW.i];
    rtDW.ImageDataTypeConversion_p = rtDW.ImageDataTypeConversion[rtDW.i +
      900000];
    if (rtDW.ImageDataTypeConversion_b > rtDW.ImageDataTypeConversion_p) {
      rtDW.ImageDataTypeConversion_c = rtDW.ImageDataTypeConversion[rtDW.i +
        1800000];
      if (rtDW.ImageDataTypeConversion_p < rtDW.ImageDataTypeConversion_c) {
        rtDW.count_right = rtDW.ImageDataTypeConversion_p;
      } else {
        rtDW.count_right = rtDW.ImageDataTypeConversion_c;
      }

      if (rtDW.ImageDataTypeConversion_b > rtDW.ImageDataTypeConversion_c) {
        rtDW.bestInlierDis = rtDW.ImageDataTypeConversion_b;
      } else {
        rtDW.bestInlierDis = rtDW.ImageDataTypeConversion_c;
      }
    } else {
      rtDW.ImageDataTypeConversion_c = rtDW.ImageDataTypeConversion[rtDW.i +
        1800000];
      if (rtDW.ImageDataTypeConversion_b < rtDW.ImageDataTypeConversion_c) {
        rtDW.count_right = rtDW.ImageDataTypeConversion_b;
      } else {
        rtDW.count_right = rtDW.ImageDataTypeConversion_c;
      }

      if (rtDW.ImageDataTypeConversion_p > rtDW.ImageDataTypeConversion_c) {
        rtDW.bestInlierDis = rtDW.ImageDataTypeConversion_p;
      } else {
        rtDW.bestInlierDis = rtDW.ImageDataTypeConversion_c;
      }
    }

    rtDW.s1DivS2 = rtDW.bestInlierDis - rtDW.count_right;
    if (rtDW.bestInlierDis != 0.0) {
      rtDW.count_right = rtDW.s1DivS2 / rtDW.bestInlierDis;
    } else {
      rtDW.count_right = 0.0;
    }

    if (rtDW.s1DivS2 != 0.0) {
      if (rtDW.ImageDataTypeConversion_b == rtDW.bestInlierDis) {
        rtDW.s1DivS2 = (rtDW.ImageDataTypeConversion_p -
                        rtDW.ImageDataTypeConversion_c) / rtDW.s1DivS2;
      } else if (rtDW.ImageDataTypeConversion_p == rtDW.bestInlierDis) {
        rtDW.s1DivS2 = (rtDW.ImageDataTypeConversion_c -
                        rtDW.ImageDataTypeConversion_b) / rtDW.s1DivS2 + 2.0;
      } else {
        rtDW.s1DivS2 = (rtDW.ImageDataTypeConversion_b -
                        rtDW.ImageDataTypeConversion_p) / rtDW.s1DivS2 + 4.0;
      }

      rtDW.s1DivS2 /= 6.0;
      if (rtDW.s1DivS2 < 0.0) {
        rtDW.s1DivS2++;
      }
    } else {
      rtDW.s1DivS2 = 0.0;
    }

    // assign the results
    rtDW.ColorSpaceConversion[rtDW.i] = rtDW.s1DivS2;

    // S-Function (svipcolorconv): '<S2>/Color Space  Conversion'
    rtDW.ColorSpaceConversion[rtDW.i + 900000] = rtDW.count_right;

    // S-Function (svipcolorconv): '<S2>/Color Space  Conversion'
    rtDW.ColorSpaceConversion[rtDW.i + 1800000] = rtDW.bestInlierDis;

    // MATLAB Function: '<S2>/MATLAB Function4' incorporates:
    //   S-Function (svipcolorconv): '<S2>/Color Space  Conversion'

    rtDW.S_Channel[rtDW.i] = rtDW.count_right;
  }

  for (rtDW.nz_j = 0; rtDW.nz_j < 8; rtDW.nz_j++) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    rtDW.pts1[rtDW.nz_j] = tmp[rtDW.nz_j];

    // MATLAB Function: '<S2>/MATLAB Function2'
    rtDW.pts2[rtDW.nz_j] = tmp_0[rtDW.nz_j];
  }

  // S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'
  memset(&rtDW.EstimateGeometricTransformation[0], 0, 9U * sizeof(real_T));
  rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[0] = 0;
  rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[1] = 1;
  rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[2] = 2;
  rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[3] = 3;
  makeConstraintMatrix_Projective_D_D((const real_T *)&rtDW.pts1[0], (const
    real_T *)&rtDW.pts2[0], 4U, 4U,
    &rtDW.EstimateGeometricTransformation_DW_CONSTRT_ALL[0]);
  rtDW.i = 0;
  while (rtDW.i < 4) {
    rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[rtDW.i] = static_cast<
      uint32_T>(rtDW.EstimateGeometricTransformation_DW_BEST_SAMPLE[rtDW.i]);
    rtDW.i++;
  }

  rtDW.bestCol = 0U;
  normPts_D_D((const real_T *)&rtDW.pts1[0], (const uint32_T *)
              &rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
              &rtDW.EstimateGeometricTransformation_DW_PTSNORM1[0],
              &rtDW.rightx_current, &rtDW.cents1[0]);
  normPts_D_D((const real_T *)&rtDW.pts2[0], (const uint32_T *)
              &rtDW.EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
              &rtDW.EstimateGeometricTransformation_DW_PTSNORM2[0],
              &rtDW.leftx_current, &rtDW.cents2[0]);
  makeConstraintMatrix_Projective_D_D((const real_T *)
    &rtDW.EstimateGeometricTransformation_DW_PTSNORM1[0], (const real_T *)
    &rtDW.EstimateGeometricTransformation_DW_PTSNORM2[0], 4U, 4U,
    &rtDW.Constraint[0]);
  for (rtDW.i = 0; rtDW.i < 8; rtDW.i++) {
    rtDW.JPVT[static_cast<uint32_T>(rtDW.i)] = 0;
  }

  QRE_real_T_j(&rtDW.Q[0], &rtDW.Constraint[0], &rtDW.E[0], &rtDW.Qraux[0],
               &rtDW.Work[0], &rtDW.JPVT[0], &rtDW.RV[0], 9, 8, true);
  rtDW.count_right = 0.0;
  for (rtDW.i = 0; rtDW.i < 9; rtDW.i++) {
    for (rtDW.j = 0; rtDW.j < 9; rtDW.j++) {
      if (static_cast<uint32_T>(rtDW.i) != static_cast<uint32_T>(rtDW.j)) {
        rtDW.s1DivS2 = 0.0;
      } else {
        rtDW.s1DivS2 = -1.0;
      }

      for (rtDW.m = 0; rtDW.m < 8; rtDW.m++) {
        rtDW.s1DivS2_tmp = static_cast<uint32_T>(rtDW.m) * 9U;
        rtDW.s1DivS2 += rtDW.Q[rtDW.s1DivS2_tmp + static_cast<uint32_T>(rtDW.i)]
          * rtDW.Q[rtDW.s1DivS2_tmp + static_cast<uint32_T>(rtDW.j)];
      }

      rtDW.RV[static_cast<uint32_T>(rtDW.i) * 9U + static_cast<uint32_T>(rtDW.j)]
        = rtDW.s1DivS2;
      if (!(rtDW.s1DivS2 >= 0.0)) {
        rtDW.s1DivS2 = -rtDW.s1DivS2;
      }

      if (rtDW.count_right < rtDW.s1DivS2) {
        rtDW.count_right = rtDW.s1DivS2;
        rtDW.bestCol = static_cast<uint32_T>(rtDW.i);
      }
    }
  }

  rtDW.j = static_cast<int32_T>(rtDW.bestCol * 9U);
  for (rtDW.i = 0; rtDW.i < 9; rtDW.i++) {
    rtDW.tformCompact[static_cast<uint32_T>(rtDW.i)] = rtDW.RV
      [static_cast<uint32_T>(rtDW.j) + static_cast<uint32_T>(rtDW.i)];
  }

  rtDW.count_right = 1.0 / rtDW.leftx_current;
  rtDW.s1DivS2 = rtDW.rightx_current * rtDW.count_right;
  rtDW.tformCompact_k[6] = rtDW.tformCompact[6] * rtDW.rightx_current;
  rtDW.tformCompact_k[7] = rtDW.tformCompact[7] * rtDW.rightx_current;
  rtDW.tformCompact_k[8] = (rtDW.tformCompact[8] - rtDW.cents1[0] *
    rtDW.tformCompact_k[6]) - rtDW.cents1[1] * rtDW.tformCompact_k[7];
  rtDW.tformCompact_k[0] = rtDW.tformCompact[0] * rtDW.s1DivS2;
  rtDW.tformCompact_k[1] = rtDW.tformCompact[1] * rtDW.s1DivS2;
  rtDW.tformCompact_k[2] = ((rtDW.cents2[0] * rtDW.tformCompact_k[8] -
    rtDW.tformCompact_k[0] * rtDW.cents1[0]) - rtDW.tformCompact_k[1] *
    rtDW.cents1[1]) + rtDW.tformCompact[2] * rtDW.count_right;
  rtDW.tformCompact_k[3] = rtDW.tformCompact[3] * rtDW.s1DivS2;
  rtDW.tformCompact_k[4] = rtDW.tformCompact[4] * rtDW.s1DivS2;
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
      rtDW.tformCompact_k[static_cast<uint32_T>(rtDW.i)] *= rtDW.count_right;
    }

    rtDW.tformCompact_k[8] = 1.0;
    rtDW.bestCol = 0U;
    for (rtDW.i = 0; rtDW.i < 4; rtDW.i++) {
      rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_T>
        (rtDW.i)] = 0.0;
      for (rtDW.j = 0; rtDW.j < 2; rtDW.j++) {
        rtDW.count_right = 0.0;
        for (rtDW.m = 0; rtDW.m < 9; rtDW.m++) {
          rtDW.count_right +=
            rtDW.EstimateGeometricTransformation_DW_CONSTRT_ALL[rtDW.bestCol +
            static_cast<uint32_T>(rtDW.m)] * rtDW.tformCompact_k
            [static_cast<uint32_T>(rtDW.m)];
        }

        rtDW.bestCol += 9U;
        rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_T>
          (rtDW.i)] += rtDW.count_right * rtDW.count_right;
      }
    }

    memcpy(&rtDW.bestTFormCompact[0], &rtDW.tformCompact_k[0], 9U * sizeof
           (real_T));
    rtDW.i = 0;
    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[0] <=
        rtP.EstimateGeometricTransformation_distanceAlg) {
      rtDW.i = 1;
    }

    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[1] <=
        rtP.EstimateGeometricTransformation_distanceAlg) {
      rtDW.i = static_cast<int32_T>(static_cast<uint32_T>(rtDW.i) + 1U);
    }

    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[2] <=
        rtP.EstimateGeometricTransformation_distanceAlg) {
      rtDW.i = static_cast<int32_T>(static_cast<uint32_T>(rtDW.i) + 1U);
    }

    if (rtDW.EstimateGeometricTransformation_DW_DISTANCE[3] <=
        rtP.EstimateGeometricTransformation_distanceAlg) {
      rtDW.i = static_cast<int32_T>(static_cast<uint32_T>(rtDW.i) + 1U);
    }
  } else {
    rtDW.i = 0;
  }

  if (static_cast<uint32_T>(rtDW.i) >= 4U) {
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

  // MATLAB Function: '<S2>/MATLAB Function6'
  for (rtDW.nz_j = 0; rtDW.nz_j < 900000; rtDW.nz_j++) {
    rtDW.rtb_S_Channel_o[rtDW.nz_j] = (rtDW.S_Channel[rtDW.nz_j] > 0.75);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function6'

  // MATLABSystem: '<S2>/Warp' incorporates:
  //   S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'

  Warp_stepImpl(&rtDW.obj, rtDW.rtb_S_Channel_o,
                rtDW.EstimateGeometricTransformation, rtDW.bv);

  // MATLAB Function: '<S2>/MATLAB Function3' incorporates:
  //   MATLABSystem: '<S2>/Warp'

  for (rtDW.i = 0; rtDW.i < 1200; rtDW.i++) {
    rtDW.xpageoffset = rtDW.i * 376;
    rtDW.nz_j = rtDW.bv[(rtDW.xpageoffset / 376 * 750 + rtDW.xpageoffset % 376)
      + 374];
    for (rtDW.j = 0; rtDW.j < 375; rtDW.j++) {
      rtDW.m = (rtDW.xpageoffset + rtDW.j) + 1;
      rtDW.nz_j += rtDW.bv[(rtDW.m / 376 * 750 + rtDW.m % 376) + 374];
    }

    rtDW.nz[rtDW.i] = rtDW.nz_j;
  }

  findpeaks(rtDW.nz, rtDW.a__1, rtDW.locs);
  rtDW.end = rtDW.locs.size(1) - 1;
  rtDW.trueCount = 0;
  for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
    // MATLAB Function: '<S2>/MATLAB Function3'
    if (rtDW.locs[rtDW.i] - rtDW.locs[0] > 200.0) {
      rtDW.trueCount++;
    }
  }

  // MATLAB Function: '<S2>/MATLAB Function3'
  rtDW.r10.set_size(1, rtDW.trueCount);
  rtDW.trueCount = 0;
  for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
    // MATLAB Function: '<S2>/MATLAB Function3'
    if (rtDW.locs[rtDW.i] - rtDW.locs[0] > 200.0) {
      rtDW.r10[rtDW.trueCount] = rtDW.i;
      rtDW.trueCount++;
    }
  }

  // MATLAB Function: '<S2>/MATLAB Function3' incorporates:
  //   Gain: '<S37>/Filter Coefficient'
  //   S-Function (svipesttform): '<S2>/Estimate Geometric Transformation'

  rtDW.rightx_current = rtDW.locs[rtDW.r10[rtDW.r10.size(1) - 1]];
  rtDW.leftx_current = rtDW.locs[0];
  memset(&rtDW.left_lane_index_l[0], 0, 200000U * sizeof(int32_T));
  memset(&rtDW.right_lane_index[0], 0, 200000U * sizeof(int32_T));
  rtDW.i = -1;
  rtDW.d_i.set_size(900000);
  rtDW.e_j.set_size(900000);
  rtDW.j = 1;
  rtDW.xpageoffset = 1;
  exitg1 = false;
  while ((!exitg1) && (rtDW.xpageoffset <= 1200)) {
    guard1 = false;
    if (rtDW.bv[((rtDW.xpageoffset - 1) * 750 + rtDW.j) - 1]) {
      rtDW.i++;
      rtDW.d_i[rtDW.i] = rtDW.j;
      rtDW.e_j[rtDW.i] = static_cast<int16_T>(rtDW.xpageoffset);
      if (rtDW.i + 1 >= 900000) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      rtDW.j++;
      if (rtDW.j > 750) {
        rtDW.j = 1;
        rtDW.xpageoffset++;
      }
    }
  }

  if (rtDW.i + 1 < 1) {
    rtDW.j = -1;
    rtDW.xpageoffset = -1;
  } else {
    rtDW.j = rtDW.i;
    rtDW.xpageoffset = rtDW.i;
  }

  rtDW.bestInlierDis = 0.0;
  rtDW.count_right = 0.0;
  for (rtDW.i = 0; rtDW.i < 10; rtDW.i++) {
    rtDW.m = 750 - (rtDW.i + 1) * 75;
    rtDW.win_y_high = 750 - rtDW.i * 75;
    rtDW.s_tmp.set_size(rtDW.xpageoffset + 1);
    for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.xpageoffset; rtDW.nz_j++) {
      rtDW.s_tmp[rtDW.nz_j] = rtDW.e_j[rtDW.nz_j];
    }

    rtDW.b_tmp_tmp.set_size(rtDW.j + 1);
    for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.j; rtDW.nz_j++) {
      rtDW.end = rtDW.d_i[rtDW.nz_j];
      rtDW.b_tmp_tmp[rtDW.nz_j] = ((rtDW.end >= rtDW.m) && (rtDW.end <
        rtDW.win_y_high));
    }

    if (rtDW.b_tmp_tmp.size(0) == rtDW.s_tmp.size(0)) {
      rtDW.b_tmp.set_size(rtDW.b_tmp_tmp.size(0));
      rtDW.m = rtDW.b_tmp_tmp.size(0);
      for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
        rtDW.b_tmp[rtDW.nz_j] = (rtDW.b_tmp_tmp[rtDW.nz_j] &&
          (rtDW.s_tmp[rtDW.nz_j] >= rtDW.leftx_current - 80.0));
      }
    } else {
      binary_expand_op_1(rtDW.b_tmp, rtDW.b_tmp_tmp, rtDW.s_tmp,
                         rtDW.leftx_current);
    }

    rtDW.t.set_size(rtDW.s_tmp.size(0));
    rtDW.m = rtDW.s_tmp.size(0);
    for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
      rtDW.t[rtDW.nz_j] = (rtDW.s_tmp[rtDW.nz_j] < rtDW.leftx_current + 80.0);
    }

    if (rtDW.b_tmp_tmp.size(0) == rtDW.s_tmp.size(0)) {
      rtDW.m = rtDW.b_tmp_tmp.size(0);
      for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
        rtDW.b_tmp_tmp[rtDW.nz_j] = (rtDW.b_tmp_tmp[rtDW.nz_j] &&
          (rtDW.s_tmp[rtDW.nz_j] >= rtDW.rightx_current - 80.0));
      }
    } else {
      binary_expand_op(rtDW.b_tmp_tmp, rtDW.s_tmp, rtDW.rightx_current);
    }

    rtDW.v.set_size(rtDW.s_tmp.size(0));
    rtDW.m = rtDW.s_tmp.size(0);
    for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
      rtDW.v[rtDW.nz_j] = (rtDW.s_tmp[rtDW.nz_j] < rtDW.rightx_current + 80.0);
    }

    rtDW.ImageDataTypeConversion_b = rtDW.bestInlierDis + 1.0;
    if (rtDW.b_tmp.size(0) == rtDW.t.size(0)) {
      rtDW.r.set_size(rtDW.b_tmp.size(0));
      rtDW.m = rtDW.b_tmp.size(0);
      for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
        rtDW.r[rtDW.nz_j] = (rtDW.b_tmp[rtDW.nz_j] && rtDW.t[rtDW.nz_j]);
      }
    } else {
      and_j(rtDW.r, rtDW.b_tmp, rtDW.t);
    }

    rtDW.end = rtDW.r.size(0) - 1;
    rtDW.trueCount = 0;
    for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
      if (rtDW.r[rtDW.nz_j]) {
        rtDW.trueCount++;
      }
    }

    rtDW.win_y_high = static_cast<int32_T>((1.0 - (rtDW.bestInlierDis + 1.0)) +
      static_cast<real_T>(rtDW.trueCount));
    for (rtDW.m = 0; rtDW.m < rtDW.win_y_high; rtDW.m++) {
      rtDW.s1DivS2 = rtDW.ImageDataTypeConversion_b + static_cast<real_T>(rtDW.m);
      rtDW.end = rtDW.b_tmp.size(0);
      if (rtDW.b_tmp.size(0) == rtDW.t.size(0)) {
        rtDW.r2.set_size(rtDW.b_tmp.size(0));
        for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.end; rtDW.nz_j++) {
          rtDW.r2[rtDW.nz_j] = (rtDW.b_tmp[rtDW.nz_j] && rtDW.t[rtDW.nz_j]);
        }
      } else {
        and_j(rtDW.r2, rtDW.b_tmp, rtDW.t);
      }

      rtDW.end = rtDW.b_tmp.size(0);
      if (rtDW.b_tmp.size(0) == rtDW.t.size(0)) {
        rtDW.r3.set_size(rtDW.b_tmp.size(0));
        for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.end; rtDW.nz_j++) {
          rtDW.r3[rtDW.nz_j] = (rtDW.b_tmp[rtDW.nz_j] && rtDW.t[rtDW.nz_j]);
        }
      } else {
        and_j(rtDW.r3, rtDW.b_tmp, rtDW.t);
      }

      rtDW.end = rtDW.r2.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r2[rtDW.nz_j]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r11.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r2[rtDW.nz_j]) {
          rtDW.r11[rtDW.trueCount] = rtDW.nz_j;
          rtDW.trueCount++;
        }
      }

      rtDW.end = rtDW.r3.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r3[rtDW.nz_j]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r12.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r3[rtDW.nz_j]) {
          rtDW.r12[rtDW.trueCount] = rtDW.nz_j;
          rtDW.trueCount++;
        }
      }

      rtDW.left_lane_index_l[static_cast<int32_T>(rtDW.s1DivS2) - 1] =
        rtDW.e_j[rtDW.r11[static_cast<int32_T>(rtDW.s1DivS2) - 1]];
      rtDW.left_lane_index_l[static_cast<int32_T>(rtDW.s1DivS2) + 99999] =
        rtDW.d_i[rtDW.r12[static_cast<int32_T>(rtDW.s1DivS2) - 1]];
      rtDW.bestInlierDis++;
    }

    rtDW.ImageDataTypeConversion_b = rtDW.count_right + 1.0;
    if (rtDW.b_tmp_tmp.size(0) == rtDW.v.size(0)) {
      rtDW.r1.set_size(rtDW.b_tmp_tmp.size(0));
      rtDW.m = rtDW.b_tmp_tmp.size(0);
      for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
        rtDW.r1[rtDW.nz_j] = (rtDW.b_tmp_tmp[rtDW.nz_j] && rtDW.v[rtDW.nz_j]);
      }
    } else {
      and_j(rtDW.r1, rtDW.b_tmp_tmp, rtDW.v);
    }

    rtDW.end = rtDW.r1.size(0) - 1;
    rtDW.trueCount = 0;
    for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
      if (rtDW.r1[rtDW.nz_j]) {
        rtDW.trueCount++;
      }
    }

    rtDW.win_y_high = static_cast<int32_T>((1.0 - (rtDW.count_right + 1.0)) +
      static_cast<real_T>(rtDW.trueCount));
    for (rtDW.m = 0; rtDW.m < rtDW.win_y_high; rtDW.m++) {
      rtDW.s1DivS2 = rtDW.ImageDataTypeConversion_b + static_cast<real_T>(rtDW.m);
      rtDW.end = rtDW.b_tmp_tmp.size(0);
      if (rtDW.b_tmp_tmp.size(0) == rtDW.v.size(0)) {
        rtDW.r6.set_size(rtDW.b_tmp_tmp.size(0));
        for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.end; rtDW.nz_j++) {
          rtDW.r6[rtDW.nz_j] = (rtDW.b_tmp_tmp[rtDW.nz_j] && rtDW.v[rtDW.nz_j]);
        }
      } else {
        and_j(rtDW.r6, rtDW.b_tmp_tmp, rtDW.v);
      }

      rtDW.end = rtDW.b_tmp_tmp.size(0);
      if (rtDW.b_tmp_tmp.size(0) == rtDW.v.size(0)) {
        rtDW.r8.set_size(rtDW.b_tmp_tmp.size(0));
        for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.end; rtDW.nz_j++) {
          rtDW.r8[rtDW.nz_j] = (rtDW.b_tmp_tmp[rtDW.nz_j] && rtDW.v[rtDW.nz_j]);
        }
      } else {
        and_j(rtDW.r8, rtDW.b_tmp_tmp, rtDW.v);
      }

      rtDW.end = rtDW.r6.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r6[rtDW.nz_j]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r14.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r6[rtDW.nz_j]) {
          rtDW.r14[rtDW.trueCount] = rtDW.nz_j;
          rtDW.trueCount++;
        }
      }

      rtDW.end = rtDW.r8.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r8[rtDW.nz_j]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r15.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r8[rtDW.nz_j]) {
          rtDW.r15[rtDW.trueCount] = rtDW.nz_j;
          rtDW.trueCount++;
        }
      }

      rtDW.right_lane_index[static_cast<int32_T>(rtDW.s1DivS2) - 1] =
        rtDW.e_j[rtDW.r14[static_cast<int32_T>(rtDW.s1DivS2) - 1]];
      rtDW.right_lane_index[static_cast<int32_T>(rtDW.s1DivS2) + 99999] =
        rtDW.d_i[rtDW.r15[static_cast<int32_T>(rtDW.s1DivS2) - 1]];
      rtDW.count_right++;
    }

    if (rtDW.b_tmp.size(0) == rtDW.t.size(0)) {
      rtDW.r4.set_size(rtDW.b_tmp.size(0));
      rtDW.m = rtDW.b_tmp.size(0);
      for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
        rtDW.r4[rtDW.nz_j] = (rtDW.b_tmp[rtDW.nz_j] && rtDW.t[rtDW.nz_j]);
      }
    } else {
      and_j(rtDW.r4, rtDW.b_tmp, rtDW.t);
    }

    rtDW.end = rtDW.r4.size(0) - 1;
    rtDW.trueCount = 0;
    for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
      if (rtDW.r4[rtDW.nz_j]) {
        rtDW.trueCount++;
      }
    }

    if (rtDW.trueCount > 40) {
      if (rtDW.b_tmp.size(0) == rtDW.t.size(0)) {
        rtDW.r5.set_size(rtDW.b_tmp.size(0));
        rtDW.m = rtDW.b_tmp.size(0);
        for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
          rtDW.r5[rtDW.nz_j] = (rtDW.b_tmp[rtDW.nz_j] && rtDW.t[rtDW.nz_j]);
        }
      } else {
        and_j(rtDW.r5, rtDW.b_tmp, rtDW.t);
      }

      rtDW.end = rtDW.r5.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r5[rtDW.nz_j]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r13.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r5[rtDW.nz_j]) {
          rtDW.r13[rtDW.trueCount] = rtDW.nz_j;
          rtDW.trueCount++;
        }
      }

      rtDW.m = rtDW.r13.size(0);
      rtDW.s_tmp.set_size(rtDW.r13.size(0));
      for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
        rtDW.s_tmp[rtDW.nz_j] = rtDW.e_j[rtDW.r13[rtDW.nz_j]];
      }

      rtDW.leftx_current = mean(rtDW.s_tmp);
    }

    if (rtDW.b_tmp_tmp.size(0) == rtDW.v.size(0)) {
      rtDW.r7.set_size(rtDW.b_tmp_tmp.size(0));
      rtDW.m = rtDW.b_tmp_tmp.size(0);
      for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
        rtDW.r7[rtDW.nz_j] = (rtDW.b_tmp_tmp[rtDW.nz_j] && rtDW.v[rtDW.nz_j]);
      }
    } else {
      and_j(rtDW.r7, rtDW.b_tmp_tmp, rtDW.v);
    }

    rtDW.end = rtDW.r7.size(0) - 1;
    rtDW.trueCount = 0;
    for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
      if (rtDW.r7[rtDW.nz_j]) {
        rtDW.trueCount++;
      }
    }

    if (rtDW.trueCount > 40) {
      if (rtDW.b_tmp_tmp.size(0) == rtDW.v.size(0)) {
        rtDW.r9.set_size(rtDW.b_tmp_tmp.size(0));
        rtDW.m = rtDW.b_tmp_tmp.size(0);
        for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
          rtDW.r9[rtDW.nz_j] = (rtDW.b_tmp_tmp[rtDW.nz_j] && rtDW.v[rtDW.nz_j]);
        }
      } else {
        and_j(rtDW.r9, rtDW.b_tmp_tmp, rtDW.v);
      }

      rtDW.end = rtDW.r9.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r9[rtDW.nz_j]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r16.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.end; rtDW.nz_j++) {
        if (rtDW.r9[rtDW.nz_j]) {
          rtDW.r16[rtDW.trueCount] = rtDW.nz_j;
          rtDW.trueCount++;
        }
      }

      rtDW.m = rtDW.r16.size(0);
      rtDW.s_tmp.set_size(rtDW.r16.size(0));
      for (rtDW.nz_j = 0; rtDW.nz_j < rtDW.m; rtDW.nz_j++) {
        rtDW.s_tmp[rtDW.nz_j] = rtDW.e_j[rtDW.r16[rtDW.nz_j]];
      }

      rtDW.rightx_current = mean(rtDW.s_tmp);
    }
  }

  if (rtDW.bestInlierDis < 1.0) {
    rtDW.j = 0;
  } else {
    rtDW.j = static_cast<int32_T>(rtDW.bestInlierDis);
  }

  if (rtDW.count_right < 1.0) {
    rtDW.m = 0;
  } else {
    rtDW.m = static_cast<int32_T>(rtDW.count_right);
  }

  rtDW.i = rtDW.j - 1;
  rtDW.s_tmp.set_size(rtDW.j);
  rtDW.left_lane_index.set_size(rtDW.j);
  for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.i; rtDW.nz_j++) {
    rtDW.s_tmp[rtDW.nz_j] = rtDW.left_lane_index_l[rtDW.nz_j + 100000];
    rtDW.left_lane_index[rtDW.nz_j] = rtDW.left_lane_index_l[rtDW.nz_j];
  }

  polyfit(rtDW.s_tmp, rtDW.left_lane_index, rtDW.p);
  rtDW.i = rtDW.m - 1;
  rtDW.s_tmp.set_size(rtDW.m);
  rtDW.left_lane_index.set_size(rtDW.m);
  for (rtDW.nz_j = 0; rtDW.nz_j <= rtDW.i; rtDW.nz_j++) {
    rtDW.s_tmp[rtDW.nz_j] = rtDW.right_lane_index[rtDW.nz_j + 100000];
    rtDW.left_lane_index[rtDW.nz_j] = rtDW.right_lane_index[rtDW.nz_j];
  }

  polyfit(rtDW.s_tmp, rtDW.left_lane_index, rtDW.b_p);
  for (rtDW.nz_j = 0; rtDW.nz_j < 751; rtDW.nz_j++) {
    rtDW.xleft[rtDW.nz_j] = rtDW.p[0];
  }

  for (rtDW.i = 0; rtDW.i < 2; rtDW.i++) {
    rtDW.count_right = rtDW.p[rtDW.i + 1];
    for (rtDW.nz_j = 0; rtDW.nz_j < 751; rtDW.nz_j++) {
      rtDW.xleft[rtDW.nz_j] = static_cast<real_T>(rtDW.nz_j) *
        rtDW.xleft[rtDW.nz_j] + rtDW.count_right;
    }
  }

  for (rtDW.nz_j = 0; rtDW.nz_j < 751; rtDW.nz_j++) {
    rtDW.xright[rtDW.nz_j] = rtDW.b_p[0];
  }

  for (rtDW.i = 0; rtDW.i < 2; rtDW.i++) {
    rtDW.count_right = rtDW.b_p[rtDW.i + 1];
    for (rtDW.nz_j = 0; rtDW.nz_j < 751; rtDW.nz_j++) {
      rtDW.xright[rtDW.nz_j] = static_cast<real_T>(rtDW.nz_j) *
        rtDW.xright[rtDW.nz_j] + rtDW.count_right;
    }
  }

  rtDW.rightx_current = 600.0 - (rtDW.xleft[750] + rtDW.xright[750]) / 2.0;

  // Gain: '<S37>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S29>/Filter'
  //   Gain: '<S28>/Derivative Gain'
  //   Sum: '<S29>/SumD'

  rtDW.leftx_current = (rtP.PIDController_D * rtDW.rightx_current -
                        rtDW.Filter_DSTATE) * rtP.PIDController_N;

  // Sum: '<S43>/Sum' incorporates:
  //   DiscreteIntegrator: '<S34>/Integrator'
  //   Gain: '<S39>/Proportional Gain'

  rtDW.bestInlierDis = (rtP.PIDController_P * rtDW.rightx_current +
                        rtDW.Integrator_DSTATE) + rtDW.leftx_current;

  // Saturate: '<S41>/Saturation'
  if (rtDW.bestInlierDis > rtP.PIDController_UpperSaturationLimit) {
    rtDW.count_right = rtP.PIDController_UpperSaturationLimit;
  } else if (rtDW.bestInlierDis < rtP.PIDController_LowerSaturationLimit) {
    rtDW.count_right = rtP.PIDController_LowerSaturationLimit;
  } else {
    rtDW.count_right = rtDW.bestInlierDis;
  }

  // End of Saturate: '<S41>/Saturation'

  // Outport: '<Root>/Out1'
  rtY.Out1 = rtDW.count_right;

  // Update for DiscreteIntegrator: '<S34>/Integrator' incorporates:
  //   Gain: '<S27>/Kb'
  //   Gain: '<S31>/Integral Gain'
  //   Sum: '<S27>/SumI2'
  //   Sum: '<S27>/SumI4'

  rtDW.Integrator_DSTATE += ((rtDW.count_right - rtDW.bestInlierDis) *
    rtP.PIDController_Kb + rtP.PIDController_I * rtDW.rightx_current) *
    rtP.Integrator_gainval;

  // Update for DiscreteIntegrator: '<S29>/Filter'
  rtDW.Filter_DSTATE += rtP.Filter_gainval * rtDW.leftx_current;
}

// Model initialize function
void LKAS_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    char_T *sErr;
    static const int8_T self_T[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

    // Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File'
    sErr = GetErrorBuffer(&rtDW.FromMultimediaFile_HostLib[0U]);
    CreateHostLibrary("libmwfrommmfile.so", &rtDW.FromMultimediaFile_HostLib[0U]);
    createAudioInfo(&rtDW.FromMultimediaFile_AudioInfo[0U], 0U, 0U, 0.0, 0, 0, 0,
                    0, GetNullPointer());
    createVideoInfo(&rtDW.FromMultimediaFile_VideoInfo[0U], 1U, 5.0, 5.0, "RGB ",
                    1, 3, 1200, 750, 1U, 1, 1, GetNullPointer());
    if (*sErr == 0) {
      LibCreate_FromMMFile(&rtDW.FromMultimediaFile_HostLib[0U], NULL,
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
        rtmSetErrorStatus(rtM, sErr);
        rtmSetStopRequested(rtM, 1);
      }
    }

    // End of Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File'

    // Start for S-Function (svipesttform): '<S2>/Estimate Geometric Transformation' 
    srand(clock());

    // InitializeConditions for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' 
    LibReset(&rtDW.FromMultimediaFile_HostLib[0U]);

    // InitializeConditions for DiscreteIntegrator: '<S34>/Integrator'
    rtDW.Integrator_DSTATE = rtP.PIDController_InitialConditionForIntegrator;

    // InitializeConditions for DiscreteIntegrator: '<S29>/Filter'
    rtDW.Filter_DSTATE = rtP.PIDController_InitialConditionForFilter;

    // Start for MATLABSystem: '<S2>/Warp'
    rtDW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      rtDW.obj.TformProjective.T[i] = self_T[i];
    }

    // End of Start for MATLABSystem: '<S2>/Warp'
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
