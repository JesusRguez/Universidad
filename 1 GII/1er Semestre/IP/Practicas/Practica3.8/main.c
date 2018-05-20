#include <stdio.h>
#include <stdlib.h>

void obtener_valores(float*,float*);
float calcular (float,float);
void imprimir_respuesta(float);
int main()
{
    float res, vol, intensidad;
    obtener_valores(&res,&vol);
    intensidad= calcular(res, vol);
    imprimir_respuesta(intensidad);

    return 0;
}
//Cabecera: void obtener_valores(float*,float*)
//Precondición:
//Postcondición: Da valores a las variables r y v
void obtener_valores(float*r,float*v)
{
    printf("Introduzca el valor de la resistencia:");
    scanf("%f",&*r);
    printf("Introduzca el valor del voltaje:");
    scanf("%f",&*v);
}
//Cabecera: float intensidad(flaot,float)
//Precondición: El denominador no puede ser 0 y las variables han de estar inicializadas
//Postcondición: Devuelve el valor de la intensidad
float calcular(float r,float v)
{
    float i;
    i=v/r;
    return (i);
}
//Cabecera: void imprimir_respuesta(float)
//Precondición:
//Postcondición: Imprime el valor de la intensidad
void imprimir_respuesta(float i)
{
    printf("El valor de la intensidad es: %f",i);
}
