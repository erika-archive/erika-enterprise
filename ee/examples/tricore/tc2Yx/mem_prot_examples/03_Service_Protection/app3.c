#include "test.h"
#include "trusted.h"

TASK(TaskApp3Prio1)
{
  test_assert(test_service_protection(E_OS_ACCESS));
  test_assert(AllowAccess() == E_OK);
  test_assert(ActivateTask(TaskApp3Prio2) == E_OK);
  TerminateTask();
}

TASK(TaskApp3Prio2)
{
/*#define APP_App3_START_SEC_VAR_NOINIT
#include "MemMap.h" */
  static unsigned int count;
/*#define APP_App3_STOP_SEC_VAR_NOINIT
#include "MemMap.h"*/

  ++count;
  if ( count == 1U ) {
    test_assert(ActivateTask(TaskApp2Prio2) == E_OK);
    TerminateTask();
    error();
  } else if ( count == 2U ){
    test_assert(ActivateTask(TaskApp2Prio2) == E_OS_LIMIT);
    IncrementCounter(CounterApp3);
    TerminateTask();
    error();
  } else {
    error();
  }
  TerminateTask();
}

#if 0
#define APP_App3_START_SEC_CODE
#include "MemMap.h"
#endif

/* User inteface */
void CallGetApp3CounterValue(TickRefType App3CntValue)
{
  (void)CallTrustedFunction(EE_ID_TRUSTED_GetApp3CounterValue, App3CntValue);
}

void TRUSTED_GetApp3CounterValue(TrustedFunctionIndexType index,
  TrustedFunctionParameterRefType ref)
{
  /* This is just to check that inside the TRUSTED function I can access
     TRUSTED memory, actually this is a concurrency bug. */
  static TickType trusted_mem_counter_value;

  (void)GetCounterValue(CounterApp3, &trusted_mem_counter_value);
  *(TickRefType)ref = trusted_mem_counter_value;

  return;
}

#if 0
#define APP_App3_START_SEC_CODE
#include "MemMap.h"
#endif
