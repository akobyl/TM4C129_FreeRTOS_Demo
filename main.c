/* FreeRTOS 8.2 Tiva Demo
 *
 * main.c
 *
 * Andy Kobyljanec
 *
 * This is a simple demonstration project of FreeRTOS 8.2 on the Tiva Launchpad
 * EK-TM4C1294XL.  TivaWare driverlib sourcecode is included.
 */

#include <stdint.h>
#include <stdbool.h>
#include "main.h"

// TivaWare includes
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"

// FreeRTOS includes
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


// Demo Task declarations
void demoLEDTask(void *pvParameters);
void demoSerialTask(void *pvParameters);

// Main function
int main(void)
{

    // Initialize system clock to 120 MHz
    uint32_t output_clock_rate_hz;
    output_clock_rate_hz = SysCtlClockFreqSet(
                               (SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN |
                                SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480),
                               SYSTEM_CLOCK);
    ASSERT(output_clock_rate_hz == SYSTEM_CLOCK);

    // Create demo tasks
    xTaskCreate(demoLEDTask, (const portCHAR *)"LEDs",
                configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    xTaskCreate(demoSerialTask, (const portCHAR *)"Serial",
                configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();
    return 0;
}


// Flash the LEDs on the launchpad
void demoLEDTask(void *pvParameters)
{
    for (;;)
    {
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}


// Write text over the Stellaris debug interface UART port
void demoSerialTask(void *pvParameters)
{
    for (;;)
    {
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}

/*  ASSERT() Error function
 *
 *  failed ASSERTS() from driverlib/debug.h are executed in this function
 */
void __error__(char *pcFilename, uint32_t ui32Line)
{
    // Place a breakpoint here to capture errors until logging routine is finished
    while (1)
    {
    }
}
