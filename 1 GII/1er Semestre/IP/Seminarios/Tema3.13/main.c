#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,i,aux,cont;

    printf("Introduzca el primer numero positivo entero:");
    do{
    scanf("%d",&a);
    if (a<0)
        printf("Introduzca el primer numero positivo entero:");
    }
    while (a<0);
    printf("Introduzca el segundo numero positivo entero:");
    do{
    scanf("%d",&b);
    if (b<0)
        printf("Introduzca el segundo numero positivo entero:");
    }
    while (b<0);
    cont=0;
    if (b>a)
    {
        aux=a;
        a=b;
        b=aux;
    }
    if (b==0)
        printf("No se puede dividir por 0.");
    else {
    if (b>0)
    {
    for (i=1;i<=a;i++)
    {
        c=a-b;
        a=c;
        cont=cont+1;
    }
    }
    printf("El cociente es: %d\n",cont);
    printf("El resto es: %d",c);
    }

    return 0;
}
