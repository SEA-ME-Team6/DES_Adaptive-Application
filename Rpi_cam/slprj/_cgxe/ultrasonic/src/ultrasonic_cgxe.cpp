/* Include files */

#include "ultrasonic_cgxe.hpp"
#include "m_Y0B9WgMUpDX622CpoG0hQE.hpp"

unsigned int cgxe_ultrasonic_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 101152690 &&
      ssGetChecksum1(S) == 1411129494 &&
      ssGetChecksum2(S) == 86953205 &&
      ssGetChecksum3(S) == 3029680075) {
    method_dispatcher_Y0B9WgMUpDX622CpoG0hQE(S, method, data);
    return 1;
  }

  return 0;
}
