/*
 * File:   OS_kernel.c
 * Author: Raven Pham
 *
 * Created on August 31, 2026, 6:38 PM
 */

// ===================== OS KERNEL INCLUDES =====================
#include "OS_kernel.h"
#include "OS_kernel_Cfg.h"

/* Runtime state for every configured task. */
static volatile OS_TaskRuntime OS_TaskRt[OS_MAX_TASKS];

void OS_Init(void)
{
    uint8_t i;
    volatile OS_TaskRuntime *rt  = OS_TaskRt;
    const OS_TaskConfig     *cfg = OS_TaskTable;

    /* Initialize each task and wait for its first release. Walk the tables with
     * incrementing pointers so the compiler never multiplies an index by a
     * non-power-of-two struct size (which would pull in the ___bmul helper and,
     * because this table is also indexed from the ISR, duplicate it: XC8
     * advisory 1510). */
    for (i = 0; i < OS_NUM_TASKS; i++, rt++, cfg++) {
        rt->counter = cfg->period_ms;
        rt->elapsed = 0;
        rt->state   = OS_TASK_SUSPENDED;
    }

    OS_InitSystick_ms();
}

void OS_TimerISR(void)
{
    uint8_t i;
    volatile OS_TaskRuntime *rt  = OS_TaskRt;
    const OS_TaskConfig     *cfg = OS_TaskTable;

    for (i = 0; i < OS_NUM_TASKS; i++, rt++, cfg++) {

        /* Monitor the deadline of tasks that are ready or running. */
        if ((rt->state == OS_TASK_READY) ||
            (rt->state == OS_TASK_RUNNING)) {
            rt->elapsed++;
            if (rt->elapsed >= cfg->deadline_ms) {
                rt->state = OS_TASK_OVERTIME;
            }
        }

        /* Count down to the next task release. Do not silently re-release a
         * task that is latched OVERTIME; it must be handled/cleared first
         * (see OS_Scheduler) so a missed deadline is never lost. */
        if (--rt->counter == 0) {
            rt->counter = cfg->period_ms;
            rt->elapsed = 0;
            if (rt->state != OS_TASK_OVERTIME) {
                rt->state = OS_TASK_READY;
            }
        }
    }
}

uint8_t OS_Scheduler(void)
{
    uint8_t i;
    volatile OS_TaskRuntime *rt  = OS_TaskRt;
    const OS_TaskConfig     *cfg = OS_TaskTable;

    /* Run each task that became ready since the previous scheduler call. */
    for (i = 0; i < OS_NUM_TASKS; i++, rt++, cfg++) {
        if (rt->state == OS_TASK_OVERTIME) {
            /* Acknowledge the latch so the ISR can release this task again
             * on its next period instead of leaving it stuck forever. */
            rt->state = OS_TASK_SUSPENDED;
            return 1;
        }
        else if (rt->state == OS_TASK_READY) {
            rt->state = OS_TASK_RUNNING;

            cfg->func();                 /* Invoke the task through its function pointer. */

            /* Return to SUSPENDED until the next release unless the ISR
             * detected an overtime while the task was running. */
            if (rt->state == OS_TASK_RUNNING) {
                rt->state = OS_TASK_SUSPENDED;
            }
        }
        else {
            /* Task not yet released (SUSPENDED) or mid-run (RUNNING); nothing
             * to do this pass. Explicit else per MISRA C Rule 15.7. */
            _NOP();
        }
    }

    return 0;
}

OS_TaskState OS_GetTaskState(uint8_t taskId)
{
    if (taskId >= OS_NUM_TASKS) {
        return OS_TASK_SUSPENDED;
    }
    return OS_TaskRt[taskId].state;
}

void OS_Fault_Trap(void){
    while(1);
}