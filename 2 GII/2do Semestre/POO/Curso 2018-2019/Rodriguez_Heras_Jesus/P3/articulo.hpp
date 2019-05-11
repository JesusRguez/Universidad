//articulo.hpp

//Jesús Rodríguez Heras 2019

#ifndef ARTICULO_HPP_
#define ARTICULO_HPP_
#include "cadena.hpp"
#include "fecha.hpp"

class Articulo{
public:
	//Constructor de artículo:
	Articulo(const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double& precio, const unsigned& stock);

	//Mostrar referencia:
	const Cadena& referencia() const;

	//Mostrar título:
	const Cadena& titulo() const;

	//Mostrar fecha de publicación:
	const Fecha& f_publi() const;

	//Mostrar precio:
	const double precio() const;
	double& precio();

	//Mostrar stock:
	const unsigned stock() const;
	unsigned& stock();

private:
	Cadena referencia_;
	Cadena titulo_;
	Fecha fecha_publi_;
	double precio_;
	unsigned stock_;
};

//Operador <<:
ostream& operator <<(ostream& os, const Articulo& a);

#endif
