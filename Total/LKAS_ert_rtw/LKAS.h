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
// C/C++ source code generated on : Wed Feb 28 11:59:13 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Emulation hardware selection:
//    Differs from embedded hardware (MATLAB Host)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_LKAS_h_
#define RTW_HEADER_LKAS_h_
#include <stdlib.h>
#include <time.h>
#include "rtwtypes.h"
#include "libmwimterp2d.h"
#include "HostLib_MMFile.h"
#include "HostLib_Multimedia.h"
#include "vipsvd_rt.h"
#include "coder_array.h"
#include <stddef.h>

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

#define LKAS_M                         (rtM)

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

#ifndef struct_c_projective2d
#define struct_c_projective2d

struct c_projective2d
{
  real_T T[9];
};

#endif                                 // struct_c_projective2d

#ifndef struct_vision_internal_blocks_Warp
#define struct_vision_internal_blocks_Warp

struct vision_internal_blocks_Warp
{
  int32_T isInitialized;
  c_projective2d TformProjective;
};

#endif                                 // struct_vision_internal_blocks_Warp

// Block signals and states (default storage) for system '<Root>'
struct DW {
  coder::array<real_T,2> a__1;
  coder::array<real_T,2> locs;
  coder::array<int32_T,1> d_i;
  coder::array<int16_T,1> e_j;
  coder::array<boolean_T,1> t;
  coder::array<boolean_T,1> v;
  coder::array<real_T,1> s_tmp;
  coder::array<boolean_T,1> b_tmp;
  coder::array<boolean_T,1> b_tmp_tmp;
  coder::array<boolean_T,1> r;
  coder::array<boolean_T,1> r1;
  coder::array<boolean_T,1> r2;
  coder::array<boolean_T,1> r3;
  coder::array<boolean_T,1> r4;
  coder::array<boolean_T,1> r5;
  coder::array<boolean_T,1> r6;
  coder::array<boolean_T,1> r7;
  coder::array<boolean_T,1> r8;
  coder::array<boolean_T,1> r9;
  coder::array<int32_T,2> r10;
  coder::array<int32_T,1> r11;
  coder::array<int32_T,1> r12;
  coder::array<int32_T,1> r13;
  coder::array<int32_T,1> r14;
  coder::array<int32_T,1> r15;
  coder::array<int32_T,1> r16;
  coder::array<real_T,1> left_lane_index;
  coder::array<real_T,2> V;
  coder::array<real_T,1> B_m;
  coder::array<real_T,1> tau;
  coder::array<int32_T,1> iPk;
  coder::array<int32_T,1> idx;
  coder::array<int32_T,1> fPk;
  coder::array<int16_T,1> iInfinite;
  coder::array<int32_T,1> b_iPk;
  coder::array<int32_T,2> y;
  coder::array<int32_T,1> iPk_c;
  vision_internal_blocks_Warp obj;     // '<S2>/Warp'
  real_T ColorSpaceConversion[2700000];// '<S2>/Color Space  Conversion'
  real_T FromMultimediaFile_HostLib[137];// '<Root>/From Multimedia File'
  real_T FromMultimediaFile_AudioInfo[5];// '<Root>/From Multimedia File'
  real_T FromMultimediaFile_VideoInfo[11];// '<Root>/From Multimedia File'
  real_T ColorSpaceConversion_DWORK1[2700000];// '<S2>/Color Space  Conversion'
  real_T xleft[751];
  real_T xright[751];
  real_T S_Channel[900000];            // '<S2>/MATLAB Function4'
  real_T nz[1200];
  real_T ImageDataTypeConversion[2700000];
  real_T b_varargout_1[900000];
  real_T xp[900000];
  real_T yp[900000];
  real_T RV[81];
  real_T EstimateGeometricTransformation_DW_CONSTRT_ALL[72];
                                    // '<S2>/Estimate Geometric Transformation'
  real_T Constraint[72];
  real_T Q[72];
  real_T EstimateGeometricTransformation[9];
                                    // '<S2>/Estimate Geometric Transformation'
  real_T bestTFormCompact[9];
  real_T tformCompact[9];
  real_T tformCompact_k[9];
  real_T pts1[8];                      // '<S2>/MATLAB Function1'
  real_T pts2[8];                      // '<S2>/MATLAB Function2'
  real_T EstimateGeometricTransformation_DW_PTSNORM1[8];
                                    // '<S2>/Estimate Geometric Transformation'
  real_T EstimateGeometricTransformation_DW_PTSNORM2[8];
                                    // '<S2>/Estimate Geometric Transformation'
  real_T E[8];
  real_T Qraux[8];
  real_T Work[8];
  real_T EstimateGeometricTransformation_DW_DISTANCE[4];
                                    // '<S2>/Estimate Geometric Transformation'
  real_T p[3];
  real_T b_p[3];
  real_T work[3];
  real_T vn1[3];
  real_T vn2[3];
  real_T cents1[2];
  real_T cents2[2];
  real_T B_c[9];
  real_T x[9];
  real_T b_inputImageSize[3];
  real_T b_outputImageSize[2];
  real_T Integrator_DSTATE;            // '<S34>/Integrator'
  real_T Filter_DSTATE;                // '<S29>/Filter'
  real_T leftx_current;
  real_T rightx_current;
  real_T count_right;
  real_T bestInlierDis;
  real_T s1DivS2;
  real_T ImageDataTypeConversion_b;
  real_T ImageDataTypeConversion_p;
  real_T ImageDataTypeConversion_c;
  real_T wj;
  real_T smax;
  real_T s;
  real_T vn1_f;
  real_T scale;
  real_T absxk;
  real_T t_g;
  real_T ykfirst;
  real_T yk;
  real_T u1;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  real_T B_g;
  real_T B_me;
  real_T B_n;
  real_T b_B_idx_0;
  real_T b_B_idx_1;
  real_T b_B_idx_2;
  real_T t_p;
  real_T nrmxl;
  real_T maxnrm;
  real_T tt;
  real_T tmpQRSL;
  real_T d;
  real_T d1;
  real_T a;
  real_T b;
  real32_T FromMultimediaFile[2700000];// '<Root>/From Multimedia File'
  int32_T left_lane_index_l[200000];
  int32_T right_lane_index[200000];
  int32_T JPVT[8];
  int32_T jpvt[3];
  int32_T win_y_high;
  int32_T xpageoffset;
  int32_T i;
  int32_T m;
  int32_T j;
  int32_T end;
  int32_T trueCount;
  int32_T nz_j;
  int32_T assumedRank;
  int32_T mn;
  int32_T b_mn;
  int32_T b_j;
  int32_T c_i;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T m_d;
  int32_T minmana;
  int32_T ma;
  int32_T ii;
  int32_T mmi;
  int32_T pvt;
  int32_T itemp;
  int32_T b_j_g;
  int32_T ix;
  int32_T iy;
  int32_T knt;
  int32_T e;
  int32_T jy;
  int32_T d_ix;
  int32_T kend;
  int32_T k;
  int32_T nPk;
  int32_T nInf;
  int32_T kfirst;
  int32_T k_l;
  int32_T fPk_d;
  int32_T na;
  int32_T nb;
  int32_T ncmax;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  int32_T itmp;
  int32_T j_d;
  int32_T L;
  int32_T ps;
  int32_T L_tmp;
  int32_T j_l;
  uint32_T EstimateGeometricTransformation_DW_SAMPLEIDX[4];
                                    // '<S2>/Estimate Geometric Transformation'
  uint32_T bestCol;
  uint32_T s1DivS2_tmp;
  int8_T EstimateGeometricTransformation_DW_BEST_SAMPLE[4];
                                    // '<S2>/Estimate Geometric Transformation'
  uint8_T inputImage_[900000];
  uint8_T outputImage[900000];
  uint8_T fillValues;
  boolean_T bv[900000];
  boolean_T rtb_S_Channel_o[900000];
  boolean_T x_b[2];
  boolean_T y_n;
};

// External outputs (root outports fed by signals with default storage)
struct ExtY {
  real_T Out1;                         // '<Root>/Out1'
};

// Parameters (default storage)
struct P_ {
  real_T PIDController_D;              // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S28>/Derivative Gain'

  real_T PIDController_I;              // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S31>/Integral Gain'

  real_T PIDController_InitialConditionForFilter;
                      // Mask Parameter: PIDController_InitialConditionForFilter
                         //  Referenced by: '<S29>/Filter'

  real_T PIDController_InitialConditionForIntegrator;
                  // Mask Parameter: PIDController_InitialConditionForIntegrator
                     //  Referenced by: '<S34>/Integrator'

  real_T PIDController_Kb;             // Mask Parameter: PIDController_Kb
                                          //  Referenced by: '<S27>/Kb'

  real_T PIDController_LowerSaturationLimit;
                           // Mask Parameter: PIDController_LowerSaturationLimit
                              //  Referenced by: '<S41>/Saturation'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S37>/Filter Coefficient'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S39>/Proportional Gain'

  real_T PIDController_UpperSaturationLimit;
                           // Mask Parameter: PIDController_UpperSaturationLimit
                              //  Referenced by: '<S41>/Saturation'

  real_T EstimateGeometricTransformation_distanceAlg;
                  // Mask Parameter: EstimateGeometricTransformation_distanceAlg
                     //  Referenced by: '<S2>/Estimate Geometric Transformation'

  uint32_T EstimateGeometricTransformation_sampleNum;
                    // Mask Parameter: EstimateGeometricTransformation_sampleNum
                       //  Referenced by: '<S2>/Estimate Geometric Transformation'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S34>/Integrator'

  real_T Filter_gainval;               // Computed Parameter: Filter_gainval
                                          //  Referenced by: '<S29>/Filter'

};

// Parameters (default storage)
typedef struct P_ P;

// Real-time Model Data Structure
struct tag_RTM {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P rtP;

#ifdef __cplusplus

}

#endif

// Block signals and states (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct DW rtDW;

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY rtY;

#ifdef __cplusplus

}

#endif

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void LKAS_initialize(void);
  extern void LKAS_step(void);

#ifdef __cplusplus

}

#endif

extern "C"
{
  static real_T rtGetInf(void);
  static real32_T rtGetInfF(void);
  static real_T rtGetMinusInf(void);
  static real32_T rtGetMinusInfF(void);
}                                      // extern "C"

extern "C"
{
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"

#define NOT_USING_NONFINITE_LITERALS   1

extern "C"
{
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static void rt_InitInfAndNaN(size_t realSize);
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
  struct BigEndianIEEEDouble {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  };

  struct LittleEndianIEEEDouble {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  };

  struct IEEESingle {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  };
}                                      // extern "C"

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL *const rtM;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
