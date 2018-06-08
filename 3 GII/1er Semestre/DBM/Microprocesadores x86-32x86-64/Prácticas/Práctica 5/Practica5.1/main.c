#include <stdio.h>

int contar_valor_en_array(int valor, int *array, unsigned int longitud, int *resultado);

int main(int argc, char *argv[])
{
	int correcto, valor, resultado=0;
	unsigned int longitud=10;
	int array[10]={1,1,5,6,6,5,4,8,7,6};
	printf("Introduce el numero que desea buscar en el vector:");
	scanf("%d", &valor);
	correcto=contar_valor_en_array(valor, array, longitud, &resultado);
	if(correcto==1)
		printf("Los argumentos son correctos y el resultado es: %d", resultado);
	else
		printf("Los argumentos no son correctos.");
	return 0;
}


