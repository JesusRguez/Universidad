//tarjeta.cpp

//Jesús Rodríguez Heras 2018

#include <iomanip>
#include <cstring>
#include <functional>
#include <algorithm>
#include "tarjeta.hpp"
#include "usuario.hpp"

//Constructor de Numero:
Numero::Numero (const Cadena& numero):numero_(numero){
	bool luhn(const Cadena& numero);

	Cadena::iterator fin = remove_if(numero_.begin(),numero_.end(),EsBlanco());
	if(fin != numero_.end()){
	    *fin = '\0';
    	Cadena sd (numero_.c_str());
    	numero_ = sd;
	}
	if(find_if(numero_.begin(),numero_.end(), not1(EsDigito())) != numero_.end())
	    throw Incorrecto(DIGITOS);

	if (numero_.length() < 13 or numero_.length() > 19)
		throw Incorrecto(Razon::LONGITUD);

	if (!luhn(numero_))
	    throw Incorrecto(Razon::NO_VALIDO);
}

//Operador const char* ():
Numero::operator const char* () const{
	return (numero_.c_str());
}

//Operador < de números:
bool operator <(const Numero& n1, const Numero& n2){
	return strcmp(n1, n2) < 0;
}

//Constructor de tarjeta:
Tarjeta::Tarjeta (const Tipo& tipo, const Numero& numero, Usuario& usuario, const Fecha& fecha_caducidad):tipo_(tipo), numero_(numero), usuario_(&usuario), fechaExp_(fecha_caducidad), titular_facial_(usuario.nombre() + " " + usuario.apellidos()){
	if (fecha_caducidad < Fecha())
		throw Caducada(fecha_caducidad);

	usuario_->es_titular_de(*this);
}

//Destructor de tarjeta:
Tarjeta::~Tarjeta(){
	if (usuario_)
		usuario_->no_es_titular_de(*this);
}

//Anular titular:
void Tarjeta::anula_titular(){
	const_cast<Usuario*&>(usuario_) = nullptr;
}

//Operador <:
bool operator < (const Tarjeta& t1,const Tarjeta& t2){
	return t1.numero()<t2.numero();
}

//operador <<:
ostream& operator << (ostream& os, Tarjeta::Tipo const& tipo){
	switch (tipo){
		case 0: os << "VISA";  break;
		case 1: os << "Mastercard"; break;
		case 2: os << "Maestro";  break;
		case 3: os << "JCB"; break;
		case 4: os << "AmericanExpress"; break;
	}

  return os;
}

ostream& operator << (ostream& os , const Tarjeta& t){
	os << t.tipo() << endl << t.numero() << endl << t.titular_facial() << endl << "Caduca: " << setfill('0') << setw(2) << t.caducidad().mes() << "/" << setw(2) << (t.caducidad().anno() % 100) << endl;
	return os;
}
