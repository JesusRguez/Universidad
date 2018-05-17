#include <stdio.h>
#include <stdlib.h>

int main()
{
    int caracter;
    char c;
    printf("Introduzca un numero y pulse f y luego ENTER para contabilizar los caracteres:");
    caracter=0;
    do
    {
    c=getchar();
    caracter=caracter+1;
    }
    while (c!='f');
    caracter=caracter-1;
    printf("Ha escrito %d caracteres.",caracter);
    return 0;
}
