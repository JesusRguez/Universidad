#include <stdio.h>
#include <stdlib.h>

#include "Palabra.h"
#include "Texto.h"
#include "Permutaciones.h"

int main() {
    char s[100];
    texto txt;
    
    printf("-------------------ANAGRAMA-------------------\n\n");
    printf("Indicar nombre del fichero (con extension): ");
    gets(s);
    txt= abrir_texto(s);
    
    printf("El numero de permutaciones es: %d\n",cuenta_permutaciones(txt));
    cerrar_texto(txt);
    
    system("PAUSE");
    return 0;
}
