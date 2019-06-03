//pedido.cpp

//Jesús Rodríguez Heras 2018

#include "pedido.hpp"
#include "pedido-articulo.hpp"
#include "usuario-pedido.hpp"

using namespace std;

int Pedido::N_pedidos = 0;

//Constructor de Pedido:
Pedido::Pedido(Usuario_Pedido& u_p, Pedido_Articulo& p_a, Usuario& u, const Tarjeta& t, const Fecha& fp):num_(N_pedidos+1), tarjeta_(&t), fecha_(fp), total_(0.0){
	if(u.compra().empty()) throw Vacio(&u);
	if(t.titular() != &u) throw Impostor(&u);
	if(t.caducidad() < fp) throw Tarjeta::Caducada(t.caducidad());
	if(t.activa() == false) throw Tarjeta::Desactivada();

	auto carro = u.compra();

	for(auto iter = carro.begin() ; iter != carro.end() ; iter ++) {
		if(ArticuloAlmacenable* AA = dynamic_cast<ArticuloAlmacenable*>(iter->first)) {
			if(iter->second > AA->stock()) {
				for(auto iter=carro.begin(); iter!=carro.end(); iter++){
					u.compra(*iter->first, 0);
				}
				throw SinStock(iter->first);
			}
		} else{
			if(LibroDigital* LD = dynamic_cast<LibroDigital*>(iter->first)) {
			if(LD->f_expir() < fp)
				u.compra(*iter->first, 0);
			}
		}
	}
	if(u.compra().empty())
		throw Vacio(&u);

	u_p.asocia(*this, u);
	carro = u.compra();
	total_ = 0;

	for(auto iter = carro.begin() ; iter != carro.end() ; iter ++) {
		total_ += iter->first->precio() * iter->second;
		p_a.pedir(*iter->first, *this, iter->first->precio(), iter->second);
		if(ArticuloAlmacenable* AA = dynamic_cast<ArticuloAlmacenable*>(iter->first))
			AA->stock() -= iter->second;
	}

	const_cast<Usuario::Articulos&>(u.compra()).clear();
	num_ = ++ N_pedidos;
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
