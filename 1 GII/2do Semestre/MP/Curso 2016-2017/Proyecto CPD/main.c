#include <stdio.h>
#include <stdlib.h>
#include "ficheros.h"
#include "administrador.h"
#include "profesor.h"

int main()
{
    char respuesta;

    volcar_memoria();   //Llamada a la función volcar_memoria() para realizar la copia de los ficheros en memoria principal.

    do{

    system("cls");
    puts("Bienvenido al CPD:");

    acceso(v_usuarios, n_act_usuarios);           //Llamada a la función acceso() para elegir que tipo de usuario se introduce en el sistema.

    puts("¿Desea realizar alguna otra accion? (s/n)");
    fflush(stdin);
    scanf("%c",&respuesta);

    }while(respuesta=='s'||respuesta=='S');

    volcar_disco();     //Llamada a la función volcar_disco() para realizar la copia de la memoria principal en los ficheros.

    return 0;
}
