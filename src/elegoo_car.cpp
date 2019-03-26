#include "elegoo_car.h"

ElegooCar::ElegooCar()
{
  rightFwd=6;  // in1
  rightRev=7;  // in2
  leftFwd=9;   // in4
  leftRev=8;   // in3
  /*define channel enable output pins*/
  rightPWM=5;  // ENA
  leftPWM=11;  // ENB

  slowest=70;
  fastest=255;

  //Open the serial port and set the baud rate to 9600
  Serial.begin(9600);

  pinMode(rightFwd,OUTPUT);
  pinMode(rightRev,OUTPUT);
  pinMode(leftFwd,OUTPUT);
  pinMode(leftRev,OUTPUT);
  pinMode(rightPWM,OUTPUT);
  pinMode(leftPWM,OUTPUT);
}

void ElegooCar::rightWheelsForward(int speed)
{
  analogWrite(rightPWM, speed);
  digitalWrite(rightFwd,HIGH);
  digitalWrite(rightRev,LOW);
}
void ElegooCar::rightWheelsStop()
{
  analogWrite(rightPWM,0);
  digitalWrite(rightFwd,LOW);
  digitalWrite(rightRev,LOW);
}
void ElegooCar::rightWheelsReverse(int speed)
{
  analogWrite(rightPWM, speed);
  digitalWrite(rightFwd,LOW);
  digitalWrite(rightRev,HIGH);
}
// -------------------------------
void ElegooCar::leftWheelsForward(int speed)
{
  analogWrite(leftPWM, speed);
  digitalWrite(leftFwd,HIGH);
  digitalWrite(leftRev,LOW);
}
void ElegooCar::leftWheelsStop()
{
  analogWrite(leftPWM,0);
  digitalWrite(leftFwd,LOW);
  digitalWrite(leftRev,LOW);
}
void ElegooCar::leftWheelsReverse(int speed)
{
  analogWrite(leftPWM, speed);
  digitalWrite(leftFwd,LOW);
  digitalWrite(leftRev,HIGH);
}

// ----------------------------------
void ElegooCar::stop(int duration = 0)
{
  leftWheelsStop();
  rightWheelsStop();
  if (duration > 0) {
    delay(duration);
  }
}
void ElegooCar::forward(int speed, int duration = 0)
{
  leftWheelsForward(speed);
  rightWheelsForward(speed);
  if (duration > 0) {
    delay(duration);
  }
}
void ElegooCar::reverse(int speed, int duration = 0)
{
  leftWheelsReverse(speed);
  rightWheelsReverse(speed);
  if (duration > 0) {
    delay(duration);
  }
}

void ElegooCar::fwdRight(int speed, int duration = 0)
{
  rightWheelsStop();
  leftWheelsForward(speed);
  if (duration > 0) {
    delay(duration);
  }
}

void ElegooCar::backRight(int speed, int duration = 0)
{
  rightWheelsStop();
  leftWheelsReverse(speed);
  if (duration > 0) {
    delay(duration);
  }
}

void ElegooCar::spinRight(int speed, int duration = 0)
{
  rightWheelsReverse(speed);
  leftWheelsForward(speed);
  if (duration > 0) {
    delay(duration);
  }
}

void ElegooCar::fwdLeft(int speed, int duration = 0)
{
  leftWheelsStop();
  rightWheelsForward(speed);
  if (duration > 0) {
    delay(duration);
  }
}

void ElegooCar::backLeft(int speed, int duration = 0)
{
  leftWheelsStop();
  rightWheelsReverse(speed);
  if (duration > 0) {
    delay(duration);
  }
}

void ElegooCar::spinLeft(int speed, int duration = 0)
{
  leftWheelsReverse(speed);
  rightWheelsForward(speed);
  if (duration > 0) {
    delay(duration);
  }
}
