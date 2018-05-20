#include <stdio.h>
#include <stdlib.h>

int main()
{
    float k, p, g, litros, T, t1, t2, consumo1, consumo100, vm;
    printf("Introduzca el total de kilometros recorridos:");
    scanf("%f",&k);
    printf("Introduzca el precio de la gasolina por litro:");
    scanf("%f",&p);
    printf("Introduzca el dinero de gasolina gastado en el viaje:");
    scanf("%f",&g);
    printf("¿Cuantas horas ha tardado en llegar a su destino?");
    scanf("%f",&t1);
    printf("¿Cuantos minutos ha tardado en llegar a su destino?");
    scanf("%f",&t2);

    T=t1+(t2/60);

    litros=p*g;
    consumo1=litros/k;
    consumo100=consumo1*100;
    vm=k/T;

    printf("El consumo de gasolina por cada kilometro es de: %f",consumo1);
    printf("\nEl consumo de gasolina por cada 100 kilometros es de: %f",consumo100);
    printf("\nLa velocidad media es de: %.2f");

    return 0;
}
