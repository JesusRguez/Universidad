#ifndef _GUARDAR_H_
#define _GUARDAR_H_

#include "tipos.h"
#include "cargar.h"

//precond: un vector usuario existente y un tam de vector
//prostcond : guarda en el fichero los datos de los usuarios
void guardar();
void guardarUsuario(usuario *u, size_t tam);
void guardarEquipo(equipo *e, size_t tam);
void guardarFutbolistas(futbolista *f, size_t tam);
void guardarPlantillas(plantilla *p, size_t tam);
void guardarJugPlant(jugplant *jp, size_t tam);
void guardarConf(config *c, size_t tam);

#endif // _GUARDAR_H_
