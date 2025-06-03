//18112C_Slave 
//
//Mc32Gest_RS232.C
// Canevas manipulatio TP2 RS232 SLO2 2016-2017
// Fonctions d'émission et de réception des message
// CHR 20.12.2016 ajout traitement int error
// CHR 22.12.2016 evolution des marquers observation int Usart
// MDS 26.09.2022 Modification pour permettre la communication avec le Xbee et la gestion des donnee reçu 

#include <xc.h>
#include <sys/attribs.h>
#include <stdint.h>
#include "system_definitions.h"
// Ajout CHR
#include "app.h"
#include "Mc32gest_RS232.h"
#include <GenericTypeDefs.h>
//Ajout MDS
#include "Retrieve_name.h"
#include "RF.h"
#include "Mc32Delays.h"
#include "Data_Code.h"
#include "GesFifoTh32.h"


//definition du byte de fin de trame
#define END  0xBB

//definition du byte de debut de trame
#define START  0xAA


// Structure décrivant le message (version 2016)


typedef union 
{
    uint32_t val32;
    
    struct
    {
        uint8_t lsb;
        uint8_t byte2;
        uint8_t byte1;
        uint8_t msb;
    } 
    shl;
} 
U_manip32;

typedef struct {
   uint8_t Start_First;
   uint8_t Start;
   U_32 Add_Master;
   U_32 Add_Slave;
   U_32 Data;
   uint8_t End;
   char Name [20];
   
} StruMess;

// Struct pour émission des messages
StruMess TxMess;
// Struct pour réception des messages
StruMess RxMess;

// Declaration des FIFO pour réception et émission
#define FIFO_RX_SIZE ( (63*7) + 1)  // 63 messages
#define FIFO_TX_SIZE ( (63*7) + 1)  // 63 messages

int8_t fifoRX[FIFO_RX_SIZE];
// Declaration du descripteur du FIFO de réception
S_fifo descrFifoRX;


int8_t fifoTX[FIFO_TX_SIZE];
// Declaration du descripteur du FIFO d'émission
S_fifo descrFifoTX;

uint32_t Add_Slave = 0;
uint32_t Add_Master = 0;

bool Message_receive;
bool Message_Broadcast = false;

bool First_Transmit; 
// Initialisation de la communication sériel
// -----------------------------------------

void InitFifoComm(void)
{
     
   // Initialisation du fifo de réception
   InitFifo ( &descrFifoRX, FIFO_RX_SIZE, fifoRX, 0 );
   // Initialisation du fifo d'émission
   InitFifo ( &descrFifoTX, FIFO_TX_SIZE, fifoTX, 0 );
   
} // InitComm

 
bool GetMessage(U_32 *pAdd_M,U_32 *pAdd_S, U_32 *pDatas)
{
    
    bool startOk = false;
    static int CommStatus = 0;
    
    int8_t CarLu,i=0,Car_Start_Trame = 0;
    
    RxMess.End = END;
    
    // Traitement de réception à introduire ICI
    if(Get_Add_Slave)
    {
       
       uint8_t* dstArray ;
    
        SYS_INT_SourceDisable(INT_SOURCE_USART_1_RECEIVE); //désactive int uart rx

        while(GetReadSize(&descrFifoRX) > 0)
        {
           
           GetCharFromFifo (&descrFifoRX, (int8_t*)&CarLu);
           dstArray[i] = CarLu;    
           i++;
        }
        Get_Add_Slave = false;
        Add_Slave = (uint32_t)dstArray;

        SYS_INT_SourceEnable(INT_SOURCE_USART_1_RECEIVE); //réactive int uart rx
    }
    else
    {
        //vérifie longueur message et présence start
        // trame 14 byte min:
        // 1 byte de start
        // 4 byte d'adresse de l'expediteur
        // 4 byte d'addresse de destinataire
        // 4 byte de donnee
        // 1 byte de fin
         while((GetReadSize(&descrFifoRX)) >= 14)
        {
            GetCharFromFifo (&descrFifoRX, &CarLu);
            if (CarLu == (int8_t)0xAA)
            {
                startOk = true;

                break;
            }
        }
         //Start trouvé, lire message et décoder
        if (startOk)
        {
            
            //prendre de la fifo les 4 byte de l'expediteur
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pAdd_M->U_32_Bytes.lsb = CarLu;
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pAdd_M->U_32_Bytes.byte2  = CarLu;   
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pAdd_M->U_32_Bytes.byte1  = CarLu; 
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pAdd_M->U_32_Bytes.msb = CarLu;
            
            //On verifie si l'adresse de l'expediteur est un broadcast
            if(pAdd_M->val32 == ADD_BROADCAST)
            {
                //prendre de la fifo les 4 byte de l'expediteur en ecrasant le broadcast
                Message_Broadcast = true;
                GetCharFromFifo (&descrFifoRX, &CarLu);
                pAdd_M->U_32_Bytes.lsb = CarLu;         
                GetCharFromFifo (&descrFifoRX, &CarLu);
                pAdd_M->U_32_Bytes.byte2  = CarLu;   
                GetCharFromFifo (&descrFifoRX, &CarLu);
                pAdd_M->U_32_Bytes.byte1  = CarLu; 
                GetCharFromFifo (&descrFifoRX, &CarLu);
                pAdd_M->U_32_Bytes.msb = CarLu;
                
            }
            else
            {
                //prendre de la fifo les 4 byte du destinataire
                GetCharFromFifo (&descrFifoRX, &CarLu);
                pAdd_S->U_32_Bytes.lsb = CarLu;         
                GetCharFromFifo (&descrFifoRX, &CarLu);
                pAdd_S->U_32_Bytes.byte2  = CarLu;   
                GetCharFromFifo (&descrFifoRX, &CarLu);
                pAdd_S->U_32_Bytes.byte1  = CarLu; 
                GetCharFromFifo (&descrFifoRX, &CarLu);
                pAdd_S->U_32_Bytes.msb = CarLu;
            }
           
            
            //prendre de la fifo les 4 byte de datas
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pDatas->U_32_Bytes.lsb = CarLu;         
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pDatas->U_32_Bytes.byte2  = CarLu;   
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pDatas->U_32_Bytes.byte1  = CarLu; 
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pDatas->U_32_Bytes.msb = CarLu;
            
            //prendre de la fifo le byte de fin
            GetCharFromFifo (&descrFifoRX, &CarLu);
            
            //on vérifie si on a bien eu le byte de fin
            if (CarLu == RxMess.End)
            {
                startOk = true;
            }
            else
            {
                startOk = false;
            }
            //si les data etait un are_you_link
//            if(pDatas->val32 == ARE_U_LINK)
//            {
//                //Cangement d etat
//                APP_UpdateState(APP_WAIT_FOR_LINK);
//            }
        }
    }
    return startOk;
} // GetMessagetMessage



// Fonction d'envoi des message
void SendMessage(uint32_t Add_S,uint32_t Add_M, uint32_t Datas)
{
    
    int8_t FreeSize,i;
    // Gestion du control de flux
    TxMess.Start = 0xAA;
    TxMess.End = 0xBB;
    TxMess.Add_Master.val32 = Add_M;
    TxMess.Add_Slave.val32 = Add_S;
    TxMess.Data.val32 = Datas;
    //TxMess.Name = buffReadName;
    countCar = 7;
    
    //vérifie longueur disponible dans le fifo
    // trame 14 byte min:
    // 1 byte de start
    // 4 byte d'adresse de l'expediteur
    // 4 byte d'addresse de destinataire
    // 4-20 byte de donnee (depend du nom de l'utilisateur)
    // 1 byte de fin
    if (GetWriteSpace(&descrFifoTX) >= (10 + countCar)) 
    {
        // on met le byte de debut de trame dans le fifo
        PutCharInFifo (&descrFifoTX, TxMess.Start);
        // on met l'adresse de l'expediteur dans le fifo
        PutCharInFifo (&descrFifoTX, TxMess.Add_Slave.U_32_Bytes.lsb); 
        PutCharInFifo (&descrFifoTX, TxMess.Add_Slave.U_32_Bytes.byte2); 
        PutCharInFifo (&descrFifoTX, TxMess.Add_Slave.U_32_Bytes.byte1);
        PutCharInFifo (&descrFifoTX, TxMess.Add_Slave.U_32_Bytes.msb);
        
        // on met l'adresse du destinataire dans le fifo
        PutCharInFifo (&descrFifoTX, TxMess.Add_Master.U_32_Bytes.lsb); 
        PutCharInFifo (&descrFifoTX, TxMess.Add_Master.U_32_Bytes.byte2); 
        PutCharInFifo (&descrFifoTX, TxMess.Add_Master.U_32_Bytes.byte1);
        PutCharInFifo (&descrFifoTX, TxMess.Add_Master.U_32_Bytes.msb);
        
        //on vérifie si c'est le premier envoie de donnee
        if(First_Transmit)
        {
            for(i = 0 ; i <= countCar - 1 ; i ++ )
            {
                //on met les different byte dans le fifo
                PutCharInFifo (&descrFifoTX, buffReadName[i]);
                
            }
            //on enleve le flag de premiere envoie
            First_Transmit = false;
        }
        else
        {
            // on met les datas dans le fifo
            PutCharInFifo (&descrFifoTX, TxMess.Data.U_32_Bytes.lsb); 
            PutCharInFifo (&descrFifoTX, TxMess.Data.U_32_Bytes.byte2); 
            PutCharInFifo (&descrFifoTX, TxMess.Data.U_32_Bytes.byte1);
            PutCharInFifo (&descrFifoTX, TxMess.Data.U_32_Bytes.msb);
        }
        PutCharInFifo (&descrFifoTX, TxMess.End);
    }                 
    
    PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
}

// !!!!!!!!
// Attention ne pas oublier de supprimer la réponse générée dans system_interrupt
// !!!!!!!!

void __ISR(_UART_1_VECTOR, ipl5AUTO) _IntHandlerDrvUsartInstance0(void)
{
    USART_ERROR UsartStatus;    
    int8_t Carac, TXsize, TxBuffFull;
    // Is this an Error interrupt ?
    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_1_ERROR) &&
            PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_1_ERROR) ) {
        /* Clear pending interrupt */
        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_ERROR);
        // Traitement de l'erreur à la réception.
    }
   

    // Is this an RX interrupt ?
    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_1_RECEIVE) &&
            PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_1_RECEIVE) ) {

        // Oui Test si erreur parité ou overrun
        UsartStatus = PLIB_USART_ErrorsGet(USART_ID_1);
        if ( (UsartStatus & (USART_ERROR_PARITY |
            USART_ERROR_FRAMING | USART_ERROR_RECEIVER_OVERRUN)) == 0) 
        {
        
            while(PLIB_USART_ReceiverDataIsAvailable(USART_ID_1))
            {
                //Led_ReadyToggle();
                Carac = PLIB_USART_ReceiverByteReceive(USART_ID_1);
                PutCharInFifo(&descrFifoRX, Carac);
            }  
            //Message_receive = true;
            // buffer is empty, clear interrupt flag
            PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_RECEIVE);
        } else {
            // Suppression des erreurs
            // La lecture des erreurs les efface sauf pour overrun
            if ( (UsartStatus & USART_ERROR_RECEIVER_OVERRUN) == USART_ERROR_RECEIVER_OVERRUN) {
                   PLIB_USART_ReceiverOverrunErrorClear(USART_ID_1);
            }
        }
        //Led_ReadyOff();
    } // end if RX
    
 
    
    // Is this an TX interrupt ?
    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT) &&
                 PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT) ) {
        
        TXsize = GetReadSize(&descrFifoTX);
        TxBuffFull = PLIB_USART_TransmitterBufferIsFull(USART_ID_1);
        if ((TXsize > 0)&& (TxBuffFull == false))
        {
            do//Faire la boucle tant que le message n'est pas envoyé
            {
                //Led_SendedToggle();
                //On va chercher les valeurs a envoyer 
                GetCharFromFifo(&descrFifoTX, &Carac);
                PLIB_USART_TransmitterByteSend(USART_ID_1, Carac);
                TXsize = GetReadSize(&descrFifoTX);
                TxBuffFull = PLIB_USART_TransmitterBufferIsFull(USART_ID_1);
                
            }while((TXsize > 0)&& (TxBuffFull == false));
            
            // Clear the TX interrupt Flag (Seulement apres TX) 
            PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
            TXsize = GetReadSize(&descrFifoTX);
            if (TXsize == 0) 
            {
                //Pour eviter les interruption inutile
                PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
            }
        }
        else
        {
              // disable TX interrupt (pour éviter une interrupt. inutile si plus rien à transmettre)
             PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
        }	   
    }
 }



