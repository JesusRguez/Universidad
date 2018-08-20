//usuario.cpp

//Jesús Rodríguez Heras 2018

#include <cstring>
#include <random>
#include <ctime>
#include <cstdlib>
#include <iomanip>
extern "C" {
	#include <unistd.h>
}
#include "usuario.hpp"

Usuario::Usuarios Usuario::setUsuarios_;

//Constructor de clave:
Clave::Clave(const char* contrasena){
	if(std::strlen(contrasena)<5)
		throw Incorrecta(CORTA);
	static const char * const cvs={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./"};
	const std::size_t longtd=sizeof(cvs)-1;
	std::random_device gna;
	std::uniform_int_distribution<size_t> dis(0, longtd-1);
	char sal[]={cvs[dis(gna)], cvs[dis(gna)]};
	if(const char * const p=crypt(contrasena, sal))
		clave_=p;
	else
		throw Incorrecta(ERROR_CRYPT);
}

//Verificar clave:
bool Clave::verifica(const char* posible_contrasena) const {
	if(const char * const p=crypt(posible_contrasena, clave_.c_str()))
		return clave_==p;
	throw Incorrecta(ERROR_CRYPT);
}

//Constructor de usuario:
Usuario::Usuario(const Cadena& id, const Cadena& nombre, const Cadena& apellidos, const Cadena& direccion, const Clave& contrasena) : id_(id), nombre_(nombre), apellidos_(apellidos), direccion_(direccion), contrasena_(contrasena){
	if (!setUsuarios_.insert(id).second)
		throw Id_duplicado(id_);
}

//Destructor de usuario:
Usuario::~Usuario(){
	for (auto& i : MapTarjetas_)
		i.second->anula_titular();
	setUsuarios_.erase(id_);
}

//Ver si es titular de una tarjeta:
void Usuario::es_titular_de(Tarjeta& t){
	if(t.titular() == this)
		MapTarjetas_[t.numero()] = const_cast<Tarjeta*>(&t);
}

//Ver si no es titular de una tarjeta:
void Usuario::no_es_titular_de(Tarjeta& t){
	MapTarjetas_.erase(t.numero());
}

//Asociacion unidireccional:
void Usuario::compra(Articulo& a, unsigned cant){
	if (cant == 0)
		n_art_.erase(const_cast<Articulo*>(&a));
	else
		n_art_[const_cast<Articulo*>(&a)] = cant;
}

//Colección de artículos:
const Usuario::Articulos& Usuario::compra() const {
	return n_art_;
}

//Operador <<:
ostream& operator<<(ostream& os, const Usuario& u){
	os << u.id() << "[" << u.contrasena_.clave() << "]" << u.nombre() << u.apellidos() << endl << u.direccion() << endl << "Tarjetas:" << endl;

	for (auto& i : u.MapTarjetas_)
		os << *i.second << endl;

	return os;
}

//Mostrar artículo:
void mostrar_articulo(ostream& os, const Articulo& a){
	os << "[" << a.referencia() << "] " << "\"" << a.titulo() << "\", " << a.f_publi().anno() << ". " << fixed << setprecision(2) << a.precio() << " €" << endl;
}

//Mostrar carro:
void mostrar_carro(ostream& os, const Usuario& u){
	os << "Carrito de la compra de " << u.id() << "[Artículos: " << u.n_articulos() << "]" << endl << " Cant. Artículo" << endl << setw(65) << setfill('=') << '\n'  << setfill(' ');
	for (auto const& i : u.compra()) {
		os << setw(4) << i.second << "   ";
		mostrar_articulo(os, *(i.first));
	}

	os << endl;
}
