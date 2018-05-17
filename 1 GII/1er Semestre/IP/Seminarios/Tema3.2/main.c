#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, aux, s, r, p, d;

    printf("Introduce el primer numero:");
    scanf("%f",&a);
    printf("Introduce el segundo numero:");
    scanf("%f",&b);
    if (a<b)
    {
        aux=a;
        a=b;
        b=aux;
    }
    s=a+b;
    r=a-b;
    p=a*b;
    d=a/b;

    printf("La suma es: %f",s);
    printf("\nLa resta es: %f",r);
    printf("\nEl producto es: %f",p);
    printf("\nLa division es: %.2f",d);

    return 0;
}
