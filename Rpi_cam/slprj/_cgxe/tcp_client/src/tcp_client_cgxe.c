/* Include files */

#include "tcp_client_cgxe.h"
#include "m_gf0TIwITOD7VTlgu02dz9D.h"

unsigned int cgxe_tcp_client_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 3761562198 &&
      ssGetChecksum1(S) == 659894759 &&
      ssGetChecksum2(S) == 886051393 &&
      ssGetChecksum3(S) == 926690589) {
    method_dispatcher_gf0TIwITOD7VTlgu02dz9D(S, method, data);
    return 1;
  }

  return 0;
}
