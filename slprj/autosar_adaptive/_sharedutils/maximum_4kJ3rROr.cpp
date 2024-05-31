//
//  maximum_4kJ3rROr.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "Rpi_cam".
//
//  Model version              : 1.156
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Fri May 31 15:19:32 2024
//  Created for block: Rpi_cam


#include <stdint.h>
#include "maximum_4kJ3rROr.h"

// Function for MATLAB Function: '<S2>/MATLAB Function1'
double maximum_4kJ3rROr(const double x_data[], const int32_t *x_size)
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
