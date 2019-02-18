
#include "Abb.h"

template <typename T>
bool esAVL (Abb<T> const& arbol)
{
	return esAVL_rec(arbol);

}

template <typename T>
bool esAVL_rec(Abb<T> const& arbol)
{
	if (!arbol.vacio())
	{
		int a=factorequil(arbol);
		if (a <= 1 && a >= -1)
			return (true && esAVL_rec(arbol.izqdo()) && esAVL_rec(arbol.drcho()));
		else
			return false;
	}
	return true;
}

template <typename T>
int factorequil (Abb<T> const& arbol)
{
	return altura(arbol.drcho()) - altura(arbol.izqdo());
}

template<typename T>
int altura(Abb<T> const& arbol)
{
	if(arbol.vacio())
	{
		return -1;
	}
	else
	{
		int maxalt = max(1 + altura(arbol.izqdo()), 1 + altura(arbol.drcho()));
		return maxalt;
	}
}
