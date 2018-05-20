#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Introduce un numero para evaluar si es par o impar:");
    scanf("%d",&a);
    if (a%2==0)
        printf("El numero es par.");
    else
        printf("El numero es impar.");
    return 0;
}
