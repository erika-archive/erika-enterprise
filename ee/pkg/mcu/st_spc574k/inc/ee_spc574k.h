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
 * SPC574K register map
 *         2014 Francesco Esposito
 */

#ifndef EE_MCU_SPC574K_H
#define EE_MCU_SPC574K_H

/* ISO int types used by SPC574K.h */
#define STDINT_SKIP_64BIT
#include "cpu/common/inc/ee_stdint.h"

/*#include "SPC574K.h"*/

#define EE_E200ZX_MAX_EXT_IRQ 961

#if (! defined EE_CURRENTCPU) || (EE_CURRENTCPU == 0)
#define INTC_CORE_OFFSET    0x18U
#define CORE_MASK_SELECTOR  0x2000U   /* IOP core */
#else
#define INTC_CORE_OFFSET    0x10U
#define CORE_MASK_SELECTOR  0x8000U	/* Core_0 */
#endif
/* INTC Base */
#define INTC_BASE 0xFC040000U

/* INTC_PSR Base */
#define INTC_PSR_BASE (INTC_BASE + 0x60U)

/* INTC SSCIR Base */
#define INTC_SSCIR_BASE (INTC_BASE + 0x40U)

/* SEMA4 Base */
#define SEMA4_BASE  (0xFC03C000U)

/* SEMA4_GATE Base */
#define SEMA4_GATE_BASE (SEMA4_BASE)

/* INTC base register setup */
#define INTC_CPR (*(EE_UREG *)(INTC_BASE + INTC_CORE_OFFSET))
#define INTC_IACKR (*(EE_UREG *)(INTC_BASE + 0x10U + INTC_CORE_OFFSET))
#define INTC_EOIR (*(EE_UREG *)(INTC_BASE + 0x20U + INTC_CORE_OFFSET))
/* This value is ignored in SPC574K,
 * it is provided just to guarantee backward compatibility */
#define EE_E200ZX_INTC_CURRPROC CORE_MASK_SELECTOR

#define SET_INT_PRIO(level, pri) \
			(*(volatile short *) ((volatile short *)INTC_PSR_BASE + \
			(level-16))) = (volatile short)(CORE_MASK_SELECTOR | pri)

#define INTC_SSCIR(n)   (*(EE_UINT8 volatile *)(INTC_SSCIR_BASE + (n)))
#define INTC_PSR(n)     (*((EE_UINT16 volatile *)(INTC_PSR_BASE) + (n)))
#define SEMA4_GATE(n)   (*(EE_UINT8 volatile *)(SEMA4_GATE_BASE + (n)))

#ifndef EE_ISR_DYNAMIC_TABLE
void EE_spc574k_initialize_external_IRQ_priorities(void);
#endif /* __STATIC_ISR_TABLE__ */

#ifdef EE_GNU__
void EE_spc574k_initMMU(void);
#else
__asm void EE_spc574k_initMMU(void);
#endif

#endif /* EE_MCU_SPC574K_H */
