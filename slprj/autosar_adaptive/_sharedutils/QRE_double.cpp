//
//  QRE_double.cpp
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
#include <stdbool.h>
#include "QRE_double.h"
#include "QRDC_double.h"
#include "QRSL1_double.h"

void QRE_double(double outQ[], double outR[], double outE[], double qrAux[],
                double work[], int32_t jpvt[], double sPtr[], int32_t M, int32_t
                N, bool economy)
{
  int32_t L;
  int32_t j;
  int32_t pq;
  int32_t ps;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
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

  pq = 0;
  for (j = 0; j < M * L; j++) {
    outQ[j] = 0.0;
  }

  for (j = 0; j < L; j++) {
    outQ[pq] = 1.0;
    pq = (pq + M) + 1;
  }

  // Convert cols of identity into cols of q. Use info stored in lower triangle of r and in vector qraux to work on columns of identity matrix I and transform them into q*I(:,j) i.e. the columns of q. 
  pq = 0;
  for (j = 0; j < L; j++) {
    QRSL1_double(&outR[0], &qrAux[0], &outQ[pq], M, N);
    pq += M;
  }

  if (economy && (M > N)) {
    // Copy upper triangle of r to s
    L = 0;
    ps = 0;
    for (j = 1; j - 1 < N; j++) {
      for (pq = 0; pq < j; pq++) {
        sPtr[ps] = outR[L];
        ps++;
        L++;
      }

      L = (L + M) - j;
      for (pq = 0; pq < N - j; pq++) {
        sPtr[ps] = 0.0;
        ps++;
      }
    }
  } else {
    // Zero strict lower triangle of r
    L = M * N - 1;
    for (j = N; j - 1 >= 0; j--) {
      for (pq = M; pq > j; pq--) {
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
  pq = 0;
  for (j = 0; j < N; j++) {
    outE[L] = jpvt[pq] + 1;
    pq = L + 1;
    L++;
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}
