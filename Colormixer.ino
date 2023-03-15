const int greenLEDPin = 9; 
const int redLEDPin = 11; 
const int blueLEDPin = 10; 
const int redSensorPin = A0;  
const int greenSensorPin = A1;
const int blueSensorPin = A2;
int dimmerPin = A3;

int dimmerVal = 0;
int redValue = 0; 
int greenValue = 0; 
int blueValue = 0;  
int redSensorValue = 0; 
int greenSensorValue = 0; 
int blueSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   

  pinMode(dimmerPin,INPUT);
  pinMode(greenLEDPin,OUTPUT);  
  pinMode(redLEDPin,OUTPUT);  
  pinMode(blueLEDPin,OUTPUT);

 
}

void loop() {

  dimmerVal=analogRead(dimmerPin);
  // put your main code here, to run repeatedly:

 redSensorValue = analogRead(redSensorPin);  
   delay(5);  
 greenSensorValue = analogRead(greenSensorPin);  
  delay(5);  
 blueSensorValue = analogRead(blueSensorPin);
 
  /*
  Serial.print("\t Dimmer:"); 
  Serial.println(dimmerVal);
*/
  
  redValue =  (redSensorValue/4)+(dimmerVal/4);  
  greenValue =  (greenSensorValue/4)+(dimmerVal/4);  
  blueValue = (blueSensorValue/4)+(dimmerVal/4);


  Serial.print("\t Red: "); 
  Serial.print(redValue); 
  Serial.print("\t Green: "); 
  Serial.print(greenValue); 
  Serial.print("\t Blue: "); 
  Serial.println(blueValue); 
 

  analogWrite(redLEDPin, redValue/4);
  analogWrite(greenLEDPin, greenValue/4);
  analogWrite(blueLEDPin, blueValue/4);
  

  
}
