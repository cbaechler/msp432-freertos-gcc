#include "hooks.h"

#ifdef configUSE_TICK_HOOK
void vApplicationTickHook(void) {

}
#endif

void vApplicationIdleHook(void) {

}

#if (configUSE_MALLOC_FAILED_HOOK == 1)
void vApplicationMallocFailedHook(void) {
	taskDISABLE_INTERRUPTS();
	for(;;);
}
#endif

void vApplicationStackOverflowHook(TaskHandle_t pxTask, char* pcTaskName) {
	(void) pcTaskName;
	(void) pxTask;

	taskDISABLE_INTERRUPTS();
	for(;;);
}

void* malloc(size_t xSize) {
	Interrupt_disableMaster();
	for(;;);
}

void vPreSleepProcessing(uint32_t ulExpectedIdleTime) {

}
