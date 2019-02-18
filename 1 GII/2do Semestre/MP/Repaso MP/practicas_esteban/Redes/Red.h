// Modulo Red

#include "Ip.h"
#include "Mac.h"

#ifndef __RED__
#define __RED__


struct T_Red {
    ip pr;
    mac m;
    char c;
};

typedef struct T_Red * red;

red CrearRed(int n);
void DestruirRed(red r);
void MostrarEquipos(red r, int n, ip prt, ip mascara);
void ActivarPuertos(red r, int n, ip prt, ip mascara);
void IntroducirRed(red r, int i, char *cad);
void MostrarMac(red r, int n, ip puesto);


#endif
