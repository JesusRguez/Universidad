const float ResolutionADC=0.00488; //4.88mV
const int CNY_Pin=A0;
const int OUT_LED=8;
int Value_CNY_Pin=0;
float Voltage;
void setup(){
 Serial.begin(9600); //Enable the serial port
 pinMode(OUT_LED,OUTPUT);
}

void loop(){
// Reads the sensor and return a value between 0-1023
 Value_CNY_Pin=analogRead(CNY_Pin);


  
// Calculates the equivalent voltage
   Voltage=Value_CNY_Pin*ResolutionADC;
   
   Serial.println (Value_CNY_Pin);
   Serial.print (" Voltage: ");
   Serial.print (Voltage);
   Serial.println (" V");

   if(Value_CNY_Pin <= 20){
  digitalWrite(OUT_LED,HIGH);
  Serial.println("NEGRO");
}else{
  digitalWrite(OUT_LED,LOW);
  Serial.println("BLANCO");
}
    
   delay(1000);
}
