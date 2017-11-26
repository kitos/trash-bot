#include "TrashBot.h"

#define DefaultSpeed 255

char TrashBot::LSpeed = DefaultSpeed;
char TrashBot::RSpeed = DefaultSpeed;

//  Default Arduino Car pin define
TrashBot::TrashBot()
{  
  LMotorSpeedPin = 5;             //Left Motor Speed pin (ENA)
  LMotorForward = A0;             //Motor-L forward (IN1).
  LMotorBackward = A1;            //Motor-L backward (IN2)
  
  RMotorSpeedPin = 6;             //Right Motor Speed pin (ENB)
  RMotorForward = A3;             //Motor-R forward (IN4)
  RMotorBackward = A2;            //Motor-R backward (IN3)
  
  pinMode(LMotorSpeedPin,OUTPUT);                     
  pinMode(LMotorForward,OUTPUT);      
  pinMode(LMotorBackward,OUTPUT);
  
  pinMode(RMotorSpeedPin,OUTPUT);       
  pinMode(RMotorForward,OUTPUT);     
  pinMode(RMotorBackward,OUTPUT);  

}

//TrashBot::TrashBot(int LSpeedPin = 5,int L1 = A0,int L2 = A1 ,int RSpeedPin = 6,int R1 = A3,int R2 = A2)
TrashBot::TrashBot(int LSpeedPin,int L1,int L2,int RSpeedPin,int R1,int R2)
{
  this->LMotorSpeedPin = LSpeedPin;             
  this->LMotorForward = L1;            
  this->LMotorBackward = L2;
  
  this->RMotorSpeedPin = RSpeedPin;       
  this->RMotorForward = R1;           
  this->RMotorBackward = R2;       
  
  pinMode(LMotorSpeedPin,OUTPUT);                     
  pinMode(LMotorForward,OUTPUT);      
  pinMode(LMotorBackward,OUTPUT);
  
  pinMode(RMotorSpeedPin,OUTPUT);       
  pinMode(RMotorForward,OUTPUT);     
  pinMode(RMotorBackward,OUTPUT); 
}


//drive the left motor run forward
void TrashBot::LeftMotorForward(char inLSpeed = LSpeed)
{
  analogWrite(LMotorSpeedPin,inLSpeed);                
  digitalWrite(LMotorForward,HIGH);  					
  digitalWrite(LMotorBackward,LOW); 
}

//drive the left motor run backward
void TrashBot::LeftMotorBackward(char inLSpeed = LSpeed)
{
  analogWrite(LMotorSpeedPin,inLSpeed);                
  digitalWrite(LMotorForward,LOW);  					
  digitalWrite(LMotorBackward,HIGH); 
}

//drive the left motor stop
void TrashBot::LeftMotorStop()
{
  digitalWrite(LMotorSpeedPin,LOW);               
}

//drive the right motor run forward
void TrashBot::RightMotorForward(char inRSpeed = RSpeed)
{
  analogWrite(RMotorSpeedPin,inRSpeed);               
  digitalWrite(RMotorForward,HIGH);   				  
  digitalWrite(RMotorBackward,LOW);
}

//drive the right motor run backward
void TrashBot::RightMotorBackward(char inRSpeed = RSpeed)
{
  analogWrite(RMotorSpeedPin,inRSpeed);               
  digitalWrite(RMotorForward,LOW);   				   
  digitalWrite(RMotorBackward,HIGH);
}

bool TrashBot::MotorRun(int LS,int RS)
{ 
  if(LS >= 0 && LS <= 255)
  {
    LeftMotorForward(LS);
  }
  if(LS < 0 && LS >= -255)
  {
    LeftMotorBackward(abs(LS));
  }
  
  if(RS >= 0 && RS <= 255)
  {
    RightMotorForward(RS);
  }
  if(RS < 0 && RS >= -255)
  {
    RightMotorBackward(abs(RS));
  }
  if (RS > 255 || RS < -255 || LS > 255 || LS < -255)
  {
    return false;
  }
  
  return true;
}

//drive the right motor stop
void TrashBot::RightMotorStop()
{
  digitalWrite(RMotorSpeedPin,LOW);             
}

//drive the car run forward
void TrashBot::Forward()
{
  LeftMotorForward();
  RightMotorForward();
}

//drive the car run forward
void TrashBot::Forward(unsigned int DelayMS)
{
  Forward();  
  delay(DelayMS);
  Brake();
}

//drive the car run backward
void TrashBot::Backward()
{
  LeftMotorBackward();
  RightMotorBackward();
}

void TrashBot::Backward(unsigned int DelayMS)
{
  Backward();  
  delay(DelayMS);
  Brake();
}

//drive the car turn left
void TrashBot::Left()
{
  LeftMotorStop();
  RightMotorForward();
}

void TrashBot::Left(unsigned int DelayMS)
{
  Left();  
  delay(DelayMS);
  Brake();
}

//drive the car turn right
void TrashBot::Right()
{
  RightMotorStop();
  LeftMotorForward();
}

void TrashBot::Right(unsigned int DelayMS)
{
  Right();  
  delay(DelayMS);
  Brake();
}

//drive the car left circle
void TrashBot::LeftCircle()
{
  LeftMotorBackward();
  RightMotorForward();
}

void TrashBot::LeftCircle(unsigned int DelayMS)
{
  LeftCircle();  
  delay(DelayMS);
  Brake();
}

//drive the car Right circle
void TrashBot::RightCircle()
{
  LeftMotorForward();
  RightMotorBackward();
}

void TrashBot::RightCircle(unsigned int DelayMS)
{
  RightCircle();  
  delay(DelayMS);
  Brake();
}

//drive the car brake
void TrashBot::Brake()
{
   LeftMotorStop();
   RightMotorStop();
}

//reset the speed of the car
void TrashBot::SetSpeed(char LSpeed,char RSpeed)
{
  this->LSpeed = LSpeed;
  this->RSpeed = RSpeed;
  analogWrite(RMotorSpeedPin,RSpeed);  
  analogWrite(LMotorSpeedPin,LSpeed);   
}

//reset the speed of the car
void TrashBot::SetSpeed(char Speed)
{
  this->LSpeed = Speed;
  this->RSpeed = Speed;
  analogWrite(RMotorSpeedPin,RSpeed);  
  analogWrite(LMotorSpeedPin,LSpeed); 
}

void TrashBot::SetRSpeed(char Speed)
{
  this->RSpeed = Speed;
  analogWrite(RMotorSpeedPin,RSpeed);                
}

void TrashBot::SetLSpeed(char Speed)
{
  this->LSpeed = Speed;
  analogWrite(LMotorSpeedPin,LSpeed);                  
}

void TrashBot::DecSpeed()
{
  if (this->LSpeed > 10) {
    SetSpeed(this->LSpeed - 10);
  }                 
}

void TrashBot::IncSpeed()
{
  if (this->LSpeed < 245) {
    SetSpeed(this->LSpeed + 10);
  }                 
}