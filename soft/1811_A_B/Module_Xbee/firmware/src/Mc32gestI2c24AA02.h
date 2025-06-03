#ifndef Mc32GestI2C24AA02_H
#define Mc32GestI2C24AA02_H

/*--------------------------------------------------------*/
// Mc32GestI2cLM92.h
/*--------------------------------------------------------*/
//	Description :	Gestion par I2C du capteur temperature LM92 du Kit
//
//	Auteur 		: 	C. Huber
//	Version		:	V1.2    12.04.2016
//	Compilateur	:	XC32 V1.40 et Harmony 1.06
//
/*--------------------------------------------------------*/

#include <stdint.h>

// prototypes des fonctions
void I2C_Init24AA02(void);
int32_t I2C_Read_UID_24AA02_F(void);
int32_t I2C_Read_UID_24AA02_P(void);
void I2C_Write_UID_24AA02_P(int32_t PnewUID);
void I2C_Write_EEPROM_24AA02(int8_t add,int8_t data);

#endif //Mc32GestI2C24AA02_H
