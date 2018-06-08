//Lo ideal sería que estuviera en hexadecimal para que se viera bien el tema de las posiciones de memoria
#include <stdio.h>

int logicas(int n1, int n2);

int main(int argc, char *argv[])
{
	unsigned int n1, n2, res;

	printf("Introudzca el primer elemento ");
	scanf("%d", &n1);
	printf("\nIntroudzca el segundo elemento: ");
	scanf("%d", &n2);

	res = logicas(n1, n2);
	printf("El valor de es: %d", res);

	return 0;
}
