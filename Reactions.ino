const int switchPin = 8;

int playerScore=0;

unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;
int scoreReader = 0;

int led = 2;

long interval = 100;


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for(int x=2;x<8;x++){
    pinMode(x,OUTPUT);
  }

pinMode(switchPin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 unsigned long currentTime = millis();

 if(currentTime - previousTime > interval){
  previousTime = currentTime;

  digitalWrite(led,HIGH);
  led++;
  if(led==8){
    
  }
 }

switchState = digitalRead(switchPin);

if(switchState != prevSwitchState){
  for(int x = 2; x<8;x++){
    digitalWrite(x,LOW);
    score();

  }
  led=2;
  previousTime=currentTime;
}
prevSwitchState = switchState;

}

void score(){
scoreReader=digitalRead(switchPin);


  if(led==3 && scoreReader==0){
    playerScore=2;
  }

  if(led==4 && scoreReader==0){
   playerScore=25;
 }
  if(led==5 && scoreReader==0){
    playerScore=50;
  }
  if(led==6 && scoreReader==0){
    playerScore=75;
  }
  if(led==7 && scoreReader==0){
    playerScore=100;
  }
  if(led==8){
    playerScore=0;
  }
    Serial.println(playerScore);
      
  }
   
