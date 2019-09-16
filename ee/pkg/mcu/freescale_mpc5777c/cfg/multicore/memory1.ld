/*
 * Memory map for Freescale MPC5777c CPU 1 in multicore setup
 * Author: Francesco Esposito
 * Company: Evidence Srl
 * 19-3-2014
 */

MEMORY
{
    /* First 16 KB for boot sector */
	boot:	org = 0x00808000, len = 0x00004000
	iflash:	org = 0x0080C000, len = 0x00008000
    /* Use only 64 kB of RAM for Slave core, (the second RAM block) */
	isram:	org = 0x40010000, len = 0x00010000
}

isram_base = ADDR(isram);
isram_len = SIZEOF(isram);
