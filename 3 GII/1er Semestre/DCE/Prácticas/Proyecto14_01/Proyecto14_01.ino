volatile int numInterrupt = 0;
volatile bool stateled=false;
void setup() {
 pinMode(3,INPUT_PULLUP);
 pinMode(8,OUTPUT);
 Serial.begin(9600);


 // Sintaxis interrupciones:
 // attachInterrupt(numero_interrupt,función_a_ejecutar,modo);
 // Modos LOW,CHANGE,RISING,FALLING


 //Pin 3 goes from '1' to '0' when pushbuttom is pressed
 attachInterrupt(0, ISR_0, FALLING);
}
void loop() {

 digitalWrite(8,stateled);

 Serial.println(numInterrupt);
 delay (150);
}
void ISR_0() {
 numInterrupt++;
 stateled=!stateled;
}
