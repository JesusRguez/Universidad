#include <stdio.h>

double fpu_producto_escalar(double *ptr_v1, double *ptr_v2, unsigned int dim);

int main(int argc, char *argv[])
{
	unsigned int dim=5;
	double ptr_v1[5]={1,2,3,4,5};
	double ptr_v2[5]={6,7,8,9,10};

	printf("La solución del producto escalar es %lf.", fpu_producto_escalar(&ptr_v1, &ptr_v2, dim));

	return 0;
}
