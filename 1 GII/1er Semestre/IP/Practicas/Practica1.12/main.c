#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

int main()
{
    float f,l,R;
    printf("Introduce el valor de la inductancia en henrios:");
    scanf("%f",&l);
    printf("Introduce el valor de la frecuencia en herzios:");
    scanf("%f",&f);
    R=2*PI*l*f;
    printf("El valor de la resistencia en ohmios es: %f",R);

    return 0;
}
