#include <stdio.h>
#include <stdlib.h>

int factorial (int*);
void fib (int);

int main()
{
    char c;
    do
    {
    int n,fac;
    printf("Introduce un numero entero:");
    scanf("%d",&n);
    fac=factorial(n);
    printf("El resultado de la factorial de %d es %d.\n",n,fac);
    fib(fac);
    printf("Quiere volver a probar? (s/n)\n");
    fflush(stdin);
    scanf("%c",&c);
    }
    while (c!='n');

    return 0;
}
//Cabecera: int factorial(int*f)
//Precondición: La variable n debe estar inicializada
//Postcondición: Devuelve el valor de la factorial
int factorial(int*f){
int p,i;
p=1;
for (i=1;i<=f;i++)
{
    p=p*i;
}
return (p);
}
//Cabecera: void fib(int*f)
//Precondición: La variable n debe estar inicializada
//Postcondición: Devuelve la sucesión de Fibonacci

void fib(int f){
int a,b,s,i;
a=0;
printf("%d\n",a);
b=1;
s=0;
for (i=1;i<=f-2;i++){
        s=a+b;
        a=b;
        b=s;
        printf("%d\n",b);

    }
}

