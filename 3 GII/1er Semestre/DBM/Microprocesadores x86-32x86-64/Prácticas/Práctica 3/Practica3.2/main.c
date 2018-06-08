#include <stdio.h>

int convertir_celsius_fahrenheit(int temperatura_entrada, int sentido_conversion, int *temperatura_salida);
int main(int argc, char *argv[])
{
	int temperatura_entrada, sentido_conversion, temperatura_salida;

	printf("Elija la conversión a realizar:\n0.) Celsius->Fahrenheit\n1.) Fahrenheit->Celsius");
	scanf("%d", &sentido_conversion);
	printf("Introduzca al temperatura de entrada:");
	scanf("%d", &temperatura_entrada);
	convertir_celsius_fahrenheit(temperatura_entrada, sentido_conversion, &temperatura_salida);

	printf("%d", temperatura_salida);

	return 0;
}
