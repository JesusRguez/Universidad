int GreenLED = 2;
int PushButton = 12;

int Value_PushButton = 0;

void setup() {
  pinMode(GreenLED, OUTPUT);
  pinMode(PushButton, INPUT);

}
/*Pull down*/
void loop() {
  Value_PushButton = digitalRead(PushButton);

  if(Value_PushButton == HIGH)
  {
    digitalWrite(GreenLED, HIGH);
  }
  else
  {
    digitalWrite(GreenLED, LOW);
  }

}
