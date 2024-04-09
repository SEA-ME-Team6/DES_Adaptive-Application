//
//  Adaptive_Event_send.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "Adaptive_Event_send".
//
//  Model version              : 1.109
//  Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
//  C++ source code generated on : Tue Mar 19 14:13:20 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#include "Adaptive_Event_send.h"

// Model step function
void Adaptive_Event_send::step()
{
  // Send: '<Root>/Event Send'
  // Send event
  ProvidedPort->Error.Send(-1.0);
}

// Model initialize function
void Adaptive_Event_send::initialize()
{
  // Initialize service provider instance - ProvidedPort
  ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::
    com::InstanceIdentifier(ara::core::StringView("1")), ara::com::
    MethodCallProcessingMode::kEventSingleThread);
  ProvidedPort->OfferService();
}

// Model terminate function
void Adaptive_Event_send::terminate()
{
  ProvidedPort->StopOfferService();
}

// Constructor
Adaptive_Event_send::Adaptive_Event_send()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
Adaptive_Event_send::~Adaptive_Event_send() = default;
