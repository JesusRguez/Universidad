#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, s, r, m, d, D;
    printf("Introduce el valor de a:");
    scanf("%f",&a);
    printf("Introduce el valor de b:");
    scanf("%f",&b);
    s=a+b;
    r=a-b;
    m=a*b;
    d=a/b;
    D=(int)a%(int)b;
    printf("La suma de a mas b es: %f",s);
    printf("\nLa resta de a menos b es: %f",r);
    printf("\nEl producto de a y b es: %f",m);
    printf("\nEl cociente de a entre b es: %.2f",d);
    printf("\nEl modulo (resto) de a y b es: %f",D);


    return 0;
}
