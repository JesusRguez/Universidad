#include <stdio.h>
#include <stdlib.h>

void inicializav(int,int);
int MODA(int,int);

int main()
{
    int *A,n,m;

    puts("Introduzca el tamaño del vector:");
    scanf("%d",&n);

    int *A=malloc(n*sizeof(int));
    inicializav(A,n);
    m=MODA(A,n);
    printf("La moda del vector es %d",m);

    return 0;
}

//Cabecera: void inicializav(int,int)
//Precondición: El vector ha de estar declarado y n inicializada
//Postcondición: Inicializa los valores del vector
void inicializav(int A,int n)
{
    int i;
    puts("Introducir los elementos del vector crecientemente:")
    for (i=0;i<n;i++)
    {
        puts("Introduzca el valor del elemento %d:",i);
        scanf("%d",A[i]);
    }
}

//Cabecera: int MODA (int,int)
//Precondición El vector y n han de estar inicializados
//Postcondición: Devuelve la moda del vector
int MODA(int A,int n)
{

}
