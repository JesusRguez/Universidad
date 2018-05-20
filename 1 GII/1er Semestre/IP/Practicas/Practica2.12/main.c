#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,p,cont;
    printf("Introduce la base de la potencia:");
    scanf("%d",&a);
    printf("Introduce el exponente de la potencia:");
    scanf("%d",&b);
    p=1;
    cont=0;

    while (cont!=abs(b))
        {
            p=p*a;
            cont=cont+1;
        }

    if (b<0)
        printf("El resultado es: 1/%d",p);
    else
        printf("El resultado es: %d",p);

    return 0;
}
