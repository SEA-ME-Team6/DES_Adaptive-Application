//
//  QRSL1_double.cpp
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
#include "QRSL1_double.h"
#include "QRCompQy_double.h"

void QRSL1_double(double qr[], const double qrAux[], double y[], int32_t n,
                  int32_t k)
{
  int32_t i;
  int32_t j;
  int32_t pqraux_tmp;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  if (k <= n - 1) {
    j = k;
  } else {
    j = n - 1;
  }

  if (j != 0) {
    pqraux_tmp = j;
    for (i = j; i > 0; i--) {
      QRCompQy_double(&qr[0], &qrAux[j - 1], &y[pqraux_tmp - 1], n, i - 1);
      pqraux_tmp = j - 1;
      j--;
    }
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}
