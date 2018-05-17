#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,s,cont;
    float m;
    printf("Introducir 10 numeros positivos:\n");
    s=0;
    cont=1;

    do
    {
        scanf("%d",&a);
        s=s+a;
        cont=cont+1;
    }
    while (cont<=10);
    m=s/10;
    printf("La media es: %f",m);

    return 0;
}
