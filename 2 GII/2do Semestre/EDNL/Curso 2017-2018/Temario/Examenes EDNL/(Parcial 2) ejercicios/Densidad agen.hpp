#include "Agen.h"


template <typename T>
double densidadAgen(Agen<T> const& arbol)
{
	return double(grado(arbol) / nhojas(arbol));
}

template <typename T>
int grado(Agen<T> const& arbol)
{
	return grado_rec(arbol.raiz(), arbol);
}

template <typename T>
T max_(T a, T b)
{
	if (a>=b) return a;
	else return b;
}

template<typename T>
int grado_rec(typename Agen<T>::nodo n, Agen<T> const& arbol)
{
	typename Agen<T>::nodo hijo;
	int maxgrado;
	if (n == Agen<T>::NODO_NULO)
		return 0;
	else
	{
		maxgrado = numhijos(n, arbol);
		hijo = arbol.hijoIzqdo(n);

		while(hijo != Agen<T>::NODO_NULO)
		{
			 maxgrado = max_(maxgrado, grado_rec(hijo, arbol));
			 hijo = arbol.hermDrcho(hijo);
		}
		return maxgrado;
	}
}

template<typename T>
int numhijos(typename Agen<T>::nodo n, Agen<T> const& arbol)
{
		typename Agen<T>::nodo hijo;
		int num_hijos=0;

		hijo=arbol.hijoIzqdo(n);

		while (hijo != Agen<T>::NODO_NULO)
		{
			num_hijos++;
			hijo = arbol.hermDrcho(hijo);
		}
		return num_hijos;
}

template <typename T>
int nhojas(Agen<T> const& arbol)
{
	nhojas_rec(arbol.raiz(), arbol);
}

template <typename T>
int nhojas_rec(typename Agen<T>::nodo n, Agen<T> const& arbol)
{
	typename Agen<T>::nodo hijo;
	int cont=0;
	if(n == Agen<T>::NODO_NULO) return 0;                     // Solo vale para comprobar la raiz, nunca va a llegar un nodo nulo
	else
	{
		hijo = arbol.hijoIzqdo(n);
		if(hijo == Agen<T>::NODO_NULO)         // si yo soy hoja
			cont += 1;
		else
		{
			while(hijo != Agen<T>::NODO_NULO)                    // llamo con mis hermanos recursivamente a ver si son hoja o no;
			{
				cont += nhojas_rec(arbol.hermDrcho(hijo), arbol);
				hijo = arbol.hermDrcho(hijo);
			}
		}
		cont += nhojas_rec(arbol.hijoIzqdo(n), arbol);
		return cont;

	}
}


