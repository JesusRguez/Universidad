//Giro alterno con motro DX con driver L293D
const int M1in1Pin=5;
const int M1in2Pin=6;

const int M2in1Pin=9;
const int M2in2Pin=10;

void setup() {
  // put your setup code here, to run once:
  pinMode(M1in1Pin, OUTPUT);
  pinMode(M1in2Pin, OUTPUT);
  pinMode(M2in1Pin, OUTPUT);
  pinMode(M2in2Pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Gira a la izquierda
  digitalWrite(M1in1Pin, HIGH);
  digitalWrite(M1in2Pin, LOW);
  digitalWrite(M2in1Pin, HIGH);
  digitalWrite(M2in2Pin, LOW);
  delay(3000);
  //Para
  digitalWrite(M1in1Pin, LOW);
  digitalWrite(M1in2Pin, LOW);
  digitalWrite(M2in1Pin, LOW);
  digitalWrite(M2in2Pin, LOW);
  delay(100);
  //Gira a la derecha
  digitalWrite(M1in1Pin, LOW);
  digitalWrite(M1in2Pin, HIGH);
  digitalWrite(M2in1Pin, LOW);
  digitalWrite(M2in2Pin, HIGH);
  delay(3000);
  //Para
  digitalWrite(M1in1Pin, LOW);
  digitalWrite(M1in2Pin, LOW);
  digitalWrite(M2in1Pin, LOW);
  digitalWrite(M2in2Pin, LOW);
  delay(100);
  
}
