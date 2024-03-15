//
//  Rpi_cam.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "Rpi_cam".
//
//  Model version              : 1.94
//  Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
//  C++ source code generated on : Tue Mar 12 16:09:41 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: Intel->x86-64 (Linux 64)
//  Code generation objectives:
//     1. Execution efficiency
//     2. RAM efficiency
//  Validation result: Not run


#ifndef RTW_HEADER_Rpi_cam_h_
#define RTW_HEADER_Rpi_cam_h_
#include <stdbool.h>
#include <stdint.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "libmwimterp2d.h"
#include "MW_availableWebcam.h"
#include "MW_v4l2_cam.h"
#include "vipsvd_rt.h"
#include "providedinterface_skeleton.h"
#include <stddef.h>
#include <array>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <memory>
#ifndef struct_codertarget_raspi_internal_Raspiv4l2Capture
#define struct_codertarget_raspi_internal_Raspiv4l2Capture

struct codertarget_raspi_internal_Raspiv4l2Capture
{
  bool matlabCodegenIsDeleted;
  int32_t isInitialized;
  bool isSetupComplete;
  double Brightness;
  double Saturation;
  double Contrast;
  double Sharpness;
  double CameraZoom;
  double ManualFocus;
  double CameraPan;
  double CameraTilt;
  double BrightnessInternal;
  double SaturationInternal;
  double ContrastInternal;
  double SharpnessInternal;
  double CameraZoomInternal;
  double ManualFocusInternal;
  double CameraPanInternal;
  double CameraTiltInternal;
  bool EnableManualFocusInternal;
};

#endif                    // struct_codertarget_raspi_internal_Raspiv4l2Capture

#ifndef struct_c_projective2d
#define struct_c_projective2d

struct c_projective2d
{
  std::array<double, 9> T;
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

// Class declaration for model Rpi_cam
class Rpi_cam final
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW {
    codertarget_raspi_internal_Raspiv4l2Capture obj;// '<Root>/V4L2 Video Capture' 
    vision_internal_blocks_Warp obj_k; // '<S4>/Warp'
    std::array<double, 921600> ColorSpaceConversion;// '<S4>/Color Space  Conversion' 
    std::array<double, 921600> ColorSpaceConversion_DWORK1;// '<S4>/Color Space  Conversion' 
    std::array<double, 200000> left_lane_index;
    std::array<double, 200000> right_lane_index;
    std::array<double, 307200> V_Channel;// '<S4>/MATLAB Function7'
    double jj_data[307200];
    double left_lane_index_data[100000];
    double left_lane_index_data_m[100000];
    std::array<double, 921600> ImageDataTypeConversion;
    std::array<double, 307200> b_varargout_1;
    std::array<double, 307200> xp;
    std::array<double, 307200> yp;
    double V_data[300000];
    double b_A_data[300000];
    double b_B_data[100000];
    double b_A_data_c[300000];
    std::array<double, 481> xleft;
    std::array<double, 481> xright;
    std::array<double, 81> RV;
    std::array<double, 72> EstimateGeometricTransformation_DW_CONSTRT_ALL;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<double, 72> Constraint;
    std::array<double, 72> Q;
    std::array<double, 9> EstimateGeometricTransformation;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<double, 9> bestTFormCompact;
    std::array<double, 9> tformCompact;
    std::array<double, 9> tformCompact_k;
    std::array<double, 8> pts1;        // '<S4>/MATLAB Function1'
    std::array<double, 8> pts2;        // '<S4>/MATLAB Function2'
    std::array<double, 8> EstimateGeometricTransformation_DW_PTSNORM1;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<double, 8> EstimateGeometricTransformation_DW_PTSNORM2;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<double, 8> E;
    std::array<double, 8> Qraux;
    std::array<double, 8> Work;
    std::array<double, 4> EstimateGeometricTransformation_DW_DISTANCE;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<double, 3> p;
    std::array<double, 3> b_p;
    double tau_data[3];
    std::array<double, 3> work;
    std::array<double, 3> vn1;
    std::array<double, 3> vn2;
    std::array<double, 2> cents1;
    std::array<double, 2> cents2;
    std::array<double, 9> B_c;
    std::array<double, 9> x;
    std::array<double, 3> b_inputImageSize;
    std::array<double, 2> b_outputImageSize;
    double count_right;
    double win_y_low;
    double win_y_high;
    double x_current;
    double y_current;
    double bestInlierDis;
    double ImageDataTypeConversion_b;
    double ImageDataTypeConversion_p;
    double tol;
    double smax;
    double s;
    double vn1_c;
    double c;
    double absx11;
    double absx21;
    double absx31;
    double B_f;
    double B_g;
    double B_g1;
    double b_B_idx_0;
    double b_B_idx_1;
    double b_B_idx_2;
    double t;
    double nrmxl;
    double maxnrm;
    double tt;
    double tmpQRSL;
    double d;
    double d1;
    double scale;
    double absxk;
    double t_m;
    double temp;
    double a;
    double b;
    int32_t ii_data[307200];
    int32_t jj_data_n[307200];
    int32_t n_tmp_data[307200];
    int32_t tmp_data[307200];
    int32_t tmp_data_p[307200];
    int32_t tmp_data_l[307200];
    int32_t tmp_data_j[307200];
    int32_t tmp_data_d[307200];
    int32_t tmp_data_g[307200];
    int32_t tmp_data_ld[307200];
    int32_t tmp_data_dh[307200];
    int32_t tmp_data_dy[307200];
    int32_t tmp_data_lx[307200];
    int32_t tmp_data_o[307200];
    int32_t tmp_data_b[307200];
    int32_t tmp_data_n[307200];
    int32_t tmp_data_bs[307200];
    std::array<int32_t, 8> JPVT;
    std::array<int32_t, 3> jpvt;
    int32_t V_size[2];
    int32_t b_A_size[2];
    int32_t b_A_size_l[2];
    int32_t j;
    int32_t d_j;
    int32_t inlierNum;
    int32_t i;
    int32_t svdRsltVar;
    int32_t end;
    int32_t partialTrueCount;
    int32_t outputImage_tmp;
    int32_t b_size;
    int32_t ii_size;
    int32_t jj_size;
    int32_t r_size;
    int32_t t_size;
    int32_t b_tmp_size;
    int32_t b_tmp_tmp_size;
    int32_t tmp_size;
    int32_t tmp_size_h;
    int32_t tmp_size_b;
    int32_t tmp_size_d;
    int32_t tmp_size_e;
    int32_t tmp_size_bj;
    int32_t tmp_size_j;
    int32_t tmp_size_f;
    int32_t tmp_size_a;
    int32_t tmp_size_ju;
    int32_t tmp_size_jz;
    int32_t tmp_size_o;
    int32_t tmp_size_n;
    int32_t tmp_size_i;
    int32_t tmp_size_oy;
    int32_t tmp_size_nv;
    int32_t tmp_size_m;
    int32_t tmp_size_c;
    int32_t tmp_size_md;
    int32_t tmp_size_m3;
    int32_t tmp_size_ja;
    int32_t tmp_size_h5;
    int32_t jj_size_c;
    int32_t left_lane_index_size;
    int32_t left_lane_index_size_c;
    int32_t n_tmp_size_idx_0;
    int32_t b_px;
    int32_t k;
    int32_t scalarLB;
    int32_t vectorUB;
    int32_t minmn;
    int32_t maxmn;
    int32_t k_p;
    int32_t b_j;
    int32_t c_i;
    int32_t scalarLB_a;
    int32_t vectorUB_e;
    int32_t tau_size;
    int32_t b_A;
    int32_t i_a;
    int32_t loop_ub;
    int32_t ma;
    int32_t ii;
    int32_t mmi;
    int32_t pvt;
    int32_t itemp;
    int32_t j_a;
    int32_t b_i;
    int32_t ix;
    int32_t knt;
    int32_t vectorUB_l;
    int32_t vectorUB_tmp;
    int32_t lastv;
    int32_t i_o;
    int32_t lastc;
    int32_t d_o;
    int32_t e;
    int32_t jA;
    int32_t jy;
    int32_t p1;
    int32_t j_i;
    int32_t kend;
    int32_t k_f;
    int32_t k_i;
    int32_t temp_tmp;
    int32_t i1;
    std::array<uint32_t, 4> EstimateGeometricTransformation_DW_SAMPLEIDX;
                                    // '<S4>/Estimate Geometric Transformation'
    uint32_t bestCol;
    uint32_t win_y_low_tmp;
    std::array<char, 101> b_errorMessage;
    std::array<char, 18> i_f;
    std::array<char, 12> devName;
    std::array<int8_t, 4> EstimateGeometricTransformation_DW_BEST_SAMPLE;
                                    // '<S4>/Estimate Geometric Transformation'
    std::array<uint8_t, 921600> outputImage;// '<Root>/MATLAB Function'
    std::array<uint8_t, 307200> b_varargout_3;
    std::array<uint8_t, 307200> b_varargout_2;
    std::array<uint8_t, 307200> b_varargout_1_g;
    std::array<uint8_t, 307200> b_varargout_1_c;
    std::array<uint8_t, 307200> inputImage_;
    std::array<uint8_t, 307200> outputImage_o;
    uint8_t xtmp;
    std::array<bool, 307200> Warp;     // '<S4>/Warp'
    std::array<bool, 307200> bv;
    bool b_data[307200];
    bool r_data[307200];
    bool t_data[307200];
    bool b_tmp_data[307200];
    bool b_tmp_tmp_data[307200];
    bool tmp_data_lm[307200];
    bool tmp_data_m[307200];
    bool tmp_data_mj[307200];
    bool tmp_data_c[307200];
    bool tmp_data_f[307200];
    bool tmp_data_p4[307200];
    bool tmp_data_e[307200];
    bool tmp_data_o4[307200];
    bool tmp_data_h[307200];
    bool tmp_data_l5[307200];
    bool tmp_data_h2[307200];
    bool tmp_data_me[307200];
    bool tmp_data_mc[307200];
    bool tmp_data_h3[307200];
    bool tmp_data_cs[307200];
    bool tmp_data_k[307200];
    bool tmp_data_pc[307200];
    bool tmp_data_px[307200];
    bool tmp_data_p4u[307200];
    bool tmp_data_a[307200];
    bool tmp_data_jd[307200];
    bool tmp_data_ek[307200];
    std::array<bool, 307200> rtb_V_Channel_o;
    bool in1_data[307200];
    bool in1_data_b[307200];
  };

  // Copy Constructor
  Rpi_cam(Rpi_cam const&) = delete;

  // Assignment Operator
  Rpi_cam& operator= (Rpi_cam const&) & = delete;

  // Move Constructor
  Rpi_cam(Rpi_cam &&) = delete;

  // Move Assignment Operator
  Rpi_cam& operator= (Rpi_cam &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  Rpi_cam();

  // Destructor
  ~Rpi_cam();

  // private data and function members
 private:
  // Block states
  DW rtDW;
  std::shared_ptr<skeleton::ProvidedInterfaceSkeleton> ProvidedPort;

  // private member function(s) for subsystem '<Root>'
  void v4l2Capture_updateV4L2Settings
    (codertarget_raspi_internal_Raspiv4l2Capture *obj, bool forceUpdate);
  void SystemCore_step(codertarget_raspi_internal_Raspiv4l2Capture *obj, uint8_t
                       varargout_1[307200], uint8_t varargout_2[307200], uint8_t
                       varargout_3[307200]);
  void QRV2Norm_double_o(const double V[], int32_t N, double v2norm[]);
  void QRDC_double_o(double xVec[], double qrAux[], int32_t jpvt[], double work[],
                     int32_t M, int32_t N);
  void QRE_double_o(double outQ[], double outR[], double outE[], double qrAux[],
                    double work[], int32_t jpvt[], double sPtr[], int32_t M,
                    int32_t N, bool economy);
  void Warp_stepImpl(vision_internal_blocks_Warp *b_this, const bool Image
                     [307200], const double input2[9], bool Jout[307200]);
  void eml_find(const bool x[307200], int32_t i_data[], int32_t *i_size, int32_t
                j_data[], int32_t *j_size);
  void binary_expand_op_5(bool in1_data[], int32_t *in1_size, const bool
    in2_data[], const int32_t *in2_size, const int32_t in3_data[], const int32_t
    *in3_size);
  void binary_expand_op_4(bool in1_data[], int32_t *in1_size, const int32_t
    in2_data[], const int32_t *in2_size);
  void and_o(bool in1_data[], int32_t *in1_size, const bool in2_data[], const
             int32_t *in2_size, const bool in3_data[], const int32_t *in3_size);
  double mean(const double x_data[], const int32_t *x_size);
  double maximum(const double x_data[], const int32_t *x_size);
  void binary_expand_op_1(bool in1_data[], int32_t *in1_size, const bool
    in2_data[], const int32_t *in2_size, const bool in3_data[], const bool
    in4_data[], const int32_t *in4_size);
  void binary_expand_op(bool in1_data[], int32_t *in1_size, const bool in2_data[],
                        const bool in3_data[], const int32_t *in3_size);
  double xnrm2(int32_t n, const double x_data[], int32_t ix0);
  void xswap(int32_t n, double x_data[], int32_t ix0, int32_t iy0);
  double rt_hypotd_snf_o(double u0, double u1);
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
  codertarget_raspi_internal_Raspiv4l2Capture *Raspiv4l2Capture_Raspiv4l2Capture
    (codertarget_raspi_internal_Raspiv4l2Capture *obj);
  void SystemCore_setup(codertarget_raspi_internal_Raspiv4l2Capture *obj);
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
//  '<Root>' : 'Rpi_cam'
//  '<S1>'   : 'Rpi_cam/MATLAB Function'
//  '<S2>'   : 'Rpi_cam/Perception Unit'
//  '<S3>'   : 'Rpi_cam/RGB to Image'
//  '<S4>'   : 'Rpi_cam/Perception Unit/Image Processing'
//  '<S5>'   : 'Rpi_cam/Perception Unit/MATLAB Function1'
//  '<S6>'   : 'Rpi_cam/Perception Unit/check src points'
//  '<S7>'   : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function1'
//  '<S8>'   : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function2'
//  '<S9>'   : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function7'
//  '<S10>'  : 'Rpi_cam/Perception Unit/Image Processing/MATLAB Function8'

#endif                                 // RTW_HEADER_Rpi_cam_h_
