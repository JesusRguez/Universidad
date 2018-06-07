#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Introduce el primer numero:");
    scanf("%d",&a);
    printf("Introduce el segundo numero:");
    scanf("%d",&b);

    if (a%b==0)
        printf("a es divisible por b.\n");
    if (a%b!=0)
        printf("a no es divisible por b.\n");
    if (b%a==0)
        printf("b es divisible por a.");
    if (b%a!=0)
        printf("b no es divisible por a.");

    return 0;
}
