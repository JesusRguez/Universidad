// Modulo Texto

#include <stdio.h>

#ifndef __TEXTO__
#define __TEXTO__


typedef FILE * texto;

texto abrir_texto(const char *s);
void cerrar_texto(texto txt);
void leer_palabra(texto txt, palabra pal);
logico fin_de_texto(texto txt);


#endif
