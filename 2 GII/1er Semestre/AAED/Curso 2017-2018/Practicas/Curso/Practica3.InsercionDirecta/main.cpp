 #include <iostream>
#include <time.h>
#include <stdlib.h>
 #include "cronometro.h"
 using namespace::std;

 enum { Tamano = 10000};
 // Cambiar la variable Tamano para ordenar una
 // cantidad diferente de datos

 int aleatorio(int, int);

 /*Prototipo de funcion Imprime */
 void Imprime( int A[]);

 /*prototipo de funcion Recibe */
 void Recibe ( int B[]);

 /*Prototipo de funcion Inserción */
 void Insercion( int C[]);


 int main()

 {           // Abre main

 int Vector[Tamano] = {0, 0};
    // El Vector se ha inicializado a 0
    srand(time(0));
    cronometro c;
    double t;

    cout <<"\nEste programa recibe una serie de %d numeros enteros" << Tamano;
    cout <<" y los ordena por medio del algoritmo de ordenacion burbuja. "<< endl;

    /*Se llena el Vector mediante un llamado a la funcion Recibe*/
    Recibe(Vector);

    /*Se imprime el Vector con las entradas en el orden original */
    cout <<"\nEsta es el orden en que se introdujeron los elementos: " <<endl;
    Imprime(Vector);

    c.activar();

    /*Se ordena el Vector mediante una llamada a la funcion Burbuja*/
    Insercion(Vector);

    c.parar();

    t=c.tiempo();

    /*Se imprime el Vector ordenado */
    cout <<"\nEste es el orden despues de el ordenamiento por inserción directa. " <<endl;
    Imprime(Vector);

    //Imprime el tiempo
    cout <<"El algoritmo tarda: "<<t<<endl;

    return 0;
 }           // Cierra main


 //////////////////////////////////////////////////
 //FUNCION IMPRIME
 /////////////////////////////////////////////////

 void Imprime( int A[] )
 {     // Abre la funcion Imprime

    for ( int j = 0; j < Tamano; j++ )
    {      // Abre for
        cout << "\t" << A[j];

        if ( 0 == j + 1 % 10)
            cout <<endl <<endl;

    }      // Cierra for

    cout <<endl <<endl;
 }     // Cierra la funcion Imprime

 ////////////////////////////////////////////////////////////////////////////
 //FUNCION RECIBE
 //////////////////////////////////////////////////////////////////////////


 void Recibe( int B[] )
 {         // Abre funcion Recibe
     int a=0;
     int b=9;

    for ( int i = 0; i < Tamano; i++ )
    {      // Abre for
        B[i]=aleatorio(a,10000);
    }
 }           // Cierra funcion Recibe



 ///////////////////////////////////////////////
 //FUNCION BURBUJA
 /////////////////////////////////////////////////


  void Insercion( int C[])
 {                 // Abre funcion Insercion

    int temp,i,j;

    for (i=1; i<Tamano; i++)
        {
            temp = C[i];
            j = i - 1;
            while ( (C[j] > temp) && (j >= 0) )
            {
                C[j+1] = C[j];
                j--;
            }
            C[j+1] = temp;         //Cierra for
        }
 }                 // Cierra funcion Inserción


 //Función aleatorio que genera números aleatorios

  int aleatorio(int a, int b)
{
    int resultado;
    resultado=(a+rand()%((b-a)+1));
    return resultado;
}
