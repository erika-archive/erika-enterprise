/*
 * Memory map for Freescale MPC5777c CPU 0 in multicore setup
 * Author: Francesco Esposito
 * Company: Evidence Srl
 * 19-3-2014
 */

MEMORY
{
    /* First 16 KB for boot sector */
	boot:	org = 0x00000000, len = 0x00004000
	iflash:	org = 0x00800000, len = 0x00008000
    /* Use only 64 kB of RAM for master core, (the first RAM block) */
	isram:	org = 0x40000000, len = 0x00010000
}

isram_base = ADDR(isram);
isram_len = SIZEOF(isram);

/* This is an alias to the entry point (in RAM) of the slave core */
EE_e200zx_cpu1_start = 0x40010000;
