/*
 * File:   Std_Types.h
 * Author: Raven Pham
 *
 * Created on September 5, 2026
 */
#ifndef STD_TYPES_H
#define STD_TYPES_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/* Shared across every Autosar_spirit module. */
typedef uint8_t Std_ReturnType;

#define E_OK     ((Std_ReturnType)0x00u)
#define E_NOT_OK ((Std_ReturnType)0x01u)

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /* STD_TYPES_H */
