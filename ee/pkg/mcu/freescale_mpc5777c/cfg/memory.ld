/* Memory map for Freescale MPC5777C */

MEMORY
{
    /* First 64 KB for boot sector (It hosts RCHW signature and boot code)*/
	boot:	org = 0x00000000, len = 0x00010000

    /* 256 KB of Flash memory available in single core configuration */
	iflash:	org = 0x00800000, len = 0x00040000

    /* Use only 64 kB of RAM */
	isram:	org = 0x40000000, len = 0x00010000
}

isram_base = ADDR(isram);
isram_len = SIZEOF(isram);

