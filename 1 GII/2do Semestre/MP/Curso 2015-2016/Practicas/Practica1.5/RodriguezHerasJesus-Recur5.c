#include <stdio.h>
#include <stdlib.h>

int conj(int n,int k);

int main()
{
    int m,n,k;
    puts("Introduce el numero de personas:");
    scanf("%d",&n); //Se introduce en la variable n el numero de personas deseado
    puts("Introduce el numero maximo de personas por grupo");
    scanf("%d",&k); //Se introduce en la variable k el numero de grupos deseados

    m=conj(n,k);    //Se introduce en la variable m el numero posible de grupos que se pueden formar con el numero de personas introducidas en sendos grupos

    printf("Se pueden hacer %d grupos",m);

    return 0;
}

//Cabecera: int conj(int,int);
//Precondición: n y k han de estar inicializados
//Postcondición: Devuelve el numero maximo de personas por grupo
int conj(int n, int k)
{
    if (k==1)
        return n;   //Si el  número de grupos es 1, se devuelve el numero de personas máximo
    else
        if (n==k)
            return 1; //Si el numero de personas es igual al numero de grupos, se devuelve 1 (una persona por grupo)
        else
            return conj(n-1,k) + conj(n-1,k-1);
}
