//
//  control.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "control".
//
//  Model version              : 2.3
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Mon Jun  3 22:36:09 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#include "control.h"
#include <cstring>
#include <cmath>
#include <stdint.h>
#include <array>
#include <stddef.h>

void control::TCPSend_setupImpl(codertarget_raspi_internal_RaspiTCPSend *obj)
{
  std::array<char, 14> ipaddr;
  double tmp;
  int16_t errorNo;
  uint16_t tmp_0;
  static const std::array<char, 14> ipaddr_0{ { '1', '9', '2', '.', '1', '6',
      '8', '.', '1', '.', '1', '5', '5', '\x00' } };

  obj->isServer_ = 0.0;
  for (int32_t i{0}; i < 14; i++) {
    ipaddr[i] = ipaddr_0[i];
  }

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

  // Start for MATLABSystem: '<Root>/TCP//IP Send'
  TCPStreamSetup(3334, 0, &obj->connStream_, tmp_0, 0.0, &errorNo, &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
}

void control::TCPSend_setupImpl_m(codertarget_raspi_internal_RaspiTCPSend *obj)
{
  std::array<char, 14> ipaddr;
  double tmp;
  int16_t errorNo;
  uint16_t tmp_0;
  static const std::array<char, 14> ipaddr_0{ { '1', '9', '2', '.', '1', '6',
      '8', '.', '1', '.', '1', '5', '5', '\x00' } };

  obj->isServer_ = 0.0;
  for (int32_t i{0}; i < 14; i++) {
    ipaddr[i] = ipaddr_0[i];
  }

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

  // Start for MATLABSystem: '<Root>/TCP//IP Send1'
  TCPStreamSetup(3335, 0, &obj->connStream_, tmp_0, 0.0, &errorNo, &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
}

void control::RequiredPortLKASReceive(ara::com::SamplePtr< proxy::events::LKAS::
  SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive'
  rtDW.EventReceive = *elementPtr;
}

void control::RequiredPortAEBReceive(ara::com::SamplePtr< proxy::events::AEB::
  SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive1'
  rtDW.EventReceive1 = *elementPtr;
}

// Model step function
void control::step()
{
  std::array<uint8_t, 8> y;
  std::shared_ptr<ara::core::Result<size_t>> resultPtr;
  double rtb_Gain;
  double tmp;
  int16_t errorNo;
  uint16_t tmp_0;
  uint8_t xtmp;
  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->LKAS.GetNewSamples(std::move(std::bind(&control::
          RequiredPortLKASReceive, this, std::placeholders::_1)), 1U));
    if (resultPtr->HasValue()) {
      resultPtr->Value();
    }
  }

  // Gain: '<Root>/Gain'
  rtb_Gain = 0.008 * rtDW.EventReceive;

  // MATLABSystem: '<Root>/TCP//IP Send'
  if (rtDW.obj_n.isLittleEnd_ == 1) {
    std::memcpy((void *)&y[0], (void *)&rtb_Gain, (uint32_t)((size_t)8 * sizeof
      (uint8_t)));
    xtmp = y[0];
    y[0] = y[7];
    y[7] = xtmp;
    xtmp = y[1];
    y[1] = y[6];
    y[6] = xtmp;
    xtmp = y[2];
    y[2] = y[5];
    y[5] = xtmp;
    xtmp = y[3];
    y[3] = y[4];
    y[4] = xtmp;
    std::memcpy((void *)&rtb_Gain, (void *)&y[0], (uint32_t)((size_t)1 * sizeof
      (double)));
  }

  tmp = std::round(rtDW.obj_n.isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_t>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = UINT16_MAX;
  }

  TCPStreamStepSend(&rtb_Gain, 8U, rtDW.obj_n.connStream_, tmp_0, &errorNo);

  // End of MATLABSystem: '<Root>/TCP//IP Send'
  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->AEB.GetNewSamples(std::move(std::bind(&control::
          RequiredPortAEBReceive, this, std::placeholders::_1)), 1U));
    if (resultPtr->HasValue()) {
      resultPtr->Value();
    }
  }

  // Switch: '<Root>/Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant1'

  if (rtDW.EventReceive1 > 0.0) {
    rtb_Gain = 0.45;
  } else {
    rtb_Gain = 0.0;
  }

  // End of Switch: '<Root>/Switch'

  // MATLABSystem: '<Root>/TCP//IP Send1'
  if (rtDW.obj.isLittleEnd_ == 1) {
    std::memcpy((void *)&y[0], (void *)&rtb_Gain, (uint32_t)((size_t)8 * sizeof
      (uint8_t)));
    xtmp = y[0];
    y[0] = y[7];
    y[7] = xtmp;
    xtmp = y[1];
    y[1] = y[6];
    y[6] = xtmp;
    xtmp = y[2];
    y[2] = y[5];
    y[5] = xtmp;
    xtmp = y[3];
    y[3] = y[4];
    y[4] = xtmp;
    std::memcpy((void *)&rtb_Gain, (void *)&y[0], (uint32_t)((size_t)1 * sizeof
      (double)));
  }

  tmp = std::round(rtDW.obj.isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_t>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = UINT16_MAX;
  }

  TCPStreamStepSend(&rtb_Gain, 8U, rtDW.obj.connStream_, tmp_0, &errorNo);

  // End of MATLABSystem: '<Root>/TCP//IP Send1'
}

// Model initialize function
void control::initialize()
{
  {
    ara::com::ServiceHandleContainer< proxy::RequiredInterfaceProxy::HandleType >
      handles;
    std::shared_ptr<ara::core::Result<ara::com::ServiceHandleContainer< proxy::
      RequiredInterfaceProxy::HandleType >>> resultPtr;

    // Start for MATLABSystem: '<Root>/TCP//IP Send'
    rtDW.obj_n.isInitialized = 1;
    TCPSend_setupImpl(&rtDW.obj_n);

    // Start for MATLABSystem: '<Root>/TCP//IP Send1'
    rtDW.obj.isInitialized = 1;
    TCPSend_setupImpl_m(&rtDW.obj);

    // Initialize service requester instance - RequiredPort
    resultPtr = std::make_shared< ara::core::Result<ara::com::
      ServiceHandleContainer< proxy::RequiredInterfaceProxy::HandleType >> >
      (proxy::RequiredInterfaceProxy::FindService(ara::com::InstanceIdentifier
        (ara::core::StringView("1"))));
    if (resultPtr->HasValue()) {
      handles = resultPtr->Value();
      if (handles.size() > 0U) {
        RequiredPort = std::make_shared< proxy::RequiredInterfaceProxy >
          (*handles.begin());

        // Subscribe events
        RequiredPort->AEB.Subscribe(1U);
        RequiredPort->LKAS.Subscribe(1U);
      }
    }
  }
}

// Model terminate function
void control::terminate()
{
  // (no terminate code required)
}

// Constructor
control::control():
  rtDW()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
control::~control() = default;
