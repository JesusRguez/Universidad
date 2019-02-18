#include <stdio.h>

void * copiar_bloque_memoria(void * destino, void * origen, unsigned int longitud);

int main(int argc, char *argv[])
{
	char *destino, *origen;
	unsigned int longitud=0;



	copiar_bloque_memoria(destino, origen, longitud);

	printf("La cadena es: " );

	return 0;
}
