/* Use a photoresistor (or photocell) to turn on an LED in the dark
   More info and circuit schematic: http://www.ardumotive.com/how-to-use-a-photoresistor-en.html
   Dev: Michalis Vasilakis // Date: 8/6/2015 // www.ardumotive.com */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Constants
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int pResistor1 = A1; // Photoresistor at Arduino analog pin A1
const int pResistor2 = A2; // Photoresistor at Arduino analog pin A2
const int pResistor3 = A3; // Photoresistor at Arduino analog pin A3
//Variables
int value;          // Store value from photoresistor (0-1023)
int value1;
int value2;          // Store value from photoresistor (0-1023)
int value3;

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display



void setup() {

  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
  pinMode(pResistor1, INPUT);// Set pResistor - A1 pin as an input (optional)
  pinMode(pResistor2, INPUT);// Set pResistor - A0 pin as an input (optional)
  pinMode(pResistor3, INPUT);// Set pResistor - A1 pin as an input (optional)
  Serial.begin(9600);
  lcd.init(); // initialize the lcd
  lcd.backlight();
}


void loop() {
  lcd.clear();
  value = analogRead(pResistor);
  value1 = analogRead(pResistor1);
  value2 = analogRead(pResistor2);
  value3 = analogRead(pResistor3);
  Serial.print(value);
  Serial.println(value1);
  Serial.print(value2);
  Serial.println(value3);
  //You can change value "400"
  if (value < 400) {
 
    lcd.setCursor(0, 0);         // move cursor to   (0, 0)
    lcd.print("winner is ");        // print message at (0, 0)
    lcd.setCursor(2, 1);         // move cursor to   (2, 1)
    lcd.print("in line one"); // print message at (2, 1)
  }
  //You can change value1 "400"
  if (value1 < 400) {
    
    lcd.setCursor(0, 0);         // move cursor to   (0, 0)
    lcd.print("winner is ");        // print message at (0, 0)
    lcd.setCursor(2, 1);         // move cursor to   (2, 1)
    lcd.print("in line two"); // print message at (2, 1)
  }
  if (value2 < 400) {
    
    lcd.setCursor(0, 0);         // move cursor to   (0, 0)
    lcd.print("winner is ");        // print message at (0, 0)
    lcd.setCursor(2, 1);         // move cursor to   (2, 1)
    lcd.print("in line three"); // print message at (2, 1)
  }
  if (value3 < 400) {
    
    lcd.setCursor(0, 0);         // move cursor to   (0, 0)
    lcd.print("winner is ");        // print message at (0, 0)
    lcd.setCursor(2, 1);         // move cursor to   (2, 1)
    lcd.print("in line four"); // print message at (2, 1)
  }
  delay(500); //Small delay

}
