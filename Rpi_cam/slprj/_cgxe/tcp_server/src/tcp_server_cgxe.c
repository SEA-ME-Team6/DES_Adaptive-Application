/* Include files */

#include "tcp_server_cgxe.h"
#include "m_Qq05ylQy9Qam86tXzLIPdH.h"

unsigned int cgxe_tcp_server_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 2346021272 &&
      ssGetChecksum1(S) == 31520438 &&
      ssGetChecksum2(S) == 1856143253 &&
      ssGetChecksum3(S) == 2170167853) {
    method_dispatcher_Qq05ylQy9Qam86tXzLIPdH(S, method, data);
    return 1;
  }

  return 0;
}
