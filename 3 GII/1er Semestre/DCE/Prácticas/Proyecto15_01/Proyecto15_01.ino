//Variables and constants
const int led = 11;
char letter; //Variable to store the read key
boolean StateLed=false; //It warns about the LED state

void setup() {
  Serial1.begin(9600);
  //pinMode(led, OUTPUT);
}

void loop(){
  //It checks when a byte is received
  //if(Serial1.available()>0){
    /*letter=Serial.read();
    Serial1.println("Se ha leido el byte");
    //It checks what key is pressed and what is the LED state
    if(((letter=='a')||(letter=='e')||(letter=='i')||(letter=='o')||(letter=='u'))&&(StateLed==false)){
      digitalWrite(led,HIGH);
      StateLed=true; //Update the LED state
      Serial1.println("Se ha encendido");
    }else{
      digitalWrite(led, LOW);
      StateLed=false; //Update the LED state
      Serial1.println("Se ha encendido");
    }*/
    Serial1.println("Hola bluetooth.");
    delay(200);
  //}
}

