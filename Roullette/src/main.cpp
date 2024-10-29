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
#include <lcdUtils.h>
#include <Wire.h>
#include <GameMode.h>

//Prototypes
void clearTopRow();
void clearBottomRow();
void setTopText(const char*);
void setBottomText(const char*);
void setColor(int, int, int);

const char* currentGameModeText(GameMode);
void incrementGameMode(GameMode &gameMode);

//initialize the liquid crystal library
const int navButtonPin = 2;
const int selectButtonPin = 3;

const int relayPowerPin = 4;
const int relaySwitchPin = 5;

//Init buttons
int buttonState = 0;  // variable for reading the pushbutton status
int redPin= 6;
int greenPin = 7;
int bluePin = 8;

bool isPlaying = 0;
GameMode gameMode = GameMode::CLASSIC6;

void setup() {
  
  //initialize lcd screen
  lcd.init();
  // turn on the backlight
  lcd.backlight();
  //Setup Pins
  pinMode(navButtonPin, INPUT);
  pinMode(redPin,  OUTPUT);              
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  //Set Top Game Text
  setTopText("TASER ROULLETTE ");
  delay(1000);
  //Sleep 1000ms before starting game
  clearTopRow();
}

void loop() {

  //Begining of the loop -- Here we need to begin menu logic.
  setTopText("  SELECT MODE   ");
  clearBottomRow();
  setBottomText(currentGameModeText(gameMode));

  buttonState = digitalRead(navButtonPin);
  if (buttonState == HIGH) {
    incrementGameMode(gameMode);
    clearBottomRow();
    setBottomText(currentGameModeText(gameMode));
    setColor(255, 0, 0); // Red Color
  }
  else {
    
  }

  //wait  for a second
  delay(1000);
  setColor(0,  255, 0); // Green Color
  // tell the screen to write on the top row
  delay(1000);
  clearTopRow();
  clearBottomRow();
  
}


/*
* currentGameModeText
* This function gets passed the current game mode and returns the char array pointer that is needed to load into the display.
*
*/
const char* currentGameModeText(GameMode gameMode) {

  switch (gameMode) {
    case GameMode::CLASSIC6:
      return "   CLASSIC 6    ";
      break;
    case GameMode::CLASSIC10:
      return "   CLASSIC 10   ";
      break;
    case GameMode::RANDOM6:
      return "    RANDOM 6    ";
      break;
    case GameMode::RANDOM10:
      return "    RANDOM 10   ";
      break;
  }
}

void incrementGameMode(GameMode &mode) {
    mode = static_cast<GameMode>((static_cast<int>(mode) + 1) % static_cast<int>(4));
}

//This sets the color of the RGB light
void setColor(int redValue, int greenValue,  int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin,  greenValue);
  analogWrite(bluePin, blueValue);
}