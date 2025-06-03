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
    #define SYS_FREQ (8000000L)    //80 MHz
#define delay_cycle() __asm__( "nop" )
#endif

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
// Fonction delay_ms Core Timer
/*--------------------------------------------------------*/

#ifndef SYS_FREQ
    #define SYS_FREQ (8000000L)    //80 MHz
#endif

//void delay_msCt(unsigned int NbMs)
//{
//    unsigned int time_to_wait;
//
//    WriteCoreTimer(0);
//    time_to_wait = (SYS_FREQ / 2000.0) * NbMs;
//    while(ReadCoreTimer() < time_to_wait) {
//        // Waiting
//    }
//}
