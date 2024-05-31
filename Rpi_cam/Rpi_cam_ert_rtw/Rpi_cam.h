//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Rpi_cam.h
//
// Code generated for Simulink model 'Rpi_cam'.
//
// Model version                  : 1.154
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Apr 18 13:37:00 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Rpi_cam_h_
#define RTW_HEADER_Rpi_cam_h_
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "rtwtypes.h"
#include "MW_TCPSendReceive.h"
#include "MW_availableWebcam.h"
#include "MW_v4l2_cam.h"
#include "vipsvd_rt.h"
#include "Rpi_cam_types.h"
#include "coder_array.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define Rpi_cam_M                      (rtM)

// Block signals (default storage)
struct B {
  coder::array<int32_T,1> ii;
  coder::array<int32_T,1> jj;
  coder::array<int32_T,1> r;
  coder::array<int32_T,1> r8;
  coder::array<int32_T,1> r9;
  coder::array<int32_T,1> r10;
  coder::array<boolean_T,1> b;
  coder::array<boolean_T,1> c;
  coder::array<boolean_T,1> d;
  coder::array<boolean_T,1> g;
  coder::array<boolean_T,1> h;
  coder::array<boolean_T,1> b_tmp;
  coder::array<boolean_T,1> r1;
  coder::array<boolean_T,1> r2;
  coder::array<boolean_T,1> r3;
  coder::array<boolean_T,1> r4;
  coder::array<boolean_T,1> r5;
  coder::array<boolean_T,1> r6;
  coder::array<boolean_T,1> r7;
  coder::array<real_T,1> c_tmp;
  coder::array<real_T,1> jj_m;
  real_T ColorSpaceConversion[921600]; // '<S4>/Color Space  Conversion'
  real_T ImageDataTypeConversion[921600];
  real_T V_Channel[307200];            // '<S4>/MATLAB Function7'
  real_T srcXIntrinsic[307200];
  real_T srcYIntrinsic[307200];
  uint8_T outputImage[921600];         // '<Root>/MATLAB Function'
  int8_T inputImage[307200];
  boolean_T bv[307200];
  boolean_T rtb_V_Channel_c[307200];
  uint8_T b_varargout_3[307200];
  uint8_T b_varargout_2[307200];
  uint8_T b_varargout_1[307200];
  uint8_T b_varargout_1_k[307200];
  real_T RV[81];
  real_T Constraint[72];
  real_T Q[72];
  real_T EstimateGeometricTransformation[9];
                                    // '<S4>/Estimate Geometric Transformation'
  real_T bestTFormCompact[9];
  real_T tformCompact[9];
  real_T tformCompact_c[9];
  real_T tinv[9];
  real_T x[9];
  real_T pts1[8];                      // '<S4>/MATLAB Function1'
  real_T pts2[8];                      // '<S4>/MATLAB Function2'
  real_T E[8];
  real_T Qraux[8];
  real_T Work[8];
  int32_T JPVT[8];
  char_T i[18];
  real_T cents1[2];
  real_T cents2[2];
  uint8_T b_x[8];
  real_T min;
  real_T s;
  real_T win_y_low;
  real_T scale1;
  real_T scale2;
  real_T maxSum;
  real_T sum;
  real_T ImageDataTypeConversion_b;
  real_T ImageDataTypeConversion_p;
  real_T srczWorld_val;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  real_T tinv_c;
  real_T tinv_f;
  real_T tinv_g;
  real_T tinv_g1;
  real_T tinv_m;
  real_T tinv_n;
  real_T t;
  real_T nrmxl;
  real_T maxnrm;
  real_T tt;
  real_T tmpQRSL;
  real_T val;
  real_T d_p;
  int32_T j;
  int32_T bestInlierNum;
  int32_T bestCol;
  int32_T k;
  int32_T xtmp_tmp;
  int32_T j_l;
  int32_T L;
  int32_T pq;
  uint32_T idx;
};

// Block states (default storage) for system '<Root>'
struct DW {
  real_T ColorSpaceConversion_DWORK1[921600];// '<S4>/Color Space  Conversion'
  real_T EstimateGeometricTransformation_DW_CONSTRT_ALL[72];
                                    // '<S4>/Estimate Geometric Transformation'
  codertarget_raspi_internal_Raspiv4l2Capture obj;// '<Root>/V4L2 Video Capture' 
  vision_internal_blocks_Warp obj_k;   // '<S4>/Warp'
  real_T EstimateGeometricTransformation_DW_PTSNORM1[8];
                                    // '<S4>/Estimate Geometric Transformation'
  real_T EstimateGeometricTransformation_DW_PTSNORM2[8];
                                    // '<S4>/Estimate Geometric Transformation'
  real_T EstimateGeometricTransformation_DW_DISTANCE[4];
                                    // '<S4>/Estimate Geometric Transformation'
  uint32_T EstimateGeometricTransformation_DW_SAMPLEIDX[4];
                                    // '<S4>/Estimate Geometric Transformation'
  codertarget_raspi_internal_RaspiTCPSend obj_d;// '<Root>/TCP//IP Send1'
  int8_T EstimateGeometricTransformation_DW_BEST_SAMPLE[4];
                                    // '<S4>/Estimate Geometric Transformation'
};

// Parameters (default storage)
struct P_ {
  real_T EstimateGeometricTransformation_distanceAlg;
                  // Mask Parameter: EstimateGeometricTransformation_distanceAlg
                     //  Referenced by: '<S4>/Estimate Geometric Transformation'

  int32_T DrawShapes2_lineWidth;       // Mask Parameter: DrawShapes2_lineWidth
                                          //  Referenced by: '<S2>/Draw Shapes2'

  uint32_T EstimateGeometricTransformation_sampleNum;
                    // Mask Parameter: EstimateGeometricTransformation_sampleNum
                       //  Referenced by: '<S4>/Estimate Geometric Transformation'

  int16_T DrawShapes3_opacity;         // Mask Parameter: DrawShapes3_opacity
                                          //  Referenced by: '<S2>/Draw Shapes3'

  int16_T DrawShapes1_opacity;         // Mask Parameter: DrawShapes1_opacity
                                          //  Referenced by: '<S2>/Draw Shapes1'

  real_T V4L2VideoCapture_Brightness;  // Expression: 0.5
                                          //  Referenced by: '<Root>/V4L2 Video Capture'

  real_T V4L2VideoCapture_Saturation;  // Expression: 0.5
                                          //  Referenced by: '<Root>/V4L2 Video Capture'

  real_T V4L2VideoCapture_Contrast;    // Expression: 0.5
                                          //  Referenced by: '<Root>/V4L2 Video Capture'

  real_T V4L2VideoCapture_Sharpness;   // Expression: 0.5
                                          //  Referenced by: '<Root>/V4L2 Video Capture'

  real_T V4L2VideoCapture_CameraPan;   // Expression: 0
                                          //  Referenced by: '<Root>/V4L2 Video Capture'

  real_T V4L2VideoCapture_CameraTilt;  // Expression: 0
                                          //  Referenced by: '<Root>/V4L2 Video Capture'

  real_T V4L2VideoCapture_CameraZoom;  // Expression: 0.5
                                          //  Referenced by: '<Root>/V4L2 Video Capture'

  real_T V4L2VideoCapture_ManualFocus; // Expression: 0.5
                                          //  Referenced by: '<Root>/V4L2 Video Capture'

};

// Real-time Model Data Structure
struct tag_RTM {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P rtP;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B rtB;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW rtDW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void Rpi_cam_initialize(void);
  extern void Rpi_cam_step(void);
  extern void Rpi_cam_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL *const rtM;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Scope' : Unused code path elimination
//  Block '<Root>/Scope' : Unused code path elimination


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

//
// File trailer for generated code.
//
// [EOF]
//
