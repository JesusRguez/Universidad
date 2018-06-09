//Fade an LEd in and out
const int LedPin=9; //LED
int i=0;
int AnalogValue=0;
int AnalogOutput=0;

void setup() {
  pinMode(LedPin, OUTPUT); //setup LedPin as an output
}

/*void loop() {
  for(i=0;i<255;i++){
    analogWrite(LedPin, i);
    delay(10);
  }
  for(i=255;i>0;i--){
    analogWrite(LedPin,i);
    delay(10);
  }
}*/
void loop(){
    //Read the pontenciometer
  AnalogValue=analogRead(A0);

  //Show the read data in the console
  Serial.print(AnalogValue);
  Serial.print(": ");
  Serial.print(AnalogValue*0.00488);
  Serial.println("V");

  //Check value to switch on or off the LED
  AnalogOutput=map(AnalogValue, 0, 1023, 0, 255);
  analogWrite(LedPin,AnalogOutput);
  delay(200);
}

