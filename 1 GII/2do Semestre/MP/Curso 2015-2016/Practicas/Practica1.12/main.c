#include <stdio.h>
#include <stdlib.h>

void llamada (int*, int);
void compara (int*, int, int, int, int, int);

int main()
{
    int A[10]={1,2,4,6,5,7,8,9,4,3};
    int n=10;

    llamada(A,n);

    return 0;
}

//Cabecera: void llamada (int*, int)
//Precoondición: Tanto el vector A como n han de estar inicializadas
//Postcodiión: Llama a la función recursiva
void llamada (int* A, int n)
{
    compara(A,n,0,1,A[0],A[1]);       //Decalaramos j y k como contadores del vector y los implementamos en la función recursiva
}

//Cabecera: void compara(int*, int, int, int,int,int)
//Preconcidión: Tanto el vector como n e j y k han de estar inicializados
//Postcondición: Dice si hay o no hay una pareja tal que desde 0 hasta j sume lo mismno que desde k hasta n
void compara(int* A, int n, int j, int k, int suma1,int suma2)
{

    if (suma1!=suma2)
        compara(A,n,j,k+1,suma1+A[j+1],suma2+A[k+1]);





}
