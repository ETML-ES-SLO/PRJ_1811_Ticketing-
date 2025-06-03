/* ************************************************************************** */
/** Descriptive Spectrogram_Gest_CoreTimer

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */
#include "Gest_TFT.h"


void TFT_Init (void)
{
    tft_begin(); 
    setRotation(1);
    tft_fillScreen(ILI9341_BLACK);  
    TFT_Font_debug ();
}

void TFT_MeasureBackGround (void)
{
    tft_fillRect(10,10,300,220,ILI9341_WHITE);   
    tft_setTextSize(2);
    tft_setCursor(15,15);
    tft_setTextColor(ILI9341_BLACK);
    tft_writeString("Ticketing Martins");
    tft_drawFastHLine(15,31,240,ILI9341_BLACK);
}

void TFT_Menu_Principal (void)
{
    tft_fillScreen(ILI9341_BLACK);
    tft_fillRect(10,10,300,220,0x221F);
    tft_setTextSize(2);
    tft_setCursor(15,15);
    tft_setTextColor(ILI9341_WHITE);
    tft_writeString("Ticketing Martins");
    tft_drawFastHLine(10,31,300,ILI9341_WHITE);
    tft_drawFastHLine(10,32,300,ILI9341_WHITE);
    tft_setTextSize(3);
    tft_setCursor(90,50);
    tft_writeString("Liste");
    tft_setCursor(90,100);
    tft_writeString("Config");
}

void TFT_Font_debug (void)
{
    
    /*tft_fillScreen(ILI9341_WHITE);
    tft_drawFastHLine(23,30,10,ILI9341_BLUE);
    tft_drawFastHLine(19,31,18,ILI9341_BLUE);
    tft_drawFastHLine(17,32,22,ILI9341_BLUE);
    tft_drawFastHLine(15,33,26,ILI9341_BLUE);
    tft_drawFastHLine(14,34,28,ILI9341_BLUE);
    tft_drawFastHLine(12,35,32,ILI9341_BLUE);
    tft_drawFastHLine(11,36,34,ILI9341_BLUE);
    tft_drawFastHLine(10,37,36,ILI9341_BLUE);
    tft_drawFastHLine(9,38,38,ILI9341_BLUE);
    tft_drawFastHLine(8,39,40,ILI9341_BLUE);
    tft_drawFastHLine(8,40,40,ILI9341_BLUE);
    tft_drawFastHLine(7,41,42,ILI9341_BLUE);
    tft_drawFastHLine(7,42,42,ILI9341_BLUE);
    tft_drawFastHLine(6,43,44,ILI9341_BLUE);
    tft_drawFastHLine(6,44,44,ILI9341_BLUE);
    tft_drawFastHLine(6,45,44,ILI9341_BLUE);
    tft_drawFastHLine(6,46,44,ILI9341_BLUE);
    tft_drawFastHLine(5,47,46,ILI9341_BLUE);
    tft_drawFastHLine(5,48,46,ILI9341_BLUE);
    tft_drawFastHLine(5,49,46,ILI9341_BLUE);
    tft_drawFastHLine(5,50,46,ILI9341_BLUE);
    tft_drawFastHLine(5,51,46,ILI9341_BLUE);
    tft_drawFastHLine(5,52,46,ILI9341_BLUE);
    tft_drawFastHLine(5,53,46,ILI9341_BLUE);
    tft_drawFastHLine(5,54,46,ILI9341_BLUE);
    tft_drawFastHLine(5,55,46,ILI9341_BLUE);
    tft_drawFastHLine(5,56,46,ILI9341_BLUE);
    tft_drawFastHLine(6,57,44,ILI9341_BLUE);
    tft_drawFastHLine(6,58,44,ILI9341_BLUE);
    tft_drawFastHLine(6,59,44,ILI9341_BLUE);
    tft_drawFastHLine(6,60,44,ILI9341_BLUE);  
    tft_drawFastHLine(7,61,42,ILI9341_BLUE);
    tft_drawFastHLine(7,62,42,ILI9341_BLUE);
    tft_drawFastHLine(8,63,40,ILI9341_BLUE);
    tft_drawFastHLine(8,64,40,ILI9341_BLUE);
    tft_drawFastHLine(9,65,38,ILI9341_BLUE);
    tft_drawFastHLine(10,66,36,ILI9341_BLUE);
    tft_drawFastHLine(11,67,34,ILI9341_BLUE);
    tft_drawFastHLine(12,68,32,ILI9341_BLUE);
    tft_drawFastHLine(14,69,28,ILI9341_BLUE);
    tft_drawFastHLine(15,70,26,ILI9341_BLUE);
    tft_drawFastHLine(17,71,22,ILI9341_BLUE);
    tft_drawFastHLine(19,72,18,ILI9341_BLUE);
    tft_drawFastHLine(23,73,10,ILI9341_BLUE);
    tft_setTextSize(3);
    tft_setCursor(12,42);
    tft_setTextColor(ILI9341_WHITE);
    tft_writeString("Es");      
    
    tft_drawFastHLine(48,25,5,ILI9341_BLUE);
    tft_drawFastHLine(46,26,9,ILI9341_BLUE);
    tft_drawFastHLine(45,27,11,ILI9341_BLUE);
    tft_drawFastHLine(44,28,13,ILI9341_BLUE);
    tft_drawFastHLine(44,29,13,ILI9341_BLUE);
    tft_drawFastHLine(43,30,15,ILI9341_BLUE);
    tft_drawFastHLine(43,31,15,ILI9341_BLUE);
    tft_drawFastHLine(43,32,15,ILI9341_BLUE);
    tft_drawFastHLine(43,33,15,ILI9341_BLUE);
    tft_drawFastHLine(43,34,15,ILI9341_BLUE);
    tft_drawFastHLine(44,35,13,ILI9341_BLUE);
    tft_drawFastHLine(44,36,13,ILI9341_BLUE);
    tft_drawFastHLine(45,37,11,ILI9341_BLUE);
    tft_drawFastHLine(46,38,9,ILI9341_BLUE);
    tft_drawFastHLine(48,39,5,ILI9341_BLUE);
    tft_setTextSize(2);
    tft_setCursor(46,26);
    tft_setTextColor(ILI9341_WHITE);
    tft_writeString("+");   
    tft_setTextSize(1);
    tft_setCursor(18,75);
    tft_setTextColor(ILI9341_BLUE);
    tft_writeString("ETML");   
    
    tft_setTextSize(4);
    tft_setCursor(20,120);
    tft_setTextColor(ILI9341_BLACK);
    tft_writeString("Bienvenue !");*/
    
    
    tft_fillRect(10,10,300,220,ILI9341_BLACK);
    tft_setTextSize(2);
    tft_setCursor(10,10);
    tft_setTextColor(ILI9341_WHITE);
    tft_writeString("Initializing");
    tft_drawFastHLine(10,31,300,ILI9341_WHITE);
    tft_drawFastHLine(10,32,300,ILI9341_WHITE);
    tft_setTextSize(1);
    
    tft_setCursor(10,50);
    tft_writeString("SD Is Plugged:");
    
    tft_setCursor(10,70);
    tft_writeString("SD Mount:");
    
    tft_setCursor(10,90);
    tft_writeString("Student file found:");
    
    tft_setCursor(10,110);
    tft_writeString("Getting list of students:");
    
    tft_setCursor(10,130);
    tft_writeString("Students found:");
    
    tft_setCursor(10,150);
    tft_writeString("checking link:");  
    
    tft_setCursor(10,170);
    tft_writeString("Students link:");  
           
}

void TFT_SD_PLUG_OK (void)
{
    tft_setTextSize(1);
    tft_setTextColor(ILI9341_WHITE);
    tft_setCursor(95,50);
    tft_writeString("OK");
}

void TFT_SD_Mount_OK (void)
{
    tft_setTextSize(1);
    tft_setTextColor(ILI9341_WHITE);
    tft_setCursor(65,70);
    tft_writeString("OK");
}

void TFT_Student_File_Detected (void)
{
    tft_setTextSize(1);
    tft_setTextColor(ILI9341_WHITE);
    tft_setCursor(125,90);
    tft_writeString("OK");
}


void TFT_List_Of_Students_OK (void)
{
    tft_setTextSize(1);
    tft_setTextColor(ILI9341_WHITE);
    tft_setCursor(160,110);
    tft_writeString("OK");
}

void TFT_Students_Found (char T_Nb_Students [3])
{
    tft_setTextSize(1);
    tft_setTextColor(ILI9341_WHITE);
    tft_setCursor(100,130);
    tft_writeString(T_Nb_Students);
}

void TFT_Cheking_Link (void)
{
    tft_setTextSize(1);
    tft_setTextColor(ILI9341_WHITE);
    tft_setCursor(95,150);
    tft_writeString("OK");
    
}

void TFT_Students_Link (int Nb_Link)
{
    char T_Nb_Students [3];
    sprintf(T_Nb_Students,"%d",Nb_Link);
    tft_setTextSize(1);
    tft_setTextColor(ILI9341_WHITE);
    tft_setCursor(95,170);
    tft_writeString(T_Nb_Students);
}

void TFT_Init_OK (void)
{
    tft_setTextSize(2);
    tft_setTextColor(ILI9341_WHITE);
    tft_setCursor(10,190);
    tft_writeString("OK tap green");
    tft_setCursor(10,220);
    tft_writeString("Re_Init tap Red");
}


void TFT_Aff_List (int I, char StudentName [15])
{
    tft_setTextSize(2);
    tft_setTextColor(ILI9341_WHITE);
    tft_setCursor(30,(35+((I-1)*20)));
    tft_writeString(StudentName);
}

void TFT_aff_list_more (int I)
{
    char more [9];
    sprintf(more,"more %d v",I);
    tft_setTextSize(2);
    tft_setTextColor(ILI9341_WHITE);
    tft_setCursor(20,215);
    tft_writeString(more);
}

void TFT_Cursor_MenuPrincipale (void)
{
    static int LastCursorPos = 0;
    tft_setTextSize(4);
    switch (MenuSelected)
    {
        case SELECTED_NONE:
        {
            if(LastCursorPos != 0)
            {
                //clear L'ancien Curseur 
                tft_fillRect(40,LastCursorPos,20,28,0x221F);             
            }
            break;
        }
        case SELECTED_LIST:
        {
            if(LastCursorPos != 0)
            {
                //clear L'ancien Curseur 
                tft_fillRect(40,LastCursorPos,20,28,0x221F);  
            }
            tft_setCursor(40,50);
            tft_writeString(">");
            LastCursorPos = 50;
            break;
        }
        case SELECTED_Configuration:
        {
            if(LastCursorPos != 0)
            {
                //clear L'ancien Curseur 
                tft_fillRect(40,LastCursorPos,20,28,0x221F);  
            }
            tft_setCursor(40,100);
            tft_writeString(">");
            LastCursorPos = 100;
            break;
        }
    }
}
   
void TFT_Font_List(void)
{
    tft_fillScreen(ILI9341_BLACK);
    tft_fillRect(10,10,300,220,0x221F);
    tft_setTextSize(2);
    tft_setCursor(15,15);
    tft_setTextColor(ILI9341_WHITE);
    tft_writeString("List");
    tft_drawFastHLine(10,31,300,ILI9341_WHITE);
    tft_drawFastHLine(10,32,300,ILI9341_WHITE);
    tft_setTextSize(2);
    tft_setCursor(15,35);
    tft_setTextColor(ILI9341_WHITE);
    tft_writeString(">");
}  

void TFT_Font_config(void)
{
    tft_fillScreen(ILI9341_BLACK);
    tft_fillRect(10,10,300,220,0x221F);
    tft_setTextSize(2);
    tft_setCursor(15,15);
    tft_setTextColor(ILI9341_WHITE);
    tft_writeString("config");
    tft_drawFastHLine(10,31,300,ILI9341_WHITE);
    tft_drawFastHLine(10,32,300,ILI9341_WHITE);
    tft_setTextSize(1);
    tft_setCursor(15,35);
    tft_setTextColor(ILI9341_WHITE);
    tft_writeString(">");
}  

void TFT_aff_all_students (void)
{
    int I;
    tft_setTextSize(1);
    tft_setCursor(25,35);
    tft_setTextColor(ILI9341_WHITE);
    for(I =0; I < I_Nbstudents; I ++)
    {
        tft_writeString(Students_Info[I].StudentName);
        tft_setCursor(25,35+((I+1)*10));
    }
}

void TFT_Update_Config_cursor (int pos)
{
    
}