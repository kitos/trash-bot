#include <Servo.h>
#include <Ultrasonic.h>

#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include "TrashBot.h"

constexpr long IR_1 = 16724175;
constexpr long IR_2 = 16718055;
constexpr long IR_3 = 16743045;
constexpr long IR_4 = 16716015;
constexpr long IR_5 = 16726215;
constexpr long IR_6 = 16734885;
constexpr long IR_7 = 16728765;
constexpr long IR_8 = 16730805;
constexpr long IR_9 = 16732845;
constexpr long IR_PLUS = 16754775;
constexpr long IR_MINUS = 16769055;

Ultrasonic ultrasonic(9, 10);
IRrecv irrecv(4);
Servo servo;

TrashBot car = TrashBot();
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  servo.attach(10);
  car.SetSpeed(150);
}

void move(long ir)
{
  switch (ir)
  {
  case IR_1:
    Serial.println("Left");
    car.Left(150);
    car.Forward();
    break;
  case IR_2:
    Serial.println("Forward");
    car.Forward();
    break;
  case IR_3:
    Serial.println("Right");
    car.Right(150);
    car.Forward();
    break;
  case IR_4:
    Serial.println("LeftCircle");
    car.LeftCircle();
    break;
  case IR_5:
    Serial.println("Brake");
    car.Brake();
    break;
  case IR_6:
    Serial.println("RightCircle");
    car.RightCircle();
    break;
  case IR_8:
    Serial.println("Backward");
    car.Backward();
    break;
  case IR_PLUS:
    Serial.println("IncSpeed");
    car.IncSpeed();
    break;
  case IR_MINUS:
    Serial.println("DecSpeed");
    car.DecSpeed();
    break;
  }
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value);
    move(results.value);
    irrecv.resume();
  }

  delay(10);

  //  servo.write(0);
  //  delay(500);

  //  servo.write(45);
  //  delay(500);

  //  servo.write(90);
  //  delay(500);

  //  servo.write(135);
  //  delay(500);

  //  servo.write(180);
  //  delay(500);

  //  servo.write(135);
  //  delay(500);

  //  servo.write(90);
  //  delay(500);

  //  servo.write(45 );
  //  delay(500);
}