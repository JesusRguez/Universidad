//articulo.cpp

//Jesús Rodríguez Heras 2018

#include "articulo.hpp"

//Constructor de artículo:
Articulo::Articulo(const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double& precio, const unsigned& stock):referencia_(referencia), titulo_(titulo), fecha_publi_(fecha_publi), precio_(precio), stock_(stock){};

//Mostrar referencia:
const Cadena& Articulo::referencia() const{
	return referencia_;
}

//Mostrar título:
const Cadena& Articulo::titulo() const{
	return titulo_;
}

//Mostrar fecha de publicación:
const Fecha& Articulo::f_publi() const{
	return fecha_publi_;
}

//Mostrar precio:
const double Articulo::precio() const{
	return precio_;
}

double& Articulo::precio(){
	return precio_;
}

//Mostrar stock:
const unsigned Articulo::stock() const{
	return stock_;
}

unsigned& Articulo::stock(){
	return stock_;
}

//Operador <<:
ostream& operator <<(ostream& os, const Articulo& a) {
    os << "[" << a.referencia() << "]" << "\"" << a.titulo() << "\"," << a.f_publi().anno() << ". " << a.precio() << " €" << endl;
    return os;
}
