#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,s,cont;
    printf("Introduzca el numero de terminos que va a introducir:");
    scanf("%d",&n);
    cont=0;
    s=0;
    while (n!=cont)
    {
        scanf("%d",&a);
        if (cont%2==0)
        {
            s=s+a;
        }
        cont=cont+1;
    }
    printf("La suma de los terminos en las posiciones impares es: %d",s);

    return 0;
}
