/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/

#define osObjectsPublic                     // define objects in main module
#include "osObjects.h"                      // RTOS object definitions
#include "fsl_device_registers.h"
#include "Low_Level_Init.h"
#include "LED.h"
#include "HD44780.h"

extern int Init_Thread (void);
extern int Init_Thread_1 (void);
/*
 * main: initialize and start the system
 */
int main (void) {
  osKernelInitialize ();                    // initialize CMSIS-RTOS
	
  // initialize peripherals here
	init_hardware();													// <- Hardware initialization MUST be always before ANY other init
	LED_Initialization();
	LCD_Init();
  // create 'thread' functions that start executing,
  Init_Thread();
	Init_Thread_1();
	// example: tid_name = osThreadCreate (osThread(name), NULL);

	osKernelStart ();                         // start thread execution 
}

