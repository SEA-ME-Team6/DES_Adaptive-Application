//
//  QRDC_double.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "lkas".
//
//  Model version              : 1.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Fri May 31 20:05:31 2024
//  Created for block: lkas


#include <stdint.h>
#include "QRDC_double.h"
#include "QRV2Norm_double.h"
#include <cmath>

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

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}
