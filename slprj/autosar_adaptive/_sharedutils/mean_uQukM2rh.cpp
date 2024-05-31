//
//  mean_uQukM2rh.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "lkas".
//
//  Model version              : 1.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Fri May 31 20:08:20 2024
//  Created for block: lkas


#include <stdint.h>
#include "mean_uQukM2rh.h"

// Function for MATLAB Function: '<S2>/MATLAB Function1'
double mean_uQukM2rh(const double x_data[], const int32_t *x_size)
{
  double b_y;
  if (*x_size == 0) {
    b_y = 0.0;
  } else {
    int32_t firstBlockLength;
    int32_t lastBlockLength;
    int32_t nblocks;
    int32_t xblockoffset;
    if (*x_size <= 1024) {
      firstBlockLength = *x_size;
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = static_cast<int32_t>(static_cast<uint32_t>(*x_size) >> 10);
      lastBlockLength = *x_size - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }

    b_y = x_data[0];
    for (xblockoffset = 2; xblockoffset <= firstBlockLength; xblockoffset++) {
      b_y += x_data[xblockoffset - 1];
    }

    for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++)
    {
      double bsum;
      int32_t hi;
      xblockoffset = (firstBlockLength - 1) << 10;
      bsum = x_data[xblockoffset];
      if (firstBlockLength == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }

      for (int32_t b_k{2}; b_k <= hi; b_k++) {
        bsum += x_data[(xblockoffset + b_k) - 1];
      }

      b_y += bsum;
    }
  }

  return b_y / static_cast<double>(*x_size);
}
