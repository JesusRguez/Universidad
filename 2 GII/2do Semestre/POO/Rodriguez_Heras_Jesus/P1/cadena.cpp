//cadena.cpp

//Jesús Rodríguez Heras 2018

#include <iostream>
#include <cstring>
#include <iomanip>
#include "cadena.hpp"

using namespace std;

//Constructor de cadena con tamano y relleno:
Cadena::Cadena(size_t n, char c):tam_(n){
	s_=new char[tam_ + 1];
	for(size_t i=0; i<tam_; i++){
		s_[i]=c;
	}
	s_[tam_]='\0';
}

//Constructor de cadena vacia:
Cadena::Cadena():tam_(0){
	s_=new char[1];
	s_[0]='\0';
}

//Constructor de copia:
Cadena::Cadena(const Cadena& cad):tam_(cad.tam_){
	s_=new char[tam_+1];
	strcpy(s_, cad.s_);
}

//Constructor Cadena de movimiento:
Cadena::Cadena(Cadena &&cad): s_(cad.s_), tam_(cad.tam_){
	cad.tam_ = 0;
	cad.s_ = nullptr;
}

//Constructor const char*:
Cadena::Cadena(const char *s):tam_(strlen(s)){
	s_=new char[tam_+1];
	strcpy(s_, s);
}

//Constructor const char* tamanno:
Cadena::Cadena(const char* s, size_t n):tam_(n){
	if(n>strlen(s))
		tam_=strlen(s);
	s_=new char[tam_+1];
	for(size_t i=0; i<tam_;i++){
		s_[i]=s[i];
	}
	s_[tam_]='\0';
}

//Constuctor con cadena, inicial y tamanno:
Cadena::Cadena(const Cadena& cad, size_t indice, size_t n):tam_(n){
	if(indice>cad.tam_-1)
		throw out_of_range("Error: Indice fuera de rango.");
	if(n==Cadena::npos || n>cad.tam_-indice)
		tam_=cad.tam_-indice;
	s_=new char[tam_+1];
	for(size_t i=0;i<tam_;i++)
		s_[i]=cad.s_[i+indice];
	s_[tam_]='\0';
}

//Destructor de cadena:
Cadena::~Cadena() {
	delete[] s_;
}

//Operador =:
Cadena& Cadena::operator =(const Cadena& cad){
	tam_=cad.tam_;
	delete[] s_;
	s_=new char[tam_+1];
	strcpy(s_, cad.s_);
	return *this;
}

//Operador = de movimiento
Cadena& Cadena::operator =(Cadena&& cad){
	s_ = cad.s_;
	tam_ = cad.tam_;
	cad.s_ = nullptr;
	cad.tam_ = 0;
	return *this;
}

//Operador +=:
Cadena& Cadena::operator +=(const Cadena& cad){
	char* temp = new char[tam_+1];
	strcpy(temp, s_);
	delete[] s_;
	tam_+=cad.tam_;
	s_=new char[tam_+1];
	strcpy(s_, temp);
	strcat(s_, cad.s_);
	delete[] temp;
	return *this;
}

//Operador at Lectura:
const char& Cadena::at(size_t indice) const{
	if(indice<tam_)
		return s_[indice];
	else
		throw out_of_range("Error. Indice fuera de rango.");
}

//Operador at Escritura:
char& Cadena::at(size_t indice){
	if(indice<tam_)
		return s_[indice];
	else
		throw out_of_range("Error. Indice fuera de rango.");
}

//Operador [] Lectura:
const char& Cadena::operator [](size_t indice) const{
	return s_[indice];
}

//Operador [] Escritura:
char& Cadena::operator [](size_t indice){
	return s_[indice];
}

//Metodo substr:
Cadena Cadena::substr(size_t indice, size_t n) const{
	if(indice>=tam_ || n>tam_-indice)
		throw out_of_range("Error. Indice fuera de rango.");
	return Cadena(*this, indice, n);
}

//Operador +:
Cadena operator + (const Cadena& c1, const Cadena& c2){
	Cadena temp(c1);
	temp+=c2;
	return temp;
}

//Operador <:
bool operator < (const Cadena& c1, const Cadena& c2){
	return strcmp(c1.c_str(), c2.c_str())<0;
}

//Operador <=:
bool operator <= (const Cadena& c1, const Cadena &c2){
	return (c1==c2 || c1<c2);
}

//Operador >:
bool operator > (const Cadena& c1, const Cadena &c2){
	return c2<c1;
}

//Operador >=:
bool operator >= (const Cadena& c1, const Cadena& c2){
	return (c1==c2 || c2<c1);
}

//Operador ==:
bool operator == (const Cadena& c1, const Cadena& c2){
	return strcmp(c1.c_str(), c2.c_str())==0;
}

//Operador !=:
bool operator != (const Cadena& c1, const Cadena& c2){
	return !(c1==c2);
}

//Operador <<:
ostream& operator <<(ostream& os, const Cadena& cad){
	os << cad.c_str();
	return os;
}

//Operador >>:
istream& operator >>(istream& is, Cadena& cad){
	char* temp = new char[33]{'\0'};
	is >> setw(33) >> temp;
	cad = Cadena(temp);
	delete[] temp;
	return is;
}

//begin:
Cadena::iterator Cadena::begin(){
	return s_;
}

Cadena::const_iterator Cadena::begin() const{
	return s_;
}


//cbegin:
Cadena::const_iterator Cadena::cbegin() const{
	return s_;
}


//rbegin:
Cadena::reverse_iterator Cadena::rbegin(){
	return reverse_iterator(end());
}

Cadena::const_reverse_iterator Cadena::rbegin() const{
	return const_reverse_iterator(end());
}


//crbegin:
Cadena::const_reverse_iterator Cadena::crbegin() const{
	return const_reverse_iterator(cend());
}


//end:
Cadena::iterator Cadena::end(){
	return s_ + tam_;
}

Cadena::const_iterator Cadena::end() const{
	return s_ + tam_;
}


//cend:
Cadena::const_iterator Cadena::cend() const{
	return s_ + tam_;
}


//rend:
Cadena::reverse_iterator Cadena::rend(){
	return reverse_iterator(begin());
}

Cadena::const_reverse_iterator Cadena::rend() const{
	return const_reverse_iterator(begin());
}


//crend:
Cadena::const_reverse_iterator Cadena::crend() const{
	return const_reverse_iterator(cbegin());
}
