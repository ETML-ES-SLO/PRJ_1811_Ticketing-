//18111C_Master
//--------------------------------------------------------
//* ************************************************************************** */
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

#ifndef _GEST_TFT_H    /* Guard against multiple inclusion */
#define _GEST_TFT_H



#ifdef __cplusplus
}
#endif

void TFT_Init (void);
void TFT_Cursor_MenuPrincipale ();
void TFT_Font_List();
void TFT_Menu_Principal (void);
void TFT_Font_debug (void);
void TFT_SD_PLUG_OK (void);
void TFT_SD_Mount_OK (void);
void TFT_List_Of_Students_OK (void);
void TFT_Students_Found (char T_Nb_Students [3]);
void TFT_Cheking_Link (void);
void TFT_Students_Link(int Nb_Link);
void TFT_Init_OK(void);
void TFT_aff_all_students (void);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
