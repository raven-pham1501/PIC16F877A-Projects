/*
 * File:   main.c
 * Author: ADMIN
 *
 * Created on August 31, 2026, 3:46 PM
 */

// ===================== CONFIG (PIC16F877A: single config word) =====================
#pragma config FOSC  = HS      // Oscillator: High-Speed crystal/resonator on OSC1/OSC2 (4-20 MHz)
#pragma config WDTE  = OFF     // Watchdog Timer: disabled
#pragma config PWRTE = ON      // Power-up Timer: enabled (~72 ms start-up delay for stable VDD)
#pragma config BOREN = OFF     // Brown-out Reset: disabled
#pragma config LVP   = OFF     // Low-Voltage Programming: disabled -> RB3 is free I/O, use HV programming
#pragma config CPD   = OFF     // Data EEPROM Code Protection: off (EEPROM readable)
#pragma config WRT   = OFF     // Flash self-write protection: off
#pragma config CP    = OFF     // Flash Program Memory Code Protection: off (memory readable)
#pragma config DEBUG = ON      // In-Circuit Debugger: enabled (RB6/RB7 reserved for debugging)
// PIC16F877A has NO MCLRE bit - pin 1 is always MCLR/VPP (still needs a 10k pull-up to +5V)

// ===================== CONFIG INCLUDE =====================
#include <xc.h>
#include "DevKit_definition/DevKit_Cfg.h"
#include "OS_kernel/OS_kernel.h"

// ===================== CONFIG DEVELOPMENT BOARD =====================
#ifndef _XTAL_FREQ
#define _XTAL_FREQ      (DEVKIT_OSC_FREQ)
#endif

/* --------------------------------------------------------------------
 * Timer2: generate a periodic 1 ms interrupt as the OS_Kernel tick.
 *
 * Timing calculation for Fosc = 20 MHz:
 *   Tosc          = 1 / Fosc = 50 ns
 *   Instruction   = 4 * Tosc = 200 ns
 *   Timer2 period = (PR2 + 1) * instruction cycle
 *                   * prescaler * postscaler
 *                 = (249 + 1) * 200 ns * 4 * 5
 *                 = 1,000,000 ns = 1 ms
 *
 * T2CON = 0x25 selects a 1:4 prescaler, a 1:5 postscaler,
 * and enables Timer2. PR2 = 249 sets the timer period register.
 * Adjust PR2, the prescaler, and the postscaler if Fosc changes.
 * -------------------------------------------------------------------- */
void OS_InitSystick_ms(void)
{
    // Set up Timer2 to generate a 1 ms interrupt for the OS kernel tick.
    T2CON = 0x25;   /* Prescaler 1:4, postscaler 1:5, TMR2ON = 1. */
    PR2   = 0xF9;   /* Period register value: 249. */
    PIR1bits.TMR2IF = 0;
    PIE1bits.TMR2IE = 1;

    PEIE = 1;
    GIE  = 1;
}

void __interrupt() ISR(void)
{
    if (PIR1bits.TMR2IF) {
        PIR1bits.TMR2IF = 0;
        PORTA = PORTA ^ DEVKIT_LED_02_ACT;    
        OS_TimerISR();
    }
 
     /* TODO: Handle other interrupts here, such as a future I2C SSPIF.
         Keep interrupt handlers short and do not call tasks directly from an ISR. */
}

int main(void) {

    DevKit_Init();

    OS_Init();

    while (1)
    {

        if (OS_Scheduler()) {
            OS_Fault_Trap();
        }
        else {
            _NOP();
        }
    }

    return 0;
}

void task_1ms(void)
{
    /* TODO: Add tasks that must run every 1 ms. */
    PORTA = PORTA ^ DEVKIT_LED_01_ACT;
}
 
void task_5ms(void)
{
    /* TODO: Add tasks that must run every 5 ms. */
}
 
void task_10ms(void)
{
    /* TODO: Add tasks that must run every 10 ms. */
}
 
void task_20ms(void)
{
    /* TODO: Add tasks that must run every 20 ms. */
}
 
void task_50ms(void)
{
    /* TODO: Add tasks that must run every 50 ms. */
    //PORTA = PORTA ^ DEVKIT_LED_02_ACT;    
}
 
void task_100ms(void)
{
    /* TODO: Add tasks that must run every 100 ms. */
    PORTA = PORTA ^ DEVKIT_LED_03_ACT;
}