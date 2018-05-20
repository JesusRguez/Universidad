#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include "cargar.h"
#include "acceso.h"
#include "menus.h"

void acceso(usuario *vUsuarios,int n){

    int i;
    int existe=0;
    char login[6];
    char pass[9];

    printf("Login: ");
    fflush(stdin);
    scanf("%5s",login);

    printf("Contraseña: ");
    fflush(stdin);
    scanf("%8s",pass);

    for(i=0;i<n;i++){

        if(strcmp(vUsuarios[i].login,login)==0) {

            existe=1;

            if(strcmp(vUsuarios[i].pass,pass)==0){

                if(strcmp(vUsuarios[i].perfil,"participante")==0)
                    menuParticipante(vUsuarios[i].id);
                if(strcmp(vUsuarios[i].perfil,"cronista")==0)
                    menuCronista();
                if(strcmp(vUsuarios[i].perfil,"administrador")==0)
                    menuAdministrador();

            }else{

                puts("ERROR: Contraseña incorrecta.");

                acceso(vUsuarios,nUsuarios);

            }

        }

    }

    if(existe==0)
        puts("El usuario no esta registrado en el sistema.");

    system("pause");

}
