//fecha.cpp

//Jesús Rodríguez Heras 2018

#include <ctime>
#include <cstdio>
#include <string>
#include <iomanip>
#include "fecha.hpp"

//Constructor de Fecha: dia, mes, anno
Fecha::Fecha(int d, int m, int a) : dia_(d), mes_(m), anno_(a) {
	if(dia_==0||mes_==0||anno_==0){
		time_t tiempoActual = time(nullptr);
		tm* structActual = localtime(&tiempoActual);
	
		if(dia_==0)
			dia_=structActual->tm_mday;
	
		if(mes_==0)
			mes_=structActual->tm_mon+1;
	
		if(anno_==0)
			anno_=structActual->tm_year+1900;
	}
	Fecha_Valida();
}

//Constructor Fecha: const char*():
Fecha::Fecha(const char* array){
	if(sscanf(array, "%d/%d/%d", &dia_, &mes_, &anno_) == 3)
		*this = Fecha(dia_, mes_, anno_);
	else
		throw Fecha::Invalida("Error: Formato no válido");
}

//Observador dia:
inline int Fecha::dia() const{
	return dia_;
}

//Observador mes:
inline int Fecha::mes() const{
	return mes_;
}

//Observador anno:
inline int Fecha::anno() const{
	return anno_;
}

//Operador const char*(), cadena:
const char* Fecha::cadena() const{
	char* cadena = new char[50];
	setlocale(LC_TIME, "");
	tm f = {};
	f.tm_mday = dia_;
	f.tm_mon = mes_ - 1;
	f.tm_year = anno_ - 1900;
	mktime(&f);
	const char* semana[]={"domingo", "lunes", "martes", "miércoles", "jueves", "viernes", "sábado"};
	const char* mes_actual[]={"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
	sprintf(cadena, "%s %d de %s de %d",semana[f.tm_wday], f.tm_mday, mes_actual[f.tm_mon], anno_);
	return cadena;
}

//Preincremento:
Fecha& Fecha::operator ++(){
	return *this += 1;
}

//Postincremento:
Fecha Fecha::operator ++(int){
	Fecha temp=*this;
	*this += 1;
	return temp;
}

//Predecremento:
Fecha& Fecha::operator --(){
	return *this += -1;
}

//Postdecremento:
Fecha Fecha::operator --(int){
	Fecha temp=*this;
	*this += -1;
	return temp;
}

//Operador +:
Fecha operator +(const Fecha& f, int dias){
	Fecha temp(f);
	temp += dias;
	return temp;
}

//Operador -:
Fecha operator -(const Fecha& f, int dias){
	Fecha temp(f);
	temp += -dias;
	return temp;
}

//Operador - Fechas:
long operator -(const Fecha& f1, const Fecha& f2){
	tm A = {};
	tm B = {};
	A.tm_mday = f1.dia();
	A.tm_mon = f1.mes() - 1;
	A.tm_year = f1.anno() - 1900;
	B.tm_mday = f2.dia();
	B.tm_mon = f2.mes() - 1;
	B.tm_year = f2.anno() - 1900;
	long dias = (long)difftime(mktime(&A), mktime(&B)) / (24 * 60 * 60);
	return dias;
}

//Operador +=:
Fecha& Fecha::operator +=(int dias){
	tm f = {};
	f.tm_mday = dia_ + dias;
	f.tm_mon = mes_ - 1;
	f.tm_year = anno_ - 1900;
	mktime(&f);
	dia_ = f.tm_mday;
	mes_ = f.tm_mon + 1;
	anno_ = f.tm_year + 1900;
	Fecha_Valida();
	return *this;
}

//Operador -=:
Fecha& Fecha::operator -=(int dias){
	return *this += -dias;
}

//Operador <:
bool operator < (const Fecha& f1, const Fecha& f2){
	if(f1.anno() < f2.anno())
		return true;
	else if(f1.anno() == f2.anno() && f1.mes() < f2.mes())
		return true;
	else if(f1.anno() == f2.anno() && f1.mes() == f2.mes() && f1.dia() < f2.dia())
		return true;
	else
		return false;
}

//Operador >:
bool operator > (const Fecha& f1, const Fecha& f2){
	return f2 < f1;
}

//Operador <=:
bool operator <= (const Fecha& f1, const Fecha& f2){
	return (f1 == f2 || f1 < f2);
}

//Operador >=:
bool operator >= (const Fecha& f1, const Fecha& f2){
	return (f1 == f1 || f2 < f1);
}

//Operador ==:
bool operator == (const Fecha& f1, const Fecha& f2){
	return f1.dia()==f2.dia() && f1.mes()==f2.mes() && f1.anno()==f2.anno();
}

//Operador !=:
bool operator != (const Fecha& f1, const Fecha& f2){
	return !(f1 == f2);
}

//Fecha_Valida:
void Fecha::Fecha_Valida() const{
	if(anno_ < Fecha::AnnoMinimo)
		throw Fecha::Invalida("Error: El anno introducido es menor que 1902.");
	if(anno_ > Fecha::AnnoMaximo)
		throw Fecha::Invalida("Error: El anno introducido es mayor que 2037.");
	switch(mes_) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(dia_ < 1 || dia_ > 31)
				throw Fecha::Invalida("Error: Los meses 1,3,5,7,8,10 y 12 tienen 31 dias.");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(dia_ < 1 || dia_ > 30)
				throw Fecha::Invalida("Error: Los meses 4,6,9 y 11 tienen 30 dias.");
			break;
		case 2:
			if(dia_ < 1 || (dia_ > 28 && !((anno_ % 4 == 0) && ((anno_ % 100 != 0) || (anno_ % 400 == 0)))))
				throw Fecha::Invalida("Error: El mes 2 tiene 28 dias, si el anno no es bisiesto.");
			if(dia_ < 1 || (dia_ > 29 && ((anno_ % 4 == 0) && ((anno_ % 100 != 0) || (anno_ % 400 == 0)))))
				throw Fecha::Invalida("Error: El mes 2 tiene 29 dias, si el anno es bisiesto.");
			break;
		default: throw Fecha::Invalida("Error: El mes tiene que estar entre 1 y 12.");
	}
}

//Fecha invalida:
Fecha::Invalida::Invalida(const char* s): s_(s) {}

//Por_que:
const char* Fecha::Invalida::por_que() const {
	return s_;
}

//Operador <<:
ostream& operator <<(ostream& os, const Fecha& fecha) {
    os << fecha.cadena();
    return os;
}

//Operador >>:
istream& operator >>(istream& is, Fecha& f){
	char* temp = new char[11];
	is >> setw(11) >> temp;
	int dia=-1, mes=-1, anno=-1;
    sscanf(temp, "%2d/%2d/%4d", &dia, &mes, &anno);
    delete[] temp;
	try{
		f = Fecha(dia, mes, anno);
	} catch (...) {
    	is.setstate(std::ios_base::failbit);
    	throw;
  	}
	return is;
}


