//
//  ultrasonic.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "ultrasonic".
//
//  Model version              : 1.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Mon Jun  3 18:59:03 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "ultrasonic.h"
#include <stdint.h>

// Model step function
void ultrasonic::step()
{
  int32_t rtb_brake_command;
  uint32_t duration;

  // MATLABSystem: '<Root>/Ultrasonic Sensor'
  if (ultrasonic_DW.obj.SampleTime != -1.0) {
    ultrasonic_DW.obj.SampleTime = -1.0;
  }

  MW_UltrasonicRead(&duration, 1, 4U, 17U, 10, 5);

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   MATLABSystem: '<Root>/Ultrasonic Sensor'
  //
  rtb_brake_command = (static_cast<double>(duration) * 0.000343 / 2.0 < 0.12);

  // Send: '<Root>/Event Send'
  // Send event
  ProvidedPort->Brake.Send(static_cast<double>(rtb_brake_command));
}

// Model initialize function
void ultrasonic::initialize()
{
  // Start for MATLABSystem: '<Root>/Ultrasonic Sensor'
  ultrasonic_DW.obj.matlabCodegenIsDeleted = false;
  ultrasonic_DW.obj.SampleTime = -1.0;
  ultrasonic_DW.obj.isInitialized = 1;
  EXT_GPIO_init(4U, 1);
  EXT_GPIO_init(17U, 0);
  ultrasonic_DW.obj.isSetupComplete = true;

  // Initialize service provider instance - ProvidedPort
  ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::
    com::InstanceIdentifier(ara::core::StringView("1")), ara::com::
    MethodCallProcessingMode::kEventSingleThread);
  ProvidedPort->OfferService();
}

// Model terminate function
void ultrasonic::terminate()
{
  // Terminate for MATLABSystem: '<Root>/Ultrasonic Sensor'
  if (!ultrasonic_DW.obj.matlabCodegenIsDeleted) {
    ultrasonic_DW.obj.matlabCodegenIsDeleted = true;
    if ((ultrasonic_DW.obj.isInitialized == 1) &&
        ultrasonic_DW.obj.isSetupComplete) {
      EXT_GPIO_terminate(17U);
      EXT_GPIO_terminate(4U);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/Ultrasonic Sensor'
  ProvidedPort->StopOfferService();
}

// Constructor
ultrasonic::ultrasonic():
  ultrasonic_DW()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
ultrasonic::~ultrasonic() = default;
