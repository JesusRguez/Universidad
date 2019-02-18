#include <stdio.h>

int sumar_diagonal(long *matriz, unsigned int num_filas_columnas, long *resultado);

int main(int argc, char *argv[])
{
	long matriz[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	unsigned int num_filas_columnas=3;
	long resultado=0;
	int correcto=sumar_diagonal(&matriz[0][0], num_filas_columnas, &resultado);
	if(correcto==1)
		printf("Los argumentos son correctos y el resultado es: %li", resultado);
	else
		printf("Los argumentos no con correctos");
	return 0;
}

