#include "ListaEnlazada.h"
template <typename T> class Conjunto{
    struct nodo;
public:
    typedef nodo* posicion;
    Conjunto();
    bool vacia();
    void insertar(T elemento);
    void eliminar(T elemento);
    posicion buscar(T elemento);
    Conjunto<T> unionC(Conjunto<T> B);
    Conjunto<T> interseccionC(Conjunto<T> B);
    Conjunto<T> diferenciaC(Conjunto<T> B);
    T primero();
private:
    Lista<T> L;

};

template <typename T> bool Conjunto<T>::vacia(){
    return (L.primera() == L.fin());
}

template <typename T> void Conjunto<T>::insertar(T elemento){
    if(L.buscar(elemento)==L.fin()){
        L.insertar(elemento, L.fin());
    }
}

template <typename T> void Conjunto<T>::eliminar(T elemento){
    posicion p;
    if(p=L.buscar(elemento)!=L.fin()){
        L.eliminar(p);
    }
}

template <typename T> <typename posicion> Conjunto<T>::buscar(T elemento){
    return L.buscar(elemento);
}

template <typename T> Conjunto<T> Conjunto<T>::unionC(Conjunto<T> B){
    while(!vacia()){
        B.insertar(L.elemento(L.primera()));
        L.eliminar(L.primera());
    }
    return B;
}

template <typename T> Conjunto<T> Conjunto<T>::interseccionC(Conjunto<T> B){
    while(L.primera()!=L.fin()){
        if(B.primero()!=L.elemento(L.buscar(B.primero()))){
            L.eliminar(L.buscar(B.primero()));
            B.eliminar(B.primero());
        }
    }
    return B;
}

template <typename T> Conjunto<T> Conjunto<T>::diferenciaC(Conjunto B){

}

template <typename T> T Conjunto<T>::primero(){
    return L.elemento(L.primera());
}
