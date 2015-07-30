
// include the servo library either by typing the following line or Sketch --> Import Library
#include <Servo.h>

Servo myServo;  // create a servo object 

int const potPin = A3; // analog pin used to connect the potentiometer
int potVal;  // variable to read the value from the analog pin 
int angle;   // variable to hold the angle for the servo motor 

void setup() {
  myServo.attach(9); // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600); // open a serial connection to your computer
  Serial.println("Welcome to my Servo Sketch!");
}

void loop() {
  potVal = analogRead(potPin); // read the value of the potentiometer
  // print out the value to the serial monitor
  Serial.print("potVal: ");
  Serial.print(potVal);

  // scale the numbers from the pot 
  angle = map(potVal, 0, 1023, 0, 179); //map works like this: map(initialRange,lowerBoundofCurrentRange, upperBoundofCurrentRange, lowerBoundOfTargetRange, upperBoundOfTargetRange)

  // print out the angle for the servo motor 
  Serial.print(", angle: ");
  Serial.println(angle); 

  // set the servo position  
  myServo.write(angle);

  // wait for the servo to get there 
  delay(15);
}


