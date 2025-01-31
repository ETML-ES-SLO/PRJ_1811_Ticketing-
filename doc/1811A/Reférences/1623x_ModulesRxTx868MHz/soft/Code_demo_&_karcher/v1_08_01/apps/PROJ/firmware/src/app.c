/*--------------------------------------------------------*/
// app.c
/*--------------------------------------------------------*/
//	Auteur 		: 	Y. Simonet
//  data        :   16.06.2017
//  
/*--------------------------------------------------------*/

#include "app.h"
#include "Mc32gest_RS232.h"
#include "Mc32gestI2c24AA02.h"
#include "NRF905SPI.h"
#include "RF_sm.h"
#include <stdint.h>                   
#include <stdbool.h>
#include <proc/p32mx130f064b.h>

//#include <proc/p32mx795f512l.h>

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
S_UART_message RX_UART; 
S_UART_message TX_UART;
int cout =0;
unsigned int myUID;
int i =0;
int mode=0;
char TMP_RX;
char TMP_TX;
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

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
            // Active les timers,FIFO et port 
            InitFifoComm();
            DRV_TMR0_Start();
            PORT_INIT();
            
            I2C_Init24AA02();
            myUID = I2C_Read_UID_24AA02_F();
            

            Init_SM_RF();
            
            TX_UART.com= 0x00;
            TX_UART.data=0x00;
            TX_UART.add = myUID;
            
            RX_UART.add =0;
            RX_UART.data ='0';
            
            SendMessage(&TX_UART);
            
            
           
            

            if (appInitialized)
            {
                
                appData.state = APP_STATE_WAIT;
            }
            break;
        }
        //toutes les 10 ms
        case APP_STATE_SERVICE_TASKS:
        {
           
            IO_1 = !IO_1;
        
   
            
            if(1)
            {
                switch (2)
                {
                    case 0:
                    {
                        RF_DoTasks();//bidirectionelle
                        break;
                    }
                    case 1:
                    {
                        if(GetMessage(&RX_UART)) // mode TX simple
                        {
                             
                            sendRF(RX_UART.add,RX_UART.data); 
                        }
                        sendRF(RX_UART.add,RX_UART.data); 
//                        if(receiverRF(&TX_UART.data))//mode RX simple
//                        {
//                            SendMessage(&TX_UART);
//                        }
                        
                        LINK =1;
                        break;
                    }
                    case 2:
                    {
                        if(receiverRF(&TMP_RX))//mode RX simple
                        {
                            if((TMP_RX >= '0')&&(TMP_RX <= 'Z'))
                            {
                                TX_UART.data = TMP_RX;
                                SendMessage(&TX_UART); 
                            }     
                        } 
//                        else if(GetMessage(&RX_UART)) // mode TX simple
//                        {
//                             
//                            sendRF(RX_UART.add,RX_UART.data); 
//                            TX_RX_CE =1;
//                        }
//                        if(receiverRF(&TMP_RX))//mode RX simple
//                        {
//                            if((TMP_RX >= '0')&&(TMP_RX <= 'Z'))
//                            {
//                                TX_UART.data = TMP_RX;
//                                SendMessage(&TX_UART); 
//                            }     
//                        } 
                         
                       
                        LINK =1;
                        break;
                    }
                }   
                
            }
            else
            {
                LINK =0;
                RF_State= CONNECTION_REQUEST;
                //implémenter la gestion des commande
                if(GetMessage(&RX_UART))
                {
                  mode = RX_UART.com;  
                }
            }
            appData.state = APP_STATE_WAIT;
           break;
        }
        
        case APP_STATE_WAIT :
          // nothing to do
            break;
        /* TODO: implement your application state machine.*/
        

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
           
    }
   
    
} 
void PORT_INIT(void)
{
  //port define

//IOs
TRISBbits.TRISB2 = 0; 
TRISBbits.TRISB3 = 0;
 
//gest nrf905
//output
TRISAbits.TRISA2 = 0; 
TRISAbits.TRISA3 = 0;
TRISBbits.TRISB5 = 0; 
TRISBbits.TRISB14 = 0;
//input
TRISBbits.TRISB10 = 1; 
TRISBbits.TRISB11 = 1;
TRISBbits.TRISB12 = 1; 

//gest pic    
//output
TRISAbits.TRISA1 = 0; 
    
//input 
TRISAbits.TRISA0 = 1; 
TRISBbits.TRISB7 = 1;

}

 

/*******************************************************************************
 End of File
 */
