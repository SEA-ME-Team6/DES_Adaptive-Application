//
//  Rpi_cam.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "Rpi_cam".
//
//  Model version              : 1.156
//  Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
//  C++ source code generated on : Fri May 31 12:10:02 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#ifndef RTW_HEADER_Rpi_cam_h_
#define RTW_HEADER_Rpi_cam_h_
#include <stdbool.h>
#include <stdint.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "MW_availableWebcam.h"
#include "MW_v4l2_cam.h"
#include "vipsvd_rt.h"
#include "providedinterface_skeleton.h"
#include <stddef.h>
#include <array>
#include <memory>
#ifndef struct_codertarget_raspi_internal_Raspiv4l2Capture
#define struct_codertarget_raspi_internal_Raspiv4l2Capture

struct codertarget_raspi_internal_Raspiv4l2Capture
{
  bool matlabCodegenIsDeleted;
  int32_t isInitialized;
  bool isSetupComplete;
  double Brightness;
  double Saturation;
  double Contrast;
  double Sharpness;
  double CameraZoom;
  double ManualFocus;
  double CameraPan;
  double CameraTilt;
  double BrightnessInternal;
  double SaturationInternal;
  double ContrastInternal;
  double SharpnessInternal;
  double CameraZoomInternal;
  double ManualFocusInternal;
  double CameraPanInternal;
  double CameraTiltInternal;
  bool EnableManualFocusInternal;
};

#endif                    // struct_codertarget_raspi_internal_Raspiv4l2Capture

#ifndef struct_c_projective2d
#define struct_c_projective2d

struct c_projective2d
{
  std::array<double, 9> T;
};

#endif                                 // struct_c_projective2d

#ifndef struct_vision_internal_blocks_Warp
#define struct_vision_internal_blocks_Warp

struct vision_internal_blocks_Warp
{
  int32_t isInitialized;
  c_projective2d TformProjective;
};

#endif                                 // struct_vision_internal_blocks_Warp

// Class declaration for model Rpi_cam
class Rpi_cam final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    codertarget_raspi_internal_Raspiv4l2Capture obj;// '<Root>/V4L2 Video Capture' 
    vision_internal_blocks_Warp obj_k; // '<S4>/Warp'
    std::array<double, 921600> ColorSpaceConversion;// '<S4>/Color Space  Conversion' 
    std::array<double, 921600> ColorSpaceConversion_DWORK1;// '<S4>/Color Space  Conversion' 
    std::array<double, 307200> V_Channel;// '<S4>/MATLAB Function7'
    double c_tmp_data[307200];
    double jj_data[307200];
    std::array<double, 921600> ImageDataTypeConversion;
    std::array<double, 307200> srcXIntrinsic;
    std::array<double, 307200> srcYIntrinsic;
    std::array<double, 81> RV;
    std::array<double, 72> EstimateGeometricTransformation_DW_CONSTRT_ALL;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<double, 72> Constraint;
    std::array<double, 72> Q;
    std::array<double, 9> EstimateGeometricTransformation;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<double, 9> bestTFormCompact;
    std::array<double, 9> tformCompact;
    std::array<double, 9> tformCompact_m;
    std::array<double, 9> tinv;
    std::array<double, 9> x;
    std::array<double, 8> pts1;        // '<S4>/MATLAB Function1'
    std::array<double, 8> pts2;        // '<S4>/MATLAB Function2'
    std::array<double, 8> EstimateGeometricTransformation_DW_PTSNORM1;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<double, 8> EstimateGeometricTransformation_DW_PTSNORM2;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<double, 8> E;
    std::array<double, 8> Qraux;
    std::array<double, 8> Work;
    std::array<double, 4> EstimateGeometricTransformation_DW_DISTANCE;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<double, 2> cents1;
    std::array<double, 2> cents2;
    double x_location;
    double win_y_low;
    double win_y_high;
    double x_current;
    double bestInlierDis;
    double s1DivS2;
    double ImageDataTypeConversion_c;
    double ImageDataTypeConversion_k;
    double ImageDataTypeConversion_cx;
    double absx11;
    double absx21;
    double absx31;
    double tinv_b;
    double tinv_p;
    double tinv_c;
    double tinv_f;
    double tinv_g;
    double tinv_g1;
    double tinv_m;
    double t;
    double nrmxl;
    double maxnrm;
    double tt;
    double tmpQRSL;
    double d;
    double d1;
    int32_t ii_data[307200];
    int32_t jj_data_n[307200];
    int32_t tmp_data[307200];
    int32_t tmp_data_p[307200];
    int32_t tmp_data_l[307200];
    int32_t tmp_data_j[307200];
    std::array<int32_t, 8> JPVT;
    int32_t j;
    int32_t inlierNum;
    int32_t i;
    int32_t svdRsltVar;
    int32_t outputImage_tmp;
    int32_t b_size;
    int32_t ii_size;
    int32_t jj_size;
    int32_t c_size;
    int32_t d_size;
    int32_t g_size;
    int32_t h_size;
    int32_t b_tmp_size;
    int32_t c_tmp_size;
    int32_t tmp_size;
    int32_t tmp_size_d;
    int32_t tmp_size_g;
    int32_t tmp_size_l;
    int32_t tmp_size_dh;
    int32_t tmp_size_dy;
    int32_t tmp_size_lx;
    int32_t jj_size_o;
    int32_t tmp_size_idx_0;
    int32_t j_b;
    int32_t L;
    std::array<uint32_t, 4> EstimateGeometricTransformation_DW_SAMPLEIDX;
                                    // '<S4>/Estimate Geometric Transformation'
    uint32_t bestCol;
    uint32_t s1DivS2_tmp;
    std::array<char, 18> i_n;
    std::array<int8_t, 307200> inputImage;
    std::array<int8_t, 4> EstimateGeometricTransformation_DW_BEST_SAMPLE;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<uint8_t, 921600> outputImage;// '<Root>/MATLAB Function'
    std::array<uint8_t, 307200> b_varargout_3;
    std::array<uint8_t, 307200> b_varargout_2;
    std::array<uint8_t, 307200> b_varargout_1;
    std::array<uint8_t, 307200> b_varargout_1_b;
    std::array<bool, 307200> bv;
    bool b_data[307200];
    bool c_data[307200];
    bool d_data[307200];
    bool g_data[307200];
    bool h_data[307200];
    bool b_tmp_data[307200];
    bool tmp_data_ln[307200];
    bool tmp_data_h[307200];
    bool tmp_data_b[307200];
    bool tmp_data_d[307200];
    bool tmp_data_e[307200];
    bool tmp_data_bj[307200];
    bool tmp_data_jz[307200];
    std::array<bool, 307200> rtb_V_Channel_f;
  };

  // Copy Constructor
  Rpi_cam(Rpi_cam const&) = delete;

  // Assignment Operator
  Rpi_cam& operator= (Rpi_cam const&) & = delete;

  // Move Constructor
  Rpi_cam(Rpi_cam &&) = delete;

  // Move Assignment Operator
  Rpi_cam& operator= (Rpi_cam &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Rpi_cam();

  // Destructor
  ~Rpi_cam();

  // private data and function members
 private:
  // Block states
  DW rtDW;
  std::shared_ptr<skeleton::ProvidedInterfaceSkeleton> ProvidedPort;

  // private member function(s) for subsystem '<Root>'
  void v4l2Capture_updateV4L2Settings
    (codertarget_raspi_internal_Raspiv4l2Capture *obj, bool forceUpdate);
  void SystemCore_step(codertarget_raspi_internal_Raspiv4l2Capture *obj, uint8_t
                       varargout_1[307200], uint8_t varargout_2[307200], uint8_t
                       varargout_3[307200]);
  void QRV2Norm_double_o(const double V[], int32_t N, double v2norm[]);
  void QRDC_double_o(double xVec[], double qrAux[], int32_t jpvt[], double work[],
                     int32_t M, int32_t N);
  void QRE_double_o(double outQ[], double outR[], double outE[], double qrAux[],
                    double work[], int32_t jpvt[], double sPtr[], int32_t M,
                    int32_t N, bool economy);
  void Warp_stepImpl(vision_internal_blocks_Warp *b_this, const bool Image
                     [307200], const double input2[9], bool Jout[307200]);
  void eml_find(const bool x[307200], int32_t i_data[], int32_t *i_size, int32_t
                j_data[], int32_t *j_size);
  void and_o(bool in1_data[], int32_t *in1_size, const bool in2_data[], const
             int32_t *in2_size, const bool in3_data[], const int32_t *in3_size);
  void binary_expand_op_3(bool in1_data[], int32_t *in1_size, const bool
    in2_data[], const int32_t *in2_size, const int32_t in3_data[], const int32_t
    *in3_size);
  double mean(const double x_data[], const int32_t *x_size);
  double maximum(const double x_data[], const int32_t *x_size);
  void binary_expand_op_2(bool in1_data[], int32_t *in1_size, const bool
    in2_data[], const int32_t *in2_size, const bool in3_data[], const bool
    in4_data[], const int32_t *in4_size, const bool in5_data[], const int32_t
    *in5_size);
  void binary_expand_op(bool in1_data[], int32_t *in1_size, const int32_t
                        in2_data[], const int32_t *in2_size, double in3, double
                        in4, const int32_t in5_data[], const int32_t *in5_size,
                        double in6);
  void binary_expand_op_1(bool in1_data[], int32_t *in1_size, const double
    in2_data[], const int32_t *in2_size, double in3, double in4, const double
    in5_data[], const int32_t *in5_size, double in6);
  codertarget_raspi_internal_Raspiv4l2Capture *Raspiv4l2Capture_Raspiv4l2Capture
    (codertarget_raspi_internal_Raspiv4l2Capture *obj);
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'Rpi_cam'
//  '<S1>'   : 'Rpi_cam/MATLAB Function'
//  '<S2>'   : 'Rpi_cam/Perception Unit'
//  '<S3>'   : 'Rpi_cam/RGB to Image'
//  '<S4>'   : 'Rpi_cam/Perception Unit/Image Processing'
//  '<S5>'   : 'Rpi_cam/Perception Unit/MATLAB Function1'
//  '<S6>'   : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function1'
//  '<S7>'   : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function2'
//  '<S8>'   : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function7'
//  '<S9>'   : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function8'

#endif                                 // RTW_HEADER_Rpi_cam_h_
