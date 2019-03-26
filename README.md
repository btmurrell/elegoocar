# An `ElegooCar` class to control the Elegoo robot car in an elegant way

To support the [robo car](https://www.amazon.com/gp/product/B01M2Z9ZTV/ref=oh_aui_detailpage_o06_s01?ie=UTF8&psc=1), this class makes it easier to tell the car what you want it to do.  It elminates the need to specify pins and all the complicated stuff of the Arduino hardware interface (that's all encapsulated in the ElegooCar class).

## Props for PlatformIO

If you are not using the [PlatformIO IDE](https://platformio.org/platformio-ide) for VS Code, you really should be. The ecosystem and convention-base approach they have developed for building and uploading code to devices is really smooth.  This library follows their directory structure convention.  

Take a short while to [familiarize yourself](https://docs.platformio.org/en/latest/ide/pioide.html) with this editor. You will be way more productive and happy using it over the Arduino editor (which they shamefully call an IDE).  PlatformIO IDE is practically zero configuration to get it up and running.

Also, you will notice that the [examples/demo.cpp](./examples/demo.cpp) has a `.cpp` (C++ language) extension, not a `.ino` (Arduino) extension.  This is to make IntelliSense in VS Code work for you.  See [explanation here](https://docs.platformio.org/en/latest/faq.html#convert-arduino-file-to-c-manually).  All `.ino` files are compiled to C++ under the hood anyway.

## Example

A demo of some of the features of this `ElegooCar` library exists in [examples/demo.cpp](./examples/demo.cpp).  To try out this demo, you need to copy it to your `./src` directory.  The PlatformIO build/upload system will only recognize files under your `/.src` directory.

## ElegooCar API

To use the API, be sure you include the header and an instance at the top. Do _not_ put it in your setup() method. Put it at the top of your `.cpp` file:

```c++
#include <elegoo_car.h>
ElegooCar car;
```

After that, you can use the `car` instance in your code, according to the API below.
In the APIs below, the int `speed` parameter is the speed you want the car (or wheels) to move in.  This speed number is a relative number (not a miles per hour!).  The range of valid values is 70 to 255.  Below 70 does not pull enough juice from the batteries to power the motors.  The int `duration` optional parameter is the amount of time in miliseconds that you want the car to make that movement.

### `car.forward(int speed [, int duration])`

The `forward` method will move the car forward at the given speed, for the given duration in miliseconds. You may omit the duration parameter, which will cause the care to continue this motion until another command is given.

### `car.reverse(int speed [, int duration])`

The `reverse` method will move the car in reverse at the given speed, for the given duration in miliseconds. You may omit the duration parameter, which will cause the care to continue this motion until another command is given.

### `car.stop(int duration)`

The `stop` method will make all the wheels on the car stop for the specified duration in miliseconds. You may omit the duration parameter, which will cause the care to continue this motion until another command is given.

### `car.fwdRight(int speed [, int duration])`

The `fwdRight` method will move the car in a forward, right direction, at the given speed for the given duration in milliseconds. You may omit the duration parameter, which will cause the care to continue this motion until another command is given. 

### `car.fwdLeft(int speed [, int duration])`

The `fwdLeft` method will move the car in a forward, left direction, at the given speed for the given duration in milliseconds. You may omit the duration parameter, which will cause the care to continue this motion until another command is given. 

### `car.backRight(int speed [, int duration])`

The `backRight` method will move the car in a backward, right direction, at the given speed for the given duration in milliseconds. You may omit the duration parameter, which will cause the care to continue this motion until another command is given. 

### `car.backLeft(int speed [, int duration])`

The `backLeft` method will move the car in a backward, left direction, at the given speed for the given duration in milliseconds. You may omit the duration parameter, which will cause the care to continue this motion until another command is given. 

