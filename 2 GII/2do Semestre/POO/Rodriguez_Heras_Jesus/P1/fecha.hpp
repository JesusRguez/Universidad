//fecha.hpp

//Jesús Rodríguez Heras 2018

#ifndef FECHA_HPP_
#define FECHA_HPP_
#include <iostream>

using namespace std;

class Fecha{
public:
	//Clase de excepcion Invalida
	class Invalida{
	public:
		//Constructor Invalida: const char*
		Invalida(const char* s);
		//Observador por_que
		const char* por_que() const;
		//Destructor de Invalida
		~Invalida()=default;
	private:
		const char* s_;
	};
	
	//Constructor Fecha: dia, mes, anno:
	explicit Fecha(int d=0, int m=0, int a=0);
	
	//Constructor Fecha: const char*():
	Fecha(const char* array);
	
	//Operador =:
	Fecha& operator =(const Fecha&)=default;
	
	//Metodos observadores:
	int dia() const;
	int mes() const;
	int anno() const;
	
	//Constantes:
	static const int AnnoMinimo=1902;
	static const int AnnoMaximo=2037;
	
	//Conversion a const char*, cadena:
	const char* cadena() const;
	
	//Preincremento:
	Fecha& operator ++();
	
	//Postincremento:
	Fecha operator ++(int);
	
	//Predecremento:
	Fecha& operator --();
	
	//Postdecremento:
	Fecha operator --(int);
	
	//Operador +=:
	Fecha& operator +=(int dias);
	
	//Operador -=:
	Fecha& operator -=(int dias);
		
private:
	int dia_, mes_, anno_;
	void Fecha_Valida() const;
};

//Operador +:
Fecha operator + (const Fecha& f, int dias);

//Operador -:
Fecha operator - (const Fecha& f, int dias);

//Operador - Fechas
long operator -(const Fecha& a, const Fecha& b);

//Operador <:
bool operator < (const Fecha& f1, const Fecha& f2);

//Operador >:
bool operator > (const Fecha& f1, const Fecha& f2);

//Operador <=:
bool operator <= (const Fecha& f1, const Fecha& f2);

//Operador >=:
bool operator >= (const Fecha& f1, const Fecha& f2);

//Operador ==:
bool operator == (const Fecha& f1, const Fecha& f2);

//Operador !=:
bool operator != (const Fecha& f1, const Fecha& f2);

//Operador <<:
ostream& operator <<(ostream& os, const Fecha& f);

//Operador >>:
istream& operator >>(istream& is, Fecha& f);


#endif
