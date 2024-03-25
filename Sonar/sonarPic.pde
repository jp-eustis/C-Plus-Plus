
import processing.serial.*;



Serial Adr;

String angle = "";
String distance = "";
String data = "";

float a, dist;

void setup(){

  size(1500,800);
  
  println(Serial.list());
  Adr = new Serial(this,Serial.list()[1],9600);
  //Adr.bufferUntil('\n');
  background(0);
  
}

void draw(){
     fill(0);              
      noStroke();
      rect(0,  0, width, height*0.93); 
      noStroke();
      fill(0);
      rect(0,height*0.93,width,height);                   
      drawRadar(); 
      drawObject();


  if (Adr.available() > 0) {
    data=Adr.readStringUntil('$');
    println("raw: " + data);
    try {
      
      String [] strings = data.split(",");
      int buffer=data.indexOf(',');
      a=Float.parseFloat(strings[0]);
      dist=Float.parseFloat(strings[1]);
      println(a + " , " + dist);  
    }
    catch(Exception e) {
      
    }
  }
}

void drawRadar(){
  pushMatrix();
  noFill();
  stroke(66,255,52);
  strokeWeight(1.05);
  
  translate(width/2,height-height*(.05));
  
  arc(0,0,(width*0.5),(width*0.5),PI,TWO_PI);
  arc(0,0,(width*0.25),(width*0.25),PI,TWO_PI);
  arc(0,0,(width*0.75),(width*0.75),PI,TWO_PI);
  arc(0,0,(width),(width),PI,TWO_PI);
  
  line(0,0,-width*cos(radians(30)),-width*sin(radians(30)));
  line(0,0,-width*cos(radians(60)),-width*sin(radians(60)));
  line(0,0,-width*cos(radians(90)),-width*sin(radians(90)));
  line(0,0,-width*cos(radians(120)),-width*sin(radians(120)));
  line(0,0,-width*cos(radians(150)),-width*sin(radians(150)));
  line(0,0,-width*cos(radians(0)),-width*sin(radians(0)));
  line(0,0,width*cos(radians(0)),width*sin(radians(0)));
  popMatrix();
  
}


void drawObject(){
  pushMatrix();
  
  float objDistance=(dist/100)*(-width/2);
  
  float x=objDistance*cos(radians(a))*(.25);
  float y=objDistance*sin(radians(a))*(.25);
  
  translate(width/2,height-height*(.05));
  
  if(dist<=1400){
    fill(255,140,0);
    textSize(35);
    text(dist/30.84,x,y);
  }
  popMatrix();
  
}
