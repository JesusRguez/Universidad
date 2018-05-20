#include <stdio.h>
#include <stdlib.h>

void inicializa_v (int *,int);
void sumas (int *,int);

int main()
{
    int *a,n;

    puts("Introduzca el numero de elementos del vector:");
    scanf("%d",&n);
    a=(int *) malloc(n*sizeof(int));

    inicializa_v(a,n);

    sumas(a,n);

    return 0;
}

//Cabecera: void (int*,int)
//Precondición: Recibe la dirección de memoria del vector "a"
//Postcondición: Inicializa el vector "a"
void inicializa_v (int *a,int n)
{
    int i;

    for (i=0;i<n;i++)
    {
        printf("Introduzca el valor del elemento %d\n",i);
        scanf("%d",&a[i]);
    }

}
//Cabecera: void sumas(int*,int)
//Precondición: El vector "a" ha de estar inicializado
//Postcondición: Busca si hay dos elementos consecutivos tal que sus sumas sean idénticas
void sumas(int *a,int n)
{

    if (a[n]+a[n-1]==a[n-2]+a[n-3])
        puts("Hay dos parejeas de elementos cuya suma es idéntica");
    else
        if (n==3)
            puts("No hay dos pajeras cuya suma sea identica");
        else
            sumas(a,n-1);
}
