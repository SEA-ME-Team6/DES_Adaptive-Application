//
//  Rpi_cam.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "Rpi_cam".
//
//  Model version              : 2.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Mon Jun  3 22:43:01 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#ifndef Rpi_cam_h_
#define Rpi_cam_h_
#include <stdbool.h>
#include <stdint.h>
#include <cmath>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "MW_availableWebcam.h"
#include "MW_v4l2_cam.h"
#include "vipsvd_rt.h"
#include "MW_TCPSendReceive.h"
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

#ifndef struct_codertarget_raspi_internal_RaspiTCPReceive
#define struct_codertarget_raspi_internal_RaspiTCPReceive

struct codertarget_raspi_internal_RaspiTCPReceive
{
  int32_t isInitialized;
  uint16_t connStream_;
  double isServer_;
};

#endif                     // struct_codertarget_raspi_internal_RaspiTCPReceive

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
    codertarget_raspi_internal_Raspiv4l2Capture obj;// '<S1>/V4L2 Video Capture' 
    vision_internal_blocks_Warp obj_k; // '<S5>/Warp'
    codertarget_raspi_internal_RaspiTCPReceive obj_e;// '<Root>/TCP//IP Receive' 
    std::array<double, 921600> ColorSpaceConversion;// '<S5>/Color Space  Conversion' 
    std::array<double, 921600> ColorSpaceConversion_DWORK1;// '<S5>/Color Space  Conversion' 
    std::array<double, 307200> V_Channel;// '<S5>/MATLAB Function7'
    std::array<double, 921600> ImageDataTypeConversion;
    std::array<double, 307200> srcXIntrinsic;
    std::array<double, 307200> srcYIntrinsic;
    std::array<double, 81> RV;
    std::array<double, 72> EstimateGeometricTransformation_DW_CONSTRT_ALL;
                                    // '<S5>/Estimate Geometric Transformation'
    std::array<double, 72> Constraint;
    std::array<double, 72> Q;
    std::array<double, 9> EstimateGeometricTransformation;
                                    // '<S5>/Estimate Geometric Transformation'
    std::array<double, 9> bestTFormCompact;
    std::array<double, 9> tformCompact;
    std::array<double, 9> tformCompact_m;
    std::array<double, 9> tinv;
    std::array<double, 9> x;
    std::array<double, 8> pts1;        // '<S5>/MATLAB Function1'
    std::array<double, 8> pts2;        // '<S5>/MATLAB Function2'
    std::array<double, 8> EstimateGeometricTransformation_DW_PTSNORM1;
                                    // '<S5>/Estimate Geometric Transformation'
    std::array<double, 8> EstimateGeometricTransformation_DW_PTSNORM2;
                                    // '<S5>/Estimate Geometric Transformation'
    std::array<double, 8> E;
    std::array<double, 8> Qraux;
    std::array<double, 8> Work;
    std::array<double, 4> EstimateGeometricTransformation_DW_DISTANCE;
                                    // '<S5>/Estimate Geometric Transformation'
    std::array<double, 2> cents1;
    std::array<double, 2> cents2;
    double bestInlierDis;
    double scale1;
    double scale2;
    double maxSum;
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
    std::array<int32_t, 8> JPVT;
    int32_t bestInlierNum;
    int32_t inlierNum;
    int32_t svdRsltVar;
    int32_t xtmp_tmp;
    int32_t outputImage_tmp;
    int32_t j;
    int32_t L;
    int32_t ps;
    std::array<uint32_t, 4> EstimateGeometricTransformation_DW_SAMPLEIDX;
                                    // '<S5>/Estimate Geometric Transformation'
    uint32_t bestCol;
    uint32_t s1DivS2_tmp;
    std::array<char, 101> b_errorMessage;
    std::array<char, 18> i;
    std::array<char, 12> devName;
    std::array<int8_t, 307200> inputImage;
    std::array<int8_t, 4> EstimateGeometricTransformation_DW_BEST_SAMPLE;
                                    // '<S5>/Estimate Geometric Transformation'
    std::array<uint8_t, 921600> outputImage;// '<S1>/MATLAB Function'
    std::array<uint8_t, 307200> uv;
    std::array<uint8_t, 307200> uv1;
    std::array<uint8_t, 307200> uv2;
    std::array<uint8_t, 307200> uv3;
    std::array<bool, 307200> rtb_V_Channel_n;
    bool unusedExpr[307200];
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
  codertarget_raspi_internal_Raspiv4l2Capture *Raspiv4l2Capture_Raspiv4l2Capture
    (codertarget_raspi_internal_Raspiv4l2Capture *obj);
  void SystemCore_setup(codertarget_raspi_internal_Raspiv4l2Capture *obj);
  void SystemCore_setup_o(codertarget_raspi_internal_RaspiTCPReceive *obj);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination


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
//  '<S1>'   : 'Rpi_cam/Enabled Subsystem'
//  '<S2>'   : 'Rpi_cam/Enabled Subsystem/MATLAB Function'
//  '<S3>'   : 'Rpi_cam/Enabled Subsystem/Perception Unit'
//  '<S4>'   : 'Rpi_cam/Enabled Subsystem/RGB to Image'
//  '<S5>'   : 'Rpi_cam/Enabled Subsystem/Perception Unit/Image Processing'
//  '<S6>'   : 'Rpi_cam/Enabled Subsystem/Perception Unit/MATLAB Function1'
//  '<S7>'   : 'Rpi_cam/Enabled Subsystem/Perception Unit/Image Processing/MATLAB Function1'
//  '<S8>'   : 'Rpi_cam/Enabled Subsystem/Perception Unit/Image Processing/MATLAB Function2'
//  '<S9>'   : 'Rpi_cam/Enabled Subsystem/Perception Unit/Image Processing/MATLAB Function7'
//  '<S10>'  : 'Rpi_cam/Enabled Subsystem/Perception Unit/Image Processing/MATLAB Function8'

#endif                                 // Rpi_cam_h_
