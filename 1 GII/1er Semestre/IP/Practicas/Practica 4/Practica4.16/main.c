#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c[100];
    int caracter,i;
    puts("Introduce una palabra o frase:");
    do
    {
        gets(c);
    }while (c!='EOF');
    caracter=0;
    i=0;
    while (c[i]!='.'||c[i]!='\0'){
        caracter=caracter+1;
        i++;
}
    printf("La palabra o frase tiene una longitud de %d caracteres",caracter);
    return 0;
}
