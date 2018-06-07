#include <stdio.h>
#include <stdlib.h>

int main()
{
    float g, f;
    printf("Introduce el valor de la temperatura en grados Celsius para obtener su valor en grados Fahrenheit:");
    scanf("%f",&g);
    f=(9/5)*g+32;
    printf("La temperatura en grados Celsius es: %f",f);

    return 0;
}
