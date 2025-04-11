//voice control robot code
#include<Servo.h>
Servo s1,s2,s3;
String voice;

const int LeftMotorForward = A0;
const int LeftMotorBackward = A1;
const int RightMotorForward = A2;
const int RightMotorBackward = A3;


void moveForward(){
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);

     delay(1500);
 
     digitalWrite(LeftMotorForward, LOW);
    digitalWrite(RightMotorForward, LOW);
  
     digitalWrite(LeftMotorBackward, LOW);
     digitalWrite(RightMotorBackward, LOW);
  }


void moveBackward(){
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);

  delay(1500);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
 
  
}

void turnRight(){

    digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(800);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);

   digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  
}

void turnLeft(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(800);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
   digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);

}


void setup() {
  Serial.begin(9600);
s1.attach(4);
s2.attach(5);
s3.attach(6);
pinMode(13,OUTPUT);


  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

s1.write(130);
s2.write(90);
s3.write(50);

digitalWrite(13,HIGH);

delay(2000);


}

void loop() {
  while(Serial.available()) {
    delay(10);
    char c=Serial.read();
    if(c=='#')
    {break; }
    voice += c;
}

if (voice.length() > 0) {
  Serial.println(voice);
  if (voice == "*hands up")
  {
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
   
    
    s1.write(10);
    s3.write(170);
    
    
    }
  else if (voice == "*hands down")
  {

    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    
      s1.write(130);
      s3.write(50);
    }

 
  else if (voice == "*right hand up")
  {
     digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    
    s3.write(170);
    
   }
   else if (voice == "*right hand down")
  {

    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
     s3.write(50);
    
   }
   else if (voice == "*left hand up")
  {

    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    
    s1.write(10);
    
   }
   else if (voice == "*left hand down")
  {
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    
    s1.write(130);
    }

    else if (voice == "*rotate head")
  {
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    
    s2.write(180);
    delay(100);
    s2.write(0);
    delay(100);
    s2.write(180);
    delay(100);
    s2.write(0);
    delay(100);
    s2.write(90);
    delay(100);
    }

   else if (voice == "*go forward")
  {moveForward(); }

 else if (voice == "*go backward")
  {moveBackward() ; }

   else if (voice == "*turn right")
  {turnRight() ; }

   else if (voice == "*turn left")
  {turnLeft() ; }
 
 
voice="";
}

}
