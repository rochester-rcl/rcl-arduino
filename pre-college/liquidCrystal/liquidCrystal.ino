#include <LiquidCrystal.h> // Include the LiquidCrystal library

LiquidCrystal lcd(12,11,5,4,3,2); //Set up all of our interface pins for the LCD 
//Read/Write, Register Select, Data 

//Smiley face characters as binary: 
byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void printSmiley() { //Example of function declaration in Arduino
  lcd.createChar(0, smiley); // creating a character to be accessed by its number, in this case, 0. Followed by the data (the smiley)
}

void setup() {
 lcd.begin(16,2); // Set up 16x2 LCD 
 Serial.begin(9600);//And our serial 
 Serial.print("Test Printing to the Screen");
 lcd.print("LCD Sketch");
 printSmiley();//creating our Smiley character by calling out printSmiley() function
 lcd.write(byte(0));// Writing it to the screen by its number.  
 
}

void loop() { 
  //Empty - smiley shows forever because we're not wiping the screen
  
}

//Can try a thumbs-up V 
/*void thumbsup() {
 byte thumb1[8] = {B00100,B00011,B00100,B00011,B00100,B00011,B00010,B00001};
 byte thumb2[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00011};
 byte thumb3[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00001,B11110};
 byte thumb4[8] = {B00000,B01100,B10010,B10010,B10001,B01000,B11110,B00000};
 byte thumb5[8] = {B00010,B00010,B00010,B00010,B00010,B01110,B10000,B00000};
 byte thumb6[8] = {B00000,B00000,B00000,B00000,B00000,B10000,B01000,B00110};
 lcd.createChar(0, thumb1);
 lcd.createChar(1, thumb2);
 lcd.createChar(2, thumb3);
 lcd.createChar(3, thumb4);
 lcd.createChar(4, thumb5);
 lcd.createChar(5, thumb6);
 lcd.setCursor(4,1);
 lcd.write(0);
 lcd.setCursor(4,0);
 lcd.write(1);
 lcd.setCursor(5,1);
 lcd.write(2);
 lcd.setCursor(5,0);
 lcd.write(3);
 lcd.setCursor(6,1);
 lcd.write(4);
 lcd.setCursor(6,0);
 lcd.write(5);
}*/
