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
	// Stop Watch Dog Timer
	MAP_WDT_A_holdTimer();

	// Enable Floating Point Unit
	FPU_enableModule();

	// Setup UART Peripheral Pins
	MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

	// Setup LED Pin
	MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
	MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
}

static void prvConfigureClocks(void) {
	// Set Core Clock to 48 MHz
	CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_48);
	CS_initClockSignal(CS_HSMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);
	CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);
	CS_initClockSignal(CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);
	CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
}
