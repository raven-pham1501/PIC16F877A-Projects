/*
 * File:   IoHwAb.h
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */
#ifndef IOHWAB_H
#define IOHWAB_H

#include "IoHwAb_Cfg.h"
#include "../Std_Types.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum {
    IOHWAB_LED_OFF = 0u,
    IOHWAB_LED_ON  = 1u
} IoHwAb_LedStateType;

/* Application-facing API: talks in "on/off", never in Dio levels or
 * channels. Polarity inversion for open-drain wiring is handled here.
 * Returns E_NOT_OK only for an out-of-range led id (config/programming
 * error) -- never a runtime hardware failure.
 *
 * NOTE: mainline-only. Do NOT call these from the ISR -- see main.c's
 * __interrupt() ISR for why (PIC16F877A's 8-level hardware call stack
 * is shared between mainline and ISR; routing the ISR through
 * IoHwAb->Dio pushed the linker's worst-case call-depth estimate to 9
 * and tripped XC8 warning 1393, "possible hardware stack overflow").
 * "static inline" was tried to shrink this chain and does NOT work on
 * this device's free-tier XC8 backend (verified: still emits a real
 * CALL at both -O0 and -O1) -- don't retry that fix here. */
Std_ReturnType IoHwAb_SetLed(IoHwAb_LedIdType led, IoHwAb_LedStateType state);
Std_ReturnType IoHwAb_ToggleLed(IoHwAb_LedIdType led);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /* IOHWAB_H */
