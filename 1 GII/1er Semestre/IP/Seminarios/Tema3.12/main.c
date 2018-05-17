#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,b,sp,si,cp,ci,mi;
    printf("Introduzca el numero de terminos que desea introducir:");
    scanf("%d",&n);
    sp=0;
    si=0;
    cp=0;
    ci=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&b);
        if (b%2==0)
        {
            sp=sp+b;
            cp=cp+1;
        }
        else
        {
            si=si+b;
            ci=ci+1;
        }
    }
    mi=si/ci;
    printf("Suma de los pares: %d\n",sp);
    printf("Cantidad de numeros pares: %d\n",cp);
    printf("Media de los impares: %d",mi);

    return 0;
}
