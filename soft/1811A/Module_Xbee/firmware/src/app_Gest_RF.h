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

#ifndef _APP_GEST_RF_H    /* Guard against multiple inclusion */
#define _APP_GEST_RF_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "app_Gest_Xbee_RF.h"
#include "Mc32gestI2c24AA02.h"

#define CS_RF_ON PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_14, false);
#define CS_RF_OFF PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_14, true);

#define PWR_UP_ON PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_5, true);
#define PWR_UP_OFF PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_5, false);

#define TX_EN_ON PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_2, true);
#define TX_EN_OFF PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_2, false);

#define TXR_CE_ON PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3, true);
#define TXR_CE_OFF PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3, false);

// regs
#define WC  0x00  // Write configuration register command
#define RC  0x10  // Read  configuration register command
#define WTP  0x20 // Write TX Payload  command
#define RTP  0x21 // Read  TX Payload  command
#define WTA  0x22 // Write TX Address  command
#define RTA  0x23 // Read  TX Address  command
#define RRP  0x24 // Read  RX Payload  command

#define AM PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_10);

#define DR PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_11);

#define CD PLIB_PORTS_PinGet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_12);

void RF_initialize ();

void Timer0Interrupt ();

void Activer_Ecoute_RF ();

void Activer_Envoi_RF ();

void Stand_by_RF ();

void Stand_by_RF ();

void MODE_CONFIG ();

void Lecture_Rx ();

void PWR_Down ();

void Ecrire_Buffer_Envoi (uint32_t);

void Timer0Interrupt ();

bool Get_AM_Value ();

bool Get_CD_Value ();

bool Get_DR_Value ();

uint32_t Get_datas (uint32_t*);

void Ecrire_Addresse_Envoi (uint32_t Data);

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#end
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

#endif
/* *****************************************************************************
 End of File
 */
