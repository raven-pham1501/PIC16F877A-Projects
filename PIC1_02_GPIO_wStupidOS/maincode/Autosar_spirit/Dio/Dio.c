/*
 * File:   Dio.c
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */

#include "Dio.h"

void Dio_WriteChannel(Dio_ChannelType channel, Dio_LevelType level)
{
    if (channel >= DIO_CHANNEL_COUNT) {
        return;
    }

    if (level == DIO_HIGH) {
        *(Dio_ChannelTable[channel].portReg) |= Dio_ChannelTable[channel].bitMask;
    } else {
        *(Dio_ChannelTable[channel].portReg) &= (uint8_t)~Dio_ChannelTable[channel].bitMask;
    }
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType channel)
{
    if (channel >= DIO_CHANNEL_COUNT) {
        return DIO_LOW;
    }

    return (*(Dio_ChannelTable[channel].portReg) & Dio_ChannelTable[channel].bitMask) ? DIO_HIGH : DIO_LOW;
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType channel)
{
    if (channel >= DIO_CHANNEL_COUNT) {
        return DIO_LOW;
    }

    *(Dio_ChannelTable[channel].portReg) ^= Dio_ChannelTable[channel].bitMask;

    return (*(Dio_ChannelTable[channel].portReg) & Dio_ChannelTable[channel].bitMask) ? DIO_HIGH : DIO_LOW;
}
