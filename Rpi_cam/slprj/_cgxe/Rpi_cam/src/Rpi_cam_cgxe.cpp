/* Include files */

#include "Rpi_cam_cgxe.hpp"
#include "m_GaAvoJiJTOAF4Sj2d9vExG.hpp"

unsigned int cgxe_Rpi_cam_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 1819320267 &&
      ssGetChecksum1(S) == 234439674 &&
      ssGetChecksum2(S) == 4065568798 &&
      ssGetChecksum3(S) == 2105807742) {
    method_dispatcher_GaAvoJiJTOAF4Sj2d9vExG(S, method, data);
    return 1;
  }

  return 0;
}
