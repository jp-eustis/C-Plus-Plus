int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;


void setup() {
Serial.begin(9600);
  // put your setup code here, to run once
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);


     while (millis() < 5000) {
      sensorValue = analogRead(A0);
        if (sensorValue > sensorHigh) {
          sensorHigh = sensorValue;
        }

         if (sensorValue < sensorLow) {
          sensorLow = sensorValue;
        }             
    }    
 
}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue = analogRead(A0);
  
int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

tone(8, pitch, 20);

if(sensorValue>100){
analogWrite(5,HIGH);
analogWrite(6,HIGH);
analogWrite(9,HIGH);
}

if(sensorValue < 100 && sensorValue>50){
analogWrite(5,HIGH);
analogWrite(6,HIGH);
analogWrite(9,LOW);
}

if(sensorValue<50){
analogWrite(5,HIGH);
analogWrite(6,LOW);
analogWrite(9,LOW);
}


delay(10);

Serial.println(sensorValue);

}
