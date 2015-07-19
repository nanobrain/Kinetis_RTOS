/** ###############Low_Level_Init.h#####################################
**     Filename  : Low_Level_Init.h
**     Processor : Universal
**     Date/Time : 2015-31-05, 20:34
** ###################################################################*/


/*************************************************************************
 *	ITM Stimulus Port Register Definitions
 *	for Debug (printf) Viewer
 *************************************************************************/
 
#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000
/*************************************************************************/

#define MASK(x) (1UL << (x))
extern void init_hardware(void);
