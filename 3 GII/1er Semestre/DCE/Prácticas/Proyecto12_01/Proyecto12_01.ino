#include <Servo.h> // Servo's library
Servo miservo;    //It declares servo object
int angulo=0;
const int pin = 11;
void setup()
{
  pinMode(pin,OUTPUT);
 miservo.attach(9,1000,2000); //Set the pin to attach the servo
}
void loop() {
  //Neutral position
   miservo.write(90);
      //digitalWrite(pin,HIGH);
      //delayMicroseconds(1000);
      //digitalWrite(pin,LOW);
   delay(200);
   //Decrease the angle from 90
  for(angulo =90; angulo >0; angulo --)
     {
      //digitalWrite(pin,HIGH);
      //delayMicroseconds(150*angulo);
      //digitalWrite(pin,LOW);

      miservo.writeMicroseconds(16*angulo);
      miservo.write(angulo);
       delay(100);
     }
     //
 delay(200);
}
