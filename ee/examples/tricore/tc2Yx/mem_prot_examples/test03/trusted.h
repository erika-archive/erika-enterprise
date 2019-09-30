#ifndef TRUSTED_H
#define TRUSTED_H

#include "ee.h"

void TRUSTED_MyTaskTrustedService(TrustedFunctionIndexType index,
  TrustedFunctionParameterRefType ref);
void TRUSTED_MyIsrTrustedService(TrustedFunctionIndexType index,
  TrustedFunctionParameterRefType ref);

#endif /* TRUSTED_H */
