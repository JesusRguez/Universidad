#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    float m;

    printf("Introduce el primer numero:");
    scanf("%i",&a);
    printf("Introduce el segundo numero:");
    scanf("%i",&b);
    printf("Introduce el tercer numero:");
    scanf("%i",&c);
    m=(float)(a+b+c)/3;
    printf("La media de %i %i y %i es %f:",a,b,c,m);

    return 0;
}
