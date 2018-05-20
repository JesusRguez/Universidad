#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x1, x2, y1, y2, d;
    printf("Para averiguar la distancia euclidea de dos puntos del plano introduzca los siguientes valores:");
    printf("\nValor de x1:");
    scanf("%f",&x1);
    printf("Valor de x2:");
    scanf("%f",&x2);
    printf("Valor de y1:");
    scanf("%f",&y1);
    printf("Valor de y2:");
    scanf("%f",&y2);
    d=sqrt((pow((x2-x1),2))+(pow((y2-y1),2)));
    printf("La distancia euclidea de dichos puntos es: %.3f",d);

    return 0;
}
