#include <stdio.h>
#include <stdlib.h>

int (operacion)(int, int);

int main()
{
    int a,b,resultado;
    char respuesta;
    do
    {
    puts("Introduzca el primer numero entero:");
    scanf("%d",&a);
    puts("Introduzca el segundo numero entero:");
    scanf("%d",&b);

    resultado=operacion(a,b);

    printf("El resultado es %d\n",resultado);

    puts("Desea volver a probar? (s/n)");
    fflush(stdin);
    scanf("%c",&respuesta);

    }while(respuesta!='n');

    return 0;
}

int(operacion)(int a, int b)
{
    char c;
    int operacion;

    puts("\nElija una opcion:\n");
    puts("\t1. Suma");
    puts("\t2. Resta");
    puts("\t3. Producto");
    puts("\t4. Division");
    fflush(stdin);
    scanf("%c",&c);

    switch (c)
    {
        case '1':
            operacion=a+b;
            break;
        case '2':
            operacion=a-b;
            break;
        case '3':
            operacion=a*b;
            break;
        case '4':
            operacion=a/b;
            break;
        default:
            puts("Opcion incorrecta.");
            break;
    }
    return (operacion);
}
