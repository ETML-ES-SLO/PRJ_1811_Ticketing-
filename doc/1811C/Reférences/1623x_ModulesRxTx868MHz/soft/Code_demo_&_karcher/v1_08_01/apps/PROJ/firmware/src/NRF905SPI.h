#ifndef NRF905SPI_H
#define NRF905SPI_H
/*--------------------------------------------------------*/
// Mc32GestSpiLM70.h
/*--------------------------------------------------------*/
//	Description :	Gestion par SPI du capteur temperature LM70 du Kit
//
//	Auteur 		: 	C. Huber
//	Version		:	V1.6    24.05.2016
//	Compilateur	:	XC32 V1.40 + Harmony 1.06
//      Modifications   :
//          CHR 06.03.2015 : Adaptation a plib_spi
//                           Utilisation stdint.h
//                           Ajout fonction SPI_CfgReadRawTempLM70
//          CHR 24.05.2016  maj version compilateur et Harmony 
//
/*--------------------------------------------------------*/



#include <stdint.h>

// Prototypes des fonctions
void SPI_Configure(void);
void SPI_InitNRF905(void);
uint8_t SPI_Read_data_RX_NRF905(int32_t Padd);
void SPI_Write_data_TX_NRF905(uint32_t Padd,uint8_t Ptx);
uint8_t SPI_Read_config_RX_NRF905(int32_t Padd);

#endif
