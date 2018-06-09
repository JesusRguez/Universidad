#include "Robot.hpp"
#include <StandardCplusplus.h>
#include <stack>
#include <vector>

//Global vars
// *************************************************************************

Robot R;                                            //The robot itself
bool ultimoMuroDelante = true;                      //Since we cannot tell if
                                                    //there's a wall behind us,
                                                    //whenever the robot moves
                                                    //forward, the next scan
                                                    //will assign this value to
                                                    //wall behind
bool vueltaDelante, vueltaIzquierda, vueltaDerecha; //If it moved behind last
                                                    //time, we don't want to
                                                    //move forward until
                                                    //there's a change of
                                                    //direction, same with left
                                                    //and right
std::stack<char,std::vector<int>> pila;             //Stores movements, used
                                                    //when going back to the
                                                    //starting cell
bool alcanzada, fin;                                //Wheter the robot has
                                                    //reached the end, and
                                                    //wheter it came back

// **************************************************************************

//Functions and procedures declarations
//---------------------------------------------------------------------------

//Scans the cell around the robot, returning a "celda" object with information
//about where are the walls around it id any.
celda escanear(const Robot& R);

//Returns true if the robot reached the final (fully black) cell
bool meta(const Robot& R);

//Moves the robot until it reaches the next cell, and stops it in the middle
void moverDelante(Robot& R);
void moverDetras(Robot& R);

//Turns the robot 90 degrees right/left
void girarDerecha(Robot& R);
void girarIzquierda(Robot& R);

//---------------------------------------------------------------------------

void setup() {

  Serial1.begin(9600);  //Enabling Bluetooth

  vueltaDelante = false;
  vueltaIzquierda = false;
  vueltaDerecha = false;
  ultimoMuroDelante = true;
  alcanzada = false;
  fin=false;

  char e = 0;

  while(e != 'e')
    if(Serial1.available() != 0)
      e = Serial1.read();

  Serial1.print("e");
}

void loop() {
  
  if(!alcanzada && !meta(R)){

    celda c = escanear(R,ultimoMuroDelante);

  if(!c.delante)
    Serial1.print("O");
  else
    Serial1.print("X");

  if(!c.izquierda)
    Serial1.print("O");
  else
    Serial1.print("X");

  if(!c.derecha)
    Serial1.print("O");
  else
    Serial1.print("X");

  if(!c.detras)
    Serial1.print("O");
  else
    Serial1.print("X");
  
    //Movement priorities: right > front > left > back
    if(!c.derecha && !vueltaDerecha) {
      ultimoMuroDelante = c.derecha;
      girarDerecha(R);
      moverDelante(R);
      Serial1.print("2");
      vueltaIzquierda = false;
      vueltaDerecha = false;
      vueltaDelante = false;
      pila.push('R');
    }
    else if(!c.delante && !vueltaDelante) {
      moverDelante(R);
      Serial1.print("0");
      ultimoMuroDelante = c.delante;
      vueltaIzquierda = false;
      vueltaDerecha = false;
      vueltaDelante = false;
      pila.push('F');
    }
    else if(!c.izquierda && !vueltaIzquierda){
      ultimoMuroDelante = c.izquierda;
      girarIzquierda(R);
      moverDelante(R);
      Serial1.print("1");
      vueltaIzquierda = false;
      vueltaDerecha = false;
      vueltaDelante = false;
      pila.push('L');
    }
    else if(!c.detras){
      moverDetras(R);

      char mov = 'F';

      if(!pila.empty()){
        mov = pila.top();
        pila.pop();
      }
      
      if(mov == 'F'){
        vueltaDelante = true;
        vueltaIzquierda = false;
        vueltaDerecha = false;
        Serial1.print("3");
      }
      if(mov == 'R'){
        girarIzquierda(R);
        vueltaDerecha = true;
        vueltaDelante = false;
        vueltaIzquierda = false;
        Serial1.print("4");
      }
      if(mov == 'L'){
        girarDerecha(R);
        vueltaIzquierda = true;
        vueltaDelante = false;
        vueltaDerecha = false;
        Serial1.print("5");
      }
    }
  }
  else if(!fin){  //Going back to the starting cell

    Serial1.print("t");
    alcanzada = true;
    girarDerecha(R);  //180 degree turn
    girarDerecha(R);

    
    
    while(!pila.empty()) {
        char mov = pila.top();
        pila.pop();

        switch(mov) {
          
          case 'R': //If it went to the right, goes forward then turns left
            moverDelante(R);
            girarIzquierda(R);
            break;
          case 'F': //If it went forwards, simply goes forward as well
            moverDelante(R);
            break;
          case 'L': //If it went to the left, goes forward then turns right
            moverDelante(R);
            girarDerecha(R);
          }
      }
      fin = true;
  }

  while(fin)
    delay(100000000);
  
}

//Functions and procedures implementations
//---------------------------------------------------------------------------

bool meta(const Robot& R) { 

  int escaneos = 3;
  bool b = true;

  for(int i=0; i< escaneos; ++i) {
    b &= (R.negroAtras() && R.negroIzq() && R.negroDcha());
    delay(100);
  }
  
  return b;

}

celda escanear(const Robot& R, bool& ultimoMuroDelante) {

  float delante=0.0f, izquierda=0.0f, derecha=0.0f;
  int escaneos = 5;

  
  for(int i=0; i<escaneos; ++i){
    delante += R.distanciaDelante();
    izquierda += R.distanciaIzq();
    derecha += R.distanciaDcha();
    delay(100);
  }  
  //Cell width and length is 20 cm
  return celda( (delante/float(escaneos)) <= 20.0f,   //front
                ultimoMuroDelante,                    //behind, equal to last
                                                      //front read
                (izquierda/float(escaneos)) <= 20.0f, //left
                (derecha/float(escaneos)) <= 20.0f ); //right
}

void moverDelante(Robot& R) {

  unsigned v = 255; //speed
  
  R.motorIzqDelante(v); //Forward both ...
  R.motorDchaDelante(v);


  while(!R.negroIzq() && !R.negroDcha()); // ... while no CNY detects black

  R.motorIzqParar();    //Stops both once one of them does
  R.motorDchaParar();

  delay(200);
  
  //Moves forward the wheel which does not have black under it, so both end
  //lined up. The robot is just about to enter the new cell now
  if(!R.negroIzq()) {
    R.motorIzqDelante(v);
    while(!R.negroIzq());
    delay(200);
    R.motorIzqParar();
  }
  else if(!R.negroDcha()) {
    R.motorDchaDelante(v);
    while(!R.negroDcha());
    delay(200);
    R.motorDchaParar();
  }
  
  R.motorIzqDelante(v); //Forward for a while, then it stops around the middle
  R.motorDchaDelante(v);

  delay(1200);

  R.motorIzqParar();
  R.motorDchaParar();
}

void moverDetras(Robot& R) {  //The same, but backwards

  unsigned v = 255;

  R.motorIzqDetras(v);
  R.motorDchaDetras(v);

  while(!R.negroIzq() && !R.negroDcha());

  R.motorIzqParar();
  R.motorDchaParar();

  delay(200);

  if(!R.negroIzq()) {
    R.motorIzqDetras(v);
    while(!R.negroIzq());
    delay(200);
    R.motorIzqParar();
  }
  else if(!R.negroDcha()) {
    R.motorDchaDetras(v);
    while(!R.negroDcha());
    delay(200);
    R.motorDchaParar();
  }

  R.motorIzqDetras(v);
  R.motorDchaDetras(v);

  delay(600);

  R.motorIzqParar();
  R.motorDchaParar();
}

void girarDerecha(Robot& R) {

  unsigned v = 255;

  R.motorIzqDelante(v); //Left wheel forward, right one backwards, so it turns
                        //in place to the right.
  R.motorDchaDetras(v);

  delay(800);  //Stops once it has completed around a 90 degrees turn

  R.motorIzqParar();
  R.motorDchaParar();
}

void girarIzquierda(Robot& R) { //The same, but to the left

  unsigned v = 255;

  R.motorDchaDelante(v);
  R.motorIzqDetras(v);

  delay(800);

  R.motorDchaParar();
  R.motorIzqParar();
}
