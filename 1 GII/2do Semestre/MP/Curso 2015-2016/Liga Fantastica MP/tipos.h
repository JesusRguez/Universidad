#ifndef _TIPOS_H_
#define _TIPOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura para usuarios.txt -> almacena info usuarios del sistema
typedef struct{
 char id[3];
 char nombre[21];
 char perfil[14];   //Deberá ser: participante ; cronista ; administrador
 char login[6];     // Nombre de usuario
 char pass[9];
}usuario;

//Estructura para equipos.txt -> almacena info de equipo
typedef struct{
char id[3];
char nombre[21];
}equipo;

//Estructura para futbolistas.txt -> almacena info de los futbolistas
typedef struct{
char id[3];
char ideq[3];
char nombre[21];
int precio;
int valor;
}futbolista;

//Estructura para plantillas.txt -> almancena info de plantillas configuradas por participante
typedef struct{
char idprop[3];
char idplant[4];
char nombre[31];
int presup;
int punt;
}plantilla;

//Estructura para Jugadores_Plantilla.txt -> Almacena info de los jugadores en base a su plantilla
typedef struct{
char idjug[3];
char ideq[3];
char idplant[4];
}jugplant;

//Estructura Configuracion.txt -> Almacena los datos de la config general
typedef struct{
char config[31];
int valor;
}config;

#endif
