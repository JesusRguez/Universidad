#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,n,i,mayor,menor,num;
    do{
    printf("Introducir el valor de N:");
    scanf("%d",&N);
    }
    while (N<=0);
    printf("Introduce num:");
    scanf("%d",&num);
    mayor=menor=num;
    while (n>1) {
        printf("Introduce num:");
        scanf("%d",&num);
        if (num>mayor)
            mayor=num;
        else if (num<menor)
        {
         menor=num;
        }
    }printf("El mayor es %d y el menor %d",mayor,menor);

    return 0;
}
