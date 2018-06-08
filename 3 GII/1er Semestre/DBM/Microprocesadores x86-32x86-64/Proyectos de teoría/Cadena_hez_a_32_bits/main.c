#include <stdio.h>

int b32_cadena_hex_a_32_bits(const char *cadena, unsigned int *resultado);

int main(int argc, char *argv[])
{
	char cadena[8];
	unsigned int resultado=0;

	for(int i=0;i<8;i++){
		printf("Introudzca el elemento %d del número hexadecimal que desea convertir en binario: ", i+1);
		fflush(stdin);
		scanf("%c", &cadena[i]);
	}

	resultado=b32_cadena_hex_a_32_bits(cadena, &resultado);

	if(resultado==1)
		printf("Se ha realizado la conversión correctamente.");
	else
		printf("No se ha podido realizar la conversion.");

	return 0;
}
