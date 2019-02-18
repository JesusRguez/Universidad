//contar cuantos nodos tienen exactamente 3 nietos

template<class T>
int cuentaNietos(const Abin<T>& A)
{ return cuentaNietosRec(A.raizB(), A); }

template<class T>
int cuentaNietosRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
    {
        if(tiene3nietos(n, A))
            return 1 + cuentaNietosRec(A.hijoIzqdoB(n), A)
                + cuentaNietosRec(A.hijoDrchoB(n), A);
        else
            return cuentaNietosRec(A.hijoIzqdoB(n), A)
                + cuentaNietosRec(A.hijoDrchoB(n), A);
    }
}

template<class T>
bool tiene3nietos(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return false;
    else
    {
        if(cuentaHijos(A.hijoIzqdoB(n), A) == 2
           and cuentaHijos(A.hijoDrchoB(n), A) == 1)
            return true;

        else if(cuentaHijos(A.hijoIzqdoB(n), A) == 1
                and cuentaHijos(A.hijoDrchoB(n), A) == 2)
            return true;

        else
            return false;
    }
}

template<class T>
int cuentaHijos(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        if(A.hijoIzqdoB(n) != Abin<T>::NODO_NULO
           and A.hijoDrchoB(n) != Abin<T>::NODO_NULO)
            return 2;
        else if(A.hijoIzqdoB(n) == Abin<T>::NODO_NULO
                and A.hijoDrchoB(n) == Abin<T>::NODO_NULO)
            return 0;
        else
            return 1;
}
