#include <stdio.h>
#include <stdlib.h>

int llamada_burbuja (int *v, int n);
int burbuja_rec (int *v, int n, int i, int j);

int main()
{
    int v[10]={7,4,1,0,2,5,8,9,6,3};
    int w[10];
    int i, n=10;

    *v=llamada_burbuja(v,n);

    for(i=0;i<n;i++)
    {
        printf("%d",v[i]);
    }

    return 0;
}

int llamada_burbuja(int *v, int n)
{
    return burbuja_rec(v,n,n,0);
}

int burbuja_rec(int *v, int n, int i, int j)
{
    int aux;

    if(i==0)
        return *v;
    else
    {
        if(j==i)
        {
            return burbuja_rec(v,n,i-1,0);
        }
        else
        {
            if(v[j]>v[j+1])
            {
                aux=v[j+1];
                v[j+1]=v[j];
                v[j]=aux;
                return burbuja_rec(v,n,i,j+1);
            }
            else
                return burbuja_rec(v,n,i,j+1);
        }
    }
}
