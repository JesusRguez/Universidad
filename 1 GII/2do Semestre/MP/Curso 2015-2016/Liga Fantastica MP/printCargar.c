#include "tipos.h"
#include "cargar.h"

void imprimir(){

    printCargarUsuarios(vUsuarios,nUsuarios);
    printCargarEquipos(vEquipos,nEquipos);
    printCargarFutbolistas(vFutbolistas,nFutbolistas);
    printCargarPlantillas(vPlantillas,nPlantillas);
    printCargarJugplants(vJugplants,nJugplants);
    printCargarConfigs(vConfigs,nConfigs);

}

void printCargarUsuarios(usuario *vUsuarios,int n){

    int i;

    puts("\n-----------------USUARIOS-----------------\n");

    for(i=0;i<n;i++){
            printf("ID USUARIO:%s\n",vUsuarios[i].id);
            printf("NOMBRE:%s\n",vUsuarios[i].nombre);
            printf("PERFIL:%s\n",vUsuarios[i].perfil);
            printf("LOGIN:%s\n",vUsuarios[i].login);
            printf("PASS:%s\n",vUsuarios[i].pass);
    }

    puts("------------------------------------------\n");

}

void printCargarEquipos(equipo *vEquipos,int n){

    int i;

    puts("\n-----------------EQUIPOS------------------\n");

    for(i=0;i<n;i++){
            printf("ID EQUIPO:%s\n",vEquipos[i].id);
            printf("NOMBRE:%s\n",vEquipos[i].nombre);
    }

    puts("------------------------------------------\n");

}

void printCargarFutbolistas(futbolista *vFutbolistas,int n){

    int i;

    puts("\n----------------FUTBOLISTAS----------------\n");

    for(i=0;i<n;i++){
            printf("ID FUTBOLISTA:%s\n",vFutbolistas[i].id);
            printf("ID EQUIPO:%s\n",vFutbolistas[i].ideq);
            printf("NOMBRE:%s\n",vFutbolistas[i].nombre);
            printf("PRECIO:%d\n",vFutbolistas[i].precio);
            printf("VALORACION:%d\n",vFutbolistas[i].valor);
    }

    puts("---------------------------------------------\n");

}

void printCargarPlantillas(plantilla *vPlantillas,int n){

    int i;

    puts("\n-----------------PLANTILLAS-----------------\n");

    for(i=0;i<n;i++){
            printf("ID PROPIETARIO:%s\n",vPlantillas[i].idprop);
            printf("ID PLANTILLA:%s\n",vPlantillas[i].idplant);
            printf("NOMBRE:%s\n",vPlantillas[i].nombre);
            printf("PRESUPUESTO:%d\n",vPlantillas[i].presup);
            printf("PUNTUACION:%d\n",vPlantillas[i].punt);
    }

    puts("----------------------------------------------\n");

}

void printCargarJugplants(jugplant *vJugplants,int n){

    int i;

    puts("\n-----------JUGADORES_PLANTILLAS--------------\n");

    for(i=0;i<n;i++){
            printf("ID USUARIO:%s\n",vJugplants[i].idjug);
            printf("ID PLANTILLA:%s\n",vJugplants[i].idplant);
    }

    puts("------------------------------------------------\n");

}

void printCargarConfigs(config *vConfigs,int n){

    int i;

    puts("\n-----------------CONFIGURACION-----------------\n");

    for(i=0;i<n;i++){
            printf("CONFIGURACION:%s\n",vConfigs[i].config);
            printf("VALOR:%d\n",vConfigs[i].valor);
    }

    puts("-------------------------------------------------\n");

}
