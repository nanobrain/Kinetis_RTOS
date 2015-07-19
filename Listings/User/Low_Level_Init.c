/* ################Low_Level_Init.c###############################
**     Filename  : Low_Level_Init.c
**     Processor : MKL25Z
**     Date/Time : 2015-18-07, 22:38
** ###############################################################*/
#include "fsl_device_registers.h"
#include "Low_Level_Init.h"

void init_hardware(void){    
	SIM->SCGC5 |= ( SIM_SCGC5_PORTA_MASK
								| SIM_SCGC5_PORTB_MASK
								| SIM_SCGC5_PORTC_MASK
								| SIM_SCGC5_PORTD_MASK
								| SIM_SCGC5_PORTE_MASK );

	SIM->SOPT2 |= 	SIM_SOPT2_PLLFLLSEL_MASK; 				// set PLLFLLSEL to select the PLL for this clock source 

}

