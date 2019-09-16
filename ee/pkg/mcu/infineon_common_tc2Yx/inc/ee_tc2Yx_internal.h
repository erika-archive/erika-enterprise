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

 /** @file   ee_tc2Yx_internal.h
  *  @brief  MCU-dependent internal part of HAL
  *  @author Errico Guidieri
  *  @date 2012
  *  @author Giuseppe Serano
  *  @date 2016
  */
#ifndef INCLUDE_EE_TC2YX_INTERNAL_H__
#define INCLUDE_EE_TC2YX_INTERNAL_H__

/* Internals must view MCU API */
#include "mcu/infineon_common_tc2Yx/inc/ee_tc2Yx_mcu.h"
/* Board inclusion for Oscillator Frequency Define EE_TC2YX_BOARD_FOSC */
/* TODO: Protect this with some kind of selector */

#if ( defined(EE_TRIBOARD_TC2X5) || defined(EE_TRIBOARD_TC2XN) )
#include "board/infineon_TriBoard_TC2XN/inc/ee_tc2xN_board.h"
#define EE_SCU_CCUCON0 (EE_TC2YX_CCUCON0_BAUD1DIV(1U) |\
  EE_TC2YX_CCUCON0_SRI(1U) | EE_TC2YX_CCUCON0_SPB(2U) |\
  EE_TC2YX_CCUCON0_FSI2(2U) | EE_TC2YX_CCUCON0_FSI(2U) |\
  EE_TC2YX_CCUCON0_CLKSEL(1U))
#elif defined (EE_APPKIT_TC2X5)
#include "board/infineon_Applikation_Kit_TC2X5/inc/ee_board.h"
#define EE_SCU_CCUCON0 (EE_TC2YX_CCUCON0_BAUD1DIV(1U) |\
  EE_TC2YX_CCUCON0_SRI(1U) | EE_TC2YX_CCUCON0_SPB(2U) |\
  EE_TC2YX_CCUCON0_FSI2(2U) | EE_TC2YX_CCUCON0_FSI(2U) |\
  EE_TC2YX_CCUCON0_CLKSEL(1U) | EE_TC2YX_CCUCON0_BAUD2DIV(1U))
#else
/* Some tests do not define a board, but EE_TC2YX_BOARD_FOSC macro is needed
   I will use the define from EE_TRIBOARD_TC2X5 */
/* Board Oscillator Frequency default (20MHz) - TriBoard quartz */
#define EE_TC2YX_BOARD_FOSC 20000000U
#define EE_SCU_CCUCON0 (EE_TC2YX_CCUCON0_BAUD1DIV(1U) |\
  EE_TC2YX_CCUCON0_SRI(1U) | EE_TC2YX_CCUCON0_SPB(2U) |\
  EE_TC2YX_CCUCON0_FSI2(2U) | EE_TC2YX_CCUCON0_FSI(2U) |\
  EE_TC2YX_CCUCON0_CLKSEL(1U))
#endif

/* Configure EVR (backup clock) frequency */
#if (!defined(EE_EVR_OSC_FREQUENCY))
#define EE_EVR_OSC_FREQUENCY 100000000U
#endif /* !EE_EVR_OSC_FREQUENCY */

/******************************************************************************
               Handle CPU Clock in case of PLL configuration Bypass
*******************************************************************************/
#if (defined(EE_BYPASS_CLOCK_CONFIGURATION)) && (!defined(EE_MM_OPT))
#if (defined(EE_CPU_CLOCK))
#if (EE_CPU_CLOCK != EE_EVR_OSC_FREQUENCY)
#error If EE_BYPASS_CLOCK_CONFIGURATION is configured, CPU_CLOCK have to be\
 equal to EE_EVR_OSC_FREQUENCY (default: 100.0 Mhz)
#endif /* EE_CPU_CLOCK != EE_EVR_OSC_FREQUENCY */
#else
#define EE_CPU_CLOCK  EE_EVR_OSC_FREQUENCY
#endif /* EE_CPU_CLOCK */
#endif /* EE_BYPASS_CLOCK_CONFIGURATION && !EE_MM_OPT */

/** Interrupt table */
extern void EE_tc_interrupt_table ( void );
/** Trap table */
extern void EE_tc_trap_table ( void );

#if (defined(EE_MASTER_CPU)) && (!defined(EE_BYPASS_CLOCK_CONFIGURATION))
/*****************************************************************************
                          CCU Clock Control Support
 ****************************************************************************/

__INLINE__ void __ALWAYS_INLINE__ EE_tc2Yx_configure_clock_ctrl ( void )
{
  /* Configure CCUCON0 */
  SCU_CCUCON0.U = EE_SCU_CCUCON0;

  /* Configure CCUCON1 and Update all CCU */
  SCU_CCUCON1.U = EE_TC2YX_CCUCON1_STMDIV(EE_TC2YX_STMDIV_VALUE) |
    EE_TC2YX_CCUCON1_GTMDIV(1U) | EE_TC2YX_CCUCON1_INSEL(1U) |
    EE_TC2YX_CCUCONX_UP;
}

__INLINE__ void __ALWAYS_INLINE__ EE_tc2Yx_configure_osc_ctrl ( void )
{
  /*
   * Default System Oscillator Configuration
   * MODE:    0   -> External Crystal
   */
  SCU_OSCCON.U= EE_TC2YX_SCU_OSCCON_OSCRES | EE_TC2YX_SCU_OSCCON_GAINSEL |
      EE_TC2YX_SCU_OSCCON_MODE(0U) | EE_TC2YX_SCU_OSCCON_OSCVAL(7U);

  while ( SCU_OSCCON.B.PLLLV == 0U ) {
    ; /* Oscillator not too low */
  }

  while ( SCU_OSCCON.B.PLLHV == 0U ) {
    ; /* Oscillator not too high */
  }
}

/******************************************************************************
                                SCU PLL Support
 *****************************************************************************/
#define EE_TC2YX_FPLL_KSTEP   240000000U
#define EE_TC2YX_FREF_MAX      24000000U
#define EE_TC2YX_FREF_MIN       8000000U
#define EE_TC2YX_FVCO_MAX     800000000U
#define EE_TC2YX_FVCO_MIN     400000000U
#define EE_TC2YX_P_MAX               16U  /* '4 bits */
#define EE_TC2YX_P_MIN                1U
#define EE_TC2YX_K2_MAX              28U  /* '7 bits */
#define EE_TC2YX_K2_MIN               1U
#define EE_TC2YX_N_MAX              128U  /* '7 bits */
#define EE_TC2YX_N_MIN                1U

#define EE_TC2YX_DEV_ALLOWED          2U

__INLINE__ void __ALWAYS_INLINE__ EE_tc2Yx_configure_clock_internal (
    EE_UREG fpll)
{
  /*
   * Dynamic PLL calculation Alg:
   *
   * fPLL = (N /( P * K2))  * fOSC
   *
   */
  EE_UINT32	p;
  EE_UINT32	n;
  EE_UINT32	k2;
  EE_UINT32	k2Steps;
  EE_UINT32	bestK2 = 0;
  EE_UINT32	bestN = 0;
  EE_UINT32	bestP = 0;

  EE_UINT64	fRef;
  EE_UINT64	fVco;
  EE_UINT64	fPllLeastError;
  EE_UINT64	fPllError;

  fPllLeastError = EE_TC2YX_CLOCK_MAX;
  fPllError = EE_TC2YX_CLOCK_MAX;

  /* K2+1 div should be even for 50% duty cycle */
  k2Steps = 2;

  if (fpll > EE_TC2YX_FPLL_KSTEP)
  {
      k2Steps = 1;
  }

  for (
    p = EE_TC2YX_P_MAX;
    ( ( p >= EE_TC2YX_P_MIN ) && ( fPllError != 0 ) );
    p--
  )
  {
    fRef = (EE_TC2YX_BOARD_FOSC / p);

    if ((fRef >= EE_TC2YX_FREF_MIN) && (fRef <= EE_TC2YX_FREF_MAX))
    {
      for (
          k2 = EE_TC2YX_K2_MIN;
          ( ( k2 <= EE_TC2YX_K2_MAX  ) && ( fPllError != 0 ) );
          k2 += k2Steps
        )
      {
        fVco = ((EE_UINT64)fpll) * k2;

        if ((fVco >= EE_TC2YX_FVCO_MIN) && (fVco <= EE_TC2YX_FVCO_MAX))
        {
          for (
              n = EE_TC2YX_N_MIN;
              ( ( n <= EE_TC2YX_N_MAX ) && ( fPllError != 0 ) );
              n++
            )
          {
            fPllError = (
              (((n) / (p * k2)) * EE_TC2YX_BOARD_FOSC) - fpll
            );

            if (fPllError == 0)
            {
              fPllLeastError = fPllError;
              bestK2         = k2;
              bestN          = n;
              bestP          = p;
            }

            if (fPllLeastError > fPllError)
            {
              fPllLeastError = fPllError;
              bestK2         = k2;
              bestN          = n;
              bestP          = p;
            }
          }
        }
      }
    }
  }

  /* percent ALLOWED_DEVIATION error allowed */
  if ((fPllLeastError) < ((fpll * EE_TC2YX_DEV_ALLOWED) / 100))
  {
    /* Divide by K2DIV + 1 */
    SCU_PLLCON1.B.K2DIV = (EE_UINT8)(bestK2 - 1);

    while ( SCU_PLLSTAT.B.K2RDY == 0U ) {
      ; /* Wait until K2-Divider is ready to operate */
    }

    /* K1 divider default value */

    /* Enabled the VCO Bypass Mode */
    SCU_PLLCON0.B.VCOBYP = 1U;

    while ( SCU_PLLSTAT.B.VCOBYST == 0U ) {
      ; /* Wait until prescaler mode is entered */
    }

    /* I will use n=80 and p=2. Because I can get al the
       needed values */
    SCU_PLLCON0.B.PDIV = (EE_UINT8)(bestP - 1);
    SCU_PLLCON0.B.NDIV = (EE_UINT8)(bestN - 1);

    /* power down VCO Normal Behaviour */
    SCU_PLLCON0.B.VCOPWD = 0U;

    /***** Configure PLL normal mode. *****/

    /* Automatic oscillator disconnect disabled */
    SCU_PLLCON0.B.OSCDISCDIS = 1U;
    /* Connect VCO to the oscillator */
    SCU_PLLCON0.B.CLRFINDIS = 1U;

    while ( SCU_PLLSTAT.B.FINDIS == 1U ) {
      ; /* Wait until oscillator is connected to the VCO */
    }

    /* Restart VCO lock detection */
    SCU_PLLCON0.B.RESLD = 1U;

    while ( SCU_PLLSTAT.B.VCOLOCK == 0U ) {
      ; /* Wait until the VCO becomes locked */
    }

    /* Disable the VCO Bypass Mode */
    SCU_PLLCON0.B.VCOBYP = 0U;

    while ( SCU_PLLSTAT.B.VCOBYST == 1U ) {
      ; /* Wait until normal mode is entered */
    }

    /* Automatic oscillator disconnect enabled */
    SCU_PLLCON0.B.OSCDISCDIS = 0U;
  }
} /* EE_tc2Yx_configure_clock_internal() */
#else /* EE_MASTER_CPU && !EE_BYPASS_CLOCK_CONFIGURATION */
__INLINE__ void __ALWAYS_INLINE__ EE_tc2Yx_configure_clock_ctrl ( void ) {}
__INLINE__ void __ALWAYS_INLINE__ EE_tc2Yx_configure_osc_ctrl ( void ) {}
__INLINE__ void __ALWAYS_INLINE__
  EE_tc2Yx_configure_clock_internal ( EE_UREG fpll ) {}
#endif  /* EE_MASTER_CPU && !EE_BYPASS_CLOCK_CONFIGURATION */

/*******************************************************************************
            Software Free Running Timer (SWFRT) (STM implementation)
 ******************************************************************************/
#if (!defined(EE_SWFRT_CCNT))

__INLINE__ EE_UREG __ALWAYS_INLINE__ EE_hal_swfrt_get_current_time ( void )
{
  /* The masking is not needed here, added only because
     it makes easier read tp data structures values */
  return (EE_tc2Yx_stm_get_time_lower_word() & EE_HAL_SWFRT_TIMER_DURATION);
}

__INLINE__ EE_UREG __ALWAYS_INLINE__ EE_hal_swfrt_eval_elapsed_time (
  EE_UREG after, EE_UREG before )
{
  /* Handle the preescaler between CPU and SMT clock with the mask. */
  return ((after - before) & EE_HAL_SWFRT_TIMER_DURATION);
}

__INLINE__ EE_UREG __ALWAYS_INLINE__ EE_hal_swfrt_get_elapsed_time (
  EE_UREG before )
{
  return EE_hal_swfrt_eval_elapsed_time(EE_hal_swfrt_get_current_time(),
    before);
}
#endif /* !EE_SWFRT_CCNT */

#if (defined(EE_TIMING_PROTECTION__))
/*******************************************************************************
                    Timing Protection Internal Support
 ******************************************************************************/
/* XXX: Timing protection will use only TPS_TIMER0. In this way we will have a
        "reference implementation" more portable on multiple architectures */

/* Internal API to deal with TPS_CON Register */
#define EE_TC_TPS_CON_TTRAP         EE_BIT(16)
#define EE_TC_TPS_CON_RESET_TTRAP   (~EE_TC_TPS_CON_TTRAP)
__INLINE__ void __ALWAYS_INLINE__ EE_tc_tps_reset_ttrap ( void )
{
  /* XXX: EG: Probably ALL the following are too much, but just to be
          conservative... */
  EE_UREG tps_con = (EE_tc_get_TPS_CON() & EE_TC_TPS_CON_RESET_TTRAP);
  EE_tc_set_TPS_CON(tps_con);
}

__INLINE__ void __ALWAYS_INLINE__ EE_hal_tp_stop ( void ) {
  /* Write zero on TPS_TIMER registers stop the corresponding timer */
  EE_tc_set_csfr(EE_CPU_REG_TPS_TIMER0, 0U);
}

__INLINE__ EE_UREG __ALWAYS_INLINE__
  EE_hal_tp_get_current_time_and_pause ( void )
{
  /* Write zero on TPS_TIMER registers stop the corresponding timer ( Pause ) */
  EE_tc_set_csfr(EE_CPU_REG_TPS_TIMER0, 0U);
  return EE_hal_swfrt_get_current_time();
}

#if (defined(EE_SWFRT_CCNT))
__INLINE__ void __ALWAYS_INLINE__ EE_hal_tp_set_expiration ( EE_UREG
  expiration )
{
  /* Write zero on TPS_TIMER register something != from zero restart the
     protection */
  EE_tc_set_csfr(EE_CPU_REG_TPS_TIMER0, expiration);
}
#else
__INLINE__ void __ALWAYS_INLINE__ EE_hal_tp_set_expiration ( EE_UREG
  expiration )
{
  /* Instead of CCNT we are using SMT.
     Clock frequency of SMT has a prescaler so in order to set the right ammount
     of bit in TPS, I need to multiply of the prescaler factor.
     XXX: For efficency (I don't want to use division in
     EE_hal_swfrt_eval_elapsed_time) The implementation proposed here works with
     EE_TC2YX_STMDIV_VALUE value of: 1,2,4,8; that are not all the allowed
     values. 5,6,10,12,15 cannot be used */
  EE_tc_set_csfr(EE_CPU_REG_TPS_TIMER0,
    (expiration * EE_TC2YX_STMDIV_VALUE));
}
#endif /* !EE_SWFRT_CCNT */
#endif /* EE_TIMING_PROTECTION__ */

#if defined(__OO_ORTI_STACK__) || defined(EE_STACK_MONITORING__)
/******************************************************************************
                            ORTI Stack Filling
 ******************************************************************************/
/**
  * @brief Fill User Stack and TASKs Private Stacks with known pattern
  *   for monitoring
  */
__INLINE__ void __ALWAYS_INLINE__ EE_tc2Yx_fill_stacks( void )
{
  /* User Stack end */
  extern EE_UINT32 EE_E_USTACK[];
  /* User Stack Base. */
  extern EE_UINT32 EE_B_USTACK[];

#if (defined(__GNUC__) && (!defined(EE_EXECUTE_FROM_RAM))) || defined(__DCC__) 
  /* ERIKA stacks table entry */
  extern EE_UINT32 ee_stacks_table[];
  /* Pointer used to traverse stack table */
  EE_UINT32 *stack_table_ptr;
  /* Actual Stack length (first in bytes then, in words) */
  EE_UINT32 stack_length;
#endif /* (__GNUC__ && !EE_EXECUTE_FROM_RAM) ||  __DCC__*/

  /* Pointer used to traverse stacks */
  register EE_UINT32 * stack_fill_ptr;

  /* Initialize the main stack with fill pattern */
  for(stack_fill_ptr = EE_B_USTACK;
      stack_fill_ptr < EE_E_USTACK; ++stack_fill_ptr)
  {
    *stack_fill_ptr = EE_STACK_FILL_PATTERN;
  }


#if (defined(__GNUC__) && (!defined(EE_EXECUTE_FROM_RAM))) || defined(__DCC__) 
  /* Stack table */
  stack_table_ptr = ee_stacks_table;
  /* Traverse it */
  while (1)
  {
    /* Get a stack section base address */
    stack_fill_ptr = (EE_UINT32 *)*stack_table_ptr;
    /* next field of the table */
    stack_table_ptr++;
    /* Get the stack section length */
    stack_length = *stack_table_ptr;
    
    /* we have finished when next length == -1 */
    if ( stack_length == 0xFFFFFFFFU ) {
      break;
    }

    /* Normalize the length with the variable's size used to fill the stack */
    stack_length = stack_length / (EE_UINT32)sizeof(*stack_fill_ptr);

    while ( stack_length ) {
      *stack_fill_ptr = EE_STACK_FILL_PATTERN;
      stack_length--;
      stack_fill_ptr++;
    }
    /* Prepare to access to next entry on stacks table */
    stack_table_ptr++;
  }
#elif ((!defined(__GNUC__)) && (!defined(__DCC__)) && (!defined(__TASKING__)))\
  && (!defined(EE_EXECUTE_FROM_RAM))
#error Fix Stack Filling code in Other compiler Than GNUC and DCC !
#endif /* (!__GNUC__ && !EE_EXECUTE_FROM_RAM) ||  __DCC__ */
}
#else  /* __OO_ORTI_STACK__ || EE_STACK_MONITORING__ */
/* If ORTI STACKs is not enabled stack filling is not active */
#define EE_tc2Yx_fill_stacks() ((void)0U)
#endif /* __OO_ORTI_STACK__ || EE_STACK_MONITORING__ */

/******************************************************************************
                              System startup
 *****************************************************************************/
/* If system is defined I have to initialize it*/
#if defined(ENABLE_SYSTEM_TIMER) && defined(EE_SYSTEM_TIMER_DEVICE)

void EE_tc2Yx_initialize_system_timer(void);
#else /* ENABLE_SYSTEM_TIMER && EE_SYSTEM_TIMER_DEVICE */
#define EE_tc2Yx_initialize_system_timer() ((void) 0)
#endif /* ENABLE_SYSTEM_TIMER && EE_SYSTEM_TIMER_DEVICE */

/** Initialize a global variable with STM frequency. */
extern void EE_tc2Yx_stm_set_clockpersec ( void );

__INLINE__ EE_TYPEBOOL __ALWAYS_INLINE__ EE_cpu_startos( void )
{
#if (defined(__EE_MEMORY_PROTECTION__) || defined(EE_TIMING_PROTECTION__)) &&\
  (defined(EE_USE_CUSTOM_STARTUP_CODE) || defined(EE_MM_OPT))
  /* In case of "User Boot" and "sytem protections" play SAFE and force
     the set of the right Trap Table. */
  EE_tc_endint_disable();
  EE_tc_set_csfr(EE_CPU_REG_BTV, (EE_UINT32)&EE_tc_trap_table);
  EE_tc_endint_enable();
#endif /* (__EE_MEMORY_PROTECTION__ || EE_TIMING_PROTECTION__) &&
   (EE_USE_CUSTOM_STARTUP_CODE || EE_MM_OPT) */
#if (defined(EE_MASTER_CPU))
#if (!defined(EE_BYPASS_CLOCK_CONFIGURATION))
  /* If a CPU CLOCK frequency is defined configure the SCU registers */
#if (defined(EE_CPU_CLOCK))
  /* Disable SAFETY ENDINIT Protection */
  EE_tc_safety_endinit_disable();

  /********* Configure CCU Clock Control. *********/
  EE_tc2Yx_configure_clock_ctrl();
  /********* Configure Oscillator Control. *********/
  EE_tc2Yx_configure_osc_ctrl();
  /***************** Configure PLL *****************/
  EE_tc2Yx_configure_clock( EE_CPU_CLOCK );

  /* Re-enable SAFETY ENDINIT Protection */
  EE_tc_safety_endinit_enable();
#endif /* EE_CPU_CLOCK */
#endif /* !EE_BYPASS_CLOCK_CONFIGURATION */

  /* Initialize intercore IRQs (in multicore environment) */
  EE_tc2Yx_setup_inter_irqs();
#endif /* EE_MASTER_CPU */

  /* Fill Stacks With Known Path for monitoring usage, if ORTI is enabled */
  EE_tc2Yx_fill_stacks();

  /* Configure hardware for memory protection or timing protection:
     if enabled */
  EE_tc_enable_protections();

  /* Initialize stdlib time reference (or internal variable) with STM
      frequency. */
  EE_tc2Yx_stm_set_clockpersec();
#if (defined(ENABLE_SYSTEM_TIMER))
#if (defined(EE_DEBUG))
  EE_tc2Yx_stm_ocds_suspend_control();
#endif /* EE_DEBUG */
  EE_tc2Yx_initialize_system_timer();
#endif /* ENABLE_SYSTEM_TIMER */

#if (defined(__IRQ_STACK_NEEDED__))
  /* Set User Stack for TASks, in case this is not done in start-up code */
  EE_tc_set_psw_user_stack();
#endif /* __IRQ_STACK_NEEDED__ */

  return 0;
}

#endif /* INCLUDE_EE_TC2YX_INTERNAL_H__ */
