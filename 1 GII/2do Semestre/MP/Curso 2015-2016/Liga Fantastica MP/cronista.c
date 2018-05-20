#include "tipos.h"
#include "cargar.h"
#include "cronista.h"
#include "menus.h"
#include "admin.h"

void valorarEquipos(futbolista **vFutbolistas,int nFutbolistas,equipo *vEquipos,int nEquipos){

    int i;
    int e;              //Indice del equipo seleccionado
    int f;

    char ideq[3]="";
    char idfut[3]="";
    int val=0;

    printf("Seleccione el ID del equipo a valorar (0 para volver a menu cronista): ");
    scanf("%2s",ideq);

    if(strcmp(ideq,"0")==0){

        menuCronista();

    }else{

        for(i=0;i<nEquipos;i++){                    //Busca el indice del equipo con el ID introducido y lo guarda en "e"

            if(strcmp(vEquipos[i].id,ideq)==0)

                e=i;

        }

        while(strcmp(idfut,"0")!=0){

            printf("------------------%s----------------------\n",vEquipos[e].nombre);

            for(i=0;i<nFutbolistas;i++){                //Imprime los futbolistas que esten en el equipo introducido

                if(strcmp((*vFutbolistas)[i].ideq,vEquipos[e].id)==0)

                    printf("%s %s\n",(*vFutbolistas)[i].id,(*vFutbolistas)[i].nombre);

            }

            puts("------------------------------------------------\n");

            printf("Introduzca el ID del futbolista a valorar (0 para volver a menu cronista): ");
            scanf("%2s",idfut);

            if(strcmp(idfut,"0")!=0){

                for(i=0;i<nFutbolistas;i++){

                    if(strcmp((*vFutbolistas)[i].id,idfut)==0)
                        f=i;

                }

                do{

                    if(val<0 || val>10)
                        puts("ERROR: La valoracion debe estar entre 0 y 10");

                    printf("La valoracion actual de %s es %d\n",(*vFutbolistas)[f].nombre,(*vFutbolistas)[f].valor);

                    printf("Introduzca la nueva valoracion de %s (0-10): ",(*vFutbolistas)[f].nombre);
                    scanf("%d",&val);

                }while(val<0 || val>10);

                //----Aqui se actualiza la valoracion de una plantilla segun la nueva valoracion del futbolista-----

                    actualizarPlantillas(vJugplants,nJugplants,&vPlantillas,nPlantillas,idfut,val);

                //--------------------------------------------------------------------------------------------------

                (*vFutbolistas)[f].valor=val;

                printf("La nueva valoracion de %s es %d\n",(*vFutbolistas)[f].nombre,(*vFutbolistas)[f].valor);

            }

            system("pause");

            system("cls");

        }

    }

    system("pause");

}

void actualizarPlantillas(jugplant *vJugplants,int nJugplants,plantilla **vPlantillas,int nPlantillas,char *idfut,int newVal){

    int i;
    char idplant[4]="";

    for(i=0;i<nJugplants;i++){

        if(strcmp(vJugplants[i].idjug,idfut)==0)

            strcpy(idplant,vJugplants[i].idplant);

    }

    if(strcmp(idplant,"")!=0){

        for(i=0;i<nPlantillas;i++){

            if(strcmp((*vPlantillas)[i].idplant,idplant)==0)
                (*vPlantillas)[i].punt=(*vPlantillas)[i].punt+newVal;

        }

    }

}
