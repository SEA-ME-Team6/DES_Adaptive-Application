//
//  ultrasonic.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "ultrasonic".
//
//  Model version              : 2.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Mon Jun  3 22:46:50 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#include "ultrasonic.h"
#include <cmath>
#include <stdint.h>
#include <array>

void ultrasonic::SystemCore_setup(codertarget_raspi_internal_RaspiTCPReceive
  *obj)
{
  std::array<char, 14> ipaddr;
  double tmp;
  int16_t errorNo;
  uint16_t tmp_0;
  uint8_t isLittleEndian;
  static const std::array<char, 14> ipaddr_0{ { '1', '9', '2', '.', '1', '6',
      '8', '.', '1', '.', '1', '5', '5', '\x00' } };

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  obj->isInitialized = 1;
  obj->isServer_ = 0.0;
  for (int32_t i{0}; i < 14; i++) {
    ipaddr[i] = ipaddr_0[i];
  }

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  tmp = std::round(obj->isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_t>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = UINT16_MAX;
  }

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  TCPStreamSetup(3333, 0, &obj->connStream_, tmp_0, 0.0, &errorNo, &ipaddr[0]);
  littleEndianCheck(&isLittleEndian);
}

// Model step function
void ultrasonic::step()
{
  double tmp;
  uint32_t duration;
  int16_t errorNo;
  uint16_t tmp_0;
  int8_t b_varargout_2;
  uint8_t b_varargout_1;

  // MATLABSystem: '<Root>/TCP//IP Receive'
  tmp = std::round(rtDW.obj_l.isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_t>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = UINT16_MAX;
  }

  TCPStreamStepRecv(&b_varargout_1, &b_varargout_2, 1, rtDW.obj_l.connStream_,
                    &errorNo, tmp_0);

  // Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1>/Enable'

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  if (b_varargout_1 > 0) {
    // MATLABSystem: '<S1>/Ultrasonic Sensor'
    if (rtDW.obj.SampleTime != -1.0) {
      rtDW.obj.SampleTime = -1.0;
    }

    MW_UltrasonicRead(&duration, 1, 4U, 17U, 10, 5);

    // End of MATLABSystem: '<S1>/Ultrasonic Sensor'
  }

  // End of Outputs for SubSystem: '<Root>/Enabled Subsystem'
}

// Model initialize function
void ultrasonic::initialize()
{
  // SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem'
  // Start for MATLABSystem: '<S1>/Ultrasonic Sensor'
  rtDW.obj.matlabCodegenIsDeleted = false;
  rtDW.obj.SampleTime = -1.0;
  rtDW.obj.isInitialized = 1;
  EXT_GPIO_init(4U, 1);
  EXT_GPIO_init(17U, 0);
  rtDW.obj.isSetupComplete = true;

  // End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem'

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  SystemCore_setup(&rtDW.obj_l);
}

// Model terminate function
void ultrasonic::terminate()
{
  // Terminate for Enabled SubSystem: '<Root>/Enabled Subsystem'
  // Terminate for MATLABSystem: '<S1>/Ultrasonic Sensor'
  if (!rtDW.obj.matlabCodegenIsDeleted) {
    rtDW.obj.matlabCodegenIsDeleted = true;
    if ((rtDW.obj.isInitialized == 1) && rtDW.obj.isSetupComplete) {
      EXT_GPIO_terminate(17U);
      EXT_GPIO_terminate(4U);
    }
  }

  // End of Terminate for MATLABSystem: '<S1>/Ultrasonic Sensor'
  // End of Terminate for SubSystem: '<Root>/Enabled Subsystem'
}

// Constructor
ultrasonic::ultrasonic():
  rtDW()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
ultrasonic::~ultrasonic() = default;
