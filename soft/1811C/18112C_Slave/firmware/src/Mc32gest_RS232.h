#ifndef Mc32Gest_RS232_H
#define Mc32Gest_RS232_H
/*--------------------------------------------------------*/
// Mc32Gest_RS232.h
/*--------------------------------------------------------*/
//	Description :	emission et reception spécialisée
//			        pour TP2 2016-2017
//
//	Auteur 		: 	C. HUBER
//
//	Version		:	V1.3
//	Compilateur	:	XC32 V1.42 + Harmony 1.08
//
/*--------------------------------------------------------*/

#include <stdint.h>
#include <stdbool.h>
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
// Définition des fonctions prototypes
/*--------------------------------------------------------*/

// prototypes des fonctions
void InitFifoComm(void);


// Descripteur des fifos
extern S_fifo descrFifoRX;
extern S_fifo descrFifoTX;
extern bool Message_receive;
extern bool Message_Broadcast;
extern bool First_Transmit;

bool GetMessage(U_32 *pAdd_M, U_32 *pAdd_S, U_32 *pDatas);
void SendMessage(uint32_t ADD_M, uint32_t Add_S, uint32_t Datas);

#endif
