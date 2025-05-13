#include <LiquidCrystal_I2C.h>
#include "max6675.h"

//in “20, 4” ändern wenn 20x04 benutzt wir
int thermoDO = 7;
int thermoCS = 5;
int thermoCLK = 6;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void showScreenTemps(LiquidCrystal_I2C &lcd){
  lcd.setCursor(0, 0);
  lcd.print("Temp.: " + String(thermocouple.readCelsius()) + " C");
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}




