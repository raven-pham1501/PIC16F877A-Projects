/*
 * File:   OS_kernel.c
 * Author: Raven Pham
 *
 * Created on August 31, 2026, 3:46 PM
 */
#ifndef OS_KERNEL_CFG_H
#define OS_KERNEL_CFG_H

#include "OS_kernel.h"

#define OS_MAX_TASKS   10

extern const OS_TaskConfig OS_TaskTable[];
extern const uint8_t       OS_NUM_TASKS;

#endif /* OS_KERNEL_CFG_H */