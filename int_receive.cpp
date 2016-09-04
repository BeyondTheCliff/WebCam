#include "Arduino.h"
#include <Servo.h>

Servo myservo;

int inputString=-1;
int LED=10;
int pos=0;


void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(pos);
}

void loop()
{
  if(Serial.available()){
    inputString=Serial.read();
    Serial.println(inputString);
  }
  if(inputString==255){
    digitalWrite(LED,HIGH);
    inputString=-1;
  }
  if((inputString>=0) && (inputString<=180)){
    pos=inputString;
    myservo.write(pos);
    inputString=-1;
  }
  if(inputString==200){
    Serial.println(pos);
    inputString=-1;
  }
}
