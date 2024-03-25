#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;
int left = 0;
int right = 0;
int moveNum = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);

  Serial.begin(9600);

  pinMode(10,INPUT);
  pinMode(11,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  left = digitalRead(10);
  right = digitalRead(11);


  if(left == HIGH){
    moveNum++;
  }    

  if(right == HIGH){
    moveNum--;
  }
  Serial.print("Move Number: ");
  Serial.print(moveNum);

  angle = map(moveNum*25, 0, 1023, 0, 179);
  Serial.print("    angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);

}
