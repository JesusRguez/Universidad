#ifndef _CRONISTA_H_
#define _CRONISTA_H_

#include "tipos.h"
#include "cargar.h"

void listarEquipos(equipo *,int);
void valorarEquipos(futbolista **,int,equipo *,int);
void actualizarPlantillas(jugplant *,int,plantilla **,int,char *,int);

#endif
