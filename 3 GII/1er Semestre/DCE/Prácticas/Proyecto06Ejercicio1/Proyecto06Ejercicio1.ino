const float ResolutionADC=0.00488; //4.88mV
const int Sharp_Pin=A0;
int Value_Sharp_Pin=0;
float Voltage;

void setup(){
    Serial.begin(9600); //Enable the serial port
}

void loop(){
  // Reads the sensor and return a value between 0-1023
   Value_Sharp_Pin=analogRead(Sharp_Pin);

  // Calculates the equivalent voltage
   Voltage=Value_Sharp_Pin*ResolutionADC;

   Serial.println (Value_Sharp_Pin);
   Serial.print (" Voltage: ");
   Serial.print (Voltage);
   Serial.println (" V");
   Serial.print (" Distancia: ");
   Serial.print(distancia(Voltage));
   Serial.println(" cm");
   
   
 delay(1000);
}

  float distancia(float Voltage)
  {
    if((Voltage > 0.5 && Voltage<2.7))
    {
     //float inv_dist = (0.1*Voltage) -0.05;
      //float inv_dist=(Voltage/9.21)-0.58;
      //return  1/(inv_dist+0.42);
      //return -0.42 + (1/inv_dist);
      return (11/(Voltage-0.15)) - 0.42;
    }
    else
    {
      return 0;
    }
  }
    



