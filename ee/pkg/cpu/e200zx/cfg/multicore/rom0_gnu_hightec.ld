/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2014  Evidence Srl
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
 * Linker script for GNU GCC compiler, for executables running from flash on CPU 0.
 * Author: 2014, Giuseppe Serano
 */

/* map all used regions to existing memory ares */
REGION_ALIAS("BOOT", iboot)
REGION_ALIAS("CODE", iflash)
REGION_ALIAS("RODATA", iflash)
REGION_ALIAS("RAM", isram)

/* This is an alias to the entry point (in Flash) of the slave core */
EE_e200zx_cpu1_start = 0x01010400;

ENTRY(__start)

SECTIONS
{

	.boot : FLAGS(axvl)
	{
		KEEP(*(.boot_data))
		*(.boot)
	} >BOOT

	/* gather some GCC specific sections */
	.glink : FLAGS(axl)
	{
		*(.glink)
	} > CODE

	.iplt      :
	{
		*(.iplt)
	} > CODE

	.rela.iplt      :
	{
		PROVIDE_HIDDEN (__rela_iplt_start = .);
		*(.rela.iplt)
		*(.rela.dyn)
		PROVIDE_HIDDEN (__rela_iplt_end = .);
	} > CODE

	ee_mcglobalt : FLAGS(axvl)
	{
		*(.text_vle.ErrorHook)
		*(.text_vle.StartupHook)
		*(.text_vle.ShutdownHook)
		/* KEEP(*(.text_vle.PreTaskHook)) */
		/* KEEP(*(.text_vle.PostTaskHook)) */
		*(.text_vle.ProtectionHook)
		*(ee_mcglobalt)
		*(ee_mcglobalt.*)
	} >CODE

	.text : FLAGS(axvl)
	{
		*(ee_kernel_text)
		*(ee_kernel_text.*)
		*(ee_api_text)
		*(ee_api_text.*)
		*(.text_vle)
		*(.text_vle.*)
		*(.init_vle)
		*(.fini_vle)
		*(rdata)
		*(.eini)
		. = ALIGN(16);
	} >CODE

	.rodata : FLAGS(arl)
	{
		*(.rodata)
		*(.rodata.*)
	} >RODATA

	ee_mcglobalc : FLAGS(al)
	{
		ee_smcglobalc = . ;
		*(ee_mcglobalc)
		*(ee_mcglobalc.*)
		ee_emcglobalc = . ;
	} >RODATA


	.sdata2 : FLAGS(arsl)
	{
		_SDA2_BASE_ = 0x8000 ;
		*(.sdata2)
		*(.sdata2.*)
		*(.sbss2)
		*(.sbss2.*)
	} >RODATA

	ee_ssmall_mcglobalc : FLAGS(asl)
	{
		ee_ssmall_mcglobalc = . ;
		*(ee_small_mcglobalc)
		*(ee_small_mcglobalc.*)
		ee_esmall_mcglobalc = . ;
	} >RODATA

	.rom_copy_info : FLAGS(arl)
	{
		PROVIDE(ee_load_ram = . ) ;
	} >RODATA

/*	.data LOAD(ee_load_ram): { } */
	.data : AT(ee_load_ram) FLAGS(awl)
	{
		ee_sdata = . ;
		*(ee_kernel_data)
		*(ee_kernel_data.*)
		*(ee_api_data)
		*(ee_api_data.*)
		*(.data)
		*(.data.*)
	} >RAM

/*	.sdata LOAD(ee_load_ram + ADDR(.sdata) - ADDR(.data)): { } */
	.sdata : AT(ee_load_ram + SIZEOF(.data)) FLAGS(awsl)
	{
		_SDA_BASE_ = 0x8000 ;
		*(.sdata)
		*(.sdata.*)
	} >RAM

/*	ee_mcglobald LOAD(ee_load_ram + ADDR(ee_mcglobald) - ADDR(.data)): { } */
	ee_mcglobald : AT(ee_load_ram + SIZEOF(.data) + SIZEOF(.sdata)) FLAGS(awl)
	{
		ee_smcglobald = . ;
		*(ee_mcglobald)
		*(ee_mcglobald.*)
	} >RAM

/*	ee_small_mcglobald LOAD(ee_load_ram + ADDR(ee_small_mcglobald) - ADDR(.data)): { } */
	ee_small_mcglobald :
	AT(ee_load_ram + SIZEOF(.data) + SIZEOF(.sdata) + SIZEOF(ee_mcglobald))
	FLAGS(awl)
	{
		*(ee_small_mcglobald)
		*(ee_small_mcglobald.*)
		ee_emcglobald = . ;
	} >RAM

	.sbss	(NOLOAD) : FLAGS(aws)
	{
		ee_sbss = . ;
		*(.sbss)
		*(.sbss.*)
	} >RAM

/*      ee_small_mcglobalu LOAD(ee_load_ram + ADDR(ee_small_mcglobalu) - ADDR(.data)): { } */
	ee_small_mcglobalu (NOLOAD): FLAGS(aws)
	{
		*(ee_small_mcglobalu)
		*(ee_small_mcglobalu.*)
	} >RAM

	.bss	(NOLOAD) : FLAGS(aw)
	{
		*(ee_kernel_bss)
		*(ee_kernel_bss.*)
		*(ee_api_bss)
		*(ee_api_bss.*)
		*(.bss)
		*(.bss.*)
	} >RAM

/*      ee_mcglobalu LOAD(ee_load_ram + ADDR(ee_mcglobalu) - ADDR(.data)): { } */
	ee_mcglobalu (NOLOAD) : FLAGS(aw)
	{
		*(ee_mcglobalu)
		*(ee_mcglobalu.*)
		ee_ebss = . ;
	} >RAM

        .stack	(NOLOAD) : ALIGN(16) FLAGS(aw)
	{
		ee_sstack = . ;
		*(.stack)
		ee_estack = . ;
	} >RAM

}
