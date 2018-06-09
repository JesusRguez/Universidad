int GreenLED = 11;
int RedLED = 12;

void setup() {
  pinMode(GreenLED, OUTPUT);
  pinMode(RedLED, OUTPUT);

}

void loop() {
  /*Práctica en cuestión*/
  digitalWrite(GreenLED, HIGH);
  digitalWrite(RedLED, LOW);

  delay(1000);

  digitalWrite(RedLED, HIGH);
  digitalWrite(GreenLED, LOW);

  delay(1000);

  /*MORSE SOS del jp:
  digitalWrite(GreenLED, HIGH);
  delay(200);
  digitalWrite(GreenLED, LOW);
  delay(200);
    digitalWrite(GreenLED, HIGH);
  delay(200);
  digitalWrite(GreenLED, LOW);
  delay(200);
    digitalWrite(GreenLED, HIGH);
  delay(200);
  digitalWrite(GreenLED, LOW);
  delay(800);
  
    digitalWrite(GreenLED, HIGH);
  delay(400);
  digitalWrite(GreenLED, LOW);
  delay(400);
    digitalWrite(GreenLED, HIGH);
  delay(400);
  digitalWrite(GreenLED, LOW);
  delay(400);
    digitalWrite(GreenLED, HIGH);
  delay(400);
  digitalWrite(GreenLED, LOW);
  delay(800);

    digitalWrite(GreenLED, HIGH);
  delay(200);
  digitalWrite(GreenLED, LOW);
  delay(200);
    digitalWrite(GreenLED, HIGH);
  delay(200);
  digitalWrite(GreenLED, LOW);
  delay(200);
    digitalWrite(GreenLED, HIGH);
  delay(200);
  digitalWrite(GreenLED, LOW);
  delay(1000);*/
  
}
