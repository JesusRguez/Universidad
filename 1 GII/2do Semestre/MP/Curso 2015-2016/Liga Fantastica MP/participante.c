#include "participante.h"
#include "admin.h"


void contarPlantillas(char *id,plantilla *vPlantillas,int nPlantillas,int *nPlantillasUsuario){

    int i;

    *nPlantillasUsuario=0;

    for(i=0;i<nPlantillas;i++){

        if(strcmp(vPlantillas[i].idprop,id)==0){

            (*nPlantillasUsuario)++;

        }

    }

}

void crearPlantilla(char *id,plantilla **vPlantillas,int *nPlantillas,jugplant **vJugplants,int *nJugplants,int *nPlantillasUsuario){

    if(*nPlantillasUsuario<vConfigs[0].valor){

        *vPlantillas=realloc((plantilla *)(*vPlantillas),((*nPlantillas)+1)*sizeof(plantilla));

        puts("Introduzca el id de la plantilla (3 cifras maximo):");
        fflush(stdin);
        scanf("%3s",(*vPlantillas)[*nPlantillas].idplant);

        puts("Introduzca el nombre completo de la plantilla (30 caracteres maximo):");
        fflush(stdin);
        //scanf("%30s",(*vPlantillas)[*nPlantillas].nombre);
        fgets((*vPlantillas)[*nPlantillas].nombre,31,stdin);
        eliminarSaltos((*vPlantillas)[*nPlantillas].nombre,31);

        strcpy((*vPlantillas)[*nPlantillas].idprop,id);

        (*vPlantillas)[*nPlantillas].presup=vConfigs[1].valor;

        (*vPlantillas)[*nPlantillas].punt=0;

        (*nPlantillas)++;
        (*nPlantillasUsuario)++;

    }else{

        puts("Ha alcanzado el limite de plantillas. No puede crear nuevas plantillas.");

    }

}

void listarplantillas(char *id, plantilla*vPlantillas, int nPlantillas, int nPlantillasUsuario){

    int i;

    if( nPlantillasUsuario == 0)
        printf("No tienes plantillas registradas \n");
    else
        for(i=0;i<nPlantillas;i++){
            if(strcmp(vPlantillas[i].idprop,id) == 0)
                printf("%s-%s-%s-%d-%d\n",vPlantillas[i].idprop,vPlantillas[i].idplant,vPlantillas[i].nombre,vPlantillas[i].presup,vPlantillas[i].punt);
        }

}

void eliminarPlantilla(char *id, plantilla **vPlantillas, int *nPlantillas, int *nPlantillasUsuario){

    int i;
    int p;
    char resp=' ';
    char idplant[4];

    printf("Introduzca el id de la plantilla a eliminar: ");
    scanf("%3s",idplant);

    if( nPlantillasUsuario == 0){

        printf("No tienes plantillas registradas\n");

    }else{

        for(i=0;i<(*nPlantillas);i++){

            if(strcmp((*vPlantillas)[i].idplant,idplant)==0){

                p=i;

            }

        }

        while(resp!='s' && resp!='n'){

            printf("Se va a eliminar la siguiente plantilla: %s-%s-%s-%d-%d\n",(*vPlantillas)[p].idprop,(*vPlantillas)[p].idplant,(*vPlantillas)[p].nombre,(*vPlantillas)[p].presup,(*vPlantillas)[p].punt);
            printf("Confirmar eliminar plantilla? (s/n)\n");
            fflush(stdin);
            scanf("%c",&resp);

        }

        if(resp=='s'){

            for(i=p;i+1<(*nPlantillas);i++){

                strcpy((*vPlantillas)[i].idprop,(*vPlantillas)[i+1].idprop);
                strcpy((*vPlantillas)[i].idplant,(*vPlantillas)[i+1].idplant);
                strcpy((*vPlantillas)[i].nombre,(*vPlantillas)[i+1].nombre);
                (*vPlantillas)[i].presup=(*vPlantillas)[i+1].presup;
                (*vPlantillas)[i].punt=(*vPlantillas)[i+1].punt;

            }

            (*nPlantillas)--;
            (*nPlantillasUsuario)--;

            *vPlantillas=realloc((plantilla *)(*vPlantillas),(*nPlantillas)*sizeof(plantilla));

        }else{

            printf("Se ha cancelado la eliminacion de la plantilla\n");

        }
    }

}

void ranking(plantilla *vPlantillas, int nPlantillas){
    int i;
    int top[3]={0,0,0},ind[3]={0,0,0};

    for(i=0;i<nPlantillas;i++)
    {
        if(vPlantillas[i].punt>=top[0])
        {
            top[2]=top[1];
            top[1]=top[0];
            top[0]=vPlantillas[i].punt;

            ind[2]=ind[1];
            ind[1]=ind[0];
            ind[0]=i;
        }
        else
        {
            if(vPlantillas[i].punt>=top[1])
            {
                top[2]=top[1];
                top[1]=vPlantillas[i].punt;

                ind[2]=ind[1];
                ind[1]=i;
            }
            else
            {
                if(vPlantillas[i].punt>=top[2])
                {
                    top[2]=vPlantillas[i].punt;

                    ind[2]=i;
                }
            }
        }
    }


    printf("1) %s-%s-%s-%d-%d\n",vPlantillas[ind[0]].idprop,vPlantillas[ind[0]].idplant,vPlantillas[ind[0]].nombre,vPlantillas[ind[0]].presup,vPlantillas[ind[0]].punt);
    printf("2) %s-%s-%s-%d-%d\n",vPlantillas[ind[1]].idprop,vPlantillas[ind[1]].idplant,vPlantillas[ind[1]].nombre,vPlantillas[ind[1]].presup,vPlantillas[ind[1]].punt);
    printf("3) %s-%s-%s-%d-%d\n",vPlantillas[ind[2]].idprop,vPlantillas[ind[2]].idplant,vPlantillas[ind[2]].nombre,vPlantillas[ind[2]].presup,vPlantillas[ind[2]].punt);

}
