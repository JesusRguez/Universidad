#include <stdio.h>
#include <stdlib.h>

void burbuja (int *v, int n);

int main()
{
    int v[10]={7,4,1,0,2,5,8,9,6,3};
    int i, n=10;

    burbuja(v,n);

    for(i=0;i<n;i++)
    {
        printf("%d",v[i]);
    }

    return 0;
}

void burbuja(int *v, int n)
{
    int i,j,aux;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(v[j]>v[j+1])
            {
                aux=v[j+1];
                v[j+1]=v[j];
                v[j]=aux;
            }
        }
    }
}
