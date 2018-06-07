#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034

int main()
{
    float radio;
    float longitud;
    float area;
    float volumen;

    printf("Introduzca el valor del radio en metros:");
    scanf("%f",&radio);

    longitud=2*PI*radio;
    area=2*PI*(radio*radio);
    volumen=(float)4/3*PI*(radio*radio*radio);

    printf("\nLa longitud de la circunferencia es: %f metros.",longitud);
    printf("\n\nEl area del circulo es: %f metros cuadrados.",area);
    printf("\n\nEl volumen de la esfera es: %f metros cubicos.",volumen);

    return 0;
}
