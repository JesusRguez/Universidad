#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,a;
    printf("Introduzca un numero:");
    scanf("%d",&a);
    p=&a;
    printf("La direccion de memoria de a es %p\n",&a);
    printf("El contenido del entero es %d\n",a);
    printf("La dirección de memoria de p es %p\n",*p);
    printf("El contenido del puntero es %d\n",*p);
    printf("El valor referenciado del puntero es %p\n",a);

    return 0;
}
