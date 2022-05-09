#include <Wire.h>  
#define echoPin 7 
#define trigPin 8   



long duration, distance; 
int sensorCounter = 0;   
int lastsensorDistance = 0;
int setCounter = 20;
int incomingByte;

void setup() {
 Serial.begin (9600);

 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop() {

  


  if (Serial.available() > 0) {            
  incomingByte = Serial.read();            
  if (incomingByte == 'R') {              
      Serial.println("Reset");
      sensorCounter = 20;

    }
  }
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 

 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = duration/58.2;

 if (distance <= 20 && lastsensorDistance >= 100){
      sensorCounter++;
    Serial.print("number of counts:  ");
    Serial.println(sensorCounter);
   Serial.println(distance);
   }
   
 else {
  
  //Serial.println("off");   not needed.

  }

  lastsensorDistance = distance;
  delay(500); 
}
