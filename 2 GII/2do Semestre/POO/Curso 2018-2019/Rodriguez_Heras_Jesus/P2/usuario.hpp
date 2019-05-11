//usuario.hpp

//Jesús Rodríguez Heras 2019

#ifndef USUARIO_HPP_
#define USUARIO_HPP_
#include "articulo.hpp"
#include "cadena.hpp"
#include "tarjeta.hpp"
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <unistd.h>
#include <ctime>
//Clase clave:
class Clave{
public:
	//Tipo enumerado para la clase Incorrecta:
	enum Razon{CORTA, ERROR_CRYPT};

	//Constructor de clave:
	Clave(const char* contrasena);

	//Mostrar clave cifrada:
	const Cadena& clave() const;

	//Verificar clave:
	bool verifica(const char* posible_contrasena) const;

	//Clase Incorrecta:
	class Incorrecta{
	  public:
	  	//Constructor de Incorrecta:
	    Incorrecta(const Clave::Razon razon):razon_(razon){}

	    //Razón:
	    Clave::Razon razon() const {return razon_;}

	  private:
	    Clave::Razon razon_;
	};

private:
	Cadena clave_;
};

class Usuario{
public:

	//Contenido del carrito:
	typedef map<Numero, Tarjeta*> Tarjetas;

	//Articulos:
	typedef unordered_map<Articulo*, unsigned> Articulos;

	//Usuarios del sistema:
	typedef unordered_set<Cadena> Usuarios;

	//Constructor de usuario:
	Usuario(const Cadena& id, const Cadena& nombre, const Cadena& apellidos, const Cadena& direccion, const Clave& contrasena);

	//Evitar copia:
	Usuario(const Usuario&) = delete;

	//Evitar asignación:
    Usuario& operator = (const Usuario&) = delete;

	//Destructuor de usuario:
	~Usuario();

	//Ver si es titular de una tarjeta:
	void es_titular_de(Tarjeta& t);

	//Ver si no es titular de una tarjeta:
	void no_es_titular_de(Tarjeta& t);

	//Mostrar id:
	Cadena id() const;

	//Mostrar nombre:
	Cadena nombre() const;

	//Mostrar apellidos:
	Cadena apellidos() const;

	//Mostrar dirección:
	Cadena direccion() const;

	//Mostrar tarjetas:
	const Tarjetas& tarjetas() const;

	//Asociacion unidireccional:
	void compra(Articulo& a, unsigned cant=1);

	//Colección de artículos:
	const Articulos& compra() const;

	//Mostrar número de artículos:
	size_t n_articulos() const;

	//Operador <<:
	friend ostream& operator<<(ostream& os, const Usuario& u);

	//Id duplicado:
	class Id_duplicado{
    public:
    	//Constructor de id duplicado:
        Id_duplicado(const Cadena& idd) : idd_(idd) {}

        //Mostrar id duplicado:
        const Cadena& idd() const {return idd_;}

    private:
        Cadena idd_;
    };

private:
	Cadena id_, nombre_, apellidos_, direccion_;
	Clave contrasena_;
	Tarjetas MapTarjetas_;
	Articulos n_art_;
	static Usuarios setUsuarios_;

};

//Mostrar carro:
void mostrar_carro(ostream& os, const Usuario& u);



#endif
