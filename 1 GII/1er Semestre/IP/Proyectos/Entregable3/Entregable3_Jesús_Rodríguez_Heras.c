//Se desea almacenar la informaci�n relativa a n productos de un establecimiento. De cada producto se desea almacenar su nombre,
//c�digo (alfanum�rico) y precio.
//1. Implementa la estructura necesaria (valor de n introducido por el usuario)
//2. Realiza la funcion void inicializa (producto v_productos[],int n)
//3. Realiza la funci�n void busca_producto(producto v_productos[], int n)
//Debe escribir nombre y c�digo del producto m�s caro (Al igual que el precio m�ximo, el primero)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
    {
        char nombre[100], codigo[100];
        int precio;
    }producto;

void inicializa (producto p, int n);
void busca_producto (producto p, int n);
void precio (producto p, int n);

int main()
{

    int n,i;

    puts("Introduzca el numero de productos que desea aniadir:");
    scanf("%d",&n);

    producto p[i];

    inicializa(p[i], n);

    busca_producto(p[i], n);

    precio(p[i], n);

    return 0;
}
//Cabecera: Inicializa (producto p, int n)
//Precondici�n: n ha de ser un valor introducido por el usuario
//Postcondici�n: Inicializa el vector producto
void inicializa (producto p, int n)
{
    int i;
    /*FILE *f;
    if ((f=fopen("Productos.txt","a"))==NULL)
        puts("El fichero no se puede abrir.");
    else{*/
    for (i=0;i<n;i++)
    {
        printf("Introduzca el nomrbe del producto %d\n",i);
        fgets(p.nombre,100,stdin);
        printf("Introduzca el codigo del producto %d\n",i);
        scanf("%s",&p.codigo);
        printf("Introduzca el precio del producto %d\n",i);
        scanf("%d",&p.precio);

        /*fprintf(f,"%s   ",p.nombre);
        fprintf(f,"%s   ",p.codigo);
        fprintf(f,"%d\n\n",p.precio);*/
    }
    puts("Informaci�n almacenada correctamente.");
   // fclose(f);
}
//Cabecera: busca_producto(producto p, int n)
//Preconcidi�n: Tanto p como n han de estar inicializados, ambos introducidos por el usuario
//Postcondici�n: Busca un producto con el mismo nombre que uno introducido por teclado y devuelve su precio y su c�digo
void busca_producto (producto p, int n)
{
    int i;
    char pb[100];
    puts("Introduzca el nombre del producto que desea buscar:");
    scanf("%s",&pb);

    for (i=0;i<n;i++)
    {
        if (strcmp(pb,p.nombre)==0)
        {
            printf("El producto %s tiene el codigo %s y el precio %d",p.nombre,p.codigo,p.precio);
        }
        else
        {
            puts("No hay productos relacionados con ese nombre.");
        }
    }
}
//Cabecera: void precio (producto p, int n)
//Precondici�n: p y n han de estar inicializados
//Postcondici�n: Busca el producto con el precio m�s alto
void precio (producto p, int n)
{
    int i;
    char mayor[100];
    for (i=0;i<n;i++)
    {
        if (p[i].precio<p[i+1].precio)
            mayor=p[i+1].nombre;
        else
            mayor:p[i];
    }
    printf("El producto %s tiene el mayor precio, que es de %d",p.nombre,p.precio);
}
//Nota: Tiene dos variables. La que tiene el fichero (que quitando el [i] a todos los p[i].--- escribe la informaci�n introducida
//por teclado en un fichero) y la que se basa en el vector que no he conseguido que funcione del todo correctamente.
//En la ultima funci�n (Precio) no he conseguido que resulte nada debido (de nuevo) a c�mo est� pasado el valor, pero no se me ocurre otra forma, al menos hoy.
//No he podido hacer que funcione del todo porque habr� alg�n fallo del que no me halla dado cuenta y crashea al ejecutarlo.
//No se donde puede estar el fallo, pero creo que es en el modo de pasar las variables a las funciones.
