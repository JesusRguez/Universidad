#include "cargar.h"

int cargar(){

    cargarUsuarios(&vUsuarios,&nUsuarios);
    cargarEquipos(&vEquipos,&nEquipos);
    cargarFutbolistas(&vFutbolistas,&nFutbolistas);
    cargarPlantillas(&vPlantillas,&nPlantillas);
    cargarJugplants(&vJugplants,&nJugplants);
    cargarConfigs(&vConfigs,&nConfigs);

    return (0);
}

int cargarUsuarios(usuario **vUsuarios,int *n){

    FILE *fichero;

    char linea[57];             // Guardará cada línea que leamos del fichero.
    char *token;

    *vUsuarios=NULL;
    *n=0;

    fichero=fopen("DATA/usuarios.txt","r");

    if (fichero==NULL){

        puts("Error al abrir el fichero DATA/usuarios.txt.");

    }else{

        do{

            fgets(linea,57,fichero);

            if (strcmp(linea,"\0")){

                *vUsuarios=realloc((usuario *)(*vUsuarios),((*n)+1)*sizeof(usuario));

                token=strtok(linea,"-");
                strcpy((*vUsuarios)[*n].id,token);

                token=strtok(NULL,"-");
                strcpy((*vUsuarios)[*n].nombre,token);

                token=strtok(NULL,"-");
                strcpy((*vUsuarios)[*n].perfil,token);

                token=strtok(NULL,"-");
                strcpy((*vUsuarios)[*n].login,token);

                token=strtok(NULL,"\n");
                strcpy((*vUsuarios)[*n].pass,token);

                (*n)++;

            }

        }while(!feof(fichero));
    }

    fclose(fichero);

    return 0;
}

int cargarEquipos(equipo **vEquipos,int *n){

    FILE *fichero;

    char linea[25];
    char *token;

    *vEquipos=NULL;
    *n=0;

    fichero=fopen("DATA/equipos.txt","r");

    if (fichero==NULL){

        puts("Error al abrir el fichero DATA/equipos.txt.");

    }else{

        do{

            fgets(linea,25,fichero);

            if (strcmp(linea,"\0")){

                *vEquipos=realloc((equipo *)(*vEquipos),((*n)+1)*sizeof(equipo));

                token=strtok(linea,"-");
                strcpy((*vEquipos)[*n].id,token);

                token=strtok(NULL,"\n");
                strcpy((*vEquipos)[*n].nombre,token);

                (*n)++;

            }

        }while(!feof(fichero));
    }

    fclose(fichero);

    return 0;
}

int cargarFutbolistas(futbolista **vFutbolistas,int *n){

    FILE *fichero;

    char linea[37];             // Guardará cada línea que leamos del fichero.
    char *token;

    *vFutbolistas=NULL;
    *n=0;

    fichero=fopen("DATA/futbolistas.txt","r");

    if (fichero==NULL){

        puts("Error al abrir el fichero DATA/futbolistas.txt.");

    }else{

        do{

            fgets(linea,37,fichero);

            if (strcmp(linea,"\0")){

                *vFutbolistas=realloc((futbolista *)(*vFutbolistas),((*n)+1)*sizeof(futbolista));

                token=strtok(linea,"-");
                strcpy((*vFutbolistas)[*n].id,token);

                token=strtok(NULL,"-");
                strcpy((*vFutbolistas)[*n].ideq,token);

                token=strtok(NULL,"-");
                strcpy((*vFutbolistas)[*n].nombre,token);

                token=strtok(NULL,"-");
                (*vFutbolistas)[*n].precio=atoi(token);

                token=strtok(NULL,"\n");
                (*vFutbolistas)[*n].valor=atoi(token);

                (*n)++;

            }

        }while(!feof(fichero));
    }

    fclose(fichero);

    return 0;
}

int cargarPlantillas(plantilla **vPlantillas,int *n){

    FILE *fichero;

    char linea[44];             // Guardará cada línea que leamos del fichero.
    char *token;

    *vPlantillas=NULL;
    *n=0;

    fichero=fopen("DATA/plantillas.txt","r");

    if (fichero==NULL){

        puts("Error al abrir el fichero DATA/plantillas.txt.");

    }else{

        do{

            fgets(linea,44,fichero);

            if (strcmp(linea,"\0")){

                *vPlantillas=realloc((plantilla *)(*vPlantillas),((*n)+1)*sizeof(plantilla));

                token=strtok(linea,"-");
                strcpy((*vPlantillas)[*n].idprop,token);

                token=strtok(NULL,"-");
                strcpy((*vPlantillas)[*n].idplant,token);

                token=strtok(NULL,"-");
                strcpy((*vPlantillas)[*n].nombre,token);

                token=strtok(NULL,"-");
                (*vPlantillas)[*n].presup=atoi(token);

                token=strtok(NULL,"\n");
                (*vPlantillas)[*n].punt=atoi(token);

                (*n)++;

            }

        }while(!feof(fichero));
    }

    fclose(fichero);

    return 0;
}

int cargarJugplants(jugplant **vJugplants,int *n){

    FILE *fichero;

    char linea[12];             // Guardará cada línea que leamos del fichero.
    char *token;

    *vJugplants=NULL;
    *n=0;

    fichero=fopen("DATA/jugadores_plantillas.txt","r");

    if (fichero==NULL){

        puts("Error al abrir el fichero DATA/jugadores_plantillas.txt.");

    }else{

        do{

            fgets(linea,12,fichero);

            if (strcmp(linea,"\0")){

                *vJugplants=realloc((jugplant *)(*vJugplants),((*n)+1)*sizeof(jugplant));

                token=strtok(linea,"-");
                strcpy((*vJugplants)[*n].idjug,token);

                token=strtok(NULL,"-");
                strcpy((*vJugplants)[*n].ideq,token);

                token=strtok(NULL,"\n");
                strcpy((*vJugplants)[*n].idplant,token);

                (*n)++;

            }

        }while(!feof(fichero));
    }

    fclose(fichero);

    return 0;
}

int cargarConfigs(config **vConfigs,int *n){

    FILE *fichero;

    char linea[35];             // Guardará cada línea que leamos del fichero.
    char *token;

    *vConfigs=NULL;
    *n=0;

    fichero=fopen("DATA/configuracion.txt","r");

    if (fichero==NULL){

        puts("Error al abrir el fichero DATA/configuracion.txt.");

    }else{

        do{

            fgets(linea,35,fichero);

            if (strcmp(linea,"\0")){

                *vConfigs=realloc((config *)(*vConfigs),((*n)+1)*sizeof(config));

                token=strtok(linea,"-");
                strcpy((*vConfigs)[*n].config,token);

                token=strtok(NULL,"\n");
                (*vConfigs)[*n].valor=atoi(token);

                (*n)++;

            }

        }while(!feof(fichero));
    }

    fclose(fichero);

    return 0;
}
