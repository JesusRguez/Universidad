#include <stdio.h>
#include <stdlib.h>

typedef char T;
const T fin = '#';

using namespace std;

void llamada_ordenacion (int *v, int n);
void ordenacion_rec(int *v, int derecha, int izquierda);


int main()
{
    int v[10]={7,4,1,0,2,5,8,9,6,3};
    int i, n=10;

    llamada_ordenacion(v,n);

    for(i=0;i<n;i++)
    {
        printf("%d",v[i]);
    }

    return 0;
}

void llamada_ordenacion(int *v, int n)
{
    ordenacion_rec(v,n,0);
}

void ordenacion_rec(int *v, int derecha, int izquierda)
{
    int i,j,central,pivote,aux;

    i=izquierda;
    j=derecha;
    central=(i+j)/2;
    pivote=v[central];

    while(i<=j)
    {
        while(v[j]>pivote)
        {
            j--;
        }
        while(v[i]<pivote)
        {
            i++;
        }
        if(i<=j)
        {
            aux=v[j];
            v[j]=v[i];
            v[i]=aux;
            i++;
            j--;
        }
    }
    if(izquierda<j)
        ordenacion_rec(v,j,izquierda);
    if(derecha>i)
        ordenacion_rec(v,derecha,i);
}
