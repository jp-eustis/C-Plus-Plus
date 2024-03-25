int x = 0;
int code1;
int code2;
int code3;
int num = 1;


void setup() {
  // put your setup code here, to run once:
  //LIGHTS
  pinMode(5,OUTPUT);
   pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
     pinMode(8,OUTPUT);
  //SWITCHES
  pinMode(2,INPUT);
   pinMode(3,INPUT);
    pinMode(4,INPUT);

  
  Serial.begin(9600);

  randomSeed(analogRead(0));
  code1=random(2,5);
  code2=random(2,5);
  code3=random(2,5);

  Serial.println(code1);
  Serial.println(code2);
  Serial.println(code3);
  
 }

void loop() {
  
  // put your main code here, to run repeatedly

  if(num == 1){
    if(digitalRead(2)==HIGH){
      x=2;
    }     
    if(digitalRead(3)==HIGH){
      x=3;
    }   
    if(digitalRead(4)==HIGH){
      x=4;
    }    
    if(code1==x){ 
      digitalWrite(5,HIGH);
      num=1+num;
      }
    }
  
  if(num == 2){    
  x=0;
    if(digitalRead(2)==HIGH){
      x=2;
    }     
    if(digitalRead(3)==HIGH){
      x=3;
    }   
    if(digitalRead(4)==HIGH){
      x=4;
    }    
    if(code2==x){ 
      digitalWrite(6,HIGH);
     num=num+1;
      }
    }
  
  if(num == 3){
  x=0;    
    if(digitalRead(2)==HIGH){
      x=2;
    }     
    if(digitalRead(3)==HIGH){
      x=3;
    }   
    if(digitalRead(4)==HIGH){
      x=4;
    }    
    if(code3==x){ 
      digitalWrite(7,HIGH);
      num=1+num;
      }
    }

    if(num==4){
      delay(1000);
      digitalWrite(8,HIGH);
    }


}
