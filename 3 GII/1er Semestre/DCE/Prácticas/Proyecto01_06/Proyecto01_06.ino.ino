int myLeds[]={2,3,4,5}; 
int counter=0; 
int Button1=0;
const int PushButton =8; 
int value_PushButton =0;

int SwitchOFF();

void setup(){ 
  pinMode(Button1, INPUT_PULLUP); 
  for (counter=0;counter<5;counter++)
   { 
      pinMode(myLeds[counter],OUTPUT); 
      }
   }
 

 
void loop(){
  //Read the pushbutton
  value_PushButton =digitalRead(PushButton);
  

if (value_PushButton ==LOW )
{ 
  Animation01(100); 
  } else { 
    SwitchOFF();
    }
}

//FUNCTIONS//
int Animation01(int timer){
  //Switch ON or OFF a LED in each iteration
  //from the LED2 to LED5
  for(int counter=0;counter<4;counter++){
    digitalWrite(myLeds[counter],HIGH);
    delay(timer);
    digitalWrite(myLeds[counter],LOW);
    delay(timer);
    }
 }

int SwitchOFF(){
  //Apaga todos los leds
  for(int counter=0;counter<4;counter++){
    digitalWrite(myLeds[counter],LOW);
    }
}
