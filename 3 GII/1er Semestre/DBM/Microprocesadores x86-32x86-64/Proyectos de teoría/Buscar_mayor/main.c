#include <stdio.h>

int b64_buscar_mayor(int *array, unsigned int num_datos, int *resultado);

int main(int argc, char *argv[])
{
	int array[10]={1,2,3,40,65,5,6,7,8,9}, resultado;
	unsigned int num_datos=10;
	int bien;
	bien=b64_buscar_mayor(array, num_datos, &resultado);
	if(bien==1)
		printf("El algoritmo ha tenido exito y el resultado es: %d", resultado);
	else
		printf("El algorimo no ha tenido exito.");

	return 0;
}
