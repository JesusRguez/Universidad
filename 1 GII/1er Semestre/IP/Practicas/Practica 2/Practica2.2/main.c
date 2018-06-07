#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, aux1, aux2;
    printf("Introduzca el primer numero:");
    scanf("%d",&a);
    printf("Introduzca el segundo numero:");
    scanf("%d",&b);
    printf("Introduzca el tercer numero:");
    scanf("%d",&c);

    if (a>b)
    {
        aux1=a;
        a=b;
        b=aux1;
    }
    if (b>c)
    {
        aux2=b;
        b=c;
        c=aux2;

        if (a>b)
    {
        aux1=a;
        a=b;
        b=aux1;
    }
    }

    printf("El mayor numero introducido es: %d",c);
    printf("\nEl menor numero introducido es: %d",a);

    return 0;
}
