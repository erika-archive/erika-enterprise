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
 * Author: 2011  Bernardo  Dal Seno
 *         2010  Fabio Checconi
 */

#include "ee_internal.h"

#ifdef EE_SUPPORT_MEMMAP_H
#define OS_START_SEC_STACK
#include "MemMap.h"
#endif /* EE_SUPPORT_MEMMAP_H */
EE_STACK_T EE_STACK_ATTRIB
	EE_e200zx_sys_stack[EE_STACK_WLEN(EE_SYS_STACK_SIZE)];
#ifdef EE_SUPPORT_MEMMAP_H
#define OS_STOP_SEC_STACK
#include "MemMap.h"
#endif /* EE_SUPPORT_MEMMAP_H */

#if (defined(__EE_MEMORY_PROTECTION__)) && (defined(OO_CPU_HAS_STARTOS_ROUTINE))
EE_TYPEBOOL EE_cpu_startos(void)
{
	EE_UREG i;
	for (i = 0U; i < EE_MAX_APP; i++) {
		EE_hal_app_init(&(EE_as_Application_ROM[i].sec_info));
	}
	EE_e200zx_fill_stacks();

	/* When the MMU is set up, access to an application space is permitted
	 * only if the CPU PID matches the application; so application memory is
	 * initialized before configuring the MMU. */
	EE_e200zx_mmu_setup(EE_hal_memprot_entries,
		EE_HAL_MEMPROT_ENTRIES(EE_MAX_APP));

	/* Initialize System Timer */
	EE_initialize_system_timer();
	return 0;
}
#endif /* __EE_MEMORY_PROTECTION__ && OO_CPU_HAS_STARTOS_ROUTINE */

#if (defined(EE_STACK_MONITORING__))

typedef void (*p_func) (void);

void EE_e200zx_fill_stacks ( void ) {
  EE_UREG i;
  EE_ADDR const sp = EE_e200zx_get_sp();
  {
    EE_STACK_T * p_end_stack = EE_e200zx_system_bos[0].SYS_tos;
    EE_STACK_T * p_stack     = EE_e200zx_system_bos[0].SYS_bos;
    if ( p_end_stack > sp ) {
      p_end_stack = sp;
    }
    /* Here I need p_stack to be stricly less than p_end_stack, because
       p_end_stack point to stack allocated memory location. */
    while ( p_stack < p_end_stack ) {
      (*p_stack) = EE_STACK_FILL_PATTERN;
      ++p_stack;
    }
  }
  for ( i = 1U; i < EE_E200Z7_SYSTEM_TOS_SIZE; ++i ) {
    EE_STACK_T * const p_end_stack = EE_e200zx_system_bos[i].SYS_tos;
    EE_STACK_T *       p_stack     = EE_e200zx_system_bos[i].SYS_bos;
    while ( p_stack <= p_end_stack ) {
      (*p_stack) = EE_STACK_FILL_PATTERN;
      ++p_stack;
    }
  }
#if (defined(__IRQ_STACK_NEEDED__))
  {
    EE_STACK_T * const p_end_stack = EE_e200z7_IRQ_tos.SYS_tos;
    EE_STACK_T *       p_stack     = EE_e200z7_IRQ_tos.SYS_bos;
    while ( p_stack <= p_end_stack ) {
      (*p_stack) = EE_STACK_FILL_PATTERN;
      ++p_stack;
    }
  }
#endif /* __IRQ_STACK_NEEDED__ */

#if (defined(EE_AS_PROTECTIONHOOK_HAS_STACK__))
  {
    EE_STACK_T * const p_end_stack = EE_e200z7_prot_hook_tos.SYS_tos;
    EE_STACK_T *       p_stack     = EE_e200z7_prot_hook_tos.SYS_bos;
    while ( p_stack <= p_end_stack ) {
      (*p_stack) = EE_STACK_FILL_PATTERN;
      ++p_stack;
    }
  }
#endif /* EE_AS_PROTECTIONHOOK_HAS_STACK__ */
}

extern void EE_e200zx_call_function_in_new_stack(EE_UREG param, p_func,
  EE_ADDR new_sp);

void EE_as_check_and_handle_stack_overflow( EE_UREG stktop )
{
  if ( EE_e200zx_check_stack_overflow(stktop) ) {
    /* Just be sure to handle the overflow with the interrupts disabled */
    EE_hal_disableIRQ();
#if (defined(EE_AS_HAS_PROTECTIONHOOK__))
#if (defined(EE_AS_PROTECTIONHOOK_HAS_STACK__))
    /* The stack is corrupted I have to switch to a new one.
       Actually I will use ISR stack, but probably this will change */
    EE_e200zx_call_function_in_new_stack(E_OS_STACKFAULT,
      EE_as_handle_protection_error, EE_e200z7_prot_hook_tos.SYS_tos);
#elif (defined(__IRQ_STACK_NEEDED__))
    /* The stack is corrupted I have to switch to a new one.
       I can use ISR stack, because as effect of ProtectionHook, I will
       Terminate the active ISR/TASK at least. */
    EE_e200zx_call_function_in_new_stack(E_OS_STACKFAULT,
      EE_oo_ShutdownOS_internal, EE_e200z7_IRQ_tos.SYS_tos);
#else
    EE_as_handle_protection_error(E_OS_STACKFAULT);
#endif /* EE_AS_PROTECTIONHOOK_HAS_STACK__ || __IRQ_STACK_NEEDED__ */
#else
#if (defined(__IRQ_STACK_NEEDED__))
    /* The stack is corrupted I have to switch to a new one.
       I can use ISR stack, because as effect of ProtectionHook, I will
       Terminate the active ISR/TASK at least. */
    EE_e200zx_call_function_in_new_stack(E_OS_STACKFAULT,
      EE_oo_ShutdownOS_internal, EE_e200z7_IRQ_tos.SYS_tos);
#else
    EE_oo_ShutdownOS_internal( E_OS_STACKFAULT );
#endif /* __IRQ_STACK_NEEDED__ */
#endif /* EE_AS_HAS_PROTECTIONHOOK__ */
  }
}

void EE_as_restore_stack_canary ( EE_UREG stktop ) {
  EE_UREG      i;
  EE_STACK_T * p_end_stack;
#if (!defined(EE_AS_OSAPPLICATIONS__)) && (defined(__IRQ_STACK_NEEDED__))
  if ( stktop == ((EE_UREG)-1) ) {
    p_end_stack = (EE_STACK_T *)EE_e200z7_IRQ_tos.SYS_bos;
  } else
#endif /* !EE_AS_OSAPPLICATIONS__ && __IRQ_STACK_NEEDED__ */
  {
    p_end_stack = (EE_STACK_T *)EE_e200zx_system_bos[stktop].SYS_bos;
  }

  for ( i = 0; i < EE_STACK_WORDS_CHECK; ++i ) {
    p_end_stack[i] = EE_STACK_FILL_PATTERN;
  }
}

#endif /* EE_STACK_MONITORING__ */


#ifdef __EE_MEMORY_PROTECTION__
/*
 * MISRA NOTE: This function is a workaround to provide
 * the capability to access arrays as a real arrays
 * although it is declared as pointer.
 * This solution prevents from misra error:
 * "pointer arithmetic by increment or decrement used"
 */
#if defined(RTDRUID_CONFIGURATOR_NUMBER) \
 && (RTDRUID_CONFIGURATOR_NUMBER >= RTDRUID_CONFNUM_STACK_IN_APP_SEC_INFO)
static void copy_mem(EE_UINT32 dest_data[], const EE_UINT32 *dest_end, \
		const EE_UINT32 src_data[], EE_UINT32 bss[], \
                const EE_UINT32 *bss_end, EE_UINT32 stack[], \
                const EE_UINT32 *stack_end)
#else
static void copy_mem(EE_UINT32 dest_data[], const EE_UINT32 *dest_end, \
		const EE_UINT32 src_data[], EE_UINT32 bss[], \
                const EE_UINT32 bss_end[])
#endif
{
	EE_UINT32 i = 0U;
        if ((dest_end != NULL) && (bss_end != NULL)) {
	        while (&dest_data[i] < dest_end) {
		        dest_data[i] = src_data[i];
		        i++;
	        }

#if defined(RTDRUID_CONFIGURATOR_NUMBER) \
 && (RTDRUID_CONFIGURATOR_NUMBER >= RTDRUID_CONFNUM_STACK_IN_APP_SEC_INFO)
                i = 0U;
                if (stack_end != NULL) {
                        while (&stack[i] < stack_end) {
                                /* Stack fill pattern */
		                stack[i] = 0xa5a5a5a5U;
		                i++;
	                }
                }
#endif

	        i = 0U;
	        while (&bss[i] < bss_end) {
		        bss[i] = 0U;
		        i++;
	        }
        }
}

void EE_hal_app_init(const EE_APP_SEC_INFO_T *app_info)
{
	const EE_UINT32 *src_data;
	EE_UINT32 *dest_data;
	const EE_UINT32 *dest_end;
	EE_UINT32 *bss;
	const EE_UINT32 *bss_end;

	EE_UINT32 *stack_start;
        const EE_UINT32 *stack_end;

	if (app_info != NULL) {
		src_data = (const EE_UINT32 *)(app_info->data_flash);
		dest_data = (EE_UINT32 *)(app_info->data_ram);
		dest_end = (EE_UINT32 *)(app_info->bss_start);

		bss = (EE_UINT32 *)(app_info->bss_start);
		bss_end = (EE_UINT32 *)(app_info->bss_end);
#if defined(RTDRUID_CONFIGURATOR_NUMBER) \
 && (RTDRUID_CONFIGURATOR_NUMBER >= RTDRUID_CONFNUM_STACK_IN_APP_SEC_INFO)
                stack_start = (EE_UINT32 *)(app_info->stack_start);
                stack_end = (EE_UINT32 *)(app_info->data_ram);
                copy_mem(dest_data, dest_end, src_data, bss, bss_end, \
                                stack_start, stack_end);
#else
		copy_mem(dest_data, dest_end, src_data, bss, bss_end);
#endif
	}
}
#endif /* __EE_MEMORY_PROTECTION__ */

/*
 * MMU setup
 *
 * MMU is normally initialized by BAM.  A different configuration can be
 * programmed with EE_e200zx_mmu_setup().
 */

#ifdef __EE_USE_MMU__

#define MMU_MAS0	624
#define MMU_MAS1	625
#define MMU_MAS2	626
#define MMU_MAS3	627


#ifdef __DCC__

__asm volatile void mmu_write_mas(EE_SREG mas, EE_UREG val)
{
% reg val; con mas;
!
	mtspr	mas, val
}

__asm volatile void mmu_write_sync(void)
{
!
	tlbwe
	isync
}

#else /* if __DCC__ */

#define mmu_write_mas(mas, val) asm volatile ("mtspr	(" \
	EE_PREPROC_STRING(mas) "), %0" : : "r"(val))

__INLINE__ void __ALWAYS_INLINE__ mmu_write_sync(void)
{
	asm volatile ("tlbwe	\n\t"
		"isync");
}

#endif /* else if __DCC__ */


void EE_e200zx_mmu_setup(const EE_MMU_ENTRY_T entries[], EE_UREG count)
{
	EE_UREG i;

	for (i = 0U; i < count; i++) {
		mmu_write_mas(MMU_MAS0, EE_E200ZX_MMU_TLBSEL1 | (i << 16));
		mmu_write_mas(MMU_MAS1, entries[i].mas1);
		mmu_write_mas(MMU_MAS2, entries[i].mas2);
		mmu_write_mas(MMU_MAS3, entries[i].mas3);
		mmu_write_sync();
	}
}

#endif /* __EE_USE_MMU__ */
