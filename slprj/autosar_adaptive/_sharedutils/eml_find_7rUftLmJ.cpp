//
//  eml_find_7rUftLmJ.cpp
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


#include <stdbool.h>
#include <stdint.h>
#include "eml_find_7rUftLmJ.h"

// Function for MATLAB Function: '<S2>/MATLAB Function1'
void eml_find_7rUftLmJ(const bool x[307200], int32_t i_data[], int32_t *i_size,
  int32_t j_data[], int32_t *j_size)
{
  int32_t idx;
  int32_t ii;
  int32_t jj;
  bool exitg1;
  idx = 0;
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 640)) {
    bool guard1;
    guard1 = false;
    if (x[((jj - 1) * 480 + ii) - 1]) {
      idx++;
      i_data[idx - 1] = ii;
      j_data[idx - 1] = jj;
      if (idx >= 307200) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
      if (ii > 480) {
        ii = 1;
        jj++;
      }
    }
  }

  if (idx < 1) {
    *i_size = 0;
    *j_size = 0;
  } else {
    *i_size = idx;
    *j_size = idx;
  }
}
