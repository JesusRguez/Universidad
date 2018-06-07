#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont;
    char c;
    printf("Introduzca una oracion:");
    cont=0;
    do
    {
    c=getchar();
    putchar(c);
    cont=cont+1;
    }
    while (c!='0');
    printf("\nEl numero de caracteres es %d",cont);

    return 0;
}
