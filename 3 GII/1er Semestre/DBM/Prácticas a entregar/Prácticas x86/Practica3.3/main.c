#include <stdio.h>

int calcular_histograma(const unsigned char *ptr_datos, unsigned int num_datos,
		unsigned int *ptr_histograma);

int main(int argc, char *argv[])
{
	const unsigned char ptr_datos[10]={1,3,5,6,2,4,9,7,8,0};
	unsigned int num_datos=10, ptr_histograma[256];
	int resultado;

	for(int i=0; i<256; i++){
		ptr_histograma[i]=0;
	}

	resultado=calcular_histograma(&ptr_datos, num_datos, &ptr_histograma);

	if(resultado==1)
		for(int i=0; i<256; i++){
			printf("%d\n",ptr_histograma[i]);
		}
	else
		printf("Han ocurrido fallos");


	return 0;
}
