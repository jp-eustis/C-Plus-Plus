#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4,2);

int threshold = 1000;
int lightDelay = 100;
const int red1Pin=13;
const int red2Pin=12;
const int yellow1Pin = 11;
const int greenPin=10;
const int yellow2Pin=9;
const int red3Pin=8;
const int red4Pin=7;
int lights[]={7,8,9,10,11,12,13};
int dir=1;
int curr=0;
int timeMark = 0;

int const potPin = A0;
int potVal;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(red1Pin,OUTPUT);
  pinMode(red2Pin,OUTPUT);
  pinMode(yellow1Pin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(yellow2Pin,OUTPUT);
  pinMode(red3Pin,OUTPUT);
  pinMode(red4Pin,OUTPUT);
}

void loop() {
 // potVal = analogRead(potPin);

  
  long sensorValue = capSensor.capacitiveSensor(30);
if(sensorValue<threshold){
  if(millis() - timeMark > lightDelay) {
    turnLightsOff();
    Serial.println(curr);
    curr += dir;
    timeMark = millis();
    if(curr == 6 || curr == 0) {
      dir = -dir;
      Serial.println("switching direction");
    }
  }
  digitalWrite(lights[curr], HIGH);

  }


if(sensorValue >= threshold){
  digitalWrite(lights[curr],HIGH);
  if(curr==4){
    lightDelay-50;
    
  }
}
}
void turnLightsOff() {
  for(int i=0;i<7;i++) {
    digitalWrite(lights[i],LOW);
  }
}
