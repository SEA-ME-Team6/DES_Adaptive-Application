//
//  client.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "client".
//
//  Model version              : 1.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Thu May 23 14:43:32 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: AMD->x86-64 (Linux 64)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "client.h"
#include <stdint.h>
#include <iostream>

void client::RequiredPortSvcHandler(ara::com::ServiceHandleContainer< proxy::
  RequiredInterfaceProxy::HandleType > svcHandles, const ara::com::
  FindServiceHandle fsHandle)
{
  if ((!RequiredPort) && (svcHandles.size() > 0U)) {
    RequiredPort = std::make_shared< proxy::RequiredInterfaceProxy >
      (*svcHandles.begin());
    RequiredPort->In1.Subscribe(1U);
    proxy::RequiredInterfaceProxy::StopFindService(fsHandle);
  }
}

void client::RequiredPortIn1Receive(ara::com::SamplePtr< proxy::events::In1::
  SampleType const > elementPtr)
{
  *elementPtr;
  std::cout << "Send messages: " << *elementPtr << std::endl;
}

// Model step function
void client::step()
{ 
  std::shared_ptr<ara::core::Result<size_t>> resultPtr;
  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> > (RequiredPort->In1.GetNewSamples(std::move(std::bind(&client::RequiredPortIn1Receive, this, std::placeholders::_1)), 1U));
    if (resultPtr->HasValue()) {
      resultPtr->Value();
    }
  }
}

// Model initialize function
void client::initialize()
{
  // Initialize service requester instance - RequiredPort
  proxy::RequiredInterfaceProxy::StartFindService(std::move(std::bind(&client::
    RequiredPortSvcHandler, this, std::placeholders::_1, std::placeholders::_2)),
    ara::com::InstanceIdentifier(std::string("1")));
}

// Model terminate function
void client::terminate()
{
  // (no terminate code required)
}

// Constructor
client::client()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
client::~client() = default;
