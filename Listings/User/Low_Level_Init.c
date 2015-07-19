/* ################Low_Level_Init.c###############################
**     Filename  : Low_Level_Init.c
**     Processor : MKL25Z
**     Date/Time : 2015-18-07, 22:38
** ###############################################################*/
#include "fsl_device_registers.h"
#include "Low_Level_Init.h"

/*************************************************************************
 *	ITM Stimulus Function Definition
 *	for Debug (printf) Viewer.
 *	use this example -> printf("AD value = 0x%04X\r\n", AD_value);
 *	Remember to set ITM Stimulus Port 0 bit
 *	to allow Trace to capture the ITM Port 0 information.
 *	Clear the Port 7..0 privilege bit
 *	to allow access to the Port 0 bit from User mode.
 *	In Debug mode Select View - Serial Windows - Debug (printf) Viewer.
 *	Only data transmitted over ITM Stimulus port 0 is displayed in the
 *	Debug (printf) Viewer window. Other ITM Ports can be monitored
 *	with the Trace Records Window.
 *************************************************************************/
struct __FILE { int handle; /* Add whatever needed */ };
struct __FILE __stdout;
struct __FILE __stdin;

int fputc(int ch, struct __FILE *f) {
  if (DEMCR & TRCENA) {
    while (ITM_Port32(0) == 0);
    ITM_Port8(0) = ch;
  }
  return(ch);
}
/*************************************************************************/


void init_hardware(void){    
	SIM->SCGC5 |= ( SIM_SCGC5_PORTA_MASK
								| SIM_SCGC5_PORTB_MASK
								| SIM_SCGC5_PORTC_MASK
								| SIM_SCGC5_PORTD_MASK
								| SIM_SCGC5_PORTE_MASK );

	SIM->SOPT2 |= 	SIM_SOPT2_PLLFLLSEL_MASK; 				// set PLLFLLSEL to select the PLL for this clock source 

}

