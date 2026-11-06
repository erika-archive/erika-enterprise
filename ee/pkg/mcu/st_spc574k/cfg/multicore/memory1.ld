/*
 * Memory map for Freescale SPC574K CPU 1 in multicore setup
 * Author: Francesco Esposito
 * Company: Evidence Srl
 * 29-5-2014
 */

MEMORY
{
    /* First 1 KB for boot sector (It hosts RCHW signature and boot code) */
	boot:	org = 0x01010400, len = 0x00000400

    /* 64 KB of Flash memory available for Master core */
	iflash:	org = 0x01010800, len = 0x00010000

    /* Use only 32 kB of RAM. It is the "System RAM", to improve performances use Local RAM" */
	isram:	org = 0x40008000, len = 0x00008000
}

isram_base = ADDR(isram);
isram_len = SIZEOF(isram);
