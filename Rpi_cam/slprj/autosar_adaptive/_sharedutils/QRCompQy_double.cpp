//
//  QRCompQy_double.cpp
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
#include "QRCompQy_double.h"
#include <cmath>

void QRCompQy_double(double qr[], const double qrAuxj[], double y[], int32_t n,
                     int32_t j)
{
  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
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

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}
