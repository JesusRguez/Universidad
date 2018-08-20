//tarjeta.hpp

//Jesús Rodríguez Heras 2018

#ifndef TARJETA_HPP_
#define TARJETA_HPP_
#include <iostream>
#include <algorithm>
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
		Numero::Razon razon() const{ return razon_; }

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
	bool operator()(char c) const { return isspace(c); }
};

//Es dígito:
class EsDigito: public unary_function<char, bool>{
public:
	bool operator()(char c) const { return isdigit(c); }
};

class Usuario;

class Tarjeta{
public:
	//Tipo enumerado de tarjeta:
	enum Tipo{VISA, Mastercard, Maestro, JCB, AmericanExpress};

	//Constructor de tarjeta:
	Tarjeta (const Tipo& tipo, const Numero& numero, Usuario& usuario, const Fecha& fecha_caducidad);

	//Evitar copia:
	Tarjeta(const Tarjeta&) = delete;
    Tarjeta& operator = (const Tarjeta&) = delete;

	//Destructor de tarjeta:
	~Tarjeta();

	//Mostrar tipo:
	inline Tipo tipo() const { return tipo_; };

	//Mostrar número:
	inline Numero numero() const { return numero_; };

	//Mostrar fecha de caducidad:
	inline Fecha caducidad() const { return fechaExp_; };

	//Mostrar titular facial:
	inline Cadena titular_facial() const { return titular_facial_; };

	//Mostrar titular:
	inline const Usuario* titular() const { return usuario_; };

	//Anular titular:
	void anula_titular();

	//Clase caducada:
	class Caducada{
	public:
		//Constructor de caducada:
		Caducada(const Fecha& caducada) : caducada_(caducada){}

		//Mostrar cuando caducó:
		const Fecha& cuando() const { return caducada_; }

	private:
		Fecha caducada_;
};

private:
	Tipo tipo_;
	Numero numero_;
	Usuario* const usuario_;
	Fecha fechaExp_;
	Cadena titular_facial_;
};

//Operador < de tarjetas:
bool operator < (const Tarjeta& t1, const Tarjeta& t2);

//operador <<:
ostream& operator << (ostream& os, Tarjeta::Tipo const& tipo);
ostream& operator << (ostream& os , const Tarjeta& t);

#endif
