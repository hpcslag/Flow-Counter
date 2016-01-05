#include "Timer.h"
const int PIRSensorPin = 12;
int people = 0;
Timer t;

void setup() {
  Serial.begin(9600);
  pinMode(PIRSensorPin,INPUT); //pin 12 is PIR Sensor
  pinMode(13,OUTPUT);
  delay(5000);
}

boolean status = false;

void loop() {
  if(digitalRead(PIRSensorPin) == HIGH){
    if(status == false){
      //addReadPeople(); if you want show in the command line
      returnStatus();
      status = true;
    }
    t.every(5000,addReadPeople, 0);
    digitalWrite(13,HIGH);
    Serial.println(people);
  }else{
    status = false;
    returnStatus();
    //Serial.println("NO ANYONE THROUGH HERE."); if you want show in the command line
    digitalWrite(13,LOW);
  }
}

void returnStatus(){
  Serial.println(status);
}

void addReadPeople(){
  people = people + 1;
}
