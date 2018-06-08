//Este programa devuelve la solución de una ecuación de segundo grado según la fórmula general de
//toda la vida. Devolverá 0 si es un puntero nulo; 1 si son raíces reales (se calculan); -1 si
//son raíces complejas (no se calculan).

#include <stdio.h>

int fpu_raices_reales(double a, double b, double c, double *raiz1, double *raiz2);

int main(int argc, char *argv[])
{
	double a, b, c, raiz1=0, raiz2=0;
	printf("Introduzca el coeficiente a:");
	scanf("%lf",&a);
	printf("Introduzca el coeficiente b:");
	scanf("%lf",&b);
	printf("Introduzca el coeficiente c:");
	scanf("%lf",&c);

	int flag=fpu_raices_reales(a, b, c, &raiz1, &raiz2);

	if(flag==1)
		printf("La solución de la ecuación de segundo grado es:\nRaiz 1: %lf\nRaiz 2: %lf", raiz1, raiz2);
	else
	{
		if(flag==0)
			printf("Punteros nulos, no se puede resolver la ecuación.");
		else
			if(flag==-1)
				printf("El resultado son raices complejas. No se calculan.");
	}

	return 0;
}
