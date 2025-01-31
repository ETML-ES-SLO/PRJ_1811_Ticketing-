/*******************************************************************************
  Board Support Package Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    bsp_sys_init.c

  Summary:
    Board Support Package implementation for Starter Kit PIC32MX795F512L ETML-ES.

  Description:
    This file contains routines that implement the board support package for
    PIC32MX795F512L  Starter Kit ES.
 *
 *  MODIFICATIONS
 *  CHR 09.12.2015 - remplacement PORT par LAT pour etablir etat out
 *                 - Ajout fonction BSP_EnableHbridge
 *
 *  CHR 17.02.2015  - PEC12 modif car lignes séparée
 *
 *  CHR 18.05.2015  - Adaptation BSP_SwitchStateGet
 * 
 *  CHR 17.09.2015  - Simplification des init car tout fait automatiquement dans 
 *                    SYS_PORT_INITIALIZE
 *
*******************************************************************************/



// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "bsp_config.h"
#include "system/devcon/sys_devcon.h"
#include "peripheral/devcon/plib_devcon.h"

// *****************************************************************************
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

  Remarks:
    Refer to bsp_config.h for usage information.
  
        CHR 17.09.2017 la fonction BSP_Initialize devient quasi vide suite à l'action
        d'initialisation effectuée dabs SYS_PORT_INIT sur la base de bsp.xml
*/

void BSP_Initialize(void )
{

    // Pour ne pas entrer en conflit avec le JTAG
    SYS_DEVCON_JTAGDisable();     // déja fait mais si on oublie
    
    /*--------------------------------------------------------*/
    // Analogique
    /*--------------------------------------------------------*/
    /*
        TRISBbits.TRISB0 = 1; //Analog0 en entrée
        TRISBbits.TRISB1 = 1; //Analog1 en entrée
   */
    
    // CHR config AN0 et AN1 en Analogique et les autres en digital 
    // Nécessaire de le faire à cause des élément non configuré
     PLIB_PORTS_AnPinsModeSelect(PORTS_ID_0, 0x0003, PORTS_PIN_MODE_ANALOG);
     PLIB_PORTS_AnPinsModeSelect(PORTS_ID_0, ~0x0003, PORTS_PIN_MODE_DIGITAL);
    
    /*
        PLIB_PORTS_PinModeSelect(PORTS_ID_0, PORTS_ANALOG_PIN_0, PORTS_PIN_MODE_ANALOG);
        PLIB_PORTS_PinModeSelect(PORTS_ID_0, PORTS_ANALOG_PIN_1, PORTS_PIN_MODE_ANALOG);
    */
   
    
	/*--------------------------------------------------------*/
	// Clavier matriciel
	/*--------------------------------------------------------*/
	// A l'initialisation, tout en entrée afin de ne pas avoir de problème
    /*
	TRISBbits.TRISB2 = 1; //Colonne1 en entrée
	TRISBbits.TRISB3 = 1; //Colonne2 en entrée
	TRISBbits.TRISB4 = 1; //Colonne3 en entrée
	TRISBbits.TRISB5 = 1; //Colonne4 en entrée
	TRISGbits.TRISG6 = 1; //Ligne1 en entrée
	TRISGbits.TRISG7 = 1; //Ligne2 en entrée
	TRISBbits.TRISB14 = 1; //Ligne3 en entrée
	TRISBbits.TRISB15 = 1; //Ligne4 en entrée
    */

	/*--------------------------------------------------------*/
	// PEC12 -- Touches
	/*--------------------------------------------------------*/
    /*
	TRISGbits.TRISG12 = 1; // S_OK  en entrée
	TRISGbits.TRISG13 = 1; // S_ESC_MENU en entrée
	TRISGbits.TRISG14 = 1; // S_PLUS en entrée
	TRISGbits.TRISG15 = 1; // S_MINUS en entrée
    // PEC12 modif du 17.02.2015
    TRISEbits.TRISE8 = 1 ;  // PEC12_A en input
    TRISEbits.TRISE9 = 1 ;  // PEC12_B en input
    TRISDbits.TRISD7 = 1 ;  // PEC12_PB en input
    */


	/*--------------------------------------------------------*/
	// I2C
	/*--------------------------------------------------------*/
	// TRISAbits.TRISA2 = 0; //I2C_SCL en sortie
	// I2C_SDA Bidirectionnel

	/*--------------------------------------------------------*/
	// SPI -- Chip Select
	/*--------------------------------------------------------*/
    /*
	TRISDbits.TRISD3 = 0;       //CS_LM70 en sortie
	LATDbits.LATD3 = 1;         //CS_LM70 à 1
	TRISDbits.TRISD4 = 0;       //CS_DAC en sortie
	LATDbits.LATD4 = 1;         //CS_DAC à 1
	TRISDbits.TRISD5 = 0;       //CS_SD en sortie
	LATDbits.LATD5 = 1;         //CS_SD à 1
    */
	/*--------------------------------------------------------*/
	// Ethernet
	/*--------------------------------------------------------*/
	// Je ne sais pas encore quoi en faire, je mets tout en entrée
    // CHR par defaut en entrée si non definit
    /*
	TRISDbits.TRISD6 = 1; //ETH_TX_EN en entrée
	TRISDbits.TRISD7 = 1; //ETH_TX_CLK en entrée
	TRISDbits.TRISD8 = 1; //ETH_MDIO en entrée
	TRISDbits.TRISD11 = 1; //ETH_MDC_EN en entrée
	TRISBbits.TRISB11 = 1; //ETH_RD_ER en entrée
	TRISBbits.TRISB12 = 1; //ETH_D0 en entrée
	TRISBbits.TRISB13 = 1; //ETH_D1 en entrée
	TRISAbits.TRISA14 = 1; //ETH_POWERDOWN_INT en entrée !! CHR
	TRISEbits.TRISE8 = 1; //ETH_AN_EN en entrée
	TRISEbits.TRISE9 = 1; //ETH_AN0 en entrée
	TRISFbits.TRISF0 = 1; //ETH_TX_D1 en entrée
	TRISFbits.TRISF1 = 1; //ETH_TX_D0 en entrée
	TRISGbits.TRISG8 = 1; //ETH_CRS_DV en entrée
	TRISGbits.TRISG8 = 1; //ETH_RST en entrée
    */
    
	/*----------------------------------------------------*/
	// SD Card
	/*----------------------------------------------------*/
	// TRISCbits.TRISC3 = 1; //SD_DETECT en entrée

	/*----------------------------------------------------*/
	// DAC
	/*----------------------------------------------------*/
	// TRISDbits.TRISD9 = 0; //DAC_CLEAR en sortie
	// LATDbits.LATD9 = 1; //DAC_CLEAR = 1

	/*----------------------------------------------------*/
	// LEDs
	/*----------------------------------------------------*/
     
    /*
	LED0_T = 0; //LED_D6  (Led0) en sortie
	LED0_W = 1; //LED_D6  (Led0) = 1
	LED1_T = 0; //LED_D10 (Led1) en sortie
	LED1_W = 1; //LED_D10 (Led1) = 1
	LED2_T = 0; //LED_D7  (Led2) en sortie
	LED2_W = 1; //LED_D7  (Led2) = 1
	LED3_T = 0; //LED_D11 (Led3) en sortie
	LED3_W = 1; //LED_D11 (Led3) = 1
	LED4_T = 0; //LED_D8  (Led4) en sortie
	LED4_W = 1; //LED_D8  (Led4) = 1
	LED5_T = 0; //LED_D12 (Led5) en sortie
	LED5_W = 1; //LED_D12 (Led5) = 1
	LED6_T = 0; //LED_D9  (Led6) en sortie
	LED6_W = 1; //LED_D9  (Led6) = 1
	LED7_T = 0; //LED_D13 (Led7) en sortie
	LED7_W = 1; //LED_D13 (Led7) = 1
    */
    
	/*--------------------------------------------------------*/
	// USB
	/*--------------------------------------------------------*/
	// TRISFbits.TRISF3 = 1; //USB_DETECT en entrée
	// TRISGbits.TRISG2 = 1; //USB_PLUS en entrée par sécurité
	// TRISGbits.TRISG3 = 1; //USB_MINUS en entrée par sécurité

	/*--------------------------------------------------------*/
	// RS232
	/*--------------------------------------------------------*/
    /*
	TRISFbits.TRISF8 = 0; //RS232_TX en sortie
	LATFbits.LATF8 = 1; //RS232_TX à 1
	TRISFbits.TRISF2 = 1; //RS232_RX en entrée
	TRISDbits.TRISD15 = 0; //RS232_RTS en sortie
	LATDbits.LATD15 = 1; //RS232_RTS à 1
	TRISDbits.TRISD14 = 1; //RS232_CTS en entrée
    */
    
	/*--------------------------------------------------------*/
	// LCD
	/*--------------------------------------------------------*/
	// On met d'abord toutes les pattes du LCD à 1 sauf le backlight
    /*
    LCD_RS_W = 1;
    LCD_RW_W = 1;
    LCD_E_W = 1;
    LCD_BL_W = 0;
    LCD_DB4_W = 1;
    LCD_DB5_W = 1;
    LCD_DB6_W = 1;
    LCD_DB7_W = 1;
    */
    // Puis on configure toutes les pattes en sortie, lorsqu'on aura besoin, on modifiera
    // ce qu'il faut en entrée
    /*
	LCD_RS_T = 0; //LCD_RS en sortie
	LCD_RW_T = 0; //LCD_RW en sortie
	LCD_E_T = 0; //LCD_E en sortie
	LCD_BL_T = 0; //LCD_BL en sortie
	LCD_DB4_T = 0; //LCD_DB4 en sortie
	LCD_DB5_T = 0; //LCD_DB5 en sortie
	LCD_DB6_T = 0; //LCD_DB6 en sortie
	LCD_DB7_T = 0; //LCD_DB7 en sortie
    */
	/*--------------------------------------------------------*/
	// Pont en H
	/*--------------------------------------------------------*/
	// Tout en sortie mais à 0
   

	/*--------------------------------------------------------*/
	// XBee
	/*--------------------------------------------------------*/
    /*
	TRISFbits.TRISF5 = 0; //XBEE_TX en sortie
	LATFbits.LATF5 = 1; //XBEE_TX = 1
	TRISFbits.TRISF4 = 1; //XBEE_RX en entrée
	TRISFbits.TRISF13 = 0; //XBEE_RTS en sortie
	LATFbits.LATF13 = 1; //XBEE_RTS = 1
	TRISFbits.TRISF12 = 1; //XBEE_CTS en entrée
	TRISGbits.TRISG0 = 1; //XBEE_ON_SLEEP en entrée
	TRISGbits.TRISG1 = 0; //XBEE_RESET en sortie
	LATGbits.LATG1 = 1; //XBEE_RESET = 1
    */
}

// *****************************************************************************
/* Function: 
    void BSP_LEDStateSet(BSP_LED led, BSP_LED_STATE state);

  Summary:
    Controls the state of the LED.
  
  Description:
    This function allows the application to specify the state of the LED.

  Adaptation:
     CHR 08.09.2014  adaptation au 8 led du KIT ES.
*/

void BSP_LEDStateSet(BSP_LED led, BSP_LED_STATE state)
{
    /* Switch ON the LED */
    if (led == BSP_LED_7) {
        PLIB_PORTS_PinWrite ( PORTS_ID_0 , PORT_CHANNEL_B , led, state );
    } else {
        PLIB_PORTS_PinWrite ( PORTS_ID_0 , PORT_CHANNEL_A , led, state );
    }
   
}

// *****************************************************************************
/* Function: 
    void BSP_LEDOn(BSP_LED led);

  Summary:
    Switches ON the specified LED.
  
  Description:
    This function switches ON the specified LED.

  Adaptation:
     CHR 08.09.2014  adaptation au 8 led du KIT ES.
*/

void BSP_LEDOn(BSP_LED led)
{
    // Led On pour Clear
    if (led == BSP_LED_7) {
        PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_B, led);
    } else {
        PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_A, led);
    }
}

// *****************************************************************************
/* Function: 
    void BSP_LEDOff(BSP_LED led);

  Summary:
    Switches OFF the specified LED.
  
  Description:
    This function switches OFF the specified LED.

  Adaptation:
     CHR 08.09.2014  adaptation au 8 led du KIT ES.
*/

void BSP_LEDOff(BSP_LED led)
{
    // Led Off pour Set
    if (led == BSP_LED_7) {
        PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_B, led);
    } else {
        PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_A, led);
    }
}

// *****************************************************************************
/* Function: 
    BSP_LED_STATE BSP_LEDStateGet(BSP_LED led);

  Summary:
    Returns the present state of the LED.
  
  Description:
    This function returns the present state of the LED.

  Adaptation:
     CHR 08.09.2014  adaptation au 8 led du KIT ES.
*/

BSP_LED_STATE BSP_LEDStateGet(BSP_LED led)
{
    BSP_LED_STATE tmp;

    if (led == BSP_LED_7) {
        tmp = PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_B, led);
    } else {
        tmp = PLIB_PORTS_PinGetLatched(PORTS_ID_0, PORT_CHANNEL_A, led);
    }
    return(tmp);
}

// *****************************************************************************
/* Function: 
    void BSP_LEDToggle(BSP_LED led);

  Summary:
    Toggles the state of the LED between BSP_LED_STATE_ON and BSP_LED_STATE_OFF.
  
  Description:
    This function toggles the state of the LED between BSP_LED_STATE_ON and
    BSP_LED_STATE_OFF.

  Adaptation:
     CHR 08.09.2014  adaptation au 8 led du KIT ES.
*/

void BSP_LEDToggle(BSP_LED led)
{
    if (led == BSP_LED_7) {
        PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_B,led );
    } else {
        PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A,led );
    }
   
}

// *****************************************************************************
/* Function: 
    void BSP_SwitchStateGet(BSP_SWITCH switch);

  Summary:
    Returns the present state (pressed or not pressed) of the specified switch.
  
  Description:
    This function returns the present state (pressed or not pressed) of the
    specified switch.

  Remarks:
    None.
*/


// CHR les switch sont sur le port G
BSP_SWITCH_STATE BSP_SwitchStateGet( BSP_SWITCH bspSwitch )
{
    return ( PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_G, bspSwitch) );
}


// ajout 9.12.2014
// correction STBY_HBRIDGE 30.01.2015
void BSP_EnableHbrige(void)
{
    TRISBbits.TRISB8 = 0; //STBY_HBRIDGE en sortie
    STBY_HBRIDGE_W = 0;   // STBY low durant init

	TRISDbits.TRISD12 = 0; //AIN1_HBRIDGE en sortie
	TRISDbits.TRISD13 = 0; //AIN2_HBRIDGE en sortie
    // Ne pas toucher PWM à cause init OC avant
	// TRISDbits.TRISD1 = 0;  //PWMA_HBRIDGE en sortie
    // Mise en short brake PWM dont care
    AIN1_HBRIDGE_W = 1;   //AIN1 High
	AIN2_HBRIDGE_W = 1;  //AIN2 High
	// PWMA_HBRIDGE_W = 0;  //PWMA low

	TRISCbits.TRISC1 = 0; //BIN1_HBRIDGE en sortie
	TRISCbits.TRISC2 = 0; //BIN2_HBRIDGE en sortie
    // Ne pas toucher PWM à cause init OC avant
	// TRISDbits.TRISD2 = 0; //PWMB_HBRIDGE en sortie

    // Mise en short brake PWM dont care
    BIN1_HBRIDGE_W = 1;   //BIN1 High
	BIN2_HBRIDGE_W = 1;   //BIN2 High
	// PWMB_HBRIDGE_W = 0;   //PWMB low

    STBY_HBRIDGE_W = 1;   // STBY High
}

/*******************************************************************************
 End of File
*/
