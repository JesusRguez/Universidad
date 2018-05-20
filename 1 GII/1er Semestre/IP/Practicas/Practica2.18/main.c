#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a,b,c;
    printf("Introduce el numero de terminos de la sucesion de Fibonnacci que quiera mostrar:");
    scanf("%d",&n);

    a=0;
    b=1;
    c=0;

    printf("%d\n",a);
    printf("%d\n",b);
    for (i=1;i<=n-2;i++){
        c=a+b;
        a=b;
        b=c;
        printf("%d\n",b);

    }

    return 0;
}
