

// named constant for the pin the sensor is connected to. A constant means that the program cannot change this value.
const int sensorPin = A4; // Can set this to any analog pin

// room temperature in Celcius
const float baselineTemp = 25.0; 

void setup(){
  // open a serial connection to display values
  
  Serial.begin(9600);
  
  // set the LED pins as outputs
  
  /* Here we can use a for() loop to set up our pins. This could also be written like this:
  
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  
  pinMode(4, OUTPUT);
  digitalWrite(3, LOW);
  
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  
 */
  for(int pinNumber = 3; pinNumber<6; pinNumber++){//set pin mode and digital write when pinNumber = 3 and pinNumber is < 6
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }//End our loop 
}

void loop() {//Here is our main loop again 
  // read the value on AnalogIn pin 4
  // and store it in a variable
  int sensorVal = analogRead(sensorPin);

  // send the 10-bit sensor value out the serial port
  Serial.print("sensor Value: ");
  Serial.print(sensorVal); 

  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0; // Here the ADC maps an 'infinite' analog signal to an int between 0 - 1023. Based on the voltage of our circuit (5V) we can figure it out.

  // Send the voltage level out the Serial port
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // convert the voltage to temperature in degrees C
  // the sensor changes 10 mV per degree C
  // the datasheet says there's a 500 mV offset arduino.cc/kitdatasheets
  // ((volatge - 500mV) times 100) For example ((3V - .5V) x 100) = 250 degrees C 
  Serial.print(", degrees C: "); 
  
  float temperature = (voltage - .5) * 100;
  
  Serial.println(temperature);

  // if the current temperature is lower than the baseline
  // turn off all LEDs
  if(temperature < baselineTemp){
    
    digitalWrite(3, LOW);
    
    digitalWrite(4, LOW);
    
    digitalWrite(5, LOW);
    
  } // if the temperature rises 2-4 degrees, turn an LED on
  
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    
    digitalWrite(3, HIGH);
    
    digitalWrite(4, LOW);
    
    digitalWrite(5, LOW);
    
  } // if the temperature rises 4-6 degrees, turn a second LED on  
  else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    
    digitalWrite(3, HIGH);
    
    digitalWrite(4, HIGH);
    
    digitalWrite(5, LOW);
  } // if the temperature rises more than 6 degrees, turn all LEDs on
  else if(temperature >= baselineTemp+6){
    
    digitalWrite(3, HIGH);
    
    digitalWrite(4, HIGH);
    
    digitalWrite(5, HIGH);
  }
  delay(1); // We wait for 1 second before looping again 
}//Close our loop 
