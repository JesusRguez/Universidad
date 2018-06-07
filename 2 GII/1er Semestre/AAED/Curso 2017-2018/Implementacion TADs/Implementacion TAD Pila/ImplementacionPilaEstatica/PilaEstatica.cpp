#include <cassert>
#include "PilaEstatica.h"
// Constructor
Pila::Pila(unsigned TamaMax) :
    elementos(new tElemento[TamaMax]),
    Lmax(TamaMax),
    tope_(-1)
{}

// Constructor de copia
Pila::Pila(const Pila& p) :
    elementos(new tElemento[p.Lmax]),
    Lmax(p.Lmax),
    tope_(p.tope_)
{
    for (int i = 0; i <= tope_; i++) // copiar el vector
        elementos[i] = p.elementos[i];
}

// Asignación entre pilas
Pila& Pila::operator =(const Pila& p)
{
    if (this != &p) { // evitar autoasignación
    // Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != p.Lmax) {
            delete [] elementos;
            Lmax = p.Lmax;
            elementos = new tElemento[Lmax];
        }
        // Copiar el vector
        tope_ = p.tope_;
        for (int i = 0; i <= tope_; i++)
            elementos[i] = p.elementos[i];
    }
    return *this;
}

bool Pila::vacia() const
{
    return (tope_ == -1);
}

bool Pila::llena() const
{
    return (tope_ > Lmax - 2);
}

const tElemento& Pila::tope() const
{
    assert(!vacia());
    return elementos[tope_];
}

void Pila::pop()
{
    assert(!vacia());
    --tope_;
}

void Pila::push(const tElemento& x)
{
    assert(!llena());
    ++tope_;
    elementos[tope_] = x;
}

// Destructor
Pila::~Pila()
{
    delete[] elementos;
}
