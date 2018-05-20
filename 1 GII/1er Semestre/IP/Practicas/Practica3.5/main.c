#include <stdio.h>
#include <stdlib.h>

int producto (int,int);
int division (int,int);

int main()
{
    int i,a,b,p,d,aux;
    for (i=1;i<=10;i++)
    {
        printf("Introduzca el primer numero:\n");
        scanf("%d",&a);
        printf("Introduzca el segundo numero:\n");
        scanf("%d",&b);
        if (i%2==1)
        {
            p=producto(a,b);
            printf("El producto de ambos numeros es: %d\n",p);
        }
        else
        {
            if (b>a)
            {
                aux=b;
                b=a;
                a=aux;
            }
            if(b==0)
            {
                printf("No se puede dividir por 0.\n");
            }
            d=division(a,b);
            printf("El cociente de ambos numeros es: %d\n",d);
        }
    }

    return 0;
}
//Cabecera: int producto (int a,int b)
//Precondición: a y b deben estar declaradas en el main
//Postcondición: Devuelve el valor del producto de a y b
int producto (int a,int b)
{
    int i,r;
    for (i=1;i<=b;i++)
    {
        a=a+a;
    }
    return (a);
}
//Cabecera: int division(int a,int b)
//Precondición: a y b deben estar declaradas en el main, mayores que cero y a>b
//Postcondición: Devuelve el valor del cociente de a y b
int division(int a,int b)
{
    int i;
    i=0;
    while (a>=b)
    {
        a=a-b;
        i++;
    }
    return (i);
}
