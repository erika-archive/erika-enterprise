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
 * Linker script for Diab compiler, for executables running from RAM on CPU 0.
 * Author: 2010 Fabio Checconi
 *         2011 Bernardo  Dal Seno
 */

SECTIONS
{
	GROUP : {
		.boot : { }

        ee_mcglobalt : {
            *(.text[ErrorHook])
            *(.text[StartupHook])
            *(.text[ErrorHook])
            *(.text[ShutdownHook])
           /* *(.text[PreTaskHook]) */
           /* *(.text[PostTaskHook]) */
            *(.text[ProtectionHook])
            *(.text_vle[ErrorHook])
            *(.text_vle[StartupHook])
            *(.text_vle[ErrorHook])
            *(.text_vle[ShutdownHook])
           /* *(.text_vle[PreTaskHook]) */
           /* *(.text_vle[PostTaskHook]) */
            *(.text_vle[ProtectionHook])
            *(ee_mcglobalt)
        }

		.text : {
			*(ee_kernel_text)
			*(ee_api_text)
			*(.text)
			*(.text_vle)
			*(.init)
			*(.fini)
			*(.rdata)
			*(.rodata)
		}

		ee_smcglobalc = . ;
		ee_mcglobalc : { }
		ee_emcglobalc = . ;

		.sram_text : { }

		.sdata2 : { }
		ee_ssmall_mcglobalc = .;
		ee_small_mcglobalc : { }
		ee_esmall_mcglobalc = .;

		ee_ssbss2 = . ;
		.sbss2 : { }
		ee_esbss2 = . ;

		ee_load_ram = . ;
		ee_sdata = . ;
		.data LOAD(ee_load_ram): {
			*(ee_kernel_data)
			*(ee_api_data)
			*(.data)
		}

		.sdata LOAD(ee_load_ram + ADDR(.sdata) - ADDR(.data)): {
			*(ee_kernel_sdata)
			*(ee_api_sdata)
			*(.sdata)
		}
		ee_smcglobald = . ;
		ee_mcglobald LOAD(ee_load_ram + ADDR(ee_mcglobald) - ADDR(.data)): { }
        ee_small_mcglobald LOAD(ee_load_ram + ADDR(ee_small_mcglobald) - ADDR(.data)): { }
		ee_emcglobald = . ;

		ee_sbss = . ;
		.sbss : {
			*(ee_kernel_sbss)
			*(ee_api_sbss)
			*(.sbss)
		}
        ee_small_mcglobalu LOAD(ee_load_ram + ADDR(ee_small_mcglobalu) - ADDR(.data)): { }
		.bss : {
			*(ee_kernel_bss)
			*(ee_api_bss)
			*(.bss)
		}
        ee_mcglobalu LOAD(ee_load_ram + ADDR(ee_mcglobalu) - ADDR(.data)): { }
		ee_ebss = . ;

		ee_sstack = . ;
		.stack : {
			*(.stack)
		}
		ee_estack = . ;
	} > isram
}
