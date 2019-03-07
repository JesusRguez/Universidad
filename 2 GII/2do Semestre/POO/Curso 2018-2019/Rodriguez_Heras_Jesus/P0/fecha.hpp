//fecha.hpp

//Jesús Rodríguez Heras 2018

#ifndef FECHA_HPP_
#define FECHA_HPP_

class Fecha{
public:
	//Clase Excepcion Invalida
	class Invalida{
	public:
		//Constructor Invalida: const char*
		Invalida(const char* s);

		//Observador por_que
		const char* por_que() const;

		//Destructor:
		~Invalida()=default;
	private:
		const char* s_;
	};

	//Fecha();
	//Fecha(int);
	//Fecha(int, int);
	explicit Fecha(int d=0, int m=0, int a=0);
	Fecha(const char* array);

	//Fecha(const Fecha& f);
	Fecha& operator =(const Fecha&)=default;

	inline int dia() const { return dia_; }

	inline int mes() const { return mes_; }

	inline int anno() const { return anno_; }

	static const int AnnoMinimo=1902;
	static const int AnnoMaximo=2037;

	operator const char*() const;

	// Preincremento
	Fecha& operator ++();

	// Postincremento
	Fecha operator ++(int);

	// Predecremento
	Fecha& operator --();

	// Postdecremento
	Fecha operator --(int);

	// Operador +=
	Fecha& operator +=(int dias);

	// Operador -=
	Fecha& operator -=(int dias);

private:
	int dia_, mes_, anno_;
	void Fecha_Valida() const;
};

//Operador +:
Fecha operator + (const Fecha& f, int dias);

//Operador -:
Fecha operator - (const Fecha& f, int dias);

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

#endif
