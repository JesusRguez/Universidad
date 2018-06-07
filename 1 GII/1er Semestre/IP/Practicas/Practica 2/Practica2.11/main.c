#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i;
    printf("Introduce el primer numero:");
    scanf("%d",&a);
    printf("Introduce el segundo numero:");
    scanf("%d",&b);

    for (i=a;i<=b;i++)
        printf("%d\n",i);

    return 0;
}
