#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a;
    printf("Introduzca un número para evaluar si es positivo, negativo o nulo:");
    scanf("%f",&a);
    if (a==0)
    {
        printf("El numero es nulo.");
    }
    else
        if (a>0)
     {
         printf("El numero es positivo.");
     }

    if (a<0)
        printf("El numero es negativo.");


return 0;
}
