//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ultrasonic.cpp
//
// Code generated for Simulink model 'ultrasonic'.
//
// Model version                  : 1.8
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Apr 18 14:01:03 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ultrasonic.h"
#include "ultrasonic_types.h"
#include <string.h>
#include "ultrasonic_private.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <math.h>

// Block states (default storage)
DW_ultrasonic_T ultrasonic_DW;

// Real-time model
RT_MODEL_ultrasonic_T ultrasonic_M_ = RT_MODEL_ultrasonic_T();
RT_MODEL_ultrasonic_T *const ultrasonic_M = &ultrasonic_M_;

// Forward declaration for local functions
static void ultrasonic_SystemCore_setup
  (codertarget_raspi_internal_RaspiTCPSend_ultrasonic_T *obj);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void ultrasonic_SystemCore_setup
  (codertarget_raspi_internal_RaspiTCPSend_ultrasonic_T *obj)
{
  real_T tmp;
  int32_T i;
  int16_T errorNo;
  uint16_T tmp_0;
  char_T ipaddr[14];
  static const char_T ipaddr_0[14] = "192.168.1.155";

  // Start for MATLABSystem: '<Root>/TCP//IP Send1'
  obj->isInitialized = 1;
  obj->isServer_ = 0.0;
  for (i = 0; i < 14; i++) {
    ipaddr[i] = ipaddr_0[i];
  }

  // Start for MATLABSystem: '<Root>/TCP//IP Send1'
  tmp = rt_roundd_snf(obj->isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_T>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  // Start for MATLABSystem: '<Root>/TCP//IP Send1'
  TCPStreamSetup(3334, 0, &obj->connStream_, tmp_0, 0.0, &errorNo, &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
}

// Model step function
void ultrasonic_step(void)
{
  real_T rtb_brake_command;
  real_T tmp;
  uint32_T duration;
  int16_T errorNo;
  uint16_T tmp_0;
  uint8_T b_x[8];
  uint8_T xtmp;

  // MATLABSystem: '<Root>/Ultrasonic Sensor1'
  if (ultrasonic_DW.obj_l.SampleTime !=
      ultrasonic_P.UltrasonicSensor1_SampleTime) {
    ultrasonic_DW.obj_l.SampleTime = ultrasonic_P.UltrasonicSensor1_SampleTime;
  }

  MW_UltrasonicRead(&duration, 1, 4U, 17U, 10, 5);

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   MATLABSystem: '<Root>/Ultrasonic Sensor1'
  //
  rtb_brake_command = (static_cast<real_T>(duration) * 0.000343 / 2.0 < 0.12);

  // MATLABSystem: '<Root>/TCP//IP Send1'
  if (ultrasonic_DW.obj.isLittleEnd_ == 1) {
    memcpy((void *)&b_x[0], (void *)&rtb_brake_command, (size_t)8 * sizeof
           (uint8_T));
    xtmp = b_x[0];
    b_x[0] = b_x[7];
    b_x[7] = xtmp;
    xtmp = b_x[1];
    b_x[1] = b_x[6];
    b_x[6] = xtmp;
    xtmp = b_x[2];
    b_x[2] = b_x[5];
    b_x[5] = xtmp;
    xtmp = b_x[3];
    b_x[3] = b_x[4];
    b_x[4] = xtmp;
    memcpy((void *)&rtb_brake_command, (void *)&b_x[0], (size_t)1 * sizeof
           (real_T));
  }

  tmp = rt_roundd_snf(ultrasonic_DW.obj.isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_T>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  TCPStreamStepSend(&rtb_brake_command, 8U, ultrasonic_DW.obj.connStream_, tmp_0,
                    &errorNo);

  // End of MATLABSystem: '<Root>/TCP//IP Send1'
}

// Model initialize function
void ultrasonic_initialize(void)
{
  // Start for MATLABSystem: '<Root>/Ultrasonic Sensor1'
  ultrasonic_DW.obj_l.matlabCodegenIsDeleted = false;
  ultrasonic_DW.obj_l.SampleTime = ultrasonic_P.UltrasonicSensor1_SampleTime;
  ultrasonic_DW.obj_l.isInitialized = 1;
  EXT_GPIO_init(4U, 1);
  EXT_GPIO_init(17U, 0);
  ultrasonic_DW.obj_l.isSetupComplete = true;

  // Start for MATLABSystem: '<Root>/TCP//IP Send1'
  ultrasonic_SystemCore_setup(&ultrasonic_DW.obj);
}

// Model terminate function
void ultrasonic_terminate(void)
{
  // Terminate for MATLABSystem: '<Root>/Ultrasonic Sensor1'
  if (!ultrasonic_DW.obj_l.matlabCodegenIsDeleted) {
    ultrasonic_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((ultrasonic_DW.obj_l.isInitialized == 1) &&
        ultrasonic_DW.obj_l.isSetupComplete) {
      EXT_GPIO_terminate(17U);
      EXT_GPIO_terminate(4U);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/Ultrasonic Sensor1'
}

//
// File trailer for generated code.
//
// [EOF]
//
