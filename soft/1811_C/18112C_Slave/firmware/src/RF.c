//--------------------------------------------------------
// RF.c
//--------------------------------------------------------
// Gestion communication	
//
//	Auteur 		: 	SCA
//  Date        :   5.12.2019
//	Version		:	V1.0
//	Compilateur	:	XC32 V2.15
//  Modifications : MDS 26.09.2022
//    code repris du projet 1623 20200214_Module_Xbee_06_SCA
//   -
/*--------------------------------------------------------*/
#include "RF.h"
#include "app.h"
#include <xc.h> //pour les définitions des registres
#include "Mc32Delays.h"
#include "peripheral/usart/plib_usart.h"
#include <string.h> //pour memcpy()

 bool Get_Add_Slave = false;


void RF_Init(void)
{
    uint32_t dummy,dummy2;
    
    //reset module RF 1 ms
    
    RstOff();
    delay_msCt(1);
    RstOn();

    delay_msCt(10); //attendre fin init module rf

    // puis envoyer trame pour sortie mode config
    //RF_SendMessage((uint8_t*)"AT+EXIT\n", 0);
    
    
    Get_Add_Slave = true;
    
    //lire sa propre adresse
    RF_SendMessage((uint8_t*)"AT+GADD", 0);
    GetMessage(dummy2,dummy);
    
    
    delay_msCt(10); //attendre traitement cmde EXIT    
}


/* ************************************************************************** */
//envoi trame au module RF via UART 1
// soit un nb de bytes défini par nbBytesToSend
// sinon si nbBytesToSend==0, envoi jusqu'à trouver une fin de chaine (car. 0))
void RF_SendMessage(uint8_t* dataToSend, uint8_t nbBytesToSend)   
//void Uart_SendMessage(uint8_t* dataToSend, uint8_t nbBytesToSend)
{
    uint8_t i = 0;
    
    if (nbBytesToSend != 0) //nb de car. à envoyer spécifié
    {
        for (i=0 ; i<nbBytesToSend ; i++)
        {
            while(PLIB_USART_TransmitterBufferIsFull(USART_ID_1));
            PLIB_USART_TransmitterByteSend(USART_ID_1, dataToSend[i]);
        }   
    } else //chaine à envoyer (se termine par car. 0)
    {
        while (dataToSend[i] != 0)
        {
            while(PLIB_USART_TransmitterBufferIsFull(USART_ID_1));
            PLIB_USART_TransmitterByteSend(USART_ID_1, dataToSend[i]);
            i++;
        }           
    }
}
