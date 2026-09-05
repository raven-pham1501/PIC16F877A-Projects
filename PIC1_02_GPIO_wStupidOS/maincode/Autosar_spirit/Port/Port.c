/*
 * File:   Port.c
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */

#include "Port.h"
#include "Port_Cfg.h"

void Port_Init(void)
{
    uint8_t i;

    for (i = 0u; i < Port_NUM_PINS; i++) {
        if (Port_PinTable[i].direction == PORT_DIR_OUTPUT) {
            *(Port_PinTable[i].trisReg) &= (uint8_t)~Port_PinTable[i].bitMask;
        } else {
            *(Port_PinTable[i].trisReg) |= Port_PinTable[i].bitMask;
        }
    }
}
