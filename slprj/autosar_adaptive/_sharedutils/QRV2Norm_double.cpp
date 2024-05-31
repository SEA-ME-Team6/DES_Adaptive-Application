//
//  QRV2Norm_double.cpp
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
#include "QRV2Norm_double.h"
#include <cmath>

void QRV2Norm_double(const double V[], int32_t N, double v2norm[])
{
  double val;
  int32_t vi;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  val = 0.0;
  vi = 0;
  for (int32_t i{0}; i < N; i++) {
    double tmp;
    tmp = std::abs(V[vi]);
    if (val > tmp) {
      double tmpQRSL;
      tmpQRSL = V[vi] / val;
      val *= std::sqrt(tmpQRSL * tmpQRSL + 1.0);
    } else if (V[vi] == 0.0) {
      val = 0.0;
    } else {
      double tmpQRSL;
      tmpQRSL = val / V[vi];
      val = std::sqrt(tmpQRSL * tmpQRSL + 1.0) * tmp;
    }

    vi++;
  }

  v2norm[0U] = val;

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}
