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
 *         2012 Francesco Esposito
 */

#ifndef __INCLUDE_E200ZX_MULTICORE_H__
#define __INCLUDE_E200ZX_MULTICORE_H__

#ifdef __MSRP__

/** @brief Type for spinlocks: an ID */
typedef EE_UINT32 EE_TYPESPIN;

#ifdef __MPC5668G__
#include "mcu/freescale_mpc5668/inc/ee_dual.h"
#define EE_hal_spin_in EE_mpc5668_spin_in
#define EE_hal_spin_out EE_mpc5668_spin_out
#define EE_hal_IRQ_interprocessor_served(cpu) EE_mpc5668_ack_signal(cpu)
#define EE_hal_IRQ_interprocessor(cpu) EE_mpc5668_signal_cpu(cpu)
#define EE_E200ZX_INTER_IRQ_LEVEL(cpu) EE_MPC5668_INTER_IRQ_LEVEL(cpu)
/*#define EE_E200ZX_DUAL_SET_INT_PRIO(level, proc, pri) \
			EE_mpc5668_set_int_prio(level, proc, pri)*/

#elif defined (EE_MPC5643L)
#include "mcu/freescale_mpc5643l/inc/ee_dual.h"
#define EE_hal_spin_in EE_mpc5643l_spin_in
#define EE_hal_spin_out EE_mpc5643l_spin_out
#define EE_hal_IRQ_interprocessor_served(cpu) EE_mpc5643l_ack_signal(cpu)
#define EE_hal_IRQ_interprocessor(cpu) EE_mpc5643l_signal_cpu(cpu)
#define EE_E200ZX_INTER_IRQ_LEVEL(cpu) EE_MPC5643L_INTER_IRQ_LEVEL(cpu)
#define EE_hal_start_slave EE_mpc5643l_start_slave
/*******************************************************************************
                      HAL For Multicore Management
   (This should be placed in internal but inline implementation of GetCoreID
    Services need that this symbol is visible to user code).
 ******************************************************************************/
#define EE_hal_get_core_id() EE_e200zx_get_core_id()
/* proc not necessary for mpc5643l */
/*#define EE_E200ZX_DUAL_SET_INT_PRIO(level, proc, pri) \
			EE_mpc5643l_set_int_prio(level, pri)*/

#elif defined (EE_MPC5777C)
#include "mcu/freescale_mpc5777c/inc/ee_dual.h"
/* Notice that spinlocks for MPC5777C are based on PowerPC
reservation mechanism. For details please check EE_e200zx_spin_in() and
EE_e200zx_spin_out */
#define EE_hal_spin_in EE_e200zx_spin_in
#define EE_hal_try_to_spin_in EE_e200zx_try_to_spin_in
#define EE_hal_spin_out EE_e200zx_spin_out
#define EE_hal_IRQ_interprocessor_served(cpu) EE_mpc5777c_ack_signal(cpu)
#define EE_hal_IRQ_interprocessor(cpu) EE_mpc5777c_signal_cpu(cpu)
#define EE_E200ZX_INTER_IRQ_LEVEL(cpu) EE_MPC5777C_INTER_IRQ_LEVEL(cpu)
#define EE_hal_start_slave EE_mpc5777c_start_slave
/*******************************************************************************
                      HAL For Multicore Management
   (This should be placed in internal but inline implementation of GetCoreID
    Services need that this symbol is visible to user code).
 ******************************************************************************/
#define EE_hal_get_core_id() EE_e200zx_get_core_id()

#elif defined (EE_SPC574K)
#include "mcu/st_spc574k/inc/ee_dual.h"
/* Notice that default spinlocks for SPC574K are based on PowerPC
reservation mechanism. For details please check EE_e200zx_spin_in() and
EE_e200zx_spin_out. But reservation mechanism is not supported on K2,
therefore spinlocks are based on SEMA42 */
/* Use SEMA4 module */
#define EE_hal_spin_in EE_spc574k_spin_in
#define EE_hal_try_to_spin_in EE_spc574k_try_to_spin_in
#define EE_hal_spin_out EE_spc574k_spin_out
#define EE_hal_IRQ_interprocessor_served(cpu) EE_spc574k_ack_signal(cpu)
#define EE_hal_IRQ_interprocessor(cpu) EE_spc574k_signal_cpu(cpu)
#define EE_E200ZX_INTER_IRQ_LEVEL(cpu) EE_SPC574K_INTER_IRQ_LEVEL(cpu)
#define EE_hal_start_slave EE_spc574k_start_slave
/*******************************************************************************
                      HAL For Multicore Management
   (This should be placed in internal but inline implementation of GetCoreID
    Services need that this symbol is visible to user code).
 ******************************************************************************/
/* K2 has an unusual logic to define core IDs (2 for master/IOP and 0 for
slave/Core_0), hence pir register is not compatible with Erika internal
policy for core IDs. EE_CURRENTCPU is used instead pir! */
#define EE_hal_get_core_id() EE_CURRENTCPU

#endif /* __MPC5668G__ */

/* Setup mode for slave core */
#if defined(__VLE__)
#define SLAVE_START_MODE    VLE_MODE
#else
#define SLAVE_START_MODE    PPC_MODE
#endif

/* [OS583]: The number of cores that can be controlled by the AUTOSAR OS shall
    be configured offline.
    A new configuration item (OsNumberOfCores) within the "OsOS" container is
    used to specify the maximum number of cores that are controlled by the
    AUTOSAR OS. If no value for (OsNumberOfCores) has been specified the number
    of cores shall be one. (BSW4080001, BSW4080011)
    FIXME: This SHOULD NOT be here */
#define OsNumberOfCores   EE_NUMBER_OF_CORES

/*************************************************************************
 System startup
 *************************************************************************/

/** @brief ID type for cores */
typedef enum EE_tc_core_id {
  OS_CORE_ID_0 = 0x0,
  OS_CORE_ID_MASTER = OS_CORE_ID_0,
  OS_CORE_ID_1 = (OS_CORE_ID_MASTER + 0x1),
  INVALID_CORE_ID = ((EE_UINT8)-1)
} EE_TYPECOREID;

/** @brief Reference to a core ID */
typedef EE_TYPECOREID *       EE_TYPECOREIDREF;
typedef EE_TYPECOREID const * EE_TYPECOREIDCONSTREF;

/** @brief Get core Id by using special purpose register 286 (PIR) */
#ifdef __DCC__
__asm volatile static EE_TYPECOREID EE_e200zx_get_core_id(void)
{
! "r3"
	mfspr	r3, pir
}
#else /* if __DCC__ */
__INLINE__ EE_TYPECOREID __ALWAYS_INLINE__ EE_e200zx_get_core_id( void )
{
  EE_TYPECOREID pir;
/*
 * __asm volatile ("mfspr %0, pir" : "=r"(pir));
 * pir = 286
 */
  __asm volatile ("mfspr %0, 286" : "=r"(pir));
  return pir;
}
#endif

/** @brief start the core represented by id param from start_up_addr */
__INLINE__ void __ALWAYS_INLINE__ EE_e200zx_start_core( EE_TYPECOREID core_id,
    EE_ADDR start_up_addr)
{
  switch( core_id )
  {
    case OS_CORE_ID_0:
        /* Nothing to do in this case */
    break;

    case OS_CORE_ID_1:
#ifdef	EE_SPC574K
	EE_hal_start_slave((EE_UINT32)start_up_addr);
#else
        EE_hal_start_slave((EE_UINT32)start_up_addr, SLAVE_START_MODE);
#endif
    break;

    default:
    break;
  }
}

/*******************************************************************************
                        HAL For Multicore Startup
 ******************************************************************************/

__INLINE__ void __ALWAYS_INLINE__ EE_hal_start_core( EE_TYPECOREID core_id,
  EE_ADDR start_up_addr )
{
  EE_e200zx_start_core(core_id, start_up_addr);
}

typedef struct ee_barrier {
	volatile EE_UINT32 value;
} EE_TYPEBARRIER;

/** @brief HAL for core synchronization inside the Kernel */
void EE_hal_sync_barrier (
  EE_TYPEBARRIER *	bar,
  EE_UREG volatile *	p_wait_mask,
  EE_VOID_CALLBACK	p_cb
);

/*
 * New type added to allow RT-Druid providing the same generated
 * code for different architectures (using and not using this type)
 */
typedef EE_UINT32           EE_TYPESPINSTATUS;

#ifdef	__DCC__
/*
 * This implementation is taken from Book-E (C.1.1.5 and C.1.2)
 */
__asm volatile __INLINE__ void __ALWAYS_INLINE__ EE_e200zx_spin_in_impl
( EE_TYPESPINSTATUS * spinlock )
{
%   reg spinlock; lab lock, loop, done;
!   "r4", "r5"
lock:
    addi r4, r0, 1

loop:
    lwarx   r5, r0, spinlock
    cmpwi   r5, 0
	/*
	 * "-" can be removed from "bne" instruction if your CPU does not
	 * support static branch prediction.
	 */
    bne-    done
    stwcx.  r4, r0, spinlock
done:
	/* "-" can be removed as mentioned above */
    bne-    loop
    isync
}
#else
__INLINE__ void __ALWAYS_INLINE__ EE_e200zx_spin_in_impl
( EE_TYPESPINSTATUS * spinlock )
{
	register EE_UREG reg4;
	register EE_UREG reg5;
	/* __asm volatile ("lock: "); */
	__asm volatile ("1: ");
	__asm volatile ("	addi %0, r0, 1": "=r"(reg4));
	/* __asm volatile ("loop: "); */
	__asm volatile ("2: ");
	__asm volatile (
		"	lwarx   %0, r0, %1"
		: "=r"(reg5) : "r"(spinlock) : "memory"
	);
	__asm volatile ("	cmpwi   %0, 0" :: "r"(reg5));
	/*
	 * "-" can be removed from "bne" instruction if your CPU does not
	 * support static branch prediction.
	 */
	/* __asm volatile ("	bne-	done"); */
	__asm volatile ("	bne-	3f");
	__asm volatile (
		"	stwcx.  %0, r0, %1"
		:: "r"(reg4), "r"(spinlock) : "memory"
	);
	/* __asm volatile ("done: "); */
	__asm volatile ("3: ");
	/* "-" can be removed as mentioned above */
	/* __asm volatile ("	bne-    loop"); */
	__asm volatile ("	bne-    2b");
	__asm volatile ("	isync");
}
#endif

#ifdef	__DCC__
/*
 * This implementation is taken from Book-E (C.1.1.5 and C.1.2)
 */
__asm volatile static void EE_e200zx_spin_out_impl
( EE_TYPESPINSTATUS * spinlock )
{
%	reg spinlock;
! "r5"

	msync
	li  r5, 0
	stw r5, 0(spinlock)
}
#else
__INLINE__ void __ALWAYS_INLINE__ EE_e200zx_spin_out_impl
( EE_TYPESPINSTATUS * spinlock )
{
	const EE_UREG reg = 0;
	__asm volatile ("msync");
	__asm volatile ("stw %0, 0(%1)" :: "r"(reg), "r"(spinlock):"memory");
}
#endif

#ifdef EE_SUPPORT_MEMMAP_H
#define SHARED_START_SEC_VAR_DATA
#include "MemMap.h"
#endif /* EE_SUPPORT_MEMMAP_H */
/* Global shared variables used as real spin locks */
extern EE_TYPESPINSTATUS EE_SHARED_IDATA
	EE_hal_spinlock_status[EE_MAX_SPINLOCK];
#ifdef EE_SUPPORT_MEMMAP_H
#define SHARED_STOP_SEC_VAR_DATA
#include "MemMap.h"
#endif /* EE_SUPPORT_MEMMAP_H */

/* Spinlocks Trivial Implementation */
/** @brief Acquire a spinlock, spin inside if the spinlock is already busy.
    @param spin_id Spinlock to be aquired id.
 */
__INLINE__ void __ALWAYS_INLINE__ EE_e200zx_spin_in( EE_TYPESPIN spin_id )
{
	EE_e200zx_spin_in_impl(&EE_hal_spinlock_status[spin_id]);
}

/** @brief Release a spin lock
    @param spin_id Spinlock to be released id */
__INLINE__ void __ALWAYS_INLINE__ EE_e200zx_spin_out
( EE_TYPESPIN spin_id )
{
	EE_e200zx_spin_out_impl(&EE_hal_spinlock_status[spin_id]);
}

#ifdef	__DCC__
__asm volatile __INLINE__ EE_BIT __ALWAYS_INLINE__ EE_e200zx_try_to_spin_in_impl
( EE_TYPESPINSTATUS * spinlock )
{
%	reg spinlock; lab lock, lock_fail, lock_success, loop, exit;
!       "r3", "r4", "r5"

lock:
	addi r4, r0, 1

loop:
	lwarx   r5, r0, spinlock
	cmpwi   r5, 0
	/* "-" can be removed as mentioned above */
    bne-    lock_fail
    stwcx.  r4, r0, spinlock
	/* "-" can be removed as mentioned above */
	bne-    loop
	b		lock_success

/* return 0 if spinlock has not been acquired */
lock_fail:
    isync
	li r3, 0
	b exit

/* return 1 if spinlock has been acquired */
lock_success:
	isync
	li r3, 1

exit:
}
#else
__INLINE__ EE_BIT __ALWAYS_INLINE__ EE_e200zx_try_to_spin_in_impl
( EE_TYPESPINSTATUS * spinlock )
{
	register EE_UREG reg3;
	register EE_UREG reg4;
	register EE_UREG reg5;
	__asm volatile("lock: ");
	__asm volatile("	addi %0, r0, 1" : "=r"(reg4));
	__asm volatile("loop: ");
	__asm volatile(
		"	lwarx   %0, r0, %1"
		: "=r"(reg5) : "r"(spinlock) : "memory"
	);
	__asm volatile("	cmpwi   %0, 0" :: "r"(reg5));
	/* "-" can be removed as mentioned above */
	__asm volatile("	bne-    lock_fail");
	__asm volatile(
		"	stwcx.  %0, r0, %1"
		:: "r"(reg4),"r"(spinlock) : "memory"
	);
	/* "-" can be removed as mentioned above */
	__asm volatile("	bne-    loop");
	__asm volatile("	b	lock_success");
	/* return 0 if spinlock has not been acquired */
	__asm volatile("lock_fail: ");
	__asm volatile("	isync");
	__asm volatile("	li	%0, 0" : "=r"(reg3));
	__asm volatile("	b	exit");
	/* return 1 if spinlock has been acquired */
	__asm volatile("lock_success: ");
	__asm volatile("	isync");
	__asm volatile("	li	%0, 1" : "=r"(reg3));
	__asm volatile("exit: ");
	return (EE_BIT)reg3;
}
#endif

/** @brief Try to acquire a spinlock, immediatly exit if it is already busy.
    @param spin_id Spinlock to be aquired id.
 */
__INLINE__ EE_BIT __ALWAYS_INLINE__ EE_e200zx_try_to_spin_in
( EE_TYPESPIN spin_id )
{
  EE_BIT result;

  result = EE_e200zx_try_to_spin_in_impl(&EE_hal_spinlock_status[spin_id]);

  return result;
}

/* Synchronize on the given barrier.  Wait until all CPUs have called this
 * function on the same barrier. */
/* OLD STYLE SYNC BARRIER */
/*void EE_e200zx_sync_barrier(EE_TYPEBARRIER *bar);*/

/* Startup barrier data */
#ifdef EE_SUPPORT_MEMMAP_H
#define SHARED_START_SEC_VAR_NOINIT
#include "MemMap.h"
#endif /* EE_SUPPORT_MEMMAP_H */
extern EE_TYPEBARRIER EE_SHARED_UDATA EE_e200zx_start_barrier;
#ifdef EE_SUPPORT_MEMMAP_H
#define SHARED_STOP_SEC_VAR_NOINIT
#include "MemMap.h"
#endif /* EE_SUPPORT_MEMMAP_H */

/* Standard Name Mapping for kernel */
#define EE_startos_before_hook_barrier          EE_e200zx_start_barrier
#define EE_startos_before_scheduling_barrier    EE_e200zx_start_barrier
#define EE_shutdownos_barrier                   EE_e200zx_start_barrier

#endif /* __MSRP__ */

#endif /* __INCLUDE_E200ZX_MULTICORE_H__ */
