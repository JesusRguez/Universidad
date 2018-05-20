#include <stdio.h>
#include <stdlib.h>

int main()
{
    int caracter,palabra,linea;
    char c;
    printf("Introduzca una oracion y finalicela con 0 mas ENTER:");
    caracter=0;
    palabra=1;
    linea=1;
    do
    {
    c=getchar();
    putchar(c);
    caracter=caracter+1;
    if (c==' '){
        palabra=palabra+1;
    }
    if (c=='\n'){
        linea=linea+1;
    }
    }
    while (c!='0');
    caracter=caracter-1;
    printf("\nEl numero de caracteres es %d",caracter);
    printf("\nEl numero de palabras es %d",palabra);
    printf("\nEl numero de lineas es %d",linea);

    return 0;
}
