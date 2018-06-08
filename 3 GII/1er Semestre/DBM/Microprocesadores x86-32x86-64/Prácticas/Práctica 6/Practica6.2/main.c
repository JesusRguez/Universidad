#include <stdio.h>

int sse_sumar_filas(const float *ptr_matriz, float *ptr_suma);

int main(int argc, char *argv[])
{
	int resultado=0;
	float ptr_matriz=0, ptr_suma=0;

	resultado=sse_sumar_filas(&ptr_matriz, &ptr_suma);

	if(resultado==1)
		printf("Los argumentos son validos y la suma es %lf", ptr_suma);
	else
		printf("Los argumentos no son validos.");

	return 0;
}
