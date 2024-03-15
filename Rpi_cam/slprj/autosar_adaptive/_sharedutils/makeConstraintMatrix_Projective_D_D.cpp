//
//  makeConstraintMatrix_Projective_D_D.cpp
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
#include "makeConstraintMatrix_Projective_D_D.h"

void makeConstraintMatrix_Projective_D_D(const double pts1[], const double pts2[],
  uint32_t sampleNum, uint32_t maxSampleNum, double constraint[])
{
  uint32_t j;
  uint32_t k;

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  // Generate the constraint matrix.
  j = 0U;
  k = 6U;
  for (uint32_t i{0U}; i < sampleNum; i++) {
    double tmp;
    double tmp_1;
    uint32_t tmp_0;
    constraint[k - 6U] = 0.0;
    constraint[k + 4294967291U] = 0.0;
    constraint[k + 4294967292U] = 0.0;
    tmp_0 = j + maxSampleNum;
    tmp = pts1[tmp_0];
    constraint[k + 4294967293U] = -tmp;
    constraint[k + 4294967294U] = -pts1[j];
    constraint[k + UINT32_MAX] = -1.0;
    constraint[k] = pts2[j];
    constraint[k] *= tmp;
    constraint[k + 1U] = pts2[j];
    constraint[k + 1U] *= pts1[j];
    constraint[k + 2U] = pts2[j];
    constraint[k + 3U] = tmp;
    constraint[k + 4U] = pts1[j];
    constraint[k + 5U] = 1.0;
    constraint[k + 6U] = 0.0;
    constraint[k + 7U] = 0.0;
    constraint[k + 8U] = 0.0;
    tmp_1 = -pts2[tmp_0];
    constraint[k + 9U] = tmp_1;
    constraint[k + 9U] *= tmp;
    constraint[k + 10U] = tmp_1;
    constraint[k + 10U] *= pts1[j];
    constraint[k + 11U] = tmp_1;
    k += 18U;
    j++;
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
}
