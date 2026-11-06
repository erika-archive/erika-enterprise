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

/**
	@file ee_vtable.c
	@brief Static Interrupt Vector Table
	@author Francesco Esposito
	@date 2014
 **/

#include "ee_internal.h"
#include "ee_irq.h"

#ifndef DEFAULT_IRQ_ENTRY
#define DEFAULT_IRQ_ENTRY (EE_e200z7_ISR_handler)0
#endif

/* Special entries to add multicore support */
#ifdef __MSRP__

#ifdef EE_PPCE200ZX_6_ISR
#error "Software Settable Interrupt 6 is ALREADY USED for internal remote\
 notifications in Erika's multicore configuration."
#endif /* EE_PPCE200ZX_6_ISR */
#ifdef EE_PPCE200ZX_7_ISR
#error "Software Settable Interrupt 7 is ALREADY USED for internal remote\
 notifications in Erika's multicore configuration."
#endif /* EE_PPCE200ZX_7_ISR */

/* Map the handler and priority in correct position according to CPU number */
#if (EE_CURRENTCPU == 0)
#define EE_PPCE200ZX_6_ISR EE_e200zx_iirq_handler
#define EE_PPCE200ZX_6_ISR_PRI EE_E200ZX_INTC_CURRPROC | 1U
#else
#define EE_PPCE200ZX_7_ISR EE_e200zx_iirq_handler
/* I need EE_E200ZX_INTC_CURRPROC bitmask to route interrupt to the right
   core */
#define EE_PPCE200ZX_7_ISR_PRI EE_E200ZX_INTC_CURRPROC | 1U
#endif /* EE_CURRENTCPU */

#endif /* __MSRP__ */

#ifdef EE_PPCE200ZX_0_ISR
extern void EE_PPCE200ZX_0_ISR(void);
#else
#define EE_PPCE200ZX_0_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_1_ISR
extern void EE_PPCE200ZX_1_ISR(void);
#else
#define EE_PPCE200ZX_1_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_2_ISR
extern void EE_PPCE200ZX_2_ISR(void);
#else
#define EE_PPCE200ZX_2_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_3_ISR
extern void EE_PPCE200ZX_3_ISR(void);
#else
#define EE_PPCE200ZX_3_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_4_ISR
extern void EE_PPCE200ZX_4_ISR(void);
#else
#define EE_PPCE200ZX_4_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_5_ISR
extern void EE_PPCE200ZX_5_ISR(void);
#else
#define EE_PPCE200ZX_5_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_6_ISR
extern void EE_PPCE200ZX_6_ISR(void);
#else
#define EE_PPCE200ZX_6_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_7_ISR
extern void EE_PPCE200ZX_7_ISR(void);
#else
#define EE_PPCE200ZX_7_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_8_ISR
extern void EE_PPCE200ZX_8_ISR(void);
#else
#define EE_PPCE200ZX_8_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_9_ISR
extern void EE_PPCE200ZX_9_ISR(void);
#else
#define EE_PPCE200ZX_9_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_10_ISR
extern void EE_PPCE200ZX_10_ISR(void);
#else
#define EE_PPCE200ZX_10_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_11_ISR
extern void EE_PPCE200ZX_11_ISR(void);
#else
#define EE_PPCE200ZX_11_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_12_ISR
extern void EE_PPCE200ZX_12_ISR(void);
#else
#define EE_PPCE200ZX_12_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_13_ISR
extern void EE_PPCE200ZX_13_ISR(void);
#else
#define EE_PPCE200ZX_13_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_14_ISR
extern void EE_PPCE200ZX_14_ISR(void);
#else
#define EE_PPCE200ZX_14_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_15_ISR
extern void EE_PPCE200ZX_15_ISR(void);
#else
#define EE_PPCE200ZX_15_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_16_ISR
extern void EE_PPCE200ZX_16_ISR(void);
#else
#define EE_PPCE200ZX_16_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_17_ISR
extern void EE_PPCE200ZX_17_ISR(void);
#else
#define EE_PPCE200ZX_17_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_18_ISR
extern void EE_PPCE200ZX_18_ISR(void);
#else
#define EE_PPCE200ZX_18_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_19_ISR
extern void EE_PPCE200ZX_19_ISR(void);
#else
#define EE_PPCE200ZX_19_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_20_ISR
extern void EE_PPCE200ZX_20_ISR(void);
#else
#define EE_PPCE200ZX_20_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_21_ISR
extern void EE_PPCE200ZX_21_ISR(void);
#else
#define EE_PPCE200ZX_21_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_22_ISR
extern void EE_PPCE200ZX_22_ISR(void);
#else
#define EE_PPCE200ZX_22_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_23_ISR
extern void EE_PPCE200ZX_23_ISR(void);
#else
#define EE_PPCE200ZX_23_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_24_ISR
extern void EE_PPCE200ZX_24_ISR(void);
#else
#define EE_PPCE200ZX_24_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_25_ISR
extern void EE_PPCE200ZX_25_ISR(void);
#else
#define EE_PPCE200ZX_25_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_26_ISR
extern void EE_PPCE200ZX_26_ISR(void);
#else
#define EE_PPCE200ZX_26_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_27_ISR
extern void EE_PPCE200ZX_27_ISR(void);
#else
#define EE_PPCE200ZX_27_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_28_ISR
extern void EE_PPCE200ZX_28_ISR(void);
#else
#define EE_PPCE200ZX_28_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_29_ISR
extern void EE_PPCE200ZX_29_ISR(void);
#else
#define EE_PPCE200ZX_29_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_30_ISR
extern void EE_PPCE200ZX_30_ISR(void);
#else
#define EE_PPCE200ZX_30_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_31_ISR
extern void EE_PPCE200ZX_31_ISR(void);
#else
#define EE_PPCE200ZX_31_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_32_ISR
extern void EE_PPCE200ZX_32_ISR(void);
#else
#define EE_PPCE200ZX_32_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_33_ISR
extern void EE_PPCE200ZX_33_ISR(void);
#else
#define EE_PPCE200ZX_33_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_34_ISR
extern void EE_PPCE200ZX_34_ISR(void);
#else
#define EE_PPCE200ZX_34_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_35_ISR
extern void EE_PPCE200ZX_35_ISR(void);
#else
#define EE_PPCE200ZX_35_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_36_ISR
extern void EE_PPCE200ZX_36_ISR(void);
#else
#define EE_PPCE200ZX_36_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_37_ISR
extern void EE_PPCE200ZX_37_ISR(void);
#else
#define EE_PPCE200ZX_37_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_38_ISR
extern void EE_PPCE200ZX_38_ISR(void);
#else
#define EE_PPCE200ZX_38_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_39_ISR
extern void EE_PPCE200ZX_39_ISR(void);
#else
#define EE_PPCE200ZX_39_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_40_ISR
extern void EE_PPCE200ZX_40_ISR(void);
#else
#define EE_PPCE200ZX_40_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_41_ISR
extern void EE_PPCE200ZX_41_ISR(void);
#else
#define EE_PPCE200ZX_41_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_42_ISR
extern void EE_PPCE200ZX_42_ISR(void);
#else
#define EE_PPCE200ZX_42_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_43_ISR
extern void EE_PPCE200ZX_43_ISR(void);
#else
#define EE_PPCE200ZX_43_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_44_ISR
extern void EE_PPCE200ZX_44_ISR(void);
#else
#define EE_PPCE200ZX_44_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_45_ISR
extern void EE_PPCE200ZX_45_ISR(void);
#else
#define EE_PPCE200ZX_45_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_46_ISR
extern void EE_PPCE200ZX_46_ISR(void);
#else
#define EE_PPCE200ZX_46_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_47_ISR
extern void EE_PPCE200ZX_47_ISR(void);
#else
#define EE_PPCE200ZX_47_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_48_ISR
extern void EE_PPCE200ZX_48_ISR(void);
#else
#define EE_PPCE200ZX_48_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_49_ISR
extern void EE_PPCE200ZX_49_ISR(void);
#else
#define EE_PPCE200ZX_49_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_50_ISR
extern void EE_PPCE200ZX_50_ISR(void);
#else
#define EE_PPCE200ZX_50_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_51_ISR
extern void EE_PPCE200ZX_51_ISR(void);
#else
#define EE_PPCE200ZX_51_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_52_ISR
extern void EE_PPCE200ZX_52_ISR(void);
#else
#define EE_PPCE200ZX_52_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_53_ISR
extern void EE_PPCE200ZX_53_ISR(void);
#else
#define EE_PPCE200ZX_53_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_54_ISR
extern void EE_PPCE200ZX_54_ISR(void);
#else
#define EE_PPCE200ZX_54_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_55_ISR
extern void EE_PPCE200ZX_55_ISR(void);
#else
#define EE_PPCE200ZX_55_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_56_ISR
extern void EE_PPCE200ZX_56_ISR(void);
#else
#define EE_PPCE200ZX_56_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_57_ISR
extern void EE_PPCE200ZX_57_ISR(void);
#else
#define EE_PPCE200ZX_57_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_58_ISR
extern void EE_PPCE200ZX_58_ISR(void);
#else
#define EE_PPCE200ZX_58_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_59_ISR
extern void EE_PPCE200ZX_59_ISR(void);
#else
#define EE_PPCE200ZX_59_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_60_ISR
extern void EE_PPCE200ZX_60_ISR(void);
#else
#define EE_PPCE200ZX_60_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_61_ISR
extern void EE_PPCE200ZX_61_ISR(void);
#else
#define EE_PPCE200ZX_61_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_62_ISR
extern void EE_PPCE200ZX_62_ISR(void);
#else
#define EE_PPCE200ZX_62_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_63_ISR
extern void EE_PPCE200ZX_63_ISR(void);
#else
#define EE_PPCE200ZX_63_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_64_ISR
extern void EE_PPCE200ZX_64_ISR(void);
#else
#define EE_PPCE200ZX_64_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_65_ISR
extern void EE_PPCE200ZX_65_ISR(void);
#else
#define EE_PPCE200ZX_65_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_66_ISR
extern void EE_PPCE200ZX_66_ISR(void);
#else
#define EE_PPCE200ZX_66_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_67_ISR
extern void EE_PPCE200ZX_67_ISR(void);
#else
#define EE_PPCE200ZX_67_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_68_ISR
extern void EE_PPCE200ZX_68_ISR(void);
#else
#define EE_PPCE200ZX_68_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_69_ISR
extern void EE_PPCE200ZX_69_ISR(void);
#else
#define EE_PPCE200ZX_69_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_70_ISR
extern void EE_PPCE200ZX_70_ISR(void);
#else
#define EE_PPCE200ZX_70_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_71_ISR
extern void EE_PPCE200ZX_71_ISR(void);
#else
#define EE_PPCE200ZX_71_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_72_ISR
extern void EE_PPCE200ZX_72_ISR(void);
#else
#define EE_PPCE200ZX_72_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_73_ISR
extern void EE_PPCE200ZX_73_ISR(void);
#else
#define EE_PPCE200ZX_73_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_74_ISR
extern void EE_PPCE200ZX_74_ISR(void);
#else
#define EE_PPCE200ZX_74_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_75_ISR
extern void EE_PPCE200ZX_75_ISR(void);
#else
#define EE_PPCE200ZX_75_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_76_ISR
extern void EE_PPCE200ZX_76_ISR(void);
#else
#define EE_PPCE200ZX_76_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_77_ISR
extern void EE_PPCE200ZX_77_ISR(void);
#else
#define EE_PPCE200ZX_77_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_78_ISR
extern void EE_PPCE200ZX_78_ISR(void);
#else
#define EE_PPCE200ZX_78_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_79_ISR
extern void EE_PPCE200ZX_79_ISR(void);
#else
#define EE_PPCE200ZX_79_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_80_ISR
extern void EE_PPCE200ZX_80_ISR(void);
#else
#define EE_PPCE200ZX_80_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_81_ISR
extern void EE_PPCE200ZX_81_ISR(void);
#else
#define EE_PPCE200ZX_81_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_82_ISR
extern void EE_PPCE200ZX_82_ISR(void);
#else
#define EE_PPCE200ZX_82_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_83_ISR
extern void EE_PPCE200ZX_83_ISR(void);
#else
#define EE_PPCE200ZX_83_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_84_ISR
extern void EE_PPCE200ZX_84_ISR(void);
#else
#define EE_PPCE200ZX_84_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_85_ISR
extern void EE_PPCE200ZX_85_ISR(void);
#else
#define EE_PPCE200ZX_85_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_86_ISR
extern void EE_PPCE200ZX_86_ISR(void);
#else
#define EE_PPCE200ZX_86_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_87_ISR
extern void EE_PPCE200ZX_87_ISR(void);
#else
#define EE_PPCE200ZX_87_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_88_ISR
extern void EE_PPCE200ZX_88_ISR(void);
#else
#define EE_PPCE200ZX_88_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_89_ISR
extern void EE_PPCE200ZX_89_ISR(void);
#else
#define EE_PPCE200ZX_89_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_90_ISR
extern void EE_PPCE200ZX_90_ISR(void);
#else
#define EE_PPCE200ZX_90_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_91_ISR
extern void EE_PPCE200ZX_91_ISR(void);
#else
#define EE_PPCE200ZX_91_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_92_ISR
extern void EE_PPCE200ZX_92_ISR(void);
#else
#define EE_PPCE200ZX_92_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_93_ISR
extern void EE_PPCE200ZX_93_ISR(void);
#else
#define EE_PPCE200ZX_93_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_94_ISR
extern void EE_PPCE200ZX_94_ISR(void);
#else
#define EE_PPCE200ZX_94_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_95_ISR
extern void EE_PPCE200ZX_95_ISR(void);
#else
#define EE_PPCE200ZX_95_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_96_ISR
extern void EE_PPCE200ZX_96_ISR(void);
#else
#define EE_PPCE200ZX_96_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_97_ISR
extern void EE_PPCE200ZX_97_ISR(void);
#else
#define EE_PPCE200ZX_97_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_98_ISR
extern void EE_PPCE200ZX_98_ISR(void);
#else
#define EE_PPCE200ZX_98_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_99_ISR
extern void EE_PPCE200ZX_99_ISR(void);
#else
#define EE_PPCE200ZX_99_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_100_ISR
extern void EE_PPCE200ZX_100_ISR(void);
#else
#define EE_PPCE200ZX_100_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_101_ISR
extern void EE_PPCE200ZX_101_ISR(void);
#else
#define EE_PPCE200ZX_101_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_102_ISR
extern void EE_PPCE200ZX_102_ISR(void);
#else
#define EE_PPCE200ZX_102_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_103_ISR
extern void EE_PPCE200ZX_103_ISR(void);
#else
#define EE_PPCE200ZX_103_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_104_ISR
extern void EE_PPCE200ZX_104_ISR(void);
#else
#define EE_PPCE200ZX_104_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_105_ISR
extern void EE_PPCE200ZX_105_ISR(void);
#else
#define EE_PPCE200ZX_105_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_106_ISR
extern void EE_PPCE200ZX_106_ISR(void);
#else
#define EE_PPCE200ZX_106_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_107_ISR
extern void EE_PPCE200ZX_107_ISR(void);
#else
#define EE_PPCE200ZX_107_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_108_ISR
extern void EE_PPCE200ZX_108_ISR(void);
#else
#define EE_PPCE200ZX_108_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_109_ISR
extern void EE_PPCE200ZX_109_ISR(void);
#else
#define EE_PPCE200ZX_109_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_110_ISR
extern void EE_PPCE200ZX_110_ISR(void);
#else
#define EE_PPCE200ZX_110_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_111_ISR
extern void EE_PPCE200ZX_111_ISR(void);
#else
#define EE_PPCE200ZX_111_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_112_ISR
extern void EE_PPCE200ZX_112_ISR(void);
#else
#define EE_PPCE200ZX_112_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_113_ISR
extern void EE_PPCE200ZX_113_ISR(void);
#else
#define EE_PPCE200ZX_113_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_114_ISR
extern void EE_PPCE200ZX_114_ISR(void);
#else
#define EE_PPCE200ZX_114_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_115_ISR
extern void EE_PPCE200ZX_115_ISR(void);
#else
#define EE_PPCE200ZX_115_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_116_ISR
extern void EE_PPCE200ZX_116_ISR(void);
#else
#define EE_PPCE200ZX_116_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_117_ISR
extern void EE_PPCE200ZX_117_ISR(void);
#else
#define EE_PPCE200ZX_117_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_118_ISR
extern void EE_PPCE200ZX_118_ISR(void);
#else
#define EE_PPCE200ZX_118_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_119_ISR
extern void EE_PPCE200ZX_119_ISR(void);
#else
#define EE_PPCE200ZX_119_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_120_ISR
extern void EE_PPCE200ZX_120_ISR(void);
#else
#define EE_PPCE200ZX_120_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_121_ISR
extern void EE_PPCE200ZX_121_ISR(void);
#else
#define EE_PPCE200ZX_121_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_122_ISR
extern void EE_PPCE200ZX_122_ISR(void);
#else
#define EE_PPCE200ZX_122_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_123_ISR
extern void EE_PPCE200ZX_123_ISR(void);
#else
#define EE_PPCE200ZX_123_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_124_ISR
extern void EE_PPCE200ZX_124_ISR(void);
#else
#define EE_PPCE200ZX_124_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_125_ISR
extern void EE_PPCE200ZX_125_ISR(void);
#else
#define EE_PPCE200ZX_125_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_126_ISR
extern void EE_PPCE200ZX_126_ISR(void);
#else
#define EE_PPCE200ZX_126_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_127_ISR
extern void EE_PPCE200ZX_127_ISR(void);
#else
#define EE_PPCE200ZX_127_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_128_ISR
extern void EE_PPCE200ZX_128_ISR(void);
#else
#define EE_PPCE200ZX_128_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_129_ISR
extern void EE_PPCE200ZX_129_ISR(void);
#else
#define EE_PPCE200ZX_129_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_130_ISR
extern void EE_PPCE200ZX_130_ISR(void);
#else
#define EE_PPCE200ZX_130_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_131_ISR
extern void EE_PPCE200ZX_131_ISR(void);
#else
#define EE_PPCE200ZX_131_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_132_ISR
extern void EE_PPCE200ZX_132_ISR(void);
#else
#define EE_PPCE200ZX_132_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_133_ISR
extern void EE_PPCE200ZX_133_ISR(void);
#else
#define EE_PPCE200ZX_133_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_134_ISR
extern void EE_PPCE200ZX_134_ISR(void);
#else
#define EE_PPCE200ZX_134_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_135_ISR
extern void EE_PPCE200ZX_135_ISR(void);
#else
#define EE_PPCE200ZX_135_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_136_ISR
extern void EE_PPCE200ZX_136_ISR(void);
#else
#define EE_PPCE200ZX_136_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_137_ISR
extern void EE_PPCE200ZX_137_ISR(void);
#else
#define EE_PPCE200ZX_137_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_138_ISR
extern void EE_PPCE200ZX_138_ISR(void);
#else
#define EE_PPCE200ZX_138_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_139_ISR
extern void EE_PPCE200ZX_139_ISR(void);
#else
#define EE_PPCE200ZX_139_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_140_ISR
extern void EE_PPCE200ZX_140_ISR(void);
#else
#define EE_PPCE200ZX_140_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_141_ISR
extern void EE_PPCE200ZX_141_ISR(void);
#else
#define EE_PPCE200ZX_141_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_142_ISR
extern void EE_PPCE200ZX_142_ISR(void);
#else
#define EE_PPCE200ZX_142_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_143_ISR
extern void EE_PPCE200ZX_143_ISR(void);
#else
#define EE_PPCE200ZX_143_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_144_ISR
extern void EE_PPCE200ZX_144_ISR(void);
#else
#define EE_PPCE200ZX_144_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_145_ISR
extern void EE_PPCE200ZX_145_ISR(void);
#else
#define EE_PPCE200ZX_145_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_146_ISR
extern void EE_PPCE200ZX_146_ISR(void);
#else
#define EE_PPCE200ZX_146_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_147_ISR
extern void EE_PPCE200ZX_147_ISR(void);
#else
#define EE_PPCE200ZX_147_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_148_ISR
extern void EE_PPCE200ZX_148_ISR(void);
#else
#define EE_PPCE200ZX_148_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_149_ISR
extern void EE_PPCE200ZX_149_ISR(void);
#else
#define EE_PPCE200ZX_149_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_150_ISR
extern void EE_PPCE200ZX_150_ISR(void);
#else
#define EE_PPCE200ZX_150_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_151_ISR
extern void EE_PPCE200ZX_151_ISR(void);
#else
#define EE_PPCE200ZX_151_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_152_ISR
extern void EE_PPCE200ZX_152_ISR(void);
#else
#define EE_PPCE200ZX_152_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_153_ISR
extern void EE_PPCE200ZX_153_ISR(void);
#else
#define EE_PPCE200ZX_153_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_154_ISR
extern void EE_PPCE200ZX_154_ISR(void);
#else
#define EE_PPCE200ZX_154_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_155_ISR
extern void EE_PPCE200ZX_155_ISR(void);
#else
#define EE_PPCE200ZX_155_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_156_ISR
extern void EE_PPCE200ZX_156_ISR(void);
#else
#define EE_PPCE200ZX_156_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_157_ISR
extern void EE_PPCE200ZX_157_ISR(void);
#else
#define EE_PPCE200ZX_157_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_158_ISR
extern void EE_PPCE200ZX_158_ISR(void);
#else
#define EE_PPCE200ZX_158_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_159_ISR
extern void EE_PPCE200ZX_159_ISR(void);
#else
#define EE_PPCE200ZX_159_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_160_ISR
extern void EE_PPCE200ZX_160_ISR(void);
#else
#define EE_PPCE200ZX_160_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_161_ISR
extern void EE_PPCE200ZX_161_ISR(void);
#else
#define EE_PPCE200ZX_161_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_162_ISR
extern void EE_PPCE200ZX_162_ISR(void);
#else
#define EE_PPCE200ZX_162_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_163_ISR
extern void EE_PPCE200ZX_163_ISR(void);
#else
#define EE_PPCE200ZX_163_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_164_ISR
extern void EE_PPCE200ZX_164_ISR(void);
#else
#define EE_PPCE200ZX_164_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_165_ISR
extern void EE_PPCE200ZX_165_ISR(void);
#else
#define EE_PPCE200ZX_165_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_166_ISR
extern void EE_PPCE200ZX_166_ISR(void);
#else
#define EE_PPCE200ZX_166_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_167_ISR
extern void EE_PPCE200ZX_167_ISR(void);
#else
#define EE_PPCE200ZX_167_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_168_ISR
extern void EE_PPCE200ZX_168_ISR(void);
#else
#define EE_PPCE200ZX_168_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_169_ISR
extern void EE_PPCE200ZX_169_ISR(void);
#else
#define EE_PPCE200ZX_169_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_170_ISR
extern void EE_PPCE200ZX_170_ISR(void);
#else
#define EE_PPCE200ZX_170_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_171_ISR
extern void EE_PPCE200ZX_171_ISR(void);
#else
#define EE_PPCE200ZX_171_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_172_ISR
extern void EE_PPCE200ZX_172_ISR(void);
#else
#define EE_PPCE200ZX_172_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_173_ISR
extern void EE_PPCE200ZX_173_ISR(void);
#else
#define EE_PPCE200ZX_173_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_174_ISR
extern void EE_PPCE200ZX_174_ISR(void);
#else
#define EE_PPCE200ZX_174_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_175_ISR
extern void EE_PPCE200ZX_175_ISR(void);
#else
#define EE_PPCE200ZX_175_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_176_ISR
extern void EE_PPCE200ZX_176_ISR(void);
#else
#define EE_PPCE200ZX_176_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_177_ISR
extern void EE_PPCE200ZX_177_ISR(void);
#else
#define EE_PPCE200ZX_177_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_178_ISR
extern void EE_PPCE200ZX_178_ISR(void);
#else
#define EE_PPCE200ZX_178_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_179_ISR
extern void EE_PPCE200ZX_179_ISR(void);
#else
#define EE_PPCE200ZX_179_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_180_ISR
extern void EE_PPCE200ZX_180_ISR(void);
#else
#define EE_PPCE200ZX_180_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_181_ISR
extern void EE_PPCE200ZX_181_ISR(void);
#else
#define EE_PPCE200ZX_181_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_182_ISR
extern void EE_PPCE200ZX_182_ISR(void);
#else
#define EE_PPCE200ZX_182_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_183_ISR
extern void EE_PPCE200ZX_183_ISR(void);
#else
#define EE_PPCE200ZX_183_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_184_ISR
extern void EE_PPCE200ZX_184_ISR(void);
#else
#define EE_PPCE200ZX_184_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_185_ISR
extern void EE_PPCE200ZX_185_ISR(void);
#else
#define EE_PPCE200ZX_185_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_186_ISR
extern void EE_PPCE200ZX_186_ISR(void);
#else
#define EE_PPCE200ZX_186_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_187_ISR
extern void EE_PPCE200ZX_187_ISR(void);
#else
#define EE_PPCE200ZX_187_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_188_ISR
extern void EE_PPCE200ZX_188_ISR(void);
#else
#define EE_PPCE200ZX_188_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_189_ISR
extern void EE_PPCE200ZX_189_ISR(void);
#else
#define EE_PPCE200ZX_189_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_190_ISR
extern void EE_PPCE200ZX_190_ISR(void);
#else
#define EE_PPCE200ZX_190_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_191_ISR
extern void EE_PPCE200ZX_191_ISR(void);
#else
#define EE_PPCE200ZX_191_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_192_ISR
extern void EE_PPCE200ZX_192_ISR(void);
#else
#define EE_PPCE200ZX_192_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_193_ISR
extern void EE_PPCE200ZX_193_ISR(void);
#else
#define EE_PPCE200ZX_193_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_194_ISR
extern void EE_PPCE200ZX_194_ISR(void);
#else
#define EE_PPCE200ZX_194_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_195_ISR
extern void EE_PPCE200ZX_195_ISR(void);
#else
#define EE_PPCE200ZX_195_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_196_ISR
extern void EE_PPCE200ZX_196_ISR(void);
#else
#define EE_PPCE200ZX_196_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_197_ISR
extern void EE_PPCE200ZX_197_ISR(void);
#else
#define EE_PPCE200ZX_197_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_198_ISR
extern void EE_PPCE200ZX_198_ISR(void);
#else
#define EE_PPCE200ZX_198_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_199_ISR
extern void EE_PPCE200ZX_199_ISR(void);
#else
#define EE_PPCE200ZX_199_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_200_ISR
extern void EE_PPCE200ZX_200_ISR(void);
#else
#define EE_PPCE200ZX_200_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_201_ISR
extern void EE_PPCE200ZX_201_ISR(void);
#else
#define EE_PPCE200ZX_201_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_202_ISR
extern void EE_PPCE200ZX_202_ISR(void);
#else
#define EE_PPCE200ZX_202_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_203_ISR
extern void EE_PPCE200ZX_203_ISR(void);
#else
#define EE_PPCE200ZX_203_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_204_ISR
extern void EE_PPCE200ZX_204_ISR(void);
#else
#define EE_PPCE200ZX_204_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_205_ISR
extern void EE_PPCE200ZX_205_ISR(void);
#else
#define EE_PPCE200ZX_205_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_206_ISR
extern void EE_PPCE200ZX_206_ISR(void);
#else
#define EE_PPCE200ZX_206_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_207_ISR
extern void EE_PPCE200ZX_207_ISR(void);
#else
#define EE_PPCE200ZX_207_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_208_ISR
extern void EE_PPCE200ZX_208_ISR(void);
#else
#define EE_PPCE200ZX_208_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_209_ISR
extern void EE_PPCE200ZX_209_ISR(void);
#else
#define EE_PPCE200ZX_209_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_210_ISR
extern void EE_PPCE200ZX_210_ISR(void);
#else
#define EE_PPCE200ZX_210_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_211_ISR
extern void EE_PPCE200ZX_211_ISR(void);
#else
#define EE_PPCE200ZX_211_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_212_ISR
extern void EE_PPCE200ZX_212_ISR(void);
#else
#define EE_PPCE200ZX_212_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_213_ISR
extern void EE_PPCE200ZX_213_ISR(void);
#else
#define EE_PPCE200ZX_213_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_214_ISR
extern void EE_PPCE200ZX_214_ISR(void);
#else
#define EE_PPCE200ZX_214_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_215_ISR
extern void EE_PPCE200ZX_215_ISR(void);
#else
#define EE_PPCE200ZX_215_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_216_ISR
extern void EE_PPCE200ZX_216_ISR(void);
#else
#define EE_PPCE200ZX_216_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_217_ISR
extern void EE_PPCE200ZX_217_ISR(void);
#else
#define EE_PPCE200ZX_217_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_218_ISR
extern void EE_PPCE200ZX_218_ISR(void);
#else
#define EE_PPCE200ZX_218_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_219_ISR
extern void EE_PPCE200ZX_219_ISR(void);
#else
#define EE_PPCE200ZX_219_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_220_ISR
extern void EE_PPCE200ZX_220_ISR(void);
#else
#define EE_PPCE200ZX_220_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_221_ISR
extern void EE_PPCE200ZX_221_ISR(void);
#else
#define EE_PPCE200ZX_221_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_222_ISR
extern void EE_PPCE200ZX_222_ISR(void);
#else
#define EE_PPCE200ZX_222_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_223_ISR
extern void EE_PPCE200ZX_223_ISR(void);
#else
#define EE_PPCE200ZX_223_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_224_ISR
extern void EE_PPCE200ZX_224_ISR(void);
#else
#define EE_PPCE200ZX_224_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_225_ISR
extern void EE_PPCE200ZX_225_ISR(void);
#else
#define EE_PPCE200ZX_225_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_226_ISR
extern void EE_PPCE200ZX_226_ISR(void);
#else
#define EE_PPCE200ZX_226_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_227_ISR
extern void EE_PPCE200ZX_227_ISR(void);
#else
#define EE_PPCE200ZX_227_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_228_ISR
extern void EE_PPCE200ZX_228_ISR(void);
#else
#define EE_PPCE200ZX_228_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_229_ISR
extern void EE_PPCE200ZX_229_ISR(void);
#else
#define EE_PPCE200ZX_229_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_230_ISR
extern void EE_PPCE200ZX_230_ISR(void);
#else
#define EE_PPCE200ZX_230_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_231_ISR
extern void EE_PPCE200ZX_231_ISR(void);
#else
#define EE_PPCE200ZX_231_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_232_ISR
extern void EE_PPCE200ZX_232_ISR(void);
#else
#define EE_PPCE200ZX_232_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_233_ISR
extern void EE_PPCE200ZX_233_ISR(void);
#else
#define EE_PPCE200ZX_233_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_234_ISR
extern void EE_PPCE200ZX_234_ISR(void);
#else
#define EE_PPCE200ZX_234_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_235_ISR
extern void EE_PPCE200ZX_235_ISR(void);
#else
#define EE_PPCE200ZX_235_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_236_ISR
extern void EE_PPCE200ZX_236_ISR(void);
#else
#define EE_PPCE200ZX_236_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_237_ISR
extern void EE_PPCE200ZX_237_ISR(void);
#else
#define EE_PPCE200ZX_237_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_238_ISR
extern void EE_PPCE200ZX_238_ISR(void);
#else
#define EE_PPCE200ZX_238_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_239_ISR
extern void EE_PPCE200ZX_239_ISR(void);
#else
#define EE_PPCE200ZX_239_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_240_ISR
extern void EE_PPCE200ZX_240_ISR(void);
#else
#define EE_PPCE200ZX_240_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_241_ISR
extern void EE_PPCE200ZX_241_ISR(void);
#else
#define EE_PPCE200ZX_241_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_242_ISR
extern void EE_PPCE200ZX_242_ISR(void);
#else
#define EE_PPCE200ZX_242_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_243_ISR
extern void EE_PPCE200ZX_243_ISR(void);
#else
#define EE_PPCE200ZX_243_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_244_ISR
extern void EE_PPCE200ZX_244_ISR(void);
#else
#define EE_PPCE200ZX_244_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_245_ISR
extern void EE_PPCE200ZX_245_ISR(void);
#else
#define EE_PPCE200ZX_245_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_246_ISR
extern void EE_PPCE200ZX_246_ISR(void);
#else
#define EE_PPCE200ZX_246_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_247_ISR
extern void EE_PPCE200ZX_247_ISR(void);
#else
#define EE_PPCE200ZX_247_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_248_ISR
extern void EE_PPCE200ZX_248_ISR(void);
#else
#define EE_PPCE200ZX_248_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_249_ISR
extern void EE_PPCE200ZX_249_ISR(void);
#else
#define EE_PPCE200ZX_249_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_250_ISR
extern void EE_PPCE200ZX_250_ISR(void);
#else
#define EE_PPCE200ZX_250_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_251_ISR
extern void EE_PPCE200ZX_251_ISR(void);
#else
#define EE_PPCE200ZX_251_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_252_ISR
extern void EE_PPCE200ZX_252_ISR(void);
#else
#define EE_PPCE200ZX_252_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_253_ISR
extern void EE_PPCE200ZX_253_ISR(void);
#else
#define EE_PPCE200ZX_253_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_254_ISR
extern void EE_PPCE200ZX_254_ISR(void);
#else
#define EE_PPCE200ZX_254_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_255_ISR
extern void EE_PPCE200ZX_255_ISR(void);
#else
#define EE_PPCE200ZX_255_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_256_ISR
extern void EE_PPCE200ZX_256_ISR(void);
#else
#define EE_PPCE200ZX_256_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_257_ISR
extern void EE_PPCE200ZX_257_ISR(void);
#else
#define EE_PPCE200ZX_257_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_258_ISR
extern void EE_PPCE200ZX_258_ISR(void);
#else
#define EE_PPCE200ZX_258_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_259_ISR
extern void EE_PPCE200ZX_259_ISR(void);
#else
#define EE_PPCE200ZX_259_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_260_ISR
extern void EE_PPCE200ZX_260_ISR(void);
#else
#define EE_PPCE200ZX_260_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_261_ISR
extern void EE_PPCE200ZX_261_ISR(void);
#else
#define EE_PPCE200ZX_261_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_262_ISR
extern void EE_PPCE200ZX_262_ISR(void);
#else
#define EE_PPCE200ZX_262_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_263_ISR
extern void EE_PPCE200ZX_263_ISR(void);
#else
#define EE_PPCE200ZX_263_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_264_ISR
extern void EE_PPCE200ZX_264_ISR(void);
#else
#define EE_PPCE200ZX_264_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_265_ISR
extern void EE_PPCE200ZX_265_ISR(void);
#else
#define EE_PPCE200ZX_265_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_266_ISR
extern void EE_PPCE200ZX_266_ISR(void);
#else
#define EE_PPCE200ZX_266_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_267_ISR
extern void EE_PPCE200ZX_267_ISR(void);
#else
#define EE_PPCE200ZX_267_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_268_ISR
extern void EE_PPCE200ZX_268_ISR(void);
#else
#define EE_PPCE200ZX_268_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_269_ISR
extern void EE_PPCE200ZX_269_ISR(void);
#else
#define EE_PPCE200ZX_269_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_270_ISR
extern void EE_PPCE200ZX_270_ISR(void);
#else
#define EE_PPCE200ZX_270_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_271_ISR
extern void EE_PPCE200ZX_271_ISR(void);
#else
#define EE_PPCE200ZX_271_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_272_ISR
extern void EE_PPCE200ZX_272_ISR(void);
#else
#define EE_PPCE200ZX_272_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_273_ISR
extern void EE_PPCE200ZX_273_ISR(void);
#else
#define EE_PPCE200ZX_273_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_274_ISR
extern void EE_PPCE200ZX_274_ISR(void);
#else
#define EE_PPCE200ZX_274_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_275_ISR
extern void EE_PPCE200ZX_275_ISR(void);
#else
#define EE_PPCE200ZX_275_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_276_ISR
extern void EE_PPCE200ZX_276_ISR(void);
#else
#define EE_PPCE200ZX_276_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_277_ISR
extern void EE_PPCE200ZX_277_ISR(void);
#else
#define EE_PPCE200ZX_277_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_278_ISR
extern void EE_PPCE200ZX_278_ISR(void);
#else
#define EE_PPCE200ZX_278_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_279_ISR
extern void EE_PPCE200ZX_279_ISR(void);
#else
#define EE_PPCE200ZX_279_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_280_ISR
extern void EE_PPCE200ZX_280_ISR(void);
#else
#define EE_PPCE200ZX_280_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_281_ISR
extern void EE_PPCE200ZX_281_ISR(void);
#else
#define EE_PPCE200ZX_281_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_282_ISR
extern void EE_PPCE200ZX_282_ISR(void);
#else
#define EE_PPCE200ZX_282_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_283_ISR
extern void EE_PPCE200ZX_283_ISR(void);
#else
#define EE_PPCE200ZX_283_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_284_ISR
extern void EE_PPCE200ZX_284_ISR(void);
#else
#define EE_PPCE200ZX_284_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_285_ISR
extern void EE_PPCE200ZX_285_ISR(void);
#else
#define EE_PPCE200ZX_285_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_286_ISR
extern void EE_PPCE200ZX_286_ISR(void);
#else
#define EE_PPCE200ZX_286_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_287_ISR
extern void EE_PPCE200ZX_287_ISR(void);
#else
#define EE_PPCE200ZX_287_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_288_ISR
extern void EE_PPCE200ZX_288_ISR(void);
#else
#define EE_PPCE200ZX_288_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_289_ISR
extern void EE_PPCE200ZX_289_ISR(void);
#else
#define EE_PPCE200ZX_289_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_290_ISR
extern void EE_PPCE200ZX_290_ISR(void);
#else
#define EE_PPCE200ZX_290_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_291_ISR
extern void EE_PPCE200ZX_291_ISR(void);
#else
#define EE_PPCE200ZX_291_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_292_ISR
extern void EE_PPCE200ZX_292_ISR(void);
#else
#define EE_PPCE200ZX_292_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_293_ISR
extern void EE_PPCE200ZX_293_ISR(void);
#else
#define EE_PPCE200ZX_293_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_294_ISR
extern void EE_PPCE200ZX_294_ISR(void);
#else
#define EE_PPCE200ZX_294_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_295_ISR
extern void EE_PPCE200ZX_295_ISR(void);
#else
#define EE_PPCE200ZX_295_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_296_ISR
extern void EE_PPCE200ZX_296_ISR(void);
#else
#define EE_PPCE200ZX_296_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_297_ISR
extern void EE_PPCE200ZX_297_ISR(void);
#else
#define EE_PPCE200ZX_297_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_298_ISR
extern void EE_PPCE200ZX_298_ISR(void);
#else
#define EE_PPCE200ZX_298_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_299_ISR
extern void EE_PPCE200ZX_299_ISR(void);
#else
#define EE_PPCE200ZX_299_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_300_ISR
extern void EE_PPCE200ZX_300_ISR(void);
#else
#define EE_PPCE200ZX_300_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_301_ISR
extern void EE_PPCE200ZX_301_ISR(void);
#else
#define EE_PPCE200ZX_301_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_302_ISR
extern void EE_PPCE200ZX_302_ISR(void);
#else
#define EE_PPCE200ZX_302_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_303_ISR
extern void EE_PPCE200ZX_303_ISR(void);
#else
#define EE_PPCE200ZX_303_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_304_ISR
extern void EE_PPCE200ZX_304_ISR(void);
#else
#define EE_PPCE200ZX_304_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_305_ISR
extern void EE_PPCE200ZX_305_ISR(void);
#else
#define EE_PPCE200ZX_305_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_306_ISR
extern void EE_PPCE200ZX_306_ISR(void);
#else
#define EE_PPCE200ZX_306_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_307_ISR
extern void EE_PPCE200ZX_307_ISR(void);
#else
#define EE_PPCE200ZX_307_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_308_ISR
extern void EE_PPCE200ZX_308_ISR(void);
#else
#define EE_PPCE200ZX_308_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_309_ISR
extern void EE_PPCE200ZX_309_ISR(void);
#else
#define EE_PPCE200ZX_309_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_310_ISR
extern void EE_PPCE200ZX_310_ISR(void);
#else
#define EE_PPCE200ZX_310_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_311_ISR
extern void EE_PPCE200ZX_311_ISR(void);
#else
#define EE_PPCE200ZX_311_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_312_ISR
extern void EE_PPCE200ZX_312_ISR(void);
#else
#define EE_PPCE200ZX_312_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_313_ISR
extern void EE_PPCE200ZX_313_ISR(void);
#else
#define EE_PPCE200ZX_313_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_314_ISR
extern void EE_PPCE200ZX_314_ISR(void);
#else
#define EE_PPCE200ZX_314_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_315_ISR
extern void EE_PPCE200ZX_315_ISR(void);
#else
#define EE_PPCE200ZX_315_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_316_ISR
extern void EE_PPCE200ZX_316_ISR(void);
#else
#define EE_PPCE200ZX_316_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_317_ISR
extern void EE_PPCE200ZX_317_ISR(void);
#else
#define EE_PPCE200ZX_317_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_318_ISR
extern void EE_PPCE200ZX_318_ISR(void);
#else
#define EE_PPCE200ZX_318_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_319_ISR
extern void EE_PPCE200ZX_319_ISR(void);
#else
#define EE_PPCE200ZX_319_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_320_ISR
extern void EE_PPCE200ZX_320_ISR(void);
#else
#define EE_PPCE200ZX_320_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_321_ISR
extern void EE_PPCE200ZX_321_ISR(void);
#else
#define EE_PPCE200ZX_321_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_322_ISR
extern void EE_PPCE200ZX_322_ISR(void);
#else
#define EE_PPCE200ZX_322_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_323_ISR
extern void EE_PPCE200ZX_323_ISR(void);
#else
#define EE_PPCE200ZX_323_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_324_ISR
extern void EE_PPCE200ZX_324_ISR(void);
#else
#define EE_PPCE200ZX_324_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_325_ISR
extern void EE_PPCE200ZX_325_ISR(void);
#else
#define EE_PPCE200ZX_325_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_326_ISR
extern void EE_PPCE200ZX_326_ISR(void);
#else
#define EE_PPCE200ZX_326_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_327_ISR
extern void EE_PPCE200ZX_327_ISR(void);
#else
#define EE_PPCE200ZX_327_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_328_ISR
extern void EE_PPCE200ZX_328_ISR(void);
#else
#define EE_PPCE200ZX_328_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_329_ISR
extern void EE_PPCE200ZX_329_ISR(void);
#else
#define EE_PPCE200ZX_329_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_330_ISR
extern void EE_PPCE200ZX_330_ISR(void);
#else
#define EE_PPCE200ZX_330_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_331_ISR
extern void EE_PPCE200ZX_331_ISR(void);
#else
#define EE_PPCE200ZX_331_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_332_ISR
extern void EE_PPCE200ZX_332_ISR(void);
#else
#define EE_PPCE200ZX_332_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_333_ISR
extern void EE_PPCE200ZX_333_ISR(void);
#else
#define EE_PPCE200ZX_333_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_334_ISR
extern void EE_PPCE200ZX_334_ISR(void);
#else
#define EE_PPCE200ZX_334_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_335_ISR
extern void EE_PPCE200ZX_335_ISR(void);
#else
#define EE_PPCE200ZX_335_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_336_ISR
extern void EE_PPCE200ZX_336_ISR(void);
#else
#define EE_PPCE200ZX_336_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_337_ISR
extern void EE_PPCE200ZX_337_ISR(void);
#else
#define EE_PPCE200ZX_337_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_338_ISR
extern void EE_PPCE200ZX_338_ISR(void);
#else
#define EE_PPCE200ZX_338_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_339_ISR
extern void EE_PPCE200ZX_339_ISR(void);
#else
#define EE_PPCE200ZX_339_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_340_ISR
extern void EE_PPCE200ZX_340_ISR(void);
#else
#define EE_PPCE200ZX_340_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_341_ISR
extern void EE_PPCE200ZX_341_ISR(void);
#else
#define EE_PPCE200ZX_341_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_342_ISR
extern void EE_PPCE200ZX_342_ISR(void);
#else
#define EE_PPCE200ZX_342_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_343_ISR
extern void EE_PPCE200ZX_343_ISR(void);
#else
#define EE_PPCE200ZX_343_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_344_ISR
extern void EE_PPCE200ZX_344_ISR(void);
#else
#define EE_PPCE200ZX_344_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_345_ISR
extern void EE_PPCE200ZX_345_ISR(void);
#else
#define EE_PPCE200ZX_345_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_346_ISR
extern void EE_PPCE200ZX_346_ISR(void);
#else
#define EE_PPCE200ZX_346_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_347_ISR
extern void EE_PPCE200ZX_347_ISR(void);
#else
#define EE_PPCE200ZX_347_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_348_ISR
extern void EE_PPCE200ZX_348_ISR(void);
#else
#define EE_PPCE200ZX_348_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_349_ISR
extern void EE_PPCE200ZX_349_ISR(void);
#else
#define EE_PPCE200ZX_349_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_350_ISR
extern void EE_PPCE200ZX_350_ISR(void);
#else
#define EE_PPCE200ZX_350_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_351_ISR
extern void EE_PPCE200ZX_351_ISR(void);
#else
#define EE_PPCE200ZX_351_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_352_ISR
extern void EE_PPCE200ZX_352_ISR(void);
#else
#define EE_PPCE200ZX_352_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_353_ISR
extern void EE_PPCE200ZX_353_ISR(void);
#else
#define EE_PPCE200ZX_353_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_354_ISR
extern void EE_PPCE200ZX_354_ISR(void);
#else
#define EE_PPCE200ZX_354_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_355_ISR
extern void EE_PPCE200ZX_355_ISR(void);
#else
#define EE_PPCE200ZX_355_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_356_ISR
extern void EE_PPCE200ZX_356_ISR(void);
#else
#define EE_PPCE200ZX_356_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_357_ISR
extern void EE_PPCE200ZX_357_ISR(void);
#else
#define EE_PPCE200ZX_357_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_358_ISR
extern void EE_PPCE200ZX_358_ISR(void);
#else
#define EE_PPCE200ZX_358_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_359_ISR
extern void EE_PPCE200ZX_359_ISR(void);
#else
#define EE_PPCE200ZX_359_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_360_ISR
extern void EE_PPCE200ZX_360_ISR(void);
#else
#define EE_PPCE200ZX_360_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_361_ISR
extern void EE_PPCE200ZX_361_ISR(void);
#else
#define EE_PPCE200ZX_361_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_362_ISR
extern void EE_PPCE200ZX_362_ISR(void);
#else
#define EE_PPCE200ZX_362_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_363_ISR
extern void EE_PPCE200ZX_363_ISR(void);
#else
#define EE_PPCE200ZX_363_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_364_ISR
extern void EE_PPCE200ZX_364_ISR(void);
#else
#define EE_PPCE200ZX_364_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_365_ISR
extern void EE_PPCE200ZX_365_ISR(void);
#else
#define EE_PPCE200ZX_365_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_366_ISR
extern void EE_PPCE200ZX_366_ISR(void);
#else
#define EE_PPCE200ZX_366_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_367_ISR
extern void EE_PPCE200ZX_367_ISR(void);
#else
#define EE_PPCE200ZX_367_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_368_ISR
extern void EE_PPCE200ZX_368_ISR(void);
#else
#define EE_PPCE200ZX_368_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_369_ISR
extern void EE_PPCE200ZX_369_ISR(void);
#else
#define EE_PPCE200ZX_369_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_370_ISR
extern void EE_PPCE200ZX_370_ISR(void);
#else
#define EE_PPCE200ZX_370_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_371_ISR
extern void EE_PPCE200ZX_371_ISR(void);
#else
#define EE_PPCE200ZX_371_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_372_ISR
extern void EE_PPCE200ZX_372_ISR(void);
#else
#define EE_PPCE200ZX_372_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_373_ISR
extern void EE_PPCE200ZX_373_ISR(void);
#else
#define EE_PPCE200ZX_373_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_374_ISR
extern void EE_PPCE200ZX_374_ISR(void);
#else
#define EE_PPCE200ZX_374_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_375_ISR
extern void EE_PPCE200ZX_375_ISR(void);
#else
#define EE_PPCE200ZX_375_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_376_ISR
extern void EE_PPCE200ZX_376_ISR(void);
#else
#define EE_PPCE200ZX_376_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_377_ISR
extern void EE_PPCE200ZX_377_ISR(void);
#else
#define EE_PPCE200ZX_377_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_378_ISR
extern void EE_PPCE200ZX_378_ISR(void);
#else
#define EE_PPCE200ZX_378_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_379_ISR
extern void EE_PPCE200ZX_379_ISR(void);
#else
#define EE_PPCE200ZX_379_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_380_ISR
extern void EE_PPCE200ZX_380_ISR(void);
#else
#define EE_PPCE200ZX_380_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_381_ISR
extern void EE_PPCE200ZX_381_ISR(void);
#else
#define EE_PPCE200ZX_381_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_382_ISR
extern void EE_PPCE200ZX_382_ISR(void);
#else
#define EE_PPCE200ZX_382_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_383_ISR
extern void EE_PPCE200ZX_383_ISR(void);
#else
#define EE_PPCE200ZX_383_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_384_ISR
extern void EE_PPCE200ZX_384_ISR(void);
#else
#define EE_PPCE200ZX_384_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_385_ISR
extern void EE_PPCE200ZX_385_ISR(void);
#else
#define EE_PPCE200ZX_385_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_386_ISR
extern void EE_PPCE200ZX_386_ISR(void);
#else
#define EE_PPCE200ZX_386_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_387_ISR
extern void EE_PPCE200ZX_387_ISR(void);
#else
#define EE_PPCE200ZX_387_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_388_ISR
extern void EE_PPCE200ZX_388_ISR(void);
#else
#define EE_PPCE200ZX_388_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_389_ISR
extern void EE_PPCE200ZX_389_ISR(void);
#else
#define EE_PPCE200ZX_389_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_390_ISR
extern void EE_PPCE200ZX_390_ISR(void);
#else
#define EE_PPCE200ZX_390_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_391_ISR
extern void EE_PPCE200ZX_391_ISR(void);
#else
#define EE_PPCE200ZX_391_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_392_ISR
extern void EE_PPCE200ZX_392_ISR(void);
#else
#define EE_PPCE200ZX_392_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_393_ISR
extern void EE_PPCE200ZX_393_ISR(void);
#else
#define EE_PPCE200ZX_393_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_394_ISR
extern void EE_PPCE200ZX_394_ISR(void);
#else
#define EE_PPCE200ZX_394_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_395_ISR
extern void EE_PPCE200ZX_395_ISR(void);
#else
#define EE_PPCE200ZX_395_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_396_ISR
extern void EE_PPCE200ZX_396_ISR(void);
#else
#define EE_PPCE200ZX_396_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_397_ISR
extern void EE_PPCE200ZX_397_ISR(void);
#else
#define EE_PPCE200ZX_397_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_398_ISR
extern void EE_PPCE200ZX_398_ISR(void);
#else
#define EE_PPCE200ZX_398_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_399_ISR
extern void EE_PPCE200ZX_399_ISR(void);
#else
#define EE_PPCE200ZX_399_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_400_ISR
extern void EE_PPCE200ZX_400_ISR(void);
#else
#define EE_PPCE200ZX_400_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_401_ISR
extern void EE_PPCE200ZX_401_ISR(void);
#else
#define EE_PPCE200ZX_401_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_402_ISR
extern void EE_PPCE200ZX_402_ISR(void);
#else
#define EE_PPCE200ZX_402_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_403_ISR
extern void EE_PPCE200ZX_403_ISR(void);
#else
#define EE_PPCE200ZX_403_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_404_ISR
extern void EE_PPCE200ZX_404_ISR(void);
#else
#define EE_PPCE200ZX_404_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_405_ISR
extern void EE_PPCE200ZX_405_ISR(void);
#else
#define EE_PPCE200ZX_405_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_406_ISR
extern void EE_PPCE200ZX_406_ISR(void);
#else
#define EE_PPCE200ZX_406_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_407_ISR
extern void EE_PPCE200ZX_407_ISR(void);
#else
#define EE_PPCE200ZX_407_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_408_ISR
extern void EE_PPCE200ZX_408_ISR(void);
#else
#define EE_PPCE200ZX_408_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_409_ISR
extern void EE_PPCE200ZX_409_ISR(void);
#else
#define EE_PPCE200ZX_409_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_410_ISR
extern void EE_PPCE200ZX_410_ISR(void);
#else
#define EE_PPCE200ZX_410_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_411_ISR
extern void EE_PPCE200ZX_411_ISR(void);
#else
#define EE_PPCE200ZX_411_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_412_ISR
extern void EE_PPCE200ZX_412_ISR(void);
#else
#define EE_PPCE200ZX_412_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_413_ISR
extern void EE_PPCE200ZX_413_ISR(void);
#else
#define EE_PPCE200ZX_413_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_414_ISR
extern void EE_PPCE200ZX_414_ISR(void);
#else
#define EE_PPCE200ZX_414_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_415_ISR
extern void EE_PPCE200ZX_415_ISR(void);
#else
#define EE_PPCE200ZX_415_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_416_ISR
extern void EE_PPCE200ZX_416_ISR(void);
#else
#define EE_PPCE200ZX_416_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_417_ISR
extern void EE_PPCE200ZX_417_ISR(void);
#else
#define EE_PPCE200ZX_417_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_418_ISR
extern void EE_PPCE200ZX_418_ISR(void);
#else
#define EE_PPCE200ZX_418_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_419_ISR
extern void EE_PPCE200ZX_419_ISR(void);
#else
#define EE_PPCE200ZX_419_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_420_ISR
extern void EE_PPCE200ZX_420_ISR(void);
#else
#define EE_PPCE200ZX_420_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_421_ISR
extern void EE_PPCE200ZX_421_ISR(void);
#else
#define EE_PPCE200ZX_421_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_422_ISR
extern void EE_PPCE200ZX_422_ISR(void);
#else
#define EE_PPCE200ZX_422_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_423_ISR
extern void EE_PPCE200ZX_423_ISR(void);
#else
#define EE_PPCE200ZX_423_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_424_ISR
extern void EE_PPCE200ZX_424_ISR(void);
#else
#define EE_PPCE200ZX_424_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_425_ISR
extern void EE_PPCE200ZX_425_ISR(void);
#else
#define EE_PPCE200ZX_425_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_426_ISR
extern void EE_PPCE200ZX_426_ISR(void);
#else
#define EE_PPCE200ZX_426_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_427_ISR
extern void EE_PPCE200ZX_427_ISR(void);
#else
#define EE_PPCE200ZX_427_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_428_ISR
extern void EE_PPCE200ZX_428_ISR(void);
#else
#define EE_PPCE200ZX_428_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_429_ISR
extern void EE_PPCE200ZX_429_ISR(void);
#else
#define EE_PPCE200ZX_429_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_430_ISR
extern void EE_PPCE200ZX_430_ISR(void);
#else
#define EE_PPCE200ZX_430_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_431_ISR
extern void EE_PPCE200ZX_431_ISR(void);
#else
#define EE_PPCE200ZX_431_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_432_ISR
extern void EE_PPCE200ZX_432_ISR(void);
#else
#define EE_PPCE200ZX_432_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_433_ISR
extern void EE_PPCE200ZX_433_ISR(void);
#else
#define EE_PPCE200ZX_433_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_434_ISR
extern void EE_PPCE200ZX_434_ISR(void);
#else
#define EE_PPCE200ZX_434_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_435_ISR
extern void EE_PPCE200ZX_435_ISR(void);
#else
#define EE_PPCE200ZX_435_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_436_ISR
extern void EE_PPCE200ZX_436_ISR(void);
#else
#define EE_PPCE200ZX_436_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_437_ISR
extern void EE_PPCE200ZX_437_ISR(void);
#else
#define EE_PPCE200ZX_437_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_438_ISR
extern void EE_PPCE200ZX_438_ISR(void);
#else
#define EE_PPCE200ZX_438_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_439_ISR
extern void EE_PPCE200ZX_439_ISR(void);
#else
#define EE_PPCE200ZX_439_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_440_ISR
extern void EE_PPCE200ZX_440_ISR(void);
#else
#define EE_PPCE200ZX_440_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_441_ISR
extern void EE_PPCE200ZX_441_ISR(void);
#else
#define EE_PPCE200ZX_441_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_442_ISR
extern void EE_PPCE200ZX_442_ISR(void);
#else
#define EE_PPCE200ZX_442_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_443_ISR
extern void EE_PPCE200ZX_443_ISR(void);
#else
#define EE_PPCE200ZX_443_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_444_ISR
extern void EE_PPCE200ZX_444_ISR(void);
#else
#define EE_PPCE200ZX_444_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_445_ISR
extern void EE_PPCE200ZX_445_ISR(void);
#else
#define EE_PPCE200ZX_445_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_446_ISR
extern void EE_PPCE200ZX_446_ISR(void);
#else
#define EE_PPCE200ZX_446_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_447_ISR
extern void EE_PPCE200ZX_447_ISR(void);
#else
#define EE_PPCE200ZX_447_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_448_ISR
extern void EE_PPCE200ZX_448_ISR(void);
#else
#define EE_PPCE200ZX_448_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_449_ISR
extern void EE_PPCE200ZX_449_ISR(void);
#else
#define EE_PPCE200ZX_449_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_450_ISR
extern void EE_PPCE200ZX_450_ISR(void);
#else
#define EE_PPCE200ZX_450_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_451_ISR
extern void EE_PPCE200ZX_451_ISR(void);
#else
#define EE_PPCE200ZX_451_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_452_ISR
extern void EE_PPCE200ZX_452_ISR(void);
#else
#define EE_PPCE200ZX_452_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_453_ISR
extern void EE_PPCE200ZX_453_ISR(void);
#else
#define EE_PPCE200ZX_453_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_454_ISR
extern void EE_PPCE200ZX_454_ISR(void);
#else
#define EE_PPCE200ZX_454_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_455_ISR
extern void EE_PPCE200ZX_455_ISR(void);
#else
#define EE_PPCE200ZX_455_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_456_ISR
extern void EE_PPCE200ZX_456_ISR(void);
#else
#define EE_PPCE200ZX_456_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_457_ISR
extern void EE_PPCE200ZX_457_ISR(void);
#else
#define EE_PPCE200ZX_457_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_458_ISR
extern void EE_PPCE200ZX_458_ISR(void);
#else
#define EE_PPCE200ZX_458_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_459_ISR
extern void EE_PPCE200ZX_459_ISR(void);
#else
#define EE_PPCE200ZX_459_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_460_ISR
extern void EE_PPCE200ZX_460_ISR(void);
#else
#define EE_PPCE200ZX_460_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_461_ISR
extern void EE_PPCE200ZX_461_ISR(void);
#else
#define EE_PPCE200ZX_461_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_462_ISR
extern void EE_PPCE200ZX_462_ISR(void);
#else
#define EE_PPCE200ZX_462_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_463_ISR
extern void EE_PPCE200ZX_463_ISR(void);
#else
#define EE_PPCE200ZX_463_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_464_ISR
extern void EE_PPCE200ZX_464_ISR(void);
#else
#define EE_PPCE200ZX_464_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_465_ISR
extern void EE_PPCE200ZX_465_ISR(void);
#else
#define EE_PPCE200ZX_465_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_466_ISR
extern void EE_PPCE200ZX_466_ISR(void);
#else
#define EE_PPCE200ZX_466_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_467_ISR
extern void EE_PPCE200ZX_467_ISR(void);
#else
#define EE_PPCE200ZX_467_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_468_ISR
extern void EE_PPCE200ZX_468_ISR(void);
#else
#define EE_PPCE200ZX_468_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_469_ISR
extern void EE_PPCE200ZX_469_ISR(void);
#else
#define EE_PPCE200ZX_469_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_470_ISR
extern void EE_PPCE200ZX_470_ISR(void);
#else
#define EE_PPCE200ZX_470_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_471_ISR
extern void EE_PPCE200ZX_471_ISR(void);
#else
#define EE_PPCE200ZX_471_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_472_ISR
extern void EE_PPCE200ZX_472_ISR(void);
#else
#define EE_PPCE200ZX_472_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_473_ISR
extern void EE_PPCE200ZX_473_ISR(void);
#else
#define EE_PPCE200ZX_473_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_474_ISR
extern void EE_PPCE200ZX_474_ISR(void);
#else
#define EE_PPCE200ZX_474_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_475_ISR
extern void EE_PPCE200ZX_475_ISR(void);
#else
#define EE_PPCE200ZX_475_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_476_ISR
extern void EE_PPCE200ZX_476_ISR(void);
#else
#define EE_PPCE200ZX_476_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_477_ISR
extern void EE_PPCE200ZX_477_ISR(void);
#else
#define EE_PPCE200ZX_477_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_478_ISR
extern void EE_PPCE200ZX_478_ISR(void);
#else
#define EE_PPCE200ZX_478_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_479_ISR
extern void EE_PPCE200ZX_479_ISR(void);
#else
#define EE_PPCE200ZX_479_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_480_ISR
extern void EE_PPCE200ZX_480_ISR(void);
#else
#define EE_PPCE200ZX_480_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_481_ISR
extern void EE_PPCE200ZX_481_ISR(void);
#else
#define EE_PPCE200ZX_481_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_482_ISR
extern void EE_PPCE200ZX_482_ISR(void);
#else
#define EE_PPCE200ZX_482_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_483_ISR
extern void EE_PPCE200ZX_483_ISR(void);
#else
#define EE_PPCE200ZX_483_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_484_ISR
extern void EE_PPCE200ZX_484_ISR(void);
#else
#define EE_PPCE200ZX_484_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_485_ISR
extern void EE_PPCE200ZX_485_ISR(void);
#else
#define EE_PPCE200ZX_485_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_486_ISR
extern void EE_PPCE200ZX_486_ISR(void);
#else
#define EE_PPCE200ZX_486_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_487_ISR
extern void EE_PPCE200ZX_487_ISR(void);
#else
#define EE_PPCE200ZX_487_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_488_ISR
extern void EE_PPCE200ZX_488_ISR(void);
#else
#define EE_PPCE200ZX_488_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_489_ISR
extern void EE_PPCE200ZX_489_ISR(void);
#else
#define EE_PPCE200ZX_489_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_490_ISR
extern void EE_PPCE200ZX_490_ISR(void);
#else
#define EE_PPCE200ZX_490_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_491_ISR
extern void EE_PPCE200ZX_491_ISR(void);
#else
#define EE_PPCE200ZX_491_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_492_ISR
extern void EE_PPCE200ZX_492_ISR(void);
#else
#define EE_PPCE200ZX_492_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_493_ISR
extern void EE_PPCE200ZX_493_ISR(void);
#else
#define EE_PPCE200ZX_493_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_494_ISR
extern void EE_PPCE200ZX_494_ISR(void);
#else
#define EE_PPCE200ZX_494_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_495_ISR
extern void EE_PPCE200ZX_495_ISR(void);
#else
#define EE_PPCE200ZX_495_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_496_ISR
extern void EE_PPCE200ZX_496_ISR(void);
#else
#define EE_PPCE200ZX_496_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_497_ISR
extern void EE_PPCE200ZX_497_ISR(void);
#else
#define EE_PPCE200ZX_497_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_498_ISR
extern void EE_PPCE200ZX_498_ISR(void);
#else
#define EE_PPCE200ZX_498_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_499_ISR
extern void EE_PPCE200ZX_499_ISR(void);
#else
#define EE_PPCE200ZX_499_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_500_ISR
extern void EE_PPCE200ZX_500_ISR(void);
#else
#define EE_PPCE200ZX_500_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_501_ISR
extern void EE_PPCE200ZX_501_ISR(void);
#else
#define EE_PPCE200ZX_501_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_502_ISR
extern void EE_PPCE200ZX_502_ISR(void);
#else
#define EE_PPCE200ZX_502_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_503_ISR
extern void EE_PPCE200ZX_503_ISR(void);
#else
#define EE_PPCE200ZX_503_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_504_ISR
extern void EE_PPCE200ZX_504_ISR(void);
#else
#define EE_PPCE200ZX_504_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_505_ISR
extern void EE_PPCE200ZX_505_ISR(void);
#else
#define EE_PPCE200ZX_505_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_506_ISR
extern void EE_PPCE200ZX_506_ISR(void);
#else
#define EE_PPCE200ZX_506_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_507_ISR
extern void EE_PPCE200ZX_507_ISR(void);
#else
#define EE_PPCE200ZX_507_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_508_ISR
extern void EE_PPCE200ZX_508_ISR(void);
#else
#define EE_PPCE200ZX_508_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_509_ISR
extern void EE_PPCE200ZX_509_ISR(void);
#else
#define EE_PPCE200ZX_509_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_510_ISR
extern void EE_PPCE200ZX_510_ISR(void);
#else
#define EE_PPCE200ZX_510_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_511_ISR
extern void EE_PPCE200ZX_511_ISR(void);
#else
#define EE_PPCE200ZX_511_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_512_ISR
extern void EE_PPCE200ZX_512_ISR(void);
#else
#define EE_PPCE200ZX_512_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_513_ISR
extern void EE_PPCE200ZX_513_ISR(void);
#else
#define EE_PPCE200ZX_513_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_514_ISR
extern void EE_PPCE200ZX_514_ISR(void);
#else
#define EE_PPCE200ZX_514_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_515_ISR
extern void EE_PPCE200ZX_515_ISR(void);
#else
#define EE_PPCE200ZX_515_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_516_ISR
extern void EE_PPCE200ZX_516_ISR(void);
#else
#define EE_PPCE200ZX_516_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_517_ISR
extern void EE_PPCE200ZX_517_ISR(void);
#else
#define EE_PPCE200ZX_517_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_518_ISR
extern void EE_PPCE200ZX_518_ISR(void);
#else
#define EE_PPCE200ZX_518_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_519_ISR
extern void EE_PPCE200ZX_519_ISR(void);
#else
#define EE_PPCE200ZX_519_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_520_ISR
extern void EE_PPCE200ZX_520_ISR(void);
#else
#define EE_PPCE200ZX_520_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_521_ISR
extern void EE_PPCE200ZX_521_ISR(void);
#else
#define EE_PPCE200ZX_521_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_522_ISR
extern void EE_PPCE200ZX_522_ISR(void);
#else
#define EE_PPCE200ZX_522_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_523_ISR
extern void EE_PPCE200ZX_523_ISR(void);
#else
#define EE_PPCE200ZX_523_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_524_ISR
extern void EE_PPCE200ZX_524_ISR(void);
#else
#define EE_PPCE200ZX_524_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_525_ISR
extern void EE_PPCE200ZX_525_ISR(void);
#else
#define EE_PPCE200ZX_525_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_526_ISR
extern void EE_PPCE200ZX_526_ISR(void);
#else
#define EE_PPCE200ZX_526_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_527_ISR
extern void EE_PPCE200ZX_527_ISR(void);
#else
#define EE_PPCE200ZX_527_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_528_ISR
extern void EE_PPCE200ZX_528_ISR(void);
#else
#define EE_PPCE200ZX_528_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_529_ISR
extern void EE_PPCE200ZX_529_ISR(void);
#else
#define EE_PPCE200ZX_529_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_530_ISR
extern void EE_PPCE200ZX_530_ISR(void);
#else
#define EE_PPCE200ZX_530_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_531_ISR
extern void EE_PPCE200ZX_531_ISR(void);
#else
#define EE_PPCE200ZX_531_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_532_ISR
extern void EE_PPCE200ZX_532_ISR(void);
#else
#define EE_PPCE200ZX_532_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_533_ISR
extern void EE_PPCE200ZX_533_ISR(void);
#else
#define EE_PPCE200ZX_533_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_534_ISR
extern void EE_PPCE200ZX_534_ISR(void);
#else
#define EE_PPCE200ZX_534_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_535_ISR
extern void EE_PPCE200ZX_535_ISR(void);
#else
#define EE_PPCE200ZX_535_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_536_ISR
extern void EE_PPCE200ZX_536_ISR(void);
#else
#define EE_PPCE200ZX_536_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_537_ISR
extern void EE_PPCE200ZX_537_ISR(void);
#else
#define EE_PPCE200ZX_537_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_538_ISR
extern void EE_PPCE200ZX_538_ISR(void);
#else
#define EE_PPCE200ZX_538_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_539_ISR
extern void EE_PPCE200ZX_539_ISR(void);
#else
#define EE_PPCE200ZX_539_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_540_ISR
extern void EE_PPCE200ZX_540_ISR(void);
#else
#define EE_PPCE200ZX_540_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_541_ISR
extern void EE_PPCE200ZX_541_ISR(void);
#else
#define EE_PPCE200ZX_541_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_542_ISR
extern void EE_PPCE200ZX_542_ISR(void);
#else
#define EE_PPCE200ZX_542_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_543_ISR
extern void EE_PPCE200ZX_543_ISR(void);
#else
#define EE_PPCE200ZX_543_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_544_ISR
extern void EE_PPCE200ZX_544_ISR(void);
#else
#define EE_PPCE200ZX_544_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_545_ISR
extern void EE_PPCE200ZX_545_ISR(void);
#else
#define EE_PPCE200ZX_545_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_546_ISR
extern void EE_PPCE200ZX_546_ISR(void);
#else
#define EE_PPCE200ZX_546_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_547_ISR
extern void EE_PPCE200ZX_547_ISR(void);
#else
#define EE_PPCE200ZX_547_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_548_ISR
extern void EE_PPCE200ZX_548_ISR(void);
#else
#define EE_PPCE200ZX_548_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_549_ISR
extern void EE_PPCE200ZX_549_ISR(void);
#else
#define EE_PPCE200ZX_549_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_550_ISR
extern void EE_PPCE200ZX_550_ISR(void);
#else
#define EE_PPCE200ZX_550_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_551_ISR
extern void EE_PPCE200ZX_551_ISR(void);
#else
#define EE_PPCE200ZX_551_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_552_ISR
extern void EE_PPCE200ZX_552_ISR(void);
#else
#define EE_PPCE200ZX_552_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_553_ISR
extern void EE_PPCE200ZX_553_ISR(void);
#else
#define EE_PPCE200ZX_553_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_554_ISR
extern void EE_PPCE200ZX_554_ISR(void);
#else
#define EE_PPCE200ZX_554_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_555_ISR
extern void EE_PPCE200ZX_555_ISR(void);
#else
#define EE_PPCE200ZX_555_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_556_ISR
extern void EE_PPCE200ZX_556_ISR(void);
#else
#define EE_PPCE200ZX_556_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_557_ISR
extern void EE_PPCE200ZX_557_ISR(void);
#else
#define EE_PPCE200ZX_557_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_558_ISR
extern void EE_PPCE200ZX_558_ISR(void);
#else
#define EE_PPCE200ZX_558_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_559_ISR
extern void EE_PPCE200ZX_559_ISR(void);
#else
#define EE_PPCE200ZX_559_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_560_ISR
extern void EE_PPCE200ZX_560_ISR(void);
#else
#define EE_PPCE200ZX_560_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_561_ISR
extern void EE_PPCE200ZX_561_ISR(void);
#else
#define EE_PPCE200ZX_561_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_562_ISR
extern void EE_PPCE200ZX_562_ISR(void);
#else
#define EE_PPCE200ZX_562_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_563_ISR
extern void EE_PPCE200ZX_563_ISR(void);
#else
#define EE_PPCE200ZX_563_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_564_ISR
extern void EE_PPCE200ZX_564_ISR(void);
#else
#define EE_PPCE200ZX_564_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_565_ISR
extern void EE_PPCE200ZX_565_ISR(void);
#else
#define EE_PPCE200ZX_565_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_566_ISR
extern void EE_PPCE200ZX_566_ISR(void);
#else
#define EE_PPCE200ZX_566_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_567_ISR
extern void EE_PPCE200ZX_567_ISR(void);
#else
#define EE_PPCE200ZX_567_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_568_ISR
extern void EE_PPCE200ZX_568_ISR(void);
#else
#define EE_PPCE200ZX_568_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_569_ISR
extern void EE_PPCE200ZX_569_ISR(void);
#else
#define EE_PPCE200ZX_569_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_570_ISR
extern void EE_PPCE200ZX_570_ISR(void);
#else
#define EE_PPCE200ZX_570_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_571_ISR
extern void EE_PPCE200ZX_571_ISR(void);
#else
#define EE_PPCE200ZX_571_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_572_ISR
extern void EE_PPCE200ZX_572_ISR(void);
#else
#define EE_PPCE200ZX_572_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_573_ISR
extern void EE_PPCE200ZX_573_ISR(void);
#else
#define EE_PPCE200ZX_573_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_574_ISR
extern void EE_PPCE200ZX_574_ISR(void);
#else
#define EE_PPCE200ZX_574_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_575_ISR
extern void EE_PPCE200ZX_575_ISR(void);
#else
#define EE_PPCE200ZX_575_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_576_ISR
extern void EE_PPCE200ZX_576_ISR(void);
#else
#define EE_PPCE200ZX_576_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_577_ISR
extern void EE_PPCE200ZX_577_ISR(void);
#else
#define EE_PPCE200ZX_577_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_578_ISR
extern void EE_PPCE200ZX_578_ISR(void);
#else
#define EE_PPCE200ZX_578_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_579_ISR
extern void EE_PPCE200ZX_579_ISR(void);
#else
#define EE_PPCE200ZX_579_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_580_ISR
extern void EE_PPCE200ZX_580_ISR(void);
#else
#define EE_PPCE200ZX_580_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_581_ISR
extern void EE_PPCE200ZX_581_ISR(void);
#else
#define EE_PPCE200ZX_581_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_582_ISR
extern void EE_PPCE200ZX_582_ISR(void);
#else
#define EE_PPCE200ZX_582_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_583_ISR
extern void EE_PPCE200ZX_583_ISR(void);
#else
#define EE_PPCE200ZX_583_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_584_ISR
extern void EE_PPCE200ZX_584_ISR(void);
#else
#define EE_PPCE200ZX_584_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_585_ISR
extern void EE_PPCE200ZX_585_ISR(void);
#else
#define EE_PPCE200ZX_585_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_586_ISR
extern void EE_PPCE200ZX_586_ISR(void);
#else
#define EE_PPCE200ZX_586_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_587_ISR
extern void EE_PPCE200ZX_587_ISR(void);
#else
#define EE_PPCE200ZX_587_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_588_ISR
extern void EE_PPCE200ZX_588_ISR(void);
#else
#define EE_PPCE200ZX_588_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_589_ISR
extern void EE_PPCE200ZX_589_ISR(void);
#else
#define EE_PPCE200ZX_589_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_590_ISR
extern void EE_PPCE200ZX_590_ISR(void);
#else
#define EE_PPCE200ZX_590_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_591_ISR
extern void EE_PPCE200ZX_591_ISR(void);
#else
#define EE_PPCE200ZX_591_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_592_ISR
extern void EE_PPCE200ZX_592_ISR(void);
#else
#define EE_PPCE200ZX_592_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_593_ISR
extern void EE_PPCE200ZX_593_ISR(void);
#else
#define EE_PPCE200ZX_593_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_594_ISR
extern void EE_PPCE200ZX_594_ISR(void);
#else
#define EE_PPCE200ZX_594_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_595_ISR
extern void EE_PPCE200ZX_595_ISR(void);
#else
#define EE_PPCE200ZX_595_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_596_ISR
extern void EE_PPCE200ZX_596_ISR(void);
#else
#define EE_PPCE200ZX_596_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_597_ISR
extern void EE_PPCE200ZX_597_ISR(void);
#else
#define EE_PPCE200ZX_597_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_598_ISR
extern void EE_PPCE200ZX_598_ISR(void);
#else
#define EE_PPCE200ZX_598_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_599_ISR
extern void EE_PPCE200ZX_599_ISR(void);
#else
#define EE_PPCE200ZX_599_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_600_ISR
extern void EE_PPCE200ZX_600_ISR(void);
#else
#define EE_PPCE200ZX_600_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_601_ISR
extern void EE_PPCE200ZX_601_ISR(void);
#else
#define EE_PPCE200ZX_601_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_602_ISR
extern void EE_PPCE200ZX_602_ISR(void);
#else
#define EE_PPCE200ZX_602_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_603_ISR
extern void EE_PPCE200ZX_603_ISR(void);
#else
#define EE_PPCE200ZX_603_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_604_ISR
extern void EE_PPCE200ZX_604_ISR(void);
#else
#define EE_PPCE200ZX_604_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_605_ISR
extern void EE_PPCE200ZX_605_ISR(void);
#else
#define EE_PPCE200ZX_605_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_606_ISR
extern void EE_PPCE200ZX_606_ISR(void);
#else
#define EE_PPCE200ZX_606_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_607_ISR
extern void EE_PPCE200ZX_607_ISR(void);
#else
#define EE_PPCE200ZX_607_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_608_ISR
extern void EE_PPCE200ZX_608_ISR(void);
#else
#define EE_PPCE200ZX_608_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_609_ISR
extern void EE_PPCE200ZX_609_ISR(void);
#else
#define EE_PPCE200ZX_609_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_610_ISR
extern void EE_PPCE200ZX_610_ISR(void);
#else
#define EE_PPCE200ZX_610_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_611_ISR
extern void EE_PPCE200ZX_611_ISR(void);
#else
#define EE_PPCE200ZX_611_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_612_ISR
extern void EE_PPCE200ZX_612_ISR(void);
#else
#define EE_PPCE200ZX_612_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_613_ISR
extern void EE_PPCE200ZX_613_ISR(void);
#else
#define EE_PPCE200ZX_613_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_614_ISR
extern void EE_PPCE200ZX_614_ISR(void);
#else
#define EE_PPCE200ZX_614_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_615_ISR
extern void EE_PPCE200ZX_615_ISR(void);
#else
#define EE_PPCE200ZX_615_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_616_ISR
extern void EE_PPCE200ZX_616_ISR(void);
#else
#define EE_PPCE200ZX_616_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_617_ISR
extern void EE_PPCE200ZX_617_ISR(void);
#else
#define EE_PPCE200ZX_617_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_618_ISR
extern void EE_PPCE200ZX_618_ISR(void);
#else
#define EE_PPCE200ZX_618_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_619_ISR
extern void EE_PPCE200ZX_619_ISR(void);
#else
#define EE_PPCE200ZX_619_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_620_ISR
extern void EE_PPCE200ZX_620_ISR(void);
#else
#define EE_PPCE200ZX_620_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_621_ISR
extern void EE_PPCE200ZX_621_ISR(void);
#else
#define EE_PPCE200ZX_621_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_622_ISR
extern void EE_PPCE200ZX_622_ISR(void);
#else
#define EE_PPCE200ZX_622_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_623_ISR
extern void EE_PPCE200ZX_623_ISR(void);
#else
#define EE_PPCE200ZX_623_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_624_ISR
extern void EE_PPCE200ZX_624_ISR(void);
#else
#define EE_PPCE200ZX_624_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_625_ISR
extern void EE_PPCE200ZX_625_ISR(void);
#else
#define EE_PPCE200ZX_625_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_626_ISR
extern void EE_PPCE200ZX_626_ISR(void);
#else
#define EE_PPCE200ZX_626_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_627_ISR
extern void EE_PPCE200ZX_627_ISR(void);
#else
#define EE_PPCE200ZX_627_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_628_ISR
extern void EE_PPCE200ZX_628_ISR(void);
#else
#define EE_PPCE200ZX_628_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_629_ISR
extern void EE_PPCE200ZX_629_ISR(void);
#else
#define EE_PPCE200ZX_629_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_630_ISR
extern void EE_PPCE200ZX_630_ISR(void);
#else
#define EE_PPCE200ZX_630_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_631_ISR
extern void EE_PPCE200ZX_631_ISR(void);
#else
#define EE_PPCE200ZX_631_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_632_ISR
extern void EE_PPCE200ZX_632_ISR(void);
#else
#define EE_PPCE200ZX_632_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_633_ISR
extern void EE_PPCE200ZX_633_ISR(void);
#else
#define EE_PPCE200ZX_633_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_634_ISR
extern void EE_PPCE200ZX_634_ISR(void);
#else
#define EE_PPCE200ZX_634_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_635_ISR
extern void EE_PPCE200ZX_635_ISR(void);
#else
#define EE_PPCE200ZX_635_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_636_ISR
extern void EE_PPCE200ZX_636_ISR(void);
#else
#define EE_PPCE200ZX_636_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_637_ISR
extern void EE_PPCE200ZX_637_ISR(void);
#else
#define EE_PPCE200ZX_637_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_638_ISR
extern void EE_PPCE200ZX_638_ISR(void);
#else
#define EE_PPCE200ZX_638_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_639_ISR
extern void EE_PPCE200ZX_639_ISR(void);
#else
#define EE_PPCE200ZX_639_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_640_ISR
extern void EE_PPCE200ZX_640_ISR(void);
#else
#define EE_PPCE200ZX_640_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_641_ISR
extern void EE_PPCE200ZX_641_ISR(void);
#else
#define EE_PPCE200ZX_641_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_642_ISR
extern void EE_PPCE200ZX_642_ISR(void);
#else
#define EE_PPCE200ZX_642_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_643_ISR
extern void EE_PPCE200ZX_643_ISR(void);
#else
#define EE_PPCE200ZX_643_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_644_ISR
extern void EE_PPCE200ZX_644_ISR(void);
#else
#define EE_PPCE200ZX_644_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_645_ISR
extern void EE_PPCE200ZX_645_ISR(void);
#else
#define EE_PPCE200ZX_645_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_646_ISR
extern void EE_PPCE200ZX_646_ISR(void);
#else
#define EE_PPCE200ZX_646_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_647_ISR
extern void EE_PPCE200ZX_647_ISR(void);
#else
#define EE_PPCE200ZX_647_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_648_ISR
extern void EE_PPCE200ZX_648_ISR(void);
#else
#define EE_PPCE200ZX_648_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_649_ISR
extern void EE_PPCE200ZX_649_ISR(void);
#else
#define EE_PPCE200ZX_649_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_650_ISR
extern void EE_PPCE200ZX_650_ISR(void);
#else
#define EE_PPCE200ZX_650_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_651_ISR
extern void EE_PPCE200ZX_651_ISR(void);
#else
#define EE_PPCE200ZX_651_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_652_ISR
extern void EE_PPCE200ZX_652_ISR(void);
#else
#define EE_PPCE200ZX_652_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_653_ISR
extern void EE_PPCE200ZX_653_ISR(void);
#else
#define EE_PPCE200ZX_653_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_654_ISR
extern void EE_PPCE200ZX_654_ISR(void);
#else
#define EE_PPCE200ZX_654_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_655_ISR
extern void EE_PPCE200ZX_655_ISR(void);
#else
#define EE_PPCE200ZX_655_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_656_ISR
extern void EE_PPCE200ZX_656_ISR(void);
#else
#define EE_PPCE200ZX_656_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_657_ISR
extern void EE_PPCE200ZX_657_ISR(void);
#else
#define EE_PPCE200ZX_657_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_658_ISR
extern void EE_PPCE200ZX_658_ISR(void);
#else
#define EE_PPCE200ZX_658_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_659_ISR
extern void EE_PPCE200ZX_659_ISR(void);
#else
#define EE_PPCE200ZX_659_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_660_ISR
extern void EE_PPCE200ZX_660_ISR(void);
#else
#define EE_PPCE200ZX_660_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_661_ISR
extern void EE_PPCE200ZX_661_ISR(void);
#else
#define EE_PPCE200ZX_661_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_662_ISR
extern void EE_PPCE200ZX_662_ISR(void);
#else
#define EE_PPCE200ZX_662_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_663_ISR
extern void EE_PPCE200ZX_663_ISR(void);
#else
#define EE_PPCE200ZX_663_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_664_ISR
extern void EE_PPCE200ZX_664_ISR(void);
#else
#define EE_PPCE200ZX_664_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_665_ISR
extern void EE_PPCE200ZX_665_ISR(void);
#else
#define EE_PPCE200ZX_665_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_666_ISR
extern void EE_PPCE200ZX_666_ISR(void);
#else
#define EE_PPCE200ZX_666_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_667_ISR
extern void EE_PPCE200ZX_667_ISR(void);
#else
#define EE_PPCE200ZX_667_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_668_ISR
extern void EE_PPCE200ZX_668_ISR(void);
#else
#define EE_PPCE200ZX_668_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_669_ISR
extern void EE_PPCE200ZX_669_ISR(void);
#else
#define EE_PPCE200ZX_669_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_670_ISR
extern void EE_PPCE200ZX_670_ISR(void);
#else
#define EE_PPCE200ZX_670_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_671_ISR
extern void EE_PPCE200ZX_671_ISR(void);
#else
#define EE_PPCE200ZX_671_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_672_ISR
extern void EE_PPCE200ZX_672_ISR(void);
#else
#define EE_PPCE200ZX_672_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_673_ISR
extern void EE_PPCE200ZX_673_ISR(void);
#else
#define EE_PPCE200ZX_673_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_674_ISR
extern void EE_PPCE200ZX_674_ISR(void);
#else
#define EE_PPCE200ZX_674_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_675_ISR
extern void EE_PPCE200ZX_675_ISR(void);
#else
#define EE_PPCE200ZX_675_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_676_ISR
extern void EE_PPCE200ZX_676_ISR(void);
#else
#define EE_PPCE200ZX_676_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_677_ISR
extern void EE_PPCE200ZX_677_ISR(void);
#else
#define EE_PPCE200ZX_677_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_678_ISR
extern void EE_PPCE200ZX_678_ISR(void);
#else
#define EE_PPCE200ZX_678_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_679_ISR
extern void EE_PPCE200ZX_679_ISR(void);
#else
#define EE_PPCE200ZX_679_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_680_ISR
extern void EE_PPCE200ZX_680_ISR(void);
#else
#define EE_PPCE200ZX_680_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_681_ISR
extern void EE_PPCE200ZX_681_ISR(void);
#else
#define EE_PPCE200ZX_681_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_682_ISR
extern void EE_PPCE200ZX_682_ISR(void);
#else
#define EE_PPCE200ZX_682_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_683_ISR
extern void EE_PPCE200ZX_683_ISR(void);
#else
#define EE_PPCE200ZX_683_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_684_ISR
extern void EE_PPCE200ZX_684_ISR(void);
#else
#define EE_PPCE200ZX_684_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_685_ISR
extern void EE_PPCE200ZX_685_ISR(void);
#else
#define EE_PPCE200ZX_685_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_686_ISR
extern void EE_PPCE200ZX_686_ISR(void);
#else
#define EE_PPCE200ZX_686_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_687_ISR
extern void EE_PPCE200ZX_687_ISR(void);
#else
#define EE_PPCE200ZX_687_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_688_ISR
extern void EE_PPCE200ZX_688_ISR(void);
#else
#define EE_PPCE200ZX_688_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_689_ISR
extern void EE_PPCE200ZX_689_ISR(void);
#else
#define EE_PPCE200ZX_689_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_690_ISR
extern void EE_PPCE200ZX_690_ISR(void);
#else
#define EE_PPCE200ZX_690_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_691_ISR
extern void EE_PPCE200ZX_691_ISR(void);
#else
#define EE_PPCE200ZX_691_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_692_ISR
extern void EE_PPCE200ZX_692_ISR(void);
#else
#define EE_PPCE200ZX_692_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_693_ISR
extern void EE_PPCE200ZX_693_ISR(void);
#else
#define EE_PPCE200ZX_693_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_694_ISR
extern void EE_PPCE200ZX_694_ISR(void);
#else
#define EE_PPCE200ZX_694_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_695_ISR
extern void EE_PPCE200ZX_695_ISR(void);
#else
#define EE_PPCE200ZX_695_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_696_ISR
extern void EE_PPCE200ZX_696_ISR(void);
#else
#define EE_PPCE200ZX_696_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_697_ISR
extern void EE_PPCE200ZX_697_ISR(void);
#else
#define EE_PPCE200ZX_697_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_698_ISR
extern void EE_PPCE200ZX_698_ISR(void);
#else
#define EE_PPCE200ZX_698_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_699_ISR
extern void EE_PPCE200ZX_699_ISR(void);
#else
#define EE_PPCE200ZX_699_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_700_ISR
extern void EE_PPCE200ZX_700_ISR(void);
#else
#define EE_PPCE200ZX_700_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_701_ISR
extern void EE_PPCE200ZX_701_ISR(void);
#else
#define EE_PPCE200ZX_701_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_702_ISR
extern void EE_PPCE200ZX_702_ISR(void);
#else
#define EE_PPCE200ZX_702_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_703_ISR
extern void EE_PPCE200ZX_703_ISR(void);
#else
#define EE_PPCE200ZX_703_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_704_ISR
extern void EE_PPCE200ZX_704_ISR(void);
#else
#define EE_PPCE200ZX_704_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_705_ISR
extern void EE_PPCE200ZX_705_ISR(void);
#else
#define EE_PPCE200ZX_705_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_706_ISR
extern void EE_PPCE200ZX_706_ISR(void);
#else
#define EE_PPCE200ZX_706_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_707_ISR
extern void EE_PPCE200ZX_707_ISR(void);
#else
#define EE_PPCE200ZX_707_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_708_ISR
extern void EE_PPCE200ZX_708_ISR(void);
#else
#define EE_PPCE200ZX_708_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_709_ISR
extern void EE_PPCE200ZX_709_ISR(void);
#else
#define EE_PPCE200ZX_709_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_710_ISR
extern void EE_PPCE200ZX_710_ISR(void);
#else
#define EE_PPCE200ZX_710_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_711_ISR
extern void EE_PPCE200ZX_711_ISR(void);
#else
#define EE_PPCE200ZX_711_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_712_ISR
extern void EE_PPCE200ZX_712_ISR(void);
#else
#define EE_PPCE200ZX_712_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_713_ISR
extern void EE_PPCE200ZX_713_ISR(void);
#else
#define EE_PPCE200ZX_713_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_714_ISR
extern void EE_PPCE200ZX_714_ISR(void);
#else
#define EE_PPCE200ZX_714_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_715_ISR
extern void EE_PPCE200ZX_715_ISR(void);
#else
#define EE_PPCE200ZX_715_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_716_ISR
extern void EE_PPCE200ZX_716_ISR(void);
#else
#define EE_PPCE200ZX_716_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_717_ISR
extern void EE_PPCE200ZX_717_ISR(void);
#else
#define EE_PPCE200ZX_717_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_718_ISR
extern void EE_PPCE200ZX_718_ISR(void);
#else
#define EE_PPCE200ZX_718_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_719_ISR
extern void EE_PPCE200ZX_719_ISR(void);
#else
#define EE_PPCE200ZX_719_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_720_ISR
extern void EE_PPCE200ZX_720_ISR(void);
#else
#define EE_PPCE200ZX_720_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_721_ISR
extern void EE_PPCE200ZX_721_ISR(void);
#else
#define EE_PPCE200ZX_721_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_722_ISR
extern void EE_PPCE200ZX_722_ISR(void);
#else
#define EE_PPCE200ZX_722_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_723_ISR
extern void EE_PPCE200ZX_723_ISR(void);
#else
#define EE_PPCE200ZX_723_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_724_ISR
extern void EE_PPCE200ZX_724_ISR(void);
#else
#define EE_PPCE200ZX_724_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_725_ISR
extern void EE_PPCE200ZX_725_ISR(void);
#else
#define EE_PPCE200ZX_725_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_726_ISR
extern void EE_PPCE200ZX_726_ISR(void);
#else
#define EE_PPCE200ZX_726_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_727_ISR
extern void EE_PPCE200ZX_727_ISR(void);
#else
#define EE_PPCE200ZX_727_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_728_ISR
extern void EE_PPCE200ZX_728_ISR(void);
#else
#define EE_PPCE200ZX_728_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_729_ISR
extern void EE_PPCE200ZX_729_ISR(void);
#else
#define EE_PPCE200ZX_729_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_730_ISR
extern void EE_PPCE200ZX_730_ISR(void);
#else
#define EE_PPCE200ZX_730_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_731_ISR
extern void EE_PPCE200ZX_731_ISR(void);
#else
#define EE_PPCE200ZX_731_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_732_ISR
extern void EE_PPCE200ZX_732_ISR(void);
#else
#define EE_PPCE200ZX_732_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_733_ISR
extern void EE_PPCE200ZX_733_ISR(void);
#else
#define EE_PPCE200ZX_733_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_734_ISR
extern void EE_PPCE200ZX_734_ISR(void);
#else
#define EE_PPCE200ZX_734_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_735_ISR
extern void EE_PPCE200ZX_735_ISR(void);
#else
#define EE_PPCE200ZX_735_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_736_ISR
extern void EE_PPCE200ZX_736_ISR(void);
#else
#define EE_PPCE200ZX_736_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_737_ISR
extern void EE_PPCE200ZX_737_ISR(void);
#else
#define EE_PPCE200ZX_737_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_738_ISR
extern void EE_PPCE200ZX_738_ISR(void);
#else
#define EE_PPCE200ZX_738_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_739_ISR
extern void EE_PPCE200ZX_739_ISR(void);
#else
#define EE_PPCE200ZX_739_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_740_ISR
extern void EE_PPCE200ZX_740_ISR(void);
#else
#define EE_PPCE200ZX_740_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_741_ISR
extern void EE_PPCE200ZX_741_ISR(void);
#else
#define EE_PPCE200ZX_741_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_742_ISR
extern void EE_PPCE200ZX_742_ISR(void);
#else
#define EE_PPCE200ZX_742_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_743_ISR
extern void EE_PPCE200ZX_743_ISR(void);
#else
#define EE_PPCE200ZX_743_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_744_ISR
extern void EE_PPCE200ZX_744_ISR(void);
#else
#define EE_PPCE200ZX_744_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_745_ISR
extern void EE_PPCE200ZX_745_ISR(void);
#else
#define EE_PPCE200ZX_745_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_746_ISR
extern void EE_PPCE200ZX_746_ISR(void);
#else
#define EE_PPCE200ZX_746_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_747_ISR
extern void EE_PPCE200ZX_747_ISR(void);
#else
#define EE_PPCE200ZX_747_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_748_ISR
extern void EE_PPCE200ZX_748_ISR(void);
#else
#define EE_PPCE200ZX_748_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_749_ISR
extern void EE_PPCE200ZX_749_ISR(void);
#else
#define EE_PPCE200ZX_749_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_750_ISR
extern void EE_PPCE200ZX_750_ISR(void);
#else
#define EE_PPCE200ZX_750_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_751_ISR
extern void EE_PPCE200ZX_751_ISR(void);
#else
#define EE_PPCE200ZX_751_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_752_ISR
extern void EE_PPCE200ZX_752_ISR(void);
#else
#define EE_PPCE200ZX_752_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_753_ISR
extern void EE_PPCE200ZX_753_ISR(void);
#else
#define EE_PPCE200ZX_753_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_754_ISR
extern void EE_PPCE200ZX_754_ISR(void);
#else
#define EE_PPCE200ZX_754_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_755_ISR
extern void EE_PPCE200ZX_755_ISR(void);
#else
#define EE_PPCE200ZX_755_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_756_ISR
extern void EE_PPCE200ZX_756_ISR(void);
#else
#define EE_PPCE200ZX_756_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_757_ISR
extern void EE_PPCE200ZX_757_ISR(void);
#else
#define EE_PPCE200ZX_757_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_758_ISR
extern void EE_PPCE200ZX_758_ISR(void);
#else
#define EE_PPCE200ZX_758_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_759_ISR
extern void EE_PPCE200ZX_759_ISR(void);
#else
#define EE_PPCE200ZX_759_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_760_ISR
extern void EE_PPCE200ZX_760_ISR(void);
#else
#define EE_PPCE200ZX_760_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_761_ISR
extern void EE_PPCE200ZX_761_ISR(void);
#else
#define EE_PPCE200ZX_761_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_762_ISR
extern void EE_PPCE200ZX_762_ISR(void);
#else
#define EE_PPCE200ZX_762_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_763_ISR
extern void EE_PPCE200ZX_763_ISR(void);
#else
#define EE_PPCE200ZX_763_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_764_ISR
extern void EE_PPCE200ZX_764_ISR(void);
#else
#define EE_PPCE200ZX_764_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_765_ISR
extern void EE_PPCE200ZX_765_ISR(void);
#else
#define EE_PPCE200ZX_765_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_766_ISR
extern void EE_PPCE200ZX_766_ISR(void);
#else
#define EE_PPCE200ZX_766_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_767_ISR
extern void EE_PPCE200ZX_767_ISR(void);
#else
#define EE_PPCE200ZX_767_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_768_ISR
extern void EE_PPCE200ZX_768_ISR(void);
#else
#define EE_PPCE200ZX_768_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_769_ISR
extern void EE_PPCE200ZX_769_ISR(void);
#else
#define EE_PPCE200ZX_769_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_770_ISR
extern void EE_PPCE200ZX_770_ISR(void);
#else
#define EE_PPCE200ZX_770_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_771_ISR
extern void EE_PPCE200ZX_771_ISR(void);
#else
#define EE_PPCE200ZX_771_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_772_ISR
extern void EE_PPCE200ZX_772_ISR(void);
#else
#define EE_PPCE200ZX_772_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_773_ISR
extern void EE_PPCE200ZX_773_ISR(void);
#else
#define EE_PPCE200ZX_773_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_774_ISR
extern void EE_PPCE200ZX_774_ISR(void);
#else
#define EE_PPCE200ZX_774_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_775_ISR
extern void EE_PPCE200ZX_775_ISR(void);
#else
#define EE_PPCE200ZX_775_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_776_ISR
extern void EE_PPCE200ZX_776_ISR(void);
#else
#define EE_PPCE200ZX_776_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_777_ISR
extern void EE_PPCE200ZX_777_ISR(void);
#else
#define EE_PPCE200ZX_777_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_778_ISR
extern void EE_PPCE200ZX_778_ISR(void);
#else
#define EE_PPCE200ZX_778_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_779_ISR
extern void EE_PPCE200ZX_779_ISR(void);
#else
#define EE_PPCE200ZX_779_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_780_ISR
extern void EE_PPCE200ZX_780_ISR(void);
#else
#define EE_PPCE200ZX_780_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_781_ISR
extern void EE_PPCE200ZX_781_ISR(void);
#else
#define EE_PPCE200ZX_781_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_782_ISR
extern void EE_PPCE200ZX_782_ISR(void);
#else
#define EE_PPCE200ZX_782_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_783_ISR
extern void EE_PPCE200ZX_783_ISR(void);
#else
#define EE_PPCE200ZX_783_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_784_ISR
extern void EE_PPCE200ZX_784_ISR(void);
#else
#define EE_PPCE200ZX_784_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_785_ISR
extern void EE_PPCE200ZX_785_ISR(void);
#else
#define EE_PPCE200ZX_785_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_786_ISR
extern void EE_PPCE200ZX_786_ISR(void);
#else
#define EE_PPCE200ZX_786_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_787_ISR
extern void EE_PPCE200ZX_787_ISR(void);
#else
#define EE_PPCE200ZX_787_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_788_ISR
extern void EE_PPCE200ZX_788_ISR(void);
#else
#define EE_PPCE200ZX_788_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_789_ISR
extern void EE_PPCE200ZX_789_ISR(void);
#else
#define EE_PPCE200ZX_789_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_790_ISR
extern void EE_PPCE200ZX_790_ISR(void);
#else
#define EE_PPCE200ZX_790_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_791_ISR
extern void EE_PPCE200ZX_791_ISR(void);
#else
#define EE_PPCE200ZX_791_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_792_ISR
extern void EE_PPCE200ZX_792_ISR(void);
#else
#define EE_PPCE200ZX_792_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_793_ISR
extern void EE_PPCE200ZX_793_ISR(void);
#else
#define EE_PPCE200ZX_793_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_794_ISR
extern void EE_PPCE200ZX_794_ISR(void);
#else
#define EE_PPCE200ZX_794_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_795_ISR
extern void EE_PPCE200ZX_795_ISR(void);
#else
#define EE_PPCE200ZX_795_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_796_ISR
extern void EE_PPCE200ZX_796_ISR(void);
#else
#define EE_PPCE200ZX_796_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_797_ISR
extern void EE_PPCE200ZX_797_ISR(void);
#else
#define EE_PPCE200ZX_797_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_798_ISR
extern void EE_PPCE200ZX_798_ISR(void);
#else
#define EE_PPCE200ZX_798_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_799_ISR
extern void EE_PPCE200ZX_799_ISR(void);
#else
#define EE_PPCE200ZX_799_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_800_ISR
extern void EE_PPCE200ZX_800_ISR(void);
#else
#define EE_PPCE200ZX_800_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_801_ISR
extern void EE_PPCE200ZX_801_ISR(void);
#else
#define EE_PPCE200ZX_801_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_802_ISR
extern void EE_PPCE200ZX_802_ISR(void);
#else
#define EE_PPCE200ZX_802_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_803_ISR
extern void EE_PPCE200ZX_803_ISR(void);
#else
#define EE_PPCE200ZX_803_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_804_ISR
extern void EE_PPCE200ZX_804_ISR(void);
#else
#define EE_PPCE200ZX_804_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_805_ISR
extern void EE_PPCE200ZX_805_ISR(void);
#else
#define EE_PPCE200ZX_805_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_806_ISR
extern void EE_PPCE200ZX_806_ISR(void);
#else
#define EE_PPCE200ZX_806_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_807_ISR
extern void EE_PPCE200ZX_807_ISR(void);
#else
#define EE_PPCE200ZX_807_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_808_ISR
extern void EE_PPCE200ZX_808_ISR(void);
#else
#define EE_PPCE200ZX_808_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_809_ISR
extern void EE_PPCE200ZX_809_ISR(void);
#else
#define EE_PPCE200ZX_809_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_810_ISR
extern void EE_PPCE200ZX_810_ISR(void);
#else
#define EE_PPCE200ZX_810_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_811_ISR
extern void EE_PPCE200ZX_811_ISR(void);
#else
#define EE_PPCE200ZX_811_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_812_ISR
extern void EE_PPCE200ZX_812_ISR(void);
#else
#define EE_PPCE200ZX_812_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_813_ISR
extern void EE_PPCE200ZX_813_ISR(void);
#else
#define EE_PPCE200ZX_813_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_814_ISR
extern void EE_PPCE200ZX_814_ISR(void);
#else
#define EE_PPCE200ZX_814_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_815_ISR
extern void EE_PPCE200ZX_815_ISR(void);
#else
#define EE_PPCE200ZX_815_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_816_ISR
extern void EE_PPCE200ZX_816_ISR(void);
#else
#define EE_PPCE200ZX_816_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_817_ISR
extern void EE_PPCE200ZX_817_ISR(void);
#else
#define EE_PPCE200ZX_817_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_818_ISR
extern void EE_PPCE200ZX_818_ISR(void);
#else
#define EE_PPCE200ZX_818_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_819_ISR
extern void EE_PPCE200ZX_819_ISR(void);
#else
#define EE_PPCE200ZX_819_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_820_ISR
extern void EE_PPCE200ZX_820_ISR(void);
#else
#define EE_PPCE200ZX_820_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_821_ISR
extern void EE_PPCE200ZX_821_ISR(void);
#else
#define EE_PPCE200ZX_821_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_822_ISR
extern void EE_PPCE200ZX_822_ISR(void);
#else
#define EE_PPCE200ZX_822_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_823_ISR
extern void EE_PPCE200ZX_823_ISR(void);
#else
#define EE_PPCE200ZX_823_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_824_ISR
extern void EE_PPCE200ZX_824_ISR(void);
#else
#define EE_PPCE200ZX_824_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_825_ISR
extern void EE_PPCE200ZX_825_ISR(void);
#else
#define EE_PPCE200ZX_825_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_826_ISR
extern void EE_PPCE200ZX_826_ISR(void);
#else
#define EE_PPCE200ZX_826_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_827_ISR
extern void EE_PPCE200ZX_827_ISR(void);
#else
#define EE_PPCE200ZX_827_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_828_ISR
extern void EE_PPCE200ZX_828_ISR(void);
#else
#define EE_PPCE200ZX_828_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_829_ISR
extern void EE_PPCE200ZX_829_ISR(void);
#else
#define EE_PPCE200ZX_829_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_830_ISR
extern void EE_PPCE200ZX_830_ISR(void);
#else
#define EE_PPCE200ZX_830_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_831_ISR
extern void EE_PPCE200ZX_831_ISR(void);
#else
#define EE_PPCE200ZX_831_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_832_ISR
extern void EE_PPCE200ZX_832_ISR(void);
#else
#define EE_PPCE200ZX_832_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_833_ISR
extern void EE_PPCE200ZX_833_ISR(void);
#else
#define EE_PPCE200ZX_833_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_834_ISR
extern void EE_PPCE200ZX_834_ISR(void);
#else
#define EE_PPCE200ZX_834_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_835_ISR
extern void EE_PPCE200ZX_835_ISR(void);
#else
#define EE_PPCE200ZX_835_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_836_ISR
extern void EE_PPCE200ZX_836_ISR(void);
#else
#define EE_PPCE200ZX_836_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_837_ISR
extern void EE_PPCE200ZX_837_ISR(void);
#else
#define EE_PPCE200ZX_837_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_838_ISR
extern void EE_PPCE200ZX_838_ISR(void);
#else
#define EE_PPCE200ZX_838_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_839_ISR
extern void EE_PPCE200ZX_839_ISR(void);
#else
#define EE_PPCE200ZX_839_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_840_ISR
extern void EE_PPCE200ZX_840_ISR(void);
#else
#define EE_PPCE200ZX_840_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_841_ISR
extern void EE_PPCE200ZX_841_ISR(void);
#else
#define EE_PPCE200ZX_841_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_842_ISR
extern void EE_PPCE200ZX_842_ISR(void);
#else
#define EE_PPCE200ZX_842_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_843_ISR
extern void EE_PPCE200ZX_843_ISR(void);
#else
#define EE_PPCE200ZX_843_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_844_ISR
extern void EE_PPCE200ZX_844_ISR(void);
#else
#define EE_PPCE200ZX_844_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_845_ISR
extern void EE_PPCE200ZX_845_ISR(void);
#else
#define EE_PPCE200ZX_845_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_846_ISR
extern void EE_PPCE200ZX_846_ISR(void);
#else
#define EE_PPCE200ZX_846_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_847_ISR
extern void EE_PPCE200ZX_847_ISR(void);
#else
#define EE_PPCE200ZX_847_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_848_ISR
extern void EE_PPCE200ZX_848_ISR(void);
#else
#define EE_PPCE200ZX_848_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_849_ISR
extern void EE_PPCE200ZX_849_ISR(void);
#else
#define EE_PPCE200ZX_849_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_850_ISR
extern void EE_PPCE200ZX_850_ISR(void);
#else
#define EE_PPCE200ZX_850_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_851_ISR
extern void EE_PPCE200ZX_851_ISR(void);
#else
#define EE_PPCE200ZX_851_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_852_ISR
extern void EE_PPCE200ZX_852_ISR(void);
#else
#define EE_PPCE200ZX_852_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_853_ISR
extern void EE_PPCE200ZX_853_ISR(void);
#else
#define EE_PPCE200ZX_853_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_854_ISR
extern void EE_PPCE200ZX_854_ISR(void);
#else
#define EE_PPCE200ZX_854_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_855_ISR
extern void EE_PPCE200ZX_855_ISR(void);
#else
#define EE_PPCE200ZX_855_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_856_ISR
extern void EE_PPCE200ZX_856_ISR(void);
#else
#define EE_PPCE200ZX_856_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_857_ISR
extern void EE_PPCE200ZX_857_ISR(void);
#else
#define EE_PPCE200ZX_857_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_858_ISR
extern void EE_PPCE200ZX_858_ISR(void);
#else
#define EE_PPCE200ZX_858_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_859_ISR
extern void EE_PPCE200ZX_859_ISR(void);
#else
#define EE_PPCE200ZX_859_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_860_ISR
extern void EE_PPCE200ZX_860_ISR(void);
#else
#define EE_PPCE200ZX_860_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_861_ISR
extern void EE_PPCE200ZX_861_ISR(void);
#else
#define EE_PPCE200ZX_861_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_862_ISR
extern void EE_PPCE200ZX_862_ISR(void);
#else
#define EE_PPCE200ZX_862_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_863_ISR
extern void EE_PPCE200ZX_863_ISR(void);
#else
#define EE_PPCE200ZX_863_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_864_ISR
extern void EE_PPCE200ZX_864_ISR(void);
#else
#define EE_PPCE200ZX_864_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_865_ISR
extern void EE_PPCE200ZX_865_ISR(void);
#else
#define EE_PPCE200ZX_865_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_866_ISR
extern void EE_PPCE200ZX_866_ISR(void);
#else
#define EE_PPCE200ZX_866_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_867_ISR
extern void EE_PPCE200ZX_867_ISR(void);
#else
#define EE_PPCE200ZX_867_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_868_ISR
extern void EE_PPCE200ZX_868_ISR(void);
#else
#define EE_PPCE200ZX_868_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_869_ISR
extern void EE_PPCE200ZX_869_ISR(void);
#else
#define EE_PPCE200ZX_869_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_870_ISR
extern void EE_PPCE200ZX_870_ISR(void);
#else
#define EE_PPCE200ZX_870_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_871_ISR
extern void EE_PPCE200ZX_871_ISR(void);
#else
#define EE_PPCE200ZX_871_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_872_ISR
extern void EE_PPCE200ZX_872_ISR(void);
#else
#define EE_PPCE200ZX_872_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_873_ISR
extern void EE_PPCE200ZX_873_ISR(void);
#else
#define EE_PPCE200ZX_873_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_874_ISR
extern void EE_PPCE200ZX_874_ISR(void);
#else
#define EE_PPCE200ZX_874_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_875_ISR
extern void EE_PPCE200ZX_875_ISR(void);
#else
#define EE_PPCE200ZX_875_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_876_ISR
extern void EE_PPCE200ZX_876_ISR(void);
#else
#define EE_PPCE200ZX_876_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_877_ISR
extern void EE_PPCE200ZX_877_ISR(void);
#else
#define EE_PPCE200ZX_877_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_878_ISR
extern void EE_PPCE200ZX_878_ISR(void);
#else
#define EE_PPCE200ZX_878_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_879_ISR
extern void EE_PPCE200ZX_879_ISR(void);
#else
#define EE_PPCE200ZX_879_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_880_ISR
extern void EE_PPCE200ZX_880_ISR(void);
#else
#define EE_PPCE200ZX_880_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_881_ISR
extern void EE_PPCE200ZX_881_ISR(void);
#else
#define EE_PPCE200ZX_881_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_882_ISR
extern void EE_PPCE200ZX_882_ISR(void);
#else
#define EE_PPCE200ZX_882_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_883_ISR
extern void EE_PPCE200ZX_883_ISR(void);
#else
#define EE_PPCE200ZX_883_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_884_ISR
extern void EE_PPCE200ZX_884_ISR(void);
#else
#define EE_PPCE200ZX_884_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_885_ISR
extern void EE_PPCE200ZX_885_ISR(void);
#else
#define EE_PPCE200ZX_885_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_886_ISR
extern void EE_PPCE200ZX_886_ISR(void);
#else
#define EE_PPCE200ZX_886_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_887_ISR
extern void EE_PPCE200ZX_887_ISR(void);
#else
#define EE_PPCE200ZX_887_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_888_ISR
extern void EE_PPCE200ZX_888_ISR(void);
#else
#define EE_PPCE200ZX_888_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_889_ISR
extern void EE_PPCE200ZX_889_ISR(void);
#else
#define EE_PPCE200ZX_889_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_890_ISR
extern void EE_PPCE200ZX_890_ISR(void);
#else
#define EE_PPCE200ZX_890_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_891_ISR
extern void EE_PPCE200ZX_891_ISR(void);
#else
#define EE_PPCE200ZX_891_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_892_ISR
extern void EE_PPCE200ZX_892_ISR(void);
#else
#define EE_PPCE200ZX_892_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_893_ISR
extern void EE_PPCE200ZX_893_ISR(void);
#else
#define EE_PPCE200ZX_893_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_894_ISR
extern void EE_PPCE200ZX_894_ISR(void);
#else
#define EE_PPCE200ZX_894_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_895_ISR
extern void EE_PPCE200ZX_895_ISR(void);
#else
#define EE_PPCE200ZX_895_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_896_ISR
extern void EE_PPCE200ZX_896_ISR(void);
#else
#define EE_PPCE200ZX_896_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_897_ISR
extern void EE_PPCE200ZX_897_ISR(void);
#else
#define EE_PPCE200ZX_897_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_898_ISR
extern void EE_PPCE200ZX_898_ISR(void);
#else
#define EE_PPCE200ZX_898_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_899_ISR
extern void EE_PPCE200ZX_899_ISR(void);
#else
#define EE_PPCE200ZX_899_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_900_ISR
extern void EE_PPCE200ZX_900_ISR(void);
#else
#define EE_PPCE200ZX_900_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_901_ISR
extern void EE_PPCE200ZX_901_ISR(void);
#else
#define EE_PPCE200ZX_901_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_902_ISR
extern void EE_PPCE200ZX_902_ISR(void);
#else
#define EE_PPCE200ZX_902_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_903_ISR
extern void EE_PPCE200ZX_903_ISR(void);
#else
#define EE_PPCE200ZX_903_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_904_ISR
extern void EE_PPCE200ZX_904_ISR(void);
#else
#define EE_PPCE200ZX_904_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_905_ISR
extern void EE_PPCE200ZX_905_ISR(void);
#else
#define EE_PPCE200ZX_905_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_906_ISR
extern void EE_PPCE200ZX_906_ISR(void);
#else
#define EE_PPCE200ZX_906_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_907_ISR
extern void EE_PPCE200ZX_907_ISR(void);
#else
#define EE_PPCE200ZX_907_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_908_ISR
extern void EE_PPCE200ZX_908_ISR(void);
#else
#define EE_PPCE200ZX_908_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_909_ISR
extern void EE_PPCE200ZX_909_ISR(void);
#else
#define EE_PPCE200ZX_909_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_910_ISR
extern void EE_PPCE200ZX_910_ISR(void);
#else
#define EE_PPCE200ZX_910_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_911_ISR
extern void EE_PPCE200ZX_911_ISR(void);
#else
#define EE_PPCE200ZX_911_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_912_ISR
extern void EE_PPCE200ZX_912_ISR(void);
#else
#define EE_PPCE200ZX_912_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_913_ISR
extern void EE_PPCE200ZX_913_ISR(void);
#else
#define EE_PPCE200ZX_913_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_914_ISR
extern void EE_PPCE200ZX_914_ISR(void);
#else
#define EE_PPCE200ZX_914_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_915_ISR
extern void EE_PPCE200ZX_915_ISR(void);
#else
#define EE_PPCE200ZX_915_ISR DEFAULT_IRQ_ENTRY
#endif

#ifdef EE_PPCE200ZX_916_ISR
extern void EE_PPCE200ZX_916_ISR(void);
#else
#define EE_PPCE200ZX_916_ISR DEFAULT_IRQ_ENTRY
#endif

/*
  Number of internal CPU exceptions (in cpu/e200zx/inc/ee_cpu_asm.h)
  EE_E200ZX_MAX_CPU_EXCP 16 
  Max External IRQ (in mcu/st_spc574k/ee_spc574k.h)
  EE_E200ZX_MAX_EXT_IRQ 916

  It has been made const so it can be put in flash
 */
const EE_e200z7_ISR_handler EE_e200z7_ISR_table[EE_E200ZX_MAX_CPU_EXCP +
  EE_E200ZX_MAX_EXT_IRQ] = 
{
  /* SOFTWARE HANDLER FOR INTERNAL CPU EXCEPTION TO ENABLE THOSE THAT POINT TO
     __empty_handler WE HAVE TO CHANGE e200zx/src/ee_ivor.S */
  /* Zen EE_e200zx_critical_input set to  __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR0 */
  /* Zen EE_e200zx_machine_check set to  __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR1 */
  /* Zen EE_e200zx_data_storage set to  __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR2 */
  /* Zen EE_EE_e200zx_instruction_storage set to  __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR3 */
  /* Zen vector EE_e200zx_external_input set to  */
  (EE_e200z7_ISR_handler)0, /* IVOR4 */
  /* Zen EE_e200zx_alignment set to  __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR5 */
  /* Zen EE_e200zx_program set to  __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR6 */
  /* Zen EE_e200zx_float_unavailable set to  __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR7 */
  /* Zen EE_e200zx_system_call set to  used for memory protection */
  (EE_e200z7_ISR_handler)0, /* IVOR8 */
  /* Zen EE_e200zx_auxiliary_unavailable set to __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR9 */
  /* Zen EE_e200zx_decrementer set to EE_e200zx_decrementer_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR10 */
  /* Zen EE_e200zx_interval_timer set to EE_e200zx_fixed_intv_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR11 */
  /* Zen EE_e200zx_watchdog_timer set to  __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR12 */
  /* Zen EE_e200zx_data_tlb_error set to  __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR13 */
  /* Zen EE_e200zx_instruction_tlb_error set to  __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR14 */
  /* Zen EE_e200zx_debug_critical set to  __empty_handler by IVOR */
  (EE_e200z7_ISR_handler)0, /* IVOR15 */

  /*  FROM HEREUNDER ARE ALL EXTERNAL INTERRUPT SOURCES,
      Position equal EE_E200ZX_MAX_CPU_EXCP + Vector Number */
  EE_PPCE200ZX_0_ISR,
  EE_PPCE200ZX_1_ISR,
  EE_PPCE200ZX_2_ISR,
  EE_PPCE200ZX_3_ISR,
  EE_PPCE200ZX_4_ISR,
  EE_PPCE200ZX_5_ISR,
  EE_PPCE200ZX_6_ISR,
  EE_PPCE200ZX_7_ISR,
  EE_PPCE200ZX_8_ISR,
  EE_PPCE200ZX_9_ISR,
  EE_PPCE200ZX_10_ISR,
  EE_PPCE200ZX_11_ISR,
  EE_PPCE200ZX_12_ISR,
  EE_PPCE200ZX_13_ISR,
  EE_PPCE200ZX_14_ISR,
  EE_PPCE200ZX_15_ISR,
  EE_PPCE200ZX_16_ISR,
  EE_PPCE200ZX_17_ISR,
  EE_PPCE200ZX_18_ISR,
  EE_PPCE200ZX_19_ISR,
  EE_PPCE200ZX_20_ISR,
  EE_PPCE200ZX_21_ISR,
  EE_PPCE200ZX_22_ISR,
  EE_PPCE200ZX_23_ISR,
  EE_PPCE200ZX_24_ISR,
  EE_PPCE200ZX_25_ISR,
  EE_PPCE200ZX_26_ISR,
  EE_PPCE200ZX_27_ISR,
  EE_PPCE200ZX_28_ISR,
  EE_PPCE200ZX_29_ISR,
  EE_PPCE200ZX_30_ISR,
  EE_PPCE200ZX_31_ISR,
  EE_PPCE200ZX_32_ISR,
  EE_PPCE200ZX_33_ISR,
  EE_PPCE200ZX_34_ISR,
  EE_PPCE200ZX_35_ISR,
  EE_PPCE200ZX_36_ISR,
  EE_PPCE200ZX_37_ISR,
  EE_PPCE200ZX_38_ISR,
  EE_PPCE200ZX_39_ISR,
  EE_PPCE200ZX_40_ISR,
  EE_PPCE200ZX_41_ISR,
  EE_PPCE200ZX_42_ISR,
  EE_PPCE200ZX_43_ISR,
  EE_PPCE200ZX_44_ISR,
  EE_PPCE200ZX_45_ISR,
  EE_PPCE200ZX_46_ISR,
  EE_PPCE200ZX_47_ISR,
  EE_PPCE200ZX_48_ISR,
  EE_PPCE200ZX_49_ISR,
  EE_PPCE200ZX_50_ISR,
  EE_PPCE200ZX_51_ISR,
  EE_PPCE200ZX_52_ISR,
  EE_PPCE200ZX_53_ISR,
  EE_PPCE200ZX_54_ISR,
  EE_PPCE200ZX_55_ISR,
  EE_PPCE200ZX_56_ISR,
  EE_PPCE200ZX_57_ISR,
  EE_PPCE200ZX_58_ISR,
  EE_PPCE200ZX_59_ISR,
  EE_PPCE200ZX_60_ISR,
  EE_PPCE200ZX_61_ISR,
  EE_PPCE200ZX_62_ISR,
  EE_PPCE200ZX_63_ISR,
  EE_PPCE200ZX_64_ISR,
  EE_PPCE200ZX_65_ISR,
  EE_PPCE200ZX_66_ISR,
  EE_PPCE200ZX_67_ISR,
  EE_PPCE200ZX_68_ISR,
  EE_PPCE200ZX_69_ISR,
  EE_PPCE200ZX_70_ISR,
  EE_PPCE200ZX_71_ISR,
  EE_PPCE200ZX_72_ISR,
  EE_PPCE200ZX_73_ISR,
  EE_PPCE200ZX_74_ISR,
  EE_PPCE200ZX_75_ISR,
  EE_PPCE200ZX_76_ISR,
  EE_PPCE200ZX_77_ISR,
  EE_PPCE200ZX_78_ISR,
  EE_PPCE200ZX_79_ISR,
  EE_PPCE200ZX_80_ISR,
  EE_PPCE200ZX_81_ISR,
  EE_PPCE200ZX_82_ISR,
  EE_PPCE200ZX_83_ISR,
  EE_PPCE200ZX_84_ISR,
  EE_PPCE200ZX_85_ISR,
  EE_PPCE200ZX_86_ISR,
  EE_PPCE200ZX_87_ISR,
  EE_PPCE200ZX_88_ISR,
  EE_PPCE200ZX_89_ISR,
  EE_PPCE200ZX_90_ISR,
  EE_PPCE200ZX_91_ISR,
  EE_PPCE200ZX_92_ISR,
  EE_PPCE200ZX_93_ISR,
  EE_PPCE200ZX_94_ISR,
  EE_PPCE200ZX_95_ISR,
  EE_PPCE200ZX_96_ISR,
  EE_PPCE200ZX_97_ISR,
  EE_PPCE200ZX_98_ISR,
  EE_PPCE200ZX_99_ISR,
  EE_PPCE200ZX_100_ISR,
  EE_PPCE200ZX_101_ISR,
  EE_PPCE200ZX_102_ISR,
  EE_PPCE200ZX_103_ISR,
  EE_PPCE200ZX_104_ISR,
  EE_PPCE200ZX_105_ISR,
  EE_PPCE200ZX_106_ISR,
  EE_PPCE200ZX_107_ISR,
  EE_PPCE200ZX_108_ISR,
  EE_PPCE200ZX_109_ISR,
  EE_PPCE200ZX_110_ISR,
  EE_PPCE200ZX_111_ISR,
  EE_PPCE200ZX_112_ISR,
  EE_PPCE200ZX_113_ISR,
  EE_PPCE200ZX_114_ISR,
  EE_PPCE200ZX_115_ISR,
  EE_PPCE200ZX_116_ISR,
  EE_PPCE200ZX_117_ISR,
  EE_PPCE200ZX_118_ISR,
  EE_PPCE200ZX_119_ISR,
  EE_PPCE200ZX_120_ISR,
  EE_PPCE200ZX_121_ISR,
  EE_PPCE200ZX_122_ISR,
  EE_PPCE200ZX_123_ISR,
  EE_PPCE200ZX_124_ISR,
  EE_PPCE200ZX_125_ISR,
  EE_PPCE200ZX_126_ISR,
  EE_PPCE200ZX_127_ISR,
  EE_PPCE200ZX_128_ISR,
  EE_PPCE200ZX_129_ISR,
  EE_PPCE200ZX_130_ISR,
  EE_PPCE200ZX_131_ISR,
  EE_PPCE200ZX_132_ISR,
  EE_PPCE200ZX_133_ISR,
  EE_PPCE200ZX_134_ISR,
  EE_PPCE200ZX_135_ISR,
  EE_PPCE200ZX_136_ISR,
  EE_PPCE200ZX_137_ISR,
  EE_PPCE200ZX_138_ISR,
  EE_PPCE200ZX_139_ISR,
  EE_PPCE200ZX_140_ISR,
  EE_PPCE200ZX_141_ISR,
  EE_PPCE200ZX_142_ISR,
  EE_PPCE200ZX_143_ISR,
  EE_PPCE200ZX_144_ISR,
  EE_PPCE200ZX_145_ISR,
  EE_PPCE200ZX_146_ISR,
  EE_PPCE200ZX_147_ISR,
  EE_PPCE200ZX_148_ISR,
  EE_PPCE200ZX_149_ISR,
  EE_PPCE200ZX_150_ISR,
  EE_PPCE200ZX_151_ISR,
  EE_PPCE200ZX_152_ISR,
  EE_PPCE200ZX_153_ISR,
  EE_PPCE200ZX_154_ISR,
  EE_PPCE200ZX_155_ISR,
  EE_PPCE200ZX_156_ISR,
  EE_PPCE200ZX_157_ISR,
  EE_PPCE200ZX_158_ISR,
  EE_PPCE200ZX_159_ISR,
  EE_PPCE200ZX_160_ISR,
  EE_PPCE200ZX_161_ISR,
  EE_PPCE200ZX_162_ISR,
  EE_PPCE200ZX_163_ISR,
  EE_PPCE200ZX_164_ISR,
  EE_PPCE200ZX_165_ISR,
  EE_PPCE200ZX_166_ISR,
  EE_PPCE200ZX_167_ISR,
  EE_PPCE200ZX_168_ISR,
  EE_PPCE200ZX_169_ISR,
  EE_PPCE200ZX_170_ISR,
  EE_PPCE200ZX_171_ISR,
  EE_PPCE200ZX_172_ISR,
  EE_PPCE200ZX_173_ISR,
  EE_PPCE200ZX_174_ISR,
  EE_PPCE200ZX_175_ISR,
  EE_PPCE200ZX_176_ISR,
  EE_PPCE200ZX_177_ISR,
  EE_PPCE200ZX_178_ISR,
  EE_PPCE200ZX_179_ISR,
  EE_PPCE200ZX_180_ISR,
  EE_PPCE200ZX_181_ISR,
  EE_PPCE200ZX_182_ISR,
  EE_PPCE200ZX_183_ISR,
  EE_PPCE200ZX_184_ISR,
  EE_PPCE200ZX_185_ISR,
  EE_PPCE200ZX_186_ISR,
  EE_PPCE200ZX_187_ISR,
  EE_PPCE200ZX_188_ISR,
  EE_PPCE200ZX_189_ISR,
  EE_PPCE200ZX_190_ISR,
  EE_PPCE200ZX_191_ISR,
  EE_PPCE200ZX_192_ISR,
  EE_PPCE200ZX_193_ISR,
  EE_PPCE200ZX_194_ISR,
  EE_PPCE200ZX_195_ISR,
  EE_PPCE200ZX_196_ISR,
  EE_PPCE200ZX_197_ISR,
  EE_PPCE200ZX_198_ISR,
  EE_PPCE200ZX_199_ISR,
  EE_PPCE200ZX_200_ISR,
  EE_PPCE200ZX_201_ISR,
  EE_PPCE200ZX_202_ISR,
  EE_PPCE200ZX_203_ISR,
  EE_PPCE200ZX_204_ISR,
  EE_PPCE200ZX_205_ISR,
  EE_PPCE200ZX_206_ISR,
  EE_PPCE200ZX_207_ISR,
  EE_PPCE200ZX_208_ISR,
  EE_PPCE200ZX_209_ISR,
  EE_PPCE200ZX_210_ISR,
  EE_PPCE200ZX_211_ISR,
  EE_PPCE200ZX_212_ISR,
  EE_PPCE200ZX_213_ISR,
  EE_PPCE200ZX_214_ISR,
  EE_PPCE200ZX_215_ISR,
  EE_PPCE200ZX_216_ISR,
  EE_PPCE200ZX_217_ISR,
  EE_PPCE200ZX_218_ISR,
  EE_PPCE200ZX_219_ISR,
  EE_PPCE200ZX_220_ISR,
  EE_PPCE200ZX_221_ISR,
  EE_PPCE200ZX_222_ISR,
  EE_PPCE200ZX_223_ISR,
  EE_PPCE200ZX_224_ISR,
  EE_PPCE200ZX_225_ISR,
  EE_PPCE200ZX_226_ISR,
  EE_PPCE200ZX_227_ISR,
  EE_PPCE200ZX_228_ISR,
  EE_PPCE200ZX_229_ISR,
  EE_PPCE200ZX_230_ISR,
  EE_PPCE200ZX_231_ISR,
  EE_PPCE200ZX_232_ISR,
  EE_PPCE200ZX_233_ISR,
  EE_PPCE200ZX_234_ISR,
  EE_PPCE200ZX_235_ISR,
  EE_PPCE200ZX_236_ISR,
  EE_PPCE200ZX_237_ISR,
  EE_PPCE200ZX_238_ISR,
  EE_PPCE200ZX_239_ISR,
  EE_PPCE200ZX_240_ISR,
  EE_PPCE200ZX_241_ISR,
  EE_PPCE200ZX_242_ISR,
  EE_PPCE200ZX_243_ISR,
  EE_PPCE200ZX_244_ISR,
  EE_PPCE200ZX_245_ISR,
  EE_PPCE200ZX_246_ISR,
  EE_PPCE200ZX_247_ISR,
  EE_PPCE200ZX_248_ISR,
  EE_PPCE200ZX_249_ISR,
  EE_PPCE200ZX_250_ISR,
  EE_PPCE200ZX_251_ISR,
  EE_PPCE200ZX_252_ISR,
  EE_PPCE200ZX_253_ISR,
  EE_PPCE200ZX_254_ISR,
  EE_PPCE200ZX_255_ISR,
  EE_PPCE200ZX_256_ISR,
  EE_PPCE200ZX_257_ISR,
  EE_PPCE200ZX_258_ISR,
  EE_PPCE200ZX_259_ISR,
  EE_PPCE200ZX_260_ISR,
  EE_PPCE200ZX_261_ISR,
  EE_PPCE200ZX_262_ISR,
  EE_PPCE200ZX_263_ISR,
  EE_PPCE200ZX_264_ISR,
  EE_PPCE200ZX_265_ISR,
  EE_PPCE200ZX_266_ISR,
  EE_PPCE200ZX_267_ISR,
  EE_PPCE200ZX_268_ISR,
  EE_PPCE200ZX_269_ISR,
  EE_PPCE200ZX_270_ISR,
  EE_PPCE200ZX_271_ISR,
  EE_PPCE200ZX_272_ISR,
  EE_PPCE200ZX_273_ISR,
  EE_PPCE200ZX_274_ISR,
  EE_PPCE200ZX_275_ISR,
  EE_PPCE200ZX_276_ISR,
  EE_PPCE200ZX_277_ISR,
  EE_PPCE200ZX_278_ISR,
  EE_PPCE200ZX_279_ISR,
  EE_PPCE200ZX_280_ISR,
  EE_PPCE200ZX_281_ISR,
  EE_PPCE200ZX_282_ISR,
  EE_PPCE200ZX_283_ISR,
  EE_PPCE200ZX_284_ISR,
  EE_PPCE200ZX_285_ISR,
  EE_PPCE200ZX_286_ISR,
  EE_PPCE200ZX_287_ISR,
  EE_PPCE200ZX_288_ISR,
  EE_PPCE200ZX_289_ISR,
  EE_PPCE200ZX_290_ISR,
  EE_PPCE200ZX_291_ISR,
  EE_PPCE200ZX_292_ISR,
  EE_PPCE200ZX_293_ISR,
  EE_PPCE200ZX_294_ISR,
  EE_PPCE200ZX_295_ISR,
  EE_PPCE200ZX_296_ISR,
  EE_PPCE200ZX_297_ISR,
  EE_PPCE200ZX_298_ISR,
  EE_PPCE200ZX_299_ISR,
  EE_PPCE200ZX_300_ISR,
  EE_PPCE200ZX_301_ISR,
  EE_PPCE200ZX_302_ISR,
  EE_PPCE200ZX_303_ISR,
  EE_PPCE200ZX_304_ISR,
  EE_PPCE200ZX_305_ISR,
  EE_PPCE200ZX_306_ISR,
  EE_PPCE200ZX_307_ISR,
  EE_PPCE200ZX_308_ISR,
  EE_PPCE200ZX_309_ISR,
  EE_PPCE200ZX_310_ISR,
  EE_PPCE200ZX_311_ISR,
  EE_PPCE200ZX_312_ISR,
  EE_PPCE200ZX_313_ISR,
  EE_PPCE200ZX_314_ISR,
  EE_PPCE200ZX_315_ISR,
  EE_PPCE200ZX_316_ISR,
  EE_PPCE200ZX_317_ISR,
  EE_PPCE200ZX_318_ISR,
  EE_PPCE200ZX_319_ISR,
  EE_PPCE200ZX_320_ISR,
  EE_PPCE200ZX_321_ISR,
  EE_PPCE200ZX_322_ISR,
  EE_PPCE200ZX_323_ISR,
  EE_PPCE200ZX_324_ISR,
  EE_PPCE200ZX_325_ISR,
  EE_PPCE200ZX_326_ISR,
  EE_PPCE200ZX_327_ISR,
  EE_PPCE200ZX_328_ISR,
  EE_PPCE200ZX_329_ISR,
  EE_PPCE200ZX_330_ISR,
  EE_PPCE200ZX_331_ISR,
  EE_PPCE200ZX_332_ISR,
  EE_PPCE200ZX_333_ISR,
  EE_PPCE200ZX_334_ISR,
  EE_PPCE200ZX_335_ISR,
  EE_PPCE200ZX_336_ISR,
  EE_PPCE200ZX_337_ISR,
  EE_PPCE200ZX_338_ISR,
  EE_PPCE200ZX_339_ISR,
  EE_PPCE200ZX_340_ISR,
  EE_PPCE200ZX_341_ISR,
  EE_PPCE200ZX_342_ISR,
  EE_PPCE200ZX_343_ISR,
  EE_PPCE200ZX_344_ISR,
  EE_PPCE200ZX_345_ISR,
  EE_PPCE200ZX_346_ISR,
  EE_PPCE200ZX_347_ISR,
  EE_PPCE200ZX_348_ISR,
  EE_PPCE200ZX_349_ISR,
  EE_PPCE200ZX_350_ISR,
  EE_PPCE200ZX_351_ISR,
  EE_PPCE200ZX_352_ISR,
  EE_PPCE200ZX_353_ISR,
  EE_PPCE200ZX_354_ISR,
  EE_PPCE200ZX_355_ISR,
  EE_PPCE200ZX_356_ISR,
  EE_PPCE200ZX_357_ISR,
  EE_PPCE200ZX_358_ISR,
  EE_PPCE200ZX_359_ISR,
  EE_PPCE200ZX_360_ISR,
  EE_PPCE200ZX_361_ISR,
  EE_PPCE200ZX_362_ISR,
  EE_PPCE200ZX_363_ISR,
  EE_PPCE200ZX_364_ISR,
  EE_PPCE200ZX_365_ISR,
  EE_PPCE200ZX_366_ISR,
  EE_PPCE200ZX_367_ISR,
  EE_PPCE200ZX_368_ISR,
  EE_PPCE200ZX_369_ISR,
  EE_PPCE200ZX_370_ISR,
  EE_PPCE200ZX_371_ISR,
  EE_PPCE200ZX_372_ISR,
  EE_PPCE200ZX_373_ISR,
  EE_PPCE200ZX_374_ISR,
  EE_PPCE200ZX_375_ISR,
  EE_PPCE200ZX_376_ISR,
  EE_PPCE200ZX_377_ISR,
  EE_PPCE200ZX_378_ISR,
  EE_PPCE200ZX_379_ISR,
  EE_PPCE200ZX_380_ISR,
  EE_PPCE200ZX_381_ISR,
  EE_PPCE200ZX_382_ISR,
  EE_PPCE200ZX_383_ISR,
  EE_PPCE200ZX_384_ISR,
  EE_PPCE200ZX_385_ISR,
  EE_PPCE200ZX_386_ISR,
  EE_PPCE200ZX_387_ISR,
  EE_PPCE200ZX_388_ISR,
  EE_PPCE200ZX_389_ISR,
  EE_PPCE200ZX_390_ISR,
  EE_PPCE200ZX_391_ISR,
  EE_PPCE200ZX_392_ISR,
  EE_PPCE200ZX_393_ISR,
  EE_PPCE200ZX_394_ISR,
  EE_PPCE200ZX_395_ISR,
  EE_PPCE200ZX_396_ISR,
  EE_PPCE200ZX_397_ISR,
  EE_PPCE200ZX_398_ISR,
  EE_PPCE200ZX_399_ISR,
  EE_PPCE200ZX_400_ISR,
  EE_PPCE200ZX_401_ISR,
  EE_PPCE200ZX_402_ISR,
  EE_PPCE200ZX_403_ISR,
  EE_PPCE200ZX_404_ISR,
  EE_PPCE200ZX_405_ISR,
  EE_PPCE200ZX_406_ISR,
  EE_PPCE200ZX_407_ISR,
  EE_PPCE200ZX_408_ISR,
  EE_PPCE200ZX_409_ISR,
  EE_PPCE200ZX_410_ISR,
  EE_PPCE200ZX_411_ISR,
  EE_PPCE200ZX_412_ISR,
  EE_PPCE200ZX_413_ISR,
  EE_PPCE200ZX_414_ISR,
  EE_PPCE200ZX_415_ISR,
  EE_PPCE200ZX_416_ISR,
  EE_PPCE200ZX_417_ISR,
  EE_PPCE200ZX_418_ISR,
  EE_PPCE200ZX_419_ISR,
  EE_PPCE200ZX_420_ISR,
  EE_PPCE200ZX_421_ISR,
  EE_PPCE200ZX_422_ISR,
  EE_PPCE200ZX_423_ISR,
  EE_PPCE200ZX_424_ISR,
  EE_PPCE200ZX_425_ISR,
  EE_PPCE200ZX_426_ISR,
  EE_PPCE200ZX_427_ISR,
  EE_PPCE200ZX_428_ISR,
  EE_PPCE200ZX_429_ISR,
  EE_PPCE200ZX_430_ISR,
  EE_PPCE200ZX_431_ISR,
  EE_PPCE200ZX_432_ISR,
  EE_PPCE200ZX_433_ISR,
  EE_PPCE200ZX_434_ISR,
  EE_PPCE200ZX_435_ISR,
  EE_PPCE200ZX_436_ISR,
  EE_PPCE200ZX_437_ISR,
  EE_PPCE200ZX_438_ISR,
  EE_PPCE200ZX_439_ISR,
  EE_PPCE200ZX_440_ISR,
  EE_PPCE200ZX_441_ISR,
  EE_PPCE200ZX_442_ISR,
  EE_PPCE200ZX_443_ISR,
  EE_PPCE200ZX_444_ISR,
  EE_PPCE200ZX_445_ISR,
  EE_PPCE200ZX_446_ISR,
  EE_PPCE200ZX_447_ISR,
  EE_PPCE200ZX_448_ISR,
  EE_PPCE200ZX_449_ISR,
  EE_PPCE200ZX_450_ISR,
  EE_PPCE200ZX_451_ISR,
  EE_PPCE200ZX_452_ISR,
  EE_PPCE200ZX_453_ISR,
  EE_PPCE200ZX_454_ISR,
  EE_PPCE200ZX_455_ISR,
  EE_PPCE200ZX_456_ISR,
  EE_PPCE200ZX_457_ISR,
  EE_PPCE200ZX_458_ISR,
  EE_PPCE200ZX_459_ISR,
  EE_PPCE200ZX_460_ISR,
  EE_PPCE200ZX_461_ISR,
  EE_PPCE200ZX_462_ISR,
  EE_PPCE200ZX_463_ISR,
  EE_PPCE200ZX_464_ISR,
  EE_PPCE200ZX_465_ISR,
  EE_PPCE200ZX_466_ISR,
  EE_PPCE200ZX_467_ISR,
  EE_PPCE200ZX_468_ISR,
  EE_PPCE200ZX_469_ISR,
  EE_PPCE200ZX_470_ISR,
  EE_PPCE200ZX_471_ISR,
  EE_PPCE200ZX_472_ISR,
  EE_PPCE200ZX_473_ISR,
  EE_PPCE200ZX_474_ISR,
  EE_PPCE200ZX_475_ISR,
  EE_PPCE200ZX_476_ISR,
  EE_PPCE200ZX_477_ISR,
  EE_PPCE200ZX_478_ISR,
  EE_PPCE200ZX_479_ISR,
  EE_PPCE200ZX_480_ISR,
  EE_PPCE200ZX_481_ISR,
  EE_PPCE200ZX_482_ISR,
  EE_PPCE200ZX_483_ISR,
  EE_PPCE200ZX_484_ISR,
  EE_PPCE200ZX_485_ISR,
  EE_PPCE200ZX_486_ISR,
  EE_PPCE200ZX_487_ISR,
  EE_PPCE200ZX_488_ISR,
  EE_PPCE200ZX_489_ISR,
  EE_PPCE200ZX_490_ISR,
  EE_PPCE200ZX_491_ISR,
  EE_PPCE200ZX_492_ISR,
  EE_PPCE200ZX_493_ISR,
  EE_PPCE200ZX_494_ISR,
  EE_PPCE200ZX_495_ISR,
  EE_PPCE200ZX_496_ISR,
  EE_PPCE200ZX_497_ISR,
  EE_PPCE200ZX_498_ISR,
  EE_PPCE200ZX_499_ISR,
  EE_PPCE200ZX_500_ISR,
  EE_PPCE200ZX_501_ISR,
  EE_PPCE200ZX_502_ISR,
  EE_PPCE200ZX_503_ISR,
  EE_PPCE200ZX_504_ISR,
  EE_PPCE200ZX_505_ISR,
  EE_PPCE200ZX_506_ISR,
  EE_PPCE200ZX_507_ISR,
  EE_PPCE200ZX_508_ISR,
  EE_PPCE200ZX_509_ISR,
  EE_PPCE200ZX_510_ISR,
  EE_PPCE200ZX_511_ISR,
  EE_PPCE200ZX_512_ISR,
  EE_PPCE200ZX_513_ISR,
  EE_PPCE200ZX_514_ISR,
  EE_PPCE200ZX_515_ISR,
  EE_PPCE200ZX_516_ISR,
  EE_PPCE200ZX_517_ISR,
  EE_PPCE200ZX_518_ISR,
  EE_PPCE200ZX_519_ISR,
  EE_PPCE200ZX_520_ISR,
  EE_PPCE200ZX_521_ISR,
  EE_PPCE200ZX_522_ISR,
  EE_PPCE200ZX_523_ISR,
  EE_PPCE200ZX_524_ISR,
  EE_PPCE200ZX_525_ISR,
  EE_PPCE200ZX_526_ISR,
  EE_PPCE200ZX_527_ISR,
  EE_PPCE200ZX_528_ISR,
  EE_PPCE200ZX_529_ISR,
  EE_PPCE200ZX_530_ISR,
  EE_PPCE200ZX_531_ISR,
  EE_PPCE200ZX_532_ISR,
  EE_PPCE200ZX_533_ISR,
  EE_PPCE200ZX_534_ISR,
  EE_PPCE200ZX_535_ISR,
  EE_PPCE200ZX_536_ISR,
  EE_PPCE200ZX_537_ISR,
  EE_PPCE200ZX_538_ISR,
  EE_PPCE200ZX_539_ISR,
  EE_PPCE200ZX_540_ISR,
  EE_PPCE200ZX_541_ISR,
  EE_PPCE200ZX_542_ISR,
  EE_PPCE200ZX_543_ISR,
  EE_PPCE200ZX_544_ISR,
  EE_PPCE200ZX_545_ISR,
  EE_PPCE200ZX_546_ISR,
  EE_PPCE200ZX_547_ISR,
  EE_PPCE200ZX_548_ISR,
  EE_PPCE200ZX_549_ISR,
  EE_PPCE200ZX_550_ISR,
  EE_PPCE200ZX_551_ISR,
  EE_PPCE200ZX_552_ISR,
  EE_PPCE200ZX_553_ISR,
  EE_PPCE200ZX_554_ISR,
  EE_PPCE200ZX_555_ISR,
  EE_PPCE200ZX_556_ISR,
  EE_PPCE200ZX_557_ISR,
  EE_PPCE200ZX_558_ISR,
  EE_PPCE200ZX_559_ISR,
  EE_PPCE200ZX_560_ISR,
  EE_PPCE200ZX_561_ISR,
  EE_PPCE200ZX_562_ISR,
  EE_PPCE200ZX_563_ISR,
  EE_PPCE200ZX_564_ISR,
  EE_PPCE200ZX_565_ISR,
  EE_PPCE200ZX_566_ISR,
  EE_PPCE200ZX_567_ISR,
  EE_PPCE200ZX_568_ISR,
  EE_PPCE200ZX_569_ISR,
  EE_PPCE200ZX_570_ISR,
  EE_PPCE200ZX_571_ISR,
  EE_PPCE200ZX_572_ISR,
  EE_PPCE200ZX_573_ISR,
  EE_PPCE200ZX_574_ISR,
  EE_PPCE200ZX_575_ISR,
  EE_PPCE200ZX_576_ISR,
  EE_PPCE200ZX_577_ISR,
  EE_PPCE200ZX_578_ISR,
  EE_PPCE200ZX_579_ISR,
  EE_PPCE200ZX_580_ISR,
  EE_PPCE200ZX_581_ISR,
  EE_PPCE200ZX_582_ISR,
  EE_PPCE200ZX_583_ISR,
  EE_PPCE200ZX_584_ISR,
  EE_PPCE200ZX_585_ISR,
  EE_PPCE200ZX_586_ISR,
  EE_PPCE200ZX_587_ISR,
  EE_PPCE200ZX_588_ISR,
  EE_PPCE200ZX_589_ISR,
  EE_PPCE200ZX_590_ISR,
  EE_PPCE200ZX_591_ISR,
  EE_PPCE200ZX_592_ISR,
  EE_PPCE200ZX_593_ISR,
  EE_PPCE200ZX_594_ISR,
  EE_PPCE200ZX_595_ISR,
  EE_PPCE200ZX_596_ISR,
  EE_PPCE200ZX_597_ISR,
  EE_PPCE200ZX_598_ISR,
  EE_PPCE200ZX_599_ISR,
  EE_PPCE200ZX_600_ISR,
  EE_PPCE200ZX_601_ISR,
  EE_PPCE200ZX_602_ISR,
  EE_PPCE200ZX_603_ISR,
  EE_PPCE200ZX_604_ISR,
  EE_PPCE200ZX_605_ISR,
  EE_PPCE200ZX_606_ISR,
  EE_PPCE200ZX_607_ISR,
  EE_PPCE200ZX_608_ISR,
  EE_PPCE200ZX_609_ISR,
  EE_PPCE200ZX_610_ISR,
  EE_PPCE200ZX_611_ISR,
  EE_PPCE200ZX_612_ISR,
  EE_PPCE200ZX_613_ISR,
  EE_PPCE200ZX_614_ISR,
  EE_PPCE200ZX_615_ISR,
  EE_PPCE200ZX_616_ISR,
  EE_PPCE200ZX_617_ISR,
  EE_PPCE200ZX_618_ISR,
  EE_PPCE200ZX_619_ISR,
  EE_PPCE200ZX_620_ISR,
  EE_PPCE200ZX_621_ISR,
  EE_PPCE200ZX_622_ISR,
  EE_PPCE200ZX_623_ISR,
  EE_PPCE200ZX_624_ISR,
  EE_PPCE200ZX_625_ISR,
  EE_PPCE200ZX_626_ISR,
  EE_PPCE200ZX_627_ISR,
  EE_PPCE200ZX_628_ISR,
  EE_PPCE200ZX_629_ISR,
  EE_PPCE200ZX_630_ISR,
  EE_PPCE200ZX_631_ISR,
  EE_PPCE200ZX_632_ISR,
  EE_PPCE200ZX_633_ISR,
  EE_PPCE200ZX_634_ISR,
  EE_PPCE200ZX_635_ISR,
  EE_PPCE200ZX_636_ISR,
  EE_PPCE200ZX_637_ISR,
  EE_PPCE200ZX_638_ISR,
  EE_PPCE200ZX_639_ISR,
  EE_PPCE200ZX_640_ISR,
  EE_PPCE200ZX_641_ISR,
  EE_PPCE200ZX_642_ISR,
  EE_PPCE200ZX_643_ISR,
  EE_PPCE200ZX_644_ISR,
  EE_PPCE200ZX_645_ISR,
  EE_PPCE200ZX_646_ISR,
  EE_PPCE200ZX_647_ISR,
  EE_PPCE200ZX_648_ISR,
  EE_PPCE200ZX_649_ISR,
  EE_PPCE200ZX_650_ISR,
  EE_PPCE200ZX_651_ISR,
  EE_PPCE200ZX_652_ISR,
  EE_PPCE200ZX_653_ISR,
  EE_PPCE200ZX_654_ISR,
  EE_PPCE200ZX_655_ISR,
  EE_PPCE200ZX_656_ISR,
  EE_PPCE200ZX_657_ISR,
  EE_PPCE200ZX_658_ISR,
  EE_PPCE200ZX_659_ISR,
  EE_PPCE200ZX_660_ISR,
  EE_PPCE200ZX_661_ISR,
  EE_PPCE200ZX_662_ISR,
  EE_PPCE200ZX_663_ISR,
  EE_PPCE200ZX_664_ISR,
  EE_PPCE200ZX_665_ISR,
  EE_PPCE200ZX_666_ISR,
  EE_PPCE200ZX_667_ISR,
  EE_PPCE200ZX_668_ISR,
  EE_PPCE200ZX_669_ISR,
  EE_PPCE200ZX_670_ISR,
  EE_PPCE200ZX_671_ISR,
  EE_PPCE200ZX_672_ISR,
  EE_PPCE200ZX_673_ISR,
  EE_PPCE200ZX_674_ISR,
  EE_PPCE200ZX_675_ISR,
  EE_PPCE200ZX_676_ISR,
  EE_PPCE200ZX_677_ISR,
  EE_PPCE200ZX_678_ISR,
  EE_PPCE200ZX_679_ISR,
  EE_PPCE200ZX_680_ISR,
  EE_PPCE200ZX_681_ISR,
  EE_PPCE200ZX_682_ISR,
  EE_PPCE200ZX_683_ISR,
  EE_PPCE200ZX_684_ISR,
  EE_PPCE200ZX_685_ISR,
  EE_PPCE200ZX_686_ISR,
  EE_PPCE200ZX_687_ISR,
  EE_PPCE200ZX_688_ISR,
  EE_PPCE200ZX_689_ISR,
  EE_PPCE200ZX_690_ISR,
  EE_PPCE200ZX_691_ISR,
  EE_PPCE200ZX_692_ISR,
  EE_PPCE200ZX_693_ISR,
  EE_PPCE200ZX_694_ISR,
  EE_PPCE200ZX_695_ISR,
  EE_PPCE200ZX_696_ISR,
  EE_PPCE200ZX_697_ISR,
  EE_PPCE200ZX_698_ISR,
  EE_PPCE200ZX_699_ISR,
  EE_PPCE200ZX_700_ISR,
  EE_PPCE200ZX_701_ISR,
  EE_PPCE200ZX_702_ISR,
  EE_PPCE200ZX_703_ISR,
  EE_PPCE200ZX_704_ISR,
  EE_PPCE200ZX_705_ISR,
  EE_PPCE200ZX_706_ISR,
  EE_PPCE200ZX_707_ISR,
  EE_PPCE200ZX_708_ISR,
  EE_PPCE200ZX_709_ISR,
  EE_PPCE200ZX_710_ISR,
  EE_PPCE200ZX_711_ISR,
  EE_PPCE200ZX_712_ISR,
  EE_PPCE200ZX_713_ISR,
  EE_PPCE200ZX_714_ISR,
  EE_PPCE200ZX_715_ISR,
  EE_PPCE200ZX_716_ISR,
  EE_PPCE200ZX_717_ISR,
  EE_PPCE200ZX_718_ISR,
  EE_PPCE200ZX_719_ISR,
  EE_PPCE200ZX_720_ISR,
  EE_PPCE200ZX_721_ISR,
  EE_PPCE200ZX_722_ISR,
  EE_PPCE200ZX_723_ISR,
  EE_PPCE200ZX_724_ISR,
  EE_PPCE200ZX_725_ISR,
  EE_PPCE200ZX_726_ISR,
  EE_PPCE200ZX_727_ISR,
  EE_PPCE200ZX_728_ISR,
  EE_PPCE200ZX_729_ISR,
  EE_PPCE200ZX_730_ISR,
  EE_PPCE200ZX_731_ISR,
  EE_PPCE200ZX_732_ISR,
  EE_PPCE200ZX_733_ISR,
  EE_PPCE200ZX_734_ISR,
  EE_PPCE200ZX_735_ISR,
  EE_PPCE200ZX_736_ISR,
  EE_PPCE200ZX_737_ISR,
  EE_PPCE200ZX_738_ISR,
  EE_PPCE200ZX_739_ISR,
  EE_PPCE200ZX_740_ISR,
  EE_PPCE200ZX_741_ISR,
  EE_PPCE200ZX_742_ISR,
  EE_PPCE200ZX_743_ISR,
  EE_PPCE200ZX_744_ISR,
  EE_PPCE200ZX_745_ISR,
  EE_PPCE200ZX_746_ISR,
  EE_PPCE200ZX_747_ISR,
  EE_PPCE200ZX_748_ISR,
  EE_PPCE200ZX_749_ISR,
  EE_PPCE200ZX_750_ISR,
  EE_PPCE200ZX_751_ISR,
  EE_PPCE200ZX_752_ISR,
  EE_PPCE200ZX_753_ISR,
  EE_PPCE200ZX_754_ISR,
  EE_PPCE200ZX_755_ISR,
  EE_PPCE200ZX_756_ISR,
  EE_PPCE200ZX_757_ISR,
  EE_PPCE200ZX_758_ISR,
  EE_PPCE200ZX_759_ISR,
  EE_PPCE200ZX_760_ISR,
  EE_PPCE200ZX_761_ISR,
  EE_PPCE200ZX_762_ISR,
  EE_PPCE200ZX_763_ISR,
  EE_PPCE200ZX_764_ISR,
  EE_PPCE200ZX_765_ISR,
  EE_PPCE200ZX_766_ISR,
  EE_PPCE200ZX_767_ISR,
  EE_PPCE200ZX_768_ISR,
  EE_PPCE200ZX_769_ISR,
  EE_PPCE200ZX_770_ISR,
  EE_PPCE200ZX_771_ISR,
  EE_PPCE200ZX_772_ISR,
  EE_PPCE200ZX_773_ISR,
  EE_PPCE200ZX_774_ISR,
  EE_PPCE200ZX_775_ISR,
  EE_PPCE200ZX_776_ISR,
  EE_PPCE200ZX_777_ISR,
  EE_PPCE200ZX_778_ISR,
  EE_PPCE200ZX_779_ISR,
  EE_PPCE200ZX_780_ISR,
  EE_PPCE200ZX_781_ISR,
  EE_PPCE200ZX_782_ISR,
  EE_PPCE200ZX_783_ISR,
  EE_PPCE200ZX_784_ISR,
  EE_PPCE200ZX_785_ISR,
  EE_PPCE200ZX_786_ISR,
  EE_PPCE200ZX_787_ISR,
  EE_PPCE200ZX_788_ISR,
  EE_PPCE200ZX_789_ISR,
  EE_PPCE200ZX_790_ISR,
  EE_PPCE200ZX_791_ISR,
  EE_PPCE200ZX_792_ISR,
  EE_PPCE200ZX_793_ISR,
  EE_PPCE200ZX_794_ISR,
  EE_PPCE200ZX_795_ISR,
  EE_PPCE200ZX_796_ISR,
  EE_PPCE200ZX_797_ISR,
  EE_PPCE200ZX_798_ISR,
  EE_PPCE200ZX_799_ISR,
  EE_PPCE200ZX_800_ISR,
  EE_PPCE200ZX_801_ISR,
  EE_PPCE200ZX_802_ISR,
  EE_PPCE200ZX_803_ISR,
  EE_PPCE200ZX_804_ISR,
  EE_PPCE200ZX_805_ISR,
  EE_PPCE200ZX_806_ISR,
  EE_PPCE200ZX_807_ISR,
  EE_PPCE200ZX_808_ISR,
  EE_PPCE200ZX_809_ISR,
  EE_PPCE200ZX_810_ISR,
  EE_PPCE200ZX_811_ISR,
  EE_PPCE200ZX_812_ISR,
  EE_PPCE200ZX_813_ISR,
  EE_PPCE200ZX_814_ISR,
  EE_PPCE200ZX_815_ISR,
  EE_PPCE200ZX_816_ISR,
  EE_PPCE200ZX_817_ISR,
  EE_PPCE200ZX_818_ISR,
  EE_PPCE200ZX_819_ISR,
  EE_PPCE200ZX_820_ISR,
  EE_PPCE200ZX_821_ISR,
  EE_PPCE200ZX_822_ISR,
  EE_PPCE200ZX_823_ISR,
  EE_PPCE200ZX_824_ISR,
  EE_PPCE200ZX_825_ISR,
  EE_PPCE200ZX_826_ISR,
  EE_PPCE200ZX_827_ISR,
  EE_PPCE200ZX_828_ISR,
  EE_PPCE200ZX_829_ISR,
  EE_PPCE200ZX_830_ISR,
  EE_PPCE200ZX_831_ISR,
  EE_PPCE200ZX_832_ISR,
  EE_PPCE200ZX_833_ISR,
  EE_PPCE200ZX_834_ISR,
  EE_PPCE200ZX_835_ISR,
  EE_PPCE200ZX_836_ISR,
  EE_PPCE200ZX_837_ISR,
  EE_PPCE200ZX_838_ISR,
  EE_PPCE200ZX_839_ISR,
  EE_PPCE200ZX_840_ISR,
  EE_PPCE200ZX_841_ISR,
  EE_PPCE200ZX_842_ISR,
  EE_PPCE200ZX_843_ISR,
  EE_PPCE200ZX_844_ISR,
  EE_PPCE200ZX_845_ISR,
  EE_PPCE200ZX_846_ISR,
  EE_PPCE200ZX_847_ISR,
  EE_PPCE200ZX_848_ISR,
  EE_PPCE200ZX_849_ISR,
  EE_PPCE200ZX_850_ISR,
  EE_PPCE200ZX_851_ISR,
  EE_PPCE200ZX_852_ISR,
  EE_PPCE200ZX_853_ISR,
  EE_PPCE200ZX_854_ISR,
  EE_PPCE200ZX_855_ISR,
  EE_PPCE200ZX_856_ISR,
  EE_PPCE200ZX_857_ISR,
  EE_PPCE200ZX_858_ISR,
  EE_PPCE200ZX_859_ISR,
  EE_PPCE200ZX_860_ISR,
  EE_PPCE200ZX_861_ISR,
  EE_PPCE200ZX_862_ISR,
  EE_PPCE200ZX_863_ISR,
  EE_PPCE200ZX_864_ISR,
  EE_PPCE200ZX_865_ISR,
  EE_PPCE200ZX_866_ISR,
  EE_PPCE200ZX_867_ISR,
  EE_PPCE200ZX_868_ISR,
  EE_PPCE200ZX_869_ISR,
  EE_PPCE200ZX_870_ISR,
  EE_PPCE200ZX_871_ISR,
  EE_PPCE200ZX_872_ISR,
  EE_PPCE200ZX_873_ISR,
  EE_PPCE200ZX_874_ISR,
  EE_PPCE200ZX_875_ISR,
  EE_PPCE200ZX_876_ISR,
  EE_PPCE200ZX_877_ISR,
  EE_PPCE200ZX_878_ISR,
  EE_PPCE200ZX_879_ISR,
  EE_PPCE200ZX_880_ISR,
  EE_PPCE200ZX_881_ISR,
  EE_PPCE200ZX_882_ISR,
  EE_PPCE200ZX_883_ISR,
  EE_PPCE200ZX_884_ISR,
  EE_PPCE200ZX_885_ISR,
  EE_PPCE200ZX_886_ISR,
  EE_PPCE200ZX_887_ISR,
  EE_PPCE200ZX_888_ISR,
  EE_PPCE200ZX_889_ISR,
  EE_PPCE200ZX_890_ISR,
  EE_PPCE200ZX_891_ISR,
  EE_PPCE200ZX_892_ISR,
  EE_PPCE200ZX_893_ISR,
  EE_PPCE200ZX_894_ISR,
  EE_PPCE200ZX_895_ISR,
  EE_PPCE200ZX_896_ISR,
  EE_PPCE200ZX_897_ISR,
  EE_PPCE200ZX_898_ISR,
  EE_PPCE200ZX_899_ISR,
  EE_PPCE200ZX_900_ISR,
  EE_PPCE200ZX_901_ISR,
  EE_PPCE200ZX_902_ISR,
  EE_PPCE200ZX_903_ISR,
  EE_PPCE200ZX_904_ISR,
  EE_PPCE200ZX_905_ISR,
  EE_PPCE200ZX_906_ISR,
  EE_PPCE200ZX_907_ISR,
  EE_PPCE200ZX_908_ISR,
  EE_PPCE200ZX_909_ISR,
  EE_PPCE200ZX_910_ISR,
  EE_PPCE200ZX_911_ISR,
  EE_PPCE200ZX_912_ISR,
  EE_PPCE200ZX_913_ISR,
  EE_PPCE200ZX_914_ISR,
  EE_PPCE200ZX_915_ISR,
  EE_PPCE200ZX_916_ISR
};

/* For MM-PWT 2: MISRA 8.1 */
__INLINE__ void __ALWAYS_INLINE__
    EE_spc574k_set_external_priority(EE_UREG psr, EE_UREG prio);
__INLINE__ void __ALWAYS_INLINE__
    EE_spc574k_set_external_priority(EE_UREG psr, EE_UREG prio)
{
	*((volatile short *)(INTC_BASE+0x60U)+(psr)) = (short)(CORE_MASK_SELECTOR | prio);
}

#if	0
void EE_spc574k_initialize_external_IRQ_priorities(void);
#endif	/* 0 */

void EE_spc574k_initialize_external_IRQ_priorities(void) {
#if defined(EE_PPCE200ZX_0_ISR_PRI)
  EE_spc574k_set_external_priority(0U, EE_PPCE200ZX_0_ISR_PRI);
#endif /* EE_PPCE200ZX_0_ISR_PRI */
#if defined(EE_PPCE200ZX_1_ISR_PRI)
  EE_spc574k_set_external_priority(1U, EE_PPCE200ZX_1_ISR_PRI);
#endif /* EE_PPCE200ZX_1_ISR_PRI */
#if defined(EE_PPCE200ZX_2_ISR_PRI)
  EE_spc574k_set_external_priority(2U, EE_PPCE200ZX_2_ISR_PRI);
#endif /* EE_PPCE200ZX_2_ISR_PRI */
#if defined(EE_PPCE200ZX_3_ISR_PRI)
  EE_spc574k_set_external_priority(3U, EE_PPCE200ZX_3_ISR_PRI);
#endif /* EE_PPCE200ZX_3_ISR_PRI */
#if defined(EE_PPCE200ZX_4_ISR_PRI)
  EE_spc574k_set_external_priority(4U, EE_PPCE200ZX_4_ISR_PRI);
#endif /* EE_PPCE200ZX_4_ISR_PRI */
#if defined(EE_PPCE200ZX_5_ISR_PRI)
  EE_spc574k_set_external_priority(5U, EE_PPCE200ZX_5_ISR_PRI);
#endif /* EE_PPCE200ZX_5_ISR_PRI */
#if defined(EE_PPCE200ZX_6_ISR_PRI)
  EE_spc574k_set_external_priority(6U, EE_PPCE200ZX_6_ISR_PRI);
#endif /* EE_PPCE200ZX_6_ISR_PRI */
#if defined(EE_PPCE200ZX_7_ISR_PRI)
  EE_spc574k_set_external_priority(7U, EE_PPCE200ZX_7_ISR_PRI);
#endif /* EE_PPCE200ZX_7_ISR_PRI */
#if defined(EE_PPCE200ZX_8_ISR_PRI)
  EE_spc574k_set_external_priority(8U, EE_PPCE200ZX_8_ISR_PRI);
#endif /* EE_PPCE200ZX_8_ISR_PRI */
#if defined(EE_PPCE200ZX_9_ISR_PRI)
  EE_spc574k_set_external_priority(9U, EE_PPCE200ZX_9_ISR_PRI);
#endif /* EE_PPCE200ZX_9_ISR_PRI */
#if defined(EE_PPCE200ZX_10_ISR_PRI)
  EE_spc574k_set_external_priority(10U, EE_PPCE200ZX_10_ISR_PRI);
#endif /* EE_PPCE200ZX_10_ISR_PRI */
#if defined(EE_PPCE200ZX_11_ISR_PRI)
  EE_spc574k_set_external_priority(11U, EE_PPCE200ZX_11_ISR_PRI);
#endif /* EE_PPCE200ZX_11_ISR_PRI */
#if defined(EE_PPCE200ZX_12_ISR_PRI)
  EE_spc574k_set_external_priority(12U, EE_PPCE200ZX_12_ISR_PRI);
#endif /* EE_PPCE200ZX_12_ISR_PRI */
#if defined(EE_PPCE200ZX_13_ISR_PRI)
  EE_spc574k_set_external_priority(13U, EE_PPCE200ZX_13_ISR_PRI);
#endif /* EE_PPCE200ZX_13_ISR_PRI */
#if defined(EE_PPCE200ZX_14_ISR_PRI)
  EE_spc574k_set_external_priority(14U, EE_PPCE200ZX_14_ISR_PRI);
#endif /* EE_PPCE200ZX_14_ISR_PRI */
#if defined(EE_PPCE200ZX_15_ISR_PRI)
  EE_spc574k_set_external_priority(15U, EE_PPCE200ZX_15_ISR_PRI);
#endif /* EE_PPCE200ZX_15_ISR_PRI */
#if defined(EE_PPCE200ZX_16_ISR_PRI)
  EE_spc574k_set_external_priority(16U, EE_PPCE200ZX_16_ISR_PRI);
#endif /* EE_PPCE200ZX_16_ISR_PRI */
#if defined(EE_PPCE200ZX_17_ISR_PRI)
  EE_spc574k_set_external_priority(17U, EE_PPCE200ZX_17_ISR_PRI);
#endif /* EE_PPCE200ZX_17_ISR_PRI */
#if defined(EE_PPCE200ZX_18_ISR_PRI)
  EE_spc574k_set_external_priority(18U, EE_PPCE200ZX_18_ISR_PRI);
#endif /* EE_PPCE200ZX_18_ISR_PRI */
#if defined(EE_PPCE200ZX_19_ISR_PRI)
  EE_spc574k_set_external_priority(19U, EE_PPCE200ZX_19_ISR_PRI);
#endif /* EE_PPCE200ZX_19_ISR_PRI */
#if defined(EE_PPCE200ZX_20_ISR_PRI)
  EE_spc574k_set_external_priority(20U, EE_PPCE200ZX_20_ISR_PRI);
#endif /* EE_PPCE200ZX_20_ISR_PRI */
#if defined(EE_PPCE200ZX_21_ISR_PRI)
  EE_spc574k_set_external_priority(21U, EE_PPCE200ZX_21_ISR_PRI);
#endif /* EE_PPCE200ZX_21_ISR_PRI */
#if defined(EE_PPCE200ZX_22_ISR_PRI)
  EE_spc574k_set_external_priority(22U, EE_PPCE200ZX_22_ISR_PRI);
#endif /* EE_PPCE200ZX_22_ISR_PRI */
#if defined(EE_PPCE200ZX_23_ISR_PRI)
  EE_spc574k_set_external_priority(23U, EE_PPCE200ZX_23_ISR_PRI);
#endif /* EE_PPCE200ZX_23_ISR_PRI */
#if defined(EE_PPCE200ZX_24_ISR_PRI)
  EE_spc574k_set_external_priority(24U, EE_PPCE200ZX_24_ISR_PRI);
#endif /* EE_PPCE200ZX_24_ISR_PRI */
#if defined(EE_PPCE200ZX_25_ISR_PRI)
  EE_spc574k_set_external_priority(25U, EE_PPCE200ZX_25_ISR_PRI);
#endif /* EE_PPCE200ZX_25_ISR_PRI */
#if defined(EE_PPCE200ZX_26_ISR_PRI)
  EE_spc574k_set_external_priority(26U, EE_PPCE200ZX_26_ISR_PRI);
#endif /* EE_PPCE200ZX_26_ISR_PRI */
#if defined(EE_PPCE200ZX_27_ISR_PRI)
  EE_spc574k_set_external_priority(27U, EE_PPCE200ZX_27_ISR_PRI);
#endif /* EE_PPCE200ZX_27_ISR_PRI */
#if defined(EE_PPCE200ZX_28_ISR_PRI)
  EE_spc574k_set_external_priority(28U, EE_PPCE200ZX_28_ISR_PRI);
#endif /* EE_PPCE200ZX_28_ISR_PRI */
#if defined(EE_PPCE200ZX_29_ISR_PRI)
  EE_spc574k_set_external_priority(29U, EE_PPCE200ZX_29_ISR_PRI);
#endif /* EE_PPCE200ZX_29_ISR_PRI */
#if defined(EE_PPCE200ZX_30_ISR_PRI)
  EE_spc574k_set_external_priority(30U, EE_PPCE200ZX_30_ISR_PRI);
#endif /* EE_PPCE200ZX_30_ISR_PRI */
#if defined(EE_PPCE200ZX_31_ISR_PRI)
  EE_spc574k_set_external_priority(31U, EE_PPCE200ZX_31_ISR_PRI);
#endif /* EE_PPCE200ZX_31_ISR_PRI */
#if defined(EE_PPCE200ZX_32_ISR_PRI)
  EE_spc574k_set_external_priority(32U, EE_PPCE200ZX_32_ISR_PRI);
#endif /* EE_PPCE200ZX_32_ISR_PRI */
#if defined(EE_PPCE200ZX_33_ISR_PRI)
  EE_spc574k_set_external_priority(33U, EE_PPCE200ZX_33_ISR_PRI);
#endif /* EE_PPCE200ZX_33_ISR_PRI */
#if defined(EE_PPCE200ZX_34_ISR_PRI)
  EE_spc574k_set_external_priority(34U, EE_PPCE200ZX_34_ISR_PRI);
#endif /* EE_PPCE200ZX_34_ISR_PRI */
#if defined(EE_PPCE200ZX_35_ISR_PRI)
  EE_spc574k_set_external_priority(35U, EE_PPCE200ZX_35_ISR_PRI);
#endif /* EE_PPCE200ZX_35_ISR_PRI */
#if defined(EE_PPCE200ZX_36_ISR_PRI)
  EE_spc574k_set_external_priority(36U, EE_PPCE200ZX_36_ISR_PRI);
#endif /* EE_PPCE200ZX_36_ISR_PRI */
#if defined(EE_PPCE200ZX_37_ISR_PRI)
  EE_spc574k_set_external_priority(37U, EE_PPCE200ZX_37_ISR_PRI);
#endif /* EE_PPCE200ZX_37_ISR_PRI */
#if defined(EE_PPCE200ZX_38_ISR_PRI)
  EE_spc574k_set_external_priority(38U, EE_PPCE200ZX_38_ISR_PRI);
#endif /* EE_PPCE200ZX_38_ISR_PRI */
#if defined(EE_PPCE200ZX_39_ISR_PRI)
  EE_spc574k_set_external_priority(39U, EE_PPCE200ZX_39_ISR_PRI);
#endif /* EE_PPCE200ZX_39_ISR_PRI */
#if defined(EE_PPCE200ZX_40_ISR_PRI)
  EE_spc574k_set_external_priority(40U, EE_PPCE200ZX_40_ISR_PRI);
#endif /* EE_PPCE200ZX_40_ISR_PRI */
#if defined(EE_PPCE200ZX_41_ISR_PRI)
  EE_spc574k_set_external_priority(41U, EE_PPCE200ZX_41_ISR_PRI);
#endif /* EE_PPCE200ZX_41_ISR_PRI */
#if defined(EE_PPCE200ZX_42_ISR_PRI)
  EE_spc574k_set_external_priority(42U, EE_PPCE200ZX_42_ISR_PRI);
#endif /* EE_PPCE200ZX_42_ISR_PRI */
#if defined(EE_PPCE200ZX_43_ISR_PRI)
  EE_spc574k_set_external_priority(43U, EE_PPCE200ZX_43_ISR_PRI);
#endif /* EE_PPCE200ZX_43_ISR_PRI */
#if defined(EE_PPCE200ZX_44_ISR_PRI)
  EE_spc574k_set_external_priority(44U, EE_PPCE200ZX_44_ISR_PRI);
#endif /* EE_PPCE200ZX_44_ISR_PRI */
#if defined(EE_PPCE200ZX_45_ISR_PRI)
  EE_spc574k_set_external_priority(45U, EE_PPCE200ZX_45_ISR_PRI);
#endif /* EE_PPCE200ZX_45_ISR_PRI */
#if defined(EE_PPCE200ZX_46_ISR_PRI)
  EE_spc574k_set_external_priority(46U, EE_PPCE200ZX_46_ISR_PRI);
#endif /* EE_PPCE200ZX_46_ISR_PRI */
#if defined(EE_PPCE200ZX_47_ISR_PRI)
  EE_spc574k_set_external_priority(47U, EE_PPCE200ZX_47_ISR_PRI);
#endif /* EE_PPCE200ZX_47_ISR_PRI */
#if defined(EE_PPCE200ZX_48_ISR_PRI)
  EE_spc574k_set_external_priority(48U, EE_PPCE200ZX_48_ISR_PRI);
#endif /* EE_PPCE200ZX_48_ISR_PRI */
#if defined(EE_PPCE200ZX_49_ISR_PRI)
  EE_spc574k_set_external_priority(49U, EE_PPCE200ZX_49_ISR_PRI);
#endif /* EE_PPCE200ZX_49_ISR_PRI */
#if defined(EE_PPCE200ZX_50_ISR_PRI)
  EE_spc574k_set_external_priority(50U, EE_PPCE200ZX_50_ISR_PRI);
#endif /* EE_PPCE200ZX_50_ISR_PRI */
#if defined(EE_PPCE200ZX_51_ISR_PRI)
  EE_spc574k_set_external_priority(51U, EE_PPCE200ZX_51_ISR_PRI);
#endif /* EE_PPCE200ZX_51_ISR_PRI */
#if defined(EE_PPCE200ZX_52_ISR_PRI)
  EE_spc574k_set_external_priority(52U, EE_PPCE200ZX_52_ISR_PRI);
#endif /* EE_PPCE200ZX_52_ISR_PRI */
#if defined(EE_PPCE200ZX_53_ISR_PRI)
  EE_spc574k_set_external_priority(53U, EE_PPCE200ZX_53_ISR_PRI);
#endif /* EE_PPCE200ZX_53_ISR_PRI */
#if defined(EE_PPCE200ZX_54_ISR_PRI)
  EE_spc574k_set_external_priority(54U, EE_PPCE200ZX_54_ISR_PRI);
#endif /* EE_PPCE200ZX_54_ISR_PRI */
#if defined(EE_PPCE200ZX_55_ISR_PRI)
  EE_spc574k_set_external_priority(55U, EE_PPCE200ZX_55_ISR_PRI);
#endif /* EE_PPCE200ZX_55_ISR_PRI */
#if defined(EE_PPCE200ZX_56_ISR_PRI)
  EE_spc574k_set_external_priority(56U, EE_PPCE200ZX_56_ISR_PRI);
#endif /* EE_PPCE200ZX_56_ISR_PRI */
#if defined(EE_PPCE200ZX_57_ISR_PRI)
  EE_spc574k_set_external_priority(57U, EE_PPCE200ZX_57_ISR_PRI);
#endif /* EE_PPCE200ZX_57_ISR_PRI */
#if defined(EE_PPCE200ZX_58_ISR_PRI)
  EE_spc574k_set_external_priority(58U, EE_PPCE200ZX_58_ISR_PRI);
#endif /* EE_PPCE200ZX_58_ISR_PRI */
#if defined(EE_PPCE200ZX_59_ISR_PRI)
  EE_spc574k_set_external_priority(59U, EE_PPCE200ZX_59_ISR_PRI);
#endif /* EE_PPCE200ZX_59_ISR_PRI */
#if defined(EE_PPCE200ZX_60_ISR_PRI)
  EE_spc574k_set_external_priority(60U, EE_PPCE200ZX_60_ISR_PRI);
#endif /* EE_PPCE200ZX_60_ISR_PRI */
#if defined(EE_PPCE200ZX_61_ISR_PRI)
  EE_spc574k_set_external_priority(61U, EE_PPCE200ZX_61_ISR_PRI);
#endif /* EE_PPCE200ZX_61_ISR_PRI */
#if defined(EE_PPCE200ZX_62_ISR_PRI)
  EE_spc574k_set_external_priority(62U, EE_PPCE200ZX_62_ISR_PRI);
#endif /* EE_PPCE200ZX_62_ISR_PRI */
#if defined(EE_PPCE200ZX_63_ISR_PRI)
  EE_spc574k_set_external_priority(63U, EE_PPCE200ZX_63_ISR_PRI);
#endif /* EE_PPCE200ZX_63_ISR_PRI */
#if defined(EE_PPCE200ZX_64_ISR_PRI)
  EE_spc574k_set_external_priority(64U, EE_PPCE200ZX_64_ISR_PRI);
#endif /* EE_PPCE200ZX_64_ISR_PRI */
#if defined(EE_PPCE200ZX_65_ISR_PRI)
  EE_spc574k_set_external_priority(65U, EE_PPCE200ZX_65_ISR_PRI);
#endif /* EE_PPCE200ZX_65_ISR_PRI */
#if defined(EE_PPCE200ZX_66_ISR_PRI)
  EE_spc574k_set_external_priority(66U, EE_PPCE200ZX_66_ISR_PRI);
#endif /* EE_PPCE200ZX_66_ISR_PRI */
#if defined(EE_PPCE200ZX_67_ISR_PRI)
  EE_spc574k_set_external_priority(67U, EE_PPCE200ZX_67_ISR_PRI);
#endif /* EE_PPCE200ZX_67_ISR_PRI */
#if defined(EE_PPCE200ZX_68_ISR_PRI)
  EE_spc574k_set_external_priority(68U, EE_PPCE200ZX_68_ISR_PRI);
#endif /* EE_PPCE200ZX_68_ISR_PRI */
#if defined(EE_PPCE200ZX_69_ISR_PRI)
  EE_spc574k_set_external_priority(69U, EE_PPCE200ZX_69_ISR_PRI);
#endif /* EE_PPCE200ZX_69_ISR_PRI */
#if defined(EE_PPCE200ZX_70_ISR_PRI)
  EE_spc574k_set_external_priority(70U, EE_PPCE200ZX_70_ISR_PRI);
#endif /* EE_PPCE200ZX_70_ISR_PRI */
#if defined(EE_PPCE200ZX_71_ISR_PRI)
  EE_spc574k_set_external_priority(71U, EE_PPCE200ZX_71_ISR_PRI);
#endif /* EE_PPCE200ZX_71_ISR_PRI */
#if defined(EE_PPCE200ZX_72_ISR_PRI)
  EE_spc574k_set_external_priority(72U, EE_PPCE200ZX_72_ISR_PRI);
#endif /* EE_PPCE200ZX_72_ISR_PRI */
#if defined(EE_PPCE200ZX_73_ISR_PRI)
  EE_spc574k_set_external_priority(73U, EE_PPCE200ZX_73_ISR_PRI);
#endif /* EE_PPCE200ZX_73_ISR_PRI */
#if defined(EE_PPCE200ZX_74_ISR_PRI)
  EE_spc574k_set_external_priority(74U, EE_PPCE200ZX_74_ISR_PRI);
#endif /* EE_PPCE200ZX_74_ISR_PRI */
#if defined(EE_PPCE200ZX_75_ISR_PRI)
  EE_spc574k_set_external_priority(75U, EE_PPCE200ZX_75_ISR_PRI);
#endif /* EE_PPCE200ZX_75_ISR_PRI */
#if defined(EE_PPCE200ZX_76_ISR_PRI)
  EE_spc574k_set_external_priority(76U, EE_PPCE200ZX_76_ISR_PRI);
#endif /* EE_PPCE200ZX_76_ISR_PRI */
#if defined(EE_PPCE200ZX_77_ISR_PRI)
  EE_spc574k_set_external_priority(77U, EE_PPCE200ZX_77_ISR_PRI);
#endif /* EE_PPCE200ZX_77_ISR_PRI */
#if defined(EE_PPCE200ZX_78_ISR_PRI)
  EE_spc574k_set_external_priority(78U, EE_PPCE200ZX_78_ISR_PRI);
#endif /* EE_PPCE200ZX_78_ISR_PRI */
#if defined(EE_PPCE200ZX_79_ISR_PRI)
  EE_spc574k_set_external_priority(79U, EE_PPCE200ZX_79_ISR_PRI);
#endif /* EE_PPCE200ZX_79_ISR_PRI */
#if defined(EE_PPCE200ZX_80_ISR_PRI)
  EE_spc574k_set_external_priority(80U, EE_PPCE200ZX_80_ISR_PRI);
#endif /* EE_PPCE200ZX_80_ISR_PRI */
#if defined(EE_PPCE200ZX_81_ISR_PRI)
  EE_spc574k_set_external_priority(81U, EE_PPCE200ZX_81_ISR_PRI);
#endif /* EE_PPCE200ZX_81_ISR_PRI */
#if defined(EE_PPCE200ZX_82_ISR_PRI)
  EE_spc574k_set_external_priority(82U, EE_PPCE200ZX_82_ISR_PRI);
#endif /* EE_PPCE200ZX_82_ISR_PRI */
#if defined(EE_PPCE200ZX_83_ISR_PRI)
  EE_spc574k_set_external_priority(83U, EE_PPCE200ZX_83_ISR_PRI);
#endif /* EE_PPCE200ZX_83_ISR_PRI */
#if defined(EE_PPCE200ZX_84_ISR_PRI)
  EE_spc574k_set_external_priority(84U, EE_PPCE200ZX_84_ISR_PRI);
#endif /* EE_PPCE200ZX_84_ISR_PRI */
#if defined(EE_PPCE200ZX_85_ISR_PRI)
  EE_spc574k_set_external_priority(85U, EE_PPCE200ZX_85_ISR_PRI);
#endif /* EE_PPCE200ZX_85_ISR_PRI */
#if defined(EE_PPCE200ZX_86_ISR_PRI)
  EE_spc574k_set_external_priority(86U, EE_PPCE200ZX_86_ISR_PRI);
#endif /* EE_PPCE200ZX_86_ISR_PRI */
#if defined(EE_PPCE200ZX_87_ISR_PRI)
  EE_spc574k_set_external_priority(87U, EE_PPCE200ZX_87_ISR_PRI);
#endif /* EE_PPCE200ZX_87_ISR_PRI */
#if defined(EE_PPCE200ZX_88_ISR_PRI)
  EE_spc574k_set_external_priority(88U, EE_PPCE200ZX_88_ISR_PRI);
#endif /* EE_PPCE200ZX_88_ISR_PRI */
#if defined(EE_PPCE200ZX_89_ISR_PRI)
  EE_spc574k_set_external_priority(89U, EE_PPCE200ZX_89_ISR_PRI);
#endif /* EE_PPCE200ZX_89_ISR_PRI */
#if defined(EE_PPCE200ZX_90_ISR_PRI)
  EE_spc574k_set_external_priority(90U, EE_PPCE200ZX_90_ISR_PRI);
#endif /* EE_PPCE200ZX_90_ISR_PRI */
#if defined(EE_PPCE200ZX_91_ISR_PRI)
  EE_spc574k_set_external_priority(91U, EE_PPCE200ZX_91_ISR_PRI);
#endif /* EE_PPCE200ZX_91_ISR_PRI */
#if defined(EE_PPCE200ZX_92_ISR_PRI)
  EE_spc574k_set_external_priority(92U, EE_PPCE200ZX_92_ISR_PRI);
#endif /* EE_PPCE200ZX_92_ISR_PRI */
#if defined(EE_PPCE200ZX_93_ISR_PRI)
  EE_spc574k_set_external_priority(93U, EE_PPCE200ZX_93_ISR_PRI);
#endif /* EE_PPCE200ZX_93_ISR_PRI */
#if defined(EE_PPCE200ZX_94_ISR_PRI)
  EE_spc574k_set_external_priority(94U, EE_PPCE200ZX_94_ISR_PRI);
#endif /* EE_PPCE200ZX_94_ISR_PRI */
#if defined(EE_PPCE200ZX_95_ISR_PRI)
  EE_spc574k_set_external_priority(95U, EE_PPCE200ZX_95_ISR_PRI);
#endif /* EE_PPCE200ZX_95_ISR_PRI */
#if defined(EE_PPCE200ZX_96_ISR_PRI)
  EE_spc574k_set_external_priority(96U, EE_PPCE200ZX_96_ISR_PRI);
#endif /* EE_PPCE200ZX_96_ISR_PRI */
#if defined(EE_PPCE200ZX_97_ISR_PRI)
  EE_spc574k_set_external_priority(97U, EE_PPCE200ZX_97_ISR_PRI);
#endif /* EE_PPCE200ZX_97_ISR_PRI */
#if defined(EE_PPCE200ZX_98_ISR_PRI)
  EE_spc574k_set_external_priority(98U, EE_PPCE200ZX_98_ISR_PRI);
#endif /* EE_PPCE200ZX_98_ISR_PRI */
#if defined(EE_PPCE200ZX_99_ISR_PRI)
  EE_spc574k_set_external_priority(99U, EE_PPCE200ZX_99_ISR_PRI);
#endif /* EE_PPCE200ZX_99_ISR_PRI */
#if defined(EE_PPCE200ZX_100_ISR_PRI)
  EE_spc574k_set_external_priority(100U, EE_PPCE200ZX_100_ISR_PRI);
#endif /* EE_PPCE200ZX_100_ISR_PRI */
#if defined(EE_PPCE200ZX_101_ISR_PRI)
  EE_spc574k_set_external_priority(101U, EE_PPCE200ZX_101_ISR_PRI);
#endif /* EE_PPCE200ZX_101_ISR_PRI */
#if defined(EE_PPCE200ZX_102_ISR_PRI)
  EE_spc574k_set_external_priority(102U, EE_PPCE200ZX_102_ISR_PRI);
#endif /* EE_PPCE200ZX_102_ISR_PRI */
#if defined(EE_PPCE200ZX_103_ISR_PRI)
  EE_spc574k_set_external_priority(103U, EE_PPCE200ZX_103_ISR_PRI);
#endif /* EE_PPCE200ZX_103_ISR_PRI */
#if defined(EE_PPCE200ZX_104_ISR_PRI)
  EE_spc574k_set_external_priority(104U, EE_PPCE200ZX_104_ISR_PRI);
#endif /* EE_PPCE200ZX_104_ISR_PRI */
#if defined(EE_PPCE200ZX_105_ISR_PRI)
  EE_spc574k_set_external_priority(105U, EE_PPCE200ZX_105_ISR_PRI);
#endif /* EE_PPCE200ZX_105_ISR_PRI */
#if defined(EE_PPCE200ZX_106_ISR_PRI)
  EE_spc574k_set_external_priority(106U, EE_PPCE200ZX_106_ISR_PRI);
#endif /* EE_PPCE200ZX_106_ISR_PRI */
#if defined(EE_PPCE200ZX_107_ISR_PRI)
  EE_spc574k_set_external_priority(107U, EE_PPCE200ZX_107_ISR_PRI);
#endif /* EE_PPCE200ZX_107_ISR_PRI */
#if defined(EE_PPCE200ZX_108_ISR_PRI)
  EE_spc574k_set_external_priority(108U, EE_PPCE200ZX_108_ISR_PRI);
#endif /* EE_PPCE200ZX_108_ISR_PRI */
#if defined(EE_PPCE200ZX_109_ISR_PRI)
  EE_spc574k_set_external_priority(109U, EE_PPCE200ZX_109_ISR_PRI);
#endif /* EE_PPCE200ZX_109_ISR_PRI */
#if defined(EE_PPCE200ZX_110_ISR_PRI)
  EE_spc574k_set_external_priority(110U, EE_PPCE200ZX_110_ISR_PRI);
#endif /* EE_PPCE200ZX_110_ISR_PRI */
#if defined(EE_PPCE200ZX_111_ISR_PRI)
  EE_spc574k_set_external_priority(111U, EE_PPCE200ZX_111_ISR_PRI);
#endif /* EE_PPCE200ZX_111_ISR_PRI */
#if defined(EE_PPCE200ZX_112_ISR_PRI)
  EE_spc574k_set_external_priority(112U, EE_PPCE200ZX_112_ISR_PRI);
#endif /* EE_PPCE200ZX_112_ISR_PRI */
#if defined(EE_PPCE200ZX_113_ISR_PRI)
  EE_spc574k_set_external_priority(113U, EE_PPCE200ZX_113_ISR_PRI);
#endif /* EE_PPCE200ZX_113_ISR_PRI */
#if defined(EE_PPCE200ZX_114_ISR_PRI)
  EE_spc574k_set_external_priority(114U, EE_PPCE200ZX_114_ISR_PRI);
#endif /* EE_PPCE200ZX_114_ISR_PRI */
#if defined(EE_PPCE200ZX_115_ISR_PRI)
  EE_spc574k_set_external_priority(115U, EE_PPCE200ZX_115_ISR_PRI);
#endif /* EE_PPCE200ZX_115_ISR_PRI */
#if defined(EE_PPCE200ZX_116_ISR_PRI)
  EE_spc574k_set_external_priority(116U, EE_PPCE200ZX_116_ISR_PRI);
#endif /* EE_PPCE200ZX_116_ISR_PRI */
#if defined(EE_PPCE200ZX_117_ISR_PRI)
  EE_spc574k_set_external_priority(117U, EE_PPCE200ZX_117_ISR_PRI);
#endif /* EE_PPCE200ZX_117_ISR_PRI */
#if defined(EE_PPCE200ZX_118_ISR_PRI)
  EE_spc574k_set_external_priority(118U, EE_PPCE200ZX_118_ISR_PRI);
#endif /* EE_PPCE200ZX_118_ISR_PRI */
#if defined(EE_PPCE200ZX_119_ISR_PRI)
  EE_spc574k_set_external_priority(119U, EE_PPCE200ZX_119_ISR_PRI);
#endif /* EE_PPCE200ZX_119_ISR_PRI */
#if defined(EE_PPCE200ZX_120_ISR_PRI)
  EE_spc574k_set_external_priority(120U, EE_PPCE200ZX_120_ISR_PRI);
#endif /* EE_PPCE200ZX_120_ISR_PRI */
#if defined(EE_PPCE200ZX_121_ISR_PRI)
  EE_spc574k_set_external_priority(121U, EE_PPCE200ZX_121_ISR_PRI);
#endif /* EE_PPCE200ZX_121_ISR_PRI */
#if defined(EE_PPCE200ZX_122_ISR_PRI)
  EE_spc574k_set_external_priority(122U, EE_PPCE200ZX_122_ISR_PRI);
#endif /* EE_PPCE200ZX_122_ISR_PRI */
#if defined(EE_PPCE200ZX_123_ISR_PRI)
  EE_spc574k_set_external_priority(123U, EE_PPCE200ZX_123_ISR_PRI);
#endif /* EE_PPCE200ZX_123_ISR_PRI */
#if defined(EE_PPCE200ZX_124_ISR_PRI)
  EE_spc574k_set_external_priority(124U, EE_PPCE200ZX_124_ISR_PRI);
#endif /* EE_PPCE200ZX_124_ISR_PRI */
#if defined(EE_PPCE200ZX_125_ISR_PRI)
  EE_spc574k_set_external_priority(125U, EE_PPCE200ZX_125_ISR_PRI);
#endif /* EE_PPCE200ZX_125_ISR_PRI */
#if defined(EE_PPCE200ZX_126_ISR_PRI)
  EE_spc574k_set_external_priority(126U, EE_PPCE200ZX_126_ISR_PRI);
#endif /* EE_PPCE200ZX_126_ISR_PRI */
#if defined(EE_PPCE200ZX_127_ISR_PRI)
  EE_spc574k_set_external_priority(127U, EE_PPCE200ZX_127_ISR_PRI);
#endif /* EE_PPCE200ZX_127_ISR_PRI */
#if defined(EE_PPCE200ZX_128_ISR_PRI)
  EE_spc574k_set_external_priority(128U, EE_PPCE200ZX_128_ISR_PRI);
#endif /* EE_PPCE200ZX_128_ISR_PRI */
#if defined(EE_PPCE200ZX_129_ISR_PRI)
  EE_spc574k_set_external_priority(129U, EE_PPCE200ZX_129_ISR_PRI);
#endif /* EE_PPCE200ZX_129_ISR_PRI */
#if defined(EE_PPCE200ZX_130_ISR_PRI)
  EE_spc574k_set_external_priority(130U, EE_PPCE200ZX_130_ISR_PRI);
#endif /* EE_PPCE200ZX_130_ISR_PRI */
#if defined(EE_PPCE200ZX_131_ISR_PRI)
  EE_spc574k_set_external_priority(131U, EE_PPCE200ZX_131_ISR_PRI);
#endif /* EE_PPCE200ZX_131_ISR_PRI */
#if defined(EE_PPCE200ZX_132_ISR_PRI)
  EE_spc574k_set_external_priority(132U, EE_PPCE200ZX_132_ISR_PRI);
#endif /* EE_PPCE200ZX_132_ISR_PRI */
#if defined(EE_PPCE200ZX_133_ISR_PRI)
  EE_spc574k_set_external_priority(133U, EE_PPCE200ZX_133_ISR_PRI);
#endif /* EE_PPCE200ZX_133_ISR_PRI */
#if defined(EE_PPCE200ZX_134_ISR_PRI)
  EE_spc574k_set_external_priority(134U, EE_PPCE200ZX_134_ISR_PRI);
#endif /* EE_PPCE200ZX_134_ISR_PRI */
#if defined(EE_PPCE200ZX_135_ISR_PRI)
  EE_spc574k_set_external_priority(135U, EE_PPCE200ZX_135_ISR_PRI);
#endif /* EE_PPCE200ZX_135_ISR_PRI */
#if defined(EE_PPCE200ZX_136_ISR_PRI)
  EE_spc574k_set_external_priority(136U, EE_PPCE200ZX_136_ISR_PRI);
#endif /* EE_PPCE200ZX_136_ISR_PRI */
#if defined(EE_PPCE200ZX_137_ISR_PRI)
  EE_spc574k_set_external_priority(137U, EE_PPCE200ZX_137_ISR_PRI);
#endif /* EE_PPCE200ZX_137_ISR_PRI */
#if defined(EE_PPCE200ZX_138_ISR_PRI)
  EE_spc574k_set_external_priority(138U, EE_PPCE200ZX_138_ISR_PRI);
#endif /* EE_PPCE200ZX_138_ISR_PRI */
#if defined(EE_PPCE200ZX_139_ISR_PRI)
  EE_spc574k_set_external_priority(139U, EE_PPCE200ZX_139_ISR_PRI);
#endif /* EE_PPCE200ZX_139_ISR_PRI */
#if defined(EE_PPCE200ZX_140_ISR_PRI)
  EE_spc574k_set_external_priority(140U, EE_PPCE200ZX_140_ISR_PRI);
#endif /* EE_PPCE200ZX_140_ISR_PRI */
#if defined(EE_PPCE200ZX_141_ISR_PRI)
  EE_spc574k_set_external_priority(141U, EE_PPCE200ZX_141_ISR_PRI);
#endif /* EE_PPCE200ZX_141_ISR_PRI */
#if defined(EE_PPCE200ZX_142_ISR_PRI)
  EE_spc574k_set_external_priority(142U, EE_PPCE200ZX_142_ISR_PRI);
#endif /* EE_PPCE200ZX_142_ISR_PRI */
#if defined(EE_PPCE200ZX_143_ISR_PRI)
  EE_spc574k_set_external_priority(143U, EE_PPCE200ZX_143_ISR_PRI);
#endif /* EE_PPCE200ZX_143_ISR_PRI */
#if defined(EE_PPCE200ZX_144_ISR_PRI)
  EE_spc574k_set_external_priority(144U, EE_PPCE200ZX_144_ISR_PRI);
#endif /* EE_PPCE200ZX_144_ISR_PRI */
#if defined(EE_PPCE200ZX_145_ISR_PRI)
  EE_spc574k_set_external_priority(145U, EE_PPCE200ZX_145_ISR_PRI);
#endif /* EE_PPCE200ZX_145_ISR_PRI */
#if defined(EE_PPCE200ZX_146_ISR_PRI)
  EE_spc574k_set_external_priority(146U, EE_PPCE200ZX_146_ISR_PRI);
#endif /* EE_PPCE200ZX_146_ISR_PRI */
#if defined(EE_PPCE200ZX_147_ISR_PRI)
  EE_spc574k_set_external_priority(147U, EE_PPCE200ZX_147_ISR_PRI);
#endif /* EE_PPCE200ZX_147_ISR_PRI */
#if defined(EE_PPCE200ZX_148_ISR_PRI)
  EE_spc574k_set_external_priority(148U, EE_PPCE200ZX_148_ISR_PRI);
#endif /* EE_PPCE200ZX_148_ISR_PRI */
#if defined(EE_PPCE200ZX_149_ISR_PRI)
  EE_spc574k_set_external_priority(149U, EE_PPCE200ZX_149_ISR_PRI);
#endif /* EE_PPCE200ZX_149_ISR_PRI */
#if defined(EE_PPCE200ZX_150_ISR_PRI)
  EE_spc574k_set_external_priority(150U, EE_PPCE200ZX_150_ISR_PRI);
#endif /* EE_PPCE200ZX_150_ISR_PRI */
#if defined(EE_PPCE200ZX_151_ISR_PRI)
  EE_spc574k_set_external_priority(151U, EE_PPCE200ZX_151_ISR_PRI);
#endif /* EE_PPCE200ZX_151_ISR_PRI */
#if defined(EE_PPCE200ZX_152_ISR_PRI)
  EE_spc574k_set_external_priority(152U, EE_PPCE200ZX_152_ISR_PRI);
#endif /* EE_PPCE200ZX_152_ISR_PRI */
#if defined(EE_PPCE200ZX_153_ISR_PRI)
  EE_spc574k_set_external_priority(153U, EE_PPCE200ZX_153_ISR_PRI);
#endif /* EE_PPCE200ZX_153_ISR_PRI */
#if defined(EE_PPCE200ZX_154_ISR_PRI)
  EE_spc574k_set_external_priority(154U, EE_PPCE200ZX_154_ISR_PRI);
#endif /* EE_PPCE200ZX_154_ISR_PRI */
#if defined(EE_PPCE200ZX_155_ISR_PRI)
  EE_spc574k_set_external_priority(155U, EE_PPCE200ZX_155_ISR_PRI);
#endif /* EE_PPCE200ZX_155_ISR_PRI */
#if defined(EE_PPCE200ZX_156_ISR_PRI)
  EE_spc574k_set_external_priority(156U, EE_PPCE200ZX_156_ISR_PRI);
#endif /* EE_PPCE200ZX_156_ISR_PRI */
#if defined(EE_PPCE200ZX_157_ISR_PRI)
  EE_spc574k_set_external_priority(157U, EE_PPCE200ZX_157_ISR_PRI);
#endif /* EE_PPCE200ZX_157_ISR_PRI */
#if defined(EE_PPCE200ZX_158_ISR_PRI)
  EE_spc574k_set_external_priority(158U, EE_PPCE200ZX_158_ISR_PRI);
#endif /* EE_PPCE200ZX_158_ISR_PRI */
#if defined(EE_PPCE200ZX_159_ISR_PRI)
  EE_spc574k_set_external_priority(159U, EE_PPCE200ZX_159_ISR_PRI);
#endif /* EE_PPCE200ZX_159_ISR_PRI */
#if defined(EE_PPCE200ZX_160_ISR_PRI)
  EE_spc574k_set_external_priority(160U, EE_PPCE200ZX_160_ISR_PRI);
#endif /* EE_PPCE200ZX_160_ISR_PRI */
#if defined(EE_PPCE200ZX_161_ISR_PRI)
  EE_spc574k_set_external_priority(161U, EE_PPCE200ZX_161_ISR_PRI);
#endif /* EE_PPCE200ZX_161_ISR_PRI */
#if defined(EE_PPCE200ZX_162_ISR_PRI)
  EE_spc574k_set_external_priority(162U, EE_PPCE200ZX_162_ISR_PRI);
#endif /* EE_PPCE200ZX_162_ISR_PRI */
#if defined(EE_PPCE200ZX_163_ISR_PRI)
  EE_spc574k_set_external_priority(163U, EE_PPCE200ZX_163_ISR_PRI);
#endif /* EE_PPCE200ZX_163_ISR_PRI */
#if defined(EE_PPCE200ZX_164_ISR_PRI)
  EE_spc574k_set_external_priority(164U, EE_PPCE200ZX_164_ISR_PRI);
#endif /* EE_PPCE200ZX_164_ISR_PRI */
#if defined(EE_PPCE200ZX_165_ISR_PRI)
  EE_spc574k_set_external_priority(165U, EE_PPCE200ZX_165_ISR_PRI);
#endif /* EE_PPCE200ZX_165_ISR_PRI */
#if defined(EE_PPCE200ZX_166_ISR_PRI)
  EE_spc574k_set_external_priority(166U, EE_PPCE200ZX_166_ISR_PRI);
#endif /* EE_PPCE200ZX_166_ISR_PRI */
#if defined(EE_PPCE200ZX_167_ISR_PRI)
  EE_spc574k_set_external_priority(167U, EE_PPCE200ZX_167_ISR_PRI);
#endif /* EE_PPCE200ZX_167_ISR_PRI */
#if defined(EE_PPCE200ZX_168_ISR_PRI)
  EE_spc574k_set_external_priority(168U, EE_PPCE200ZX_168_ISR_PRI);
#endif /* EE_PPCE200ZX_168_ISR_PRI */
#if defined(EE_PPCE200ZX_169_ISR_PRI)
  EE_spc574k_set_external_priority(169U, EE_PPCE200ZX_169_ISR_PRI);
#endif /* EE_PPCE200ZX_169_ISR_PRI */
#if defined(EE_PPCE200ZX_170_ISR_PRI)
  EE_spc574k_set_external_priority(170U, EE_PPCE200ZX_170_ISR_PRI);
#endif /* EE_PPCE200ZX_170_ISR_PRI */
#if defined(EE_PPCE200ZX_171_ISR_PRI)
  EE_spc574k_set_external_priority(171U, EE_PPCE200ZX_171_ISR_PRI);
#endif /* EE_PPCE200ZX_171_ISR_PRI */
#if defined(EE_PPCE200ZX_172_ISR_PRI)
  EE_spc574k_set_external_priority(172U, EE_PPCE200ZX_172_ISR_PRI);
#endif /* EE_PPCE200ZX_172_ISR_PRI */
#if defined(EE_PPCE200ZX_173_ISR_PRI)
  EE_spc574k_set_external_priority(173U, EE_PPCE200ZX_173_ISR_PRI);
#endif /* EE_PPCE200ZX_173_ISR_PRI */
#if defined(EE_PPCE200ZX_174_ISR_PRI)
  EE_spc574k_set_external_priority(174U, EE_PPCE200ZX_174_ISR_PRI);
#endif /* EE_PPCE200ZX_174_ISR_PRI */
#if defined(EE_PPCE200ZX_175_ISR_PRI)
  EE_spc574k_set_external_priority(175U, EE_PPCE200ZX_175_ISR_PRI);
#endif /* EE_PPCE200ZX_175_ISR_PRI */
#if defined(EE_PPCE200ZX_176_ISR_PRI)
  EE_spc574k_set_external_priority(176U, EE_PPCE200ZX_176_ISR_PRI);
#endif /* EE_PPCE200ZX_176_ISR_PRI */
#if defined(EE_PPCE200ZX_177_ISR_PRI)
  EE_spc574k_set_external_priority(177U, EE_PPCE200ZX_177_ISR_PRI);
#endif /* EE_PPCE200ZX_177_ISR_PRI */
#if defined(EE_PPCE200ZX_178_ISR_PRI)
  EE_spc574k_set_external_priority(178U, EE_PPCE200ZX_178_ISR_PRI);
#endif /* EE_PPCE200ZX_178_ISR_PRI */
#if defined(EE_PPCE200ZX_179_ISR_PRI)
  EE_spc574k_set_external_priority(179U, EE_PPCE200ZX_179_ISR_PRI);
#endif /* EE_PPCE200ZX_179_ISR_PRI */
#if defined(EE_PPCE200ZX_180_ISR_PRI)
  EE_spc574k_set_external_priority(180U, EE_PPCE200ZX_180_ISR_PRI);
#endif /* EE_PPCE200ZX_180_ISR_PRI */
#if defined(EE_PPCE200ZX_181_ISR_PRI)
  EE_spc574k_set_external_priority(181U, EE_PPCE200ZX_181_ISR_PRI);
#endif /* EE_PPCE200ZX_181_ISR_PRI */
#if defined(EE_PPCE200ZX_182_ISR_PRI)
  EE_spc574k_set_external_priority(182U, EE_PPCE200ZX_182_ISR_PRI);
#endif /* EE_PPCE200ZX_182_ISR_PRI */
#if defined(EE_PPCE200ZX_183_ISR_PRI)
  EE_spc574k_set_external_priority(183U, EE_PPCE200ZX_183_ISR_PRI);
#endif /* EE_PPCE200ZX_183_ISR_PRI */
#if defined(EE_PPCE200ZX_184_ISR_PRI)
  EE_spc574k_set_external_priority(184U, EE_PPCE200ZX_184_ISR_PRI);
#endif /* EE_PPCE200ZX_184_ISR_PRI */
#if defined(EE_PPCE200ZX_185_ISR_PRI)
  EE_spc574k_set_external_priority(185U, EE_PPCE200ZX_185_ISR_PRI);
#endif /* EE_PPCE200ZX_185_ISR_PRI */
#if defined(EE_PPCE200ZX_186_ISR_PRI)
  EE_spc574k_set_external_priority(186U, EE_PPCE200ZX_186_ISR_PRI);
#endif /* EE_PPCE200ZX_186_ISR_PRI */
#if defined(EE_PPCE200ZX_187_ISR_PRI)
  EE_spc574k_set_external_priority(187U, EE_PPCE200ZX_187_ISR_PRI);
#endif /* EE_PPCE200ZX_187_ISR_PRI */
#if defined(EE_PPCE200ZX_188_ISR_PRI)
  EE_spc574k_set_external_priority(188U, EE_PPCE200ZX_188_ISR_PRI);
#endif /* EE_PPCE200ZX_188_ISR_PRI */
#if defined(EE_PPCE200ZX_189_ISR_PRI)
  EE_spc574k_set_external_priority(189U, EE_PPCE200ZX_189_ISR_PRI);
#endif /* EE_PPCE200ZX_189_ISR_PRI */
#if defined(EE_PPCE200ZX_190_ISR_PRI)
  EE_spc574k_set_external_priority(190U, EE_PPCE200ZX_190_ISR_PRI);
#endif /* EE_PPCE200ZX_190_ISR_PRI */
#if defined(EE_PPCE200ZX_191_ISR_PRI)
  EE_spc574k_set_external_priority(191U, EE_PPCE200ZX_191_ISR_PRI);
#endif /* EE_PPCE200ZX_191_ISR_PRI */
#if defined(EE_PPCE200ZX_192_ISR_PRI)
  EE_spc574k_set_external_priority(192U, EE_PPCE200ZX_192_ISR_PRI);
#endif /* EE_PPCE200ZX_192_ISR_PRI */
#if defined(EE_PPCE200ZX_193_ISR_PRI)
  EE_spc574k_set_external_priority(193U, EE_PPCE200ZX_193_ISR_PRI);
#endif /* EE_PPCE200ZX_193_ISR_PRI */
#if defined(EE_PPCE200ZX_194_ISR_PRI)
  EE_spc574k_set_external_priority(194U, EE_PPCE200ZX_194_ISR_PRI);
#endif /* EE_PPCE200ZX_194_ISR_PRI */
#if defined(EE_PPCE200ZX_195_ISR_PRI)
  EE_spc574k_set_external_priority(195U, EE_PPCE200ZX_195_ISR_PRI);
#endif /* EE_PPCE200ZX_195_ISR_PRI */
#if defined(EE_PPCE200ZX_196_ISR_PRI)
  EE_spc574k_set_external_priority(196U, EE_PPCE200ZX_196_ISR_PRI);
#endif /* EE_PPCE200ZX_196_ISR_PRI */
#if defined(EE_PPCE200ZX_197_ISR_PRI)
  EE_spc574k_set_external_priority(197U, EE_PPCE200ZX_197_ISR_PRI);
#endif /* EE_PPCE200ZX_197_ISR_PRI */
#if defined(EE_PPCE200ZX_198_ISR_PRI)
  EE_spc574k_set_external_priority(198U, EE_PPCE200ZX_198_ISR_PRI);
#endif /* EE_PPCE200ZX_198_ISR_PRI */
#if defined(EE_PPCE200ZX_199_ISR_PRI)
  EE_spc574k_set_external_priority(199U, EE_PPCE200ZX_199_ISR_PRI);
#endif /* EE_PPCE200ZX_199_ISR_PRI */
#if defined(EE_PPCE200ZX_200_ISR_PRI)
  EE_spc574k_set_external_priority(200U, EE_PPCE200ZX_200_ISR_PRI);
#endif /* EE_PPCE200ZX_200_ISR_PRI */
#if defined(EE_PPCE200ZX_201_ISR_PRI)
  EE_spc574k_set_external_priority(201U, EE_PPCE200ZX_201_ISR_PRI);
#endif /* EE_PPCE200ZX_201_ISR_PRI */
#if defined(EE_PPCE200ZX_202_ISR_PRI)
  EE_spc574k_set_external_priority(202U, EE_PPCE200ZX_202_ISR_PRI);
#endif /* EE_PPCE200ZX_202_ISR_PRI */
#if defined(EE_PPCE200ZX_203_ISR_PRI)
  EE_spc574k_set_external_priority(203U, EE_PPCE200ZX_203_ISR_PRI);
#endif /* EE_PPCE200ZX_203_ISR_PRI */
#if defined(EE_PPCE200ZX_204_ISR_PRI)
  EE_spc574k_set_external_priority(204U, EE_PPCE200ZX_204_ISR_PRI);
#endif /* EE_PPCE200ZX_204_ISR_PRI */
#if defined(EE_PPCE200ZX_205_ISR_PRI)
  EE_spc574k_set_external_priority(205U, EE_PPCE200ZX_205_ISR_PRI);
#endif /* EE_PPCE200ZX_205_ISR_PRI */
#if defined(EE_PPCE200ZX_206_ISR_PRI)
  EE_spc574k_set_external_priority(206U, EE_PPCE200ZX_206_ISR_PRI);
#endif /* EE_PPCE200ZX_206_ISR_PRI */
#if defined(EE_PPCE200ZX_207_ISR_PRI)
  EE_spc574k_set_external_priority(207U, EE_PPCE200ZX_207_ISR_PRI);
#endif /* EE_PPCE200ZX_207_ISR_PRI */
#if defined(EE_PPCE200ZX_208_ISR_PRI)
  EE_spc574k_set_external_priority(208U, EE_PPCE200ZX_208_ISR_PRI);
#endif /* EE_PPCE200ZX_208_ISR_PRI */
#if defined(EE_PPCE200ZX_209_ISR_PRI)
  EE_spc574k_set_external_priority(209U, EE_PPCE200ZX_209_ISR_PRI);
#endif /* EE_PPCE200ZX_209_ISR_PRI */
#if defined(EE_PPCE200ZX_210_ISR_PRI)
  EE_spc574k_set_external_priority(210U, EE_PPCE200ZX_210_ISR_PRI);
#endif /* EE_PPCE200ZX_210_ISR_PRI */
#if defined(EE_PPCE200ZX_211_ISR_PRI)
  EE_spc574k_set_external_priority(211U, EE_PPCE200ZX_211_ISR_PRI);
#endif /* EE_PPCE200ZX_211_ISR_PRI */
#if defined(EE_PPCE200ZX_212_ISR_PRI)
  EE_spc574k_set_external_priority(212U, EE_PPCE200ZX_212_ISR_PRI);
#endif /* EE_PPCE200ZX_212_ISR_PRI */
#if defined(EE_PPCE200ZX_213_ISR_PRI)
  EE_spc574k_set_external_priority(213U, EE_PPCE200ZX_213_ISR_PRI);
#endif /* EE_PPCE200ZX_213_ISR_PRI */
#if defined(EE_PPCE200ZX_214_ISR_PRI)
  EE_spc574k_set_external_priority(214U, EE_PPCE200ZX_214_ISR_PRI);
#endif /* EE_PPCE200ZX_214_ISR_PRI */
#if defined(EE_PPCE200ZX_215_ISR_PRI)
  EE_spc574k_set_external_priority(215U, EE_PPCE200ZX_215_ISR_PRI);
#endif /* EE_PPCE200ZX_215_ISR_PRI */
#if defined(EE_PPCE200ZX_216_ISR_PRI)
  EE_spc574k_set_external_priority(216U, EE_PPCE200ZX_216_ISR_PRI);
#endif /* EE_PPCE200ZX_216_ISR_PRI */
#if defined(EE_PPCE200ZX_217_ISR_PRI)
  EE_spc574k_set_external_priority(217U, EE_PPCE200ZX_217_ISR_PRI);
#endif /* EE_PPCE200ZX_217_ISR_PRI */
#if defined(EE_PPCE200ZX_218_ISR_PRI)
  EE_spc574k_set_external_priority(218U, EE_PPCE200ZX_218_ISR_PRI);
#endif /* EE_PPCE200ZX_218_ISR_PRI */
#if defined(EE_PPCE200ZX_219_ISR_PRI)
  EE_spc574k_set_external_priority(219U, EE_PPCE200ZX_219_ISR_PRI);
#endif /* EE_PPCE200ZX_219_ISR_PRI */
#if defined(EE_PPCE200ZX_220_ISR_PRI)
  EE_spc574k_set_external_priority(220U, EE_PPCE200ZX_220_ISR_PRI);
#endif /* EE_PPCE200ZX_220_ISR_PRI */
#if defined(EE_PPCE200ZX_221_ISR_PRI)
  EE_spc574k_set_external_priority(221U, EE_PPCE200ZX_221_ISR_PRI);
#endif /* EE_PPCE200ZX_221_ISR_PRI */
#if defined(EE_PPCE200ZX_222_ISR_PRI)
  EE_spc574k_set_external_priority(222U, EE_PPCE200ZX_222_ISR_PRI);
#endif /* EE_PPCE200ZX_222_ISR_PRI */
#if defined(EE_PPCE200ZX_223_ISR_PRI)
  EE_spc574k_set_external_priority(223U, EE_PPCE200ZX_223_ISR_PRI);
#endif /* EE_PPCE200ZX_223_ISR_PRI */
#if defined(EE_PPCE200ZX_224_ISR_PRI)
  EE_spc574k_set_external_priority(224U, EE_PPCE200ZX_224_ISR_PRI);
#endif /* EE_PPCE200ZX_224_ISR_PRI */
#if defined(EE_PPCE200ZX_225_ISR_PRI)
  EE_spc574k_set_external_priority(225U, EE_PPCE200ZX_225_ISR_PRI);
#endif /* EE_PPCE200ZX_225_ISR_PRI */
#if defined(EE_PPCE200ZX_226_ISR_PRI)
  EE_spc574k_set_external_priority(226U, EE_PPCE200ZX_226_ISR_PRI);
#endif /* EE_PPCE200ZX_226_ISR_PRI */
#if defined(EE_PPCE200ZX_227_ISR_PRI)
  EE_spc574k_set_external_priority(227U, EE_PPCE200ZX_227_ISR_PRI);
#endif /* EE_PPCE200ZX_227_ISR_PRI */
#if defined(EE_PPCE200ZX_228_ISR_PRI)
  EE_spc574k_set_external_priority(228U, EE_PPCE200ZX_228_ISR_PRI);
#endif /* EE_PPCE200ZX_228_ISR_PRI */
#if defined(EE_PPCE200ZX_229_ISR_PRI)
  EE_spc574k_set_external_priority(229U, EE_PPCE200ZX_229_ISR_PRI);
#endif /* EE_PPCE200ZX_229_ISR_PRI */
#if defined(EE_PPCE200ZX_230_ISR_PRI)
  EE_spc574k_set_external_priority(230U, EE_PPCE200ZX_230_ISR_PRI);
#endif /* EE_PPCE200ZX_230_ISR_PRI */
#if defined(EE_PPCE200ZX_231_ISR_PRI)
  EE_spc574k_set_external_priority(231U, EE_PPCE200ZX_231_ISR_PRI);
#endif /* EE_PPCE200ZX_231_ISR_PRI */
#if defined(EE_PPCE200ZX_232_ISR_PRI)
  EE_spc574k_set_external_priority(232U, EE_PPCE200ZX_232_ISR_PRI);
#endif /* EE_PPCE200ZX_232_ISR_PRI */
#if defined(EE_PPCE200ZX_233_ISR_PRI)
  EE_spc574k_set_external_priority(233U, EE_PPCE200ZX_233_ISR_PRI);
#endif /* EE_PPCE200ZX_233_ISR_PRI */
#if defined(EE_PPCE200ZX_234_ISR_PRI)
  EE_spc574k_set_external_priority(234U, EE_PPCE200ZX_234_ISR_PRI);
#endif /* EE_PPCE200ZX_234_ISR_PRI */
#if defined(EE_PPCE200ZX_235_ISR_PRI)
  EE_spc574k_set_external_priority(235U, EE_PPCE200ZX_235_ISR_PRI);
#endif /* EE_PPCE200ZX_235_ISR_PRI */
#if defined(EE_PPCE200ZX_236_ISR_PRI)
  EE_spc574k_set_external_priority(236U, EE_PPCE200ZX_236_ISR_PRI);
#endif /* EE_PPCE200ZX_236_ISR_PRI */
#if defined(EE_PPCE200ZX_237_ISR_PRI)
  EE_spc574k_set_external_priority(237U, EE_PPCE200ZX_237_ISR_PRI);
#endif /* EE_PPCE200ZX_237_ISR_PRI */
#if defined(EE_PPCE200ZX_238_ISR_PRI)
  EE_spc574k_set_external_priority(238U, EE_PPCE200ZX_238_ISR_PRI);
#endif /* EE_PPCE200ZX_238_ISR_PRI */
#if defined(EE_PPCE200ZX_239_ISR_PRI)
  EE_spc574k_set_external_priority(239U, EE_PPCE200ZX_239_ISR_PRI);
#endif /* EE_PPCE200ZX_239_ISR_PRI */
#if defined(EE_PPCE200ZX_240_ISR_PRI)
  EE_spc574k_set_external_priority(240U, EE_PPCE200ZX_240_ISR_PRI);
#endif /* EE_PPCE200ZX_240_ISR_PRI */
#if defined(EE_PPCE200ZX_241_ISR_PRI)
  EE_spc574k_set_external_priority(241U, EE_PPCE200ZX_241_ISR_PRI);
#endif /* EE_PPCE200ZX_241_ISR_PRI */
#if defined(EE_PPCE200ZX_242_ISR_PRI)
  EE_spc574k_set_external_priority(242U, EE_PPCE200ZX_242_ISR_PRI);
#endif /* EE_PPCE200ZX_242_ISR_PRI */
#if defined(EE_PPCE200ZX_243_ISR_PRI)
  EE_spc574k_set_external_priority(243U, EE_PPCE200ZX_243_ISR_PRI);
#endif /* EE_PPCE200ZX_243_ISR_PRI */
#if defined(EE_PPCE200ZX_244_ISR_PRI)
  EE_spc574k_set_external_priority(244U, EE_PPCE200ZX_244_ISR_PRI);
#endif /* EE_PPCE200ZX_244_ISR_PRI */
#if defined(EE_PPCE200ZX_245_ISR_PRI)
  EE_spc574k_set_external_priority(245U, EE_PPCE200ZX_245_ISR_PRI);
#endif /* EE_PPCE200ZX_245_ISR_PRI */
#if defined(EE_PPCE200ZX_246_ISR_PRI)
  EE_spc574k_set_external_priority(246U, EE_PPCE200ZX_246_ISR_PRI);
#endif /* EE_PPCE200ZX_246_ISR_PRI */
#if defined(EE_PPCE200ZX_247_ISR_PRI)
  EE_spc574k_set_external_priority(247U, EE_PPCE200ZX_247_ISR_PRI);
#endif /* EE_PPCE200ZX_247_ISR_PRI */
#if defined(EE_PPCE200ZX_248_ISR_PRI)
  EE_spc574k_set_external_priority(248U, EE_PPCE200ZX_248_ISR_PRI);
#endif /* EE_PPCE200ZX_248_ISR_PRI */
#if defined(EE_PPCE200ZX_249_ISR_PRI)
  EE_spc574k_set_external_priority(249U, EE_PPCE200ZX_249_ISR_PRI);
#endif /* EE_PPCE200ZX_249_ISR_PRI */
#if defined(EE_PPCE200ZX_250_ISR_PRI)
  EE_spc574k_set_external_priority(250U, EE_PPCE200ZX_250_ISR_PRI);
#endif /* EE_PPCE200ZX_250_ISR_PRI */
#if defined(EE_PPCE200ZX_251_ISR_PRI)
  EE_spc574k_set_external_priority(251U, EE_PPCE200ZX_251_ISR_PRI);
#endif /* EE_PPCE200ZX_251_ISR_PRI */
#if defined(EE_PPCE200ZX_252_ISR_PRI)
  EE_spc574k_set_external_priority(252U, EE_PPCE200ZX_252_ISR_PRI);
#endif /* EE_PPCE200ZX_252_ISR_PRI */
#if defined(EE_PPCE200ZX_253_ISR_PRI)
  EE_spc574k_set_external_priority(253U, EE_PPCE200ZX_253_ISR_PRI);
#endif /* EE_PPCE200ZX_253_ISR_PRI */
#if defined(EE_PPCE200ZX_254_ISR_PRI)
  EE_spc574k_set_external_priority(254U, EE_PPCE200ZX_254_ISR_PRI);
#endif /* EE_PPCE200ZX_254_ISR_PRI */
#if defined(EE_PPCE200ZX_255_ISR_PRI)
  EE_spc574k_set_external_priority(255U, EE_PPCE200ZX_255_ISR_PRI);
#endif /* EE_PPCE200ZX_255_ISR_PRI */
#if defined(EE_PPCE200ZX_256_ISR_PRI)
  EE_spc574k_set_external_priority(256U, EE_PPCE200ZX_256_ISR_PRI);
#endif /* EE_PPCE200ZX_256_ISR_PRI */
#if defined(EE_PPCE200ZX_257_ISR_PRI)
  EE_spc574k_set_external_priority(257U, EE_PPCE200ZX_257_ISR_PRI);
#endif /* EE_PPCE200ZX_257_ISR_PRI */
#if defined(EE_PPCE200ZX_258_ISR_PRI)
  EE_spc574k_set_external_priority(258U, EE_PPCE200ZX_258_ISR_PRI);
#endif /* EE_PPCE200ZX_258_ISR_PRI */
#if defined(EE_PPCE200ZX_259_ISR_PRI)
  EE_spc574k_set_external_priority(259U, EE_PPCE200ZX_259_ISR_PRI);
#endif /* EE_PPCE200ZX_259_ISR_PRI */
#if defined(EE_PPCE200ZX_260_ISR_PRI)
  EE_spc574k_set_external_priority(260U, EE_PPCE200ZX_260_ISR_PRI);
#endif /* EE_PPCE200ZX_260_ISR_PRI */
#if defined(EE_PPCE200ZX_261_ISR_PRI)
  EE_spc574k_set_external_priority(261U, EE_PPCE200ZX_261_ISR_PRI);
#endif /* EE_PPCE200ZX_261_ISR_PRI */
#if defined(EE_PPCE200ZX_262_ISR_PRI)
  EE_spc574k_set_external_priority(262U, EE_PPCE200ZX_262_ISR_PRI);
#endif /* EE_PPCE200ZX_262_ISR_PRI */
#if defined(EE_PPCE200ZX_263_ISR_PRI)
  EE_spc574k_set_external_priority(263U, EE_PPCE200ZX_263_ISR_PRI);
#endif /* EE_PPCE200ZX_263_ISR_PRI */
#if defined(EE_PPCE200ZX_264_ISR_PRI)
  EE_spc574k_set_external_priority(264U, EE_PPCE200ZX_264_ISR_PRI);
#endif /* EE_PPCE200ZX_264_ISR_PRI */
#if defined(EE_PPCE200ZX_265_ISR_PRI)
  EE_spc574k_set_external_priority(265U, EE_PPCE200ZX_265_ISR_PRI);
#endif /* EE_PPCE200ZX_265_ISR_PRI */
#if defined(EE_PPCE200ZX_266_ISR_PRI)
  EE_spc574k_set_external_priority(266U, EE_PPCE200ZX_266_ISR_PRI);
#endif /* EE_PPCE200ZX_266_ISR_PRI */
#if defined(EE_PPCE200ZX_267_ISR_PRI)
  EE_spc574k_set_external_priority(267U, EE_PPCE200ZX_267_ISR_PRI);
#endif /* EE_PPCE200ZX_267_ISR_PRI */
#if defined(EE_PPCE200ZX_268_ISR_PRI)
  EE_spc574k_set_external_priority(268U, EE_PPCE200ZX_268_ISR_PRI);
#endif /* EE_PPCE200ZX_268_ISR_PRI */
#if defined(EE_PPCE200ZX_269_ISR_PRI)
  EE_spc574k_set_external_priority(269U, EE_PPCE200ZX_269_ISR_PRI);
#endif /* EE_PPCE200ZX_269_ISR_PRI */
#if defined(EE_PPCE200ZX_270_ISR_PRI)
  EE_spc574k_set_external_priority(270U, EE_PPCE200ZX_270_ISR_PRI);
#endif /* EE_PPCE200ZX_270_ISR_PRI */
#if defined(EE_PPCE200ZX_271_ISR_PRI)
  EE_spc574k_set_external_priority(271U, EE_PPCE200ZX_271_ISR_PRI);
#endif /* EE_PPCE200ZX_271_ISR_PRI */
#if defined(EE_PPCE200ZX_272_ISR_PRI)
  EE_spc574k_set_external_priority(272U, EE_PPCE200ZX_272_ISR_PRI);
#endif /* EE_PPCE200ZX_272_ISR_PRI */
#if defined(EE_PPCE200ZX_273_ISR_PRI)
  EE_spc574k_set_external_priority(273U, EE_PPCE200ZX_273_ISR_PRI);
#endif /* EE_PPCE200ZX_273_ISR_PRI */
#if defined(EE_PPCE200ZX_274_ISR_PRI)
  EE_spc574k_set_external_priority(274U, EE_PPCE200ZX_274_ISR_PRI);
#endif /* EE_PPCE200ZX_274_ISR_PRI */
#if defined(EE_PPCE200ZX_275_ISR_PRI)
  EE_spc574k_set_external_priority(275U, EE_PPCE200ZX_275_ISR_PRI);
#endif /* EE_PPCE200ZX_275_ISR_PRI */
#if defined(EE_PPCE200ZX_276_ISR_PRI)
  EE_spc574k_set_external_priority(276U, EE_PPCE200ZX_276_ISR_PRI);
#endif /* EE_PPCE200ZX_276_ISR_PRI */
#if defined(EE_PPCE200ZX_277_ISR_PRI)
  EE_spc574k_set_external_priority(277U, EE_PPCE200ZX_277_ISR_PRI);
#endif /* EE_PPCE200ZX_277_ISR_PRI */
#if defined(EE_PPCE200ZX_278_ISR_PRI)
  EE_spc574k_set_external_priority(278U, EE_PPCE200ZX_278_ISR_PRI);
#endif /* EE_PPCE200ZX_278_ISR_PRI */
#if defined(EE_PPCE200ZX_279_ISR_PRI)
  EE_spc574k_set_external_priority(279U, EE_PPCE200ZX_279_ISR_PRI);
#endif /* EE_PPCE200ZX_279_ISR_PRI */
#if defined(EE_PPCE200ZX_280_ISR_PRI)
  EE_spc574k_set_external_priority(280U, EE_PPCE200ZX_280_ISR_PRI);
#endif /* EE_PPCE200ZX_280_ISR_PRI */
#if defined(EE_PPCE200ZX_281_ISR_PRI)
  EE_spc574k_set_external_priority(281U, EE_PPCE200ZX_281_ISR_PRI);
#endif /* EE_PPCE200ZX_281_ISR_PRI */
#if defined(EE_PPCE200ZX_282_ISR_PRI)
  EE_spc574k_set_external_priority(282U, EE_PPCE200ZX_282_ISR_PRI);
#endif /* EE_PPCE200ZX_282_ISR_PRI */
#if defined(EE_PPCE200ZX_283_ISR_PRI)
  EE_spc574k_set_external_priority(283U, EE_PPCE200ZX_283_ISR_PRI);
#endif /* EE_PPCE200ZX_283_ISR_PRI */
#if defined(EE_PPCE200ZX_284_ISR_PRI)
  EE_spc574k_set_external_priority(284U, EE_PPCE200ZX_284_ISR_PRI);
#endif /* EE_PPCE200ZX_284_ISR_PRI */
#if defined(EE_PPCE200ZX_285_ISR_PRI)
  EE_spc574k_set_external_priority(285U, EE_PPCE200ZX_285_ISR_PRI);
#endif /* EE_PPCE200ZX_285_ISR_PRI */
#if defined(EE_PPCE200ZX_286_ISR_PRI)
  EE_spc574k_set_external_priority(286U, EE_PPCE200ZX_286_ISR_PRI);
#endif /* EE_PPCE200ZX_286_ISR_PRI */
#if defined(EE_PPCE200ZX_287_ISR_PRI)
  EE_spc574k_set_external_priority(287U, EE_PPCE200ZX_287_ISR_PRI);
#endif /* EE_PPCE200ZX_287_ISR_PRI */
#if defined(EE_PPCE200ZX_288_ISR_PRI)
  EE_spc574k_set_external_priority(288U, EE_PPCE200ZX_288_ISR_PRI);
#endif /* EE_PPCE200ZX_288_ISR_PRI */
#if defined(EE_PPCE200ZX_289_ISR_PRI)
  EE_spc574k_set_external_priority(289U, EE_PPCE200ZX_289_ISR_PRI);
#endif /* EE_PPCE200ZX_289_ISR_PRI */
#if defined(EE_PPCE200ZX_290_ISR_PRI)
  EE_spc574k_set_external_priority(290U, EE_PPCE200ZX_290_ISR_PRI);
#endif /* EE_PPCE200ZX_290_ISR_PRI */
#if defined(EE_PPCE200ZX_291_ISR_PRI)
  EE_spc574k_set_external_priority(291U, EE_PPCE200ZX_291_ISR_PRI);
#endif /* EE_PPCE200ZX_291_ISR_PRI */
#if defined(EE_PPCE200ZX_292_ISR_PRI)
  EE_spc574k_set_external_priority(292U, EE_PPCE200ZX_292_ISR_PRI);
#endif /* EE_PPCE200ZX_292_ISR_PRI */
#if defined(EE_PPCE200ZX_293_ISR_PRI)
  EE_spc574k_set_external_priority(293U, EE_PPCE200ZX_293_ISR_PRI);
#endif /* EE_PPCE200ZX_293_ISR_PRI */
#if defined(EE_PPCE200ZX_294_ISR_PRI)
  EE_spc574k_set_external_priority(294U, EE_PPCE200ZX_294_ISR_PRI);
#endif /* EE_PPCE200ZX_294_ISR_PRI */
#if defined(EE_PPCE200ZX_295_ISR_PRI)
  EE_spc574k_set_external_priority(295U, EE_PPCE200ZX_295_ISR_PRI);
#endif /* EE_PPCE200ZX_295_ISR_PRI */
#if defined(EE_PPCE200ZX_296_ISR_PRI)
  EE_spc574k_set_external_priority(296U, EE_PPCE200ZX_296_ISR_PRI);
#endif /* EE_PPCE200ZX_296_ISR_PRI */
#if defined(EE_PPCE200ZX_297_ISR_PRI)
  EE_spc574k_set_external_priority(297U, EE_PPCE200ZX_297_ISR_PRI);
#endif /* EE_PPCE200ZX_297_ISR_PRI */
#if defined(EE_PPCE200ZX_298_ISR_PRI)
  EE_spc574k_set_external_priority(298U, EE_PPCE200ZX_298_ISR_PRI);
#endif /* EE_PPCE200ZX_298_ISR_PRI */
#if defined(EE_PPCE200ZX_299_ISR_PRI)
  EE_spc574k_set_external_priority(299U, EE_PPCE200ZX_299_ISR_PRI);
#endif /* EE_PPCE200ZX_299_ISR_PRI */
#if defined(EE_PPCE200ZX_300_ISR_PRI)
  EE_spc574k_set_external_priority(300U, EE_PPCE200ZX_300_ISR_PRI);
#endif /* EE_PPCE200ZX_300_ISR_PRI */
#if defined(EE_PPCE200ZX_301_ISR_PRI)
  EE_spc574k_set_external_priority(301U, EE_PPCE200ZX_301_ISR_PRI);
#endif /* EE_PPCE200ZX_301_ISR_PRI */
#if defined(EE_PPCE200ZX_302_ISR_PRI)
  EE_spc574k_set_external_priority(302U, EE_PPCE200ZX_302_ISR_PRI);
#endif /* EE_PPCE200ZX_302_ISR_PRI */
#if defined(EE_PPCE200ZX_303_ISR_PRI)
  EE_spc574k_set_external_priority(303U, EE_PPCE200ZX_303_ISR_PRI);
#endif /* EE_PPCE200ZX_303_ISR_PRI */
#if defined(EE_PPCE200ZX_304_ISR_PRI)
  EE_spc574k_set_external_priority(304U, EE_PPCE200ZX_304_ISR_PRI);
#endif /* EE_PPCE200ZX_304_ISR_PRI */
#if defined(EE_PPCE200ZX_305_ISR_PRI)
  EE_spc574k_set_external_priority(305U, EE_PPCE200ZX_305_ISR_PRI);
#endif /* EE_PPCE200ZX_305_ISR_PRI */
#if defined(EE_PPCE200ZX_306_ISR_PRI)
  EE_spc574k_set_external_priority(306U, EE_PPCE200ZX_306_ISR_PRI);
#endif /* EE_PPCE200ZX_306_ISR_PRI */
#if defined(EE_PPCE200ZX_307_ISR_PRI)
  EE_spc574k_set_external_priority(307U, EE_PPCE200ZX_307_ISR_PRI);
#endif /* EE_PPCE200ZX_307_ISR_PRI */
#if defined(EE_PPCE200ZX_308_ISR_PRI)
  EE_spc574k_set_external_priority(308U, EE_PPCE200ZX_308_ISR_PRI);
#endif /* EE_PPCE200ZX_308_ISR_PRI */
#if defined(EE_PPCE200ZX_309_ISR_PRI)
  EE_spc574k_set_external_priority(309U, EE_PPCE200ZX_309_ISR_PRI);
#endif /* EE_PPCE200ZX_309_ISR_PRI */
#if defined(EE_PPCE200ZX_310_ISR_PRI)
  EE_spc574k_set_external_priority(310U, EE_PPCE200ZX_310_ISR_PRI);
#endif /* EE_PPCE200ZX_310_ISR_PRI */
#if defined(EE_PPCE200ZX_311_ISR_PRI)
  EE_spc574k_set_external_priority(311U, EE_PPCE200ZX_311_ISR_PRI);
#endif /* EE_PPCE200ZX_311_ISR_PRI */
#if defined(EE_PPCE200ZX_312_ISR_PRI)
  EE_spc574k_set_external_priority(312U, EE_PPCE200ZX_312_ISR_PRI);
#endif /* EE_PPCE200ZX_312_ISR_PRI */
#if defined(EE_PPCE200ZX_313_ISR_PRI)
  EE_spc574k_set_external_priority(313U, EE_PPCE200ZX_313_ISR_PRI);
#endif /* EE_PPCE200ZX_313_ISR_PRI */
#if defined(EE_PPCE200ZX_314_ISR_PRI)
  EE_spc574k_set_external_priority(314U, EE_PPCE200ZX_314_ISR_PRI);
#endif /* EE_PPCE200ZX_314_ISR_PRI */
#if defined(EE_PPCE200ZX_315_ISR_PRI)
  EE_spc574k_set_external_priority(315U, EE_PPCE200ZX_315_ISR_PRI);
#endif /* EE_PPCE200ZX_315_ISR_PRI */
#if defined(EE_PPCE200ZX_316_ISR_PRI)
  EE_spc574k_set_external_priority(316U, EE_PPCE200ZX_316_ISR_PRI);
#endif /* EE_PPCE200ZX_316_ISR_PRI */
#if defined(EE_PPCE200ZX_317_ISR_PRI)
  EE_spc574k_set_external_priority(317U, EE_PPCE200ZX_317_ISR_PRI);
#endif /* EE_PPCE200ZX_317_ISR_PRI */
#if defined(EE_PPCE200ZX_318_ISR_PRI)
  EE_spc574k_set_external_priority(318U, EE_PPCE200ZX_318_ISR_PRI);
#endif /* EE_PPCE200ZX_318_ISR_PRI */
#if defined(EE_PPCE200ZX_319_ISR_PRI)
  EE_spc574k_set_external_priority(319U, EE_PPCE200ZX_319_ISR_PRI);
#endif /* EE_PPCE200ZX_319_ISR_PRI */
#if defined(EE_PPCE200ZX_320_ISR_PRI)
  EE_spc574k_set_external_priority(320U, EE_PPCE200ZX_320_ISR_PRI);
#endif /* EE_PPCE200ZX_320_ISR_PRI */
#if defined(EE_PPCE200ZX_321_ISR_PRI)
  EE_spc574k_set_external_priority(321U, EE_PPCE200ZX_321_ISR_PRI);
#endif /* EE_PPCE200ZX_321_ISR_PRI */
#if defined(EE_PPCE200ZX_322_ISR_PRI)
  EE_spc574k_set_external_priority(322U, EE_PPCE200ZX_322_ISR_PRI);
#endif /* EE_PPCE200ZX_322_ISR_PRI */
#if defined(EE_PPCE200ZX_323_ISR_PRI)
  EE_spc574k_set_external_priority(323U, EE_PPCE200ZX_323_ISR_PRI);
#endif /* EE_PPCE200ZX_323_ISR_PRI */
#if defined(EE_PPCE200ZX_324_ISR_PRI)
  EE_spc574k_set_external_priority(324U, EE_PPCE200ZX_324_ISR_PRI);
#endif /* EE_PPCE200ZX_324_ISR_PRI */
#if defined(EE_PPCE200ZX_325_ISR_PRI)
  EE_spc574k_set_external_priority(325U, EE_PPCE200ZX_325_ISR_PRI);
#endif /* EE_PPCE200ZX_325_ISR_PRI */
#if defined(EE_PPCE200ZX_326_ISR_PRI)
  EE_spc574k_set_external_priority(326U, EE_PPCE200ZX_326_ISR_PRI);
#endif /* EE_PPCE200ZX_326_ISR_PRI */
#if defined(EE_PPCE200ZX_327_ISR_PRI)
  EE_spc574k_set_external_priority(327U, EE_PPCE200ZX_327_ISR_PRI);
#endif /* EE_PPCE200ZX_327_ISR_PRI */
#if defined(EE_PPCE200ZX_328_ISR_PRI)
  EE_spc574k_set_external_priority(328U, EE_PPCE200ZX_328_ISR_PRI);
#endif /* EE_PPCE200ZX_328_ISR_PRI */
#if defined(EE_PPCE200ZX_329_ISR_PRI)
  EE_spc574k_set_external_priority(329U, EE_PPCE200ZX_329_ISR_PRI);
#endif /* EE_PPCE200ZX_329_ISR_PRI */
#if defined(EE_PPCE200ZX_330_ISR_PRI)
  EE_spc574k_set_external_priority(330U, EE_PPCE200ZX_330_ISR_PRI);
#endif /* EE_PPCE200ZX_330_ISR_PRI */
#if defined(EE_PPCE200ZX_331_ISR_PRI)
  EE_spc574k_set_external_priority(331U, EE_PPCE200ZX_331_ISR_PRI);
#endif /* EE_PPCE200ZX_331_ISR_PRI */
#if defined(EE_PPCE200ZX_332_ISR_PRI)
  EE_spc574k_set_external_priority(332U, EE_PPCE200ZX_332_ISR_PRI);
#endif /* EE_PPCE200ZX_332_ISR_PRI */
#if defined(EE_PPCE200ZX_333_ISR_PRI)
  EE_spc574k_set_external_priority(333U, EE_PPCE200ZX_333_ISR_PRI);
#endif /* EE_PPCE200ZX_333_ISR_PRI */
#if defined(EE_PPCE200ZX_334_ISR_PRI)
  EE_spc574k_set_external_priority(334U, EE_PPCE200ZX_334_ISR_PRI);
#endif /* EE_PPCE200ZX_334_ISR_PRI */
#if defined(EE_PPCE200ZX_335_ISR_PRI)
  EE_spc574k_set_external_priority(335U, EE_PPCE200ZX_335_ISR_PRI);
#endif /* EE_PPCE200ZX_335_ISR_PRI */
#if defined(EE_PPCE200ZX_336_ISR_PRI)
  EE_spc574k_set_external_priority(336U, EE_PPCE200ZX_336_ISR_PRI);
#endif /* EE_PPCE200ZX_336_ISR_PRI */
#if defined(EE_PPCE200ZX_337_ISR_PRI)
  EE_spc574k_set_external_priority(337U, EE_PPCE200ZX_337_ISR_PRI);
#endif /* EE_PPCE200ZX_337_ISR_PRI */
#if defined(EE_PPCE200ZX_338_ISR_PRI)
  EE_spc574k_set_external_priority(338U, EE_PPCE200ZX_338_ISR_PRI);
#endif /* EE_PPCE200ZX_338_ISR_PRI */
#if defined(EE_PPCE200ZX_339_ISR_PRI)
  EE_spc574k_set_external_priority(339U, EE_PPCE200ZX_339_ISR_PRI);
#endif /* EE_PPCE200ZX_339_ISR_PRI */
#if defined(EE_PPCE200ZX_340_ISR_PRI)
  EE_spc574k_set_external_priority(340U, EE_PPCE200ZX_340_ISR_PRI);
#endif /* EE_PPCE200ZX_340_ISR_PRI */
#if defined(EE_PPCE200ZX_341_ISR_PRI)
  EE_spc574k_set_external_priority(341U, EE_PPCE200ZX_341_ISR_PRI);
#endif /* EE_PPCE200ZX_341_ISR_PRI */
#if defined(EE_PPCE200ZX_342_ISR_PRI)
  EE_spc574k_set_external_priority(342U, EE_PPCE200ZX_342_ISR_PRI);
#endif /* EE_PPCE200ZX_342_ISR_PRI */
#if defined(EE_PPCE200ZX_343_ISR_PRI)
  EE_spc574k_set_external_priority(343U, EE_PPCE200ZX_343_ISR_PRI);
#endif /* EE_PPCE200ZX_343_ISR_PRI */
#if defined(EE_PPCE200ZX_344_ISR_PRI)
  EE_spc574k_set_external_priority(344U, EE_PPCE200ZX_344_ISR_PRI);
#endif /* EE_PPCE200ZX_344_ISR_PRI */
#if defined(EE_PPCE200ZX_345_ISR_PRI)
  EE_spc574k_set_external_priority(345U, EE_PPCE200ZX_345_ISR_PRI);
#endif /* EE_PPCE200ZX_345_ISR_PRI */
#if defined(EE_PPCE200ZX_346_ISR_PRI)
  EE_spc574k_set_external_priority(346U, EE_PPCE200ZX_346_ISR_PRI);
#endif /* EE_PPCE200ZX_346_ISR_PRI */
#if defined(EE_PPCE200ZX_347_ISR_PRI)
  EE_spc574k_set_external_priority(347U, EE_PPCE200ZX_347_ISR_PRI);
#endif /* EE_PPCE200ZX_347_ISR_PRI */
#if defined(EE_PPCE200ZX_348_ISR_PRI)
  EE_spc574k_set_external_priority(348U, EE_PPCE200ZX_348_ISR_PRI);
#endif /* EE_PPCE200ZX_348_ISR_PRI */
#if defined(EE_PPCE200ZX_349_ISR_PRI)
  EE_spc574k_set_external_priority(349U, EE_PPCE200ZX_349_ISR_PRI);
#endif /* EE_PPCE200ZX_349_ISR_PRI */
#if defined(EE_PPCE200ZX_350_ISR_PRI)
  EE_spc574k_set_external_priority(350U, EE_PPCE200ZX_350_ISR_PRI);
#endif /* EE_PPCE200ZX_350_ISR_PRI */
#if defined(EE_PPCE200ZX_351_ISR_PRI)
  EE_spc574k_set_external_priority(351U, EE_PPCE200ZX_351_ISR_PRI);
#endif /* EE_PPCE200ZX_351_ISR_PRI */
#if defined(EE_PPCE200ZX_352_ISR_PRI)
  EE_spc574k_set_external_priority(352U, EE_PPCE200ZX_352_ISR_PRI);
#endif /* EE_PPCE200ZX_352_ISR_PRI */
#if defined(EE_PPCE200ZX_353_ISR_PRI)
  EE_spc574k_set_external_priority(353U, EE_PPCE200ZX_353_ISR_PRI);
#endif /* EE_PPCE200ZX_353_ISR_PRI */
#if defined(EE_PPCE200ZX_354_ISR_PRI)
  EE_spc574k_set_external_priority(354U, EE_PPCE200ZX_354_ISR_PRI);
#endif /* EE_PPCE200ZX_354_ISR_PRI */
#if defined(EE_PPCE200ZX_355_ISR_PRI)
  EE_spc574k_set_external_priority(355U, EE_PPCE200ZX_355_ISR_PRI);
#endif /* EE_PPCE200ZX_355_ISR_PRI */
#if defined(EE_PPCE200ZX_356_ISR_PRI)
  EE_spc574k_set_external_priority(356U, EE_PPCE200ZX_356_ISR_PRI);
#endif /* EE_PPCE200ZX_356_ISR_PRI */
#if defined(EE_PPCE200ZX_357_ISR_PRI)
  EE_spc574k_set_external_priority(357U, EE_PPCE200ZX_357_ISR_PRI);
#endif /* EE_PPCE200ZX_357_ISR_PRI */
#if defined(EE_PPCE200ZX_358_ISR_PRI)
  EE_spc574k_set_external_priority(358U, EE_PPCE200ZX_358_ISR_PRI);
#endif /* EE_PPCE200ZX_358_ISR_PRI */
#if defined(EE_PPCE200ZX_359_ISR_PRI)
  EE_spc574k_set_external_priority(359U, EE_PPCE200ZX_359_ISR_PRI);
#endif /* EE_PPCE200ZX_359_ISR_PRI */
#if defined(EE_PPCE200ZX_360_ISR_PRI)
  EE_spc574k_set_external_priority(360U, EE_PPCE200ZX_360_ISR_PRI);
#endif /* EE_PPCE200ZX_360_ISR_PRI */
#if defined(EE_PPCE200ZX_361_ISR_PRI)
  EE_spc574k_set_external_priority(361U, EE_PPCE200ZX_361_ISR_PRI);
#endif /* EE_PPCE200ZX_361_ISR_PRI */
#if defined(EE_PPCE200ZX_362_ISR_PRI)
  EE_spc574k_set_external_priority(362U, EE_PPCE200ZX_362_ISR_PRI);
#endif /* EE_PPCE200ZX_362_ISR_PRI */
#if defined(EE_PPCE200ZX_363_ISR_PRI)
  EE_spc574k_set_external_priority(363U, EE_PPCE200ZX_363_ISR_PRI);
#endif /* EE_PPCE200ZX_363_ISR_PRI */
#if defined(EE_PPCE200ZX_364_ISR_PRI)
  EE_spc574k_set_external_priority(364U, EE_PPCE200ZX_364_ISR_PRI);
#endif /* EE_PPCE200ZX_364_ISR_PRI */
#if defined(EE_PPCE200ZX_365_ISR_PRI)
  EE_spc574k_set_external_priority(365U, EE_PPCE200ZX_365_ISR_PRI);
#endif /* EE_PPCE200ZX_365_ISR_PRI */
#if defined(EE_PPCE200ZX_366_ISR_PRI)
  EE_spc574k_set_external_priority(366U, EE_PPCE200ZX_366_ISR_PRI);
#endif /* EE_PPCE200ZX_366_ISR_PRI */
#if defined(EE_PPCE200ZX_367_ISR_PRI)
  EE_spc574k_set_external_priority(367U, EE_PPCE200ZX_367_ISR_PRI);
#endif /* EE_PPCE200ZX_367_ISR_PRI */
#if defined(EE_PPCE200ZX_368_ISR_PRI)
  EE_spc574k_set_external_priority(368U, EE_PPCE200ZX_368_ISR_PRI);
#endif /* EE_PPCE200ZX_368_ISR_PRI */
#if defined(EE_PPCE200ZX_369_ISR_PRI)
  EE_spc574k_set_external_priority(369U, EE_PPCE200ZX_369_ISR_PRI);
#endif /* EE_PPCE200ZX_369_ISR_PRI */
#if defined(EE_PPCE200ZX_370_ISR_PRI)
  EE_spc574k_set_external_priority(370U, EE_PPCE200ZX_370_ISR_PRI);
#endif /* EE_PPCE200ZX_370_ISR_PRI */
#if defined(EE_PPCE200ZX_371_ISR_PRI)
  EE_spc574k_set_external_priority(371U, EE_PPCE200ZX_371_ISR_PRI);
#endif /* EE_PPCE200ZX_371_ISR_PRI */
#if defined(EE_PPCE200ZX_372_ISR_PRI)
  EE_spc574k_set_external_priority(372U, EE_PPCE200ZX_372_ISR_PRI);
#endif /* EE_PPCE200ZX_372_ISR_PRI */
#if defined(EE_PPCE200ZX_373_ISR_PRI)
  EE_spc574k_set_external_priority(373U, EE_PPCE200ZX_373_ISR_PRI);
#endif /* EE_PPCE200ZX_373_ISR_PRI */
#if defined(EE_PPCE200ZX_374_ISR_PRI)
  EE_spc574k_set_external_priority(374U, EE_PPCE200ZX_374_ISR_PRI);
#endif /* EE_PPCE200ZX_374_ISR_PRI */
#if defined(EE_PPCE200ZX_375_ISR_PRI)
  EE_spc574k_set_external_priority(375U, EE_PPCE200ZX_375_ISR_PRI);
#endif /* EE_PPCE200ZX_375_ISR_PRI */
#if defined(EE_PPCE200ZX_376_ISR_PRI)
  EE_spc574k_set_external_priority(376U, EE_PPCE200ZX_376_ISR_PRI);
#endif /* EE_PPCE200ZX_376_ISR_PRI */
#if defined(EE_PPCE200ZX_377_ISR_PRI)
  EE_spc574k_set_external_priority(377U, EE_PPCE200ZX_377_ISR_PRI);
#endif /* EE_PPCE200ZX_377_ISR_PRI */
#if defined(EE_PPCE200ZX_378_ISR_PRI)
  EE_spc574k_set_external_priority(378U, EE_PPCE200ZX_378_ISR_PRI);
#endif /* EE_PPCE200ZX_378_ISR_PRI */
#if defined(EE_PPCE200ZX_379_ISR_PRI)
  EE_spc574k_set_external_priority(379U, EE_PPCE200ZX_379_ISR_PRI);
#endif /* EE_PPCE200ZX_379_ISR_PRI */
#if defined(EE_PPCE200ZX_380_ISR_PRI)
  EE_spc574k_set_external_priority(380U, EE_PPCE200ZX_380_ISR_PRI);
#endif /* EE_PPCE200ZX_380_ISR_PRI */
#if defined(EE_PPCE200ZX_381_ISR_PRI)
  EE_spc574k_set_external_priority(381U, EE_PPCE200ZX_381_ISR_PRI);
#endif /* EE_PPCE200ZX_381_ISR_PRI */
#if defined(EE_PPCE200ZX_382_ISR_PRI)
  EE_spc574k_set_external_priority(382U, EE_PPCE200ZX_382_ISR_PRI);
#endif /* EE_PPCE200ZX_382_ISR_PRI */
#if defined(EE_PPCE200ZX_383_ISR_PRI)
  EE_spc574k_set_external_priority(383U, EE_PPCE200ZX_383_ISR_PRI);
#endif /* EE_PPCE200ZX_383_ISR_PRI */
#if defined(EE_PPCE200ZX_384_ISR_PRI)
  EE_spc574k_set_external_priority(384U, EE_PPCE200ZX_384_ISR_PRI);
#endif /* EE_PPCE200ZX_384_ISR_PRI */
#if defined(EE_PPCE200ZX_385_ISR_PRI)
  EE_spc574k_set_external_priority(385U, EE_PPCE200ZX_385_ISR_PRI);
#endif /* EE_PPCE200ZX_385_ISR_PRI */
#if defined(EE_PPCE200ZX_386_ISR_PRI)
  EE_spc574k_set_external_priority(386U, EE_PPCE200ZX_386_ISR_PRI);
#endif /* EE_PPCE200ZX_386_ISR_PRI */
#if defined(EE_PPCE200ZX_387_ISR_PRI)
  EE_spc574k_set_external_priority(387U, EE_PPCE200ZX_387_ISR_PRI);
#endif /* EE_PPCE200ZX_387_ISR_PRI */
#if defined(EE_PPCE200ZX_388_ISR_PRI)
  EE_spc574k_set_external_priority(388U, EE_PPCE200ZX_388_ISR_PRI);
#endif /* EE_PPCE200ZX_388_ISR_PRI */
#if defined(EE_PPCE200ZX_389_ISR_PRI)
  EE_spc574k_set_external_priority(389U, EE_PPCE200ZX_389_ISR_PRI);
#endif /* EE_PPCE200ZX_389_ISR_PRI */
#if defined(EE_PPCE200ZX_390_ISR_PRI)
  EE_spc574k_set_external_priority(390U, EE_PPCE200ZX_390_ISR_PRI);
#endif /* EE_PPCE200ZX_390_ISR_PRI */
#if defined(EE_PPCE200ZX_391_ISR_PRI)
  EE_spc574k_set_external_priority(391U, EE_PPCE200ZX_391_ISR_PRI);
#endif /* EE_PPCE200ZX_391_ISR_PRI */
#if defined(EE_PPCE200ZX_392_ISR_PRI)
  EE_spc574k_set_external_priority(392U, EE_PPCE200ZX_392_ISR_PRI);
#endif /* EE_PPCE200ZX_392_ISR_PRI */
#if defined(EE_PPCE200ZX_393_ISR_PRI)
  EE_spc574k_set_external_priority(393U, EE_PPCE200ZX_393_ISR_PRI);
#endif /* EE_PPCE200ZX_393_ISR_PRI */
#if defined(EE_PPCE200ZX_394_ISR_PRI)
  EE_spc574k_set_external_priority(394U, EE_PPCE200ZX_394_ISR_PRI);
#endif /* EE_PPCE200ZX_394_ISR_PRI */
#if defined(EE_PPCE200ZX_395_ISR_PRI)
  EE_spc574k_set_external_priority(395U, EE_PPCE200ZX_395_ISR_PRI);
#endif /* EE_PPCE200ZX_395_ISR_PRI */
#if defined(EE_PPCE200ZX_396_ISR_PRI)
  EE_spc574k_set_external_priority(396U, EE_PPCE200ZX_396_ISR_PRI);
#endif /* EE_PPCE200ZX_396_ISR_PRI */
#if defined(EE_PPCE200ZX_397_ISR_PRI)
  EE_spc574k_set_external_priority(397U, EE_PPCE200ZX_397_ISR_PRI);
#endif /* EE_PPCE200ZX_397_ISR_PRI */
#if defined(EE_PPCE200ZX_398_ISR_PRI)
  EE_spc574k_set_external_priority(398U, EE_PPCE200ZX_398_ISR_PRI);
#endif /* EE_PPCE200ZX_398_ISR_PRI */
#if defined(EE_PPCE200ZX_399_ISR_PRI)
  EE_spc574k_set_external_priority(399U, EE_PPCE200ZX_399_ISR_PRI);
#endif /* EE_PPCE200ZX_399_ISR_PRI */
#if defined(EE_PPCE200ZX_400_ISR_PRI)
  EE_spc574k_set_external_priority(400U, EE_PPCE200ZX_400_ISR_PRI);
#endif /* EE_PPCE200ZX_400_ISR_PRI */
#if defined(EE_PPCE200ZX_401_ISR_PRI)
  EE_spc574k_set_external_priority(401U, EE_PPCE200ZX_401_ISR_PRI);
#endif /* EE_PPCE200ZX_401_ISR_PRI */
#if defined(EE_PPCE200ZX_402_ISR_PRI)
  EE_spc574k_set_external_priority(402U, EE_PPCE200ZX_402_ISR_PRI);
#endif /* EE_PPCE200ZX_402_ISR_PRI */
#if defined(EE_PPCE200ZX_403_ISR_PRI)
  EE_spc574k_set_external_priority(403U, EE_PPCE200ZX_403_ISR_PRI);
#endif /* EE_PPCE200ZX_403_ISR_PRI */
#if defined(EE_PPCE200ZX_404_ISR_PRI)
  EE_spc574k_set_external_priority(404U, EE_PPCE200ZX_404_ISR_PRI);
#endif /* EE_PPCE200ZX_404_ISR_PRI */
#if defined(EE_PPCE200ZX_405_ISR_PRI)
  EE_spc574k_set_external_priority(405U, EE_PPCE200ZX_405_ISR_PRI);
#endif /* EE_PPCE200ZX_405_ISR_PRI */
#if defined(EE_PPCE200ZX_406_ISR_PRI)
  EE_spc574k_set_external_priority(406U, EE_PPCE200ZX_406_ISR_PRI);
#endif /* EE_PPCE200ZX_406_ISR_PRI */
#if defined(EE_PPCE200ZX_407_ISR_PRI)
  EE_spc574k_set_external_priority(407U, EE_PPCE200ZX_407_ISR_PRI);
#endif /* EE_PPCE200ZX_407_ISR_PRI */
#if defined(EE_PPCE200ZX_408_ISR_PRI)
  EE_spc574k_set_external_priority(408U, EE_PPCE200ZX_408_ISR_PRI);
#endif /* EE_PPCE200ZX_408_ISR_PRI */
#if defined(EE_PPCE200ZX_409_ISR_PRI)
  EE_spc574k_set_external_priority(409U, EE_PPCE200ZX_409_ISR_PRI);
#endif /* EE_PPCE200ZX_409_ISR_PRI */
#if defined(EE_PPCE200ZX_410_ISR_PRI)
  EE_spc574k_set_external_priority(410U, EE_PPCE200ZX_410_ISR_PRI);
#endif /* EE_PPCE200ZX_410_ISR_PRI */
#if defined(EE_PPCE200ZX_411_ISR_PRI)
  EE_spc574k_set_external_priority(411U, EE_PPCE200ZX_411_ISR_PRI);
#endif /* EE_PPCE200ZX_411_ISR_PRI */
#if defined(EE_PPCE200ZX_412_ISR_PRI)
  EE_spc574k_set_external_priority(412U, EE_PPCE200ZX_412_ISR_PRI);
#endif /* EE_PPCE200ZX_412_ISR_PRI */
#if defined(EE_PPCE200ZX_413_ISR_PRI)
  EE_spc574k_set_external_priority(413U, EE_PPCE200ZX_413_ISR_PRI);
#endif /* EE_PPCE200ZX_413_ISR_PRI */
#if defined(EE_PPCE200ZX_414_ISR_PRI)
  EE_spc574k_set_external_priority(414U, EE_PPCE200ZX_414_ISR_PRI);
#endif /* EE_PPCE200ZX_414_ISR_PRI */
#if defined(EE_PPCE200ZX_415_ISR_PRI)
  EE_spc574k_set_external_priority(415U, EE_PPCE200ZX_415_ISR_PRI);
#endif /* EE_PPCE200ZX_415_ISR_PRI */
#if defined(EE_PPCE200ZX_416_ISR_PRI)
  EE_spc574k_set_external_priority(416U, EE_PPCE200ZX_416_ISR_PRI);
#endif /* EE_PPCE200ZX_416_ISR_PRI */
#if defined(EE_PPCE200ZX_417_ISR_PRI)
  EE_spc574k_set_external_priority(417U, EE_PPCE200ZX_417_ISR_PRI);
#endif /* EE_PPCE200ZX_417_ISR_PRI */
#if defined(EE_PPCE200ZX_418_ISR_PRI)
  EE_spc574k_set_external_priority(418U, EE_PPCE200ZX_418_ISR_PRI);
#endif /* EE_PPCE200ZX_418_ISR_PRI */
#if defined(EE_PPCE200ZX_419_ISR_PRI)
  EE_spc574k_set_external_priority(419U, EE_PPCE200ZX_419_ISR_PRI);
#endif /* EE_PPCE200ZX_419_ISR_PRI */
#if defined(EE_PPCE200ZX_420_ISR_PRI)
  EE_spc574k_set_external_priority(420U, EE_PPCE200ZX_420_ISR_PRI);
#endif /* EE_PPCE200ZX_420_ISR_PRI */
#if defined(EE_PPCE200ZX_421_ISR_PRI)
  EE_spc574k_set_external_priority(421U, EE_PPCE200ZX_421_ISR_PRI);
#endif /* EE_PPCE200ZX_421_ISR_PRI */
#if defined(EE_PPCE200ZX_422_ISR_PRI)
  EE_spc574k_set_external_priority(422U, EE_PPCE200ZX_422_ISR_PRI);
#endif /* EE_PPCE200ZX_422_ISR_PRI */
#if defined(EE_PPCE200ZX_423_ISR_PRI)
  EE_spc574k_set_external_priority(423U, EE_PPCE200ZX_423_ISR_PRI);
#endif /* EE_PPCE200ZX_423_ISR_PRI */
#if defined(EE_PPCE200ZX_424_ISR_PRI)
  EE_spc574k_set_external_priority(424U, EE_PPCE200ZX_424_ISR_PRI);
#endif /* EE_PPCE200ZX_424_ISR_PRI */
#if defined(EE_PPCE200ZX_425_ISR_PRI)
  EE_spc574k_set_external_priority(425U, EE_PPCE200ZX_425_ISR_PRI);
#endif /* EE_PPCE200ZX_425_ISR_PRI */
#if defined(EE_PPCE200ZX_426_ISR_PRI)
  EE_spc574k_set_external_priority(426U, EE_PPCE200ZX_426_ISR_PRI);
#endif /* EE_PPCE200ZX_426_ISR_PRI */
#if defined(EE_PPCE200ZX_427_ISR_PRI)
  EE_spc574k_set_external_priority(427U, EE_PPCE200ZX_427_ISR_PRI);
#endif /* EE_PPCE200ZX_427_ISR_PRI */
#if defined(EE_PPCE200ZX_428_ISR_PRI)
  EE_spc574k_set_external_priority(428U, EE_PPCE200ZX_428_ISR_PRI);
#endif /* EE_PPCE200ZX_428_ISR_PRI */
#if defined(EE_PPCE200ZX_429_ISR_PRI)
  EE_spc574k_set_external_priority(429U, EE_PPCE200ZX_429_ISR_PRI);
#endif /* EE_PPCE200ZX_429_ISR_PRI */
#if defined(EE_PPCE200ZX_430_ISR_PRI)
  EE_spc574k_set_external_priority(430U, EE_PPCE200ZX_430_ISR_PRI);
#endif /* EE_PPCE200ZX_430_ISR_PRI */
#if defined(EE_PPCE200ZX_431_ISR_PRI)
  EE_spc574k_set_external_priority(431U, EE_PPCE200ZX_431_ISR_PRI);
#endif /* EE_PPCE200ZX_431_ISR_PRI */
#if defined(EE_PPCE200ZX_432_ISR_PRI)
  EE_spc574k_set_external_priority(432U, EE_PPCE200ZX_432_ISR_PRI);
#endif /* EE_PPCE200ZX_432_ISR_PRI */
#if defined(EE_PPCE200ZX_433_ISR_PRI)
  EE_spc574k_set_external_priority(433U, EE_PPCE200ZX_433_ISR_PRI);
#endif /* EE_PPCE200ZX_433_ISR_PRI */
#if defined(EE_PPCE200ZX_434_ISR_PRI)
  EE_spc574k_set_external_priority(434U, EE_PPCE200ZX_434_ISR_PRI);
#endif /* EE_PPCE200ZX_434_ISR_PRI */
#if defined(EE_PPCE200ZX_435_ISR_PRI)
  EE_spc574k_set_external_priority(435U, EE_PPCE200ZX_435_ISR_PRI);
#endif /* EE_PPCE200ZX_435_ISR_PRI */
#if defined(EE_PPCE200ZX_436_ISR_PRI)
  EE_spc574k_set_external_priority(436U, EE_PPCE200ZX_436_ISR_PRI);
#endif /* EE_PPCE200ZX_436_ISR_PRI */
#if defined(EE_PPCE200ZX_437_ISR_PRI)
  EE_spc574k_set_external_priority(437U, EE_PPCE200ZX_437_ISR_PRI);
#endif /* EE_PPCE200ZX_437_ISR_PRI */
#if defined(EE_PPCE200ZX_438_ISR_PRI)
  EE_spc574k_set_external_priority(438U, EE_PPCE200ZX_438_ISR_PRI);
#endif /* EE_PPCE200ZX_438_ISR_PRI */
#if defined(EE_PPCE200ZX_439_ISR_PRI)
  EE_spc574k_set_external_priority(439U, EE_PPCE200ZX_439_ISR_PRI);
#endif /* EE_PPCE200ZX_439_ISR_PRI */
#if defined(EE_PPCE200ZX_440_ISR_PRI)
  EE_spc574k_set_external_priority(440U, EE_PPCE200ZX_440_ISR_PRI);
#endif /* EE_PPCE200ZX_440_ISR_PRI */
#if defined(EE_PPCE200ZX_441_ISR_PRI)
  EE_spc574k_set_external_priority(441U, EE_PPCE200ZX_441_ISR_PRI);
#endif /* EE_PPCE200ZX_441_ISR_PRI */
#if defined(EE_PPCE200ZX_442_ISR_PRI)
  EE_spc574k_set_external_priority(442U, EE_PPCE200ZX_442_ISR_PRI);
#endif /* EE_PPCE200ZX_442_ISR_PRI */
#if defined(EE_PPCE200ZX_443_ISR_PRI)
  EE_spc574k_set_external_priority(443U, EE_PPCE200ZX_443_ISR_PRI);
#endif /* EE_PPCE200ZX_443_ISR_PRI */
#if defined(EE_PPCE200ZX_444_ISR_PRI)
  EE_spc574k_set_external_priority(444U, EE_PPCE200ZX_444_ISR_PRI);
#endif /* EE_PPCE200ZX_444_ISR_PRI */
#if defined(EE_PPCE200ZX_445_ISR_PRI)
  EE_spc574k_set_external_priority(445U, EE_PPCE200ZX_445_ISR_PRI);
#endif /* EE_PPCE200ZX_445_ISR_PRI */
#if defined(EE_PPCE200ZX_446_ISR_PRI)
  EE_spc574k_set_external_priority(446U, EE_PPCE200ZX_446_ISR_PRI);
#endif /* EE_PPCE200ZX_446_ISR_PRI */
#if defined(EE_PPCE200ZX_447_ISR_PRI)
  EE_spc574k_set_external_priority(447U, EE_PPCE200ZX_447_ISR_PRI);
#endif /* EE_PPCE200ZX_447_ISR_PRI */
#if defined(EE_PPCE200ZX_448_ISR_PRI)
  EE_spc574k_set_external_priority(448U, EE_PPCE200ZX_448_ISR_PRI);
#endif /* EE_PPCE200ZX_448_ISR_PRI */
#if defined(EE_PPCE200ZX_449_ISR_PRI)
  EE_spc574k_set_external_priority(449U, EE_PPCE200ZX_449_ISR_PRI);
#endif /* EE_PPCE200ZX_449_ISR_PRI */
#if defined(EE_PPCE200ZX_450_ISR_PRI)
  EE_spc574k_set_external_priority(450U, EE_PPCE200ZX_450_ISR_PRI);
#endif /* EE_PPCE200ZX_450_ISR_PRI */
#if defined(EE_PPCE200ZX_451_ISR_PRI)
  EE_spc574k_set_external_priority(451U, EE_PPCE200ZX_451_ISR_PRI);
#endif /* EE_PPCE200ZX_451_ISR_PRI */
#if defined(EE_PPCE200ZX_452_ISR_PRI)
  EE_spc574k_set_external_priority(452U, EE_PPCE200ZX_452_ISR_PRI);
#endif /* EE_PPCE200ZX_452_ISR_PRI */
#if defined(EE_PPCE200ZX_453_ISR_PRI)
  EE_spc574k_set_external_priority(453U, EE_PPCE200ZX_453_ISR_PRI);
#endif /* EE_PPCE200ZX_453_ISR_PRI */
#if defined(EE_PPCE200ZX_454_ISR_PRI)
  EE_spc574k_set_external_priority(454U, EE_PPCE200ZX_454_ISR_PRI);
#endif /* EE_PPCE200ZX_454_ISR_PRI */
#if defined(EE_PPCE200ZX_455_ISR_PRI)
  EE_spc574k_set_external_priority(455U, EE_PPCE200ZX_455_ISR_PRI);
#endif /* EE_PPCE200ZX_455_ISR_PRI */
#if defined(EE_PPCE200ZX_456_ISR_PRI)
  EE_spc574k_set_external_priority(456U, EE_PPCE200ZX_456_ISR_PRI);
#endif /* EE_PPCE200ZX_456_ISR_PRI */
#if defined(EE_PPCE200ZX_457_ISR_PRI)
  EE_spc574k_set_external_priority(457U, EE_PPCE200ZX_457_ISR_PRI);
#endif /* EE_PPCE200ZX_457_ISR_PRI */
#if defined(EE_PPCE200ZX_458_ISR_PRI)
  EE_spc574k_set_external_priority(458U, EE_PPCE200ZX_458_ISR_PRI);
#endif /* EE_PPCE200ZX_458_ISR_PRI */
#if defined(EE_PPCE200ZX_459_ISR_PRI)
  EE_spc574k_set_external_priority(459U, EE_PPCE200ZX_459_ISR_PRI);
#endif /* EE_PPCE200ZX_459_ISR_PRI */
#if defined(EE_PPCE200ZX_460_ISR_PRI)
  EE_spc574k_set_external_priority(460U, EE_PPCE200ZX_460_ISR_PRI);
#endif /* EE_PPCE200ZX_460_ISR_PRI */
#if defined(EE_PPCE200ZX_461_ISR_PRI)
  EE_spc574k_set_external_priority(461U, EE_PPCE200ZX_461_ISR_PRI);
#endif /* EE_PPCE200ZX_461_ISR_PRI */
#if defined(EE_PPCE200ZX_462_ISR_PRI)
  EE_spc574k_set_external_priority(462U, EE_PPCE200ZX_462_ISR_PRI);
#endif /* EE_PPCE200ZX_462_ISR_PRI */
#if defined(EE_PPCE200ZX_463_ISR_PRI)
  EE_spc574k_set_external_priority(463U, EE_PPCE200ZX_463_ISR_PRI);
#endif /* EE_PPCE200ZX_463_ISR_PRI */
#if defined(EE_PPCE200ZX_464_ISR_PRI)
  EE_spc574k_set_external_priority(464U, EE_PPCE200ZX_464_ISR_PRI);
#endif /* EE_PPCE200ZX_464_ISR_PRI */
#if defined(EE_PPCE200ZX_465_ISR_PRI)
  EE_spc574k_set_external_priority(465U, EE_PPCE200ZX_465_ISR_PRI);
#endif /* EE_PPCE200ZX_465_ISR_PRI */
#if defined(EE_PPCE200ZX_466_ISR_PRI)
  EE_spc574k_set_external_priority(466U, EE_PPCE200ZX_466_ISR_PRI);
#endif /* EE_PPCE200ZX_466_ISR_PRI */
#if defined(EE_PPCE200ZX_467_ISR_PRI)
  EE_spc574k_set_external_priority(467U, EE_PPCE200ZX_467_ISR_PRI);
#endif /* EE_PPCE200ZX_467_ISR_PRI */
#if defined(EE_PPCE200ZX_468_ISR_PRI)
  EE_spc574k_set_external_priority(468U, EE_PPCE200ZX_468_ISR_PRI);
#endif /* EE_PPCE200ZX_468_ISR_PRI */
#if defined(EE_PPCE200ZX_469_ISR_PRI)
  EE_spc574k_set_external_priority(469U, EE_PPCE200ZX_469_ISR_PRI);
#endif /* EE_PPCE200ZX_469_ISR_PRI */
#if defined(EE_PPCE200ZX_470_ISR_PRI)
  EE_spc574k_set_external_priority(470U, EE_PPCE200ZX_470_ISR_PRI);
#endif /* EE_PPCE200ZX_470_ISR_PRI */
#if defined(EE_PPCE200ZX_471_ISR_PRI)
  EE_spc574k_set_external_priority(471U, EE_PPCE200ZX_471_ISR_PRI);
#endif /* EE_PPCE200ZX_471_ISR_PRI */
#if defined(EE_PPCE200ZX_472_ISR_PRI)
  EE_spc574k_set_external_priority(472U, EE_PPCE200ZX_472_ISR_PRI);
#endif /* EE_PPCE200ZX_472_ISR_PRI */
#if defined(EE_PPCE200ZX_473_ISR_PRI)
  EE_spc574k_set_external_priority(473U, EE_PPCE200ZX_473_ISR_PRI);
#endif /* EE_PPCE200ZX_473_ISR_PRI */
#if defined(EE_PPCE200ZX_474_ISR_PRI)
  EE_spc574k_set_external_priority(474U, EE_PPCE200ZX_474_ISR_PRI);
#endif /* EE_PPCE200ZX_474_ISR_PRI */
#if defined(EE_PPCE200ZX_475_ISR_PRI)
  EE_spc574k_set_external_priority(475U, EE_PPCE200ZX_475_ISR_PRI);
#endif /* EE_PPCE200ZX_475_ISR_PRI */
#if defined(EE_PPCE200ZX_476_ISR_PRI)
  EE_spc574k_set_external_priority(476U, EE_PPCE200ZX_476_ISR_PRI);
#endif /* EE_PPCE200ZX_476_ISR_PRI */
#if defined(EE_PPCE200ZX_477_ISR_PRI)
  EE_spc574k_set_external_priority(477U, EE_PPCE200ZX_477_ISR_PRI);
#endif /* EE_PPCE200ZX_477_ISR_PRI */
#if defined(EE_PPCE200ZX_478_ISR_PRI)
  EE_spc574k_set_external_priority(478U, EE_PPCE200ZX_478_ISR_PRI);
#endif /* EE_PPCE200ZX_478_ISR_PRI */
#if defined(EE_PPCE200ZX_479_ISR_PRI)
  EE_spc574k_set_external_priority(479U, EE_PPCE200ZX_479_ISR_PRI);
#endif /* EE_PPCE200ZX_479_ISR_PRI */
#if defined(EE_PPCE200ZX_480_ISR_PRI)
  EE_spc574k_set_external_priority(480U, EE_PPCE200ZX_480_ISR_PRI);
#endif /* EE_PPCE200ZX_480_ISR_PRI */
#if defined(EE_PPCE200ZX_481_ISR_PRI)
  EE_spc574k_set_external_priority(481U, EE_PPCE200ZX_481_ISR_PRI);
#endif /* EE_PPCE200ZX_481_ISR_PRI */
#if defined(EE_PPCE200ZX_482_ISR_PRI)
  EE_spc574k_set_external_priority(482U, EE_PPCE200ZX_482_ISR_PRI);
#endif /* EE_PPCE200ZX_482_ISR_PRI */
#if defined(EE_PPCE200ZX_483_ISR_PRI)
  EE_spc574k_set_external_priority(483U, EE_PPCE200ZX_483_ISR_PRI);
#endif /* EE_PPCE200ZX_483_ISR_PRI */
#if defined(EE_PPCE200ZX_484_ISR_PRI)
  EE_spc574k_set_external_priority(484U, EE_PPCE200ZX_484_ISR_PRI);
#endif /* EE_PPCE200ZX_484_ISR_PRI */
#if defined(EE_PPCE200ZX_485_ISR_PRI)
  EE_spc574k_set_external_priority(485U, EE_PPCE200ZX_485_ISR_PRI);
#endif /* EE_PPCE200ZX_485_ISR_PRI */
#if defined(EE_PPCE200ZX_486_ISR_PRI)
  EE_spc574k_set_external_priority(486U, EE_PPCE200ZX_486_ISR_PRI);
#endif /* EE_PPCE200ZX_486_ISR_PRI */
#if defined(EE_PPCE200ZX_487_ISR_PRI)
  EE_spc574k_set_external_priority(487U, EE_PPCE200ZX_487_ISR_PRI);
#endif /* EE_PPCE200ZX_487_ISR_PRI */
#if defined(EE_PPCE200ZX_488_ISR_PRI)
  EE_spc574k_set_external_priority(488U, EE_PPCE200ZX_488_ISR_PRI);
#endif /* EE_PPCE200ZX_488_ISR_PRI */
#if defined(EE_PPCE200ZX_489_ISR_PRI)
  EE_spc574k_set_external_priority(489U, EE_PPCE200ZX_489_ISR_PRI);
#endif /* EE_PPCE200ZX_489_ISR_PRI */
#if defined(EE_PPCE200ZX_490_ISR_PRI)
  EE_spc574k_set_external_priority(490U, EE_PPCE200ZX_490_ISR_PRI);
#endif /* EE_PPCE200ZX_490_ISR_PRI */
#if defined(EE_PPCE200ZX_491_ISR_PRI)
  EE_spc574k_set_external_priority(491U, EE_PPCE200ZX_491_ISR_PRI);
#endif /* EE_PPCE200ZX_491_ISR_PRI */
#if defined(EE_PPCE200ZX_492_ISR_PRI)
  EE_spc574k_set_external_priority(492U, EE_PPCE200ZX_492_ISR_PRI);
#endif /* EE_PPCE200ZX_492_ISR_PRI */
#if defined(EE_PPCE200ZX_493_ISR_PRI)
  EE_spc574k_set_external_priority(493U, EE_PPCE200ZX_493_ISR_PRI);
#endif /* EE_PPCE200ZX_493_ISR_PRI */
#if defined(EE_PPCE200ZX_494_ISR_PRI)
  EE_spc574k_set_external_priority(494U, EE_PPCE200ZX_494_ISR_PRI);
#endif /* EE_PPCE200ZX_494_ISR_PRI */
#if defined(EE_PPCE200ZX_495_ISR_PRI)
  EE_spc574k_set_external_priority(495U, EE_PPCE200ZX_495_ISR_PRI);
#endif /* EE_PPCE200ZX_495_ISR_PRI */
#if defined(EE_PPCE200ZX_496_ISR_PRI)
  EE_spc574k_set_external_priority(496U, EE_PPCE200ZX_496_ISR_PRI);
#endif /* EE_PPCE200ZX_496_ISR_PRI */
#if defined(EE_PPCE200ZX_497_ISR_PRI)
  EE_spc574k_set_external_priority(497U, EE_PPCE200ZX_497_ISR_PRI);
#endif /* EE_PPCE200ZX_497_ISR_PRI */
#if defined(EE_PPCE200ZX_498_ISR_PRI)
  EE_spc574k_set_external_priority(498U, EE_PPCE200ZX_498_ISR_PRI);
#endif /* EE_PPCE200ZX_498_ISR_PRI */
#if defined(EE_PPCE200ZX_499_ISR_PRI)
  EE_spc574k_set_external_priority(499U, EE_PPCE200ZX_499_ISR_PRI);
#endif /* EE_PPCE200ZX_499_ISR_PRI */
#if defined(EE_PPCE200ZX_500_ISR_PRI)
  EE_spc574k_set_external_priority(500U, EE_PPCE200ZX_500_ISR_PRI);
#endif /* EE_PPCE200ZX_500_ISR_PRI */
#if defined(EE_PPCE200ZX_501_ISR_PRI)
  EE_spc574k_set_external_priority(501U, EE_PPCE200ZX_501_ISR_PRI);
#endif /* EE_PPCE200ZX_501_ISR_PRI */
#if defined(EE_PPCE200ZX_502_ISR_PRI)
  EE_spc574k_set_external_priority(502U, EE_PPCE200ZX_502_ISR_PRI);
#endif /* EE_PPCE200ZX_502_ISR_PRI */
#if defined(EE_PPCE200ZX_503_ISR_PRI)
  EE_spc574k_set_external_priority(503U, EE_PPCE200ZX_503_ISR_PRI);
#endif /* EE_PPCE200ZX_503_ISR_PRI */
#if defined(EE_PPCE200ZX_504_ISR_PRI)
  EE_spc574k_set_external_priority(504U, EE_PPCE200ZX_504_ISR_PRI);
#endif /* EE_PPCE200ZX_504_ISR_PRI */
#if defined(EE_PPCE200ZX_505_ISR_PRI)
  EE_spc574k_set_external_priority(505U, EE_PPCE200ZX_505_ISR_PRI);
#endif /* EE_PPCE200ZX_505_ISR_PRI */
#if defined(EE_PPCE200ZX_506_ISR_PRI)
  EE_spc574k_set_external_priority(506U, EE_PPCE200ZX_506_ISR_PRI);
#endif /* EE_PPCE200ZX_506_ISR_PRI */
#if defined(EE_PPCE200ZX_507_ISR_PRI)
  EE_spc574k_set_external_priority(507U, EE_PPCE200ZX_507_ISR_PRI);
#endif /* EE_PPCE200ZX_507_ISR_PRI */
#if defined(EE_PPCE200ZX_508_ISR_PRI)
  EE_spc574k_set_external_priority(508U, EE_PPCE200ZX_508_ISR_PRI);
#endif /* EE_PPCE200ZX_508_ISR_PRI */
#if defined(EE_PPCE200ZX_509_ISR_PRI)
  EE_spc574k_set_external_priority(509U, EE_PPCE200ZX_509_ISR_PRI);
#endif /* EE_PPCE200ZX_509_ISR_PRI */
#if defined(EE_PPCE200ZX_510_ISR_PRI)
  EE_spc574k_set_external_priority(510U, EE_PPCE200ZX_510_ISR_PRI);
#endif /* EE_PPCE200ZX_510_ISR_PRI */
#if defined(EE_PPCE200ZX_511_ISR_PRI)
  EE_spc574k_set_external_priority(511U, EE_PPCE200ZX_511_ISR_PRI);
#endif /* EE_PPCE200ZX_511_ISR_PRI */
#if defined(EE_PPCE200ZX_512_ISR_PRI)
  EE_spc574k_set_external_priority(512U, EE_PPCE200ZX_512_ISR_PRI);
#endif /* EE_PPCE200ZX_512_ISR_PRI */
#if defined(EE_PPCE200ZX_513_ISR_PRI)
  EE_spc574k_set_external_priority(513U, EE_PPCE200ZX_513_ISR_PRI);
#endif /* EE_PPCE200ZX_513_ISR_PRI */
#if defined(EE_PPCE200ZX_514_ISR_PRI)
  EE_spc574k_set_external_priority(514U, EE_PPCE200ZX_514_ISR_PRI);
#endif /* EE_PPCE200ZX_514_ISR_PRI */
#if defined(EE_PPCE200ZX_515_ISR_PRI)
  EE_spc574k_set_external_priority(515U, EE_PPCE200ZX_515_ISR_PRI);
#endif /* EE_PPCE200ZX_515_ISR_PRI */
#if defined(EE_PPCE200ZX_516_ISR_PRI)
  EE_spc574k_set_external_priority(516U, EE_PPCE200ZX_516_ISR_PRI);
#endif /* EE_PPCE200ZX_516_ISR_PRI */
#if defined(EE_PPCE200ZX_517_ISR_PRI)
  EE_spc574k_set_external_priority(517U, EE_PPCE200ZX_517_ISR_PRI);
#endif /* EE_PPCE200ZX_517_ISR_PRI */
#if defined(EE_PPCE200ZX_518_ISR_PRI)
  EE_spc574k_set_external_priority(518U, EE_PPCE200ZX_518_ISR_PRI);
#endif /* EE_PPCE200ZX_518_ISR_PRI */
#if defined(EE_PPCE200ZX_519_ISR_PRI)
  EE_spc574k_set_external_priority(519U, EE_PPCE200ZX_519_ISR_PRI);
#endif /* EE_PPCE200ZX_519_ISR_PRI */
#if defined(EE_PPCE200ZX_520_ISR_PRI)
  EE_spc574k_set_external_priority(520U, EE_PPCE200ZX_520_ISR_PRI);
#endif /* EE_PPCE200ZX_520_ISR_PRI */
#if defined(EE_PPCE200ZX_521_ISR_PRI)
  EE_spc574k_set_external_priority(521U, EE_PPCE200ZX_521_ISR_PRI);
#endif /* EE_PPCE200ZX_521_ISR_PRI */
#if defined(EE_PPCE200ZX_522_ISR_PRI)
  EE_spc574k_set_external_priority(522U, EE_PPCE200ZX_522_ISR_PRI);
#endif /* EE_PPCE200ZX_522_ISR_PRI */
#if defined(EE_PPCE200ZX_523_ISR_PRI)
  EE_spc574k_set_external_priority(523U, EE_PPCE200ZX_523_ISR_PRI);
#endif /* EE_PPCE200ZX_523_ISR_PRI */
#if defined(EE_PPCE200ZX_524_ISR_PRI)
  EE_spc574k_set_external_priority(524U, EE_PPCE200ZX_524_ISR_PRI);
#endif /* EE_PPCE200ZX_524_ISR_PRI */
#if defined(EE_PPCE200ZX_525_ISR_PRI)
  EE_spc574k_set_external_priority(525U, EE_PPCE200ZX_525_ISR_PRI);
#endif /* EE_PPCE200ZX_525_ISR_PRI */
#if defined(EE_PPCE200ZX_526_ISR_PRI)
  EE_spc574k_set_external_priority(526U, EE_PPCE200ZX_526_ISR_PRI);
#endif /* EE_PPCE200ZX_526_ISR_PRI */
#if defined(EE_PPCE200ZX_527_ISR_PRI)
  EE_spc574k_set_external_priority(527U, EE_PPCE200ZX_527_ISR_PRI);
#endif /* EE_PPCE200ZX_527_ISR_PRI */
#if defined(EE_PPCE200ZX_528_ISR_PRI)
  EE_spc574k_set_external_priority(528U, EE_PPCE200ZX_528_ISR_PRI);
#endif /* EE_PPCE200ZX_528_ISR_PRI */
#if defined(EE_PPCE200ZX_529_ISR_PRI)
  EE_spc574k_set_external_priority(529U, EE_PPCE200ZX_529_ISR_PRI);
#endif /* EE_PPCE200ZX_529_ISR_PRI */
#if defined(EE_PPCE200ZX_530_ISR_PRI)
  EE_spc574k_set_external_priority(530U, EE_PPCE200ZX_530_ISR_PRI);
#endif /* EE_PPCE200ZX_530_ISR_PRI */
#if defined(EE_PPCE200ZX_531_ISR_PRI)
  EE_spc574k_set_external_priority(531U, EE_PPCE200ZX_531_ISR_PRI);
#endif /* EE_PPCE200ZX_531_ISR_PRI */
#if defined(EE_PPCE200ZX_532_ISR_PRI)
  EE_spc574k_set_external_priority(532U, EE_PPCE200ZX_532_ISR_PRI);
#endif /* EE_PPCE200ZX_532_ISR_PRI */
#if defined(EE_PPCE200ZX_533_ISR_PRI)
  EE_spc574k_set_external_priority(533U, EE_PPCE200ZX_533_ISR_PRI);
#endif /* EE_PPCE200ZX_533_ISR_PRI */
#if defined(EE_PPCE200ZX_534_ISR_PRI)
  EE_spc574k_set_external_priority(534U, EE_PPCE200ZX_534_ISR_PRI);
#endif /* EE_PPCE200ZX_534_ISR_PRI */
#if defined(EE_PPCE200ZX_535_ISR_PRI)
  EE_spc574k_set_external_priority(535U, EE_PPCE200ZX_535_ISR_PRI);
#endif /* EE_PPCE200ZX_535_ISR_PRI */
#if defined(EE_PPCE200ZX_536_ISR_PRI)
  EE_spc574k_set_external_priority(536U, EE_PPCE200ZX_536_ISR_PRI);
#endif /* EE_PPCE200ZX_536_ISR_PRI */
#if defined(EE_PPCE200ZX_537_ISR_PRI)
  EE_spc574k_set_external_priority(537U, EE_PPCE200ZX_537_ISR_PRI);
#endif /* EE_PPCE200ZX_537_ISR_PRI */
#if defined(EE_PPCE200ZX_538_ISR_PRI)
  EE_spc574k_set_external_priority(538U, EE_PPCE200ZX_538_ISR_PRI);
#endif /* EE_PPCE200ZX_538_ISR_PRI */
#if defined(EE_PPCE200ZX_539_ISR_PRI)
  EE_spc574k_set_external_priority(539U, EE_PPCE200ZX_539_ISR_PRI);
#endif /* EE_PPCE200ZX_539_ISR_PRI */
#if defined(EE_PPCE200ZX_540_ISR_PRI)
  EE_spc574k_set_external_priority(540U, EE_PPCE200ZX_540_ISR_PRI);
#endif /* EE_PPCE200ZX_540_ISR_PRI */
#if defined(EE_PPCE200ZX_541_ISR_PRI)
  EE_spc574k_set_external_priority(541U, EE_PPCE200ZX_541_ISR_PRI);
#endif /* EE_PPCE200ZX_541_ISR_PRI */
#if defined(EE_PPCE200ZX_542_ISR_PRI)
  EE_spc574k_set_external_priority(542U, EE_PPCE200ZX_542_ISR_PRI);
#endif /* EE_PPCE200ZX_542_ISR_PRI */
#if defined(EE_PPCE200ZX_543_ISR_PRI)
  EE_spc574k_set_external_priority(543U, EE_PPCE200ZX_543_ISR_PRI);
#endif /* EE_PPCE200ZX_543_ISR_PRI */
#if defined(EE_PPCE200ZX_544_ISR_PRI)
  EE_spc574k_set_external_priority(544U, EE_PPCE200ZX_544_ISR_PRI);
#endif /* EE_PPCE200ZX_544_ISR_PRI */
#if defined(EE_PPCE200ZX_545_ISR_PRI)
  EE_spc574k_set_external_priority(545U, EE_PPCE200ZX_545_ISR_PRI);
#endif /* EE_PPCE200ZX_545_ISR_PRI */
#if defined(EE_PPCE200ZX_546_ISR_PRI)
  EE_spc574k_set_external_priority(546U, EE_PPCE200ZX_546_ISR_PRI);
#endif /* EE_PPCE200ZX_546_ISR_PRI */
#if defined(EE_PPCE200ZX_547_ISR_PRI)
  EE_spc574k_set_external_priority(547U, EE_PPCE200ZX_547_ISR_PRI);
#endif /* EE_PPCE200ZX_547_ISR_PRI */
#if defined(EE_PPCE200ZX_548_ISR_PRI)
  EE_spc574k_set_external_priority(548U, EE_PPCE200ZX_548_ISR_PRI);
#endif /* EE_PPCE200ZX_548_ISR_PRI */
#if defined(EE_PPCE200ZX_549_ISR_PRI)
  EE_spc574k_set_external_priority(549U, EE_PPCE200ZX_549_ISR_PRI);
#endif /* EE_PPCE200ZX_549_ISR_PRI */
#if defined(EE_PPCE200ZX_550_ISR_PRI)
  EE_spc574k_set_external_priority(550U, EE_PPCE200ZX_550_ISR_PRI);
#endif /* EE_PPCE200ZX_550_ISR_PRI */
#if defined(EE_PPCE200ZX_551_ISR_PRI)
  EE_spc574k_set_external_priority(551U, EE_PPCE200ZX_551_ISR_PRI);
#endif /* EE_PPCE200ZX_551_ISR_PRI */
#if defined(EE_PPCE200ZX_552_ISR_PRI)
  EE_spc574k_set_external_priority(552U, EE_PPCE200ZX_552_ISR_PRI);
#endif /* EE_PPCE200ZX_552_ISR_PRI */
#if defined(EE_PPCE200ZX_553_ISR_PRI)
  EE_spc574k_set_external_priority(553U, EE_PPCE200ZX_553_ISR_PRI);
#endif /* EE_PPCE200ZX_553_ISR_PRI */
#if defined(EE_PPCE200ZX_554_ISR_PRI)
  EE_spc574k_set_external_priority(554U, EE_PPCE200ZX_554_ISR_PRI);
#endif /* EE_PPCE200ZX_554_ISR_PRI */
#if defined(EE_PPCE200ZX_555_ISR_PRI)
  EE_spc574k_set_external_priority(555U, EE_PPCE200ZX_555_ISR_PRI);
#endif /* EE_PPCE200ZX_555_ISR_PRI */
#if defined(EE_PPCE200ZX_556_ISR_PRI)
  EE_spc574k_set_external_priority(556U, EE_PPCE200ZX_556_ISR_PRI);
#endif /* EE_PPCE200ZX_556_ISR_PRI */
#if defined(EE_PPCE200ZX_557_ISR_PRI)
  EE_spc574k_set_external_priority(557U, EE_PPCE200ZX_557_ISR_PRI);
#endif /* EE_PPCE200ZX_557_ISR_PRI */
#if defined(EE_PPCE200ZX_558_ISR_PRI)
  EE_spc574k_set_external_priority(558U, EE_PPCE200ZX_558_ISR_PRI);
#endif /* EE_PPCE200ZX_558_ISR_PRI */
#if defined(EE_PPCE200ZX_559_ISR_PRI)
  EE_spc574k_set_external_priority(559U, EE_PPCE200ZX_559_ISR_PRI);
#endif /* EE_PPCE200ZX_559_ISR_PRI */
#if defined(EE_PPCE200ZX_560_ISR_PRI)
  EE_spc574k_set_external_priority(560U, EE_PPCE200ZX_560_ISR_PRI);
#endif /* EE_PPCE200ZX_560_ISR_PRI */
#if defined(EE_PPCE200ZX_561_ISR_PRI)
  EE_spc574k_set_external_priority(561U, EE_PPCE200ZX_561_ISR_PRI);
#endif /* EE_PPCE200ZX_561_ISR_PRI */
#if defined(EE_PPCE200ZX_562_ISR_PRI)
  EE_spc574k_set_external_priority(562U, EE_PPCE200ZX_562_ISR_PRI);
#endif /* EE_PPCE200ZX_562_ISR_PRI */
#if defined(EE_PPCE200ZX_563_ISR_PRI)
  EE_spc574k_set_external_priority(563U, EE_PPCE200ZX_563_ISR_PRI);
#endif /* EE_PPCE200ZX_563_ISR_PRI */
#if defined(EE_PPCE200ZX_564_ISR_PRI)
  EE_spc574k_set_external_priority(564U, EE_PPCE200ZX_564_ISR_PRI);
#endif /* EE_PPCE200ZX_564_ISR_PRI */
#if defined(EE_PPCE200ZX_565_ISR_PRI)
  EE_spc574k_set_external_priority(565U, EE_PPCE200ZX_565_ISR_PRI);
#endif /* EE_PPCE200ZX_565_ISR_PRI */
#if defined(EE_PPCE200ZX_566_ISR_PRI)
  EE_spc574k_set_external_priority(566U, EE_PPCE200ZX_566_ISR_PRI);
#endif /* EE_PPCE200ZX_566_ISR_PRI */
#if defined(EE_PPCE200ZX_567_ISR_PRI)
  EE_spc574k_set_external_priority(567U, EE_PPCE200ZX_567_ISR_PRI);
#endif /* EE_PPCE200ZX_567_ISR_PRI */
#if defined(EE_PPCE200ZX_568_ISR_PRI)
  EE_spc574k_set_external_priority(568U, EE_PPCE200ZX_568_ISR_PRI);
#endif /* EE_PPCE200ZX_568_ISR_PRI */
#if defined(EE_PPCE200ZX_569_ISR_PRI)
  EE_spc574k_set_external_priority(569U, EE_PPCE200ZX_569_ISR_PRI);
#endif /* EE_PPCE200ZX_569_ISR_PRI */
#if defined(EE_PPCE200ZX_570_ISR_PRI)
  EE_spc574k_set_external_priority(570U, EE_PPCE200ZX_570_ISR_PRI);
#endif /* EE_PPCE200ZX_570_ISR_PRI */
#if defined(EE_PPCE200ZX_571_ISR_PRI)
  EE_spc574k_set_external_priority(571U, EE_PPCE200ZX_571_ISR_PRI);
#endif /* EE_PPCE200ZX_571_ISR_PRI */
#if defined(EE_PPCE200ZX_572_ISR_PRI)
  EE_spc574k_set_external_priority(572U, EE_PPCE200ZX_572_ISR_PRI);
#endif /* EE_PPCE200ZX_572_ISR_PRI */
#if defined(EE_PPCE200ZX_573_ISR_PRI)
  EE_spc574k_set_external_priority(573U, EE_PPCE200ZX_573_ISR_PRI);
#endif /* EE_PPCE200ZX_573_ISR_PRI */
#if defined(EE_PPCE200ZX_574_ISR_PRI)
  EE_spc574k_set_external_priority(574U, EE_PPCE200ZX_574_ISR_PRI);
#endif /* EE_PPCE200ZX_574_ISR_PRI */
#if defined(EE_PPCE200ZX_575_ISR_PRI)
  EE_spc574k_set_external_priority(575U, EE_PPCE200ZX_575_ISR_PRI);
#endif /* EE_PPCE200ZX_575_ISR_PRI */
#if defined(EE_PPCE200ZX_576_ISR_PRI)
  EE_spc574k_set_external_priority(576U, EE_PPCE200ZX_576_ISR_PRI);
#endif /* EE_PPCE200ZX_576_ISR_PRI */
#if defined(EE_PPCE200ZX_577_ISR_PRI)
  EE_spc574k_set_external_priority(577U, EE_PPCE200ZX_577_ISR_PRI);
#endif /* EE_PPCE200ZX_577_ISR_PRI */
#if defined(EE_PPCE200ZX_578_ISR_PRI)
  EE_spc574k_set_external_priority(578U, EE_PPCE200ZX_578_ISR_PRI);
#endif /* EE_PPCE200ZX_578_ISR_PRI */
#if defined(EE_PPCE200ZX_579_ISR_PRI)
  EE_spc574k_set_external_priority(579U, EE_PPCE200ZX_579_ISR_PRI);
#endif /* EE_PPCE200ZX_579_ISR_PRI */
#if defined(EE_PPCE200ZX_580_ISR_PRI)
  EE_spc574k_set_external_priority(580U, EE_PPCE200ZX_580_ISR_PRI);
#endif /* EE_PPCE200ZX_580_ISR_PRI */
#if defined(EE_PPCE200ZX_581_ISR_PRI)
  EE_spc574k_set_external_priority(581U, EE_PPCE200ZX_581_ISR_PRI);
#endif /* EE_PPCE200ZX_581_ISR_PRI */
#if defined(EE_PPCE200ZX_582_ISR_PRI)
  EE_spc574k_set_external_priority(582U, EE_PPCE200ZX_582_ISR_PRI);
#endif /* EE_PPCE200ZX_582_ISR_PRI */
#if defined(EE_PPCE200ZX_583_ISR_PRI)
  EE_spc574k_set_external_priority(583U, EE_PPCE200ZX_583_ISR_PRI);
#endif /* EE_PPCE200ZX_583_ISR_PRI */
#if defined(EE_PPCE200ZX_584_ISR_PRI)
  EE_spc574k_set_external_priority(584U, EE_PPCE200ZX_584_ISR_PRI);
#endif /* EE_PPCE200ZX_584_ISR_PRI */
#if defined(EE_PPCE200ZX_585_ISR_PRI)
  EE_spc574k_set_external_priority(585U, EE_PPCE200ZX_585_ISR_PRI);
#endif /* EE_PPCE200ZX_585_ISR_PRI */
#if defined(EE_PPCE200ZX_586_ISR_PRI)
  EE_spc574k_set_external_priority(586U, EE_PPCE200ZX_586_ISR_PRI);
#endif /* EE_PPCE200ZX_586_ISR_PRI */
#if defined(EE_PPCE200ZX_587_ISR_PRI)
  EE_spc574k_set_external_priority(587U, EE_PPCE200ZX_587_ISR_PRI);
#endif /* EE_PPCE200ZX_587_ISR_PRI */
#if defined(EE_PPCE200ZX_588_ISR_PRI)
  EE_spc574k_set_external_priority(588U, EE_PPCE200ZX_588_ISR_PRI);
#endif /* EE_PPCE200ZX_588_ISR_PRI */
#if defined(EE_PPCE200ZX_589_ISR_PRI)
  EE_spc574k_set_external_priority(589U, EE_PPCE200ZX_589_ISR_PRI);
#endif /* EE_PPCE200ZX_589_ISR_PRI */
#if defined(EE_PPCE200ZX_590_ISR_PRI)
  EE_spc574k_set_external_priority(590U, EE_PPCE200ZX_590_ISR_PRI);
#endif /* EE_PPCE200ZX_590_ISR_PRI */
#if defined(EE_PPCE200ZX_591_ISR_PRI)
  EE_spc574k_set_external_priority(591U, EE_PPCE200ZX_591_ISR_PRI);
#endif /* EE_PPCE200ZX_591_ISR_PRI */
#if defined(EE_PPCE200ZX_592_ISR_PRI)
  EE_spc574k_set_external_priority(592U, EE_PPCE200ZX_592_ISR_PRI);
#endif /* EE_PPCE200ZX_592_ISR_PRI */
#if defined(EE_PPCE200ZX_593_ISR_PRI)
  EE_spc574k_set_external_priority(593U, EE_PPCE200ZX_593_ISR_PRI);
#endif /* EE_PPCE200ZX_593_ISR_PRI */
#if defined(EE_PPCE200ZX_594_ISR_PRI)
  EE_spc574k_set_external_priority(594U, EE_PPCE200ZX_594_ISR_PRI);
#endif /* EE_PPCE200ZX_594_ISR_PRI */
#if defined(EE_PPCE200ZX_595_ISR_PRI)
  EE_spc574k_set_external_priority(595U, EE_PPCE200ZX_595_ISR_PRI);
#endif /* EE_PPCE200ZX_595_ISR_PRI */
#if defined(EE_PPCE200ZX_596_ISR_PRI)
  EE_spc574k_set_external_priority(596U, EE_PPCE200ZX_596_ISR_PRI);
#endif /* EE_PPCE200ZX_596_ISR_PRI */
#if defined(EE_PPCE200ZX_597_ISR_PRI)
  EE_spc574k_set_external_priority(597U, EE_PPCE200ZX_597_ISR_PRI);
#endif /* EE_PPCE200ZX_597_ISR_PRI */
#if defined(EE_PPCE200ZX_598_ISR_PRI)
  EE_spc574k_set_external_priority(598U, EE_PPCE200ZX_598_ISR_PRI);
#endif /* EE_PPCE200ZX_598_ISR_PRI */
#if defined(EE_PPCE200ZX_599_ISR_PRI)
  EE_spc574k_set_external_priority(599U, EE_PPCE200ZX_599_ISR_PRI);
#endif /* EE_PPCE200ZX_599_ISR_PRI */
#if defined(EE_PPCE200ZX_600_ISR_PRI)
  EE_spc574k_set_external_priority(600U, EE_PPCE200ZX_600_ISR_PRI);
#endif /* EE_PPCE200ZX_600_ISR_PRI */
#if defined(EE_PPCE200ZX_601_ISR_PRI)
  EE_spc574k_set_external_priority(601U, EE_PPCE200ZX_601_ISR_PRI);
#endif /* EE_PPCE200ZX_601_ISR_PRI */
#if defined(EE_PPCE200ZX_602_ISR_PRI)
  EE_spc574k_set_external_priority(602U, EE_PPCE200ZX_602_ISR_PRI);
#endif /* EE_PPCE200ZX_602_ISR_PRI */
#if defined(EE_PPCE200ZX_603_ISR_PRI)
  EE_spc574k_set_external_priority(603U, EE_PPCE200ZX_603_ISR_PRI);
#endif /* EE_PPCE200ZX_603_ISR_PRI */
#if defined(EE_PPCE200ZX_604_ISR_PRI)
  EE_spc574k_set_external_priority(604U, EE_PPCE200ZX_604_ISR_PRI);
#endif /* EE_PPCE200ZX_604_ISR_PRI */
#if defined(EE_PPCE200ZX_605_ISR_PRI)
  EE_spc574k_set_external_priority(605U, EE_PPCE200ZX_605_ISR_PRI);
#endif /* EE_PPCE200ZX_605_ISR_PRI */
#if defined(EE_PPCE200ZX_606_ISR_PRI)
  EE_spc574k_set_external_priority(606U, EE_PPCE200ZX_606_ISR_PRI);
#endif /* EE_PPCE200ZX_606_ISR_PRI */
#if defined(EE_PPCE200ZX_607_ISR_PRI)
  EE_spc574k_set_external_priority(607U, EE_PPCE200ZX_607_ISR_PRI);
#endif /* EE_PPCE200ZX_607_ISR_PRI */
#if defined(EE_PPCE200ZX_608_ISR_PRI)
  EE_spc574k_set_external_priority(608U, EE_PPCE200ZX_608_ISR_PRI);
#endif /* EE_PPCE200ZX_608_ISR_PRI */
#if defined(EE_PPCE200ZX_609_ISR_PRI)
  EE_spc574k_set_external_priority(609U, EE_PPCE200ZX_609_ISR_PRI);
#endif /* EE_PPCE200ZX_609_ISR_PRI */
#if defined(EE_PPCE200ZX_610_ISR_PRI)
  EE_spc574k_set_external_priority(610U, EE_PPCE200ZX_610_ISR_PRI);
#endif /* EE_PPCE200ZX_610_ISR_PRI */
#if defined(EE_PPCE200ZX_611_ISR_PRI)
  EE_spc574k_set_external_priority(611U, EE_PPCE200ZX_611_ISR_PRI);
#endif /* EE_PPCE200ZX_611_ISR_PRI */
#if defined(EE_PPCE200ZX_612_ISR_PRI)
  EE_spc574k_set_external_priority(612U, EE_PPCE200ZX_612_ISR_PRI);
#endif /* EE_PPCE200ZX_612_ISR_PRI */
#if defined(EE_PPCE200ZX_613_ISR_PRI)
  EE_spc574k_set_external_priority(613U, EE_PPCE200ZX_613_ISR_PRI);
#endif /* EE_PPCE200ZX_613_ISR_PRI */
#if defined(EE_PPCE200ZX_614_ISR_PRI)
  EE_spc574k_set_external_priority(614U, EE_PPCE200ZX_614_ISR_PRI);
#endif /* EE_PPCE200ZX_614_ISR_PRI */
#if defined(EE_PPCE200ZX_615_ISR_PRI)
  EE_spc574k_set_external_priority(615U, EE_PPCE200ZX_615_ISR_PRI);
#endif /* EE_PPCE200ZX_615_ISR_PRI */
#if defined(EE_PPCE200ZX_616_ISR_PRI)
  EE_spc574k_set_external_priority(616U, EE_PPCE200ZX_616_ISR_PRI);
#endif /* EE_PPCE200ZX_616_ISR_PRI */
#if defined(EE_PPCE200ZX_617_ISR_PRI)
  EE_spc574k_set_external_priority(617U, EE_PPCE200ZX_617_ISR_PRI);
#endif /* EE_PPCE200ZX_617_ISR_PRI */
#if defined(EE_PPCE200ZX_618_ISR_PRI)
  EE_spc574k_set_external_priority(618U, EE_PPCE200ZX_618_ISR_PRI);
#endif /* EE_PPCE200ZX_618_ISR_PRI */
#if defined(EE_PPCE200ZX_619_ISR_PRI)
  EE_spc574k_set_external_priority(619U, EE_PPCE200ZX_619_ISR_PRI);
#endif /* EE_PPCE200ZX_619_ISR_PRI */
#if defined(EE_PPCE200ZX_620_ISR_PRI)
  EE_spc574k_set_external_priority(620U, EE_PPCE200ZX_620_ISR_PRI);
#endif /* EE_PPCE200ZX_620_ISR_PRI */
#if defined(EE_PPCE200ZX_621_ISR_PRI)
  EE_spc574k_set_external_priority(621U, EE_PPCE200ZX_621_ISR_PRI);
#endif /* EE_PPCE200ZX_621_ISR_PRI */
#if defined(EE_PPCE200ZX_622_ISR_PRI)
  EE_spc574k_set_external_priority(622U, EE_PPCE200ZX_622_ISR_PRI);
#endif /* EE_PPCE200ZX_622_ISR_PRI */
#if defined(EE_PPCE200ZX_623_ISR_PRI)
  EE_spc574k_set_external_priority(623U, EE_PPCE200ZX_623_ISR_PRI);
#endif /* EE_PPCE200ZX_623_ISR_PRI */
#if defined(EE_PPCE200ZX_624_ISR_PRI)
  EE_spc574k_set_external_priority(624U, EE_PPCE200ZX_624_ISR_PRI);
#endif /* EE_PPCE200ZX_624_ISR_PRI */
#if defined(EE_PPCE200ZX_625_ISR_PRI)
  EE_spc574k_set_external_priority(625U, EE_PPCE200ZX_625_ISR_PRI);
#endif /* EE_PPCE200ZX_625_ISR_PRI */
#if defined(EE_PPCE200ZX_626_ISR_PRI)
  EE_spc574k_set_external_priority(626U, EE_PPCE200ZX_626_ISR_PRI);
#endif /* EE_PPCE200ZX_626_ISR_PRI */
#if defined(EE_PPCE200ZX_627_ISR_PRI)
  EE_spc574k_set_external_priority(627U, EE_PPCE200ZX_627_ISR_PRI);
#endif /* EE_PPCE200ZX_627_ISR_PRI */
#if defined(EE_PPCE200ZX_628_ISR_PRI)
  EE_spc574k_set_external_priority(628U, EE_PPCE200ZX_628_ISR_PRI);
#endif /* EE_PPCE200ZX_628_ISR_PRI */
#if defined(EE_PPCE200ZX_629_ISR_PRI)
  EE_spc574k_set_external_priority(629U, EE_PPCE200ZX_629_ISR_PRI);
#endif /* EE_PPCE200ZX_629_ISR_PRI */
#if defined(EE_PPCE200ZX_630_ISR_PRI)
  EE_spc574k_set_external_priority(630U, EE_PPCE200ZX_630_ISR_PRI);
#endif /* EE_PPCE200ZX_630_ISR_PRI */
#if defined(EE_PPCE200ZX_631_ISR_PRI)
  EE_spc574k_set_external_priority(631U, EE_PPCE200ZX_631_ISR_PRI);
#endif /* EE_PPCE200ZX_631_ISR_PRI */
#if defined(EE_PPCE200ZX_632_ISR_PRI)
  EE_spc574k_set_external_priority(632U, EE_PPCE200ZX_632_ISR_PRI);
#endif /* EE_PPCE200ZX_632_ISR_PRI */
#if defined(EE_PPCE200ZX_633_ISR_PRI)
  EE_spc574k_set_external_priority(633U, EE_PPCE200ZX_633_ISR_PRI);
#endif /* EE_PPCE200ZX_633_ISR_PRI */
#if defined(EE_PPCE200ZX_634_ISR_PRI)
  EE_spc574k_set_external_priority(634U, EE_PPCE200ZX_634_ISR_PRI);
#endif /* EE_PPCE200ZX_634_ISR_PRI */
#if defined(EE_PPCE200ZX_635_ISR_PRI)
  EE_spc574k_set_external_priority(635U, EE_PPCE200ZX_635_ISR_PRI);
#endif /* EE_PPCE200ZX_635_ISR_PRI */
#if defined(EE_PPCE200ZX_636_ISR_PRI)
  EE_spc574k_set_external_priority(636U, EE_PPCE200ZX_636_ISR_PRI);
#endif /* EE_PPCE200ZX_636_ISR_PRI */
#if defined(EE_PPCE200ZX_637_ISR_PRI)
  EE_spc574k_set_external_priority(637U, EE_PPCE200ZX_637_ISR_PRI);
#endif /* EE_PPCE200ZX_637_ISR_PRI */
#if defined(EE_PPCE200ZX_638_ISR_PRI)
  EE_spc574k_set_external_priority(638U, EE_PPCE200ZX_638_ISR_PRI);
#endif /* EE_PPCE200ZX_638_ISR_PRI */
#if defined(EE_PPCE200ZX_639_ISR_PRI)
  EE_spc574k_set_external_priority(639U, EE_PPCE200ZX_639_ISR_PRI);
#endif /* EE_PPCE200ZX_639_ISR_PRI */
#if defined(EE_PPCE200ZX_640_ISR_PRI)
  EE_spc574k_set_external_priority(640U, EE_PPCE200ZX_640_ISR_PRI);
#endif /* EE_PPCE200ZX_640_ISR_PRI */
#if defined(EE_PPCE200ZX_641_ISR_PRI)
  EE_spc574k_set_external_priority(641U, EE_PPCE200ZX_641_ISR_PRI);
#endif /* EE_PPCE200ZX_641_ISR_PRI */
#if defined(EE_PPCE200ZX_642_ISR_PRI)
  EE_spc574k_set_external_priority(642U, EE_PPCE200ZX_642_ISR_PRI);
#endif /* EE_PPCE200ZX_642_ISR_PRI */
#if defined(EE_PPCE200ZX_643_ISR_PRI)
  EE_spc574k_set_external_priority(643U, EE_PPCE200ZX_643_ISR_PRI);
#endif /* EE_PPCE200ZX_643_ISR_PRI */
#if defined(EE_PPCE200ZX_644_ISR_PRI)
  EE_spc574k_set_external_priority(644U, EE_PPCE200ZX_644_ISR_PRI);
#endif /* EE_PPCE200ZX_644_ISR_PRI */
#if defined(EE_PPCE200ZX_645_ISR_PRI)
  EE_spc574k_set_external_priority(645U, EE_PPCE200ZX_645_ISR_PRI);
#endif /* EE_PPCE200ZX_645_ISR_PRI */
#if defined(EE_PPCE200ZX_646_ISR_PRI)
  EE_spc574k_set_external_priority(646U, EE_PPCE200ZX_646_ISR_PRI);
#endif /* EE_PPCE200ZX_646_ISR_PRI */
#if defined(EE_PPCE200ZX_647_ISR_PRI)
  EE_spc574k_set_external_priority(647U, EE_PPCE200ZX_647_ISR_PRI);
#endif /* EE_PPCE200ZX_647_ISR_PRI */
#if defined(EE_PPCE200ZX_648_ISR_PRI)
  EE_spc574k_set_external_priority(648U, EE_PPCE200ZX_648_ISR_PRI);
#endif /* EE_PPCE200ZX_648_ISR_PRI */
#if defined(EE_PPCE200ZX_649_ISR_PRI)
  EE_spc574k_set_external_priority(649U, EE_PPCE200ZX_649_ISR_PRI);
#endif /* EE_PPCE200ZX_649_ISR_PRI */
#if defined(EE_PPCE200ZX_650_ISR_PRI)
  EE_spc574k_set_external_priority(650U, EE_PPCE200ZX_650_ISR_PRI);
#endif /* EE_PPCE200ZX_650_ISR_PRI */
#if defined(EE_PPCE200ZX_651_ISR_PRI)
  EE_spc574k_set_external_priority(651U, EE_PPCE200ZX_651_ISR_PRI);
#endif /* EE_PPCE200ZX_651_ISR_PRI */
#if defined(EE_PPCE200ZX_652_ISR_PRI)
  EE_spc574k_set_external_priority(652U, EE_PPCE200ZX_652_ISR_PRI);
#endif /* EE_PPCE200ZX_652_ISR_PRI */
#if defined(EE_PPCE200ZX_653_ISR_PRI)
  EE_spc574k_set_external_priority(653U, EE_PPCE200ZX_653_ISR_PRI);
#endif /* EE_PPCE200ZX_653_ISR_PRI */
#if defined(EE_PPCE200ZX_654_ISR_PRI)
  EE_spc574k_set_external_priority(654U, EE_PPCE200ZX_654_ISR_PRI);
#endif /* EE_PPCE200ZX_654_ISR_PRI */
#if defined(EE_PPCE200ZX_655_ISR_PRI)
  EE_spc574k_set_external_priority(655U, EE_PPCE200ZX_655_ISR_PRI);
#endif /* EE_PPCE200ZX_655_ISR_PRI */
#if defined(EE_PPCE200ZX_656_ISR_PRI)
  EE_spc574k_set_external_priority(656U, EE_PPCE200ZX_656_ISR_PRI);
#endif /* EE_PPCE200ZX_656_ISR_PRI */
#if defined(EE_PPCE200ZX_657_ISR_PRI)
  EE_spc574k_set_external_priority(657U, EE_PPCE200ZX_657_ISR_PRI);
#endif /* EE_PPCE200ZX_657_ISR_PRI */
#if defined(EE_PPCE200ZX_658_ISR_PRI)
  EE_spc574k_set_external_priority(658U, EE_PPCE200ZX_658_ISR_PRI);
#endif /* EE_PPCE200ZX_658_ISR_PRI */
#if defined(EE_PPCE200ZX_659_ISR_PRI)
  EE_spc574k_set_external_priority(659U, EE_PPCE200ZX_659_ISR_PRI);
#endif /* EE_PPCE200ZX_659_ISR_PRI */
#if defined(EE_PPCE200ZX_660_ISR_PRI)
  EE_spc574k_set_external_priority(660U, EE_PPCE200ZX_660_ISR_PRI);
#endif /* EE_PPCE200ZX_660_ISR_PRI */
#if defined(EE_PPCE200ZX_661_ISR_PRI)
  EE_spc574k_set_external_priority(661U, EE_PPCE200ZX_661_ISR_PRI);
#endif /* EE_PPCE200ZX_661_ISR_PRI */
#if defined(EE_PPCE200ZX_662_ISR_PRI)
  EE_spc574k_set_external_priority(662U, EE_PPCE200ZX_662_ISR_PRI);
#endif /* EE_PPCE200ZX_662_ISR_PRI */
#if defined(EE_PPCE200ZX_663_ISR_PRI)
  EE_spc574k_set_external_priority(663U, EE_PPCE200ZX_663_ISR_PRI);
#endif /* EE_PPCE200ZX_663_ISR_PRI */
#if defined(EE_PPCE200ZX_664_ISR_PRI)
  EE_spc574k_set_external_priority(664U, EE_PPCE200ZX_664_ISR_PRI);
#endif /* EE_PPCE200ZX_664_ISR_PRI */
#if defined(EE_PPCE200ZX_665_ISR_PRI)
  EE_spc574k_set_external_priority(665U, EE_PPCE200ZX_665_ISR_PRI);
#endif /* EE_PPCE200ZX_665_ISR_PRI */
#if defined(EE_PPCE200ZX_666_ISR_PRI)
  EE_spc574k_set_external_priority(666U, EE_PPCE200ZX_666_ISR_PRI);
#endif /* EE_PPCE200ZX_666_ISR_PRI */
#if defined(EE_PPCE200ZX_667_ISR_PRI)
  EE_spc574k_set_external_priority(667U, EE_PPCE200ZX_667_ISR_PRI);
#endif /* EE_PPCE200ZX_667_ISR_PRI */
#if defined(EE_PPCE200ZX_668_ISR_PRI)
  EE_spc574k_set_external_priority(668U, EE_PPCE200ZX_668_ISR_PRI);
#endif /* EE_PPCE200ZX_668_ISR_PRI */
#if defined(EE_PPCE200ZX_669_ISR_PRI)
  EE_spc574k_set_external_priority(669U, EE_PPCE200ZX_669_ISR_PRI);
#endif /* EE_PPCE200ZX_669_ISR_PRI */
#if defined(EE_PPCE200ZX_670_ISR_PRI)
  EE_spc574k_set_external_priority(670U, EE_PPCE200ZX_670_ISR_PRI);
#endif /* EE_PPCE200ZX_670_ISR_PRI */
#if defined(EE_PPCE200ZX_671_ISR_PRI)
  EE_spc574k_set_external_priority(671U, EE_PPCE200ZX_671_ISR_PRI);
#endif /* EE_PPCE200ZX_671_ISR_PRI */
#if defined(EE_PPCE200ZX_672_ISR_PRI)
  EE_spc574k_set_external_priority(672U, EE_PPCE200ZX_672_ISR_PRI);
#endif /* EE_PPCE200ZX_672_ISR_PRI */
#if defined(EE_PPCE200ZX_673_ISR_PRI)
  EE_spc574k_set_external_priority(673U, EE_PPCE200ZX_673_ISR_PRI);
#endif /* EE_PPCE200ZX_673_ISR_PRI */
#if defined(EE_PPCE200ZX_674_ISR_PRI)
  EE_spc574k_set_external_priority(674U, EE_PPCE200ZX_674_ISR_PRI);
#endif /* EE_PPCE200ZX_674_ISR_PRI */
#if defined(EE_PPCE200ZX_675_ISR_PRI)
  EE_spc574k_set_external_priority(675U, EE_PPCE200ZX_675_ISR_PRI);
#endif /* EE_PPCE200ZX_675_ISR_PRI */
#if defined(EE_PPCE200ZX_676_ISR_PRI)
  EE_spc574k_set_external_priority(676U, EE_PPCE200ZX_676_ISR_PRI);
#endif /* EE_PPCE200ZX_676_ISR_PRI */
#if defined(EE_PPCE200ZX_677_ISR_PRI)
  EE_spc574k_set_external_priority(677U, EE_PPCE200ZX_677_ISR_PRI);
#endif /* EE_PPCE200ZX_677_ISR_PRI */
#if defined(EE_PPCE200ZX_678_ISR_PRI)
  EE_spc574k_set_external_priority(678U, EE_PPCE200ZX_678_ISR_PRI);
#endif /* EE_PPCE200ZX_678_ISR_PRI */
#if defined(EE_PPCE200ZX_679_ISR_PRI)
  EE_spc574k_set_external_priority(679U, EE_PPCE200ZX_679_ISR_PRI);
#endif /* EE_PPCE200ZX_679_ISR_PRI */
#if defined(EE_PPCE200ZX_680_ISR_PRI)
  EE_spc574k_set_external_priority(680U, EE_PPCE200ZX_680_ISR_PRI);
#endif /* EE_PPCE200ZX_680_ISR_PRI */
#if defined(EE_PPCE200ZX_681_ISR_PRI)
  EE_spc574k_set_external_priority(681U, EE_PPCE200ZX_681_ISR_PRI);
#endif /* EE_PPCE200ZX_681_ISR_PRI */
#if defined(EE_PPCE200ZX_682_ISR_PRI)
  EE_spc574k_set_external_priority(682U, EE_PPCE200ZX_682_ISR_PRI);
#endif /* EE_PPCE200ZX_682_ISR_PRI */
#if defined(EE_PPCE200ZX_683_ISR_PRI)
  EE_spc574k_set_external_priority(683U, EE_PPCE200ZX_683_ISR_PRI);
#endif /* EE_PPCE200ZX_683_ISR_PRI */
#if defined(EE_PPCE200ZX_684_ISR_PRI)
  EE_spc574k_set_external_priority(684U, EE_PPCE200ZX_684_ISR_PRI);
#endif /* EE_PPCE200ZX_684_ISR_PRI */
#if defined(EE_PPCE200ZX_685_ISR_PRI)
  EE_spc574k_set_external_priority(685U, EE_PPCE200ZX_685_ISR_PRI);
#endif /* EE_PPCE200ZX_685_ISR_PRI */
#if defined(EE_PPCE200ZX_686_ISR_PRI)
  EE_spc574k_set_external_priority(686U, EE_PPCE200ZX_686_ISR_PRI);
#endif /* EE_PPCE200ZX_686_ISR_PRI */
#if defined(EE_PPCE200ZX_687_ISR_PRI)
  EE_spc574k_set_external_priority(687U, EE_PPCE200ZX_687_ISR_PRI);
#endif /* EE_PPCE200ZX_687_ISR_PRI */
#if defined(EE_PPCE200ZX_688_ISR_PRI)
  EE_spc574k_set_external_priority(688U, EE_PPCE200ZX_688_ISR_PRI);
#endif /* EE_PPCE200ZX_688_ISR_PRI */
#if defined(EE_PPCE200ZX_689_ISR_PRI)
  EE_spc574k_set_external_priority(689U, EE_PPCE200ZX_689_ISR_PRI);
#endif /* EE_PPCE200ZX_689_ISR_PRI */
#if defined(EE_PPCE200ZX_690_ISR_PRI)
  EE_spc574k_set_external_priority(690U, EE_PPCE200ZX_690_ISR_PRI);
#endif /* EE_PPCE200ZX_690_ISR_PRI */
#if defined(EE_PPCE200ZX_691_ISR_PRI)
  EE_spc574k_set_external_priority(691U, EE_PPCE200ZX_691_ISR_PRI);
#endif /* EE_PPCE200ZX_691_ISR_PRI */
#if defined(EE_PPCE200ZX_692_ISR_PRI)
  EE_spc574k_set_external_priority(692U, EE_PPCE200ZX_692_ISR_PRI);
#endif /* EE_PPCE200ZX_692_ISR_PRI */
#if defined(EE_PPCE200ZX_693_ISR_PRI)
  EE_spc574k_set_external_priority(693U, EE_PPCE200ZX_693_ISR_PRI);
#endif /* EE_PPCE200ZX_693_ISR_PRI */
#if defined(EE_PPCE200ZX_694_ISR_PRI)
  EE_spc574k_set_external_priority(694U, EE_PPCE200ZX_694_ISR_PRI);
#endif /* EE_PPCE200ZX_694_ISR_PRI */
#if defined(EE_PPCE200ZX_695_ISR_PRI)
  EE_spc574k_set_external_priority(695U, EE_PPCE200ZX_695_ISR_PRI);
#endif /* EE_PPCE200ZX_695_ISR_PRI */
#if defined(EE_PPCE200ZX_696_ISR_PRI)
  EE_spc574k_set_external_priority(696U, EE_PPCE200ZX_696_ISR_PRI);
#endif /* EE_PPCE200ZX_696_ISR_PRI */
#if defined(EE_PPCE200ZX_697_ISR_PRI)
  EE_spc574k_set_external_priority(697U, EE_PPCE200ZX_697_ISR_PRI);
#endif /* EE_PPCE200ZX_697_ISR_PRI */
#if defined(EE_PPCE200ZX_698_ISR_PRI)
  EE_spc574k_set_external_priority(698U, EE_PPCE200ZX_698_ISR_PRI);
#endif /* EE_PPCE200ZX_698_ISR_PRI */
#if defined(EE_PPCE200ZX_699_ISR_PRI)
  EE_spc574k_set_external_priority(699U, EE_PPCE200ZX_699_ISR_PRI);
#endif /* EE_PPCE200ZX_699_ISR_PRI */
#if defined(EE_PPCE200ZX_700_ISR_PRI)
  EE_spc574k_set_external_priority(700U, EE_PPCE200ZX_700_ISR_PRI);
#endif /* EE_PPCE200ZX_700_ISR_PRI */
#if defined(EE_PPCE200ZX_701_ISR_PRI)
  EE_spc574k_set_external_priority(701U, EE_PPCE200ZX_701_ISR_PRI);
#endif /* EE_PPCE200ZX_701_ISR_PRI */
#if defined(EE_PPCE200ZX_702_ISR_PRI)
  EE_spc574k_set_external_priority(702U, EE_PPCE200ZX_702_ISR_PRI);
#endif /* EE_PPCE200ZX_702_ISR_PRI */
#if defined(EE_PPCE200ZX_703_ISR_PRI)
  EE_spc574k_set_external_priority(703U, EE_PPCE200ZX_703_ISR_PRI);
#endif /* EE_PPCE200ZX_703_ISR_PRI */
#if defined(EE_PPCE200ZX_704_ISR_PRI)
  EE_spc574k_set_external_priority(704U, EE_PPCE200ZX_704_ISR_PRI);
#endif /* EE_PPCE200ZX_704_ISR_PRI */
#if defined(EE_PPCE200ZX_705_ISR_PRI)
  EE_spc574k_set_external_priority(705U, EE_PPCE200ZX_705_ISR_PRI);
#endif /* EE_PPCE200ZX_705_ISR_PRI */
#if defined(EE_PPCE200ZX_706_ISR_PRI)
  EE_spc574k_set_external_priority(706U, EE_PPCE200ZX_706_ISR_PRI);
#endif /* EE_PPCE200ZX_706_ISR_PRI */
#if defined(EE_PPCE200ZX_707_ISR_PRI)
  EE_spc574k_set_external_priority(707U, EE_PPCE200ZX_707_ISR_PRI);
#endif /* EE_PPCE200ZX_707_ISR_PRI */
#if defined(EE_PPCE200ZX_708_ISR_PRI)
  EE_spc574k_set_external_priority(708U, EE_PPCE200ZX_708_ISR_PRI);
#endif /* EE_PPCE200ZX_708_ISR_PRI */
#if defined(EE_PPCE200ZX_709_ISR_PRI)
  EE_spc574k_set_external_priority(709U, EE_PPCE200ZX_709_ISR_PRI);
#endif /* EE_PPCE200ZX_709_ISR_PRI */
#if defined(EE_PPCE200ZX_710_ISR_PRI)
  EE_spc574k_set_external_priority(710U, EE_PPCE200ZX_710_ISR_PRI);
#endif /* EE_PPCE200ZX_710_ISR_PRI */
#if defined(EE_PPCE200ZX_711_ISR_PRI)
  EE_spc574k_set_external_priority(711U, EE_PPCE200ZX_711_ISR_PRI);
#endif /* EE_PPCE200ZX_711_ISR_PRI */
#if defined(EE_PPCE200ZX_712_ISR_PRI)
  EE_spc574k_set_external_priority(712U, EE_PPCE200ZX_712_ISR_PRI);
#endif /* EE_PPCE200ZX_712_ISR_PRI */
#if defined(EE_PPCE200ZX_713_ISR_PRI)
  EE_spc574k_set_external_priority(713U, EE_PPCE200ZX_713_ISR_PRI);
#endif /* EE_PPCE200ZX_713_ISR_PRI */
#if defined(EE_PPCE200ZX_714_ISR_PRI)
  EE_spc574k_set_external_priority(714U, EE_PPCE200ZX_714_ISR_PRI);
#endif /* EE_PPCE200ZX_714_ISR_PRI */
#if defined(EE_PPCE200ZX_715_ISR_PRI)
  EE_spc574k_set_external_priority(715U, EE_PPCE200ZX_715_ISR_PRI);
#endif /* EE_PPCE200ZX_715_ISR_PRI */
#if defined(EE_PPCE200ZX_716_ISR_PRI)
  EE_spc574k_set_external_priority(716U, EE_PPCE200ZX_716_ISR_PRI);
#endif /* EE_PPCE200ZX_716_ISR_PRI */
#if defined(EE_PPCE200ZX_717_ISR_PRI)
  EE_spc574k_set_external_priority(717U, EE_PPCE200ZX_717_ISR_PRI);
#endif /* EE_PPCE200ZX_717_ISR_PRI */
#if defined(EE_PPCE200ZX_718_ISR_PRI)
  EE_spc574k_set_external_priority(718U, EE_PPCE200ZX_718_ISR_PRI);
#endif /* EE_PPCE200ZX_718_ISR_PRI */
#if defined(EE_PPCE200ZX_719_ISR_PRI)
  EE_spc574k_set_external_priority(719U, EE_PPCE200ZX_719_ISR_PRI);
#endif /* EE_PPCE200ZX_719_ISR_PRI */
#if defined(EE_PPCE200ZX_720_ISR_PRI)
  EE_spc574k_set_external_priority(720U, EE_PPCE200ZX_720_ISR_PRI);
#endif /* EE_PPCE200ZX_720_ISR_PRI */
#if defined(EE_PPCE200ZX_721_ISR_PRI)
  EE_spc574k_set_external_priority(721U, EE_PPCE200ZX_721_ISR_PRI);
#endif /* EE_PPCE200ZX_721_ISR_PRI */
#if defined(EE_PPCE200ZX_722_ISR_PRI)
  EE_spc574k_set_external_priority(722U, EE_PPCE200ZX_722_ISR_PRI);
#endif /* EE_PPCE200ZX_722_ISR_PRI */
#if defined(EE_PPCE200ZX_723_ISR_PRI)
  EE_spc574k_set_external_priority(723U, EE_PPCE200ZX_723_ISR_PRI);
#endif /* EE_PPCE200ZX_723_ISR_PRI */
#if defined(EE_PPCE200ZX_724_ISR_PRI)
  EE_spc574k_set_external_priority(724U, EE_PPCE200ZX_724_ISR_PRI);
#endif /* EE_PPCE200ZX_724_ISR_PRI */
#if defined(EE_PPCE200ZX_725_ISR_PRI)
  EE_spc574k_set_external_priority(725U, EE_PPCE200ZX_725_ISR_PRI);
#endif /* EE_PPCE200ZX_725_ISR_PRI */
#if defined(EE_PPCE200ZX_726_ISR_PRI)
  EE_spc574k_set_external_priority(726U, EE_PPCE200ZX_726_ISR_PRI);
#endif /* EE_PPCE200ZX_726_ISR_PRI */
#if defined(EE_PPCE200ZX_727_ISR_PRI)
  EE_spc574k_set_external_priority(727U, EE_PPCE200ZX_727_ISR_PRI);
#endif /* EE_PPCE200ZX_727_ISR_PRI */
#if defined(EE_PPCE200ZX_728_ISR_PRI)
  EE_spc574k_set_external_priority(728U, EE_PPCE200ZX_728_ISR_PRI);
#endif /* EE_PPCE200ZX_728_ISR_PRI */
#if defined(EE_PPCE200ZX_729_ISR_PRI)
  EE_spc574k_set_external_priority(729U, EE_PPCE200ZX_729_ISR_PRI);
#endif /* EE_PPCE200ZX_729_ISR_PRI */
#if defined(EE_PPCE200ZX_730_ISR_PRI)
  EE_spc574k_set_external_priority(730U, EE_PPCE200ZX_730_ISR_PRI);
#endif /* EE_PPCE200ZX_730_ISR_PRI */
#if defined(EE_PPCE200ZX_731_ISR_PRI)
  EE_spc574k_set_external_priority(731U, EE_PPCE200ZX_731_ISR_PRI);
#endif /* EE_PPCE200ZX_731_ISR_PRI */
#if defined(EE_PPCE200ZX_732_ISR_PRI)
  EE_spc574k_set_external_priority(732U, EE_PPCE200ZX_732_ISR_PRI);
#endif /* EE_PPCE200ZX_732_ISR_PRI */
#if defined(EE_PPCE200ZX_733_ISR_PRI)
  EE_spc574k_set_external_priority(733U, EE_PPCE200ZX_733_ISR_PRI);
#endif /* EE_PPCE200ZX_733_ISR_PRI */
#if defined(EE_PPCE200ZX_734_ISR_PRI)
  EE_spc574k_set_external_priority(734U, EE_PPCE200ZX_734_ISR_PRI);
#endif /* EE_PPCE200ZX_734_ISR_PRI */
#if defined(EE_PPCE200ZX_735_ISR_PRI)
  EE_spc574k_set_external_priority(735U, EE_PPCE200ZX_735_ISR_PRI);
#endif /* EE_PPCE200ZX_735_ISR_PRI */
#if defined(EE_PPCE200ZX_736_ISR_PRI)
  EE_spc574k_set_external_priority(736U, EE_PPCE200ZX_736_ISR_PRI);
#endif /* EE_PPCE200ZX_736_ISR_PRI */
#if defined(EE_PPCE200ZX_737_ISR_PRI)
  EE_spc574k_set_external_priority(737U, EE_PPCE200ZX_737_ISR_PRI);
#endif /* EE_PPCE200ZX_737_ISR_PRI */
#if defined(EE_PPCE200ZX_738_ISR_PRI)
  EE_spc574k_set_external_priority(738U, EE_PPCE200ZX_738_ISR_PRI);
#endif /* EE_PPCE200ZX_738_ISR_PRI */
#if defined(EE_PPCE200ZX_739_ISR_PRI)
  EE_spc574k_set_external_priority(739U, EE_PPCE200ZX_739_ISR_PRI);
#endif /* EE_PPCE200ZX_739_ISR_PRI */
#if defined(EE_PPCE200ZX_740_ISR_PRI)
  EE_spc574k_set_external_priority(740U, EE_PPCE200ZX_740_ISR_PRI);
#endif /* EE_PPCE200ZX_740_ISR_PRI */
#if defined(EE_PPCE200ZX_741_ISR_PRI)
  EE_spc574k_set_external_priority(741U, EE_PPCE200ZX_741_ISR_PRI);
#endif /* EE_PPCE200ZX_741_ISR_PRI */
#if defined(EE_PPCE200ZX_742_ISR_PRI)
  EE_spc574k_set_external_priority(742U, EE_PPCE200ZX_742_ISR_PRI);
#endif /* EE_PPCE200ZX_742_ISR_PRI */
#if defined(EE_PPCE200ZX_743_ISR_PRI)
  EE_spc574k_set_external_priority(743U, EE_PPCE200ZX_743_ISR_PRI);
#endif /* EE_PPCE200ZX_743_ISR_PRI */
#if defined(EE_PPCE200ZX_744_ISR_PRI)
  EE_spc574k_set_external_priority(744U, EE_PPCE200ZX_744_ISR_PRI);
#endif /* EE_PPCE200ZX_744_ISR_PRI */
#if defined(EE_PPCE200ZX_745_ISR_PRI)
  EE_spc574k_set_external_priority(745U, EE_PPCE200ZX_745_ISR_PRI);
#endif /* EE_PPCE200ZX_745_ISR_PRI */
#if defined(EE_PPCE200ZX_746_ISR_PRI)
  EE_spc574k_set_external_priority(746U, EE_PPCE200ZX_746_ISR_PRI);
#endif /* EE_PPCE200ZX_746_ISR_PRI */
#if defined(EE_PPCE200ZX_747_ISR_PRI)
  EE_spc574k_set_external_priority(747U, EE_PPCE200ZX_747_ISR_PRI);
#endif /* EE_PPCE200ZX_747_ISR_PRI */
#if defined(EE_PPCE200ZX_748_ISR_PRI)
  EE_spc574k_set_external_priority(748U, EE_PPCE200ZX_748_ISR_PRI);
#endif /* EE_PPCE200ZX_748_ISR_PRI */
#if defined(EE_PPCE200ZX_749_ISR_PRI)
  EE_spc574k_set_external_priority(749U, EE_PPCE200ZX_749_ISR_PRI);
#endif /* EE_PPCE200ZX_749_ISR_PRI */
#if defined(EE_PPCE200ZX_750_ISR_PRI)
  EE_spc574k_set_external_priority(750U, EE_PPCE200ZX_750_ISR_PRI);
#endif /* EE_PPCE200ZX_750_ISR_PRI */
#if defined(EE_PPCE200ZX_751_ISR_PRI)
  EE_spc574k_set_external_priority(751U, EE_PPCE200ZX_751_ISR_PRI);
#endif /* EE_PPCE200ZX_751_ISR_PRI */
#if defined(EE_PPCE200ZX_752_ISR_PRI)
  EE_spc574k_set_external_priority(752U, EE_PPCE200ZX_752_ISR_PRI);
#endif /* EE_PPCE200ZX_752_ISR_PRI */
#if defined(EE_PPCE200ZX_753_ISR_PRI)
  EE_spc574k_set_external_priority(753U, EE_PPCE200ZX_753_ISR_PRI);
#endif /* EE_PPCE200ZX_753_ISR_PRI */
#if defined(EE_PPCE200ZX_754_ISR_PRI)
  EE_spc574k_set_external_priority(754U, EE_PPCE200ZX_754_ISR_PRI);
#endif /* EE_PPCE200ZX_754_ISR_PRI */
#if defined(EE_PPCE200ZX_755_ISR_PRI)
  EE_spc574k_set_external_priority(755U, EE_PPCE200ZX_755_ISR_PRI);
#endif /* EE_PPCE200ZX_755_ISR_PRI */
#if defined(EE_PPCE200ZX_756_ISR_PRI)
  EE_spc574k_set_external_priority(756U, EE_PPCE200ZX_756_ISR_PRI);
#endif /* EE_PPCE200ZX_756_ISR_PRI */
#if defined(EE_PPCE200ZX_757_ISR_PRI)
  EE_spc574k_set_external_priority(757U, EE_PPCE200ZX_757_ISR_PRI);
#endif /* EE_PPCE200ZX_757_ISR_PRI */
#if defined(EE_PPCE200ZX_758_ISR_PRI)
  EE_spc574k_set_external_priority(758U, EE_PPCE200ZX_758_ISR_PRI);
#endif /* EE_PPCE200ZX_758_ISR_PRI */
#if defined(EE_PPCE200ZX_759_ISR_PRI)
  EE_spc574k_set_external_priority(759U, EE_PPCE200ZX_759_ISR_PRI);
#endif /* EE_PPCE200ZX_759_ISR_PRI */
#if defined(EE_PPCE200ZX_760_ISR_PRI)
  EE_spc574k_set_external_priority(760U, EE_PPCE200ZX_760_ISR_PRI);
#endif /* EE_PPCE200ZX_760_ISR_PRI */
#if defined(EE_PPCE200ZX_761_ISR_PRI)
  EE_spc574k_set_external_priority(761U, EE_PPCE200ZX_761_ISR_PRI);
#endif /* EE_PPCE200ZX_761_ISR_PRI */
#if defined(EE_PPCE200ZX_762_ISR_PRI)
  EE_spc574k_set_external_priority(762U, EE_PPCE200ZX_762_ISR_PRI);
#endif /* EE_PPCE200ZX_762_ISR_PRI */
#if defined(EE_PPCE200ZX_763_ISR_PRI)
  EE_spc574k_set_external_priority(763U, EE_PPCE200ZX_763_ISR_PRI);
#endif /* EE_PPCE200ZX_763_ISR_PRI */
#if defined(EE_PPCE200ZX_764_ISR_PRI)
  EE_spc574k_set_external_priority(764U, EE_PPCE200ZX_764_ISR_PRI);
#endif /* EE_PPCE200ZX_764_ISR_PRI */
#if defined(EE_PPCE200ZX_765_ISR_PRI)
  EE_spc574k_set_external_priority(765U, EE_PPCE200ZX_765_ISR_PRI);
#endif /* EE_PPCE200ZX_765_ISR_PRI */
#if defined(EE_PPCE200ZX_766_ISR_PRI)
  EE_spc574k_set_external_priority(766U, EE_PPCE200ZX_766_ISR_PRI);
#endif /* EE_PPCE200ZX_766_ISR_PRI */
#if defined(EE_PPCE200ZX_767_ISR_PRI)
  EE_spc574k_set_external_priority(767U, EE_PPCE200ZX_767_ISR_PRI);
#endif /* EE_PPCE200ZX_767_ISR_PRI */
#if defined(EE_PPCE200ZX_768_ISR_PRI)
  EE_spc574k_set_external_priority(768U, EE_PPCE200ZX_768_ISR_PRI);
#endif /* EE_PPCE200ZX_768_ISR_PRI */
#if defined(EE_PPCE200ZX_769_ISR_PRI)
  EE_spc574k_set_external_priority(769U, EE_PPCE200ZX_769_ISR_PRI);
#endif /* EE_PPCE200ZX_769_ISR_PRI */
#if defined(EE_PPCE200ZX_770_ISR_PRI)
  EE_spc574k_set_external_priority(770U, EE_PPCE200ZX_770_ISR_PRI);
#endif /* EE_PPCE200ZX_770_ISR_PRI */
#if defined(EE_PPCE200ZX_771_ISR_PRI)
  EE_spc574k_set_external_priority(771U, EE_PPCE200ZX_771_ISR_PRI);
#endif /* EE_PPCE200ZX_771_ISR_PRI */
#if defined(EE_PPCE200ZX_772_ISR_PRI)
  EE_spc574k_set_external_priority(772U, EE_PPCE200ZX_772_ISR_PRI);
#endif /* EE_PPCE200ZX_772_ISR_PRI */
#if defined(EE_PPCE200ZX_773_ISR_PRI)
  EE_spc574k_set_external_priority(773U, EE_PPCE200ZX_773_ISR_PRI);
#endif /* EE_PPCE200ZX_773_ISR_PRI */
#if defined(EE_PPCE200ZX_774_ISR_PRI)
  EE_spc574k_set_external_priority(774U, EE_PPCE200ZX_774_ISR_PRI);
#endif /* EE_PPCE200ZX_774_ISR_PRI */
#if defined(EE_PPCE200ZX_775_ISR_PRI)
  EE_spc574k_set_external_priority(775U, EE_PPCE200ZX_775_ISR_PRI);
#endif /* EE_PPCE200ZX_775_ISR_PRI */
#if defined(EE_PPCE200ZX_776_ISR_PRI)
  EE_spc574k_set_external_priority(776U, EE_PPCE200ZX_776_ISR_PRI);
#endif /* EE_PPCE200ZX_776_ISR_PRI */
#if defined(EE_PPCE200ZX_777_ISR_PRI)
  EE_spc574k_set_external_priority(777U, EE_PPCE200ZX_777_ISR_PRI);
#endif /* EE_PPCE200ZX_777_ISR_PRI */
#if defined(EE_PPCE200ZX_778_ISR_PRI)
  EE_spc574k_set_external_priority(778U, EE_PPCE200ZX_778_ISR_PRI);
#endif /* EE_PPCE200ZX_778_ISR_PRI */
#if defined(EE_PPCE200ZX_779_ISR_PRI)
  EE_spc574k_set_external_priority(779U, EE_PPCE200ZX_779_ISR_PRI);
#endif /* EE_PPCE200ZX_779_ISR_PRI */
#if defined(EE_PPCE200ZX_780_ISR_PRI)
  EE_spc574k_set_external_priority(780U, EE_PPCE200ZX_780_ISR_PRI);
#endif /* EE_PPCE200ZX_780_ISR_PRI */
#if defined(EE_PPCE200ZX_781_ISR_PRI)
  EE_spc574k_set_external_priority(781U, EE_PPCE200ZX_781_ISR_PRI);
#endif /* EE_PPCE200ZX_781_ISR_PRI */
#if defined(EE_PPCE200ZX_782_ISR_PRI)
  EE_spc574k_set_external_priority(782U, EE_PPCE200ZX_782_ISR_PRI);
#endif /* EE_PPCE200ZX_782_ISR_PRI */
#if defined(EE_PPCE200ZX_783_ISR_PRI)
  EE_spc574k_set_external_priority(783U, EE_PPCE200ZX_783_ISR_PRI);
#endif /* EE_PPCE200ZX_783_ISR_PRI */
#if defined(EE_PPCE200ZX_784_ISR_PRI)
  EE_spc574k_set_external_priority(784U, EE_PPCE200ZX_784_ISR_PRI);
#endif /* EE_PPCE200ZX_784_ISR_PRI */
#if defined(EE_PPCE200ZX_785_ISR_PRI)
  EE_spc574k_set_external_priority(785U, EE_PPCE200ZX_785_ISR_PRI);
#endif /* EE_PPCE200ZX_785_ISR_PRI */
#if defined(EE_PPCE200ZX_786_ISR_PRI)
  EE_spc574k_set_external_priority(786U, EE_PPCE200ZX_786_ISR_PRI);
#endif /* EE_PPCE200ZX_786_ISR_PRI */
#if defined(EE_PPCE200ZX_787_ISR_PRI)
  EE_spc574k_set_external_priority(787U, EE_PPCE200ZX_787_ISR_PRI);
#endif /* EE_PPCE200ZX_787_ISR_PRI */
#if defined(EE_PPCE200ZX_788_ISR_PRI)
  EE_spc574k_set_external_priority(788U, EE_PPCE200ZX_788_ISR_PRI);
#endif /* EE_PPCE200ZX_788_ISR_PRI */
#if defined(EE_PPCE200ZX_789_ISR_PRI)
  EE_spc574k_set_external_priority(789U, EE_PPCE200ZX_789_ISR_PRI);
#endif /* EE_PPCE200ZX_789_ISR_PRI */
#if defined(EE_PPCE200ZX_790_ISR_PRI)
  EE_spc574k_set_external_priority(790U, EE_PPCE200ZX_790_ISR_PRI);
#endif /* EE_PPCE200ZX_790_ISR_PRI */
#if defined(EE_PPCE200ZX_791_ISR_PRI)
  EE_spc574k_set_external_priority(791U, EE_PPCE200ZX_791_ISR_PRI);
#endif /* EE_PPCE200ZX_791_ISR_PRI */
#if defined(EE_PPCE200ZX_792_ISR_PRI)
  EE_spc574k_set_external_priority(792U, EE_PPCE200ZX_792_ISR_PRI);
#endif /* EE_PPCE200ZX_792_ISR_PRI */
#if defined(EE_PPCE200ZX_793_ISR_PRI)
  EE_spc574k_set_external_priority(793U, EE_PPCE200ZX_793_ISR_PRI);
#endif /* EE_PPCE200ZX_793_ISR_PRI */
#if defined(EE_PPCE200ZX_794_ISR_PRI)
  EE_spc574k_set_external_priority(794U, EE_PPCE200ZX_794_ISR_PRI);
#endif /* EE_PPCE200ZX_794_ISR_PRI */
#if defined(EE_PPCE200ZX_795_ISR_PRI)
  EE_spc574k_set_external_priority(795U, EE_PPCE200ZX_795_ISR_PRI);
#endif /* EE_PPCE200ZX_795_ISR_PRI */
#if defined(EE_PPCE200ZX_796_ISR_PRI)
  EE_spc574k_set_external_priority(796U, EE_PPCE200ZX_796_ISR_PRI);
#endif /* EE_PPCE200ZX_796_ISR_PRI */
#if defined(EE_PPCE200ZX_797_ISR_PRI)
  EE_spc574k_set_external_priority(797U, EE_PPCE200ZX_797_ISR_PRI);
#endif /* EE_PPCE200ZX_797_ISR_PRI */
#if defined(EE_PPCE200ZX_798_ISR_PRI)
  EE_spc574k_set_external_priority(798U, EE_PPCE200ZX_798_ISR_PRI);
#endif /* EE_PPCE200ZX_798_ISR_PRI */
#if defined(EE_PPCE200ZX_799_ISR_PRI)
  EE_spc574k_set_external_priority(799U, EE_PPCE200ZX_799_ISR_PRI);
#endif /* EE_PPCE200ZX_799_ISR_PRI */
#if defined(EE_PPCE200ZX_800_ISR_PRI)
  EE_spc574k_set_external_priority(800U, EE_PPCE200ZX_800_ISR_PRI);
#endif /* EE_PPCE200ZX_800_ISR_PRI */
#if defined(EE_PPCE200ZX_801_ISR_PRI)
  EE_spc574k_set_external_priority(801U, EE_PPCE200ZX_801_ISR_PRI);
#endif /* EE_PPCE200ZX_801_ISR_PRI */
#if defined(EE_PPCE200ZX_802_ISR_PRI)
  EE_spc574k_set_external_priority(802U, EE_PPCE200ZX_802_ISR_PRI);
#endif /* EE_PPCE200ZX_802_ISR_PRI */
#if defined(EE_PPCE200ZX_803_ISR_PRI)
  EE_spc574k_set_external_priority(803U, EE_PPCE200ZX_803_ISR_PRI);
#endif /* EE_PPCE200ZX_803_ISR_PRI */
#if defined(EE_PPCE200ZX_804_ISR_PRI)
  EE_spc574k_set_external_priority(804U, EE_PPCE200ZX_804_ISR_PRI);
#endif /* EE_PPCE200ZX_804_ISR_PRI */
#if defined(EE_PPCE200ZX_805_ISR_PRI)
  EE_spc574k_set_external_priority(805U, EE_PPCE200ZX_805_ISR_PRI);
#endif /* EE_PPCE200ZX_805_ISR_PRI */
#if defined(EE_PPCE200ZX_806_ISR_PRI)
  EE_spc574k_set_external_priority(806U, EE_PPCE200ZX_806_ISR_PRI);
#endif /* EE_PPCE200ZX_806_ISR_PRI */
#if defined(EE_PPCE200ZX_807_ISR_PRI)
  EE_spc574k_set_external_priority(807U, EE_PPCE200ZX_807_ISR_PRI);
#endif /* EE_PPCE200ZX_807_ISR_PRI */
#if defined(EE_PPCE200ZX_808_ISR_PRI)
  EE_spc574k_set_external_priority(808U, EE_PPCE200ZX_808_ISR_PRI);
#endif /* EE_PPCE200ZX_808_ISR_PRI */
#if defined(EE_PPCE200ZX_809_ISR_PRI)
  EE_spc574k_set_external_priority(809U, EE_PPCE200ZX_809_ISR_PRI);
#endif /* EE_PPCE200ZX_809_ISR_PRI */
#if defined(EE_PPCE200ZX_810_ISR_PRI)
  EE_spc574k_set_external_priority(810U, EE_PPCE200ZX_810_ISR_PRI);
#endif /* EE_PPCE200ZX_810_ISR_PRI */
#if defined(EE_PPCE200ZX_811_ISR_PRI)
  EE_spc574k_set_external_priority(811U, EE_PPCE200ZX_811_ISR_PRI);
#endif /* EE_PPCE200ZX_811_ISR_PRI */
#if defined(EE_PPCE200ZX_812_ISR_PRI)
  EE_spc574k_set_external_priority(812U, EE_PPCE200ZX_812_ISR_PRI);
#endif /* EE_PPCE200ZX_812_ISR_PRI */
#if defined(EE_PPCE200ZX_813_ISR_PRI)
  EE_spc574k_set_external_priority(813U, EE_PPCE200ZX_813_ISR_PRI);
#endif /* EE_PPCE200ZX_813_ISR_PRI */
#if defined(EE_PPCE200ZX_814_ISR_PRI)
  EE_spc574k_set_external_priority(814U, EE_PPCE200ZX_814_ISR_PRI);
#endif /* EE_PPCE200ZX_814_ISR_PRI */
#if defined(EE_PPCE200ZX_815_ISR_PRI)
  EE_spc574k_set_external_priority(815U, EE_PPCE200ZX_815_ISR_PRI);
#endif /* EE_PPCE200ZX_815_ISR_PRI */
#if defined(EE_PPCE200ZX_816_ISR_PRI)
  EE_spc574k_set_external_priority(816U, EE_PPCE200ZX_816_ISR_PRI);
#endif /* EE_PPCE200ZX_816_ISR_PRI */
#if defined(EE_PPCE200ZX_817_ISR_PRI)
  EE_spc574k_set_external_priority(817U, EE_PPCE200ZX_817_ISR_PRI);
#endif /* EE_PPCE200ZX_817_ISR_PRI */
#if defined(EE_PPCE200ZX_818_ISR_PRI)
  EE_spc574k_set_external_priority(818U, EE_PPCE200ZX_818_ISR_PRI);
#endif /* EE_PPCE200ZX_818_ISR_PRI */
#if defined(EE_PPCE200ZX_819_ISR_PRI)
  EE_spc574k_set_external_priority(819U, EE_PPCE200ZX_819_ISR_PRI);
#endif /* EE_PPCE200ZX_819_ISR_PRI */
#if defined(EE_PPCE200ZX_820_ISR_PRI)
  EE_spc574k_set_external_priority(820U, EE_PPCE200ZX_820_ISR_PRI);
#endif /* EE_PPCE200ZX_820_ISR_PRI */
#if defined(EE_PPCE200ZX_821_ISR_PRI)
  EE_spc574k_set_external_priority(821U, EE_PPCE200ZX_821_ISR_PRI);
#endif /* EE_PPCE200ZX_821_ISR_PRI */
#if defined(EE_PPCE200ZX_822_ISR_PRI)
  EE_spc574k_set_external_priority(822U, EE_PPCE200ZX_822_ISR_PRI);
#endif /* EE_PPCE200ZX_822_ISR_PRI */
#if defined(EE_PPCE200ZX_823_ISR_PRI)
  EE_spc574k_set_external_priority(823U, EE_PPCE200ZX_823_ISR_PRI);
#endif /* EE_PPCE200ZX_823_ISR_PRI */
#if defined(EE_PPCE200ZX_824_ISR_PRI)
  EE_spc574k_set_external_priority(824U, EE_PPCE200ZX_824_ISR_PRI);
#endif /* EE_PPCE200ZX_824_ISR_PRI */
#if defined(EE_PPCE200ZX_825_ISR_PRI)
  EE_spc574k_set_external_priority(825U, EE_PPCE200ZX_825_ISR_PRI);
#endif /* EE_PPCE200ZX_825_ISR_PRI */
#if defined(EE_PPCE200ZX_826_ISR_PRI)
  EE_spc574k_set_external_priority(826U, EE_PPCE200ZX_826_ISR_PRI);
#endif /* EE_PPCE200ZX_826_ISR_PRI */
#if defined(EE_PPCE200ZX_827_ISR_PRI)
  EE_spc574k_set_external_priority(827U, EE_PPCE200ZX_827_ISR_PRI);
#endif /* EE_PPCE200ZX_827_ISR_PRI */
#if defined(EE_PPCE200ZX_828_ISR_PRI)
  EE_spc574k_set_external_priority(828U, EE_PPCE200ZX_828_ISR_PRI);
#endif /* EE_PPCE200ZX_828_ISR_PRI */
#if defined(EE_PPCE200ZX_829_ISR_PRI)
  EE_spc574k_set_external_priority(829U, EE_PPCE200ZX_829_ISR_PRI);
#endif /* EE_PPCE200ZX_829_ISR_PRI */
#if defined(EE_PPCE200ZX_830_ISR_PRI)
  EE_spc574k_set_external_priority(830U, EE_PPCE200ZX_830_ISR_PRI);
#endif /* EE_PPCE200ZX_830_ISR_PRI */
#if defined(EE_PPCE200ZX_831_ISR_PRI)
  EE_spc574k_set_external_priority(831U, EE_PPCE200ZX_831_ISR_PRI);
#endif /* EE_PPCE200ZX_831_ISR_PRI */
#if defined(EE_PPCE200ZX_832_ISR_PRI)
  EE_spc574k_set_external_priority(832U, EE_PPCE200ZX_832_ISR_PRI);
#endif /* EE_PPCE200ZX_832_ISR_PRI */
#if defined(EE_PPCE200ZX_833_ISR_PRI)
  EE_spc574k_set_external_priority(833U, EE_PPCE200ZX_833_ISR_PRI);
#endif /* EE_PPCE200ZX_833_ISR_PRI */
#if defined(EE_PPCE200ZX_834_ISR_PRI)
  EE_spc574k_set_external_priority(834U, EE_PPCE200ZX_834_ISR_PRI);
#endif /* EE_PPCE200ZX_834_ISR_PRI */
#if defined(EE_PPCE200ZX_835_ISR_PRI)
  EE_spc574k_set_external_priority(835U, EE_PPCE200ZX_835_ISR_PRI);
#endif /* EE_PPCE200ZX_835_ISR_PRI */
#if defined(EE_PPCE200ZX_836_ISR_PRI)
  EE_spc574k_set_external_priority(836U, EE_PPCE200ZX_836_ISR_PRI);
#endif /* EE_PPCE200ZX_836_ISR_PRI */
#if defined(EE_PPCE200ZX_837_ISR_PRI)
  EE_spc574k_set_external_priority(837U, EE_PPCE200ZX_837_ISR_PRI);
#endif /* EE_PPCE200ZX_837_ISR_PRI */
#if defined(EE_PPCE200ZX_838_ISR_PRI)
  EE_spc574k_set_external_priority(838U, EE_PPCE200ZX_838_ISR_PRI);
#endif /* EE_PPCE200ZX_838_ISR_PRI */
#if defined(EE_PPCE200ZX_839_ISR_PRI)
  EE_spc574k_set_external_priority(839U, EE_PPCE200ZX_839_ISR_PRI);
#endif /* EE_PPCE200ZX_839_ISR_PRI */
#if defined(EE_PPCE200ZX_840_ISR_PRI)
  EE_spc574k_set_external_priority(840U, EE_PPCE200ZX_840_ISR_PRI);
#endif /* EE_PPCE200ZX_840_ISR_PRI */
#if defined(EE_PPCE200ZX_841_ISR_PRI)
  EE_spc574k_set_external_priority(841U, EE_PPCE200ZX_841_ISR_PRI);
#endif /* EE_PPCE200ZX_841_ISR_PRI */
#if defined(EE_PPCE200ZX_842_ISR_PRI)
  EE_spc574k_set_external_priority(842U, EE_PPCE200ZX_842_ISR_PRI);
#endif /* EE_PPCE200ZX_842_ISR_PRI */
#if defined(EE_PPCE200ZX_843_ISR_PRI)
  EE_spc574k_set_external_priority(843U, EE_PPCE200ZX_843_ISR_PRI);
#endif /* EE_PPCE200ZX_843_ISR_PRI */
#if defined(EE_PPCE200ZX_844_ISR_PRI)
  EE_spc574k_set_external_priority(844U, EE_PPCE200ZX_844_ISR_PRI);
#endif /* EE_PPCE200ZX_844_ISR_PRI */
#if defined(EE_PPCE200ZX_845_ISR_PRI)
  EE_spc574k_set_external_priority(845U, EE_PPCE200ZX_845_ISR_PRI);
#endif /* EE_PPCE200ZX_845_ISR_PRI */
#if defined(EE_PPCE200ZX_846_ISR_PRI)
  EE_spc574k_set_external_priority(846U, EE_PPCE200ZX_846_ISR_PRI);
#endif /* EE_PPCE200ZX_846_ISR_PRI */
#if defined(EE_PPCE200ZX_847_ISR_PRI)
  EE_spc574k_set_external_priority(847U, EE_PPCE200ZX_847_ISR_PRI);
#endif /* EE_PPCE200ZX_847_ISR_PRI */
#if defined(EE_PPCE200ZX_848_ISR_PRI)
  EE_spc574k_set_external_priority(848U, EE_PPCE200ZX_848_ISR_PRI);
#endif /* EE_PPCE200ZX_848_ISR_PRI */
#if defined(EE_PPCE200ZX_849_ISR_PRI)
  EE_spc574k_set_external_priority(849U, EE_PPCE200ZX_849_ISR_PRI);
#endif /* EE_PPCE200ZX_849_ISR_PRI */
#if defined(EE_PPCE200ZX_850_ISR_PRI)
  EE_spc574k_set_external_priority(850U, EE_PPCE200ZX_850_ISR_PRI);
#endif /* EE_PPCE200ZX_850_ISR_PRI */
#if defined(EE_PPCE200ZX_851_ISR_PRI)
  EE_spc574k_set_external_priority(851U, EE_PPCE200ZX_851_ISR_PRI);
#endif /* EE_PPCE200ZX_851_ISR_PRI */
#if defined(EE_PPCE200ZX_852_ISR_PRI)
  EE_spc574k_set_external_priority(852U, EE_PPCE200ZX_852_ISR_PRI);
#endif /* EE_PPCE200ZX_852_ISR_PRI */
#if defined(EE_PPCE200ZX_853_ISR_PRI)
  EE_spc574k_set_external_priority(853U, EE_PPCE200ZX_853_ISR_PRI);
#endif /* EE_PPCE200ZX_853_ISR_PRI */
#if defined(EE_PPCE200ZX_854_ISR_PRI)
  EE_spc574k_set_external_priority(854U, EE_PPCE200ZX_854_ISR_PRI);
#endif /* EE_PPCE200ZX_854_ISR_PRI */
#if defined(EE_PPCE200ZX_855_ISR_PRI)
  EE_spc574k_set_external_priority(855U, EE_PPCE200ZX_855_ISR_PRI);
#endif /* EE_PPCE200ZX_855_ISR_PRI */
#if defined(EE_PPCE200ZX_856_ISR_PRI)
  EE_spc574k_set_external_priority(856U, EE_PPCE200ZX_856_ISR_PRI);
#endif /* EE_PPCE200ZX_856_ISR_PRI */
#if defined(EE_PPCE200ZX_857_ISR_PRI)
  EE_spc574k_set_external_priority(857U, EE_PPCE200ZX_857_ISR_PRI);
#endif /* EE_PPCE200ZX_857_ISR_PRI */
#if defined(EE_PPCE200ZX_858_ISR_PRI)
  EE_spc574k_set_external_priority(858U, EE_PPCE200ZX_858_ISR_PRI);
#endif /* EE_PPCE200ZX_858_ISR_PRI */
#if defined(EE_PPCE200ZX_859_ISR_PRI)
  EE_spc574k_set_external_priority(859U, EE_PPCE200ZX_859_ISR_PRI);
#endif /* EE_PPCE200ZX_859_ISR_PRI */
#if defined(EE_PPCE200ZX_860_ISR_PRI)
  EE_spc574k_set_external_priority(860U, EE_PPCE200ZX_860_ISR_PRI);
#endif /* EE_PPCE200ZX_860_ISR_PRI */
#if defined(EE_PPCE200ZX_861_ISR_PRI)
  EE_spc574k_set_external_priority(861U, EE_PPCE200ZX_861_ISR_PRI);
#endif /* EE_PPCE200ZX_861_ISR_PRI */
#if defined(EE_PPCE200ZX_862_ISR_PRI)
  EE_spc574k_set_external_priority(862U, EE_PPCE200ZX_862_ISR_PRI);
#endif /* EE_PPCE200ZX_862_ISR_PRI */
#if defined(EE_PPCE200ZX_863_ISR_PRI)
  EE_spc574k_set_external_priority(863U, EE_PPCE200ZX_863_ISR_PRI);
#endif /* EE_PPCE200ZX_863_ISR_PRI */
#if defined(EE_PPCE200ZX_864_ISR_PRI)
  EE_spc574k_set_external_priority(864U, EE_PPCE200ZX_864_ISR_PRI);
#endif /* EE_PPCE200ZX_864_ISR_PRI */
#if defined(EE_PPCE200ZX_865_ISR_PRI)
  EE_spc574k_set_external_priority(865U, EE_PPCE200ZX_865_ISR_PRI);
#endif /* EE_PPCE200ZX_865_ISR_PRI */
#if defined(EE_PPCE200ZX_866_ISR_PRI)
  EE_spc574k_set_external_priority(866U, EE_PPCE200ZX_866_ISR_PRI);
#endif /* EE_PPCE200ZX_866_ISR_PRI */
#if defined(EE_PPCE200ZX_867_ISR_PRI)
  EE_spc574k_set_external_priority(867U, EE_PPCE200ZX_867_ISR_PRI);
#endif /* EE_PPCE200ZX_867_ISR_PRI */
#if defined(EE_PPCE200ZX_868_ISR_PRI)
  EE_spc574k_set_external_priority(868U, EE_PPCE200ZX_868_ISR_PRI);
#endif /* EE_PPCE200ZX_868_ISR_PRI */
#if defined(EE_PPCE200ZX_869_ISR_PRI)
  EE_spc574k_set_external_priority(869U, EE_PPCE200ZX_869_ISR_PRI);
#endif /* EE_PPCE200ZX_869_ISR_PRI */
#if defined(EE_PPCE200ZX_870_ISR_PRI)
  EE_spc574k_set_external_priority(870U, EE_PPCE200ZX_870_ISR_PRI);
#endif /* EE_PPCE200ZX_870_ISR_PRI */
#if defined(EE_PPCE200ZX_871_ISR_PRI)
  EE_spc574k_set_external_priority(871U, EE_PPCE200ZX_871_ISR_PRI);
#endif /* EE_PPCE200ZX_871_ISR_PRI */
#if defined(EE_PPCE200ZX_872_ISR_PRI)
  EE_spc574k_set_external_priority(872U, EE_PPCE200ZX_872_ISR_PRI);
#endif /* EE_PPCE200ZX_872_ISR_PRI */
#if defined(EE_PPCE200ZX_873_ISR_PRI)
  EE_spc574k_set_external_priority(873U, EE_PPCE200ZX_873_ISR_PRI);
#endif /* EE_PPCE200ZX_873_ISR_PRI */
#if defined(EE_PPCE200ZX_874_ISR_PRI)
  EE_spc574k_set_external_priority(874U, EE_PPCE200ZX_874_ISR_PRI);
#endif /* EE_PPCE200ZX_874_ISR_PRI */
#if defined(EE_PPCE200ZX_875_ISR_PRI)
  EE_spc574k_set_external_priority(875U, EE_PPCE200ZX_875_ISR_PRI);
#endif /* EE_PPCE200ZX_875_ISR_PRI */
#if defined(EE_PPCE200ZX_876_ISR_PRI)
  EE_spc574k_set_external_priority(876U, EE_PPCE200ZX_876_ISR_PRI);
#endif /* EE_PPCE200ZX_876_ISR_PRI */
#if defined(EE_PPCE200ZX_877_ISR_PRI)
  EE_spc574k_set_external_priority(877U, EE_PPCE200ZX_877_ISR_PRI);
#endif /* EE_PPCE200ZX_877_ISR_PRI */
#if defined(EE_PPCE200ZX_878_ISR_PRI)
  EE_spc574k_set_external_priority(878U, EE_PPCE200ZX_878_ISR_PRI);
#endif /* EE_PPCE200ZX_878_ISR_PRI */
#if defined(EE_PPCE200ZX_879_ISR_PRI)
  EE_spc574k_set_external_priority(879U, EE_PPCE200ZX_879_ISR_PRI);
#endif /* EE_PPCE200ZX_879_ISR_PRI */
#if defined(EE_PPCE200ZX_880_ISR_PRI)
  EE_spc574k_set_external_priority(880U, EE_PPCE200ZX_880_ISR_PRI);
#endif /* EE_PPCE200ZX_880_ISR_PRI */
#if defined(EE_PPCE200ZX_881_ISR_PRI)
  EE_spc574k_set_external_priority(881U, EE_PPCE200ZX_881_ISR_PRI);
#endif /* EE_PPCE200ZX_881_ISR_PRI */
#if defined(EE_PPCE200ZX_882_ISR_PRI)
  EE_spc574k_set_external_priority(882U, EE_PPCE200ZX_882_ISR_PRI);
#endif /* EE_PPCE200ZX_882_ISR_PRI */
#if defined(EE_PPCE200ZX_883_ISR_PRI)
  EE_spc574k_set_external_priority(883U, EE_PPCE200ZX_883_ISR_PRI);
#endif /* EE_PPCE200ZX_883_ISR_PRI */
#if defined(EE_PPCE200ZX_884_ISR_PRI)
  EE_spc574k_set_external_priority(884U, EE_PPCE200ZX_884_ISR_PRI);
#endif /* EE_PPCE200ZX_884_ISR_PRI */
#if defined(EE_PPCE200ZX_885_ISR_PRI)
  EE_spc574k_set_external_priority(885U, EE_PPCE200ZX_885_ISR_PRI);
#endif /* EE_PPCE200ZX_885_ISR_PRI */
#if defined(EE_PPCE200ZX_886_ISR_PRI)
  EE_spc574k_set_external_priority(886U, EE_PPCE200ZX_886_ISR_PRI);
#endif /* EE_PPCE200ZX_886_ISR_PRI */
#if defined(EE_PPCE200ZX_887_ISR_PRI)
  EE_spc574k_set_external_priority(887U, EE_PPCE200ZX_887_ISR_PRI);
#endif /* EE_PPCE200ZX_887_ISR_PRI */
#if defined(EE_PPCE200ZX_888_ISR_PRI)
  EE_spc574k_set_external_priority(888U, EE_PPCE200ZX_888_ISR_PRI);
#endif /* EE_PPCE200ZX_888_ISR_PRI */
#if defined(EE_PPCE200ZX_889_ISR_PRI)
  EE_spc574k_set_external_priority(889U, EE_PPCE200ZX_889_ISR_PRI);
#endif /* EE_PPCE200ZX_889_ISR_PRI */
#if defined(EE_PPCE200ZX_890_ISR_PRI)
  EE_spc574k_set_external_priority(890U, EE_PPCE200ZX_890_ISR_PRI);
#endif /* EE_PPCE200ZX_890_ISR_PRI */
#if defined(EE_PPCE200ZX_891_ISR_PRI)
  EE_spc574k_set_external_priority(891U, EE_PPCE200ZX_891_ISR_PRI);
#endif /* EE_PPCE200ZX_891_ISR_PRI */
#if defined(EE_PPCE200ZX_892_ISR_PRI)
  EE_spc574k_set_external_priority(892U, EE_PPCE200ZX_892_ISR_PRI);
#endif /* EE_PPCE200ZX_892_ISR_PRI */
#if defined(EE_PPCE200ZX_893_ISR_PRI)
  EE_spc574k_set_external_priority(893U, EE_PPCE200ZX_893_ISR_PRI);
#endif /* EE_PPCE200ZX_893_ISR_PRI */
#if defined(EE_PPCE200ZX_894_ISR_PRI)
  EE_spc574k_set_external_priority(894U, EE_PPCE200ZX_894_ISR_PRI);
#endif /* EE_PPCE200ZX_894_ISR_PRI */
#if defined(EE_PPCE200ZX_895_ISR_PRI)
  EE_spc574k_set_external_priority(895U, EE_PPCE200ZX_895_ISR_PRI);
#endif /* EE_PPCE200ZX_895_ISR_PRI */
#if defined(EE_PPCE200ZX_896_ISR_PRI)
  EE_spc574k_set_external_priority(896U, EE_PPCE200ZX_896_ISR_PRI);
#endif /* EE_PPCE200ZX_896_ISR_PRI */
#if defined(EE_PPCE200ZX_897_ISR_PRI)
  EE_spc574k_set_external_priority(897U, EE_PPCE200ZX_897_ISR_PRI);
#endif /* EE_PPCE200ZX_897_ISR_PRI */
#if defined(EE_PPCE200ZX_898_ISR_PRI)
  EE_spc574k_set_external_priority(898U, EE_PPCE200ZX_898_ISR_PRI);
#endif /* EE_PPCE200ZX_898_ISR_PRI */
#if defined(EE_PPCE200ZX_899_ISR_PRI)
  EE_spc574k_set_external_priority(899U, EE_PPCE200ZX_899_ISR_PRI);
#endif /* EE_PPCE200ZX_899_ISR_PRI */
#if defined(EE_PPCE200ZX_900_ISR_PRI)
  EE_spc574k_set_external_priority(900U, EE_PPCE200ZX_900_ISR_PRI);
#endif /* EE_PPCE200ZX_900_ISR_PRI */
#if defined(EE_PPCE200ZX_901_ISR_PRI)
  EE_spc574k_set_external_priority(901U, EE_PPCE200ZX_901_ISR_PRI);
#endif /* EE_PPCE200ZX_901_ISR_PRI */
#if defined(EE_PPCE200ZX_902_ISR_PRI)
  EE_spc574k_set_external_priority(902U, EE_PPCE200ZX_902_ISR_PRI);
#endif /* EE_PPCE200ZX_902_ISR_PRI */
#if defined(EE_PPCE200ZX_903_ISR_PRI)
  EE_spc574k_set_external_priority(903U, EE_PPCE200ZX_903_ISR_PRI);
#endif /* EE_PPCE200ZX_903_ISR_PRI */
#if defined(EE_PPCE200ZX_904_ISR_PRI)
  EE_spc574k_set_external_priority(904U, EE_PPCE200ZX_904_ISR_PRI);
#endif /* EE_PPCE200ZX_904_ISR_PRI */
#if defined(EE_PPCE200ZX_905_ISR_PRI)
  EE_spc574k_set_external_priority(905U, EE_PPCE200ZX_905_ISR_PRI);
#endif /* EE_PPCE200ZX_905_ISR_PRI */
#if defined(EE_PPCE200ZX_906_ISR_PRI)
  EE_spc574k_set_external_priority(906U, EE_PPCE200ZX_906_ISR_PRI);
#endif /* EE_PPCE200ZX_906_ISR_PRI */
#if defined(EE_PPCE200ZX_907_ISR_PRI)
  EE_spc574k_set_external_priority(907U, EE_PPCE200ZX_907_ISR_PRI);
#endif /* EE_PPCE200ZX_907_ISR_PRI */
#if defined(EE_PPCE200ZX_908_ISR_PRI)
  EE_spc574k_set_external_priority(908U, EE_PPCE200ZX_908_ISR_PRI);
#endif /* EE_PPCE200ZX_908_ISR_PRI */
#if defined(EE_PPCE200ZX_909_ISR_PRI)
  EE_spc574k_set_external_priority(909U, EE_PPCE200ZX_909_ISR_PRI);
#endif /* EE_PPCE200ZX_909_ISR_PRI */
#if defined(EE_PPCE200ZX_910_ISR_PRI)
  EE_spc574k_set_external_priority(910U, EE_PPCE200ZX_910_ISR_PRI);
#endif /* EE_PPCE200ZX_910_ISR_PRI */
#if defined(EE_PPCE200ZX_911_ISR_PRI)
  EE_spc574k_set_external_priority(911U, EE_PPCE200ZX_911_ISR_PRI);
#endif /* EE_PPCE200ZX_911_ISR_PRI */
#if defined(EE_PPCE200ZX_912_ISR_PRI)
  EE_spc574k_set_external_priority(912U, EE_PPCE200ZX_912_ISR_PRI);
#endif /* EE_PPCE200ZX_912_ISR_PRI */
#if defined(EE_PPCE200ZX_913_ISR_PRI)
  EE_spc574k_set_external_priority(913U, EE_PPCE200ZX_913_ISR_PRI);
#endif /* EE_PPCE200ZX_913_ISR_PRI */
#if defined(EE_PPCE200ZX_914_ISR_PRI)
  EE_spc574k_set_external_priority(914U, EE_PPCE200ZX_914_ISR_PRI);
#endif /* EE_PPCE200ZX_914_ISR_PRI */
#if defined(EE_PPCE200ZX_915_ISR_PRI)
  EE_spc574k_set_external_priority(915U, EE_PPCE200ZX_915_ISR_PRI);
#endif /* EE_PPCE200ZX_915_ISR_PRI */
#if defined(EE_PPCE200ZX_916_ISR_PRI)
  EE_spc574k_set_external_priority(916U, EE_PPCE200ZX_916_ISR_PRI);
#endif /* EE_PPCE200ZX_916_ISR_PRI */
#if defined(EE_PPCE200ZX_917_ISR_PRI)
  EE_spc574k_set_external_priority(917U, EE_PPCE200ZX_917_ISR_PRI);
#endif /* EE_PPCE200ZX_917_ISR_PRI */
#if defined(EE_PPCE200ZX_918_ISR_PRI)
  EE_spc574k_set_external_priority(918U, EE_PPCE200ZX_918_ISR_PRI);
#endif /* EE_PPCE200ZX_918_ISR_PRI */
#if defined(EE_PPCE200ZX_919_ISR_PRI)
  EE_spc574k_set_external_priority(919U, EE_PPCE200ZX_919_ISR_PRI);
#endif /* EE_PPCE200ZX_919_ISR_PRI */
#if defined(EE_PPCE200ZX_920_ISR_PRI)
  EE_spc574k_set_external_priority(920U, EE_PPCE200ZX_920_ISR_PRI);
#endif /* EE_PPCE200ZX_920_ISR_PRI */
#if defined(EE_PPCE200ZX_921_ISR_PRI)
  EE_spc574k_set_external_priority(921U, EE_PPCE200ZX_921_ISR_PRI);
#endif /* EE_PPCE200ZX_921_ISR_PRI */
#if defined(EE_PPCE200ZX_922_ISR_PRI)
  EE_spc574k_set_external_priority(922U, EE_PPCE200ZX_922_ISR_PRI);
#endif /* EE_PPCE200ZX_922_ISR_PRI */
#if defined(EE_PPCE200ZX_923_ISR_PRI)
  EE_spc574k_set_external_priority(923U, EE_PPCE200ZX_923_ISR_PRI);
#endif /* EE_PPCE200ZX_923_ISR_PRI */
#if defined(EE_PPCE200ZX_924_ISR_PRI)
  EE_spc574k_set_external_priority(924U, EE_PPCE200ZX_924_ISR_PRI);
#endif /* EE_PPCE200ZX_924_ISR_PRI */
#if defined(EE_PPCE200ZX_925_ISR_PRI)
  EE_spc574k_set_external_priority(925U, EE_PPCE200ZX_925_ISR_PRI);
#endif /* EE_PPCE200ZX_925_ISR_PRI */
#if defined(EE_PPCE200ZX_926_ISR_PRI)
  EE_spc574k_set_external_priority(926U, EE_PPCE200ZX_926_ISR_PRI);
#endif /* EE_PPCE200ZX_926_ISR_PRI */
#if defined(EE_PPCE200ZX_927_ISR_PRI)
  EE_spc574k_set_external_priority(927U, EE_PPCE200ZX_927_ISR_PRI);
#endif /* EE_PPCE200ZX_927_ISR_PRI */
#if defined(EE_PPCE200ZX_928_ISR_PRI)
  EE_spc574k_set_external_priority(928U, EE_PPCE200ZX_928_ISR_PRI);
#endif /* EE_PPCE200ZX_928_ISR_PRI */
#if defined(EE_PPCE200ZX_929_ISR_PRI)
  EE_spc574k_set_external_priority(929U, EE_PPCE200ZX_929_ISR_PRI);
#endif /* EE_PPCE200ZX_929_ISR_PRI */
#if defined(EE_PPCE200ZX_930_ISR_PRI)
  EE_spc574k_set_external_priority(930U, EE_PPCE200ZX_930_ISR_PRI);
#endif /* EE_PPCE200ZX_930_ISR_PRI */
#if defined(EE_PPCE200ZX_931_ISR_PRI)
  EE_spc574k_set_external_priority(931U, EE_PPCE200ZX_931_ISR_PRI);
#endif /* EE_PPCE200ZX_931_ISR_PRI */
#if defined(EE_PPCE200ZX_932_ISR_PRI)
  EE_spc574k_set_external_priority(932U, EE_PPCE200ZX_932_ISR_PRI);
#endif /* EE_PPCE200ZX_932_ISR_PRI */
#if defined(EE_PPCE200ZX_933_ISR_PRI)
  EE_spc574k_set_external_priority(933U, EE_PPCE200ZX_933_ISR_PRI);
#endif /* EE_PPCE200ZX_933_ISR_PRI */
#if defined(EE_PPCE200ZX_934_ISR_PRI)
  EE_spc574k_set_external_priority(934U, EE_PPCE200ZX_934_ISR_PRI);
#endif /* EE_PPCE200ZX_934_ISR_PRI */
#if defined(EE_PPCE200ZX_935_ISR_PRI)
  EE_spc574k_set_external_priority(935U, EE_PPCE200ZX_935_ISR_PRI);
#endif /* EE_PPCE200ZX_935_ISR_PRI */
#if defined(EE_PPCE200ZX_936_ISR_PRI)
  EE_spc574k_set_external_priority(936U, EE_PPCE200ZX_936_ISR_PRI);
#endif /* EE_PPCE200ZX_936_ISR_PRI */
#if defined(EE_PPCE200ZX_937_ISR_PRI)
  EE_spc574k_set_external_priority(937U, EE_PPCE200ZX_937_ISR_PRI);
#endif /* EE_PPCE200ZX_937_ISR_PRI */
#if defined(EE_PPCE200ZX_938_ISR_PRI)
  EE_spc574k_set_external_priority(938U, EE_PPCE200ZX_938_ISR_PRI);
#endif /* EE_PPCE200ZX_938_ISR_PRI */
#if defined(EE_PPCE200ZX_939_ISR_PRI)
  EE_spc574k_set_external_priority(939U, EE_PPCE200ZX_939_ISR_PRI);
#endif /* EE_PPCE200ZX_939_ISR_PRI */
#if defined(EE_PPCE200ZX_940_ISR_PRI)
  EE_spc574k_set_external_priority(940U, EE_PPCE200ZX_940_ISR_PRI);
#endif /* EE_PPCE200ZX_940_ISR_PRI */
#if defined(EE_PPCE200ZX_941_ISR_PRI)
  EE_spc574k_set_external_priority(941U, EE_PPCE200ZX_941_ISR_PRI);
#endif /* EE_PPCE200ZX_941_ISR_PRI */
#if defined(EE_PPCE200ZX_942_ISR_PRI)
  EE_spc574k_set_external_priority(942U, EE_PPCE200ZX_942_ISR_PRI);
#endif /* EE_PPCE200ZX_942_ISR_PRI */
#if defined(EE_PPCE200ZX_943_ISR_PRI)
  EE_spc574k_set_external_priority(943U, EE_PPCE200ZX_943_ISR_PRI);
#endif /* EE_PPCE200ZX_943_ISR_PRI */
#if defined(EE_PPCE200ZX_944_ISR_PRI)
  EE_spc574k_set_external_priority(944U, EE_PPCE200ZX_944_ISR_PRI);
#endif /* EE_PPCE200ZX_944_ISR_PRI */
#if defined(EE_PPCE200ZX_945_ISR_PRI)
  EE_spc574k_set_external_priority(945U, EE_PPCE200ZX_945_ISR_PRI);
#endif /* EE_PPCE200ZX_945_ISR_PRI */
#if defined(EE_PPCE200ZX_946_ISR_PRI)
  EE_spc574k_set_external_priority(946U, EE_PPCE200ZX_946_ISR_PRI);
#endif /* EE_PPCE200ZX_946_ISR_PRI */
#if defined(EE_PPCE200ZX_947_ISR_PRI)
  EE_spc574k_set_external_priority(947U, EE_PPCE200ZX_947_ISR_PRI);
#endif /* EE_PPCE200ZX_947_ISR_PRI */
#if defined(EE_PPCE200ZX_948_ISR_PRI)
  EE_spc574k_set_external_priority(948U, EE_PPCE200ZX_948_ISR_PRI);
#endif /* EE_PPCE200ZX_948_ISR_PRI */
#if defined(EE_PPCE200ZX_949_ISR_PRI)
  EE_spc574k_set_external_priority(949U, EE_PPCE200ZX_949_ISR_PRI);
#endif /* EE_PPCE200ZX_949_ISR_PRI */
#if defined(EE_PPCE200ZX_950_ISR_PRI)
  EE_spc574k_set_external_priority(950U, EE_PPCE200ZX_950_ISR_PRI);
#endif /* EE_PPCE200ZX_950_ISR_PRI */
#if defined(EE_PPCE200ZX_951_ISR_PRI)
  EE_spc574k_set_external_priority(951U, EE_PPCE200ZX_951_ISR_PRI);
#endif /* EE_PPCE200ZX_951_ISR_PRI */
#if defined(EE_PPCE200ZX_952_ISR_PRI)
  EE_spc574k_set_external_priority(952U, EE_PPCE200ZX_952_ISR_PRI);
#endif /* EE_PPCE200ZX_952_ISR_PRI */
#if defined(EE_PPCE200ZX_953_ISR_PRI)
  EE_spc574k_set_external_priority(953U, EE_PPCE200ZX_953_ISR_PRI);
#endif /* EE_PPCE200ZX_953_ISR_PRI */
#if defined(EE_PPCE200ZX_954_ISR_PRI)
  EE_spc574k_set_external_priority(954U, EE_PPCE200ZX_954_ISR_PRI);
#endif /* EE_PPCE200ZX_954_ISR_PRI */
#if defined(EE_PPCE200ZX_955_ISR_PRI)
  EE_spc574k_set_external_priority(955U, EE_PPCE200ZX_955_ISR_PRI);
#endif /* EE_PPCE200ZX_955_ISR_PRI */
#if defined(EE_PPCE200ZX_956_ISR_PRI)
  EE_spc574k_set_external_priority(956U, EE_PPCE200ZX_956_ISR_PRI);
#endif /* EE_PPCE200ZX_956_ISR_PRI */
#if defined(EE_PPCE200ZX_957_ISR_PRI)
  EE_spc574k_set_external_priority(957U, EE_PPCE200ZX_957_ISR_PRI);
#endif /* EE_PPCE200ZX_957_ISR_PRI */
#if defined(EE_PPCE200ZX_958_ISR_PRI)
  EE_spc574k_set_external_priority(958U, EE_PPCE200ZX_958_ISR_PRI);
#endif /* EE_PPCE200ZX_958_ISR_PRI */
#if defined(EE_PPCE200ZX_959_ISR_PRI)
  EE_spc574k_set_external_priority(959U, EE_PPCE200ZX_959_ISR_PRI);
#endif /* EE_PPCE200ZX_959_ISR_PRI */
#if defined(EE_PPCE200ZX_960_ISR_PRI)
  EE_spc574k_set_external_priority(960U, EE_PPCE200ZX_960_ISR_PRI);
#endif /* EE_PPCE200ZX_960_ISR_PRI */
#if defined(EE_PPCE200ZX_961_ISR_PRI)
  EE_spc574k_set_external_priority(961U, EE_PPCE200ZX_961_ISR_PRI);
#endif /* EE_PPCE200ZX_961_ISR_PRI */
}

