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

 /*Prototipo de funcion Burbuja */
 void Burbuja( int C[]);


 int main()
 {           // Abre main
    srand(time(0));
    cronometro c;
    double t;

    int Vector[Tamano] = {0, 0};
    // El Vector se ha inicializado a 0

    cout <<"\nEste programa recibe una serie de %d numeros enteros" << Tamano;
    cout <<" y los ordena por medio del algoritmo de ordenacion burbuja. "<< endl;

    /*Se llena el Vector mediante un llamado a la funcion Recibe*/
    Recibe(Vector);

    /*Se imprime el Vector con las entradas en el orden original */
    cout <<"\nEsta es el orden en que se introdujeron los elementos: " <<endl;
    Imprime(Vector);

    c.activar(); //Se debería activar el cronómetro

    /*Se ordena el Vector mediante una llamada a la funcion Burbuja*/
    Burbuja(Vector);

    c.parar();   // Se debería parar el cronómetro

    t=c.tiempo();

    /*Se imprime el Vector ordenado */
    cout <<"\nEste es el orden despues de el ordenamiento segun el algoritmo burbuja. " <<endl;
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
 }         // Cierra funcion Recibe



 ///////////////////////////////////////////////
 //FUNCION BURBUJA
 /////////////////////////////////////////////////


  void Burbuja( int C[])
 {                 // Abre funcion Burbuja

    int temporal;

    for ( int m = 0; m < Tamano - 1; m++ )
    for ( int n = 0; n <= Tamano - 1; n++ )
        {    // Abre for
            if ( C[n] > C[n + 1] )
            {    // Abre if
                temporal = C[n];
                C[n] = C[n + 1];
                C[n + 1] = temporal;
            }    // Cierra if
        }         //Cierra for
 }                 // Cierra funcion Burbuja


 //Función aleatorio que genera números aleatorios

 int aleatorio(int a, int b)
{
    int resultado;
    resultado=(a+rand()%((b-a)+1));
    return resultado;
}
