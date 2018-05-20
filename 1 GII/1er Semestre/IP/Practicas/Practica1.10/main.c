#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159
#define G 9.81

int main()
{
    float L, p;
    printf("Introduce la longitud del pendulo:");
    scanf("%f",&L);
    p=2*PI*sqrt(L/G);
    printf("El periodo del pendulo es %f",p);

    return 0;
}
