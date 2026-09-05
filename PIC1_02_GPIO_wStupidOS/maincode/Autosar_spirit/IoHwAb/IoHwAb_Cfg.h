/*
 * File:   IoHwAb_Cfg.h
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */
#ifndef IOHWAB_CFG_H
#define IOHWAB_CFG_H

#include "../Dio/Dio_Cfg.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/* Logical LED identities the application asks for. The mapping to a
 * physical Dio channel (and its polarity) is decided only here. */
typedef enum {
    IOHWAB_LED_HEARTBEAT = 0u,   /* task_1ms activity indicator */
    IOHWAB_LED_ALIVE,            /* systick ISR activity indicator */
    IOHWAB_LED_ERROR,            /* task_100ms / fault indicator */
    IOHWAB_LED_COUNT
} IoHwAb_LedIdType;

typedef enum {
    IOHWAB_POLARITY_ACTIVE_HIGH = 0u,
    IOHWAB_POLARITY_ACTIVE_LOW  = 1u
} IoHwAb_PolarityType;

typedef struct {
    Dio_ChannelType     channel;
    IoHwAb_PolarityType polarity;
} IoHwAb_LedConfigType;

extern const IoHwAb_LedConfigType IoHwAb_LedTable[IOHWAB_LED_COUNT];

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /* IOHWAB_CFG_H */
