#include <elegoo_car.h>
ElegooCar car;


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  int speed = 120;

  car.forward(speed, 1000);
  car.stop(1000);

  car.fwdLeft(speed, 1000);
  car.stop(1000);

  car.reverse(speed, 1000);
  car.stop(1000);

  car.backRight(speed, 1000);
  car.stop(1000);
}

