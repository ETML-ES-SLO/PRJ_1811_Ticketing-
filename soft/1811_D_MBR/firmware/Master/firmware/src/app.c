
//18111C_Master
//--------------------------------------------------------
// App.c
//--------------------------------------------------------
// 
//
//	Auteur 		: 	
//  Date        :   
//  Version     :   
//  Modifications : MDS 26.09.2022
//  Description :
//          Application principal de la carte ticketing Master 1811C
//   
//
/*--------------------------------------------------------*/


#include "app.h"
#include "app_SDCard.h"
#include "Data_Code.h"
#include "Mc32gest_RS232.h"
#include "Gest_Menu.h"
#include "RF.h"
#include "Mc32gest_RS232.h"
#include "Gest_TFT.h"
#include "Gest_USB.h"
#include "Gest_LINK.h"
#include <stdint.h>


APP_DATA appData;
APP_DATA appData_Old;
APP_DATA appData_callback;


uint8_t Nb_Student = 0;//eleves actuellement en cours de traitement
uint8_t Nb_Student_max = 0;//nombre max de slave/eleve actuellement enregistrer 
bool Message_receive_XBEE;// flag de reception de donnee xbee
bool Message_send_XBEE;// flag de reception de donnee xbee
bool Message_receive_USB;// flag de reception de donnee xbee
bool Message_send_USB = true;// flag de reception de donnee xbee

static bool Waiting_Answer = false;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

/*******************************************************************************
  Function:
    void APP_MainTimer_Callback ( void )
 * 
 * Fonction de callback du timer principal, doit venir toutes les 100ms. Elle 
 * permet de compter des temps de l'app.
 */
void APP_MainTimer_Callback()
{
    if(appData.compt_Link < LINK_DELAY)
    {
        appData.compt_Link++;
    }
    else
    {
        APP_UpdateState(APP_STATE_LINK_XBEE);
        appData.compt_Link = 0;
        appData.compt_Link_HasElapsed = true;
    }
}


/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    appData.state = APP_STATE_INIT;
}
/*******************************************************************************
  Function:
    void APP_UpdateState ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_UpdateState (APP_STATES NewState)
{
    appData.state = NewState;
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    static int Count = 0,I,J;
    int32_t RXSize;
    char trash;
    static uint32_t DataCodeToSend = 0;
    static bool Ticket_Refused = false;
    U_32 RXData;
    U_32 ADD_M;
    U_32 ADD_S;
    bool flagOkpressed = false;
    
    
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            
            DRV_TMR0_Stop();// stoper le timer 1
            
            RF_Init();  // initialisation de l Xbee
 
            TFT_Init(); // initialisation du TFT
            Init_Menu(); // initialisation du menu
            InitFifoComm();// initialisation du fifo
            
            DRV_TMR1_Start(); //Start le timer 2
            APP_UpdateState (APP_STATE_SERVICE_WAIT);//changement d'etat
            
            break;
        }
        case APP_STATE_SERVICE_TASKS:
        {                    
            Gest_Menu();
            APP_UpdateState (APP_STATE_SERVICE_WAIT);//changement d'etat
            break;
        }
        case APP_STATE_SERVICE_WAIT:
        {
            
          break;  
        }
            

        /*case APP_STATE_GEST_MENU:
        {        
            Led_QuestToggle();

            Gest_Menu();//gestion du menu

            break;
        }*/
        case APP_STATE_LINK_XBEE:
        {     
            //AddTarget.val32 = Students_Info[0].ID;
            //AddTarget.val32 = Add_Master;
            DataCodeToSend = ARE_U_LINK;//preparation de l'envoie
            
            //sauvegarde de l'etat precedent
            appData_callback.state = appData.state;
            //changement de l'etat
            APP_UpdateState(APP_STATE_SEND_ID);
            //sauvegarder l'etat
            appData_Old.state = APP_STATE_LINK_XBEE;
            

            break;
        }
        
        case APP_STATE_SEND_ID:
        {    
            if(appData_Old.state == APP_STATE_LINK_XBEE)
            {
                //flag start Link
                LINK = false;
                //flag adresse slave connu
                Add_ON = false;
                //envoie du message
                SendMessage(Add_Master,NULL,DataCodeToSend);
                //flag adresse slave connu
                Add_ON = true;
                //Changement d etat
                APP_UpdateState(APP_STATE_GET_DATA);
            }
            else if(appData_Old.state == APP_STATE_PRESENCE)
            {
                //envoie du message
                SendMessage(Add_Master,Add_Slave,DataCodeToSend);
                //Changement d etat
                APP_UpdateState(APP_STATE_GET_DATA);
                //incrementation de la list
                Nb_In_List++;
            }
            else
            {
                //envoie du message
                SendMessage(Add_Master,Add_Slave,DataCodeToSend);
            }
            
            break;
        }
        case APP_STATE_GET_DATA:
        {               
 
            if(Message_receive_XBEE)
            {
                //reception du message et de l expediteur
               GetMessage(&ADD_S,&ADD_M,&RXData);
                Message_receive_XBEE = false;
                
            }
            else if (Message_receive_USB)
            {
                GetMessage_USB(&RXData);
                Message_receive_USB = false;
            }
               
               
               //on check que l'expediteur est bien le maitre
               if((ADD_M.val32 == Add_Master)||(Waiting_Answer))
                {
                   //on check si l'on recois un ticket ou si on attend une 
                   //reponse de l'utilisateur
                    if ((RXData.val32 == ENVOI_TICKET) || (Waiting_Answer))
                    {
                        //Message_send_USB = true;
                        if(Message_send_USB)
                        {
                            DataCodeToSend = ENVOI_TICKET;
                            SendMessage_USB(DataCodeToSend);
                            Message_send_USB = false;
                        }
                        if(Message_receive_USB)
                        {
                            GetMessage_USB(&RXData);
                            Message_receive_USB = false;
                        }
                                
                        appData_Old.state == APP_STATE_GET_DATA;
                        //start du timer 1
                        DRV_TMR0_Start();
                        Led_QuestOn();
                        //on met un flag d'attente de reponse
                        Waiting_Answer = true ;
                        //si le bounton Acc a ete appuyer
                        if((appButtons.But_ACC)||(RXData.val32 == TICKET_ACCEPT))
                        {
                            
                            //on prepare le data a envoyer
                            DataCodeToSend = TICKET_ACCEPT;
                            //Changement d'etat
                            APP_UpdateState(APP_STATE_SEND_DATA);
                            //on enleve le flag
                            Waiting_Answer = false ;
                            //on arrete le timer 1
                            DRV_TMR0_Stop();
                            Led_QuestOff();

                        }
                        //si le bounton Acc a ete appuyer
                        else if((appButtons.But_DECL)||(RXData.val32 == TICKET_REFUSE))
                        {
                            //on prepare le data a envoyer
                            DataCodeToSend = TICKET_REFUSE;
                            //Changement d'etat
                            APP_UpdateState(APP_STATE_SEND_DATA);
                            //on enleve le flag
                            Waiting_Answer = false ;
                            Add_ON = true;
                            //on arrete le timer 1
                            DRV_TMR0_Stop();
                            Led_QuestOff();
                        }
                        else if(appButtons.But_ESC)
                        {
                            DataCodeToSend= TICKET_RESET;
                            APP_UpdateState(APP_STATE_SEND_DATA);
                            Waiting_Answer = false ;
                            DRV_TMR0_Stop();
                        }
                    }
                    // si l'on recois une adresse d'un noouveau slave
                    if((New_student)&&(!Waiting_Answer))
                    {
                        //on enleve le falg de nouveau slave
                        New_student = false;
                        //on prepare le data a envoyer
                        DataCodeToSend= ACK;
                        //Changement d'etat
                        APP_UpdateState(APP_STATE_SEND_DATA);
                    }
               }
            break;
        }
        case APP_STATE_SEND_DATA:
        {    
            Message_send_USB = true;
            //envoie de message au Xbee

                InitFifoComm();
                SendMessage(Add_Master,Add_Slave,DataCodeToSend);  
                 
                if(appData_Old.state == APP_STATE_LINK_XBEE)
                {   
                    //on retourne au debut de la list
                    Nb_In_List = 0;
                    //Changement d'etat
                    //APP_UpdateState(APP_STATE_PRESENCE);
                    APP_UpdateState(APP_STATE_GET_DATA);
                }
                else if (appData_Old.state == APP_STATE_PRESENCE)
                {
                    //Changement d'etat
                    APP_UpdateState(APP_STATE_PRESENCE);
                    //on incremente la list
                    Nb_In_List++;
                }
                else
                {
                    //Changement d'etat
                    APP_UpdateState(APP_STATE_GET_DATA);
                
            }
            break;
        }
        case APP_STATE_RESET:
        {    
            //TODO
            break;
        }
        case APP_STATE_REFUSE:
        {    
            //Changement d'etat
            APP_UpdateState(APP_STATE_SEND_ID);
            //on prepare le data a envoyer
            DataCodeToSend = TICKET_REFUSE;
            //on prepare l'adress a envoyer
            Add_Slave = Students_Info[Nb_In_List].ID;         
            break;
        }
        case APP_STATE_ACCEPT:
        {    
            //Changement d'etat
            APP_UpdateState(APP_STATE_SEND_ID);
            //on prepare le data a envoyer
            DataCodeToSend = TICKET_ACCEPT;
            //on prepare l'adress a envoyer
            Add_Slave = Students_Info[Nb_In_List].ID;
            //on reduit le nombre max de question
            Students_Info[Nb_In_List].LimitQues --;
            break;
        }
        
        case APP_STATE_PRESENCE:
        {    
            //on prepare le data a envoyer
            DataCodeToSend = ARE_U_LINK;
            //on prepare l'adress a envoyer
            Add_Slave =  Students_Info[Nb_In_List].ID; 
            //si on arrive a la fin de la list
            if(Nb_In_List == Nb_Student_max)
            {
                //Changement d'etat
                APP_UpdateState(APP_STATE_SEND_DATA);
                //on retourne dans l etat avant le pulling
                appData_Old.state == appData_callback.state;
            }
            else
            {
                //Changement d'etat
                appData_Old.state == APP_STATE_PRESENCE;
                //incrémentation de la list
                Nb_In_List++;
            } 
            break;
        }
        default:
        {
            break;
        }
    }
}

 

/*******************************************************************************
 End of File
 */
