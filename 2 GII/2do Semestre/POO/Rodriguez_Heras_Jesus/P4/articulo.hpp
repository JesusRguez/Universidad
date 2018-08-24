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
	inline Cadena nombre() const noexcept { return nombre_; }

	//Mostrar apellidos:
	inline Cadena apellidos() const noexcept { return apellidos_; }

	//Mostrar direccion:
	inline Cadena direccion() const noexcept { return direccion_; }

private:
	Cadena nombre_;
	Cadena apellidos_;
	Cadena direccion_;
};

//Clase Artículo:
class Articulo{
public:

	//Clase Autores_vacios:
	class Autores_vacios{};

	typedef set<Autor*> Autores;

	//Constructor de artículo:
	Articulo(const Autores& a, const Cadena& referencia, const Cadena& titulo, const Fecha& fecha_publi, const double precio);

	//Mostrar referencia:
	inline const Cadena& referencia() const { return referencia_; }

	//Mostrar título:
	inline const Cadena& titulo() const { return titulo_; }

	//Mostrar fecha de publicación:
	inline const Fecha& f_publi() const { return fecha_publi_; }

	//Mostrar precio:
	inline const double precio() const { return precio_; }
	inline double& precio() { return precio_; }

	//Mostrar autores:
	inline const Autores& autores() const { return autores_; }

	//impresion_especifica:
	virtual void impresion_especifica(ostream& os) const = 0;

	//Destructor virtual:
	virtual ~Articulo(){}

private:
	const Autores autores_;
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
	inline unsigned stock() const { return stock_; }

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
	inline const Fecha& f_expir() const { return f_expir_; }

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
	inline unsigned n_pag() const { return n_pag_; }

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
	inline unsigned tam() const { return tam_; }

	//impresion_especifica:
	void impresion_especifica(ostream& os) const;

private:
	unsigned tam_;
};

#endif
