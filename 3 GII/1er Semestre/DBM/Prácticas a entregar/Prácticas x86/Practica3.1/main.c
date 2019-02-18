#include <stdio.h>

int extraer_campos_float(float flotante, unsigned int * fraccion, unsigned char * exponente, unsigned char * signo);

int main(int argc, char *argv[])
{
	float flotante=3.2;
	int exito=0;
	unsigned char exponente=0, signo=0;
	unsigned int fraccion=0;

	exito=extraer_campos_float(flotante, &fraccion, &exponente, &signo);

	printf("Fraccion: %u  ", fraccion);
	printf("Exponente: %u  ", exponente);
	printf("Signo: %u  ", signo);

	return 0;
}
