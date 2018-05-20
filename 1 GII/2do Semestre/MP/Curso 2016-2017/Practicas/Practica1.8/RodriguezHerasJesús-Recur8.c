#include <stdio.h>
#include <stdlib.h>

int llamada (int*, int);
int cambio (int*, int, int, int, char);

int main()
{
    int A[10]={1,2,3,0,5,3,3,9,4,3};
    int n=10;                           //n es el tama�o del vector
    int cambios;

    cambios=llamada(A,n);               //En cambios guardaremos el numero de cambios de tendencia que tenga el vector

    printf("El numero de cambio de tendencias es %d",cambios);      //Imprime el numero de cambios de tendencia

    return 0;
}

//Cabecera: int llamada (int*, int)
//Precondici�n: El vector A y el tama�o del vector "n", han de estar inicializados
//Postcondici�n: Inicializa la funci�n recursiva que calcular� los cambios de tendencia
int llamada(int* A, int n)              //Funci�n llamada a la llamada recursiva
{
    char ta;                            //ta ser� la tendencia actual "+" si es creciente y "-" si es decreciente
    if (A[0]>A[1])
        ta='-';                         //Si es decreciente, ta ser� "-"
    else
        ta='+';                         //Si es creciente, ta ser� "+"
    return(cambio(A,n,0,0,ta));         //Llamada a la funci�n recursiva con los par�metros A (vector), n (n�mero de elementos del vector),
}                                       //i (indice del vector inicializado a 0), cambios (n�mero de cambios de tendencia inicializado a 0)
                                        //y ta (par�metro con la tendencia actual que se inicializar� en funci�n de la comparaci�n llevada
                                        //a cabo en la funci�n llamada con el primer y segundo elemento del vector

//Cabecera: int cambio (int*, int, int, int, char)
//Precondici�n: El vector A y el tama�o del vector "n", han de estar inicializados
//Postcondici�n: Devuelve el numero de cambios de tendencias en el vector A
int cambio (int* A, int n, int i, int cambios, char ta)     //Funci�n recursiva para contar el numero de cambios de tendencias que hay en el vector
{
    if (i==(n-1))
        return cambios;                                     //Si el �ndice del vector es igual al m�ximo n�mero de elementos del vector, la funci�n
    else{                                                   //termina devolviendo el n�mero de cambios actual, es decir, 0, si no es as� continuar� con el bloque else
        if (A[i]>A[i+1] && ta=='+')
            return cambio(A,n,i+1,cambios+1,'-');          //Si el primer elemento es mayor que el segundo y ten�amos tendencia positiva, se incrementa el �ndice, se incrementa cambios, y ta pasa a tener valor "-" (decreciente)
        else{
            if (A[i]>=A[i+1] && ta=='-')
                return cambio(A,n,i+1,cambios,ta);         //Si el primer elemento es mayor o igual que el segundo y ten�amos tendencia negativa, se incrementa el �ndice y se dejan igual tanto cambios como ta.
            else{
                if (A[i]<=A[i+1] && ta=='+')
                    return cambio(A,n,i+1,cambios,ta);     // Si el primer elemento es menor o igual que el segundo y ten�amos tendencia positiva, se incrementa el �ndice y se dejan iugal tanto cambios como ta.
                else{
                    if (A[i]<A[i+1] && ta=='-')
                        return cambio(A,n,i+1,cambios+1,'+');  // Si el primer elemento es menor que el segundo y ten�amos tendencia negativa, se incrementa el �ndice, se incrementa cambios y ta pasa a tener valor "+" (creciente)
                }
            }
        }
    }
}
