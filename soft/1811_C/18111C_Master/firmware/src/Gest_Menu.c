//18111C_Master
//--------------------------------------------------------
// Gest_Menu.c
//--------------------------------------------------------
// 
//
//	Auteur 		: 	
//  Date        :   
//  Version     :   
//  Modifications : MDS 26.09.2022
//  Desciption  :
//      Gestion des bouton et du menu de la carte Ticketing Master 1811C
//
/*--------------------------------------------------------*/

#include "app.h"
#include "Mc32gest_RS232.h"
#include "Data_Code.h"
#include "Gest_Menu.h"
#include "app_SDCard.h"
//#include "system_config.h"

bool CNA0IsEnable = true;      //Bouton Decline
bool CNA1IsEnable = true;      //Bouton Reset Tickets
bool CNA7IsEnable = true;      //Bouton Accept
bool CNA8IsEnable = true;      //Bouton OK
bool CNB3IsEnable = true;      //Bouton Down
bool CNB4IsEnable = true;      //Bouton UP
bool CNB13IsEnable = true;     //Bouton ESC

bool flagUpPressed = false;
bool flagDownPressed = false;
bool flagEscPressed = false;
bool flagOkpressed = false;
bool flagACCPressed = false;
bool flagDECLPressed = false;
bool flagRESETpressed = false;

int Nb_Students_In_List ;
uint32_t List [];


void Gest_Menu ()
{
    U_32 Target_ADD, TX_Data, RX_Data, ADD_Source;
    static int tmp = 0;
    int SizeTX, SizeRX;
    static int I,J,PosCursorConfig;
   
    switch (MenuList)
    {
        /**********************************************************************/
        /*                      MENU_MenuPrincipal                            */
        /**********************************************************************/        
        case MENU_MenuPrincipal:
        {          
            if (appButtons.But_UP)
            {
                if(MenuSelected == SELECTED_LIST)
                {
                    MenuSelected = SELECTED_Configuration;
                }
                else
                {
                    MenuSelected --;
                }
                TFT_Cursor_MenuPrincipale ();
                ClearALLButtons();
            }
            else if (appButtons.But_Down)
            {
                if(MenuSelected == SELECTED_Configuration)
                {
                    MenuSelected = SELECTED_LIST;
                }
                else 
                {
                    MenuSelected ++;
                }
                TFT_Cursor_MenuPrincipale ();
                ClearALLButtons();
            }
            else if (appButtons.But_OK)
            {                
                if(MenuSelected != SELECTED_NONE)
                {
                    MenuList = MenuSelected;       
                    if(MenuSelected == SELECTED_LIST)
                    {
                        TFT_Font_List();
                        if(Nb_Students_In_List > 9)
                        {
                            TFT_aff_list_more (Nb_Students_In_List - 9);
                        }
                    }
                    else if(MenuSelected == SELECTED_Configuration)
                    {
                        MenuList = MENU_Config; 
                        PosCursorConfig = 0;
                        TFT_Font_config();
                        TFT_aff_all_students();
                    }
                }
                ClearALLButtons();
            }     
            break;
        }          
        
        case MENU_List:
        {
            if (Nb_Students_In_List > 0)
            {
                for(I = 1; I < Nb_Students_In_List; I ++)
                {
                    if(I > 8)
                    {
                        I = Nb_Students_In_List;
                    }
                    for (J = 0;J < 9; J++)
                    {       
                        if(Students_Info[J].ID == List[I-1])
                        {                        
                            TFT_Aff_List(I,Students_Info[J].StudentName);
                            J = 10;
                        }
                    }    
                }
            }
            MenuList = Idle;
            break;
        }
        
        case Idle:
        {
//            if(appButtons.But_ESC)
//            {
//                MenuList = MENU_MenuPrincipal;
//                TFT_Cursor_MenuPrincipale ();
//                TFT_Menu_Principal ();  
//                ClearALLButtons();
//            }
//            if(appButtons.But_ACC)
//            {
//                
//                
//                TFT_Font_List();
//                if(Nb_Students_In_List > 9)
//                {
//                    TFT_aff_list_more (Nb_Students_In_List - 9);
//                }
//                MenuList = MENU_List;   
//                I = I_Nbstudents;
//                ClearALLButtons();
//            }
//            if(appButtons.But_DECL)
//            {
//                
//                
//                TFT_Font_List();
//                if(Nb_Students_In_List > 9)
//                {
//                    TFT_aff_list_more (Nb_Students_In_List - 9);
//                }
//                ClearALLButtons();
//                I = I_Nbstudents;
//                MenuList = MENU_List;
//            }
//            if(appButtons.But_Reset_Tick)
//            {
//                
//                
//                TFT_Font_List();
//                if(Nb_Students_In_List > 9)
//                {
//                    TFT_aff_list_more (Nb_Students_In_List - 9);
//                }
//                ClearALLButtons();
//                I = I_Nbstudents;
//                MenuList = MENU_List;
//            }
            break;
        }
        
        case MENU_Config:
        {
            if(appButtons.But_UP)
            {
                if(PosCursorConfig != 0)
                {
                    PosCursorConfig ++;
                    TFT_Update_Config_cursor (PosCursorConfig);
                }
                ClearALLButtons();
            }
            else if(appButtons.But_Down)
            {
                if(PosCursorConfig < I_Nbstudents)
                {
                    PosCursorConfig --;
                    TFT_Update_Config_cursor (PosCursorConfig);
                }
                ClearALLButtons();
            }
            else if(appButtons.But_OK)
            {
                
                ClearALLButtons();
            }
            else if(appButtons.But_ESC)
            {
                
                ClearALLButtons();
            }
            break;
        }

        case MENU_Initialisation:
        {         
            Menu_loading_init ();
        }
        break;     
    }
}


void Init_Menu (void)
{
    ClearALLButtons();
    MenuList = MENU_Initialisation;
    MenuSelected = SELECTED_NONE;
}

void MenuChange (MENU NewMenu)
{
    MenuList = NewMenu;
}

void ClearALLButtons (void)
{
    appButtons.But_Down = false;
    appButtons.But_ESC = false;
    appButtons.But_OK = false;
    appButtons.But_UP = false;
    appButtons.But_DECL = false;
    appButtons.But_Reset_Tick = false;
    appButtons.But_ACC = false;
}

void Menu_loading_init (void)
{
    int I = 0;
    int J = 0;
    int Rx_Taille;
    U_32 Rx_Message;
    U_32 AddSource;
    U_32 TX_Message;
    U_32 AddTarget;
    static int init_status = 0;
 


    switch (init_status)
    {
        case 0:
        {
            if(SDCARDPLUGED)
            {
                TFT_SD_PLUG_OK ();     
                init_status ++;
            }
            else
            {
                init_status = 6;
            }
            break;
        }
        case 1:
        {
            if(SDCARDMOUNTED)
            {
                TFT_SD_Mount_OK();
                init_status ++;
            }
            break;
        }
        case 2:
        {
            if(SDCARDFILEFOUND)
            {
                TFT_Student_File_Detected();
                init_status ++;
            }
            break;
        }
        case 3:
        {
            if(SDCARDFILEREADED)
            {
                TFT_List_Of_Students_OK ();
                TFT_Students_Found(Nbstudents);
                init_status ++;
            }
            break;
        }
        case 4:
        {
            if(!Students_Info[I].IsOk )
            {
                TFT_Cheking_Link();
                init_status ++;
                break;
            }
            break;
              
        }
        case 5:
        {
            J = 0;
            for(I = 0; I < I_Nbstudents; I ++)
            {
                if (Students_Info[I].IsOk == true)
                {
                    J++;
                }
            }
            TFT_Students_Link (J);
            init_status ++;
            TFT_Init_OK ();
            break;         
        }
        case 6:
        {
            MenuList = MENU_MenuPrincipal;
            TFT_Cursor_MenuPrincipale ();
            TFT_Menu_Principal ();          
            ClearALLButtons();
            init_status = 0;
//            if(appButtons.But_ACC)
//            {
//                MenuList = MENU_MenuPrincipal;
//                TFT_Cursor_MenuPrincipale ();
//                TFT_Menu_Principal ();          
//                ClearALLButtons();
//                init_status = 0;
//            }
//            else if (appButtons.But_DECL)
//            {
//                init_status = 0;
//                TFT_Font_debug();
//                ClearALLButtons();
//            }
//            break;
        }
    }
}



//interruption lors de changement d'etat sur les boutons
void __ISR(_CHANGE_NOTICE_VECTOR, ipl3AUTO) _IntHandlerChangeNotification(void)
{      
    APP_UpdateState(APP_STATE_GEST_MENU);
      
    //Bouton DECLINE
    if (PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0) && (CNA0IsEnable))
    {
        flagDECLPressed = true;       
    }
   
    //Bouton RESET TICKET
    if (PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_1) && (CNA1IsEnable))
    {
        flagRESETpressed = true;
    }   
    
    //Bouton ACCEPT
    if (PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_7) && (CNA7IsEnable))
    {
        flagACCPressed = true;
    }
     
    //Bouton OK
    if (PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_8) && (CNA8IsEnable))
    {
        flagOkpressed = true;
    }
    
    //Bouton DOWN
    if (PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_3) && (CNB3IsEnable))
    {
        flagDownPressed = true;
    }
    
    //Bouton UP
    if (PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_4) && (CNB4IsEnable))
    {
        flagUpPressed = true;
    }
    
    //Bouton ESC
    if (PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_13) && (CNB13IsEnable))
    {
        flagEscPressed = true;
    }
    
    /********************************************************************************/
    if (flagDECLPressed)
    {
        if(!PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0))
        {
            appButtons.But_DECL = true;
            flagDECLPressed = false;
        }
    }
    if (flagRESETpressed)
    {
        if(!PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_1))
        {
            appButtons.But_Reset_Tick= true;
            flagRESETpressed = false;
        }
    }
    if (flagACCPressed)
    {
        if(!PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_7))
        {
            appButtons.But_ACC = true;
            flagACCPressed = false;
        }
    }
    if (flagOkpressed)
    {
        if(!PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_8))
        {
            appButtons.But_OK = true;
            flagOkpressed = false;
        }
    }
    
    if (flagDownPressed)
    {
        if(!PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_3))
        {
            appButtons.But_Down = true;
            flagDownPressed = false;
        }
    }
    
    if (flagUpPressed)
    {
        if(!PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_4))
        {
            appButtons.But_UP = true;
            flagUpPressed = false;
        }
    }
       
    if (flagEscPressed)
    {
        if(!PLIB_PORTS_PinGet (PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_13))
        {
            appButtons.But_ESC = true;
            flagEscPressed = false;
        }
    }
    
    PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_CHANGE_NOTICE_A);
    PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_CHANGE_NOTICE_B);
}