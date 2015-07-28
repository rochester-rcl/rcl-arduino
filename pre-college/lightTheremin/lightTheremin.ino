
// variable to hold sensor value
int sensorValue;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;
// LED pin
const int ledPin = 13;

void setup() {
  
  // Make the LED pin an output and turn it on
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(ledPin, HIGH);
  
  Serial.begin(9600);
  Serial.println("Light Theremin Project!");

  // calibrate for the first five seconds after program runs
  //Here we have a while loop, which will run while a condition is met (no variable, no check condition, no incrementation)
  while (millis() < 5000) { //Here we're going to calibrate for 5 seconds
    // record the maximum sensor value
    sensorValue = analogRead(A3);
    
    if (sensorValue > sensorHigh) {
      
      sensorHigh = sensorValue;
      
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin, LOW);
}

void loop() {
  //read the input from A0 and store it in a variable
  sensorValue = analogRead(A3);
  Serial.println(sensorValue);

  // map the sensor values to a wide range of pitches
  /*Here we're using the map function to map our values from our pin to a pitch value for our tone function. Map works like this: 
   map(lowerBoundofCurrentRange, upperBoundofCurrentRange, lowerBoundOfTargetRange, upperBoundOfTargetRange)
   */
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 1000); //so we map our sensor value to a new 'pitch' range from 50 - 1000


  // play the tone for 20 ms on pin 8
  tone(8, pitch, 20);

  // wait for 10ms 
  delay(10);
  
}//Program in some options to turn it off

