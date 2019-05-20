//tarjeta.cpp

//Jesús Rodríguez Heras 2019

#include <iomanip>
#include <cstring>
#include <functional>
#include <algorithm>
#include <set>
#include <ctype.h>
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

//Operador < de números:
bool operator <(const Numero& n1, const Numero& n2){
	return strcmp(n1, n2) < 0;
}

//Constructor de tarjeta:
Tarjeta::Tarjeta (const Numero& numero, Usuario& usuario, const Fecha& fecha_caducidad):numero_(numero), usuario_(&usuario), fechaExp_(fecha_caducidad){
	if (fecha_caducidad < Fecha())
		throw Caducada(fecha_caducidad);

	activa_ = true;
	usuario_->es_titular_de(*this);

	switch (numero[0]) {
		case '3':{
			if (numero[1] == 4 || numero[1] == 7) {
				tipo_ = AmericanExpress;
			}else{
				tipo_ = JCB;
			}
		} break;
		case '4': tipo_ = VISA; break;
		case '5': tipo_ = Mastercard; break;
		case '6': tipo_ = Maestro; break;
		default: tipo_ = Otro;
	}

	std::pair<std::set<Numero>::iterator, bool> ret;
	ret = numeros_.insert(numero);

	if (ret.second == false) {
		throw Num_duplicado(numero);
	}
}

//Destructor de tarjeta:
Tarjeta::~Tarjeta(){
	if (usuario_)
		usuario_->no_es_titular_de(*this);
}

//Cambiar activada/desactivada:
bool Tarjeta::activa(bool a){
	activa_ = a;
	return activa_;
}

//Anular titular:
void Tarjeta::anula_titular(){
	const_cast<Usuario*&>(usuario_) = nullptr;
	activa_ = false;
}

//Operador <:
bool operator < (const Tarjeta& t1,const Tarjeta& t2){
	return t1.numero()<t2.numero();
}

//operador <<:
ostream& operator << (ostream& os, Tarjeta::Tipo const& tipo){
	switch (tipo){
		case 0: os << "Tipo indeterminado"; break;
		case 1: os << "VISA"; break;
		case 2: os << "Mastercard"; break;
		case 3: os << "Maestro"; break;
		case 4: os << "JCB"; break;
		case 5: os << "AmericanExpress"; break;
	}

  return os;
}

ostream& operator << (ostream& os , const Tarjeta& t){
	Cadena nombre(t.titular()->nombre());
	Cadena apellidos(t.titular()->apellidos());

	for (size_t i = 0; i < nombre.length(); ++i) {
		nombre[i] = toupper(nombre[i]);
	}

	for (size_t i = 0; i < apellidos.length(); ++i) {
		apellidos[i] = toupper(apellidos[i]);
	}



	os << t.tipo() << endl << t.numero() << endl << nombre << " " << apellidos << endl << "Caduca: " << setfill('0') << setw(2) << t.caducidad().mes() << "/" << setw(2) << (t.caducidad().anno() % 100) << endl;
	return os;
}
