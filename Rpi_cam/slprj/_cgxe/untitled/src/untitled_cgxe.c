/* Include files */

#include "untitled_cgxe.h"
#include "m_sOaALxpPwWOVdZ1Z3G3ztH.h"
#include "m_gf0TIwITOD7VTlgu02dz9D.h"

unsigned int cgxe_untitled_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 3096557831 &&
      ssGetChecksum1(S) == 4173762615 &&
      ssGetChecksum2(S) == 3617398249 &&
      ssGetChecksum3(S) == 2546831998) {
    method_dispatcher_sOaALxpPwWOVdZ1Z3G3ztH(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3761562198 &&
      ssGetChecksum1(S) == 659894759 &&
      ssGetChecksum2(S) == 886051393 &&
      ssGetChecksum3(S) == 926690589) {
    method_dispatcher_gf0TIwITOD7VTlgu02dz9D(S, method, data);
    return 1;
  }

  return 0;
}
