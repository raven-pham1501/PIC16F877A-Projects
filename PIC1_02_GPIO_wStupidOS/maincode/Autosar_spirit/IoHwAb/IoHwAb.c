/*
 * File:   IoHwAb.c
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */

#include "IoHwAb.h"
#include "../Dio/Dio.h"

Std_ReturnType IoHwAb_SetLed(IoHwAb_LedIdType led, IoHwAb_LedStateType state)
{
    Dio_LevelType onLevel;
    Dio_LevelType level;

    if (led >= IOHWAB_LED_COUNT) {
        return E_NOT_OK;
    }

    onLevel = (IoHwAb_LedTable[led].polarity == IOHWAB_POLARITY_ACTIVE_LOW) ? DIO_LOW : DIO_HIGH;
    level   = (state == IOHWAB_LED_ON) ? onLevel : ((onLevel == DIO_HIGH) ? DIO_LOW : DIO_HIGH);

    Dio_WriteChannel(IoHwAb_LedTable[led].channel, level);

    return E_OK;
}

Std_ReturnType IoHwAb_ToggleLed(IoHwAb_LedIdType led)
{
    if (led >= IOHWAB_LED_COUNT) {
        return E_NOT_OK;
    }

    (void)Dio_FlipChannel(IoHwAb_LedTable[led].channel);

    return E_OK;
}
