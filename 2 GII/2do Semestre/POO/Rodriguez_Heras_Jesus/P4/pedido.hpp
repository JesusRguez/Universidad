//pedido.hpp

//Jesús Rodríguez Heras 2018

#ifndef PEDIDO_HPP_
#define PEDIDO_HPP_

#include "usuario.hpp"
#include "tarjeta.hpp"
#include "fecha.hpp"
#include "articulo.hpp"
#include "usuario-pedido.hpp"
#include "pedido-articulo.hpp"

//Declaración adelantada de las clases:
class Usuario_Pedido;
class Pedido_Articulo;
class Tarjeta;

//Clase Pedido
class Pedido{
public:
	//Constructor de Pedido:
	Pedido(Usuario_Pedido& u_p, Pedido_Articulo& p_a, Usuario& u, const Tarjeta& t, const Fecha& fp=Fecha());

	//Mostrar número:
	int numero() const;

	//Mostrar tarjeta:
	Tarjeta const* tarjeta() const;

	//Mostrar fecha:
	Fecha fecha() const;

	//Mostrar total:
	double total() const;

	//Mostrar n_total_pedidos:
	static int n_total_pedidos();

	class Vacio{
  	public:
    	Vacio(Usuario *usuario);
    	Usuario& usuario() const;
  	private:
    	Usuario* usuario_;
  	};

  	class Impostor{
  	public:
    	Impostor(Usuario *usuario);
    	Usuario& usuario() const;
  	private:
    	Usuario* usuario_;
  	};

  	class SinStock{
  	public:
    	SinStock(Articulo* articulo);
    	Articulo& articulo() const;
  	private:
    	Articulo* articulo_;
  	};

private:
	static int N_pedidos;
	int num_;
	Tarjeta const *tarjeta_;
	Fecha fecha_;
	double total_;
};

//Operador <<:
ostream& operator<<(ostream& os, const Pedido& pedido);

#endif
