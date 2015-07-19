/* ################LED.h##########################################
**     Filename  : LED.h
**     Processor : MKL25Z
**     Date/Time : 2015-18-07, 22:38
** ###############################################################*/
#include "fsl_device_registers.h"

#define MASK(x) (1UL << (x))
#define LED_R 18
#define LED_G 19
#define LED_B 1

extern void RGB(uint16_t Red, uint16_t Green, uint16_t Blue);				// RGB-LED Control: 1=on, 0=off, for each of the 3 colors
extern void LED_Initialization(void);
