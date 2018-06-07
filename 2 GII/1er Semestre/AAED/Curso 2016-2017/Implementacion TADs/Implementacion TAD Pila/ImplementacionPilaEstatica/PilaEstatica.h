#ifndef _tElemento_
#define _tElemento_
    typedef int tElemento; // por ejemplo
#endif // _tElemento_
#ifndef PILAESTATICA_H
#define PILAESTATICA_H
class Pila {
public:
    explicit Pila(unsigned TamaMax); // constructor
    Pila(const Pila& p); // ctor. de copia
    Pila& operator =(const Pila& p); // asignaci�n entre pilas
    bool vacia() const;
    bool llena() const; // Requerida por la implementaci�n
    const tElemento& tope() const;
    void pop();
    void push(const tElemento& x);
    ~Pila(); // destructor
private:
    tElemento *elementos; // vector de elementos
    int Lmax; // tama�o del vector
    int tope_; // posici�n del tope
};
#endif // PILAESTATICA_H
