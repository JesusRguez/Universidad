#include <stdio.h>
#include <stdlib.h>

void numero_elementos (int v[]);
void inicializa_vector (int v[]);

int main()
{
    int vector [10];
    inicializa_vector(vector);
    numero_elementos(vector);
    return 0;
}
void inicializa_vector(int v[])
{
    int i;
    for (i=0;i<10;i++)
    {
        printf("Intoruzca el elemento %d\n",i);
        scanf("%d",&v[i]);
}
}
void numero_elementos(int v[])
{
    int i;
    int aux[11]={0};
    for (i=0;i<10;i++)
        aux[v[i]]=aux[v[i]]+1;
    for (i=1;i<11;i++)
        printf("Hay %d elementos con valor %d.\n",aux[i],i);
}
