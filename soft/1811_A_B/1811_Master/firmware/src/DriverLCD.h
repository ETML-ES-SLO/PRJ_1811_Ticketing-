#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H
/*--------------------------------------------------------*/
// DriverLCD.h
/*--------------------------------------------------------*/
//	Description : Utilitaire qui contient les prototypes 
//              de fonctions des differentes variables pour
//              l'écran
//
//	Auteur 		: Paulo Gomes
//	Version		: V1.0
//
/*--------------------------------------------------------*/

// Variables pour certains calculs
unsigned short _width, _height, cursor_y, cursor_x, 
            textcolor, textbgcolor, textsize, wrap;

// Differentes fonctions pour l'écran

// Initialisation de l'écran
void tft_begin(void); 

// Écriture d'un caractère
void tft_write(unsigned char c);

// Remplissage de l'écran avec une couleur 
void tft_fillScreen(unsigned short color);

// Dessine et rempli un rectangle avec une couleur
void tft_fillRect(short x, short y, short w, short h,
                 unsigned short color);

// Choisi l'endroit ou on veut écrire ou dessiner
void tft_setAddrWindow(unsigned short x0, unsigned short y0, 
                   unsigned short x1, unsigned short y1);

// Dessine un pixel
void tft_drawPixel(short x, short y, unsigned short color);

/* DrawLine(Xa,Ya,Xb,Yb,color);
 * dessine une ligne entre 2 points A et B
 * http://www.brackeen.com/vga/shapes.html 
 */
void DrawLine(short Xa, short Ya, short Xb, short Yb, unsigned short color);

// Dessine une line horizontale
void tft_drawFastHLine( short x,  short y,  short w, unsigned short color);

// Dessine une line verticale
void tft_drawFastVLine(short x, short y, short h, unsigned short color);

// Desine un caractère
void drawChar(short x, short y, unsigned char c,
               unsigned short fgcolor, unsigned short bgcolor, unsigned short size);

// Fait un rotation de l'écran de 90° vers la droite (max 4 fois)
void setRotation(short m);

// Defini l'emplacement du curseur
void tft_setCursor(short x, short y);

// Modifie la couleur de la police
void tft_setTextColor(unsigned short c);

void tft_setTextColor_F(unsigned short fore, unsigned short Back);
// Modifie la taille du text à afficher
void tft_setTextSize(unsigned char s);

// Fonction qui permet d'écrire
void tft_write(unsigned char c);

// Fonction qui permet d'écrire une chaine de caractères
void tft_writeString(char* str);

#endif	/* XC_HEADER_TEMPLATE_H */

