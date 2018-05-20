#include <stdio.h>
#include <stdlib.h>

int llamada_seleccion (int *v, int n);
int seleccion_rec (int *v, int n, int i, int j, int min);

int main()
{
    int v[10]={7,4,1,0,2,5,8,9,6,3};

    int i, n=10;

    *v=llamada_seleccion(v,n);

    for(i=0;i<n;i++)
    {
        printf("%d",v[i]);
    }

    return 0;
}

int llamada_seleccion(int *v, int n)
{
    return seleccion_rec(v,n,0,1,0);
}

int seleccion_rec(int *v, int n, int i, int j, int min)
{

    int aux;
    if(i>=n)
        return *v;
    else
    {
        if (j>=n)
        {
            aux=v[i];
            v[i]=v[min];
            v[min]=aux;
            return seleccion_rec(v,n,i+1,i+2,i+1);
        }
        else
        {
            if(v[j]<v[min])
            {
                min=j;
                return seleccion_rec(v,n,i,j+1,min);
            }
            else
            {
                return seleccion_rec(v,n,i,j+1,min);
            }
        }
    }
}
