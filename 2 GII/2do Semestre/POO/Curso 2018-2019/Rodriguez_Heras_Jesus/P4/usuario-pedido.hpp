//usuario-pedido.hpp

//Jesús Rodríguez Heras 2019

#ifndef USUARIO_PEDIDO_HPP_
#define USUARIO_PEDIDO_HPP_

#include "pedido.hpp"
#include "usuario.hpp"

using namespace std;

//Declaración adelantada de las clases:
class Usuario;
class Pedido;

class Usuario_Pedido{
public:
	//set y maps:
	typedef set<Pedido*> Pedidos;
  	typedef map<Usuario*, Pedidos> UsuarioP;
  	typedef map<Pedido*, Usuario*> PedidoU;

	//Método asocia:
	void asocia(Usuario& u, Pedido& p){
		usu_ped_[&u].insert(&p);
    	ped_usu_[&p] = &u;
	}
	void asocia(Pedido& p, Usuario& u){
		asocia(u, p);
	}

	//Método pedidos:
	Pedidos pedidos(Usuario& u){
		return usu_ped_.find(&u)->second;
	}

	//Método cliente:
	Usuario* cliente(Pedido& p){
		return ped_usu_.find(&p)->second;
	}

private:
	UsuarioP usu_ped_;
  	PedidoU ped_usu_;
};

#endif
