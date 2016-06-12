#include <stdio.h>

#include <FreeRTOS.h>
#include <task.h>

static void prvSetupHardware(void);
static void prvConfigureClocks(void);

extern void vBlink(void* pvParameters);

int main(void) {
	prvSetupHardware();
	prvConfigureClocks();

	xTaskCreate(vBlink,						/* The function that implements the task. */
				"BLINK",					/* The text name assigned to the task - for debug only as it is not used by the kernel. */
				configMINIMAL_STACK_SIZE,	/* The size of the stack to allocate to the task. */
				(void*) NULL, 				/* The parameter passed to the task - just to check the functionality. */
				tskIDLE_PRIORITY, 			/* The priority assigned to the task. */
				(xTaskHandle*) NULL);

	vTaskStartScheduler();

	for(;;);
	return 0;
}

static void prvSetupHardware(void) {
	// Setup LED Pin
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

	// Setup UART Peripheral Pins
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
}

static void prvConfigureClocks(void) {
	// Set Core Clock to 24 MHz
	FlashCtl_setWaitState(FLASH_BANK0, 2);
    FlashCtl_setWaitState(FLASH_BANK1, 2);
    MAP_PCM_setCoreVoltageLevel(PCM_VCORE1);
    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_24);
}
