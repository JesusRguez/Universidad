#ifndef _CARGAR_H_
#define _CARGAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

int nUsuarios;              //Numero de usuarios en usuarios.txt
int nEquipos;               //Numero de equipos en equipos.txt
int nFutbolistas;           //Numero de futbolistas en equipos.txt
int nPlantillas;            //Numero de plantillas en plantillas.txt
int nJugplants;             //Numero de relaciones entre jugadores y plantillas en jugadores_plantillas.txt
int nConfigs;               //Numero de datos de configuracion general en configuracion.txt

usuario *vUsuarios;             //vUsuarios es un puntero con la direccion de inicio de un vetor de usuario
equipo *vEquipos;               //vEquipos es un puntero con la direccion de inicio de un vetor de equipo
futbolista *vFutbolistas;       //vFutbolistas es un puntero con la direccion de inicio de un vetor de futbolista
plantilla *vPlantillas;         //vPlantillas es un puntero con la direccion de inicio de un vetor de plantilla
jugplant *vJugplants;           //vJugplant es un puntero con la direccion de inicio de un vetor de jugplant
config *vConfigs;               //vConfig es un puntero con la direccion de inicio de un vetor de config

int cargar();
int cargarUsuarios(usuario **,int *);
int cargarEquipos(equipo **,int *);
int cargarFutbolistas(futbolista **,int *);
int cargarPlantillas(plantilla **,int *);
int cargarJugplants(jugplant **,int *);
int cargarConfigs(config **,int *);

void imprimir();
void printCargarUsuarios(usuario *,int);
void printCargarEquipos(equipo *,int);
void printCargarFutbolistas(futbolista *,int);
void printCargarPlantillas(plantilla *,int);
void printCargarJugplants(jugplant *,int);
void printCargarConfigs(config *,int);

#endif
