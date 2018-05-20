#include <stdio.h>
#include <stdlib.h>

in main()
{
    int a,i,m,s;
    printf("Introduce diez numeros");
    s=0;
    for (i=1;i<=10;i++){
        scanf("%d",&a);
        s=s+a;
    }
    m=s/10;
    printf("La media de estos numeros es: %d",m);
    return 0;
}
