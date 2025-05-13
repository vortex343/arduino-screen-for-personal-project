#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "max6675.h"
#include "displayManager.h"



void setup() {
  initButtons();
  initDisplay();
}

void loop() {
  handleButtons();
  showScreen();

}












