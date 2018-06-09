#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

#include "celda.hpp"
#include "sUltrasonidos.hpp"
#include "sInfrarrojos.hpp"
#include "sCNY.hpp"
#include "motor.hpp"

//Default values for Robot pins

#define ULTRA A3
#define INFRA_IZQ A4
#define INFRA_DCHA A8
#define CNY_AT A5
#define CNY_IZQ A1
#define CNY_DCHA A0
#define M_11 10
#define M_12 9
#define M_21 6
#define M_22 5

class Robot {

public:

	Robot(int ultra = ULTRA, int infraIzq = INFRA_IZQ, int infraDcha = INFRA_DCHA, int CNYAt = CNY_AT, int CNYIzq = CNY_IZQ,
	      int CNYDcha = CNY_DCHA, int M11 = M_11, int M12 = M_12, int M21 = M_21, int M22 = M_22);

	float distanciaDelante() const;
	float distanciaIzq() const;
	float distanciaDcha() const;

	bool negroAtras() const;
	bool negroIzq() const;
	bool negroDcha() const;

  //Testing
  int numeroAtras() const;
  int numeroIzq() const;
  int numeroDcha() const;

	void motorIzqDelante(unsigned v);
	void motorDchaDelante(unsigned v);
	void motorIzqDetras(unsigned v);
	void motorDchaDetras(unsigned v);
	void motorIzqParar();
	void motorDchaParar();


private:



	//Connected sensors and motors
	sUltrasonidos ultrasonidos;
	sInfrarrojos sharpIzq;
	sInfrarrojos sharpDcha;

	sCNY CNYAtras;
	sCNY CNYIzq;
	sCNY CNYDcha;

	motor MIzq;
	motor MDcha;
};

inline Robot::Robot(int ultra, int infraIzq, int infraDcha, int CNYAt, int CNYIzq, int CNYDcha, int M11, int M12, int M21, int M22):
	ultrasonidos{ultra},
	sharpIzq{infraIzq},
	sharpDcha{infraDcha},
	CNYAtras{CNYAt},
	CNYIzq{CNYIzq},
	CNYDcha{CNYDcha},
	MIzq{M11,M12},
	MDcha{M21,M22}
	{}

inline float Robot::distanciaDelante() const { return ultrasonidos.distancia(); }
inline float Robot::distanciaIzq() const { return sharpIzq.distancia(); }
inline float Robot::distanciaDcha() const { return sharpDcha.distancia(); }

inline bool Robot::negroAtras() const { return CNYAtras.negro(); }
inline bool Robot::negroIzq() const { return CNYIzq.negro(); }
inline bool Robot::negroDcha() const { return CNYDcha.negro(); }

//Used for testing purposes
inline int Robot::numeroAtras() const { return CNYAtras.numero(); }
inline int Robot::numeroIzq() const { return CNYIzq.numero(); }
inline int Robot::numeroDcha() const { return CNYDcha.numero(); }

inline void Robot::motorIzqDelante(unsigned v) { MIzq.delante(v); }
inline void Robot::motorDchaDelante(unsigned v) { MDcha.delante(v); }
inline void Robot::motorIzqDetras(unsigned v) { MIzq.detras(v); }
inline void Robot::motorDchaDetras(unsigned v) { MDcha.detras(v); }
inline void Robot::motorIzqParar() { MIzq.parar(); }
inline void Robot::motorDchaParar() { MDcha.parar(); }

#endif
