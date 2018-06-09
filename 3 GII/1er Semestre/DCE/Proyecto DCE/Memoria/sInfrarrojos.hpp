 #ifndef _SINFRARROJOS_HPP_
#define _SINFRARROJOS_HPP_

class sInfrarrojos {

public:

	sInfrarrojos(int p);

	float distancia();

private:

	int pin;

};

inline sInfrarrojos::sInfrarrojos(int p): pin{p} { pinMode(p, INPUT); }
inline float sInfrarrojos::distancia() {

	float V = analogRead(pin) * 0.00488f;

	if(V > 0.5f && V < 2.7f)
		return 12.0f/(V - 0.2f) + 0.42f;
	else if(V <= 0.5f)
    return 60.0f;
  else if(V >= 2.7f)
    return 8.0f;
}

#endif
