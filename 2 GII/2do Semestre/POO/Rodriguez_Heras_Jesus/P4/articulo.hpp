//articulo.hpp

//Jesús Rodríguez Heras 2018

#ifndef ARTICULO_HPP_
#define ARTICULO_HPP_
#include <set>
#include "cadena.hpp"
#include "fecha.hpp"

//Clase Autor:
class Autor{
public:
	//Constructor de Autor:
	Autor(const Cadena& nombre, const Cadena& apellidos, const Cadena& direccion);

	//Mostrar nombre:
	Cadena nombre() const;

	//Mostrar apellidos:
	Cadena apellidos() const;

	//Mostrar direccion:
	Cadena direccion() const;

private:
	Cadena nombre_;
	Cadena apellidos_;
	Cadena direccion_;
};

//Clase Artículo:
class Articulo{
public:
	typedef set<Autor*> Autores;

	//Constructor de artículo:
	Articulo(const Autores& a, const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double precio);

	//Mostrar referencia:
	const Cadena& referencia() const;

	//Mostrar título:
	const Cadena& titulo() const;

	//Mostrar fecha de publicación:
	const Fecha& f_publi() const;

	//Mostrar precio:
	const double precio() const;
	double& precio();

	//Mostrar autores:
	const Autores& autores() const;

	//impresion_especifica:
	virtual void impresion_especifica(ostream& os) const = 0;

	//Destructor virtual:
	virtual ~Articulo(){}

	//Clase Autores_vacios:
	class Autores_vacios{};

private:
	Autores autores_;
	Cadena referencia_;
	Cadena titulo_;
	Fecha fecha_publi_;
	double precio_;
};

//Operador <<:
ostream& operator <<(ostream& os, const Articulo& a);

//Clase ArticuloAlmacenable:
class ArticuloAlmacenable : public Articulo{
public:
	//Constructor de ArticuloAlmacenable:
	ArticuloAlmacenable(const Autores& a, const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double precio, const unsigned stock=0);

	//Mostrar stock;
	unsigned stock() const;

	//Modificar stock:
	unsigned& stock();

protected:
	unsigned stock_;
};

//Clase LibroDigital:
class LibroDigital : public Articulo{
public:
	//Constructor de LibroDigital:
	LibroDigital(const Autores& a, const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double precio, const Fecha& f_expir);

	//Mostrar f_expir:
	const Fecha& f_expir() const;

	//impresion_especifica:
	void impresion_especifica(ostream& os) const;

private:
	const Fecha f_expir_;
};

//Clase Libro:
class Libro : public ArticuloAlmacenable{
public:
	//Constructor de Libro:
	Libro(const Autores& a, const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double precio, const unsigned n_pag, const unsigned stock=0);

	//Mostrar n_pag:
	unsigned n_pag() const;

	//impresion_especifica:
	void impresion_especifica(ostream& os) const;

private:
	const unsigned n_pag_;
};

//Clase Cederron:
class Cederron : public ArticuloAlmacenable{
public:
	//Constructor de Cederron:
	Cederron(const Autores& a, const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double precio, const unsigned tam, const unsigned stock=0);

	//Mostrar tam:
	unsigned tam() const;

	//impresion_especifica:
	void impresion_especifica(ostream& os) const;

private:
	unsigned tam_;
};



#endif
