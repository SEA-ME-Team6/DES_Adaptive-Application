//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Rpi_cam.h
//
// Code generated for Simulink model 'Rpi_cam'.
//
// Model version                  : 1.153
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Apr  9 15:11:19 2024
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
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_TCPSendReceive.h"
#include "MW_availableWebcam.h"
#include "MW_v4l2_cam.h"
#include "vipsvd_rt.h"
#include "Rpi_cam_types.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#define Rpi_cam_M                      (rtM)

// Block signals (default storage)
struct B {
  real_T ColorSpaceConversion[921600]; // '<S4>/Color Space  Conversion'
  real_T ImageDataTypeConversion[921600];
  real_T V_Channel[307200];
  real_T srcXIntrinsic[307200];
  real_T srcYIntrinsic[307200];
  int8_T inputImage[307200];
  boolean_T DrawShapes1[307200];       // '<S2>/Draw Shapes1'
  boolean_T V_Channel_m[307200];
  uint8_T b_varargout_3[307200];
  uint8_T b_varargout_2[307200];
  uint8_T b_varargout_1_k[307200];
  uint8_T b_varargout_1[307200];
  real_T rectangle_points[168];
  int32_T DataTypeConversion3[168];    // '<S2>/Data Type Conversion3'
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
  real_T E[8];
  real_T Qraux[8];
  real_T Work[8];
  real_T pts1[8];
  real_T pts2[8];
  int32_T JPVT[8];
  char_T i[18];
  real_T cents1[2];
  real_T cents2[2];
  char_T j[12];
  char_T b[11];
  char_T e[10];
  char_T c[9];
  uint8_T b_x[8];
  real_T error;                        // '<S2>/MATLAB Function1'
  real_T x_location;                   // '<S2>/MATLAB Function1'
  uint8_T outputImage[921600];         // '<Root>/MATLAB Function'
  real_T min;
  real_T s;
  real_T win_y_low;
  real_T scale1;
  real_T scale2;
  real_T maxSum;
  real_T sum;
  real_T ImageDataTypeConversion_c;
  real_T ImageDataTypeConversion_b;
  real_T srczWorld_val;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  real_T tinv_p;
  real_T tinv_c;
  real_T tinv_f;
  real_T tinv_g;
  real_T tinv_g1;
  real_T tinv_m;
  real_T t;
  real_T nrmxl;
  real_T maxnrm;
  real_T tt;
  real_T tmpQRSL;
  real_T val;
  real_T d;
  real_T ts;
  real_T t_n;
  real_T temp;
  real_T b_y;
  real_T bsum;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T x_p;
  real_T sumDis;
  real32_T qx1;
  real32_T qx2;
  int32_T lastRow;
  int32_T lastCol;
  int32_T halfLineWidth;
  int32_T dc;
  int32_T OutCode1;
  int32_T OutCode2;
  int32_T bestInlierNum;
  int32_T bestCol;
  int32_T k;
  int32_T line_idx_3;
  int32_T line_idx_2;
  int32_T line_idx_1;
  int32_T rtb_DataTypeConversion1_idx_0;
  int32_T xtmp_tmp;
  int32_T line_idx_0_tmp;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  int32_T j_l;
  int32_T L;
  int32_T pq;
  int32_T ps;
  int32_T j_j;
  int32_T i_d;
  int32_T l;
  int32_T maxj;
  int32_T pl;
  int32_T pu;
  int32_T mml;
  int32_T px;
  int32_T px2;
  int32_T plj;
  int32_T minVal;
  int32_T vi;
  int32_T i_g;
  int32_T i_l;
  int32_T j_d;
  int32_T i_dy;
  int32_T pqraux_tmp;
  int32_T nmj;
  int32_T i_lx;
  int32_T pjj;
  int32_T pqr;
  int32_T py;
  int32_T firstBlockLength;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T xblockoffset;
  int32_T hi;
  int32_T b_k;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T loop_ub;
  int32_T i1;
  int32_T newNumel;
  int32_T i_o;
  int32_T stride_0_0_b;
  int32_T stride_1_0_n;
  int32_T loop_ub_b;
  int32_T i2;
  int32_T stride_0_0_l;
  int32_T stride_1_0_h;
  int32_T stride_2_0;
  int32_T loop_ub_bn;
  int32_T i3;
  int32_T i4;
  int32_T stride_0_0_d;
  int32_T stride_1_0_tmp;
  int32_T loop_ub_e;
  int32_T i5;
  int32_T i6;
  int32_T idx;
  int32_T ii;
  int32_T jj;
  int32_T newNumel_b;
  int32_T i_j;
  int32_T stride_0_0_f;
  int32_T stride_1_0_a;
  int32_T loop_ub_j;
  int32_T i7;
  int32_T newNumel_j;
  int32_T i_o4;
  int32_T last;
  int32_T k_n;
  int32_T i_i;
  int32_T i_oy;
  int32_T i_n;
  uint32_T idx_m;
  uint32_T i_c;
  uint32_T j_m;
  uint32_T k_m;
  uint32_T u;
  uint32_T i_ja;
  uint32_T j_h;
  int16_T errorNo;
  uint16_T u1;
  int8_T i8;
  int8_T i9;
  uint8_T xtmp;
  uint8_T status;
  boolean_T visited1;
  boolean_T visited2;
  boolean_T done;
  boolean_T DrawShapes1_DW_FillColorAdd;
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
  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<Root>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_k;                     // '<S2>/Scope'

  uint8_T is_active_c10_Rpi_cam;       // '<S2>/MATLAB Function1'
  uint8_T is_active_c6_Rpi_cam;        // '<S4>/MATLAB Function8'
  uint8_T is_active_c5_Rpi_cam;        // '<S4>/MATLAB Function7'
  uint8_T is_active_c3_Rpi_cam;        // '<S4>/MATLAB Function2'
  uint8_T is_active_c1_Rpi_cam;        // '<S4>/MATLAB Function1'
  uint8_T is_active_c9_Rpi_cam;        // '<Root>/MATLAB Function'
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
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
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
