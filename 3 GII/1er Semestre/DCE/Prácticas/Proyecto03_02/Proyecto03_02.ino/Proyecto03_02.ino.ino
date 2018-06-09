//Fade an LEd in and out
const int LedPin=9; //LED
int i=0;

void setup() {
  pinMode(LedPin, OUTPUT); //setup LedPin as an output
}

void loop() {
  for(i=0;i<255;i++){
    analogWrite(LedPin, i);
    delay(10);
  }
  for(i=255;i>0;i--){
    analogWrite(LedPin,i);
    delay(10);
  }
}
