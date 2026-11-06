/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2011  Evidence Srl
 *
 * This file is part of ERIKA Enterprise.
 *
 * ERIKA Enterprise is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation,
 * (with a special exception described below).
 *
 * Linking this code statically or dynamically with other modules is
 * making a combined work based on this code.  Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 *
 * As a special exception, the copyright holders of this library give you
 * permission to link this code with independent modules to produce an
 * executable, regardless of the license terms of these independent
 * modules, and to copy and distribute the resulting executable under
 * terms of your choice, provided that you also meet, for each linked
 * independent module, the terms and conditions of the license of that
 * module.  An independent module is a module which is not derived from
 * or based on this library.  If you modify this code, you may extend
 * this exception to your version of the code, but you are not
 * obligated to do so.  If you do not wish to do so, delete this
 * exception statement from your version.
 *
 * ERIKA Enterprise is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with ERIKA Enterprise; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 * ###*E*### */

/*
 * Multicore support
 * Author: 2011 Bernardo  Dal Seno
 */

#include "ee_internal.h"
#include "cpu/e200zx/inc/ee_e200zx_irq.h"

/* Startup barrier data */
/* Variable definition only for master core */
#if (defined(EE_CURRENTCPU)) && (EE_CURRENTCPU == EE_SHARED_VAR_DEF_CORE)

#ifdef EE_SUPPORT_MEMMAP_H
#define SHARED_START_SEC_VAR_NOINIT
#include "MemMap.h"
#endif /* EE_SUPPORT_MEMMAP_H */
EE_TYPEBARRIER EE_SHARED_UDATA EE_e200zx_start_barrier;
#ifdef EE_SUPPORT_MEMMAP_H
#define SHARED_STOP_SEC_VAR_NOINIT
#include "MemMap.h"
#endif /* EE_SUPPORT_MEMMAP_H */

#endif /* EE_CURRENTCPU && EE_CURRENTCPU == EE_SHARED_VAR_DEF_CORE */

#if 0
void EE_e200zx_sync_barrier(EE_TYPEBARRIER *bar)
{
	EE_UINT32 all = ((EE_UINT32)1U << EE_MAX_CPU) - 1U;

	if (bar != NULL) {
		EE_hal_spin_in(0U);
		bar->value |= ((EE_UINT32)1U << EE_CURRENTCPU);
		EE_hal_spin_out(0U);
		while (bar->value != all) {
			; /* Wait for all other cores/CPUs */
		}
	}
}
#endif /* 0 - OLD STYLE SYNC BARRIER */

void EE_hal_sync_barrier(
  EE_TYPEBARRIER *	bar,
  EE_UREG volatile *	p_wait_mask,
  EE_VOID_CALLBACK	p_cb
)
{
  /* Not OK for MISRA: taken as reference
  EE_UINT32 const exit_mask  = (0xFFFFFFFFU << EE_MAX_CPU); */

  EE_UINT32 const exit_mask  = (0xFFFFFFFFU ^
    (((EE_UINT32)0x1U << EE_MAX_CPU) - 1U));

  EE_UINT32 wait_mask, all_exited;

  if ( (bar != NULL) && (p_wait_mask != NULL) ) {
    while( (bar->value & exit_mask) != 0U ) {
      /* If the barrier is still not completed exited: wait */
      if ( p_cb != NULL )
      {
        p_cb();
      }
    }
    /* I need a spinlock so I will reuse spinlock for core 0 */
    EE_hal_spin_in(EE_SPINLOCK_CORE0);
    /* Set current CPU as entered */
    bar->value |= ((EE_UINT32)1U << EE_CURRENTCPU);
    EE_hal_spin_out(EE_SPINLOCK_CORE0);
    do {
      if ( p_cb != NULL )
      {
        p_cb();
      }
      wait_mask = (*p_wait_mask);
      /* Wait for all other cores/CPUs */
    } while ( (bar->value & wait_mask) != wait_mask );

    all_exited = (wait_mask << EE_MAX_CPU) | wait_mask;
    EE_hal_spin_in(EE_SPINLOCK_CORE0);
    /* Set current CPU as exited */
    bar->value |= ((EE_UINT32)1U << (EE_MAX_CPU + EE_CURRENTCPU));
    /* This ensures subsequent "if" statement to work with coherent data */
    EE_e200zx_msync();
    if ( bar->value == all_exited ) {
      /* Reset the barrier */
      bar->value = 0U;
    }
    EE_hal_spin_out(EE_SPINLOCK_CORE0);
  }
}

#ifdef EE_ISR_DYNAMIC_TABLE
static void EE_e200zx_setup_inter_irqs(void)
{
	EE_e200z7_register_ISR(EE_E200ZX_INTER_IRQ_LEVEL(EE_CURRENTCPU),
		&EE_rn_handler, (EE_UINT8)1U);
}

static void EE_e200zx_iirq_handler(void)
{
#ifdef EE_AS_RPC__
  EE_as_rpc_handler();
#elif defined(__RN__)
  EE_rn_handler();
#endif /*  EE_AS_RPC__ || __RN__ */
}
#else /* EE_ISR_DYNAMIC_TABLE */

/* STATIC ISR TABLE IMPLEMENTATION */
#define EE_e200zx_setup_inter_irqs()  ((void)0)
/* Declare ISR handler */
void EE_e200zx_iirq_handler(void);

ISR2 (EE_e200zx_iirq_handler)
{
#ifdef EE_AS_RPC__
  EE_as_rpc_handler();
#elif defined(__RN__)
  EE_rn_handler();
#endif /*  EE_AS_RPC__ || __RN__ */
}
#endif /* EE_ISR_DYNAMIC_TABLE */

EE_TYPEBOOL EE_cpu_startos(void)
{
    EE_e200zx_fill_stacks();
    EE_e200zx_setup_inter_irqs();

/* Used only if system timer is required by the application */
#if defined(ENABLE_SYSTEM_TIMER) && defined(EE_SYSTEM_TIMER_DEVICE)
    EE_initialize_system_timer();
#endif

    return 0;
}
