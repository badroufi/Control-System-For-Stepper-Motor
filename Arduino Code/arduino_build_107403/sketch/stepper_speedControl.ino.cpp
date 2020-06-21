#include <Arduino.h>
#line 1 "C:\\Users\\bader\\OneDrive\\Documents\\EE\\Summer Training\\Tasks\\Arduino Uno _ Stepper-Motor\\stepper_speedControl\\stepper_speedControl.ino"

/*
 Stepper Motor Control - speed control

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.

 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps,
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.

 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

int stepCount = 0;  // number of steps the motor has taken
int LED = 3;

#line 32 "C:\\Users\\bader\\OneDrive\\Documents\\EE\\Summer Training\\Tasks\\Arduino Uno _ Stepper-Motor\\stepper_speedControl\\stepper_speedControl.ino"
void setup();
#line 36 "C:\\Users\\bader\\OneDrive\\Documents\\EE\\Summer Training\\Tasks\\Arduino Uno _ Stepper-Motor\\stepper_speedControl\\stepper_speedControl.ino"
void loop();
#line 32 "C:\\Users\\bader\\OneDrive\\Documents\\EE\\Summer Training\\Tasks\\Arduino Uno _ Stepper-Motor\\stepper_speedControl\\stepper_speedControl.ino"
void setup() {
  pinMode(LED, OUTPUT);  // we will attach an Led to pin 3 and it will turn on if the Stepper  is moving 
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 10:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:

     digitalWrite(LED, HIGH);
     
    myStepper.step(stepsPerRevolution / 100);
  }
   else 
  
 digitalWrite(LED, LOW);

 delay(15); 
}

