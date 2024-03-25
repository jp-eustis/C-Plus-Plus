
#include <Servo.h>



Servo myServo;

float angle=0;

const int trigPin = 5;
const int echoPin = 6;

long duration;
int distance;

float vel = 1;
void setup() {


  myServo.attach(3);
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {

 
  angle+=vel;
  myServo.write(angle);


if(angle>=180 || angle<=0){
  vel=-vel;
}
  

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  Serial.print(angle);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(",$\n");

  delay(17);
}
  
