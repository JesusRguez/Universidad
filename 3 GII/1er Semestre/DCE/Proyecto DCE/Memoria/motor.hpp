#ifndef _MOTOR_HPP_
#define _MOTOR_HPP_

class motor {

public:

	motor(int p1, int p2);

	void delante(unsigned v);	//v is a value betwwen 0 and 255
	void detras(unsigned v);		//0 = stopped, 255 = full speed
	void parar();

private:

	int pin1;
	int pin2;
};

inline motor::motor(int p1, int p2): pin1{p1}, pin2{p2} { pinMode(p1,OUTPUT); pinMode(p2,OUTPUT); }

inline void motor::delante(unsigned v) {

  if(v > 255)
    v = 255;

	digitalWrite(pin1,LOW);
	analogWrite(pin2,v);
}

inline void motor::detras(unsigned v) {

  if(v > 255)
    v = 255;
  
	digitalWrite(pin2,LOW);
	analogWrite(pin1,v);
}

inline void motor::parar() {

	digitalWrite(pin1,LOW);
	digitalWrite(pin2,LOW);
}

#endif
