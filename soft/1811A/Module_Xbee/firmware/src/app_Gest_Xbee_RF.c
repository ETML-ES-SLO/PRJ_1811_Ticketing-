/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app_Gest_Xbee_RF.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/
bool Timeout = false;
int Count_Timeout = 0;
APP_DATA appData;

bool test = false;
U_32 Received_ADD;
U_32 Target_ADD;
U_32 Target_ADD_Same;
U_32 DataTX;
U_32 DataRX;



// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    bool GetAM, GetDR, GetCD;
    int32_t Rx_size,Tx_size;
    uint32_t OK = 0x496c5ee3;
    uint32_t ERROR = 0x44b284de ;
    static int nbrOfTimeOut = 0;
    

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
            RF_initialize();
            InitFifoComm();
            
            if (appInitialized)
            {                          
                appData.state = APP_STATE_SERVICE_TASKS;
                //appData.state = APP_SEND_RF_Message;
            }
            break;
        }
        case APP_STATE_SERVICE_TASKS:
        {  
            //Active l'écoute du coté RF
            Activer_Ecoute_RF ();
            
            //On recupère l'info si une adresse a match du coté RF
            GetAM = Get_AM_Value();
            
            //On rrecupère l'info si des infos sont arrivées du coté UART
            Rx_size = GetReadSize(&descrFifoRX);
            
            //si on recois du coté RF
            if(GetAM)
            {
                //Check si le CRC est bon
                GetDR = Get_DR_Value();
                if(GetDR)
                {
                    //Recupération des données recues
                    DataRX.val32 = Get_datas(&Received_ADD.val32);
                    if(DataRX.val32 != OK)
                    {
                        //Récupération de l'adresse de la source
                        Target_ADD.val32 = Received_ADD.val32;
                        //Préparation a la confirmation de reception
                        DataTX.val32 = OK;
                        //Ecriture dans le registre de l'adressse cible
                        //L'adresse du module qui nous a transmis cette tram
                        Ecrire_Addresse_Envoi (Target_ADD.val32);
                        //State d'envoi de réponse
                        appData.state = APP_SEND_RF_Answer;
                    }
                }
            }
            //si on recois du coté UART
            else if(Rx_size >= 8)
            {
                //On récupère les infos dans le Fifo de l'UART
                GetMessage(&Target_ADD, &DataTX);
                //On écrit dans le registre de l'adresse cible
                Ecrire_Addresse_Envoi (Target_ADD.val32);
                //Prochain état envoi de message RF
                appData.state = APP_SEND_RF_Message;              
            }
            break;
        }
        case APP_SEND_RF_Answer:
        {
            //on attend que la bande soit disponible
            while(GetCD)
            {           
                GetCD = Get_CD_Value();
            }
            //On écrit les données a envoyer
            Ecrire_Buffer_Envoi(DataTX.val32); 
            appData.state = APP_SEND_Datas_To_UART;
            break;
        }
        case APP_SEND_Datas_To_UART:
        {
            //On écrit les infos et l'adresse de la source
            //dans le fifo pour un envoi dans le bus UART
            SendMessage (&Target_ADD, &DataRX);
            appData.state = APP_STATE_SERVICE_TASKS;              
            break;
        }
        case APP_SEND_RF_Message:
        {
            //on attend que la bande soit disponible
            while(GetCD)
            {           
                GetCD = Get_CD_Value();
            }
            //On écrit les données a envoyer
            Ecrire_Buffer_Envoi(DataTX.val32);          
            //on start le timer qui gère les timeouts
            DRV_TMR0_Start();
            appData.state = APP_WAIT_FOR_ANSWER;
            break;
        }
        
        case APP_WAIT_FOR_ANSWER:
        {
            //on attend que on nous parle
            GetAM = Get_AM_Value();
            if(GetAM)
            {
                //reset des variables de timeout
                Count_Timeout = 0;   
                nbrOfTimeOut = 0;
                //Arret du timer qui gère les timeouts
                DRV_TMR0_Stop();            
                appData.state = APP_MESSAGE_CHECK_SUCCES;
            }
            //si il y a eu timeout
            else if(Timeout)
            {
                //reset des variable de timeout
                Count_Timeout = 0;    
                Timeout = false;
                //incrémentation du nombres de timeouts
                nbrOfTimeOut ++;
                //si il y a eu 3 timeouts
                if (nbrOfTimeOut >= 4)
                {
                    //on pars dans l'erreur
                    appData.state = APP_SEND_ERROR;
                }
                else
                {   
                    //on renvoie le message
                    appData.state = APP_SEND_RF_Message;
                }
            } 
            break;               
        }
        
        case APP_MESSAGE_CHECK_SUCCES:
        {
            //start du timer 
            DRV_TMR0_Start();
            //Check si le CRC est juste
            GetDR = Get_DR_Value();
            if(GetDR)
            {
                //Reception des info recues en RF
                DataRX.val32 = Get_datas(&Target_ADD_Same.val32);
                //rest de la variable de timeout
                nbrOfTimeOut = 0;
                //on regarde si c'est le même module qui nous parle
                if(Target_ADD.val32 == Target_ADD_Same.val32)
                {
                    //On regarde si on a bien recu une validation de reception
                    if(DataRX.val32 == OK)
                    {
                        appData.state = APP_SEND_SUCCEDED;
                    }
                    else
                    {
                        appData.state = APP_SEND_ERROR;                      
                    }
                }
            }
            //si il y a eu timeout
            else if(Timeout)
            {
                //reset des variables de timeout
                Count_Timeout = 0;    
                Timeout = false;
                //incrémentation du nombres de timeouts
                nbrOfTimeOut ++;
                //si il y a eu 3 timeouts
                if (nbrOfTimeOut >= 4)
                {
                    appData.state = APP_SEND_ERROR;
                }
            }
            break;
        }
        
        case APP_SEND_SUCCEDED:
        {
            //on envoi une confirmation par UART de l'envoi du 
            //message RF
            appData.state = APP_STATE_SERVICE_TASKS;
            break;
        }
        
        case APP_SEND_ERROR:
        {
            //si une erreur a été détectée
            //on envoie par UART l'info comme quoi il y a eu une erreur
            Tx_size = GetReadSize(&descrFifoTX);
            DataTX.val32 = ERROR;
            if(Tx_size >= 9)
            {
                SendMessage (&Target_ADD, &DataTX);
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }
        
        case Wait:
        {
            break;
        }
        /* TODO: implement your application state machine.*/
        

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

 
void CheckTimout (void)
{
    //met la variable "timeout" à 1
    //toutes les 3 secondes
    Count_Timeout ++;
    if(Count_Timeout >= 10)
    {
        Timeout = true;
    } 
}
/*******************************************************************************
 End of File
 */
