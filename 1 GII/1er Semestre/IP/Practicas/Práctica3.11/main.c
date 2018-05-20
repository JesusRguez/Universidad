#include <stdio.h>
#include <stdlib.h>

void orden (float, float, float);

int main()
{
    float a,b,c;
    char respuesta;
    do
    {
    puts("Introduzca el primer numero:");
    scanf("%f",&a);
    puts("Introduzca el segundo numero:");
    scanf("%f",&b);
    puts("Introduzca el tercer numero:");
    scanf("%f",&c);

    orden(a,b,c);

    fflush(stdin);
    puts("Desea volver a probar?(S/N)");
    scanf("%c",&respuesta);
    system("cls");
    }while (respuesta!='n');
    return 0;
}
void orden(float a,float b,float c)
{
    float aux;
    if (a<b)
    {
        aux=a;
        a=b;
        b=aux;
    }
    if (b<c)
    {
        aux=b;
        b=c;
        c=aux;

    if (a<b)

        aux=a;
        a=b;
        b=aux;
    }

    printf("El mayor valor es %f\n",a);
}
