// Modulo Permutaciones

#include <stdio.h>

#include "Palabra.h"
#include "Texto.h"
#include "Permutaciones.h"


// Cabecera: cuenta_permutaciones(texto txt)
// Precondición: txt inicializado
// Postcondición: devuelve el nº de palabras del texto que son anagramas de la primera palabra tras el indicador
int cuenta_permutaciones(texto txt) {
    palabra pal1,pal2;
    int num_permut=0;
    
    leer_palabra(txt,pal1);
    while(!fin_de_texto(txt)) {
        leer_palabra(txt,pal2);
        if(palabra_es_permut(pal1,pal2))
            num_permut++;
    }
    
    return num_permut;
}
