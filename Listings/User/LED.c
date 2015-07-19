/* ################LED.c##########################################
**     Filename  : LED.c
**     Processor : MKL25Z
**     Date/Time : 2015-18-07, 22:38
** ###############################################################*/
#include "LED.h"
#include "Delay.h"

void RGB(uint16_t Red,uint16_t Green,uint16_t Blue){
  (void)(Red   ? (FPTB->PCOR |= MASK(LED_R)) : (FPTB->PSOR |= MASK(LED_R)));
	(void)(Green ? (FPTB->PCOR |= MASK(LED_G)) : (FPTB->PSOR |= MASK(LED_G)));
	(void)(Blue  ? (FPTD->PCOR |= MASK(LED_B)) : (FPTD->PSOR |= MASK(LED_B)));
}

void LED_Initialization(void)
{
	PORTB->PCR[18] = PORT_PCR_MUX(1);              		// Set Pin B18 to GPIO function
	PORTB->PCR[19] = PORT_PCR_MUX(1);              		// Set Pin B19 to GPIO function
	PORTD->PCR[1]  = PORT_PCR_MUX(1);               	// Set Pin D1 to GPIO function

	FPTB->PDDR |= (1<<LED_R);                        	// Red LED, Negative Logic (0=on, 1=off)
	FPTB->PDDR |= (1<<LED_G);                      		// Green LED, Negative Logic (0=on, 1=off)
	FPTD->PDDR |= (1<<LED_B);                        	// Blue LED, Negative Logic (0=on, 1=off)

	FPTB->PCOR |= (1<<LED_R);													// Turn off leds
	FPTB->PCOR |= (1<<LED_G);
	FPTD->PCOR |= (1<<LED_B);
					
	RGB(1,0,0);		
	_delay_ms(200);
	RGB(0,1,0);
	_delay_ms(200);
	RGB(0,0,1);
	_delay_ms(200);
	RGB(0,0,0);
	_delay_ms(200);
	RGB(1,1,1);		
	_delay_ms(400);
	RGB(0,0,0);		
	_delay_ms(200);		
	RGB(1,1,1);		
	_delay_ms(400);
	RGB(0,0,0);		
	_delay_ms(200);
	}
