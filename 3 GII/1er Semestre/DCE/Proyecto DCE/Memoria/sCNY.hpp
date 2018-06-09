#ifndef _SCNY_HPP_
#define _SCNY_HPP_

#define REF_NEGRO 750 //values above this value are treated as black colour

class sCNY {

public:

	sCNY(int p);

	bool negro();	//returns true when the black line is below it
  int numero(); //testing

private:

	int pin;

};

inline sCNY::sCNY(int p): pin{p} { pinMode(p,INPUT); }

inline bool sCNY::negro() {	return (analogRead(pin) > REF_NEGRO); }

//testing
inline int sCNY::numero() { return analogRead(pin); }


#endif
