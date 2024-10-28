/*
* Roulette main.cpp
* Author: Saebastion Cole
* Date: 10/20/2024
* This program is meant to run on a Arduino Nano.
* It uses an IC2 display and momentary pushbuttons. to control the game.
*
*/
//Imports
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include  <Wire.h>

//Prototypes
void clearTopRow();
void clearBottomRow();
void setTopText(const char*);
void setBottomText(const char*);


//initialize the liquid crystal library
LiquidCrystal_I2C lcd(0x27,  16, 2);
const int buttonPin = 2;
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  
  //initialize lcd screen
  lcd.init();
  // turn on the backlight
  lcd.backlight();
  pinMode(buttonPin, INPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    setTopText("PRESSED        ");
  }
  else {
    
  }
  //wait  for a second
  delay(1000);
  // tell the screen to write on the top row
  setTopText("Hello!         ");
  // tell the screen to write on the bottom  row
  lcd.setCursor(0,1);
  // tell the screen to write “Arduino_uno_guy”  on the bottom row
  // you can change whats in the quotes to be what you want  it to be!
  setBottomText("Arduino_uno_guy");
  delay(1000);
  clearTopRow();
  clearBottomRow();
  
}

//Clears top row of the lcd
void clearTopRow() {
  lcd.setCursor(0,0);
  // tell the screen to write “hello, from” on the top  row
  lcd.print("                ");
}

//Clears bottom row of the lcd
void clearBottomRow() {
  lcd.setCursor(0,1);
  // tell the screen to write “hello, from” on the top  row
  lcd.print("                ");
}

/*  Passed string shows up on the top row of lcd
*   const char* -- this is the pointer to the passed char[]
*/
void setTopText(const char* printArr) {
  lcd.setCursor(0,0);
  // tell the screen to write “hello, from” on the top  row
  lcd.print(printArr);
}

/*  Passed string shows up on the bottom row of lcd
*   const char* -- this is the pointer to the passed char[]
*/
void setBottomText(const char* printArr) {
  lcd.setCursor(0,1);
  // tell the screen to write “hello, from” on the top  row
  lcd.print(printArr);
}