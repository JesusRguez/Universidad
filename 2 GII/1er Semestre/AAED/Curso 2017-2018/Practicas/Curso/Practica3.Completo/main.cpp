#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include "cronometro.h"

using namespace std;

//enum { repeticiones = 1000};
// Cambiar la variable repeticiones para ordenar una
// cantidad diferente de datos


/*Prototipo de funcion Imprime */
void Imprime( int A[], int);

/*prototipo de funcion Recibe */
void Recibe ( int B[], int);

/*Prototipo de funcion Burbuja */
void Burbuja( int C[], int);

/*Prototipo de funcion Inserción */
void Insercion( int C[], int);

/*Prototipo de funcion Selección */
void Seleccion( int C[], int);


int main()

{           // Abre main
    int *Vector,*VectorBurbuja,*VectorInsercion,*VectorSeleccion;


    cronometro c;
    double t;
    int repeticiones;

    Vector=(int*)calloc(1,sizeof(int));

    //Vector=new int[1*sizeof(int)];

        for(repeticiones=1000;repeticiones<=20000;repeticiones=repeticiones+1000)
        {

            /*Se llena el Vector mediante un llamado a la funcion Recibe*/
            Recibe(Vector,repeticiones);

            memcpy(VectorBurbuja,Vector,repeticiones*sizeof(int));
            memcpy(VectorInsercion,Vector,repeticiones*sizeof(int));
            memcpy(VectorSeleccion,Vector,repeticiones*sizeof(int));

            c.activar();
            Burbuja(VectorBurbuja,repeticiones);
            c.parar();
            t=c.tiempo();

            cout<<"El tiempo con "<<repeticiones<<" elementos con Burbuja es: "<<t<<endl;



            c.activar();
            Insercion(VectorInsercion,repeticiones);
            c.parar();
            t=c.tiempo();

            cout<<"El tiempo con "<<repeticiones<<" elementos con Insercion Directa es: "<<t<<endl;



            c.activar();
            Seleccion(VectorSeleccion,repeticiones);
            c.parar();
            t=c.tiempo();

            cout<<"El tiempo con "<<repeticiones<<" elementos con Seleccion Directa es: "<<t<<endl;

            VectorBurbuja = (int*) realloc (Vector, 1000 * sizeof(int));
            VectorInsercion = (int*) realloc (Vector, 1000 * sizeof(int));
            VectorSeleccion = (int*) realloc (Vector, 1000 * sizeof(int));
        }

    return 0;
}


//////////////////////////////////////////////////
//FUNCION IMPRIME
/////////////////////////////////////////////////

void Imprime( int A[], int repeticiones)
{     // Abre la funcion Imprime

    for ( int j = 0; j < repeticiones; j++ )
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


void Recibe( int B[], int tam)
{         // Abre funcion Recibe
    for ( int i = 0; i < tam; i++ )
    {      // Abre for
        B=(int*)realloc(B,i*sizeof(int));
    }
    random_shuffle(B,B+tam);

}         // Cierra funcion Recibe

///////////////////////////////////////////////
//FUNCION BURBUJA
/////////////////////////////////////////////////


void Burbuja( int C[], int repeticiones)
{                 // Abre funcion Burbuja

    int temporal;

    for ( int m = 0; m < repeticiones - 1; m++ )
    for ( int n = 0; n <= repeticiones - 1; n++ )
        {    // Abre for
            if ( C[n] > C[n + 1] )
            {    // Abre if
                temporal = C[n];
                C[n] = C[n + 1];
                C[n + 1] = temporal;
            }    // Cierra if
        }         //Cierra for
}                 // Cierra funcion Burbuja

///////////////////////////////////////////////
//FUNCION INSERCION
/////////////////////////////////////////////////


void Insercion( int C[], int repeticiones)
{                 // Abre funcion Insercion

    int temp,i,j;

    for (i=1; i<repeticiones; i++)
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

///////////////////////////////////////////////
//FUNCION SELECCION
/////////////////////////////////////////////////


void Seleccion( int C[], int repeticiones)
{                 // Abre funcion Selección

    int min, tmp;

/* recorremos todo el vector */
    for(int i = 0; i < repeticiones - 1; i++) {
      /* suponemos que es el primero */
      min = i;
      /* recorremos la parte no ordenada */
      for(int j = i+1; j < repeticiones; j++) {
         /* buscamos el de menor peso */
         if(C[j] < C[min]) min = j;
      }
      /* intercambio posicion i por el de menor peso */
      tmp = C[i];
      C[i] = C[min];
      C[min] = tmp;
   }
}

