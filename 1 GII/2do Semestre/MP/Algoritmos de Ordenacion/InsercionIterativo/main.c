#include <stdio.h>
#include <stdlib.h>

void insercion (int *v, int n);

int main()
{
    int v[10]={7,4,1,0,2,5,8,9,6,3};
    int i, n=10;

    insercion(v,n);

    for(i=0;i<n;i++)
    {
        printf("%d",v[i]);
    }

    return 0;
}

void insercion(int *v, int n)
{
    int i,j,temp;

    for(i=1;i<n;i++)
    {
        j=i-1;
        temp=v[i];
        while(j>=0&&temp<v[j])
        {
            v[j+1]=v[j];
            j=j-1;
        }
        v[j+1]=temp;
    }
}
