/* Memory map for Freescale SPC574K */

MEMORY
{
    /* First 1 KB for boot sector (It hosts RCHW signature and boot code) */
	boot:	org = 0x01000000, len = 0x00000400

    /* 255 KB of Flash memory available in single core configuration */
	iflash:	org = 0x01000400, len = 0x0003FC00

    /* Use only 64 kB of RAM. It is the "System RAM", to improve performances use Local RAM" */
	isram:	org = 0x40000000, len = 0x00010000
}

isram_base = ADDR(isram);
isram_len = SIZEOF(isram);

