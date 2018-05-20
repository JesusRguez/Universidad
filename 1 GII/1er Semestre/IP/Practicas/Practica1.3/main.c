#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    int entero;
    float decimal;
    double real;

    printf("Escriba la constante tipo char:");
    scanf("\n%c",&letra);
    printf("Escriba la constante tipo int:");
    scanf("\n%i",&entero);
    printf("Escriba la constante tipo float:");
    scanf("\n%f",&decimal);
    printf("Escriba la constante tipo double:");
    scanf("\n%lf",&real);

    printf("\n%c", letra);
    printf("\n%i", entero);
    printf("\n%f", decimal);
    printf("\n%lf", real);

    return 0;
}
