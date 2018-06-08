#include <stdio.h>

int b32_es_binario_capicua(unsigned int n);

int main(int argc, char *argv[])
{
	unsigned int n;
	int c;

	printf("Introudzca un numero para saber si es binariamente capicua: ");
	scanf("%u", &n);

	c=b32_es_binario_capicua(n);

	if(c==1){
		puts("El numero es binariamente capicua.");
	}else{
		puts("El número no es binariamente capicua.");
	}

	return 0;
}
