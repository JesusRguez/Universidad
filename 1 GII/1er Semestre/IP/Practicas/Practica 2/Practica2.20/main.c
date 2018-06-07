#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,aux,r;
    printf("Introduce el primer numero:");
    scanf("%d",&a);
    printf("Introduce el segundo numero:");
    scanf("%d",&b);
    if (a<b)
    {
        aux=a;
        a=b;
        b=aux;
    }
    do
    {
        r=(a%b);
        a=b;
        b=r;
    }
    while (b!=0);
    printf("El M.C.D. es %d",a);

    return 0;
}
