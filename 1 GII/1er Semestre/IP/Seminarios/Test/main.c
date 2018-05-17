#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,suma;
    i=1;
    j=2;
    suma=0;
    do
    {
        suma=suma+i+j;
        j=j+2;
        i=j-1;
    }
    while (i<11);
    printf("%d",suma);

    return 0;
}
