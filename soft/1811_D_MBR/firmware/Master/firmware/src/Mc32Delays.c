/*--------------------------------------------------------*/
//	Mc32Delays.c
/*--------------------------------------------------------*/
//	Description :	Fonctions de delay afin
//			de pouvoir utiliser la même syntaxe
//			que sous CCS.
//
//	Auteurs 		: 	F. Dominé / C. Huber
//
//	Version		:	V2.0
//	Compilateur	:	nécessaire pour XC32 V 1.40
//
// Revu / modifié: 
// CHR 17.12.2015    besoin du fichier maison Mc32CoreTimer.h
/*--------------------------------------------------------*/


#include "Mc32Delays.h"
#include <stdint.h>
#include <cp0defs.h>
#include <xc.h>
// Nécessaire pour la fonction delay_msCt
//#include "Mc32CoreTimer.h"

#ifndef SYS_FREQ
    #define SYS_FREQ (4000000L)    //40 MHz
#define delay_cycle() __asm__( "nop" )
#endif
//le core timer est incrémenté tous les 2 SYSCLK
#define TICK_CT_MS (SYS_FREQ / 2000L)
#define TICK_CT_US (SYS_FREQ / 2000000L)
//#define TICK_OVERHEAD 15    //pour ajustement. mesuré 15 cycles Core Timer de surplus
//valeur quasi-fixe (pu observer 3 cycles CPU en plus en optimisation 0
//par rapport à 1.
#define TICK_OVERHEAD 0
/*
// Utilisation du CoreTimer
void PreciseWait(int usToWait)
{
    //int i = 0;
    //for(i)
        
}


void delay100ns(void)
{
  // Il a fallu touiller un peu pour arriver à 500ns
  // CHR ajout pour Ep3 2015 non testé
  //
}
 * */
/*--------------------------------------------------------*/
// Fonction delay500ns
/*--------------------------------------------------------*/
void delay500ns(void)
{
  // Il a fallu touiller un peu pour arriver à 500ns
  // CHR 09.09.2014 avec 8 250 ns avec 9 612 ns ??????
    
    delay_cycle(); // !! INCORRECT ??
    
}

/*--------------------------------------------------------*/
// Fonction delay_us
/*--------------------------------------------------------*/
void delay_us(unsigned int us)
{
  // Il a fallu touiller un peu pour arriver à la us
  // Delay de 1us pour le PIC32MZ
	int i = 0;
    us --;//compense pour les init de boucle
        delay_cycle();
    for(i=0;i<us;i++)
    {   // 1us = 1000ns
        delay_cycle();
        delay_cycle();
        delay_cycle();
        delay_cycle();
        delay_cycle();
    }
}
/*--------------------------------------------------------*/
// Fonction delay_ms
/*--------------------------------------------------------*/
void delay_ms(unsigned int ms)
{	
	unsigned int i;
	for(i=1;i<=ms;i++)
	{
		// 1ms = 1000us
		delay_us(20000); 	
	}
}



/*--------------------------------------------------------*/
// Fonction delay_msCt Core Timer
/*--------------------------------------------------------*/
//attente passive n * ms
//utilise le Core Timer
void __attribute__((optimize("-O0"))) delay_msCt(uint32_t NbMs)
{
    uint32_t time_to_wait;

    _CP0_SET_COUNT(0);
    time_to_wait = (TICK_CT_MS * NbMs) - TICK_OVERHEAD;
    while(_CP0_GET_COUNT()  < time_to_wait) {
        // Waiting
    }
}
//testé SCA 24.09.19 : 996 us au lieu de 1 ms
#ifndef SYS_FREQ
    #define SYS_FREQ (4000000L)    //40 MHz
#endif



