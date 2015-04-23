

/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/


#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *myMotor2 = AFMS.getStepper(200, 2);
int joyPin = 2;

int joyVal = 0;

int motorSpeedForward = 0;

int motorSpeedBackward = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  myMotor->setSpeed(10);  // 10 rpm   
}

void loop() {
  uint8_t i;
  joyVal = analogRead(joyPin);
  Serial.println(joyVal);
  motorSpeedForward = map(joyVal, 515, 1023, 0, 10);
  motorSpeedBackward = map(joyVal, 515, 0, 0, 10);
  delay(10);
  if (joyVal > 515) {
  //  myMotor->setSpeed(motorSpeedForward);
    myMotor->step(motorSpeedForward, FORWARD, MICROSTEP);
    myMotor2->step(motorSpeedForward, FORWARD, MICROSTEP);
  }
  else if (joyVal < 515) {
   // myMotor->setSpeed(motorSpeedBackward );
    myMotor->step(motorSpeedBackward, BACKWARD, MICROSTEP);
    myMotor2->step(motorSpeedBackward, BACKWARD, MICROSTEP);
  }
    

}
