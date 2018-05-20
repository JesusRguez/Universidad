#include "confPlant.h"
void listarFutbPlant(char *idPlant, jugplant *vJugplants, int nJugplants)
{
    int i;
    for(i=0;i<nJugplants;i++)

    if(strcmp(vJugplants[i].idplant,idPlant) == 0)
        printf("%s-%s-%s\n", vJugplants[i].idjug, vJugplants[i].ideq, vJugplants[i].idplant);
}

int esFutbTitular(char * idFutb, jugplant *vJugplants, int nJugplants )
{
    int i;

    for(i=0;i<nJugplants;i++)

        if( strcmp(vJugplants[i].idjug, idFutb) == 0 )
            return 1;

    return 0;

}

void listarFutbDisp(char *idPlant, jugplant *vJugplants, int nJugplants, futbolista *vFutbolistas , int nFutbolistas)
{
    int i;
    for(i=0;i<nFutbolistas;i++)

        if( !esFutbTitular(vFutbolistas[i].id, vJugplants, nJugplants) )
            printf("%s-%s-%s-%d-%d\n", vFutbolistas[i].id, vFutbolistas[i].ideq, vFutbolistas[i].nombre, vFutbolistas[i].precio, vFutbolistas[i].valor);
}

void ficharFutb(char *idPlant, jugplant **vJugplants, int *nJugplants, futbolista *vFutbolistas , int nFutbolistas)
{
    int i;
    char ideq[3], idFutb[3];

    puts("introduce el id de un jugador a fichar: ");
    fflush(stdin);
    scanf("%2s",idFutb);

    (*nJugplants)++;
    *vJugplants=realloc((jugplant *)(*vJugplants),(*nJugplants)*sizeof(jugplant));

    for(i=0;i<nFutbolistas;i++)

        if( strcmp(vFutbolistas[i].id, idFutb) == 0 )
            strcpy(ideq, vFutbolistas[i].ideq);

    strcpy( (*vJugplants)[(*nJugplants) - 1].idjug, idFutb);
    strcpy( (*vJugplants)[(*nJugplants) - 1].ideq, ideq);
    strcpy( (*vJugplants)[(*nJugplants) - 1].idplant, idPlant);

}

void despedirFutb(char *idPlant, jugplant **vJugplants, int *nJugplants, futbolista *vFutbolistas , int nFutbolistas)
{
    int i = 0;
    char idFutb[3], resp=' ';

    puts("introduce el id de un jugador a despedir: ");
    fflush(stdin);
    scanf("%2s",idFutb);

    while( (strcmp((*vJugplants)[i].idjug, idFutb) != 0 || strcmp((*vJugplants)[i].idplant, idPlant) != 0) && i <(*nJugplants) )
        i++;


    while(resp!='s' && resp!='n'){

            printf("Se va a eliminar el jugador con id %s de la plantilla %s", idFutb, idPlant);
            printf("Confirmar eliminar jugador de la plantilla? (s/n)\n");
            fflush(stdin);
            scanf("%c",&resp);

        }

        if(resp=='s')
        {

            for(;i+1<(*nJugplants);i++)
            {

                strcpy( (*vJugplants)[i].idjug,(*vJugplants)[i+1].idjug );
                strcpy((*vJugplants)[i].ideq,(*vJugplants)[i+1].ideq);
                strcpy((*vJugplants)[i].idplant,(*vJugplants)[i+1].idplant);
            }

            (*nJugplants)--;
            *vJugplants=realloc((jugplant *)(*vJugplants),(*nJugplants)*sizeof(jugplant));

        }
        else
        {

            printf("Se ha cancelado la eliminacion del jugador de la plantilla\n");

        }

}


