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
 * C/C++ source code generated on : Mon Mar  4 13:32:08 2024
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
#include "MW_SDL2_video_display.h"
#include "MW_availableWebcam.h"
#include "MW_v4l2_cam.h"
#endif                                 /* Rpi_cam_COMMON_INCLUDES_ */

#include "Rpi_cam_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T converttoimage[921600];      /* '<S2>/convert to image' */
  uint8_T R[307200];                   /* '<Root>/ImageToRGB' */
  uint8_T G[307200];                   /* '<Root>/ImageToRGB' */
  uint8_T B[307200];                   /* '<Root>/ImageToRGB' */
  uint8_T b_varargout_3[307200];
  uint8_T b_varargout_2[307200];
  uint8_T b_varargout_1[307200];
  uint8_T b_varargout_1_m[307200];
  char_T b_errorMessage[101];
  char_T b[18];
  char_T i[18];
  char_T devName[12];
  char_T j[12];
} B_Rpi_cam_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_Ra_T obj; /* '<Root>/V4L2 Video Capture' */
  codertarget_linux_blocks_SDL2_T obj_j;/* '<S3>/MATLAB System' */
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
  const char_T * volatile errorStatus;
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
 * '<S1>'   : 'Rpi_cam/ImageToRGB'
 * '<S2>'   : 'Rpi_cam/RGB to Image'
 * '<S3>'   : 'Rpi_cam/SDL Video Display'
 */
#endif                                 /* RTW_HEADER_Rpi_cam_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
