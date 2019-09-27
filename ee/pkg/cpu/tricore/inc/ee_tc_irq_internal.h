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

 /** @file  ee_tc_irq_internal.h
  *  @brief Header with definition for ISR2 Wrappers generation
  *  @author Errico Guidieri
  *  @date 2012
  */
#ifndef INCLUDE_EE_TC_IRQ_INTERNAL_H__
#define INCLUDE_EE_TC_IRQ_INTERNAL_H__

/* I need cpu internals for multistack global structures */
#include "cpu/tricore/inc/ee_tc_internal.h"
/* I need Kernel inclusion for Common Context and Service Protection */
#include "ee.h"
/* I need Kernel inclusion for IRQ callbacks */
#include "ee_irq.h"
/* Plus I need Common End-ISR Scheduler Implementation */
#include "cpu/common/inc/ee_irqstub.h"
/* Plus I need TriCore IRQ handling defines */
#include "cpu/tricore/inc/ee_tc_irq.h"
/* Include Kernel Data Structures Declarations + Change Protection Set Code +
   Stack Monitoring */
#include "cpu/tricore/inc/ee_tc_mem_prot_internal.h"

#ifdef EE_AS_OSAPPLICATIONS__

#include "kernel/as/inc/ee_as_internal.h"

/* Needed to have a context to return to + the context restoring will
   set back Kernel Protection Set. */
/* I've got lucky since parameter passing registers are D4..D7 for
   non-pointers parameter and A4..A7 for pointer parameters.
   So 3 non-pointer parameters and 3 pointer parameters passed trought
   registers. */
extern void __NEVER_INLINE__ EE_tc_isr2_ar_wrapper(
  EE_FREG const flags,
  ApplicationType const app_from,
  ApplicationType const app_to,
  EE_as_Application_ROM_type const * const app_ROM_ptr,
  EE_ADDR interrupted_sp,
  EE_tc_ISR_handler f);

/* ISR2 support have to be configured when OS Applications are used */
#if defined(EE_MAX_ISR_ID) && (EE_MAX_ISR_ID > 0)

/*
 * With memory protection ISR2 are somehow tricky: we need to execute them in
 * trusted/untrusted mode according to the OS application they belong to, and
 * we must be able to terminate them if necessary. We use one ISR2 stack
 * per application and we maintain a stack of ISR2 descriptors to track
 * the active ISR2s. A complete implementation would use two stacks per
 * application: one for trusted and one for untrusted mode.
 */
__INLINE__ void __ALWAYS_INLINE__ EE_TC_CHANGE_STACK_POINTER
  EE_tc_isr2_wrapper_body(EE_tc_ISR_handler f)
{
  /* In TriCore Architecture the vector table is ordered by priority so ISR
     priority is her ID. After an ISR is taken, her priority value (i.e. her id)
     is automatically loaded, by the hardware, in ICR.CCPN field. */
  register ISRType const isr2_id = (ISRType)EE_tc_get_ICR().bits.CCPN;
  /* Interrupted OS-Application */
  register ApplicationType const app_from = EE_as_active_app;
  /* Get NEW ISR2 Stack Data Structures. The following Data Structures is used
     to save SP and OS-Application for an interrupted ISR2/TASK.
     It is accessed via EE_IRQ_nesting_level (not incremented). */
  register EE_as_ISR_RAM_type * const isr_stack_ptr =
    &EE_as_ISR_stack[EE_hal_get_IRQ_nesting_level()];

  /* The ISR2 ROM is accessed via isr_id */
  register EE_as_ISR_ROM_type const * const isr_rom_ptr =
    &EE_as_ISR_ROM[isr2_id];
  /* ISR2's OS-Application ID (the OS-Application where to switch to) */
  register ApplicationType const app_to = isr_rom_ptr->ApplID;
  /* OS-Application to switch to informations */
  register EE_as_Application_RAM_type * const app_RAM_ptr =
    &EE_as_Application_RAM[app_to];
  register EE_as_Application_ROM_type const * const app_ROM_ptr =
    &EE_as_Application_ROM[app_to];
  /* Interrupted TOS structure pointer */
  register struct EE_TC_TOS * p_interrupted_tos;
  /* Interrupted Stack */
  register EE_ADDR interrupted_sp;

  /* Pause and Update the active TP */
  EE_as_tp_active_pause_and_update_budgets();

  /* [OS287]: Check if the OS-Application to witch current ISR belong is
      Terminated or Restarting, if yes return immediately. */
  /* [OS563]: The OperatingSystem shall not schedule any other Tasks which
      belong to the same OS-Application as the non-trusted caller of the
      service. Also interrupts of Category 2 which belong to the same
      OS-Application shall be disabled during the execution of the service. */
  /* XXX: The following is not a real ISR2 disabling but is the best I can do */
  /* [SWS_Os_00470]: The Operating System module shall limit the inter-arrival
      time of Category 2 ISRs to one per OsIsrTimeFrame. (SRS_Os_11008) */
  /* [SWS_Os_00471]: The Operating System module shall measure the start of an
      OsIsrTimeFrame from the point at which it recognises the interrupt
      (i.e. in the Operating System interrupt wrapper). (SRS_Os_11008) */
  /* [SWS_Os_00048]: If Category 2 interrupt occurs before the end of the
      OsIsrTimeFrame then the Operating System module SHALL NOT not execute the
      user provided ISR AND shall call the ProtectionHook() with
      E_OS_PROTECTION_ARRIVAL. (SRS_Os_11008) */
  if (  (app_RAM_ptr->ApplState == APPLICATION_ACCESSIBLE) &&
        ((app_RAM_ptr->TrustedFunctionCallsCounter == 0U) ||
          (app_ROM_ptr->Mode == EE_MEMPROT_TRUST_MODE)) &&
        EE_as_tp_handle_interarrival(EE_AS_TP_ID_FROM_ISR2(isr2_id))  )
  {
    /* Mask all ISR2s, so I can reenable Interrupts */
    EE_FREG const flags = EE_hal_begin_nested_primitive();
    /* Enable IRQ to reduce ISR1 latency as much as possible */
    EE_hal_enableIRQ();
    /* Switch ORTI ISR2 value */
    EE_ORTI_set_runningisr2(f);

    /* Get the interrupted SP */
    interrupted_sp = EE_tc_get_prev_stack();

    /* Get witch TOS have been interrupted */
    if ( EE_IRQ_nesting_level > 0U ) {
      p_interrupted_tos = &EE_tc_system_tos[EE_as_Application_ROM[app_from].
        ISRTOS];
      /* Save the previous ISR TOS */
      p_interrupted_tos->ram_tos = interrupted_sp;
    } else {
      p_interrupted_tos = &EE_tc_system_tos[EE_tc_active_tos];
    }

    /* Increment nesting level here after ISR Stack Access */
    EE_increment_IRQ_nesting_level();
    /* Save interrupted "Top Of Stack" (TASK or ISR2) to be restored. */
    isr_stack_ptr->TerminationTOS   = p_interrupted_tos->ram_tos;
    /* Save Interrupted OS-Application */
    isr_stack_ptr->Interrupted_App  = app_from;
    /* Save the ID of this ISR to be retrieved by GetISRID() Kernel Function.
       It's used even to flag if an ISR need to be Terminated
       (not yet supported). */
    isr_stack_ptr->ISR_ID           = isr2_id;

    /* Save Info for TerminateISR: I need to save a context to switch back to
       and there's only explicit lower context saving instruction.
       Even though we will use a call to wrap the ISR2 body call, I cannot use
       the context of that call as returning point, since we want to return
       from that call to re-enter in Kernel Protection Set without a syscall.
       This will release the context and generate a race condition long a bunch
       of instructions (those needed to raise ICR.CCPN with
       EE_hal_begin_nested_primitive) where an ISR2 could nest and mess with
       CSA. */
    EE_tc_svlcx();
    /* PCXI Saving */
    isr_stack_ptr->ISR_Terminate_data = EE_tc_get_pcxi();

    /* Set the right execution context */
#if (defined(EE_SERVICE_PROTECTION__))
    if (app_to == KERNEL_OSAPPLICATION) {
      EE_as_set_execution_context(Kernel_Context);
    } else {
      EE_as_set_execution_context(ISR2_Context);
    }
#endif /* EE_SERVICE_PROTECTION__ */

    /* Start the timing protection for the new ISR2 */
    EE_as_tp_active_start_for_ISR2(isr2_id);

    /* Context restoring from this call let us get back to
       Kernel Protection Set without a syscall even for NON-Trusted OS-A. */
    EE_tc_isr2_ar_wrapper(flags, app_from, app_to, app_ROM_ptr,
      interrupted_sp, f);

    /* CSA CONTEXT RESTORING SET BACK KERNEL PROTECTION SET. */

    /* Entering in the Kernel -> Mask ISR2, do not disable interrupts. */
    (void)EE_hal_begin_nested_primitive();
    /* Stop active TP */
    EE_as_tp_active_stop();
    /* Handle ISR2 Rollback and Termination + Scheduling. */
    EE_as_TerminateISR2();
  } else {
    /* Restart old TP's first expiring budget.
       I cannot check and update here because if the budget would be
       terminated I wouldn't be on the right stack to handle it. */
    EE_as_tp_active_set_from_id_with_restart(EE_as_tp_active.active_tp);
  }
}
#else /* EE_MAX_ISR_ID > 0 */
#error You cannot use ISR2 with OSApplications without configuring them!
#endif /* EE_MAX_ISR_ID > 0 */

#else /* EE_AS_OSAPPLICATIONS__ */

#if defined(__OO_ORTI_RUNNINGISR2__) || defined(EE_TIMING_PROTECTION__)
#ifndef EE_TIMING_PROTECTION__
/* Only ORTI local */
#define EE_generate_locals()  \
  register EE_ORTI_runningisr2_type orti_old
#elif (!defined(__OO_ORTI_RUNNINGISR2__))
/* Only Timing Protection locals */
#define EE_generate_locals()                  \
  register TimingProtectionType     old_tp;   \
  register ISRType                  isr2_id
#else /* !EE_TIMING_PROTECTION__ || !__OO_ORTI_RUNNINGISR2__ */
/* Both locals */
#define EE_generate_locals()                  \
  register EE_ORTI_runningisr2_type orti_old; \
  register TimingProtectionType     old_tp;   \
  register ISRType                  isr2_id
#endif /* !EE_TIMING_PROTECTION__ */
#else /* __OO_ORTI_RUNNINGISR2__ || EE_TIMING_PROTECTION__ */
/* No locals */
#define EE_generate_locals()  ((void)0)
#endif /* __OO_ORTI_RUNNINGISR2__ || EE_TIMING_PROTECTION__ */

#ifdef __OO_ORTI_RUNNINGISR2__
/* Keep the old ORTI and switch to new one */
#define EE_ORTI_running_isr2_begin(f)         \
  do {                                        \
    orti_old = EE_ORTI_get_runningisr2();     \
    EE_ORTI_set_runningisr2(f);               \
  } while ( 0 )
/* Restore old ORTI */
#define EE_ORTI_running_isr2_end()  EE_ORTI_set_runningisr2(orti_old)
#else /* __OO_ORTI_RUNNINGISR2__ */
#define EE_ORTI_running_isr2_begin(f) ((void)0)
#define EE_ORTI_running_isr2_end()    ((void)0)
#endif /* __OO_ORTI_RUNNINGISR2__ */

#ifdef EE_TIMING_PROTECTION__
#define EE_tp_active_pause_update_and_save()      \
  do {                                            \
    EE_as_tp_active_pause_and_update_budgets();   \
    isr2_id = (ISRType)EE_tc_get_ICR().bits.CCPN; \
    old_tp = EE_as_tp_active.active_tp;           \
  } while ( 0 )

#define EE_tp_active_old_restart()                    \
  do {                                                \
    EE_as_tp_active_set_from_id_with_restart(old_tp); \
  } while ( 0 )
#else /*  EE_TIMING_PROTECTION__ */
#define EE_tp_active_pause_update_and_save()  ((void)0)
#define EE_tp_active_old_restart()            ((void)0)
#endif /*  EE_TIMING_PROTECTION__ */

#if (!defined(__OO_BCC1__)) && (!defined(__OO_BCC2__)) && \
    (!defined(__OO_ECC1__)) && (!defined(__OO_ECC2__))
#define EE_as_set_execution_context(ctx)  ((void)0)
#endif /* !__OO_BCC1__ && !__OO_BCC2__ && !__OO_ECC1__ && !__OO_ECC2__ */

#if (defined(EE_STACK_MONITORING__)) && (defined(EE_ERIKA_ISR_HANDLING_OFF))
extern void EE_as_monitoring_the_stack( void );
#endif /* EE_STACK_MONITORING__ && EE_ERIKA_ISR_HANDLING_OFF */

__INLINE__ void __ALWAYS_INLINE__ EE_tc_isr2_wrapper_body(EE_tc_ISR_handler f)
{
  /* This macro generate the local variables eventually needed */
  EE_generate_locals();
  /* Update interrupted TP and Pause it, plus save a local reference to
     restore it at the ISR2 end, in case of ISR2 nesting */
  EE_tp_active_pause_update_and_save();
  /* Monitor the preempted stack */
#if (defined(EE_STACK_MONITORING__))
#if (defined(__IRQ_STACK_NEEDED__))
  if (EE_IRQ_nesting_level > 0U) {
    EE_tc_check_and_handle_stack_overflow_with_sp(EE_ISR2_TOS_ID,
      EE_tc_get_SP());
  } else {
    EE_tc_check_and_handle_stack_overflow_with_sp(
      EE_std_thread_tos[EE_stk_queryfirst() + 1], EE_tc_get_prev_stack());
  }
#else /* __IRQ_STACK_NEEDED__ */
  EE_tc_check_and_handle_stack_overflow_with_sp(
    EE_std_thread_tos[EE_stk_queryfirst() + 1], EE_tc_get_SP());
#endif /* __IRQ_STACK_NEEDED__ */
#endif /* EE_STACK_MONITORING__ */
  /* [SWS_Os_00470]: The Operating System module shall limit the inter-arrival
      time of Category 2 ISRs to one per OsIsrTimeFrame. (SRS_Os_11008) */
  /* [SWS_Os_00471]: The Operating System module shall measure the start of an
      OsIsrTimeFrame from the point at which it recognises the interrupt
      (i.e. in the Operating System interrupt wrapper). (SRS_Os_11008) */
  /* [SWS_Os_00048]: If Category 2 interrupt occurs before the end of the
      OsIsrTimeFrame then the Operating System module shall not execute the user
      provided ISR AND shall call the ProtectionHook() with
      E_OS_PROTECTION_ARRIVAL. (SRS_Os_11008) */
  /* Check the interarrival */
  if (EE_as_tp_handle_interarrival(EE_AS_TP_ID_FROM_ISR2(isr2_id)))
  {
#if (defined(EE_SYSTEM_TIMER)) || (defined(__MSRP__))
    EE_TYPEBOOL EE_std_is_disableIRQ_nested = EE_FALSE;
#if (defined(EE_SYSTEM_TIMER))
    EE_std_is_disableIRQ_nested |= (
      EE_tc_get_int_prio() == EE_ISR2_ID_EE_tc_system_timer_handler
    );
#endif  /* EE_SYSTEM_TIMER */
#if (defined(__MSRP__))
    EE_std_is_disableIRQ_nested |= (EE_tc_get_int_prio() == EE_ISR_PRI_1);
#endif /* MSRP */
    /* We don't want to make Kernel ISR2 preemptables */
    if (EE_std_is_disableIRQ_nested) {
      /* Mask all ISR2s */
      (void)EE_hal_begin_nested_primitive();
    }
#endif  /* EE_SYSTEM_TIMER || MSRP */
    /* Increment nesting level here, with IRQ disabled */
    EE_increment_IRQ_nesting_level();
    /* Enable at least ISR1s. */
    EE_hal_enableIRQ();
    /* Keep the old ORTI ISR2 and switch to new one */
    EE_ORTI_running_isr2_begin(f);
    /* Set the context execution at ISR2 */
    EE_as_set_execution_context( ISR2_Context );
    /* Start TP protection for this ISR2 */
    EE_as_tp_active_start_for_ISR2(isr2_id);
#if (defined(__IRQ_STACK_NEEDED__))
    if (EE_IRQ_nesting_level == 1U) {
      /* Switch on NEW ISR2 User Stack */
      EE_tc_set_SP(EE_tc_IRQ_tos.base_stack);
    }
#endif /* __IRQ_STACK_NEEDED__ */
    /* Call The ISR User Handler */
    EE_tc_isr2_call_handler(f);
    /* Entering in the Kernel -> Mask all ISR2s, do not disable interrupts. */
    (void)EE_hal_begin_nested_primitive();
    /* Stop active TP */
    EE_as_tp_active_stop();
    /* ISR2 instance clean-up as requested by AR, must be
       called  before EE_decrement_IRQ_nesting_level */
    EE_std_end_IRQ_post_stub();
    /* Decrement nesting level here, with IRQ disabled */
    EE_decrement_IRQ_nesting_level();
    /* Restore the old ORTI ISR2 value */
    EE_ORTI_running_isr2_end();
    /* If the ISR at the lowest level is ended, restore old
       SP, reset CCPN and call the scheduler. */
    /* Check for scheduling point */
    if (EE_is_inside_ISR_call() == 0) {
      /* Set CCPN to unmask next IRQ, it would have been
         done by RFE but we are not returning yet */
      EE_tc_set_int_prio((EE_TYPEISR2PRIO)EE_ISR_UNMASKED);
      /* Restore task stack pointer if needed */
      EE_tc_set_prev_stack_back();
      /* Call the scheduler */
      EE_std_after_IRQ_schedule();
#if (defined(EE_STACK_MONITORING__))
      /* Monitor The returning Stack */
      EE_as_monitoring_the_stack();
#endif /* EE_STACK_MONITORING__ */
    }
  }
  /* Restore the interrupted timing protection set and restart it */
  EE_tp_active_old_restart();
}
#endif /* EE_AS_OSAPPLICATIONS__ */

/* ISR2 Wrapper Function Body */
#define EE_ISR2_WRAPPER_BODY(f)  EE_tc_isr2_wrapper_body(f)

#endif /* INCLUDE_EE_TC_IRQ_INTERNAL_H__ */

