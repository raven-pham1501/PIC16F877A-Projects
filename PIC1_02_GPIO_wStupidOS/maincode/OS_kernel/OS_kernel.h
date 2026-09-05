/*
 * File:   OS_Kernel.h
 * Author: Raven Pham
 *
 * Created on August 31, 2026, 3:46 PM
 */
#ifndef OS_KERNEL_H
#define OS_KERNEL_H

#include <stdint.h>
#include <xc.h>

/* XC8 v3.10 exposes only the __nop() intrinsic; keep the classic _NOP()
 * spelling available to every translation unit that includes this header,
 * so an else-terminator (MISRA C Rule 15.7) can invoke a real no-op. */
#ifndef _NOP
#define _NOP()          __nop()
#endif

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

/* Function signature required by every scheduled task. */
typedef void (*OS_TaskFunc)(void);

/* Lifecycle states reported by the scheduler. */
typedef enum {
    OS_TASK_SUSPENDED  = 0u,       
    OS_TASK_READY      = 1u,       
    OS_TASK_RUNNING    = 2u,      
    OS_TASK_OVERTIME   = 3u
} OS_TaskState;

/* Static configuration for one task. */
typedef struct {
    OS_TaskFunc        func;           
    uint8_t            period_ms;      
    uint8_t            deadline_ms; 
} OS_TaskConfig;

/* Mutable runtime data maintained by the kernel. */
typedef struct {
    uint8_t            counter;     
    uint8_t            elapsed;     
    OS_TaskState       state;      
} OS_TaskRuntime;               

/* Initialize all configured tasks before the scheduler starts. */
void        OS_Init(void);

/* Advance task timing; call this function from the timer ISR. */
void        OS_TimerISR(void);

/* Execute all tasks that are ready to run. */
uint8_t     OS_Scheduler(void);

void        OS_Fault_Trap(void);

/* Initialize the timer to generate a periodic 1 ms interrupt for the OS kernel tick. */
extern void OS_InitSystick_ms(void);

/* Return the current state of a task, or SUSPENDED for an invalid ID. */
OS_TaskState OS_GetTaskState(uint8_t taskId);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif /* OS_KERNEL_H */