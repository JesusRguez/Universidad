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
	inline const Cadena& referencia() const { return referencia_; }

	//Mostrar título:
	inline const Cadena& titulo() const { return titulo_; }

	//Mostrar fecha de publicación:
	inline const Fecha& f_publi() const { return fecha_publi_; }

	//Mostrar precio:
	inline const double precio() const { return precio_; }
	inline double& precio() { return precio_; }

	//Mostrar stock:
	inline const unsigned stock() const { return stock_; }
	inline unsigned& stock() { return stock_; }

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
