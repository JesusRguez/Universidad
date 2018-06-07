#include <stdio.h>
#include <stdlib.h>

void inicializa_vector(int vector[]);
void imprimir (int vector[]);

int main()
{
    int vector[10];
    inicializa_vector(vector);
    imprimir(vector);

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

void imprimir(int vector[])
{
    int i;
    for (i=0;i<10;i++)
        printf("%d",vector[i]);
}
