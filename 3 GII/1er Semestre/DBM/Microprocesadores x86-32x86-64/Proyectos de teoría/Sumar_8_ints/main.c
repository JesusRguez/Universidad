#include <stdio.h>

int b64_sumar_8_ints(int a, int b, int c, int d, int e, int f, int g, int h);

int main(int argc, char *argv[])
{
	int a=2,b=3,c=4,d=2,e=5,f=8,g=8,h=9, suma;
	suma=b64_sumar_8_ints(a,b,c,d,e,f,g,h);
	printf("El resultado es: %d", suma);

	return 0;
}
