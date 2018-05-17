#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,c,i;
    printf("Introduce un numero para saber si esta en la serie de Fibonnacci:");
    scanf("%d",&n);
    a=0;
    b=1;
    c=0;
    if (n==0)
        printf("Si pertenece.");

    for (i=1;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
        if (n==c){
        printf("Si pertenece.");
        }

    }

    return 0;
}
