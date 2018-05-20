#include <stdio.h>
#include <stdlib.h>

int cifras (int);

int main()
{
    int a,n;
    puts("Introduce un numero entero para calcular sus cifras:");
    scanf("%d",&a);

    n=cifras(a);

    printf("El numero tiene %d cifras",n);

    return 0;
}

//Cabecera: int cifras (int)
//Precondición: la variable a debe estar inicializada
//Postcondición: Devuelve el numero de cifras de a
int cifras(a)
{
    if (a==0)
        return 0;
    else
        return 1 + cifras(a/10);
}
