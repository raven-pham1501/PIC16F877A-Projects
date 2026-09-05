/*
 * File:   Port.h
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */
#ifndef PORT_H
#define PORT_H

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/* Apply the direction configured in Port_Cfg to every managed pin.
 * Call once during system bring-up, after DevKit_Init(). */
void Port_Init(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /* PORT_H */
