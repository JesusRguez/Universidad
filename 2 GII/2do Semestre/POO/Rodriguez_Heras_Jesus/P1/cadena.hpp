//cadena.hpp

//Jesús Rodríguez Heras 2018

#ifndef CADENA_H_
#define CADENA_H_
#include <iostream>

using namespace std;

class Cadena{
public:
	//Constructor de cadena con tamano y relleno:
	explicit Cadena(size_t n, char c=' ');
	
	//Constructor de cadena vacia:
	Cadena();
	
	//Constructor de copia:
	Cadena(const Cadena& cad);
	
	//Constructor Cadena de movimiento:
	Cadena(Cadena&& cad);
	
	//Constructor const char*:
	Cadena(const char *s);
	
	//Constructor cons char* tamanno:
	Cadena(const char* s, size_t n);
	
	//Consttuctor con cadena, inicial y tamanno:
	Cadena(const Cadena& cad, size_t indice, size_t n=pos);
	
	//Destructor de cadena:
	~Cadena();
	
	//Constante pos:
	static const size_t pos=-1;
	
	//Operador =:
	Cadena& operator =(const Cadena& cad);
	
	//Operador = de movimiento:
	Cadena& operator =(Cadena&& cad);
	
	//Conversion const char*:
	const char* c_str() const;
	
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
	
	//iterator:
	typedef char* iterator;
	
	//const_iterator:
	typedef const char* const_iterator;
	
	//reverse_iterator:
	typedef std::reverse_iterator<iterator> reverse_iterator;
	
	//const_reverse_iterator:
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	
	//begins:
	iterator begin();
	const_iterator begin() const;
	
	//cbegin:
	const_iterator cbegin() const;
	
	//rbegin:
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	
	//crbegin:
	const_reverse_iterator crbegin() const;
	
	//end:
	iterator end();
	const_iterator end() const;
	
	//cend:
	const_iterator cend() const;
	
	//rend:
	reverse_iterator rend();
	const_reverse_iterator rend() const;
	
	//crend:
	const_reverse_iterator crend() const;
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

//Operador <<:
ostream& operator <<(ostream& os, const Cadena& cad);

//Operador >>:
istream& operator >>(istream& is, Cadena& cad);

namespace std { // Estaremos dentro del espacio de nombres std
	template <> // Es una especialización de una plantilla para Cadena
	struct hash<Cadena> { // Es una clase con solo un operador publico
		size_t operator() (const Cadena& cad) const // el operador función
		{
			hash<string> hs; // creamos un objeto hash de string
			const char * p = cad.c_str(); // obtenemos la cadena de la Cadena
			string s(p); // creamos un string desde una cadena
			size_t res = hs(s); // el hash del string. Como hs.operator()(s);
			return res; // devolvemos el hash del string
		}
	};
}

#endif
