#include <stdio.h>
#include <stdlib.h>

float suma (float,float);
float resta (float,float);
float producto (float,float);
float division (float,float);

int main()
{
    int o;
    float s,r,p,d,x,y;
    printf("Elija la operacion que desea realizar\n1.-Suma     2.-Resta      3.-Producto     4.-Division\n");
    scanf("%d",&o);
    switch (o)
    {
        case 1:
            printf("Introduzca el primer numero:");
            scanf("%f",&x);
            printf("Introduzca el segundo numero:");
            scanf("%f",&y);
            s=suma(x,y);
            printf("El resultado es: %f",s);
            break;
        case 2:
            printf("Introduzca el primer numero:");
            scanf("%f",&x);
            printf("Introduzca el segundo numero:");
            scanf("%f",&y);
            r=resta(x,y);
            printf("El resultado es: %f",r);
            break;
        case 3:
            printf("Introduzca el primer numero:");
            scanf("%f",&x);
            printf("Introduzca el segundo numero:");
            scanf("%f",&y);
            p=producto(x,y);
            printf("El resultado es: %f",p);
            break;
        case 4:
            printf("Introduzca el primer numero:");
            scanf("%f",&x);
            printf("Introduzca el segundo numero:");
            scanf("%f",&y);
            d=division(x,y);
            printf("El resultado es %f",d);
            break;
        default:
            printf("Operacion no valida.");
    }

    return 0;
}

//Cabecera: float suma (float a,float b)
//Precondición: El valor de a y de b ya viene dado del main
//Postcondición: Devuelve el valor de la suma
float suma (float a, float b){
    float s;
    s=a+b;
    return (s);
}
//Cabecera: float resta(float a, float b)
//Precondición: El valor de a  y de b ya viene dado del main
//Postcondición: Devuelve el valor de la resta
float resta(float a, float b){
    float s;
    s=a-b;
    return(s);
}
//Cabecera: float producto(float a, float b)
//Precondición: El valor de a y de b ya viene dado del main
//Postcondición: Devuelve el valor del producto
float producto(float a, float b){
    float s;
    s=a*b;
    return(s);
}
//Cabecera: float division(float a, float b)
//Precondición: El valor de a y de b ya viene dado del main
//Postcondición: Devuelve el valor de la divisón
float division(float a, float b){
    float s;
    if (b==0)
        printf("No se puede dividir por cero.");
        else
            s=a/b;
    return (s);
}
