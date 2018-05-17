#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a,b,c;
    printf("Introduce el numero del termino de la sucesion de Fibonnacci que desea mostrar:");
    scanf("%d",&n);
    a=0;
    b=1;
    c=0;

    for (i=1;i<=n-2;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    printf("%d",b);

    return 0;
}
