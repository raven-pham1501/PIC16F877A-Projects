/*
 * File:   DevKit_Cfg.c
 * Author: Raven Pham
 *
 * Created on August 31, 2026, 6:38 PM
 */

// ===================== CONFIGURATION INCLUDE =====================
#include "DevKit_Cfg.h"

#include <xc.h>

void    DevKit_Init(void)
{
    ADCON1 = 0x06;    // PCFG3:0 = 0110 -> all PORTA/PORTE pins digital I/O (the 877A way)
    TRISA = 0x00;     // PORTA = output
    PORTA = 0xFF;     // all LEDs active
}




