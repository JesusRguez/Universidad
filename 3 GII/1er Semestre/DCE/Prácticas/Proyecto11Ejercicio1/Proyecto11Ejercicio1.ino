//Giro alterno con motro DX con driver L293D
const int in1Pin=10;
const int in2Pin=11;

int SpeedMotor;
void setup() {
  // put your setup code here, to run once:
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop() {
  
  SpeedMotor=analogRead(A0);
  setMotor(SpeedMotor);
  
  
}

void setMotor(int SpeedMotor){
  int velocidad;
  if(SpeedMotor<500){
    //Gira a la izquierda
    velocidad=map(SpeedMotor, 0, 500, 255, 0);
    analogWrite(in1Pin, velocidad);
    analogWrite(in2Pin, 0);
  }else if(SpeedMotor>=500 && SpeedMotor<523){
    analogWrite(in1Pin, 0);
    analogWrite(in2Pin, 0);
  }else{
    //Gira a la derecha
    velocidad=map(SpeedMotor, 523, 1023, 0, 255);
    analogWrite(in1Pin, 0);
    analogWrite(in2Pin, SpeedMotor);
  }
}

