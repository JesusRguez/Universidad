template<class T>
T infimo(T x, const Abb<T>& A)
{
    Abb<T> aux;

    if(!A.vacio())
        aux = A.buscar(x);

    if(!aux.vacio())
        return x;
    else
        return infimoRec(x, A, minimo(A));
}

template<class T>
T supremo(T x, const Abb<T>& A)
{
    Abb<T> aux;

    if(!A.vacio())
        aux = A.buscar(x);

    if(!aux.vacio())
        return x;
    else
        return supremoRec(x, A, maximo(A));
}

template<class T>
T infimoRec(const T& x, const Abb<T>& A, T maxi)
{
    if(A.vacio())
        return maxi;
    else
    {
        if(x > A.elemento()){
            maxi = max(maxi, A.elemento());
            infimoRec(x, A.drcho(), maxi);
        }
        else
            infimoRec(x, A.izqdo(), maxi);
    }
}

template<class T>
T minimo(const Abb<T>& A)
{
    if(A.izqdo().vacio())
        return A.elemento();
    else
        return minimo(A.izqdo());
}

template<class T>
T supremoRec(const T& x, const Abb<T>& A, T mini)
{
    if(A.vacio())
        return mini;
    else
    {
        if(x > A.elemento())
            supremoRec(x, A.drcho(), mini);
        else {
            mini = min(mini, A.elemento());
            supremoRec(x, A.izqdo(), mini);
        }
    }
}

template<class T>
T maximo(const Abb<T>& A)
{
    if(A.drcho().vacio())
        return A.elemento();
    else
        return maximo(A.drcho());
}
