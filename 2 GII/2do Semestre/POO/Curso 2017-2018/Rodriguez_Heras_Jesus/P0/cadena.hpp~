//cadena.hpp

#ifndef CADENA_H_
#define CADENA_H_
#include <iostream>

class Cadena{
public:
	//Constructor de cadena con tamano y relleno:
	explicit Cadena(size_t n, char c=' ');
	//Constructor de cadena vacia:
	Cadena();
	//Constructor de copia:
	Cadena(const Cadena& cad);
	//Constructor const char*:
	Cadena(const char *s);
	//Constructor cons char* tamanno:
	Cadena(const char* s, size_t n);
	//Consttuctor con cadena, inicial y tamanno:
	Cadena(const Cadena& cad, size_t indice, size_t n=pos);
	//Destructor:
	~Cadena();
	//Constante pos:
	static const size_t pos=-1;
	//Operador =:
	Cadena& operator =(const Cadena& cad);
	//Conversion const char*:
	operator const char*() const;
	//Metodo length:
	size_t length()const;
	//Operador +=:
	Cadena& operator +=(const Cadena& cad);
	//Operador at Lectura:
	const char& at(size_t indice) const;
	//Operador at Escritura:
	char& at(size_t inidce);
	//Operador [] Lectura:
	const char& operator [](size_t indice) const;
	//Operador [] Escritura:
	char& operator [](size_t indice);
	//Metodo substr:
	Cadena substr(size_t indice, size_t n) const;
private:
	char *s_;
	size_t tam_;
};

//Operador +:
Cadena operator + (const Cadena& c1, const Cadena& c2);
//Operador <:
bool operator < (const Cadena& c1, const Cadena& c2);
//Operador <=:
bool operator <= (const Cadena& c1, const Cadena &c2);
//Operador >:
bool operator > (const Cadena& c1, const Cadena &c2);
//Operador >=:
bool operator >= (const Cadena& c1, const Cadena& c2);
//Operador ==:
bool operator == (const Cadena& c1, const Cadena& c2);
//Operador !=:
bool operator != (const Cadena& c1, const Cadena& c2);

#endif
