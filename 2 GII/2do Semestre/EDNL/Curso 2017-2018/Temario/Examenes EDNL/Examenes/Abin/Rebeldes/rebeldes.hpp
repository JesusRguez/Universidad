/*Se dice de nodo rebelde aquel cuyas ideas
son diferentes a la de la mayoría de sus ancestros. Dado un árbol binario
cualquiera calcular el número de nodos rebeldes de dicho árbol.

Trabajaremos con un arbol de booleanos, donde False seran las ideas de derecha
y True las de izquierda*/

template<class T>
int cuentaRebeldes(const Abin<T>& A)
{ return cuentaRebeldesRec(A.raizB(), A, 0, 0); }

template<class T>
int cuentaRebeldesRec(typename Abin<T>::nodo n, const Abin<T>& A,
                      unsigned n_true, unsigned n_false)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else if(A.elemento(n) == 'T' and n_false > n_true++)
        return 1
            + cuentaRebeldesRec(A.hijoIzqdoB(n), A, n_true, n_false)
            + cuentaRebeldesRec(A.hijoDrchoB(n), A, n_true, n_false);
    else if(A.elemento(n) == 'F' and n_true > n_false++)
        return 1
            + cuentaRebeldesRec(A.hijoIzqdoB(n), A, n_true, n_false)
            + cuentaRebeldesRec(A.hijoDrchoB(n), A, n_true, n_false);
    else
        return cuentaRebeldesRec(A.hijoIzqdoB(n), A, n_true, n_false)
            + cuentaRebeldesRec(A.hijoDrchoB(n), A, n_true, n_false);
}
