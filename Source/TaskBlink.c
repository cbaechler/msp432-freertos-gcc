#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

void vBlink(void* pvParameters) {
	while(1) {
		vTaskDelay(250);
		MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
	}
}
