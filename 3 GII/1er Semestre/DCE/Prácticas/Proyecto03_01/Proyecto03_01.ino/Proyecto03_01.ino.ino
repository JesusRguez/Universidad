const int LedPin=9;
int AnalogValue=0;

void setup() {
  //Open and set the baudrate for the Serial port (9600 baudios)
  pinMode(LedPin, OUTPUT);

  Serial.begin(9600);

}

void loop() {
  //Read the pontenciometer
  AnalogValue=analogRead(A0);

  //Show the read data in the console
  Serial.print(AnalogValue);
  Serial.print(": ");
  Serial.print(AnalogValue*0.00488);
  Serial.println("V");

  //Check value to switch on or off the LED
  if(AnalogValue>=500){
    digitalWrite(LedPin, HIGH);
  }else{
    digitalWrite(LedPin, LOW);
  }
  delay(200);
}
