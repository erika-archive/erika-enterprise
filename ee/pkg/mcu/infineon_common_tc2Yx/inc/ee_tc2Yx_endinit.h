/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2012  Evidence Srl
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

 /** @file   ee_tc2Yx_endinit.h
  *  @brief  ENDINIT Support Must Be Added by One and no more of
  *          Kernel modules, by default is included in start-up
  *          code for Tasking.
  *  @author Errico Guidieri
  *  @date 2012
  */

#ifndef INCLUDE_EE_TC2YX_ENDINIT_H__
#define INCLUDE_EE_TC2YX_ENDINIT_H__

/* Public API must be seen by Kernel internals */
#include "mcu/infineon_common_tc2Yx/inc/ee_tc2Yx_mcu.h"

/* Multicore ENDINIT Support */
#ifdef EE_MASTER_CPU
#if defined(__TASKING__)
#define EE_WDTCPUCON0   SCU_WDTCPU0CON0
#define EE_WDTCPUCON1   SCU_WDTCPU0CON1
#else /* __DCC__ || __GNUC__ */
#define EE_WDTCPUCON0   SCU_WDTCPU0_CON0
#define EE_WDTCPUCON1   SCU_WDTCPU0_CON1
#endif
#elif (EE_CURRENTCPU == 1)
#if defined (__TASKING__)
#define EE_WDTCPUCON0   SCU_WDTCPU1CON0
#define EE_WDTCPUCON1   SCU_WDTCPU1CON1
#else /* __DCC__ || __GNUC__ */
#define EE_WDTCPUCON0   SCU_WDTCPU1_CON0
#define EE_WDTCPUCON1   SCU_WDTCPU1_CON1
#endif
#elif (EE_CURRENTCPU == 2)
#if defined (__TASKING__)
#define EE_WDTCPUCON0   SCU_WDTCPU2CON0
#define EE_WDTCPUCON1   SCU_WDTCPU2CON1
#else /* __DCC__ || __GNUC__ */
#define EE_WDTCPUCON0   SCU_WDTCPU2_CON0
#define EE_WDTCPUCON1   SCU_WDTCPU2_CON1
#endif
#else
#error Unknown CPU ID
#endif

#ifndef __TASKING__
#define SCU_WDTCPU0CON0_type Ifx_SCU_WDTCPU_CON0
#endif

/*************************************************************************
 *
 * FUNCTION:	EE_tc2Yx_getCpuWatchdogPassword
 *
 * DESCRIPTION:	Retrieves the PW bits in the WDT_CON0 register.
 *
 *************************************************************************/

__INLINE__ EE_UINT16 __ALWAYS_INLINE__
  EE_tc2Yx_getCpuWatchdogPassword(void)
{
  EE_UINT16 password;

  /* Read Password from CON0 register
   * !!! NOTE: !!! when read bottom six bit of password are inverted so we have
   * to toggle them before returning password */
  password = EE_WDTCPUCON0.B.PW;
  password ^= 0x003F;

  return password;
}

/*************************************************************************
 *
 * FUNCTION:	EE_tc2Yx_setCpuEndinit
 *
 * DESCRIPTION:	Sets the ENDINIT bit in the WDT_CON0 register.
 *
 *************************************************************************/

__INLINE__ void __ALWAYS_INLINE__
  EE_tc2Yx_setCpuEndinit(EE_UINT16 password)
{
    /* Read Config_0 register */
    Ifx_SCU_WDTCPU_CON0 wdt_con0 = EE_WDTCPUCON0;

    if (wdt_con0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wdt_con0.B.ENDINIT = 1;
        wdt_con0.B.LCK     = 0;
        wdt_con0.B.PW      = password;

        /* Password ready. Store it to WDT_CON0 to unprotect the register */
        EE_WDTCPUCON0.U = wdt_con0.U;
    }

    /* Set ENDINT and set LCK bit in Config_0 register */
    wdt_con0.B.ENDINIT = 1;
    wdt_con0.B.LCK     = 1;
    EE_WDTCPUCON0.U   = wdt_con0.U;

    /* read back ENDINIT and wait until it has been set */
    while (EE_WDTCPUCON0.B.ENDINIT == 0)
    {}

    /*
     * FIXME: old version: removed this line after check:
     * watchdog->CON0.U; */ /* read is required */ /*
     */
}

/*************************************************************************
 *
 * FUNCTION:	EE_tc2Yx_clearCpuEndinit
 *
 * DESCRIPTION:	Clears the ENDINIT bit in the WDT_CON0 register.
 *
 *************************************************************************/

__INLINE__ void __ALWAYS_INLINE__
  EE_tc2Yx_clearCpuEndinit(EE_UINT16 password)
{
    /* Read Config_0 register */
    Ifx_SCU_WDTCPU_CON0 wdt_con0 = EE_WDTCPUCON0;

    if (wdt_con0.B.LCK)
    {
        /* see Table 1 (Pass.word Access Bit Pattern Requirements) */
        wdt_con0.B.ENDINIT = 1;
        wdt_con0.B.LCK     = 0;
        wdt_con0.B.PW      = password;

        /* Password ready. Store it to WDT_CON0 to unprotect the register */
        EE_WDTCPUCON0.U = wdt_con0.U;
    }

    /* Clear ENDINT and set LCK bit in Config_0 register */
    wdt_con0.B.ENDINIT = 0;
    wdt_con0.B.LCK     = 1;
    EE_WDTCPUCON0.U   = wdt_con0.U;

    /* read back ENDINIT and wait until it has been cleared */
    while (EE_WDTCPUCON0.B.ENDINIT == 1)
    {}
}

/*************************************************************************
 *
 * FUNCTION:	EE_tc2Yx_disableCpuWatchdog
 *
 * DESCRIPTION:	Desables the CPU Watchdog.
 *
 *************************************************************************/

__INLINE__ void __ALWAYS_INLINE__
  EE_tc2Yx_disableCpuWatchdog(EE_UINT16 password)
{
    EE_tc2Yx_clearCpuEndinit(password);
    EE_WDTCPUCON1.B.DR = 1;	/* Set DR bit in Config_1 register */
    EE_tc2Yx_setCpuEndinit(password);
}

/*************************************************************************
 *
 * FUNCTION:	EE_tc2Yx_getSafetyWatchdogPassword
 *
 * DESCRIPTION:	Retrieves the PW bits in the WDT_CON0 register.
 *
 *************************************************************************/

__INLINE__ EE_UINT16 __ALWAYS_INLINE__
  EE_tc2Yx_getSafetyWatchdogPassword(void)
{
  EE_UINT16 password;

  /* Read Password from CON0 register
   * !!! NOTE: !!! when read bottom six bit of password are inverted so we have
   * to toggle them before returning password */
  password = SCU_WDTSCON0.B.PW;
  password ^= 0x003F;

  return password;
}

/*************************************************************************
 *
 * FUNCTION:	EE_tc2Yx_setSafetyEndinit
 *
 * DESCRIPTION:	Sets the ENDINIT bit in the WDT_CON0 register.
 *
 *************************************************************************/

__INLINE__ void __ALWAYS_INLINE__
  EE_tc2Yx_setSafetyEndinit(EE_UINT16 password)
{
    /* Read Config_0 register */
    Ifx_SCU_WDTS_CON0 wdt_con0 = SCU_WDTSCON0;

    if (wdt_con0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wdt_con0.B.ENDINIT = 1;
        wdt_con0.B.LCK     = 0;
        wdt_con0.B.PW      = password;

        /* Password ready. Store it to WDT_CON0 to unprotect the register */
        SCU_WDTSCON0.U = wdt_con0.U;
    }

    /* Set ENDINT and set LCK bit in Config_0 register */
    wdt_con0.B.ENDINIT = 1;
    wdt_con0.B.LCK     = 1;
    SCU_WDTSCON0.U   = wdt_con0.U;

    /* read back ENDINIT and wait until it has been set */
    while (SCU_WDTSCON0.B.ENDINIT == 0)
    {}
}

/*************************************************************************
 *
 * FUNCTION:	EE_tc2Yx_clearSafetyEndinit
 *
 * DESCRIPTION:	Clears the ENDINIT bit in the WDT_CON0 register.
 *
 *************************************************************************/

__INLINE__ void __ALWAYS_INLINE__
  EE_tc2Yx_clearSafetyEndinit(EE_UINT16 password)
{
    /* Read Config_0 register */
    Ifx_SCU_WDTS_CON0 wdt_con0 = SCU_WDTSCON0;

    if (wdt_con0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wdt_con0.B.ENDINIT = 1;
        wdt_con0.B.LCK     = 0;
        wdt_con0.B.PW      = password;

        /* Password ready. Store it to WDT_CON0 to unprotect the register */
        SCU_WDTSCON0.U = wdt_con0.U;
    }

    /* Clear ENDINT and set LCK bit in Config_0 register */
    wdt_con0.B.ENDINIT = 0;
    wdt_con0.B.LCK     = 1;
    SCU_WDTSCON0.U   = wdt_con0.U;

    /* read back ENDINIT and wait until it has been set */
    while (SCU_WDTSCON0.B.ENDINIT == 1)
    {}
}

/*************************************************************************
 *
 * FUNCTION:	EE_tc2Yx_disableSafetyWatchdog
 *
 * DESCRIPTION:	Desables the CPU Watchdog.
 *
 *************************************************************************/

__INLINE__ void __ALWAYS_INLINE__
  EE_tc2Yx_disableSafetyWatchdog(EE_UINT16 password)
{
    EE_tc2Yx_clearSafetyEndinit(password);
    SCU_WDTSCON1.B.DR = 1;	/* Set DR bit in Config_1 register */
    EE_tc2Yx_setSafetyEndinit(password);
}

#endif /* INCLUDE_EE_TC2YX_ENDINIT_H__ */
