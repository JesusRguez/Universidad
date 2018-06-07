#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,s;
    s=0;
    for (i=2;i<=1000;i=i+2)
    s=s+i;
    printf("El resultado es: %d",s);

    return 0;
}
