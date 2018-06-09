int GreenLED = 2; //Alias for LED pin
int PushButton = 12;  //Alias for Pushbutton pin

int Value_PushButton = 0; //Variable to store the push value

boolean StateLED=false; //Variable to store the state of the LED

void setup() {
  pinMode(GreenLED, OUTPUT);
  pinMode(PushButton, INPUT_PULLUP);  //Set PushPin as INPUT and
  //enable the internal Pull-up resistor

}
/*Pull up*/
void loop() {
  Value_PushButton = digitalRead(PushButton); //Read the button

  //Check if the input is LOW (button is pressed) and change the "state"

  if(Value_PushButton == LOW)
  {
    StateLED = ! StateLED;  //Toggle the value of state
  }

  if(StateLED == true)
  {
    digitalWrite(GreenLED, HIGH);
  }
  else
  {
    digitalWrite(GreenLED, LOW);
  }

}
