/*Contar nodos prosperos*/

/*Un nodo es prospero si es mas rico que sus ancestros y
  mas pobre que sus descendientes */

template<class T>
int cuentaProsperos(const Abin<T>& A)
{ return cuentaProsperosRec(A.raizB(), A); }

template<class T>
int cuentaProsperosRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == A.NODO_NULO)
        return 0;
    else
    {
        if(esProspero(n, A)) {
            cout << "Soy el nodo " << n << " tengo el valor " << A.elemento(n)
                 << " Y SOY PROSPERO" << endl;
            return 1 + cuentaProsperosRec(A.hijoIzqdoB(n), A)
                + cuentaProsperosRec(A.hijoDrchoB(n), A);

        }
        else{
            cout << "Soy el nodo " << n << " tengo el valor " << A.elemento(n)
                 << " Y-- NO --SOY PROSPERO" << endl;
            return cuentaProsperosRec(A.hijoIzqdoB(n), A)
                + cuentaProsperosRec(A.hijoDrchoB(n), A);
        }
    }
}

template<class T>
bool esProspero(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(masRicoQueAncestros(n, n, A) and masPobreQueDescendientes(n, n, A))
        return true;
    else
        return false;
}

template<class T>
bool masRicoQueAncestros(typename Abin<T>::nodo n, typename Abin<T>::nodo r, const Abin<T>& A)
{
    if(A.padreB(r) == A.NODO_NULO)
        return true;
    else if(A.elemento(n) > A.elemento(A.padreB(r)))
        return masRicoQueAncestros(n, A.padreB(r), A);
    else
        return false;
}

template<class T>
bool masPobreQueDescendientes(typename Abin<T>::nodo n, typename Abin<T>::nodo r, const Abin<T>& A)
{
    if(A.hijoIzqdoB(r) == A.NODO_NULO and A.hijoDrchoB(r) == A.NODO_NULO)
        return true;
    else
    {
        if(A.hijoIzqdoB(r) != A.NODO_NULO)
            if(A.elemento(n) < A.elemento(A.hijoIzqdoB(r))) {
                if(masPobreQueDescendientes(n, A.hijoIzqdoB(r), A))
                    if(A.hijoDrchoB(r) != A.NODO_NULO)
                        if(A.elemento(n) < A.elemento(A.hijoDrchoB(r)))
                            return masPobreQueDescendientes(n, A.hijoDrchoB(r), A);
                        else
                            return false;
            }
            else
                return false;

        if(A.hijoDrchoB(r) != A.NODO_NULO)
            if(A.elemento(n) < A.elemento(A.hijoDrchoB(r)))
                return masPobreQueDescendientes(n, A.hijoDrchoB(r), A);
            else
                return false;
    }
}
