/*******************************************************************************
  Board Support Package Header File.

  Company:      
    Microchip Technology Inc.

  File Name:    
    bsp_config.h

  Autor / modifications :
    C. HUBER  adaptation au kit pic32mx ES
 *

  Summary:      
    Board Support Package Header file for Starter Kit PIC32MX795F512L ETML ES.

  Description:
    This file contains constants, macros, type defintions and function
    declarations required by the PIC32MX Starter Kit ES.
 *
 *  Ajout CHR 09.12.2014
        - void BSP_EnableHbrige(void);
 *      - définitions _R et _W pour Hbridge
 *  Correction 30.01.2015 CHR
 *      - STBY_HBRIGE est en B8 et non en C13 !!!
 *  Correction 17.02.2015 CHR
 *      - traitement correct du PEC12
 *  Correction  29.03.2015
 *     - adaptation définitions des BSP_SWITCH
 *  EVOLUTION du PRINCIPE
 *  CHR 16.09.2015
 *     - exploitation des automatisme obtenu du pin configurator et
 *       du fichier XML
 *
*******************************************************************************/


#ifndef _BSP_CONFIG_H
#define _BSP_CONFIG_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "peripheral/ports/plib_ports.h"
#include "peripheral/tmr/plib_tmr.h"


// *****************************************************************************
// *****************************************************************************
// Section: Constants and Type Definitions.
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Oscillator Frequency

  Summary:
    Defines frequency value of crystal/oscillator used on the board

  Description:
    Defines frequency value of crystal/oscillator used on the board
*/

#define BSP_OSC_FREQUENCY 8000000      // 8 MHz



// CHR 08.09.2014
// Ajout définition direct des E/S du Kit 32MX795F512L
// ===================================================

/*--------------------------------------------------------*/
// Analogique
/*--------------------------------------------------------*/
// Uniquement pour Info
#define Analog0     PORTBbits.RB0
#define Analog1		PORTBbits.RB1

// Definitions dans le fichier XML (bsp.xml)
// <!--  Analog IN -->
// <function name="POT0" pin="RB0" mode="analog" />
// <function name="POT1" pin="RB1" mode="analog" />

/*--------------------------------------------------------*/
// Touches
/*--------------------------------------------------------*/
// Definitions directes
#define S_OK         PORTGbits.RG12
#define S_ESC_MENU   PORTGbits.RG13
#define S_PLUS       PORTGbits.RG14
#define S_MINUS      PORTGbits.RG15
// Definitions pour fonctions PLIB_PORTS
#define S_OK_PORT          PORT_CHANNEL_G
#define S_OK_BIT           PORTS_BIT_POS_12
#define S_ESC_MENU_PORT    PORT_CHANNEL_G
#define S_ESC_MENU_BIT     PORTS_BIT_POS_13
#define S_PLUS_PORT        PORT_CHANNEL_G
#define S_PLUS_BIT         PORTS_BIT_POS_14
#define S_MINUS_PORT       PORT_CHANNEL_G
#define S_MINUS_BIT        PORTS_BIT_POS_15

// Definitions dans le fichier XML (bsp.xml)
// <function name="S_OK" pin="RG12" mode="digital" pullup="true"/>
// <function name="S_ESC_MENU" pin="RG13" mode="digital" pullup="true"/>
// <function name="S_PLUS" pin="RG14" mode="digital" pullup="true"/>
// <function name="S_MINUS" pin="RG15" mode="digital" pullup="true"/>



/*--------------------------------------------------------*/
// PEC12
/*--------------------------------------------------------*/
// Sur schema B   cablage séparé
// Mais en conflit avec lignes Ethernet
#define PEC12_A      PORTEbits.RE8
#define PEC12_B      PORTEbits.RE9
#define PEC12_PB     PORTDbits.RD7

// Definitions pour fonction PLIB_PORTS
#define PEC12_A_PORT          PORT_CHANNEL_E
#define PEC12_A_BIT           PORTS_BIT_POS_8
#define PEC12_B_PORT          PORT_CHANNEL_E
#define PEC12_B_BIT           PORTS_BIT_POS_9
#define PEC12_PB_PORT         PORT_CHANNEL_D
#define PEC12_PB_BIT          PORTS_BIT_POS_7

// Definitions dans le fichier XML (bsp.xml)
// <!--  PEC12 -->
// <function name="PEC12_A" pin="RE8" mode="digital" pullup="true"/>
// <function name="PEC12_B" pin="RE9" mode="digital" pullup="true"/>
// <function name="PEC12_PB" pin="RD7" mode="digital" pullup="true"/>

/*--------------------------------------------------------*/
// Clavier matriciel
/*--------------------------------------------------------*/
	/*----------------------------------------------------*/
	// Colonnes
	/*----------------------------------------------------*/
	#define COLONNE1     PORTBbits.RB2
	#define COLONNE2     PORTBbits.RB3
	#define COLONNE3     PORTBbits.RB4
	#define COLONNE4     PORTBbits.RB5

	#define COLONNE1_T   DDRBbits.RB2
	#define COLONNE2_T   DDRBbits.RB3
	#define COLONNE3_T   DDRBbits.RB4
	#define COLONNE4_T   DDRBbits.RB5

// Definitions pour fonctions PLIB_PORTS
#define COLONNE1_PORT    PORT_CHANNEL_B
#define COLONNE1_BIT     PORTS_BIT_POS_2
#define COLONNE2_PORT    PORT_CHANNEL_B
#define COLONNE2_BIT     PORTS_BIT_POS_3
#define COLONNE3_PORT    PORT_CHANNEL_B
#define COLONNE3_BIT     PORTS_BIT_POS_4
#define COLONNE4_PORT    PORT_CHANNEL_B
#define COLONNE4_BIT     PORTS_BIT_POS_5

// Definitions dans le fichier XML (bsp.xml)
// <!--  Colonnes -->
// <function name="COLONNE1" pin="RB2" mode="digital" pullup="true"/>
// <function name="COLONNE2" pin="RB3" mode="digital" pullup="true"/>
// <function name="COLONNE3" pin="RB4" mode="digital" pullup="true"/>
// <function name="COLONNE4" pin="RB5" mode="digital" pullup="true"/>

	/*----------------------------------------------------*/
	// Lignes
	/*----------------------------------------------------*/
	#define LIGNE1       PORTGbits.RG6
	#define LIGNE2       PORTGbits.RG7
	#define LIGNE3       PORTBbits.RB14
	#define LIGNE4       PORTBbits.RB15

	#define LIGNE1_T     DDRGbits.RG6
	#define LIGNE2_T     DDRGbits.RG7
	#define LIGNE3_T     DDRBbits.RB14
	#define LIGNE4_T     DDRBbits.RB15

// Definitions pour fonctions PLIB_PORTS
#define LIGNE1_PORT    PORT_CHANNEL_G
#define LIGNE1_BIT     PORTS_BIT_POS_6
#define LIGNE2_PORT    PORT_CHANNEL_G
#define LIGNE2_BIT     PORTS_BIT_POS_7
#define LIGNE3_PORT    PORT_CHANNEL_B
#define LIGNE3_BIT     PORTS_BIT_POS_14
#define LIGNE4_PORT    PORT_CHANNEL_B
#define LIGNE4_BIT     PORTS_BIT_POS_15

// Definitions dans le fichier XML (bsp.xml)
// <!--  Lignes -->
// <function name="LIGNE1" pin="RG6" mode="digital" pullup="true"/>
// <function name="LIGNE2" pin="RG7" mode="digital" pullup="true"/>
// <function name="LIGNE3" pin="RB14" mode="digital" pullup="true"/>
// <function name="LIGNE4" pin="RB15" mode="digital" pullup="true"/>

/*--------------------------------------------------------*/
// LEDs
/*--------------------------------------------------------*/

// Attention 11020_B modification du câblage
// -----------------------------------------
// Led0   RA0    D6
// Led1   RA1    D10
// Led2   RA4    D7
// Led3   RA5    D11
// Led4   RA6    D8
// Led5   RA7    D12
// Led6   RA15   D9
// Led7   RB10   D13   !!! port B

// On écrit dans le latch pour éviter les problèmes de R/W
#define LED0_W       LATAbits.LATA0  //Led0
#define LED1_W       LATAbits.LATA1  //Led1
#define LED2_W       LATAbits.LATA4  //Led2
#define LED3_W       LATAbits.LATA5  //Led3
#define LED4_W       LATAbits.LATA6  //Led4
#define LED5_W       LATAbits.LATA7  //Led5
#define LED6_W       LATAbits.LATA15 //Led6
#define LED7_W       LATBbits.LATB10 //Led7
// On lit directement sur le port, sinon on obtient la valeur
// précédemment écrite dans le latch!!
#define LED0_R       PORTAbits.RA0 //Led0
#define LED1_R       PORTAbits.RA1 //Led1
#define LED2_R       PORTAbits.RA4 //Led2
#define LED3_R       PORTAbits.RA5 //Led3
#define LED4_R       PORTAbits.RA6 //Led4
#define LED5_R       PORTAbits.RA7 //Led5
#define LED6_R       PORTAbits.RA15 //Led6
#define LED7_R       PORTBbits.RB10 //Led7

#define LED0_T     TRISAbits.TRISA0
#define LED1_T     TRISAbits.TRISA1
#define LED2_T     TRISAbits.TRISA4
#define LED3_T     TRISAbits.TRISA5
#define LED4_T     TRISAbits.TRISA6
#define LED5_T     TRISAbits.TRISA7
#define LED6_T     TRISAbits.TRISA15
#define LED7_T     TRISBbits.TRISB10

// Definitions pour fonction PLIB_PORTS
#define LED0_PORT    PORT_CHANNEL_A
#define LED0_BIT     PORTS_BIT_POS_0

#define LED1_PORT    PORT_CHANNEL_A
#define LED1_BIT     PORTS_BIT_POS_1

#define LED2_PORT    PORT_CHANNEL_A
#define LED2_BIT     PORTS_BIT_POS_4
// correction oubli LED3 20.11.1015 CHR
#define LED3_PORT    PORT_CHANNEL_A
#define LED3_BIT     PORTS_BIT_POS_5

#define LED4_PORT    PORT_CHANNEL_A
#define LED4_BIT     PORTS_BIT_POS_6

#define LED5_PORT    PORT_CHANNEL_A
#define LED5_BIT     PORTS_BIT_POS_7

#define LED6_PORT    PORT_CHANNEL_A
#define LED6_BIT     PORTS_BIT_POS_15

#define LED7_PORT    PORT_CHANNEL_B
#define LED7_BIT     PORTS_BIT_POS_10

// Definitions dans le fichier XML (bsp.xml)
// Avec essais effet latch low ou High
// <!--  LEDS -->
// <function name="LED_0" pin="RA0" mode="digital" direction="out" latch="low"/>
// <function name="LED_1" pin="RA1" mode="digital" direction="out" latch="low"/>
// <function name="LED_2" pin="RA4" mode="digital" direction="out" latch="low"/>
// <function name="LED_3" pin="RA5" mode="digital" direction="out" latch="low"/>
// <function name="LED_4" pin="RA6" mode="digital" direction="out" latch="high"/>
// <function name="LED_5" pin="RA7" mode="digital" direction="out" latch="high"/>
// <function name="LED_6" pin="RA15" mode="digital" direction="out" latch="high"/>
// <function name="LED_7" pin="RB10" mode="digital" direction="out" latch="high"/>

/*--------------------------------------------------------*/
// I2C
/*--------------------------------------------------------*/
// Uniquement pour Info
#define I2C_SCL      PORTAbits.RA2
#define I2C_SDA      PORTAbits.RA3

/*--------------------------------------------------------*/
// SPI
/*--------------------------------------------------------*/
// Uniquement pour Info
#define SPI_SCL      PORTDbits.RD10
#define SPI_SDI      PORTCbits.RC4
#define SPI_SDO      PORTDbits.RD0

/*----------------------------------------------------*/
// Chip Select SPI
/*----------------------------------------------------*/
#define CS_LM70      PORTDbits.RD3
#define CS_DAC       PORTDbits.RD4
#define CS_SD        PORTDbits.RD5

// Definitions pour fonctions PLIB_PORTS
#define CS_LM70_PORT   PORT_CHANNEL_D
#define CS_LM70_BIT    PORTS_BIT_POS_3
#define CS_DAC_PORT    PORT_CHANNEL_D
#define CS_DAC_BIT     PORTS_BIT_POS_4
#define CS_SD_PORT     PORT_CHANNEL_D
#define CS_SD_BIT      PORTS_BIT_POS_5

// Definitions dans le fichier XML (bsp.xml)
// <!--  _CS SPI -->
//	<function name="CS_LM70" pin="RD3" mode="digital" direction="out" latch="high" pullup="true"/>
//  <function name="CS_DAC"  pin="RD4" mode="digital" direction="out" latch="high" pullup="true"/>
//  <function name="CS_SD"   pin="RD5" mode="digital" direction="out" latch="high" pullup="true"/>

/*--------------------------------------------------------*/
// Ethernet
/*--------------------------------------------------------*/

// Uniquement pour info
#define ETH_TX_EN	PORTDbits.RD6
#define ETH_TX_CLK	PORTDbits.RD7
#define ETH_MDIO	PORTDbits.RD8
#define ETH_MDC		PORTDbits.RD11
#define ETH_RD_ER	PORTBbits.RB11
#define ETH_D0		PORTBbits.RB12
#define ETH_D1		PORTBbits.RB13
// Attention
#define ETH_POWERDOWN_INT   PORTAbits.RA14
#define ETH_AN_EN	PORTEbits.RE8
#define ETH_AN0		PORTEbits.RE9
#define ETH_TX_D1	PORTFbits.RF0
#define ETH_TX_D0	PORTFbits.RF1
#define ETH_CRS_DV	PORTGbits.RG8
#define ETH_RST		PORTGbits.RG9

/*----------------------------------------------------*/
// SD Card
/*----------------------------------------------------*/
#define SD_DETECT	PORTCbits.RC3

// Definitions pour fonctions PLIB_PORTS
#define SD_DETECT_PORT   PORT_CHANNEL_C
#define SD_DETECT_BIT    PORTS_BIT_POS_3

// Definitions dans le fichier XML (bsp.xml)
// <!--  SD_DETECT -->
// <function name="SD_DETECT" pin="RC3" mode="digital" pullup="true"/>

/*----------------------------------------------------*/
// DAC
/*----------------------------------------------------*/
#define DAC_CLEAR	PORTDbits.RD9

// Definitions pour fonctions PLIB_PORTS
#define DAC_CLEAR_PORT   PORT_CHANNEL_D
#define DAC_CLEAR_BIT    PORTS_BIT_POS_9

// Definitions dans le fichier XML (bsp.xml)
// <!--  DAC_CLEAR -->
// <function name="DAC_CLEAR" pin="RD9" mode="digital" direction="out" latch="high" pullup="true"/>

/*--------------------------------------------------------*/
// USB
/*--------------------------------------------------------*/
#define USB_DETECT	PORTFbits.RF3
// Definitions pour fonctions PLIB_PORTS
#define USB_DETECT_PORT   PORT_CHANNEL_F
#define USB_DETECT_BIT    PORTS_BIT_POS_3

// Definitions dans le fichier XML (bsp.xml)
// <!--  USB_DETECT -->
// <function name="USB_DETECT" pin="RF3" mode="digital" pullup="true"/>
        
// Uniquement pour info
#define USB_PLUS	PORTGbits.RG2
#define USB_MINUS	PORTGbits.RG3

/*--------------------------------------------------------*/
// RS232
/*--------------------------------------------------------*/
// Uniquement pour info
#define RS232_TX     PORTFbits.RF8
#define RS232_RX     PORTFbits.RF2


#define RS232_RTS    LATDbits.LATD15    // output donc latch
#define RS232_CTS    PORTDbits.RD14
// Definitions pour fonctions PLIB_PORTS
#define RS232_RTS_PORT   PORT_CHANNEL_D
#define RS232_RTS_BIT    PORTS_BIT_POS_15
#define RS232_CTS_PORT   PORT_CHANNEL_D
#define RS232_CTS_BIT    PORTS_BIT_POS_14

// Definitions dans le fichier XML (bsp.xml)
// <!--  RS232 -->
//	<function name="RS232_RTS" pin="RD15" mode="digital" direction="out" latch="high" pullup="true"/>
//	<function name="RS232_CTS" pin="RD14" mode="digital" pullup="true"/>

/*--------------------------------------------------------*/
// LCD
/*--------------------------------------------------------*/
//On écrit dans le latch pour éviter les problèmes de R/W
#define LCD_RS_W       LATEbits.LATE0
#define LCD_RW_W       LATEbits.LATE1
#define LCD_E_W        LATEbits.LATE2
#define LCD_BL_W       LATEbits.LATE3
#define LCD_DB4_W      LATEbits.LATE4
#define LCD_DB5_W      LATEbits.LATE5
#define LCD_DB6_W      LATEbits.LATE6
#define LCD_DB7_W      LATEbits.LATE7
//On lit directement sur le port, sinon on obtient la valeur
//précédemment écrite dans le latch!!
#define LCD_RS_R       PORTEbits.RE0
#define LCD_RW_R       PORTEbits.RE1
#define LCD_E_R        PORTEbits.RE2
#define LCD_BL_R       PORTEbits.RE3
#define LCD_DB4_R      PORTEbits.RE4
#define LCD_DB5_R      PORTEbits.RE5
#define LCD_DB6_R      PORTEbits.RE6
#define LCD_DB7_R      PORTEbits.RE7

#define LCD_RS_T     TRISEbits.TRISE0
#define LCD_RW_T     TRISEbits.TRISE1
#define LCD_E_T      TRISEbits.TRISE2
#define LCD_BL_T     TRISEbits.TRISE3
#define LCD_DB4_T    TRISEbits.TRISE4
#define LCD_DB5_T    TRISEbits.TRISE5
#define LCD_DB6_T    TRISEbits.TRISE6
#define LCD_DB7_T    TRISEbits.TRISE7



// Definitions pour fonctions PLIB_PORTS
#define LCD_RS_PORT   PORT_CHANNEL_E
#define LCD_RS_BIT    PORTS_BIT_POS_0
#define LCD_RW_PORT   PORT_CHANNEL_E
#define LCD_RW_BIT    PORTS_BIT_POS_1
#define LCD_E_PORT    PORT_CHANNEL_E
#define LCD_E_BIT     PORTS_BIT_POS_2
#define LCD_BL_PORT   PORT_CHANNEL_E
#define LCD_BL_BIT    PORTS_BIT_POS_3
#define LCD_DB4_PORT   PORT_CHANNEL_E
#define LCD_DB4_BIT    PORTS_BIT_POS_4
#define LCD_DB5_PORT   PORT_CHANNEL_E
#define LCD_DB5_BIT    PORTS_BIT_POS_5
#define LCD_DB6_PORT   PORT_CHANNEL_E
#define LCD_DB6_BIT    PORTS_BIT_POS_6
#define LCD_DB7_PORT   PORT_CHANNEL_E
#define LCD_DB7_BIT    PORTS_BIT_POS_7

// Definitions dans le fichier XML (bsp.xml)
// <function name="LCD_RS" pin="RE0" mode="digital" direction="out"/>
// <function name="LCD_RW" pin="RE1" mode="digital" direction="out"/>
// <function name="LCD_E" pin="RE2" mode="digital" direction="out"/>
// <function name="LCD_BL" pin="RE3" mode="digital" direction="out"/ latch="low">
// <function name="LCD_DB4" pin="RE4" mode="digital" direction="out" latch="high"/>
// <function name="LCD_DB5" pin="RE5" mode="digital" direction="out" latch="high"/>
// <function name="LCD_DB6" pin="RE6" mode="digital" direction="out" latch="high"/>
// <function name="LCD_DB7" pin="RE7" mode="digital" direction="out" latch="high"/>

/*--------------------------------------------------------*/
// Ponts en H
/*--------------------------------------------------------*/
// attention sur schéma STBY_HBRIDGE est en B8
// Correction du 30.10.2015 CHR
#define STBY_HBRIDGE_R	PORTBbits.RB8   // corrigé
#define AIN1_HBRIDGE_R	PORTDbits.RD12
#define AIN2_HBRIDGE_R	PORTDbits.RD13
#define PWMA_HBRIDGE_R	PORTDbits.RD1
#define BIN1_HBRIDGE_R	PORTCbits.RC1
#define BIN2_HBRIDGE_R	PORTCbits.RC2
#define PWMB_HBRIDGE_R	PORTDbits.RD2

#define STBY_HBRIDGE_W	LATBbits.LATB8   // corrigé
#define AIN1_HBRIDGE_W	LATDbits.LATD12
#define AIN2_HBRIDGE_W	LATDbits.LATD13
#define PWMA_HBRIDGE_W	LATDbits.LATD1
#define BIN1_HBRIDGE_W	LATCbits.LATC1
#define BIN2_HBRIDGE_W	LATCbits.LATC2
#define PWMB_HBRIDGE_W	LATDbits.LATD2

// Definitions pour fonctions PLIB_PORTS
#define STBY_HBRIDGE_PORT   PORT_CHANNEL_B
#define STBY_HBRIDGE_BIT    PORTS_BIT_POS_8
#define AIN1_HBRIDGE_PORT   PORT_CHANNEL_D
#define AIN1_HBRIDGE_BIT    PORTS_BIT_POS_12
#define AIN2_HBRIDGE_PORT   PORT_CHANNEL_D
#define AIN2_HBRIDGE_BIT    PORTS_BIT_POS_13
#define BIN1_HBRIDGE_PORT   PORT_CHANNEL_C
#define BIN1_HBRIDGE_BIT    PORTS_BIT_POS_1
#define BIN2_HBRIDGE_PORT   PORT_CHANNEL_C
#define BIN2_HBRIDGE_BIT    PORTS_BIT_POS_2

// Definitions dans le fichier XML (bsp.xml)
// Remarque tout en sortie et niveau bas (standby et stop) & ne pas définir pour les OC (PWM)
// <!--  H BRIDGE -->
//	<function name="STBY_HBRIDGE" pin="RB8"  mode="digital" direction="out" latch="low"/>
//	<function name="AIN1_HBRIDGE" pin="RD12" mode="digital" direction="out" latch="low"/>
//	<function name="AIN2_HBRIDGE" pin="RD13" mode="digital" direction="out" latch="low"/>
//	<function name="BIN1_HBRIDGE" pin="RC1"  mode="digital" direction="out" latch="low"/>
//	<function name="BIN2_HBRIDGE" pin="RC2"  mode="digital" direction="out" latch="low"/>


/*--------------------------------------------------------*/
// XBee
/*--------------------------------------------------------*/
#define XBEE_TX         PORTFbits.RF5
#define XBEE_RX         PORTFbits.RF4

#define XBEE_RTS        PORTFbits.RF13
#define XBEE_CTS        PORTFbits.RF12
#define XBEE_ON_SLEEP	PORTGbits.RG0
#define XBEE_RESET      PORTGbits.RG1

// Definitions pour fonctions PLIB_PORTS
#define  XBEE_RTS_PORT   PORT_CHANNEL_F
#define  XBEE_RTS_BIT    PORTS_BIT_POS_13
#define  XBEE_CTS_PORT   PORT_CHANNEL_F
#define  XBEE_CTS_BIT    PORTS_BIT_POS_12
#define  XBEE_ON_SLEEP_PORT   PORT_CHANNEL_G
#define  XBEE_ON_SLEEP_BIT    PORTS_BIT_POS_0
#define  XBEE_RESET_PORT   PORT_CHANNEL_G
#define  XBEE_RESET_BIT    PORTS_BIT_POS_1

#define Xbee_DG1_T    TRISGbits.TRISG1

// Definitions dans le fichier XML (bsp.xml)
// <!--  XBEE -->
//	<function name="XBEE_RTS"  pin="RF13" mode="digital" direction="out" latch="high" />
//	<function name="RS232_CTS" pin="RD14" mode="digital" pullup="true"/>
//	<function name="XBEE_ON_SLEEP"  pin="RG0" mode="digital" direction="out" latch="low" />
//	<function name="XBEE_RESET"  pin="RG1" mode="digital" direction="out" latch="high" />



// *****************************************************************************
/* BSP Switch.

  Summary:
    Defines the switches available on this board.

  Description:
    This enumeration defines the switches available on this board.

  Remarks:
    None.
*/


// CHR mise à jour 29.03.2015
// #define S_OK         PORTGbits.RG12   SWITCH_1
// #define S_ESC_MENU   PORTGbits.RG13   SWITCH_2
// #define S_PLUS       PORTGbits.RG14   SWITCH_3
// #define S_MINUS      PORTGbits.RG15   SWITCH_4
typedef enum
{
    /* SWITCH 1 */
     BSP_SWITCH_1 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_12/*DOM-IGNORE-END*/,
                                                                          
    /* SWITCH 2 */                                                        
     BSP_SWITCH_2 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_13/*DOM-IGNORE-END*/,

    /* SWITCH 3 */
     BSP_SWITCH_3 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_14/*DOM-IGNORE-END*/,

     BSP_SWITCH_4 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_15/*DOM-IGNORE-END*/

} BSP_SWITCH;

// *****************************************************************************
/* BSP Switch state.

  Summary:
    Defines possible states of the switches on this board.

  Description:
    This enumeration defines the possible states of the switches on this board.

  Remarks:
    None.
*/

typedef enum
{
    /* Switch pressed */
    BSP_SWITCH_STATE_PRESSED = /*DOM-IGNORE-BEGIN*/0/*DOM-IGNORE-END*/,

   /* Switch not pressed */
    BSP_SWITCH_STATE_RELEASED = /*DOM-IGNORE-BEGIN*/1/*DOM-IGNORE-END*/

} BSP_SWITCH_STATE;

// *****************************************************************************
/* LED Number.

  Summary:
    Defines the LEDs available on this board.

  Description:
    This enumeration defines the LEDs available on this board.

  Remarks:
    None.
*/

// CHR introduction des 8 led du kit ES

// #define LED0_W       LATAbits.LATA0  //Led0
// #define LED1_W       LATAbits.LATA1  //Led1
// #define LED2_W       LATAbits.LATA4  //Led2
// #define LED3_W       LATAbits.LATA5  //Led3
// #define LED4_W       LATAbits.LATA6  //Led4
// #define LED5_W       LATAbits.LATA7  //Led5
// #define LED6_W       LATAbits.LATA15 //Led6
// #define LED7_W       LATBbits.LATB10 //Led7

typedef enum
{
    BSP_LED_0 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_0/*DOM-IGNORE-END*/,
    BSP_LED_1 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_1/*DOM-IGNORE-END*/,
    BSP_LED_2 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_4/*DOM-IGNORE-END*/,
    BSP_LED_3 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_5/*DOM-IGNORE-END*/,
    BSP_LED_4 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_6/*DOM-IGNORE-END*/,
    BSP_LED_5 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_7/*DOM-IGNORE-END*/,
    BSP_LED_6 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_15/*DOM-IGNORE-END*/,
    // Attention port B
    BSP_LED_7 = /*DOM-IGNORE-BEGIN*/PORTS_BIT_POS_10/*DOM-IGNORE-END*/,

} BSP_LED;

// *****************************************************************************
/* LED State

  Summary:
    Enumerates the supported LED states.

  Description:
    This enumeration defines the supported LED states.

  Remarks:
    None.
*/

typedef enum
{
    /* LED State is on */
    BSP_LED_STATE_OFF = /*DOM-IGNORE-BEGIN*/0,/*DOM-IGNORE-END*/

    /* LED State is off */
    BSP_LED_STATE_ON = /*DOM-IGNORE-BEGIN*/1,/*DOM-IGNORE-END*/

} BSP_LED_STATE;


// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function: 
    void BSP_Initialize(void)

  Summary:
    Performs the necessary actions to initialize a board
  
  Description:
    This function initializes the LED and Switch ports on the board.  This
    function must be called by the user before using any APIs present on this
    BSP.  

  Precondition:
    None.

  Parameters:
    None
  
  Returns:
    None.

  Example:
    <code>
    //Initialize the BSP
    BSP_Initialize();
    </code>

  Remarks:
    None                                                                   
*/

void BSP_Initialize(void);

// *****************************************************************************
/* Function: 
    void BSP_LEDStateSet(BSP_LED led, BSP_LED_STATE state);

  Summary:
    Controls the state of the LED.
  
  Description:
    This function allows the application to specify the state of the LED.

  Precondition:
    BSP_Initialize() should have been called.

  Parameters:
    led     - The LED to operate on.
    state   - The state to be set.
  
  Returns:
    None.

  Example:
    <code>
    
    // Initialize the BSP
    BSP_Initialize();

    // Switch on LED1 on the board 
    BSP_LEDStateSet(BSP_LED_1, BSP_LED_STATE_ON);
    
    // Switch off LED2 on the board 
    BSP_LEDStateSet(BSP_LED_2, BSP_LED_STATE_OFF);

    </code>

  Remarks:
    None                                                                   
*/

void BSP_LEDStateSet(BSP_LED led, BSP_LED_STATE state);

// *****************************************************************************
/* Function: 
    BSP_LED_STATE BSP_LEDStateGet(BSP_LED led);

  Summary:
    Returns the present state of the LED.
  
  Description:
    This function returns the present state of the LED.

  Precondition:
    BSP_Initialize() should have been called.

  Parameters:
    led - The LED to whose status needs to be obtained.
  
  Returns:
    The ON/OFF state of the LED.

  Example:
    <code>
    
    // Initialize the BSP
    BSP_Initialize();

    // Check if LED2 is off
    if(BSP_LED_STATE_OFF == BSP_LEDStateGet(BSP_LED_2)
    {
        // Switch on the LED.
        BSP_LEDStateSet(BSP_LED_2, BSP_LED_STATE_ON);
    }

    </code>

  Remarks:
    None                                                                   
*/

BSP_LED_STATE BSP_LEDStateGet(BSP_LED led);

// *****************************************************************************
/* Function: 
    void BSP_LEDToggle(BSP_LED led);

  Summary:
    Toggles the state of the LED between BSP_LED_STATE_ON and BSP_LED_STATE_OFF.
  
  Description:
    This function toggles the state of the LED between BSP_LED_STATE_ON and
    BSP_LED_STATE_OFF.

  Precondition:
    BSP_Initialize() should have been called.

  Parameters:
    led - The LED to toggle.
  
  Returns:
    None.

  Example:
    <code>
    
    // Initialize the BSP
    BSP_Initialize();

    // Switch on LED1 on the board 
    BSP_LEDStateSet(BSP_LED_1, BSP_LED_STATE_ON);
    
    // Switch off LED2 on the board 
    BSP_LEDStateSet(BSP_LED_2, BSP_LED_STATE_OFF);

    // Toggle state of LED3
    BSP_LEDToggle(BSP_LED_3);
    </code>

  Remarks:
    None                                                                   
*/

void BSP_LEDToggle(BSP_LED led);

// *****************************************************************************
/* Function: 
    void BSP_LEDOn(BSP_LED led);

  Summary:
    Switches ON the specified LED.
  
  Description:
    This function switches ON the specified LED.

  Precondition:
    BSP_Initialize() should have been called.

  Parameters:
    led - The LED to switch on.
  
  Returns:
    None.

  Example:
    <code>
    
    // Initialize the BSP
    BSP_Initialize();

    // Switch on LED1 on the board 
    BSP_LEDOn(BSP_LED_1);
    
    </code>

  Remarks:
    None                                                                   
*/

void BSP_LEDOn(BSP_LED led);

// *****************************************************************************
/* Function: 
    void BSP_LEDOff(BSP_LED led);

  Summary:
    Switches OFF the specified LED.
  
  Description:
    This function switches OFF the specified LED.

  Precondition:
    BSP_Initialize() should have been called.

  Parameters:
    led - The LED to switch off.
  
  Returns:
    None.

  Example:
    <code>
    
    // Initialize the BSP
    BSP_Initialize();

    // Switch off LED1 on the board 
    BSP_LEDOff(BSP_LED_1);
    
    </code>

  Remarks:
    None                                                                   
*/

void BSP_LEDOff(BSP_LED led);

// *****************************************************************************
/* Function: 
    BSP_SWITCH_STATE BSP_SwitchStateGet(BSP_SWITCH switch);

  Summary:
    Returns the present state (pressed or not pressed) of the specified switch.
  
  Description:
    This function returns the present state (pressed or not pressed) of the
    specified switch.

  Precondition:
    BSP_Initialize() should have been called.

  Parameters:
    switch  - The switch whose state needs to be obtained.
  
  Returns:
    The pressed released state of the switch.

  Example:
    <code>
    
    // Initialize the BSP
    BSP_Initialize();

    // Check the state of the switch.
    if(BSP_SWITCH_STATE_PRESSED == BSP_SwitchStateGet(BSP_SWITCH_1))
    {
        // This means that Switch 1 on the board is pressed.
    }

    </code>

  Remarks:
    None                                                                   
*/

BSP_SWITCH_STATE BSP_SwitchStateGet(BSP_SWITCH bspSwitch);


// Ajout CHR 09.12.2014
void BSP_EnableHbrige(void);

#endif //_BSP_CONFIG_H

/*******************************************************************************
 End of File
*/
