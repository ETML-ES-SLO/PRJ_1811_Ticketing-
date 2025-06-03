//18111C_Master
// Mc32Gest_RS232.C
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
#include "GesFifoTh32.h"
#include "RF.h"
#include "Mc32Delays.h"
#include "Data_Code.h"
#include "app_SDCard.h"
#include <string.h>


//definition du byte de fin de trame
#define END  0xBB

//definition du byte de debut de trame
#define START  0xAA

uint8_t countCar = 0;           // Compteur du nombre de characters d'un nom
char buffReadName[20] = {' '};// Buffer de reception de l'UART
uint8_t Name_Receive = false;   //Flag Nom recu

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
   uint8_t Start;
   U_32 Add_Master;
   U_32 Add_Slave;
   U_32  Broadcast;
   U_32  data;
   uint8_t End;
   
} StruMess;

// Struct pour émission des messages
StruMess TxMess;
// Struct pour réception des messages
StruMess RxMess;

// Declaration des FIFO pour réception et émission
#define FIFO_RX_SIZE ( (30 * 7) + 1)  
#define FIFO_TX_SIZE ( (30 * 7) + 1)  
#define FIFO_TX_USB_SIZE ( (20 * 7) + 1)  
#define FIFO_RX_USB_SIZE ( (20 * 7) + 1)  

int8_t fifoTX_USB[FIFO_TX_USB_SIZE];
// Declaration du descripteur du FIFO d'émission USB
S_fifo descrFifoTX_USB;

int8_t fifoRX_USB[FIFO_RX_USB_SIZE];
// Declaration du descripteur du FIFO d'émission USB
S_fifo descrFifoRX_USB;


int8_t fifoRX[FIFO_RX_SIZE];
// Declaration du descripteur du FIFO de réception
S_fifo descrFifoRX;


int8_t fifoTX[FIFO_TX_SIZE];
// Declaration du descripteur du FIFO d'émission
S_fifo descrFifoTX;

bool LINK,Add_ON;
uint32_t Add_Master = 0;
uint32_t Add_Slave = 0;
bool ID_In_List;
bool New_student;
uint8_t Nb_In_List;

// Initialisation de la communication sériel
// -----------------------------------------

void InitFifoComm(void)
{
     
   // Initialisation du fifo de réception
   InitFifo ( &descrFifoRX, FIFO_RX_SIZE, fifoRX, 0 );
   // Initialisation du fifo d'émission
   InitFifo ( &descrFifoTX, FIFO_TX_SIZE, fifoTX, 0 );
   
   // Initialisation du fifo d'émission USB
   InitFifo ( &descrFifoTX_USB, FIFO_TX_USB_SIZE, fifoTX_USB, 0 );
    // Initialisation du fifo de réception USB
   InitFifo ( &descrFifoRX_USB, FIFO_RX_USB_SIZE, fifoRX_USB, 0 );
} // InitComm

 
void GetMessage(U_32 *pAdd_S,U_32 *pAdd_M, U_32 *pDatas)
{
    bool startOk = false;
    
    RxMess.End = END;
    int8_t CarLu,i,y,x;
    uint8_t car ;
    if(Get_Add_Master)
    {
       
       uint8_t* dstArray ;

        SYS_INT_SourceDisable(INT_SOURCE_USART_1_RECEIVE); //désactive int uart rx


        while(GetReadSize(&descrFifoRX) > 0)
        {
           
           GetCharFromFifo (&descrFifoRX, (int8_t*)&CarLu);
           dstArray[i] = CarLu;    
           i++;
        }
        Get_Add_Master = false;
        Add_Master = (uint32_t)dstArray;
        

        SYS_INT_SourceEnable(INT_SOURCE_USART_1_RECEIVE); //désactive int uart rx

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
            if (CarLu == (int8_t)START)
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
            pAdd_S->U_32_Bytes.lsb = CarLu;         
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pAdd_S->U_32_Bytes.byte2  = CarLu;   
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pAdd_S->U_32_Bytes.byte1  = CarLu; 
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pAdd_S->U_32_Bytes.msb = CarLu;

            //prendre de la fifo les 4 byte du destinataire
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pAdd_M->U_32_Bytes.lsb = CarLu;         
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pAdd_M->U_32_Bytes.byte2  = CarLu;   
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pAdd_M->U_32_Bytes.byte1  = CarLu; 
            GetCharFromFifo (&descrFifoRX, &CarLu);
            pAdd_M->U_32_Bytes.msb = CarLu;

            
            
            //lecture byte dans fifo
            GetCharFromFifo (&descrFifoRX, &CarLu);
            //tant que l'on a pas le byte de fin on enregistre les donnees
            while ( CarLu!= '»')
            {
                //copie des donnee dans un tableau
                buffReadName[countCar] = CarLu;
                // lire la prochaine valeur du fifo
                GetCharFromFifo (&descrFifoRX, &CarLu);
                //incrementation dans le tableau
                countCar++;
            }
//            do
//            { 
//                //copie des donnee dans un tableau
//                buffReadName[countCar] = CarLu;
//                // lire la prochaine valeur du fifo
//                GetCharFromFifo (&descrFifoRX, &CarLu);
//                //incrementation dans le tableau
//                countCar++;
//            }
//            while ( CarLu!= '»');

            //si les data sont <4 alors c'est une commande
            if(countCar <= 4)
            {
                //memset(&pDatas, 0x00, sizeof(pDatas));
                pDatas->U_32_Bytes.lsb = buffReadName[0];
                pDatas->U_32_Bytes.byte2 = buffReadName[1];
                pDatas->U_32_Bytes.byte1 = buffReadName[2];
                pDatas->U_32_Bytes.msb = buffReadName[3];
            }
            //si > alors c'est un nom d'eleve
            else
            {
                //on verifie la liste d'eleve
                for( i = 0; i < Nb_Student_max ; i++ )
                {
                    x=0;
                    //on verifie les lettre d'un eleve
                    for( y = 0; y < countCar ; y++ )
                    {
                        //on compare si ce sont les meme
                        if(buffReadName[y] == Students_Info[i].StudentName[y])
                        {
                            x++;
                            if(x == countCar)
                            {
                                //flag pour indiquer que le nom est deja dans la list
                                ID_In_List = true;
                                //on indique quel position dans la list
                                Nb_In_List = i;
                                // on sort de la boucle
                                i = Nb_Student_max;
                            }
                        }
                        else
                        {
                            //flag pour indiquer que le nom n'est pas dans la list
                            ID_In_List = false;
                            //on sort de la boucle
                            y=countCar;
                        }
                    }
                }
                if(!ID_In_List)
                {
                    //flag de nouveau eleve
                    New_student=true;
                    
                    for( y = 0; y < countCar ; y++ )
                    {
                        //on copie le nom dans la structure
                        Students_Info[Nb_Student_max].StudentName[y] = buffReadName[y];
                    }
                    //on copie l'adresse dans la structure
                    Students_Info[Nb_Student_max].ID = pAdd_S->val32;
                    //on copie le nombre de lettre dans le nom dans la structure
                    Students_Info[Nb_Student_max].Name_length = countCar;
                    //on augmente le nombre max d eleve dans la list
                    Nb_Student_max++;
                    
                    
                }
                else
                {
                    for(i=0; i< Nb_Student_max;i++)
                    {
                        if(Students_Info[i].ID == pAdd_S->val32)
                        {
                            Nb_In_List == i;
                        }
                    }
                    
                }
            }
            //on remet le compteur de data a 0
            countCar = 0;
            //on enleve le flag de reception xbee
            Message_receive_XBEE = false;
        }
    }
} // GetMessagetMessage



// Fonction d'envoi des message du Xbee
void SendMessage(uint32_t ADD_M,uint32_t ADD_S, uint32_t pDatas)
{
    uint8_t FreeSize,i,n;
    TxMess.Start = START;
    TxMess.Add_Master.val32 = ADD_M;
    TxMess.Add_Slave.val32 = ADD_S;
    TxMess.data.val32 = pDatas;
    TxMess.End = END;
    TxMess.Broadcast.val32 = ADD_BROADCAST;
   
    //vérifie longueur disponible dans le fifo
    // trame 14 byte min:
    // 1 byte de start
    // 4 byte d'adresse de l'expediteur
    // 4 byte d'addresse de destinataire
    // 4 byte de donnee
    // 1 byte de fin
    if (GetWriteSpace(&descrFifoTX) >= 10)  
    {   
        // on met le byte de debut de trame dans le fifo
        PutCharInFifo (&descrFifoTX, TxMess.Start);
        //on vérifie si l'on a deja essayer de se LINK
        if(!LINK)
        {
            // on met l'adresse de broadcast dans le fifo
            PutCharInFifo (&descrFifoTX,  TxMess.Broadcast.U_32_Bytes.lsb); 
            PutCharInFifo (&descrFifoTX,  TxMess.Broadcast.U_32_Bytes.byte2); 
            PutCharInFifo (&descrFifoTX,  TxMess.Broadcast.U_32_Bytes.byte1);
            PutCharInFifo (&descrFifoTX,  TxMess.Broadcast.U_32_Bytes.msb);
            LINK = true;
        }
        
    
        // on met l'adresse de l'expediteur dans le fifo
        PutCharInFifo (&descrFifoTX, TxMess.Add_Master.U_32_Bytes.lsb); 
        PutCharInFifo (&descrFifoTX, TxMess.Add_Master.U_32_Bytes.byte2); 
        PutCharInFifo (&descrFifoTX, TxMess.Add_Master.U_32_Bytes.byte1);
        PutCharInFifo (&descrFifoTX, TxMess.Add_Master.U_32_Bytes.msb);
        
        //on vérifie si on a une adresse à envoyer
        if(Add_ON)
        {
            // on met l'adresse du destinataire dans le fifo
            PutCharInFifo (&descrFifoTX, TxMess.Add_Slave.U_32_Bytes.lsb); 
            PutCharInFifo (&descrFifoTX, TxMess.Add_Slave.U_32_Bytes.byte2); 
            PutCharInFifo (&descrFifoTX, TxMess.Add_Slave.U_32_Bytes.byte1);
            PutCharInFifo (&descrFifoTX, TxMess.Add_Slave.U_32_Bytes.msb);
        }
        
        // on met les datas dans le fifo
        PutCharInFifo (&descrFifoTX, TxMess.data.U_32_Bytes.lsb); 
        PutCharInFifo (&descrFifoTX, TxMess.data.U_32_Bytes.byte2); 
        PutCharInFifo (&descrFifoTX, TxMess.data.U_32_Bytes.byte1);
        PutCharInFifo (&descrFifoTX, TxMess.data.U_32_Bytes.msb);

        // on met le byte de fin de trame dans le fifo
        PutCharInFifo (&descrFifoTX, TxMess.End);
    }

    // On met le flag d'envoye de l'uart Xbee
    PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
    
      
}
// Fonction d'envoi des message du USB
void SendMessage_USB( uint32_t pDatas)
{
    uint8_t FreeSize,i,n;
    TxMess.Start = START;
    TxMess.data.val32 = pDatas;
    TxMess.End = END;
    //InitFifo ( &descrFifoTX_USB, FIFO_TX_USB_SIZE, fifoTX_USB, 0 );
    //vérifie longueur disponible dans le fifo
    // trame 14 byte min:
    // 1 byte de start
    // 4 byte d'adresse de l'expediteur
    // 4 byte d'addresse de destinataire
    // 4 byte de donnee
    // 1 byte de fin
    if (GetWriteSpace(&descrFifoTX_USB) >= 10)  
    {
        // on met le byte de debut de trame dans le fifo
        PutCharInFifo (&descrFifoTX_USB, TxMess.Start);
        
        for(i = 0 ; i < Students_Info[0].Name_length ; i++ )
        {
            //on met les different byte dans le fifo
            PutCharInFifo (&descrFifoTX_USB, Students_Info[0].StudentName[i]);

        }
        
        // on met l'adresse de l'expediteur dans le fifo
        PutCharInFifo (&descrFifoTX_USB, TxMess.data.U_32_Bytes.lsb); 
        PutCharInFifo (&descrFifoTX_USB, TxMess.data.U_32_Bytes.byte2); 
        PutCharInFifo (&descrFifoTX_USB, TxMess.data.U_32_Bytes.byte1);
        PutCharInFifo (&descrFifoTX_USB, TxMess.data.U_32_Bytes.msb);
        
        

        // on met le byte de fin de trame dans le fifo
        PutCharInFifo (&descrFifoTX_USB, TxMess.End);
    }

    //Message_send_USB = false;
    // On met le flag d'envoye de l'uart USB
    PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_USART_2_TRANSMIT);
    
      
}
void GetMessage_USB( U_32 *pDatas)
{
    bool startOk = false;
    int8_t CarLu,i,x,y;
    RxMess.End = END;


    while((GetReadSize(&descrFifoRX)) >= 10)
    {
        GetCharFromFifo (&descrFifoRX, &CarLu);
        if (CarLu == (int8_t)START)
        {
            startOk = true;

            break;
        }
    }
    if (startOk)
    {
        GetCharFromFifo (&descrFifoRX_USB, &CarLu);
        pDatas->U_32_Bytes.lsb = CarLu;         
        GetCharFromFifo (&descrFifoRX_USB, &CarLu);
        pDatas->U_32_Bytes.byte2  = CarLu;   
        GetCharFromFifo (&descrFifoRX_USB, &CarLu);
        pDatas->U_32_Bytes.byte1  = CarLu; 
        GetCharFromFifo (&descrFifoRX_USB, &CarLu);
        pDatas->U_32_Bytes.msb = CarLu;

         do
        { 
            //copie des donnee dans un tableau
            buffReadName[countCar] = CarLu;
            // lire la prochaine valeur du fifo
            GetCharFromFifo (&descrFifoRX_USB, &CarLu);
            //incrementation dans le tableau
            countCar++;
        }
        while (( CarLu!= END) || (descrFifoRX_USB.pRead == 0));
        
        for( i = 0; i < Nb_Student_max ; i++ )
        {
            x=0;
            //on verifie les lettre d'un eleve
            for( y = 0; y < countCar ; y++ )
            {
                //on compare si ce sont les meme
                if(buffReadName[countCar] == Students_Info[i].StudentName[countCar])
                {
                    x++;
                    if(x == countCar)
                    {
                        //flag pour indiquer que le nom est deja dans la list
                        ID_In_List = true;
                        //on indique quel position dans la list
                        Nb_In_List = i;
                        // on sort de la boucle
                        i = Nb_Student_max;
                    }
                }
                else
                {
                    //on sort de la boucle
                    y=countCar;
                }
            }
        }
    }

} // GetMessagetMessage


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
                //Led_QuestToggle();
                Carac = PLIB_USART_ReceiverByteReceive(USART_ID_1);
                PutCharInFifo(&descrFifoRX, Carac);
                
            }    
            APP_UpdateState(APP_STATE_GET_DATA);
            // buffer is empty, clear interrupt flag
            PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_RECEIVE);
            Message_receive_XBEE = true;
        } else {
            // Suppression des erreurs
            // La lecture des erreurs les efface sauf pour overrun
            if ( (UsartStatus & USART_ERROR_RECEIVER_OVERRUN) == USART_ERROR_RECEIVER_OVERRUN) {
                   PLIB_USART_ReceiverOverrunErrorClear(USART_ID_1);
            }
        }

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
                //Led_QuestToggle();
                //On va chercher les valeurs a envoyer 
                GetCharFromFifo(&descrFifoTX, &Carac);
                PLIB_USART_TransmitterByteSend(USART_ID_1, Carac);
                TXsize = GetReadSize(&descrFifoTX);
                TxBuffFull = PLIB_USART_TransmitterBufferIsFull(USART_ID_1);
                
            }while((TXsize > 0)&& (TxBuffFull == false) && (Carac!= '»'));
            
            
            TXsize = GetReadSize(&descrFifoTX);
            if (TXsize == 0) 
            {
                // Clear the TX interrupt Flag (Seulement apres TX) 
                PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);
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



void __ISR(_UART_2_VECTOR, ipl5AUTO) _IntHandlerDrvUsartInstance1(void)
{
    USART_ERROR UsartStatus;    
    int8_t Carac, TXsize, TxBuffFull;
    // Is this an Error interrupt ?
    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_2_ERROR) &&
            PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_2_ERROR) ) {
        /* Clear pending interrupt */
        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_2_ERROR);
        // Traitement de l'erreur à la réception.
    }
   

    // Is this an RX interrupt ?
    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_2_RECEIVE) &&
            PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_2_RECEIVE) ) {

        // Oui Test si erreur parité ou overrun
        UsartStatus = PLIB_USART_ErrorsGet(USART_ID_2);

        if ( (UsartStatus & (USART_ERROR_PARITY |
            USART_ERROR_FRAMING | USART_ERROR_RECEIVER_OVERRUN)) == 0) 
        {
            while(PLIB_USART_ReceiverDataIsAvailable(USART_ID_2))
            {
                Carac = PLIB_USART_ReceiverByteReceive(USART_ID_2);
                PutCharInFifo(&descrFifoRX, Carac);
            }                     
            // buffer is empty, clear interrupt flag
            PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_2_RECEIVE);
            Message_receive_USB = true;
        } else {
            // Suppression des erreurs
            // La lecture des erreurs les efface sauf pour overrun
            if ( (UsartStatus & USART_ERROR_RECEIVER_OVERRUN) == USART_ERROR_RECEIVER_OVERRUN) {
                   PLIB_USART_ReceiverOverrunErrorClear(USART_ID_2);
            }
        }

    } // end if RX
    
//    // Is this an TX interrupt ?
//    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_2_TRANSMIT) &&
//                 PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_2_TRANSMIT) ) 
//    {
//        
//         
//        // Traitement TX à faire ICI
//        // Envoi des caractères depuis le fifo SW -> buffer HW
//        while (GetReadSize (&descrFifoTX_USB)>0 && !PLIB_USART_TransmitterBufferIsFull(USART_ID_2))
//        {
//            GetCharFromFifo(&descrFifoTX_USB,&Carac);
//            PLIB_USART_TransmitterByteSend(USART_ID_2,Carac);    
//        }    
//        
//        //désactive interrupt car on ne peut plus rien mettre dans le buffer
//        PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_USART_2_TRANSMIT);
//        
//        //clear flag d'interrupt
//        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_2_TRANSMIT);
//    }
    
    // Is this an TX interrupt ?
    if ( PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_2_TRANSMIT) &&
                 PLIB_INT_SourceIsEnabled(INT_ID_0, INT_SOURCE_USART_2_TRANSMIT) ) {
        
        TXsize = GetReadSize(&descrFifoTX_USB);
        TxBuffFull = PLIB_USART_TransmitterBufferIsFull(USART_ID_2);
        if ((TXsize > 0)&& (TxBuffFull == false))
        {
            do//Faire la boucle tant que le message n'est pas envoyé
            {
                //Led_QuestToggle();
                //On va chercher les valeurs a envoyer 
                GetCharFromFifo(&descrFifoTX_USB, &Carac);
                PLIB_USART_TransmitterByteSend(USART_ID_2, Carac);
                TXsize = GetReadSize(&descrFifoTX_USB);
                TxBuffFull = PLIB_USART_TransmitterBufferIsFull(USART_ID_2);
                
            }while((TXsize > 0) && (TxBuffFull == false) && (Carac!= '»'));
            
            TXsize = GetReadSize(&descrFifoTX_USB);
            if (TXsize == 0) 
            {
                //Pour eviter les interruption inutile
                PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_USART_2_TRANSMIT);
                // Clear the TX interrupt Flag (Seulement apres TX) 
                PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_2_TRANSMIT);
                
            }
        }
        else
        {
              // disable TX interrupt (pour éviter une interrupt. inutile si plus rien à transmettre)
             PLIB_INT_SourceDisable(INT_ID_0, INT_SOURCE_USART_2_TRANSMIT);
        }	   
    }
 }