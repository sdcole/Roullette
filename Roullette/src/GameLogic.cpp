#include <Arduino.h>
#include "GameLogic.h"
#include "LCDUtils.h"



GameLogic::GameLogic(int navButtonPin, int selectButtonPin, int redPin, int greenPin, int bluePin, int relayPowerPin, int relaySwitchPin) : 
    navButtonPin(navButtonPin), selectButtonPin(selectButtonPin), redPin(redPin), greenPin(greenPin), bluePin(bluePin), relayPowerPin(relayPowerPin), relaySwitchPin(relaySwitchPin), isGameActive(false) {

    pinMode(navButtonPin, INPUT);
    pinMode(selectButtonPin, INPUT);
    pinMode(relayPowerPin, OUTPUT);
    pinMode(relaySwitchPin, OUTPUT);
}


void GameLogic::startGame(GameMode mode) {
    // Set the game mode
    gameMode = mode;
    isGameActive = true;


    //This will turn on the power.
    digitalWrite(relayPowerPin, HIGH);

    // Display game start message
    Serial.println("Game Started!");
    Serial.print("Game Mode: ");
    Serial.print(static_cast<int>(gameMode));
    // Additional setup based on mode
    switch (gameMode) {
        case GameMode::CLASSIC6:
            // Set up for CLASSIC6 mode
            playClassic(6);
            break;
        case GameMode::CLASSIC10:
            // Set up for CLASSIC10 mode
            playClassic(10);
            break;
        case GameMode::RANDOM6:
            // Set up for RANDOM6 mode
            playRandom(6);
            break;
        case GameMode::RANDOM10:
            // Set up for RANDOM10 mode
            playRandom(10);
            break;
    }
}

void GameLogic::playRandom(int probability) {
  Serial.println("In play random");
  //This will create a psuedo random seed that the numbers will be based on.
  randomSeed(analogRead(0));
  int randomValue;

  while(isGameActive) {
    
    if (digitalRead(selectButtonPin) == HIGH) {
      randomValue = random(0,probability);
      Serial.println(randomValue);
      if (randomValue == 0) {
        //TRIGGER LOSE RELAY
        setBottomText("    YOU LOSE    ");
        digitalWrite(relaySwitchPin, HIGH);
        delay(100);
        digitalWrite(relaySwitchPin, LOW);
        return;
      }
      else {
        setBottomText("      SAFE     ");
      }
      delay(200);
      clearBottomRow();
    }
  }
}

void GameLogic::playClassic(int probability) {
  //This will create a psuedo random seed that the numbers will be based on.
  randomSeed(analogRead(0));
  bool validRandom = false;
  int randomValue;

  //Initial 5 to know if they hit or not
  bool hit1 = false;
  bool hit2 = false;
  bool hit3 = false;
  bool hit4 = false;
  bool hit5 = false;

  if (probability == 6) {
    while(isGameActive) {
      if (digitalRead(selectButtonPin) == HIGH) {
        //This will make sure that the hit has not already been done.
        while (!validRandom) {
          randomValue = random(0,probability);
          Serial.print("Random value: ");
          Serial.print(randomValue);
          //These conditions will check if the selection has already been made and loop until it hasn't.
          if (randomValue == 0) {
            //TRIGGER
            delay(100);
            setBottomText("    YOU LOSE    ");
          }
          else if (randomValue == 1) {
            if (hit1) {
              continue;
            }
            else {
              hit1 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 2) {
            if (hit2) {
              continue;
            }
            else {
              hit2 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 3) {
            if (hit3) {
              continue;
            }
            else {
              hit3 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 4) {
            if (hit4) {
              continue;
            }
            else {
              hit4 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 5) {
            if (hit5) {
              continue;
            }
            else {
              hit5 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          
        }
        
      }

    delay(500);
  }
  }
  else if (probability == 10){
    //Since probability is 10 we need more bool conditions.
    bool hit6 = false;
    bool hit7 = false;
    bool hit8 = false;
    bool hit9 = false;
    while(isGameActive) {
      //This will make sure that the hit has not already been done.
        while (!validRandom) {
          randomValue = random(0,probability);
          Serial.print("Random value: ");
          Serial.print(randomValue);
          //These conditions will check if the selection has already been made and loop until it hasn't.
          if (randomValue == 0) {
            //TRIGGER
            delay(100);
            setBottomText("    YOU LOSE    ");
          }
          else if (randomValue == 1) {
            if (hit1) {
              continue;
            }
            else {
              hit1 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 2) {
            if (hit2) {
              continue;
            }
            else {
              hit2 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 3) {
            if (hit3) {
              continue;
            }
            else {
              hit3 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 4) {
            if (hit4) {
              continue;
            }
            else {
              hit4 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 5) {
            if (hit5) {
              continue;
            }
            else {
              hit5 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 6) {
            if (hit6) {
              continue;
            }
            else {
              hit6 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 7) {
            if (hit7) {
              continue;
            }
            else {
              hit7 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 8) {
            if (hit8) {
              continue;
            }
            else {
              hit8 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }
          else if (randomValue == 9) {
            if (hit9) {
              continue;
            }
            else {
              hit9 = true;
              setBottomText("      SAFE      ");
              validRandom = true;
            }
          }

          
        }

    delay(500);
  }

  }
  return;
  
}
