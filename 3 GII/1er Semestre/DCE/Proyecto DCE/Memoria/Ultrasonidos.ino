float distance;
unsigned long time_bounce;
const int pin = A3;

void setup() {
    Serial.begin(9600); // Setup the serial port
}

void loop() {
    digitalWrite(pin, LOW);
    delayMicroseconds(5);

    /* Send a pulse HIGH for 10 us (According to datasheet) */
    digitalWrite(pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin, LOW);
 
    pinMode(pin,INPUT);

    time_bounce = pulseIn(pin, HIGH);

 
    /* Formula to figure out the distance
    * speed = space /time --> space = speed * time
    * sound speed = 340 m/s --> 0.034 cm/us
    * space --> to travel from the sensor to the object and from de object to
    * sensor distance to object = space / 2
    */
 
    distance = 0.017 * time_bounce; //Formula para calcular la distancia
 
    /*Show in cm the distance measured, by serial monitor */
 
    Serial.println("Distancia ");
    Serial.print(distance);
    Serial.println(" cm");
    
    delay(1000);
}
