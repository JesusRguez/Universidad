#include <stdio.h>

int b64_sumar_char_short_int_long(char a, short b, int c, long d);

int main(int argc, char *argv[])
{
	char a=2;
	short b=5;
	int c=3;
	long d=4;
	int suma;
	suma=b64_sumar_char_short_int_long(a,b,c,d);
	printf("El resultado es %i", suma);

	return 0;
}
