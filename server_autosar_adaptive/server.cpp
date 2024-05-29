//
//  server.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "server".
//
//  Model version              : 1.2
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Tue May 28 15:29:44 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: AMD->x86-64 (Linux 64)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "server.h"

// Model step function
void server::step()
{
  // Send: '<Root>/Event Send' incorporates:
  //   Constant: '<Root>/Constant'

  // Send event
  ProvidedPort->Out1.Send(8.0);
}

// Model initialize function
void server::initialize()
{
  // Initialize service provider instance - ProvidedPort
  ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::
    com::InstanceIdentifier(std::string("1")), ara::com::
    MethodCallProcessingMode::kEventSingleThread);
  ProvidedPort->OfferService();
}

// Model terminate function
void server::terminate()
{
  ProvidedPort->StopOfferService();
}

// Constructor
server::server()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
server::~server() = default;
