/*
 * File:   IoHwAb_Cfg.c
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */

// ===================== CONFIGURATION INCLUDE =====================
#include "IoHwAb_Cfg.h"

/* Order must match IoHwAb_LedIdType.
 * NOTE: LED_02/RA4 is wired open-drain (see DevKit_Cfg.h) -- assumed to
 * sink current to turn the LED on, hence ACTIVE_LOW. Verify against the
 * schematic and adjust if the wiring differs. */
const IoHwAb_LedConfigType IoHwAb_LedTable[IOHWAB_LED_COUNT] = {
    { DIO_CHANNEL_LED_01, IOHWAB_POLARITY_ACTIVE_HIGH },  /* IOHWAB_LED_HEARTBEAT */
    { DIO_CHANNEL_LED_02, IOHWAB_POLARITY_ACTIVE_LOW  },  /* IOHWAB_LED_ALIVE */
    { DIO_CHANNEL_LED_03, IOHWAB_POLARITY_ACTIVE_HIGH },  /* IOHWAB_LED_ERROR */
};
