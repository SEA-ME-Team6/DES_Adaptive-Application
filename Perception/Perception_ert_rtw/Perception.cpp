//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Perception.cpp
//
// Code generated for Simulink model 'Perception'.
//
// Model version                  : 1.6
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Mar  1 10:44:42 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "Perception.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <string.h>
#include <stddef.h>
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
extern real_T rt_hypotd_snf(real_T u0, real_T u1);

// Forward declaration for local functions
static void QRV2Norm_real_T_k(const real_T V[], int32_T N, real_T v2norm[]);
static void QRDC_real_T_k(real_T xVec[], real_T qrAux[], int32_T jpvt[], real_T
  work[], int32_T M, int32_T N);
static void QRE_real_T_k(real_T outQ[], real_T outR[], real_T outE[], real_T
  qrAux[], real_T work[], int32_T jpvt[], real_T sPtr[], int32_T M, int32_T N,
  boolean_T economy);
static void Warp_stepImpl(vision_internal_blocks_Warp *b_this, const boolean_T
  Image[900000], const real_T input2[9], boolean_T Jout[900000]);
static void do_vectors(const int32_T a_data[], const int32_T a_size[1], const
  int32_T b_data[], const int32_T b_size[1], int32_T c_data[], int32_T c_size[1],
  int32_T ia_data[], int32_T ia_size[1], int32_T ib_data[], int32_T ib_size[1]);
static void findpeaks(const real_T Yin[1200], real_T Ypk_data[], int32_T
                      Ypk_size[2], real_T Xpk_data[], int32_T Xpk_size[2]);
static void eml_find(const boolean_T x[900000], coder::array<int32_T, 1U> &i,
                     coder::array<int32_T, 1U> &j);
static void binary_expand_op_1(coder::array<boolean_T, 1U> &in1, const coder::
  array<boolean_T, 1U> &in2, const coder::array<real_T, 1U> &in3, real_T in4);
static void binary_expand_op(coder::array<boolean_T, 1U> &in1, const coder::
  array<real_T, 1U> &in2, real_T in3);
static void and_k(coder::array<boolean_T, 1U> &in1, const coder::array<boolean_T,
                  1U> &in2, const coder::array<boolean_T, 1U> &in3);
static real_T mean(const coder::array<real_T, 1U> &x);
static real_T xnrm2(int32_T n, const coder::array<real_T, 2U> &x, int32_T ix0);
static void xswap(int32_T n, coder::array<real_T, 2U> &x, int32_T ix0, int32_T
                  iy0);
static void xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, coder::array<
                   real_T, 2U> &C, int32_T ic0, int32_T ldc, real_T work[3]);
static void qrpf(coder::array<real_T, 2U> &A, int32_T m, real_T tau_data[],
                 int32_T jpvt[3]);
static void xgeqp3(coder::array<real_T, 2U> &A, real_T tau_data[], int32_T
                   tau_size[1], int32_T jpvt[3]);
static void qrsolve(const coder::array<real_T, 2U> &A, const coder::array<real_T,
                    1U> &B_0, real_T Y[3], int32_T *rankA);
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

  // S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
}

void normPts_D_D(const real_T pts[], const uint32_T samples[], uint32_T ptsNum,
                 uint32_T sampleNum, real_T ptsNorm[], real_T scale[], real_T
                 cents[])
{
  real_T sumDis;

  // S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
}

static void QRV2Norm_real_T_k(const real_T V[], int32_T N, real_T v2norm[])
{
  int32_T vi;

  // S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
}

static void QRDC_real_T_k(real_T xVec[], real_T qrAux[], int32_T jpvt[], real_T
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

  // S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
  pl = 0;
  rtDW.j_b = 0;
  while (rtDW.j_b < N) {
    pu = (jpvt[rtDW.j_b] > 0);
    if (jpvt[rtDW.j_b] < 0) {
      jpvt[rtDW.j_b] = -rtDW.j_b;
    } else {
      jpvt[rtDW.j_b] = rtDW.j_b;
    }

    if (pu == 1) {
      if (rtDW.j_b != pl) {
        // Swap columns pl and j
        px = pl * M;
        px2 = rtDW.j_b * M;
        for (i = M; i > 0; i--) {
          rtDW.maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = rtDW.maxnrm;
          px++;
          px2++;
        }
      }

      jpvt[rtDW.j_b] = jpvt[pl];
      jpvt[pl] = rtDW.j_b;
      pl++;
    }

    rtDW.j_b++;
  }

  pu = N - 1;
  rtDW.j_b = N - 1;
  while (rtDW.j_b >= 0) {
    if (jpvt[rtDW.j_b] < 0) {
      jpvt[rtDW.j_b] = -jpvt[rtDW.j_b];
      if (rtDW.j_b != pu) {
        // Swap columns pu and j
        px = pu * M;
        px2 = rtDW.j_b * M;
        for (i = M; i > 0; i--) {
          rtDW.maxnrm = xVec[px];
          xVec[px] = xVec[px2];
          xVec[px2] = rtDW.maxnrm;
          px++;
          px2++;
        }

        px = jpvt[pu];
        jpvt[pu] = jpvt[rtDW.j_b];
        jpvt[rtDW.j_b] = px;
      }

      pu--;
    }

    rtDW.j_b--;
  }

  // compute the norms of the free columns
  rtDW.j_b = pl;
  while (rtDW.j_b <= pu) {
    QRV2Norm_real_T_k(&xVec[rtDW.j_b * M], M, &qrAux[rtDW.j_b]);
    work[rtDW.j_b] = qrAux[rtDW.j_b];
    rtDW.j_b++;
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
      rtDW.j_b = l;
      while (rtDW.j_b <= pu) {
        if (qrAux[rtDW.j_b] > rtDW.maxnrm) {
          rtDW.maxnrm = qrAux[rtDW.j_b];
          maxj = rtDW.j_b;
        }

        rtDW.j_b++;
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
      QRV2Norm_real_T_k(&xVec[maxj], mml, &rtDW.nrmxl);
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
        rtDW.j_b = l + 1;
        while (rtDW.j_b < N) {
          plj = rtDW.j_b * M + l;
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
          if (qrAux[rtDW.j_b] == 0.0) {
            px2 = 1;
          }

          if ((rtDW.j_b >= pl) && (rtDW.j_b <= pu) && (px2 == 0)) {
            rtDW.maxnrm = fabs(xVec[plj]) / qrAux[rtDW.j_b];
            rtDW.tt = 1.0 - rtDW.maxnrm * rtDW.maxnrm;
            if (rtDW.tt < 0.0) {
              rtDW.tt = 0.0;
            }

            rtDW.t = rtDW.tt;
            rtDW.maxnrm = qrAux[rtDW.j_b] / work[rtDW.j_b];
            rtDW.tt = 0.05 * rtDW.tt * rtDW.maxnrm * rtDW.maxnrm + 1.0;
            if (rtDW.tt != 1.0) {
              qrAux[rtDW.j_b] *= sqrt(rtDW.t);
            } else {
              QRV2Norm_real_T_k(&xVec[plj + 1], mml - 1, &rtDW.maxnrm);
              qrAux[rtDW.j_b] = rtDW.maxnrm;
              work[rtDW.j_b] = qrAux[rtDW.j_b];
            }
          }

          rtDW.j_b++;
        }

        // save the transformation.
        qrAux[l] = xVec[px];
        xVec[px] = -rtDW.nrmxl;
      }
    }
  }

  // End of S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
}

void QRCompQy_real_T(real_T qr[], const real_T qrAuxj[], real_T y[], int32_T n,
                     int32_T j)
{
  // S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
}

void QRSL1_real_T(real_T qr[], const real_T qrAux[], real_T y[], int32_T n,
                  int32_T k)
{
  int32_T j;
  int32_T pqraux;
  int32_T y_0;

  // S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
}

static void QRE_real_T_k(real_T outQ[], real_T outR[], real_T outE[], real_T
  qrAux[], real_T work[], int32_T jpvt[], real_T sPtr[], int32_T M, int32_T N,
  boolean_T economy)
{
  // S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
  QRDC_real_T_k(&outR[0], &qrAux[0], &jpvt[0], &work[0], M, N);

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
  rtDW.j_o = 0;
  while (rtDW.j_o < M * rtDW.L) {
    outQ[rtDW.j_o] = 0.0;
    rtDW.j_o++;
  }

  rtDW.j_o = 0;
  while (rtDW.j_o < rtDW.L) {
    outQ[rtDW.L_tmp] = 1.0;
    rtDW.L_tmp = (rtDW.L_tmp + M) + 1;
    rtDW.j_o++;
  }

  // Convert cols of identity into cols of q. Use info stored in lower triangle of r and in vector qraux to work on columns of identity matrix I and transform them into q*I(:,j) i.e. the columns of q. 
  rtDW.L_tmp = 0;
  rtDW.j_o = 0;
  while (rtDW.j_o < rtDW.L) {
    QRSL1_real_T(&outR[0], &qrAux[0], &outQ[rtDW.L_tmp], M, N);
    rtDW.L_tmp += M;
    rtDW.j_o++;
  }

  if (economy && (M > N)) {
    // Copy upper triangle of r to s
    rtDW.L = 0;
    rtDW.ps = 0;
    rtDW.j_o = 1;
    while (rtDW.j_o - 1 < N) {
      rtDW.L_tmp = 0;
      while (rtDW.L_tmp <= rtDW.j_o - 1) {
        sPtr[rtDW.ps] = outR[rtDW.L];
        rtDW.ps++;
        rtDW.L++;
        rtDW.L_tmp++;
      }

      rtDW.L = (rtDW.L + M) - rtDW.j_o;
      rtDW.L_tmp = 0;
      while (rtDW.L_tmp < N - rtDW.j_o) {
        sPtr[rtDW.ps] = 0.0;
        rtDW.ps++;
        rtDW.L_tmp++;
      }

      rtDW.j_o++;
    }
  } else {
    // Zero strict lower triangle of r
    rtDW.L = M * N - 1;
    rtDW.j_o = N;
    while (rtDW.j_o - 1 >= 0) {
      rtDW.L_tmp = M;
      while (rtDW.L_tmp > rtDW.j_o) {
        outR[rtDW.L] = 0.0;
        rtDW.L--;
        rtDW.L_tmp--;
      }

      if (M < rtDW.j_o) {
        rtDW.L -= M;
      } else {
        rtDW.L -= rtDW.j_o;
      }

      rtDW.j_o--;
    }
  }

  // form permutation vector e
  rtDW.L = 0;
  rtDW.L_tmp = 0;
  rtDW.j_o = 0;
  while (rtDW.j_o < N) {
    outE[rtDW.L] = jpvt[rtDW.L_tmp] + 1;
    rtDW.L_tmp = rtDW.L + 1;
    rtDW.L++;
    rtDW.j_o++;
  }

  // End of S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
}

static void Warp_stepImpl(vision_internal_blocks_Warp *b_this, const boolean_T
  Image[900000], const real_T input2[9], boolean_T Jout[900000])
{
  real_T tinv;
  real_T tinv_0;
  int32_T itmp;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  for (p2 = 0; p2 < 9; p2++) {
    // Start for MATLABSystem: '<S1>/Warp'
    rtDW.absx11 = input2[p2];
    b_this->TformProjective.T[p2] = rtDW.absx11;
    rtDW.x[p2] = rtDW.absx11;
  }

  p1 = 1;
  p2 = 3;
  p3 = 6;

  // Start for MATLABSystem: '<S1>/Warp'
  rtDW.absx11 = fabs(b_this->TformProjective.T[0]);
  rtDW.absx21 = fabs(b_this->TformProjective.T[1]);
  rtDW.absx31 = fabs(b_this->TformProjective.T[2]);
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

  // Start for MATLABSystem: '<S1>/Warp'
  rtDW.absx11 = rtDW.x[2] / rtDW.x[0];
  rtDW.x[2] = rtDW.absx11;
  rtDW.x[4] -= rtDW.absx31 * rtDW.x[3];
  rtDW.x[5] -= rtDW.absx11 * rtDW.x[3];
  rtDW.x[7] -= rtDW.absx31 * rtDW.x[6];
  rtDW.x[8] -= rtDW.absx11 * rtDW.x[6];

  // Start for MATLABSystem: '<S1>/Warp'
  if (fabs(rtDW.x[5]) > fabs(rtDW.x[4])) {
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

  // Start for MATLABSystem: '<S1>/Warp'
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
  rtDW.tinv_g = rtDW.tinv[8];

  // Start for MATLABSystem: '<S1>/Warp'
  rtDW.tinv_g1 = rtDW.tinv[0];
  rtDW.tinv_m = rtDW.tinv[1];
  rtDW.tinv_n = rtDW.tinv[2];
  rtDW.tinv_p = rtDW.tinv[3];
  tinv = rtDW.tinv[4];
  tinv_0 = rtDW.tinv[5];
  for (p1 = 0; p1 < 1200; p1++) {
    for (p2 = 0; p2 < 750; p2++) {
      // Start for MATLABSystem: '<S1>/Warp'
      rtDW.absx11 = ((((static_cast<real_T>(p1) + 1.0) - 0.5) + 0.5) *
                     rtDW.absx21 + (((static_cast<real_T>(p2) + 1.0) - 0.5) +
        0.5) * rtDW.absx31) + rtDW.tinv_g;
      itmp = 750 * p1 + p2;
      rtDW.srcXIntrinsic[itmp] = ((((((static_cast<real_T>(p1) + 1.0) - 0.5) +
        0.5) * rtDW.tinv_g1 + (((static_cast<real_T>(p2) + 1.0) - 0.5) + 0.5) *
        rtDW.tinv_m) + rtDW.tinv_n) / rtDW.absx11 - 0.5) + 0.5;
      rtDW.srcYIntrinsic[itmp] = ((((((static_cast<real_T>(p1) + 1.0) - 0.5) +
        0.5) * rtDW.tinv_p + (((static_cast<real_T>(p2) + 1.0) - 0.5) + 0.5) *
        tinv) + tinv_0) / rtDW.absx11 - 0.5) + 0.5;
    }
  }

  for (p2 = 0; p2 < 900000; p2++) {
    // Start for MATLABSystem: '<S1>/Warp'
    rtDW.inputImage[p2] = static_cast<int8_T>(Image[p2]);
  }

  for (p1 = 0; p1 < 900000; p1++) {
    real32_T qx2;

    // Start for MATLABSystem: '<S1>/Warp'
    rtDW.absx11 = rtDW.srcXIntrinsic[p1];
    if ((rtDW.absx11 >= 1.0) && (rtDW.absx11 <= 1200.0)) {
      rtDW.absx21 = rtDW.srcYIntrinsic[p1];
      if ((rtDW.absx21 >= 1.0) && (rtDW.absx21 <= 750.0)) {
        real32_T qx1;
        if (rtDW.absx11 <= 1.0) {
          p3 = 1;
        } else if (rtDW.absx11 <= 1199.0) {
          p3 = static_cast<int32_T>(floor(rtDW.absx11));
        } else {
          p3 = 1199;
        }

        rtDW.absx21 = rtDW.srcYIntrinsic[p1];
        if (rtDW.absx21 <= 1.0) {
          itmp = 1;
        } else if (rtDW.absx21 <= 749.0) {
          itmp = static_cast<int32_T>(floor(rtDW.absx21));
        } else {
          itmp = 749;
        }

        if (rtDW.absx11 == p3) {
          p2 = (p3 - 1) * 750 + itmp;
          qx1 = rtDW.inputImage[p2 - 1];
          qx2 = rtDW.inputImage[p2];
        } else if (static_cast<real_T>(p3) + 1.0 == rtDW.absx11) {
          p2 = 750 * p3 + itmp;
          qx1 = rtDW.inputImage[p2 - 1];
          qx2 = rtDW.inputImage[p2];
        } else {
          int8_T tmp;
          int8_T tmp_0;
          rtDW.absx11 -= static_cast<real_T>(p3);
          p2 = (p3 - 1) * 750 + itmp;
          tmp = rtDW.inputImage[p2 - 1];
          p3 = 750 * p3 + itmp;
          tmp_0 = rtDW.inputImage[p3 - 1];
          if (tmp == tmp_0) {
            qx1 = tmp;
          } else {
            qx1 = static_cast<real32_T>(1.0 - rtDW.absx11) *
              static_cast<real32_T>(tmp) + static_cast<real32_T>(tmp_0) *
              static_cast<real32_T>(rtDW.absx11);
          }

          tmp = rtDW.inputImage[p2];
          tmp_0 = rtDW.inputImage[p3];
          if (tmp == tmp_0) {
            qx2 = tmp;
          } else {
            qx2 = static_cast<real32_T>(1.0 - rtDW.absx11) *
              static_cast<real32_T>(tmp) + static_cast<real32_T>(tmp_0) *
              static_cast<real32_T>(rtDW.absx11);
          }
        }

        if ((rtDW.absx21 == itmp) || (qx1 == qx2)) {
          qx2 = qx1;
        } else if (!(static_cast<real_T>(itmp) + 1.0 == rtDW.absx21)) {
          rtDW.absx11 = rtDW.absx21 - static_cast<real_T>(itmp);
          qx2 = static_cast<real32_T>(1.0 - rtDW.absx11) * qx1 +
            static_cast<real32_T>(rtDW.absx11) * qx2;
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

// Function for MATLAB Function: '<S1>/MATLAB Function3'
static void do_vectors(const int32_T a_data[], const int32_T a_size[1], const
  int32_T b_data[], const int32_T b_size[1], int32_T c_data[], int32_T c_size[1],
  int32_T ia_data[], int32_T ia_size[1], int32_T ib_data[], int32_T ib_size[1])
{
  int32_T c_ialast;
  int32_T iafirst;
  int32_T ialast;
  int32_T ibfirst;
  int32_T iblast;
  int32_T nc;
  int32_T nia;
  int32_T nib;
  rtDW.na = a_size[0];
  rtDW.nb = b_size[0];
  rtDW.ncmax = a_size[0] + b_size[0];
  c_size[0] = rtDW.ncmax;
  ia_size[0] = a_size[0];
  ib_size[0] = b_size[0];
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
    ak = a_data[ialast];
    while ((c_ialast < a_size[0]) && (a_data[c_ialast] == ak)) {
      c_ialast++;
    }

    ialast = c_ialast - 1;
    b_iblast = iblast + 1;
    bk = b_data[iblast];
    while ((b_iblast < b_size[0]) && (b_data[b_iblast] == bk)) {
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

  while (ialast + 1 <= rtDW.na) {
    c_ialast = ialast + 1;
    while ((c_ialast < a_size[0]) && (a_data[c_ialast] == a_data[ialast])) {
      c_ialast++;
    }

    nc++;
    nia++;
    c_data[nc] = a_data[ialast];
    ia_data[nia] = iafirst;
    ialast = c_ialast;
    iafirst = c_ialast + 1;
  }

  while (iblast + 1 <= rtDW.nb) {
    rtDW.na = iblast + 1;
    while ((rtDW.na < b_size[0]) && (b_data[rtDW.na] == b_data[iblast])) {
      rtDW.na++;
    }

    nc++;
    nib++;
    c_data[nc] = b_data[iblast];
    ib_data[nib - 1] = ibfirst + 1;
    iblast = rtDW.na;
    ibfirst = rtDW.na;
  }

  if (a_size[0] > 0) {
    if (nia + 1 < 1) {
      ia_size[0] = 0;
    } else {
      ia_size[0] = nia + 1;
    }
  }

  if (b_size[0] > 0) {
    if (nib < 1) {
      ib_size[0] = 0;
    } else {
      ib_size[0] = nib;
    }
  }

  if (rtDW.ncmax > 0) {
    if (nc + 1 < 1) {
      c_size[0] = 0;
    } else {
      c_size[0] = nc + 1;
    }
  }
}

// Function for MATLAB Function: '<S1>/MATLAB Function3'
static void findpeaks(const real_T Yin[1200], real_T Ypk_data[], int32_T
                      Ypk_size[2], real_T Xpk_data[], int32_T Xpk_size[2])
{
  char_T dir;
  char_T previousdir;
  boolean_T isinfykfirst;
  rtDW.nPk = -1;
  dir = 'n';
  rtDW.kfirst = -1;
  rtDW.ykfirst = (rtInf);
  isinfykfirst = true;
  for (rtDW.k_n = 0; rtDW.k_n < 1200; rtDW.k_n++) {
    rtDW.Yin = Yin[rtDW.k_n];
    if (rtDW.Yin != rtDW.ykfirst) {
      previousdir = dir;
      if (isinfykfirst) {
        dir = 'n';
      } else if (rtDW.Yin < rtDW.ykfirst) {
        dir = 'd';
        if (previousdir == 'i') {
          rtDW.nPk++;
          rtDW.fPk_data[rtDW.nPk] = rtDW.kfirst + 1;
        }
      } else {
        dir = 'i';
      }

      rtDW.ykfirst = rtDW.Yin;
      rtDW.kfirst = rtDW.k_n;
      isinfykfirst = false;
    }
  }

  if (rtDW.nPk + 1 < 1) {
    rtDW.nPk = -1;
  }

  rtDW.kfirst = 0;
  for (rtDW.k_n = 0; rtDW.k_n <= rtDW.nPk; rtDW.k_n++) {
    rtDW.fPk = rtDW.fPk_data[rtDW.k_n];
    rtDW.ykfirst = Yin[rtDW.fPk - 2];
    rtDW.Yin = Yin[rtDW.fPk];
    if ((rtDW.ykfirst >= rtDW.Yin) || rtIsNaN(rtDW.Yin)) {
      rtDW.Yin = rtDW.ykfirst;
    }

    if (Yin[rtDW.fPk - 1] - rtDW.Yin >= 0.0) {
      rtDW.kfirst++;
      rtDW.b_iPk_data[rtDW.kfirst - 1] = rtDW.fPk;
    }
  }

  if (rtDW.kfirst < 1) {
    rtDW.b_iPk_size[0] = 0;
  } else {
    rtDW.b_iPk_size[0] = rtDW.kfirst;
  }

  rtDW.iInfinite_size[0] = 0;
  do_vectors(rtDW.b_iPk_data, rtDW.b_iPk_size, rtDW.b_iPk_data,
             rtDW.iInfinite_size, rtDW.iPk_data, rtDW.iPk_size, rtDW.fPk_data,
             rtDW.fPk_size, rtDW.ib_data, rtDW.ib_size);
  rtDW.nPk = rtDW.iPk_size[0];
  rtDW.fPk = rtDW.iPk_size[0];
  if (rtDW.iPk_size[0] > 0) {
    rtDW.y_data[0] = 1;
    rtDW.kfirst = 1;
    for (rtDW.k_n = 2; rtDW.k_n <= rtDW.nPk; rtDW.k_n++) {
      rtDW.kfirst++;
      rtDW.y_data[rtDW.k_n - 1] = static_cast<int16_T>(rtDW.kfirst);
    }
  }

  if (rtDW.fPk - 1 >= 0) {
    memcpy(&rtDW.idx_data[0], &rtDW.y_data[0], static_cast<uint32_T>(rtDW.fPk) *
           sizeof(int16_T));
  }

  if (rtDW.iPk_size[0] > 1200) {
    rtDW.fPk_size[0] = 1200;
  } else {
    rtDW.fPk_size[0] = rtDW.iPk_size[0];
  }

  if (rtDW.fPk_size[0] < 1) {
    rtDW.nPk = -1;
  } else {
    rtDW.nPk = rtDW.fPk_size[0] - 1;
  }

  rtDW.b_iPk_size[0] = rtDW.nPk + 1;
  for (rtDW.kfirst = 0; rtDW.kfirst <= rtDW.nPk; rtDW.kfirst++) {
    rtDW.b_iPk_data[rtDW.kfirst] = rtDW.iPk_data[rtDW.idx_data[rtDW.kfirst] - 1];
  }

  Ypk_size[0] = 1;
  Ypk_size[1] = rtDW.nPk + 1;
  rtDW.nPk++;
  Xpk_size[0] = 1;
  Xpk_size[1] = rtDW.b_iPk_size[0];
  for (rtDW.kfirst = 0; rtDW.kfirst < rtDW.nPk; rtDW.kfirst++) {
    rtDW.k_n = rtDW.b_iPk_data[rtDW.kfirst];
    Ypk_data[rtDW.kfirst] = Yin[rtDW.k_n - 1];
    Xpk_data[rtDW.kfirst] = static_cast<int16_T>(static_cast<int16_T>(rtDW.k_n -
      1) + 1);
  }
}

// Function for MATLAB Function: '<S1>/MATLAB Function3'
static void eml_find(const boolean_T x[900000], coder::array<int32_T, 1U> &i,
                     coder::array<int32_T, 1U> &j)
{
  int32_T idx;
  int32_T ii;
  int32_T jj;
  boolean_T exitg1;
  idx = 0;
  i.set_size(900000);
  j.set_size(900000);
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 1200)) {
    boolean_T guard1;
    guard1 = false;
    if (x[((jj - 1) * 750 + ii) - 1]) {
      idx++;
      i[idx - 1] = ii;
      j[idx - 1] = jj;
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
    i.set_size(0);
    j.set_size(0);
  } else {
    i.set_size(idx);
    j.set_size(idx);
  }
}

static void binary_expand_op_1(coder::array<boolean_T, 1U> &in1, const coder::
  array<boolean_T, 1U> &in2, const coder::array<real_T, 1U> &in3, real_T in4)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S1>/MATLAB Function3'
  loop_ub = in3.size(0) == 1 ? in2.size(0) : in3.size(0);
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i = 0; i < loop_ub; i++) {
    in1[i] = (in2[i * stride_0_0] && (in3[i * stride_1_0] >= in4 - 80.0));
  }

  // End of MATLAB Function: '<S1>/MATLAB Function3'
}

static void binary_expand_op(coder::array<boolean_T, 1U> &in1, const coder::
  array<real_T, 1U> &in2, real_T in3)
{
  coder::array<boolean_T, 1U> in1_0;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S1>/MATLAB Function3'
  loop_ub = in2.size(0) == 1 ? in1.size(0) : in2.size(0);
  in1_0.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int32_T i = 0; i < loop_ub; i++) {
    in1_0[i] = (in1[i * stride_0_0] && (in2[i * stride_1_0] >= in3 - 80.0));
  }

  in1.set_size(in1_0.size(0));
  loop_ub = in1_0.size(0);
  for (int32_T i = 0; i < loop_ub; i++) {
    in1[i] = in1_0[i];
  }

  // End of MATLAB Function: '<S1>/MATLAB Function3'
}

static void and_k(coder::array<boolean_T, 1U> &in1, const coder::array<boolean_T,
                  1U> &in2, const coder::array<boolean_T, 1U> &in3)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;

  // MATLAB Function: '<S1>/MATLAB Function3'
  loop_ub = in3.size(0) == 1 ? in2.size(0) : in3.size(0);
  in1.set_size(loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i = 0; i < loop_ub; i++) {
    in1[i] = (in2[i * stride_0_0] && in3[i * stride_1_0]);
  }

  // End of MATLAB Function: '<S1>/MATLAB Function3'
}

// Function for MATLAB Function: '<S1>/MATLAB Function3'
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

// Function for MATLAB Function: '<S1>/MATLAB Function3'
static real_T xnrm2(int32_T n, const coder::array<real_T, 2U> &x, int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      int32_T kend;
      rtDW.scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > rtDW.scale) {
          real_T t;
          t = rtDW.scale / absxk;
          y = y * t * t + 1.0;
          rtDW.scale = absxk;
        } else {
          real_T t;
          t = absxk / rtDW.scale;
          y += t * t;
        }
      }

      y = rtDW.scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S1>/MATLAB Function3'
static void xswap(int32_T n, coder::array<real_T, 2U> &x, int32_T ix0, int32_T
                  iy0)
{
  for (int32_T k = 0; k < n; k++) {
    real_T temp;
    int32_T temp_tmp;
    int32_T tmp;
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];
    tmp = (iy0 + k) - 1;
    x[temp_tmp] = x[tmp];
    x[tmp] = temp;
  }
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S1>/MATLAB Function3'
static void xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, coder::array<
                   real_T, 2U> &C, int32_T ic0, int32_T ldc, real_T work[3])
{
  int32_T i;
  int32_T jA;
  int32_T lastc;
  int32_T lastv;
  if (tau != 0.0) {
    boolean_T exitg2;
    lastv = m;
    i = iv0 + m;
    while ((lastv > 0) && (C[i - 2] == 0.0)) {
      lastv--;
      i--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      int32_T exitg1;
      i = (lastc - 1) * ldc + ic0;
      jA = i;
      do {
        exitg1 = 0;
        if (jA <= (i + lastv) - 1) {
          if (C[jA - 1] != 0.0) {
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
    int32_T d;
    int32_T e;
    if (lastc != 0) {
      int32_T jy;
      memset(&work[0], 0, static_cast<uint8_T>(lastc) * sizeof(real_T));
      jy = 0;
      d = (lastc - 1) * ldc + ic0;
      for (i = ic0; ldc < 0 ? i >= d : i <= d; i += ldc) {
        rtDW.c = 0.0;
        e = (i + lastv) - 1;
        for (jA = i; jA <= e; jA++) {
          rtDW.c += C[((iv0 + jA) - i) - 1] * C[jA - 1];
        }

        work[jy] += rtDW.c;
        jy++;
      }
    }

    if (!(-tau == 0.0)) {
      jA = ic0;
      d = static_cast<uint8_T>(lastc);
      for (lastc = 0; lastc < d; lastc++) {
        rtDW.c = work[lastc];
        if (rtDW.c != 0.0) {
          rtDW.c *= -tau;
          e = lastv + jA;
          for (i = jA; i < e; i++) {
            C[i - 1] = C[((iv0 + i) - jA) - 1] * rtDW.c + C[i - 1];
          }
        }

        jA += ldc;
      }
    }
  }
}

// Function for MATLAB Function: '<S1>/MATLAB Function3'
static void qrpf(coder::array<real_T, 2U> &A, int32_T m, real_T tau_data[],
                 int32_T jpvt[3])
{
  int32_T b;
  int32_T itemp;
  int32_T ix;
  int32_T j;
  int32_T knt;
  rtDW.ma = A.size(0);
  rtDW.work[0] = 0.0;
  rtDW.vn1_f = xnrm2(m, A, 1);
  rtDW.vn1[0] = rtDW.vn1_f;
  rtDW.vn2[0] = rtDW.vn1_f;
  rtDW.work[1] = 0.0;
  rtDW.vn1_f = xnrm2(m, A, A.size(0) + 1);
  rtDW.vn1[1] = rtDW.vn1_f;
  rtDW.vn2[1] = rtDW.vn1_f;
  rtDW.work[2] = 0.0;
  rtDW.vn1_f = xnrm2(m, A, (A.size(0) << 1) + 1);
  rtDW.vn1[2] = rtDW.vn1_f;
  rtDW.vn2[2] = rtDW.vn1_f;
  if (m <= 3) {
    b = static_cast<uint8_T>(m);
  } else {
    b = 3;
  }

  for (j = 0; j < b; j++) {
    ix = j * rtDW.ma;
    rtDW.ii_l = ix + j;
    rtDW.mmi = m - j;
    itemp = 3 - j;
    knt = 0;
    if (3 - j > 1) {
      rtDW.smax = fabs(rtDW.vn1[j]);
      for (rtDW.pvt = 2; rtDW.pvt <= itemp; rtDW.pvt++) {
        rtDW.s = fabs(rtDW.vn1[(j + rtDW.pvt) - 1]);
        if (rtDW.s > rtDW.smax) {
          knt = rtDW.pvt - 1;
          rtDW.smax = rtDW.s;
        }
      }
    }

    rtDW.pvt = j + knt;
    if (rtDW.pvt != j) {
      xswap(m, A, rtDW.pvt * rtDW.ma + 1, ix + 1);
      itemp = jpvt[rtDW.pvt];
      jpvt[rtDW.pvt] = jpvt[j];
      jpvt[j] = itemp;
      rtDW.vn1[rtDW.pvt] = rtDW.vn1[j];
      rtDW.vn2[rtDW.pvt] = rtDW.vn2[j];
    }

    if (j + 1 < m) {
      rtDW.s = A[rtDW.ii_l];
      rtDW.pvt = rtDW.ii_l + 2;
      tau_data[j] = 0.0;
      if (rtDW.mmi > 0) {
        rtDW.vn1_f = xnrm2(rtDW.mmi - 1, A, rtDW.ii_l + 2);
        if (rtDW.vn1_f != 0.0) {
          rtDW.smax = rt_hypotd_snf(A[rtDW.ii_l], rtDW.vn1_f);
          if (A[rtDW.ii_l] >= 0.0) {
            rtDW.smax = -rtDW.smax;
          }

          if (fabs(rtDW.smax) < 1.0020841800044864E-292) {
            knt = 0;
            itemp = rtDW.ii_l + rtDW.mmi;
            do {
              knt++;
              for (ix = rtDW.pvt; ix <= itemp; ix++) {
                A[ix - 1] = A[ix - 1] * 9.9792015476736E+291;
              }

              rtDW.smax *= 9.9792015476736E+291;
              rtDW.s *= 9.9792015476736E+291;
            } while ((fabs(rtDW.smax) < 1.0020841800044864E-292) && (knt < 20));

            rtDW.smax = rt_hypotd_snf(rtDW.s, xnrm2(rtDW.mmi - 1, A, rtDW.ii_l +
              2));
            if (rtDW.s >= 0.0) {
              rtDW.smax = -rtDW.smax;
            }

            tau_data[j] = (rtDW.smax - rtDW.s) / rtDW.smax;
            rtDW.s = 1.0 / (rtDW.s - rtDW.smax);
            for (ix = rtDW.pvt; ix <= itemp; ix++) {
              A[ix - 1] = A[ix - 1] * rtDW.s;
            }

            for (rtDW.pvt = 0; rtDW.pvt < knt; rtDW.pvt++) {
              rtDW.smax *= 1.0020841800044864E-292;
            }

            rtDW.s = rtDW.smax;
          } else {
            tau_data[j] = (rtDW.smax - A[rtDW.ii_l]) / rtDW.smax;
            rtDW.s = 1.0 / (A[rtDW.ii_l] - rtDW.smax);
            ix = rtDW.ii_l + rtDW.mmi;
            for (knt = rtDW.pvt; knt <= ix; knt++) {
              A[knt - 1] = A[knt - 1] * rtDW.s;
            }

            rtDW.s = rtDW.smax;
          }
        }
      }

      A[rtDW.ii_l] = rtDW.s;
    } else {
      tau_data[j] = 0.0;
    }

    if (j + 1 < 3) {
      rtDW.smax = A[rtDW.ii_l];
      A[rtDW.ii_l] = 1.0;
      xzlarf(rtDW.mmi, 2 - j, rtDW.ii_l + 1, tau_data[j], A, (rtDW.ii_l +
              rtDW.ma) + 1, rtDW.ma, rtDW.work);
      A[rtDW.ii_l] = rtDW.smax;
    }

    for (rtDW.ii_l = j + 2; rtDW.ii_l < 4; rtDW.ii_l++) {
      rtDW.pvt = (rtDW.ii_l - 1) * rtDW.ma + j;
      rtDW.vn1_f = rtDW.vn1[rtDW.ii_l - 1];
      if (rtDW.vn1_f != 0.0) {
        rtDW.smax = fabs(A[rtDW.pvt]) / rtDW.vn1_f;
        rtDW.smax = 1.0 - rtDW.smax * rtDW.smax;
        if (rtDW.smax < 0.0) {
          rtDW.smax = 0.0;
        }

        rtDW.s = rtDW.vn1_f / rtDW.vn2[rtDW.ii_l - 1];
        rtDW.s = rtDW.s * rtDW.s * rtDW.smax;
        if (rtDW.s <= 1.4901161193847656E-8) {
          if (j + 1 < m) {
            rtDW.vn1_f = xnrm2(rtDW.mmi - 1, A, rtDW.pvt + 2);
            rtDW.vn1[rtDW.ii_l - 1] = rtDW.vn1_f;
            rtDW.vn2[rtDW.ii_l - 1] = rtDW.vn1_f;
          } else {
            rtDW.vn1[rtDW.ii_l - 1] = 0.0;
            rtDW.vn2[rtDW.ii_l - 1] = 0.0;
          }
        } else {
          rtDW.vn1[rtDW.ii_l - 1] = rtDW.vn1_f * sqrt(rtDW.smax);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S1>/MATLAB Function3'
static void xgeqp3(coder::array<real_T, 2U> &A, real_T tau_data[], int32_T
                   tau_size[1], int32_T jpvt[3])
{
  boolean_T guard1;
  rtDW.b_A_k.set_size(A.size(0), 3);
  rtDW.loop_ub = A.size(0) * 3;
  for (rtDW.i_dy = 0; rtDW.i_dy < rtDW.loop_ub; rtDW.i_dy++) {
    rtDW.b_A_k[rtDW.i_dy] = A[rtDW.i_dy];
  }

  if (A.size(0) <= 3) {
    rtDW.loop_ub = A.size(0);
  } else {
    rtDW.loop_ub = 3;
  }

  tau_size[0] = rtDW.loop_ub;
  if (rtDW.loop_ub - 1 >= 0) {
    memset(&tau_data[0], 0, static_cast<uint32_T>(rtDW.loop_ub) * sizeof(real_T));
  }

  guard1 = false;
  if (A.size(0) == 0) {
    guard1 = true;
  } else {
    if (A.size(0) <= 3) {
      rtDW.i_dy = A.size(0);
    } else {
      rtDW.i_dy = 3;
    }

    if (rtDW.i_dy < 1) {
      guard1 = true;
    } else {
      jpvt[0] = 1;
      jpvt[1] = 2;
      jpvt[2] = 3;
      qrpf(rtDW.b_A_k, A.size(0), tau_data, jpvt);
    }
  }

  if (guard1) {
    jpvt[0] = 1;
    jpvt[1] = 2;
    jpvt[2] = 3;
  }

  A.set_size(rtDW.b_A_k.size(0), 3);
  rtDW.loop_ub = rtDW.b_A_k.size(0);
  for (rtDW.i_dy = 0; rtDW.i_dy < 3; rtDW.i_dy++) {
    for (rtDW.b_A_d = 0; rtDW.b_A_d < rtDW.loop_ub; rtDW.b_A_d++) {
      A[rtDW.b_A_d + A.size(0) * rtDW.i_dy] = rtDW.b_A_k[rtDW.b_A_k.size(0) *
        rtDW.i_dy + rtDW.b_A_d];
    }
  }
}

// Function for MATLAB Function: '<S1>/MATLAB Function3'
static void qrsolve(const coder::array<real_T, 2U> &A, const coder::array<real_T,
                    1U> &B_0, real_T Y[3], int32_T *rankA)
{
  rtDW.b_A.set_size(A.size(0), 3);
  rtDW.maxmn = A.size(0) * 3;
  for (rtDW.b_j = 0; rtDW.b_j < rtDW.maxmn; rtDW.b_j++) {
    rtDW.b_A[rtDW.b_j] = A[rtDW.b_j];
  }

  xgeqp3(rtDW.b_A, rtDW.tau_data, rtDW.tau_size, rtDW.jpvt);
  *rankA = 0;
  if (rtDW.b_A.size(0) < 3) {
    rtDW.minmn = rtDW.b_A.size(0);
    rtDW.maxmn = 3;
  } else {
    rtDW.minmn = 3;
    rtDW.maxmn = rtDW.b_A.size(0);
  }

  if (rtDW.minmn > 0) {
    rtDW.tol = 2.2204460492503131E-15 * static_cast<real_T>(rtDW.maxmn) * fabs
      (rtDW.b_A[0]);
    while ((*rankA < rtDW.minmn) && (!(fabs(rtDW.b_A[rtDW.b_A.size(0) * *rankA +
              *rankA]) <= rtDW.tol))) {
      (*rankA)++;
    }
  }

  rtDW.minmn = 0;
  if (rtDW.b_A.size(0) <= 3) {
    rtDW.maxmn = rtDW.b_A.size(0);
  } else {
    rtDW.maxmn = 3;
  }

  if (rtDW.maxmn > 0) {
    for (rtDW.k_l = 0; rtDW.k_l < rtDW.maxmn; rtDW.k_l++) {
      if (rtDW.b_A[rtDW.b_A.size(0) * rtDW.k_l + rtDW.k_l] != 0.0) {
        rtDW.minmn++;
      }
    }
  }

  rtDW.b_B.set_size(B_0.size(0));
  rtDW.maxmn = B_0.size(0);
  for (rtDW.b_j = 0; rtDW.b_j < rtDW.maxmn; rtDW.b_j++) {
    rtDW.b_B[rtDW.b_j] = B_0[rtDW.b_j];
  }

  Y[0] = 0.0;
  Y[1] = 0.0;
  Y[2] = 0.0;
  rtDW.maxmn = rtDW.b_A.size(0);
  if (rtDW.b_A.size(0) <= 3) {
    rtDW.k_l = rtDW.b_A.size(0);
  } else {
    rtDW.k_l = 3;
  }

  for (rtDW.b_j = 0; rtDW.b_j < rtDW.k_l; rtDW.b_j++) {
    if (rtDW.tau_data[rtDW.b_j] != 0.0) {
      rtDW.tol = rtDW.b_B[rtDW.b_j];
      for (rtDW.c_i = rtDW.b_j + 2; rtDW.c_i <= rtDW.maxmn; rtDW.c_i++) {
        rtDW.tol += rtDW.b_A[(rtDW.b_A.size(0) * rtDW.b_j + rtDW.c_i) - 1] *
          rtDW.b_B[rtDW.c_i - 1];
      }

      rtDW.tol *= rtDW.tau_data[rtDW.b_j];
      if (rtDW.tol != 0.0) {
        rtDW.b_B[rtDW.b_j] = rtDW.b_B[rtDW.b_j] - rtDW.tol;
        for (rtDW.c_i = rtDW.b_j + 2; rtDW.c_i <= rtDW.maxmn; rtDW.c_i++) {
          rtDW.b_B[rtDW.c_i - 1] = rtDW.b_B[rtDW.c_i - 1] - rtDW.b_A
            [(rtDW.b_A.size(0) * rtDW.b_j + rtDW.c_i) - 1] * rtDW.tol;
        }
      }
    }
  }

  for (rtDW.maxmn = 0; rtDW.maxmn < rtDW.minmn; rtDW.maxmn++) {
    Y[rtDW.jpvt[rtDW.maxmn] - 1] = rtDW.b_B[rtDW.maxmn];
  }

  for (rtDW.maxmn = rtDW.minmn; rtDW.maxmn >= 1; rtDW.maxmn--) {
    rtDW.k_l = rtDW.jpvt[rtDW.maxmn - 1];
    Y[rtDW.k_l - 1] /= rtDW.b_A[((rtDW.maxmn - 1) * rtDW.b_A.size(0) +
      rtDW.maxmn) - 1];
    for (rtDW.b_j = 0; rtDW.b_j <= rtDW.maxmn - 2; rtDW.b_j++) {
      Y[rtDW.jpvt[rtDW.b_j] - 1] -= rtDW.b_A[(rtDW.maxmn - 1) * rtDW.b_A.size(0)
        + rtDW.b_j] * Y[rtDW.k_l - 1];
    }
  }
}

// Function for MATLAB Function: '<S1>/MATLAB Function3'
static void polyfit(const coder::array<real_T, 1U> &x, const coder::array<real_T,
                    1U> &y, real_T p[3])
{
  rtDW.V.set_size(x.size(0), 3);
  if (x.size(0) != 0) {
    rtDW.b = x.size(0);
    for (rtDW.k = 0; rtDW.k < rtDW.b; rtDW.k++) {
      rtDW.V[rtDW.k + (rtDW.V.size(0) << 1)] = 1.0;
    }

    rtDW.b = x.size(0);
    for (rtDW.k = 0; rtDW.k < rtDW.b; rtDW.k++) {
      rtDW.V[rtDW.k + rtDW.V.size(0)] = x[rtDW.k];
    }

    rtDW.b = x.size(0);
    for (rtDW.k = 0; rtDW.k < rtDW.b; rtDW.k++) {
      rtDW.V[rtDW.k] = rtDW.V[rtDW.k + rtDW.V.size(0)] * x[rtDW.k];
    }
  }

  qrsolve(rtDW.V, y, p, &rtDW.b);
}

// Model step function
void Perception_step(void)
{
  char_T *sErr;
  void *source_R;
  static const int16_T tmp[8] = { 519, 675, 113, 1049, 411, 411, 587, 587 };

  static const int16_T tmp_0[8] = { 450, 750, 450, 750, 0, 0, 750, 750 };

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

  // S-Function (svipscalenconvert): '<S1>/Image Data Type Conversion' incorporates:
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

  // End of S-Function (svipscalenconvert): '<S1>/Image Data Type Conversion'
  // temporary variables for in-place operation
  for (rtDW.i = 0; rtDW.i < 900000; rtDW.i++) {
    // S-Function (svipcolorconv): '<S1>/Color Space  Conversion' incorporates:
    //   S-Function (svipscalenconvert): '<S1>/Image Data Type Conversion'

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

    // S-Function (svipcolorconv): '<S1>/Color Space  Conversion'
    rtDW.ColorSpaceConversion[rtDW.i + 900000] = rtDW.count_right;

    // S-Function (svipcolorconv): '<S1>/Color Space  Conversion'
    rtDW.ColorSpaceConversion[rtDW.i + 1800000] = rtDW.bestInlierDis;

    // MATLAB Function: '<S1>/MATLAB Function4' incorporates:
    //   S-Function (svipcolorconv): '<S1>/Color Space  Conversion'

    rtDW.S_Channel[rtDW.i] = rtDW.count_right;
  }

  for (rtDW.i_d = 0; rtDW.i_d < 8; rtDW.i_d++) {
    // MATLAB Function: '<S1>/MATLAB Function1'
    rtDW.pts1[rtDW.i_d] = tmp[rtDW.i_d];

    // MATLAB Function: '<S1>/MATLAB Function2'
    rtDW.pts2[rtDW.i_d] = tmp_0[rtDW.i_d];
  }

  // S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'
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

  QRE_real_T_k(&rtDW.Q[0], &rtDW.Constraint[0], &rtDW.E[0], &rtDW.Qraux[0],
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
  rtDW.tformCompact_c[6] = rtDW.tformCompact[6] * rtDW.rightx_current;
  rtDW.tformCompact_c[7] = rtDW.tformCompact[7] * rtDW.rightx_current;
  rtDW.tformCompact_c[8] = (rtDW.tformCompact[8] - rtDW.cents1[0] *
    rtDW.tformCompact_c[6]) - rtDW.cents1[1] * rtDW.tformCompact_c[7];
  rtDW.tformCompact_c[0] = rtDW.tformCompact[0] * rtDW.s1DivS2;
  rtDW.tformCompact_c[1] = rtDW.tformCompact[1] * rtDW.s1DivS2;
  rtDW.tformCompact_c[2] = ((rtDW.cents2[0] * rtDW.tformCompact_c[8] -
    rtDW.tformCompact_c[0] * rtDW.cents1[0]) - rtDW.tformCompact_c[1] *
    rtDW.cents1[1]) + rtDW.tformCompact[2] * rtDW.count_right;
  rtDW.tformCompact_c[3] = rtDW.tformCompact[3] * rtDW.s1DivS2;
  rtDW.tformCompact_c[4] = rtDW.tformCompact[4] * rtDW.s1DivS2;
  rtDW.tformCompact_c[5] = ((rtDW.cents2[1] * rtDW.tformCompact_c[8] -
    rtDW.cents1[0] * rtDW.tformCompact_c[3]) - rtDW.cents1[1] *
    rtDW.tformCompact_c[4]) + rtDW.tformCompact[5] * rtDW.count_right;
  rtDW.tformCompact_c[0] += rtDW.cents2[0] * rtDW.tformCompact_c[6];
  rtDW.tformCompact_c[1] += rtDW.cents2[0] * rtDW.tformCompact_c[7];
  rtDW.tformCompact_c[3] += rtDW.cents2[1] * rtDW.tformCompact_c[6];
  rtDW.tformCompact_c[4] += rtDW.cents2[1] * rtDW.tformCompact_c[7];
  if (rtDW.tformCompact_c[8U] != 0.0) {
    rtDW.count_right = 1.0 / rtDW.tformCompact_c[8];
    for (rtDW.i = 0; rtDW.i < 8; rtDW.i++) {
      rtDW.tformCompact_c[static_cast<uint32_T>(rtDW.i)] *= rtDW.count_right;
    }

    rtDW.tformCompact_c[8] = 1.0;
    rtDW.bestCol = 0U;
    for (rtDW.i = 0; rtDW.i < 4; rtDW.i++) {
      rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_T>
        (rtDW.i)] = 0.0;
      for (rtDW.j = 0; rtDW.j < 2; rtDW.j++) {
        rtDW.count_right = 0.0;
        for (rtDW.m = 0; rtDW.m < 9; rtDW.m++) {
          rtDW.count_right +=
            rtDW.EstimateGeometricTransformation_DW_CONSTRT_ALL[rtDW.bestCol +
            static_cast<uint32_T>(rtDW.m)] * rtDW.tformCompact_c
            [static_cast<uint32_T>(rtDW.m)];
        }

        rtDW.bestCol += 9U;
        rtDW.EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_T>
          (rtDW.i)] += rtDW.count_right * rtDW.count_right;
      }
    }

    memcpy(&rtDW.bestTFormCompact[0], &rtDW.tformCompact_c[0], 9U * sizeof
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

  // MATLAB Function: '<S1>/MATLAB Function6'
  for (rtDW.i_d = 0; rtDW.i_d < 900000; rtDW.i_d++) {
    rtDW.rtb_S_Channel_b[rtDW.i_d] = (rtDW.S_Channel[rtDW.i_d] > 0.75);
  }

  // End of MATLAB Function: '<S1>/MATLAB Function6'

  // MATLABSystem: '<S1>/Warp' incorporates:
  //   S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'

  Warp_stepImpl(&rtDW.obj, rtDW.rtb_S_Channel_b,
                rtDW.EstimateGeometricTransformation, rtDW.bv);

  // MATLAB Function: '<S1>/MATLAB Function3' incorporates:
  //   MATLABSystem: '<S1>/Warp'

  for (rtDW.i = 0; rtDW.i < 1200; rtDW.i++) {
    rtDW.m = rtDW.i * 376;
    rtDW.nz_g = rtDW.bv[(rtDW.m / 376 * 750 + rtDW.m % 376) + 374];
    for (rtDW.j = 0; rtDW.j < 375; rtDW.j++) {
      rtDW.s_j = (rtDW.m + rtDW.j) + 1;
      rtDW.nz_g += rtDW.bv[(rtDW.s_j / 376 * 750 + rtDW.s_j % 376) + 374];
    }

    rtDW.nz[rtDW.i] = rtDW.nz_g;
  }

  findpeaks(rtDW.nz, rtDW.a__1_data, rtDW.a__1_size, rtDW.locs_data,
            rtDW.locs_size);
  rtDW.end = rtDW.locs_size[1] - 1;
  rtDW.trueCount = 0;
  for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
    // MATLAB Function: '<S1>/MATLAB Function3'
    if (rtDW.locs_data[rtDW.i] - rtDW.locs_data[0] > 200.0) {
      rtDW.trueCount++;
    }
  }

  rtDW.i_d = rtDW.trueCount;
  rtDW.trueCount = 0;
  for (rtDW.i = 0; rtDW.i <= rtDW.end; rtDW.i++) {
    // MATLAB Function: '<S1>/MATLAB Function3'
    if (rtDW.locs_data[rtDW.i] - rtDW.locs_data[0] > 200.0) {
      rtDW.tmp_data[rtDW.trueCount] = static_cast<int16_T>(rtDW.i);
      rtDW.trueCount++;
    }
  }

  // MATLAB Function: '<S1>/MATLAB Function3' incorporates:
  //   MATLABSystem: '<S1>/Warp'
  //   S-Function (svipesttform): '<S1>/Estimate Geometric Transformation'

  rtDW.rightx_current = rtDW.locs_data[rtDW.tmp_data[rtDW.i_d - 1]];
  rtDW.leftx_current = rtDW.locs_data[0];
  memset(&rtDW.left_lane_index_l[0], 0, 200000U * sizeof(int32_T));
  memset(&rtDW.right_lane_index[0], 0, 200000U * sizeof(int32_T));
  eml_find(rtDW.bv, rtDW.ii, rtDW.jj);
  rtDW.bestInlierDis = 0.0;
  rtDW.count_right = 0.0;
  rtDW.nz_g = rtDW.jj.size(0);
  rtDW.s_j = rtDW.ii.size(0);
  for (rtDW.i = 0; rtDW.i < 10; rtDW.i++) {
    rtDW.j = 750 - (rtDW.i + 1) * 75;
    rtDW.m = 750 - rtDW.i * 75;
    rtDW.n_tmp.set_size(rtDW.jj.size(0));
    for (rtDW.i_d = 0; rtDW.i_d < rtDW.nz_g; rtDW.i_d++) {
      rtDW.n_tmp[rtDW.i_d] = rtDW.jj[rtDW.i_d];
    }

    rtDW.b_tmp_tmp.set_size(rtDW.ii.size(0));
    for (rtDW.i_d = 0; rtDW.i_d < rtDW.s_j; rtDW.i_d++) {
      rtDW.end = rtDW.ii[rtDW.i_d];
      rtDW.b_tmp_tmp[rtDW.i_d] = ((rtDW.end >= rtDW.j) && (rtDW.end < rtDW.m));
    }

    if (rtDW.b_tmp_tmp.size(0) == rtDW.n_tmp.size(0)) {
      rtDW.b_tmp.set_size(rtDW.b_tmp_tmp.size(0));
      rtDW.j = rtDW.b_tmp_tmp.size(0);
      for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
        rtDW.b_tmp[rtDW.i_d] = (rtDW.b_tmp_tmp[rtDW.i_d] && (rtDW.n_tmp[rtDW.i_d]
          >= rtDW.leftx_current - 80.0));
      }
    } else {
      binary_expand_op_1(rtDW.b_tmp, rtDW.b_tmp_tmp, rtDW.n_tmp,
                         rtDW.leftx_current);
    }

    rtDW.o.set_size(rtDW.n_tmp.size(0));
    rtDW.j = rtDW.n_tmp.size(0);
    for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
      rtDW.o[rtDW.i_d] = (rtDW.n_tmp[rtDW.i_d] < rtDW.leftx_current + 80.0);
    }

    if (rtDW.b_tmp_tmp.size(0) == rtDW.n_tmp.size(0)) {
      rtDW.j = rtDW.b_tmp_tmp.size(0);
      for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
        rtDW.b_tmp_tmp[rtDW.i_d] = (rtDW.b_tmp_tmp[rtDW.i_d] &&
          (rtDW.n_tmp[rtDW.i_d] >= rtDW.rightx_current - 80.0));
      }
    } else {
      binary_expand_op(rtDW.b_tmp_tmp, rtDW.n_tmp, rtDW.rightx_current);
    }

    rtDW.r.set_size(rtDW.n_tmp.size(0));
    rtDW.j = rtDW.n_tmp.size(0);
    for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
      rtDW.r[rtDW.i_d] = (rtDW.n_tmp[rtDW.i_d] < rtDW.rightx_current + 80.0);
    }

    rtDW.ImageDataTypeConversion_b = rtDW.bestInlierDis + 1.0;
    if (rtDW.b_tmp.size(0) == rtDW.o.size(0)) {
      rtDW.r_m.set_size(rtDW.b_tmp.size(0));
      rtDW.j = rtDW.b_tmp.size(0);
      for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
        rtDW.r_m[rtDW.i_d] = (rtDW.b_tmp[rtDW.i_d] && rtDW.o[rtDW.i_d]);
      }
    } else {
      and_k(rtDW.r_m, rtDW.b_tmp, rtDW.o);
    }

    rtDW.end = rtDW.r_m.size(0) - 1;
    rtDW.trueCount = 0;
    for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
      if (rtDW.r_m[rtDW.i_d]) {
        rtDW.trueCount++;
      }
    }

    rtDW.m = static_cast<int32_T>((1.0 - (rtDW.bestInlierDis + 1.0)) +
      static_cast<real_T>(rtDW.trueCount));
    for (rtDW.j = 0; rtDW.j < rtDW.m; rtDW.j++) {
      rtDW.s1DivS2 = rtDW.ImageDataTypeConversion_b + static_cast<real_T>(rtDW.j);
      rtDW.end = rtDW.b_tmp.size(0);
      if (rtDW.b_tmp.size(0) == rtDW.o.size(0)) {
        rtDW.r2.set_size(rtDW.b_tmp.size(0));
        for (rtDW.i_d = 0; rtDW.i_d < rtDW.end; rtDW.i_d++) {
          rtDW.r2[rtDW.i_d] = (rtDW.b_tmp[rtDW.i_d] && rtDW.o[rtDW.i_d]);
        }
      } else {
        and_k(rtDW.r2, rtDW.b_tmp, rtDW.o);
      }

      rtDW.end = rtDW.b_tmp.size(0);
      if (rtDW.b_tmp.size(0) == rtDW.o.size(0)) {
        rtDW.r3.set_size(rtDW.b_tmp.size(0));
        for (rtDW.i_d = 0; rtDW.i_d < rtDW.end; rtDW.i_d++) {
          rtDW.r3[rtDW.i_d] = (rtDW.b_tmp[rtDW.i_d] && rtDW.o[rtDW.i_d]);
        }
      } else {
        and_k(rtDW.r3, rtDW.b_tmp, rtDW.o);
      }

      rtDW.end = rtDW.r2.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r2[rtDW.i_d]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r10.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r2[rtDW.i_d]) {
          rtDW.r10[rtDW.trueCount] = rtDW.i_d;
          rtDW.trueCount++;
        }
      }

      rtDW.end = rtDW.r3.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r3[rtDW.i_d]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r11.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r3[rtDW.i_d]) {
          rtDW.r11[rtDW.trueCount] = rtDW.i_d;
          rtDW.trueCount++;
        }
      }

      rtDW.left_lane_index_l[static_cast<int32_T>(rtDW.s1DivS2) - 1] =
        rtDW.jj[rtDW.r10[static_cast<int32_T>(rtDW.s1DivS2) - 1]];
      rtDW.left_lane_index_l[static_cast<int32_T>(rtDW.s1DivS2) + 99999] =
        rtDW.ii[rtDW.r11[static_cast<int32_T>(rtDW.s1DivS2) - 1]];
      rtDW.bestInlierDis++;
    }

    rtDW.ImageDataTypeConversion_b = rtDW.count_right + 1.0;
    if (rtDW.b_tmp_tmp.size(0) == rtDW.r.size(0)) {
      rtDW.r1.set_size(rtDW.b_tmp_tmp.size(0));
      rtDW.j = rtDW.b_tmp_tmp.size(0);
      for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
        rtDW.r1[rtDW.i_d] = (rtDW.b_tmp_tmp[rtDW.i_d] && rtDW.r[rtDW.i_d]);
      }
    } else {
      and_k(rtDW.r1, rtDW.b_tmp_tmp, rtDW.r);
    }

    rtDW.end = rtDW.r1.size(0) - 1;
    rtDW.trueCount = 0;
    for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
      if (rtDW.r1[rtDW.i_d]) {
        rtDW.trueCount++;
      }
    }

    rtDW.m = static_cast<int32_T>((1.0 - (rtDW.count_right + 1.0)) +
      static_cast<real_T>(rtDW.trueCount));
    for (rtDW.j = 0; rtDW.j < rtDW.m; rtDW.j++) {
      rtDW.s1DivS2 = rtDW.ImageDataTypeConversion_b + static_cast<real_T>(rtDW.j);
      rtDW.end = rtDW.b_tmp_tmp.size(0);
      if (rtDW.b_tmp_tmp.size(0) == rtDW.r.size(0)) {
        rtDW.r6.set_size(rtDW.b_tmp_tmp.size(0));
        for (rtDW.i_d = 0; rtDW.i_d < rtDW.end; rtDW.i_d++) {
          rtDW.r6[rtDW.i_d] = (rtDW.b_tmp_tmp[rtDW.i_d] && rtDW.r[rtDW.i_d]);
        }
      } else {
        and_k(rtDW.r6, rtDW.b_tmp_tmp, rtDW.r);
      }

      rtDW.end = rtDW.b_tmp_tmp.size(0);
      if (rtDW.b_tmp_tmp.size(0) == rtDW.r.size(0)) {
        rtDW.r8.set_size(rtDW.b_tmp_tmp.size(0));
        for (rtDW.i_d = 0; rtDW.i_d < rtDW.end; rtDW.i_d++) {
          rtDW.r8[rtDW.i_d] = (rtDW.b_tmp_tmp[rtDW.i_d] && rtDW.r[rtDW.i_d]);
        }
      } else {
        and_k(rtDW.r8, rtDW.b_tmp_tmp, rtDW.r);
      }

      rtDW.end = rtDW.r6.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r6[rtDW.i_d]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r13.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r6[rtDW.i_d]) {
          rtDW.r13[rtDW.trueCount] = rtDW.i_d;
          rtDW.trueCount++;
        }
      }

      rtDW.end = rtDW.r8.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r8[rtDW.i_d]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r14.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r8[rtDW.i_d]) {
          rtDW.r14[rtDW.trueCount] = rtDW.i_d;
          rtDW.trueCount++;
        }
      }

      rtDW.right_lane_index[static_cast<int32_T>(rtDW.s1DivS2) - 1] =
        rtDW.jj[rtDW.r13[static_cast<int32_T>(rtDW.s1DivS2) - 1]];
      rtDW.right_lane_index[static_cast<int32_T>(rtDW.s1DivS2) + 99999] =
        rtDW.ii[rtDW.r14[static_cast<int32_T>(rtDW.s1DivS2) - 1]];
      rtDW.count_right++;
    }

    if (rtDW.b_tmp.size(0) == rtDW.o.size(0)) {
      rtDW.r4.set_size(rtDW.b_tmp.size(0));
      rtDW.j = rtDW.b_tmp.size(0);
      for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
        rtDW.r4[rtDW.i_d] = (rtDW.b_tmp[rtDW.i_d] && rtDW.o[rtDW.i_d]);
      }
    } else {
      and_k(rtDW.r4, rtDW.b_tmp, rtDW.o);
    }

    rtDW.end = rtDW.r4.size(0) - 1;
    rtDW.trueCount = 0;
    for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
      if (rtDW.r4[rtDW.i_d]) {
        rtDW.trueCount++;
      }
    }

    if (rtDW.trueCount > 40) {
      if (rtDW.b_tmp.size(0) == rtDW.o.size(0)) {
        rtDW.r5.set_size(rtDW.b_tmp.size(0));
        rtDW.j = rtDW.b_tmp.size(0);
        for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
          rtDW.r5[rtDW.i_d] = (rtDW.b_tmp[rtDW.i_d] && rtDW.o[rtDW.i_d]);
        }
      } else {
        and_k(rtDW.r5, rtDW.b_tmp, rtDW.o);
      }

      rtDW.end = rtDW.r5.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r5[rtDW.i_d]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r12.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r5[rtDW.i_d]) {
          rtDW.r12[rtDW.trueCount] = rtDW.i_d;
          rtDW.trueCount++;
        }
      }

      rtDW.j = rtDW.r12.size(0);
      rtDW.n_tmp.set_size(rtDW.r12.size(0));
      for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
        rtDW.n_tmp[rtDW.i_d] = rtDW.jj[rtDW.r12[rtDW.i_d]];
      }

      rtDW.leftx_current = mean(rtDW.n_tmp);
    }

    if (rtDW.b_tmp_tmp.size(0) == rtDW.r.size(0)) {
      rtDW.r7.set_size(rtDW.b_tmp_tmp.size(0));
      rtDW.j = rtDW.b_tmp_tmp.size(0);
      for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
        rtDW.r7[rtDW.i_d] = (rtDW.b_tmp_tmp[rtDW.i_d] && rtDW.r[rtDW.i_d]);
      }
    } else {
      and_k(rtDW.r7, rtDW.b_tmp_tmp, rtDW.r);
    }

    rtDW.end = rtDW.r7.size(0) - 1;
    rtDW.trueCount = 0;
    for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
      if (rtDW.r7[rtDW.i_d]) {
        rtDW.trueCount++;
      }
    }

    if (rtDW.trueCount > 40) {
      if (rtDW.b_tmp_tmp.size(0) == rtDW.r.size(0)) {
        rtDW.r9.set_size(rtDW.b_tmp_tmp.size(0));
        rtDW.j = rtDW.b_tmp_tmp.size(0);
        for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
          rtDW.r9[rtDW.i_d] = (rtDW.b_tmp_tmp[rtDW.i_d] && rtDW.r[rtDW.i_d]);
        }
      } else {
        and_k(rtDW.r9, rtDW.b_tmp_tmp, rtDW.r);
      }

      rtDW.end = rtDW.r9.size(0) - 1;
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r9[rtDW.i_d]) {
          rtDW.trueCount++;
        }
      }

      rtDW.r15.set_size(rtDW.trueCount);
      rtDW.trueCount = 0;
      for (rtDW.i_d = 0; rtDW.i_d <= rtDW.end; rtDW.i_d++) {
        if (rtDW.r9[rtDW.i_d]) {
          rtDW.r15[rtDW.trueCount] = rtDW.i_d;
          rtDW.trueCount++;
        }
      }

      rtDW.j = rtDW.r15.size(0);
      rtDW.n_tmp.set_size(rtDW.r15.size(0));
      for (rtDW.i_d = 0; rtDW.i_d < rtDW.j; rtDW.i_d++) {
        rtDW.n_tmp[rtDW.i_d] = rtDW.jj[rtDW.r15[rtDW.i_d]];
      }

      rtDW.rightx_current = mean(rtDW.n_tmp);
    }
  }

  if (rtDW.bestInlierDis < 1.0) {
    rtDW.i = -1;
  } else {
    rtDW.i = static_cast<int32_T>(rtDW.bestInlierDis) - 1;
  }

  if (rtDW.count_right < 1.0) {
    rtDW.j = -1;
  } else {
    rtDW.j = static_cast<int32_T>(rtDW.count_right) - 1;
  }

  rtDW.left_lane_index.set_size(rtDW.i + 1);
  rtDW.left_lane_index_c.set_size(rtDW.i + 1);
  for (rtDW.i_d = 0; rtDW.i_d <= rtDW.i; rtDW.i_d++) {
    rtDW.left_lane_index[rtDW.i_d] = rtDW.left_lane_index_l[rtDW.i_d + 100000];
    rtDW.left_lane_index_c[rtDW.i_d] = rtDW.left_lane_index_l[rtDW.i_d];
  }

  polyfit(rtDW.left_lane_index, rtDW.left_lane_index_c, rtDW.p);
  rtDW.left_lane_index.set_size(rtDW.j + 1);
  rtDW.left_lane_index_c.set_size(rtDW.j + 1);
  for (rtDW.i_d = 0; rtDW.i_d <= rtDW.j; rtDW.i_d++) {
    rtDW.left_lane_index[rtDW.i_d] = rtDW.right_lane_index[rtDW.i_d + 100000];
    rtDW.left_lane_index_c[rtDW.i_d] = rtDW.right_lane_index[rtDW.i_d];
  }

  polyfit(rtDW.left_lane_index, rtDW.left_lane_index_c, rtDW.b_p);
  for (rtDW.i_d = 0; rtDW.i_d < 751; rtDW.i_d++) {
    rtDW.xleft[rtDW.i_d] = rtDW.p[0];
  }

  for (rtDW.i = 0; rtDW.i < 2; rtDW.i++) {
    rtDW.count_right = rtDW.p[rtDW.i + 1];
    for (rtDW.i_d = 0; rtDW.i_d < 751; rtDW.i_d++) {
      rtDW.xleft[rtDW.i_d] = static_cast<real_T>(rtDW.i_d) * rtDW.xleft[rtDW.i_d]
        + rtDW.count_right;
    }
  }

  for (rtDW.i_d = 0; rtDW.i_d < 751; rtDW.i_d++) {
    rtDW.xright[rtDW.i_d] = rtDW.b_p[0];
  }

  for (rtDW.i = 0; rtDW.i < 2; rtDW.i++) {
    rtDW.count_right = rtDW.b_p[rtDW.i + 1];
    for (rtDW.i_d = 0; rtDW.i_d < 751; rtDW.i_d++) {
      rtDW.xright[rtDW.i_d] = static_cast<real_T>(rtDW.i_d) *
        rtDW.xright[rtDW.i_d] + rtDW.count_right;
    }
  }

  // Outport: '<Root>/Out1' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function3'

  rtY.Out1 = 600.0 - (rtDW.xleft[750] + rtDW.xright[750]) / 2.0;
}

// Model initialize function
void Perception_initialize(void)
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

    // Start for S-Function (svipesttform): '<S1>/Estimate Geometric Transformation' 
    srand(clock());

    // InitializeConditions for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' 
    LibReset(&rtDW.FromMultimediaFile_HostLib[0U]);

    // Start for MATLABSystem: '<S1>/Warp'
    rtDW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      rtDW.obj.TformProjective.T[i] = self_T[i];
    }

    // End of Start for MATLABSystem: '<S1>/Warp'
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
