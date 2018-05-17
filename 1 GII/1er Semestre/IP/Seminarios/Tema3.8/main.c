#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i,b,p;
    printf("Introduce el valor de la base:");
    scanf("%d",&a);
    printf("Introduce el valor del exponente:");
    scanf("%d",&b);

    p=1;

    for (i=1;i<=b;i++)
    {
        p=a*p;
    }
    if (b==0)
        printf("El resultado es 1.");
    if (b<0)
    {
        printf("El resultado es 1/%d",p);
    }
    else
        printf("El resultado es %d",p);

    return 0;
}
