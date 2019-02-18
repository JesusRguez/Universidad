#include <stdio.h>

int sse_sumar_filas(const float *ptr_matriz, float *ptr_suma);

int main(int argc, char *argv[])
{
	int resultado=0;
	float ptr_matriz[4][4]={{1.0,2.0,3.0,4.0},{5.0,6.0,7.0,8.0},{9.0,10.0,11.0,12.0},{13.0,14.0,15.0,16.0}}, ptr_suma[4]={0,0,0,0};

	resultado=sse_sumar_filas(&ptr_matriz[0][0], ptr_suma);

	if(resultado==1){
		printf("Los argumentos son validos y la suma es:");
		printf("%f - %f - %f - %f", ptr_suma[0],ptr_suma[1],ptr_suma[2],ptr_suma[3]);
	}
	else
		printf("Los argumentos no son validos.");

	return 0;
}
