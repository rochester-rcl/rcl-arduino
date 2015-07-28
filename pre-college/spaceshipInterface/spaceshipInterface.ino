//Commented code for our first Arduino Sketch

int switchState = 0; //Setting up a variable (integer) to represent our switch state 
/*We don't necessarily need to assign it a value now, it can also be written as:
int switchState;
*/
void setup() { // Our setup function that will run once, when the program starts. Required by every Arduino sketch

Serial.begin(9600); //Setting up our Serial connection object for debugging

Serial.println("Hello World");// We'll test it by printing to the serial monitor 

//Declare all of our output pins here. Each pin will provide the e.m.f. for our LED circuits
pinMode(3,OUTPUT);

pinMode(4,OUTPUT);

pinMode(5,OUTPUT);

// declare the switch pin as an input here 
pinMode(2,INPUT);
}

void loop() {// Our main (infinite) loop, which is also required, like our setup function

// read the value of the switch
// digitalRead() checks to see if there is voltage
// on the pin or not 
switchState = digitalRead(2);

/*
Our first conditional statement
if the button is not pressed
blink the red LEDs
*/
if (switchState == LOW) {
  
Serial.println("Low");// We're going to print LOW for debugging purposes
  
digitalWrite(3, HIGH); // turn the green LED on pin 3 on

digitalWrite(4, LOW); // turn the red LED on pin 4 off

digitalWrite(5, LOW); // turn the red LED on pin 5 off

}//End of the 'if' portion of our conditional 

// this else is part of the above if() statement. 
// if the switch is not LOW (the button is pressed)
// the code below will run 
else {
  
Serial.println("High"); // Again, for debugging 

digitalWrite(3, LOW); // turn the green LED on pin 3 off

digitalWrite(4, LOW); // turn the red LED on pin 4 off

digitalWrite(5, HIGH); // turn the red LED on pin 5 on

// wait for a quarter second before changing the light
delay(250);

digitalWrite(4, HIGH); // turn the red LED on pin 4 on

digitalWrite(5, LOW); // turn the red LED on pin 5 off

// wait for a quarter second before changing the light
delay(250);
} //End of 'else' conditional 

}//Close our main loop 
