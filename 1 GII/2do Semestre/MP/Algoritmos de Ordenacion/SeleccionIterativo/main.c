#include <stdio.h>
#include <stdlib.h>

void seleccion (int *v, int n);

int main()
{
    int v[10]={7,4,1,0,2,5,8,9,6,3};
    int i, n=10;

    seleccion(v,n);

    for(i=0;i<n;i++)
    {
        printf("%d",v[i]);
    }

    return 0;
}

void seleccion(int *v, int n)
{
    int i,j,i_min,temp;

    for(i=0;i<=n-1;i++)
    {
        i_min=i;
        for(j=i+1;j<=n;j++)
        {
            if(v[j]<v[i_min])
            {
                i_min=j;
            }
        }
        if(i!=i_min)
        {
            temp=v[i];
            v[i]=v[i_min];
            v[i_min]=temp;
        }
    }
}
