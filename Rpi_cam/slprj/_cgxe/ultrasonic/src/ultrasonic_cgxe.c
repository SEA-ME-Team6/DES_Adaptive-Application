/* Include files */

#include "ultrasonic_cgxe.h"
#include "m_KfxEnyUMbeaOYicAxfslDF.h"

unsigned int cgxe_ultrasonic_method_dispatcher(SimStruct* S, int_T method, void*
  data)
{
  if (ssGetChecksum0(S) == 2646544621 &&
      ssGetChecksum1(S) == 2841598840 &&
      ssGetChecksum2(S) == 1088234895 &&
      ssGetChecksum3(S) == 2607690963) {
    method_dispatcher_KfxEnyUMbeaOYicAxfslDF(S, method, data);
    return 1;
  }

  return 0;
}
