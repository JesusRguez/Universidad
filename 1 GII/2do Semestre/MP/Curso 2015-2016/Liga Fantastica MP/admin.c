#include "admin.h"

void editConfig(config **vConfigs,int nConfigs){

    int i;
    int val;

    puts("\n------------------CONFIGURACION------------------");

    for(i=0;i<nConfigs;i++){
            printf("%d) %s: %d\n",i+1,(*vConfigs)[i].config,(*vConfigs)[i].valor);
    }

    puts("-------------------------------------------------");

    i=-1;

    while(i<0 || i>nConfigs){

        printf("Seleccione el numero de la opcion de configuracion que desea modificar (0 para volver a menu amdnistrador): ");
        scanf("%d",&i);

        if(i!=0){

            if(i<1 || i>nConfigs){

                printf("ERROR: La valoracion debe estar entre 1 y %d\n",nConfigs);

            }else{

                printf("El valor actual de %s es %d\n",(*vConfigs)[i-1].config,(*vConfigs)[i-1].valor);

                printf("Introduzca el nuevo valor de %s: ",(*vConfigs)[i-1].config);

                scanf("%d",&val);

                (*vConfigs)[i-1].valor=val;

                printf("El nuevo valor de %s es %d\n",(*vConfigs)[i-1].config,(*vConfigs)[i-1].valor);

            }

        }

    }

    system("pause");

}

void listarUsuarios(usuario *vUsuarios,int nUsuarios){

    int i;

    puts("\n-----------------USUARIOS-----------------\n");
    puts("ID-NOMBRE-PERFIL-LOGIN-CONTRASEÑA\n");

    for(i=0;i<nUsuarios;i++){
            printf("%s-%s-%s-%s-%s\n",vUsuarios[i].id,vUsuarios[i].nombre,vUsuarios[i].perfil,vUsuarios[i].login,vUsuarios[i].pass);
    }

    puts("------------------------------------------\n");

}

void modificarUsuario(usuario **vUsuarios,int nUsuarios){

    int i;
    int u=-1;
    char resp=' ';
    char id[3];

    int nModUsuario=0;

    usuario *modUsuario;

    modUsuario=malloc(sizeof(usuario));

    puts("MODIFICAR USUARIO");
    puts("-----------------");

    while(u == -1){

        printf("Introduzca el id del usuario que desea modificar: ");
        scanf("%2s",id);
        printf("\n");

        for(i=0;i<nUsuarios;i++){

            if(strcmp((*vUsuarios)[i].id,id)==0){

                u=i;

            }

        }

        if(u == -1){

            puts("ERROR: El usuario seleccionado no esta registrado");

        }else{

            printf("Informacion actual del usuario seleccionado: %s-%s-%s-%s-%s\n\n",(*vUsuarios)[u].id,(*vUsuarios)[u].nombre,(*vUsuarios)[u].perfil,(*vUsuarios)[u].login,(*vUsuarios)[u].pass);

            printf("Introduzca la nueva informacion del usuario respetando el formato establecido(ID-NOMBRE-PERFIL-LOGIN-CONTRASEÑA)\n\n");

            anadirUsuario(&modUsuario,&nModUsuario,1);

            while(resp!='s' && resp!='n'){

                printf("Confirmar modificar usuario? (s/n)\n");
                fflush(stdin);
                scanf("%c",&resp);

            }

            if(resp=='s'){

                (*vUsuarios)[u]=modUsuario[0];

            }else{

                printf("Se ha cancelado la modificacion del usuario\n");

            }

        }

    }

}

void anadirUsuario(usuario **vUsuarios,int *nUsuarios,int admin){

    int n;

    *vUsuarios=realloc((usuario *)(*vUsuarios),((*nUsuarios)+1)*sizeof(usuario));

    puts("Introduzca el id del usuario (2 cifras maximo):");
    fflush(stdin);
    scanf("%2s",(*vUsuarios)[*nUsuarios].id);

    puts("Introduzca el nombre completo del usuario (20 caracteres maximo):");
    fflush(stdin);
    scanf("%20s",(*vUsuarios)[*nUsuarios].nombre);


    while(n<1 || n>3){

        if(admin==1){

            puts("Seleccione el perfil del usuario:");
            puts("1) Administrador");
            puts("2) Cronista");
            puts("3) Participante");
            fflush(stdin);
            scanf("%d",&n);

        }else{

            n=3;

        }

        switch(n){

            case 1:
                strcpy((*vUsuarios)[*nUsuarios].perfil,"administrador");
                break;

            case 2:
                strcpy((*vUsuarios)[*nUsuarios].perfil,"cronista");
                break;

            case 3:
                strcpy((*vUsuarios)[*nUsuarios].perfil,"participante");
                break;

            default:
                puts("ERROR: La opcion introducida no es valida");

        }

    }

    puts("Introduzca el login del usuario (5 caracteres maximo):");
    fflush(stdin);
    scanf("%5s",(*vUsuarios)[*nUsuarios].login);

    puts("Introduzca la contraseña del usuario (8 caracteres maximo):");
    fflush(stdin);
    scanf("%8s",(*vUsuarios)[*nUsuarios].pass);

    (*nUsuarios)++;

}

void eliminarUsuario(usuario **vUsuarios,int *nUsuarios){

    int i;
    int u;
    char resp=' ';
    char id[3];

    puts("ELIMINAR USUARIO");
    puts("----------------");

    printf("Introduzca el id del usuario a eliminar: ");
    scanf("%2s",id);

    for(i=0;i<(*nUsuarios);i++){

        if(strcmp((*vUsuarios)[i].id,id)==0){

            u=i;

        }

    }

    while(resp!='s' && resp!='n'){

        printf("Se va a eliminar el siguiente usuario: %s-%s-%s-%s-%s\n",(*vUsuarios)[u].id,(*vUsuarios)[u].nombre,(*vUsuarios)[u].perfil,(*vUsuarios)[u].login,(*vUsuarios)[u].pass);
        printf("Confirmar eliminar usuario? (s/n)\n");
        fflush(stdin);
        scanf("%c",&resp);

    }

    if(resp=='s'){

        for(i=u;i+1<(*nUsuarios);i++){

            strcpy((*vUsuarios)[i].id,(*vUsuarios)[i+1].id);
            strcpy((*vUsuarios)[i].nombre,(*vUsuarios)[i+1].nombre);
            strcpy((*vUsuarios)[i].perfil,(*vUsuarios)[i+1].perfil);
            strcpy((*vUsuarios)[i].login,(*vUsuarios)[i+1].login);
            strcpy((*vUsuarios)[i].pass,(*vUsuarios)[i+1].pass);

        }

        (*nUsuarios)--;

        *vUsuarios=realloc((usuario *)(*vUsuarios),(*nUsuarios)*sizeof(usuario));

    }else{

        printf("Se ha cancelado la eliminacion del usuario\n");

    }

}

void listarEquipos(equipo *vEquipos,int nEquipos){

    int i;

    puts("\n-----------------EQUIPOS------------------\n");
    puts("ID-NOMBRE\n");

    for(i=0;i<nEquipos;i++){
            printf("%s %s\n",vEquipos[i].id,vEquipos[i].nombre);
    }

    puts("--------------------------------------------");

}

void modificarEquipo(equipo **vEquipos,int nEquipos){

    int i;
    int e=-1;
    char resp=' ';
    char id[3];

    int nModEquipo=0;

    equipo *modEquipo;

    modEquipo=malloc(sizeof(equipo));

    puts("MODIFICAR EQUIPO");
    puts("----------------");

    while(e == -1){

        printf("Introduzca el id del equipo que desea modificar: ");
        scanf("%2s",id);
        printf("\n");

        for(i=0;i<nEquipos;i++){

            if(strcmp((*vEquipos)[i].id,id)==0){

                e=i;

            }

        }

        if(e == -1){

            puts("ERROR: El usuario seleccionado no esta registrado");

        }else{

            printf("Informacion actual del equipo seleccionado: %s-%s\n\n",(*vEquipos)[e].id,(*vEquipos)[e].nombre);

            printf("Introduzca la nueva informacion del equipo respetando el formato establecido(ID-NOMBRE)\n\n");

            anadirEquipo(&modEquipo,&nModEquipo);

            while(resp!='s' && resp!='n'){

                printf("Confirmar modificar equipo? (s/n)\n");
                fflush(stdin);
                scanf("%c",&resp);

            }

            if(resp=='s'){

                (*vEquipos)[e]=modEquipo[0];

            }else{

                printf("Se ha cancelado la modificacion del equipo\n");

            }

        }

    }

}

void anadirEquipo(equipo **vEquipos,int *nEquipos){

    *vEquipos=realloc((equipo *)(*vEquipos),((*nEquipos)+1)*sizeof(equipo));

    puts("Introduzca el id del equipo (2 cifras maximo):");
    scanf("%2s",(*vEquipos)[*nEquipos].id);

    puts("Introduzca el nombre del equipo (20 caracteres maximo):");
    scanf("%20s",(*vEquipos)[*nEquipos].nombre);

    (*nEquipos)++;

}

void eliminarEquipo(equipo **vEquipos,int *nEquipos){

    int i;
    int e;
    char resp=' ';
    char id[3];

    puts("ELIMINAR EQUIPO");
    puts("---------------");

    printf("Introduzca el id del equipo a eliminar: ");
    scanf("%2s",id);

    for(i=0;i<(*nEquipos);i++){

        if(strcmp((*vEquipos)[i].id,id)==0){

            e=i;

        }

    }

    while(resp!='s' && resp!='n'){

        printf("Se va a eliminar el siguiente equipo: %s-%s\n",(*vEquipos)[e].id,(*vEquipos)[e].nombre);
        printf("Confirmar eliminar equipo? (s/n)\n");
        fflush(stdin);
        scanf("%c",&resp);

    }

    if(resp=='s'){

        for(i=e;i+1<(*nEquipos);i++){

            strcpy((*vEquipos)[i].id,(*vEquipos)[i+1].id);
            strcpy((*vEquipos)[i].nombre,(*vEquipos)[i+1].nombre);

        }

        (*nEquipos)--;

        *vEquipos=realloc((equipo *)(*vEquipos),(*nEquipos)*sizeof(equipo));

    }else{

        printf("Se ha cancelado la eliminacion del equipo\n");

    }

}

void listarFutbolistas(futbolista *vFutbolistas,int nFutbolistas){

    int i;

    puts("\n---------------FUTBOLISTAS----------------\n");
    puts("ID-ID_EQUIPO-NOMBRE-PRECIO-VALORACION\n");

    for(i=0;i<nFutbolistas;i++){
            printf("%s-%s-%s-%d-%d\n",vFutbolistas[i].id,vFutbolistas[i].ideq,vFutbolistas[i].nombre,vFutbolistas[i].precio,vFutbolistas[i].valor);
    }

    puts("--------------------------------------------");

}

void modificarFutbolista(futbolista **vFutbolistas,int nFutbolistas){

    int i;
    int f=-1;
    char resp=' ';
    char id[3];

    int nModFutbolista=0;

    futbolista *modFutbolista;

    modFutbolista=malloc(sizeof(futbolista));

    puts("MODIFICAR FUTBOLISTA");
    puts("--------------------");

    while(f == -1){

        printf("Introduzca el id del futbolsta que desea modificar: ");
        scanf("%2s",id);
        printf("\n");

        for(i=0;i<nFutbolistas;i++){

            if(strcmp((*vFutbolistas)[i].id,id)==0){

                f=i;

            }

        }

        if(f == -1){

            puts("ERROR: El futbolista seleccionado no esta registrado");

        }else{

            printf("Informacion actual del futbolista seleccionado: %s-%s-%s-%d-%d\n\n",(*vFutbolistas)[f].id,(*vFutbolistas)[f].ideq,(*vFutbolistas)[f].nombre,(*vFutbolistas)[f].precio,(*vFutbolistas)[f].valor);

            printf("Introduzca la nueva informacion del futbolista respetando el formato establecido(ID-NOMBRE)\n\n");

            anadirFutbolista(&modFutbolista,&nModFutbolista);

            while(resp!='s' && resp!='n'){

                printf("Confirmar modificar futbolista? (s/n)\n");
                fflush(stdin);
                scanf("%c",&resp);

            }

            if(resp=='s'){

                (*vFutbolistas)[f]=modFutbolista[0];

            }else{

                printf("Se ha cancelado la modificacion del futbolista\n");

            }

        }

    }

}

void anadirFutbolista(futbolista **vFutbolistas,int *nFutbolistas){

    *vFutbolistas=realloc((futbolista *)(*vFutbolistas),((*nFutbolistas)+1)*sizeof(futbolista));

    puts("Introduzca el id del futbolista (2 cifras maximo):");
    scanf("%2s",(*vFutbolistas)[*nFutbolistas].id);

    puts("Introduzca el id del equipo al que pertenece el futbolista (2 cifras maximo):");
    scanf("%2s",(*vFutbolistas)[*nFutbolistas].ideq);

    puts("Introduzca el nombre del futbolista (20 caracteres maximo):");
    scanf("%20s",(*vFutbolistas)[*nFutbolistas].nombre);

    puts("Introduzca el precio del futbolista en millones de euros (2 cifras maximo):");
    scanf("%d",&(*vFutbolistas)[*nFutbolistas].precio);

    puts("Introduzca la valoracion del futbolista (0-10):");
    scanf("%d",&(*vFutbolistas)[*nFutbolistas].valor);

    (*nFutbolistas)++;

}

void eliminarFutbolista(futbolista **vFutbolistas,int *nFutbolistas){

    int i;
    int f;
    char resp=' ';
    char id[3];

    puts("ELIMINAR FUTBOLISTA");
    puts("-------------------");

    printf("Introduzca el id del futbolista a eliminar: ");
    scanf("%2s",id);

    for(i=0;i<(*nFutbolistas);i++){

        if(strcmp((*vFutbolistas)[i].id,id)==0){

            f=i;

        }

    }

    while(resp!='s' && resp!='n'){

        printf("Se va a eliminar el siguiente usuario: %s-%s-%s-%d-%d\n",(*vFutbolistas)[f].id,(*vFutbolistas)[f].nombre,(*vFutbolistas)[f].nombre,(*vFutbolistas)[f].precio,(*vFutbolistas)[f].valor);
        printf("Confirmar eliminar usuario? (s/n)\n");
        fflush(stdin);
        scanf("%c",&resp);

    }

    if(resp=='s'){

        for(i=f;i+1<(*nFutbolistas);i++){

            strcpy((*vFutbolistas)[i].id,(*vFutbolistas)[i+1].id);
            strcpy((*vFutbolistas)[i].ideq,(*vFutbolistas)[i+1].ideq);
            strcpy((*vFutbolistas)[i].nombre,(*vFutbolistas)[i+1].nombre);
            (*vFutbolistas)[i].precio=(*vFutbolistas)[i+1].precio;
            (*vFutbolistas)[i].valor=(*vFutbolistas)[i+1].valor;

        }

        (*nFutbolistas)--;

        *vFutbolistas=realloc((futbolista *)(*vFutbolistas),(*nFutbolistas)*sizeof(futbolista));

    }else{

        printf("Se ha cancelado la eliminacion del usuario\n");

    }
}
