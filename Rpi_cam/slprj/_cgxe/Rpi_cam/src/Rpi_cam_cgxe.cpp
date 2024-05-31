/* Include files */

#include "Rpi_cam_cgxe.hpp"
#include "m_uoiFwOpYbmSgDtdnhR8aM.hpp"

unsigned int cgxe_Rpi_cam_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 144465007 &&
      ssGetChecksum1(S) == 3324633204 &&
      ssGetChecksum2(S) == 639695094 &&
      ssGetChecksum3(S) == 2803130862) {
    method_dispatcher_uoiFwOpYbmSgDtdnhR8aM(S, method, data);
    return 1;
  }

  return 0;
}
