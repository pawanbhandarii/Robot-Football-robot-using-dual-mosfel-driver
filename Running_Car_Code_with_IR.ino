#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // Using Pin 2 and  3 as tx for arduino nano
char bt='S';
const int IN1=6;
const int IN2=7;


const int IN3=8;
const int IN4=9;

const int ENA=10;
const int ENB=11;
const int IN5=4;
#define irl A2
#define irm A1
#define irr A0

int fast=100;
void setup() {
    Serial.begin(9600);
    BTserial.begin(9600);
    
    
     pinMode(IN1, OUTPUT);
     pinMode(IN2, OUTPUT);
     pinMode(ENA, OUTPUT);
     pinMode(IN4, OUTPUT);
     pinMode(IN3, OUTPUT);
     pinMode(ENB, OUTPUT);
     pinMode(IN5, OUTPUT);
     pinMode(irl, INPUT);
     pinMode(irm, INPUT);
     pinMode(irr, INPUT);
}
void loop() {
  
  int s1 = digitalRead(irl);  //Left Most Sensor
  int s2 = digitalRead(irm);  //Midlle Sensor
  int s3 = digitalRead(irr);  //Right Most Sensor
  //if only middle sensor is sensing
  if((s1 == 0) && (s2 == 1) && (s3 == 0))
{
  Serial.print("Forward Movement\n");
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
}
//if only left sensor is sensing black
else if((s1 == 1) && (s2 == 0) && (s3 == 0))
{
  Serial.print("left Movement\n");
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast); 
}
//if both left and middle  sensor is sensing black
else if((s1 == 1) && (s2 == 1) && (s3 == 0))
{
  Serial.print("left Movement\n");
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
 
}
//if only right sensor is sensing black
else if((s1 == 0) && (s2 == 0) && (s3 == 1))
{
  Serial.print("right Movement\n");
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
}
//if both  right and middle sensor is sensing black
if((s1 == 0) && (s2 == 0) && (s3 == 1))
{
  Serial.print("right Movement\n");
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
 
}
//if all sensor is sensing black
if((s1 == 1) && (s2 == 1) && (s3 == 1))
{
  Serial.print("left Movement\n");
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
}
//if all sensor is sensing white
else if((s1 == 1) && (s2 == 1) && (s3 == 1))
{
  Serial.print("left Movement\n");
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
}

  
  bt=BTserial.read();
  //BACKWAED 
  if(bt=='0')
    fast=5;
  if(bt=='1')
    fast=25;
   if(bt=='2')
    fast=50;
   if(bt=='3')
    fast=75;
   if(bt=='4')
    fast=100;
   if(bt=='5')
    fast=125;
   if(bt=='6')
    fast=150;
   if(bt=='7')
    fast=175;
   if(bt=='8')
    fast=200;
   if(bt=='9')
    fast=230;
   if(bt=='q')
    fast=255;
    
  
  //FORWARD
  if(bt=='F'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
  }
   //Back
  if(bt=='B'){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
  }
  //LEFT
  if(bt=='L'){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
  }
  //RIGHT
  if(bt=='R'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
  }
  //BACKWARD LEFT
  if(bt=='H'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
  }
  //FORWARD LEFT
  if(bt=='G'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
  }
  //BACKWARD RIGHT
   if(bt=='J'){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
  }
  //FORWARD RIGHT
   if(bt=='I'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
  }
  
  if(bt=='S'){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  
  }
  //SHOOTER
   if(bt=='V'){
  digitalWrite(IN5,HIGH); 
  delay(5000);
  digitalWrite(IN5,LOW); 
  }
}
