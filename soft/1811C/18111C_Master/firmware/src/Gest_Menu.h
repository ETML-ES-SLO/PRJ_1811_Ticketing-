/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _GEST_MENU_H    /* Guard against multiple inclusion */
#define _GEST_MENU_H



#ifdef __cplusplus
}
#endif

typedef enum {
    SELECTED_NONE = 0,
    SELECTED_LIST = 1,
    SELECTED_Configuration = 2,        
        
}MENUSELECT;

typedef struct
{
    /* The application's current state */
    bool But_UP;
    bool But_Down;
    bool But_OK;
    bool But_ESC;
    bool But_ACC;
    bool But_DECL;
    bool But_Reset_Tick;
    /* TODO: Define any additional data used by the application. */

} APP_BUTTON;

typedef enum {
    MENU_MenuPrincipal = 0,
    MENU_List = 1,
    MENU_Initialisation, 
    MENU_Config,
    Idle,
}MENU;

APP_BUTTON appButtons;
MENU MenuList;
MENUSELECT MenuSelected;


//int IntegrationTimeTmp = 0;
//bool Integration_Auto = true;


void Gest_Menu (void);
void MenuChange (MENU NewMenu);
void TFT_CablirationInfo(void);
void ClearALLButtons (void);
void Init_Menu(void);
void Menu_loading_init (void);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
