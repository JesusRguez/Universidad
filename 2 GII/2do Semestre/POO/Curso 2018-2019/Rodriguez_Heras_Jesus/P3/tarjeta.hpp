//tarjeta.hpp

//Jesús Rodríguez Heras 2019

#ifndef TARJETA_HPP_
#define TARJETA_HPP_
#include <iostream>
#include <algorithm>
#include <set>
#include "fecha.hpp"
#include "cadena.hpp"

//Clase Numero:
class Numero{
public:
	//Tipo enumerado para la clase Numero:
	enum Razon{LONGITUD,DIGITOS,NO_VALIDO};

	//Constructor de Numero:
	Numero (const Cadena& numero);

	//Operador const char* ():
	operator const char* () const;

	//Clase Incorrecto:
	class Incorrecto{
	public:
		//Constructor de Incorrecto:
		Incorrecto (Numero::Razon razon):razon_(razon){}

		//Razón:
		Numero::Razon razon() const{return razon_;}

	private:
		Numero::Razon razon_;
	};

private:
	Cadena numero_;
};

//Operador < de números:
bool operator <(const Numero& n1, const Numero& n2);

//Es blanco:
class EsBlanco: public unary_function<char, bool>{
public:
	bool operator()(char c) const {return isspace(c);}
};

//Es dígito:
class EsDigito: public unary_function<char, bool>{
public:
	bool operator()(char c) const {return isdigit(c);}
};

class Usuario;

class Tarjeta{
public:
	//Tipo enumerado de tarjeta:
	enum Tipo{Otro,VISA, Mastercard, Maestro, JCB, AmericanExpress};

	//Set de números:
	typedef std::set<Numero> numeros;

	//Constructor de tarjeta:
	Tarjeta (const Numero& numero, Usuario& usuario, const Fecha& fecha_caducidad);

	//Evitar copia:
	Tarjeta(const Tarjeta&) = delete;
    Tarjeta& operator = (const Tarjeta&) = delete;

	//Destructor de tarjeta:
	~Tarjeta();

	//Mostrar tipo:
	Tipo tipo() const;

	//Mostrar número:
	Numero numero() const;

	//Mostrar fecha de caducidad:
	Fecha caducidad() const;

	//Mostrar si está activa:
	bool activa() const;

	//Cambiar activada/desactivada:
	bool activa(bool a = true);

	//Mostrar titular:
	const Usuario* titular() const;

	//Anular titular:
	void anula_titular();

	//Clase Caducada:
	class Caducada{
	public:
		//Constructor de Caducada:
		Caducada(const Fecha& caducada) : caducada_(caducada){}

		//Mostrar cuando caducó:
		const Fecha& cuando() const { return caducada_; }

	private:
		Fecha caducada_;
	};

	//Clase Desactivada:
	class Desactivada{};

	//Clase Num_duplicado:
	class Num_duplicado{
	public:
		//Constructor de Num_duplicado:
		Num_duplicado(const Numero& numero) : numero_(numero){}

		//Mostrar número duplicado:
		const Numero& que() const { return numero_; }

	private:
		Numero numero_;
	};

private:
	Tipo tipo_;
	Numero numero_;
	Usuario* const usuario_;
	Fecha fechaExp_;
	bool activa_;
	numeros numeros_;
};

//Operador < de tarjetas:
bool operator < (const Tarjeta& t1, const Tarjeta& t2);

//operador <<:
ostream& operator << (ostream& os, Tarjeta::Tipo const& tipo);
ostream& operator << (ostream& os , const Tarjeta& t);

#endif
