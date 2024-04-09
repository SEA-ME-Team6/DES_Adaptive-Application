/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Rpi_cam.c
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

#include "Rpi_cam.h"
#include "Rpi_cam_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "Rpi_cam_private.h"

/* Block signals (default storage) */
B_Rpi_cam_T Rpi_cam_B;

/* Block states (default storage) */
DW_Rpi_cam_T Rpi_cam_DW;

/* Real-time model */
static RT_MODEL_Rpi_cam_T Rpi_cam_M_;
RT_MODEL_Rpi_cam_T *const Rpi_cam_M = &Rpi_cam_M_;

/* Forward declaration for local functions */
static void v4l2Capture_updateV4L2Settings(codertarget_raspi_internal_Ra_T *obj,
  boolean_T forceUpdate);
static void Rpi_cam_SystemCore_step(codertarget_raspi_internal_Ra_T *obj,
  uint8_T varargout_1[307200], uint8_T varargout_2[307200], uint8_T varargout_3
  [307200]);
static codertarget_raspi_internal_Ra_T *Raspiv4l2Capture_Raspiv4l2Captu
  (codertarget_raspi_internal_Ra_T *obj);
static void Rpi_cam_SystemCore_setup(codertarget_raspi_internal_Ra_T *obj);
static void v4l2Capture_updateV4L2Settings(codertarget_raspi_internal_Ra_T *obj,
  boolean_T forceUpdate)
{
  int32_T i;
  uint8_T status;
  static const char_T b[11] = "Brightness";
  static const char_T c[9] = "Contrast";
  static const char_T d[11] = "Saturation";
  static const char_T e[10] = "Sharpness";
  static const char_T f[10] = "CameraPan";
  static const char_T g[11] = "CameraTilt";
  static const char_T h[11] = "CameraZoom";
  static const char_T i_0[18] = "EnableManualFocus";
  static const char_T j[12] = "ManualFocus";

  /* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
  if ((obj->Brightness != obj->BrightnessInternal) || forceUpdate) {
    obj->BrightnessInternal = obj->Brightness;
    for (i = 0; i < 11; i++) {
      Rpi_cam_B.b[i] = b[i];
    }

    EXT_updateV4L2Control(&Rpi_cam_B.b[0], (real32_T)obj->Brightness, 0, &status);
  }

  if ((obj->Contrast != obj->ContrastInternal) || forceUpdate) {
    obj->ContrastInternal = obj->Contrast;
    for (i = 0; i < 9; i++) {
      Rpi_cam_B.c[i] = c[i];
    }

    EXT_updateV4L2Control(&Rpi_cam_B.c[0], (real32_T)obj->Contrast, 0, &status);
  }

  if ((obj->Saturation != obj->SaturationInternal) || forceUpdate) {
    obj->SaturationInternal = obj->Saturation;
    for (i = 0; i < 11; i++) {
      Rpi_cam_B.b[i] = d[i];
    }

    EXT_updateV4L2Control(&Rpi_cam_B.b[0], (real32_T)obj->Saturation, 0, &status);
  }

  if ((obj->Sharpness != obj->SharpnessInternal) || forceUpdate) {
    obj->SharpnessInternal = obj->Sharpness;
    for (i = 0; i < 10; i++) {
      Rpi_cam_B.e[i] = e[i];
    }

    EXT_updateV4L2Control(&Rpi_cam_B.e[0], (real32_T)obj->Sharpness, 0, &status);
  }

  if ((obj->CameraPan != obj->CameraPanInternal) || forceUpdate) {
    obj->CameraPanInternal = obj->CameraPan;
    for (i = 0; i < 10; i++) {
      Rpi_cam_B.e[i] = f[i];
    }

    EXT_updateV4L2Control(&Rpi_cam_B.e[0], (real32_T)obj->CameraPan, 0, &status);
  }

  if ((obj->CameraTilt != obj->CameraTiltInternal) || forceUpdate) {
    obj->CameraTiltInternal = obj->CameraTilt;
    for (i = 0; i < 11; i++) {
      Rpi_cam_B.b[i] = g[i];
    }

    EXT_updateV4L2Control(&Rpi_cam_B.b[0], (real32_T)obj->CameraTilt, 0, &status);
  }

  if ((obj->CameraZoom != obj->CameraZoomInternal) || forceUpdate) {
    obj->CameraZoomInternal = obj->CameraZoom;
    for (i = 0; i < 11; i++) {
      Rpi_cam_B.b[i] = h[i];
    }

    EXT_updateV4L2Control(&Rpi_cam_B.b[0], (real32_T)obj->CameraZoom, 0, &status);
  }

  if ((!obj->EnableManualFocusInternal) || forceUpdate) {
    obj->EnableManualFocusInternal = true;
    for (i = 0; i < 18; i++) {
      Rpi_cam_B.i[i] = i_0[i];
    }

    EXT_updateV4L2Control(&Rpi_cam_B.i[0], 1.0F, 0, &status);
  }

  if ((obj->ManualFocus != obj->ManualFocusInternal) || forceUpdate) {
    obj->ManualFocusInternal = obj->ManualFocus;
    for (i = 0; i < 12; i++) {
      Rpi_cam_B.j[i] = j[i];
    }

    EXT_updateV4L2Control(&Rpi_cam_B.j[0], (real32_T)obj->ManualFocus, 0,
                          &status);
  }

  /* End of Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
}

static void Rpi_cam_SystemCore_step(codertarget_raspi_internal_Ra_T *obj,
  uint8_T varargout_1[307200], uint8_T varargout_2[307200], uint8_T varargout_3
  [307200])
{
  real_T ts;

  /* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
  v4l2Capture_updateV4L2Settings(obj, false);
  EXT_webcamReadFrame(0, &ts, &varargout_1[0], &varargout_2[0], &varargout_3[0]);
}

static codertarget_raspi_internal_Ra_T *Raspiv4l2Capture_Raspiv4l2Captu
  (codertarget_raspi_internal_Ra_T *obj)
{
  codertarget_raspi_internal_Ra_T *b_obj;

  /* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
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

static void Rpi_cam_SystemCore_setup(codertarget_raspi_internal_Ra_T *obj)
{
  int32_T i;
  int8_T resolutionStatus;
  uint8_T camIndex;
  static const char_T devName[12] = "/dev/video0";
  static const char_T b_errorMessage[101] =
    "Webcam cannot be initialized properly. Please check if the device supports the specified resolution.";
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
  obj->isInitialized = 1;
  getCameraList();
  for (i = 0; i < 12; i++) {
    Rpi_cam_B.devName[i] = devName[i];
  }

  /* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
  camIndex = getCameraAddrIndex(&Rpi_cam_B.devName[0], 11U);
  resolutionStatus = validateResolution(camIndex, 640, 480);
  if (resolutionStatus >= 0) {
    /* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
    EXT_webcamInit(0, 0, 0, 0, 0, 0, 640U, 480U, 2U, 2U, 1U, 0.1);
  } else {
    /* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
    memcpy(&Rpi_cam_B.b_errorMessage[0], &b_errorMessage[0], 101U * sizeof
           (char_T));
    perror(&Rpi_cam_B.b_errorMessage[0]);

    /* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
    exit(0);
  }

  /* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
  v4l2Capture_updateV4L2Settings(obj, true);
  obj->isSetupComplete = true;
}

/* Model step function */
void Rpi_cam_step(void)
{
  real_T ImageDataTypeConversion;
  real_T ImageDataTypeConversion_0;
  real_T ImageDataTypeConversion_1;
  real_T max;
  real_T s;
  int32_T i;
  int32_T i_0;

  /* MATLABSystem: '<Root>/V4L2 Video Capture' */
  if (Rpi_cam_DW.obj.Brightness != Rpi_cam_P.V4L2VideoCapture_Brightness) {
    Rpi_cam_DW.obj.Brightness = Rpi_cam_P.V4L2VideoCapture_Brightness;
  }

  if (Rpi_cam_DW.obj.Saturation != Rpi_cam_P.V4L2VideoCapture_Saturation) {
    Rpi_cam_DW.obj.Saturation = Rpi_cam_P.V4L2VideoCapture_Saturation;
  }

  if (Rpi_cam_DW.obj.Contrast != Rpi_cam_P.V4L2VideoCapture_Contrast) {
    Rpi_cam_DW.obj.Contrast = Rpi_cam_P.V4L2VideoCapture_Contrast;
  }

  if (Rpi_cam_DW.obj.Sharpness != Rpi_cam_P.V4L2VideoCapture_Sharpness) {
    Rpi_cam_DW.obj.Sharpness = Rpi_cam_P.V4L2VideoCapture_Sharpness;
  }

  if (Rpi_cam_DW.obj.CameraPan != Rpi_cam_P.V4L2VideoCapture_CameraPan) {
    Rpi_cam_DW.obj.CameraPan = Rpi_cam_P.V4L2VideoCapture_CameraPan;
  }

  if (Rpi_cam_DW.obj.CameraTilt != Rpi_cam_P.V4L2VideoCapture_CameraTilt) {
    Rpi_cam_DW.obj.CameraTilt = Rpi_cam_P.V4L2VideoCapture_CameraTilt;
  }

  if (Rpi_cam_DW.obj.CameraZoom != Rpi_cam_P.V4L2VideoCapture_CameraZoom) {
    Rpi_cam_DW.obj.CameraZoom = Rpi_cam_P.V4L2VideoCapture_CameraZoom;
  }

  if (Rpi_cam_DW.obj.ManualFocus != Rpi_cam_P.V4L2VideoCapture_ManualFocus) {
    Rpi_cam_DW.obj.ManualFocus = Rpi_cam_P.V4L2VideoCapture_ManualFocus;
  }

  Rpi_cam_SystemCore_step(&Rpi_cam_DW.obj, Rpi_cam_B.b_varargout_1,
    Rpi_cam_B.b_varargout_2, Rpi_cam_B.b_varargout_3);

  /* Math: '<S2>/Transpose' incorporates:
   *  Concatenate: '<S2>/convert to image'
   *  MATLABSystem: '<Root>/V4L2 Video Capture'
   * */
  for (i = 0; i < 640; i++) {
    for (i_0 = 0; i_0 < 480; i_0++) {
      Rpi_cam_B.b_varargout_1_m[i_0 + 480 * i] = Rpi_cam_B.b_varargout_1[640 *
        i_0 + i];
    }
  }

  memcpy(&Rpi_cam_B.converttoimage[0], &Rpi_cam_B.b_varargout_1_m[0], 307200U *
         sizeof(uint8_T));

  /* End of Math: '<S2>/Transpose' */

  /* Math: '<S2>/Transpose1' incorporates:
   *  Concatenate: '<S2>/convert to image'
   *  MATLABSystem: '<Root>/V4L2 Video Capture'
   * */
  for (i = 0; i < 640; i++) {
    for (i_0 = 0; i_0 < 480; i_0++) {
      Rpi_cam_B.b_varargout_1[i_0 + 480 * i] = Rpi_cam_B.b_varargout_2[640 * i_0
        + i];
    }
  }

  memcpy(&Rpi_cam_B.converttoimage[307200], &Rpi_cam_B.b_varargout_1[0], 307200U
         * sizeof(uint8_T));

  /* End of Math: '<S2>/Transpose1' */

  /* Math: '<S2>/Transpose2' incorporates:
   *  Concatenate: '<S2>/convert to image'
   *  MATLABSystem: '<Root>/V4L2 Video Capture'
   * */
  for (i = 0; i < 640; i++) {
    for (i_0 = 0; i_0 < 480; i_0++) {
      Rpi_cam_B.b_varargout_2[i_0 + 480 * i] = Rpi_cam_B.b_varargout_3[640 * i_0
        + i];
    }
  }

  memcpy(&Rpi_cam_B.converttoimage[614400], &Rpi_cam_B.b_varargout_2[0], 307200U
         * sizeof(uint8_T));

  /* End of Math: '<S2>/Transpose2' */

  /* S-Function (svipscalenconvert): '<S1>/Image Data Type Conversion' incorporates:
   *  Concatenate: '<S2>/convert to image'
   */
  for (i = 0; i < 921600; i++) {
    Rpi_cam_B.ImageDataTypeConversion[i] = (real_T)Rpi_cam_B.converttoimage[i] /
      255.0;
  }

  /* End of S-Function (svipscalenconvert): '<S1>/Image Data Type Conversion' */
  /* temporary variables for in-place operation */
  for (i = 0; i < 307200; i++) {
    /* S-Function (svipcolorconv): '<S1>/Color Space  Conversion' incorporates:
     *  S-Function (svipscalenconvert): '<S1>/Image Data Type Conversion'
     */
    /* First get the min and max of the RGB triplet */
    ImageDataTypeConversion = Rpi_cam_B.ImageDataTypeConversion[i];
    ImageDataTypeConversion_0 = Rpi_cam_B.ImageDataTypeConversion[i + 307200];
    if (ImageDataTypeConversion > ImageDataTypeConversion_0) {
      ImageDataTypeConversion_1 = Rpi_cam_B.ImageDataTypeConversion[i + 614400];
      if (ImageDataTypeConversion_0 < ImageDataTypeConversion_1) {
        Rpi_cam_B.min = ImageDataTypeConversion_0;
      } else {
        Rpi_cam_B.min = ImageDataTypeConversion_1;
      }

      if (ImageDataTypeConversion > ImageDataTypeConversion_1) {
        max = ImageDataTypeConversion;
      } else {
        max = ImageDataTypeConversion_1;
      }
    } else {
      ImageDataTypeConversion_1 = Rpi_cam_B.ImageDataTypeConversion[i + 614400];
      if (ImageDataTypeConversion < ImageDataTypeConversion_1) {
        Rpi_cam_B.min = ImageDataTypeConversion;
      } else {
        Rpi_cam_B.min = ImageDataTypeConversion_1;
      }

      if (ImageDataTypeConversion_0 > ImageDataTypeConversion_1) {
        max = ImageDataTypeConversion_0;
      } else {
        max = ImageDataTypeConversion_1;
      }
    }

    s = max - Rpi_cam_B.min;
    if (max != 0.0) {
      Rpi_cam_B.min = s / max;
    } else {
      Rpi_cam_B.min = 0.0;
    }

    if (s != 0.0) {
      if (ImageDataTypeConversion == max) {
        ImageDataTypeConversion = (ImageDataTypeConversion_0 -
          ImageDataTypeConversion_1) / s;
      } else if (ImageDataTypeConversion_0 == max) {
        ImageDataTypeConversion = (ImageDataTypeConversion_1 -
          ImageDataTypeConversion) / s + 2.0;
      } else {
        ImageDataTypeConversion = (ImageDataTypeConversion -
          ImageDataTypeConversion_0) / s + 4.0;
      }

      ImageDataTypeConversion /= 6.0;
      if (ImageDataTypeConversion < 0.0) {
        ImageDataTypeConversion++;
      }
    } else {
      ImageDataTypeConversion = 0.0;
    }

    /* assign the results */
    Rpi_cam_B.ColorSpaceConversion[i] = ImageDataTypeConversion;

    /* S-Function (svipcolorconv): '<S1>/Color Space  Conversion' */
    Rpi_cam_B.ColorSpaceConversion[i + 307200] = Rpi_cam_B.min;

    /* S-Function (svipcolorconv): '<S1>/Color Space  Conversion' */
    Rpi_cam_B.ColorSpaceConversion[i + 614400] = max;

    /* MATLAB Function: '<S1>/MATLAB Function6' incorporates:
     *  S-Function (svipcolorconv): '<S1>/Color Space  Conversion'
     */
    Rpi_cam_B.BW[i] = (Rpi_cam_B.min > 0.75);
  }

  {                                    /* Sample time: [0.1s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Rpi_cam_M->Timing.taskTime0 =
    ((time_T)(++Rpi_cam_M->Timing.clockTick0)) * Rpi_cam_M->Timing.stepSize0;
}

/* Model initialize function */
void Rpi_cam_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Rpi_cam_M, 50.0);
  Rpi_cam_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Rpi_cam_M->Sizes.checksums[0] = (2578648991U);
  Rpi_cam_M->Sizes.checksums[1] = (2800834537U);
  Rpi_cam_M->Sizes.checksums[2] = (2315794945U);
  Rpi_cam_M->Sizes.checksums[3] = (515467661U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Rpi_cam_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Rpi_cam_M->extModeInfo,
      &Rpi_cam_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Rpi_cam_M->extModeInfo, Rpi_cam_M->Sizes.checksums);
    rteiSetTPtr(Rpi_cam_M->extModeInfo, rtmGetTPtr(Rpi_cam_M));
  }

  /* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
  Rpi_cam_DW.obj.matlabCodegenIsDeleted = true;
  Raspiv4l2Capture_Raspiv4l2Captu(&Rpi_cam_DW.obj);
  Rpi_cam_DW.obj.Brightness = Rpi_cam_P.V4L2VideoCapture_Brightness;
  Rpi_cam_DW.obj.Saturation = Rpi_cam_P.V4L2VideoCapture_Saturation;
  Rpi_cam_DW.obj.Contrast = Rpi_cam_P.V4L2VideoCapture_Contrast;
  Rpi_cam_DW.obj.Sharpness = Rpi_cam_P.V4L2VideoCapture_Sharpness;
  Rpi_cam_DW.obj.CameraPan = Rpi_cam_P.V4L2VideoCapture_CameraPan;
  Rpi_cam_DW.obj.CameraTilt = Rpi_cam_P.V4L2VideoCapture_CameraTilt;
  Rpi_cam_DW.obj.CameraZoom = Rpi_cam_P.V4L2VideoCapture_CameraZoom;
  Rpi_cam_DW.obj.ManualFocus = Rpi_cam_P.V4L2VideoCapture_ManualFocus;
  Rpi_cam_SystemCore_setup(&Rpi_cam_DW.obj);
}

/* Model terminate function */
void Rpi_cam_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/V4L2 Video Capture' */
  if (!Rpi_cam_DW.obj.matlabCodegenIsDeleted) {
    Rpi_cam_DW.obj.matlabCodegenIsDeleted = true;
    if ((Rpi_cam_DW.obj.isInitialized == 1) && Rpi_cam_DW.obj.isSetupComplete) {
      EXT_webcamTerminate(0, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/V4L2 Video Capture' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
