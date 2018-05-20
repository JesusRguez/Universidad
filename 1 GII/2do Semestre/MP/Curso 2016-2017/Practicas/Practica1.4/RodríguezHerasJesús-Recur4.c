#include <stdio.h>
#include <stdlib.h>

int llamada (int* , int);
int elemay (int* , int, int, int, int);

int main()
{
    int v[10]={1,2,3,4,5,6,7,8,9,5}; //Los datos del vector son introducidos de forma estática
    int m,n=10; //n es la longitud del vector

    m=llamada(v,n);

    if (m==-1)
        printf("No hay elemento mayoritario.");
    else
        printf("Existe el elemento mayoritario y la primera posición que ocupa es: %d",m);

    return 0;
}

//Cabecera: void llamada (int*, int)
//Precondición: El vector v y la longitud del vector "n" han de estar inicializados
//Postcondición: Llama a la función recursiva
int llamada (int *v, int n){
    return elemay(v,n,0,1,1);
}

//Cabecera: int elemay(int*, int )
//Precondición: El vector v y la longitud del vector "n" han de estar inicializados
//Postcondición: Devuelve la posición donde se encuentra el elemento mayoritario del vector v
int elemay(int *v, int n, int i, int j, int cont)
{
    if (cont>=(n/2))
        return i;
    else if(i==n/2+1)       //Comprueba que llega al siguiente elmento de la mitad del vector
    {
        return -1;
    }else
        {
        if(v[i]==v[j])
        {
            return elemay(v,n,i,j+1,cont+1);
        }else if(j==n)
        {
            return elemay(v,n,i+1,i+2,cont);
        }else
        {
            return elemay(v,n,i,j+1,cont);
        }
    }
}
