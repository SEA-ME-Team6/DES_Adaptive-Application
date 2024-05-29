//
//  server.h
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


#ifndef server_h_
#define server_h_
#include <stdbool.h>
#include <stdint.h>
// #include "complex_types.h"
#include "providedinterface_skeleton.h"
#include <stddef.h>
#include "server_types.h"
#include <memory>

// Class declaration for model server
class server final
{
  // public data and function members
 public:
  // Copy Constructor
  server(server const&) = delete;

  // Assignment Operator
  server& operator= (server const&) & = delete;

  // Move Constructor
  server(server &&) = delete;

  // Move Assignment Operator
  server& operator= (server &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  server();

  // Destructor
  ~server();

  // private data and function members
 private:
  std::shared_ptr<skeleton::ProvidedInterfaceSkeleton> ProvidedPort;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'server'

#endif                                 // server_h_
