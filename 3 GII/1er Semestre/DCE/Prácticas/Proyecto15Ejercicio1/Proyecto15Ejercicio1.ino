int AnalogValue=0;

void setup() {
  Serial.begin(9600);
}

void loop(){
  AnalogValue=analogRead(A0);

  AnalogValue=map(AnalogValue, 0, 1023, 0, 10);
  Serial.println(AnalogValue);
  delay(100);
}

