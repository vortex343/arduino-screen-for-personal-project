#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "displayManager.h"
#include "temperature.h"

#define BUTTON_PIN_1 2
#define BUTTON_PIN_2 4
#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1
#define NUM_SCREENS 2

bool buttonPressed1 = false;
bool buttonPressed2 = false;
int buttonState1 = 0;
int buttonState2 = 0;
int screen = 0;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


//functions
void initButtons() {
  pinMode(BUTTON_PIN_1, INPUT);
  pinMode(BUTTON_PIN_2, INPUT);

}

void handleButtons() {
  buttonState1 = digitalRead(BUTTON_PIN_1);
  buttonState2 = digitalRead(BUTTON_PIN_2);

  if (buttonState1 == HIGH && !buttonPressed1) {
    screen = (screen + 1) % NUM_SCREENS;
    buttonPressed1 = true;
    lcd.clear();

  } else if (buttonState2 == HIGH && !buttonPressed2) {
    screen = (screen - 1 + NUM_SCREENS) % NUM_SCREENS;

    buttonPressed2 = true;
    lcd.clear();
  }

  if (buttonState1 == LOW && buttonPressed1) {
    buttonPressed1 = false;
  } else if (buttonState2 == LOW && buttonPressed2) {
    buttonPressed2 = false;
  }
}

void initDisplay() {
  lcd.init();
  lcd.backlight();
}


void showScreen() {
  switch (screen)
  {
  case 0:
    showScreenTemps(lcd);
    break;
  
    default:  
    lcd.setCursor(0, 0);
    lcd.print("Screen: " + String(screen));
    break;
  }

}