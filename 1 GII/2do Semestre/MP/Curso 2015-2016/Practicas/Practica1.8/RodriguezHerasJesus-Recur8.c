#include <stdio.h>
#include <stdlib.h>

void llamada(int* , int, int);
void intercambio(int* , int, int, int);

int main()
{
    int A[10]={1,4,6,6,2,6,8,4,6,5};
    int i,k, n=10;

    do      //Comprobamos que el numero introducido por el usuario sea menor o igual a la mitad de la longitud del vector
    {
    puts("Introduce el valor de K inferior o igual a 5:");
    scanf("%d",&k);
    }while (k<0 && k>5);

    llamada(A,n,k);     // Llamada a la funci�n recursiva

    printf("El vector intercambiado es:\n");

    for (i=0;i<n;i++)       //Escribe el vector en pantalla
        printf(A[i]);

    return 0;
}

//Cabecera: void llamada(int* ,int)
//Precondici�n: El vector y su longiutud han de estar inicializados
//Postcondici�n: LLama a la funci�n recursiva
void llamada (int* A, int n, int k)
{
    intercambio(A,n,k,0);       //Llama a la funci�n recursiva
}

//Cabecera: void intercambio((int* ,int, int, int, int)
//Precondici�n: El vector y su longitud han de estar inicializados
//Postcondici�n: Devuelve el vector cambiando los k primeros valores por los k ultimos
void intercambio(int* A, int n, int k, int i)
{
    int aux;

    if (i<k){
        aux=A[i];
        A[i]=A[n-k+i];
        A[n-k+i]=A[i];
        intercambio(A,n,k,i+1);
    }
}
