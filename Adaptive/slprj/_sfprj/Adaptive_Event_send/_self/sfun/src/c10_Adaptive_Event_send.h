#ifndef __c10_Adaptive_Event_send_h__
#define __c10_Adaptive_Event_send_h__

/* Forward Declarations */
struct SFc10_Adaptive_Event_sendInstanceStruct;

/* Type Definitions */
#ifndef typedef_c10_Adaptive_Event_sendStackData
#define typedef_c10_Adaptive_Event_sendStackData

struct c10_Adaptive_Event_sendStackData
{
};

#endif                                 /* typedef_c10_Adaptive_Event_sendStackData */

#ifndef struct_SFc10_Adaptive_Event_sendInstanceStruct
#define struct_SFc10_Adaptive_Event_sendInstanceStruct

struct SFc10_Adaptive_Event_sendInstanceStruct
{
  SimStruct *S;
  ChartInfoStruct chartInfo;
  int32_T c10_sfEvent;
  boolean_T c10_doneDoubleBufferReInit;
  uint8_T c10_is_active_c10_Adaptive_Event_send;
  uint8_T c10_JITStateAnimation[1];
  uint8_T c10_JITTransitionAnimation[1];
  real_T c10_nonzerox_data[307200];
  int32_T c10_ii_data[307200];
  int32_T c10_jj_data[307200];
  int32_T c10_nonzeroy_data[307200];
  int32_T c10_tmp_data[307200];
  int32_T c10_b_tmp_data[307200];
  int32_T c10_c_tmp_data[307200];
  int32_T c10_d_tmp_data[307200];
  int32_T c10_e_tmp_data[307200];
  int32_T c10_f_tmp_data[307200];
  int32_T c10_g_tmp_data[307200];
  int32_T c10_h_tmp_data[307200];
  boolean_T c10_i_tmp_data[307200];
  boolean_T c10_j_tmp_data[307200];
  boolean_T c10_k_tmp_data[307200];
  boolean_T c10_m_tmp_data[307200];
  boolean_T c10_o_tmp_data[307200];
  boolean_T c10_p_tmp_data[307200];
  boolean_T c10_q_tmp_data[307200];
  boolean_T c10_r_tmp_data[307200];
  boolean_T c10_s_tmp_data[307200];
  boolean_T c10_t_tmp_data[307200];
  boolean_T c10_u_tmp_data[307200];
  boolean_T c10_v_tmp_data[307200];
  boolean_T c10_w_tmp_data[307200];
  boolean_T c10_in2_data[307200];
  boolean_T c10_in1_data[307200];
  void *c10_fEmlrtCtx;
  boolean_T (*c10_binary_image)[307200];
  real_T *c10_error;
};

#endif                                 /* struct_SFc10_Adaptive_Event_sendInstanceStruct */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c10_Adaptive_Event_send_get_eml_resolved_functions_info
  ();

/* Function Definitions */
extern void sf_c10_Adaptive_Event_send_get_check_sum(mxArray *plhs[]);
extern void c10_Adaptive_Event_send_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
