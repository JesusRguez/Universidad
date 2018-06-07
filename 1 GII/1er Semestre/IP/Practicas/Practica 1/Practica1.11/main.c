#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n, a, b, c, d;
    printf("Introduce el valor de n:");
    scanf("%f",&n);
    a=pow(n,2);
    b=pow(n,3);
    c=pow(2,n);
    d=pow(3,n);
    printf("El valor de n elevado a dos es: %f",a);
    printf("\nEl valor de n elevado a tres es: %f", b);
    printf("\nEl valor de 2 elevado a n es: %f",c);
    printf("\nEl valor de 3 elevado a n es: %f",d);

    return 0;
}
