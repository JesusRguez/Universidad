#include <stdio.h>

int sse_producto_escalar(const float *vector_1, const float *vector_2, unsigned int dimension, float *resultado);

int main(int argc, char *argv[])
{
	int bien=0;
	float vector_1[10], vector_2[10], resultado;
	unsigned int dimension=10;

	bien=sse_producto_escalar(vector_1, vector_2, dimension, &resultado);

	if(bien==1)
		printf("Los argumentos son validos y la suma es");
	else
		printf("Los argumentos no son validos.");

	return 0;
}
