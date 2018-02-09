#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

void print(String str) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(str.substring(0, 20));
  lcd.setCursor(0, 1);
  lcd.print(str.substring(20, 40));
  lcd.setCursor(0, 2);
  lcd.print(str.substring(40, 60));
  lcd.setCursor(0, 3);
  lcd.print(str.substring(60, 80));
}

void setup()
{
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.backlight(); // finish with backlight on
  print("de specificaties van mijn nieuwe kompjoeter");  
}

void loop()
{
}

