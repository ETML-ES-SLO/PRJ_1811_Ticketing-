

#include "app_Gest_RF.h"
#include "peripheral/spi/plib_spi.h"
#include "Mc32gestI2c24AA02.h"
#include "Mc32_I2cUtilCCS.h"


U_32 UID_32;

U_32 Datas;

bool BitTimer = false;

/* ************************************************************************** */
/* ************************************************************************** */
void  RF_initialize (void)
{
    unsigned char tmp [10] = {0};
    int I,J; 
    unsigned char Tab_config [10] = {0xEA,0x0E,0x44,0x08,0x08,0x00,0x00,0x00,0x00,0x5E};
    
    //Initialisation du module I2C
    I2C_Init24AA02();
    
    //Récupération de l'addresse stockée dans l'EEPROM
    UID_32.val32 = I2C_Read_UID_24AA02_P();
    
    //Décomposition en Bytes
    Tab_config [8] = UID_32.U_32_Bytes.lsb;
    Tab_config [7] = UID_32.U_32_Bytes.byte1;
    Tab_config [6] = UID_32.U_32_Bytes.byte2;
    Tab_config [5] = UID_32.U_32_Bytes.msb;
    
    //nRF904 en mode configuration
    MODE_CONFIG();
    
    
    PLIB_SPI_Enable(SPI_ID_2);
    
    //Temps d'attente de minimum 650us pour le passage en mode configuration
    for(I = 0; I <10000; I ++)
    {
    }
    
    //écriture des registres de configuration
    for(I = 0; I < 10; I ++)
    {   
        //chip select nRF905
        CS_RF_ON

        //Selection Registre de configuration
        PLIB_SPI_BufferWrite(SPI_ID_2,(WC+I));
        do
        {      
        }while (PLIB_SPI_IsBusy(SPI_ID_2));
        PLIB_SPI_BufferRead(SPI_ID_2);


        PLIB_SPI_BufferWrite(SPI_ID_2,Tab_config[I]);
        do
        {      
        }while (PLIB_SPI_IsBusy(SPI_ID_2));
        PLIB_SPI_BufferRead(SPI_ID_2);

        //chip select nRF905
        CS_RF_OFF
                
        for(J = 0; J < 500; J ++)
        {       
        }
    }
              
    Activer_Ecoute_RF();   
    
    //Temps d'attente pour que le nRF passe bien en mode écoute
    for (I = 0 ; I < 3000 ; I ++)
    {       
    } 
     
    //Debug, lecture des registres de configuration
    CS_RF_ON
    PLIB_SPI_BufferWrite(SPI_ID_2,0x10);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2);    
    
    for( I = 0; I < 10; I ++)
    {
        PLIB_SPI_BufferWrite(SPI_ID_2,0x00);
        do
        {      
        }while (PLIB_SPI_IsBusy(SPI_ID_2));


        tmp [I] = PLIB_SPI_BufferRead(SPI_ID_2);
        
    }
    
    CS_RF_OFF
    
}

/* ************************************************************************** */
/* ************************************************************************** */
void Activer_Ecoute_RF (void)
{
    TXR_CE_ON
    TX_EN_OFF        
    PWR_UP_ON
}

/* ************************************************************************** */
/* ************************************************************************** */
void Activer_Envoi_RF (void)
{
    TXR_CE_ON
    TX_EN_ON       
    PWR_UP_ON
}

/* ************************************************************************** */
/* ************************************************************************** */
void Stand_by_RF (void)
{
    TXR_CE_OFF
    TX_EN_OFF       
    PWR_UP_ON
}

/* ************************************************************************** */
/* ************************************************************************** */
void MODE_CONFIG (void)
{
    TXR_CE_OFF
    TX_EN_OFF       
    PWR_UP_ON    
}

/* ************************************************************************** */
/* ************************************************************************** */
void Lecture_Rx (void)
{
    TXR_CE_ON
    TX_EN_OFF       
    PWR_UP_ON             
}

/* ************************************************************************** */
/* ************************************************************************** */
void Ecriture_TX (void)
{
    TXR_CE_OFF
    TX_EN_ON       
    PWR_UP_ON             
}

/* ************************************************************************** */
/* ************************************************************************** */
void PWR_Down(void)
{
    TXR_CE_OFF
    TX_EN_OFF       
    PWR_UP_OFF             
}

/* ************************************************************************** */
/* ************************************************************************** */
void Ecrire_Addresse_Envoi (uint32_t Data)
{
    Datas.val32 = Data;
    int I = 0;
    
    Ecriture_TX ();
 
    for(I = 0; I <100000; I ++)
    {
    }
    
    CS_RF_ON;
    
    //selection du registre adresse TX
    PLIB_SPI_BufferWrite(SPI_ID_2,0x22);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2);
    //écriture de l'adresse source
    PLIB_SPI_BufferWrite(SPI_ID_2,Datas.U_32_Bytes.msb);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));    
    PLIB_SPI_BufferRead(SPI_ID_2);
    PLIB_SPI_BufferWrite(SPI_ID_2,Datas.U_32_Bytes.byte2);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2);
    PLIB_SPI_BufferWrite(SPI_ID_2,Datas.U_32_Bytes.byte1);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2);
    PLIB_SPI_BufferWrite(SPI_ID_2,Datas.U_32_Bytes.lsb);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2);
    CS_RF_OFF;   
    
                   
    Activer_Ecoute_RF ();
}
/* ************************************************************************** */
/* ************************************************************************** */
void Ecrire_Buffer_Envoi (uint32_t Data)
{
    int I = 0;
    Datas.val32 = Data;
    int tmp [8];
    
    
    Ecriture_TX ();
     
    for(I = 0; I <100000; I ++)
    {
    }
     
    CS_RF_ON;
    
    //selection du registre TX
    PLIB_SPI_BufferWrite(SPI_ID_2,0x20);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2);
    //écriture de l'adresse source
    PLIB_SPI_BufferWrite(SPI_ID_2,UID_32.U_32_Bytes.lsb);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));    
    PLIB_SPI_BufferRead(SPI_ID_2);
    PLIB_SPI_BufferWrite(SPI_ID_2,UID_32.U_32_Bytes.byte1);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));   
    PLIB_SPI_BufferRead(SPI_ID_2);
    PLIB_SPI_BufferWrite(SPI_ID_2,UID_32.U_32_Bytes.byte2);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2);
    PLIB_SPI_BufferWrite(SPI_ID_2,UID_32.U_32_Bytes.msb);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2);   
    
    //écriture des datas
    PLIB_SPI_BufferWrite(SPI_ID_2,Datas.U_32_Bytes.lsb);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2);
    PLIB_SPI_BufferWrite(SPI_ID_2,Datas.U_32_Bytes.byte1);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2);
    PLIB_SPI_BufferWrite(SPI_ID_2,Datas.U_32_Bytes.byte2);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2);
    PLIB_SPI_BufferWrite(SPI_ID_2,Datas.U_32_Bytes.msb);
    do
    {      
    }while (PLIB_SPI_IsBusy(SPI_ID_2));
    PLIB_SPI_BufferRead(SPI_ID_2); 
    CS_RF_OFF;
    
    Activer_Envoi_RF ();  
    /*
    while(!Get_DR_Value())
    {        
    }*/
    
    for (I = 0 ; I < 5 ; I ++)
    {       
    } 
    
    Activer_Ecoute_RF ();
    
    for (I = 0 ; I < 500 ; I ++)
    {       
    } 
}

/* ************************************************************************** */
/* ************************************************************************** */
bool Get_AM_Value (void)
{
    bool val;
    val = AM
    return val;
}

/* ************************************************************************** */
/* ************************************************************************** */
bool Get_CD_Value (void)
{
    bool val;
    val = CD
    return val;
}

/* ************************************************************************** */
/* ************************************************************************** */
bool Get_DR_Value (void)
{
    bool val;
    val = DR
    return val;
}

/* ************************************************************************** */
/* ************************************************************************** */

uint32_t Get_datas (uint32_t *TargetAdd)
{
    U_32 Datas;
    U_32 Add_Target;
    uint32_t payload [8] = {0};
    
    int I = 0;
    
    Lecture_Rx();
    
    for (I = 0 ; I < 500 ; I ++)
    {       
    } 
    
    CS_RF_ON;
    
    //acces registre rx
    PLIB_SPI_BufferWrite(SPI_ID_2,0x24);
    do
    {           
    }while (PLIB_SPI_IsBusy(SPI_ID_2));    
    PLIB_SPI_BufferRead(SPI_ID_2);
    I = 0;
    
    while (Get_DR_Value() == 1)
    { 
        //get de l'adress de la target
        PLIB_SPI_BufferWrite(SPI_ID_2,0x00);
        do
        {           
        }while (PLIB_SPI_IsBusy(SPI_ID_2));
    
        payload [I] = PLIB_SPI_BufferRead(SPI_ID_2);
        
        I ++;       
    }
     
    CS_RF_OFF
    
    //récupération de l'adresse en bytes
    Add_Target.U_32_Bytes.lsb = payload [0];
    Add_Target.U_32_Bytes.byte1 = payload [1];
    Add_Target.U_32_Bytes.byte2 = payload [2];
    Add_Target.U_32_Bytes.msb = payload [3];
    
    //récupération des datas en bytes
    Datas.U_32_Bytes.lsb = payload [4];
    Datas.U_32_Bytes.byte1 = payload [5];
    Datas.U_32_Bytes.byte2 = payload [6];
    Datas.U_32_Bytes.msb = payload [7];        
            
    Activer_Ecoute_RF();
    
    *TargetAdd = Add_Target.val32;
    return Datas.val32;
}