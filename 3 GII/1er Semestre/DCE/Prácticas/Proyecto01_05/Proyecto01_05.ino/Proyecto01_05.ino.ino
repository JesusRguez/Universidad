int GreenLED = 2; //Alias for LED pin
int PushButton = 12;  //Alias for Pushbutton pin

int First_Value_PushButton = 1; //It stores th FIRST reading
int Second_Value_PushButton = 0; //It stores the SECOND reading


boolean StateLED=false; //Variable to store the state of the LED

void setup() {
  pinMode(GreenLED, OUTPUT);
  pinMode(PushButton, INPUT_PULLUP);  //Set PushPin as INPUT and
  //enable the internal Pull-up resistor

}
/*Pull up*/
void loop() {

  //First time, "First_ValPush" is the initialized value
  //Microcontroler reads a second value from the button
  Second_Value_PushButton = digitalRead(PushButton);
  

  //Check if the input is LOW (button is pressed) and change the "state"

  if((First_Value_PushButton == HIGH) && (Second_Value_PushButton == LOW))
  {
    StateLED = ! StateLED;  //Toggle the value of state
  }

  First_Value_PushButton = Second_Value_PushButton;

  if(StateLED == true)
  {
    digitalWrite(GreenLED, HIGH);
  }
  else
  {
    digitalWrite(GreenLED, LOW);
  }

}
