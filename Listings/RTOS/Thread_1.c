
#include <cmsis_os.h>                                           // CMSIS RTOS header file
#include "LED.h"

/*----------------------------------------------------------------------------
 *      Thread 1 'Thread_1': Sample thread
 *---------------------------------------------------------------------------*/
 
void Thread_1 (void const *argument);                             // thread function
osThreadId tid_Thread_1;                                          // thread id
osThreadDef (Thread_1, osPriorityNormal, 1, 0);                   // thread object

int Init_Thread_1 (void) {

  tid_Thread_1 = osThreadCreate (osThread(Thread_1), NULL);
  if(!tid_Thread_1) return(-1);
  
  return(0);
}

void Thread_1 (void const *argument) {

  while (1) {
			RGB(0,0,1);
			osDelay(1000);
			osThreadYield();                                            // suspend thread
  }
}


