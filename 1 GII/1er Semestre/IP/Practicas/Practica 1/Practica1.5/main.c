#include <stdio.h>
#include <stdlib.h>

char c;
int i;
float f;
double d;

int main()
{
    printf("El valor en bytes del tipo char es: %d", sizeof(char));
    printf("\nEl valor en bytes del tipo int es: %d", sizeof(int));
    printf("\nEl valor en bytes del tipo float es: %d", sizeof(float));
    printf("\nEl valor en bytes del tipo double es: %d", sizeof(double));

    return 0;
}
