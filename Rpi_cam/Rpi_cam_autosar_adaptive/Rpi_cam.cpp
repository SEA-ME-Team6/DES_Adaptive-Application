

    

        /*
        * Rpi_cam.cpp
        *
                * Academic License - for use in teaching, academic research, and meeting
* course requirements at degree granting institutions only.  Not for
* government, commercial, or other organizational use.
        *
    * Code generation for model "Rpi_cam".
    *
    * Model version              : 1.156
    * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
        * C++ source code generated on : Fri May 31 15:21:38 2024
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
/* {S!d322}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>131a36*/if ((/*@>195f77*/obj->Brightness/*@>169036*/ != /*@>195f7a*/obj->BrightnessInternal)/*@>15c7ce*/ || /*@>195ed0*/forceUpdate) {
    /*@>195ed2*/obj->/*@>1e5ee3*/BrightnessInternal/*@>131a4b*/ = /*@>195ed4*/obj->Brightness;
/*@>18053c*/    for ( int32_t /*@>1e5ca5*/i{/*@>1e5ca4*/0}; /*@>1e5caf*/i < /*@>1e5cad*/11; /*@>1e5cab*/i/*@>1e5cb3*/++) {
        /*@>195fb2*/b/*@>18f29f*/[/*@>195fb0*/i]/*@>18052f*/ = /*@>1da72e*/b_0/*@>1da730*/[/*@>1da72d*/i];
    }
    /*@>1d35b0*/EXT_updateV4L2Control(&/*@>195f2d*/b/*@>18f2af*/[/*@>196031*/0], static_cast<float>(/*@>195ed6*/obj->Brightness), /*@>1b0db0*/0, &/*@>195ed8*/status);
}
/*@>131a96*/if ((/*@>195f7d*/obj->Contrast/*@>169042*/ != /*@>195f80*/obj->ContrastInternal)/*@>15c7cf*/ || /*@>195eda*/forceUpdate) {
    /*@>195edc*/obj->/*@>1e5ee6*/ContrastInternal/*@>131aab*/ = /*@>195ede*/obj->Contrast;
/*@>18058c*/    for ( int32_t /*@>1e5c94*/i{/*@>1e5c93*/0}; /*@>1e5c9e*/i < /*@>1e5c9c*/9; /*@>1e5c9a*/i/*@>1e5cb5*/++) {
        /*@>195fc1*/c/*@>18f2c1*/[/*@>195fbf*/i]/*@>18057f*/ = /*@>1da734*/c_0/*@>1da736*/[/*@>1da733*/i];
    }
    /*@>1d35b2*/EXT_updateV4L2Control(&/*@>195f36*/c/*@>18f2d2*/[/*@>196032*/0], static_cast<float>(/*@>195ee0*/obj->Contrast), /*@>1b0dc9*/0, &/*@>195ee2*/status);
}
/*@>131af6*/if ((/*@>195f83*/obj->Saturation/*@>16904e*/ != /*@>195f86*/obj->SaturationInternal)/*@>15c7d0*/ || /*@>195ee4*/forceUpdate) {
    /*@>195ee6*/obj->/*@>1e5ee9*/SaturationInternal/*@>131b0b*/ = /*@>195ee8*/obj->Saturation;
/*@>1805dd*/    for ( int32_t /*@>1e5c83*/i{/*@>1e5c82*/0}; /*@>1e5c8d*/i < /*@>1e5c8b*/11; /*@>1e5c89*/i/*@>1e5cb7*/++) {
        /*@>195fd0*/b/*@>18f2e2*/[/*@>195fce*/i]/*@>1805d0*/ = /*@>1da73a*/d/*@>1da73c*/[/*@>1da739*/i];
    }
    /*@>1d35b4*/EXT_updateV4L2Control(&/*@>195f3f*/b/*@>18f2f2*/[/*@>196033*/0], static_cast<float>(/*@>195eea*/obj->Saturation), /*@>1b0de2*/0, &/*@>195eec*/status);
}
/*@>131b56*/if ((/*@>195f89*/obj->Sharpness/*@>16905a*/ != /*@>195f8c*/obj->SharpnessInternal)/*@>15c7d1*/ || /*@>195eee*/forceUpdate) {
    /*@>195ef0*/obj->/*@>1e5eec*/SharpnessInternal/*@>131b6b*/ = /*@>195ef2*/obj->Sharpness;
/*@>18062e*/    for ( int32_t /*@>1e5c72*/i{/*@>1e5c71*/0}; /*@>1e5c7c*/i < /*@>1e5c7a*/10; /*@>1e5c78*/i/*@>1e5cb9*/++) {
        /*@>195fdf*/e/*@>18f304*/[/*@>195fdd*/i]/*@>180621*/ = /*@>1da740*/e_0/*@>1da742*/[/*@>1da73f*/i];
    }
    /*@>1d35b6*/EXT_updateV4L2Control(&/*@>195f48*/e/*@>18f314*/[/*@>196034*/0], static_cast<float>(/*@>195ef4*/obj->Sharpness), /*@>1b0dfb*/0, &/*@>195ef6*/status);
}
/*@>131bb6*/if ((/*@>195f8f*/obj->CameraPan/*@>169066*/ != /*@>195f92*/obj->CameraPanInternal)/*@>15c7d2*/ || /*@>195ef8*/forceUpdate) {
    /*@>195efa*/obj->/*@>1e5eef*/CameraPanInternal/*@>131bcb*/ = /*@>195efc*/obj->CameraPan;
/*@>18067f*/    for ( int32_t /*@>1e5c61*/i{/*@>1e5c60*/0}; /*@>1e5c6b*/i < /*@>1e5c69*/10; /*@>1e5c67*/i/*@>1e5cbb*/++) {
        /*@>195fee*/e/*@>18f324*/[/*@>195fec*/i]/*@>180672*/ = /*@>1da746*/f/*@>1da748*/[/*@>1da745*/i];
    }
    /*@>1d35b8*/EXT_updateV4L2Control(&/*@>195f51*/e/*@>18f334*/[/*@>196035*/0], static_cast<float>(/*@>195efe*/obj->CameraPan), /*@>1b0e14*/0, &/*@>195f00*/status);
}
/*@>131c16*/if ((/*@>195f95*/obj->CameraTilt/*@>169072*/ != /*@>195f98*/obj->CameraTiltInternal)/*@>15c7d3*/ || /*@>195f02*/forceUpdate) {
    /*@>195f04*/obj->/*@>1e5ef2*/CameraTiltInternal/*@>131c2b*/ = /*@>195f06*/obj->CameraTilt;
/*@>1806d0*/    for ( int32_t /*@>1e5c50*/i{/*@>1e5c4f*/0}; /*@>1e5c5a*/i < /*@>1e5c58*/11; /*@>1e5c56*/i/*@>1e5cbd*/++) {
        /*@>195ffd*/b/*@>18f344*/[/*@>195ffb*/i]/*@>1806c3*/ = /*@>1da74c*/g/*@>1da74e*/[/*@>1da74b*/i];
    }
    /*@>1d35ba*/EXT_updateV4L2Control(&/*@>195f5a*/b/*@>18f354*/[/*@>196036*/0], static_cast<float>(/*@>195f08*/obj->CameraTilt), /*@>1b0e2c*/0, &/*@>195f0a*/status);
}
/*@>131c76*/if ((/*@>195f9b*/obj->CameraZoom/*@>16907e*/ != /*@>195f9e*/obj->CameraZoomInternal)/*@>15c7d4*/ || /*@>195f0c*/forceUpdate) {
    /*@>195f0e*/obj->/*@>1e5ef5*/CameraZoomInternal/*@>131c8b*/ = /*@>195f10*/obj->CameraZoom;
/*@>180721*/    for ( int32_t /*@>1e5c3f*/i{/*@>1e5c3e*/0}; /*@>1e5c49*/i < /*@>1e5c47*/11; /*@>1e5c45*/i/*@>1e5cbf*/++) {
        /*@>19600c*/b/*@>18f364*/[/*@>19600a*/i]/*@>180714*/ = /*@>1da752*/h/*@>1da754*/[/*@>1da751*/i];
    }
    /*@>1d35bc*/EXT_updateV4L2Control(&/*@>195f63*/b/*@>18f374*/[/*@>196037*/0], static_cast<float>(/*@>195f12*/obj->CameraZoom), /*@>1b0e43*/0, &/*@>195f14*/status);
}
/*@>131cd6*/if ((!/*@<16908a*//*@>195fa1*/obj->EnableManualFocusInternal)/*@>15c7d5*/ || /*@>195f16*/forceUpdate) {
    /*@>195f18*/obj->/*@>1e5ef8*/EnableManualFocusInternal/*@>131ceb*/ = /*@>195f65*/true;
/*@>180772*/    for ( int32_t /*@>1e5c2e*/i{/*@>1e5c2d*/0}; /*@>1e5c38*/i < /*@>1e5c36*/18; /*@>1e5c34*/i/*@>1e5cc1*/++) {
        /*@>1debb4*/rtDW./*@>1e5efe*/i_l/*@>18f384*/[/*@>196019*/i]/*@>180765*/ = /*@>1da758*/i_0/*@>1da75a*/[/*@>1da757*/i];
    }
    /*@>1d35be*/EXT_updateV4L2Control(&/*@>1debba*/rtDW./*@>1e5f01*/i_l/*@>18f395*/[/*@>196038*/0], /*@>195f76*/1.0F, /*@>1b0e57*/0, &/*@>195f1a*/status);
}
/*@>131d36*/if ((/*@>195fa4*/obj->ManualFocus/*@>169091*/ != /*@>195fa7*/obj->ManualFocusInternal)/*@>15c7d6*/ || /*@>195f1c*/forceUpdate) {
    /*@>195f1e*/obj->/*@>1e5efb*/ManualFocusInternal/*@>131d4b*/ = /*@>195f20*/obj->ManualFocus;
/*@>1807c2*/    for ( int32_t /*@>1e5c1d*/i{/*@>1e5c1c*/0}; /*@>1e5c27*/i < /*@>1e5c25*/12; /*@>1e5c23*/i/*@>1e5cc2*/++) {
        /*@>19602a*/j/*@>18f3a4*/[/*@>196028*/i]/*@>1807b5*/ = /*@>1da75e*/j_0/*@>1da760*/[/*@>1da75d*/i];
    }
    /*@>1d35c0*/EXT_updateV4L2Control(&/*@>195f74*/j/*@>18f3b4*/[/*@>196039*/0], static_cast<float>(/*@>195f22*/obj->ManualFocus), /*@>1b0e66*/0, &/*@>195f24*/status);
}
/* {E!d322}End of Start for MATLABSystem: '<Root>/V4L2 Video Capture' */


        }

                





                        


         

                
                void Rpi_cam::SystemCore_step(codertarget_raspi_internal_Raspiv4l2Capture *obj, uint8_t varargout_1[307200], uint8_t varargout_2[307200], uint8_t varargout_3[307200])
        {
            double ts;



/* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@[1e57b5*/v4l2Capture_updateV4L2Settings(/*@>1e6038*/obj, /*@>1e6046*/false)/*@]*/;
/*@>1d35c4*/EXT_webcamReadFrame(/*@>1b0ed2*/0, &/*@>1960a5*/ts, &/*@>1d34fb*/varargout_1/*@>18f3c6*/[/*@>1960ad*/0], &/*@>1d34fe*/varargout_2/*@>18f3cd*/[/*@>1960ae*/0], &/*@>1d3501*/varargout_3/*@>18f3d4*/[/*@>1960af*/0]);


        }

                



            


                        


         

                
                void Rpi_cam::QRV2Norm_double_o(const double V[], int32_t N, double v2norm[])
        {
            int32_t vi;
/* {S!d334}S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */
/*@>1dee24*/rtDW./*@>1e63d2*/tmpQRSL/*@>15e286*/ = /*@>1967f1*/0.0;
/*@>1967f2*/vi/*@>15e28d*/ = /*@>1e6321*/0;
/*@>1e633b*/for ( int32_t /*@>1e6337*/i{/*@>1e6338*/0}; /*@>1e632d*/i/*@>1e632b*/ < /*@>1e632f*/N; /*@>1e6331*/i/*@>1e634f*/++) {
    /*@>1dee30*/rtDW./*@>1e63d8*/d/*@>17142f*/ = /*@>1dee36*/rtDW./*@>1e63db*/tmpQRSL;
    /*@>1dee3c*/rtDW./*@>1e63de*/d1/*@>17143f*/ = /*@>1d35da*/std::abs(/*@>1da96c*/V/*@>1da96e*/[/*@>1da96a*/vi]);
    /*@>15e2c1*/if (/*@>1dee42*/rtDW./*@>1e63e1*/tmpQRSL/*@>15e2c0*/ > /*@>1dee48*/rtDW./*@>1e63e4*/d1) {
        /*@>1dee4e*/rtDW./*@>1e63e7*/tmpQRSL/*@>15e2c8*/ = /*@>1da97a*/V/*@>1da97c*/[/*@>1da978*/vi]/*@>15e2c7*/ / /*@>1dee54*/rtDW./*@>1e63ea*/tmpQRSL;
        /*@>1dee6c*/rtDW./*@>1e63f3*/tmpQRSL/*@>15e2da*/ = /*@>1d35de*/std::sqrt(/*@>1dee72*/rtDW./*@>1e63f6*/tmpQRSL/*@>196e97*/ * /*@>1dee78*/rtDW./*@>1e63f9*/tmpQRSL/*@>15e2d1*/ + /*@>19680b*/1.0)/*@>196e93*/ * rtDW.d;
    } else /*@>15e2e1*/if (/*@>1da973*/V/*@>1da975*/[/*@>1da971*/vi]/*@>15e2e0*/ == /*@>19680f*/0.0) {
        /*@>1dee66*/rtDW./*@>1e63f0*/tmpQRSL/*@>15e2e6*/ = /*@>196810*/0.0;
    } else {
        /*@>1dee5a*/rtDW./*@>1e63ed*/tmpQRSL/*@>1e6351*/ /= /*@>1da981*/V/*@>1da983*/[/*@>1da97f*/vi];
        /*@>1dee84*/rtDW./*@>1e63ff*/tmpQRSL/*@>15e300*/ = /*@>1d35dc*/std::sqrt(/*@>1dee8a*/rtDW./*@>1e6402*/tmpQRSL/*@>196e8f*/ * /*@>1dee90*/rtDW./*@>1e6405*/tmpQRSL/*@>15e2f7*/ + /*@>19681b*/1.0)/*@>196e8b*/ * rtDW.d1;
    }
    /*@>196822*/vi/*@>1e6350*/++;
}
/*@>1967ed*/v2norm/*@>15e311*/[/*@>196824*/0U]/*@>15e315*/ = /*@>1dee2a*/rtDW./*@>1e63d5*/tmpQRSL;
/* {E!d334}End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */


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










/* {S!d332}S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */
/*@>1964a2*/pl/*@>15e099*/ = /*@>1e6429*/0;
/*@>1e65ec*/for (/*@>1e65e8*/j/*@>1e65e7*/ = /*@>1e65e9*/0; /*@>1e65de*/j/*@>1e65dc*/ < /*@>1e65e0*/N; /*@>1e65e2*/j/*@>1e6624*/++) {
    /*@>1964a6*/pu/*@>15e0c1*/ = (/*@>1da862*/jpvt/*@>1da864*/[/*@>1da860*/j]/*@>15e0bc*/ > /*@>1964c3*/0);
    /*@>1a77fe*/if (/*@>1da869*/jpvt/*@>1da86b*/[/*@>1da867*/j]/*@>15e0d1*/ < /*@>1964c4*/0) {
        /*@>1a7804*/jpvt/*@>1a7802*/[/*@>1a7806*/j]/*@>1a7801*/ = -/*@<196e47*//*@>1964c5*/j;
    } else {
        /*@>1967b2*/jpvt/*@>18fdda*/[/*@>1967b4*/j]/*@>18fdd9*/ = /*@>1964c7*/j;
    }
    /*@>15e0ee*/if (/*@>1964c9*/pu/*@>15e0ed*/ == /*@>1964cb*/1) {
        /*@>15e0f5*/if (/*@>1964ce*/j/*@>15e0f4*/ != /*@>1964cc*/pl) {
            /* Swap columns pl and j */
            /*@>1964a8*/px/*@>15e108*/ = /*@>1966bc*/pl/*@>196e44*/ * /*@>1966be*/M;
            /*@>1964aa*/px2/*@>15e10c*/ = /*@>1966c0*/j/*@>196e41*/ * /*@>1966c2*/M;
/*@>1e6610*/            for (/*@>1e660b*/i/*@>1e660a*/ = /*@>1e660d*/M; /*@>1e6602*/i/*@>1e6600*/ > /*@>1e6603*/0; /*@>1e6605*/i/*@>1e6625*/--) {
                /*@>1ded10*/rtDW./*@>1e69fc*/maxnrm/*@>15e126*/ = /*@>1da88c*/xVec/*@>1da88e*/[/*@>1da88a*/px];
                /*@>196702*/xVec/*@>180fd7*/[/*@>196704*/px]/*@>15e135*/ = /*@>1da8a1*/xVec/*@>1da8a3*/[/*@>1da89f*/px2];
                /*@>1964dc*/xVec/*@>15e13b*/[/*@>1964da*/px2]/*@>15e13f*/ = /*@>1ded1c*/rtDW./*@>1e6a02*/maxnrm;
                /*@>1964e3*/px/*@>1e6626*/++;
                /*@>1964e8*/px2/*@>1e6627*/++;
            }
        }
        /*@>1966ee*/jpvt/*@>180f61*/[/*@>1966f0*/j]/*@>15e15e*/ = /*@>1da87e*/jpvt/*@>1da880*/[/*@>1da87c*/pl];
        /*@>1964ee*/jpvt/*@>15e166*/[/*@>1964ec*/pl]/*@>15e168*/ = /*@>1964ea*/j;
        /*@>1964f3*/pl/*@>1e6628*/++;
    }
}
/*@>1964f8*/pu/*@>15e178*/ = /*@>1964f5*/N/*@>15e176*/ - /*@>1964f7*/1;
/*@>1e65a2*/for (/*@>1e659b*/j/*@>1e659a*/ = /*@>1e659e*/N/*@>1e659c*/ - /*@>1e659f*/1; /*@>1e6592*/j/*@>1e6590*/ >= /*@>1e6593*/0; /*@>1e6595*/j/*@>1e6629*/--) {
    /*@>15e19d*/if (/*@>1da870*/jpvt/*@>1da872*/[/*@>1da86e*/j]/*@>15e19c*/ < /*@>196504*/0) {
        /*@>1966e6*/jpvt/*@>180f39*/[/*@>1966e8*/j]/*@>15e1ad*/ = -/*@<196e4f*//*@>1da877*/jpvt/*@>1da879*/[/*@>1da875*/j];
        /*@>15e1b4*/if (/*@>196507*/j/*@>15e1b3*/ != /*@>196505*/pu) {
            /* Swap columns pu and j */
            /*@>196509*/px/*@>15e1cb*/ = /*@>1966b4*/pu/*@>196e4c*/ * /*@>1966b6*/M;
            /*@>19650b*/px2/*@>15e1d0*/ = /*@>1966b8*/j/*@>196e49*/ * /*@>1966ba*/M;
/*@>1e65c8*/            for (/*@>1e65c3*/i/*@>1e65c2*/ = /*@>1e65c5*/M; /*@>1e65ba*/i/*@>1e65b8*/ > /*@>1e65bb*/0; /*@>1e65bd*/i/*@>1e662a*/--) {
                /*@>1ded16*/rtDW./*@>1e69ff*/maxnrm/*@>15e1ee*/ = /*@>1da89a*/xVec/*@>1da89c*/[/*@>1da898*/px];
                /*@>19671a*/xVec/*@>181056*/[/*@>19671c*/px]/*@>15e1fd*/ = /*@>1da8af*/xVec/*@>1da8b1*/[/*@>1da8ad*/px2];
                /*@>19651d*/xVec/*@>15e203*/[/*@>19651b*/px2]/*@>15e207*/ = /*@>1ded22*/rtDW./*@>1e6a05*/maxnrm;
                /*@>196524*/px/*@>1e662b*/++;
                /*@>196529*/px2/*@>1e662c*/++;
            }
            /*@>19649c*/px/*@>15e220*/ = /*@>1da893*/jpvt/*@>1da895*/[/*@>1da891*/pu];
            /*@>196712*/jpvt/*@>18102e*/[/*@>196714*/pu]/*@>15e22f*/ = /*@>1da8a8*/jpvt/*@>1da8aa*/[/*@>1da8a6*/j];
            /*@>19652d*/jpvt/*@>15e237*/[/*@>196695*/j]/*@>15e239*/ = /*@>19652b*/px;
        }
        /*@>196532*/pu/*@>1e662d*/--;
    }
}
/* compute the norms of the free columns */
/*@>1e657b*/for (/*@>1e6576*/j/*@>1e6575*/ = /*@>1e6578*/pl; /*@>1e656c*/j/*@>1e656a*/ <= /*@>1e656e*/pu; /*@>1e6570*/j/*@>1e662e*/++) {
    /*@[1e57ce*/QRV2Norm_double_o(&/*@>1e6a90*/xVec/*@>1e6a8f*/[/*@>1e6a92*/j/*@>1e6a91*/ * /*@>1e6a93*/M], /*@>1e6aa1*/M, &/*@>1e6ab1*/qrAux/*@>1e6ab0*/[/*@>1e6ab2*/j])/*@]*/;
    /*@>1966f6*/work/*@>180f95*/[/*@>1966f8*/j]/*@>15e32d*/ = /*@>1da885*/qrAux/*@>1da887*/[/*@>1da883*/j];
}
/* perform the Householder reduction of x */
/*@>1a7807*/if (/*@>1a5e8d*/M/*@>1a048d*/ <= /*@>1a5e8f*/N) {
    /*@>1a780b*/minVal/*@>1a780a*/ = /*@>1a5e91*/M;
} else {
    /*@>1a0492*/minVal/*@>1a0493*/ = /*@>1a5e93*/N;
}
/*@>1e6452*/for (/*@>1e644e*/l/*@>1e644d*/ = /*@>1e644f*/0; /*@>1e6444*/l/*@>1e6442*/ < /*@>1e6446*/minVal; /*@>1e6448*/l/*@>1e662f*/++) {
    /*@>1964a4*/mml/*@>15e35c*/ = /*@>196554*/M/*@>15e35b*/ - /*@>196552*/l;
    /* locate the column of largest norm and bring it into the pivot position */
    /*@>15e36b*/if ((/*@>19655c*/l/*@>15e369*/ >= /*@>19655a*/pl)/*@>15e36a*/ && (/*@>196558*/l/*@>15e364*/ < /*@>196556*/pu)) {
        /*@>1ded28*/rtDW./*@>1e6a08*/maxnrm/*@>15e36f*/ = /*@>19655e*/0.0;
        /*@>1964a0*/maxj/*@>15e373*/ = /*@>19655f*/l;
/*@>1e6555*/        for (/*@>1e6550*/j/*@>1e654f*/ = /*@>1e6552*/l; /*@>1e6546*/j/*@>1e6544*/ <= /*@>1e6548*/pu; /*@>1e654a*/j/*@>1e6630*/++) {
            /*@>15e393*/if (/*@>1da8b6*/qrAux/*@>1da8b8*/[/*@>1da8b4*/j]/*@>15e392*/ > /*@>1ded2e*/rtDW./*@>1e6a0b*/maxnrm) {
                /*@>1ded3a*/rtDW./*@>1e6a11*/maxnrm/*@>15e39d*/ = /*@>1da8bd*/qrAux/*@>1da8bf*/[/*@>1da8bb*/j];
                /*@>196574*/maxj/*@>15e3a2*/ = /*@>196572*/j;
            }
        }
        /*@>15e3a9*/if (/*@>196578*/maxj/*@>15e3a8*/ != /*@>196576*/l) {
            /* Swap columns l and maxj */
            /*@>19657a*/px/*@>15e3bf*/ = /*@>196697*/l/*@>196e5f*/ * /*@>196699*/M;
            /*@>19657c*/px2/*@>15e3c4*/ = /*@>19669b*/maxj/*@>196e5c*/ * /*@>19669d*/M;
/*@>1e6530*/            for (/*@>1e652b*/i/*@>1e652a*/ = /*@>1e652d*/M; /*@>1e6522*/i/*@>1e6520*/ > /*@>1e6523*/0; /*@>1e6525*/i/*@>1e6631*/--) {
                /*@>1ded6a*/rtDW./*@>1e6a29*/maxnrm/*@>15e3e2*/ = /*@>1da8d9*/xVec/*@>1da8db*/[/*@>1da8d7*/px];
                /*@>196746*/xVec/*@>181155*/[/*@>196748*/px]/*@>15e3f1*/ = /*@>1da8e7*/xVec/*@>1da8e9*/[/*@>1da8e5*/px2];
                /*@>19658e*/xVec/*@>15e3f7*/[/*@>19658c*/px2]/*@>15e3fb*/ = /*@>1ded82*/rtDW./*@>1e6a35*/maxnrm;
                /*@>196595*/px/*@>1e6632*/++;
                /*@>19659a*/px2/*@>1e6633*/++;
            }
            /*@>196732*/qrAux/*@>1810ee*/[/*@>196734*/maxj]/*@>15e41a*/ = /*@>1da8d2*/qrAux/*@>1da8d4*/[/*@>1da8d0*/l];
            /*@>19673e*/work/*@>18112d*/[/*@>196740*/maxj]/*@>15e429*/ = /*@>1da8e0*/work/*@>1da8e2*/[/*@>1da8de*/l];
            /*@>19659c*/px/*@>15e433*/ = /*@>1da8ee*/jpvt/*@>1da8f0*/[/*@>1da8ec*/maxj];
            /*@>196752*/jpvt/*@>181195*/[/*@>196754*/maxj]/*@>15e442*/ = /*@>1da8f5*/jpvt/*@>1da8f7*/[/*@>1da8f3*/l];
            /*@>1965a2*/jpvt/*@>15e44a*/[/*@>1965a0*/l]/*@>15e44c*/ = /*@>19659e*/px;
        }
    }
    /*@>1965a6*/qrAux/*@>15e452*/[/*@>1965a4*/l]/*@>15e456*/ = /*@>1965a8*/0.0;
    /*@>15e460*/if (/*@>1965a9*/M/*@>15e45c*/ - /*@>1965ab*/1/*@>15e45f*/ != /*@>1965ac*/l) {
        /* Compute the Householder transformation for column l */
        /*@>1964ac*/maxj/*@>15e46c*/ = (/*@>1965ae*/M/*@>15e468*/ + /*@>1965b0*/1)/*@>196e59*/ * /*@>1965b1*/l;
        /*@>1965b5*/px/*@>15e471*/ = /*@>1965b3*/maxj;
        /*@[1e57e7*/QRV2Norm_double_o(&/*@>1e6ac2*/xVec/*@>1e6ac1*/[/*@>1e6ac3*/maxj], /*@>1e6ad1*/mml, &/*@>1e6ae1*/rtDW./*@>1e6ae0*/nrmxl)/*@]*/;
        /*@>1ded40*/rtDW./*@>1e6a14*/maxnrm/*@>1c3491*/ = /*@>1d35ce*/std::abs(/*@>1ded46*/rtDW./*@>1e6a17*/nrmxl);
        /*@>15e489*/if (/*@>1ded4c*/rtDW./*@>1e6a1a*/maxnrm/*@>15e488*/ != /*@>1965bc*/0.0) {
            /*@>15e49e*/if (/*@>1d35d0*/std::abs(/*@>1da8c4*/xVec/*@>1da8c6*/[/*@>1da8c2*/maxj])/*@>15e49d*/ != /*@>1965bd*/0.0) {
                /*@>1a780c*/if (/*@>1da8cb*/xVec/*@>1da8cd*/[/*@>1da8c9*/maxj]/*@>15e4ae*/ >= /*@>1965be*/0.0) {
                    /*@>1ded5e*/rtDW./*@>1e6a23*/nrmxl/*@>1a780f*/ = rtDW.maxnrm;
                } else {
                    /*@>1ded52*/rtDW./*@>1e6a1d*/nrmxl/*@>18fde2*/ = -/*@<196e58*/rtDW.maxnrm;
                }
            }
            /* Check if it's safe to multiply by 1/nrmxl instead of dividing by nrmxl */
            /*@>1965c7*/px2/*@>15e4c5*/ = /*@>196691*/maxj;
            /*@>15e4d3*/if (/*@>1966a2*/5.0E-20/*@>196e56*/ * /*@>1ded70*/rtDW./*@>1e6a2c*/nrmxl/*@>15e4d2*/ != /*@>1965c9*/0.0) {
                /*@>1ded76*/rtDW./*@>1e6a2f*/maxnrm/*@>15e4db*/ = /*@>1965cc*/1.0/*@>15e4d9*/ / /*@>1ded7c*/rtDW./*@>1e6a32*/nrmxl;
/*@>1e650c*/                for (/*@>1e6507*/i/*@>1e6506*/ = /*@>1e6509*/mml; /*@>1e64fe*/i/*@>1e64fc*/ > /*@>1e64ff*/0; /*@>1e6501*/i/*@>1e6634*/--) {
                    /*@>19676a*/xVec/*@>181212*/[/*@>19676c*/px2]/*@>1e6635*/ *= /*@>1ded8e*/rtDW./*@>1e6a3b*/maxnrm;
                    /*@>1965e0*/px2/*@>1e6636*/++;
                }
            } else {
/*@>1e64e8*/                for (/*@>1e64e3*/i/*@>1e64e2*/ = /*@>1e64e5*/mml; /*@>1e64da*/i/*@>1e64d8*/ > /*@>1e64db*/0; /*@>1e64dd*/i/*@>1e6643*/--) {
                    /*@>19675a*/xVec/*@>1811be*/[/*@>19675c*/px2]/*@>1e6644*/ /= /*@>1ded88*/rtDW./*@>1e6a38*/nrmxl;
                    /*@>1965f3*/px2/*@>1e6645*/++;
                }
            }
            /*@>196762*/xVec/*@>1811e9*/[/*@>196764*/maxj]/*@>1e6637*/++;
            /* apply the transformation to the remaining columns, updating the norms. */
/*@>1e6479*/            for (/*@>1e6472*/j/*@>1e6471*/ = /*@>1e6475*/l/*@>1e6473*/ + /*@>1e6476*/1; /*@>1e6468*/j/*@>1e6466*/ < /*@>1e646a*/N; /*@>1e646c*/j/*@>1e6638*/++) {
                /*@>1964ae*/plj/*@>15e56b*/ = /*@>196608*/j/*@>196e7e*/ * /*@>196606*/M/*@>15e56a*/ + /*@>196604*/l;
                /*@>19660c*/px2/*@>15e570*/ = /*@>19660a*/plj;
                /*@>1ded9a*/rtDW./*@>1e6a41*/t/*@>15e574*/ = /*@>19660e*/0.0;
/*@>1e64c4*/                for (/*@>1e64bf*/i/*@>1e64be*/ = /*@>1e64c1*/mml; /*@>1e64b6*/i/*@>1e64b4*/ > /*@>1e64b7*/0; /*@>1e64b9*/i/*@>1e6639*/--) {
                    /*@>1deda0*/rtDW./*@>1e6a44*/t/*@>1e663a*/ -= /*@>1da918*/xVec/*@>1da91a*/[/*@>1da916*/px]/*@>196e83*/ * /*@>1da91f*/xVec/*@>1da921*/[/*@>1da91d*/px2];
                    /*@>196622*/px/*@>1e663b*/++;
                    /*@>196627*/px2/*@>1e663c*/++;
                }
                /*@>19662b*/px/*@>15e5b2*/ = /*@>196629*/maxj;
                /*@>19662f*/px2/*@>15e5b7*/ = /*@>19662d*/plj;
                /*@>1dedac*/rtDW./*@>1e6a47*/t/*@>1e663d*/ /= /*@>1da926*/xVec/*@>1da928*/[/*@>1da924*/maxj];
/*@>1e64a0*/                for (/*@>1e649b*/i/*@>1e649a*/ = /*@>1e649d*/mml; /*@>1e6492*/i/*@>1e6490*/ > /*@>1e6493*/0; /*@>1e6495*/i/*@>1e663e*/--) {
                    /*@>19678a*/xVec/*@>1812c8*/[/*@>19678c*/px2]/*@>1e663f*/ += /*@>1dedb8*/rtDW./*@>1e6a4a*/t/*@>196e87*/ * /*@>1da92d*/xVec/*@>1da92f*/[/*@>1da92b*/px];
                    /*@>196646*/px/*@>1e6640*/++;
                    /*@>19664b*/px2/*@>1e6641*/++;
                }
                /*@>19664f*/px/*@>15e606*/ = /*@>19664d*/maxj;
                /*@>196651*/px2/*@>15e638*/ = /*@>1e6432*/0;
                /*@>15e644*/if (/*@>1da93b*/qrAux/*@>1da93d*/[/*@>1da939*/j]/*@>15e643*/ == /*@>196654*/0.0) {
                    /*@>196656*/px2/*@>15e649*/ = /*@>1e6435*/1;
                }
                /*@>15e654*/if ((/*@>1966a5*/j/*@>169fbf*/ >= /*@>1966a7*/pl)/*@>169fbe*/ && (/*@>1966a9*/j/*@>169fc0*/ <= /*@>1966ab*/pu)/*@>169fbb*/ && (/*@>196658*/px2/*@>197e47*/ == /*@>196e7b*/0)) {
                    /*@>1dedbe*/rtDW./*@>1e6a4d*/maxnrm/*@>15e66d*/ = /*@>1d35d2*/std::abs(/*@>1da942*/xVec/*@>1da944*/[/*@>1da940*/plj])/*@>15e66b*/ / /*@>1da949*/qrAux/*@>1da94b*/[/*@>1da947*/j];
                    /*@>1dedc4*/rtDW./*@>1e6a50*/tt/*@>15e677*/ = /*@>196660*/1.0/*@>15e676*/ - /*@>1dedca*/rtDW./*@>1e6a53*/maxnrm/*@>196e78*/ * /*@>1dedd0*/rtDW./*@>1e6a56*/maxnrm;
                    /*@>15e67e*/if (/*@>1dedd6*/rtDW./*@>1e6a59*/tt/*@>15e67d*/ < /*@>196663*/0.0) {
                        /*@>1deddc*/rtDW./*@>1e6a5c*/tt/*@>15e683*/ = /*@>196664*/0.0;
                    }
                    /*@>1dede2*/rtDW./*@>1e6a5f*/t/*@>15e688*/ = /*@>1dede8*/rtDW./*@>1e6a62*/tt;
                    /*@>1dedee*/rtDW./*@>1e6a65*/maxnrm/*@>15e69a*/ = /*@>1da950*/qrAux/*@>1da952*/[/*@>1da94e*/j]/*@>15e698*/ / /*@>1da957*/work/*@>1da959*/[/*@>1da955*/j];
                    /*@>1dedf4*/rtDW./*@>1e6a68*/tt/*@>15e6ab*/ = /*@>196673*/0.05/*@>196e74*/ * /*@>1dedfa*/rtDW./*@>1e6a6b*/tt/*@>196e70*/ * /*@>1dee00*/rtDW./*@>1e6a6e*/maxnrm/*@>196e6c*/ * /*@>1dee06*/rtDW./*@>1e6a71*/maxnrm/*@>15e6a9*/ + /*@>196674*/1.0;
                    /*@>15e6b2*/if (/*@>1dee0c*/rtDW./*@>1e6a74*/tt/*@>15e6b1*/ != /*@>196679*/1.0) {
                        /*@>1967a6*/qrAux/*@>181365*/[/*@>1967a8*/j]/*@>1e6642*/ *= /*@>1d35d6*/std::sqrt(/*@>1dee18*/rtDW./*@>1e6a7a*/t);
                    } else {
                        /*@[1e5800*/QRV2Norm_double_o(&/*@>1e6af2*/xVec/*@>1e6af1*/[/*@>1e6af4*/plj/*@>1e6af3*/ + /*@>1e6af5*/1], /*@>1e6b04*/mml/*@>1e6b03*/ - /*@>1e6b05*/1, &/*@>1e6b15*/rtDW./*@>1e6b14*/maxnrm)/*@]*/;
                        /*@>196685*/qrAux/*@>15e6e3*/[/*@>196683*/j]/*@>15e6e7*/ = /*@>1dee1e*/rtDW./*@>1e6a7d*/maxnrm;
                        /*@>1967ae*/work/*@>18138e*/[/*@>1967b0*/j]/*@>15e6f6*/ = /*@>1da965*/qrAux/*@>1da967*/[/*@>1da963*/j];
                    }
                }
            }
            /* save the transformation. */
            /*@>196772*/qrAux/*@>181241*/[/*@>196774*/l]/*@>15e707*/ = /*@>1da911*/xVec/*@>1da913*/[/*@>1da90f*/px];
            /*@>19668d*/xVec/*@>15e710*/[/*@>19668b*/px]/*@>15e712*/ = -/*@<196e53*//*@>1ded94*/rtDW./*@>1e6a3e*/nrmxl;
        }
    }
}
/* {E!d332}End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */


        }

                



            


                        


         

                
                void Rpi_cam::QRE_double_o(double outQ[], double outR[], double outE[], double qrAux[], double work[], int32_t jpvt[], double sPtr[], int32_t M, int32_t N, bool economy)
        {
            int32_t L_tmp;
int32_t ps;














/* {S!d330}S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */
/*@[1e5837*/QRDC_double_o(&/*@>1e6f9f*/outR/*@>1e6f9e*/[/*@>1e6fa0*/0], &/*@>1e6fb0*/qrAux/*@>1e6faf*/[/*@>1e6fb1*/0], &/*@>1e6fc1*/jpvt/*@>1e6fc0*/[/*@>1e6fc2*/0], &/*@>1e6fd2*/work/*@>1e6fd1*/[/*@>1e6fd3*/0], /*@>1e6fe1*/M, /*@>1e6fef*/N)/*@]*/;
/* explicitly form q by manipulating identity */
/*@>18fdcb*/if (/*@>196314*/economy) {
    /*@>1a77f3*/if (/*@>1a5d11*/M/*@>1a0459*/ <= /*@>1a5d13*/N) {
        /*@>1debcc*/rtDW./*@>1e6f0e*/L/*@>1a77f6*/ = /*@>1a5d15*/M;
    } else {
        /*@>1debc6*/rtDW./*@>1e6f0b*/L/*@>1a045f*/ = /*@>1a5d17*/N;
    }
} else {
    /*@>1debc0*/rtDW./*@>1e6f08*/L/*@>15e73f*/ = /*@>196316*/M;
}
/*@>196318*/L_tmp/*@>15e750*/ = /*@>1e6ce2*/0;
/*@>1debd2*/rtDW./*@>1e6f11*/j_b/*@>15e763*/ = /*@>1e6ce5*/0;
while/*@<15e766*/ (/*@>1debd8*/rtDW./*@>1e6f14*/j_b/*@>15e75f*/ < /*@>196320*/M/*@>196e3e*/ * /*@>1debde*/rtDW./*@>1e6f17*/L) {
    /*@>196305*/outQ/*@>15e76a*/[/*@>1debea*/rtDW./*@>1e6f1d*/j_b]/*@>15e76e*/ = /*@>196329*/0.0;
    /*@>1debf0*/rtDW./*@>1e6f20*/j_b/*@>1e6d92*/++;
}
/*@>1debe4*/rtDW./*@>1e6f1a*/j_b/*@>15e77f*/ = /*@>1e6ce8*/0;
while/*@<15e782*/ (/*@>1debfc*/rtDW./*@>1e6f23*/j_b/*@>15e77b*/ < /*@>1dec02*/rtDW./*@>1e6f26*/L) {
    /*@>196338*/outQ/*@>15e788*/[/*@>196336*/L_tmp]/*@>15e78c*/ = /*@>19633a*/1.0;
    /*@>196340*/L_tmp/*@>15e797*/ = (/*@>19633d*/L_tmp/*@>15e792*/ + /*@>19633b*/M)/*@>15e795*/ + /*@>19633f*/1;
    /*@>1dec0e*/rtDW./*@>1e6f2c*/j_b/*@>1e6d93*/++;
}
/* Convert cols of identity into cols of q. Use info stored in lower triangle of r and in vector qraux to work on columns of identity matrix I and transform them into q*I(:,j) i.e. the columns of q. */
/*@>196343*/L_tmp/*@>15e79e*/ = /*@>1e6ceb*/0;
/*@>1dec08*/rtDW./*@>1e6f29*/j_b/*@>15e7af*/ = /*@>1e6cee*/0;
while/*@<15e7b2*/ (/*@>1dec1a*/rtDW./*@>1e6f2f*/j_b/*@>15e7ab*/ < /*@>1dec20*/rtDW./*@>1e6f32*/L) {
    /*@[1e5852*/QRSL1_double(&/*@>1e6fff*/outR/*@>1e6ffe*/[/*@>1e7000*/0], &/*@>1e7010*/qrAux/*@>1e700f*/[/*@>1e7011*/0], &/*@>1e7021*/outQ/*@>1e7020*/[/*@>1e7022*/L_tmp], /*@>1e7030*/M, /*@>1e703e*/N)/*@]*/;
    /*@>196364*/L_tmp/*@>1e6d94*/ += /*@>196360*/M;
    /*@>1dec32*/rtDW./*@>1e6f3b*/j_b/*@>1e6d95*/++;
}
/*@>15e994*/if (/*@>19636c*/economy/*@>15e993*/ && (/*@>19636a*/M/*@>15e98f*/ > /*@>196368*/N)) {
    /* Copy upper triangle of r to s */
    /*@>1dec2c*/rtDW./*@>1e6f38*/L/*@>15e99a*/ = /*@>1e6cf1*/0;
    /*@>19636f*/ps/*@>15e9a1*/ = /*@>1e6cf4*/0;
    /*@>1dec44*/rtDW./*@>1e6f41*/j_b/*@>15e9b2*/ = /*@>1e6cf7*/1;
    while/*@<15e9b5*/ (/*@>1dec50*/rtDW./*@>1e6f47*/j_b/*@>184e11*/ - /*@>19641e*/1/*@>15e9ae*/ < /*@>196377*/N) {
/*@>1e6d79*/        for (/*@>1e6d75*/L_tmp/*@>1e6d74*/ = /*@>1e6d76*/0; /*@>1e6d67*/L_tmp/*@>1e6d91*/ < /*@>1e6d6b*/rtDW./*@>1e6f8c*/j_b; /*@>1e6d6f*/L_tmp/*@>1e6d96*/++) {
            /*@>196410*/sPtr/*@>180df2*/[/*@>196412*/ps]/*@>15e9d3*/ = /*@>1da854*/outR/*@>1da856*/[/*@>1decb6*/rtDW./*@>1e6f6b*/L];
            /*@>19638b*/ps/*@>1e6d97*/++;
            /*@>1decce*/rtDW./*@>1e6f74*/L/*@>1e6d98*/++;
        }
        /*@>1deca4*/rtDW./*@>1e6f62*/L/*@>15e9f1*/ = (/*@>1decaa*/rtDW./*@>1e6f65*/L/*@>15e9eb*/ + /*@>196394*/M)/*@>15e9ec*/ - /*@>1decb0*/rtDW./*@>1e6f68*/j_b;
/*@>1e6d4c*/        for (/*@>1e6d48*/L_tmp/*@>1e6d47*/ = /*@>1e6d49*/0; /*@>1e6d39*/L_tmp/*@>1e6d37*/ < /*@>1e6d3c*/N/*@>1e6d3a*/ - /*@>1e6d3f*/rtDW./*@>1e6f89*/j_b; /*@>1e6d42*/L_tmp/*@>1e6d99*/++) {
            /*@>1963aa*/sPtr/*@>15ea11*/[/*@>1963a8*/ps]/*@>15ea15*/ = /*@>1963ac*/0.0;
            /*@>1963b0*/ps/*@>1e6d9a*/++;
        }
        /*@>1decec*/rtDW./*@>1e6f7d*/j_b/*@>1e6d9b*/++;
    }
} else {
    /* Zero strict lower triangle of r */
    /*@>1dec26*/rtDW./*@>1e6f35*/L/*@>15ea2a*/ = /*@>1963b4*/M/*@>196e3b*/ * /*@>1963b2*/N/*@>15ea28*/ - /*@>1963b6*/1;
    /*@>1dec3e*/rtDW./*@>1e6f3e*/j_b/*@>15ea3e*/ = /*@>1963c1*/N;
    while/*@<15ea41*/ (/*@>1dec4a*/rtDW./*@>1e6f44*/j_b/*@>184e0a*/ - /*@>19641c*/1/*@>15ea37*/ >= /*@>1963c0*/0) {
/*@>1e6d20*/        for (/*@>1e6d1b*/L_tmp/*@>1e6d1a*/ = /*@>1e6d1d*/M; /*@>1e6d0f*/L_tmp/*@>1e6d0d*/ > /*@>1e6d12*/rtDW./*@>1e6f86*/j_b; /*@>1e6d15*/L_tmp/*@>1e6d9e*/--) {
            /*@>1963d4*/outR/*@>15ea5e*/[/*@>1dec68*/rtDW./*@>1e6f50*/L]/*@>15ea62*/ = /*@>1963d6*/0.0;
            /*@>1dec98*/rtDW./*@>1e6f5f*/L/*@>1e6d9f*/--;
        }
        /*@>1a77f8*/if (/*@>1963de*/M/*@>15ea73*/ < /*@>1dec62*/rtDW./*@>1e6f4d*/j_b) {
            /*@>1dec8c*/rtDW./*@>1e6f5c*/L/*@>1e6da0*/ -= /*@>1963e0*/M;
        } else {
            /*@>1dec7a*/rtDW./*@>1e6f56*/L/*@>1e6da2*/ -= /*@>1dec86*/rtDW./*@>1e6f59*/j_b;
        }
        /*@>1decc2*/rtDW./*@>1e6f71*/j_b/*@>1e6da1*/--;
    }
}
/* form permutation vector e */
/*@>1dec56*/rtDW./*@>1e6f4a*/L/*@>15ea90*/ = /*@>1e6cfd*/0;
/*@>1963ed*/L_tmp/*@>15ea97*/ = /*@>1e6d00*/0;
/*@>1dec74*/rtDW./*@>1e6f53*/j_b/*@>15eaa8*/ = /*@>1e6d03*/0;
while/*@<15eaab*/ (/*@>1decbc*/rtDW./*@>1e6f6e*/j_b/*@>15eaa4*/ < /*@>1963f5*/N) {
    /*@>196418*/outE/*@>180e1f*/[/*@>1decda*/rtDW./*@>1e6f77*/L]/*@>15eaba*/ = /*@>1da85b*/jpvt/*@>1da85d*/[/*@>1da859*/L_tmp]/*@>15eab4*/ + /*@>1963fc*/1;
    /*@>1c1521*/L_tmp/*@>1c1523*/ = /*@>1dece6*/rtDW./*@>1e6f7a*/L/*@>1cf3f3*/ + /*@>1cf3f6*/1;
    /*@>1decf8*/rtDW./*@>1e6f80*/L/*@>1e6d9c*/++;
    /*@>1ded04*/rtDW./*@>1e6f83*/j_b/*@>1e6d9d*/++;
}
/* {E!d330}End of S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */


        }

                





                        


         

                
                void Rpi_cam::Warp_stepImpl(vision_internal_blocks_Warp *b_this, const bool Image[307200], const double input2[9], bool Jout[307200])
        {
            int32_t itmp;
int32_t p1;
int32_t p2;
int32_t p3;
/*@>17eb13*/for (/*@>1e70d3*/p2 = /*@>1e70d2*/0; /*@>1e70dd*/p2 < /*@>1e70db*/9; /*@>1e70d9*/p2/*@>1e70e1*/++) {
    /* {S!d290}Start for MATLABSystem: '<S4>/Warp' */
    /*@>1de6c2*/rtDW./*@>1e76e9*/absx11/*@>17eb06*/ = /*@>1da49e*/input2/*@>1da4a0*/[/*@>1da49c*/p2];
    /*@>1ae229*/b_this->/*@>1e768c*/TformProjective./*@>1e7689*/T/*@>1ae225*/[/*@>1ae22d*/p2]/*@>1ae230*/ = /*@>1de6c8*/rtDW./*@>1e76ec*/absx11;
    /*@>1de6ce*/rtDW./*@>1e76ef*/x/*@>17eb4e*/[/*@>195969*/p2]/*@>17eb4f*/ = /*@>1de6d4*/rtDW./*@>1e76f2*/absx11;
}
/*@>195849*/p1/*@>13eea4*/ = /*@>1e704c*/1;
/*@>19584b*/p2/*@>13eea6*/ = /*@>1e704f*/3;
/*@>19584d*/p3/*@>13eea8*/ = /*@>1e7052*/6;
/* {S!d292}Start for MATLABSystem: '<S4>/Warp' */
/*@>1de6da*/rtDW./*@>1e76f5*/absx11/*@>13f7b4*/ = /*@>1d3592*/std::abs(/*@>1da4a4*/b_this->/*@>1e768f*/TformProjective./*@>1e7692*/T/*@>1da4ae*/[/*@>1da4a2*/0]);
/*@>1de6e0*/rtDW./*@>1e76f8*/absx21/*@>13f7d0*/ = /*@>1d3594*/std::abs(/*@>1da4b2*/b_this->/*@>1e7695*/TformProjective./*@>1e7698*/T/*@>1da4bc*/[/*@>1da4b0*/1]);
/*@>1de6e6*/rtDW./*@>1e76fb*/absx31/*@>13f7ec*/ = /*@>1d3596*/std::abs(/*@>1da4c0*/b_this->/*@>1e769b*/TformProjective./*@>1e769e*/T/*@>1da4ca*/[/*@>1da4be*/2]);
/*@>13f110*/if ((/*@>1de6ec*/rtDW./*@>1e76fe*/absx21/*@>13f06e*/ > /*@>1de6f2*/rtDW./*@>1e7701*/absx11)/*@>154df4*/ && (/*@>1de6f8*/rtDW./*@>1e7704*/absx21/*@>13f06f*/ > /*@>1de6fe*/rtDW./*@>1e7707*/absx31)) {
    /*@>195857*/p1/*@>13eec1*/ = /*@>1e7055*/4;
    /*@>195859*/p2/*@>13eec3*/ = /*@>1e705b*/0;
    /*@>1de710*/rtDW./*@>1e7710*/x/*@>18edfe*/[/*@>195b90*/0]/*@>13eece*/ = /*@>1da4ce*/b_this->/*@>1e76a1*/TformProjective./*@>1e76a4*/T/*@>1da4d8*/[/*@>1da4cc*/1];
    /*@>1de72e*/rtDW./*@>1e771f*/x/*@>18ee0c*/[/*@>195b92*/1]/*@>13eed3*/ = /*@>1da4f4*/b_this->/*@>1e76ad*/TformProjective./*@>1e76b0*/T/*@>1da4fe*/[/*@>1da4f2*/0];
    /*@>1de746*/rtDW./*@>1e772b*/x/*@>18ee1a*/[/*@>195b94*/3]/*@>13eede*/ = /*@>1da510*/b_this->/*@>1e76b9*/TformProjective./*@>1e76bc*/T/*@>1da51a*/[/*@>1da50e*/4];
    /*@>1de764*/rtDW./*@>1e773a*/x/*@>18ee28*/[/*@>195b96*/4]/*@>13eee3*/ = /*@>1da536*/b_this->/*@>1e76c5*/TformProjective./*@>1e76c8*/T/*@>1da540*/[/*@>1da534*/3];
    /*@>1de77c*/rtDW./*@>1e7746*/x/*@>18ee36*/[/*@>195b98*/6]/*@>13eeee*/ = /*@>1da552*/b_this->/*@>1e76d1*/TformProjective./*@>1e76d4*/T/*@>1da55c*/[/*@>1da550*/7];
    /*@>1de7a0*/rtDW./*@>1e7755*/x/*@>18ee44*/[/*@>195b9a*/7]/*@>13eef3*/ = /*@>1da578*/b_this->/*@>1e76dd*/TformProjective./*@>1e76e0*/T/*@>1da582*/[/*@>1da576*/6];
} else /*@>13f11e*/if (/*@>1de704*/rtDW./*@>1e770a*/absx31/*@>13f070*/ > /*@>1de70a*/rtDW./*@>1e770d*/absx11) {
    /*@>19585f*/p1/*@>13eef9*/ = /*@>1e7058*/7;
    /*@>195861*/p3/*@>13eefb*/ = /*@>1e705e*/0;
    /*@>1de728*/rtDW./*@>1e771c*/x/*@>18eda8*/[/*@>195b84*/0]/*@>13ef06*/ = /*@>1da4e6*/b_this->/*@>1e76a7*/TformProjective./*@>1e76aa*/T/*@>1da4f0*/[/*@>1da4e4*/2];
    /*@>1de740*/rtDW./*@>1e7728*/x/*@>18edb6*/[/*@>195b86*/2]/*@>13ef0b*/ = /*@>1da502*/b_this->/*@>1e76b3*/TformProjective./*@>1e76b6*/T/*@>1da50c*/[/*@>1da500*/0];
    /*@>1de75e*/rtDW./*@>1e7737*/x/*@>18edc4*/[/*@>195b88*/3]/*@>13ef16*/ = /*@>1da528*/b_this->/*@>1e76bf*/TformProjective./*@>1e76c2*/T/*@>1da532*/[/*@>1da526*/5];
    /*@>1de776*/rtDW./*@>1e7743*/x/*@>18edd2*/[/*@>195b8a*/5]/*@>13ef1b*/ = /*@>1da544*/b_this->/*@>1e76cb*/TformProjective./*@>1e76ce*/T/*@>1da54e*/[/*@>1da542*/3];
    /*@>1de79a*/rtDW./*@>1e7752*/x/*@>18ede0*/[/*@>195b8c*/6]/*@>13ef26*/ = /*@>1da56a*/b_this->/*@>1e76d7*/TformProjective./*@>1e76da*/T/*@>1da574*/[/*@>1da568*/8];
    /*@>1de7be*/rtDW./*@>1e7761*/x/*@>18edee*/[/*@>195b8e*/8]/*@>13ef2b*/ = /*@>1da590*/b_this->/*@>1e76e3*/TformProjective./*@>1e76e6*/T/*@>1da59a*/[/*@>1da58e*/6];
}
/*@>1de716*/rtDW./*@>1e7713*/absx31/*@>1bd6ff*/ = /*@>1de71c*/rtDW./*@>1e7716*/x/*@>1da4dd*/[/*@>1da4da*/1]/*@>196d41*/ / /*@>1de722*/rtDW./*@>1e7719*/x/*@>1da4e2*/[/*@>1da4df*/0];
/*@>1de734*/rtDW./*@>1e7722*/x/*@>18ee61*/[/*@>195b9e*/1]/*@>13ef34*/ = rtDW.absx31;
/* {S!d294}Start for MATLABSystem: '<S4>/Warp' */
/*@>1de74c*/rtDW./*@>1e772e*/absx11/*@>1bd709*/ = /*@>1de752*/rtDW./*@>1e7731*/x/*@>1da51f*/[/*@>1da51c*/2]/*@>196d39*/ / /*@>1de758*/rtDW./*@>1e7734*/x/*@>1da524*/[/*@>1da521*/0];
/*@>1de76a*/rtDW./*@>1e773d*/x/*@>18ee85*/[/*@>195ba3*/2]/*@>13ef3d*/ = rtDW.absx11;
/*@>1de782*/rtDW./*@>1e7749*/x/*@>18ee9a*/[/*@>195ba6*/4]/*@>1e70e2*/ -= /*@>1de78e*/rtDW./*@>1e774c*/absx31/*@>196d31*/ * /*@>1de794*/rtDW./*@>1e774f*/x/*@>1da566*/[/*@>1da563*/3];
/*@>1de7a6*/rtDW./*@>1e7758*/x/*@>18eeb0*/[/*@>195ba9*/5]/*@>1e70e3*/ -= /*@>1de7b2*/rtDW./*@>1e775b*/absx11/*@>196d2d*/ * /*@>1de7b8*/rtDW./*@>1e775e*/x/*@>1da58c*/[/*@>1da589*/3];
/*@>1de7c4*/rtDW./*@>1e7764*/x/*@>18eec6*/[/*@>195bac*/7]/*@>1e70e4*/ -= /*@>1de7d0*/rtDW./*@>1e7767*/absx31/*@>196d29*/ * /*@>1de7d6*/rtDW./*@>1e776a*/x/*@>1da5a4*/[/*@>1da5a1*/6];
/*@>1de7dc*/rtDW./*@>1e776d*/x/*@>18eedc*/[/*@>195baf*/8]/*@>1e70e5*/ -= /*@>1de7e8*/rtDW./*@>1e7770*/absx11/*@>196d25*/ * /*@>1de7ee*/rtDW./*@>1e7773*/x/*@>1da5ae*/[/*@>1da5ab*/6];
/* {S!d296}Start for MATLABSystem: '<S4>/Warp' */
/*@>13f132*/if (/*@>1d3598*/std::abs(/*@>1de7f4*/rtDW./*@>1e7776*/x/*@>1da5b3*/[/*@>1da5b0*/5])/*@>13f09d*/ > /*@>1d359a*/std::abs(/*@>1de7fa*/rtDW./*@>1e7779*/x/*@>1da5b8*/[/*@>1da5b5*/4])) {
    /*@>195863*/itmp/*@>13ef77*/ = /*@>195865*/p2;
    /*@>195867*/p2/*@>13ef7b*/ = /*@>195869*/p3;
    /*@>19586b*/p3/*@>13ef7f*/ = /*@>19586d*/itmp;
    /*@>1de848*/rtDW./*@>1e779d*/x/*@>18ef06*/[/*@>195bb4*/1]/*@>13ef8a*/ = /*@>1de84e*/rtDW./*@>1e77a0*/absx11;
    /*@>1de872*/rtDW./*@>1e77b2*/x/*@>18ef0e*/[/*@>195bb5*/2]/*@>13ef8f*/ = /*@>1de878*/rtDW./*@>1e77b5*/absx31;
    /*@>1de884*/rtDW./*@>1e77b8*/absx11/*@>13ef94*/ = /*@>1de88a*/rtDW./*@>1e77bb*/x/*@>1da5ef*/[/*@>1da5ec*/4];
    /*@>1de8b4*/rtDW./*@>1e77d0*/x/*@>18ef1e*/[/*@>195bb7*/4]/*@>13ef9a*/ = /*@>1de8ba*/rtDW./*@>1e77d3*/x/*@>1da603*/[/*@>1da600*/5];
    /*@>1de8cc*/rtDW./*@>1e77dc*/x/*@>18ef2c*/[/*@>195bb9*/5]/*@>13ef9f*/ = /*@>1de8d2*/rtDW./*@>1e77df*/absx11;
    /*@>1de8e4*/rtDW./*@>1e77e8*/absx11/*@>13efa4*/ = /*@>1de8ea*/rtDW./*@>1e77eb*/x/*@>1da608*/[/*@>1da605*/7];
    /*@>1de902*/rtDW./*@>1e77f7*/x/*@>18ef3c*/[/*@>195bbb*/7]/*@>13efaa*/ = /*@>1de908*/rtDW./*@>1e77fa*/x/*@>1da612*/[/*@>1da60f*/8];
    /*@>1de926*/rtDW./*@>1e7809*/x/*@>18ef4a*/[/*@>195bbd*/8]/*@>13efaf*/ = /*@>1de92c*/rtDW./*@>1e780c*/absx11;
}
/*@>1de800*/rtDW./*@>1e777c*/absx31/*@>1bd713*/ = /*@>1de806*/rtDW./*@>1e777f*/x/*@>1da5bd*/[/*@>1da5ba*/5]/*@>196d21*/ / /*@>1de80c*/rtDW./*@>1e7782*/x/*@>1da5c2*/[/*@>1da5bf*/4];
/*@>1de812*/rtDW./*@>1e7785*/x/*@>18ef76*/[/*@>195bc3*/8]/*@>1e70e6*/ -= /*@>1de81e*/rtDW./*@>1e7788*/absx31/*@>196d19*/ * /*@>1de824*/rtDW./*@>1e778b*/x/*@>1da5cc*/[/*@>1da5c9*/7];
/* {S!d298}Start for MATLABSystem: '<S4>/Warp' */
/*@>1de82a*/rtDW./*@>1e778e*/absx11/*@>13f1f1*/ = (/*@>1de830*/rtDW./*@>1e7791*/x/*@>1da5d1*/[/*@>1da5ce*/1]/*@>196d15*/ * rtDW.absx31/*@>142859*/ - /*@>1de83c*/rtDW./*@>1e7797*/x/*@>1da5d6*/[/*@>1da5d3*/2])/*@>196d11*/ / /*@>1de842*/rtDW./*@>1e779a*/x/*@>1da5db*/[/*@>1da5d8*/8];
/*@>1de854*/rtDW./*@>1e77a3*/absx21/*@>13f1ff*/ = -/*@<196d0a*/(/*@>1de85a*/rtDW./*@>1e77a6*/x/*@>1da5e0*/[/*@>1da5dd*/7]/*@>196d0d*/ * /*@>1de860*/rtDW./*@>1e77a9*/absx11/*@>142872*/ + /*@>1de866*/rtDW./*@>1e77ac*/x/*@>1da5e5*/[/*@>1da5e2*/1])/*@>196d08*/ / /*@>1de86c*/rtDW./*@>1e77af*/x/*@>1da5ea*/[/*@>1da5e7*/4];
/*@>1de890*/rtDW./*@>1e77be*/tinv/*@>17f47b*/[/*@>195a22*/p1/*@>184d76*/ - /*@>195b4a*/1]/*@>13eff0*/ = ((/*@>195919*/1.0/*@>142e93*/ - /*@>1de896*/rtDW./*@>1e77c1*/x/*@>1da5f4*/[/*@>1da5f1*/3]/*@>196d00*/ * /*@>1de89c*/rtDW./*@>1e77c4*/absx21)/*@>142e92*/ - /*@>1de8a2*/rtDW./*@>1e77c7*/x/*@>1da5f9*/[/*@>1da5f6*/6]/*@>196d04*/ * /*@>1de8a8*/rtDW./*@>1e77ca*/absx11)/*@>196cfc*/ / /*@>1de8ae*/rtDW./*@>1e77cd*/x/*@>1da5fe*/[/*@>1da5fb*/0];
/*@>1de8c0*/rtDW./*@>1e77d6*/tinv/*@>17f49f*/[/*@>195a26*/p1]/*@>13eff8*/ = /*@>1de8c6*/rtDW./*@>1e77d9*/absx21;
/*@>1de8d8*/rtDW./*@>1e77e2*/tinv/*@>17f4e5*/[/*@>195a2c*/p1/*@>17f4ec*/ + /*@>195a2e*/1]/*@>13f000*/ = /*@>1de8de*/rtDW./*@>1e77e5*/absx11;
/*@>1de8f0*/rtDW./*@>1e77ee*/absx11/*@>13f250*/ = -/*@<196cf9*/rtDW.absx31/*@>196cf7*/ / /*@>1de8fc*/rtDW./*@>1e77f4*/x/*@>1da60d*/[/*@>1da60a*/8];
/*@>1de90e*/rtDW./*@>1e77fd*/absx21/*@>13f25e*/ = (/*@>1958ef*/1.0/*@>1428d0*/ - /*@>1de914*/rtDW./*@>1e7800*/x/*@>1da617*/[/*@>1da614*/7]/*@>196cf3*/ * /*@>1de91a*/rtDW./*@>1e7803*/absx11)/*@>196cef*/ / /*@>1de920*/rtDW./*@>1e7806*/x/*@>1da61c*/[/*@>1da619*/4];
/*@>1de932*/rtDW./*@>1e780f*/tinv/*@>17f629*/[/*@>195a43*/p2]/*@>13f022*/ = -/*@<196ce4*/(/*@>1de938*/rtDW./*@>1e7812*/x/*@>1da621*/[/*@>1da61e*/3]/*@>196ce7*/ * /*@>1de93e*/rtDW./*@>1e7815*/absx21/*@>142eb4*/ + /*@>1de944*/rtDW./*@>1e7818*/x/*@>1da626*/[/*@>1da623*/6]/*@>196ceb*/ * /*@>1de94a*/rtDW./*@>1e781b*/absx11)/*@>196ce2*/ / /*@>1de950*/rtDW./*@>1e781e*/x/*@>1da62b*/[/*@>1da628*/0];
/*@>1de956*/rtDW./*@>1e7821*/tinv/*@>17f64c*/[/*@>195a47*/p2/*@>17f653*/ + /*@>195a49*/1]/*@>13f02a*/ = /*@>1de95c*/rtDW./*@>1e7824*/absx21;
/*@>1de962*/rtDW./*@>1e7827*/tinv/*@>17f671*/[/*@>195a4c*/p2/*@>17f678*/ + /*@>195a4e*/2]/*@>13f032*/ = /*@>1de968*/rtDW./*@>1e782a*/absx11;
/*@>1de96e*/rtDW./*@>1e782d*/absx11/*@>13f2af*/ = /*@>1958f2*/1.0/*@>196cde*/ / /*@>1de974*/rtDW./*@>1e7830*/x/*@>1da630*/[/*@>1da62d*/8];
/*@>1de97a*/rtDW./*@>1e7833*/absx21/*@>13f2bd*/ = -/*@<196cdb*//*@>1de980*/rtDW./*@>1e7836*/x/*@>1da635*/[/*@>1da632*/7]/*@>196cd9*/ * /*@>1de986*/rtDW./*@>1e7839*/absx11/*@>196cd5*/ / /*@>1de98c*/rtDW./*@>1e783c*/x/*@>1da63a*/[/*@>1da637*/4];
/*@>1de992*/rtDW./*@>1e783f*/tinv/*@>17f758*/[/*@>195a5d*/p3]/*@>13f051*/ = -/*@<196cca*/(/*@>1de998*/rtDW./*@>1e7842*/x/*@>1da63f*/[/*@>1da63c*/3]/*@>196ccd*/ * /*@>1de99e*/rtDW./*@>1e7845*/absx21/*@>142ed3*/ + /*@>1de9a4*/rtDW./*@>1e7848*/x/*@>1da644*/[/*@>1da641*/6]/*@>196cd1*/ * /*@>1de9aa*/rtDW./*@>1e784b*/absx11)/*@>196cc8*/ / /*@>1de9b0*/rtDW./*@>1e784e*/x/*@>1da649*/[/*@>1da646*/0];
/*@>1de9b6*/rtDW./*@>1e7851*/tinv/*@>17f77b*/[/*@>195a61*/p3/*@>17f782*/ + /*@>195a63*/1]/*@>13f059*/ = /*@>1de9bc*/rtDW./*@>1e7854*/absx21;
/*@>1de9c2*/rtDW./*@>1e7857*/tinv/*@>17f7a0*/[/*@>195a66*/p3/*@>17f7a7*/ + /*@>195a68*/2]/*@>13f061*/ = /*@>1de9c8*/rtDW./*@>1e785a*/absx11;
/*@>1de9ce*/rtDW./*@>1e785d*/absx21/*@>188f96*/ = /*@>1de9d4*/rtDW./*@>1e7860*/tinv/*@>1da64e*/[/*@>1da64b*/6];
/*@>1de9da*/rtDW./*@>1e7863*/absx31/*@>188fa5*/ = /*@>1de9e0*/rtDW./*@>1e7866*/tinv/*@>1da653*/[/*@>1da650*/7];
/*@>1de9e6*/rtDW./*@>1e7869*/tinv_b/*@>188fb4*/ = /*@>1de9ec*/rtDW./*@>1e786c*/tinv/*@>1da658*/[/*@>1da655*/8];
/* {S!d300}Start for MATLABSystem: '<S4>/Warp' */
/*@>1de9f2*/rtDW./*@>1e786f*/tinv_p/*@>188fc3*/ = /*@>1de9f8*/rtDW./*@>1e7872*/tinv/*@>1da65d*/[/*@>1da65a*/0];
/*@>1de9fe*/rtDW./*@>1e7875*/tinv_c/*@>188fd2*/ = /*@>1dea04*/rtDW./*@>1e7878*/tinv/*@>1da662*/[/*@>1da65f*/1];
/*@>1dea0a*/rtDW./*@>1e787b*/tinv_f/*@>188fe1*/ = /*@>1dea10*/rtDW./*@>1e787e*/tinv/*@>1da667*/[/*@>1da664*/2];
/*@>1dea16*/rtDW./*@>1e7881*/tinv_g/*@>188ff0*/ = /*@>1dea1c*/rtDW./*@>1e7884*/tinv/*@>1da66c*/[/*@>1da669*/3];
/*@>1dea22*/rtDW./*@>1e7887*/tinv_g1/*@>188fff*/ = /*@>1dea28*/rtDW./*@>1e788a*/tinv/*@>1da671*/[/*@>1da66e*/4];
/*@>1dea2e*/rtDW./*@>1e788d*/tinv_m/*@>18900e*/ = /*@>1dea34*/rtDW./*@>1e7890*/tinv/*@>1da676*/[/*@>1da673*/5];
/*@>13ecd3*/for (/*@>1e70b1*/p1 = /*@>1e70b0*/0; /*@>1e70bb*/p1 < /*@>1e70b9*/640; /*@>1e70b7*/p1/*@>1e70e7*/++) {
/*@>13ecd7*/    for (/*@>1e70c2*/p2 = /*@>1e70c1*/0; /*@>1e70cc*/p2 < /*@>1e70ca*/480; /*@>1e70c8*/p2/*@>1e70e8*/++) {
        /* {S!d302}Start for MATLABSystem: '<S4>/Warp' */
        /*@>1dea4c*/rtDW./*@>1e7893*/absx11/*@>13ec6a*/ = ((((static_cast<double>(/*@>195926*/p1)/*@>142ef5*/ + /*@>195928*/1.0)/*@>14299f*/ - /*@>1958f6*/0.5)/*@>14299d*/ + /*@>1958f5*/0.5)/*@>196d7d*/ * /*@>1dea52*/rtDW./*@>1e7896*/absx21/*@>13ecb6*/ + (((static_cast<double>(/*@>195929*/p2)/*@>142efa*/ + /*@>19592b*/1.0)/*@>1429a5*/ - /*@>1958f8*/0.5)/*@>1429a3*/ + /*@>1958f7*/0.5)/*@>196d84*/ * /*@>1dea58*/rtDW./*@>1e7899*/absx31)/*@>13ecb7*/ + /*@>1dea5e*/rtDW./*@>1e789c*/tinv_b;
        /*@>1bd71b*/itmp/*@>1bd71d*/ = /*@>195be6*/480/*@>196d66*/ * /*@>195a7a*/p1/*@>18f0a9*/ + /*@>195a78*/p2;
        /*@>1dea6a*/rtDW./*@>1e78a2*/srcXIntrinsic/*@>18f0ad*/[/*@>1bd71f*/itmp]/*@>13ec80*/ = ((((((static_cast<double>(/*@>195942*/p1)/*@>14300c*/ + /*@>195944*/1.0)/*@>14300b*/ - /*@>195945*/0.5)/*@>143009*/ + /*@>195941*/0.5)/*@>196d6f*/ * /*@>1dea70*/rtDW./*@>1e78a5*/tinv_p/*@>142f28*/ + (((static_cast<double>(/*@>195947*/p2)/*@>143015*/ + /*@>195949*/1.0)/*@>143014*/ - /*@>19594a*/0.5)/*@>143012*/ + /*@>195946*/0.5)/*@>196d76*/ * /*@>1dea76*/rtDW./*@>1e78a8*/tinv_c)/*@>142f27*/ + /*@>1dea7c*/rtDW./*@>1e78ab*/tinv_f)/*@>196d6b*/ / /*@>1dea82*/rtDW./*@>1e78ae*/absx11/*@>13ecbc*/ - /*@>195847*/0.5)/*@>13ecbd*/ + /*@>19583b*/0.5;
        /*@>1dea88*/rtDW./*@>1e78b1*/srcYIntrinsic/*@>18f0c0*/[itmp]/*@>13ec8a*/ = ((((((static_cast<double>(/*@>19594c*/p1)/*@>14301f*/ + /*@>19594e*/1.0)/*@>14301e*/ - /*@>19594f*/0.5)/*@>14301c*/ + /*@>19594b*/0.5)/*@>196d5a*/ * /*@>1dea8e*/rtDW./*@>1e78b4*/tinv_g/*@>142f43*/ + (((static_cast<double>(/*@>195951*/p2)/*@>143028*/ + /*@>195953*/1.0)/*@>143027*/ - /*@>195954*/0.5)/*@>143025*/ + /*@>195950*/0.5)/*@>196d61*/ * /*@>1dea94*/rtDW./*@>1e78b7*/tinv_g1)/*@>142f42*/ + /*@>1dea9a*/rtDW./*@>1e78ba*/tinv_m)/*@>196d56*/ / /*@>1deaa0*/rtDW./*@>1e78bd*/absx11/*@>13ecbe*/ - /*@>195848*/0.5)/*@>13ecbf*/ + /*@>19583c*/0.5;
    }
}
/*@>17f7f8*/for (/*@>1e70a0*/p2 = /*@>1e709f*/0; /*@>1e70aa*/p2 < /*@>1e70a8*/307200; /*@>1e70a6*/p2/*@>1e70ef*/++) {
    /* {S!d304}Start for MATLABSystem: '<S4>/Warp' */
    /*@>1dea64*/rtDW./*@>1e789f*/inputImage/*@>17f7ea*/[/*@>195a6d*/p2]/*@>17f7eb*/ = static_cast<int8_t>(/*@>1da67b*/Image/*@>1da67d*/[/*@>1da679*/p2]);
}
/*@>13f596*/for (/*@>1e708f*/p1 = /*@>1e708e*/0; /*@>1e7099*/p1 < /*@>1e7097*/307200; /*@>1e7095*/p1/*@>1e70f1*/++) {
    float qx2;
    /* {S!d306}Start for MATLABSystem: '<S4>/Warp' */
    /*@>1deaa6*/rtDW./*@>1e78c0*/absx11/*@>1ae191*/ = /*@>1deaac*/rtDW./*@>1e78c3*/srcXIntrinsic/*@>1da683*/[/*@>1da680*/p1];
    /*@>13f616*/if ((/*@>1deab2*/rtDW./*@>1e78c6*/absx11/*@>13f604*/ >= /*@>1958b1*/1.0)/*@>1e521e*/ && (/*@>1deab8*/rtDW./*@>1e78c9*/absx11/*@>13f605*/ <= /*@>1958b3*/640.0)) {
        /*@>1deabe*/rtDW./*@>1e78cc*/absx21/*@>1ae1b5*/ = /*@>1deac4*/rtDW./*@>1e78cf*/srcYIntrinsic/*@>1da689*/[/*@>1da686*/p1];
        /*@>13f618*/if ((/*@>1deaca*/rtDW./*@>1e78d2*/absx21/*@>13f606*/ >= /*@>1958b2*/1.0)/*@>1e521f*/ && (/*@>1dead0*/rtDW./*@>1e78d5*/absx21/*@>13f607*/ <= /*@>1958b4*/480.0)) {
            float qx1;
            /*@>1a77c1*/if (/*@>1dead6*/rtDW./*@>1e78d8*/absx11/*@>13f641*/ <= /*@>1958b6*/1.0) {
                /*@>1a77c5*/p3/*@>1a77c4*/ = /*@>1e7061*/1;
            } else /*@>1a77d5*/if (/*@>1deadc*/rtDW./*@>1e78db*/absx11/*@>13f642*/ <= /*@>195955*/639.0) {
                /*@>1a77d9*/p3/*@>1a77d8*/ = static_cast<int32_t>(/*@>1d359c*/std::floor(/*@>1deae2*/rtDW./*@>1e78de*/absx11));
            } else {
                /*@>195bf6*/p3/*@>18fd8c*/ = /*@>1e7064*/639;
            }
            /*@>1deae8*/rtDW./*@>1e78e1*/absx21/*@>1ae1c7*/ = /*@>1deaee*/rtDW./*@>1e78e4*/srcYIntrinsic/*@>1da68f*/[/*@>1da68c*/p1];
            /*@>1a77c6*/if (/*@>1deaf4*/rtDW./*@>1e78e7*/absx21/*@>13f666*/ <= /*@>1958ba*/1.0) {
                /*@>1a77ca*/itmp/*@>1a77c9*/ = /*@>1e7067*/1;
            } else /*@>1a77da*/if (/*@>1deafa*/rtDW./*@>1e78ea*/absx21/*@>13f667*/ <= /*@>195956*/479.0) {
                /*@>1a77de*/itmp/*@>1a77dd*/ = static_cast<int32_t>(/*@>1d359e*/std::floor(/*@>1deb00*/rtDW./*@>1e78ed*/absx21));
            } else {
                /*@>195bf8*/itmp/*@>18fd91*/ = /*@>1e706a*/479;
            }
            /*@>13f718*/if (/*@>1deb06*/rtDW./*@>1e78f0*/absx11/*@>13f706*/ == /*@>1958fd*/p3) {
                /*@>1bd725*/p2/*@>1bd727*/ = (/*@>195ab0*/p3/*@>17fbbd*/ - /*@>195ab2*/1)/*@>196dd0*/ * /*@>195bf4*/480/*@>19079a*/ + /*@>195aad*/itmp;
                /*@>1958be*/qx1/*@>13f699*/ = /*@>1deb1e*/rtDW./*@>1e78f9*/inputImage/*@>1da697*/[/*@>1da693*/p2/*@>1da691*/ - /*@>1da694*/1];
                /*@>1958c0*/qx2/*@>13f69d*/ = /*@>1deb2a*/rtDW./*@>1e78ff*/inputImage/*@>1da6a5*/[p2];
            } else /*@>13f71b*/if (static_cast<double>(/*@>195930*/p3)/*@>142b54*/ + /*@>1958ff*/1.0/*@>13f707*/ == /*@>1deb0c*/rtDW./*@>1e78f3*/absx11) {
                /*@>1bd72f*/p2/*@>1bd731*/ = /*@>195bf2*/480/*@>196dca*/ * /*@>195aba*/p3/*@>190798*/ + /*@>195ab7*/itmp;
                /*@>1958c2*/qx1/*@>13f6a5*/ = /*@>1deb24*/rtDW./*@>1e78fc*/inputImage/*@>1da69f*/[/*@>1da69b*/p2/*@>1da699*/ - /*@>1da69c*/1];
                /*@>1958c4*/qx2/*@>13f6a9*/ = /*@>1deb36*/rtDW./*@>1e7905*/inputImage/*@>1da6b3*/[p2];
            } else {
                int8_t tmp;
                int8_t tmp_0;
                /*@>1deb12*/rtDW./*@>1e78f6*/absx11/*@>1e70f8*/ -= static_cast<double>(/*@>195900*/p3);
                /*@>1bd74f*/p2/*@>1bd751*/ = (/*@>195ac8*/p3/*@>17fc54*/ - /*@>195aca*/1)/*@>196dbd*/ * /*@>195be8*/480/*@>19075c*/ + /*@>195ac5*/itmp;
                /*@>1bd739*/tmp/*@>1bd73b*/ = /*@>1deb30*/rtDW./*@>1e7902*/inputImage/*@>1da6ad*/[/*@>1da6a9*/p2/*@>1da6a7*/ - /*@>1da6aa*/1];
                /*@>1bd759*/p3/*@>1bd75b*/ = /*@>195be9*/480/*@>196dc0*/ * /*@>195ad0*/p3/*@>19075e*/ + /*@>195acd*/itmp;
                /*@>1bd745*/tmp_0/*@>1bd747*/ = /*@>1deb42*/rtDW./*@>1e790b*/inputImage/*@>1da6bb*/[/*@>1da6b7*/p3/*@>1da6b5*/ - /*@>1da6b8*/1];
                /*@>1a77cb*/if (/*@>1bd73d*/tmp/*@>13f70c*/ == /*@>1bd749*/tmp_0) {
                    /*@>1a77cf*/qx1/*@>1a77ce*/ = tmp;
                } else {
                    /*@>195bfa*/qx1/*@>18fd96*/ = static_cast<float>(/*@>195934*/1.0/*@>142f8d*/ - /*@>1deb4e*/rtDW./*@>1e7911*/absx11)/*@>196dae*/ * static_cast<float>(tmp)/*@>13f70d*/ + static_cast<float>(tmp_0)/*@>196db5*/ * static_cast<float>(/*@>1deb54*/rtDW./*@>1e7914*/absx11);
                }
                /*@>1bd763*/tmp/*@>1bd765*/ = /*@>1deb72*/rtDW./*@>1e7923*/inputImage/*@>1da6c1*/[p2];
                /*@>1bd76f*/tmp_0/*@>1bd771*/ = /*@>1deb78*/rtDW./*@>1e7926*/inputImage/*@>1da6c7*/[p3];
                /*@>1a77d0*/if (/*@>1bd767*/tmp/*@>13f70e*/ == /*@>1bd773*/tmp_0) {
                    /*@>1a77d4*/qx2/*@>1a77d3*/ = tmp;
                } else {
                    /*@>195bfc*/qx2/*@>18fd9b*/ = static_cast<float>(/*@>195937*/1.0/*@>142fa8*/ - /*@>1deb7e*/rtDW./*@>1e7929*/absx11)/*@>196d97*/ * static_cast<float>(tmp)/*@>13f70f*/ + static_cast<float>(tmp_0)/*@>196d9e*/ * static_cast<float>(/*@>1deb84*/rtDW./*@>1e792c*/absx11);
                }
            }
            /*@>13f72a*/if ((/*@>1deb3c*/rtDW./*@>1e7908*/absx21/*@>13f710*/ == /*@>195909*/itmp)/*@>1e5220*/ || (/*@>1958cc*/qx1/*@>13f711*/ == /*@>1958ce*/qx2)) {
                /*@>1ae20e*/qx2/*@>13f6e8*/ = /*@>1958d0*/qx1;
            } else /*@>13f72e*/if (!/*@<1c9fea*/(static_cast<double>(/*@>19593a*/itmp)/*@>142c66*/ + /*@>19590b*/1.0/*@>13f712*/ == /*@>1deb48*/rtDW./*@>1e790e*/absx21)) {
                /*@>1deb5a*/rtDW./*@>1e7917*/absx11/*@>13f6fa*/ = /*@>1deb60*/rtDW./*@>1e791a*/absx21/*@>13f713*/ - static_cast<double>(/*@>19590c*/itmp);
                /*@>1ae20a*/qx2/*@>13f705*/ = static_cast<float>(/*@>19593e*/1.0/*@>142fcc*/ - /*@>1deb66*/rtDW./*@>1e791d*/absx11)/*@>196d8b*/ * /*@>195911*/qx1/*@>13f717*/ + static_cast<float>(/*@>1deb6c*/rtDW./*@>1e7920*/absx11)/*@>196d8f*/ * /*@>195915*/qx2;
            }
        } else {
            /*@>1e707f*/qx2/*@>1e707e*/ = /*@>1e7080*/0.0F;
        }
    } else {
        /*@>1ae208*/qx2/*@>13f603*/ = /*@>1958b5*/0.0F;
    }
    /*@>1d349c*/Jout/*@>17f91f*/[/*@>195a80*/p1]/*@>17f920*/ = (/*@>1ae210*/qx2/*@>17f90a*/ > /*@>195957*/0.5F);
}


        }

                





                        


        // Function for MATLAB Function: '<S2>/MATLAB Function1'

                
                void Rpi_cam::eml_find(const bool x[307200], int32_t i_data[], int32_t *i_size, int32_t j_data[], int32_t *j_size)
        {
            int32_t idx;
int32_t ii;
int32_t jj;
bool exitg1;
/*@>195ca2*/idx/*@>232f2*/ = /*@>1e7959*/0;
/*@>195ca9*/ii/*@>232f1*/ = /*@>1e795c*/1;
/*@>195cac*/jj/*@>232f0*/ = /*@>1e795f*/1;
exitg1 = false;
while/*@<23301*/ ((!exitg1) && (/*@>195caf*/jj/*@>232c9*/ <= /*@>195cb1*/640)) {
    bool guard1;
    guard1 = false;
    /*@>23302*/if (/*@>1da6d5*/x/*@>1da6d7*/[((/*@>1da6ce*/jj/*@>1da6cc*/ - /*@>1da6cf*/1)/*@>1da6cb*/ * /*@>1da6d0*/480/*@>1da6ca*/ + /*@>1da6d2*/ii)/*@>1da6c9*/ - /*@>1da6d3*/1]) {
        /*@>195cb5*/idx/*@>1e79aa*/++;
        /*@>1d34ae*/i_data/*@>232e7*/[/*@>195cbc*/idx/*@>232bb*/ - /*@>195cbe*/1]/*@>232e5*/ = /*@>195cbf*/ii;
        /*@>1d34b1*/j_data/*@>232e3*/[/*@>195cc4*/idx/*@>232b1*/ - /*@>195cc6*/1]/*@>232e1*/ = /*@>195cc7*/jj;
        /*@>23307*/if (/*@>195cd1*/idx/*@>232c3*/ >= /*@>195cd3*/307200) {
            exitg1 = true;
        } else {
            guard1 = true;
        }
    } else {
        guard1 = true;
    }
    if (guard1) {
        /*@>195cba*/ii/*@>1e79ab*/++;
        /*@>2330a*/if (/*@>195cc1*/ii/*@>232c1*/ > /*@>195cc3*/480) {
            /*@>195cc9*/ii/*@>232d5*/ = /*@>1e7968*/1;
            /*@>195ccf*/jj/*@>1e79ac*/++;
        }
    }
}
/*@>18fda8*/if (/*@>195cd6*/idx/*@>168ebe*/ < /*@>195cd8*/1) {
    *i_size/*@>18fdab*/ = /*@>1e7962*/0;
    *j_size/*@>18fdb3*/ = /*@>1e7965*/0;
} else {
    *i_size/*@>254af*/ = /*@>195cda*/idx;
    *j_size/*@>254c5*/ = /*@>195cdd*/idx;
}


        }

                





                        


         

                
                void Rpi_cam::and_o(bool in1_data[], int32_t *in1_size, const bool in2_data[], const int32_t *in2_size, const bool in3_data[], const int32_t *in3_size)
        {
            int32_t loop_ub;
int32_t stride_0_0;
int32_t stride_1_0;
/* {S!d340}MATLAB Function: '<S2>/MATLAB Function1' */
/*@>1c4239*/loop_ub/*@>1c423b*/ = *in3_size/*@>181571*/ == /*@>196931*/1/*@>181571*/ ? *in2_size : *in3_size;
*in1_size/*@>181591*/ = /*@>1c423d*/loop_ub;
/*@>196951*/stride_0_0/*@>1815e5*/ = (*in2_size/*@>18aacf*/ != /*@>19696b*/1);
/*@>196953*/stride_1_0/*@>1815f1*/ = (*in3_size/*@>18aaef*/ != /*@>19696f*/1);
/*@>1815ce*/for ( int32_t /*@>1e7a2c*/i{/*@>1e7a2b*/0}; /*@>1e7a39*/i < loop_ub; /*@>1e7a32*/i/*@>1e7a3c*/++) {
    /*@>1cdbfe*/in1_data/*@>1815ab*/[/*@>19693f*/i]/*@>1815ac*/ = (/*@>1da9c1*/in2_data/*@>1da9c3*/[/*@>1da9bd*/i * /*@>1da9bf*/stride_0_0]/*@>181596*/ && /*@>1da9cb*/in3_data/*@>1da9cd*/[/*@>1da9c7*/i * /*@>1da9c9*/stride_1_0]);
}
/* {E!d340}End of MATLAB Function: '<S2>/MATLAB Function1' */


        }

                





                        


         

                
                void Rpi_cam::binary_expand_op_3(bool in1_data[], int32_t *in1_size, const bool in2_data[], const int32_t *in2_size, const int32_t in3_data[], const int32_t *in3_size)
        {
            int32_t loop_ub;
int32_t stride_0_0;
int32_t stride_1_0_tmp;
/* {S!d348}MATLAB Function: '<S2>/MATLAB Function1' */
/*@>1c4ef4*/loop_ub/*@>1c4ef6*/ = *in3_size/*@>181ad1*/ == /*@>196af8*/1/*@>181ad1*/ ? *in3_size/*@>181ada*/ == /*@>196afc*/1/*@>181ada*/ ? *in2_size : *in3_size : *in3_size;
*in1_size/*@>181b00*/ = /*@>1c4ef8*/loop_ub;
/*@>196b28*/stride_0_0/*@>181b6f*/ = (*in2_size/*@>18aca4*/ != /*@>196b4b*/1);
stride_1_0_tmp = (*in3_size/*@>18acc4*/ != /*@>196b4f*/1);
/*@>181b57*/for ( int32_t /*@>1e7aaa*/i{/*@>1e7aa9*/0}; /*@>1e7ab7*/i < loop_ub; /*@>1e7ab0*/i/*@>1e7aba*/++) {
    int32_t tmp;
    /*@>1c4efe*/tmp/*@>1c4f00*/ = /*@>1daa1f*/in3_data/*@>1daa21*/[/*@>1daa1b*/i * stride_1_0_tmp];
    /*@>1cddfc*/in1_data/*@>181b25*/[/*@>196b0f*/i]/*@>181b26*/ = (/*@>1daa29*/in2_data/*@>1daa2b*/[/*@>1daa25*/i * /*@>1daa27*/stride_0_0]/*@>181b07*/ && (/*@>1c4f02*/tmp/*@>181b0f*/ >= /*@>196af3*/0)/*@>181b06*/ && (tmp/*@>181b17*/ < /*@>196af4*/160));
}
/* {E!d348}End of MATLAB Function: '<S2>/MATLAB Function1' */


        }

                





                        


        // Function for MATLAB Function: '<S2>/MATLAB Function1'

                
                double Rpi_cam::mean(const double x_data[], const int32_t *x_size)
        {
            double b_y;
/*@>23572*/if (*x_size/*@>2356e*/ == /*@>195d65*/0) {
    /*@>195d63*/b_y/*@>23567*/ = /*@>195d62*/0.0;
} else {
    int32_t firstBlockLength;
    int32_t lastBlockLength;
    int32_t nblocks;
    int32_t xblockoffset;
    /*@>235f9*/if (*x_size/*@>235e6*/ <= /*@>195d61*/1024) {
        /*@>195d5c*/firstBlockLength/*@>235b5*/ = *x_size;
        /*@>195d5a*/lastBlockLength/*@>235b6*/ = /*@>1e7b3c*/0;
        /*@>195d52*/nblocks/*@>235b7*/ = /*@>1e7b3f*/1;
    } else {
        /*@>195d5f*/firstBlockLength/*@>235b8*/ = /*@>1e7b39*/1024;
        /*@>195d11*/nblocks/*@>2367c*/ = static_cast<int32_t>(static_cast<uint32_t>(*x_size)/*@>19ab71*/ >> /*@>196ded*/10);
        /*@>195d54*/lastBlockLength/*@>235bc*/ = *x_size/*@>235e8*/ - (/*@>195d57*/nblocks/*@>196de6*/ << /*@>196de5*/10);
        /*@>235ff*/if (/*@>195d4f*/lastBlockLength/*@>235e9*/ > /*@>195d4e*/0) {
            /*@>195d46*/nblocks/*@>1e7b85*/++;
        } else {
            /*@>195d4c*/lastBlockLength/*@>235c0*/ = /*@>1e7b42*/1024;
        }
    }
    /*@>195d44*/b_y/*@>235c3*/ = /*@>1da6db*/x_data/*@>1da6dd*/[/*@>1da6d9*/0];
/*@>23605*/    for (/*@>1e7b6f*/xblockoffset = /*@>1e7b6e*/2; /*@>1e7b7a*/xblockoffset <= /*@>1e7b78*/firstBlockLength; /*@>1e7b75*/xblockoffset/*@>1e7b7d*/++) {
        /*@>195d2e*/b_y/*@>1e7b7e*/ += /*@>1da6e4*/x_data/*@>1da6e6*/[/*@>1da6e1*/xblockoffset/*@>1da6df*/ - /*@>1da6e2*/1];
    }
/*@>2360a*/    for (/*@>1e7b4f*/firstBlockLength = /*@>1e7b4e*/2; /*@>1e7b5a*/firstBlockLength <= /*@>1e7b58*/nblocks; /*@>1e7b55*/firstBlockLength/*@>1e7b7f*/++) {
        double bsum;
        int32_t hi;
        /*@>195d32*/xblockoffset/*@>235ce*/ = (/*@>195d36*/firstBlockLength/*@>235ef*/ - /*@>195d35*/1)/*@>196dfa*/ << /*@>196df9*/10;
        /*@>195d2c*/bsum/*@>235d4*/ = /*@>1da6eb*/x_data/*@>1da6ed*/[/*@>1da6e9*/xblockoffset];
        /*@>1a77e1*/if (/*@>195d2a*/firstBlockLength/*@>235f3*/ == /*@>195d28*/nblocks) {
            /*@>1a77e5*/hi/*@>1a77e4*/ = /*@>195d25*/lastBlockLength;
        } else {
            /*@>195d90*/hi/*@>18fdbc*/ = /*@>1e7b45*/1024;
        }
/*@>23613*/        for ( int32_t /*@>1e7b5f*/b_k{/*@>1e7b5e*/2}; /*@>1e7b6a*/b_k <= /*@>1e7b68*/hi; /*@>1e7b65*/b_k/*@>1e7b80*/++) {
            /*@>195d13*/bsum/*@>1e7b81*/ += /*@>1da6f7*/x_data/*@>1da6f9*/[(/*@>1da6f2*/xblockoffset/*@>1da6f0*/ + /*@>1da6f4*/b_k)/*@>1da6ef*/ - /*@>1da6f5*/1];
        }
        /*@>195d17*/b_y/*@>1e7b82*/ += /*@>195d19*/bsum;
    }
}
return /*@>195d66*/b_y/*@>1680d*/ / static_cast<double>(*x_size);


        }

                





                        


        // Function for MATLAB Function: '<S2>/MATLAB Function1'

                
                double Rpi_cam::maximum(const double x_data[], const int32_t *x_size)
        {
            double ex;
int32_t last;
/*@>195da9*/last/*@>2343a*/ = *x_size;
/*@>2343e*/if (*x_size/*@>2341c*/ <= /*@>195dab*/2) {
    /*@>2343f*/if (*x_size/*@>2341b*/ == /*@>195dac*/1) {
        /*@>195dad*/ex/*@>23433*/ = /*@>1da70d*/x_data/*@>1da70f*/[/*@>1da70b*/0];
    } else {
        /*@>1be1f3*/ex/*@>1be1f5*/ = /*@>1da707*/x_data/*@>1da709*/[*x_size/*@>1da701*/ - /*@>1da705*/1];
        /*@>1a77e7*/if (!/*@<1c9ff1*/(/*@>1da713*/x_data/*@>1da715*/[/*@>1da711*/0]/*@>23419*/ < /*@>1be1f7*/ex)) {
            /*@>195de9*/ex/*@>18fdc2*/ = /*@>1da722*/x_data/*@>1da724*/[/*@>1da720*/0];
        }
    }
} else {
    /*@>195db1*/ex/*@>234cb*/ = /*@>1da6fd*/x_data/*@>1da6ff*/[/*@>1da6fb*/0];
/*@>234db*/    for ( int32_t /*@>1e7c4b*/k{/*@>1e7c4a*/2}; /*@>1e7c56*/k <= /*@>1e7c54*/last; /*@>1e7c51*/k/*@>1e7c58*/++) {
        double x;
        /*@>195dde*/x/*@>189086*/ = /*@>1da71c*/x_data/*@>1da71e*/[/*@>1da719*/k/*@>1da717*/ - /*@>1da71a*/1];
        /*@>234dd*/if (/*@>195db7*/ex/*@>234d6*/ < /*@>195de5*/x) {
            /*@>195db9*/ex/*@>234d3*/ = /*@>195de7*/x;
        }
    }
}
return ex;


        }

                





                        


         

                
                void Rpi_cam::binary_expand_op_2(bool in1_data[], int32_t *in1_size, const bool in2_data[], const int32_t *in2_size, const bool in3_data[], const bool in4_data[], const int32_t *in4_size, const bool in5_data[], const int32_t *in5_size)
        {
            int32_t loop_ub;
int32_t stride_0_0;
int32_t stride_1_0;
int32_t stride_2_0;
/* {S!d346}MATLAB Function: '<S2>/MATLAB Function1' */
/*@>1c4bb6*/loop_ub/*@>1c4bb8*/ = *in5_size/*@>18194d*/ == /*@>196a6a*/1/*@>18194d*/ ? *in4_size/*@>181956*/ == /*@>196a6e*/1/*@>181956*/ ? *in2_size : *in4_size : *in5_size;
*in1_size/*@>18197c*/ = /*@>1c4bba*/loop_ub;
/*@>196a9c*/stride_0_0/*@>1819f1*/ = (*in2_size/*@>18ac24*/ != /*@>196ac3*/1);
/*@>196a9e*/stride_1_0/*@>1819fd*/ = (*in4_size/*@>18ac44*/ != /*@>196ac7*/1);
/*@>196aa0*/stride_2_0/*@>181a09*/ = (*in5_size/*@>18ac64*/ != /*@>196acb*/1);
/*@>1819d9*/for ( int32_t /*@>1e7cd6*/i{/*@>1e7cd5*/0}; /*@>1e7ce3*/i < loop_ub; /*@>1e7cdc*/i/*@>1e7ce6*/++) {
    int32_t tmp;
    tmp = /*@>196ab3*/i * /*@>196ab5*/stride_0_0;
    /*@>1cdd6f*/in1_data/*@>1819a7*/[/*@>196a83*/i]/*@>1819a8*/ = (/*@>1da9fa*/in2_data/*@>1da9fc*/[tmp]/*@>181984*/ && /*@>1daa01*/in3_data/*@>1daa03*/[tmp]/*@>181983*/ && /*@>1daa0b*/in4_data/*@>1daa0d*/[/*@>1daa07*/i * /*@>1daa09*/stride_1_0]/*@>181982*/ && /*@>1daa15*/in5_data/*@>1daa17*/[/*@>1daa11*/i * /*@>1daa13*/stride_2_0]);
}
/* {E!d346}End of MATLAB Function: '<S2>/MATLAB Function1' */


        }

                





                        


         

                
                void Rpi_cam::binary_expand_op(bool in1_data[], int32_t *in1_size, const int32_t in2_data[], const int32_t *in2_size, double in3, double in4, const int32_t in5_data[], const int32_t *in5_size, double in6)
        {
            int32_t loop_ub;
int32_t stride_0_0;
int32_t stride_1_0;
/* {S!d342}MATLAB Function: '<S2>/MATLAB Function1' */
/*@>1c4529*/loop_ub/*@>1c452b*/ = *in5_size/*@>1816a2*/ == /*@>196998*/1/*@>1816a2*/ ? *in2_size : *in5_size;
*in1_size/*@>1816c2*/ = /*@>1c452d*/loop_ub;
/*@>1969ba*/stride_0_0/*@>18172d*/ = (*in2_size/*@>18ab1f*/ != /*@>1969d8*/1);
/*@>1969bc*/stride_1_0/*@>181739*/ = (*in5_size/*@>18ab3f*/ != /*@>1969dc*/1);
/*@>181716*/for ( int32_t /*@>1e7d81*/i{/*@>1e7d80*/0}; /*@>1e7d8e*/i < loop_ub; /*@>1e7d87*/i/*@>1e7d91*/++) {
    double tmp;
    /*@>1c4533*/tmp/*@>1c4535*/ = /*@>1da9d5*/in2_data/*@>1da9d7*/[/*@>1da9d1*/i * /*@>1da9d3*/stride_0_0];
    /*@>1cdc73*/in1_data/*@>1816f3*/[/*@>1969a8*/i]/*@>1816f4*/ = ((/*@>1c4537*/tmp/*@>1816c9*/ >= /*@>19698b*/in3)/*@>1816c8*/ && (tmp/*@>1816d5*/ < /*@>19698d*/in4)/*@>1816c7*/ && (/*@>1da9df*/in5_data/*@>1da9e1*/[/*@>1da9db*/i * /*@>1da9dd*/stride_1_0]/*@>1816e1*/ >= /*@>1a6229*/in6/*@>1a6227*/ - /*@>1a622a*/40.0));
}
/* {E!d342}End of MATLAB Function: '<S2>/MATLAB Function1' */


        }

                





                        


         

                
                void Rpi_cam::binary_expand_op_1(bool in1_data[], int32_t *in1_size, const double in2_data[], const int32_t *in2_size, double in3, double in4, const double in5_data[], const int32_t *in5_size, double in6)
        {
            int32_t loop_ub;
int32_t stride_0_0;
int32_t stride_1_0;
/* {S!d344}MATLAB Function: '<S2>/MATLAB Function1' */
/*@>1c4820*/loop_ub/*@>1c4822*/ = *in5_size/*@>1817ea*/ == /*@>196a06*/1/*@>1817ea*/ ? *in2_size : *in5_size;
*in1_size/*@>18180a*/ = /*@>1c4824*/loop_ub;
/*@>196a28*/stride_0_0/*@>181869*/ = (*in2_size/*@>18ab9f*/ != /*@>196a46*/1);
/*@>196a2a*/stride_1_0/*@>181875*/ = (*in5_size/*@>18abbf*/ != /*@>196a4a*/1);
/*@>181852*/for ( int32_t /*@>1e7e0f*/i{/*@>1e7e0e*/0}; /*@>1e7e1c*/i < loop_ub; /*@>1e7e15*/i/*@>1e7e1f*/++) {
    double tmp;
    /*@>1c482a*/tmp/*@>1c482c*/ = /*@>1da9e9*/in2_data/*@>1da9eb*/[/*@>1da9e5*/i * /*@>1da9e7*/stride_0_0];
    /*@>1cdce7*/in1_data/*@>18182f*/[/*@>196a16*/i]/*@>181830*/ = ((/*@>1c482e*/tmp/*@>181811*/ >= /*@>1969f9*/in3)/*@>181810*/ && (tmp/*@>181819*/ < /*@>1969fb*/in4)/*@>18180f*/ && (/*@>1da9f3*/in5_data/*@>1da9f5*/[/*@>1da9ef*/i * /*@>1da9f1*/stride_1_0]/*@>181821*/ >= /*@>1a6253*/in6/*@>1a6251*/ - /*@>1a6254*/40.0));
}
/* {E!d344}End of MATLAB Function: '<S2>/MATLAB Function1' */


        }

                





                        


         

                
                codertarget_raspi_internal_Raspiv4l2Capture *Rpi_cam::Raspiv4l2Capture_Raspiv4l2Capture(codertarget_raspi_internal_Raspiv4l2Capture *obj)
        {
            codertarget_raspi_internal_Raspiv4l2Capture *b_obj;
/* Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>195e1f*/obj->/*@>1e7ee1*/BrightnessInternal/*@>156ff4*/ = /*@>195e0a*/0.5;
/*@>195e21*/obj->/*@>1e7ee4*/SaturationInternal/*@>156ffa*/ = /*@>195e0c*/0.5;
/*@>195e23*/obj->/*@>1e7ee7*/ContrastInternal/*@>157000*/ = /*@>195e0e*/0.5;
/*@>195e25*/obj->/*@>1e7eea*/SharpnessInternal/*@>157006*/ = /*@>195e10*/0.5;
/*@>195e27*/obj->/*@>1e7eed*/CameraZoomInternal/*@>15700c*/ = /*@>195e12*/0.5;
/*@>195e29*/obj->/*@>1e7ef0*/ManualFocusInternal/*@>157012*/ = /*@>195e14*/0.5;
/*@>195e2b*/obj->/*@>1e7ef3*/CameraPanInternal/*@>157018*/ = /*@>195e16*/0.0;
/*@>195e2d*/obj->/*@>1e7ef6*/CameraTiltInternal/*@>15701e*/ = /*@>195e18*/0.0;
/*@>195e2f*/obj->/*@>1e7ef9*/EnableManualFocusInternal/*@>157024*/ = /*@>195e1a*/true;
/*@>195e31*/obj->/*@>1e7efc*/isInitialized/*@>1570d2*/ = /*@>1e7e98*/0;
/*@>195e1c*/b_obj/*@>15707f*/ = /*@>195e33*/obj;
/*@>195e35*/obj->matlabCodegenIsDeleted = false;
return b_obj;


        }

                





                        


         

                
                void Rpi_cam::SystemCore_setup(codertarget_raspi_internal_Raspiv4l2Capture *obj)
        {
            int32_t i;
int8_t resolutionStatus;
uint8_t camIndex;
static const std::array<char, 12> devName{ { '/', 'd', 'e', 'v', '/', 'v', 'i', 'd', 'e', 'o', '0', '\x00' } };
static const std::array<char, 101> b_errorMessage{ { 'W', 'e', 'b', 'c', 'a', 'm', ' ', 'c', 'a', 'n', 'n', 'o', 't', ' ', 'b', 'e', ' ', 'i', 'n', 'i', 't', 'i', 'a', 'l', 'i', 'z', 'e', 'd', ' ', 'p', 'r', 'o', 'p', 'e', 'r', 'l', 'y', '.', ' ', 'P', 'l', 'e', 'a', 's', 'e', ' ', 'c', 'h', 'e', 'c', 'k', ' ', 'i', 'f', ' ', 't', 'h', 'e', ' ', 'd', 'e', 'v', 'i', 'c', 'e', ' ', 's', 'u', 'p', 'p', 'o', 'r', 't', 's', ' ', 't', 'h', 'e', ' ', 's', 'p', 'e', 'c', 'i', 'f', 'i', 'e', 'd', ' ', 'r', 'e', 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', '.', '\x00' } };



/*@>195e46*/obj->/*@>1e7f9d*/isSetupComplete/*@>1247ff*/ = /*@>195e4f*/false;
/* {S!d310}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>195e49*/obj->/*@>1e7fa0*/isInitialized/*@>124826*/ = /*@>1e7f29*/1;
/*@>1d35a0*/getCameraList();
/*@>18045d*/for (/*@>1e7f31*/i = /*@>1e7f30*/0; /*@>1e7f3b*/i < /*@>1e7f39*/12; /*@>1e7f37*/i/*@>1e7f3f*/++) {
    /*@>1deb96*/rtDW./*@>1e7fa9*/devName/*@>18f25e*/[/*@>195e7f*/i]/*@>180450*/ = /*@>1da728*/devName/*@>1da72a*/[/*@>1da727*/i];
}
/* {S!d312}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>195e51*/camIndex/*@>15722d*/ = /*@>1d35a2*/getCameraAddrIndex(&/*@>1deb90*/rtDW./*@>1e7fa6*/devName/*@>18f26f*/[/*@>195e97*/0], /*@>195e6b*/11U);
/*@>195e55*/resolutionStatus/*@>157237*/ = /*@>1d35a4*/validateResolution(/*@>195e57*/camIndex, /*@>1b0a3e*/640, /*@>1b0a41*/480);
/*@>1572a0*/if (/*@>195e59*/resolutionStatus/*@>15726b*/ >= /*@>195e5b*/0) {
    /* {S!d314}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
    /*@>1d35ac*/EXT_webcamInit(/*@>1b0a47*/0, /*@>1b0a4a*/0, /*@>195e6f*/0, /*@>195e70*/0, /*@>195e71*/0, /*@>195e72*/0, /*@>195e73*/640U, /*@>195e74*/480U, /*@>195e75*/2U, /*@>195e76*/2U, /*@>195e77*/1U, /*@>195e60*/0.1);
} else {
    /* {S!d316}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
    /*@>1d483d*/std::memcpy(&/*@>1deba2*/rtDW./*@>1e7fac*/b_errorMessage/*@>1d0e37*/[/*@>1d0e26*/0], &/*@>1d0e3e*/b_errorMessage/*@>1d0e3f*/[/*@>1d0e33*/0], /*@>1d0e35*/101U/*@>1d0e42*/ * /*@>1d0e41*/sizeof(char));
    /*@>1d35a8*/std::perror(&/*@>1deba8*/rtDW./*@>1e7faf*/b_errorMessage/*@>18f28d*/[/*@>195e98*/0]);
    /* {S!d318}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
    /*@>1d35aa*/std::exit(/*@>195e78*/0);
}
/* {S!d320}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@[1e586a*/v4l2Capture_updateV4L2Settings(/*@>1e7fde*/obj, /*@>1e7fec*/true)/*@]*/;
/*@>195e4c*/obj->/*@>1e7fa3*/isSetupComplete/*@>1248a6*/ = /*@>195e50*/true;


        }

                



                        




        // Model step function
        
                    
        void Rpi_cam::step() 
        {
            


        

                
        
            
uint8_t xtmp;
static const std::array<int16_t, 8> tmp{ { 145, 500, 27, 639, 300, 300, 415, 415 } };
static const std::array<int16_t, 8> tmp_0{ { 40, 600, 40, 600, 300, 300, 480, 480 } };

            
            



        

        




                
        




                                                    
                                    /* {S!d238}MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>15fbb8*/if (/*@>1dce92*/rtDW./*@>1e9c7c*/obj.Brightness/*@>15fb76*/ != /*@>19546b*/0.5) {
    /*@>1dce98*/rtDW./*@>1e9c7f*/obj./*@>1e9c64*/Brightness/*@>15fbaf*/ = /*@>19546c*/0.5;
}
/*@>15fbbb*/if (/*@>1dce9e*/rtDW./*@>1e9c82*/obj.Saturation/*@>15fb75*/ != /*@>19546d*/0.5) {
    /*@>1dcea4*/rtDW./*@>1e9c85*/obj./*@>1e9c67*/Saturation/*@>15fba7*/ = /*@>19546e*/0.5;
}
/*@>15fbbe*/if (/*@>1dceaa*/rtDW./*@>1e9c88*/obj.Contrast/*@>15fb74*/ != /*@>19546f*/0.5) {
    /*@>1dceb0*/rtDW./*@>1e9c8b*/obj./*@>1e9c6a*/Contrast/*@>15fb9f*/ = /*@>195470*/0.5;
}
/*@>15fbc1*/if (/*@>1dceb6*/rtDW./*@>1e9c8e*/obj.Sharpness/*@>15fb73*/ != /*@>195471*/0.5) {
    /*@>1dcebc*/rtDW./*@>1e9c91*/obj./*@>1e9c6d*/Sharpness/*@>15fb97*/ = /*@>195472*/0.5;
}
/*@>15fbc4*/if (/*@>1dcec2*/rtDW./*@>1e9c94*/obj.CameraPan/*@>15fb72*/ != /*@>195473*/0.0) {
    /*@>1dcec8*/rtDW./*@>1e9c97*/obj./*@>1e9c70*/CameraPan/*@>15fb8f*/ = /*@>195474*/0.0;
}
/*@>15fbc7*/if (/*@>1dcece*/rtDW./*@>1e9c9a*/obj.CameraTilt/*@>15fb71*/ != /*@>195475*/0.0) {
    /*@>1dced4*/rtDW./*@>1e9c9d*/obj./*@>1e9c73*/CameraTilt/*@>15fb87*/ = /*@>195476*/0.0;
}
/*@>15fbca*/if (/*@>1dceda*/rtDW./*@>1e9ca0*/obj.CameraZoom/*@>15fb70*/ != /*@>195477*/0.5) {
    /*@>1dcee0*/rtDW./*@>1e9ca3*/obj./*@>1e9c76*/CameraZoom/*@>15fb7f*/ = /*@>195478*/0.5;
}
/*@>15fbcd*/if (/*@>1dcee6*/rtDW./*@>1e9ca6*/obj.ManualFocus/*@>15fb6f*/ != /*@>195479*/0.5) {
    /*@>1dceec*/rtDW./*@>1e9ca9*/obj./*@>1e9c79*/ManualFocus/*@>15fb77*/ = /*@>19547a*/0.5;
}
/*@[1e5884*/SystemCore_step(&/*@>1eaa27*/rtDW./*@>1eaa26*/obj, &/*@>1eaa39*/rtDW./*@>1eaa38*/uv[0], &/*@>1eaa4c*/rtDW./*@>1eaa4b*/uv1[0], &/*@>1eaa5f*/rtDW./*@>1eaa5e*/uv2[0])/*@]*/;
/* {S!d240}Math: '<S3>/Transpose' incorporates:
 *  MATLABSystem: '<Root>/V4L2 Video Capture'
 */
/*@>17b9d6*/for (/*@>1e87e6*/rtDW./*@>1ea9b4*/i = /*@>1e87e4*/0; /*@>1e87f6*/rtDW./*@>1ea9ba*/i < /*@>1e87f3*/640; /*@>1e87f0*/rtDW./*@>1ea9b7*/i/*@>1e8816*/++) {
/*@>17b9c6*/    for (/*@>1e8801*/rtDW./*@>1ea9bd*/inlierNum = /*@>1e87ff*/0; /*@>1e8811*/rtDW./*@>1ea9c3*/inlierNum < /*@>1e880e*/480; /*@>1e880b*/rtDW./*@>1ea9c0*/inlierNum/*@>1e8817*/++) {
        /*@>1dcf46*/rtDW./*@>1e9cbe*/uv3/*@>18e8ed*/[/*@>1dcf4c*/rtDW./*@>1e9cc1*/inlierNum/*@>18e8e9*/ + /*@>195556*/480/*@>196ba8*/ * /*@>1dcf52*/rtDW./*@>1e9cc4*/i]/*@>17b9b9*/ = /*@>1dcf58*/rtDW./*@>1e9cc7*/uv/*@>1da179*/[/*@>1da172*/640/*@>1da171*/ * /*@>1dcf5e*/rtDW./*@>1e9cca*/inlierNum/*@>1da170*/ + /*@>1dcf64*/rtDW./*@>1e9ccd*/i];
    }
}
/*@>1d482a*/std::memcpy(&/*@>1dcf28*/rtDW./*@>1e9cb2*/outputImage/*@>1d030c*/[/*@>1d02fa*/0], &/*@>1dcf2e*/rtDW./*@>1e9cb5*/uv3/*@>1d0314*/[/*@>1d0307*/0], /*@>1d030a*/307200U/*@>1d0317*/ * /*@>1d0316*/sizeof(uint8_t));
/* {E!d240}End of Math: '<S3>/Transpose' */

/* {S!d242}Math: '<S3>/Transpose1' incorporates:
 *  MATLABSystem: '<Root>/V4L2 Video Capture'
 */
/*@>17baac*/for (/*@>1e87b0*/rtDW./*@>1ea9a2*/i = /*@>1e87ae*/0; /*@>1e87c0*/rtDW./*@>1ea9a8*/i < /*@>1e87bd*/640; /*@>1e87ba*/rtDW./*@>1ea9a5*/i/*@>1e8818*/++) {
/*@>17ba9c*/    for (/*@>1e87cb*/rtDW./*@>1ea9ab*/inlierNum = /*@>1e87c9*/0; /*@>1e87db*/rtDW./*@>1ea9b1*/inlierNum < /*@>1e87d8*/480; /*@>1e87d5*/rtDW./*@>1ea9ae*/inlierNum/*@>1e8819*/++) {
        /*@>1dcf88*/rtDW./*@>1e9cdc*/uv/*@>18e90f*/[/*@>1dcf8e*/rtDW./*@>1e9cdf*/inlierNum/*@>18e90b*/ + /*@>195558*/480/*@>196bae*/ * /*@>1dcf94*/rtDW./*@>1e9ce2*/i]/*@>17ba8f*/ = /*@>1dcf9a*/rtDW./*@>1e9ce5*/uv1/*@>1da184*/[/*@>1da17d*/640/*@>1da17c*/ * /*@>1dcfa0*/rtDW./*@>1e9ce8*/inlierNum/*@>1da17b*/ + /*@>1dcfa6*/rtDW./*@>1e9ceb*/i];
    }
}
/*@>1d482c*/std::memcpy(&/*@>1dcf6a*/rtDW./*@>1e9cd0*/outputImage/*@>1d029f*/[/*@>1d028d*/307200], &/*@>1dcf70*/rtDW./*@>1e9cd3*/uv/*@>1d02a7*/[/*@>1d029a*/0], /*@>1d029d*/307200U/*@>1d02aa*/ * /*@>1d02a9*/sizeof(uint8_t));
/* {E!d242}End of Math: '<S3>/Transpose1' */

/* {S!d244}Math: '<S3>/Transpose2' incorporates:
 *  MATLABSystem: '<Root>/V4L2 Video Capture'
 */
/*@>17bb86*/for (/*@>1e877a*/rtDW./*@>1ea990*/i = /*@>1e8778*/0; /*@>1e878a*/rtDW./*@>1ea996*/i < /*@>1e8787*/640; /*@>1e8784*/rtDW./*@>1ea993*/i/*@>1e881a*/++) {
/*@>17bb76*/    for (/*@>1e8795*/rtDW./*@>1ea999*/inlierNum = /*@>1e8793*/0; /*@>1e87a5*/rtDW./*@>1ea99f*/inlierNum < /*@>1e87a2*/480; /*@>1e879f*/rtDW./*@>1ea99c*/inlierNum/*@>1e881b*/++) {
        /*@>1dcfc4*/rtDW./*@>1e9cfa*/uv/*@>18e92e*/[/*@>1dcfca*/rtDW./*@>1e9cfd*/inlierNum/*@>18e92a*/ + /*@>19555a*/480/*@>196bb4*/ * /*@>1dcfd0*/rtDW./*@>1e9d00*/i]/*@>17bb69*/ = /*@>1dcfd6*/rtDW./*@>1e9d03*/uv2/*@>1da18f*/[/*@>1da188*/640/*@>1da187*/ * /*@>1dcfdc*/rtDW./*@>1e9d06*/inlierNum/*@>1da186*/ + /*@>1dcfe2*/rtDW./*@>1e9d09*/i];
    }
}
/*@>1d482e*/std::memcpy(&/*@>1dcfac*/rtDW./*@>1e9cee*/outputImage/*@>1d0232*/[/*@>1d0220*/614400], &/*@>1dcfb2*/rtDW./*@>1e9cf1*/uv/*@>1d023a*/[/*@>1d022d*/0], /*@>1d0230*/307200U/*@>1d023d*/ * /*@>1d023c*/sizeof(uint8_t));
/* {E!d244}End of Math: '<S3>/Transpose2' */

/* {S!d246}MATLAB Function: '<Root>/MATLAB Function' */
/*@>15f8ac*/for (/*@>1e8729*/rtDW./*@>1ea975*/inlierNum = /*@>1e8727*/0; /*@>1e8739*/rtDW./*@>1ea97b*/inlierNum < /*@>1e8736*/3; /*@>1e8733*/rtDW./*@>1ea978*/inlierNum/*@>1e881c*/++) {
/*@>15f8ae*/    for (/*@>1e8744*/rtDW./*@>1ea97e*/j = /*@>1e8742*/0; /*@>1e8754*/rtDW./*@>1ea984*/j < /*@>1e8751*/640; /*@>1e874e*/rtDW./*@>1ea981*/j/*@>1e881d*/++) {
/*@>15f8b0*/        for (/*@>1e875f*/rtDW./*@>1ea987*/svdRsltVar = /*@>1e875d*/0; /*@>1e876f*/rtDW./*@>1ea98d*/svdRsltVar < /*@>1e876c*/240; /*@>1e8769*/rtDW./*@>1ea98a*/svdRsltVar/*@>1e881e*/++) {
            /*@>1dd012*/rtDW./*@>1e9d1e*/i/*@>1bbd3a*/ = (/*@>195543*/480/*@>196bcc*/ * /*@>1dd018*/rtDW./*@>1e9d21*/j/*@>18a58e*/ + /*@>1dd01e*/rtDW./*@>1e9d24*/svdRsltVar)/*@>18a593*/ + /*@>195544*/307200/*@>196bcf*/ * /*@>1dd024*/rtDW./*@>1e9d27*/inlierNum;
            /*@>194bcd*/xtmp/*@>15f8a4*/ = /*@>1dd042*/rtDW./*@>1e9d36*/outputImage/*@>1da19b*/[/*@>1dd048*/rtDW./*@>1e9d39*/i];
            /*@>1dd06c*/rtDW./*@>1e9d48*/outputImage_tmp/*@>1bbd44*/ = ((/*@>195547*/480/*@>196bc6*/ * /*@>1dd072*/rtDW./*@>1e9d4b*/j/*@>1904e9*/ - /*@>1dd078*/rtDW./*@>1e9d4e*/svdRsltVar)/*@>1904eb*/ + /*@>195548*/307200/*@>196bc9*/ * /*@>1dd07e*/rtDW./*@>1e9d51*/inlierNum)/*@>1904ec*/ + /*@>194ed9*/479;
            /*@>1dd096*/rtDW./*@>1e9d5d*/outputImage/*@>18a5a7*/[rtDW.i]/*@>15f8a8*/ = /*@>1dd0a2*/rtDW./*@>1e9d63*/outputImage/*@>1da1a7*/[/*@>1dd0a8*/rtDW./*@>1e9d66*/outputImage_tmp];
            /*@>1dd0c6*/rtDW./*@>1e9d75*/outputImage/*@>18a5c6*/[rtDW.outputImage_tmp]/*@>15f8ab*/ = /*@>194bcf*/xtmp;
        }
    }
}
/*@>15f8d4*/for (/*@>1e86d8*/rtDW./*@>1ea95a*/svdRsltVar = /*@>1e86d6*/0; /*@>1e86e8*/rtDW./*@>1ea960*/svdRsltVar < /*@>1e86e5*/3; /*@>1e86e2*/rtDW./*@>1ea95d*/svdRsltVar/*@>1e881f*/++) {
/*@>15f8d6*/    for (/*@>1e86f3*/rtDW./*@>1ea963*/inlierNum = /*@>1e86f1*/0; /*@>1e8703*/rtDW./*@>1ea969*/inlierNum < /*@>1e8700*/320; /*@>1e86fd*/rtDW./*@>1ea966*/inlierNum/*@>1e8820*/++) {
/*@>15f8d8*/        for (/*@>1e870e*/rtDW./*@>1ea96c*/j = /*@>1e870c*/0; /*@>1e871e*/rtDW./*@>1ea972*/j < /*@>1e871b*/480; /*@>1e8718*/rtDW./*@>1ea96f*/j/*@>1e8821*/++) {
            /*@>1dd054*/rtDW./*@>1e9d3c*/i/*@>1bbd4e*/ = (/*@>19554b*/480/*@>196be4*/ * /*@>1dd05a*/rtDW./*@>1e9d3f*/inlierNum/*@>18a5cc*/ + /*@>1dd060*/rtDW./*@>1e9d42*/j)/*@>18a5d1*/ + /*@>19554c*/307200/*@>196be7*/ * /*@>1dd066*/rtDW./*@>1e9d45*/svdRsltVar;
            /*@>194be0*/xtmp/*@>15f8cc*/ = /*@>1dd08a*/rtDW./*@>1e9d57*/outputImage/*@>1da1a1*/[/*@>1dd090*/rtDW./*@>1e9d5a*/i];
            /*@>1dd0ae*/rtDW./*@>1e9d69*/outputImage_tmp/*@>1bbd58*/ = ((/*@>194ef9*/639/*@>17bdda*/ - /*@>1dd0b4*/rtDW./*@>1e9d6c*/inlierNum)/*@>196bde*/ * /*@>19554f*/480/*@>18a5eb*/ + /*@>1dd0ba*/rtDW./*@>1e9d6f*/j)/*@>18a5f0*/ + /*@>195550*/307200/*@>196be1*/ * /*@>1dd0c0*/rtDW./*@>1e9d72*/svdRsltVar;
            /*@>1dd0d8*/rtDW./*@>1e9d7b*/outputImage/*@>18a5e5*/[rtDW.i]/*@>15f8d0*/ = /*@>1dd0e4*/rtDW./*@>1e9d81*/outputImage/*@>1da1ad*/[/*@>1dd0ea*/rtDW./*@>1e9d84*/outputImage_tmp];
            /*@>1dd108*/rtDW./*@>1e9d90*/outputImage/*@>18a604*/[rtDW.outputImage_tmp]/*@>15f8d3*/ = /*@>194be2*/xtmp;
        }
    }
}
/* {E!d246}End of MATLAB Function: '<Root>/MATLAB Function' */

/* {S!d248}S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion' */
/*@>181ef5*/for (/*@>1e86bd*/rtDW./*@>1ea951*/svdRsltVar = /*@>1e86bb*/0; /*@>1e86cd*/rtDW./*@>1ea957*/svdRsltVar < /*@>1e86ca*/921600; /*@>1e86c7*/rtDW./*@>1ea954*/svdRsltVar/*@>1e8822*/++) {
    /*@>1dd02a*/rtDW./*@>1e9d2a*/ImageDataTypeConversion/*@>17bc99*/[/*@>1dd030*/rtDW./*@>1e9d2d*/svdRsltVar]/*@>15d797*/ = static_cast<double>(/*@>1dd036*/rtDW./*@>1e9d30*/outputImage/*@>1da195*/[/*@>1dd03c*/rtDW./*@>1e9d33*/svdRsltVar])/*@>15d794*/ / /*@>194a34*/255.0;
}
/* {E!d248}End of S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion' */
/* temporary variables for in-place operation */
/*@>181ede*/for (/*@>1e86a2*/rtDW./*@>1ea948*/svdRsltVar = /*@>1e86a0*/0; /*@>1e86b2*/rtDW./*@>1ea94e*/svdRsltVar < /*@>1e86af*/307200; /*@>1e86ac*/rtDW./*@>1ea94b*/svdRsltVar/*@>1e8824*/++) {
    /* {S!d250}S-Function (svipcolorconv): '<S4>/Color Space  Conversion' incorporates:
 *  S-Function (svipscalenconvert): '<S4>/Image Data Type Conversion'
 */
    /* First get the min and max of the RGB triplet */
    /*@>1dd0f6*/rtDW./*@>1e9d87*/ImageDataTypeConversion_c/*@>188d7b*/ = /*@>1dd0fc*/rtDW./*@>1e9d8a*/ImageDataTypeConversion/*@>1da1b3*/[/*@>1dd102*/rtDW./*@>1e9d8d*/svdRsltVar];
    /*@>1dd11a*/rtDW./*@>1e9d99*/ImageDataTypeConversion_k/*@>188da1*/ = /*@>1dd120*/rtDW./*@>1e9d9c*/ImageDataTypeConversion/*@>1da1bb*/[/*@>1dd126*/rtDW./*@>1e9d9f*/svdRsltVar/*@>1da1b5*/ + /*@>1da1b8*/307200];
    /*@>15f6a8*/if (/*@>1dd12c*/rtDW./*@>1e9da2*/ImageDataTypeConversion_c/*@>15f6a7*/ > /*@>1dd132*/rtDW./*@>1e9da5*/ImageDataTypeConversion_k) {
        /*@>1dd162*/rtDW./*@>1e9dba*/ImageDataTypeConversion_cx/*@>188dd4*/ = /*@>1dd168*/rtDW./*@>1e9dbd*/ImageDataTypeConversion/*@>1da1d1*/[/*@>1dd16e*/rtDW./*@>1e9dc0*/svdRsltVar/*@>1da1cb*/ + /*@>1da1ce*/614400];
        /*@>1a77a9*/if (/*@>1dd198*/rtDW./*@>1e9dd5*/ImageDataTypeConversion_k/*@>15f6b8*/ < /*@>1dd19e*/rtDW./*@>1e9dd8*/ImageDataTypeConversion_cx) {
            /*@>1dd1ce*/rtDW./*@>1e9df0*/win_y_high/*@>1a77ac*/ = /*@>1dd1d4*/rtDW./*@>1e9df3*/ImageDataTypeConversion_k;
        } else {
            /*@>1dd1c2*/rtDW./*@>1e9dea*/win_y_high/*@>18fd6a*/ = /*@>1dd1c8*/rtDW./*@>1e9ded*/ImageDataTypeConversion_cx;
        }
        /*@>1a77b3*/if (/*@>1dd1f2*/rtDW./*@>1e9e02*/ImageDataTypeConversion_c/*@>15f6d9*/ > /*@>1dd1f8*/rtDW./*@>1e9e05*/ImageDataTypeConversion_cx) {
            /*@>1dd228*/rtDW./*@>1e9e1d*/bestInlierDis/*@>1a77b6*/ = /*@>1dd22e*/rtDW./*@>1e9e20*/ImageDataTypeConversion_c;
        } else {
            /*@>1dd21c*/rtDW./*@>1e9e17*/bestInlierDis/*@>18fd74*/ = /*@>1dd222*/rtDW./*@>1e9e1a*/ImageDataTypeConversion_cx;
        }
    } else {
        /*@>1dd150*/rtDW./*@>1e9db1*/ImageDataTypeConversion_cx/*@>188dc7*/ = /*@>1dd156*/rtDW./*@>1e9db4*/ImageDataTypeConversion/*@>1da1c9*/[/*@>1dd15c*/rtDW./*@>1e9db7*/svdRsltVar/*@>1da1c3*/ + /*@>1da1c6*/614400];
        /*@>1a77a4*/if (/*@>1dd18c*/rtDW./*@>1e9dcf*/ImageDataTypeConversion_c/*@>15f6f7*/ < /*@>1dd192*/rtDW./*@>1e9dd2*/ImageDataTypeConversion_cx) {
            /*@>1dd1b6*/rtDW./*@>1e9de4*/win_y_high/*@>1a77a7*/ = /*@>1dd1bc*/rtDW./*@>1e9de7*/ImageDataTypeConversion_c;
        } else {
            /*@>1dd1aa*/rtDW./*@>1e9dde*/win_y_high/*@>18fd65*/ = /*@>1dd1b0*/rtDW./*@>1e9de1*/ImageDataTypeConversion_cx;
        }
        /*@>1a77ae*/if (/*@>1dd1e6*/rtDW./*@>1e9dfc*/ImageDataTypeConversion_k/*@>15f719*/ > /*@>1dd1ec*/rtDW./*@>1e9dff*/ImageDataTypeConversion_cx) {
            /*@>1dd210*/rtDW./*@>1e9e11*/bestInlierDis/*@>1a77b1*/ = /*@>1dd216*/rtDW./*@>1e9e14*/ImageDataTypeConversion_k;
        } else {
            /*@>1dd204*/rtDW./*@>1e9e0b*/bestInlierDis/*@>18fd6f*/ = /*@>1dd20a*/rtDW./*@>1e9e0e*/ImageDataTypeConversion_cx;
        }
    }
    /*@>1dd24c*/rtDW./*@>1e9e2f*/s1DivS2/*@>15f739*/ = /*@>1dd252*/rtDW./*@>1e9e32*/bestInlierDis/*@>15f738*/ - /*@>1dd258*/rtDW./*@>1e9e35*/win_y_high;
    /*@>15f73f*/if (/*@>1dd264*/rtDW./*@>1e9e3b*/bestInlierDis/*@>15f73e*/ != /*@>194b8b*/0.0) {
        /*@>1dd28e*/rtDW./*@>1e9e50*/win_y_high/*@>15f74b*/ = /*@>1dd294*/rtDW./*@>1e9e53*/s1DivS2/*@>15f749*/ / /*@>1dd29a*/rtDW./*@>1e9e56*/bestInlierDis;
    } else {
        /*@>1dd288*/rtDW./*@>1e9e4d*/win_y_high/*@>15f74f*/ = /*@>194b90*/0.0;
    }
    /*@>15f755*/if (/*@>1dd2e8*/rtDW./*@>1e9e7a*/s1DivS2/*@>15f754*/ != /*@>194b95*/0.0) {
        /*@>15f75e*/if (/*@>1dd306*/rtDW./*@>1e9e89*/ImageDataTypeConversion_c/*@>15f75d*/ == /*@>1dd30c*/rtDW./*@>1e9e8c*/bestInlierDis) {
            /*@>1dd324*/rtDW./*@>1e9e98*/s1DivS2/*@>15f777*/ = (/*@>1dd32a*/rtDW./*@>1e9e9b*/ImageDataTypeConversion_k/*@>16875a*/ - /*@>1dd330*/rtDW./*@>1e9e9e*/ImageDataTypeConversion_cx)/*@>15f775*/ / /*@>1dd336*/rtDW./*@>1e9ea1*/s1DivS2;
        } else /*@>15f783*/if (/*@>1dd318*/rtDW./*@>1e9e92*/ImageDataTypeConversion_k/*@>15f782*/ == /*@>1dd31e*/rtDW./*@>1e9e95*/bestInlierDis) {
            /*@>1dd354*/rtDW./*@>1e9eb0*/s1DivS2/*@>15f7a1*/ = (/*@>1dd35a*/rtDW./*@>1e9eb3*/ImageDataTypeConversion_cx/*@>1688c8*/ - /*@>1dd360*/rtDW./*@>1e9eb6*/ImageDataTypeConversion_c)/*@>168750*/ / /*@>1dd366*/rtDW./*@>1e9eb9*/s1DivS2/*@>15f79f*/ + /*@>194b9e*/2.0;
        } else {
            /*@>1dd33c*/rtDW./*@>1e9ea4*/s1DivS2/*@>15f7bf*/ = (/*@>1dd342*/rtDW./*@>1e9ea7*/ImageDataTypeConversion_c/*@>1688b7*/ - /*@>1dd348*/rtDW./*@>1e9eaa*/ImageDataTypeConversion_k)/*@>168738*/ / /*@>1dd34e*/rtDW./*@>1e9ead*/s1DivS2/*@>15f7bd*/ + /*@>194ba1*/4.0;
        }
        /*@>1dd3b4*/rtDW./*@>1e9ee0*/s1DivS2/*@>1e8825*/ /= /*@>194ba6*/6.0;
        /*@>15f7cc*/if (/*@>1dd3d8*/rtDW./*@>1e9eef*/s1DivS2/*@>15f7cb*/ < /*@>194bab*/0.0) {
            /*@>1dd3f6*/rtDW./*@>1e9efe*/s1DivS2/*@>1e8826*/++;
        }
    } else {
        /*@>1dd300*/rtDW./*@>1e9e86*/s1DivS2/*@>15f7d7*/ = /*@>194bb1*/0.0;
    }
    /* assign the results */
    /*@>1dd3a2*/rtDW./*@>1e9ed7*/ColorSpaceConversion/*@>15f7dc*/[/*@>1dd3a8*/rtDW./*@>1e9eda*/svdRsltVar]/*@>15f7df*/ = /*@>1dd3ae*/rtDW./*@>1e9edd*/s1DivS2;
    /*@>1dd3c6*/rtDW./*@>1e9ee6*/ColorSpaceConversion/*@>15f7e7*/[/*@>1dd3cc*/rtDW./*@>1e9ee9*/svdRsltVar/*@>15f7e5*/ + /*@>194c95*/307200]/*@>15f7ea*/ = /*@>1dd3d2*/rtDW./*@>1e9eec*/win_y_high;
    /* {S!d252}S-Function (svipcolorconv): '<S4>/Color Space  Conversion' */
    /*@>1dd3e4*/rtDW./*@>1e9ef5*/ColorSpaceConversion/*@>1ae0a5*/[/*@>1dd3ea*/rtDW./*@>1e9ef8*/svdRsltVar/*@>1ae0a7*/ + /*@>1ae0aa*/614400]/*@>1ae0ad*/ = /*@>1dd3f0*/rtDW./*@>1e9efb*/bestInlierDis;
    /* {S!d254}MATLAB Function: '<S4>/MATLAB Function7' incorporates:
 *  S-Function (svipcolorconv): '<S4>/Color Space  Conversion'
 */
    /*@>1dd402*/rtDW./*@>1e9f01*/V_Channel/*@>18a63d*/[/*@>1dd408*/rtDW./*@>1e9f04*/svdRsltVar]/*@>17beda*/ = /*@>1dd40e*/rtDW./*@>1e9f07*/bestInlierDis;
}
/*@>17bf37*/for (/*@>1e8687*/rtDW./*@>1ea93f*/i = /*@>1e8685*/0; /*@>1e8697*/rtDW./*@>1ea945*/i < /*@>1e8694*/8; /*@>1e8691*/rtDW./*@>1ea942*/i/*@>1e8827*/++) {
    /* {S!d256}MATLAB Function: '<S4>/MATLAB Function1' */
    /*@>1dd13e*/rtDW./*@>1e9da8*/pts1/*@>17bf29*/[/*@>1dd144*/rtDW./*@>1e9dab*/i]/*@>17bf2a*/ = /*@>1da1bf*/tmp/*@>1da1c1*/[/*@>1dd14a*/rtDW./*@>1e9dae*/i];
    /* {S!d258}MATLAB Function: '<S4>/MATLAB Function2' */
    /*@>1dd17a*/rtDW./*@>1e9dc6*/pts2/*@>17bfa6*/[/*@>1dd180*/rtDW./*@>1e9dc9*/i]/*@>17bfa7*/ = /*@>1da1d5*/tmp_0/*@>1da1d7*/[/*@>1dd186*/rtDW./*@>1e9dcc*/i];
}
/* {S!d260}S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */
/*@>1d4839*/std::memset(&/*@>1dd174*/rtDW./*@>1e9dc3*/EstimateGeometricTransformation/*@>1d1896*/[/*@>1d1892*/0], /*@>1e80ab*/0, /*@>1d1894*/9U/*@>1d189c*/ * /*@>1d189b*/sizeof(double));
/*@>1dd1a4*/rtDW./*@>1e9ddb*/EstimateGeometricTransformation_DW_BEST_SAMPLE/*@>1901d4*/[/*@>1955d8*/0]/*@>1901d3*/ = /*@>1e80ae*/0;
/*@>1dd1da*/rtDW./*@>1e9df6*/EstimateGeometricTransformation_DW_BEST_SAMPLE/*@>1901e0*/[/*@>1955db*/1]/*@>1901df*/ = /*@>1e80b1*/1;
/*@>1dd1e0*/rtDW./*@>1e9df9*/EstimateGeometricTransformation_DW_BEST_SAMPLE/*@>1901ec*/[/*@>1955de*/2]/*@>1901eb*/ = /*@>1e80b4*/2;
/*@>1dd1fe*/rtDW./*@>1e9e08*/EstimateGeometricTransformation_DW_BEST_SAMPLE/*@>1901f8*/[/*@>1955e1*/3]/*@>1901f7*/ = /*@>1e80b7*/3;
/*@[1e589f*/makeConstraintMatrix_Projective_D_D((const double *)&/*@>1eaa73*/rtDW./*@>1eaa72*/pts1/*@>1eaa71*/[/*@>1eaa75*/0], (const double *)&/*@>1eaa87*/rtDW./*@>1eaa86*/pts2/*@>1eaa85*/[/*@>1eaa89*/0], /*@>1eaa97*/4U, /*@>1eaaa5*/4U, &/*@>1eaab6*/rtDW./*@>1eaab5*/EstimateGeometricTransformation_DW_CONSTRT_ALL/*@>1eaab4*/[/*@>1eaab8*/0])/*@]*/;
/*@>1dd246*/rtDW./*@>1e9e2c*/svdRsltVar/*@>15dd06*/ = /*@>1e80ba*/0;
while/*@<15dd0c*/ (/*@>1dd25e*/rtDW./*@>1e9e38*/svdRsltVar/*@>15dd0b*/ < /*@>19994f*/4) {
    /*@>1dd270*/rtDW./*@>1e9e41*/EstimateGeometricTransformation_DW_SAMPLEIDX/*@>17c488*/[/*@>1dd276*/rtDW./*@>1e9e44*/svdRsltVar]/*@>15dd12*/ = static_cast<uint32_t>(/*@>1dd27c*/rtDW./*@>1e9e47*/EstimateGeometricTransformation_DW_BEST_SAMPLE/*@>1da1dd*/[/*@>1dd282*/rtDW./*@>1e9e4a*/svdRsltVar]);
    /*@>1dd2be*/rtDW./*@>1e9e68*/svdRsltVar/*@>1e8829*/++;
}
/*@>1dd26a*/rtDW./*@>1e9e3e*/bestCol/*@>15dd40*/ = /*@>194a29*/0U;
/*@[1e58bc*/normPts_D_D((const double *)&/*@>1eaaca*/rtDW./*@>1eaac9*/pts1/*@>1eaac8*/[/*@>1eaacc*/0], (const uint32_t *)&/*@>1eaade*/rtDW./*@>1eaadd*/EstimateGeometricTransformation_DW_SAMPLEIDX/*@>1eaadc*/[/*@>1eaae0*/0], /*@>1eaaee*/4U, /*@>1eaafc*/4U, &/*@>1eab0d*/rtDW./*@>1eab0c*/EstimateGeometricTransformation_DW_PTSNORM1/*@>1eab0b*/[/*@>1eab0f*/0], &/*@>1eab1f*/rtDW./*@>1eab1e*/x_location, &/*@>1eab31*/rtDW./*@>1eab30*/cents1/*@>1eab2f*/[/*@>1eab33*/0])/*@]*/;
/*@[1e58d9*/normPts_D_D((const double *)&/*@>1eab45*/rtDW./*@>1eab44*/pts2/*@>1eab43*/[/*@>1eab47*/0], (const uint32_t *)&/*@>1eab59*/rtDW./*@>1eab58*/EstimateGeometricTransformation_DW_SAMPLEIDX/*@>1eab57*/[/*@>1eab5b*/0], /*@>1eab69*/4U, /*@>1eab77*/4U, &/*@>1eab88*/rtDW./*@>1eab87*/EstimateGeometricTransformation_DW_PTSNORM2/*@>1eab86*/[/*@>1eab8a*/0], &/*@>1eab9a*/rtDW./*@>1eab99*/x_current, &/*@>1eabac*/rtDW./*@>1eabab*/cents2/*@>1eabaa*/[/*@>1eabae*/0])/*@]*/;
/*@[1e58f4*/makeConstraintMatrix_Projective_D_D((const double *)&/*@>1eabc0*/rtDW./*@>1eabbf*/EstimateGeometricTransformation_DW_PTSNORM1/*@>1eabbe*/[/*@>1eabc2*/0], (const double *)&/*@>1eabd4*/rtDW./*@>1eabd3*/EstimateGeometricTransformation_DW_PTSNORM2/*@>1eabd2*/[/*@>1eabd6*/0], /*@>1eabe4*/4U, /*@>1eabf2*/4U, &/*@>1eac03*/rtDW./*@>1eac02*/Constraint/*@>1eac01*/[/*@>1eac05*/0])/*@]*/;
/*@>181e6a*/for (/*@>1e866c*/rtDW./*@>1ea936*/i = /*@>1e866a*/0; /*@>1e867c*/rtDW./*@>1ea93c*/i < /*@>1e8679*/8; /*@>1e8676*/rtDW./*@>1ea939*/i/*@>1e882a*/++) {
    /*@>1dd396*/rtDW./*@>1e9ed1*/JPVT/*@>15dfbe*/[static_cast<uint32_t>(/*@>1dd39c*/rtDW./*@>1e9ed4*/i)]/*@>15dfbf*/ = /*@>1e80bd*/0;
}
/*@[1e5914*/QRE_double_o(&/*@>1eac16*/rtDW./*@>1eac15*/Q/*@>1eac14*/[/*@>1eac18*/0], &/*@>1eac29*/rtDW./*@>1eac28*/Constraint/*@>1eac27*/[/*@>1eac2b*/0], &/*@>1eac3c*/rtDW./*@>1eac3b*/E/*@>1eac3a*/[/*@>1eac3e*/0], &/*@>1eac4f*/rtDW./*@>1eac4e*/Qraux/*@>1eac4d*/[/*@>1eac51*/0], &/*@>1eac62*/rtDW./*@>1eac61*/Work/*@>1eac60*/[/*@>1eac64*/0], &/*@>1eac75*/rtDW./*@>1eac74*/JPVT/*@>1eac73*/[/*@>1eac77*/0], &/*@>1eac88*/rtDW./*@>1eac87*/RV/*@>1eac86*/[/*@>1eac8a*/0], /*@>1eac98*/9, /*@>1eaca6*/8, /*@>1eacb4*/true)/*@]*/;
/*@>1dd3c0*/rtDW./*@>1e9ee3*/win_y_high/*@>15eadf*/ = /*@>194a25*/0.0;
/*@>181e1a*/for (/*@>1e861b*/rtDW./*@>1ea91b*/i = /*@>1e8619*/0; /*@>1e862b*/rtDW./*@>1ea921*/i < /*@>1e8628*/9; /*@>1e8625*/rtDW./*@>1ea91e*/i/*@>1e882c*/++) {
/*@>181e3c*/    for (/*@>1e8636*/rtDW./*@>1ea924*/j = /*@>1e8634*/0; /*@>1e8646*/rtDW./*@>1ea92a*/j < /*@>1e8643*/9; /*@>1e8640*/rtDW./*@>1ea927*/j/*@>1e882d*/++) {
        /*@>1a77b8*/if (static_cast<uint32_t>(/*@>1dd42c*/rtDW./*@>1e9f16*/i)/*@>15eaf0*/ != static_cast<uint32_t>(/*@>1dd432*/rtDW./*@>1e9f19*/j)) {
            /*@>1dd468*/rtDW./*@>1e9f34*/s1DivS2/*@>1a77bb*/ = /*@>194a13*/0.0;
        } else {
            /*@>1dd462*/rtDW./*@>1e9f31*/s1DivS2/*@>18fd79*/ = /*@>194a12*/-1.0;
        }
/*@>181e53*/        for (/*@>1e8651*/rtDW./*@>1ea92d*/inlierNum = /*@>1e864f*/0; /*@>1e8661*/rtDW./*@>1ea933*/inlierNum < /*@>1e865e*/8; /*@>1e865b*/rtDW./*@>1ea930*/inlierNum/*@>1e8830*/++) {
            /*@>1dd4e6*/rtDW./*@>1e9f73*/s1DivS2_tmp/*@>1bbd62*/ = static_cast<uint32_t>(/*@>1dd4ec*/rtDW./*@>1e9f76*/inlierNum)/*@>196c77*/ * /*@>1950e2*/9U;
            /*@>1dd50a*/rtDW./*@>1e9f85*/s1DivS2/*@>1e8834*/ += /*@>1dd510*/rtDW./*@>1e9f88*/Q/*@>1da21a*/[/*@>1dd516*/rtDW./*@>1e9f8b*/s1DivS2_tmp/*@>1da212*/ + static_cast<uint32_t>(/*@>1dd51c*/rtDW./*@>1e9f8e*/i)]/*@>196c75*/ * /*@>1dd522*/rtDW./*@>1e9f91*/Q/*@>1da224*/[rtDW.s1DivS2_tmp/*@>1da21c*/ + static_cast<uint32_t>(/*@>1dd52e*/rtDW./*@>1e9f97*/j)];
        }
        /*@>1dd4ce*/rtDW./*@>1e9f67*/RV/*@>15eb1e*/[static_cast<uint32_t>(/*@>1dd4d4*/rtDW./*@>1e9f6a*/i)/*@>196c70*/ * /*@>194a11*/9U/*@>15eb1c*/ + static_cast<uint32_t>(/*@>1dd4da*/rtDW./*@>1e9f6d*/j)]/*@>15eb1f*/ = /*@>1dd4e0*/rtDW./*@>1e9f70*/s1DivS2;
        /*@>18fd7b*/if (!/*@<1c9fe1*/(/*@>1dd504*/rtDW./*@>1e9f82*/s1DivS2/*@>15eb23*/ >= /*@>194a10*/0.0)) {
            /*@>1dd54c*/rtDW./*@>1e9fa3*/s1DivS2/*@>15eb27*/ = -/*@<196c6f*//*@>1dd552*/rtDW./*@>1e9fa6*/s1DivS2;
        }
        /*@>15eb2e*/if (/*@>1dd58e*/rtDW./*@>1e9fc4*/win_y_high/*@>15eb2d*/ < /*@>1dd594*/rtDW./*@>1e9fc7*/s1DivS2) {
            /*@>1dd5ac*/rtDW./*@>1e9fd3*/win_y_high/*@>15eb31*/ = /*@>1dd5b2*/rtDW./*@>1e9fd6*/s1DivS2;
            /*@>1dd5ca*/rtDW./*@>1e9fe2*/bestCol/*@>15eb33*/ = static_cast<uint32_t>(/*@>1dd5d0*/rtDW./*@>1e9fe5*/i);
        }
    }
}
/*@>1dd414*/rtDW./*@>1e9f0a*/j/*@>15ebac*/ = static_cast<int32_t>(/*@>1dd41a*/rtDW./*@>1e9f0d*/bestCol/*@>196c47*/ * /*@>194a23*/9U);
/*@>181dd3*/for (/*@>1e8600*/rtDW./*@>1ea912*/i = /*@>1e85fe*/0; /*@>1e8610*/rtDW./*@>1ea918*/i < /*@>1e860d*/9; /*@>1e860a*/rtDW./*@>1ea915*/i/*@>1e8839*/++) {
    /*@>1dd444*/rtDW./*@>1e9f22*/tformCompact/*@>17ce37*/[static_cast<uint32_t>(/*@>1dd44a*/rtDW./*@>1e9f25*/i)]/*@>15ebb9*/ = /*@>1dd450*/rtDW./*@>1e9f28*/RV/*@>1da1e8*/[static_cast<uint32_t>(/*@>1dd456*/rtDW./*@>1e9f2b*/j) + static_cast<uint32_t>(/*@>1dd45c*/rtDW./*@>1e9f2e*/i)];
}
/*@>1dd438*/rtDW./*@>1e9f1c*/win_y_high/*@>15ebc7*/ = /*@>194b2c*/1.0/*@>15ebc6*/ / /*@>1dd43e*/rtDW./*@>1e9f1f*/x_current;
/*@>1dd46e*/rtDW./*@>1e9f37*/s1DivS2/*@>15ebcc*/ = /*@>1dd474*/rtDW./*@>1e9f3a*/x_location/*@>196c45*/ * /*@>1dd47a*/rtDW./*@>1e9f3d*/win_y_high;
/*@>1dd480*/rtDW./*@>1e9f40*/tformCompact_m/*@>17ced2*/[/*@>1950dd*/6]/*@>15ebd4*/ = /*@>1dd486*/rtDW./*@>1e9f43*/tformCompact/*@>1da1ed*/[/*@>1da1ea*/6]/*@>196c41*/ * /*@>1dd48c*/rtDW./*@>1e9f46*/x_location;
/*@>1dd498*/rtDW./*@>1e9f4c*/tformCompact_m/*@>17cf4f*/[/*@>1950f1*/7]/*@>15ebdc*/ = /*@>1dd49e*/rtDW./*@>1e9f4f*/tformCompact/*@>1da1f2*/[/*@>1da1ef*/7]/*@>196c3d*/ * /*@>1dd4a4*/rtDW./*@>1e9f52*/x_location;
/*@>1dd4aa*/rtDW./*@>1e9f55*/tformCompact_m/*@>17cff9*/[/*@>195103*/8]/*@>15ebf2*/ = (/*@>1dd4b0*/rtDW./*@>1e9f58*/tformCompact/*@>1da1f7*/[/*@>1da1f4*/8]/*@>15ebe7*/ - /*@>1dd4b6*/rtDW./*@>1e9f5b*/cents1/*@>1da1fc*/[/*@>1da1f9*/0]/*@>196c35*/ * /*@>1dd4bc*/rtDW./*@>1e9f5e*/tformCompact_m/*@>1da201*/[/*@>1da1fe*/6])/*@>15ebef*/ - /*@>1dd4c2*/rtDW./*@>1e9f61*/cents1/*@>1da206*/[/*@>1da203*/1]/*@>196c39*/ * /*@>1dd4c8*/rtDW./*@>1e9f64*/tformCompact_m/*@>1da20b*/[/*@>1da208*/7];
/*@>1dd4f2*/rtDW./*@>1e9f79*/tformCompact_m/*@>17d02e*/[/*@>195109*/0]/*@>15ebfa*/ = /*@>1dd4f8*/rtDW./*@>1e9f7c*/tformCompact/*@>1da210*/[/*@>1da20d*/0]/*@>196c31*/ * /*@>1dd4fe*/rtDW./*@>1e9f7f*/s1DivS2;
/*@>1dd53a*/rtDW./*@>1e9f9a*/tformCompact_m/*@>17d185*/[/*@>195121*/1]/*@>15ec02*/ = /*@>1dd540*/rtDW./*@>1e9f9d*/tformCompact/*@>1da229*/[/*@>1da226*/1]/*@>196c2d*/ * /*@>1dd546*/rtDW./*@>1e9fa0*/s1DivS2;
/*@>1dd558*/rtDW./*@>1e9fa9*/tformCompact_m/*@>17d268*/[/*@>195139*/2]/*@>15ec22*/ = ((/*@>1dd55e*/rtDW./*@>1e9fac*/cents2/*@>1da22e*/[/*@>1da22b*/0]/*@>196c1d*/ * /*@>1dd564*/rtDW./*@>1e9faf*/tformCompact_m/*@>1da233*/[/*@>1da230*/8]/*@>15ec11*/ - /*@>1dd56a*/rtDW./*@>1e9fb2*/tformCompact_m/*@>1da238*/[/*@>1da235*/0]/*@>196c21*/ * /*@>1dd570*/rtDW./*@>1e9fb5*/cents1/*@>1da23d*/[/*@>1da23a*/0])/*@>15ec19*/ - /*@>1dd576*/rtDW./*@>1e9fb8*/tformCompact_m/*@>1da242*/[/*@>1da23f*/1]/*@>196c25*/ * /*@>1dd57c*/rtDW./*@>1e9fbb*/cents1/*@>1da247*/[/*@>1da244*/1])/*@>15ec1f*/ + /*@>1dd582*/rtDW./*@>1e9fbe*/tformCompact/*@>1da24c*/[/*@>1da249*/2]/*@>196c29*/ * /*@>1dd588*/rtDW./*@>1e9fc1*/win_y_high;
/*@>1dd59a*/rtDW./*@>1e9fca*/tformCompact_m/*@>17d2a2*/[/*@>19513f*/3]/*@>15ec2a*/ = /*@>1dd5a0*/rtDW./*@>1e9fcd*/tformCompact/*@>1da251*/[/*@>1da24e*/3]/*@>196c19*/ * /*@>1dd5a6*/rtDW./*@>1e9fd0*/s1DivS2;
/*@>1dd5b8*/rtDW./*@>1e9fd9*/tformCompact_m/*@>17d2d7*/[/*@>195145*/4]/*@>15ec32*/ = /*@>1dd5be*/rtDW./*@>1e9fdc*/tformCompact/*@>1da256*/[/*@>1da253*/4]/*@>196c15*/ * /*@>1dd5c4*/rtDW./*@>1e9fdf*/s1DivS2;
/*@>1dd5d6*/rtDW./*@>1e9fe8*/tformCompact_m/*@>17d5ca*/[/*@>1951ad*/5]/*@>15ec52*/ = ((/*@>1dd5dc*/rtDW./*@>1e9feb*/cents2/*@>1da25b*/[/*@>1da258*/1]/*@>196c05*/ * /*@>1dd5e2*/rtDW./*@>1e9fee*/tformCompact_m/*@>1da260*/[/*@>1da25d*/8]/*@>15ec41*/ - /*@>1dd5e8*/rtDW./*@>1e9ff1*/cents1/*@>1da265*/[/*@>1da262*/0]/*@>196c09*/ * /*@>1dd5ee*/rtDW./*@>1e9ff4*/tformCompact_m/*@>1da26a*/[/*@>1da267*/3])/*@>15ec49*/ - /*@>1dd5f4*/rtDW./*@>1e9ff7*/cents1/*@>1da26f*/[/*@>1da26c*/1]/*@>196c0d*/ * /*@>1dd5fa*/rtDW./*@>1e9ffa*/tformCompact_m/*@>1da274*/[/*@>1da271*/4])/*@>15ec4f*/ + /*@>1dd600*/rtDW./*@>1e9ffd*/tformCompact/*@>1da279*/[/*@>1da276*/5]/*@>196c11*/ * /*@>1dd606*/rtDW./*@>1ea000*/win_y_high;
/*@>1dd60c*/rtDW./*@>1ea003*/tformCompact_m/*@>17d6a5*/[/*@>1951c1*/0]/*@>1e883d*/ += /*@>1dd612*/rtDW./*@>1ea006*/cents2/*@>1da27e*/[/*@>1da27b*/0]/*@>196c01*/ * /*@>1dd618*/rtDW./*@>1ea009*/tformCompact_m/*@>1da283*/[/*@>1da280*/6];
/*@>1dd624*/rtDW./*@>1ea00c*/tformCompact_m/*@>17d8df*/[/*@>1951fc*/1]/*@>1e883e*/ += /*@>1dd62a*/rtDW./*@>1ea00f*/cents2/*@>1da28d*/[/*@>1da28a*/0]/*@>196bfd*/ * /*@>1dd630*/rtDW./*@>1ea012*/tformCompact_m/*@>1da292*/[/*@>1da28f*/7];
/*@>1dd63c*/rtDW./*@>1ea015*/tformCompact_m/*@>17da44*/[/*@>19522f*/3]/*@>1e883f*/ += /*@>1dd642*/rtDW./*@>1ea018*/cents2/*@>1da29c*/[/*@>1da299*/1]/*@>196bf9*/ * /*@>1dd648*/rtDW./*@>1ea01b*/tformCompact_m/*@>1da2a1*/[/*@>1da29e*/6];
/*@>1dd654*/rtDW./*@>1ea01e*/tformCompact_m/*@>17daaf*/[/*@>19523b*/4]/*@>1e8840*/ += /*@>1dd65a*/rtDW./*@>1ea021*/cents2/*@>1da2ab*/[/*@>1da2a8*/1]/*@>196bf5*/ * /*@>1dd660*/rtDW./*@>1ea024*/tformCompact_m/*@>1da2b0*/[/*@>1da2ad*/7];
/*@>15ec94*/if (/*@>1dd66c*/rtDW./*@>1ea027*/tformCompact_m/*@>1da2ba*/[/*@>1da2b7*/8U]/*@>15ec93*/ != /*@>194a22*/0.0) {
    /*@>1dd678*/rtDW./*@>1ea02d*/win_y_high/*@>15ec9c*/ = /*@>194b45*/1.0/*@>15ec9b*/ / /*@>1dd67e*/rtDW./*@>1ea030*/tformCompact_m/*@>1da2bf*/[/*@>1da2bc*/8];
/*@>181dbb*/    for (/*@>1e85e5*/rtDW./*@>1ea909*/i = /*@>1e85e3*/0; /*@>1e85f5*/rtDW./*@>1ea90f*/i < /*@>1e85f2*/8; /*@>1e85ef*/rtDW./*@>1ea90c*/i/*@>1e8841*/++) {
        /*@>1dd6a2*/rtDW./*@>1ea042*/tformCompact_m/*@>17dc6d*/[static_cast<uint32_t>(/*@>1dd6a8*/rtDW./*@>1ea045*/i)]/*@>1e8844*/ *= /*@>1dd6ba*/rtDW./*@>1ea048*/win_y_high;
    }
    /*@>1dd69c*/rtDW./*@>1ea03f*/tformCompact_m/*@>15ecb2*/[/*@>194b4a*/8]/*@>15ecb4*/ = /*@>194a20*/1.0;
    /*@>1dd6d2*/rtDW./*@>1ea051*/bestCol/*@>15ecc4*/ = /*@>194a1c*/0U;
/*@>181d6e*/    for (/*@>1e8594*/rtDW./*@>1ea8ee*/i = /*@>1e8592*/0; /*@>1e85a4*/rtDW./*@>1ea8f4*/i < /*@>1e85a1*/4; /*@>1e859e*/rtDW./*@>1ea8f1*/i/*@>1e8845*/++) {
        /*@>1dd72c*/rtDW./*@>1ea078*/EstimateGeometricTransformation_DW_DISTANCE/*@>15ecce*/[static_cast<uint32_t>(/*@>1dd732*/rtDW./*@>1ea07b*/i)]/*@>15ecd0*/ = /*@>194a15*/0.0;
/*@>181d8c*/        for (/*@>1e85af*/rtDW./*@>1ea8f7*/j = /*@>1e85ad*/0; /*@>1e85bf*/rtDW./*@>1ea8fd*/j < /*@>1e85bc*/2; /*@>1e85b9*/rtDW./*@>1ea8fa*/j/*@>1e8847*/++) {
            /*@>1dd79e*/rtDW./*@>1ea0a5*/win_y_high/*@>15ecda*/ = /*@>194a14*/0.0;
/*@>181da4*/            for (/*@>1e85ca*/rtDW./*@>1ea900*/inlierNum = /*@>1e85c8*/0; /*@>1e85da*/rtDW./*@>1ea906*/inlierNum < /*@>1e85d7*/9; /*@>1e85d4*/rtDW./*@>1ea903*/inlierNum/*@>1e8848*/++) {
                /*@>1dd804*/rtDW./*@>1ea0cc*/win_y_high/*@>1e884b*/ += /*@>1dd80a*/rtDW./*@>1ea0cf*/EstimateGeometricTransformation_DW_CONSTRT_ALL/*@>1da30d*/[/*@>1dd810*/rtDW./*@>1ea0d2*/bestCol + static_cast<uint32_t>(/*@>1dd816*/rtDW./*@>1ea0d5*/inlierNum)]/*@>196c87*/ * /*@>1dd81c*/rtDW./*@>1ea0d8*/tformCompact_m/*@>1da314*/[static_cast<uint32_t>(/*@>1dd822*/rtDW./*@>1ea0db*/inlierNum)];
            }
            rtDW.bestCol += /*@>195464*/9U;
            /*@>1dd840*/rtDW./*@>1ea0e7*/EstimateGeometricTransformation_DW_DISTANCE/*@>17d4b4*/[static_cast<uint32_t>(/*@>1dd846*/rtDW./*@>1ea0ea*/i)]/*@>1e884f*/ += /*@>1dd84c*/rtDW./*@>1ea0ed*/win_y_high/*@>196c83*/ * /*@>1dd852*/rtDW./*@>1ea0f0*/win_y_high;
        }
    }
    /*@>1d483b*/std::memcpy(&/*@>1dd75c*/rtDW./*@>1ea087*/bestTFormCompact/*@>1d015c*/[/*@>1d014b*/0], &/*@>1dd762*/rtDW./*@>1ea08a*/tformCompact_m/*@>1d0164*/[/*@>1d0158*/0], /*@>1d015a*/9U/*@>1d0167*/ * /*@>1d0166*/sizeof(double));
    /*@>1dd780*/rtDW./*@>1ea099*/inlierNum/*@>15ed4b*/ = /*@>1e80c3*/0;
    /*@>1900e0*/if (/*@>1dd798*/rtDW./*@>1ea0a2*/EstimateGeometricTransformation_DW_DISTANCE/*@>1da2f9*/[/*@>1da2f6*/0]/*@>1900e1*/ <= /*@>195568*/2.5) {
        /*@>1dd7b6*/rtDW./*@>1ea0ae*/inlierNum/*@>1900f3*/ = /*@>1e80c6*/1;
    }
    /*@>1900fc*/if (/*@>1dd7e0*/rtDW./*@>1ea0c0*/EstimateGeometricTransformation_DW_DISTANCE/*@>1da303*/[/*@>1da300*/1]/*@>1900fd*/ <= /*@>195570*/2.5) {
        /*@>1dd7ec*/rtDW./*@>1ea0c3*/inlierNum/*@>19010f*/ = static_cast<int32_t>(static_cast<uint32_t>(/*@>1dd7f2*/rtDW./*@>1ea0c6*/inlierNum)/*@>190111*/ + /*@>195579*/1U);
    }
    /*@>190118*/if (/*@>1dd83a*/rtDW./*@>1ea0e4*/EstimateGeometricTransformation_DW_DISTANCE/*@>1da319*/[/*@>1da316*/2]/*@>190119*/ <= /*@>19557d*/2.5) {
        /*@>1dd870*/rtDW./*@>1ea0f9*/inlierNum/*@>19012b*/ = static_cast<int32_t>(static_cast<uint32_t>(/*@>1dd876*/rtDW./*@>1ea0fc*/inlierNum)/*@>19012d*/ + /*@>195586*/1U);
    }
    /*@>190134*/if (/*@>1dd882*/rtDW./*@>1ea0ff*/EstimateGeometricTransformation_DW_DISTANCE/*@>1da325*/[/*@>1da322*/3]/*@>190135*/ <= /*@>19558a*/2.5) {
        /*@>1dd894*/rtDW./*@>1ea105*/inlierNum/*@>190147*/ = static_cast<int32_t>(static_cast<uint32_t>(/*@>1dd89a*/rtDW./*@>1ea108*/inlierNum)/*@>190149*/ + /*@>195593*/1U);
    }
} else {
    /*@>1dd672*/rtDW./*@>1ea02a*/inlierNum/*@>15ed87*/ = /*@>1e80c0*/0;
}
/*@>15ed94*/if (static_cast<uint32_t>(/*@>1dd68a*/rtDW./*@>1ea036*/inlierNum)/*@>15ed93*/ >= /*@>194a2e*/4U) {
    /*@>1dd690*/rtDW./*@>1ea039*/EstimateGeometricTransformation/*@>17c2e8*/[/*@>194f3f*/0]/*@>15ed9b*/ = /*@>1dd696*/rtDW./*@>1ea03c*/bestTFormCompact/*@>1da2c4*/[/*@>1da2c1*/4];
    /*@>1dd6c6*/rtDW./*@>1ea04b*/EstimateGeometricTransformation/*@>17c363*/[/*@>194f54*/1]/*@>15eda1*/ = /*@>1dd6cc*/rtDW./*@>1ea04e*/bestTFormCompact/*@>1da2d0*/[/*@>1da2cd*/3];
    /*@>1dd6de*/rtDW./*@>1ea057*/EstimateGeometricTransformation/*@>17c3c5*/[/*@>194f5a*/2]/*@>15eda7*/ = /*@>1dd6e4*/rtDW./*@>1ea05a*/bestTFormCompact/*@>1da2d5*/[/*@>1da2d2*/5];
    /*@>1dd6f0*/rtDW./*@>1ea060*/EstimateGeometricTransformation/*@>17c3f8*/[/*@>194f60*/3]/*@>15edad*/ = /*@>1dd6f6*/rtDW./*@>1ea063*/bestTFormCompact/*@>1da2da*/[/*@>1da2d7*/1];
    /*@>1dd71a*/rtDW./*@>1ea072*/EstimateGeometricTransformation/*@>17c453*/[/*@>194f66*/4]/*@>15edb3*/ = /*@>1dd720*/rtDW./*@>1ea075*/bestTFormCompact/*@>1da2e5*/[/*@>1da2e2*/0];
    /*@>1dd750*/rtDW./*@>1ea081*/EstimateGeometricTransformation/*@>17c533*/[/*@>194f8f*/5]/*@>15edb9*/ = /*@>1dd756*/rtDW./*@>1ea084*/bestTFormCompact/*@>1da2ea*/[/*@>1da2e7*/2];
    /*@>1dd774*/rtDW./*@>1ea093*/EstimateGeometricTransformation/*@>17c5de*/[/*@>194fb0*/6]/*@>15edbf*/ = /*@>1dd77a*/rtDW./*@>1ea096*/bestTFormCompact/*@>1da2ef*/[/*@>1da2ec*/7];
    /*@>1dd78c*/rtDW./*@>1ea09c*/EstimateGeometricTransformation/*@>17c689*/[/*@>194fd1*/7]/*@>15edc5*/ = /*@>1dd792*/rtDW./*@>1ea09f*/bestTFormCompact/*@>1da2f4*/[/*@>1da2f1*/6];
    /*@>1dd7aa*/rtDW./*@>1ea0a8*/EstimateGeometricTransformation/*@>17c757*/[/*@>194ff6*/8]/*@>15edcb*/ = /*@>1dd7b0*/rtDW./*@>1ea0ab*/bestTFormCompact/*@>1da2fe*/[/*@>1da2fb*/8];
}
/* {S!d262}MATLAB Function: '<S4>/MATLAB Function8' */
/*@>17c332*/for (/*@>1e8579*/rtDW./*@>1ea8e5*/i = /*@>1e8577*/0; /*@>1e8589*/rtDW./*@>1ea8eb*/i < /*@>1e8586*/307200; /*@>1e8583*/rtDW./*@>1ea8e8*/i/*@>1e8857*/++) {
    /*@>1dd702*/rtDW./*@>1ea066*/rtb_V_Channel_a/*@>17c324*/[/*@>1dd708*/rtDW./*@>1ea069*/i]/*@>17c325*/ = (/*@>1dd70e*/rtDW./*@>1ea06c*/V_Channel/*@>1da2e0*/[/*@>1dd714*/rtDW./*@>1ea06f*/i]/*@>17c316*/ > /*@>194dff*/0.5);
}
/* {E!d262}End of MATLAB Function: '<S4>/MATLAB Function8' */

/* {S!d264}MATLABSystem: '<S4>/Warp' incorporates:
 *  S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
 */
/*@[1e592e*/Warp_stepImpl(&/*@>1eacc4*/rtDW./*@>1eacc3*/obj_k, &/*@>1eacd6*/rtDW./*@>1eacd5*/rtb_V_Channel_a[0], &/*@>1eace9*/rtDW./*@>1eace8*/EstimateGeometricTransformation[0], &/*@>1eacfc*/rtDW./*@>1eacfb*/bv[0])/*@]*/;
/* {S!d266}MATLAB Function: '<S2>/MATLAB Function1' incorporates:
 *  MATLABSystem: '<S4>/Warp'
 */
/*@>1dd76e*/rtDW./*@>1ea090*/x_location/*@>15f995*/ = /*@>194be6*/320.0;
/*@[1e5949*/eml_find(&/*@>1ead0f*/rtDW./*@>1ead0e*/bv[0], /*@>1ead20*/rtDW./*@>1ead1f*/ii_data_n, &rtDW.ii_size, /*@>1ead41*/rtDW./*@>1ead40*/jj_data_p, &rtDW.jj_size)/*@]*/;
/*@>1dd82e*/rtDW./*@>1ea0de*/j/*@>1bbd6c*/ = rtDW.ii_size;
rtDW.c_size/*@>17c4cf*/ = rtDW.ii_size;
/*@>17c4f1*/for (/*@>1e855a*/rtDW./*@>1ea8d9*/i = /*@>1e8558*/0; /*@>1e856f*/rtDW./*@>1ea8e2*/i < rtDW.j; /*@>1e8564*/rtDW./*@>1ea8dc*/i/*@>1e8858*/++) {
    /*@>1dd8a6*/rtDW./*@>1ea10b*/outputImage_tmp/*@>1ae003*/ = /*@>1dd8ac*/rtDW./*@>1ea10e*/ii_data_n/*@>1da32b*/[/*@>1dd8b2*/rtDW./*@>1ea111*/i];
    /*@>1dd8c4*/rtDW./*@>1ea11a*/c_data/*@>17c4de*/[/*@>1dd8ca*/rtDW./*@>1ea11d*/i]/*@>17c4df*/ = (/*@>1dd8d0*/rtDW./*@>1ea120*/outputImage_tmp/*@>17c4d2*/ >= /*@>194e00*/456);
    /*@>1dd8e2*/rtDW./*@>1ea129*/d_data/*@>17c589*/[/*@>1dd8e8*/rtDW./*@>1ea12c*/i]/*@>17c58a*/ = (/*@>1dd8ee*/rtDW./*@>1ea12f*/outputImage_tmp/*@>17c57d*/ < /*@>194e01*/480);
}
/*@>1dd8b8*/rtDW./*@>1ea114*/svdRsltVar/*@>1bbd78*/ = rtDW.jj_size;
rtDW.g_size/*@>17c625*/ = rtDW.jj_size;
/*@>17c647*/for (/*@>1e853b*/rtDW./*@>1ea8cd*/i = /*@>1e8539*/0; /*@>1e8550*/rtDW./*@>1ea8d6*/i < rtDW.svdRsltVar; /*@>1e8545*/rtDW./*@>1ea8d0*/i/*@>1e8859*/++) {
    /*@>1dd906*/rtDW./*@>1ea135*/g_data/*@>17c634*/[/*@>1dd90c*/rtDW./*@>1ea138*/i]/*@>17c635*/ = (/*@>1dd912*/rtDW./*@>1ea13b*/jj_data_p/*@>1da331*/[/*@>1dd918*/rtDW./*@>1ea13e*/i]/*@>17c628*/ >= /*@>194e02*/480);
}
rtDW.b_tmp_size/*@>17c6ed*/ = rtDW.ii_size;
/*@>17c715*/for (/*@>1e851c*/rtDW./*@>1ea8c1*/i = /*@>1e851a*/0; /*@>1e8531*/rtDW./*@>1ea8ca*/i < rtDW.j; /*@>1e8526*/rtDW./*@>1ea8c4*/i/*@>1e885a*/++) {
    /*@>1dd942*/rtDW./*@>1ea150*/b_tmp_data/*@>17c702*/[/*@>1dd948*/rtDW./*@>1ea153*/i]/*@>17c703*/ = (/*@>1dd94e*/rtDW./*@>1ea156*/c_data/*@>1da337*/[/*@>1dd954*/rtDW./*@>1ea159*/i]/*@>17c6f0*/ && /*@>1dd95a*/rtDW./*@>1ea15c*/d_data/*@>1da33d*/[/*@>1dd960*/rtDW./*@>1ea15f*/i]);
}
if (rtDW.ii_size == rtDW.jj_size) {
    /* {S!d268}MATLAB Function: '<S2>/MATLAB Function1' */
    rtDW.b_size/*@>17c821*/ = rtDW.ii_size;
/*@>17c849*/    for (/*@>1e84fd*/rtDW./*@>1ea8b5*/i = /*@>1e84fb*/0; /*@>1e8512*/rtDW./*@>1ea8be*/i < rtDW.j; /*@>1e8507*/rtDW./*@>1ea8b8*/i/*@>1e885b*/++) {
        /*@>1dd9c6*/rtDW./*@>1ea186*/b_data/*@>17c836*/[/*@>1dd9cc*/rtDW./*@>1ea189*/i]/*@>17c837*/ = (/*@>1dd9d2*/rtDW./*@>1ea18c*/b_tmp_data/*@>1da343*/[/*@>1dd9d8*/rtDW./*@>1ea18f*/i]/*@>17c824*/ && /*@>1dd9de*/rtDW./*@>1ea192*/g_data/*@>1da349*/[/*@>1dd9e4*/rtDW./*@>1ea195*/i]);
    }
} else {
    /* {S!d270}MATLAB Function: '<S2>/MATLAB Function1' */
    /*@[1e5965*/and_o(/*@>1ead62*/rtDW./*@>1ead61*/b_data, &rtDW.b_size, /*@>1ead83*/rtDW./*@>1ead82*/b_tmp_data, &rtDW.b_tmp_size, /*@>1eada4*/rtDW./*@>1eada3*/g_data, &rtDW.g_size)/*@]*/;
}
/* {S!d272}MATLAB Function: '<S2>/MATLAB Function1' */
rtDW.h_size/*@>17c8a3*/ = rtDW.jj_size;
/*@>17c8c5*/for (/*@>1e84de*/rtDW./*@>1ea8a9*/i = /*@>1e84dc*/0; /*@>1e84f3*/rtDW./*@>1ea8b2*/i < rtDW.svdRsltVar; /*@>1e84e8*/rtDW./*@>1ea8ac*/i/*@>1e885c*/++) {
    /*@>1dd9f6*/rtDW./*@>1ea19e*/h_data/*@>17c8b2*/[/*@>1dd9fc*/rtDW./*@>1ea1a1*/i]/*@>17c8b3*/ = (/*@>1dda02*/rtDW./*@>1ea1a4*/jj_data_p/*@>1da34f*/[/*@>1dda08*/rtDW./*@>1ea1a7*/i]/*@>17c8a6*/ < /*@>194e21*/640);
}
if (rtDW.b_size == rtDW.jj_size) {
    /* {S!d274}MATLAB Function: '<S2>/MATLAB Function1' */
    /*@>1dda38*/rtDW./*@>1ea1bc*/svdRsltVar/*@>1bbd8e*/ = rtDW.b_size;
    rtDW.tmp_size/*@>17c9d8*/ = rtDW.b_size;
/*@>17ca00*/    for (/*@>1e84bf*/rtDW./*@>1ea89d*/i = /*@>1e84bd*/0; /*@>1e84d4*/rtDW./*@>1ea8a6*/i < rtDW.svdRsltVar; /*@>1e84c9*/rtDW./*@>1ea8a0*/i/*@>1e885d*/++) {
        /*@>1dda7a*/rtDW./*@>1ea1d7*/tmp_data_h/*@>17c9ed*/[/*@>1dda80*/rtDW./*@>1ea1da*/i]/*@>17c9ee*/ = (/*@>1dda86*/rtDW./*@>1ea1dd*/b_data/*@>1da355*/[/*@>1dda8c*/rtDW./*@>1ea1e0*/i]/*@>17c9db*/ && /*@>1dda92*/rtDW./*@>1ea1e3*/h_data/*@>1da35b*/[/*@>1dda98*/rtDW./*@>1ea1e6*/i]);
    }
} else {
    /* {S!d276}MATLAB Function: '<S2>/MATLAB Function1' */
    /*@[1e5981*/and_o(/*@>1eadc5*/rtDW./*@>1eadc4*/tmp_data_h, &rtDW.tmp_size, /*@>1eade6*/rtDW./*@>1eade5*/b_data, &rtDW.b_size, /*@>1eae07*/rtDW./*@>1eae06*/h_data, &rtDW.h_size)/*@]*/;
}
rtDW.outputImage_tmp = rtDW.tmp_size - 1;
rtDW.trueCount = 0;
for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
    /* {S!d278}MATLAB Function: '<S2>/MATLAB Function1' */
    if (/*@>1ddaa4*/rtDW./*@>1ea1ec*/tmp_data_h/*@>1da361*/[rtDW.i]) {
        rtDW.trueCount++;
    }
}
/* {S!d280}MATLAB Function: '<S2>/MATLAB Function1' incorporates:
 *  S-Function (svipcolorconv): '<S4>/Color Space  Conversion'
 *  S-Function (svipesttform): '<S4>/Estimate Geometric Transformation'
 */
/*@>15f9dd*/if (rtDW.trueCount/*@>15f9bb*/ > /*@>194be7*/30) {
    /*@>1ddab6*/rtDW./*@>1ea1f5*/inlierNum/*@>15f996*/ = /*@>1e80cf*/1;
    if (rtDW.b_size == rtDW.jj_size) {
        /*@>1ddb58*/rtDW./*@>1ea23d*/svdRsltVar/*@>1bbd98*/ = rtDW.b_size;
        rtDW.tmp_size_g/*@>17cdc9*/ = rtDW.b_size;
/*@>17cdf1*/        for (/*@>1e8484*/rtDW./*@>1ea885*/i = /*@>1e8482*/0; /*@>1e8499*/rtDW./*@>1ea88e*/i < rtDW.svdRsltVar; /*@>1e848e*/rtDW./*@>1ea888*/i/*@>1e8860*/++) {
            /*@>1ddbe2*/rtDW./*@>1ea276*/tmp_data_b/*@>17cdde*/[/*@>1ddbe8*/rtDW./*@>1ea279*/i]/*@>17cddf*/ = (/*@>1ddbee*/rtDW./*@>1ea27c*/b_data/*@>1da36d*/[/*@>1ddbf4*/rtDW./*@>1ea27f*/i]/*@>17cdcc*/ && /*@>1ddbfa*/rtDW./*@>1ea282*/h_data/*@>1da373*/[/*@>1ddc00*/rtDW./*@>1ea285*/i]);
        }
    } else {
        /*@[1e599d*/and_o(/*@>1eae28*/rtDW./*@>1eae27*/tmp_data_b, &rtDW.tmp_size_g, /*@>1eae49*/rtDW./*@>1eae48*/b_data, &rtDW.b_size, /*@>1eae6a*/rtDW./*@>1eae69*/h_data, &rtDW.h_size)/*@]*/;
    }
    rtDW.outputImage_tmp = rtDW.tmp_size_g - 1;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1ddc4e*/rtDW./*@>1ea2ac*/tmp_data_b/*@>1da385*/[rtDW.i]) {
            rtDW.trueCount++;
        }
    }
    rtDW.tmp_size_idx_0 = rtDW.trueCount;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1ddcae*/rtDW./*@>1ea2ca*/tmp_data_b/*@>1da391*/[rtDW.i]) {
            /*@>1ddce4*/rtDW./*@>1ea2e5*/tmp_data[rtDW.trueCount]/*@>178d08*/ = rtDW.i;
            rtDW.trueCount++;
        }
    }
    rtDW.jj_size_b/*@>17d40c*/ = rtDW.tmp_size_idx_0;
/*@>17d445*/    for (/*@>1e842d*/rtDW./*@>1ea861*/i = /*@>1e842b*/0; /*@>1e8442*/rtDW./*@>1ea86a*/i < rtDW.tmp_size_idx_0; /*@>1e8437*/rtDW./*@>1ea864*/i/*@>1e8865*/++) {
        /*@>1ddd4a*/rtDW./*@>1ea309*/jj_data/*@>17d432*/[/*@>1ddd50*/rtDW./*@>1ea30c*/i]/*@>17d433*/ = /*@>1ddd56*/rtDW./*@>1ea30f*/jj_data_p/*@>1da3a0*/[/*@>1ddd5c*/rtDW./*@>1ea312*/tmp_data/*@>1da39a*/[/*@>1ddd62*/rtDW./*@>1ea315*/i]];
    }
    /*@>1ddd38*/rtDW./*@>1ea300*/x_current/*@>15f997*/ = /*@[1e59b5*/mean(/*@>1eae8b*/rtDW./*@>1eae8a*/jj_data, &rtDW.jj_size_b)/*@]*/;
    if ((rtDW.ii_size == rtDW.jj_size) && ((rtDW.ii_size == 1 ? rtDW.jj_size : rtDW.ii_size) == rtDW.jj_size)) {
        rtDW.tmp_size_l/*@>17d994*/ = rtDW.ii_size;
/*@>17d9ca*/        for (/*@>1e840e*/rtDW./*@>1ea855*/i = /*@>1e840c*/0; /*@>1e8423*/rtDW./*@>1ea85e*/i < rtDW.j; /*@>1e8418*/rtDW./*@>1ea858*/i/*@>1e8866*/++) {
            /*@>1dde64*/rtDW./*@>1ea38d*/tmp_data_da/*@>17d9b7*/[/*@>1dde6a*/rtDW./*@>1ea390*/i]/*@>17d9b8*/ = (/*@>1dde70*/rtDW./*@>1ea393*/c_data/*@>1da3c4*/[/*@>1dde76*/rtDW./*@>1ea396*/i]/*@>17d999*/ && /*@>1dde7c*/rtDW./*@>1ea399*/d_data/*@>1da3ca*/[/*@>1dde82*/rtDW./*@>1ea39c*/i]/*@>17d998*/ && /*@>1dde88*/rtDW./*@>1ea39f*/g_data/*@>1da3d0*/[/*@>1dde8e*/rtDW./*@>1ea3a2*/i]/*@>17d997*/ && /*@>1dde94*/rtDW./*@>1ea3a5*/h_data/*@>1da3d6*/[/*@>1dde9a*/rtDW./*@>1ea3a8*/i]);
        }
    } else {
        /*@[1e59d4*/binary_expand_op_2(/*@>1eaeac*/rtDW./*@>1eaeab*/tmp_data_da, &rtDW.tmp_size_l, /*@>1eaecd*/rtDW./*@>1eaecc*/c_data, &rtDW.c_size, /*@>1eaeee*/rtDW./*@>1eaeed*/d_data, /*@>1eaefe*/rtDW./*@>1eaefd*/g_data, &rtDW.g_size, /*@>1eaf1f*/rtDW./*@>1eaf1e*/h_data, &rtDW.h_size)/*@]*/;
    }
    rtDW.outputImage_tmp = rtDW.tmp_size_l - 1;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1ddedc*/rtDW./*@>1ea3c9*/tmp_data_da/*@>1da3dc*/[rtDW.i]) {
            rtDW.trueCount++;
        }
    }
    rtDW.tmp_size_idx_0 = rtDW.trueCount;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1ddfa2*/rtDW./*@>1ea41d*/tmp_data_da/*@>1da3e2*/[rtDW.i]) {
            /*@>1ddfd2*/rtDW./*@>1ea432*/tmp_data_l[rtDW.trueCount]/*@>178dc9*/ = rtDW.i;
            rtDW.trueCount++;
        }
    }
    rtDW.ii_size_n/*@>17de14*/ = rtDW.tmp_size_idx_0;
/*@>17de4d*/    for (/*@>1e83b7*/rtDW./*@>1ea831*/i = /*@>1e83b5*/0; /*@>1e83cc*/rtDW./*@>1ea83a*/i < rtDW.tmp_size_idx_0; /*@>1e83c1*/rtDW./*@>1ea834*/i/*@>1e886b*/++) {
        /*@>1de074*/rtDW./*@>1ea474*/ii_data/*@>17de3a*/[/*@>1de07a*/rtDW./*@>1ea477*/i]/*@>17de3b*/ = /*@>1de080*/rtDW./*@>1ea47a*/ii_data_n/*@>1da3fd*/[/*@>1de086*/rtDW./*@>1ea47d*/tmp_data_l/*@>1da3f7*/[/*@>1de08c*/rtDW./*@>1ea480*/i]];
    }
    /*@>1de062*/rtDW./*@>1ea46b*/bestInlierDis/*@>15fa3e*/ = /*@[1e59ec*/maximum(/*@>1eaf40*/rtDW./*@>1eaf3f*/ii_data, &rtDW.ii_size_n)/*@]*/;
} else {
    /*@>1ddab0*/rtDW./*@>1ea1f2*/inlierNum/*@>15f998*/ = /*@>1e80cc*/2;
    if ((rtDW.ii_size == rtDW.jj_size) && ((rtDW.ii_size == 1 ? rtDW.jj_size : rtDW.ii_size) == rtDW.jj_size)) {
        /*@>1ddb4c*/rtDW./*@>1ea237*/j/*@>1bbdba*/ = rtDW.ii_size;
        rtDW.tmp_size_g/*@>17cd26*/ = rtDW.ii_size;
/*@>17cd57*/        for (/*@>1e8398*/rtDW./*@>1ea825*/i = /*@>1e8396*/0; /*@>1e83ad*/rtDW./*@>1ea82e*/i < rtDW.j; /*@>1e83a2*/rtDW./*@>1ea828*/i/*@>1e888a*/++) {
            /*@>1ddbd0*/rtDW./*@>1ea26d*/outputImage_tmp/*@>188cfd*/ = /*@>1ddbd6*/rtDW./*@>1ea270*/jj_data_p/*@>1da367*/[/*@>1ddbdc*/rtDW./*@>1ea273*/i];
            /*@>1ddc1e*/rtDW./*@>1ea294*/tmp_data_b/*@>17cd44*/[/*@>1ddc24*/rtDW./*@>1ea297*/i]/*@>17cd45*/ = (/*@>1ddc2a*/rtDW./*@>1ea29a*/b_tmp_data/*@>1da37f*/[/*@>1ddc30*/rtDW./*@>1ea29d*/i]/*@>17cd2a*/ && (/*@>1ddc36*/rtDW./*@>1ea2a0*/outputImage_tmp/*@>17cd31*/ >= /*@>194e3e*/0)/*@>17cd29*/ && (/*@>1ddc3c*/rtDW./*@>1ea2a3*/outputImage_tmp/*@>17cd38*/ < /*@>194e3f*/160));
        }
    } else {
        /*@[1e5a08*/binary_expand_op_3(/*@>1eaf61*/rtDW./*@>1eaf60*/tmp_data_b, &rtDW.tmp_size_g, /*@>1eaf82*/rtDW./*@>1eaf81*/b_tmp_data, &rtDW.b_tmp_size, /*@>1eafa3*/rtDW./*@>1eafa2*/jj_data_p, &rtDW.jj_size)/*@]*/;
    }
    rtDW.outputImage_tmp = rtDW.tmp_size_g - 1;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1ddc12*/rtDW./*@>1ea28e*/tmp_data_b/*@>1da379*/[rtDW.i]) {
            rtDW.trueCount++;
        }
    }
    rtDW.tmp_size_idx_0 = rtDW.trueCount;
    rtDW.trueCount = 0;
    for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
        if (/*@>1ddc9c*/rtDW./*@>1ea2c4*/tmp_data_b/*@>1da38b*/[rtDW.i]) {
            /*@>1ddcc6*/rtDW./*@>1ea2d6*/tmp_data[rtDW.trueCount]/*@>178c56*/ = rtDW.i;
            rtDW.trueCount++;
        }
    }
    rtDW.jj_size_b/*@>17d338*/ = rtDW.tmp_size_idx_0;
    rtDW.ii_size_n/*@>17d706*/ = rtDW.tmp_size_idx_0;
/*@>17d371*/    for (/*@>1e8341*/rtDW./*@>1ea801*/i = /*@>1e833f*/0; /*@>1e8356*/rtDW./*@>1ea80a*/i < rtDW.tmp_size_idx_0; /*@>1e834b*/rtDW./*@>1ea804*/i/*@>1e888f*/++) {
        /*@>1ddd9e*/rtDW./*@>1ea333*/jj_data/*@>17d35e*/[/*@>1ddda4*/rtDW./*@>1ea336*/i]/*@>17d35f*/ = /*@>1dddaa*/rtDW./*@>1ea339*/jj_data_p/*@>1da3af*/[/*@>1dddb0*/rtDW./*@>1ea33c*/tmp_data/*@>1da3a9*/[/*@>1dddb6*/rtDW./*@>1ea33f*/i]];
        /*@>1dde0a*/rtDW./*@>1ea366*/ii_data/*@>17d72c*/[/*@>1dde10*/rtDW./*@>1ea369*/i]/*@>17d72d*/ = /*@>1dde16*/rtDW./*@>1ea36c*/ii_data_n/*@>1da3be*/[/*@>1dde1c*/rtDW./*@>1ea36f*/tmp_data/*@>1da3b8*/[/*@>1dde22*/rtDW./*@>1ea372*/i]];
    }
    /*@>1ddd8c*/rtDW./*@>1ea32a*/x_current/*@>15f999*/ = /*@[1e5a20*/mean(/*@>1eafc4*/rtDW./*@>1eafc3*/jj_data, &rtDW.jj_size_b)/*@]*/;
    /*@>1dddf8*/rtDW./*@>1ea35d*/bestInlierDis/*@>15fa3b*/ = /*@[1e5a38*/maximum(/*@>1eafe5*/rtDW./*@>1eafe4*/ii_data, &rtDW.ii_size_n)/*@]*/;
}
/*@>15f9e3*/for (/*@>1e810a*/rtDW./*@>1ea720*/svdRsltVar = /*@>1e8108*/0; /*@>1e811a*/rtDW./*@>1ea726*/svdRsltVar < /*@>1e8117*/20; /*@>1e8114*/rtDW./*@>1ea723*/svdRsltVar/*@>1e886c*/++) {
    /*@>15f9e5*/if (/*@>1ddea0*/rtDW./*@>1ea3ab*/inlierNum/*@>15f9bc*/ == /*@>194bf9*/1) {
        /*@>1ddebe*/rtDW./*@>1ea3ba*/win_y_low/*@>15f99d*/ = /*@>1ddec4*/rtDW./*@>1ea3bd*/bestInlierDis/*@>15f9bf*/ - ((static_cast<double>(/*@>1ddeca*/rtDW./*@>1ea3c0*/svdRsltVar)/*@>15fa63*/ + /*@>194c3e*/1.0)/*@>15f9bd*/ + /*@>194bfc*/1.0)/*@>196ca6*/ * /*@>194bfd*/24.0;
        /*@>1ddefa*/rtDW./*@>1ea3d8*/win_y_high/*@>15f99f*/ = /*@>1ddf00*/rtDW./*@>1ea3db*/bestInlierDis/*@>15f9c1*/ - (static_cast<double>(/*@>1ddf06*/rtDW./*@>1ea3de*/svdRsltVar)/*@>15fa67*/ + /*@>194c41*/1.0)/*@>196c9f*/ * /*@>194c05*/24.0;
        /*@>1ddf48*/rtDW./*@>1ea3f6*/j/*@>1bbdd2*/ = rtDW.ii_size;
        rtDW.jj_size_b/*@>17dc03*/ = rtDW.ii_size;
/*@>17dc27*/        for (/*@>1e8322*/rtDW./*@>1ea7f5*/i = /*@>1e8320*/0; /*@>1e8337*/rtDW./*@>1ea7fe*/i < /*@>1e8332*/rtDW./*@>1ea7fb*/j; /*@>1e832c*/rtDW./*@>1ea7f8*/i/*@>1e886f*/++) {
            /*@>1de020*/rtDW./*@>1ea44a*/jj_data/*@>17dc14*/[/*@>1de026*/rtDW./*@>1ea44d*/i]/*@>17dc15*/ = /*@>1de02c*/rtDW./*@>1ea450*/ii_data_n/*@>1da3e8*/[/*@>1de032*/rtDW./*@>1ea453*/i];
        }
        /*@>1de056*/rtDW./*@>1ea465*/outputImage_tmp/*@>1adf7e*/ = rtDW.jj_size;
        rtDW.ii_size_n/*@>17dcb5*/ = rtDW.jj_size;
/*@>17dcd9*/        for (/*@>1e8303*/rtDW./*@>1ea7e9*/i = /*@>1e8301*/0; /*@>1e8318*/rtDW./*@>1ea7f2*/i < /*@>1e8313*/rtDW./*@>1ea7ef*/outputImage_tmp; /*@>1e830d*/rtDW./*@>1ea7ec*/i/*@>1e8870*/++) {
            /*@>1de14c*/rtDW./*@>1ea4d7*/ii_data/*@>17dcc6*/[/*@>1de152*/rtDW./*@>1ea4da*/i]/*@>17dcc7*/ = /*@>1de158*/rtDW./*@>1ea4dd*/jj_data_p/*@>1da40f*/[/*@>1de15e*/rtDW./*@>1ea4e0*/i];
        }
        if (rtDW.ii_size == rtDW.jj_size) {
            rtDW.c_size/*@>17dfcc*/ = rtDW.ii_size;
/*@>17dffe*/            for (/*@>1e82e4*/rtDW./*@>1ea7dd*/i = /*@>1e82e2*/0; /*@>1e82f9*/rtDW./*@>1ea7e6*/i < rtDW.j; /*@>1e82ee*/rtDW./*@>1ea7e0*/i/*@>1e8871*/++) {
                /*@>1de23c*/rtDW./*@>1ea540*/outputImage_tmp/*@>188ba8*/ = static_cast<int32_t>(/*@>1de242*/rtDW./*@>1ea543*/jj_data/*@>1da421*/[/*@>1de248*/rtDW./*@>1ea546*/i]);
                /*@>1de26c*/rtDW./*@>1ea555*/c_data/*@>17dfeb*/[/*@>1de272*/rtDW./*@>1ea558*/i]/*@>17dfec*/ = ((/*@>1de278*/rtDW./*@>1ea55b*/outputImage_tmp/*@>17dfd1*/ >= /*@>1de27e*/rtDW./*@>1ea55e*/win_y_low)/*@>17dfd0*/ && (/*@>1de284*/rtDW./*@>1ea561*/outputImage_tmp/*@>17dfd8*/ < /*@>1de28a*/rtDW./*@>1ea564*/win_y_high)/*@>17dfcf*/ && (/*@>1de290*/rtDW./*@>1ea567*/ii_data/*@>1da42d*/[/*@>1de296*/rtDW./*@>1ea56a*/i]/*@>17dfdf*/ >= /*@>1de29c*/rtDW./*@>1ea56d*/x_current/*@>1a51c4*/ - /*@>1a51c7*/40.0));
            }
        } else {
            /*@[1e5a57*/binary_expand_op_1(/*@>1eb006*/rtDW./*@>1eb005*/c_data, &rtDW.c_size, /*@>1eb027*/rtDW./*@>1eb026*/jj_data, &rtDW.jj_size_b, /*@>1eb048*/rtDW./*@>1eb047*/win_y_low, /*@>1eb058*/rtDW./*@>1eb057*/win_y_high, /*@>1eb068*/rtDW./*@>1eb067*/ii_data, &rtDW.ii_size_n, /*@>1eb089*/rtDW./*@>1eb088*/x_current)/*@]*/;
        }
        /*@>1de200*/rtDW./*@>1ea522*/j/*@>1bbdde*/ = rtDW.jj_size;
        rtDW.d_size/*@>17e0ec*/ = rtDW.jj_size;
/*@>17e10e*/        for (/*@>1e82c5*/rtDW./*@>1ea7d1*/i = /*@>1e82c3*/0; /*@>1e82da*/rtDW./*@>1ea7da*/i < rtDW.j; /*@>1e82cf*/rtDW./*@>1ea7d4*/i/*@>1e8873*/++) {
            /*@>1de2fc*/rtDW./*@>1ea597*/d_data/*@>17e0fb*/[/*@>1de302*/rtDW./*@>1ea59a*/i]/*@>17e0fc*/ = (/*@>1de308*/rtDW./*@>1ea59d*/ii_data/*@>1da433*/[/*@>1de30e*/rtDW./*@>1ea5a0*/i]/*@>17e0ef*/ < /*@>1de314*/rtDW./*@>1ea5a3*/x_current/*@>1a51ca*/ + /*@>1a51cd*/40.0);
        }
        if (rtDW.c_size == rtDW.jj_size) {
            /*@>1de374*/rtDW./*@>1ea5d0*/j/*@>1bbde8*/ = rtDW.c_size;
            rtDW.tmp_size_dy/*@>17e2dc*/ = rtDW.c_size;
/*@>17e304*/            for (/*@>1e82a6*/rtDW./*@>1ea7c5*/i = /*@>1e82a4*/0; /*@>1e82bb*/rtDW./*@>1ea7ce*/i < rtDW.j; /*@>1e82b0*/rtDW./*@>1ea7c8*/i/*@>1e8874*/++) {
                /*@>1de41c*/rtDW./*@>1ea618*/tmp_data_bj/*@>17e2f1*/[/*@>1de422*/rtDW./*@>1ea61b*/i]/*@>17e2f2*/ = (/*@>1de428*/rtDW./*@>1ea61e*/c_data/*@>1da44b*/[/*@>1de42e*/rtDW./*@>1ea621*/i]/*@>17e2df*/ && /*@>1de434*/rtDW./*@>1ea624*/d_data/*@>1da451*/[/*@>1de43a*/rtDW./*@>1ea627*/i]);
            }
        } else {
            /*@[1e5a73*/and_o(/*@>1eb099*/rtDW./*@>1eb098*/tmp_data_bj, &rtDW.tmp_size_dy, /*@>1eb0ba*/rtDW./*@>1eb0b9*/c_data, &rtDW.c_size, /*@>1eb0db*/rtDW./*@>1eb0da*/d_data, &rtDW.d_size)/*@]*/;
        }
        rtDW.outputImage_tmp = rtDW.tmp_size_dy - 1;
        rtDW.trueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
            if (/*@>1de458*/rtDW./*@>1ea633*/tmp_data_bj/*@>1da457*/[rtDW.i]) {
                rtDW.trueCount++;
            }
        }
        /*@>15f9e9*/if (rtDW.trueCount/*@>15f9c7*/ > /*@>194c18*/30) {
            if (rtDW.c_size == rtDW.jj_size) {
                /*@>1de4dc*/rtDW./*@>1ea669*/j/*@>1bbdf2*/ = rtDW.c_size;
                rtDW.tmp_size_o/*@>17e646*/ = rtDW.c_size;
/*@>17e66e*/                for (/*@>1e826b*/rtDW./*@>1ea7ad*/i = /*@>1e8269*/0; /*@>1e8280*/rtDW./*@>1ea7b6*/i < rtDW.j; /*@>1e8275*/rtDW./*@>1ea7b0*/i/*@>1e8877*/++) {
                    /*@>1de584*/rtDW./*@>1ea6b1*/tmp_data_f/*@>17e65b*/[/*@>1de58a*/rtDW./*@>1ea6b4*/i]/*@>17e65c*/ = (/*@>1de590*/rtDW./*@>1ea6b7*/c_data/*@>1da472*/[/*@>1de596*/rtDW./*@>1ea6ba*/i]/*@>17e649*/ && /*@>1de59c*/rtDW./*@>1ea6bd*/d_data/*@>1da478*/[/*@>1de5a2*/rtDW./*@>1ea6c0*/i]);
                }
            } else {
                /*@[1e5a8f*/and_o(/*@>1eb0fc*/rtDW./*@>1eb0fb*/tmp_data_f, &rtDW.tmp_size_o, /*@>1eb11d*/rtDW./*@>1eb11c*/c_data, &rtDW.c_size, /*@>1eb13e*/rtDW./*@>1eb13d*/d_data, &rtDW.d_size)/*@]*/;
            }
            rtDW.outputImage_tmp = rtDW.tmp_size_o - 1;
            rtDW.trueCount = 0;
            for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
                if (/*@>1de5b4*/rtDW./*@>1ea6c9*/tmp_data_f/*@>1da47e*/[rtDW.i]) {
                    rtDW.trueCount++;
                }
            }
            rtDW.tmp_size_idx_0 = rtDW.trueCount;
            rtDW.trueCount = 0;
            for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
                if (/*@>1de5e4*/rtDW./*@>1ea6d8*/tmp_data_f/*@>1da484*/[rtDW.i]) {
                    /*@>1de5fc*/rtDW./*@>1ea6e4*/tmp_data_d[rtDW.trueCount]/*@>17900b*/ = rtDW.i;
                    rtDW.trueCount++;
                }
            }
            rtDW.jj_size_b/*@>17e90f*/ = rtDW.tmp_size_idx_0;
/*@>17e948*/            for (/*@>1e8214*/rtDW./*@>1ea789*/i = /*@>1e8212*/0; /*@>1e8229*/rtDW./*@>1ea792*/i < rtDW.tmp_size_idx_0; /*@>1e821e*/rtDW./*@>1ea78c*/i/*@>1e887c*/++) {
                /*@>1de638*/rtDW./*@>1ea6fc*/jj_data/*@>17e935*/[/*@>1de63e*/rtDW./*@>1ea6ff*/i]/*@>17e936*/ = /*@>1de644*/rtDW./*@>1ea702*/jj_data_p/*@>1da493*/[/*@>1de64a*/rtDW./*@>1ea705*/tmp_data_d/*@>1da48d*/[/*@>1de650*/rtDW./*@>1ea708*/i]];
            }
            /*@>1de626*/rtDW./*@>1ea6f3*/x_current/*@>15f9a0*/ = /*@[1e5aa7*/mean(/*@>1eb15f*/rtDW./*@>1eb15e*/jj_data, &rtDW.jj_size_b)/*@]*/;
        }
        /*@>15f9ec*/if ((/*@>1de488*/rtDW./*@>1ea645*/win_y_low/*@>15f9c8*/ > /*@>194c1e*/300.0)/*@>15fb28*/ && (/*@>1de48e*/rtDW./*@>1ea648*/win_y_low/*@>15f9c9*/ < /*@>194c23*/340.0)) {
            /*@>1de4d0*/rtDW./*@>1ea663*/x_location/*@>15f9a4*/ = /*@>1de4d6*/rtDW./*@>1ea666*/x_current/*@>15f9ca*/ - /*@>194c29*/220.0;
        }
    } else {
        /*@>1ddeac*/rtDW./*@>1ea3b1*/win_y_low/*@>15f9a7*/ = /*@>1ddeb2*/rtDW./*@>1ea3b4*/bestInlierDis/*@>15f9ce*/ - ((static_cast<double>(/*@>1ddeb8*/rtDW./*@>1ea3b7*/svdRsltVar)/*@>15fa75*/ + /*@>194c44*/1.0)/*@>15f9cc*/ + /*@>194c0a*/1.0)/*@>196c98*/ * /*@>194c0b*/24.0;
        /*@>1ddee8*/rtDW./*@>1ea3cf*/win_y_high/*@>15f9a9*/ = /*@>1ddeee*/rtDW./*@>1ea3d2*/bestInlierDis/*@>15f9d0*/ - (static_cast<double>(/*@>1ddef4*/rtDW./*@>1ea3d5*/svdRsltVar)/*@>15fa79*/ + /*@>194c47*/1.0)/*@>196c91*/ * /*@>194c15*/24.0;
        /*@>1ddf1e*/rtDW./*@>1ea3e7*/outputImage_tmp/*@>1adf45*/ = rtDW.ii_size;
        if (rtDW.ii_size == rtDW.jj_size) {
            rtDW.c_size/*@>17df04*/ = rtDW.ii_size;
/*@>17df3f*/            for (/*@>1e81f5*/rtDW./*@>1ea77d*/i = /*@>1e81f3*/0; /*@>1e820a*/rtDW./*@>1ea786*/i < /*@>1e8205*/rtDW./*@>1ea783*/outputImage_tmp; /*@>1e81ff*/rtDW./*@>1ea780*/i/*@>1e887f*/++) {
                /*@>1de044*/rtDW./*@>1ea45c*/j/*@>188b77*/ = /*@>1de04a*/rtDW./*@>1ea45f*/ii_data_n/*@>1da3ee*/[/*@>1de050*/rtDW./*@>1ea462*/i];
                /*@>1de09e*/rtDW./*@>1ea486*/c_data/*@>17df2c*/[/*@>1de0a4*/rtDW./*@>1ea489*/i]/*@>17df2d*/ = ((/*@>1de0aa*/rtDW./*@>1ea48c*/j/*@>17df09*/ >= /*@>1de0b0*/rtDW./*@>1ea48f*/win_y_low)/*@>17df08*/ && (/*@>1de0b6*/rtDW./*@>1ea492*/j/*@>17df13*/ < /*@>1de0bc*/rtDW./*@>1ea495*/win_y_high)/*@>17df07*/ && (/*@>1de0c2*/rtDW./*@>1ea498*/jj_data_p/*@>1da403*/[/*@>1de0c8*/rtDW./*@>1ea49b*/i]/*@>17df1d*/ >= /*@>1de0ce*/rtDW./*@>1ea49e*/x_current/*@>1a516e*/ - /*@>1a5171*/40.0));
            }
        } else {
            /*@[1e5ac6*/binary_expand_op(/*@>1eb180*/rtDW./*@>1eb17f*/c_data, &rtDW.c_size, /*@>1eb1a1*/rtDW./*@>1eb1a0*/ii_data_n, &rtDW.ii_size, /*@>1eb1c2*/rtDW./*@>1eb1c1*/win_y_low, /*@>1eb1d2*/rtDW./*@>1eb1d1*/win_y_high, /*@>1eb1e2*/rtDW./*@>1eb1e1*/jj_data_p, &rtDW.jj_size, /*@>1eb203*/rtDW./*@>1eb202*/x_current)/*@]*/;
        }
        /*@>1de00e*/rtDW./*@>1ea444*/outputImage_tmp/*@>1adf6c*/ = rtDW.jj_size;
        rtDW.d_size/*@>17e072*/ = rtDW.jj_size;
/*@>17e097*/        for (/*@>1e81d6*/rtDW./*@>1ea771*/i = /*@>1e81d4*/0; /*@>1e81eb*/rtDW./*@>1ea77a*/i < /*@>1e81e6*/rtDW./*@>1ea777*/outputImage_tmp; /*@>1e81e0*/rtDW./*@>1ea774*/i/*@>1e8880*/++) {
            /*@>1de0f8*/rtDW./*@>1ea4b0*/d_data/*@>17e084*/[/*@>1de0fe*/rtDW./*@>1ea4b3*/i]/*@>17e085*/ = (/*@>1de104*/rtDW./*@>1ea4b6*/jj_data_p/*@>1da409*/[/*@>1de10a*/rtDW./*@>1ea4b9*/i]/*@>17e075*/ < /*@>1de110*/rtDW./*@>1ea4bc*/x_current/*@>1a5182*/ + /*@>1a5185*/40.0);
        }
        if (rtDW.c_size == rtDW.jj_size) {
            /*@>1de164*/rtDW./*@>1ea4e3*/j/*@>1bbdfc*/ = rtDW.c_size;
            rtDW.tmp_size_d/*@>17e242*/ = rtDW.c_size;
/*@>17e26a*/            for (/*@>1e81b7*/rtDW./*@>1ea765*/i = /*@>1e81b5*/0; /*@>1e81cc*/rtDW./*@>1ea76e*/i < rtDW.j; /*@>1e81c1*/rtDW./*@>1ea768*/i/*@>1e8881*/++) {
                /*@>1de20c*/rtDW./*@>1ea528*/tmp_data_e/*@>17e257*/[/*@>1de212*/rtDW./*@>1ea52b*/i]/*@>17e258*/ = (/*@>1de218*/rtDW./*@>1ea52e*/c_data/*@>1da415*/[/*@>1de21e*/rtDW./*@>1ea531*/i]/*@>17e245*/ && /*@>1de224*/rtDW./*@>1ea534*/d_data/*@>1da41b*/[/*@>1de22a*/rtDW./*@>1ea537*/i]);
            }
        } else {
            /*@[1e5ae2*/and_o(/*@>1eb213*/rtDW./*@>1eb212*/tmp_data_e, &rtDW.tmp_size_d, /*@>1eb234*/rtDW./*@>1eb233*/c_data, &rtDW.c_size, /*@>1eb255*/rtDW./*@>1eb254*/d_data, &rtDW.d_size)/*@]*/;
        }
        rtDW.outputImage_tmp = rtDW.tmp_size_d - 1;
        rtDW.trueCount = 0;
        for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
            if (/*@>1de254*/rtDW./*@>1ea54c*/tmp_data_e/*@>1da427*/[rtDW.i]) {
                rtDW.trueCount++;
            }
        }
        /*@>15f9f2*/if (rtDW.trueCount/*@>15f9d6*/ > /*@>194c1b*/30) {
            if (rtDW.c_size == rtDW.jj_size) {
                /*@>1de326*/rtDW./*@>1ea5ac*/j/*@>1bbe06*/ = rtDW.c_size;
                rtDW.tmp_size_lx/*@>17e5ab*/ = rtDW.c_size;
/*@>17e5d3*/                for (/*@>1e817c*/rtDW./*@>1ea74d*/i = /*@>1e817a*/0; /*@>1e8191*/rtDW./*@>1ea756*/i < rtDW.j; /*@>1e8186*/rtDW./*@>1ea750*/i/*@>1e8884*/++) {
                    /*@>1de3d4*/rtDW./*@>1ea5f7*/tmp_data_jz/*@>17e5c0*/[/*@>1de3da*/rtDW./*@>1ea5fa*/i]/*@>17e5c1*/ = (/*@>1de3e0*/rtDW./*@>1ea5fd*/c_data/*@>1da439*/[/*@>1de3e6*/rtDW./*@>1ea600*/i]/*@>17e5ae*/ && /*@>1de3ec*/rtDW./*@>1ea603*/d_data/*@>1da43f*/[/*@>1de3f2*/rtDW./*@>1ea606*/i]);
                }
            } else {
                /*@[1e5afe*/and_o(/*@>1eb276*/rtDW./*@>1eb275*/tmp_data_jz, &rtDW.tmp_size_lx, /*@>1eb297*/rtDW./*@>1eb296*/c_data, &rtDW.c_size, /*@>1eb2b8*/rtDW./*@>1eb2b7*/d_data, &rtDW.d_size)/*@]*/;
            }
            rtDW.outputImage_tmp = rtDW.tmp_size_lx - 1;
            rtDW.trueCount = 0;
            for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
                if (/*@>1de410*/rtDW./*@>1ea612*/tmp_data_jz/*@>1da445*/[rtDW.i]) {
                    rtDW.trueCount++;
                }
            }
            rtDW.tmp_size_idx_0 = rtDW.trueCount;
            rtDW.trueCount = 0;
            for (rtDW.i = 0; rtDW.i <= rtDW.outputImage_tmp; rtDW.i++) {
                if (/*@>1de4c4*/rtDW./*@>1ea65d*/tmp_data_jz/*@>1da45d*/[rtDW.i]) {
                    /*@>1de4f4*/rtDW./*@>1ea675*/tmp_data_j[rtDW.trueCount]/*@>178f59*/ = rtDW.i;
                    rtDW.trueCount++;
                }
            }
            rtDW.jj_size_b/*@>17e83b*/ = rtDW.tmp_size_idx_0;
/*@>17e874*/            for (/*@>1e8125*/rtDW./*@>1ea729*/i = /*@>1e8123*/0; /*@>1e813a*/rtDW./*@>1ea732*/i < rtDW.tmp_size_idx_0; /*@>1e812f*/rtDW./*@>1ea72c*/i/*@>1e8889*/++) {
                /*@>1de566*/rtDW./*@>1ea6a2*/jj_data/*@>17e861*/[/*@>1de56c*/rtDW./*@>1ea6a5*/i]/*@>17e862*/ = /*@>1de572*/rtDW./*@>1ea6a8*/jj_data_p/*@>1da46c*/[/*@>1de578*/rtDW./*@>1ea6ab*/tmp_data_j/*@>1da466*/[/*@>1de57e*/rtDW./*@>1ea6ae*/i]];
            }
            /*@>1de554*/rtDW./*@>1ea699*/x_current/*@>15f9aa*/ = /*@[1e5b16*/mean(/*@>1eb2d9*/rtDW./*@>1eb2d8*/jj_data, &rtDW.jj_size_b)/*@]*/;
        }
        /*@>15f9f5*/if ((/*@>1de2ba*/rtDW./*@>1ea579*/win_y_low/*@>15f9d7*/ > /*@>194c26*/300.0)/*@>15fb29*/ && (/*@>1de2c0*/rtDW./*@>1ea57c*/win_y_low/*@>15f9d8*/ < /*@>194c2e*/340.0)) {
            /*@>1de31a*/rtDW./*@>1ea5a6*/x_location/*@>15f9ae*/ = /*@>1de320*/rtDW./*@>1ea5a9*/x_current/*@>15f9d9*/ + /*@>194c31*/290.0;
        }
    }
    /*@>1de380*/rtDW./*@>1ea5d6*/win_y_low/*@>15f9b0*/ = /*@>194c10*/340.0/*@>15f9da*/ - /*@>1de386*/rtDW./*@>1ea5d9*/x_location;
}
/* Send event */
ProvidedPort->Error.Send(/*@>1ddea6*/rtDW./*@>1ea3ae*/win_y_low);






        



                




                    



        

            
            





        





        
                    


            




                


        } 
        
            
















    // Model initialize function
    
            void Rpi_cam::initialize()
    {
            


    




    
        

        



        











                {
            
int32_t i;
static const std::array<int8_t, 9> self_T{ { 1, 0, 0, 0, 1, 0, 0, 0, 1 } };

                                        
                                    

        

                

        

                

/* {S!d284}Start for S-Function (svipesttform): '<S4>/Estimate Geometric Transformation' */
/*@>1d3582*/srand(/*@>1d3580*/clock());
        

                

/* {S!d286}Start for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>1de66e*/rtDW./*@>1eb3f7*/obj./*@>1eb3d3*/matlabCodegenIsDeleted/*@>15fcad*/ = /*@>195786*/true;
/*@[1e5b44*/Raspiv4l2Capture_Raspiv4l2Capture(&/*@>1eb470*/rtDW./*@>1eb46f*/obj)/*@]*/;
/*@>1de67a*/rtDW./*@>1eb3fd*/obj./*@>1eb3eb*/Brightness/*@>15fcf6*/ = /*@>1957c0*/0.5;
/*@>1de680*/rtDW./*@>1eb400*/obj./*@>1eb3e8*/Saturation/*@>15fcf2*/ = /*@>1957c1*/0.5;
/*@>1de686*/rtDW./*@>1eb403*/obj./*@>1eb3e5*/Contrast/*@>15fcee*/ = /*@>1957c2*/0.5;
/*@>1de68c*/rtDW./*@>1eb406*/obj./*@>1eb3e2*/Sharpness/*@>15fcea*/ = /*@>1957c3*/0.5;
/*@>1de692*/rtDW./*@>1eb409*/obj./*@>1eb3df*/CameraPan/*@>15fce6*/ = /*@>1957c4*/0.0;
/*@>1de698*/rtDW./*@>1eb40c*/obj./*@>1eb3dc*/CameraTilt/*@>15fce2*/ = /*@>1957c5*/0.0;
/*@>1de69e*/rtDW./*@>1eb40f*/obj./*@>1eb3d9*/CameraZoom/*@>15fcde*/ = /*@>1957c6*/0.5;
/*@>1de6a4*/rtDW./*@>1eb412*/obj./*@>1eb3d6*/ManualFocus/*@>15fcda*/ = /*@>1957c7*/0.5;
/*@[1e5b2d*/SystemCore_setup(&/*@>1eb481*/rtDW./*@>1eb480*/obj)/*@]*/;
/* {S!d288}Start for MATLABSystem: '<S4>/Warp' */
/*@>1de6b0*/rtDW./*@>1eb418*/obj_k./*@>1eb3ee*/isInitialized/*@>15fd2c*/ = /*@>1eb34c*/1;
/*@>17ea46*/for (/*@>1eb354*/i = /*@>1eb353*/0; /*@>1eb35e*/i < /*@>1eb35c*/9; /*@>1eb35a*/i/*@>1eb362*/++) {
    /*@>1de6b6*/rtDW./*@>1eb41b*/obj_k./*@>1eb3f4*/TformProjective./*@>1eb3f1*/T/*@>17ea38*/[/*@>1957b3*/i]/*@>17ea39*/ = /*@>1da497*/self_T/*@>1da499*/[/*@>1da496*/i];
}
/* {E!d288}End of Start for MATLABSystem: '<S4>/Warp' */
/* Initialize service provider instance - ProvidedPort */
ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::com::InstanceIdentifier(ara::core::StringView("1")), ara::com::MethodCallProcessingMode::kEventSingleThread);
ProvidedPort->OfferService();









        }





    





                



        
    }        






        




        
        // Model terminate function
                    void Rpi_cam::terminate()

        {
            


                                                            




                        




                                                    

                        
                                    /* {S!d282}Terminate for MATLABSystem: '<Root>/V4L2 Video Capture' */
/*@>15fc21*/if (!/*@<15fc1f*//*@>1de656*/rtDW./*@>1eb327*/obj.matlabCodegenIsDeleted) {
    /*@>1de65c*/rtDW./*@>1eb32a*/obj./*@>1eb324*/matlabCodegenIsDeleted/*@>15fc1e*/ = /*@>19574f*/true;
    /*@>15fc27*/if ((/*@>1de662*/rtDW./*@>1eb32d*/obj.isInitialized/*@>15fc26*/ == /*@>19575c*/1)/*@>15fc36*/ && /*@>1de668*/rtDW./*@>1eb330*/obj.isSetupComplete) {
        /*@>1d3578*/EXT_webcamTerminate(/*@>1b001f*/0, /*@>1b0022*/0);
    }
}
/* {E!d282}End of Terminate for MATLABSystem: '<Root>/V4L2 Video Capture' */
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


    

    

    

    
