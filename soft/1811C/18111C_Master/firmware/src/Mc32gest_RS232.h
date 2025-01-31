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
extern S_fifo descrFifoRX_USB;
extern S_fifo descrFifoTX_USB;

extern bool Message_receive_USB;
extern bool Message_send_USB;
extern bool Message_receive_XBEE;
extern bool Message_send_XBEE;
extern bool LINK,Add_ON;

extern uint32_t Add_Master;
extern uint32_t Add_Slave;

extern uint8_t Nb_Student;
extern uint8_t Nb_In_List;
extern bool New_student;

void GetMessage(U_32 *Add_S,U_32 *Add_M, U_32 *pDatas);
void SendMessage(uint32_t Add_M,uint32_t Add_S, uint32_t pDatas);
void SendMessage_USB(uint32_t pDatas);
void GetMessage_USB( U_32 *pDatas);

#endif
