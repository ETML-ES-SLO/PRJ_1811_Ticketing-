#include "app.h"
#include "Gest_LINK.h"
#include "Gest_Menu.h"
#include "Mc32gest_RS232.h"
#include "Data_Code.h"
#include "app_SDCard.h"

void Xbee_Link ()
{
    int Rx_Taille;
    U_32 Rx_Message;
    U_32 AddSource;
    U_32 TX_Message;
    U_32 AddTarget;
    
    TX_Message.val32 = ARE_U_LINK;
    //AddTarget.val32 = Students_Info[0].ID;
    //AddTarget.val32 = Add_Master;
    AddTarget.val32 = ADD_BROADCAST;
    //todo
    SendMessage(AddTarget.val32,TX_Message.val32);
    if(Message_receive_XBEE)
    {
        Rx_Taille = GetReadSize(&descrFifoRX);
        while(Rx_Taille < 8)
        {   
            Rx_Taille = GetReadSize(&descrFifoRX);
        }
        //todo
       GetMessage(&AddSource,&Rx_Message);
        TX_Message.val32 = ACK;
        AddTarget.val32 =  Students_Info[0].ID;
        //todo
      SendMessage(AddTarget.val32,TX_Message.val32);  
    }
                              
}