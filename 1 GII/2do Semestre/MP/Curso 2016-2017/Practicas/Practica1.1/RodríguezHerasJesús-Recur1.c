#include <stdio.h>
#include <stdlib.h>

int MCD (int, int);

int main()
{
    int a,b,aux,mcd;

    puts("Programa para calcular el MCD de dos numeros enteros:");
    puts("Introduce el primer numero entero:");
    scanf("%d",&a);
    puts("Introduce el segundo numero entero:");
    scanf("%d",&b);

    if (b>a) //Si b es mayor que a, intercambia los valores para que el algoritmo de Euclides se realice adecuadamente.
    {
        aux=b;
        b=a;
        a=aux;
    }

    mcd=MCD(a,b);   //Llamada a la función MCD

    printf("El MCD es %d",mcd);

    return 0;
}

//Cabecera int MCD (int, int)
//Precondición: a y b han de estar inicializados
//Postcondición: Devuelve el máximo común divisor de a y b
int MCD(int a, int b)
{
    if (a%b==0)
        return b; //Si el resto de dividir a entre b es igual a 0, devuelve el valor de b
    else
        return MCD(b,a%b);  //En otro caso, devuelve b y el resto de dividir a entre b como segundo parámetro
}
