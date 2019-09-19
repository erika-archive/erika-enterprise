#ifndef SHARED_H
#define SHARED_H

#include <ee.h>
#include <ee_irq.h>
/* Assertions */
#include "test/assert/inc/ee_assert.h"

#ifndef FALSE
#define FALSE 0U
#endif /* FALSE */

#define TEST_WAIT 1000000U

void test_assert ( int test );

#define	SHARED_START_SEC_VAR_NOINIT
#include "MemMap.h"

extern EE_BIT volatile slave2_app_startup_flag;
extern EE_BIT volatile slave2_app_shutdown_flag;

#define	SHARED_STOP_SEC_VAR_NOINIT
#include "MemMap.h"

#endif /* SHARED_H */
