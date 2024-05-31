//
//  lkas.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "lkas".
//
//  Model version              : 1.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Fri May 31 20:22:50 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: Intel->x86-64 (Windows64)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "lkas.h"
#include "lkas_types.h"
#include <stdbool.h>
#include <stdint.h>
#include <cstring>
#include <cmath>
#include "makeConstraintMatrix_Projective_D_D.h"
#include "normPts_D_D.h"
#include "QRE_double.h"
#include <emmintrin.h>
#include <array>

void lkas::lkas_v4l2Capture_updateV4L2Settings
  (codertarget_raspi_internal_Raspiv4l2Capture_lkas_T *obj, bool forceUpdate)
{
  std::array<char, 11> b;
  std::array<char, 9> c;
  std::array<char, 10> e;
  std::array<char, 18> i;
  std::array<char, 12> j;
  uint8_t status;
  static const std::array<char, 11> b_0{ { 'B', 'r', 'i', 'g', 'h', 't', 'n',
      'e', 's', 's', '\x00' } };

  static const std::array<char, 9> c_0{ { 'C', 'o', 'n', 't', 'r', 'a', 's', 't',
      '\x00' } };

  static const std::array<char, 11> d{ { 'S', 'a', 't', 'u', 'r', 'a', 't', 'i',
      'o', 'n', '\x00' } };

  static const std::array<char, 10> e_0{ { 'S', 'h', 'a', 'r', 'p', 'n', 'e',
      's', 's', '\x00' } };

  static const std::array<char, 10> f{ { 'C', 'a', 'm', 'e', 'r', 'a', 'P', 'a',
      'n', '\x00' } };

  static const std::array<char, 11> g{ { 'C', 'a', 'm', 'e', 'r', 'a', 'T', 'i',
      'l', 't', '\x00' } };

  static const std::array<char, 11> h{ { 'C', 'a', 'm', 'e', 'r', 'a', 'Z', 'o',
      'o', 'm', '\x00' } };

  static const std::array<char, 18> i_1{ { 'E', 'n', 'a', 'b', 'l', 'e', 'M',
      'a', 'n', 'u', 'a', 'l', 'F', 'o', 'c', 'u', 's', '\x00' } };

  static const std::array<char, 12> j_0{ { 'M', 'a', 'n', 'u', 'a', 'l', 'F',
      'o', 'c', 'u', 's', '\x00' } };

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  if ((obj->Brightness != obj->BrightnessInternal) || forceUpdate) {
    obj->BrightnessInternal = obj->Brightness;
    for (int32_t i_0{0}; i_0 < 11; i_0++) {
      b[i_0] = b_0[i_0];
    }

    EXT_updateV4L2Control(&b[0], static_cast<float>(obj->Brightness), 0, &status);
  }

  if ((obj->Contrast != obj->ContrastInternal) || forceUpdate) {
    obj->ContrastInternal = obj->Contrast;
    for (int32_t i_0{0}; i_0 < 9; i_0++) {
      c[i_0] = c_0[i_0];
    }

    EXT_updateV4L2Control(&c[0], static_cast<float>(obj->Contrast), 0, &status);
  }

  if ((obj->Saturation != obj->SaturationInternal) || forceUpdate) {
    obj->SaturationInternal = obj->Saturation;
    for (int32_t i_0{0}; i_0 < 11; i_0++) {
      b[i_0] = d[i_0];
    }

    EXT_updateV4L2Control(&b[0], static_cast<float>(obj->Saturation), 0, &status);
  }

  if ((obj->Sharpness != obj->SharpnessInternal) || forceUpdate) {
    obj->SharpnessInternal = obj->Sharpness;
    for (int32_t i_0{0}; i_0 < 10; i_0++) {
      e[i_0] = e_0[i_0];
    }

    EXT_updateV4L2Control(&e[0], static_cast<float>(obj->Sharpness), 0, &status);
  }

  if ((obj->CameraPan != obj->CameraPanInternal) || forceUpdate) {
    obj->CameraPanInternal = obj->CameraPan;
    for (int32_t i_0{0}; i_0 < 10; i_0++) {
      e[i_0] = f[i_0];
    }

    EXT_updateV4L2Control(&e[0], static_cast<float>(obj->CameraPan), 0, &status);
  }

  if ((obj->CameraTilt != obj->CameraTiltInternal) || forceUpdate) {
    obj->CameraTiltInternal = obj->CameraTilt;
    for (int32_t i_0{0}; i_0 < 11; i_0++) {
      b[i_0] = g[i_0];
    }

    EXT_updateV4L2Control(&b[0], static_cast<float>(obj->CameraTilt), 0, &status);
  }

  if ((obj->CameraZoom != obj->CameraZoomInternal) || forceUpdate) {
    obj->CameraZoomInternal = obj->CameraZoom;
    for (int32_t i_0{0}; i_0 < 11; i_0++) {
      b[i_0] = h[i_0];
    }

    EXT_updateV4L2Control(&b[0], static_cast<float>(obj->CameraZoom), 0, &status);
  }

  if ((!obj->EnableManualFocusInternal) || forceUpdate) {
    obj->EnableManualFocusInternal = true;
    for (int32_t i_0{0}; i_0 < 18; i_0++) {
      i[i_0] = i_1[i_0];
    }

    EXT_updateV4L2Control(&i[0], 1.0F, 0, &status);
  }

  if ((obj->ManualFocus != obj->ManualFocusInternal) || forceUpdate) {
    obj->ManualFocusInternal = obj->ManualFocus;
    for (int32_t i_0{0}; i_0 < 12; i_0++) {
      j[i_0] = j_0[i_0];
    }

    EXT_updateV4L2Control(&j[0], static_cast<float>(obj->ManualFocus), 0,
                          &status);
  }

  // End of Start for MATLABSystem: '<Root>/V4L2 Video Capture'
}

void lkas::lkas_SystemCore_step
  (codertarget_raspi_internal_Raspiv4l2Capture_lkas_T *obj, uint8_t varargout_1
   [307200], uint8_t varargout_2[307200], uint8_t varargout_3[307200])
{
  double ts;

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  lkas_v4l2Capture_updateV4L2Settings(obj, false);
  EXT_webcamReadFrame(0, &ts, &varargout_1[0], &varargout_2[0], &varargout_3[0]);
}

void lkas::lkas_Warp_stepImpl(vision_internal_blocks_Warp_lkas_T *b_this, const
  bool Image[307200], const double input2[9], bool Jout[307200])
{
  __m128d tmp;
  __m128d tmp_1;
  std::array<double, 9> tinv;
  std::array<double, 9> x;
  double tmp_0[2];
  double absx11;
  double absx21;
  double absx31;
  double tinv_0;
  double tinv_1;
  double tinv_2;
  double tinv_3;
  double tinv_4;
  double tinv_5;
  int32_t itmp;
  int32_t p1;
  int32_t p2;
  int32_t p3;
  for (p2 = 0; p2 < 9; p2++) {
    // Start for MATLABSystem: '<S4>/Warp'
    absx11 = input2[p2];
    b_this->TformProjective.T[p2] = absx11;
    x[p2] = absx11;
  }

  p1 = 1;
  p2 = 3;
  p3 = 6;

  // Start for MATLABSystem: '<S4>/Warp'
  absx11 = std::abs(b_this->TformProjective.T[0]);
  absx21 = std::abs(b_this->TformProjective.T[1]);
  absx31 = std::abs(b_this->TformProjective.T[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 4;
    p2 = 0;
    x[0] = b_this->TformProjective.T[1];
    x[1] = b_this->TformProjective.T[0];
    x[3] = b_this->TformProjective.T[4];
    x[4] = b_this->TformProjective.T[3];
    x[6] = b_this->TformProjective.T[7];
    x[7] = b_this->TformProjective.T[6];
  } else if (absx31 > absx11) {
    p1 = 7;
    p3 = 0;
    x[0] = b_this->TformProjective.T[2];
    x[2] = b_this->TformProjective.T[0];
    x[3] = b_this->TformProjective.T[5];
    x[5] = b_this->TformProjective.T[3];
    x[6] = b_this->TformProjective.T[8];
    x[8] = b_this->TformProjective.T[6];
  }

  absx11 = x[1] / x[0];
  tmp = _mm_div_pd(_mm_loadu_pd(&x[1]), _mm_set1_pd(x[0]));
  _mm_storeu_pd(&tmp_0[0], tmp);
  x[1] = tmp_0[0];

  // Start for MATLABSystem: '<S4>/Warp'
  x[2] /= x[0];
  tmp = _mm_set_pd(tmp_0[1], absx11);
  tmp_1 = _mm_sub_pd(_mm_loadu_pd(&x[4]), _mm_mul_pd(tmp, _mm_set1_pd(x[3])));
  _mm_storeu_pd(&x[4], tmp_1);
  tmp = _mm_sub_pd(_mm_loadu_pd(&x[7]), _mm_mul_pd(tmp, _mm_set1_pd(x[6])));
  _mm_storeu_pd(&x[7], tmp);

  // Start for MATLABSystem: '<S4>/Warp'
  if (std::abs(x[5]) > std::abs(x[4])) {
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    x[1] = tmp_0[1];
    x[2] = absx11;
    absx11 = x[4];
    x[4] = x[5];
    x[5] = absx11;
    absx11 = x[7];
    x[7] = x[8];
    x[8] = absx11;
  }

  absx11 = x[5] / x[4];
  x[8] -= absx11 * x[7];

  // Start for MATLABSystem: '<S4>/Warp'
  absx21 = (x[1] * absx11 - x[2]) / x[8];
  absx31 = -(x[7] * absx21 + x[1]) / x[4];
  tinv[p1 - 1] = ((1.0 - x[3] * absx31) - x[6] * absx21) / x[0];
  tinv[p1] = absx31;
  tinv[p1 + 1] = absx21;
  absx21 = -absx11 / x[8];
  absx31 = (1.0 - x[7] * absx21) / x[4];
  tinv[p2] = -(x[3] * absx31 + x[6] * absx21) / x[0];
  tinv[p2 + 1] = absx31;
  tinv[p2 + 2] = absx21;
  absx21 = 1.0 / x[8];
  absx31 = -x[7] * absx21 / x[4];
  tinv[p3] = -(x[3] * absx31 + x[6] * absx21) / x[0];
  tinv[p3 + 1] = absx31;
  tinv[p3 + 2] = absx21;
  absx11 = tinv[6];
  absx21 = tinv[7];
  absx31 = tinv[8];

  // Start for MATLABSystem: '<S4>/Warp'
  tinv_0 = tinv[0];
  tinv_1 = tinv[1];
  tinv_2 = tinv[2];
  tinv_3 = tinv[3];
  tinv_4 = tinv[4];
  tinv_5 = tinv[5];
  for (p1 = 0; p1 < 640; p1++) {
    for (p2 = 0; p2 < 480; p2++) {
      double srcXIntrinsic_tmp;

      // Start for MATLABSystem: '<S4>/Warp'
      srcXIntrinsic_tmp = ((((static_cast<double>(p1) + 1.0) - 0.5) + 0.5) *
                           absx11 + (((static_cast<double>(p2) + 1.0) - 0.5) +
        0.5) * absx21) + absx31;
      p3 = 480 * p1 + p2;
      lkas_B.srcXIntrinsic[p3] = ((((((static_cast<double>(p1) + 1.0) - 0.5) +
        0.5) * tinv_0 + (((static_cast<double>(p2) + 1.0) - 0.5) + 0.5) * tinv_1)
        + tinv_2) / srcXIntrinsic_tmp - 0.5) + 0.5;
      lkas_B.srcYIntrinsic[p3] = ((((((static_cast<double>(p1) + 1.0) - 0.5) +
        0.5) * tinv_3 + (((static_cast<double>(p2) + 1.0) - 0.5) + 0.5) * tinv_4)
        + tinv_5) / srcXIntrinsic_tmp - 0.5) + 0.5;
    }
  }

  for (p2 = 0; p2 < 307200; p2++) {
    // Start for MATLABSystem: '<S4>/Warp'
    lkas_B.inputImage[p2] = static_cast<int8_t>(Image[p2]);
  }

  for (p1 = 0; p1 < 307200; p1++) {
    float qx2;

    // Start for MATLABSystem: '<S4>/Warp'
    absx21 = lkas_B.srcXIntrinsic[p1];
    if ((absx21 >= 1.0) && (absx21 <= 640.0)) {
      absx11 = lkas_B.srcYIntrinsic[p1];
      if ((absx11 >= 1.0) && (absx11 <= 480.0)) {
        float qx1;
        if (absx21 <= 1.0) {
          itmp = 1;
        } else if (absx21 <= 639.0) {
          itmp = static_cast<int32_t>(std::floor(absx21));
        } else {
          itmp = 639;
        }

        absx11 = lkas_B.srcYIntrinsic[p1];
        if (absx11 <= 1.0) {
          p3 = 1;
        } else if (absx11 <= 479.0) {
          p3 = static_cast<int32_t>(std::floor(absx11));
        } else {
          p3 = 479;
        }

        if (absx21 == itmp) {
          p2 = (itmp - 1) * 480 + p3;
          qx1 = lkas_B.inputImage[p2 - 1];
          qx2 = lkas_B.inputImage[p2];
        } else if (static_cast<double>(itmp) + 1.0 == absx21) {
          p2 = 480 * itmp + p3;
          qx1 = lkas_B.inputImage[p2 - 1];
          qx2 = lkas_B.inputImage[p2];
        } else {
          int8_t tmp_2;
          int8_t tmp_3;
          absx21 -= static_cast<double>(itmp);
          p2 = (itmp - 1) * 480 + p3;
          tmp_2 = lkas_B.inputImage[p2 - 1];
          itmp = 480 * itmp + p3;
          tmp_3 = lkas_B.inputImage[itmp - 1];
          if (tmp_2 == tmp_3) {
            qx1 = tmp_2;
          } else {
            qx1 = static_cast<float>(1.0 - absx21) * static_cast<float>(tmp_2) +
              static_cast<float>(tmp_3) * static_cast<float>(absx21);
          }

          tmp_2 = lkas_B.inputImage[p2];
          tmp_3 = lkas_B.inputImage[itmp];
          if (tmp_2 == tmp_3) {
            qx2 = tmp_2;
          } else {
            qx2 = static_cast<float>(1.0 - absx21) * static_cast<float>(tmp_2) +
              static_cast<float>(tmp_3) * static_cast<float>(absx21);
          }
        }

        if ((absx11 == p3) || (qx1 == qx2)) {
          qx2 = qx1;
        } else if (static_cast<double>(p3) + 1.0 != absx11) {
          absx11 -= static_cast<double>(p3);
          qx2 = static_cast<float>(1.0 - absx11) * qx1 + static_cast<float>
            (absx11) * qx2;
        }
      } else {
        qx2 = 0.0F;
      }
    } else {
      qx2 = 0.0F;
    }

    Jout[p1] = (qx2 > 0.5F);
  }
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
void lkas::lkas_eml_find(const bool x[307200], int32_t i_data[], int32_t *i_size,
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

void lkas::lkas_and(bool in1_data[], int32_t *in1_size, const bool in2_data[],
                    const int32_t *in2_size, const bool in3_data[], const
                    int32_t *in3_size)
{
  int32_t loop_ub;
  int32_t stride_0_0;
  int32_t stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (*in3_size == 1) {
    *in1_size = *in2_size;
  } else {
    *in1_size = *in3_size;
  }

  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (*in3_size != 1);
  if (*in3_size == 1) {
    loop_ub = *in2_size;
  } else {
    loop_ub = *in3_size;
  }

  for (int32_t i{0}; i < loop_ub; i++) {
    in1_data[i] = (in2_data[i * stride_0_0] && in3_data[i * stride_1_0]);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

void lkas::lkas_binary_expand_op_3(bool in1_data[], int32_t *in1_size, const
  bool in2_data[], const int32_t *in2_size, const int32_t in3_data[], const
  int32_t *in3_size)
{
  int32_t loop_ub;
  int32_t stride_0_0;
  int32_t stride_1_0_tmp;

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (*in3_size == 1) {
    if (*in3_size == 1) {
      *in1_size = *in2_size;
    } else {
      *in1_size = *in3_size;
    }
  } else {
    *in1_size = *in3_size;
  }

  stride_0_0 = (*in2_size != 1);
  stride_1_0_tmp = (*in3_size != 1);
  if (*in3_size == 1) {
    if (*in3_size == 1) {
      loop_ub = *in2_size;
    } else {
      loop_ub = *in3_size;
    }
  } else {
    loop_ub = *in3_size;
  }

  for (int32_t i{0}; i < loop_ub; i++) {
    int32_t tmp;
    tmp = in3_data[i * stride_1_0_tmp];
    in1_data[i] = (in2_data[i * stride_0_0] && (tmp >= 0) && (tmp < 160));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

// Function for MATLAB Function: '<S2>/MATLAB Function1'
double lkas::lkas_mean(const double x_data[], const int32_t *x_size)
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

// Function for MATLAB Function: '<S2>/MATLAB Function1'
double lkas::lkas_maximum(const double x_data[], const int32_t *x_size)
{
  double ex;
  int32_t last;
  last = *x_size;
  if (*x_size <= 2) {
    if (*x_size == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[*x_size - 1];
      if (x_data[0] >= ex) {
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

void lkas::lkas_binary_expand_op_2(bool in1_data[], int32_t *in1_size, const
  bool in2_data[], const int32_t *in2_size, const bool in3_data[], const bool
  in4_data[], const int32_t *in4_size, const bool in5_data[], const int32_t
  *in5_size)
{
  int32_t loop_ub;
  int32_t stride_0_0;
  int32_t stride_1_0;
  int32_t stride_2_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (*in5_size == 1) {
    if (*in4_size == 1) {
      *in1_size = *in2_size;
    } else {
      *in1_size = *in4_size;
    }
  } else {
    *in1_size = *in5_size;
  }

  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (*in4_size != 1);
  stride_2_0 = (*in5_size != 1);
  if (*in5_size == 1) {
    if (*in4_size == 1) {
      loop_ub = *in2_size;
    } else {
      loop_ub = *in4_size;
    }
  } else {
    loop_ub = *in5_size;
  }

  for (int32_t i{0}; i < loop_ub; i++) {
    int32_t tmp;
    tmp = i * stride_0_0;
    in1_data[i] = (in2_data[tmp] && in3_data[tmp] && in4_data[i * stride_1_0] &&
                   in5_data[i * stride_2_0]);
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

void lkas::lkas_binary_expand_op(bool in1_data[], int32_t *in1_size, const
  int32_t in2_data[], const int32_t *in2_size, double in3, double in4, const
  int32_t in5_data[], const int32_t *in5_size, double in6)
{
  int32_t loop_ub;
  int32_t stride_0_0;
  int32_t stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (*in5_size == 1) {
    *in1_size = *in2_size;
  } else {
    *in1_size = *in5_size;
  }

  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (*in5_size != 1);
  if (*in5_size == 1) {
    loop_ub = *in2_size;
  } else {
    loop_ub = *in5_size;
  }

  for (int32_t i{0}; i < loop_ub; i++) {
    double tmp;
    tmp = in2_data[i * stride_0_0];
    in1_data[i] = ((tmp >= in3) && (tmp < in4) && (in5_data[i * stride_1_0] >=
      in6 - 40.0));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

void lkas::lkas_binary_expand_op_1(bool in1_data[], int32_t *in1_size, const
  double in2_data[], const int32_t *in2_size, double in3, double in4, const
  double in5_data[], const int32_t *in5_size, double in6)
{
  int32_t loop_ub;
  int32_t stride_0_0;
  int32_t stride_1_0;

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (*in5_size == 1) {
    *in1_size = *in2_size;
  } else {
    *in1_size = *in5_size;
  }

  stride_0_0 = (*in2_size != 1);
  stride_1_0 = (*in5_size != 1);
  if (*in5_size == 1) {
    loop_ub = *in2_size;
  } else {
    loop_ub = *in5_size;
  }

  for (int32_t i{0}; i < loop_ub; i++) {
    double tmp;
    tmp = in2_data[i * stride_0_0];
    in1_data[i] = ((tmp >= in3) && (tmp < in4) && (in5_data[i * stride_1_0] >=
      in6 - 40.0));
  }

  // End of MATLAB Function: '<S2>/MATLAB Function1'
}

codertarget_raspi_internal_Raspiv4l2Capture_lkas_T *lkas::
  lkas_Raspiv4l2Capture_Raspiv4l2Capture
  (codertarget_raspi_internal_Raspiv4l2Capture_lkas_T *obj)
{
  codertarget_raspi_internal_Raspiv4l2Capture_lkas_T *b_obj;

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  obj->BrightnessInternal = 0.5;
  obj->SaturationInternal = 0.5;
  obj->ContrastInternal = 0.5;
  obj->SharpnessInternal = 0.5;
  obj->CameraZoomInternal = 0.5;
  obj->ManualFocusInternal = 0.5;
  obj->CameraPanInternal = 0.0;
  obj->CameraTiltInternal = 0.0;
  obj->EnableManualFocusInternal = true;
  obj->isInitialized = 0;
  b_obj = obj;
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

void lkas::lkas_SystemCore_setup
  (codertarget_raspi_internal_Raspiv4l2Capture_lkas_T *obj)
{
  std::array<char, 101> b_errorMessage;
  std::array<char, 12> devName;
  int32_t i;
  int8_t resolutionStatus;
  uint8_t camIndex;
  static const std::array<char, 12> devName_0{ { '/', 'd', 'e', 'v', '/', 'v',
      'i', 'd', 'e', 'o', '0', '\x00' } };

  static const std::array<char, 101> b_errorMessage_0{ { 'W', 'e', 'b', 'c', 'a',
      'm', ' ', 'c', 'a', 'n', 'n', 'o', 't', ' ', 'b', 'e', ' ', 'i', 'n', 'i',
      't', 'i', 'a', 'l', 'i', 'z', 'e', 'd', ' ', 'p', 'r', 'o', 'p', 'e', 'r',
      'l', 'y', '.', ' ', 'P', 'l', 'e', 'a', 's', 'e', ' ', 'c', 'h', 'e', 'c',
      'k', ' ', 'i', 'f', ' ', 't', 'h', 'e', ' ', 'd', 'e', 'v', 'i', 'c', 'e',
      ' ', 's', 'u', 'p', 'p', 'o', 'r', 't', 's', ' ', 't', 'h', 'e', ' ', 's',
      'p', 'e', 'c', 'i', 'f', 'i', 'e', 'd', ' ', 'r', 'e', 's', 'o', 'l', 'u',
      't', 'i', 'o', 'n', '.', '\x00' } };

  obj->isSetupComplete = false;

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  obj->isInitialized = 1;
  getCameraList();
  for (i = 0; i < 12; i++) {
    devName[i] = devName_0[i];
  }

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  camIndex = getCameraAddrIndex(&devName[0], 11U);
  resolutionStatus = validateResolution(camIndex, 640, 480);
  if (resolutionStatus >= 0) {
    // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
    EXT_webcamInit(0, 0, 0, 0, 0, 0, 640U, 480U, 2U, 2U, 1U, 0.1);
  } else {
    // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
    std::memcpy(&b_errorMessage[0], &b_errorMessage_0[0], 101U * sizeof(char));
    std::perror(&b_errorMessage[0]);

    // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
    std::exit(0);
  }

  // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
  lkas_v4l2Capture_updateV4L2Settings(obj, true);
  obj->isSetupComplete = true;
}

// Model step function
void lkas::step()
{
  __m128d tmp;
  __m128d tmp_0;
  std::array<double, 72> Constraint;
  std::array<double, 8> E;
  std::array<int8_t, 4> EstimateGeometricTransformation_DW_BEST_SAMPLE;
  std::array<double, 72> EstimateGeometricTransformation_DW_CONSTRT_ALL;
  std::array<double, 4> EstimateGeometricTransformation_DW_DISTANCE;
  std::array<double, 8> EstimateGeometricTransformation_DW_PTSNORM1;
  std::array<double, 8> EstimateGeometricTransformation_DW_PTSNORM2;
  std::array<uint32_t, 4> EstimateGeometricTransformation_DW_SAMPLEIDX;
  std::array<int32_t, 8> JPVT;
  std::array<double, 72> Q;
  std::array<double, 8> Qraux;
  std::array<double, 81> RV;
  std::array<double, 8> Work;
  std::array<double, 9> bestTFormCompact;
  std::array<double, 2> cents1;
  std::array<double, 2> cents2;
  std::array<double, 9> rtb_EstimateGeometricTransformation;
  std::array<double, 8> rtb_pts1;
  std::array<double, 8> rtb_pts2;
  std::array<double, 9> tformCompact;
  std::array<double, 9> tformCompact_0;
  double ImageDataTypeConversion;
  double ImageDataTypeConversion_0;
  double maxSum;
  double min;
  double s;
  double scale1;
  double scale2;
  double sum;
  double win_y_low;
  int32_t bestCol;
  int32_t bestInlierNum;
  int32_t j;
  int32_t k;
  int32_t xtmp_tmp;
  uint32_t idx;
  uint8_t xtmp;
  static const std::array<int16_t, 8> tmp_1{ { 145, 500, 27, 639, 300, 300, 415,
      415 } };

  static const std::array<int16_t, 8> tmp_2{ { 40, 600, 40, 600, 300, 300, 480,
      480 } };

  int32_t c_size;
  int32_t ii_size;
  int32_t jj_size;

  // MATLABSystem: '<Root>/V4L2 Video Capture'
  if (lkas_DW.obj.Brightness != 0.5) {
    lkas_DW.obj.Brightness = 0.5;
  }

  if (lkas_DW.obj.Saturation != 0.5) {
    lkas_DW.obj.Saturation = 0.5;
  }

  if (lkas_DW.obj.Contrast != 0.5) {
    lkas_DW.obj.Contrast = 0.5;
  }

  if (lkas_DW.obj.Sharpness != 0.5) {
    lkas_DW.obj.Sharpness = 0.5;
  }

  if (lkas_DW.obj.CameraPan != 0.0) {
    lkas_DW.obj.CameraPan = 0.0;
  }

  if (lkas_DW.obj.CameraTilt != 0.0) {
    lkas_DW.obj.CameraTilt = 0.0;
  }

  if (lkas_DW.obj.CameraZoom != 0.5) {
    lkas_DW.obj.CameraZoom = 0.5;
  }

  if (lkas_DW.obj.ManualFocus != 0.5) {
    lkas_DW.obj.ManualFocus = 0.5;
  }

  lkas_SystemCore_step(&lkas_DW.obj, &lkas_B.uv[0], &lkas_B.uv1[0], &lkas_B.uv2
                       [0]);

  // Math: '<S3>/Transpose' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'

  for (j = 0; j < 640; j++) {
    for (bestInlierNum = 0; bestInlierNum < 480; bestInlierNum++) {
      lkas_B.uv3[bestInlierNum + 480 * j] = lkas_B.uv[640 * bestInlierNum + j];
    }
  }

  std::memcpy(&lkas_B.outputImage[0], &lkas_B.uv3[0], 307200U * sizeof(uint8_t));

  // End of Math: '<S3>/Transpose'

  // Math: '<S3>/Transpose1' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'

  for (j = 0; j < 640; j++) {
    for (bestInlierNum = 0; bestInlierNum < 480; bestInlierNum++) {
      lkas_B.uv[bestInlierNum + 480 * j] = lkas_B.uv1[640 * bestInlierNum + j];
    }
  }

  std::memcpy(&lkas_B.outputImage[307200], &lkas_B.uv[0], 307200U * sizeof
              (uint8_t));

  // End of Math: '<S3>/Transpose1'

  // Math: '<S3>/Transpose2' incorporates:
  //   MATLABSystem: '<Root>/V4L2 Video Capture'

  for (j = 0; j < 640; j++) {
    for (bestInlierNum = 0; bestInlierNum < 480; bestInlierNum++) {
      lkas_B.uv[bestInlierNum + 480 * j] = lkas_B.uv2[640 * bestInlierNum + j];
    }
  }

  std::memcpy(&lkas_B.outputImage[614400], &lkas_B.uv[0], 307200U * sizeof
              (uint8_t));

  // End of Math: '<S3>/Transpose2'

  // MATLAB Function: '<Root>/MATLAB Function'
  for (bestCol = 0; bestCol < 3; bestCol++) {
    for (j = 0; j < 640; j++) {
      for (bestInlierNum = 0; bestInlierNum < 240; bestInlierNum++) {
        xtmp_tmp = (480 * j + bestInlierNum) + 307200 * bestCol;
        xtmp = lkas_B.outputImage[xtmp_tmp];
        k = ((480 * j - bestInlierNum) + 307200 * bestCol) + 479;
        lkas_B.outputImage[xtmp_tmp] = lkas_B.outputImage[k];
        lkas_B.outputImage[k] = xtmp;
      }
    }

    for (bestInlierNum = 0; bestInlierNum < 320; bestInlierNum++) {
      for (j = 0; j < 480; j++) {
        xtmp_tmp = (480 * bestInlierNum + j) + 307200 * bestCol;
        xtmp = lkas_B.outputImage[xtmp_tmp];
        k = ((639 - bestInlierNum) * 480 + j) + 307200 * bestCol;
        lkas_B.outputImage[xtmp_tmp] = lkas_B.outputImage[k];
        lkas_B.outputImage[k] = xtmp;
      }
    }
  }

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion'
  for (bestInlierNum = 0; bestInlierNum <= 921598; bestInlierNum += 2) {
    lkas_B.ImageDataTypeConversion[bestInlierNum] = static_cast<double>
      (lkas_B.outputImage[bestInlierNum]) / 255.0;
    lkas_B.ImageDataTypeConversion[bestInlierNum + 1] = static_cast<double>
      (lkas_B.outputImage[bestInlierNum + 1]) / 255.0;
  }

  // End of S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion'
  // temporary variables for in-place operation
  for (bestInlierNum = 0; bestInlierNum < 307200; bestInlierNum++) {
    // S-Function (svipcolorconv): '<S4>/Color Space  Conversion' incorporates:
    //   S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion'

    // First get the min and max of the RGB triplet
    sum = lkas_B.ImageDataTypeConversion[bestInlierNum];
    ImageDataTypeConversion = lkas_B.ImageDataTypeConversion[bestInlierNum +
      307200];
    if (sum > ImageDataTypeConversion) {
      ImageDataTypeConversion_0 = lkas_B.ImageDataTypeConversion[bestInlierNum +
        614400];
      min = std::fmin(ImageDataTypeConversion, ImageDataTypeConversion_0);
      maxSum = std::fmax(sum, ImageDataTypeConversion_0);
    } else {
      ImageDataTypeConversion_0 = lkas_B.ImageDataTypeConversion[bestInlierNum +
        614400];
      min = std::fmin(sum, ImageDataTypeConversion_0);
      maxSum = std::fmax(ImageDataTypeConversion, ImageDataTypeConversion_0);
    }

    s = maxSum - min;
    if (maxSum != 0.0) {
      min = s / maxSum;
    } else {
      min = 0.0;
    }

    if (s != 0.0) {
      if (sum == maxSum) {
        sum = (ImageDataTypeConversion - ImageDataTypeConversion_0) / s;
      } else if (ImageDataTypeConversion == maxSum) {
        sum = (ImageDataTypeConversion_0 - sum) / s + 2.0;
      } else {
        sum = (sum - ImageDataTypeConversion) / s + 4.0;
      }

      sum /= 6.0;
      if (sum < 0.0) {
        sum++;
      }
    } else {
      sum = 0.0;
    }

    // assign the results
    lkas_B.ColorSpaceConversion[bestInlierNum] = sum;
    lkas_B.ColorSpaceConversion[bestInlierNum + 307200] = min;

    // S-Function (svipcolorconv): '<S4>/Color Space  Conversion'
    lkas_B.ColorSpaceConversion[bestInlierNum + 614400] = maxSum;

    // MATLAB Function: '<S4>/MATLAB Function7' incorporates:
    //   S-Function (svipcolorconv): '<S4>/Color Space  Conversion'

    lkas_B.V_Channel[bestInlierNum] = maxSum;
  }

  for (j = 0; j < 8; j++) {
    // MATLAB Function: '<S4>/MATLAB Function1'
    rtb_pts1[j] = tmp_1[j];

    // MATLAB Function: '<S4>/MATLAB Function2'
    rtb_pts2[j] = tmp_2[j];
  }

  // S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
  std::memset(&rtb_EstimateGeometricTransformation[0], 0, 9U * sizeof(double));
  EstimateGeometricTransformation_DW_BEST_SAMPLE[0] = 0;
  EstimateGeometricTransformation_DW_BEST_SAMPLE[1] = 1;
  EstimateGeometricTransformation_DW_BEST_SAMPLE[2] = 2;
  EstimateGeometricTransformation_DW_BEST_SAMPLE[3] = 3;
  makeConstraintMatrix_Projective_D_D((const double *)&rtb_pts1[0], (const
    double *)&rtb_pts2[0], 4U, 4U,
    &EstimateGeometricTransformation_DW_CONSTRT_ALL[0]);
  for (bestInlierNum = 0; bestInlierNum < 4; bestInlierNum++) {
    EstimateGeometricTransformation_DW_SAMPLEIDX[bestInlierNum] =
      static_cast<uint32_t>
      (EstimateGeometricTransformation_DW_BEST_SAMPLE[bestInlierNum]);
  }

  bestCol = 0;
  normPts_D_D((const double *)&rtb_pts1[0], (const uint32_t *)
              &EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
              &EstimateGeometricTransformation_DW_PTSNORM1[0], &scale1, &cents1
              [0]);
  normPts_D_D((const double *)&rtb_pts2[0], (const uint32_t *)
              &EstimateGeometricTransformation_DW_SAMPLEIDX[0], 4U, 4U,
              &EstimateGeometricTransformation_DW_PTSNORM2[0], &scale2, &cents2
              [0]);
  makeConstraintMatrix_Projective_D_D((const double *)
    &EstimateGeometricTransformation_DW_PTSNORM1[0], (const double *)
    &EstimateGeometricTransformation_DW_PTSNORM2[0], 4U, 4U, &Constraint[0]);
  for (bestInlierNum = 0; bestInlierNum < 8; bestInlierNum++) {
    JPVT[static_cast<uint32_t>(bestInlierNum)] = 0;
  }

  QRE_double(&Q[0], &Constraint[0], &E[0], &Qraux[0], &Work[0], &JPVT[0], &RV[0],
             9, 8, true);
  maxSum = 0.0;
  for (bestInlierNum = 0; bestInlierNum < 9; bestInlierNum++) {
    for (j = 0; j < 9; j++) {
      if (static_cast<uint32_t>(bestInlierNum) != static_cast<uint32_t>(j)) {
        sum = 0.0;
      } else {
        sum = -1.0;
      }

      for (k = 0; k < 8; k++) {
        idx = static_cast<uint32_t>(k) * 9U;
        sum += Q[idx + static_cast<uint32_t>(bestInlierNum)] * Q[idx +
          static_cast<uint32_t>(j)];
      }

      RV[static_cast<uint32_t>(bestInlierNum) * 9U + static_cast<uint32_t>(j)] =
        sum;
      if (sum < 0.0) {
        sum = -sum;
      }

      if (maxSum < sum) {
        maxSum = sum;
        bestCol = bestInlierNum;
      }
    }
  }

  j = static_cast<int32_t>(static_cast<uint32_t>(bestCol) * 9U);
  for (bestInlierNum = 0; bestInlierNum < 9; bestInlierNum++) {
    tformCompact[static_cast<uint32_t>(bestInlierNum)] = RV[static_cast<uint32_t>
      (j) + static_cast<uint32_t>(bestInlierNum)];
  }

  scale2 = 1.0 / scale2;
  tmp = _mm_mul_pd(_mm_loadu_pd(&tformCompact[6]), _mm_set1_pd(scale1));
  _mm_storeu_pd(&tformCompact_0[6], tmp);
  tformCompact_0[8] = (tformCompact[8] - cents1[0] * tformCompact_0[6]) -
    cents1[1] * tformCompact_0[7];
  tmp = _mm_set1_pd(scale1 * scale2);
  tmp_0 = _mm_mul_pd(_mm_loadu_pd(&tformCompact[0]), tmp);
  _mm_storeu_pd(&tformCompact_0[0], tmp_0);
  tformCompact_0[2] = ((cents2[0] * tformCompact_0[8] - tformCompact_0[0] *
                        cents1[0]) - tformCompact_0[1] * cents1[1]) +
    tformCompact[2] * scale2;
  tmp = _mm_mul_pd(_mm_loadu_pd(&tformCompact[3]), tmp);
  _mm_storeu_pd(&tformCompact_0[3], tmp);
  tformCompact_0[5] = ((cents2[1] * tformCompact_0[8] - cents1[0] *
                        tformCompact_0[3]) - cents1[1] * tformCompact_0[4]) +
    tformCompact[5] * scale2;
  tmp = _mm_add_pd(_mm_mul_pd(_mm_set1_pd(cents2[0]), _mm_loadu_pd
    (&tformCompact_0[6])), _mm_loadu_pd(&tformCompact_0[0]));
  _mm_storeu_pd(&tformCompact_0[0], tmp);
  tmp = _mm_add_pd(_mm_mul_pd(_mm_set1_pd(cents2[1]), _mm_loadu_pd
    (&tformCompact_0[6])), _mm_loadu_pd(&tformCompact_0[3]));
  _mm_storeu_pd(&tformCompact_0[3], tmp);
  if (tformCompact_0[8U] != 0.0) {
    scale1 = 1.0 / tformCompact_0[8];
    for (bestInlierNum = 0; bestInlierNum < 8; bestInlierNum++) {
      tformCompact_0[static_cast<uint32_t>(bestInlierNum)] *= scale1;
    }

    tformCompact_0[8] = 1.0;
    idx = 0U;
    for (bestInlierNum = 0; bestInlierNum < 4; bestInlierNum++) {
      EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_t>
        (bestInlierNum)] = 0.0;
      for (j = 0; j < 2; j++) {
        scale1 = 0.0;
        for (k = 0; k < 9; k++) {
          scale1 += EstimateGeometricTransformation_DW_CONSTRT_ALL[idx +
            static_cast<uint32_t>(k)] * tformCompact_0[static_cast<uint32_t>(k)];
        }

        idx += 9U;
        EstimateGeometricTransformation_DW_DISTANCE[static_cast<uint32_t>
          (bestInlierNum)] += scale1 * scale1;
      }
    }

    std::memcpy(&bestTFormCompact[0], &tformCompact_0[0], 9U * sizeof(double));
    bestInlierNum = 0;
    if (EstimateGeometricTransformation_DW_DISTANCE[0] <= 2.5) {
      bestInlierNum = 1;
    }

    if (EstimateGeometricTransformation_DW_DISTANCE[1] <= 2.5) {
      bestInlierNum = static_cast<int32_t>(static_cast<uint32_t>(bestInlierNum)
        + 1U);
    }

    if (EstimateGeometricTransformation_DW_DISTANCE[2] <= 2.5) {
      bestInlierNum = static_cast<int32_t>(static_cast<uint32_t>(bestInlierNum)
        + 1U);
    }

    if (EstimateGeometricTransformation_DW_DISTANCE[3] <= 2.5) {
      bestInlierNum = static_cast<int32_t>(static_cast<uint32_t>(bestInlierNum)
        + 1U);
    }
  } else {
    bestInlierNum = 0;
  }

  if (static_cast<uint32_t>(bestInlierNum) >= 4U) {
    rtb_EstimateGeometricTransformation[0] = bestTFormCompact[4];
    rtb_EstimateGeometricTransformation[1] = bestTFormCompact[3];
    rtb_EstimateGeometricTransformation[2] = bestTFormCompact[5];
    rtb_EstimateGeometricTransformation[3] = bestTFormCompact[1];
    rtb_EstimateGeometricTransformation[4] = bestTFormCompact[0];
    rtb_EstimateGeometricTransformation[5] = bestTFormCompact[2];
    rtb_EstimateGeometricTransformation[6] = bestTFormCompact[7];
    rtb_EstimateGeometricTransformation[7] = bestTFormCompact[6];
    rtb_EstimateGeometricTransformation[8] = bestTFormCompact[8];
  }

  // End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'

  // MATLAB Function: '<S4>/MATLAB Function8'
  for (j = 0; j < 307200; j++) {
    lkas_B.rtb_V_Channel_p[j] = (lkas_B.V_Channel[j] > 0.5);
  }

  // End of MATLAB Function: '<S4>/MATLAB Function8'

  // MATLABSystem: '<S4>/Warp' incorporates:
  //   S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'

  lkas_Warp_stepImpl(&lkas_DW.obj_c, &lkas_B.rtb_V_Channel_p[0],
                     &rtb_EstimateGeometricTransformation[0], &lkas_B.bv[0]);

  // MATLAB Function: '<S2>/MATLAB Function1' incorporates:
  //   MATLABSystem: '<S4>/Warp'

  scale1 = 320.0;
  lkas_eml_find(&lkas_B.bv[0], lkas_B.ii_data_m, &ii_size, lkas_B.jj_data_c,
                &jj_size);
  c_size = ii_size;
  for (j = 0; j < ii_size; j++) {
    xtmp_tmp = lkas_B.ii_data_m[j];
    lkas_B.c_data[j] = (xtmp_tmp >= 456);
    lkas_B.d_data[j] = (xtmp_tmp < 480);
  }

  for (j = 0; j < jj_size; j++) {
    lkas_B.g_data[j] = (lkas_B.jj_data_c[j] >= 480);
  }

  for (j = 0; j < ii_size; j++) {
    lkas_B.b_tmp_data[j] = (lkas_B.c_data[j] && lkas_B.d_data[j]);
  }

  if (ii_size == jj_size) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    for (j = 0; j < ii_size; j++) {
      lkas_B.b_data[j] = (lkas_B.b_tmp_data[j] && lkas_B.g_data[j]);
    }
  } else {
    // MATLAB Function: '<S2>/MATLAB Function1'
    lkas_and(lkas_B.b_data, &c_size, lkas_B.b_tmp_data, &ii_size, lkas_B.g_data,
             &jj_size);
  }

  // MATLAB Function: '<S2>/MATLAB Function1'
  for (j = 0; j < jj_size; j++) {
    lkas_B.h_data[j] = (lkas_B.jj_data_c[j] < 640);
  }

  if (c_size == jj_size) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    k = c_size;
    for (j = 0; j < c_size; j++) {
      lkas_B.tmp_data_p[j] = (lkas_B.b_data[j] && lkas_B.h_data[j]);
    }
  } else {
    // MATLAB Function: '<S2>/MATLAB Function1'
    lkas_and(lkas_B.tmp_data_p, &k, lkas_B.b_data, &c_size, lkas_B.h_data,
             &jj_size);
  }

  j = k - 1;
  xtmp_tmp = 0;
  for (bestInlierNum = 0; bestInlierNum <= j; bestInlierNum++) {
    // MATLAB Function: '<S2>/MATLAB Function1'
    if (lkas_B.tmp_data_p[bestInlierNum]) {
      xtmp_tmp++;
    }
  }

  // MATLAB Function: '<S2>/MATLAB Function1'
  if (xtmp_tmp > 30) {
    bestCol = 1;
    if (c_size == jj_size) {
      k = c_size;
      for (j = 0; j < c_size; j++) {
        lkas_B.tmp_data_cv[j] = (lkas_B.b_data[j] && lkas_B.h_data[j]);
      }
    } else {
      lkas_and(lkas_B.tmp_data_cv, &k, lkas_B.b_data, &c_size, lkas_B.h_data,
               &jj_size);
    }

    j = k - 1;
    xtmp_tmp = 0;
    for (bestInlierNum = 0; bestInlierNum <= j; bestInlierNum++) {
      if (lkas_B.tmp_data_cv[bestInlierNum]) {
        xtmp_tmp++;
      }
    }

    c_size = xtmp_tmp;
    xtmp_tmp = 0;
    for (bestInlierNum = 0; bestInlierNum <= j; bestInlierNum++) {
      if (lkas_B.tmp_data_cv[bestInlierNum]) {
        lkas_B.tmp_data[xtmp_tmp] = bestInlierNum;
        xtmp_tmp++;
      }
    }

    for (j = 0; j < c_size; j++) {
      lkas_B.jj_data[j] = lkas_B.jj_data_c[lkas_B.tmp_data[j]];
    }

    scale2 = lkas_mean(lkas_B.jj_data, &c_size);
    if (ii_size == 1) {
      j = jj_size;
    } else {
      j = ii_size;
    }

    if ((ii_size == jj_size) && (j == jj_size)) {
      k = ii_size;
      for (j = 0; j < ii_size; j++) {
        lkas_B.tmp_data_f[j] = (lkas_B.c_data[j] && lkas_B.d_data[j] &&
          lkas_B.g_data[j] && lkas_B.h_data[j]);
      }
    } else {
      lkas_binary_expand_op_2(lkas_B.tmp_data_f, &k, lkas_B.c_data, &ii_size,
        lkas_B.d_data, lkas_B.g_data, &jj_size, lkas_B.h_data, &jj_size);
    }

    j = k - 1;
    xtmp_tmp = 0;
    for (bestInlierNum = 0; bestInlierNum <= j; bestInlierNum++) {
      if (lkas_B.tmp_data_f[bestInlierNum]) {
        xtmp_tmp++;
      }
    }

    c_size = xtmp_tmp;
    xtmp_tmp = 0;
    for (bestInlierNum = 0; bestInlierNum <= j; bestInlierNum++) {
      if (lkas_B.tmp_data_f[bestInlierNum]) {
        lkas_B.tmp_data_k[xtmp_tmp] = bestInlierNum;
        xtmp_tmp++;
      }
    }

    for (j = 0; j < c_size; j++) {
      lkas_B.ii_data[j] = lkas_B.ii_data_m[lkas_B.tmp_data_k[j]];
    }

    maxSum = lkas_maximum(lkas_B.ii_data, &c_size);
  } else {
    bestCol = 2;
    if (ii_size == 1) {
      j = jj_size;
    } else {
      j = ii_size;
    }

    if ((ii_size == jj_size) && (j == jj_size)) {
      k = ii_size;
      for (j = 0; j < ii_size; j++) {
        xtmp_tmp = lkas_B.jj_data_c[j];
        lkas_B.tmp_data_cv[j] = (lkas_B.b_tmp_data[j] && (xtmp_tmp >= 0) &&
          (xtmp_tmp < 160));
      }
    } else {
      lkas_binary_expand_op_3(lkas_B.tmp_data_cv, &k, lkas_B.b_tmp_data,
        &ii_size, lkas_B.jj_data_c, &jj_size);
    }

    j = k - 1;
    xtmp_tmp = 0;
    for (bestInlierNum = 0; bestInlierNum <= j; bestInlierNum++) {
      if (lkas_B.tmp_data_cv[bestInlierNum]) {
        xtmp_tmp++;
      }
    }

    c_size = xtmp_tmp;
    xtmp_tmp = 0;
    for (bestInlierNum = 0; bestInlierNum <= j; bestInlierNum++) {
      if (lkas_B.tmp_data_cv[bestInlierNum]) {
        lkas_B.tmp_data[xtmp_tmp] = bestInlierNum;
        xtmp_tmp++;
      }
    }

    for (j = 0; j < c_size; j++) {
      lkas_B.jj_data[j] = lkas_B.jj_data_c[lkas_B.tmp_data[j]];
      lkas_B.ii_data[j] = lkas_B.ii_data_m[lkas_B.tmp_data[j]];
    }

    scale2 = lkas_mean(lkas_B.jj_data, &c_size);
    maxSum = lkas_maximum(lkas_B.ii_data, &c_size);
  }

  for (bestInlierNum = 0; bestInlierNum < 20; bestInlierNum++) {
    if (bestCol == 1) {
      win_y_low = maxSum - ((static_cast<double>(bestInlierNum) + 1.0) + 1.0) *
        24.0;
      sum = maxSum - (static_cast<double>(bestInlierNum) + 1.0) * 24.0;
      for (j = 0; j < ii_size; j++) {
        lkas_B.jj_data[j] = lkas_B.ii_data_m[j];
      }

      for (j = 0; j < jj_size; j++) {
        lkas_B.ii_data[j] = lkas_B.jj_data_c[j];
      }

      if (ii_size == jj_size) {
        c_size = ii_size;
        for (j = 0; j < ii_size; j++) {
          ImageDataTypeConversion = static_cast<int32_t>(lkas_B.jj_data[j]);
          lkas_B.c_data[j] = ((ImageDataTypeConversion >= win_y_low) &&
                              (ImageDataTypeConversion < sum) &&
                              (lkas_B.ii_data[j] >= scale2 - 40.0));
        }
      } else {
        lkas_binary_expand_op_1(lkas_B.c_data, &c_size, lkas_B.jj_data, &ii_size,
          win_y_low, sum, lkas_B.ii_data, &jj_size, scale2);
      }

      for (j = 0; j < jj_size; j++) {
        lkas_B.d_data[j] = (lkas_B.ii_data[j] < scale2 + 40.0);
      }

      if (c_size == jj_size) {
        k = c_size;
        for (j = 0; j < c_size; j++) {
          lkas_B.tmp_data_g1[j] = (lkas_B.c_data[j] && lkas_B.d_data[j]);
        }
      } else {
        lkas_and(lkas_B.tmp_data_g1, &k, lkas_B.c_data, &c_size, lkas_B.d_data,
                 &jj_size);
      }

      j = k - 1;
      xtmp_tmp = 0;
      for (k = 0; k <= j; k++) {
        if (lkas_B.tmp_data_g1[k]) {
          xtmp_tmp++;
        }
      }

      if (xtmp_tmp > 30) {
        if (c_size == jj_size) {
          k = c_size;
          for (j = 0; j < c_size; j++) {
            lkas_B.tmp_data_n[j] = (lkas_B.c_data[j] && lkas_B.d_data[j]);
          }
        } else {
          lkas_and(lkas_B.tmp_data_n, &k, lkas_B.c_data, &c_size, lkas_B.d_data,
                   &jj_size);
        }

        j = k - 1;
        xtmp_tmp = 0;
        for (k = 0; k <= j; k++) {
          if (lkas_B.tmp_data_n[k]) {
            xtmp_tmp++;
          }
        }

        c_size = xtmp_tmp;
        xtmp_tmp = 0;
        for (k = 0; k <= j; k++) {
          if (lkas_B.tmp_data_n[k]) {
            lkas_B.tmp_data_b[xtmp_tmp] = k;
            xtmp_tmp++;
          }
        }

        for (j = 0; j < c_size; j++) {
          lkas_B.jj_data[j] = lkas_B.jj_data_c[lkas_B.tmp_data_b[j]];
        }

        scale2 = lkas_mean(lkas_B.jj_data, &c_size);
      }

      if ((win_y_low > 300.0) && (win_y_low < 340.0)) {
        scale1 = scale2 - 220.0;
      }
    } else {
      win_y_low = maxSum - ((static_cast<double>(bestInlierNum) + 1.0) + 1.0) *
        24.0;
      sum = maxSum - (static_cast<double>(bestInlierNum) + 1.0) * 24.0;
      if (ii_size == jj_size) {
        c_size = ii_size;
        for (j = 0; j < ii_size; j++) {
          ImageDataTypeConversion = lkas_B.ii_data_m[j];
          lkas_B.c_data[j] = ((ImageDataTypeConversion >= win_y_low) &&
                              (ImageDataTypeConversion < sum) &&
                              (lkas_B.jj_data_c[j] >= scale2 - 40.0));
        }
      } else {
        lkas_binary_expand_op(lkas_B.c_data, &c_size, lkas_B.ii_data_m, &ii_size,
                              win_y_low, sum, lkas_B.jj_data_c, &jj_size, scale2);
      }

      for (j = 0; j < jj_size; j++) {
        lkas_B.d_data[j] = (lkas_B.jj_data_c[j] < scale2 + 40.0);
      }

      if (c_size == jj_size) {
        k = c_size;
        for (j = 0; j < c_size; j++) {
          lkas_B.tmp_data_g[j] = (lkas_B.c_data[j] && lkas_B.d_data[j]);
        }
      } else {
        lkas_and(lkas_B.tmp_data_g, &k, lkas_B.c_data, &c_size, lkas_B.d_data,
                 &jj_size);
      }

      j = k - 1;
      xtmp_tmp = 0;
      for (k = 0; k <= j; k++) {
        if (lkas_B.tmp_data_g[k]) {
          xtmp_tmp++;
        }
      }

      if (xtmp_tmp > 30) {
        if (c_size == jj_size) {
          k = c_size;
          for (j = 0; j < c_size; j++) {
            lkas_B.tmp_data_m[j] = (lkas_B.c_data[j] && lkas_B.d_data[j]);
          }
        } else {
          lkas_and(lkas_B.tmp_data_m, &k, lkas_B.c_data, &c_size, lkas_B.d_data,
                   &jj_size);
        }

        j = k - 1;
        xtmp_tmp = 0;
        for (k = 0; k <= j; k++) {
          if (lkas_B.tmp_data_m[k]) {
            xtmp_tmp++;
          }
        }

        c_size = xtmp_tmp;
        xtmp_tmp = 0;
        for (k = 0; k <= j; k++) {
          if (lkas_B.tmp_data_m[k]) {
            lkas_B.tmp_data_c[xtmp_tmp] = k;
            xtmp_tmp++;
          }
        }

        for (j = 0; j < c_size; j++) {
          lkas_B.jj_data[j] = lkas_B.jj_data_c[lkas_B.tmp_data_c[j]];
        }

        scale2 = lkas_mean(lkas_B.jj_data, &c_size);
      }

      if ((win_y_low > 300.0) && (win_y_low < 340.0)) {
        scale1 = scale2 + 290.0;
      }
    }

    win_y_low = 340.0 - scale1;
  }

  // Send event
  ProvidedPort->Error.Send(win_y_low);
}

// Model initialize function
void lkas::initialize()
{
  {
    int32_t i;
    static const std::array<int8_t, 9> self_T{ { 1, 0, 0, 0, 1, 0, 0, 0, 1 } };

    // Start for S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' 
    srand(clock());

    // Start for MATLABSystem: '<Root>/V4L2 Video Capture'
    lkas_DW.obj.matlabCodegenIsDeleted = true;
    lkas_Raspiv4l2Capture_Raspiv4l2Capture(&lkas_DW.obj);
    lkas_DW.obj.Brightness = 0.5;
    lkas_DW.obj.Saturation = 0.5;
    lkas_DW.obj.Contrast = 0.5;
    lkas_DW.obj.Sharpness = 0.5;
    lkas_DW.obj.CameraPan = 0.0;
    lkas_DW.obj.CameraTilt = 0.0;
    lkas_DW.obj.CameraZoom = 0.5;
    lkas_DW.obj.ManualFocus = 0.5;
    lkas_SystemCore_setup(&lkas_DW.obj);

    // Start for MATLABSystem: '<S4>/Warp'
    lkas_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      lkas_DW.obj_c.TformProjective.T[i] = self_T[i];
    }

    // End of Start for MATLABSystem: '<S4>/Warp'
    // Initialize service provider instance - ProvidedPort
    ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::
      com::InstanceIdentifier(std::string("1")), ara::com::
      MethodCallProcessingMode::kEventSingleThread);
    ProvidedPort->OfferService();
  }
}

// Model terminate function
void lkas::terminate()
{
  // Terminate for MATLABSystem: '<Root>/V4L2 Video Capture'
  if (!lkas_DW.obj.matlabCodegenIsDeleted) {
    lkas_DW.obj.matlabCodegenIsDeleted = true;
    if ((lkas_DW.obj.isInitialized == 1) && lkas_DW.obj.isSetupComplete) {
      EXT_webcamTerminate(0, 0);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/V4L2 Video Capture'
  ProvidedPort->StopOfferService();
}

// Constructor
lkas::lkas():
  lkas_B(),
  lkas_DW()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
lkas::~lkas() = default;
