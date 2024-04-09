//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Perception.h
//
// Code generated for Simulink model 'Perception'.
//
// Model version                  : 1.6
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Mar  1 10:44:42 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_Perception_h_
#define RTW_HEADER_Perception_h_
#include <stdlib.h>
#include <time.h>
#include "rtwtypes.h"
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

#define Perception_M                   (rtM)

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
  coder::array<int32_T,1> ii;
  coder::array<int32_T,1> jj;
  coder::array<boolean_T,1> o;
  coder::array<boolean_T,1> r;
  coder::array<real_T,1> n_tmp;
  coder::array<boolean_T,1> b_tmp;
  coder::array<boolean_T,1> b_tmp_tmp;
  coder::array<boolean_T,1> r_m;
  coder::array<boolean_T,1> r1;
  coder::array<boolean_T,1> r2;
  coder::array<boolean_T,1> r3;
  coder::array<boolean_T,1> r4;
  coder::array<boolean_T,1> r5;
  coder::array<boolean_T,1> r6;
  coder::array<boolean_T,1> r7;
  coder::array<boolean_T,1> r8;
  coder::array<boolean_T,1> r9;
  coder::array<int32_T,1> r10;
  coder::array<int32_T,1> r11;
  coder::array<int32_T,1> r12;
  coder::array<int32_T,1> r13;
  coder::array<int32_T,1> r14;
  coder::array<int32_T,1> r15;
  coder::array<real_T,1> left_lane_index;
  coder::array<real_T,1> left_lane_index_c;
  coder::array<real_T,2> V;
  coder::array<real_T,2> b_A;
  coder::array<real_T,1> b_B;
  coder::array<real_T,2> b_A_k;
  vision_internal_blocks_Warp obj;     // '<S1>/Warp'
  real_T ColorSpaceConversion[2700000];// '<S1>/Color Space  Conversion'
  real_T FromMultimediaFile_HostLib[137];// '<Root>/From Multimedia File'
  real_T FromMultimediaFile_AudioInfo[5];// '<Root>/From Multimedia File'
  real_T FromMultimediaFile_VideoInfo[11];// '<Root>/From Multimedia File'
  real_T ColorSpaceConversion_DWORK1[2700000];// '<S1>/Color Space  Conversion'
  real_T a__1_data[1200];
  real_T xleft[751];
  real_T xright[751];
  real_T locs_data[1200];
  real_T S_Channel[900000];            // '<S1>/MATLAB Function4'
  real_T nz[1200];
  real_T ImageDataTypeConversion[2700000];
  real_T srcXIntrinsic[900000];
  real_T srcYIntrinsic[900000];
  real_T RV[81];
  real_T EstimateGeometricTransformation_DW_CONSTRT_ALL[72];
                                    // '<S1>/Estimate Geometric Transformation'
  real_T Constraint[72];
  real_T Q[72];
  real_T EstimateGeometricTransformation[9];
                                    // '<S1>/Estimate Geometric Transformation'
  real_T bestTFormCompact[9];
  real_T tformCompact[9];
  real_T tformCompact_c[9];
  real_T pts1[8];                      // '<S1>/MATLAB Function1'
  real_T pts2[8];                      // '<S1>/MATLAB Function2'
  real_T EstimateGeometricTransformation_DW_PTSNORM1[8];
                                    // '<S1>/Estimate Geometric Transformation'
  real_T EstimateGeometricTransformation_DW_PTSNORM2[8];
                                    // '<S1>/Estimate Geometric Transformation'
  real_T E[8];
  real_T Qraux[8];
  real_T Work[8];
  real_T EstimateGeometricTransformation_DW_DISTANCE[4];
                                    // '<S1>/Estimate Geometric Transformation'
  real_T p[3];
  real_T b_p[3];
  real_T tau_data[3];
  real_T work[3];
  real_T vn1[3];
  real_T vn2[3];
  real_T cents1[2];
  real_T cents2[2];
  real_T tinv[9];
  real_T x[9];
  real_T leftx_current;
  real_T rightx_current;
  real_T count_right;
  real_T bestInlierDis;
  real_T s1DivS2;
  real_T ImageDataTypeConversion_b;
  real_T ImageDataTypeConversion_p;
  real_T ImageDataTypeConversion_c;
  real_T tol;
  real_T smax;
  real_T s;
  real_T vn1_f;
  real_T c;
  real_T absx11;
  real_T absx21;
  real_T absx31;
  real_T tinv_g;
  real_T tinv_g1;
  real_T tinv_m;
  real_T tinv_n;
  real_T tinv_p;
  real_T t;
  real_T nrmxl;
  real_T maxnrm;
  real_T tt;
  real_T tmpQRSL;
  real_T d;
  real_T d1;
  real_T ykfirst;
  real_T Yin;
  real_T scale;
  real32_T FromMultimediaFile[2700000];// '<Root>/From Multimedia File'
  int32_T left_lane_index_l[200000];
  int32_T right_lane_index[200000];
  int32_T fPk_data[1200];
  int32_T iPk_data[2400];
  int32_T b_iPk_data[1200];
  int32_T ib_data[1200];
  int32_T JPVT[8];
  int32_T jpvt[3];
  int32_T a__1_size[2];
  int32_T locs_size[2];
  int32_T tau_size[1];
  int32_T fPk_size[1];
  int32_T iPk_size[1];
  int32_T b_iPk_size[1];
  int32_T ib_size[1];
  int32_T iInfinite_size[1];
  int32_T s_j;
  int32_T i;
  int32_T m;
  int32_T j;
  int32_T end;
  int32_T trueCount;
  int32_T i_d;
  int32_T nz_g;
  int32_T b;
  int32_T k;
  int32_T minmn;
  int32_T maxmn;
  int32_T k_l;
  int32_T b_j;
  int32_T c_i;
  int32_T b_A_d;
  int32_T i_dy;
  int32_T loop_ub;
  int32_T ma;
  int32_T ii_l;
  int32_T mmi;
  int32_T pvt;
  int32_T j_o;
  int32_T L;
  int32_T ps;
  int32_T L_tmp;
  int32_T j_b;
  int32_T nPk;
  int32_T kfirst;
  int32_T k_n;
  int32_T fPk;
  int32_T na;
  int32_T nb;
  int32_T ncmax;
  uint32_T EstimateGeometricTransformation_DW_SAMPLEIDX[4];
                                    // '<S1>/Estimate Geometric Transformation'
  uint32_T bestCol;
  uint32_T s1DivS2_tmp;
  int16_T idx_data[2400];
  int16_T y_data[2400];
  int16_T tmp_data[1200];
  int8_T inputImage[900000];
  int8_T EstimateGeometricTransformation_DW_BEST_SAMPLE[4];
                                    // '<S1>/Estimate Geometric Transformation'
  boolean_T bv[900000];
  boolean_T rtb_S_Channel_b[900000];
};

// External outputs (root outports fed by signals with default storage)
struct ExtY {
  real_T Out1;                         // '<Root>/Out1'
};

// Parameters (default storage)
struct P_ {
  real_T EstimateGeometricTransformation_distanceAlg;
                  // Mask Parameter: EstimateGeometricTransformation_distanceAlg
                     //  Referenced by: '<S1>/Estimate Geometric Transformation'

  uint32_T EstimateGeometricTransformation_sampleNum;
                    // Mask Parameter: EstimateGeometricTransformation_sampleNum
                       //  Referenced by: '<S1>/Estimate Geometric Transformation'

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
  extern void Perception_initialize(void);
  extern void Perception_step(void);

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
//  '<Root>' : 'Perception'
//  '<S1>'   : 'Perception/Perception Unit'
//  '<S2>'   : 'Perception/Perception Unit/MATLAB Function1'
//  '<S3>'   : 'Perception/Perception Unit/MATLAB Function2'
//  '<S4>'   : 'Perception/Perception Unit/MATLAB Function3'
//  '<S5>'   : 'Perception/Perception Unit/MATLAB Function4'
//  '<S6>'   : 'Perception/Perception Unit/MATLAB Function6'

#endif                                 // RTW_HEADER_Perception_h_

//
// File trailer for generated code.
//
// [EOF]
//
