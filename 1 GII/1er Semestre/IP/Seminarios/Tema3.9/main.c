#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,m,s;
    for (h=0;h<=23;h++){
        for (m=0;m<=59;m++){
            for (s=0;s<=59;s++){
            printf("%d:%d:%d\n",h,m,s);
            }
        }
    }
    printf("Este dia ha terminado.");

    return 0;
}
