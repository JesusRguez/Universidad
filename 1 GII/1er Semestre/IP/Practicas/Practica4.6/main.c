#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[15],n,i;

    for (i=0;i<15;i++)
    v[i] = rand() % 11;
    do
    {
    puts("Introduzca un numero:");
    scanf("%d",&n);
    }while(n<0||n>10);
    for (i=0;i<15;i++)
    {
        if (n==v[i])
            printf("El numero esta en la posicion %d del vector.\n",i);
    }
    for (i=0;i<15;i++)
            printf("%d  ",v[i]);

    return 0;
}
