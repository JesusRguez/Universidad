#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i,j;
    for (i=3+1;i<32767;i++)
        {
        for (j=2;i%j!=0;j++)
    {
        if (j==i)
        printf("%d\t",i);

    }

        }


    return 0;
}
