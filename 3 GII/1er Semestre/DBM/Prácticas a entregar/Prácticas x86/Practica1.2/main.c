#include <stdio.h>

int det(int a11, int a12, int a21, int a22);

int main(int argc, char *argv[])
{
	int a11, a12, a21, a22, d;

	printf("Introudzca el valor del a11: ");
	scanf("%d", &a11);
	printf("\nIntroudzca el valor del a12: ");
	scanf("%d", &a12);
	printf("\nIntroudzca el valor del a21: ");
	scanf("%d", &a21);
	printf("\nIntroudzca el valor del a22: ");
	scanf("%d", &a22);

	d = det(a11, a12, a21, a22);
	//El determinante era a11*a22-a12*a21

	printf("El valor del determinante es: %d", d);

	return 0;
}
