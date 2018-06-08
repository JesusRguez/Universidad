//pedido-articulo.hpp

//Jesús Rodríguez Heras 2018

#include "pedido-articulo.hpp"

using namespace std;

//Constructor de LineaPedido:
LineaPedido::LineaPedido(double pv, unsigned cant):precio_venta_(pv), cantidad_(cant){};

//Mostrar el precio de venta:
double LineaPedido::precio_venta() const{
	return precio_venta_;
}

//Mostrar la cantidad:
unsigned LineaPedido::cantidad() const{
	return cantidad_;
}

//Operador <<:
ostream& operator <<(ostream& os, const LineaPedido& LP){
	os << fixed << setprecision(2) << LP.precio_venta() << " €\t"<< LP.cantidad();
	return os;
}

//Método pedir:
void Pedido_Articulo::pedir(Pedido& p, Articulo& a, double precio, unsigned cantidad){
	ped_art_[&p].insert(make_pair(&a,LineaPedido(precio,cantidad)));
	art_ped_[&a].insert(make_pair(&p,LineaPedido(precio,cantidad)));
}

void Pedido_Articulo::pedir(Articulo& a, Pedido& p, double precio, unsigned cantidad){
	pedir(p, a, precio, cantidad);
}

//Método detalle:
const Pedido_Articulo::ItemsPedido& Pedido_Articulo::detalle(Pedido& p){
	return ped_art_.find(&p)->second;
}

//Método ventas:
Pedido_Articulo::Pedidos Pedido_Articulo::ventas(Articulo& a){
	if(art_ped_.find(&a) == art_ped_.end()){
		Pedido_Articulo::Pedidos Vacio;
		return Vacio;
	}else
		return art_ped_.find(&a)->second;
}

//Mostrar detalle de los pedidos:
ostream& Pedido_Articulo::mostrarDetallePedidos(ostream& os) const{
	double precio = 0;
 	map<Pedido*, Pedido_Articulo::ItemsPedido, OrdenaPedidos>::const_iterator iter;
 	for(iter = ped_art_.begin() ; iter != ped_art_.end() ; iter ++){
 		os << "Pedido núm. " << iter->first->numero();
 		os << "\tCliente: " << iter->first->tarjeta()->titular()->nombre() << " " << "\n";
 		os << "Fecha: " << iter->first->fecha() << iter->second;
 		precio += iter->first->total();
 	}
 	os << fixed;
 	os << "TOTAL VENTAS: " << setprecision(2) << precio << " €" << endl;
 	return os;
}

//Mostrar ventas de los articulos:
ostream& Pedido_Articulo::mostrarVentasArticulos(ostream& os) const{
	map<Articulo*, Pedido_Articulo::Pedidos,OrdenaArticulos>::const_iterator iter;
	for(iter = art_ped_.begin() ; iter != art_ped_.end() ; iter ++){
 		os << "Ventas de " << "[" << iter->first->referencia() << "]";
	 	os << "\"" << iter->first->titulo() << "\" \n" << iter->second << endl;
 	}
	return os;
}

//Operador <<:
ostream& operator <<(ostream& os,const Pedido_Articulo::ItemsPedido& IP){
	double precio = 0;
  	Pedido_Articulo::ItemsPedido::const_iterator i;
  	os << endl << "====================================================" << endl;
  	os << " PVP \t Cant. \t Articulo \n";
  	os << "====================================================" << endl;
  	for(i = IP.begin(); i != IP.end(); ++i){
  		os << " " << i->second.precio_venta() << "€\t";
    	os << i->second.cantidad() << "\t";
    	os << "[" << i->first->referencia() << "] ";
    	os << "\"" << i->first->titulo() << "\" " << endl;
    	precio = precio + i->second.precio_venta() * i->second.cantidad();
    }
  	os << "===================================================" << endl;
  	os << fixed;
  	os << setprecision(2) << precio << " €" << endl;
  	return os;
}

ostream& operator <<(ostream& os,const Pedido_Articulo::Pedidos& P){
	double precio = 0;
  	unsigned total = 0;
  	Pedido_Articulo::Pedidos::const_iterator i;
  	os << "====================================================" << endl;
  	os << " PVP \t Cant. \t Fecha venta \n";
  	os << "====================================================" << endl;
  	for(auto i : P){
    	os << " " << i.second.precio_venta() << "€\t";
    	os << i.second.cantidad() << "\t";
    	os << i.first->fecha() << endl;
    	precio = precio + i.second.precio_venta() * i.second.cantidad();
    	total = total + i.second.cantidad();
    }
  	os << "====================================================" << endl;
  	os << fixed;
  	os << setprecision(2) << precio << " €\t" << total <<endl ;
 	return os;
}

//Operador ():
bool OrdenaPedidos::operator()(const Pedido* p1,const Pedido* p2) const{
  	return (p1->numero() < p2->numero());
}
