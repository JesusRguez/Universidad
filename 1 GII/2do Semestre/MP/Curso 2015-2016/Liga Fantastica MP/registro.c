#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include "cargar.h"
#include "registro.h"

void registro(usuario **vUsuarios,int *n){

    puts("REGISTRO DE USUARIO NUEVO");
    puts("-------------------------");

    puts("Introduzca el id del usuario (2 caracteres maximo):");
    fflush(stdin);
    scanf("%2s",(*vUsuarios)[*n].id);

    puts("Introduzca el nombre completo del usuario (20 caracteres maximo):");
    fflush(stdin);
    scanf("%20s",(*vUsuarios)[*n].nombre);

    puts("Introduzca el login del usuario (5 caracteres maximo):");
    fflush(stdin);
    scanf("%5s",(*vUsuarios)[*n].login);

    puts("Introduzca la contraseña del usuario (8 caracteres maximo):");
    fflush(stdin);
    scanf("%8s",(*vUsuarios)[*n].pass);

    strcpy((*vUsuarios)[*n].perfil,"participante");

    (*n)++;

}
