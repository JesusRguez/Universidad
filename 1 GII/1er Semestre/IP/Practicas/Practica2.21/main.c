#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("Introduzca una oracion:");
    do
    {
    c=getchar();
    putchar(c);
    }
    while (c!='0');

    return 0;
}
