#include <stdio.h>
#include <stdlib.h>

int llamada (int* , int);
int elemay (int* , int, int, int, int);

int main()
{
    int A[10]={1,4,6,6,2,6,8,4,6,5}; //Los datos del vector son introducidos de forma estática
    int may,n=10; //n es la longitud del vector

    may=llamada(A,n);

    if (may==0)
        printf("No hay elemento mayoritario.");
    else
        printf("Existe el elemento mayoritario y la primera posición que ocupa es: %d",may);

    return 0;
}

//Cabecera: void llamada (int*, int)
//Precondición: El vector A y la longitud del vector "n" han de estar inicializados
//Postcondición: Llama a la función recursiva
int llamada (int *A, int n){
    return elemay(A,n,0,0,1);
}

//Cabecera: int elemay(int *, int )
//Precondición: El vector A y la longitud del vector "n" han de estar inicializados
//Postcondición: Devuelve la moda del vector
int elemay(int *A, int n, int posactual, int posicion, int cont)
{
    if (cont!=(n/2))
        return 0;
    else
        if (posactua<n)
}
