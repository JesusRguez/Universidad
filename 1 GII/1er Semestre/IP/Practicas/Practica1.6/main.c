#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{
    float a, b, c, d, x, resultado;
    printf("Para resolver un polinomio de grado 3 siga las siguientes instrucciones:");
    printf("\nIntroduce el valor de a:");
    scanf("%f",&a);
    printf("Introduce el valor de b:");
    scanf("%f",&b);
    printf("Introduce el valor de c:");
    scanf("%f",&c);
    printf("Introduce el valor de x:");
    scanf("%f",&x);
    resultado=a*pow(x,3)+b*pow(x,2)+c*x+d;
    printf("El resultado de dicho polinomio es: %f",resultado);

    return 0;
}
