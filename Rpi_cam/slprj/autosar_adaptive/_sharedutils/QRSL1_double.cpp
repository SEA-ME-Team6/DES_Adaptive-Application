//
//  QRSL1_double.cpp
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
//  Created for block: Rpi_cam


#include <stdint.h>
#include "QRSL1_double.h"
#include "QRCompQy_double.h"

void QRSL1_double(double qr[], const double qrAux[], double y[], int32_t n,
                  int32_t k)
{
  int32_t j;
  int32_t pqraux;
  int32_t y_0;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}
