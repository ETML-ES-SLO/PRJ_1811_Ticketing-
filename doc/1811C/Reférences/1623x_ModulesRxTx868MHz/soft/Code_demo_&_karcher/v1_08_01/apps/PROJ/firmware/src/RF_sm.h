/* ************************************************************************** */
/** gestion RF via machine d'état
 *
 *  @Company
 *    ETML-ES - Simonet Yoann
 *
 *  @File Name
 *    RF_sm.h
 *
 *  @Summary
 *    gestion RF via machine d'état
 *
 *  @Description
 *    gestion SPI via machine d'état
 *    Testé pour fonctionner avec NRF905
 * 

 *  
*/

#ifndef _RF_SM_H    /* Guard against multiple inclusion */
#define _RF_SM_H

#include <stdint.h>
#include "app.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */


typedef enum
{
	/* SPI's state machine's states. */
	CONNECTION_REQUEST=0,
    RF_STATE_IDLE,
    RF_STATE_SEND,
    RF_STATE_RECEIVE,        
    RF_STATE_AWAIT_ACK,        
    RF_STATE_SEND_ACK,

} SPI_STATES;

extern SPI_STATES RF_State;


void RF_DoTasks(void);
void sendRF(uint32_t add,uint8_t data);
bool receiverRF(char *pmess);
void Init_SM_RF();

#endif /* _SPI_SM_H */

/* *****************************************************************************
 End of File
 */
