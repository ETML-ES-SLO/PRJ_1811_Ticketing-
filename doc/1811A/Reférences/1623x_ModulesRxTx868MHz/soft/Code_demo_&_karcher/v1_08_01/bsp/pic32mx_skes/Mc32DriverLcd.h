#ifndef __MC32DRIVERLCD_H
#define __MC32DRIVERLCD_H
/*--------------------------------------------------------*/
//	Mc32DriverLcd.h
/*--------------------------------------------------------*/
//	Description :	Driver pour LCD Pic 32 
//					
//
//	Auteur 		: 	Gomes Andres
//	Modifications   :
//              C. HUBER 15.05. 2104   ajout printf_lcd
//              C. HUBER 02.12. 2104   ajout lcd_ClearLine
//	Version		:	V1.2
//	Compilateur	:	XC32 V1.33
//
/*--------------------------------------------------------*/

#include <stdarg.h>

/*--------------------------------------------------------*/
// Définition des fonctions prototypes
/*--------------------------------------------------------*/
unsigned char lcd_read_byte( void );
void lcd_send_nibble( unsigned char n );
void lcd_send_byte( unsigned char address, unsigned char n );
void lcd_init(void);
void lcd_gotoxy( unsigned char x, unsigned char y);
void lcd_putc( unsigned char c);
void lcd_put_string_ram( char *ptr_char );
void lcd_put_string_rom( const char *ptr_char );
char lcd_getc( unsigned char x, unsigned char y);
void lcd_bl_on( void ); 
void lcd_bl_off( void );
void printf_lcd(const char *format,  ...);
// Ajout a la demande des utilisateurs
// Auteur C. Huber 02.12.2014
void lcd_ClearLine( unsigned char NoLine);

#endif
