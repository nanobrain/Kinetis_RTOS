
#include <cmsis_os.h>                                           // CMSIS RTOS header file
#include "LED.h"

/*----------------------------------------------------------------------------
 *      Thread 1 'Thread': Sample thread
 *---------------------------------------------------------------------------*/
 
void Thread (void const *argument);                             // thread function
osThreadId tid_Thread;                                          // thread id
osThreadDef (Thread, osPriorityNormal, 1, 0);                   // thread object

int Init_Thread (void) {

  tid_Thread = osThreadCreate (osThread(Thread), NULL);
  if(!tid_Thread) return(-1);
  
  return(0);
}

void Thread (void const *argument) {
	//int AD_value = 0x43;
	while (1) {
		RGB(1,0,0);
		//printf ("Width trick: %*d \n", 5, 10);
		osDelay(1000);
		osThreadYield();                                            // suspend thread
	}
}


