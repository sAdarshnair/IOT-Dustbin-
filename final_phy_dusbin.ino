#include <dht.h>

dht DHT;
#define DHT11_PIN A0

int echo = 7; 
int trig = 6;

int distance;
long duration;
float initialHumidity = 0.0;
float finalHumidity = 0.0;

void setup() {    
  
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(10, OUTPUT); 
    pinMode(8, OUTPUT); 
    pinMode(9, OUTPUT); 
    pinMode(3, OUTPUT); 
    pinMode(4, OUTPUT); 

    Serial.begin(9600);
    

} 

void loop() {
        // Read initial humidity value

  
    digitalWrite(trig, 0);
    digitalWrite(trig, 1);
    delayMicroseconds(10);
    digitalWrite(trig, 0);
    duration = pulseIn(echo, 1);
    distance = duration * 0.034 / 2;
        Serial.print("distance:  ");

    Serial.println(distance);


    if (distance < 30) {
        digitalWrite(9, HIGH);
        digitalWrite(8, LOW);
      
        delay(400);
  
        digitalWrite(9, LOW);
        int chk = DHT.read11(DHT11_PIN);
        initialHumidity = DHT.humidity; 
                analogWrite(A0,0);



    

    
        // Read final humidity value
        
        for(int i=0; i<=200;i++){
        chk = DHT.read11(DHT11_PIN);
        finalHumidity = DHT.humidity;
              }
        delay(1000);
        

        Serial.print("Initial Humidity: ");
        Serial.println(initialHumidity);
        Serial.print("Final Humidity: ");
        Serial.println(finalHumidity);
        delay(2000);

        if (finalHumidity > initialHumidity) {
            digitalWrite(3, 0);
            digitalWrite(4, 1);
            delay(1300);
            digitalWrite(3, 1);
            delay(3000);
            digitalWrite(3, 1);
            digitalWrite(4, 0);
            delay(1300);
            digitalWrite(3, 0);
        } else {
            digitalWrite(3, 1);
            digitalWrite(4, 0);
            delay(1400);
            digitalWrite(3, 0);
            delay(3000);
            digitalWrite(3, 0);
            digitalWrite(4, 1);
            delay(1400);
            digitalWrite(4, 0);
        }

        digitalWrite(8, 1);
        digitalWrite(9, 0);
        delay(1000);
        
        chk = DHT.read11(DHT11_PIN);
        initialHumidity = DHT.humidity;
        Serial.print("Final test Humidity: ");

        Serial.println(initialHumidity);
         delay(500);
    }
}
