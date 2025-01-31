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

#include "app.h"

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

APP_DATA appData;
APP_DATA appData_Old;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

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
    static int Count = 0;
    int RXSize;
    char trash;
    static uint32_t DataCodeToSend = 0;
    static uint32_t Address_Master = ADD_MASTER;
    static bool Ticket_Refused = false;
    U_32 RXData;
    U_32 SourceADD;
    
  
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            InitFifoComm();
            bool appInitialized = true;
            //start du timer
            DRV_TMR0_Start();
            ALL_LED_OFF;
            if (appInitialized)
            {
                
                //appData.state = APP_SEND;
                appData.state = APP_WAIT_FOR_LINK;
                //appData.state = APP_READY_TO_SEND;
            }
            break;
        }
        case APP_WAIT_FOR_LINK:
        {
            //Attente d'un message au niveau de l'UART
            RXSize = GetReadSize(&descrFifoRX);
            if(RXSize >= 8)
            {
                //on récupère le message
                GetMessage(&SourceADD,&RXData);
                //on vérifie que ca soie bien le maitre qui nous parle
                if(SourceADD.val32 == ADD_MASTER)
                {
                    //On vérifie que le message recu est bien un message de link
                    if(RXData.val32 == ARE_U_LINK)
                    {
                        //on prépare le message de réponse
                        DataCodeToSend = I_AM_LINK;
                        //stop le timer de clignotement des LEDs
                        DRV_TMR0_Stop();
                        ALL_LED_OFF
                        appData.state = APP_SEND;
                        appData_Old.state = APP_WAIT_FOR_LINK;
                    }
                    else
                    {
                        appData.state = APP_ERROR;
                    }
                }
                else
                {
                    appData.state = APP_ERROR;  
                }
            }
            break;
        }

        case APP_READY_TO_SEND:
        {
            //On allume la LED verte
            LED_READY_ON
            //On attend que l'utilisateur appuie sur le bouton
            if(PLIB_PORTS_PinGet(PORTS_ID_0,PORT_CHANNEL_B,PORTS_BIT_POS_7))
            {
                //on prépare l'envoi du ticket
                DataCodeToSend = ENVOI_TICKET;
                //LED verte éteinte
                LED_READY_OFF
                //LED orange allumée
                LED_WAIT_ON
                appData_Old.state = APP_READY_TO_SEND;
                appData.state = APP_SEND;
            }
            break;
        }
        
        case APP_SEND:
        {
            //envoi du message et de l'adresse du module maitre par UART
            SendMessage(Address_Master, DataCodeToSend);      
            appData.state = APP_WAIT_FOR_ACK;
            break;
        }
        
        case APP_WAIT_FOR_ACK:
        {
            //On attend une reception sur le bus UART
            RXSize = GetReadSize(&descrFifoRX);
            if(RXSize >= 8)
            {
               //reception du message et de la source
               GetMessage(&SourceADD,&RXData);
               
               //on check que la source est bien le maitre
               if(SourceADD.val32 == ADD_MASTER)
                {
                    if(RXData.val32 == ACK)
                    {
                        //comme il sagissait d'un envoi de donné
                        //on regarde quel etat l'as provoqué pour
                        //ensuite le rediriger au bon état suivant
                        switch(appData_Old.state)
                        {
                            case APP_WAIT_FOR_LINK:
                            {
                                DRV_TMR0_Stop();
                                appData_Old.state = APP_WAIT_FOR_ACK;
                                appData.state = APP_READY_TO_SEND;
                                break;
                            }
                            case APP_READY_TO_SEND:
                            {
                                LED_WAIT_OFF
                                appData_Old.state = APP_WAIT_FOR_ACK;
                                appData.state = APP_WAIT_FOR_TICKET_ACCEPT;
                                break;
                            }
                            case APP_WAIT_FOR_TICKET_ACCEPT:
                            {
                                LED_WAIT_OFF
                                appData.state = APP_READY_TO_SEND;
                                break;
                            }

                        }
                    }
                    else
                    {
                        appData.state = APP_ERROR;
                    }
                }                    
            }
            break;
        }
        
        case APP_WAIT_FOR_TICKET_ACCEPT:
        {
            //Led d'attente
            LED_WAIT_ON
            //on regarde si on recois un message via l'UART        
            RXSize = GetReadSize(&descrFifoRX);
            if(RXSize >= 8)
            {
                //reception du message
                GetMessage(&SourceADD,&RXData);
                //check si la source est bien le maitre
                if(SourceADD.val32 == ADD_MASTER)
                {
                    //ici on regarde l'info qui nous a été retourné
                    //et selon la réponse retournée et redirige sur les
                    //diffèrents états
                    if(RXData.val32 == TICKET_ACCEPT)
                    {
                        appData.state = APP_ACCEPT;
                    }
                    else if(RXData.val32 == TICKET_REFUSE)
                    {
                        Ticket_Refused = true;
                        appData.state = APP_REFUSED;
                    }
                    else if(RXData.val32 == BLOCKED)
                    {
                        appData.state = APP_BLOCKED;
                    }
                    else if(RXData.val32 == TICKET_RESET)
                    {
                        appData.state = APP_RESET;
                    }
                    else
                    {
                        appData.state = APP_ERROR;
                    }
                }
            }
            //si l'utilisateur appuie longtemps sur le bouton
            //il générera une annulation du ticket
            if(PLIB_PORTS_PinGet(PORTS_ID_0,PORT_CHANNEL_B,PORTS_BIT_POS_7))
            {
                Count ++;
                if(Count >= 5000)
                {
                    DataCodeToSend = TICKET_ANNULER;
                    appData.state = APP_SEND;
                    appData_Old.state = APP_WAIT_FOR_TICKET_ACCEPT;
                }
            }
            else
            {
                Count = 0;
            }
            break;
        }
        
        case APP_ACCEPT:
        {
            //si le ticket a accepté
            //on fait clignoté la led verte
            //et on retourne dans le ready to send
            LED_WAIT_OFF
            Blink_LED_ACC();            
            appData.state = APP_READY_TO_SEND;        
            break;
        }
        
        case APP_REFUSED:
        {
            //si le ticket a été refusé 
            //on allume la led rouge
            //et on bloque l'envoi de ticket pendant un moment
            //dépbloquage via le temps ou le reset de ticket
            LED_BLOCKED_ON
            if(Ticket_Refused == false) //débloqué par le timer
            {
               LED_BLOCKED_OFF
               appData.state = APP_READY_TO_SEND;    
            }
            //Reception du message de reset
            RXSize = GetReadSize(&descrFifoRX);
            if(RXSize >= 8)
            {
                GetMessage(&SourceADD,&RXData);
                if(SourceADD.val32 == ADD_MASTER)
                {
                    if(RXData.val32 == TICKET_RESET)
                    {
                        LED_BLOCKED_OFF
                        appData.state = APP_READY_TO_SEND;                      
                    }
                }
            }
            break;
        }
        
        case APP_BLOCKED:
        {
            //on se retrouve dans cet état si on a épuisé notre
            //quota de questions
            //l'unique moyen 
            LED_BLOCKED_ON
            RXSize = GetReadSize(&descrFifoRX);
            if(RXSize >= 8)
            {
                GetMessage(&SourceADD,&RXData);
                if(SourceADD.val32 == ADD_MASTER)
                {
                    if(RXData.val32 == TICKET_RESET)
                    {
                        LED_BLOCKED_OFF
                        appData.state = APP_RESET;                      
                    }
                }
            }   
            break;
        }
        
        case APP_ERROR:
        {
            //vide le FIFO
            RXSize = GetReadSize(&descrFifoRX);
            {
                while (RXSize > 0)
                {
                    GetCharFromFifo(&descrFifoRX, &trash);
                    RXSize --;
                }
                appData.state = APP_WAIT_FOR_LINK;
            }
            break;
        }
        
        case APP_RESET:
        {
            //Vide le FIFO
            RXSize = GetReadSize(&descrFifoRX);
            {
                while (RXSize > 0)
                {
                    GetCharFromFifo(&descrFifoRX, &trash);
                    RXSize --;
                }
                appData.state = APP_READY_TO_SEND;
            }
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

 
void Blink_LED_ACC (void)
{
    int I;
    ALL_LED_OFF
    for(I = 0; I < 5000; I ++)
    {
        
    }
    ALL_LED_ON
    for(I = 0; I < 5000; I ++)
    {
        
    }
    ALL_LED_OFF
}

/*******************************************************************************
 End of File
 */
