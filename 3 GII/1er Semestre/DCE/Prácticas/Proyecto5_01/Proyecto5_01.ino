const float ResolutionADC=0.00488; //4.88mV
const int delante=A5;
const int izquierdo=A0;
const int derecho=A1;
const int OUT_LED=8;
int Value_CNY_Pin=0;
float Voltage;
void setup(){
 Serial1.begin(9600); //Enable the serial port
 pinMode(OUT_LED,OUTPUT);
}

void loop(){
// Reads the sensor and return a value between 0-1023
Serial1.println("DELANTE:");
 Value_CNY_Pin=analogRead(delante);

// Calculates the equivalent voltage
   Voltage=Value_CNY_Pin*ResolutionADC;
   
   Serial1.println (Value_CNY_Pin);
   Serial1.print (" Voltage: ");
   Serial1.print (Voltage);
   Serial1.println (" V");

   if(Value_CNY_Pin <= 600){
  digitalWrite(OUT_LED,HIGH);
  Serial1.println("NEGRO");
}else{
  digitalWrite(OUT_LED,LOW);
  Serial1.println("BLANCO");
}

Serial1.println();
Serial1.println("DERECHO");

      Value_CNY_Pin=analogRead(derecho);

// Calculates the equivalent voltage
   Voltage=Value_CNY_Pin*ResolutionADC;
   
   Serial1.println (Value_CNY_Pin);
   Serial1.print (" Voltage: ");
   Serial1.print (Voltage);
   Serial1.println (" V");

   if(Value_CNY_Pin <= 600){
  digitalWrite(OUT_LED,HIGH);
  Serial1.println("NEGRO");
}else{
  digitalWrite(OUT_LED,LOW);
  Serial1.println("BLANCO");
}
Serial1.println();
  Serial1.println("IZQUIERDO:");
  Value_CNY_Pin=analogRead(izquierdo);

// Calculates the equivalent voltage
   Voltage=Value_CNY_Pin*ResolutionADC;
   
   Serial1.println (Value_CNY_Pin);
   Serial1.print (" Voltage: ");
   Serial1.print (Voltage);
   Serial1.println (" V");

   if(Value_CNY_Pin <= 600){
  digitalWrite(OUT_LED,HIGH);
  Serial1.println("NEGRO");
}else{
  digitalWrite(OUT_LED,LOW);
  Serial1.println("BLANCO");
}
Serial1.println();
Serial1.println();
   delay(2000);
}
