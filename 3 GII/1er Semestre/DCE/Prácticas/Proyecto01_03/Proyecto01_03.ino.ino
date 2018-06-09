int GreenLED = 2; //Alias for LED pin
int PushButton = 12;  //Alias for Pushbutton pin

int Value_PushButton = 0; //Variable to store the push value

void setup() {
  pinMode(GreenLED, OUTPUT);
  pinMode(PushButton, INPUT_PULLUP);  //Set PushPin as INPUT and
  //enable the internal Pull-up resistor

}
/*Pull up*/
void loop() {
  Value_PushButton = digitalRead(PushButton);

  if(Value_PushButton == LOW)
  {
    digitalWrite(GreenLED, LOW);
  }
  else
  {
    digitalWrite(GreenLED, HIGH);
  }

}
