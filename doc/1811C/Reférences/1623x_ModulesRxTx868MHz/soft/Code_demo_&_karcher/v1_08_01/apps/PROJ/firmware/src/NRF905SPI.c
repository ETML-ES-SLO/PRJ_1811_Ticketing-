/*--------------------------------------------------------*/
// NRF905SPI.c
/*--------------------------------------------------------*/
//	Description :	Gestion par SPI du NRF905
//
//	Auteur 		: 	Y. Simonet
//  
/*--------------------------------------------------------*/



#include "app.h"   // pour system_config et autre
#include "NRF905SPI.h"
#include "Mc32SpiUtil.h"
#include "peripheral\SPI\plib_spi.h"

// SPI_ID_2 correspond au SPI 2 !
#define Spi2 (SPI_ID_2)
#define ERROR_ADD -1
//structur pour la manipulation 32 bits
typedef union 
{
    uint32_t val32;
    
    struct
    {
        uint8_t lsb;
        uint8_t byte1;
        uint8_t byte2;
        uint8_t msb;
    } 
    shl;
} 
U_manip32;

U_manip32 add_32;


// Initialisation de la communication SPI pour le NRF905
// ---------------------------------------------------

void SPI_Configure(void)
{
   PLIB_SPI_Disable(Spi2);
   PLIB_SPI_BufferClear(Spi2);
   PLIB_SPI_OutputDataPhaseSelect(Spi2,1);
   PLIB_SPI_Enable(Spi2);
}

//configuration du NRF905
void SPI_InitNRF905(void)  
{

   SPI_Configure();
    
   // action de configuration
   CS = 0;
   //aller dans le registre de configuration
   spi_write2(0x00);
   //écrire config

   //byte 0 
   spi_write2(0x75); //ch_NO[7:0] = '0111 0101' soit 868.2MHz

   //byte 1 = '0000 1110'
   spi_write2(0x2E);//AUTO_RETRAN ='0',RX_RED_PWR = '0',
                    //Output power ='11',PLL ='1',ch_NO[8] = '0'      
   
   //byte 2 = 0001 0001'
   spi_write2(0x11);// RX_AFW ='1', TX_AFW ='1' soit un byte d'addresse 
   
   //byte 3 et 4 payload width Rx et Tx = '0000 0101'
   spi_write2(0x05); //32 bits d' addresse + 8bits de data soit 5bytes
   spi_write2(0x05); //32 bits d' addresse + 8bits de data soit 5bytes
   
   //byte 5 à 8 Rx add
   spi_write2(0xE7); 
   spi_write2(0xE7); 
   spi_write2(0xE7); 
   spi_write2(0xE7);
   
   //byte 9 = '1101 1111'
   //CRC_MODE = '1',CRC check enable ='1',
   //Crystal 16Mhz ='011' Output clock enable = '1',Output clock frequency '10' 
   spi_write2(0xDE);
    CS = 1;
} // SPI_Init



// Lecture des dnnées recus par le NRF905
// Version sans reconfiguration
uint8_t SPI_Read_data_RX_NRF905(int32_t Padd)
{
    uint8_t data_spi;

    CS = 0;
   //aller dans le registre RX
   spi_write2(0x24);
 
   
   //lire l' addresse
   add_32.shl.msb   =spi_read2(0);
   add_32.shl.byte2 =spi_read2(0);
   add_32.shl.byte1 =spi_read2(0);
   add_32.shl.lsb   =spi_read2(0);
   //lire la data
   data_spi         =spi_read2(0);

   //tester si l' addresse coréspond a l'UID
   if((add_32.val32!=Padd))
   {
       //tester si on est en braudcaste
       if(add_32.val32 != 0)
       {
         data_spi = ERROR_ADD;
       }
   }
   CS = 1;
   return data_spi;  
} 

// SPI_Read fonction utilisé pour relire la configuration
//utilisé seulement pour du débug
uint8_t SPI_Read_config_RX_NRF905(int32_t Padd)
{
    uint8_t data_spi;
    uint8_t data_spi2;
     uint8_t data_spi3;
    uint8_t data_spi4;
     uint8_t data_spi5;

    
    CS = 0;
   //aller dans le registre RX
   spi_write2(0x21);
   //relire les datas
   data_spi   =spi_read2(0);
   data_spi2  =spi_read2(0);
   data_spi3  =spi_read2(0);
   data_spi4  =spi_read2(0);
   data_spi5  =spi_read2(0);

   
   CS = 1;
   return data_spi;  
} 

// écriture du registre du registre TX
// Version avec reconfiguration
void SPI_Write_data_TX_NRF905(uint32_t Padd,uint8_t Ptx)
{
   
    add_32.val32 = Padd;
     
     
     CS = 0;
   
   //aller dans le registre RX
   spi_write2(0x20);
 
   //écrir l' addresse
   spi_write2(add_32.shl.msb);
   spi_write2(add_32.shl.byte2);
   spi_write2(add_32.shl.byte1);
   spi_write2(add_32.shl.lsb);
   
   //écrire la data
   spi_write2(Ptx); 
   CS = 1;
} // SPI_Cfg
   



