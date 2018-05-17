#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s,i;
    s=0;
    for (i=2;i<=200;i=i+2)
    {
        s=s+i;
    }
    printf("%d",s);

    return 0;
}
