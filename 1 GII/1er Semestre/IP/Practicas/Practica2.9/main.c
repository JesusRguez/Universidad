#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
float a, b, c, aux1, aux2, r1, r2;
    printf("Introduzca el primer numero:");
    scanf("%f",&a);
    printf("Introduzca el segundo numero:");
    scanf("%f",&b);
    printf("Introduzca el tercer numero:");
    scanf("%f",&c);

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
    r1=pow(b,3);
    r2=pow(c,3);

    printf("El cubo del segundo valor mas grande es %.2f y la del valor mas grande es %.2f",r1,r2);

    return 0;
}
