/**
 * @file tpl_external_interrupts.c
 *
 * @section desc File description
 *
 * External interrupts init and acknowledge functions for blink
 * Automatically generated by goil on Sun Jul 16 15:01:28 2023
 * from root OIL file blink.oil
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence v2
 *
 */

#include "tpl_machine.h"
#include "tpl_cortex_definitions.h"
#include "pinAccess.h"


/*
 * External Interrupts initialization for the STM32F407 Microcontroller
 *
 * Interrupt vectors are EXTI0_IRQ, EXTI1_IRQ, EXTI2_IRQ, EXTI3_IRQ, EXTI4_IRQ
 * EXTI5_9_IRQ and EXTI15_10_IRQ
 *
 * Inits are done according to the source(s) pin(s) selected for an interrupt
 * vector corresponding to an or a set of interrupt(s) line(s)
 */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_init_external_interrupts()
{
// ---

    /* Set the clock for SYSCFG */
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    RCC->APB2ENR; /* force read access */

    /* Set Interrupt Mask Register */


    /* select port associated to each interrupt */

    /* select trigger mode - RISING, FALLIN, BOTH */

// -------------------------------------------------------------------------------------

}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_external_interrupts.c */

