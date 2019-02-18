/*Contar cuantos nodos son nostalgicos
Un nodo es nostalgico si tiene mas ancestros que descendientes*/

template<class T>
int nostalgicos(const Abin<T>& A)
{ return nostalgicosRec(A.raizB(), A); }

template<class T>
int nostalgicosRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
    {
        if(esNostalgico(n, A))
            return 1 + nostalgicosRec(A.hijoIzqdoB(n), A)
                + nostalgicosRec(A.hijoDrchoB(n), A);
        else
            return nostalgicosRec(A.hijoIzqdoB(n), A)
                + nostalgicosRec(A.hijoDrchoB(n), A);
    }
}

template<class T>
bool esNostalgico(typename Abin<T>::nodo n, const Abin<T>& A)
{
    int a = cuentaAncestros(n, A);
    int d = cuentaDescendientes(n, A) - 1;
    cout << "tiene " << a << " ancenstros y " << d << " des." << endl;

    if(a > d)
    {
        cout << "El nodo " << &n << " es nostalgico" << endl;
        return true;
    }
    else {
        cout << "El nodo " << &n << " NO es nostalgico" << endl;
        return false;
    }
}

template<class T>
int cuentaAncestros(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == A.raizB())
        return 0;
    else
        return 1 + cuentaAncestros(A.padreB(n), A);
}

template<class T>
int cuentaDescendientes(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + cuentaDescendientes(A.hijoIzqdoB(n), A)
            + cuentaDescendientes(A.hijoDrchoB(n), A);
}
