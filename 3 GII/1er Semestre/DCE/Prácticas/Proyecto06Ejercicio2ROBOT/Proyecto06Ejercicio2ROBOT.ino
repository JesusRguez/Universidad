

void setup() {
  // put your setup code here, to run once:
public class movROBOT(){
  movROBOT(){
    
  }

  void ForwROBOT(int Pin1, Pin2, int velocidad){ //Derecha
    //Los valores recibidos en velocidad serán entre 0 y 255
    analogWrite(Pin1, velocidad);
    analogWrite(Pin2, 0);
  }

  void BackROBOT(int Pin1, Pin2, int velocidad){ //Izquierda
    //Los valores recibidos en velocidad serán entre 0 y 255
    analogWrite(Pin1, 0);
    analogWrite(Pin2, velocidad);
  }
}
}
}

void loop() {
  // put your main code here, to run repeatedly:

}
