#include <stdio.h>
#include <stdlib.h>

int contador (int);

int main()
{
    int n,x;
    printf("Introduce un numero entero para contar las cifras:");
    scanf("%d",&n);
    x=contador(n);
    printf("El numero tiene %d cifras",x);
    return 0;
}
//Cabecera: int contador (int n)
//Precondición: La variable n debe estar inicializada en la función principal
//Postcondición: Devuelve el número de cifras
int contador (int n)
{
    int i,cont;
    cont=0;
    while (n>0)
    {
        n=n/10;
        cont=cont+1;
    }
    return (cont);
}
