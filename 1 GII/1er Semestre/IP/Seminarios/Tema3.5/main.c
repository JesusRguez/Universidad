#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,aux;
    printf("Introducir el primer numero:");
    scanf("%f",&a);
    printf("Introducir el segundo numero:");
    scanf("%f",&b);
    printf("Introducir el tercer numero:");
    scanf("%f",&c);

    if (a>b)
    {
        aux=b;
        b=a;
        a=aux;
    }
    if (b>c)
    {
        aux=c;
        c=b;
        b=aux;

    if (a>b)
    {
        aux=b;
        b=a;
        a=aux;
    }
    }
    printf("El orden es: %f < %f < %f",a,b,c);

    return 0;
}
