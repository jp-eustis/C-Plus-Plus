#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
 
  const int highPin = 6;
  int highState = 0;
  int prevHighState = 0;
  
  const int lowPin = 10;
  int lowState = 0;
  int prevLowState = 0;

  int num;
  int secondNum;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(highPin,INPUT);
  pinMode(lowPin,INPUT);

  lcd.print("Higher Or Lower:");
  randomSeed(analogRead(8));
  num = random(0,100);
  secondNum = random(0,100);
  
lcd.setCursor(0, 1);
lcd.print(num);  
  
  Serial.println(num);
  Serial.println(secondNum);
}

void loop() {
  // put your main code here, to run repeatedly:
  highState = digitalRead(highPin);
  lowState = digitalRead(lowPin);

  
    if(highState == 1){
      if(num<=secondNum){
        lcd.setCursor(0, 0);
        lcd.print("Correct!");
        delay(200);
      }
      if(num>secondNum){
        lcd.setCursor(0,0);
        lcd.print("Wrong! fuck u");
        
      }
    
   }

   else if(lowState == 1){
        if(num>=secondNum){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Correct!");
        
      }
      if(num<secondNum){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Wrong!");
        
      }
   }
  
  prevHighState = highState;
  prevLowState = lowState;
}
