#ifndef __c10_Rpi_cam_h__
#define __c10_Rpi_cam_h__

/* Forward Declarations */
struct SFc10_Rpi_camInstanceStruct;

/* Type Definitions */
#ifndef typedef_c10_Rpi_camStackData
#define typedef_c10_Rpi_camStackData

typedef struct {
} c10_Rpi_camStackData;

#endif                                 /* typedef_c10_Rpi_camStackData */

#ifndef struct_SFc10_Rpi_camInstanceStruct
#define struct_SFc10_Rpi_camInstanceStruct

struct SFc10_Rpi_camInstanceStruct
{
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c10_sfEvent;
  boolean_T c10_doneDoubleBufferReInit;
  uint8_T c10_is_active_c10_Rpi_cam;
  uint8_T c10_JITStateAnimation[1];
  uint8_T c10_JITTransitionAnimation[1];
  int32_T c10_IsDebuggerActive;
  int32_T c10_IsSequenceViewerPresent;
  int32_T c10_SequenceViewerOptimization;
  int32_T c10_IsHeatMapPresent;
  void *c10_RuntimeVar;
  uint32_T c10_mlFcnLineNumber;
  void *c10_fcnDataPtrs[36];
  const char_T *c10_dataNames[36];
  uint32_T c10_numFcnVars;
  uint32_T c10_ssIds[36];
  uint32_T c10_statuses[36];
  void *c10_outMexFcns[36];
  void *c10_inMexFcns[36];
  boolean_T c10_bv[307200];
  CovrtStateflowInstance *c10_covrtInstance;
  void *c10_fEmlrtCtx;
  real_T (*c10_mean_points)[3];
  real_T (*c10_rectangle_points)[168];
  boolean_T (*c10_binary_image)[307200];
  real_T *c10_error;
  real_T *c10_x_location;
};

#endif                                 /* struct_SFc10_Rpi_camInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c10_Rpi_cam_get_eml_resolved_functions_info();

/* Function Definitions */
extern void sf_c10_Rpi_cam_get_check_sum(mxArray *plhs[]);
extern void c10_Rpi_cam_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
