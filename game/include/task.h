#ifndef __TASK_H__
#define __TASK_H__

#include "constants/bf_types.h"

typedef void(*TaskCB)(u8 taskId);

typedef struct task_s {
	TaskCB func;

	u8 id;
	u8 priority;
	u8 next;
	u8 prev;
	s16 data[16];

	u32 flags;
}Task;

extern Task gTaskManager[];

void RunTask();
Task* CreateTask(TaskCB func, u8 priority);
void DestroyTask(u8 id);
void ClearTasks();
void SetTaskArgs(u8 taskid, u8 argid, s16 val);

#endif /*__TASK_H__*/
