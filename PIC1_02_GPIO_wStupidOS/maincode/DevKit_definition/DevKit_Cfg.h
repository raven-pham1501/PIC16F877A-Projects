/*
 * File:   DevKit_Cfg
 * Author: Raven Pham
 *
 * Created on August 31, 2026, 3:46 PM
 */
#ifndef DEVKIT_CFG_H
#define DEVKIT_CFG_H

//Crystal Oscillator
#define DEVKIT_OSC_FREQ         (20000000UL)

//RA3 - PushPull
#define DEVKIT_LED_01_ACT       (0b00001000)

//RA4 - OpenDrain*
#define DEVKIT_LED_02_ACT       (0b00010000)

//RA5 - PushPull
#define DEVKIT_LED_03_ACT       (0b00100000)

void    DevKit_Init(void);

#endif /* DEVKIT_CFG_H */