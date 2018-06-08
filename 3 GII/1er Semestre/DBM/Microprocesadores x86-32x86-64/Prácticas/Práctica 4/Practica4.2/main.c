#include <stdio.h>

double eval_poli(double *coefs, double x, unsigned int grado);
int main(int argc, char *argv[])
{
	unsigned int grado;
	double coefs[]={1, 2, 3};
	double x;

	printf("Introduce el grado del polinomio:");
	scanf("%i", &grado);

	printf("Introduce el valor de x para el que debe evaluarse el polinomio:");
	scanf("%lf",&x);

	printf("El resultado de evaluar el polinomio es: %lf", eval_poli(coefs, x, grado));

	return 0;
}
