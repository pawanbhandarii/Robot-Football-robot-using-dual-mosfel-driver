#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // Using Pin 2 and  3 as tx for arduino nano
char bt='S';
const int IN1=6;
const int IN2=7;
const int ENA=10;

const int IN3=8;
const int IN4=9;
const int ENB=11;

void setup() {
    Serial.begin(9600);
    BTserial.begin(9600);
    
     pinMode(IN1, OUTPUT); //INT1 AND INT2  are used for left motor
     pinMode(IN2, OUTPUT); //INT2 and INT 3 are used for right motor
     pinMode(ENA, OUTPUT); 

     pinMode(IN4, OUTPUT);
     pinMode(IN3, OUTPUT);
     pinMode(ENB, OUTPUT);
}
void loop() {
  
  bt=BTserial.read();
  //BACKWARD 
  if(bt=='B'){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  }
  //FORWARD
  if(bt=='F'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  }
  //LEFT
  if(bt=='L'){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  }
  //RIGHT
  if(bt=='R'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  }
  //BACKWARD LEFT
  if(bt=='H'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  }
  //FORWARD LEFT
  if(bt=='G'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  }
  //BACKWARD RIGHT
   if(bt=='J'){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  }
  //FORWARD RIGHT
   if(bt=='I'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  }
  
  if(bt=='S'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
   digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  
  }
}
