//Variables and constants
const int led = 11;
char letter; //Variable to store the read key
boolean StateLed=false; //It warns about the LED state

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop(){
  //It checks when a byte is received
  if(Serial.available()>0){
    letter=Serial.read();
    Serial.println("Se ha leido el byte");
    //It checks what key is pressed and what is the LED state
    switch(letter){
      case 'y':
        digitalWrite(led, HIGH);
        break;
      case 'n':
        digitalWrite(led, LOW);
        break;
      default:
        break;
    }
    
    
    /*if(letter=='y'&&(StateLed==false)){
      digitalWrite(led,HIGH);
      StateLed=true; //Update the LED state
      Serial.println("Se ha encendido");
    }else if(letter=='n'){
      digitalWrite(led, LOW);
      StateLed=false; //Update the LED state
      Serial.println("Se ha encendido");
    }*/
    delay(200);
  }
}

