//articulo.cpp

//Jesús Rodríguez Heras 2019

#include "articulo.hpp"

//Constructor de artículo:
Articulo::Articulo(const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double& precio, const unsigned& stock):referencia_(referencia), titulo_(titulo), fecha_publi_(fecha_publi), precio_(precio), stock_(stock){};

//Operador <<:
ostream& operator <<(ostream& os, const Articulo& a) {
    os << "[" << a.referencia() << "]" << "\"" << a.titulo() << "\"," << a.f_publi().anno() << ". " << a.precio() << " €" << endl;
    return os;
}
