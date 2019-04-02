//articulo.cpp

//Jesús Rodríguez Heras 2018

#include "articulo.hpp"
#include <iomanip>

//Constructor de Autor:
Autor::Autor(const Cadena& nombre, const Cadena& apellidos, const Cadena& direccion):nombre_(nombre), apellidos_(apellidos), direccion_(direccion){}

//Constructor de artículo:
Articulo::Articulo(const Articulo::Autores& a, const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double precio):autores_(a), referencia_(referencia), titulo_(titulo), fecha_publi_(fecha_publi), precio_(precio){
	if(a.empty()){
		throw Autores_vacios();
	}
}

//Operador <<:
ostream& operator <<(ostream& os, const Articulo& a) {
	os <<"[" << a.referencia() << "] "<< "\"" << a.titulo() << "\", de ";

  	const auto& autores = a.autores();

  	auto iter = autores.begin();
  	os << (*iter)->apellidos();
  	while (++iter != autores.end()){
    	os << ", " << (*iter)->apellidos();
  	}

	os << ". " << a.f_publi().anno() << ". " << fixed << setprecision(2) << a.precio() << " €\n\t";

  	a.impresion_especifica(os);

	return os;
}

//Constructor de ArticuloAlmacenable:
ArticuloAlmacenable::ArticuloAlmacenable(const Articulo::Autores& a, const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double precio, const unsigned stock):Articulo(a, referencia, titulo, fecha_publi, precio), stock_(stock){}

//Modificar stock:
unsigned& ArticuloAlmacenable::stock(){
	return stock_;
}

//Constructor de LibroDigital:
LibroDigital::LibroDigital(const Articulo::Autores& a, const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double precio, const Fecha& f_expir):Articulo(a, referencia, titulo, fecha_publi, precio), f_expir_(f_expir){}

//Impresion_especifica de LibroDigital:
void LibroDigital::impresion_especifica(ostream& os) const{
	os << "A la venta hasta el " << f_expir_ << ".";
}

//Constructor de Libro:
Libro::Libro(const Articulo::Autores& a, const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double precio, const unsigned n_pag, const unsigned stock):ArticuloAlmacenable(a, referencia, titulo, fecha_publi, precio, stock), n_pag_(n_pag){}

//Impresion_especifica de Libro:
void Libro::impresion_especifica(ostream& os) const{
	os << n_pag_ << " págs., " << stock_ << " unidades.";
}

//Constructor de Cederron:
Cederron::Cederron(const Articulo::Autores& a, const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double precio, const unsigned tam, const unsigned stock):ArticuloAlmacenable(a, referencia, titulo, fecha_publi, precio, stock), tam_(tam){}

//Impresion_especifica de Cederron:
void Cederron::impresion_especifica(ostream& os) const{
	os << tam_ << " MB, " << stock_ << " unidades.";
}
