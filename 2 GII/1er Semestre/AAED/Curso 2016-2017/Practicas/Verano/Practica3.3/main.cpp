#include <iostream>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include "cronometro.h"

using namespace std;

void Imprime(int A[]);
void Recibe(int B[]);
void Burbuja(int C[]);
void Insercion(int C[]);
void Seleccion(int C[]);
int aleatorio(int a, int b);

enum {Tamano=10000};

int main()
{
    srand(time(0));
    cronometro c;
    double t;
    int s;

    int v[Tamano]={0, 0}, v1[Tamano]={0, 0}, v2[Tamano]={0, 0};

    Recibe(v);

    memcpy(v1, v, sizeof v);
    memcpy(v2, v, sizeof v);

    cout<<"Que metodo de ordenacion desea usar?"<<endl<<"1. Burbuja"<<endl<<"2. Insercion"<<endl<<"3. Seleccion"<<endl<<"4. Todos"<<endl;
    cin>>s;

    switch(s)
    {
    case 1:
        c.activar();
        Burbuja(v);
        c.parar();
        t=c.tiempo();
        cout<<"El algoritmo de burbuja ha tardado "<<t<<" segundos en ordenar el vector autogenerado de "<<Tamano<<" elementos."<<endl;
        break;
    case 2:
        c.activar();
        Insercion(v);
        c.parar();
        t=c.tiempo();
        cout<<"El algoritmo de insercion ha tardado "<<t<<" segundos en ordenar el vector autogenerado de "<<Tamano<<" elementos."<<endl;
        break;
    case 3:
        c.activar();
        Seleccion(v);
        c.parar();
        t=c.tiempo();
        cout<<"El algoritmo de seleccion ha tardado "<<t<<" segundos en ordenar el vector autogenerado de "<<Tamano<<" elementos."<<endl;
        break;
    case 4:
        c.activar();
        Burbuja(v);
        c.parar();
        t=c.tiempo();
        cout<<"El algoritmo de burbuja ha tardado "<<t<<" segundos en ordenar el vector autogenerado de "<<Tamano<<" elementos."<<endl;

        c.activar();
        Insercion(v1);
        c.parar();
        t=c.tiempo();
        cout<<"El algoritmo de insercion ha tardado "<<t<<" segundos en ordenar el vector autogenerado de "<<Tamano<<" elementos."<<endl;

        c.activar();
        Seleccion(v2);
        c.parar();
        t=c.tiempo();
        cout<<"El algoritmo de seleccion ha tardado "<<t<<" segundos en ordenar el vector autogenerado de "<<Tamano<<" elementos."<<endl;
        break;
    }

    return 0;
}

/////////////////////////////////////////////////
//FUNCION IMPRIME
/////////////////////////////////////////////////

void Imprime(int A[])
{     // Abre la funcion Imprime

    for(int j=0; j<Tamano; j++)
    {      // Abre for
        cout<<"\t"<<A[j];

        if(0==j+1%10)
            cout<<endl<<endl;

    }      // Cierra for

    cout<<endl<<endl;
}     // Cierra la funcion Imprime

////////////////////////////////////////////////////////////////////////////
//FUNCION RECIBE
//////////////////////////////////////////////////////////////////////////


void Recibe(int B[])
{         // Abre funcion Recibe
    int a=0;

    for (int i=0; i<Tamano; i++)
    {      // Abre for
        B[i]=aleatorio(a,Tamano);
    }
}         // Cierra funcion Recibe

void Burbuja(int C[])
{                 // Abre funcion Burbuja

    int temporal;

    for(int m=0; m<Tamano-1; m++)
    {
        for(int n=0; n<=Tamano-1; n++)
        {    // Abre for
            if(C[n]>C[n+1])
            {    // Abre if
                temporal=C[n];
                C[n]=C[n+1];
                C[n+1]=temporal;
            }    // Cierra if
        }         //Cierra for
    }

}                 // Cierra funcion Burbuja


void Insercion(int C[])
{                 // Abre funcion Insercion

    int temp,i,j;

    for(i=1; i<Tamano; i++)
        {
            temp=C[i];
            j=i-1;
            while((C[j]>temp) && (j>=0))
            {
                C[j+1]=C[j];
                j--;
            }
            C[j+1]=temp;         //Cierra for
        }
}                 // Cierra funcion Inserción


void Seleccion(int C[])
{                 // Abre funcion Selección

    int min, tmp;

/* recorremos todo el vector */
    for(int i=0; i<Tamano-1; i++)
    {
      /* suponemos que es el primero */
        min=i;
      /* recorremos la parte no ordenada */
        for(int j=i+1; j<Tamano; j++)
        {
         /* buscamos el de menor peso */
            if(C[j] < C[min])
                min = j;
        }
      /* intercambio posicion i por el de menor peso */
      tmp=C[i];
      C[i]=C[min];
      C[min]=tmp;
    }
}


//Función aleatorio que genera números aleatorios

int aleatorio(int a, int b)
{
    int resultado;
    resultado=(a+rand()%((b-a)+1));
    return resultado;
}
