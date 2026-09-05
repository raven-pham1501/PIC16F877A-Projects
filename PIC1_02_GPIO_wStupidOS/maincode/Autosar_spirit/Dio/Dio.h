/*
 * File:   Dio.h
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */
#ifndef DIO_H
#define DIO_H

#include "Dio_Cfg.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum {
    DIO_LOW  = 0u,
    DIO_HIGH = 1u
} Dio_LevelType;

/* Read/write a single channel by symbolic ID. No caller ever touches
 * PORTx/LATx/bitmask directly -- that knowledge lives only in Dio_Cfg.
 *
 * NOTE: tried "static inline" (fully defined in this header) to shave
 * call-stack depth on PIC16F877A (only an 8-level hardware
 * return-address stack, shared between mainline and ISR). Verified by
 * disassembly that XC8's free-tier backend for this device IGNORES the
 * inline hint at -O0 AND -O1 -- it still emits real CALL/RETURN and
 * still reports the same "possible hardware stack overflow" (1393).
 * Real inlining needs the paid PRO optimizer. Do not retry "static
 * inline" here without re-checking disassembly; it silently does
 * nothing on this toolchain. See main.c's ISR for the fix that
 * actually worked: keep the ISR off this call chain entirely. */
void          Dio_WriteChannel(Dio_ChannelType channel, Dio_LevelType level);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType channel);

/* Returns the channel's level *after* the flip, per the AUTOSAR Dio SWS. */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType channel);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /* DIO_H */
