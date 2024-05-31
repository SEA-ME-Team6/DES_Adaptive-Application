//
//  QRE_double.h
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


#ifndef QRE_double_h_
#define QRE_double_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"

extern void QRE_double(double outQ[], double outR[], double outE[], double
  qrAux[], double work[], int32_t jpvt[], double sPtr[], int32_t M, int32_t N,
  bool economy);

#endif                                 // QRE_double_h_
