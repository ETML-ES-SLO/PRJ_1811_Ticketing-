// Mc32Gest_RS232.C
// Canevas manipulatio TP2 RS232 SLO2 2016-2017
// Fonctions d'�mission et de r�ception des message
// CHR 20.12.2016 ajout traitement int error
// CHR 22.12.2016 evolution des marquers observation int Usart

#include <xc.h>
#include <sys/attribs.h>
#include "system_definitions.h"
// Ajout CHR
#include <GenericTypeDefs.h>
#include "app.h"
#include "GesFifoTh32.h"
#include "Mc32gest_RS232.h"





// Definition pour les messages
#define MESS_SIZE  7
// avec int8_t besoin -86 au lieur de 0xAA
#define STX_code  (-86)

// Structure d�crivant le message (version 2016)


typedef union 
{
    uint32_t val32;
    
    struct
    {
        uint8_t lsb;
        uint8_t byte1;
        uint8_t byte2;
        uint8_t msb;
    } 
    shl;
} 
U_manip32;
typedef struct {
   uint8_t Start;
   uint8_t com;
   U_manip32 add;
   int8_t  data;
   
} StruMess;


U_manip32 add_32;

// Struct pour �mission des messages
StruMess TxMess;
// Struct pour r�ception des messages
StruMess RxMess;

// Declaration des FIFO pour r�ception et �mission
#define FIFO_RX_SIZE ( (63*7) + 1)  // 63 messages
#define FIFO_TX_SIZE ( (63*7) + 1)  // 63 messages

int8_t fifoRX[FIFO_RX_SIZE];
// Declaration du descripteur du FIFO de r�ception
S_fifo descrFifoRX;


int8_t fifoTX[FIFO_TX_SIZE];
// Declaration du descripteur du FIFO d'�mission
S_fifo descrFifoTX;


// Initialisation de la communication s�riel
// -----------------------------------------

void InitFifoComm(void)
{
     
   // Initialisation du fifo de r�ception
   InitFifo ( &descrFifoRX, FIFO_RX_SIZE, fifoRX, 0 );
   // Initialisation du fifo d'�mission
   InitFifo ( &descrFifoTX, FIFO_TX_SIZE, fifoTX, 0 );
   
   /*
   // Init RTS 
   RS232_RTS = 1;   // interdit �mission par l'autre                                        */
   
} // InitComm

 
  
// Valeur de retour 0  = pas de message re�u donc local (data non modifi�)
// Valeur de retour 1  = message re�u donc en remote (data mis � jour)
int GetMessage(S_UART_message *pData)
{
    bool startOk = false;
    static int CommStatus = 0;

    int8_t CarLu;
    
    // Traitement de r�ception � introduire ICI
    
    // Retourne le nombre de caract�res � lire
    // Si le message est complet
    
    //v�rifie longueur message et pr�sence start
     while((GetReadSize(&descrFifoRX)) >= 7)
    {
        GetCharFromFifo (&descrFifoRX, &CarLu);
        if (CarLu == (int8_t)0xAA)
        {
            startOk = true;

            break;
        }
    }
     //Start trouv�, lire message et d�coder
    if (startOk)
    {
        // OK
        GetCharFromFifo (&descrFifoRX, &CarLu);
         pData->com = CarLu;         
         GetCharFromFifo (&descrFifoRX, &CarLu);
         RxMess.add.shl.msb  = CarLu;   
         GetCharFromFifo (&descrFifoRX, &CarLu);
         RxMess.add.shl.byte2  = CarLu; 
         GetCharFromFifo (&descrFifoRX, &CarLu);
         RxMess.add.shl.byte1 = CarLu;
         GetCharFromFifo (&descrFifoRX, &CarLu);
         RxMess.add.shl.lsb =  CarLu; 
         pData->add =RxMess.add.val32;
         GetCharFromFifo (&descrFifoRX, &CarLu);
         pData->data =   CarLu;       
         
         CommStatus = 1; 
    }
    else
    {
        CommStatus = 0;
    }
                                                 
    return CommStatus;
 
} // GetMessagetMessage


// Fonction d'envoi des message, appel cyclique
// Traite des 2 canaux de l'AD
// Envoi  1 message de type 1 et 1 message de type 2


void SendMessage(S_UART_message *pData)
{
  int8_t FreeSize;
  // Gestion du control de flux
  TxMess.Start = 0xAA;
  TxMess.com = pData->com;
  TxMess.add.val32 = pData->add;
  TxMess.data = pData->data;
  
  
  if (GetWriteSpace(&descrFifoTX) >= 7) 
  {
    //mettre les datas dans la FIFO
    PutCharInFifo (&descrFifoTX, TxMess.Start);
    PutCharInFifo (&descrFifoTX, TxMess.com); 
    PutCharInFifo (&descrFifoTX, TxMess.add.shl.msb); 
    PutCharInFifo (&descrFifoTX, TxMess.add.shl.byte2);
    PutCharInFifo (&descrFifoTX, TxMess.add.shl.byte1);
    PutCharInFifo (&descrFifoTX, TxMess.add.shl.lsb); 
    PutCharInFifo (&descrFifoTX, TxMess.data); 
  }
  // si on a un caract�re � envoyer
  FreeSize = GetReadSize(&descrFifoTX);
  if (FreeSize > 0)
  {
        // Autorise int �mission                                                     !!!!!!!!!!!!!!!
        PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
  }                                                                                    
}

// !!!!!!!!
// Attention ne pas oublier de supprimer la r�ponse g�n�r�e dans system_interrupt
// !!!!!!!!

 void __ISR(_UART_1_VECTOR, ipl5AUTO) _IntHandlerDrvUsartInstance0(void)
{

    uint8_t ErrFiFoFull = 0;
    int32_t freeSize, TXsize;
    int8_t c;
  
    bool  TxBuffFull;

    USART_ERROR  UsartStatus;

    
    // Is this an Error interrupt ?
    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_1_ERROR) &&
                 PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_1_ERROR) ) {
         /* Clear pending interrupt */
         PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_ERROR);
         // Traitement de l'erreur � la r�ception.
    }
   

    // Is this an RX interrupt ?
    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_1_RECEIVE) &&
                 PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_1_RECEIVE) ) {
        
        // Oui Test si erreur parit� ou overrun
        UsartStatus = PLIB_USART_ErrorsGet(USART_ID_1);
        
        if ( (UsartStatus & (USART_ERROR_PARITY |
                             USART_ERROR_FRAMING | USART_ERROR_RECEIVER_OVERRUN)) == 0) {
                                
             // transfert dans le fifo de tous les char re�u
             while (PLIB_USART_ReceiverDataIsAvailable(USART_ID_1))
             {
                 c = PLIB_USART_ReceiverByteReceive(USART_ID_1);
                 PutCharInFifo ( &descrFifoRX, c);
             }
             // buffer is empty, clear interrupt flag
             PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_RECEIVE);
        } else {
             // Suppression des erreurs
             // La lecture des erreurs les efface sauf pour overrun
             if ( (UsartStatus & USART_ERROR_RECEIVER_OVERRUN) == USART_ERROR_RECEIVER_OVERRUN) {
                    PLIB_USART_ReceiverOverrunErrorClear(USART_ID_1);
             }
        }         
        
        freeSize = GetWriteSpace ( &descrFifoRX);
        if (freeSize <= 6 )   // a cause d'un int pour 6 char
        {
           // Demande de ne plus �mettre
           //RS232_RTS = 1;                                                           !!!!!!!!!!

           if (freeSize == 0) {
                ErrFiFoFull = 1;    // pour debugging
                if (ErrFiFoFull >= 1) ErrFiFoFull = 2;
           }
        }           
        
            
                                                         
    } // end if RX                                                                                  

    // Is this an TX interrupt ?
    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT) &&
                 PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT) ) {
        
        PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_USART_1_TRANSMIT);
        
        


                
         TXsize = GetReadSize (&descrFifoTX);
         // i_cts = input(RS232_CTS);
         // On v�rifie 3 conditions :
         //    Si CTS = 0 (autorisation d'�mettre)
         //    Si il y a un carat�res � �mettre
         //    Si le txreg est bien disponible

                                                        

          //TxPossible = UARTTransmitterIsReady(UART1);
        
         TxBuffFull = PLIB_USART_TransmitterBufferIsFull(USART_ID_1);
         
         if ( /*(i_cts == 0) &&*/ ( TXsize > 0 ) &&  TxBuffFull==false )  {         //!!!!!!!!!!

            do {
                 GetCharFromFifo(&descrFifoTX, &c);
                 PLIB_USART_TransmitterByteSend(USART_ID_1, c);
                 //i_cts = RS232_CTS;                                                 //!!!!!!!
                 TXsize = GetReadSize (&descrFifoTX);
                 TxBuffFull = PLIB_USART_TransmitterBufferIsFull(USART_ID_1);

            } while ( /*(i_cts == 0) &&*/ ( TXsize > 0 ) &&                         // !!!!!!!
                                               TxBuffFull==false  );

            // Clear the TX interrupt Flag
            // (Seulement apr�s TX)
           PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
			if (TXsize == 0) {
                // disable TX interrupt (pour �viter une int inutile)
                PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
            }
            else {
            // disable TX interrupt
                    PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
                }                                                                                           
            }
        }
 }




