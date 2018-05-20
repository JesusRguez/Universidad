#include <stdio.h>
#include <stdlib.h>

int MCD (int,int);
void intercambio (int*,int*);

int main()
{
    int a,b,aux,mcd;

    puts("Introduce el primer numero entero:");
    scanf("%d",&a);
    puts("Introduce el segundo numero entero:");
    scanf("%d",&b);

    if (b>a)
    {
        aux=b;
        b=a;
        a=aux;
    }

    mcd=MCD(a,b);

    printf("El MCD es %d",mcd);

    return 0;
}

//Cabecera int MCD (int,int)
//Precondición: a y b han de estar inicializados
//Postcondición: Devuelve el máximo común divisor de a y b
int MCD(int a, int b)
{
    int aux;
    if (a%b==0)
        return b;
    else
        return MCD(b,a%b);

}
