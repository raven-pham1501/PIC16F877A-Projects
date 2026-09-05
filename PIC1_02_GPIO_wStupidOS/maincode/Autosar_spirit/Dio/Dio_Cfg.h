/*
 * File:   Dio_Cfg.h
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */
#ifndef DIO_CFG_H
#define DIO_CFG_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/* Symbolic channel IDs. Application/IoHwAb code refers to channels by
 * name only -- never by raw PORT register + bitmask. */
typedef enum {
    DIO_CHANNEL_LED_01 = 0u,
    DIO_CHANNEL_LED_02,
    DIO_CHANNEL_LED_03,
    DIO_CHANNEL_COUNT
} Dio_ChannelType;

typedef struct {
    volatile uint8_t *portReg;
    uint8_t            bitMask;
} Dio_ChannelConfigType;

extern const Dio_ChannelConfigType Dio_ChannelTable[DIO_CHANNEL_COUNT];

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /* DIO_CFG_H */
