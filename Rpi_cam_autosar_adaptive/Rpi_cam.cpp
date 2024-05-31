

    

        /*
        * Rpi_cam.cpp
        *
                * Academic License - for use in teaching, academic research, and meeting
* course requirements at degree granting institutions only.  Not for
* government, commercial, or other organizational use.
        *
    * Code generation for model "Rpi_cam".
    *
    * Model version              : 2.0
    * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
        * C++ source code generated on : Fri May 31 15:27:45 2024
 * 
 * Target selection: autosar_adaptive.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: 
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
        */




    
#include "Rpi_cam.h"

#include <stdbool.h>

#include <stdint.h>

#include <cstring>

#include "makeConstraintMatrix_Projective_D_D.h"

#include "normPts_D_D.h"

#include "eml_find_7rUftLmJ.h"

#include "mean_uQukM2rh.h"

#include "maximum_4kJ3rROr.h"

#include <array>

#include <cmath>

#include "QRSL1_double.h"


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    
    

                
        
        
        
        
        
        
        

    

                        


         

                
                void Rpi_cam::v4l2Capture_updateV4L2Settings(codertarget_raspi_internal_Raspiv4l2Capture *obj, bool forceUpdate)
        {
            std::array<char, 11> b;
std::array<char, 9> c;
std::array<char, 10> e;
std::array<char, 12> j;
uint8_t status;
static const std::array<char, 11> b_0{ { 'B', 'r', 'i', 'g', 'h', 't', 'n', 'e', 's', 's', '\x00' } };
static const std::array<char, 9> c_0{ { 'C', 'o', 'n', 't', 'r', 'a', 's', 't', '\x00' } };
static const std::array<char, 11> d{ { 'S', 'a', 't', 'u', 'r', 'a', 't', 'i', 'o', 'n', '\x00' } };
static const std::array<char, 10> e_0{ { 'S', 'h', 'a', 'r', 'p', 'n', 'e', 's', 's', '\x00' } };
static const std::array<char, 10> f{ { 'C', 'a', 'm', 'e', 'r', 'a', 'P', 'a', 'n', '\x00' } };
static const std::array<char, 11> g{ { 'C', 'a', 'm', 'e', 'r', 'a', 'T', 'i', 'l', 't', '\x00' } };
static const std::array<char, 11> h{ { 'C', 'a', 'm', 'e', 'r', 'a', 'Z', 'o', 'o', 'm', '\x00' } };
static const std::array<char, 18> i_0{ { 'E', 'n', 'a', 'b', 'l', 'e', 'M', 'a', 'n', 'u', 'a', 'l', 'F', 'o', 'c', 'u', 's', '\x00' } };
static const std::array<char, 12> j_0{ { 'M', 'a', 'n', 'u', 'a', 'l', 'F', 'o', 'c', 'u', 's', '\x00' } };
/* {S!d546}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>10b961*/if ((/*@>195f7f*/obj->Brightness/*@>16903e*/ != /*@>195f82*/obj->BrightnessInternal)/*@>15c7d6*/ || /*@>195ed8*/forceUpdate) {
    /*@>195eda*/obj->/*@>1e5ffd*/BrightnessInternal/*@>10b976*/ = /*@>195edc*/obj->Brightness;
/*@>180544*/    for ( int32_t /*@>1e5dbf*/i{/*@>1e5dbe*/0}; /*@>1e5dc9*/i < /*@>1e5dc7*/11; /*@>1e5dc5*/i/*@>1e5dcd*/++) {
        /*@>195fba*/b/*@>18f2a7*/[/*@>195fb8*/i]/*@>180537*/ = /*@>1da848*/b_0/*@>1da84a*/[/*@>1da847*/i];
    }
    /*@>1d35b8*/EXT_updateV4L2Control(&/*@>195f35*/b/*@>18f2b7*/[/*@>196039*/0], static_cast<float>(/*@>195ede*/obj->Brightness), /*@>1b0db8*/0, &/*@>195ee0*/status);
}
/*@>10b9c1*/if ((/*@>195f85*/obj->Contrast/*@>16904a*/ != /*@>195f88*/obj->ContrastInternal)/*@>15c7d7*/ || /*@>195ee2*/forceUpdate) {
    /*@>195ee4*/obj->/*@>1e6000*/ContrastInternal/*@>10b9d6*/ = /*@>195ee6*/obj->Contrast;
/*@>180594*/    for ( int32_t /*@>1e5dae*/i{/*@>1e5dad*/0}; /*@>1e5db8*/i < /*@>1e5db6*/9; /*@>1e5db4*/i/*@>1e5dcf*/++) {
        /*@>195fc9*/c/*@>18f2c9*/[/*@>195fc7*/i]/*@>180587*/ = /*@>1da84e*/c_0/*@>1da850*/[/*@>1da84d*/i];
    }
    /*@>1d35ba*/EXT_updateV4L2Control(&/*@>195f3e*/c/*@>18f2da*/[/*@>19603a*/0], static_cast<float>(/*@>195ee8*/obj->Contrast), /*@>1b0dd1*/0, &/*@>195eea*/status);
}
/*@>10ba21*/if ((/*@>195f8b*/obj->Saturation/*@>169056*/ != /*@>195f8e*/obj->SaturationInternal)/*@>15c7d8*/ || /*@>195eec*/forceUpdate) {
    /*@>195eee*/obj->/*@>1e6003*/SaturationInternal/*@>10ba36*/ = /*@>195ef0*/obj->Saturation;
/*@>1805e5*/    for ( int32_t /*@>1e5d9d*/i{/*@>1e5d9c*/0}; /*@>1e5da7*/i < /*@>1e5da5*/11; /*@>1e5da3*/i/*@>1e5dd1*/++) {
        /*@>195fd8*/b/*@>18f2ea*/[/*@>195fd6*/i]/*@>1805d8*/ = /*@>1da854*/d/*@>1da856*/[/*@>1da853*/i];
    }
    /*@>1d35bc*/EXT_updateV4L2Control(&/*@>195f47*/b/*@>18f2fa*/[/*@>19603b*/0], static_cast<float>(/*@>195ef2*/obj->Saturation), /*@>1b0dea*/0, &/*@>195ef4*/status);
}
/*@>10ba81*/if ((/*@>195f91*/obj->Sharpness/*@>169062*/ != /*@>195f94*/obj->SharpnessInternal)/*@>15c7d9*/ || /*@>195ef6*/forceUpdate) {
    /*@>195ef8*/obj->/*@>1e6006*/SharpnessInternal/*@>10ba96*/ = /*@>195efa*/obj->Sharpness;
/*@>180636*/    for ( int32_t /*@>1e5d8c*/i{/*@>1e5d8b*/0}; /*@>1e5d96*/i < /*@>1e5d94*/10; /*@>1e5d92*/i/*@>1e5dd3*/++) {
        /*@>195fe7*/e/*@>18f30c*/[/*@>195fe5*/i]/*@>180629*/ = /*@>1da85a*/e_0/*@>1da85c*/[/*@>1da859*/i];
    }
    /*@>1d35be*/EXT_updateV4L2Control(&/*@>195f50*/e/*@>18f31c*/[/*@>19603c*/0], static_cast<float>(/*@>195efc*/obj->Sharpness), /*@>1b0e03*/0, &/*@>195efe*/status);
}
/*@>10bae1*/if ((/*@>195f97*/obj->CameraPan/*@>16906e*/ != /*@>195f9a*/obj->CameraPanInternal)/*@>15c7da*/ || /*@>195f00*/forceUpdate) {
    /*@>195f02*/obj->/*@>1e6009*/CameraPanInternal/*@>10baf6*/ = /*@>195f04*/obj->CameraPan;
/*@>180687*/    for ( int32_t /*@>1e5d7b*/i{/*@>1e5d7a*/0}; /*@>1e5d85*/i < /*@>1e5d83*/10; /*@>1e5d81*/i/*@>1e5dd5*/++) {
        /*@>195ff6*/e/*@>18f32c*/[/*@>195ff4*/i]/*@>18067a*/ = /*@>1da860*/f/*@>1da862*/[/*@>1da85f*/i];
    }
    /*@>1d35c0*/EXT_updateV4L2Control(&/*@>195f59*/e/*@>18f33c*/[/*@>19603d*/0], static_cast<float>(/*@>195f06*/obj->CameraPan), /*@>1b0e1c*/0, &/*@>195f08*/status);
}
/*@>10bb41*/if ((/*@>195f9d*/obj->CameraTilt/*@>16907a*/ != /*@>195fa0*/obj->CameraTiltInternal)/*@>15c7db*/ || /*@>195f0a*/forceUpdate) {
    /*@>195f0c*/obj->/*@>1e600c*/CameraTiltInternal/*@>10bb56*/ = /*@>195f0e*/obj->CameraTilt;
/*@>1806d8*/    for ( int32_t /*@>1e5d6a*/i{/*@>1e5d69*/0}; /*@>1e5d74*/i < /*@>1e5d72*/11; /*@>1e5d70*/i/*@>1e5dd7*/++) {
        /*@>196005*/b/*@>18f34c*/[/*@>196003*/i]/*@>1806cb*/ = /*@>1da866*/g/*@>1da868*/[/*@>1da865*/i];
    }
    /*@>1d35c2*/EXT_updateV4L2Control(&/*@>195f62*/b/*@>18f35c*/[/*@>19603e*/0], static_cast<float>(/*@>195f10*/obj->CameraTilt), /*@>1b0e34*/0, &/*@>195f12*/status);
}
/*@>10bba1*/if ((/*@>195fa3*/obj->CameraZoom/*@>169086*/ != /*@>195fa6*/obj->CameraZoomInternal)/*@>15c7dc*/ || /*@>195f14*/forceUpdate) {
    /*@>195f16*/obj->/*@>1e600f*/CameraZoomInternal/*@>10bbb6*/ = /*@>195f18*/obj->CameraZoom;
/*@>180729*/    for ( int32_t /*@>1e5d59*/i{/*@>1e5d58*/0}; /*@>1e5d63*/i < /*@>1e5d61*/11; /*@>1e5d5f*/i/*@>1e5dd9*/++) {
        /*@>196014*/b/*@>18f36c*/[/*@>196012*/i]/*@>18071c*/ = /*@>1da86c*/h/*@>1da86e*/[/*@>1da86b*/i];
    }
    /*@>1d35c4*/EXT_updateV4L2Control(&/*@>195f6b*/b/*@>18f37c*/[/*@>19603f*/0], static_cast<float>(/*@>195f1a*/obj->CameraZoom), /*@>1b0e4b*/0, &/*@>195f1c*/status);
}
/*@>10bc01*/if ((!/*@<169092*//*@>195fa9*/obj->EnableManualFocusInternal)/*@>15c7dd*/ || /*@>195f1e*/forceUpdate) {
    /*@>195f20*/obj->/*@>1e6012*/EnableManualFocusInternal/*@>10bc16*/ = /*@>195f6d*/true;
/*@>18077a*/    for ( int32_t /*@>1e5d48*/i{/*@>1e5d47*/0}; /*@>1e5d52*/i < /*@>1e5d50*/18; /*@>1e5d4e*/i/*@>1e5ddb*/++) {
        /*@>1decce*/rtDW./*@>1e6018*/i_l/*@>18f38c*/[/*@>196021*/i]/*@>18076d*/ = /*@>1da872*/i_0/*@>1da874*/[/*@>1da871*/i];
    }
    /*@>1d35c6*/EXT_updateV4L2Control(&/*@>1decd4*/rtDW./*@>1e601b*/i_l/*@>18f39d*/[/*@>196040*/0], /*@>195f7e*/1.0F, /*@>1b0e5f*/0, &/*@>195f22*/status);
}
/*@>10bc61*/if ((/*@>195fac*/obj->ManualFocus/*@>169099*/ != /*@>195faf*/obj->ManualFocusInternal)/*@>15c7de*/ || /*@>195f24*/forceUpdate) {
    /*@>195f26*/obj->/*@>1e6015*/ManualFocusInternal/*@>10bc76*/ = /*@>195f28*/obj->ManualFocus;
/*@>1807ca*/    for ( int32_t /*@>1e5d37*/i{/*@>1e5d36*/0}; /*@>1e5d41*/i < /*@>1e5d3f*/12; /*@>1e5d3d*/i/*@>1e5ddc*/++) {
        /*@>196032*/j/*@>18f3ac*/[/*@>196030*/i]/*@>1807bd*/ = /*@>1da878*/j_0/*@>1da87a*/[/*@>1da877*/i];
    }
    /*@>1d35c8*/EXT_updateV4L2Control(&/*@>195f7c*/j/*@>18f3bc*/[/*@>196041*/0], static_cast<float>(/*@>195f2a*/obj->ManualFocus), /*@>1b0e6e*/0, &/*@>195f2c*/status);
}
/* {E!d546}End of Start for MATLABSystem: '<Root>/V4L2 Video Capture' */


        }

                





                        


         

                
                void Rpi_cam::SystemCore_step(codertarget_raspi_internal_Raspiv4l2Capture *obj, uint8_t varargout_1[307200], uint8_t varargout_2[307200], uint8_t varargout_3[307200])
        {
            double ts;



/* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@[1e58cf*/v4l2Capture_updateV4L2Settings(/*@>1e6152*/obj, /*@>1e6160*/false)/*@]*/;
/*@>1d35cc*/EXT_webcamReadFrame(/*@>1b0eda*/0, &/*@>1960ad*/ts, &/*@>1d3503*/varargout_1/*@>18f3ce*/[/*@>1960b5*/0], &/*@>1d3506*/varargout_2/*@>18f3d5*/[/*@>1960b6*/0], &/*@>1d3509*/varargout_3/*@>18f3dc*/[/*@>1960b7*/0]);


        }

                



            


                        


         

                
                void Rpi_cam::QRV2Norm_double_o(const double V[], int32_t N, double v2norm[])
        {
            int32_t vi;
/* {S!d558}S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */
/*@>1def3e*/rtDW./*@>1e64ec*/tmpQRSL/*@>15e28e*/ = /*@>1967f9*/0.0;
/*@>1967fa*/vi/*@>15e295*/ = /*@>1e643b*/0;
/*@>1e6455*/for ( int32_t /*@>1e6451*/i{/*@>1e6452*/0}; /*@>1e6447*/i/*@>1e6445*/ < /*@>1e6449*/N; /*@>1e644b*/i/*@>1e6469*/++) {
    /*@>1def4a*/rtDW./*@>1e64f2*/d/*@>171437*/ = /*@>1def50*/rtDW./*@>1e64f5*/tmpQRSL;
    /*@>1def56*/rtDW./*@>1e64f8*/d1/*@>171447*/ = /*@>1d35e2*/std::abs(/*@>1daa86*/V/*@>1daa88*/[/*@>1daa84*/vi]);
    /*@>15e2c9*/if (/*@>1def5c*/rtDW./*@>1e64fb*/tmpQRSL/*@>15e2c8*/ > /*@>1def62*/rtDW./*@>1e64fe*/d1) {
        /*@>1def68*/rtDW./*@>1e6501*/tmpQRSL/*@>15e2d0*/ = /*@>1daa94*/V/*@>1daa96*/[/*@>1daa92*/vi]/*@>15e2cf*/ / /*@>1def6e*/rtDW./*@>1e6504*/tmpQRSL;
        /*@>1def86*/rtDW./*@>1e650d*/tmpQRSL/*@>15e2e2*/ = /*@>1d35e6*/std::sqrt(/*@>1def8c*/rtDW./*@>1e6510*/tmpQRSL/*@>196e9f*/ * /*@>1def92*/rtDW./*@>1e6513*/tmpQRSL/*@>15e2d9*/ + /*@>196813*/1.0)/*@>196e9b*/ * rtDW.d;
    } else /*@>15e2e9*/if (/*@>1daa8d*/V/*@>1daa8f*/[/*@>1daa8b*/vi]/*@>15e2e8*/ == /*@>196817*/0.0) {
        /*@>1def80*/rtDW./*@>1e650a*/tmpQRSL/*@>15e2ee*/ = /*@>196818*/0.0;
    } else {
        /*@>1def74*/rtDW./*@>1e6507*/tmpQRSL/*@>1e646b*/ /= /*@>1daa9b*/V/*@>1daa9d*/[/*@>1daa99*/vi];
        /*@>1def9e*/rtDW./*@>1e6519*/tmpQRSL/*@>15e308*/ = /*@>1d35e4*/std::sqrt(/*@>1defa4*/rtDW./*@>1e651c*/tmpQRSL/*@>196e97*/ * /*@>1defaa*/rtDW./*@>1e651f*/tmpQRSL/*@>15e2ff*/ + /*@>196823*/1.0)/*@>196e93*/ * rtDW.d1;
    }
    /*@>19682a*/vi/*@>1e646a*/++;
}
/*@>1967f5*/v2norm/*@>15e319*/[/*@>19682c*/0U]/*@>15e31d*/ = /*@>1def44*/rtDW./*@>1e64ef*/tmpQRSL;
/* {E!d558}End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */


        }

                





                        


         

                
                void Rpi_cam::QRDC_double_o(double xVec[], double qrAux[], int32_t jpvt[], double work[], int32_t M, int32_t N)
        {
            int32_t i;
int32_t j;
int32_t l;
int32_t maxj;
int32_t minVal;
int32_t mml;
int32_t pl;
int32_t plj;
int32_t pu;
int32_t px;
int32_t px2;










/* {S!d556}S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */
/*@>1964aa*/pl/*@>15e0a1*/ = /*@>1e6543*/0;
/*@>1e6706*/for (/*@>1e6702*/j/*@>1e6701*/ = /*@>1e6703*/0; /*@>1e66f8*/j/*@>1e66f6*/ < /*@>1e66fa*/N; /*@>1e66fc*/j/*@>1e673e*/++) {
    /*@>1964ae*/pu/*@>15e0c9*/ = (/*@>1da97c*/jpvt/*@>1da97e*/[/*@>1da97a*/j]/*@>15e0c4*/ > /*@>1964cb*/0);
    /*@>1a7806*/if (/*@>1da983*/jpvt/*@>1da985*/[/*@>1da981*/j]/*@>15e0d9*/ < /*@>1964cc*/0) {
        /*@>1a780c*/jpvt/*@>1a780a*/[/*@>1a780e*/j]/*@>1a7809*/ = -/*@<196e4f*//*@>1964cd*/j;
    } else {
        /*@>1967ba*/jpvt/*@>18fde2*/[/*@>1967bc*/j]/*@>18fde1*/ = /*@>1964cf*/j;
    }
    /*@>15e0f6*/if (/*@>1964d1*/pu/*@>15e0f5*/ == /*@>1964d3*/1) {
        /*@>15e0fd*/if (/*@>1964d6*/j/*@>15e0fc*/ != /*@>1964d4*/pl) {
            /* Swap columns pl and j */
            /*@>1964b0*/px/*@>15e110*/ = /*@>1966c4*/pl/*@>196e4c*/ * /*@>1966c6*/M;
            /*@>1964b2*/px2/*@>15e114*/ = /*@>1966c8*/j/*@>196e49*/ * /*@>1966ca*/M;
/*@>1e672a*/            for (/*@>1e6725*/i/*@>1e6724*/ = /*@>1e6727*/M; /*@>1e671c*/i/*@>1e671a*/ > /*@>1e671d*/0; /*@>1e671f*/i/*@>1e673f*/--) {
                /*@>1dee2a*/rtDW./*@>1e6b16*/maxnrm/*@>15e12e*/ = /*@>1da9a6*/xVec/*@>1da9a8*/[/*@>1da9a4*/px];
                /*@>19670a*/xVec/*@>180fdf*/[/*@>19670c*/px]/*@>15e13d*/ = /*@>1da9bb*/xVec/*@>1da9bd*/[/*@>1da9b9*/px2];
                /*@>1964e4*/xVec/*@>15e143*/[/*@>1964e2*/px2]/*@>15e147*/ = /*@>1dee36*/rtDW./*@>1e6b1c*/maxnrm;
                /*@>1964eb*/px/*@>1e6740*/++;
                /*@>1964f0*/px2/*@>1e6741*/++;
            }
        }
        /*@>1966f6*/jpvt/*@>180f69*/[/*@>1966f8*/j]/*@>15e166*/ = /*@>1da998*/jpvt/*@>1da99a*/[/*@>1da996*/pl];
        /*@>1964f6*/jpvt/*@>15e16e*/[/*@>1964f4*/pl]/*@>15e170*/ = /*@>1964f2*/j;
        /*@>1964fb*/pl/*@>1e6742*/++;
    }
}
/*@>196500*/pu/*@>15e180*/ = /*@>1964fd*/N/*@>15e17e*/ - /*@>1964ff*/1;
/*@>1e66bc*/for (/*@>1e66b5*/j/*@>1e66b4*/ = /*@>1e66b8*/N/*@>1e66b6*/ - /*@>1e66b9*/1; /*@>1e66ac*/j/*@>1e66aa*/ >= /*@>1e66ad*/0; /*@>1e66af*/j/*@>1e6743*/--) {
    /*@>15e1a5*/if (/*@>1da98a*/jpvt/*@>1da98c*/[/*@>1da988*/j]/*@>15e1a4*/ < /*@>19650c*/0) {
        /*@>1966ee*/jpvt/*@>180f41*/[/*@>1966f0*/j]/*@>15e1b5*/ = -/*@<196e57*//*@>1da991*/jpvt/*@>1da993*/[/*@>1da98f*/j];
        /*@>15e1bc*/if (/*@>19650f*/j/*@>15e1bb*/ != /*@>19650d*/pu) {
            /* Swap columns pu and j */
            /*@>196511*/px/*@>15e1d3*/ = /*@>1966bc*/pu/*@>196e54*/ * /*@>1966be*/M;
            /*@>196513*/px2/*@>15e1d8*/ = /*@>1966c0*/j/*@>196e51*/ * /*@>1966c2*/M;
/*@>1e66e2*/            for (/*@>1e66dd*/i/*@>1e66dc*/ = /*@>1e66df*/M; /*@>1e66d4*/i/*@>1e66d2*/ > /*@>1e66d5*/0; /*@>1e66d7*/i/*@>1e6744*/--) {
                /*@>1dee30*/rtDW./*@>1e6b19*/maxnrm/*@>15e1f6*/ = /*@>1da9b4*/xVec/*@>1da9b6*/[/*@>1da9b2*/px];
                /*@>196722*/xVec/*@>18105e*/[/*@>196724*/px]/*@>15e205*/ = /*@>1da9c9*/xVec/*@>1da9cb*/[/*@>1da9c7*/px2];
                /*@>196525*/xVec/*@>15e20b*/[/*@>196523*/px2]/*@>15e20f*/ = /*@>1dee3c*/rtDW./*@>1e6b1f*/maxnrm;
                /*@>19652c*/px/*@>1e6745*/++;
                /*@>196531*/px2/*@>1e6746*/++;
            }
            /*@>1964a4*/px/*@>15e228*/ = /*@>1da9ad*/jpvt/*@>1da9af*/[/*@>1da9ab*/pu];
            /*@>19671a*/jpvt/*@>181036*/[/*@>19671c*/pu]/*@>15e237*/ = /*@>1da9c2*/jpvt/*@>1da9c4*/[/*@>1da9c0*/j];
            /*@>196535*/jpvt/*@>15e23f*/[/*@>19669d*/j]/*@>15e241*/ = /*@>196533*/px;
        }
        /*@>19653a*/pu/*@>1e6747*/--;
    }
}
/* compute the norms of the free columns */
/*@>1e6695*/for (/*@>1e6690*/j/*@>1e668f*/ = /*@>1e6692*/pl; /*@>1e6686*/j/*@>1e6684*/ <= /*@>1e6688*/pu; /*@>1e668a*/j/*@>1e6748*/++) {
    /*@[1e58e8*/QRV2Norm_double_o(&/*@>1e6baa*/xVec/*@>1e6ba9*/[/*@>1e6bac*/j/*@>1e6bab*/ * /*@>1e6bad*/M], /*@>1e6bbb*/M, &/*@>1e6bcb*/qrAux/*@>1e6bca*/[/*@>1e6bcc*/j])/*@]*/;
    /*@>1966fe*/work/*@>180f9d*/[/*@>196700*/j]/*@>15e335*/ = /*@>1da99f*/qrAux/*@>1da9a1*/[/*@>1da99d*/j];
}
/* perform the Householder reduction of x */
/*@>1a780f*/if (/*@>1a5e95*/M/*@>1a0495*/ <= /*@>1a5e97*/N) {
    /*@>1a7813*/minVal/*@>1a7812*/ = /*@>1a5e99*/M;
} else {
    /*@>1a049a*/minVal/*@>1a049b*/ = /*@>1a5e9b*/N;
}
/*@>1e656c*/for (/*@>1e6568*/l/*@>1e6567*/ = /*@>1e6569*/0; /*@>1e655e*/l/*@>1e655c*/ < /*@>1e6560*/minVal; /*@>1e6562*/l/*@>1e6749*/++) {
    /*@>1964ac*/mml/*@>15e364*/ = /*@>19655c*/M/*@>15e363*/ - /*@>19655a*/l;
    /* locate the column of largest norm and bring it into the pivot position */
    /*@>15e373*/if ((/*@>196564*/l/*@>15e371*/ >= /*@>196562*/pl)/*@>15e372*/ && (/*@>196560*/l/*@>15e36c*/ < /*@>19655e*/pu)) {
        /*@>1dee42*/rtDW./*@>1e6b22*/maxnrm/*@>15e377*/ = /*@>196566*/0.0;
        /*@>1964a8*/maxj/*@>15e37b*/ = /*@>196567*/l;
/*@>1e666f*/        for (/*@>1e666a*/j/*@>1e6669*/ = /*@>1e666c*/l; /*@>1e6660*/j/*@>1e665e*/ <= /*@>1e6662*/pu; /*@>1e6664*/j/*@>1e674a*/++) {
            /*@>15e39b*/if (/*@>1da9d0*/qrAux/*@>1da9d2*/[/*@>1da9ce*/j]/*@>15e39a*/ > /*@>1dee48*/rtDW./*@>1e6b25*/maxnrm) {
                /*@>1dee54*/rtDW./*@>1e6b2b*/maxnrm/*@>15e3a5*/ = /*@>1da9d7*/qrAux/*@>1da9d9*/[/*@>1da9d5*/j];
                /*@>19657c*/maxj/*@>15e3aa*/ = /*@>19657a*/j;
            }
        }
        /*@>15e3b1*/if (/*@>196580*/maxj/*@>15e3b0*/ != /*@>19657e*/l) {
            /* Swap columns l and maxj */
            /*@>196582*/px/*@>15e3c7*/ = /*@>19669f*/l/*@>196e67*/ * /*@>1966a1*/M;
            /*@>196584*/px2/*@>15e3cc*/ = /*@>1966a3*/maxj/*@>196e64*/ * /*@>1966a5*/M;
/*@>1e664a*/            for (/*@>1e6645*/i/*@>1e6644*/ = /*@>1e6647*/M; /*@>1e663c*/i/*@>1e663a*/ > /*@>1e663d*/0; /*@>1e663f*/i/*@>1e674b*/--) {
                /*@>1dee84*/rtDW./*@>1e6b43*/maxnrm/*@>15e3ea*/ = /*@>1da9f3*/xVec/*@>1da9f5*/[/*@>1da9f1*/px];
                /*@>19674e*/xVec/*@>18115d*/[/*@>196750*/px]/*@>15e3f9*/ = /*@>1daa01*/xVec/*@>1daa03*/[/*@>1da9ff*/px2];
                /*@>196596*/xVec/*@>15e3ff*/[/*@>196594*/px2]/*@>15e403*/ = /*@>1dee9c*/rtDW./*@>1e6b4f*/maxnrm;
                /*@>19659d*/px/*@>1e674c*/++;
                /*@>1965a2*/px2/*@>1e674d*/++;
            }
            /*@>19673a*/qrAux/*@>1810f6*/[/*@>19673c*/maxj]/*@>15e422*/ = /*@>1da9ec*/qrAux/*@>1da9ee*/[/*@>1da9ea*/l];
            /*@>196746*/work/*@>181135*/[/*@>196748*/maxj]/*@>15e431*/ = /*@>1da9fa*/work/*@>1da9fc*/[/*@>1da9f8*/l];
            /*@>1965a4*/px/*@>15e43b*/ = /*@>1daa08*/jpvt/*@>1daa0a*/[/*@>1daa06*/maxj];
            /*@>19675a*/jpvt/*@>18119d*/[/*@>19675c*/maxj]/*@>15e44a*/ = /*@>1daa0f*/jpvt/*@>1daa11*/[/*@>1daa0d*/l];
            /*@>1965aa*/jpvt/*@>15e452*/[/*@>1965a8*/l]/*@>15e454*/ = /*@>1965a6*/px;
        }
    }
    /*@>1965ae*/qrAux/*@>15e45a*/[/*@>1965ac*/l]/*@>15e45e*/ = /*@>1965b0*/0.0;
    /*@>15e468*/if (/*@>1965b1*/M/*@>15e464*/ - /*@>1965b3*/1/*@>15e467*/ != /*@>1965b4*/l) {
        /* Compute the Householder transformation for column l */
        /*@>1964b4*/maxj/*@>15e474*/ = (/*@>1965b6*/M/*@>15e470*/ + /*@>1965b8*/1)/*@>196e61*/ * /*@>1965b9*/l;
        /*@>1965bd*/px/*@>15e479*/ = /*@>1965bb*/maxj;
        /*@[1e5901*/QRV2Norm_double_o(&/*@>1e6bdc*/xVec/*@>1e6bdb*/[/*@>1e6bdd*/maxj], /*@>1e6beb*/mml, &/*@>1e6bfb*/rtDW./*@>1e6bfa*/nrmxl)/*@]*/;
        /*@>1dee5a*/rtDW./*@>1e6b2e*/maxnrm/*@>1c3499*/ = /*@>1d35d6*/std::abs(/*@>1dee60*/rtDW./*@>1e6b31*/nrmxl);
        /*@>15e491*/if (/*@>1dee66*/rtDW./*@>1e6b34*/maxnrm/*@>15e490*/ != /*@>1965c4*/0.0) {
            /*@>15e4a6*/if (/*@>1d35d8*/std::abs(/*@>1da9de*/xVec/*@>1da9e0*/[/*@>1da9dc*/maxj])/*@>15e4a5*/ != /*@>1965c5*/0.0) {
                /*@>1a7814*/if (/*@>1da9e5*/xVec/*@>1da9e7*/[/*@>1da9e3*/maxj]/*@>15e4b6*/ >= /*@>1965c6*/0.0) {
                    /*@>1dee78*/rtDW./*@>1e6b3d*/nrmxl/*@>1a7817*/ = rtDW.maxnrm;
                } else {
                    /*@>1dee6c*/rtDW./*@>1e6b37*/nrmxl/*@>18fdea*/ = -/*@<196e60*/rtDW.maxnrm;
                }
            }
            /* Check if it's safe to multiply by 1/nrmxl instead of dividing by nrmxl */
            /*@>1965cf*/px2/*@>15e4cd*/ = /*@>196699*/maxj;
            /*@>15e4db*/if (/*@>1966aa*/5.0E-20/*@>196e5e*/ * /*@>1dee8a*/rtDW./*@>1e6b46*/nrmxl/*@>15e4da*/ != /*@>1965d1*/0.0) {
                /*@>1dee90*/rtDW./*@>1e6b49*/maxnrm/*@>15e4e3*/ = /*@>1965d4*/1.0/*@>15e4e1*/ / /*@>1dee96*/rtDW./*@>1e6b4c*/nrmxl;
/*@>1e6626*/                for (/*@>1e6621*/i/*@>1e6620*/ = /*@>1e6623*/mml; /*@>1e6618*/i/*@>1e6616*/ > /*@>1e6619*/0; /*@>1e661b*/i/*@>1e674e*/--) {
                    /*@>196772*/xVec/*@>18121a*/[/*@>196774*/px2]/*@>1e674f*/ *= /*@>1deea8*/rtDW./*@>1e6b55*/maxnrm;
                    /*@>1965e8*/px2/*@>1e6750*/++;
                }
            } else {
/*@>1e6602*/                for (/*@>1e65fd*/i/*@>1e65fc*/ = /*@>1e65ff*/mml; /*@>1e65f4*/i/*@>1e65f2*/ > /*@>1e65f5*/0; /*@>1e65f7*/i/*@>1e675d*/--) {
                    /*@>196762*/xVec/*@>1811c6*/[/*@>196764*/px2]/*@>1e675e*/ /= /*@>1deea2*/rtDW./*@>1e6b52*/nrmxl;
                    /*@>1965fb*/px2/*@>1e675f*/++;
                }
            }
            /*@>19676a*/xVec/*@>1811f1*/[/*@>19676c*/maxj]/*@>1e6751*/++;
            /* apply the transformation to the remaining columns, updating the norms. */
/*@>1e6593*/            for (/*@>1e658c*/j/*@>1e658b*/ = /*@>1e658f*/l/*@>1e658d*/ + /*@>1e6590*/1; /*@>1e6582*/j/*@>1e6580*/ < /*@>1e6584*/N; /*@>1e6586*/j/*@>1e6752*/++) {
                /*@>1964b6*/plj/*@>15e573*/ = /*@>196610*/j/*@>196e86*/ * /*@>19660e*/M/*@>15e572*/ + /*@>19660c*/l;
                /*@>196614*/px2/*@>15e578*/ = /*@>196612*/plj;
                /*@>1deeb4*/rtDW./*@>1e6b5b*/t/*@>15e57c*/ = /*@>196616*/0.0;
/*@>1e65de*/                for (/*@>1e65d9*/i/*@>1e65d8*/ = /*@>1e65db*/mml; /*@>1e65d0*/i/*@>1e65ce*/ > /*@>1e65d1*/0; /*@>1e65d3*/i/*@>1e6753*/--) {
                    /*@>1deeba*/rtDW./*@>1e6b5e*/t/*@>1e6754*/ -= /*@>1daa32*/xVec/*@>1daa34*/[/*@>1daa30*/px]/*@>196e8b*/ * /*@>1daa39*/xVec/*@>1daa3b*/[/*@>1daa37*/px2];
                    /*@>19662a*/px/*@>1e6755*/++;
                    /*@>19662f*/px2/*@>1e6756*/++;
                }
                /*@>196633*/px/*@>15e5ba*/ = /*@>196631*/maxj;
                /*@>196637*/px2/*@>15e5bf*/ = /*@>196635*/plj;
                /*@>1deec6*/rtDW./*@>1e6b61*/t/*@>1e6757*/ /= /*@>1daa40*/xVec/*@>1daa42*/[/*@>1daa3e*/maxj];
/*@>1e65ba*/                for (/*@>1e65b5*/i/*@>1e65b4*/ = /*@>1e65b7*/mml; /*@>1e65ac*/i/*@>1e65aa*/ > /*@>1e65ad*/0; /*@>1e65af*/i/*@>1e6758*/--) {
                    /*@>196792*/xVec/*@>1812d0*/[/*@>196794*/px2]/*@>1e6759*/ += /*@>1deed2*/rtDW./*@>1e6b64*/t/*@>196e8f*/ * /*@>1daa47*/xVec/*@>1daa49*/[/*@>1daa45*/px];
                    /*@>19664e*/px/*@>1e675a*/++;
                    /*@>196653*/px2/*@>1e675b*/++;
                }
                /*@>196657*/px/*@>15e60e*/ = /*@>196655*/maxj;
                /*@>196659*/px2/*@>15e640*/ = /*@>1e654c*/0;
                /*@>15e64c*/if (/*@>1daa55*/qrAux/*@>1daa57*/[/*@>1daa53*/j]/*@>15e64b*/ == /*@>19665c*/0.0) {
                    /*@>19665e*/px2/*@>15e651*/ = /*@>1e654f*/1;
                }
                /*@>15e65c*/if ((/*@>1966ad*/j/*@>169fc7*/ >= /*@>1966af*/pl)/*@>169fc6*/ && (/*@>1966b1*/j/*@>169fc8*/ <= /*@>1966b3*/pu)/*@>169fc3*/ && (/*@>196660*/px2/*@>197e4f*/ == /*@>196e83*/0)) {
                    /*@>1deed8*/rtDW./*@>1e6b67*/maxnrm/*@>15e675*/ = /*@>1d35da*/std::abs(/*@>1daa5c*/xVec/*@>1daa5e*/[/*@>1daa5a*/plj])/*@>15e673*/ / /*@>1daa63*/qrAux/*@>1daa65*/[/*@>1daa61*/j];
                    /*@>1deede*/rtDW./*@>1e6b6a*/tt/*@>15e67f*/ = /*@>196668*/1.0/*@>15e67e*/ - /*@>1deee4*/rtDW./*@>1e6b6d*/maxnrm/*@>196e80*/ * /*@>1deeea*/rtDW./*@>1e6b70*/maxnrm;
                    /*@>15e686*/if (/*@>1deef0*/rtDW./*@>1e6b73*/tt/*@>15e685*/ < /*@>19666b*/0.0) {
                        /*@>1deef6*/rtDW./*@>1e6b76*/tt/*@>15e68b*/ = /*@>19666c*/0.0;
                    }
                    /*@>1deefc*/rtDW./*@>1e6b79*/t/*@>15e690*/ = /*@>1def02*/rtDW./*@>1e6b7c*/tt;
                    /*@>1def08*/rtDW./*@>1e6b7f*/maxnrm/*@>15e6a2*/ = /*@>1daa6a*/qrAux/*@>1daa6c*/[/*@>1daa68*/j]/*@>15e6a0*/ / /*@>1daa71*/work/*@>1daa73*/[/*@>1daa6f*/j];
                    /*@>1def0e*/rtDW./*@>1e6b82*/tt/*@>15e6b3*/ = /*@>19667b*/0.05/*@>196e7c*/ * /*@>1def14*/rtDW./*@>1e6b85*/tt/*@>196e78*/ * /*@>1def1a*/rtDW./*@>1e6b88*/maxnrm/*@>196e74*/ * /*@>1def20*/rtDW./*@>1e6b8b*/maxnrm/*@>15e6b1*/ + /*@>19667c*/1.0;
                    /*@>15e6ba*/if (/*@>1def26*/rtDW./*@>1e6b8e*/tt/*@>15e6b9*/ != /*@>196681*/1.0) {
                        /*@>1967ae*/qrAux/*@>18136d*/[/*@>1967b0*/j]/*@>1e675c*/ *= /*@>1d35de*/std::sqrt(/*@>1def32*/rtDW./*@>1e6b94*/t);
                    } else {
                        /*@[1e591a*/QRV2Norm_double_o(&/*@>1e6c0c*/xVec/*@>1e6c0b*/[/*@>1e6c0e*/plj/*@>1e6c0d*/ + /*@>1e6c0f*/1], /*@>1e6c1e*/mml/*@>1e6c1d*/ - /*@>1e6c1f*/1, &/*@>1e6c2f*/rtDW./*@>1e6c2e*/maxnrm)/*@]*/;
                        /*@>19668d*/qrAux/*@>15e6eb*/[/*@>19668b*/j]/*@>15e6ef*/ = /*@>1def38*/rtDW./*@>1e6b97*/maxnrm;
                        /*@>1967b6*/work/*@>181396*/[/*@>1967b8*/j]/*@>15e6fe*/ = /*@>1daa7f*/qrAux/*@>1daa81*/[/*@>1daa7d*/j];
                    }
                }
            }
            /* save the transformation. */
            /*@>19677a*/qrAux/*@>181249*/[/*@>19677c*/l]/*@>15e70f*/ = /*@>1daa2b*/xVec/*@>1daa2d*/[/*@>1daa29*/px];
            /*@>196695*/xVec/*@>15e718*/[/*@>196693*/px]/*@>15e71a*/ = -/*@<196e5b*//*@>1deeae*/rtDW./*@>1e6b58*/nrmxl;
        }
    }
}
/* {E!d556}End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */


        }

                



            


                        


         

                
                void Rpi_cam::QRE_double_o(double outQ[], double outR[], double outE[], double qrAux[], double work[], int32_t jpvt[], double sPtr[], int32_t M, int32_t N, bool economy)
        {
            int32_t L_tmp;
int32_t ps;














/* {S!d554}S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */
/*@[1e5951*/QRDC_double_o(&/*@>1e70b9*/outR/*@>1e70b8*/[/*@>1e70ba*/0], &/*@>1e70ca*/qrAux/*@>1e70c9*/[/*@>1e70cb*/0], &/*@>1e70db*/jpvt/*@>1e70da*/[/*@>1e70dc*/0], &/*@>1e70ec*/work/*@>1e70eb*/[/*@>1e70ed*/0], /*@>1e70fb*/M, /*@>1e7109*/N)/*@]*/;
/* explicitly form q by manipulating identity */
/*@>18fdd3*/if (/*@>19631c*/economy) {
    /*@>1a77fb*/if (/*@>1a5d19*/M/*@>1a0461*/ <= /*@>1a5d1b*/N) {
        /*@>1dece6*/rtDW./*@>1e7028*/L/*@>1a77fe*/ = /*@>1a5d1d*/M;
    } else {
        /*@>1dece0*/rtDW./*@>1e7025*/L/*@>1a0467*/ = /*@>1a5d1f*/N;
    }
} else {
    /*@>1decda*/rtDW./*@>1e7022*/L/*@>15e747*/ = /*@>19631e*/M;
}
/*@>196320*/L_tmp/*@>15e758*/ = /*@>1e6dfc*/0;
/*@>1decec*/rtDW./*@>1e702b*/j_b/*@>15e76b*/ = /*@>1e6dff*/0;
while/*@<15e76e*/ (/*@>1decf2*/rtDW./*@>1e702e*/j_b/*@>15e767*/ < /*@>196328*/M/*@>196e46*/ * /*@>1decf8*/rtDW./*@>1e7031*/L) {
    /*@>19630d*/outQ/*@>15e772*/[/*@>1ded04*/rtDW./*@>1e7037*/j_b]/*@>15e776*/ = /*@>196331*/0.0;
    /*@>1ded0a*/rtDW./*@>1e703a*/j_b/*@>1e6eac*/++;
}
/*@>1decfe*/rtDW./*@>1e7034*/j_b/*@>15e787*/ = /*@>1e6e02*/0;
while/*@<15e78a*/ (/*@>1ded16*/rtDW./*@>1e703d*/j_b/*@>15e783*/ < /*@>1ded1c*/rtDW./*@>1e7040*/L) {
    /*@>196340*/outQ/*@>15e790*/[/*@>19633e*/L_tmp]/*@>15e794*/ = /*@>196342*/1.0;
    /*@>196348*/L_tmp/*@>15e79f*/ = (/*@>196345*/L_tmp/*@>15e79a*/ + /*@>196343*/M)/*@>15e79d*/ + /*@>196347*/1;
    /*@>1ded28*/rtDW./*@>1e7046*/j_b/*@>1e6ead*/++;
}
/* Convert cols of identity into cols of q. Use info stored in lower triangle of r and in vector qraux to work on columns of identity matrix I and transform them into q*I(:,j) i.e. the columns of q. */
/*@>19634b*/L_tmp/*@>15e7a6*/ = /*@>1e6e05*/0;
/*@>1ded22*/rtDW./*@>1e7043*/j_b/*@>15e7b7*/ = /*@>1e6e08*/0;
while/*@<15e7ba*/ (/*@>1ded34*/rtDW./*@>1e7049*/j_b/*@>15e7b3*/ < /*@>1ded3a*/rtDW./*@>1e704c*/L) {
    /*@[1e596c*/QRSL1_double(&/*@>1e7119*/outR/*@>1e7118*/[/*@>1e711a*/0], &/*@>1e712a*/qrAux/*@>1e7129*/[/*@>1e712b*/0], &/*@>1e713b*/outQ/*@>1e713a*/[/*@>1e713c*/L_tmp], /*@>1e714a*/M, /*@>1e7158*/N)/*@]*/;
    /*@>19636c*/L_tmp/*@>1e6eae*/ += /*@>196368*/M;
    /*@>1ded4c*/rtDW./*@>1e7055*/j_b/*@>1e6eaf*/++;
}
/*@>15e99c*/if (/*@>196374*/economy/*@>15e99b*/ && (/*@>196372*/M/*@>15e997*/ > /*@>196370*/N)) {
    /* Copy upper triangle of r to s */
    /*@>1ded46*/rtDW./*@>1e7052*/L/*@>15e9a2*/ = /*@>1e6e0b*/0;
    /*@>196377*/ps/*@>15e9a9*/ = /*@>1e6e0e*/0;
    /*@>1ded5e*/rtDW./*@>1e705b*/j_b/*@>15e9ba*/ = /*@>1e6e11*/1;
    while/*@<15e9bd*/ (/*@>1ded6a*/rtDW./*@>1e7061*/j_b/*@>184e19*/ - /*@>196426*/1/*@>15e9b6*/ < /*@>19637f*/N) {
/*@>1e6e93*/        for (/*@>1e6e8f*/L_tmp/*@>1e6e8e*/ = /*@>1e6e90*/0; /*@>1e6e81*/L_tmp/*@>1e6eab*/ < /*@>1e6e85*/rtDW./*@>1e70a6*/j_b; /*@>1e6e89*/L_tmp/*@>1e6eb0*/++) {
            /*@>196418*/sPtr/*@>180dfa*/[/*@>19641a*/ps]/*@>15e9db*/ = /*@>1da96e*/outR/*@>1da970*/[/*@>1dedd0*/rtDW./*@>1e7085*/L];
            /*@>196393*/ps/*@>1e6eb1*/++;
            /*@>1dede8*/rtDW./*@>1e708e*/L/*@>1e6eb2*/++;
        }
        /*@>1dedbe*/rtDW./*@>1e707c*/L/*@>15e9f9*/ = (/*@>1dedc4*/rtDW./*@>1e707f*/L/*@>15e9f3*/ + /*@>19639c*/M)/*@>15e9f4*/ - /*@>1dedca*/rtDW./*@>1e7082*/j_b;
/*@>1e6e66*/        for (/*@>1e6e62*/L_tmp/*@>1e6e61*/ = /*@>1e6e63*/0; /*@>1e6e53*/L_tmp/*@>1e6e51*/ < /*@>1e6e56*/N/*@>1e6e54*/ - /*@>1e6e59*/rtDW./*@>1e70a3*/j_b; /*@>1e6e5c*/L_tmp/*@>1e6eb3*/++) {
            /*@>1963b2*/sPtr/*@>15ea19*/[/*@>1963b0*/ps]/*@>15ea1d*/ = /*@>1963b4*/0.0;
            /*@>1963b8*/ps/*@>1e6eb4*/++;
        }
        /*@>1dee06*/rtDW./*@>1e7097*/j_b/*@>1e6eb5*/++;
    }
} else {
    /* Zero strict lower triangle of r */
    /*@>1ded40*/rtDW./*@>1e704f*/L/*@>15ea32*/ = /*@>1963bc*/M/*@>196e43*/ * /*@>1963ba*/N/*@>15ea30*/ - /*@>1963be*/1;
    /*@>1ded58*/rtDW./*@>1e7058*/j_b/*@>15ea46*/ = /*@>1963c9*/N;
    while/*@<15ea49*/ (/*@>1ded64*/rtDW./*@>1e705e*/j_b/*@>184e12*/ - /*@>196424*/1/*@>15ea3f*/ >= /*@>1963c8*/0) {
/*@>1e6e3a*/        for (/*@>1e6e35*/L_tmp/*@>1e6e34*/ = /*@>1e6e37*/M; /*@>1e6e29*/L_tmp/*@>1e6e27*/ > /*@>1e6e2c*/rtDW./*@>1e70a0*/j_b; /*@>1e6e2f*/L_tmp/*@>1e6eb8*/--) {
            /*@>1963dc*/outR/*@>15ea66*/[/*@>1ded82*/rtDW./*@>1e706a*/L]/*@>15ea6a*/ = /*@>1963de*/0.0;
            /*@>1dedb2*/rtDW./*@>1e7079*/L/*@>1e6eb9*/--;
        }
        /*@>1a7800*/if (/*@>1963e6*/M/*@>15ea7b*/ < /*@>1ded7c*/rtDW./*@>1e7067*/j_b) {
            /*@>1deda6*/rtDW./*@>1e7076*/L/*@>1e6eba*/ -= /*@>1963e8*/M;
        } else {
            /*@>1ded94*/rtDW./*@>1e7070*/L/*@>1e6ebc*/ -= /*@>1deda0*/rtDW./*@>1e7073*/j_b;
        }
        /*@>1deddc*/rtDW./*@>1e708b*/j_b/*@>1e6ebb*/--;
    }
}
/* form permutation vector e */
/*@>1ded70*/rtDW./*@>1e7064*/L/*@>15ea98*/ = /*@>1e6e17*/0;
/*@>1963f5*/L_tmp/*@>15ea9f*/ = /*@>1e6e1a*/0;
/*@>1ded8e*/rtDW./*@>1e706d*/j_b/*@>15eab0*/ = /*@>1e6e1d*/0;
while/*@<15eab3*/ (/*@>1dedd6*/rtDW./*@>1e7088*/j_b/*@>15eaac*/ < /*@>1963fd*/N) {
    /*@>196420*/outE/*@>180e27*/[/*@>1dedf4*/rtDW./*@>1e7091*/L]/*@>15eac2*/ = /*@>1da975*/jpvt/*@>1da977*/[/*@>1da973*/L_tmp]/*@>15eabc*/ + /*@>196404*/1;
    /*@>1c1529*/L_tmp/*@>1c152b*/ = /*@>1dee00*/rtDW./*@>1e7094*/L/*@>1cf3fb*/ + /*@>1cf3fe*/1;
    /*@>1dee12*/rtDW./*@>1e709a*/L/*@>1e6eb6*/++;
    /*@>1dee1e*/rtDW./*@>1e709d*/j_b/*@>1e6eb7*/++;
}
/* {E!d554}End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */


        }

                





                        


         

                
                void Rpi_cam::Warp_stepImpl(vision_internal_blocks_Warp *b_this, const bool Image[307200], const double input2[9], bool Jout[307200])
        {
            int32_t itmp;
int32_t p1;
int32_t p2;
int32_t p3;
/*@>17eb1b*/for (/*@>1e71ed*/p2 = /*@>1e71ec*/0; /*@>1e71f7*/p2 < /*@>1e71f5*/9; /*@>1e71f3*/p2/*@>1e71fb*/++) {
    /* {S!d514}Start for MATLABSystem: '<S4>/Warp' */
    /*@>1de7dc*/rtDW./*@>1e7803*/absx11/*@>17eb0e*/ = /*@>1da5b8*/input2/*@>1da5ba*/[/*@>1da5b6*/p2];
    /*@>1ae231*/b_this->/*@>1e77a6*/TformProjective./*@>1e77a3*/T/*@>1ae22d*/[/*@>1ae235*/p2]/*@>1ae238*/ = /*@>1de7e2*/rtDW./*@>1e7806*/absx11;
    /*@>1de7e8*/rtDW./*@>1e7809*/x/*@>17eb56*/[/*@>195971*/p2]/*@>17eb57*/ = /*@>1de7ee*/rtDW./*@>1e780c*/absx11;
}
/*@>195851*/p1/*@>11e2dd*/ = /*@>1e7166*/1;
/*@>195853*/p2/*@>11e2df*/ = /*@>1e7169*/3;
/*@>195855*/p3/*@>11e2e1*/ = /*@>1e716c*/6;
/* {S!d516}Start for MATLABSystem: '<S4>/Warp' */
/*@>1de7f4*/rtDW./*@>1e780f*/absx11/*@>11ebed*/ = /*@>1d359a*/std::abs(/*@>1da5be*/b_this->/*@>1e77a9*/TformProjective./*@>1e77ac*/T/*@>1da5c8*/[/*@>1da5bc*/0]);
/*@>1de7fa*/rtDW./*@>1e7812*/absx21/*@>11ec09*/ = /*@>1d359c*/std::abs(/*@>1da5cc*/b_this->/*@>1e77af*/TformProjective./*@>1e77b2*/T/*@>1da5d6*/[/*@>1da5ca*/1]);
/*@>1de800*/rtDW./*@>1e7815*/absx31/*@>11ec25*/ = /*@>1d359e*/std::abs(/*@>1da5da*/b_this->/*@>1e77b5*/TformProjective./*@>1e77b8*/T/*@>1da5e4*/[/*@>1da5d8*/2]);
/*@>11e549*/if ((/*@>1de806*/rtDW./*@>1e7818*/absx21/*@>11e4a7*/ > /*@>1de80c*/rtDW./*@>1e781b*/absx11)/*@>13422d*/ && (/*@>1de812*/rtDW./*@>1e781e*/absx21/*@>11e4a8*/ > /*@>1de818*/rtDW./*@>1e7821*/absx31)) {
    /*@>19585f*/p1/*@>11e2fa*/ = /*@>1e716f*/4;
    /*@>195861*/p2/*@>11e2fc*/ = /*@>1e7175*/0;
    /*@>1de82a*/rtDW./*@>1e782a*/x/*@>18ee06*/[/*@>195b98*/0]/*@>11e307*/ = /*@>1da5e8*/b_this->/*@>1e77bb*/TformProjective./*@>1e77be*/T/*@>1da5f2*/[/*@>1da5e6*/1];
    /*@>1de848*/rtDW./*@>1e7839*/x/*@>18ee14*/[/*@>195b9a*/1]/*@>11e30c*/ = /*@>1da60e*/b_this->/*@>1e77c7*/TformProjective./*@>1e77ca*/T/*@>1da618*/[/*@>1da60c*/0];
    /*@>1de860*/rtDW./*@>1e7845*/x/*@>18ee22*/[/*@>195b9c*/3]/*@>11e317*/ = /*@>1da62a*/b_this->/*@>1e77d3*/TformProjective./*@>1e77d6*/T/*@>1da634*/[/*@>1da628*/4];
    /*@>1de87e*/rtDW./*@>1e7854*/x/*@>18ee30*/[/*@>195b9e*/4]/*@>11e31c*/ = /*@>1da650*/b_this->/*@>1e77df*/TformProjective./*@>1e77e2*/T/*@>1da65a*/[/*@>1da64e*/3];
    /*@>1de896*/rtDW./*@>1e7860*/x/*@>18ee3e*/[/*@>195ba0*/6]/*@>11e327*/ = /*@>1da66c*/b_this->/*@>1e77eb*/TformProjective./*@>1e77ee*/T/*@>1da676*/[/*@>1da66a*/7];
    /*@>1de8ba*/rtDW./*@>1e786f*/x/*@>18ee4c*/[/*@>195ba2*/7]/*@>11e32c*/ = /*@>1da692*/b_this->/*@>1e77f7*/TformProjective./*@>1e77fa*/T/*@>1da69c*/[/*@>1da690*/6];
} else /*@>11e557*/if (/*@>1de81e*/rtDW./*@>1e7824*/absx31/*@>11e4a9*/ > /*@>1de824*/rtDW./*@>1e7827*/absx11) {
    /*@>195867*/p1/*@>11e332*/ = /*@>1e7172*/7;
    /*@>195869*/p3/*@>11e334*/ = /*@>1e7178*/0;
    /*@>1de842*/rtDW./*@>1e7836*/x/*@>18edb0*/[/*@>195b8c*/0]/*@>11e33f*/ = /*@>1da600*/b_this->/*@>1e77c1*/TformProjective./*@>1e77c4*/T/*@>1da60a*/[/*@>1da5fe*/2];
    /*@>1de85a*/rtDW./*@>1e7842*/x/*@>18edbe*/[/*@>195b8e*/2]/*@>11e344*/ = /*@>1da61c*/b_this->/*@>1e77cd*/TformProjective./*@>1e77d0*/T/*@>1da626*/[/*@>1da61a*/0];
    /*@>1de878*/rtDW./*@>1e7851*/x/*@>18edcc*/[/*@>195b90*/3]/*@>11e34f*/ = /*@>1da642*/b_this->/*@>1e77d9*/TformProjective./*@>1e77dc*/T/*@>1da64c*/[/*@>1da640*/5];
    /*@>1de890*/rtDW./*@>1e785d*/x/*@>18edda*/[/*@>195b92*/5]/*@>11e354*/ = /*@>1da65e*/b_this->/*@>1e77e5*/TformProjective./*@>1e77e8*/T/*@>1da668*/[/*@>1da65c*/3];
    /*@>1de8b4*/rtDW./*@>1e786c*/x/*@>18ede8*/[/*@>195b94*/6]/*@>11e35f*/ = /*@>1da684*/b_this->/*@>1e77f1*/TformProjective./*@>1e77f4*/T/*@>1da68e*/[/*@>1da682*/8];
    /*@>1de8d8*/rtDW./*@>1e787b*/x/*@>18edf6*/[/*@>195b96*/8]/*@>11e364*/ = /*@>1da6aa*/b_this->/*@>1e77fd*/TformProjective./*@>1e7800*/T/*@>1da6b4*/[/*@>1da6a8*/6];
}
/*@>1de830*/rtDW./*@>1e782d*/absx31/*@>1bd707*/ = /*@>1de836*/rtDW./*@>1e7830*/x/*@>1da5f7*/[/*@>1da5f4*/1]/*@>196d49*/ / /*@>1de83c*/rtDW./*@>1e7833*/x/*@>1da5fc*/[/*@>1da5f9*/0];
/*@>1de84e*/rtDW./*@>1e783c*/x/*@>18ee69*/[/*@>195ba6*/1]/*@>11e36d*/ = rtDW.absx31;
/* {S!d518}Start for MATLABSystem: '<S4>/Warp' */
/*@>1de866*/rtDW./*@>1e7848*/absx11/*@>1bd711*/ = /*@>1de86c*/rtDW./*@>1e784b*/x/*@>1da639*/[/*@>1da636*/2]/*@>196d41*/ / /*@>1de872*/rtDW./*@>1e784e*/x/*@>1da63e*/[/*@>1da63b*/0];
/*@>1de884*/rtDW./*@>1e7857*/x/*@>18ee8d*/[/*@>195bab*/2]/*@>11e376*/ = rtDW.absx11;
/*@>1de89c*/rtDW./*@>1e7863*/x/*@>18eea2*/[/*@>195bae*/4]/*@>1e71fc*/ -= /*@>1de8a8*/rtDW./*@>1e7866*/absx31/*@>196d39*/ * /*@>1de8ae*/rtDW./*@>1e7869*/x/*@>1da680*/[/*@>1da67d*/3];
/*@>1de8c0*/rtDW./*@>1e7872*/x/*@>18eeb8*/[/*@>195bb1*/5]/*@>1e71fd*/ -= /*@>1de8cc*/rtDW./*@>1e7875*/absx11/*@>196d35*/ * /*@>1de8d2*/rtDW./*@>1e7878*/x/*@>1da6a6*/[/*@>1da6a3*/3];
/*@>1de8de*/rtDW./*@>1e787e*/x/*@>18eece*/[/*@>195bb4*/7]/*@>1e71fe*/ -= /*@>1de8ea*/rtDW./*@>1e7881*/absx31/*@>196d31*/ * /*@>1de8f0*/rtDW./*@>1e7884*/x/*@>1da6be*/[/*@>1da6bb*/6];
/*@>1de8f6*/rtDW./*@>1e7887*/x/*@>18eee4*/[/*@>195bb7*/8]/*@>1e71ff*/ -= /*@>1de902*/rtDW./*@>1e788a*/absx11/*@>196d2d*/ * /*@>1de908*/rtDW./*@>1e788d*/x/*@>1da6c8*/[/*@>1da6c5*/6];
/* {S!d520}Start for MATLABSystem: '<S4>/Warp' */
/*@>11e56b*/if (/*@>1d35a0*/std::abs(/*@>1de90e*/rtDW./*@>1e7890*/x/*@>1da6cd*/[/*@>1da6ca*/5])/*@>11e4d6*/ > /*@>1d35a2*/std::abs(/*@>1de914*/rtDW./*@>1e7893*/x/*@>1da6d2*/[/*@>1da6cf*/4])) {
    /*@>19586b*/itmp/*@>11e3b0*/ = /*@>19586d*/p2;
    /*@>19586f*/p2/*@>11e3b4*/ = /*@>195871*/p3;
    /*@>195873*/p3/*@>11e3b8*/ = /*@>195875*/itmp;
    /*@>1de962*/rtDW./*@>1e78b7*/x/*@>18ef0e*/[/*@>195bbc*/1]/*@>11e3c3*/ = /*@>1de968*/rtDW./*@>1e78ba*/absx11;
    /*@>1de98c*/rtDW./*@>1e78cc*/x/*@>18ef16*/[/*@>195bbd*/2]/*@>11e3c8*/ = /*@>1de992*/rtDW./*@>1e78cf*/absx31;
    /*@>1de99e*/rtDW./*@>1e78d2*/absx11/*@>11e3cd*/ = /*@>1de9a4*/rtDW./*@>1e78d5*/x/*@>1da709*/[/*@>1da706*/4];
    /*@>1de9ce*/rtDW./*@>1e78ea*/x/*@>18ef26*/[/*@>195bbf*/4]/*@>11e3d3*/ = /*@>1de9d4*/rtDW./*@>1e78ed*/x/*@>1da71d*/[/*@>1da71a*/5];
    /*@>1de9e6*/rtDW./*@>1e78f6*/x/*@>18ef34*/[/*@>195bc1*/5]/*@>11e3d8*/ = /*@>1de9ec*/rtDW./*@>1e78f9*/absx11;
    /*@>1de9fe*/rtDW./*@>1e7902*/absx11/*@>11e3dd*/ = /*@>1dea04*/rtDW./*@>1e7905*/x/*@>1da722*/[/*@>1da71f*/7];
    /*@>1dea1c*/rtDW./*@>1e7911*/x/*@>18ef44*/[/*@>195bc3*/7]/*@>11e3e3*/ = /*@>1dea22*/rtDW./*@>1e7914*/x/*@>1da72c*/[/*@>1da729*/8];
    /*@>1dea40*/rtDW./*@>1e7923*/x/*@>18ef52*/[/*@>195bc5*/8]/*@>11e3e8*/ = /*@>1dea46*/rtDW./*@>1e7926*/absx11;
}
/*@>1de91a*/rtDW./*@>1e7896*/absx31/*@>1bd71b*/ = /*@>1de920*/rtDW./*@>1e7899*/x/*@>1da6d7*/[/*@>1da6d4*/5]/*@>196d29*/ / /*@>1de926*/rtDW./*@>1e789c*/x/*@>1da6dc*/[/*@>1da6d9*/4];
/*@>1de92c*/rtDW./*@>1e789f*/x/*@>18ef7e*/[/*@>195bcb*/8]/*@>1e7200*/ -= /*@>1de938*/rtDW./*@>1e78a2*/absx31/*@>196d21*/ * /*@>1de93e*/rtDW./*@>1e78a5*/x/*@>1da6e6*/[/*@>1da6e3*/7];
/* {S!d522}Start for MATLABSystem: '<S4>/Warp' */
/*@>1de944*/rtDW./*@>1e78a8*/absx11/*@>11e62a*/ = (/*@>1de94a*/rtDW./*@>1e78ab*/x/*@>1da6eb*/[/*@>1da6e8*/1]/*@>196d1d*/ * rtDW.absx31/*@>121c92*/ - /*@>1de956*/rtDW./*@>1e78b1*/x/*@>1da6f0*/[/*@>1da6ed*/2])/*@>196d19*/ / /*@>1de95c*/rtDW./*@>1e78b4*/x/*@>1da6f5*/[/*@>1da6f2*/8];
/*@>1de96e*/rtDW./*@>1e78bd*/absx21/*@>11e638*/ = -/*@<196d12*/(/*@>1de974*/rtDW./*@>1e78c0*/x/*@>1da6fa*/[/*@>1da6f7*/7]/*@>196d15*/ * /*@>1de97a*/rtDW./*@>1e78c3*/absx11/*@>121cab*/ + /*@>1de980*/rtDW./*@>1e78c6*/x/*@>1da6ff*/[/*@>1da6fc*/1])/*@>196d10*/ / /*@>1de986*/rtDW./*@>1e78c9*/x/*@>1da704*/[/*@>1da701*/4];
/*@>1de9aa*/rtDW./*@>1e78d8*/tinv/*@>17f483*/[/*@>195a2a*/p1/*@>184d7e*/ - /*@>195b52*/1]/*@>11e429*/ = ((/*@>195921*/1.0/*@>1222cc*/ - /*@>1de9b0*/rtDW./*@>1e78db*/x/*@>1da70e*/[/*@>1da70b*/3]/*@>196d08*/ * /*@>1de9b6*/rtDW./*@>1e78de*/absx21)/*@>1222cb*/ - /*@>1de9bc*/rtDW./*@>1e78e1*/x/*@>1da713*/[/*@>1da710*/6]/*@>196d0c*/ * /*@>1de9c2*/rtDW./*@>1e78e4*/absx11)/*@>196d04*/ / /*@>1de9c8*/rtDW./*@>1e78e7*/x/*@>1da718*/[/*@>1da715*/0];
/*@>1de9da*/rtDW./*@>1e78f0*/tinv/*@>17f4a7*/[/*@>195a2e*/p1]/*@>11e431*/ = /*@>1de9e0*/rtDW./*@>1e78f3*/absx21;
/*@>1de9f2*/rtDW./*@>1e78fc*/tinv/*@>17f4ed*/[/*@>195a34*/p1/*@>17f4f4*/ + /*@>195a36*/1]/*@>11e439*/ = /*@>1de9f8*/rtDW./*@>1e78ff*/absx11;
/*@>1dea0a*/rtDW./*@>1e7908*/absx11/*@>11e689*/ = -/*@<196d01*/rtDW.absx31/*@>196cff*/ / /*@>1dea16*/rtDW./*@>1e790e*/x/*@>1da727*/[/*@>1da724*/8];
/*@>1dea28*/rtDW./*@>1e7917*/absx21/*@>11e697*/ = (/*@>1958f7*/1.0/*@>121d09*/ - /*@>1dea2e*/rtDW./*@>1e791a*/x/*@>1da731*/[/*@>1da72e*/7]/*@>196cfb*/ * /*@>1dea34*/rtDW./*@>1e791d*/absx11)/*@>196cf7*/ / /*@>1dea3a*/rtDW./*@>1e7920*/x/*@>1da736*/[/*@>1da733*/4];
/*@>1dea4c*/rtDW./*@>1e7929*/tinv/*@>17f631*/[/*@>195a4b*/p2]/*@>11e45b*/ = -/*@<196cec*/(/*@>1dea52*/rtDW./*@>1e792c*/x/*@>1da73b*/[/*@>1da738*/3]/*@>196cef*/ * /*@>1dea58*/rtDW./*@>1e792f*/absx21/*@>1222ed*/ + /*@>1dea5e*/rtDW./*@>1e7932*/x/*@>1da740*/[/*@>1da73d*/6]/*@>196cf3*/ * /*@>1dea64*/rtDW./*@>1e7935*/absx11)/*@>196cea*/ / /*@>1dea6a*/rtDW./*@>1e7938*/x/*@>1da745*/[/*@>1da742*/0];
/*@>1dea70*/rtDW./*@>1e793b*/tinv/*@>17f654*/[/*@>195a4f*/p2/*@>17f65b*/ + /*@>195a51*/1]/*@>11e463*/ = /*@>1dea76*/rtDW./*@>1e793e*/absx21;
/*@>1dea7c*/rtDW./*@>1e7941*/tinv/*@>17f679*/[/*@>195a54*/p2/*@>17f680*/ + /*@>195a56*/2]/*@>11e46b*/ = /*@>1dea82*/rtDW./*@>1e7944*/absx11;
/*@>1dea88*/rtDW./*@>1e7947*/absx11/*@>11e6e8*/ = /*@>1958fa*/1.0/*@>196ce6*/ / /*@>1dea8e*/rtDW./*@>1e794a*/x/*@>1da74a*/[/*@>1da747*/8];
/*@>1dea94*/rtDW./*@>1e794d*/absx21/*@>11e6f6*/ = -/*@<196ce3*//*@>1dea9a*/rtDW./*@>1e7950*/x/*@>1da74f*/[/*@>1da74c*/7]/*@>196ce1*/ * /*@>1deaa0*/rtDW./*@>1e7953*/absx11/*@>196cdd*/ / /*@>1deaa6*/rtDW./*@>1e7956*/x/*@>1da754*/[/*@>1da751*/4];
/*@>1deaac*/rtDW./*@>1e7959*/tinv/*@>17f760*/[/*@>195a65*/p3]/*@>11e48a*/ = -/*@<196cd2*/(/*@>1deab2*/rtDW./*@>1e795c*/x/*@>1da759*/[/*@>1da756*/3]/*@>196cd5*/ * /*@>1deab8*/rtDW./*@>1e795f*/absx21/*@>12230c*/ + /*@>1deabe*/rtDW./*@>1e7962*/x/*@>1da75e*/[/*@>1da75b*/6]/*@>196cd9*/ * /*@>1deac4*/rtDW./*@>1e7965*/absx11)/*@>196cd0*/ / /*@>1deaca*/rtDW./*@>1e7968*/x/*@>1da763*/[/*@>1da760*/0];
/*@>1dead0*/rtDW./*@>1e796b*/tinv/*@>17f783*/[/*@>195a69*/p3/*@>17f78a*/ + /*@>195a6b*/1]/*@>11e492*/ = /*@>1dead6*/rtDW./*@>1e796e*/absx21;
/*@>1deadc*/rtDW./*@>1e7971*/tinv/*@>17f7a8*/[/*@>195a6e*/p3/*@>17f7af*/ + /*@>195a70*/2]/*@>11e49a*/ = /*@>1deae2*/rtDW./*@>1e7974*/absx11;
/*@>1deae8*/rtDW./*@>1e7977*/absx21/*@>188f9e*/ = /*@>1deaee*/rtDW./*@>1e797a*/tinv/*@>1da768*/[/*@>1da765*/6];
/*@>1deaf4*/rtDW./*@>1e797d*/absx31/*@>188fad*/ = /*@>1deafa*/rtDW./*@>1e7980*/tinv/*@>1da76d*/[/*@>1da76a*/7];
/*@>1deb00*/rtDW./*@>1e7983*/tinv_b/*@>188fbc*/ = /*@>1deb06*/rtDW./*@>1e7986*/tinv/*@>1da772*/[/*@>1da76f*/8];
/* {S!d524}Start for MATLABSystem: '<S4>/Warp' */
/*@>1deb0c*/rtDW./*@>1e7989*/tinv_p/*@>188fcb*/ = /*@>1deb12*/rtDW./*@>1e798c*/tinv/*@>1da777*/[/*@>1da774*/0];
/*@>1deb18*/rtDW./*@>1e798f*/tinv_c/*@>188fda*/ = /*@>1deb1e*/rtDW./*@>1e7992*/tinv/*@>1da77c*/[/*@>1da779*/1];
/*@>1deb24*/rtDW./*@>1e7995*/tinv_f/*@>188fe9*/ = /*@>1deb2a*/rtDW./*@>1e7998*/tinv/*@>1da781*/[/*@>1da77e*/2];
/*@>1deb30*/rtDW./*@>1e799b*/tinv_g/*@>188ff8*/ = /*@>1deb36*/rtDW./*@>1e799e*/tinv/*@>1da786*/[/*@>1da783*/3];
/*@>1deb3c*/rtDW./*@>1e79a1*/tinv_g1/*@>189007*/ = /*@>1deb42*/rtDW./*@>1e79a4*/tinv/*@>1da78b*/[/*@>1da788*/4];
/*@>1deb48*/rtDW./*@>1e79a7*/tinv_m/*@>189016*/ = /*@>1deb4e*/rtDW./*@>1e79aa*/tinv/*@>1da790*/[/*@>1da78d*/5];
/*@>11e10c*/for (/*@>1e71cb*/p1 = /*@>1e71ca*/0; /*@>1e71d5*/p1 < /*@>1e71d3*/640; /*@>1e71d1*/p1/*@>1e7201*/++) {
/*@>11e110*/    for (/*@>1e71dc*/p2 = /*@>1e71db*/0; /*@>1e71e6*/p2 < /*@>1e71e4*/480; /*@>1e71e2*/p2/*@>1e7202*/++) {
        /* {S!d526}Start for MATLABSystem: '<S4>/Warp' */
        /*@>1deb66*/rtDW./*@>1e79ad*/absx11/*@>11e0a3*/ = ((((static_cast<double>(/*@>19592e*/p1)/*@>12232e*/ + /*@>195930*/1.0)/*@>121dd8*/ - /*@>1958fe*/0.5)/*@>121dd6*/ + /*@>1958fd*/0.5)/*@>196d85*/ * /*@>1deb6c*/rtDW./*@>1e79b0*/absx21/*@>11e0ef*/ + (((static_cast<double>(/*@>195931*/p2)/*@>122333*/ + /*@>195933*/1.0)/*@>121dde*/ - /*@>195900*/0.5)/*@>121ddc*/ + /*@>1958ff*/0.5)/*@>196d8c*/ * /*@>1deb72*/rtDW./*@>1e79b3*/absx31)/*@>11e0f0*/ + /*@>1deb78*/rtDW./*@>1e79b6*/tinv_b;
        /*@>1bd723*/itmp/*@>1bd725*/ = /*@>195bee*/480/*@>196d6e*/ * /*@>195a82*/p1/*@>18f0b1*/ + /*@>195a80*/p2;
        /*@>1deb84*/rtDW./*@>1e79bc*/srcXIntrinsic/*@>18f0b5*/[/*@>1bd727*/itmp]/*@>11e0b9*/ = ((((((static_cast<double>(/*@>19594a*/p1)/*@>122445*/ + /*@>19594c*/1.0)/*@>122444*/ - /*@>19594d*/0.5)/*@>122442*/ + /*@>195949*/0.5)/*@>196d77*/ * /*@>1deb8a*/rtDW./*@>1e79bf*/tinv_p/*@>122361*/ + (((static_cast<double>(/*@>19594f*/p2)/*@>12244e*/ + /*@>195951*/1.0)/*@>12244d*/ - /*@>195952*/0.5)/*@>12244b*/ + /*@>19594e*/0.5)/*@>196d7e*/ * /*@>1deb90*/rtDW./*@>1e79c2*/tinv_c)/*@>122360*/ + /*@>1deb96*/rtDW./*@>1e79c5*/tinv_f)/*@>196d73*/ / /*@>1deb9c*/rtDW./*@>1e79c8*/absx11/*@>11e0f5*/ - /*@>19584f*/0.5)/*@>11e0f6*/ + /*@>195843*/0.5;
        /*@>1deba2*/rtDW./*@>1e79cb*/srcYIntrinsic/*@>18f0c8*/[itmp]/*@>11e0c3*/ = ((((((static_cast<double>(/*@>195954*/p1)/*@>122458*/ + /*@>195956*/1.0)/*@>122457*/ - /*@>195957*/0.5)/*@>122455*/ + /*@>195953*/0.5)/*@>196d62*/ * /*@>1deba8*/rtDW./*@>1e79ce*/tinv_g/*@>12237c*/ + (((static_cast<double>(/*@>195959*/p2)/*@>122461*/ + /*@>19595b*/1.0)/*@>122460*/ - /*@>19595c*/0.5)/*@>12245e*/ + /*@>195958*/0.5)/*@>196d69*/ * /*@>1debae*/rtDW./*@>1e79d1*/tinv_g1)/*@>12237b*/ + /*@>1debb4*/rtDW./*@>1e79d4*/tinv_m)/*@>196d5e*/ / /*@>1debba*/rtDW./*@>1e79d7*/absx11/*@>11e0f7*/ - /*@>195850*/0.5)/*@>11e0f8*/ + /*@>195844*/0.5;
    }
}
/*@>17f800*/for (/*@>1e71ba*/p2 = /*@>1e71b9*/0; /*@>1e71c4*/p2 < /*@>1e71c2*/307200; /*@>1e71c0*/p2/*@>1e7209*/++) {
    /* {S!d528}Start for MATLABSystem: '<S4>/Warp' */
    /*@>1deb7e*/rtDW./*@>1e79b9*/inputImage/*@>17f7f2*/[/*@>195a75*/p2]/*@>17f7f3*/ = static_cast<int8_t>(/*@>1da795*/Image/*@>1da797*/[/*@>1da793*/p2]);
}
/*@>11e9cf*/for (/*@>1e71a9*/p1 = /*@>1e71a8*/0; /*@>1e71b3*/p1 < /*@>1e71b1*/307200; /*@>1e71af*/p1/*@>1e720b*/++) {
    float qx2;
    /* {S!d530}Start for MATLABSystem: '<S4>/Warp' */
    /*@>1debc0*/rtDW./*@>1e79da*/absx11/*@>1ae199*/ = /*@>1debc6*/rtDW./*@>1e79dd*/srcXIntrinsic/*@>1da79d*/[/*@>1da79a*/p1];
    /*@>11ea4f*/if ((/*@>1debcc*/rtDW./*@>1e79e0*/absx11/*@>11ea3d*/ >= /*@>1958b9*/1.0)/*@>1e5338*/ && (/*@>1debd2*/rtDW./*@>1e79e3*/absx11/*@>11ea3e*/ <= /*@>1958bb*/640.0)) {
        /*@>1debd8*/rtDW./*@>1e79e6*/absx21/*@>1ae1bd*/ = /*@>1debde*/rtDW./*@>1e79e9*/srcYIntrinsic/*@>1da7a3*/[/*@>1da7a0*/p1];
        /*@>11ea51*/if ((/*@>1debe4*/rtDW./*@>1e79ec*/absx21/*@>11ea3f*/ >= /*@>1958ba*/1.0)/*@>1e5339*/ && (/*@>1debea*/rtDW./*@>1e79ef*/absx21/*@>11ea40*/ <= /*@>1958bc*/480.0)) {
            float qx1;
            /*@>1a77c9*/if (/*@>1debf0*/rtDW./*@>1e79f2*/absx11/*@>11ea7a*/ <= /*@>1958be*/1.0) {
                /*@>1a77cd*/p3/*@>1a77cc*/ = /*@>1e717b*/1;
            } else /*@>1a77dd*/if (/*@>1debf6*/rtDW./*@>1e79f5*/absx11/*@>11ea7b*/ <= /*@>19595d*/639.0) {
                /*@>1a77e1*/p3/*@>1a77e0*/ = static_cast<int32_t>(/*@>1d35a4*/std::floor(/*@>1debfc*/rtDW./*@>1e79f8*/absx11));
            } else {
                /*@>195bfe*/p3/*@>18fd94*/ = /*@>1e717e*/639;
            }
            /*@>1dec02*/rtDW./*@>1e79fb*/absx21/*@>1ae1cf*/ = /*@>1dec08*/rtDW./*@>1e79fe*/srcYIntrinsic/*@>1da7a9*/[/*@>1da7a6*/p1];
            /*@>1a77ce*/if (/*@>1dec0e*/rtDW./*@>1e7a01*/absx21/*@>11ea9f*/ <= /*@>1958c2*/1.0) {
                /*@>1a77d2*/itmp/*@>1a77d1*/ = /*@>1e7181*/1;
            } else /*@>1a77e2*/if (/*@>1dec14*/rtDW./*@>1e7a04*/absx21/*@>11eaa0*/ <= /*@>19595e*/479.0) {
                /*@>1a77e6*/itmp/*@>1a77e5*/ = static_cast<int32_t>(/*@>1d35a6*/std::floor(/*@>1dec1a*/rtDW./*@>1e7a07*/absx21));
            } else {
                /*@>195c00*/itmp/*@>18fd99*/ = /*@>1e7184*/479;
            }
            /*@>11eb51*/if (/*@>1dec20*/rtDW./*@>1e7a0a*/absx11/*@>11eb3f*/ == /*@>195905*/p3) {
                /*@>1bd72d*/p2/*@>1bd72f*/ = (/*@>195ab8*/p3/*@>17fbc5*/ - /*@>195aba*/1)/*@>196dd8*/ * /*@>195bfc*/480/*@>1907a2*/ + /*@>195ab5*/itmp;
                /*@>1958c6*/qx1/*@>11ead2*/ = /*@>1dec38*/rtDW./*@>1e7a13*/inputImage/*@>1da7b1*/[/*@>1da7ad*/p2/*@>1da7ab*/ - /*@>1da7ae*/1];
                /*@>1958c8*/qx2/*@>11ead6*/ = /*@>1dec44*/rtDW./*@>1e7a19*/inputImage/*@>1da7bf*/[p2];
            } else /*@>11eb54*/if (static_cast<double>(/*@>195938*/p3)/*@>121f8d*/ + /*@>195907*/1.0/*@>11eb40*/ == /*@>1dec26*/rtDW./*@>1e7a0d*/absx11) {
                /*@>1bd737*/p2/*@>1bd739*/ = /*@>195bfa*/480/*@>196dd2*/ * /*@>195ac2*/p3/*@>1907a0*/ + /*@>195abf*/itmp;
                /*@>1958ca*/qx1/*@>11eade*/ = /*@>1dec3e*/rtDW./*@>1e7a16*/inputImage/*@>1da7b9*/[/*@>1da7b5*/p2/*@>1da7b3*/ - /*@>1da7b6*/1];
                /*@>1958cc*/qx2/*@>11eae2*/ = /*@>1dec50*/rtDW./*@>1e7a1f*/inputImage/*@>1da7cd*/[p2];
            } else {
                int8_t tmp;
                int8_t tmp_0;
                /*@>1dec2c*/rtDW./*@>1e7a10*/absx11/*@>1e7212*/ -= static_cast<double>(/*@>195908*/p3);
                /*@>1bd757*/p2/*@>1bd759*/ = (/*@>195ad0*/p3/*@>17fc5c*/ - /*@>195ad2*/1)/*@>196dc5*/ * /*@>195bf0*/480/*@>190764*/ + /*@>195acd*/itmp;
                /*@>1bd741*/tmp/*@>1bd743*/ = /*@>1dec4a*/rtDW./*@>1e7a1c*/inputImage/*@>1da7c7*/[/*@>1da7c3*/p2/*@>1da7c1*/ - /*@>1da7c4*/1];
                /*@>1bd761*/p3/*@>1bd763*/ = /*@>195bf1*/480/*@>196dc8*/ * /*@>195ad8*/p3/*@>190766*/ + /*@>195ad5*/itmp;
                /*@>1bd74d*/tmp_0/*@>1bd74f*/ = /*@>1dec5c*/rtDW./*@>1e7a25*/inputImage/*@>1da7d5*/[/*@>1da7d1*/p3/*@>1da7cf*/ - /*@>1da7d2*/1];
                /*@>1a77d3*/if (/*@>1bd745*/tmp/*@>11eb45*/ == /*@>1bd751*/tmp_0) {
                    /*@>1a77d7*/qx1/*@>1a77d6*/ = tmp;
                } else {
                    /*@>195c02*/qx1/*@>18fd9e*/ = static_cast<float>(/*@>19593c*/1.0/*@>1223c6*/ - /*@>1dec68*/rtDW./*@>1e7a2b*/absx11)/*@>196db6*/ * static_cast<float>(tmp)/*@>11eb46*/ + static_cast<float>(tmp_0)/*@>196dbd*/ * static_cast<float>(/*@>1dec6e*/rtDW./*@>1e7a2e*/absx11);
                }
                /*@>1bd76b*/tmp/*@>1bd76d*/ = /*@>1dec8c*/rtDW./*@>1e7a3d*/inputImage/*@>1da7db*/[p2];
                /*@>1bd777*/tmp_0/*@>1bd779*/ = /*@>1dec92*/rtDW./*@>1e7a40*/inputImage/*@>1da7e1*/[p3];
                /*@>1a77d8*/if (/*@>1bd76f*/tmp/*@>11eb47*/ == /*@>1bd77b*/tmp_0) {
                    /*@>1a77dc*/qx2/*@>1a77db*/ = tmp;
                } else {
                    /*@>195c04*/qx2/*@>18fda3*/ = static_cast<float>(/*@>19593f*/1.0/*@>1223e1*/ - /*@>1dec98*/rtDW./*@>1e7a43*/absx11)/*@>196d9f*/ * static_cast<float>(tmp)/*@>11eb48*/ + static_cast<float>(tmp_0)/*@>196da6*/ * static_cast<float>(/*@>1dec9e*/rtDW./*@>1e7a46*/absx11);
                }
            }
            /*@>11eb63*/if ((/*@>1dec56*/rtDW./*@>1e7a22*/absx21/*@>11eb49*/ == /*@>195911*/itmp)/*@>1e533a*/ || (/*@>1958d4*/qx1/*@>11eb4a*/ == /*@>1958d6*/qx2)) {
                /*@>1ae216*/qx2/*@>11eb21*/ = /*@>1958d8*/qx1;
            } else /*@>11eb67*/if (!/*@<1c9ff2*/(static_cast<double>(/*@>195942*/itmp)/*@>12209f*/ + /*@>195913*/1.0/*@>11eb4b*/ == /*@>1dec62*/rtDW./*@>1e7a28*/absx21)) {
                /*@>1dec74*/rtDW./*@>1e7a31*/absx11/*@>11eb33*/ = /*@>1dec7a*/rtDW./*@>1e7a34*/absx21/*@>11eb4c*/ - static_cast<double>(/*@>195914*/itmp);
                /*@>1ae212*/qx2/*@>11eb3e*/ = static_cast<float>(/*@>195946*/1.0/*@>122405*/ - /*@>1dec80*/rtDW./*@>1e7a37*/absx11)/*@>196d93*/ * /*@>195919*/qx1/*@>11eb50*/ + static_cast<float>(/*@>1dec86*/rtDW./*@>1e7a3a*/absx11)/*@>196d97*/ * /*@>19591d*/qx2;
            }
        } else {
            /*@>1e7199*/qx2/*@>1e7198*/ = /*@>1e719a*/0.0F;
        }
    } else {
        /*@>1ae210*/qx2/*@>11ea3c*/ = /*@>1958bd*/0.0F;
    }
    /*@>1d34a4*/Jout/*@>17f927*/[/*@>195a88*/p1]/*@>17f928*/ = (/*@>1ae218*/qx2/*@>17f912*/ > /*@>19595f*/0.5F);
}


        }

                



            


                        


         

                
                void Rpi_cam::and_o(bool in1_data[], int32_t *in1_size, const bool in2_data[], const int32_t *in2_size, const bool in3_data[], const int32_t *in3_size)
        {
            int32_t loop_ub;
int32_t stride_0_0;
int32_t stride_1_0;
/* {S!d564}MATLAB Function: '<S2>/MATLAB Function1' */
/*@>1c4241*/loop_ub/*@>1c4243*/ = *in3_size/*@>181579*/ == /*@>196939*/1/*@>181579*/ ? *in2_size : *in3_size;
*in1_size/*@>181599*/ = /*@>1c4245*/loop_ub;
/*@>196959*/stride_0_0/*@>1815ed*/ = (*in2_size/*@>18aad7*/ != /*@>196973*/1);
/*@>19695b*/stride_1_0/*@>1815f9*/ = (*in3_size/*@>18aaf7*/ != /*@>196977*/1);
/*@>1815d6*/for ( int32_t /*@>1e7b46*/i{/*@>1e7b45*/0}; /*@>1e7b53*/i < loop_ub; /*@>1e7b4c*/i/*@>1e7b56*/++) {
    /*@>1cdc06*/in1_data/*@>1815b3*/[/*@>196947*/i]/*@>1815b4*/ = (/*@>1daadb*/in2_data/*@>1daadd*/[/*@>1daad7*/i * /*@>1daad9*/stride_0_0]/*@>18159e*/ && /*@>1daae5*/in3_data/*@>1daae7*/[/*@>1daae1*/i * /*@>1daae3*/stride_1_0]);
}
/* {E!d564}End of MATLAB Function: '<S2>/MATLAB Function1' */


        }

                





                        


         

                
                void Rpi_cam::binary_expand_op_3(bool in1_data[], int32_t *in1_size, const bool in2_data[], const int32_t *in2_size, const int32_t in3_data[], const int32_t *in3_size)
        {
            int32_t loop_ub;
int32_t stride_0_0;
int32_t stride_1_0_tmp;
/* {S!d572}MATLAB Function: '<S2>/MATLAB Function1' */
/*@>1c4efc*/loop_ub/*@>1c4efe*/ = *in3_size/*@>181ad9*/ == /*@>196b00*/1/*@>181ad9*/ ? *in3_size/*@>181ae2*/ == /*@>196b04*/1/*@>181ae2*/ ? *in2_size : *in3_size : *in3_size;
*in1_size/*@>181b08*/ = /*@>1c4f00*/loop_ub;
/*@>196b30*/stride_0_0/*@>181b77*/ = (*in2_size/*@>18acac*/ != /*@>196b53*/1);
stride_1_0_tmp = (*in3_size/*@>18accc*/ != /*@>196b57*/1);
/*@>181b5f*/for ( int32_t /*@>1e7bc4*/i{/*@>1e7bc3*/0}; /*@>1e7bd1*/i < loop_ub; /*@>1e7bca*/i/*@>1e7bd4*/++) {
    int32_t tmp;
    /*@>1c4f06*/tmp/*@>1c4f08*/ = /*@>1dab39*/in3_data/*@>1dab3b*/[/*@>1dab35*/i * stride_1_0_tmp];
    /*@>1cde04*/in1_data/*@>181b2d*/[/*@>196b17*/i]/*@>181b2e*/ = (/*@>1dab43*/in2_data/*@>1dab45*/[/*@>1dab3f*/i * /*@>1dab41*/stride_0_0]/*@>181b0f*/ && (/*@>1c4f0a*/tmp/*@>181b17*/ >= /*@>196afb*/0)/*@>181b0e*/ && (tmp/*@>181b1f*/ < /*@>196afc*/160));
}
/* {E!d572}End of MATLAB Function: '<S2>/MATLAB Function1' */


        }

                



            


                        


         

                
                void Rpi_cam::binary_expand_op_2(bool in1_data[], int32_t *in1_size, const bool in2_data[], const int32_t *in2_size, const bool in3_data[], const bool in4_data[], const int32_t *in4_size, const bool in5_data[], const int32_t *in5_size)
        {
            int32_t loop_ub;
int32_t stride_0_0;
int32_t stride_1_0;
int32_t stride_2_0;
/* {S!d570}MATLAB Function: '<S2>/MATLAB Function1' */
/*@>1c4bbe*/loop_ub/*@>1c4bc0*/ = *in5_size/*@>181955*/ == /*@>196a72*/1/*@>181955*/ ? *in4_size/*@>18195e*/ == /*@>196a76*/1/*@>18195e*/ ? *in2_size : *in4_size : *in5_size;
*in1_size/*@>181984*/ = /*@>1c4bc2*/loop_ub;
/*@>196aa4*/stride_0_0/*@>1819f9*/ = (*in2_size/*@>18ac2c*/ != /*@>196acb*/1);
/*@>196aa6*/stride_1_0/*@>181a05*/ = (*in4_size/*@>18ac4c*/ != /*@>196acf*/1);
/*@>196aa8*/stride_2_0/*@>181a11*/ = (*in5_size/*@>18ac6c*/ != /*@>196ad3*/1);
/*@>1819e1*/for ( int32_t /*@>1e7df0*/i{/*@>1e7def*/0}; /*@>1e7dfd*/i < loop_ub; /*@>1e7df6*/i/*@>1e7e00*/++) {
    int32_t tmp;
    tmp = /*@>196abb*/i * /*@>196abd*/stride_0_0;
    /*@>1cdd77*/in1_data/*@>1819af*/[/*@>196a8b*/i]/*@>1819b0*/ = (/*@>1dab14*/in2_data/*@>1dab16*/[tmp]/*@>18198c*/ && /*@>1dab1b*/in3_data/*@>1dab1d*/[tmp]/*@>18198b*/ && /*@>1dab25*/in4_data/*@>1dab27*/[/*@>1dab21*/i * /*@>1dab23*/stride_1_0]/*@>18198a*/ && /*@>1dab2f*/in5_data/*@>1dab31*/[/*@>1dab2b*/i * /*@>1dab2d*/stride_2_0]);
}
/* {E!d570}End of MATLAB Function: '<S2>/MATLAB Function1' */


        }

                





                        


         

                
                void Rpi_cam::binary_expand_op(bool in1_data[], int32_t *in1_size, const int32_t in2_data[], const int32_t *in2_size, double in3, double in4, const int32_t in5_data[], const int32_t *in5_size, double in6)
        {
            int32_t loop_ub;
int32_t stride_0_0;
int32_t stride_1_0;
/* {S!d566}MATLAB Function: '<S2>/MATLAB Function1' */
/*@>1c4531*/loop_ub/*@>1c4533*/ = *in5_size/*@>1816aa*/ == /*@>1969a0*/1/*@>1816aa*/ ? *in2_size : *in5_size;
*in1_size/*@>1816ca*/ = /*@>1c4535*/loop_ub;
/*@>1969c2*/stride_0_0/*@>181735*/ = (*in2_size/*@>18ab27*/ != /*@>1969e0*/1);
/*@>1969c4*/stride_1_0/*@>181741*/ = (*in5_size/*@>18ab47*/ != /*@>1969e4*/1);
/*@>18171e*/for ( int32_t /*@>1e7e9b*/i{/*@>1e7e9a*/0}; /*@>1e7ea8*/i < loop_ub; /*@>1e7ea1*/i/*@>1e7eab*/++) {
    double tmp;
    /*@>1c453b*/tmp/*@>1c453d*/ = /*@>1daaef*/in2_data/*@>1daaf1*/[/*@>1daaeb*/i * /*@>1daaed*/stride_0_0];
    /*@>1cdc7b*/in1_data/*@>1816fb*/[/*@>1969b0*/i]/*@>1816fc*/ = ((/*@>1c453f*/tmp/*@>1816d1*/ >= /*@>196993*/in3)/*@>1816d0*/ && (tmp/*@>1816dd*/ < /*@>196995*/in4)/*@>1816cf*/ && (/*@>1daaf9*/in5_data/*@>1daafb*/[/*@>1daaf5*/i * /*@>1daaf7*/stride_1_0]/*@>1816e9*/ >= /*@>1a6231*/in6/*@>1a622f*/ - /*@>1a6232*/40.0));
}
/* {E!d566}End of MATLAB Function: '<S2>/MATLAB Function1' */


        }

                





                        


         

                
                void Rpi_cam::binary_expand_op_1(bool in1_data[], int32_t *in1_size, const double in2_data[], const int32_t *in2_size, double in3, double in4, const double in5_data[], const int32_t *in5_size, double in6)
        {
            int32_t loop_ub;
int32_t stride_0_0;
int32_t stride_1_0;
/* {S!d568}MATLAB Function: '<S2>/MATLAB Function1' */
/*@>1c4828*/loop_ub/*@>1c482a*/ = *in5_size/*@>1817f2*/ == /*@>196a0e*/1/*@>1817f2*/ ? *in2_size : *in5_size;
*in1_size/*@>181812*/ = /*@>1c482c*/loop_ub;
/*@>196a30*/stride_0_0/*@>181871*/ = (*in2_size/*@>18aba7*/ != /*@>196a4e*/1);
/*@>196a32*/stride_1_0/*@>18187d*/ = (*in5_size/*@>18abc7*/ != /*@>196a52*/1);
/*@>18185a*/for ( int32_t /*@>1e7f29*/i{/*@>1e7f28*/0}; /*@>1e7f36*/i < loop_ub; /*@>1e7f2f*/i/*@>1e7f39*/++) {
    double tmp;
    /*@>1c4832*/tmp/*@>1c4834*/ = /*@>1dab03*/in2_data/*@>1dab05*/[/*@>1daaff*/i * /*@>1dab01*/stride_0_0];
    /*@>1cdcef*/in1_data/*@>181837*/[/*@>196a1e*/i]/*@>181838*/ = ((/*@>1c4836*/tmp/*@>181819*/ >= /*@>196a01*/in3)/*@>181818*/ && (tmp/*@>181821*/ < /*@>196a03*/in4)/*@>181817*/ && (/*@>1dab0d*/in5_data/*@>1dab0f*/[/*@>1dab09*/i * /*@>1dab0b*/stride_1_0]/*@>181829*/ >= /*@>1a625b*/in6/*@>1a6259*/ - /*@>1a625c*/40.0));
}
/* {E!d568}End of MATLAB Function: '<S2>/MATLAB Function1' */


        }

                





                        


         

                
                codertarget_raspi_internal_Raspiv4l2Capture *Rpi_cam::Raspiv4l2Capture_Raspiv4l2Capture(codertarget_raspi_internal_Raspiv4l2Capture *obj)
        {
            codertarget_raspi_internal_Raspiv4l2Capture *b_obj;
/* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>195e27*/obj->/*@>1e7ffb*/BrightnessInternal/*@>156ffc*/ = /*@>195e12*/0.5;
/*@>195e29*/obj->/*@>1e7ffe*/SaturationInternal/*@>157002*/ = /*@>195e14*/0.5;
/*@>195e2b*/obj->/*@>1e8001*/ContrastInternal/*@>157008*/ = /*@>195e16*/0.5;
/*@>195e2d*/obj->/*@>1e8004*/SharpnessInternal/*@>15700e*/ = /*@>195e18*/0.5;
/*@>195e2f*/obj->/*@>1e8007*/CameraZoomInternal/*@>157014*/ = /*@>195e1a*/0.5;
/*@>195e31*/obj->/*@>1e800a*/ManualFocusInternal/*@>15701a*/ = /*@>195e1c*/0.5;
/*@>195e33*/obj->/*@>1e800d*/CameraPanInternal/*@>157020*/ = /*@>195e1e*/0.0;
/*@>195e35*/obj->/*@>1e8010*/CameraTiltInternal/*@>157026*/ = /*@>195e20*/0.0;
/*@>195e37*/obj->/*@>1e8013*/EnableManualFocusInternal/*@>15702c*/ = /*@>195e22*/true;
/*@>195e39*/obj->/*@>1e8016*/isInitialized/*@>1570da*/ = /*@>1e7fb2*/0;
/*@>195e24*/b_obj/*@>157087*/ = /*@>195e3b*/obj;
/*@>195e3d*/obj->matlabCodegenIsDeleted = false;
return b_obj;


        }

                





                        


         

                
                void Rpi_cam::SystemCore_setup(codertarget_raspi_internal_Raspiv4l2Capture *obj)
        {
            int32_t i;
int8_t resolutionStatus;
uint8_t camIndex;
static const std::array<char, 12> devName{ { '/', 'd', 'e', 'v', '/', 'v', 'i', 'd', 'e', 'o', '0', '\x00' } };
static const std::array<char, 101> b_errorMessage{ { 'W', 'e', 'b', 'c', 'a', 'm', ' ', 'c', 'a', 'n', 'n', 'o', 't', ' ', 'b', 'e', ' ', 'i', 'n', 'i', 't', 'i', 'a', 'l', 'i', 'z', 'e', 'd', ' ', 'p', 'r', 'o', 'p', 'e', 'r', 'l', 'y', '.', ' ', 'P', 'l', 'e', 'a', 's', 'e', ' ', 'c', 'h', 'e', 'c', 'k', ' ', 'i', 'f', ' ', 't', 'h', 'e', ' ', 'd', 'e', 'v', 'i', 'c', 'e', ' ', 's', 'u', 'p', 'p', 'o', 'r', 't', 's', ' ', 't', 'h', 'e', ' ', 's', 'p', 'e', 'c', 'i', 'f', 'i', 'e', 'd', ' ', 'r', 'e', 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', '.', '\x00' } };



/*@>195e4e*/obj->/*@>1e80b7*/isSetupComplete/*@>fe72a*/ = /*@>195e57*/false;
/* {S!d534}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>195e51*/obj->/*@>1e80ba*/isInitialized/*@>fe751*/ = /*@>1e8043*/1;
/*@>1d35a8*/getCameraList();
/*@>180465*/for (/*@>1e804b*/i = /*@>1e804a*/0; /*@>1e8055*/i < /*@>1e8053*/12; /*@>1e8051*/i/*@>1e8059*/++) {
    /*@>1decb0*/rtDW./*@>1e80c3*/devName/*@>18f266*/[/*@>195e87*/i]/*@>180458*/ = /*@>1da842*/devName/*@>1da844*/[/*@>1da841*/i];
}
/* {S!d536}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>195e59*/camIndex/*@>157235*/ = /*@>1d35aa*/getCameraAddrIndex(&/*@>1decaa*/rtDW./*@>1e80c0*/devName/*@>18f277*/[/*@>195e9f*/0], /*@>195e73*/11U);
/*@>195e5d*/resolutionStatus/*@>15723f*/ = /*@>1d35ac*/validateResolution(/*@>195e5f*/camIndex, /*@>1b0a46*/640, /*@>1b0a49*/480);
/*@>1572a8*/if (/*@>195e61*/resolutionStatus/*@>157273*/ >= /*@>195e63*/0) {
    /* {S!d538}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
    /*@>1d35b4*/EXT_webcamInit(/*@>1b0a4f*/0, /*@>1b0a52*/0, /*@>195e77*/0, /*@>195e78*/0, /*@>195e79*/0, /*@>195e7a*/0, /*@>195e7b*/640U, /*@>195e7c*/480U, /*@>195e7d*/2U, /*@>195e7e*/2U, /*@>195e7f*/1U, /*@>195e68*/0.1);
} else {
    /* {S!d540}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
    /*@>1d4845*/std::memcpy(&/*@>1decbc*/rtDW./*@>1e80c6*/b_errorMessage/*@>1d0e3f*/[/*@>1d0e2e*/0], &/*@>1d0e46*/b_errorMessage/*@>1d0e47*/[/*@>1d0e3b*/0], /*@>1d0e3d*/101U/*@>1d0e4a*/ * /*@>1d0e49*/sizeof(char));
    /*@>1d35b0*/std::perror(&/*@>1decc2*/rtDW./*@>1e80c9*/b_errorMessage/*@>18f295*/[/*@>195ea0*/0]);
    /* {S!d542}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
    /*@>1d35b2*/std::exit(/*@>195e80*/0);
}
/* {S!d544}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@[1e5984*/v4l2Capture_updateV4L2Settings(/*@>1e80f8*/obj, /*@>1e8106*/true)/*@]*/;
/*@>195e54*/obj->/*@>1e80bd*/isSetupComplete/*@>fe7d1*/ = /*@>195e58*/true;


        }

                



                        




        // Model step function
        
                    
        void Rpi_cam::step() 
        {
            


        

                
        
            
uint8_t xtmp;
static const std::array<int16_t, 8> tmp{ { 145, 500, 27, 639, 300, 300, 415, 415 } };
static const std::array<int16_t, 8> tmp_0{ { 40, 600, 40, 600, 300, 300, 480, 480 } };

            
            



        

        




                
        




                                                    
                                    /* {S!d462}MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>15fbc0*/if (/*@>1dcfac*/rtDW./*@>1e9d96*/obj.Brightness/*@>15fb7e*/ != /*@>195473*/0.5) {
    /*@>1dcfb2*/rtDW./*@>1e9d99*/obj./*@>1e9d7e*/Brightness/*@>15fbb7*/ = /*@>195474*/0.5;
}
/*@>15fbc3*/if (/*@>1dcfb8*/rtDW./*@>1e9d9c*/obj.Saturation/*@>15fb7d*/ != /*@>195475*/0.5) {
    /*@>1dcfbe*/rtDW./*@>1e9d9f*/obj./*@>1e9d81*/Saturation/*@>15fbaf*/ = /*@>195476*/0.5;
}
/*@>15fbc6*/if (/*@>1dcfc4*/rtDW./*@>1e9da2*/obj.Contrast/*@>15fb7c*/ != /*@>195477*/0.5) {
    /*@>1dcfca*/rtDW./*@>1e9da5*/obj./*@>1e9d84*/Contrast/*@>15fba7*/ = /*@>195478*/0.5;
}
/*@>15fbc9*/if (/*@>1dcfd0*/rtDW./*@>1e9da8*/obj.Sharpness/*@>15fb7b*/ != /*@>195479*/0.5) {
    /*@>1dcfd6*/rtDW./*@>1e9dab*/obj./*@>1e9d87*/Sharpness/*@>15fb9f*/ = /*@>19547a*/0.5;
}
/*@>15fbcc*/if (/*@>1dcfdc*/rtDW./*@>1e9dae*/obj.CameraPan/*@>15fb7a*/ != /*@>19547b*/0.0) {
    /*@>1dcfe2*/rtDW./*@>1e9db1*/obj./*@>1e9d8a*/CameraPan/*@>15fb97*/ = /*@>19547c*/0.0;
}
/*@>15fbcf*/if (/*@>1dcfe8*/rtDW./*@>1e9db4*/obj.CameraTilt/*@>15fb79*/ != /*@>19547d*/0.0) {
    /*@>1dcfee*/rtDW./*@>1e9db7*/obj./*@>1e9d8d*/CameraTilt/*@>15fb8f*/ = /*@>19547e*/0.0;
}
/*@>15fbd2*/if (/*@>1dcff4*/rtDW./*@>1e9dba*/obj.CameraZoom/*@>15fb78*/ != /*@>19547f*/0.5) {
    /*@>1dcffa*/rtDW./*@>1e9dbd*/obj./*@>1e9d90*/CameraZoom/*@>15fb87*/ = /*@>195480*/0.5;
}
/*@>15fbd5*/if (/*@>1dd000*/rtDW./*@>1e9dc0*/obj.ManualFocus/*@>15fb77*/ != /*@>195481*/0.5) {
    /*@>1dd006*/rtDW./*@>1e9dc3*/obj./*@>1e9d93*/ManualFocus/*@>15fb7f*/ = /*@>195482*/0.5;
}
/*@[1e599e*/SystemCore_step(&/*@>1eab41*/rtDW./*@>1eab40*/obj, &/*@>1eab53*/rtDW./*@>1eab52*/uv[0], &/*@>1eab66*/rtDW./*@>1eab65*/uv1[0], &/*@>1eab79*/rtDW./*@>1eab78*/uv2[0])/*@]*/;
/* {S!d464}Math: '<S3>/Transpose' incorporates:
 *  MATLABSystem: '<Root>/V4L2 Video Capture'
 */
/*@>17b9de*/for (/*@>1e8900*/rtDW./*@>1eaace*/i = /*@>1e88fe*/0; /*@>1e8910*/rtDW./*@>1eaad4*/i < /*@>1e890d*/640; /*@>1e890a*/rtDW./*@>1eaad1*/i/*@>1e8930*/++) {
/*@>17b9ce*/    for (/*@>1e891b*/rtDW./*@>1eaad7*/inlierNum = /*@>1e8919*/0; /*@>1e892b*/rtDW./*@>1eaadd*/inlierNum < /*@>1e8928*/480; /*@>1e8925*/rtDW./*@>1eaada*/inlierNum/*@>1e8931*/++) {
        /*@>1dd060*/rtDW./*@>1e9dd8*/uv3/*@>18e8f5*/[/*@>1dd066*/rtDW./*@>1e9ddb*/inlierNum/*@>18e8f1*/ + /*@>19555e*/480/*@>196bb0*/ * /*@>1dd06c*/rtDW./*@>1e9dde*/i]/*@>17b9c1*/ = /*@>1dd072*/rtDW./*@>1e9de1*/uv/*@>1da293*/[/*@>1da28c*/640/*@>1da28b*/ * /*@>1dd078*/rtDW./*@>1e9de4*/inlierNum/*@>1da28a*/ + /*@>1dd07e*/rtDW./*@>1e9de7*/i];
    }
}
/*@>1d4832*/std::memcpy(&/*@>1dd042*/rtDW./*@>1e9dcc*/outputImage/*@>1d0314*/[/*@>1d0302*/0], &/*@>1dd048*/rtDW./*@>1e9dcf*/uv3/*@>1d031c*/[/*@>1d030f*/0], /*@>1d0312*/307200U/*@>1d031f*/ * /*@>1d031e*/sizeof(uint8_t));
/* {E!d464}End of Math: '<S3>/Transpose' */

/* {S!d466}Math: '<S3>/Transpose1' incorporates:
 *  MATLABSystem: '<Root>/V4L2 Video Capture'
 */
/*@>17bab4*/for (/*@>1e88ca*/rtDW./*@>1eaabc*/i = /*@>1e88c8*/0; /*@>1e88da*/rtDW./*@>1eaac2*/i < /*@>1e88d7*/640; /*@>1e88d4*/rtDW./*@>1eaabf*/i/*@>1e8932*/++) {
/*@>17baa4*/    for (/*@>1e88e5*/rtDW./*@>1eaac5*/inlierNum = /*@>1e88e3*/0; /*@>1e88f5*/rtDW./*@>1eaacb*/inlierNum < /*@>1e88f2*/480; /*@>1e88ef*/rtDW./*@>1eaac8*/inlierNum/*@>1e8933*/++) {
        /*@>1dd0a2*/rtDW./*@>1e9df6*/uv/*@>18e917*/[/*@>1dd0a8*/rtDW./*@>1e9df9*/inlierNum/*@>18e913*/ + /*@>195560*/480/*@>196bb6*/ * /*@>1dd0ae*/rtDW./*@>1e9dfc*/i]/*@>17ba97*/ = /*@>1dd0b4*/rtDW./*@>1e9dff*/uv1/*@>1da29e*/[/*@>1da297*/640/*@>1da296*/ * /*@>1dd0ba*/rtDW./*@>1e9e02*/inlierNum/*@>1da295*/ + /*@>1dd0c0*/rtDW./*@>1e9e05*/i];
    }
}
/*@>1d4834*/std::memcpy(&/*@>1dd084*/rtDW./*@>1e9dea*/outputImage/*@>1d02a7*/[/*@>1d0295*/307200], &/*@>1dd08a*/rtDW./*@>1e9ded*/uv/*@>1d02af*/[/*@>1d02a2*/0], /*@>1d02a5*/307200U/*@>1d02b2*/ * /*@>1d02b1*/sizeof(uint8_t));
/* {E!d466}End of Math: '<S3>/Transpose1' */

/* {S!d468}Math: '<S3>/Transpose2' incorporates:
 *  MATLABSystem: '<Root>/V4L2 Video Capture'
 */
/*@>17bb8e*/for (/*@>1e8894*/rtDW./*@>1eaaaa*/i = /*@>1e8892*/0; /*@>1e88a4*/rtDW./*@>1eaab0*/i < /*@>1e88a1*/640; /*@>1e889e*/rtDW./*@>1eaaad*/i/*@>1e8934*/++) {
/*@>17bb7e*/    for (/*@>1e88af*/rtDW./*@>1eaab3*/inlierNum = /*@>1e88ad*/0; /*@>1e88bf*/rtDW./*@>1eaab9*/inlierNum < /*@>1e88bc*/480; /*@>1e88b9*/rtDW./*@>1eaab6*/inlierNum/*@>1e8935*/++) {
        /*@>1dd0de*/rtDW./*@>1e9e14*/uv/*@>18e936*/[/*@>1dd0e4*/rtDW./*@>1e9e17*/inlierNum/*@>18e932*/ + /*@>195562*/480/*@>196bbc*/ * /*@>1dd0ea*/rtDW./*@>1e9e1a*/i]/*@>17bb71*/ = /*@>1dd0f0*/rtDW./*@>1e9e1d*/uv2/*@>1da2a9*/[/*@>1da2a2*/640/*@>1da2a1*/ * /*@>1dd0f6*/rtDW./*@>1e9e20*/inlierNum/*@>1da2a0*/ + /*@>1dd0fc*/rtDW./*@>1e9e23*/i];
    }
}
/*@>1d4836*/std::memcpy(&/*@>1dd0c6*/rtDW./*@>1e9e08*/outputImage/*@>1d023a*/[/*@>1d0228*/614400], &/*@>1dd0cc*/rtDW./*@>1e9e0b*/uv/*@>1d0242*/[/*@>1d0235*/0], /*@>1d0238*/307200U/*@>1d0245*/ * /*@>1d0244*/sizeof(uint8_t));
/* {E!d468}End of Math: '<S3>/Transpose2' */

/* {S!d470}MATLAB Function: '<Root>/MATLAB Function' */
/*@>15f8b4*/for (/*@>1e8843*/rtDW./*@>1eaa8f*/inlierNum = /*@>1e8841*/0; /*@>1e8853*/rtDW./*@>1eaa95*/inlierNum < /*@>1e8850*/3; /*@>1e884d*/rtDW./*@>1eaa92*/inlierNum/*@>1e8936*/++) {
/*@>15f8b6*/    for (/*@>1e885e*/rtDW./*@>1eaa98*/j = /*@>1e885c*/0; /*@>1e886e*/rtDW./*@>1eaa9e*/j < /*@>1e886b*/640; /*@>1e8868*/rtDW./*@>1eaa9b*/j/*@>1e8937*/++) {
/*@>15f8b8*/        for (/*@>1e8879*/rtDW./*@>1eaaa1*/svdRsltVar = /*@>1e8877*/0; /*@>1e8889*/rtDW./*@>1eaaa7*/svdRsltVar < /*@>1e8886*/240; /*@>1e8883*/rtDW./*@>1eaaa4*/svdRsltVar/*@>1e8938*/++) {
            /*@>1dd12c*/rtDW./*@>1e9e38*/i/*@>1bbd42*/ = (/*@>19554b*/480/*@>196bd4*/ * /*@>1dd132*/rtDW./*@>1e9e3b*/j/*@>18a596*/ + /*@>1dd138*/rtDW./*@>1e9e3e*/svdRsltVar)/*@>18a59b*/ + /*@>19554c*/307200/*@>196bd7*/ * /*@>1dd13e*/rtDW./*@>1e9e41*/inlierNum;
            /*@>194bd5*/xtmp/*@>15f8ac*/ = /*@>1dd15c*/rtDW./*@>1e9e50*/outputImage/*@>1da2b5*/[/*@>1dd162*/rtDW./*@>1e9e53*/i];
            /*@>1dd186*/rtDW./*@>1e9e62*/outputImage_tmp/*@>1bbd4c*/ = ((/*@>19554f*/480/*@>196bce*/ * /*@>1dd18c*/rtDW./*@>1e9e65*/j/*@>1904f1*/ - /*@>1dd192*/rtDW./*@>1e9e68*/svdRsltVar)/*@>1904f3*/ + /*@>195550*/307200/*@>196bd1*/ * /*@>1dd198*/rtDW./*@>1e9e6b*/inlierNum)/*@>1904f4*/ + /*@>194ee1*/479;
            /*@>1dd1b0*/rtDW./*@>1e9e77*/outputImage/*@>18a5af*/[rtDW.i]/*@>15f8b0*/ = /*@>1dd1bc*/rtDW./*@>1e9e7d*/outputImage/*@>1da2c1*/[/*@>1dd1c2*/rtDW./*@>1e9e80*/outputImage_tmp];
            /*@>1dd1e0*/rtDW./*@>1e9e8f*/outputImage/*@>18a5ce*/[rtDW.outputImage_tmp]/*@>15f8b3*/ = /*@>194bd7*/xtmp;
        }
    }
}
/*@>15f8dc*/for (/*@>1e87f2*/rtDW./*@>1eaa74*/svdRsltVar = /*@>1e87f0*/0; /*@>1e8802*/rtDW./*@>1eaa7a*/svdRsltVar < /*@>1e87ff*/3; /*@>1e87fc*/rtDW./*@>1eaa77*/svdRsltVar/*@>1e8939*/++) {
/*@>15f8de*/    for (/*@>1e880d*/rtDW./*@>1eaa7d*/inlierNum = /*@>1e880b*/0; /*@>1e881d*/rtDW./*@>1eaa83*/inlierNum < /*@>1e881a*/320; /*@>1e8817*/rtDW./*@>1eaa80*/inlierNum/*@>1e893a*/++) {
/*@>15f8e0*/        for (/*@>1e8828*/rtDW./*@>1eaa86*/j = /*@>1e8826*/0; /*@>1e8838*/rtDW./*@>1eaa8c*/j < /*@>1e8835*/480; /*@>1e8832*/rtDW./*@>1eaa89*/j/*@>1e893b*/++) {
            /*@>1dd16e*/rtDW./*@>1e9e56*/i/*@>1bbd56*/ = (/*@>195553*/480/*@>196bec*/ * /*@>1dd174*/rtDW./*@>1e9e59*/inlierNum/*@>18a5d4*/ + /*@>1dd17a*/rtDW./*@>1e9e5c*/j)/*@>18a5d9*/ + /*@>195554*/307200/*@>196bef*/ * /*@>1dd180*/rtDW./*@>1e9e5f*/svdRsltVar;
            /*@>194be8*/xtmp/*@>15f8d4*/ = /*@>1dd1a4*/rtDW./*@>1e9e71*/outputImage/*@>1da2bb*/[/*@>1dd1aa*/rtDW./*@>1e9e74*/i];
            /*@>1dd1c8*/rtDW./*@>1e9e83*/outputImage_tmp/*@>1bbd60*/ = ((/*@>194f01*/639/*@>17bde2*/ - /*@>1dd1ce*/rtDW./*@>1e9e86*/inlierNum)/*@>196be6*/ * /*@>195557*/480/*@>18a5f3*/ + /*@>1dd1d4*/rtDW./*@>1e9e89*/j)/*@>18a5f8*/ + /*@>195558*/307200/*@>196be9*/ * /*@>1dd1da*/rtDW./*@>1e9e8c*/svdRsltVar;
            /*@>1dd1f2*/rtDW./*@>1e9e95*/outputImage/*@>18a5ed*/[rtDW.i]/*@>15f8d8*/ = /*@>1dd1fe*/rtDW./*@>1e9e9b*/outputImage/*@>1da2c7*/[/*@>1dd204*/rtDW./*@>1e9e9e*/outputImage_tmp];
            /*@>1dd222*/rtDW./*@>1e9eaa*/outputImage/*@>18a60c*/[rtDW.outputImage_tmp]/*@>15f8db*/ = /*@>194bea*/xtmp;
        }
    }
}
/* {E!d470}End of MATLAB Function: '<Root>/MATLAB Function' */

/* {S!d472}S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion' */
/*@>181efd*/for (/*@>1e87d7*/rtDW./*@>1eaa6b*/svdRsltVar = /*@>1e87d5*/0; /*@>1e87e7*/rtDW./*@>1eaa71*/svdRsltVar < /*@>1e87e4*/921600; /*@>1e87e1*/rtDW./*@>1eaa6e*/svdRsltVar/*@>1e893c*/++) {
    /*@>1dd144*/rtDW./*@>1e9e44*/ImageDataTypeConversion/*@>17bca1*/[/*@>1dd14a*/rtDW./*@>1e9e47*/svdRsltVar]/*@>15d79f*/ = static_cast<double>(/*@>1dd150*/rtDW./*@>1e9e4a*/outputImage/*@>1da2af*/[/*@>1dd156*/rtDW./*@>1e9e4d*/svdRsltVar])/*@>15d79c*/ / /*@>194a3c*/255.0;
}
/* {E!d472}End of S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion' */
/* temporary variables for in-place operation */
/*@>181ee6*/for (/*@>1e87bc*/rtDW./*@>1eaa62*/svdRsltVar = /*@>1e87ba*/0; /*@>1e87cc*/rtDW./*@>1eaa68*/svdRsltVar < /*@>1e87c9*/307200; /*@>1e87c6*/rtDW./*@>1eaa65*/svdRsltVar/*@>1e893e*/++) {
    /* {S!d474}S-Function (svipcolorconv): '<S4>/Color Space  Conversion' incorporates:
 *  S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion'
 */
    /* First get the min and max of the RGB triplet */
    /*@>1dd210*/rtDW./*@>1e9ea1*/ImageDataTypeConversion_c/*@>188d83*/ = /*@>1dd216*/rtDW./*@>1e9ea4*/ImageDataTypeConversion/*@>1da2cd*/[/*@>1dd21c*/rtDW./*@>1e9ea7*/svdRsltVar];
    /*@>1dd234*/rtDW./*@>1e9eb3*/ImageDataTypeConversion_k/*@>188da9*/ = /*@>1dd23a*/rtDW./*@>1e9eb6*/ImageDataTypeConversion/*@>1da2d5*/[/*@>1dd240*/rtDW./*@>1e9eb9*/svdRsltVar/*@>1da2cf*/ + /*@>1da2d2*/307200];
    /*@>15f6b0*/if (/*@>1dd246*/rtDW./*@>1e9ebc*/ImageDataTypeConversion_c/*@>15f6af*/ > /*@>1dd24c*/rtDW./*@>1e9ebf*/ImageDataTypeConversion_k) {
        /*@>1dd27c*/rtDW./*@>1e9ed4*/ImageDataTypeConversion_cx/*@>188ddc*/ = /*@>1dd282*/rtDW./*@>1e9ed7*/ImageDataTypeConversion/*@>1da2eb*/[/*@>1dd288*/rtDW./*@>1e9eda*/svdRsltVar/*@>1da2e5*/ + /*@>1da2e8*/614400];
        /*@>1a77b1*/if (/*@>1dd2b2*/rtDW./*@>1e9eef*/ImageDataTypeConversion_k/*@>15f6c0*/ < /*@>1dd2b8*/rtDW./*@>1e9ef2*/ImageDataTypeConversion_cx) {
            /*@>1dd2e8*/rtDW./*@>1e9f0a*/win_y_high/*@>1a77b4*/ = /*@>1dd2ee*/rtDW./*@>1e9f0d*/ImageDataTypeConversion_k;
        } else {
            /*@>1dd2dc*/rtDW./*@>1e9f04*/win_y_high/*@>18fd72*/ = /*@>1dd2e2*/rtDW./*@>1e9f07*/ImageDataTypeConversion_cx;
        }
        /*@>1a77bb*/if (/*@>1dd30c*/rtDW./*@>1e9f1c*/ImageDataTypeConversion_c/*@>15f6e1*/ > /*@>1dd312*/rtDW./*@>1e9f1f*/ImageDataTypeConversion_cx) {
            /*@>1dd342*/rtDW./*@>1e9f37*/bestInlierDis/*@>1a77be*/ = /*@>1dd348*/rtDW./*@>1e9f3a*/ImageDataTypeConversion_c;
        } else {
            /*@>1dd336*/rtDW./*@>1e9f31*/bestInlierDis/*@>18fd7c*/ = /*@>1dd33c*/rtDW./*@>1e9f34*/ImageDataTypeConversion_cx;
        }
    } else {
        /*@>1dd26a*/rtDW./*@>1e9ecb*/ImageDataTypeConversion_cx/*@>188dcf*/ = /*@>1dd270*/rtDW./*@>1e9ece*/ImageDataTypeConversion/*@>1da2e3*/[/*@>1dd276*/rtDW./*@>1e9ed1*/svdRsltVar/*@>1da2dd*/ + /*@>1da2e0*/614400];
        /*@>1a77ac*/if (/*@>1dd2a6*/rtDW./*@>1e9ee9*/ImageDataTypeConversion_c/*@>15f6ff*/ < /*@>1dd2ac*/rtDW./*@>1e9eec*/ImageDataTypeConversion_cx) {
            /*@>1dd2d0*/rtDW./*@>1e9efe*/win_y_high/*@>1a77af*/ = /*@>1dd2d6*/rtDW./*@>1e9f01*/ImageDataTypeConversion_c;
        } else {
            /*@>1dd2c4*/rtDW./*@>1e9ef8*/win_y_high/*@>18fd6d*/ = /*@>1dd2ca*/rtDW./*@>1e9efb*/ImageDataTypeConversion_cx;
        }
        /*@>1a77b6*/if (/*@>1dd300*/rtDW./*@>1e9f16*/ImageDataTypeConversion_k/*@>15f721*/ > /*@>1dd306*/rtDW./*@>1e9f19*/ImageDataTypeConversion_cx) {
            /*@>1dd32a*/rtDW./*@>1e9f2b*/bestInlierDis/*@>1a77b9*/ = /*@>1dd330*/rtDW./*@>1e9f2e*/ImageDataTypeConversion_k;
        } else {
            /*@>1dd31e*/rtDW./*@>1e9f25*/bestInlierDis/*@>18fd77*/ = /*@>1dd324*/rtDW./*@>1e9f28*/ImageDataTypeConversion_cx;
        }
    }
    /*@>1dd366*/rtDW./*@>1e9f49*/s1DivS2/*@>15f741*/ = /*@>1dd36c*/rtDW./*@>1e9f4c*/bestInlierDis/*@>15f740*/ - /*@>1dd372*/rtDW./*@>1e9f4f*/win_y_high;
    /*@>15f747*/if (/*@>1dd37e*/rtDW./*@>1e9f55*/bestInlierDis/*@>15f746*/ != /*@>194b93*/0.0) {
        /*@>1dd3a8*/rtDW./*@>1e9f6a*/win_y_high/*@>15f753*/ = /*@>1dd3ae*/rtDW./*@>1e9f6d*/s1DivS2/*@>15f751*/ / /*@>1dd3b4*/rtDW./*@>1e9f70*/bestInlierDis;
    } else {
        /*@>1dd3a2*/rtDW./*@>1e9f67*/win_y_high/*@>15f757*/ = /*@>194b98*/0.0;
    }
    /*@>15f75d*/if (/*@>1dd402*/rtDW./*@>1e9f94*/s1DivS2/*@>15f75c*/ != /*@>194b9d*/0.0) {
        /*@>15f766*/if (/*@>1dd420*/rtDW./*@>1e9fa3*/ImageDataTypeConversion_c/*@>15f765*/ == /*@>1dd426*/rtDW./*@>1e9fa6*/bestInlierDis) {
            /*@>1dd43e*/rtDW./*@>1e9fb2*/s1DivS2/*@>15f77f*/ = (/*@>1dd444*/rtDW./*@>1e9fb5*/ImageDataTypeConversion_k/*@>168762*/ - /*@>1dd44a*/rtDW./*@>1e9fb8*/ImageDataTypeConversion_cx)/*@>15f77d*/ / /*@>1dd450*/rtDW./*@>1e9fbb*/s1DivS2;
        } else /*@>15f78b*/if (/*@>1dd432*/rtDW./*@>1e9fac*/ImageDataTypeConversion_k/*@>15f78a*/ == /*@>1dd438*/rtDW./*@>1e9faf*/bestInlierDis) {
            /*@>1dd46e*/rtDW./*@>1e9fca*/s1DivS2/*@>15f7a9*/ = (/*@>1dd474*/rtDW./*@>1e9fcd*/ImageDataTypeConversion_cx/*@>1688d0*/ - /*@>1dd47a*/rtDW./*@>1e9fd0*/ImageDataTypeConversion_c)/*@>168758*/ / /*@>1dd480*/rtDW./*@>1e9fd3*/s1DivS2/*@>15f7a7*/ + /*@>194ba6*/2.0;
        } else {
            /*@>1dd456*/rtDW./*@>1e9fbe*/s1DivS2/*@>15f7c7*/ = (/*@>1dd45c*/rtDW./*@>1e9fc1*/ImageDataTypeConversion_c/*@>1688bf*/ - /*@>1dd462*/rtDW./*@>1e9fc4*/ImageDataTypeConversion_k)/*@>168740*/ / /*@>1dd468*/rtDW./*@>1e9fc7*/s1DivS2/*@>15f7c5*/ + /*@>194ba9*/4.0;
        }
        /*@>1dd4ce*/rtDW./*@>1e9ffa*/s1DivS2/*@>1e893f*/ /= /*@>194bae*/6.0;
        /*@>15f7d4*/if (/*@>1dd4f2*/rtDW./*@>1ea009*/s1DivS2/*@>15f7d3*/ < /*@>194bb3*/0.0) {
            /*@>1dd510*/rtDW./*@>1ea018*/s1DivS2/*@>1e8940*/++;
        }
    } else {
        /*@>1dd41a*/rtDW./*@>1e9fa0*/s1DivS2/*@>15f7df*/ = /*@>194bb9*/0.0;
    }
    /* assign the results */
    /*@>1dd4bc*/rtDW./*@>1e9ff1*/ColorSpaceConversion/*@>15f7e4*/[/*@>1dd4c2*/rtDW./*@>1e9ff4*/svdRsltVar]/*@>15f7e7*/ = /*@>1dd4c8*/rtDW./*@>1e9ff7*/s1DivS2;
    /*@>1dd4e0*/rtDW./*@>1ea000*/ColorSpaceConversion/*@>15f7ef*/[/*@>1dd4e6*/rtDW./*@>1ea003*/svdRsltVar/*@>15f7ed*/ + /*@>194c9d*/307200]/*@>15f7f2*/ = /*@>1dd4ec*/rtDW./*@>1ea006*/win_y_high;
    /* {S!d476}S-Function (svipcolorconv): '<S4>/Color Space  Conversion' */
    /*@>1dd4fe*/rtDW./*@>1ea00f*/ColorSpaceConversion/*@>1ae0ad*/[/*@>1dd504*/rtDW./*@>1ea012*/svdRsltVar/*@>1ae0af*/ + /*@>1ae0b2*/614400]/*@>1ae0b5*/ = /*@>1dd50a*/rtDW./*@>1ea015*/bestInlierDis;
    /* {S!d478}MATLAB Function: '<S4>/MATLAB Function7' incorporates:
 *  S-Function (svipcolorconv): '<S4>/Color Space  Conversion'
 */
    /*@>1dd51c*/rtDW./*@>1ea01b*/V_Channel/*@>18a645*/[/*@>1dd522*/rtDW./*@>1ea01e*/svdRsltVar]/*@>17bee2*/ = /*@>1dd528*/rtDW./*@>1ea021*/bestInlierDis;
}
/*@>17bf3f*/for (/*@>1e87a1*/rtDW./*@>1eaa59*/i = /*@>1e879f*/0; /*@>1e87b1*/rtDW./*@>1eaa5f*/i < /*@>1e87ae*/8; /*@>1e87ab*/rtDW./*@>1eaa5c*/i/*@>1e8941*/++) {
    /* {S!d480}MATLAB Function: '<S4>/MATLAB Function1' */
    /*@>1dd258*/rtDW./*@>1e9ec2*/pts1/*@>17bf31*/[/*@>1dd25e*/rtDW./*@>1e9ec5*/i]/*@>17bf32*/ = /*@>1da2d9*/tmp/*@>1da2db*/[/*@>1dd264*/rtDW./*@>1e9ec8*/i];
    /* {S!d482}MATLAB Function: '<S4>/MATLAB Function2' */
    /*@>1dd294*/rtDW./*@>1e9ee0*/pts2/*@>17bfae*/[/*@>1dd29a*/rtDW./*@>1e9ee3*/i]/*@>17bfaf*/ = /*@>1da2ef*/tmp_0/*@>1da2f1*/[/*@>1dd2a0*/rtDW./*@>1e9ee6*/i];
}
/* {S!d484}S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */
/*@>1d4841*/std::memset(&/*@>1dd28e*/rtDW./*@>1e9edd*/EstimateGeometricTransformation/*@>1d189e*/[/*@>1d189a*/0], /*@>1e81c5*/0, /*@>1d189c*/9U/*@>1d18a4*/ * /*@>1d18a3*/sizeof(double));
/*@>1dd2be*/rtDW./*@>1e9ef5*/EstimateGeometricTransformation_DW_BEST_SAMPLE/*@>1901dc*/[/*@>1955e0*/0]/*@>1901db*/ = /*@>1e81c8*/0;
/*@>1dd2f4*/rtDW./*@>1e9f10*/EstimateGeometricTransformation_DW_BEST_SAMPLE/*@>1901e8*/[/*@>1955e3*/1]/*@>1901e7*/ = /*@>1e81cb*/1;
/*@>1dd2fa*/rtDW./*@>1e9f13*/EstimateGeometricTransformation_DW_BEST_SAMPLE/*@>1901f4*/[/*@>1955e6*/2]/*@>1901f3*/ = /*@>1e81ce*/2;
/*@>1dd318*/rtDW./*@>1e9f22*/EstimateGeometricTransformation_DW_BEST_SAMPLE/*@>190200*/[/*@>1955e9*/3]/*@>1901ff*/ = /*@>1e81d1*/3;
/*@[1e59b9*/makeConstraintMatrix_Projective_D_D((const double *)&/*@>1eab8d*/rtDW./*@>1eab8c*/pts1/*@>1eab8b*/[/*@>1eab8f*/0], (const double *)&/*@>1eaba1*/rtDW./*@>1eaba0*/pts2/*@>1eab9f*/[/*@>1eaba3*/0], /*@>1eabb1*/4U, /*@>1eabbf*/4U, &/*@>1eabd0*/rtDW./*@>1eabcf*/EstimateGeometricTransformation_DW_CONSTRT_ALL/*@>1eabce*/[/*@>1eabd2*/0])/*@]*/;
/*@>1dd360*/rtDW./*@>1e9f46*/svdRsltVar/*@>15dd0e*/ = /*@>1e81d4*/0;
while/*@<15dd14*/ (/*@>1dd378*/rtDW./*@>1e9f52*/svdRsltVar/*@>15dd13*/ < /*@>199957*/4) {
    /*@>1dd38a*/rtDW./*@>1e9f5b*/EstimateGeometricTransformation_DW_SAMPLEIDX/*@>17c490*/[/*@>1dd390*/rtDW./*@>1e9f5e*/svdRsltVar]/*@>15dd1a*/ = static_cast<uint32_t>(/*@>1dd396*/rtDW./*@>1e9f61*/EstimateGeometricTransformation_DW_BEST_SAMPLE/*@>1da2f7*/[/*@>1dd39c*/rtDW./*@>1e9f64*/svdRsltVar]);
    /*@>1dd3d8*/rtDW./*@>1e9f82*/svdRsltVar/*@>1e8943*/++;
}
/*@>1dd384*/rtDW./*@>1e9f58*/bestCol/*@>15dd48*/ = /*@>194a31*/0U;
/*@[1e59d6*/normPts_D_D((const double *)&/*@>1eabe4*/rtDW./*@>1eabe3*/pts1/*@>1eabe2*/[/*@>1eabe6*/0], (const uint32_t *)&/*@>1eabf8*/rtDW./*@>1eabf7*/EstimateGeometricTransformation_DW_SAMPLEIDX/*@>1eabf6*/[/*@>1eabfa*/0], /*@>1eac08*/4U, /*@>1eac16*/4U, &/*@>1eac27*/rtDW./*@>1eac26*/EstimateGeometricTransformation_DW_PTSNORM1/*@>1eac25*/[/*@>1eac29*/0], &/*@>1eac39*/rtDW./*@>1eac38*/x_location, &/*@>1eac4b*/rtDW./*@>1eac4a*/cents1/*@>1eac49*/[/*@>1eac4d*/0])/*@]*/;
/*@[1e59f3*/normPts_D_D((const double *)&/*@>1eac5f*/rtDW./*@>1eac5e*/pts2/*@>1eac5d*/[/*@>1eac61*/0], (const uint32_t *)&/*@>1eac73*/rtDW./*@>1eac72*/EstimateGeometricTransformation_DW_SAMPLEIDX/*@>1eac71*/[/*@>1eac75*/0], /*@>1eac83*/4U, /*@>1eac91*/4U, &/*@>1eaca2*/rtDW./*@>1eaca1*/EstimateGeometricTransformation_DW_PTSNORM2/*@>1eaca0*/[/*@>1eaca4*/0], &/*@>1eacb4*/rtDW./*@>1eacb3*/x_current, &/*@>1eacc6*/rtDW./*@>1eacc5*/cents2/*@>1eacc4*/[/*@>1eacc8*/0])/*@]*/;
/*@[1e5a0e*/makeConstraintMatrix_Projective_D_D((const double *)&/*@>1eacda*/rtDW./*@>1eacd9*/EstimateGeometricTransformation_DW_PTSNORM1/*@>1eacd8*/[/*@>1eacdc*/0], (const double *)&/*@>1eacee*/rtDW./*@>1eaced*/EstimateGeometricTransformation_DW_PTSNORM2/*@>1eacec*/[/*@>1eacf0*/0], /*@>1eacfe*/4U, /*@>1ead0c*/4U, &/*@>1ead1d*/rtDW./*@>1ead1c*/Constraint/*@>1ead1b*/[/*@>1ead1f*/0])/*@]*/;
/*@>181e72*/for (/*@>1e8786*/rtDW./*@>1eaa50*/i = /*@>1e8784*/0; /*@>1e8796*/rtDW./*@>1eaa56*/i < /*@>1e8793*/8; /*@>1e8790*/rtDW./*@>1eaa53*/i/*@>1e8944*/++) {
    /*@>1dd4b0*/rtDW./*@>1e9feb*/JPVT/*@>15dfc6*/[static_cast<uint32_t>(/*@>1dd4b6*/rtDW./*@>1e9fee*/i)]/*@>15dfc7*/ = /*@>1e81d7*/0;
}
/*@[1e5a2e*/QRE_double_o(&/*@>1ead30*/rtDW./*@>1ead2f*/Q/*@>1ead2e*/[/*@>1ead32*/0], &/*@>1ead43*/rtDW./*@>1ead42*/Constraint/*@>1ead41*/[/*@>1ead45*/0], &/*@>1ead56*/rtDW./*@>1ead55*/E/*@>1ead54*/[/*@>1ead58*/0], &/*@>1ead69*/rtDW./*@>1ead68*/Qraux/*@>1ead67*/[/*@>1ead6b*/0], &/*@>1ead7c*/rtDW./*@>1ead7b*/Work/*@>1ead7a*/[/*@>1ead7e*/0], &/*@>1ead8f*/rtDW./*@>1ead8e*/JPVT/*@>1ead8d*/[/*@>1ead91*/0], &/*@>1eada2*/rtDW./*@>1eada1*/RV/*@>1eada0*/[/*@>1eada4*/0], /*@>1eadb2*/9, /*@>1eadc0*/8, /*@>1eadce*/true)/*@]*/;
/*@>1dd4da*/rtDW./*@>1e9ffd*/win_y_high/*@>15eae7*/ = /*@>194a2d*/0.0;
/*@>181e22*/for (/*@>1e8735*/rtDW./*@>1eaa35*/i = /*@>1e8733*/0; /*@>1e8745*/rtDW./*@>1eaa3b*/i < /*@>1e8742*/9; /*@>1e873f*/rtDW./*@>1eaa38*/i/*@>1e8946*/++) {
/*@>181e44*/    for (/*@>1e8750*/rtDW./*@>1eaa3e*/j = /*@>1e874e*/0; /*@>1e8760*/rtDW./*@>1eaa44*/j < /*@>1e875d*/9; /*@>1e875a*/rtDW./*@>1eaa41*/j/*@>1e8947*/++) {
        /*@>1a77c0*/if (static_cast<uint32_t>(/*@>1dd546*/rtDW./*@>1ea030*/i)/*@>15eaf8*/ != static_cast<uint32_t>(/*@>1dd54c*/rtDW./*@>1ea033*/j)) {
            /*@>1dd582*/rtDW./*@>1ea04e*/s1DivS2/*@>1a77c3*/ = /*@>194a1b*/0.0;
        } else {
            /*@>1dd57c*/rtDW./*@>1ea04b*/s1DivS2/*@>18fd81*/ = /*@>194a1a*/-1.0;
        }
/*@>181e5b*/        for (/*@>1e876b*/rtDW./*@>1eaa47*/inlierNum = /*@>1e8769*/0; /*@>1e877b*/rtDW./*@>1eaa4d*/inlierNum < /*@>1e8778*/8; /*@>1e8775*/rtDW./*@>1eaa4a*/inlierNum/*@>1e894a*/++) {
            /*@>1dd600*/rtDW./*@>1ea08d*/s1DivS2_tmp/*@>1bbd6a*/ = static_cast<uint32_t>(/*@>1dd606*/rtDW./*@>1ea090*/inlierNum)/*@>196c7f*/ * /*@>1950ea*/9U;
            /*@>1dd624*/rtDW./*@>1ea09f*/s1DivS2/*@>1e894e*/ += /*@>1dd62a*/rtDW./*@>1ea0a2*/Q/*@>1da334*/[/*@>1dd630*/rtDW./*@>1ea0a5*/s1DivS2_tmp/*@>1da32c*/ + static_cast<uint32_t>(/*@>1dd636*/rtDW./*@>1ea0a8*/i)]/*@>196c7d*/ * /*@>1dd63c*/rtDW./*@>1ea0ab*/Q/*@>1da33e*/[rtDW.s1DivS2_tmp/*@>1da336*/ + static_cast<uint32_t>(/*@>1dd648*/rtDW./*@>1ea0b1*/j)];
        }
        /*@>1dd5e8*/rtDW./*@>1ea081*/RV/*@>15eb26*/[static_cast<uint32_t>(/*@>1dd5ee*/rtDW./*@>1ea084*/i)/*@>196c78*/ * /*@>194a19*/9U/*@>15eb24*/ + static_cast<uint32_t>(/*@>1dd5f4*/rtDW./*@>1ea087*/j)]/*@>15eb27*/ = /*@>1dd5fa*/rtDW./*@>1ea08a*/s1DivS2;
        /*@>18fd83*/if (!/*@<1c9fe9*/(/*@>1dd61e*/rtDW./*@>1ea09c*/s1DivS2/*@>15eb2b*/ >= /*@>194a18*/0.0)) {
            /*@>1dd666*/rtDW./*@>1ea0bd*/s1DivS2/*@>15eb2f*/ = -/*@<196c77*//*@>1dd66c*/rtDW./*@>1ea0c0*/s1DivS2;
        }
        /*@>15eb36*/if (/*@>1dd6a8*/rtDW./*@>1ea0de*/win_y_high/*@>15eb35*/ < /*@>1dd6ae*/rtDW./*@>1ea0e1*/s1DivS2) {
            /*@>1dd6c6*/rtDW./*@>1ea0ed*/win_y_high/*@>15eb39*/ = /*@>1dd6cc*/rtDW./*@>1ea0f0*/s1DivS2;
            /*@>1dd6e4*/rtDW./*@>1ea0fc*/bestCol/*@>15eb3b*/ = static_cast<uint32_t>(/*@>1dd6ea*/rtDW./*@>1ea0ff*/i);
        }
    }
}
/*@>1dd52e*/rtDW./*@>1ea024*/j/*@>15ebb4*/ = static_cast<int32_t>(/*@>1dd534*/rtDW./*@>1ea027*/bestCol/*@>196c4f*/ * /*@>194a2b*/9U);
/*@>181ddb*/for (/*@>1e871a*/rtDW./*@>1eaa2c*/i = /*@>1e8718*/0; /*@>1e872a*/rtDW./*@>1eaa32*/i < /*@>1e8727*/9; /*@>1e8724*/rtDW./*@>1eaa2f*/i/*@>1e8953*/++) {
    /*@>1dd55e*/rtDW./*@>1ea03c*/tformCompact/*@>17ce3f*/[static_cast<uint32_t>(/*@>1dd564*/rtDW./*@>1ea03f*/i)]/*@>15ebc1*/ = /*@>1dd56a*/rtDW./*@>1ea042*/RV/*@>1da302*/[static_cast<uint32_t>(/*@>1dd570*/rtDW./*@>1ea045*/j) + static_cast<uint32_t>(/*@>1dd576*/rtDW./*@>1ea048*/i)];
}
/*@>1dd552*/rtDW./*@>1ea036*/win_y_high/*@>15ebcf*/ = /*@>194b34*/1.0/*@>15ebce*/ / /*@>1dd558*/rtDW./*@>1ea039*/x_current;
/*@>1dd588*/rtDW./*@>1ea051*/s1DivS2/*@>15ebd4*/ = /*@>1dd58e*/rtDW./*@>1ea054*/x_location/*@>196c4d*/ * /*@>1dd594*/rtDW./*@>1ea057*/win_y_high;
/*@>1dd59a*/rtDW./*@>1ea05a*/tformCompact_m/*@>17ceda*/[/*@>1950e5*/6]/*@>15ebdc*/ = /*@>1dd5a0*/rtDW./*@>1ea05d*/tformCompact/*@>1da307*/[/*@>1da304*/6]/*@>196c49*/ * /*@>1dd5a6*/rtDW./*@>1ea060*/x_location;
/*@>1dd5b2*/rtDW./*@>1ea066*/tformCompact_m/*@>17cf57*/[/*@>1950f9*/7]/*@>15ebe4*/ = /*@>1dd5b8*/rtDW./*@>1ea069*/tformCompact/*@>1da30c*/[/*@>1da309*/7]/*@>196c45*/ * /*@>1dd5be*/rtDW./*@>1ea06c*/x_location;
/*@>1dd5c4*/rtDW./*@>1ea06f*/tformCompact_m/*@>17d001*/[/*@>19510b*/8]/*@>15ebfa*/ = (/*@>1dd5ca*/rtDW./*@>1ea072*/tformCompact/*@>1da311*/[/*@>1da30e*/8]/*@>15ebef*/ - /*@>1dd5d0*/rtDW./*@>1ea075*/cents1/*@>1da316*/[/*@>1da313*/0]/*@>196c3d*/ * /*@>1dd5d6*/rtDW./*@>1ea078*/tformCompact_m/*@>1da31b*/[/*@>1da318*/6])/*@>15ebf7*/ - /*@>1dd5dc*/rtDW./*@>1ea07b*/cents1/*@>1da320*/[/*@>1da31d*/1]/*@>196c41*/ * /*@>1dd5e2*/rtDW./*@>1ea07e*/tformCompact_m/*@>1da325*/[/*@>1da322*/7];
/*@>1dd60c*/rtDW./*@>1ea093*/tformCompact_m/*@>17d036*/[/*@>195111*/0]/*@>15ec02*/ = /*@>1dd612*/rtDW./*@>1ea096*/tformCompact/*@>1da32a*/[/*@>1da327*/0]/*@>196c39*/ * /*@>1dd618*/rtDW./*@>1ea099*/s1DivS2;
/*@>1dd654*/rtDW./*@>1ea0b4*/tformCompact_m/*@>17d18d*/[/*@>195129*/1]/*@>15ec0a*/ = /*@>1dd65a*/rtDW./*@>1ea0b7*/tformCompact/*@>1da343*/[/*@>1da340*/1]/*@>196c35*/ * /*@>1dd660*/rtDW./*@>1ea0ba*/s1DivS2;
/*@>1dd672*/rtDW./*@>1ea0c3*/tformCompact_m/*@>17d270*/[/*@>195141*/2]/*@>15ec2a*/ = ((/*@>1dd678*/rtDW./*@>1ea0c6*/cents2/*@>1da348*/[/*@>1da345*/0]/*@>196c25*/ * /*@>1dd67e*/rtDW./*@>1ea0c9*/tformCompact_m/*@>1da34d*/[/*@>1da34a*/8]/*@>15ec19*/ - /*@>1dd684*/rtDW./*@>1ea0cc*/tformCompact_m/*@>1da352*/[/*@>1da34f*/0]/*@>196c29*/ * /*@>1dd68a*/rtDW./*@>1ea0cf*/cents1/*@>1da357*/[/*@>1da354*/0])/*@>15ec21*/ - /*@>1dd690*/rtDW./*@>1ea0d2*/tformCompact_m/*@>1da35c*/[/*@>1da359*/1]/*@>196c2d*/ * /*@>1dd696*/rtDW./*@>1ea0d5*/cents1/*@>1da361*/[/*@>1da35e*/1])/*@>15ec27*/ + /*@>1dd69c*/rtDW./*@>1ea0d8*/tformCompact/*@>1da366*/[/*@>1da363*/2]/*@>196c31*/ * /*@>1dd6a2*/rtDW./*@>1ea0db*/win_y_high;
/*@>1dd6b4*/rtDW./*@>1ea0e4*/tformCompact_m/*@>17d2aa*/[/*@>195147*/3]/*@>15ec32*/ = /*@>1dd6ba*/rtDW./*@>1ea0e7*/tformCompact/*@>1da36b*/[/*@>1da368*/3]/*@>196c21*/ * /*@>1dd6c0*/rtDW./*@>1ea0ea*/s1DivS2;
/*@>1dd6d2*/rtDW./*@>1ea0f3*/tformCompact_m/*@>17d2df*/[/*@>19514d*/4]/*@>15ec3a*/ = /*@>1dd6d8*/rtDW./*@>1ea0f6*/tformCompact/*@>1da370*/[/*@>1da36d*/4]/*@>196c1d*/ * /*@>1dd6de*/rtDW./*@>1ea0f9*/s1DivS2;
/*@>1dd6f0*/rtDW./*@>1ea102*/tformCompact_m/*@>17d5d2*/[/*@>1951b5*/5]/*@>15ec5a*/ = ((/*@>1dd6f6*/rtDW./*@>1ea105*/cents2/*@>1da375*/[/*@>1da372*/1]/*@>196c0d*/ * /*@>1dd6fc*/rtDW./*@>1ea108*/tformCompact_m/*@>1da37a*/[/*@>1da377*/8]/*@>15ec49*/ - /*@>1dd702*/rtDW./*@>1ea10b*/cents1/*@>1da37f*/[/*@>1da37c*/0]/*@>196c11*/ * /*@>1dd708*/rtDW./*@>1ea10e*/tformCompact_m/*@>1da384*/[/*@>1da381*/3])/*@>15ec51*/ - /*@>1dd70e*/rtDW./*@>1ea111*/cents1/*@>1da389*/[/*@>1da386*/1]/*@>196c15*/ * /*@>1dd714*/rtDW./*@>1ea114*/tformCompact_m/*@>1da38e*/[/*@>1da38b*/4])/*@>15ec57*/ + /*@>1dd71a*/rtDW./*@>1ea117*/tformCompact/*@>1da393*/[/*@>1da390*/5]/*@>196c19*/ * /*@>1dd720*/rtDW./*@>1ea11a*/win_y_high;
/*@>1dd726*/rtDW./*@>1ea11d*/tformCompact_m/*@>17d6ad*/[/*@>1951c9*/0]/*@>1e8957*/ += /*@>1dd72c*/rtDW./*@>1ea120*/cents2/*@>1da398*/[/*@>1da395*/0]/*@>196c09*/ * /*@>1dd732*/rtDW./*@>1ea123*/tformCompact_m/*@>1da39d*/[/*@>1da39a*/6];
/*@>1dd73e*/rtDW./*@>1ea126*/tformCompact_m/*@>17d8e7*/[/*@>195204*/1]/*@>1e8958*/ += /*@>1dd744*/rtDW./*@>1ea129*/cents2/*@>1da3a7*/[/*@>1da3a4*/0]/*@>196c05*/ * /*@>1dd74a*/rtDW./*@>1ea12c*/tformCompact_m/*@>1da3ac*/[/*@>1da3a9*/7];
/*@>1dd756*/rtDW./*@>1ea12f*/tformCompact_m/*@>17da4c*/[/*@>195237*/3]/*@>1e8959*/ += /*@>1dd75c*/rtDW./*@>1ea132*/cents2/*@>1da3b6*/[/*@>1da3b3*/1]/*@>196c01*/ * /*@>1dd762*/rtDW./*@>1ea135*/tformCompact_m/*@>1da3bb*/[/*@>1da3b8*/6];
/*@>1dd76e*/rtDW./*@>1ea138*/tformCompact_m/*@>17dab7*/[/*@>195243*/4]/*@>1e895a*/ += /*@>1dd774*/rtDW./*@>1ea13b*/cents2/*@>1da3c5*/[/*@>1da3c2*/1]/*@>196bfd*/ * /*@>1dd77a*/rtDW./*@>1ea13e*/tformCompact_m/*@>1da3ca*/[/*@>1da3c7*/7];
/*@>15ec9c*/if (/*@>1dd786*/rtDW./*@>1ea141*/tformCompact_m/*@>1da3d4*/[/*@>1da3d1*/8U]/*@>15ec9b*/ != /*@>194a2a*/0.0) {
    /*@>1dd792*/rtDW./*@>1ea147*/win_y_high/*@>15eca4*/ = /*@>194b4d*/1.0/*@>15eca3*/ / /*@>1dd798*/rtDW./*@>1ea14a*/tformCompact_m/*@>1da3d9*/[/*@>1da3d6*/8];
/*@>181dc3*/    for (/*@>1e86ff*/rtDW./*@>1eaa23*/i = /*@>1e86fd*/0; /*@>1e870f*/rtDW./*@>1eaa29*/i < /*@>1e870c*/8; /*@>1e8709*/rtDW./*@>1eaa26*/i/*@>1e895b*/++) {
        /*@>1dd7bc*/rtDW./*@>1ea15c*/tformCompact_m/*@>17dc75*/[static_cast<uint32_t>(/*@>1dd7c2*/rtDW./*@>1ea15f*/i)]/*@>1e895e*/ *= /*@>1dd7d4*/rtDW./*@>1ea162*/win_y_high;
    }
    /*@>1dd7b6*/rtDW./*@>1ea159*/tformCompact_m/*@>15ecba*/[/*@>194b52*/8]/*@>15ecbc*/ = /*@>194a28*/1.0;
    /*@>1dd7ec*/rtDW./*@>1ea16b*/bestCol/*@>15eccc*/ = /*@>194a24*/0U;
/*@>181d76*/    for (/*@>1e86ae*/rtDW./*@>1eaa08*/i = /*@>1e86ac*/0; /*@>1e86be*/rtDW./*@>1eaa0e*/i < /*@>1e86bb*/4; /*@>1e86b8*/rtDW./*@>1eaa0b*/i/*@>1e895f*/++) {
        /*@>1dd846*/rtDW./*@>1ea192*/EstimateGeometricTransformation_DW_DISTANCE/*@>15ecd6*/[static_cast<uint32_t>(/*@>1dd84c*/rtDW./*@>1ea195*/i)]/*@>15ecd8*/ = /*@>194a1d*/0.0;
/*@>181d94*/        for (/*@>1e86c9*/rtDW./*@>1eaa11*/j = /*@>1e86c7*/0; /*@>1e86d9*/rtDW./*@>1eaa17*/j < /*@>1e86d6*/2; /*@>1e86d3*/rtDW./*@>1eaa14*/j/*@>1e8961*/++) {
            /*@>1dd8b8*/rtDW./*@>1ea1bf*/win_y_high/*@>15ece2*/ = /*@>194a1c*/0.0;
/*@>181dac*/            for (/*@>1e86e4*/rtDW./*@>1eaa1a*/inlierNum = /*@>1e86e2*/0; /*@>1e86f4*/rtDW./*@>1eaa20*/inlierNum < /*@>1e86f1*/9; /*@>1e86ee*/rtDW./*@>1eaa1d*/inlierNum/*@>1e8962*/++) {
                /*@>1dd91e*/rtDW./*@>1ea1e6*/win_y_high/*@>1e8965*/ += /*@>1dd924*/rtDW./*@>1ea1e9*/EstimateGeometricTransformation_DW_CONSTRT_ALL/*@>1da427*/[/*@>1dd92a*/rtDW./*@>1ea1ec*/bestCol + static_cast<uint32_t>(/*@>1dd930*/rtDW./*@>1ea1ef*/inlierNum)]/*@>196c8f*/ * /*@>1dd936*/rtDW./*@>1ea1f2*/tformCompact_m/*@>1da42e*/[static_cast<uint32_t>(/*@>1dd93c*/rtDW./*@>1ea1f5*/inlierNum)];
            }
            rtDW.bestCol += /*@>19546c*/9U;
            /*@>1dd95a*/rtDW./*@>1ea201*/EstimateGeometricTransformation_DW_DISTANCE/*@>17d4bc*/[static_cast<uint32_t>(/*@>1dd960*/rtDW./*@>1ea204*/i)]/*@>1e8969*/ += /*@>1dd966*/rtDW./*@>1ea207*/win_y_high/*@>196c8b*/ * /*@>1dd96c*/rtDW./*@>1ea20a*/win_y_high;
        }
    }
    /*@>1d4843*/std::memcpy(&/*@>1dd876*/rtDW./*@>1ea1a1*/bestTFormCompact/*@>1d0164*/[/*@>1d0153*/0], &/*@>1dd87c*/rtDW./*@>1ea1a4*/tformCompact_m/*@>1d016c*/[/*@>1d0160*/0], /*@>1d0162*/9U/*@>1d016f*/ * /*@>1d016e*/sizeof(double));
    /*@>1dd89a*/rtDW./*@>1ea1b3*/inlierNum/*@>15ed53*/ = /*@>1e81dd*/0;
    /*@>1900e8*/if (/*@>1dd8b2*/rtDW./*@>1ea1bc*/EstimateGeometricTransformation_DW_DISTANCE/*@>1da413*/[/*@>1da410*/0]/*@>1900e9*/ <= /*@>195570*/2.5) {
        /*@>1dd8d0*/rtDW./*@>1ea1c8*/inlierNum/*@>1900fb*/ = /*@>1e81e0*/1;
    }
    /*@>190104*/if (/*@>1dd8fa*/rtDW./*@>1ea1da*/EstimateGeometricTransformation_DW_DISTANCE/*@>1da41d*/[/*@>1da41a*/1]/*@>190105*/ <= /*@>195578*/2.5) {
        /*@>1dd906*/rtDW./*@>1ea1dd*/inlierNum/*@>190117*/ = static_cast<int32_t>(static_cast<uint32_t>(/*@>1dd90c*/rtDW./*@>1ea1e0*/inlierNum)/*@>190119*/ + /*@>195581*/1U);
    }
    /*@>190120*/if (/*@>1dd954*/rtDW./*@>1ea1fe*/EstimateGeometricTransformation_DW_DISTANCE/*@>1da433*/[/*@>1da430*/2]/*@>190121*/ <= /*@>195585*/2.5) {
        /*@>1dd98a*/rtDW./*@>1ea213*/inlierNum/*@>190133*/ = static_cast<int32_t>(static_cast<uint32_t>(/*@>1dd990*/rtDW./*@>1ea216*/inlierNum)/*@>190135*/ + /*@>19558e*/1U);
    }
    /*@>19013c*/if (/*@>1dd99c*/rtDW./*@>1ea219*/EstimateGeometricTransformation_DW_DISTANCE/*@>1da43f*/[/*@>1da43c*/3]/*@>19013d*/ <= /*@>195592*/2.5) {
        /*@>1dd9ae*/rtDW./*@>1ea21f*/inlierNum/*@>19014f*/ = static_cast<int32_t>(static_cast<uint32_t>(/*@>1dd9b4*/rtDW./*@>1ea222*/inlierNum)/*@>190151*/ + /*@>19559b*/1U);
    }
} else {
    /*@>1dd78c*/rtDW./*@>1ea144*/inlierNum/*@>15ed8f*/ = /*@>1e81da*/0;
}
/*@>15ed9c*/if (static_cast<uint32_t>(/*@>1dd7a4*/rtDW./*@>1ea150*/inlierNum)/*@>15ed9b*/ >= /*@>194a36*/4U) {
    /*@>1dd7aa*/rtDW./*@>1ea153*/EstimateGeometricTransformation/*@>17c2f0*/[/*@>194f47*/0]/*@>15eda3*/ = /*@>1dd7b0*/rtDW./*@>1ea156*/bestTFormCompact/*@>1da3de*/[/*@>1da3db*/4];
    /*@>1dd7e0*/rtDW./*@>1ea165*/EstimateGeometricTransformation/*@>17c36b*/[/*@>194f5c*/1]/*@>15eda9*/ = /*@>1dd7e6*/rtDW./*@>1ea168*/bestTFormCompact/*@>1da3ea*/[/*@>1da3e7*/3];
    /*@>1dd7f8*/rtDW./*@>1ea171*/EstimateGeometricTransformation/*@>17c3cd*/[/*@>194f62*/2]/*@>15edaf*/ = /*@>1dd7fe*/rtDW./*@>1ea174*/bestTFormCompact/*@>1da3ef*/[/*@>1da3ec*/5];
    /*@>1dd80a*/rtDW./*@>1ea17a*/EstimateGeometricTransformation/*@>17c400*/[/*@>194f68*/3]/*@>15edb5*/ = /*@>1dd810*/rtDW./*@>1ea17d*/bestTFormCompact/*@>1da3f4*/[/*@>1da3f1*/1];
    /*@>1dd834*/rtDW./*@>1ea18c*/EstimateGeometricTransformation/*@>17c45b*/[/*@>194f6e*/4]/*@>15edbb*/ = /*@>1dd83a*/rtDW./*@>1ea18f*/bestTFormCompact/*@>1da3ff*/[/*@>1da3fc*/0];
    /*@>1dd86a*/rtDW./*@>1ea19b*/EstimateGeometricTransformation/*@>17c53b*/[/*@>194f97*/5]/*@>15edc1*/ = /*@>1dd870*/rtDW./*@>1ea19e*/bestTFormCompact/*@>1da404*/[/*@>1da401*/2];
    /*@>1dd88e*/rtDW./*@>1ea1ad*/EstimateGeometricTransformation/*@>17c5e6*/[/*@>194fb8*/6]/*@>15edc7*/ = /*@>1dd894*/rtDW./*@>1ea1b0*/bestTFormCompact/*@>1da409*/[/*@>1da406*/7];
    /*@>1dd8a6*/rtDW./*@>1ea1b6*/EstimateGeometricTransformation/*@>17c691*/[/*@>194fd9*/7]/*@>15edcd*/ = /*@>1dd8ac*/rtDW./*@>1ea1b9*/bestTFormCompact/*@>1da40e*/[/*@>1da40b*/6];
    /*@>1dd8c4*/rtDW./*@>1ea1c2*/EstimateGeometricTransformation/*@>17c75f*/[/*@>194ffe*/8]/*@>15edd3*/ = /*@>1dd8ca*/rtDW./*@>1ea1c5*/bestTFormCompact/*@>1da418*/[/*@>1da415*/8];
}
/* {S!d486}MATLAB Function: '<S4>/MATLAB Function8' */
/*@>17c33a*/for (/*@>1e8693*/rtDW./*@>1ea9ff*/i = /*@>1e8691*/0; /*@>1e86a3*/rtDW./*@>1eaa05*/i < /*@>1e86a0*/307200; /*@>1e869d*/rtDW./*@>1eaa02*/i/*@>1e8971*/++) {
    /*@>1dd81c*/rtDW./*@>1ea180*/rtb_V_Channel_a/*@>17c32c*/[/*@>1dd822*/rtDW./*@>1ea183*/i]/*@>17c32d*/ = (/*@>1dd828*/rtDW./*@>1ea186*/V_Channel/*@>1da3fa*/[/*@>1dd82e*/rtDW./*@>1ea189*/i]/*@>17c31e*/ > /*@>194e07*/0.5);
}
/* {E!d486}End of MATLAB Function: '<S4>/MATLAB Function8' */

/* {S!d488}MATLABSystem: '<S4>/Warp' incorporates:
 *  S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
 */
/*@[1e5a48*/Warp_stepImpl(&/*@>1eadde*/rtDW./*@>1eaddd*/obj_k, &/*@>1eadf0*/rtDW./*@>1eadef*/rtb_V_Channel_a[0], &/*@>1eae03*/rtDW./*@>1eae02*/EstimateGeometricTransformation[0], &/*@>1eae16*/rtDW./*@>1eae15*/bv[0])/*@]*/;
/* {S!d490}MATLAB Function: '<S2>/MATLAB Function1' incorporates:
 *  MATLABSystem: '<S4>/Warp'
 */
/*@>1dd888*/rtDW./*@>1ea1aa*/x_location/*@>15f99d*/ = /*@>194bee*/320.0;
/*@[1e5a63*/eml_find_7rUftLmJ(&/*@>1eae29*/rtDW./*@>1eae28*/bv[0], /*@>1eae3a*/rtDW./*@>1eae39*/ii_data_n, &rtDW.ii_size, /*@>1eae5b*/rtDW./*@>1eae5a*/jj_data_p, &rtDW.jj_size)/*@]*/;
/*@>1dd948*/rtDW./*@>1ea1f8*/j/*@>1bbd74*/ = rtDW.ii_size;
rtDW.c_size/*@>17c4d7*/ = rtDW.ii_size;
/*@>17c4f9*/for (/*@>1e8674*/rtDW./*@>1ea9f3*/i = /*@>1e8672*/0; /*@>1e8689*/rtDW./*@>1ea9fc*/i < rtDW.j; /*@>1e867e*/rtDW./*@>1ea9f6*/i/*@>1e8972*/++) {
    /*@>1dd9c0*/rtDW./*@>1ea225*/outputImage_tmp/*@>1ae00b*/ = /*@>1dd9c6*/rtDW./*@>1ea228*/ii_data_n/*@>1da445*/[/*@>1dd9cc*/rtDW./*@>1ea22b*/i];
    /*@>1dd9de*/rtDW./*@>1ea234*/c_data/*@>17c4e6*/[/*@>1dd9e4*/rtDW./*@>1ea237*/i]/*@>17c4e7*/ = (/*@>1dd9ea*/rtDW./*@>1ea23a*/outputImage_tmp/*@>17c4da*/ >= /*@>194e08*/456);
    /*@>1dd9fc*/rtDW./*@>1ea243*/d_data/*@>17c591*/[/*@>1dda02*/rtDW./*@>1ea246*/i]/*@>17c592*/ = (/*@>1dda08*/rtDW./*@>1ea249*/outputImage_tmp/*@>17c585*/ < /*@>194e09*/480);
}
/*@>1dd9d2*/rtDW./*@>1ea22e*/svdRsltVar/*@>1bbd80*/ = rtDW.jj_size;
rtDW.g_size/*@>17c62d*/ = rtDW.jj_size;
/*@>17c64f*/for (/*@>1e8655*/rtDW./*@>1ea9e7*/i = /*@>1e8653*/0; /*@>1e866a*/rtDW./*@>1ea9f0*/i < rtDW.svdRsltVar; /*@>1e865f*/rtDW./*@>1ea9ea*/i/*@>1e8973*/++) {
    /*@>1dda20*/rtDW./*@>1ea24f*/g_data/*@>17c63c*/[/*@>1dda26*/rtDW./*@>1ea252*/i]/*@>17c63d*/ = (/*@>1dda2c*/rtDW./*@>1ea255*/jj_data_p/*@>1da44b*/[/*@>1dda32*/rtDW./*@>1ea258*/i]/*@>17c630*/ >= /*@>194e0a*/480);
}
rtDW.b_tmp_size/*@>17c6f5*/ = rtDW.ii_size;
/*@>17c71d*/for (/*@>1e8636*/rtDW./*@>1ea9db*/i = /*@>1e8634*/0; /*@>1e864b*/rtDW./*@>1ea9e4*/i < rtDW.j; /*@>1e8640*/rtDW./*@>1ea9de*/i/*@>1e8974*/++) {
    /*@>1dda5c*/rtDW./*@>1ea26a*/b_tmp_data/*@>17c70a*/[/*@>1dda62*/rtDW./*@>1ea26d*/i]/*@>17c70b*/ = (/*@>1dda68*/rtDW./*@>1ea270*/c_data/*@>1da451*/[/*@>1dda6e*/rtDW./*@>1ea273*/i]/*@>17c6f8*/ && /*@>1dda74*/rtDW./*@>1ea276*/d_data/*@>1da457*/[/*@>1dda7a*/rtDW./*@>1ea279*/i]);
}
if (rtDW.ii_size == rtDW.jj_size) {
    /* {S!d492}MATLAB Function: '<S2>/MATLAB Function1' */
    rtDW.b_size/*@>17c829*/ = rtDW.ii_size;
/*@>17c851*/    for (/*@>1e8617*/rtDW./*@>1ea9cf*/i = /*@>1e8615*/0; /*@>1e862c*/rtDW./*@>1ea9d8*/i < rtDW.j; /*@>1e8621*/rtDW./*@>1ea9d2*/i/*@>1e8975*/++) {
        /*@>1ddae0*/rtDW./*@>1ea2a0*/b_data/*@>17c83e*/[/*@>1ddae6*/rtDW./*@>1ea2a3*/i]/*@>17c83f*/ = (/*@>1ddaec*/rtDW./*@>1ea2a6*/b_tmp_data/*@>1da45d*/[/*@>1ddaf2*/rtDW./*@>1ea2a9*/i]/*@>17c82c*/ && /*@>1ddaf8*/rtDW./*@>1ea2ac*/g_data/*@>1da463*/[/*@>1ddafe*/rtDW./*@>1ea2af*/i]);
    }
} else {
    /* {S!d494}MATLAB Function: '<S2>/MATLAB Function1' */
    /*@[1e5a7f*/and_o(/*@>1eae7c*/rtDW./*@>1eae7b*/b_data, &rtDW.b_size, /*@>1eae9d*/rtDW./*@>1eae9c*/b_tmp_data, &rtDW.b_tmp_size, /*@>1eaebe*/rtDW./*@>1eaebd*/g_data, &rtDW.g_size)/*@]*/;
}
/* {S!d496}MATLAB Function: '<S2>/MATLAB Function1' */
rtDW.h_size/*@>17c8ab*/ = rtDW.jj_size;
/*@>17c8cd*/for (/*@>1e85f8*/rtDW./*@>1ea9c3*/i = /*@>1e85f6*/0; /*@>1e860d*/rtDW./*@>1ea9cc*/i < rtDW.svdRsltVar; /*@>1e8602*/rtDW./*@>1ea9c6*/i/*@>1e8976*/++) {
    /*@>1ddb10*/rtDW./*@>1ea2b8*/h_data/*@>17c8ba*/[/*@>1ddb16*/rtDW./*@>1ea2bb*/i]/*@>17c8bb*/ = (/*@>1ddb1c*/rtDW./*@>1ea2be*/jj_data_p/*@>1da469*/[/*@>1ddb22*/rtDW./*@>1ea2c1*/i]/*@>17c8ae*/ < /*@>194e29*/640);
}
if (rtDW.b_size == rtDW.jj_size) {
    /* {S!d498}MATLAB Function: '<S2>/MATLAB Function1' */
    /*@>1ddb52*/rtDW./*@>1ea2d6*/svdRsltVar/*@>1bbd96*/ = rtDW.b_size;
    rtDW.tmp_size/*@>17c9e0*/ = rtDW.b_size;
/*@>17ca08*/    for (/*@>1e85d9*/rtDW./*@>1ea9b7*/i = /*@>1e85d7*/0; /*@>1e85ee*/rtDW./*@>1ea9c0*/i < rtDW.svdRsltVar; /*@>1e85e3*/rtDW./*@>1ea9ba*/i/*@>1e8977*/++) {
        /*@>1ddb94*/rtDW./*@>1ea2f1*/tmp_data_h/*@>17c9f5*/[/*@>1ddb9a*/rtDW./*@>1ea2f4*/i]/*@>17c9f6*/ = (/*@>1ddba0*/rtDW./*@>1ea2f7*/b_data/*@>1da46f*/[/*@>1ddba6*/rtDW./*@>1ea2fa*/i]/*@>17c9e3*/ && /*@>1ddbac*/rtDW./*@>1ea2fd*/h_data/*@>1da475*/[/*@>1ddbb2*/rtDW./*@>1ea300*/i]);
    }
} else {
    /* {S!d500}MATLAB Function: '<S2>/MATLAB Function1' */
    /*@[1e5a9b*/and_o(/*@>1eaedf*/rtDW./*@>1eaede*/tmp_data_h, &rtDW.tmp_size, /*@>1eaf00*/rtDW./*@>1eaeff*/b_data, &rtDW.b_size, /*@>1eaf21*/rtDW./*@>1eaf20*/h_data, &rtDW.h_size)/*@]*/;
}
rtDW.outputImage_tmp = rtDW.tmp_size - 1;
rtDW.trueCount = 0;
for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
    /* {S!d502}MATLAB Function: '<S2>/MATLAB Function1' */
    if (/*@>1ddbbe*/rtDW./*@>1ea306*/tmp_data_h/*@>1da47b*/[rtDW.i]) {
        rtDW.trueCount++;
    }
}
/* {S!d504}MATLAB Function: '<S2>/MATLAB Function1' incorporates:
 *  S-Function (svipcolorconv): '<S4>/Color Space  Conversion'
 *  S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
 */
/*@>15f9e5*/if (rtDW.trueCount/*@>15f9c3*/ > /*@>194bef*/30) {
    /*@>1ddbd0*/rtDW./*@>1ea30f*/inlierNum/*@>15f99e*/ = /*@>1e81e9*/1;
    if (rtDW.b_size == rtDW.jj_size) {
        /*@>1ddc72*/rtDW./*@>1ea357*/svdRsltVar/*@>1bbda0*/ = rtDW.b_size;
        rtDW.tmp_size_g/*@>17cdd1*/ = rtDW.b_size;
/*@>17cdf9*/        for (/*@>1e859e*/rtDW./*@>1ea99f*/i = /*@>1e859c*/0; /*@>1e85b3*/rtDW./*@>1ea9a8*/i < rtDW.svdRsltVar; /*@>1e85a8*/rtDW./*@>1ea9a2*/i/*@>1e897a*/++) {
            /*@>1ddcfc*/rtDW./*@>1ea390*/tmp_data_b/*@>17cde6*/[/*@>1ddd02*/rtDW./*@>1ea393*/i]/*@>17cde7*/ = (/*@>1ddd08*/rtDW./*@>1ea396*/b_data/*@>1da487*/[/*@>1ddd0e*/rtDW./*@>1ea399*/i]/*@>17cdd4*/ && /*@>1ddd14*/rtDW./*@>1ea39c*/h_data/*@>1da48d*/[/*@>1ddd1a*/rtDW./*@>1ea39f*/i]);
        }
    } else {
        /*@[1e5ab7*/and_o(/*@>1eaf42*/rtDW./*@>1eaf41*/tmp_data_b, &rtDW.tmp_size_g, /*@>1eaf63*/rtDW./*@>1eaf62*/b_data, &rtDW.b_size, /*@>1eaf84*/rtDW./*@>1eaf83*/h_data, &rtDW.h_size)/*@]*/;
    }
    rtDW.outputImage_tmp = rtDW.tmp_size_g - 1;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1ddd68*/rtDW./*@>1ea3c6*/tmp_data_b/*@>1da49f*/[rtDW.i]) {
            rtDW.trueCount++;
        }
    }
    rtDW.tmp_size_idx_0 = rtDW.trueCount;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1dddc8*/rtDW./*@>1ea3e4*/tmp_data_b/*@>1da4ab*/[rtDW.i]) {
            /*@>1dddfe*/rtDW./*@>1ea3ff*/tmp_data[rtDW.trueCount]/*@>178d10*/ = rtDW.i;
            rtDW.trueCount++;
        }
    }
    rtDW.jj_size_b/*@>17d414*/ = rtDW.tmp_size_idx_0;
/*@>17d44d*/    for (/*@>1e8547*/rtDW./*@>1ea97b*/i = /*@>1e8545*/0; /*@>1e855c*/rtDW./*@>1ea984*/i < rtDW.tmp_size_idx_0; /*@>1e8551*/rtDW./*@>1ea97e*/i/*@>1e897f*/++) {
        /*@>1dde64*/rtDW./*@>1ea423*/jj_data/*@>17d43a*/[/*@>1dde6a*/rtDW./*@>1ea426*/i]/*@>17d43b*/ = /*@>1dde70*/rtDW./*@>1ea429*/jj_data_p/*@>1da4ba*/[/*@>1dde76*/rtDW./*@>1ea42c*/tmp_data/*@>1da4b4*/[/*@>1dde7c*/rtDW./*@>1ea42f*/i]];
    }
    /*@>1dde52*/rtDW./*@>1ea41a*/x_current/*@>15f99f*/ = /*@[1e5acf*/mean_uQukM2rh(/*@>1eafa5*/rtDW./*@>1eafa4*/jj_data, &rtDW.jj_size_b)/*@]*/;
    if ((rtDW.ii_size == rtDW.jj_size) && ((rtDW.ii_size == 1 ? rtDW.jj_size : rtDW.ii_size) == rtDW.jj_size)) {
        rtDW.tmp_size_l/*@>17d99c*/ = rtDW.ii_size;
/*@>17d9d2*/        for (/*@>1e8528*/rtDW./*@>1ea96f*/i = /*@>1e8526*/0; /*@>1e853d*/rtDW./*@>1ea978*/i < rtDW.j; /*@>1e8532*/rtDW./*@>1ea972*/i/*@>1e8980*/++) {
            /*@>1ddf7e*/rtDW./*@>1ea4a7*/tmp_data_da/*@>17d9bf*/[/*@>1ddf84*/rtDW./*@>1ea4aa*/i]/*@>17d9c0*/ = (/*@>1ddf8a*/rtDW./*@>1ea4ad*/c_data/*@>1da4de*/[/*@>1ddf90*/rtDW./*@>1ea4b0*/i]/*@>17d9a1*/ && /*@>1ddf96*/rtDW./*@>1ea4b3*/d_data/*@>1da4e4*/[/*@>1ddf9c*/rtDW./*@>1ea4b6*/i]/*@>17d9a0*/ && /*@>1ddfa2*/rtDW./*@>1ea4b9*/g_data/*@>1da4ea*/[/*@>1ddfa8*/rtDW./*@>1ea4bc*/i]/*@>17d99f*/ && /*@>1ddfae*/rtDW./*@>1ea4bf*/h_data/*@>1da4f0*/[/*@>1ddfb4*/rtDW./*@>1ea4c2*/i]);
        }
    } else {
        /*@[1e5aee*/binary_expand_op_2(/*@>1eafc6*/rtDW./*@>1eafc5*/tmp_data_da, &rtDW.tmp_size_l, /*@>1eafe7*/rtDW./*@>1eafe6*/c_data, &rtDW.c_size, /*@>1eb008*/rtDW./*@>1eb007*/d_data, /*@>1eb018*/rtDW./*@>1eb017*/g_data, &rtDW.g_size, /*@>1eb039*/rtDW./*@>1eb038*/h_data, &rtDW.h_size)/*@]*/;
    }
    rtDW.outputImage_tmp = rtDW.tmp_size_l - 1;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1ddff6*/rtDW./*@>1ea4e3*/tmp_data_da/*@>1da4f6*/[rtDW.i]) {
            rtDW.trueCount++;
        }
    }
    rtDW.tmp_size_idx_0 = rtDW.trueCount;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1de0bc*/rtDW./*@>1ea537*/tmp_data_da/*@>1da4fc*/[rtDW.i]) {
            /*@>1de0ec*/rtDW./*@>1ea54c*/tmp_data_l[rtDW.trueCount]/*@>178dd1*/ = rtDW.i;
            rtDW.trueCount++;
        }
    }
    rtDW.ii_size_n/*@>17de1c*/ = rtDW.tmp_size_idx_0;
/*@>17de55*/    for (/*@>1e84d1*/rtDW./*@>1ea94b*/i = /*@>1e84cf*/0; /*@>1e84e6*/rtDW./*@>1ea954*/i < rtDW.tmp_size_idx_0; /*@>1e84db*/rtDW./*@>1ea94e*/i/*@>1e8985*/++) {
        /*@>1de18e*/rtDW./*@>1ea58e*/ii_data/*@>17de42*/[/*@>1de194*/rtDW./*@>1ea591*/i]/*@>17de43*/ = /*@>1de19a*/rtDW./*@>1ea594*/ii_data_n/*@>1da517*/[/*@>1de1a0*/rtDW./*@>1ea597*/tmp_data_l/*@>1da511*/[/*@>1de1a6*/rtDW./*@>1ea59a*/i]];
    }
    /*@>1de17c*/rtDW./*@>1ea585*/bestInlierDis/*@>15fa46*/ = /*@[1e5b06*/maximum_4kJ3rROr(/*@>1eb05a*/rtDW./*@>1eb059*/ii_data, &rtDW.ii_size_n)/*@]*/;
} else {
    /*@>1ddbca*/rtDW./*@>1ea30c*/inlierNum/*@>15f9a0*/ = /*@>1e81e6*/2;
    if ((rtDW.ii_size == rtDW.jj_size) && ((rtDW.ii_size == 1 ? rtDW.jj_size : rtDW.ii_size) == rtDW.jj_size)) {
        /*@>1ddc66*/rtDW./*@>1ea351*/j/*@>1bbdc2*/ = rtDW.ii_size;
        rtDW.tmp_size_g/*@>17cd2e*/ = rtDW.ii_size;
/*@>17cd5f*/        for (/*@>1e84b2*/rtDW./*@>1ea93f*/i = /*@>1e84b0*/0; /*@>1e84c7*/rtDW./*@>1ea948*/i < rtDW.j; /*@>1e84bc*/rtDW./*@>1ea942*/i/*@>1e89a4*/++) {
            /*@>1ddcea*/rtDW./*@>1ea387*/outputImage_tmp/*@>188d05*/ = /*@>1ddcf0*/rtDW./*@>1ea38a*/jj_data_p/*@>1da481*/[/*@>1ddcf6*/rtDW./*@>1ea38d*/i];
            /*@>1ddd38*/rtDW./*@>1ea3ae*/tmp_data_b/*@>17cd4c*/[/*@>1ddd3e*/rtDW./*@>1ea3b1*/i]/*@>17cd4d*/ = (/*@>1ddd44*/rtDW./*@>1ea3b4*/b_tmp_data/*@>1da499*/[/*@>1ddd4a*/rtDW./*@>1ea3b7*/i]/*@>17cd32*/ && (/*@>1ddd50*/rtDW./*@>1ea3ba*/outputImage_tmp/*@>17cd39*/ >= /*@>194e46*/0)/*@>17cd31*/ && (/*@>1ddd56*/rtDW./*@>1ea3bd*/outputImage_tmp/*@>17cd40*/ < /*@>194e47*/160));
        }
    } else {
        /*@[1e5b22*/binary_expand_op_3(/*@>1eb07b*/rtDW./*@>1eb07a*/tmp_data_b, &rtDW.tmp_size_g, /*@>1eb09c*/rtDW./*@>1eb09b*/b_tmp_data, &rtDW.b_tmp_size, /*@>1eb0bd*/rtDW./*@>1eb0bc*/jj_data_p, &rtDW.jj_size)/*@]*/;
    }
    rtDW.outputImage_tmp = rtDW.tmp_size_g - 1;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1ddd2c*/rtDW./*@>1ea3a8*/tmp_data_b/*@>1da493*/[rtDW.i]) {
            rtDW.trueCount++;
        }
    }
    rtDW.tmp_size_idx_0 = rtDW.trueCount;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1dddb6*/rtDW./*@>1ea3de*/tmp_data_b/*@>1da4a5*/[rtDW.i]) {
            /*@>1ddde0*/rtDW./*@>1ea3f0*/tmp_data[rtDW.trueCount]/*@>178c5e*/ = rtDW.i;
            rtDW.trueCount++;
        }
    }
    rtDW.jj_size_b/*@>17d340*/ = rtDW.tmp_size_idx_0;
    rtDW.ii_size_n/*@>17d70e*/ = rtDW.tmp_size_idx_0;
/*@>17d379*/    for (/*@>1e845b*/rtDW./*@>1ea91b*/i = /*@>1e8459*/0; /*@>1e8470*/rtDW./*@>1ea924*/i < rtDW.tmp_size_idx_0; /*@>1e8465*/rtDW./*@>1ea91e*/i/*@>1e89a9*/++) {
        /*@>1ddeb8*/rtDW./*@>1ea44d*/jj_data/*@>17d366*/[/*@>1ddebe*/rtDW./*@>1ea450*/i]/*@>17d367*/ = /*@>1ddec4*/rtDW./*@>1ea453*/jj_data_p/*@>1da4c9*/[/*@>1ddeca*/rtDW./*@>1ea456*/tmp_data/*@>1da4c3*/[/*@>1dded0*/rtDW./*@>1ea459*/i]];
        /*@>1ddf24*/rtDW./*@>1ea480*/ii_data/*@>17d734*/[/*@>1ddf2a*/rtDW./*@>1ea483*/i]/*@>17d735*/ = /*@>1ddf30*/rtDW./*@>1ea486*/ii_data_n/*@>1da4d8*/[/*@>1ddf36*/rtDW./*@>1ea489*/tmp_data/*@>1da4d2*/[/*@>1ddf3c*/rtDW./*@>1ea48c*/i]];
    }
    /*@>1ddea6*/rtDW./*@>1ea444*/x_current/*@>15f9a1*/ = /*@[1e5b3a*/mean_uQukM2rh(/*@>1eb0de*/rtDW./*@>1eb0dd*/jj_data, &rtDW.jj_size_b)/*@]*/;
    /*@>1ddf12*/rtDW./*@>1ea477*/bestInlierDis/*@>15fa43*/ = /*@[1e5b52*/maximum_4kJ3rROr(/*@>1eb0ff*/rtDW./*@>1eb0fe*/ii_data, &rtDW.ii_size_n)/*@]*/;
}
/*@>15f9eb*/for (/*@>1e8224*/rtDW./*@>1ea83a*/svdRsltVar = /*@>1e8222*/0; /*@>1e8234*/rtDW./*@>1ea840*/svdRsltVar < /*@>1e8231*/20; /*@>1e822e*/rtDW./*@>1ea83d*/svdRsltVar/*@>1e8986*/++) {
    /*@>15f9ed*/if (/*@>1ddfba*/rtDW./*@>1ea4c5*/inlierNum/*@>15f9c4*/ == /*@>194c01*/1) {
        /*@>1ddfd8*/rtDW./*@>1ea4d4*/win_y_low/*@>15f9a5*/ = /*@>1ddfde*/rtDW./*@>1ea4d7*/bestInlierDis/*@>15f9c7*/ - ((static_cast<double>(/*@>1ddfe4*/rtDW./*@>1ea4da*/svdRsltVar)/*@>15fa6b*/ + /*@>194c46*/1.0)/*@>15f9c5*/ + /*@>194c04*/1.0)/*@>196cae*/ * /*@>194c05*/24.0;
        /*@>1de014*/rtDW./*@>1ea4f2*/win_y_high/*@>15f9a7*/ = /*@>1de01a*/rtDW./*@>1ea4f5*/bestInlierDis/*@>15f9c9*/ - (static_cast<double>(/*@>1de020*/rtDW./*@>1ea4f8*/svdRsltVar)/*@>15fa6f*/ + /*@>194c49*/1.0)/*@>196ca7*/ * /*@>194c0d*/24.0;
        /*@>1de062*/rtDW./*@>1ea510*/j/*@>1bbdda*/ = rtDW.ii_size;
        rtDW.jj_size_b/*@>17dc0b*/ = rtDW.ii_size;
/*@>17dc2f*/        for (/*@>1e843c*/rtDW./*@>1ea90f*/i = /*@>1e843a*/0; /*@>1e8451*/rtDW./*@>1ea918*/i < /*@>1e844c*/rtDW./*@>1ea915*/j; /*@>1e8446*/rtDW./*@>1ea912*/i/*@>1e8989*/++) {
            /*@>1de13a*/rtDW./*@>1ea564*/jj_data/*@>17dc1c*/[/*@>1de140*/rtDW./*@>1ea567*/i]/*@>17dc1d*/ = /*@>1de146*/rtDW./*@>1ea56a*/ii_data_n/*@>1da502*/[/*@>1de14c*/rtDW./*@>1ea56d*/i];
        }
        /*@>1de170*/rtDW./*@>1ea57f*/outputImage_tmp/*@>1adf86*/ = rtDW.jj_size;
        rtDW.ii_size_n/*@>17dcbd*/ = rtDW.jj_size;
/*@>17dce1*/        for (/*@>1e841d*/rtDW./*@>1ea903*/i = /*@>1e841b*/0; /*@>1e8432*/rtDW./*@>1ea90c*/i < /*@>1e842d*/rtDW./*@>1ea909*/outputImage_tmp; /*@>1e8427*/rtDW./*@>1ea906*/i/*@>1e898a*/++) {
            /*@>1de266*/rtDW./*@>1ea5f1*/ii_data/*@>17dcce*/[/*@>1de26c*/rtDW./*@>1ea5f4*/i]/*@>17dccf*/ = /*@>1de272*/rtDW./*@>1ea5f7*/jj_data_p/*@>1da529*/[/*@>1de278*/rtDW./*@>1ea5fa*/i];
        }
        if (rtDW.ii_size == rtDW.jj_size) {
            rtDW.c_size/*@>17dfd4*/ = rtDW.ii_size;
/*@>17e006*/            for (/*@>1e83fe*/rtDW./*@>1ea8f7*/i = /*@>1e83fc*/0; /*@>1e8413*/rtDW./*@>1ea900*/i < rtDW.j; /*@>1e8408*/rtDW./*@>1ea8fa*/i/*@>1e898b*/++) {
                /*@>1de356*/rtDW./*@>1ea65a*/outputImage_tmp/*@>188bb0*/ = static_cast<int32_t>(/*@>1de35c*/rtDW./*@>1ea65d*/jj_data/*@>1da53b*/[/*@>1de362*/rtDW./*@>1ea660*/i]);
                /*@>1de386*/rtDW./*@>1ea66f*/c_data/*@>17dff3*/[/*@>1de38c*/rtDW./*@>1ea672*/i]/*@>17dff4*/ = ((/*@>1de392*/rtDW./*@>1ea675*/outputImage_tmp/*@>17dfd9*/ >= /*@>1de398*/rtDW./*@>1ea678*/win_y_low)/*@>17dfd8*/ && (/*@>1de39e*/rtDW./*@>1ea67b*/outputImage_tmp/*@>17dfe0*/ < /*@>1de3a4*/rtDW./*@>1ea67e*/win_y_high)/*@>17dfd7*/ && (/*@>1de3aa*/rtDW./*@>1ea681*/ii_data/*@>1da547*/[/*@>1de3b0*/rtDW./*@>1ea684*/i]/*@>17dfe7*/ >= /*@>1de3b6*/rtDW./*@>1ea687*/x_current/*@>1a51cc*/ - /*@>1a51cf*/40.0));
            }
        } else {
            /*@[1e5b71*/binary_expand_op_1(/*@>1eb120*/rtDW./*@>1eb11f*/c_data, &rtDW.c_size, /*@>1eb141*/rtDW./*@>1eb140*/jj_data, &rtDW.jj_size_b, /*@>1eb162*/rtDW./*@>1eb161*/win_y_low, /*@>1eb172*/rtDW./*@>1eb171*/win_y_high, /*@>1eb182*/rtDW./*@>1eb181*/ii_data, &rtDW.ii_size_n, /*@>1eb1a3*/rtDW./*@>1eb1a2*/x_current)/*@]*/;
        }
        /*@>1de31a*/rtDW./*@>1ea63c*/j/*@>1bbde6*/ = rtDW.jj_size;
        rtDW.d_size/*@>17e0f4*/ = rtDW.jj_size;
/*@>17e116*/        for (/*@>1e83df*/rtDW./*@>1ea8eb*/i = /*@>1e83dd*/0; /*@>1e83f4*/rtDW./*@>1ea8f4*/i < rtDW.j; /*@>1e83e9*/rtDW./*@>1ea8ee*/i/*@>1e898d*/++) {
            /*@>1de416*/rtDW./*@>1ea6b1*/d_data/*@>17e103*/[/*@>1de41c*/rtDW./*@>1ea6b4*/i]/*@>17e104*/ = (/*@>1de422*/rtDW./*@>1ea6b7*/ii_data/*@>1da54d*/[/*@>1de428*/rtDW./*@>1ea6ba*/i]/*@>17e0f7*/ < /*@>1de42e*/rtDW./*@>1ea6bd*/x_current/*@>1a51d2*/ + /*@>1a51d5*/40.0);
        }
        if (rtDW.c_size == rtDW.jj_size) {
            /*@>1de48e*/rtDW./*@>1ea6ea*/j/*@>1bbdf0*/ = rtDW.c_size;
            rtDW.tmp_size_dy/*@>17e2e4*/ = rtDW.c_size;
/*@>17e30c*/            for (/*@>1e83c0*/rtDW./*@>1ea8df*/i = /*@>1e83be*/0; /*@>1e83d5*/rtDW./*@>1ea8e8*/i < rtDW.j; /*@>1e83ca*/rtDW./*@>1ea8e2*/i/*@>1e898e*/++) {
                /*@>1de536*/rtDW./*@>1ea732*/tmp_data_bj/*@>17e2f9*/[/*@>1de53c*/rtDW./*@>1ea735*/i]/*@>17e2fa*/ = (/*@>1de542*/rtDW./*@>1ea738*/c_data/*@>1da565*/[/*@>1de548*/rtDW./*@>1ea73b*/i]/*@>17e2e7*/ && /*@>1de54e*/rtDW./*@>1ea73e*/d_data/*@>1da56b*/[/*@>1de554*/rtDW./*@>1ea741*/i]);
            }
        } else {
            /*@[1e5b8d*/and_o(/*@>1eb1b3*/rtDW./*@>1eb1b2*/tmp_data_bj, &rtDW.tmp_size_dy, /*@>1eb1d4*/rtDW./*@>1eb1d3*/c_data, &rtDW.c_size, /*@>1eb1f5*/rtDW./*@>1eb1f4*/d_data, &rtDW.d_size)/*@]*/;
        }
        rtDW.outputImage_tmp = rtDW.tmp_size_dy - 1;
        rtDW.trueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
            if (/*@>1de572*/rtDW./*@>1ea74d*/tmp_data_bj/*@>1da571*/[rtDW.i]) {
                rtDW.trueCount++;
            }
        }
        /*@>15f9f1*/if (rtDW.trueCount/*@>15f9cf*/ > /*@>194c20*/30) {
            if (rtDW.c_size == rtDW.jj_size) {
                /*@>1de5f6*/rtDW./*@>1ea783*/j/*@>1bbdfa*/ = rtDW.c_size;
                rtDW.tmp_size_o/*@>17e64e*/ = rtDW.c_size;
/*@>17e676*/                for (/*@>1e8385*/rtDW./*@>1ea8c7*/i = /*@>1e8383*/0; /*@>1e839a*/rtDW./*@>1ea8d0*/i < rtDW.j; /*@>1e838f*/rtDW./*@>1ea8ca*/i/*@>1e8991*/++) {
                    /*@>1de69e*/rtDW./*@>1ea7cb*/tmp_data_f/*@>17e663*/[/*@>1de6a4*/rtDW./*@>1ea7ce*/i]/*@>17e664*/ = (/*@>1de6aa*/rtDW./*@>1ea7d1*/c_data/*@>1da58c*/[/*@>1de6b0*/rtDW./*@>1ea7d4*/i]/*@>17e651*/ && /*@>1de6b6*/rtDW./*@>1ea7d7*/d_data/*@>1da592*/[/*@>1de6bc*/rtDW./*@>1ea7da*/i]);
                }
            } else {
                /*@[1e5ba9*/and_o(/*@>1eb216*/rtDW./*@>1eb215*/tmp_data_f, &rtDW.tmp_size_o, /*@>1eb237*/rtDW./*@>1eb236*/c_data, &rtDW.c_size, /*@>1eb258*/rtDW./*@>1eb257*/d_data, &rtDW.d_size)/*@]*/;
            }
            rtDW.outputImage_tmp = rtDW.tmp_size_o - 1;
            rtDW.trueCount = 0;
            for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
                if (/*@>1de6ce*/rtDW./*@>1ea7e3*/tmp_data_f/*@>1da598*/[rtDW.i]) {
                    rtDW.trueCount++;
                }
            }
            rtDW.tmp_size_idx_0 = rtDW.trueCount;
            rtDW.trueCount = 0;
            for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
                if (/*@>1de6fe*/rtDW./*@>1ea7f2*/tmp_data_f/*@>1da59e*/[rtDW.i]) {
                    /*@>1de716*/rtDW./*@>1ea7fe*/tmp_data_d[rtDW.trueCount]/*@>179013*/ = rtDW.i;
                    rtDW.trueCount++;
                }
            }
            rtDW.jj_size_b/*@>17e917*/ = rtDW.tmp_size_idx_0;
/*@>17e950*/            for (/*@>1e832e*/rtDW./*@>1ea8a3*/i = /*@>1e832c*/0; /*@>1e8343*/rtDW./*@>1ea8ac*/i < rtDW.tmp_size_idx_0; /*@>1e8338*/rtDW./*@>1ea8a6*/i/*@>1e8996*/++) {
                /*@>1de752*/rtDW./*@>1ea816*/jj_data/*@>17e93d*/[/*@>1de758*/rtDW./*@>1ea819*/i]/*@>17e93e*/ = /*@>1de75e*/rtDW./*@>1ea81c*/jj_data_p/*@>1da5ad*/[/*@>1de764*/rtDW./*@>1ea81f*/tmp_data_d/*@>1da5a7*/[/*@>1de76a*/rtDW./*@>1ea822*/i]];
            }
            /*@>1de740*/rtDW./*@>1ea80d*/x_current/*@>15f9a8*/ = /*@[1e5bc1*/mean_uQukM2rh(/*@>1eb279*/rtDW./*@>1eb278*/jj_data, &rtDW.jj_size_b)/*@]*/;
        }
        /*@>15f9f4*/if ((/*@>1de5a2*/rtDW./*@>1ea75f*/win_y_low/*@>15f9d0*/ > /*@>194c26*/300.0)/*@>15fb30*/ && (/*@>1de5a8*/rtDW./*@>1ea762*/win_y_low/*@>15f9d1*/ < /*@>194c2b*/340.0)) {
            /*@>1de5ea*/rtDW./*@>1ea77d*/x_location/*@>15f9ac*/ = /*@>1de5f0*/rtDW./*@>1ea780*/x_current/*@>15f9d2*/ - /*@>194c31*/220.0;
        }
    } else {
        /*@>1ddfc6*/rtDW./*@>1ea4cb*/win_y_low/*@>15f9af*/ = /*@>1ddfcc*/rtDW./*@>1ea4ce*/bestInlierDis/*@>15f9d6*/ - ((static_cast<double>(/*@>1ddfd2*/rtDW./*@>1ea4d1*/svdRsltVar)/*@>15fa7d*/ + /*@>194c4c*/1.0)/*@>15f9d4*/ + /*@>194c12*/1.0)/*@>196ca0*/ * /*@>194c13*/24.0;
        /*@>1de002*/rtDW./*@>1ea4e9*/win_y_high/*@>15f9b1*/ = /*@>1de008*/rtDW./*@>1ea4ec*/bestInlierDis/*@>15f9d8*/ - (static_cast<double>(/*@>1de00e*/rtDW./*@>1ea4ef*/svdRsltVar)/*@>15fa81*/ + /*@>194c4f*/1.0)/*@>196c99*/ * /*@>194c1d*/24.0;
        /*@>1de038*/rtDW./*@>1ea501*/outputImage_tmp/*@>1adf4d*/ = rtDW.ii_size;
        if (rtDW.ii_size == rtDW.jj_size) {
            rtDW.c_size/*@>17df0c*/ = rtDW.ii_size;
/*@>17df47*/            for (/*@>1e830f*/rtDW./*@>1ea897*/i = /*@>1e830d*/0; /*@>1e8324*/rtDW./*@>1ea8a0*/i < /*@>1e831f*/rtDW./*@>1ea89d*/outputImage_tmp; /*@>1e8319*/rtDW./*@>1ea89a*/i/*@>1e8999*/++) {
                /*@>1de15e*/rtDW./*@>1ea576*/j/*@>188b7f*/ = /*@>1de164*/rtDW./*@>1ea579*/ii_data_n/*@>1da508*/[/*@>1de16a*/rtDW./*@>1ea57c*/i];
                /*@>1de1b8*/rtDW./*@>1ea5a0*/c_data/*@>17df34*/[/*@>1de1be*/rtDW./*@>1ea5a3*/i]/*@>17df35*/ = ((/*@>1de1c4*/rtDW./*@>1ea5a6*/j/*@>17df11*/ >= /*@>1de1ca*/rtDW./*@>1ea5a9*/win_y_low)/*@>17df10*/ && (/*@>1de1d0*/rtDW./*@>1ea5ac*/j/*@>17df1b*/ < /*@>1de1d6*/rtDW./*@>1ea5af*/win_y_high)/*@>17df0f*/ && (/*@>1de1dc*/rtDW./*@>1ea5b2*/jj_data_p/*@>1da51d*/[/*@>1de1e2*/rtDW./*@>1ea5b5*/i]/*@>17df25*/ >= /*@>1de1e8*/rtDW./*@>1ea5b8*/x_current/*@>1a5176*/ - /*@>1a5179*/40.0));
            }
        } else {
            /*@[1e5be0*/binary_expand_op(/*@>1eb29a*/rtDW./*@>1eb299*/c_data, &rtDW.c_size, /*@>1eb2bb*/rtDW./*@>1eb2ba*/ii_data_n, &rtDW.ii_size, /*@>1eb2dc*/rtDW./*@>1eb2db*/win_y_low, /*@>1eb2ec*/rtDW./*@>1eb2eb*/win_y_high, /*@>1eb2fc*/rtDW./*@>1eb2fb*/jj_data_p, &rtDW.jj_size, /*@>1eb31d*/rtDW./*@>1eb31c*/x_current)/*@]*/;
        }
        /*@>1de128*/rtDW./*@>1ea55e*/outputImage_tmp/*@>1adf74*/ = rtDW.jj_size;
        rtDW.d_size/*@>17e07a*/ = rtDW.jj_size;
/*@>17e09f*/        for (/*@>1e82f0*/rtDW./*@>1ea88b*/i = /*@>1e82ee*/0; /*@>1e8305*/rtDW./*@>1ea894*/i < /*@>1e8300*/rtDW./*@>1ea891*/outputImage_tmp; /*@>1e82fa*/rtDW./*@>1ea88e*/i/*@>1e899a*/++) {
            /*@>1de212*/rtDW./*@>1ea5ca*/d_data/*@>17e08c*/[/*@>1de218*/rtDW./*@>1ea5cd*/i]/*@>17e08d*/ = (/*@>1de21e*/rtDW./*@>1ea5d0*/jj_data_p/*@>1da523*/[/*@>1de224*/rtDW./*@>1ea5d3*/i]/*@>17e07d*/ < /*@>1de22a*/rtDW./*@>1ea5d6*/x_current/*@>1a518a*/ + /*@>1a518d*/40.0);
        }
        if (rtDW.c_size == rtDW.jj_size) {
            /*@>1de27e*/rtDW./*@>1ea5fd*/j/*@>1bbe04*/ = rtDW.c_size;
            rtDW.tmp_size_d/*@>17e24a*/ = rtDW.c_size;
/*@>17e272*/            for (/*@>1e82d1*/rtDW./*@>1ea87f*/i = /*@>1e82cf*/0; /*@>1e82e6*/rtDW./*@>1ea888*/i < rtDW.j; /*@>1e82db*/rtDW./*@>1ea882*/i/*@>1e899b*/++) {
                /*@>1de326*/rtDW./*@>1ea642*/tmp_data_e/*@>17e25f*/[/*@>1de32c*/rtDW./*@>1ea645*/i]/*@>17e260*/ = (/*@>1de332*/rtDW./*@>1ea648*/c_data/*@>1da52f*/[/*@>1de338*/rtDW./*@>1ea64b*/i]/*@>17e24d*/ && /*@>1de33e*/rtDW./*@>1ea64e*/d_data/*@>1da535*/[/*@>1de344*/rtDW./*@>1ea651*/i]);
            }
        } else {
            /*@[1e5bfc*/and_o(/*@>1eb32d*/rtDW./*@>1eb32c*/tmp_data_e, &rtDW.tmp_size_d, /*@>1eb34e*/rtDW./*@>1eb34d*/c_data, &rtDW.c_size, /*@>1eb36f*/rtDW./*@>1eb36e*/d_data, &rtDW.d_size)/*@]*/;
        }
        rtDW.outputImage_tmp = rtDW.tmp_size_d - 1;
        rtDW.trueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
            if (/*@>1de36e*/rtDW./*@>1ea666*/tmp_data_e/*@>1da541*/[rtDW.i]) {
                rtDW.trueCount++;
            }
        }
        /*@>15f9fa*/if (rtDW.trueCount/*@>15f9de*/ > /*@>194c23*/30) {
            if (rtDW.c_size == rtDW.jj_size) {
                /*@>1de440*/rtDW./*@>1ea6c6*/j/*@>1bbe0e*/ = rtDW.c_size;
                rtDW.tmp_size_lx/*@>17e5b3*/ = rtDW.c_size;
/*@>17e5db*/                for (/*@>1e8296*/rtDW./*@>1ea867*/i = /*@>1e8294*/0; /*@>1e82ab*/rtDW./*@>1ea870*/i < rtDW.j; /*@>1e82a0*/rtDW./*@>1ea86a*/i/*@>1e899e*/++) {
                    /*@>1de4ee*/rtDW./*@>1ea711*/tmp_data_jz/*@>17e5c8*/[/*@>1de4f4*/rtDW./*@>1ea714*/i]/*@>17e5c9*/ = (/*@>1de4fa*/rtDW./*@>1ea717*/c_data/*@>1da553*/[/*@>1de500*/rtDW./*@>1ea71a*/i]/*@>17e5b6*/ && /*@>1de506*/rtDW./*@>1ea71d*/d_data/*@>1da559*/[/*@>1de50c*/rtDW./*@>1ea720*/i]);
                }
            } else {
                /*@[1e5c18*/and_o(/*@>1eb390*/rtDW./*@>1eb38f*/tmp_data_jz, &rtDW.tmp_size_lx, /*@>1eb3b1*/rtDW./*@>1eb3b0*/c_data, &rtDW.c_size, /*@>1eb3d2*/rtDW./*@>1eb3d1*/d_data, &rtDW.d_size)/*@]*/;
            }
            rtDW.outputImage_tmp = rtDW.tmp_size_lx - 1;
            rtDW.trueCount = 0;
            for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
                if (/*@>1de52a*/rtDW./*@>1ea72c*/tmp_data_jz/*@>1da55f*/[rtDW.i]) {
                    rtDW.trueCount++;
                }
            }
            rtDW.tmp_size_idx_0 = rtDW.trueCount;
            rtDW.trueCount = 0;
            for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
                if (/*@>1de5de*/rtDW./*@>1ea777*/tmp_data_jz/*@>1da577*/[rtDW.i]) {
                    /*@>1de60e*/rtDW./*@>1ea78f*/tmp_data_j[rtDW.trueCount]/*@>178f61*/ = rtDW.i;
                    rtDW.trueCount++;
                }
            }
            rtDW.jj_size_b/*@>17e843*/ = rtDW.tmp_size_idx_0;
/*@>17e87c*/            for (/*@>1e823f*/rtDW./*@>1ea843*/i = /*@>1e823d*/0; /*@>1e8254*/rtDW./*@>1ea84c*/i < rtDW.tmp_size_idx_0; /*@>1e8249*/rtDW./*@>1ea846*/i/*@>1e89a3*/++) {
                /*@>1de680*/rtDW./*@>1ea7bc*/jj_data/*@>17e869*/[/*@>1de686*/rtDW./*@>1ea7bf*/i]/*@>17e86a*/ = /*@>1de68c*/rtDW./*@>1ea7c2*/jj_data_p/*@>1da586*/[/*@>1de692*/rtDW./*@>1ea7c5*/tmp_data_j/*@>1da580*/[/*@>1de698*/rtDW./*@>1ea7c8*/i]];
            }
            /*@>1de66e*/rtDW./*@>1ea7b3*/x_current/*@>15f9b2*/ = /*@[1e5c30*/mean_uQukM2rh(/*@>1eb3f3*/rtDW./*@>1eb3f2*/jj_data, &rtDW.jj_size_b)/*@]*/;
        }
        /*@>15f9fd*/if ((/*@>1de3d4*/rtDW./*@>1ea693*/win_y_low/*@>15f9df*/ > /*@>194c2e*/300.0)/*@>15fb31*/ && (/*@>1de3da*/rtDW./*@>1ea696*/win_y_low/*@>15f9e0*/ < /*@>194c36*/340.0)) {
            /*@>1de434*/rtDW./*@>1ea6c0*/x_location/*@>15f9b6*/ = /*@>1de43a*/rtDW./*@>1ea6c3*/x_current/*@>15f9e1*/ + /*@>194c39*/290.0;
        }
    }
    /*@>1de49a*/rtDW./*@>1ea6f0*/win_y_low/*@>15f9b8*/ = /*@>194c18*/340.0/*@>15f9e2*/ - /*@>1de4a0*/rtDW./*@>1ea6f3*/x_location;
}
/* Send event */
ProvidedPort->Error.Send(/*@>1ddfc0*/rtDW./*@>1ea4c8*/win_y_low);






        



                




                    



        

            
            





        





        
                    


            




                


        } 
        
            
















    // Model initialize function
    
            void Rpi_cam::initialize()
    {
            


    




    
        

        



        











                {
            
int32_t i;
static const std::array<int8_t, 9> self_T{ { 1, 0, 0, 0, 1, 0, 0, 0, 1 } };

                                        
                                    

        

                

        

                

/* {S!d508}Start for S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */
/*@>1d358a*/srand(/*@>1d3588*/clock());
        

                

/* {S!d510}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>1de788*/rtDW./*@>1eb511*/obj./*@>1eb4ed*/matlabCodegenIsDeleted/*@>15fcb5*/ = /*@>19578e*/true;
/*@[1e5c5e*/Raspiv4l2Capture_Raspiv4l2Capture(&/*@>1eb58a*/rtDW./*@>1eb589*/obj)/*@]*/;
/*@>1de794*/rtDW./*@>1eb517*/obj./*@>1eb505*/Brightness/*@>15fcfe*/ = /*@>1957c8*/0.5;
/*@>1de79a*/rtDW./*@>1eb51a*/obj./*@>1eb502*/Saturation/*@>15fcfa*/ = /*@>1957c9*/0.5;
/*@>1de7a0*/rtDW./*@>1eb51d*/obj./*@>1eb4ff*/Contrast/*@>15fcf6*/ = /*@>1957ca*/0.5;
/*@>1de7a6*/rtDW./*@>1eb520*/obj./*@>1eb4fc*/Sharpness/*@>15fcf2*/ = /*@>1957cb*/0.5;
/*@>1de7ac*/rtDW./*@>1eb523*/obj./*@>1eb4f9*/CameraPan/*@>15fcee*/ = /*@>1957cc*/0.0;
/*@>1de7b2*/rtDW./*@>1eb526*/obj./*@>1eb4f6*/CameraTilt/*@>15fcea*/ = /*@>1957cd*/0.0;
/*@>1de7b8*/rtDW./*@>1eb529*/obj./*@>1eb4f3*/CameraZoom/*@>15fce6*/ = /*@>1957ce*/0.5;
/*@>1de7be*/rtDW./*@>1eb52c*/obj./*@>1eb4f0*/ManualFocus/*@>15fce2*/ = /*@>1957cf*/0.5;
/*@[1e5c47*/SystemCore_setup(&/*@>1eb59b*/rtDW./*@>1eb59a*/obj)/*@]*/;
/* {S!d512}Start for MATLABSystem: '<S4>/Warp' */
/*@>1de7ca*/rtDW./*@>1eb532*/obj_k./*@>1eb508*/isInitialized/*@>15fd34*/ = /*@>1eb466*/1;
/*@>17ea4e*/for (/*@>1eb46e*/i = /*@>1eb46d*/0; /*@>1eb478*/i < /*@>1eb476*/9; /*@>1eb474*/i/*@>1eb47c*/++) {
    /*@>1de7d0*/rtDW./*@>1eb535*/obj_k./*@>1eb50e*/TformProjective./*@>1eb50b*/T/*@>17ea40*/[/*@>1957bb*/i]/*@>17ea41*/ = /*@>1da5b1*/self_T/*@>1da5b3*/[/*@>1da5b0*/i];
}
/* {E!d512}End of Start for MATLABSystem: '<S4>/Warp' */
/* Initialize service provider instance - ProvidedPort */
ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::com::InstanceIdentifier(ara::core::StringView("1")), ara::com::MethodCallProcessingMode::kEventSingleThread);
ProvidedPort->OfferService();









        }





    





                



        
    }        






        




        
        // Model terminate function
                    void Rpi_cam::terminate()

        {
            


                                                            




                        




                                                    

                        
                                    /* {S!d506}Terminate for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>15fc29*/if (!/*@<15fc27*//*@>1de770*/rtDW./*@>1eb441*/obj.matlabCodegenIsDeleted) {
    /*@>1de776*/rtDW./*@>1eb444*/obj./*@>1eb43e*/matlabCodegenIsDeleted/*@>15fc26*/ = /*@>195757*/true;
    /*@>15fc2f*/if ((/*@>1de77c*/rtDW./*@>1eb447*/obj.isInitialized/*@>15fc2e*/ == /*@>195764*/1)/*@>15fc3e*/ && /*@>1de782*/rtDW./*@>1eb44a*/obj.isSetupComplete) {
        /*@>1d3580*/EXT_webcamTerminate(/*@>1b0027*/0, /*@>1b002a*/0);
    }
}
/* {E!d506}End of Terminate for MATLABSystem: '<Root>/V4L2 Video Capture' */
ProvidedPort->StopOfferService();





                


                    




                




                                



                        }
            





    




    // Constructor

    

     Rpi_cam::Rpi_cam():
rtDW()

    {
            /* Currently there is no constructor body generated.*/
    }


        // Destructor
            /* Currently there is no destructor body generated.*/
             Rpi_cam::~Rpi_cam() = default;


    

    

    

    
