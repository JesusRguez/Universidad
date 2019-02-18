#include <stdio.h>

double media(double *vector, unsigned int numdatos);
int main(int argc, char *argv[])
{
	unsigned int numdatos=10;
	double vector[]={1,2,3,4,5,6,7,8,9,10};

	/*for(int i=0;i<numdatos;i++){
		printf("Introduce el elemento %d del vector: ", i+1);
		scanf("%lf",&vector[i]);
	}*/


	printf("La media es: %lf", media(vector, numdatos));

	return 0;
}
