#ifndef ElegooCar_h
#define ElegooCar_h

#include <Arduino.h>

class ElegooCar
{
  public:
    ElegooCar();

    void stop(int duration);

    void forward(int speed, int duration);
    void reverse(int speed, int duration);

    void fwdLeft(int speed, int duration);
    void backLeft(int speed, int duration);
    void spinLeft(int speed, int duration);

    void fwdRight(int speed, int duration);
    void backRight(int speed, int duration);
    void spinRight(int speed, int duration);

  private:
    int rightFwd;
    int rightRev;
    int leftFwd;
    int leftRev;
    int rightPWM;
    int leftPWM;
    int slowest;
    int fastest;
    void rightWheelsForward(int speed);
    void rightWheelsReverse(int speed);
    void rightWheelsStop();
    void leftWheelsForward(int speed);
    void leftWheelsReverse(int speed);
    void leftWheelsStop();
};

#endif
