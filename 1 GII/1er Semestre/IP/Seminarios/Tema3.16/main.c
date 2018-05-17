#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a,b,c;
    a=0;
    b=1;
    c=0;

    for (i=1;i<=10;i++)
    {
        c=a+b;
        a=b;
        b=c;
        printf("%d\n",b);
    }


    return 0;
}
