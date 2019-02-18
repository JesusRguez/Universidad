#include "Agen.h"
#include "agen_E-S.h"
//EJERCICIOS EXAMEN

template <typename T>
double Densidad(const Agen<T>& A){
	return (Grado_Arbol(A)/Cuenta_Hojas(A));
}


template <typename T>
int Cuenta_Hojas(const Agen<T>& A){
	return Cuenta_Hojas_Rec(A.raiz(),A);
}

template <typename T>
int Cuenta_Hojas_Rec(typename Agen<T>::nodo n, const Agen<T>& A){
	typename Agen<T>::nodo hijo;
	int cont = 0;
	if(n == Agen<T>::NODO_NULO)
		return 0;
	else{
		hijo = n;
		if(Es_Hoja(n,A))
			cont += 1;
		else
			cont += Cuenta_Hojas_Rec(A.hijoIzqdo(hijo),A);

		cont+=Cuenta_Hojas_Rec(A.hermDrcho(hijo),A);
		return cont;
	}
}

template <typename T>
bool Es_Hoja(typename Agen<T>::nodo n, const Agen<T>& A){
	if(A.hijoIzqdo(n)==Agen<T>::NODO_NULO)
		return true;
	else
		return false;
}

template<typename T>
int Grado_Rec(typename Agen<T>::nodo n, const Agen<T>& A){
	typename Agen<T>::nodo aux;
	int MaxHijos;
	if(n==Agen<T>::NODO_NULO)
		return 0;
	else{
		MaxHijos=CuentaHijos_Rec(n,A);
		aux=A.hijoIzqdo(n);

		while(aux!=Agen<T>::NODO_NULO){
			MaxHijos=max(MaxHijos,Grado_Rec(aux,A));
			aux=A.hermDrcho(aux);
		}
	}
	return MaxHijos;
}

template <typename T>
int Grado_Arbol(const Agen<T>& A){
	return Grado_Rec(A.raiz(),A);
}

template <typename T>
int CuentaHijos_Rec(typename Agen<T>::nodo n, const Agen<T>& A){
	typename Agen<T>::nodo aux;
	int cont;
	if(n==Agen<T>::NODO_NULO)
		return 0;
	else{
		aux=A.hijoIzqdo(n);
		cont=0;
		while(aux!=Agen<T>::NODO_NULO){
			cont++;
			aux=A.hermDrcho(aux);
		}
		return cont;
	}
}
