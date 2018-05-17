//Realiza un programa que reciba el valor de x y el numero de terminos de n (debe ser mayor a 0).
//Y que realice la aproximacion de ln(1+x) segun la formula anterior.
//No utilizar la función pow, sino crear una nueva funcion potencia.

#include <stdio.h>
#include <stdlib.h>

void potencia (float, int, double*);
float aproximacion (float, float);

int main()
{
    float x,aprox;
    int n;
    char c;
    do
    {
    do
    {
        printf ("Introduce el valor de x entre -1 y 1:\n");
        scanf("%f",&x);
        if (x<-1 || x>1)
            printf("El valor de x debe estar entre -1 y 1.\n");
    }
    while (x<-1 || x>1);
    do
    {
        printf("Introducir el numero de terminos con el que realizar la aproximación:\n");
        scanf("%d",&n);
        if (n<0)
            printf("El numero de terminos debe ser entero y positivo.");
    }
    while (n<=0);
    aprox=aproximacion(x,n);
    printf("El resultado aproximado de la funcion es: %f\n",aprox);
    printf("Desea volver a repetir el proceso: s(si)/n(no)\n");
    fflush(stdin);
    scanf("%c",&c);
    }
    while (c!='n');
    return 0;
}

//Cabecera: void potencia(float b, int e, double*r).
//Precondición: x y n han de estar inicializadas. x ha de estar entre -1 y 1 y n ha de ser un entero positivo.
//Postcondición: Devuelve el valor de la potencia b^e.
void potencia (float b, int e, double*r)
{
    int i;
    float p;
    p=b;
    for (i=1;i<e;i++)
    {
        p=p*b;
    }
    *r=p;
}

//Cabecera: float aproximacion(float x, float n)
//Precondición: x y n han de estar inicializadas. x ha de estar entre -1 y 1 y n ha de ser un entero positivo.
//Postcondición: Devuelve el valor de la aproximación de la función ln(1+x)
float aproximacion(float x, float n)
{
    int i;
    double resultado,suma,xp,s,p;
    suma=0;
    for (i=1;i<=n;i++)
    {
        potencia(x,i,&xp);
        potencia(-1,i-1,&s);
        suma=suma+(s*(xp/i));
    }
return (suma);
}
