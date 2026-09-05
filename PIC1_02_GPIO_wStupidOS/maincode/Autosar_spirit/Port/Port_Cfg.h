/*
 * File:   Port_Cfg.h
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */
#ifndef PORT_CFG_H
#define PORT_CFG_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/* Direction requested for a pin at Port_Init() time. */
typedef enum {
    PORT_DIR_OUTPUT = 0u,
    PORT_DIR_INPUT  = 1u
} Port_PinDirectionType;

/* One entry per physical pin managed by the Port layer. */
typedef struct {
    volatile uint8_t     *trisReg;
    uint8_t                bitMask;
    Port_PinDirectionType  direction;
} Port_PinConfigType;

extern const Port_PinConfigType Port_PinTable[];
extern const uint8_t             Port_NUM_PINS;

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /* PORT_CFG_H */
