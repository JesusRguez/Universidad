#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i;
    printf("Introduce un numero:");
    scanf("%d",&a);
    b=0;
    for (i=1;i<=a;i++)
    {
        if (a%i==0)
            b++;
    }
    if (b==2)
        printf("El numero es primo.");
    else
        printf("El numero no es primo.");

    return 0;
}
