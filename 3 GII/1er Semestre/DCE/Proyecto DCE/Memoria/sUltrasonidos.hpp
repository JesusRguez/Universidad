#ifndef _SULTRASONIDOS_HPP_
#define _SULTRASONIDOS_HPP_

class sUltrasonidos {

public:

	sUltrasonidos(int p);

	float distancia();	//returns measured distance in cm

private:

	int pin;

};

inline sUltrasonidos::sUltrasonidos(int p): pin{p} {}

inline float sUltrasonidos::distancia() {

	pinMode(pin,OUTPUT);

	digitalWrite(pin,LOW);
	delayMicroseconds(5);

	digitalWrite(pin,HIGH);
	delayMicroseconds(10);
	digitalWrite(pin,LOW);

	pinMode(pin,INPUT);

	return 0.017f * pulseIn(pin,HIGH);
}

#endif