//Giro alterno con motro DX con driver L293D
const int in1Pin=10;
const int in2Pin=11;

int PushButton = 12;  //Alias for Pushbutton pin
int First_Value_PushButton = 1; //It stores th FIRST reading
int Second_Value_PushButton = 0; //It stores the SECOND reading
boolean SpinMotor=false; //Variable to store the state of the LED
int SpeedMotor;
void setup() {
  // put your setup code here, to run once:
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(PushButton, INPUT_PULLUP);
}

void loop() {

  //First time, "First_ValPush" is the initialized value
  //Microcontroler reads a second value from the button
  Second_Value_PushButton = digitalRead(PushButton);
  
  //Check if the input is LOW (button is pressed) and change the "state"

  if((First_Value_PushButton == HIGH) && (Second_Value_PushButton == LOW))
  {
    SpinMotor = ! SpinMotor;  //Toggle the value of state
  }

  First_Value_PushButton = Second_Value_PushButton;
  
  SpeedMotor=analogRead(A0);
  setMotor(SpeedMotor, SpinMotor);
  
  
}

void setMotor(int SpeedMotor, boolean SpinMotor){
  //Gira a la izquierda                 
  SpeedMotor=map(SpeedMotor, 0, 1023, 0, 255);
  if(SpinMotor==true){
    //Gira a la izquierda
    analogWrite(in1Pin, SpeedMotor);
    analogWrite(in2Pin, 0);
  }else{
    //Gira a la derecha
    analogWrite(in1Pin, 0);
    analogWrite(in2Pin, SpeedMotor);
  }
}

