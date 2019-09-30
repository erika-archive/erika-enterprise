#include "test.h"
#include "trusted.h"

#define SHARED_START_SEC_VAR_NOINIT
#include "MemMap.h"
extern EE_UREG volatile sync_shutdown_asserts;
#define SHARED_STOP_SEC_VAR_NOINIT
#include "MemMap.h"

int main ( void ) {
  StartOS(DONOTCARE);
  return 0;
}

/* User inteface */
void CallSignalShutdown ( void )
{
  (void)CallTrustedFunction(EE_ID_TRUSTED_SignalShutdown, NULL);
}

void TRUSTED_SignalShutdown (TrustedFunctionIndexType index,
  TrustedFunctionParameterRefType ref)
{
  sync_shutdown_asserts = 0U;
  return;
}

EE_TYPEASSERTVALUE EE_assertions[15];

#define APP_AppCore1_START_SEC_CODE
#define APP_AppCore1_START_SEC_DATA
#include "MemMap.h"

static int assert_count = EE_ASSERT_NIL;

#define APP_AppCore1_STOP_SEC_DATA
#include "MemMap.h"
#define APP_AppCore1_START_SEC_VAR_NOINIT
#include "MemMap.h"

void test_assert(int test)
{
  register int next_assert;
  next_assert = (assert_count == EE_ASSERT_NIL) ? 1 : assert_count + 1;
  EE_assert(next_assert, test, EE_ASSERT_NIL);
  assert_count = next_assert;
}

EE_UREG volatile std_activated;
EE_UREG volatile ext_activated;

EE_UREG volatile core1App_startup;

TASK(TaskCore1Restart) {
  test_assert(core1App_startup == 1U);
#ifdef EE_TEST_TASK_IN_EXECUTION_TERMINATION
  test_assert(std_activated == 3U);
#else  /* EE_TEST_TASK_IN_EXECUTION_TERMINATION */
  test_assert(std_activated <= 3U);
#endif /* EE_TEST_TASK_IN_EXECUTION_TERMINATION */
  test_assert(ext_activated == 1U);

  test_assert(ActivateTask(TaskCore1Restart) == E_OS_LIMIT);
  test_assert(ActivateTask(TaskCore1ExtPrio2) == E_OK);
  while ( sync_shutdown_asserts == 0U )
    ;
  AllowAccess();
  CallSignalShutdown();
  TerminateTask();
}

TASK(TaskCore1StdPrio1) {
  ++std_activated;
  EE_tc2Yx_delay(100);
#ifndef EE_TEST_TASK_IN_EXECUTION_TERMINATION
  error();
#endif /* !EE_TEST_TASK_IN_EXECUTION_TERMINATION */
  TerminateTask();
}

TASK(TaskCore1ExtPrio2) {
  ++ext_activated;
  while ( 1 ) {
    WaitEvent(EventCore1);
    ClearEvent(EventCore1); /* Never Reached: Just as reminder */
    error();
  }
  TerminateTask();
}


void StartupHook_AppCore1( void )
{
  test_assert(GetApplicationID() == AppCore1);
  ++core1App_startup;
}

void ShutdownHook_AppCore1( StatusType Error )
{
  test_assert(GetApplicationID() == AppCore1);
  test_assert(core1App_startup == 1U);
#ifdef EE_TEST_TASK_IN_EXECUTION_TERMINATION
  test_assert(std_activated == 6U);
  test_assert(ext_activated == 2U);
#else  /* EE_TEST_TASK_IN_EXECUTION_TERMINATION */
  test_assert(std_activated <= 6U);
  test_assert(ext_activated <= 2U);
#endif /* EE_TEST_TASK_IN_EXECUTION_TERMINATION */

  EE_assert_range(0, 1, assert_count);
  EE_assert_last();
}

#define APP_AppCore1_STOP_SEC_CODE
#define APP_AppCore1_STOP_SEC_VAR_NOINIT
#include "MemMap.h"
