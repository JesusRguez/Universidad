#include <stdio.h>

int sse_imagen_a_blanco_y_negro(unsigned char *ptr_imagen, int ancho, int alto, unsigned char umbral);

int main(int argc, char *argv[])
{
	unsigned char ptr_imagen=0, umbral=0;
	int ancho=0, alto=0, resultado;

	resultado=sse_imagen_a_blanco_y_negro(&ptr_imagen, ancho, alto, umbral);

	if(resultado==1)
		printf("La funcion ha trabajado correctamente.");
	else
		printf("Se ha producido algun error en los valores.");

	printf("Los argumentos no con correctos");
	return 0;
}
