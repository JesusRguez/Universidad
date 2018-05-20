#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c, x1, x2;
    printf("Introduce el valor de a:");
    scanf("%f",&a);
    printf("Introducir el valor de b:");
    scanf("%f",&b);
    printf("Introducir el valor de c:");
    scanf("%f",&c);

    x1=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
    x2=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);

    if ((pow(b,2)-4*a*c)<0)
    {
        printf("No se puede realizar la operacion porque la raiz cuadrada es negativa.");
    }

    printf("El valor del primer resultado es: %f",x1);
    printf("\nEl valor del segundo resultado es: %f",x2);

    return 0;
}
