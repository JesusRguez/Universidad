#include <stdio.h>

char * int_a_cadena_decimal(int dato, char * buffer);

int main(int argc, char *argv[])
{
	int dato;
	char buffer[12];

	printf("Introudzca un numero para devolver una cadena con su mismo valor: ");
	scanf("%d", &dato); //El dato recibido está en hexadecimal

	int_a_cadena_decimal(dato, buffer);

	printf("La cadena es: %s", buffer);

	return 0;
}
