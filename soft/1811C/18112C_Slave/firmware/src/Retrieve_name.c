/******************************************************************************/
// Project		: 2126 Affichage Matriciel Nom Etudiant
// Author 		: Ricardo Crespo
// Date 		: 12.06.2022
// Descrition   : Fichier du code principal
//
//  Modification: Mario Dos Santos
//  Date        : 31.08.2022
//  Description : Modifier le fichier pour n'avoir que la partie lecture de nom.
//                pour pouvoir l'utiliser dans le projet 1811C Ticketing 
//                (Supprimer la partie Matrix, I2C et animation)
//
/******************************************************************************/
#include "Retrieve_name.h"                       
#include "app.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************


uint8_t countCar = 0;           // Compteur du nombre de characters d'un nom
char buffReadName[20] = {'M','a','r','i','o',' ','D'};// Buffer de reception de l'UART

bool Name_Receive = false;   //Flag Nom recu

/******************************************************************************
  Function:
    void Retrive_Name ( void )

  Remarks:
    See prototype in Retrive_Name.h.
 */
void Retrive_Name ( void )
{
    
    static uint8_t numberChar = 0;       // Compteur de la taille de la cl� d'envoi

    char key[] = {'C', '\0'};            // Cl� de confirmaiton pour le software
    char keyCom = 'x';                   // Cl� de communication de la part du software
    char keyEndName[] = {'X', 'D', 'R'}; // Cl� de fin de nom complet
    char character;                      // Buffeur du character actuellement lu
    char reciveCharacter = ' ';          // Buffeur de r�ception des caracteres de l'UART
    
    static bool startReadName = false;   // Permet de commencer � lire le nom
    

  

    
    // Tant que l'on re�ois des datas dans le RX buffeur 
    while(PLIB_USART_ReceiverDataIsAvailable(USART_ID_2))
    {
        // R�cup�ration du charactere dpuis le RX buffeur
       
        character = PLIB_USART_ReceiverByteReceive(USART_ID_2);
        
        

        // Si on a pas re�u la cl� de communication et qu'on a pas encore lu le nom 
        if((character != keyCom) && (!startReadName))
        {
            // Reset du compteur du nombre de characteres du nom
            countCar = 0;
            // Peut d�marrer la lecture du nom complete
            startReadName = true;
        }
        // Si non on stock la cl� de communication avec le software
        else
        {
            // Sauvegarde de la cl� de communicaiton avec le software
            reciveCharacter = character;
        }

        // Si on peut faire la lecture du nom complete
        if(startReadName)
        {
            // Stockage du charactere actuel dans le buffer de stockage du nom
            buffReadName[countCar] = character;
            // Incr�mentation du nombre de characteres du nom
            countCar++;
        }
    }

    // Si on a re�u la cl� du Software ET que l'on lit pas le nom
    if((reciveCharacter == keyCom) && !startReadName)
    {
        // Tant qu'on a pas fini la chaine ET que l'on a pas plus de 8 caracteres
        while ((key[numberChar] != 0) && (numberChar < SIZE_KEY)) 
        {
            // Attente que le TX buffeur soit disponible
            while(PLIB_USART_TransmitterBufferIsFull(USART_ID_2));
            // Envoi de la cl� de confirmation au software
            PLIB_USART_TransmitterByteSend(USART_ID_2, key[numberChar]);
            // Incr�mentation du compteur de nombre de characteres
            numberChar++;
        }
        // Reset du buffer de r�ception des characteres
        reciveCharacter = ' ';
        // Reset du compteur de nombre de characteres
        numberChar = 0;
    } 

    // Si on a re�u un nom d'�l�ve 
    if((buffReadName[0] != 0x20)
    && (buffReadName[0] != NULL)
    && (buffReadName[0] != keyCom)
    && (buffReadName[countCar - 3] == keyEndName[0])
    && (buffReadName[countCar - 2] == keyEndName[1])
    && (buffReadName[countCar - 1] == keyEndName[2]))
    {
        // Enl�ve les position de la cl� de r�ception du nom 
        countCar -= (END_NAME_KEY_SIZE - 1);
        // Ins�re un '.' apr�s la lettre majuscule du nom de l'�l�ve
        Name_Receive = true;
    }

}

/*******************************************************************************
 End of File
 */
