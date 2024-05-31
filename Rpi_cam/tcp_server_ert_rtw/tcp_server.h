/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tcp_server.h
 *
 * Code generated for Simulink model 'tcp_server'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue May 28 16:07:19 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_tcp_server_h_
#define RTW_HEADER_tcp_server_h_
#ifndef tcp_server_COMMON_INCLUDES_
#define tcp_server_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_TCPSendReceive.h"
#endif                                 /* tcp_server_COMMON_INCLUDES_ */

#include "tcp_server_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_Ra_T obj; /* '<S1>/TCP//IP Receive' */
} DW_tcp_server_T;

/* Real-time Model Data Structure */
struct tag_RTM_tcp_server_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_tcp_server_T tcp_server_DW;

/* Model entry point functions */
extern void tcp_server_initialize(void);
extern void tcp_server_step(void);
extern void tcp_server_terminate(void);

/* Real-time Model object */
extern RT_MODEL_tcp_server_T *const tcp_server_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 */

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
 * '<Root>' : 'tcp_server'
 * '<S1>'   : 'tcp_server/Subsystem'
 */
#endif                                 /* RTW_HEADER_tcp_server_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
