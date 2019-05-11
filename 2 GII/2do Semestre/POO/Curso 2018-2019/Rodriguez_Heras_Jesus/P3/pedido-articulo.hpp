//pedido-articulo.hpp

//Jesús Rodríguez Heras 2019

#ifndef PEDIDO_ARTICULO_HPP_
#define PEDIDO_ARTICULO_HPP_

#include <iostream>
#include <iomanip>
#include "pedido.hpp"
#include "articulo.hpp"

using namespace std;

//Declaración adelantada de las clases:
class Pedido;
class Articulo;

class LineaPedido{
public:
	//Constructor de LineaPedido:
	explicit LineaPedido(double pv, unsigned cant=1);

	//Mostrar el precio de venta:
	double precio_venta() const;

	//Mostrar la cantidad:
	unsigned cantidad() const;

private:
	double precio_venta_;
	unsigned cantidad_;
};

//Operador <<:
ostream& operator<<(ostream& os, const LineaPedido& LP);

//Clase OrdenaPedidos:
class OrdenaPedidos: public binary_function<Pedido*,Pedido*,bool>{
public:
	//Operador ():
  	bool operator()(const Pedido* p1,const Pedido* p2) const;
};

//Clase OrdenaArticulos:
class OrdenaArticulos: public binary_function<Articulo*,Articulo*,bool>{
public:
	//Operador ():
  	bool operator()(const Articulo* a1,const Articulo* a2) const{
  	return (a1->referencia() < a2->referencia());
  	}
};

class Pedido_Articulo{
public:
	//Maps para las relaciones:
	typedef std::map<Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido;
	typedef std::map<Pedido*, LineaPedido, OrdenaPedidos> Pedidos;
	typedef std::map<Pedido*, ItemsPedido, OrdenaPedidos> Directa;
	typedef std::map<Articulo*, Pedidos, OrdenaArticulos> Inversa;

	//Método pedir:
	void pedir(Pedido& p, Articulo& a, double precio, unsigned cantidad=1);
	void pedir(Articulo& a, Pedido& p, double precio, unsigned cantidad=1);

	//Método detalle:
	const ItemsPedido& detalle(Pedido& p);

	//Método ventas:
	Pedidos ventas(Articulo& a);

	//Mostrar detalle de los pedidos:
	ostream& mostrarDetallePedidos(ostream&) const;

	//Mostrar ventas de los articulos:
	ostream& mostrarVentasArticulos(ostream&) const;

private:
	Directa ped_art_;
	Inversa art_ped_;
};

//Operador <<:
ostream& operator <<(ostream& os,const Pedido_Articulo::ItemsPedido&);
ostream& operator <<(ostream& os,const Pedido_Articulo::Pedidos&);


#endif
