#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ascii,i;
    ascii=0;

    for (i=0;i<=256;i++)
    {
        ascii=i;
        printf("El codigo ascii %d corresponde a %c\t",ascii,i);
    }
    return 0;
}
