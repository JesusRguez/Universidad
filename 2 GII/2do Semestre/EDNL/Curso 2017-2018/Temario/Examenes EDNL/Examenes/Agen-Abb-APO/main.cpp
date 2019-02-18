#include <iostream>
#include <fstream>
#include "Agen.h"
#include "agen_E-S.h"
#include "operaciones.h"

using namespace std;

typedef char tElto;
const tElto fin = '#'; //fin de lectura

int main()
{
	Agen<tElto> A, B;

	cout << "Lectura del arbol A" << endl;
	rellenarAgen(A, fin); //desde std::cin

	ofstream fs("agen.dat"); //Abrir en fichero de salida
	imprimirAgen(fs, A, fin); //en fichero
	fs.close();
	cout << "\n Arbol A guardado en fichero agen.dat" << endl;

	cout << "Lectura de arbol B de agen.dat" << endl;
	ifstream fe("agen.dat"); //abrir fichero de entrada
	rellenarAgen(fe, B);
	fe.close();

	cout << "Mostrar arbol B" << endl;
	imprimirAgen(B);

	/*Prints Practica 1*/
	cout << "Densidad =  " << calculaDensidad(A) << endl; //Ejercicio 1
}
