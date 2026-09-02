/*
 * File:   OS_kernel_Cfg.c
 * Author: Raven Pham
 *
 * Created on August 31, 2026, 6:38 PM
 */

// ===================== CONFIGURATION INCLUDE =====================
#include "OS_kernel_Cfg.h"

/* Task groups are declared here and can be implemented independently. */
extern void task_1ms(void);
extern void task_5ms(void);
extern void task_10ms(void);
extern void task_20ms(void);
extern void task_50ms(void);
extern void task_100ms(void);

const OS_TaskConfig OS_TaskTable[] = {
    /*  function        period_ms   deadline_ms  */
    {   task_1ms,        1,          1   },
    {   task_5ms,        5,          4   },
    {   task_10ms,       10,         8   },
    {   task_20ms,       20,         15  },
    {   task_50ms,       50,         40  },
    {   task_100ms,      100,        80  },
};

const uint8_t OS_NUM_TASKS = sizeof(OS_TaskTable) / sizeof(OS_TaskConfig);

/* Keep the runtime task storage large enough for the configured task table. */
_Static_assert(OS_MAX_TASKS >= (sizeof(OS_TaskTable) / sizeof(OS_TaskTable[0])),
               "OS_MAX_TASKS is insufficient for the number of tasks in OS_TaskTable");