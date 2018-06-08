#include <stdio.h>

char * uint_a_cadena_binario(unsigned int dato, char * buffer);

int main(int argc, char *argv[])
{
	unsigned int dato;
	char buffer[33];

	printf("Introudzca un numero en hexadecimal para pasarlo a binario: ");
	scanf("%x", &dato); //El dato recibido está en hexadecimal

	uint_a_cadena_binario(dato, buffer);

	printf("El numero en binario es: %s", buffer);

	return 0;
}
