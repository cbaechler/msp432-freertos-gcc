#ifndef FREERTOS_HOOKS_H_
#define FREERTOS_HOOKS_H_

#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"

void vApplicationTickHook(void);
void vApplicationIdleHook(void);
void vApplicationMallocFailedHook(void);
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char* pcTaskName);
void* malloc(size_t xSize);
void vPreSleepProcessing(uint32_t ulExpectedIdleTime);

#endif /* FREERTOS_HOOKS_H_ */
