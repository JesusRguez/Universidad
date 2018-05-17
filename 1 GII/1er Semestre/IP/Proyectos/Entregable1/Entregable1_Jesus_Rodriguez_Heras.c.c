//Realiza un programa que calcule la suma de los digitos impares de un número entero.
//Quiere probar con otro número?? El programa deberá pedir números hasta que el usuario desee.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,s,cont,ascii,c;
    char r;
do
{
    printf("Introduzca un numero para hallar la suma de sus cifras impares pulsando 0 mas ENTER despues de introducir el numero:");
    s=0;
    do
    {
        c=getchar();
        if (c%2==1)
        {
            s=s+c;
        }
    }
    while (c!='0');

    printf("La suma de los digitos impares es: %i\n",s);
    printf("¿Desea probar con otro numero?(s/n)");
    scanf("%c",&r);
}
while (r=='s');
    return 0;
}
//Debería de pedir el reinicio del programa pero no he conseguido hacer que lo pida.
//Tampoco he conseguido que funcione del todo el algoritmo por falta de tiempo y por que al usar el getchar, el algoritmo trabaja con el codigo asccii de los numero introducidos y al hacer la suma, me suma los numeros ascii y no con el valor introducido.
