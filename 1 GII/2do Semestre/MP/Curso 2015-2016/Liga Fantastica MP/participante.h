#ifndef _PARTICIPANTE_H_
#define _PARTICIPANTE_H_

#include "tipos.h"
#include "cargar.h"

int nPlantillasUsuario;

void contarPlantillas(char *,plantilla *,int,int *);
void crearPlantilla(char *,plantilla **,int *,jugplant **,int *,int *);
void listarplantillas(char *,plantilla *,int,int);
void eliminarPlantilla(char *, plantilla **, int *, int *);
void ranking(plantilla *, int);
void eliminarSaltos(char *, int);

#endif
