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
 * Dual-core interfacing code for SPC574K
 * Author: 2014 Francesco Esposito
 */

#ifndef EE_MCU_SPC574K_DUAL_H
#define EE_MCU_SPC574K_DUAL_H

#include "ee_spc574k.h"

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

#define MC_ME 0xFFFB8000

/* This register contains the reset vector, reset control and instruction
execution type selection for Core1 */
#define SIU_RSTVEC1 0xC3F909B0U

/* First software IRQ used for interprocessor communication  */
#define EE_SPC574K_INTER_IRQ_BASE 0x06U
/* Position in VBA of the first interprocessor IRQ */
#define EE_SPC574K_INTER_IRQ_VBA_BASE EE_SPC574K_INTER_IRQ_BASE
/* Interprocessor IRQ vector number, from CPU id */
#define EE_SPC574K_INTER_IRQ_LEVEL(cpu) \
	((EE_SREG)(cpu) + EE_SPC574K_INTER_IRQ_VBA_BASE + 16U)

#if defined (EE_ISR_DYNAMIC_TABLE)
/* Setup the intercore IRQs used by ERIKA for multicore support */
__INLINE__ void __ALWAYS_INLINE__ EE_spc574k_setup_inter_irqs(void)
{
	/* SW isr set to IOP */
    INTC_PSR(EE_SPC574K_INTER_IRQ_BASE) = (0x2000U | 0x1U);

	/* SW isr set to Core_0 */
	INTC_PSR(EE_SPC574K_INTER_IRQ_BASE + 1) = (0x8000U | 0x1U);
}
#endif

/* Signal the core `cpu' (0/1) by sending an IIRQ */
__INLINE__ void __ALWAYS_INLINE__ EE_spc574k_signal_cpu(EE_UINT8 cpu)
{
    INTC_SSCIR(EE_SPC574K_INTER_IRQ_BASE + cpu) = 0x2U;
}

/* Acknowledge the signal riceved by the core `cpu' (0/1) */
__INLINE__ void __ALWAYS_INLINE__ EE_spc574k_ack_signal(EE_UINT8 cpu)
{
    INTC_SSCIR(EE_SPC574K_INTER_IRQ_BASE + cpu) = 0x1U;
}

#ifdef	__DCC__
__asm __INLINE__ EE_UREG EE_spc574k_get_pir(void)
{
! "r3"
	mfspr	r3, pir
}
#else
__INLINE__ EE_UREG __ALWAYS_INLINE__ EE_spc574k_get_pir(void)
{
  register EE_UREG reg;
/*
 * __asm volatile ("mfspr %0, pir"   : "=r"(reg));
 * pir = 286
 */
  __asm volatile ("mfspr %0, 286" : "=r"(reg));
  return reg;
}
#endif

/* Acquire the spin lock `spin_id' */
__INLINE__ void __ALWAYS_INLINE__ EE_spc574k_spin_in(EE_TYPESPIN spin_id)
{
    /* The same value as EE_CURRENTCPU can be obtained at run-time by
	 * reading from special register PIR (286) */
	/*uint8_t locked_val = (uint8_t)EE_CURRENTCPU;*/
	EE_UREG locked_val = (EE_UINT8)EE_spc574k_get_pir();

	locked_val += 1U;
	do {

#if	0
		SEMA4.GATE[spin_id].R = 3;
#endif

        	SEMA4_GATE(spin_id) = (EE_UINT8)locked_val;
	} while (SEMA4_GATE(spin_id) != (EE_UINT8)locked_val);

}

__INLINE__ EE_BIT __ALWAYS_INLINE__ EE_spc574k_try_to_spin_in(EE_TYPESPIN spin_id)
{
	/* The same value as EE_CURRENTCPU can be obtained at run-time by
	 * reading from special register PIR (286) */
	/*uint8_t locked_val = (uint8_t)EE_CURRENTCPU;*/
	EE_UREG locked_val = EE_spc574k_get_pir();

	locked_val += 1U;
	
	SEMA4_GATE(spin_id) = (EE_UINT8)locked_val;

	if (SEMA4_GATE(spin_id) != (EE_UINT8)locked_val)
	{
		return (EE_BIT)0;
	}
	else
	{
		return (EE_BIT)1;
	}

}

/* Release the spin lock `spin_id' */
__INLINE__ void __ALWAYS_INLINE__ EE_spc574k_spin_out(EE_TYPESPIN spin_id)
{
#if	0
    SEMA4.GATE[spin_id].R = 0U;
#endif	/* 0 */
    SEMA4_GATE(spin_id) = 0U;
}

/* Function to check whether Core_1 (the checker core) is enabled or not */
__INLINE__ unsigned int __ALWAYS_INLINE__ EE_spc574k_lsm_enabled(void)
{
	unsigned int* volatile pME_CS;	/* core status */

	pME_CS = (unsigned int*) (MC_ME + 0x1C0);

	/* Check wheter bit S_CORE2  of ME_CS register is sdet or not*/
	if ( (*pME_CS & 0x4) == 0x4 )
	{
		/* Checker core is running */
		return 1U;
	}
	else
	{
		/* Checker core is not running */
		return 0U;
	}
}

/* Start slave core */
__INLINE__ void __ALWAYS_INLINE__ EE_spc574k_start_slave(unsigned int start)
{
#if	0
	volatile unsigned int* pME_CADDR2;	/* Checker core */
#endif	/* 0 */
	volatile unsigned int* pME_CADDR1;	/* Core_0 */
#if	0
	unsigned int* volatile pME_CADDR0;	/* IOP core */
#endif	/* 0 */
	volatile unsigned int* pME_MCTL;
	volatile unsigned int* pME_GS;
	volatile unsigned short* pME_CCTL1;	/* Core_0 */
	volatile unsigned short* pME_CCTL0;	/* IOP core */

	/* Init pointers */
#if	0
	pME_CADDR2 = (unsigned int*) (MC_ME + 0x1E8);
	pME_CADDR0 = (unsigned int*) (MC_ME + 0x1E0);
#endif	/* 0 */
	pME_CADDR1 = (unsigned int*) (MC_ME + 0x1E4);
	pME_CCTL0 = (unsigned short*) (MC_ME + 0x1C4);
	pME_CCTL1 = (unsigned short*) (MC_ME + 0x1C6);
	pME_MCTL = (unsigned int*) (MC_ME + 0x4);
	pME_GS = (unsigned int*) (MC_ME);

	/* Enable IOP and Core_0 in ALL modes */
	*pME_CCTL0 = 0xFE;
	*pME_CCTL1 = 0xFE;

	/* Setup addresses for IOP and Core_0 */
#if	0
	*pME_CADDR0 = (unsigned int)(0x40000001);	/* RMC = 1 */
#endif	/* 0 */
	*pME_CADDR1 = (unsigned int)(start | 0x1);	/* RMC = 1 */

	/* RE enter the drun mode, to update the configuration */
	*pME_MCTL = (unsigned int)(0x30005AF0);		/* Mode & Key */
	*pME_MCTL = (unsigned int)(0x3000A50F);		/* Mode & Key inverted */

	while((*pME_GS & 0x8000000) == 0x8000000);	/* Wait for mode entry to complete */
	while((*pME_GS & 0xF0000000) != 0x30000000);	/* Check DRUN mode has been entered */

	/* Here slave core is running!!! */
}

#endif /* EE_MCU_SPC574K_DUAL_H */
