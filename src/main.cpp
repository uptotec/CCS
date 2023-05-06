#include <Arduino.h>

#define LS 35      // left sensor
#define RS 34       // right sensor
#define LM1 32      //motor Driver in1
#define LM2 33     //motor Driver in2
#define RM1 25      //motor Driver in3
#define RM2 26      //motor Driver in4
#define ENA 14      //motor Driver ENA
#define ENB 27      //motor Driver ENB

#define MOTOR_SPEED 85
#define MOTOR_ROTATE_SPEED 95

void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop()
{
  bool left = digitalRead(LS);
  bool right = digitalRead(RS);

  if(!left && !right)
  {
    // FORWARD
    analogWrite(ENA, MOTOR_SPEED);
    analogWrite(ENB, MOTOR_SPEED);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
  if(left && !right)
  {
    // Left turn
    analogWrite(ENA, MOTOR_ROTATE_SPEED);
    analogWrite(ENB, MOTOR_ROTATE_SPEED);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }
  
  if(!left && right)
  {
    // turn right
    analogWrite(ENA, MOTOR_ROTATE_SPEED);
    analogWrite(ENB, MOTOR_ROTATE_SPEED);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }
  
  if(left && right)
  {
    //Stop
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}