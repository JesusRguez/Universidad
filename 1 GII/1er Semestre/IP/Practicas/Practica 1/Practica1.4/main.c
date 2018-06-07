#include <stdio.h>
#include <stdlib.h>

char letra;
char letra2;
int codigo;
int ascii;
int asciisig;

int main()
{
    printf("Escriba un caracter:");
    scanf("%c",&letra);
    ascii=letra;
    printf("El codigo ASCII de dicho caracter es: %d",ascii);
    asciisig=ascii+1;
    letra2=asciisig;
    printf("\nEl caracter con el codigo ASCII %d es: %c",asciisig, letra2);

    return 0;
}
