#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,f,cont;
    printf("Introduce el numero entero positivo:");
    scanf("%d",&a);
    f=1;
    cont=1;
    while (a<0){
        printf("Introduzca solo numeros positivos. Introduzca un numero entero positivo:");
        scanf("%d",&a);
    }

    if (a>0)
    {
        do
        {
            f=f*cont;
            cont=cont+1;
        }
        while (cont<=a);
        printf("El resultado es: %d",f);
    }
    else
        printf("El resultado es: %d",f);

    return 0;
}
