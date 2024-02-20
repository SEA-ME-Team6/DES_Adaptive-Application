//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: LKAS.h
//
// Code generated for Simulink model 'LKAS'.
//
// Model version                  : 12.33
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Feb 20 13:02:00 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_LKAS_h_
#define RTW_HEADER_LKAS_h_
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "libmwimterp2d.h"
#include "HostLib_MMFile.h"
#include "HostLib_Multimedia.h"
#include "vipsvd_rt.h"
#include <stddef.h>
#include <iostream>
#include <ctime>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef struct_c_projective2d
#define struct_c_projective2d

struct c_projective2d
{
  double T[9];
};

#endif                                 // struct_c_projective2d

#ifndef struct_vision_internal_blocks_Warp
#define struct_vision_internal_blocks_Warp

struct vision_internal_blocks_Warp
{
  int32_t isInitialized;
  c_projective2d TformProjective;
};

#endif                                 // struct_vision_internal_blocks_Warp

extern "C"
{
  static double rtGetInf(void);
  static float rtGetInfF(void);
  static double rtGetMinusInf(void);
  static float rtGetMinusInfF(void);
}                                      // extern "C"

extern "C"
{
  static double rtGetNaN(void);
  static float rtGetNaNF(void);
}                                      // extern "C"

#define NOT_USING_NONFINITE_LITERALS   1

extern "C"
{
  extern double rtInf;
  extern double rtMinusInf;
  extern double rtNaN;
  extern float rtInfF;
  extern float rtMinusInfF;
  extern float rtNaNF;
  static void rt_InitInfAndNaN(size_t realSize);
  static bool rtIsInf(double value);
  static bool rtIsInfF(float value);
  static bool rtIsNaN(double value);
  static bool rtIsNaNF(float value);
  struct BigEndianIEEEDouble {
    struct {
      uint32_t wordH;
      uint32_t wordL;
    } words;
  };

  struct LittleEndianIEEEDouble {
    struct {
      uint32_t wordL;
      uint32_t wordH;
    } words;
  };

  struct IEEESingle {
    union {
      float wordLreal;
      uint32_t wordLuint;
    } wordL;
  };
}                                      // extern "C"

// Class declaration for model LKAS
class LKAS final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    vision_internal_blocks_Warp obj;   // '<S2>/Warp'
    double ColorSpaceConversion[2700000];// '<S2>/Color Space  Conversion'
    double FromMultimediaFile_HostLib[137];// '<Root>/From Multimedia File'
    double FromMultimediaFile_AudioInfo[5];// '<Root>/From Multimedia File'
    double FromMultimediaFile_VideoInfo[11];// '<Root>/From Multimedia File'
    double ColorSpaceConversion_DWORK1[2700000];// '<S2>/Color Space  Conversion' 
    double a__1_data[1200];
    double xleft[751];
    double xright[751];
    double locs_data[1200];
    double S_Channel[900000];          // '<S2>/MATLAB Function4'
    double nz[1200];
    double left_lane_index_data[100000];
    double left_lane_index_data_m[100000];
    double ImageDataTypeConversion[2700000];
    double V_data[300000];
    double b_A_data[300000];
    double b_B_data[100000];
    double b_A_data_c[300000];
    double b_varargout_1[900000];
    double xp[900000];
    double yp[900000];
    double Integrator_DSTATE;          // '<S34>/Integrator'
    double Filter_DSTATE;              // '<S29>/Filter'
    float FromMultimediaFile[2700000]; // '<Root>/From Multimedia File'
    int32_t left_lane_index[200000];
    int32_t right_lane_index[200000];
    int32_t ii_data[900000];
    int32_t jj_data[900000];
    int32_t tmp_data[900000];
    int32_t tmp_data_k[900000];
    int32_t tmp_data_c[900000];
    int32_t tmp_data_b[900000];
    int32_t tmp_data_p[900000];
    int32_t tmp_data_cv[900000];
    int32_t fPk_data[1200];
    int32_t iPk_data[2400];
    int32_t b_iPk_data[1200];
    int32_t ib_data[1200];
    int16_t idx_data[2400];
    int16_t y_data[2400];
    uint8_t inputImage_[900000];
    uint8_t outputImage[900000];
    bool o_data[900000];
    bool r_data[900000];
    bool b_tmp_data[900000];
    bool tmp_data_f[900000];
    bool tmp_data_g[900000];
    bool tmp_data_g1[900000];
    bool tmp_data_m[900000];
    bool tmp_data_n[900000];
    bool tmp_data_pp[900000];
    bool tmp_data_l[900000];
    bool tmp_data_j[900000];
    bool tmp_data_d[900000];
    bool tmp_data_gu[900000];
    bool rtb_S_Channel_l[900000];
    bool in1_data[900000];
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY {
    double Out1;                       // '<Root>/Out1'
  };

  // Real-time Model Data Structure
  struct RT_MODEL {
    const char * volatile errorStatus;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      bool stopRequestedFlag;
    } Timing;
  };

  // Copy Constructor
  LKAS(LKAS const&) = delete;

  // Assignment Operator
  LKAS& operator= (LKAS const&) & = delete;

  // Move Constructor
  LKAS(LKAS &&) = delete;

  // Move Assignment Operator
  LKAS& operator= (LKAS &&) = delete;

  // Real-Time Model get method
  LKAS::RT_MODEL * getRTM();

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  int i=0;
  int cnt_flag = 0;
  double start, finish, duration;

  // Constructor
  LKAS();

  // Destructor
  ~LKAS();

  // private data and function members
 private:
  // Block states
  DW rtDW;

  // private member function(s) for subsystem '<Root>'
  void Warp_stepImpl(vision_internal_blocks_Warp *b_this, const bool Image
                     [900000], const double input2[9], bool Jout[900000]);
  void do_vectors(const int32_t a_data[], const int32_t *a_size, const int32_t
                  b_data[], const int32_t *b_size, int32_t c_data[], int32_t
                  *c_size, int32_t ia_data[], int32_t *ia_size, int32_t ib_data[],
                  int32_t *ib_size);
  void findpeaks(const double Yin[1200], double Ypk_data[], int32_t Ypk_size[2],
                 double Xpk_data[], int32_t Xpk_size[2]);
  void eml_find(const bool x[900000], int32_t i_data[], int32_t *i_size, int32_t
                j_data[], int32_t *j_size);
  void binary_expand_op_1(bool in1_data[], int32_t *in1_size, const bool
    in2_data[], const int32_t *in2_size, const double in3_data[], const int32_t *
    in3_size, double in4);
  void binary_expand_op(bool in1_data[], int32_t *in1_size, const double
                        in2_data[], const int32_t *in2_size, double in3);
  void and_j(bool in1_data[], int32_t *in1_size, const bool in2_data[], const
             int32_t *in2_size, const bool in3_data[], const int32_t *in3_size);
  double mean(const double x_data[], const int32_t *x_size);
  double xnrm2(int32_t n, const double x_data[], int32_t ix0);
  void xswap(int32_t n, double x_data[], int32_t ix0, int32_t iy0);
  void xzlarf(int32_t m, int32_t n, int32_t iv0, double tau, double C_data[],
              int32_t ic0, int32_t ldc, double work[3]);
  void qrpf(double A_data[], const int32_t A_size[2], int32_t m, double
            tau_data[], int32_t jpvt[3]);
  void xgeqp3(double A_data[], int32_t A_size[2], double tau_data[], int32_t
              *tau_size, int32_t jpvt[3]);
  void qrsolve(const double A_data[], const int32_t A_size[2], const double
               B_data[], const int32_t *B_size, double Y[3], int32_t *rankA);
  void polyfit(const double x_data[], const int32_t *x_size, const double
               y_data[], const int32_t *y_size, double p[3]);

  // Real-Time Model
  RT_MODEL rtM;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S27>/Kb' : Eliminated nontunable gain of 1


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
//  '<Root>' : 'LKAS'
//  '<S1>'   : 'LKAS/PID Controller'
//  '<S2>'   : 'LKAS/Perception Unit'
//  '<S3>'   : 'LKAS/PID Controller/Anti-windup'
//  '<S4>'   : 'LKAS/PID Controller/D Gain'
//  '<S5>'   : 'LKAS/PID Controller/Filter'
//  '<S6>'   : 'LKAS/PID Controller/Filter ICs'
//  '<S7>'   : 'LKAS/PID Controller/I Gain'
//  '<S8>'   : 'LKAS/PID Controller/Ideal P Gain'
//  '<S9>'   : 'LKAS/PID Controller/Ideal P Gain Fdbk'
//  '<S10>'  : 'LKAS/PID Controller/Integrator'
//  '<S11>'  : 'LKAS/PID Controller/Integrator ICs'
//  '<S12>'  : 'LKAS/PID Controller/N Copy'
//  '<S13>'  : 'LKAS/PID Controller/N Gain'
//  '<S14>'  : 'LKAS/PID Controller/P Copy'
//  '<S15>'  : 'LKAS/PID Controller/Parallel P Gain'
//  '<S16>'  : 'LKAS/PID Controller/Reset Signal'
//  '<S17>'  : 'LKAS/PID Controller/Saturation'
//  '<S18>'  : 'LKAS/PID Controller/Saturation Fdbk'
//  '<S19>'  : 'LKAS/PID Controller/Sum'
//  '<S20>'  : 'LKAS/PID Controller/Sum Fdbk'
//  '<S21>'  : 'LKAS/PID Controller/Tracking Mode'
//  '<S22>'  : 'LKAS/PID Controller/Tracking Mode Sum'
//  '<S23>'  : 'LKAS/PID Controller/Tsamp - Integral'
//  '<S24>'  : 'LKAS/PID Controller/Tsamp - Ngain'
//  '<S25>'  : 'LKAS/PID Controller/postSat Signal'
//  '<S26>'  : 'LKAS/PID Controller/preSat Signal'
//  '<S27>'  : 'LKAS/PID Controller/Anti-windup/Back Calculation'
//  '<S28>'  : 'LKAS/PID Controller/D Gain/Internal Parameters'
//  '<S29>'  : 'LKAS/PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S30>'  : 'LKAS/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S31>'  : 'LKAS/PID Controller/I Gain/Internal Parameters'
//  '<S32>'  : 'LKAS/PID Controller/Ideal P Gain/Passthrough'
//  '<S33>'  : 'LKAS/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S34>'  : 'LKAS/PID Controller/Integrator/Discrete'
//  '<S35>'  : 'LKAS/PID Controller/Integrator ICs/Internal IC'
//  '<S36>'  : 'LKAS/PID Controller/N Copy/Disabled'
//  '<S37>'  : 'LKAS/PID Controller/N Gain/Internal Parameters'
//  '<S38>'  : 'LKAS/PID Controller/P Copy/Disabled'
//  '<S39>'  : 'LKAS/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S40>'  : 'LKAS/PID Controller/Reset Signal/Disabled'
//  '<S41>'  : 'LKAS/PID Controller/Saturation/Enabled'
//  '<S42>'  : 'LKAS/PID Controller/Saturation Fdbk/Disabled'
//  '<S43>'  : 'LKAS/PID Controller/Sum/Sum_PID'
//  '<S44>'  : 'LKAS/PID Controller/Sum Fdbk/Disabled'
//  '<S45>'  : 'LKAS/PID Controller/Tracking Mode/Disabled'
//  '<S46>'  : 'LKAS/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S47>'  : 'LKAS/PID Controller/Tsamp - Integral/TsSignalSpecification'
//  '<S48>'  : 'LKAS/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S49>'  : 'LKAS/PID Controller/postSat Signal/Forward_Path'
//  '<S50>'  : 'LKAS/PID Controller/preSat Signal/Forward_Path'
//  '<S51>'  : 'LKAS/Perception Unit/MATLAB Function1'
//  '<S52>'  : 'LKAS/Perception Unit/MATLAB Function2'
//  '<S53>'  : 'LKAS/Perception Unit/MATLAB Function3'
//  '<S54>'  : 'LKAS/Perception Unit/MATLAB Function4'
//  '<S55>'  : 'LKAS/Perception Unit/MATLAB Function6'

#endif                                 // RTW_HEADER_LKAS_h_

//
// File trailer for generated code.
//
// [EOF]
//
