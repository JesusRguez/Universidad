#include <stdio.h>
#include <stdlib.h>

int llamada_insercion (int *v, int n);
int insercion_rec (int *v, int n, int i, int j, int sel);

int main()
{
    int v[10]={7,4,1,0,2,5,8,9,6,3};

    int i, n=10;

    *v=llamada_insercion(v,n);

    for(i=0;i<n;i++)
    {
        printf("%d",v[i]);
    }
    return 0;
}

int llamada_insercion(int *v, int n)
{
    return insercion_rec(v,n,1,0,v[1]);
}

int insercion_rec(int *v, int n, int i, int j, int sel)
{
    int r;

    if(i==n)
        return *v;
    else
    {
        if(sel<v[j] && j>=0)
        {
            v[j+1]=v[j];
            return insercion_rec(v,n,i,j-1,sel);
        }
        else
        {
            v[j+1]=sel;
            return insercion_rec(v,n,i+1,i,v[i+1]);
        }
    }
}
