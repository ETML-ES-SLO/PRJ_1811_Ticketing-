/* ************************************************************************** */
/** gestion RF via machine d'�tat
 *
 *  @Company
 *    ETML-ES - Simonet Yoann
 *
 *  @File Name
 *    RF_sm.c
 *
 *  @Summary
 *    gestion RF via machine d'�tat
 *
 *  @Description
 *    gestion SPI via machine d'�tat
 *    Test� pour fonctionner avec NRF905
 * 
 *   Cr�ation 14.03.2017 SCA
 *  
*/


#include "peripheral/spi/plib_spi.h"
#include "system/clk/sys_clk.h" // pour SYS_CLK_PeripheralFrequencyGet()
#include "system/int/sys_int.h"
#include "RF_sm.h"
#include "app.h"
#include "Mc32gest_RS232.h"
#include "NRF905SPI.h"

//byte bidon pour envoi lorsqu'uniquement une lecture est demand�e
//le spi �tant full-duplex, une lecture implique forc�ment une �criture simultan�e
#define DUMMY_BYTE  0xF0   
#define ACK         0x06 
#define SOH         0x01  


SPI_STATES RF_State= CONNECTION_REQUEST;

int UNIQUE_value = 0; //valeur entre 0 et 2000

int cont_IDLE =0;
int cont_CONNECTION_REQUEST =0;
int cont_RF_STATE_AWAIT_ACK=0;

char tmp_mess;

//initialisation du NRF905
void Init_SM_RF()
{
    int i;
    //allumer le NRF et le mettre en STBY
    PWR_UP = 1;
    TX_RX_CE =0;
    TX_EN =0;
    for(i=0;i<100000;i++);//attendre environ 20ms
    SPI_InitNRF905();
    //calcule du temps unique
    UNIQUE_value = (myUID%400)+ 100;//de 1 � 5 seconds
    
}

//envoie d' une trame RF
void sendRF(uint32_t add,uint8_t data)
{
    int i;
    //passer en mode Tx
    TX_EN =1;
    //remplire le registre Tx
    SPI_Write_data_TX_NRF905(add,data);
    
    //stat communication avec pulse de 10us 
    TX_RX_CE =1;
    for(i=0;i<5;i++);
    TX_RX_CE =0;
    
    //attendre que la comm soie fini
    while(DR == 0); 
  
    TX_EN =0;
  
}
bool receiverRF(char *pmess)
{
    bool tmp;
   
    TX_RX_CE =1;//se mettre en mode RX
    TX_EN =0;
    
    if(DR)//si il y a une communication avec CRC juste
    {
       *pmess = SPI_Read_data_RX_NRF905(myUID);//recup�rer les datas
       if(*pmess!=0xFF)//si il y a eu un addresse matche
       {
         tmp =true;//Trame OK  
       }
       else
       {
          tmp =false;//Trame not OK   
       } 
    }
    else
    {
       tmp =false;//Trame not OK  
    }
    return tmp;
}

//gestion de la machine d'�tat du SPI pour RF
void RF_DoTasks(void)
{
    switch(RF_State)
    {
        //envoyer un demande de connection toutes les 1 � 5s
        //�couter le reste du temps
        //si r�ponce alore connection OK
        case CONNECTION_REQUEST:
            // si 1 � 5 second et pas de communication
            if((cont_CONNECTION_REQUEST> UNIQUE_value)&&!CD)
            {
               cont_CONNECTION_REQUEST =0;
               sendRF(RX_UART.add,SOH);//envoi demande de connection
            }
            else
            {
               cont_CONNECTION_REQUEST++;
               
               if(receiverRF(&tmp_mess))
               {
                  //si recu ACK
                  if(tmp_mess == ACK)
                  {
                     LINK = 1;//connect�
                     RF_State = RF_STATE_IDLE;
                  }
                  //si recu SOH
                  else if (tmp_mess == SOH)
                  {
                     sendRF(RX_UART.add,ACK);//envoi d' un ACK
                     LINK = 1;//connect�
                     RF_State = RF_STATE_IDLE;
                  }
               } 
            }
            break;
        //attendre une communication Tx ou Rx
        //si temps sans activit� trop long refaire un demande de conection 'SOH' 
        case RF_STATE_IDLE:
            //si on recoi une trame UART � envoier
            if(GetMessage(&RX_UART))
            { 
               cont_IDLE =0;//indiquer activit�
                RF_State = RF_STATE_SEND;//passer en mode Tx
            }
            else if(receiverRF(&tmp_mess))
            {
               cont_IDLE =0;//indiquer activit�
                RF_State = RF_STATE_RECEIVE;//passer en mode Rx 
            }
            else if(cont_IDLE > UNIQUE_value + 1000 )//11s � 15s sans activit� 
            {
               cont_IDLE =0;//indiquer activit�
               sendRF(RX_UART.add,SOH);//envoi demande de connection
               RF_State = RF_STATE_AWAIT_ACK;//attendre ACK
            }
            else
            {
               cont_IDLE++; 
            }
     
            break;
       // envoie une trame en RF    
        case RF_STATE_SEND:
            if(!CD)//si pas de communication
            {
                sendRF(RX_UART.add,RX_UART.data);//Tx data
                RF_State = RF_STATE_AWAIT_ACK;//attendre ACK
            }
             break;
        //gestion de la r�c�ption    
        case RF_STATE_RECEIVE:
            if((tmp_mess>=0x20)&&(tmp_mess<=0x7F))//si on � un carat�re ASCII
            {
                //envoyer data en UART
                TX_UART.data = tmp_mess;
                SendMessage(&TX_UART); 
                RF_State = RF_STATE_SEND_ACK;//send ACK
            }
            else if(tmp_mess == SOH )//si on a une demande de connection
            {
              RF_State = RF_STATE_SEND_ACK;//send ACK  
            }
            else// erreur data
            {
                RF_State = CONNECTION_REQUEST;  
                LINK = 0;
            }
            
             break;
        //attendre un ACK si on attend trop longtemps se d�connecter    
        case RF_STATE_AWAIT_ACK:
            
            if(receiverRF(&tmp_mess))
            {
                cont_RF_STATE_AWAIT_ACK=0;
                if(tmp_mess == ACK)
                {
                   RF_State = RF_STATE_IDLE;
                }
                else 
                {
                  RF_State = CONNECTION_REQUEST; //recicroniser 
                  LINK = 0;
                }
            }
            else
            {
              cont_RF_STATE_AWAIT_ACK++;
              if(cont_RF_STATE_AWAIT_ACK>(500))//si on d�passe 5s
              {
                  RF_State = CONNECTION_REQUEST; //recincroniser 
                  cont_RF_STATE_AWAIT_ACK=0;
                  LINK = 0;
              }
            }            
             break;
            
        case RF_STATE_SEND_ACK:
            sendRF(RX_UART.add,ACK); 
            RF_State = RF_STATE_IDLE;
             break;
    }
    
           
 
}


/* *****************************************************************************
 End of File
 */
