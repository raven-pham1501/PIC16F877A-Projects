/*
 * File:   Port_Cfg.c
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */

// ===================== CONFIGURATION INCLUDE =====================
#include "Port_Cfg.h"

#include <xc.h>

/* Pin table for every channel the Dio layer exposes to the application.
 * NOTE: overlaps with DevKit_Init()'s blanket TRISA=0x00 today. DevKit_Cfg
 * owns one-time board bring-up (oscillator, ADCON1); Port owns direction
 * for the individual channels the Dio/IoHwAb layers manage. */
const Port_PinConfigType Port_PinTable[] = {
    { &TRISA, 0b00001000, PORT_DIR_OUTPUT },  /* RA3 - LED_01 (push-pull) */
    { &TRISA, 0b00010000, PORT_DIR_OUTPUT },  /* RA4 - LED_02 (open-drain) */
    { &TRISA, 0b00100000, PORT_DIR_OUTPUT },  /* RA5 - LED_03 (push-pull) */
};

const uint8_t Port_NUM_PINS = sizeof(Port_PinTable) / sizeof(Port_PinTable[0]);
