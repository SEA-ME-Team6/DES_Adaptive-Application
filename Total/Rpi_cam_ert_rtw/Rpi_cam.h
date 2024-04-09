/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Rpi_cam.h
 *
 * Code generated for Simulink model 'Rpi_cam'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Mar  4 15:22:01 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Rpi_cam_h_
#define RTW_HEADER_Rpi_cam_h_
#ifndef Rpi_cam_COMMON_INCLUDES_
#define Rpi_cam_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_availableWebcam.h"
#include "MW_v4l2_cam.h"
#endif                                 /* Rpi_cam_COMMON_INCLUDES_ */

#include "Rpi_cam_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
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

/* Block signals (default storage) */
typedef struct {
  real_T ColorSpaceConversion[921600]; /* '<S1>/Color Space  Conversion' */
  real_T ImageDataTypeConversion[921600];
  uint8_T converttoimage[921600];      /* '<S2>/convert to image' */
  boolean_T BW[307200];                /* '<S1>/MATLAB Function6' */
  uint8_T b_varargout_3[307200];
  uint8_T b_varargout_2[307200];
  uint8_T b_varargout_1[307200];
  uint8_T b_varargout_1_m[307200];
  char_T b_errorMessage[101];
  char_T i[18];
  char_T devName[12];
  char_T j[12];
  char_T b[11];
  char_T e[10];
  char_T c[9];
  real_T min;
} B_Rpi_cam_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_Ra_T obj; /* '<Root>/V4L2 Video Capture' */
  real_T ColorSpaceConversion_DWORK1[921600];/* '<S1>/Color Space  Conversion' */
  uint8_T is_active_c7_Rpi_cam;        /* '<S1>/MATLAB Function6' */
  uint8_T is_active_c8_Rpi_cam;        /* '<S1>/MATLAB Function4' */
} DW_Rpi_cam_T;

/* Parameters (default storage) */
struct P_Rpi_cam_T_ {
  real_T V4L2VideoCapture_Brightness;  /* Expression: 0.5
                                        * Referenced by: '<Root>/V4L2 Video Capture'
                                        */
  real_T V4L2VideoCapture_Saturation;  /* Expression: 0.5
                                        * Referenced by: '<Root>/V4L2 Video Capture'
                                        */
  real_T V4L2VideoCapture_Contrast;    /* Expression: 0.5
                                        * Referenced by: '<Root>/V4L2 Video Capture'
                                        */
  real_T V4L2VideoCapture_Sharpness;   /* Expression: 0.5
                                        * Referenced by: '<Root>/V4L2 Video Capture'
                                        */
  real_T V4L2VideoCapture_CameraPan;   /* Expression: 0
                                        * Referenced by: '<Root>/V4L2 Video Capture'
                                        */
  real_T V4L2VideoCapture_CameraTilt;  /* Expression: 0
                                        * Referenced by: '<Root>/V4L2 Video Capture'
                                        */
  real_T V4L2VideoCapture_CameraZoom;  /* Expression: 0.5
                                        * Referenced by: '<Root>/V4L2 Video Capture'
                                        */
  real_T V4L2VideoCapture_ManualFocus; /* Expression: 0.5
                                        * Referenced by: '<Root>/V4L2 Video Capture'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Rpi_cam_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Rpi_cam_T Rpi_cam_P;

/* Block signals (default storage) */
extern B_Rpi_cam_T Rpi_cam_B;

/* Block states (default storage) */
extern DW_Rpi_cam_T Rpi_cam_DW;

/* Model entry point functions */
extern void Rpi_cam_initialize(void);
extern void Rpi_cam_step(void);
extern void Rpi_cam_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Rpi_cam_T *const Rpi_cam_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Rpi_cam'
 * '<S1>'   : 'Rpi_cam/Perception Unit'
 * '<S2>'   : 'Rpi_cam/RGB to Image'
 * '<S3>'   : 'Rpi_cam/Perception Unit/MATLAB Function4'
 * '<S4>'   : 'Rpi_cam/Perception Unit/MATLAB Function6'
 */
#endif                                 /* RTW_HEADER_Rpi_cam_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
