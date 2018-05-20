#include <stdio.h>
#include <stdlib.h>

int llamada (int*, int);
int cambio (int*, int, int, int, char);

int main()
{
    int A[10]={1,2,3,0,5,3,3,9,4,3};
    int n=10;                           //n es el tamaño del vector
    int cambios;

    cambios=llamada(A,n);               //En cambios guardaremos el numero de cambios de tendencia que tenga el vector

    printf("El numero de cambio de tendencias es %d",cambios);      //Imprime el numero de cambios de tendencia

    return 0;
}

//Cabecera: int llamada (int*, int)
//Precondición: El vector A y el tamaño del vector "n", han de estar inicializados
//Postcondición: Inicializa la función recursiva que calculará los cambios de tendencia
int llamada(int* A, int n)              //Función llamada a la llamada recursiva
{
    char ta;                            //ta será la tendencia actual "+" si es creciente y "-" si es decreciente
    if (A[0]>A[1])
        ta='-';                         //Si es decreciente, ta será "-"
    else
        ta='+';                         //Si es creciente, ta será "+"
    return(cambio(A,n,0,0,ta));         //Llamada a la función recursiva con los parámetros A (vector), n (número de elementos del vector),
}                                       //i (indice del vector inicializado a 0), cambios (número de cambios de tendencia inicializado a 0)
                                        //y ta (parámetro con la tendencia actual que se inicializará en función de la comparación llevada
                                        //a cabo en la función llamada con el primer y segundo elemento del vector

//Cabecera: int cambio (int*, int, int, int, char)
//Precondición: El vector A y el tamaño del vector "n", han de estar inicializados
//Postcondición: Devuelve el numero de cambios de tendencias en el vector A
int cambio (int* A, int n, int i, int cambios, char ta)     //Función recursiva para contar el numero de cambios de tendencias que hay en el vector
{
    if (i==(n-1))
        return cambios;                                     //Si el índice del vector es igual al máximo número de elementos del vector, la función
    else{                                                   //termina devolviendo el número de cambios actual, es decir, 0, si no es así continuará con el bloque else
        if (A[i]>A[i+1] && ta=='+')
            return cambio(A,n,i+1,cambios+1,'-');          //Si el primer elemento es mayor que el segundo y teníamos tendencia positiva, se incrementa el índice, se incrementa cambios, y ta pasa a tener valor "-" (decreciente)
        else{
            if (A[i]>=A[i+1] && ta=='-')
                return cambio(A,n,i+1,cambios,ta);         //Si el primer elemento es mayor o igual que el segundo y teníamos tendencia negativa, se incrementa el índice y se dejan igual tanto cambios como ta.
            else{
                if (A[i]<=A[i+1] && ta=='+')
                    return cambio(A,n,i+1,cambios,ta);     // Si el primer elemento es menor o igual que el segundo y teníamos tendencia positiva, se incrementa el índice y se dejan iugal tanto cambios como ta.
                else{
                    if (A[i]<A[i+1] && ta=='-')
                        return cambio(A,n,i+1,cambios+1,'+');  // Si el primer elemento es menor que el segundo y teníamos tendencia negativa, se incrementa el índice, se incrementa cambios y ta pasa a tener valor "+" (creciente)
                }
            }
        }
    }
}
