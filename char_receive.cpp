#include "Arduino.h"
#include <Servo.h>

Servo myservo;

char inputString='-';
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
    Serial.println(String(inputString));
  }
  if(inputString=='H'){
    digitalWrite(LED,HIGH);
    inputString='-';
  }
  if(inputString=='h'){
    digitalWrite(LED,LOW);
    inputString='-';
  }
  if(inputString==']'){
    if(pos<180){
      pos=pos+1;
    }
    Serial.println(pos);
    myservo.write(pos);
    inputString='-';
  }
  if(inputString=='['){
    if(pos>0){
      pos=pos-1;
    }
    Serial.println(pos);
    myservo.write(pos);
    inputString='-';
  }
  if(inputString=='x'){
    pos=0;
    myservo.write(pos);
    Serial.println(pos);
    inputString='-';
  }
  if(inputString=='F'){
    Serial.println(pos);
    inputString='-';
  }
}
