#include <stdio.h>
#include <stdlib.h>

void inicializa_vector(int v[]);

int main()
{
    int i;
    float vector[20];
    inicializa_vector(vector);
    for (i=0;i<20;i++)
    {
        vector[i]=i/v[20];
        printf("%d",vector[i]);
    }
    return 0;
}
void inicializa_vector(int v[])
{
    int i;
    for (i=0;i<20;i++)
    {
        printf("Intoruzca el elemento %d\n",i);
        scanf("%d",&v[i]);
}
}
