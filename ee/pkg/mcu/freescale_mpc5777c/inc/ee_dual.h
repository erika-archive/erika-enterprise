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
 * Dual-core interfacing code for MPC5777C
 * Author: 2014 Francesco Esposito
 */

#ifndef EE_MCU_MPC5777C_DUAL_H
#define EE_MCU_MPC5777C_DUAL_H

#include "ee_mpc5777c.h"

/* The following are added here to fulfill some Autosar kernel requirements that
   are architecture dependent */

#define EE_NUMBER_OF_CORES    2

/** @brief The following macros MAY be redefined by a user that want use
      custom startup code (setting the EEOPT=EE_USE_CUSTOM_STARTUP_CODE in OIL
      file) to tell the kernel Start(NonAutosar)Core which is the core start
      address */
#ifndef EE_CPU1_START_ADDR
#define EE_CPU1_START_ADDR  EE_e200zx_cpu1_start
#endif  /* EE_CPU1_START_ADDR */

#define VLE_MODE 0x2U
#define PPC_MODE 0x0U

/* This register contains the reset vector, reset control and instruction
execution type selection for Core1 */
#define SIU_RSTVEC1 0xC3F909B0U

/* First software IRQ used for interprocessor communication  */
#define EE_MPC5777C_INTER_IRQ_BASE 6U
/* Position in VBA of the first interprocessor IRQ */
#define EE_MPC5777C_INTER_IRQ_VBA_BASE EE_MPC5777C_INTER_IRQ_BASE
/* Interprocessor IRQ vector number, from CPU id */
#define EE_MPC5777C_INTER_IRQ_LEVEL(cpu) \
	((EE_SREG)(cpu) + EE_MPC5777C_INTER_IRQ_VBA_BASE + 16)

#if defined (EE_ISR_DYNAMIC_TABLE)
/* Setup the intercore IRQs used by ERIKA for multicore support */
__INLINE__ void EE_mpc5777c_setup_inter_irqs(void)
{
    INTC_PSR(EE_MPC5777C_INTER_IRQ_BASE) = 0x01U;
    INTC_PSR(EE_MPC5777C_INTER_IRQ_BASE + 1U) = 0xC1U;
}
#endif

/* Signal the core `cpu' (0/1) by sending an IIRQ */
__INLINE__ void EE_mpc5777c_signal_cpu(EE_UINT8 cpu)
{
    INTC_SSCIR(EE_MPC5777C_INTER_IRQ_BASE + (EE_UINT32)cpu) = 0x2U;
}

/* Acknowledge the signal riceved by the core `cpu' (0/1) */
__INLINE__ void EE_mpc5777c_ack_signal(EE_UINT8 cpu)
{
    INTC_SSCIR(EE_MPC5777C_INTER_IRQ_BASE + (EE_UINT32)cpu) = 0x1U;
}

/* Acquire the spin lock `spin_id' */
__INLINE__ void EE_mpc5777c_spin_in(EE_TYPESPIN spin_id)
{
    /* The same value as EE_CURRENTCPU can be obtained at run-time by
     * reading from special register PIR (286) */
    EE_UINT8 locked_val = (EE_UINT8)EE_CURRENTCPU;

    locked_val += (EE_UINT8)1U;
    do {
    	/*SEMA4.GATE[spin_id].R = locked_val;*/
    	SEMA4_GATE(spin_id) = locked_val;
    } while (SEMA4_GATE(spin_id) != locked_val);
}

/* Release the spin lock `spin_id' */
__INLINE__ void EE_mpc5777c_spin_out(EE_TYPESPIN spin_id)
{
    /*SEMA4.GATE[spin_id].R = 0U;*/
    SEMA4_GATE(spin_id) = 0U;
}

/* Function used to check whether core 1 has LOCKSTEP mode enabled or not */
__INLINE__ EE_UINT32 EE_mpc5777c_lsm_enabled(void)
{
    return SIU_LOCKSTEP;
}

/* Start slave core */
__INLINE__ void EE_mpc5777c_start_slave(EE_UINT32 start, EE_UINT32 mode)
{
    EE_UINT32 * volatile pRSTVEC1;
    pRSTVEC1 = (EE_UINT32 *)SIU_RSTVEC1;

    /* Build up starg mask */
    if ( mode == VLE_MODE )
    {
        /* Run slave core in VLE mode  */
        *pRSTVEC1 = (EE_UINT32)(start) | 0x1U;
    }
    else
    {
        /* Run slave core in Book-E mode  */
        *pRSTVEC1 = (EE_UINT32)start;
    }

	/* Here slave core is running!!! */
}

#endif /* EE_MCU_MPC5777C_DUAL_H */
