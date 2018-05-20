#include <stdio.h>
#include <stdlib.h>

int main()
{
    float s, h, p;
    printf("Introduce el numero de horas trabajadas:");
    scanf("%f",&h);
    printf("Introduce el precio de una hora de trabajo:");
    scanf("%f",&p);
    s=h*p*0.9;
    printf("El salario de dicho trabajador es: %f",s);

        return 0;
}
