#include <stdio.h>
# include <bits/libc-header-start.h>

int logicas(int n1, int n2);

int main(void)
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
