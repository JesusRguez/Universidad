#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415

float perimetro (float);
float area(float);
float volumen (float);

int main()
{
    float n,p,a,v;
    int o;
    printf("Introduce el valor del radio:");
    scanf("%f",&n);
    printf("Intoduzca: 1=perimetro; 2=area; 3=volumen\n");
    scanf("%d",&o);
    switch (o)
    {
    case 1:
        p=perimetro(n);
        printf("El perimetro es: %f",p);
        break;
    case 2:
        a=area(n);
        printf("El area es: %f",a);
        break;
    case 3:
        v=volumen(n);
        printf("El volumen es: %f",v);
        break;
    default:
        printf("Valor incorrecto.");
    }

    return 0;
}

//Cabecera: float perimetro (flaot r)
//Precondición: El valor del radio ya está definido
//Postcondición: Devuelve el valor del perimetro
float perimetro(float r){
    float s;
    s=2*PI*r;
    return (s);
}
//Cabecera: float area (float r)
//Precondición: El valor del radio ya está definido
//Postcondición: Devuelve el valor del area
float area (float r){
    float s;
    s=2*PI*r*r;
    return (s);
}
//Cabecera: float volumen (float v)
//Precondición: El valor del radio ya está definido
//Postcondición: Devuelve el valor del volumen
float volumen (float r){
    float s;
    s=(4/3)*PI*r*r*r;
    return (s);
}
