/*
 * File:   Dio_Cfg.c
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */

// ===================== CONFIGURATION INCLUDE =====================
#include "Dio_Cfg.h"

#include <xc.h>

/* Order must match Dio_ChannelType. */
const Dio_ChannelConfigType Dio_ChannelTable[DIO_CHANNEL_COUNT] = {
    { &PORTA, 0b00001000 },  /* DIO_CHANNEL_LED_01 - RA3 */
    { &PORTA, 0b00010000 },  /* DIO_CHANNEL_LED_02 - RA4 */
    { &PORTA, 0b00100000 },  /* DIO_CHANNEL_LED_03 - RA5 */
};
