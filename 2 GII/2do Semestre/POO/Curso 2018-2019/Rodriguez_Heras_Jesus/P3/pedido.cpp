//pedido.cpp

//Jesús Rodríguez Heras 2019

#include "pedido.hpp"
#include "pedido-articulo.hpp"
#include "usuario-pedido.hpp"

using namespace std;

int Pedido::N_pedidos = 0;

Pedido::Pedido(Usuario_Pedido& u_p, Pedido_Articulo& p_a, Usuario& u, const Tarjeta& t, const Fecha& fp):num_(N_pedidos+1), tarjeta_(&t), fecha_(fp), total_(0.0){
	if(u.n_articulos()==0) throw Vacio(&u);
	if(t.titular()!=&u) throw Impostor(&u);
	if(t.caducidad()<fp) throw Tarjeta::Caducada(t.caducidad());
	if(!t.activa()) throw Tarjeta::Desactivada();
	for(const pair<Articulo*, unsigned> c : u.compra()){
		if(c.first->stock() < c.second){
			const_cast<Usuario::Articulos&>(u.compra()).clear();
			throw SinStock(c.first);
		}
	}
	//Fin de excepciones
	auto carro=u.compra();
	for(auto c : carro){
		Articulo* pa=c.first;
		unsigned cantidad=c.second;
		double precio=pa->precio();
		pa->stock()-=cantidad;
		p_a.pedir(*this, *pa, precio, cantidad);
		total_+=precio*cantidad;
		u.compra(*pa, 0);
	}
	u_p.asocia(u, *this);
	++N_pedidos;
}

//Mostrar número:
int Pedido::numero() const{
	return num_;
}

//Mostrar tarjeta:
Tarjeta const* Pedido::tarjeta() const{
	return tarjeta_;
}

//Mostrar fecha:
Fecha Pedido::fecha() const{
	return fecha_;
}

//Mostrar total:
double Pedido::total() const{
	return total_;
}

//Mostrar n_total_pedidos:
int Pedido::n_total_pedidos(){
	return N_pedidos;
}

//Constructor de Vacio:
Pedido::Vacio::Vacio(Usuario *usuario):usuario_(usuario){}

//Usuario que realiza el pedido:
Usuario& Pedido::Vacio::usuario() const{
	return *usuario_;
}

//Constructor de Impostor:
Pedido::Impostor::Impostor(Usuario *usuario): usuario_(usuario){}

//Usuario impostor:
Usuario& Pedido::Impostor::usuario() const{
	return *usuario_;
}

//Constructor de SinStock:
Pedido::SinStock::SinStock(Articulo* articulo): articulo_(articulo){}

//Artículo sin stock:
Articulo& Pedido::SinStock::articulo() const{
	return *articulo_;
}

//Operador <<:
ostream& operator<<(ostream& os, const Pedido& pedido){
  	os << "Núm. pedido: " << pedido.numero() << endl
    	<< "Fecha:       " << pedido.fecha() << endl
    	<< "Pagado con:  " << pedido.tarjeta()->tipo() << " nº: " << pedido.tarjeta()->numero() << endl
    	<< "Importe:     " << fixed << setprecision(2) << pedido.total() << " €" << endl;
  return os;
}
