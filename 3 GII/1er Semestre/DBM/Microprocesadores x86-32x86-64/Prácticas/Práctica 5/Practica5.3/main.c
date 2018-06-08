#include <stdio.h>

int ordenar(int *array, unsigned int longitud);

int main(int argc, char *argv[])
{
	int array[10]={5,9,4,6,8,1,3,7,2,0};
	unsigned int longitud=10;
	int correcto=ordenar(&array, longitud);
	if(correcto==1){
		printf("Los argumentos son correctos.\n");
		for (int i=0; i<longitud;i++)
			printf("%lf  ", array[i]);
	}
	else
		printf("Los argumentos no con correctos");
	return 0;
}


