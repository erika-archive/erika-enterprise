#ifndef EE_MCU_SPC574K_STM_H
#define EE_MCU_SPC574K_STM_H

/* EE_USE_STM_x is defined at .oil file level */
#if defined __MSRP__
/* Multicore case: IOP=master and Core_0=slave */
#if defined (EE_CURRENTCPU) && (EE_CURRENTCPU == 0)
#define STM_BASE 0xFC070000U	/* STM_2 */
#define ISR_NUMBER 44			/* STM_2 has isr 44 */
#else
#define STM_BASE 0xFC068000U	/* STM_0 */
#define ISR_NUMBER 36			/* STM_0 has isr 36 */
#endif

#else
/* Single core case (ONLY the IOP) */
#define STM_BASE 0xFC070000U	/* STM_2 */
#define ISR_NUMBER 44			/* STM_2 has isr 44 */
#endif /* __MSRP__ */

#define STM_CR	(*(volatile unsigned int *)(STM_BASE))
#define STM_CNT	(*(volatile unsigned int *)(STM_BASE + 0x04U))
#define STM_CCR0	(*(volatile unsigned int *)(STM_BASE + 0x10U))
#define STM_CIR0	(*(volatile unsigned int *)(STM_BASE + 0x14U))
#define STM_CMP0	(*(volatile unsigned int *)(STM_BASE + 0x18U))

__INLINE__ void __ALWAYS_INLINE__ spc574k_STM_freeze_on(void)
{
	STM_CR = (STM_CR | 0x2U);
}

__INLINE__ void __ALWAYS_INLINE__ spc574k_STM_freeze_off(void)
{
	STM_CR = (STM_CR & ~0x2U);
}

__INLINE__ void __ALWAYS_INLINE__ spc574k_STM_set_prescaler(unsigned int val)
{
	STM_CR = (STM_CR | ((val-1)<<8));
}

__INLINE__ void __ALWAYS_INLINE__ spc574k_STM_cmp(unsigned int val)
{
	STM_CMP0 = val;
}

__INLINE__ void __ALWAYS_INLINE__ spc574k_STM_clear_int(void)
{
	STM_CIR0 = 1;
}

__INLINE__ void __ALWAYS_INLINE__ spc574k_STM_set_counter(unsigned int val)
{
	STM_CNT = val;
}

__INLINE__ void __ALWAYS_INLINE__ spc574k_STM_enable(void)
{
	STM_CCR0 = 1;
	STM_CR = (STM_CR | 0x1U);
}

__INLINE__ void __ALWAYS_INLINE__ spc574k_STM_disable(void)
{
	STM_CCR0 = 0;
	STM_CR = (STM_CR & ~0x1U);
}


#endif