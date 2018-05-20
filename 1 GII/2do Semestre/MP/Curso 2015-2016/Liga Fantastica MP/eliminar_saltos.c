#include <stdio.h>

//CABECERA:
//PRECONDICION:
//POSTCONDICION: Elimina los saltos de linea de una cadena.

void eliminarSaltos(char *cad, int tam){

    int i;

    for(i=0;i<=tam;i++){
        if(cad[i]=='\n')
            cad[i]='\0';
    }

}
