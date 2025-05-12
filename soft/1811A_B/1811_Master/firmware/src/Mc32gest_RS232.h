#ifndef Mc32Gest_RS232_H
#define Mc32Gest_RS232_H
/*--------------------------------------------------------*/
// Mc32Gest_RS232.h
/*--------------------------------------------------------*/
//	Description :	emission et reception sp�cialis�e
//			        pour TP2 2016-2017
//
//	Auteur 		: 	C. HUBER
//
//	Version		:	V1.3
//	Compilateur	:	XC32 V1.42 + Harmony 1.08
//
/*--------------------------------------------------------*/

#include <stdint.h>
#include "GesFifoTh32.h"

typedef union 
{
    uint32_t val32;
    
    struct
    {
        uint8_t msb;
        uint8_t byte1;
        uint8_t byte2;
        uint8_t lsb;
    } 
    U_32_Bytes;
} 
U_32;

/*--------------------------------------------------------*/
// D�finition des fonctions prototypes
/*--------------------------------------------------------*/

// prototypes des fonctions
void InitFifoComm(void);


// Descripteur des fifos
extern S_fifo descrFifoRX;
extern S_fifo descrFifoTX;

bool GetMessage(U_32 *pAdd, U_32 *pDatas);
void SendMessage(uint32_t pAddTarget, uint32_t pDatas);

#endif
