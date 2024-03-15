//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Rpi_cam.h
//
// Code generated for Simulink model 'Rpi_cam'.
//
// Model version                  : 1.104
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Mar 15 11:10:11 2024
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
#include "MW_SDL2_video_display.h"
#include "MW_availableWebcam.h"
#include "MW_v4l2_cam.h"
#include "vipsvd_rt.h"
#include "Rpi_cam_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

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
  real_T left_lane_index[200000];
  real_T right_lane_index[200000];
  int8_T inputImage[307200];
  boolean_T bv[307200];
  boolean_T V_Channel_m[307200];
  uint8_T R[307200];                   // '<S2>/ImageToRGB'
  uint8_T G[307200];                   // '<S2>/ImageToRGB'
  uint8_T B_n[307200];                 // '<S2>/ImageToRGB'
  uint8_T outputImage[921600];         // '<Root>/MATLAB Function'
  uint8_T b_varargout_3[307200];
  uint8_T b_varargout_2[307200];
  uint8_T b_varargout_1[307200];
  uint8_T b_varargout_1_c[307200];
  real_T xleft[481];
  real_T xright[481];
  real_T RV[81];
  real_T Constraint[72];
  real_T Q[72];
  real_T EstimateGeometricTransformation[9];
                                    // '<S4>/Estimate Geometric Transformation'
  real_T bestTFormCompact[9];
  real_T tformCompact[9];
  real_T tformCompact_k[9];
  real_T tinv[9];
  real_T x[9];
  real_T E[8];
  real_T Qraux[8];
  real_T Work[8];
  real_T pts2[8];
  real_T pts1[8];
  int32_T JPVT[8];
  real_T p[3];
  real_T b_p[3];
  real_T tau_data[3];
  real_T work[3];
  real_T vn1[3];
  real_T vn2[3];
  char_T i[18];
  real_T cents1[2];
  real_T cents2[2];
  char_T j[12];
  int32_T jpvt[3];
  char_T b[11];
  char_T e[10];
  char_T c[9];
  real_T error;                        // '<S2>/MATLAB Function1'
  real_T min;
  real_T s;
  real_T win_y_low;
  real_T win_y_high;
  real_T scale1;
  real_T scale2;
  real_T maxSum;
  real_T sum;
  real_T x_c;
  real_T tol;
  real_T temp2;
  real_T smax;
  real_T s_b;
  real_T c_p;
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
  real_T d;
  real_T ts;
  real_T scale;
  real_T absxk;
  real_T t_p;
  real_T temp;
  real_T a;
  real_T b_l;
  real_T t_j;
  real_T temp_d;
  real32_T qx1;
  real32_T qx2;
  int32_T j_g;
  int32_T line_flag;
  int32_T d_j;
  int32_T bestInlierNum;
  int32_T bestCol;
  int32_T k;
  int32_T partialTrueCount;
  int32_T i_l;
  int32_T b_d;
  int32_T k_d;
  int32_T minmn;
  int32_T maxmn;
  int32_T k_l;
  int32_T b_j;
  int32_T c_i;
  int32_T tau_size;
  int32_T b_A;
  int32_T loop_ub;
  int32_T i_o;
  int32_T ma;
  int32_T ii;
  int32_T mmi;
  int32_T pvt;
  int32_T itemp;
  int32_T b_b;
  int32_T i_n;
  int32_T idxmax;
  int32_T knt;
  int32_T lastv;
  int32_T lastc;
  int32_T iy;
  int32_T d_b;
  int32_T e_l;
  int32_T coltop;
  int32_T jA;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  int32_T j_h;
  int32_T L;
  int32_T pq;
  int32_T ps;
  int32_T j_b;
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
  int32_T i_e;
  int32_T i1;
  int32_T kend;
  int32_T k_b;
  int32_T k_j;
  int32_T temp_tmp;
  int32_T i2;
  int32_T newNumel;
  int32_T i_f;
  int32_T j_a;
  int32_T i_j;
  int32_T pqraux_tmp;
  int32_T nmj;
  int32_T i_jz;
  int32_T pjj;
  int32_T pqr;
  int32_T py;
  int32_T i_o4;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T loop_ub_n;
  int32_T in1_tmp;
  int32_T i3;
  int32_T newNumel_i;
  int32_T i_oy;
  uint32_T idx;
  int8_T i4;
  int8_T i5;
  uint8_T xtmp;
  uint8_T status;
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
  codertarget_linux_blocks_SDL2VideoDisplay obj_a;// '<S7>/MATLAB System'
  int8_T EstimateGeometricTransformation_DW_BEST_SAMPLE[4];
                                    // '<S4>/Estimate Geometric Transformation'
  uint8_T is_active_c10_Rpi_cam;       // '<S2>/MATLAB Function1'
  uint8_T is_active_c11_Rpi_cam;       // '<S2>/ImageToRGB'
  uint8_T is_active_c6_Rpi_cam;        // '<S4>/MATLAB Function8'
  uint8_T is_active_c5_Rpi_cam;        // '<S4>/MATLAB Function7'
  uint8_T is_active_c3_Rpi_cam;        // '<S4>/MATLAB Function2'
  uint8_T is_active_c1_Rpi_cam;        // '<S4>/MATLAB Function1'
  uint8_T is_active_c9_Rpi_cam;        // '<Root>/MATLAB Function'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY {
  real_T Out1;                         // '<Root>/Out1'
};

// Parameters (default storage)
struct P_ {
  real_T EstimateGeometricTransformation_distanceAlg;
                  // Mask Parameter: EstimateGeometricTransformation_distanceAlg
                     //  Referenced by: '<S4>/Estimate Geometric Transformation'

  uint32_T EstimateGeometricTransformation_sampleNum;
                    // Mask Parameter: EstimateGeometricTransformation_sampleNum
                       //  Referenced by: '<S4>/Estimate Geometric Transformation'

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

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY rtY;

#ifdef __cplusplus

}

#endif

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
//  '<S5>'   : 'Rpi_cam/Perception Unit/ImageToRGB'
//  '<S6>'   : 'Rpi_cam/Perception Unit/MATLAB Function1'
//  '<S7>'   : 'Rpi_cam/Perception Unit/SDL Video Display'
//  '<S8>'   : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function1'
//  '<S9>'   : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function2'
//  '<S10>'  : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function7'
//  '<S11>'  : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function8'

#endif                                 // RTW_HEADER_Rpi_cam_h_

//
// File trailer for generated code.
//
// [EOF]
//
