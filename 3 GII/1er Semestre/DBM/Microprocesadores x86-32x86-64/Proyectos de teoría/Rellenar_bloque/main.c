#include <stdio.h>

int b32_rellenar_bloque(void *ptr_bloque, unsigned char byte_relleno, unsigned int longitud_bloque);

int main(int argc, char *argv[])
{
	char ptr_bloque;
	unsigned char byte_relleno=0;
	unsigned int longitud_bloque=4;

	int resultado=b32_rellenar_bloque(&ptr_bloque, byte_relleno, longitud_bloque);

	if(resultado==1)
		printf("El proceso terminó correctamente.");
	else
		printf("Ocurrió algún fallo en el proceso.");

	return 0;
}
