#ifndef __MC32DRIVERADCALT_H
#define __MC32DRIVERADCALT_H
/*--------------------------------------------------------*/
//	Mc32DriverAdcALT.h
/*--------------------------------------------------------*/
//	Description :	Gestion ADC10 en mode alterné
//			
//
//	Auteur 		: 	C. Huber 
//
//	Version		:	V1.0
//	Compilateur	:	XC32 V1.33 & Harmony V1.00
//
/*--------------------------------------------------------*/

// #include "bsp_config.h"
#include <stdint.h>

// Structure pour 2 canaux
typedef struct {
   uint16_t Chan0;
   uint16_t Chan1;
} S_ADCResultsAlt ;

/*--------------------------------------------------------*/
// Fonction BSP_InitADC10Alt
/*--------------------------------------------------------*/
void BSP_InitADC10Alt(void);

/*--------------------------------------------------------*/
// Fonction BSP_ReadADCAlt                                     
/*--------------------------------------------------------*/
S_ADCResultsAlt BSP_ReadADCAlt();

#endif
